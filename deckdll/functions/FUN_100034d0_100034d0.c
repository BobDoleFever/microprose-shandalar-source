/*
 * Decompiled function: FUN_100034d0
 * Entry Point: 100034d0
 * Size: 437 bytes
 */
#include "deckdll.h"


int32_t * FUN_100034d0(int32_t *arg_1,int y,int width,int height)

{
  int val_1;
  uint32_t uval_2;
  int32_t *u_ptr_3;
  int val_4;
  int *_Memory;
  int *piVar5;
  void *pvVar6;
  int val_7;
  int val_8;
  uint32_t uVar9;
  int32_t *puVar10;
  int32_t *puVar11;
  int iVar12;
  int32_t *puVar13;
  int local_24;
  void *local_1c;
  void *local_18;
  
  u_ptr_3 = (int32_t *)0x0;
  local_24 = 0;
  local_18 = (void *)0x0;
  if (y != 0) {
    uval_2 = width * 3;
    val_8 = (DAT_10040410 - (int)uval_2 % DAT_10040410) % DAT_10040410;
    u_ptr_3 = arg_1;
    if (arg_1 == (int32_t *)0x0) {
      u_ptr_3 = malloc((uval_2 + val_8) * height + 4);
    }
    iVar12 = *(int *)(y + 0x1c);
    val_4 = (*(int *)(y + 0x20) << 0x10) / height;
    if (*(int *)(y + 0x1a8) == 0) {
      local_1c = (void *)thunk_FUN_10002360((int *)y,(undefined8 *)0x0);
    }
    else {
      local_1c = *(void **)(y + 0x1ac);
    }
    val_1 = *(int *)(y + 0x1c);
    _Memory = malloc(width << 2);
    uVar9 = 0;
    piVar5 = _Memory;
    val_7 = width;
    if (0 < width) {
      do {
        *piVar5 = ((int)(uVar9 & 0xffff7fff) >> 0xf) + ((int)uVar9 >> 0x10);
        uVar9 = uVar9 + (iVar12 << 0x10) / width;
        val_7 = val_7 + -1;
        piVar5 = piVar5 + 1;
      } while (val_7 != 0);
    }
    puVar10 = u_ptr_3;
    if (0 < height) {
      do {
        pvVar6 = (void *)((local_24 >> 0x10) * val_1 * 3 + (int)local_1c);
        if (local_18 == pvVar6) {
          puVar11 = (int32_t *)((int)puVar10 + (width * -3 - val_8));
          puVar13 = puVar10;
          for (uVar9 = uval_2 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          puVar10 = (int32_t *)((int)puVar10 + uval_2);
          for (uVar9 = uval_2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(uint8_t *)puVar13 = *(uint8_t *)puVar11;
            puVar11 = (int32_t *)((int)puVar11 + 1);
            puVar13 = (int32_t *)((int)puVar13 + 1);
          }
        }
        else {
          piVar5 = _Memory;
          puVar11 = puVar10;
          iVar12 = width;
          local_18 = pvVar6;
          if (0 < width) {
            do {
              val_7 = *piVar5;
              puVar10 = (int32_t *)((int)puVar11 + 3);
              piVar5 = piVar5 + 1;
              iVar12 = iVar12 + -1;
              *puVar11 = *(int32_t *)(val_7 + (int)pvVar6);
              puVar11 = puVar10;
            } while (iVar12 != 0);
          }
        }
        local_24 = local_24 + val_4;
        height = height + -1;
        puVar10 = (int32_t *)((int)puVar10 + val_8);
      } while (height != 0);
    }
    free(_Memory);
    if (*(int *)(y + 0x1a8) == 0) {
      free(local_1c);
    }
  }
  return u_ptr_3;
}


