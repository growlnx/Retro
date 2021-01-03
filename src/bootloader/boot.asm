[bits 32]

; imports
extern K_main

; exports
global _start

%include "inc/multiboot.asm"

; create a stack with 1024 bytes
stack_bottom:
	times 1024 db 0x00  
stack_top:

section .text

	_start:
		; point to stack
		mov esp, stack_top
		; bootstrap the kernel
		call K_main
		cli

		jmp $