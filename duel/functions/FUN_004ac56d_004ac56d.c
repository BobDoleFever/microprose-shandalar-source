/*
 * Decompiled function: FUN_004ac56d
 * Entry Point: 004ac56d
 * Size: 1594 bytes
 */
#include "duel.h"


undefined4 FUN_004ac56d(int arg_1,int arg_2,int arg_3)

{
  int arg_2_00;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_8;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    if (DAT_0068ecd0 == -1) {
      uVar2 = 0;
    }
    else if ((DAT_00676504 == arg_1) && (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      iVar1 = Rules_ParseFilter_0041c0ab
                        (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (DAT_0068ecd0 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(undefined1 *)0x0,
                         arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar1 = *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20);
        arg_2_00 = *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
        if (iVar1 == DAT_00676510) {
          FUN_0048d878(arg_1,arg_2,0x7e,0,0);
          local_8 = Ai_CalcManaRequirement_004ba890
                              (iVar1,0,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
          FUN_0048e251();
          DAT_00681ea4 = 0;
        }
        else {
          iVar3 = FUN_0049b309(iVar1,7,1);
          if (iVar3 == 0) {
            local_8 = 0;
          }
          else {
            local_8 = Ai_CalcManaRequirement_004ba890
                                (iVar1,0,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
          }
        }
        if (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          local_14 = 0;
          while ((local_14 < 7 &&
                 (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)))) {
            for (; (0 < *(int *)(&DAT_0068f2e0 + local_14 * 4 + iVar1 * 0x20) &&
                   (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)));
                local_8 = local_8 + 1) {
              *(int *)(&DAT_0068f2e0 + local_14 * 4 + iVar1 * 0x20) =
                   *(int *)(&DAT_0068f2e0 + local_14 * 4 + iVar1 * 0x20) + -1;
              *(int *)(&DAT_0068f2fc + iVar1 * 0x20) = *(int *)(&DAT_0068f2fc + iVar1 * 0x20) + -1;
            }
            local_14 = local_14 + 1;
          }
          local_18 = 0;
          while ((local_18 < (int)(&DAT_00666408)[iVar1] &&
                 (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)))) {
            iVar3 = FUN_0048a33f(iVar1,local_18);
            if (((iVar3 != 0) &&
                ((((&DAT_004ff594)
                   [*(int *)(&DAT_006826c4 + local_18 * 0x120 + iVar1 * 0x5b20) * 0x34] & 1) != 0 &&
                 (((&DAT_006826cc)[local_18 * 0x120 + iVar1 * 0x5b20] & 0x10) == 0)))) &&
               ((((&DAT_006826ce)[local_18 * 0x120 + iVar1 * 0x5b20] & 3) == 0 ||
                (((&DAT_004ff594)
                  [*(int *)(&DAT_006826c4 + local_18 * 0x120 + iVar1 * 0x5b20) * 0x34] & 2) == 0))))
            {
              FUN_0042dd5e(iVar1,local_18);
              local_14 = 0;
              while ((local_14 < 7 &&
                     (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)))) {
                for (; (0 < *(int *)(&DAT_0068f2e0 + local_14 * 4 + iVar1 * 0x20) &&
                       (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)));
                    local_8 = local_8 + 1) {
                  *(int *)(&DAT_0068f2e0 + local_14 * 4 + iVar1 * 0x20) =
                       *(int *)(&DAT_0068f2e0 + local_14 * 4 + iVar1 * 0x20) + -1;
                  *(int *)(&DAT_0068f2fc + iVar1 * 0x20) =
                       *(int *)(&DAT_0068f2fc + iVar1 * 0x20) + -1;
                }
                local_14 = local_14 + 1;
              }
            }
            local_18 = local_18 + 1;
          }
        }
        if (local_8 < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          FUN_0046e571(iVar1,arg_2_00,1);
        }
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


