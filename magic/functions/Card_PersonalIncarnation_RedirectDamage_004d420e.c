/*
 * Decompiled function: Card_PersonalIncarnation_RedirectDamage
 * Entry Point: 004d420e
 * Size: 1364 bytes
 */
#include "magic.h"


undefined4 Card_PersonalIncarnation_RedirectDamage(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  INT_PTR local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x21) &&
      ((char)(&g_CardSlot_Toughness)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20]
       == spell_id)) &&
     (*(int *)(&g_CardSlot_OriginalCardId +
              g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == target_id)) {
    *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
  }
  if (flags == 0x73) {
    if ((((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0) ||
       (((byte)g_PlayerHandCardCount & 4) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       (((byte)g_PlayerHandCardCount & 4) != 0)) {
      if (((&DAT_006a5f3d)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) {
        local_18 = 0;
      }
      else {
        local_18 = 1;
      }
      do {
        Pic_Subsystem_00424500(s_prompts_txt_0052e9ec,s_PERSONAL_INCARNATION_0052e9d4);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,0,
                           0,&g_OverworldGoldAmount,1,&local_14);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else if (((char)(&g_CardSlot_Toughness)[local_14 * 0x5b20 + local_10 * 0x120] == spell_id)
                && (*(int *)(&g_CardSlot_OriginalCardId + local_14 * 0x5b20 + local_10 * 0x120) ==
                    target_id)) {
          if (*(int *)(&g_CardSlot_ConvertedManaCost + local_14 * 0x5b20 + local_10 * 0x120) +
              (int)*(short *)(&g_CardSlot_Power + target_id * 0x120 + spell_id * 0x5b20) < 6) {
            local_20 = 0;
          }
          else {
            local_20 = *(int *)(&g_CardSlot_ConvertedManaCost + local_14 * 0x5b20 + local_10 * 0x120
                               ) -
                       (5 - *(short *)(&g_CardSlot_Power + target_id * 0x120 + spell_id * 0x5b20));
          }
          local_8 = Ai_Subsystem_004cc8de
                              (spell_id,s_How_much_damage_to_redirect_to_y_0052e9f8,local_20);
          local_c = FUN_0041db67(local_18,-1,local_8,
                                 (int)(char)(&g_CardSlot_DamageReceived)
                                            [local_14 * 0x5b20 + local_10 * 0x120],
                                 *(int *)(&g_CardSlot_TypeFlags +
                                         local_14 * 0x5b20 + local_10 * 0x120));
          if (local_c != -1) {
            *(undefined4 *)(&DAT_006a5f74 + local_c * 0x120 + spell_id * 0x5b20) =
                 *(undefined4 *)(&DAT_006a5f74 + local_14 * 0x5b20 + local_10 * 0x120);
            *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
                 0xfffffffe;
            *(int *)(&g_CardSlot_ConvertedManaCost + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(int *)(&g_CardSlot_ConvertedManaCost + local_14 * 0x5b20 + local_10 * 0x120) -
                 local_8;
          }
        }
      } while ((g_ActivePlayer != 1) &&
              (((char)(&g_CardSlot_Toughness)[local_14 * 0x5b20 + local_10 * 0x120] != spell_id ||
               (*(int *)(&g_CardSlot_OriginalCardId + local_14 * 0x5b20 + local_10 * 0x120) !=
                target_id))));
    }
    if (flags == 0x25) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
           0xfffffffe;
    }
    if ((((flags == 0x77) && (target_id == g_OverworldMapGrid)) &&
        (spell_id == g_OverworldPlayerCoordX)) &&
       (iVar2 = Pic_Subsystem_00451291(spell_id,DAT_006ff564), iVar2 != -1)) {
      *(undefined4 *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + spell_id * 0x5b20) |
           CONCAT31((uint3)((uint)*(undefined4 *)
                                   (&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) >> 8)
                    & 0x10,2);
      *(undefined4 *)(&DAT_006a5f74 + iVar2 * 0x120 + spell_id * 0x5b20) = 0xb5;
      FUN_00476482(spell_id,iVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


