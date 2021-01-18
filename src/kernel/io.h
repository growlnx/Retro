#ifndef K_IO_H
#define K_IO_H

#include "types.h"

void
K_IO_outb(uint16 port, uint8 val);

uint8
K_IO_inb(uint16 port);

#endif // K_IO_H