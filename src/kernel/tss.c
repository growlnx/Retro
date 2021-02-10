#include "tss.h"
#include "types.h"
#include "gdt.h"
#include "mem.h"

volatile struct K_TSS_tss
{
	uint16 link;
	uint16 link_h;

	unsigned long esp0;
	uint16 ss0;
	uint16 ss0_h;

	unsigned long esp1;
	uint16 ss1;
	uint16 ss1_h;

	unsigned long esp2;
	uint16 ss2;
	uint16 ss2_h;

	unsigned long cr3;
	unsigned long eip;
	unsigned long eflags;

	unsigned long eax;
	unsigned long ecx;
	unsigned long edx;
	unsigned long ebx;

	unsigned long esp;
	unsigned long ebp;
	
	unsigned long esi;
	unsigned long edi;

	uint16 es;
	uint16 es_h;

	uint16 cs;
	uint16 cs_h;

	uint16 ss;
	uint16 ss_h;

	uint16 ds;
	uint16 ds_h;

	uint16 fs;
	uint16 fs_h;

	uint16 gs;
	uint16 gs_h;

	uint16 ldt;
	uint16 ldt_h;

	uint16 trap;
	uint16 iomap;
} __attribute__((packed));

extern void K_TSS_switch_to_usermode();

struct K_TSS_tss tss;

void
K_TSS_install(unsigned int i, unsigned short ss0, unsigned short esp0)
{

	unsigned int base = (unsigned int)&tss;
	unsigned int size = base + sizeof(struct K_TSS_tss);
	K_GDT_set_gate(i, base, size, 0xE9, 0x00);
	K_MEM_set(&tss, 0, sizeof(struct K_TSS_tss));
	tss.ss0 = ss0;
	tss.esp0 = esp0;
	tss.cs = 0x0B;
	tss.ss = 0x13;
	tss.ds = 0x13;
	tss.es = 0x13;
	tss.fs = 0x13;
	tss.gs = 0x13;
}