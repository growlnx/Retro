#ifndef K_H
#define K_H

#include "types.h"

extern void
K_halt();

extern void*
K_memset(void* dest, int val, int len);

extern void
K_panic(int code, string msg);

#endif // K_H