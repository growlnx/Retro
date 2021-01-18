AC = nasm
AFLAGS = -f elf32
OBJS = boot.asm

all:
	$(AC) -o boot.o $(AFLAGS) $(OBJS)

clean:
	- rm *.o -f