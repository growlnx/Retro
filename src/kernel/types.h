#ifndef __K_TYPES_H
#define __K_TYPES_H

typedef unsigned char uchar;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long int uint64;
typedef char* string;

struct regs
{
  uint32 ds;
  uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32 interrupt, err_code;
  uint32 eip, cs, eflags, useresp, ss;
};

#define NULL 0

#define TRUE 1
#define FALSE 0

#endif // __K_TYPES_H