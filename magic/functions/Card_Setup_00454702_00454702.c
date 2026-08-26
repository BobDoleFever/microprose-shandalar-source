/*
 * Decompiled function: Card_Setup_00454702
 * Entry Point: 00454702
 * Size: 739 bytes
 */
#include "magic.h"


undefined4 Card_Setup_00454702(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  uint local_8;
  
  if (arg_3 == 1) {
    uVar2 = Minit_Subsystem_004528c0(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x71) {
    uVar2 = Minit_Subsystem_004528c0(arg_1,arg_2,0x71,0);
  }
  else if (arg_3 == 0x73) {
    uVar2 = Minit_Subsystem_004528c0(arg_1,arg_2,0x73,0);
  }
  else {
    if (arg_3 == 0x6d) {
      strcpy(&g_OverworldWorldState,s_Get_mana__00524020);
      iVar1 = (&DAT_006b3008)[arg_1];
      if (iVar1 != 7) {
        strcat(&g_OverworldWorldState,s___Draw_a_card__0052403c);
      }
      else {
        strcat(&g_OverworldWorldState,s_Draw_a_card__0052402c);
      }
      local_c = (uint)(iVar1 == 7);
      strcat(&g_OverworldWorldState,s_Cancel__0052404c);
      if (DAT_00695ec8 == 0) {
        local_8 = 0;
      }
      else if (DAT_006ff4ac == 0) {
        if (arg_1 == g_CurrentTurnPhase) {
          local_8 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&g_OverworldWorldState,local_c);
        }
        else {
          local_8 = local_c;
        }
      }
      else {
        local_8 = 0;
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      if (local_8 == 0) {
        uVar2 = Minit_Subsystem_004528c0(arg_1,arg_2,0x6d,0);
        return uVar2;
      }
      if (local_8 == 1) {
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        FUN_0040d82b(arg_1,0,1);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
        DAT_006ff2d4 = 0xffffffff;
      }
      else {
        g_ActivePlayer = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 1)) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
      FUN_0046f5d1(arg_1);
    }
    if (arg_3 == 0x7f) {
      uVar2 = Minit_Subsystem_004528c0(arg_1,arg_2,0x7f,0);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


