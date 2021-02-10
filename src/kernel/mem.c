#include "mem.h"

void*
K_MEM_set(void* dest, int val, int len)
{
  unsigned char* ptr = dest;
  while (len-- > 0)
    *ptr++ = val;
  return dest;
}
