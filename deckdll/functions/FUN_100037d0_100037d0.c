/*
 * Decompiled function: FUN_100037d0
 * Entry Point: 100037d0
 * Size: 1158 bytes
 */
#include "deckdll.h"


uint32_t * FUN_100037d0(void)

{
  int val_1;
  uint32_t *u_ptr_2;
  int val_3;
  int val_4;
  int val_5;
  uint32_t uval_6;
  int val_7;
  uint32_t *puVar8;
  uint32_t uVar9;
  int iVar10;
  int iVar11;
  uint32_t uVar12;
  int *piVar13;
  uint8_t *pbVar14;
  uint32_t *puVar15;
  int iStack00000004;
  uint32_t *puStack00000008;
  uint32_t *puStack00000010;
  int iStack00000014;
  int iStack0000001c;
  int *piStack00000020;
  uint32_t *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  
  FUN_1003d810();
  if (stack_arg != (int *)0x0) {
    val_3 = stack_arg[7];
    val_7 = stack_arg[8];
    if (stack_arg[0x6a] == 0) {
      puStack00000008 = (uint32_t *)thunk_FUN_10002360(stack_arg,(undefined8 *)&DAT_1004c890);
    }
    else {
      puStack00000008 = (uint32_t *)stack_arg[0x6b];
    }
    val_5 = stack_arg[7];
    uVar9 = stack_arg * 3;
    iVar10 = (DAT_10040410 - (int)uVar9 % DAT_10040410) % DAT_10040410;
    if (stack_arg == (uint32_t *)0x0) {
      stack_arg = (uint32_t *)&DAT_100c7090;
    }
    val_4 = 0;
    val_1 = stack_arg;
    piVar13 = (int *)&stack0x00000024;
    if (0 < stack_arg) {
      do {
        iVar11 = val_4 >> 8;
        val_4 = val_4 + (val_3 << 0x10) / stack_arg;
        val_1 = val_1 + -1;
        *piVar13 = iVar11;
        piVar13 = piVar13 + 1;
      } while (val_1 != 0);
    }
    val_3 = stack_arg[8];
    puStack00000010 = stack_arg;
    if (val_3 < stack_arg) {
      puStack00000010 =
           (uint32_t *)((int)stack_arg + (stack_arg - val_3) * (uVar9 + iVar10));
    }
    iStack0000001c = 0;
    if (0 < val_3) {
      puVar15 = puStack00000010;
      do {
        u_ptr_2 = (uint32_t *)&stack0x00000024;
        puVar8 = puVar15;
        iStack00000004 = stack_arg;
        if (0 < stack_arg) {
          do {
            pbVar14 = (uint8_t *)(((int)*u_ptr_2 >> 8) * 3 + (int)puStack00000008);
            puVar15 = (uint32_t *)((int)puVar8 + 3);
            *(uint8_t *)puVar8 =
                 (char)(((uint32_t)pbVar14[3] - (uint32_t)*pbVar14) * (*u_ptr_2 & 0xff) >> 8) + *pbVar14;
            *(uint8_t *)((int)puVar8 + 1) =
                 (char)(((uint32_t)pbVar14[4] - (uint32_t)pbVar14[1]) * (*u_ptr_2 & 0xff) >> 8) + pbVar14[1];
            *(uint8_t *)((int)puVar8 + 2) =
                 (char)(((uint32_t)pbVar14[5] - (uint32_t)pbVar14[2]) * (*u_ptr_2 & 0xff) >> 8) + pbVar14[2];
            iStack00000004 = iStack00000004 + -1;
            u_ptr_2 = u_ptr_2 + 1;
            puVar8 = puVar15;
          } while (iStack00000004 != 0);
        }
        puStack00000008 = (uint32_t *)((int)puStack00000008 + val_5 * 3);
        iStack0000001c = iStack0000001c + 1;
        puVar15 = (uint32_t *)((int)puVar15 + iVar10);
      } while (iStack0000001c < stack_arg[8]);
    }
    val_5 = 0;
    val_3 = stack_arg;
    piStack00000020 = (int *)&stack0x00004024;
    if (0 < stack_arg) {
      do {
        val_1 = val_5 >> 8;
        val_5 = val_5 + (val_7 << 0x10) / stack_arg;
        val_3 = val_3 + -1;
        *piStack00000020 = val_1;
        piStack00000020 = piStack00000020 + 1;
      } while (val_3 != 0);
    }
    uVar12 = uVar9 + iVar10;
    if (stack_arg < stack_arg[8]) {
      puVar15 = (uint32_t *)((int)stack_arg + (stack_arg[8] + -1) * uVar12);
      u_ptr_2 = (uint32_t *)&stack0x00000024;
      for (uval_6 = uVar12 >> 2; uval_6 != 0; uval_6 = uval_6 - 1) {
        *u_ptr_2 = *puVar15;
        puVar15 = puVar15 + 1;
        u_ptr_2 = u_ptr_2 + 1;
      }
      for (uval_6 = uVar12 & 3; uval_6 != 0; uval_6 = uval_6 - 1) {
        *(char *)u_ptr_2 = (char)*puVar15;
        puVar15 = (uint32_t *)((int)puVar15 + 1);
        u_ptr_2 = (uint32_t *)((int)u_ptr_2 + 1);
      }
    }
    if (0 < stack_arg) {
      iStack00000004 = stack_arg;
      puStack00000008 = stack_arg;
      do {
        puVar15 = (uint32_t *)&stack0x00004024;
        u_ptr_2 = puStack00000008;
        iStack00000014 = stack_arg + -1;
        if (0 < stack_arg + -1) {
          do {
            val_7 = (int)*puVar15 >> 8;
            val_3 = stack_arg[8] + -2;
            if (val_7 <= stack_arg[8] + -2) {
              val_3 = val_7;
            }
            puVar8 = (uint32_t *)((int)puStack00000010 + val_3 * uVar12);
            *(uint8_t *)u_ptr_2 =
                 (char)(((uint32_t)*(uint8_t *)(uVar12 + (int)puVar8) - (uint32_t)(uint8_t)*puVar8) *
                        (*puVar15 & 0xff) >> 8) + (uint8_t)*puVar8;
            *(uint8_t *)((int)u_ptr_2 + 1) =
                 (char)(((uint32_t)*(uint8_t *)(uVar12 + 1 + (int)puVar8) -
                        (uint32_t)*(uint8_t *)((int)puVar8 + 1)) * (*puVar15 & 0xff) >> 8) +
                 *(uint8_t *)((int)puVar8 + 1);
            *(uint8_t *)((int)u_ptr_2 + 2) =
                 (char)(((uint32_t)*(uint8_t *)(uVar12 + 2 + (int)puVar8) -
                        (uint32_t)*(uint8_t *)((int)puVar8 + 2)) * (*puVar15 & 0xff) >> 8) +
                 *(uint8_t *)((int)puVar8 + 2);
            iStack00000014 = iStack00000014 + -1;
            puVar15 = puVar15 + 1;
            u_ptr_2 = (uint32_t *)((int)u_ptr_2 + uVar12);
          } while (iStack00000014 != 0);
        }
        puStack00000010 = (uint32_t *)((int)puStack00000010 + 3);
        puStack00000008 = (uint32_t *)((int)puStack00000008 + 3);
        iStack00000004 = iStack00000004 + -1;
      } while (iStack00000004 != 0);
    }
    if (stack_arg < stack_arg[8]) {
      puVar15 = (uint32_t *)&stack0x00000024;
      u_ptr_2 = (uint32_t *)((int)stack_arg + (stack_arg + -1) * uVar12);
      for (uval_6 = uVar12 >> 2; uval_6 != 0; uval_6 = uval_6 - 1) {
        *u_ptr_2 = *puVar15;
        puVar15 = puVar15 + 1;
        u_ptr_2 = u_ptr_2 + 1;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(char *)u_ptr_2 = (char)*puVar15;
        puVar15 = (uint32_t *)((int)puVar15 + 1);
        u_ptr_2 = (uint32_t *)((int)u_ptr_2 + 1);
      }
    }
    else {
      puVar15 = (uint32_t *)((int)stack_arg + (stack_arg + -1) * uVar12);
      for (uval_6 = uVar12 >> 2; uval_6 != 0; uval_6 = uval_6 - 1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(uint8_t *)puVar15 = 0;
        puVar15 = (uint32_t *)((int)puVar15 + 1);
      }
    }
    uVar12 = (int)uVar9 >> 0x1f;
    uVar9 = 4 - (((uVar9 ^ uVar12) - uVar12 & 3 ^ uVar12) - uVar12);
    uVar12 = (int)uVar9 >> 0x1f;
    val_3 = ((uVar9 ^ uVar12) - uVar12 & 3 ^ uVar12) - uVar12;
    if (DAT_10041580 == 0) {
      thunk_FUN_1000ef86(stack_arg,stack_arg,stack_arg,val_3);
    }
    else if (DAT_101cf94c == 0x10) {
      thunk_FUN_1000fc9e(DAT_10041580,DAT_10041584,(int)stack_arg,stack_arg,
                         stack_arg,val_3);
    }
    else if (DAT_101cf94c == 8) {
      thunk_FUN_1000f104(DAT_10041580,DAT_10041584,stack_arg,stack_arg,
                         stack_arg,val_3);
    }
    return stack_arg;
  }
  return (uint32_t *)0x0;
}


