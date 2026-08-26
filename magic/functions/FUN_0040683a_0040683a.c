/*
 * Decompiled function: FUN_0040683a
 * Entry Point: 0040683a
 * Size: 583 bytes
 */
#include "magic.h"


int FUN_0040683a(char *str_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char local_24;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  local_c = 0;
  iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  sVar3 = strlen(str_1);
  for (local_18 = 0; local_18 < (int)sVar3; local_18 = local_18 + 1) {
    if (str_1[local_18] < '\0') {
      local_24 = str_1[local_18] + -0x80;
    }
    else {
      local_24 = str_1[local_18];
    }
    iVar4 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),local_24);
    local_c = local_c + iVar4;
    if (((str_1[local_18] == ' ') || (str_1[local_18] == '\n')) || (str_1[local_18] == '^')) {
      local_8 = local_18;
    }
    if (((str_1[local_18] == '\n') || (str_1[local_18] == '^')) || (arg_2 * 8 < local_c)) {
      cVar1 = str_1[local_8];
      str_1[local_8] = '\0';
      if (10 < iVar2) {
        strcpy(str_1 + 0x200,str_1);
        FUN_00406a88(str_1 + local_10,(DAT_00522458 + -2) - arg_3);
      }
      FUN_0040c274(str_1 + local_10,arg_3,arg_4,arg_5);
      if (10 < iVar2) {
        strcpy(str_1,str_1 + 0x200);
      }
      str_1[local_8] = cVar1;
      arg_4 = arg_4 + iVar2;
      local_c = 0;
      local_10 = local_8 + 1;
      if (str_1[local_18] == '^') {
        local_10 = local_8 + 2;
      }
      local_18 = local_8;
      if (DAT_0052245c + -8 < arg_4) break;
    }
  }
  if ((0 < local_c) && (arg_4 <= DAT_0052245c + -8)) {
    FUN_0040c274(str_1 + local_10,arg_3,arg_4,arg_5);
    arg_4 = arg_4 + iVar2;
  }
  return arg_4;
}


