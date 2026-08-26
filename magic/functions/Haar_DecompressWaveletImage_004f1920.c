/*
 * Decompiled function: Haar_DecompressWaveletImage
 * Entry Point: 004f1920
 * Size: 836 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * Haar_DecompressWaveletImage(int *arg1,undefined8 *arg2)

{
  int *arg_1;
  int *arg_1_00;
  uint uVar1;
  int iVar2;
  int arg_8;
  int iVar3;
  undefined8 *_Memory;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  bool bVar12;
  int arg_4;
  int arg_9;
  int local_2c;
  int local_10;
  undefined8 *in_stack_fffffff4;
  
  if (DAT_00566228 == 0) {
    iVar5 = -0x400;
    iVar9 = -0x3fc00;
    do {
      if ((iVar9 < 0) || (0xf708 < iVar9)) {
        if (iVar9 < 0x9f6) {
          PTR_DAT_005300a0[iVar5] = 0;
        }
        else {
          PTR_DAT_005300a0[iVar5] = 0xff;
        }
      }
      else {
        PTR_DAT_005300a0[iVar5] = (char)(iVar9 / 0xf8);
      }
      iVar9 = iVar9 + 0xff;
      iVar5 = iVar5 + 1;
    } while (iVar9 < 0x3fc01);
    DAT_00566228 = 1;
  }
  bVar12 = arg2 != (undefined8 *)0x0;
  if (bVar12) {
    iVar5 = arg1[0x24] + 2000;
    FUN_0048aee0(arg2,(int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2);
  }
  else {
    arg2 = malloc(arg1[0x24] + 2000);
    FUN_0048aee0(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  _DAT_00640f04 = Haar_DecompressHeader((undefined4 *)arg2,arg1);
  iVar5 = arg1[10];
  if (iVar5 == 1) {
    in_stack_fffffff4 = (undefined8 *)0x1;
  }
  else if (iVar5 == 4) {
    in_stack_fffffff4 = (undefined8 *)0x2;
  }
  else if (iVar5 == 0x10) {
    in_stack_fffffff4 = (undefined8 *)0x4;
  }
  else {
    AssertOrLog(0,0x5300d4,0x15e,s_wavelet_pieces_has_illegal_value_005300f8);
  }
  iVar9 = arg1[7] / (int)in_stack_fffffff4;
  iVar5 = arg1[9];
  local_10 = 0;
  iVar2 = arg1[8] / (int)in_stack_fffffff4;
  if (0 < arg1[10]) {
    arg_8 = iVar9 * iVar9;
    do {
      iVar3 = iVar2;
      iVar6 = iVar9;
      if (*arg1 != 0) {
        iVar6 = (arg1[10] == 1) + 1;
        iVar3 = (iVar2 / (int)in_stack_fffffff4) / iVar6;
        iVar6 = (iVar9 / (int)in_stack_fffffff4) / iVar6;
      }
      arg_1 = (int *)((int)arg2 + (arg_8 + 0x40 + iVar6 * iVar6 * 2) * local_10 * 4);
      arg_1_00 = arg_1 + arg_8 + 0x20;
      Mem_AllocOrFree_004f1ec0(arg_1,iVar9,iVar5);
      Mem_AllocOrFree_004f1ec0(arg_1_00,iVar6,iVar5);
      Mem_AllocOrFree_004f1ec0(arg_1_00 + iVar6 * iVar6 + 0x20,iVar6,iVar5);
      if (local_10 < arg1[10] / 2) {
        arg_9 = *arg1;
        arg_4 = iVar9;
        arg_8 = iVar6;
      }
      else {
        arg_9 = *arg1;
        arg_4 = iVar2;
        arg_8 = iVar3;
        if (1 < arg1[10]) {
          arg_4 = arg1[8] - iVar9;
        }
      }
      _Memory = (undefined8 *)
                Mem_AllocOrFree_004f21d0
                          (&DAT_005663e0,arg_1,iVar9,arg_4,arg_1_00,arg_1_00 + iVar6 * iVar6 + 0x20,
                           iVar6,arg_8,arg_9);
      if (arg1[10] < 2) {
        puVar4 = _Memory;
        if (!bVar12) {
          local_10 = 0x4f1c3c;
          free(arg2);
          in_stack_fffffff4 = arg2;
        }
      }
      else {
        puVar4 = (undefined8 *)
                 ((int)arg2 +
                 ((local_10 / (int)in_stack_fffffff4) * arg_9 + local_10 % (int)in_stack_fffffff4) *
                 iVar9 * 3);
        if (0 < iVar9) {
          uVar1 = iVar9 * 3;
          puVar8 = _Memory;
          local_2c = iVar9;
          do {
            puVar11 = puVar4;
            puVar10 = puVar8;
            for (uVar7 = uVar1 >> 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
            uVar7 = uVar1 & 7;
            if (uVar7 != 0) {
              for (; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
                puVar10 = (undefined8 *)((int)puVar10 + 1);
                puVar11 = (undefined8 *)((int)puVar11 + 1);
              }
            }
            puVar8 = (undefined8 *)((int)puVar8 + uVar1);
            puVar4 = (undefined8 *)((int)puVar4 + arg_9 * 3);
            local_2c = local_2c + -1;
          } while (local_2c != 0);
        }
        local_10 = 0x4f1c26;
        free(_Memory);
        puVar4 = arg2;
        in_stack_fffffff4 = _Memory;
      }
      arg2 = puVar4;
      local_10 = local_10 + 1;
    } while (local_10 < arg1[10]);
  }
  return arg2;
}


