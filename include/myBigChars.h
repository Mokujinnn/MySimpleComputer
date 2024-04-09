#ifndef MY_BIG_CHARS_H
#define MY_BIG_CHARS_H
#include <stddef.h>

#include "myTerm.h"

#define CHAR_BOX "a"
#define CHAR_ULC "l"
#define CHAR_URC "k"
#define CHAR_LLC "m"
#define CHAR_LRC "j"
#define CHAR_HOR_LINE "q"
#define CHAR_VER_LINE "x"

#define BITS_IN_BYTE 8
#define ARR_SIZE 2

int bc_strlen (char *str);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);
int bc_printA (char *str);
int bc_setbigcharpos (int big[ARR_SIZE], int x, int y, int value);
int bc_getbigcharpos (int big[ARR_SIZE], int x, int y, int *value);
int bc_printbigchar (int bigchar[ARR_SIZE], int x, int y, enum colors fg,
                     enum colors bg);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);

#endif // MY_BIG_CHARS_H