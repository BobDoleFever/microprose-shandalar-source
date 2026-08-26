/*
 * Decompiled function: FUN_0045cb9e
 * Entry Point: 0045cb9e
 * Size: 1222 bytes
 */
#include "duel.h"


bool FUN_0045cb9e(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    iVar2 = FUN_004680fc(arg_1,arg_2);
    bVar1 = 1 < iVar2;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_004680fc(arg_1,arg_2), 1 < iVar2)) {
      *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
      *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
      }
      FUN_0046801f(arg_1,arg_2,2);
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + 1;
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (iVar2 != -1) {
            *(undefined2 *)(&DAT_006826d8 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(undefined2 *)(&DAT_006826da + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) &&
        ((arg_1 == DAT_0068ecb0 && (DAT_0068eeac != 0)))) && (arg_1 == DAT_00681ec4)) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        FUN_00467e37(arg_1,arg_2);
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


