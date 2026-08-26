/*
 * Decompiled function: Pic_Subsystem_0043f51d
 * Entry Point: 004d2318
 * Size: 1498 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043f51d(int spell_id,int target_id,int flags)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (flags == 1) {
    *(int *)(&DAT_0068f330 + spell_id * 0x20) = *(int *)(&DAT_0068f330 + spell_id * 0x20) + 2;
  }
  if (flags == 0x74) {
    FUN_0043071d(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar3 = FUN_004521e2(spell_id,target_id);
    uVar3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508f94,s_THE_BRUTE_00508f88);
      iVar4 = FUN_00468130(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,
                         arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_00682718)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x73) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
       (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      bVar1 = (&DAT_006826cc)
              [*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      cVar2 = (&DAT_006826e0)
              [*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      iVar4 = FUN_0049b68d(spell_id,target_id,4,3);
      if (iVar4 == 0 || (cVar2 != '\x02' || (bVar1 & 2) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
    else if (flags == 0x90) {
      FUN_0043071d(0);
      uVar3 = 0;
    }
    else {
      if (((flags == 0x6d) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
         (FUN_0042ecaf(spell_id,target_id,4,3), DAT_00681ea4 != 1)) {
        DAT_006664ec = 1;
        *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
      }
      if ((flags == 0x72) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
        *(undefined4 *)
         (&DAT_006826e4 +
         *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        FUN_0045962d((int)(char)(&DAT_006826d2)
                                [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) *
                                 0x5b20 + *(int *)(&DAT_006827b4 +
                                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120],
                     *(int *)(&DAT_006826e8 +
                             *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) *
                             0x5b20 + *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20
                                              ) * 0x120));
      }
      if ((((*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00690c48) &&
           ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_0068ecb0)) &&
          (DAT_00690c48 != -1)) &&
         ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 && (flags == 0x32)))
         ) {
        DAT_0066642c = DAT_0066642c + 1;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


