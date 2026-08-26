/*
 * Decompiled function: Minit_Subsystem_0045a9ff
 * Entry Point: 0045a9ff
 * Size: 1858 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045a9ff(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (flags == 0x73) {
    if ((g_ActivePlayerPriority == spell_id) &&
       (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_0042475a(s_prompts_txt_005243c8,s_URZAS_AVENGER_005243b8);
      iVar2 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,0);
      *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = iVar2 + 1;
      if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 5) {
        g_ActivePlayer = 1;
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    if (flags == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        if (((&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] == -1) &&
           (*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) == -1)) {
          local_8 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                                 g_DuelArenaHwnd);
          if (local_8 != -1) {
            *(undefined4 *)(&g_CardSlot_Abilities2 + local_8 * 0x120 + spell_id * 0x5b20) = 0;
            (&g_CardSlot_DamageReceived)
            [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
                 (undefined1)spell_id;
            *(int *)(&g_CardSlot_TypeFlags +
                    *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                    + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120) = local_8;
          }
        }
        else {
          local_8 = *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20);
        }
        if (local_8 != -1) {
          switch(*(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20)) {
          case 1:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x20;
            break;
          case 2:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x40;
            break;
          case 3:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x100;
            break;
          case 4:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x80;
          }
          *(short *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) =
               *(short *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) + 1;
          *(short *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) =
               *(short *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) + 1;
        }
        *(undefined4 *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0x8000000;
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20) + -1;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20) + -1;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                             * 0x5b20) + 1;
        *(undefined4 *)
         (&g_CardSlot_TargetSlot +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
      }
    }
    if ((flags == 0x22) || (flags == 199)) {
      *(short *)(&DAT_006a5f48 + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&DAT_006a5f48 + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(undefined4 *)
                   (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      *(short *)(&DAT_006a5f4a + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&DAT_006a5f4a + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(undefined4 *)
                   (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
           (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
    }
    uVar1 = 0;
  }
  return uVar1;
}


