/*
 * Decompiled function: FUN_004c6dbe
 * Entry Point: 004c6dbe
 * Size: 1401 bytes
 */
#include "duel.h"


undefined4 FUN_004c6dbe(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508b74,&DAT_00508b6c);
      iVar2 = FUN_00468130(param_1,param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
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
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
    }
    if ((DAT_0068f230 == 0xda) &&
       (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) {
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
      DAT_0068f230 = 0xffffffff;
      if (((((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00666458) &&
           ((((&DAT_006826cc)
              [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20] & 4) != 0 &&
            (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 2) != 0)))) &&
          ((&DAT_006826de)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] == -1)) &&
         (DAT_0068ecb0 != DAT_00666458)) {
        iVar2 = FUN_004c7337(DAT_0068ecb0,DAT_00690c48,
                             (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                             *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20));
        if (iVar2 != 0) {
          if ((&DAT_006826de)
              [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20] == -1) {
            local_8 = (undefined1)
                      *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20);
          }
          else {
            local_8 = (&DAT_006826de)
                      [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                       (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20];
          }
          if (param_3 == 0x7d) {
            DAT_0066642c = DAT_0066642c | 2;
          }
          if (param_3 == 0x7e) {
            (&DAT_006826de)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] = local_8;
            *(uint *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
                 *(uint *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) | 0x8008;
          }
        }
      }
      DAT_0068f230 = 0xda;
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


