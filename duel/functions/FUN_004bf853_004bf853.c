/*
 * Decompiled function: FUN_004bf853
 * Entry Point: 004bf853
 * Size: 1040 bytes
 */
#include "duel.h"


int FUN_004bf853(int arg1,int arg2)

{
  int iVar1;
  int arg1_00;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  undefined1 local_8;
  
  arg1_00 = 1 - arg1;
  iVar1 = *(int *)(&DAT_006826f4 + arg1 * 0x5b20 + arg2 * 0x120);
  iVar2 = Pic_Subsystem_00451291(arg1_00,*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120));
  if (iVar2 != -1) {
    FID_conflict__memcpy
              (&DAT_006826c0 + arg1_00 * 0x5b20 + iVar2 * 0x120,
               &DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20,0x120);
    if (*(int *)(&DAT_004ff590 + *(int *)(&DAT_006826c4 + iVar2 * 0x120 + arg1_00 * 0x5b20) * 0x34)
        != 0xab) {
      *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg1_00 * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg1_00 * 0x5b20) | 0x30000;
    }
    *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg1_00 * 0x5b20) =
         *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg1_00 * 0x5b20) & 0xfffffff3;
    *(int *)(&DAT_00690320 + iVar1 * 4) = arg1_00;
    *(int *)(&DAT_00681ee0 + iVar1 * 4) = iVar2;
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      for (local_18 = 0; local_18 < (int)(&DAT_00666408)[local_14]; local_18 = local_18 + 1) {
        local_8 = (undefined1)arg1_00;
        if (((char)(&DAT_006826d2)[local_18 * 0x120 + local_14 * 0x5b20] == arg1) &&
           (*(int *)(&DAT_006826e8 + local_18 * 0x120 + local_14 * 0x5b20) == arg2)) {
          (&DAT_006826d2)[local_18 * 0x120 + local_14 * 0x5b20] = local_8;
          *(int *)(&DAT_006826e8 + local_18 * 0x120 + local_14 * 0x5b20) = iVar2;
        }
        if (((char)(&DAT_006826d3)[local_18 * 0x120 + local_14 * 0x5b20] == arg1) &&
           (*(int *)(&DAT_006826ec + local_18 * 0x120 + local_14 * 0x5b20) == arg2)) {
          (&DAT_006826d3)[local_18 * 0x120 + local_14 * 0x5b20] = local_8;
          *(int *)(&DAT_006826ec + local_18 * 0x120 + local_14 * 0x5b20) = iVar2;
        }
        if ((&DAT_006827b8)[local_18 * 0x120 + local_14 * 0x5b20] != '\0') {
          for (local_1c = 0; local_1c < (char)(&DAT_006827b8)[local_18 * 0x120 + local_14 * 0x5b20];
              local_1c = local_1c + 1) {
            if ((*(int *)(&DAT_00682718 + local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) ==
                 arg1) &&
               (*(int *)(&DAT_0068271c + local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) ==
                arg2)) {
              *(int *)(&DAT_00682718 + local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) =
                   arg1_00;
              *(int *)(&DAT_0068271c + local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) = iVar2;
            }
          }
        }
      }
    }
  }
  *(uint *)(&DAT_006826f8 + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint *)(&DAT_006826f8 + arg1 * 0x5b20 + arg2 * 0x120) | 8;
  FUN_0046e571(arg1,arg2,4);
  return iVar2;
}


