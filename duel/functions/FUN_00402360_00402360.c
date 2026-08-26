/*
 * Decompiled function: FUN_00402360
 * Entry Point: 00402360
 * Size: 477 bytes
 */
#include "duel.h"


undefined4 FUN_00402360(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_1c;
  int aiStack_14 [4];
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      for (aiStack_14[2] = 0; aiStack_14[2] < 2; aiStack_14[2] = aiStack_14[2] + 1) {
        if (*(int *)(&DAT_006669f0 + aiStack_14[2] * 2000) == -1) {
          aiStack_14[aiStack_14[2]] = 0;
        }
        else {
          aiStack_14[3] =
               Ai_Subsystem_004cc56d
                         (aiStack_14[2],arg_1,arg_2,-1,-1,
                          s_Ante_an_additional_card__No_addi_004f20e8,
                          (uint)(0xf < (int)(&DAT_00681ea8)[aiStack_14[2]]));
          if (aiStack_14[3] == 0) {
            aiStack_14[aiStack_14[2]] = 1;
          }
          else {
            aiStack_14[aiStack_14[2]] = 0;
          }
        }
      }
      for (aiStack_14[2] = 0; aiStack_14[2] < 2; aiStack_14[2] = aiStack_14[2] + 1) {
        if (aiStack_14[aiStack_14[2]] != 0) {
          (&DAT_00681ea8)[aiStack_14[2]] = 0x14;
          for (local_1c = 0;
              ((&DAT_0068ed50)[aiStack_14[2] * 0x10 + local_1c] != -1 && (local_1c < 0x10));
              local_1c = local_1c + 1) {
          }
          if (local_1c < 0x10) {
            uVar1 = *(undefined4 *)(&DAT_006669f0 + aiStack_14[2] * 2000);
            FUN_004d7acc(aiStack_14[2],0);
            (&DAT_0068ed50)[aiStack_14[2] * 0x10 + local_1c] = uVar1;
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


