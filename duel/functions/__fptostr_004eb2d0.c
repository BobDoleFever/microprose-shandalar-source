/*
 * Decompiled function: __fptostr
 * Entry Point: 004eb2d0
 * Size: 215 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __fptostr
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __fptostr(char *x,size_t y,int width,STRFLT height)

{
  char *pcVar1;
  char *local_c;
  char *local_8;
  
  local_c = *(char **)(width + 0xc);
  *x = '0';
  pcVar1 = x;
  for (; local_8 = pcVar1 + 1, 0 < (int)y; y = y - 1) {
    if (*local_c == '\0') {
      *local_8 = '0';
    }
    else {
      *local_8 = *local_c;
      local_c = local_c + 1;
    }
    pcVar1 = local_8;
  }
  *local_8 = '\0';
  if ((-1 < (int)y) && (local_8 = pcVar1, '4' < *local_c)) {
    for (; *local_8 == '9'; local_8 = local_8 + -1) {
      *local_8 = '0';
    }
    *local_8 = *local_8 + '\x01';
  }
  if (*x == '1') {
    *(int *)(width + 4) = *(int *)(width + 4) + 1;
  }
  else {
    width = Mem_AllocOrFree_004d9630((uint *)x,(uint *)(x + 1));
  }
  return width;
}


