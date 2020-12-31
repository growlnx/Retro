#include "vga.h"

uint16* D_VGA_buffer;

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
//clear video buffer array
D_VGA_clear_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color)
{
  for(uint32 i = 0; i < D_VGA_BUFFER_SZ; i++){
    (*buffer)[i] = D_VGA_entry(NULL, fore_color, back_color);
  }
}

void 
//initialize vga buffer
D_VGA_init(uint8 fore_color, uint8 back_color)
{
  D_VGA_buffer = (uint16*)D_VGA_ADDRESS;  //point vga_buffer pointer to VGA_ADDRESS 
  D_VGA_clear_buffer(&D_VGA_buffer, fore_color, back_color);  //clear buffer
}