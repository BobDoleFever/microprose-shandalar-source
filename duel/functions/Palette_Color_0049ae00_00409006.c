/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 00409006
 * Size: 1451 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  int y;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if (flags == 0x74) {
    if ((DAT_00676504 == spell_id) && (iVar1 = FUN_0049b309(spell_id,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      if ((DAT_00681eb0._1_1_ & 4) == 0) {
        DAT_00681ea0 = 0;
        Ai_CalcManaRequirement_004ba890(spell_id,1,-1);
        if (DAT_00681ea4 == 1) {
          return 0;
        }
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_00681ea0;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&DAT_006826e4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20);
      }
      FUN_00434660(s_prompts_txt_004f2670,s_DRAIN_LIFE_004f2664);
      FUN_00461047(spell_id,target_id);
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      y = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      iVar3 = FUN_004612b0(spell_id,target_id,0x71,
                           *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20));
      if ((iVar3 == 0) || (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < 1)) {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      else {
        if (y == -1) {
          local_8 = *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
          if ((int)(&DAT_00681ea8)[iVar1] <=
              *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20)) {
            local_8 = (&DAT_00681ea8)[iVar1];
          }
        }
        else {
          iVar3 = FUN_0048b81a(iVar1,y,0x33,0xffffffff);
          if (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < iVar3) {
            local_8 = *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
          }
          else {
            local_8 = FUN_0048b81a(iVar1,y,0x33,0xffffffff);
          }
        }
        if (local_8 < 0) {
          local_8 = 0;
        }
        iVar1 = Pic_Subsystem_00451291(spell_id,DAT_0068eee8);
        if (iVar1 != -1) {
          *(undefined4 *)(&DAT_006826c0 + iVar1 * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20);
          *(uint *)(&DAT_006826cc + iVar1 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&DAT_006826cc + iVar1 * 0x120 + spell_id * 0x5b20) | 2;
          *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + spell_id * 0x5b20) = 0x44;
          *(undefined4 *)(&DAT_00682710 + iVar1 * 0x120 + spell_id * 0x5b20) = 0xd7;
          *(int *)(&DAT_006826e4 + iVar1 * 0x120 + spell_id * 0x5b20) = local_8;
          FUN_0048eb25(spell_id,iVar1);
          (&DAT_006826d3)[iVar1 * 0x120 + spell_id * 0x5b20] = (undefined1)spell_id;
          *(int *)(&DAT_006826ec + iVar1 * 0x120 + spell_id * 0x5b20) = target_id;
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    if (((flags == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) &&
       ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == -1 &&
        ((((char)(&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] == spell_id &&
          (*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == target_id)) &&
         (*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) != 0)))))) {
      (&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)DAT_0068ecb0;
      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) = DAT_00690c48;
    }
    uVar2 = 0;
  }
  return uVar2;
}


