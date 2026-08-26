/*
 * Decompiled function: FUN_0048e0a1
 * Entry Point: 0048e0a1
 * Size: 77 bytes
 */
#include "magic.h"


int FUN_0048e0a1(char *str_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  for (; *str_1 != '\0'; str_1 = str_1 + 1) {
    iVar1 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),*str_1);
    local_8 = local_8 + iVar1;
  }
  return local_8;
}


