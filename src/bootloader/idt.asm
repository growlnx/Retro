%ifndef IDT
%define IDT

; imports
extern idtr
extern K_IDT_irq_handler

; exports
global K_IDT_update

%assign i 0
%rep 48
	global K_IDT_irq %+i
	%assign i i+1
%endrep

global K_IDT_irq80

section .text
	
	K_IDT_update:
		lidt[idtr]
		sti
		ret

	%assign i 0
	%rep 48
		K_IDT_irq %+i:
			cli
			push byte 0
			push byte i
			jmp K_IDT_irq_common_stub
		%assign i i+1
	%endrep

	K_IDT_irq80:
		cli
		push byte 0
		push byte 80
		jmp K_IDT_irq_common_stub

	; This is a stub that we have created for IRQ based ISRs.  This calls
	; 'irq_handler' in our C code.  We need to create this in an 'irq.c'
	K_IDT_irq_common_stub:
	        pusha           ; Pushes edi, esi, ebp, esp, ebx, edx, ecx,
	                        ; eax

	        mov ax, ds      ; Lower 16-bits of eax = ds
	        push eax        ; Save the data segment descriptor

	        mov ax, 0x10    ; Load the kernel data segment descriptor
	        mov ds, ax
	        mov es, ax
	        mov fs, ax
	        mov gs, ax

	        call K_IDT_irq_handler

	        pop eax         ; Reload the original data segment descriptor
	        mov ds, ax
	        mov es, ax
	        mov fs, ax
	        mov gs, ax

	        popa            ; Pops edi, esi, ebp...
	        add esp, 8      ; Cleans up pushed error code and pushed ISR
	                        ; number.
	        sti
	        iret            ; Pops 5 things at once: CS, EIP, EFLAGS, SS and ESP!

%endif ; IDT