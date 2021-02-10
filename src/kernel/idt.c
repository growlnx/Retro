#include "idt.h"
#include "mem.h"

#define IDT_SIZE 256
#define PIC_MASTER_CMD 0x0020
#define PIC_MASTER_DATA PIC_MASTER_CMD + 1
#define PIC_SLAVE_CMD 0x00A0
#define PIC_SLAVE_DATA PIC_SLAVE_CMD + 1

struct idt_entry idt[IDT_SIZE];
struct idt_descriptor idtr;

// import from ASM
extern void
K_IDT_update();

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
K_IDT_irq40();

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
K_IDT_install()
{

  idtr.limit = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
  idtr.base = (unsigned)&idt;
  K_MEM_set((void*)&idt, 0, sizeof(struct idt_entry) * IDT_SIZE);

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

  // Processor exceptions
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

  // Kernel Custom IRQ's
  idt_set_gate(32, (unsigned)K_IDT_irq32, 0x08, 0x8E);
  idt_set_gate(33, (unsigned)K_IDT_irq33, 0x08, 0x8E);
  idt_set_gate(34, (unsigned)K_IDT_irq34, 0x08, 0x8E);
  idt_set_gate(35, (unsigned)K_IDT_irq35, 0x08, 0x8E);
  idt_set_gate(36, (unsigned)K_IDT_irq36, 0x08, 0x8E);
  idt_set_gate(37, (unsigned)K_IDT_irq37, 0x08, 0x8E);
  idt_set_gate(38, (unsigned)K_IDT_irq38, 0x08, 0x8E);
  idt_set_gate(39, (unsigned)K_IDT_irq39, 0x08, 0x8E);
  idt_set_gate(40, (unsigned)K_IDT_irq40, 0x08, 0x8E);
  idt_set_gate(41, (unsigned)K_IDT_irq41, 0x08, 0x8E);
  idt_set_gate(42, (unsigned)K_IDT_irq42, 0x08, 0x8E);
  idt_set_gate(43, (unsigned)K_IDT_irq43, 0x08, 0x8E);
  idt_set_gate(44, (unsigned)K_IDT_irq44, 0x08, 0x8E);
  idt_set_gate(45, (unsigned)K_IDT_irq45, 0x08, 0x8E);
  idt_set_gate(46, (unsigned)K_IDT_irq46, 0x08, 0x8E);
  idt_set_gate(47, (unsigned)K_IDT_irq47, 0x08, 0x8E);
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
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      break;

    case 9:
      break;

    case 10:
      break;

    case 11:
      break;

    case 12:
      break;

    case 13:
      break;

    case 14:
      break;

    case 15:
      break;

    case 16:
      break;

    case 17:
      break;

    case 18:
      break;

    case 19:
      break;

    case 20:
      break;

    case 21:
      break;

    case 22:
      break;

    case 23:
      break;

    case 24:
      break;

    case 25:
      break;

    case 26:
      break;

    case 27:
      break;

    case 28:
      break;

    case 29:
      break;

    case 30:
      break;

    case 31:
      break;

    case 32:
      break;

    case 33:
      D_PS2_KB_handler(r);
      break;

    case 34:
      break;

    case 35:
      break;

    case 36:
      break;

    case 37:
      break;

    case 38:
      break;

    case 39:
      break;

    case 40:
      break;

    case 41:
      break;

    case 42:
      break;

    case 43:
      break;

    case 44:
      break;

    case 45:
      break;

    case 46:
      break;

    case 47:
      break;

    default:
      // wtf
      K_panic(1, "Unknow Interuption");
      break;
  }

  // send End Of Interrupt signal to Slave PIC
  if (r.interrupt >= 40)
    K_IO_outb(PIC_SLAVE_CMD, 0x20);

  // send End Of Interrupt signal to Master PIC
  K_IO_outb(PIC_MASTER_CMD, 0x20);
}