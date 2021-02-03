#ifndef D_VGA_H
#define D_VGA_H

#include "../types.h"

enum D_VGA_color
{
  D_VGA_BLACK,
  D_VGA_BLUE,
  D_VGA_GREEN,
  D_VGA_CYAN,
  D_VGA_RED,
  D_VGA_MAGENTA,
  D_VGA_BROWN,
  D_VGA_GREY,
  D_VGA_DARK_GREY,
  D_VGA_BRIGHT_BLUE,
  D_VGA_BRIGHT_GREEN,
  D_VGA_BRIGHT_CYAN,
  D_VGA_BRIGHT_RED,
  D_VGA_BRIGHT_MAGENTA,
  D_VGA_YELLOW,
  D_VGA_WHITE,
};

void
D_VGA_print_chr(uint8 line,
                uint8 column,
                char c,
                uint8 fore_color,
                uint8 back_color);

void
D_VGA_print_str(uint8 line,
                uint8 column,
                char* str,
                uint8 fore_color,
                uint8 back_color);

void
// paint full screen
D_VGA_fill_screen(uint8 fore_color, uint8 back_color);

void
// paint a range of line and column
D_VGA_fill_line(uint8 line,
                uint8 start_column,
                uint8 end_column,
                uint8 fore_color,
                uint8 back_color);

void
D_VGA_mk_retang(uint8 a_line,
                uint8 a_column,
                uint8 b,
                uint8 h,
                uint8 fore_color,
                uint8 back_color);

#endif // D_VGA_H