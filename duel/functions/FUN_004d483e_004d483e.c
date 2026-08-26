/*
 * Decompiled function: FUN_004d483e
 * Entry Point: 004d483e
 * Size: 1481 bytes
 */
#include "duel.h"


int FUN_004d483e(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_5a0 [50];
  int local_4d8;
  int aiStack_4d4 [50];
  int aiStack_40c [50];
  byte abStack_344 [200];
  int local_27c;
  int local_278;
  int local_274;
  int aiStack_270 [50];
  int local_1a8;
  int aiStack_1a4 [50];
  int local_dc;
  int aiStack_d8 [50];
  int local_10;
  int local_c;
  int local_8;
  
  if (arg1 == -1) {
    local_8 = -1;
  }
  else if (arg2 == 1) {
    local_8 = -1;
    local_c = -10;
    local_1a8 = 0;
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[arg1]; local_10 = local_10 + 1) {
      local_dc = *(int *)(&DAT_006826c4 + local_10 * 0x120 + arg1 * 0x5b20);
      if (((local_dc != -1) && (((&DAT_006826cc)[local_10 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
         ((((&DAT_004ff594)[local_dc * 0x34] & 1) != 0 &&
          (((&DAT_006826cc)[local_10 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)))) {
        aiStack_d8[local_1a8] = local_10;
        aiStack_1a4[local_1a8] = 0;
        local_1a8 = local_1a8 + 1;
      }
    }
    for (local_10 = 0; local_10 < local_1a8; local_10 = local_10 + 1) {
      if (((&DAT_004ff5a8)
           [*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + aiStack_d8[local_10] * 0x120) * 0x34] & 1) != 0
         ) {
        aiStack_1a4[local_10] = aiStack_1a4[local_10] + 1;
      }
      if (((&DAT_006826ce)[local_10 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
        aiStack_1a4[local_10] = -1;
      }
    }
    for (local_10 = 0; local_10 < local_1a8; local_10 = local_10 + 1) {
      if (local_c < aiStack_1a4[local_10]) {
        local_c = aiStack_1a4[local_10];
        local_8 = aiStack_d8[local_10];
      }
    }
  }
  else if (arg2 == 2) {
    local_8 = -1;
    local_c = -1;
    local_274 = 0;
    local_278 = 0;
    local_4d8 = 0;
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[arg1]; local_10 = local_10 + 1) {
      local_27c = *(int *)(&DAT_006826c4 + local_10 * 0x120 + arg1 * 0x5b20);
      if ((((local_27c != -1) && (((&DAT_006826cc)[local_10 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
          (((&DAT_004ff594)[local_27c * 0x34] & 2) != 0)) &&
         (((&DAT_006826cc)[local_10 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
        aiStack_270[local_4d8] = local_10;
        iVar1 = FUN_0048b81a(arg1,local_10,0x32,0xffffffff);
        aiStack_4d4[local_4d8] = iVar1;
        if (local_274 < aiStack_4d4[local_4d8]) {
          local_274 = aiStack_4d4[local_4d8];
        }
        iVar1 = FUN_0048b81a(arg1,local_10,0x33,0xffffffff);
        aiStack_5a0[local_4d8] = iVar1;
        if (local_278 < aiStack_5a0[local_4d8]) {
          local_278 = aiStack_5a0[local_4d8];
        }
        uVar2 = FUN_0048b81a(arg1,local_10,0x34,0xffffffff);
        *(undefined4 *)(abStack_344 + local_4d8 * 4) = uVar2;
        aiStack_40c[local_4d8] = 0;
        local_4d8 = local_4d8 + 1;
      }
    }
    for (local_10 = 0; local_10 < local_4d8; local_10 = local_10 + 1) {
      if (aiStack_4d4[local_10] == local_274) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 3;
      }
      if (aiStack_5a0[local_10] == local_278) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 2;
      }
      if ((abStack_344[local_10 * 4] & 0x20) != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
      if ((abStack_344[local_10 * 4 + 1] & 1) != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
      while (*(int *)(abStack_344 + local_10 * 4) != 0) {
        if ((abStack_344[local_10 * 4] & 1) != 0) {
          aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
        }
        *(int *)(abStack_344 + local_10 * 4) = *(int *)(abStack_344 + local_10 * 4) >> 1;
      }
      if (((&DAT_004ff5a9)
           [*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + aiStack_270[local_10] * 0x120) * 0x34] & 0x10)
          != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
      if (((&DAT_004ff5a8)
           [*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + aiStack_270[local_10] * 0x120) * 0x34] & 1) !=
          0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
    }
    for (local_10 = 0; local_10 < local_4d8; local_10 = local_10 + 1) {
      if (local_c < aiStack_40c[local_10]) {
        local_c = aiStack_40c[local_10];
        local_8 = aiStack_270[local_10];
      }
    }
  }
  else {
    local_8 = -1;
  }
  return local_8;
}


