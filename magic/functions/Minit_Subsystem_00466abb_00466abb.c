/*
 * Decompiled function: Minit_Subsystem_00466abb
 * Entry Point: 00466abb
 * Size: 617 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00466abb(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x73) {
    if ((((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) &&
         (iVar1 = FUN_0040d949(arg_1,7,5), iVar1 != 0)) &&
        ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) &&
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      if ((arg_1 == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      return 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,5), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,5), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      if (0 < DAT_006ff550) {
        DAT_006ff550 = DAT_006ff550 + -1;
      }
    }
    if (arg_3 == 0x72) {
      iVar1 = Pic_Subsystem_0045268f(0x375);
      iVar1 = Pic_Subsystem_00451291(arg_1,iVar1);
      if (iVar1 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,iVar1);
        *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
    }
  }
  return 0;
}


