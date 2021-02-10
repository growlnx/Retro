CC		:= gcc
CFLAGS	:= -c -std=gnu99 -ffreestanding -fomit-frame-pointer -O0 -m32 -g
OBJECTS	:= $(patsubst %.c,%.o,$(wildcard *.c))
SUBDIRS := $(wildcard */)

all: $(SUBDIRS) $(OBJECTS)

clean: $(SUBDIRS)
	- rm -f *.o

$(OBJECTS): %.o : %.c
	$(info ************ BUILDING KERNEL CORE ************)
	$(CC) -o $@ $<  $(CFLAGS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: all clean $(SUBDIRS) $(OBJECTS)

