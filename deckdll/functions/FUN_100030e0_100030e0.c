/*
 * Decompiled function: FUN_100030e0
 * Entry Point: 100030e0
 * Size: 431 bytes
 */
#include "deckdll.h"


int32_t FUN_100030e0(int32_t *arg1,int *arg2)

{
  int32_t *u_ptr_1;
  int arg_3;
  int val_2;
  int val_3;
  int val_4;
  uint32_t uval_5;
  int val_6;
  int *piVar7;
  int32_t *puVar8;
  int32_t *puVar9;
  uint32_t *puVar10;
  uint32_t uVar11;
  int32_t *puVar12;
  int *local_20;
  int32_t *local_18;
  int local_c;
  
  val_2 = arg2[7] / (int)(2 - (uint32_t)(arg2[10] == 1));
  val_3 = val_2 / (int)(2 - (uint32_t)(*arg2 == 0));
  val_3 = val_3 * val_3;
  val_6 = arg2[9];
  piVar7 = (int *)arg2[0x68] + 1;
  arg_3 = *(int *)arg2[0x68];
  *piVar7 = -0x80000000;
  val_4 = thunk_FUN_10015770((uint32_t *)(piVar7 + arg_3),piVar7,arg_3);
  puVar8 = (int32_t *)((int)(piVar7 + arg_3) + val_4);
  local_c = 0;
  if (0 < arg2[10]) {
    local_20 = arg2 + 0x17;
    local_18 = arg1;
    uVar11 = val_6 * val_6;
    do {
      u_ptr_1 = local_18 + val_2 * val_2 + 0x20;
      puVar12 = puVar8;
      puVar9 = local_18;
      for (uval_5 = uVar11 & 0x3fffffff; uval_5 != 0; uval_5 = uval_5 - 1) {
        *puVar9 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar9 = puVar9 + 1;
      }
      for (val_6 = 0; val_6 != 0; val_6 = val_6 + -1) {
        *(uint8_t *)puVar9 = *(uint8_t *)puVar12;
        puVar12 = (int32_t *)((int)puVar12 + 1);
        puVar9 = (int32_t *)((int)puVar9 + 1);
      }
      thunk_FUN_10016060(local_18 + uVar11,puVar8 + uVar11,*local_20);
      puVar9 = (int32_t *)((int)(puVar8 + uVar11) + *local_20);
      puVar8 = puVar9;
      puVar12 = u_ptr_1;
      for (uval_5 = uVar11 & 0x3fffffff; uval_5 != 0; uval_5 = uval_5 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = puVar9 + uVar11;
      for (val_6 = 0; val_6 != 0; val_6 = val_6 + -1) {
        *(uint8_t *)puVar12 = *(uint8_t *)puVar8;
        puVar8 = (int32_t *)((int)puVar8 + 1);
        puVar12 = (int32_t *)((int)puVar12 + 1);
      }
      thunk_FUN_10016060(u_ptr_1 + uVar11,puVar10,local_20[4]);
      puVar9 = (int32_t *)((int)puVar10 + local_20[4]);
      puVar8 = puVar9;
      puVar12 = u_ptr_1 + val_3 + 0x20;
      for (uval_5 = uVar11 & 0x3fffffff; uval_5 != 0; uval_5 = uval_5 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = puVar9 + uVar11;
      for (val_6 = 0; val_6 != 0; val_6 = val_6 + -1) {
        *(uint8_t *)puVar12 = *(uint8_t *)puVar8;
        puVar8 = (int32_t *)((int)puVar8 + 1);
        puVar12 = (int32_t *)((int)puVar12 + 1);
      }
      thunk_FUN_10016060(u_ptr_1 + val_3 + 0x20 + uVar11,puVar10,local_20[8]);
      piVar7 = local_20 + 8;
      local_20 = local_20 + 1;
      puVar8 = (int32_t *)((int)puVar10 + *piVar7);
      local_18 = local_18 + val_2 * val_2 + val_3 * 2 + 0x40;
      local_c = local_c + 1;
    } while (local_c < arg2[10]);
  }
  return 0;
}


