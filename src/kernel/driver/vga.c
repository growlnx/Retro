#include "vga.h"

#define XY_TO_X(x, y) (x*80)+y

// kernel imports
extern void
K_panic(int code, char * msg);

//point vga_buffer pointer to VGA_ADDRESS
uint16* D_VGA_buffer = (uint16*) D_VGA_ADDRESS;  

uint16 
D_VGA_entry(unsigned char ch, uint8 fore_color, uint8 back_color) 
{
  return ((((back_color) << 4) | fore_color) << 8) | ch;
}

void
D_VGA_print_chr(uint8 line, uint8 column, char c, uint8 fore_color, uint8 back_color)
{
  if(line >= 25 || column >= 80) K_panic(1, "VGA: index out of bonds");
  D_VGA_buffer[XY_TO_X(line, column)] = D_VGA_entry(c, fore_color, back_color);
}

void 
D_VGA_print_str(uint8 line, uint8 column, char* str, uint8 fore_color, uint8 back_color)
{
  for(int i = 0; str[i] != '\0'; ++i) {
    D_VGA_print_chr(line, column, str[i], fore_color, back_color);
    column++;
  }
}

void 
// paint full screen
D_VGA_fill_screen(uint8 fore_color, uint8 back_color)
{  
  for(uint32 i = 0; i < D_VGA_BUFFER_LIM; i++){
    D_VGA_buffer[i] = D_VGA_entry(NULL, fore_color, back_color);
  }
}

void
// paint a range of line and column
D_VGA_fill_line(uint8 line, uint8 start_column, uint8 end_column, uint8 fore_color, uint8 back_color)
{
  for(uint8 column = start_column; column <= end_column; ++column) {
    D_VGA_print_chr(line, column, ' ', fore_color, back_color);
  }
}

void
D_VGA_mk_retang(uint8 a_line, uint8 a_column, uint8 b, uint8 h, uint8 fore_color, uint8 back_color)
{
  for(uint8 line = a_line; line < (a_line+h); ++line) {
    D_VGA_fill_line(line, a_column, (a_column+b+1), fore_color, back_color);     
  }
}