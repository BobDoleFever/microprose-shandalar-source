/*
 * Decompiled function: FUN_0048d878
 * Entry Point: 0048d878
 * Size: 1062 bytes
 */
#include "duel.h"


undefined4 FUN_0048d878(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5)

{
  undefined4 uVar1;
  bool bVar2;
  int local_c;
  
  if (DAT_006764b8 < 0x20) {
    *(undefined4 *)(&DAT_0068f240 + DAT_006764b8 * 4) =
         *(undefined4 *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(uint *)(&DAT_0068f240 + DAT_006764b8 * 4) =
         *(uint *)(&DAT_0068f240 + DAT_006764b8 * 4) | arg_3 << 0x10;
    *(uint *)(&DAT_0068f240 + DAT_006764b8 * 4) =
         *(uint *)(&DAT_0068f240 + DAT_006764b8 * 4) | arg_4 << 0x18;
    if (((arg_3 == 0x71) || (arg_3 == 0x7e)) ||
       (*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) < 5)) {
      local_c = arg_2;
      bVar2 = true;
    }
    else {
      local_c = Pic_Subsystem_00451291(arg_1,DAT_0068eee0);
      if (local_c == -1) {
        bVar2 = false;
      }
      else {
        uVar1 = *(undefined4 *)(&DAT_006826f4 + arg_1 * 0x5b20 + local_c * 0x120);
        FID_conflict__memcpy
                  (&DAT_006826c0 + local_c * 0x120 + arg_1 * 0x5b20,
                   &DAT_006826c0 + arg_1 * 0x5b20 + arg_2 * 0x120,0x120);
        *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_c * 0x120) = DAT_0068eee0;
        *(undefined4 *)(&DAT_00682710 + arg_1 * 0x5b20 + local_c * 0x120) = 0;
        (&DAT_006826e0)[arg_1 * 0x5b20 + local_c * 0x120] = 0;
        if (*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
          *(undefined4 *)(&DAT_006826c0 + arg_1 * 0x5b20 + local_c * 0x120) =
               *(undefined4 *)(&DAT_006826c0 + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        else {
          *(undefined4 *)(&DAT_006826c0 + arg_1 * 0x5b20 + local_c * 0x120) =
               *(undefined4 *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        *(undefined4 *)(&DAT_00682704 + arg_1 * 0x5b20 + local_c * 0x120) =
             *(undefined4 *)(&DAT_00682704 + arg_2 * 0x120 + arg_1 * 0x5b20);
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_c * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_c * 0x120) | 2;
        *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + local_c * 0x120) = arg_1;
        *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + local_c * 0x120) = arg_2;
        *(undefined4 *)(&DAT_006826f4 + arg_1 * 0x5b20 + local_c * 0x120) = uVar1;
        bVar2 = true;
      }
    }
    if (bVar2) {
      (&DAT_0068efb0)[DAT_006764b8 * 2] = arg_1;
      *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8) = local_c;
      *(int *)(&DAT_0068f120 + DAT_006764b8 * 8) =
           (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20];
      *(undefined4 *)(&DAT_0068f124 + DAT_006764b8 * 8) =
           *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (DAT_0068f230 == -1) {
        *(undefined4 *)(&DAT_00666960 + DAT_006764b8 * 4) = DAT_0068f2c4;
      }
      else {
        *(int *)(&DAT_00666960 + DAT_006764b8 * 4) = DAT_0068f230;
      }
      if (DAT_0066aaf4 != 1) {
        *(undefined4 *)(&DAT_00666460 + DAT_006764b8 * 4) = arg_5;
      }
      DAT_006764b8 = DAT_006764b8 + 1;
      (&DAT_0068efb0)[DAT_006764b8 * 2] = 0xffffffff;
    }
  }
  return 0;
}


