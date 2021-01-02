SUBDIRS := $(wildcard */)

all: $(SUBDIRS)
	$(info ************ BUILDING ISO FILE ************)
	# verifica se o kernel é compatível com multiboot
	grub2-file --is-x86-multiboot src/kernel.bin

	# cria uma imagem iso
	mkdir -p iso/boot/grub
	cp src/kernel.bin iso/boot/kernel.bin
	cp src/bootloader/grub.cfg iso/boot/grub/grub.cfg
	grub2-mkrescue -o kernel.iso iso
	rm iso -fr

clean: $(SUBDIRS)
	- rm -fr *.o *.bin *iso 

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


.PHONY: all clean $(SUBDIRS)
