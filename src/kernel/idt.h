#ifndef K_IDT_H
#define K_IDT_H

#include "driver/ps2_kb.h"
#include "io.h"
#include "types.h"
#include "kernel.h"

#define PIC_MASTER_CMD 0x0020
#define PIC_MASTER_DATA PIC_MASTER_CMD + 1
#define PIC_SLAVE_CMD 0x00A0
#define PIC_SLAVE_DATA PIC_SLAVE_CMD + 1

static struct idt_entry
{
  unsigned short base_low;
  unsigned short selector;
  unsigned char null;
  unsigned char flags;
  unsigned short base_high;
} __attribute__((packed));

static struct idt_descriptor
{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

static struct idt_entry idt[256];
extern struct idt_descriptor idtr;

#endif // K_IDT_H