/*
 * Decompiled function: Card_PsionicEntity_EvaluateTarget
 * Entry Point: 004e0e60
 * Size: 368 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Card_PsionicEntity_EvaluateTarget(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (iVar1 = CardQuery_PlayerControlsColor(arg_1,0x40), iVar1 != 0)) {
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
    if (arg_3 == 0x6d) {
      iVar1 = CardTarget_HasValidPlayerOrCreatureTarget(arg_1);
      if (iVar1 != 0) {
        if (local_8 == -1) {
          g_ActivePlayer = 1;
        }
        else {
          *(short *)(&DAT_006a5f48 + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) =
               *(short *)(&DAT_006a5f48 + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) + 1;
          *(short *)(&DAT_006a5f4a + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) =
               *(short *)(&DAT_006a5f4a + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) + 1;
        }
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


