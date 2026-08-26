/*
 * Decompiled function: FUN_004acbac
 * Entry Point: 004acbac
 * Size: 995 bytes
 */
#include "duel.h"


undefined4 FUN_004acbac(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    if (DAT_0068ecd0 == -1) {
      uVar3 = 0;
    }
    else if ((DAT_00676504 == arg_1) && (iVar2 = FUN_0049b309(arg_1,7,2), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      local_c = (int)(char)(&DAT_004ff598)
                           [*(int *)(&DAT_006826c4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20) *
                            0x34];
      if (local_c == -1) {
        local_c = DAT_00681ea0;
      }
      cVar1 = (&DAT_004ff597)
              [*(int *)(&DAT_006826c4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20) * 0x34];
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = cVar1 + local_c;
      iVar2 = FUN_0049b309(arg_1,2,1);
      if (((iVar2 == 0) || (iVar2 = FUN_0049b309(arg_1,7,cVar1 + local_c + 1), iVar2 == 0)) ||
         (iVar2 = Rules_ParseFilter_0041c0ab
                            (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,
                             -1,0xffffffff,0xffffffff,2,0,0), iVar2 == 0)) {
        uVar3 = 0;
      }
      else {
        DAT_0068ef44 = 1;
        uVar3 = 99;
      }
    }
  }
  else {
    if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
       (DAT_0068ecd0 != -1)) {
      DAT_0068ece8 = 1;
      Ai_CalcManaRequirement_004ba890
                (arg_1,0,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (DAT_00681ea4 != 1) {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        DAT_00681ea0 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (arg_3 == 0x71) {
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(undefined1 *)0x0,
                         arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (((&DAT_006826cc)
                [*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x20) != 0) {
        FUN_0046e571(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


