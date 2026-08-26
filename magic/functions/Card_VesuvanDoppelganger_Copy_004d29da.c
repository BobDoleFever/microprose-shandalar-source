/*
 * Decompiled function: Card_VesuvanDoppelganger_Copy
 * Entry Point: 004d29da
 * Size: 573 bytes
 */
#include "magic.h"


undefined4 Card_VesuvanDoppelganger_Copy(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052e9a0,s_VESUVAN_DOPPELGANGER_0052e988);
    iVar1 = Action_ValidateTarget_00405802
                      (spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &g_OverworldGoldAmount,1,(int *)local_c);
    if (iVar1 == 0) {
      Pic_Subsystem_0044867e(spell_id,target_id,1);
      g_ActivePlayer = 1;
    }
    else {
      (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = local_c[0];
      *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) = local_8;
    }
  }
  if (flags == 0x71) {
    *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
         *(undefined4 *)
          (&g_CardSlot_CardId +
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
    (&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20] =
         (&DAT_0051aebe)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) * 0x34];
    *(uint *)(&g_CardSlot_Abilities1 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + target_id * 0x120 + spell_id * 0x5b20) | 0x2000;
    Magic_TriggerCardEvent(spell_id,target_id,0x6c,1 - spell_id,0xffffffff);
  }
  return 0;
}


