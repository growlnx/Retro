SUBDIRS 	:= $(wildcard */)
OBJECTS		:= $(wildcard kernel/*.o) $(wildcard kernel/driver/*.o) $(wildcard bootloader/*.o)

all: $(SUBDIRS)
	$(info ************ LINKING KERNEL OBJECTS ************)
	ld -m elf_i386 -T linker.ld $(OBJECTS) -o kernel.bin -nostdlib

clean: $(SUBDIRS)
	- rm -f kernel.bin

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


.PHONY: all clean $(SUBDIRS)