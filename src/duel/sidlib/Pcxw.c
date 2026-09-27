/*
 * sidlib/Pcxw.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 72
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: FUN_0044c1e0
 * Entry Point: 0044c1e0
 * Size: 535 bytes
 */


uint8_t * FUN_0044c1e0(char *filepath,uint8_t *arg_2,void *arg_3)

{
  uint8_t *u_ptr_1;
  uint32_t uval_2;
  int val_3;
  HGLOBAL pvVar4;
  uint32_t uval_5;
  int target_idx;
  int player_idx;
  int slot_idx;
  
  DAT_00694430 = _fopen(str_1,&DAT_004f817c);
  File_Load_Assertfile
            ((uint32_t)(DAT_00694430 != (FILE *)0x0),
             (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x69,
             s_Error_Opening_File__s_004f8164);
  DAT_00694438 = str_1;
  FUN_0044c47a(arg_3);
  if ((DAT_00694443 == '\b') && (DAT_00694481 == '\x01')) {
    target_idx = 1;
  }
  else {
    target_idx = 0;
  }
  File_Load_Assertfile
            (target_idx,(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x6f,
             s__s_Not_a_256_color_palettized_pc_004f8180);
  uval_2 = 4 - (DAT_004ff154 & 3);
  uval_5 = (int)uval_2 >> 0x1f;
  val_3 = ((uval_2 ^ uval_5) - uval_5 & 3 ^ uval_5) - uval_5;
  if ((DAT_004f8138 == DAT_004ff154) && (DAT_004f813c == DAT_004ff158)) {
    _memset(arg_2,0,(DAT_004f8138 + val_3) * DAT_004f813c);
  }
  else {
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalFree(pvVar4);
    pvVar4 = GlobalAlloc(0x40,(val_3 + DAT_004ff154) * DAT_004ff158);
    arg_2 = GlobalLock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalLock(pvVar4);
    DAT_004f8138 = DAT_004ff154;
    DAT_004f813c = DAT_004ff158;
  }
  u_ptr_1 = arg_2;
  for (slot_idx = 0; slot_idx < DAT_004ff158; slot_idx = slot_idx + 1) {
    FUN_0044c660(&DAT_00693430);
    for (player_idx = 0; player_idx < (int)DAT_004ff154; player_idx = player_idx + 1) {
      *arg_2 = (&DAT_00693430)[player_idx];
      arg_2 = arg_2 + 1;
    }
    arg_2 = arg_2 + val_3;
  }
  _fclose(DAT_00694430);
  return u_ptr_1;
}



/*
 * Decompiled function: FUN_0044c3f7
 * Entry Point: 0044c3f7
 * Size: 131 bytes
 */


bool FUN_0044c3f7(char *filepath,void *arg2)

{
  int val_1;
  
  DAT_00694430 = _fopen(str_1,&DAT_004f81c4);
  File_Load_Assertfile
            ((uint32_t)(DAT_00694430 != (FILE *)0x0),
             (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x9c,
             s_Error_Opening_File__s_004f81ac);
  DAT_00694438 = str_1;
  val_1 = FUN_0044c47a(arg2);
  if (val_1 != 0) {
    _fclose(DAT_00694430);
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_0044c47a
 * Entry Point: 0044c47a
 * Size: 486 bytes
 */


int32_t FUN_0044c47a(void *arg_1)

{
  int slot_idx;
  
  _fread(&DAT_00694440,0x80,1,DAT_00694430);
  File_Load_Assertfile
            ((uint32_t)(DAT_00694440 == '\n'),(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0xad,
             s__s_Not_a_pcx_file_004f81c8);
  File_Load_Assertfile
            ((uint32_t)(DAT_00694441 == '\x05'),(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,
             0xae,s__s_Not_a_version_5_pcx_file_004f81dc);
  DAT_004ff154 = ((uint32_t)DAT_00694448 - (uint32_t)DAT_00694444) + 1;
  DAT_004ff158 = ((uint32_t)DAT_0069444a - (uint32_t)DAT_00694446) + 1;
  if (arg_1 != (void *)0x0) {
    if ((DAT_00694481 == '\x01') && (DAT_00694443 == '\b')) {
      _fseek(DAT_00694430,-0x300,2);
      _fread(arg_1,1,0x300,DAT_00694430);
      _fseek(DAT_00694430,0x80,0);
    }
    else if ((DAT_00694481 == '\x04') && (DAT_00694443 == '\x01')) {
      _fseek(DAT_00694430,0x10,2);
      for (slot_idx = 0; slot_idx < 0x10; slot_idx = slot_idx + 1) {
        _fread((void *)(slot_idx * 4 + (int)arg_1),1,3,DAT_00694430);
      }
      _fseek(DAT_00694430,0x80,0);
    }
    else {
      File_Load_Assertfile
                (0,(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0xd4,
                 s__s_is_not_in_a_recognizable_form_004f81fc);
    }
  }
  return 1;
}



/*
 * Decompiled function: FUN_0044c660
 * Entry Point: 0044c660
 * Size: 220 bytes
 */


int32_t FUN_0044c660(uint8_t *arg_1)

{
  uint32_t uval_1;
  int val_2;
  int target_idx;
  uint32_t card_idx;
  
  target_idx = (int)DAT_00694482;
  while (0 < target_idx) {
    uval_1 = _fgetc(DAT_00694430);
    if (((uint8_t)uval_1 & 0xc0) == 0xc0) {
      uval_1 = uval_1 & 0x3f;
      val_2 = _fgetc(DAT_00694430);
      if (uval_1 < 2) {
        *arg_1 = (uint8_t)val_2;
        arg_1 = arg_1 + 1;
        target_idx = target_idx + -1;
      }
      else {
        for (card_idx = 0; card_idx < uval_1; card_idx = card_idx + 1) {
          *arg_1 = (uint8_t)val_2;
          arg_1 = arg_1 + 1;
        }
        target_idx = target_idx - uval_1;
      }
    }
    else {
      *arg_1 = (uint8_t)uval_1;
      arg_1 = arg_1 + 1;
      target_idx = target_idx + -1;
    }
  }
  return 1;
}



/*
 * Decompiled function: FUN_0044c73c
 * Entry Point: 0044c73c
 * Size: 240 bytes
 */


int32_t
FUN_0044c73c(uint8_t *arg_1,char *mode_str,void *arg_3,int32_t arg_4,int32_t arg_5,int arg_6,
            int arg_7)

{
  int local_100c;
  char local_1008 [4064];
  int32_t uStackY_28;
  
  Mem_AllocOrFree_004ddee0();
  DAT_00694434 = _fopen(str_2,&DAT_004f823c);
  uStackY_28 = 0x44c78a;
  File_Load_Assertfile
            ((uint32_t)(DAT_00694434 != (FILE *)0x0),
             (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x146,
             s_Error_Opening_File__s_004f8224);
  DAT_00694438 = str_2;
  FUN_0044c82c(arg_6,(short)arg_7);
  for (local_100c = 0; local_100c < arg_7; local_100c = local_100c + 1) {
    uStackY_28 = 0x44c7eb;
    Mem_AllocOrFree_0043d863();
    FUN_0044c8f0(local_1008,arg_6);
  }
  FUN_0044caaf(arg_3);
  _fclose(DAT_00694434);
  return 0;
}



/*
 * Decompiled function: FUN_0044c82c
 * Entry Point: 0044c82c
 * Size: 196 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_0044c82c(int32_t arg1,short arg2)

{
  uint16_t uval_1;
  uint16_t uval_2;
  
  DAT_00694440 = 10;
  DAT_00694441 = 5;
  DAT_00694442 = 1;
  DAT_00694443 = 8;
  DAT_00694444 = 0;
  uval_1 = (uint16_t)arg1;
  DAT_00694448 = uval_1 - 1;
  DAT_00694446 = 0;
  DAT_0069444a = arg2 + -1;
  _DAT_0069444c = 0;
  _DAT_0069444e = 0;
  DAT_00694480 = 0;
  DAT_00694481 = 1;
  uval_2 = (uint16_t)((int)arg1 >> 0x1f);
  DAT_00694482 = uval_1 + (((uval_1 ^ uval_2) - uval_2 & 1 ^ uval_2) - uval_2);
  _DAT_00694484 = 1;
  _DAT_00694486 = 0;
  _DAT_00694488 = 0;
  FID_conflict___fwrite_lk(&DAT_00694440,0x80,1,DAT_00694434);
  return 0;
}



/*
 * Decompiled function: FUN_0044c8f0
 * Entry Point: 0044c8f0
 * Size: 275 bytes
 */


int32_t FUN_0044c8f0(char *filepath,int arg2)

{
  uint8_t arg_1;
  int event_type;
  int player_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  slot_idx = slot_idx & 0xffffff00;
  player_idx = 0;
  while (player_idx < arg2) {
    arg_1 = *str_1;
    slot_idx = CONCAT31(slot_idx._1_3_,arg_1);
    if ((arg2 - player_idx == 1) || (str_1[1] != arg_1)) {
      FUN_0044ca03(arg_1);
      player_idx = player_idx + 1;
      str_1 = str_1 + 1;
    }
    else {
      arg_3 = arg2 - player_idx;
      if (0x3e < arg_3) {
        arg_3 = 0x3f;
      }
      match_count = FUN_0044ca50(arg_1,str_1,arg_3);
      player_idx = player_idx + match_count;
      str_1 = str_1 + match_count;
      match_count = match_count | 0xc0;
      FID_conflict___fwrite_lk(&match_count,1,1,DAT_00694434);
      FID_conflict___fwrite_lk(&slot_idx,1,1,DAT_00694434);
    }
  }
  if (player_idx < DAT_00694482) {
    slot_idx = (uint32_t)slot_idx._1_3_ << 8;
    FID_conflict___fwrite_lk(&slot_idx,1,1,DAT_00694434);
  }
  return 1;
}



/*
 * Decompiled function: FUN_0044ca03
 * Entry Point: 0044ca03
 * Size: 77 bytes
 */


void FUN_0044ca03(uint8_t arg_1)

{
  uint8_t slot_idx [4];
  
  slot_idx[0] = 0xc1;
  if ((arg_1 & 0xc0) == 0xc0) {
    FID_conflict___fwrite_lk(slot_idx,1,1,DAT_00694434);
  }
  FID_conflict___fwrite_lk(&arg_1,1,1,DAT_00694434);
  return;
}



/*
 * Decompiled function: FUN_0044ca50
 * Entry Point: 0044ca50
 * Size: 95 bytes
 */


int FUN_0044ca50(char arg_1,char *mode_str,int event_type)

{
  int slot_idx;
  
  slot_idx = 0;
  while ((arg_3 != 0 && (*str_2 == arg_1))) {
    slot_idx = slot_idx + 1;
    str_2 = str_2 + 1;
    arg_3 = arg_3 + -1;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0044caaf
 * Entry Point: 0044caaf
 * Size: 72 bytes
 */


int32_t FUN_0044caaf(void *arg_1)

{
  uint8_t slot_idx [4];
  
  slot_idx[0] = 0xc;
  FID_conflict___fwrite_lk(slot_idx,1,1,DAT_00694434);
  FID_conflict___fwrite_lk(arg_1,3,0x100,DAT_00694434);
  return 0;
}



/*
 * Decompiled function: UI_LoadPhaseBackdrop
 * Entry Point: 0044cb00
 * Size: 248 bytes
 */


int32_t UI_LoadPhaseBackdrop(LPCSTR str_1)

{
  ATOM AVar1;
  uint32_t local_138 [66];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_PhaseDisplayWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00516b78 = CreatePopupMenu();
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138, (uint32_t *)s__WINBK_Phase_pic_004f8240);
  DAT_00516b58 = Pic_LoadKimPicture((char *)local_138);
  DAT_00516bb0 = 2;
  DAT_00516b74 = CreateHatchBrush(3,0x808080);
  return local_30;
}



/*
 * Decompiled function: FUN_0044cbf8
 * Entry Point: 0044cbf8
 * Size: 118 bytes
 */


void FUN_0044cbf8(void)

{
  if (DAT_00516b78 != (HMENU)0x0) {
    DestroyMenu(DAT_00516b78);
  }
  DAT_00516b78 = (HMENU)0x0;
  if (DAT_00516b58 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_00516b58);
  }
  if (DAT_00516b74 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00516b74);
  }
  DAT_00516b58 = (HANDLE)0x0;
  DAT_00516b74 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_LoadPhaseCombatBackdrop
 * Entry Point: 0044cc6e
 * Size: 209 bytes
 */


int32_t UI_LoadPhaseCombatBackdrop(LPCSTR str_1)

{
  ATOM AVar1;
  uint32_t local_138 [66];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_CombatDefenseWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138, (uint32_t *)s__WINBK_PhaseCombat_pic_004f8254);
  DAT_00516b70 = Pic_LoadKimPicture((char *)local_138);
  return local_30;
}



/*
 * Decompiled function: Mem_AllocOrFree_0044cd3f
 * Entry Point: 0044cd3f
 * Size: 48 bytes
 */


void Mem_AllocOrFree_0044cd3f(void)

{
  if (DAT_00516b70 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_00516b70);
  }
  DAT_00516b70 = (HANDLE)0x0;
  return;
}



/*
 * Decompiled function: UI_PhaseDisplayWndProc
 * Entry Point: 0044cd6f
 * Size: 4970 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT UI_PhaseDisplayWndProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam)

{
  bool flag_1;
  uint32_t uval_2;
  UINT dwMilliseconds;
  HBRUSH pHVar3;
  int val_4;
  LRESULT LVar5;
  int local_5b4;
  int local_5b0;
  int local_5ac [38];
  tagPOINT local_514;
  UINT_PTR local_50c;
  int local_508;
  int local_504;
  UINT_PTR local_500;
  int local_4fc;
  UINT_PTR local_4f8;
  tagRECT local_4f4;
  tagPOINT local_4e4;
  tagRECT local_4dc;
  int local_4cc;
  uint32_t local_4c8 [66];
  HRGN local_3c0;
  HDC local_3bc;
  int local_3b8;
  uint8_t local_3b4 [4];
  int local_3b0;
  int local_3ac;
  tagPAINTSTRUCT local_39c;
  int local_35c;
  tagRECT local_358;
  int local_348;
  tagRECT local_344;
  tagMSG local_334;
  uint32_t local_318;
  BOOL local_314;
  POINT local_310;
  tagRECT local_308;
  int local_2f8;
  uint32_t local_2f4 [66];
  ULONG_PTR local_1ec;
  int local_1e8;
  uint32_t local_1e4;
  tagRECT local_1e0;
  tagRECT local_1d0;
  int local_1c0;
  uint32_t local_1bc;
  int local_1b8;
  uint32_t local_1b4;
  int local_1b0;
  int local_1ac;
  uint32_t local_1a8 [66];
  ULONG_PTR local_a0;
  int local_9c;
  int local_98;
  uint32_t local_94 [25];
  int local_30;
  POINT local_2c;
  int local_24;
  int loop_idx;
  tagRECT color_idx;
  LONG match_count;
  LONG slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      match_count = GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      FUN_0044897a(&local_348,&local_3b8);
      if ((match_count != local_3b8) || (slot_idx != local_348)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (DAT_00516b58 == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_4c8,(uint32_t *)&g_DuelAssetDirectory);
        Str_CopyFast(local_4c8,(uint32_t *)s__WINBK_Phase_pic_004f833c);
        DAT_00516b58 = (HANDLE)Pic_LoadKimPicture((char *)local_4c8);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_3bc = DAT_0060157c;
      local_35c = SaveDC(DAT_0060157c);
      GetClientRect(hwnd,&local_344);
      if (DAT_00516b58 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(4);
        FillRect(local_3bc,&local_344,pHVar3);
      }
      else {
        GetObjectA(DAT_00516b58,0x18,local_3b4);
        FUN_00470a16(local_3bc,&local_344.left,DAT_00516b58,0,0,local_3b0 / DAT_00516bb0,local_3ac);
      }
      if ((local_348 != -1) && (local_3b8 != -1)) {
        FUN_0044e52d(&local_358,local_348,local_3b8,local_344.right,local_344.bottom);
        local_3c0 = CreateRectRgnIndirect(&local_358);
        SelectClipRgn(local_3bc,local_3c0);
        if (DAT_00516b58 == (HANDLE)0x0) {
          pHVar3 = GetStockObject(2);
          FillRect(local_3bc,&local_344,pHVar3);
        }
        else {
          GetObjectA(DAT_00516b58,0x18,local_3b4);
          FUN_00470a16(local_3bc,&local_344.left,DAT_00516b58,local_3b0 - local_3b0 / DAT_00516bb0,0
                       ,local_3b0 / DAT_00516bb0,local_3ac);
        }
        SelectClipRgn(local_3bc,(HRGN)0x0);
        DeleteObject(local_3c0);
      }
      RestoreDC(DAT_0060157c,local_35c);
      FUN_0044e776(local_3bc,(int)&local_344);
      local_3bc = BeginPaint(hwnd,&local_39c);
      if (local_3bc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_3bc);
        GetClientRect(hwnd,&local_344);
        if (DAT_00601580 != 0) {
          pHVar3 = GetStockObject(0);
          FillRect(local_3bc,&local_344,pHVar3);
          Sleep(200);
        }
        BitBlt(local_3bc,0,0,local_344.right,local_344.bottom,DAT_0060157c,0,0,0xcc0020);
        FUN_00448a38(&local_4cc);
        if (local_4cc != -1) {
          if (local_4cc == 0) {
            local_344.bottom = local_344.bottom - (local_344.bottom - local_344.top) / 2;
          }
          else {
            local_344.top = local_344.top + (local_344.bottom - local_344.top) / 2;
          }
          SelectObject(local_3bc,DAT_00516b74);
          SetBkMode(local_3bc,1);
          Rectangle(local_3bc,local_344.left,local_344.top,local_344.right,local_344.bottom);
        }
        EndPaint(hwnd,&local_39c);
        match_count = local_3b8;
        slot_idx = local_348;
        SetWindowLongA(hwnd,0,local_3b8);
        SetWindowLongA(hwnd,4,slot_idx);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      match_count = 0;
      slot_idx = 0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,slot_idx);
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
      GetCursorPos(&local_514);
      ScreenToClient(hwnd,&local_514);
      GetClientRect(hwnd,&local_4f4);
      FUN_0044e141(&local_514,&local_4f4,&local_4fc,&local_5b0);
      if (local_4fc == 1) {
        local_508 = 10;
      }
      else {
        local_508 = 0;
      }
      if (local_5b0 == 1) {
        local_504 = 0;
      }
      else if ((((local_5b0 == 2) || (local_5b0 == 3)) || (local_5b0 == 4)) || (local_5b0 == 5)) {
        local_504 = 1;
      }
      else if (local_5b0 == 10) {
        local_504 = 2;
      }
      else if (local_5b0 == 0x14) {
        local_504 = 3;
      }
      else if ((((local_5b0 == 0x15) || (local_5b0 == 0x16)) ||
               ((local_5b0 == 0x17 || ((local_5b0 == 0x18 || (local_5b0 == 0x19)))))) ||
              ((local_5b0 == 0x1a || (local_5b0 == 0x1b)))) {
        local_504 = 4;
      }
      else if (local_5b0 == 0x1e) {
        local_504 = 5;
      }
      else if (local_5b0 == 0x1f) {
        local_504 = 6;
      }
      else if ((((local_5b0 == 0x20) || (local_5b0 == 0x21)) || (local_5b0 == 0x22)) ||
              (local_5b0 == 0x25)) {
        local_504 = 7;
      }
      else {
        local_504 = -1;
      }
      if (local_5b0 != -1) {
        if (DAT_00618158 != 0) {
          local_500 = local_504 + local_508 + 0x96;
          AppendMenuA(DAT_00516b78,0,local_500,s_Run_to_this_phase_004f8350);
        }
        val_4 = GetMenuItemCount(DAT_00516b78);
        if (val_4 != 0) {
          AppendMenuA(DAT_00516b78,0x800,0,(LPCSTR)0x0);
        }
        local_4f8 = local_504 + local_508 + 200;
        AppendMenuA(DAT_00516b78,0,local_4f8,s_Mark_this_phase_to_always_stop_004f8364);
        FUN_004489c3(local_5ac,local_4fc);
        if (local_5ac[local_5b0] != 0) {
          CheckMenuItem(DAT_00516b78,local_4f8,8);
        }
        local_50c = local_504 + local_508 + 0xfa;
        AppendMenuA(DAT_00516b78,0,local_50c,s_Help_for_this_phase____004f8384);
      }
      AppendMenuA(DAT_00516b78,0,100,s_Help____004f839c);
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 100) {
        local_a0 = 0x7e5;
        Mem_AllocOrFree_004d9630(local_1a8,(uint32_t *)&DAT_005f76e0);
        Str_CopyFast(local_1a8,(uint32_t *)s__duel_hlp_004f8324);
        WinHelpA(g_DuelMainHwnd,(LPCSTR)local_1a8,1,local_a0);
      }
      else {
        uval_2 = wParam & 0xffff;
        if (uval_2 < 0xfa) {
          if (uval_2 < 200) {
            local_1b0 = 0x96;
          }
          else {
            local_1b0 = 200;
          }
        }
        else {
          local_1b0 = 0xfa;
        }
        local_1b8 = uval_2 - local_1b0;
        flag_1 = 9 < local_1b8;
        if (flag_1) {
          local_1b8 = local_1b8 + -10;
        }
        local_1b4 = (uint32_t)flag_1;
        local_1ac = local_1b8;
        if (local_1b0 == 0x96) {
          local_1bc = local_1b4;
          if (local_1b8 == 0) {
            local_1c0 = 1;
          }
          else if (local_1b8 == 1) {
            local_1c0 = 4;
          }
          else if (local_1b8 == 2) {
            local_1c0 = 10;
          }
          else if (local_1b8 == 3) {
            local_1c0 = 0x14;
          }
          else if (local_1b8 == 4) {
            if (local_1b4 == 0) {
              local_1c0 = 0x15;
            }
            else {
              local_1c0 = 0x16;
            }
          }
          else if (local_1b8 == 5) {
            local_1c0 = 0x1e;
          }
          else if (local_1b8 == 6) {
            local_1c0 = 0x1f;
          }
          else if (local_1b8 == 7) {
            local_1c0 = 0x20;
          }
          DAT_0066aac4 = local_1b4;
          DAT_0066ab04 = local_1c0;
          DAT_0066643c = 0;
          _DAT_00516ba0 = 0xfffffffe;
          _DAT_00516ba4 = 0xffffffff;
          _DAT_00516ba8 = 0xffffffff;
          PostMessageA(g_DuelMainHwnd,0x464,0,0x516ba0);
        }
        else if (local_1b0 == 200) {
          local_1e4 = local_1b4;
          if (local_1b8 == 0) {
            local_1e8 = 1;
          }
          else if (local_1b8 == 1) {
            local_1e8 = 4;
          }
          else if (local_1b8 == 2) {
            local_1e8 = 10;
          }
          else if (local_1b8 == 3) {
            local_1e8 = 0x14;
          }
          else if (local_1b8 == 4) {
            if (local_1b4 == 0) {
              local_1e8 = 0x15;
            }
            else {
              local_1e8 = 0x16;
            }
          }
          else if (local_1b8 == 5) {
            local_1e8 = 0x1e;
          }
          else if (local_1b8 == 6) {
            local_1e8 = 0x1f;
          }
          else if (local_1b8 == 7) {
            local_1e8 = 0x20;
          }
          if (((&DAT_006667c0)[local_1e8 * 4 + local_1b4 * 0x98] & 1) == 0) {
            *(uint32_t *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint32_t *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) | 1;
          }
          else {
            *(uint32_t *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint32_t *)(&DAT_006667c0 + local_1e8 * 4 + local_1b4 * 0x98) & 0xfffffffe;
          }
          Rules_ParseFilter_00481890();
          FUN_004457a2();
          GetClientRect(hwnd,&local_1e0);
          FUN_0044e52d(&local_1d0,local_1e4,local_1e8,local_1e0.right,local_1e0.bottom);
          InvalidateRect(hwnd,&local_1d0,0);
        }
        else if (local_1b0 == 0xfa) {
          if (local_1b8 == 0) {
            local_1ec = 0x7da;
          }
          else if (local_1b8 == 1) {
            local_1ec = 0x7db;
          }
          else if (local_1b8 == 2) {
            local_1ec = 0x7dc;
          }
          else if (local_1b8 == 3) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 4) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 5) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 6) {
            local_1ec = 0x7de;
          }
          else if (local_1b8 == 7) {
            local_1ec = 0x7df;
          }
          Mem_AllocOrFree_004d9630(local_2f4,(uint32_t *)&DAT_005f76e0);
          Str_CopyFast(local_2f4,(uint32_t *)s__duel_hlp_004f8330);
          WinHelpA(g_DuelMainHwnd,(LPCSTR)local_2f4,1,local_1ec);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      dwMilliseconds = GetDoubleClickTime();
      Sleep(dwMilliseconds);
      local_314 = PeekMessageA(&local_334,hwnd,0x203,0x203,0);
      local_310.x = lParam & 0xffff;
      local_310.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_308);
      FUN_0044e141(&local_310,&local_308,&local_318,&local_2f8);
      if ((local_2f8 != -1) && (DAT_00618158 != 0)) {
        DAT_0066aac4 = local_318;
        DAT_0066ab04 = local_2f8;
        DAT_0066643c = local_314;
        _DAT_00516b60 = 0xfffffffe;
        _DAT_00516b64 = 0xffffffff;
        _DAT_00516b68 = 0xffffffff;
        PostMessageA(g_DuelMainHwnd,0x464,0,0x516b60);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_5b4 = GetMenuItemCount(DAT_00516b78);
        while (local_5b4 != 0) {
          DeleteMenu(DAT_00516b78,0,0x400);
          local_5b4 = local_5b4 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = GDI_RealizePaletteTree(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_4e4.x = lParam & 0xffff;
      local_4e4.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_4e4);
      SetRect(&local_4dc,local_4e4.x,local_4e4.y,local_4e4.x + 1,local_4e4.y + 1);
      TrackPopupMenu(DAT_00516b78,2,local_4e4.x,local_4e4.y,0,hwnd,&local_4dc);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      Mem_AllocOrFree_0045033a(hwnd,wParam,lParam);
      return 0;
    }
    if (uMsg == 0x432) {
      match_count = GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      FUN_0044897a(&local_98,&local_9c);
      if ((match_count != local_9c) || (slot_idx != local_98)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_2c.x = lParam & 0xffff;
      local_2c.y = lParam >> 0x10;
      GetClientRect(hwnd,&color_idx);
      FUN_0044e141(&local_2c,&color_idx,&loop_idx,&local_30);
      local_24 = 1;
      if (loop_idx == 0) {
        Mem_AllocOrFree_004d9630(local_94,(uint32_t *)s_Your_004f826c);
      }
      else {
        FUN_00448412((char *)local_94);
        Str_CopyFast(local_94,(uint32_t *)&DAT_004f8274);
      }
      switch(local_30) {
      case 1:
        Str_CopyFast(local_94,(uint32_t *)s_Untap_phase_004f8278);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
        Str_CopyFast(local_94,(uint32_t *)s_Upkeep_phase_004f8284);
        break;
      default:
        local_24 = 0;
        break;
      case 10:
        Str_CopyFast(local_94,(uint32_t *)s_Draw_phase_004f8294);
        break;
      case 0x14:
        Str_CopyFast(local_94,(uint32_t *)s_Main_phase__pre_combat__004f82a0);
        break;
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
        if (loop_idx == 1) {
          Str_CopyFast(local_94,(uint32_t *)s_Main_phase__combat__004f82b8);
        }
        else {
          Str_CopyFast(local_94,(uint32_t *)s_Main_phase__declare_attack__004f82cc);
        }
        break;
      case 0x1e:
        Str_CopyFast(local_94,(uint32_t *)s_Main_phase__post_combat__004f82e8);
        break;
      case 0x1f:
        Str_CopyFast(local_94,(uint32_t *)s_Discard_phase_004f8304);
        break;
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x25:
        Str_CopyFast(local_94,(uint32_t *)s_Cleanup_phase_004f8314);
      }
      if (local_24 == 0) {
        return 0;
      }
      Mem_AllocOrFree_004d9630((uint32_t *)wParam,local_94);
      return local_24;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar5;
}



/*
 * Decompiled function: FUN_0044e141
 * Entry Point: 0044e141
 * Size: 1004 bytes
 */


void FUN_0044e141(POINT *x,RECT *arg_2,int32_t *arg_3,int *height)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  POINT pt_09;
  POINT pt_10;
  POINT pt_11;
  POINT pt_12;
  POINT pt_13;
  POINT pt_14;
  BOOL BVar1;
  int32_t local_34;
  tagRECT local_28;
  tagRECT target_idx;
  int slot_idx;
  
  CopyRect(&local_28,arg_2);
  pt_14 = *x;
  pt_13 = *x;
  pt_12 = *x;
  pt_11 = *x;
  pt_10 = *x;
  pt_09 = *x;
  pt_08 = *x;
  pt_07 = *x;
  pt_06 = *x;
  pt_05 = *x;
  pt_04 = *x;
  pt_03 = *x;
  pt_02 = *x;
  pt_01 = *x;
  pt_00 = *x;
  pt = *x;
  slot_idx = -1;
  local_34 = 1;
  FUN_0044e52d(&target_idx,1,1,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt);
  if (BVar1 != 0) {
    slot_idx = 1;
  }
  FUN_0044e52d(&target_idx,1,4,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_00);
  if (BVar1 != 0) {
    slot_idx = 4;
  }
  FUN_0044e52d(&target_idx,1,10,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_01);
  if (BVar1 != 0) {
    slot_idx = 10;
  }
  FUN_0044e52d(&target_idx,1,0x14,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_02);
  if (BVar1 != 0) {
    slot_idx = 0x14;
  }
  FUN_0044e52d(&target_idx,1,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_03);
  if (BVar1 != 0) {
    slot_idx = 0x16;
  }
  FUN_0044e52d(&target_idx,1,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_04);
  if (BVar1 != 0) {
    slot_idx = 0x1e;
  }
  FUN_0044e52d(&target_idx,1,0x1f,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_05);
  if (BVar1 != 0) {
    slot_idx = 0x1f;
  }
  FUN_0044e52d(&target_idx,1,0x20,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_06);
  if (BVar1 != 0) {
    slot_idx = 0x20;
  }
  if (slot_idx == -1) {
    local_34 = 0;
    FUN_0044e52d(&target_idx,0,1,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_07);
    if (BVar1 != 0) {
      slot_idx = 1;
    }
    FUN_0044e52d(&target_idx,0,4,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_08);
    if (BVar1 != 0) {
      slot_idx = 4;
    }
    FUN_0044e52d(&target_idx,0,10,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_09);
    if (BVar1 != 0) {
      slot_idx = 10;
    }
    FUN_0044e52d(&target_idx,0,0x14,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_10);
    if (BVar1 != 0) {
      slot_idx = 0x14;
    }
    FUN_0044e52d(&target_idx,0,0x15,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_11);
    if (BVar1 != 0) {
      slot_idx = 0x15;
    }
    FUN_0044e52d(&target_idx,0,0x1e,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_12);
    if (BVar1 != 0) {
      slot_idx = 0x1e;
    }
    FUN_0044e52d(&target_idx,0,0x1f,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_13);
    if (BVar1 != 0) {
      slot_idx = 0x1f;
    }
    FUN_0044e52d(&target_idx,0,0x20,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_14);
    if (BVar1 != 0) {
      slot_idx = 0x20;
    }
  }
  *arg_3 = local_34;
  *height = slot_idx;
  return;
}



/*
 * Decompiled function: FUN_0044e52d
 * Entry Point: 0044e52d
 * Size: 585 bytes
 */


void FUN_0044e52d(LPRECT arg_1,int card_slot,int event_type,int arg_4,int arg_5)

{
  int32_t slot_idx;
  
  if ((arg_2 == -1) || (arg_3 == -1)) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    if (arg_3 == 1) {
      slot_idx = (arg_5 * 2) / 0x2f8;
    }
    else if ((((arg_3 == 2) || (arg_3 == 3)) || (arg_3 == 4)) || (arg_3 == 5)) {
      slot_idx = (arg_5 * 0x2b) / 0x2f8;
    }
    else if (arg_3 == 10) {
      slot_idx = (arg_5 * 0x54) / 0x2f8;
    }
    else if (arg_3 == 0x14) {
      slot_idx = (arg_5 * 0x7d) / 0x2f8;
    }
    else if (((arg_2 == 1) && (arg_3 == 0x16)) || ((arg_2 == 0 && (arg_3 == 0x15)))) {
      slot_idx = (arg_5 * 0xa6) / 0x2f8;
    }
    else if (arg_3 == 0x1e) {
      slot_idx = (arg_5 * 0xcf) / 0x2f8;
    }
    else if (arg_3 == 0x1f) {
      slot_idx = (arg_5 * 0xf8) / 0x2f8;
    }
    else if (((arg_3 == 0x20) || (arg_3 == 0x21)) || ((arg_3 == 0x22 || (arg_3 == 0x25)))) {
      slot_idx = (arg_5 * 0x121) / 0x2f8;
    }
    else {
      slot_idx = -1;
    }
    if (slot_idx == -1) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      if (arg_2 == 0) {
        slot_idx = slot_idx + (arg_5 * 0x1ae) / 0x2f8;
      }
      SetRect(arg_1,0,slot_idx,arg_4,slot_idx + (arg_5 * 0x28) / 0x2f8);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0044e776
 * Entry Point: 0044e776
 * Size: 685 bytes
 */


void FUN_0044e776(HDC hdc,int arg2)

{
  BOOL BVar1;
  int local_d4;
  int local_d0 [38];
  HGDIOBJ local_38;
  tagRECT local_34;
  int local_24;
  tagRECT loop_idx;
  int card_idx;
  HBRUSH match_count;
  int slot_idx;
  
  FUN_00448b26(&slot_idx,&local_24);
  if ((slot_idx == -1) || (local_24 == -1)) {
    match_count = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,match_count);
    for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
      FUN_004489c3(local_d0,card_idx);
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if (local_d0[local_d4] != 0) {
          FUN_0044e52d(&local_34,card_idx,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&loop_idx,&local_34);
            loop_idx.left = loop_idx.right - (local_34.right - local_34.left) / 3;
            loop_idx.top = loop_idx.bottom -
                           ((local_34.bottom - local_34.top) * (loop_idx.right - loop_idx.left)) /
                           (local_34.right - local_34.left);
            Ellipse(hdc,loop_idx.left,loop_idx.top,loop_idx.right,loop_idx.bottom);
          }
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(match_count);
  }
  if ((slot_idx != -1) && (local_24 != -1)) {
    match_count = CreateSolidBrush(0xff00);
    local_38 = SelectObject(hdc,match_count);
    for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if ((card_idx == slot_idx) && (local_d4 == local_24)) {
          FUN_0044e52d(&local_34,card_idx,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&loop_idx,&local_34);
            loop_idx.right = loop_idx.left + (local_34.right - local_34.left) / 3;
            loop_idx.top = loop_idx.bottom -
                           ((local_34.bottom - local_34.top) * (loop_idx.right - loop_idx.left)) /
                           (local_34.right - local_34.left);
            Ellipse(hdc,loop_idx.left,loop_idx.top,loop_idx.right,loop_idx.bottom);
          }
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(match_count);
  }
  return;
}



/*
 * Decompiled function: UI_CombatDefenseWndProc
 * Entry Point: 0044ea23
 * Size: 4223 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT UI_CombatDefenseWndProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam)

{
  uint32_t uval_1;
  UINT dwMilliseconds;
  HBRUSH pHVar2;
  int val_3;
  LRESULT LVar4;
  int local_5a4;
  int local_5a0;
  int local_59c;
  int local_598;
  int local_594 [38];
  tagPOINT local_4fc;
  UINT_PTR local_4f4;
  int local_4f0;
  UINT_PTR local_4ec;
  UINT_PTR local_4e8;
  tagRECT local_4e4;
  int local_4d4;
  tagPOINT local_4d0;
  tagRECT local_4c8;
  uint32_t local_4b8 [66];
  HRGN local_3b0;
  HDC local_3ac;
  int local_3a8;
  uint8_t local_3a4 [4];
  int local_3a0;
  int local_39c;
  tagPAINTSTRUCT local_38c;
  int local_34c;
  tagRECT local_348;
  int local_338;
  tagRECT local_334;
  int32_t local_324;
  tagMSG local_320;
  BOOL local_304;
  POINT local_300;
  tagRECT local_2f8;
  int local_2e8;
  uint32_t local_2e4 [66];
  ULONG_PTR local_1dc;
  int local_1d8;
  int local_1d4;
  tagRECT local_1d0;
  tagRECT local_1c0;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int32_t local_1a0;
  uint32_t local_19c [66];
  ULONG_PTR local_94;
  int local_90;
  uint32_t local_8c [25];
  int local_28;
  POINT local_24;
  int color_idx;
  tagRECT target_idx;
  int slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = GetWindowLongA(hwnd,0);
      FUN_0044897a(&local_338,&local_3a8);
      if (DAT_00516b70 == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_4b8,(uint32_t *)&g_DuelAssetDirectory);
        Str_CopyFast(local_4b8,(uint32_t *)s__WINBK_PhaseCombat_pic_004f8474);
        DAT_00516b70 = (HANDLE)Pic_LoadKimPicture((char *)local_4b8);
      }
      if (slot_idx != local_3a8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_3ac = DAT_0060157c;
      local_34c = SaveDC(DAT_0060157c);
      GetClientRect(hwnd,&local_334);
      FUN_0044897a(&local_338,(int32_t *)0x0);
      if (DAT_00516b70 == (HANDLE)0x0) {
        pHVar2 = GetStockObject(4);
        FillRect(local_3ac,&local_334,pHVar2);
      }
      else {
        GetObjectA(DAT_00516b70,0x18,local_3a4);
        if (local_338 == 1) {
          local_5a0 = 0;
        }
        else {
          local_5a0 = local_3a0 / 2;
        }
        FUN_00470a16(local_3ac,&local_334.left,DAT_00516b70,local_5a0,0,
                     (int)(local_3a0 + (local_3a0 >> 0x1f & 3U)) >> 2,local_39c);
      }
      if (local_3a8 != -1) {
        GetClientRect(hwnd,&local_334);
        FUN_0044fc75(&local_348,local_3a8,local_334.right,local_334.bottom);
        local_3b0 = CreateRectRgnIndirect(&local_348);
        SelectClipRgn(local_3ac,local_3b0);
        if (DAT_00516b70 == (HANDLE)0x0) {
          pHVar2 = GetStockObject(2);
          FillRect(local_3ac,&local_334,pHVar2);
        }
        else {
          GetObjectA(DAT_00516b70,0x18,local_3a4);
          if (local_338 == 1) {
            local_5a4 = local_3a0 + (local_3a0 >> 0x1f & 3U);
          }
          else {
            local_5a4 = local_3a0 * 3 + (local_3a0 * 3 >> 0x1f & 3U);
          }
          local_5a4 = local_5a4 >> 2;
          FUN_00470a16(local_3ac,&local_334.left,DAT_00516b70,local_5a4,0,
                       (int)(local_3a0 + (local_3a0 >> 0x1f & 3U)) >> 2,local_39c);
        }
        SelectClipRgn(local_3ac,(HRGN)0x0);
        DeleteObject(local_3b0);
      }
      RestoreDC(DAT_0060157c,local_34c);
      FUN_0044fe36(local_3ac,(int)&local_334);
      local_3ac = BeginPaint(hwnd,&local_38c);
      if (local_3ac != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_3ac);
        GetClientRect(hwnd,&local_334);
        BitBlt(local_3ac,0,0,local_334.right,local_334.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_38c);
        slot_idx = local_3a8;
        SetWindowLongA(hwnd,0,local_3a8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = 0;
      SetWindowLongA(hwnd,0,0);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_00471df6(hwnd,0x20,wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      GetCursorPos(&local_4fc);
      ScreenToClient(hwnd,&local_4fc);
      GetClientRect(hwnd,&local_4e4);
      FUN_0044fab8(&local_4fc,&local_4e4,&local_598);
      FUN_0044897a(&local_4d4,(int32_t *)0x0);
      if (local_598 == 0x15) {
        local_4f0 = 0;
      }
      else if (local_598 == 0x16) {
        local_4f0 = 1;
      }
      else if (local_598 == 0x17) {
        local_4f0 = 2;
      }
      else if (local_598 == 0x18) {
        local_4f0 = 3;
      }
      else if (local_598 == 0x19) {
        local_4f0 = 4;
      }
      else if (local_598 == 0x1b) {
        local_4f0 = 5;
      }
      else if (local_598 == 0x1e) {
        local_4f0 = 6;
      }
      else {
        local_4f0 = -1;
      }
      if (local_598 != -1) {
        if (DAT_00618158 != 0) {
          local_4ec = local_4f0 + 0x96;
          AppendMenuA(DAT_00516b78,0,local_4ec,s_Run_to_this_phase_004f848c);
        }
        val_3 = GetMenuItemCount(DAT_00516b78);
        if (val_3 != 0) {
          AppendMenuA(DAT_00516b78,0x800,0,(LPCSTR)0x0);
        }
        local_4e8 = local_4f0 + 200;
        AppendMenuA(DAT_00516b78,0,local_4e8,s_Mark_this_phase_to_always_stop_004f84a0);
        FUN_004489c3(local_594,local_4d4);
        if (local_594[local_598] != 0) {
          CheckMenuItem(DAT_00516b78,local_4e8,8);
        }
        local_4f4 = local_4f0 + 0xfa;
        AppendMenuA(DAT_00516b78,0,local_4f4,s_Help_for_this_phase____004f84c0);
      }
      AppendMenuA(DAT_00516b78,0,100,s_Help____004f84d8);
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 100) {
        local_94 = 0x7e5;
        Mem_AllocOrFree_004d9630(local_19c,(uint32_t *)&DAT_005f76e0);
        Str_CopyFast(local_19c,(uint32_t *)s__duel_hlp_004f845c);
        WinHelpA(g_DuelMainHwnd,(LPCSTR)local_19c,1,local_94);
      }
      else {
        uval_1 = wParam & 0xffff;
        if (uval_1 < 0xfa) {
          if (uval_1 < 200) {
            local_1a8 = 0x96;
          }
          else {
            local_1a8 = 200;
          }
        }
        else {
          local_1a8 = 0xfa;
        }
        local_1ac = uval_1 - local_1a8;
        local_1a4 = local_1ac;
        if (local_1a8 == 0x96) {
          if (local_1ac == 0) {
            local_1b0 = 0x15;
          }
          else if (local_1ac == 1) {
            local_1b0 = 0x16;
          }
          else if (local_1ac == 2) {
            local_1b0 = 0x17;
          }
          else if (local_1ac == 3) {
            local_1b0 = 0x18;
          }
          else if (local_1ac == 4) {
            local_1b0 = 0x19;
          }
          else if (local_1ac == 5) {
            local_1b0 = 0x1b;
          }
          else if (local_1ac == 6) {
            local_1b0 = 0x1e;
          }
          FUN_0044897a(&local_1a0,(int32_t *)0x0);
          DAT_0066aac4 = local_1a0;
          DAT_0066ab04 = local_1b0;
          DAT_0066643c = 0;
          _DAT_00516b90 = 0xfffffffe;
          _DAT_00516b94 = 0xffffffff;
          _DAT_00516b98 = 0xffffffff;
          PostMessageA(g_DuelMainHwnd,0x464,0,0x516b90);
        }
        else if (local_1a8 == 200) {
          if (local_1ac == 0) {
            local_1d8 = 0x15;
          }
          else if (local_1ac == 1) {
            local_1d8 = 0x16;
          }
          else if (local_1ac == 2) {
            local_1d8 = 0x17;
          }
          else if (local_1ac == 3) {
            local_1d8 = 0x18;
          }
          else if (local_1ac == 4) {
            local_1d8 = 0x19;
          }
          else if (local_1ac == 5) {
            local_1d8 = 0x1b;
          }
          else if (local_1ac == 6) {
            local_1d8 = 0x1e;
          }
          FUN_0044897a(&local_1d4,(int32_t *)0x0);
          if (((&DAT_006667c0)[local_1d8 * 4 + local_1d4 * 0x98] & 1) == 0) {
            *(uint32_t *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint32_t *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) | 1;
          }
          else {
            *(uint32_t *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint32_t *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) & 0xfffffffe;
          }
          FUN_004457a2();
          GetClientRect(hwnd,&local_1d0);
          FUN_0044fc75(&local_1c0,local_1d8,local_1d0.right,local_1d0.bottom);
          InvalidateRect(hwnd,&local_1c0,0);
        }
        else if (local_1a8 == 0xfa) {
          if (local_1ac == 0) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 1) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 2) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 3) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 4) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 5) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 6) {
            local_1dc = 0x7dd;
          }
          Mem_AllocOrFree_004d9630(local_2e4,(uint32_t *)&DAT_005f76e0);
          Str_CopyFast(local_2e4,(uint32_t *)s__duel_hlp_004f8468);
          WinHelpA(g_DuelMainHwnd,(LPCSTR)local_2e4,1,local_1dc);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      dwMilliseconds = GetDoubleClickTime();
      Sleep(dwMilliseconds);
      local_304 = PeekMessageA(&local_320,hwnd,0x203,0x203,0);
      local_300.x = lParam & 0xffff;
      local_300.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_2f8);
      FUN_0044fab8(&local_300,&local_2f8,&local_2e8);
      if ((local_2e8 != -1) && (DAT_00618158 != 0)) {
        FUN_0044897a(&local_324,(int32_t *)0x0);
        DAT_0066aac4 = local_324;
        DAT_0066ab04 = local_2e8;
        DAT_0066643c = local_304;
        _DAT_00516b80 = 0xfffffffe;
        _DAT_00516b84 = 0xffffffff;
        _DAT_00516b88 = 0xffffffff;
        PostMessageA(g_DuelMainHwnd,0x464,0,0x516b80);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_59c = GetMenuItemCount(DAT_00516b78);
        while (local_59c != 0) {
          DeleteMenu(DAT_00516b78,0,0x400);
          local_59c = local_59c + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = GDI_RealizePaletteTree(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x204) {
      local_4d0.x = lParam & 0xffff;
      local_4d0.y = lParam >> 0x10;
      if (DAT_00618158 != 0) {
        ClientToScreen(hwnd,&local_4d0);
        SetRect(&local_4c8,local_4d0.x,local_4d0.y,local_4d0.x + 1,local_4d0.y + 1);
        TrackPopupMenu(DAT_00516b78,2,local_4d0.x,local_4d0.y,0,hwnd,&local_4c8);
      }
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      Mem_AllocOrFree_0045033a(hwnd,wParam,lParam);
      return 0;
    }
    if (uMsg == 0x432) {
      slot_idx = GetWindowLongA(hwnd,0);
      FUN_0044897a((int32_t *)0x0,&local_90);
      if (slot_idx != local_90) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_24.x = lParam & 0xffff;
      local_24.y = lParam >> 0x10;
      GetClientRect(hwnd,&target_idx);
      FUN_0044fab8(&local_24,&target_idx,&local_28);
      color_idx = 1;
      if (local_28 == 0x15) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Choose_attackers_phase_004f83a4);
      }
      else if (local_28 == 0x16) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Attacker_fast_effects_phase_004f83bc);
      }
      else if (local_28 == 0x17) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Assign_defenders_phase_004f83d8);
      }
      else if (local_28 == 0x18) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Blocker_fast_effects_phase_004f83f0);
      }
      else if (local_28 == 0x19) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Resolve_1st_strike_damage_004f840c);
      }
      else if ((local_28 == 0x1a) || (local_28 == 0x1b)) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Resolve_normal_damage_004f8428);
      }
      else if (local_28 == 0x1e) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Main_phase__post_combat__004f8440);
      }
      else {
        color_idx = 0;
      }
      if (color_idx == 0) {
        return 0;
      }
      Mem_AllocOrFree_004d9630((uint32_t *)wParam,local_8c);
      return color_idx;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: FUN_0044fab8
 * Entry Point: 0044fab8
 * Size: 445 bytes
 */


void FUN_0044fab8(POINT *arg_1,RECT *arg_2,int32_t *arg_3)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  BOOL BVar1;
  tagRECT local_28;
  tagRECT target_idx;
  int32_t slot_idx;
  
  CopyRect(&local_28,arg_2);
  pt_05 = *arg_1;
  pt_04 = *arg_1;
  pt_03 = *arg_1;
  pt_02 = *arg_1;
  pt_01 = *arg_1;
  pt_00 = *arg_1;
  pt = *arg_1;
  slot_idx = 0xffffffff;
  FUN_0044fc75(&target_idx,0x15,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt);
  if (BVar1 != 0) {
    slot_idx = 0x15;
  }
  FUN_0044fc75(&target_idx,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_00);
  if (BVar1 != 0) {
    slot_idx = 0x16;
  }
  FUN_0044fc75(&target_idx,0x17,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_01);
  if (BVar1 != 0) {
    slot_idx = 0x17;
  }
  FUN_0044fc75(&target_idx,0x18,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_02);
  if (BVar1 != 0) {
    slot_idx = 0x18;
  }
  FUN_0044fc75(&target_idx,0x19,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_03);
  if (BVar1 != 0) {
    slot_idx = 0x19;
  }
  FUN_0044fc75(&target_idx,0x1b,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_04);
  if (BVar1 != 0) {
    slot_idx = 0x1a;
  }
  FUN_0044fc75(&target_idx,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_05);
  if (BVar1 != 0) {
    slot_idx = 0x1e;
  }
  *arg_3 = slot_idx;
  return;
}



/*
 * Decompiled function: FUN_0044fc75
 * Entry Point: 0044fc75
 * Size: 449 bytes
 */


void FUN_0044fc75(LPRECT arg_1,int y,int width,int height)

{
  int32_t slot_idx;
  
  if (y == -1) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    if (y == 0x15) {
      slot_idx = (height * 2) / 0x2f8;
    }
    else if (y == 0x16) {
      slot_idx = (height * 0x2b) / 0x2f8;
    }
    else if (y == 0x17) {
      slot_idx = (height * 0x54) / 0x2f8;
    }
    else if (y == 0x18) {
      slot_idx = (height * 0x7d) / 0x2f8;
    }
    else if (y == 0x19) {
      slot_idx = (height * 0xa6) / 0x2f8;
    }
    else if (y == 0x1a) {
      slot_idx = (height * 0xcf) / 0x2f8;
    }
    else if (y == 0x1b) {
      slot_idx = (height * 0xcf) / 0x2f8;
    }
    else if (y == 0x1e) {
      slot_idx = (height * 0x121) / 0x2f8;
    }
    else {
      slot_idx = -1;
    }
    if (slot_idx == -1) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      SetRect(arg_1,0,slot_idx,width,(height * 0x28) / 0x2f8 + slot_idx);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0044fe36
 * Entry Point: 0044fe36
 * Size: 619 bytes
 */


void FUN_0044fe36(HDC hdc,int arg2)

{
  BOOL BVar1;
  int local_d4;
  int local_d0 [38];
  HGDIOBJ local_38;
  tagRECT local_34;
  int local_24;
  tagRECT loop_idx;
  HBRUSH card_idx;
  int match_count;
  int slot_idx;
  
  FUN_00448b26(&slot_idx,&local_24);
  if ((slot_idx == -1) || (local_24 == -1)) {
    card_idx = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,card_idx);
    FUN_0044897a(&match_count,(int32_t *)0x0);
    FUN_004489c3(local_d0,match_count);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_d0[local_d4] != 0) {
        FUN_0044fc75(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
        BVar1 = IsRectEmpty(&local_34);
        if (BVar1 == 0) {
          CopyRect(&loop_idx,&local_34);
          loop_idx.left = loop_idx.right - (local_34.right - local_34.left) / 3;
          loop_idx.top = loop_idx.bottom -
                         ((local_34.bottom - local_34.top) * (loop_idx.right - loop_idx.left)) /
                         (local_34.right - local_34.left);
          Ellipse(hdc,loop_idx.left,loop_idx.top,loop_idx.right,loop_idx.bottom);
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(card_idx);
  }
  if ((slot_idx != -1) && (local_24 != -1)) {
    card_idx = CreateSolidBrush(0xff00);
    local_38 = SelectObject(hdc,card_idx);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_24 == local_d4) {
        FUN_0044fc75(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
        BVar1 = IsRectEmpty(&local_34);
        if (BVar1 == 0) {
          CopyRect(&loop_idx,&local_34);
          loop_idx.right = loop_idx.left + (local_34.right - local_34.left) / 3;
          loop_idx.top = loop_idx.bottom -
                         ((local_34.bottom - local_34.top) * (loop_idx.right - loop_idx.left)) /
                         (local_34.right - local_34.left);
          Ellipse(hdc,loop_idx.left,loop_idx.top,loop_idx.right,loop_idx.bottom);
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(card_idx);
  }
  return;
}



/*
 * Decompiled function: Pic_Draw_00427e36
 * Entry Point: 004500a1
 * Size: 563 bytes
 */


void Pic_Draw_00427e36(int *arg_1,int32_t *arg_2,int event_type)

{
  int local_7c;
  uint32_t local_74 [25];
  int32_t card_idx;
  int32_t match_count;
  int slot_idx;
  
  FUN_0044897a(&slot_idx,&card_idx);
  local_7c = slot_idx;
  switch(card_idx) {
  case 1:
    match_count = 4;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Upkeep_phase_004f84e0);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    match_count = 10;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Draw_phase_004f84f0);
    break;
  default:
    match_count = 0xffffffff;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_next_phase_004f85ec);
    break;
  case 10:
    match_count = 0x14;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Main_phase__pre_combat__004f84fc);
    break;
  case 0x14:
    match_count = 0x15;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Main_phase__combat__004f8514);
    break;
  case 0x15:
    match_count = 0x16;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Attack_fast_effects_phase_004f8528);
    break;
  case 0x16:
    match_count = 0x17;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Choose_defenders_phase_004f8544);
    break;
  case 0x17:
    match_count = 0x18;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Block_fast_effects_phase_004f855c);
    break;
  case 0x18:
    match_count = 0x19;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Resolve_1st_strike_004f8578);
    break;
  case 0x19:
  case 0x1a:
    match_count = 0x1b;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Resolve_attack_004f858c);
    break;
  case 0x1b:
    match_count = 0x1e;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Main_phase__post_combat__004f859c);
    break;
  case 0x1e:
    match_count = 0x1f;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Discard_phase_004f85b8);
    break;
  case 0x1f:
    match_count = 0x20;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Cleanup_phase_004f85c8);
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
    match_count = 0;
    local_7c = 1 - slot_idx;
    Mem_AllocOrFree_004d9630(local_74,(uint32_t *)s_Start_of_next_turn_004f85d8);
  }
  if (arg_1 != (int *)0x0) {
    *arg_1 = local_7c;
  }
  if (arg_2 != (int32_t *)0x0) {
    *arg_2 = match_count;
  }
  if (arg_3 != 0) {
    Mem_AllocOrFree_004d9630((uint32_t *)arg_3,local_74);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0045033a
 * Entry Point: 0045033a
 * Size: 19 bytes
 */


void Mem_AllocOrFree_0045033a(void)

{
  return;
}



/*
 * Decompiled function: FUN_00450590
 * Entry Point: 00450590
 * Size: 52 bytes
 */


uint32_t FUN_00450590(int arg1,int arg2)

{
  return *(uint32_t *)(&g_DuelCardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff00;
}



/*
 * Decompiled function: Mem_AllocOrFree_004505c4
 * Entry Point: 004505c4
 * Size: 47 bytes
 */


int32_t Mem_AllocOrFree_004505c4(int arg1,int arg2)

{
  return *(int32_t *)(&g_DuelCardSlot_Counters + arg2 * 0x120 + arg1 * 0x5b20);
}



/*
 * Decompiled function: FUN_004505f3
 * Entry Point: 004505f3
 * Size: 106 bytes
 */


uint32_t FUN_004505f3(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  
  val_1 = Mem_AllocOrFree_004506f6(arg1,arg2);
  if (val_1 == -1) {
    uval_2 = 0;
  }
  else if (((&DAT_004ff5a8)[val_1 * 0x34] & 0x20) == 0) {
    uval_2 = 0;
  }
  else {
    uval_2 = Mem_AllocOrFree_004505c4(arg1,arg2);
    uval_2 = uval_2 & 0xf;
  }
  return uval_2;
}



/*
 * Decompiled function: Mem_AllocOrFree_00450667
 * Entry Point: 00450667
 * Size: 48 bytes
 */


int Mem_AllocOrFree_00450667(int arg1,int arg2)

{
  return (int)(char)(&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20];
}



/*
 * Decompiled function: Mem_AllocOrFree_00450697
 * Entry Point: 00450697
 * Size: 48 bytes
 */


int Mem_AllocOrFree_00450697(int arg1,int arg2)

{
  return (int)*(short *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20);
}



/*
 * Decompiled function: Mem_AllocOrFree_004506c7
 * Entry Point: 004506c7
 * Size: 47 bytes
 */


int32_t Mem_AllocOrFree_004506c7(int arg1,int arg2)

{
  return *(int32_t *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20);
}



/*
 * Decompiled function: Mem_AllocOrFree_004506f6
 * Entry Point: 004506f6
 * Size: 47 bytes
 */


int32_t Mem_AllocOrFree_004506f6(int arg1,int arg2)

{
  return *(int32_t *)(&g_DuelCardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120);
}



/*
 * Decompiled function: FUN_00450725
 * Entry Point: 00450725
 * Size: 106 bytes
 */


int32_t FUN_00450725(int arg1,int arg2)

{
  int32_t uval_1;
  int val_2;
  
  if ((arg1 == -1) || (arg2 == -1)) {
    uval_1 = 0xffffffff;
  }
  else {
    val_2 = Mem_AllocOrFree_004506f6(arg1,arg2);
    if (val_2 == -1) {
      uval_1 = 0xffffffff;
    }
    else {
      uval_1 = *(int32_t *)(&DAT_004ff590 + val_2 * 0x34);
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardTypeFromID
 * Entry Point: 00450799
 * Size: 137 bytes
 */


int CardTypeFromID(int player_id)

{
  int match_count;
  int slot_idx;
  
                    /* 0x50799  3  CardTypeFromID */
  if (arg_1 == -1) {
    slot_idx = -1;
  }
  else {
    slot_idx = -1;
    match_count = 0;
    while ((*(int *)(&DAT_004ff590 + match_count * 0x34) != -1 && (slot_idx == -1))) {
      if (*(int *)(&DAT_004ff590 + match_count * 0x34) == arg_1) {
        slot_idx = match_count;
      }
      match_count = match_count + 1;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: CardIDFromType
 * Entry Point: 00450827
 * Size: 61 bytes
 */


int32_t CardIDFromType(uint32_t arg_1)

{
  int32_t uval_1;
  
                    /* 0x50827  1  CardIDFromType */
  if (arg_1 == 0xffffffff) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = *(int32_t *)(&DAT_004ff590 + (arg_1 & 0xfff) * 0x34);
  }
  return uval_1;
}



/*
 * Decompiled function: CardInDeck
 * Entry Point: 00450869
 * Size: 44 bytes
 */


uint32_t CardInDeck(uint32_t arg_1)

{
  uint32_t uval_1;
  
                    /* 0x50869  2  CardInDeck */
  if (arg_1 == 0xffffffff) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = arg_1 & 0x4000;
  }
  return uval_1;
}



/*
 * Decompiled function: SetCardInDeck
 * Entry Point: 0045089a
 * Size: 54 bytes
 */


void SetCardInDeck(int arg1,int arg2)

{
                    /* 0x5089a  6  SetCardInDeck */
  if (arg2 == 1) {
    *(uint32_t *)(&deck + arg1 * 4) = *(uint32_t *)(&deck + arg1 * 4) | 0x4000;
  }
  else {
    *(uint32_t *)(&deck + arg1 * 4) = *(uint32_t *)(&deck + arg1 * 4) & 0x8fff;
  }
  return;
}



/*
 * Decompiled function: FUN_004508d0
 * Entry Point: 004508d0
 * Size: 66 bytes
 */


bool FUN_004508d0(int arg1,int arg2)

{
  return ((&g_DuelCardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 2) != 0;
}



/*
 * Decompiled function: FUN_00450917
 * Entry Point: 00450917
 * Size: 283 bytes
 */


uint8_t FUN_00450917(int arg1,int arg2)

{
  uint8_t flag_1;
  
  flag_1 = ((&g_DuelCardSlot_Subtypes)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0;
  if (((&g_DuelCardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) {
    flag_1 = flag_1 | 2;
  }
  if (((&g_DuelCardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    flag_1 = flag_1 | 4;
  }
  if ((&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] != -1) {
    flag_1 = flag_1 | 8;
  }
  if (((&g_DuelCardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (*(int *)(&g_DuelCardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) != -1)) {
    flag_1 = flag_1 | 0x10;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_00450a32
 * Entry Point: 00450a32
 * Size: 94 bytes
 */


undefined8 FUN_00450a32(int arg1,int arg2)

{
  return CONCAT44(*(int32_t *)(&g_DuelCardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20),
                  (int)(char)(&g_DuelCardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20]);
}



/*
 * Decompiled function: FUN_00450a90
 * Entry Point: 00450a90
 * Size: 131 bytes
 */


int32_t FUN_00450a90(int player_id,int card_slot,int *arg_3)

{
  if (arg_3 != (int *)0x0) {
    *arg_3 = (int)(char)(&g_DuelCardSlot_Controller)[arg_2 * 0x120 + arg_1 * 0x5b20];
    arg_3[1] = *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  return *(int32_t *)(&DAT_00682704 + arg_2 * 0x120 + arg_1 * 0x5b20);
}



/*
 * Decompiled function: FUN_00450b13
 * Entry Point: 00450b13
 * Size: 111 bytes
 */


uint8_t FUN_00450b13(int arg1,int arg2)

{
  uint8_t uval_1;
  
  if (*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uval_1 = 0;
  }
  else {
    uval_1 = (&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00450b87
 * Entry Point: 00450b87
 * Size: 48 bytes
 */


int Mem_AllocOrFree_00450b87(int arg1,int arg2)

{
  return (int)*(short *)(&DAT_006826d4 + arg2 * 0x120 + arg1 * 0x5b20);
}



/*
 * Decompiled function: Mem_AllocOrFree_00450bb7
 * Entry Point: 00450bb7
 * Size: 48 bytes
 */


int Mem_AllocOrFree_00450bb7(int arg1,int arg2)

{
  return (int)*(short *)(&DAT_006826d6 + arg2 * 0x120 + arg1 * 0x5b20);
}



/*
 * Decompiled function: FUN_00450be7
 * Entry Point: 00450be7
 * Size: 92 bytes
 */


int32_t FUN_00450be7(int arg1,int arg2)

{
  int32_t uval_1;
  
  if (*(int *)(&g_DuelCardSlot_Abilities2 + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    uval_1 = 0;
  }
  else {
    uval_1 = *(int32_t *)(&g_DuelCardSlot_Abilities2 + arg1 * 0x5b20 + arg2 * 0x120);
  }
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00450c48
 * Entry Point: 00450c48
 * Size: 48 bytes
 */


int Mem_AllocOrFree_00450c48(int arg1,int arg2)

{
  return (int)(char)(&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20];
}



/*
 * Decompiled function: Mem_AllocOrFree_00450c78
 * Entry Point: 00450c78
 * Size: 48 bytes
 */


int Mem_AllocOrFree_00450c78(int arg1,int arg2)

{
  return (int)(char)(&DAT_006826dc)[arg2 * 0x120 + arg1 * 0x5b20];
}



/*
 * Decompiled function: Ai_Subsystem_004cc1e8
 * Entry Point: 00450ca8
 * Size: 110 bytes
 */


char * Ai_Subsystem_004cc1e8(int arg1,int arg2)

{
  char *char_ptr_1;
  
  if (*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    char_ptr_1 = &DAT_004f85f8;
  }
  else {
    char_ptr_1 = s_Swamp_004ff581 + *(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34;
  }
  return char_ptr_1;
}



/*
 * Decompiled function: FUN_00450d1b
 * Entry Point: 00450d1b
 * Size: 108 bytes
 */


int FUN_00450d1b(int arg1,int arg2)

{
  int val_1;
  
  if (*(int *)(&g_DuelCardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    val_1 = 0;
  }
  else {
    val_1 = (int)(char)(&g_DuelMasterCardSubType)
                       [*(int *)(&g_DuelCardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00450d8c
 * Entry Point: 00450d8c
 * Size: 108 bytes
 */


int FUN_00450d8c(int arg1,int arg2)

{
  int val_1;
  
  if (*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    val_1 = 0;
  }
  else {
    val_1 = (int)(char)(&DAT_004ff598)
                       [*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00450dfd
 * Entry Point: 00450dfd
 * Size: 135 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_00450dfd(int player_id,int card_slot,int32_t arg_3)

{
  if (arg_2 == 0) {
    _DAT_00687fac = 0;
  }
  else {
    _DAT_00687fac = 0x10;
  }
  _DAT_00687fc8 = arg_3;
  DAT_00687fbe = 0xff;
  DAT_00687fbc = (&DAT_004ff596)[arg_1 * 0x34];
  _DAT_00687fdc = *(int32_t *)(&DAT_004ff5a4 + arg_1 * 0x34);
  _DAT_00687fa4 = 0xffffffff;
  return 0x4f;
}



/*
 * Decompiled function: FUN_00450e84
 * Entry Point: 00450e84
 * Size: 52 bytes
 */


int32_t FUN_00450e84(int arg1,int arg2)

{
  int32_t uval_1;
  
  if (g_DuelDebugModeFlag == 1) {
    uval_1 = 0;
  }
  else {
    uval_1 = FUN_00440af9(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00450eb8
 * Entry Point: 00450eb8
 * Size: 53 bytes
 */


void FUN_00450eb8(int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4)

{
  if (g_DuelDebugModeFlag != 1) {
    FUN_00440eff(arg_1,arg_2,arg_3,arg_4);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00450eed
 * Entry Point: 00450eed
 * Size: 40 bytes
 */


void Mem_AllocOrFree_00450eed(uint8_t *arg_1)

{
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00522300,(uint32_t *)arg_1);
  FUN_004469c9(arg_1);
  return;
}



/*
 * Decompiled function: FUN_00450f15
 * Entry Point: 00450f15
 * Size: 69 bytes
 */


int32_t FUN_00450f15(int *arg_1,int card_slot,int32_t arg_3,int arg_4,int32_t arg_5)

{
  int32_t uval_1;
  
  if (g_DuelDebugModeFlag == 1) {
    uval_1 = 1;
  }
  else {
    uval_1 = Ai_EvaluateCreatureCast(arg_1,0,arg_2,arg_3,arg_4,arg_5);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00450f5a
 * Entry Point: 00450f5a
 * Size: 71 bytes
 */


int32_t FUN_00450f5a(int *arg_1,int card_slot,int event_type,int32_t arg_4,int arg_5,int32_t arg_6)

{
  int32_t uval_1;
  
  if (g_DuelDebugModeFlag == 1) {
    uval_1 = 1;
  }
  else {
    uval_1 = Ai_EvaluateCreatureCast(arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
  }
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00450fa1
 * Entry Point: 00450fa1
 * Size: 41 bytes
 */


void Mem_AllocOrFree_00450fa1(int32_t arg_1)

{
  if (g_DuelDebugModeFlag != 1) {
    Mem_AllocOrFree_0044274a(arg_1);
  }
  return;
}



/*
 * Decompiled function: FUN_00450fca
 * Entry Point: 00450fca
 * Size: 99 bytes
 */


void FUN_00450fca(int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f6bf(arg_1,arg_2,arg_3,arg_4);
    }
    else {
      FUN_00442839(arg_1,-1,-1);
    }
  }
  return;
}



/*
 * Decompiled function: Ai_Subsystem_004cc56d
 * Entry Point: 0045102d
 * Size: 592 bytes
 */


int Ai_Subsystem_004cc56d(int player_id,int card_slot,int event_type,int arg_4,int arg_5,uint32_t *arg_6,int arg_7)

{
  int val_1;
  bool flag_2;
  int32_t local_274;
  uint32_t local_26c [150];
  int player_idx;
  int match_count;
  uint32_t slot_idx;
  
  if ((((g_DuelDebugModeFlag != 1) && (-1 < arg_1)) && (-1 < arg_2)) && (-1 < arg_3)) {
    Mem_AllocOrFree_004d9630(local_26c,arg_6);
    g_DuelCardChoicePrompt = 0;
    if (arg_1 == g_DuelTargetPlayer) {
      FUN_0044a5a4(arg_2,arg_3);
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f8608);
    }
    else {
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_00666500);
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_selects__004f85fc);
      slot_idx = 1;
      player_idx = arg_7;
      for (match_count = 0; val_1 = player_idx, match_count < 1000; match_count = match_count + 1) {
        if (((slot_idx != 0) && (*(char *)((int)local_26c + match_count) == ' ')) &&
           (player_idx = player_idx + -1, val_1 == 0)) {
          *(uint8_t *)((int)local_26c + match_count) = 0x3e;
          break;
        }
        flag_2 = *(char *)((int)local_26c + match_count) != '\n';
        if (flag_2) {
          slot_idx = 0;
        }
        else {
          slot_idx = 1;
        }
        slot_idx = (uint32_t)!flag_2;
      }
    }
    Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,local_26c);
    if ((*(int *)(&g_DuelCardSlot_CardId + arg_3 * 0x120 + arg_2 * 0x5b20) == -1) ||
       (*(int *)(&g_DuelCardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20) == -1)) {
      Duel_UpdateBoardState(1,0xff);
    }
    if ((arg_1 == g_DuelTargetPlayer) && (DAT_0068f0b0 == 0)) {
      local_274 = 1;
    }
    else {
      local_274 = 0;
    }
    val_1 = FUN_00446c16(arg_2,arg_3,arg_4,arg_5,&g_DuelCardChoicePrompt,local_274);
    if ((arg_1 == g_DuelTargetPlayer) && (DAT_0068f0b0 == 0)) {
      arg_7 = val_1;
    }
  }
  return arg_7;
}



/*
 * Decompiled function: FUN_00451282
 * Entry Point: 00451282
 * Size: 79 bytes
 */


void FUN_00451282(int32_t arg1,int32_t arg2)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f6ca(arg1,arg2);
    }
    else {
      Mem_AllocOrFree_004428c2(arg1,arg2);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004512d1
 * Entry Point: 004512d1
 * Size: 107 bytes
 */


INT_PTR FUN_004512d1(int player_id,int32_t arg_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      arg_3 = Mem_AllocOrFree_0049f6d5(arg_1,arg_2,arg_3);
    }
    else {
      arg_3 = FUN_004428d2(arg_1,arg_2,arg_3,str_4,str_5,str_6);
    }
  }
  return arg_3;
}



/*
 * Decompiled function: FUN_0045133c
 * Entry Point: 0045133c
 * Size: 95 bytes
 */


INT_PTR FUN_0045133c(int player_id,int32_t arg_2,INT_PTR arg_3)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      arg_3 = Mem_AllocOrFree_0049f6d5(arg_1,arg_2,arg_3);
    }
    else {
      arg_3 = FUN_00442e3c(arg_1,arg_2,arg_3);
    }
  }
  return arg_3;
}



/*
 * Decompiled function: FUN_0045139b
 * Entry Point: 0045139b
 * Size: 95 bytes
 */


INT_PTR FUN_0045139b(int player_id,int32_t arg_2,INT_PTR arg_3)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      arg_3 = Mem_AllocOrFree_0049f6e7(arg_1,arg_2,arg_3);
    }
    else {
      arg_3 = FUN_00443000(arg_1,arg_2,arg_3);
    }
  }
  return arg_3;
}



/*
 * Decompiled function: FUN_004513fa
 * Entry Point: 004513fa
 * Size: 65 bytes
 */


int FUN_004513fa(int player_id,int32_t arg_2,int32_t arg_3,int arg_4,uint32_t arg_5)

{
  if (g_DuelDebugModeFlag != 1) {
    arg_4 = FUN_00443784(arg_1,arg_2,arg_3,arg_4,arg_5);
  }
  return arg_4;
}



/*
 * Decompiled function: FUN_0045143b
 * Entry Point: 0045143b
 * Size: 71 bytes
 */


void FUN_0045143b(int32_t arg_1)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f6f9(arg_1);
    }
    else {
      Mem_AllocOrFree_00445797(arg_1);
    }
  }
  return;
}



/*
 * Decompiled function: Duel_UpdateBoardState
 * Entry Point: 00451482
 * Size: 734 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Duel_UpdateBoardState(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  int card_idx;
  int slot_idx;
  
  FUN_00451760();
  if ((DAT_0068edd4 == 0) && (g_DuelCurrentEventCode == -1)) {
    _DAT_0068f0b4 = 0;
  }
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; card_idx = card_idx + 1) {
      if ((*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) != -1) &&
         (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) * 0x34] & 2
          ) != 0)) {
        Duel_QueryCardAttribute(slot_idx, card_idx, 0x3c, 0xffffffff);
      }
    }
  }
  FUN_00451995();
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; card_idx = card_idx + 1) {
      if ((*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) != -1) &&
         (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) * 0x34] & 2
          ) != 0)) {
        Duel_QueryCardAttribute(slot_idx,card_idx,0x34,0xffffffff);
        Duel_QueryCardAttribute(slot_idx,card_idx,0x32,0xffffffff);
        Duel_QueryCardAttribute(slot_idx,card_idx,0x33,0xffffffff);
      }
    }
  }
  if (g_DuelDebugModeFlag != 1) {
    DAT_00676500 = 0;
    for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
      for (card_idx = 0; card_idx < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; card_idx = card_idx + 1) {
        if (*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) != -1) {
          uval_1 = FUN_0046da4a(slot_idx,card_idx);
          *(int32_t *)(&DAT_00682714 + card_idx * 0x120 + slot_idx * 0x5b20) = uval_1;
        }
      }
    }
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f704(arg1,arg2);
    }
    else {
      SendMessageA(g_DuelMainHwnd,0x464,0xffff,0);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00451760
 * Entry Point: 00451760
 * Size: 565 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451760(void)

{
  int match_count;
  int slot_idx;
  
  for (match_count = 0; match_count < 8; match_count = match_count + 1) {
    *(int32_t *)(&DAT_00676150 + match_count * 4) = 0;
    *(int32_t *)(&DAT_0068ed30 + match_count * 4) = *(int32_t *)(&DAT_00676150 + match_count * 4);
    *(int32_t *)(&DAT_0068ed10 + match_count * 4) = *(int32_t *)(&DAT_0068ed30 + match_count * 4);
  }
  DAT_0066663c = 0xffffffff;
  _DAT_00666570 = 0xffffffff;
  DAT_0066692c = 0xffffffff;
  _DAT_00666900 = 0xffffffff;
  DAT_0068f364 = 0;
  _DAT_0068f360 = 0;
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; match_count = match_count + 1) {
      if ((((&DAT_004ff5a9)[*(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] &
           0x10) != 0) && (((&g_DuelCardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
        FUN_0048c50b(slot_idx,match_count,0x7f);
      }
      if ((*(int *)(&DAT_004ff590 +
                   *(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34) == 0xee) &&
         (((&g_DuelCardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
        Duel_PlayCardSoundEffect(slot_idx,match_count,0x7f,0xffffffff,0xffffffff);
      }
      if ((*(int *)(&DAT_004ff590 +
                   *(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34) == 100) &&
         (((&g_DuelCardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
        Duel_PlayCardSoundEffect(slot_idx,match_count,0x7f,0xffffffff,0xffffffff);
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00451995
 * Entry Point: 00451995
 * Size: 631 bytes
 */


void FUN_00451995(void)

{
  int card_idx;
  int match_count;
  int slot_idx;
  
  for (match_count = 0; match_count < 8; match_count = match_count + 1) {
    *(int32_t *)(&DAT_0068ef70 + match_count * 4) = 0;
    *(int32_t *)(&DAT_0068ef50 + match_count * 4) = *(int32_t *)(&DAT_0068ef70 + match_count * 4);
  }
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; match_count = match_count + 1) {
      if ((((*(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) != -1) &&
           (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] &
            1) != 0)) && (((&g_DuelCardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
         (((&g_DuelCardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 0x20) == 0)) {
        if (*(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) < 5) {
          (&DAT_0068ef54)
          [slot_idx * 8 + *(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20)] =
               (&DAT_0068ef54)
               [slot_idx * 8 + *(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20)] + 1;
        }
        else if ((*(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) < DAT_00665ed0) ||
                (DAT_00665ed0 + 0x10 <= *(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20)
                )) {
          *(int *)(&DAT_0068ef50 + slot_idx * 0x20) = *(int *)(&DAT_0068ef50 + slot_idx * 0x20) + 1;
        }
        else {
          for (card_idx = 0; card_idx < 5; card_idx = card_idx + 1) {
            if (*(int *)(&DAT_004ff590 +
                        *(int *)(&g_DuelCardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34) ==
                (&DAT_0068f0e0)[card_idx]) {
              (&DAT_0068ef54)[slot_idx * 8 + card_idx] = (&DAT_0068ef54)[slot_idx * 8 + card_idx] + 1;
            }
          }
        }
        *(int *)(&DAT_0068ef6c + slot_idx * 0x20) = *(int *)(&DAT_0068ef6c + slot_idx * 0x20) + 1;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00451c0c
 * Entry Point: 00451c0c
 * Size: 73 bytes
 */


void FUN_00451c0c(int32_t arg_1)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f70f(arg_1);
    }
    else {
      Mem_AllocOrFree_004468f5(arg_1,1);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00451c55
 * Entry Point: 00451c55
 * Size: 57 bytes
 */


void FUN_00451c55(void)

{
  if (g_DuelDebugModeFlag != 1) {
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f71a();
    }
    else {
      Mem_AllocOrFree_00446905();
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00451c8e
 * Entry Point: 00451c8e
 * Size: 61 bytes
 */


int32_t FUN_00451c8e(void)

{
  int32_t uval_1;
  
  if (g_DuelDebugModeFlag == 1) {
    uval_1 = 0;
  }
  else if (DAT_0068eed8 == 0) {
    uval_1 = Mem_AllocOrFree_0049ab06();
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Load_Title
 * Entry Point: 00451ccb
 * Size: 372 bytes
 */


int32_t Pic_Load_Title(void)

{
  int32_t uval_1;
  int32_t card_idx;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    uval_1 = Duel_RandomRange(5);
    switch(uval_1) {
    case 0:
      FUN_00439659(s_decks_0016_dck_004f8610,slot_idx,1,0xffffffff);
      card_idx = 2;
      break;
    case 1:
      FUN_00439659(s_decks_0283_dck_004f8620,slot_idx,1,0xffffffff);
      card_idx = 10;
      break;
    case 2:
      FUN_00439659(s_decks_0150_dck_004f8630,slot_idx,1,0xffffffff);
      card_idx = 0x10;
      break;
    case 3:
      FUN_00439659(s_decks_0076_dck_004f8640,slot_idx,1,0xffffffff);
      card_idx = 0x17;
      break;
    case 4:
      FUN_00439659(s_decks_0102_dck_004f8650,slot_idx,1,0xffffffff);
      card_idx = 0x20;
    }
  }
  DAT_00505988 = 0;
  DAT_00505984 = 1;
  for (match_count = 0; match_count < 0x10; match_count = match_count + 1) {
    (&DAT_0068ed90)[match_count] = 0xffffffff;
    (&DAT_0068ed50)[match_count] = (&DAT_0068ed90)[match_count];
  }
  DAT_0068f0b0 = 1;
  Mem_AllocOrFree_004d4e10(0,card_idx);
  DAT_0068f0b0 = 0;
  return 0;
}



/*
 * Decompiled function: FUN_00451e58
 * Entry Point: 00451e58
 * Size: 592 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451e58(void)

{
  uint32_t uval_1;
  
  uval_1 = DAT_0050538c / 0x34;
  DAT_00665ed0 = uval_1 - 0x10;
  g_DuelTargetCardId = uval_1 - 0x2d;
  DAT_0066aaec = uval_1 - 0x2c;
  DAT_006667b0 = uval_1 - 0x2b;
  DAT_00667994 = uval_1 - 0x2a;
  _DAT_0068ecc0 = uval_1 - 0x29;
  _DAT_0068ed0c = uval_1 - 0x28;
  DAT_006764c0 = uval_1 - 0x27;
  DAT_0066ab00 = uval_1 - 0x26;
  DAT_0068ed08 = uval_1 - 0x25;
  DAT_006764b4 = uval_1 - 0x24;
  DAT_0068f0c4 = uval_1 - 0x23;
  DAT_006664e8 = uval_1 - 0x22;
  DAT_0068f10c = uval_1 - 0x21;
  DAT_00666438 = uval_1 - 0x20;
  DAT_0066aac8 = uval_1 - 0x1f;
  DAT_00681ec8 = uval_1 - 0x1e;
  DAT_0066aaf8 = uval_1 - 0x1d;
  DAT_0066aafc = uval_1 - 0x1c;
  DAT_0068f2d0 = uval_1 - 0x1b;
  DAT_0068eee0 = uval_1 - 0x1a;
  DAT_00666414 = uval_1 - 0x19;
  DAT_0066675c = uval_1 - 0x18;
  DAT_00666750 = uval_1 - 0x17;
  DAT_00676514 = uval_1 - 0x16;
  DAT_00666420 = uval_1 - 0x15;
  DAT_0068eee8 = uval_1 - 0x14;
  DAT_00690c40 = uval_1 - 0x13;
  DAT_0068eed0 = uval_1 - 0x12;
  DAT_0066674c = uval_1 - 0x11;
  DAT_00666720 = 0x385;
  DAT_0066aae8 = 0x386;
  DAT_00666444 = 0x387;
  DAT_0068f108 = 0x388;
  DAT_00666450 = 0x389;
  DAT_0068f0fc = 0x38a;
  _DAT_00666710 = 8;
  _DAT_00666714 = 8;
  _DAT_00666718 = 0xc;
  _DAT_0066671c = 0xc;
  _DAT_0066aad8 = 0xffffffff;
  DAT_00666748 = 0xffffffff;
  DAT_0068f0f4 = 0xffffffff;
  g_DuelTargetCardSlot = 1;
  DAT_005ef980 = 0xffffffff;
  DAT_006826b4 = 0x30;
  _DAT_0068eed4 = 1;
  DAT_005071bc = 2;
  return;
}



