#!/usr/bin/env bash

set -e

DEBUG="false";

while [[ $# -gt 0 ]]
do
	key="$1"

	case $key in
	    -d|--debug)
	    	DEBUG="true";
	    	shift
	    ;;
	    *)
			echo "FUTURE HELP MSG";
			exit;
	esac
done

if [[ $DEBUG == "true" ]]; then
	echo "ALOU"
	gdb -x debug
	exit
fi

qemu-system-i386 -cdrom kernel.iso -no-reboot -no-shutdown -d cpu_reset,int -D qemu.log