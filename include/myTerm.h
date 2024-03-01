#ifndef MY_TERM_H
#define MY_TERM_H

enum colors
{
    Black = 0,
    DarkRed,
    DarkGreen,
    DarkYellow,
    DarkBlue,
    DarkMagenta,
    DarkCyan,
    LightGray,
    Default = 9,

    Foreground = 30,
    Background = 40
};

int mt_clrscr();
int mt_getscreensize (int * rows, int * cols);
int mt_gotoXY (int x, int y);
int mt_setbgcolor (enum colors color);
int mt_setfgcolor (enum colors color);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);

#endif // MY_TERM_H