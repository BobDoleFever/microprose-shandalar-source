/*
 * Decompiled function: FUN_1000f877
 * Entry Point: 1000f877
 * Size: 1063 bytes
 */
#include "deckdll.h"


int32_t FUN_1000f877(int arg_1,uint8_t *arg_2,int arg_3,int arg_4,int arg_5)

{
  uint8_t flag_1;
  uint8_t flag_2;
  uint8_t flag_3;
  uint8_t bVar4;
  uint8_t bVar5;
  uint8_t bVar6;
  uint8_t bVar7;
  uint8_t bVar8;
  uint8_t bVar9;
  uint8_t bVar10;
  uint8_t bVar11;
  uint8_t bVar12;
  uint8_t bVar13;
  uint8_t bVar14;
  uint8_t bVar15;
  uint8_t bVar16;
  uint8_t bVar17;
  uint8_t bVar18;
  size_t arg_3_00;
  uint8_t *pbVar19;
  uint8_t *pbVar20;
  uint8_t *ptr_1;
  void *ptr_1_00;
  int local_18;
  int local_14;
  uint8_t *local_c;
  
  ptr_1 = arg_2;
  arg_3_00 = arg_3 * 3;
  ptr_1_00 = malloc((arg_3_00 + arg_5) * arg_4 + 0x10);
  if (DAT_10129244 == 0) {
    for (local_14 = -0x200; local_14 < 0x200; local_14 = local_14 + 1) {
      if ((local_14 < 0) || (0xff < local_14)) {
        if (local_14 < 0) {
          PTR_DAT_10042380[local_14] = 0;
        }
        else {
          PTR_DAT_10042380[local_14] = 0xff;
        }
      }
      else {
        PTR_DAT_10042380[local_14] = (uint8_t)local_14;
      }
    }
    DAT_10129244 = 1;
  }
  memcpy(ptr_1_00,arg_2,arg_3_00);
  arg_2 = arg_2 + arg_3_00 + arg_5;
  local_c = (uint8_t *)((int)ptr_1_00 + arg_3_00 + arg_5);
  for (local_18 = 1; local_18 < arg_4 + -1; local_18 = local_18 + 1) {
    *local_c = *arg_2;
    local_c[1] = arg_2[1];
    local_c[2] = arg_2[2];
    pbVar19 = arg_2;
    pbVar20 = local_c;
    for (local_14 = 1; local_c = pbVar20 + 3, arg_2 = pbVar19 + 3, local_14 < arg_3 + -1;
        local_14 = local_14 + 1) {
      flag_1 = arg_2[(arg_3 * -3 - arg_5) + -2];
      flag_2 = arg_2[(arg_3 * -3 - arg_5) + 1];
      flag_3 = arg_2[(arg_3 * -3 - arg_5) + 4];
      bVar4 = pbVar19[1];
      bVar5 = pbVar19[4];
      bVar6 = pbVar19[7];
      bVar7 = arg_2[arg_3_00 + arg_5 + -2];
      bVar8 = arg_2[arg_3_00 + arg_5 + 1];
      bVar9 = arg_2[arg_3_00 + arg_5 + 4];
      bVar10 = arg_2[(arg_3 * -3 - arg_5) + -1];
      bVar11 = arg_2[(arg_3 * -3 - arg_5) + 2];
      bVar12 = arg_2[(arg_3 * -3 - arg_5) + 5];
      bVar13 = pbVar19[2];
      bVar14 = pbVar19[5];
      bVar15 = pbVar19[8];
      bVar16 = arg_2[arg_3_00 + arg_5 + -1];
      bVar17 = arg_2[arg_3_00 + arg_5 + 2];
      bVar18 = arg_2[arg_3_00 + arg_5 + 5];
      *local_c = PTR_DAT_10042380
                 [(int)(((((((uint32_t)arg_2[arg_3 * -3 - arg_5] * -2 -
                            (uint32_t)arg_2[(arg_3 * -3 - arg_5) + -3]) -
                           (uint32_t)arg_2[(arg_3 * -3 - arg_5) + 3]) + (uint32_t)*pbVar19 * -2 +
                           (uint32_t)*arg_2 * arg_1 + (uint32_t)pbVar19[6] * -2) -
                         (uint32_t)arg_2[arg_3_00 + arg_5 + -3]) + (uint32_t)arg_2[arg_3_00 + arg_5] * -2) -
                       (uint32_t)arg_2[arg_3_00 + arg_5 + 3]) / (arg_1 + -0xc)];
      pbVar20[4] = PTR_DAT_10042380
                   [(int)(((((((uint32_t)flag_2 * -2 - (uint32_t)flag_1) - (uint32_t)flag_3) + (uint32_t)bVar4 * -2 +
                             (uint32_t)bVar5 * arg_1 + (uint32_t)bVar6 * -2) - (uint32_t)bVar7) +
                          (uint32_t)bVar8 * -2) - (uint32_t)bVar9) / (arg_1 + -0xc)];
      pbVar20[5] = PTR_DAT_10042380
                   [(int)(((((((uint32_t)bVar11 * -2 - (uint32_t)bVar10) - (uint32_t)bVar12) + (uint32_t)bVar13 * -2
                             + (uint32_t)bVar14 * arg_1 + (uint32_t)bVar15 * -2) - (uint32_t)bVar16) +
                          (uint32_t)bVar17 * -2) - (uint32_t)bVar18) / (arg_1 + -0xc)];
      pbVar19 = arg_2;
      pbVar20 = local_c;
    }
    *local_c = *arg_2;
    pbVar20[4] = pbVar19[4];
    pbVar20[5] = pbVar19[5];
    arg_2 = pbVar19 + arg_5 + 6;
    local_c = pbVar20 + arg_5 + 6;
  }
  memcpy(local_c,arg_2,arg_3_00);
  memcpy(ptr_1,ptr_1_00,(arg_3_00 + arg_5) * arg_4);
  free(ptr_1_00);
  return 0;
}


