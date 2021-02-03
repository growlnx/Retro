%ifndef STACK
%define STACK

section .bss

	stack resb 1024

	STACK_BOTTOM equ stack
	STACK_TOP equ stack+$

%endif ; STACK