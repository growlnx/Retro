#pragma once

extern void
K_TSS_install(unsigned int i, unsigned short ss0, unsigned short esp0);

extern void K_TSS_update();