/*
 * Decompiled function: FUN_00418380
 * Entry Point: 00418380
 * Size: 981 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x00418726) */

undefined4 FUN_00418380(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0xc;
  }
  if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0) &&
       (iVar2 = FUN_0049b309(arg_1,7,2), iVar2 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar3 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0049b309(arg_1,7,2), iVar2 != 0)) {
      if (local_c == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,0,2);
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
        (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) = local_c;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1)) {
      iVar2 = FUN_004a2b00(arg_1,arg_2,DAT_00667994,
                           (int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120],
                           *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120));
      if (iVar2 != -1) {
        cVar1 = FUN_004af74c(arg_1,arg_2,2);
        *(int *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1 << (cVar1 - 1U & 0x1f);
      }
      *(undefined4 *)
       (&DAT_006826fc +
       *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
       (char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) = 0x8000000;
      FUN_00418755(arg_1,arg_2,*(uint *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120));
      *(undefined4 *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0xffffffff;
      (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] =
           (&DAT_006826e8)[arg_1 * 0x5b20 + arg_2 * 0x120];
    }
    if ((((arg_3 == 0x77) && (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) != 0)) &&
        (iVar2 = FUN_00418795(arg_1,arg_2), DAT_0068eef0 == DAT_0068ecb0)) &&
       (DAT_00690c48 == iVar2)) {
      FUN_0046e571(arg_1,arg_2,2);
    }
    uVar3 = 0;
  }
  return uVar3;
}


