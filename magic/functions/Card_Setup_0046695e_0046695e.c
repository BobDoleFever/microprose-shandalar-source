/*
 * Decompiled function: Card_Setup_0046695e
 * Entry Point: 0046695e
 * Size: 349 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Card_Setup_0046695e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,1);
    if ((iVar1 == 0) || (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      strcpy(&g_OverworldWorldState,s_Tap_which_card__00524734);
      if (local_8 != -1) {
        *(uint *)(&g_CardSlot_Flags + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) | 0x10;
        FUN_00473e69(_DAT_0063ee20,local_8,0x7c);
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


