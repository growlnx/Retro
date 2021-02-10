#pragma once

typedef unsigned char uchar;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long int uint64;
typedef char* string;

struct regs
{
  uint32 ds;
  uint32 edi;
  uint32 esi; 
  uint32 ebp;
  uint32 esp;
  uint32 ebx;
  uint32 edx;
  uint32 ecx;
  uint32 eax;
  uint32 interrupt;
  uint32 err_code;
  uint32 eip;
  uint32 cs;
  uint32 eflags;
  uint32 useresp;
  uint32 ss;
};

#define NULL 0

#define TRUE 1
#define FALSE 0