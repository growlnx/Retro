CC		:= gcc
CFLAGS	:= -c -std=gnu99 -ffreestanding -fomit-frame-pointer -O0 -m32 -g
OBJECTS	:= $(patsubst %.c,%.o,$(wildcard *.c))

all: $(OBJECTS)
	
clean:
	- rm -f *.o

$(OBJECTS): %.o : %.c
	$(info ************ BUILDING DRIVERS ************)
	@echo "DRIVERS ---> $(OBJECTS)"
	$(CC) -o $@ $<  $(CFLAGS)

.PHONY: all clean $(OBJECTS)