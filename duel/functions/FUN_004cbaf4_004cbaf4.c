/*
 * Decompiled function: FUN_004cbaf4
 * Entry Point: 004cbaf4
 * Size: 1820 bytes
 */
#include "duel.h"


undefined4 FUN_004cbaf4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_98 [12];
  undefined1 *local_8c;
  undefined1 local_88 [128];
  undefined1 *local_8;
  
  local_8 = local_88;
  local_8c = local_98;
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508c90,s_PARALYZE_00508c84);
      iVar2 = FUN_00468130(param_1,2,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006827cc)
        [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] =
             (&DAT_006827cc)
             [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] + '\x04';
        if (DAT_00676504 == param_1) {
          if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == param_1) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
          }
          else if (((&DAT_004ff595)
                    [*(int *)(&DAT_006826c4 +
                             *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                             *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) *
                     0x34] == '\0') &&
                  (((&DAT_006826f9)
                    [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                     *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] & 8) == 0
                  )) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
          }
          else {
            DAT_0068f2d4 = DAT_0068f2d4 +
                           *(int *)(&DAT_00682700 +
                                   *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) *
                                   0x120 + (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]
                                           * 0x5b20) / 2;
          }
        }
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_00682718)[param_2 * 0x120 + param_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
        FUN_004a7b83((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                     *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20));
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (((param_3 == 0x82) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
        (DAT_00690c48 != -1)))) {
      *(uint *)(&DAT_006827c8 +
               *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006827c8 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) & 0xfffffffc
      ;
    }
    if (((((param_3 == 0x84) &&
          (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
         ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0)) &&
        ((DAT_00690c48 != -1 &&
         (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
            (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20] & 0x10) != 0)))) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00666458 &&
        (DAT_00666458 == DAT_00681eb4)))) {
      *(uint *)(&DAT_006827d4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
           *(uint *)(&DAT_006827d4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) | 0x10;
      (&DAT_006827cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] =
           (&DAT_006827cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] + '\x04';
    }
    uVar1 = 0;
  }
  return uVar1;
}


