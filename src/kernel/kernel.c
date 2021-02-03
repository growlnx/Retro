#include "kernel.h"
#include "driver/vga.h"
#include "types.h"

// gdt imports
extern void
K_GDT_install();

// idt imports
extern void
K_IDT_install();

void
K_halt()
{
  asm volatile("hlt");
}

void*
K_memset(void* dest, int val, int len)
{
  unsigned char* ptr = dest;
  while (len-- > 0)
    *ptr++ = val;
  return dest;
}

void
K_panic(int code, string msg)
{
  D_VGA_fill_screen(D_VGA_BLUE, D_VGA_BLUE);
  D_VGA_print_str(0, 0, "KERNEL PANIC:", D_VGA_YELLOW, D_VGA_BLUE);
  D_VGA_print_str(1, 0, msg, D_VGA_YELLOW, D_VGA_BLUE);
  K_halt();
}

void
K_main()
{
  D_VGA_fill_screen(D_VGA_YELLOW, D_VGA_BLACK);
  D_VGA_print_str(2, 0, "[+] Waiting... Interrupt", D_VGA_YELLOW, D_VGA_BLACK);
  K_GDT_install();
  K_IDT_install();
  while (TRUE)
    ;
}