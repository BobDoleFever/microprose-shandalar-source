/*
 * Decompiled function: FUN_0041b695
 * Entry Point: 0041b695
 * Size: 519 bytes
 */
#include "magic.h"


uint FUN_0041b695(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_10;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = (&DAT_006a2828)[arg_1] & 2;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (local_10 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_10;
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
      }
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
        FUN_0040d875(arg_1,1,(int)(char)(&DAT_0051aebf)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_OriginalCardId +
                                                         arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                                 (char)(&g_CardSlot_Toughness)
                                                       [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
                                         0x34] +
                             (int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_OriginalCardId +
                                                         arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                                 (char)(&g_CardSlot_Toughness)
                                                       [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
                                         0x34]);
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


