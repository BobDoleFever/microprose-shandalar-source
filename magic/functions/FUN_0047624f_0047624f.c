/*
 * Decompiled function: FUN_0047624f
 * Entry Point: 0047624f
 * Size: 495 bytes
 */
#include "magic.h"


undefined4 FUN_0047624f(int x,undefined4 arg_2,char *str_3,int height)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int local_18;
  
  uVar5 = DAT_006a4b5c;
  uVar4 = DAT_00695f0c;
  uVar3 = DAT_00695ec4;
  uVar2 = DAT_0068a67c;
  uVar1 = DAT_0063ee70;
  DAT_006fd3f0 = DAT_006fd3f0 + 1;
  DAT_00695ec4 = arg_2;
  DAT_006a4b5c = x;
  do {
    if (x == 0) {
      DAT_0068a67c = 1;
    }
    else {
      DAT_0068a67c = 2;
    }
    g_PlayerManaPool = arg_2;
    if (height == 0) {
      DAT_0063ee70 = 0;
    }
    else {
      DAT_0063ee70 = 0x30;
    }
    g_ActivePlayer = 0;
    DAT_0068a714 = 0;
    DAT_00695f0c = 0;
    iVar6 = Pic_Subsystem_004458b0(x,str_3);
    DAT_0063edc8 = uVar1 & 0x30;
  } while (((DAT_00695f0c & (-(uint)(iVar6 == 0) & 0xfffffffe) + 6) != 0) ||
          ((height != 0 && (iVar6 != 0))));
  g_PlayerManaPool = 0xffffffff;
  DAT_006fd3f0 = DAT_006fd3f0 + -1;
  DAT_0063ee70 = uVar1;
  DAT_0068a67c = uVar2;
  if (DAT_006fd3f0 == 0) {
    for (x = 0; x < 2; x = x + 1) {
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[x]; local_18 = local_18 + 1) {
        *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + x * 0x5b20) & 0xfffffeff;
      }
    }
    if (DAT_006ff684 == 0) {
      DAT_0063ee1c = 0;
      DAT_0063edc4 = 0;
    }
  }
  DAT_00695f0c = uVar4;
  DAT_006a4b5c = uVar5;
  DAT_00695ec4 = uVar3;
  return 0;
}


