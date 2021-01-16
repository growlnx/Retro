#ifndef K_IDT_H
#define K_IDT_H

#include "types.h"

#define PIC_MASTER_CMD 0x0020
#define PIC_MASTER_DATA PIC_MASTER_CMD + 1
#define PIC_SLAVE_CMD 0x00A0
#define PIC_SLAVE_DATA PIC_SLAVE_CMD + 1

// TODO: Move this data structure to types.h
struct regs
{
  uint32 ds;
  uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32 interrupt, err_code;
  uint32 eip, cs, eflags, useresp, ss;
};

#endif // K_IDT_H