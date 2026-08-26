/*
 * Decompiled function: Magic_EndTurnPhase
 * Entry Point: 004756a1
 * Size: 1295 bytes
 */
#include "magic.h"


undefined4 Magic_EndTurnPhase(void)

{
  int arg_1;
  int arg_2;
  int local_c;
  
  if (0 < DAT_006a3f78) {
    DAT_006a3f78 = DAT_006a3f78 + -1;
    arg_1 = (&DAT_006fecc0)[DAT_006a3f78 * 2];
    arg_2 = *(int *)(&DAT_006fecc4 + DAT_006a3f78 * 8);
    local_c = *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
    if (DAT_006fd3f4 == local_c) {
      local_c = *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
      if ((char)((uint)*(undefined4 *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) >> 0x10) == '~') {
        Pic_Subsystem_004485d6
                  (arg_1,arg_2,*(uint *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) >> 0x10 & 0xff,
                   *(int *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) >> 0x18);
      }
      else if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) == 0) {
        if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x80) == 0) {
          Magic_TriggerCardEvent
                    (arg_1,arg_2,*(uint *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) >> 0x10 & 0xff,
                     1 - arg_1,0xffffffff);
        }
        else {
          if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x40) != 0) {
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) *
                          0x120 + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                  0x5b20) & 0xffffffef;
            Magic_TriggerCardEvent
                      (*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20),
                       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20),0x83,
                       1 - arg_1,0xffffffff);
          }
          *(uint *)(&g_CardSlot_SpecialState +
                   *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_SpecialState +
                        *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
               & 0xffffff7f;
        }
      }
      else {
        if (((((&DAT_006a6045)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0) &&
            (Magic_TriggerCardEvent(arg_1,arg_2,0x86,1 - arg_1,0xffffffff),
            *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
           (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20),1);
        }
        *(uint *)(&g_CardSlot_SpecialState +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
             0xfffffdf7;
        *(uint *)(&g_CardSlot_SpecialState +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 4;
      }
      if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_006fd3f4) {
        Pic_Subsystem_0044867e(arg_1,arg_2,4);
      }
    }
    (&DAT_006fecc0)[DAT_006a3f78 * 2] = 0xffffffff;
    FUN_00472fae();
    if (((((&DAT_0051aed1)[local_c * 0x34] & 0x10) == 0) || (((byte)g_PlayerHandCardCount & 2) != 0)
        ) && ((DAT_006fd3f0 < 2 && (((g_PlayerHandCardCount._1_1_ & 2) == 0 || (DAT_006a3f78 == 0)))
              ))) {
      Pic_Subsystem_004475a4(g_DefendingPlayer);
      Pic_Subsystem_004488a0();
    }
  }
  return 0;
}


