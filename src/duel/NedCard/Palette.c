/*
 * NedCard/Palette.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 65
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Palette_AllocErrorDiffusionTable
 * Entry Point: 00435cb5
 * Size: 441 bytes
 */


int32_t Palette_AllocErrorDiffusionTable(int arg1,int arg2)

{
  int val_1;
  int val_2;
  void *buf_ptr_3;
  int player_idx;
  int card_idx;
  
  val_1 = *(int *)(&DAT_004f4680 + arg1 * 4);
  for (card_idx = 0; card_idx < *(int *)(&DAT_004f4630 + arg1 * 4); card_idx = card_idx + 1) {
    val_2 = *(int *)(&DAT_004f46a8 + card_idx * 0x10 + arg1 * 0xc0);
    if (*(int *)(arg2 + val_2 * 4) == 0) {
      buf_ptr_3 = _malloc(0x800);
      *(void **)(arg2 + val_2 * 4) = buf_ptr_3;
      if (*(int *)(arg2 + val_2 * 4) == 0) {
        __assert((uint32_t *)s_deltas_EVal_____NULL_004f5488,
                 (uint32_t *)s_D__Newmagic_sources_NedCard_Pale_004f5460,0x4fd);
      }
      for (player_idx = -0x100; player_idx < 0x100; player_idx = player_idx + 1) {
        *(int *)(*(int *)(arg2 + val_2 * 4) + 0x400 + player_idx * 4) =
             ((val_2 * player_idx + (val_1 >> 1)) * 0x100) / *(int *)(&DAT_004f4680 + arg1 * 4);
      }
      *(int *)(&DAT_004f46b4 + card_idx * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + val_2 * 4) + 0x3fc;
    }
    else {
      *(int *)(&DAT_004f46b4 + card_idx * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + val_2 * 4) + 0x400;
    }
  }
  for (card_idx = 0; card_idx < *(int *)(&DAT_004f4630 + arg1 * 4); card_idx = card_idx + 1) {
    *(int *)(&DAT_004f4d74 + card_idx * 0x10 + arg1 * 0xc0) =
         *(int *)(arg2 + *(int *)(&DAT_004f4d68 + card_idx * 0x10 + arg1 * 0xc0) * 4) + 0x3fc;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00435e6e
 * Entry Point: 00435e6e
 * Size: 1061 bytes
 */


int32_t FUN_00435e6e(int player_id,uint8_t *arg_2,int event_type,int arg_4,int arg_5)

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
  uint8_t *color_idx;
  int target_idx;
  int card_idx;
  
  ptr_1 = arg_2;
  arg_3_00 = arg_3 * 3;
  ptr_1_00 = _malloc((arg_3_00 + arg_5) * arg_4 + 0x10);
  if (DAT_005162b8 == 0) {
    for (card_idx = -0x200; card_idx < 0x200; card_idx = card_idx + 1) {
      if ((card_idx < 0) || (0xff < card_idx)) {
        if (card_idx < 0) {
          PTR_DAT_004f5428[card_idx] = 0;
        }
        else {
          PTR_DAT_004f5428[card_idx] = 0xff;
        }
      }
      else {
        PTR_DAT_004f5428[card_idx] = (uint8_t)card_idx;
      }
    }
    DAT_005162b8 = 1;
  }
  FID_conflict__memcpy(ptr_1_00,arg_2,arg_3_00);
  arg_2 = arg_2 + arg_3_00 + arg_5;
  color_idx = (uint8_t *)((int)ptr_1_00 + arg_3_00 + arg_5);
  for (target_idx = 1; target_idx < arg_4 + -1; target_idx = target_idx + 1) {
    *color_idx = *arg_2;
    color_idx[1] = arg_2[1];
    color_idx[2] = arg_2[2];
    pbVar19 = arg_2;
    pbVar20 = color_idx;
    for (card_idx = 1; color_idx = pbVar20 + 3, arg_2 = pbVar19 + 3, card_idx < arg_3 + -1;
        card_idx = card_idx + 1) {
      flag_1 = arg_2[(arg_3 * -3 - arg_5) + -2];
      flag_2 = arg_2[(arg_3 * -3 - arg_5) + 1];
      flag_3 = arg_2[(arg_3 * -3 - arg_5) + 4];
      bVar4 = pbVar19[1];
      bVar5 = pbVar19[4];
      bVar6 = pbVar19[7];
      bVar7 = arg_2[arg_5 + arg_3_00 + -2];
      bVar8 = arg_2[arg_5 + arg_3_00 + 1];
      bVar9 = arg_2[arg_5 + arg_3_00 + 4];
      bVar10 = arg_2[(arg_3 * -3 - arg_5) + -1];
      bVar11 = arg_2[(arg_3 * -3 - arg_5) + 2];
      bVar12 = arg_2[(arg_3 * -3 - arg_5) + 5];
      bVar13 = pbVar19[2];
      bVar14 = pbVar19[5];
      bVar15 = pbVar19[8];
      bVar16 = arg_2[arg_5 + arg_3_00 + -1];
      bVar17 = arg_2[arg_5 + arg_3_00 + 2];
      bVar18 = arg_2[arg_5 + arg_3_00 + 5];
      *color_idx = PTR_DAT_004f5428
                  [(int)(((((((uint32_t)arg_2[arg_3 * -3 - arg_5] * -2 -
                             (uint32_t)arg_2[(arg_3 * -3 - arg_5) + -3]) -
                            (uint32_t)arg_2[(arg_3 * -3 - arg_5) + 3]) + (uint32_t)*pbVar19 * -2 +
                            (uint32_t)*arg_2 * arg_1 + (uint32_t)pbVar19[6] * -2) -
                          (uint32_t)arg_2[arg_5 + arg_3_00 + -3]) + (uint32_t)arg_2[arg_5 + arg_3_00] * -2)
                        - (uint32_t)arg_2[arg_5 + arg_3_00 + 3]) / (arg_1 + -0xc)];
      pbVar20[4] = PTR_DAT_004f5428
                   [(int)(((((((uint32_t)flag_2 * -2 - (uint32_t)flag_1) - (uint32_t)flag_3) + (uint32_t)bVar4 * -2 +
                             (uint32_t)bVar5 * arg_1 + (uint32_t)bVar6 * -2) - (uint32_t)bVar7) +
                          (uint32_t)bVar8 * -2) - (uint32_t)bVar9) / (arg_1 + -0xc)];
      pbVar20[5] = PTR_DAT_004f5428
                   [(int)(((((((uint32_t)bVar11 * -2 - (uint32_t)bVar10) - (uint32_t)bVar12) + (uint32_t)bVar13 * -2
                             + (uint32_t)bVar14 * arg_1 + (uint32_t)bVar15 * -2) - (uint32_t)bVar16) +
                          (uint32_t)bVar17 * -2) - (uint32_t)bVar18) / (arg_1 + -0xc)];
      pbVar19 = arg_2;
      pbVar20 = color_idx;
    }
    *color_idx = *arg_2;
    pbVar20[4] = pbVar19[4];
    pbVar20[5] = pbVar19[5];
    arg_2 = pbVar19 + arg_5 + 6;
    color_idx = pbVar20 + arg_5 + 6;
  }
  FID_conflict__memcpy(color_idx,arg_2,arg_3_00);
  FID_conflict__memcpy(ptr_1,ptr_1_00,(arg_3_00 + arg_5) * arg_4);
  FUN_004db150(ptr_1_00);
  return 0;
}



/*
 * Decompiled function: FUN_00436293
 * Entry Point: 00436293
 * Size: 1345 bytes
 */


int32_t FUN_00436293(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  uint8_t flag_1;
  int val_2;
  uint32_t uval_3;
  int val_4;
  uint32_t uval_5;
  short *psVar6;
  int local_88;
  uint32_t local_84;
  int local_80;
  uint8_t *local_7c;
  int local_70 [6];
  int local_58;
  int16_t local_54;
  int16_t local_52;
  int16_t local_50;
  int16_t local_4e;
  uint32_t local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint32_t local_38;
  int local_34;
  uint8_t *local_30;
  int32_t local_2c;
  uint32_t local_28;
  int16_t local_24;
  int16_t local_22;
  int16_t loop_idx;
  int16_t local_1e;
  int color_idx;
  uint32_t target_idx;
  int16_t player_idx;
  int16_t local_12;
  int16_t card_idx;
  int16_t local_e;
  int match_count;
  uint32_t slot_idx;
  
  player_idx = 0;
  local_12 = 0;
  card_idx = 0;
  local_e = 0;
  local_54 = 0;
  local_52 = 0;
  local_50 = 0;
  local_4e = 0;
  local_24 = 0xffff;
  local_22 = 0xffff;
  loop_idx = 0xffff;
  local_1e = 0;
  local_3c = 1;
  local_2c = 0;
  local_7c = &DAT_004f46a8 + arg_1 * 0xc0;
  target_idx = arg_5 * 8 + 0x50U >> 2;
  if (DAT_005166dc == 0) {
    for (local_4c = -0x200; (int)local_4c < 0x200; local_4c = local_4c + 1) {
      if (((int)local_4c < 0) || (0xff < (int)local_4c)) {
        if ((int)local_4c < 0) {
          PTR_DAT_004f5428[local_4c] = 0;
        }
        else {
          PTR_DAT_004f5428[local_4c] = 0xff;
        }
      }
      else {
        PTR_DAT_004f5428[local_4c] = (uint8_t)local_4c;
      }
    }
    DAT_005166dc = 1;
  }
  if (arg_1 != DAT_004f5430) {
    for (local_4c = 0; local_4c < 0x41; local_4c = local_4c + 1) {
      if (*(int *)(&DAT_006c0560 + local_4c * 4) != 0) {
        FUN_004db150(*(int32_t *)(&DAT_006c0560 + local_4c * 4));
        *(int32_t *)(&DAT_006c0560 + local_4c * 4) = 0;
      }
    }
    Palette_AllocErrorDiffusionTable(arg_1,0x6c0560);
    DAT_004f5430 = arg_1;
  }
  for (local_4c = 0; local_4c < 5; local_4c = local_4c + 1) {
    _memset(&DAT_00695f50 + local_4c * 0x8060,0,0x8060);
    local_70[local_4c + 1] = local_4c * 0x8060 + 0x695f78;
  }
  val_2 = *(int *)(&DAT_004f4630 + arg_1 * 4);
  for (local_58 = 0; local_58 < arg_4; local_58 = local_58 + 1) {
    if (local_3c < 1) {
      local_80 = arg_5 + -1;
      color_idx = -1;
      local_88 = -3;
    }
    else {
      local_80 = 0;
      color_idx = arg_5;
      local_88 = 3;
    }
    match_count = local_80 * 3;
    for (local_4c = local_80; local_4c != color_idx; local_4c = local_4c + local_3c) {
      uval_3 = *(uint32_t *)(match_count + arg_3);
      uval_5 = uval_3 & 0xffffff;
      *(uint32_t *)(match_count + arg_3) = *(uint32_t *)(match_count + arg_3) & 0xff000000;
      psVar6 = (short *)(local_70[1] + local_4c * 8);
      slot_idx = (uint32_t)(uint8_t)PTR_DAT_004f5428[(uval_3 & 0xff) + ((int)*psVar6 >> 8)];
      local_38 = (uint32_t)(uint8_t)PTR_DAT_004f5428[(uval_5 >> 8 & 0xff) + ((int)psVar6[1] >> 8)];
      flag_1 = PTR_DAT_004f5428[(uval_5 >> 0x10) + ((int)psVar6[2] >> 8)];
      local_28 = (uint32_t)flag_1 << 0x10 |
                 (uint32_t)(uint8_t)PTR_DAT_004f5428[(uval_5 >> 8 & 0xff) + ((int)psVar6[1] >> 8)] << 8 |
                 (uint32_t)(uint8_t)PTR_DAT_004f5428[(uval_3 & 0xff) + ((int)*psVar6 >> 8)];
      if (local_28 == 0) {
        local_84 = 0;
      }
      else if (local_28 == 0xffffff) {
        local_84 = 0xffffff;
      }
      else {
        local_84 = Mem_AllocOrFree_00436800(local_28);
      }
      *(uint32_t *)(match_count + arg_3) = *(uint32_t *)(match_count + arg_3) | local_84;
      local_40 = slot_idx - (local_84 & 0xff);
      local_34 = local_38 - (local_84 >> 8 & 0xff);
      local_30 = local_7c;
      for (local_70[0] = 0; local_70[0] < val_2; local_70[0] = local_70[0] + 1) {
        local_44 = *(int *)(local_30 + 4);
        local_48 = *(int *)(local_30 + 8);
        val_4 = *(int *)(local_30 + 0xc);
        psVar6 = (short *)((*(int *)(local_30 + 4) + local_4c) * 8 +
                          local_70[*(int *)(local_30 + 8) + 1]);
        *psVar6 = (short)*(int32_t *)(val_4 + local_40 * 4) + *psVar6;
        psVar6[1] = (short)*(int32_t *)(val_4 + local_34 * 4) + psVar6[1];
        psVar6[2] = (short)*(int32_t *)(val_4 + ((uint32_t)flag_1 - (local_84 >> 0x10 & 0xff)) * 4) +
                    psVar6[2];
        local_30 = local_30 + 0x10;
      }
      match_count = match_count + local_88;
    }
    FUN_00435c74(local_70 + 1,*(int *)(&DAT_004f4658 + arg_1 * 4));
    _memset((void *)(local_70[*(int *)(&DAT_004f4658 + arg_1 * 4)] + -0x28),0,target_idx << 2);
    if (arg_2 != 0) {
      local_3c = -local_3c;
      local_7c = &DAT_004f46a8 + (uint32_t)(local_3c == -1) * 0x6c0 + arg_1 * 0xc0;
    }
    arg_3 = arg_3 + arg_5 * 3 + arg_6;
  }
  return 1;
}



/*
 * Decompiled function: Mem_AllocOrFree_004367d4
 * Entry Point: 004367d4
 * Size: 35 bytes
 */


void Mem_AllocOrFree_004367d4(void)

{
  FUN_00434fa1(DAT_005162b4);
  DAT_005162b4 = (int *)0x0;
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00436800
 * Entry Point: 00436800
 * Size: 24 bytes
 */


uint32_t Mem_AllocOrFree_00436800(uint32_t arg_1)

{
  return arg_1 & 0xf8f8f8;
}



/*
 * Decompiled function: UI_Register_FACE_BLACK_00436820
 * Entry Point: 00436820
 * Size: 562 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t UI_Register_FACE_BLACK_00436820(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  uint32_t local_138 [66];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Ai_CalcManaRequirement_004b9284;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00516700 = CreatePopupMenu();
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__FACE_MULTI_pic_004f69d8);
  _DAT_00516708 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__FACE_BLACK_pic_004f69e8);
  _DAT_0051670c = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__FACE_BLUE_pic_004f69f8);
  _DAT_00516710 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__FACE_GREEN_pic_004f6a08);
  _DAT_00516714 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__FACE_RED_pic_004f6a18);
  _DAT_00516718 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__FACE_WHITE_pic_004f6a28);
  _DAT_0051671c = Pic_LoadKimPicture((char *)local_138);
  lplf = (LOGFONTA *)FUN_00472731(&DAT_004f6a38,0);
  DAT_00516704 = CreateFontIndirectA(lplf);
  DAT_005166e8 = 0x2f6f7f7;
  DAT_005166ec = 0x2565656;
  return local_30;
}



/*
 * Decompiled function: FUN_00436a52
 * Entry Point: 00436a52
 * Size: 164 bytes
 */


void FUN_00436a52(void)

{
  int slot_idx;
  
  if (DAT_00516700 != (HMENU)0x0) {
    DestroyMenu(DAT_00516700);
  }
  DAT_00516700 = (HMENU)0x0;
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    if (*(int *)(&DAT_00516708 + slot_idx * 4) != 0) {
      FUN_00471395(*(HANDLE *)(&DAT_00516708 + slot_idx * 4));
      *(int32_t *)(&DAT_00516708 + slot_idx * 4) = 0;
    }
  }
  if (DAT_00516704 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00516704);
  }
  DAT_00516704 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: Ai_CalcManaRequirement_004b9284
 * Entry Point: 00436af6
 * Size: 1760 bytes
 */


LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam)

{
  LONG LVar1;
  uint32_t uval_2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int val_3;
  LRESULT LVar4;
  int local_278;
  uint32_t local_274 [25];
  uint32_t local_210;
  char local_20c [100];
  tagPOINT local_1a8;
  tagRECT local_1a0;
  HDC local_190;
  tagPAINTSTRUCT local_18c;
  tagRECT local_14c;
  tagMSG local_13c;
  uint32_t local_120;
  uint32_t local_11c [66];
  ULONG_PTR player_idx;
  uint32_t card_idx;
  HANDLE match_count;
  uint32_t slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      match_count = (HANDLE)GetWindowLongA(hwnd,0);
      local_190 = BeginPaint(hwnd,&local_18c);
      if (local_190 != (HDC)0x0) {
        FUN_004707a4(local_190);
        GetClientRect(hwnd,&local_14c);
        if (match_count == (HANDLE)0x0) {
          hbr = GetStockObject(4);
          FillRect(local_190,&local_14c,hbr);
        }
        else {
          FUN_004371ec(local_190,&local_14c,(uint32_t)(hwnd != DAT_00601550));
        }
        EndPaint(hwnd,&local_18c);
      }
      return 0;
    }
    if (uMsg == 1) {
      match_count = (HANDLE)0x0;
      SetWindowLongA(hwnd,0,0);
      slot_idx = 0;
      SetWindowLongA(hwnd,4,0);
      return 0;
    }
    if (uMsg == 2) {
      match_count = (HANDLE)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      if ((match_count != (HANDLE)0x0) && (slot_idx == 0)) {
        FUN_00471395(match_count);
      }
      return 0;
    }
  }
  else if (uMsg < 0x112) {
    if (uMsg == 0x111) {
      uval_2 = wParam & 0xffff;
      if (uval_2 == 100) {
        FUN_0043753a((uint32_t)(hwnd != DAT_00601550),0);
      }
      else if (uval_2 == 0x65) {
        player_idx = 0xbdf;
        Mem_AllocOrFree_004d9630(local_11c,(uint32_t *)&DAT_005f76e0);
        FUN_004d9640(local_11c,(uint32_t *)s__duel_hlp_004f6a40);
        WinHelpA(DAT_00618990,(LPCSTR)local_11c,1,player_idx);
      }
      else if (uval_2 == 0x66) {
        card_idx = (uint32_t)(hwnd != DAT_00601550);
        DAT_0066643c = 0;
        FUN_00437681(card_idx);
      }
      return 0;
    }
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_00471df6(hwnd,0x20,wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_278 = GetMenuItemCount(DAT_00516700);
        while (local_278 != 0) {
          DeleteMenu(DAT_00516700,0,0x400);
          local_278 = local_278 + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      local_210 = (uint32_t)(DAT_00618160 != hwnd);
      if ((DAT_00618158 != 0) && (val_3 = FUN_004376c0(local_210), val_3 != 0)) {
        if (local_210 == 1) {
          FUN_00448412(local_20c);
          _sprintf((char *)local_274,s_Target__s_004f6a4c,local_20c);
        }
        else {
          Mem_AllocOrFree_004d9630(local_274,(uint32_t *)s_Target_yourself_004f6a58);
        }
        AppendMenuA(DAT_00516700,0,0x66,(LPCSTR)local_274);
      }
      val_3 = GetMenuItemCount(DAT_00516700);
      if (0 < val_3) {
        AppendMenuA(DAT_00516700,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00516700,0,100,s_Flip_back_to_lifepoints_004f6a68);
      AppendMenuA(DAT_00516700,0,0x65,s_Help____004f6a80);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_1a8.x = lParam & 0xffff;
      local_1a8.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_1a8);
      SetRect(&local_1a0,local_1a8.x,local_1a8.y,local_1a8.x + 1,local_1a8.y + 1);
      TrackPopupMenu(DAT_00516700,2,local_1a8.x,local_1a8.y,0,hwnd,&local_1a0);
      return 0;
    }
    if (uMsg == 0x201) {
      local_120 = (uint32_t)(hwnd != DAT_00601550);
      if (DAT_00618158 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        DAT_0066643c = PeekMessageA(&local_13c,hwnd,0x203,0x203,0);
        FUN_00437681(local_120);
      }
      return 0;
    }
  }
  else if (uMsg < 0x439) {
    if (uMsg == 0x438) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      LVar4 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg == 0x439) {
    match_count = (HANDLE)GetWindowLongA(hwnd,0);
    slot_idx = GetWindowLongA(hwnd,4);
    if ((match_count != (HANDLE)0x0) && (slot_idx == 0)) {
      FUN_00471395(match_count);
    }
    match_count = (HANDLE)wParam;
    slot_idx = lParam;
    SetWindowLongA(hwnd,0,wParam);
    SetWindowLongA(hwnd,4,slot_idx);
    InvalidateRect(hwnd,(RECT *)0x0,0);
    return 0;
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: FUN_004371ec
 * Entry Point: 004371ec
 * Size: 846 bytes
 */


void FUN_004371ec(HDC hdc,RECT *arg_2,int event_type)

{
  HBRUSH hbr;
  char *char_ptr_1;
  size_t len_2;
  uint8_t local_7c [4];
  int local_78;
  int local_74;
  int local_64;
  tagRECT local_60;
  HANDLE local_50;
  tagPOINT local_4c;
  int local_44;
  HANDLE local_40;
  uint32_t local_3c [13];
  HWND slot_idx;
  
  if (arg_3 == 0) {
    slot_idx = DAT_00601550;
  }
  else {
    slot_idx = DAT_00617438;
  }
  local_40 = (HANDLE)GetWindowLongA(slot_idx,0);
  if (arg_3 == 0) {
    local_50 = *(HANDLE *)(&DAT_00516708 + DAT_006169f0 * 4);
  }
  else {
    local_50 = *(HANDLE *)(&DAT_00516708 + DAT_00663e6c * 4);
  }
  if (local_50 == (HANDLE)0x0) {
    hbr = GetStockObject(4);
    FillRect(hdc,arg_2,hbr);
  }
  else {
    FUN_004709ae((int)hdc,(int)arg_2,local_50);
  }
  if (local_40 != (HANDLE)0x0) {
    GetObjectA(local_40,0x18,local_7c);
    local_78 = local_78 / 2;
    local_64 = SaveDC(hdc);
    SetMapMode(hdc,7);
    SetWindowOrgEx(hdc,local_78 / 2,local_74 / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,arg_2->left + (arg_2->right - arg_2->left) / 2,
                     arg_2->top + (arg_2->bottom - arg_2->top) / 2,(LPPOINT)0x0);
    SetWindowExtEx(hdc,local_78,local_74,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SetRect(&local_60,0,0,local_78,local_74);
    FUN_00470c78(hdc,&local_60,local_40);
    RestoreDC(hdc,local_64);
  }
  if (arg_3 == 1) {
    FUN_00448412((char *)local_3c);
  }
  else {
    Mem_AllocOrFree_004d9630(local_3c,(uint32_t *)&DAT_006015b0);
    char_ptr_1 = _strchr((char *)local_3c,0x2d);
    if (char_ptr_1 != (char *)0x0) {
      char_ptr_1 = _strchr((char *)local_3c,0x2d);
      *char_ptr_1 = '\0';
    }
  }
  len_2 = _strlen((char *)local_3c);
  if (len_2 != 0) {
    local_44 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,arg_2->right - arg_2->left,100,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SelectObject(hdc,DAT_00516704);
    SetBkMode(hdc,1);
    SetTextAlign(hdc,0xe);
    local_4c.x = arg_2->left + (arg_2->right - arg_2->left) / 2;
    local_4c.y = arg_2->bottom;
    DPtoLP(hdc,&local_4c,1);
    SetTextColor(hdc,DAT_005166ec);
    len_2 = _strlen((char *)local_3c);
    TextOutA(hdc,local_4c.x + 1,local_4c.y + 1,(LPCSTR)local_3c,len_2);
    SetTextColor(hdc,DAT_005166e8);
    len_2 = _strlen((char *)local_3c);
    TextOutA(hdc,local_4c.x,local_4c.y,(LPCSTR)local_3c,len_2);
    RestoreDC(hdc,local_44);
  }
  return;
}



/*
 * Decompiled function: FUN_0043753a
 * Entry Point: 0043753a
 * Size: 327 bytes
 */


void FUN_0043753a(int arg1,int arg2)

{
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  HWND hWnd_02;
  int32_t match_count;
  
  if (arg1 == 0) {
    match_count = DAT_00618950;
    hWnd = DAT_00618978;
    hWnd_00 = DAT_00663e68;
    hWnd_01 = DAT_00618160;
    hWnd_02 = DAT_00601550;
  }
  else {
    match_count = DAT_00664c34;
    hWnd = DAT_0061737c;
    hWnd_00 = DAT_00664c04;
    hWnd_01 = DAT_00664c28;
    hWnd_02 = DAT_00617438;
  }
  if (arg2 == 0) {
    ShowWindow(hWnd_01,5);
    ShowWindow(hWnd_00,5);
    ShowWindow(hWnd,5);
    ShowWindow(match_count,5);
    ShowWindow(hWnd_02,0);
  }
  else {
    ShowWindow(hWnd_02,5);
    BringWindowToTop(hWnd_02);
    ShowWindow(hWnd_01,0);
    if (DAT_00663e24 != 2) {
      ShowWindow(hWnd_00,0);
      ShowWindow(hWnd,0);
      ShowWindow(match_count,0);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00437681
 * Entry Point: 00437681
 * Size: 63 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00437681(int32_t arg_1)

{
  _DAT_005166f0 = 0;
  _DAT_005166f4 = arg_1;
  _DAT_005166f8 = 0xffffffff;
  PostMessageA(DAT_00618990,0x464,0,0x5166f0);
  return;
}



/*
 * Decompiled function: FUN_004376c0
 * Entry Point: 004376c0
 * Size: 74 bytes
 */


int32_t FUN_004376c0(int player_id)

{
  int32_t uval_1;
  
  if (((arg_1 == 1) && (DAT_00664860 != 0)) || ((arg_1 == 0 && (DAT_00664864 != 0)))) {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Palette_Color_00495430
 * Entry Point: 00437710
 * Size: 1013 bytes
 */


int32_t Palette_Color_00495430(char *filepath)

{
  size_t len_1;
  int val_2;
  int val_3;
  int32_t *arg_3;
  BITMAPINFO *arg_4;
  int32_t *arg_5;
  char *pcVar4;
  int32_t *arg_6;
  uint32_t *puVar5;
  int *arg_7;
  uint32_t local_118 [66];
  int32_t card_idx;
  HDC match_count;
  int slot_idx;
  
  card_idx = 1;
  FUN_0047076e(&DAT_005f76e0);
  __chdir(&DAT_005f76e0);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00664a60,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640((uint32_t *)&DAT_00664a60,(uint32_t *)s__PlayDeck_004f6a98);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00617470,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640((uint32_t *)&DAT_00617470,(uint32_t *)s__Faces_004f6aa4);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f7800,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640((uint32_t *)&DAT_005f7800,(uint32_t *)s__CardArt_004f6aac);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_006189a0,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640((uint32_t *)&DAT_006189a0,(uint32_t *)s__DuelArt_004f6ab8);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_0060d4a0,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640((uint32_t *)&DAT_0060d4a0,(uint32_t *)s__DuelSounds_004f6ac4);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00664c40,(uint32_t *)&DAT_006189a0);
  FUN_004d9640((uint32_t *)&DAT_00664c40,(uint32_t *)s__Duel_dat_004f6ad0);
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00615350,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640((uint32_t *)&DAT_00615350,(uint32_t *)s__SaveGame_004f6adc);
  FID_conflict___mkdir(&DAT_00615350);
  Mem_AllocOrFree_004d9630(local_118,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint32_t *)s__CARDS_DAT_004f6ae8);
  DAT_0061743c = Ai_CalcManaRequirement_004b9284((char *)local_118);
  if (DAT_0061743c == 0) {
    card_idx = 0;
    puVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_card_data_file_004f6af4;
    len_1 = _strlen(str_1);
    _sprintf(str_1 + len_1,pcVar4,puVar5);
  }
  Mem_AllocOrFree_004d9630(local_118,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint32_t *)s__LEGACY_CSV_004f6b1c);
  val_2 = FUN_0043ce77((LPCSTR)local_118);
  if (val_2 == 0) {
    card_idx = 0;
    puVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_special_card_d_004f6b28;
    len_1 = _strlen(str_1);
    _sprintf(str_1 + len_1,pcVar4,puVar5);
  }
  FUN_004b8bf0();
  match_count = GetDC((HWND)0x0);
  if (match_count == (HDC)0x0) {
    card_idx = 0;
    FUN_004d9640((uint32_t *)str_1,(uint32_t *)s_Not_enough_system_resources_to_d_004f6b88);
  }
  else {
    val_2 = GetDeviceCaps(match_count,0xc);
    val_3 = GetDeviceCaps(match_count,0xe);
    DAT_00664c30 = val_2 * val_3;
    ReleaseDC((HWND)0x0,match_count);
  }
  val_2 = FUN_00471426();
  if (val_2 == 0) {
    card_idx = 0;
    FUN_004d9640((uint32_t *)str_1,(uint32_t *)s_Couldn_t_create_the_palette_004f6bc8);
  }
  arg_7 = &DAT_0061897c;
  arg_6 = (int32_t *)&DAT_00664db0;
  arg_5 = &DAT_00664c00;
  arg_4 = (BITMAPINFO *)&DAT_00617440;
  arg_3 = &DAT_0060157c;
  val_2 = GetSystemMetrics(1);
  val_3 = GetSystemMetrics(0);
  val_2 = FUN_004707f3(val_3,val_2,arg_3,arg_4,arg_5,arg_6,arg_7);
  if (val_2 == 0) {
    card_idx = 0;
    FUN_004d9640((uint32_t *)str_1,(uint32_t *)s_Couldn_t_create_the_app_wide_mem_004f6be8);
  }
  val_2 = Palette_Color_0049ae00();
  if (val_2 == 0) {
    card_idx = 0;
    FUN_004d9640((uint32_t *)str_1,(uint32_t *)s_Couldn_t_initialize_for_card_dra_004f6c1c);
  }
  val_2 = FUN_004706d0();
  if (val_2 == 0) {
    card_idx = 0;
    FUN_004d9640((uint32_t *)str_1,(uint32_t *)s_Couldn_t_initialize_for_utility_d_004f6c44);
  }
  for (slot_idx = 0; slot_idx < 0x14; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00664870 + slot_idx * 0x18) = 0;
  }
  DAT_005f76d4 = 0;
  for (slot_idx = 0; slot_idx < 2000; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_0060d5b0 + slot_idx * 0x10) = 0;
  }
  for (slot_idx = 0; slot_idx < 100; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00616a10 + slot_idx * 0x18) = 0;
  }
  DAT_00663df8 = 0;
  Glue_Timer_004cd63b();
  return card_idx;
}



/*
 * Decompiled function: FUN_00437b05
 * Entry Point: 00437b05
 * Size: 135 bytes
 */


void FUN_00437b05(void)

{
  int32_t slot_idx;
  
  Mem_AllocOrFree_0043ce47();
  Mem_AllocOrFree_0043d0c9();
  FUN_00471717();
  FUN_0047097b(DAT_0060157c,DAT_00664c00);
  DAT_00664c00 = (HGDIOBJ)0x0;
  DAT_0060157c = (HDC)0x0;
  FUN_0047072d();
  Palette_Color_0049ae00();
  FUN_00486bc3();
  for (slot_idx = 0; slot_idx < DAT_0061743c; slot_idx = slot_idx + 1) {
    FUN_00438e72(slot_idx);
  }
  FUN_00439516();
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004958b1
 * Entry Point: 00437b8c
 * Size: 167 bytes
 */


int Palette_Subsystem_004958b1(int player_id)

{
  CHAR local_7d8 [2000];
  int slot_idx;
  
  DAT_00663dfc = 1;
  DAT_00617434 = arg_1;
  if (arg_1 == -1) {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00664b90,(uint32_t *)s_Opponent_004f6c70);
  }
  else {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00664b90,(uint32_t *)(&DAT_00507370 + arg_1 * 0x44));
  }
  slot_idx = Palette_Subsystem_00495958(local_7d8);
  if (slot_idx == -2) {
    MessageBoxA((HWND)0x0,local_7d8,s_Duel_couldn_t_run_004f6c7c,0x1030);
  }
  return slot_idx;
}



/*
 * Decompiled function: Palette_Subsystem_00495958
 * Entry Point: 00437c33
 * Size: 901 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Palette_Subsystem_00495958(uint8_t *arg_1)

{
  DWORD arg_1_00;
  HANDLE buf_ptr_1;
  int val_2;
  BOOL BVar3;
  int32_t uval_4;
  HWND hWndParent;
  HMENU hMenu;
  HINSTANCE hInstance;
  int val_5;
  LPVOID lpParam;
  DWORD local_60;
  tagMSG local_5c;
  int local_40;
  _AppBarData local_3c;
  int target_idx;
  WPARAM player_idx;
  UINT_PTR card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  arg_1_00 = GetTickCount();
  Mem_AllocOrFree_004d9830(arg_1_00);
  local_40 = 1;
  *arg_1 = 0;
  val_5 = 1;
  buf_ptr_1 = GetCurrentThread();
  SetThreadPriority(buf_ptr_1,val_5);
  local_3c.cbSize = 0x24;
  card_idx = SHAppBarMessage(4,&local_3c);
  match_count = card_idx & 1;
  slot_idx = card_idx & 2;
  OutputDebugStringA(s_Main__initializing_critical_sect_004f6c90);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
  DAT_00601618 = 0;
  DAT_0060cc60 = 0;
  DAT_0060cc70 = 1;
  DAT_005f77f0 = 0;
  DAT_0061815c = 0;
  DAT_00601580 = 0;
  _DAT_0060d494 = 0;
  Rules_ParseFilter_0048111e();
  DAT_00663e30 = LoadCursorA(DAT_00664680,s_Hand1_004f6cb8);
  DAT_00663e34 = LoadCursorA(DAT_00664680,s_SwordWait_004f6cc0);
  DAT_00663e60 = 3;
  _DAT_00663e38 = LoadCursorA(DAT_00664680,s_Hand2_004f6ccc);
  _DAT_00663e3c = LoadCursorA(DAT_00664680,s_Hand3_004f6cd4);
  _DAT_00663e40 = LoadCursorA(DAT_00664680,s_Hand4_004f6cdc);
  Palette_Subsystem_0049608e();
  OutputDebugStringA(s_Main__creating_windows_004f6ce4);
  local_60 = 0x82000000;
  if (1 < (int)DAT_00663dfc) {
    local_60 = 0x82040000;
  }
  if ((DAT_00663dfc & 1) == 0) {
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hWndParent = DAT_005f67ec;
    hInstance = DAT_00664680;
    val_5 = GetSystemMetrics(1);
    val_2 = GetSystemMetrics(0);
    DAT_00618990 = CreateWindowExA(0,s_MAGICGAME_MainClass_004f6d20,s_Magic_004f6d18,local_60,1,0,
                                   val_2 + -1,val_5,hWndParent,hMenu,hInstance,lpParam);
  }
  else {
    DAT_00618990 = CreateWindowExA(0,s_MAGICGAME_MainClass_004f6d04,s_Magic_004f6cfc,local_60,1,0,
                                   DAT_005071c8,DAT_005071cc,DAT_005f67ec,(HMENU)0x0,DAT_00664680,
                                   (LPVOID)0x0);
  }
  if (DAT_00618990 == (HWND)0x0) {
    local_40 = 0;
    FUN_004d9640((uint32_t *)arg_1,(uint32_t *)s_Couldn_t_create_the_main_window_004f6d34);
  }
  DAT_00664c2c = LoadAcceleratorsA(DAT_00664680,(LPCSTR)0x6f);
  if (((DAT_00663dfc & 4) != 0) || ((DAT_00663dfc & 2) != 0)) {
    Sound_Init((int)DAT_00618990,0,0);
  }
  FUN_0048d320();
  if (local_40 == 0) {
    uval_4 = 0xfffffffe;
  }
  else {
    Palette_Subsystem_004963e7();
    while( true ) {
      BVar3 = GetMessageA(&local_5c,(HWND)0x0,0,0);
      if (BVar3 == 0) break;
      FUN_00437fb8(&local_5c);
    }
    player_idx = local_5c.wParam;
    Palette_Subsystem_0049608e();
    if (DAT_00663e30 != (HCURSOR)0x0) {
      DestroyCursor(DAT_00663e30);
    }
    if (DAT_00663e34 != (HCURSOR)0x0) {
      DestroyCursor(DAT_00663e34);
    }
    for (target_idx = 0; target_idx < DAT_00663e60; target_idx = target_idx + 1) {
      if (*(int *)(&DAT_00663e38 + target_idx * 4) != 0) {
        DestroyCursor(*(HCURSOR *)(&DAT_00663e38 + target_idx * 4));
      }
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
    FUN_0048d3af();
    if (((DAT_00663dfc & 2) != 0) || ((DAT_00663dfc & 4) != 0)) {
      CloseSnd();
    }
    GdiFlush();
    val_5 = 0;
    buf_ptr_1 = GetCurrentThread();
    SetThreadPriority(buf_ptr_1,val_5);
    uval_4 = DAT_006679e0;
  }
  return uval_4;
}



/*
 * Decompiled function: FUN_00437fb8
 * Entry Point: 00437fb8
 * Size: 526 bytes
 */


void FUN_00437fb8(MSG *arg_1)

{
  int val_1;
  BOOL BVar2;
  LRESULT LVar3;
  uint32_t uval_4;
  WPARAM slot_idx;
  
  val_1 = TranslateAcceleratorA(DAT_00618990,DAT_00664c2c,arg_1);
  if ((val_1 == 0) && (val_1 = FUN_004381c6((int *)arg_1,0x4b), val_1 == 0)) {
    if (((DAT_00618158 == 0) ||
        (((BVar2 = IsWindowVisible(DAT_00664d90), BVar2 == 0 ||
          (LVar3 = SendMessageA(DAT_00664d90,0x402,0,0), LVar3 == 0)) || (arg_1->message != 0x102)))
        ) || (((arg_1->wParam != 0x20 && (arg_1->wParam != 0xd)) && (arg_1->wParam != 0x1b)))) {
      val_1 = FUN_00491ef3((int *)arg_1);
      if ((val_1 == 0) &&
         (((Mem_AllocOrFree_0043860c(arg_1->hwnd,arg_1->message,arg_1->wParam,arg_1->lParam),
           arg_1->message != 0x201 && (arg_1->message != 0x204)) || (DAT_00618158 != 0)))) {
        TranslateMessage(arg_1);
        DispatchMessageA(arg_1);
      }
    }
    else {
      uval_4 = SendMessageA(DAT_00664d90,0x402,0,0);
      slot_idx = 0xfffffc18;
      if (((uval_4 & 2) == 0) || ((uval_4 & 1) == 0)) {
        if ((arg_1->wParam == 0xd) || (arg_1->wParam == 0x20)) {
          slot_idx = 0;
        }
        else if ((arg_1->wParam == 0x1b) && ((uval_4 & 1) != 0)) {
          slot_idx = DAT_00601614;
        }
      }
      else if (arg_1->wParam == 0xd) {
        slot_idx = DAT_0060cc78;
      }
      else if (arg_1->wParam == 0x1b) {
        slot_idx = DAT_00601614;
      }
      if (slot_idx != 0xfffffc18) {
        SendMessageA(DAT_00664d90,0x401,slot_idx,0);
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004381c6
 * Entry Point: 004381c6
 * Size: 408 bytes
 */


int32_t FUN_004381c6(int *arg1,UINT arg2)

{
  BOOL BVar1;
  int val_2;
  int val_3;
  tagPOINT color_idx;
  tagRECT player_idx;
  
  val_2 = arg1[1];
  if (val_2 != 0xa0) {
    if (val_2 == 0x113) {
      if ((*arg1 == 0) && (arg1[2] == DAT_004f6a94)) {
        KillTimer((HWND)0x0,DAT_004f6a94);
        DAT_004f6a94 = 0;
        GetCursorPos(&color_idx);
        val_2 = GetSystemMetrics(0xd);
        color_idx.x = color_idx.x + val_2;
        val_2 = GetSystemMetrics(0xe);
        color_idx.y = color_idx.y + val_2;
        GetWindowRect(DAT_0060cc6c,&player_idx);
        val_3 = (player_idx.right - player_idx.left) + color_idx.x;
        val_2 = GetSystemMetrics(0);
        val_3 = val_3 - val_2;
        if (0 < val_3) {
          color_idx.x = color_idx.x - val_3;
        }
        val_3 = (player_idx.bottom - player_idx.top) + color_idx.y;
        val_2 = GetSystemMetrics(1);
        val_3 = val_3 - val_2;
        if (0 < val_3) {
          color_idx.y = color_idx.y - val_3;
        }
        SetWindowPos(DAT_0060cc6c,(HWND)0x0,color_idx.x,color_idx.y,0,0,5);
        return 1;
      }
      return 0;
    }
    if (val_2 != 0x200) {
      return 0;
    }
  }
  if (DAT_004f6a94 != 0) {
    KillTimer((HWND)0x0,DAT_004f6a94);
    DAT_004f6a94 = 0;
  }
  if ((DAT_00663e04 != 0) && (BVar1 = IsWindowVisible(DAT_0060cc6c), BVar1 != 0)) {
    DAT_004f6a94 = SetTimer((HWND)0x0,0,arg2,(TIMERPROC)0x0);
  }
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 00438368
 * Size: 418 bytes
 */


/* WARNING: Removing unreachable block (ram,0x004384f4) */

int32_t Palette_Subsystem_0049608e(void)

{
  Ordinal_17();
  UI_RegisterClass_004b3360(s_MAGICGAME_MainClass_004f6d58);
  UI_Register_sPoison_00499ba0(s_MAGICGAME_LifeClass_004f6d6c);
  UI_RegisterClass_0041a600(s_MAGICGAME_FullCardClass_004f6d80);
  Ai_CalcManaRequirement_004b9120(s_MAGICGAME_ManaSummaryClass_004f6d98);
  UI_RegisterClass_004b9460(s_MAGICGAME_HandClass_004f6db4);
  UI_BigCardDialogProc(s_MAGICGAME_ChatClass_004f6dc8);
  UI_RegisterClass_00467880(s_MAGICGAME_CardClass_004f6ddc);
  UI_LoadPhaseBackdrop(s_MAGICGAME_PhaseDisplayClass_004f6df0);
  UI_LoadPhaseCombatBackdrop(s_MAGICGAME_AttackPhaseDisplayClas_004f6e0c);
  Glue_Subsystem_004ecee0(s_MAGICGAME_TerritoryClass_004f6e30);
  UI_RegisterClass_00486c90(s_MAGICGAME_LibraryClass_004f6e4c);
  UI_RegisterExpandedGraveyardClass(s_MAGICGAME_GraveyardClass_004f6e64);
  UI_Register_WINBK_Attack_00493810(s_MAGICGAME_AttackClass_004f6e80);
  Glue_Subsystem_004cd760(s_MAGICGAME_SpellChainClass_004f6e98);
  UI_Register_FACE_BLACK_00436820(s_MAGICGAME_FaceClass_004f6eb4);
  UI_RegisterClass_0046f240(s_MAGICGAME_ScrollbarClass_004f6ec8);
  UI_RegisterClass_0042b2a0(s_MAGICTHEME_IconButtonClass_004f6ee4);
  UI_Register_WINBK_BigCard_0049036d(s_MAGICGAME_BigCardChoiceClass_004f6f00);
  UI_RegisterClass_00490196(s_MAGICGAME_BigCardCardClass_004f6f20);
  UI_RegisterClass_0044bd60(s_MAGIC_PaletteClass_004f6f3c);
  UI_RegisterClass_004917d0(s_MAGIC_CueCardClass_004f6f50);
  UI_RegisterClass_00433e40(s_MAGIC_PlayerDirectiveClass_004f6f64);
  Palette_Color_0049ae00(s_MAGIC_TellUserClass_004f6f80);
  return 1;
}



/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 0043850a
 * Size: 258 bytes
 */


void Palette_Subsystem_0049608e(void)

{
  FUN_00499c93(s_MAGICGAME_LifeClass_004f6f94);
  FUN_0041a698(s_MAGICGAME_FullCardClass_004f6fa8);
  FUN_0044a6ce(s_MAGICGAME_ManaSummaryClass_004f6fc0);
  FUN_004b9523(s_MAGICGAME_HandClass_004f6fdc);
  FUN_004010b7(s_MAGICGAME_ChatClass_004f6ff0);
  FUN_004821cf(s_MAGICGAME_CardClass_004f7004);
  FUN_0044cbf8(s_MAGICGAME_PhaseDisplayClass_004f7018);
  Mem_AllocOrFree_0044cd3f(s_MAGICGAME_AttackPhaseDisplayClas_004f7034);
  FUN_004afe04(s_MAGICGAME_TerritoryClass_004f7058);
  FUN_00486dc6(s_MAGICGAME_LibraryClass_004f7074);
  FUN_0043a531(s_MAGICGAME_GraveyardClass_004f708c);
  FUN_00493c0c(s_MAGICGAME_AttackClass_004f70a8);
  FUN_0049fac1(s_MAGICGAME_SpellChainClass_004f70c0);
  FUN_00436a52(s_MAGICGAME_FaceClass_004f70dc);
  FUN_0046f2f5(s_MAGICGAME_ScrollbarClass_004f70f0);
  Mem_AllocOrFree_00490448(s_MAGICGAME_BigCardChoiceClass_004f710c);
  Mem_AllocOrFree_00490228(s_MAGICGAME_BigCardCardClass_004f712c);
  FUN_004918f1(s_MAGIC_CueCardClass_004f7148);
  FUN_004b6eac(s_MAGIC_TellUserClass_004f715c);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043860c
 * Entry Point: 0043860c
 * Size: 37 bytes
 */


int32_t Mem_AllocOrFree_0043860c(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_00438636
 * Entry Point: 00438636
 * Size: 134 bytes
 */


int32_t FUN_00438636(HWND arg_1,uint32_t y,HWND arg_3,int32_t arg_4)

{
  int32_t uval_1;
  
  if (y == 0x30f) {
    uval_1 = FUN_00472b60(arg_1,0x30f,arg_3,arg_4);
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uval_1 = 0;
  }
  else {
    uval_1 = FUN_00472b60(arg_1,y,arg_3,arg_4);
  }
  return uval_1;
}



/*
 * Decompiled function: Palette_Subsystem_004963e7
 * Entry Point: 004386c1
 * Size: 176 bytes
 */


int32_t Palette_Subsystem_004963e7(void)

{
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = Palette_Subsystem_00496497;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(1);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_KimDebug_004f7170;
  RegisterClassA(&local_2c);
  DAT_00694744 = CreateWindowExA(0,s_KimDebug_004f7180,&DAT_004f717c,0x80cc0000,10,10,0xfa,0x113,
                                 DAT_00618990,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  return 1;
}



/*
 * Decompiled function: Palette_Subsystem_00496497
 * Entry Point: 00438771
 * Size: 487 bytes
 */


LRESULT Palette_Subsystem_00496497(HWND hwnd,uint32_t y,WPARAM arg_3,uint32_t height)

{
  LRESULT LVar1;
  
  if (y == 0x4c8) {
    LVar1 = SendMessageA(DAT_00516734,0x181,0,height);
    if (LVar1 == -2) {
      LVar1 = SendMessageA(DAT_00516734,0x18b,0,0);
      SendMessageA(DAT_00516734,0x182,LVar1 - 1,0);
      SendMessageA(DAT_00516734,0x182,LVar1 - 2,0);
      SendMessageA(DAT_00516734,0x181,0,height);
    }
    return 0;
  }
  if (y < 0x11) {
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
    switch(y) {
    case 1:
      DAT_00516734 = CreateWindowExA(0,s_LISTBOX_004f7190,&DAT_004f718c,0x50240000,0,0,0,0,hwnd,
                                     (HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      LVar1 = 0;
      break;
    case 2:
      KillTimer(hwnd,1);
      LVar1 = 0;
      break;
    case 3:
      SendMessageA(DAT_00516734,0x184,0,0);
      LVar1 = 0;
      break;
    default:
      goto switchD_00438930_caseD_4;
    case 5:
      MoveWindow(DAT_00516734,0,0,height & 0xffff,height >> 0x10,1);
      LVar1 = 0;
    }
  }
  else {
    if (y == 0x113) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x201) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
switchD_00438930_caseD_4:
    LVar1 = DefWindowProcA(hwnd,y,arg_3,height);
  }
  return LVar1;
}



/*
 * Decompiled function: FUN_00438980
 * Entry Point: 00438980
 * Size: 619 bytes
 */


int FUN_00438980(WPARAM arg_1,int card_slot,int width,int height)

{
  int local_154;
  char local_150 [264];
  HBITMAP local_48;
  HDC local_44;
  int local_40;
  int *local_3c;
  void *local_38;
  void *local_34;
  BITMAPINFO local_30;
  
  local_40 = 1;
  if (arg_1 == 0xffffffff) {
    local_40 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg_1 * 0x98) < 2) {
    if (*(int *)(&DAT_0060d5b0 + arg_1 * 0x10) != 0) {
      if ((*(int *)(&DAT_0060d5b8 + arg_1 * 0x10) == width) &&
         (*(int *)(&DAT_0060d5bc + arg_1 * 0x10) == height)) {
        return 1;
      }
      FUN_00438e72(arg_1);
    }
    _sprintf(local_150,s__s__04d_WVL_004f7198,&DAT_005f7800,arg_1);
    local_3c = (int *)Glue_Subsystem_004f15c0(0,local_150,0);
    if (local_3c == (int *)0x0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      FUN_004707a4(local_44);
      FUN_00491750((int32_t *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)FUN_0047fc77((uint32_t *)0x0,local_3c,width,height);
        if (local_34 == (void *)0x0) {
          local_40 = 0;
          DeleteObject(local_48);
        }
        else {
          if ((-width & 3U) == 0) {
            local_154 = 0;
          }
          else {
            local_154 = 4 - (-width & 3U);
          }
          FID_conflict__memcpy(local_38,local_34,(width * 3 + local_154) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      FUN_0047e7a5(local_3c);
    }
    if (local_40 != 0) {
      *(HBITMAP *)(&DAT_0060d5b0 + arg_1 * 0x10) = local_48;
      *(void **)(&DAT_0060d5b4 + arg_1 * 0x10) = local_38;
      *(int *)(&DAT_0060d5b8 + arg_1 * 0x10) = width;
      *(int *)(&DAT_0060d5bc + arg_1 * 0x10) = height;
      PostMessageA(DAT_00618990,0x433,arg_1,0);
    }
  }
  else {
    local_40 = FUN_00438ec2(arg_1,arg_2,width,height);
  }
  return local_40;
}



/*
 * Decompiled function: FUN_00438bf0
 * Entry Point: 00438bf0
 * Size: 130 bytes
 */


int32_t FUN_00438bf0(int arg1,int arg2)

{
  int32_t uval_1;
  int val_2;
  
  if (arg1 == -1) {
    uval_1 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg1 * 0x98) < 2) {
    if (*(int *)(&DAT_0060d5b0 + arg1 * 0x10) == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    val_2 = FUN_00439172(arg1,arg2);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00438c81
 * Entry Point: 00438c81
 * Size: 221 bytes
 */


int FUN_00438c81(HDC hdc,RECT *arg_2,int width,int arg_4)

{
  int val_1;
  HBRUSH hbr;
  int slot_idx;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (RECT *)0x0)) {
    slot_idx = 0;
  }
  else if (width == -1) {
    slot_idx = 0;
  }
  else if (*(int *)(&DAT_00618b04 + width * 0x98) < 2) {
    val_1 = FUN_00438bf0(width,arg_4);
    if (val_1 == 0) {
      slot_idx = 0;
    }
    else {
      slot_idx = FUN_004709ae((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_0060d5b0 + width * 0x10));
    }
    if (slot_idx == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  else {
    slot_idx = FUN_00439208(hdc,arg_2,width,arg_4);
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00438d5e
 * Entry Point: 00438d5e
 * Size: 271 bytes
 */


int32_t FUN_00438d5e(WPARAM arg_1,int card_slot,int width,int height)

{
  HGDIOBJ ho;
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg_1 * 0x98) < 2) {
    if (((*(int *)(&DAT_0060d5b0 + arg_1 * 0x10) == 0) ||
        (*(int *)(&DAT_0060d5b8 + arg_1 * 0x10) != width)) ||
       (*(int *)(&DAT_0060d5bc + arg_1 * 0x10) != height)) {
      ho = *(HGDIOBJ *)(&DAT_0060d5b0 + arg_1 * 0x10);
      *(int32_t *)(&DAT_0060d5b0 + arg_1 * 0x10) = 0;
      val_2 = FUN_00438980(arg_1,arg_2,width,height);
      if (val_2 == 0) {
        *(HGDIOBJ *)(&DAT_0060d5b0 + arg_1 * 0x10) = ho;
        uval_1 = 0;
      }
      else {
        if (ho != (HGDIOBJ)0x0) {
          DeleteObject(ho);
        }
        uval_1 = 1;
      }
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    uval_1 = FUN_004392f3(arg_1,arg_2,width,height);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00438e72
 * Entry Point: 00438e72
 * Size: 80 bytes
 */


void FUN_00438e72(int player_id)

{
  if ((arg_1 != -1) && (*(int *)(&DAT_0060d5b0 + arg_1 * 0x10) != 0)) {
    DeleteObject(*(HGDIOBJ *)(&DAT_0060d5b0 + arg_1 * 0x10));
    *(int32_t *)(&DAT_0060d5b0 + arg_1 * 0x10) = 0;
  }
  return;
}



/*
 * Decompiled function: FUN_00438ec2
 * Entry Point: 00438ec2
 * Size: 683 bytes
 */


int FUN_00438ec2(WPARAM arg_1,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  HBITMAP local_4c;
  HDC local_48;
  int local_44;
  int *local_40;
  void *local_3c;
  void *local_38;
  BITMAPINFO local_34;
  int slot_idx;
  
  local_44 = 1;
  if (arg_1 == 0xffffffff) {
    local_44 = 0;
  }
  else {
    slot_idx = FUN_00439172(arg_1,y);
    if (slot_idx != 0) {
      if ((*(int *)(slot_idx + 8) == width) && (*(int *)(slot_idx + 0xc) == height)) {
        return 1;
      }
      FUN_004393a2(arg_1,y);
    }
    if (y == 0) {
      _sprintf(local_154,s__s__04d_WVL_004f71b4,&DAT_005f7800,arg_1);
    }
    else {
      _sprintf(local_154,s__s__04d_c_WVL_004f71a4,&DAT_005f7800,arg_1,(int)(char)((char)y + '`'));
    }
    local_40 = (int *)Glue_Subsystem_004f15c0(0,local_154,0);
    if (local_40 == (int *)0x0) {
      local_44 = 0;
    }
    else {
      local_48 = GetDC((HWND)0x0);
      FUN_004707a4(local_48);
      FUN_00491750((int32_t *)&local_34,width,height);
      local_4c = CreateDIBSection(local_48,&local_34,0,&local_3c,(HANDLE)0x0,0);
      if (local_4c == (HBITMAP)0x0) {
        local_44 = 0;
      }
      else {
        local_38 = (void *)FUN_0047fc77((uint32_t *)0x0,local_40,width,height);
        if (local_38 == (void *)0x0) {
          local_44 = 0;
          DeleteObject(local_4c);
        }
        else {
          if ((-width & 3U) == 0) {
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          FID_conflict__memcpy(local_3c,local_38,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_48);
      FUN_0047e7a5(local_40);
    }
    if (local_44 != 0) {
      *(HBITMAP *)(&DAT_00616a10 + DAT_00663df8 * 0x18) = local_4c;
      *(void **)(&DAT_00616a14 + DAT_00663df8 * 0x18) = local_3c;
      *(int *)(&DAT_00616a18 + DAT_00663df8 * 0x18) = width;
      *(int *)(&DAT_00616a1c + DAT_00663df8 * 0x18) = height;
      *(WPARAM *)(&DAT_00616a20 + DAT_00663df8 * 0x18) = arg_1;
      *(int *)(&DAT_00616a24 + DAT_00663df8 * 0x18) = y;
      DAT_00663df8 = DAT_00663df8 + 1;
      PostMessageA(DAT_00618990,0x433,arg_1,y);
    }
  }
  return local_44;
}



/*
 * Decompiled function: FUN_00439172
 * Entry Point: 00439172
 * Size: 150 bytes
 */


uint8_t * FUN_00439172(int arg1,int arg2)

{
  int match_count;
  uint8_t *slot_idx;
  
  slot_idx = (uint8_t *)0x0;
  if (arg1 == -1) {
    slot_idx = (uint8_t *)0x0;
  }
  else {
    match_count = 0;
    while ((match_count < DAT_00663df8 && (slot_idx == (uint8_t *)0x0))) {
      if ((*(int *)(&DAT_00616a20 + match_count * 0x18) == arg1) &&
         (*(int *)(&DAT_00616a24 + match_count * 0x18) == arg2)) {
        slot_idx = &DAT_00616a10 + match_count * 0x18;
      }
      match_count = match_count + 1;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00439208
 * Entry Point: 00439208
 * Size: 235 bytes
 */


int FUN_00439208(HDC hdc,RECT *arg_2,int width,int height)

{
  bool flag_1;
  HBRUSH hbr;
  int player_idx;
  int card_idx;
  int match_count;
  
  if (width == -1) {
    player_idx = 0;
  }
  else {
    match_count = 0;
    flag_1 = false;
    while ((match_count < DAT_00663df8 && (!flag_1))) {
      if ((*(int *)(&DAT_00616a20 + match_count * 0x18) == width) &&
         (*(int *)(&DAT_00616a24 + match_count * 0x18) == height)) {
        flag_1 = true;
        card_idx = match_count;
      }
      match_count = match_count + 1;
    }
    if (flag_1) {
      player_idx = FUN_004709ae((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_00616a10 + card_idx * 0x18));
    }
    else {
      player_idx = 0;
    }
    if (player_idx == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  return player_idx;
}



/*
 * Decompiled function: FUN_004392f3
 * Entry Point: 004392f3
 * Size: 165 bytes
 */


int32_t FUN_004392f3(WPARAM arg_1,int y,int width,int height)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else {
    val_2 = FUN_00439172(arg_1,y);
    if (val_2 != 0) {
      if ((*(int *)(val_2 + 8) == width) && (*(int *)(val_2 + 0xc) == height)) {
        return 1;
      }
      FUN_004393a2(arg_1,y);
    }
    val_2 = FUN_00438ec2(arg_1,y,width,height);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004393a2
 * Entry Point: 004393a2
 * Size: 372 bytes
 */


void FUN_004393a2(int arg1,int arg2)

{
  bool flag_1;
  int card_idx;
  int match_count;
  
  if (arg1 != -1) {
    match_count = 0;
    flag_1 = false;
    while ((match_count < DAT_00663df8 && (!flag_1))) {
      if ((*(int *)(&DAT_00616a20 + match_count * 0x18) == arg1) &&
         (*(int *)(&DAT_00616a24 + match_count * 0x18) == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_00616a10 + match_count * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_00616a10 + match_count * 0x18));
        }
        DAT_00663df8 = DAT_00663df8 + -1;
        for (card_idx = match_count; card_idx < DAT_00663df8; card_idx = card_idx + 1) {
          *(int32_t *)(&DAT_00616a10 + card_idx * 0x18) =
               *(int32_t *)(&DAT_00616a10 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_00616a14 + card_idx * 0x18) =
               *(int32_t *)(&DAT_00616a14 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_00616a18 + card_idx * 0x18) =
               *(int32_t *)(&DAT_00616a18 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_00616a1c + card_idx * 0x18) =
               *(int32_t *)(&DAT_00616a1c + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_00616a20 + card_idx * 0x18) =
               *(int32_t *)(&DAT_00616a20 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_00616a24 + card_idx * 0x18) =
               *(int32_t *)(&DAT_00616a24 + (card_idx * 3 + 3) * 8);
        }
      }
      match_count = match_count + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00439516
 * Entry Point: 00439516
 * Size: 79 bytes
 */


void FUN_00439516(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < DAT_00663df8; slot_idx = slot_idx + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00616a10 + slot_idx * 0x18));
  }
  DAT_00663df8 = 0;
  return;
}



/*
 * Decompiled function: FUN_00439570
 * Entry Point: 00439570
 * Size: 102 bytes
 */


void FUN_00439570(int player_id)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_004f71c0 + slot_idx * 8) =
         *(int32_t *)(&DAT_004f71c0 + slot_idx * 8 + arg_1 * 0x280);
    (&DAT_004f71c4)[slot_idx * 2] = (&DAT_004f71c4)[arg_1 * 0xa0 + slot_idx * 2];
  }
  return;
}



/*
 * Decompiled function: FUN_004395d6
 * Entry Point: 004395d6
 * Size: 131 bytes
 */


void FUN_004395d6(int arg1,int arg2)

{
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (0x4f < slot_idx) {
      return;
    }
    if ((0 < (int)(&DAT_004f71c4)[arg1 * 0xa0 + slot_idx * 2]) &&
       (val_1 = FUN_004d7d5e(*(int *)(&DAT_004f71c0 + slot_idx * 8 + arg1 * 0x280)), val_1 == arg2))
    break;
    slot_idx = slot_idx + 1;
  }
  (&DAT_004f71c4)[arg1 * 0xa0 + slot_idx * 2] = (&DAT_004f71c4)[arg1 * 0xa0 + slot_idx * 2] + -1;
  return;
}



/*
 * Decompiled function: FUN_00439659
 * Entry Point: 00439659
 * Size: 145 bytes
 */


void FUN_00439659(char *arg_1,int y,uint32_t arg_3,int arg_4)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
    (&DAT_004f71c4)[y * 0xa0 + slot_idx * 2] = 0;
    *(int32_t *)(&DAT_004f71c0 + slot_idx * 8 + y * 0x280) =
         (&DAT_004f71c4)[y * 0xa0 + slot_idx * 2];
  }
  Deck_FilterAttributes_00492bd9(arg_1,(int)(&DAT_004f71c0 + y * 0x280),arg_3,arg_4);
  return;
}



/*
 * Decompiled function: FUN_004396ea
 * Entry Point: 004396ea
 * Size: 324 bytes
 */


int FUN_004396ea(int player_id)

{
  int val_1;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_1 == -1) {
    val_1 = -1;
  }
  else {
    card_idx = 0;
    for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
      card_idx = card_idx + (&DAT_004f71c4)[arg_1 * 0xa0 + slot_idx * 2];
    }
    if (card_idx == 0) {
      val_1 = -1;
    }
    else {
      match_count = FUN_00439892(card_idx);
      for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
        match_count = match_count - (&DAT_004f71c4)[arg_1 * 0xa0 + slot_idx * 2];
        if (match_count < 0) {
          player_idx = *(int *)(&DAT_004f71c0 + slot_idx * 8 + arg_1 * 0x280);
          if (DAT_0066aaf4 != 1) {
            (&DAT_004f71c4)[arg_1 * 0xa0 + slot_idx * 2] =
                 (&DAT_004f71c4)[arg_1 * 0xa0 + slot_idx * 2] + -1;
          }
          break;
        }
      }
      for (slot_idx = 0;
          (val_1 = DAT_00665ed0, slot_idx < DAT_00665ed0 &&
          (val_1 = slot_idx, *(int *)(&DAT_004ff590 + slot_idx * 0x34) != player_idx));
          slot_idx = slot_idx + 1) {
      }
    }
  }
  return val_1;
}



/*
 * Decompiled function: FUN_0043982e
 * Entry Point: 0043982e
 * Size: 53 bytes
 */


void FUN_0043982e(void)

{
  Palette_Subsystem_004a5722
            (DAT_00676510,(int *)&DAT_006671c0,500,s_Opponent_library_004f76c4,0,&DAT_004f76c0);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00439863
 * Entry Point: 00439863
 * Size: 47 bytes
 */


void Mem_AllocOrFree_00439863(void)

{
  Palette_Subsystem_004a5722
            (DAT_00676510,(int *)&DAT_006669f0,500,s_Your_Library_004f76dc,0,&DAT_004f76d8);
  return;
}



/*
 * Decompiled function: FUN_00439892
 * Entry Point: 00439892
 * Size: 44 bytes
 */


int FUN_00439892(int player_id)

{
  int val_1;
  
  if (arg_1 < 2) {
    val_1 = 0;
  }
  else {
    val_1 = _rand();
    val_1 = val_1 % arg_1;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_004398be
 * Entry Point: 004398be
 * Size: 64 bytes
 */


void FUN_004398be(void)

{
  int val_1;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 100; slot_idx = slot_idx + 1) {
    val_1 = _rand();
    *(int *)(&DAT_00516748 + slot_idx * 4) = val_1;
  }
  Mem_AllocOrFree_004398fe();
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004398fe
 * Entry Point: 004398fe
 * Size: 21 bytes
 */


void Mem_AllocOrFree_004398fe(void)

{
  DAT_00516744 = 0;
  return;
}



/*
 * Decompiled function: FUN_00439913
 * Entry Point: 00439913
 * Size: 101 bytes
 */


uint32_t FUN_00439913(uint32_t arg_1)

{
  uint32_t uval_1;
  
  if (DAT_00516744 < 100) {
    uval_1 = (int)(*(int *)(&DAT_00516748 + (DAT_00516744 % 100) * 4) * arg_1) >> 0xf;
  }
  else {
    uval_1 = DAT_00516744 % arg_1;
  }
  DAT_00516744 = DAT_00516744 + 1;
  return uval_1;
}



/*
 * Decompiled function: UI_DeckDialogProc_00439980
 * Entry Point: 00439980
 * Size: 246 bytes
 */


int32_t UI_DeckDialogProc_00439980(uint32_t *arg_1,uint32_t *arg_2,int32_t *arg_3)

{
  INT_PTR IVar1;
  int32_t local_21c;
  uint32_t local_214 [65];
  uint32_t local_10f [65];
  int32_t slot_idx;
  
  slot_idx = *arg_3;
  IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdd,DAT_00618990,Palette_Subsystem_00496497,
                          (LPARAM)local_214);
  if (IVar1 == -1) {
    MessageBoxA(DAT_00618990,s_Couldn_t_bring_up_the_Load_Decks_004f76f0,&DAT_004f76ec,0);
    local_21c = 0;
  }
  else if (IVar1 == 1) {
    Mem_AllocOrFree_004d9630(arg_1,local_214);
    Mem_AllocOrFree_004d9630(arg_2,local_10f);
    *arg_3 = slot_idx;
    DAT_00601578 = 0;
    local_21c = 1;
  }
  else if (IVar1 == 0) {
    DAT_00601578 = 1;
    local_21c = 1;
  }
  return local_21c;
}



/*
 * Decompiled function: Palette_Subsystem_00496497
 * Entry Point: 00439a76
 * Size: 1556 bytes
 */


HGDIOBJ Palette_Subsystem_00496497(HWND hwnd,uint32_t y,HDC hdc,HWND param_4)

{
  char *char_ptr_1;
  size_t len_2;
  int val_3;
  HWND pHVar4;
  UINT UVar5;
  HGDIOBJ pvVar6;
  HBRUSH hbr;
  tagRECT local_334;
  HWND local_324;
  int local_320;
  HDC local_31c;
  WPARAM local_314;
  uint8_t local_310 [32];
  uint32_t local_2f0 [66];
  uint32_t local_1e8 [66];
  HWND local_e0;
  int local_dc;
  char local_d8 [200];
  WPARAM card_idx;
  FILE *match_count;
  char *slot_idx;
  
  if (y < 0x111) {
    if (y == 0x110) {
      DAT_005168d8 = param_4;
      local_e0 = CreateWindowExA(0,s_LISTBOX_004f771c,&DAT_004f7718,0x40a00003,0,0,0,0,hwnd,
                                 (HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      if (local_e0 == (HWND)0x0) {
        EndDialog(hwnd,-1);
        return (HGDIOBJ)0x1;
      }
      Mem_AllocOrFree_004d9630(local_1e8,(uint32_t *)&DAT_00664a60);
      FUN_004d9640(local_1e8,(uint32_t *)s____DCK_004f7724);
      SendMessageA(local_e0,0x18d,0,(LPARAM)local_1e8);
      local_dc = SendMessageA(local_e0,0x18b,0,0);
      for (card_idx = 0; (int)card_idx < local_dc; card_idx = card_idx + 1) {
        SendMessageA(local_e0,0x189,card_idx,(LPARAM)local_1e8);
        Mem_AllocOrFree_004d9630(local_2f0,(uint32_t *)&DAT_00664a60);
        FUN_004d9640(local_2f0,(uint32_t *)&DAT_004f772c);
        FUN_004d9640(local_2f0,local_1e8);
        match_count = _fopen((char *)local_2f0,&DAT_004f7730);
        if (match_count != (FILE *)0x0) {
          local_d8[0] = '\0';
          len_2 = _strlen(local_d8);
          slot_idx = local_d8 + len_2;
          while( true ) {
            val_3 = _fgetc(match_count);
            *slot_idx = (char)val_3;
            if (*slot_idx == '\n') break;
            slot_idx = slot_idx + 1;
          }
          *slot_idx = '\0';
          _fclose(match_count);
          SendDlgItemMessageA(hwnd,1000,0x143,0,(LPARAM)local_d8);
          SendDlgItemMessageA(hwnd,0x3e9,0x143,0,(LPARAM)local_d8);
        }
      }
      SendDlgItemMessageA(hwnd,1000,0x14e,0,0);
      SendDlgItemMessageA(hwnd,0x3e9,0x14e,0,0);
      if ((DAT_005168d8[0x83].unused < 0) || (3 < DAT_005168d8[0x83].unused)) {
        DAT_005168d8[0x83].unused = 1;
      }
      CheckRadioButton(hwnd,0x3eb,0x3ee,DAT_005168d8[0x83].unused + 0x3eb);
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      return (HGDIOBJ)0x0;
    }
    if (y == 0x14) {
      FUN_004707a4(hdc);
      GetClientRect(hwnd,&local_334);
      hbr = GetStockObject(1);
      FillRect(hdc,&local_334,hbr);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (y == 0x111) {
      if (((uint32_t)hdc & 0xffff) == 0x3ef) {
        FUN_00480690(DAT_00618990);
        pHVar4 = GetDlgItem(hwnd,1);
        SetFocus(pHVar4);
      }
      else if (((uint32_t)hdc & 0xffff) == 1) {
        local_314 = SendDlgItemMessageA(hwnd,1000,0x147,0,0);
        SendDlgItemMessageA(hwnd,1000,0x148,local_314,(LPARAM)local_310);
        _sprintf((char *)DAT_005168d8,s__s__s_dck_004f7734,&DAT_00664a60,local_310);
        local_314 = SendDlgItemMessageA(hwnd,0x3e9,0x147,0,0);
        SendDlgItemMessageA(hwnd,0x3e9,0x148,local_314,(LPARAM)local_310);
        _sprintf((char *)((int)DAT_005168d8 + 0x105),s__s__s_dck_004f7740,&DAT_00664a60,local_310);
        UVar5 = IsDlgButtonChecked(hwnd,0x3eb);
        if (UVar5 == 0) {
          UVar5 = IsDlgButtonChecked(hwnd,0x3ec);
          if (UVar5 == 0) {
            UVar5 = IsDlgButtonChecked(hwnd,0x3ed);
            if (UVar5 == 0) {
              UVar5 = IsDlgButtonChecked(hwnd,0x3ee);
              if (UVar5 != 0) {
                char_ptr_1 = (char *)DAT_005168d8;
                char_ptr_1[0x20c] = '\x03';
                char_ptr_1[0x20d] = '\0';
                char_ptr_1[0x20e] = '\0';
                char_ptr_1[0x20f] = '\0';
              }
            }
            else {
              char_ptr_1 = (char *)DAT_005168d8;
              char_ptr_1[0x20c] = '\x02';
              char_ptr_1[0x20d] = '\0';
              char_ptr_1[0x20e] = '\0';
              char_ptr_1[0x20f] = '\0';
            }
          }
          else {
            char_ptr_1 = (char *)DAT_005168d8;
            char_ptr_1[0x20c] = '\x01';
            char_ptr_1[0x20d] = '\0';
            char_ptr_1[0x20e] = '\0';
            char_ptr_1[0x20f] = '\0';
          }
        }
        else {
          char_ptr_1 = (char *)DAT_005168d8;
          char_ptr_1[0x20c] = '\0';
          char_ptr_1[0x20d] = '\0';
          char_ptr_1[0x20e] = '\0';
          char_ptr_1[0x20f] = '\0';
        }
        EndDialog(hwnd,1);
      }
      else if (((uint32_t)hdc & 0xffff) == 0x471) {
        FUN_004328ba(1);
        DAT_0066aaf4 = 0xfffffffe;
        EndDialog(hwnd,0);
      }
      else if (((uint32_t)hdc & 0xffff) == 0x472) {
        FUN_004328ba(0);
        DAT_0066aaf4 = 0xffffffff;
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
    if ((y == 0x135) || (y == 0x138)) {
      local_31c = hdc;
      FUN_004707a4(hdc);
      local_324 = param_4;
      local_320 = GetDlgCtrlID(param_4);
      if (local_320 != 0x3ea) {
        SetBkMode(local_31c,1);
        pvVar6 = GetStockObject(5);
        return pvVar6;
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: FUN_0043a094
 * Entry Point: 0043a094
 * Size: 775 bytes
 */


int32_t FUN_0043a094(int player_id)

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
  if (arg_1 == -1) {
    for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
      if ((*(int *)(&deck + color_idx * 4) != -1) && (((&DAT_006c13b1)[color_idx * 4] & 0xc0) == 0)) {
        flag_1 = (&DAT_004ff596)[(*(uint32_t *)(&deck + color_idx * 4) & 0xfff) * 0x34];
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
      val_2 = (&DAT_004f71c4)[arg_1 * 0xa0 + color_idx * 2];
      if ((*(int *)(&DAT_004f71c0 + color_idx * 8 + arg_1 * 0x280) != -1) && (val_2 != 0)) {
        val_3 = CardTypeFromID(*(int *)(&DAT_004f71c0 + color_idx * 8 + arg_1 * 0x280));
        flag_1 = (&DAT_004ff596)[val_3 * 0x34];
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
 * Decompiled function: UI_RegisterExpandedGraveyardClass
 * Entry Point: 0043a3a0
 * Size: 401 bytes
 */


bool UI_RegisterExpandedGraveyardClass(LPCSTR str_1)

{
  ATOM AVar1;
  ATOM AVar2;
  ATOM AVar3;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_GraveyardMenuProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 8;
  local_2c.lpfnWndProc = UI_WndProc_0043b02a;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ExpandedGraveyard_004f774c;
  AVar2 = RegisterClassA(&local_2c);
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_0043b1a4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_GraveyardCards_004f7760;
  AVar3 = RegisterClassA(&local_2c);
  DAT_005168ec = CreatePopupMenu();
  return AVar3 != 0 && (AVar2 != 0 && AVar1 != 0);
}



/*
 * Decompiled function: FUN_0043a531
 * Entry Point: 0043a531
 * Size: 46 bytes
 */


void FUN_0043a531(void)

{
  if (DAT_005168ec != (HMENU)0x0) {
    DestroyMenu(DAT_005168ec);
  }
  DAT_005168ec = (HMENU)0x0;
  return;
}



/*
 * Decompiled function: UI_GraveyardMenuProc
 * Entry Point: 0043a55f
 * Size: 2639 bytes
 */


LRESULT UI_GraveyardMenuProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam)

{
  LONG LVar1;
  HBRUSH pHVar2;
  UINT dwMilliseconds;
  BOOL BVar3;
  int val_4;
  WPARAM wParam_00;
  LRESULT LVar5;
  int local_a68;
  uint8_t local_a60 [2000];
  uint32_t local_290;
  tagMSG local_28c;
  int local_270;
  tagPOINT local_26c;
  tagRECT local_264;
  HDC local_254;
  tagPAINTSTRUCT local_250;
  tagRECT local_210;
  int local_200;
  uint32_t local_1fc [66];
  ULONG_PTR local_f4;
  uint32_t local_f0;
  uint32_t local_ec;
  int local_e8;
  uint32_t local_e4;
  uint32_t local_e0;
  WPARAM local_dc;
  uint32_t local_d8 [25];
  uint32_t local_74 [25];
  LONG card_idx;
  HGDIOBJ match_count;
  HWND slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      card_idx = GetWindowLongA(hwnd,0);
      match_count = (HGDIOBJ)GetWindowLongA(hwnd,8);
      local_200 = FUN_0043b850((uint32_t)(hwnd != DAT_00618978));
      if (local_200 != card_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(hwnd,&local_210);
      pHVar2 = GetStockObject(4);
      FillRect(DAT_0060157c,&local_210,pHVar2);
      if (local_200 == -1) {
        if (match_count != (HANDLE)0x0) {
          FUN_004709ae((int)DAT_0060157c,(int)&local_210,match_count);
        }
      }
      else {
        Palette_Subsystem_0049c7c7
                  (DAT_0060157c,&local_210.left,(int32_t *)(&DAT_00618ac0 + local_200 * 0x98),0,
                   0x11,0);
      }
      local_254 = BeginPaint(hwnd,&local_250);
      if (local_254 != (HDC)0x0) {
        FUN_004707a4(local_254);
        if (DAT_00601580 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_254,&local_210,pHVar2);
          Sleep(200);
        }
        BitBlt(local_254,0,0,local_210.right,local_210.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_250);
        card_idx = local_200;
        SetWindowLongA(hwnd,0,local_200);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      card_idx = 0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      slot_idx = (HWND)0x0;
      SetWindowLongA(hwnd,4,0);
      match_count = (HGDIOBJ)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      match_count = (HGDIOBJ)GetWindowLongA(hwnd,8);
      if (match_count != (HANDLE)0x0) {
        FUN_00471395(match_count);
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar5 = UI_WndProc_00471df6(hwnd,0x20,wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      local_290 = (uint32_t)(hwnd != DAT_00618978);
      AppendMenuA(DAT_005168ec,0,100,s_View_the_graveyard_004f7794);
      val_4 = FUN_00448653(local_a60,local_290);
      if (val_4 == 0) {
        EnableMenuItem(DAT_005168ec,100,1);
      }
      AppendMenuA(DAT_005168ec,0,0x65,s_View_the_out_of_play_cards_004f77a8);
      val_4 = FUN_004486f6(local_a60,local_290);
      if (val_4 == 0) {
        EnableMenuItem(DAT_005168ec,0x65,1);
      }
      AppendMenuA(DAT_005168ec,0,0x66,s_View_both_antes_004f77c4);
      AppendMenuA(DAT_005168ec,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_005168ec,0,0x67,s_Help____004f77d4);
      return 0;
    }
    if (uMsg == 0x111) {
      switch(wParam & 0xffff) {
      case 100:
        SendMessageA(hwnd,0x400,1,1);
        break;
      case 0x65:
        SendMessageA(hwnd,0x400,1,0);
        break;
      case 0x66:
        Mem_AllocOrFree_0043b8a8();
        break;
      case 0x67:
        local_f4 = 0x7e6;
        Mem_AllocOrFree_004d9630(local_1fc,(uint32_t *)&DAT_005f76e0);
        FUN_004d9640(local_1fc,(uint32_t *)s__duel_hlp_004f7788);
        WinHelpA(DAT_00618990,(LPCSTR)local_1fc,1,local_f4);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x400,1,1);
      return 0;
    }
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_a68 = GetMenuItemCount(DAT_005168ec);
        while (local_a68 != 0) {
          DeleteMenu(DAT_005168ec,0,0x400);
          local_a68 = local_a68 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_270 = 1;
      if (DAT_00663e24 == 2) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        BVar3 = PeekMessageA(&local_28c,hwnd,0x206,0x206,0);
        if (BVar3 != 0) {
          local_270 = 0;
        }
      }
      if (local_270 != 0) {
        local_26c.x = lParam & 0xffff;
        local_26c.y = lParam >> 0x10;
        ClientToScreen(hwnd,&local_26c);
        SetRect(&local_264,local_26c.x,local_26c.y,local_26c.x + 1,local_26c.y + 1);
        TrackPopupMenu(DAT_005168ec,2,local_26c.x,local_26c.y,0,hwnd,&local_264);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      wParam_00 = FUN_0043b850((uint32_t)(hwnd != DAT_00618978));
      if ((wParam_00 != 0xffffffff) && (DAT_00663e24 == 2)) {
        SendMessageA(DAT_006152e0,0x401,wParam_00,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      slot_idx = (HWND)GetWindowLongA(hwnd,4);
      local_ec = wParam;
      local_f0 = lParam;
      if (wParam == 0) {
        if (slot_idx != (HWND)0x0) {
          ReleaseCapture();
          FUN_0043b83b(slot_idx);
          slot_idx = (HWND)0x0;
          SetWindowLongA(hwnd,4,0);
        }
      }
      else {
        if (slot_idx == (HWND)0x0) {
          slot_idx = (HWND)UI_RegisterExpandedGraveyardClass(hwnd,lParam);
        }
        SetWindowLongA(hwnd,4,(LONG)slot_idx);
        if (slot_idx != (HWND)0x0) {
          SetCapture(slot_idx);
        }
      }
      return 0;
    case 0x432:
      card_idx = GetWindowLongA(hwnd,0);
      local_e8 = FUN_0043b850((uint32_t)(hwnd != DAT_00618978));
      SendMessageA(hwnd,0x400,0,0);
      if (local_e8 != card_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_e0 = FUN_0043b850((uint32_t)(hwnd != DAT_00618978));
      local_e4 = wParam;
      if (wParam == local_e0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      if (hwnd == DAT_00618978) {
        Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Your_004f7770);
      }
      else {
        FUN_00448412((char *)local_74);
      }
      _sprintf((char *)local_d8,s__s_graveyard_004f7778,local_74);
      Mem_AllocOrFree_004d9630((uint32_t *)wParam,local_d8);
      local_dc = FUN_0043b850((uint32_t)(hwnd != DAT_00618978));
      if ((local_dc != 0xffffffff) &&
         ((DAT_00663e24 != 2 || (BVar3 = IsWindowVisible(DAT_006152e0), BVar3 != 0)))) {
        SendMessageA(DAT_006152e0,0x401,local_dc,0);
      }
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      match_count = (HGDIOBJ)GetWindowLongA(hwnd,8);
      if (match_count != (HGDIOBJ)0x0) {
        DeleteObject(match_count);
      }
      match_count = (HGDIOBJ)wParam;
      SetWindowLongA(hwnd,8,wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar5;
}



/*
 * Decompiled function: UI_WndProc_0043b02a
 * Entry Point: 0043b02a
 * Size: 366 bytes
 */


LRESULT UI_WndProc_0043b02a(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam)

{
  POINT Point;
  LRESULT LVar1;
  tagPOINT card_idx;
  HWND slot_idx;
  
  if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_0043b07d:
      GetCursorPos(&card_idx);
      Point.y = card_idx.y;
      Point.x = card_idx.x;
      slot_idx = WindowFromPoint(Point);
      MapWindowPoints((HWND)0x0,slot_idx,&card_idx,1);
      if (hwnd != slot_idx) {
        SendMessageA(slot_idx,uMsg,wParam,card_idx.y << 0x10 | card_idx.x & 0xffffU);
      }
      return 0;
    }
    if (uMsg == 1) {
      return 0;
    }
  }
  else if (uMsg < 0x207) {
    if (uMsg == 0x206) goto LAB_0043b07d;
    if (uMsg == 0x201) {
      SendMessageA(DAT_00618978,0x400,0,0);
      SendMessageA(DAT_0061737c,0x400,0,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 0x437) {
      return 0;
    }
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar1;
}



/*
 * Decompiled function: UI_WndProc_0043b1a4
 * Entry Point: 0043b1a4
 * Size: 705 bytes
 */


LRESULT UI_WndProc_0043b1a4(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam)

{
  BOOL BVar1;
  LONG LVar2;
  WPARAM WVar3;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar4;
  tagPAINTSTRUCT local_58;
  tagRECT target_idx;
  WPARAM slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = GetWindowLongA(hwnd,0);
      GetClientRect(hwnd,&target_idx);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&target_idx,hbr);
      Palette_Subsystem_0049c7c7
                (DAT_0060157c,&target_idx.left,(int32_t *)(&DAT_00618ac0 + slot_idx * 0x98),0,0x11,0
                );
      hdc = BeginPaint(hwnd,&local_58);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        BitBlt(hdc,0,0,target_idx.right,target_idx.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_58);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = 0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x206) {
      slot_idx = GetWindowLongA(hwnd,0);
      if (DAT_00663e24 == 2) {
        SendMessageA(DAT_006152e0,0x401,slot_idx,0);
      }
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      LVar2 = GetWindowLongA(hwnd,0);
      return LVar2;
    }
    if (uMsg == 0x401) {
      WVar3 = GetWindowLongA(hwnd,0);
      if (wParam != WVar3) {
        slot_idx = wParam;
        SetWindowLongA(hwnd,0,wParam);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      slot_idx = GetWindowLongA(hwnd,0);
      if ((DAT_00663e24 != 2) || (BVar1 = IsWindowVisible(DAT_006152e0), BVar1 != 0)) {
        SendMessageA(DAT_006152e0,0x401,slot_idx,0);
      }
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: UI_RegisterExpandedGraveyardClass
 * Entry Point: 0043b471
 * Size: 970 bytes
 */


HWND UI_RegisterExpandedGraveyardClass(HWND hwnd,int arg2)

{
  int val_1;
  HGDIOBJ buf_ptr_2;
  int val_3;
  int local_834;
  int local_830;
  int local_82c;
  int local_820;
  int local_818;
  WPARAM local_814 [500];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  uint32_t local_28;
  tagRECT local_24;
  tagRECT player_idx;
  
  GetWindowRect(hwnd,&local_24);
  player_idx.left = local_24.left;
  player_idx.top = local_24.top;
  GetClientRect(DAT_00618990,&local_24);
  player_idx.right = (local_24.right * 0x4b) / 100;
  player_idx.bottom = local_24.bottom;
  GetClientRect(hwnd,&local_24);
  local_2c = local_24.bottom;
  val_1 = (local_24.right * 0x3c) / 100;
  local_44 = 5;
  local_40 = 5;
  local_3c = (((player_idx.right - player_idx.left) + -10) - local_24.right) / val_1 + 1;
  local_28 = (uint32_t)(hwnd != DAT_00618978);
  local_30 = CreateWindowExA(0,s_ExpandedGraveyard_004f7800,
                             s_Graveyard_list_004f77dc + ((arg2 != 0) - 1 & 0x10),0x80000000,0,0,0,0
                             ,DAT_00618990,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  if (local_30 == (HWND)0x0) {
    local_30 = (HWND)0x0;
  }
  else {
    if (arg2 == 0) {
      buf_ptr_2 = GetStockObject(0);
      SetClassLongA(local_30,-10,(LONG)buf_ptr_2);
    }
    else {
      buf_ptr_2 = GetStockObject(4);
      SetClassLongA(local_30,-10,(LONG)buf_ptr_2);
    }
    local_830 = local_44;
    local_38 = local_40;
    if (arg2 == 0) {
      local_820 = FUN_004486f6(local_814,local_28);
    }
    else {
      local_820 = FUN_00448653(local_814,local_28);
    }
    local_82c = 0;
    local_818 = local_820;
    while (local_818 = local_818 + -1, -1 < local_818) {
      local_34 = CreateWindowExA(0,s_GraveyardCards_004f7838,
                                 s_Graveyard_card_004f7814 + ((arg2 != 0) - 1 & 0x10),0x54000000,
                                 local_830,local_38,local_24.right,local_2c,local_30,(HMENU)0x1,
                                 DAT_00664680,(LPVOID)0x0);
      if (local_34 != (HWND)0x0) {
        local_82c = local_82c + 1;
        SendMessageA(local_34,0x401,local_814[local_818],0);
        local_830 = local_830 + val_1;
        if (local_82c % local_3c == 0) {
          local_830 = local_44;
          local_38 = local_38 + local_40 + local_2c;
        }
      }
    }
    if (local_820 == 0) {
      DestroyWindow(local_30);
      local_30 = (HWND)0x0;
    }
    else {
      BringWindowToTop(local_30);
      val_3 = local_3c + -1;
      if (local_820 + -1 <= local_3c + -1) {
        val_3 = local_820 + -1;
      }
      player_idx.right = val_3 * val_1 + local_44 * 2 + player_idx.left + local_24.right;
      local_834 = local_820 / local_3c;
      if (local_820 % local_3c != 0) {
        local_834 = local_834 + 1;
      }
      player_idx.bottom =
           (local_40 + local_2c) * (local_834 + -1) + local_40 * 2 + player_idx.top + local_2c;
      GetClientRect(DAT_00618990,&local_24);
      if (local_24.bottom < player_idx.bottom) {
        OffsetRect(&player_idx,0,-(player_idx.bottom - local_24.bottom));
      }
      MoveWindow(local_30,player_idx.left,player_idx.top,player_idx.right - player_idx.left,
                 player_idx.bottom - player_idx.top,1);
      ShowWindow(local_30,5);
    }
  }
  return local_30;
}



/*
 * Decompiled function: FUN_0043b83b
 * Entry Point: 0043b83b
 * Size: 21 bytes
 */


void FUN_0043b83b(HWND hwnd)

{
  DestroyWindow(hwnd);
  return;
}



/*
 * Decompiled function: FUN_0043b850
 * Entry Point: 0043b850
 * Size: 83 bytes
 */


int32_t FUN_0043b850(int player_id)

{
  int32_t uval_1;
  int local_7d8;
  uint8_t local_7d4 [2000];
  
  local_7d8 = FUN_00448653(local_7d4,arg_1);
  if (local_7d8 == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = *(int32_t *)(local_7d4 + local_7d8 * 4 + -4);
  }
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043b8a8
 * Entry Point: 0043b8a8
 * Size: 41 bytes
 */


void Mem_AllocOrFree_0043b8a8(void)

{
  DialogBoxParamA(DAT_00664680,(LPCSTR)0xeb,DAT_00618990,UI_AnteDisplayWndProc,0);
  return;
}



/*
 * Decompiled function: UI_AnteDisplayWndProc
 * Entry Point: 0043b8d1
 * Size: 2562 bytes
 */


HGDIOBJ UI_AnteDisplayWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  size_t c;
  int val_1;
  BOOL BVar2;
  HGDIOBJ buf_ptr_3;
  HBRUSH hbr;
  HWND pHVar4;
  HWND pHVar5;
  int val_6;
  int val_7;
  int val_8;
  tagSIZE *psizl;
  UINT UVar9;
  tagRECT *ptVar10;
  int local_420 [16];
  int local_3e0 [16];
  HDC local_3a0;
  tagPAINTSTRUCT local_39c;
  int local_35c;
  int local_358;
  tagRECT local_354;
  int local_344;
  int local_340;
  HDC local_33c;
  HGDIOBJ local_338;
  tagRECT local_334;
  tagRECT local_324;
  CHAR local_314 [100];
  HWND local_2b0;
  int local_2ac;
  HDC local_2a8;
  WPARAM local_2a4 [16];
  WPARAM local_264 [16];
  uint32_t local_224;
  uint32_t local_220;
  int local_21c;
  int local_218;
  tagRECT local_214;
  int local_204;
  WPARAM local_200;
  HDC local_1fc;
  int local_1f8;
  int local_1f4;
  HGDIOBJ local_1f0;
  tagSIZE local_1ec;
  char local_1e4 [264];
  uint32_t local_dc [50];
  tagRECT player_idx;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_33c = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_324);
      local_338 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_33c,local_338);
      SetTextColor(local_33c,0);
      SetBkMode(local_33c,1);
      if (DAT_005168e0 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_33c,&local_324,hbr);
      }
      else {
        FUN_004709ae((int)local_33c,(int)&local_324,DAT_005168e0);
      }
      ptVar10 = &local_334;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      GetWindowRect(pHVar4,ptVar10);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_334,2);
      FUN_004709ae((int)local_33c,(int)&local_334,DAT_005168e8);
      GetDlgItemTextA(hwnd,0x43a,local_314,100);
      local_334.left =
           local_334.left +
           ((int)((local_334.bottom - local_334.top) +
                 (local_334.bottom - local_334.top >> 0x1f & 3U)) >> 2);
      DrawTextA(local_33c,local_314,-1,&local_334,0x24);
      ptVar10 = &local_334;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      GetWindowRect(pHVar4,ptVar10);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_334,2);
      FUN_004709ae((int)local_33c,(int)&local_334,DAT_005168e8);
      GetDlgItemTextA(hwnd,0x43b,local_314,100);
      local_334.left =
           local_334.left +
           ((int)((local_334.bottom - local_334.top) +
                 (local_334.bottom - local_334.top >> 0x1f & 3U)) >> 2);
      DrawTextA(local_33c,local_314,-1,&local_334,0x24);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      local_3a0 = BeginPaint(hwnd,&local_39c);
      if (local_3a0 != (HDC)0x0) {
        FUN_004707a4(local_3a0);
        FUN_00448897((int)local_420,&local_344,(int)local_3e0,&local_35c);
        if (local_344 != 0) {
          for (local_358 = 0; local_358 < local_344; local_358 = local_358 + 1) {
            FUN_0043c2dd(&local_354,hwnd,1,local_358);
            local_340 = local_420[local_358];
            Palette_Subsystem_0049c7c7
                      (local_3a0,&local_354.left,(int32_t *)(&DAT_00618ac0 + local_340 * 0x98),0,
                       0x12,0);
          }
        }
        if (local_35c != 0) {
          for (local_358 = 0; local_358 < local_35c; local_358 = local_358 + 1) {
            FUN_0043c2dd(&local_354,hwnd,0,local_358);
            local_340 = local_3e0[local_358];
            Palette_Subsystem_0049c7c7
                      (local_3a0,&local_354.left,(int32_t *)(&DAT_00618ac0 + local_340 * 0x98),0,
                       0x12,0);
          }
        }
        EndPaint(hwnd,&local_39c);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      val_8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43c);
      ShowWindow(pHVar4,val_8);
      val_8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x439);
      ShowWindow(pHVar4,val_8);
      val_8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      ShowWindow(pHVar4,val_8);
      val_8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      ShowWindow(pHVar4,val_8);
      _sprintf(local_1e4,s__s_WINBK_Ante_pic_004f7848,&DAT_006189a0);
      DAT_005168e0 = (HANDLE)Pic_LoadKimPicture(local_1e4);
      _sprintf(local_1e4,s__s_WINBK_AnteLabel_pic_004f785c,&DAT_006189a0);
      DAT_005168e8 = (HANDLE)Pic_LoadKimPicture(local_1e4);
      DAT_005168e4 = 0;
      FUN_00448412((char *)local_dc);
      FUN_004d9640(local_dc,(uint32_t *)s_ante__004f7874);
      SetDlgItemTextA(hwnd,0x43a,(LPCSTR)local_dc);
      Mem_AllocOrFree_004d9630(local_dc,(uint32_t *)s_Your_ante__004f787c);
      SetDlgItemTextA(hwnd,0x43b,(LPCSTR)local_dc);
      local_1fc = GetDC(hwnd);
      FUN_004707a4(local_1fc);
      local_1f0 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_1fc,local_1f0);
      GetDlgItemTextA(hwnd,0x43a,(LPSTR)local_dc,200);
      psizl = &local_1ec;
      c = _strlen((char *)local_dc);
      GetTextExtentPoint32A(local_1fc,(LPCSTR)local_dc,c,psizl);
      val_8 = local_1ec.cy + local_1ec.cx;
      val_1 = (local_1ec.cy * 3) / 2;
      UVar9 = 6;
      val_7 = 0;
      val_6 = 0;
      pHVar5 = (HWND)0x0;
      local_1f8 = val_1;
      local_1f4 = val_8;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      SetWindowPos(pHVar4,pHVar5,val_6,val_7,val_8,val_1,UVar9);
      UVar9 = 6;
      val_7 = 0;
      val_6 = 0;
      pHVar5 = (HWND)0x0;
      val_8 = local_1f4;
      val_1 = local_1f8;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      SetWindowPos(pHVar4,pHVar5,val_6,val_7,val_8,val_1,UVar9);
      ReleaseDC(hwnd,local_1fc);
      GetWindowRect(hwnd,&player_idx);
      UVar9 = 5;
      val_6 = 0;
      val_1 = 0;
      val_8 = GetSystemMetrics(0);
      SetWindowPos(hwnd,(HWND)0x0,(val_8 * 0x14) / 100,player_idx.top,val_1,val_6,UVar9);
      SetFocus(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x100) {
LAB_0043bb82:
      FUN_00471395(DAT_005168e0);
      FUN_00471395(DAT_005168e8);
      EndDialog(hwnd,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_2a8 = wParam;
      FUN_004707a4(wParam);
      local_2b0 = lParam;
      local_2ac = GetDlgCtrlID(lParam);
      SetBkMode(local_2a8,1);
      SetTextColor(local_2a8,DAT_005168e4);
      buf_ptr_3 = GetStockObject(5);
      return buf_ptr_3;
    }
    if (uMsg == 0x111) goto LAB_0043bb82;
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      buf_ptr_3 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return buf_ptr_3;
    }
    if (uMsg != 0x200) {
      if (uMsg == 0x201) {
        FUN_00471395(DAT_005168e0);
        FUN_00471395(DAT_005168e8);
        EndDialog(hwnd,0);
        return (HGDIOBJ)0x1;
      }
      if (uMsg != 0x204) {
        return (HGDIOBJ)0x0;
      }
    }
    FUN_00448897((int)local_2a4,&local_204,(int)local_264,&local_21c);
    local_224 = (uint32_t)lParam & 0xffff;
    local_220 = (uint32_t)lParam >> 0x10;
    if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
      local_200 = 0xffffffff;
      if (local_21c != 0) {
        while ((local_218 = local_21c + -1, -1 < local_218 && (local_200 == 0xffffffff))) {
          FUN_0043c2dd(&local_214,hwnd,0,local_218);
          pt.y = local_220;
          pt.x = local_224;
          BVar2 = PtInRect(&local_214,pt);
          local_21c = local_218;
          if (BVar2 != 0) {
            local_200 = local_264[local_218];
          }
        }
      }
      if (local_204 != 0) {
        while ((local_218 = local_204 + -1, -1 < local_218 && (local_200 == 0xffffffff))) {
          FUN_0043c2dd(&local_214,hwnd,1,local_218);
          pt_00.y = local_220;
          pt_00.x = local_224;
          BVar2 = PtInRect(&local_214,pt_00);
          local_204 = local_218;
          if (BVar2 != 0) {
            local_200 = local_2a4[local_218];
          }
        }
      }
      if (local_200 != 0xffffffff) {
        SendMessageA(DAT_006152e0,0x401,local_200,0);
      }
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: FUN_0043c2dd
 * Entry Point: 0043c2dd
 * Size: 496 bytes
 */


void FUN_0043c2dd(LPRECT arg_1,HWND hwnd,int width,int height)

{
  HWND pHVar1;
  tagRECT *ptVar2;
  uint8_t local_c4 [64];
  uint8_t local_84 [64];
  int local_44;
  int local_40;
  tagRECT local_3c;
  tagRECT local_2c;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  FUN_00448897((int)local_c4,&target_idx,(int)local_84,&color_idx);
  ptVar2 = &local_3c;
  pHVar1 = GetDlgItem(hwnd,0x43c);
  GetWindowRect(pHVar1,ptVar2);
  MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_3c,2);
  ptVar2 = &local_2c;
  pHVar1 = GetDlgItem(hwnd,0x439);
  GetWindowRect(pHVar1,ptVar2);
  MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_2c,2);
  local_44 = local_3c.right - local_3c.left;
  GetClientRect(hwnd,&player_idx);
  player_idx.left = local_3c.left;
  if (width == 0) {
    if ((color_idx < 1) || (color_idx <= height)) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      for (local_40 = (local_44 * 0x3c) / 100;
          (player_idx.right - local_3c.left < (color_idx + -1) * local_40 + local_44 &&
          ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
      }
      CopyRect(arg_1,&local_2c);
      OffsetRect(arg_1,local_40 * height,0);
    }
  }
  else if ((target_idx < 1) || (target_idx <= height)) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    for (local_40 = (local_44 * 0x3c) / 100;
        (player_idx.right - local_3c.left < (target_idx + -1) * local_40 + local_44 &&
        ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
    }
    CopyRect(arg_1,&local_3c);
    OffsetRect(arg_1,local_40 * height,0);
  }
  return;
}



/*
 * Decompiled function: Ai_CalcManaRequirement_004b9284
 * Entry Point: 0043c4d0
 * Size: 2423 bytes
 */


size_t Ai_CalcManaRequirement_004b9284(char *filepath)

{
  char *char_ptr_1;
  int val_2;
  size_t len_3;
  int local_414;
  int local_410;
  int local_40c;
  uint32_t local_408 [250];
  char *loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  size_t card_idx;
  int match_count;
  FILE *slot_idx;
  
  slot_idx = _fopen(str_1,&DAT_004f7888);
  if (slot_idx == (FILE *)0x0) {
    len_3 = 0;
  }
  else {
    _fread(&DAT_0061743c,4,1,slot_idx);
    _fread(&card_idx,4,1,slot_idx);
    DAT_0060cc68 = _malloc(card_idx);
    if (DAT_0060cc68 == (void *)0x0) {
      _fclose(slot_idx);
      len_3 = 0;
    }
    else {
      _fread(&DAT_00618ac0,0x98,DAT_0061743c,slot_idx);
      _fread(DAT_0060cc68,1,card_idx,slot_idx);
      _fclose(slot_idx);
      for (match_count = 0; match_count < (int)DAT_0061743c; match_count = match_count + 1) {
        *(int *)(&DAT_00618ac4 + match_count * 0x98) =
             *(int *)(&DAT_00618ac4 + match_count * 0x98) + (int)DAT_0060cc68;
        *(int *)(&DAT_00618ac8 + match_count * 0x98) =
             *(int *)(&DAT_00618ac8 + match_count * 0x98) + (int)DAT_0060cc68;
        *(int *)(&DAT_00618b34 + match_count * 0x98) =
             *(int *)(&DAT_00618b34 + match_count * 0x98) + (int)DAT_0060cc68;
        *(int *)(&DAT_00618b38 + match_count * 0x98) =
             *(int *)(&DAT_00618b38 + match_count * 0x98) + (int)DAT_0060cc68;
        val_2 = __strcmpi(*(char **)(&DAT_00618b34 + match_count * 0x98),&DAT_004f788c);
        if (val_2 == 0) {
          *(uint8_t **)(&DAT_00618b34 + match_count * 0x98) = &DAT_004f7894;
        }
        val_2 = __strcmpi(*(char **)(&DAT_00618b38 + match_count * 0x98),&DAT_004f7898);
        if ((val_2 == 0) ||
           (val_2 = __strcmpi(*(char **)(&DAT_00618b38 + match_count * 0x98),s_Blank_004f78a0),
           val_2 == 0)) {
          *(uint8_t **)(&DAT_00618b38 + match_count * 0x98) = &DAT_004f78a8;
        }
        *(uint8_t **)(&DAT_00618b00 + match_count * 0x98) =
             (&PTR_DAT_004f58e8)[*(int *)(&DAT_00618b00 + match_count * 0x98)];
        if (*(int *)(&DAT_00618b04 + match_count * 0x98) == 0) {
          *(int32_t *)(&DAT_00618b04 + match_count * 0x98) = 1;
        }
        for (player_idx = 0; player_idx < *(int *)(&DAT_00618b04 + match_count * 0x98);
            player_idx = player_idx + 1) {
          *(int *)(&DAT_00618b0c + player_idx * 4 + match_count * 0x98) =
               *(int *)(&DAT_00618b0c + player_idx * 4 + match_count * 0x98) + (int)DAT_0060cc68;
        }
        *(int32_t *)(&DAT_00618b08 + match_count * 0x98) = 0;
        for (player_idx = 0; player_idx < *(int *)(&DAT_00618b04 + match_count * 0x98);
            player_idx = player_idx + 1) {
          *(int32_t *)(&DAT_00618b20 + player_idx * 4 + match_count * 0x98) = 0;
        }
      }
      for (target_idx = 0; target_idx < (int)DAT_0061743c; target_idx = target_idx + 1) {
        if (((&DAT_00618acc)[target_idx * 0x98] & 0x40) != 0) {
          *(int32_t *)(&DAT_00618acc + target_idx * 0x98) = 0x80;
        }
      }
      for (color_idx = 0; color_idx < (int)DAT_0061743c; color_idx = color_idx + 1) {
        if ((&DAT_00618ae8)[color_idx * 0x98] == '\x11') {
          (&DAT_00618ae8)[color_idx * 0x98] = 10;
        }
      }
      for (local_40c = 0; local_40c < (int)DAT_0061743c; local_40c = local_40c + 1) {
        local_410 = 0;
        for (loop_idx = *(char **)(&DAT_00618b34 + local_40c * 0x98); *loop_idx != '\0';
            loop_idx = loop_idx + 1) {
          if (*loop_idx == '|') {
            char_ptr_1 = loop_idx + 1;
            if (*char_ptr_1 == 'T') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xee;
            }
            else if (*char_ptr_1 == 'B') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xfe;
            }
            else if (*char_ptr_1 == 'U') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xfd;
            }
            else if (*char_ptr_1 == 'W') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xfb;
            }
            else if (*char_ptr_1 == 'G') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xff;
            }
            else if (*char_ptr_1 == 'R') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xfc;
            }
            else if (*char_ptr_1 == 'X') {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0xf0;
            }
            else if ((*char_ptr_1 == '1') && (loop_idx[2] == '0')) {
              loop_idx = loop_idx + 2;
              *(uint8_t *)((int)local_408 + local_410) = 0xef;
            }
            else if ((*char_ptr_1 < '0') || ('9' < *char_ptr_1)) {
              loop_idx = char_ptr_1;
              *(uint8_t *)((int)local_408 + local_410) = 0x7c;
              loop_idx = loop_idx + -1;
            }
            else {
              loop_idx = char_ptr_1;
              *(char *)((int)local_408 + local_410) = *char_ptr_1 + -0x3f;
            }
          }
          else if (((*loop_idx == '\\') && (loop_idx[1] == '\\')) ||
                  ((*loop_idx == '\\' && (loop_idx[1] == 'n')))) {
            loop_idx = loop_idx + 1;
            *(uint8_t *)((int)local_408 + local_410) = 10;
          }
          else {
            *(char *)((int)local_408 + local_410) = *loop_idx;
          }
          local_410 = local_410 + 1;
        }
        *(uint8_t *)((int)local_408 + local_410) = 0;
        Mem_AllocOrFree_004d9630(*(uint32_t **)(&DAT_00618b34 + local_40c * 0x98),local_408);
      }
      for (local_414 = 0; len_3 = DAT_0061743c, local_414 < (int)DAT_0061743c;
          local_414 = local_414 + 1) {
        *(int32_t *)(&DAT_00618b1c + local_414 * 0x98) = 0;
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_black_004f78ac,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) | 2;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),&DAT_004f78b4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) | 4;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_green_004f78bc,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) | 8;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),&DAT_004f78c4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) | 0x10;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_white_004f78c8,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b1c + local_414 * 0x98) | 0x20;
        }
        *(int32_t *)(&DAT_00618b54 + local_414 * 0x98) = 0;
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_swamp_004f78d0,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) | 2;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_island_004f78d8,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) | 4;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_forest_004f78e0,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) | 8;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_mountain_004f78e8,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) | 0x10;
        }
        val_2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_plains_004f78f4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_00618b54 + local_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return len_3;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043ce47
 * Entry Point: 0043ce47
 * Size: 48 bytes
 */


void Mem_AllocOrFree_0043ce47(void)

{
  if (DAT_0060cc68 != 0) {
    FUN_004db150(DAT_0060cc68);
  }
  DAT_0060cc68 = 0;
  return;
}



/*
 * Decompiled function: FUN_0043ce77
 * Entry Point: 0043ce77
 * Size: 594 bytes
 */


int32_t FUN_0043ce77(LPCSTR str_1)

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
  for (match_count = 0; match_count < DAT_0061743c; match_count = match_count + 1) {
    *(uint8_t **)(&DAT_005f7910 + match_count * 0x14) = &DAT_004f78fc;
    *(uint8_t **)(&DAT_005f7914 + match_count * 0x14) = &DAT_004f7900;
    *(uint8_t **)(&DAT_005f7918 + match_count * 0x14) = &DAT_004f7904;
    *(uint8_t **)(&DAT_005f791c + match_count * 0x14) = &DAT_004f7908;
    *(uint8_t **)(&DAT_005f7920 + match_count * 0x14) = &DAT_004f790c;
  }
  color_idx = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (color_idx != (HANDLE)0xffffffff) {
    card_idx = GetFileSize(color_idx,(LPDWORD)0x0);
    DAT_0060161c = _malloc(card_idx + 1);
    if (DAT_0060161c != (char *)0x0) {
      ReadFile(color_idx,DAT_0060161c,card_idx,&player_idx,(LPOVERLAPPED)0x0);
      slot_idx = DAT_0060161c;
      char_ptr_1 = _strchr(DAT_0060161c,10);
      slot_idx = char_ptr_1 + 1;
      for (match_count = 0; match_count < DAT_0061743c; match_count = match_count + 1) {
        _sscanf(slot_idx,&DAT_004f7910,loop_idx);
        slot_idx = (char *)FUN_0043d0f9(&slot_idx);
        slot_idx = (char *)FUN_0043d0f9(&slot_idx);
        char_ptr_1 = (char *)FUN_0043d0f9(&slot_idx);
        *(char **)(&DAT_005f7910 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_0043d0f9(&slot_idx);
        *(char **)(&DAT_005f7914 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_0043d0f9(&slot_idx);
        *(char **)(&DAT_005f7918 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_0043d0f9(&slot_idx);
        *(char **)(&DAT_005f791c + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
        char_ptr_1 = (char *)FUN_0043d0f9(&slot_idx);
        *(char **)(&DAT_005f7920 + match_count * 0x14) = slot_idx;
        slot_idx = char_ptr_1;
      }
      target_idx = 1;
    }
    CloseHandle(color_idx);
  }
  return target_idx;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043d0c9
 * Entry Point: 0043d0c9
 * Size: 48 bytes
 */


void Mem_AllocOrFree_0043d0c9(void)

{
  if (DAT_0060161c != 0) {
    FUN_004db150(DAT_0060161c);
  }
  DAT_0060161c = 0;
  return;
}



/*
 * Decompiled function: FUN_0043d0f9
 * Entry Point: 0043d0f9
 * Size: 202 bytes
 */


char * FUN_0043d0f9(int32_t *arg_1)

{
  char *char_ptr_1;
  char *player_idx;
  char *slot_idx;
  
  slot_idx = (char *)*arg_1;
  if (*slot_idx == '\"') {
    slot_idx = slot_idx + 1;
    player_idx = _strchr(slot_idx,0x22);
    *player_idx = '\0';
    if (player_idx[1] == ',') {
      player_idx = player_idx + 2;
    }
    else {
      player_idx = player_idx + 3;
    }
  }
  else {
    player_idx = _strchr(slot_idx,0x2c);
    char_ptr_1 = _strchr(slot_idx,0xd);
    if (player_idx < char_ptr_1) {
      *player_idx = '\0';
      player_idx = player_idx + 1;
    }
    else {
      *char_ptr_1 = '\0';
      player_idx = char_ptr_1 + 2;
    }
  }
  *arg_1 = slot_idx;
  return player_idx;
}



/*
 * Decompiled function: FUN_0043d1d0
 * Entry Point: 0043d1d0
 * Size: 559 bytes
 */


uint8_t * FUN_0043d1d0(int player_id,int card_slot,int event_type)

{
  int val_1;
  DWORD dwMaximumSizeLow;
  int32_t uval_2;
  HANDLE buf_ptr_3;
  HDC pHVar4;
  HBITMAP pHVar5;
  uint8_t *puVar6;
  uint32_t uval_7;
  
  *(int *)(PTR_DAT_004f7914 + 0x20) = arg_1;
  *(int *)(PTR_DAT_004f7914 + 0x24) = arg_2;
  *(int *)(PTR_DAT_004f7914 + 0x28) = arg_3;
  val_1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
  uval_7 = val_1 >> 0x1f;
  if (((val_1 >> 3 ^ uval_7) - uval_7 & 3 ^ uval_7) == uval_7) {
    *(int32_t *)(PTR_DAT_004f7914 + 0x2c) = 0;
  }
  else {
    val_1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
    uval_7 = val_1 >> 0x1f;
    *(uint32_t *)(PTR_DAT_004f7914 + 0x2c) = 4 - (((val_1 >> 3 ^ uval_7) - uval_7 & 3 ^ uval_7) - uval_7);
  }
  val_1 = (*(int *)(PTR_DAT_004f7914 + 0x2c) + arg_1) * arg_2 * arg_3;
  dwMaximumSizeLow = ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 0x10;
  *(DWORD *)(PTR_DAT_004f7914 + 0x1c) = dwMaximumSizeLow;
  uval_2 = FUN_0047f7d3(arg_1,arg_2,arg_3);
  *(int32_t *)(PTR_DAT_004f7914 + 0x10) = uval_2;
  if (*(int *)(PTR_DAT_004f7914 + 0x10) == 0) {
    puVar6 = (uint8_t *)0x0;
  }
  else {
    buf_ptr_3 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                dwMaximumSizeLow,(LPCSTR)0x0);
    *(HANDLE *)PTR_DAT_004f7914 = buf_ptr_3;
    if (*(int *)PTR_DAT_004f7914 == 0) {
      Mem_AllocOrFree_0047f8f7(*(int32_t *)(PTR_DAT_004f7914 + 0x10));
      puVar6 = (uint8_t *)0x0;
    }
    else {
      pHVar4 = GetDC((HWND)0x0);
      *(HDC *)(PTR_DAT_004f7914 + 4) = pHVar4;
      FUN_004707a4(*(HDC *)(PTR_DAT_004f7914 + 4));
      pHVar5 = CreateDIBSection(*(HDC *)(PTR_DAT_004f7914 + 4),
                                *(BITMAPINFO **)(PTR_DAT_004f7914 + 0x10),(uint32_t)(arg_3 == 8),
                                (void **)(PTR_DAT_004f7914 + 0x18),*(HANDLE *)PTR_DAT_004f7914,0);
      *(HBITMAP *)(PTR_DAT_004f7914 + 8) = pHVar5;
      ReleaseDC((HWND)0x0,*(HDC *)(PTR_DAT_004f7914 + 4));
      if (*(int *)(PTR_DAT_004f7914 + 8) == 0) {
        Mem_AllocOrFree_0047f8f7(*(int32_t *)(PTR_DAT_004f7914 + 0x10));
        CloseHandle(*(HANDLE *)PTR_DAT_004f7914);
        puVar6 = (uint8_t *)0x0;
      }
      else {
        Mem_AllocOrFree_0047f8f7(*(int32_t *)(PTR_DAT_004f7914 + 0x10));
        puVar6 = PTR_DAT_004f7914;
      }
    }
  }
  return puVar6;
}



