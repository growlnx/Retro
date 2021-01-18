SUBDIRS 	:= $(wildcard */)

all: $(SUBDIRS)
	$(info ************ LINKING KERNEL OBJECTS ************)
	ld -m elf_i386 -T linker.ld $(wildcard kernel/*.o kernel/driver/*.o bootloader/*.o) -o kernel.bin -nostdlib

clean: $(SUBDIRS)
	- rm -f kernel.bin

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


.PHONY: all clean $(SUBDIRS)