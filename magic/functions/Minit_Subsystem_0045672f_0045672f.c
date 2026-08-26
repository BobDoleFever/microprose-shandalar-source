/*
 * Decompiled function: Minit_Subsystem_0045672f
 * Entry Point: 0045672f
 * Size: 1364 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045672f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  int *arg_20;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int arg_15;
  uint uVar7;
  uint arg_17;
  uint uVar8;
  undefined1 *arg_18;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_18;
  uint local_14 [2];
  uint local_c;
  uint local_8;
  
  if (flags == 0x73) {
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0)))
       ) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if (DAT_006ff4ac == 0) {
        Ai_CalcManaRequirement_004ba890(spell_id,0,3);
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_005241d4,s_ARENA_005241cc);
          for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
            arg_20 = (int *)(((spell_id == 0) - 1 & (int)&local_c - (int)local_14) + (int)local_14);
            uVar3 = (uint)(spell_id == local_18);
            arg_18 = &g_OverworldGoldAmount;
            arg_17 = 0;
            uVar11 = 0;
            uVar10 = 0;
            uVar9 = 0xffffffff;
            uVar8 = 0xffffffff;
            iVar6 = -1;
            iVar5 = -1;
            uVar7 = 0;
            uVar4 = 0;
            uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
            iVar5 = Action_ValidateTarget_00405802
                              (spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,uVar4,uVar7,iVar5,iVar6,
                               uVar8,uVar9,uVar10,uVar11,arg_17,arg_18,uVar3,arg_20);
            if (iVar5 == 0) {
              g_ActivePlayer = 1;
            }
          }
          if (g_ActivePlayer != 1) {
            if (((((char)local_c == '\0') && ((local_8 & 0xffff) == 0)) &&
                ((local_14[0] & 0xffffff) == 0)) && (local_14[1] == 0)) {
              *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                   = 0;
            }
            else {
              *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                   = 1;
            }
          }
        }
      }
      else {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x72) {
      local_c = *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) >>
                0x18;
      local_8 = (*(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
                0xff0000) >> 0x10;
      local_14[0] = (uint)(byte)(&DAT_006a5f55)[target_id * 0x120 + spell_id * 0x5b20];
      local_14[1] = *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                    & 0xff;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,1,1,1,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6
                         ,uVar7,uVar8,uVar9,uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      arg_15 = -1;
      iVar6 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0040360b
                        (local_14[0],local_14[1],(char *)0x0,0,0,0,0x200,2,0,0,uVar2,uVar3,uVar4,
                         iVar6,arg_15,uVar7,uVar8,uVar9,uVar10,uVar11);
      if ((iVar5 == 0) || (iVar6 == 0)) {
        if ((iVar5 == 0) || (iVar6 != 0)) {
          if (((iVar5 == 0) && (iVar6 != 0)) &&
             (*(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) | 0x10,
             *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) != -1)) {
            iVar5 = FUN_00473179(local_c,local_8,0x32,0xffffffff);
            FUN_0041db67(local_14[0],local_14[1],iVar5,local_c,local_8);
          }
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) | 0x10;
          if (*(int *)(&g_CardSlot_CardId + local_14[1] * 0x120 + local_14[0] * 0x5b20) != -1) {
            iVar5 = FUN_00473179(local_14[0],local_14[1],0x32,0xffffffff);
            FUN_0041db67(local_c,local_8,iVar5,local_14[0],local_14[1]);
          }
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) | 0x10;
        *(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) | 0x10;
        iVar5 = FUN_00473179(local_c,local_8,0x32,0xffffffff);
        iVar6 = FUN_00473179(local_14[0],local_14[1],0x32,0xffffffff);
        FUN_0041db67(local_c,local_8,iVar6,local_14[0],local_14[1]);
        FUN_0041db67(local_14[0],local_14[1],iVar5,local_c,local_8);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


