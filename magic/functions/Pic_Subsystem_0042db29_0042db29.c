/*
 * Decompiled function: Pic_Subsystem_0042db29
 * Entry Point: 0042db29
 * Size: 502 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0042db29(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  if (arg_3 == 0x73) {
    if ((((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
        ((*(byte *)(&DAT_006a2828 + (1 - arg_1)) & 0x40) != 0)) &&
       ((iVar1 = FUN_0040d949(arg_1,7,3), iVar1 != 0 &&
        (iVar1 = FUN_0040d949(arg_1,4,2), iVar1 != 0)))) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_006b2d40 = 1;
      Ai_CalcManaRequirement_004ba890(arg_1,4,2);
      if (local_10 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Pic_Subsystem_0042ca53(_DAT_0063ee20,local_10);
        *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + (1 - _DAT_0063ee20) * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + (1 - _DAT_0063ee20) * 0x5b20) |
             0x400;
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (((arg_3 == 0x77) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[1 - arg_1]; local_c = local_c + 1)
      {
        if (((&DAT_006a5f69)[local_c * 0x120 + (1 - arg_1) * 0x5b20] & 4) != 0) {
          iVar1 = Pic_Subsystem_0042ca53(1 - arg_1,local_c);
          *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg_1 * 0x5b20) & 0xfffffbff;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


