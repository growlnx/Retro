#include "kernel.h"

// VGA driver imports

extern uint16
D_VGA_entry(uchar ch, uint8 fore_color, uint8 back_color);

extern void
D_VGA_fill_screen(uint8 fore_color, uint8 back_color);

extern void
D_VGA_print_str(uint8 line,
                uint8 column,
                string str,
                uint8 fore_color,
                uint8 back_color);
// gdt imports
extern void
K_GDT_install();

// idt imports
extern void
K_IDT_install();

// tty imports
extern void
D_TTY_shell();

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
  K_GDT_install();
  K_IDT_install();
  D_VGA_fill_screen(D_VGA_YELLOW, D_VGA_BLACK);
  D_VGA_print_str(2, 0, "[+] Waiting... Interrupt", D_VGA_YELLOW, D_VGA_BLACK);
  while (TRUE)
    ;
}