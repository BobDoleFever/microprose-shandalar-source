/*
 * Decompiled function: FUN_00435e6e
 * Entry Point: 00435e6e
 * Size: 1061 bytes
 */
#include "duel.h"


undefined4 FUN_00435e6e(int arg_1,byte *arg_2,int arg_3,int arg_4,int arg_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  size_t arg_3_00;
  byte *pbVar19;
  byte *pbVar20;
  byte *ptr_1;
  void *ptr_1_00;
  byte *local_1c;
  int local_18;
  int local_10;
  
  ptr_1 = arg_2;
  arg_3_00 = arg_3 * 3;
  ptr_1_00 = _malloc((arg_3_00 + arg_5) * arg_4 + 0x10);
  if (DAT_005162b8 == 0) {
    for (local_10 = -0x200; local_10 < 0x200; local_10 = local_10 + 1) {
      if ((local_10 < 0) || (0xff < local_10)) {
        if (local_10 < 0) {
          PTR_DAT_004f5428[local_10] = 0;
        }
        else {
          PTR_DAT_004f5428[local_10] = 0xff;
        }
      }
      else {
        PTR_DAT_004f5428[local_10] = (undefined1)local_10;
      }
    }
    DAT_005162b8 = 1;
  }
  FID_conflict__memcpy(ptr_1_00,arg_2,arg_3_00);
  arg_2 = arg_2 + arg_3_00 + arg_5;
  local_1c = (byte *)((int)ptr_1_00 + arg_3_00 + arg_5);
  for (local_18 = 1; local_18 < arg_4 + -1; local_18 = local_18 + 1) {
    *local_1c = *arg_2;
    local_1c[1] = arg_2[1];
    local_1c[2] = arg_2[2];
    pbVar19 = arg_2;
    pbVar20 = local_1c;
    for (local_10 = 1; local_1c = pbVar20 + 3, arg_2 = pbVar19 + 3, local_10 < arg_3 + -1;
        local_10 = local_10 + 1) {
      bVar1 = arg_2[(arg_3 * -3 - arg_5) + -2];
      bVar2 = arg_2[(arg_3 * -3 - arg_5) + 1];
      bVar3 = arg_2[(arg_3 * -3 - arg_5) + 4];
      bVar4 = pbVar19[1];
      bVar5 = pbVar19[4];
      bVar6 = pbVar19[7];
      bVar7 = arg_2[arg_5 + arg_3_00 + -2];
      bVar8 = arg_2[arg_5 + arg_3_00 + 1];
      bVar9 = arg_2[arg_5 + arg_3_00 + 4];
      bVar10 = arg_2[(arg_3 * -3 - arg_5) + -1];
      bVar11 = arg_2[(arg_3 * -3 - arg_5) + 2];
      bVar12 = arg_2[(arg_3 * -3 - arg_5) + 5];
      bVar13 = pbVar19[2];
      bVar14 = pbVar19[5];
      bVar15 = pbVar19[8];
      bVar16 = arg_2[arg_5 + arg_3_00 + -1];
      bVar17 = arg_2[arg_5 + arg_3_00 + 2];
      bVar18 = arg_2[arg_5 + arg_3_00 + 5];
      *local_1c = PTR_DAT_004f5428
                  [(int)(((((((uint)arg_2[arg_3 * -3 - arg_5] * -2 -
                             (uint)arg_2[(arg_3 * -3 - arg_5) + -3]) -
                            (uint)arg_2[(arg_3 * -3 - arg_5) + 3]) + (uint)*pbVar19 * -2 +
                            (uint)*arg_2 * arg_1 + (uint)pbVar19[6] * -2) -
                          (uint)arg_2[arg_5 + arg_3_00 + -3]) + (uint)arg_2[arg_5 + arg_3_00] * -2)
                        - (uint)arg_2[arg_5 + arg_3_00 + 3]) / (arg_1 + -0xc)];
      pbVar20[4] = PTR_DAT_004f5428
                   [(int)(((((((uint)bVar2 * -2 - (uint)bVar1) - (uint)bVar3) + (uint)bVar4 * -2 +
                             (uint)bVar5 * arg_1 + (uint)bVar6 * -2) - (uint)bVar7) +
                          (uint)bVar8 * -2) - (uint)bVar9) / (arg_1 + -0xc)];
      pbVar20[5] = PTR_DAT_004f5428
                   [(int)(((((((uint)bVar11 * -2 - (uint)bVar10) - (uint)bVar12) + (uint)bVar13 * -2
                             + (uint)bVar14 * arg_1 + (uint)bVar15 * -2) - (uint)bVar16) +
                          (uint)bVar17 * -2) - (uint)bVar18) / (arg_1 + -0xc)];
      pbVar19 = arg_2;
      pbVar20 = local_1c;
    }
    *local_1c = *arg_2;
    pbVar20[4] = pbVar19[4];
    pbVar20[5] = pbVar19[5];
    arg_2 = pbVar19 + arg_5 + 6;
    local_1c = pbVar20 + arg_5 + 6;
  }
  FID_conflict__memcpy(local_1c,arg_2,arg_3_00);
  FID_conflict__memcpy(ptr_1,ptr_1_00,(arg_3_00 + arg_5) * arg_4);
  FUN_004db150(ptr_1_00);
  return 0;
}


