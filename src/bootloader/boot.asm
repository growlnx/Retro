[bits 32]

; imports
extern K_main

; exports
global _start

%include "inc/multiboot.asm"
%include "inc/gdt.asm"
%include "inc/idt.asm"
%include "inc/stack.asm"

section .text

	_start:
		; point to stack
		mov esp, STACK_TOP
		; bootstrap the kernel
		call K_main

