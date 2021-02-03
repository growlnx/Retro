#include "ps2_kb.h"
#include "../io.h"
#include "vga.h"

#define D_PS2_KB_PORT 0x60

static char D_PS2_KB_buffer = NULL;

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