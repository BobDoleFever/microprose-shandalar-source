/*
 * Decompiled function: FUN_0040c465
 * Entry Point: 0040c465
 * Size: 96 bytes
 */
#include "magic.h"


int FUN_0040c465(char *str_1)

{
  int arg1;
  int iVar1;
  int local_10;
  char *local_c;
  
  local_c = str_1;
  arg1 = *(int *)(g_DisplaySurfaceScreen + 0x20);
  local_10 = 0;
  while (*local_c != '\0') {
    iVar1 = FUN_0050f390(arg1,*local_c);
    local_10 = local_10 + iVar1;
    local_c = local_c + 1;
  }
  return local_10;
}


