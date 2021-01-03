AC = nasm
AFLAGS = -f elf32
OBJS = $(wildcard *.asm)

all:
	$(AC) -o boot.o $(AFLAGS) $(OBJS)

clean:
	- rm *.o -f