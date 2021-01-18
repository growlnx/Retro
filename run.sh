#!/usr/bin/env sh

set -e

if [ ! -f kernel.iso ]; then
	echo "You need a kernel.iso file";
	echo "to build your kernel run:\n$ make all";
	exit 1;
fi

gdb -tui -x debug -nx