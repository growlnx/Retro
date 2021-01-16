%ifndef IDT
%define IDT

; imports
extern gdtr

; exports
global K_GDT_update

section .text

	K_GDT_update:
		cli ; disable interrupts
		lgdt [gdtr]	; load IDT pointer into idtr register
		
		jmp 0x08:reload_segment_regs ; update cs and ip registers
		
		reload_segment_regs:
			mov ax, 0x10
			mov ds, ax
			mov es, ax
			mov fs, ax
			mov gs, ax
			mov ss, ax
		ret		

%endif