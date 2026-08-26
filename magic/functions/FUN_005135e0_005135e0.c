/*
 * Decompiled function: FUN_005135e0
 * Entry Point: 005135e0
 * Size: 170 bytes
 */
#include "magic.h"


void FUN_005135e0(int arg1,uint arg2)

{
  int arg_1;
  uint uVar1;
  
  arg_1 = DAT_006261d4;
  while (arg1 != 0) {
    arg1 = arg1 + -1;
    uVar1 = DAT_006261b8;
    if (7 < DAT_006261c0) {
      (&DAT_00706510)[DAT_006261e0] = (char)DAT_006261b8;
      DAT_006261e0 = DAT_006261e0 + 1;
      DAT_006261b8 = 0;
      DAT_006261c0 = 0;
      uVar1 = 0;
      if (0x1ff < DAT_006261e0) {
        _write(arg_1,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        arg_1 = DAT_006261d4;
        uVar1 = DAT_006261b8;
      }
    }
    DAT_006261b8 = (int)uVar1 >> 1;
    if ((arg2 & 1) != 0) {
      DAT_006261b8 = DAT_006261b8 | 0x80;
    }
    arg2 = (int)arg2 >> 1;
    DAT_006261c0 = DAT_006261c0 + 1;
  }
  return;
}


