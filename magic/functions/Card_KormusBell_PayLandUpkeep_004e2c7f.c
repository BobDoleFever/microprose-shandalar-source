/*
 * Decompiled function: Card_KormusBell_PayLandUpkeep
 * Entry Point: 004e2c7f
 * Size: 873 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Card_KormusBell_PayLandUpkeep(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       ((((&DAT_006a2828)[1 - arg_1] | DAT_006a2828) & 1) != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      if (local_c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) ||
       (arg_3 == 199)) {
      bVar1 = false;
      iVar3 = FUN_0040d949(arg_1,1,3);
      if ((iVar3 != 0) &&
         (iVar3 = Ai_Subsystem_004cc56d
                            (arg_1,arg_1,arg_2,-1,-1,s_Pay_mana__Sacrifice_Land__0052eed8,0),
         iVar3 == 0)) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,3);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          bVar1 = true;
        }
      }
      if ((arg_3 == 199) && (iVar3 = FUN_0040d949(arg_1,1,3), iVar3 != 0)) {
        bVar1 = true;
      }
      if ((!bVar1) && (iVar3 = CardQuery_PlayerControlsColor(arg_1,1), iVar3 != 0)) {
        do {
        } while (local_c == -1);
        Pic_Subsystem_0044867e(_DAT_0063ee20,local_c,3);
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


