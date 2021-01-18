#include "ps2_kb.h"

static char D_PS2_KB_buffer = NULL;

// extern uint8
// K_IO_inb(uint16 port);

// extern void
// K_panic(int code, string msg);

// extern void
// D_VGA_print_str(uint8 line,
//                 uint8 column,
//                 char* str,
//                 uint8 fore_color,
//                 uint8 back_color);
// extern void
// D_VGA_print_chr(uint8 line,
//                 uint8 column,
//                 char c,
//                 uint8 fore_color,
//                 uint8 back_color);

void
D_PS2_KB_handler(struct regs r)
{
  D_VGA_print_str(
    2, 0, "[+] D_PS2_KB_handler called", D_VGA_YELLOW, D_VGA_BLACK);
  uchar scancode = K_IO_inb(D_PS2_KB_PORT);

  if (scancode & 0x80) {
    if (scancode == 0x9C) {
      D_PS2_KB_buffer = 'x';
    }
  }
}