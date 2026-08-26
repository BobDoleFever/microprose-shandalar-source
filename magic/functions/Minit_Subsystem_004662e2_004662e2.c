/*
 * Decompiled function: Minit_Subsystem_004662e2
 * Entry Point: 004662e2
 * Size: 607 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004662e2(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
        (iVar1 = FUN_0040d949(arg_1,7,3), iVar1 != 0)) &&
       ((((&DAT_006a2828)[1 - arg_1] | (&DAT_006a2828)[g_CurrentTurnPhase]) & 2) != 0)) {
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
    if (((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = FUN_0040d949(arg_1,7,3), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,3);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      if (local_c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
    }
    if (((arg_3 == 0x72) &&
        (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
       (iVar1 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,
                             (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20)),
       iVar1 != -1)) {
      *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0xfffe;
      *(undefined2 *)(&DAT_006a5f4a + iVar1 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


