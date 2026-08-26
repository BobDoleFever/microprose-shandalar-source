/*
 * Decompiled function: FUN_00471bc0
 * Entry Point: 00471bc0
 * Size: 114 bytes
 */
#include "magic.h"


bool FUN_00471bc0(int arg1,int arg2)

{
  bool bVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    bVar1 = false;
  }
  else {
    bVar1 = ((byte)*(undefined4 *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x22) != 2;
  }
  return bVar1;
}


