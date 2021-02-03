AC = nasm
AFLAGS = -f elf32
OBJECTS = boot.o

all: $(OBJECTS)

$(OBJECTS): %.o : %.asm
	$(info ************ BUILDING BOOTLOADER ************)
	$(AC) -o $@ $< $(AFLAGS)

clean:
	- rm *.o -f

.PHONY: all clean $(OBJECTS)