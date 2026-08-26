/*
 * Decompiled function: Minit_Subsystem_0045a42a
 * Entry Point: 0045a42a
 * Size: 331 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045a42a(int arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0;
      local_c < *(int *)(&g_CardSlot_TargetSlot +
                        *(int *)(&g_CardSlot_TapState + arg2 * 0x120 + arg1 * 0x5b20) * 0x5b20 +
                        *(int *)(&g_CardSlot_SicknessState + arg2 * 0x120 + arg1 * 0x5b20) * 0x120);
      local_c = local_c + 1) {
    iVar1 = Pic_Subsystem_0045268f(0x37b);
    iVar1 = Pic_Subsystem_00451291(arg1,iVar1);
    if (iVar1 != -1) {
      Pic_Subsystem_0042ac1f(arg1,iVar1);
      (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + arg1 * 0x5b20] = (undefined1)g_DialogPromptHwnd;
      *(undefined4 *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + arg1 * 0x5b20) = g_DuelArenaHwnd;
      *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg1 * 0x5b20) | 0x10;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg1 * 0x5b20) = 1;
    }
  }
  return 0;
}


