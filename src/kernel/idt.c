#include "idt.h"

// import from IO
extern void
K_IO_outb();

// import from Kernel
extern void*
K_memset(void* dest, int val, int len);

extern void
K_panic(int code, string msg);

// import from ASM
extern void
K_IDT_update();

// import from Keyboard
void
D_PS2_KB_handler(struct regs r);

extern void
K_IDT_irq0();

extern void
K_IDT_irq1();

extern void
K_IDT_irq2();

extern void
K_IDT_irq3();

extern void
K_IDT_irq4();

extern void
K_IDT_irq5();

extern void
K_IDT_irq6();

extern void
K_IDT_irq7();

extern void
K_IDT_irq8();

extern void
K_IDT_irq9();

extern void
K_IDT_irq10();

extern void
K_IDT_irq11();

extern void
K_IDT_irq12();

extern void
K_IDT_irq13();

extern void
K_IDT_irq14();

extern void
K_IDT_irq15();

extern void
K_IDT_irq16();

extern void
K_IDT_irq17();

extern void
K_IDT_irq18();

extern void
K_IDT_irq19();

extern void
K_IDT_irq20();

extern void
K_IDT_irq21();

extern void
K_IDT_irq22();

extern void
K_IDT_irq23();

extern void
K_IDT_irq24();

extern void
K_IDT_irq25();

extern void
K_IDT_irq26();

extern void
K_IDT_irq27();

extern void
K_IDT_irq28();

extern void
K_IDT_irq29();

extern void
K_IDT_irq30();

extern void
K_IDT_irq31();

extern void
K_IDT_irq32();

extern void
K_IDT_irq33();

extern void
K_IDT_irq34();

extern void
K_IDT_irq35();

extern void
K_IDT_irq36();

extern void
K_IDT_irq37();

extern void
K_IDT_irq38();

extern void
K_IDT_irq39();

extern void
ir140();

extern void
K_IDT_irq41();

extern void
K_IDT_irq42();

extern void
K_IDT_irq43();

extern void
K_IDT_irq44();

extern void
K_IDT_irq45();

extern void
K_IDT_irq46();

extern void
K_IDT_irq47();

extern void
K_IDT_irq80();

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

struct idt_entry idt[256];
struct idt_descriptor idtr;

static void
idt_set_gate(unsigned char i,
             unsigned long base,
             unsigned short selector,
             unsigned char flags)
{
  idt[i].base_low = (base & 0xFFFF);
  idt[i].base_high = (base >> 16) & 0xFFFF;
  idt[i].selector = selector;
  idt[i].null = 0;
  idt[i].flags = flags;
}

void
keyboard_handler()
{
  K_panic(0, "Keyboard INTERRUPT");
}

void
K_IDT_install()
{

  idtr.limit = (sizeof(struct idt_entry) * 256) - 1;
  idtr.base = (unsigned)&idt;
  K_memset((void*)&idt, 0, sizeof(struct idt_entry) * 256);

  // remmaping 8259 PIC
  K_IO_outb(PIC_MASTER_CMD, 0x11);
  K_IO_outb(PIC_SLAVE_CMD, 0x11);

  K_IO_outb(PIC_MASTER_DATA, 0x20);
  K_IO_outb(PIC_SLAVE_DATA, 0x28);

  K_IO_outb(PIC_MASTER_DATA, 0x04);
  K_IO_outb(PIC_SLAVE_DATA, 0x02);
  K_IO_outb(PIC_MASTER_DATA, 0x01);
  K_IO_outb(PIC_SLAVE_DATA, 0x01);
  K_IO_outb(PIC_MASTER_DATA, 0x0);
  K_IO_outb(PIC_SLAVE_DATA, 0x0);

  idt_set_gate(0, (unsigned)K_IDT_irq0, 0x08, 0x8E);
  idt_set_gate(1, (unsigned)K_IDT_irq1, 0x08, 0x8E);
  idt_set_gate(2, (unsigned)K_IDT_irq2, 0x08, 0x8E);
  idt_set_gate(3, (unsigned)K_IDT_irq3, 0x08, 0x8E);
  idt_set_gate(4, (unsigned)K_IDT_irq4, 0x08, 0x8E);
  idt_set_gate(5, (unsigned)K_IDT_irq5, 0x08, 0x8E);
  idt_set_gate(6, (unsigned)K_IDT_irq6, 0x08, 0x8E);
  idt_set_gate(7, (unsigned)K_IDT_irq7, 0x08, 0x8E);
  idt_set_gate(8, (unsigned)K_IDT_irq8, 0x08, 0x8E);
  idt_set_gate(9, (unsigned)K_IDT_irq9, 0x08, 0x8E);
  idt_set_gate(10, (unsigned)K_IDT_irq10, 0x08, 0x8E);
  idt_set_gate(11, (unsigned)K_IDT_irq11, 0x08, 0x8E);
  idt_set_gate(12, (unsigned)K_IDT_irq12, 0x08, 0x8E);
  idt_set_gate(13, (unsigned)K_IDT_irq13, 0x08, 0x8E);
  idt_set_gate(14, (unsigned)K_IDT_irq14, 0x08, 0x8E);
  idt_set_gate(15, (unsigned)K_IDT_irq15, 0x08, 0x8E);
  idt_set_gate(16, (unsigned)K_IDT_irq16, 0x08, 0x8E);
  idt_set_gate(17, (unsigned)K_IDT_irq17, 0x08, 0x8E);
  idt_set_gate(18, (unsigned)K_IDT_irq18, 0x08, 0x8E);
  idt_set_gate(19, (unsigned)K_IDT_irq19, 0x08, 0x8E);
  idt_set_gate(20, (unsigned)K_IDT_irq20, 0x08, 0x8E);
  idt_set_gate(21, (unsigned)K_IDT_irq21, 0x08, 0x8E);
  idt_set_gate(22, (unsigned)K_IDT_irq22, 0x08, 0x8E);
  idt_set_gate(23, (unsigned)K_IDT_irq23, 0x08, 0x8E);
  idt_set_gate(24, (unsigned)K_IDT_irq24, 0x08, 0x8E);
  idt_set_gate(25, (unsigned)K_IDT_irq25, 0x08, 0x8E);
  idt_set_gate(26, (unsigned)K_IDT_irq26, 0x08, 0x8E);
  idt_set_gate(27, (unsigned)K_IDT_irq27, 0x08, 0x8E);
  idt_set_gate(28, (unsigned)K_IDT_irq28, 0x08, 0x8E);
  idt_set_gate(29, (unsigned)K_IDT_irq29, 0x08, 0x8E);
  idt_set_gate(30, (unsigned)K_IDT_irq30, 0x08, 0x8E);
  idt_set_gate(31, (unsigned)K_IDT_irq31, 0x08, 0x8E);
  idt_set_gate(32, (unsigned)K_IDT_irq0, 0x08, 0x8E);
  idt_set_gate(33, (unsigned)K_IDT_irq1, 0x08, 0x8E);
  idt_set_gate(34, (unsigned)K_IDT_irq2, 0x08, 0x8E);
  idt_set_gate(35, (unsigned)K_IDT_irq3, 0x08, 0x8E);
  idt_set_gate(36, (unsigned)K_IDT_irq4, 0x08, 0x8E);
  idt_set_gate(37, (unsigned)K_IDT_irq5, 0x08, 0x8E);
  idt_set_gate(38, (unsigned)K_IDT_irq6, 0x08, 0x8E);
  idt_set_gate(39, (unsigned)K_IDT_irq7, 0x08, 0x8E);
  idt_set_gate(40, (unsigned)K_IDT_irq8, 0x08, 0x8E);
  idt_set_gate(41, (unsigned)K_IDT_irq9, 0x08, 0x8E);
  idt_set_gate(42, (unsigned)K_IDT_irq10, 0x08, 0x8E);
  idt_set_gate(43, (unsigned)K_IDT_irq11, 0x08, 0x8E);
  idt_set_gate(44, (unsigned)K_IDT_irq12, 0x08, 0x8E);
  idt_set_gate(45, (unsigned)K_IDT_irq13, 0x08, 0x8E);
  idt_set_gate(46, (unsigned)K_IDT_irq14, 0x08, 0x8E);
  idt_set_gate(47, (unsigned)K_IDT_irq15, 0x08, 0x8E);
  idt_set_gate(0x80, (unsigned)K_IDT_irq80, 0x08, 0x8E | 0x60);

  K_IDT_update();
}

void
K_IDT_irq_handler(struct regs r)
{
  // select the right handler based in interrupt number
  switch (r.interrupt) {
    case 0:
      break;

    case 1:
      D_PS2_KB_handler(r);
      break;

    default:
      break;
  }

  // send End Of Interrupt signal to Slave PIC
  if (r.interrupt >= 40)
    K_IO_outb(PIC_SLAVE_CMD, 0x20);

  // send End Of Interrupt signal to Master PIC
  K_IO_outb(PIC_MASTER_CMD, 0x20);
}