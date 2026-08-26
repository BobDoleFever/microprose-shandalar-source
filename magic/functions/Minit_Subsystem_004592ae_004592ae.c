/*
 * Decompiled function: Minit_Subsystem_004592ae
 * Entry Point: 004592ae
 * Size: 554 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004592ae(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,6);
    if (((iVar1 == 0) || ((&DAT_006a2828)[arg_1] == 0)) ||
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
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
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,6), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,6);
      strcpy(&g_OverworldWorldState,s_Pick_a_permanent_00524284);
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
      if (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      FUN_0041da41((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20];
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


