#ifndef __D_VGA_H
#define __D_VGA_H

#include "../types.h"

// the VGA MMIO
#define D_VGA_ADDRESS 0xb8000

// vga text mode dimessions
#define D_VGA_LINE_LIM 25
#define D_VGA_COLUMN_LIM 80

// its a sequential array of 80*25
#define D_VGA_BUFFER_LIM D_VGA_LINE_LIM*D_VGA_COLUMN_LIM

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

#endif // __D_VGA_H