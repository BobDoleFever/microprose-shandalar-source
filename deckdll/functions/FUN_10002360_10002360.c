/*
 * Decompiled function: DeckDll_DecompressHaarWavelet
 * Entry Point: 10002360
 * Size: 836 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * DeckDll_DecompressHaarWavelet(int *arg1,undefined8 *arg2)

{
  int *arg_1;
  int *arg_1_00;
  uint32_t uval_1;
  int val_2;
  int arg_8;
  int val_3;
  undefined8 *_Memory;
  undefined8 *puVar4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  bool bVar12;
  int arg_4;
  int arg_9;
  int local_2c;
  int local_10;
  undefined8 *stack_arg;
  
  if (DAT_1004c6d8 == 0) {
    val_5 = -0x400;
    iVar9 = -0x3fc00;
    do {
      if ((iVar9 < 0) || (0xf708 < iVar9)) {
        if (iVar9 < 0x9f6) {
          PTR_DAT_10040448[val_5] = 0;
        }
        else {
          PTR_DAT_10040448[val_5] = 0xff;
        }
      }
      else {
        PTR_DAT_10040448[val_5] = (char)(iVar9 / 0xf8);
      }
      iVar9 = iVar9 + 0xff;
      val_5 = val_5 + 1;
    } while (iVar9 < 0x3fc01);
    DAT_1004c6d8 = 1;
  }
  bVar12 = arg2 != (undefined8 *)0x0;
  if (bVar12) {
    val_5 = arg1[0x24] + 2000;
    thunk_FUN_10014a60(arg2,(int)(val_5 + (val_5 >> 0x1f & 3U)) >> 2);
  }
  else {
    arg2 = malloc(arg1[0x24] + 2000);
    thunk_FUN_10014a60(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  _DAT_102151e4 = thunk_FUN_100030e0((int32_t *)arg2,arg1);
  val_5 = arg1[10];
  if (val_5 == 1) {
    stack_arg = (undefined8 *)0x1;
  }
  else if (val_5 == 4) {
    stack_arg = (undefined8 *)0x2;
  }
  else if (val_5 == 0x10) {
    stack_arg = (undefined8 *)0x4;
  }
  else {
    thunk_FUN_10016850(0,0x10040490,0x15e,s_wavelet_pieces_has_illegal_value_100404bc);
  }
  iVar9 = arg1[7] / (int)stack_arg;
  val_5 = arg1[9];
  local_10 = 0;
  val_2 = arg1[8] / (int)stack_arg;
  if (0 < arg1[10]) {
    arg_8 = iVar9 * iVar9;
    do {
      val_3 = val_2;
      val_6 = iVar9;
      if (*arg1 != 0) {
        val_6 = (arg1[10] == 1) + 1;
        val_3 = (val_2 / (int)stack_arg) / val_6;
        val_6 = (iVar9 / (int)stack_arg) / val_6;
      }
      arg_1 = (int *)((int)arg2 + (arg_8 + 0x40 + val_6 * val_6 * 2) * local_10 * 4);
      arg_1_00 = arg_1 + arg_8 + 0x20;
      thunk_FUN_10002a60(arg_1,iVar9,val_5);
      thunk_FUN_10002a60(arg_1_00,val_6,val_5);
      thunk_FUN_10002a60(arg_1_00 + val_6 * val_6 + 0x20,val_6,val_5);
      if (local_10 < arg1[10] / 2) {
        arg_9 = *arg1;
        arg_4 = iVar9;
        arg_8 = val_6;
      }
      else {
        arg_9 = *arg1;
        arg_4 = val_2;
        arg_8 = val_3;
        if (1 < arg1[10]) {
          arg_4 = arg1[8] - iVar9;
        }
      }
      _Memory = (undefined8 *)
                thunk_FUN_10002e20(&DAT_1004c890,arg_1,iVar9,arg_4,arg_1_00,
                                   arg_1_00 + val_6 * val_6 + 0x20,val_6,arg_8,arg_9);
      if (arg1[10] < 2) {
        puVar4 = _Memory;
        if (!bVar12) {
          local_10 = 0x1000267c;
          free(arg2);
          stack_arg = arg2;
        }
      }
      else {
        puVar4 = (undefined8 *)
                 ((int)arg2 +
                 ((local_10 / (int)stack_arg) * arg_9 + local_10 % (int)stack_arg) *
                 iVar9 * 3);
        if (0 < iVar9) {
          uval_1 = iVar9 * 3;
          puVar8 = _Memory;
          local_2c = iVar9;
          do {
            puVar11 = puVar4;
            puVar10 = puVar8;
            for (uval_7 = uval_1 >> 3; uval_7 != 0; uval_7 = uval_7 - 1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
            uval_7 = uval_1 & 7;
            if (uval_7 != 0) {
              for (; uval_7 != 0; uval_7 = uval_7 - 1) {
                *(uint8_t *)puVar11 = *(uint8_t *)puVar10;
                puVar10 = (undefined8 *)((int)puVar10 + 1);
                puVar11 = (undefined8 *)((int)puVar11 + 1);
              }
            }
            puVar8 = (undefined8 *)((int)puVar8 + uval_1);
            puVar4 = (undefined8 *)((int)puVar4 + arg_9 * 3);
            local_2c = local_2c + -1;
          } while (local_2c != 0);
        }
        local_10 = 0x10002666;
        free(_Memory);
        puVar4 = arg2;
        stack_arg = _Memory;
      }
      arg2 = puVar4;
      local_10 = local_10 + 1;
    } while (local_10 < arg1[10]);
  }
  return arg2;
}


