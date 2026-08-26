/*
 * Decompiled function: FUN_004559ad
 * Entry Point: 004559ad
 * Size: 1364 bytes
 */
#include "duel.h"


undefined4 FUN_004559ad(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((param_3 == 0x21) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == param_1)) &&
     (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == param_2)) {
    *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) | 1;
  }
  if (param_3 == 0x73) {
    if ((((&DAT_006826e4)[param_2 * 0x120 + param_1 * 0x5b20] & 1) == 0) ||
       (((byte)DAT_00681eb0 & 4) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 99;
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if (((param_3 == 0x6d) && (((&DAT_006826e4)[param_2 * 0x120 + param_1 * 0x5b20] & 1) != 0)) &&
       (((byte)DAT_00681eb0 & 4) != 0)) {
      if (((&DAT_006826cd)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0) {
        local_18 = 0;
      }
      else {
        local_18 = 1;
      }
      do {
        FUN_00434660(s_prompts_txt_004f8880,s_PERSONAL_INCARNATION_004f8868);
        iVar2 = FUN_0041e2a2(param_1,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,0xffffffff,
                             0xffffffff,0,0,0,&DAT_006679f0,1,&local_14);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (((char)(&DAT_006826d2)[local_10 * 0x120 + local_14 * 0x5b20] == param_1) &&
                (*(int *)(&DAT_006826e8 + local_10 * 0x120 + local_14 * 0x5b20) == param_2)) {
          if (*(int *)(&DAT_006826e4 + local_10 * 0x120 + local_14 * 0x5b20) +
              (int)*(short *)(&DAT_006826d0 + param_2 * 0x120 + param_1 * 0x5b20) < 6) {
            local_20 = 0;
          }
          else {
            local_20 = *(int *)(&DAT_006826e4 + local_10 * 0x120 + local_14 * 0x5b20) -
                       (5 - *(short *)(&DAT_006826d0 + param_2 * 0x120 + param_1 * 0x5b20));
          }
          local_8 = FUN_0045139b(param_1,s_How_much_damage_to_redirect_to_y_004f888c,local_20);
          local_c = FUN_004af950(local_18,0xffffffff,local_8,
                                 (int)(char)(&DAT_006826d3)[local_10 * 0x120 + local_14 * 0x5b20],
                                 *(undefined4 *)
                                  (&DAT_006826ec + local_10 * 0x120 + local_14 * 0x5b20));
          if (local_c != -1) {
            *(undefined4 *)(&DAT_00682704 + local_c * 0x120 + param_1 * 0x5b20) =
                 *(undefined4 *)(&DAT_00682704 + local_10 * 0x120 + local_14 * 0x5b20);
            *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffffffe;
            *(int *)(&DAT_006826e4 + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(int *)(&DAT_006826e4 + local_14 * 0x5b20 + local_10 * 0x120) - local_8;
          }
        }
      } while ((DAT_00681ea4 != 1) &&
              (((char)(&DAT_006826d2)[local_10 * 0x120 + local_14 * 0x5b20] != param_1 ||
               (*(int *)(&DAT_006826e8 + local_10 * 0x120 + local_14 * 0x5b20) != param_2))));
    }
    if (param_3 == 0x25) {
      *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffffffe;
    }
    if ((((param_3 == 0x77) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) &&
       (iVar2 = FUN_004d695b(param_1,DAT_0068f2d0), iVar2 != -1)) {
      *(undefined4 *)(&DAT_006826c0 + param_1 * 0x5b20 + iVar2 * 0x120) =
           *(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20);
      *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + iVar2 * 0x120) =
           *(uint *)(&DAT_006826cc + param_1 * 0x5b20 + iVar2 * 0x120) |
           CONCAT31((uint3)((uint)*(undefined4 *)
                                   (&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) >> 8) & 0x10
                    ,2);
      *(undefined4 *)(&DAT_00682704 + param_1 * 0x5b20 + iVar2 * 0x120) = 0xb5;
      FUN_0048eb25(param_1,iVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


