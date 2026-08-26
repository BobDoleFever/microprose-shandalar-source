/*
 * Decompiled function: FUN_00417a57
 * Entry Point: 00417a57
 * Size: 178 bytes
 */
#include "magic.h"


undefined4 FUN_00417a57(int arg1,int arg2)

{
  int iVar1;
  
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    iVar1 = FUN_00410cc0(DAT_00538728,DAT_0053872c,DAT_006a2854,arg1,arg2);
    if (iVar1 != -1) {
      *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + DAT_00538728 * 0x5b20) = 1;
      *(undefined2 *)(&DAT_006a5f4a + iVar1 * 0x120 + DAT_00538728 * 0x5b20) = 1;
    }
  }
  return 0;
}


