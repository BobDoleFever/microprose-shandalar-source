/*
 * Decompiled function: Ai_Subsystem_004c7aa8
 * Entry Point: 004c7aa8
 * Size: 317 bytes
 */
#include "magic.h"


void Ai_Subsystem_004c7aa8(int arg_1)

{
  undefined4 uVar1;
  int local_c;
  
  uVar1 = DAT_0067bdb0;
  DAT_0067bdb0 = 2;
  Ai_Subsystem_004c4c84(arg_1);
  DAT_005597b8 = (uint)(g_CurrentTurnPhase != arg_1);
  DAT_0055a008 = 0xffffd8f1;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00559738 + local_c * 4) = 0;
  }
  Ai_Subsystem_004c7be5(arg_1,0);
  if ((g_IsAiThinking == 1) || (g_DefendingPlayer == g_CurrentTurnPhase)) {
    for (local_c = 0; local_c < DAT_00559b1c; local_c = local_c + 1) {
      (&g_CardSlot_ColorMask)[DAT_00559a20 * 0x5b20 + (&DAT_0055a050)[local_c] * 0x120] =
           (&DAT_005597c0)[local_c * 4];
      if (g_IsAiThinking != 1) {
        Ai_Subsystem_004cc3f8(DAT_00559a20,(&DAT_0055a050)[local_c],5,2);
      }
    }
  }
  DAT_0067bdb0 = uVar1;
  return;
}


