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
  int *player;
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
  int card_idx;
  undefined8 *stack_arg;
  
  if (DAT_00566228 == 0) {
    val_5 = -0x400;
    iVar9 = -0x3fc00;
    do {
      if ((iVar9 < 0) || (0xf708 < iVar9)) {
        if (iVar9 < 0x9f6) {
          PTR_DAT_005300a0[val_5] = 0;
        }
        else {
          PTR_DAT_005300a0[val_5] = 0xff;
        }
      }
      else {
        PTR_DAT_005300a0[val_5] = (char)(iVar9 / 0xf8);
      }
      iVar9 = iVar9 + 0xff;
      val_5 = val_5 + 1;
    } while (iVar9 < 0x3fc01);
    DAT_00566228 = 1;
  }
  bVar12 = arg2 != (undefined8 *)0x0;
  if (bVar12) {
    val_5 = arg1[0x24] + 2000;
    FUN_0048aee0(arg2,(int)(val_5 + (val_5 >> 0x1f & 3U)) >> 2);
  }
  else {
    arg2 = malloc(arg1[0x24] + 2000);
    FUN_0048aee0(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  _DAT_00640f04 = Haar_DecompressHeader((int32_t *)arg2,arg1);
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
    AssertOrLog(0,0x5300d4,0x15e,s_wavelet_pieces_has_illegal_value_005300f8);
  }
  iVar9 = arg1[7] / (int)stack_arg;
  val_5 = arg1[9];
  card_idx = 0;
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
      player = (int *)((int)arg2 + (arg_8 + 0x40 + val_6 * val_6 * 2) * card_idx * 4);
      arg_1_00 = player + arg_8 + 0x20;
      Mem_AllocOrFree_004f1ec0(player,iVar9,val_5);
      Mem_AllocOrFree_004f1ec0(arg_1_00,val_6,val_5);
      Mem_AllocOrFree_004f1ec0(arg_1_00 + val_6 * val_6 + 0x20,val_6,val_5);
      if (card_idx < arg1[10] / 2) {
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
                Mem_AllocOrFree_004f21d0
                          (&DAT_005663e0,player,iVar9,arg_4,arg_1_00,arg_1_00 + val_6 * val_6 + 0x20,
                           val_6,arg_8,arg_9);
      if (arg1[10] < 2) {
        puVar4 = _Memory;
        if (!bVar12) {
          card_idx = 0x4f1c3c;
          free(arg2);
          stack_arg = arg2;
        }
      }
      else {
        puVar4 = (undefined8 *)
                 ((int)arg2 +
                 ((card_idx / (int)stack_arg) * arg_9 + card_idx % (int)stack_arg) *
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
        card_idx = 0x4f1c26;
        free(_Memory);
        puVar4 = arg2;
        stack_arg = _Memory;
      }
      arg2 = puVar4;
      card_idx = card_idx + 1;
    } while (card_idx < arg1[10]);
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
  int *i_ptr_1;
  int val_2;
  int reg_eax;
  int val_3;
  int *piVar4;
  int val_5;
  int *piVar6;
  bool in_ZF;
  char in_SF;
  char in_OF;
  int iStack0000000c;
  int *stack_arg;
  int *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  
  iStack0000000c = reg_eax;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar4 = stack_arg;
      piVar6 = stack_arg;
      while (piVar4 < stack_arg + stack_arg + -1) {
        piVar6 = piVar6 + stack_arg * 2;
        i_ptr_1 = piVar4 + 1;
        piVar4 = piVar4 + 1;
        val_2 = *stack_arg;
        val_5 = *i_ptr_1 * 0xb504;
        val_3 = val_5;
        if (val_2 != 0) {
          val_3 = val_5 + val_2 * 0xb504;
          val_5 = val_5 + val_2 * -0xb504;
        }
        stack_arg = stack_arg + 1;
        *piVar6 = val_3 >> 0x10;
        piVar6[stack_arg] = val_5 >> 0x10;
      }
      *stack_arg = (*stack_arg + *stack_arg) * 0xb504 >> 0x10;
      val_3 = *stack_arg;
      val_5 = *stack_arg;
      stack_arg = piVar4 + 1;
      stack_arg = stack_arg + 1;
      iStack0000000c = iStack0000000c + -1;
      stack_arg[stack_arg] = (val_3 - val_5) * 0xb504 >> 0x10;
      stack_arg = stack_arg + 1;
    } while (iStack0000000c != 0);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f1e20
 * Entry Point: 004f1e20
 * Size: 45 bytes
 */


void Mem_AllocOrFree_004f1e20(undefined8 *player,undefined8 *card_slot,uint32_t arg_3)

{
  uint32_t uval_1;
  
  for (uval_1 = arg_3 >> 3; uval_1 != 0; uval_1 = uval_1 - 1) {
    *player = *card_slot;
    card_slot = card_slot + 1;
    player = player + 1;
  }
  uval_1 = arg_3 & 7;
  if (uval_1 != 0) {
    for (; uval_1 != 0; uval_1 = uval_1 - 1) {
      *(uint8_t *)player = *(uint8_t *)card_slot;
      card_slot = (undefined8 *)((int)card_slot + 1);
      player = (undefined8 *)((int)player + 1);
    }
  }
  return;
}



/*
 * Decompiled function: Haar_Transform2D_Inverse
 * Entry Point: 004f1e50
 * Size: 110 bytes
 */


void Haar_Transform2D_Inverse(undefined8 *player,uint32_t card_slot,uint32_t arg_3)

{
  uint32_t uval_1;
  int val_2;
  uint32_t arg2;
  undefined8 uval_3;
  
  uval_1 = card_slot << 8 | card_slot;
  arg2 = (int)uval_1 >> 0x1f | ((int)uval_1 >> 0x1f) << 0x10 | uval_1 >> 0x10;
  uval_3 = __allshl(0x20,arg2);
  uval_3 = CONCAT44(arg2 | (uint32_t)((ulonglong)uval_3 >> 0x20),uval_1 | uval_1 << 0x10 | (uint32_t)uval_3);
  val_2 = (arg_3 >> 3) - 1;
  do {
    *player = uval_3;
    player = player + 1;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  *player = uval_3;
  for (uval_1 = arg_3 & 7; uval_1 != 0; uval_1 = uval_1 - 1) {
    *(char *)player = (char)card_slot;
    player = (undefined8 *)((int)player + 1);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f1ec0
 * Entry Point: 004f1ec0
 * Size: 11 bytes
 */


void Mem_AllocOrFree_004f1ec0(int *player,int card_slot,int event_type)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int *arg_2_00;
  int val_4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int stack_arg;
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
      val_4 = arg_3 * arg_3;
      piVar5 = player + val_4;
      piVar6 = piStack_c;
      piVar7 = player;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          i_ptr_1 = piVar6 + arg_3 * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar7;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar7 + arg_3) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[arg_3] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + arg_3 * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar6 = *piVar7 + *i_ptr_2;
          piVar6[arg_3] = *piVar7 - *i_ptr_2;
          iStack_18 = iStack_18 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = i_ptr_3;
        } while (iStack_18 != 0);
      }
      piVar5 = player + val_4 * 3;
      piVar6 = player + val_4 * 2;
      piVar7 = arg_2_00;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          i_ptr_1 = piVar7 + arg_3 * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar6;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar6 + arg_3) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[arg_3] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + arg_3 * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar7 = *piVar6 + *i_ptr_2;
          piVar7[arg_3] = *piVar6 - *i_ptr_2;
          iStack_18 = iStack_18 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = i_ptr_3;
        } while (iStack_18 != 0);
      }
      val_4 = arg_3 * 2;
      Mem_AllocOrFree_004f2110(piStack_c,arg_2_00,player,arg_3,val_4,val_4,val_4);
      arg_3 = val_4;
    } while (val_4 < stack_arg);
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
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int *card_slot;
  int val_4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  int iStack00000004;
  int *piStack00000010;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  int stack_arg;
  
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
  if (stack_arg < stack_arg) {
    do {
      val_4 = stack_arg * stack_arg;
      piVar5 = stack_arg + val_4;
      piVar6 = piStack00000010;
      piVar7 = stack_arg;
      iStack00000004 = stack_arg;
      if (0 < stack_arg) {
        do {
          i_ptr_1 = piVar6 + stack_arg * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar7;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar7 + stack_arg) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[stack_arg] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + stack_arg * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar6 = *piVar7 + *i_ptr_2;
          piVar6[stack_arg] = *piVar7 - *i_ptr_2;
          iStack00000004 = iStack00000004 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = i_ptr_3;
        } while (iStack00000004 != 0);
      }
      piVar5 = stack_arg + val_4 * 3;
      piVar6 = stack_arg + val_4 * 2;
      piVar7 = card_slot;
      iStack00000004 = stack_arg;
      if (0 < stack_arg) {
        do {
          i_ptr_1 = piVar7 + stack_arg * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar6;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar6 + stack_arg) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[stack_arg] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + stack_arg * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar7 = *piVar6 + *i_ptr_2;
          piVar7[stack_arg] = *piVar6 - *i_ptr_2;
          iStack00000004 = iStack00000004 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = i_ptr_3;
        } while (iStack00000004 != 0);
      }
      val_4 = stack_arg * 2;
      Mem_AllocOrFree_004f2110
                (piStack00000010,card_slot,stack_arg,stack_arg,val_4,val_4,val_4);
      stack_arg = val_4;
    } while (val_4 < stack_arg);
  }
  return;
}



/*
 * Decompiled function: FUN_004f207a
 * Entry Point: 004f207a
 * Size: 136 bytes
 */


void FUN_004f207a(int player_id,int32_t card_slot,int *arg_3,int *arg_4,int *arg_5,int arg_6,
                 int32_t arg_7,int32_t arg_8,int arg_9)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int reg_eax;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  player = reg_eax;
  if (!in_ZF && in_OF == in_SF) {
    do {
      i_ptr_1 = arg_5 + arg_9 * 2;
      i_ptr_2 = arg_4;
      i_ptr_3 = arg_3;
      while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < arg_3 + arg_6) {
        *i_ptr_1 = *i_ptr_2 + *i_ptr_3;
        i_ptr_1[arg_9] = *i_ptr_3 - *i_ptr_2;
        i_ptr_1 = i_ptr_1 + arg_9 * 2;
        i_ptr_2 = i_ptr_2 + 1;
      }
      arg_4 = i_ptr_2 + 1;
      *arg_5 = *i_ptr_2 + *arg_3;
      arg_5[arg_9] = *arg_3 - *i_ptr_2;
      player = player + -1;
      arg_3 = i_ptr_3;
      arg_5 = arg_5 + 1;
    } while (player != 0);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f2110
 * Entry Point: 004f2110
 * Size: 10 bytes
 */


void Mem_AllocOrFree_004f2110
               (int *player,int *card_slot,int *arg_3,int arg_4,int arg_5,int32_t arg_6,int arg_7)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int iStack_4;
  
  if (0 < arg_5) {
    iStack_4 = arg_5;
    do {
      i_ptr_1 = arg_3 + arg_7 * 2;
      i_ptr_2 = card_slot;
      i_ptr_3 = player;
      while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < player + arg_4) {
        *i_ptr_1 = *i_ptr_2 + *i_ptr_3 >> 1;
        i_ptr_1[arg_7] = *i_ptr_3 - *i_ptr_2 >> 1;
        i_ptr_1 = i_ptr_1 + arg_7 * 2;
        i_ptr_2 = i_ptr_2 + 1;
      }
      card_slot = i_ptr_2 + 1;
      *arg_3 = *i_ptr_2 + *player >> 1;
      arg_3[arg_7] = *player - *i_ptr_2 >> 1;
      iStack_4 = iStack_4 + -1;
      player = i_ptr_3;
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


void FUN_004f211a(int player_id,int32_t card_slot,int *arg_3,int *arg_4,int *arg_5,int arg_6,
                 int32_t arg_7,int32_t arg_8,int arg_9)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int reg_eax;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  player = reg_eax;
  if (!in_ZF && in_OF == in_SF) {
    do {
      i_ptr_1 = arg_5 + arg_9 * 2;
      i_ptr_2 = arg_4;
      i_ptr_3 = arg_3;
      while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < arg_3 + arg_6) {
        *i_ptr_1 = *i_ptr_2 + *i_ptr_3 >> 1;
        i_ptr_1[arg_9] = *i_ptr_3 - *i_ptr_2 >> 1;
        i_ptr_1 = i_ptr_1 + arg_9 * 2;
        i_ptr_2 = i_ptr_2 + 1;
      }
      arg_4 = i_ptr_2 + 1;
      *arg_5 = *i_ptr_2 + *arg_3 >> 1;
      arg_5[arg_9] = *arg_3 - *i_ptr_2 >> 1;
      player = player + -1;
      arg_3 = i_ptr_3;
      arg_5 = arg_5 + 1;
    } while (player != 0);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004f21d0
 * Entry Point: 004f21d0
 * Size: 11 bytes
 */


uint8_t *
Mem_AllocOrFree_004f21d0
          (uint8_t *player,int *card_slot,int event_type,int arg_4,int *arg_5,int *arg_6,int arg_7,
          int32_t arg_8,int arg_9)

{
  int val_1;
  int val_2;
  int val_3;
  uint8_t *puVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int iStack_1c;
  uint32_t uStack_18;
  int iStack_14;
  int *piStack_10;
  int *piStack_c;
  
  if (DAT_0061d7e4 == 0) {
    val_1 = -0x400;
    do {
      if (val_1 < 1) {
        PTR_DAT_005300b0[val_1] = 0;
      }
      else {
        val_2 = val_1 >> 2;
        if (0xfe < val_2) {
          val_2 = 0xff;
        }
        PTR_DAT_005300b0[val_1] = (char)val_2;
      }
      val_1 = val_1 + 1;
    } while (val_1 < 0x1c00);
    DAT_0061d7e4 = 1;
  }
  if (player == (uint8_t *)0x0) {
    player = malloc(arg_3 * arg_3 * 3 + 0x10);
  }
  iStack_14 = 0;
  if (0 < arg_4) {
    piStack_10 = arg_6;
    piStack_c = arg_5;
    puVar4 = player;
    do {
      piVar5 = piStack_c;
      piVar6 = piStack_10;
      if (arg_9 != 0) {
        val_1 = (iStack_14 / 2) * arg_7;
        piVar5 = arg_5 + val_1;
        piVar6 = arg_6 + val_1;
      }
      uStack_18 = 0;
      if (0 < arg_3) {
        do {
          val_1 = *card_slot;
          if (arg_9 == 0) {
            val_2 = *piVar6;
            val_2 = (val_2 >> 3) + (val_2 >> 1) + val_2;
            iStack_1c = *piVar5;
          }
          else {
            if ((uStack_18 & 1) == 0) {
              iStack_1c = *piVar5;
              val_2 = *piVar6;
            }
            else {
              bVar7 = arg_3 - uStack_18 != 1;
              iStack_1c = (piVar5[bVar7] + *piVar5) / 2;
              val_2 = (piVar6[bVar7] + *piVar6) / 2;
            }
            val_2 = (val_2 >> 3) + (val_2 >> 1) + val_2;
          }
          val_3 = val_2 + -0x333 + val_1;
          val_2 = val_1 + -0x400 + iStack_1c * 2;
          *puVar4 = PTR_DAT_005300b0[val_2];
          puVar4[1] = PTR_DAT_005300b0
                      [((((val_2 >> 4) - (val_1 >> 2)) - (val_2 >> 2)) - (val_3 >> 1)) + val_1 * 2];
          puVar4[2] = PTR_DAT_005300b0[val_3];
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
  return player;
}



/*
 * Decompiled function: FUN_004f21db
 * Entry Point: 004f21db
 * Size: 549 bytes
 */


uint8_t * FUN_004f21db(void)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  uint8_t *puVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  bool bVar8;
  uint32_t uStack00000004;
  int iStack00000008;
  int *piStack0000000c;
  int *piStack00000010;
  uint8_t *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  int *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  
  if (in_ZF) {
    val_2 = -0x400;
    do {
      if (val_2 < 1) {
        PTR_DAT_005300b0[val_2] = 0;
      }
      else {
        val_3 = val_2 >> 2;
        if (0xfe < val_3) {
          val_3 = 0xff;
        }
        PTR_DAT_005300b0[val_2] = (char)val_3;
      }
      val_2 = val_2 + 1;
    } while (val_2 < 0x1c00);
    DAT_0061d7e4 = 1;
  }
  if (stack_arg == (uint8_t *)0x0) {
    stack_arg = malloc(stack_arg * stack_arg * 3 + 0x10);
  }
  iStack00000008 = 0;
  if (0 < stack_arg) {
    piStack0000000c = stack_arg;
    piStack00000010 = stack_arg;
    puVar5 = stack_arg;
    do {
      piVar6 = piStack00000010;
      piVar7 = piStack0000000c;
      if (stack_arg != 0) {
        val_2 = (iStack00000008 / 2) * stack_arg;
        piVar6 = stack_arg + val_2;
        piVar7 = stack_arg + val_2;
      }
      uStack00000004 = 0;
      if (0 < stack_arg) {
        do {
          val_2 = *stack_arg;
          if (stack_arg == 0) {
            val_3 = *piVar7;
            val_3 = (val_3 >> 3) + (val_3 >> 1) + val_3;
            val_1 = *piVar6;
          }
          else {
            if ((uStack00000004 & 1) == 0) {
              val_1 = *piVar6;
              val_3 = *piVar7;
            }
            else {
              bVar8 = stack_arg - uStack00000004 != 1;
              val_1 = (piVar6[bVar8] + *piVar6) / 2;
              val_3 = (piVar7[bVar8] + *piVar7) / 2;
            }
            val_3 = (val_3 >> 3) + (val_3 >> 1) + val_3;
          }
          val_4 = val_3 + -0x333 + val_2;
          val_3 = val_2 + -0x400 + val_1 * 2;
          *puVar5 = PTR_DAT_005300b0[val_3];
          puVar5[1] = PTR_DAT_005300b0
                      [((((val_3 >> 4) - (val_2 >> 2)) - (val_3 >> 2)) - (val_4 >> 1)) + val_2 * 2];
          puVar5[2] = PTR_DAT_005300b0[val_4];
          if ((stack_arg == 0) || ((uStack00000004 & 1) != 0)) {
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          uStack00000004 = uStack00000004 + 1;
          stack_arg = stack_arg + 1;
          puVar5 = puVar5 + 3;
        } while ((int)uStack00000004 < stack_arg);
      }
      piStack0000000c = piStack0000000c + stack_arg;
      piStack00000010 = piStack00000010 + stack_arg;
      iStack00000008 = iStack00000008 + 1;
    } while (iStack00000008 < stack_arg);
  }
  return stack_arg;
}



/*
 * Decompiled function: Haar_DecompressHeader
 * Entry Point: 004f2400
 * Size: 431 bytes
 */


int32_t Haar_DecompressHeader(int32_t *arg1,int *arg2)

{
  int32_t *u_ptr_1;
  int event_type;
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
  int *loop_idx;
  int32_t *target_idx;
  int match_count;
  
  val_2 = arg2[7] / (int)(2 - (uint32_t)(arg2[10] == 1));
  val_3 = val_2 / (int)(2 - (uint32_t)(*arg2 == 0));
  val_3 = val_3 * val_3;
  val_6 = arg2[9];
  piVar7 = (int *)arg2[0x68] + 1;
  arg_3 = *(int *)arg2[0x68];
  *piVar7 = -0x80000000;
  val_4 = FUN_0048b950((uint32_t *)(piVar7 + arg_3),piVar7,arg_3);
  puVar8 = (int32_t *)((int)(piVar7 + arg_3) + val_4);
  match_count = 0;
  if (0 < arg2[10]) {
    loop_idx = arg2 + 0x17;
    target_idx = arg1;
    uVar11 = val_6 * val_6;
    do {
      u_ptr_1 = target_idx + val_2 * val_2 + 0x20;
      puVar12 = puVar8;
      puVar9 = target_idx;
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
      FUN_0048c070(target_idx + uVar11,puVar8 + uVar11,*loop_idx);
      puVar9 = (int32_t *)((int)(puVar8 + uVar11) + *loop_idx);
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
      FUN_0048c070(u_ptr_1 + uVar11,puVar10,loop_idx[4]);
      puVar9 = (int32_t *)((int)puVar10 + loop_idx[4]);
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
      FUN_0048c070(u_ptr_1 + val_3 + 0x20 + uVar11,puVar10,loop_idx[8]);
      piVar7 = loop_idx + 8;
      loop_idx = loop_idx + 1;
      puVar8 = (int32_t *)((int)puVar10 + *piVar7);
      target_idx = target_idx + val_2 * val_2 + val_3 * 2 + 0x40;
      match_count = match_count + 1;
    } while (match_count < arg2[10]);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004f27c0
 * Entry Point: 004f27c0
 * Size: 1153 bytes
 */


uint32_t * FUN_004f27c0(void)

{
  int val_1;
  int val_2;
  uint32_t *u_ptr_3;
  int val_4;
  int val_5;
  uint32_t uval_6;
  uint32_t uval_7;
  int val_8;
  int iVar9;
  int *piVar10;
  uint32_t uVar11;
  int iVar12;
  uint8_t *pbVar13;
  uint32_t *puVar14;
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
  
  Mem_AllocOrFree_00513bd0();
  if (stack_arg != (int *)0x0) {
    val_2 = stack_arg[7];
    iVar9 = stack_arg[8];
    if (stack_arg[0x6a] == 0) {
      puStack00000008 =
           (uint32_t *)Haar_DecompressWaveletImage(stack_arg,(undefined8 *)&DAT_005663e0);
    }
    else {
      puStack00000008 = (uint32_t *)stack_arg[0x6b];
    }
    uval_7 = stack_arg * 3;
    val_5 = stack_arg[7];
    val_8 = (DAT_00530068 - (int)uval_7 % DAT_00530068) % DAT_00530068;
    if (stack_arg == (uint32_t *)0x0) {
      stack_arg = (uint32_t *)&DAT_005e0be0;
    }
    val_4 = 0;
    val_1 = stack_arg;
    piVar10 = (int *)&stack0x00000024;
    if (0 < stack_arg) {
      do {
        iVar12 = val_4 >> 8;
        val_4 = val_4 + (val_2 << 0x10) / stack_arg;
        val_1 = val_1 + -1;
        *piVar10 = iVar12;
        piVar10 = piVar10 + 1;
      } while (val_1 != 0);
    }
    val_2 = stack_arg[8];
    puStack00000010 = stack_arg;
    if (val_2 < stack_arg) {
      puStack00000010 =
           (uint32_t *)((int)stack_arg + (uval_7 + val_8) * (stack_arg - val_2));
    }
    iStack0000001c = 0;
    if (0 < val_2) {
      puVar15 = puStack00000010;
      do {
        u_ptr_3 = (uint32_t *)&stack0x00000024;
        puVar14 = puVar15;
        iStack00000004 = stack_arg;
        if (0 < stack_arg) {
          do {
            pbVar13 = (uint8_t *)(((int)*u_ptr_3 >> 8) * 3 + (int)puStack00000008);
            puVar15 = (uint32_t *)((int)puVar14 + 3);
            *(uint8_t *)puVar14 =
                 (char)(((uint32_t)pbVar13[3] - (uint32_t)*pbVar13) * (*u_ptr_3 & 0xff) >> 8) + *pbVar13;
            *(uint8_t *)((int)puVar14 + 1) =
                 (char)(((uint32_t)pbVar13[4] - (uint32_t)pbVar13[1]) * (*u_ptr_3 & 0xff) >> 8) + pbVar13[1];
            *(uint8_t *)((int)puVar14 + 2) =
                 (char)(((uint32_t)pbVar13[5] - (uint32_t)pbVar13[2]) * (*u_ptr_3 & 0xff) >> 8) + pbVar13[2];
            iStack00000004 = iStack00000004 + -1;
            u_ptr_3 = u_ptr_3 + 1;
            puVar14 = puVar15;
          } while (iStack00000004 != 0);
        }
        puStack00000008 = (uint32_t *)((int)puStack00000008 + val_5 * 3);
        iStack0000001c = iStack0000001c + 1;
        puVar15 = (uint32_t *)((int)puVar15 + val_8);
      } while (iStack0000001c < stack_arg[8]);
    }
    val_5 = 0;
    val_2 = stack_arg;
    piStack00000020 = (int *)&stack0x00004024;
    if (0 < stack_arg) {
      do {
        val_1 = val_5 >> 8;
        val_5 = val_5 + (iVar9 << 0x10) / stack_arg;
        val_2 = val_2 + -1;
        *piStack00000020 = val_1;
        piStack00000020 = piStack00000020 + 1;
      } while (val_2 != 0);
    }
    uVar11 = uval_7 + val_8;
    if (stack_arg < stack_arg[8]) {
      puVar15 = (uint32_t *)((int)stack_arg + (stack_arg[8] + -1) * uVar11);
      u_ptr_3 = (uint32_t *)&stack0x00000024;
      for (uval_6 = uVar11 >> 2; uval_6 != 0; uval_6 = uval_6 - 1) {
        *u_ptr_3 = *puVar15;
        puVar15 = puVar15 + 1;
        u_ptr_3 = u_ptr_3 + 1;
      }
      for (uval_6 = uVar11 & 3; uval_6 != 0; uval_6 = uval_6 - 1) {
        *(char *)u_ptr_3 = (char)*puVar15;
        puVar15 = (uint32_t *)((int)puVar15 + 1);
        u_ptr_3 = (uint32_t *)((int)u_ptr_3 + 1);
      }
    }
    if (0 < stack_arg) {
      iStack00000004 = stack_arg;
      puStack00000008 = stack_arg;
      do {
        puVar15 = (uint32_t *)&stack0x00004024;
        u_ptr_3 = puStack00000008;
        iStack00000014 = stack_arg + -1;
        if (0 < stack_arg + -1) {
          do {
            iVar9 = (int)*puVar15 >> 8;
            val_2 = stack_arg[8] + -2;
            if (iVar9 <= stack_arg[8] + -2) {
              val_2 = iVar9;
            }
            puVar14 = (uint32_t *)(val_2 * uVar11 + (int)puStack00000010);
            *(uint8_t *)u_ptr_3 =
                 (char)(((uint32_t)*(uint8_t *)((int)puVar14 + uVar11) - (uint32_t)(uint8_t)*puVar14) *
                        (*puVar15 & 0xff) >> 8) + (uint8_t)*puVar14;
            *(uint8_t *)((int)u_ptr_3 + 1) =
                 (char)(((uint32_t)*(uint8_t *)((int)puVar14 + uVar11 + 1) -
                        (uint32_t)*(uint8_t *)((int)puVar14 + 1)) * (*puVar15 & 0xff) >> 8) +
                 *(uint8_t *)((int)puVar14 + 1);
            *(uint8_t *)((int)u_ptr_3 + 2) =
                 (char)(((uint32_t)*(uint8_t *)((int)puVar14 + uVar11 + 2) -
                        (uint32_t)*(uint8_t *)((int)puVar14 + 2)) * (*puVar15 & 0xff) >> 8) +
                 *(uint8_t *)((int)puVar14 + 2);
            iStack00000014 = iStack00000014 + -1;
            u_ptr_3 = (uint32_t *)((int)u_ptr_3 + uVar11);
            puVar15 = puVar15 + 1;
          } while (iStack00000014 != 0);
        }
        puStack00000010 = (uint32_t *)((int)puStack00000010 + 3);
        puStack00000008 = (uint32_t *)((int)puStack00000008 + 3);
        iStack00000004 = iStack00000004 + -1;
      } while (iStack00000004 != 0);
    }
    if (stack_arg < stack_arg[8]) {
      puVar15 = (uint32_t *)&stack0x00000024;
      u_ptr_3 = (uint32_t *)((int)stack_arg + (stack_arg + -1) * uVar11);
      for (uval_6 = uVar11 >> 2; uval_6 != 0; uval_6 = uval_6 - 1) {
        *u_ptr_3 = *puVar15;
        puVar15 = puVar15 + 1;
        u_ptr_3 = u_ptr_3 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(char *)u_ptr_3 = (char)*puVar15;
        puVar15 = (uint32_t *)((int)puVar15 + 1);
        u_ptr_3 = (uint32_t *)((int)u_ptr_3 + 1);
      }
    }
    else {
      puVar15 = (uint32_t *)((int)stack_arg + (stack_arg + -1) * uVar11);
      for (uval_6 = uVar11 >> 2; uval_6 != 0; uval_6 = uval_6 - 1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(uint8_t *)puVar15 = 0;
        puVar15 = (uint32_t *)((int)puVar15 + 1);
      }
    }
    uVar11 = (int)uval_7 >> 0x1f;
    uval_7 = 4 - (((uval_7 ^ uVar11) - uVar11 & 3 ^ uVar11) - uVar11);
    uVar11 = (int)uval_7 >> 0x1f;
    val_2 = ((uval_7 ^ uVar11) - uVar11 & 3 ^ uVar11) - uVar11;
    if (DAT_0052a1b8 == (uint32_t *)0x0) {
      Palette_RemapBitmapRGB(stack_arg,stack_arg,stack_arg,val_2);
    }
    else if (DAT_006ff554 == 0x10) {
      Palette_DitherScanline
                ((int)DAT_0052a1b8,DAT_0052a1bc,(int)stack_arg,stack_arg,
                 stack_arg,val_2);
    }
    else if (DAT_006ff554 == 8) {
      Palette_DitherBitmapRGB
                (DAT_0052a1b8,DAT_0052a1bc,stack_arg,stack_arg,stack_arg,
                 val_2);
    }
    return stack_arg;
  }
  return (uint32_t *)0x0;
}



/*
 * Decompiled function: FUN_004f2c50
 * Entry Point: 004f2c50
 * Size: 140 bytes
 */


int32_t FUN_004f2c50(HWND player,int y,int width,int height)

{
  uint32_t *arg_3;
  
  if (y == 0) {
    return 0;
  }
  arg_3 = (uint32_t *)FUN_004f27c0(0,y,width,height);
  Palette_DitherBitmapRGB
            (DAT_0052a1b8,DAT_0052a1bc,arg_3,height,width,
             (DAT_00530068 - (width * 3) % DAT_00530068) % DAT_00530068);
  FUN_0050ec20(player,arg_3,0,0,width,height);
  if (*(uint32_t **)(y + 0x1ac) != arg_3) {
    free(arg_3);
  }
  return 1;
}



/*
 * Decompiled function: FUN_004f2d30
 * Entry Point: 004f2d30
 * Size: 292 bytes
 */


int FUN_004f2d30(HWND hwnd,int card_slot,int event_type,int arg_4,DWORD arg_5,DWORD arg_6)

{
  uint8_t uval_1;
  int32_t *lpvBits;
  int val_2;
  BITMAPINFO *lpbmi;
  HDC hdc;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t *puVar6;
  int32_t *puVar7;
  int val_8;
  int iVar9;
  int *piVar10;
  int iVar11;
  DWORD DVar12;
  DWORD local_4;
  
  val_8 = 0;
  iVar11 = 0;
  uval_4 = arg_6 * arg_5 * 3;
  lpvBits = malloc(arg_6 * arg_5 * 3 + 8);
  puVar7 = lpvBits;
  for (uval_3 = uval_4 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (uval_4 = uval_4 & 3; uval_4 != 0; uval_4 = uval_4 - 1) {
    *(uint8_t *)puVar7 = 0;
    puVar7 = (int32_t *)((int)puVar7 + 1);
  }
  if (0 < (int)arg_6) {
    val_5 = 0;
    local_4 = arg_6;
    puVar7 = lpvBits;
    do {
      if (0 < (int)arg_5) {
        piVar10 = (int *)(card_slot + val_5 * 4);
        puVar6 = puVar7;
        iVar9 = val_8;
        DVar12 = arg_5;
        do {
          val_2 = *piVar10 >> 2;
          val_8 = val_2;
          if ((iVar9 <= val_2) && (val_8 = iVar9, iVar11 < val_2)) {
            iVar11 = val_2;
          }
          if (val_2 < 1) {
            val_2 = 0;
          }
          if (0xfe < val_2) {
            val_2 = 0xff;
          }
          uval_1 = (uint8_t)val_2;
          *(uint8_t *)((int)puVar6 + 2) = uval_1;
          piVar10 = piVar10 + 1;
          *(uint8_t *)((int)puVar6 + 1) = uval_1;
          puVar7 = (int32_t *)((int)puVar6 + 3);
          DVar12 = DVar12 - 1;
          *(uint8_t *)puVar6 = uval_1;
          puVar6 = puVar7;
          iVar9 = val_8;
        } while (DVar12 != 0);
      }
      val_5 = val_5 + arg_5;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  lpbmi = (BITMAPINFO *)FUN_0050ec90(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_8 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,lpvBits,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  Mem_AllocOrFree_0050ed10(lpbmi);
  free(lpvBits);
  return val_8;
}



/*
 * Decompiled function: UI_DeckDialogProc_004f2e60
 * Entry Point: 004f2e60
 * Size: 246 bytes
 */


int32_t UI_DeckDialogProc_004f2e60(char *filepath,char *mode_str,int32_t *arg_3)

{
  INT_PTR IVar1;
  int32_t local_21c;
  char local_214 [261];
  char local_10f [263];
  int32_t slot_idx;
  
  slot_idx = *arg_3;
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdd,g_MainAppHwnd,UI_DialogProc_004f2f56,
                          (LPARAM)local_214);
  if (IVar1 == -1) {
    MessageBoxA(g_MainAppHwnd,s_Couldn_t_bring_up_the_Load_Decks_00530124,&DAT_00530120,0);
    local_21c = 0;
  }
  else if (IVar1 == 1) {
    strcpy(str_1,local_214);
    strcpy(str_2,local_10f);
    *arg_3 = slot_idx;
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
 * Decompiled function: UI_DialogProc_004f2f56
 * Entry Point: 004f2f56
 * Size: 1561 bytes
 */


HGDIOBJ UI_DialogProc_004f2f56(HWND hwnd,uint32_t y,HDC hdc,HWND param_4)

{
  size_t len_1;
  int val_2;
  HWND pHVar3;
  UINT UVar4;
  HGDIOBJ pvVar5;
  HBRUSH hbr;
  tagRECT local_334;
  HWND local_324;
  int local_320;
  HDC local_31c;
  WPARAM local_314;
  uint8_t local_310 [32];
  char local_2f0 [264];
  char local_1e8 [264];
  HWND local_e0;
  int local_dc;
  char local_d8 [200];
  WPARAM card_idx;
  FILE *match_count;
  char *slot_idx;
  
  if (y < 0x111) {
    if (y == 0x110) {
      DAT_0061d7e8 = param_4;
      local_e0 = CreateWindowExA(0,s_LISTBOX_00530150,&DAT_0053014c,0x40a00003,0,0,0,0,hwnd,
                                 (HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (local_e0 == (HWND)0x0) {
        EndDialog(hwnd,-1);
        return (HGDIOBJ)0x1;
      }
      strcpy(local_1e8,&g_PlayDeckDirectory);
      strcat(local_1e8,s____DCK_00530158);
      SendMessageA(local_e0,0x18d,0,(LPARAM)local_1e8);
      local_dc = SendMessageA(local_e0,0x18b,0,0);
      for (card_idx = 0; (int)card_idx < local_dc; card_idx = card_idx + 1) {
        SendMessageA(local_e0,0x189,card_idx,(LPARAM)local_1e8);
        strcpy(local_2f0,&g_PlayDeckDirectory);
        strcat(local_2f0,&DAT_00530160);
        strcat(local_2f0,local_1e8);
        match_count = fopen(local_2f0,&DAT_00530164);
        if (match_count != (FILE *)0x0) {
          local_d8[0] = '\0';
          len_1 = strlen(local_d8);
          slot_idx = local_d8 + len_1;
          while( true ) {
            val_2 = fgetc(match_count);
            *slot_idx = (char)val_2;
            if (*slot_idx == '\n') break;
            slot_idx = slot_idx + 1;
          }
          *slot_idx = '\0';
          fclose(match_count);
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
      if (((uint32_t)hdc & 0xffff) == 0x3ef) {
        FUN_004ff450(g_MainAppHwnd);
        pHVar3 = GetDlgItem(hwnd,1);
        SetFocus(pHVar3);
      }
      else if (((uint32_t)hdc & 0xffff) == 1) {
        local_314 = SendDlgItemMessageA(hwnd,1000,0x147,0,0);
        SendDlgItemMessageA(hwnd,1000,0x148,local_314,(LPARAM)local_310);
        sprintf((char *)DAT_0061d7e8,s__s__s_dck_00530168,&g_PlayDeckDirectory,local_310);
        local_314 = SendDlgItemMessageA(hwnd,0x3e9,0x147,0,0);
        SendDlgItemMessageA(hwnd,0x3e9,0x148,local_314,(LPARAM)local_310);
        sprintf((char *)((int)&DAT_0061d7e8[0x41].unused + 1),s__s__s_dck_00530174,&g_PlayDeckDirectory,
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
      else if (((uint32_t)hdc & 0xffff) == 0x471) {
        SaveGame_LoadCampaignFile(1);
        g_IsAiThinking = 0xfffffffe;
        EndDialog(hwnd,0);
      }
      else if (((uint32_t)hdc & 0xffff) == 0x472) {
        SaveGame_LoadCampaignFile(0);
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


int32_t FUN_004f3579(int player_id)

{
  uint8_t flag_1;
  int val_2;
  int val_3;
  int local_30;
  int local_28;
  int color_idx;
  int32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  local_28 = 0;
  card_idx = 0;
  local_30 = 0;
  slot_idx = 0;
  if (player == -1) {
    for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
      if ((*(int *)(&deck + color_idx * 4) != -1) && (((&DAT_00702151)[color_idx * 4] & 0xc0) == 0)) {
        flag_1 = (&g_MasterCardColorTable)[(*(uint32_t *)(&deck + color_idx * 4) & 0xfff) * 0x34];
        if ((flag_1 & 2) != 0) {
          slot_idx = slot_idx + 1;
        }
        if ((flag_1 & 0x20) != 0) {
          local_30 = local_30 + 1;
        }
        if ((flag_1 & 8) != 0) {
          card_idx = card_idx + 1;
        }
        if ((flag_1 & 0x10) != 0) {
          local_28 = local_28 + 1;
        }
        if ((flag_1 & 4) != 0) {
          match_count = match_count + 1;
        }
      }
    }
  }
  else {
    for (color_idx = 0; color_idx < 0x50; color_idx = color_idx + 1) {
      val_2 = *(int *)(&DAT_00516cbc + color_idx * 8 + player * 0x280);
      if ((*(int *)(&DAT_00516cb8 + color_idx * 8 + player * 0x280) != -1) && (val_2 != 0)) {
        val_3 = CardTypeFromID(*(int *)(&DAT_00516cb8 + color_idx * 8 + player * 0x280));
        flag_1 = (&g_MasterCardColorTable)[val_3 * 0x34];
        if ((flag_1 & 2) != 0) {
          slot_idx = slot_idx + val_2;
        }
        if ((flag_1 & 0x20) != 0) {
          local_30 = local_30 + val_2;
        }
        if ((flag_1 & 8) != 0) {
          card_idx = card_idx + val_2;
        }
        if ((flag_1 & 0x10) != 0) {
          local_28 = local_28 + val_2;
        }
        if ((flag_1 & 4) != 0) {
          match_count = match_count + val_2;
        }
      }
    }
  }
  player_idx = 0;
  if ((((slot_idx < local_30) || (slot_idx < card_idx)) || (slot_idx < local_28)) ||
     (slot_idx < match_count)) {
    if (((local_30 < slot_idx) || (local_30 < card_idx)) ||
       ((local_30 < local_28 || (local_30 < match_count)))) {
      if (((card_idx < slot_idx) || (card_idx < local_30)) ||
         ((card_idx < local_28 || (card_idx < match_count)))) {
        if ((((local_28 < slot_idx) || (local_28 < card_idx)) || (local_28 < local_30)) ||
           (local_28 < match_count)) {
          if (((slot_idx <= match_count) && (card_idx <= match_count)) &&
             ((local_28 <= match_count && (local_30 <= match_count)))) {
            player_idx = 2;
          }
        }
        else {
          player_idx = 4;
        }
      }
      else {
        player_idx = 3;
      }
    }
    else {
      player_idx = 5;
    }
  }
  else {
    player_idx = 1;
  }
  return player_idx;
}



/*
 * Decompiled function: FUN_004f3880
 * Entry Point: 004f3880
 * Size: 93 bytes
 */


bool FUN_004f3880(void)

{
  if (DAT_00530180 == 0) {
    FUN_004f39a4(10,10,&DAT_00530180,(BITMAPINFO *)0x0,&DAT_0061d7f0,(int32_t *)0x0,(int *)0x0);
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


void FUN_004f391e(char *filepath)

{
  char *char_ptr_1;
  
  GetModuleFileNameA((HMODULE)0x0,str_1,0x105);
  char_ptr_1 = strrchr(str_1,0x5c);
  *char_ptr_1 = '\0';
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


int32_t
FUN_004f39a4(int32_t player,int card_slot,int32_t *arg_3,BITMAPINFO *arg_4,int32_t *arg_5,
            int32_t *arg_6,int *arg_7)

{
  int32_t uval_1;
  HDC hdc;
  HBITMAP local_44;
  HDC local_3c;
  BITMAPINFO local_38;
  HGDIOBJ match_count;
  void *slot_idx;
  
  local_3c = (HDC)0x0;
  local_44 = (HBITMAP)0x0;
  slot_idx = (void *)0x0;
  if ((arg_3 == (int32_t *)0x0) || (arg_5 == (int32_t *)0x0)) {
    uval_1 = 0;
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
        FUN_005017f0((int32_t *)arg_4,player,card_slot);
        local_38.bmiHeader.biBitCount = 0x20;
        local_44 = CreateDIBSection(hdc,arg_4,0,&slot_idx,(HANDLE)0x0,0);
        match_count = SelectObject(local_3c,local_44);
        GDI_RealizeAndFlushPalette_Magic(local_3c);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    if (((local_3c == (HDC)0x0) || (local_44 == (HBITMAP)0x0)) || (slot_idx == (void *)0x0)) {
      if (local_3c != (HDC)0x0) {
        DeleteDC(local_3c);
      }
      if (local_44 != (HBITMAP)0x0) {
        DeleteObject(local_44);
      }
      uval_1 = 0;
    }
    else {
      if (arg_3 != (int32_t *)0x0) {
        *arg_3 = local_3c;
      }
      if (arg_5 != (int32_t *)0x0) {
        *arg_5 = local_44;
      }
      if (arg_6 != (int32_t *)0x0) {
        *arg_6 = match_count;
      }
      if (arg_7 != (int *)0x0) {
        *arg_7 = (int)slot_idx;
      }
      uval_1 = 1;
    }
  }
  return uval_1;
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


int32_t FUN_004f3b5f(int player_id,int card_slot,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t color_idx [4];
  int target_idx;
  int player_idx;
  
  if (((player == 0) || (card_slot == 0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    GetObjectA(arg_3,0x18,color_idx);
    uval_1 = FUN_004f3bc7((HDC)player,(int *)card_slot,arg_3,0,0,target_idx,player_idx);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f3bc7
 * Entry Point: 004f3bc7
 * Size: 330 bytes
 */


int32_t FUN_004f3bc7(HDC hdc,int *card_slot,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int32_t uval_1;
  HGDIOBJ h;
  int local_2c;
  uint8_t local_28 [4];
  int local_24;
  int loop_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    h = SelectObject(DAT_00530180,arg_3);
    GetObjectA(arg_3,0x18,local_28);
    slot_idx = *card_slot;
    match_count = card_slot[1];
    if (card_slot[2] < *card_slot) {
      card_idx = local_24;
    }
    else {
      card_idx = card_slot[2] - *card_slot;
    }
    if (card_slot[3] < card_slot[1]) {
      local_2c = loop_idx;
    }
    else {
      local_2c = card_slot[3] - card_slot[1];
    }
    GDI_RealizeAndFlushPalette_Magic(DAT_00530180);
    if (arg_7 <= loop_idx) {
      loop_idx = arg_7;
    }
    if (arg_6 <= local_24) {
      local_24 = arg_6;
    }
    StretchBlt(hdc,slot_idx,match_count,card_idx,local_2c,DAT_00530180,arg_4,arg_5,local_24,loop_idx,
               0xcc0020);
    SelectObject(DAT_00530180,h);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f3d11
 * Entry Point: 004f3d11
 * Size: 280 bytes
 */


int32_t FUN_004f3d11(HDC hdc,int *card_slot,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t local_38 [4];
  int local_34;
  int local_30;
  tagRECT loop_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    match_count = SaveDC(hdc);
    IntersectClipRect(hdc,*card_slot,card_slot[1],card_slot[2],card_slot[3]);
    GetObjectA(arg_3,0x18,local_38);
    for (slot_idx = *card_slot; slot_idx < card_slot[2]; slot_idx = slot_idx + local_34) {
      for (card_idx = card_slot[1]; card_idx < card_slot[3]; card_idx = card_idx + local_30) {
        SetRect(&loop_idx,slot_idx,card_idx,slot_idx + -1,card_idx + -1);
        FUN_004f3bc7(hdc,&loop_idx.left,arg_3,0,0,local_34,local_30);
      }
    }
    RestoreDC(hdc,match_count);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f3e29
 * Entry Point: 004f3e29
 * Size: 129 bytes
 */


int32_t FUN_004f3e29(HDC player,int *card_slot,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t local_34 [4];
  int local_30;
  int local_2c;
  int color_idx;
  int target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  int slot_idx;
  
  GetObjectA(arg_3,0x18,local_34);
  target_idx = local_30 / 2;
  color_idx = local_2c;
  card_idx = 0;
  match_count = 0;
  player_idx = 0;
  slot_idx = target_idx;
  uval_1 = FUN_004f3eaa(player,card_slot,arg_3,target_idx,local_2c,0,0,target_idx,0);
  return uval_1;
}



/*
 * Decompiled function: FUN_004f3eaa
 * Entry Point: 004f3eaa
 * Size: 379 bytes
 */


int32_t
FUN_004f3eaa(HDC hdc,int *card_slot,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9)

{
  int32_t uval_1;
  int local_30;
  uint8_t local_2c [24];
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    card_idx = SaveDC(hdc);
    SelectObject(DAT_00530180,arg_3);
    GetObjectA(arg_3,0x18,local_2c);
    slot_idx = *card_slot;
    match_count = card_slot[1];
    if (card_slot[2] < *card_slot) {
      player_idx = arg_4;
    }
    else {
      player_idx = card_slot[2] - *card_slot;
    }
    if (card_slot[3] < card_slot[1]) {
      local_30 = arg_5;
    }
    else {
      local_30 = card_slot[3] - card_slot[1];
    }
    GDI_RealizeAndFlushPalette_Magic(DAT_00530180);
    StretchBlt(hdc,slot_idx,match_count,player_idx,local_30,DAT_00530180,arg_8,arg_9,arg_4,arg_5,0x8800c6);
    GDI_RealizeAndFlushPalette_Magic(DAT_00530180);
    StretchBlt(hdc,slot_idx,match_count,player_idx,local_30,DAT_00530180,arg_6,arg_7,arg_4,arg_5,0xee0086);
    RestoreDC(hdc,card_idx);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_LoadDIBSection
 * Entry Point: 004f4025
 * Size: 193 bytes
 */


int32_t Pic_LoadDIBSection(int32_t player,LPCSTR str_2,void *arg_3,int32_t arg_4)

{
  char local_208 [500];
  int32_t player_idx;
  HGLOBAL card_idx;
  BITMAPINFO *match_count;
  HRSRC slot_idx;
  
  player_idx = 0;
  slot_idx = FindResourceA(g_AppHInstance,str_2,(LPCSTR)0x2);
  if (slot_idx != (HRSRC)0x0) {
    card_idx = LoadResource(g_AppHInstance,slot_idx);
    if (card_idx != (HGLOBAL)0x0) {
      match_count = LockResource(card_idx);
      if (match_count != (BITMAPINFO *)0x0) {
        player_idx = FUN_004f41e7(match_count,arg_3);
      }
    }
  }
  if (DAT_006b157c != 0) {
    sprintf(local_208,s__08X_LoadDIBSection___s__005301c4,player_idx,str_2);
    OutputDebugStringA(local_208);
  }
  return player_idx;
}



/*
 * Decompiled function: Pic_LoadDIBSectionFromFile
 * Entry Point: 004f40e6
 * Size: 257 bytes
 */


int32_t Pic_LoadDIBSectionFromFile(LPCSTR str_1,void *card_slot,int32_t arg_3)

{
  char local_20c [500];
  int32_t target_idx;
  HANDLE player_idx;
  HANDLE card_idx;
  LPVOID match_count;
  BITMAPINFO *slot_idx;
  
  target_idx = 0;
  player_idx = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  if (player_idx != (HANDLE)0xffffffff) {
    card_idx = CreateFileMappingA(player_idx,(LPSECURITY_ATTRIBUTES)0x0,0x8000000,0,0,(LPCSTR)0x0);
    if (card_idx != (HANDLE)0x0) {
      match_count = MapViewOfFile(card_idx,4,0,0,0);
      if (match_count != (LPVOID)0x0) {
        slot_idx = (BITMAPINFO *)((int)match_count + 0xe);
        target_idx = FUN_004f41e7(slot_idx,card_slot);
        UnmapViewOfFile(slot_idx);
      }
      CloseHandle(card_idx);
    }
    CloseHandle(player_idx);
  }
  if (DAT_006b157c != 0) {
    sprintf(local_20c,s__08X_LoadDIBSectionFromFile___s__005301e0,target_idx,str_1);
    OutputDebugStringA(local_20c);
  }
  return target_idx;
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
  void *card_idx;
  DWORD match_count;
  int slot_idx;
  
  local_2c = (HBITMAP)0x0;
  WVar1 = (arg1->bmiHeader).biBitCount;
  if (WVar1 == 1) {
    slot_idx = 2;
  }
  else if (WVar1 == 4) {
    slot_idx = 0x10;
  }
  else if (WVar1 == 8) {
    slot_idx = 0x100;
  }
  else {
    slot_idx = 0;
  }
  lpBits = &arg1->bmiColors[slot_idx + -10].rgbBlue + (arg1->bmiHeader).biSize;
  lpbmi = malloc(slot_idx * 4 + 0x28);
  if (lpbmi != (BITMAPINFO *)0x0) {
    memcpy(lpbmi,arg1,0x28);
    memcpy(lpbmi->bmiColors,arg1->bmiColors,slot_idx << 2);
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
    match_count = (arg1->bmiHeader).biSizeImage;
    DVar2 = match_count;
    if ((int)match_count <= (int)local_28) {
      DVar2 = local_28;
    }
    hSection = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                  DVar2 + 1000,(LPCSTR)0x0);
    if (hSection != (HANDLE)0x0) {
      hdc = GetDC((HWND)0x0);
      GDI_RealizeAndFlushPalette_Magic(hdc);
      (lpbmi->bmiHeader).biSizeImage = local_28;
      (lpbmi->bmiHeader).biCompression = 0;
      if (slot_idx == 0) {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&card_idx,hSection,0);
      }
      else {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&card_idx,hSection,0);
      }
      (lpbmi->bmiHeader).biSizeImage = match_count;
      if (local_2c == (HBITMAP)0x0) {
        CloseHandle(hSection);
      }
      else {
        if (slot_idx == 0) {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        else {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        if (arg2 != (void *)0x0) {
          memcpy(arg2,arg1,0x28);
          memcpy((void *)((int)arg2 + 0x28),arg1->bmiColors,slot_idx << 2);
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
 * Decompiled function: Pic_DestroyDIBSection
 * Entry Point: 004f4548
 * Size: 146 bytes
 */


void Pic_DestroyDIBSection(HANDLE player)

{
  char local_254 [500];
  HANDLE local_60;
  uint8_t local_5c [20];
  int local_48;
  HANDLE card_idx;
  int match_count;
  int slot_idx;
  
  if (player != (HANDLE)0x0) {
    GetObjectA(player,0x54,local_5c);
    local_60 = card_idx;
    slot_idx = local_48 + match_count;
    DeleteObject(player);
    if (local_60 != (HANDLE)0x0) {
      CloseHandle(local_60);
    }
  }
  if (DAT_006b157c != 0) {
    sprintf(local_254,s__08x_DestroyDIBSection__file_map_00530204,player,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}



/*
 * Decompiled function: Palette_LoadDuelPalette
 * Entry Point: 004f45da
 * Size: 753 bytes
 */


int32_t Palette_LoadDuelPalette(void)

{
  UINT UVar1;
  PALETTEENTRY local_628;
  char local_624 [264];
  int32_t local_51c;
  UINT local_514;
  char local_510 [264];
  LOGPALETTE *local_408;
  tagPALETTEENTRY local_404 [256];
  
  local_51c = 1;
  strcpy(local_624,&g_GameInstallDirectory);
  strcat(local_624,s__DUELPALall_TR_00530234);
  strcpy(local_510,&g_GameInstallDirectory);
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


void FUN_004f48f1(int player_id,int card_slot,RECT *arg_3)

{
  int arg_3_00;
  int val_1;
  int32_t arg_6;
  int32_t uval_2;
  uint32_t arg_2_00;
  int local_28;
  tagRECT player_idx;
  
  if (((player != 0) && (card_slot != 0)) && (arg_3 != (RECT *)0x0)) {
    CopyRect(&player_idx,arg_3);
    arg_3_00 = *(int *)(player + 4);
    arg_2_00 = (uint32_t)*(uint16_t *)(player + 0xe);
    while( true ) {
      player_idx.bottom = player_idx.bottom + -1;
      player_idx.right = player_idx.right + -1;
      if (player_idx.right <= player_idx.left) break;
      for (local_28 = player_idx.left; local_28 < player_idx.right; local_28 = local_28 + 1) {
        val_1 = local_28 - player_idx.left;
        arg_6 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,player_idx.left + val_1,player_idx.top);
        uval_2 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,player_idx.left,player_idx.bottom - val_1);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,player_idx.left + val_1,player_idx.top,uval_2);
        uval_2 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,player_idx.right - val_1,player_idx.bottom);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,player_idx.left,player_idx.bottom - val_1,uval_2);
        uval_2 = FUN_004f5f20(card_slot,arg_2_00,arg_3_00,player_idx.right,player_idx.top + val_1);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,player_idx.right - val_1,player_idx.bottom,uval_2);
        FUN_004f6060(card_slot,arg_2_00,arg_3_00,player_idx.right,player_idx.top + val_1,arg_6);
      }
      player_idx.left = player_idx.left + 1;
      player_idx.top = player_idx.top + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004f4a92
 * Entry Point: 004f4a92
 * Size: 591 bytes
 */


void FUN_004f4a92(char *filepath,char *mode_str,int width,char *str_4)

{
  char cVar1;
  size_t len_2;
  int val_3;
  int *piVar4;
  uint32_t local_20c;
  int local_208;
  char local_204 [500];
  size_t card_idx;
  int match_count;
  char *slot_idx;
  
  if (((((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) && (str_4 != (char *)0x0)) &&
      ((len_2 = strlen(str_1), len_2 != 0 && (len_2 = strlen(str_2), len_2 != 0)))) &&
     (len_2 = strlen(str_4), len_2 != 0)) {
    card_idx = strlen(str_2);
    slot_idx = str_1;
    local_204[0] = '\0';
    local_208 = 0;
    while (*slot_idx != '\0') {
      match_count = 0;
      if (((width != 0) && (val_3 = strncmp(slot_idx,str_2,card_idx), val_3 == 0)) ||
         ((width == 0 && (val_3 = _strnicmp(slot_idx,str_2,card_idx), val_3 == 0)))) {
        if (slot_idx[card_idx] == '\0') {
          match_count = 1;
        }
        else if (slot_idx[card_idx] == 's') {
          match_count = 1;
        }
        else if (slot_idx[card_idx] == '.') {
          match_count = 1;
        }
        else if (slot_idx[card_idx] == ' ') {
          piVar4 = (int *)__p___mb_cur_max();
          if (*piVar4 < 2) {
            cVar1 = slot_idx[card_idx + 1];
            piVar4 = (int *)__p__pctype();
            local_20c = *(uint16_t *)(*piVar4 + cVar1 * 2) & 1;
          }
          else {
            local_20c = _isctype((int)slot_idx[card_idx + 1],1);
          }
          if (local_20c == 0) {
            match_count = 1;
          }
        }
      }
      if (match_count == 0) {
        local_204[local_208] = *slot_idx;
        slot_idx = slot_idx + 1;
        local_204[local_208 + 1] = '\0';
        local_208 = local_208 + 1;
      }
      else {
        strcat(local_204,str_4);
        len_2 = strlen(str_4);
        slot_idx = slot_idx + card_idx;
        local_208 = local_208 + len_2;
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


int FUN_004f4ce1(char *filepath,char *mode_str,int event_type)

{
  char cVar1;
  bool flag_2;
  size_t len_3;
  int val_4;
  int *piVar5;
  uint32_t target_idx;
  int player_idx;
  char *slot_idx;
  
  if ((((str_1 == (char *)0x0) || (str_2 == (char *)0x0)) || (len_3 = strlen(str_1), len_3 == 0)) ||
     (len_3 = strlen(str_2), len_3 == 0)) {
    return -1;
  }
  len_3 = strlen(str_2);
  slot_idx = str_1;
  player_idx = 0;
  flag_2 = false;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if ((*slot_idx == '\0') || (flag_2)) {
              if (!flag_2) {
                return -1;
              }
              return player_idx;
            }
            if (((arg_3 != 0) && (val_4 = strncmp(slot_idx,str_2,len_3), val_4 == 0)) ||
               ((arg_3 == 0 && (val_4 = _strnicmp(slot_idx,str_2,len_3), val_4 == 0)))) break;
            slot_idx = slot_idx + 1;
            player_idx = player_idx + 1;
          }
          if (slot_idx[len_3] != 's') break;
          flag_2 = true;
        }
        if (slot_idx[len_3] != '.') break;
        flag_2 = true;
      }
      if (slot_idx[len_3] == ' ') break;
LAB_004f4e77:
      slot_idx = slot_idx + 1;
      player_idx = player_idx + 1;
    }
    piVar5 = (int *)__p___mb_cur_max();
    if (*piVar5 < 2) {
      cVar1 = slot_idx[len_3 + 1];
      piVar5 = (int *)__p__pctype();
      target_idx = *(uint16_t *)(*piVar5 + cVar1 * 2) & 1;
    }
    else {
      target_idx = _isctype((int)slot_idx[len_3 + 1],1);
    }
    if (target_idx != 0) goto LAB_004f4e77;
    flag_2 = true;
  } while( true );
}



/*
 * Decompiled function: FUN_004f4eb3
 * Entry Point: 004f4eb3
 * Size: 261 bytes
 */


int FUN_004f4eb3(HWND hwnd,char *mode_str)

{
  int val_1;
  HGDIOBJ h;
  HDC hdc;
  char local_104 [200];
  tagTEXTMETRICA local_3c;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
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
    val_1 = Palette_Subsystem_0049dcd5(hdc,local_104);
    GetTextMetricsA(hdc,&local_3c);
    val_1 = val_1 + local_3c.tmHeight * 3;
    ReleaseDC(hwnd,hdc);
  }
  return val_1;
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


int32_t FUN_004f5048(char *filepath,COLORREF card_slot,HBRUSH arg_3)

{
  HDC hdc;
  size_t c;
  tagRECT player_idx;
  
  SetRect(&player_idx,0,0x23f,0x8c,0x26c);
  if (DAT_00530184 != 0xffffffff) {
    hdc = CreateDCA(s_DISPLAY_00530254,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
    SetTextColor(hdc,card_slot);
    SetBkMode(hdc,1);
    FillRect(hdc,&player_idx,arg_3);
    c = strlen(str_1);
    TextOutA(hdc,player_idx.left + 5,player_idx.top + 5,str_1,c);
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


void FUN_004f5107(int player_id,HBRUSH card_slot,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  HGDIOBJ h;
  size_t c;
  tagSIZE *psizl;
  RECT local_64;
  HGDIOBJ local_54;
  tagRECT local_50;
  CHAR local_40 [52];
  tagSIZE match_count;
  
  hdc = *(HDC *)(player + 0x18);
  CopyRect(&local_50,(RECT *)(player + 0x1c));
  GetWindowTextA(*(HWND *)(player + 0x14),local_40,0x32);
  GDI_RealizeAndFlushPalette_Magic(hdc);
  OffsetRect(&local_50,-*(int *)(player + 0x1c),-*(int *)(player + 0x20));
  if ((*(uint8_t *)(player + 0x10) & 1) == 0) {
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
  local_54 = (HGDIOBJ)SendMessageA(*(HWND *)(player + 0x14),0x31,0,0);
  SelectObject(hdc,local_54);
  DrawTextA(hdc,local_40,-1,&local_50,0x25);
  if ((arg_6 != 0) && ((*(uint8_t *)(player + 0x10) & 0x10) != 0)) {
    psizl = &match_count;
    c = strlen(local_40);
    GetTextExtentPoint32A(hdc,local_40,c,psizl);
    local_64.left = ((local_50.right - local_50.left) / 2 - match_count.cx / 2) + -3;
    local_64.right = match_count.cx + local_64.left + 6;
    local_64.top = ((local_50.bottom - local_50.top) / 2 - match_count.cy / 2) + -3;
    local_64.bottom = match_count.cy + local_64.top + 6;
    DrawFocusRect(hdc,&local_64);
  }
  return;
}



/*
 * Decompiled function: FUN_004f54d5
 * Entry Point: 004f54d5
 * Size: 567 bytes
 */


void FUN_004f54d5(int player_id,HANDLE card_slot,HANDLE arg_3,HANDLE arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  size_t c;
  tagSIZE *psizl;
  RECT local_f8;
  HGDIOBJ local_e8;
  tagRECT local_e4;
  CHAR local_d4 [200];
  tagSIZE match_count;
  
  hdc = *(HDC *)(player + 0x18);
  CopyRect(&local_e4,(RECT *)(player + 0x1c));
  GetWindowTextA(*(HWND *)(player + 0x14),local_d4,200);
  GDI_RealizeAndFlushPalette_Magic(hdc);
  OffsetRect(&local_e4,-*(int *)(player + 0x1c),-*(int *)(player + 0x20));
  if ((*(uint8_t *)(player + 0x10) & 1) == 0) {
    if (((*(uint8_t *)(player + 0x10) & 4) == 0) && ((*(uint8_t *)(player + 0x10) & 2) == 0)) {
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
  local_e8 = (HGDIOBJ)SendMessageA(*(HWND *)(player + 0x14),0x31,0,0);
  SelectObject(hdc,local_e8);
  DrawTextA(hdc,local_d4,-1,&local_e4,0x25);
  if ((arg_6 != 0) && ((*(uint8_t *)(player + 0x10) & 0x10) != 0)) {
    psizl = &match_count;
    c = strlen(local_d4);
    GetTextExtentPoint32A(hdc,local_d4,c,psizl);
    local_f8.left = ((local_e4.right - local_e4.left) / 2 - match_count.cx / 2) + -3;
    local_f8.right = match_count.cx + local_f8.left + 6;
    local_f8.top = ((local_e4.bottom - local_e4.top) / 2 - match_count.cy / 2) + -3;
    local_f8.bottom = match_count.cy + local_f8.top + 6;
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


int32_t FUN_004f5728(HWND hwnd)

{
  int val_1;
  
  val_1 = FUN_004f589e(hwnd);
  if (val_1 != 0) {
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
  int val_1;
  HWND hWnd;
  UINT Msg;
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  if ((y == 7) || (y == 8)) {
    if (y == 7) {
      match_count = hwnd;
      card_idx = param_3;
    }
    else {
      card_idx = hwnd;
      match_count = param_3;
    }
    val_1 = FUN_004f589e(match_count);
    if (val_1 == 0) {
      match_count = (HWND)0x0;
    }
    val_1 = FUN_004f589e(card_idx);
    if (val_1 == 0) {
      card_idx = (HWND)0x0;
    }
    Msg = 0x4c8;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,(WPARAM)match_count,(LPARAM)card_idx);
    slot_idx = 0;
  }
  else if ((y == 0x311) || ((y == 0x310 || (y == 0x30f)))) {
    slot_idx = CallWindowProcA(DAT_0063eedc,hwnd,y,(WPARAM)param_3,arg_4);
    GDI_RealizePaletteTree_Magic(hwnd,y,param_3,arg_4);
  }
  else {
    slot_idx = CallWindowProcA(DAT_0063eedc,hwnd,y,(WPARAM)param_3,arg_4);
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004f589e
 * Entry Point: 004f589e
 * Size: 72 bytes
 */


bool FUN_004f589e(HWND hwnd)

{
  int val_1;
  CHAR local_68 [100];
  
  GetClassNameA(hwnd,local_68,100);
  val_1 = strcmp(local_68,s_Button_0053025c);
  return val_1 == 0;
}



/*
 * Decompiled function: FUN_004f58eb
 * Entry Point: 004f58eb
 * Size: 268 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * FUN_004f58eb(char *filepath,int arg2)

{
  char local_6c [100];
  UINT slot_idx;
  
  memcpy(&DAT_0061d7f8,&DAT_00530188,0x3c);
  strcpy(local_6c,&DAT_00530264);
  strcat(local_6c,str_1);
  _DAT_0061d7f8 = GetPrivateProfileIntA(s_Fonts_0053026c,local_6c,0x14,&g_DuelDatFilePath);
  strcpy(local_6c,&DAT_00530274);
  strcat(local_6c,str_1);
  slot_idx = GetPrivateProfileIntA(s_Fonts_0053027c,local_6c,0,&g_DuelDatFilePath);
  if (slot_idx != 0) {
    _DAT_0061d808 = 700;
  }
  if (arg2 != 0) {
    DAT_0061d80c = 1;
  }
  strcpy(local_6c,&DAT_00530284);
  strcat(local_6c,str_1);
  GetPrivateProfileStringA
            (s_Fonts_0053029c,local_6c,s_MS_Sans_Serif_0053028c,&DAT_0061d814,0x20,&g_DuelDatFilePath);
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
  bool flag_1;
  BOOL BVar2;
  int val_3;
  int local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  int loop_idx;
  int32_t color_idx;
  int32_t target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = g_AiPlayerHandDifferential;
  match_count = DAT_007006b0;
  card_idx = DAT_006fe3fc;
  player_idx = g_AiDecisionMatrix_Row;
  target_idx = DAT_006b2e24;
  color_idx = g_AiLookaheadTreeRoot;
  loop_idx = g_AiDuelTurnState;
  flag_1 = false;
  local_2c = g_MainAppHwnd;
  local_34 = -1;
  while (local_2c != (HWND)0x0) {
    local_2c = GetWindow(local_2c,3);
    local_30 = 0;
    local_28 = -1;
    while ((local_30 < 7 && (local_28 == -1))) {
      if ((HWND)(&loop_idx)[local_30] == local_2c) {
        local_28 = local_30;
      }
      local_30 = local_30 + 1;
    }
    if ((local_28 != -1) && (BVar2 = IsWindowVisible(local_2c), BVar2 != 0)) {
      if (local_28 < local_34) {
        flag_1 = true;
      }
      local_34 = local_28;
    }
  }
  if ((flag_1) && (val_3 = FUN_004f5b76((int)&loop_idx,7), val_3 != -1)) {
    SetWindowPos((HWND)(&loop_idx)[val_3],(HWND)0x1,0,0,0,0,3);
    if (val_3 + 1 < 7) {
      local_3c = (int)&color_idx + val_3 * 4;
    }
    else {
      local_3c = 0;
    }
    FUN_004f5bf9((HWND)(&loop_idx)[val_3],local_3c,7 - (val_3 + 1));
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
  int match_count;
  int slot_idx;
  
  slot_idx = -1;
  if ((arg1 == 0) || (arg2 == 0)) {
    slot_idx = -1;
  }
  else {
    match_count = 0;
    while ((match_count < arg2 && (slot_idx == -1))) {
      BVar1 = IsWindowVisible(*(HWND *)(arg1 + match_count * 4));
      if (BVar1 != 0) {
        slot_idx = match_count;
      }
      match_count = match_count + 1;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004f5bf9
 * Entry Point: 004f5bf9
 * Size: 190 bytes
 */


int32_t FUN_004f5bf9(HWND hwnd,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int32_t match_count;
  
  if ((card_slot == 0) || (arg_3 < 1)) {
    uval_1 = 0;
  }
  else {
    val_2 = FUN_004f5b76(card_slot,arg_3);
    if (val_2 == -1) {
      uval_1 = 0;
    }
    else {
      SetWindowPos(*(HWND *)(card_slot + val_2 * 4),hwnd,0,0,0,0,3);
      if (val_2 + 1 < arg_3) {
        match_count = val_2 * 4 + 4 + card_slot;
      }
      else {
        match_count = 0;
      }
      FUN_004f5bf9(*(HWND *)(card_slot + val_2 * 4),match_count,arg_3 - (val_2 + 1));
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f5cbc
 * Entry Point: 004f5cbc
 * Size: 94 bytes
 */


uint32_t FUN_004f5cbc(int player_id)

{
  return CONCAT12((&DAT_006a4b70)[player * 4],
                  CONCAT11((&DAT_006a4b71)[player * 4],(&DAT_006a4b72)[player * 4])) | 0x2000000;
}



/*
 * Decompiled function: GDI_RealizePaletteTree_Magic
 * Entry Point: 004f5d1a
 * Size: 421 bytes
 */


int32_t GDI_RealizePaletteTree_Magic(HWND hwnd,uint32_t y,HWND param_3,int32_t arg_4)

{
  uint32_t uval_1;
  UINT UVar2;
  HDC hdc;
  int32_t uval_3;
  HWND local_38;
  uint32_t local_34;
  HWND local_30;
  int32_t local_2c;
  DWORD color_idx;
  HDC target_idx;
  DWORD player_idx;
  DWORD card_idx;
  HWND match_count;
  DWORD slot_idx;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_00680774);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_00680774,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uval_3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uval_3 = 0;
  }
  else {
    match_count = param_3;
    if (hwnd != param_3) {
      player_idx = GetWindowThreadProcessId(param_3,&slot_idx);
      color_idx = GetWindowThreadProcessId(hwnd,&card_idx);
      if (card_idx == slot_idx) {
        uval_1 = GetWindowLongA(hwnd,-0x10);
        if ((uval_1 & 0x40000000) == 0) {
          target_idx = GetDC(hwnd);
          SelectPalette(target_idx,DAT_00680774,1);
          UVar2 = RealizePalette(target_idx);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,target_idx);
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
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: FUN_004f5ec4
 * Entry Point: 004f5ec4
 * Size: 84 bytes
 */


int32_t FUN_004f5ec4(HWND hwnd,int *arg2)

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


uint32_t FUN_004f5f20(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int val_1;
  uint32_t *u_ptr_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int32_t card_idx;
  
  if (player == 0) {
    card_idx = 0;
  }
  else if ((((card_slot == 0x20) || (card_slot == 0x18)) || (card_slot == 0x10)) || (card_slot == 8)) {
    val_1 = (int)(card_slot + (card_slot >> 0x1f & 7U)) >> 3;
    uval_3 = arg_3 * val_1 >> 0x1f;
    uval_3 = 4 - (((arg_3 * val_1 ^ uval_3) - uval_3 & 3 ^ uval_3) - uval_3);
    uval_4 = (int)uval_3 >> 0x1f;
    u_ptr_2 = (uint32_t *)((arg_3 * val_1 + (((uval_3 ^ uval_4) - uval_4 & 3 ^ uval_4) - uval_4)) * arg_5 +
                      arg_4 * val_1 + player);
    if (card_slot == 0x20) {
      card_idx = *u_ptr_2;
    }
    else if (card_slot == 0x18) {
      card_idx = (uint32_t)(uint8_t)*u_ptr_2 << 0x10 | (uint32_t)*(uint8_t *)((int)u_ptr_2 + 1) << 8 |
                 (uint32_t)*(uint8_t *)((int)u_ptr_2 + 2);
    }
    else if (card_slot == 0x10) {
      card_idx = (uint32_t)CONCAT11((uint8_t)*u_ptr_2,*(uint8_t *)((int)u_ptr_2 + 1));
    }
    else if (card_slot == 8) {
      card_idx = (uint32_t)(uint8_t)*u_ptr_2;
    }
  }
  else {
    card_idx = 0;
  }
  return card_idx;
}



/*
 * Decompiled function: FUN_004f6060
 * Entry Point: 004f6060
 * Size: 278 bytes
 */


void FUN_004f6060(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int32_t arg_6)

{
  uint8_t uval_3;
  int val_1;
  int32_t *u_ptr_2;
  uint32_t uval_4;
  uint32_t uval_5;
  
  if ((player != 0) && ((((card_slot == 0x20 || (card_slot == 0x18)) || (card_slot == 0x10)) || (card_slot == 8)))) {
    val_1 = (int)(card_slot + (card_slot >> 0x1f & 7U)) >> 3;
    uval_4 = arg_3 * val_1 >> 0x1f;
    uval_4 = 4 - (((arg_3 * val_1 ^ uval_4) - uval_4 & 3 ^ uval_4) - uval_4);
    uval_5 = (int)uval_4 >> 0x1f;
    u_ptr_2 = (int32_t *)
             ((arg_3 * val_1 + (((uval_4 ^ uval_5) - uval_5 & 3 ^ uval_5) - uval_5)) * arg_5 +
              arg_4 * val_1 + player);
    if (card_slot == 0x20) {
      *u_ptr_2 = arg_6;
    }
    else {
      uval_3 = (uint8_t)((uint32_t)arg_6 >> 8);
      if (card_slot == 0x18) {
        *(char *)u_ptr_2 = (char)((uint32_t)arg_6 >> 0x10);
        *(uint8_t *)((int)u_ptr_2 + 1) = uval_3;
        *(uint8_t *)((int)u_ptr_2 + 2) = (uint8_t)arg_6;
      }
      else if (card_slot == 0x10) {
        *(uint8_t *)u_ptr_2 = uval_3;
        *(uint8_t *)((int)u_ptr_2 + 1) = (uint8_t)arg_6;
      }
      else if (card_slot == 8) {
        *(uint8_t *)u_ptr_2 = (uint8_t)arg_6;
      }
    }
  }
  return;
}



/*
 * Decompiled function: Catalog_LoadCardsDat
 * Entry Point: 004f6180
 * Size: 2434 bytes
 */


int Catalog_LoadCardsDat(char *filepath)

{
  char *char_ptr_1;
  int val_2;
  int local_414;
  int local_410;
  int local_40c;
  char local_408 [1000];
  char *loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  size_t card_idx;
  int match_count;
  FILE *slot_idx;
  
  slot_idx = fopen(str_1,&DAT_005302a4);
  if (slot_idx == (FILE *)0x0) {
    val_2 = 0;
  }
  else {
    fread(&g_CardsDatLoadedHandle,4,1,slot_idx);
    fread(&card_idx,4,1,slot_idx);
    DAT_00695e9c = (int)malloc(card_idx);
    if ((void *)DAT_00695e9c == (void *)0x0) {
      fclose(slot_idx);
      val_2 = 0;
    }
    else {
      fread(&DAT_006b3070,0x98,g_CardsDatLoadedHandle,slot_idx);
      fread((void *)DAT_00695e9c,1,card_idx,slot_idx);
      fclose(slot_idx);
      for (match_count = 0; match_count < g_CardsDatLoadedHandle; match_count = match_count + 1) {
        *(int *)(&DAT_006b3074 + match_count * 0x98) =
             *(int *)(&DAT_006b3074 + match_count * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b3078 + match_count * 0x98) =
             *(int *)(&DAT_006b3078 + match_count * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b30e4 + match_count * 0x98) =
             *(int *)(&DAT_006b30e4 + match_count * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b30e8 + match_count * 0x98) =
             *(int *)(&DAT_006b30e8 + match_count * 0x98) + DAT_00695e9c;
        val_2 = _strcmpi(*(char **)(&DAT_006b30e4 + match_count * 0x98),&DAT_005302a8);
        if (val_2 == 0) {
          *(uint8_t **)(&DAT_006b30e4 + match_count * 0x98) = &DAT_005302b0;
        }
        val_2 = _strcmpi(*(char **)(&DAT_006b30e8 + match_count * 0x98),&DAT_005302b4);
        if ((val_2 == 0) ||
           (val_2 = _strcmpi(*(char **)(&DAT_006b30e8 + match_count * 0x98),s_Blank_005302bc),
           val_2 == 0)) {
          *(uint8_t **)(&DAT_006b30e8 + match_count * 0x98) = &DAT_005302c4;
        }
        *(uint8_t **)(&DAT_006b30b0 + match_count * 0x98) =
             (&PTR_DAT_005290b0)[*(int *)(&DAT_006b30b0 + match_count * 0x98)];
        if (*(int *)(&DAT_006b30b4 + match_count * 0x98) == 0) {
          *(int32_t *)(&DAT_006b30b4 + match_count * 0x98) = 1;
        }
        for (player_idx = 0; player_idx < *(int *)(&DAT_006b30b4 + match_count * 0x98);
            player_idx = player_idx + 1) {
          *(int *)(&DAT_006b30bc + player_idx * 4 + match_count * 0x98) =
               *(int *)(&DAT_006b30bc + player_idx * 4 + match_count * 0x98) + DAT_00695e9c;
        }
        *(int32_t *)(&DAT_006b30b8 + match_count * 0x98) = 0;
        for (player_idx = 0; player_idx < *(int *)(&DAT_006b30b4 + match_count * 0x98);
            player_idx = player_idx + 1) {
          *(int32_t *)(&DAT_006b30d0 + player_idx * 4 + match_count * 0x98) = 0;
        }
      }
      for (target_idx = 0; target_idx < g_CardsDatLoadedHandle; target_idx = target_idx + 1) {
        if (((&DAT_006b307c)[target_idx * 0x98] & 0x40) != 0) {
          *(int32_t *)(&DAT_006b307c + target_idx * 0x98) = 0x80;
        }
      }
      for (color_idx = 0; color_idx < g_CardsDatLoadedHandle; color_idx = color_idx + 1) {
        if ((&DAT_006b3098)[color_idx * 0x98] == '\x11') {
          (&DAT_006b3098)[color_idx * 0x98] = 10;
        }
      }
      for (local_40c = 0; local_40c < g_CardsDatLoadedHandle; local_40c = local_40c + 1) {
        local_410 = 0;
        for (loop_idx = *(char **)(&DAT_006b30e4 + local_40c * 0x98); *loop_idx != '\0';
            loop_idx = loop_idx + 1) {
          if (*loop_idx == '|') {
            char_ptr_1 = loop_idx + 1;
            if (*char_ptr_1 == 'T') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -0x12;
            }
            else if (*char_ptr_1 == 'B') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -2;
            }
            else if (*char_ptr_1 == 'U') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -3;
            }
            else if (*char_ptr_1 == 'W') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -5;
            }
            else if (*char_ptr_1 == 'G') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -1;
            }
            else if (*char_ptr_1 == 'R') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -4;
            }
            else if (*char_ptr_1 == 'X') {
              loop_idx = char_ptr_1;
              local_408[local_410] = -0x10;
            }
            else if ((*char_ptr_1 == '1') && (loop_idx[2] == '0')) {
              loop_idx = loop_idx + 2;
              local_408[local_410] = -0x11;
            }
            else if ((*char_ptr_1 < '0') || ('9' < *char_ptr_1)) {
              loop_idx = char_ptr_1;
              local_408[local_410] = '|';
              loop_idx = loop_idx + -1;
            }
            else {
              loop_idx = char_ptr_1;
              local_408[local_410] = *char_ptr_1 + -0x3f;
            }
          }
          else if (((*loop_idx == '\\') && (loop_idx[1] == '\\')) ||
                  ((*loop_idx == '\\' && (loop_idx[1] == 'n')))) {
            loop_idx = loop_idx + 1;
            local_408[local_410] = '\n';
          }
          else {
            local_408[local_410] = *loop_idx;
          }
          local_410 = local_410 + 1;
        }
        local_408[local_410] = '\0';
        strcpy(*(char **)(&DAT_006b30e4 + local_40c * 0x98),local_408);
      }
      for (local_414 = 0; val_2 = g_CardsDatLoadedHandle, local_414 < g_CardsDatLoadedHandle; local_414 = local_414 + 1)
      {
        *(int32_t *)(&DAT_006b30cc + local_414 * 0x98) = 0;
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_black_005302c8,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) | 2;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),&DAT_005302d0,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) | 4;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_green_005302d8,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) | 8;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),&DAT_005302e0,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) | 0x10;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_white_005302e4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b30cc + local_414 * 0x98) | 0x20;
        }
        *(int32_t *)(&DAT_006b3104 + local_414 * 0x98) = 0;
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_swamp_005302ec,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) | 2;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_island_005302f4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) | 4;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_forest_005302fc,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) | 8;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_mountain_00530304,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) | 0x10;
        }
        val_2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_plains_00530310,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_006b3104 + local_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return val_2;
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


int32_t FUN_004f6b33(LPCSTR str_1)

{
  char *char_ptr_1;
  uint8_t loop_idx [4];
  HANDLE color_idx;
  int32_t target_idx;
  DWORD player_idx;
  DWORD card_idx;
  int match_count;
  char *slot_idx;
  
  target_idx = 0;
  for (match_count = 0; match_count < g_CardsDatLoadedHandle; match_count = match_count + 1) {
    *(uint8_t **)(&DAT_006809e0 + match_count * 0x14) = &DAT_00530318;
    *(uint8_t **)(&DAT_006809e4 + match_count * 0x14) = &DAT_0053031c;
    *(uint8_t **)(&DAT_006809e8 + match_count * 0x14) = &DAT_00530320;
    *(uint8_t **)(&DAT_006809ec + match_count * 0x14) = &DAT_00530324;
    *(uint8_t **)(&DAT_006809f0 + match_count * 0x14) = &DAT_00530328;
  }
  color_idx = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (color_idx != (HANDLE)0xffffffff) {
    card_idx = GetFileSize(color_idx,(LPDWORD)0x0);
    DAT_0068a720 = malloc(card_idx + 1);
    if (DAT_0068a720 != (void *)0x0) {
      ReadFile(color_idx,DAT_0068a720,card_idx,&player_idx,(LPOVERLAPPED)0x0);
      slot_idx = DAT_0068a720;
      char_ptr_1 = strchr(DAT_0068a720,10);
      slot_idx = char_ptr_1 + 1;
      for (match_count = 0; match_count < g_CardsDatLoadedHandle; match_count = match_count + 1) {
        sscanf(slot_idx,&DAT_0053032c,loop_idx);
        slot_idx = (char *)FUN_004f6db9(&slot_idx);
        slot_idx = (char *)FUN_004f6db9(&slot_idx);
        char_ptr_1 = (char *)FUN_004f6db9(&slot_idx);
        *(char **)(&DAT_006809e0 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_004f6db9(&slot_idx);
        *(char **)(&DAT_006809e4 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_004f6db9(&slot_idx);
        *(char **)(&DAT_006809e8 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_004f6db9(&slot_idx);
        *(char **)(&DAT_006809ec + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_004f6db9(&slot_idx);
        *(char **)(&DAT_006809f0 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
      }
      target_idx = 1;
    }
    CloseHandle(color_idx);
  }
  return target_idx;
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


char * FUN_004f6db9(int32_t *player)

{
  char *char_ptr_1;
  char *player_idx;
  char *slot_idx;
  
  slot_idx = (char *)*player;
  if (*slot_idx == '\"') {
    slot_idx = slot_idx + 1;
    player_idx = strchr(slot_idx,0x22);
    *player_idx = '\0';
    if (player_idx[1] == ',') {
      player_idx = player_idx + 2;
    }
    else {
      player_idx = player_idx + 3;
    }
  }
  else {
    player_idx = strchr(slot_idx,0x2c);
    char_ptr_1 = strchr(slot_idx,0xd);
    if (player_idx < char_ptr_1) {
      *player_idx = '\0';
      player_idx = player_idx + 1;
    }
    else {
      *char_ptr_1 = '\0';
      player_idx = char_ptr_1 + 2;
    }
  }
  *player = slot_idx;
  return player_idx;
}



/*
 * Decompiled function: FUN_004f6e90
 * Entry Point: 004f6e90
 * Size: 701 bytes
 */


int32_t FUN_004f6e90(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int32_t uval_2;
  int val_3;
  int val_4;
  int height;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      target_idx = 0;
      do {
        target_idx = target_idx + 1;
        if (999 < target_idx) {
          slot_idx = -1;
          break;
        }
        player_idx = Util_GetRandomNumber(2);
        slot_idx = Util_GetRandomNumber(500);
        card_idx = *(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player_idx * 2000);
      } while ((card_idx == -1) || (((&g_MasterCardColorTable)[card_idx * 0x34] & 2) == 0));
      if (slot_idx == -1) {
        color_idx = 0;
        while ((color_idx < 2 && (slot_idx == -1))) {
          target_idx = 0;
          while (((target_idx < 500 &&
                  (*(int *)(&g_PlayerGraveyardList + target_idx * 4 + color_idx * 2000) != -1)) &&
                 (slot_idx == -1))) {
            card_idx = *(int *)(&g_PlayerGraveyardList + target_idx * 4 + color_idx * 2000);
            if (((&g_MasterCardColorTable)[card_idx * 0x34] & 2) != 0) {
              slot_idx = target_idx;
              player_idx = color_idx;
            }
            target_idx = target_idx + 1;
          }
          color_idx = color_idx + 1;
        }
      }
      if ((slot_idx != -1) && (*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player_idx * 2000) != -1)) {
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x23);
        }
        val_3 = Deck_AddCardToDeck
                          (player,*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player_idx * 2000));
        if (player_idx == 0) {
          *(int32_t *)(&g_CardSlot_Flags + val_3 * 0x120 + player * 0x5b20) = 0;
        }
        else {
          *(int32_t *)(&g_CardSlot_Flags + val_3 * 0x120 + player * 0x5b20) = 0x1000;
        }
        if (val_3 != -1) {
          Pic_Subsystem_00449223(player_idx,slot_idx);
          Pic_Subsystem_0042ac1f(player,val_3);
          cVar1 = (&g_MasterCardSubTypeTable2)[card_idx * 0x34];
          val_3 = player;
          height = card_slot;
          val_4 = Math_Clamp((int)(char)(&g_MasterCardManaCostTable)[card_idx * 0x34],0,99);
          Mem_AllocOrFree_0041df33(player,cVar1 + val_4,val_3,height);
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004f714d
 * Entry Point: 004f714d
 * Size: 355 bytes
 */


int32_t FUN_004f714d(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x60;
    }
    if (arg_3 == 0x71) {
      if (DAT_006ff2d8 == -1) {
        flag_1 = false;
        match_count = 0;
        while ((match_count < 2 && (!flag_1))) {
          for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[match_count];
              slot_idx = slot_idx + 1) {
            if ((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) == DAT_006a4b64)
               && (((&DAT_006a5f69)[slot_idx * 0x120 + match_count * 0x5b20] & 1) != 0)) {
              flag_1 = true;
            }
          }
          match_count = match_count + 1;
        }
        if (!flag_1) {
          DAT_006ff2d8 = player;
        }
      }
      val_3 = Card_ApplyTriggerEffect(player,card_slot,DAT_006a4b64,-1,-1);
      *(uint32_t *)(&g_CardSlot_Abilities1 + val_3 * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + val_3 * 0x120 + player * 0x5b20) | 0x120;
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Prompts_Load_004f72b0
 * Entry Point: 004f72b0
 * Size: 936 bytes
 */


int32_t Prompts_Load_004f72b0(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int local_110;
  int local_108;
  char local_104 [252];
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (flags == 0x71) {
      Pic_Subsystem_00424500(s_prompts_txt_00530338,s_BALANCE_00530330);
      strcpy(local_104,&g_OverworldGoldAmount);
      do {
        strcpy(&g_OverworldGoldAmount,local_104);
        local_110 = 0;
        local_108 = 0;
        slot_idx = 0;
        while( true ) {
          val_2 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            val_2 = g_PlayerActiveCardCount;
          }
          if (val_2 <= slot_idx) break;
          val_2 = Card_IsTapped(0, slot_idx);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + slot_idx * 0x120) * 0x34] & 1)
              != 0)) {
            local_108 = local_108 + 1;
          }
          val_2 = Card_IsTapped(1,slot_idx);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + slot_idx * 0x120) * 0x34] & 1) != 0
             )) {
            local_110 = local_110 + 1;
          }
          slot_idx = slot_idx + 1;
        }
        if (local_110 < local_108) {
          Glue_Subsystem_004e701f(0);
        }
        else if (local_108 < local_110) {
          Glue_Subsystem_004e701f(1);
        }
        Ai_EvaluateTacticalPosition(0,0xff);
      } while (local_110 != local_108);
      do {
        if (DAT_006b300c < g_ActivePlayerSpellPriority) {
          Prompts_Load_0046fa40(0,0,0);
        }
        if (g_ActivePlayerSpellPriority < DAT_006b300c) {
          Prompts_Load_0046fa40(1,0,0);
        }
      } while (g_ActivePlayerSpellPriority != DAT_006b300c);
      do {
        local_110 = 0;
        local_108 = 0;
        slot_idx = 0;
        while( true ) {
          val_2 = DAT_006808bc;
          if (DAT_006808bc <= g_PlayerActiveCardCount) {
            val_2 = g_PlayerActiveCardCount;
          }
          if (val_2 <= slot_idx) break;
          val_2 = Card_IsTapped(0, slot_idx);
          if (((val_2 != 0) &&
              (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + slot_idx * 0x120) * 0x34] & 2
               ) != 0)) && ((&g_CardSlot_CardTypeIndex)[slot_idx * 0x120] != '\x03')) {
            local_108 = local_108 + 1;
          }
          val_2 = Card_IsTapped(1,slot_idx);
          if (((val_2 != 0) &&
              (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + slot_idx * 0x120) * 0x34] & 2) !=
               0)) && ((&g_CardSlot_CardTypeIndex)[slot_idx * 0x120] != '\x03')) {
            local_110 = local_110 + 1;
          }
          slot_idx = slot_idx + 1;
        }
        strcpy(&g_OverworldGoldAmount,&DAT_0069f84a);
        if (local_110 < local_108) {
          val_2 = Glue_Subsystem_004e6bff(0);
          Pic_Subsystem_0044867e(0,val_2,3);
        }
        if (local_108 < local_110) {
          val_2 = Glue_Subsystem_004e6bff(1);
          Pic_Subsystem_0044867e(1,val_2,3);
        }
        Ai_EvaluateTacticalPosition(0,0xff);
      } while (local_110 != local_108);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004f7658
 * Entry Point: 004f7658
 * Size: 529 bytes
 */


int32_t Prompts_Load_004f7658(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int player_idx;
  int32_t card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if ((spell_id == g_ActivePlayerPriority) && (val_1 = Font_DrawString(spell_id, 7, 3), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530350,s_BRAINGEYSER_00530344);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&player_idx);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = player_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = card_idx
        ;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      slot_idx = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      for (match_count = 0;
          match_count < *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120);
          match_count = match_count + 1) {
        Magic_ExecuteDrawPhase(slot_idx);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004f7869
 * Entry Point: 004f7869
 * Size: 529 bytes
 */


int32_t FUN_004f7869(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth - ((&g_ActivePlayerSpellPriority)[player] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      color_idx = 0;
      player_idx = g_DefendingPlayer;
      while (color_idx < 2) {
        loop_idx = 0;
        for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[player_idx]; slot_idx = slot_idx + 1
            ) {
          val_2 = FUN_00471bc0(player_idx,slot_idx);
          if (val_2 != 0) {
            loop_idx = loop_idx + 1;
          }
        }
        for (target_idx = 0; target_idx < loop_idx; target_idx = target_idx + 1) {
          Prompts_Load_0046fa40(player_idx,1,0);
        }
        color_idx = color_idx + 1;
        if (g_DefendingPlayer == 0) {
          player_idx = player_idx + 1;
        }
        else {
          player_idx = player_idx + -1;
        }
      }
      Ai_EvaluateTacticalPosition(0,0x30);
      card_idx = 0;
      match_count = 0;
      for (target_idx = 0; target_idx < 500; target_idx = target_idx + 1) {
        if (*(int *)(&g_PlayerDeckCardList + target_idx * 4) != -1) {
          match_count = match_count + 1;
        }
        if (*(int *)(&DAT_0069ef00 + target_idx * 4) != -1) {
          card_idx = card_idx + 1;
        }
      }
      if ((match_count < 7) && (card_idx < 7)) {
        if (g_IsAiThinking == 1) {
          g_PlayerCreatureCount = 0;
          g_PlayerDeckCardCount = 0;
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
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Darkpact
 * Entry Point: 004f7a7a
 * Size: 380 bytes
 */


int32_t CardScript_Darkpact(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
      if ((player == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        Ai_Subsystem_004cd198();
        val_2 = Ai_Subsystem_004cc814
                          (player,s_Darkpact__Swap_ante_005303cc,0,s_Swap_my_ante_005303bc,
                           s_Swap_opponent_s_ante_005303a4,(char *)0x0);
        if (val_2 == 0) {
          match_count = player;
        }
        else {
          match_count = 1 - player;
        }
      }
      else {
        match_count = player;
      }
      *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = match_count;
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&g_PlayerDeckCardList + player * 2000) != -1) {
        uval_1 = (&DAT_006b2d90)
                [*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) * 0x10];
        (&DAT_006b2d90)
        [*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) * 0x10] =
             *(int32_t *)(&g_PlayerDeckCardList + player * 2000);
        *(int32_t *)(&g_PlayerDeckCardList + player * 2000) = uval_1;
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f7bf6
 * Entry Point: 004f7bf6
 * Size: 283 bytes
 */


int32_t FUN_004f7bf6(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
      while ((&g_ActivePlayerSpellPriority)[player] != 0) {
        Prompts_Load_0046fa40(player,1,0);
      }
      for (match_count = 0; ((&DAT_006b2d90)[player * 0x10 + match_count] != -1 && (match_count < 0x10));
          match_count = match_count + 1) {
      }
      if (match_count < 0x10) {
        val_2 = Magic_ExecuteDrawPhase(player);
        (&DAT_006b2d90)[player * 0x10 + match_count] =
             *(int32_t *)(&g_CardSlot_CardId + val_2 * 0x120 + player * 0x5b20);
        *(int32_t *)(&g_CardSlot_CardId + val_2 * 0x120 + player * 0x5b20) = 0xffffffff;
      }
      FUN_004f823a(player,7);
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f7d11
 * Entry Point: 004f7d11
 * Size: 477 bytes
 */


int32_t FUN_004f7d11(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int color_idx;
  int aiStack_14 [4];
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      for (aiStack_14[2] = 0; aiStack_14[2] < 2; aiStack_14[2] = aiStack_14[2] + 1) {
        if (*(int *)(&g_PlayerDeckCardList + aiStack_14[2] * 2000) == -1) {
          aiStack_14[aiStack_14[2]] = 0;
        }
        else {
          aiStack_14[3] =
               Ai_Subsystem_004cc56d
                         (aiStack_14[2],player,card_slot,-1,-1,
                          s_Ante_an_additional_card__No_addi_005303e0,
                          (uint32_t)(0xf < (int)(&g_PlayerCreatureCount)[aiStack_14[2]]));
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
          for (color_idx = 0;
              ((&DAT_006b2d90)[aiStack_14[2] * 0x10 + color_idx] != -1 && (color_idx < 0x10));
              color_idx = color_idx + 1) {
          }
          if (color_idx < 0x10) {
            uval_1 = *(int32_t *)(&g_PlayerDeckCardList + aiStack_14[2] * 2000);
            Pic_Subsystem_004523fd(aiStack_14[2],0);
            (&DAT_006b2d90)[aiStack_14[2] * 0x10 + color_idx] = uval_1;
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f7eee
 * Entry Point: 004f7eee
 * Size: 323 bytes
 */


int32_t FUN_004f7eee(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      card_idx = 0;
      slot_idx = g_DefendingPlayer;
      while (card_idx < 2) {
        player_idx = 0;
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = FUN_00471bc0(slot_idx,match_count);
          if (val_2 != 0) {
            Pic_Subsystem_0045245e
                      (slot_idx,*(int32_t *)
                                (&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20));
            *(int32_t *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) = 0xffffffff;
            player_idx = player_idx + 1;
          }
        }
        Ai_EvaluateTacticalPosition(0,0x30);
        Pic_Subsystem_00452276(slot_idx);
        FUN_004f823a(slot_idx,player_idx);
        card_idx = card_idx + 1;
        if (g_DefendingPlayer == 0) {
          slot_idx = slot_idx + 1;
        }
        else {
          slot_idx = slot_idx + -1;
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f8031
 * Entry Point: 004f8031
 * Size: 521 bytes
 */


int32_t FUN_004f8031(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth - ((&g_ActivePlayerSpellPriority)[player] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      card_idx = 0;
      slot_idx = g_DefendingPlayer;
      while (card_idx < 2) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = FUN_00471bc0(slot_idx,match_count);
          if (val_2 != 0) {
            Pic_Subsystem_0045245e
                      (slot_idx,*(int32_t *)
                                (&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20));
            *(int32_t *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) = 0xffffffff;
          }
        }
        match_count = 0;
        while ((match_count < 500 && (*(int *)(&g_PlayerGraveyardList + match_count * 4 + slot_idx * 2000) != -1))) {
          Pic_Subsystem_0045245e
                    (slot_idx,*(int32_t *)(&g_PlayerGraveyardList + match_count * 4 + slot_idx * 2000));
          match_count = match_count + 1;
        }
        for (match_count = 0; match_count < 500; match_count = match_count + 1) {
          *(int32_t *)(&g_PlayerGraveyardList + match_count * 4 + slot_idx * 2000) = 0xffffffff;
        }
        Ai_EvaluateTacticalPosition(0,0x30);
        Pic_Subsystem_00452276(slot_idx);
        FUN_004f823a(slot_idx,7);
        card_idx = card_idx + 1;
        if (g_DefendingPlayer == 0) {
          slot_idx = slot_idx + 1;
        }
        else {
          slot_idx = slot_idx + -1;
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f823a
 * Entry Point: 004f823a
 * Size: 91 bytes
 */


void FUN_004f823a(int arg1,int arg2)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < arg2; slot_idx = slot_idx + 1) {
    Magic_ExecuteDrawPhase(arg1);
    if (arg1 != 0) {
      g_PendingSpellResolutionFlag = 0;
    }
  }
  (&g_ActivePlayerSpellPriority)[arg1] = arg2;
  return;
}



/*
 * Decompiled function: FUN_004f8295
 * Entry Point: 004f8295
 * Size: 140 bytes
 */


int32_t FUN_004f8295(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  (&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20] = 1;
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      Card_ApplyTriggerEffect(player,card_slot,DAT_006a2824,-1,-1);
      FUN_0040d7e9(player,0,1);
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004f8321
 * Entry Point: 004f8321
 * Size: 849 bytes
 */


int32_t Prompts_Load_004f8321(int spell_id,int target_id,int flags)

{
  char cVar1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int val_6;
  int32_t arg_11;
  int val_7;
  int32_t arg_12;
  uint32_t uval_8;
  int32_t arg_13;
  uint32_t uVar9;
  int32_t arg_14;
  uint32_t uVar10;
  int32_t arg_15;
  uint32_t uVar11;
  int32_t arg_16;
  uint32_t uVar12;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
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
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uval_2,arg_11,arg_12,
                         arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0053041c,s_ENERGYTAP_00530410);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_6 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_6 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_6,val_7,uval_8,
                         uVar9,uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
      if (val_6 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_6 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_6 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,0x200,2,
                         0,0,uval_3,uval_4,uval_5,val_6,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (val_6 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_00415d48(match_count,slot_idx);
        cVar1 = (&g_MasterCardSubTypeTable2)
                [*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) * 0x34];
        val_6 = Math_Clamp((int)(char)(&g_MasterCardManaCostTable)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 match_count * 0x5b20 + slot_idx * 0x120) * 0x34],0,99);
        *(int *)(&g_AiLookaheadDepth + spell_id * 0x20) =
             *(int *)(&g_AiLookaheadDepth + spell_id * 0x20) + cVar1 + val_6;
        cVar1 = (&g_MasterCardSubTypeTable2)
                [*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) * 0x34];
        val_6 = Math_Clamp((int)(char)(&g_MasterCardManaCostTable)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 match_count * 0x5b20 + slot_idx * 0x120) * 0x34],0,99);
        *(int *)(&DAT_0063eeac + spell_id * 0x20) =
             *(int *)(&DAT_0063eeac + spell_id * 0x20) + cVar1 + val_6;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Prompts_Load_004f8672
 * Entry Point: 004f8672
 * Size: 572 bytes
 */


int32_t Prompts_Load_004f8672(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int val_3;
  int match_count;
  int32_t slot_idx;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (val_1 = Font_DrawString(spell_id,7,2), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      val_1 = (&g_PlayerCreatureCount)[spell_id];
      val_3 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (val_1 * 0x18) / val_3;
      Pic_Subsystem_00424500(s_prompts_txt_00530438,s_STREAMOFLIFE_00530428);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&match_count);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
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
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004f88ae
 * Entry Point: 004f88ae
 * Size: 237 bytes
 */


int32_t FUN_004f88ae(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = Card_IsTapped(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 4) != 0)
             ) {
            Pic_Subsystem_0044867e(slot_idx,match_count,2);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004f899b
 * Entry Point: 004f899b
 * Size: 1852 bytes
 */


int32_t Prompts_Load_004f899b(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint32_t)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,0,0,0,uval_1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((spell_id == g_ActivePlayerPriority) &&
       ((g_OverworldPlayerCoordY == 0 || (val_2 = Font_DrawString(spell_id,7,4), val_2 == 0)))) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
    return uval_1;
  }
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    val_2 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                          spell_id * 0x5b20 + target_id * 0x120));
    g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)val_2);
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    target_idx = 0;
    card_idx = 0;
    while (((target_idx < g_TurnCounter && (card_idx == 0)) && (g_ActivePlayer != 1))) {
      player_idx = Card_UntapCard(spell_id, target_id, 4);
      player_idx = player_idx + -1;
      Pic_Subsystem_00424500(s_prompts_txt_00530458,s_VOLCANIC_ERUPTION_00530444);
      sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,target_idx + 1,g_TurnCounter);
      if (player_idx == 4) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_0053046c,0,s_PLAINS_00530464);
      }
      else if (player_idx == 0) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_00530480,0,s_SWAMP_00530478);
      }
      else if (player_idx == 1) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_00530494,0,s_ISLAND_0053048c);
      }
      else if (player_idx == 2) {
        FUN_004f4a92(&g_OverworldGoldAmount,s_mountain_005304a8,0,s_FOREST_005304a0);
      }
      arg_20 = &loop_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      uval_5 = 0;
      uval_4 = 0;
      val_2 = player_idx;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        if (color_idx == -1) {
          g_ActivePlayer = 1;
        }
        else {
          card_idx = 1;
        }
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + loop_idx * 0x5b20 + color_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + loop_idx * 0x5b20 + color_idx * 0x120) | 0x300000;
        Ai_EvaluateTacticalPosition(0,0x20);
        *(int *)(&g_CardSlot_CombatTarget +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             loop_idx;
        *(int *)(&g_CardSlot_AttachedAura +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             color_idx;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
      }
      target_idx = target_idx + 1;
    }
    for (target_idx = 0;
        target_idx < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        target_idx = target_idx + 1) {
      *(uint32_t *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_CombatTarget +
                       spell_id * 0x5b20 + target_id * 0x120 + target_idx * 8) * 0x5b20 +
               *(int *)(&g_CardSlot_AttachedAura +
                       spell_id * 0x5b20 + target_id * 0x120 + target_idx * 8) * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_CombatTarget +
                            spell_id * 0x5b20 + target_id * 0x120 + target_idx * 8) * 0x5b20 +
                    *(int *)(&g_CardSlot_AttachedAura +
                            spell_id * 0x5b20 + target_id * 0x120 + target_idx * 8) * 0x120) &
           0xffcfffff;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
  }
  if (flags == 0x71) {
    player_idx = Card_UntapCard(spell_id, target_id, 4);
    player_idx = player_idx + -1;
    slot_idx = 0;
    for (target_idx = 0;
        target_idx < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        target_idx = target_idx + 1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      uval_5 = 0;
      uval_4 = 0;
      val_2 = player_idx;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget +
                                 target_idx * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_idx * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                         spell_id,2,2,0x200,0,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,uval_8,uVar9,
                         uVar10,uVar11);
      if (val_2 == 0) {
        slot_idx = slot_idx + 1;
      }
      else {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget +
                           target_idx * 8 + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura +
                           target_idx * 8 + target_id * 0x120 + spell_id * 0x5b20),2);
      }
    }
    if ((char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] == slot_idx) {
      g_ActivePlayer = 1;
    }
    if ((g_ActivePlayer != 1) &&
       (match_count = Deck_AddCardToDeck(spell_id,DAT_006ff564), match_count != -1)) {
      *(int32_t *)(&g_ActiveCardsInPlay + match_count * 0x120 + spell_id * 0x5b20) =
           *(int32_t *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120);
      *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x120 + spell_id * 0x5b20) | 2;
      *(int32_t *)(&DAT_006a5f74 + match_count * 0x120 + spell_id * 0x5b20) = 0x109;
      *(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x120 + spell_id * 0x5b20) =
           (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] - slot_idx;
      FUN_00476482(spell_id,match_count);
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


int32_t FUN_004f90d7(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    if ((player == g_ActivePlayerPriority) && (val_1 = Font_DrawString(player,7,2), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      val_1 = FUN_004fa423(player,*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)val_1);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        Mem_AllocOrFree_0041df33
                  (slot_idx,*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120),
                   player,card_slot);
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_1 = Card_IsTapped(slot_idx,match_count);
          if (((val_1 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0
              )) && (uval_3 = Card_TapForMana(slot_idx, match_count, 0x34, 0xffffffff), (uval_3 & 0x20) == 0)) {
            Card_ApplyCombatDamage(slot_idx, match_count, *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120),
                         player,card_slot);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004f92f3
 * Entry Point: 004f92f3
 * Size: 541 bytes
 */


int32_t FUN_004f92f3(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    if ((player == g_ActivePlayerPriority) && (val_1 = Font_DrawString(player,7,2), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
      val_1 = FUN_004fa423(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x24 / (longlong)val_1);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        Mem_AllocOrFree_0041df33
                  (slot_idx,*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20),
                   player,card_slot);
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_1 = Card_IsTapped(slot_idx,match_count);
          if (((val_1 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0
              )) && (uval_3 = Card_TapForMana(slot_idx, match_count, 0x34, 0xffffffff), (uval_3 & 0x20) != 0)) {
            Card_ApplyCombatDamage(slot_idx, match_count, *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20),
                         player,card_slot);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004f9510
 * Entry Point: 004f9510
 * Size: 237 bytes
 */


int32_t FUN_004f9510(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = Card_IsTapped(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 1) != 0)
             ) {
            Pic_Subsystem_0044867e(slot_idx,match_count,2);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004f95fd
 * Entry Point: 004f95fd
 * Size: 314 bytes
 */


int32_t FUN_004f95fd(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = Card_IsTapped(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 1) != 0)
             ) {
            val_2 = *(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20);
            val_3 = Card_UntapCard(player,card_slot,2);
            if (*(int *)(&g_MasterCardTypeTable + val_2 * 0x34) ==
                *(int *)(&DAT_006ff2bc + val_3 * 4)) {
              Pic_Subsystem_0044867e(slot_idx,match_count,2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004f9737
 * Entry Point: 004f9737
 * Size: 1153 bytes
 */


int32_t Prompts_Load_004f9737(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int *arg_20;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int card_idx;
  int match_count;
  int slot_idx;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo(&card_idx,0,spell_id,2,2,0x200,2,0x40,0,uval_1,arg_11,arg_12,arg_13,arg_14,arg_15,
                 arg_16,arg_17,arg_18_00,arg_19);
    if (card_idx < 2) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      match_count = 0;
      while ((match_count < 2 && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_005304c4,s_ASHESTOASHES_005304b4);
        arg_20 = (int *)(&g_CardSlot_CombatTarget +
                        target_id * 0x120 + spell_id * 0x5b20 + match_count * 8);
        uval_1 = 1;
        arg_18 = &g_OverworldGoldAmount + match_count * 0xfa;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uval_8 = 0xffffffff;
        uval_7 = 0xffffffff;
        val_6 = -1;
        val_5 = -1;
        uval_4 = 0;
        uval_3 = 0;
        uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_5 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,2,0x40,0,uval_2,uval_3,uval_4,val_5,val_6,
                           uval_7,uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
        if (val_5 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) |
               0x300000;
          Ai_EvaluateTacticalPosition(0,0x20);
        }
        match_count = match_count + 1;
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 2;
      for (match_count = 0;
          match_count < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          match_count = match_count + 1) {
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
    }
    if (flags == 0x71) {
      slot_idx = 0;
      for (match_count = 0;
          match_count < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          match_count = match_count + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uval_8 = 0xffffffff;
        uval_7 = 0xffffffff;
        val_6 = -1;
        val_5 = -1;
        uval_4 = 0;
        uval_3 = 0;
        uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_5 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                           spell_id,2,2,0x200,2,0x40,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                           uVar9,uVar10,uVar11);
        if (val_5 == 0) {
          slot_idx = slot_idx + 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget +
                             match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura +
                             match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),4);
        }
      }
      if (slot_idx == 2) {
        g_ActivePlayer = 1;
      }
      else {
        Mem_AllocOrFree_0041df33(spell_id,5,spell_id,target_id);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004f9bbd
 * Entry Point: 004f9bbd
 * Size: 679 bytes
 */


int32_t Prompts_Load_004f9bbd(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uval_1,arg_11,arg_12,arg_13,
                         arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      val_2 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x30 / (longlong)val_2);
      Pic_Subsystem_00424500(s_prompts_txt_005304e0,s_DESERT_TWISTER_005304d0);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uval_3,uval_4,uval_5,val_2,val_6,
                         uval_7,uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,0x1047,0,0,uval_3,uval_4,uval_5
                         ,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(match_count,slot_idx,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004f9e64
 * Entry Point: 004f9e64
 * Size: 1471 bytes
 */


int32_t Prompts_Load_004f9e64(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint32_t)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,2,0,0,uval_1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((g_ActivePlayerPriority == spell_id) &&
       ((g_OverworldPlayerCoordY == 0 || (val_2 = Font_DrawString(spell_id,7,2), val_2 == 0)))) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      match_count = 0;
      slot_idx = 0;
      while (((match_count < g_TurnCounter && (slot_idx == 0)) && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_005304fc,s_WINTER_BLAST_005304ec);
        sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,match_count + 1,g_TurnCounter);
        arg_20 = &player_idx;
        uval_1 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uval_8 = 0xffffffff;
        uval_7 = 0xffffffff;
        val_6 = -1;
        val_2 = -1;
        uval_5 = 0;
        uval_4 = 0;
        uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_2 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                           uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
        if (val_2 == 0) {
          if (card_idx == -1) {
            g_ActivePlayer = 1;
          }
          else {
            slot_idx = 1;
          }
        }
        else {
          *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) | 0x300000;
          Ai_EvaluateTacticalPosition(0,0x20);
          *(int *)(&g_CardSlot_CombatTarget +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               player_idx;
          *(int *)(&g_CardSlot_AttachedAura +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               card_idx;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
               (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
        }
        match_count = match_count + 1;
      }
      for (match_count = 0;
          match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          match_count = match_count + 1) {
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      for (match_count = 0;
          match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          match_count = match_count + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uval_8 = 0xffffffff;
        uval_7 = 0xffffffff;
        val_6 = -1;
        val_2 = -1;
        uval_5 = 0;
        uval_4 = 0;
        uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),(char *)0x0,
                           spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,uval_8,uVar9,
                           uVar10,uVar11);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_00415d48(*(int *)(&g_CardSlot_CombatTarget +
                               target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                       *(int *)(&g_CardSlot_AttachedAura +
                               target_id * 0x120 + spell_id * 0x5b20 + match_count * 8));
          uval_3 = Card_TapForMana(*(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                               *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),0x34,
                               0xffffffff);
          if ((uval_3 & 0x20) != 0) {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),2,spell_id,
                         target_id);
          }
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fa423
 * Entry Point: 004fa423
 * Size: 149 bytes
 */


int FUN_004fa423(int arg1,int arg2)

{
  int match_count;
  int slot_idx;
  
  match_count = 1;
  for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[arg1]; slot_idx = slot_idx + 1) {
    if ((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + arg1 * 0x5b20) == arg2) &&
       (((&g_CardSlot_Flags)[slot_idx * 0x120 + arg1 * 0x5b20] & 2) == 0)) {
      match_count = match_count + 1;
    }
  }
  return match_count;
}



/*
 * Decompiled function: FUN_004fa4b8
 * Entry Point: 004fa4b8
 * Size: 206 bytes
 */


int FUN_004fa4b8(int player_id,int card_slot,int event_type)

{
  int match_count;
  int slot_idx;
  
  match_count = 0;
  for (player = 0; player < 2; player = player + 1) {
    if ((arg_3 == -1) || (arg_3 == player)) {
      for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[player]; slot_idx = slot_idx + 1) {
        if ((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + player * 0x5b20) == card_slot) &&
           (((&g_CardSlot_Flags)[slot_idx * 0x120 + player * 0x5b20] & 2) != 0)) {
          match_count = match_count + 1;
        }
      }
    }
  }
  return match_count;
}



/*
 * Decompiled function: Prompts_Load_004fa586
 * Entry Point: 004fa586
 * Size: 3166 bytes
 */


int32_t Prompts_Load_004fa586(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  int32_t arg_11;
  uint32_t uval_4;
  int32_t arg_12;
  uint32_t uval_5;
  int32_t arg_13;
  int32_t arg_14;
  int32_t arg_15;
  uint32_t uval_6;
  int32_t arg_16;
  uint32_t uval_7;
  int32_t arg_17;
  uint8_t *puVar8;
  uint32_t uVar9;
  int iVar10;
  int32_t arg_18;
  uint32_t uVar11;
  int event_type;
  int32_t arg_19;
  int *piVar12;
  uint32_t uVar13;
  int local_30;
  int local_28;
  int local_24;
  int loop_idx;
  int32_t color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      DAT_006fe3f4 = 1;
    }
    else {
      val_1 = Font_DrawString(spell_id,7,2);
      if (val_1 == 0) {
        return 0;
      }
    }
    uval_2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      val_1 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x48 / (longlong)val_1);
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
          player_idx = Font_DrawString(spell_id,7,1);
          player_idx = player_idx + -1;
          arg_19 = 0;
          arg_18 = 0;
          arg_17 = 0;
          arg_16 = 0xffffffff;
          arg_15 = 0xffffffff;
          arg_14 = 0xffffffff;
          arg_13 = 0xffffffff;
          arg_12 = 0;
          arg_11 = 0;
          uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          UI_PaintBigCardInfo(&target_idx,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,arg_15
                       ,arg_16,arg_17,arg_18,arg_19);
          target_idx = target_idx + 2;
          card_idx = player_idx;
          match_count = 1;
          val_1 = Ai_Subsystem_004b832d
                            (spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),player_idx,
                             target_idx,&card_idx,&match_count,&color_idx);
          if (val_1 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 color_idx;
            g_TurnCounter = 0;
            DAT_006b2d50 = 1;
            Ai_CalcManaRequirement_004ba890(spell_id,0,card_idx);
            if (g_ActivePlayer != 1) {
              g_TurnCounter = card_idx - (match_count + -1);
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              loop_idx = 0;
              while ((loop_idx < match_count && (g_ActivePlayer != 1))) {
                Pic_Subsystem_00424500(s_prompts_txt_00530514,s_FIREBALL_00530508);
                sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,loop_idx + 1,match_count);
                piVar12 = &local_28;
                uval_2 = 1;
                puVar8 = &g_OverworldGoldAmount;
                uVar13 = 0;
                uVar11 = 0;
                uVar9 = 0;
                uval_7 = 0xffffffff;
                uval_6 = 0xffffffff;
                iVar10 = -1;
                val_1 = -1;
                uval_5 = 0;
                uval_4 = 0;
                uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
                val_1 = Action_ValidateTarget_00405802
                                  (spell_id,2,1 - spell_id,0x1200,2,0,0,uval_3,uval_4,uval_5,val_1,
                                   iVar10,uval_6,uval_7,uVar9,uVar11,uVar13,puVar8,uval_2,piVar12);
                if (val_1 == 0) {
                  g_ActivePlayer = 1;
                }
                else {
                  *(uint32_t *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                       *(uint32_t *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) |
                       0x300000;
                  Ai_EvaluateTacticalPosition(0,0x20);
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
                loop_idx = loop_idx + 1;
              }
              for (loop_idx = 0;
                  loop_idx < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
                  loop_idx = loop_idx + 1) {
                *(uint32_t *)(&g_CardSlot_Flags +
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x120 +
                         *(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x5b20) =
                     *(uint32_t *)(&g_CardSlot_Flags +
                              *(int *)(&g_CardSlot_AttachedAura +
                                      target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x120
                              + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) *
                                0x5b20) & 0xffcfffff;
              }
              if (g_ActivePlayer == 1) {
                (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              }
            }
          }
        }
        else {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_ConvertedManaCost + g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20);
          match_count = (int)(char)(&g_CardSlot_TurnPlayed)
                               [g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20];
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          loop_idx = 0;
          while ((loop_idx < match_count && (g_ActivePlayer != 1))) {
            Pic_Subsystem_00424500(s_prompts_txt_0053052c,s_FIREBALL_00530520);
            sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,loop_idx + 1,match_count);
            piVar12 = &local_28;
            uval_2 = 1;
            puVar8 = &g_OverworldGoldAmount;
            uVar13 = 0;
            uVar11 = 0;
            uVar9 = 0;
            uval_7 = 0xffffffff;
            uval_6 = 0xffffffff;
            iVar10 = -1;
            val_1 = -1;
            uval_5 = 0;
            uval_4 = 0;
            uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
            val_1 = Action_ValidateTarget_00405802
                              (spell_id,2,1 - spell_id,0x1200,2,0,0,uval_3,uval_4,uval_5,val_1,iVar10,
                               uval_6,uval_7,uVar9,uVar11,uVar13,puVar8,uval_2,piVar12);
            if (val_1 == 0) {
              g_ActivePlayer = 1;
            }
            else {
              *(uint32_t *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                   *(uint32_t *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
              Ai_EvaluateTacticalPosition(0,0x20);
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
            loop_idx = loop_idx + 1;
          }
          for (loop_idx = 0;
              loop_idx < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
              loop_idx = loop_idx + 1) {
            *(uint32_t *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_AttachedAura +
                             target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x120 +
                     *(int *)(&g_CardSlot_CombatTarget +
                             target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_AttachedAura +
                                  target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x120 +
                          *(int *)(&g_CardSlot_CombatTarget +
                                  target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8) * 0x5b20) &
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
            val_1 = Util_GetRandomNumber((g_TurnCounter + 1) / 2);
            g_AiDecisionScore = Math_Clamp(val_1 + 1,iVar10,arg_3);
          }
          else {
            g_AiDecisionScore =
                 (int)(char)(&g_CardSlot_TurnPlayed)[g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20];
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
        val_1 = g_TurnCounter - local_30;
        for (loop_idx = 0; loop_idx < local_30; loop_idx = loop_idx + 1) {
          Glue_Subsystem_004df8ba(spell_id,target_id);
          *(int32_t *)
           (&g_CardSlot_CombatTarget +
           target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - loop_idx) * 8) =
               *(int32_t *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          *(int32_t *)
           (&g_CardSlot_AttachedAura +
           target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - loop_idx) * 8) =
               *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = (uint8_t)local_30;
        }
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             (val_1 + 1) / local_30;
      }
    }
    if (flags == 0x71) {
      if (g_CurrentTurnPhase == spell_id) {
        slot_idx = 0;
        for (loop_idx = 0;
            loop_idx < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            loop_idx = loop_idx + 1) {
          uVar13 = 0;
          uVar11 = 0;
          uVar9 = 0;
          uval_7 = 0xffffffff;
          uval_6 = 0xffffffff;
          iVar10 = -1;
          val_1 = -1;
          uval_5 = 0;
          uval_4 = 0;
          uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
          val_1 = Rules_ParseFilter_0040360b
                            (*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8),
                             (char *)0x0,spell_id,2,2,0x1200,2,0,0,uval_3,uval_4,uval_5,val_1,iVar10,
                             uval_6,uval_7,uVar9,uVar11,uVar13);
          if (val_1 == 0) {
            slot_idx = slot_idx + 1;
          }
          else {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8),
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20),spell_id,target_id);
          }
        }
      }
      else {
        val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        for (loop_idx = 0;
            loop_idx < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            loop_idx = loop_idx + 1) {
          *(int32_t *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8);
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + loop_idx * 8);
          Glue_Subsystem_004dfb23(spell_id,target_id,0x71,val_1);
        }
      }
      if ((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == slot_idx) {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Prompts_Load_004fb1e4
 * Entry Point: 004fb1e4
 * Size: 906 bytes
 */


int32_t Prompts_Load_004fb1e4(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    val_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else if ((g_ActivePlayerPriority == spell_id) &&
            (val_2 = Font_DrawString(spell_id,7,2), val_2 == 0)) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530544,s_DETONATE_00530538);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0x40,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,0x40,0,0,uval_3,uval_4,uval_5,
                         val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((int)(char)(&g_MasterCardSubTypeTable2)
                          [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) * 0x34]
               + (int)(char)(&g_MasterCardManaCostTable)
                            [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) *
                             0x34] ==
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)) {
        Mem_AllocOrFree_0041df33
                  (match_count,*(int *)(&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20),spell_id,target_id);
        Pic_Subsystem_0044867e(match_count,slot_idx,1);
      }
      else {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fb573
 * Entry Point: 004fb573
 * Size: 322 bytes
 */


int32_t FUN_004fb573(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((&g_PlayerCreatureCount)[player] - (&g_PlayerCreatureCount)[1 - player]) * 0x18;
    }
    if ((arg_3 == 0x71) && (g_IsAiThinking != 1)) {
      do {
        val_2 = Ai_Subsystem_004b7d38(s_Your_flip_00530550);
        val_3 = Ai_Subsystem_004b7d38(s_Opponent_flip_0053055c);
        if (val_2 == 1) {
          Mem_AllocOrFree_0041df33(0,1,player,card_slot);
        }
        if (val_3 == 1) {
          Mem_AllocOrFree_0041df33(1,1,player,card_slot);
        }
        if ((val_2 != 0) || (val_3 != 0)) {
          Ai_Subsystem_004cc56d
                    (player,player,card_slot,-1,-1,s_Repeating_since_a_tails_came_up__0053056c,0);
        }
      } while ((val_2 != 0) || (val_3 != 0));
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004fb6b5
 * Entry Point: 004fb6b5
 * Size: 1311 bytes
 */


int32_t Prompts_Load_004fb6b5(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint32_t)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,2,0,0,uval_1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((spell_id == g_ActivePlayerPriority) &&
       ((g_OverworldPlayerCoordY == 0 || (val_2 = Font_DrawString(spell_id, 7, 3), val_2 == 0)))) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
    return uval_1;
  }
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = g_TurnCounter;
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    match_count = 0;
    slot_idx = 0;
    while (((match_count < g_TurnCounter && (slot_idx == 0)) && (g_ActivePlayer != 1))) {
      Pic_Subsystem_00424500(s_prompts_txt_005305a0,s_WORDOFBINDING_00530590);
      sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,match_count + 1,g_TurnCounter);
      arg_20 = &player_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        if (card_idx == -1) {
          g_ActivePlayer = 1;
        }
        else {
          slot_idx = 1;
        }
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) | 0x300000;
        Ai_EvaluateTacticalPosition(0,0x20);
        *(int *)(&g_CardSlot_CombatTarget +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             player_idx;
        *(int *)(&g_CardSlot_AttachedAura +
                spell_id * 0x5b20 +
                target_id * 0x120 +
                (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
             card_idx;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
      }
      match_count = match_count + 1;
    }
    for (match_count = 0;
        match_count < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        match_count = match_count + 1) {
      *(uint32_t *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_AttachedAura +
                       match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               *(int *)(&g_CardSlot_CombatTarget +
                       match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_AttachedAura +
                            match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    *(int *)(&g_CardSlot_CombatTarget +
                            match_count * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
           0xffcfffff;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
  }
  if (flags == 0x71) {
    for (match_count = 0;
        match_count < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
        match_count = match_count + 1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget +
                                 match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0,
                         spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,uval_8,uVar9,
                         uVar10,uVar11);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_00415d48(*(int *)(&g_CardSlot_CombatTarget +
                             match_count * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura +
                             match_count * 8 + target_id * 0x120 + spell_id * 0x5b20));
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
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    slot_idx = 0;
    card_idx = 0;
    while (((card_idx < 500 && (slot_idx == 0)) &&
           (*(int *)(&g_PlayerGraveyardList + card_idx * 4 + spell_id * 2000) != -1))) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_PlayerGraveyardList + card_idx * 4 + spell_id * 2000) * 0x34] & 2) != 0) {
        slot_idx = 1;
      }
      card_idx = card_idx + 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_005305b8,s_RAISEDEAD_005305ac);
        do {
          match_count = UI_DeckSelectionMenu(spell_id,(int)(&g_PlayerGraveyardList + spell_id * 2000),500,
                                      &g_OverworldGoldAmount,0);
          if (match_count == -1) break;
        } while (((&g_MasterCardColorTable)
                  [*(int *)(&g_PlayerGraveyardList + match_count * 4 + spell_id * 2000) * 0x34] & 2) == 0);
      }
      else {
        match_count = FUN_004fd9c0(spell_id,2);
      }
      if (((match_count == -1) || (*(int *)(&g_PlayerGraveyardList + match_count * 4 + spell_id * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + match_count * 4 + spell_id * 2000) * 0x34]
          & 2) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = Deck_AddCardToDeck
                          (spell_id,*(int *)(&g_PlayerGraveyardList + match_count * 4 + spell_id * 2000));
        *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + val_1 * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + val_1 * 0x120) | 0x20;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = val_1;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = match_count;
      }
    }
    if (flags == 0x71) {
      val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if (((val_1 == -1) || (*(int *)(&g_PlayerGraveyardList + val_1 * 4 + spell_id * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + val_1 * 4 + spell_id * 2000) * 0x34] &
          2) == 0)) {
        *(int32_t *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0xffffffff;
      }
      else {
        Pic_Subsystem_00449223(spell_id,val_1);
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                 + *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                      0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120) & 0xffffffdf;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: CardScript_DrafnasRestoration
 * Entry Point: 004fc023
 * Size: 706 bytes
 */


int32_t CardScript_DrafnasRestoration(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  uint32_t slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      if ((g_CurrentTurnPhase == player) && (g_IsAiThinking != 1)) {
        val_2 = Ai_Subsystem_004cc814
                          (player,s_Drafna_s_Restoration__005305f4,0,s_My_graveyard_005305e4,
                           s_Opponent_s_graveyard_005305cc,(char *)0x0);
        if (val_2 == 0) {
          match_count = player;
        }
        else {
          match_count = 1 - player;
        }
        slot_idx = UI_DeckSelectionMenu(player,(int)(&g_PlayerGraveyardList + match_count * 2000),500,
                                    s_Pick_an_artifact_00530610,1);
        if ((slot_idx != 0xffffffff) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + match_count * 2000) * 0x34] & 0x40) == 0)) {
          slot_idx = 0xffffffff;
        }
      }
      else {
        match_count = player;
        slot_idx = FUN_004fd9c0(player,0x40);
      }
      if (((slot_idx == 0xffffffff) || (*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + match_count * 2000) == -1)
          ) || (((&g_MasterCardColorTable)
                 [*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + match_count * 2000) * 0x34] & 0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             match_count << 8 | slot_idx;
      }
    }
    if (arg_3 == 0x71) {
      val_2 = *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20);
      if (((val_2 != -1) && (*(int *)(&g_PlayerGraveyardList + val_2 * 4 + match_count * 2000) != -1)) &&
         (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + val_2 * 4 + match_count * 2000) * 0x34] &
          0x40) != 0)) {
        Pic_Subsystem_004524db(match_count,*(int32_t *)(&g_PlayerGraveyardList + val_2 * 4 + match_count * 2000));
        *(int32_t *)(&g_PlayerGraveyardList + val_2 * 4 + match_count * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004fc2e5
 * Entry Point: 004fc2e5
 * Size: 889 bytes
 */


int Prompts_Load_004fc2e5(int spell_id,int target_id,int flags)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    slot_idx = 0;
    card_idx = 0;
    while (((card_idx < 500 && (slot_idx == 0)) &&
           (*(int *)(&g_PlayerGraveyardList + card_idx * 4 + spell_id * 2000) != -1))) {
      slot_idx = 1;
      card_idx = card_idx + 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_00530630,s_REGROWTH_00530624);
        match_count = UI_DeckSelectionMenu(spell_id,(int)(&g_PlayerGraveyardList + spell_id * 2000),500,
                                    &g_OverworldGoldAmount,0);
      }
      else {
        match_count = FUN_004fd9c0(spell_id,0xffffffff);
      }
      if ((match_count == -1) || (*(int *)(&g_PlayerGraveyardList + match_count * 4 + spell_id * 2000) == -1)) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = Deck_AddCardToDeck
                          (spell_id,*(int *)(&g_PlayerGraveyardList + match_count * 4 + spell_id * 2000));
        *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + val_1 * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + val_1 * 0x120) | 0x20;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = val_1;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = match_count;
      }
    }
    if (flags == 0x71) {
      val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if ((val_1 == -1) || (*(int *)(&g_PlayerGraveyardList + val_1 * 4 + spell_id * 2000) == -1)) {
        *(int32_t *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             0xffffffff;
      }
      else {
        Pic_Subsystem_00449223(spell_id,val_1);
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                 + *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                   0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) & 0xffffffdf;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004fc65e
 * Entry Point: 004fc65e
 * Size: 576 bytes
 */


int32_t FUN_004fc65e(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      if ((player == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        do {
          slot_idx = UI_DeckSelectionMenu(player,(int)(&g_PlayerGraveyardList + player * 2000),500,
                                      s_Pick_an_artifact_00530648,1);
          if (slot_idx == -1) break;
        } while (((&g_MasterCardColorTable)
                  [*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) * 0x34] & 0x40) == 0);
      }
      else {
        slot_idx = FUN_004fd9c0(player,0x40);
      }
      if (((slot_idx == -1) || (*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) * 0x34] &
          0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = slot_idx;
      }
    }
    if (arg_3 == 0x71) {
      val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120);
      if ((val_1 != -1) &&
         (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + val_1 * 4 + player * 2000) * 0x34] &
          0x40) != 0)) {
        Deck_AddCardToDeck(player,*(int *)(&g_PlayerGraveyardList + val_1 * 4 + player * 2000));
        *(int32_t *)(&g_PlayerGraveyardList + val_1 * 4 + player * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Prompts_Load_004fc89e
 * Entry Point: 004fc89e
 * Size: 711 bytes
 */


int32_t Prompts_Load_004fc89e(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t card_idx;
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
        (spell_id == g_EventSourcePlayer)) &&
       ((spell_id == g_ActivePlayerPriority && (*(int *)(&g_PlayerDeckCardList + spell_id * 2000) == -1))))
    {
      g_ActivePlayer = 1;
    }
    if (flags == 0x71) {
      if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_0053066c,s_DEMONIC_TUTOR_0053065c);
        slot_idx = UI_DeckSelectionMenu(spell_id,(int)(&g_PlayerDeckCardList + spell_id * 2000),500,
                                    &g_OverworldGoldAmount,1);
        if ((slot_idx != -1) && (*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + spell_id * 2000) != -1)) {
          Deck_AddCardToDeck(spell_id,*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + spell_id * 2000));
          Pic_Subsystem_004523fd(spell_id,slot_idx);
        }
      }
      else {
        if (spell_id == g_CurrentTurnPhase) {
          card_idx = 0x42;
        }
        else {
          if (g_IsAiThinking == 1) {
            g_AiDecisionScore = Util_GetRandomNumber(4);
            Ai_EvaluateCreaturePower();
          }
          else {
            Ai_CalcCardAdvantage();
          }
          switch(g_AiDecisionScore) {
          case 0:
            card_idx = 2;
            break;
          case 1:
            card_idx = 0x40;
            break;
          case 2:
            card_idx = 8;
            break;
          case 3:
            card_idx = 0x10;
          }
        }
        slot_idx = FUN_004fdad2(spell_id,spell_id,card_idx);
        if (slot_idx == -1) {
          slot_idx = FUN_004fdad2(spell_id,spell_id,0xffffffff);
        }
        if ((slot_idx != -1) && (*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + spell_id * 2000) != -1)) {
          Deck_AddCardToDeck(spell_id,*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + spell_id * 2000));
          Pic_Subsystem_004523fd(spell_id,slot_idx);
        }
      }
      if (slot_idx != -1) {
        Ai_EvaluateTacticalPosition(0,0x30);
        Pic_Subsystem_00452276(spell_id);
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004fcb7a
 * Entry Point: 004fcb7a
 * Size: 880 bytes
 */


int32_t Prompts_Load_004fcb7a(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int32_t uval_2;
  int arg2;
  int player_idx;
  int match_count;
  
  if (flags == 0x74) {
    uval_2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (flags == 0x71) {
      if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_0053068c,s_UNTAMED_WILDS_0053067c);
        flag_1 = false;
        player_idx = 0;
        while (((player_idx < 500 && (!flag_1)) &&
               (*(int *)(&g_PlayerDeckCardList + player_idx * 4 + spell_id * 2000) != -1))) {
          if (*(int *)(&g_PlayerDeckCardList + player_idx * 4 + spell_id * 2000) < 5) {
            flag_1 = true;
          }
          player_idx = player_idx + 1;
        }
        if (flag_1) {
          do {
            match_count = UI_DeckSelectionMenu(spell_id,(int)(&g_PlayerDeckCardList + spell_id * 2000),500,
                                        &g_OverworldGoldAmount,1);
            if (match_count == -1) break;
          } while (4 < *(int *)(&g_PlayerDeckCardList + match_count * 4 + spell_id * 2000));
        }
        else {
          match_count = -1;
          UI_DeckSelectionMenu(spell_id,(int)(&g_PlayerDeckCardList + spell_id * 2000),500,
                            &g_OverworldGoldAmount,0);
        }
      }
      else {
        match_count = FUN_004fdad2(spell_id,spell_id,1);
        if ((match_count != -1) && (4 < *(int *)(&g_PlayerDeckCardList + match_count * 4 + spell_id * 2000))) {
          match_count = -1;
          player_idx = 0;
          while (((player_idx < 500 && (match_count == -1)) &&
                 (*(int *)(&g_PlayerDeckCardList + player_idx * 4 + spell_id * 2000) != -1))) {
            if (*(int *)(&g_PlayerDeckCardList + player_idx * 4 + spell_id * 2000) < 5) {
              match_count = player_idx;
            }
            player_idx = player_idx + 1;
          }
        }
      }
      if ((match_count != -1) &&
         ((*(int *)(&g_PlayerDeckCardList + match_count * 4 + spell_id * 2000) == -1 ||
          (4 < *(int *)(&g_PlayerDeckCardList + match_count * 4 + spell_id * 2000))))) {
        match_count = -1;
      }
      if (((match_count != -1) && (*(int *)(&g_PlayerDeckCardList + match_count * 4 + spell_id * 2000) != -1)) &&
         (arg2 = Deck_AddCardToDeck
                           (spell_id,*(int *)(&g_PlayerDeckCardList + match_count * 4 + spell_id * 2000)),
         arg2 != -1)) {
        Pic_Subsystem_004523fd(spell_id,match_count);
        Pic_Subsystem_0042ac1f(spell_id,arg2);
        Ai_EvaluateTacticalPosition(0,0x30);
      }
      Pic_Subsystem_00452276(spell_id);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Prompts_Load_004fceea
 * Entry Point: 004fceea
 * Size: 561 bytes
 */


int32_t Prompts_Load_004fceea(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int32_t slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005306ac,s_VISIONS_005306a4);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&match_count);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      if (((spell_id == 0) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_005306c0,s_VISIONS_005306b8);
        UI_DeckSelectionMenu(0,(int)(&g_PlayerDeckCardList +
                                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120) * 2000),5,
                          &DAT_0069f84a,0);
      }
      val_2 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,
                         s_Shuffle_library__Don_t_shuffle__005306d4,1);
      if (val_2 == 0) {
        Pic_Subsystem_00452276
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fd11b
 * Entry Point: 004fd11b
 * Size: 692 bytes
 */


int32_t FUN_004fd11b(int player_id,int card_slot,int event_type)

{
  char cVar1;
  char cVar2;
  int arg2;
  int32_t uval_3;
  int val_4;
  int color_idx;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      if ((g_CurrentTurnPhase == player) && (g_IsAiThinking != 1)) {
        slot_idx = UI_DeckSelectionMenu(player,(int)(&g_PlayerDeckCardList + player * 2000),500,
                                    s_Pick_an_artifact_005306fc,1);
      }
      else {
        slot_idx = FUN_004fdad2(player,player,0x40);
      }
      if ((slot_idx == -1) || (*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + player * 2000) == -1)) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = slot_idx;
      }
    }
    if (arg_3 == 0x71) {
      val_4 = *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20);
      if ((*(int *)(&g_PlayerDeckCardList + val_4 * 4 + player * 2000) != -1) &&
         (arg2 = *(int *)(&g_PlayerDeckCardList + val_4 * 4 + player * 2000),
         ((&g_MasterCardColorTable)[arg2 * 0x34] & 0x40) != 0)) {
        Pic_Subsystem_004523fd(player,val_4);
        if (color_idx != -1) {
          val_4 = *(int *)(&g_CardSlot_CardId + color_idx * 0x120 + player * 0x5b20);
          Pic_Subsystem_0044867e(player,color_idx,2);
          cVar1 = (&g_MasterCardManaCostTable)[arg2 * 0x34];
          cVar2 = (&g_MasterCardManaCostTable)[val_4 * 0x34];
          while (0 < (int)cVar1 - (int)cVar2) {
            val_4 = Font_DrawString(player,7,1);
            if (val_4 == 0) break;
            Ai_CalcManaRequirement_004ba890(player,0,1);
          }
          if ((int)cVar1 - (int)cVar2 < 1) {
            val_4 = Deck_AddCardToDeck(player,arg2);
            if (val_4 != -1) {
              *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + val_4 * 0x120) =
                   *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + val_4 * 0x120) | 0x30002;
            }
          }
        }
      }
      Pic_Subsystem_00452276(player);
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Prompts_Load_004fd3cf
 * Entry Point: 004fd3cf
 * Size: 533 bytes
 */


int32_t Prompts_Load_004fd3cf(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int card_idx;
  int32_t match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (val_1 = Font_DrawString(spell_id,7,2), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0053071c,s_MINDTWIST_00530710);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&card_idx);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      for (slot_idx = 0;
          slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
          slot_idx = slot_idx + 1) {
        Prompts_Load_0046fa40
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),1,0);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004fd5e4
 * Entry Point: 004fd5e4
 * Size: 608 bytes
 */


int32_t FUN_004fd5e4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  char local_d8 [200];
  int card_idx;
  int match_count;
  uint32_t slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
        if ((&g_ActivePlayerSpellPriority)[card_idx] == 0) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530728);
          slot_idx = 0;
        }
        else if ((&g_ActivePlayerSpellPriority)[card_idx] == 1) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_005307a4);
          slot_idx = (uint32_t)((int)(&g_PlayerCreatureCount)[card_idx] < 5);
        }
        else if ((&g_ActivePlayerSpellPriority)[card_idx] == 2) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530820);
          if ((int)(&g_PlayerCreatureCount)[card_idx] < 5) {
            slot_idx = 2;
          }
          else {
            slot_idx = 0;
          }
        }
        else {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530898);
          if ((int)(&g_PlayerCreatureCount)[card_idx] < 5) {
            slot_idx = 3;
          }
          else {
            slot_idx = 0;
          }
        }
        match_count = Ai_Subsystem_004cc56d(card_idx,player,card_slot,-1,-1,local_d8,slot_idx);
        if (match_count == 1) {
          Mem_AllocOrFree_0041df33(card_idx,2,player,card_slot);
          Prompts_Load_0046fa40(card_idx,0,1);
        }
        else if (match_count == 2) {
          Mem_AllocOrFree_0041df33(card_idx,1,player,card_slot);
          Prompts_Load_0046fa40(card_idx,0,1);
          Prompts_Load_0046fa40(card_idx,0,1);
        }
        else if (match_count == 3) {
          Prompts_Load_0046fa40(card_idx,0,1);
          Prompts_Load_0046fa40(card_idx,0,1);
          Prompts_Load_0046fa40(card_idx,0,1);
        }
        else {
          Mem_AllocOrFree_0041df33(card_idx,3,player,card_slot);
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fd844
 * Entry Point: 004fd844
 * Size: 380 bytes
 */


int32_t FUN_004fd844(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      if ((g_CurrentTurnPhase == player) && (g_IsAiThinking != 1)) {
        slot_idx = UI_DeckSelectionMenu(player,(int)(&g_PlayerGraveyardList + player * 2000),500,
                                    s_Pick_a_creature_00530914,1);
      }
      else {
        slot_idx = FUN_004fd9c0(player,2);
      }
      if (((slot_idx != -1) && (*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) != -1)) &&
         (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) * 0x34] &
          2) != 0)) {
        val_2 = Deck_AddCardToDeck(player,*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000));
        if (val_2 != -1) {
          *(int32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + player * 0x5b20) = 0x30002;
        }
        *(int32_t *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fd9c0
 * Entry Point: 004fd9c0
 * Size: 274 bytes
 */


int FUN_004fd9c0(int arg1,uint32_t arg2)

{
  int val_1;
  int val_2;
  int target_idx;
  int player_idx;
  int card_idx;
  
  player_idx = 0;
  card_idx = -1;
  if (arg1 == -1) {
    card_idx = -1;
  }
  else {
    target_idx = 0;
    while ((target_idx < 500 && (*(int *)(&g_PlayerGraveyardList + target_idx * 4 + arg1 * 2000) != -1))) {
      val_1 = *(int *)(&g_PlayerGraveyardList + target_idx * 4 + arg1 * 2000);
      if ((arg2 == 0xffffffff) || ((arg2 & (uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34]) != 0)) {
        val_2 = abs((int)(char)(&g_MasterCardManaCostTable)[val_1 * 0x34]);
        val_1 = (char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34] * 3 + val_2 * 2;
        if (player_idx < val_1) {
          card_idx = target_idx;
          player_idx = val_1;
        }
      }
      target_idx = target_idx + 1;
    }
  }
  return card_idx;
}



/*
 * Decompiled function: FUN_004fdad2
 * Entry Point: 004fdad2
 * Size: 334 bytes
 */


int FUN_004fdad2(int player_id,int card_slot,uint32_t arg_3)

{
  int val_1;
  int target_idx;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  player_idx = -99;
  card_idx = -1;
  if (card_slot == -1) {
    card_idx = -1;
  }
  else {
    target_idx = 0;
    while ((target_idx < 500 && (*(int *)(&g_PlayerDeckCardList + target_idx * 4 + card_slot * 2000) != -1))) {
      val_1 = *(int *)(&g_PlayerDeckCardList + target_idx * 4 + card_slot * 2000);
      if ((arg_3 == 0xffffffff) || ((arg_3 & (uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34]) != 0)) {
        slot_idx = abs((int)(char)(&g_MasterCardManaCostTable)[val_1 * 0x34]);
        slot_idx = slot_idx + (char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34] * 2;
        if (*(int *)(&g_PlayerManaPoolDelta + player * 0x20) < slot_idx) {
          slot_idx = -slot_idx;
        }
        if (slot_idx == 0) {
          slot_idx = 99;
        }
        val_1 = File_Load_Info(val_1);
        slot_idx = slot_idx + val_1 * 2;
        if (player_idx < slot_idx) {
          card_idx = target_idx;
          player_idx = slot_idx;
        }
      }
      target_idx = target_idx + 1;
    }
  }
  return card_idx;
}



/*
 * Decompiled function: FUN_004fdc20
 * Entry Point: 004fdc20
 * Size: 299 bytes
 */


int FUN_004fdc20(int x,int y,uint32_t width,int height)

{
  int val_1;
  int target_idx;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  player_idx = -99;
  card_idx = -1;
  if (y == -1) {
    card_idx = -1;
  }
  else {
    for (target_idx = 0; (*(int *)(height + target_idx * 4) != -1 && (target_idx < 0x50));
        target_idx = target_idx + 1) {
      val_1 = *(int *)(height + target_idx * 4);
      if ((width == 0xffffffff) || ((width & (uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34]) != 0)) {
        slot_idx = abs((int)(char)(&g_MasterCardManaCostTable)[val_1 * 0x34]);
        slot_idx = slot_idx + (char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34] * 2;
        if (*(int *)(&g_PlayerManaPoolDelta + x * 0x20) < slot_idx) {
          slot_idx = -slot_idx;
        }
        if (slot_idx == 0) {
          slot_idx = 99;
        }
        val_1 = File_Load_Info(val_1);
        slot_idx = slot_idx + val_1 * 2;
        if (player_idx < slot_idx) {
          card_idx = target_idx;
          player_idx = slot_idx;
        }
      }
    }
  }
  return card_idx;
}



/*
 * Decompiled function: FUN_004fdd4b
 * Entry Point: 004fdd4b
 * Size: 237 bytes
 */


int32_t FUN_004fdd4b(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = Card_IsTapped(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0)
             ) {
            Pic_Subsystem_0044867e(slot_idx,match_count,1);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fde38
 * Entry Point: 004fde38
 * Size: 314 bytes
 */


int32_t FUN_004fde38(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = Card_IsTapped(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 1) != 0)
             ) {
            val_2 = *(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20);
            val_3 = Card_UntapCard(player,card_slot,5);
            if (*(int *)(&g_MasterCardTypeTable + val_2 * 0x34) ==
                *(int *)(&DAT_006ff2bc + val_3 * 4)) {
              Pic_Subsystem_0044867e(slot_idx,match_count,2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004fdf72
 * Entry Point: 004fdf72
 * Size: 237 bytes
 */


int32_t FUN_004fdf72(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = Card_IsTapped(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 0x40) !=
              0)) {
            Pic_Subsystem_0044867e(slot_idx,match_count,1);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004fe05f
 * Entry Point: 004fe05f
 * Size: 1568 bytes
 */


int32_t Prompts_Load_004fe05f(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint8_t *arg_18;
  uint32_t uVar9;
  uint32_t uVar10;
  int *arg_20;
  uint32_t uVar11;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        Pic_Subsystem_00424500(s_prompts_txt_00530934,s_PYROTECHNICS_00530924);
        match_count = 0;
        while ((match_count < 4 && (g_ActivePlayer != 1))) {
          arg_20 = &player_idx;
          uval_1 = 1;
          arg_18 = &g_OverworldGoldAmount + match_count * 0xfa;
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uval_8 = 0xffffffff;
          uval_7 = 0xffffffff;
          val_6 = -1;
          val_5 = -1;
          uval_4 = 0;
          uval_3 = 0;
          uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          val_5 = Action_ValidateTarget_00405802
                            (spell_id,2,1 - spell_id,0x1200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,
                             uval_7,uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
          if (val_5 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) | 0x200000;
            Ai_EvaluateTacticalPosition(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + match_count * 8)
                 = player_idx;
            *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + match_count * 8)
                 = card_idx;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          match_count = match_count + 1;
        }
        for (match_count = 0;
            match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            match_count = match_count + 1) {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x5b20) &
               0xffcfffff;
        }
        if (g_ActivePlayer == 1) {
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        }
      }
      else {
        for (match_count = 0; match_count < 4; match_count = match_count + 1) {
          Glue_Subsystem_004df8ba(spell_id,target_id);
          *(int32_t *)
           (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + (3 - match_count) * 8) =
               *(int32_t *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          *(int32_t *)
           (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + (3 - match_count) * 8) =
               *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 4;
        }
      }
    }
    if (flags == 0x71) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        slot_idx = 0;
        for (match_count = 0;
            match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            match_count = match_count + 1) {
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uval_8 = 0xffffffff;
          uval_7 = 0xffffffff;
          val_6 = -1;
          val_5 = -1;
          uval_4 = 0;
          uval_3 = 0;
          uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          val_5 = Rules_ParseFilter_0040360b
                            (*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                             (char *)0x0,spell_id,2,2,0x1200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,
                             uval_7,uval_8,uVar9,uVar10,uVar11);
          if (val_5 == 0) {
            slot_idx = slot_idx + 1;
          }
          else {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + match_count * 8),1,spell_id,
                         target_id);
          }
        }
        if ((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == slot_idx) {
          g_ActivePlayer = 1;
        }
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
      else {
        for (match_count = 0; match_count < 4; match_count = match_count + 1) {
          *(int32_t *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + match_count * 8);
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + match_count * 8);
          Glue_Subsystem_004dfb23(spell_id,target_id,0x71,1);
        }
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004fe67f
 * Entry Point: 004fe67f
 * Size: 642 bytes
 */


int32_t Prompts_Load_004fe67f(int spell_id,int target_id,int flags)

{
  int arg_5;
  int val_1;
  int32_t uval_2;
  int val_3;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (val_1 = Font_DrawString(spell_id,7,2), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           g_TurnCounter;
      Pic_Subsystem_00424500(s_prompts_txt_00530950,s_DISINTEGRATE_00530940);
      val_1 = Glue_Subsystem_004df8ba(spell_id,target_id);
      if (val_1 != 0) {
        val_1 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20));
        g_SpellStackDepth = g_SpellStackDepth - (int)(0x30 / (longlong)val_1);
      }
    }
    if (flags == 0x71) {
      val_1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      arg_5 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      val_3 = Glue_Subsystem_004dfb23
                        (spell_id,target_id,0x71,
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20));
      if ((val_3 != 0) &&
         (*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        val_3 = Card_ApplyTriggerEffect(spell_id,target_id,DAT_006a49ec,val_1,arg_5);
        if (val_3 != -1) {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_3 * 0x120 + spell_id * 0x5b20) = 0x200
          ;
        }
        *(int32_t *)(&g_CardSlot_Abilities2 + arg_5 * 0x120 + val_1 * 0x5b20) = 0x8000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004fe901
 * Entry Point: 004fe901
 * Size: 181 bytes
 */


int32_t FUN_004fe901(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  int val_4;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      val_3 = player;
      val_4 = card_slot;
      val_2 = Card_UntapCard(player,card_slot,4);
      Mem_AllocOrFree_0041df33
                (1 - player,*(int *)(&g_AiCombatScore_Attacker + val_2 * 4 + player * 0x20),val_3,val_4);
      val_3 = player;
      val_4 = card_slot;
      val_2 = Card_UntapCard(player,card_slot,4);
      Mem_AllocOrFree_0041df33
                (player,(*(int *)(&g_AiCombatScore_Attacker + val_2 * 4 + player * 0x20) + 1) / 2,val_3,val_4);
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004fe9b6
 * Entry Point: 004fe9b6
 * Size: 1451 bytes
 */


int32_t Prompts_Load_004fe9b6(int spell_id,int target_id,int flags)

{
  int y;
  int val_1;
  int32_t uval_2;
  int val_3;
  int slot_idx;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (val_1 = Font_DrawString(spell_id, 7, 3), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
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
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)
              (&g_CardSlot_ConvertedManaCost + g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20);
      }
      Pic_Subsystem_00424500(s_prompts_txt_00530968,s_DRAIN_LIFE_0053095c);
      Glue_Subsystem_004df8ba(spell_id,target_id);
    }
    if (flags == 0x71) {
      val_1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      y = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      val_3 = Glue_Subsystem_004dfb23
                        (spell_id,target_id,0x71,
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20));
      if ((val_3 == 0) ||
         (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) < 1)) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      else {
        if (y == -1) {
          slot_idx = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
          if ((int)(&g_PlayerCreatureCount)[val_1] <=
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)) {
            slot_idx = (&g_PlayerCreatureCount)[val_1];
          }
        }
        else {
          val_3 = Card_TapForMana(val_1,y,0x33,0xffffffff);
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) <
              val_3) {
            slot_idx = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20
                              );
          }
          else {
            slot_idx = Card_TapForMana(val_1,y,0x33,0xffffffff);
          }
        }
        if (slot_idx < 0) {
          slot_idx = 0;
        }
        val_1 = Deck_AddCardToDeck(spell_id,DAT_006fdbd0);
        if (val_1 != -1) {
          *(int32_t *)(&g_ActiveCardsInPlay + val_1 * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20);
          *(uint32_t *)(&g_CardSlot_Flags + val_1 * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + val_1 * 0x120 + spell_id * 0x5b20) | 2;
          *(int32_t *)(&DAT_006a5f74 + val_1 * 0x120 + spell_id * 0x5b20) = 0x44;
          *(int32_t *)(&DAT_006a5f80 + val_1 * 0x120 + spell_id * 0x5b20) = 0xd7;
          *(int *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + spell_id * 0x5b20) = slot_idx;
          FUN_00476482(spell_id,val_1);
          (&g_CardSlot_DamageReceived)[val_1 * 0x120 + spell_id * 0x5b20] = (uint8_t)spell_id;
          *(int *)(&g_CardSlot_TypeFlags + val_1 * 0x120 + spell_id * 0x5b20) = target_id;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    if (((flags == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                 ) == g_PendingSpellTargetSlot)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == -1 &&
        ((((char)(&g_CardSlot_DamageReceived)
                 [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] == spell_id &&
          (*(int *)(&g_CardSlot_TypeFlags +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == target_id)) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) != 0)))))) {
      (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
           (uint8_t)g_EventSourcePlayer;
      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = g_EventSourceSlot;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Prompts_Load_004fef61
 * Entry Point: 004fef61
 * Size: 542 bytes
 */


int32_t Prompts_Load_004fef61(int spell_id,int target_id,int flags)

{
  int color_mask;
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int val_3;
  int32_t arg_14;
  int arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  
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
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530980,s_STONE_RAIN_00530974);
      val_2 = Glue_Subsystem_004e6dcc(spell_id,2,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth +
             ((-(uint32_t)(*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
                      spell_id) & 0xfffffffb) * 3 + 9) * 4;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      val_2 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (val_2,color_mask,(char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,
                         val_3,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(val_2,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_004ff17f
 * Entry Point: 004ff17f
 * Size: 492 bytes
 */


int32_t Prompts_Load_004ff17f(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int player_idx;
  int32_t card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00530998,s_DRAIN_POWER_0053098c);
      val_2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&player_idx);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = card_idx
        ;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      slot_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      Glue_Subsystem_004e65e1(FUN_004ff36b,slot_idx);
      if (slot_idx != spell_id) {
        for (match_count = 0; match_count < 8; match_count = match_count + 1) {
          *(int *)(&g_AiLookaheadDepth + match_count * 4 + spell_id * 0x20) =
               *(int *)(&g_AiLookaheadDepth + match_count * 4 + spell_id * 0x20) +
               *(int *)(&g_AiLookaheadDepth + match_count * 4 + slot_idx * 0x20);
          *(int32_t *)(&g_AiLookaheadDepth + match_count * 4 + slot_idx * 0x20) = 0;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004ff36b
 * Entry Point: 004ff36b
 * Size: 228 bytes
 */


int32_t FUN_004ff36b(int player_id,int card_slot,int event_type)

{
  g_AiManaPoolReserve = 1;
  g_PendingAttackersTargetSlot = 0xffffffff;
  if (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 1) != 0)) &&
     (((&g_MasterCardFlagsTable)[arg_3 * 0x34] & 0x10) != 0)) {
    Magic_TriggerCardEvent(player,card_slot,0x6d,1 - player,0xffffffff);
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0) {
      Rules_ApplyContinuousDamage(player,card_slot,0x81);
    }
  }
  g_AiManaPoolReserve = 0;
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
      UI_LoadGraveyardBackdrops(0,DAT_006a3f60,DAT_006fe44c);
    }
    else {
      UI_LoadGraveyardBackdrops(0,DAT_006fe448,DAT_006fe44c);
    }
    LockWindowUpdate(g_MainAppHwnd);
    UI_ShowDuelArenaWindow(0,0);
    UI_ShowDuelArenaWindow(1,0);
    Pic_Subsystem_004441cc(g_MainAppHwnd,g_DuelArenaStatusFlags);
    FUN_00478163(DAT_007006b0);
    Glue_Subsystem_004eee4e(g_TurnPriorityState);
    Glue_Subsystem_004eee4e(g_AiSelectedActionCode);
    Pic_Subsystem_0044cfe4(g_AiLookaheadTreeRoot);
    Pic_Subsystem_0044cfe4(g_AiDuelTurnState);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(g_AiLookaheadTreeRoot,0x435,0,0);
    SendMessageA(g_AiDuelTurnState,0x435,0,0);
    SendMessageA(g_TurnPriorityState,0x435,0,0);
    SendMessageA(g_AiSelectedActionCode,0x435,0,0);
    SendMessageA(g_AiDecisionMatrix_Row,0x435,0,0);
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


HBRUSH UI_DialogProc_004ff5c6(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

{
  UINT UVar1;
  HWND pHVar2;
  HBRUSH pHVar3;
  BOOL bEnable;
  tagRECT local_38;
  COLORREF local_28;
  HWND local_24;
  HWND loop_idx;
  int color_idx;
  HDC target_idx;
  HWND card_idx;
  HWND match_count;
  int slot_idx;
  
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
      target_idx = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      loop_idx = lParam;
      color_idx = GetDlgCtrlID(lParam);
      if ((color_idx != 0x3ff) && (color_idx != 0x40d)) {
        if (color_idx == 0x48b) {
          SetTextColor(target_idx,DAT_0061d854);
          SetBkMode(target_idx,1);
          pHVar3 = GetStockObject(5);
          return pHVar3;
        }
        pHVar2 = GetFocus();
        if (pHVar2 == loop_idx) {
          SetTextColor(target_idx,DAT_0061d85c);
        }
        else {
          SetTextColor(target_idx,DAT_0061d868);
        }
        SetBkMode(target_idx,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetTextColor(target_idx,DAT_0061d868);
      SetBkMode(target_idx,1);
      return DAT_0061d864;
    }
    if (uMsg == 0x110) {
      Pic_Load_s_WINBK_Options_004ffd9c
                (&DAT_0061d858,&DAT_0061d854,&DAT_0061d868,(int *)&DAT_0061d864,(int *)&DAT_0061d850
                 ,(int *)&DAT_0061d860,&DAT_0061d86c,&DAT_0061d85c);
      if (g_DuelArenaStatusFlags == 1) {
        slot_idx = 0x400;
      }
      else {
        slot_idx = 0x401;
      }
      CheckDlgButton(hwnd,slot_idx,1);
      CheckRadioButton(hwnd,0x400,0x401,slot_idx);
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
      if (((uint8_t)DAT_006fe410 & 1) == 0) {
        bEnable = 0;
        pHVar2 = GetDlgItem(hwnd,0x495);
        EnableWindow(pHVar2,bEnable);
        CheckDlgButton(hwnd,0x495,1);
      }
      if (DAT_006fe448 == 1) {
        slot_idx = 0x409;
      }
      else if (DAT_006fe448 == 2) {
        slot_idx = 0x408;
      }
      else if (DAT_006fe448 == 3) {
        slot_idx = 0x40b;
      }
      else if (DAT_006fe448 == 5) {
        slot_idx = 0x407;
      }
      else if (DAT_006fe448 == 4) {
        slot_idx = 0x40a;
      }
      else {
        slot_idx = 0x40c;
      }
      CheckDlgButton(hwnd,slot_idx,1);
      CheckRadioButton(hwnd,0x407,0x40c,slot_idx);
      if (DAT_006fe44c == 0) {
        slot_idx = 0x40e;
      }
      else if (DAT_006fe44c == 1) {
        slot_idx = 0x40f;
      }
      else {
        slot_idx = 0x410;
      }
      CheckDlgButton(hwnd,slot_idx,1);
      CheckRadioButton(hwnd,0x40e,0x410,slot_idx);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint32_t)wParam & 0xffff) == 2) {
        FUN_004ffe82(DAT_0061d858,DAT_0061d864,DAT_0061d850,DAT_0061d860);
        EndDialog(hwnd,0);
      }
      else if (((uint32_t)wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x400);
        if (UVar1 == 0) {
          g_DuelArenaStatusFlags = 2;
        }
        else {
          g_DuelArenaStatusFlags = 1;
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
      match_count = (HWND)wParam;
      card_idx = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == match_count) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (match_count != (HWND)0x0) {
        InvalidateRect(match_count,(RECT *)0x0,1);
      }
      if (card_idx != (HWND)0x0) {
        InvalidateRect(card_idx,(RECT *)0x0,1);
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
               (int32_t *player,int32_t *out_buffer,int32_t *arg_3,int *arg_4,int *arg_5,
               int *arg_6,int32_t *arg_7,int32_t *arg_8)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_Options_pic_00530a20,&g_AiCurrentChoiceIndex);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *player = uval_1;
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


void FUN_004ffe82(HANDLE player,HGDIOBJ card_slot,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (player != (HANDLE)0x0) {
    Pic_DestroyDIBSection(player);
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
  int val_2;
  int local_90;
  int local_8c;
  BYTE *local_88;
  BYTE local_84 [100];
  int loop_idx;
  int color_idx;
  HKEY target_idx;
  BYTE player_idx [12];
  DWORD slot_idx;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a4,0,1,
                        &target_idx);
  if (LVar1 == 0) {
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_Layout_00530a38,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,&slot_idx)
    ;
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530a40,&g_DuelArenaStatusFlags);
    }
    else {
      g_DuelArenaStatusFlags = 1;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_DirectiveTracksMouse_00530a44,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530a5c,&DAT_006fe424);
    }
    else {
      DAT_006fe424 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowCueCards_00530a60,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,
                             &slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530a70,&DAT_006fe420);
    }
    else {
      DAT_006fe420 = 1;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowPowerToughnessOnCards_00530a74,(LPDWORD)0x0,(LPDWORD)0x0
                             ,player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530a90,&DAT_006fe428);
    }
    else {
      DAT_006fe428 = 1;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowIDTagsOnCards_00530a94,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530aa8,&DAT_006fe438);
    }
    else {
      DAT_006fe438 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowInvisibleEffectCards_00530aac,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530ac8,&DAT_006fe43c);
    }
    else {
      DAT_006fe43c = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowAllCardsSummonSickness_00530acc,(LPDWORD)0x0,
                             (LPDWORD)0x0,player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530ae8,&DAT_006fe440);
    }
    else {
      DAT_006fe440 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    RegQueryValueExA(target_idx,s_ShowAbilitiesOnCards_00530aec,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,
                     &slot_idx);
    if (player_idx[0] == '\0') {
      DAT_006fe42c = 1;
    }
    else {
      sscanf((char *)player_idx,&DAT_00530b04,&DAT_006fe42c);
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ExpandTextBoxOnBigCard_00530b08,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530b20,&DAT_006fe430);
    }
    else {
      DAT_006fe430 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_SeeNextDrawsAtEndOfDuel_00530b24,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)player_idx,&DAT_00530b3c,&DAT_006fe434);
    }
    else {
      DAT_006fe434 = 1;
    }
    slot_idx = 100;
    local_84[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_PhaseStoppers_00530b40,(LPDWORD)0x0,(LPDWORD)0x0,local_84,
                             &slot_idx);
    if (LVar1 == 0) {
      local_88 = local_84;
      color_idx = 0;
      while ((color_idx < 2 && (*local_88 != '\0'))) {
        loop_idx = 0;
        while ((loop_idx < 0x25 && (*local_88 != '\0'))) {
          if (*local_88 == 'S') {
            *(int32_t *)(&g_PlayerManaPoolAvailable + loop_idx * 4 + color_idx * 0x98) = 1;
          }
          else {
            *(int32_t *)(&g_PlayerManaPoolAvailable + loop_idx * 4 + color_idx * 0x98) = 0;
          }
          loop_idx = loop_idx + 1;
          local_88 = local_88 + 1;
        }
        color_idx = color_idx + 1;
      }
    }
    else {
      for (color_idx = 0; color_idx < 2; color_idx = color_idx + 1) {
        for (loop_idx = 0; loop_idx < 0x25; loop_idx = loop_idx + 1) {
          *(int32_t *)(&g_PlayerManaPoolAvailable + loop_idx * 4 + color_idx * 0x98) = 0;
        }
      }
      _DAT_00696790 = 1;
      _DAT_006967b8 = 1;
      DAT_00696854 = 1;
    }
    if (((uint8_t)DAT_006fe410 & 1) == 0) {
      slot_idx = 10;
      player_idx[0] = '\0';
      LVar1 = RegQueryValueExA(target_idx,s_PlayerTerritoryColor_00530b50,(LPDWORD)0x0,(LPDWORD)0x0,
                               player_idx,&slot_idx);
      if (LVar1 == 0) {
        sscanf((char *)player_idx,&DAT_00530b68,&DAT_006fe448);
      }
      else {
        DAT_006fe448 = 0xffffffff;
      }
    }
    if (((uint8_t)DAT_006fe410 & 1) == 0) {
      slot_idx = 10;
      player_idx[0] = '\0';
      LVar1 = RegQueryValueExA(target_idx,s_PlayerTerritoryType_00530b6c,(LPDWORD)0x0,(LPDWORD)0x0,
                               player_idx,&slot_idx);
      if (LVar1 == 0) {
        sscanf((char *)player_idx,&DAT_00530b80,&DAT_006fe44c);
      }
      else {
        DAT_006fe44c = 2;
      }
    }
    slot_idx = 10;
    LVar1 = RegQueryValueExA(target_idx,s_CoolKimCheats_00530b84,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,
                             &slot_idx);
    if (LVar1 == 0) {
      val_2 = strcmp((char *)player_idx,s_HolyMoly_00530b94);
      DAT_006b2d38 = (uint32_t)(val_2 == 0);
    }
    else {
      DAT_006b2d38 = 0;
    }
  }
  else {
    g_DuelArenaStatusFlags = 1;
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
        *(int32_t *)(&g_PlayerManaPoolAvailable + local_90 * 4 + local_8c * 0x98) = 0;
      }
    }
    _DAT_00696790 = 1;
    _DAT_006967a0 = 1;
    _DAT_006967b8 = 1;
    DAT_00696830 = 1;
    _DAT_00696838 = 1;
    DAT_00696854 = 1;
    if (((uint8_t)DAT_006fe410 & 1) == 0) {
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
  size_t len_2;
  BYTE *local_88;
  BYTE local_84 [100];
  int loop_idx;
  int color_idx;
  HKEY target_idx;
  BYTE player_idx [12];
  DWORD slot_idx;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a4,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&target_idx,&slot_idx);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)player_idx,&DAT_00530ba0,g_DuelArenaStatusFlags);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_Layout_00530ba4,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530bac,DAT_006fe424);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_DirectiveTracksMouse_00530bb0,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530bc8,DAT_006fe420);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowCueCards_00530bcc,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530bdc,DAT_006fe428);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowPowerToughnessOnCards_00530be0,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530bfc,DAT_006fe42c);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowAbilitiesOnCards_00530c00,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530c18,DAT_006fe438);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowIDTagsOnCards_00530c1c,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530c30,DAT_006fe43c);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowInvisibleEffectCards_00530c34,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530c50,DAT_006fe440);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowAllCardsSummonSickness_00530c54,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530c70,DAT_006fe430);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ExpandTextBoxOnBigCard_00530c74,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530c8c,DAT_006fe434);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_SeeNextDrawsAtEndOfDuel_00530c90,0,1,player_idx,len_2 + 1);
    local_88 = local_84;
    for (color_idx = 0; color_idx < 2; color_idx = color_idx + 1) {
      for (loop_idx = 0; loop_idx < 0x25; loop_idx = loop_idx + 1) {
        if (((&g_PlayerManaPoolAvailable)[loop_idx * 4 + color_idx * 0x98] & 1) == 0) {
          *local_88 = '-';
        }
        else {
          *local_88 = 'S';
        }
        local_88 = local_88 + 1;
      }
    }
    *local_88 = '\0';
    len_2 = strlen((char *)local_84);
    RegSetValueExA(target_idx,s_PhaseStoppers_00530ca8,0,1,local_84,len_2 + 1);
    if (((uint8_t)DAT_006fe410 & 1) == 0) {
      wsprintfA((LPSTR)player_idx,&DAT_00530cb8,DAT_006fe448);
      len_2 = strlen((char *)player_idx);
      RegSetValueExA(target_idx,s_PlayerTerritoryColor_00530cbc,0,1,player_idx,len_2 + 1);
    }
    if (((uint8_t)DAT_006fe410 & 1) == 0) {
      wsprintfA((LPSTR)player_idx,&DAT_00530cd4,DAT_006fe44c);
      len_2 = strlen((char *)player_idx);
      RegSetValueExA(target_idx,s_PlayerTerritoryType_00530cd8,0,1,player_idx,len_2 + 1);
    }
    RegFlushKey(target_idx);
    RegCloseKey(target_idx);
  }
  return;
}



/*
 * Decompiled function: Config_SaveRegistrySettings
 * Entry Point: 00500a5b
 * Size: 634 bytes
 */


void Config_SaveRegistrySettings(void)

{
  LSTATUS LVar1;
  HKEY local_2c;
  BYTE local_28 [32];
  DWORD slot_idx;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a8,0,1,
                        &local_2c);
  if (LVar1 == 0) {
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Difficulty_00530cec,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530cf8,&DAT_006fee70);
    }
    else {
      DAT_006fee70 = 1;
    }
    slot_idx = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_PlayerDeck_00530cfc,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &slot_idx);
    if (LVar1 == 0) {
      sprintf(&DAT_006fee74,&DAT_00530d08,local_28);
    }
    else {
      DAT_006fee74 = 0;
    }
    slot_idx = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_OpponentDeck_00530d0c,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &slot_idx);
    if (LVar1 == 0) {
      sprintf(&DAT_006fee92,&DAT_00530d1c,local_28);
    }
    else {
      DAT_006fee92 = 0;
    }
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_00530d20,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d28,&DAT_006feeb0);
    }
    else {
      DAT_006feeb0 = 1;
    }
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Match_00530d2c,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&slot_idx);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d34,&DAT_006feeb4);
    }
    else {
      DAT_006feeb4 = 1;
    }
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_00530d38,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&slot_idx);
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
  size_t len_2;
  HKEY target_idx;
  BYTE player_idx [12];
  DWORD slot_idx;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a8,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&target_idx,&slot_idx);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)player_idx,&DAT_00530d44,DAT_006fee70);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_Difficulty_00530d48,0,1,player_idx,len_2 + 1);
    len_2 = strlen(&DAT_006fee74);
    RegSetValueExA(target_idx,s_PlayerDeck_00530d54,0,1,&DAT_006fee74,len_2 + 1);
    len_2 = strlen(&DAT_006fee92);
    RegSetValueExA(target_idx,s_OpponentDeck_00530d60,0,1,&DAT_006fee92,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530d70,DAT_006feeb0);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,&DAT_00530d74,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530d7c,DAT_006feeb4);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_Match_00530d80,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_00530d88,DAT_006feeb8);
    len_2 = strlen((char *)player_idx);
    RegSetValueExA(target_idx,&DAT_00530d8c,0,1,player_idx,len_2 + 1);
    RegFlushKey(target_idx);
    RegCloseKey(target_idx);
  }
  return;
}



