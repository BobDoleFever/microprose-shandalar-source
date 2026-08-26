/*
 * Decompiled function: FUN_0045d774
 * Entry Point: 0045d774
 * Size: 746 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d774(int arg_1,int arg_2,int arg_3)

{
  short sVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 != 0x73) {
    if (arg_3 == 0x90) {
      FUN_0043071d(0);
    }
    else {
      if ((arg_3 == 0x6d) &&
         ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
        if (local_c == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
          *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
        }
      }
      if (arg_3 == 0x72) {
        iVar2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,
                             (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
        if (iVar2 != -1) {
          sVar1 = FUN_0048b81a((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),0x32,
                               0xffffffff);
          *(short *)(&DAT_006826d8 + iVar2 * 0x120 + arg_1 * 0x5b20) = -sVar1;
        }
        *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
  }
  return;
}


