/*
 * Decompiled function: FUN_004d3084
 * Entry Point: 004d3084
 * Size: 1028 bytes
 */
#include "duel.h"


undefined4 FUN_004d3084(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 6;
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) &&
       (iVar2 = FUN_00404b06(param_1,*(undefined4 *)
                                      (&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20),param_1),
       iVar2 == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ef68 + DAT_00676510 * 0x20) +
                      *(int *)(&DAT_0068ede0 + DAT_00676510 * 0x20) / 2 +
                     *(int *)(&DAT_0068ef6c + DAT_00676510 * 0x20)) * 0x18;
    }
    if (param_3 == 0x73) {
      if ((((byte)DAT_00681eb0 & 4) != 0) && (iVar2 = FUN_0049b68d(param_1,param_2,7,2), iVar2 != 0)
         ) {
        iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,
                             DAT_0068f104,0xffffffff,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar2 != 0) {
          return 99;
        }
      }
      uVar1 = 0;
    }
    else {
      if (((param_3 == 0x6d) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0))
         && (FUN_0042ecaf(param_1,param_2,0,2), DAT_00681ea4 != 1)) {
        FUN_00434660(s_prompts_txt_00508ff4,s_CIRCLE_OF_PROTECTION_00508fdc);
        iVar2 = FUN_0041e2a2(param_1,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,DAT_0068f104,
                             0xffffffff,0xffffffff,0xffffffff,0x20,0,0,&DAT_006679f0,1,&local_10);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
          *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      }
      if (param_3 == 0x72) {
        iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                             param_1,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,DAT_0068f104,
                             0xffffffff,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (*(int *)(&DAT_006826e4 +
                         *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                         *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) != 0)
        {
          *(undefined4 *)
           (&DAT_006826e4 +
           *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = 0;
        }
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


