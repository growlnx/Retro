#include "kernel.h"

// VGA driver imports

extern uint16 
D_VGA_entry(uchar ch, uint8 fore_color, uint8 back_color);

extern void 
D_VGA_fill_screen(uint8 fore_color, uint8 back_color);

extern void 
D_VGA_print_str(uint8 line, uint8 column, string str, uint8 fore_color, uint8 back_color);

extern void
D_VGA_fill_line(uint8 line, uint8 start_column, uint8 end_column, uint8 fore_color, uint8 back_color);

extern void
D_VGA_mk_retang(uint8 a_line, uint8 a_column, uint8 b, uint8 h, uint8 fore_color, uint8 back_color);


void
K_panic(int code, string msg)
{
	D_VGA_fill_screen(D_VGA_BLUE, D_VGA_BLUE);
	D_VGA_print_str(0, 0, "KERNEL PANIC:", D_VGA_YELLOW, D_VGA_BLUE);
	D_VGA_print_str(1, 0, msg, D_VGA_YELLOW, D_VGA_BLUE);
	while(1);
}

void
K_main()
{

	//first init VGA with fore & back colors
	D_VGA_fill_screen(D_VGA_BLUE, D_VGA_BLUE);

	D_VGA_print_str(0, 32, "Welcome to Retro", D_VGA_YELLOW, D_VGA_BLUE);
	D_VGA_print_str(2, 0, "[+] System is loading...", D_VGA_YELLOW, D_VGA_BLUE);
}