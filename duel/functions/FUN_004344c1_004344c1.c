/*
 * Decompiled function: FUN_004344c1
 * Entry Point: 004344c1
 * Size: 169 bytes
 */
#include "duel.h"


size_t FUN_004344c1(int arg_1,undefined4 arg_2,int *arg_3)

{
  undefined4 *arg1;
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  
  arg1 = (undefined4 *)(&DAT_006c0cb0 + (arg_1 + -1) * 0x114);
  iVar1 = FUN_00434446((int)arg1,arg_2);
  if (iVar1 == 0) {
    sVar2 = 0xffffffff;
  }
  else {
    if (*arg_3 == 0) {
      pvVar3 = _malloc(*(int *)(iVar1 + 8) + 0x10);
      *arg_3 = (int)pvVar3;
    }
    _fseek((FILE *)*arg1,*(long *)(iVar1 + 4),0);
    sVar2 = _fread((void *)*arg_3,1,*(size_t *)(iVar1 + 8),(FILE *)*arg1);
  }
  return sVar2;
}


