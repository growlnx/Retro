#include "kernel.h"

// VGA driver imports

extern uint16 
D_VGA_entry(unsigned char ch, uint8 fore_color, uint8 back_color);

extern void 
D_VGA_fill(uint8 fore_color, uint8 back_color);

extern void 
D_VGA_print_str(uint8 line, uint8 column, char* str, uint8 fore_color, uint8 back_color);

void
K_main()
{
	//first init VGA with fore & back colors
	D_VGA_fill(D_VGA_BLUE, D_VGA_BLUE);

	D_VGA_print_str(24, 77, "loading kernel", D_VGA_YELLOW, D_VGA_BLUE);
}

void
K_panic(int code, char * msg)
{
	D_VGA_fill(D_VGA_BLUE, D_VGA_BLUE);
	D_VGA_print_str(0, 0, "KERNEL PANIC:", D_VGA_YELLOW, D_VGA_BLUE);
	D_VGA_print_str(1, 0, msg, D_VGA_YELLOW, D_VGA_BLUE);
	while(1);
}
