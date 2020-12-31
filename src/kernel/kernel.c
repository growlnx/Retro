#include "kernel.h"

// VGA DRIVER imports

extern uint16* D_VGA_buffer;

extern uint16 
D_VGA_entry(unsigned char ch, uint8 fore_color, uint8 back_color);

extern void 
D_VGA_init(uint8 fore_color, uint8 back_color);

void
K_main()
{
	//first init VGA with fore & back colors
	D_VGA_init(D_VGA_WHITE, D_VGA_BLACK);

	//assign each ASCII character to video buffer
	//you can change colors here
	D_VGA_buffer[0] 	= D_VGA_entry('H', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[1] 	= D_VGA_entry('e', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[2] 	= D_VGA_entry('l', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[3] 	= D_VGA_entry('l', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[4] 	= D_VGA_entry('o', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[5] 	= D_VGA_entry(' ', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[6] 	= D_VGA_entry('W', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[7] 	= D_VGA_entry('o', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[8] 	= D_VGA_entry('r', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[9] 	= D_VGA_entry('l', D_VGA_WHITE, D_VGA_BLACK);
	D_VGA_buffer[10]	= D_VGA_entry('d', D_VGA_WHITE, D_VGA_BLACK);

	D_VGA_init(D_VGA_WHITE, D_VGA_BLACK);

	// D_VGA_clear_buffer(D_VGA_buffer, D_VGA_BLACK, D_VGA_BLACK);
}

