#ifndef K_IDT_H
#define K_IDT_H

#include "driver/ps2_kb.h"
#include "io.h"
#include "kernel.h"
#include "types.h"

struct idt_entry
{
  uint16 base_low;
  uint16 selector;
  uchar null;
  uchar flags;
  uint16 base_high;
} __attribute__((packed));

struct idt_descriptor
{
  uint16 limit;
  uint32 base;
} __attribute__((packed));

extern struct idt_descriptor idtr;

#endif // K_IDT_H