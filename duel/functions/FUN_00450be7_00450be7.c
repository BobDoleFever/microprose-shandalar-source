/*
 * Decompiled function: FUN_00450be7
 * Entry Point: 00450be7
 * Size: 92 bytes
 */
#include "duel.h"


undefined4 FUN_00450be7(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_006826fc + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_006826fc + arg1 * 0x5b20 + arg2 * 0x120);
  }
  return uVar1;
}


