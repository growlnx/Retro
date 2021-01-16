extern void
K_GDT_update();

static struct gdt_entry
{
  unsigned short limit_low;
  unsigned short base_low;
  unsigned char base_middle;
  unsigned char access;
  unsigned char granularity;
  unsigned char base_high;
} __attribute__((packed));

static struct gdt_descriptor
{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

struct gdt_entry gdt[3];
struct gdt_descriptor gdtr;

static void
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

  gdtr.limit = (sizeof(struct gdt_entry) * 3) - 1;
  gdtr.base = (unsigned int)&gdt;

  K_GDT_update();
}