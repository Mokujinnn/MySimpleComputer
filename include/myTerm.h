#ifndef MY_TERM_H
#define MY_TERM_H

enum colors
{
    ForegroundBlack = 30,
    ForegroundDarkRed,
    ForegroundDarkGreen,
    ForegroundDarkYellow,
    ForegroundDarkBlue,
    ForegroundDarkMagenta,
    ForegroundDarkCyan,
    ForegroundLightGray,
    ForegroundDefault = 39,

    BackgroundBlack = 40,
    BackgroundDarkRed,
    BackgroundDarkGreen,
    BackgroundDarkYellow,
    BackgroundDarkBlue,
    BackgroundDarkMagenta,
    BackgroundDarkCyan,
    BackgroundLightGray,
    BackgroundDefault = 49

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