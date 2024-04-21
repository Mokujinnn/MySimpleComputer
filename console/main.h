#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myReadKey.h"

void loadFont(int *bigchar, int n)
{
    FILE *f = fopen("font/font.bin", "rb");

    if (f == NULL)
    {
        printf("Cant open file with font\n");
        exit(EXIT_FAILURE);
    }

    fread(bigchar, sizeof(int), n * ARR_SIZE, f);
    fclose(f);
}

void InitMem()
{
    sc_memoryInit();
    for (int i = 0; i < rand() % SIZEMEM; ++i)
    {
        sc_memorySet(i, rand() % 0x7fff);
    }

    sc_regInit();
    sc_accumulatorInit();
    sc_icounterInit();
}

int CheckOutputStream()
{
    int rows = 0;
    int cols = 0;

    if (!ttyname(STDOUT_FILENO))
    {
        printf("Output stream is not a terminal\n");
        return 0;
    }

    mt_getscreensize(&rows, &cols);

    mt_clrscr();
    if (!(90 < cols && 26 < rows))
    {
        printf("Small terminal size\n");
        return 0;
    }
    return 1;
}

void Init(int *bigchar)
{
    loadFont(bigchar, 18);
    int status = CheckOutputStream();
    if (!status)
    {
        exit(EXIT_FAILURE);
    }

    InitMem();
}

void printMem(int addresOfCurrentCell)
{
    for (int i = 0; i < SIZEMEM; ++i)
    {
        printCell(i, ForegroundDefault, BackgroundDefault);
    }
    printCell(addresOfCurrentCell, ForegroundBlack, BackgroundLightGray);
}

void printKeybord()
{
    mt_gotoXY(75, 20);
    write(STDOUT_FILENO, "l - load  s - save i - reset", 29);
    mt_gotoXY(75, 21);
    write(STDOUT_FILENO, "r - run  t - step", 18);
    mt_gotoXY(75, 22);
    write(STDOUT_FILENO, "ESC - выход", 17);
    mt_gotoXY(75, 23);
    write(STDOUT_FILENO, "F5 - accumulator", 17);
    mt_gotoXY(75, 24);
    write(STDOUT_FILENO, "F6 - instruction counter", 25);
}

void printAllBoxes()
{
    bc_box(1, 1, 61, 15, ForegroundDefault, BackgroundDefault, " Оперативная память ",
           ForegroundDarkRed, ForegroundDefault);
    bc_box(1, 16, 61, 18, ForegroundDefault, BackgroundDefault,
           " Редактируемая ячейка (декодированно) ", ForegroundDarkRed,
           BackgroundDefault);
    bc_box(62, 1, 87, 3, ForegroundDefault, BackgroundDefault, " Аккумулятор ",
           ForegroundDarkRed, BackgroundDefault);
    bc_box(62, 4, 87, 6, ForegroundDefault, BackgroundDefault,
           " Счётчик инструкций ", ForegroundDarkRed, BackgroundDefault);
    bc_box(88, 4, 111, 6, ForegroundDefault, BackgroundDefault, " Команда ",
           ForegroundDarkRed, BackgroundDefault);
    bc_box(88, 1, 111, 3, ForegroundDefault, BackgroundDefault, " Флаги ",
           ForegroundDarkRed, BackgroundDefault);
    bc_box(62, 7, 111, 18, ForegroundDefault, BackgroundDefault,
           " Редактируемая ечейка (увеличено) ", ForegroundDarkRed,
           ForegroundDefault);
    bc_box(63, 19, 73, 25, ForegroundDefault, BackgroundDefault, " IN--OUT ",
           ForegroundDarkRed, BackgroundLightGray);
    bc_box(1, 19, 62, 25, ForegroundDefault, BackgroundDefault, " Кеш Память ",
           ForegroundDarkRed, BackgroundDefault);
    bc_box(74, 19, 111, 25, ForegroundDefault, BackgroundDefault, " Клавиатура ",
           ForegroundDarkRed, BackgroundDefault);
}

void UpdateAll(int bigchars[][ARR_SIZE], int addresOfCurrentCell)
{
    printMem(addresOfCurrentCell);
    printFlags();
    printDecodedCommand(addresOfCurrentCell);
    printAccumulator();
    printCounters();
    printCommand();
    printBigCell(addresOfCurrentCell, bigchars);
    printTerm(0, 0);
}

int KeyToInt(enum keys key)
{
    switch (key)
    {
    case PLUS: return 0;
    case MINUS: return 1;
    case NUM0: return 0;
    case NUM1: return 1;
    case NUM2: return 2;
    case NUM3: return 3;
    case NUM4: return 4;
    case NUM5: return 5;
    case NUM6: return 6;
    case NUM7: return 7;
    case NUM8: return 8;
    case NUM9: return 9;
    case A: return 10;
    case B: return 11;
    case C: return 12;
    case D: return 13;
    case E: return 14;
    case F: return 15;
    default: return -1;
    }
}

int IsCorrectInPlaceInput(enum keys key, int n)
{
    if (n == 0)
    {
        return key == PLUS || key == MINUS;
    }
    else if (n == 1)
    {
        return key >= NUM0 && key <= NUM5;
    }
    else if (n == 2)
    {
        return (key >= NUM0 && key <= NUM9) || (key >= A && key <= F);
    }
    else if (n == 3)
    {
        return (key >= NUM0 && key <= NUM7);
    }
    else if (n == 4)
    {
        return (key >= NUM0 && key <= NUM9) || (key >= A && key <= F);
    }

    return 0;
}

void InPlaceInput(int *currentCell)
{
    int buf[5] = {0};
    int line = *currentCell / 10;
    int colmn = (*currentCell % 10) * 6;
    int i = 0;
    int flag = 1;
    enum keys key;

    mt_setcursorvisible(1);

    mt_gotoXY(colmn + 2, line + 2);
    write(STDOUT_FILENO, "     ", 5);
    mt_gotoXY(colmn + 2, line + 2);

    rk_mytermsave();

    rk_mytermregime(0, 1, 1, 1, 0);

    for (i = 0; i < 5; i++)
    {
        rk_readkey(&key);
        if (!IsCorrectInPlaceInput(key, i))
        {
            flag = 0;
            break;
        }
        buf[i] = KeyToInt(key);
    }

    if (!flag)
    {
        mt_gotoXY(colmn + 5, line + 5);
        write(STDOUT_FILENO, " ", 1);
        rk_mytermrestore();
        mt_setcursorvisible(0);
        return;
    }

    sc_commandEncode(buf[0], buf[1] * 16 + buf[2], buf[3] * 16 + buf[4], &i); 
    sc_memorySet(*currentCell, i);

    rk_mytermrestore();
    mt_setcursorvisible(0);
}

void InPlaceAccumulator()
{
    int buf[5] = {0};
    int flag = 1;
    enum keys key;
    int i = 0;

    mt_setcursorvisible(1);

    mt_gotoXY (69, 2);
    write(STDOUT_FILENO, "     ", 6);
    mt_gotoXY (69, 2);

    rk_mytermsave();

    rk_mytermregime(0, 1, 1, 1, 0);

    for (i = 0; i < 5; i++)
    {
        rk_readkey(&key);
        if (!IsCorrectInPlaceInput(key, i))
        {
            flag = 0;
            break;
        }
        buf[i] = KeyToInt(key);
    }

    if (!flag)
    {
        mt_gotoXY(74, 2);
        write(STDOUT_FILENO, " ", 1);
        rk_mytermrestore();
        mt_setcursorvisible(0);
        return;
    }

    sc_commandEncode(buf[0], buf[1] * 16 + buf[2], buf[3] * 16 + buf[4], &i); 
    sc_accumulatorSet(i);

    rk_mytermrestore();
    mt_setcursorvisible(0);
}

void Control(enum keys key, int *currentCell, int *escIsNotPressed)
{
    switch (key)
    {
    case ESC:
        *escIsNotPressed = 0;
        break;
    case LEFT:
        if (*currentCell == 120)
        {
            *currentCell += 7;
        }
        else if (*currentCell % 10 == 0)
            *currentCell += 9;
        else
            *currentCell -= 1;
        break;
    case RIGHT:
        if (*currentCell == 127)
        {
            *currentCell -= 7;
        }
        else if (*currentCell % 10 == 9)
            *currentCell -= 9;
        else
            *currentCell += 1;
        break;
    case UP:
        if (*currentCell == 8 || *currentCell == 9)
        {
            *currentCell += 110;
        }
        else if (*currentCell < 10)
            *currentCell += 120;
        else
            *currentCell -= 10;
        break;
    case DOWN:
        if (*currentCell == 118 || *currentCell == 119)
        {
            *currentCell -= 110;
        }
        else if (*currentCell > 119)
            *currentCell -= 120;
        else
            *currentCell += 10;
        break;
    case ENTER:
        InPlaceInput(currentCell);
        break;
    case F5:
        InPlaceAccumulator();
        break;
    default:
        break;
    }
}