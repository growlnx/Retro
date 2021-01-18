[bits 32]

; imports
extern K_main

; exports
global _start

%include "multiboot.asm"
%include "gdt.asm"
%include "idt.asm"
%include "stack.asm"

section .text

	_start:
		; point to stack
		mov esp, STACK_TOP
		; bootstrap the kernel
		call K_main

