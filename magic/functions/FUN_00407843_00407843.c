/*
 * Decompiled function: FUN_00407843
 * Entry Point: 00407843
 * Size: 753 bytes
 */
#include "magic.h"


char * FUN_00407843(char *str_1,char *str_2,int arg_3)

{
  int iVar1;
  undefined4 *puVar2;
  char *local_114;
  int local_110;
  size_t local_10c;
  char *local_108;
  char local_104;
  undefined4 local_103 [63];
  
  local_110 = 0;
  local_108 = str_1;
  local_104 = '\0';
  puVar2 = local_103;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *str_2 = '\0';
  while (local_114 = (char *)FUN_004077ae(local_108), local_114 != (char *)0x0) {
    local_10c = (int)local_114 - (int)local_108;
    iVar1 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_108,local_10c);
    if (arg_3 < local_110 + iVar1) {
      strcat(&local_104,&DAT_00516590);
      strcat(str_2,&local_104);
      local_104 = '\0';
      for (; (local_108 != (char *)0x0 && (*local_108 == ' ')); local_108 = local_108 + 1) {
        local_10c = local_10c - 1;
      }
      strncat(&local_104,local_108,local_10c);
      for (; (*local_114 != '\0' && (*local_114 == '\n')); local_114 = local_114 + 1) {
        strcat(str_2,&DAT_00516594);
      }
      local_110 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_114,local_10c);
      local_108 = local_114;
    }
    else {
      iVar1 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_108,local_10c);
      local_110 = local_110 + iVar1;
      strncat(&local_104,local_108,local_10c);
      if (*local_114 == '\n') {
        strcat(str_2,&local_104);
      }
      for (; (local_108 = local_114, *local_114 != '\0' && (*local_114 == '\n'));
          local_114 = local_114 + 1) {
        strcat(str_2,&DAT_00516598);
        local_110 = 0;
        local_104 = '\0';
      }
    }
  }
  iVar1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,local_108);
  if (arg_3 < local_110 + iVar1) {
    strcat(&local_104,&DAT_0051659c);
    strcat(str_2,&local_104);
    strcat(str_2,local_108);
  }
  else {
    strcat(str_2,&local_104);
    strcat(str_2,local_108);
  }
  return str_2;
}


