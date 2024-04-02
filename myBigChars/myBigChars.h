#ifndef MY_BIG_CHARS_H
#define MY_BIG_CHARS_H

#define CHAR_BOX 'a'
#define CHAR_ULC "l"
#define CHAR_URC "k"
#define CHAR_LLC "m"
#define CHAR_LRC "j"
#define CHAR_HOR_LINE "q"
#define CHAR_VER_LINE "x"

int bc_strlen(char * str);
int bc_box(int x1, int y1, int x2, int y2, enum colors box_fg,
enum colors box_bg, char *header, enum colors header_fg, enum colors header_bg);
int bc_printA(char * str);

#endif //MY_BIG_CHARS_H