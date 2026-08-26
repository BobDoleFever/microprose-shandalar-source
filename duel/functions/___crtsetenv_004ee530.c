/*
 * Decompiled function: ___crtsetenv
 * Entry Point: 004ee530
 * Size: 867 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtsetenv
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___crtsetenv(char **str_1,int arg_2)

{
  char **ppcVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *arg1;
  undefined1 *puVar5;
  bool bVar6;
  undefined4 arg_2_00;
  char *arg_3;
  undefined4 arg_4;
  LPCSTR local_20;
  int local_c;
  
  if (((str_1 == (char **)0x0) ||
      (ppcVar1 = (char **)__mbschr((uchar *)str_1,0x3d), ppcVar1 == (char **)0x0)) ||
     (str_1 == ppcVar1)) {
    return -1;
  }
  bVar6 = *(uchar *)((int)ppcVar1 + 1) == '\0';
  if (DAT_0050944c == DAT_00509448) {
    DAT_00509448 = (int *)copy_environ(DAT_00509448);
  }
  if (DAT_00509448 == (int *)0x0) {
    if ((arg_2 == 0) || (DAT_00509450 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_00509448 = (int *)__malloc_dbg(4,2,"setenv.c",0x87);
      if (DAT_00509448 == (int *)0x0) {
        return -1;
      }
      *DAT_00509448 = 0;
      if (DAT_00509450 == (undefined4 *)0x0) {
        DAT_00509450 = (undefined4 *)__malloc_dbg(4,2,"setenv.c",0x8e);
        if (DAT_00509450 == (undefined4 *)0x0) {
          return -1;
        }
        *DAT_00509450 = 0;
      }
    }
    else {
      iVar2 = ___wtomb_environ();
      if (iVar2 != 0) {
        return -1;
      }
    }
  }
  piVar3 = DAT_00509448;
  local_c = findenv((uchar *)str_1,(int)ppcVar1 - (int)str_1);
  if ((local_c < 0) || (*piVar3 == 0)) {
    if (bVar6) {
      return 0;
    }
    if (local_c < 0) {
      local_c = -local_c;
    }
    piVar3 = (int *)__realloc_dbg(piVar3,local_c * 4 + 8,2,"setenv.c",0xce);
    if (piVar3 == (int *)0x0) {
      return -1;
    }
    piVar3[local_c] = (int)str_1;
    piVar3[local_c + 1] = 0;
    DAT_00509448 = piVar3;
  }
  else if (bVar6) {
    __free_dbg((void *)piVar3[local_c],2);
    for (; piVar3[local_c] != 0; local_c = local_c + 1) {
      piVar3[local_c] = piVar3[local_c + 1];
    }
    piVar3 = (int *)__realloc_dbg(piVar3,local_c << 2,2,"setenv.c",0xb9);
    if (piVar3 != (int *)0x0) {
      DAT_00509448 = piVar3;
    }
  }
  else {
    piVar3[local_c] = (int)str_1;
  }
  if (arg_2 != 0) {
    arg_4 = 0xe5;
    arg_3 = "setenv.c";
    arg_2_00 = 2;
    sVar4 = _strlen((char *)str_1);
    arg1 = (uint *)__malloc_dbg(sVar4 + 2,arg_2_00,arg_3,arg_4);
    if (arg1 != (uint *)0x0) {
      Mem_AllocOrFree_004d9630(arg1,(uint *)str_1);
      puVar5 = (undefined1 *)(((int)ppcVar1 - (int)str_1) + (int)arg1);
      *puVar5 = 0;
      local_20 = puVar5 + 1;
      if (bVar6) {
        local_20 = (LPCSTR)0x0;
      }
      SetEnvironmentVariableA((LPCSTR)arg1,local_20);
      __free_dbg(arg1,2);
    }
  }
  return 0;
}


