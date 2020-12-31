AC = as
AFLAGS = --32
OBJS = $(wildcard *.S)

all:
	$(AS) -o boot.o $(AFLAGS) $(OBJS)

clean:
	- rm *.o -f