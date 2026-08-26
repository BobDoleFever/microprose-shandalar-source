/*
 * Decompiled function: Pic_Subsystem_004336f8
 * Entry Point: 004c64ff
 * Size: 934 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_004336f8(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  int local_18;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar4 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (DAT_00676510 == arg_1) {
        iVar5 = FUN_00439892(5);
        local_18 = iVar5 + 1;
      }
      else {
        local_8 = -1;
        for (local_c = 1; local_c < 7; local_c = local_c + 1) {
          if (local_8 < *(int *)(&DAT_0068ede0 + local_c * 4 + (1 - arg_1) * 0x20) +
                        *(int *)(&DAT_0068ee20 + local_c * 4 + (1 - arg_1) * 0x20)) {
            local_8 = *(int *)(&DAT_0068ee20 + local_c * 4 + (1 - arg_1) * 0x20) +
                      *(int *)(&DAT_0068ee20 + local_c * 4 + (1 - arg_1) * 0x20);
            local_18 = local_c;
          }
        }
      }
      if (arg_1 == 1) {
        local_1c = local_18;
      }
      else {
        local_1c = -1;
      }
      iVar5 = FUN_004513fa(arg_1,s_Jihad_color__00508b40,1,local_1c,0xffffffff);
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar5;
      if (iVar5 == -1) {
        DAT_00681ea4 = 1;
      }
    }
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       ((((byte)*(undefined4 *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x22) == 2 &&
        ((((byte)*(undefined4 *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) &
          0x22) == 2 &&
         (cVar1 = (&DAT_006826dc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120],
         bVar3 = FUN_004af7bb(arg_1,arg_2,5), (1 << (bVar3 & 0x1f) & (int)cVar1) != 0)))))) {
      if (arg_3 == 0x32) {
        DAT_0066642c = DAT_0066642c + 2;
      }
      else {
        DAT_0066642c = DAT_0066642c + 1;
      }
    }
    if (((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0) && (DAT_00690c48 == arg_2))
       && (DAT_0068ecb0 == arg_1)) {
      bVar2 = false;
      iVar5 = 1 - arg_1;
      bVar3 = (&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20];
      for (local_c = 0; local_c < (int)(&DAT_00666408)[iVar5]; local_c = local_c + 1) {
        iVar6 = FUN_0048a33f(iVar5,local_c);
        if (((iVar6 != 0) &&
            (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + iVar5 * 0x5b20) * 0x34] &
             0x1e) != 0)) &&
           ((1 << (bVar3 & 0x1f) & (int)(char)(&DAT_006826dd)[local_c * 0x120 + iVar5 * 0x5b20]) !=
            0)) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        FUN_0046e571(arg_1,arg_2,1);
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}


