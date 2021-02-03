#ifndef K_GDT_H
#define K_GDT_H

#include "types.h"

struct gdt_entry
{
  unsigned short limit_low;
  unsigned short base_low;
  unsigned char base_middle;
  unsigned char access;
  unsigned char granularity;
  unsigned char base_high;
} __attribute__((packed));

struct gdt_descriptor
{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

extern struct gdt_descriptor gdtr;

extern void
K_GDT_install();

#endif // K_GDT_H