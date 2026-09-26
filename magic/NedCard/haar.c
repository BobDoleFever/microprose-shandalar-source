/*
 * NedCard/haar.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 122
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Haar_DecompressWaveletImage
 * Entry Point: 004f1920
 * Size: 836 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * Haar_DecompressWaveletImage(int *arg1,undefined8 *arg2)

{
  int *hDIBSection;
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
      hDIBSection = (int *)((int)arg2 + (arg_8 + 0x40 + iVar6 * iVar6 * 2) * local_10 * 4);
      arg_1_00 = hDIBSection + arg_8 + 0x20;
      Mem_AllocOrFree_004f1ec0(hDIBSection,iVar9,iVar5);
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
                          (&DAT_005663e0,hDIBSection,iVar9,arg_4,arg_1_00,arg_1_00 + iVar6 * iVar6 + 0x20,
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



/*
 * Decompiled function: FUN_004f1cfa
 * Entry Point: 004f1cfa
 * Size: 283 bytes
 */


void FUN_004f1cfa(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  bool in_ZF;
  char in_SF;
  char in_OF;
  int iStack0000000c;
  int *in_stack_00000014;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_0000002c;
  
  iStack0000000c = in_EAX;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar4 = in_stack_00000014;
      piVar6 = in_stack_0000001c;
      while (piVar4 < in_stack_00000014 + in_stack_00000020 + -1) {
        piVar6 = piVar6 + in_stack_0000002c * 2;
        piVar1 = piVar4 + 1;
        piVar4 = piVar4 + 1;
        iVar2 = *in_stack_00000018;
        iVar5 = *piVar1 * 0xb504;
        iVar3 = iVar5;
        if (iVar2 != 0) {
          iVar3 = iVar5 + iVar2 * 0xb504;
          iVar5 = iVar5 + iVar2 * -0xb504;
        }
        in_stack_00000018 = in_stack_00000018 + 1;
        *piVar6 = iVar3 >> 0x10;
        piVar6[in_stack_0000002c] = iVar5 >> 0x10;
      }
      *in_stack_0000001c = (*in_stack_00000018 + *in_stack_00000014) * 0xb504 >> 0x10;
      iVar3 = *in_stack_00000014;
      iVar5 = *in_stack_00000018;
      in_stack_00000014 = piVar4 + 1;
      in_stack_00000018 = in_stack_00000018 + 1;
      iStack0000000c = iStack0000000c + -1;
      in_stack_0000001c[in_stack_0000002c] = (iVar3 - iVar5) * 0xb504 >> 0x10;
      in_stack_0000001c = in_stack_0000001c + 1;
    } while (iStack0000000c != 0);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f1e20
 * Entry Point: 004f1e20
 * Size: 45 bytes
 */


void Mem_AllocOrFree_004f1e20(undefined8 *hDIBSection,undefined8 *card_slot,uint arg_3)

{
  uint uVar1;
  
  for (uVar1 = arg_3 >> 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *hDIBSection = *card_slot;
    card_slot = card_slot + 1;
    hDIBSection = hDIBSection + 1;
  }
  uVar1 = arg_3 & 7;
  if (uVar1 != 0) {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)hDIBSection = *(undefined1 *)card_slot;
      card_slot = (undefined8 *)((int)card_slot + 1);
      hDIBSection = (undefined8 *)((int)hDIBSection + 1);
    }
  }
  return;
}



/*
 * Decompiled function: Haar_Transform2D_Inverse
 * Entry Point: 004f1e50
 * Size: 110 bytes
 */


void Haar_Transform2D_Inverse(undefined8 *hDIBSection,uint card_slot,uint arg_3)

{
  uint uVar1;
  int iVar2;
  uint arg2;
  undefined8 uVar3;
  
  uVar1 = card_slot << 8 | card_slot;
  arg2 = (int)uVar1 >> 0x1f | ((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10;
  uVar3 = __allshl(0x20,arg2);
  uVar3 = CONCAT44(arg2 | (uint)((ulonglong)uVar3 >> 0x20),uVar1 | uVar1 << 0x10 | (uint)uVar3);
  iVar2 = (arg_3 >> 3) - 1;
  do {
    *hDIBSection = uVar3;
    hDIBSection = hDIBSection + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *hDIBSection = uVar3;
  for (uVar1 = arg_3 & 7; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(char *)hDIBSection = (char)card_slot;
    hDIBSection = (undefined8 *)((int)hDIBSection + 1);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f1ec0
 * Entry Point: 004f1ec0
 * Size: 11 bytes
 */


void Mem_AllocOrFree_004f1ec0(int *hDIBSection,int card_slot,int arg_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *arg_2_00;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int in_stack_00000024;
  int iStack_18;
  int *piStack_c;
  
  if (DAT_005300ac == 0) {
    piStack_c = malloc(0x32000);
    DAT_0063eef0 = piStack_c;
    DAT_0063eeec = malloc(0x32000);
    DAT_005300ac = 1;
  }
  else {
    piStack_c = DAT_0063eef0;
  }
  arg_2_00 = DAT_0063eeec;
  if (arg_3 < card_slot) {
    do {
      iVar4 = arg_3 * arg_3;
      piVar5 = hDIBSection + iVar4;
      piVar6 = piStack_c;
      piVar7 = hDIBSection;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          piVar1 = piVar6 + arg_3 * 2;
          piVar2 = piVar5;
          piVar3 = piVar7;
          while (piVar3 = piVar3 + 1, piVar3 < piVar7 + arg_3) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[arg_3] = *piVar3 - *piVar2;
            piVar1 = piVar1 + arg_3 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar6 = *piVar7 + *piVar2;
          piVar6[arg_3] = *piVar7 - *piVar2;
          iStack_18 = iStack_18 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = piVar3;
        } while (iStack_18 != 0);
      }
      piVar5 = hDIBSection + iVar4 * 3;
      piVar6 = hDIBSection + iVar4 * 2;
      piVar7 = arg_2_00;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          piVar1 = piVar7 + arg_3 * 2;
          piVar2 = piVar5;
          piVar3 = piVar6;
          while (piVar3 = piVar3 + 1, piVar3 < piVar6 + arg_3) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[arg_3] = *piVar3 - *piVar2;
            piVar1 = piVar1 + arg_3 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar7 = *piVar6 + *piVar2;
          piVar7[arg_3] = *piVar6 - *piVar2;
          iStack_18 = iStack_18 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = piVar3;
        } while (iStack_18 != 0);
      }
      iVar4 = arg_3 * 2;
      Mem_AllocOrFree_004f2110(piStack_c,arg_2_00,hDIBSection,arg_3,iVar4,iVar4,iVar4);
      arg_3 = iVar4;
    } while (iVar4 < in_stack_00000024);
  }
  return;
}



/*
 * Decompiled function: FUN_004f1ecb
 * Entry Point: 004f1ecb
 * Size: 416 bytes
 */


void FUN_004f1ecb(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *card_slot;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  int iStack00000004;
  int *piStack00000010;
  int *in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_00000040;
  
  if (in_ZF) {
    piStack00000010 = malloc(0x32000);
    DAT_0063eef0 = piStack00000010;
    DAT_0063eeec = malloc(0x32000);
    DAT_005300ac = 1;
  }
  else {
    piStack00000010 = DAT_0063eef0;
  }
  card_slot = DAT_0063eeec;
  if (in_stack_00000028 < in_stack_00000024) {
    do {
      iVar4 = in_stack_00000028 * in_stack_00000028;
      piVar5 = in_stack_00000020 + iVar4;
      piVar6 = piStack00000010;
      piVar7 = in_stack_00000020;
      iStack00000004 = in_stack_00000028;
      if (0 < in_stack_00000028) {
        do {
          piVar1 = piVar6 + in_stack_00000028 * 2;
          piVar2 = piVar5;
          piVar3 = piVar7;
          while (piVar3 = piVar3 + 1, piVar3 < piVar7 + in_stack_00000028) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[in_stack_00000028] = *piVar3 - *piVar2;
            piVar1 = piVar1 + in_stack_00000028 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar6 = *piVar7 + *piVar2;
          piVar6[in_stack_00000028] = *piVar7 - *piVar2;
          iStack00000004 = iStack00000004 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = piVar3;
        } while (iStack00000004 != 0);
      }
      piVar5 = in_stack_00000020 + iVar4 * 3;
      piVar6 = in_stack_00000020 + iVar4 * 2;
      piVar7 = card_slot;
      iStack00000004 = in_stack_00000028;
      if (0 < in_stack_00000028) {
        do {
          piVar1 = piVar7 + in_stack_00000028 * 2;
          piVar2 = piVar5;
          piVar3 = piVar6;
          while (piVar3 = piVar3 + 1, piVar3 < piVar6 + in_stack_00000028) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[in_stack_00000028] = *piVar3 - *piVar2;
            piVar1 = piVar1 + in_stack_00000028 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar7 = *piVar6 + *piVar2;
          piVar7[in_stack_00000028] = *piVar6 - *piVar2;
          iStack00000004 = iStack00000004 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = piVar3;
        } while (iStack00000004 != 0);
      }
      iVar4 = in_stack_00000028 * 2;
      Mem_AllocOrFree_004f2110
                (piStack00000010,card_slot,in_stack_00000020,in_stack_00000028,iVar4,iVar4,iVar4);
      in_stack_00000028 = iVar4;
    } while (iVar4 < in_stack_00000040);
  }
  return;
}



/*
 * Decompiled function: FUN_004f207a
 * Entry Point: 004f207a
 * Size: 136 bytes
 */


void FUN_004f207a(int hDIBSection,undefined4 card_slot,int *arg_3,int *arg_4,int *arg_5,int arg_6,
                 undefined4 arg_7,undefined4 arg_8,int arg_9)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  hDIBSection = in_EAX;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar1 = arg_5 + arg_9 * 2;
      piVar2 = arg_4;
      piVar3 = arg_3;
      while (piVar3 = piVar3 + 1, piVar3 < arg_3 + arg_6) {
        *piVar1 = *piVar2 + *piVar3;
        piVar1[arg_9] = *piVar3 - *piVar2;
        piVar1 = piVar1 + arg_9 * 2;
        piVar2 = piVar2 + 1;
      }
      arg_4 = piVar2 + 1;
      *arg_5 = *piVar2 + *arg_3;
      arg_5[arg_9] = *arg_3 - *piVar2;
      hDIBSection = hDIBSection + -1;
      arg_3 = piVar3;
      arg_5 = arg_5 + 1;
    } while (hDIBSection != 0);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f2110
 * Entry Point: 004f2110
 * Size: 10 bytes
 */


void Mem_AllocOrFree_004f2110
               (int *hDIBSection,int *card_slot,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iStack_4;
  
  if (0 < arg_5) {
    iStack_4 = arg_5;
    do {
      piVar1 = arg_3 + arg_7 * 2;
      piVar2 = card_slot;
      piVar3 = hDIBSection;
      while (piVar3 = piVar3 + 1, piVar3 < hDIBSection + arg_4) {
        *piVar1 = *piVar2 + *piVar3 >> 1;
        piVar1[arg_7] = *piVar3 - *piVar2 >> 1;
        piVar1 = piVar1 + arg_7 * 2;
        piVar2 = piVar2 + 1;
      }
      card_slot = piVar2 + 1;
      *arg_3 = *piVar2 + *hDIBSection >> 1;
      arg_3[arg_7] = *hDIBSection - *piVar2 >> 1;
      iStack_4 = iStack_4 + -1;
      hDIBSection = piVar3;
      arg_3 = arg_3 + 1;
    } while (iStack_4 != 0);
  }
  return;
}



/*
 * Decompiled function: FUN_004f211a
 * Entry Point: 004f211a
 * Size: 140 bytes
 */


void FUN_004f211a(int hDIBSection,undefined4 card_slot,int *arg_3,int *arg_4,int *arg_5,int arg_6,
                 undefined4 arg_7,undefined4 arg_8,int arg_9)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  hDIBSection = in_EAX;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar1 = arg_5 + arg_9 * 2;
      piVar2 = arg_4;
      piVar3 = arg_3;
      while (piVar3 = piVar3 + 1, piVar3 < arg_3 + arg_6) {
        *piVar1 = *piVar2 + *piVar3 >> 1;
        piVar1[arg_9] = *piVar3 - *piVar2 >> 1;
        piVar1 = piVar1 + arg_9 * 2;
        piVar2 = piVar2 + 1;
      }
      arg_4 = piVar2 + 1;
      *arg_5 = *piVar2 + *arg_3 >> 1;
      arg_5[arg_9] = *arg_3 - *piVar2 >> 1;
      hDIBSection = hDIBSection + -1;
      arg_3 = piVar3;
      arg_5 = arg_5 + 1;
    } while (hDIBSection != 0);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f21d0
 * Entry Point: 004f21d0
 * Size: 11 bytes
 */


undefined1 *
Mem_AllocOrFree_004f21d0
          (undefined1 *hDIBSection,int *card_slot,int arg_3,int arg_4,int *arg_5,int *arg_6,int arg_7,
          undefined4 arg_8,int arg_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int iStack_1c;
  uint uStack_18;
  int iStack_14;
  int *piStack_10;
  int *piStack_c;
  
  if (DAT_0061d7e4 == 0) {
    iVar1 = -0x400;
    do {
      if (iVar1 < 1) {
        PTR_DAT_005300b0[iVar1] = 0;
      }
      else {
        iVar2 = iVar1 >> 2;
        if (0xfe < iVar2) {
          iVar2 = 0xff;
        }
        PTR_DAT_005300b0[iVar1] = (char)iVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x1c00);
    DAT_0061d7e4 = 1;
  }
  if (hDIBSection == (undefined1 *)0x0) {
    hDIBSection = malloc(arg_3 * arg_3 * 3 + 0x10);
  }
  iStack_14 = 0;
  if (0 < arg_4) {
    piStack_10 = arg_6;
    piStack_c = arg_5;
    puVar4 = hDIBSection;
    do {
      piVar5 = piStack_c;
      piVar6 = piStack_10;
      if (arg_9 != 0) {
        iVar1 = (iStack_14 / 2) * arg_7;
        piVar5 = arg_5 + iVar1;
        piVar6 = arg_6 + iVar1;
      }
      uStack_18 = 0;
      if (0 < arg_3) {
        do {
          iVar1 = *card_slot;
          if (arg_9 == 0) {
            iVar2 = *piVar6;
            iVar2 = (iVar2 >> 3) + (iVar2 >> 1) + iVar2;
            iStack_1c = *piVar5;
          }
          else {
            if ((uStack_18 & 1) == 0) {
              iStack_1c = *piVar5;
              iVar2 = *piVar6;
            }
            else {
              bVar7 = arg_3 - uStack_18 != 1;
              iStack_1c = (piVar5[bVar7] + *piVar5) / 2;
              iVar2 = (piVar6[bVar7] + *piVar6) / 2;
            }
            iVar2 = (iVar2 >> 3) + (iVar2 >> 1) + iVar2;
          }
          iVar3 = iVar2 + -0x333 + iVar1;
          iVar2 = iVar1 + -0x400 + iStack_1c * 2;
          *puVar4 = PTR_DAT_005300b0[iVar2];
          puVar4[1] = PTR_DAT_005300b0
                      [((((iVar2 >> 4) - (iVar1 >> 2)) - (iVar2 >> 2)) - (iVar3 >> 1)) + iVar1 * 2];
          puVar4[2] = PTR_DAT_005300b0[iVar3];
          if ((arg_9 == 0) || ((uStack_18 & 1) != 0)) {
            piVar5 = piVar5 + 1;
            piVar6 = piVar6 + 1;
          }
          uStack_18 = uStack_18 + 1;
          card_slot = card_slot + 1;
          puVar4 = puVar4 + 3;
        } while ((int)uStack_18 < arg_3);
      }
      piStack_10 = piStack_10 + arg_7;
      piStack_c = piStack_c + arg_7;
      iStack_14 = iStack_14 + 1;
    } while (iStack_14 < arg_4);
  }
  return hDIBSection;
}



/*
 * Decompiled function: FUN_004f21db
 * Entry Point: 004f21db
 * Size: 549 bytes
 */


undefined1 * FUN_004f21db(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  bool bVar8;
  uint uStack00000004;
  int iStack00000008;
  int *piStack0000000c;
  int *piStack00000010;
  undefined1 *in_stack_00000020;
  int *in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int *in_stack_00000030;
  int *in_stack_00000034;
  int in_stack_00000038;
  int in_stack_00000040;
  
  if (in_ZF) {
    iVar2 = -0x400;
    do {
      if (iVar2 < 1) {
        PTR_DAT_005300b0[iVar2] = 0;
      }
      else {
        iVar3 = iVar2 >> 2;
        if (0xfe < iVar3) {
          iVar3 = 0xff;
        }
        PTR_DAT_005300b0[iVar2] = (char)iVar3;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x1c00);
    DAT_0061d7e4 = 1;
  }
  if (in_stack_00000020 == (undefined1 *)0x0) {
    in_stack_00000020 = malloc(in_stack_00000028 * in_stack_00000028 * 3 + 0x10);
  }
  iStack00000008 = 0;
  if (0 < in_stack_0000002c) {
    piStack0000000c = in_stack_00000034;
    piStack00000010 = in_stack_00000030;
    puVar5 = in_stack_00000020;
    do {
      piVar6 = piStack00000010;
      piVar7 = piStack0000000c;
      if (in_stack_00000040 != 0) {
        iVar2 = (iStack00000008 / 2) * in_stack_00000038;
        piVar6 = in_stack_00000030 + iVar2;
        piVar7 = in_stack_00000034 + iVar2;
      }
      uStack00000004 = 0;
      if (0 < in_stack_00000028) {
        do {
          iVar2 = *in_stack_00000024;
          if (in_stack_00000040 == 0) {
            iVar3 = *piVar7;
            iVar3 = (iVar3 >> 3) + (iVar3 >> 1) + iVar3;
            iVar1 = *piVar6;
          }
          else {
            if ((uStack00000004 & 1) == 0) {
              iVar1 = *piVar6;
              iVar3 = *piVar7;
            }
            else {
              bVar8 = in_stack_00000028 - uStack00000004 != 1;
              iVar1 = (piVar6[bVar8] + *piVar6) / 2;
              iVar3 = (piVar7[bVar8] + *piVar7) / 2;
            }
            iVar3 = (iVar3 >> 3) + (iVar3 >> 1) + iVar3;
          }
          iVar4 = iVar3 + -0x333 + iVar2;
          iVar3 = iVar2 + -0x400 + iVar1 * 2;
          *puVar5 = PTR_DAT_005300b0[iVar3];
          puVar5[1] = PTR_DAT_005300b0
                      [((((iVar3 >> 4) - (iVar2 >> 2)) - (iVar3 >> 2)) - (iVar4 >> 1)) + iVar2 * 2];
          puVar5[2] = PTR_DAT_005300b0[iVar4];
          if ((in_stack_00000040 == 0) || ((uStack00000004 & 1) != 0)) {
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          uStack00000004 = uStack00000004 + 1;
          in_stack_00000024 = in_stack_00000024 + 1;
          puVar5 = puVar5 + 3;
        } while ((int)uStack00000004 < in_stack_00000028);
      }
      piStack0000000c = piStack0000000c + in_stack_00000038;
      piStack00000010 = piStack00000010 + in_stack_00000038;
      iStack00000008 = iStack00000008 + 1;
    } while (iStack00000008 < in_stack_0000002c);
  }
  return in_stack_00000020;
}



/*
 * Decompiled function: Haar_DecompressHeader
 * Entry Point: 004f2400
 * Size: 431 bytes
 */


undefined4 Haar_DecompressHeader(undefined4 *arg1,int *arg2)

{
  undefined4 *puVar1;
  int arg_3;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *local_20;
  undefined4 *local_18;
  int local_c;
  
  iVar2 = arg2[7] / (int)(2 - (uint)(arg2[10] == 1));
  iVar3 = iVar2 / (int)(2 - (uint)(*arg2 == 0));
  iVar3 = iVar3 * iVar3;
  iVar6 = arg2[9];
  piVar7 = (int *)arg2[0x68] + 1;
  arg_3 = *(int *)arg2[0x68];
  *piVar7 = -0x80000000;
  iVar4 = FUN_0048b950((uint *)(piVar7 + arg_3),piVar7,arg_3);
  puVar8 = (undefined4 *)((int)(piVar7 + arg_3) + iVar4);
  local_c = 0;
  if (0 < arg2[10]) {
    local_20 = arg2 + 0x17;
    local_18 = arg1;
    uVar11 = iVar6 * iVar6;
    do {
      puVar1 = local_18 + iVar2 * iVar2 + 0x20;
      puVar12 = puVar8;
      puVar9 = local_18;
      for (uVar5 = uVar11 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar9 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_0048c070(local_18 + uVar11,puVar8 + uVar11,*local_20);
      puVar9 = (undefined4 *)((int)(puVar8 + uVar11) + *local_20);
      puVar8 = puVar9;
      puVar12 = puVar1;
      for (uVar5 = uVar11 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = puVar9 + uVar11;
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      FUN_0048c070(puVar1 + uVar11,puVar10,local_20[4]);
      puVar9 = (undefined4 *)((int)puVar10 + local_20[4]);
      puVar8 = puVar9;
      puVar12 = puVar1 + iVar3 + 0x20;
      for (uVar5 = uVar11 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = puVar9 + uVar11;
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      FUN_0048c070(puVar1 + iVar3 + 0x20 + uVar11,puVar10,local_20[8]);
      piVar7 = local_20 + 8;
      local_20 = local_20 + 1;
      puVar8 = (undefined4 *)((int)puVar10 + *piVar7);
      local_18 = local_18 + iVar2 * iVar2 + iVar3 * 2 + 0x40;
      local_c = local_c + 1;
    } while (local_c < arg2[10]);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004f27c0
 * Entry Point: 004f27c0
 * Size: 1153 bytes
 */


uint * FUN_004f27c0(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  uint *puVar14;
  uint *puVar15;
  int iStack00000004;
  uint *puStack00000008;
  uint *puStack00000010;
  int iStack00000014;
  int iStack0000001c;
  int *piStack00000020;
  uint *in_stack_00005028;
  int *in_stack_0000502c;
  int in_stack_00005030;
  int in_stack_00005034;
  
  Mem_AllocOrFree_00513bd0();
  if (in_stack_0000502c != (int *)0x0) {
    iVar2 = in_stack_0000502c[7];
    iVar9 = in_stack_0000502c[8];
    if (in_stack_0000502c[0x6a] == 0) {
      puStack00000008 =
           (uint *)Haar_DecompressWaveletImage(in_stack_0000502c,(undefined8 *)&DAT_005663e0);
    }
    else {
      puStack00000008 = (uint *)in_stack_0000502c[0x6b];
    }
    uVar7 = in_stack_00005030 * 3;
    iVar5 = in_stack_0000502c[7];
    iVar8 = (DAT_00530068 - (int)uVar7 % DAT_00530068) % DAT_00530068;
    if (in_stack_00005028 == (uint *)0x0) {
      in_stack_00005028 = (uint *)&DAT_005e0be0;
    }
    iVar4 = 0;
    iVar1 = in_stack_00005030;
    piVar10 = (int *)&stack0x00000024;
    if (0 < in_stack_00005030) {
      do {
        iVar12 = iVar4 >> 8;
        iVar4 = iVar4 + (iVar2 << 0x10) / in_stack_00005030;
        iVar1 = iVar1 + -1;
        *piVar10 = iVar12;
        piVar10 = piVar10 + 1;
      } while (iVar1 != 0);
    }
    iVar2 = in_stack_0000502c[8];
    puStack00000010 = in_stack_00005028;
    if (iVar2 < in_stack_00005034) {
      puStack00000010 =
           (uint *)((int)in_stack_00005028 + (uVar7 + iVar8) * (in_stack_00005034 - iVar2));
    }
    iStack0000001c = 0;
    if (0 < iVar2) {
      puVar15 = puStack00000010;
      do {
        puVar3 = (uint *)&stack0x00000024;
        puVar14 = puVar15;
        iStack00000004 = in_stack_00005030;
        if (0 < in_stack_00005030) {
          do {
            pbVar13 = (byte *)(((int)*puVar3 >> 8) * 3 + (int)puStack00000008);
            puVar15 = (uint *)((int)puVar14 + 3);
            *(byte *)puVar14 =
                 (char)(((uint)pbVar13[3] - (uint)*pbVar13) * (*puVar3 & 0xff) >> 8) + *pbVar13;
            *(byte *)((int)puVar14 + 1) =
                 (char)(((uint)pbVar13[4] - (uint)pbVar13[1]) * (*puVar3 & 0xff) >> 8) + pbVar13[1];
            *(byte *)((int)puVar14 + 2) =
                 (char)(((uint)pbVar13[5] - (uint)pbVar13[2]) * (*puVar3 & 0xff) >> 8) + pbVar13[2];
            iStack00000004 = iStack00000004 + -1;
            puVar3 = puVar3 + 1;
            puVar14 = puVar15;
          } while (iStack00000004 != 0);
        }
        puStack00000008 = (uint *)((int)puStack00000008 + iVar5 * 3);
        iStack0000001c = iStack0000001c + 1;
        puVar15 = (uint *)((int)puVar15 + iVar8);
      } while (iStack0000001c < in_stack_0000502c[8]);
    }
    iVar5 = 0;
    iVar2 = in_stack_00005034;
    piStack00000020 = (int *)&stack0x00004024;
    if (0 < in_stack_00005034) {
      do {
        iVar1 = iVar5 >> 8;
        iVar5 = iVar5 + (iVar9 << 0x10) / in_stack_00005034;
        iVar2 = iVar2 + -1;
        *piStack00000020 = iVar1;
        piStack00000020 = piStack00000020 + 1;
      } while (iVar2 != 0);
    }
    uVar11 = uVar7 + iVar8;
    if (in_stack_00005034 < in_stack_0000502c[8]) {
      puVar15 = (uint *)((int)in_stack_00005028 + (in_stack_0000502c[8] + -1) * uVar11);
      puVar3 = (uint *)&stack0x00000024;
      for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar3 = puVar3 + 1;
      }
      for (uVar6 = uVar11 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)puVar3 = (char)*puVar15;
        puVar15 = (uint *)((int)puVar15 + 1);
        puVar3 = (uint *)((int)puVar3 + 1);
      }
    }
    if (0 < in_stack_00005030) {
      iStack00000004 = in_stack_00005030;
      puStack00000008 = in_stack_00005028;
      do {
        puVar15 = (uint *)&stack0x00004024;
        puVar3 = puStack00000008;
        iStack00000014 = in_stack_00005034 + -1;
        if (0 < in_stack_00005034 + -1) {
          do {
            iVar9 = (int)*puVar15 >> 8;
            iVar2 = in_stack_0000502c[8] + -2;
            if (iVar9 <= in_stack_0000502c[8] + -2) {
              iVar2 = iVar9;
            }
            puVar14 = (uint *)(iVar2 * uVar11 + (int)puStack00000010);
            *(byte *)puVar3 =
                 (char)(((uint)*(byte *)((int)puVar14 + uVar11) - (uint)(byte)*puVar14) *
                        (*puVar15 & 0xff) >> 8) + (byte)*puVar14;
            *(byte *)((int)puVar3 + 1) =
                 (char)(((uint)*(byte *)((int)puVar14 + uVar11 + 1) -
                        (uint)*(byte *)((int)puVar14 + 1)) * (*puVar15 & 0xff) >> 8) +
                 *(byte *)((int)puVar14 + 1);
            *(byte *)((int)puVar3 + 2) =
                 (char)(((uint)*(byte *)((int)puVar14 + uVar11 + 2) -
                        (uint)*(byte *)((int)puVar14 + 2)) * (*puVar15 & 0xff) >> 8) +
                 *(byte *)((int)puVar14 + 2);
            iStack00000014 = iStack00000014 + -1;
            puVar3 = (uint *)((int)puVar3 + uVar11);
            puVar15 = puVar15 + 1;
          } while (iStack00000014 != 0);
        }
        puStack00000010 = (uint *)((int)puStack00000010 + 3);
        puStack00000008 = (uint *)((int)puStack00000008 + 3);
        iStack00000004 = iStack00000004 + -1;
      } while (iStack00000004 != 0);
    }
    if (in_stack_00005034 < in_stack_0000502c[8]) {
      puVar15 = (uint *)&stack0x00000024;
      puVar3 = (uint *)((int)in_stack_00005028 + (in_stack_00005034 + -1) * uVar11);
      for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar3 = puVar3 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(char *)puVar3 = (char)*puVar15;
        puVar15 = (uint *)((int)puVar15 + 1);
        puVar3 = (uint *)((int)puVar3 + 1);
      }
    }
    else {
      puVar15 = (uint *)((int)in_stack_00005028 + (in_stack_00005034 + -1) * uVar11);
      for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined1 *)puVar15 = 0;
        puVar15 = (uint *)((int)puVar15 + 1);
      }
    }
    uVar11 = (int)uVar7 >> 0x1f;
    uVar7 = 4 - (((uVar7 ^ uVar11) - uVar11 & 3 ^ uVar11) - uVar11);
    uVar11 = (int)uVar7 >> 0x1f;
    iVar2 = ((uVar7 ^ uVar11) - uVar11 & 3 ^ uVar11) - uVar11;
    if (DAT_0052a1b8 == (uint *)0x0) {
      Palette_RemapBitmapRGB(in_stack_00005028,in_stack_00005034,in_stack_00005030,iVar2);
    }
    else if (DAT_006ff554 == 0x10) {
      Palette_DitherScanline
                ((int)DAT_0052a1b8,DAT_0052a1bc,(int)in_stack_00005028,in_stack_00005034,
                 in_stack_00005030,iVar2);
    }
    else if (DAT_006ff554 == 8) {
      Palette_DitherBitmapRGB
                (DAT_0052a1b8,DAT_0052a1bc,in_stack_00005028,in_stack_00005034,in_stack_00005030,
                 iVar2);
    }
    return in_stack_00005028;
  }
  return (uint *)0x0;
}



/*
 * Decompiled function: FUN_004f2c50
 * Entry Point: 004f2c50
 * Size: 140 bytes
 */


undefined4 FUN_004f2c50(HWND hDIBSection,int y,int width,int height)

{
  uint *arg_3;
  
  if (y == 0) {
    return 0;
  }
  arg_3 = (uint *)FUN_004f27c0(0,y,width,height);
  Palette_DitherBitmapRGB
            (DAT_0052a1b8,DAT_0052a1bc,arg_3,height,width,
             (DAT_00530068 - (width * 3) % DAT_00530068) % DAT_00530068);
  FUN_0050ec20(hDIBSection,arg_3,0,0,width,height);
  if (*(uint **)(y + 0x1ac) != arg_3) {
    free(arg_3);
  }
  return 1;
}



/*
 * Decompiled function: FUN_004f2d30
 * Entry Point: 004f2d30
 * Size: 292 bytes
 */


int FUN_004f2d30(HWND hwnd,int card_slot,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  undefined1 uVar1;
  undefined4 *lpvBits;
  int iVar2;
  BITMAPINFO *lpbmi;
  HDC hdc;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  DWORD DVar12;
  DWORD local_4;
  
  iVar8 = 0;
  iVar11 = 0;
  uVar4 = arg_6 * arg_5 * 3;
  lpvBits = malloc(arg_6 * arg_5 * 3 + 8);
  puVar7 = lpvBits;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  if (0 < (int)arg_6) {
    iVar5 = 0;
    local_4 = arg_6;
    puVar7 = lpvBits;
    do {
      if (0 < (int)arg_5) {
        piVar10 = (int *)(card_slot + iVar5 * 4);
        puVar6 = puVar7;
        iVar9 = iVar8;
        DVar12 = arg_5;
        do {
          iVar2 = *piVar10 >> 2;
          iVar8 = iVar2;
          if ((iVar9 <= iVar2) && (iVar8 = iVar9, iVar11 < iVar2)) {
            iVar11 = iVar2;
          }
          if (iVar2 < 1) {
            iVar2 = 0;
          }
          if (0xfe < iVar2) {
            iVar2 = 0xff;
          }
          uVar1 = (undefined1)iVar2;
          *(undefined1 *)((int)puVar6 + 2) = uVar1;
          piVar10 = piVar10 + 1;
          *(undefined1 *)((int)puVar6 + 1) = uVar1;
          puVar7 = (undefined4 *)((int)puVar6 + 3);
          DVar12 = DVar12 - 1;
          *(undefined1 *)puVar6 = uVar1;
          puVar6 = puVar7;
          iVar9 = iVar8;
        } while (DVar12 != 0);
      }
      iVar5 = iVar5 + arg_5;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  lpbmi = (BITMAPINFO *)FUN_0050ec90(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  iVar8 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,lpvBits,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  Mem_AllocOrFree_0050ed10(lpbmi);
  free(lpvBits);
  return iVar8;
}



/*
 * Decompiled function: UI_DialogProc_004f2e60
 * Entry Point: 004f2e60
 * Size: 246 bytes
 */


undefined4 UI_DialogProc_004f2e60(char *str_1,char *str_2,undefined4 *arg_3)

{
  INT_PTR IVar1;
  undefined4 local_21c;
  char local_214 [261];
  char local_10f [263];
  undefined4 local_8;
  
  local_8 = *arg_3;
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdd,g_MainAppHwnd,UI_CreateWindow_004f2f56,
                          (LPARAM)local_214);
  if (IVar1 == -1) {
    MessageBoxA(g_MainAppHwnd,s_Couldn_t_bring_up_the_Load_Decks_00530124,&DAT_00530120,0);
    local_21c = 0;
  }
  else if (IVar1 == 1) {
    strcpy(str_1,local_214);
    strcpy(str_2,local_10f);
    *arg_3 = local_8;
    DAT_0068a648 = 0;
    local_21c = 1;
  }
  else if (IVar1 == 0) {
    DAT_0068a648 = 1;
    local_21c = 1;
  }
  return local_21c;
}



/*
 * Decompiled function: UI_CreateWindow_004f2f56
 * Entry Point: 004f2f56
 * Size: 1561 bytes
 */


HGDIOBJ UI_CreateWindow_004f2f56(HWND hwnd,uint y,HDC hdc,HWND param_4)

{
  size_t sVar1;
  int iVar2;
  HWND pHVar3;
  UINT UVar4;
  HGDIOBJ pvVar5;
  HBRUSH hbr;
  tagRECT local_334;
  HWND local_324;
  int local_320;
  HDC local_31c;
  WPARAM local_314;
  undefined1 local_310 [32];
  char local_2f0 [264];
  char local_1e8 [264];
  HWND local_e0;
  int local_dc;
  char local_d8 [200];
  WPARAM local_10;
  FILE *local_c;
  char *local_8;
  
  if (y < 0x111) {
    if (y == 0x110) {
      DAT_0061d7e8 = param_4;
      local_e0 = CreateWindowExA(0,s_LISTBOX_00530150,&DAT_0053014c,0x40a00003,0,0,0,0,hwnd,
                                 (HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (local_e0 == (HWND)0x0) {
        EndDialog(hwnd,-1);
        return (HGDIOBJ)0x1;
      }
      strcpy(local_1e8,&DAT_006ff1b0);
      strcat(local_1e8,s____DCK_00530158);
      SendMessageA(local_e0,0x18d,0,(LPARAM)local_1e8);
      local_dc = SendMessageA(local_e0,0x18b,0,0);
      for (local_10 = 0; (int)local_10 < local_dc; local_10 = local_10 + 1) {
        SendMessageA(local_e0,0x189,local_10,(LPARAM)local_1e8);
        strcpy(local_2f0,&DAT_006ff1b0);
        strcat(local_2f0,&DAT_00530160);
        strcat(local_2f0,local_1e8);
        local_c = fopen(local_2f0,&DAT_00530164);
        if (local_c != (FILE *)0x0) {
          local_d8[0] = '\0';
          sVar1 = strlen(local_d8);
          local_8 = local_d8 + sVar1;
          while( true ) {
            iVar2 = fgetc(local_c);
            *local_8 = (char)iVar2;
            if (*local_8 == '\n') break;
            local_8 = local_8 + 1;
          }
          *local_8 = '\0';
          fclose(local_c);
          SendDlgItemMessageA(hwnd,1000,0x143,0,(LPARAM)local_d8);
          SendDlgItemMessageA(hwnd,0x3e9,0x143,0,(LPARAM)local_d8);
        }
      }
      SendDlgItemMessageA(hwnd,1000,0x14e,0,0);
      SendDlgItemMessageA(hwnd,0x3e9,0x14e,0,0);
      if ((DAT_0061d7e8[0x83].unused < 0) || (3 < DAT_0061d7e8[0x83].unused)) {
        DAT_0061d7e8[0x83].unused = 1;
      }
      CheckRadioButton(hwnd,0x3eb,0x3ee,DAT_0061d7e8[0x83].unused + 0x3eb);
      pHVar3 = GetDlgItem(hwnd,1);
      SetFocus(pHVar3);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      GDI_RealizeAndFlushPalette_Magic(hdc);
      GetClientRect(hwnd,&local_334);
      hbr = GetStockObject(1);
      FillRect(hdc,&local_334,hbr);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint)hdc & 0xffff) == 0x3ef) {
        FUN_004ff450(g_MainAppHwnd);
        pHVar3 = GetDlgItem(hwnd,1);
        SetFocus(pHVar3);
      }
      else if (((uint)hdc & 0xffff) == 1) {
        local_314 = SendDlgItemMessageA(hwnd,1000,0x147,0,0);
        SendDlgItemMessageA(hwnd,1000,0x148,local_314,(LPARAM)local_310);
        sprintf((char *)DAT_0061d7e8,s__s__s_dck_00530168,&DAT_006ff1b0,local_310);
        local_314 = SendDlgItemMessageA(hwnd,0x3e9,0x147,0,0);
        SendDlgItemMessageA(hwnd,0x3e9,0x148,local_314,(LPARAM)local_310);
        sprintf((char *)((int)&DAT_0061d7e8[0x41].unused + 1),s__s__s_dck_00530174,&DAT_006ff1b0,
                local_310);
        UVar4 = IsDlgButtonChecked(hwnd,0x3eb);
        if (UVar4 == 0) {
          UVar4 = IsDlgButtonChecked(hwnd,0x3ec);
          if (UVar4 == 0) {
            UVar4 = IsDlgButtonChecked(hwnd,0x3ed);
            if (UVar4 == 0) {
              UVar4 = IsDlgButtonChecked(hwnd,0x3ee);
              if (UVar4 != 0) {
                DAT_0061d7e8[0x83].unused = 3;
              }
            }
            else {
              DAT_0061d7e8[0x83].unused = 2;
            }
          }
          else {
            DAT_0061d7e8[0x83].unused = 1;
          }
        }
        else {
          DAT_0061d7e8[0x83].unused = 0;
        }
        EndDialog(hwnd,1);
      }
      else if (((uint)hdc & 0xffff) == 0x471) {
        FUN_0048c72a(1);
        g_IsAiThinking = 0xfffffffe;
        EndDialog(hwnd,0);
      }
      else if (((uint)hdc & 0xffff) == 0x472) {
        FUN_0048c72a(0);
        g_IsAiThinking = 0xffffffff;
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_31c = hdc;
      GDI_RealizeAndFlushPalette_Magic(hdc);
      local_324 = param_4;
      local_320 = GetDlgCtrlID(param_4);
      if (local_320 != 0x3ea) {
        SetBkMode(local_31c,1);
        pvVar5 = GetStockObject(5);
        return pvVar5;
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: FUN_004f3579
 * Entry Point: 004f3579
 * Size: 775 bytes
 */


undefined4 FUN_004f3579(int hDIBSection)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_28;
  int local_1c;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_28 = 0;
  local_10 = 0;
  local_30 = 0;
  local_8 = 0;
  if (hDIBSection == -1) {
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      if ((*(int *)(&deck + local_1c * 4) != -1) && (((&DAT_00702151)[local_1c * 4] & 0xc0) == 0)) {
        bVar1 = (&DAT_0051aebe)[(*(uint *)(&deck + local_1c * 4) & 0xfff) * 0x34];
        if ((bVar1 & 2) != 0) {
          local_8 = local_8 + 1;
        }
        if ((bVar1 & 0x20) != 0) {
          local_30 = local_30 + 1;
        }
        if ((bVar1 & 8) != 0) {
          local_10 = local_10 + 1;
        }
        if ((bVar1 & 0x10) != 0) {
          local_28 = local_28 + 1;
        }
        if ((bVar1 & 4) != 0) {
          local_c = local_c + 1;
        }
      }
    }
  }
  else {
    for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
      iVar2 = *(int *)(&DAT_00516cbc + local_1c * 8 + hDIBSection * 0x280);
      if ((*(int *)(&DAT_00516cb8 + local_1c * 8 + hDIBSection * 0x280) != -1) && (iVar2 != 0)) {
        iVar3 = CardTypeFromID(*(int *)(&DAT_00516cb8 + local_1c * 8 + hDIBSection * 0x280));
        bVar1 = (&DAT_0051aebe)[iVar3 * 0x34];
        if ((bVar1 & 2) != 0) {
          local_8 = local_8 + iVar2;
        }
        if ((bVar1 & 0x20) != 0) {
          local_30 = local_30 + iVar2;
        }
        if ((bVar1 & 8) != 0) {
          local_10 = local_10 + iVar2;
        }
        if ((bVar1 & 0x10) != 0) {
          local_28 = local_28 + iVar2;
        }
        if ((bVar1 & 4) != 0) {
          local_c = local_c + iVar2;
        }
      }
    }
  }
  local_14 = 0;
  if ((((local_8 < local_30) || (local_8 < local_10)) || (local_8 < local_28)) ||
     (local_8 < local_c)) {
    if (((local_30 < local_8) || (local_30 < local_10)) ||
       ((local_30 < local_28 || (local_30 < local_c)))) {
      if (((local_10 < local_8) || (local_10 < local_30)) ||
         ((local_10 < local_28 || (local_10 < local_c)))) {
        if ((((local_28 < local_8) || (local_28 < local_10)) || (local_28 < local_30)) ||
           (local_28 < local_c)) {
          if (((local_8 <= local_c) && (local_10 <= local_c)) &&
             ((local_28 <= local_c && (local_30 <= local_c)))) {
            local_14 = 2;
          }
        }
        else {
          local_14 = 4;
        }
      }
      else {
        local_14 = 3;
      }
    }
    else {
      local_14 = 5;
    }
  }
  else {
    local_14 = 1;
  }
  return local_14;
}



/*
 * Decompiled function: FUN_004f3880
 * Entry Point: 004f3880
 * Size: 93 bytes
 */


bool FUN_004f3880(void)

{
  if (DAT_00530180 == 0) {
    FUN_004f39a4(10,10,&DAT_00530180,(BITMAPINFO *)0x0,&DAT_0061d7f0,(undefined4 *)0x0,(int *)0x0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
  }
  return DAT_00530180 != 0;
}



/*
 * Decompiled function: FUN_004f38dd
 * Entry Point: 004f38dd
 * Size: 65 bytes
 */


void FUN_004f38dd(void)

{
  if (DAT_00530180 != (HDC)0x0) {
    FUN_004f3b2c(DAT_00530180,DAT_0061d7f0);
    DAT_00530180 = (HDC)0x0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
  }
  return;
}



/*
 * Decompiled function: FUN_004f391e
 * Entry Point: 004f391e
 * Size: 55 bytes
 */


void FUN_004f391e(char *str_1)

{
  char *pcVar1;
  
  GetModuleFileNameA((HMODULE)0x0,str_1,0x105);
  pcVar1 = strrchr(str_1,0x5c);
  *pcVar1 = '\0';
  return;
}



/*
 * Decompiled function: GDI_RealizeAndFlushPalette_Magic
 * Entry Point: 004f3955
 * Size: 79 bytes
 */


void GDI_RealizeAndFlushPalette_Magic(HDC hdc)

{
  SelectPalette(hdc,DAT_00680774,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_006a4b70);
  SetStretchBltMode(hdc,3);
  return;
}



/*
 * Decompiled function: FUN_004f39a4
 * Entry Point: 004f39a4
 * Size: 387 bytes
 */


undefined4
FUN_004f39a4(undefined4 hDIBSection,int card_slot,undefined4 *arg_3,BITMAPINFO *arg_4,undefined4 *arg_5,
            undefined4 *arg_6,int *arg_7)

{
  undefined4 uVar1;
  HDC hdc;
  HBITMAP local_44;
  HDC local_3c;
  BITMAPINFO local_38;
  HGDIOBJ local_c;
  void *local_8;
  
  local_3c = (HDC)0x0;
  local_44 = (HBITMAP)0x0;
  local_8 = (void *)0x0;
  if ((arg_3 == (undefined4 *)0x0) || (arg_5 == (undefined4 *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (arg_4 == (BITMAPINFO *)0x0) {
      arg_4 = &local_38;
    }
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      GDI_RealizeAndFlushPalette_Magic(hdc);
      local_3c = CreateCompatibleDC(hdc);
      if (local_3c != (HDC)0x0) {
        FUN_005017f0((undefined4 *)arg_4,hDIBSection,card_slot);
        local_38.bmiHeader.biBitCount = 0x20;
        local_44 = CreateDIBSection(hdc,arg_4,0,&local_8,(HANDLE)0x0,0);
        local_c = SelectObject(local_3c,local_44);
        GDI_RealizeAndFlushPalette_Magic(local_3c);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    if (((local_3c == (HDC)0x0) || (local_44 == (HBITMAP)0x0)) || (local_8 == (void *)0x0)) {
      if (local_3c != (HDC)0x0) {
        DeleteDC(local_3c);
      }
      if (local_44 != (HBITMAP)0x0) {
        DeleteObject(local_44);
      }
      uVar1 = 0;
    }
    else {
      if (arg_3 != (undefined4 *)0x0) {
        *arg_3 = local_3c;
      }
      if (arg_5 != (undefined4 *)0x0) {
        *arg_5 = local_44;
      }
      if (arg_6 != (undefined4 *)0x0) {
        *arg_6 = local_c;
      }
      if (arg_7 != (int *)0x0) {
        *arg_7 = (int)local_8;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f3b2c
 * Entry Point: 004f3b2c
 * Size: 51 bytes
 */


void FUN_004f3b2c(HDC hdc,HGDIOBJ arg2)

{
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  return;
}



/*
 * Decompiled function: FUN_004f3b5f
 * Entry Point: 004f3b5f
 * Size: 104 bytes
 */


undefined4 FUN_004f3b5f(int hDIBSection,int card_slot,HANDLE arg_3)

{
  undefined4 uVar1;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  
  if (((hDIBSection == 0) || (card_slot == 0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    GetObjectA(arg_3,0x18,local_1c);
    uVar1 = FUN_004f3bc7((HDC)hDIBSection,(int *)card_slot,arg_3,0,0,local_18,local_14);
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f3bc7
 * Entry Point: 004f3bc7
 * Size: 330 bytes
 */


undefined4 FUN_004f3bc7(HDC hdc,int *card_slot,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  undefined4 uVar1;
  HGDIOBJ h;
  int local_2c;
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    h = SelectObject(DAT_00530180,arg_3);
    GetObjectA(arg_3,0x18,local_28);
    local_8 = *card_slot;
    local_c = card_slot[1];
    if (card_slot[2] < *card_slot) {
      local_10 = local_24;
    }
    else {
      local_10 = card_slot[2] - *card_slot;
    }
    if (card_slot[3] < card_slot[1]) {
      local_2c = local_20;
    }
    else {
      local_2c = card_slot[3] - card_slot[1];
    }
    GDI_RealizeAndFlushPalette_Magic(DAT_00530180);
    if (arg_7 <= local_20) {
      local_20 = arg_7;
    }
    if (arg_6 <= local_24) {
      local_24 = arg_6;
    }
    StretchBlt(hdc,local_8,local_c,local_10,local_2c,DAT_00530180,arg_4,arg_5,local_24,local_20,
               0xcc0020);
    SelectObject(DAT_00530180,h);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f3d11
 * Entry Point: 004f3d11
 * Size: 280 bytes
 */


undefined4 FUN_004f3d11(HDC hdc,int *card_slot,HANDLE arg_3)

{
  undefined4 uVar1;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  tagRECT local_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    local_c = SaveDC(hdc);
    IntersectClipRect(hdc,*card_slot,card_slot[1],card_slot[2],card_slot[3]);
    GetObjectA(arg_3,0x18,local_38);
    for (local_8 = *card_slot; local_8 < card_slot[2]; local_8 = local_8 + local_34) {
      for (local_10 = card_slot[1]; local_10 < card_slot[3]; local_10 = local_10 + local_30) {
        SetRect(&local_20,local_8,local_10,local_8 + -1,local_10 + -1);
        FUN_004f3bc7(hdc,&local_20.left,arg_3,0,0,local_34,local_30);
      }
    }
    RestoreDC(hdc,local_c);
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f3e29
 * Entry Point: 004f3e29
 * Size: 129 bytes
 */


undefined4 FUN_004f3e29(HDC hDIBSection,int *card_slot,HANDLE arg_3)

{
  undefined4 uVar1;
  undefined1 local_34 [4];
  int local_30;
  int local_2c;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  GetObjectA(arg_3,0x18,local_34);
  local_18 = local_30 / 2;
  local_1c = local_2c;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  local_8 = local_18;
  uVar1 = FUN_004f3eaa(hDIBSection,card_slot,arg_3,local_18,local_2c,0,0,local_18,0);
  return uVar1;
}



/*
 * Decompiled function: FUN_004f3eaa
 * Entry Point: 004f3eaa
 * Size: 379 bytes
 */


undefined4
FUN_004f3eaa(HDC hdc,int *card_slot,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9)

{
  undefined4 uVar1;
  int local_30;
  undefined1 local_2c [24];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    local_10 = SaveDC(hdc);
    SelectObject(DAT_00530180,arg_3);
    GetObjectA(arg_3,0x18,local_2c);
    local_8 = *card_slot;
    local_c = card_slot[1];
    if (card_slot[2] < *card_slot) {
      local_14 = arg_4;
    }
    else {
      local_14 = card_slot[2] - *card_slot;
    }
    if (card_slot[3] < card_slot[1]) {
      local_30 = arg_5;
    }
    else {
      local_30 = card_slot[3] - card_slot[1];
    }
    GDI_RealizeAndFlushPalette_Magic(DAT_00530180);
    StretchBlt(hdc,local_8,local_c,local_14,local_30,DAT_00530180,arg_8,arg_9,arg_4,arg_5,0x8800c6);
    GDI_RealizeAndFlushPalette_Magic(DAT_00530180);
    StretchBlt(hdc,local_8,local_c,local_14,local_30,DAT_00530180,arg_6,arg_7,arg_4,arg_5,0xee0086);
    RestoreDC(hdc,local_10);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f4025
 * Entry Point: 004f4025
 * Size: 193 bytes
 */


undefined4 FUN_004f4025(undefined4 hDIBSection,LPCSTR str_2,void *arg_3,undefined4 arg_4)

{
  char local_208 [500];
  undefined4 local_14;
  HGLOBAL local_10;
  BITMAPINFO *local_c;
  HRSRC local_8;
  
  local_14 = 0;
  local_8 = FindResourceA(g_AppHInstance,str_2,(LPCSTR)0x2);
  if (local_8 != (HRSRC)0x0) {
    local_10 = LoadResource(g_AppHInstance,local_8);
    if (local_10 != (HGLOBAL)0x0) {
      local_c = LockResource(local_10);
      if (local_c != (BITMAPINFO *)0x0) {
        local_14 = FUN_004f41e7(local_c,arg_3);
      }
    }
  }
  if (DAT_006b157c != 0) {
    sprintf(local_208,s__08X_LoadDIBSection___s__005301c4,local_14,str_2);
    OutputDebugStringA(local_208);
  }
  return local_14;
}



/*
 * Decompiled function: FUN_004f40e6
 * Entry Point: 004f40e6
 * Size: 257 bytes
 */


undefined4 FUN_004f40e6(LPCSTR str_1,void *card_slot,undefined4 arg_3)

{
  char local_20c [500];
  undefined4 local_18;
  HANDLE local_14;
  HANDLE local_10;
  LPVOID local_c;
  BITMAPINFO *local_8;
  
  local_18 = 0;
  local_14 = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  if (local_14 != (HANDLE)0xffffffff) {
    local_10 = CreateFileMappingA(local_14,(LPSECURITY_ATTRIBUTES)0x0,0x8000000,0,0,(LPCSTR)0x0);
    if (local_10 != (HANDLE)0x0) {
      local_c = MapViewOfFile(local_10,4,0,0,0);
      if (local_c != (LPVOID)0x0) {
        local_8 = (BITMAPINFO *)((int)local_c + 0xe);
        local_18 = FUN_004f41e7(local_8,card_slot);
        UnmapViewOfFile(local_8);
      }
      CloseHandle(local_10);
    }
    CloseHandle(local_14);
  }
  if (DAT_006b157c != 0) {
    sprintf(local_20c,s__08X_LoadDIBSectionFromFile___s__005301e0,local_18,str_1);
    OutputDebugStringA(local_20c);
  }
  return local_18;
}



/*
 * Decompiled function: FUN_004f41e7
 * Entry Point: 004f41e7
 * Size: 795 bytes
 */


HBITMAP FUN_004f41e7(BITMAPINFO *arg1,void *arg2)

{
  WORD WVar1;
  BYTE *lpBits;
  BITMAPINFO *lpbmi;
  DWORD DVar2;
  HANDLE hSection;
  HDC hdc;
  int local_30;
  HBITMAP local_2c;
  DWORD local_28;
  void *local_10;
  DWORD local_c;
  int local_8;
  
  local_2c = (HBITMAP)0x0;
  WVar1 = (arg1->bmiHeader).biBitCount;
  if (WVar1 == 1) {
    local_8 = 2;
  }
  else if (WVar1 == 4) {
    local_8 = 0x10;
  }
  else if (WVar1 == 8) {
    local_8 = 0x100;
  }
  else {
    local_8 = 0;
  }
  lpBits = &arg1->bmiColors[local_8 + -10].rgbBlue + (arg1->bmiHeader).biSize;
  lpbmi = malloc(local_8 * 4 + 0x28);
  if (lpbmi != (BITMAPINFO *)0x0) {
    memcpy(lpbmi,arg1,0x28);
    memcpy(lpbmi->bmiColors,arg1->bmiColors,local_8 << 2);
    if ((arg1->bmiHeader).biWidth % 3 == 0) {
      local_30 = 0;
    }
    else {
      local_30 = 4 - (arg1->bmiHeader).biWidth % 3;
    }
    local_28 = ((arg1->bmiHeader).biWidth + local_30) * (arg1->bmiHeader).biHeight;
    switch((arg1->bmiHeader).biBitCount) {
    case 1:
      break;
    case 4:
      break;
    case 8:
      break;
    case 0x10:
      local_28 = local_28 * 2;
      break;
    case 0x18:
      local_28 = local_28 * 3;
      break;
    case 0x20:
      local_28 = local_28 * 4;
    }
    local_c = (arg1->bmiHeader).biSizeImage;
    DVar2 = local_c;
    if ((int)local_c <= (int)local_28) {
      DVar2 = local_28;
    }
    hSection = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                  DVar2 + 1000,(LPCSTR)0x0);
    if (hSection != (HANDLE)0x0) {
      hdc = GetDC((HWND)0x0);
      GDI_RealizeAndFlushPalette_Magic(hdc);
      (lpbmi->bmiHeader).biSizeImage = local_28;
      (lpbmi->bmiHeader).biCompression = 0;
      if (local_8 == 0) {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&local_10,hSection,0);
      }
      else {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&local_10,hSection,0);
      }
      (lpbmi->bmiHeader).biSizeImage = local_c;
      if (local_2c == (HBITMAP)0x0) {
        CloseHandle(hSection);
      }
      else {
        if (local_8 == 0) {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        else {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        if (arg2 != (void *)0x0) {
          memcpy(arg2,arg1,0x28);
          memcpy((void *)((int)arg2 + 0x28),arg1->bmiColors,local_8 << 2);
        }
        SetBitmapDimensionEx(local_2c,(int)hSection,0,(LPSIZE)0x0);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    free(lpbmi);
  }
  return local_2c;
}



/*
 * Decompiled function: GDI_DestroyDIBSection_Magic
 * Entry Point: 004f4548
 * Size: 146 bytes
 */


void GDI_DestroyDIBSection_Magic(HANDLE hDIBSection)

{
  char local_254 [500];
  HANDLE local_60;
  undefined1 local_5c [20];
  int local_48;
  HANDLE local_10;
  int local_c;
  int local_8;
  
  if (hDIBSection != (HANDLE)0x0) {
    GetObjectA(hDIBSection,0x54,local_5c);
    local_60 = local_10;
    local_8 = local_48 + local_c;
    DeleteObject(hDIBSection);
    if (local_60 != (HANDLE)0x0) {
      CloseHandle(local_60);
    }
  }
  if (DAT_006b157c != 0) {
    sprintf(local_254,s__08x_DestroyDIBSection__file_map_00530204,hDIBSection,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}



/*
 * Decompiled function: FUN_004f45da
 * Entry Point: 004f45da
 * Size: 753 bytes
 */


undefined4 FUN_004f45da(void)

{
  UINT UVar1;
  PALETTEENTRY local_628;
  char local_624 [264];
  undefined4 local_51c;
  UINT local_514;
  char local_510 [264];
  LOGPALETTE *local_408;
  tagPALETTEENTRY local_404 [256];
  
  local_51c = 1;
  strcpy(local_624,&DAT_006807a0);
  strcat(local_624,s__DUELPALall_TR_00530234);
  strcpy(local_510,&DAT_006807a0);
  strcat(local_510,s__DUEL_plogpal_00530244);
  local_408 = (LOGPALETTE *)Catalog_LoadPaletteMap(local_624,local_510);
  if (local_408 == (LOGPALETTE *)0x0) {
    local_51c = 0;
  }
  else {
    for (local_514 = 1; (int)local_514 < 0xff; local_514 = local_514 + 1) {
      local_408->palPalEntry[local_514].peFlags = '\x04';
    }
    DAT_00680774 = CreatePalette(local_408);
    if (DAT_00680774 == (HPALETTE)0x0) {
      local_51c = 0;
    }
    else {
      local_628.peRed = 0xff;
      local_628.peGreen = 0xff;
      local_628.peBlue = 0xff;
      local_628.peFlags = '\0';
      SetPaletteEntries(DAT_00680774,0xff,1,&local_628);
      local_628.peRed = 0xfe;
      local_628.peGreen = 0xfe;
      local_628.peBlue = 0xfe;
      local_628.peFlags = '\x04';
      SetPaletteEntries(DAT_00680774,0xbf,1,&local_628);
      for (local_514 = 0xec; (int)local_514 < 0xff; local_514 = local_514 + 1) {
        local_628.peRed = '\x01';
        local_628.peGreen = '\x01';
        local_628.peBlue = '\x01';
        local_628.peFlags = '\x04';
        SetPaletteEntries(DAT_00680774,local_514,1,&local_628);
      }
      UVar1 = GetPaletteEntries(DAT_00680774,0,0x100,local_404);
      for (local_514 = 0; (int)local_514 < (int)UVar1; local_514 = local_514 + 1) {
        (&DAT_006a4b70)[local_514 * 4] = local_404[local_514].peBlue;
        (&DAT_006a4b71)[local_514 * 4] = local_404[local_514].peGreen;
        (&DAT_006a4b72)[local_514 * 4] = local_404[local_514].peRed;
        (&DAT_006a4b73)[local_514 * 4] = 0;
      }
      while (local_514 = UVar1, (int)local_514 < 0x100) {
        (&DAT_006a4b70)[local_514 * 4] = 0;
        (&DAT_006a4b71)[local_514 * 4] = 0;
        (&DAT_006a4b72)[local_514 * 4] = 0;
        (&DAT_006a4b73)[local_514 * 4] = 0;
        UVar1 = local_514 + 1;
      }
    }
  }
  return local_51c;
}



/*
 * Decompiled function: FUN_004f48cb
 * Entry Point: 004f48cb
 * Size: 38 bytes
 */


void FUN_004f48cb(void)

{
  DeleteObject(DAT_00680774);
  DAT_00680774 = (HGDIOBJ)0x0;
  Palette_Util_00495410();
  return;
}



/*
 * Decompiled function: FUN_004f48f1
 * Entry Point: 004f48f1
 * Size: 417 bytes
 */


void FUN_004f48f1(int hDIBSection,int card_slot,RECT *arg_3)

{
  int arg_3_00;
  int iVar1;
  undefined4 arg_6;
  undefined4 uVar2;
  uint arg_2_00;
  int local_28;
  tagRECT local_14;
  
  if (((hDIBSection != 0) && (card_slot != 0)) && (arg_3 != (RECT *)0x0)) {
    CopyRect(&local_14,arg_3);
    arg_3_00 = *(int *)(hDIBSection + 4);
    arg_2_00 = (uint)*(ushort *)(hDIBSection + 0xe);
    while( true ) {
      local_14.bottom = local_14.bottom + -1;
      local_14.right = local_14.right + -1;
      if (local_14.right <= local_14.left) break;
      for (local_28 = local_14.left; local_28 < local_14.right; local_28 = local_28 + 1) {
        iVar1 = local_28 - local_14.left;
        arg_6 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,local_14.left + iVar1,local_14.top);
        uVar2 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,local_14.left,local_14.bottom - iVar1);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,local_14.left + iVar1,local_14.top,uVar2);
        uVar2 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,local_14.right - iVar1,local_14.bottom);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,local_14.left,local_14.bottom - iVar1,uVar2);
        uVar2 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,local_14.right,local_14.top + iVar1);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,local_14.right - iVar1,local_14.bottom,uVar2);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,local_14.right,local_14.top + iVar1,arg_6);
      }
      local_14.left = local_14.left + 1;
      local_14.top = local_14.top + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004f4a92
 * Entry Point: 004f4a92
 * Size: 591 bytes
 */


void FUN_004f4a92(char *str_1,char *str_2,int width,char *str_4)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  uint local_20c;
  int local_208;
  char local_204 [500];
  size_t local_10;
  int local_c;
  char *local_8;
  
  if (((((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) && (str_4 != (char *)0x0)) &&
      ((sVar2 = strlen(str_1), sVar2 != 0 && (sVar2 = strlen(str_2), sVar2 != 0)))) &&
     (sVar2 = strlen(str_4), sVar2 != 0)) {
    local_10 = strlen(str_2);
    local_8 = str_1;
    local_204[0] = '\0';
    local_208 = 0;
    while (*local_8 != '\0') {
      local_c = 0;
      if (((width != 0) && (iVar3 = strncmp(local_8,str_2,local_10), iVar3 == 0)) ||
         ((width == 0 && (iVar3 = _strnicmp(local_8,str_2,local_10), iVar3 == 0)))) {
        if (local_8[local_10] == '\0') {
          local_c = 1;
        }
        else if (local_8[local_10] == 's') {
          local_c = 1;
        }
        else if (local_8[local_10] == '.') {
          local_c = 1;
        }
        else if (local_8[local_10] == ' ') {
          piVar4 = (int *)__p___mb_cur_max();
          if (*piVar4 < 2) {
            cVar1 = local_8[local_10 + 1];
            piVar4 = (int *)__p__pctype();
            local_20c = *(ushort *)(*piVar4 + cVar1 * 2) & 1;
          }
          else {
            local_20c = _isctype((int)local_8[local_10 + 1],1);
          }
          if (local_20c == 0) {
            local_c = 1;
          }
        }
      }
      if (local_c == 0) {
        local_204[local_208] = *local_8;
        local_8 = local_8 + 1;
        local_204[local_208 + 1] = '\0';
        local_208 = local_208 + 1;
      }
      else {
        strcat(local_204,str_4);
        sVar2 = strlen(str_4);
        local_8 = local_8 + local_10;
        local_208 = local_208 + sVar2;
      }
    }
    strcpy(str_1,local_204);
  }
  return;
}



/*
 * Decompiled function: FUN_004f4ce1
 * Entry Point: 004f4ce1
 * Size: 461 bytes
 */


int FUN_004f4ce1(char *str_1,char *str_2,int arg_3)

{
  char cVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  int *piVar5;
  uint local_18;
  int local_14;
  char *local_8;
  
  if ((((str_1 == (char *)0x0) || (str_2 == (char *)0x0)) || (sVar3 = strlen(str_1), sVar3 == 0)) ||
     (sVar3 = strlen(str_2), sVar3 == 0)) {
    return -1;
  }
  sVar3 = strlen(str_2);
  local_8 = str_1;
  local_14 = 0;
  bVar2 = false;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if ((*local_8 == '\0') || (bVar2)) {
              if (!bVar2) {
                return -1;
              }
              return local_14;
            }
            if (((arg_3 != 0) && (iVar4 = strncmp(local_8,str_2,sVar3), iVar4 == 0)) ||
               ((arg_3 == 0 && (iVar4 = _strnicmp(local_8,str_2,sVar3), iVar4 == 0)))) break;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          if (local_8[sVar3] != 's') break;
          bVar2 = true;
        }
        if (local_8[sVar3] != '.') break;
        bVar2 = true;
      }
      if (local_8[sVar3] == ' ') break;
LAB_004f4e77:
      local_8 = local_8 + 1;
      local_14 = local_14 + 1;
    }
    piVar5 = (int *)__p___mb_cur_max();
    if (*piVar5 < 2) {
      cVar1 = local_8[sVar3 + 1];
      piVar5 = (int *)__p__pctype();
      local_18 = *(ushort *)(*piVar5 + cVar1 * 2) & 1;
    }
    else {
      local_18 = _isctype((int)local_8[sVar3 + 1],1);
    }
    if (local_18 != 0) goto LAB_004f4e77;
    bVar2 = true;
  } while( true );
}



/*
 * Decompiled function: FUN_004f4eb3
 * Entry Point: 004f4eb3
 * Size: 261 bytes
 */


int FUN_004f4eb3(HWND hwnd,char *str_2)

{
  int iVar1;
  HGDIOBJ h;
  HDC hdc;
  char local_104 [200];
  tagTEXTMETRICA local_3c;
  
  if (hwnd == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    h = (HGDIOBJ)SendMessageA(hwnd,0x31,0,0);
    if (str_2 == (char *)0x0) {
      GetWindowTextA(hwnd,local_104,200);
    }
    else {
      strcpy(local_104,str_2);
    }
    hdc = GetDC(hwnd);
    GDI_RealizeAndFlushPalette_Magic(hdc);
    if (h != (HGDIOBJ)0x0) {
      SelectObject(hdc,h);
    }
    iVar1 = Palette_Subsystem_0049dcd5(hdc,local_104);
    GetTextMetricsA(hdc,&local_3c);
    iVar1 = iVar1 + local_3c.tmHeight * 3;
    ReleaseDC(hwnd,hdc);
  }
  return iVar1;
}



/*
 * Decompiled function: UI_WndProc_004f4fb8
 * Entry Point: 004f4fb8
 * Size: 134 bytes
 */


LRESULT UI_WndProc_004f4fb8(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)

{
  HCURSOR hCursor;
  LRESULT LVar1;
  
  if (uMsg == 0x20) {
    if (DAT_006b1578 == 0) {
      hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f8a);
      SetCursor(hCursor);
      LVar1 = 0;
    }
    else {
      LVar1 = DefWindowProcA(hwnd,0x20,wParam,lParam);
    }
  }
  else {
    LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  }
  return LVar1;
}



/*
 * Decompiled function: FUN_004f5048
 * Entry Point: 004f5048
 * Size: 191 bytes
 */


undefined4 FUN_004f5048(char *str_1,COLORREF card_slot,HBRUSH arg_3)

{
  HDC hdc;
  size_t c;
  tagRECT local_14;
  
  SetRect(&local_14,0,0x23f,0x8c,0x26c);
  if (DAT_00530184 != 0xffffffff) {
    hdc = CreateDCA(s_DISPLAY_00530254,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
    SetTextColor(hdc,card_slot);
    SetBkMode(hdc,1);
    FillRect(hdc,&local_14,arg_3);
    c = strlen(str_1);
    TextOutA(hdc,local_14.left + 5,local_14.top + 5,str_1,c);
    DeleteDC(hdc);
    Sleep(DAT_00530184);
  }
  return 1;
}



/*
 * Decompiled function: FUN_004f5107
 * Entry Point: 004f5107
 * Size: 974 bytes
 */


void FUN_004f5107(int hDIBSection,HBRUSH card_slot,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  HGDIOBJ h;
  size_t c;
  tagSIZE *psizl;
  RECT local_64;
  HGDIOBJ local_54;
  tagRECT local_50;
  CHAR local_40 [52];
  tagSIZE local_c;
  
  hdc = *(HDC *)(hDIBSection + 0x18);
  CopyRect(&local_50,(RECT *)(hDIBSection + 0x1c));
  GetWindowTextA(*(HWND *)(hDIBSection + 0x14),local_40,0x32);
  GDI_RealizeAndFlushPalette_Magic(hdc);
  OffsetRect(&local_50,-*(int *)(hDIBSection + 0x1c),-*(int *)(hDIBSection + 0x20));
  if ((*(byte *)(hDIBSection + 0x10) & 1) == 0) {
    FillRect(hdc,&local_50,card_slot);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,local_50.bottom);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,local_50.bottom + -1);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,local_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom);
    MoveToEx(hdc,1,local_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,local_50.bottom + -1);
    MoveToEx(hdc,local_50.right + -2,2,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -2,local_50.bottom + -1);
    MoveToEx(hdc,2,local_50.bottom + -2,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom + -2);
  }
  else {
    FillRect(hdc,&local_50,card_slot);
    h = GetStockObject(7);
    SelectObject(hdc,h);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,local_50.bottom);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,local_50.bottom + -1);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,local_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom);
    MoveToEx(hdc,1,local_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,local_50.bottom + -1);
    OffsetRect(&local_50,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  local_54 = (HGDIOBJ)SendMessageA(*(HWND *)(hDIBSection + 0x14),0x31,0,0);
  SelectObject(hdc,local_54);
  DrawTextA(hdc,local_40,-1,&local_50,0x25);
  if ((arg_6 != 0) && ((*(byte *)(hDIBSection + 0x10) & 0x10) != 0)) {
    psizl = &local_c;
    c = strlen(local_40);
    GetTextExtentPoint32A(hdc,local_40,c,psizl);
    local_64.left = ((local_50.right - local_50.left) / 2 - local_c.cx / 2) + -3;
    local_64.right = local_c.cx + local_64.left + 6;
    local_64.top = ((local_50.bottom - local_50.top) / 2 - local_c.cy / 2) + -3;
    local_64.bottom = local_c.cy + local_64.top + 6;
    DrawFocusRect(hdc,&local_64);
  }
  return;
}



/*
 * Decompiled function: FUN_004f54d5
 * Entry Point: 004f54d5
 * Size: 567 bytes
 */


void FUN_004f54d5(int hDIBSection,HANDLE card_slot,HANDLE arg_3,HANDLE arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  size_t c;
  tagSIZE *psizl;
  RECT local_f8;
  HGDIOBJ local_e8;
  tagRECT local_e4;
  CHAR local_d4 [200];
  tagSIZE local_c;
  
  hdc = *(HDC *)(hDIBSection + 0x18);
  CopyRect(&local_e4,(RECT *)(hDIBSection + 0x1c));
  GetWindowTextA(*(HWND *)(hDIBSection + 0x14),local_d4,200);
  GDI_RealizeAndFlushPalette_Magic(hdc);
  OffsetRect(&local_e4,-*(int *)(hDIBSection + 0x1c),-*(int *)(hDIBSection + 0x20));
  if ((*(byte *)(hDIBSection + 0x10) & 1) == 0) {
    if (((*(byte *)(hDIBSection + 0x10) & 4) == 0) && ((*(byte *)(hDIBSection + 0x10) & 2) == 0)) {
      FUN_004f3b5f((int)hdc,(int)&local_e4,card_slot);
    }
    else {
      FUN_004f3b5f((int)hdc,(int)&local_e4,arg_4);
    }
  }
  else {
    FUN_004f3b5f((int)hdc,(int)&local_e4,arg_3);
    OffsetRect(&local_e4,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  local_e8 = (HGDIOBJ)SendMessageA(*(HWND *)(hDIBSection + 0x14),0x31,0,0);
  SelectObject(hdc,local_e8);
  DrawTextA(hdc,local_d4,-1,&local_e4,0x25);
  if ((arg_6 != 0) && ((*(byte *)(hDIBSection + 0x10) & 0x10) != 0)) {
    psizl = &local_c;
    c = strlen(local_d4);
    GetTextExtentPoint32A(hdc,local_d4,c,psizl);
    local_f8.left = ((local_e4.right - local_e4.left) / 2 - local_c.cx / 2) + -3;
    local_f8.right = local_c.cx + local_f8.left + 6;
    local_f8.top = ((local_e4.bottom - local_e4.top) / 2 - local_c.cy / 2) + -3;
    local_f8.bottom = local_c.cy + local_f8.top + 6;
    DrawFocusRect(hdc,&local_f8);
  }
  return;
}



/*
 * Decompiled function: FUN_004f570c
 * Entry Point: 004f570c
 * Size: 28 bytes
 */


void FUN_004f570c(HWND hwnd)

{
  EnumChildWindows(hwnd,FUN_004f5728,0);
  return;
}



/*
 * Decompiled function: FUN_004f5728
 * Entry Point: 004f5728
 * Size: 65 bytes
 */


undefined4 FUN_004f5728(HWND hwnd)

{
  int iVar1;
  
  iVar1 = FUN_004f589e(hwnd);
  if (iVar1 != 0) {
    DAT_0063eedc = SetWindowLongA(hwnd,-4,0x4f5769);
  }
  return 1;
}



/*
 * Decompiled function: FUN_004f5769
 * Entry Point: 004f5769
 * Size: 309 bytes
 */


LRESULT FUN_004f5769(HWND hwnd,UINT y,HWND param_3,LPARAM arg_4)

{
  int iVar1;
  HWND hWnd;
  UINT Msg;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((y == 7) || (y == 8)) {
    if (y == 7) {
      local_c = hwnd;
      local_10 = param_3;
    }
    else {
      local_10 = hwnd;
      local_c = param_3;
    }
    iVar1 = FUN_004f589e(local_c);
    if (iVar1 == 0) {
      local_c = (HWND)0x0;
    }
    iVar1 = FUN_004f589e(local_10);
    if (iVar1 == 0) {
      local_10 = (HWND)0x0;
    }
    Msg = 0x4c8;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,(WPARAM)local_c,(LPARAM)local_10);
    local_8 = 0;
  }
  else if ((y == 0x311) || ((y == 0x310 || (y == 0x30f)))) {
    local_8 = CallWindowProcA(DAT_0063eedc,hwnd,y,(WPARAM)param_3,arg_4);
    GDI_RealizePaletteTree_Magic(hwnd,y,param_3,arg_4);
  }
  else {
    local_8 = CallWindowProcA(DAT_0063eedc,hwnd,y,(WPARAM)param_3,arg_4);
  }
  return local_8;
}



/*
 * Decompiled function: FUN_004f589e
 * Entry Point: 004f589e
 * Size: 72 bytes
 */


bool FUN_004f589e(HWND hwnd)

{
  int iVar1;
  CHAR local_68 [100];
  
  GetClassNameA(hwnd,local_68,100);
  iVar1 = strcmp(local_68,s_Button_0053025c);
  return iVar1 == 0;
}



/*
 * Decompiled function: FUN_004f58eb
 * Entry Point: 004f58eb
 * Size: 268 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004f58eb(char *str_1,int arg2)

{
  char local_6c [100];
  UINT local_8;
  
  memcpy(&DAT_0061d7f8,&DAT_00530188,0x3c);
  strcpy(local_6c,&DAT_00530264);
  strcat(local_6c,str_1);
  _DAT_0061d7f8 = GetPrivateProfileIntA(s_Fonts_0053026c,local_6c,0x14,&DAT_006ff570);
  strcpy(local_6c,&DAT_00530274);
  strcat(local_6c,str_1);
  local_8 = GetPrivateProfileIntA(s_Fonts_0053027c,local_6c,0,&DAT_006ff570);
  if (local_8 != 0) {
    _DAT_0061d808 = 700;
  }
  if (arg2 != 0) {
    DAT_0061d80c = 1;
  }
  strcpy(local_6c,&DAT_00530284);
  strcat(local_6c,str_1);
  GetPrivateProfileStringA
            (s_Fonts_0053029c,local_6c,s_MS_Sans_Serif_0053028c,&DAT_0061d814,0x20,&DAT_006ff570);
  return &DAT_0061d7f8;
}



/*
 * Decompiled function: FUN_004f59f7
 * Entry Point: 004f59f7
 * Size: 383 bytes
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_004f59f7(void)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  int local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = DAT_00695ea0;
  local_c = DAT_007006b0;
  local_10 = DAT_006fe3fc;
  local_14 = DAT_006b3064;
  local_18 = DAT_006b2e24;
  local_1c = DAT_0069e720;
  local_20 = DAT_006fe400;
  bVar1 = false;
  local_2c = g_MainAppHwnd;
  local_34 = -1;
  while (local_2c != (HWND)0x0) {
    local_2c = GetWindow(local_2c,3);
    local_30 = 0;
    local_28 = -1;
    while ((local_30 < 7 && (local_28 == -1))) {
      if ((HWND)(&local_20)[local_30] == local_2c) {
        local_28 = local_30;
      }
      local_30 = local_30 + 1;
    }
    if ((local_28 != -1) && (BVar2 = IsWindowVisible(local_2c), BVar2 != 0)) {
      if (local_28 < local_34) {
        bVar1 = true;
      }
      local_34 = local_28;
    }
  }
  if ((bVar1) && (iVar3 = FUN_004f5b76((int)&local_20,7), iVar3 != -1)) {
    SetWindowPos((HWND)(&local_20)[iVar3],(HWND)0x1,0,0,0,0,3);
    if (iVar3 + 1 < 7) {
      local_3c = (int)&local_1c + iVar3 * 4;
    }
    else {
      local_3c = 0;
    }
    FUN_004f5bf9((HWND)(&local_20)[iVar3],local_3c,7 - (iVar3 + 1));
  }
  return;
}



/*
 * Decompiled function: FUN_004f5b76
 * Entry Point: 004f5b76
 * Size: 131 bytes
 */


int FUN_004f5b76(int arg1,int arg2)

{
  BOOL BVar1;
  int local_c;
  int local_8;
  
  local_8 = -1;
  if ((arg1 == 0) || (arg2 == 0)) {
    local_8 = -1;
  }
  else {
    local_c = 0;
    while ((local_c < arg2 && (local_8 == -1))) {
      BVar1 = IsWindowVisible(*(HWND *)(arg1 + local_c * 4));
      if (BVar1 != 0) {
        local_8 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}



/*
 * Decompiled function: FUN_004f5bf9
 * Entry Point: 004f5bf9
 * Size: 190 bytes
 */


undefined4 FUN_004f5bf9(HWND hwnd,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  
  if ((card_slot == 0) || (arg_3 < 1)) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_004f5b76(card_slot,arg_3);
    if (iVar2 == -1) {
      uVar1 = 0;
    }
    else {
      SetWindowPos(*(HWND *)(card_slot + iVar2 * 4),hwnd,0,0,0,0,3);
      if (iVar2 + 1 < arg_3) {
        local_c = iVar2 * 4 + 4 + card_slot;
      }
      else {
        local_c = 0;
      }
      FUN_004f5bf9(*(HWND *)(card_slot + iVar2 * 4),local_c,arg_3 - (iVar2 + 1));
      uVar1 = 1;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f5cbc
 * Entry Point: 004f5cbc
 * Size: 94 bytes
 */


uint FUN_004f5cbc(int hDIBSection)

{
  return CONCAT12((&DAT_006a4b70)[hDIBSection * 4],
                  CONCAT11((&DAT_006a4b71)[hDIBSection * 4],(&DAT_006a4b72)[hDIBSection * 4])) | 0x2000000;
}



/*
 * Decompiled function: GDI_RealizePaletteTree_Magic
 * Entry Point: 004f5d1a
 * Size: 421 bytes
 */


undefined4 GDI_RealizePaletteTree_Magic(HWND hwnd,uint y,HWND param_3,undefined4 arg_4)

{
  uint uVar1;
  UINT UVar2;
  HDC hdc;
  undefined4 uVar3;
  HWND local_38;
  uint local_34;
  HWND local_30;
  undefined4 local_2c;
  DWORD local_1c;
  HDC local_18;
  DWORD local_14;
  DWORD local_10;
  HWND local_c;
  DWORD local_8;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_00680774);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_00680774,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uVar3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar3 = 0;
  }
  else {
    local_c = param_3;
    if (hwnd != param_3) {
      local_14 = GetWindowThreadProcessId(param_3,&local_8);
      local_1c = GetWindowThreadProcessId(hwnd,&local_10);
      if (local_10 == local_8) {
        uVar1 = GetWindowLongA(hwnd,-0x10);
        if ((uVar1 & 0x40000000) == 0) {
          local_18 = GetDC(hwnd);
          SelectPalette(local_18,DAT_00680774,1);
          UVar2 = RealizePalette(local_18);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,local_18);
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
    }
    if (y == 0x311) {
      local_38 = hwnd;
      local_34 = y;
      local_30 = param_3;
      local_2c = arg_4;
      EnumChildWindows(hwnd,FUN_004f5ec4,(LPARAM)&local_38);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: FUN_004f5ec4
 * Entry Point: 004f5ec4
 * Size: 84 bytes
 */


undefined4 FUN_004f5ec4(HWND hwnd,int *arg2)

{
  HWND pHVar1;
  
  pHVar1 = GetParent(hwnd);
  if (pHVar1 == (HWND)*arg2) {
    SendMessageA(hwnd,arg2[1],arg2[2],arg2[3]);
  }
  return 1;
}



/*
 * Decompiled function: FUN_004f5f20
 * Entry Point: 004f5f20
 * Size: 305 bytes
 */


uint FUN_004f5f20(int hDIBSection,int card_slot,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_10;
  
  if (hDIBSection == 0) {
    local_10 = 0;
  }
  else if ((((card_slot == 0x20) || (card_slot == 0x18)) || (card_slot == 0x10)) || (card_slot == 8)) {
    iVar1 = (int)(card_slot + (card_slot >> 0x1f & 7U)) >> 3;
    uVar3 = arg_3 * iVar1 >> 0x1f;
    uVar3 = 4 - (((arg_3 * iVar1 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3);
    uVar4 = (int)uVar3 >> 0x1f;
    puVar2 = (uint *)((arg_3 * iVar1 + (((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4)) * arg_5 +
                      arg_4 * iVar1 + hDIBSection);
    if (card_slot == 0x20) {
      local_10 = *puVar2;
    }
    else if (card_slot == 0x18) {
      local_10 = (uint)(byte)*puVar2 << 0x10 | (uint)*(byte *)((int)puVar2 + 1) << 8 |
                 (uint)*(byte *)((int)puVar2 + 2);
    }
    else if (card_slot == 0x10) {
      local_10 = (uint)CONCAT11((byte)*puVar2,*(byte *)((int)puVar2 + 1));
    }
    else if (card_slot == 8) {
      local_10 = (uint)(byte)*puVar2;
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/*
 * Decompiled function: FUN_004f6060
 * Entry Point: 004f6060
 * Size: 278 bytes
 */


void FUN_004f6060(int hDIBSection,int card_slot,int arg_3,int arg_4,int arg_5,undefined4 arg_6)

{
  undefined1 uVar3;
  int iVar1;
  undefined4 *puVar2;
  uint uVar4;
  uint uVar5;
  
  if ((hDIBSection != 0) && ((((card_slot == 0x20 || (card_slot == 0x18)) || (card_slot == 0x10)) || (card_slot == 8)))) {
    iVar1 = (int)(card_slot + (card_slot >> 0x1f & 7U)) >> 3;
    uVar4 = arg_3 * iVar1 >> 0x1f;
    uVar4 = 4 - (((arg_3 * iVar1 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4);
    uVar5 = (int)uVar4 >> 0x1f;
    puVar2 = (undefined4 *)
             ((arg_3 * iVar1 + (((uVar4 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5)) * arg_5 +
              arg_4 * iVar1 + hDIBSection);
    if (card_slot == 0x20) {
      *puVar2 = arg_6;
    }
    else {
      uVar3 = (undefined1)((uint)arg_6 >> 8);
      if (card_slot == 0x18) {
        *(char *)puVar2 = (char)((uint)arg_6 >> 0x10);
        *(undefined1 *)((int)puVar2 + 1) = uVar3;
        *(undefined1 *)((int)puVar2 + 2) = (undefined1)arg_6;
      }
      else if (card_slot == 0x10) {
        *(undefined1 *)puVar2 = uVar3;
        *(undefined1 *)((int)puVar2 + 1) = (undefined1)arg_6;
      }
      else if (card_slot == 8) {
        *(undefined1 *)puVar2 = (undefined1)arg_6;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004f6180
 * Entry Point: 004f6180
 * Size: 2434 bytes
 */


int FUN_004f6180(char *str_1)

{
  char *pcVar1;
  int iVar2;
  int local_414;
  int local_410;
  int local_40c;
  char local_408 [1000];
  char *local_20;
  int local_1c;
  int local_18;
  int local_14;
  size_t local_10;
  int local_c;
  FILE *local_8;
  
  local_8 = fopen(str_1,&DAT_005302a4);
  if (local_8 == (FILE *)0x0) {
    iVar2 = 0;
  }
  else {
    fread(&DAT_006a49f4,4,1,local_8);
    fread(&local_10,4,1,local_8);
    DAT_00695e9c = (int)malloc(local_10);
    if ((void *)DAT_00695e9c == (void *)0x0) {
      fclose(local_8);
      iVar2 = 0;
    }
    else {
      fread(&DAT_006b3070,0x98,DAT_006a49f4,local_8);
      fread((void *)DAT_00695e9c,1,local_10,local_8);
      fclose(local_8);
      for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
        *(int *)(&DAT_006b3074 + local_c * 0x98) =
             *(int *)(&DAT_006b3074 + local_c * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b3078 + local_c * 0x98) =
             *(int *)(&DAT_006b3078 + local_c * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b30e4 + local_c * 0x98) =
             *(int *)(&DAT_006b30e4 + local_c * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b30e8 + local_c * 0x98) =
             *(int *)(&DAT_006b30e8 + local_c * 0x98) + DAT_00695e9c;
        iVar2 = _strcmpi(*(char **)(&DAT_006b30e4 + local_c * 0x98),&DAT_005302a8);
        if (iVar2 == 0) {
          *(undefined **)(&DAT_006b30e4 + local_c * 0x98) = &DAT_005302b0;
        }
        iVar2 = _strcmpi(*(char **)(&DAT_006b30e8 + local_c * 0x98),&DAT_005302b4);
        if ((iVar2 == 0) ||
           (iVar2 = _strcmpi(*(char **)(&DAT_006b30e8 + local_c * 0x98),s_Blank_005302bc),
           iVar2 == 0)) {
          *(undefined **)(&DAT_006b30e8 + local_c * 0x98) = &DAT_005302c4;
        }
        *(undefined **)(&DAT_006b30b0 + local_c * 0x98) =
             (&PTR_DAT_005290b0)[*(int *)(&DAT_006b30b0 + local_c * 0x98)];
        if (*(int *)(&DAT_006b30b4 + local_c * 0x98) == 0) {
          *(undefined4 *)(&DAT_006b30b4 + local_c * 0x98) = 1;
        }
        for (local_14 = 0; local_14 < *(int *)(&DAT_006b30b4 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(int *)(&DAT_006b30bc + local_14 * 4 + local_c * 0x98) =
               *(int *)(&DAT_006b30bc + local_14 * 4 + local_c * 0x98) + DAT_00695e9c;
        }
        *(undefined4 *)(&DAT_006b30b8 + local_c * 0x98) = 0;
        for (local_14 = 0; local_14 < *(int *)(&DAT_006b30b4 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_006b30d0 + local_14 * 4 + local_c * 0x98) = 0;
        }
      }
      for (local_18 = 0; local_18 < DAT_006a49f4; local_18 = local_18 + 1) {
        if (((&DAT_006b307c)[local_18 * 0x98] & 0x40) != 0) {
          *(undefined4 *)(&DAT_006b307c + local_18 * 0x98) = 0x80;
        }
      }
      for (local_1c = 0; local_1c < DAT_006a49f4; local_1c = local_1c + 1) {
        if ((&DAT_006b3098)[local_1c * 0x98] == '\x11') {
          (&DAT_006b3098)[local_1c * 0x98] = 10;
        }
      }
      for (local_40c = 0; local_40c < DAT_006a49f4; local_40c = local_40c + 1) {
        local_410 = 0;
        for (local_20 = *(char **)(&DAT_006b30e4 + local_40c * 0x98); *local_20 != '\0';
            local_20 = local_20 + 1) {
          if (*local_20 == '|') {
            pcVar1 = local_20 + 1;
            if (*pcVar1 == 'T') {
              local_20 = pcVar1;
              local_408[local_410] = -0x12;
            }
            else if (*pcVar1 == 'B') {
              local_20 = pcVar1;
              local_408[local_410] = -2;
            }
            else if (*pcVar1 == 'U') {
              local_20 = pcVar1;
              local_408[local_410] = -3;
            }
            else if (*pcVar1 == 'W') {
              local_20 = pcVar1;
              local_408[local_410] = -5;
            }
            else if (*pcVar1 == 'G') {
              local_20 = pcVar1;
              local_408[local_410] = -1;
            }
            else if (*pcVar1 == 'R') {
              local_20 = pcVar1;
              local_408[local_410] = -4;
            }
            else if (*pcVar1 == 'X') {
              local_20 = pcVar1;
              local_408[local_410] = -0x10;
            }
            else if ((*pcVar1 == '1') && (local_20[2] == '0')) {
              local_20 = local_20 + 2;
              local_408[local_410] = -0x11;
            }
            else if ((*pcVar1 < '0') || ('9' < *pcVar1)) {
              local_20 = pcVar1;
              local_408[local_410] = '|';
              local_20 = local_20 + -1;
            }
            else {
              local_20 = pcVar1;
              local_408[local_410] = *pcVar1 + -0x3f;
            }
          }
          else if (((*local_20 == '\\') && (local_20[1] == '\\')) ||
                  ((*local_20 == '\\' && (local_20[1] == 'n')))) {
            local_20 = local_20 + 1;
            local_408[local_410] = '\n';
          }
          else {
            local_408[local_410] = *local_20;
          }
          local_410 = local_410 + 1;
        }
        local_408[local_410] = '\0';
        strcpy(*(char **)(&DAT_006b30e4 + local_40c * 0x98),local_408);
      }
      for (local_414 = 0; iVar2 = DAT_006a49f4, local_414 < DAT_006a49f4; local_414 = local_414 + 1)
      {
        *(undefined4 *)(&DAT_006b30cc + local_414 * 0x98) = 0;
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_black_005302c8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 2;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),&DAT_005302d0,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 4;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_green_005302d8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 8;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),&DAT_005302e0,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 0x10;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_white_005302e4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 0x20;
        }
        *(undefined4 *)(&DAT_006b3104 + local_414 * 0x98) = 0;
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_swamp_005302ec,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 2;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_island_005302f4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 4;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_forest_005302fc,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 8;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_mountain_00530304,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 0x10;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_plains_00530310,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return iVar2;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f6b02
 * Entry Point: 004f6b02
 * Size: 49 bytes
 */


void Mem_AllocOrFree_004f6b02(void)

{
  if (DAT_00695e9c != 0) {
    free((void *)DAT_00695e9c);
  }
  DAT_00695e9c = 0;
  return;
}



/*
 * Decompiled function: FUN_004f6b33
 * Entry Point: 004f6b33
 * Size: 597 bytes
 */


undefined4 FUN_004f6b33(LPCSTR str_1)

{
  char *pcVar1;
  undefined1 local_20 [4];
  HANDLE local_1c;
  undefined4 local_18;
  DWORD local_14;
  DWORD local_10;
  int local_c;
  char *local_8;
  
  local_18 = 0;
  for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
    *(undefined **)(&DAT_006809e0 + local_c * 0x14) = &DAT_00530318;
    *(undefined **)(&DAT_006809e4 + local_c * 0x14) = &DAT_0053031c;
    *(undefined **)(&DAT_006809e8 + local_c * 0x14) = &DAT_00530320;
    *(undefined **)(&DAT_006809ec + local_c * 0x14) = &DAT_00530324;
    *(undefined **)(&DAT_006809f0 + local_c * 0x14) = &DAT_00530328;
  }
  local_1c = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (local_1c != (HANDLE)0xffffffff) {
    local_10 = GetFileSize(local_1c,(LPDWORD)0x0);
    DAT_0068a720 = malloc(local_10 + 1);
    if (DAT_0068a720 != (void *)0x0) {
      ReadFile(local_1c,DAT_0068a720,local_10,&local_14,(LPOVERLAPPED)0x0);
      local_8 = DAT_0068a720;
      pcVar1 = strchr(DAT_0068a720,10);
      local_8 = pcVar1 + 1;
      for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
        sscanf(local_8,&DAT_0053032c,local_20);
        local_8 = (char *)FUN_004f6db9(&local_8);
        local_8 = (char *)FUN_004f6db9(&local_8);
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809e0 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809e4 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809e8 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809ec + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809f0 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
      }
      local_18 = 1;
    }
    CloseHandle(local_1c);
  }
  return local_18;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f6d88
 * Entry Point: 004f6d88
 * Size: 49 bytes
 */


void Mem_AllocOrFree_004f6d88(void)

{
  if (DAT_0068a720 != 0) {
    free((void *)DAT_0068a720);
  }
  DAT_0068a720 = 0;
  return;
}



/*
 * Decompiled function: FUN_004f6db9
 * Entry Point: 004f6db9
 * Size: 205 bytes
 */


char * FUN_004f6db9(undefined4 *hDIBSection)

{
  char *pcVar1;
  char *local_14;
  char *local_8;
  
  local_8 = (char *)*hDIBSection;
  if (*local_8 == '\"') {
    local_8 = local_8 + 1;
    local_14 = strchr(local_8,0x22);
    *local_14 = '\0';
    if (local_14[1] == ',') {
      local_14 = local_14 + 2;
    }
    else {
      local_14 = local_14 + 3;
    }
  }
  else {
    local_14 = strchr(local_8,0x2c);
    pcVar1 = strchr(local_8,0xd);
    if (local_14 < pcVar1) {
      *local_14 = '\0';
      local_14 = local_14 + 1;
    }
    else {
      *pcVar1 = '\0';
      local_14 = pcVar1 + 2;
    }
  }
  *hDIBSection = local_8;
  return local_14;
}



/*
 * Decompiled function: FUN_004f6e90
 * Entry Point: 004f6e90
 * Size: 701 bytes
 */


undefined4 FUN_004f6e90(int hDIBSection,int card_slot,int arg_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int height;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      local_18 = 0;
      do {
        local_18 = local_18 + 1;
        if (999 < local_18) {
          local_8 = -1;
          break;
        }
        local_14 = Math_RandomRange(2);
        local_8 = Math_RandomRange(500);
        local_10 = *(int *)(&DAT_006ff710 + local_8 * 4 + local_14 * 2000);
      } while ((local_10 == -1) || (((&g_MasterCardColorTable)[local_10 * 0x34] & 2) == 0));
      if (local_8 == -1) {
        local_1c = 0;
        while ((local_1c < 2 && (local_8 == -1))) {
          local_18 = 0;
          while (((local_18 < 500 &&
                  (*(int *)(&DAT_006ff710 + local_18 * 4 + local_1c * 2000) != -1)) &&
                 (local_8 == -1))) {
            local_10 = *(int *)(&DAT_006ff710 + local_18 * 4 + local_1c * 2000);
            if (((&g_MasterCardColorTable)[local_10 * 0x34] & 2) != 0) {
              local_8 = local_18;
              local_14 = local_1c;
            }
            local_18 = local_18 + 1;
          }
          local_1c = local_1c + 1;
        }
      }
      if ((local_8 != -1) && (*(int *)(&DAT_006ff710 + local_8 * 4 + local_14 * 2000) != -1)) {
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x23);
        }
        iVar3 = Pic_Subsystem_00451291
                          (hDIBSection,*(int *)(&DAT_006ff710 + local_8 * 4 + local_14 * 2000));
        if (local_14 == 0) {
          *(undefined4 *)(&g_CardSlot_Flags + iVar3 * 0x120 + hDIBSection * 0x5b20) = 0;
        }
        else {
          *(undefined4 *)(&g_CardSlot_Flags + iVar3 * 0x120 + hDIBSection * 0x5b20) = 0x1000;
        }
        if (iVar3 != -1) {
          Pic_Subsystem_00449223(local_14,local_8);
          Pic_Subsystem_0042ac1f(hDIBSection,iVar3);
          cVar1 = (&DAT_0051aebf)[local_10 * 0x34];
          iVar3 = hDIBSection;
          height = card_slot;
          iVar4 = Math_Clamp((int)(char)(&DAT_0051aec0)[local_10 * 0x34],0,99);
          Mem_AllocOrFree_0041df33(hDIBSection,cVar1 + iVar4,iVar3,height);
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004f714d
 * Entry Point: 004f714d
 * Size: 355 bytes
 */


undefined4 FUN_004f714d(int hDIBSection,int card_slot,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x60;
    }
    if (arg_3 == 0x71) {
      if (DAT_006ff2d8 == -1) {
        bVar1 = false;
        local_c = 0;
        while ((local_c < 2 && (!bVar1))) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c];
              local_8 = local_8 + 1) {
            if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) == DAT_006a4b64)
               && (((&DAT_006a5f69)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              bVar1 = true;
            }
          }
          local_c = local_c + 1;
        }
        if (!bVar1) {
          DAT_006ff2d8 = hDIBSection;
        }
      }
      iVar3 = Card_ApplyTriggerEffect(hDIBSection,card_slot,DAT_006a4b64,-1,-1);
      *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + hDIBSection * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + hDIBSection * 0x5b20) | 0x120;
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Prompts_Load_004f72b0
 * Entry Point: 004f72b0
 * Size: 936 bytes
 */


undefined4 Prompts_Load_004f72b0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_110;
  int local_108;
  char local_104 [252];
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (flags == 0x71) {
      Pic_Subsystem_00424500(s_prompts_txt_00530338,s_BALANCE_00530330);
      strcpy(local_104,&g_OverworldGoldAmount);
      do {
        strcpy(&g_OverworldGoldAmount,local_104);
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            iVar2 = g_PlayerActiveCardCount;
          }
          if (iVar2 <= local_8) break;
          iVar2 = Card_IsTapped(0, local_8);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + local_8 * 0x120) * 0x34] & 1)
              != 0)) {
            local_108 = local_108 + 1;
          }
          iVar2 = Card_IsTapped(1,local_8);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + local_8 * 0x120) * 0x34] & 1) != 0
             )) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        if (local_110 < local_108) {
          Glue_Subsystem_004e701f(0);
        }
        else if (local_108 < local_110) {
          Glue_Subsystem_004e701f(1);
        }
        Ai_Subsystem_004cc9c5(0,0xff);
      } while (local_110 != local_108);
      do {
        if (DAT_006b300c < DAT_006b3008) {
          Prompts_Load_0046fa40(0,0,0);
        }
        if (DAT_006b3008 < DAT_006b300c) {
          Prompts_Load_0046fa40(1,0,0);
        }
      } while (DAT_006b3008 != DAT_006b300c);
      do {
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            iVar2 = g_PlayerActiveCardCount;
          }
          if (iVar2 <= local_8) break;
          iVar2 = Card_IsTapped(0, local_8);
          if (((iVar2 != 0) &&
              (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + local_8 * 0x120) * 0x34] & 2
               ) != 0)) && ((&DAT_006a5f50)[local_8 * 0x120] != '\x03')) {
            local_108 = local_108 + 1;
          }
          iVar2 = Card_IsTapped(1,local_8);
          if (((iVar2 != 0) &&
              (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + local_8 * 0x120) * 0x34] & 2) !=
               0)) && ((&DAT_006a5f50)[local_8 * 0x120] != '\x03')) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        strcpy(&g_OverworldGoldAmount,&DAT_0069f84a);
        if (local_110 < local_108) {
          iVar2 = Glue_Subsystem_004e6bff(0);
          Pic_Subsystem_0044867e(0,iVar2,3);
        }
        if (local_108 < local_110) {
          iVar2 = Glue_Subsystem_004e6bff(1);
          Pic_Subsystem_0044867e(1,iVar2,3);
        }
        Ai_Subsystem_004cc9c5(0,0xff);
      } while (local_110 != local_108);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004f7658
 * Entry Point: 004f7658
 * Size: 529 bytes
 */


undefined4 Prompts_Load_004f7658(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((spell_id == g_ActivePlayerPriority) && (iVar1 = Font_DrawString(spell_id, 7, 3), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530350,s_BRAINGEYSER_00530344);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&local_14);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_14;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_10
        ;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      for (local_c = 0;
          local_c < *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120);
          local_c = local_c + 1) {
        Magic_ExecuteDrawPhase(local_8);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004f7869
 * Entry Point: 004f7869
 * Size: 529 bytes
 */


undefined4 FUN_004f7869(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth - ((&DAT_006b3008)[hDIBSection] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      local_1c = 0;
      local_14 = g_DefendingPlayer;
      while (local_1c < 2) {
        local_20 = 0;
        for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_14]; local_8 = local_8 + 1
            ) {
          iVar2 = FUN_00471bc0(local_14,local_8);
          if (iVar2 != 0) {
            local_20 = local_20 + 1;
          }
        }
        for (local_18 = 0; local_18 < local_20; local_18 = local_18 + 1) {
          Prompts_Load_0046fa40(local_14,1,0);
        }
        local_1c = local_1c + 1;
        if (g_DefendingPlayer == 0) {
          local_14 = local_14 + 1;
        }
        else {
          local_14 = local_14 + -1;
        }
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      local_10 = 0;
      local_c = 0;
      for (local_18 = 0; local_18 < 500; local_18 = local_18 + 1) {
        if (*(int *)(&DAT_0069e730 + local_18 * 4) != -1) {
          local_c = local_c + 1;
        }
        if (*(int *)(&DAT_0069ef00 + local_18 * 4) != -1) {
          local_10 = local_10 + 1;
        }
      }
      if ((local_c < 7) && (local_10 < 7)) {
        if (g_IsAiThinking == 1) {
          g_PlayerCreatureCount = 0;
          DAT_006a4a04 = 0;
        }
        else {
          Ai_Util_004cc42d(s_Neither_player_has_enough_librar_0053035c);
          Sleep(0x9c4);
          Ai_Util_004cc42d(&DAT_005303a0);
          Pic_Util_00450975(2);
        }
      }
      else {
        FUN_004f823a(0,7);
        FUN_004f823a(1,7);
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f7a7a
 * Entry Point: 004f7a7a
 * Size: 380 bytes
 */


undefined4 FUN_004f7a7a(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (hDIBSection == g_EventSourcePlayer)) {
      if ((hDIBSection == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        Ai_Subsystem_004cd198();
        iVar2 = Ai_Subsystem_004cc814
                          (hDIBSection,s_Darkpact__Swap_ante_005303cc,0,s_Swap_my_ante_005303bc,
                           s_Swap_opponent_s_ante_005303a4,(char *)0x0);
        if (iVar2 == 0) {
          local_c = hDIBSection;
        }
        else {
          local_c = 1 - hDIBSection;
        }
      }
      else {
        local_c = hDIBSection;
      }
      *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) = local_c;
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&DAT_0069e730 + hDIBSection * 2000) != -1) {
        uVar1 = (&DAT_006b2d90)
                [*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) * 0x10];
        (&DAT_006b2d90)
        [*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) * 0x10] =
             *(undefined4 *)(&DAT_0069e730 + hDIBSection * 2000);
        *(undefined4 *)(&DAT_0069e730 + hDIBSection * 2000) = uVar1;
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f7bf6
 * Entry Point: 004f7bf6
 * Size: 283 bytes
 */


undefined4 FUN_004f7bf6(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
      while ((&DAT_006b3008)[hDIBSection] != 0) {
        Prompts_Load_0046fa40(hDIBSection,1,0);
      }
      for (local_c = 0; ((&DAT_006b2d90)[hDIBSection * 0x10 + local_c] != -1 && (local_c < 0x10));
          local_c = local_c + 1) {
      }
      if (local_c < 0x10) {
        iVar2 = Magic_ExecuteDrawPhase(hDIBSection);
        (&DAT_006b2d90)[hDIBSection * 0x10 + local_c] =
             *(undefined4 *)(&g_CardSlot_CardId + iVar2 * 0x120 + hDIBSection * 0x5b20);
        *(undefined4 *)(&g_CardSlot_CardId + iVar2 * 0x120 + hDIBSection * 0x5b20) = 0xffffffff;
      }
      FUN_004f823a(hDIBSection,7);
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f7d11
 * Entry Point: 004f7d11
 * Size: 477 bytes
 */


undefined4 FUN_004f7d11(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int local_1c;
  int aiStack_14 [4];
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) = 0;
      for (aiStack_14[2] = 0; aiStack_14[2] < 2; aiStack_14[2] = aiStack_14[2] + 1) {
        if (*(int *)(&DAT_0069e730 + aiStack_14[2] * 2000) == -1) {
          aiStack_14[aiStack_14[2]] = 0;
        }
        else {
          aiStack_14[3] =
               Ai_Subsystem_004cc56d
                         (aiStack_14[2],hDIBSection,card_slot,-1,-1,
                          s_Ante_an_additional_card__No_addi_005303e0,
                          (uint)(0xf < (int)(&g_PlayerCreatureCount)[aiStack_14[2]]));
          if (aiStack_14[3] == 0) {
            aiStack_14[aiStack_14[2]] = 1;
          }
          else {
            aiStack_14[aiStack_14[2]] = 0;
          }
        }
      }
      for (aiStack_14[2] = 0; aiStack_14[2] < 2; aiStack_14[2] = aiStack_14[2] + 1) {
        if (aiStack_14[aiStack_14[2]] != 0) {
          (&g_PlayerCreatureCount)[aiStack_14[2]] = 0x14;
          for (local_1c = 0;
              ((&DAT_006b2d90)[aiStack_14[2] * 0x10 + local_1c] != -1 && (local_1c < 0x10));
              local_1c = local_1c + 1) {
          }
          if (local_1c < 0x10) {
            uVar1 = *(undefined4 *)(&DAT_0069e730 + aiStack_14[2] * 2000);
            Pic_Subsystem_004523fd(aiStack_14[2],0);
            (&DAT_006b2d90)[aiStack_14[2] * 0x10 + local_1c] = uVar1;
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f7eee
 * Entry Point: 004f7eee
 * Size: 323 bytes
 */


undefined4 FUN_004f7eee(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      local_10 = 0;
      local_8 = g_DefendingPlayer;
      while (local_10 < 2) {
        local_14 = 0;
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = FUN_00471bc0(local_8,local_c);
          if (iVar2 != 0) {
            Pic_Subsystem_0045245e
                      (local_8,*(undefined4 *)
                                (&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20));
            *(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
            local_14 = local_14 + 1;
          }
        }
        Ai_Subsystem_004cc9c5(0,0x30);
        Pic_Subsystem_00452276(local_8);
        FUN_004f823a(local_8,local_14);
        local_10 = local_10 + 1;
        if (g_DefendingPlayer == 0) {
          local_8 = local_8 + 1;
        }
        else {
          local_8 = local_8 + -1;
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f8031
 * Entry Point: 004f8031
 * Size: 521 bytes
 */


undefined4 FUN_004f8031(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth - ((&DAT_006b3008)[hDIBSection] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      local_10 = 0;
      local_8 = g_DefendingPlayer;
      while (local_10 < 2) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = FUN_00471bc0(local_8,local_c);
          if (iVar2 != 0) {
            Pic_Subsystem_0045245e
                      (local_8,*(undefined4 *)
                                (&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20));
            *(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
          }
        }
        local_c = 0;
        while ((local_c < 500 && (*(int *)(&DAT_006ff710 + local_c * 4 + local_8 * 2000) != -1))) {
          Pic_Subsystem_0045245e
                    (local_8,*(undefined4 *)(&DAT_006ff710 + local_c * 4 + local_8 * 2000));
          local_c = local_c + 1;
        }
        for (local_c = 0; local_c < 500; local_c = local_c + 1) {
          *(undefined4 *)(&DAT_006ff710 + local_c * 4 + local_8 * 2000) = 0xffffffff;
        }
        Ai_Subsystem_004cc9c5(0,0x30);
        Pic_Subsystem_00452276(local_8);
        FUN_004f823a(local_8,7);
        local_10 = local_10 + 1;
        if (g_DefendingPlayer == 0) {
          local_8 = local_8 + 1;
        }
        else {
          local_8 = local_8 + -1;
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f823a
 * Entry Point: 004f823a
 * Size: 91 bytes
 */


void FUN_004f823a(int arg1,int arg2)

{
  int local_8;
  
  for (local_8 = 0; local_8 < arg2; local_8 = local_8 + 1) {
    Magic_ExecuteDrawPhase(arg1);
    if (arg1 != 0) {
      DAT_00627a14 = 0;
    }
  }
  (&DAT_006b3008)[arg1] = arg2;
  return;
}



/*
 * Decompiled function: FUN_004f8295
 * Entry Point: 004f8295
 * Size: 140 bytes
 */


undefined4 FUN_004f8295(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  (&DAT_006a5f4c)[card_slot * 0x120 + hDIBSection * 0x5b20] = 1;
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      Card_ApplyTriggerEffect(hDIBSection,card_slot,DAT_006a2824,-1,-1);
      FUN_0040d7e9(hDIBSection,0,1);
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004f8321
 * Entry Point: 004f8321
 * Size: 849 bytes
 */


undefined4 Prompts_Load_004f8321(int spell_id,int target_id,int flags)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 1;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                         arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0053041c,s_ENERGYTAP_00530410);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar6 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,
                         uVar9,uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
      if (iVar6 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,2,
                         0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar6 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_00415d48(local_c,local_8);
        cVar1 = (&DAT_0051aebf)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34];
        iVar6 = Math_Clamp((int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 local_c * 0x5b20 + local_8 * 0x120) * 0x34],0,99);
        *(int *)(&DAT_0063ee90 + spell_id * 0x20) =
             *(int *)(&DAT_0063ee90 + spell_id * 0x20) + cVar1 + iVar6;
        cVar1 = (&DAT_0051aebf)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34];
        iVar6 = Math_Clamp((int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 local_c * 0x5b20 + local_8 * 0x120) * 0x34],0,99);
        *(int *)(&DAT_0063eeac + spell_id * 0x20) =
             *(int *)(&DAT_0063eeac + spell_id * 0x20) + cVar1 + iVar6;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Prompts_Load_004f8672
 * Entry Point: 004f8672
 * Size: 572 bytes
 */


undefined4 Prompts_Load_004f8672(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = Font_DrawString(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      iVar1 = (&g_PlayerCreatureCount)[spell_id];
      iVar3 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (iVar1 * 0x18) / iVar3;
      Pic_Subsystem_00424500(s_prompts_txt_00530438,s_STREAMOFLIFE_00530428);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      (&g_PlayerCreatureCount)
      [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)] =
           (&g_PlayerCreatureCount)
           [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)] +
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004f88ae
 * Entry Point: 004f88ae
 * Size: 237 bytes
 */


undefined4 FUN_004f88ae(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 4) != 0)
             ) {
            Pic_Subsystem_0044867e(local_8,local_c,2);
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004f899b
 * Entry Point: 004f899b
 * Size: 1852 bytes
 */


undefined4 Prompts_Load_004f899b(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 3;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,0,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((spell_id == g_ActivePlayerPriority) &&
       ((g_OverworldPlayerCoordY == 0 || (iVar2 = Font_DrawString(spell_id,7,4), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    iVar2 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                          spell_id * 0x5b20 + target_id * 0x120));
    g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)iVar2);
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    local_18 = 0;
    local_10 = 0;
    while (((local_18 < g_TurnCounter && (local_10 == 0)) && (g_ActivePlayer != 1))) {
      local_14 = Card_UntapCard(spell_id, target_id, 4);
      local_14 = local_14 + -1;
      Pic_Subsystem_00424500(s_prompts_txt_00530458,s_VOLCANIC_ERUPTION_00530444);
      sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_18 + 1,g_TurnCounter);
      if (local_14 == 4) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_0053046c,0,s_PLAINS_00530464);
      }
      else if (local_14 == 0) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_00530480,0,s_SWAMP_00530478);
      }
      else if (local_14 == 1) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_00530494,0,s_ISLAND_0053048c);
      }
      else if (local_14 == 2) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_005304a8,0,s_FOREST_005304a0);
      }
      arg_20 = &local_20;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      iVar2 = local_14;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        if (local_1c == -1) {
          g_ActivePlayer = 1;
        }
        else {
          local_10 = 1;
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_20 * 0x5b20 + local_1c * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_20 * 0x5b20 + local_1c * 0x120) | 0x300000;
        Ai_Subsystem_004cc9c5(0,0x20);
        *(int *)(&g_CardSlot_CombatTarget +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             local_20;
        *(int *)(&g_CardSlot_AttachedAura +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             local_1c;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
      }
      local_18 = local_18 + 1;
    }
    for (local_18 = 0;
        local_18 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        local_18 = local_18 + 1) {
      *(uint *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_CombatTarget +
                       spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x5b20 +
               *(int *)(&g_CardSlot_AttachedAura +
                       spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x120) =
           *(uint *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_CombatTarget +
                            spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x5b20 +
                    *(int *)(&g_CardSlot_AttachedAura +
                            spell_id * 0x5b20 + target_id * 0x120 + local_18 * 8) * 0x120) &
           0xffcfffff;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
  }
  if (flags == 0x71) {
    local_14 = Card_UntapCard(spell_id, target_id, 4);
    local_14 = local_14 + -1;
    local_8 = 0;
    for (local_18 = 0;
        local_18 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        local_18 = local_18 + 1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      iVar2 = local_14;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget +
                                 local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                         spell_id,2,2,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11);
      if (iVar2 == 0) {
        local_8 = local_8 + 1;
      }
      else {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget +
                           local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura +
                           local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),2);
      }
    }
    if ((char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] == local_8) {
      g_ActivePlayer = 1;
    }
    if ((g_ActivePlayer != 1) &&
       (local_c = Pic_Subsystem_00451291(spell_id,DAT_006ff564), local_c != -1)) {
      *(undefined4 *)(&g_ActiveCardsInPlay + local_c * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120);
      *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + spell_id * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + local_c * 0x120 + spell_id * 0x5b20) = 0x109;
      *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + spell_id * 0x5b20) =
           (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] - local_8;
      FUN_00476482(spell_id,local_c);
    }
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    Pic_Subsystem_0044867e(spell_id,target_id,1);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004f90d7
 * Entry Point: 004f90d7
 * Size: 540 bytes
 */


undefined4 FUN_004f90d7(int hDIBSection,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((hDIBSection == g_ActivePlayerPriority) && (iVar1 = Font_DrawString(hDIBSection,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (hDIBSection == g_EventSourcePlayer)) {
      iVar1 = FUN_004fa423(hDIBSection,*(int *)(&g_CardSlot_CardId + hDIBSection * 0x5b20 + card_slot * 0x120));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)iVar1);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + hDIBSection * 0x5b20 + card_slot * 0x120) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        Mem_AllocOrFree_0041df33
                  (local_8,*(int *)(&g_CardSlot_ConvertedManaCost + hDIBSection * 0x5b20 + card_slot * 0x120),
                   hDIBSection,card_slot);
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar1 = Card_IsTapped(local_8,local_c);
          if (((iVar1 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0
              )) && (uVar3 = Card_TapForMana(local_8, local_c, 0x34, 0xffffffff), (uVar3 & 0x20) == 0)) {
            Card_ApplyCombatDamage(local_8, local_c, *(int *)(&g_CardSlot_ConvertedManaCost + hDIBSection * 0x5b20 + card_slot * 0x120),
                         hDIBSection,card_slot);
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004f92f3
 * Entry Point: 004f92f3
 * Size: 541 bytes
 */


undefined4 FUN_004f92f3(int hDIBSection,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((hDIBSection == g_ActivePlayerPriority) && (iVar1 = Font_DrawString(hDIBSection,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (hDIBSection == g_EventSourcePlayer)) {
      iVar1 = FUN_004fa423(hDIBSection,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + hDIBSection * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)iVar1);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        Mem_AllocOrFree_0041df33
                  (local_8,*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20),
                   hDIBSection,card_slot);
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar1 = Card_IsTapped(local_8,local_c);
          if (((iVar1 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0
              )) && (uVar3 = Card_TapForMana(local_8, local_c, 0x34, 0xffffffff), (uVar3 & 0x20) != 0)) {
            Card_ApplyCombatDamage(local_8, local_c, *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20),
                         hDIBSection,card_slot);
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004f9510
 * Entry Point: 004f9510
 * Size: 237 bytes
 */


undefined4 FUN_004f9510(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 1) != 0)
             ) {
            Pic_Subsystem_0044867e(local_8,local_c,2);
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004f95fd
 * Entry Point: 004f95fd
 * Size: 314 bytes
 */


undefined4 FUN_004f95fd(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 1) != 0)
             ) {
            iVar2 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20);
            iVar3 = Card_UntapCard(hDIBSection,card_slot,2);
            if (*(int *)(&g_MasterCardTypeTable + iVar2 * 0x34) ==
                *(int *)(&DAT_006ff2bc + iVar3 * 4)) {
              Pic_Subsystem_0044867e(local_8,local_c,2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004f9737
 * Entry Point: 004f9737
 * Size: 1153 bytes
 */


undefined4 Prompts_Load_004f9737(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int *arg_20;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo(&local_10,0,spell_id,2,2,0x200,2,0x40,0,uVar1,arg_11,arg_12,arg_13,arg_14,arg_15,
                 arg_16,arg_17,arg_18_00,arg_19);
    if (local_10 < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      local_c = 0;
      while ((local_c < 2 && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_005304c4,s_ASHESTOASHES_005304b4);
        arg_20 = (int *)(&g_CardSlot_CombatTarget +
                        target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        uVar1 = 1;
        arg_18 = &g_OverworldGoldAmount + local_c * 0xfa;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
        iVar5 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,2,0x40,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                           uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar5 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) |
               0x300000;
          Ai_Subsystem_004cc9c5(0,0x20);
        }
        local_c = local_c + 1;
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 2;
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_c = local_c + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_c = local_c + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
        iVar5 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                           spell_id,2,2,0x200,2,0x40,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                           uVar9,uVar10,uVar11);
        if (iVar5 == 0) {
          local_8 = local_8 + 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget +
                             local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura +
                             local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),4);
        }
      }
      if (local_8 == 2) {
        g_ActivePlayer = 1;
      }
      else {
        Mem_AllocOrFree_0041df33(spell_id,5,spell_id,target_id);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004f9bbd
 * Entry Point: 004f9bbd
 * Size: 679 bytes
 */


undefined4 Prompts_Load_004f9bbd(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uVar1,arg_11,arg_12,arg_13,
                         arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      iVar2 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x30 / (longlong)iVar2);
      Pic_Subsystem_00424500(s_prompts_txt_005304e0,s_DESERT_TWISTER_005304d0);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,
                         uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,0x1047,0,0,uVar3,uVar4,uVar5
                         ,iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(local_c,local_8,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004f9e64
 * Entry Point: 004f9e64
 * Size: 1471 bytes
 */


undefined4 Prompts_Load_004f9e64(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,2,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((g_ActivePlayerPriority == spell_id) &&
       ((g_OverworldPlayerCoordY == 0 || (iVar2 = Font_DrawString(spell_id,7,2), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      local_c = 0;
      local_8 = 0;
      while (((local_c < g_TurnCounter && (local_8 == 0)) && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_005304fc,s_WINTER_BLAST_005304ec);
        sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_c + 1,g_TurnCounter);
        arg_20 = &local_14;
        uVar1 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar2 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar2 == 0) {
          if (local_10 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            local_8 = 1;
          }
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) | 0x300000;
          Ai_Subsystem_004cc9c5(0,0x20);
          *(int *)(&g_CardSlot_CombatTarget +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_14;
          *(int *)(&g_CardSlot_AttachedAura +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_10;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
               (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
        }
        local_c = local_c + 1;
      }
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar2 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
        iVar2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),(char *)0x0,
                           spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,
                           uVar10,uVar11);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_00415d48(*(int *)(&g_CardSlot_CombatTarget +
                               target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                       *(int *)(&g_CardSlot_AttachedAura +
                               target_id * 0x120 + spell_id * 0x5b20 + local_c * 8));
          uVar3 = Card_TapForMana(*(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                               *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),0x34,
                               0xffffffff);
          if ((uVar3 & 0x20) != 0) {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),2,spell_id,
                         target_id);
          }
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fa423
 * Entry Point: 004fa423
 * Size: 149 bytes
 */


int FUN_004fa423(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 1;
  for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_8 = local_8 + 1) {
    if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + arg1 * 0x5b20) == arg2) &&
       (((&g_CardSlot_Flags)[local_8 * 0x120 + arg1 * 0x5b20] & 2) == 0)) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}



/*
 * Decompiled function: FUN_004fa4b8
 * Entry Point: 004fa4b8
 * Size: 206 bytes
 */


int FUN_004fa4b8(int hDIBSection,int card_slot,int arg_3)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (hDIBSection = 0; hDIBSection < 2; hDIBSection = hDIBSection + 1) {
    if ((arg_3 == -1) || (arg_3 == hDIBSection)) {
      for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[hDIBSection]; local_8 = local_8 + 1) {
        if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + hDIBSection * 0x5b20) == card_slot) &&
           (((&g_CardSlot_Flags)[local_8 * 0x120 + hDIBSection * 0x5b20] & 2) != 0)) {
          local_c = local_c + 1;
        }
      }
    }
  }
  return local_c;
}



/*
 * Decompiled function: Prompts_Load_004fa586
 * Entry Point: 004fa586
 * Size: 3166 bytes
 */


undefined4 Prompts_Load_004fa586(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 arg_11;
  uint uVar4;
  undefined4 arg_12;
  uint uVar5;
  undefined4 arg_13;
  undefined4 arg_14;
  undefined4 arg_15;
  uint uVar6;
  undefined4 arg_16;
  uint uVar7;
  undefined4 arg_17;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 arg_18;
  uint uVar11;
  int arg_3;
  undefined4 arg_19;
  int *piVar12;
  uint uVar13;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      DAT_006fe3f4 = 1;
    }
    else {
      iVar1 = Font_DrawString(spell_id,7,2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      iVar1 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x48 / (longlong)iVar1);
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
          local_14 = Font_DrawString(spell_id,7,1);
          local_14 = local_14 + -1;
          arg_19 = 0;
          arg_18 = 0;
          arg_17 = 0;
          arg_16 = 0xffffffff;
          arg_15 = 0xffffffff;
          arg_14 = 0xffffffff;
          arg_13 = 0xffffffff;
          arg_12 = 0;
          arg_11 = 0;
          uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          UI_PaintBigCardInfo(&local_18,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,arg_15
                       ,arg_16,arg_17,arg_18,arg_19);
          local_18 = local_18 + 2;
          local_10 = local_14;
          local_c = 1;
          iVar1 = Ai_Subsystem_004b832d
                            (spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),local_14,
                             local_18,&local_10,&local_c,&local_1c);
          if (iVar1 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 local_1c;
            g_TurnCounter = 0;
            DAT_006b2d50 = 1;
            Ai_CalcManaRequirement_004ba890(spell_id,0,local_10);
            if (g_ActivePlayer != 1) {
              g_TurnCounter = local_10 - (local_c + -1);
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              local_20 = 0;
              while ((local_20 < local_c && (g_ActivePlayer != 1))) {
                Pic_Subsystem_00424500(s_prompts_txt_00530514,s_FIREBALL_00530508);
                sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_20 + 1,local_c);
                piVar12 = &local_28;
                uVar2 = 1;
                puVar8 = &g_OverworldGoldAmount;
                uVar13 = 0;
                uVar11 = 0;
                uVar9 = 0;
                uVar7 = 0xffffffff;
                uVar6 = 0xffffffff;
                iVar10 = -1;
                iVar1 = -1;
                uVar5 = 0;
                uVar4 = 0;
                uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
                iVar1 = Action_ValidateTarget_00405802
                                  (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,
                                   iVar10,uVar6,uVar7,uVar9,uVar11,uVar13,puVar8,uVar2,piVar12);
                if (iVar1 == 0) {
                  g_ActivePlayer = 1;
                }
                else {
                  *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                       *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) |
                       0x300000;
                  Ai_Subsystem_004cc9c5(0,0x20);
                  *(int *)(&g_CardSlot_CombatTarget +
                          target_id * 0x120 +
                          spell_id * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8)
                       = local_28;
                  *(int *)(&g_CardSlot_AttachedAura +
                          target_id * 0x120 +
                          spell_id * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8)
                       = local_24;
                  (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                       (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
                }
                local_20 = local_20 + 1;
              }
              for (local_20 = 0;
                  local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
                  local_20 = local_20 + 1) {
                *(uint *)(&g_CardSlot_Flags +
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                         *(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags +
                              *(int *)(&g_CardSlot_AttachedAura +
                                      target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120
                              + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) *
                                0x5b20) & 0xffcfffff;
              }
              if (g_ActivePlayer == 1) {
                (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              }
            }
          }
        }
        else {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_ConvertedManaCost + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20);
          local_c = (int)(char)(&g_CardSlot_TurnPlayed)
                               [DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20];
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          local_20 = 0;
          while ((local_20 < local_c && (g_ActivePlayer != 1))) {
            Pic_Subsystem_00424500(s_prompts_txt_0053052c,s_FIREBALL_00530520);
            sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_20 + 1,local_c);
            piVar12 = &local_28;
            uVar2 = 1;
            puVar8 = &g_OverworldGoldAmount;
            uVar13 = 0;
            uVar11 = 0;
            uVar9 = 0;
            uVar7 = 0xffffffff;
            uVar6 = 0xffffffff;
            iVar10 = -1;
            iVar1 = -1;
            uVar5 = 0;
            uVar4 = 0;
            uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
            iVar1 = Action_ValidateTarget_00405802
                              (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar10,
                               uVar6,uVar7,uVar9,uVar11,uVar13,puVar8,uVar2,piVar12);
            if (iVar1 == 0) {
              g_ActivePlayer = 1;
            }
            else {
              *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
              Ai_Subsystem_004cc9c5(0,0x20);
              *(int *)(&g_CardSlot_CombatTarget +
                      target_id * 0x120 +
                      spell_id * 0x5b20 +
                      (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                   local_28;
              *(int *)(&g_CardSlot_AttachedAura +
                      target_id * 0x120 +
                      spell_id * 0x5b20 +
                      (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                   local_24;
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                   (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
            }
            local_20 = local_20 + 1;
          }
          for (local_20 = 0;
              local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
              local_20 = local_20 + 1) {
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_AttachedAura +
                             target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                     *(int *)(&g_CardSlot_CombatTarget +
                             target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_AttachedAura +
                                  target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                          *(int *)(&g_CardSlot_CombatTarget +
                                  target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) &
                 0xffcfffff;
          }
          if (g_ActivePlayer == 1) {
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          }
        }
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        if (g_IsAiThinking == 1) {
          if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
            arg_3 = 5;
            iVar10 = 1;
            iVar1 = Math_RandomRange((g_TurnCounter + 1) / 2);
            g_AiDecisionScore = Math_Clamp(iVar1 + 1,iVar10,arg_3);
          }
          else {
            g_AiDecisionScore =
                 (int)(char)(&g_CardSlot_TurnPlayed)[DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20];
          }
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
        }
        local_30 = g_AiDecisionScore;
        if (g_AiDecisionScore == 99) {
          local_30 = 1;
        }
        iVar1 = g_TurnCounter - local_30;
        for (local_20 = 0; local_20 < local_30; local_20 = local_20 + 1) {
          Glue_Subsystem_004df8ba(spell_id,target_id);
          *(undefined4 *)
           (&g_CardSlot_CombatTarget +
           target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - local_20) * 8) =
               *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)
           (&g_CardSlot_AttachedAura +
           target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - local_20) * 8) =
               *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)local_30;
        }
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             (iVar1 + 1) / local_30;
      }
    }
    if (flags == 0x71) {
      if (g_CurrentTurnPhase == spell_id) {
        local_8 = 0;
        for (local_20 = 0;
            local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_20 = local_20 + 1) {
          uVar13 = 0;
          uVar11 = 0;
          uVar9 = 0;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar10 = -1;
          iVar1 = -1;
          uVar5 = 0;
          uVar4 = 0;
          uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
          iVar1 = Rules_ParseFilter_0040360b
                            (*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                             (char *)0x0,spell_id,2,2,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar10,
                             uVar6,uVar7,uVar9,uVar11,uVar13);
          if (iVar1 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20),spell_id,target_id);
          }
        }
      }
      else {
        iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        for (local_20 = 0;
            local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_20 = local_20 + 1) {
          *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8);
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8);
          Glue_Subsystem_004dfb23(spell_id,target_id,0x71,iVar1);
        }
      }
      if ((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == local_8) {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Prompts_Load_004fb1e4
 * Entry Point: 004fb1e4
 * Size: 906 bytes
 */


undefined4 Prompts_Load_004fb1e4(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else if ((g_ActivePlayerPriority == spell_id) &&
            (iVar2 = Font_DrawString(spell_id,7,2), iVar2 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530544,s_DETONATE_00530538);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,
                         iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((int)(char)(&DAT_0051aebf)
                          [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34]
               + (int)(char)(&DAT_0051aec0)
                            [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) *
                             0x34] ==
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)) {
        Mem_AllocOrFree_0041df33
                  (local_c,*(int *)(&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20),spell_id,target_id);
        Pic_Subsystem_0044867e(local_c,local_8,1);
      }
      else {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fb573
 * Entry Point: 004fb573
 * Size: 322 bytes
 */


undefined4 FUN_004fb573(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == hDIBSection)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((&g_PlayerCreatureCount)[hDIBSection] - (&g_PlayerCreatureCount)[1 - hDIBSection]) * 0x18;
    }
    if ((arg_3 == 0x71) && (g_IsAiThinking != 1)) {
      do {
        iVar2 = Ai_Subsystem_004b7d38(s_Your_flip_00530550);
        iVar3 = Ai_Subsystem_004b7d38(s_Opponent_flip_0053055c);
        if (iVar2 == 1) {
          Mem_AllocOrFree_0041df33(0,1,hDIBSection,card_slot);
        }
        if (iVar3 == 1) {
          Mem_AllocOrFree_0041df33(1,1,hDIBSection,card_slot);
        }
        if ((iVar2 != 0) || (iVar3 != 0)) {
          Ai_Subsystem_004cc56d
                    (hDIBSection,hDIBSection,card_slot,-1,-1,s_Repeating_since_a_tails_came_up__0053056c,0);
        }
      } while ((iVar2 != 0) || (iVar3 != 0));
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004fb6b5
 * Entry Point: 004fb6b5
 * Size: 1311 bytes
 */


undefined4 Prompts_Load_004fb6b5(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,2,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((spell_id == g_ActivePlayerPriority) &&
       ((g_OverworldPlayerCoordY == 0 || (iVar2 = Font_DrawString(spell_id, 7, 3), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = g_TurnCounter;
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    local_c = 0;
    local_8 = 0;
    while (((local_c < g_TurnCounter && (local_8 == 0)) && (g_ActivePlayer != 1))) {
      Pic_Subsystem_00424500(s_prompts_txt_005305a0,s_WORDOFBINDING_00530590);
      sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_c + 1,g_TurnCounter);
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        if (local_10 == -1) {
          g_ActivePlayer = 1;
        }
        else {
          local_8 = 1;
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) | 0x300000;
        Ai_Subsystem_004cc9c5(0,0x20);
        *(int *)(&g_CardSlot_CombatTarget +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             local_14;
        *(int *)(&g_CardSlot_AttachedAura +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             local_10;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
      }
      local_c = local_c + 1;
    }
    for (local_c = 0;
        local_c < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        local_c = local_c + 1) {
      *(uint *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_AttachedAura +
                       local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               *(int *)(&g_CardSlot_CombatTarget +
                       local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_AttachedAura +
                            local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    *(int *)(&g_CardSlot_CombatTarget +
                            local_c * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
           0xffcfffff;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
  }
  if (flags == 0x71) {
    for (local_c = 0;
        local_c < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        local_c = local_c + 1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget +
                                 local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                         spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_00415d48(*(int *)(&g_CardSlot_CombatTarget +
                             local_c * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura +
                             local_c * 8 + target_id * 0x120 + spell_id * 0x5b20));
      }
    }
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    Pic_Subsystem_0044867e(spell_id,target_id,1);
  }
  return 0;
}



/*
 * Decompiled function: Prompts_Load_004fbbd4
 * Entry Point: 004fbbd4
 * Size: 1103 bytes
 */


int Prompts_Load_004fbbd4(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    local_8 = 0;
    local_10 = 0;
    while (((local_10 < 500 && (local_8 == 0)) &&
           (*(int *)(&DAT_006ff710 + local_10 * 4 + spell_id * 2000) != -1))) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&DAT_006ff710 + local_10 * 4 + spell_id * 2000) * 0x34] & 2) != 0) {
        local_8 = 1;
      }
      local_10 = local_10 + 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_005305b8,s_RAISEDEAD_005305ac);
        do {
          local_c = Pic_Load_004509e8(spell_id,(int)(&DAT_006ff710 + spell_id * 2000),500,
                                      &g_OverworldGoldAmount,0);
          if (local_c == -1) break;
        } while (((&g_MasterCardColorTable)
                  [*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) * 0x34] & 2) == 0);
      }
      else {
        local_c = FUN_004fd9c0(spell_id,2);
      }
      if (((local_c == -1) || (*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) * 0x34]
          & 2) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Pic_Subsystem_00451291
                          (spell_id,*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000));
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + iVar1 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + iVar1 * 0x120) | 0x20;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = iVar1;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = local_c;
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if (((iVar1 == -1) || (*(int *)(&DAT_006ff710 + iVar1 * 4 + spell_id * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + iVar1 * 4 + spell_id * 2000) * 0x34] &
          2) == 0)) {
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0xffffffff;
      }
      else {
        Pic_Subsystem_00449223(spell_id,iVar1);
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                 + *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                      0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120) & 0xffffffdf;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    local_8 = 0;
  }
  return local_8;
}



/*
 * Decompiled function: FUN_004fc023
 * Entry Point: 004fc023
 * Size: 706 bytes
 */


undefined4 FUN_004fc023(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  uint local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == hDIBSection)) {
      if ((g_CurrentTurnPhase == hDIBSection) && (g_IsAiThinking != 1)) {
        iVar2 = Ai_Subsystem_004cc814
                          (hDIBSection,s_Drafna_s_Restoration__005305f4,0,s_My_graveyard_005305e4,
                           s_Opponent_s_graveyard_005305cc,(char *)0x0);
        if (iVar2 == 0) {
          local_c = hDIBSection;
        }
        else {
          local_c = 1 - hDIBSection;
        }
        local_8 = Pic_Load_004509e8(hDIBSection,(int)(&DAT_006ff710 + local_c * 2000),500,
                                    s_Pick_an_artifact_00530610,1);
        if ((local_8 != 0xffffffff) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&DAT_006ff710 + local_8 * 4 + local_c * 2000) * 0x34] & 0x40) == 0)) {
          local_8 = 0xffffffff;
        }
      }
      else {
        local_c = hDIBSection;
        local_8 = FUN_004fd9c0(hDIBSection,0x40);
      }
      if (((local_8 == 0xffffffff) || (*(int *)(&DAT_006ff710 + local_8 * 4 + local_c * 2000) == -1)
          ) || (((&g_MasterCardColorTable)
                 [*(int *)(&DAT_006ff710 + local_8 * 4 + local_c * 2000) * 0x34] & 0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) =
             local_c << 8 | local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20);
      if (((iVar2 != -1) && (*(int *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000) != -1)) &&
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000) * 0x34] &
          0x40) != 0)) {
        Pic_Subsystem_004524db(local_c,*(undefined4 *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000));
        *(undefined4 *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004fc2e5
 * Entry Point: 004fc2e5
 * Size: 889 bytes
 */


int Prompts_Load_004fc2e5(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    local_8 = 0;
    local_10 = 0;
    while (((local_10 < 500 && (local_8 == 0)) &&
           (*(int *)(&DAT_006ff710 + local_10 * 4 + spell_id * 2000) != -1))) {
      local_8 = 1;
      local_10 = local_10 + 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_00530630,s_REGROWTH_00530624);
        local_c = Pic_Load_004509e8(spell_id,(int)(&DAT_006ff710 + spell_id * 2000),500,
                                    &g_OverworldGoldAmount,0);
      }
      else {
        local_c = FUN_004fd9c0(spell_id,0xffffffff);
      }
      if ((local_c == -1) || (*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000) == -1)) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Pic_Subsystem_00451291
                          (spell_id,*(int *)(&DAT_006ff710 + local_c * 4 + spell_id * 2000));
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + iVar1 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + iVar1 * 0x120) | 0x20;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = iVar1;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = local_c;
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if ((iVar1 == -1) || (*(int *)(&DAT_006ff710 + iVar1 * 4 + spell_id * 2000) == -1)) {
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             0xffffffff;
      }
      else {
        Pic_Subsystem_00449223(spell_id,iVar1);
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                 + *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                   0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) & 0xffffffdf;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    local_8 = 0;
  }
  return local_8;
}



/*
 * Decompiled function: FUN_004fc65e
 * Entry Point: 004fc65e
 * Size: 576 bytes
 */


undefined4 FUN_004fc65e(int hDIBSection,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == hDIBSection)) {
      if ((hDIBSection == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        do {
          local_8 = Pic_Load_004509e8(hDIBSection,(int)(&DAT_006ff710 + hDIBSection * 2000),500,
                                      s_Pick_an_artifact_00530648,1);
          if (local_8 == -1) break;
        } while (((&g_MasterCardColorTable)
                  [*(int *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000) * 0x34] & 0x40) == 0);
      }
      else {
        local_8 = FUN_004fd9c0(hDIBSection,0x40);
      }
      if (((local_8 == -1) || (*(int *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000) * 0x34] &
          0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + hDIBSection * 0x5b20 + card_slot * 0x120) = local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + hDIBSection * 0x5b20 + card_slot * 0x120);
      if ((iVar1 != -1) &&
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + iVar1 * 4 + hDIBSection * 2000) * 0x34] &
          0x40) != 0)) {
        Pic_Subsystem_00451291(hDIBSection,*(int *)(&DAT_006ff710 + iVar1 * 4 + hDIBSection * 2000));
        *(undefined4 *)(&DAT_006ff710 + iVar1 * 4 + hDIBSection * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Prompts_Load_004fc89e
 * Entry Point: 004fc89e
 * Size: 711 bytes
 */


undefined4 Prompts_Load_004fc89e(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint local_10;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
        (spell_id == g_EventSourcePlayer)) &&
       ((spell_id == g_ActivePlayerPriority && (*(int *)(&DAT_0069e730 + spell_id * 2000) == -1))))
    {
      g_ActivePlayer = 1;
    }
    if (flags == 0x71) {
      if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_0053066c,s_DEMONIC_TUTOR_0053065c);
        local_8 = Pic_Load_004509e8(spell_id,(int)(&DAT_0069e730 + spell_id * 2000),500,
                                    &g_OverworldGoldAmount,1);
        if ((local_8 != -1) && (*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000) != -1)) {
          Pic_Subsystem_00451291(spell_id,*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000));
          Pic_Subsystem_004523fd(spell_id,local_8);
        }
      }
      else {
        if (spell_id == g_CurrentTurnPhase) {
          local_10 = 0x42;
        }
        else {
          if (g_IsAiThinking == 1) {
            g_AiDecisionScore = Math_RandomRange(4);
            Ai_EvaluateCreaturePower();
          }
          else {
            Ai_CalcCardAdvantage();
          }
          switch(g_AiDecisionScore) {
          case 0:
            local_10 = 2;
            break;
          case 1:
            local_10 = 0x40;
            break;
          case 2:
            local_10 = 8;
            break;
          case 3:
            local_10 = 0x10;
          }
        }
        local_8 = FUN_004fdad2(spell_id,spell_id,local_10);
        if (local_8 == -1) {
          local_8 = FUN_004fdad2(spell_id,spell_id,0xffffffff);
        }
        if ((local_8 != -1) && (*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000) != -1)) {
          Pic_Subsystem_00451291(spell_id,*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000));
          Pic_Subsystem_004523fd(spell_id,local_8);
        }
      }
      if (local_8 != -1) {
        Ai_Subsystem_004cc9c5(0,0x30);
        Pic_Subsystem_00452276(spell_id);
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004fcb7a
 * Entry Point: 004fcb7a
 * Size: 880 bytes
 */


undefined4 Prompts_Load_004fcb7a(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int arg2;
  int local_14;
  int local_c;
  
  if (flags == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (flags == 0x71) {
      if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_0053068c,s_UNTAMED_WILDS_0053067c);
        bVar1 = false;
        local_14 = 0;
        while (((local_14 < 500 && (!bVar1)) &&
               (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) != -1))) {
          if (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) < 5) {
            bVar1 = true;
          }
          local_14 = local_14 + 1;
        }
        if (bVar1) {
          do {
            local_c = Pic_Load_004509e8(spell_id,(int)(&DAT_0069e730 + spell_id * 2000),500,
                                        &g_OverworldGoldAmount,1);
            if (local_c == -1) break;
          } while (4 < *(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000));
        }
        else {
          local_c = -1;
          Pic_Load_004509e8(spell_id,(int)(&DAT_0069e730 + spell_id * 2000),500,
                            &g_OverworldGoldAmount,0);
        }
      }
      else {
        local_c = FUN_004fdad2(spell_id,spell_id,1);
        if ((local_c != -1) && (4 < *(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000))) {
          local_c = -1;
          local_14 = 0;
          while (((local_14 < 500 && (local_c == -1)) &&
                 (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) != -1))) {
            if (*(int *)(&DAT_0069e730 + local_14 * 4 + spell_id * 2000) < 5) {
              local_c = local_14;
            }
            local_14 = local_14 + 1;
          }
        }
      }
      if ((local_c != -1) &&
         ((*(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000) == -1 ||
          (4 < *(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000))))) {
        local_c = -1;
      }
      if (((local_c != -1) && (*(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000) != -1)) &&
         (arg2 = Pic_Subsystem_00451291
                           (spell_id,*(int *)(&DAT_0069e730 + local_c * 4 + spell_id * 2000)),
         arg2 != -1)) {
        Pic_Subsystem_004523fd(spell_id,local_c);
        Pic_Subsystem_0042ac1f(spell_id,arg2);
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      Pic_Subsystem_00452276(spell_id);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Prompts_Load_004fceea
 * Entry Point: 004fceea
 * Size: 561 bytes
 */


undefined4 Prompts_Load_004fceea(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005306ac,s_VISIONS_005306a4);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      if (((spell_id == 0) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_005306c0,s_VISIONS_005306b8);
        Pic_Load_004509e8(0,(int)(&DAT_0069e730 +
                                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120) * 2000),5,
                          &DAT_0069f84a,0);
      }
      iVar2 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,
                         s_Shuffle_library__Don_t_shuffle__005306d4,1);
      if (iVar2 == 0) {
        Pic_Subsystem_00452276
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fd11b
 * Entry Point: 004fd11b
 * Size: 692 bytes
 */


undefined4 FUN_004fd11b(int hDIBSection,int card_slot,int arg_3)

{
  char cVar1;
  char cVar2;
  int arg2;
  undefined4 uVar3;
  int iVar4;
  int local_1c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == hDIBSection)) {
      if ((g_CurrentTurnPhase == hDIBSection) && (g_IsAiThinking != 1)) {
        local_8 = Pic_Load_004509e8(hDIBSection,(int)(&DAT_0069e730 + hDIBSection * 2000),500,
                                    s_Pick_an_artifact_005306fc,1);
      }
      else {
        local_8 = FUN_004fdad2(hDIBSection,hDIBSection,0x40);
      }
      if ((local_8 == -1) || (*(int *)(&DAT_0069e730 + local_8 * 4 + hDIBSection * 2000) == -1)) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20) = local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar4 = *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + hDIBSection * 0x5b20);
      if ((*(int *)(&DAT_0069e730 + iVar4 * 4 + hDIBSection * 2000) != -1) &&
         (arg2 = *(int *)(&DAT_0069e730 + iVar4 * 4 + hDIBSection * 2000),
         ((&g_MasterCardColorTable)[arg2 * 0x34] & 0x40) != 0)) {
        Pic_Subsystem_004523fd(hDIBSection,iVar4);
        if (local_1c != -1) {
          iVar4 = *(int *)(&g_CardSlot_CardId + local_1c * 0x120 + hDIBSection * 0x5b20);
          Pic_Subsystem_0044867e(hDIBSection,local_1c,2);
          cVar1 = (&DAT_0051aec0)[arg2 * 0x34];
          cVar2 = (&DAT_0051aec0)[iVar4 * 0x34];
          while (0 < (int)cVar1 - (int)cVar2) {
            iVar4 = Font_DrawString(hDIBSection,7,1);
            if (iVar4 == 0) break;
            Ai_CalcManaRequirement_004ba890(hDIBSection,0,1);
          }
          if ((int)cVar1 - (int)cVar2 < 1) {
            iVar4 = Pic_Subsystem_00451291(hDIBSection,arg2);
            if (iVar4 != -1) {
              *(uint *)(&g_CardSlot_Flags + hDIBSection * 0x5b20 + iVar4 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + hDIBSection * 0x5b20 + iVar4 * 0x120) | 0x30002;
            }
          }
        }
      }
      Pic_Subsystem_00452276(hDIBSection);
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Prompts_Load_004fd3cf
 * Entry Point: 004fd3cf
 * Size: 533 bytes
 */


undefined4 Prompts_Load_004fd3cf(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = Font_DrawString(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0053071c,s_MINDTWIST_00530710);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_10);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      for (local_8 = 0;
          local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
          local_8 = local_8 + 1) {
        Prompts_Load_0046fa40
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),1,0);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004fd5e4
 * Entry Point: 004fd5e4
 * Size: 608 bytes
 */


undefined4 FUN_004fd5e4(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  char local_d8 [200];
  int local_10;
  int local_c;
  uint local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
        if ((&DAT_006b3008)[local_10] == 0) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530728);
          local_8 = 0;
        }
        else if ((&DAT_006b3008)[local_10] == 1) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_005307a4);
          local_8 = (uint)((int)(&g_PlayerCreatureCount)[local_10] < 5);
        }
        else if ((&DAT_006b3008)[local_10] == 2) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530820);
          if ((int)(&g_PlayerCreatureCount)[local_10] < 5) {
            local_8 = 2;
          }
          else {
            local_8 = 0;
          }
        }
        else {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530898);
          if ((int)(&g_PlayerCreatureCount)[local_10] < 5) {
            local_8 = 3;
          }
          else {
            local_8 = 0;
          }
        }
        local_c = Ai_Subsystem_004cc56d(local_10,hDIBSection,card_slot,-1,-1,local_d8,local_8);
        if (local_c == 1) {
          Mem_AllocOrFree_0041df33(local_10,2,hDIBSection,card_slot);
          Prompts_Load_0046fa40(local_10,0,1);
        }
        else if (local_c == 2) {
          Mem_AllocOrFree_0041df33(local_10,1,hDIBSection,card_slot);
          Prompts_Load_0046fa40(local_10,0,1);
          Prompts_Load_0046fa40(local_10,0,1);
        }
        else if (local_c == 3) {
          Prompts_Load_0046fa40(local_10,0,1);
          Prompts_Load_0046fa40(local_10,0,1);
          Prompts_Load_0046fa40(local_10,0,1);
        }
        else {
          Mem_AllocOrFree_0041df33(local_10,3,hDIBSection,card_slot);
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fd844
 * Entry Point: 004fd844
 * Size: 380 bytes
 */


undefined4 FUN_004fd844(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      if ((g_CurrentTurnPhase == hDIBSection) && (g_IsAiThinking != 1)) {
        local_8 = Pic_Load_004509e8(hDIBSection,(int)(&DAT_006ff710 + hDIBSection * 2000),500,
                                    s_Pick_a_creature_00530914,1);
      }
      else {
        local_8 = FUN_004fd9c0(hDIBSection,2);
      }
      if (((local_8 != -1) && (*(int *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000) != -1)) &&
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000) * 0x34] &
          2) != 0)) {
        iVar2 = Pic_Subsystem_00451291(hDIBSection,*(int *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000));
        if (iVar2 != -1) {
          *(undefined4 *)(&g_CardSlot_Flags + iVar2 * 0x120 + hDIBSection * 0x5b20) = 0x30002;
        }
        *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + hDIBSection * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fd9c0
 * Entry Point: 004fd9c0
 * Size: 274 bytes
 */


int FUN_004fd9c0(int arg1,uint arg2)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  
  local_14 = 0;
  local_10 = -1;
  if (arg1 == -1) {
    local_10 = -1;
  }
  else {
    local_18 = 0;
    while ((local_18 < 500 && (*(int *)(&DAT_006ff710 + local_18 * 4 + arg1 * 2000) != -1))) {
      iVar1 = *(int *)(&DAT_006ff710 + local_18 * 4 + arg1 * 2000);
      if ((arg2 == 0xffffffff) || ((arg2 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
        iVar2 = abs((int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
        iVar1 = (char)(&DAT_0051aebf)[iVar1 * 0x34] * 3 + iVar2 * 2;
        if (local_14 < iVar1) {
          local_10 = local_18;
          local_14 = iVar1;
        }
      }
      local_18 = local_18 + 1;
    }
  }
  return local_10;
}



/*
 * Decompiled function: FUN_004fdad2
 * Entry Point: 004fdad2
 * Size: 334 bytes
 */


int FUN_004fdad2(int hDIBSection,int card_slot,uint arg_3)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = -99;
  local_10 = -1;
  if (card_slot == -1) {
    local_10 = -1;
  }
  else {
    local_18 = 0;
    while ((local_18 < 500 && (*(int *)(&DAT_0069e730 + local_18 * 4 + card_slot * 2000) != -1))) {
      iVar1 = *(int *)(&DAT_0069e730 + local_18 * 4 + card_slot * 2000);
      if ((arg_3 == 0xffffffff) || ((arg_3 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
        local_8 = abs((int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
        local_8 = local_8 + (char)(&DAT_0051aebf)[iVar1 * 0x34] * 2;
        if (*(int *)(&DAT_0063ee4c + hDIBSection * 0x20) < local_8) {
          local_8 = -local_8;
        }
        if (local_8 == 0) {
          local_8 = 99;
        }
        iVar1 = Pic_Subsystem_00452551(iVar1);
        local_8 = local_8 + iVar1 * 2;
        if (local_14 < local_8) {
          local_10 = local_18;
          local_14 = local_8;
        }
      }
      local_18 = local_18 + 1;
    }
  }
  return local_10;
}



/*
 * Decompiled function: FUN_004fdc20
 * Entry Point: 004fdc20
 * Size: 299 bytes
 */


int FUN_004fdc20(int x,int y,uint width,int height)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = -99;
  local_10 = -1;
  if (y == -1) {
    local_10 = -1;
  }
  else {
    for (local_18 = 0; (*(int *)(height + local_18 * 4) != -1 && (local_18 < 0x50));
        local_18 = local_18 + 1) {
      iVar1 = *(int *)(height + local_18 * 4);
      if ((width == 0xffffffff) || ((width & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
        local_8 = abs((int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
        local_8 = local_8 + (char)(&DAT_0051aebf)[iVar1 * 0x34] * 2;
        if (*(int *)(&DAT_0063ee4c + x * 0x20) < local_8) {
          local_8 = -local_8;
        }
        if (local_8 == 0) {
          local_8 = 99;
        }
        iVar1 = Pic_Subsystem_00452551(iVar1);
        local_8 = local_8 + iVar1 * 2;
        if (local_14 < local_8) {
          local_10 = local_18;
          local_14 = local_8;
        }
      }
    }
  }
  return local_10;
}



/*
 * Decompiled function: FUN_004fdd4b
 * Entry Point: 004fdd4b
 * Size: 237 bytes
 */


undefined4 FUN_004fdd4b(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            Pic_Subsystem_0044867e(local_8,local_c,1);
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fde38
 * Entry Point: 004fde38
 * Size: 314 bytes
 */


undefined4 FUN_004fde38(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 1) != 0)
             ) {
            iVar2 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20);
            iVar3 = Card_UntapCard(hDIBSection,card_slot,5);
            if (*(int *)(&g_MasterCardTypeTable + iVar2 * 0x34) ==
                *(int *)(&DAT_006ff2bc + iVar3 * 4)) {
              Pic_Subsystem_0044867e(local_8,local_c,2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004fdf72
 * Entry Point: 004fdf72
 * Size: 237 bytes
 */


undefined4 FUN_004fdf72(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 0x40) !=
              0)) {
            Pic_Subsystem_0044867e(local_8,local_c,1);
          }
        }
      }
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004fe05f
 * Entry Point: 004fe05f
 * Size: 1568 bytes
 */


undefined4 Prompts_Load_004fe05f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined *arg_18;
  uint uVar9;
  uint uVar10;
  int *arg_20;
  uint uVar11;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        Pic_Subsystem_00424500(s_prompts_txt_00530934,s_PYROTECHNICS_00530924);
        local_c = 0;
        while ((local_c < 4 && (g_ActivePlayer != 1))) {
          arg_20 = &local_14;
          uVar1 = 1;
          arg_18 = &g_OverworldGoldAmount + local_c * 0xfa;
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 0xffffffff;
          uVar7 = 0xffffffff;
          iVar6 = -1;
          iVar5 = -1;
          uVar4 = 0;
          uVar3 = 0;
          uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          iVar5 = Action_ValidateTarget_00405802
                            (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                             uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
          if (iVar5 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) | 0x200000;
            Ai_Subsystem_004cc9c5(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                 = local_14;
            *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                 = local_10;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          local_c = local_c + 1;
        }
        for (local_c = 0;
            local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) &
               0xffcfffff;
        }
        if (g_ActivePlayer == 1) {
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        }
      }
      else {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          Glue_Subsystem_004df8ba(spell_id,target_id);
          *(undefined4 *)
           (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + (3 - local_c) * 8) =
               *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)
           (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + (3 - local_c) * 8) =
               *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 4;
        }
      }
    }
    if (flags == 0x71) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        local_8 = 0;
        for (local_c = 0;
            local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 0xffffffff;
          uVar7 = 0xffffffff;
          iVar6 = -1;
          iVar5 = -1;
          uVar4 = 0;
          uVar3 = 0;
          uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          iVar5 = Rules_ParseFilter_0040360b
                            (*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                             (char *)0x0,spell_id,2,2,0x1200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                             uVar7,uVar8,uVar9,uVar10,uVar11);
          if (iVar5 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),1,spell_id,
                         target_id);
          }
        }
        if ((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == local_8) {
          g_ActivePlayer = 1;
        }
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
      else {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
          Glue_Subsystem_004dfb23(spell_id,target_id,0x71,1);
        }
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004fe67f
 * Entry Point: 004fe67f
 * Size: 642 bytes
 */


undefined4 Prompts_Load_004fe67f(int spell_id,int target_id,int flags)

{
  int arg_5;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = Font_DrawString(spell_id,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           g_TurnCounter;
      Pic_Subsystem_00424500(s_prompts_txt_00530950,s_DISINTEGRATE_00530940);
      iVar1 = Glue_Subsystem_004df8ba(spell_id,target_id);
      if (iVar1 != 0) {
        iVar1 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20));
        g_SpellStackDepth = g_SpellStackDepth - (int)(0x30 / (longlong)iVar1);
      }
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      arg_5 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar3 = Glue_Subsystem_004dfb23
                        (spell_id,target_id,0x71,
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20));
      if ((iVar3 != 0) &&
         (*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        iVar3 = Card_ApplyTriggerEffect(spell_id,target_id,DAT_006a49ec,iVar1,arg_5);
        if (iVar3 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar3 * 0x120 + spell_id * 0x5b20) = 0x200
          ;
        }
        *(undefined4 *)(&g_CardSlot_Abilities2 + arg_5 * 0x120 + iVar1 * 0x5b20) = 0x8000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004fe901
 * Entry Point: 004fe901
 * Size: 181 bytes
 */


undefined4 FUN_004fe901(int hDIBSection,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      iVar3 = hDIBSection;
      iVar4 = card_slot;
      iVar2 = Card_UntapCard(hDIBSection,card_slot,4);
      Mem_AllocOrFree_0041df33
                (1 - hDIBSection,*(int *)(&DAT_0063ee30 + iVar2 * 4 + hDIBSection * 0x20),iVar3,iVar4);
      iVar3 = hDIBSection;
      iVar4 = card_slot;
      iVar2 = Card_UntapCard(hDIBSection,card_slot,4);
      Mem_AllocOrFree_0041df33
                (hDIBSection,(*(int *)(&DAT_0063ee30 + iVar2 * 4 + hDIBSection * 0x20) + 1) / 2,iVar3,iVar4);
      Pic_Subsystem_0044867e(hDIBSection,card_slot,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004fe9b6
 * Entry Point: 004fe9b6
 * Size: 1451 bytes
 */


undefined4 Prompts_Load_004fe9b6(int spell_id,int target_id,int flags)

{
  int y;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = Font_DrawString(spell_id, 7, 3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
        g_TurnCounter = 0;
        Ai_CalcManaRequirement_004ba890(spell_id,1,-1);
        if (g_ActivePlayer == 1) {
          return 0;
        }
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)
              (&g_CardSlot_ConvertedManaCost + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20);
      }
      Pic_Subsystem_00424500(s_prompts_txt_00530968,s_DRAIN_LIFE_0053095c);
      Glue_Subsystem_004df8ba(spell_id,target_id);
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      y = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar3 = Glue_Subsystem_004dfb23
                        (spell_id,target_id,0x71,
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20));
      if ((iVar3 == 0) ||
         (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) < 1)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      else {
        if (y == -1) {
          local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
          if ((int)(&g_PlayerCreatureCount)[iVar1] <=
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)) {
            local_8 = (&g_PlayerCreatureCount)[iVar1];
          }
        }
        else {
          iVar3 = Card_TapForMana(iVar1,y,0x33,0xffffffff);
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) <
              iVar3) {
            local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20
                              );
          }
          else {
            local_8 = Card_TapForMana(iVar1,y,0x33,0xffffffff);
          }
        }
        if (local_8 < 0) {
          local_8 = 0;
        }
        iVar1 = Pic_Subsystem_00451291(spell_id,DAT_006fdbd0);
        if (iVar1 != -1) {
          *(undefined4 *)(&g_ActiveCardsInPlay + iVar1 * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20);
          *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + spell_id * 0x5b20) | 2;
          *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + spell_id * 0x5b20) = 0x44;
          *(undefined4 *)(&DAT_006a5f80 + iVar1 * 0x120 + spell_id * 0x5b20) = 0xd7;
          *(int *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + spell_id * 0x5b20) = local_8;
          FUN_00476482(spell_id,iVar1);
          (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + spell_id * 0x5b20] = (undefined1)spell_id;
          *(int *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + spell_id * 0x5b20) = target_id;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    if (((flags == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                 ) == DAT_006ff2e0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == -1 &&
        ((((char)(&g_CardSlot_DamageReceived)
                 [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] == spell_id &&
          (*(int *)(&g_CardSlot_TypeFlags +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == target_id)) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) != 0)))))) {
      (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
           (undefined1)g_EventSourcePlayer;
      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = g_EventSourceSlot;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Prompts_Load_004fef61
 * Entry Point: 004fef61
 * Size: 542 bytes
 */


undefined4 Prompts_Load_004fef61(int spell_id,int target_id,int flags)

{
  int color_mask;
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  int iVar3;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530980,s_STONE_RAIN_00530974);
      iVar2 = Glue_Subsystem_004e6dcc(spell_id,2,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth +
             ((-(uint)(*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
                      spell_id) & 0xfffffffb) * 3 + 9) * 4;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      iVar2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0040360b
                        (iVar2,color_mask,(char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,
                         iVar3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(iVar2,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_004ff17f
 * Entry Point: 004ff17f
 * Size: 492 bytes
 */


undefined4 Prompts_Load_004ff17f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530998,s_DRAIN_POWER_0053098c);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_14);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10
        ;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      Glue_Subsystem_004e65e1(FUN_004ff36b,local_8);
      if (local_8 != spell_id) {
        for (local_c = 0; local_c < 8; local_c = local_c + 1) {
          *(int *)(&DAT_0063ee90 + local_c * 4 + spell_id * 0x20) =
               *(int *)(&DAT_0063ee90 + local_c * 4 + spell_id * 0x20) +
               *(int *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20);
          *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20) = 0;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004ff36b
 * Entry Point: 004ff36b
 * Size: 228 bytes
 */


undefined4 FUN_004ff36b(int hDIBSection,int card_slot,int arg_3)

{
  DAT_006ff4ac = 1;
  DAT_006ff2d4 = 0xffffffff;
  if (((((&g_CardSlot_Flags)[card_slot * 0x120 + hDIBSection * 0x5b20] & 0x10) == 0) &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 1) != 0)) &&
     (((&DAT_0051aed1)[arg_3 * 0x34] & 0x10) != 0)) {
    Magic_TriggerCardEvent(hDIBSection,card_slot,0x6d,1 - hDIBSection,0xffffffff);
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + hDIBSection * 0x5b20] & 0x10) != 0) {
      FUN_00473e69(hDIBSection,card_slot,0x81);
    }
  }
  DAT_006ff4ac = 0;
  return 0;
}



/*
 * Decompiled function: FUN_004ff450
 * Entry Point: 004ff450
 * Size: 374 bytes
 */


void FUN_004ff450(HWND hwnd)

{
  INT_PTR IVar1;
  
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe1,hwnd,UI_DialogProc_004ff5c6,0);
  if (IVar1 != 0) {
    if (DAT_006fe448 == -1) {
      Pic_Load_004450c3(0,DAT_006a3f60,DAT_006fe44c);
    }
    else {
      Pic_Load_004450c3(0,DAT_006fe448,DAT_006fe44c);
    }
    LockWindowUpdate(g_MainAppHwnd);
    FUN_00409b2c(0,0);
    FUN_00409b2c(1,0);
    Pic_Subsystem_004441cc(g_MainAppHwnd,DAT_006fe444);
    FUN_00478163(DAT_007006b0);
    Glue_Subsystem_004eee4e(DAT_006a4924);
    Glue_Subsystem_004eee4e(DAT_006b2e2c);
    Pic_Subsystem_0044cfe4(DAT_0069e720);
    Pic_Subsystem_0044cfe4(DAT_006fe400);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(DAT_0069e720,0x435,0,0);
    SendMessageA(DAT_006fe400,0x435,0,0);
    SendMessageA(DAT_006a4924,0x435,0,0);
    SendMessageA(DAT_006b2e2c,0x435,0,0);
    SendMessageA(DAT_006b3064,0x435,0,0);
    SendMessageA(DAT_006fe3fc,0x435,0,0);
    Rules_ParseFilter_0050065d();
  }
  return;
}



/*
 * Decompiled function: UI_DialogProc_004ff5c6
 * Entry Point: 004ff5c6
 * Size: 2001 bytes
 */


HBRUSH UI_DialogProc_004ff5c6(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  UINT UVar1;
  HWND pHVar2;
  HBRUSH pHVar3;
  BOOL bEnable;
  tagRECT local_38;
  COLORREF local_28;
  HWND local_24;
  HWND local_20;
  int local_1c;
  HDC local_18;
  HWND local_10;
  HWND local_c;
  int local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_24 = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_24[5].unused) {
        local_28 = DAT_0061d85c;
      }
      else {
        local_28 = DAT_0061d86c;
      }
      FUN_004f5107((int)local_24,DAT_0061d864,DAT_0061d850,DAT_0061d860,local_28,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      GDI_RealizeAndFlushPalette_Magic(wParam);
      GetClientRect(hwnd,&local_38);
      if (DAT_0061d858 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(wParam,&local_38,pHVar3);
      }
      else {
        FUN_004f3b5f((int)wParam,(int)&local_38,DAT_0061d858);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_004ffaf5:
      local_18 = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      local_20 = lParam;
      local_1c = GetDlgCtrlID(lParam);
      if ((local_1c != 0x3ff) && (local_1c != 0x40d)) {
        if (local_1c == 0x48b) {
          SetTextColor(local_18,DAT_0061d854);
          SetBkMode(local_18,1);
          pHVar3 = GetStockObject(5);
          return pHVar3;
        }
        pHVar2 = GetFocus();
        if (pHVar2 == local_20) {
          SetTextColor(local_18,DAT_0061d85c);
        }
        else {
          SetTextColor(local_18,DAT_0061d868);
        }
        SetBkMode(local_18,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetTextColor(local_18,DAT_0061d868);
      SetBkMode(local_18,1);
      return DAT_0061d864;
    }
    if (uMsg == 0x110) {
      Pic_Load_s_WINBK_Options_004ffd9c
                (&DAT_0061d858,&DAT_0061d854,&DAT_0061d868,(int *)&DAT_0061d864,(int *)&DAT_0061d850
                 ,(int *)&DAT_0061d860,&DAT_0061d86c,&DAT_0061d85c);
      if (DAT_006fe444 == 1) {
        local_8 = 0x400;
      }
      else {
        local_8 = 0x401;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x400,0x401,local_8);
      if (DAT_006fe420 != 0) {
        CheckDlgButton(hwnd,0x403,1);
      }
      if (DAT_006fe428 != 0) {
        CheckDlgButton(hwnd,0x404,1);
      }
      if (DAT_006fe42c != 0) {
        CheckDlgButton(hwnd,0x405,1);
      }
      if (DAT_006fe434 != 0) {
        CheckDlgButton(hwnd,0x495,1);
      }
      if (((byte)DAT_006fe410 & 1) == 0) {
        bEnable = 0;
        pHVar2 = GetDlgItem(hwnd,0x495);
        EnableWindow(pHVar2,bEnable);
        CheckDlgButton(hwnd,0x495,1);
      }
      if (DAT_006fe448 == 1) {
        local_8 = 0x409;
      }
      else if (DAT_006fe448 == 2) {
        local_8 = 0x408;
      }
      else if (DAT_006fe448 == 3) {
        local_8 = 0x40b;
      }
      else if (DAT_006fe448 == 5) {
        local_8 = 0x407;
      }
      else if (DAT_006fe448 == 4) {
        local_8 = 0x40a;
      }
      else {
        local_8 = 0x40c;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x407,0x40c,local_8);
      if (DAT_006fe44c == 0) {
        local_8 = 0x40e;
      }
      else if (DAT_006fe44c == 1) {
        local_8 = 0x40f;
      }
      else {
        local_8 = 0x410;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x40e,0x410,local_8);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 2) {
        FUN_004ffe82(DAT_0061d858,DAT_0061d864,DAT_0061d850,DAT_0061d860);
        EndDialog(hwnd,0);
      }
      else if (((uint)wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x400);
        if (UVar1 == 0) {
          DAT_006fe444 = 2;
        }
        else {
          DAT_006fe444 = 1;
        }
        DAT_006fe420 = IsDlgButtonChecked(hwnd,0x403);
        DAT_006fe428 = IsDlgButtonChecked(hwnd,0x404);
        DAT_006fe42c = IsDlgButtonChecked(hwnd,0x405);
        DAT_006fe434 = IsDlgButtonChecked(hwnd,0x495);
        UVar1 = IsDlgButtonChecked(hwnd,0x409);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x408);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(hwnd,0x407);
            if (UVar1 == 0) {
              UVar1 = IsDlgButtonChecked(hwnd,0x40b);
              if (UVar1 == 0) {
                UVar1 = IsDlgButtonChecked(hwnd,0x40a);
                if (UVar1 == 0) {
                  DAT_006fe448 = -1;
                }
                else {
                  DAT_006fe448 = 4;
                }
              }
              else {
                DAT_006fe448 = 3;
              }
            }
            else {
              DAT_006fe448 = 5;
            }
          }
          else {
            DAT_006fe448 = 2;
          }
        }
        else {
          DAT_006fe448 = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x40e);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x40f);
          if (UVar1 == 0) {
            DAT_006fe44c = 2;
          }
          else {
            DAT_006fe44c = 1;
          }
        }
        else {
          DAT_006fe44c = 0;
        }
        Rules_ParseFilter_0050065d();
        FUN_004ffe82(DAT_0061d858,DAT_0061d864,DAT_0061d850,DAT_0061d860);
        EndDialog(hwnd,1);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_004ffaf5;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar3 = (HBRUSH)GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar3;
    }
    if (uMsg == 0x4c8) {
      local_c = (HWND)wParam;
      local_10 = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == local_c) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_c != (HWND)0x0) {
        InvalidateRect(local_c,(RECT *)0x0,1);
      }
      if (local_10 != (HWND)0x0) {
        InvalidateRect(local_10,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}



/*
 * Decompiled function: Pic_Load_s_WINBK_Options_004ffd9c
 * Entry Point: 004ffd9c
 * Size: 230 bytes
 */


void Pic_Load_s_WINBK_Options_004ffd9c
               (undefined4 *hDIBSection,undefined4 *out_buffer,undefined4 *arg_3,int *arg_4,int *arg_5,
               int *arg_6,undefined4 *arg_7,undefined4 *arg_8)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_Options_pic_00530a20,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *hDIBSection = uVar1;
  *out_buffer = 0x1000007;
  *arg_3 = 0x1000001;
  pHVar2 = CreateSolidBrush(0x1000036);
  *arg_4 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000ba);
  *arg_5 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000016);
  *arg_6 = (int)pHVar3;
  *arg_7 = 0x1000001;
  *arg_8 = 0x10000bf;
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_5 = (int)pvVar4;
  }
  if (*arg_6 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_6 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_004ffe82
 * Entry Point: 004ffe82
 * Size: 93 bytes
 */


void FUN_004ffe82(HANDLE hDIBSection,HGDIOBJ card_slot,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (hDIBSection != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(hDIBSection);
  }
  if (card_slot != (HGDIOBJ)0x0) {
    DeleteObject(card_slot);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  return;
}



/*
 * Decompiled function: Rules_ParseFilter_004ffedf
 * Entry Point: 004ffedf
 * Size: 1918 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Rules_ParseFilter_004ffedf(void)

{
  LSTATUS LVar1;
  int iVar2;
  int local_90;
  int local_8c;
  BYTE *local_88;
  BYTE local_84 [100];
  int local_20;
  int local_1c;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a4,0,1,
                        &local_18);
  if (LVar1 == 0) {
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_Layout_00530a38,(LPDWORD)0x0,(LPDWORD)0x0,local_14,&local_8)
    ;
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a40,&DAT_006fe444);
    }
    else {
      DAT_006fe444 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_DirectiveTracksMouse_00530a44,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a5c,&DAT_006fe424);
    }
    else {
      DAT_006fe424 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowCueCards_00530a60,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                             &local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a70,&DAT_006fe420);
    }
    else {
      DAT_006fe420 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowPowerToughnessOnCards_00530a74,(LPDWORD)0x0,(LPDWORD)0x0
                             ,local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a90,&DAT_006fe428);
    }
    else {
      DAT_006fe428 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowIDTagsOnCards_00530a94,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530aa8,&DAT_006fe438);
    }
    else {
      DAT_006fe438 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowInvisibleEffectCards_00530aac,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530ac8,&DAT_006fe43c);
    }
    else {
      DAT_006fe43c = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowAllCardsSummonSickness_00530acc,(LPDWORD)0x0,
                             (LPDWORD)0x0,local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530ae8,&DAT_006fe440);
    }
    else {
      DAT_006fe440 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    RegQueryValueExA(local_18,s_ShowAbilitiesOnCards_00530aec,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                     &local_8);
    if (local_14[0] == '\0') {
      DAT_006fe42c = 1;
    }
    else {
      sscanf((char *)local_14,&DAT_00530b04,&DAT_006fe42c);
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ExpandTextBoxOnBigCard_00530b08,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530b20,&DAT_006fe430);
    }
    else {
      DAT_006fe430 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_SeeNextDrawsAtEndOfDuel_00530b24,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530b3c,&DAT_006fe434);
    }
    else {
      DAT_006fe434 = 1;
    }
    local_8 = 100;
    local_84[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_PhaseStoppers_00530b40,(LPDWORD)0x0,(LPDWORD)0x0,local_84,
                             &local_8);
    if (LVar1 == 0) {
      local_88 = local_84;
      local_1c = 0;
      while ((local_1c < 2 && (*local_88 != '\0'))) {
        local_20 = 0;
        while ((local_20 < 0x25 && (*local_88 != '\0'))) {
          if (*local_88 == 'S') {
            *(undefined4 *)(&DAT_00696740 + local_20 * 4 + local_1c * 0x98) = 1;
          }
          else {
            *(undefined4 *)(&DAT_00696740 + local_20 * 4 + local_1c * 0x98) = 0;
          }
          local_20 = local_20 + 1;
          local_88 = local_88 + 1;
        }
        local_1c = local_1c + 1;
      }
    }
    else {
      for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < 0x25; local_20 = local_20 + 1) {
          *(undefined4 *)(&DAT_00696740 + local_20 * 4 + local_1c * 0x98) = 0;
        }
      }
      _DAT_00696790 = 1;
      _DAT_006967b8 = 1;
      DAT_00696854 = 1;
    }
    if (((byte)DAT_006fe410 & 1) == 0) {
      local_8 = 10;
      local_14[0] = '\0';
      LVar1 = RegQueryValueExA(local_18,s_PlayerTerritoryColor_00530b50,(LPDWORD)0x0,(LPDWORD)0x0,
                               local_14,&local_8);
      if (LVar1 == 0) {
        sscanf((char *)local_14,&DAT_00530b68,&DAT_006fe448);
      }
      else {
        DAT_006fe448 = 0xffffffff;
      }
    }
    if (((byte)DAT_006fe410 & 1) == 0) {
      local_8 = 10;
      local_14[0] = '\0';
      LVar1 = RegQueryValueExA(local_18,s_PlayerTerritoryType_00530b6c,(LPDWORD)0x0,(LPDWORD)0x0,
                               local_14,&local_8);
      if (LVar1 == 0) {
        sscanf((char *)local_14,&DAT_00530b80,&DAT_006fe44c);
      }
      else {
        DAT_006fe44c = 2;
      }
    }
    local_8 = 10;
    LVar1 = RegQueryValueExA(local_18,s_CoolKimCheats_00530b84,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                             &local_8);
    if (LVar1 == 0) {
      iVar2 = strcmp((char *)local_14,s_HolyMoly_00530b94);
      DAT_006b2d38 = (uint)(iVar2 == 0);
    }
    else {
      DAT_006b2d38 = 0;
    }
  }
  else {
    DAT_006fe444 = 1;
    DAT_006fe424 = 0;
    DAT_006fe420 = 1;
    DAT_006fe428 = 1;
    DAT_006fe438 = 0;
    DAT_006fe43c = 0;
    DAT_006fe440 = 0;
    DAT_006fe42c = 1;
    DAT_006fe430 = 0;
    DAT_006fe434 = 1;
    for (local_8c = 0; local_8c < 2; local_8c = local_8c + 1) {
      for (local_90 = 0; local_90 < 0x25; local_90 = local_90 + 1) {
        *(undefined4 *)(&DAT_00696740 + local_90 * 4 + local_8c * 0x98) = 0;
      }
    }
    _DAT_00696790 = 1;
    _DAT_006967a0 = 1;
    _DAT_006967b8 = 1;
    DAT_00696830 = 1;
    _DAT_00696838 = 1;
    DAT_00696854 = 1;
    if (((byte)DAT_006fe410 & 1) == 0) {
      DAT_006fe448 = 0xffffffff;
      DAT_006fe44c = 2;
    }
  }
  return;
}



/*
 * Decompiled function: Rules_ParseFilter_0050065d
 * Entry Point: 0050065d
 * Size: 1022 bytes
 */


void Rules_ParseFilter_0050065d(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  BYTE *local_88;
  BYTE local_84 [100];
  int local_20;
  int local_1c;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a4,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_00530ba0,DAT_006fe444);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Layout_00530ba4,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bac,DAT_006fe424);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_DirectiveTracksMouse_00530bb0,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bc8,DAT_006fe420);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowCueCards_00530bcc,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bdc,DAT_006fe428);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowPowerToughnessOnCards_00530be0,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bfc,DAT_006fe42c);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowAbilitiesOnCards_00530c00,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c18,DAT_006fe438);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowIDTagsOnCards_00530c1c,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c30,DAT_006fe43c);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowInvisibleEffectCards_00530c34,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c50,DAT_006fe440);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowAllCardsSummonSickness_00530c54,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c70,DAT_006fe430);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ExpandTextBoxOnBigCard_00530c74,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c8c,DAT_006fe434);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_SeeNextDrawsAtEndOfDuel_00530c90,0,1,local_14,sVar2 + 1);
    local_88 = local_84;
    for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < 0x25; local_20 = local_20 + 1) {
        if (((&DAT_00696740)[local_20 * 4 + local_1c * 0x98] & 1) == 0) {
          *local_88 = '-';
        }
        else {
          *local_88 = 'S';
        }
        local_88 = local_88 + 1;
      }
    }
    *local_88 = '\0';
    sVar2 = strlen((char *)local_84);
    RegSetValueExA(local_18,s_PhaseStoppers_00530ca8,0,1,local_84,sVar2 + 1);
    if (((byte)DAT_006fe410 & 1) == 0) {
      wsprintfA((LPSTR)local_14,&DAT_00530cb8,DAT_006fe448);
      sVar2 = strlen((char *)local_14);
      RegSetValueExA(local_18,s_PlayerTerritoryColor_00530cbc,0,1,local_14,sVar2 + 1);
    }
    if (((byte)DAT_006fe410 & 1) == 0) {
      wsprintfA((LPSTR)local_14,&DAT_00530cd4,DAT_006fe44c);
      sVar2 = strlen((char *)local_14);
      RegSetValueExA(local_18,s_PlayerTerritoryType_00530cd8,0,1,local_14,sVar2 + 1);
    }
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}



/*
 * Decompiled function: FUN_00500a5b
 * Entry Point: 00500a5b
 * Size: 634 bytes
 */


void FUN_00500a5b(void)

{
  LSTATUS LVar1;
  HKEY local_2c;
  BYTE local_28 [32];
  DWORD local_8;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a8,0,1,
                        &local_2c);
  if (LVar1 == 0) {
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Difficulty_00530cec,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530cf8,&DAT_006fee70);
    }
    else {
      DAT_006fee70 = 1;
    }
    local_8 = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_PlayerDeck_00530cfc,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      sprintf(&DAT_006fee74,&DAT_00530d08,local_28);
    }
    else {
      DAT_006fee74 = 0;
    }
    local_8 = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_OpponentDeck_00530d0c,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      sprintf(&DAT_006fee92,&DAT_00530d1c,local_28);
    }
    else {
      DAT_006fee92 = 0;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_00530d20,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d28,&DAT_006feeb0);
    }
    else {
      DAT_006feeb0 = 1;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Match_00530d2c,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d34,&DAT_006feeb4);
    }
    else {
      DAT_006feeb4 = 1;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_00530d38,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d40,&DAT_006feeb8);
    }
    else {
      DAT_006feeb8 = 1;
    }
    RegCloseKey(local_2c);
  }
  else {
    DAT_006fee70 = 1;
    DAT_006fee74 = 0;
    DAT_006fee92 = 0;
    DAT_006feeb0 = 1;
    DAT_006feeb4 = 1;
    DAT_006feeb8 = 1;
  }
  return;
}



/*
 * Decompiled function: FUN_00500cd5
 * Entry Point: 00500cd5
 * Size: 418 bytes
 */


void FUN_00500cd5(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a8,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_00530d44,DAT_006fee70);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Difficulty_00530d48,0,1,local_14,sVar2 + 1);
    sVar2 = strlen(&DAT_006fee74);
    RegSetValueExA(local_18,s_PlayerDeck_00530d54,0,1,&DAT_006fee74,sVar2 + 1);
    sVar2 = strlen(&DAT_006fee92);
    RegSetValueExA(local_18,s_OpponentDeck_00530d60,0,1,&DAT_006fee92,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530d70,DAT_006feeb0);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,&DAT_00530d74,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530d7c,DAT_006feeb4);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Match_00530d80,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530d88,DAT_006feeb8);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,&DAT_00530d8c,0,1,local_14,sVar2 + 1);
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}



