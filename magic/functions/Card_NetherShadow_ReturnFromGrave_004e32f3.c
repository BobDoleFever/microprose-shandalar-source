/*
 * Decompiled function: Card_NetherShadow_ReturnFromGrave
 * Entry Point: 004e32f3
 * Size: 497 bytes
 */
#include "magic.h"


undefined4 Card_NetherShadow_ReturnFromGrave(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_14;
  int local_c;
  
  if (((((g_PlayerManaPool == 0xcb) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
      ((arg_1 == g_OverworldPlayerCoordX && (arg_1 == g_DefendingPlayer)))) &&
     (DAT_006a4b5c == arg_1)) {
    iVar1 = Pic_Subsystem_0045268f(0xab);
    local_14 = 0;
    for (local_c = 499; -1 < local_c; local_c = local_c + -1) {
      if (((*(int *)(&DAT_006ff710 + local_c * 4 + arg_1 * 2000) != -1) &&
          (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_c * 4 + arg_1 * 2000) * 0x34] &
           2) != 0)) &&
         ((local_14 = local_14 + 1, *(int *)(&DAT_006ff710 + local_c * 4 + arg_1 * 2000) == iVar1 &&
          (3 < local_14)))) {
        if (arg_3 == 0x7d) {
          g_ActivePalette = g_ActivePalette | 1;
        }
        if ((arg_3 != 0x7e) && (arg_3 != 199)) {
          return 0;
        }
        iVar1 = Pic_Subsystem_00451291(arg_1,iVar1);
        if (iVar1 == -1) {
          return 0;
        }
        Pic_Subsystem_0042ac1f(arg_1,iVar1);
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + iVar1 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + iVar1 * 0x120) & 0xfffcffff;
        Pic_Subsystem_00449223(arg_1,local_c);
        Pic_Subsystem_0044867e(arg_1,arg_2,4);
        Ai_Subsystem_004cc9c5(0,0x30);
        Ai_Subsystem_004cc56d(arg_1,arg_1,iVar1,-1,-1,s_is_returning_from_the_grave__0052eef4,0);
        return 0;
      }
    }
  }
  return 0;
}


