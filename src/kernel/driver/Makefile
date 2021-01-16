CC		:= gcc
CFLAGS	:= -c -std=gnu99 -ffreestanding -O0 -m32 -g
OBJECTS	:= $(patsubst %.c,%.o,$(wildcard *.c))

all: $(OBJECTS)
	
clean:
	- rm -f *.o

$(OBJECTS): %.o : %.c
	$(info ************ BUILDING DRIVERS ************)
	$(CC) -o $@ $<  $(CFLAGS)

.PHONY: all clean $(OBJECTS)