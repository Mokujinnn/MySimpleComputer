#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "myBigChars.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"

#define INPUTCELL 0
#define INPUTACCUM 1
#define INPUTICOUNTER 2

void loadFont (int *bigchar, int n);

void InitMem ();

int CheckOutputStream ();

void Init (int *bigchar);

void printMem (int addresOfCurrentCell);

void printKeybord ();

void printAllBoxes ();

void UpdateAndDraw (int bigchars[][ARR_SIZE], int addresOfCurrentCell);

void InPlaceInput (int line, int colmn, int type);

void MemorySave ();

void MemoryLoad ();

void MemoryReset ();

void Control (enum keys *key, int *currentCell, int *escIsNotPressed);