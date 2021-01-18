#ifndef K_H
#define K_H

#include "driver/vga.h"
#include "types.h"

void
K_halt();

void*
K_memset(void* dest, int val, int len);

void
K_panic(int code, string msg);

#endif // K_H