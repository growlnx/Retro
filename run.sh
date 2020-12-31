#!/usr/bin/env sh

if [ ! -f kernel.iso ]; then
	echo "You need a kernel.iso file";
	echo "to build your kernel run:\n$ make all";
	exit 1;
fi

EMULATOR=qemu

if [ ! -z "$1" ]; then
	EMULATOR=$1;
fi

if [ "$EMULATOR" = "qemu" ]; then
	qemu-system-x86_64 -cdrom kernel.iso
fi