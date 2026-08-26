/*
 * Decompiled function: Prompts_Load_004ae01a
 * Entry Point: 004ae01a
 * Size: 1704 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004ae01a(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_524;
  int local_520;
  int local_51c;
  int local_518;
  int local_514 [80];
  int local_3d4;
  int local_3d0;
  int local_3cc;
  int aiStack_3c8 [160];
  int local_148 [80];
  int local_8;
  
  if (flags == 0x74) {
    FUN_0043071d(0);
    if (((byte)DAT_00681eb0 & 4) == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,
                           0xffffffff,0xffffffff,0x20,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if ((((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) &&
       (((byte)DAT_00681eb0 & 4) != 0)) {
      FUN_00434660(s_prompts_txt_0050650c,s_SAMITE_HEALER_005064fc);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0x20,0
                         ,0,&DAT_006679f0,1,&local_524);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_524;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_520;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x71) {
      if (((byte)DAT_00681eb0 & 4) == 0) {
        local_3d4 = 0;
        local_51c = 0;
        for (local_3d0 = 0; local_3d0 < 2; local_3d0 = local_3d0 + 1) {
          for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
            if ('\0' < (char)(&DAT_00690b00)[spell_id + local_3d0 * 0xa0 + local_8 * 2]) {
              aiStack_3c8[local_3d4 * 2] = local_3d0;
              aiStack_3c8[local_3d4 * 2 + 1] = local_8;
              local_514[local_3d4] =
                   (int)(char)(&DAT_00690b00)[spell_id + local_3d0 * 0xa0 + local_8 * 2];
              if (*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_3d0 * 0x5b20) == -1) {
                local_148[local_3d4] =
                     *(int *)(&DAT_006826c0 + local_8 * 0x120 + local_3d0 * 0x5b20);
                local_3d4 = local_3d4 + 1;
              }
              else {
                local_148[local_3d4] =
                     *(int *)(&DAT_006826c4 + local_8 * 0x120 + local_3d0 * 0x5b20);
                local_3d4 = local_3d4 + 1;
              }
            }
          }
        }
        if (0 < local_3d4) {
          if ((spell_id == 1) || (DAT_0066aaf4 == 1)) {
            local_51c = 0;
            for (local_518 = 0; local_518 < local_3d4; local_518 = local_518 + 1) {
              if (local_51c < local_514[local_518]) {
                local_51c = local_518;
              }
            }
            local_3cc = local_51c;
          }
          else {
            local_3cc = FUN_004d65f2(spell_id,local_148,(int)local_514,local_3d4,
                                     s_Select_the_card_that_has_damaged_0050651c,1,&DAT_00506518);
          }
          (&DAT_00681ea8)[spell_id] =
               (&DAT_00681ea8)[spell_id] +
               (char)(&DAT_00690b00)
                     [spell_id +
                      aiStack_3c8[local_3cc * 2] * 0xa0 + aiStack_3c8[local_3cc * 2 + 1] * 2] * 2;
          (&DAT_00690b00)
          [spell_id + aiStack_3c8[local_3cc * 2] * 0xa0 + aiStack_3c8[local_3cc * 2 + 1] * 2] = 0;
        }
        if ((int)(&DAT_00681ea8)[1 - spell_id] < 1) {
          DAT_0068f2d4 = DAT_0068f2d4 + 1000;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (local_51c * 100) / (int)(&DAT_00681ea8)[1 - spell_id] + -100;
        }
      }
      else {
        local_524 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
        local_520 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
        iVar1 = Rules_ParseFilter_0041c0ab
                          (local_524,local_520,(undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                           DAT_0068f104,-1,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar1 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (*(int *)(&DAT_006826e4 + local_524 * 0x5b20 + local_520 * 0x120) != 0) {
          (&DAT_00681ea8)[spell_id] =
               (&DAT_00681ea8)[spell_id] +
               (char)(&DAT_00690b00)
                     [spell_id +
                      (char)(&DAT_006826d3)[local_524 * 0x5b20 + local_520 * 0x120] * 0xa0 +
                      *(int *)(&DAT_006826ec + local_524 * 0x5b20 + local_520 * 0x120) * 2] * 2 +
               *(int *)(&DAT_006826e4 + local_524 * 0x5b20 + local_520 * 0x120);
          *(undefined4 *)(&DAT_006826e4 + local_524 * 0x5b20 + local_520 * 0x120) = 0;
        }
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


