#ifndef D_PS2_KB_H
#define D_PS2_KB_H

#include "../io.h"
#include "../kernel.h"
#include "../types.h"
#include "vga.h"

#define D_PS2_KB_PORT 0x60

void
D_PS2_KB_handler(struct regs r);

#endif // D_PS2_KB_H