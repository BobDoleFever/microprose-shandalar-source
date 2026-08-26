/*
 * Decompiled function: Card_Sinbad_Draw
 * Entry Point: 004d1cc4
 * Size: 332 bytes
 */
#include "magic.h"


bool Card_Sinbad_Draw(int arg_1,int arg_2,int arg_3)

{
  int arg_5;
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_5 = FUN_0046f5d1(arg_1);
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,arg_1,arg_5,s_Sinbad_draws____0052e914,0);
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_1 * 0x5b20) * 0x34] & 1) == 0) {
        Pic_Subsystem_0044913a(arg_1,arg_5);
        *(undefined4 *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
        (&DAT_006b3008)[arg_1] = (&DAT_006b3008)[arg_1] + -1;
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x18);
        }
      }
    }
    bVar1 = false;
  }
  return bVar1;
}


