/*
 * Decompiled function: FUN_004118a8
 * Entry Point: 004118a8
 * Size: 1776 bytes
 */
#include "magic.h"


undefined4 FUN_004118a8(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if ((((g_OverworldMapGrid == arg_2) && (g_OverworldPlayerCoordX == arg_1)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
     (((byte)g_PlayerHandCardCount & 4) != 0)) {
    uVar2 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),0x34,
                         0xffffffff);
    if ((uVar2 & 0x1ff800) != 0) {
      cVar1 = FUN_00473cc5((&DAT_006a5f4d)
                           [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                            + (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                              0x5b20]);
      if ((uVar2 & 0x800 << (cVar1 - 1U & 0x1f)) != 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
      }
    }
  }
  if (((arg_3 == 0x6e) && (g_OverworldMapGrid == arg_2)) &&
     ((g_OverworldPlayerCoordX == arg_1 &&
      (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)))) {
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    if (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0xe);
      }
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId +
                          *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                          0x5b20) * 0x34) == DAT_006a2848) {
        (&DAT_00700ec0)
        [(char)(&g_CardSlot_DamageReceived)
               [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] * 0xa0
         + (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] +
           *(int *)(&g_CardSlot_TypeFlags +
                   *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 2]
             = (&DAT_00700ec0)
               [(char)(&g_CardSlot_DamageReceived)
                      [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                       (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20]
                * 0xa0 + (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] +
                         *(int *)(&g_CardSlot_TypeFlags +
                                 *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                 0x120 + (char)(&g_CardSlot_DamageReceived)
                                               [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 2] +
               (char)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
        ;
      }
      else {
        (&DAT_00700ec0)
        [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 2 +
         (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0xa0 +
         (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
             (&DAT_00700ec0)
             [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 2 +
              (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0xa0 +
              (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] +
             (char)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      (&g_PlayerCreatureCount)[(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
           (&g_PlayerCreatureCount)[(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] -
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(int *)(&DAT_006b3030 + (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 4) =
           *(int *)(&DAT_006b3030 +
                   (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 4) +
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    else {
      iVar3 = FUN_00471c32((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
      if ((iVar3 != 0) &&
         (*(short *)(&g_CardSlot_Power +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
               *(short *)(&g_CardSlot_Power +
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) *
                         0x120 + (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                 0x5b20) +
               (short)*(undefined4 *)
                       (&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),
         g_IsAiThinking != 1)) {
        Magic_UpkeepPhase(0x16);
        Ai_Subsystem_004cc3f8
                  ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),6,2)
        ;
      }
    }
  }
  return 0;
}


