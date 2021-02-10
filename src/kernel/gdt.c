#include "gdt.h"
#include "tss.h"
#include "mem.h"

#define GDT_SIZE 6

static struct gdt_entry gdt[GDT_SIZE];
struct gdt_descriptor gdtr;

extern void
// import from bootloader
K_GDT_update();

void
K_GDT_set_gate(int i,
               unsigned long base,
               unsigned long limit,
               unsigned char access,
               unsigned char granularity)
{
  gdt[i].limit_low = (limit & 0xFFFF);
  gdt[i].base_low = (base & 0xFFFF);
  gdt[i].base_middle = (base >> 16) & 0xFF;
  gdt[i].access = access;
  gdt[i].granularity = ((limit >> 16) & 0x0F);
  gdt[i].granularity |= (granularity & 0xF0);
  gdt[i].base_high = (base >> 24) & 0xFF;
}

void
K_GDT_install()
{
  // default null descriptor
  K_GDT_set_gate(0, 0, 0, 0, 0);
  // kerneland code segment
  K_GDT_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
  // kerneland data segment
  K_GDT_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
  // userland code segment
  K_GDT_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
  // userland data segment
  K_GDT_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

  K_TSS_install(5, 0x10, 0x00);

  gdtr.limit = (sizeof(struct gdt_entry) * GDT_SIZE) - 1;
  gdtr.base = (unsigned int)&gdt;

  K_GDT_update();
  K_TSS_update();
}