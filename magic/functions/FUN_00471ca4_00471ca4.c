/*
 * Decompiled function: FUN_00471ca4
 * Entry Point: 00471ca4
 * Size: 114 bytes
 */
#include "magic.h"


undefined4 FUN_00471ca4(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uVar1 = 0;
  }
  else if (((byte)*(undefined4 *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x1e) == 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


