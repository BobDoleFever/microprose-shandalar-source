/*
 * NedCard/haar.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 33
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
 * Entry Point: 0047e7d3
 * Size: 1106 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * Haar_DecompressWaveletImage(int *arg1,void *arg2)

{
  int arg_7;
  int event_type;
  int card_slot;
  int arg_4;
  int *arg_2_00;
  int *hDIBSection;
  int *arg_1_00;
  bool flag_1;
  void *local_50;
  int local_4c;
  int local_48;
  int local_34;
  int local_2c;
  int slot_idx;
  
  if (DAT_005237c8 == 0) {
    for (local_4c = -0x400; local_4c < 0x401; local_4c = local_4c + 1) {
      if ((local_4c < 0) || (0xf8 < local_4c)) {
        if (local_4c < 10) {
          PTR_DAT_004f9d40[local_4c] = 0;
        }
        else {
          PTR_DAT_004f9d40[local_4c] = 0xff;
        }
      }
      else {
        PTR_DAT_004f9d40[local_4c] = (char)((local_4c * 0xff) / 0xf8);
      }
    }
    DAT_005237c8 = 1;
  }
  flag_1 = arg2 != (void *)0x0;
  if (flag_1) {
    FUN_004d7f60(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  else {
    arg2 = _malloc(arg1[0x24] + 2000);
    FUN_004d7f60(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  _DAT_00692c64 = FUN_0047f4b0((int)arg2,arg1);
  if (arg1[10] == 1) {
    slot_idx = 1;
  }
  else if (arg1[10] == 4) {
    slot_idx = 2;
  }
  else if (arg1[10] == 0x10) {
    slot_idx = 4;
  }
  else {
    File_Load_Assertfile(0,0x4f9d9c,0x15e,s_wavelet_pieces_has_illegal_value_004f9d74);
  }
  arg_7 = arg1[7];
  arg_2 = arg1[7] / slot_idx;
  arg_3 = arg1[9];
  arg_4 = arg1[8] / slot_idx;
  for (local_48 = 0; local_48 < arg1[10]; local_48 = local_48 + 1) {
    local_34 = arg_4;
    local_2c = arg_2;
    if (*arg1 != 0) {
      local_34 = (arg_4 / slot_idx) / (int)((arg1[10] == 1) + 1);
      local_2c = (arg_2 / slot_idx) / (int)((arg1[10] == 1) + 1);
    }
    arg_2_00 = (int *)((arg_2 * arg_2 + local_2c * local_2c * 2 + 0x40) * local_48 * 4 + (int)arg2);
    hDIBSection = arg_2_00 + arg_2 * arg_2 + 0x20;
    arg_1_00 = hDIBSection + local_2c * local_2c + 0x20;
    FUN_0047eecc((int)arg_2_00,arg_2,arg_3);
    FUN_0047eecc((int)hDIBSection,local_2c,arg_3);
    FUN_0047eecc((int)arg_1_00,local_2c,arg_3);
    if (local_48 < arg1[10] / 2) {
      local_50 = (void *)FUN_0047f1e7(&DAT_00523980,arg_2_00,arg_2,arg_2,(int)hDIBSection,(int)arg_1_00,
                                      local_2c,local_2c,*arg1);
    }
    else if (arg1[10] < 2) {
      local_50 = (void *)FUN_0047f1e7(&DAT_00523980,arg_2_00,arg_2,arg_4,(int)hDIBSection,(int)arg_1_00,
                                      local_2c,local_34,*arg1);
    }
    else {
      local_50 = (void *)FUN_0047f1e7(&DAT_00523980,arg_2_00,arg_2,arg1[8] - arg_2,(int)hDIBSection,
                                      (int)arg_1_00,local_2c,local_34,*arg1);
    }
    if (arg1[10] < 2) {
      if (!flag_1) {
        FUN_004db150(arg2);
      }
      arg2 = local_50;
    }
    else {
      FUN_0047ec25((int)arg2,(int)local_50,(arg_7 / slot_idx) * (local_48 % slot_idx),
                   (arg_7 / slot_idx) * (local_48 / slot_idx),arg_2,arg_2,arg_7);
      FUN_004db150(local_50);
    }
  }
  return arg2;
}



/*
 * Decompiled function: FUN_0047ec25
 * Entry Point: 0047ec25
 * Size: 103 bytes
 */


void FUN_0047ec25(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int32_t slot_idx;
  
  hDIBSection = hDIBSection + (arg_7 * arg_4 + arg_3) * 3;
  for (slot_idx = 0; slot_idx < arg_6; slot_idx = slot_idx + 1) {
    FUN_0047ee28((undefined8 *)hDIBSection,(undefined8 *)arg_2,arg_5 * 3);
    hDIBSection = hDIBSection + arg_7 * 3;
    arg_2 = arg_2 + arg_5 * 3;
  }
  return;
}



/*
 * Decompiled function: FUN_0047ec8c
 * Entry Point: 0047ec8c
 * Size: 412 bytes
 */


void FUN_0047ec8c(int *hDIBSection,int *arg_2,int *arg_3,int arg_4,int arg_5,int32_t arg_6,int arg_7)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int loop_idx;
  int color_idx;
  int *match_count;
  int slot_idx;
  
  for (slot_idx = 0; i_ptr_1 = hDIBSection, slot_idx < arg_5; slot_idx = slot_idx + 1) {
    i_ptr_2 = hDIBSection + arg_4 + -1;
    match_count = arg_3 + arg_7 * 2;
    for (; hDIBSection < i_ptr_2; hDIBSection = hDIBSection + 1) {
      color_idx = hDIBSection[1] * 0xb504;
      loop_idx = hDIBSection[1] * 0xb504;
      if (*arg_2 != 0) {
        color_idx = color_idx + *arg_2 * 0xb504;
        loop_idx = loop_idx + *arg_2 * -0xb504;
      }
      *match_count = color_idx >> 0x10;
      match_count[arg_7] = loop_idx >> 0x10;
      arg_2 = arg_2 + 1;
      match_count = match_count + arg_7 * 2;
    }
    *arg_3 = *arg_2 * 0xb504 + *i_ptr_1 * 0xb504 >> 0x10;
    arg_3[arg_7] = *arg_2 * -0xb504 + *i_ptr_1 * 0xb504 >> 0x10;
    arg_3 = arg_3 + 1;
    hDIBSection = hDIBSection + 1;
    arg_2 = arg_2 + 1;
  }
  return;
}



/*
 * Decompiled function: FUN_0047ee28
 * Entry Point: 0047ee28
 * Size: 59 bytes
 */


void FUN_0047ee28(undefined8 *hDIBSection,undefined8 *arg_2,uint32_t arg_3)

{
  uint32_t uval_1;
  
  for (uval_1 = arg_3 >> 3; uval_1 != 0; uval_1 = uval_1 - 1) {
    *hDIBSection = *arg_2;
    arg_2 = arg_2 + 1;
    hDIBSection = hDIBSection + 1;
  }
  uval_1 = arg_3 & 7;
  if (uval_1 != 0) {
    for (; uval_1 != 0; uval_1 = uval_1 - 1) {
      *(uint8_t *)hDIBSection = *(uint8_t *)arg_2;
      arg_2 = (undefined8 *)((int)arg_2 + 1);
      hDIBSection = (undefined8 *)((int)hDIBSection + 1);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0047ee63
 * Entry Point: 0047ee63
 * Size: 105 bytes
 */


void FUN_0047ee63(undefined8 *hDIBSection,uint32_t arg_2,uint32_t arg_3)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  undefined8 uval_4;
  
  uval_1 = arg_2 << 8 | arg_2;
  uval_3 = (int)uval_1 >> 0x1f | ((int)uval_1 >> 0x1f) << 0x10 | uval_1 >> 0x10;
  uval_4 = __allshl(0x20,uval_3);
  uval_4 = CONCAT44(uval_3 | (uint32_t)((ulonglong)uval_4 >> 0x20),uval_1 | uval_1 << 0x10 | (uint32_t)uval_4);
  val_2 = (arg_3 >> 3) - 1;
  do {
    *hDIBSection = uval_4;
    hDIBSection = hDIBSection + 1;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  *hDIBSection = uval_4;
  for (uval_3 = arg_3 & 7; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(char *)hDIBSection = (char)arg_2;
    hDIBSection = (undefined8 *)((int)hDIBSection + 1);
  }
  return;
}



/*
 * Decompiled function: FUN_0047eecc
 * Entry Point: 0047eecc
 * Size: 325 bytes
 */


void FUN_0047eecc(int player_id,int card_slot,int event_type)

{
  int *arg_3_00;
  int32_t color_idx;
  int32_t player_idx;
  
  if (DAT_004f9d4c == 0) {
    color_idx = _malloc(0x32000);
    DAT_00690c5c = color_idx;
    DAT_00690c58 = _malloc(0x32000);
    DAT_004f9d4c = 1;
  }
  else {
    color_idx = DAT_00690c5c;
  }
  arg_3_00 = DAT_00690c58;
  for (player_idx = arg_3; player_idx < arg_2; player_idx = player_idx << 1) {
    FUN_0047f011((int *)hDIBSection,(int *)(player_idx * player_idx * 4 + hDIBSection),color_idx,player_idx,player_idx,
                 player_idx * 2,player_idx);
    FUN_0047f011((int *)(player_idx * player_idx * 8 + hDIBSection),(int *)(player_idx * player_idx * 0xc + hDIBSection)
                 ,arg_3_00,player_idx,player_idx,player_idx * 2,player_idx);
    FUN_0047f0e6(color_idx,arg_3_00,(int *)hDIBSection,player_idx,player_idx * 2,player_idx * 2,player_idx * 2);
  }
  return;
}



/*
 * Decompiled function: FUN_0047f011
 * Entry Point: 0047f011
 * Size: 213 bytes
 */


void FUN_0047f011(int *hDIBSection,int *arg_2,int *arg_3,int arg_4,int arg_5,int32_t arg_6,int arg_7)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *match_count;
  int slot_idx;
  
  for (slot_idx = 0; i_ptr_1 = hDIBSection, slot_idx < arg_5; slot_idx = slot_idx + 1) {
    i_ptr_2 = hDIBSection + arg_4;
    match_count = arg_3 + arg_7 * 2;
    while (hDIBSection = hDIBSection + 1, hDIBSection < i_ptr_2) {
      *match_count = *arg_2 + *hDIBSection;
      match_count[arg_7] = *hDIBSection - *arg_2;
      arg_2 = arg_2 + 1;
      match_count = match_count + arg_7 * 2;
    }
    *arg_3 = *i_ptr_1 + *arg_2;
    arg_3[arg_7] = *i_ptr_1 - *arg_2;
    arg_3 = arg_3 + 1;
    arg_2 = arg_2 + 1;
  }
  return;
}



/*
 * Decompiled function: FUN_0047f0e6
 * Entry Point: 0047f0e6
 * Size: 219 bytes
 */


void FUN_0047f0e6(int *hDIBSection,int *arg_2,int *arg_3,int arg_4,int arg_5,int32_t arg_6,int arg_7)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *match_count;
  int slot_idx;
  
  for (slot_idx = 0; i_ptr_1 = hDIBSection, slot_idx < arg_5; slot_idx = slot_idx + 1) {
    i_ptr_2 = hDIBSection + arg_4;
    match_count = arg_3 + arg_7 * 2;
    while (hDIBSection = hDIBSection + 1, hDIBSection < i_ptr_2) {
      *match_count = *arg_2 + *hDIBSection >> 1;
      match_count[arg_7] = *hDIBSection - *arg_2 >> 1;
      arg_2 = arg_2 + 1;
      match_count = match_count + arg_7 * 2;
    }
    *arg_3 = *i_ptr_1 + *arg_2 >> 1;
    arg_3[arg_7] = *i_ptr_1 - *arg_2 >> 1;
    arg_3 = arg_3 + 1;
    arg_2 = arg_2 + 1;
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047f1c1
 * Entry Point: 0047f1c1
 * Size: 38 bytes
 */


int16_t Mem_AllocOrFree_0047f1c1(uint32_t arg1,uint32_t arg2)

{
  uint8_t *u_ptr_1;
  uint8_t uval_2;
  uint32_t uval_3;
  uint8_t *puVar4;
  
  puVar4 = (uint8_t *)(arg1 & 0xffffffe0);
  uval_3 = arg2 >> 6;
  do {
    uval_2 = *puVar4;
    u_ptr_1 = puVar4 + 0x20;
    puVar4 = puVar4 + 0x40;
    uval_3 = uval_3 - 1;
  } while (uval_3 != 0);
  return CONCAT11(*u_ptr_1,uval_2);
}



/*
 * Decompiled function: FUN_0047f1e7
 * Entry Point: 0047f1e7
 * Size: 713 bytes
 */


uint8_t *
FUN_0047f1e7(uint8_t *hDIBSection,int *arg_2,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,
            int32_t arg_8,int arg_9)

{
  uint8_t *u_ptr_1;
  int val_2;
  int local_2c;
  int local_28;
  int loop_idx;
  uint32_t color_idx;
  int *player_idx;
  int *card_idx;
  int match_count;
  int slot_idx;
  
  if (DAT_005dad84 == 0) {
    for (color_idx = -0x400; (int)color_idx < 0x1c00; color_idx = color_idx + 1) {
      if ((int)color_idx < 1) {
        PTR_DAT_004f9d50[color_idx] = 0;
      }
      else {
        val_2 = (int)color_idx >> 2;
        if (0xfe < val_2) {
          val_2 = 0xff;
        }
        PTR_DAT_004f9d50[color_idx] = (char)val_2;
      }
    }
    DAT_005dad84 = 1;
  }
  if (hDIBSection == (uint8_t *)0x0) {
    hDIBSection = _malloc(arg_3 * arg_3 * 3 + 0x10);
  }
  u_ptr_1 = hDIBSection;
  for (loop_idx = 0; loop_idx < arg_4; loop_idx = loop_idx + 1) {
    val_2 = loop_idx;
    if (arg_9 != 0) {
      val_2 = loop_idx / 2;
    }
    card_idx = (int *)(val_2 * arg_7 * 4 + arg_6);
    player_idx = (int *)(val_2 * arg_7 * 4 + arg_5);
    for (color_idx = 0; (int)color_idx < arg_3; color_idx = color_idx + 1) {
      val_2 = *arg_2;
      if (arg_9 == 0) {
        local_2c = *player_idx;
        local_28 = *card_idx;
        local_28 = (local_28 >> 3) + (local_28 >> 1) + local_28;
      }
      else {
        if ((color_idx & 1) == 0) {
          local_2c = *player_idx;
          local_28 = *card_idx;
        }
        else {
          local_2c = (player_idx[arg_3 - 1U != color_idx] + *player_idx) / 2;
          local_28 = (card_idx[arg_3 - 1U != color_idx] + *card_idx) / 2;
        }
        local_28 = (local_28 >> 3) + (local_28 >> 1) + local_28;
      }
      slot_idx = local_2c * 2 + -0x400 + val_2;
      match_count = local_28 + -0x333 + val_2;
      *hDIBSection = PTR_DAT_004f9d50[slot_idx];
      hDIBSection[1] = PTR_DAT_004f9d50
                 [((val_2 * 2 - (val_2 >> 2)) - (match_count >> 1)) - ((slot_idx >> 2) - (slot_idx >> 4))]
      ;
      hDIBSection[2] = PTR_DAT_004f9d50[match_count];
      if (arg_9 == 0) {
        player_idx = player_idx + 1;
        card_idx = card_idx + 1;
      }
      else if ((color_idx & 1) != 0) {
        player_idx = player_idx + 1;
        card_idx = card_idx + 1;
      }
      arg_2 = arg_2 + 1;
      hDIBSection = hDIBSection + 3;
    }
  }
  return u_ptr_1;
}



/*
 * Decompiled function: FUN_0047f4b0
 * Entry Point: 0047f4b0
 * Size: 567 bytes
 */


int32_t FUN_0047f4b0(int arg1,int *arg2)

{
  int *arg_2;
  uint32_t *u_ptr_1;
  int val_2;
  int event_type;
  int val_3;
  int val_4;
  int val_5;
  void *pvVar6;
  void *ptr_1;
  void *ptr_1_00;
  int local_28;
  void *target_idx;
  
  val_3 = arg2[7] / (int)(2 - (uint32_t)(arg2[10] == 1));
  val_4 = val_3 / (int)(2 - (uint32_t)(*arg2 == 0));
  val_2 = arg2[9];
  arg_3 = *(int *)arg2[0x68];
  arg_2 = (int *)arg2[0x68] + 1;
  *arg_2 = -0x80000000;
  val_5 = FUN_004d85eb(arg_2 + arg_3,arg_2,arg_3);
  target_idx = (void *)((int)(arg_2 + arg_3) + val_5);
  for (local_28 = 0; local_28 < arg2[10]; local_28 = local_28 + 1) {
    pvVar6 = (void *)((val_3 * val_3 + val_4 * val_4 * 2 + 0x40) * local_28 * 4 + arg1);
    ptr_1 = (void *)((int)pvVar6 + val_3 * val_3 * 4 + 0x80);
    ptr_1_00 = (void *)((int)ptr_1 + val_4 * val_4 * 4 + 0x80);
    FID_conflict__memcpy(pvVar6,target_idx,val_2 * val_2 * 4);
    u_ptr_1 = (uint32_t *)((int)target_idx + val_2 * val_2 * 4);
    FUN_004d8cfe((undefined8 *)((int)pvVar6 + val_2 * val_2 * 4),u_ptr_1,arg2[local_28 + 0x17]);
    pvVar6 = (void *)((int)u_ptr_1 + arg2[local_28 + 0x17]);
    FID_conflict__memcpy(ptr_1,pvVar6,val_2 * val_2 * 4);
    u_ptr_1 = (uint32_t *)((int)pvVar6 + val_2 * val_2 * 4);
    FUN_004d8cfe((undefined8 *)((int)ptr_1 + val_2 * val_2 * 4),u_ptr_1,arg2[local_28 + 0x1b]);
    pvVar6 = (void *)((int)u_ptr_1 + arg2[local_28 + 0x1b]);
    FID_conflict__memcpy(ptr_1_00,pvVar6,val_2 * val_2 * 4);
    u_ptr_1 = (uint32_t *)((int)pvVar6 + val_2 * val_2 * 4);
    FUN_004d8cfe((undefined8 *)((int)ptr_1_00 + val_2 * val_2 * 4),u_ptr_1,arg2[local_28 + 0x1f]);
    target_idx = (void *)((int)u_ptr_1 + arg2[local_28 + 0x1f]);
  }
  return 0;
}



/*
 * Decompiled function: FUN_0047f6e7
 * Entry Point: 0047f6e7
 * Size: 105 bytes
 */


bool FUN_0047f6e7(HWND hwnd)

{
  HDC hDC;
  HBRUSH hbr;
  tagRECT player_idx;
  
  if (hwnd != (HWND)0x0) {
    hDC = GetDC(hwnd);
    GetClientRect(hwnd,&player_idx);
    hbr = GetStockObject(0);
    FillRect(hDC,&player_idx,hbr);
    ReleaseDC(hwnd,hDC);
  }
  return hwnd != (HWND)0x0;
}



/*
 * Decompiled function: FUN_0047f750
 * Entry Point: 0047f750
 * Size: 131 bytes
 */


int FUN_0047f750(HWND hwnd,void *arg_2,int event_type,int arg_4,DWORD arg_5,DWORD arg_6)

{
  BITMAPINFO *lpbmi;
  HDC hdc;
  int val_1;
  
  lpbmi = (BITMAPINFO *)FUN_0047f7d3(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_1 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,arg_2,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  Mem_AllocOrFree_0047f8f7(lpbmi);
  return val_1;
}



/*
 * Decompiled function: FUN_0047f7d3
 * Entry Point: 0047f7d3
 * Size: 292 bytes
 */


int32_t * FUN_0047f7d3(int32_t hDIBSection,int card_slot,int event_type)

{
  int card_idx;
  int32_t *match_count;
  int32_t *slot_idx;
  
  if (arg_3 == 8) {
    slot_idx = _malloc(0x42c);
  }
  else if (arg_3 == 0x18) {
    slot_idx = _malloc(0x2c);
  }
  else {
    slot_idx = _malloc(0x2c);
  }
  *slot_idx = 0x28;
  slot_idx[1] = hDIBSection;
  slot_idx[2] = -arg_2;
  *(int16_t *)(slot_idx + 3) = 1;
  *(short *)((int)slot_idx + 0xe) = (short)arg_3;
  slot_idx[4] = 0;
  slot_idx[5] = 0;
  slot_idx[6] = 0;
  slot_idx[7] = 0;
  if (arg_3 == 8) {
    slot_idx[8] = 0x100;
    slot_idx[9] = 0x100;
    match_count = slot_idx + 10;
    for (card_idx = 0; card_idx < 0x100; card_idx = card_idx + 1) {
      *(short *)match_count = (short)card_idx;
      match_count = (int32_t *)((int)match_count + 2);
    }
  }
  else {
    slot_idx[8] = 0;
    slot_idx[9] = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047f8f7
 * Entry Point: 0047f8f7
 * Size: 33 bytes
 */


int32_t Mem_AllocOrFree_0047f8f7(int32_t hDIBSection)

{
  FUN_004db150(hDIBSection);
  return 1;
}



/*
 * Decompiled function: FUN_0047f918
 * Entry Point: 0047f918
 * Size: 757 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0047fb79) */
/* WARNING: Removing unreachable block (ram,0x0047fbb3) */
/* WARNING: Removing unreachable block (ram,0x0047fb83) */
/* WARNING: Removing unreachable block (ram,0x0047fa7a) */
/* WARNING: Removing unreachable block (ram,0x0047fa97) */
/* WARNING: Removing unreachable block (ram,0x0047fa84) */

int32_t * FUN_0047f918(int32_t *hDIBSection,int *y,int width,int height)

{
  int val_1;
  int val_2;
  int32_t *u_ptr_3;
  int *arg_1_00;
  int val_4;
  int val_5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int *local_28;
  int local_24;
  
  local_38 = 0;
  local_24 = 0;
  if (y == (int *)0x0) {
    u_ptr_3 = (int32_t *)0x0;
  }
  else {
    val_5 = (DAT_004f9d08 - (width * 3) % DAT_004f9d08) % DAT_004f9d08;
    if (hDIBSection == (int32_t *)0x0) {
      hDIBSection = _malloc((width * 3 + val_5) * height + 4);
    }
    u_ptr_3 = hDIBSection;
    val_4 = y[7];
    val_1 = y[8];
    if (y[0x6a] == 0) {
      local_40 = Haar_DecompressWaveletImage(y,(void *)0x0);
    }
    else {
      local_40 = y[0x6b];
    }
    val_2 = y[7];
    arg_1_00 = _malloc(width << 2);
    local_2c = 0;
    local_28 = arg_1_00;
    for (local_34 = 0; local_34 < width; local_34 = local_34 + 1) {
      *local_28 = (local_2c >> 0xf & 0xfffffffeU) + (local_2c >> 0x10);
      local_2c = local_2c + (val_4 << 0x10) / width;
      local_28 = local_28 + 1;
    }
    for (local_3c = 0; local_3c < height; local_3c = local_3c + 1) {
      val_4 = val_2 * 3 * (local_38 >> 0x10) + local_40;
      if (local_24 == val_4) {
        FID_conflict__memcpy(hDIBSection,(void *)((int)hDIBSection + (width * -3 - val_5)),width * 3);
        hDIBSection = (int32_t *)((int)hDIBSection + width * 3);
      }
      else {
        local_28 = arg_1_00;
        for (local_34 = 0; local_24 = val_4, local_34 < width; local_34 = local_34 + 1) {
          *hDIBSection = *(int32_t *)(*local_28 + val_4);
          hDIBSection = (int32_t *)((int)hDIBSection + 3);
          local_28 = local_28 + 1;
        }
      }
      local_38 = local_38 + (val_1 << 0x10) / height;
      hDIBSection = (int32_t *)((int)hDIBSection + val_5);
    }
    FUN_004db150(arg_1_00);
    if (y[0x6a] == 0) {
      FUN_004db150(local_40);
    }
  }
  return u_ptr_3;
}



/*
 * Decompiled function: FUN_0047fc0d
 * Entry Point: 0047fc0d
 * Size: 106 bytes
 */


bool FUN_0047fc0d(HWND hwnd,int *y,DWORD arg_3,DWORD arg_4)

{
  void *arg_2;
  
  if (y != (int *)0x0) {
    arg_2 = (void *)FUN_0047f918((int32_t *)0x0,y,arg_3,arg_4);
    FUN_0047f750(hwnd,arg_2,0,0,arg_3,arg_4);
    FUN_004db150(arg_2);
  }
  return y != (int *)0x0;
}



/*
 * Decompiled function: FUN_0047fc77
 * Entry Point: 0047fc77
 * Size: 1831 bytes
 */


/* WARNING: Removing unreachable block (ram,0x00480068) */
/* WARNING: Removing unreachable block (ram,0x0047fe45) */

uint32_t * FUN_0047fc77(uint32_t *x,int *y,int width,int height)

{
  int val_1;
  int val_2;
  uint32_t *local_5054;
  uint32_t local_5050 [4096];
  int local_1050;
  int local_104c;
  int local_1048;
  int local_1044;
  uint32_t local_1040;
  int local_103c;
  uint32_t *local_1038;
  int local_1034;
  uint32_t *local_1030;
  int32_t local_102c;
  uint32_t *local_1028;
  int local_1024;
  int local_1020;
  size_t local_101c;
  int local_1018;
  int32_t local_1014;
  uint8_t *local_1010;
  uint32_t local_100c [1016];
  int32_t uStackY_2c;
  
  Mem_AllocOrFree_004ddee0();
  local_1034 = 0;
  local_1048 = 0;
  local_102c = 0;
  local_1030 = local_5050;
  local_1038 = local_100c;
  local_1040 = (uint32_t)(x != (uint32_t *)0x0);
  if (y == (int *)0x0) {
    local_5054 = (uint32_t *)0x0;
  }
  else {
    local_1018 = y[7] << 0x10;
    local_1024 = y[8] << 0x10;
    val_1 = local_1018 / width;
    val_2 = local_1024 / height;
    if (y[0x6a] == 0) {
      local_1050 = Haar_DecompressWaveletImage(y,&DAT_00523980);
    }
    else {
      local_1050 = y[0x6b];
    }
    local_103c = y[7];
    local_1014 = 0;
    local_1020 = (DAT_004f9d08 - (width * 3) % DAT_004f9d08) % DAT_004f9d08;
    if (x == (uint32_t *)0x0) {
      local_5054 = (uint32_t *)&DAT_0059e180;
    }
    else {
      local_5054 = x;
    }
    local_1034 = 0;
    for (local_1044 = 0; local_1044 < width; local_1044 = local_1044 + 1) {
      *local_1030 = local_1034 >> 8;
      local_1034 = local_1034 + val_1;
      local_1030 = local_1030 + 1;
    }
    x = local_5054;
    if (y[8] < height) {
      x = (uint32_t *)((int)local_5054 + (height - y[8]) * (width * 3 + local_1020));
    }
    local_1028 = x;
    for (local_104c = 0; local_104c < y[8]; local_104c = local_104c + 1) {
      local_1030 = local_5050;
      for (local_1044 = 0; local_1044 < width; local_1044 = local_1044 + 1) {
        local_1010 = (uint8_t *)(((int)*local_1030 >> 8) * 3 + local_103c * 3 * local_104c + local_1050
                             );
        *(uint8_t *)x = (char)(((uint32_t)local_1010[3] - (uint32_t)*local_1010) * (*local_1030 & 0xff) >> 8) +
                     *local_1010;
        *(uint8_t *)((int)x + 1) =
             (char)(((uint32_t)local_1010[4] - (uint32_t)local_1010[1]) * (*local_1030 & 0xff) >> 8) +
             local_1010[1];
        *(uint8_t *)((int)x + 2) =
             (char)(((uint32_t)local_1010[5] - (uint32_t)local_1010[2]) * (*local_1030 & 0xff) >> 8) +
             local_1010[2];
        x = (uint32_t *)((int)x + 3);
        local_1030 = local_1030 + 1;
      }
      x = (uint32_t *)((int)x + local_1020);
    }
    local_1048 = 0;
    for (local_1044 = 0; local_1044 < height; local_1044 = local_1044 + 1) {
      *local_1038 = local_1048 >> 8;
      local_1048 = local_1048 + val_2;
      local_1038 = local_1038 + 1;
    }
    local_101c = width * 3 + local_1020;
    if (height < y[8]) {
      FID_conflict__memcpy
                (local_5050,(uint32_t *)((y[8] + -1) * local_101c + (int)local_5054),local_101c);
    }
    for (local_1044 = 0; local_1044 < width; local_1044 = local_1044 + 1) {
      x = (uint32_t *)(local_1044 * 3 + (int)local_5054);
      local_1038 = local_100c;
      for (local_104c = 0; local_104c < height + -1; local_104c = local_104c + 1) {
        val_1 = y[8] + -2;
        if ((int)*local_1038 >> 8 <= y[8] + -2) {
          val_1 = (int)*local_1038 >> 8;
        }
        local_1010 = (uint8_t *)((int)local_1028 + val_1 * local_101c + local_1044 * 3);
        *(uint8_t *)x = (char)(((uint32_t)local_1010[local_101c] - (uint32_t)*local_1010) *
                            (*local_1038 & 0xff) >> 8) + *local_1010;
        *(uint8_t *)((int)x + 1) =
             (char)(((uint32_t)local_1010[local_101c + 1] - (uint32_t)local_1010[1]) * (*local_1038 & 0xff)
                   >> 8) + local_1010[1];
        *(uint8_t *)((int)x + 2) =
             (char)(((uint32_t)local_1010[local_101c + 2] - (uint32_t)local_1010[2]) * (*local_1038 & 0xff)
                   >> 8) + local_1010[2];
        local_1038 = local_1038 + 1;
        x = (uint32_t *)((int)x + local_101c);
      }
    }
    if (height < y[8]) {
      FID_conflict__memcpy
                ((uint32_t *)((height + -1) * local_101c + (int)local_5054),local_5050,local_101c);
    }
    else {
      _memset((uint32_t *)((height + -1) * local_101c + (int)local_5054),0,local_101c);
    }
    val_1 = (4 - (width * 3) % 4) % 4;
    if (DAT_004f4628 == 0) {
      FUN_00435551(local_5054,height,width,val_1);
    }
    else if (DAT_00664c30 == 0x10) {
      uStackY_2c = 0x48034f;
      FUN_00436293(DAT_004f4628,DAT_004f462c,(int)local_5054,height,width,val_1);
    }
    else if (DAT_00664c30 == 8) {
      uStackY_2c = 0x48038b;
      FUN_004356cf(DAT_004f4628,DAT_004f462c,local_5054,height,width,val_1);
    }
  }
  return local_5054;
}



/*
 * Decompiled function: FUN_0048039e
 * Entry Point: 0048039e
 * Size: 193 bytes
 */


int32_t FUN_0048039e(HWND hwnd,int *y,DWORD arg_3,DWORD arg_4)

{
  int32_t uval_1;
  uint32_t *arg_3_00;
  
  if (y == (int *)0x0) {
    uval_1 = 0;
  }
  else {
    arg_3_00 = (uint32_t *)FUN_0047fc77((uint32_t *)0x0,y,arg_3,arg_4);
    FUN_004356cf(DAT_004f4628,DAT_004f462c,arg_3_00,arg_4,arg_3,
                 (DAT_004f9d08 - (int)(arg_3 * 3) % DAT_004f9d08) % DAT_004f9d08);
    FUN_0047f750(hwnd,arg_3_00,0,0,arg_3,arg_4);
    if ((uint32_t *)y[0x6b] != arg_3_00) {
      FUN_004db150(arg_3_00);
    }
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0048045f
 * Entry Point: 0048045f
 * Size: 82 bytes
 */


int32_t * FUN_0048045f(int player_id)

{
  int32_t *slot_idx;
  
  slot_idx = _malloc(hDIBSection + 8);
  if (((uint32_t)slot_idx & 7) == 0) {
    slot_idx[1] = 0;
    slot_idx = slot_idx + 2;
  }
  else {
    *slot_idx = 0xffffffff;
    slot_idx = slot_idx + 1;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004804b1
 * Entry Point: 004804b1
 * Size: 58 bytes
 */


void FUN_004804b1(int player_id)

{
  int32_t slot_idx;
  
  if (*(int *)(hDIBSection + -4) == 0) {
    slot_idx = hDIBSection + -8;
  }
  else {
    slot_idx = hDIBSection + -4;
  }
  FUN_004db150(slot_idx);
  return;
}



/*
 * Decompiled function: FUN_004804eb
 * Entry Point: 004804eb
 * Size: 420 bytes
 */


int FUN_004804eb(HWND hwnd,int card_slot,int event_type,int arg_4,DWORD arg_5,DWORD arg_6)

{
  uint8_t *ptr_1;
  int val_1;
  BITMAPINFO *lpbmi;
  HDC hdc;
  int val_2;
  int local_2c;
  int local_28;
  int color_idx;
  uint8_t *player_idx;
  uint8_t card_idx;
  int slot_idx;
  
  color_idx = 0;
  slot_idx = 0;
  ptr_1 = _malloc(arg_6 * arg_5 * 3 + 8);
  _memset(ptr_1,0,arg_6 * arg_5 * 3);
  player_idx = ptr_1;
  for (local_2c = 0; local_2c < (int)arg_6; local_2c = local_2c + 1) {
    for (local_28 = 0; local_28 < (int)arg_5; local_28 = local_28 + 1) {
      val_1 = *(int *)(local_28 * 4 + arg_5 * local_2c * 4 + arg_2) >> 2;
      val_2 = val_1;
      if ((slot_idx <= val_1) && (val_2 = slot_idx, color_idx < val_1)) {
        color_idx = val_1;
      }
      slot_idx = val_2;
      if (val_1 < 1) {
        val_1 = 0;
      }
      if (0xfe < val_1) {
        val_1 = 0xff;
      }
      card_idx = (uint8_t)val_1;
      player_idx[2] = card_idx;
      player_idx[1] = player_idx[2];
      *player_idx = player_idx[1];
      player_idx = player_idx + 3;
    }
  }
  lpbmi = (BITMAPINFO *)FUN_0047f7d3(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_2 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,ptr_1,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  Mem_AllocOrFree_0047f8f7(lpbmi);
  FUN_004db150(ptr_1);
  return val_2;
}



/*
 * Decompiled function: FUN_00480690
 * Entry Point: 00480690
 * Size: 374 bytes
 */


void FUN_00480690(HWND hwnd)

{
  INT_PTR IVar1;
  
  IVar1 = DialogBoxParamA(g_DuelInstanceHandle,(LPCSTR)0xe1,hwnd,UI_DialogProc_00480806,0);
  if (IVar1 != 0) {
    if (DAT_00663e28 == -1) {
      Palette_Subsystem_0049c3ac(0,DAT_006169f0,DAT_00663e2c);
    }
    else {
      Palette_Subsystem_0049c3ac(0,DAT_00663e28,DAT_00663e2c);
    }
    LockWindowUpdate(g_DuelMainHwnd);
    FUN_0043753a(0,0);
    FUN_0043753a(1,0);
    FUN_004b5565(g_DuelMainHwnd,DAT_00663e24);
    FUN_004b7f54(DAT_00664d90);
    FUN_004b1cc1(DAT_00617378);
    FUN_004b1cc1(DAT_00618988);
    FUN_004baa8b(DAT_006152b0);
    FUN_004baa8b(DAT_00663df4);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(DAT_006152b0,0x435,0,0);
    SendMessageA(DAT_00663df4,0x435,0,0);
    SendMessageA(DAT_00617378,0x435,0,0);
    SendMessageA(DAT_00618988,0x435,0,0);
    SendMessageA(DAT_00618ab0,0x435,0,0);
    SendMessageA(DAT_00663df0,0x435,0,0);
    Rules_ParseFilter_00481890();
  }
  return;
}



/*
 * Decompiled function: UI_DialogProc_00480806
 * Entry Point: 00480806
 * Size: 2001 bytes
 */


HBRUSH UI_DialogProc_00480806(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

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
        local_28 = DAT_005dad94;
      }
      else {
        local_28 = DAT_005dada4;
      }
      FUN_00471f45((int)local_24,DAT_005dad9c,DAT_005dad88,DAT_005dad98,local_28,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      GDI_RealizeAndFlushPalette(wParam);
      GetClientRect(hwnd,&local_38);
      if (DAT_005dad90 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(wParam,&local_38,pHVar3);
      }
      else {
        GDI_DrawBitmapToHDC((int)wParam,(int)&local_38,DAT_005dad90);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_00480d35:
      target_idx = wParam;
      GDI_RealizeAndFlushPalette(wParam);
      loop_idx = lParam;
      color_idx = GetDlgCtrlID(lParam);
      if ((color_idx != 0x3ff) && (color_idx != 0x40d)) {
        if (color_idx == 0x48b) {
          SetTextColor(target_idx,DAT_005dad8c);
          SetBkMode(target_idx,1);
          pHVar3 = GetStockObject(5);
          return pHVar3;
        }
        pHVar2 = GetFocus();
        if (pHVar2 == loop_idx) {
          SetTextColor(target_idx,DAT_005dad94);
        }
        else {
          SetTextColor(target_idx,DAT_005dada0);
        }
        SetBkMode(target_idx,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetTextColor(target_idx,DAT_005dada0);
      SetBkMode(target_idx,1);
      return DAT_005dad9c;
    }
    if (uMsg == 0x110) {
      Pic_Load_s_WINBK_Options_00480fdc
                (&DAT_005dad90,&DAT_005dad8c,&DAT_005dada0,(int *)&DAT_005dad9c,(int *)&DAT_005dad88
                 ,(int *)&DAT_005dad98,&DAT_005dada4,&DAT_005dad94);
      if (DAT_00663e24 == 1) {
        slot_idx = 0x400;
      }
      else {
        slot_idx = 0x401;
      }
      CheckDlgButton(hwnd,slot_idx,1);
      CheckRadioButton(hwnd,0x400,0x401,slot_idx);
      if (DAT_00663e00 != 0) {
        CheckDlgButton(hwnd,0x403,1);
      }
      if (DAT_00663e08 != 0) {
        CheckDlgButton(hwnd,0x404,1);
      }
      if (DAT_00663e0c != 0) {
        CheckDlgButton(hwnd,0x405,1);
      }
      if (DAT_00663e14 != 0) {
        CheckDlgButton(hwnd,0x495,1);
      }
      if (((uint8_t)DAT_00663dfc & 1) == 0) {
        bEnable = 0;
        pHVar2 = GetDlgItem(hwnd,0x495);
        EnableWindow(pHVar2,bEnable);
        CheckDlgButton(hwnd,0x495,1);
      }
      if (DAT_00663e28 == 1) {
        slot_idx = 0x409;
      }
      else if (DAT_00663e28 == 2) {
        slot_idx = 0x408;
      }
      else if (DAT_00663e28 == 3) {
        slot_idx = 0x40b;
      }
      else if (DAT_00663e28 == 5) {
        slot_idx = 0x407;
      }
      else if (DAT_00663e28 == 4) {
        slot_idx = 0x40a;
      }
      else {
        slot_idx = 0x40c;
      }
      CheckDlgButton(hwnd,slot_idx,1);
      CheckRadioButton(hwnd,0x407,0x40c,slot_idx);
      if (DAT_00663e2c == 0) {
        slot_idx = 0x40e;
      }
      else if (DAT_00663e2c == 1) {
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
      FUN_00472552(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint32_t)wParam & 0xffff) == 2) {
        FUN_004810c1(DAT_005dad90,DAT_005dad9c,DAT_005dad88,DAT_005dad98);
        EndDialog(hwnd,0);
      }
      else if (((uint32_t)wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x400);
        if (UVar1 == 0) {
          DAT_00663e24 = 2;
        }
        else {
          DAT_00663e24 = 1;
        }
        DAT_00663e00 = IsDlgButtonChecked(hwnd,0x403);
        DAT_00663e08 = IsDlgButtonChecked(hwnd,0x404);
        DAT_00663e0c = IsDlgButtonChecked(hwnd,0x405);
        DAT_00663e14 = IsDlgButtonChecked(hwnd,0x495);
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
                  DAT_00663e28 = -1;
                }
                else {
                  DAT_00663e28 = 4;
                }
              }
              else {
                DAT_00663e28 = 3;
              }
            }
            else {
              DAT_00663e28 = 5;
            }
          }
          else {
            DAT_00663e28 = 2;
          }
        }
        else {
          DAT_00663e28 = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x40e);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x40f);
          if (UVar1 == 0) {
            DAT_00663e2c = 2;
          }
          else {
            DAT_00663e2c = 1;
          }
        }
        else {
          DAT_00663e2c = 0;
        }
        Rules_ParseFilter_00481890();
        FUN_004810c1(DAT_005dad90,DAT_005dad9c,DAT_005dad88,DAT_005dad98);
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
    if (uMsg == 0x138) goto LAB_00480d35;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar3 = (HBRUSH)GDI_RealizePaletteTree(hwnd,uMsg,(HWND)wParam,lParam);
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
 * Decompiled function: Pic_Load_s_WINBK_Options_00480fdc
 * Entry Point: 00480fdc
 * Size: 229 bytes
 */


void Pic_Load_s_WINBK_Options_00480fdc
               (int32_t *hDIBSection,int32_t *out_buffer,int32_t *arg_3,int *arg_4,int *arg_5,
               int *arg_6,int32_t *arg_7,int32_t *arg_8)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_Options_pic_004f9ec4,&g_DuelAssetDirectory);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *hDIBSection = uval_1;
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
 * Decompiled function: FUN_004810c1
 * Entry Point: 004810c1
 * Size: 93 bytes
 */


void FUN_004810c1(HANDLE hDIBSection,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (hDIBSection != (HANDLE)0x0) {
    GDI_DestroyDIBSection(hDIBSection);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
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
 * Decompiled function: Rules_ParseFilter_0048111e
 * Entry Point: 0048111e
 * Size: 1906 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Rules_ParseFilter_0048111e(void)

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
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e48,0,1,
                        &target_idx);
  if (LVar1 == 0) {
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_Layout_004f9edc,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,&slot_idx)
    ;
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9ee4,&DAT_00663e24);
    }
    else {
      DAT_00663e24 = 1;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_DirectiveTracksMouse_004f9ee8,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9f00,&DAT_00663e04);
    }
    else {
      DAT_00663e04 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowCueCards_004f9f04,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,
                             &slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9f14,&DAT_00663e00);
    }
    else {
      DAT_00663e00 = 1;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowPowerToughnessOnCards_004f9f18,(LPDWORD)0x0,(LPDWORD)0x0
                             ,player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9f34,&DAT_00663e08);
    }
    else {
      DAT_00663e08 = 1;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowIDTagsOnCards_004f9f38,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9f4c,&DAT_00663e18);
    }
    else {
      DAT_00663e18 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowInvisibleEffectCards_004f9f50,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9f6c,&DAT_00663e1c);
    }
    else {
      DAT_00663e1c = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ShowAllCardsSummonSickness_004f9f70,(LPDWORD)0x0,
                             (LPDWORD)0x0,player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9f8c,&DAT_00663e20);
    }
    else {
      DAT_00663e20 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    RegQueryValueExA(target_idx,s_ShowAbilitiesOnCards_004f9f90,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,
                     &slot_idx);
    if (player_idx[0] == '\0') {
      DAT_00663e0c = 1;
    }
    else {
      _sscanf((char *)player_idx,&DAT_004f9fa8,&DAT_00663e0c);
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_ExpandTextBoxOnBigCard_004f9fac,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9fc4,&DAT_00663e10);
    }
    else {
      DAT_00663e10 = 0;
    }
    slot_idx = 10;
    player_idx[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_SeeNextDrawsAtEndOfDuel_004f9fc8,(LPDWORD)0x0,(LPDWORD)0x0,
                             player_idx,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)player_idx,&DAT_004f9fe0,&DAT_00663e14);
    }
    else {
      DAT_00663e14 = 1;
    }
    slot_idx = 100;
    local_84[0] = '\0';
    LVar1 = RegQueryValueExA(target_idx,s_PhaseStoppers_004f9fe4,(LPDWORD)0x0,(LPDWORD)0x0,local_84,
                             &slot_idx);
    if (LVar1 == 0) {
      local_88 = local_84;
      color_idx = 0;
      while ((color_idx < 2 && (*local_88 != '\0'))) {
        loop_idx = 0;
        while ((loop_idx < 0x25 && (*local_88 != '\0'))) {
          if (*local_88 == 'S') {
            *(int32_t *)(&DAT_006667c0 + color_idx * 0x98 + loop_idx * 4) = 1;
          }
          else {
            *(int32_t *)(&DAT_006667c0 + color_idx * 0x98 + loop_idx * 4) = 0;
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
          *(int32_t *)(&DAT_006667c0 + color_idx * 0x98 + loop_idx * 4) = 0;
        }
      }
      _DAT_00666810 = 1;
      _DAT_00666838 = 1;
      DAT_006668d4 = 1;
    }
    if (((uint8_t)DAT_00663dfc & 1) == 0) {
      slot_idx = 10;
      player_idx[0] = '\0';
      LVar1 = RegQueryValueExA(target_idx,s_PlayerTerritoryColor_004f9ff4,(LPDWORD)0x0,(LPDWORD)0x0,
                               player_idx,&slot_idx);
      if (LVar1 == 0) {
        _sscanf((char *)player_idx,&DAT_004fa00c,&DAT_00663e28);
      }
      else {
        DAT_00663e28 = 0xffffffff;
      }
    }
    if (((uint8_t)DAT_00663dfc & 1) == 0) {
      slot_idx = 10;
      player_idx[0] = '\0';
      LVar1 = RegQueryValueExA(target_idx,s_PlayerTerritoryType_004fa010,(LPDWORD)0x0,(LPDWORD)0x0,
                               player_idx,&slot_idx);
      if (LVar1 == 0) {
        _sscanf((char *)player_idx,&DAT_004fa024,&DAT_00663e2c);
      }
      else {
        DAT_00663e2c = 2;
      }
    }
    slot_idx = 10;
    LVar1 = RegQueryValueExA(target_idx,s_CoolKimCheats_004fa028,(LPDWORD)0x0,(LPDWORD)0x0,player_idx,
                             &slot_idx);
    if (LVar1 == 0) {
      val_2 = _strcmp((char *)player_idx,s_HolyMoly_004fa038);
      DAT_0061894c = (uint32_t)(val_2 == 0);
    }
    else {
      DAT_0061894c = 0;
    }
  }
  else {
    DAT_00663e24 = 1;
    DAT_00663e04 = 0;
    DAT_00663e00 = 1;
    DAT_00663e08 = 1;
    DAT_00663e18 = 0;
    DAT_00663e1c = 0;
    DAT_00663e20 = 0;
    DAT_00663e0c = 1;
    DAT_00663e10 = 0;
    DAT_00663e14 = 1;
    for (local_8c = 0; local_8c < 2; local_8c = local_8c + 1) {
      for (local_90 = 0; local_90 < 0x25; local_90 = local_90 + 1) {
        *(int32_t *)(&DAT_006667c0 + local_90 * 4 + local_8c * 0x98) = 0;
      }
    }
    _DAT_00666810 = 1;
    _DAT_00666820 = 1;
    _DAT_00666838 = 1;
    DAT_006668b0 = 1;
    _DAT_006668b8 = 1;
    DAT_006668d4 = 1;
    if (((uint8_t)DAT_00663dfc & 1) == 0) {
      DAT_00663e28 = 0xffffffff;
      DAT_00663e2c = 2;
    }
  }
  return;
}



/*
 * Decompiled function: Rules_ParseFilter_00481890
 * Entry Point: 00481890
 * Size: 1022 bytes
 */


void Rules_ParseFilter_00481890(void)

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
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e48,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&target_idx,&slot_idx);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)player_idx,&DAT_004fa044,DAT_00663e24);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_Layout_004fa048,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa050,DAT_00663e04);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_DirectiveTracksMouse_004fa054,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa06c,DAT_00663e00);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowCueCards_004fa070,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa080,DAT_00663e08);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowPowerToughnessOnCards_004fa084,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa0a0,DAT_00663e0c);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowAbilitiesOnCards_004fa0a4,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa0bc,DAT_00663e18);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowIDTagsOnCards_004fa0c0,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa0d4,DAT_00663e1c);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowInvisibleEffectCards_004fa0d8,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa0f4,DAT_00663e20);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ShowAllCardsSummonSickness_004fa0f8,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa114,DAT_00663e10);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_ExpandTextBoxOnBigCard_004fa118,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa130,DAT_00663e14);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_SeeNextDrawsAtEndOfDuel_004fa134,0,1,player_idx,len_2 + 1);
    local_88 = local_84;
    for (color_idx = 0; color_idx < 2; color_idx = color_idx + 1) {
      for (loop_idx = 0; loop_idx < 0x25; loop_idx = loop_idx + 1) {
        if (((&DAT_006667c0)[loop_idx * 4 + color_idx * 0x98] & 1) == 0) {
          *local_88 = '-';
        }
        else {
          *local_88 = 'S';
        }
        local_88 = local_88 + 1;
      }
    }
    *local_88 = '\0';
    len_2 = _strlen((char *)local_84);
    RegSetValueExA(target_idx,s_PhaseStoppers_004fa14c,0,1,local_84,len_2 + 1);
    if (((uint8_t)DAT_00663dfc & 1) == 0) {
      wsprintfA((LPSTR)player_idx,&DAT_004fa15c,DAT_00663e28);
      len_2 = _strlen((char *)player_idx);
      RegSetValueExA(target_idx,s_PlayerTerritoryColor_004fa160,0,1,player_idx,len_2 + 1);
    }
    if (((uint8_t)DAT_00663dfc & 1) == 0) {
      wsprintfA((LPSTR)player_idx,&DAT_004fa178,DAT_00663e2c);
      len_2 = _strlen((char *)player_idx);
      RegSetValueExA(target_idx,s_PlayerTerritoryType_004fa17c,0,1,player_idx,len_2 + 1);
    }
    RegFlushKey(target_idx);
    RegCloseKey(target_idx);
  }
  return;
}



/*
 * Decompiled function: FUN_00481c8e
 * Entry Point: 00481c8e
 * Size: 628 bytes
 */


void FUN_00481c8e(void)

{
  LSTATUS LVar1;
  HKEY local_2c;
  BYTE local_28 [32];
  DWORD slot_idx;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e4c,0,1,
                        &local_2c);
  if (LVar1 == 0) {
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Difficulty_004fa190,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa19c,&DAT_00664730);
    }
    else {
      DAT_00664730 = 1;
    }
    slot_idx = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_PlayerDeck_004fa1a0,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &slot_idx);
    if (LVar1 == 0) {
      _sprintf(&DAT_00664734,&DAT_004fa1ac,local_28);
    }
    else {
      DAT_00664734 = 0;
    }
    slot_idx = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_OpponentDeck_004fa1b0,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &slot_idx);
    if (LVar1 == 0) {
      _sprintf(&DAT_00664752,&DAT_004fa1c0,local_28);
    }
    else {
      DAT_00664752 = 0;
    }
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_004fa1c4,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa1cc,&DAT_00664770);
    }
    else {
      DAT_00664770 = 1;
    }
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Match_004fa1d0,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa1d8,&DAT_00664774);
    }
    else {
      DAT_00664774 = 1;
    }
    slot_idx = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_004fa1dc,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&slot_idx);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa1e4,&DAT_00664778);
    }
    else {
      DAT_00664778 = 1;
    }
    RegCloseKey(local_2c);
  }
  else {
    DAT_00664730 = 1;
    DAT_00664734 = 0;
    DAT_00664752 = 0;
    DAT_00664770 = 1;
    DAT_00664774 = 1;
    DAT_00664778 = 1;
  }
  return;
}



/*
 * Decompiled function: FUN_00481f02
 * Entry Point: 00481f02
 * Size: 418 bytes
 */


void FUN_00481f02(void)

{
  LSTATUS LVar1;
  size_t len_2;
  HKEY target_idx;
  BYTE player_idx [12];
  DWORD slot_idx;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e4c,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&target_idx,&slot_idx);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)player_idx,&DAT_004fa1e8,DAT_00664730);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_Difficulty_004fa1ec,0,1,player_idx,len_2 + 1);
    len_2 = _strlen(&DAT_00664734);
    RegSetValueExA(target_idx,s_PlayerDeck_004fa1f8,0,1,&DAT_00664734,len_2 + 1);
    len_2 = _strlen(&DAT_00664752);
    RegSetValueExA(target_idx,s_OpponentDeck_004fa204,0,1,&DAT_00664752,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa214,DAT_00664770);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,&DAT_004fa218,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa220,DAT_00664774);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,s_Match_004fa224,0,1,player_idx,len_2 + 1);
    wsprintfA((LPSTR)player_idx,&DAT_004fa22c,DAT_00664778);
    len_2 = _strlen((char *)player_idx);
    RegSetValueExA(target_idx,&DAT_004fa230,0,1,player_idx,len_2 + 1);
    RegFlushKey(target_idx);
    RegCloseKey(target_idx);
  }
  return;
}



/*
 * Decompiled function: UI_RegisterClass_00467880
 * Entry Point: 004820b0
 * Size: 287 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool UI_RegisterClass_00467880(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Card_Setup_00467a68;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_005dadac = CreatePopupMenu();
  DAT_005dada8 = CreatePopupMenu();
  AppendMenuA(DAT_005dada8,0,0x72,&DAT_004fa35c);
  DAT_005dade8 = LoadCursorA(g_DuelInstanceHandle,s_HAND1_004fa360);
  DAT_005dadd4 = 3;
  _DAT_005dadc8 = LoadCursorA(g_DuelInstanceHandle,s_HAND2_004fa368);
  _DAT_005dadcc = LoadCursorA(g_DuelInstanceHandle,s_HAND3_004fa370);
  _DAT_005dadd0 = LoadCursorA(g_DuelInstanceHandle,s_HAND4_004fa378);
  return AVar1 != 0;
}



/*
 * Decompiled function: FUN_004821cf
 * Entry Point: 004821cf
 * Size: 202 bytes
 */


void FUN_004821cf(void)

{
  int slot_idx;
  
  if (DAT_005dadac != (HMENU)0x0) {
    DestroyMenu(DAT_005dadac);
  }
  if (DAT_005dada8 != (HMENU)0x0) {
    DestroyMenu(DAT_005dada8);
  }
  DAT_005dadac = (HMENU)0x0;
  DAT_005dada8 = (HMENU)0x0;
  if (DAT_005dade8 != (HCURSOR)0x0) {
    DestroyCursor(DAT_005dade8);
  }
  DAT_005dade8 = (HCURSOR)0x0;
  for (slot_idx = 0; slot_idx < DAT_005dadd4; slot_idx = slot_idx + 1) {
    if (*(int *)(&DAT_005dadc8 + slot_idx * 4) != 0) {
      DestroyCursor(*(HCURSOR *)(&DAT_005dadc8 + slot_idx * 4));
    }
    *(int32_t *)(&DAT_005dadc8 + slot_idx * 4) = 0;
  }
  return;
}



/*
 * Decompiled function: Card_Setup_00467a68
 * Entry Point: 00482299
 * Size: 12135 bytes
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Card_Setup_00467a68(HWND hwnd,uint32_t uMsg,HWND wParam,int *lParam)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  uint8_t arg_3;
  uint32_t uval_1;
  LONG LVar2;
  HWND pHVar3;
  HBRUSH pHVar4;
  int val_5;
  uint32_t uval_6;
  DWORD DVar7;
  BOOL BVar8;
  LRESULT LVar9;
  UINT UVar10;
  int *wParam_00;
  LONG *pLVar11;
  LPARAM LVar12;
  int iVar13;
  int local_960;
  int32_t local_954;
  HWND local_950;
  int local_94c;
  uint32_t local_948;
  uint32_t local_944;
  uint32_t local_940;
  int32_t local_93c;
  int32_t local_938;
  uint32_t local_934;
  uint32_t local_930;
  int32_t local_92c;
  uint32_t local_928;
  int32_t local_924;
  HWND local_920;
  tagMSG local_91c;
  HWND local_900;
  int local_8fc;
  tagPOINT local_8f8;
  tagRECT local_8f0;
  int32_t local_8e0;
  uint32_t local_8dc;
  uint32_t local_8d8;
  int local_8d4;
  int local_8d0;
  int local_8cc;
  int local_8c8;
  HDC local_8c4;
  tagPAINTSTRUCT local_8c0;
  tagRECT local_880;
  DWORD local_870;
  ULONG_PTR local_86c;
  int32_t local_868;
  int32_t local_864;
  HWND local_860;
  HWND local_85c;
  HWND local_858;
  tagRECT local_854;
  tagMSG local_844;
  BOOL local_828;
  int local_824;
  tagRECT local_820;
  LONG *local_810;
  int32_t local_80c;
  CHAR local_808 [100];
  int local_7a4;
  int local_7a0;
  int local_79c;
  int local_798;
  int local_794;
  uint8_t local_790 [20];
  uint32_t local_77c;
  char local_778 [208];
  int local_6a8;
  int local_6a4;
  int local_6a0;
  CHAR local_69c [100];
  int local_638;
  int local_634;
  int local_630;
  int local_62c;
  int local_628;
  uint8_t local_624 [20];
  uint32_t local_610;
  char local_60c [208];
  int local_53c [68];
  ULONG_PTR local_42c;
  uint32_t local_428;
  int local_424;
  int local_420;
  WPARAM local_41c;
  LONG local_418;
  LONG local_414;
  HWND local_410;
  int local_40c;
  HWND local_408 [2];
  uint8_t local_400 [288];
  HWND local_2e0;
  HDC local_2d4;
  tagRECT local_2d0;
  ULONG_PTR local_2c0;
  uint8_t local_2bc [84];
  int local_268;
  uint32_t local_19c;
  uint32_t local_198;
  uint32_t local_194;
  tagRECT local_190;
  uint32_t local_180 [25];
  uint32_t local_11c;
  uint32_t local_118;
  uint32_t local_114;
  uint32_t local_110;
  int local_10c;
  int local_108;
  uint32_t local_104 [18];
  tagRECT local_bc;
  int local_ac;
  int local_a8;
  int local_a4;
  char *local_a0 [4];
  char *local_90;
  char *local_8c;
  char *local_88;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  uint32_t local_5c;
  int local_58;
  tagRECT local_54;
  int local_44;
  int local_40;
  int local_3c;
  tagRECT local_38;
  tagRECT local_28;
  int target_idx;
  void *player_idx;
  int card_idx;
  int match_count;
  HWND slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      LVar9 = SendMessageA(hwnd,0x404,0,0);
      if (LVar9 != 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_870 = GetTickCount();
      GetClientRect(hwnd,&local_880);
      local_8c4 = BeginPaint(hwnd,&local_8c0);
      if (local_8c4 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_8c4);
        if (DAT_00601580 != 0) {
          pHVar4 = GetStockObject(0);
          FillRect(local_8c4,&local_880,pHVar4);
          Sleep(200);
        }
        if ((match_count == -1) && (card_idx == -1)) {
          FUN_0042043e(local_8c4,&local_880);
        }
        else if (card_idx == -1) {
          FUN_004371ec(local_8c4,&local_880,match_count);
          pHVar4 = GetStockObject(4);
          FrameRect(local_8c4,&local_880,pHVar4);
        }
        else {
          local_86c = Deck_ValidateCardLimit(match_count, card_idx);
          if ((local_86c != 0xffffffff) && ((int)local_86c < DAT_0061743c)) {
            if (DAT_0068f108 == local_86c) {
              FUN_0042043e(local_8c4,&local_880);
              iVar13 = 1;
              val_5 = FUN_00447c07(match_count,card_idx);
              FUN_00424f7b(local_8c4,&local_880.left,0x4fa6b8,val_5,iVar13);
            }
            else if ((((local_86c == DAT_00666720) || (DAT_00666450 == local_86c)) ||
                     (local_86c == DAT_00666444)) || (local_86c == DAT_0066aae8)) {
              FUN_004474ec(&local_8cc,match_count,card_idx);
              Palette_Subsystem_0049eda9(local_8c4,&local_880.left,local_86c,match_count,card_idx);
              val_5 = FUN_00447cf8(match_count,card_idx);
              iVar13 = FUN_00447c74(match_count,card_idx);
              FUN_00426620(local_8c4,&local_880.left,iVar13,val_5);
              FUN_004241e8(local_8c4,&local_880.left,local_8cc,local_8c8,DAT_00663e18);
            }
            else if (DAT_0068f0fc == local_86c) {
              FUN_0044826e(&local_8d4,match_count,card_idx);
              Palette_Subsystem_004a155f
                        (DAT_0060157c,&local_880,local_86c,match_count,card_idx,local_8d4,local_8d0);
              val_5 = FUN_00447cf8(local_8d4,local_8d0);
              iVar13 = FUN_00447c74(local_8d4,local_8d0);
              FUN_00426620(DAT_0060157c,&local_880.left,iVar13,val_5);
              FUN_004241e8(DAT_0060157c,&local_880.left,local_8d4,local_8d0,DAT_00663e18);
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,DAT_0060157c,0,0,0xcc0020);
            }
            else {
              local_8d8 = FUN_004472ad(match_count,card_idx);
              pHVar3 = GetParent(hwnd);
              if (pHVar3 == DAT_00618ab0) {
                local_8dc = 0;
              }
              else {
                local_8dc = local_8d8 & 4;
                local_8e0 = FUN_00447038(match_count,card_idx);
              }
              FUN_00447c07(match_count,card_idx);
              Palette_Subsystem_004a155f(DAT_0060157c,&local_880.left,match_count,card_idx);
              val_5 = FUN_00447cf8(match_count,card_idx);
              iVar13 = FUN_00447c74(match_count,card_idx);
              FUN_00426620(DAT_0060157c,&local_880.left,iVar13,val_5);
              uval_6 = FUN_00448124(match_count,card_idx);
              FUN_00426746(DAT_0060157c,&local_880.left,uval_6 & 0x20000);
              arg_3 = FUN_00448191(match_count,card_idx);
              FUN_004267dc(DAT_0060157c,&local_880,arg_3);
              FUN_004241e8(DAT_0060157c,&local_880.left,match_count,card_idx,DAT_00663e18);
              uval_6 = FUN_00447604(match_count,card_idx);
              if ((((uval_6 & 2) != 0) || (DAT_00663e20 != 0)) &&
                 (uval_6 = FUN_004472ad(match_count,card_idx), (uval_6 & 1) != 0)) {
                Mem_AllocOrFree_00426c5c(&DAT_00617440,DAT_0061897c,&local_880);
              }
              if ((local_8d8 & 2) != 0) {
                FUN_0047173d(0x617440,DAT_0061897c,&local_880);
              }
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,DAT_0060157c,0,0,0xcc0020);
            }
            player_idx = (void *)GetWindowLongA(hwnd,0xc);
            FUN_004485c7(player_idx,match_count,card_idx);
            if (DAT_005f77f0 != 0) {
              FUN_00486239(local_8c4,(int)&local_880,match_count,card_idx);
            }
          }
        }
        EndPaint(hwnd,&local_8c0);
      }
      DVar7 = GetTickCount();
      _DAT_0060d494 = _DAT_0060d494 + (DVar7 - local_870);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      local_810 = (LONG *)*lParam;
      if (local_810 == (LONG *)0x0) {
        return -1;
      }
      match_count = *local_810;
      card_idx = local_810[1];
      SetWindowLongA(hwnd,0,match_count);
      SetWindowLongA(hwnd,4,card_idx);
      slot_idx = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      player_idx = _malloc(0x120);
      SetWindowLongA(hwnd,0xc,(LONG)player_idx);
      SetWindowLongA(hwnd,0x10,0);
      if (player_idx == (void *)0x0) {
        return -1;
      }
      _memset(player_idx,0,0x120);
      return 0;
    }
    if (uMsg == 2) {
      player_idx = (void *)GetWindowLongA(hwnd,0xc);
      FUN_004db150(player_idx);
      return 0;
    }
    if (uMsg == 3) {
      LVar12 = 0;
      UVar10 = 0x410;
      pHVar3 = GetParent(hwnd);
      SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar9 = UI_WndProc_00471df6(hwnd,0x20,(WPARAM)wParam,(LPARAM)lParam);
      return LVar9;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x117) {
    if (uMsg == 0x116) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      local_940 = FUN_004472ad(match_count,card_idx);
      local_940 = local_940 & 4;
      if (local_940 != 0) {
        FUN_00447038(match_count,card_idx);
      }
      local_938 = FUN_00447038(match_count,card_idx);
      local_93c = FUN_00485361(hwnd);
      local_948 = FUN_00447751(match_count,card_idx);
      local_948 = local_948 & 0x40;
      local_94c = FUN_004471f7(match_count,card_idx);
      local_944 = FUN_00447114(match_count,card_idx);
      local_924 = Deck_ValidateCardLimit(match_count, card_idx);
      local_930 = FUN_004478fb(match_count,card_idx);
      local_930 = local_930 & 0x40000;
      local_934 = *(uint32_t *)(&DAT_004ff5a8 + local_944 * 0x34) & 0x1000;
      uval_6 = FUN_00447604(match_count,card_idx);
      local_950 = GetParent(hwnd);
      local_928 = FUN_00448304(match_count,card_idx);
      FUN_0044897a(&local_92c,&local_954);
      if (local_928 != local_944) {
        AppendMenuA(DAT_005dadac,0x10,(UINT_PTR)DAT_005dada8,s_Original_type_004fa6c4);
        val_5 = CardIDFromType(local_928);
        ModifyMenuA(DAT_005dada8,0x72,0,0x72,*(LPCSTR *)(&DAT_00618ac4 + val_5 * 0x98));
      }
      if (DAT_00663e24 == 2) {
        AppendMenuA(DAT_005dadac,0,0x6e,s_Show_full_card_R_DblClk_004fa6d4);
      }
      else {
        AppendMenuA(DAT_005dadac,0,0x6e,s_View_in_full_card_004fa6ec);
      }
      if (((((uval_6 & 1) != 0) && (local_934 != 0)) &&
          (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00617378)) &&
         (AppendMenuA(DAT_005dadac,0,0x70,s_Don_t_auto_tap_this_card_004fa700), local_930 != 0)) {
        CheckMenuItem(DAT_005dadac,0x70,8);
      }
      AppendMenuA(DAT_005dadac,0,0x73,s_Show_ID_tags_Ctrl_T_004fa71c);
      if (DAT_00663e18 != 0) {
        CheckMenuItem(DAT_005dadac,0x73,8);
      }
      AppendMenuA(DAT_005dadac,0,0x74,s_Show_invisible_effects_Ctrl_I_004fa730);
      if (DAT_00663e1c != 0) {
        CheckMenuItem(DAT_005dadac,0x74,8);
      }
      AppendMenuA(DAT_005dadac,0,0x75,s_Show_all_cards__summoning_sickne_004fa750);
      if (DAT_00663e20 != 0) {
        CheckMenuItem(DAT_005dadac,0x75,8);
      }
      AppendMenuA(DAT_005dadac,0,0x71,s_Help____004fa77c);
      if ((DAT_00601618 != 0) && (DAT_00618158 != 0)) {
        if (local_94c == 0) {
          AppendMenuA(DAT_005dadac,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dadac,0,0x262,s__M__Add_mana_for_this_card_004fa784);
          AppendMenuA(DAT_005dadac,0,0x264,s__B__Bury_this_card_004fa7a0);
        }
        else {
          AppendMenuA(DAT_005dadac,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_005dadac,0,0x262,s__M__Add_mana_for_this_card_004fa7b4);
          AppendMenuA(DAT_005dadac,0,0x263,s__T__Tap_untap_this_card_004fa7d0);
          AppendMenuA(DAT_005dadac,0,0x264,s__B__Bury_this_card_004fa7e8);
          AppendMenuA(DAT_005dadac,0,0x266,s__X__Increment_counters_for_this_c_004fa7fc);
        }
      }
      return 0;
    }
    if (uMsg == 0x111) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      local_418 = match_count;
      local_414 = card_idx;
      pHVar3 = GetParent(hwnd);
      if (pHVar3 == DAT_00618ab0) {
        local_410 = hwnd;
        FUN_004b26c4(DAT_00617378,&local_418,(int32_t *)0x0,local_408);
      }
      else {
        local_408[0] = hwnd;
        FUN_004994f8(DAT_00618ab0,&local_418,(int32_t *)0x0,&local_410,(int32_t *)0x0);
      }
      uval_6 = (uint32_t)wParam & 0xffff;
      if (uval_6 < 0x263) {
        if (uval_6 == 0x262) {
          if (DAT_00601618 != 0) {
            local_40c = *(int *)(&g_DuelCardSlot_CardId + match_count * 0x5b20 + card_idx * 0x120);
            val_5 = (int)(char)(&g_DuelMasterCardSubType)[local_40c * 0x34];
            iVar13 = Duel_ColorMaskToIndex((&DAT_004ff596)
                                  [*(int *)(&g_DuelCardSlot_CardId + match_count * 0x5b20 + card_idx * 0x120) *
                                   0x34]);
            FUN_0049b235(match_count,iVar13,val_5);
            val_5 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_40c * 0x34]);
            FUN_0049b235(match_count,0,val_5);
            FUN_00446d17();
            Duel_RefreshAllWindows(0,0xff);
          }
        }
        else {
          switch(uval_6) {
          case 100:
          case 0x6d:
            DAT_0066643c = 0;
            FUN_004852b1(hwnd);
            break;
          case 0x65:
            FUN_0044897a((int32_t *)0x0,local_53c);
            val_5 = FUN_0048ad82(match_count,card_idx);
            if (val_5 != 0) {
              local_53c[1] = 0xffffffff;
              *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                   *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 4;
              (&DAT_006826de)[match_count * 0x5b20 + card_idx * 0x120] = 0xff;
              FUN_004457a2();
              if ((local_53c[0] < 0x15) || (0x1d < local_53c[0])) {
                LVar12 = 0;
                pLVar11 = &local_418;
                UVar10 = 0x436;
                pHVar3 = GetParent(hwnd);
                SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
              }
              else {
                SendMessageA(DAT_00618ab0,0x412,0,0);
              }
            }
            break;
          case 0x66:
            val_5 = FUN_00447038(match_count,card_idx);
            if (val_5 != -1) {
              SendMessageA(hwnd,0x111,0x69,0);
            }
            *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                 *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) & 0xfffffffb;
            (&DAT_006826de)[match_count * 0x5b20 + card_idx * 0x120] = 0xff;
            FUN_004457a2();
            if (hwnd == local_410) {
              SendMessageA(DAT_00618ab0,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x68:
            SendMessageA(hwnd,0x111,0x69,0);
          case 0x67:
            val_5 = FUN_0048ad82(match_count,card_idx);
            if (val_5 != 0) {
              FID_conflict__memcpy(local_624,&DAT_00664780,0xe8);
              GetWindowTextA(DAT_0060cc6c,local_69c,100);
              local_628 = DAT_00618158;
              local_634 = Action_ValidateTarget_0041e2a2
                                    (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                     s_Band_with_which_attacker__004fa634,1,&local_630);
              DAT_00618158 = local_628;
              if (local_634 != 0) {
                uval_6 = FUN_004472ad(local_630,local_62c);
                if ((uval_6 & 4) == 0) {
                  UpdateWindow(g_DuelMainHwnd);
                  FUN_004469c9(s_That_isn_t_an_attacker_004fa660);
                  UpdateWindow(DAT_00664d90);
                  Sleep(2000);
                }
                else {
                  val_5 = FUN_00498613(match_count,card_idx);
                  if (val_5 == 0) {
                    UpdateWindow(g_DuelMainHwnd);
                    FUN_004469c9(s_Illegal_band_004fa650);
                    UpdateWindow(DAT_00664d90);
                    Sleep(2000);
                  }
                  else {
                    local_638 = FUN_00447038(local_630,local_62c);
                    if (local_638 == -1) {
                      local_638 = local_62c;
                      val_5 = local_638;
                      *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                           *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 4;
                      local_638._0_1_ = (uint8_t)local_62c;
                      (&DAT_006826de)[match_count * 0x5b20 + card_idx * 0x120] = (uint8_t)local_638;
                      *(uint32_t *)(&g_DuelCardSlot_Flags + local_630 * 0x5b20 + local_62c * 0x120) =
                           *(uint32_t *)(&g_DuelCardSlot_Flags + local_630 * 0x5b20 + local_62c * 0x120) | 4;
                      (&DAT_006826de)[local_630 * 0x5b20 + local_62c * 0x120] =
                           (uint8_t)local_638;
                      local_638 = val_5;
                      FUN_004457a2();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(DAT_00618ab0);
                      if (BVar8 == 0) {
                        LVar12 = 0;
                        wParam_00 = &local_630;
                        UVar10 = 0x436;
                        pHVar3 = GetParent(local_408[0]);
                        SendMessageA(pHVar3,UVar10,(WPARAM)wParam_00,LVar12);
                      }
                      else {
                        SendMessageA(DAT_00618ab0,0x412,0,0);
                        SendMessageA(DAT_00618ab0,0x436,(WPARAM)&local_630,0);
                      }
                    }
                    else {
                      *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                           *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 4;
                      (&DAT_006826de)[match_count * 0x5b20 + card_idx * 0x120] = (uint8_t)local_638;
                      FUN_004457a2();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(DAT_00618ab0);
                      if (BVar8 != 0) {
                        SendMessageA(DAT_00618ab0,0x412,0,0);
                      }
                    }
                  }
                }
              }
              FID_conflict__memcpy(&DAT_00664780,local_624,0xe8);
              FUN_004b7b63(DAT_00664d90,local_60c,local_610);
              FUN_00446a07(local_69c);
            }
            break;
          case 0x69:
            local_6a0 = FUN_00447038(match_count,card_idx);
            for (local_6a4 = 0; local_6a4 < (int)(&g_DuelPlayerCreatureCount)[match_count]; local_6a4 = local_6a4 + 1
                ) {
              val_5 = FUN_00447114(match_count,local_6a4);
              if (((val_5 != -1) && (uval_6 = FUN_004472ad(match_count,local_6a4), (uval_6 & 4) != 0)) &&
                 (val_5 = FUN_00447038(match_count,local_6a4), val_5 == local_6a0)) {
                (&DAT_006826de)[local_6a4 * 0x120 + match_count * 0x5b20] = 0xff;
                FUN_004457a2();
                local_418 = match_count;
                local_414 = local_6a4;
                BVar8 = IsWindowVisible(DAT_00618ab0);
                if (BVar8 == 0) {
                  LVar12 = 0;
                  pLVar11 = &local_418;
                  UVar10 = 0x436;
                  pHVar3 = GetParent(local_408[0]);
                  SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                }
                else {
                  SendMessageA(DAT_00618ab0,0x436,(WPARAM)&local_418,0);
                }
              }
            }
            BVar8 = IsWindowVisible(DAT_00618ab0);
            if (BVar8 != 0) {
              SendMessageA(DAT_00618ab0,0x412,0,0);
            }
            break;
          case 0x6a:
          case 0x6b:
            FID_conflict__memcpy(local_790,&DAT_00664780,0xe8);
            GetWindowTextA(DAT_0060cc6c,local_808,100);
            local_794 = DAT_00618158;
            local_7a0 = Action_ValidateTarget_0041e2a2
                                  (0,1,0,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                   s_Block_which_attacker__004fa678,1,&local_79c);
            DAT_00618158 = local_794;
            if (local_7a0 != 0) {
              uval_6 = FUN_004472ad(local_79c,local_798);
              if ((uval_6 & 4) == 0) {
                UpdateWindow(g_DuelMainHwnd);
                FUN_004469c9(s_That_isn_t_an_attacker_004fa6a0);
                UpdateWindow(DAT_00664d90);
                Sleep(2000);
              }
              else {
                val_5 = FUN_0048b4c5(match_count,card_idx,local_79c,local_798);
                if (val_5 == 0) {
                  UpdateWindow(g_DuelMainHwnd);
                  FUN_004469c9(s_Illegal_block_004fa690);
                  UpdateWindow(DAT_00664d90);
                  Sleep(2000);
                }
                else {
                  local_7a4 = FUN_00447038(local_79c,local_798);
                  local_6a8 = local_7a4;
                  if (local_7a4 == -1) {
                    local_6a8 = local_798;
                  }
                  *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                       *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 8;
                  (&DAT_006826de)[match_count * 0x5b20 + card_idx * 0x120] = (uint8_t)local_6a8;
                  FUN_004457a2();
                  BVar8 = IsWindowVisible(DAT_00618ab0);
                  if ((BVar8 == 0) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00618ab0)) {
                    LVar12 = 0;
                    pLVar11 = &local_418;
                    UVar10 = 0x436;
                    pHVar3 = GetParent(hwnd);
                    SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                  }
                  else {
                    SendMessageA(DAT_00618ab0,0x412,0,0);
                  }
                }
              }
            }
            FID_conflict__memcpy(&DAT_00664780,local_790,0xe8);
            FUN_004b7b63(DAT_00664d90,local_778,local_77c);
            FUN_00446a07(local_808);
            break;
          case 0x6c:
            *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                 *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) & 0xfffffff7;
            (&DAT_006826de)[match_count * 0x5b20 + card_idx * 0x120] = 0xff;
            FUN_004457a2();
            if (hwnd == local_410) {
              SendMessageA(DAT_00618ab0,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x6e:
            local_41c = Deck_ValidateCardLimit(match_count, card_idx);
            local_424 = match_count;
            local_420 = card_idx;
            SendMessageA(DAT_006152e0,0x401,local_41c,(LPARAM)&local_424);
            break;
          case 0x6f:
            pHVar3 = GetParent(hwnd);
            if ((pHVar3 == DAT_006152b0) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00663df4)) {
              LVar12 = 0;
              UVar10 = 0x400;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
            }
            break;
          case 0x70:
            uval_6 = FUN_004478fb(match_count,card_idx);
            local_428 = (uint32_t)((uval_6 & 0x40000) == 0);
            if (local_428 == 0) {
              *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                   *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) & 0xfffbffff;
            }
            else {
              *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                   *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 0x40000;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
            *(int32_t *)(&DAT_0060162c + match_count * 0x5b20 + card_idx * 0x120) =
                 *(int32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
            InvalidateRect(hwnd,(RECT *)0x0,1);
            break;
          case 0x71:
            local_42c = Deck_ValidateCardLimit(match_count, card_idx);
            if (local_42c == DAT_0068f108) {
              local_42c = 0xc1b;
            }
            if (local_42c != 0xffffffff) {
              Mem_AllocOrFree_004d9630((uint32_t *)(local_53c + 2),(uint32_t *)&DAT_005f76e0);
              Str_CopyFast((uint32_t *)(local_53c + 2),(uint32_t *)s__duel_hlp_004fa628);
              WinHelpA(g_DuelMainHwnd,(LPCSTR)(local_53c + 2),1,local_42c);
            }
            break;
          case 0x73:
            SendMessageA(g_DuelMainHwnd,0x111,0x279,0);
            break;
          case 0x74:
            SendMessageA(g_DuelMainHwnd,0x111,0x27a,0);
            break;
          case 0x75:
            SendMessageA(g_DuelMainHwnd,0x111,0x27c,0);
          }
        }
      }
      else if (uval_6 == 0x263) {
        if (DAT_00601618 != 0) {
          *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
               *(uint32_t *)(&g_DuelCardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) ^ 0x10;
          Duel_RefreshAllWindows(0,0xff);
        }
      }
      else if (uval_6 == 0x264) {
        if (DAT_00601618 != 0) {
          local_80c = *(int32_t *)(&DAT_006667c0 + g_DuelCombatPhaseState * 4 + g_TurnPlayer * 0x98);
          *(uint32_t *)(&DAT_006667c0 + g_DuelCombatPhaseState * 4 + g_TurnPlayer * 0x98) =
               *(uint32_t *)(&DAT_006667c0 + g_DuelCombatPhaseState * 4 + g_TurnPlayer * 0x98) & 0xfffe;
          *(uint32_t *)(&g_DuelCardSlot_Abilities1 + match_count * 0x5b20 + card_idx * 0x120) =
               *(uint32_t *)(&g_DuelCardSlot_Abilities1 + match_count * 0x5b20 + card_idx * 0x120) | 8;
          Duel_DrawCardSprite(match_count,card_idx,2);
          *(int32_t *)(&DAT_006667c0 + g_DuelCombatPhaseState * 4 + g_TurnPlayer * 0x98) = local_80c;
          Duel_RefreshAllWindows(0,0xff);
        }
      }
      else if ((uval_6 == 0x266) && (DAT_00601618 != 0)) {
        *(int *)(&DAT_0068270c + match_count * 0x5b20 + card_idx * 0x120) =
             *(int *)(&DAT_0068270c + match_count * 0x5b20 + card_idx * 0x120) + 1;
        Duel_RefreshAllWindows(0,0xff);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      UVar10 = GetDoubleClickTime();
      LVar2 = GetMessageTime();
      DVar7 = GetTickCount();
      Sleep(UVar10 - (LVar2 - DVar7));
      local_828 = PeekMessageA(&local_844,hwnd,0x203,0x203,0);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 == DAT_00617378) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_00618988)) {
        if (slot_idx == (HWND)0x0) {
          local_85c = hwnd;
        }
        else {
          local_85c = slot_idx;
          pHVar3 = local_85c;
          do {
            local_85c = pHVar3;
            local_860 = (HWND)FUN_004864b1(local_85c);
            pHVar3 = local_860;
          } while (local_860 != (HWND)0x0);
          local_860 = (HWND)0x0;
        }
        GetWindowRect(local_85c,&local_854);
        local_858 = GetWindow(local_85c,3);
        SendMessageA(local_85c,0x112,0xf012,0);
        GetWindowRect(local_85c,&local_820);
        val_5 = Mem_AllocOrFree_004d9810(local_854.top - local_820.top);
        iVar13 = Mem_AllocOrFree_004d9810(local_854.left - local_820.left);
        if (val_5 + iVar13 < 5) {
          local_824 = 0;
          SetWindowPos(local_85c,local_858,0,0,0,0,3);
        }
        else {
          local_824 = 1;
        }
      }
      else {
        local_824 = 0;
      }
      if (local_824 == 0) {
        FUN_0044897a(&local_864,&local_868);
        val_5 = FUN_00485361(hwnd);
        if (val_5 != 0) {
          DAT_0066643c = local_828;
          FUN_004852b1(hwnd);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == (int *)0x0)) {
        local_960 = GetMenuItemCount(DAT_005dadac);
        while (local_960 != 0) {
          RemoveMenu(DAT_005dadac,0,0x400);
          local_960 = local_960 + -1;
        }
        pHVar3 = GetParent(hwnd);
        if ((pHVar3 != DAT_006152b0) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_00663df4)) {
          pHVar3 = (HWND)GetWindowLongA(hwnd,0x10);
          SetWindowPos(hwnd,pHVar3,0,0,0,0,3);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar9 = GDI_RealizePaletteTree(hwnd,uMsg,wParam,lParam);
      return LVar9;
    }
    if (uMsg == 0x204) {
      local_8fc = 1;
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != DAT_006152b0) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_00663df4)) {
        local_900 = GetWindow(hwnd,3);
        SetWindowLongA(hwnd,0x10,(LONG)local_900);
        BringWindowToTop(hwnd);
      }
      if (DAT_00663e24 == 2) {
        UVar10 = GetDoubleClickTime();
        Sleep(UVar10);
        BVar8 = PeekMessageA(&local_91c,hwnd,0x206,0x206,0);
        if (BVar8 != 0) {
          local_8fc = 0;
        }
      }
      if ((match_count != -1) && (card_idx == -1)) {
        local_8fc = 0;
      }
      if (local_8fc != 0) {
        local_8f8.x = (uint32_t)lParam & 0xffff;
        local_8f8.y = (uint32_t)lParam >> 0x10;
        ClientToScreen(hwnd,&local_8f8);
        val_5 = GetSystemMetrics(0xd);
        local_8f8.x = local_8f8.x + val_5;
        val_5 = local_8f8.y + 4;
        iVar13 = local_8f8.y + 5;
        local_8f8.y = val_5;
        SetRect(&local_8f0,local_8f8.x,val_5,local_8f8.x + 1,iVar13);
        TrackPopupMenu(DAT_005dadac,2,local_8f8.x,local_8f8.y,0,hwnd,(RECT *)0x0);
      }
      return 0;
    }
    if (uMsg == 0x205) {
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != DAT_006152b0) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_00663df4)) {
        local_920 = (HWND)GetWindowLongA(hwnd,0x10);
        SetWindowPos(hwnd,local_920,0,0,0,0,3);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      if ((match_count == -1) || (card_idx != -1)) {
        SendMessageA(hwnd,0x111,0x6e,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      LVar9 = Deck_ValidateCardLimit(match_count, card_idx);
      return LVar9;
    case 0x401:
      match_count = GetWindowLongA(hwnd,0);
      LVar2 = GetWindowLongA(hwnd,4);
      if (wParam != (HWND)0x0) {
        wParam->unused = match_count;
        wParam[1].unused = LVar2;
      }
      return 0;
    case 0x402:
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      local_2e0 = wParam;
      if (slot_idx != wParam) {
        if (wParam == (HWND)0x0) {
          BringWindowToTop(hwnd);
        }
        slot_idx = local_2e0;
        SetWindowLongA(hwnd,8,(LONG)local_2e0);
      }
      return 0;
    case 0x403:
      LVar2 = GetWindowLongA(hwnd,8);
      return LVar2;
    case 0x404:
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      player_idx = (void *)GetWindowLongA(hwnd,0xc);
      if ((match_count != -1) && (card_idx == -1)) {
        return 0;
      }
      FUN_004485c7(local_400,match_count,card_idx);
      val_5 = _memcmp(player_idx,local_400,0x120);
      return val_5;
    case 0x432:
      BVar8 = IsWindowVisible(hwnd);
      if (BVar8 == 0) {
        return 0;
      }
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      player_idx = (void *)GetWindowLongA(hwnd,0xc);
      FUN_004485c7(local_2bc,match_count,card_idx);
      if ((match_count != -1) && (card_idx == -1)) {
        return 0;
      }
      val_5 = FUN_004855f9((int)player_idx,(int)local_2bc);
      if (val_5 == 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      else if ((DAT_00663e0c == 0) ||
              (val_5 = FUN_00485c20((int)player_idx,(int)local_2bc), val_5 != 0)) {
        if (*(int *)((int)player_idx + 0x54) != local_268) {
          local_2c0 = Deck_ValidateCardLimit(match_count, card_idx);
          uval_6 = FUN_004472ad(match_count,card_idx);
          if ((uval_6 & 2) == 0) {
            if ((((DAT_0068f0fc == local_2c0) || (DAT_0068f108 == local_2c0)) ||
                (DAT_00666444 == local_2c0)) ||
               (((DAT_00666720 == local_2c0 || (DAT_0066aae8 == local_2c0)) ||
                (DAT_00666450 == local_2c0)))) {
              InvalidateRect(hwnd,(RECT *)0x0,0);
            }
            else if (local_2c0 != 0xffffffff) {
              local_2d4 = GetDC(hwnd);
              GDI_RealizeAndFlushPalette(local_2d4);
              GetClientRect(hwnd,&local_2d0);
              val_5 = FUN_00447a88(match_count,card_idx);
              uval_6 = (uint32_t)(val_5 == match_count);
              val_5 = FUN_00447c07(match_count,card_idx);
              FUN_00424f7b(local_2d4,&local_2d0.left,*(int *)(&DAT_00618ac8 + local_2c0 * 0x98),
                           val_5,uval_6);
              ReleaseDC(hwnd,local_2d4);
              *(int *)((int)player_idx + 0x54) = local_268;
            }
          }
          else {
            InvalidateRect(hwnd,(RECT *)0x0,0);
          }
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      local_104[0] = 0x20;
      local_104[1] = 0x400;
      local_104[2] = 0x40;
      local_104[3] = 0x80;
      local_104[4] = 0x100;
      local_104[5] = 0x200;
      local_104[6] = 1;
      local_104[7] = 2;
      local_104[8] = 4;
      local_104[9] = 8;
      local_104[10] = 0x10;
      local_104[0xb] = 0x800;
      local_104[0xc] = 0x1000;
      local_104[0xd] = 0x2000;
      local_104[0xe] = 0x4000;
      local_104[0xf] = 0x8000;
      local_104[0x10] = 0x10000;
      local_a0[0] = s_Flying_004fa388;
      local_a0[1] = &DAT_004fa394;
      local_a0[2] = s_Banding_004fa3a0;
      local_a0[3] = s_Trample_004fa3b0;
      local_90 = s_First_strike_004fa3c8;
      local_8c = s_Regenerates_004fa3e4;
      local_88 = s_Swampwalk_004fa3fc;
      local_84 = s_Islandwalk_004fa414;
      local_80 = s_Forestwalk_004fa42c;
      local_7c = s_Mountainwalk_004fa448;
      local_78 = s_Plainswalk_004fa464;
      local_74 = s_Protection_from_black_004fa488;
      local_70 = s_Protection_from_blue_004fa4b8;
      local_6c = s_Protection_from_green_004fa4e8;
      local_68 = s_Protection_from_red_004fa514;
      local_64 = s_Protection_from_white_004fa540;
      local_60 = s_Protection_from_artifacts_004fa574;
      local_ac = 0x11;
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      local_3c = Deck_ValidateCardLimit(match_count, card_idx);
      local_114 = (uint32_t)lParam & 0xffff;
      local_110 = (uint32_t)lParam >> 0x10;
      if ((match_count == -1) || (card_idx != -1)) {
        local_10c = 0;
        GetClientRect(hwnd,&local_54);
        uval_1 = FUN_004472ad(match_count,card_idx);
        uval_6 = local_114;
        if ((uval_1 & 2) != 0) {
          local_19c = local_114;
          local_114 = local_110;
          local_110 = local_54.bottom - uval_6;
        }
        local_194 = FUN_00447751(match_count,card_idx);
        local_44 = -1;
        if (local_194 != 0) {
          local_108 = 0;
          while ((local_108 < local_ac && (local_44 == -1))) {
            FUN_00424d18(&local_190,local_104[local_108],&local_54.left,local_194);
            pt.y = local_110;
            pt.x = local_114;
            BVar8 = PtInRect(&local_190,pt);
            if (BVar8 != 0) {
              local_44 = local_108;
            }
            local_108 = local_108 + 1;
          }
        }
        local_58 = FUN_00446f0f(match_count,card_idx);
        FUN_00446f81(match_count,card_idx,&local_5c,local_104 + 0x11,&local_118);
        FUN_0042458c(&local_bc,&local_54.left,local_58);
        target_idx = FUN_00447c74(match_count,card_idx);
        val_5 = FUN_00447cf8(match_count,card_idx);
        local_198 = (uint32_t)(val_5 == 0);
        local_40 = FUN_004470a6(match_count,card_idx);
        FUN_00424114(&local_38,&local_54.left);
        local_11c = FUN_00448191(match_count,card_idx);
        FUN_00426824(&local_28,&local_54.left);
        local_a4 = FUN_00448374(match_count,card_idx);
        if ((((local_11c & 1) == 0) || ((local_11c & 2) == 0)) ||
           (pt_00.y = local_110, pt_00.x = local_114, BVar8 = PtInRect(&local_28,pt_00), BVar8 == 0)
           ) {
          if (local_44 == -1) {
            if ((local_40 < 1) ||
               (pt_01.y = local_110, pt_01.x = local_114, BVar8 = PtInRect(&local_38,pt_01),
               BVar8 == 0)) {
              if ((local_58 < 1) ||
                 (pt_02.y = local_110, pt_02.x = local_114, BVar8 = PtInRect(&local_bc,pt_02),
                 BVar8 == 0)) {
                if ((((int)(local_104[0x11] + local_118 + local_5c) < 1) ||
                    ((int)local_110 <= (local_54.bottom * 0x23) / 100)) ||
                   ((local_54.bottom * 0x3e) / 100 <= (int)local_110)) {
                  val_5 = FUN_00447a88(match_count,card_idx);
                  if ((val_5 == match_count) || ((local_54.bottom * 0xc) / 100 <= (int)local_110)) {
                    if (((target_idx == 0) && (local_198 == 0)) ||
                       (((((int)local_114 <= (local_54.right * 5) / 100 ||
                          ((local_54.right * 0x5f) / 100 <= (int)local_114)) ||
                         ((int)local_110 <= (local_54.bottom * 0xf) / 100)) ||
                        ((local_54.bottom * 0x5f) / 100 <= (int)local_110)))) {
                      if (((local_a4 == 2) && ((local_54.right * 5) / 100 < (int)local_114)) &&
                         (((int)local_114 < (local_54.right * 0x5f) / 100 &&
                          (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                           ((int)local_110 < (local_54.bottom * 0x5f) / 100)))))) {
                        Mem_AllocOrFree_004d9630(local_180,(uint32_t *)s_Dying_004fa60c);
                        local_10c = 1;
                      }
                      else {
                        uval_6 = FUN_00447604(match_count,card_idx);
                        if ((((uval_6 & 2) != 0) &&
                            (((uval_6 = FUN_004472ad(match_count,card_idx), (uval_6 & 1) != 0 &&
                              ((local_54.right * 5) / 100 < (int)local_114)) &&
                             ((int)local_114 < (local_54.right * 0x5f) / 100)))) &&
                           (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                            ((int)local_110 < (local_54.bottom * 0x5f) / 100)))) {
                          Mem_AllocOrFree_004d9630(local_180,(uint32_t *)s_Summoning_sickness_004fa614);
                          local_10c = 1;
                        }
                      }
                    }
                    else {
                      local_180[0]._0_1_ = '\0';
                      if (target_idx != 0) {
                        Str_CopyFast(local_180,(uint32_t *)s_Is_a_target_004fa5e8);
                      }
                      if ((target_idx != 0) && (local_198 != 0)) {
                        Str_CopyFast(local_180,(uint32_t *)&DAT_004fa5f4);
                      }
                      if (local_198 != 0) {
                        Str_CopyFast(local_180,(uint32_t *)s_Can_t_target_this_004fa5f8);
                      }
                      local_10c = 1;
                    }
                  }
                  else {
                    Mem_AllocOrFree_004d9630
                              (local_180,(uint32_t *)s_Card_is_not_controlled_by_owner_004fa5c8);
                    local_10c = 1;
                  }
                }
                else {
                  local_a8 = (local_54.right - local_54.left) / 3;
                  if ((int)local_114 < local_54.left + local_a8) {
                    FUN_004860aa((char *)local_180,1,local_118);
                  }
                  else if ((int)local_114 < local_a8 * 2 + local_54.left) {
                    FUN_004860aa((char *)local_180,2,local_104[0x11]);
                  }
                  else {
                    FUN_004860aa((char *)local_180,3,local_5c);
                  }
                  local_10c = 1;
                }
              }
              else {
                FUN_00485d15((char *)local_180,local_3c,local_58);
                local_10c = 1;
              }
            }
            else {
              _sprintf((char *)local_180,s_Damage___d_004fa5bc,local_40);
              local_10c = 1;
            }
          }
          else {
            Mem_AllocOrFree_004d9630(local_180,(uint32_t *)local_a0[local_44]);
            local_10c = 1;
          }
        }
        else {
          Mem_AllocOrFree_004d9630(local_180,(uint32_t *)s_This_card_will_untap_004fa5a4);
          local_10c = 1;
        }
      }
      else {
        local_10c = 1;
        Mem_AllocOrFree_004d9630(local_180,(uint32_t *)s_Damage_to_player_004fa590);
      }
      if (local_10c != 0) {
        Mem_AllocOrFree_004d9630((uint32_t *)wParam,local_180);
      }
      if (DAT_00663e24 == 2) {
        return local_10c;
      }
      SendMessageA(hwnd,0x111,0x6e,0);
      return local_10c;
    }
  }
  LVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar9;
}



