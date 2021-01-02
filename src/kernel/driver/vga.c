#include "vga.h"

extern void
K_panic(int code, char * msg);

//point vga_buffer pointer to VGA_ADDRESS
uint16* D_VGA_buffer = (uint16*) D_VGA_ADDRESS;  

uint16 
D_VGA_entry(unsigned char ch, uint8 fore_color, uint8 back_color) 
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void
D_VGA_print_chr(uint8 line, uint8 column, char c, uint8 fore_color, uint8 back_color)
{
  if(line >= 25 || column >= 80) K_panic(1, "VGA: index out of bonds");
  D_VGA_buffer[(line*80)+column] = D_VGA_entry(c, fore_color, back_color);
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
//initialize vga buffer
D_VGA_fill(uint8 fore_color, uint8 back_color)
{  
  for(uint32 i = 0; i < D_VGA_BUFFER_LIM; i++){
    D_VGA_buffer[i] = D_VGA_entry(NULL, fore_color, back_color);
  }
}