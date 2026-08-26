/*
 * Decompiled function: Glue_Subsystem_004d9afd
 * Entry Point: 0045b29a
 * Size: 1153 bytes
 */
#include "duel.h"


void Glue_Subsystem_004d9afd(int arg_1,int arg_2,int arg_3)

{
  int arg_4;
  int local_94;
  int local_90;
  int local_88;
  int local_80 [30];
  int local_8;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f324 + arg_1 * 0x20) = *(int *)(&DAT_0068f324 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    FUN_0049b309(arg_1,1,3);
  }
  else {
    if (((arg_3 == 0x6d) &&
        ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,1,3), DAT_00681ea4 != 1)) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_4 = 1 - arg_1;
      if (((DAT_0066aaf4 != 1) && (arg_1 == 0)) && (DAT_0068f0b0 == 0)) {
        local_90 = 0;
        for (local_88 = 0; local_88 < DAT_0066640c; local_88 = local_88 + 1) {
          if ((*(int *)(&DAT_006881e4 + local_88 * 0x120) != -1) &&
             (((&DAT_006881ec)[local_88 * 0x120] & 2) == 0)) {
            local_80[local_90] = *(int *)(&DAT_006881e4 + local_88 * 0x120);
            local_90 = local_90 + 1;
          }
        }
        if (DAT_0066aaf4 != 1) {
          Palette_Subsystem_004a5722(0,local_80,local_90,s_Opponent_s_Hand_004f8998,0,&DAT_004f8990)
          ;
        }
      }
      local_90 = 0;
      do {
        local_94 = FUN_00439892((&DAT_00666408)[arg_4]);
        local_90 = local_90 + 1;
        if (0x3e6 < local_90) break;
      } while (((*(int *)(&DAT_006826c4 + arg_4 * 0x5b20 + local_94 * 0x120) == -1) ||
               (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_4 * 0x5b20 + local_94 * 0x120) * 0x34]
                & 2) == 0)) || (((&DAT_006826cc)[arg_4 * 0x5b20 + local_94 * 0x120] & 2) != 0));
      if (local_90 < 999) {
        local_8 = 1;
      }
      else {
        local_8 = 0;
        local_88 = 0;
        while ((local_88 < (int)(&DAT_00666408)[arg_4] && (local_8 == 0))) {
          if ((*(int *)(&DAT_006826c4 + local_88 * 0x120 + arg_4 * 0x5b20) != -1) &&
             ((((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_88 * 0x120 + arg_4 * 0x5b20) * 0x34]
               & 2) != 0 && (((&DAT_006826cc)[local_88 * 0x120 + arg_4 * 0x5b20] & 2) == 0)))) {
            local_8 = 1;
            local_94 = local_88;
          }
          local_88 = local_88 + 1;
        }
      }
      if (local_8 != 0) {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x19);
        }
        if (DAT_0066aaf4 != 1) {
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,arg_4,local_94,s_Randomly_chose_this_creature_to_d_004f89a8,0
                    );
        }
        FUN_0046f02d(arg_4,local_94);
        *(undefined4 *)(&DAT_006826c4 + arg_4 * 0x5b20 + local_94 * 0x120) = 0xffffffff;
        (&DAT_0068ee78)[arg_4] = (&DAT_0068ee78)[arg_4] + -1;
      }
    }
  }
  return;
}


