/*
 * Decompiled function: FUN_0048caf4
 * Entry Point: 0048caf4
 * Size: 71 bytes
 */
#include "magic.h"


bool FUN_0048caf4(int arg_1,void *arg_2,uint arg_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = _write(arg_1,arg_2,arg_3);
  if (iVar1 == -1) {
    piVar2 = _errno();
    DAT_0054aad4 = *piVar2;
  }
  return iVar1 != -1;
}


