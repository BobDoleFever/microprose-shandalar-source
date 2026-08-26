/*
 * Decompiled function: FUN_00465f8b
 * Entry Point: 00465f8b
 * Size: 1959 bytes
 */
#include "duel.h"


undefined4 FUN_00465f8b(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_18;
  int local_10;
  
  if (((param_3 == 0x3c) && (*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) != -1)) &&
     ((&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] != -1)) {
    (&DAT_006827df)
    [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
     (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] =
         (&DAT_006827df)
         [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
          (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] | 0x3f;
  }
  if (param_3 == 0x74) {
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_004f8e40,s_VENOM_004f8e38);
      iVar3 = FUN_00468130(param_1,param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (param_3 == 0x71) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120),
                           *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120),0,
                           param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] =
             (&DAT_00682718)[param_1 * 0x5b20 + param_2 * 0x120];
        *(undefined4 *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) =
             *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
      }
      (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
    }
    if (param_3 == 0x1a) {
      iVar3 = 1 - (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120];
      if (((char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] == DAT_00666458) &&
         (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
            (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] & 0x44) != 0)) {
        if ((&DAT_006826de)
            [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
             (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] == -1) {
          local_18 = *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120);
        }
        else {
          local_18 = (int)(char)(&DAT_006826de)
                                [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) *
                                 0x120 + (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] *
                                         0x5b20];
        }
        for (local_10 = 0; local_10 < (int)(&DAT_00666408)[iVar3]; local_10 = local_10 + 1) {
          if ((((char)(&DAT_006826de)[iVar3 * 0x5b20 + local_10 * 0x120] == local_18) &&
              ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + local_10 * 0x120) * 0x34]
               != '\0')) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + local_10 * 0x120) * 0x34] &
              2) != 0)) {
            FUN_004a2b00(param_1,param_2,DAT_006764c0,iVar3,local_10);
          }
        }
      }
      if (((char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] != DAT_00666458) &&
         ((&DAT_006826de)
          [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
           (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] != -1)) {
        cVar1 = (&DAT_006826de)
                [iVar3 * 0x5b20 +
                 (char)(&DAT_006826de)
                       [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                        (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20] * 0x120]
        ;
        if (cVar1 == -1) {
          FUN_004a2b00(param_1,param_2,DAT_006764c0,iVar3,
                       (int)(char)(&DAT_006826de)
                                  [*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) *
                                   0x120 + (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120]
                                           * 0x5b20]);
        }
        else {
          for (local_10 = 0; local_10 < (int)(&DAT_00666408)[iVar3]; local_10 = local_10 + 1) {
            iVar4 = FUN_0048a33f(iVar3,local_10);
            if ((iVar4 != 0) && ((&DAT_006826de)[iVar3 * 0x5b20 + local_10 * 0x120] == cVar1)) {
              FUN_004a2b00(param_1,param_2,DAT_006764c0,iVar3,local_10);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


