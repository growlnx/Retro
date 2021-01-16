#include "io.h"

void
K_IO_outb(uint16 port, uint8 val)
{
  asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

uint8
K_IO_inb(uint16 port)
{
  uint8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
  return ret;
}