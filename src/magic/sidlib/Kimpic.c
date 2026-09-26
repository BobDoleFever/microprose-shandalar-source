/*
 * sidlib/Kimpic.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 268
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Pic_LoadImageFile
 * Entry Point: 0042351b
 * Size: 792 bytes
 */


int32_t
Pic_LoadImageFile(int player_id,int32_t card_slot,int32_t arg_3,char *str_4,uint8_t *arg_5)

{
  char *_Str2;
  int val_1;
  int32_t arg_1_00;
  int32_t arg_2_00;
  int local_414;
  int local_410;
  uint8_t local_40c [1024];
  uint8_t *match_count;
  int slot_idx;
  
  slot_idx = 8;
  _Str2 = strchr(str_4,0x2e);
  val_1 = _stricmp(&g_KimpicExtensionStr,_Str2);
  if (val_1 == 0) {
    g_PicFileStream = (int)fopen(str_4,&g_KimpicReadModeStr);
    if ((FILE *)g_PicFileStream == (FILE *)0x0) {
      return 0;
    }
    DAT_00703938 = str_4;
    if (arg_5 == (uint8_t *)0x1) {
      arg_5 = local_40c;
    }
    if (arg_5 == (uint8_t *)0x0) {
      Pic_DecodeKimpicHeader((void *)0x0);
      if (player < 0) {
        g_PicSourceHeight = 0;
      }
      if ((int)g_PicSourceWidth % 3 == 0) {
        local_410 = 0;
      }
      else {
        local_410 = 4 - (int)g_PicSourceWidth % 3;
      }
      g_PicAlignedRowPitch = g_PicSourceWidth + local_410;
      Pic_AllocateImageBuffer(g_PicAlignedRowPitch,g_PicSourceHeight,slot_idx);
      match_count = *(uint8_t **)(PTR_DAT_00520cb8 + 0x18);
      for (g_PicScanlineCounter = 0; g_PicScanlineCounter < g_PicSourceHeight; g_PicScanlineCounter = g_PicScanlineCounter + 1) {
        Pic_DecodeKimpicScanline(match_count);
        match_count = match_count + ((int)(slot_idx + (slot_idx >> 0x1f & 7U)) >> 3) * g_PicAlignedRowPitch;
      }
      fclose((FILE *)g_PicFileStream);
    }
    else {
      Pic_DecodeKimpicHeader(arg_5 + 6);
      *arg_5 = 0x4d;
      arg_5[1] = 0x31;
      *(int16_t *)(arg_5 + 2) = 0x300;
      arg_5[4] = 0;
      arg_5[5] = 0xff;
    }
  }
  else {
    DAT_00538ae0 = Pic_OpenArchiveStream(str_4,0x8000);
    if (DAT_00538ae0 == -1) {
      AssertOrLog(0,0x520cec,0xe4,s_Could_not_open_file__s_00520cd4);
      *(int32_t *)(PTR_DAT_00520cb8 + 8) = 0;
    }
    else {
      Pic_SeekImageStream(DAT_00538ae0);
      Pic_ReadCompressedChunk(arg_1_00,arg_2_00,(uint16_t *)arg_5);
      if ((g_PicSourceWidth & 3) == 0) {
        local_414 = 0;
      }
      else {
        local_414 = 4 - (g_PicSourceWidth & 3);
      }
      g_PicAlignedRowPitch = g_PicSourceWidth + local_414;
      val_1 = Pic_AllocateImageBuffer(g_PicSourceWidth,g_PicSourceHeight,slot_idx);
      if (val_1 == 0) {
        *(int32_t *)(PTR_DAT_00520cb8 + 8) = 0;
      }
      else {
        match_count = *(uint8_t **)(PTR_DAT_00520cb8 + 0x18);
        g_PicScanlineCounter = 0;
        while (g_PicScanlineCounter < g_PicSourceHeight) {
          Mem_AllocOrFree_0070d484(match_count,g_PicSourceWidth);
          g_PicScanlineCounter = g_PicScanlineCounter + 1;
          match_count = (uint8_t *)((int)match_count +
                            *(int *)(PTR_DAT_00520cb8 + 0x2c) +
                            ((int)(slot_idx * g_PicSourceWidth +
                                  ((int)(slot_idx * g_PicSourceWidth) >> 0x1f & 7U)) >> 3));
        }
      }
      Pic_Subsystem_004238ee(DAT_00538ae0);
    }
  }
  return *(int32_t *)(PTR_DAT_00520cb8 + 8);
}



/*
 * Decompiled function: Pic_LoadKimPicture
 * Entry Point: 00423833
 * Size: 135 bytes
 */


int Pic_LoadKimPicture(char *filepath)

{
  char local_1fc [500];
  int slot_idx;
  
  slot_idx = Pic_LoadImageFile(0,0,0,str_1,(uint8_t *)0x0);
  if (slot_idx != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_00520cb8);
  }
  if (DAT_006b157c != 0) {
    sprintf(local_1fc,s__08X_LoadKimPicture___s___file_m_00520d10,slot_idx,str_1,
            *(int32_t *)PTR_DAT_00520cb8);
    OutputDebugStringA(local_1fc);
  }
  return slot_idx;
}



/*
 * Decompiled function: Pic_OpenArchiveStream
 * Entry Point: 004238ba
 * Size: 52 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pic_OpenArchiveStream(char *filepath,int arg2)

{
  int val_1;
  
  val_1 = _open(str_1,arg2);
  _DAT_00538ae8 = 0xffffffff;
  return val_1;
}



/*
 * Decompiled function: Pic_Subsystem_004238ee
 * Entry Point: 004238ee
 * Size: 43 bytes
 */


void Pic_Subsystem_004238ee(int player_id)

{
  if (player != DAT_00520cbc) {
    _close(player);
  }
  return;
}



/*
 * Decompiled function: Pic_SeekImageStream
 * Entry Point: 00423919
 * Size: 39 bytes
 */


void Pic_SeekImageStream(int32_t player)

{
  DAT_00538ae4 = player;
  DAT_00706500 = PTR_DAT_005327b0;
  DAT_0067f43c = Pic_Subsystem_00423940;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00423940
 * Entry Point: 00423940
 * Size: 60 bytes
 */


int Pic_Subsystem_00423940(void)

{
  int val_1;
  
  val_1 = _read(DAT_00538ae4,&DAT_00706510,0x200);
  DAT_00706500 = &DAT_00706510;
  return val_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423980
 * Entry Point: 00423980
 * Size: 353 bytes
 */


int Pic_Subsystem_00423980(int hInst,int32_t hWnd,uint32_t flags)

{
  int val_1;
  FARPROC pFVar2;
  int match_count;
  
  if (g_KimpicDecoderInitialized == 0) {
    DAT_0067f3c8 = LoadLibraryA(PTR_s_magsnd_00520d4c);
    if (DAT_0067f3c8 == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (match_count = 0; match_count < 0x1b; match_count = match_count + 1) {
        pFVar2 = GetProcAddress(DAT_0067f3c8,(LPCSTR)(match_count + 1U & 0xffff));
        (&DAT_0067f3d0)[match_count] = pFVar2;
        if ((&DAT_0067f3d0)[match_count] == (code *)0x0) {
          FreeLibrary(DAT_0067f3c8);
          Pic_Subsystem_004241ae();
          return 4;
        }
      }
      if ((hInst == 0) && ((flags & 2) == 0)) {
        FreeLibrary(DAT_0067f3c8);
        Pic_Subsystem_004241ae();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_0067f3d0)(hInst,hWnd,flags);
        if (val_1 == 0) {
          DAT_00520d48 = 1;
          if ((flags & 2) != 0) {
            DAT_00520d40 = 1;
          }
          g_KimpicDecoderInitialized = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_0067f3c8);
          Pic_Subsystem_004241ae();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423ae1
 * Entry Point: 00423ae1
 * Size: 118 bytes
 */


void Pic_Subsystem_00423ae1(void)

{
  if (g_KimpicDecoderInitialized != 0) {
    g_KimpicDecoderInitialized = 0;
    if ((DAT_00520d48 != 0) && (DAT_00520d40 == 0)) {
      (*DAT_0067f3d4)();
    }
    FreeLibrary(DAT_0067f3c8);
    Pic_Subsystem_004241ae();
    DAT_0067f3c8 = (HMODULE)0x0;
    DAT_00520d40 = 0;
    DAT_00520d48 = 0;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00423b57
 * Entry Point: 00423b57
 * Size: 60 bytes
 */


int32_t Pic_Subsystem_00423b57(int32_t player,int32_t card_slot,int32_t arg_3)

{
  int32_t uval_1;
  
  if (g_KimpicDecoderInitialized == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3d8)(player,card_slot,arg_3);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423b93
 * Entry Point: 00423b93
 * Size: 52 bytes
 */


int32_t Pic_Subsystem_00423b93(int32_t player)

{
  int32_t uval_1;
  
  if (g_KimpicDecoderInitialized == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3dc)(player);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423bc7
 * Entry Point: 00423bc7
 * Size: 45 bytes
 */


int32_t Pic_Subsystem_00423bc7(void)

{
  int32_t uval_1;
  
  if (g_KimpicDecoderInitialized == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3e0)();
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423bf4
 * Entry Point: 00423bf4
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423bf4(int32_t sound_id,int32_t flags)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3e4)(sound_id,flags);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423c39
 * Entry Point: 00423c39
 * Size: 73 bytes
 */


int32_t Pic_Subsystem_00423c39(int32_t filename,int32_t loop_flag,int32_t out_handle)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3e8)(filename,loop_flag,out_handle);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423c82
 * Entry Point: 00423c82
 * Size: 65 bytes
 */


int32_t Pic_Subsystem_00423c82(int32_t sound_id)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3ec)(sound_id);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423cc3
 * Entry Point: 00423cc3
 * Size: 48 bytes
 */


void Pic_Subsystem_00423cc3(void)

{
  if ((g_KimpicDecoderInitialized != 0) && (g_KimpicDecoderInitialized != 2)) {
    (*DAT_0067f3f0)();
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00423cf3
 * Entry Point: 00423cf3
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423cf3(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3f4)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423d38
 * Entry Point: 00423d38
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423d38(int32_t value,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3f8)(value,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423d7d
 * Entry Point: 00423d7d
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423d7d(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f3fc)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423dc2
 * Entry Point: 00423dc2
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423dc2(int32_t value,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f400)(value,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423e07
 * Entry Point: 00423e07
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423e07(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f404)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423e4c
 * Entry Point: 00423e4c
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423e4c(int32_t value,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f408)(value,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423e91
 * Entry Point: 00423e91
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423e91(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f40c)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423ed6
 * Entry Point: 00423ed6
 * Size: 58 bytes
 */


int32_t Pic_Subsystem_00423ed6(void)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f410)();
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423f10
 * Entry Point: 00423f10
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423f10(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f414)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423f55
 * Entry Point: 00423f55
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423f55(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f418)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423f9a
 * Entry Point: 00423f9a
 * Size: 65 bytes
 */


int32_t Pic_Subsystem_00423f9a(int32_t player)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f420)(player);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00423fdb
 * Entry Point: 00423fdb
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00423fdb(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f41c)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00424020
 * Entry Point: 00424020
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_00424020(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f424)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00424065
 * Entry Point: 00424065
 * Size: 66 bytes
 */


int32_t Pic_Subsystem_00424065(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_0067f428)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004240a7
 * Entry Point: 004240a7
 * Size: 69 bytes
 */


int32_t Pic_Subsystem_004240a7(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f42c)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004240ec
 * Entry Point: 004240ec
 * Size: 55 bytes
 */


int32_t Pic_Subsystem_004240ec(void)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_0067f430)();
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00424123
 * Entry Point: 00424123
 * Size: 66 bytes
 */


int32_t Pic_Subsystem_00424123(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_0067f434)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00424165
 * Entry Point: 00424165
 * Size: 73 bytes
 */


int32_t Pic_Subsystem_00424165(int32_t player,int32_t card_slot,int32_t arg_3)

{
  int32_t uval_1;
  
  if ((g_KimpicDecoderInitialized == 0) || (g_KimpicDecoderInitialized == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0067f438)(player,card_slot,arg_3);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004241ae
 * Entry Point: 004241ae
 * Size: 58 bytes
 */


void Pic_Subsystem_004241ae(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x1b; slot_idx = slot_idx + 1) {
    (&DAT_0067f3d0)[slot_idx] = 0;
  }
  return;
}



/*
 * Decompiled function: UI_RegisterClass_004241f0
 * Entry Point: 004241f0
 * Size: 146 bytes
 */


bool UI_RegisterClass_004241f0(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_WndProc_00424282;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}



/*
 * Decompiled function: UI_WndProc_00424282
 * Entry Point: 00424282
 * Size: 516 bytes
 */


LRESULT UI_WndProc_00424282(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam)

{
  HDC hdc;
  LRESULT LVar1;
  tagPAINTSTRUCT local_134;
  CHAR local_f4 [200];
  tagRECT local_2c;
  HDC color_idx;
  tagRECT target_idx;
  HBRUSH slot_idx;
  
  if (uMsg < 0xd) {
    if (uMsg == 0xc) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      LVar1 = DefWindowProcA(hwnd,0xc,(WPARAM)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 1) {
      return 0;
    }
  }
  else if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      color_idx = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      GetClientRect(hwnd,&target_idx);
      slot_idx = CreateSolidBrush(0xffff);
      FillRect(color_idx,&target_idx,slot_idx);
      DeleteObject(slot_idx);
      return 1;
    }
    if (uMsg == 0xf) {
      hdc = BeginPaint(hwnd,&local_134);
      if (hdc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(hdc);
        GetWindowTextA(hwnd,local_f4,200);
        SetTextAlign(hdc,6);
        SetBkMode(hdc,1);
        SetTextColor(hdc,0);
        GetClientRect(hwnd,&local_2c);
        Palette_Subsystem_0049e5bc(hdc,&local_2c.left,local_f4,1);
        EndPaint(hwnd,&local_134);
      }
      return 0;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    LVar1 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
    return LVar1;
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}



/*
 * Decompiled function: UI_LoadHallBackdrop
 * Entry Point: 004244a0
 * Size: 81 bytes
 */


void UI_LoadHallBackdrop(void)

{
  Mem_AllocOrFree_00510de0(1,s_hallback_pic_00520d58);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  Ai_Subsystem_004cd1d1();
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00424500
 * Entry Point: 00424500
 * Size: 597 bytes
 */


int Pic_Subsystem_00424500(char *filepath,char *mode_str)

{
  FILE *_File;
  int val_1;
  char *char_ptr_2;
  size_t len_3;
  int local_310;
  char local_30c [252];
  char local_210 [264];
  char local_108 [252];
  int match_count;
  int slot_idx;
  
  if (g_IsAiThinking != 1) {
    strcpy(local_108,&DAT_00520d68);
    strcat(local_108,str_2);
    strcat(local_108,&DAT_00520d6c);
    strcpy(local_210,&g_GameInstallDirectory);
    strcat(local_210,&DAT_00520d70);
    strcpy(local_210,str_1);
    _File = fopen(local_210,&DAT_00520d74);
    if (_File != (FILE *)0x0) {
      do {
        val_1 = strcmp(local_108,local_30c);
        if (val_1 == 0) {
          fscanf(_File,&DAT_00520d78,&slot_idx);
          fgets(local_30c,0x50,_File);
          match_count = 0;
          for (local_310 = 0; (local_310 < slot_idx && (local_310 < 0x32)); local_310 = local_310 + 1
              ) {
            char_ptr_2 = fgets(&g_OverworldGoldAmount + local_310 * 0xfa,0xfa,_File);
            if (char_ptr_2 == (char *)0x0) {
              fclose(_File);
              return -match_count;
            }
            len_3 = strlen(&g_OverworldGoldAmount + local_310 * 0xfa);
            (&DAT_0069f74f)[local_310 * 0xfa + len_3] = 0;
            match_count = match_count + 1;
          }
          fclose(_File);
          if (match_count < slot_idx) {
            return -match_count;
          }
          return match_count;
        }
        char_ptr_2 = fgets(local_30c,0x50,_File);
      } while (char_ptr_2 != (char *)0x0);
      fclose(_File);
    }
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042475a
 * Entry Point: 0042475a
 * Size: 340 bytes
 */


int Pic_Subsystem_0042475a(char *filepath,char *mode_str)

{
  int player_id;
  int val_1;
  size_t len_2;
  int target_idx;
  int card_idx;
  int match_count;
  
  if (g_IsAiThinking == 1) {
    player = 0;
  }
  else {
    player = Pic_Subsystem_00424500(str_1,str_2);
    for (match_count = 0; val_1 = abs(player), match_count < val_1; match_count = match_count + 1) {
      len_2 = strlen(&g_OverworldGoldAmount + match_count * 0xfa);
      target_idx = 0;
      for (card_idx = 0; card_idx < (int)len_2; card_idx = card_idx + 1) {
        if (((&g_OverworldGoldAmount)[match_count * 0xfa + card_idx] == '\\') &&
           ((&DAT_0069f751)[match_count * 0xfa + card_idx] == 'n')) {
          (&g_OverworldGoldAmount)[match_count * 0xfa + target_idx] = 10;
          card_idx = card_idx + 1;
        }
        else {
          (&g_OverworldGoldAmount)[match_count * 0xfa + target_idx] =
               (&g_OverworldGoldAmount)[match_count * 0xfa + card_idx];
        }
        target_idx = target_idx + 1;
      }
      (&g_OverworldGoldAmount)[match_count * 0xfa + target_idx] = 0;
    }
  }
  return player;
}



/*
 * Decompiled function: UI_LoadPhaseBackdrop
 * Entry Point: 004248b0
 * Size: 248 bytes
 */


int32_t UI_LoadPhaseBackdrop(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_PhaseDisplayWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00538b40 = CreatePopupMenu();
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_Phase_pic_00520d7c);
  DAT_00538b20 = Pic_LoadKimPicture(local_138);
  DAT_00538b78 = 2;
  DAT_00538b3c = CreateHatchBrush(3,0x808080);
  return local_30;
}



/*
 * Decompiled function: Pic_Subsystem_004249a8
 * Entry Point: 004249a8
 * Size: 118 bytes
 */


void Pic_Subsystem_004249a8(void)

{
  if (DAT_00538b40 != (HMENU)0x0) {
    DestroyMenu(DAT_00538b40);
  }
  DAT_00538b40 = (HMENU)0x0;
  if (DAT_00538b20 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00538b20);
  }
  if (DAT_00538b3c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538b3c);
  }
  DAT_00538b20 = (HANDLE)0x0;
  DAT_00538b3c = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_LoadPhaseCombatBackdrop
 * Entry Point: 00424a1e
 * Size: 209 bytes
 */


int32_t UI_LoadPhaseCombatBackdrop(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_CombatDefenseWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_PhaseCombat_pic_00520d90);
  DAT_00538b38 = Pic_LoadKimPicture(local_138);
  return local_30;
}



/*
 * Decompiled function: Pic_Subsystem_00424aef
 * Entry Point: 00424aef
 * Size: 48 bytes
 */


void Pic_Subsystem_00424aef(void)

{
  if (DAT_00538b38 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00538b38);
  }
  DAT_00538b38 = (HANDLE)0x0;
  return;
}



/*
 * Decompiled function: UI_PhaseDisplayWndProc
 * Entry Point: 00424b1f
 * Size: 4956 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT UI_PhaseDisplayWndProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam)

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
  char local_4c8 [264];
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
  char local_2f4 [264];
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
  char local_1a8 [264];
  ULONG_PTR local_a0;
  int local_9c;
  int local_98;
  char local_94 [100];
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
      Ai_Subsystem_004b74b1(&local_348,&local_3b8);
      if ((match_count != local_3b8) || (slot_idx != local_348)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (DAT_00538b20 == (HANDLE)0x0) {
        strcpy(local_4c8,&g_AiCurrentChoiceIndex);
        strcat(local_4c8,s__WINBK_Phase_pic_00520e78);
        DAT_00538b20 = (HANDLE)Pic_LoadKimPicture(local_4c8);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_3bc = g_HdcBackBuffer;
      local_35c = SaveDC(g_HdcBackBuffer);
      GetClientRect(hwnd,&local_344);
      if (DAT_00538b20 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(4);
        FillRect(local_3bc,&local_344,pHVar3);
      }
      else {
        GetObjectA(DAT_00538b20,0x18,local_3b4);
        FUN_004f3bc7(local_3bc,&local_344.left,DAT_00538b20,0,0,local_3b0 / DAT_00538b78,local_3ac);
      }
      if ((local_348 != -1) && (local_3b8 != -1)) {
        Pic_Subsystem_004262cf(&local_358,local_348,local_3b8,local_344.right,local_344.bottom);
        local_3c0 = CreateRectRgnIndirect(&local_358);
        SelectClipRgn(local_3bc,local_3c0);
        if (DAT_00538b20 == (HANDLE)0x0) {
          pHVar3 = GetStockObject(2);
          FillRect(local_3bc,&local_344,pHVar3);
        }
        else {
          GetObjectA(DAT_00538b20,0x18,local_3b4);
          FUN_004f3bc7(local_3bc,&local_344.left,DAT_00538b20,local_3b0 - local_3b0 / DAT_00538b78,0
                       ,local_3b0 / DAT_00538b78,local_3ac);
        }
        SelectClipRgn(local_3bc,(HRGN)0x0);
        DeleteObject(local_3c0);
      }
      RestoreDC(g_HdcBackBuffer,local_35c);
      Pic_Subsystem_00426518(local_3bc,(int)&local_344);
      local_3bc = BeginPaint(hwnd,&local_39c);
      if (local_3bc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_3bc);
        GetClientRect(hwnd,&local_344);
        if (DAT_0068a674 != 0) {
          pHVar3 = GetStockObject(0);
          FillRect(local_3bc,&local_344,pHVar3);
          Sleep(200);
        }
        BitBlt(local_3bc,0,0,local_344.right,local_344.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        Ai_Subsystem_004b756f(&local_4cc);
        if (local_4cc != -1) {
          if (local_4cc == 0) {
            local_344.bottom = local_344.bottom - (local_344.bottom - local_344.top) / 2;
          }
          else {
            local_344.top = local_344.top + (local_344.bottom - local_344.top) / 2;
          }
          SelectObject(local_3bc,DAT_00538b3c);
          SetBkMode(local_3bc,1);
          Rectangle(local_3bc,local_344.left,local_344.top,local_344.right,local_344.bottom);
        }
        EndPaint(hwnd,&local_39c);
        match_count = local_3b8;
        slot_idx = local_348;
        SetWindowLongA(hwnd,0,local_3b8);
        SetWindowLongA(hwnd,4,slot_idx);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
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
      LVar5 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
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
      Pic_Subsystem_00425ee3(&local_514,&local_4f4,&local_4fc,&local_5b0);
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
        if (DAT_006b1578 != 0) {
          local_500 = local_504 + local_508 + 0x96;
          AppendMenuA(DAT_00538b40,0,local_500,s_Run_to_this_phase_00520e8c);
        }
        val_4 = GetMenuItemCount(DAT_00538b40);
        if (val_4 != 0) {
          AppendMenuA(DAT_00538b40,0x800,0,(LPCSTR)0x0);
        }
        local_4f8 = local_504 + local_508 + 200;
        AppendMenuA(DAT_00538b40,0,local_4f8,s_Mark_this_phase_to_always_stop_00520ea0);
        Ai_Subsystem_004b74fa(local_5ac,local_4fc);
        if (local_5ac[local_5b0] != 0) {
          CheckMenuItem(DAT_00538b40,local_4f8,8);
        }
        local_50c = local_504 + local_508 + 0xfa;
        AppendMenuA(DAT_00538b40,0,local_50c,s_Help_for_this_phase____00520ec0);
      }
      AppendMenuA(DAT_00538b40,0,100,s_Help____00520ed8);
      return 0;
    }
    if (uMsg == 0x111) {
      if (((uint32_t)wParam & 0xffff) == 100) {
        local_a0 = 0x7e5;
        strcpy(local_1a8,&g_GameInstallDirectory);
        strcat(local_1a8,s__duel_hlp_00520e60);
        WinHelpA(g_MainAppHwnd,local_1a8,1,local_a0);
      }
      else {
        uval_2 = (uint32_t)wParam & 0xffff;
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
          DAT_00627a84 = local_1b4;
          DAT_00627a88 = local_1c0;
          g_AiTemporaryCardState = 0;
          _DAT_00538b68 = 0xfffffffe;
          _DAT_00538b6c = 0xffffffff;
          _DAT_00538b70 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x538b68);
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
          if (((&g_PlayerManaPoolAvailable)[local_1e8 * 4 + local_1b4 * 0x98] & 1) == 0) {
            *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1e8 * 4 + local_1b4 * 0x98) | 1;
          }
          else {
            *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1e8 * 4 + local_1b4 * 0x98) & 0xfffffffe;
          }
          Rules_ParseFilter_0050065d();
          Ai_Subsystem_004b42dc();
          GetClientRect(hwnd,&local_1e0);
          Pic_Subsystem_004262cf(&local_1d0,local_1e4,local_1e8,local_1e0.right,local_1e0.bottom);
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
          strcpy(local_2f4,&g_GameInstallDirectory);
          strcat(local_2f4,s__duel_hlp_00520e6c);
          WinHelpA(g_MainAppHwnd,local_2f4,1,local_1ec);
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
      Pic_Subsystem_00425ee3(&local_310,&local_308,&local_318,&local_2f8);
      if ((local_2f8 != -1) && (DAT_006b1578 != 0)) {
        DAT_00627a84 = local_318;
        DAT_00627a88 = local_2f8;
        g_AiTemporaryCardState = local_314;
        _DAT_00538b28 = 0xfffffffe;
        _DAT_00538b2c = 0xffffffff;
        _DAT_00538b30 = 0xffffffff;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538b28);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_5b4 = GetMenuItemCount(DAT_00538b40);
        while (local_5b4 != 0) {
          DeleteMenu(DAT_00538b40,0,0x400);
          local_5b4 = local_5b4 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_4e4.x = lParam & 0xffff;
      local_4e4.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_4e4);
      SetRect(&local_4dc,local_4e4.x,local_4e4.y,local_4e4.x + 1,local_4e4.y + 1);
      TrackPopupMenu(DAT_00538b40,2,local_4e4.x,local_4e4.y,0,hwnd,&local_4dc);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      Pic_Util_004280cf(hwnd,wParam,lParam);
      return 0;
    }
    if (uMsg == 0x432) {
      match_count = GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      Ai_Subsystem_004b74b1(&local_98,&local_9c);
      if ((match_count != local_9c) || (slot_idx != local_98)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_2c.x = lParam & 0xffff;
      local_2c.y = lParam >> 0x10;
      GetClientRect(hwnd,&color_idx);
      Pic_Subsystem_00425ee3(&local_2c,&color_idx,&loop_idx,&local_30);
      local_24 = 1;
      if (loop_idx == 0) {
        strcpy(local_94,s_Your_00520da8);
      }
      else {
        Ai_Subsystem_004b6f49(local_94);
        strcat(local_94,&DAT_00520db0);
      }
      switch(local_30) {
      case 1:
        strcat(local_94,s_Untap_phase_00520db4);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
        strcat(local_94,s_Upkeep_phase_00520dc0);
        break;
      default:
        local_24 = 0;
        break;
      case 10:
        strcat(local_94,s_Draw_phase_00520dd0);
        break;
      case 0x14:
        strcat(local_94,s_Main_phase__pre_combat__00520ddc);
        break;
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
        if (loop_idx == 1) {
          strcat(local_94,s_Main_phase__combat__00520df4);
        }
        else {
          strcat(local_94,s_Main_phase__declare_attack__00520e08);
        }
        break;
      case 0x1e:
        strcat(local_94,s_Main_phase__post_combat__00520e24);
        break;
      case 0x1f:
        strcat(local_94,s_Discard_phase_00520e40);
        break;
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x25:
        strcat(local_94,s_Cleanup_phase_00520e50);
      }
      if (local_24 == 0) {
        return 0;
      }
      strcpy(wParam,local_94);
      return local_24;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}



/*
 * Decompiled function: Pic_Subsystem_00425ee3
 * Entry Point: 00425ee3
 * Size: 1004 bytes
 */


void Pic_Subsystem_00425ee3(POINT *x,RECT *card_slot,int32_t *arg_3,int *height)

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
  
  CopyRect(&local_28,card_slot);
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
  Pic_Subsystem_004262cf(&target_idx,1,1,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt);
  if (BVar1 != 0) {
    slot_idx = 1;
  }
  Pic_Subsystem_004262cf(&target_idx,1,4,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_00);
  if (BVar1 != 0) {
    slot_idx = 4;
  }
  Pic_Subsystem_004262cf(&target_idx,1,10,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_01);
  if (BVar1 != 0) {
    slot_idx = 10;
  }
  Pic_Subsystem_004262cf(&target_idx,1,0x14,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_02);
  if (BVar1 != 0) {
    slot_idx = 0x14;
  }
  Pic_Subsystem_004262cf(&target_idx,1,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_03);
  if (BVar1 != 0) {
    slot_idx = 0x16;
  }
  Pic_Subsystem_004262cf(&target_idx,1,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_04);
  if (BVar1 != 0) {
    slot_idx = 0x1e;
  }
  Pic_Subsystem_004262cf(&target_idx,1,0x1f,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_05);
  if (BVar1 != 0) {
    slot_idx = 0x1f;
  }
  Pic_Subsystem_004262cf(&target_idx,1,0x20,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_06);
  if (BVar1 != 0) {
    slot_idx = 0x20;
  }
  if (slot_idx == -1) {
    local_34 = 0;
    Pic_Subsystem_004262cf(&target_idx,0,1,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_07);
    if (BVar1 != 0) {
      slot_idx = 1;
    }
    Pic_Subsystem_004262cf(&target_idx,0,4,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_08);
    if (BVar1 != 0) {
      slot_idx = 4;
    }
    Pic_Subsystem_004262cf(&target_idx,0,10,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_09);
    if (BVar1 != 0) {
      slot_idx = 10;
    }
    Pic_Subsystem_004262cf(&target_idx,0,0x14,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_10);
    if (BVar1 != 0) {
      slot_idx = 0x14;
    }
    Pic_Subsystem_004262cf(&target_idx,0,0x15,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_11);
    if (BVar1 != 0) {
      slot_idx = 0x15;
    }
    Pic_Subsystem_004262cf(&target_idx,0,0x1e,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_12);
    if (BVar1 != 0) {
      slot_idx = 0x1e;
    }
    Pic_Subsystem_004262cf(&target_idx,0,0x1f,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&target_idx,pt_13);
    if (BVar1 != 0) {
      slot_idx = 0x1f;
    }
    Pic_Subsystem_004262cf(&target_idx,0,0x20,local_28.right,local_28.bottom);
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
 * Decompiled function: Pic_Subsystem_004262cf
 * Entry Point: 004262cf
 * Size: 585 bytes
 */


void Pic_Subsystem_004262cf(LPRECT player,int card_slot,int event_type,int arg_4,int arg_5)

{
  int32_t slot_idx;
  
  if ((card_slot == -1) || (arg_3 == -1)) {
    SetRect(player,0,0,0,0);
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
    else if (((card_slot == 1) && (arg_3 == 0x16)) || ((card_slot == 0 && (arg_3 == 0x15)))) {
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
      SetRect(player,0,0,0,0);
    }
    else {
      if (card_slot == 0) {
        slot_idx = slot_idx + (arg_5 * 0x1ae) / 0x2f8;
      }
      SetRect(player,0,slot_idx,arg_4,slot_idx + (arg_5 * 0x28) / 0x2f8);
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00426518
 * Entry Point: 00426518
 * Size: 685 bytes
 */


void Pic_Subsystem_00426518(HDC hdc,int arg2)

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
  
  Ai_Subsystem_004b765d(&slot_idx,&local_24);
  if ((slot_idx == -1) || (local_24 == -1)) {
    match_count = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,match_count);
    for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
      Ai_Subsystem_004b74fa(local_d0,card_idx);
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if (local_d0[local_d4] != 0) {
          Pic_Subsystem_004262cf
                    (&local_34,card_idx,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&loop_idx,&local_34);
            loop_idx.left = loop_idx.right - (local_34.right - local_34.left) / 3;
            loop_idx.top = loop_idx.bottom -
                           ((loop_idx.right - loop_idx.left) * (local_34.bottom - local_34.top)) /
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
          Pic_Subsystem_004262cf
                    (&local_34,card_idx,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&loop_idx,&local_34);
            loop_idx.right = loop_idx.left + (local_34.right - local_34.left) / 3;
            loop_idx.top = loop_idx.bottom -
                           ((loop_idx.right - loop_idx.left) * (local_34.bottom - local_34.top)) /
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
 * Entry Point: 004267c5
 * Size: 4210 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT UI_CombatDefenseWndProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam)

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
  char local_4b8 [264];
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
  char local_2e4 [264];
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
  char local_19c [264];
  ULONG_PTR local_94;
  int local_90;
  char local_8c [100];
  int local_28;
  POINT local_24;
  int color_idx;
  tagRECT target_idx;
  int slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b74b1(&local_338,&local_3a8);
      if (DAT_00538b38 == (HANDLE)0x0) {
        strcpy(local_4b8,&g_AiCurrentChoiceIndex);
        strcat(local_4b8,s__WINBK_PhaseCombat_pic_00520fb0);
        DAT_00538b38 = (HANDLE)Pic_LoadKimPicture(local_4b8);
      }
      if (slot_idx != local_3a8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_3ac = g_HdcBackBuffer;
      local_34c = SaveDC(g_HdcBackBuffer);
      GetClientRect(hwnd,&local_334);
      Ai_Subsystem_004b74b1(&local_338,(int32_t *)0x0);
      if (DAT_00538b38 == (HANDLE)0x0) {
        pHVar2 = GetStockObject(4);
        FillRect(local_3ac,&local_334,pHVar2);
      }
      else {
        GetObjectA(DAT_00538b38,0x18,local_3a4);
        if (local_338 == 1) {
          local_5a0 = 0;
        }
        else {
          local_5a0 = local_3a0 / 2;
        }
        FUN_004f3bc7(local_3ac,&local_334.left,DAT_00538b38,local_5a0,0,
                     (int)(local_3a0 + (local_3a0 >> 0x1f & 3U)) >> 2,local_39c);
      }
      if (local_3a8 != -1) {
        GetClientRect(hwnd,&local_334);
        Pic_Subsystem_00427a0a(&local_348,local_3a8,local_334.right,local_334.bottom);
        local_3b0 = CreateRectRgnIndirect(&local_348);
        SelectClipRgn(local_3ac,local_3b0);
        if (DAT_00538b38 == (HANDLE)0x0) {
          pHVar2 = GetStockObject(2);
          FillRect(local_3ac,&local_334,pHVar2);
        }
        else {
          GetObjectA(DAT_00538b38,0x18,local_3a4);
          if (local_338 == 1) {
            local_5a4 = local_3a0 + (local_3a0 >> 0x1f & 3U);
          }
          else {
            local_5a4 = local_3a0 * 3 + (local_3a0 * 3 >> 0x1f & 3U);
          }
          local_5a4 = local_5a4 >> 2;
          FUN_004f3bc7(local_3ac,&local_334.left,DAT_00538b38,local_5a4,0,
                       (int)(local_3a0 + (local_3a0 >> 0x1f & 3U)) >> 2,local_39c);
        }
        SelectClipRgn(local_3ac,(HRGN)0x0);
        DeleteObject(local_3b0);
      }
      RestoreDC(g_HdcBackBuffer,local_34c);
      Pic_Subsystem_00427bcb(local_3ac,(int)&local_334);
      local_3ac = BeginPaint(hwnd,&local_38c);
      if (local_3ac != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_3ac);
        GetClientRect(hwnd,&local_334);
        BitBlt(local_3ac,0,0,local_334.right,local_334.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_38c);
        slot_idx = local_3a8;
        SetWindowLongA(hwnd,0,local_3a8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
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
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
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
      Pic_Subsystem_0042784d(&local_4fc,&local_4e4,&local_598);
      Ai_Subsystem_004b74b1(&local_4d4,(int32_t *)0x0);
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
        if (DAT_006b1578 != 0) {
          local_4ec = local_4f0 + 0x96;
          AppendMenuA(DAT_00538b40,0,local_4ec,s_Run_to_this_phase_00520fc8);
        }
        val_3 = GetMenuItemCount(DAT_00538b40);
        if (val_3 != 0) {
          AppendMenuA(DAT_00538b40,0x800,0,(LPCSTR)0x0);
        }
        local_4e8 = local_4f0 + 200;
        AppendMenuA(DAT_00538b40,0,local_4e8,s_Mark_this_phase_to_always_stop_00520fdc);
        Ai_Subsystem_004b74fa(local_594,local_4d4);
        if (local_594[local_598] != 0) {
          CheckMenuItem(DAT_00538b40,local_4e8,8);
        }
        local_4f4 = local_4f0 + 0xfa;
        AppendMenuA(DAT_00538b40,0,local_4f4,s_Help_for_this_phase____00520ffc);
      }
      AppendMenuA(DAT_00538b40,0,100,s_Help____00521014);
      return 0;
    }
    if (uMsg == 0x111) {
      if (((uint32_t)wParam & 0xffff) == 100) {
        local_94 = 0x7e5;
        strcpy(local_19c,&g_GameInstallDirectory);
        strcat(local_19c,s__duel_hlp_00520f98);
        WinHelpA(g_MainAppHwnd,local_19c,1,local_94);
      }
      else {
        uval_1 = (uint32_t)wParam & 0xffff;
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
          Ai_Subsystem_004b74b1(&local_1a0,(int32_t *)0x0);
          DAT_00627a84 = local_1a0;
          DAT_00627a88 = local_1b0;
          g_AiTemporaryCardState = 0;
          _DAT_00538b58 = 0xfffffffe;
          _DAT_00538b5c = 0xffffffff;
          _DAT_00538b60 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x538b58);
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
          Ai_Subsystem_004b74b1(&local_1d4,(int32_t *)0x0);
          if (((&g_PlayerManaPoolAvailable)[local_1d8 * 4 + local_1d4 * 0x98] & 1) == 0) {
            *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1d8 * 4 + local_1d4 * 0x98) | 1;
          }
          else {
            *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint32_t *)(&g_PlayerManaPoolAvailable + local_1d8 * 4 + local_1d4 * 0x98) & 0xfffffffe;
          }
          Ai_Subsystem_004b42dc();
          GetClientRect(hwnd,&local_1d0);
          Pic_Subsystem_00427a0a(&local_1c0,local_1d8,local_1d0.right,local_1d0.bottom);
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
          strcpy(local_2e4,&g_GameInstallDirectory);
          strcat(local_2e4,s__duel_hlp_00520fa4);
          WinHelpA(g_MainAppHwnd,local_2e4,1,local_1dc);
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
      Pic_Subsystem_0042784d(&local_300,&local_2f8,&local_2e8);
      if ((local_2e8 != -1) && (DAT_006b1578 != 0)) {
        Ai_Subsystem_004b74b1(&local_324,(int32_t *)0x0);
        DAT_00627a84 = local_324;
        DAT_00627a88 = local_2e8;
        g_AiTemporaryCardState = local_304;
        _DAT_00538b48 = 0xfffffffe;
        _DAT_00538b4c = 0xffffffff;
        _DAT_00538b50 = 0xffffffff;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538b48);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_59c = GetMenuItemCount(DAT_00538b40);
        while (local_59c != 0) {
          DeleteMenu(DAT_00538b40,0,0x400);
          local_59c = local_59c + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x204) {
      local_4d0.x = lParam & 0xffff;
      local_4d0.y = lParam >> 0x10;
      if (DAT_006b1578 != 0) {
        ClientToScreen(hwnd,&local_4d0);
        SetRect(&local_4c8,local_4d0.x,local_4d0.y,local_4d0.x + 1,local_4d0.y + 1);
        TrackPopupMenu(DAT_00538b40,2,local_4d0.x,local_4d0.y,0,hwnd,&local_4c8);
      }
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      Pic_Util_004280cf(hwnd,wParam,lParam);
      return 0;
    }
    if (uMsg == 0x432) {
      slot_idx = GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b74b1((int32_t *)0x0,&local_90);
      if (local_90 != slot_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_24.x = lParam & 0xffff;
      local_24.y = lParam >> 0x10;
      GetClientRect(hwnd,&target_idx);
      Pic_Subsystem_0042784d(&local_24,&target_idx,&local_28);
      color_idx = 1;
      if (local_28 == 0x15) {
        strcpy(local_8c,s_Choose_attackers_phase_00520ee0);
      }
      else if (local_28 == 0x16) {
        strcpy(local_8c,s_Attacker_fast_effects_phase_00520ef8);
      }
      else if (local_28 == 0x17) {
        strcpy(local_8c,s_Assign_defenders_phase_00520f14);
      }
      else if (local_28 == 0x18) {
        strcpy(local_8c,s_Blocker_fast_effects_phase_00520f2c);
      }
      else if (local_28 == 0x19) {
        strcpy(local_8c,s_Resolve_1st_strike_damage_00520f48);
      }
      else if ((local_28 == 0x1a) || (local_28 == 0x1b)) {
        strcpy(local_8c,s_Resolve_normal_damage_00520f64);
      }
      else if (local_28 == 0x1e) {
        strcpy(local_8c,s_Main_phase__post_combat__00520f7c);
      }
      else {
        color_idx = 0;
      }
      if (color_idx == 0) {
        return 0;
      }
      strcpy(wParam,local_8c);
      return color_idx;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: Pic_Subsystem_0042784d
 * Entry Point: 0042784d
 * Size: 445 bytes
 */


void Pic_Subsystem_0042784d(POINT *player,RECT *card_slot,int32_t *arg_3)

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
  
  CopyRect(&local_28,card_slot);
  pt_05 = *player;
  pt_04 = *player;
  pt_03 = *player;
  pt_02 = *player;
  pt_01 = *player;
  pt_00 = *player;
  pt = *player;
  slot_idx = 0xffffffff;
  Pic_Subsystem_00427a0a(&target_idx,0x15,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt);
  if (BVar1 != 0) {
    slot_idx = 0x15;
  }
  Pic_Subsystem_00427a0a(&target_idx,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_00);
  if (BVar1 != 0) {
    slot_idx = 0x16;
  }
  Pic_Subsystem_00427a0a(&target_idx,0x17,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_01);
  if (BVar1 != 0) {
    slot_idx = 0x17;
  }
  Pic_Subsystem_00427a0a(&target_idx,0x18,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_02);
  if (BVar1 != 0) {
    slot_idx = 0x18;
  }
  Pic_Subsystem_00427a0a(&target_idx,0x19,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_03);
  if (BVar1 != 0) {
    slot_idx = 0x19;
  }
  Pic_Subsystem_00427a0a(&target_idx,0x1b,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_04);
  if (BVar1 != 0) {
    slot_idx = 0x1a;
  }
  Pic_Subsystem_00427a0a(&target_idx,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&target_idx,pt_05);
  if (BVar1 != 0) {
    slot_idx = 0x1e;
  }
  *arg_3 = slot_idx;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00427a0a
 * Entry Point: 00427a0a
 * Size: 449 bytes
 */


void Pic_Subsystem_00427a0a(LPRECT player,int y,int width,int height)

{
  int32_t slot_idx;
  
  if (y == -1) {
    SetRect(player,0,0,0,0);
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
      SetRect(player,0,0,0,0);
    }
    else {
      SetRect(player,0,slot_idx,width,(height * 0x28) / 0x2f8 + slot_idx);
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00427bcb
 * Entry Point: 00427bcb
 * Size: 619 bytes
 */


void Pic_Subsystem_00427bcb(HDC hdc,int arg2)

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
  
  Ai_Subsystem_004b765d(&slot_idx,&local_24);
  if ((slot_idx == -1) || (local_24 == -1)) {
    card_idx = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,card_idx);
    Ai_Subsystem_004b74b1(&match_count,(int32_t *)0x0);
    Ai_Subsystem_004b74fa(local_d0,match_count);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_d0[local_d4] != 0) {
        Pic_Subsystem_00427a0a(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
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
        Pic_Subsystem_00427a0a(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
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
 * Entry Point: 00427e36
 * Size: 563 bytes
 */


void Pic_Draw_00427e36(int *player,int32_t *card_slot,char *str_3)

{
  int local_7c;
  char local_74 [100];
  int32_t card_idx;
  int32_t match_count;
  int slot_idx;
  
  Ai_Subsystem_004b74b1(&slot_idx,&card_idx);
  local_7c = slot_idx;
  switch(card_idx) {
  case 1:
    match_count = 4;
    strcpy(local_74,s_Upkeep_phase_0052101c);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    match_count = 10;
    strcpy(local_74,s_Draw_phase_0052102c);
    break;
  default:
    match_count = 0xffffffff;
    strcpy(local_74,s_next_phase_00521128);
    break;
  case 10:
    match_count = 0x14;
    strcpy(local_74,s_Main_phase__pre_combat__00521038);
    break;
  case 0x14:
    match_count = 0x15;
    strcpy(local_74,s_Main_phase__combat__00521050);
    break;
  case 0x15:
    match_count = 0x16;
    strcpy(local_74,s_Attack_fast_effects_phase_00521064);
    break;
  case 0x16:
    match_count = 0x17;
    strcpy(local_74,s_Choose_defenders_phase_00521080);
    break;
  case 0x17:
    match_count = 0x18;
    strcpy(local_74,s_Block_fast_effects_phase_00521098);
    break;
  case 0x18:
    match_count = 0x19;
    strcpy(local_74,s_Resolve_1st_strike_005210b4);
    break;
  case 0x19:
  case 0x1a:
    match_count = 0x1b;
    strcpy(local_74,s_Resolve_attack_005210c8);
    break;
  case 0x1b:
    match_count = 0x1e;
    strcpy(local_74,s_Main_phase__post_combat__005210d8);
    break;
  case 0x1e:
    match_count = 0x1f;
    strcpy(local_74,s_Discard_phase_005210f4);
    break;
  case 0x1f:
    match_count = 0x20;
    strcpy(local_74,s_Cleanup_phase_00521104);
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
    match_count = 0;
    local_7c = 1 - slot_idx;
    strcpy(local_74,s_Start_of_next_turn_00521114);
  }
  if (player != (int *)0x0) {
    *player = local_7c;
  }
  if (card_slot != (int32_t *)0x0) {
    *card_slot = match_count;
  }
  if (str_3 != (char *)0x0) {
    strcpy(str_3,local_74);
  }
  return;
}



/*
 * Decompiled function: Pic_Util_004280cf
 * Entry Point: 004280cf
 * Size: 19 bytes
 */


void Pic_Util_004280cf(void)

{
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00428320
 * Entry Point: 00428320
 * Size: 1278 bytes
 */


int32_t Pic_Subsystem_00428320(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  char cVar2;
  int32_t uval_3;
  int val_4;
  int val_5;
  int card_idx;
  int match_count;
  
  if (arg_3 == 0x74) {
    uval_3 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player))
       && (val_4 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),
                                player), val_4 == 0)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if ((((g_PlayerManaPool == 0xcf) && (g_ScWillyScore == 10)) &&
        ((g_DefendingPlayer == g_CurrentCardColorTarget &&
         ((g_OverworldMapGrid == card_slot && (g_OverworldPlayerCoordX == player)))))) &&
       (g_CurrentCardColorTarget == player)) {
      if (arg_3 == 0x7d) {
        if (g_ActivePlayerPriority == player) {
          if (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 2) == 0) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 2;
            match_count = 0;
            flag_1 = false;
            while ((match_count < (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase] && (!flag_1))) {
              val_4 = *(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_CurrentTurnPhase * 0x5b20);
              if (((val_4 != -1) &&
                  (((((&g_CardSlot_Flags)[match_count * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0
                    && (((&g_MasterCardColorTable)[val_4 * 0x34] & 2) != 0)) &&
                   (((&g_CardSlot_Abilities2)[match_count * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x20)
                    == 0)))) &&
                 (((val_5 = g_CurrentTurnPhase * 0x5b20, cVar2 = Card_UntapCard(player, card_slot, 2),
                   (*(uint32_t *)(&g_CardSlot_Abilities2 + match_count * 0x120 + val_5) &
                   1 << (cVar2 - 1U & 0x1f)) == 0 && ((&g_MasterCardRarityTable)[val_4 * 0x34] == '\0')) &&
                  (((&DAT_006a5f69)[match_count * 0x120 + g_CurrentTurnPhase * 0x5b20] & 8) == 0)))) {
                flag_1 = true;
              }
              match_count = match_count + 1;
            }
            if ((flag_1) && (val_4 = Util_GetRandomNumber(8 - (&g_ActivePlayerSpellPriority)[player]), val_4 == 0)) {
              *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
            }
          }
          if (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) != 0) {
            g_ActivePalette = g_ActivePalette | 2;
          }
        }
        else {
          g_ActivePalette = g_ActivePalette | 1;
        }
      }
      if (arg_3 == 0x7e) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
        *(int32_t *)(&DAT_00680780 + player * 4) = 1;
        val_4 = Card_ApplyTriggerEffect(player, card_slot, DAT_006a4b64, -1, -1);
        if (val_4 != -1) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_4 * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_4 * 0x120 + player * 0x5b20) | 0x400020;
          cVar2 = Card_UntapCard(player, card_slot, 2);
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_4 * 0x120 + player * 0x5b20) =
               1 << (cVar2 - 1U & 0x1f) | 0x20;
          if (((&g_CardSlot_Abilities1)[card_slot * 0x120 + player * 0x5b20] & 2) != 0) {
            *(uint32_t *)(&g_CardSlot_Abilities1 + val_4 * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Abilities1 + val_4 * 0x120 + player * 0x5b20) | 2;
            for (card_idx = 0; card_idx < 6; card_idx = card_idx + 1) {
              (&DAT_006a602f)[card_idx + player * 0x5b20 + val_4 * 0x120] =
                   (&DAT_006a602f)[card_idx + player * 0x5b20 + card_slot * 0x120];
            }
          }
        }
        DAT_006fe408 = 1;
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_OverworldMapGrid == card_slot)) &&
       (g_OverworldPlayerCoordX == player)) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Pic_Subsystem_0042881e
 * Entry Point: 0042881e
 * Size: 1340 bytes
 */


int32_t Pic_Subsystem_0042881e(int player_id,int card_slot,int event_type)

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
      val_2 = Card_UntapCard(player,card_slot,1);
      val_2 = FUN_0041d8a6(val_2 + -1);
      if (val_2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = val_2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint32_t *)(&g_MasterCardSubtypeTable +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint32_t *)(&g_MasterCardSubtypeTable +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(int16_t *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(int16_t *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&g_MasterCardSubTypeTable2)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((int)(char)(&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120] !=
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120));
      val_2 = Card_UntapCard(player,card_slot,1);
      val_2 = FUN_0041d8a6(val_2 + -1);
      if (val_2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = val_2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint32_t *)(&g_MasterCardSubtypeTable +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint32_t *)(&g_MasterCardSubtypeTable +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(int16_t *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(int16_t *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&g_MasterCardSubTypeTable2)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((arg_3 == 0x3c) && (val_2 = Card_IsTapped(player,card_slot), val_2 != 0)) {
      if ((g_PlayerHandCardCount & 0x20000) == 0) {
        g_PlayerHandCardCount = g_PlayerHandCardCount | 0x10000;
      }
      else {
        val_2 = Card_IsTapped(g_OverworldPlayerCoordX,g_OverworldMapGrid);
        if (((val_2 != 0) &&
            (val_3 = g_OverworldMapGrid * 0x120, val_4 = g_OverworldPlayerCoordX * 0x5b20,
            val_2 = Card_UntapCard(player,card_slot,1),
            *(int *)(&g_CardSlot_CardId + val_4 + val_3) == val_2 + -1)) &&
           ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0 ||
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)))) {
          g_ActivePalette = *(int32_t *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120)
          ;
          *(uint32_t *)(&g_CardSlot_Abilities1 +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
               *(uint32_t *)(&g_CardSlot_Abilities1 +
                        g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x40;
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00428d5a
 * Entry Point: 00428d5a
 * Size: 1245 bytes
 */


int32_t Pic_Subsystem_00428d5a(int player_id,int card_slot,int event_type)

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
      val_2 = Card_UntapCard(player,card_slot,3);
      val_2 = FUN_0041d8a6(val_2 + -1);
      if (val_2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = val_2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6032)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint32_t *)(&g_MasterCardSubtypeTable +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint32_t *)(&g_MasterCardSubtypeTable +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(int16_t *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(int16_t *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&g_MasterCardSubTypeTable2)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((int)(char)(&DAT_006a6032)[player * 0x5b20 + card_slot * 0x120] !=
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120));
      val_2 = Card_UntapCard(player,card_slot,3);
      val_2 = FUN_0041d8a6(val_2 + -1);
      if (val_2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = val_2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6032)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint32_t *)(&g_MasterCardSubtypeTable +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint32_t *)(&g_MasterCardSubtypeTable +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(int16_t *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(int16_t *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&g_MasterCardSubTypeTable2)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((arg_3 == 0x3c) && (val_2 = Card_IsTapped(player,card_slot), val_2 != 0)) {
      if ((g_PlayerHandCardCount & 0x20000) == 0) {
        g_PlayerHandCardCount = g_PlayerHandCardCount | 0x10000;
      }
      else {
        val_2 = Card_IsTapped(g_OverworldPlayerCoordX,g_OverworldMapGrid);
        if ((val_2 != 0) &&
           (val_3 = g_OverworldMapGrid * 0x120, val_4 = g_OverworldPlayerCoordX * 0x5b20,
           val_2 = Card_UntapCard(player,card_slot,3),
           *(int *)(&g_CardSlot_CardId + val_4 + val_3) == val_2 + -1)) {
          g_ActivePalette = *(int32_t *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120)
          ;
          *(uint32_t *)(&g_CardSlot_Abilities1 +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
               *(uint32_t *)(&g_CardSlot_Abilities1 +
                        g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x40;
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_SylvanLibrary
 * Entry Point: 00429237
 * Size: 1462 bytes
 */


int32_t CardScript_SylvanLibrary(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int local_10c;
  uint32_t local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int32_t local_f4 [30];
  int aiStack_7c [30];
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (flags == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if ((((flags == 0x73) && (g_DefendingPlayer == spell_id)) &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) &&
       (g_ScWillyScore == 10)) {
      val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[spell_id * 0x5b20 + target_id * 0x120]);
      if ((*(int *)(&DAT_006330d0 + val_2 * 4) == 0) ||
         (val_2 = FUN_0040dcca(spell_id,target_id,7,0), val_2 != 0)) {
        if (spell_id == g_ActivePlayerPriority) {
          g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        }
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if ((flags == 0x6d) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_006330d0 + val_2 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 1
          ;
        }
      }
      if ((flags == 0x72) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          Magic_ExecuteDrawPhase(g_DefendingPlayer);
        }
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          local_10c = 0;
          for (local_100 = 0; local_100 < (int)(&g_PlayerActiveCardCount)[spell_id];
              local_100 = local_100 + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_100 * 0x120 + spell_id * 0x5b20) != -1) &&
                (((&g_CardSlot_Flags)[local_100 * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
               (((&g_CardSlot_Flags)[local_100 * 0x120 + spell_id * 0x5b20] & 2) == 0)) {
              local_f4[local_10c] =
                   *(int32_t *)(&g_CardSlot_CardId + local_100 * 0x120 + spell_id * 0x5b20);
              aiStack_7c[local_10c] = local_100;
              local_10c = local_10c + 1;
            }
          }
          local_fc = 0;
          if (0x12 < (int)(&g_PlayerCreatureCount)[spell_id]) {
            local_fc = (&g_PlayerCreatureCount)[spell_id] + 0x1e;
          }
          if ((int)(&g_ActivePlayerSpellPriority)[spell_id] < 7) {
            local_fc = local_fc + (7 - (&g_ActivePlayerSpellPriority)[spell_id]) * 5 + 10;
          }
          if ((0 < local_f8) && (local_104 == 0)) {
            local_fc = local_fc / 2;
          }
          if ((int)(&g_PlayerCreatureCount)[spell_id] < 4) {
            local_fc = 0;
          }
          val_2 = Util_GetRandomNumber(100);
          local_104 = (uint32_t)(local_fc <= val_2);
          val_2 = Ai_Subsystem_004cc56d
                            (spell_id,g_DialogPromptHwnd,g_DuelArenaHwnd,-1,-1,
                             s_Lose_4_life__Put_back_on_library_00521134,local_104);
          if (val_2 == 0) {
            (&g_PlayerCreatureCount)[spell_id] = (&g_PlayerCreatureCount)[spell_id] + -4;
          }
          else if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) &&
                  (g_AiTurnDecisionFlag == 0)) {
            Pic_Subsystem_00424500(s_prompts_txt_00521168,s_SYLVAN_LIBRARY_00521158);
            val_2 = UI_DeckSelectionMenu(spell_id,(int)local_f4,local_10c,&g_OverworldGoldAmount,1);
            Pic_Subsystem_004524db(spell_id,local_f4[val_2]);
            *(int32_t *)(&g_CardSlot_CardId + spell_id * 0x5b20 + aiStack_7c[val_2] * 0x120) =
                 0xffffffff;
            (&g_ActivePlayerSpellPriority)[spell_id] = (&g_ActivePlayerSpellPriority)[spell_id] + -1;
          }
          else if (0 < local_10c) {
            val_2 = Util_GetRandomNumber(local_10c);
            Pic_Subsystem_004524db(spell_id,local_f4[val_2]);
            *(int32_t *)(&g_CardSlot_CardId + spell_id * 0x5b20 + aiStack_7c[val_2] * 0x120) =
                 0xffffffff;
            (&g_ActivePlayerSpellPriority)[spell_id] = (&g_ActivePlayerSpellPriority)[spell_id] + -1;
          }
        }
      }
      if (((flags == 0x22) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_LandTax
 * Entry Point: 004297ed
 * Size: 1675 bytes
 */


int32_t CardScript_LandTax(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int val_4;
  int color_idx;
  int target_idx;
  int player_idx [4];
  
  if (flags == 0x74) {
    uval_2 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       (val_3 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       val_3 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((*(int *)(&g_PlayerManaPoolDelta + (1 - spell_id) * 0x20) -
            *(int *)(&g_PlayerManaPoolDelta + spell_id * 0x20)) * 3 + 6) * 4;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == spell_id)) && (spell_id == g_CurrentTurnTargetPlayer))
         && ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0
             && (*(int *)(&g_PlayerManaPoolDelta + spell_id * 0x20) <
                 *(int *)(&g_PlayerManaPoolDelta + (1 - spell_id) * 0x20))))) {
        val_3 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_006330d0 + val_3 * 4) == 0) ||
           (val_3 = FUN_0040dcca(spell_id,target_id,7,0), val_3 != 0)) {
          if ((g_CurrentTurnPhase != spell_id) && (*(int *)(&DAT_0069e740 + spell_id * 2000) != -1))
          {
            g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
          }
          uval_2 = 1;
        }
        else {
          uval_2 = 0;
        }
      }
      else {
        uval_2 = 0;
      }
    }
    else {
      if (((flags == 0x6d) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        val_3 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + val_3 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
        }
      }
      if (flags == 0x72) {
        if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
          Pic_Subsystem_00424500(s_prompts_txt_005211ac,s_LANDTAX_005211a4);
          val_3 = Ai_Subsystem_004b76a6(&g_PlayerDeckCardList + spell_id * 2000,500,(int)player_idx,3);
          for (target_idx = 0; target_idx < val_3; target_idx = target_idx + 1) {
            Deck_AddCardToDeck
                      (spell_id,*(int *)(&g_PlayerDeckCardList + player_idx[target_idx] * 4 + spell_id * 2000));
          }
          if (val_3 == 1) {
            Pic_Subsystem_004523fd(spell_id,player_idx[0]);
          }
          if (val_3 == 2) {
            val_4 = player_idx[1];
            if (player_idx[1] <= player_idx[0]) {
              val_4 = player_idx[0];
            }
            Pic_Subsystem_004523fd(spell_id,val_4);
            val_4 = player_idx[1];
            if (player_idx[0] <= player_idx[1]) {
              val_4 = player_idx[0];
            }
            Pic_Subsystem_004523fd(spell_id,val_4);
          }
          if (val_3 == 3) {
            Pic_Subsystem_004523fd(spell_id,player_idx[0]);
            if (player_idx[0] < player_idx[1]) {
              player_idx[1] = player_idx[1] + -1;
            }
            if (player_idx[0] < player_idx[2]) {
              player_idx[2] = player_idx[2] + -1;
            }
            val_3 = player_idx[1];
            if (player_idx[1] <= player_idx[2]) {
              val_3 = player_idx[2];
            }
            Pic_Subsystem_004523fd(spell_id,val_3);
            val_3 = player_idx[1];
            if (player_idx[2] <= player_idx[1]) {
              val_3 = player_idx[2];
            }
            Pic_Subsystem_004523fd(spell_id,val_3);
          }
          Ai_EvaluateTacticalPosition(0,0xff);
        }
        else {
          color_idx = 0;
          target_idx = 0;
          flag_1 = false;
          while ((target_idx < (int)(&g_ActivePlayerSpellPriority)[spell_id] && (!flag_1))) {
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + target_idx * 0x120 + spell_id * 0x5b20) * 0x34] & 1)
                != 0) {
              flag_1 = true;
            }
            target_idx = target_idx + 1;
          }
          if (!flag_1) {
            g_SpellStackDepth = g_SpellStackDepth + 0x30;
          }
          val_3 = Math_Clamp(8 - (&g_ActivePlayerSpellPriority)[spell_id],1,3);
          for (target_idx = 0; target_idx < val_3; target_idx = target_idx + 1) {
            player_idx[3] = FUN_004fdad2(spell_id,spell_id,1);
            if (4 < *(int *)(&g_PlayerDeckCardList + player_idx[3] * 4 + spell_id * 2000)) {
              player_idx[3] = -1;
              target_idx = 0;
              while (((target_idx < 500 && (player_idx[3] == -1)) &&
                     (*(int *)(&g_PlayerDeckCardList + target_idx * 4 + spell_id * 2000) != -1))) {
                if (*(int *)(&g_PlayerDeckCardList + target_idx * 4 + spell_id * 2000) < 5) {
                  player_idx[3] = target_idx;
                }
                target_idx = target_idx + 1;
              }
            }
            if ((player_idx[3] != -1) &&
               (*(int *)(&g_PlayerDeckCardList + player_idx[3] * 4 + spell_id * 2000) != -1)) {
              player_idx[color_idx] = *(int *)(&g_PlayerDeckCardList + player_idx[3] * 4 + spell_id * 2000);
              color_idx = color_idx + 1;
              Pic_Subsystem_004523fd(spell_id,player_idx[3]);
            }
          }
          if (spell_id == 1) {
            UI_DeckSelectionMenu(0,(int)player_idx,color_idx,s_Opponent_chose_these_basic_lands_00521180,0
                             );
          }
          for (target_idx = 0; target_idx < color_idx; target_idx = target_idx + 1) {
            Deck_AddCardToDeck(spell_id,player_idx[target_idx]);
          }
        }
        Pic_Subsystem_00452276(spell_id);
      }
      if (((flags == 0x22) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_Kismet
 * Entry Point: 00429e7d
 * Size: 601 bytes
 */


int CardScript_Kismet(int spell_id,int target_id,int flags)

{
  int val_1;
  int match_count;
  int32_t slot_idx;
  
  if (flags == 0x74) {
    val_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      val_1 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                            spell_id * 0x5b20 + target_id * 0x120),-1);
      if (val_1 == 0) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
    }
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_005211c0,s_KISMET_005211b8);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&match_count);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = slot_idx;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    val_1 = target_id * 0x120;
    if (((((&g_CardSlot_Flags)[spell_id * 0x5b20 + val_1] & 0x20) == 0) && (flags == 0x6c)) &&
       ((val_1 = target_id * 0x120,
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + val_1) ==
        g_OverworldPlayerCoordX &&
        (val_1 = *(int *)(&g_CardSlot_CardId +
                         g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0xd,
        ((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x43) !=
        0)))) {
      val_1 = g_OverworldMapGrid * 0x120;
      *(uint32_t *)(&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + val_1) =
           *(uint32_t *)(&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + val_1) | 0x10;
    }
  }
  return val_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042a0d6
 * Entry Point: 0042a0d6
 * Size: 243 bytes
 */


void Pic_Subsystem_0042a0d6(int player_id,int card_slot,int event_type)

{
  int val_1;
  int val_2;
  
  if (((arg_3 == 0x7f) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
    val_1 = Card_SetTapState(player, card_slot, 5);
    *(int *)(&DAT_006330d0 + val_1 * 4) = *(int *)(&DAT_006330d0 + val_1 * 4) + 3;
  }
  if ((((arg_3 != 0x74) && ((arg_3 == 0x6c || (arg_3 == 199)))) && (g_OverworldMapGrid == card_slot)) &&
     (g_OverworldPlayerCoordX == player)) {
    val_1 = Card_SetTapState(player, card_slot, 5);
    val_1 = *(int *)(&g_AiCombatScore_Attacker + val_1 * 4 + (1 - player) * 0x20);
    val_2 = Card_SetTapState(player, card_slot, 5);
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((val_1 + *(int *)(&g_AiCombatScore_Attacker + val_2 * 4 + player * 0x20) * -2) * 3 + 3) * 4;
  }
  return;
}



/*
 * Decompiled function: Pic_Load_0042a1c9
 * Entry Point: 0042a1c9
 * Size: 2641 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t Pic_Load_0042a1c9(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint32_t uval_2;
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx [4];
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      uval_2 = (DAT_00695e04 | _DAT_00695e00) & 2;
    }
    else {
      if (g_IsAiThinking == 1) {
        g_AiDecisionScore = Util_GetRandomNumber(2);
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           g_AiDecisionScore;
      uval_2 = *(uint32_t *)(&DAT_00695e00 + g_AiDecisionScore * 4) & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        player_idx[1] = 0;
        player_idx[0] = 0;
        for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
          loop_idx = 0;
          while( true ) {
            if ((499 < loop_idx) || (*(int *)(&g_PlayerGraveyardList + loop_idx * 4 + spell_id * 2000) == -1)
               ) goto LAB_0042a2fb;
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_PlayerGraveyardList + loop_idx * 4 + target_idx * 2000) * 0x34] & 2) != 0) break;
            loop_idx = loop_idx + 1;
          }
          player_idx[target_idx] = player_idx[target_idx] + 1;
LAB_0042a2fb:
        }
        if ((player_idx[0] == 0) || (player_idx[1] == 0)) {
          if (player_idx[0] == 0) {
            local_24 = 1;
          }
          else {
            local_24 = 0;
          }
        }
        else {
          local_24 = Ai_Subsystem_004cc56d
                               (spell_id,spell_id,target_id,-1,-1,
                                s_From_my_graveyard__From_opponent_005211cc,0);
          if (local_24 == 2) {
            g_ActivePlayer = 1;
          }
        }
        if (g_ActivePlayer != 1) {
          if (local_24 == 0) {
            strcpy(&g_OverworldWorldState,&DAT_00521208);
          }
          else {
            Ai_Subsystem_004b6f49(&g_OverworldWorldState);
            strcat(&g_OverworldWorldState,&DAT_00521204);
          }
          strcat(&g_OverworldWorldState,s_graveyard__Pick_a_creature_00521210);
          color_idx = 0;
          do {
            player_idx[3] = UI_DeckSelectionMenu(spell_id,(int)(&g_PlayerGraveyardList + local_24 * 2000),500,
                                            &g_OverworldWorldState,0);
            if (player_idx[3] == -1) {
              g_ActivePlayer = 1;
            }
            else if (((&g_MasterCardColorTable)
                      [*(int *)(&g_PlayerGraveyardList + player_idx[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0
                    ) {
              if (g_IsAiThinking != 1) {
                Ai_Util_004cc42d(s_Illegal_Target_00521234);
                Sleep(2000);
                Ai_Util_004cc42d(&DAT_00521244);
              }
            }
            else {
              color_idx = color_idx + 1;
            }
          } while ((g_ActivePlayer != 1) && (color_idx == 0));
        }
      }
      else {
        local_24 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        player_idx[3] = FUN_004fd9c0(local_24,2);
      }
      if ((g_ActivePlayer == 1) ||
         (((player_idx[3] == -1 || (*(int *)(&g_PlayerGraveyardList + player_idx[3] * 4 + local_24 * 2000) == -1)
           ) || (((&g_MasterCardColorTable)
                  [*(int *)(&g_PlayerGraveyardList + player_idx[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0))))
      {
        g_ActivePlayer = 1;
      }
      else {
        player_idx[2] = Deck_AddCardToDeck
                                (spell_id,*(int *)(&g_PlayerGraveyardList + player_idx[3] * 4 + local_24 * 2000
                                                  ));
        if (player_idx[2] != -1) {
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) = player_idx[2]
          ;
          (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = (uint8_t)spell_id;
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffefff;
          if (local_24 != 0) {
            *(uint32_t *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_OriginalCardId +
                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) | 0x1000;
          }
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 0x20;
          *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20) = local_24;
          *(int *)(&DAT_006a5f94 + target_id * 0x120 + spell_id * 0x5b20) = player_idx[3];
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
    }
    if (flags == 0x71) {
      player_idx[3] = *(int *)(&DAT_006a5f94 + target_id * 0x120 + spell_id * 0x5b20);
      if (*(int *)(&g_PlayerGraveyardList +
                  player_idx[3] * 4 +
                  *(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20) * 2000) == -1) {
        Pic_Subsystem_0044867e(spell_id,target_id,2);
        *(int32_t *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0xffffffff;
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_00449223
                  (*(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20),player_idx[3]);
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        Pic_Subsystem_0042ac1f
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
        *(int16_t *)
         (&g_CardSlot_PowerCounters +
         *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) = 0xffff;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((((g_PlayerManaPool == 0xd4) && (g_OverworldMapGrid == target_id)) &&
         ((g_OverworldPlayerCoordX == spell_id &&
          (((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1 &&
           (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) != -1)))))) && (DAT_00695f08 == spell_id)) &&
       ((DAT_006b2e14 == target_id && (spell_id == g_CurrentCardColorTarget)))) {
      if (flags == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (flags == 0x7e) {
        if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0) {
          *(uint32_t *)(&g_CardSlot_Abilities1 +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 8;
        }
        cVar1 = (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
        Pic_Subsystem_0044867e
                  ((int)cVar1,
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),1);
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_0042ac1f
 * Entry Point: 0042ac1f
 * Size: 510 bytes
 */


int32_t Pic_Subsystem_0042ac1f(int arg1,int arg2)

{
  if ((arg1 != -1) && (arg2 != -1)) {
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg1 * 4) = *(int *)(&DAT_006b3010 + arg1 * 4) + 1;
    }
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg1] = (&DAT_006b3018)[arg1] + 1;
    }
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg1 * 4) = *(int *)(&DAT_006b3020 + arg1 * 4) + 1;
    }
    (&g_PlayerPoisonCounters)[arg1] =
         (&g_PlayerPoisonCounters)[arg1] |
         (uint32_t)(uint8_t)(&g_MasterCardColorTable)
                     [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
    *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) | 0x30022;
    Rules_ApplyContinuousDamage(arg1,arg2,0x6c);
    *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) |
         CONCAT31((uint3)((arg1 == 0) - 1 >> 8) & 0x4000,0x80);
    Magic_TriggerCardEvent(arg1,arg2,0x71,1 - arg1,0xffffffff);
    *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) & 0xffffffdf;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    FUN_00476205(g_DefendingPlayer,0xdb,s_Card_into_play_00521248,0);
  }
  return 0;
}



/*
 * Decompiled function: CardScript_AnimateArtifact
 * Entry Point: 0042ae1d
 * Size: 2008 bytes
 */


int32_t CardScript_AnimateArtifact(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
  int *arg_20;
  int card_idx;
  int32_t match_count;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052126c,s_ANIMATE_ARTIFACT_00521258);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,2,0x200,0x40,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9
                         ,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7
                         ,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) * 0x34] & 0x42) == 0x40) {
          slot_idx = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                         *(int *)(&g_CardSlot_OriginalCardId +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                         (char)(&g_CardSlot_Toughness)
                                               [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20));
          if (slot_idx != -1) {
            (&g_MasterCardColorTable)[slot_idx * 0x34] = 0x42;
            *(short *)(&DAT_0051aec4 + slot_idx * 0x34) =
                 (short)(char)(&g_MasterCardManaCostTable)
                              [*(int *)(&g_CardSlot_CardId +
                                       *(int *)(&g_CardSlot_OriginalCardId +
                                               target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                       (char)(&g_CardSlot_Toughness)
                                             [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) *
                               0x34];
            *(int16_t *)(&DAT_0051aec2 + slot_idx * 0x34) =
                 *(int16_t *)(&DAT_0051aec4 + slot_idx * 0x34);
            *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
            *(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) = slot_idx;
            *(uint32_t *)(&g_CardSlot_Abilities2 +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Abilities2 +
                          *(int *)(&g_CardSlot_OriginalCardId +
                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) | 0x1000000;
          }
        }
        else {
          *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x77) && (g_OverworldMapGrid == target_id)) &&
       ((g_OverworldPlayerCoordX == spell_id &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)))) {
      (&g_MasterCardColorTable)
      [*(int *)(&g_CardSlot_CardId +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) *
       0x34] = (&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34] &
               0xfd;
    }
    if (((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid &&
        ((((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)) &&
         (val_5 = Card_IsTapped(spell_id,target_id), val_5 != 0)))))) {
      g_ActivePalette =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint32_t *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) | 0x40;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042b5f5
 * Entry Point: 0042b5f5
 * Size: 1209 bytes
 */


int32_t Pic_Subsystem_0042b5f5(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int val_4;
  int card_idx;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      Glue_Subsystem_004e65e1(Pic_Subsystem_0042baae,-1);
    }
    if ((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) {
      val_3 = Card_IsTapped(player,card_slot);
      if ((val_3 != 0) &&
         ((g_OverworldMapGrid != -1 &&
          (((&g_MasterCardColorTable)[g_ActivePalette * 0x34] & 0x42) == 0x40)))) {
        card_idx = 0;
        flag_1 = false;
        while( true ) {
          val_3 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
          if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
              (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
            val_3 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
          }
          if ((val_3 <= card_idx) || (flag_1)) break;
          if (((*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + g_CurrentTurnPhase * 0x5b20) ==
                DAT_00695edc) &&
              (((&g_CardSlot_Flags)[card_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
             (((char)(&g_CardSlot_Toughness)[card_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] ==
               g_OverworldPlayerCoordX &&
              (*(int *)(&g_CardSlot_OriginalCardId + card_idx * 0x120 + g_CurrentTurnPhase * 0x5b20)
               == g_OverworldMapGrid)))) {
            flag_1 = true;
          }
          if (((*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) ==
                DAT_00695edc) &&
              (((&g_CardSlot_Flags)[card_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0))
             && (((char)(&g_CardSlot_Toughness)[card_idx * 0x120 + g_ActivePlayerPriority * 0x5b20]
                  == g_OverworldPlayerCoordX &&
                 (*(int *)(&g_CardSlot_OriginalCardId +
                          card_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) == g_OverworldMapGrid)
                 ))) {
            flag_1 = true;
          }
          card_idx = card_idx + 1;
        }
        if (!flag_1) {
          val_3 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                                       ));
          if (val_3 != -1) {
            val_4 = Card_ApplyTriggerEffect(player,card_slot,DAT_00695edc,g_OverworldPlayerCoordX,g_OverworldMapGrid
                                );
            if (val_4 != -1) {
              *(int *)(&g_CardSlot_Controller + val_4 * 0x120 + player * 0x5b20) = val_3;
              *(uint32_t *)(&g_CardSlot_Abilities1 + val_4 * 0x120 + player * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_Abilities1 + val_4 * 0x120 + player * 0x5b20) | 0x10020;
              UI_PaintBigCardInfo(&slot_idx,0,player,2,2,0x200,0,0,0,0,0,0,
                           *(int32_t *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120),
                           0xffffffff,0xffffffff,0xffffffff,0,0,0);
              *(int *)(&g_CardSlot_TargetSlot + val_4 * 0x120 + player * 0x5b20) = slot_idx;
            }
            (&g_MasterCardColorTable)[val_3 * 0x34] = 0x42;
            *(short *)(&DAT_0051aec4 + val_3 * 0x34) =
                 (short)(char)(&g_MasterCardSubTypeTable2)
                              [*(int *)(&g_CardSlot_CardId +
                                       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                                       ) * 0x34] +
                 (short)(char)(&g_MasterCardManaCostTable)
                              [*(int *)(&g_CardSlot_CardId +
                                       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                                       ) * 0x34];
            *(int16_t *)(&DAT_0051aec2 + val_3 * 0x34) =
                 *(int16_t *)(&DAT_0051aec4 + val_3 * 0x34);
            *(code **)(&g_CardScriptCallbackTable + val_3 * 0x34) = Glue_Util_004d0a30;
            *(int32_t *)(&g_MasterCardSubtypeTable + val_3 * 0x34) = 0x8000;
            (&g_MasterCardColorTable)[val_3 * 0x34] = 1;
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      Glue_Subsystem_004e65e1(Pic_Subsystem_0042baee,-1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_0042baae
 * Entry Point: 0042baae
 * Size: 64 bytes
 */


int32_t Pic_Subsystem_0042baae(int player_id,int card_slot,int event_type)

{
  if (DAT_00695edc == arg_3) {
    *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) + 1;
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042baee
 * Entry Point: 0042baee
 * Size: 64 bytes
 */


int32_t Pic_Subsystem_0042baee(int player_id,int card_slot,int event_type)

{
  if (DAT_00695edc == arg_3) {
    *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) + -1;
  }
  return 0;
}



/*
 * Decompiled function: CardScript_AnimateWall
 * Entry Point: 0042bb2e
 * Size: 951 bytes
 */


int32_t CardScript_AnimateWall(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
  int *arg_20;
  int match_count;
  int32_t slot_idx;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 1;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521288,s_ANIMATE_WALL_00521278);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = slot_idx;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
        *(uint32_t *)(&g_CardSlot_Abilities1 +
                 *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                 0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                         0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 +
                      *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                      0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                              0x5b20) | 0x800;
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x77) && (target_id == g_OverworldMapGrid)) &&
       ((spell_id == g_OverworldPlayerCoordX &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) != -1)))) {
      *(uint32_t *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                    0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) & 0xfffff7ff;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_ControlMagic
 * Entry Point: 0042bee5
 * Size: 96 bytes
 */


void CardScript_ControlMagic(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005212a4,s_CONTROL_MAGIC_00521294);
  }
  Pic_Subsystem_0042bfa5(spell_id,target_id,flags,2);
  return;
}



/*
 * Decompiled function: CardScript_StealArtifact
 * Entry Point: 0042bf45
 * Size: 96 bytes
 */


void CardScript_StealArtifact(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005212c0,s_STEAL_ARTIFACT_005212b0);
  }
  Pic_Subsystem_0042bfa5(spell_id,target_id,flags,0x40);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0042bfa5
 * Entry Point: 0042bfa5
 * Size: 2442 bytes
 */


int32_t Pic_Subsystem_0042bfa5(int x,int y,int width,uint32_t height)

{
  int32_t uval_1;
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
  int *arg_20;
  int player_idx;
  int32_t card_idx;
  int match_count;
  int slot_idx;
  
  if (width == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(x,y);
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,x,2,2,0x200,height,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((width == 0x6c) && (g_OverworldMapGrid == y)) && (g_OverworldPlayerCoordX == x)) {
      arg_20 = &player_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(x,y);
      val_5 = Action_ValidateTarget_00405802
                        (x,2,1 - x,0x200,height,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9,
                         uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) = player_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) = card_idx;
        (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 1;
      }
    }
    if (width == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(x,y);
      val_5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x200,height,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9,uVar10,
                         uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(x,y,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] =
             (&g_CardSlot_CombatTarget)[y * 0x120 + x * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20);
        for (match_count = 0; match_count < 2; match_count = match_count + 1) {
          for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[match_count];
              slot_idx = slot_idx + 1) {
            if ((((*(int *)(&g_MasterCardTypeTable +
                           *(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) * 0x34)
                   == 0x2c) ||
                 (*(int *)(&g_MasterCardTypeTable +
                          *(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) * 0x34)
                  == 0xea)) &&
                ((((&g_CardSlot_Flags)[slot_idx * 0x120 + match_count * 0x5b20] & 2) != 0 &&
                 (((&g_CardSlot_Toughness)[slot_idx * 0x120 + match_count * 0x5b20] ==
                   (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] &&
                  (*(int *)(&g_CardSlot_OriginalCardId + slot_idx * 0x120 + match_count * 0x5b20) ==
                   *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20))))))) &&
               (((&DAT_006a5f6b)[slot_idx * 0x120 + match_count * 0x5b20] & 1) != 0)) {
              *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + match_count * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + match_count * 0x5b20) &
                   0xfeffffff;
              (&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] = (uint8_t)match_count;
              *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) = slot_idx;
            }
          }
        }
        *(uint32_t *)(&g_CardSlot_Abilities1 + y * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + y * 0x120 + x * 0x5b20) | 0x1000000;
        if (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) != x) {
          slot_idx = Pic_Subsystem_0042ca53
                              ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] = (uint8_t)x;
          *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) = slot_idx;
        }
      }
      (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((((g_PlayerManaPool == 0xd4) && (g_OverworldMapGrid == y)) &&
         (g_OverworldPlayerCoordX == x)) &&
        (((&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] != -1 &&
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1)))) &&
       ((DAT_00695f08 == x && ((DAT_006b2e14 == y && (x == g_CurrentCardColorTarget)))))) {
      if (width == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (width == 0x7e) {
        if (((&DAT_006a5f6b)[y * 0x120 + x * 0x5b20] & 1) == 0) {
          Glue_Subsystem_004e65e1(Pic_Subsystem_0042c92f,-1);
        }
        else if ((&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] == -1) {
          if ((*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                       (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1) &&
             (((((&g_CardSlot_Subtypes)
                 [*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) != 0 &&
               ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_CurrentTurnPhase)) ||
              ((((&g_CardSlot_Subtypes)
                 [*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) == 0 &&
               ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_ActivePlayerPriority)))))
             ) {
            Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          }
        }
        else {
          *(uint32_t *)(&g_CardSlot_Abilities1 +
                   *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 +
                        *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) * 0x120 +
                        (char)(&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] * 0x5b20) |
               0x1000000;
          if ((&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] !=
              (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20]) {
            Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          }
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042c92f
 * Entry Point: 0042c92f
 * Size: 292 bytes
 */


int32_t Pic_Subsystem_0042c92f(int player_id,int card_slot,int event_type)

{
  if ((((*(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) == 0x2c) ||
       (*(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) == 0xea)) &&
      ((char)(&g_CardSlot_DamageReceived)[card_slot * 0x120 + player * 0x5b20] == g_OverworldPlayerCoordX
      )) && (*(int *)(&g_CardSlot_TypeFlags + card_slot * 0x120 + player * 0x5b20) == g_OverworldMapGrid)
     ) {
    (&g_CardSlot_DamageReceived)[card_slot * 0x120 + player * 0x5b20] =
         (&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
    ;
    *(int32_t *)(&g_CardSlot_TypeFlags + card_slot * 0x120 + player * 0x5b20) =
         *(int32_t *)
          (&g_CardSlot_TypeFlags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042ca53
 * Entry Point: 0042ca53
 * Size: 1040 bytes
 */


int Pic_Subsystem_0042ca53(int arg1,int arg2)

{
  int val_1;
  int arg1_00;
  int val_2;
  int color_idx;
  int target_idx;
  int player_idx;
  uint8_t slot_idx;
  
  arg1_00 = 1 - arg1;
  val_1 = *(int *)(&g_CardSlot_DisplayIndex + arg1 * 0x5b20 + arg2 * 0x120);
  val_2 = Deck_AddCardToDeck
                    (arg1_00,*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120));
  if (val_2 != -1) {
    memcpy(&g_ActiveCardsInPlay + arg1_00 * 0x5b20 + val_2 * 0x120,
           &g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20,0x120);
    if (*(int *)(&g_MasterCardTypeTable +
                *(int *)(&g_CardSlot_CardId + val_2 * 0x120 + arg1_00 * 0x5b20) * 0x34) != 0xab) {
      *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + arg1_00 * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + arg1_00 * 0x5b20) | 0x30000;
    }
    *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + arg1_00 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + arg1_00 * 0x5b20) & 0xfffffff3;
    *(int *)(&g_CardDisplayOrder_Player + val_1 * 4) = arg1_00;
    *(int *)(&g_CardDisplayOrder_Slot + val_1 * 4) = val_2;
    for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
      for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[player_idx];
          target_idx = target_idx + 1) {
        slot_idx = (uint8_t)arg1_00;
        if (((char)(&g_CardSlot_Toughness)[target_idx * 0x120 + player_idx * 0x5b20] == arg1) &&
           (*(int *)(&g_CardSlot_OriginalCardId + target_idx * 0x120 + player_idx * 0x5b20) == arg2)) {
          (&g_CardSlot_Toughness)[target_idx * 0x120 + player_idx * 0x5b20] = slot_idx;
          *(int *)(&g_CardSlot_OriginalCardId + target_idx * 0x120 + player_idx * 0x5b20) = val_2;
        }
        if (((char)(&g_CardSlot_DamageReceived)[target_idx * 0x120 + player_idx * 0x5b20] == arg1) &&
           (*(int *)(&g_CardSlot_TypeFlags + target_idx * 0x120 + player_idx * 0x5b20) == arg2)) {
          (&g_CardSlot_DamageReceived)[target_idx * 0x120 + player_idx * 0x5b20] = slot_idx;
          *(int *)(&g_CardSlot_TypeFlags + target_idx * 0x120 + player_idx * 0x5b20) = val_2;
        }
        if ((&g_CardSlot_TurnPlayed)[target_idx * 0x120 + player_idx * 0x5b20] != '\0') {
          for (color_idx = 0;
              color_idx < (char)(&g_CardSlot_TurnPlayed)[target_idx * 0x120 + player_idx * 0x5b20];
              color_idx = color_idx + 1) {
            if ((*(int *)(&g_CardSlot_CombatTarget +
                         target_idx * 0x120 + player_idx * 0x5b20 + color_idx * 8) == arg1) &&
               (*(int *)(&g_CardSlot_AttachedAura +
                        target_idx * 0x120 + player_idx * 0x5b20 + color_idx * 8) == arg2)) {
              *(int *)(&g_CardSlot_CombatTarget +
                      target_idx * 0x120 + player_idx * 0x5b20 + color_idx * 8) = arg1_00;
              *(int *)(&g_CardSlot_AttachedAura +
                      target_idx * 0x120 + player_idx * 0x5b20 + color_idx * 8) = val_2;
            }
          }
        }
      }
    }
  }
  *(uint32_t *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint32_t *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) | 8;
  Pic_Subsystem_0044867e(arg1,arg2,4);
  return val_2;
}



/*
 * Decompiled function: Pic_Subsystem_0042ce63
 * Entry Point: 0042ce63
 * Size: 2028 bytes
 */


int32_t Pic_Subsystem_0042ce63(int x,int y,int width,int height)

{
  int val_1;
  int val_2;
  int val_3;
  int32_t uval_4;
  int val_5;
  int loop_idx;
  int color_idx;
  int card_idx;
  
  val_1 = *(int *)(&g_CardSlot_DisplayIndex + y * 0x120 + x * 0x5b20);
  val_2 = *(int *)(&g_CardSlot_DisplayIndex + height * 0x120 + width * 0x5b20);
  val_3 = Deck_AddCardToDeck(x,*(int *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20));
  if (val_3 == -1) {
    uval_4 = 0;
  }
  else {
    val_5 = Deck_AddCardToDeck(width,*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20));
    if (val_5 == -1) {
      *(int32_t *)(&g_CardSlot_CardId + val_3 * 0x120 + x * 0x5b20) = 0xffffffff;
      uval_4 = 0;
    }
    else {
      memcpy(&g_ActiveCardsInPlay + x * 0x5b20 + val_3 * 0x120,
             &g_ActiveCardsInPlay + width * 0x5b20 + height * 0x120,0x120);
      memcpy(&g_ActiveCardsInPlay + width * 0x5b20 + val_5 * 0x120,
             &g_ActiveCardsInPlay + x * 0x5b20 + y * 0x120,0x120);
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + val_3 * 0x120 + x * 0x5b20) * 0x34) != 0xab) {
        *(uint32_t *)(&g_CardSlot_Flags + val_3 * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + val_3 * 0x120 + x * 0x5b20) | 0x30000;
      }
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + val_5 * 0x120 + width * 0x5b20) * 0x34) != 0xab) {
        *(uint32_t *)(&g_CardSlot_Flags + val_5 * 0x120 + width * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + val_5 * 0x120 + width * 0x5b20) | 0x30000;
      }
      *(uint32_t *)(&g_CardSlot_Flags + val_3 * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_3 * 0x120 + x * 0x5b20) & 0xfffffff3;
      *(uint32_t *)(&g_CardSlot_Flags + val_5 * 0x120 + width * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_5 * 0x120 + width * 0x5b20) & 0xfffffff3;
      *(int *)(&g_CardDisplayOrder_Player + val_1 * 4) = width;
      *(int *)(&g_CardDisplayOrder_Slot + val_1 * 4) = val_5;
      *(int *)(&g_CardDisplayOrder_Player + val_2 * 4) = x;
      *(int *)(&g_CardDisplayOrder_Slot + val_2 * 4) = val_3;
      *(uint32_t *)(&g_CardSlot_Flags + val_5 * 0x120 + width * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_5 * 0x120 + width * 0x5b20) | 0x400000;
      for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
        for (color_idx = 0; color_idx < (int)(&g_PlayerActiveCardCount)[card_idx];
            color_idx = color_idx + 1) {
          if (((char)(&g_CardSlot_Toughness)[color_idx * 0x120 + card_idx * 0x5b20] == x) &&
             (*(int *)(&g_CardSlot_OriginalCardId + color_idx * 0x120 + card_idx * 0x5b20) == y)) {
            (&g_CardSlot_Toughness)[color_idx * 0x120 + card_idx * 0x5b20] = (uint8_t)width;
            *(int *)(&g_CardSlot_OriginalCardId + color_idx * 0x120 + card_idx * 0x5b20) = val_5;
          }
          if (((char)(&g_CardSlot_DamageReceived)[color_idx * 0x120 + card_idx * 0x5b20] == x) &&
             (*(int *)(&g_CardSlot_TypeFlags + color_idx * 0x120 + card_idx * 0x5b20) == y)) {
            (&g_CardSlot_DamageReceived)[color_idx * 0x120 + card_idx * 0x5b20] = (uint8_t)width;
            *(int *)(&g_CardSlot_TypeFlags + color_idx * 0x120 + card_idx * 0x5b20) = val_5;
          }
          if ((&g_CardSlot_TurnPlayed)[color_idx * 0x120 + card_idx * 0x5b20] != '\0') {
            for (loop_idx = 0;
                loop_idx < (char)(&g_CardSlot_TurnPlayed)[color_idx * 0x120 + card_idx * 0x5b20];
                loop_idx = loop_idx + 1) {
              if ((*(int *)(&g_CardSlot_CombatTarget +
                           color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) == x) &&
                 (*(int *)(&g_CardSlot_AttachedAura +
                          color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) == y)) {
                *(int *)(&g_CardSlot_CombatTarget +
                        color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) = width;
                *(int *)(&g_CardSlot_AttachedAura +
                        color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) = val_5;
              }
            }
          }
          if (((char)(&g_CardSlot_Toughness)[color_idx * 0x120 + card_idx * 0x5b20] == width) &&
             (*(int *)(&g_CardSlot_OriginalCardId + color_idx * 0x120 + card_idx * 0x5b20) == height)
             ) {
            (&g_CardSlot_Toughness)[color_idx * 0x120 + card_idx * 0x5b20] = (uint8_t)x;
            *(int *)(&g_CardSlot_OriginalCardId + color_idx * 0x120 + card_idx * 0x5b20) = val_3;
          }
          if (((char)(&g_CardSlot_DamageReceived)[color_idx * 0x120 + card_idx * 0x5b20] == width) &&
             (*(int *)(&g_CardSlot_TypeFlags + color_idx * 0x120 + card_idx * 0x5b20) == height)) {
            (&g_CardSlot_DamageReceived)[color_idx * 0x120 + card_idx * 0x5b20] = (uint8_t)x;
            *(int *)(&g_CardSlot_TypeFlags + color_idx * 0x120 + card_idx * 0x5b20) = val_3;
          }
          if ((&g_CardSlot_TurnPlayed)[color_idx * 0x120 + card_idx * 0x5b20] != '\0') {
            for (loop_idx = 0;
                loop_idx < (char)(&g_CardSlot_TurnPlayed)[color_idx * 0x120 + card_idx * 0x5b20];
                loop_idx = loop_idx + 1) {
              if ((*(int *)(&g_CardSlot_CombatTarget +
                           color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) == width) &&
                 (*(int *)(&g_CardSlot_AttachedAura +
                          color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) == height)) {
                *(int *)(&g_CardSlot_CombatTarget +
                        color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) = x;
                *(int *)(&g_CardSlot_AttachedAura +
                        color_idx * 0x120 + card_idx * 0x5b20 + loop_idx * 8) = val_3;
              }
            }
          }
        }
      }
      *(int32_t *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = 0xffffffff;
      *(int32_t *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20) = 0xffffffff;
      Rules_ProcessCombatDamageStep();
      uval_4 = 1;
    }
  }
  return uval_4;
}



/*
 * Decompiled function: Pic_Subsystem_0042d64f
 * Entry Point: 0042d64f
 * Size: 1242 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0042d64f(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  int val_3;
  int32_t uval_4;
  int match_count;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       ((*(uint8_t *)(&g_PlayerPoisonCounters + (1 - player)) & 2) != 0)) {
      return 1;
    }
    return 0;
  }
  if (arg_3 != 0x6d) goto LAB_0042d76f;
  if (match_count == -1) {
LAB_0042d745:
    g_ActivePlayer = 1;
  }
  else {
    val_2 = Card_TapForMana(player, card_slot, 0x32, 0xffffffff);
    val_3 = Card_TapForMana(g_TemporaryToughnessBuffer,match_count,0x32,0xffffffff);
    if (val_2 < val_3) goto LAB_0042d745;
    *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = match_count;
    (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
  }
  *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
       *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
LAB_0042d76f:
  if ((arg_3 == 0x72) &&
     (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
    uval_4 = Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
    *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = uval_4;
    (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = (uint8_t)player;
  }
  if (((((&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] != -1) &&
       (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
    flag_1 = true;
    if (((arg_3 == 0x77) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      flag_1 = false;
    }
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      flag_1 = false;
    }
    val_2 = Card_TapForMana(player, card_slot, 0x32, 0xffffffff);
    val_3 = Card_TapForMana((int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20),0x32,
                         0xffffffff);
    if (val_2 < val_3) {
      flag_1 = false;
    }
    if (!flag_1) {
      val_2 = *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20);
      *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
      Pic_Subsystem_0042ca53(player,val_2);
    }
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if (((arg_3 == 0x77) &&
      (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_OverworldMapGrid))
     && (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_OverworldPlayerCoordX
         && (g_OverworldMapGrid != -1)))) {
    *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
    (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
         (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042db29
 * Entry Point: 0042db29
 * Size: 502 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0042db29(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int card_idx;
  int match_count;
  
  if (arg_3 == 0x73) {
    if ((((*(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
        ((*(uint8_t *)(&g_PlayerPoisonCounters + (1 - player)) & 0x40) != 0)) &&
       ((val_1 = Font_DrawString(player, 7, 3), val_1 != 0 &&
        (val_1 = Font_DrawString(player,4,2), val_1 != 0)))) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      g_AiSelectedTargetCard = 1;
      Ai_CalcManaRequirement_004ba890(player,4,2);
      if (card_idx == -1) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = Pic_Subsystem_0042ca53(g_TemporaryToughnessBuffer,card_idx);
        *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + (1 - g_TemporaryToughnessBuffer) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + (1 - g_TemporaryToughnessBuffer) * 0x5b20) |
             0x400;
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (((arg_3 == 0x77) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[1 - player]; match_count = match_count + 1)
      {
        if (((&DAT_006a5f69)[match_count * 0x120 + (1 - player) * 0x5b20] & 4) != 0) {
          val_1 = Pic_Subsystem_0042ca53(1 - player,match_count);
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + player * 0x5b20) & 0xfffffbff;
        }
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_Feedback
 * Entry Point: 0042dd1f
 * Size: 1461 bytes
 */


int32_t CardScript_Feedback(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
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
  int32_t slot_idx;
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
    }
    else {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
    }
  }
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
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005212d8,s_FEEDBACK_005212cc);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + 0x30;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,4,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_2 = 1;
      }
      else {
        uval_2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_Brainwash
 * Entry Point: 0042e2d9
 * Size: 1333 bytes
 */


int32_t CardScript_Brainwash(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005212f0,s_BRAINWASH_005212e4);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = slot_idx;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        if (match_count == spell_id) {
          val_5 = Card_TapForMana(match_count,slot_idx,0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth - (val_5 * 0xc) / 2;
        }
        else {
          val_5 = Card_TapForMana(match_count,slot_idx,0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + (val_5 * 0xc) / 2;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((((g_PlayerManaPool == 0xdc) && (g_ScWillyScore == 0x15)) &&
         ((g_OverworldMapGrid == target_id &&
          ((g_OverworldPlayerCoordX == spell_id && (g_DefendingPlayer == g_CurrentCardColorTarget)))))) &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) &&
       (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == DAT_00695f08 &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         DAT_006b2e14)))) {
      val_5 = Font_DrawString(g_DefendingPlayer,7,3);
      if (val_5 == 0) {
        DAT_0068a65c = 1;
      }
      else {
        if (flags == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (flags == 0x7e) {
          Magic_CombatPhase(spell_id,target_id,0x7e,spell_id,0);
          Ai_CalcManaRequirement_004ba890(g_DefendingPlayer,0,3);
          Magic_DiscardToHandSize();
          if (g_ActivePlayer == 1) {
            DAT_0068a65c = 1;
            g_ActivePlayer = 0;
          }
          else {
            *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 1;
          }
        }
      }
    }
    if ((flags == 0x79) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
      val_5 = Font_DrawString(g_DefendingPlayer,7,3);
      if (val_5 == 0) {
        g_ActivePalette = 1;
      }
      uval_1 = 0;
    }
    else {
      if ((flags == 0x22) || (flags == 199)) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042e80e
 * Entry Point: 0042e80e
 * Size: 178 bytes
 */


int32_t Pic_Subsystem_0042e80e(int player_id,int card_slot,int event_type)

{
  if (((*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_OverworldMapGrid)
      && ((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_OverworldPlayerCoordX))
     && (g_OverworldMapGrid != -1)) {
    (**(code **)(&g_CardScriptCallbackTable + arg_3 * 0x34))(player,card_slot,0x79);
    if (g_ActivePlayer == 1) {
      g_ActivePalette = g_ActivePalette + 1;
      g_ActivePlayer = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_SpiritShackle
 * Entry Point: 0042e8c0
 * Size: 933 bytes
 */


int32_t CardScript_SpiritShackle(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052130c,s_SPIRIT_SHACKLE_005212fc);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (match_count == spell_id) {
          val_5 = -(*(int *)(&DAT_006a5f70 + match_count * 0x5b20 + slot_idx * 0x120) / 2);
        }
        else {
          val_5 = *(int *)(&DAT_006a5f70 + match_count * 0x5b20 + slot_idx * 0x120) / 2;
        }
        g_SpellStackDepth = g_SpellStackDepth + val_5;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      Pic_Subsystem_0042ec65(spell_id,target_id);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042ec65
 * Entry Point: 0042ec65
 * Size: 314 bytes
 */


int32_t Pic_Subsystem_0042ec65(int arg1,int arg2)

{
  *(int *)(&DAT_006a5f7c +
          *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
          (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) =
       *(int *)(&DAT_006a5f7c +
               *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) + 0x100;
  if (g_IsAiThinking != 1) {
    Duel_PlaySoundById(0x1b);
  }
  *(short *)(&g_CardSlot_ToughnessCounters +
            *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) =
       *(short *)(&g_CardSlot_ToughnessCounters +
                 *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) + -2;
  return 0;
}



/*
 * Decompiled function: CardScript_RelicBind
 * Entry Point: 0042ed9f
 * Size: 1369 bytes
 */


int32_t CardScript_RelicBind(uint32_t spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
  int *arg_20;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == spell_id) &&
       (g_OverworldMapGrid == target_id)) && (g_OverworldPlayerCoordX == spell_id)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    Pic_Subsystem_0044867e(spell_id,target_id,3);
  }
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,1 - spell_id,1 - spell_id,0x200,0x40,0,0,uval_1,arg_11
                         ,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521324,s_RELIC_BIND_00521318);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,1 - spell_id,1 - spell_id,0x200,0x40,0,0,uval_2,uval_3,uval_4,val_5,
                         val_6,uval_7,uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (((&g_MasterCardSubtypeTable)
             [*(int *)(&g_CardSlot_CardId + card_idx * 0x5b20 + match_count * 0x120) * 0x34] & 1) != 0)
        {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (((char)(&g_MasterCardManaCostTable)
                       [*(int *)(&g_CardSlot_CardId + card_idx * 0x5b20 + match_count * 0x120) * 0x34] *
                 3 + 6) * 8) / 2;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,1 - (char)spell_id,1 - (char)spell_id,0x200,0x40,0,0,
                         uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      slot_idx = Ai_Subsystem_004cc56d
                          (spell_id,spell_id,target_id,-1,-1,s_Gain_life__Take_Damage__00521330,
                           (uint32_t)((int)(&g_PlayerCreatureCount)[1 - spell_id] <=
                                 (int)(&g_PlayerCreatureCount)[spell_id]));
      Pic_Subsystem_00424500(s_prompts_txt_00521358,s_RELIC_BIND_0052134c);
      if ((int)(&g_PlayerCreatureCount)[spell_id] < (int)(&g_PlayerCreatureCount)[1 - spell_id]) {
        player_idx = spell_id;
      }
      else {
        player_idx = 1 - spell_id;
      }
      Action_ValidateTarget_00405802
                (spell_id,2,player_idx,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0xffffffff,0,0,
                 &DAT_0069f84a,0,&card_idx);
      if (slot_idx == 0) {
        (&g_PlayerCreatureCount)[card_idx] = (&g_PlayerCreatureCount)[card_idx] + 1;
      }
      else {
        Mem_AllocOrFree_0041df33(card_idx,1,spell_id,target_id);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f2f8
 * Entry Point: 0042f2f8
 * Size: 915 bytes
 */


uint32_t Pic_Subsystem_0042f2f8(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == player) {
      uval_1 = (g_PlayerPoisonCounters | DAT_006a282c) & 0x40;
    }
    else {
      uval_1 = (&g_PlayerPoisonCounters)[g_CurrentTurnPhase] & 0x40;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      if (slot_idx == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = slot_idx;
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
      }
    }
    if ((arg_3 == 0x71) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      if (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      }
    }
    if (((arg_3 == 0x7c) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_OverworldMapGrid
        )) && (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] ==
                g_OverworldPlayerCoordX &&
               ((g_OverworldMapGrid != -1 &&
                (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0))))))
    {
      Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,2,player,card_slot);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    if (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1) {
      if (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0) {
        Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,2,player,card_slot);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f690
 * Entry Point: 0042f690
 * Size: 249 bytes
 */


int32_t Pic_Subsystem_0042f690(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b3000 + (7 - player) * 4) - (&DAT_006b3018)[player]) * 0x18;
    }
    if (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40) !=
        0)) {
      Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,1,player,card_slot);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f789
 * Entry Point: 0042f789
 * Size: 242 bytes
 */


int32_t Pic_Subsystem_0042f789(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (card_slot == g_OverworldMapGrid)) && (player == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth = g_SpellStackDepth + (*(int *)(&DAT_006b3000 + (7 - player) * 4) * 0x18) / 2
      ;
    }
    if (((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       ((player != g_OverworldPlayerCoordX &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40) !=
         0)))) {
      (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_PowerLeak
 * Entry Point: 0042f87b
 * Size: 1562 bytes
 */


int32_t CardScript_PowerLeak(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
  int *arg_20;
  int target_idx;
  int32_t player_idx;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521370,s_POWERLEAK_00521364);
      arg_20 = &target_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = player_idx
        ;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = target_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,4,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        match_count = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                          [target_id * 0x120 + spell_id * 0x5b20],7,1);
        if (2 < match_count) {
          if (((match_count < 8) && (5 < (int)(&g_ActivePlayerSpellPriority)[spell_id])) &&
             (7 < (int)(&g_PlayerCreatureCount)[spell_id])) {
            match_count = 0;
          }
          else {
            match_count = 2;
          }
        }
        slot_idx = Ai_Subsystem_004cc56d
                            ((int)(char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20],spell_id,target_id,
                             (int)(char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             s_Take_the_2_damage__Pay_1_mana__t_0052137c,match_count);
        if (slot_idx == 0) {
          card_idx = 2;
        }
        else if (slot_idx == 1) {
          Magic_CombatPhase(spell_id,target_id,0x7e,0,0);
          Ai_CalcManaRequirement_004ba890
                    ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],0,1);
          Magic_DiscardToHandSize();
          if (g_ActivePlayer == 1) {
            card_idx = 2;
          }
          else {
            card_idx = 1;
          }
        }
        else {
          Ai_CalcManaRequirement_004ba890
                    ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],0,2);
          if (g_ActivePlayer == 1) {
            card_idx = 2;
          }
          else {
            card_idx = 0;
          }
        }
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                   card_idx,g_DialogPromptHwnd,g_DuelArenaHwnd);
        g_ActivePlayer = -1;
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0042fe9a
 * Entry Point: 0042fe9a
 * Size: 387 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0042fe9a(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((arg_3 == 2) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) &&
       ((*(uint8_t *)(&g_PlayerPoisonCounters + player) & 2) != 0)) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) &&
       ((g_OverworldPlayerCoordX == player && ((*(uint8_t *)(&g_PlayerPoisonCounters + player) & 2) != 0)))) {
      val_2 = Ai_Subsystem_004cc56d
                        (player,player,card_slot,-1,-1,s_Sacrifice_creature_to_use_gate__N_005213bc,0);
      if (val_2 != 0) {
        val_2 = Glue_Subsystem_004e6bff(player);
        if (val_2 != -1) {
          Pic_Subsystem_0044867e(player,val_2,3);
          if ((val_2 != -1) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) *
                          0x5b20) * 0x34] & 0x40) != 0)) {
            Pic_Subsystem_0044867e(g_TemporaryToughnessBuffer,val_2,2);
          }
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043001d
 * Entry Point: 0043001d
 * Size: 407 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0043001d(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player))
       && (g_ActivePlayerPriority == player)) {
      if (DAT_006b3018 == 0) {
        g_SpellStackDepth = g_SpellStackDepth + -0xf0;
      }
      else {
        val_2 = Font_DrawString(g_ActivePlayerPriority,7,1);
        g_SpellStackDepth = g_SpellStackDepth + (val_2 / 2 + (DAT_006b3018 - _DAT_006b301c)) * 0x18;
      }
    }
    if (((arg_3 == 0x85) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40) !=
         0)) && ((g_OverworldPlayerCoordX == g_CurrentTurnTargetPlayer && (g_DefendingPlayer == g_CurrentTurnTargetPlayer))))
    {
      *(uint32_t *)(&g_CardSlot_SpecialState +
               g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(uint32_t *)(&g_CardSlot_SpecialState +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 3;
      (&DAT_006a6048)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
           (&DAT_006a6048)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x02';
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004301b4
 * Entry Point: 004301b4
 * Size: 158 bytes
 */


int32_t Pic_Subsystem_004301b4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (card_slot == g_OverworldMapGrid)) && (player == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b3000 + (7 - player) * 4) - (&DAT_006b3018)[player]) * 0xc;
    }
    if (arg_3 == 0x22) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00430252
 * Entry Point: 00430252
 * Size: 922 bytes
 */


uint32_t Pic_Subsystem_00430252(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_2;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == player) {
      uval_1 = (g_PlayerPoisonCounters | DAT_006a282c) & 1;
    }
    else {
      uval_1 = (&g_PlayerPoisonCounters)[g_ActivePlayerPriority] & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      Glue_Subsystem_004e6dcc(player,player,card_slot);
      if (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
    }
    if (arg_3 == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uval_1 = Glue_Subsystem_004d0a42(player,card_slot);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                         (char *)0x0,player,2,2,0x200,1,0,0,uval_1,arg_12,arg_13,val_2,arg_15,arg_16,
                         arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
             (&g_CardSlot_CombatTarget)[card_slot * 0x120 + player * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20);
        Glue_Subsystem_004e65e1(Pic_Subsystem_004305f1,-1);
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    if (((arg_3 == 0x77) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_OverworldMapGrid
        )) && (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] ==
                g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      g_ActivePalette = 1;
    }
    if ((((arg_3 == 0x6c) && ((g_OverworldMapGrid != card_slot || (g_OverworldPlayerCoordX != player))))
        && (*(int *)(&g_CardSlot_OriginalCardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
            *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20))) &&
       (((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
         (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 4) != 0)
        ))) {
      g_ActivePlayer = 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004305f1
 * Entry Point: 004305f1
 * Size: 283 bytes
 */


int32_t Pic_Subsystem_004305f1(int player_id,int card_slot,int event_type)

{
  if ((((((&g_MasterCardColorTable)[arg_3 * 0x34] & 4) != 0) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20))) &&
      ((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
       (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20])) &&
     ((*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) != 0x29 &&
      ((g_OverworldPlayerCoordX != player || (g_OverworldMapGrid != card_slot)))))) {
    Pic_Subsystem_0044867e(player,card_slot,1);
  }
  return 0;
}



/*
 * Decompiled function: CardScript_Erosion
 * Entry Point: 0043070c
 * Size: 2036 bytes
 */


int32_t CardScript_Erosion(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  uint32_t uval_4;
  int32_t arg_11;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int32_t arg_14;
  int val_5;
  int32_t arg_15;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  int card_idx;
  
  flag_1 = false;
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11 = 0;
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_2,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005213f0,s_EROSION_005213e8);
      val_3 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_3 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
            g_CurrentTurnPhase) {
          val_3 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)
                               [*(int *)(&g_CardSlot_CardId +
                                        *(int *)(&g_CardSlot_AttachedAura +
                                                spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                                        *(int *)(&g_CardSlot_CombatTarget +
                                                spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               *(int *)(&g_AiCombatScore_Attacker + val_3 * 4 + g_CurrentTurnPhase * 0x20) * -4 + 0x20;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      val_5 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uval_4 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_3 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uval_4,arg_12,arg_13,val_3,val_5,arg_16
                         ,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[spell_id * 0x5b20 + target_id * 0x120] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_SpecialState + spell_id * 0x5b20 + target_id * 0x120) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_2 = 1;
      }
      else {
        uval_2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        val_3 = 1;
        uval_4 = Rules_CalculateManaCostReduction((&g_CardSlot_PlusOneCounters)
                             [*(int *)(&g_CardSlot_OriginalCardId +
                                      spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                              (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                              0x5b20]);
        val_3 = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],uval_4,val_3);
        val_5 = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],7,1);
        if (val_3 == 1) {
          if ((val_5 < 4) &&
             (10 < (int)(&g_PlayerCreatureCount)
                        [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]])) {
            card_idx = 2;
          }
          else {
            card_idx = 1;
          }
        }
        else if ((val_5 < 3) &&
                (0xf < (int)(&g_PlayerCreatureCount)
                            [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]]))
        {
          card_idx = 2;
        }
        else {
          card_idx = 0;
        }
        while (!flag_1) {
          val_3 = Ai_Subsystem_004cc56d
                            ((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],spell_id,target_id,
                             (int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],
                             *(int *)(&g_CardSlot_OriginalCardId +
                                     spell_id * 0x5b20 + target_id * 0x120),
                             s_Destroy_enchanted_land__Pay_1_ma_005213fc,card_idx);
          if (val_3 == 0) {
            Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120],
                       *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120),
                       2);
            flag_1 = true;
          }
          else if (val_3 == 1) {
            val_3 = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                            [spell_id * 0x5b20 + target_id * 0x120],7,1);
            if (val_3 != 0) {
              *(uint32_t *)(&g_CardSlot_Flags +
                       *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_Flags +
                            *(int *)(&g_CardSlot_OriginalCardId +
                                    spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                            (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) | 0x40000;
              Ai_CalcManaRequirement_004ba890
                        ((int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120],0
                         ,1);
              if (g_ActivePlayer == 1) {
                g_ActivePlayer = 0;
              }
              else {
                flag_1 = true;
              }
            }
          }
          else if (val_3 == 2) {
            (&g_PlayerCreatureCount)
            [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]] =
                 (&g_PlayerCreatureCount)
                 [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]] + -1;
            flag_1 = true;
          }
        }
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) &
             0xfffffffe;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_CursedLand
 * Entry Point: 00430f0a
 * Size: 1326 bytes
 */


int32_t CardScript_CursedLand(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
    }
    else {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
    }
  }
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
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521448,s_CURSED_LAND_0052143c);
      val_1 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_1 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + 0x30;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,val_1,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_2 = 1;
      }
      else {
        uval_2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_0043143d
 * Entry Point: 0043143d
 * Size: 650 bytes
 */


uint32_t Pic_Subsystem_0043143d(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int val_2;
  uint8_t flag_3;
  int match_count;
  
  if (arg_3 == 0x74) {
    if (player == g_CurrentTurnPhase) {
      uval_1 = (g_PlayerPoisonCounters | DAT_006a282c) & 1;
    }
    else {
      uval_1 = (&g_PlayerPoisonCounters)[g_CurrentTurnPhase] & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      val_2 = Glue_Subsystem_004e6dcc(player,1 - player,card_slot);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_slot * 0x120] == player) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&g_PlayerManaPoolDelta + (1 - player) * 0x20) - *(int *)(&g_PlayerManaPoolDelta + player * 0x20))
             * 0xc;
      }
    }
    if (((arg_3 == 0x7c) && (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x20) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_slot * 0x120) == g_OverworldMapGrid
        && (((char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_slot * 0x120] ==
             g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) {
      val_2 = Glue_Subsystem_004e654a(g_OverworldPlayerCoordX,1);
      flag_3 = val_2 != 0;
      val_2 = Glue_Subsystem_004e654a(1 - g_OverworldPlayerCoordX,1);
      if (val_2 != 0) {
        flag_3 = flag_3 | 2;
      }
      if (flag_3 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,2);
      }
      else {
        if (g_OverworldPlayerCoordX == g_CurrentTurnPhase) {
          do {
          } while (match_count == -1);
        }
        else {
          do {
          } while (match_count == -1);
        }
        *(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_slot * 0x120) = match_count;
        (&g_CardSlot_Toughness)[player * 0x5b20 + card_slot * 0x120] = g_TemporaryToughnessBuffer;
      }
      Pic_Subsystem_0044867e(g_OverworldPlayerCoordX,g_OverworldMapGrid,2);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004316cc
 * Entry Point: 004316cc
 * Size: 756 bytes
 */


int32_t Pic_Subsystem_004316cc(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int val_3;
  int val_4;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    val_1 = Card_UntapCard(player,card_slot,1);
    if (*(int *)(&g_AiCombatScore_Attacker + val_1 * 4 + g_CurrentTurnPhase * 0x20) != 0) {
      val_1 = 0x18 - (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase] /
                     *(int *)(&g_AiCombatScore_Attacker + val_1 * 4 + g_CurrentTurnPhase * 0x20);
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
    }
    val_1 = Card_UntapCard(player,card_slot,1);
    if (*(int *)(&g_AiCombatScore_Attacker + val_1 * 4 + g_ActivePlayerPriority * 0x20) != 0) {
      val_1 = 0x18 - (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] /
                     *(int *)(&g_AiCombatScore_Attacker + val_1 * 4 + g_ActivePlayerPriority * 0x20);
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
    }
  }
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else if (arg_3 == 0x73) {
    if (((g_ScWillyScore == 4) &&
        (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) &&
       ((g_DefendingPlayer == g_CurrentTurnTargetPlayer &&
        (val_1 = Card_UntapCard(player,card_slot,1),
        *(int *)(&g_AiCombatScore_Attacker + val_1 * 4 + g_CurrentTurnTargetPlayer * 0x20) != 0)))) {
      *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x101;
      g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
      return 1;
    }
    uval_2 = 0;
  }
  else {
    if (((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
      DAT_00695df8 = 1;
      g_ActivePalette = g_ActivePalette | 1;
    }
    if (arg_3 == 0x86) {
      val_1 = player;
      val_4 = card_slot;
      val_3 = Card_UntapCard(player,card_slot,1);
      Mem_AllocOrFree_0041df33
                (g_DefendingPlayer,*(int *)(&g_AiCombatScore_Attacker + val_3 * 4 + g_DefendingPlayer * 0x20),
                 val_1,val_4);
    }
    if (arg_3 == 0x22) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
    }
    if (arg_3 == 199) {
      val_1 = 1 - g_DefendingPlayer;
      val_4 = Card_UntapCard(player,card_slot,1);
      Mem_AllocOrFree_0041df33(val_1,*(int *)(&g_AiCombatScore_Attacker + val_4 * 4 + val_1 * 0x20),player,card_slot)
      ;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_EvilPresence
 * Entry Point: 004319c5
 * Size: 1294 bytes
 */


int32_t CardScript_EvilPresence(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521464,s_EVIL_PRESENCE_00521454);
      val_2 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x40 / (longlong)(*(int *)(&g_PlayerManaPoolDelta + g_CurrentTurnPhase * 0x20) + 1));
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                    target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) == 0) {
          g_SpellStackDepth = g_SpellStackDepth + -0xf0;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
        val_2 = Card_UntapCard(spell_id,target_id,
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     target_id * 0x120 + spell_id * 0x5b20));
        *(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             val_2 + -1;
        *(uint32_t *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x1000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
        ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_OverworldMapGrid &&
         (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) &&
       (val_2 = Card_IsTapped(spell_id,target_id), val_2 != 0)) {
      val_2 = Card_UntapCard(spell_id,target_id,
                           *(int *)(&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20));
      g_ActivePalette = val_2 + -1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_LivingArtifact
 * Entry Point: 00431ed3
 * Size: 1830 bytes
 */


int32_t CardScript_LivingArtifact(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  int slot_idx;
  
  if ((((flags == 0x6e) &&
       (*(int *)(&g_CardSlot_CardId + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
        == g_PendingSpellTargetSlot)) &&
      ((char)(&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
       == spell_id)) &&
     ((*(int *)(&g_CardSlot_OriginalCardId +
               g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) == -1 &&
      (*(int *)(&g_CardSlot_ConvertedManaCost +
               g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) != 0)))) {
    *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) +
         *(int *)(&g_CardSlot_ConvertedManaCost +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120);
  }
  if (((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == target_id)) &&
     ((g_OverworldPlayerCoordX == spell_id &&
      ((*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
       (spell_id == g_CurrentCardColorTarget)))))) {
    if (flags == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (flags == 0x7e) {
      Glue_Subsystem_004e67e1
                (spell_id,target_id,
                 *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20));
      *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
  }
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uval_1,arg_11_00,arg_12_00,
                         arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521480,s_LIVING_ARTIFACT_00521470);
      val_2 = Glue_Subsystem_004e70ad(spell_id,2,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (g_ActivePlayer != 1) {
        if ((int)(&g_PlayerCreatureCount)[spell_id] < (int)(&g_PlayerCreatureCount)[1 - spell_id]) {
          slot_idx = 3;
        }
        else {
          slot_idx = 1;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (char)(&g_MasterCardManaCostTable)
                     [*(int *)(&g_CardSlot_CardId +
                              *(int *)(&g_CardSlot_AttachedAura +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                              *(int *)(&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] *
               slot_idx * 0x18;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + (uint32_t)(slot_idx * 0x18) / 2;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == spell_id)) && (spell_id == g_CurrentTurnTargetPlayer))
         && ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0
             && (val_2 = Glue_Subsystem_004e6978(spell_id,target_id), val_2 != 0)))) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_006330d0 + val_2 * 4) == 0) ||
           (val_2 = FUN_0040dcca(spell_id,target_id,7,0), val_2 != 0)) {
          if (g_ActivePlayerPriority == spell_id) {
            g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
          }
          uval_1 = 1;
        }
        else {
          uval_1 = 0;
        }
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if (((flags == 0x6d) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + val_2 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
          Glue_Subsystem_004e676b(spell_id,target_id);
        }
      }
      if (flags == 0x72) {
        (&g_PlayerCreatureCount)[spell_id] = (&g_PlayerCreatureCount)[spell_id] + 1;
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Blight
 * Entry Point: 004325fe
 * Size: 1300 bytes
 */


int32_t CardScript_Blight(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
  int *arg_20;
  int card_idx;
  int match_count;
  
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521494,s_BLIGHT_0052148c);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,2,0x200,1,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9,
                         uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (card_idx == g_CurrentTurnPhase) {
          val_5 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)
                               [*(int *)(&g_CardSlot_CardId + card_idx * 0x5b20 + match_count * 0x120) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x60 / (longlong)
                            (*(int *)(&g_AiCombatScore_Attacker + val_5 * 4 + g_CurrentTurnPhase * 0x20) + 1));
        }
        if (card_idx == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x18;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                        0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) | 0x40000;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x81) &&
         (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_OverworldMapGrid)) &&
        (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_OverworldPlayerCoordX &&
         ((g_OverworldMapGrid != -1 &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))))) &&
       (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0)) {
      val_5 = Card_ApplyTriggerEffect(spell_id,target_id,DAT_006a4b64,
                           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(int *)(&g_CardSlot_OriginalCardId +
                                    target_id * 0x120 + spell_id * 0x5b20));
      if (val_5 != -1) {
        (&g_CardSlot_CardTypeIndex)[val_5 * 0x120 + spell_id * 0x5b20] = 5;
      }
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_TargetLand
 * Entry Point: 00432b12
 * Size: 1118 bytes
 */


int32_t CardScript_TargetLand(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214ac,s_TARGET_LAND_005214a0);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,1,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (match_count == g_CurrentTurnPhase) {
          val_5 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)
                               [*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x60 / (longlong)
                            (*(int *)(&g_AiCombatScore_Attacker + val_5 * 4 + g_CurrentTurnPhase * 0x20) + 1));
        }
        if (match_count == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                        0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) | 0x40000;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      Mem_AllocOrFree_0041df33
                ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],2,
                 spell_id,target_id);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00432f70
 * Entry Point: 00432f70
 * Size: 231 bytes
 */


int32_t Pic_Subsystem_00432f70(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&g_PlayerManaPoolDelta + g_ActivePlayerPriority * 0x20) -
           *(int *)(&g_PlayerManaPoolDelta + g_CurrentTurnPhase * 0x20)) * 0x18;
    }
    if (((arg_3 == 0x81) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 1) != 0)
        ) && (g_PendingAttackersTargetSlot != -1)) {
      Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,1,player,card_slot);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00433057
 * Entry Point: 00433057
 * Size: 475 bytes
 */


int32_t Pic_Subsystem_00433057(int player_id,int card_slot,int event_type)

{
  uint8_t arg_1_00;
  int32_t uval_1;
  int arg_2_00;
  int arg_3_00;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (player == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if (((arg_3 == 0x81) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 1) != 0)
        ) && (g_PendingAttackersTargetSlot != -1)) {
      FUN_0040d875(g_OverworldPlayerCoordX,g_PendingAttackersTargetSlot,1);
    }
    if (((arg_3 == 0x7f) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 1) != 0)
        ) && (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] &
              0x10) == 0)) {
      arg_1_00 = (&g_CardSlot_PlusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      slot_idx = 0;
      for (match_count = 0; match_count < 7; match_count = match_count + 1) {
        if (((int)(char)arg_1_00 & 1 << ((uint8_t)match_count & 0x1f)) != 0) {
          slot_idx = slot_idx + 1;
        }
      }
      if (slot_idx < 1) {
        arg_3_00 = 1;
        arg_2_00 = Rules_CalculateManaCostReduction(arg_1_00);
        FUN_0040d7e9(g_OverworldPlayerCoordX,arg_2_00,arg_3_00);
      }
      else {
        FUN_0040d59c(g_OverworldPlayerCoordX,(int)(char)arg_1_00,1);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00433232
 * Entry Point: 00433232
 * Size: 258 bytes
 */


int32_t Pic_Subsystem_00433232(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((arg_3 == 0x81) && (g_OverworldPlayerCoordX != player)) {
      val_3 = *(int *)(&g_CardSlot_CardId +
                      g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120);
      val_2 = Card_UntapCard(player,card_slot,3);
      if (*(int *)(&g_MasterCardTypeTable + val_3 * 0x34) == *(int *)(&DAT_006ff2bc + val_2 * 4)) {
        (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
      }
    }
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (g_OverworldMapGrid == card_slot)) &&
       (g_OverworldPlayerCoordX == player)) {
      val_3 = Card_UntapCard(player,card_slot,3);
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&g_AiCombatScore_Attacker + val_3 * 4 + g_CurrentTurnPhase * 0x20) * 3 + 3) * 8;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00433334
 * Entry Point: 00433334
 * Size: 306 bytes
 */


void Pic_Subsystem_00433334(int player_id,int32_t card_slot,int event_type)

{
  if (arg_3 != 0x74) {
    if ((((arg_3 == 0x32) && (g_OverworldPlayerCoordX == player)) &&
        ((&g_MasterCardRarityTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] == '\0'))
       && (((uint8_t)*(int32_t *)
                   (&g_CardSlot_Flags +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) & 0x22) == 2)) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    if (((arg_3 == 0x34) && (g_OverworldPlayerCoordX == player)) &&
       (((&g_MasterCardRarityTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] == '\0' &&
        (((uint8_t)*(int32_t *)
                 (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
         & 0x22) == 2)))) {
      g_ActivePalette = g_ActivePalette | 0x40;
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00433466
 * Entry Point: 00433466
 * Size: 438 bytes
 */


int32_t Pic_Subsystem_00433466(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  
  if (arg_3 == 0x74) {
    uval_3 = 1;
  }
  else {
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       (((uint8_t)*(int32_t *)
                (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
        & 0x22) == 2)) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(player,card_slot,2);
      if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    if (((arg_3 == 0x85) && (g_OverworldMapGrid == card_slot)) &&
       ((g_OverworldPlayerCoordX == player &&
        ((g_DefendingPlayer == player && (g_CurrentTurnTargetPlayer == player)))))) {
      *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
      (&DAT_006a604a)[card_slot * 0x120 + player * 0x5b20] =
           (&DAT_006a604a)[card_slot * 0x120 + player * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if ((arg_3 == 199) && ((int)(&DAT_0063ee38)[player * 8] < 2)) {
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Pic_Subsystem_0043361c
 * Entry Point: 0043361c
 * Size: 220 bytes
 */


int32_t Pic_Subsystem_0043361c(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  
  if (arg_3 == 0x74) {
    uval_3 = 1;
  }
  else {
    if ((((arg_3 == 0x32) || (arg_3 == 0x33)) &&
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0)) &&
       (((uint8_t)*(int32_t *)
                (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
        & 0x22) == 2)) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(player,card_slot,1);
      if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Pic_Subsystem_004336f8
 * Entry Point: 004336f8
 * Size: 934 bytes
 */


int32_t Pic_Subsystem_004336f8(int player_id,int card_slot,int event_type)

{
  char cVar1;
  bool flag_2;
  uint8_t flag_3;
  int32_t uval_4;
  int val_5;
  int val_6;
  int color_idx;
  int target_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_4 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      if (g_CurrentTurnPhase == player) {
        val_5 = Util_GetRandomNumber(5);
        target_idx = val_5 + 1;
      }
      else {
        slot_idx = -1;
        for (match_count = 1; match_count < 7; match_count = match_count + 1) {
          if (slot_idx < *(int *)(&DAT_006b2e40 + match_count * 4 + (1 - player) * 0x20) +
                        *(int *)(&DAT_006b2fa0 + match_count * 4 + (1 - player) * 0x20)) {
            slot_idx = *(int *)(&DAT_006b2fa0 + match_count * 4 + (1 - player) * 0x20) +
                      *(int *)(&DAT_006b2fa0 + match_count * 4 + (1 - player) * 0x20);
            target_idx = match_count;
          }
        }
      }
      if (player == 1) {
        color_idx = target_idx;
      }
      else {
        color_idx = -1;
      }
      val_5 = Ai_Subsystem_004cc93d(player,s_Jihad_color__005214b8,1,color_idx,0xffffffff);
      *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = val_5;
      if (val_5 == -1) {
        g_ActivePlayer = 1;
      }
    }
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       ((((uint8_t)*(int32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x22) == 2 &&
        ((((uint8_t)*(int32_t *)
                  (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                  ) & 0x22) == 2 &&
         (cVar1 = (&g_CardSlot_PlusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120],
         flag_3 = Card_SetTapState(player, card_slot, 5), (1 << (flag_3 & 0x1f) & (int)cVar1) != 0)))))) {
      if (arg_3 == 0x32) {
        g_ActivePalette = g_ActivePalette + 2;
      }
      else {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0) &&
        (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      flag_2 = false;
      val_5 = 1 - player;
      flag_3 = (&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20];
      for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[val_5]; match_count = match_count + 1) {
        val_6 = Card_IsTapped(val_5,match_count);
        if (((val_6 != 0) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + val_5 * 0x5b20) * 0x34] & 0x1e) != 0)
            ) && ((1 << (flag_3 & 0x1f) &
                  (int)(char)(&g_CardSlot_MinusOneCounters)[match_count * 0x120 + val_5 * 0x5b20]) != 0)) {
          flag_2 = true;
          break;
        }
      }
      if (!flag_2) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
        Pic_Subsystem_0044867e(player,card_slot,1);
      }
    }
    uval_4 = 0;
  }
  return uval_4;
}



/*
 * Decompiled function: Pic_Subsystem_00433a9e
 * Entry Point: 00433a9e
 * Size: 229 bytes
 */


int32_t Pic_Subsystem_00433a9e(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_006b3010 + player * 4) * 0xc;
    }
    if (((arg_3 == 0x32) &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 4) !=
         0)) && ((player == g_DefendingPlayer &&
                 ((g_OverworldPlayerCoordX == player &&
                  (((uint8_t)*(int32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) & 0x22
                   ) == 2)))))) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00433b83
 * Entry Point: 00433b83
 * Size: 223 bytes
 */


int32_t Pic_Subsystem_00433b83(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  
  if (arg_3 == 0x74) {
    uval_3 = 1;
  }
  else {
    if ((((arg_3 == 0x32) || (arg_3 == 0x33)) &&
        (((uint8_t)*(int32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x22) == 2))
       && (((uint8_t)*(int32_t *)
                   (&g_CardSlot_Flags +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) & 0x22) == 2)) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(player, card_slot, 5);
      if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: CardScript_AspectOfWolf
 * Entry Point: 00433c62
 * Size: 851 bytes
 */


int32_t CardScript_AspectOfWolf(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214d8,s_ASPECTOFWOLF_005214c8);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if ((g_ActivePlayer != 1) &&
         (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
          g_CurrentTurnPhase)) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 0x32) {
        val_2 = Card_UntapCard(spell_id,target_id,3);
        g_ActivePalette =
             g_ActivePalette + *(int *)(&g_AiCombatScore_Attacker + val_2 * 4 + spell_id * 0x20) / 2;
      }
      if (flags == 0x33) {
        val_2 = Card_UntapCard(spell_id,target_id,3);
        g_ActivePalette =
             g_ActivePalette + (*(int *)(&g_AiCombatScore_Attacker + val_2 * 4 + spell_id * 0x20) + 1) / 2;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: File_Load_Prompts
 * Entry Point: 00433fb5
 * Size: 1401 bytes
 */


int32_t File_Load_Prompts(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  uint8_t slot_idx;
  
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214ec,&DAT_005214e4);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if ((g_PlayerManaPool == 0xda) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      g_PlayerManaPool = 0xffffffff;
      if (((((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
             g_DefendingPlayer) &&
           ((((&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 4)
             != 0 && (((&g_CardSlot_Flags)
                       [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 2) != 0))))
          && ((&g_CardSlot_ColorMask)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
              == -1)) && (g_OverworldPlayerCoordX != g_DefendingPlayer)) {
        val_2 = Pic_Subsystem_0043452e
                          (g_OverworldPlayerCoordX,g_OverworldMapGrid,
                           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(int32_t *)
                             (&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
        if (val_2 != 0) {
          if ((&g_CardSlot_ColorMask)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] ==
              -1) {
            slot_idx = (uint8_t)
                      *(int32_t *)
                       (&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          }
          else {
            slot_idx = (&g_CardSlot_ColorMask)
                      [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
          }
          if (flags == 0x7d) {
            g_ActivePalette = g_ActivePalette | 2;
          }
          if (flags == 0x7e) {
            (&g_CardSlot_ColorMask)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
                 slot_idx;
            *(uint32_t *)(&g_CardSlot_Flags +
                     g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags +
                          g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x8008;
          }
        }
      }
      g_PlayerManaPool = 0xda;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043452e
 * Entry Point: 0043452e
 * Size: 123 bytes
 */


int32_t Pic_Subsystem_0043452e(int x,int card_slot,int event_type,int arg_4)

{
  uint32_t arg_5;
  int32_t uval_1;
  uint32_t card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  arg_5 = Card_TapForMana(arg_3,arg_4,0x34,0xffffffff);
  Ai_FilterValidBlockers(&slot_idx,&match_count);
  if (x == 1) {
    card_idx = slot_idx;
  }
  else {
    card_idx = match_count;
  }
  uval_1 = FUN_00472c0c(x,card_slot,arg_3,arg_4,arg_5,card_idx);
  return uval_1;
}



/*
 * Decompiled function: CardScript_SpiritLink
 * Entry Point: 004345a9
 * Size: 1398 bytes
 */


int32_t CardScript_SpiritLink(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  int slot_idx;
  
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521504,s_SPIRITLINK_005214f8);
      val_2 = Glue_Subsystem_004e69ac(spell_id,2,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (g_ActivePlayer != 1) {
        val_2 = Card_TapForMana(*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
        g_SpellStackDepth = g_SpellStackDepth + val_2 * 0x18;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                 ) == g_PendingSpellTargetSlot)) &&
       (((&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
         == (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] &&
        ((*(int *)(&g_CardSlot_TypeFlags +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) != 0)))))) {
      *(int *)(&g_CardSlot_CombatTarget +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_OverworldPlayerCoordX;
      *(int *)(&g_CardSlot_AttachedAura +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_OverworldMapGrid;
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
        (spell_id == g_CurrentCardColorTarget)))) {
      if (flags == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (flags == 0x7e) {
        for (slot_idx = 0;
            slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20
                              ); slot_idx = slot_idx + 1) {
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_AttachedAura +
                               target_id * 0x120 + spell_id * 0x5b20 + slot_idx * 8) * 0x120 +
                       *(int *)(&g_CardSlot_CombatTarget +
                               target_id * 0x120 + spell_id * 0x5b20 + slot_idx * 8) * 0x5b20);
        }
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_CreatureBond
 * Entry Point: 00434b1f
 * Size: 1043 bytes
 */


int32_t CardScript_CreatureBond(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521520,s_CREATUREBOND_00521510);
      val_2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + 0x18;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x77) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX &&
        ((g_OverworldMapGrid != -1 &&
         (val_2 = Deck_AddCardToDeck(spell_id,DAT_006ff564), val_2 != -1)))))) {
      *(int32_t *)(&g_ActiveCardsInPlay + val_2 * 0x120 + spell_id * 0x5b20) =
           *(int32_t *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20);
      *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + spell_id * 0x5b20) | 2;
      *(int32_t *)(&DAT_006a5f74 + val_2 * 0x120 + spell_id * 0x5b20) = 0x32;
      uval_1 = Card_TapForMana(g_OverworldPlayerCoordX,g_OverworldMapGrid,0x33,0xffffffff);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) = uval_1;
      (&g_CardSlot_Toughness)[val_2 * 0x120 + spell_id * 0x5b20] =
           (uint8_t)g_OverworldPlayerCoordX;
      FUN_00476482(spell_id,val_2);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_GaseousForm
 * Entry Point: 00434f32
 * Size: 1153 bytes
 */


int32_t CardScript_GaseousForm(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521538,s_GASEOUSFORM_0052152c);
      val_2 = Glue_Subsystem_004e69ac(spell_id,2,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x21) && ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) &&
       (*(int *)(&g_CardSlot_CardId + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
        == g_PendingSpellTargetSlot)) {
      if (((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
           (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]) &&
         (*(int *)(&g_CardSlot_OriginalCardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20))) {
        (&DAT_006a5f4f)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
             (&g_CardSlot_ConvertedManaCost)
             [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
        *(int32_t *)
         (&g_CardSlot_ConvertedManaCost +
         g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) = 0;
      }
      if (((&g_CardSlot_DamageReceived)
           [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
           (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]) &&
         (*(int *)(&g_CardSlot_TypeFlags +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20))) {
        (&DAT_006a5f4f)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
             (&g_CardSlot_ConvertedManaCost)
             [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
        *(int32_t *)
         (&g_CardSlot_ConvertedManaCost +
         g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) = 0;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Backfire
 * Entry Point: 004353b3
 * Size: 1804 bytes
 */


int32_t CardScript_Backfire(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  int card_idx;
  
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521550,s_BACKFIRE_00521544);
      val_2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          val_2 = Card_TapForMana(*(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20),
                               *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + val_2 * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + -0x18;
        }
        (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x6e) &&
         (*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) == g_PendingSpellTargetSlot))
        && ((*(int *)(&g_CardSlot_OriginalCardId +
                     g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) == -1 &&
            (((char)(&g_CardSlot_Toughness)
                    [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] == spell_id &&
             (*(int *)(&g_CardSlot_TypeFlags +
                      g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
              *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20))))))) &&
       ((&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
        == (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20])) {
      *(int *)(&g_CardSlot_CombatTarget +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_OverworldPlayerCoordX;
      *(int *)(&g_CardSlot_AttachedAura +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_OverworldMapGrid;
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
        (spell_id == g_CurrentCardColorTarget)))) {
      if (flags == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (flags == 0x7e) {
        for (card_idx = 0;
            card_idx <
            *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
            card_idx = card_idx + 1) {
          Mem_AllocOrFree_0041df33
                    ((int)(char)(&g_CardSlot_DamageReceived)
                                [*(int *)(&g_CardSlot_AttachedAura +
                                         target_id * 0x120 + spell_id * 0x5b20 + card_idx * 8) *
                                 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 +
                                                 spell_id * 0x5b20 + card_idx * 8) * 0x5b20],
                     *(int *)(&g_CardSlot_ConvertedManaCost +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + card_idx * 8) * 0x120 +
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + card_idx * 8) * 0x5b20)
                     ,spell_id,target_id);
        }
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    if (((flags == 0x8a) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount +
                     *(short *)(&g_CardSlot_Counters +
                               *(int *)(&g_CardSlot_OriginalCardId +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                               (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                               * 0x5b20) * 0x18;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_HolyArmor
 * Entry Point: 00435abf
 * Size: 2625 bytes
 */


int32_t CardScript_HolyArmor(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (flags == 1) {
    *(int *)(&DAT_006ff6a4 + spell_id * 0x20) = *(int *)(&DAT_006ff6a4 + spell_id * 0x20) + 1;
  }
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
      *(int32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
           *(int32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
      Pic_Subsystem_00424500(s_prompts_txt_00521568,s_HOLY_ARMOR_0052155c);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x33) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         g_OverworldMapGrid &&
        (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
          g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) {
      g_ActivePalette = g_ActivePalette + 2;
    }
    if (flags == 0x73) {
      uval_1 = FUN_0040dcca(spell_id,target_id,5,1);
    }
    else if (flags == 0x90) {
      if (spell_id == g_DefendingPlayer) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      g_AiCurrentSearchPath = (int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] << 8
                     | *(uint32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
      ;
      uval_1 = 0;
    }
    else {
      if ((flags == 0x6d) && (val_2 = FUN_0040dcca(spell_id,target_id,5,1), val_2 != 0)) {
        if (spell_id == g_DefendingPlayer) {
          val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,-1);
          }
          else {
            g_TurnCounter = Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          if (g_TurnCounter < 1) {
            g_ActivePlayer = 1;
          }
          else {
            *(int *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = g_TurnCounter
            ;
          }
        }
        else {
          val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          *(int32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(int32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) =
               (int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120];
          *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) =
               *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120);
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)
          {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) |
                 0x80000;
          }
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                    0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) == -1) {
          g_ActivePlayer = 1;
        }
        else {
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] = 0;
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                       0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120
                                       ) * 0x5b20) +
               (*(uint32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) & 0xff) *
               0x100;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120
                + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] &
              8) != 0) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                     0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120)
                             * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120
                                  ) * 0x120 +
                          *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                          0x5b20) & 0xfff7ffff;
            val_2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [spell_id * 0x5b20 + target_id * 0x120],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         spell_id * 0x5b20 + target_id * 0x120));
            if (val_2 != -1) {
              *(short *)(&g_CardSlot_ToughnessCounters + val_2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(int32_t *)
                           (&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
              *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) |
                   0x80000;
            }
          }
        }
      }
      if (flags == 199) {
        if (spell_id == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee44 + spell_id * 0x20) * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee44 + spell_id * 0x20) * -0xc;
        }
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(int32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Blessing
 * Entry Point: 00436500
 * Size: 2656 bytes
 */


int32_t CardScript_Blessing(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (flags == 1) {
    *(int *)(&DAT_006ff6a4 + spell_id * 0x20) = *(int *)(&DAT_006ff6a4 + spell_id * 0x20) + 1;
  }
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      Pic_Subsystem_00424500(s_prompts_txt_00521580,s_BLESSING_00521574);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      uval_1 = FUN_0040dcca(spell_id,target_id,5,1);
    }
    else if (flags == 0x90) {
      if (g_DefendingPlayer == spell_id) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      g_AiCurrentSearchPath = (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] << 8
                     | *(uint32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
      ;
      uval_1 = 0;
    }
    else {
      if ((flags == 0x6d) && (val_2 = FUN_0040dcca(spell_id,target_id,5,1), val_2 != 0)) {
        if (g_DefendingPlayer == spell_id) {
          val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,-1);
          }
          else {
            g_TurnCounter = Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          if (g_TurnCounter < 1) {
            g_ActivePlayer = 1;
          }
          else {
            *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = g_TurnCounter
            ;
          }
        }
        else {
          val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
          {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) |
                 0x80000;
          }
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) == -1) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) +
               (*(uint32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) & 0xff);
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) +
               (*(uint32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) & 0xff) *
               0x100;
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120]
              & 8) != 0) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                     + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                           target_id * 0x120 + spell_id * 0x5b20) * 0x120) &
                 0xfff7ffff;
            val_2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [target_id * 0x120 + spell_id * 0x5b20],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         target_id * 0x120 + spell_id * 0x5b20));
            if (val_2 != -1) {
              *(short *)(&g_CardSlot_PowerCounters + val_2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(int32_t *)
                           (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
              *(short *)(&g_CardSlot_ToughnessCounters + val_2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(int32_t *)
                           (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
              *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) |
                   0x80000;
            }
          }
        }
      }
      if (flags == 199) {
        if (g_ActivePlayerPriority == spell_id) {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee44 + spell_id * 0x20) * 3 + 6) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee44 + spell_id * 0x20) * 3 + 6) * -4;
        }
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Firebreathing
 * Entry Point: 00436f60
 * Size: 2522 bytes
 */


int32_t CardScript_Firebreathing(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (flags == 1) {
    *(int *)(&DAT_006ff6a0 + spell_id * 0x20) = *(int *)(&DAT_006ff6a0 + spell_id * 0x20) + 1;
  }
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      Pic_Subsystem_00424500(s_prompts_txt_0052159c,s_FIREBREATHING_0052158c);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == spell_id) {
        g_SpellStackDepth = g_SpellStackDepth + 0xc;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0xc;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      uval_1 = FUN_0040dcca(spell_id,target_id,4,1);
    }
    else if (flags == 0x90) {
      if (spell_id == g_DefendingPlayer) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      g_AiCurrentSearchPath = (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] << 8
                     | *(uint32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
      ;
      uval_1 = 0;
    }
    else {
      if ((flags == 0x6d) && (val_2 = FUN_0040dcca(spell_id,target_id,4,1), val_2 != 0)) {
        if (spell_id == g_DefendingPlayer) {
          val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,4,-1);
          }
          else {
            g_TurnCounter = Ai_Subsystem_004be192(spell_id,target_id,4,1);
          }
          if (g_TurnCounter < 1) {
            g_ActivePlayer = 1;
          }
          else {
            *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = g_TurnCounter
            ;
          }
        }
        else {
          val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + val_2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,4,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,4,1);
          }
          *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
          {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) |
                 0x80000;
          }
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) == -1) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) +
               (*(uint32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) & 0xff);
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120]
              & 8) != 0) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                     + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                           target_id * 0x120 + spell_id * 0x5b20) * 0x120) &
                 0xfff7ffff;
            val_2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [target_id * 0x120 + spell_id * 0x5b20],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         target_id * 0x120 + spell_id * 0x5b20));
            if (val_2 != -1) {
              *(short *)(&g_CardSlot_PowerCounters + val_2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(int32_t *)
                           (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
              *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + spell_id * 0x5b20) |
                   0x80000;
            }
          }
        }
      }
      if (flags == 199) {
        if (spell_id == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee40 + spell_id * 0x20) * 3 + 3) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee40 + spell_id * 0x20) * 3 + 3) * -4;
        }
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Invisibility
 * Entry Point: 0043793a
 * Size: 387 bytes
 */


void CardScript_Invisibility(int spell_id,int target_id,int flags)

{
  int val_1;
  
  if (flags != 0x74) {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215b8,s_INVISIBILITY_005215a8);
      val_1 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         DAT_006b2d5c)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == DAT_007006c8 &&
        ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         ((&g_MasterCardRarityTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] != '\0')))
        ))) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  return;
}



/*
 * Decompiled function: File_Load_Prompts
 * Entry Point: 00437ac2
 * Size: 820 bytes
 */


int32_t File_Load_Prompts(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  int val_4;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215cc,&DAT_005215c4);
      val_4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         DAT_006b2d5c)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == DAT_007006c8 &&
        ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(spell_id,target_id,1);
      if ((1 << (flag_2 & 0x1f) & (int)cVar1) == 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: CardScript_Seeker
 * Entry Point: 00437df6
 * Size: 820 bytes
 */


int32_t CardScript_Seeker(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  int val_4;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215e0,s_SEEKER_005215d8);
      val_4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         DAT_006b2d5c)) &&
       (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == DAT_007006c8 &&
        ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(spell_id,target_id,5);
      if ((1 << (flag_2 & 0x1f) & (int)cVar1) == 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: File_Load_Prompts
 * Entry Point: 0043812a
 * Size: 754 bytes
 */


int32_t File_Load_Prompts(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215f0,&DAT_005215ec);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if ((g_ActivePlayer != 1) && (spell_id != g_CurrentTurnPhase)) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 0x33) {
        g_ActivePalette = g_ActivePalette + 2;
      }
      if (flags == 0x34) {
        g_ActivePalette = g_ActivePalette | 0x400;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043841c
 * Entry Point: 0043841c
 * Size: 1143 bytes
 */


int32_t Pic_Subsystem_0043841c(int player_id,int card_slot,int event_type)

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
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      val_2 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1);
      if (val_2 == 0) {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_006b2e5c + (1 - player) * 0x20) - *(int *)(&DAT_006b2e5c + player * 0x20))
        ;
      }
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = (uint8_t)player;
    }
    if (((arg_3 == 0x85) && (g_OverworldMapGrid == card_slot)) &&
       ((g_OverworldPlayerCoordX == player &&
        ((g_DefendingPlayer == player && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)))))) {
      *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
      (&DAT_006a604a)[card_slot * 0x120 + player * 0x5b20] =
           (&DAT_006a604a)[card_slot * 0x120 + player * 0x5b20] + '\x01';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if (arg_3 == 199) {
      if ((int)(&DAT_0063ee38)[player * 8] < 1) {
        Pic_Subsystem_0044867e(player,card_slot,1);
      }
      else {
        val_2 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          val_2 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        match_count = 0;
        for (slot_idx = 0; slot_idx < val_2; slot_idx = slot_idx + 1) {
          if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1)
              && (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
              & 2) != 0)) {
            if (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) == 0) {
              val_3 = Rules_ValidateCardTargetSlot(g_CurrentTurnPhase,slot_idx);
              if (val_3 == 0) {
                match_count = match_count + *(short *)(&g_CardSlot_Counters +
                                              slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20);
              }
            }
            else {
              match_count = match_count + *(short *)(&g_CardSlot_Counters +
                                            slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20) * 2;
            }
          }
          if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
                -1) && (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                        != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) *
                0x34] & 2) != 0)) {
            if (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0
               ) {
              val_3 = Rules_ValidateCardTargetSlot(g_ActivePlayerPriority,slot_idx);
              if (val_3 == 0) {
                match_count = match_count - *(short *)(&g_CardSlot_Counters +
                                              slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20);
              }
            }
            else {
              match_count = match_count + *(short *)(&g_CardSlot_Counters +
                                            slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) * -2;
            }
          }
        }
        g_SpellStackDepth = g_SpellStackDepth + match_count * 0xc;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00438893
 * Entry Point: 00438893
 * Size: 258 bytes
 */


int32_t Pic_Subsystem_00438893(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((g_DefendingPlayer == player) && ((g_PlayerHandCardCount & 1) != 0)) {
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffffe;
      if (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else {
        Mem_AllocOrFree_0041df33(player,1,player,card_slot);
      }
    }
    if (arg_3 == 0x22) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00438995
 * Entry Point: 00438995
 * Size: 856 bytes
 */


int32_t Pic_Subsystem_00438995(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int32_t uval_3;
  
  if (arg_3 == 0x74) {
    uval_3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e48 + (1 - player) * 0x20) - *(int *)(&DAT_006b2e48 + player * 0x20));
    }
    if (arg_3 == 0x82) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(player,card_slot,2);
      if (((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0
         )) {
        *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
             *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                      ) & 0xfffffffc;
      }
    }
    if (((arg_3 == 0x84) &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 0x10)
         != 0)) &&
       ((g_DefendingPlayer == g_OverworldPlayerCoordX &&
        ((g_DefendingPlayer == g_CurrentTurnTargetPlayer &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0
         )))))) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(player,card_slot,2);
      if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
        *(uint32_t *)(&g_CardSlot_SpecialState +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
             *(uint32_t *)(&g_CardSlot_SpecialState +
                      g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x10;
        (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
             (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x04'
        ;
      }
    }
    if (arg_3 == 0x6c) {
      cVar1 = (&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      flag_2 = Card_SetTapState(player,card_slot,2);
      if (((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0
         )) {
        (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
             (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x04'
        ;
      }
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: CardScript_Paralyze
 * Entry Point: 00438ced
 * Size: 1819 bytes
 */


int32_t CardScript_Paralyze(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  uint8_t local_98 [12];
  uint8_t *local_8c;
  uint8_t local_88 [128];
  uint8_t *slot_idx;
  
  slot_idx = local_88;
  local_8c = local_98;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521608,s_PARALYZE_005215fc);
      val_2 = Glue_Subsystem_004e69ac(spell_id,2,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        (&DAT_006a603c)
        [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] =
             (&DAT_006a603c)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] +
             '\x04';
        if (g_ActivePlayerPriority == spell_id) {
          if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == spell_id
             ) {
            g_SpellStackDepth = g_SpellStackDepth + -0x18;
          }
          else if (((&g_MasterCardRarityTable)
                    [*(int *)(&g_CardSlot_CardId +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] ==
                    '\0') &&
                  (((&DAT_006a5f69)
                    [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] & 8) == 0)) {
            g_SpellStackDepth = g_SpellStackDepth + -0x18;
          }
          else {
            g_SpellStackDepth =
                 g_SpellStackDepth +
                 *(int *)(&DAT_006a5f70 +
                         *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20
                                 ) * 0x120 +
                         (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) / 2;
          }
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        FUN_00415d48((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x82) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      *(uint32_t *)(&g_CardSlot_ProtectionFlags +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ProtectionFlags +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) & 0xfffffffc;
    }
    if (((((flags == 0x84) &&
          (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_OverworldMapGrid)) &&
         ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_OverworldPlayerCoordX)) &&
        ((g_OverworldMapGrid != -1 &&
         (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10)
          != 0)))) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
        && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)))) {
      *(uint32_t *)(&g_CardSlot_SpecialState +
               g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(uint32_t *)(&g_CardSlot_SpecialState +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x10;
      (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
           (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x04';
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00439408
 * Entry Point: 00439408
 * Size: 987 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_00439408(int player_id,int card_slot,int event_type)

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
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player))
       && (val_2 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120),
                                -1), val_2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e5c + g_CurrentTurnPhase * 0x20) -
           *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20)) * 0xc;
    }
    if ((arg_3 == 0x82) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0))
    {
      *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
           & 0xfffffffd;
      _DAT_006ff198 = _DAT_006ff198 | 2;
    }
    if (((g_ScWillyScore == 1) && (g_OverworldMapGrid == card_slot)) &&
       (g_OverworldPlayerCoordX == player)) {
      if (((arg_3 == 0x7d) &&
          (val_2 = UI_PaintBigCardInfo((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                                0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,
                                0x800,0), val_2 == 0)) &&
         (val_2 = UI_PaintBigCardInfo((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                               0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400
                               ,0), val_2 != 0)) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (arg_3 == 0x7e) {
        if (g_DefendingPlayer == 1) {
          card_idx = g_DefendingPlayer;
          match_count = Pic_Subsystem_00441a42(1,2);
          Ai_Subsystem_004cc56d
                    (player,player,card_slot,card_idx,match_count,s_Opponent_chooses_to_untap__00521614,0);
        }
        else {
          Action_ValidateTarget_00405802
                    (g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,0x200,2,0,0,0,0,0,-1,-1,
                     0xffffffff,0xffffffff,0,0x401,0,s_PROCESSING_Smoke__Select_creatur_00521630,0,
                     &card_idx);
        }
        *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_idx * 0x5b20 + match_count * 0x120) =
             *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_idx * 0x5b20 + match_count * 0x120) | 2;
        for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[g_DefendingPlayer];
            slot_idx = slot_idx + 1) {
          val_2 = Card_IsTapped(g_DefendingPlayer,slot_idx);
          if (((val_2 != 0) &&
              (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_DefendingPlayer * 0x5b20] & 0x10) != 0)) &&
             ((((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_DefendingPlayer * 0x5b20) * 0x34]
               & 2) != 0 &&
              (((&g_CardSlot_ProtectionFlags)[slot_idx * 0x120 + g_DefendingPlayer * 0x5b20] & 2) == 0)))) {
            *(uint32_t *)(&g_CardSlot_ProtectionFlags + slot_idx * 0x120 + g_DefendingPlayer * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ProtectionFlags + slot_idx * 0x120 + g_DefendingPlayer * 0x5b20) &
                 0xfffffffe;
          }
        }
      }
    }
    if (arg_3 == 0x22) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004397e3
 * Entry Point: 004397e3
 * Size: 938 bytes
 */


int32_t Pic_Subsystem_004397e3(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x6a) {
      *(int32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) = 0;
      for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[g_DefendingPlayer];
          match_count = match_count + 1) {
        val_2 = Card_IsTapped(g_DefendingPlayer,match_count);
        if (((val_2 != 0) &&
            (((&g_CardSlot_Flags)[match_count * 0x120 + g_DefendingPlayer * 0x5b20] & 0x10) == 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_DefendingPlayer * 0x5b20) * 0x34] &
            1) != 0)) {
          *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
               *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) + 1;
        }
      }
    }
    if (arg_3 == 0x73) {
      if (((g_ScWillyScore == 4) &&
          (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) &&
         (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) {
        *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 0x86) {
        Mem_AllocOrFree_0041df33
                  (g_DefendingPlayer,
                   *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20),player,card_slot);
        *(int32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) = 0;
      }
      if (arg_3 == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
      }
      if (arg_3 == 199) {
        slot_idx = 0;
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[1 - g_DefendingPlayer];
            match_count = match_count + 1) {
          val_2 = Card_IsTapped(1 - g_DefendingPlayer,match_count);
          if (((val_2 != 0) &&
              (((&g_CardSlot_Flags)[match_count * 0x120 + (1 - g_DefendingPlayer) * 0x5b20] & 0x10) == 0
              )) && (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId +
                               match_count * 0x120 + (1 - g_DefendingPlayer) * 0x5b20) * 0x34] & 1) != 0
                    )) {
            slot_idx = slot_idx + 1;
          }
        }
        Mem_AllocOrFree_0041df33(1 - g_DefendingPlayer,slot_idx,player,card_slot);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Cocoon
 * Entry Point: 00439b92
 * Size: 500 bytes
 */


uint32_t CardScript_Cocoon(int spell_id,int target_id,int flags)

{
  uint32_t uval_1;
  int val_2;
  
  if (flags == 0x74) {
    if (spell_id == g_CurrentTurnPhase) {
      uval_1 = (g_PlayerPoisonCounters | DAT_006a282c) & 2;
    }
    else {
      uval_1 = (&g_PlayerPoisonCounters)[g_CurrentTurnPhase] & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521664,s_COCOON_0052165c);
      val_2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 4) {
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) + 1;
      }
      if (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) < 4) {
        *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      else {
        if (flags == 0x33) {
          g_ActivePalette = g_ActivePalette + 1;
        }
        if (flags == 0x32) {
          g_ActivePalette = g_ActivePalette + 1;
        }
        if (flags == 0x34) {
          g_ActivePalette = g_ActivePalette | 0x20;
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Burrowing
 * Entry Point: 00439d8b
 * Size: 123 bytes
 */


void CardScript_Burrowing(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052167c,s_BURROWING_00521670);
  }
  cVar1 = Card_UntapCard(spell_id,target_id,4);
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,1 << (cVar1 - 1U & 0x1f));
  return;
}



/*
 * Decompiled function: CardScript_Wanderlust
 * Entry Point: 00439e06
 * Size: 1313 bytes
 */


int32_t CardScript_Wanderlust(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
    }
    else {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
    }
  }
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
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521694,s_WANDERLUST_00521688);
      val_1 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_1 == 0);
      if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
          g_CurrentTurnPhase) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
      if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
          g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + -0x60;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_1,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_2 = 1;
      }
      else {
        uval_2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_InstillEnergy
 * Entry Point: 0043a32c
 * Size: 2364 bytes
 */


int32_t CardScript_InstillEnergy(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005216b0,s_INSTILL_ENERGY_005216a0);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if ((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) {
        if (((&g_MasterCardRarityTable)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] ==
             '\0') &&
           (((&DAT_006a5f69)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] &
            8) == 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -0x30;
        }
        if ((((&g_MasterCardSubtypeTable)
              [*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] & 1)
             != 0) &&
           (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == spell_id))
        {
          g_SpellStackDepth = g_SpellStackDepth + 0x30;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (((&g_CardSlot_Flags)
             [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 2) !=
            0) {
          *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xfffcffff;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
      if ((*(int *)(&DAT_006330d0 + val_2 * 4) == 0) ||
         (val_2 = FUN_0040dcca(spell_id,target_id,7,0), val_2 != 0)) {
        if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
            && ((((&g_CardSlot_Flags)
                  [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20] & 0x10) != 0 && (g_DefendingPlayer == g_OverworldPlayerCoordX))))
           && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) {
          uval_1 = 1;
        }
        else {
          uval_1 = 0;
        }
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if ((flags == 0x6d) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + val_2 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
        }
      }
      if (flags == 0x72) {
        if (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) == -1) {
          g_ActivePlayer = 1;
        }
        else {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffffef;
        }
      }
      if ((((((g_PlayerManaPool == 0xd4) && (g_OverworldMapGrid == target_id)) &&
            (g_OverworldPlayerCoordX == spell_id)) &&
           ((*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
            ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)))) &&
          ((*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) != -1 &&
           ((DAT_00695f08 == spell_id && (DAT_006b2e14 == target_id)))))) &&
         (spell_id == g_CurrentCardColorTarget)) {
        if (flags == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (flags == 0x7e) {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 0x30000;
        }
      }
      if (((flags == 0x22) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Flood
 * Entry Point: 0043ac68
 * Size: 811 bytes
 */


int32_t CardScript_Flood(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
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
  int32_t slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if (flags == 0x73) {
      val_2 = FUN_0040dcca(spell_id,target_id,2,2);
      if (val_2 != 0) {
        arg_19 = 0;
        arg_18_00 = 0;
        arg_17 = 0;
        arg_16 = 0xffffffff;
        arg_15 = 0xffffffff;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        arg_12 = 0;
        uval_1 = 0;
        uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_3 | 0x20,uval_1,arg_12,arg_13,
                             arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
        if (val_2 != 0) {
          return 1;
        }
      }
      uval_1 = 0;
    }
    else {
      if ((flags == 0x6d) && (Ai_Subsystem_004be192(spell_id,target_id,2,2), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_005216c4,s_FLOOD_005216bc);
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
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3 | 0x20,uval_4,uval_5,val_2,val_6,
                           uval_7,uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               slot_idx;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
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
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3 | 0x20,uval_4,uval_5,
                           val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_00415d48(*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                       *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20));
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043af93
 * Entry Point: 0043af93
 * Size: 212 bytes
 */


int32_t Pic_Subsystem_0043af93(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else if (arg_3 == 0x73) {
    if ((g_ActivePlayerPriority == player) && ((&g_PlayerCreatureCount)[player] == 2)) {
      uval_1 = 0;
    }
    else {
      val_2 = FUN_0040dcca(player,card_slot,1,1);
      if ((val_2 == 0) || ((int)(&g_PlayerCreatureCount)[player] < 2)) {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
  }
  else {
    if (arg_3 == 0x6d) {
      Ai_Subsystem_004be192(player,card_slot,1,1);
    }
    if (arg_3 == 0x72) {
      Magic_ExecuteDrawPhase(player);
      (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + -2;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043b067
 * Entry Point: 0043b067
 * Size: 368 bytes
 */


int32_t Pic_Subsystem_0043b067(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else if (arg_3 == 0x73) {
    uval_1 = FUN_0040dcca(player,card_slot,1,1);
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_0040dcca(player,card_slot,1,1);
      if (val_2 != 0) {
        Ai_Subsystem_004be192(player,card_slot,1,1);
      }
    }
    if (arg_3 == 0x72) {
      Mem_AllocOrFree_0041df33(1 - player,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      Mem_AllocOrFree_0041df33(player,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      Glue_Subsystem_004e65e1(Pic_Subsystem_0043b1d7,-1);
    }
    if ((((g_PlayerManaPool == 0xcd) && (g_OverworldMapGrid == card_slot)) &&
        (g_OverworldPlayerCoordX == player)) && (g_CurrentCardColorTarget == player)) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (arg_3 == 0x7e) {
        val_2 = Glue_Subsystem_004e654a(player,2);
        if (val_2 == 0) {
          val_2 = Glue_Subsystem_004e654a(1 - player,2);
          if (val_2 == 0) {
            Pic_Subsystem_0044867e(player,card_slot,2);
          }
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043b1d7
 * Entry Point: 0043b1d7
 * Size: 77 bytes
 */


int32_t Pic_Subsystem_0043b1d7(int player_id,int card_slot,int event_type)

{
  if (((&g_MasterCardColorTable)[arg_3 * 0x34] & 2) != 0) {
    Card_ApplyCombatDamage(player, card_slot, 1, g_DialogPromptHwnd, g_DuelArenaHwnd);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0043b224
 * Entry Point: 0043b224
 * Size: 512 bytes
 */


int32_t Pic_Subsystem_0043b224(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((&g_PlayerCreatureCount)[player] - (&g_PlayerCreatureCount)[1 - player]) * 0xc;
    }
    if (((arg_3 == 2) && (g_OverworldMapGrid == card_slot)) && (player == g_OverworldPlayerCoordX)) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) && (player == g_OverworldPlayerCoordX)) {
      val_2 = Font_DrawString(player,3,*(int *)(&g_CardSlot_ConvertedManaCost +
                                           card_slot * 0x120 + player * 0x5b20) + 1);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,2);
      }
      else {
        val_2 = Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_Pay_mana__No_Yes_005216d0,1);
        if (val_2 == 0) {
          Pic_Subsystem_0044867e(player,card_slot,2);
        }
        else {
          Ai_CalcManaRequirement_004ba890
                    (player,3,*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20
                                     ) + 1);
          *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) + 1;
          Mem_AllocOrFree_0041df33
                    (1 - player,
                     *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20),player,
                     card_slot);
          Mem_AllocOrFree_0041df33
                    (player,*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20),
                     player,card_slot);
          Glue_Subsystem_004e65e1(Pic_Subsystem_0043b1d7,-1);
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043b424
 * Entry Point: 0043b424
 * Size: 711 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0043b424(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int val_3;
  int val_4;
  int val_5;
  char *mode_str;
  int local_28;
  int loop_idx;
  int target_idx;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 2) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x6c) {
      val_5 = *(int *)(&DAT_006b2e5c + player * 0x20);
      val_3 = Math_Clamp(*(int *)(&DAT_006b3010 + player * 4),1,99);
      val_1 = *(int *)(&DAT_006b2e5c + (1 - player) * 0x20);
      val_4 = Math_Clamp(*(int *)(&DAT_006b3000 + (5 - player) * 4),1,99);
      g_SpellStackDepth = g_SpellStackDepth + ((val_5 * 0xc) / val_3 - (val_1 * 0xc) / val_4);
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      card_idx = 999;
      loop_idx = 0;
      player_idx = 0xffffffff;
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_5 = Card_IsTapped(slot_idx,match_count);
          if ((val_5 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0)
             ) {
            val_5 = Card_TapForMana(slot_idx,match_count,0x32,0xffffffff);
            if (val_5 < card_idx) {
              player_idx = slot_idx * 0x100 + match_count;
              loop_idx = 0;
              card_idx = val_5;
            }
            if (val_5 == card_idx) {
              loop_idx = loop_idx + 1;
            }
          }
        }
      }
      if (loop_idx == 1) {
        Pic_Subsystem_0044867e((int)player_idx >> 8,player_idx & 0xff,1);
      }
      if (1 < loop_idx) {
        do {
          strcpy(&g_OverworldWorldState,s_Lowest_power_is_005216e4);
          str_2 = _itoa(card_idx,&DAT_00538b80,10);
          strcat(&g_OverworldWorldState,str_2);
          target_idx = -1;
          if (local_28 != -1) {
            target_idx = Card_TapForMana(g_TemporaryToughnessBuffer,local_28,0x32,0xffffffff);
          }
        } while (target_idx != card_idx);
        Pic_Subsystem_0044867e(g_TemporaryToughnessBuffer,local_28,1);
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_Lance
 * Entry Point: 0043b6eb
 * Size: 99 bytes
 */


void CardScript_Lance(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521700,s_LANCE_005216f8);
  }
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,0x100);
  return;
}



/*
 * Decompiled function: CardScript_FishliverOil
 * Entry Point: 0043b74e
 * Size: 123 bytes
 */


void CardScript_FishliverOil(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052171c,s_FISHLIVEROIL_0052170c);
  }
  cVar1 = Card_UntapCard(spell_id,target_id,2);
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,1 << (cVar1 - 1U & 0x1f));
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043b7c9
 * Entry Point: 0043b7c9
 * Size: 677 bytes
 */


void Pic_Subsystem_0043b7c9(int x,int y,int width,uint32_t height)

{
  int32_t arg_10;
  int val_1;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (width == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    arg_10 = Glue_Subsystem_004d0a42(x,y);
    UI_PaintBigCardInfo((int *)0x0,0,x,2,2,0x200,2,0,0,arg_10,arg_11_00,arg_12_00,arg_13_00,arg_14,
                 arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((width == 0x6c) && (g_OverworldMapGrid == y)) && (g_OverworldPlayerCoordX == x)) {
      val_1 = Glue_Subsystem_004e69ac(x,x,y);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (width == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(x,y);
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_1,arg_15,arg_16,arg_17,arg_18,
                         arg_19,arg_20);
      if (val_1 == 0) {
        Pic_Subsystem_0044867e(x,y,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] =
             (&g_CardSlot_CombatTarget)[y * 0x120 + x * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) == g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x20) == 0 && (width == 0x34)))))) {
      g_ActivePalette = g_ActivePalette | height;
    }
  }
  return;
}



/*
 * Decompiled function: CardScript_HolyStrength
 * Entry Point: 0043ba6e
 * Size: 98 bytes
 */


void CardScript_HolyStrength(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521738,s_HOLY_STRENGTH_00521728);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,1,2);
  return;
}



/*
 * Decompiled function: CardScript_GiantStrength
 * Entry Point: 0043bad0
 * Size: 98 bytes
 */


void CardScript_GiantStrength(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521754,s_GIANT_STRENGTH_00521744);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,2);
  return;
}



/*
 * Decompiled function: CardScript_Immolation
 * Entry Point: 0043bb32
 * Size: 98 bytes
 */


void CardScript_Immolation(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052176c,s_IMMOLATION_00521760);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,-2);
  return;
}



/*
 * Decompiled function: CardScript_DivineTransformation
 * Entry Point: 0043bb94
 * Size: 98 bytes
 */


void CardScript_DivineTransformation(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521790,s_DIVINE_TRANSFORMATION_00521778);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,3,3);
  return;
}



/*
 * Decompiled function: CardScript_UnholyStrength
 * Entry Point: 0043bbf6
 * Size: 98 bytes
 */


void CardScript_UnholyStrength(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005217ac,s_UNHOLY_STRENGTH_0052179c);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,1);
  return;
}



/*
 * Decompiled function: CardScript_Weakness
 * Entry Point: 0043bc58
 * Size: 98 bytes
 */


void CardScript_Weakness(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005217c4,s_WEAKNESS_005217b8);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,-2,-1);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043bcba
 * Entry Point: 0043bcba
 * Size: 1006 bytes
 */


int32_t Pic_Subsystem_0043bcba(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t uval_3;
  uint32_t arg_12;
  int32_t uval_4;
  uint32_t arg_13;
  int32_t uval_5;
  int32_t uval_6;
  int arg_15;
  int32_t uval_7;
  uint32_t arg_16;
  int32_t uval_8;
  uint32_t arg_17;
  int32_t uVar9;
  uint32_t arg_18;
  int32_t uVar10;
  uint32_t arg_19;
  int32_t uVar11;
  uint32_t arg_20;
  uint32_t slot_idx;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == player) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      uval_6 = 0xffffffff;
      uval_5 = 0xffffffff;
      uval_4 = 0;
      uval_3 = 0;
      uval_1 = Glue_Subsystem_004d0a42(player,card_slot);
      uval_1 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uval_1,uval_3,uval_4,uval_5,uval_6,uval_7,
                           uval_8,uVar9,uVar10,uVar11);
    }
    else if (arg_5 + arg_4 < 0) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      uval_6 = 0xffffffff;
      uval_5 = 0xffffffff;
      uval_4 = 0;
      uval_3 = 0;
      uval_1 = Glue_Subsystem_004d0a42(player,card_slot);
      uval_1 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uval_1,uval_3,uval_4,uval_5,uval_6,uval_7,
                           uval_8,uVar9,uVar10,uVar11);
    }
    else {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      uval_6 = 0xffffffff;
      uval_5 = 0xffffffff;
      uval_4 = 0;
      uval_3 = 0;
      uval_1 = Glue_Subsystem_004d0a42(player,card_slot);
      uval_1 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uval_1,uval_3,uval_4,uval_5,uval_6,uval_7,
                           uval_8,uVar9,uVar10,uVar11);
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      if (arg_5 + arg_4 < 0) {
        slot_idx = 1 - player;
      }
      else {
        slot_idx = player;
      }
      val_2 = Glue_Subsystem_004e69ac(player,slot_idx,card_slot);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (arg_3 == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(player,card_slot);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                         (char *)0x0,player,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,arg_16,
                         arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
             (&g_CardSlot_CombatTarget)[card_slot * 0x120 + player * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0) {
      if (((arg_3 == 0x32) &&
          (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) ==
           g_OverworldMapGrid)) &&
         (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_OverworldPlayerCoordX
          && (g_OverworldMapGrid != -1)))) {
        g_ActivePalette = g_ActivePalette + arg_4;
      }
      if (((arg_3 == 0x33) &&
          (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) ==
           g_OverworldMapGrid)) &&
         (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_OverworldPlayerCoordX
          && (g_OverworldMapGrid != -1)))) {
        g_ActivePalette = g_ActivePalette + arg_5;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043c0b2
 * Entry Point: 0043c0b2
 * Size: 194 bytes
 */


int32_t Pic_Subsystem_0043c0b2(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((arg_3 == 0x33) && (g_OverworldPlayerCoordX == player)) &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 0x14)
         == 0)) &&
       ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x20) == 0 &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 2) !=
         0)))) {
      g_ActivePalette = g_ActivePalette + 2;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043c174
 * Entry Point: 0043c174
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c174(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,1);
  CardScript_AnyWard(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c1ab
 * Entry Point: 0043c1ab
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c1ab(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,3);
  CardScript_AnyWard(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c1e2
 * Entry Point: 0043c1e2
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c1e2(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,2);
  CardScript_AnyWard(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c219
 * Entry Point: 0043c219
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c219(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,4);
  CardScript_AnyWard(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c250
 * Entry Point: 0043c250
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c250(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player, card_slot, 5);
  CardScript_AnyWard(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: CardScript_AnyWard
 * Entry Point: 0043c287
 * Size: 1646 bytes
 */


int32_t CardScript_AnyWard(int spell_id,int target_id,int flags,int height)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  uint32_t uval_4;
  int32_t arg_11;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int32_t arg_14;
  int32_t arg_15;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  int card_idx;
  int slot_idx;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005217dc,s_ANY_WARD_005217d0);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_ActivePlayerPriority) {
          val_2 = *(int *)(&DAT_006b2e40 + height * 4 + g_CurrentTurnPhase * 0x20);
          val_3 = Card_TapForMana((int)(char)(&g_CardSlot_Toughness)
                                          [target_id * 0x120 + spell_id * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId +
                                       target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + (val_2 + 1) * val_3 * 3;
        }
        if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      val_3 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uval_4 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uval_4,arg_12,arg_13,val_2,val_3,arg_16
                         ,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    uval_4 = g_ActivePalette;
    if (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[slot_idx];
            card_idx = card_idx + 1) {
          if (((((((&g_CardSlot_Flags)[card_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0) &&
                (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
                 *(int *)(&g_CardSlot_OriginalCardId + card_idx * 0x120 + slot_idx * 0x5b20))) &&
               (((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
                 (&g_CardSlot_Toughness)[card_idx * 0x120 + slot_idx * 0x5b20] &&
                ((int)(char)(&g_CardSlot_MinusOneCounters)[card_idx * 0x120 + slot_idx * 0x5b20] ==
                 1 << ((uint8_t)height & 0x1f))))) &&
              ((spell_id != slot_idx || (target_id != card_idx)))) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) * 0x34] & 4) != 0
             )) {
            g_ActivePalette = uval_4;
            Pic_Subsystem_0044867e(slot_idx,card_idx,1);
          }
        }
      }
    }
    g_ActivePalette = uval_4;
    if ((((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_OverworldMapGrid) &&
         ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) &&
       ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (height = Card_SetTapState(spell_id,target_id,height), flags == 0x34)))) {
      g_ActivePalette = g_ActivePalette | 0x800 << ((char)height - 1U & 0x1f);
    }
    if (((flags == 0x6c) &&
        ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         (&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120])) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         *(int *)(&g_CardSlot_OriginalCardId +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) &&
        (((1 << ((uint8_t)height & 0x1f) &
          (int)(char)(&g_CardSlot_MinusOneCounters)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120])
          != 0 && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))))) {
      g_ActivePalette = 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_UnstableMutation
 * Entry Point: 0043c8f5
 * Size: 2249 bytes
 */


int32_t CardScript_UnstableMutation(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005217fc,s_UNSTABLE_MUTATION_005217e8);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) &&
         (((&g_CardSlot_Subtypes)
           [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] & 3
          ) != 0)) {
        g_SpellStackDepth = g_SpellStackDepth + -99;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x32) || (flags == 0x33)) &&
       ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_OverworldMapGrid &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)))))) {
      g_ActivePalette = g_ActivePalette + 3;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        *(short *)(&g_CardSlot_PowerCounters +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&g_CardSlot_PowerCounters +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(short *)(&g_CardSlot_ToughnessCounters +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&g_CardSlot_ToughnessCounters +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(int *)(&DAT_006a5f7c +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             *(int *)(&DAT_006a5f7c +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) + 0x10000;
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x1b);
        }
      }
      if (flags == 199) {
        *(short *)(&g_CardSlot_PowerCounters +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&g_CardSlot_PowerCounters +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(short *)(&g_CardSlot_ToughnessCounters +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&g_CardSlot_ToughnessCounters +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(uint32_t *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x6000000;
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      if (flags == 199) {
        *(short *)(&g_CardSlot_PowerCounters +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&g_CardSlot_PowerCounters +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -2;
        *(short *)(&g_CardSlot_ToughnessCounters +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&g_CardSlot_ToughnessCounters +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -2;
        if (((g_ActivePlayerPriority == spell_id) && (g_DefendingPlayer == g_ActivePlayerPriority))
           && (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20] & 0x40) == 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -0x3c;
        }
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_CopyArtifact
 * Entry Point: 0043d1c3
 * Size: 2124 bytes
 */


int32_t CardScript_CopyArtifact(int spell_id,int target_id,int flags)

{
  bool flag_1;
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
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      do {
        Pic_Subsystem_00424500(s_prompts_txt_00521818,s_COPY_ARTIFACT_00521808);
        arg_20 = &card_idx;
        uval_2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
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
                          (spell_id,2,2,0x200,0x40,0,0,uval_3,uval_4,uval_5,val_6,val_7,uval_8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
        if (val_6 == 0) {
          g_ActivePlayer = 1;
        }
        else if (((&g_MasterCardColorTable)
                  [*(int *)(&g_ActiveCardsInPlay + card_idx * 0x5b20 + match_count * 0x120) * 0x34] &
                 0x40) == 0) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_target__didn_t_enter_pla_00521824);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_00521858);
          }
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               card_idx;
          *(int *)(&g_CardSlot_AttachedAura +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               match_count;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      } while ((g_ActivePlayer != 1) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_ActiveCardsInPlay + card_idx * 0x5b20 + match_count * 0x120) * 0x34] & 0x40
               ) == 0));
    }
    if (flags == 0x71) {
      uVar12 = 0;
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uval_3,uval_4,uval_5,val_6,val_7,uval_8
                         ,uVar9,uVar10,uVar11,uVar12);
      if (val_6 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        flag_1 = false;
        if ((*(int *)(&g_MasterCardTypeTable +
                     *(int *)(&g_ActiveCardsInPlay +
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20) * 0x120) * 0x34) ==
             0x207) ||
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_ActiveCardsInPlay +
                            *(int *)(&g_CardSlot_CombatTarget +
                                    target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                            *(int *)(&g_CardSlot_AttachedAura +
                                    target_id * 0x120 + spell_id * 0x5b20) * 0x120) * 0x34) == 0x20d
           )) {
          flag_1 = true;
        }
        if (flag_1) {
          slot_idx = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                         *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&g_CardSlot_AttachedAura +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        else {
          slot_idx = FUN_0041d8a6(*(int *)(&g_ActiveCardsInPlay +
                                         *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&g_CardSlot_AttachedAura +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        if (slot_idx != -1) {
          *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
          *(int32_t *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
               *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
          *(int32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
               0x1000000;
          (&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] =
               (&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] | 4;
        }
        (&g_CardSlot_MinusOneCounters)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_MinusOneCounters)
             [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120];
        if (flag_1) {
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) !=
              0) {
            *(int *)(&DAT_006b3010 + spell_id * 4) = *(int *)(&DAT_006b3010 + spell_id * 4) + 1;
          }
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 0x40)
              != 0) {
            (&DAT_006b3018)[spell_id] = (&DAT_006b3018)[spell_id] + 1;
          }
          if (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 4) !=
              0) {
            *(int *)(&DAT_006b3020 + spell_id * 4) = *(int *)(&DAT_006b3020 + spell_id * 4) + 1;
          }
          (&g_PlayerPoisonCounters)[spell_id] =
               (&g_PlayerPoisonCounters)[spell_id] |
               (uint32_t)(uint8_t)(&g_MasterCardColorTable)
                           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) *
                            0x34];
          *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) |
               (spell_id == 0) - 1 & 0x400000 | 0x30082;
          DAT_00695f08 = spell_id;
          DAT_006b2e14 = target_id;
          FUN_00476205(g_DefendingPlayer,0xdb,s_Card_into_play_0052185c,0);
        }
        else {
          Pic_Subsystem_0042ac1f(spell_id,target_id);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
        (g_OverworldMapGrid == target_id)) &&
       ((g_OverworldPlayerCoordX == spell_id &&
        (val_6 = Card_IsTapped(spell_id,target_id), val_6 != 0)))) {
      g_ActivePalette =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_TargetArtifact
 * Entry Point: 0043da0f
 * Size: 1447 bytes
 */


int32_t CardScript_TargetArtifact(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
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
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
    }
    else {
      val_1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
    }
  }
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
    uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052187c,s_TARGET_ARTIFACT_0052186c);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0x40,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (match_count == g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               ((char)(&g_MasterCardManaCostTable)
                      [*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) * 0x34] * 3
               + 3) * 4;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7
                         ,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_DefendingPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_2 = 1;
      }
      else {
        uval_2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_0043dfbb
 * Entry Point: 0043dfbb
 * Size: 315 bytes
 */


int32_t Pic_Subsystem_0043dfbb(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ede4 + player * 0x20) * 0xc;
    }
    if (((arg_3 == 2) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      val_2 = Font_DrawString(player,5,2);
      if (val_2 != 0) {
        g_ActivePalette = g_ActivePalette | 1;
      }
    }
    if ((((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) ||
       (arg_3 == 199)) {
      val_2 = Font_DrawString(player,5,2);
      if (val_2 != 0) {
        val_2 = Ai_Subsystem_004cc56d
                          (player,player,card_slot,-1,-1,s_Add_life_for_2_white_mana__No_Ye_00521888,1);
        if (val_2 != 0) {
          Ai_CalcManaRequirement_004ba890(player,5,2);
          (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043e0f6
 * Entry Point: 0043e0f6
 * Size: 1697 bytes
 */


int32_t Pic_Subsystem_0043e0f6(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  uint32_t uval_2;
  char *char_ptr_3;
  int val_4;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int aiStack_288 [160];
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (arg_3 == 0x73) {
      if (((g_ScWillyScore == 4) &&
          (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) &&
         (g_DefendingPlayer == g_CurrentTurnTargetPlayer)) {
        *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x101;
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_ActivePalette = g_ActivePalette | 1;
      }
      if (arg_3 == 0x86) {
        if (g_IsAiThinking == 1) {
          return 0;
        }
        for (local_290 = 0; local_290 < 2; local_290 = local_290 + 1) {
          local_294 = 0;
          for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[local_290];
              slot_idx = slot_idx + 1) {
            if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + local_290 * 0x5b20) != -1) &&
                (((&g_CardSlot_Flags)[slot_idx * 0x120 + local_290 * 0x5b20] & 2) != 0)) &&
               ((((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + local_290 * 0x5b20) * 0x34] &
                 0x43) != 0 &&
                (val_4 = slot_idx * 0x120, uval_2 = Glue_Subsystem_004d0a42(player,card_slot),
                (*(uint32_t *)(&g_CardSlot_Abilities2 + val_4 + local_290 * 0x5b20) & uval_2) == 0)))) {
              aiStack_288[local_294 + local_290 * 0x50] = slot_idx;
              local_294 = local_294 + 1;
            }
          }
          if (g_CurrentTurnPhase == local_290) {
            local_2a8 = local_294;
          }
          else {
            local_2a4 = local_294;
          }
        }
        if (g_DefendingPlayer == g_CurrentTurnPhase) {
          if (local_2a8 < 1) {
            g_ActivePlayer = 1;
          }
          else {
            val_4 = Util_GetRandomNumber(local_2a8);
            local_298 = aiStack_288[val_4 + g_CurrentTurnPhase * 0x50];
            local_28c = 0;
            local_29c = 0;
            local_294 = Util_GetRandomNumber(local_2a4);
            while ((local_28c == 0 && (local_29c < local_2a4))) {
              local_2a0 = aiStack_288[local_294 + g_ActivePlayerPriority * 0x50];
              if (((&g_MasterCardColorTable)
                   [*(int *)(&g_CardSlot_CardId +
                            g_ActivePlayerPriority * 0x5b20 + local_2a0 * 0x120) * 0x34] &
                  (&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_298 * 0x120 + g_CurrentTurnPhase * 0x5b20) *
                   0x34]) == 0) {
                local_294 = (local_294 + 1) % local_2a4;
                local_29c = local_29c + 1;
              }
              else {
                local_28c = 1;
              }
            }
            if (local_28c != 1) {
              g_ActivePlayer = 1;
            }
          }
        }
        else if (local_2a4 < 1) {
          g_ActivePlayer = 1;
        }
        else {
          val_4 = Util_GetRandomNumber(local_2a4);
          local_2a0 = aiStack_288[val_4 + g_ActivePlayerPriority * 0x50];
          local_28c = 0;
          local_29c = 0;
          local_294 = Util_GetRandomNumber(local_2a8);
          while ((local_28c == 0 && (local_29c < local_2a8))) {
            local_298 = aiStack_288[local_294 + g_CurrentTurnPhase * 0x50];
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + g_ActivePlayerPriority * 0x5b20 + local_2a0 * 0x120)
                  * 0x34] &
                (&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_298 * 0x120 + g_CurrentTurnPhase * 0x5b20) *
                 0x34]) == 0) {
              local_294 = (local_294 + 1) % local_2a8;
              local_29c = local_29c + 1;
            }
            else {
              local_28c = 1;
            }
          }
          if (local_28c != 1) {
            g_ActivePlayer = 1;
          }
        }
        if ((local_28c == 1) && (g_ActivePlayer != 1)) {
          strcpy(&g_OverworldWorldState,s_is_swapping_005218b0);
          char_ptr_3 = (char *)Ai_Subsystem_004b8e4d(g_CurrentTurnPhase,local_298);
          strcat(&g_OverworldWorldState,char_ptr_3);
          strcat(&g_OverworldWorldState,s_for_005218c0);
          char_ptr_3 = (char *)Ai_Subsystem_004b8e4d(g_ActivePlayerPriority,local_2a0);
          strcat(&g_OverworldWorldState,char_ptr_3);
          Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,&g_OverworldWorldState,0);
          Pic_Subsystem_0042ce63(g_CurrentTurnPhase,local_298,g_ActivePlayerPriority,local_2a0);
        }
        if (g_ActivePlayer != 1) {
          Duel_PlaySoundById(0x2a);
        }
      }
      if (arg_3 == 0x22) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043e79c
 * Entry Point: 0043e79c
 * Size: 1054 bytes
 */


int32_t Pic_Subsystem_0043e79c(int player_id,int card_slot,int event_type)

{
  short len_1;
  char cVar2;
  char cVar3;
  short sVar4;
  int32_t uval_5;
  int val_6;
  
  if (arg_3 == 0x74) {
    uval_5 = 1;
  }
  else if (arg_3 == 0x73) {
    val_6 = Glue_Subsystem_004e6978(player,card_slot);
    if ((val_6 != 0) && (val_6 = FUN_0040dcca(player,card_slot,7,5), val_6 != 0)) {
      if ((player == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
      }
      return 1;
    }
    uval_5 = 0;
  }
  else {
    if ((((arg_3 == 0x6d) && (val_6 = FUN_0040dcca(player,card_slot,7,5), val_6 != 0)) &&
        (Ai_Subsystem_004be192(player,card_slot,0,5), g_ActivePlayer != 1)) && (0 < DAT_006ff550)) {
      DAT_006ff550 = DAT_006ff550 + -1;
    }
    if (arg_3 == 0x72) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x26);
      }
      val_6 = Pic_Subsystem_0045268f(900);
      val_6 = Deck_AddCardToDeck(player,val_6);
      if (val_6 != -1) {
        Pic_Subsystem_0042ac1f(player,val_6);
        cVar2 = Card_SetTapState(player,card_slot,1);
        (&g_CardSlot_MinusOneCounters)[val_6 * 0x120 + player * 0x5b20] = (char)(2 << (cVar2 - 1U & 0x1f));
        *(uint32_t *)(&g_CardSlot_Abilities1 + val_6 * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + val_6 * 0x120 + player * 0x5b20) | 0x10;
        if (((&g_CardSlot_Abilities1)[player * 0x5b20 + card_slot * 0x120] & 2) != 0) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_6 * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_6 * 0x120 + player * 0x5b20) | 2;
          (&DAT_006a6030)[val_6 * 0x120 + player * 0x5b20] =
               (&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120];
        }
        *(int32_t *)(&DAT_006a5f74 + val_6 * 0x120 + player * 0x5b20) =
             *(int32_t *)
              (&g_MasterCardTypeTable +
              *(int *)(&g_ActiveCardsInPlay + player * 0x5b20 + card_slot * 0x120) * 0x34);
        len_1 = *(short *)(&g_CardSlot_PowerCounters + val_6 * 0x120 + player * 0x5b20);
        sVar4 = Util_GetRandomNumber(3);
        *(short *)(&g_CardSlot_PowerCounters + val_6 * 0x120 + player * 0x5b20) = len_1 + sVar4;
        len_1 = *(short *)(&g_CardSlot_ToughnessCounters + val_6 * 0x120 + player * 0x5b20);
        sVar4 = Util_GetRandomNumber(3);
        *(short *)(&g_CardSlot_ToughnessCounters + val_6 * 0x120 + player * 0x5b20) = len_1 + sVar4;
        Glue_Subsystem_004e676b(g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
    }
    if (((arg_3 == 0x77) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0)
        ) && ((((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] &
               0x20) == 0 &&
              (((&g_CardSlot_CardTypeIndex)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] !=
                '\x04' &&
               (cVar2 = (&g_CardSlot_MinusOneCounters)
                        [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120],
               cVar3 = Card_SetTapState(player,card_slot,1), (2 << (cVar3 - 1U & 0x1f) & (int)cVar2) == 0))))
             )) {
      Glue_Subsystem_004e66b3(player,card_slot);
    }
    uval_5 = 0;
  }
  return uval_5;
}



/*
 * Decompiled function: CardScript_Regeneration
 * Entry Point: 0043ebbf
 * Size: 1503 bytes
 */


int32_t CardScript_Regeneration(int spell_id,int target_id,int flags)

{
  uint8_t flag_1;
  char cVar2;
  int32_t uval_3;
  int val_4;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (flags == 1) {
    *(int *)(&DAT_006ff69c + spell_id * 0x20) = *(int *)(&DAT_006ff69c + spell_id * 0x20) + 2;
  }
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
    uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_005218d8,s_REGENERATION_005218c8);
      val_4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_4 == 0);
      if (((g_ActivePlayer != 1) && (spell_id == g_ActivePlayerPriority)) &&
         ((((&DAT_006a5f6d)
            [*(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
             *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] &
           2) != 0 ||
          (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
           g_CurrentTurnPhase)))) {
        g_SpellStackDepth = g_SpellStackDepth + -0x30;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x73) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
      flag_1 = (&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
      cVar2 = (&g_CardSlot_CardTypeIndex)
              [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
      val_4 = FUN_0040dcca(spell_id,target_id,3,1);
      if (val_4 == 0 || (cVar2 != '\x02' || (flag_1 & 2) == 0)) {
        uval_3 = 0;
      }
      else {
        uval_3 = 99;
      }
    }
    else if (flags == 0x90) {
      Ai_GetOpponentPlayerScore(0);
      uval_3 = 0;
    }
    else {
      if (((flags == 0x6d) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,3,1), g_ActivePlayer != 1)) {
        DAT_00695df8 = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) + 1;
      }
      if ((flags == 0x72) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
        *(int32_t *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
         *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) = 0;
        Glue_Subsystem_004d7e90
                  ((int)(char)(&g_CardSlot_Toughness)
                              [*(int *)(&g_CardSlot_SicknessState +
                                       spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                               *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120
                                       ) * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId +
                           *(int *)(&g_CardSlot_SicknessState +
                                   spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20));
      }
      uval_3 = 0;
    }
  }
  return uval_3;
}



/*
 * Decompiled function: CardScript_EternalWarrior
 * Entry Point: 0043f19e
 * Size: 895 bytes
 */


int32_t CardScript_EternalWarrior(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005218f4,s_ETERNAL_WARRIOR_005218e4);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint32_t)(val_2 == 0);
      if (((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) &&
         ((val_2 = Rules_ValidateCardTargetSlot(*(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20),
                                *(int *)(&g_CardSlot_AttachedAura +
                                        target_id * 0x120 + spell_id * 0x5b20)), val_2 != 0 ||
          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
           g_CurrentTurnPhase)))) {
        g_SpellStackDepth = g_SpellStackDepth + -0x30;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
      *(uint32_t *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) | 0x2000;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_TheBrute
 * Entry Point: 0043f51d
 * Size: 1498 bytes
 */


int32_t CardScript_TheBrute(int spell_id,int target_id,int flags)

{
  uint8_t flag_1;
  char cVar2;
  int32_t uval_3;
  int val_4;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  
  if (flags == 1) {
    *(int *)(&DAT_006ff6a0 + spell_id * 0x20) = *(int *)(&DAT_006ff6a0 + spell_id * 0x20) + 2;
  }
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uval_3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052190c,s_THE_BRUTE_00521900);
      val_4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x73) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      flag_1 = (&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      cVar2 = (&g_CardSlot_CardTypeIndex)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      val_4 = FUN_0040dcca(spell_id,target_id,4,3);
      if (val_4 == 0 || (cVar2 != '\x02' || (flag_1 & 2) == 0)) {
        uval_3 = 0;
      }
      else {
        uval_3 = 99;
      }
    }
    else if (flags == 0x90) {
      Ai_GetOpponentPlayerScore(0);
      uval_3 = 0;
    }
    else {
      if (((flags == 0x6d) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,4,3), g_ActivePlayer != 1)) {
        DAT_00695df8 = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
      }
      if ((flags == 0x72) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
        *(int32_t *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) = 0;
        Glue_Subsystem_004d7e90
                  ((int)(char)(&g_CardSlot_Toughness)
                              [*(int *)(&g_CardSlot_SicknessState +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                               *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId +
                           *(int *)(&g_CardSlot_SicknessState +
                                   target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                           0x5b20));
      }
      if ((((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
             g_OverworldMapGrid) &&
           ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) &&
         ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
          (flags == 0x32)))) {
        g_ActivePalette = g_ActivePalette + 1;
      }
      uval_3 = 0;
    }
  }
  return uval_3;
}



/*
 * Decompiled function: CardScript_Earthbind
 * Entry Point: 0043faf7
 * Size: 639 bytes
 */


uint32_t CardScript_Earthbind(int spell_id,int target_id,int flags)

{
  uint32_t uval_1;
  int val_2;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      uval_1 = (g_PlayerPoisonCounters | DAT_006a282c) & 2;
    }
    else {
      uval_1 = (&g_PlayerPoisonCounters)[g_CurrentTurnPhase] & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521924,s_EARTH_BIND_00521918);
    }
    val_2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
    g_ActivePlayer = (uint32_t)(val_2 == 0);
    if ((flags == 0x71) &&
       (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      uval_1 = Card_TapForMana((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(int *)(&g_CardSlot_OriginalCardId +
                                    target_id * 0x120 + spell_id * 0x5b20),0x34,0xffffffff);
      if ((uval_1 & 0x20) != 0) {
        Card_ApplyCombatDamage((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),2,
                     spell_id,target_id);
      }
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && ((g_OverworldMapGrid != -1 && (flags == 0x34)))))) {
      g_ActivePalette = g_ActivePalette & 0xffffffdf;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0043fd7b
 * Entry Point: 0043fd7b
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fd7b(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,1);
  CardScript_CircleOfProtection(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fdb2
 * Entry Point: 0043fdb2
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fdb2(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player, card_slot, 5);
  CardScript_CircleOfProtection(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fde9
 * Entry Point: 0043fde9
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fde9(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,4);
  CardScript_CircleOfProtection(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fe20
 * Entry Point: 0043fe20
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fe20(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,2);
  CardScript_CircleOfProtection(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fe57
 * Entry Point: 0043fe57
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fe57(int player_id,int card_slot,int event_type)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,3);
  CardScript_CircleOfProtection(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: CardScript_CircleOfProtection
 * Entry Point: 0043fe8e
 * Size: 1014 bytes
 */


int32_t CardScript_CircleOfProtection(int spell_id,int target_id,int flags,int height)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int32_t slot_idx;
  
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       (val_2 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       val_2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&g_AiCombatScore_Attacker + height * 4 + g_CurrentTurnPhase * 0x20) +
           *(int *)(&DAT_006b2e40 + height * 4 + g_CurrentTurnPhase * 0x20) / 2) * 0x18;
    }
    if (flags == 0x73) {
      if (((((uint8_t)g_PlayerHandCardCount & 4) == 0) ||
          (val_2 = FUN_0040dcca(spell_id,target_id,7,1), val_2 == 0)) ||
         (val_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((uint8_t)height & 0x1f),0,
                               g_PendingSpellTargetSlot,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), val_2 == 0))
      {
        uval_1 = 0;
      }
      else {
        uval_1 = 99;
      }
    }
    else {
      if (((flags == 0x6d) &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,0,1), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_00521948,s_CIRCLE_OF_PROTECTION_00521930);
        val_2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((uint8_t)height & 0x1f),0,g_PendingSpellTargetSlot,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&match_count);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               slot_idx;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        val_2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,0,
                           1 << ((uint8_t)height & 0x1f),0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0x20,0
                           ,0);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) != 0) {
          *(int32_t *)
           (&g_CardSlot_ConvertedManaCost +
           *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_CircleOfProtection
 * Entry Point: 00440289
 * Size: 1027 bytes
 */


int32_t CardScript_CircleOfProtection(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = 6;
  if (flags == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       (val_2 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       val_2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee48 + g_CurrentTurnPhase * 0x20) +
            *(int *)(&DAT_006b2e40 + g_CurrentTurnPhase * 0x20) / 2 +
           *(int *)(&g_PlayerManaPoolDelta + g_CurrentTurnPhase * 0x20)) * 0x18;
    }
    if (flags == 0x73) {
      if ((((uint8_t)g_PlayerHandCardCount & 4) != 0) &&
         (val_2 = FUN_0040dcca(spell_id,target_id,7,2), val_2 != 0)) {
        val_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((uint8_t)slot_idx & 0x1f),0,
                             g_PendingSpellTargetSlot,0xffffffff,0xffffffff,0xffffffff,0x20,0,0);
        if (val_2 != 0) {
          return 99;
        }
      }
      uval_1 = 0;
    }
    else {
      if (((flags == 0x6d) &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,0,2), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_0052196c,s_CIRCLE_OF_PROTECTION_00521954);
        val_2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((uint8_t)slot_idx & 0x1f),0,g_PendingSpellTargetSlot,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&card_idx);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
          *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               match_count;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        val_2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,0,
                           1 << ((uint8_t)slot_idx & 0x1f),0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0x20,
                           0,0);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) != 0) {
          *(int32_t *)
           (&g_CardSlot_ConvertedManaCost +
           *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_PhantasmalTerrain
 * Entry Point: 0044068c
 * Size: 1213 bytes
 */


int32_t CardScript_PhantasmalTerrain(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
  int match_count;
  int slot_idx;
  
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
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052198c,s_PHANTASMAL_TERRAIN_00521978);
      val_2 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (g_CurrentTurnPhase == spell_id) {
          if (spell_id == 1) {
            match_count = Util_GetRandomNumber(5);
            match_count = match_count + 1;
          }
          else {
            match_count = -1;
          }
          slot_idx = Ai_Subsystem_004cc93d(spell_id,s_Land_type__00521998,0,match_count,0x3e);
          if (slot_idx == -1) {
            g_ActivePlayer = 1;
          }
        }
        else if (g_IsAiThinking == 1) {
          slot_idx = Util_GetRandomNumber(5);
          slot_idx = slot_idx + 1;
          g_AiDecisionScore = slot_idx;
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
          slot_idx = g_AiDecisionScore;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == spell_id)
        {
          g_SpellStackDepth = g_SpellStackDepth + -0x30;
        }
        *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) + -1;
        *(int32_t *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
        *(uint32_t *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x1000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
        ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_OverworldMapGrid &&
         (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) &&
       (val_2 = Card_IsTapped(spell_id,target_id), val_2 != 0)) {
      g_ActivePalette =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00440b49
 * Entry Point: 00440b49
 * Size: 620 bytes
 */


int32_t Pic_Subsystem_00440b49(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (g_OverworldMapGrid == card_slot)) &&
       (g_OverworldPlayerCoordX == player)) {
      val_2 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1);
      if (val_2 == 0) {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_006b2e54 + g_ActivePlayerPriority * 0x20) -
             *(int *)(&DAT_006b2e54 + g_CurrentTurnPhase * 0x20)) * 0xc;
      }
    }
    if (arg_3 == 0x71) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 5;
    }
    if (((arg_3 == 0x85) && (g_OverworldMapGrid == card_slot)) &&
       ((g_OverworldPlayerCoordX == player &&
        ((g_DefendingPlayer == player && (g_DefendingPlayer == g_CurrentTurnTargetPlayer)))))) {
      *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
      (&DAT_006a604d)[card_slot * 0x120 + player * 0x5b20] =
           (&DAT_006a604d)[card_slot * 0x120 + player * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if ((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) {
      val_2 = Card_IsTapped(player,card_slot);
      if (val_2 != 0) {
        val_2 = Card_IsTapped(g_OverworldPlayerCoordX,g_OverworldMapGrid);
        if (val_2 != 0) {
          val_2 = Card_UntapCard(player,card_slot,4);
          if (*(int *)(&DAT_006ff2bc + val_2 * 4) ==
              *(int *)(&g_MasterCardTypeTable + g_ActivePalette * 0x34)) {
            val_2 = Card_UntapCard(player,card_slot,
                                 *(int *)(&g_CardSlot_ConvertedManaCost +
                                         card_slot * 0x120 + player * 0x5b20));
            g_ActivePalette = val_2 + -1;
          }
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_WildGrowth
 * Entry Point: 00440db5
 * Size: 946 bytes
 */


int32_t CardScript_WildGrowth(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005219b0,s_WILD_GROWTH_005219a4);
      val_2 = Glue_Subsystem_004e6dcc(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
               g_ActivePlayerPriority) {
        g_SpellStackDepth =
             g_SpellStackDepth + *(int *)(&DAT_006b2e4c + g_ActivePlayerPriority * 0x20) * 0xc;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && ((g_OverworldMapGrid != -1 && (g_PendingAttackersTargetSlot != -1)))))) {
      FUN_0040d875((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],3,1);
    }
    if ((((flags == 0x7f) &&
         (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_OverworldMapGrid)) &&
        ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 0x10)
         == 0)))) {
      FUN_0040d7e9(g_OverworldPlayerCoordX,3,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Flight
 * Entry Point: 00441167
 * Size: 885 bytes
 */


int32_t CardScript_Flight(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
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
    Ai_GetOpponentPlayerScore(0);
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
    uval_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005219c4,s_FLIGHT_005219bc);
      val_2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + -0x18;
        }
        if (((&g_CardSlot_Abilities2)
             [*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] &
            0x20) != 0) {
          g_SpellStackDepth = g_SpellStackDepth + -99;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0) &&
        (*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       ((*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldPlayerCoordX && ((g_OverworldMapGrid != -1 && (flags == 0x34)))))) {
      g_ActivePalette = g_ActivePalette | 0x20;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004414dc
 * Entry Point: 004414dc
 * Size: 686 bytes
 */


int32_t Pic_Subsystem_004414dc(int player_id,int card_slot,int event_type)

{
  uint8_t flag_1;
  int32_t uval_2;
  int val_3;
  uint32_t uval_4;
  int val_5;
  uint32_t uval_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee34)[(1 - player) * 8] * 5 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (g_SelectedTargetPlayer == -1) {
        uval_2 = 0;
      }
      else {
        if ((((uint8_t)g_PlayerHandCardCount & 0x20) != 0) &&
           (val_3 = FUN_0040dcca(player,card_slot,3,2), val_3 != 0)) {
          uVar10 = 0;
          uVar9 = 0;
          uval_8 = 2;
          uval_7 = 0xffffffff;
          uval_6 = 0xffffffff;
          val_5 = -1;
          val_3 = -1;
          uval_4 = 0;
          flag_1 = Card_SetTapState(player,card_slot,1);
          val_3 = Rules_ParseFilter_0040360b
                            (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,player,2,2,0,0,0,0,0,
                             1 << (flag_1 & 0x1f),uval_4,val_3,val_5,uval_6,uval_7,uval_8,uVar9,uVar10);
          if (val_3 != 0) {
            return 99;
          }
        }
        uval_2 = 0;
      }
    }
    else {
      if (((arg_3 == 0x6d) && (val_3 = FUN_0040dcca(player,card_slot,3,2), val_3 != 0)) &&
         ((g_SelectedTargetPlayer != -1 && (Ai_Subsystem_004be192(player,card_slot,3,2), g_ActivePlayer != 1)))) {
        *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) = g_SelectedTargetSlot;
      }
      if (arg_3 == 0x72) {
        uVar10 = 0;
        uVar9 = 0;
        uval_8 = 2;
        uval_7 = 0xffffffff;
        uval_6 = 0xffffffff;
        val_5 = -1;
        val_3 = -1;
        uval_4 = 0;
        flag_1 = Card_SetTapState(player,card_slot,1);
        val_3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                           (char *)0x0,player,2,2,0,0,0,0,0,1 << (flag_1 & 0x1f),uval_4,val_3,val_5,
                           uval_6,uval_7,uval_8,uVar9,uVar10);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),1);
        }
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_0044178f
 * Entry Point: 0044178f
 * Size: 686 bytes
 */


int32_t Pic_Subsystem_0044178f(int player_id,int card_slot,int event_type)

{
  uint8_t flag_1;
  int32_t uval_2;
  int val_3;
  uint32_t uval_4;
  int val_5;
  uint32_t uval_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  if (arg_3 == 0x74) {
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth + *(int *)(&DAT_0063ee3c + (1 - player) * 0x20) * 5 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (g_SelectedTargetPlayer == -1) {
        uval_2 = 0;
      }
      else {
        if ((((uint8_t)g_PlayerHandCardCount & 0x20) != 0) &&
           (val_3 = FUN_0040dcca(player,card_slot,1,2), val_3 != 0)) {
          uVar10 = 0;
          uVar9 = 0;
          uval_8 = 2;
          uval_7 = 0xffffffff;
          uval_6 = 0xffffffff;
          val_5 = -1;
          val_3 = -1;
          uval_4 = 0;
          flag_1 = Card_SetTapState(player,card_slot,3);
          val_3 = Rules_ParseFilter_0040360b
                            (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,player,2,2,0,0,0,0,0,
                             1 << (flag_1 & 0x1f),uval_4,val_3,val_5,uval_6,uval_7,uval_8,uVar9,uVar10);
          if (val_3 != 0) {
            return 99;
          }
        }
        uval_2 = 0;
      }
    }
    else {
      if (((arg_3 == 0x6d) && (val_3 = FUN_0040dcca(player,card_slot,1,2), val_3 != 0)) &&
         ((g_SelectedTargetPlayer != -1 && (Ai_Subsystem_004be192(player,card_slot,1,2), g_ActivePlayer != 1)))) {
        *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) = g_SelectedTargetSlot;
      }
      if (arg_3 == 0x72) {
        uVar10 = 0;
        uVar9 = 0;
        uval_8 = 2;
        uval_7 = 0xffffffff;
        uval_6 = 0xffffffff;
        val_5 = -1;
        val_3 = -1;
        uval_4 = 0;
        flag_1 = Card_SetTapState(player,card_slot,3);
        val_3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                           (char *)0x0,player,2,2,0,0,0,0,0,1 << (flag_1 & 0x1f),uval_4,val_3,val_5,
                           uval_6,uval_7,uval_8,uVar9,uVar10);
        if (val_3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),1);
        }
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_00441a42
 * Entry Point: 00441a42
 * Size: 1480 bytes
 */


int Pic_Subsystem_00441a42(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  int aiStack_5a0 [50];
  int local_4d8;
  int aiStack_4d4 [50];
  int aiStack_40c [50];
  uint8_t abStack_344 [200];
  int local_27c;
  int local_278;
  int local_274;
  int aiStack_270 [50];
  int local_1a8;
  int aiStack_1a4 [50];
  int local_dc;
  int aiStack_d8 [50];
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg1 == -1) {
    slot_idx = -1;
  }
  else if (arg2 == 1) {
    slot_idx = -1;
    match_count = -10;
    local_1a8 = 0;
    for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[arg1]; card_idx = card_idx + 1) {
      local_dc = *(int *)(&g_CardSlot_CardId + card_idx * 0x120 + arg1 * 0x5b20);
      if (((local_dc != -1) && (((&g_CardSlot_Flags)[card_idx * 0x120 + arg1 * 0x5b20] & 2) != 0))
         && ((((&g_MasterCardColorTable)[local_dc * 0x34] & 1) != 0 &&
             (((&g_CardSlot_Flags)[card_idx * 0x120 + arg1 * 0x5b20] & 0x10) != 0)))) {
        aiStack_d8[local_1a8] = card_idx;
        aiStack_1a4[local_1a8] = 0;
        local_1a8 = local_1a8 + 1;
      }
    }
    for (card_idx = 0; card_idx < local_1a8; card_idx = card_idx + 1) {
      if (((&g_MasterCardSubtypeTable)
           [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + aiStack_d8[card_idx] * 0x120) * 0x34] & 1)
          != 0) {
        aiStack_1a4[card_idx] = aiStack_1a4[card_idx] + 1;
      }
      if (((&g_CardSlot_Subtypes)[card_idx * 0x120 + arg1 * 0x5b20] & 4) != 0) {
        aiStack_1a4[card_idx] = -1;
      }
    }
    for (card_idx = 0; card_idx < local_1a8; card_idx = card_idx + 1) {
      if (match_count < aiStack_1a4[card_idx]) {
        match_count = aiStack_1a4[card_idx];
        slot_idx = aiStack_d8[card_idx];
      }
    }
  }
  else if (arg2 == 2) {
    slot_idx = -1;
    match_count = -1;
    local_274 = 0;
    local_278 = 0;
    local_4d8 = 0;
    for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[arg1]; card_idx = card_idx + 1) {
      local_27c = *(int *)(&g_CardSlot_CardId + card_idx * 0x120 + arg1 * 0x5b20);
      if ((((local_27c != -1) && (((&g_CardSlot_Flags)[card_idx * 0x120 + arg1 * 0x5b20] & 2) != 0))
          && (((&g_MasterCardColorTable)[local_27c * 0x34] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[card_idx * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
        aiStack_270[local_4d8] = card_idx;
        val_1 = Card_TapForMana(arg1,card_idx,0x32,0xffffffff);
        aiStack_4d4[local_4d8] = val_1;
        if (local_274 < aiStack_4d4[local_4d8]) {
          local_274 = aiStack_4d4[local_4d8];
        }
        val_1 = Card_TapForMana(arg1,card_idx,0x33,0xffffffff);
        aiStack_5a0[local_4d8] = val_1;
        if (local_278 < aiStack_5a0[local_4d8]) {
          local_278 = aiStack_5a0[local_4d8];
        }
        uval_2 = Card_TapForMana(arg1,card_idx,0x34,0xffffffff);
        *(int32_t *)(abStack_344 + local_4d8 * 4) = uval_2;
        aiStack_40c[local_4d8] = 0;
        local_4d8 = local_4d8 + 1;
      }
    }
    for (card_idx = 0; card_idx < local_4d8; card_idx = card_idx + 1) {
      if (aiStack_4d4[card_idx] == local_274) {
        aiStack_40c[card_idx] = aiStack_40c[card_idx] + 3;
      }
      if (aiStack_5a0[card_idx] == local_278) {
        aiStack_40c[card_idx] = aiStack_40c[card_idx] + 2;
      }
      if ((abStack_344[card_idx * 4] & 0x20) != 0) {
        aiStack_40c[card_idx] = aiStack_40c[card_idx] + 1;
      }
      if ((abStack_344[card_idx * 4 + 1] & 1) != 0) {
        aiStack_40c[card_idx] = aiStack_40c[card_idx] + 1;
      }
      while (*(int *)(abStack_344 + card_idx * 4) != 0) {
        if ((abStack_344[card_idx * 4] & 1) != 0) {
          aiStack_40c[card_idx] = aiStack_40c[card_idx] + 1;
        }
        *(int *)(abStack_344 + card_idx * 4) = *(int *)(abStack_344 + card_idx * 4) >> 1;
      }
      if (((&g_MasterCardFlagsTable)
           [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + aiStack_270[card_idx] * 0x120) * 0x34] &
          0x10) != 0) {
        aiStack_40c[card_idx] = aiStack_40c[card_idx] + 1;
      }
      if (((&g_MasterCardSubtypeTable)
           [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + aiStack_270[card_idx] * 0x120) * 0x34] & 1
          ) != 0) {
        aiStack_40c[card_idx] = aiStack_40c[card_idx] + 1;
      }
    }
    for (card_idx = 0; card_idx < local_4d8; card_idx = card_idx + 1) {
      if (match_count < aiStack_40c[card_idx]) {
        match_count = aiStack_40c[card_idx];
        slot_idx = aiStack_270[card_idx];
      }
    }
  }
  else {
    slot_idx = -1;
  }
  return slot_idx;
}



/*
 * Decompiled function: UI_RegisterClass_00442010
 * Entry Point: 00442010
 * Size: 145 bytes
 */


bool UI_RegisterClass_00442010(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x20;
  local_2c.lpfnWndProc = Catalog_LoadAllBigCardArtPics;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA(g_AppHInstance,(LPCSTR)0x66);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}



/*
 * Decompiled function: Catalog_LoadAllBigCardArtPics
 * Entry Point: 004420a1
 * Size: 6620 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t Catalog_LoadAllBigCardArtPics(HWND hwnd,uint32_t y,void *arg_3,int *height)

{
  POINT Point;
  DWORD _Seed;
  int32_t uval_1;
  int val_2;
  int val_3;
  BOOL BVar4;
  uint32_t uval_5;
  HDC *arg_3_00;
  BITMAPINFO *arg_4;
  HGDIOBJ *arg_5;
  int32_t *arg_6;
  int *arg_7;
  int local_630;
  char local_62c [264];
  char local_524 [500];
  char local_330 [52];
  int local_2fc;
  int32_t local_2f8;
  int local_2f4;
  int local_2f0;
  uint32_t local_2ec;
  DWORD local_2e8;
  int local_2e4;
  int local_2e0;
  int local_2dc;
  int local_2d8;
  char local_2d4 [260];
  char local_1d0 [260];
  WPARAM local_cc;
  int local_c8;
  int local_c4;
  char local_c0 [100];
  int local_5c;
  void *local_58;
  int *local_54;
  int local_50;
  int local_4c;
  tagPOINT local_48;
  uint32_t local_40;
  HWND local_3c;
  void *local_38;
  tagMSG local_34;
  DWORD target_idx;
  int *player_idx;
  BOOL card_idx;
  uint32_t match_count;
  int slot_idx;
  
  if (y < 0x11) {
    if (y == 0x10) {
      DAT_0067f3c4 = 1;
      g_PlayerCreatureCount = 0;
      return 0;
    }
    if (y == 1) {
      DAT_006fe484 = (HANDLE)0x0;
      val_2 = Pic_Clip_00443b63(hwnd);
      if (val_2 == 0) {
        return 0xffffffff;
      }
      PostMessageA(hwnd,0x400,0,0);
      DAT_006a49e4 = CreateWindowExA(0,s_MAGIC_PaletteClass_00521b20,s_Palette_00521b18,0x80cc0000,
                                     0x14,0x14,300,0x15e,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0)
      ;
      DAT_006fdbd4 = (void *)0x14;
      DAT_006ff1a8 = (HWND)0x0;
      return 0;
    }
    if (y == 2) {
      strcpy(local_62c,&g_GameInstallDirectory);
      strcat(local_62c,s__duel_hlp_00521b34);
      WinHelpA(g_MainAppHwnd,local_62c,2,0);
      KillTimer(hwnd,(UINT_PTR)DAT_006fdbd4);
      return 0;
    }
    if (y == 5) {
      if ((arg_3 == (void *)0x0) && (DAT_005219d4 == 0)) {
        LockWindowUpdate(hwnd);
        Pic_Subsystem_004441cc(hwnd,g_DuelArenaStatusFlags);
        Glue_Subsystem_004eee4e(g_TurnPriorityState);
        Glue_Subsystem_004eee4e(g_AiSelectedActionCode);
        LockWindowUpdate((HWND)0x0);
      }
      if (arg_3 == (void *)0x1) {
        DAT_005219d4 = 1;
      }
      else if (arg_3 == (void *)0x0) {
        DAT_005219d4 = 0;
      }
      if ((arg_3 == (void *)0x1) && (_hwndScreen != (HWND)0x0)) {
        ShowWindow(_hwndScreen,5);
      }
      return 0;
    }
  }
  else if (y < 0x7f) {
    if (y == 0x7e) {
      if (DAT_006ff554 != arg_3) {
        for (local_630 = 0; local_630 < g_CardsDatLoadedHandle; local_630 = local_630 + 1) {
          FUN_0046c1b3(local_630);
        }
        for (local_630 = 0; local_630 < DAT_00680778; local_630 = local_630 + 1) {
          FUN_004788e0((&DAT_006fefc0)[local_630 * 6],(&DAT_006fefc4)[local_630 * 6]);
        }
        DAT_00680778 = 0;
      }
      DAT_006ff554 = arg_3;
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      FUN_004f3b2c(g_HdcBackBuffer,DAT_006ff384);
      arg_7 = &DAT_006b2e1c;
      arg_6 = (int32_t *)&DAT_007006dc;
      arg_5 = &DAT_006ff384;
      arg_4 = (BITMAPINFO *)&DAT_006a4a20;
      arg_3_00 = &g_HdcBackBuffer;
      val_2 = GetSystemMetrics(1);
      val_3 = GetSystemMetrics(0);
      val_2 = FUN_004f39a4(val_3,val_2,arg_3_00,arg_4,arg_5,arg_6,arg_7);
      if (val_2 == 0) {
        MessageBoxA(hwnd,s_Not_enough_system_memory_to_run_a_00521b58,
                    s_Magic__The_Gathering_00521b40,0x30);
        ShowWindow(hwnd,0);
      }
      else {
        ShowWindow(hwnd,5);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      BVar4 = IsIconic(hwnd);
      if (BVar4 == 0) {
        MoveWindow(hwnd,1,0,((uint32_t)height & 0xffff) - 1,(uint32_t)height >> 0x10,1);
      }
      else {
        DAT_005219d0 = 1;
      }
      return 0;
    }
    if (y == 0x13) {
      if (DAT_005219d0 != 0) {
        PostMessageA(hwnd,0x501,0,0);
      }
      if (_hwndScreen != (HWND)0x0) {
        ShowWindow(_hwndScreen,5);
      }
      return 1;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      uval_5 = GDI_RealizePaletteTree_Magic(hwnd,y,arg_3,height);
      return uval_5;
    }
    if (y == 0x111) {
      switch((uint32_t)arg_3 & 0xffff) {
      case 599:
        DAT_0068a718 = (uint32_t)(DAT_0068a718 == 0);
        if (DAT_006b2d38 == 0) {
          DAT_0068a718 = 0;
        }
        break;
      case 0x25c:
        if (DAT_0068a718 != 0) {
          DAT_00695e90 = (uint32_t)(DAT_00695e90 == 0);
          Pic_Subsystem_0044cfe4(g_AiDuelTurnState);
        }
        break;
      case 0x25d:
        if (DAT_0068a718 != 0) {
          UI_RenderOpponentLibraryPrompt(DAT_0052eff8);
        }
        break;
      case 0x25e:
        if (DAT_0068a718 != 0) {
          UI_RenderPlayerLibraryPrompt(DAT_0052eff8);
        }
        break;
      case 0x263:
        if (DAT_0068a718 != 0) {
          g_PlayerCreatureCount = 0;
          g_PlayerDeckCardCount = 0;
          SendMessageA(DAT_006b2530,0x432,0,0);
          SendMessageA(DAT_006ff4a8,0x432,0,0);
        }
        break;
      case 0x267:
      case 0x268:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint32_t)(((uint32_t)arg_3 & 0xffff) == 0x267);
          (&g_PlayerCreatureCount)[local_2ec] = 0;
          SendMessageA(DAT_006b2530,0x432,0,0);
          SendMessageA(DAT_006ff4a8,0x432,0,0);
        }
        break;
      case 0x269:
      case 0x26a:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint32_t)(((uint32_t)arg_3 & 0xffff) != 0x269);
          Magic_ExecuteDrawPhase(local_2ec);
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26b:
      case 0x26c:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint32_t)(((uint32_t)arg_3 & 0xffff) != 0x26b);
          local_2f0 = Palette_Subsystem_004a62a0(s_Pick_a_card_to_put_into_play_00521a60,-1,-1);
          local_2f8 = *(int32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98)
          ;
          *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
               *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) & 0xfffe;
          local_2f4 = Deck_AddCardToDeck(local_2ec,local_2f0);
          if (local_2f4 != -1) {
            Pic_Subsystem_0042ac1f(local_2ec,local_2f4);
          }
          *(int32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) = local_2f8
          ;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26d:
      case 0x26e:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint32_t)(((uint32_t)arg_3 & 0xffff) != 0x26d);
          local_2f0 = Palette_Subsystem_004a62a0(s_Pick_a_card_to_put_into_hand_00521a80,-1,-1);
          local_2f4 = Deck_AddCardToDeck(local_2ec,local_2f0);
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26f:
      case 0x270:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint32_t)(((uint32_t)arg_3 & 0xffff) != 0x26f);
          uval_1 = Ai_Subsystem_004b1b38
                            (0,s_Set_player_lives_to__00521aa0 + ((local_2ec == 0) - 1 & 0x18),
                             (&g_PlayerCreatureCount)[local_2ec]);
          (&g_PlayerCreatureCount)[local_2ec] = uval_1;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x271:
        if (DAT_0068a718 != 0) {
          ShowWindow(DAT_006a49e4,5);
        }
        break;
      case 0x272:
        if (DAT_0068a718 != 0) {
          DAT_006808c4 = (uint32_t)(DAT_006808c4 == 0);
          SendMessageA(g_TurnPriorityState,0x435,0,0);
          SendMessageA(g_AiSelectedActionCode,0x435,0,0);
          SendMessageA(g_AiLookaheadTreeRoot,0x435,0,0);
          SendMessageA(g_AiDuelTurnState,0x435,0,0);
          InvalidateRect(DAT_006fe48c,(RECT *)0x0,1);
          InvalidateRect(DAT_006ff388,(RECT *)0x0,1);
        }
        break;
      case 0x273:
        if (DAT_0068a718 != 0) {
          DAT_00695ea4 = (uint32_t)(DAT_00695ea4 == 0);
          SendMessageA(g_TurnPriorityState,0x435,0,0);
          SendMessageA(g_AiSelectedActionCode,0x435,0,0);
          SendMessageA(g_AiLookaheadTreeRoot,0x435,0,0);
          SendMessageA(g_AiDuelTurnState,0x435,0,0);
          InvalidateRect(DAT_0069f744,(RECT *)0x0,0);
        }
        break;
      case 0x274:
        if (DAT_0068a718 != 0) {
          g_AiTurnDecisionFlag = 0;
        }
        break;
      case 0x275:
        if (DAT_0068a718 != 0) {
          sprintf(local_524,s__d_big_arts_are_in__max_is__d__00521ad0,DAT_00680778,0x14);
          for (local_2fc = 0; local_2fc < DAT_00680778; local_2fc = local_2fc + 1) {
            sprintf(local_330,s__3d__d___dx_d_00521af0,(&DAT_006fefc0)[local_2fc * 6],
                    (&DAT_006fefc4)[local_2fc * 6],*(int32_t *)(&DAT_006fefb8 + local_2fc * 0x18)
                    ,*(int32_t *)(&DAT_006fefbc + local_2fc * 0x18));
            strcat(local_524,local_330);
          }
          MessageBoxA(hwnd,local_524,s_These_big_arts_are_in__00521b00,0);
        }
        break;
      case 0x276:
        if (DAT_0068a718 != 0) {
          if (DAT_0068a674 == 0) {
            DAT_0068a674 = 1;
          }
          else {
            DAT_0068a674 = 0;
          }
        }
        break;
      case 0x277:
        if (DAT_0068a718 != 0) {
          BVar4 = IsWindowVisible(DAT_0064a0bc);
          ShowWindow(DAT_0064a0bc,-(uint32_t)(BVar4 == 0) & 5);
        }
        break;
      case 0x279:
        DAT_006fe438 = (uint32_t)(DAT_006fe438 == 0);
        SendMessageA(g_TurnPriorityState,0x435,0,0);
        SendMessageA(g_AiSelectedActionCode,0x435,0,0);
        SendMessageA(g_AiDecisionMatrix_Row,0x435,0,0);
        SendMessageA(DAT_006fe3fc,0x435,0,0);
        break;
      case 0x27a:
        DAT_006fe43c = (uint32_t)(DAT_006fe43c == 0);
        Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        break;
      case 0x27b:
        _DAT_006a2864 = g_MainAppHwnd;
        _DAT_006a2890 = s_Save_Game_00521a54;
        _DAT_006a2894 = 0x2a000c;
        BVar4 = GetSaveFileNameA((LPOPENFILENAMEA)&DAT_006a2860);
        if (BVar4 != 0) {
          Pic_Subsystem_0044ef03(DAT_006a287c);
        }
        break;
      case 0x27c:
        DAT_006fe440 = (uint32_t)(DAT_006fe440 == 0);
        SendMessageA(g_TurnPriorityState,0x435,0,0);
        SendMessageA(g_AiSelectedActionCode,0x435,0,0);
        SendMessageA(g_AiDecisionMatrix_Row,0x435,0,0);
        SendMessageA(DAT_006fe3fc,0x435,0,0);
      }
      return 0;
    }
    if (y == 0x113) {
      if (((DAT_006fdbd4 == arg_3) && (DAT_006b1578 == 0)) && (DAT_006ff1a8 == (HWND)0x0)) {
        Pic_Subsystem_0044559e();
      }
      return 0;
    }
  }
  else if (y < 0x435) {
    if (0x432 < y) {
      return 0;
    }
    if (y == 0x400) {
      DAT_0067f3c4 = 0;
      if (g_DuelArenaStatusFlags == 2) {
        ShowWindow(DAT_0069f744,0);
      }
      else {
        SendMessageA(DAT_0069f744,0x401,0xffffffff,0);
      }
      SendMessageA(g_AiLookaheadTreeRoot,0x40c,0,0);
      SendMessageA(g_AiDuelTurnState,0x40c,0,0);
      SendMessageA(g_TurnPriorityState,0x40c,0,0);
      SendMessageA(g_AiSelectedActionCode,0x40c,0,0);
      DAT_006808ac = 0xffffffff;
      DAT_006a2834 = 0xffffffff;
      DAT_006a48e0 = 0;
      DAT_0068a678 = 0xffffffff;
      SendMessageA(DAT_006a284c,0x432,0,0);
      ShowWindow(DAT_006a284c,5);
      ShowWindow(DAT_006a283c,0);
      DAT_006ff194 = 0;
      DAT_006a3f7c = 0;
      DAT_007006d8 = 0;
      DAT_00695ed8 = 0;
      SendMessageA(DAT_006b2530,0x432,0,0);
      SendMessageA(DAT_006ff4a8,0x432,0,0);
      for (local_c8 = 0; local_c8 < 7; local_c8 = local_c8 + 1) {
        *(int32_t *)(&DAT_00695ee0 + local_c8 * 4) = 0;
        *(int32_t *)(&DAT_0069f6e0 + local_c8 * 4) =
             *(int32_t *)(&DAT_00695ee0 + local_c8 * 4);
      }
      SendMessageA(g_AiSelectedCardTargetSlot,0x432,0,0);
      SendMessageA(DAT_006ff560,0x432,0,0);
      DAT_006b2e20 = 1;
      DAT_006b2d30 = 1;
      SendMessageA(DAT_006fe48c,0x432,0,0);
      SendMessageA(DAT_006ff388,0x432,0,0);
      DAT_007006b4 = 0;
      DAT_006ff1a0 = 0;
      DAT_006b2d34 = 0;
      DAT_006ff2e4 = 0;
      SendMessageA(DAT_006b2e10,0x432,0,0);
      SendMessageA(DAT_006a4928,0x432,0,0);
      SendMessageA(g_AiDecisionMatrix_Row,0x40c,0,0);
      g_AiCandidateActionCount = 0;
      DAT_006fecc0 = 0xffffffff;
      SendMessageA(DAT_006fe3fc,0x40c,0,0);
      DAT_006b1578 = 0;
      ShowWindow(DAT_006a49f0,0);
      ShowWindow(DAT_0068a620,0);
      UpdateWindow(hwnd);
      SetFocus(hwnd);
      _Seed = GetTickCount();
      srand(_Seed);
      if (g_IsAiThinking == -10) {
        FUN_0048e1bf(DAT_006a287c);
        g_OverworldPlayerDirection = 0;
        DAT_0052eff8 = 1;
      }
      else if (((uint8_t)DAT_006fe410 & 4) == 0) {
        if (((uint8_t)DAT_006fe410 & 1) != 0) {
          DAT_006fe490 = FUN_004f3579(DAT_0052eff8);
          DAT_006a3f60 = FUN_004f3579(g_OverworldPlayerDirection);
        }
      }
      else {
        DAT_006fe490 = FUN_004f3579(DAT_0052eff8);
        DAT_006a3f60 = FUN_004f3579(g_OverworldPlayerDirection);
      }
      if (((uint8_t)DAT_006fe410 & 0x10) == 0) {
        if (((uint8_t)DAT_006fe410 & 1) == 0) {
          if (DAT_006a49e8 == -1) {
            sprintf(local_2d4,s__s__03d_pic_00521a3c,&g_FacesDirectory,_OpponFace);
          }
          else {
            sprintf(local_2d4,s__s__03d_pic_00521a30,&g_FacesDirectory,DAT_006a49e8);
          }
          local_cc = Pic_LoadKimPicture(local_2d4);
          SendMessageA(DAT_006a49f0,0x439,local_cc,0);
          sprintf(local_2d4,s__s__03d_pic_00521a48,&g_FacesDirectory,_PlayerFace);
          local_cc = Pic_LoadKimPicture(local_2d4);
          SendMessageA(DAT_0068a620,0x439,local_cc,0);
        }
        else {
          if (DAT_006a49e8 == -1) {
            local_cc = 0;
          }
          else {
            sprintf(local_1d0,s__s__03d_pic_00521a24,&g_FacesDirectory,DAT_006a49e8);
            local_cc = Pic_LoadKimPicture(local_1d0);
          }
          SendMessageA(DAT_006a49f0,0x439,local_cc,0);
          local_cc = DAT_0067bdd8;
          SendMessageA(DAT_0068a620,0x439,DAT_0067bdd8,1);
        }
      }
      else {
        SendMessageA(DAT_006a49f0,0x439,0,0);
        SendMessageA(DAT_0068a620,0x439,0,0);
      }
      if (((uint8_t)DAT_006fe410 & 0x10) == 0) {
        if (DAT_0068a648 == 0) {
          local_2dc = DAT_006fe490;
          local_2e4 = rand();
          local_2e4 = local_2e4 % 3;
          if (DAT_006fe448 == -1) {
            local_2e0 = DAT_006a3f60;
          }
          else {
            local_2e0 = DAT_006fe448;
          }
          local_2d8 = DAT_006fe44c;
          if ((local_2e0 == local_2dc) && (DAT_006fe44c == local_2e4)) {
            local_2e4 = (local_2e4 + 1) % 3;
          }
          DAT_006a4930 = local_2e4;
        }
        else {
          local_2dc = DAT_006fe490;
          local_2e4 = DAT_006a4930;
          if (DAT_006fe448 == -1) {
            local_2e0 = DAT_006a3f60;
          }
          else {
            local_2e0 = DAT_006fe448;
          }
          local_2d8 = DAT_006fe44c;
        }
      }
      else {
        local_2e0 = 1;
        local_2dc = 1;
        local_2d8 = 2;
        local_2e4 = 2;
      }
      UI_LoadGraveyardBackdrops(1,local_2dc,local_2e4);
      UI_LoadGraveyardBackdrops(0,local_2e0,local_2d8);
      BVar4 = IsWindowVisible(hwnd);
      if (BVar4 == 0) {
        ShowWindow(hwnd,5);
        SetForegroundWindow(hwnd);
        UpdateWindow(hwnd);
        ShowWindow(g_AiLookaheadTreeRoot,5);
        ShowWindow(g_AiDuelTurnState,5);
      }
      if (((uint8_t)DAT_006fe410 & 0x10) == 0) {
        DAT_006fe484 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,Pic_Subsystem_00443b0c,(LPVOID)0x0,
                                    0,&local_2e8);
        SetThreadPriority(DAT_006fe484,0);
      }
      else {
        DAT_006fe484 = (HANDLE)0x0;
        PostMessageA(hwnd,0x401,0,0);
      }
      return 0;
    }
    if (y == 0x401) {
      local_58 = arg_3;
      local_5c = 1;
      if (DAT_006fe484 != (HANDLE)0x0) {
        WaitForSingleObject(DAT_006fe484,0xffffffff);
        CloseHandle(DAT_006fe484);
        DAT_006fe484 = (HANDLE)0x0;
      }
      if (((uint8_t)DAT_006fe410 & 1) == 0) {
        if (((uint8_t)DAT_006fe410 & 2) != 0) {
          local_c4 = 1;
          if (local_58 == (void *)0x1) {
            strcpy(local_c0,s_Congratulations__005219d8);
          }
          else if (local_58 == (void *)0x0) {
            strcpy(local_c0,s_Too_bad_005219ec);
          }
          else if (local_58 == (void *)0xffffffff) {
            strcpy(local_c0,s_Oh_well____005219f4);
          }
          else {
            local_c4 = 0;
          }
          if (local_c4 != 0) {
            strcat(local_c0,s_Want_to_play_again__00521a00);
            val_2 = MessageBoxA(hwnd,local_c0,s_End_of_duel_00521a18,4);
            if (val_2 == 6) {
              local_5c = 0;
              SendMessageA(hwnd,0x400,0,0);
            }
          }
        }
      }
      else if (DAT_006fe434 != 0) {
        Ai_ScoreBoardPermanents((int)local_58);
      }
      if (local_5c != 0) {
        DestroyWindow(hwnd);
        DAT_00627a80 = local_58;
        PostQuitMessage((int)local_58);
      }
      return 0;
    }
    if (y == 0x403) {
      if (DAT_006ff1a8 != (HWND)0x0) {
        SendMessageA(DAT_006ff1a8,0x10,0,0);
      }
      KillTimer(hwnd,(UINT_PTR)DAT_006fdbd4);
      local_38 = arg_3;
      player_idx = height;
      DAT_006b1578 = 1;
      memcpy(&DAT_006feec0,arg_3,0xe8);
      GetCursorPos(&local_48);
      Point.y = local_48.y;
      Point.x = local_48.x;
      local_3c = WindowFromPoint(Point);
      local_40 = SendMessageA(local_3c,0x84,0,local_48.y << 0x10 | local_48.x & 0xffffU);
      SendMessageA(local_3c,0x20,(WPARAM)local_3c,local_40 & 0xffff | 0x2000000);
      UI_ShowDuelArenaWindow(1,*(int *)((int)local_38 + 0xe0));
      UI_ShowDuelArenaWindow(0,*(int *)((int)local_38 + 0xe4));
      FUN_00477d73(DAT_007006b0,(char *)((int)local_38 + 0x18),*(uint32_t *)((int)local_38 + 0x14));
      Ai_Subsystem_004b74b1(&local_4c,&local_50);
      if (((local_50 == 0x15) && (local_4c == 1)) && (val_2 = Ai_Subsystem_004b75a4(), val_2 != 0))
      {
        DAT_0069f6d0 = 1;
      }
      slot_idx = 0;
      while (slot_idx == 0) {
        GetExitCodeThread(DAT_006fe484,&target_idx);
        if (target_idx != 0x103) {
          slot_idx = 1;
        }
        card_idx = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
        if (DAT_0067f3c4 != 0) {
          if ((card_idx != 0) && (local_34.message == 0x464)) {
            card_idx = 0;
          }
          slot_idx = 1;
          *player_idx = -5;
          player_idx[1] = -1;
          player_idx[2] = -1;
          if (*player_idx == 0) {
            match_count = 1;
          }
          else {
            match_count = 0;
          }
        }
        if (card_idx != 0) {
          if (local_34.message == 0x464) {
            local_54 = (int *)local_34.lParam;
            slot_idx = 1;
            match_count = (uint32_t)(*(int *)local_34.lParam == 0);
            memcpy(player_idx,(void *)local_34.lParam,0x10);
          }
          else if (local_34.message == 0x12) {
            PostQuitMessage(local_34.wParam);
            slot_idx = 1;
            match_count = 0;
            *player_idx = -2;
          }
          else {
            Palette_Subsystem_00495cde(&local_34);
          }
        }
      }
      FUN_00477d73(DAT_007006b0,(char *)0x0,0);
      UI_ShowDuelArenaWindow(1,0);
      UI_ShowDuelArenaWindow(0,0);
      UpdateWindow(g_MainAppHwnd);
      DAT_006b1578 = 0;
      SetTimer(hwnd,(UINT_PTR)DAT_006fdbd4,45000,(TIMERPROC)0x0);
      return match_count;
    }
  }
  else {
    if (y == 0x464) {
      Ai_EvalAttackCandidate_004b4a3f(0,(uint32_t)arg_3);
      return 0;
    }
    if (y == 0x501) {
      DAT_005219d0 = 0;
      BVar4 = 1;
      val_2 = GetSystemMetrics(1);
      val_3 = GetSystemMetrics(0);
      MoveWindow(hwnd,1,0,val_3 + -1,val_2,BVar4);
      return 0;
    }
  }
  uval_5 = DefWindowProcA(hwnd,y,(WPARAM)arg_3,(LPARAM)height);
  return uval_5;
}



/*
 * Decompiled function: Pic_Subsystem_00443b0c
 * Entry Point: 00443b0c
 * Size: 87 bytes
 */


WPARAM Pic_Subsystem_00443b0c(void)

{
  DWORD _Seed;
  WPARAM wParam;
  
  _Seed = GetTickCount();
  srand(_Seed);
  Ai_Subsystem_004cd3eb();
  wParam = Pic_Subsystem_0044f1de(0,DAT_006a49e8);
  PostMessageA(g_MainAppHwnd,0x401,wParam,0);
  return wParam;
}



/*
 * Decompiled function: Pic_Clip_00443b63
 * Entry Point: 00443b63
 * Size: 1636 bytes
 */


int32_t Pic_Clip_00443b63(HWND hwnd)

{
  int32_t uval_1;
  tagRECT player_idx;
  
  GetClientRect(hwnd,&player_idx);
  DAT_006b1570 = CreateWindowExA(0,s_MAGIC_CueCardClass_00521bf4,&DAT_00521bf0,0x80000000,0,0,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  g_AiPlayerHandDifferential = CreateWindowExA(0,s_MAGIC_PlayerDirectiveClass_00521c0c,&DAT_00521c08,0x80000000,0,
                                 0,100,0x1e,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_007006b0 = CreateWindowExA(0,s_MAGIC_TellUserClass_00521c2c,&DAT_00521c28,0x80000001,0,0,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006a284c = CreateWindowExA(0,s_MAGICGAME_PhaseDisplayClass_00521c50,s_Phase_Display_00521c40,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x77,g_AppHInstance,(LPVOID)0x0);
  DAT_006a283c = CreateWindowExA(0,s_MAGICGAME_AttackPhaseDisplayClas_00521c84,
                                 s_Attack_Phase_Display_00521c6c,0x50000000,0,0,0,0,hwnd,(HMENU)0x78
                                 ,g_AppHInstance,(LPVOID)0x0);
  DAT_0069f744 = CreateWindowExA(0,s_MAGICGAME_FullCardClass_00521cb8,s_Full_size_card_00521ca8,
                                 0x90000000,0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006ff4a8 = CreateWindowExA(0,s_MAGICGAME_LifeClass_00521cdc,s_Oppon_Life_00521cd0,0x50000000,0
                                 ,0,0,0,hwnd,(HMENU)0x65,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2530 = CreateWindowExA(0,s_MAGICGAME_LifeClass_00521cfc,s_Player_Life_00521cf0,0x50000000,
                                 0,0,0,0,hwnd,(HMENU)0x66,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4928 = CreateWindowExA(0,s_MAGICGAME_GraveyardClass_00521d20,s_Oppon_Graveyard_00521d10,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x6c,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2e10 = CreateWindowExA(0,s_MAGICGAME_GraveyardClass_00521d50,s_Player_Graveyard_00521d3c,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x6e,g_AppHInstance,(LPVOID)0x0);
  DAT_006ff388 = CreateWindowExA(0,s_MAGICGAME_LibraryClass_00521d7c,s_Oppon_Library_00521d6c,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x6d,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe48c = CreateWindowExA(0,s_MAGICGAME_LibraryClass_00521da4,s_Player_Library_00521d94,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x6f,g_AppHInstance,(LPVOID)0x0);
  DAT_006ff560 = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00521dc8,s_Oppon_Mana_00521dbc,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x68,g_AppHInstance,(LPVOID)0x0);
  g_AiSelectedCardTargetSlot = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00521df0,s_Player_Mana_00521de4,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x69,g_AppHInstance,(LPVOID)0x0);
  DAT_006a49f0 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00521e18,s_Oppon_Face_00521e0c,0x40000000,0
                                 ,0,0,0,hwnd,(HMENU)0x7c,g_AppHInstance,(LPVOID)0x0);
  DAT_0068a620 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00521e38,s_Player_Face_00521e2c,0x40000000,
                                 0,0,0,0,hwnd,(HMENU)0x7b,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4b60 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00521e58,s_Oppon_Chat_00521e4c,0x80800000,0
                                 ,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006b1574 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00521e78,s_Player_Chat_00521e6c,0x80800000,
                                 0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  g_TurnPriorityState = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00521ea0,s_Player_Territory_00521e8c,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x79,g_AppHInstance,(LPVOID)0x0);
  g_AiSelectedActionCode = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00521ecc,s_Oppon_Territory_00521ebc,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x7a,g_AppHInstance,(LPVOID)0x0);
  g_AiDuelTurnState = CreateWindowExA(0,s_MAGICGAME_HandClass_00521ef8,s_Opponent_Hand_00521ee8,
                                 0x82000000,(player_idx.right * 0x50) / 100,
                                 (player_idx.bottom * 0x28) / 100,0,0,hwnd,(HMENU)0x0,g_AppHInstance,
                                 (LPVOID)0x0);
  g_AiLookaheadTreeRoot = CreateWindowExA(0,s_MAGICGAME_HandClass_00521f18,s_Player_Hand_00521f0c,0x82000000,
                                 (player_idx.right * 0x50) / 100,(player_idx.bottom * 0x3c) / 100,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  g_AiDecisionMatrix_Row = CreateWindowExA(0,s_MAGICGAME_AttackClass_00521f34,s_Attack_00521f2c,0x82c00000,0,0
                                 ,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe3fc = CreateWindowExA(0,s_MAGICGAME_SpellChainClass_00521f58,s_Spell_Chain_00521f4c,
                                 0x80c00000,0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  if ((((((g_AiPlayerHandDifferential == (HWND)0x0) || (DAT_0069f744 == (HWND)0x0)) || (DAT_006ff4a8 == (HWND)0x0)
        ) || (((DAT_006b2530 == (HWND)0x0 || (DAT_006ff560 == (HWND)0x0)) ||
              ((g_AiSelectedCardTargetSlot == (HWND)0x0 ||
               ((DAT_006a4928 == (HWND)0x0 || (DAT_006ff388 == (HWND)0x0)))))))) ||
      ((DAT_006b2e10 == (HWND)0x0 ||
       ((((((DAT_006fe48c == (HWND)0x0 || (DAT_006a4b60 == (HWND)0x0)) ||
           (DAT_006b1574 == (HWND)0x0)) ||
          ((DAT_006a284c == (HWND)0x0 || (DAT_006a283c == (HWND)0x0)))) ||
         ((g_AiDecisionMatrix_Row == (HWND)0x0 || ((DAT_006fe3fc == (HWND)0x0 || (g_TurnPriorityState == (HWND)0x0)))
          ))) || (g_AiSelectedActionCode == (HWND)0x0)))))) ||
     ((((DAT_007006b0 == (HWND)0x0 || (DAT_006a49f0 == (HWND)0x0)) || (DAT_0068a620 == (HWND)0x0))
      || ((g_AiDuelTurnState == (HWND)0x0 || (g_AiLookaheadTreeRoot == (HWND)0x0)))))) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_004441cc
 * Entry Point: 004441cc
 * Size: 3831 bytes
 */


void Pic_Subsystem_004441cc(HWND hwnd,int arg2)

{
  char local_350 [200];
  uint32_t local_288;
  CHAR local_284 [100];
  char local_220 [200];
  uint32_t local_158;
  CHAR local_154 [100];
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  tagPOINT local_b8;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  tagRECT local_2c;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  GetClientRect(hwnd,&local_2c);
  g_PlayerGoldCoins = (int)(local_2c.right + (local_2c.right >> 0x1f & 7U)) >> 3;
  DAT_006ff67c = (g_PlayerGoldCoins * 0x21) / 0x118;
  g_PlayerAmuletGems = g_PlayerGoldCoins;
  if (arg2 == 1) {
    GetWindowTextA(g_AiPlayerHandDifferential,local_154,100);
    Ai_Subsystem_004b553f(local_154);
    GetClientRect(hwnd,&local_2c);
    local_a0 = local_2c.right;
    local_bc = local_2c.bottom;
    local_44 = (int)(local_2c.right + (local_2c.right >> 0x1f & 3U)) >> 2;
    local_ec = local_2c.bottom / 2;
    local_8c = local_2c.left;
    local_b8.y = local_2c.top + (local_2c.bottom - local_ec) / 2;
    local_b8.x = local_2c.left;
    local_88 = local_b8.y;
    ClientToScreen(hwnd,&local_b8);
    MoveWindow(DAT_0069f744,local_b8.x,local_b8.y,local_44,local_ec,1);
    GetWindowRect(DAT_0069f744,&local_2c);
    local_44 = local_2c.right - local_2c.left;
    local_ec = local_2c.bottom - local_2c.top;
    GetClientRect(hwnd,&local_2c);
    local_a0 = local_2c.right;
    local_bc = local_2c.bottom;
    local_c4 = local_44 / 2;
    local_d0 = local_2c.top;
    local_5c = local_88 + local_ec;
    local_d4 = (local_44 + local_8c) - local_c4;
    local_34 = local_88 - local_2c.top;
    local_b0 = local_2c.bottom - local_5c;
    local_e0 = (int)(local_44 + (local_44 >> 0x1f & 3U)) >> 2;
    local_7c = (local_44 - local_c4) - local_e0;
    local_cc = local_34 / 2;
    local_54 = local_d4 - local_e0;
    local_f0 = local_54 - local_7c;
    local_58 = local_88 - local_cc;
    local_80 = local_88 + local_ec;
    local_64 = local_44 - local_c4;
    local_90 = local_2c.left;
    match_count = local_2c.left;
    local_70 = local_2c.top;
    local_e4 = local_cc + local_80;
    local_9c = local_58 - local_2c.top;
    color_idx = local_2c.bottom - local_e4;
    local_4c = local_44 + local_8c;
    local_98 = local_2c.top;
    local_a8 = local_64 / 3;
    local_94 = local_2c.bottom;
    local_d8 = (local_2c.right - local_44) - local_a8;
    local_3c = local_2c.bottom / 2;
    local_38 = local_2c.bottom - local_3c;
    local_dc = local_a8 + local_4c;
    local_c0 = local_2c.bottom - local_38;
    local_84 = local_2c.top;
    local_a4 = (local_38 * 9) / 100;
    local_c8 = local_c0 - local_a4 / 2;
    local_68 = local_2c.bottom / 0x28;
    local_e8 = local_2c.top;
    local_74 = local_c0 - local_68;
    local_ac = local_f0;
    local_78 = local_dc;
    local_6c = local_80;
    local_60 = local_d4;
    local_50 = local_58;
    local_48 = local_dc;
    local_40 = local_dc;
    local_30 = local_d8;
    target_idx = local_cc;
    player_idx = local_54;
    card_idx = local_d8;
    slot_idx = local_dc;
    ShowWindow(DAT_0069f744,5);
    MoveWindow(DAT_006ff4a8,match_count,local_70,local_64,local_9c,1);
    MoveWindow(DAT_006b2530,local_90,local_e4,local_64,color_idx,1);
    MoveWindow(DAT_006ff560,local_d4,local_d0,local_c4,local_34,1);
    MoveWindow(g_AiSelectedCardTargetSlot,local_60,local_5c,local_c4,local_b0,1);
    MoveWindow(DAT_006ff388,local_ac,local_58,local_7c,target_idx,1);
    MoveWindow(DAT_006fe48c,local_f0,local_80,local_7c,target_idx,1);
    MoveWindow(DAT_006a4928,player_idx,local_50,local_e0,local_cc,1);
    MoveWindow(DAT_006b2e10,local_54,local_6c,local_e0,local_cc,1);
    local_b8.x = local_8c;
    local_b8.y = local_88;
    ClientToScreen(hwnd,&local_b8);
    MoveWindow(DAT_0069f744,local_b8.x,local_b8.y,local_44,local_ec,1);
    MoveWindow(g_AiSelectedActionCode,slot_idx,local_84,card_idx,local_3c,1);
    SendMessageA(g_AiSelectedActionCode,0x412,0,0);
    MoveWindow(g_TurnPriorityState,local_40,local_c0,card_idx,local_38,1);
    SendMessageA(g_TurnPriorityState,0x412,0,0);
    local_b8.x = local_48;
    local_b8.y = local_c8;
    ClientToScreen(hwnd,&local_b8);
    local_48 = local_b8.x;
    local_c8 = local_b8.y;
    MoveWindow(DAT_007006b0,local_b8.x,local_b8.y,local_30,local_a4,1);
    local_158 = SendMessageA(DAT_007006b0,0x402,(WPARAM)local_220,0);
    FUN_00477d73(DAT_007006b0,local_220,local_158);
    MoveWindow(DAT_006a284c,local_4c,local_98,local_a8,local_94,1);
    MoveWindow(DAT_006a283c,local_4c,local_98,local_a8,local_94,1);
    MoveWindow(DAT_006a49f0,match_count,local_70,local_c4 + local_64,local_34,1);
    MoveWindow(DAT_0068a620,local_90,local_80,local_c4 + local_64,local_b0,1);
    local_b8.x = local_dc;
    local_b8.y = local_e8;
    ClientToScreen(hwnd,&local_b8);
    local_dc = local_b8.x;
    local_e8 = local_b8.y;
    ShowWindow(DAT_006a4b60,0);
    MoveWindow(DAT_006a4b60,local_dc,local_e8,local_d8,local_68,1);
    local_b8.x = local_78;
    local_b8.y = local_74;
    ClientToScreen(hwnd,&local_b8);
    local_78 = local_b8.x;
    local_74 = local_b8.y;
    ShowWindow(DAT_006b1574,0);
    MoveWindow(DAT_006b1574,local_78,local_74,local_d8,local_68,1);
  }
  else if (arg2 == 2) {
    GetWindowTextA(g_AiPlayerHandDifferential,local_284,100);
    Ai_Subsystem_004b553f(local_284);
    GetClientRect(hwnd,&local_2c);
    local_a0 = local_2c.right;
    local_bc = local_2c.bottom;
    local_44 = (local_2c.right * 0x23) / 100;
    local_ec = (local_2c.bottom * 0x3c) / 100;
    local_8c = local_2c.left;
    local_88 = local_2c.top;
    MoveWindow(DAT_0069f744,local_2c.left,local_2c.top,local_44,local_ec,0);
    GetWindowRect(DAT_0069f744,&local_2c);
    local_44 = local_2c.right - local_2c.left;
    local_ec = local_2c.bottom - local_2c.top;
    GetClientRect(hwnd,&local_2c);
    local_a0 = local_2c.right;
    local_bc = local_2c.bottom;
    local_c4 = (int)(local_2c.right + (local_2c.right >> 0x1f & 7U)) >> 3;
    local_9c = (int)(local_2c.bottom + (local_2c.bottom >> 0x1f & 7U)) >> 3;
    local_90 = local_2c.left;
    match_count = local_2c.left;
    local_70 = local_2c.bottom / 2 - local_9c;
    local_e4 = local_2c.bottom / 2;
    local_7c = local_c4 / 2;
    local_e0 = local_c4 - local_7c;
    local_cc = (int)(local_2c.bottom + (local_2c.bottom >> 0x1f & 7U)) >> 3;
    local_54 = (local_c4 + local_2c.left) - local_e0;
    local_f0 = local_2c.left;
    local_ac = local_2c.left;
    local_58 = local_70 - local_cc;
    local_80 = local_9c + local_e4;
    local_60 = local_2c.left;
    local_d4 = local_2c.left;
    local_d0 = local_2c.top;
    local_5c = local_cc + local_80;
    local_34 = local_58 - local_2c.top;
    local_b0 = local_2c.bottom - local_5c;
    local_4c = local_c4 + local_2c.left;
    local_98 = local_2c.top;
    local_a8 = local_c4 / 3;
    local_94 = local_2c.bottom;
    local_84 = local_2c.top;
    local_3c = (local_9c + local_70) - local_2c.top;
    local_38 = local_2c.bottom - local_e4;
    local_dc = local_a8 + local_4c;
    local_d8 = (local_2c.right - local_c4) - local_a8;
    local_a4 = (local_38 * 9) / 100;
    local_c8 = local_e4 - local_a4 / 2;
    local_68 = local_2c.bottom / 0x28;
    local_e8 = local_2c.top;
    local_74 = local_e4 - local_68;
    local_c0 = local_e4;
    local_78 = local_dc;
    local_6c = local_80;
    local_64 = local_c4;
    local_50 = local_58;
    local_48 = local_dc;
    local_40 = local_dc;
    local_30 = local_d8;
    color_idx = local_9c;
    target_idx = local_cc;
    player_idx = local_54;
    card_idx = local_d8;
    slot_idx = local_dc;
    ShowWindow(DAT_0069f744,0);
    MoveWindow(DAT_006ff4a8,match_count,local_70,local_64,local_9c,1);
    MoveWindow(DAT_006b2530,local_90,local_e4,local_64,color_idx,1);
    MoveWindow(DAT_006ff560,local_d4,local_d0,local_c4,local_34,1);
    MoveWindow(g_AiSelectedCardTargetSlot,local_60,local_5c,local_c4,local_b0,1);
    MoveWindow(DAT_006ff388,local_ac,local_58,local_7c,target_idx,1);
    MoveWindow(DAT_006fe48c,local_f0,local_80,local_7c,target_idx,1);
    MoveWindow(DAT_006a4928,player_idx,local_50,local_e0,local_cc,1);
    MoveWindow(DAT_006b2e10,local_54,local_6c,local_e0,local_cc,1);
    MoveWindow(DAT_0069f744,local_8c,local_88,local_44,local_ec,1);
    MoveWindow(g_AiSelectedActionCode,slot_idx,local_84,card_idx,local_3c,1);
    SendMessageA(g_AiSelectedActionCode,0x412,0,0);
    MoveWindow(g_TurnPriorityState,local_40,local_c0,card_idx,local_38,1);
    SendMessageA(g_TurnPriorityState,0x412,0,0);
    local_b8.x = local_48;
    local_b8.y = local_c8;
    ClientToScreen(hwnd,&local_b8);
    local_48 = local_b8.x;
    local_c8 = local_b8.y;
    MoveWindow(DAT_007006b0,local_b8.x,local_b8.y,local_30,local_a4,1);
    local_288 = SendMessageA(DAT_007006b0,0x402,(WPARAM)local_350,0);
    FUN_00477d73(DAT_007006b0,local_350,local_288);
    MoveWindow(DAT_006a284c,local_4c,local_98,local_a8,local_94,1);
    MoveWindow(DAT_006a283c,local_4c,local_98,local_a8,local_94,1);
    MoveWindow(DAT_006a49f0,match_count,local_70,local_64,local_9c,1);
    MoveWindow(DAT_0068a620,local_90,local_e4,local_64,color_idx,1);
    local_b8.x = local_dc;
    local_b8.y = local_e8;
    ClientToScreen(hwnd,&local_b8);
    local_dc = local_b8.x;
    local_e8 = local_b8.y;
    ShowWindow(DAT_006a4b60,0);
    MoveWindow(DAT_006a4b60,local_dc,local_e8,local_d8,local_68,1);
    local_b8.x = local_78;
    local_b8.y = local_74;
    ClientToScreen(hwnd,&local_b8);
    local_78 = local_b8.x;
    local_74 = local_b8.y;
    ShowWindow(DAT_006b1574,0);
    MoveWindow(DAT_006b1574,local_78,local_74,local_d8,local_68,1);
  }
  Pic_Subsystem_0044cfe4(g_AiLookaheadTreeRoot);
  Pic_Subsystem_0044cfe4(g_AiDuelTurnState);
  Glue_Subsystem_004eed47(g_TurnPriorityState);
  Glue_Subsystem_004eed47(g_AiSelectedActionCode);
  UI_LayoutAttackCards(g_AiDecisionMatrix_Row);
  Glue_Subsystem_004cffda(DAT_006fe3fc,(LPRECT)0x0);
  UpdateWindow(DAT_0069f744);
  UpdateWindow(hwnd);
  return;
}



/*
 * Decompiled function: UI_LoadGraveyardBackdrops
 * Entry Point: 004450c3
 * Size: 1243 bytes
 */


void UI_LoadGraveyardBackdrops(int player_id,int card_slot,int event_type)

{
  HWND local_17c;
  HWND local_178;
  HWND local_174;
  HWND local_170;
  char local_16c [264];
  HANDLE local_64;
  char local_60 [52];
  uint8_t local_2c [8];
  int local_24;
  int player_idx [4];
  
  if (card_slot == 1) {
    strcpy(local_60,s_TERR_BLACK_00521f74);
  }
  else if (card_slot == 5) {
    strcpy(local_60,s_TERR_WHITE_00521f80);
  }
  else if (card_slot == 3) {
    strcpy(local_60,s_TERR_GREEN_00521f8c);
  }
  else if (card_slot == 2) {
    strcpy(local_60,s_TERR_BLUE_00521f98);
  }
  else {
    strcpy(local_60,s_TERR_RED_00521fa4);
  }
  if (arg_3 == 0) {
    strcat(local_60,&DAT_00521fb0);
  }
  else if (arg_3 == 1) {
    strcat(local_60,&DAT_00521fb8);
  }
  else {
    strcat(local_60,&DAT_00521fc0);
  }
  sprintf(local_16c,s__s__s_pic_00521fc8,&g_AiCurrentChoiceIndex,local_60);
  local_64 = (HANDLE)Pic_LoadKimPicture(local_16c);
  if (player == 0) {
    local_170 = g_TurnPriorityState;
  }
  else {
    local_170 = g_AiSelectedActionCode;
  }
  SendMessageA(local_170,0x439,(WPARAM)local_64,0);
  if (card_slot == 1) {
    strcpy(local_60,s_LIFE_BLACK_00521fd4);
  }
  else if (card_slot == 5) {
    strcpy(local_60,s_LIFE_WHITE_00521fe0);
  }
  else if (card_slot == 3) {
    strcpy(local_60,s_LIFE_GREEN_00521fec);
  }
  else if (card_slot == 2) {
    strcpy(local_60,s_LIFE_BLUE_00521ff8);
  }
  else {
    strcpy(local_60,s_LIFE_RED_00522004);
  }
  if (arg_3 == 0) {
    strcat(local_60,&DAT_00522010);
  }
  else if (arg_3 == 1) {
    strcat(local_60,&DAT_00522018);
  }
  else {
    strcat(local_60,&DAT_00522020);
  }
  sprintf(local_16c,s__s__s_pic_00522028,&g_AiCurrentChoiceIndex,local_60);
  local_64 = (HANDLE)Pic_LoadKimPicture(local_16c);
  if (player == 0) {
    local_174 = DAT_006b2530;
  }
  else {
    local_174 = DAT_006ff4a8;
  }
  SendMessageA(local_174,0x439,(WPARAM)local_64,0);
  if (card_slot == 1) {
    strcpy(local_60,s_GRAVE_BLACK_00522034);
  }
  else if (card_slot == 5) {
    strcpy(local_60,s_GRAVE_WHITE_00522040);
  }
  else if (card_slot == 3) {
    strcpy(local_60,s_GRAVE_GREEN_0052204c);
  }
  else if (card_slot == 2) {
    strcpy(local_60,s_GRAVE_BLUE_00522058);
  }
  else {
    strcpy(local_60,s_GRAVE_RED_00522064);
  }
  sprintf(local_16c,s__s__s_pic_00522070,&g_AiCurrentChoiceIndex,local_60);
  local_64 = (HANDLE)Pic_LoadKimPicture(local_16c);
  if (player == 0) {
    local_178 = DAT_006b2e10;
  }
  else {
    local_178 = DAT_006a4928;
  }
  SendMessageA(local_178,0x439,(WPARAM)local_64,0);
  if (card_slot == 1) {
    strcpy(local_60,s_HAND_BLACK_0052207c);
  }
  else if (card_slot == 5) {
    strcpy(local_60,s_HAND_WHITE_00522088);
  }
  else if (card_slot == 3) {
    strcpy(local_60,s_HAND_GREEN_00522094);
  }
  else if (card_slot == 2) {
    strcpy(local_60,s_HAND_BLUE_005220a0);
  }
  else {
    strcpy(local_60,s_HAND_RED_005220ac);
  }
  sprintf(local_16c,s__s__s_pic_005220b8,&g_AiCurrentChoiceIndex,local_60);
  local_64 = (HANDLE)Pic_LoadKimPicture(local_16c);
  GetObjectA(local_64,0x18,local_2c);
  player_idx[1] = 0xb;
  player_idx[0] = local_24 + -0xb;
  player_idx[2] = 7;
  player_idx[3] = 4;
  if (player == 0) {
    local_17c = g_AiLookaheadTreeRoot;
  }
  else {
    local_17c = g_AiDuelTurnState;
  }
  SendMessageA(local_17c,0x439,(WPARAM)local_64,(LPARAM)player_idx);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044559e
 * Entry Point: 0044559e
 * Size: 69 bytes
 */


void Pic_Subsystem_0044559e(void)

{
  if (DAT_006ff1a8 == 0) {
    DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf9,g_MainAppHwnd,UI_RegisterThinkingCardClass,0);
    DAT_006ff1a8 = 0;
  }
  return;
}



/*
 * Decompiled function: UI_RegisterThinkingCardClass
 * Entry Point: 004455e3
 * Size: 704 bytes
 */


int32_t UI_RegisterThinkingCardClass(HWND hwnd,uint32_t y,HDC hdc,int32_t arg_4)

{
  int32_t uval_1;
  HBRUSH hbr;
  HGDIOBJ h;
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_30;
  int32_t loop_idx;
  int32_t color_idx;
  HWND target_idx;
  tagRECT player_idx;
  
  if (y < 0x101) {
    if (y == 0x100) {
LAB_004457c6:
      EndDialog(hwnd,0);
      return 1;
    }
    if (y == 0x14) {
      GDI_RealizeAndFlushPalette_Magic(hdc);
      GetClientRect(hwnd,&local_30);
      hbr = GetStockObject(4);
      FillRect(hdc,&local_30,hbr);
      h = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x49d,0x31,0,0);
      SelectObject(hdc,h);
      SetBkMode(hdc,1);
      SetTextColor(hdc,DAT_00538b94);
      lpRect = &local_30;
      hWnd = GetDlgItem(hwnd,0x49d);
      GetWindowRect(hWnd,lpRect);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_30,2);
      SetTextColor(hdc,DAT_00538b90);
      DrawTextA(hdc,s_Still_thinking____005220f4,-1,&local_30,1);
      OffsetRect(&local_30,-2,-2);
      SetTextColor(hdc,DAT_00538b94);
      DrawTextA(hdc,s_Still_thinking____00522108,-1,&local_30,1);
      return 1;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
LAB_004457dc:
      EndDialog(hwnd,0);
      return 1;
    }
    if (y == 0x110) {
      DAT_006ff1a8 = hwnd;
      DAT_00538b94 = 0x100009a;
      DAT_00538b90 = 0x10000c9;
      loop_idx = 1;
      color_idx = 0xffffffff;
      GetClientRect(hwnd,&player_idx);
      target_idx = CreateWindowExA(0,s_MAGICGAME_CardClass_005220e0,
                                 s_StillThinking_small_card_005220c4,0x50000000,
                                 (player_idx.right - g_PlayerGoldCoins) / 2,
                                 (player_idx.bottom - g_PlayerAmuletGems) + -10,g_PlayerGoldCoins,g_PlayerAmuletGems,
                                 hwnd,(HMENU)0x1,g_AppHInstance,&loop_idx);
      SetTimer(hwnd,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (y == 0x111) goto LAB_004457c6;
    if (y == 0x113) {
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else {
    if (y == 0x204) goto LAB_004457dc;
    if ((0x30e < y) && (y < 0x312)) {
      uval_1 = GDI_RealizePaletteTree_Magic(hwnd,y,(HWND)hdc,arg_4);
      return uval_1;
    }
  }
  return 0;
}



/*
 * Decompiled function: UI_PromptFastEffectsDialog
 * Entry Point: 004458b0
 * Size: 4135 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t UI_PromptFastEffectsDialog(int arg1,char *mode_str)

{
  bool flag_1;
  int32_t uval_2;
  uint32_t uval_3;
  int val_4;
  uint32_t uval_5;
  int local_84;
  int local_7c;
  int local_78;
  uint8_t local_74;
  int local_70;
  char local_68 [64];
  uint32_t local_28;
  int local_24;
  uint32_t loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase] < 1) {
    *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
         *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) | 2;
  }
  target_idx = 0;
  if (((g_IsAiThinking != 1) && (g_DefendingPlayer == DAT_00627a84)) &&
     (DAT_00627a88 == g_ScWillyScore)) {
    DAT_0063ee1c = 0;
  }
  if (arg1 == 1) {
    card_idx = 0;
  }
  else {
    card_idx = FUN_00505d20(g_ScWillyScore);
  }
  strcpy(local_68,str_2);
  uval_3 = g_PlayerHandCardCount;
  uval_2 = g_CurrentTurnTargetPlayer;
  player_idx = arg1;
  g_CurrentTurnTargetPlayer = arg1;
  local_24 = arg1;
  DAT_0063ee10 = 1;
  DAT_0063edc8 = DAT_0063ee70 & 0x30;
  _DAT_0063eed8 = 0;
  DAT_00627a10 = DAT_00627a10 + 1;
  if (DAT_00627a10 < DAT_0063edc4) {
    DAT_0063edc4 = 0;
  }
  _DAT_00538bb4 = 2;
  _DAT_00538bb8 = 0x20;
  if (0x16 < g_ScWillyScore) {
    _DAT_00538bb4 = 4;
    _DAT_00538bb8 = 0x40;
  }
  if (g_ScWillyScore < 0x15) {
    _DAT_00538bb4 = 1;
    _DAT_00538bb8 = 0x10;
  }
  if (0x1d < g_ScWillyScore) {
    _DAT_00538bb4 = 8;
    _DAT_00538bb8 = 0xffffff80;
  }
  if (g_ScWillyScore == 0x1f) {
    _DAT_00538bb4 = 0xf;
    _DAT_00538bb8 = 0xfffffff0;
  }
  if ((g_ActivePlayerPriority == arg1) && (DAT_006fecc0 == g_CurrentTurnPhase)) {
    _DAT_00538bb4 = 0xf;
    _DAT_00538bb8 = 0xfffffff0;
  }
  if (((((g_IsAiThinking == 1) || (DAT_00633434 != 0)) ||
       ((g_PlayerManaPool != -1 && (g_ActivePlayerPriority == g_CurrentCardColorTarget)))) ||
      (g_ActiveCardTargetSlot == 4)) ||
     ((g_ActivePlayerPriority == arg1 && ((g_PlayerHandCardCount & 0x200) != 0)))) {
    local_84 = Pic_Subsystem_004468dc(arg1);
    player_idx = g_TemporaryToughnessBuffer;
  }
  else {
    local_84 = -1;
  }
  loop_idx = 0;
  if ((local_84 != -1) &&
     (val_4 = Pic_Subsystem_004485d6(player_idx,local_84,0x7d,local_24), val_4 == 2)) {
    Magic_ExecuteProcessTriggers(player_idx,local_84,local_24);
    local_84 = -1;
    Ai_EvaluateTacticalPosition(0,0xff);
  }
  if (local_84 != -1) {
    _DAT_0063ee84 = *(int *)(&g_CardSlot_CardId + local_84 * 0x120 + player_idx * 0x5b20);
    color_idx = _DAT_0063ee84;
    if (((&g_CardSlot_Flags)[local_84 * 0x120 + player_idx * 0x5b20] & 2) == 0) {
      val_4 = FUN_0046fe86(player_idx,local_84);
      if (val_4 != 0) {
        if ((&g_MasterCardColorTable)[color_idx * 0x34] == ' ') {
          DAT_0063edc8 = DAT_0063ee70 & 0x20;
        }
        loop_idx = 1;
        Ai_EvaluateTacticalPosition(0,0xff);
        if ((g_IsAiThinking != 1) && (val_4 = Util_GetRandomNumber(3), val_4 == 0)) {
          Pic_Subsystem_0045275a(s_Didn_t_expect_that__did_ya__00522120);
        }
      }
    }
    else {
      if (((*(int *)(&DAT_006a5f80 + local_84 * 0x120 + player_idx * 0x5b20) == g_PlayerManaPool) &&
          (DAT_00695f18 != (code *)0x0)) && (g_PlayerManaPool != -1)) {
        if (DAT_00695f18 != (code *)0x0) {
          (*DAT_00695f18)(player_idx,local_84);
        }
      }
      else {
        Magic_TriggerCardEvent(player_idx,local_84,0x73,1 - player_idx,0xffffffff);
        val_4 = Magic_ExecuteUpkeepPhase(player_idx,local_84);
        if (val_4 != 0) {
          Magic_ExecuteTapCardAction(player_idx,local_84);
        }
        g_ActivePlayer = 0;
      }
      loop_idx = 1;
      Ai_EvaluateTacticalPosition(0,0xff);
    }
  }
  local_28 = 0;
  slot_idx = 0;
  local_7c = -1;
  if ((g_IsAiThinking != 1) || ((g_PlayerManaPool != -1 && (g_CurrentTurnPhase == g_CurrentCardColorTarget)))) {
    if ((g_CurrentTurnPhase == g_CurrentCardColorTarget) && (g_PlayerManaPool != -1)) {
      for (local_24 = 0; local_24 < 2; local_24 = local_24 + 1) {
        for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[local_24];
            local_70 = local_70 + 1) {
          if ((((&g_CardSlot_Flags)[local_70 * 0x120 + local_24 * 0x5b20] & 2) != 0) &&
             (val_4 = Pic_Subsystem_004485d6(local_24,local_70,0x7d,arg1), val_4 != 0)) {
            if (val_4 == 2) {
              local_7c = local_70;
              match_count = local_24;
              player_idx = local_24;
              slot_idx = slot_idx + 1;
            }
            else {
              local_74 = (uint8_t)val_4;
              local_28 = local_28 | 1 << (local_74 & 0x1f);
            }
          }
          if (((((DAT_0068a67c & 1) != 0) &&
               (*(int *)(&DAT_006a5f80 + local_70 * 0x120 + local_24 * 0x5b20) == g_PlayerManaPool))
              && (local_24 == g_CurrentCardColorTarget)) && (g_PlayerManaPool != -1)) {
            local_28 = local_28 | 4;
            local_7c = local_70;
            match_count = local_24;
            player_idx = local_24;
            slot_idx = slot_idx + 1;
          }
        }
      }
    }
    if (local_7c == -1) {
      if (g_IsAiThinking == 1) goto LAB_00446898;
      if ((g_PlayerManaPool == 0xca) && (*(int *)(&DAT_00696750 + g_DefendingPlayer * 0x98) == 0)) {
        DAT_0068a67c = 0;
      }
      if ((g_PlayerManaPool == 0xce) && (*(int *)(&DAT_00696768 + g_DefendingPlayer * 0x98) == 0)) {
        DAT_0068a67c = 0;
      }
    }
    if (((local_7c != -1) || (local_28 != 0)) || (((DAT_0068a67c & 1) != 0 && (DAT_0063ee70 != 0))))
    {
      g_CombatPhaseFlags = 0;
      DAT_0068a67c = 0;
      local_78 = 0;
      for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
          local_70 = local_70 + 1) {
        if (((*(int *)(&g_CardSlot_CardId + local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1)
            && (((((&g_CardSlot_SpecialState)[local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 1)
                  != 0 || (((&g_CardSlot_SpecialState)
                            [local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) != 0)) ||
                ((val_4 = Magic_ResolveSpellStack(g_CurrentTurnPhase,local_70), val_4 == 0 &&
                 (g_CurrentTurnPhase == g_CurrentTurnTargetPlayer)))))) &&
           (((uval_5 = Pic_Subsystem_00446d52(g_CurrentTurnPhase,local_70), 1 < (int)uval_5 ||
             ((((DAT_006808b0 != 0 || (g_DefendingPlayer != g_CurrentTurnPhase)) &&
               ((uval_5 & 2) != 0)) || ((g_CombatPhaseFlags & 2) != 0)))) &&
            (((g_CurrentTurnPhase != g_CurrentCardColorTarget || (g_PlayerManaPool == -1)) ||
             ((uval_5 != 2 || ((g_CombatPhaseFlags & 2) != 0)))))))) {
          if (((g_CombatPhaseFlags & 2) == 0) && (uval_5 != 2)) {
            if (uval_5 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
          }
          else {
            local_7c = local_70;
            match_count = g_CurrentTurnPhase;
            slot_idx = slot_idx + 1;
          }
          g_CombatPhaseFlags = g_CombatPhaseFlags & 0xfffffffd;
        }
      }
      if (g_ActiveCardTargetSlot == 4) {
        for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[1 - g_CurrentTurnPhase];
            local_70 = local_70 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20)
                != -1) &&
              (((((&g_CardSlot_SpecialState)[local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20] &
                 1) != 0 ||
                (((&g_CardSlot_SpecialState)[local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20] &
                 0x10) != 0)) ||
               (val_4 = Magic_ResolveSpellStack(1 - g_CurrentTurnPhase,local_70), val_4 == 0)))) &&
             (val_4 = Pic_Subsystem_00446d52(1 - g_CurrentTurnPhase,local_70),
             (g_CombatPhaseFlags & 2) != 0)) {
            local_7c = local_70;
            match_count = 1 - g_CurrentTurnPhase;
            slot_idx = slot_idx + 1;
            g_CombatPhaseFlags = g_CombatPhaseFlags & 0xfffffffd;
            if (val_4 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
            break;
          }
        }
      }
      if ((local_28 & 2) != 0) {
        target_idx = 1;
      }
    }
  }
  if (((target_idx != 0) || (card_idx != 0)) || (slot_idx != 0)) {
    strcpy(&g_OverworldWorldState,s_Triggered_effects_____0052213c);
    if (((DAT_0063edc8 & 0x10) == 0) || (g_SelectedTargetPlayer != -1)) {
      if ((DAT_0063edc8 & 0x20) != 0) {
        strcpy(&g_OverworldWorldState,s_Interrupts_____00522168);
      }
    }
    else {
      strcpy(&g_OverworldWorldState,s_Fast_Effects_____00522154);
    }
    if (g_PlayerManaPool != -1) {
      strcpy(&g_OverworldWorldState,s_Triggered_effects_____00522178);
    }
    strcat(&g_OverworldWorldState,local_68);
    if ((DAT_0063ee1c == 0) || ((local_28 & 2) != 0)) {
      if (((((card_idx == 0) && ((DAT_006808b0 == 0 || (g_PlayerManaPool != -1)))) &&
           ((target_idx == 0 || (g_PlayerManaPool == -1)))) &&
          ((DAT_00525850 == 0 || ((local_28 & 6) == 0)))) &&
         (((slot_idx <= (int)(uint32_t)((local_28 & 2) == 0) && ((local_28 & 4) == 0)) ||
          ((((local_78 == 0 && (val_4 = FUN_00505c74(), val_4 != 0)) || (g_PlayerManaPool == 0xd6))
           || ((local_7c != -1 && (DAT_00627a10 == DAT_0063edc4)))))))) {
        local_84 = local_7c;
        player_idx = match_count;
        _DAT_0063eed8 = 1;
      }
      else {
        DAT_007006d0 = 1;
        DAT_00627a84 = -1;
        DAT_0063edc4 = 0;
        flag_1 = false;
        while (!flag_1) {
          if (g_IsAiThinking == 1) {
            local_84 = local_7c;
            flag_1 = true;
            DAT_0063ee8c = -1;
          }
          else {
            local_84 = Glue_Subsystem_004efd50
                                 (g_CurrentTurnPhase,-1,g_CurrentTurnPhase,0xff,0,
                                  &g_OverworldWorldState,2);
            player_idx = g_TemporaryToughnessBuffer;
            if (-1 < local_84) {
              *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
                   *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) | 2;
            }
          }
          if (DAT_0063ee8c == -3) {
            flag_1 = false;
          }
          else if (DAT_0063ee8c == -2) {
            flag_1 = true;
            local_84 = -1;
            g_TurnPhaseStateFlags = g_TurnPhaseStateFlags & 0xfffffffd;
            if (g_PlayerManaPool != -1) {
              DAT_00627a84 = g_DefendingPlayer;
              DAT_00627a88 = g_ScWillyScore;
              DAT_0063ee8c = 0;
            }
            if (slot_idx != 0) {
              DAT_0063edc4 = DAT_00627a10;
              DAT_0063ee1c = 1;
              _DAT_0063eed8 = 1;
              DAT_00627a88 = -1;
              DAT_00627a84 = -1;
            }
          }
          else if (DAT_0063ee8c == 0) {
            if ((player_idx == -1) || (local_84 == -1)) {
              if ((player_idx != -1) && (local_84 == -1)) {
                flag_1 = false;
              }
            }
            else {
              flag_1 = true;
            }
          }
        }
      }
    }
    else {
      local_84 = local_7c;
      player_idx = match_count;
      if (local_7c != -1) {
        _DAT_0063eed8 = 1;
      }
    }
    g_OverworldWorldState = 0;
    if ((local_84 != -1) &&
       ((g_CurrentTurnPhase == player_idx ||
        (((((&g_CardSlot_Flags)[local_84 * 0x120 + player_idx * 0x5b20] & 2) != 0 &&
          (val_4 = Pic_Subsystem_004485d6(player_idx,local_84,0x7d,g_CurrentTurnPhase), val_4 != 0))
         || (g_ActiveCardTargetSlot == 4)))))) {
      color_idx = *(int *)(&g_CardSlot_CardId + local_84 * 0x120 + player_idx * 0x5b20);
      val_4 = Pic_Subsystem_00446d52(player_idx,local_84);
      if (val_4 == 0) {
        val_4 = FUN_005063f6(player_idx,local_84);
        if (val_4 != 0) {
          FUN_005064e9(player_idx,local_84);
        }
      }
      else {
        if (((&g_CardSlot_Flags)[local_84 * 0x120 + player_idx * 0x5b20] & 2) == 0) {
          FUN_0046fe86(player_idx,local_84);
          if ((&g_MasterCardColorTable)[color_idx * 0x34] == ' ') {
            DAT_0063edc8 = DAT_0063ee70 & 0x20;
          }
          val_4 = Util_GetRandomNumber(3);
          if (val_4 == 0) {
            Pic_Subsystem_0045275a(s_I_knew_that_was_coming__00522190);
          }
        }
        else {
          val_4 = Pic_Subsystem_004485d6(player_idx,local_84,0x7d,g_CurrentTurnPhase);
          if (val_4 == 0) {
            if (((*(int *)(&DAT_006a5f80 + local_84 * 0x120 + player_idx * 0x5b20) == g_PlayerManaPool
                 ) && (DAT_00695f18 != (code *)0x0)) && (g_PlayerManaPool != -1)) {
              if (DAT_00695f18 != (code *)0x0) {
                (*DAT_00695f18)(player_idx,local_84);
              }
            }
            else {
              val_4 = Magic_ExecuteUpkeepPhase(player_idx,local_84);
              if (((val_4 != 0) && (Magic_ExecuteTapCardAction(player_idx,local_84), g_ActivePlayer != 1)) &&
                 (g_IsAiThinking != 1)) {
                Duel_PlaySoundById(0x1c);
              }
              g_ActivePlayer = 0;
            }
          }
          else {
            Magic_ExecuteProcessTriggers(player_idx,local_84,g_CurrentTurnPhase);
          }
        }
        Ai_EvaluateTacticalPosition(0,0xff);
        loop_idx = loop_idx | 2;
      }
      loop_idx = loop_idx | 2;
    }
    DAT_0068a67c = 1;
    _DAT_0063eed8 = 0;
  }
LAB_00446898:
  if (loop_idx == 0) {
    DAT_0063edc8 = DAT_0063ee70 & 0x30;
  }
  DAT_0063ee10 = 0;
  g_CurrentTurnTargetPlayer = uval_2;
  g_PlayerHandCardCount = uval_3;
  DAT_00627a10 = DAT_00627a10 + -1;
  return loop_idx;
}



/*
 * Decompiled function: Pic_Subsystem_004468dc
 * Entry Point: 004468dc
 * Size: 1142 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t Pic_Subsystem_004468dc(int player_id)

{
  int val_1;
  uint32_t uval_2;
  uint32_t auStack_68 [20];
  int target_idx;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  if ((g_PlayerManaPool != -1) && (g_ActivePlayerPriority == g_CurrentCardColorTarget)) {
    for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
      for (player_idx = 0; (int)player_idx < (int)(&g_PlayerActiveCardCount)[card_idx];
          player_idx = player_idx + 1) {
        if ((((&g_CardSlot_Flags)[player_idx * 0x120 + card_idx * 0x5b20] & 2) != 0) &&
           (val_1 = Pic_Subsystem_004485d6(card_idx,player_idx,0x7d,player), val_1 == 2)) {
          g_TemporaryToughnessBuffer = card_idx;
          g_TurnPhaseStateFlags = 4;
          return player_idx;
        }
        if ((((card_idx == player) &&
             (*(int *)(&DAT_006a5f80 + player_idx * 0x120 + card_idx * 0x5b20) == g_PlayerManaPool))
            && (card_idx == g_CurrentCardColorTarget)) && (g_PlayerManaPool != -1)) {
          g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
          DAT_0068a714 = DAT_0068a714 + 1;
          g_TemporaryToughnessBuffer = card_idx;
          return player_idx;
        }
      }
    }
  }
  if (((((uint8_t)DAT_0068a67c & 2) == 0) || (g_CurrentTurnPhase == player)) || (DAT_0063ee70 == 0)) {
    uval_2 = 0xffffffff;
  }
  else {
    g_TemporaryToughnessBuffer = player;
    for (player_idx = 0; (int)player_idx < (int)(&g_PlayerActiveCardCount)[player];
        player_idx = player_idx + 1) {
      match_count = *(int *)(&g_CardSlot_CardId + player_idx * 0x120 + player * 0x5b20);
      if ((match_count != -1) && (target_idx = Pic_Subsystem_00446d52(player,player_idx), target_idx != 0)) {
        auStack_68[slot_idx] = player_idx;
        slot_idx = slot_idx + 1;
        if (target_idx == 2) {
          return player_idx;
        }
      }
    }
    if (g_ActiveCardTargetSlot == 4) {
      for (player_idx = 0; (int)player_idx < (int)(&g_PlayerActiveCardCount)[1 - player];
          player_idx = player_idx + 1) {
        match_count = *(int *)(&g_CardSlot_CardId + player_idx * 0x120 + (1 - player) * 0x5b20);
        if (((match_count != -1) &&
            (target_idx = Pic_Subsystem_00446d52(1 - player,player_idx), target_idx != 0)) &&
           (target_idx == 2)) {
          g_TemporaryToughnessBuffer = 1 - player;
          return player_idx;
        }
      }
    }
    if (g_ActiveCardTargetSlot == 4) {
      uval_2 = 0xffffffff;
    }
    else {
      auStack_68[slot_idx] = 0xffffffff;
      slot_idx = slot_idx + 1;
      if (g_IsAiThinking == 1) {
        val_1 = Util_GetRandomNumber(2);
        if ((val_1 == 0) || (val_1 = Ai_ClearCandidateScoreList(), val_1 == 0)) {
          g_AiDecisionScore = Util_GetRandomNumber(slot_idx);
        }
        else {
          g_AiDecisionScore = slot_idx + -1;
        }
        if ((DAT_006a2838 != 0) && (g_AiDecisionScore = slot_idx + -1, DAT_006a2838 == 1)) {
          DAT_006a2838 = -1;
        }
        g_AiCurrentSearchPath = (-(uint32_t)((*(uint32_t *)(&g_CardSlot_Flags +
                                          player * 0x5b20 + auStack_68[g_AiDecisionScore] * 0x120) &
                                2) == 0) & 0xfffff000) + 0x2000 | auStack_68[g_AiDecisionScore] |
                       (player == 0) - 1 & 0x100;
        DAT_0052ce1c = 4;
        Ai_EvaluateCreaturePower();
      }
      else {
        DAT_0052ce1c = 4;
        Ai_CalcCardAdvantage();
        if (slot_idx <= g_AiDecisionScore) {
          g_AiDecisionScore = slot_idx + -1;
        }
      }
      if (auStack_68[g_AiDecisionScore] != 0xffffffff) {
        if (0xf < DAT_006a2844) {
          DAT_006a2844 = DAT_006a2844 + -1;
        }
        *(int32_t *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
             *(int32_t *)
              (&g_CardSlot_CardId + player * 0x5b20 + auStack_68[g_AiDecisionScore] * 0x120);
        *(uint32_t *)(&DAT_006966f0 + DAT_006a2844 * 4) = auStack_68[g_AiDecisionScore];
        DAT_006a2844 = DAT_006a2844 + 1;
      }
      uval_2 = auStack_68[g_AiDecisionScore];
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_00446d52
 * Entry Point: 00446d52
 * Size: 1260 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_00446d52(int arg1,int arg2)

{
  int val_1;
  int val_2;
  uint8_t match_count;
  
  val_1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
    if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
      return 0;
    }
    if ((g_PlayerManaPool != -1) &&
       (*(code **)(&g_CardScriptCallbackTable + val_1 * 0x34) != Prompts_Load_00416f1a)) {
      return 0;
    }
    if ((DAT_00525778 != 0) && (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x20) == 0)) {
      return 0;
    }
    if (((((DAT_0063edc8 & (uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34]) != 0) &&
         (val_2 = FUN_00470ea3(arg1,arg1,arg2), val_2 != 0)) &&
        ((((uint8_t)g_PlayerHandCardCount & 4) == 0 ||
         ((*(uint32_t *)(&g_MasterCardSubtypeTable + val_1 * 0x34) & 0x3004) != 0)))) &&
       (((g_CurrentTurnPhase == arg1 ||
         ((_DAT_00538bb4 & (int)(char)(&DAT_0051aed5)[val_1 * 0x34]) != 0)) &&
        (val_1 = Magic_TriggerCardEvent(arg1,arg2,0x74,1 - arg1,0xffffffff), val_1 != 0)))) {
      return 3;
    }
  }
  else {
    if ((*(int *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) == g_PlayerManaPool) &&
       (g_PlayerManaPool != -1)) {
      if (arg1 == g_CurrentCardColorTarget) {
        g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
        DAT_0068a714 = DAT_0068a714 + 1;
        return 2;
      }
      return 0;
    }
    if (g_PlayerManaPool != -1) {
      val_1 = Pic_Subsystem_004485d6(arg1,arg2,0x7d,arg1);
      if (val_1 == 0) {
        return 0;
      }
      match_count = (uint8_t)val_1;
      g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 1 << (match_count & 0x1f);
      DAT_0068a714 = DAT_0068a714 + 1;
      if (1 < val_1) {
        return 2;
      }
      return 3;
    }
    if ((((((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0) &&
         (((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 1) != 0)) && ((DAT_0063edc8 & 0x10) != 0)) ||
       ((((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 2) != 0 && ((DAT_0063edc8 & 0x20) != 0)))) {
      if ((DAT_00525778 != 0) && (((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 2) == 0)) {
        return 0;
      }
      if (((((uint8_t)g_PlayerHandCardCount & 4) == 0) ||
          ((*(uint32_t *)(&g_MasterCardSubtypeTable + val_1 * 0x34) & 0x5004) != 0)) &&
         (((g_CombatPhaseFlags = g_CombatPhaseFlags & 0xfffffffd, g_CurrentTurnPhase == arg1 ||
           ((_DAT_00538bb8 & (int)(char)(&DAT_0051aed5)[val_1 * 0x34]) != 0)) &&
          ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0 &&
           (val_1 = Magic_TriggerCardEvent(arg1,arg2,0x73,1 - arg1,0xffffffff), val_1 != 0)))))) {
        if ((g_CombatPhaseFlags & 2) != 0) {
          g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
          return 2;
        }
        g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 2;
        return 3;
      }
    }
    if ((g_ActiveCardTargetSlot == 4) && (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)
       ) {
      g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
      g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
      return 2;
    }
    if ((((g_ActiveCardTargetSlot == 4) && (arg1 == g_CurrentTurnTargetPlayer)) &&
        (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
       ((((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0 &&
        (val_1 = FUN_00476675(arg1,arg2), val_1 != 0)))) {
      g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 2;
      if (g_ActivePlayerPriority == arg1) {
        return 2;
      }
      return 3;
    }
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044724d
 * Entry Point: 0044724d
 * Size: 840 bytes
 */


int32_t Pic_Subsystem_0044724d(void)

{
  int32_t uval_1;
  
  if (g_ActiveCardTargetSlot == 0x8e) {
    if (g_ActiveBattlefieldFlag == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else if (((((g_ActiveCardTargetSlot == 0x6a) || (g_ActiveCardTargetSlot == 0x6b)) || (g_ActiveCardTargetSlot == 0x6c)) ||
           ((((g_ActiveCardTargetSlot == 0x6d || (g_ActiveCardTargetSlot == 0x6e)) ||
             ((g_ActiveCardTargetSlot == 0x6f || ((g_ActiveCardTargetSlot == 0x70 || (g_ActiveCardTargetSlot == 0x71)))))) ||
            ((g_ActiveCardTargetSlot == 0x72 ||
             ((((g_ActiveCardTargetSlot == 0x73 || (g_ActiveCardTargetSlot == 0x74)) || (g_ActiveCardTargetSlot == 0x75)) ||
              ((g_ActiveCardTargetSlot == 0x76 || (g_ActiveCardTargetSlot == 0x77)))))))))) ||
          (((g_ActiveCardTargetSlot == 0x78 || ((g_ActiveCardTargetSlot == 0x79 || (g_ActiveCardTargetSlot == 0x7a)))) ||
           (((g_ActiveCardTargetSlot == 0x7b ||
             ((((g_ActiveCardTargetSlot == 0x7c || (g_ActiveCardTargetSlot == 0x7d)) || (g_ActiveCardTargetSlot == 0x7e)) ||
              (((g_ActiveCardTargetSlot == 0x7f || (g_ActiveCardTargetSlot == 0x80)) ||
               ((g_ActiveCardTargetSlot == 0x81 || ((g_ActiveCardTargetSlot == 0x82 || (g_ActiveCardTargetSlot == 0x83))))))))))
            || ((((g_ActiveCardTargetSlot == 0x84 ||
                  ((((((g_ActiveCardTargetSlot == 0x85 || (g_ActiveCardTargetSlot == 0x86)) || (g_ActiveCardTargetSlot == 0x87))
                     || (((g_ActiveCardTargetSlot == 0x88 || (g_ActiveCardTargetSlot == 0x89)) ||
                         ((g_ActiveCardTargetSlot == 0x8e || ((g_ActiveCardTargetSlot == 199 || (g_ActiveCardTargetSlot == 200))))
                         )))) || (g_ActiveCardTargetSlot == 0xc9)) ||
                   ((((((g_ActiveCardTargetSlot == 0xca || (g_ActiveCardTargetSlot == 0xcb)) || (g_ActiveCardTargetSlot == 0xcc))
                      || ((g_ActiveCardTargetSlot == 0xcd || (g_ActiveCardTargetSlot == 0xce)))) ||
                     (g_ActiveCardTargetSlot == 0xcf)) || ((g_ActiveCardTargetSlot == 0xd2 || (g_ActiveCardTargetSlot == 0xd3)))))
                   ))) || (((g_ActiveCardTargetSlot == 0xd4 ||
                            (((g_ActiveCardTargetSlot == 0xd5 || (g_ActiveCardTargetSlot == 0xd6)) ||
                             (g_ActiveCardTargetSlot == 0xd7)))) ||
                           (((g_ActiveCardTargetSlot == 0xd8 || (g_ActiveCardTargetSlot == 0xd9)) ||
                            (g_ActiveCardTargetSlot == 0xdc)))))) || (g_ActiveCardTargetSlot == 0xdb)))))))) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: Rules_ProcessDamagePrevention
 * Entry Point: 004475a4
 * Size: 1142 bytes
 */


void Rules_ProcessDamagePrevention(void)

{
  bool flag_1;
  int val_2;
  int target_idx;
  int player_idx;
  int card_idx;
  int32_t match_count;
  
  if ((g_PlayerHandCardCount & 2) == 0) {
    return;
  }
  g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffffd;
  g_PlayerHandCardCount = g_PlayerHandCardCount | 4;
  Ai_EvaluateTacticalPosition(0,0xff);
  for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
    for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[player_idx]; target_idx = target_idx + 1
        ) {
      if (((*(int *)(&g_CardSlot_CardId + target_idx * 0x120 + player_idx * 0x5b20) == g_PendingSpellTargetSlot) &&
          (((&g_CardSlot_Flags)[target_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[target_idx * 0x120 + player_idx * 0x5b20] & 0x10) == 0)) {
        Rules_ApplyContinuousDamage(player_idx,target_idx,0x21);
      }
    }
  }
  flag_1 = false;
  do {
    if ((g_IsAiThinking != 1) && (DAT_00633434 == 0)) {
      FUN_00472f0c(9,0xf);
      card_idx = -99999;
      flag_1 = true;
    }
    while( true ) {
      if ((DAT_006808a8 == 9) && (flag_1)) {
        Ai_GetActivePlayerScore();
        DAT_006b253c = 0;
        DAT_006b2538 = 0;
        DAT_006a2844 = 0;
        g_SpellStackDepth = 0;
      }
      val_2 = FUN_00475c8a(-2,0xffffffff,s_Damage_prevention_005221a8,0x8e);
      if (val_2 != 0) break;
      Magic_ScanCards(0x25);
      for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
        for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[player_idx];
            target_idx = target_idx + 1) {
          if (((*(int *)(&g_CardSlot_CardId + target_idx * 0x120 + player_idx * 0x5b20) == g_PendingSpellTargetSlot)
              && (((&g_CardSlot_Flags)[target_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) &&
             (((&g_CardSlot_Flags)[target_idx * 0x120 + player_idx * 0x5b20] & 0x10) == 0)) {
            Rules_ApplyContinuousDamage(player_idx,target_idx,0x6e);
          }
        }
      }
      FUN_00476205(g_DefendingPlayer,0xd7,s_Damage_Dealing_005221bc,0);
      for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
        for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[player_idx];
            target_idx = target_idx + 1) {
          if ((*(int *)(&g_CardSlot_CardId + target_idx * 0x120 + player_idx * 0x5b20) == g_PendingSpellTargetSlot)
             && (((&g_CardSlot_Flags)[target_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) {
            if (((&g_CardSlot_Flags)[target_idx * 0x120 + player_idx * 0x5b20] & 0x10) == 0) {
              g_PlayerHandCardCount = g_PlayerHandCardCount | 2;
            }
            else {
              Pic_Subsystem_0044867e(player_idx,target_idx,1);
            }
          }
        }
      }
      Pic_Subsystem_00447a1a();
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffffb;
      if (((g_IsAiThinking != 1) || (!flag_1)) || (DAT_006808a8 != 9)) {
        if (g_IsAiThinking == 1) {
          return;
        }
        if (!flag_1) {
          return;
        }
        DAT_00633434 = 0;
        return;
      }
      Rules_SendCardsToGraveyard();
      val_2 = Ai_SimulateCombatRound(g_ActivePlayerPriority);
      val_2 = g_SpellStackDepth + val_2;
      if (card_idx < val_2) {
        Ai_ScoreBoardPosition();
        match_count = DAT_00680790;
        card_idx = val_2;
      }
      if (DAT_006a2840 == 999) {
        DAT_006a2840 = -1;
      }
      DAT_006a2838 = 0;
      val_2 = Mem_AllocOrFree_00501721();
      if ((DAT_006fe40c * DAT_0052244c) / 5 < val_2) {
        g_IsAiThinking = 0;
        DAT_006a2840 = -1;
        DAT_00680790 = match_count;
      }
      g_PlayerHandCardCount = g_PlayerHandCardCount | 4;
    }
  } while( true );
}



/*
 * Decompiled function: Pic_Subsystem_00447a1a
 * Entry Point: 00447a1a
 * Size: 317 bytes
 */


void Pic_Subsystem_00447a1a(void)

{
  short len_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1) {
      if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) != -1) &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0))
         && (((&g_CardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
        len_1 = *(short *)(&g_CardSlot_Power + match_count * 0x120 + slot_idx * 0x5b20);
        val_2 = Card_TapForMana(slot_idx,match_count,0x33,0xffffffff);
        if (val_2 <= len_1) {
          if (g_IsAiThinking != 1) {
            Duel_PlaySoundById(0x19);
          }
          Pic_Subsystem_0044867e(slot_idx,match_count,2);
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00447b57
 * Entry Point: 00447b57
 * Size: 2677 bytes
 */


int Pic_Subsystem_00447b57(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int event_type;
  int player_idx;
  int match_count;
  
  DAT_0063ee88 = 1;
  *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x800;
  val_1 = Card_IsTapped(arg1,arg2);
  if (((((val_1 == 0) || (g_ScWillyScore != 0x15)) || (g_DefendingPlayer != arg1)) ||
      ((((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0 ||
       (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)))) ||
     (val_1 = FUN_004726c5(arg1,arg2), val_1 == 0)) {
    if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (g_PlayerManaPool == -1))
    {
      if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) &&
         ((g_PlayerManaPool != -1 &&
          (*(code **)(&g_CardScriptCallbackTable +
                     *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34) !=
           Prompts_Load_00416f1a)))) {
        match_count = 0;
      }
      else if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) ||
              (g_ScWillyScore != 1)) {
        if (g_CurrentTurnPhase == arg1) {
          val_1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
          if ((DAT_0063ee10 == 0) && ((g_ScWillyScore == 0x15 || (g_ScWillyScore == 0x17)))) {
            if (((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) &&
                (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
               (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) != 0)) {
              if (((g_DefendingPlayer == arg1) && (val_1 = FUN_004726c5(arg1,arg2), val_1 != 0)) &&
                 (((&g_CardSlot_Subtypes)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0)) {
                DAT_0063ee88 = 0;
                return 0x10;
              }
              if ((g_DefendingPlayer != arg1) && (g_ActiveBattlefieldFlag != 0)) {
                DAT_0063ee88 = 0;
                return 0x20;
              }
            }
            *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            match_count = 0;
          }
          else {
            if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
              if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
                *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                     *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                DAT_0063ee88 = 0;
                return 0;
              }
              Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[val_1 * 0x34]);
              if ((DAT_0063ee10 == 0) ||
                 ((DAT_0063edc8 & (uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34]) != 0)) {
                if (((&g_MasterCardColorTable)[val_1 * 0x34] & 1) != 0) {
                  if (((g_DefendingPlayer == arg1) && (((uint8_t)g_PlayerHandCardCount & 1) == 0)) &&
                     ((g_ScWillyScore == 0x14 || (g_ScWillyScore == 0x1e)))) {
                    DAT_0063ee88 = 0;
                    return 4;
                  }
                  *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                       *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                  DAT_0063ee88 = 0;
                  return 0;
                }
                if (((g_DefendingPlayer == g_CurrentTurnPhase) ||
                    (((g_DefendingPlayer != g_CurrentTurnPhase && (DAT_0063ee10 != 0)) &&
                     ((((&g_MasterCardColorTable)[val_1 * 0x34] & 0x10) != 0 ||
                      (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x20) != 0)))))) &&
                   ((val_2 = FUN_00470ea3(arg1,arg1,arg2), val_2 != 0 &&
                    (((((uint8_t)g_PlayerHandCardCount & 4) == 0 ||
                      ((*(uint32_t *)(&g_MasterCardSubtypeTable + val_1 * 0x34) & 0x3004) != 0)) &&
                     ((((&g_MasterCardColorTable)[val_1 * 0x34] & 0x42) != 0 ||
                      (val_1 = Magic_TriggerCardEvent(arg1,arg2,0x74,1 - arg1,0xffffffff),
                      val_1 != 0)))))))) {
                  DAT_0063ee88 = 0;
                  return 4;
                }
              }
            }
            else {
              if ((g_ActiveCardTargetSlot == 4) &&
                 (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
                g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
                g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
                DAT_0063ee88 = 0;
                return 2;
              }
              if ((((g_ActiveCardTargetSlot == 4) &&
                   (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
                  (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0)) &&
                 (val_2 = FUN_00476675(arg1,arg2), val_2 != 0)) {
                g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 2;
                DAT_0063ee88 = 0;
                return 8;
              }
              if (((((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) &&
                    (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) != 0)) &&
                   ((DAT_0063ee10 == 0 && ((g_DefendingPlayer == arg1 && (g_ScWillyScore < 0x1b)))))
                   ) && (val_2 = FUN_004726c5(arg1,arg2), val_2 != 0)) &&
                 ((((&g_CardSlot_Subtypes)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                  (((&g_MasterCardColorTable)
                    [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0))
                 )) {
                DAT_0063ee78 = 1;
              }
              if (((((((&g_MasterCardFlagsTable)[val_1 * 0x34] & 0x10) != 0) &&
                    (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
                   ((((&g_CardSlot_Subtypes)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                    (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0
                    )))) || (((((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 1) != 0 &&
                              ((DAT_0063edc8 & 0x10) != 0)) ||
                             ((((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 2) != 0 &&
                              ((DAT_0063edc8 & 0x20) != 0)))))) &&
                 ((((((uint8_t)g_PlayerHandCardCount & 4) == 0 ||
                    ((*(uint32_t *)(&g_MasterCardSubtypeTable + val_1 * 0x34) & 0x5004) != 0)) &&
                   (g_CombatPhaseFlags = g_CombatPhaseFlags & 0xfffffffd,
                   ((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)) &&
                  (val_1 = Magic_TriggerCardEvent(arg1,arg2,0x73,1 - arg1,0xffffffff), val_1 != 0)))
                 ) {
                if ((g_CombatPhaseFlags & 2) != 0) {
                  g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
                  DAT_0063ee88 = 0;
                  return 2;
                }
                g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 2;
                DAT_0063ee88 = 0;
                return 8;
              }
            }
            *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            match_count = 0;
          }
        }
        else if ((g_ActiveCardTargetSlot == 4) &&
                (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
          g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
          g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 4;
          match_count = 2;
        }
        else {
          *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
          match_count = 0;
        }
      }
      else {
        g_OverworldPlayerCoordX = arg1;
        g_OverworldMapGrid = arg2;
        g_ActivePalette = 0;
        Magic_ScanCards(0x7d);
        match_count = g_ActivePalette;
      }
    }
    else {
      if (*(int *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) == g_PlayerManaPool) {
        if (arg1 == g_CurrentCardColorTarget) {
          player_idx = 2;
        }
        else {
          player_idx = 0;
        }
      }
      else {
        arg_3 = 2;
        val_2 = 0;
        val_1 = Pic_Subsystem_004485d6(arg1,arg2,0x7d,arg1);
        player_idx = Math_Clamp(val_1,val_2,arg_3);
      }
      if (player_idx == 0) {
        match_count = 0;
      }
      else {
        g_TurnPhaseStateFlags = g_TurnPhaseStateFlags | 1 << ((uint8_t)player_idx & 0x1f);
        DAT_0068a714 = DAT_0068a714 + 1;
        match_count = player_idx;
      }
    }
  }
  else {
    match_count = 2;
  }
  DAT_0063ee88 = 0;
  return match_count;
}



/*
 * Decompiled function: Pic_Subsystem_004485d6
 * Entry Point: 004485d6
 * Size: 168 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_004485d6(int x,int y,int width,int32_t arg_4)

{
  int32_t uval_1;
  
  if ((width == 0x7d) &&
     ((((&DAT_006a5f3d)[y * 0x120 + x * 0x5b20] & 1) != 0 || (DAT_0068078c != 0)))) {
    uval_1 = 0;
  }
  else if (g_PlayerManaPool < 200) {
    uval_1 = 0;
  }
  else {
    g_ActivePalette = 0;
    g_OverworldPlayerCoordX = x;
    g_OverworldMapGrid = y;
    _DAT_006b2fe8 = arg_4;
    DAT_006b2d5c = 0xffffffff;
    Magic_ScanCards(width);
    uval_1 = g_ActivePalette;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0044867e
 * Entry Point: 0044867e
 * Size: 546 bytes
 */


void Pic_Subsystem_0044867e(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((player != -1) && (card_slot != -1)) &&
     (((&g_CardSlot_Abilities1)[card_slot * 0x120 + player * 0x5b20] & 0x80) == 0)) {
    *(uint32_t *)(&g_CardSlot_Abilities1 + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities1 + card_slot * 0x120 + player * 0x5b20) | 0x80;
    val_1 = *(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20);
    if (val_1 != -1) {
      if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) == 0) {
        arg_3 = 3;
      }
      if (((((&g_CardSlot_Abilities1)[card_slot * 0x120 + player * 0x5b20] & 8) == 0) && (arg_3 != 3)) &&
         ((arg_3 != 4 &&
          ((((&g_MasterCardColorTable)[val_1 * 0x34] & 3) != 0 &&
           ((&g_MasterCardColorTable)[val_1 * 0x34] != -0x80)))))) {
        (&g_CardSlot_CardTypeIndex)[card_slot * 0x120 + player * 0x5b20] = (uint8_t)arg_3;
        *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 2;
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) == 0) {
          Rules_CardLeavingPlay(player,card_slot);
        }
        else {
          *(int32_t *)(&DAT_006a5f80 + card_slot * 0x120 + player * 0x5b20) = 0xd6;
        }
        DAT_00695f18 = Rules_CardLeavingPlay;
      }
      else {
        (&g_CardSlot_CardTypeIndex)[card_slot * 0x120 + player * 0x5b20] = (uint8_t)arg_3;
        Rules_CardLeavingPlay(player,card_slot);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Rules_SendCardsToGraveyard
 * Entry Point: 004488a0
 * Size: 191 bytes
 */


int32_t Rules_SendCardsToGraveyard(void)

{
  if ((DAT_00695f18 != 0) && (DAT_0052211c == 0)) {
    DAT_0052211c = 1;
    g_PlayerHandCardCount = g_PlayerHandCardCount | 0x200;
    FUN_00475c8a(-2,g_ScWillyScore,s_Use_Regeneration_Effects_005221cc,0x70);
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffdff;
    FUN_00476205(g_DefendingPlayer,0xd6,s_Graveyard_order_005221e8,0);
    FUN_00476205(g_DefendingPlayer,0xd5,s_Card_s__to_Graveyard_005221f8,0);
    DAT_00695f18 = 0;
    DAT_0052211c = 0;
    Ai_EvaluateTacticalPosition(0,0xff);
  }
  return 0;
}



/*
 * Decompiled function: Rules_CardLeavingPlay
 * Entry Point: 0044895f
 * Size: 1226 bytes
 */


int32_t Rules_CardLeavingPlay(int arg1,int arg2)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  int32_t uval_4;
  
  val_2 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  cVar1 = (&g_CardSlot_CardTypeIndex)[arg2 * 0x120 + arg1 * 0x5b20];
  if (cVar1 != '\0') {
    if ((((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0) &&
       ((&g_MasterCardColorTable)[val_2 * 0x34] != -0x80)) {
      if ((cVar1 != '\x04') &&
         ((((&g_MasterCardColorTable)[val_2 * 0x34] & 2) != 0 &&
          (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)))) {
        DAT_006b303c = DAT_006b303c + 1;
      }
      if (((&g_MasterCardColorTable)[val_2 * 0x34] & 0x47) != 0) {
        Magic_PayManaCost();
        g_ActivePalette = 0;
        g_OverworldPlayerCoordX = arg1;
        g_OverworldMapGrid = arg2;
        DAT_007006c8 = 1 - arg1;
        DAT_006b2d5c = 0xffffffff;
        Magic_ScanCards(0x77);
        if (0 < g_ActivePalette) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
          Magic_TapCardForMana();
          return 0;
        }
        cVar1 = (&g_CardSlot_CardTypeIndex)[arg2 * 0x120 + arg1 * 0x5b20];
        Magic_TapCardForMana();
      }
      if (((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
        if (cVar1 == '\x04') {
          Pic_Subsystem_0044929c
                    ((*(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x1000) >> 0xc,
                     *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20));
        }
        else {
          if ((cVar1 != '\x03') && (g_IsAiThinking != 1)) {
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0) {
              if (((&g_MasterCardColorTable)
                   [*(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x38) ==
                  0) {
                Duel_PlaySoundById(1);
              }
            }
            else {
              Duel_PlaySoundById(0x19);
            }
          }
          Pic_Subsystem_0044913a(arg1,arg2);
          if (cVar1 == '\x03') {
            FUN_00476205(g_DefendingPlayer,0xd5,s_Card_s__to_Graveyard_00522210,0);
          }
        }
      }
    }
    Magic_PayManaCost();
    uval_4 = DAT_006b2e14;
    uval_3 = DAT_00695f08;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    if (((&g_MasterCardColorTable)[val_2 * 0x34] & 0x47) != 0) {
      FUN_00476205(g_DefendingPlayer,0xd4,s_Card_leaving_play_00522228,0);
    }
    DAT_00695f08 = uval_3;
    DAT_006b2e14 = uval_4;
    Magic_TapCardForMana();
    if (((&g_MasterCardColorTable)[val_2 * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg1 * 4) = *(int *)(&DAT_006b3010 + arg1 * 4) + -1;
    }
    if (((&g_MasterCardColorTable)[val_2 * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg1] = (&DAT_006b3018)[arg1] + -1;
    }
    if (((&g_MasterCardColorTable)[val_2 * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg1 * 4) = *(int *)(&DAT_006b3020 + arg1 * 4) + -1;
    }
    *(int32_t *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
    (&g_CardSlot_CardTypeIndex)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(int32_t *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    if (g_IsAiThinking != 1) {
      Ai_Subsystem_004cc3f8(arg1,arg2,7,2);
    }
    Pic_Subsystem_00448e29(arg1,arg2);
    if (((&g_MasterCardColorTable)[val_2 * 0x34] & 0x47) != 0) {
      Rules_ProcessCombatDamageStep();
    }
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_00448e29
 * Entry Point: 00448e29
 * Size: 785 bytes
 */


void Pic_Subsystem_00448e29(int arg1,int arg2)

{
  int local_514;
  int local_510;
  int local_508;
  int aiStack_504 [320];
  
  local_510 = 0;
  for (local_508 = 0; local_508 < 2; local_508 = local_508 + 1) {
    for (local_514 = 0; local_514 < (int)(&g_PlayerActiveCardCount)[local_508];
        local_514 = local_514 + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_514 * 0x120 + local_508 * 0x5b20) != -1) &&
           (((&g_CardSlot_Flags)[local_514 * 0x120 + local_508 * 0x5b20] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[local_514 * 0x120 + local_508 * 0x5b20] == arg1)) &&
         ((*(int *)(&g_CardSlot_OriginalCardId + local_514 * 0x120 + local_508 * 0x5b20) == arg2 &&
          ((local_508 != arg1 || (local_514 != arg2)))))) {
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_514 * 0x120 + local_508 * 0x5b20) * 0x34] & 0x43)
            == 0) {
          aiStack_504[local_510 * 2] = local_508;
          aiStack_504[local_510 * 2 + 1] = local_514;
          local_510 = local_510 + 1;
        }
        else {
          (&g_CardSlot_Toughness)[local_514 * 0x120 + local_508 * 0x5b20] = 0xff;
          *(int32_t *)(&g_CardSlot_OriginalCardId + local_514 * 0x120 + local_508 * 0x5b20) =
               0xffffffff;
        }
      }
    }
  }
  while (local_510 != 0) {
    local_510 = local_510 + -1;
    Pic_Subsystem_0044867e(aiStack_504[local_510 * 2],aiStack_504[local_510 * 2 + 1],2);
  }
  *(int16_t *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20) = 0;
  *(int16_t *)(&g_CardSlot_ToughnessCounters + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int16_t *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20);
  *(int16_t *)(&g_CardSlot_PowerCounters + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int16_t *)(&g_CardSlot_ToughnessCounters + arg2 * 0x120 + arg1 * 0x5b20);
  (&g_CardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044913a
 * Entry Point: 0044913a
 * Size: 233 bytes
 */


void Pic_Subsystem_0044913a(int arg1,int arg2)

{
  int val_1;
  int card_idx;
  uint32_t match_count;
  
  val_1 = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20);
  match_count = (uint32_t)(((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
  *(uint32_t *)(&DAT_00695e00 + match_count * 4) =
       *(uint32_t *)(&DAT_00695e00 + match_count * 4) | (uint32_t)(uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34];
  card_idx = 0;
  while( true ) {
    if (499 < card_idx) {
      return;
    }
    if (*(int *)(&g_PlayerGraveyardList + card_idx * 4 + match_count * 2000) == -1) break;
    card_idx = card_idx + 1;
  }
  *(int *)(&g_PlayerGraveyardList + card_idx * 4 + match_count * 2000) = val_1;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00449223
 * Entry Point: 00449223
 * Size: 121 bytes
 */


void Pic_Subsystem_00449223(int arg1,int arg2)

{
  int slot_idx;
  
  for (slot_idx = arg2; slot_idx < 499; slot_idx = slot_idx + 1) {
    *(int32_t *)(&g_PlayerGraveyardList + slot_idx * 4 + arg1 * 2000) =
         *(int32_t *)(&DAT_006ff714 + slot_idx * 4 + arg1 * 2000);
  }
  *(int32_t *)(&DAT_006ffedc + arg1 * 2000) = 0xffffffff;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044929c
 * Entry Point: 0044929c
 * Size: 164 bytes
 */


void Pic_Subsystem_0044929c(int arg1,int arg2)

{
  int slot_idx;
  
  if ((g_IsAiThinking != 1) && (((&g_MasterCardColorTable)[arg2 * 0x34] & 2) != 0)) {
    Duel_PlaySoundById(0x17);
  }
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return;
    }
    if (*(int *)(&DAT_006b1590 + slot_idx * 4 + arg1 * 2000) == -1) break;
    slot_idx = slot_idx + 1;
  }
  *(int *)(&DAT_006b1590 + slot_idx * 4 + arg1 * 2000) = arg2;
  return;
}



/*
 * Decompiled function: UI_RegisterExpandedGraveyardClass
 * Entry Point: 00449340
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
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  local_2c.style = 8;
  local_2c.lpfnWndProc = UI_WndProc_00449fbb;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_ExpandedGraveyard_0052223c;
  AVar2 = RegisterClassA(&local_2c);
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_0044a135;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_GraveyardCards_00522250;
  AVar3 = RegisterClassA(&local_2c);
  DAT_00538bcc = CreatePopupMenu();
  return AVar3 != 0 && (AVar2 != 0 && AVar1 != 0);
}



/*
 * Decompiled function: Pic_Subsystem_004494d1
 * Entry Point: 004494d1
 * Size: 46 bytes
 */


void Pic_Subsystem_004494d1(void)

{
  if (DAT_00538bcc != (HMENU)0x0) {
    DestroyMenu(DAT_00538bcc);
  }
  DAT_00538bcc = (HMENU)0x0;
  return;
}



/*
 * Decompiled function: UI_GraveyardMenuProc
 * Entry Point: 004494ff
 * Size: 2624 bytes
 */


LRESULT UI_GraveyardMenuProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam)

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
  char local_1fc [264];
  ULONG_PTR local_f4;
  uint32_t local_f0;
  char *local_ec;
  int local_e8;
  char *local_e4;
  char *local_e0;
  WPARAM local_dc;
  char local_d8 [100];
  char local_74 [100];
  LONG card_idx;
  char *match_count;
  HWND slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      card_idx = GetWindowLongA(hwnd,0);
      match_count = (char *)GetWindowLongA(hwnd,8);
      local_200 = Pic_Subsystem_0044a7e1((uint32_t)(hwnd != DAT_006b2e10));
      if (local_200 != card_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      GetClientRect(hwnd,&local_210);
      pHVar2 = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_210,pHVar2);
      if (local_200 == -1) {
        if (match_count != (HANDLE)0x0) {
          FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_210,match_count);
        }
      }
      else {
        Palette_Subsystem_0049c7c7
                  (g_HdcBackBuffer,&local_210.left,(WPARAM *)(&DAT_006b3070 + local_200 * 0x98),0,
                   0x11,0);
      }
      local_254 = BeginPaint(hwnd,&local_250);
      if (local_254 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_254);
        if (DAT_0068a674 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_254,&local_210,pHVar2);
          Sleep(200);
        }
        BitBlt(local_254,0,0,local_210.right,local_210.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_250);
        card_idx = local_200;
        SetWindowLongA(hwnd,0,local_200);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return 0;
    }
    if (uMsg == 1) {
      card_idx = 0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      slot_idx = (HWND)0x0;
      SetWindowLongA(hwnd,4,0);
      match_count = (char *)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      match_count = (char *)GetWindowLongA(hwnd,8);
      if (match_count != (HANDLE)0x0) {
        Pic_DestroyDIBSection(match_count);
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar5 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      local_290 = (uint32_t)(hwnd != DAT_006b2e10);
      AppendMenuA(DAT_00538bcc,0,100,s_View_the_graveyard_00522284);
      val_4 = Ai_Subsystem_004b718a(local_a60,local_290);
      if (val_4 == 0) {
        EnableMenuItem(DAT_00538bcc,100,1);
      }
      AppendMenuA(DAT_00538bcc,0,0x65,s_View_the_out_of_play_cards_00522298);
      val_4 = Ai_Subsystem_004b722d(local_a60,local_290);
      if (val_4 == 0) {
        EnableMenuItem(DAT_00538bcc,0x65,1);
      }
      AppendMenuA(DAT_00538bcc,0,0x66,s_View_both_antes_005222b4);
      AppendMenuA(DAT_00538bcc,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_00538bcc,0,0x67,s_Help____005222c4);
      return 0;
    }
    if (uMsg == 0x111) {
      switch((uint32_t)wParam & 0xffff) {
      case 100:
        SendMessageA(hwnd,0x400,1,1);
        break;
      case 0x65:
        SendMessageA(hwnd,0x400,1,0);
        break;
      case 0x66:
        Pic_Subsystem_0044a839();
        break;
      case 0x67:
        local_f4 = 0x7e6;
        strcpy(local_1fc,&g_GameInstallDirectory);
        strcat(local_1fc,s__duel_hlp_00522278);
        WinHelpA(g_MainAppHwnd,local_1fc,1,local_f4);
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
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_a68 = GetMenuItemCount(DAT_00538bcc);
        while (local_a68 != 0) {
          DeleteMenu(DAT_00538bcc,0,0x400);
          local_a68 = local_a68 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_270 = 1;
      if (g_DuelArenaStatusFlags == 2) {
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
        TrackPopupMenu(DAT_00538bcc,2,local_26c.x,local_26c.y,0,hwnd,&local_264);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      wParam_00 = Pic_Subsystem_0044a7e1((uint32_t)(hwnd != DAT_006b2e10));
      if ((wParam_00 != 0xffffffff) && (g_DuelArenaStatusFlags == 2)) {
        SendMessageA(DAT_0069f744,0x401,wParam_00,0);
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
      if (wParam == (char *)0x0) {
        if (slot_idx != (HWND)0x0) {
          ReleaseCapture();
          Pic_Util_0044a7cc(slot_idx);
          slot_idx = (HWND)0x0;
          SetWindowLongA(hwnd,4,0);
        }
      }
      else {
        if (slot_idx == (HWND)0x0) {
          slot_idx = (HWND)UI_GraveyardListWndProc(hwnd,lParam);
        }
        SetWindowLongA(hwnd,4,(LONG)slot_idx);
        if (slot_idx != (HWND)0x0) {
          SetCapture(slot_idx);
        }
      }
      return 0;
    case 0x432:
      card_idx = GetWindowLongA(hwnd,0);
      local_e8 = Pic_Subsystem_0044a7e1((uint32_t)(hwnd != DAT_006b2e10));
      SendMessageA(hwnd,0x400,0,0);
      if (local_e8 != card_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_e0 = (char *)Pic_Subsystem_0044a7e1((uint32_t)(hwnd != DAT_006b2e10));
      local_e4 = wParam;
      if (wParam == local_e0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      if (hwnd == DAT_006b2e10) {
        strcpy(local_74,s_Your_00522260);
      }
      else {
        Ai_Subsystem_004b6f49(local_74);
      }
      sprintf(local_d8,s__s_graveyard_00522268,local_74);
      strcpy(wParam,local_d8);
      local_dc = Pic_Subsystem_0044a7e1((uint32_t)(hwnd != DAT_006b2e10));
      if ((local_dc != 0xffffffff) &&
         ((g_DuelArenaStatusFlags != 2 || (BVar3 = IsWindowVisible(DAT_0069f744), BVar3 != 0)))) {
        SendMessageA(DAT_0069f744,0x401,local_dc,0);
      }
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      match_count = (char *)GetWindowLongA(hwnd,8);
      if (match_count != (HGDIOBJ)0x0) {
        DeleteObject(match_count);
      }
      match_count = wParam;
      SetWindowLongA(hwnd,8,(LONG)wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}



/*
 * Decompiled function: UI_WndProc_00449fbb
 * Entry Point: 00449fbb
 * Size: 366 bytes
 */


LRESULT UI_WndProc_00449fbb(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam)

{
  POINT Point;
  LRESULT LVar1;
  tagPOINT card_idx;
  HWND slot_idx;
  
  if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_0044a00e:
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
    if (uMsg == 0x206) goto LAB_0044a00e;
    if (uMsg == 0x201) {
      SendMessageA(DAT_006b2e10,0x400,0,0);
      SendMessageA(DAT_006a4928,0x400,0,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
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
 * Decompiled function: UI_WndProc_0044a135
 * Entry Point: 0044a135
 * Size: 705 bytes
 */


LRESULT UI_WndProc_0044a135(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam)

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
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      hbr = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&target_idx,hbr);
      Palette_Subsystem_0049c7c7
                (g_HdcBackBuffer,&target_idx.left,(WPARAM *)(&DAT_006b3070 + slot_idx * 0x98),0,0x11,0)
      ;
      hdc = BeginPaint(hwnd,&local_58);
      if (hdc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(hdc);
        BitBlt(hdc,0,0,target_idx.right,target_idx.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_58);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
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
      LVar4 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x206) {
      slot_idx = GetWindowLongA(hwnd,0);
      if (g_DuelArenaStatusFlags == 2) {
        SendMessageA(DAT_0069f744,0x401,slot_idx,0);
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
      if (WVar3 != wParam) {
        slot_idx = wParam;
        SetWindowLongA(hwnd,0,wParam);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      slot_idx = GetWindowLongA(hwnd,0);
      if ((g_DuelArenaStatusFlags != 2) || (BVar1 = IsWindowVisible(DAT_0069f744), BVar1 != 0)) {
        SendMessageA(DAT_0069f744,0x401,slot_idx,0);
      }
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: UI_GraveyardListWndProc
 * Entry Point: 0044a402
 * Size: 970 bytes
 */


HWND UI_GraveyardListWndProc(HWND hwnd,int arg2)

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
  GetClientRect(g_MainAppHwnd,&local_24);
  player_idx.right = (local_24.right * 0x4b) / 100;
  player_idx.bottom = local_24.bottom;
  GetClientRect(hwnd,&local_24);
  local_2c = local_24.bottom;
  val_1 = (local_24.right * 0x3c) / 100;
  local_44 = 5;
  local_40 = 5;
  local_3c = (((player_idx.right - player_idx.left) + -10) - local_24.right) / val_1 + 1;
  local_28 = (uint32_t)(hwnd != DAT_006b2e10);
  local_30 = CreateWindowExA(0,s_ExpandedGraveyard_005222f0,
                             s_Graveyard_list_005222cc + ((arg2 != 0) - 1 & 0x10),0x80000000,0,0,0,0
                             ,g_MainAppHwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
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
      local_820 = Ai_Subsystem_004b722d(local_814,local_28);
    }
    else {
      local_820 = Ai_Subsystem_004b718a(local_814,local_28);
    }
    local_82c = 0;
    local_818 = local_820;
    while (local_818 = local_818 + -1, -1 < local_818) {
      local_34 = CreateWindowExA(0,s_GraveyardCards_00522328,
                                 s_Graveyard_card_00522304 + ((arg2 != 0) - 1 & 0x10),0x54000000,
                                 local_830,local_38,local_24.right,local_2c,local_30,(HMENU)0x1,
                                 g_AppHInstance,(LPVOID)0x0);
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
      GetClientRect(g_MainAppHwnd,&local_24);
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
 * Decompiled function: Pic_Util_0044a7cc
 * Entry Point: 0044a7cc
 * Size: 21 bytes
 */


void Pic_Util_0044a7cc(HWND hwnd)

{
  DestroyWindow(hwnd);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044a7e1
 * Entry Point: 0044a7e1
 * Size: 83 bytes
 */


int32_t Pic_Subsystem_0044a7e1(int player_id)

{
  int32_t uval_1;
  int local_7d8;
  uint8_t local_7d4 [2000];
  
  local_7d8 = Ai_Subsystem_004b718a(local_7d4,player);
  if (local_7d8 == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = *(int32_t *)(local_7d4 + local_7d8 * 4 + -4);
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_0044a839
 * Entry Point: 0044a839
 * Size: 41 bytes
 */


void Pic_Subsystem_0044a839(void)

{
  DialogBoxParamA(g_AppHInstance,(LPCSTR)0xeb,g_MainAppHwnd,UI_AnteDisplayWndProc,0);
  return;
}



/*
 * Decompiled function: UI_AnteDisplayWndProc
 * Entry Point: 0044a862
 * Size: 2560 bytes
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
  char local_dc [200];
  tagRECT player_idx;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_33c = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      GetClientRect(hwnd,&local_324);
      local_338 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_33c,local_338);
      SetTextColor(local_33c,0);
      SetBkMode(local_33c,1);
      if (DAT_00538bc0 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_33c,&local_324,hbr);
      }
      else {
        FUN_004f3b5f((int)local_33c,(int)&local_324,DAT_00538bc0);
      }
      ptVar10 = &local_334;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      GetWindowRect(pHVar4,ptVar10);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_334,2);
      FUN_004f3b5f((int)local_33c,(int)&local_334,DAT_00538bc8);
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
      FUN_004f3b5f((int)local_33c,(int)&local_334,DAT_00538bc8);
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
        GDI_RealizeAndFlushPalette_Magic(local_3a0);
        Ai_Subsystem_004b73ce((int)local_420,&local_344,(int)local_3e0,&local_35c);
        if (local_344 != 0) {
          for (local_358 = 0; local_358 < local_344; local_358 = local_358 + 1) {
            Pic_Subsystem_0044b26c(&local_354,hwnd,1,local_358);
            local_340 = local_420[local_358];
            Palette_Subsystem_0049c7c7
                      (local_3a0,&local_354.left,(WPARAM *)(&DAT_006b3070 + local_340 * 0x98),0,0x12
                       ,0);
          }
        }
        if (local_35c != 0) {
          for (local_358 = 0; local_358 < local_35c; local_358 = local_358 + 1) {
            Pic_Subsystem_0044b26c(&local_354,hwnd,0,local_358);
            local_340 = local_3e0[local_358];
            Palette_Subsystem_0049c7c7
                      (local_3a0,&local_354.left,(WPARAM *)(&DAT_006b3070 + local_340 * 0x98),0,0x12
                       ,0);
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
      sprintf(local_1e4,s__s_WINBK_Ante_pic_00522338,&g_AiCurrentChoiceIndex);
      DAT_00538bc0 = (HANDLE)Pic_LoadKimPicture(local_1e4);
      sprintf(local_1e4,s__s_WINBK_AnteLabel_pic_0052234c,&g_AiCurrentChoiceIndex);
      DAT_00538bc8 = (HANDLE)Pic_LoadKimPicture(local_1e4);
      DAT_00538bc4 = 0;
      Ai_Subsystem_004b6f49(local_dc);
      strcat(local_dc,s_ante__00522364);
      SetDlgItemTextA(hwnd,0x43a,local_dc);
      strcpy(local_dc,s_Your_ante__0052236c);
      SetDlgItemTextA(hwnd,0x43b,local_dc);
      local_1fc = GetDC(hwnd);
      GDI_RealizeAndFlushPalette_Magic(local_1fc);
      local_1f0 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x43a,0x31,0,0);
      SelectObject(local_1fc,local_1f0);
      GetDlgItemTextA(hwnd,0x43a,local_dc,200);
      psizl = &local_1ec;
      c = strlen(local_dc);
      GetTextExtentPoint32A(local_1fc,local_dc,c,psizl);
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
LAB_0044ab14:
      Pic_DestroyDIBSection(DAT_00538bc0);
      Pic_DestroyDIBSection(DAT_00538bc8);
      EndDialog(hwnd,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_2a8 = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      local_2b0 = lParam;
      local_2ac = GetDlgCtrlID(lParam);
      SetBkMode(local_2a8,1);
      SetTextColor(local_2a8,DAT_00538bc4);
      buf_ptr_3 = GetStockObject(5);
      return buf_ptr_3;
    }
    if (uMsg == 0x111) goto LAB_0044ab14;
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      buf_ptr_3 = (HGDIOBJ)GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return buf_ptr_3;
    }
    if (uMsg != 0x200) {
      if (uMsg == 0x201) {
        Pic_DestroyDIBSection(DAT_00538bc0);
        Pic_DestroyDIBSection(DAT_00538bc8);
        EndDialog(hwnd,0);
        return (HGDIOBJ)0x1;
      }
      if (uMsg != 0x204) {
        return (HGDIOBJ)0x0;
      }
    }
    Ai_Subsystem_004b73ce((int)local_2a4,&local_204,(int)local_264,&local_21c);
    local_224 = (uint32_t)lParam & 0xffff;
    local_220 = (uint32_t)lParam >> 0x10;
    if (((uMsg == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((uMsg == 0x204 && (g_DuelArenaStatusFlags == 2)))) {
      local_200 = 0xffffffff;
      if (local_21c != 0) {
        while ((local_218 = local_21c + -1, -1 < local_218 && (local_200 == 0xffffffff))) {
          Pic_Subsystem_0044b26c(&local_214,hwnd,0,local_218);
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
          Pic_Subsystem_0044b26c(&local_214,hwnd,1,local_218);
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
        SendMessageA(DAT_0069f744,0x401,local_200,0);
      }
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: Pic_Subsystem_0044b26c
 * Entry Point: 0044b26c
 * Size: 496 bytes
 */


void Pic_Subsystem_0044b26c(LPRECT player,HWND hwnd,int width,int height)

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
  
  Ai_Subsystem_004b73ce((int)local_c4,&target_idx,(int)local_84,&color_idx);
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
      SetRect(player,0,0,0,0);
    }
    else {
      for (local_40 = (local_44 * 0x3c) / 100;
          (player_idx.right - local_3c.left < (color_idx + -1) * local_40 + local_44 &&
          ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
      }
      CopyRect(player,&local_2c);
      OffsetRect(player,local_40 * height,0);
    }
  }
  else if ((target_idx < 1) || (target_idx <= height)) {
    SetRect(player,0,0,0,0);
  }
  else {
    for (local_40 = (local_44 * 0x3c) / 100;
        (player_idx.right - local_3c.left < (target_idx + -1) * local_40 + local_44 &&
        ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
    }
    CopyRect(player,&local_3c);
    OffsetRect(player,local_40 * height,0);
  }
  return;
}



/*
 * Decompiled function: Font_LoadCustomFonts
 * Entry Point: 0044b460
 * Size: 985 bytes
 */


void Font_LoadCustomFonts(void)

{
  DWORD DVar1;
  int32_t uval_2;
  int val_3;
  char *pcVar4;
  char *pcVar5;
  int val_6;
  int val_7;
  int32_t card_idx;
  int match_count;
  
  DVar1 = GetTickCount();
  srand(DVar1);
  uval_2 = Mem_AllocOrFree_0050ce90(s_misc_exe_005239f4,0);
  Mem_AllocOrFree_0050ce80(uval_2);
  uval_2 = Mem_AllocOrFree_0050ce90(s_mgraphic_exe_00523a0c,0x523a00);
  Mem_AllocOrFree_0050ce80(uval_2);
  uval_2 = Mem_AllocOrFree_0050ce90(s_nsound_cvl_00523a1c,0);
  Mem_AllocOrFree_0050ce80(uval_2);
  if (g_AiManaColorCost_Red == 0x280) {
    DVar1 = 1;
    val_6 = 700;
    pcVar5 = s_MagicMedieval_00523a28;
    pcVar4 = s_magim____ttf_00523a38;
    val_3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,val_3,pcVar4,pcVar5,val_6,DVar1);
    FUN_0050f1e0(1,0x10,s_tt0300m__ttf_00523a58,s_Zurich_Cn_BT_00523a48,400,0);
  }
  else if (g_AiManaColorCost_Red == 800) {
    DVar1 = 1;
    val_6 = 700;
    pcVar5 = s_MagicMedieval_00523a68;
    pcVar4 = s_magim____ttf_00523a78;
    val_3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,val_3,pcVar4,pcVar5,val_6,DVar1);
    FUN_0050f1e0(1,0x10,s_tt0127m__ttf_00523a98,s_Benguiat_Bk_BT_00523a88,100,0);
  }
  else if (g_AiManaColorCost_Red == 0x400) {
    DVar1 = 1;
    val_6 = 700;
    pcVar5 = s_MagicMedieval_00523aa8;
    pcVar4 = s_magim____ttf_00523ab8;
    val_3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,val_3,pcVar4,pcVar5,val_6,DVar1);
    DVar1 = 0;
    val_6 = 100;
    pcVar5 = s_Benguiat_Bk_BT_00523ac8;
    pcVar4 = s_tt0127m__ttf_00523ad8;
    val_3 = Ai_Util_004c3bc4(0xc);
    FUN_0050f1e0(1,val_3,pcVar4,pcVar5,val_6,DVar1);
    DVar1 = 0;
    val_6 = 100;
    pcVar5 = s_Benguiat_Bk_BT_00523ae8;
    pcVar4 = s_tt0127m__ttf_00523af8;
    val_3 = Ai_Util_004c3bc4(0x11);
    FUN_0050f1e0(4,val_3,pcVar4,pcVar5,val_6,DVar1);
  }
  thunk_FUN_0050cef0(0);
  Catalog_LoadPaletteMap(s_todpal_tr_00523b08,(char *)0x0);
  for (match_count = 0; match_count < 3; match_count = match_count + 1) {
    if ((match_count == 1) && (*(int *)(g_ScreenSurfaces + 0x20) < 0x401)) {
      card_idx = Memory_AllocateVirtualPage(1,0x400,800,8);
    }
    else {
      card_idx = Mem_AllocOrFree_0050cec0(match_count);
    }
    FUN_0050d370(match_count,card_idx);
  }
  val_7 = 8;
  val_3 = Ai_Util_004c3bc4(0x1e0);
  val_6 = Ai_Util_004c3bc4(0x148);
  val_6 = (val_3 - val_6) + 3;
  val_3 = Ai_Util_004c3bc4(0x280);
  uval_2 = Memory_AllocateVirtualPage(3,val_3,val_6,val_7);
  FUN_0050d370(3,uval_2);
  val_7 = 8;
  val_3 = Ai_Util_004c3bc4(0x148);
  val_6 = Ai_Util_004c3bc4(0x40);
  uval_2 = Memory_AllocateVirtualPage(5,val_6,val_3,val_7);
  FUN_0050d370(5,uval_2);
  uval_2 = Ai_Util_004c3bc4(0x280);
  *(int32_t *)(PTR_DAT_005174bc + 0xc) = uval_2;
  *(int32_t *)(g_DisplaySurfaceWork + 0xc) = *(int32_t *)(PTR_DAT_005174bc + 0xc);
  *(int32_t *)(g_DisplaySurfaceBackBuffer + 0xc) = *(int32_t *)(g_DisplaySurfaceWork + 0xc);
  *(int32_t *)(g_DisplaySurfaceScreen + 0xc) = *(int32_t *)(g_DisplaySurfaceBackBuffer + 0xc);
  uval_2 = Ai_Util_004c3bc4(0x1e0);
  *(int32_t *)(g_DisplaySurfaceWork + 0xc) = uval_2;
  *(int32_t *)(g_DisplaySurfaceBackBuffer + 0x10) = *(int32_t *)(g_DisplaySurfaceWork + 0xc);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x10) =
       *(int32_t *)(g_DisplaySurfaceBackBuffer + 0x10);
  val_3 = Ai_Util_004c3bc4(0x1e0);
  val_6 = Ai_Util_004c3bc4(0x148);
  *(int *)(PTR_DAT_005174bc + 0x10) = val_3 - val_6;
  uval_2 = Ai_Util_004c3bc4(0x148);
  *(int32_t *)(PTR_DAT_005174e4 + 0x10) = uval_2;
  uval_2 = Ai_Util_004c3bc4(0x40);
  *(int32_t *)(PTR_DAT_005174e4 + 0xc) = uval_2;
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
  FUN_0050d4e0(0);
  DAT_005239ec = Mem_AllocOrFree_005121d0();
  do {
    Glue_Subsystem_004e73a0();
  } while (DAT_006fe3f0 == 0);
  FUN_0050f350(5);
  if (DAT_005239ec != 0) {
    Mem_AllocOrFree_005121e0();
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}



/*
 * Decompiled function: Pic_Util_0044b839
 * Entry Point: 0044b839
 * Size: 18 bytes
 */


int32_t Pic_Util_0044b839(void)

{
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044b84b
 * Entry Point: 0044b84b
 * Size: 95 bytes
 */


void Pic_Subsystem_0044b84b(void)

{
  uint32_t uval_1;
  
  if (DAT_005239ec == 0) {
    g_MouseScreenCoordY = 0;
    g_MouseScreenCoordX = 0;
    g_CombatAttackerSlotIndex = 0;
  }
  else {
    uval_1 = Mem_AllocOrFree_00512210();
    g_CombatAttackerSlotIndex = uval_1 | g_MouseCursorButtonState;
    g_MouseScreenCoordX = g_MouseCursorX;
    g_MouseScreenCoordY = g_MouseCursorY;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044b8aa
 * Entry Point: 0044b8aa
 * Size: 48 bytes
 */


void Pic_Subsystem_0044b8aa(void)

{
  DAT_0067f378 = DAT_0067f378 + 1;
  if ((DAT_005239ec != 0) && (DAT_0067f378 == 1)) {
    FUN_005121f0();
  }
  return;
}



/*
 * Decompiled function: UI_PrepareCombatViewport
 * Entry Point: 0044b8da
 * Size: 48 bytes
 */


void UI_PrepareCombatViewport(void)

{
  if ((DAT_005239ec != 0) && (DAT_0067f378 == 1)) {
    FUN_00512200();
  }
  DAT_0067f378 = DAT_0067f378 + -1;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044b90a
 * Entry Point: 0044b90a
 * Size: 57 bytes
 */


void Pic_Subsystem_0044b90a(char *arg1,int32_t arg2)

{
  Mem_AllocOrFree_00510e60(arg1,(short *)&DAT_00627020);
  Pic_Util_0044b943(arg2,&DAT_00627020);
  return;
}



/*
 * Decompiled function: Pic_Util_0044b943
 * Entry Point: 0044b943
 * Size: 23 bytes
 */


void Pic_Util_0044b943(int32_t arg1,short *arg2)

{
  FUN_0050e8b0(arg2);
  return;
}



/*
 * Decompiled function: Pic_Util_0044b95a
 * Entry Point: 0044b95a
 * Size: 18 bytes
 */


int32_t Pic_Util_0044b95a(void)

{
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044b96c
 * Entry Point: 0044b96c
 * Size: 81 bytes
 */


int32_t Pic_Subsystem_0044b96c(int player_id)

{
  int val_1;
  
  if ((player != 0) && (g_IsAiThinking != 1)) {
    Mem_AllocOrFree_005016f9();
    do {
      val_1 = Mem_AllocOrFree_00501721();
    } while (val_1 < DAT_0052244c * player);
  }
  return 0;
}



/*
 * Decompiled function: UI_RegisterClass_0044b9c0
 * Entry Point: 0044b9c0
 * Size: 195 bytes
 */


bool UI_RegisterClass_0044b9c0(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_PlayerHandCardWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x20;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_00538bf8 = CreatePopupMenu();
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00523b14,0);
  DAT_00538bfc = CreateFontIndirectA(lplf);
  DAT_00538bf0 = 0x10000bf;
  DAT_00538bf4 = 0x10000c9;
  return AVar1 != 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044ba83
 * Entry Point: 0044ba83
 * Size: 81 bytes
 */


void Pic_Subsystem_0044ba83(void)

{
  if (DAT_00538bf8 != (HMENU)0x0) {
    DestroyMenu(DAT_00538bf8);
  }
  DAT_00538bf8 = (HMENU)0x0;
  if (DAT_00538bfc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538bfc);
  }
  DAT_00538bfc = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_PlayerHandCardWndProc
 * Entry Point: 0044bad4
 * Size: 5255 bytes
 */


LRESULT UI_PlayerHandCardWndProc(HWND hwnd,uint32_t y,int32_t *arg_3,LONG *arg_4)

{
  LONG LVar1;
  int val_2;
  int val_3;
  HBRUSH hbr;
  LRESULT LVar4;
  int local_394;
  tagPOINT local_390;
  tagRECT local_388;
  int local_378;
  int local_374;
  CHAR local_370 [100];
  tagRECT local_30c;
  HDC local_2fc;
  tagPAINTSTRUCT local_2f8;
  int local_2b8;
  tagRECT local_2b4;
  int local_2a4;
  tagRECT local_2a0;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  uint32_t local_274;
  uint32_t local_270;
  int local_26c;
  int local_268;
  int local_264;
  tagRECT local_260;
  tagRECT local_250;
  char local_240 [264];
  ULONG_PTR local_138;
  int local_134;
  int *local_130;
  LRESULT local_12c;
  int local_128;
  int *local_124;
  int local_120;
  int local_11c;
  HWND local_118;
  int local_114;
  char local_110 [52];
  int local_dc;
  char local_d8 [52];
  int *local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  char local_94 [52];
  int local_60;
  HWND local_5c;
  int *local_58;
  int local_54;
  int32_t *local_50;
  int32_t *local_4c;
  LONG *local_48;
  LONG *local_44;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int32_t *local_2c;
  int local_28;
  LONG local_24;
  int loop_idx;
  LONG color_idx;
  LONG target_idx;
  LONG player_idx;
  void *card_idx;
  int match_count;
  int32_t *slot_idx;
  
  if (y < 0x10) {
    if (y == 0xf) {
      color_idx = GetWindowLongA(hwnd,8);
      target_idx = GetWindowLongA(hwnd,0xc);
      player_idx = GetWindowLongA(hwnd,0x10);
      local_24 = GetWindowLongA(hwnd,0x14);
      slot_idx = (int32_t *)GetWindowLongA(hwnd,0x18);
      Pic_Subsystem_0044d58f
                (g_PlayerGoldCoins,g_PlayerAmuletGems,color_idx,target_idx,player_idx,local_24,&local_2a4,&local_290
                 ,&local_378,&local_374);
      GetClientRect(hwnd,&local_30c);
      local_288 = local_30c.top + local_2a4;
      local_280 = local_30c.bottom - local_290;
      local_28c = local_30c.left + local_378;
      local_284 = local_30c.right - local_378;
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_2b8 = SaveDC(g_HdcBackBuffer);
      hbr = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_30c,hbr);
      Pic_Subsystem_0044d31a
                ((int)g_HdcBackBuffer,&local_30c.left,&local_28c,local_374,color_idx,target_idx,
                 player_idx,local_24,slot_idx);
      SetMapMode(g_HdcBackBuffer,8);
      SetWindowExtEx(g_HdcBackBuffer,local_30c.right - local_30c.left,0x14,(LPSIZE)0x0);
      SetViewportExtEx(g_HdcBackBuffer,local_30c.right - local_30c.left,(local_2a4 * 0x30) / 100,
                       (LPSIZE)0x0);
      SelectObject(g_HdcBackBuffer,DAT_00538bfc);
      GetWindowTextA(hwnd,local_370,100);
      SetBkMode(g_HdcBackBuffer,1);
      SetRect(&local_2b4,local_30c.left,local_30c.top,local_30c.right,local_288);
      DPtoLP(g_HdcBackBuffer,(LPPOINT)&local_2b4,2);
      OffsetRect(&local_2b4,2,2);
      SetTextColor(g_HdcBackBuffer,DAT_00538bf4);
      DrawTextA(g_HdcBackBuffer,local_370,-1,&local_2b4,0x25);
      OffsetRect(&local_2b4,-2,-2);
      SetTextColor(g_HdcBackBuffer,DAT_00538bf0);
      DrawTextA(g_HdcBackBuffer,local_370,-1,&local_2b4,0x25);
      RestoreDC(g_HdcBackBuffer,local_2b8);
      local_2fc = BeginPaint(hwnd,&local_2f8);
      if (local_2fc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_2fc);
        GetClientRect(hwnd,&local_2a0);
        BitBlt(local_2fc,0,0,local_2a0.right,local_2a0.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_2f8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return 0;
    }
    if (y == 1) {
      loop_idx = 0;
      SetWindowLongA(hwnd,4,0);
      card_idx = malloc(200);
      SetWindowLongA(hwnd,0,(LONG)card_idx);
      color_idx = 0;
      target_idx = 0;
      player_idx = 0;
      local_24 = 0;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,0xc,target_idx);
      SetWindowLongA(hwnd,0x10,player_idx);
      SetWindowLongA(hwnd,0x14,local_24);
      slot_idx = (int32_t *)0x0;
      SetWindowLongA(hwnd,0x18,0);
      match_count = 0xffffffff;
      SetWindowLongA(hwnd,0x1c,-1);
      if (card_idx == (void *)0x0) {
        return -1;
      }
      Pic_Subsystem_0044cfe4(hwnd);
      return 0;
    }
    if (y == 2) {
      card_idx = (void *)GetWindowLongA(hwnd,0);
      free(card_idx);
      slot_idx = (int32_t *)GetWindowLongA(hwnd,0x18);
      if (slot_idx != (HANDLE)0x0) {
        Pic_DestroyDIBSection(slot_idx);
      }
      return 0;
    }
  }
  else if (y < 0x15) {
    if (y == 0x14) {
      return 1;
    }
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
  }
  else if (y < 0x118) {
    if (y == 0x117) {
      AppendMenuA(DAT_00538bf8,0,100,s_Help____00523b48);
      return 0;
    }
    if (y == 0x111) {
      if (((uint32_t)arg_3 & 0xffff) == 100) {
        local_138 = 0x7e3;
        strcpy(local_240,&g_GameInstallDirectory);
        strcat(local_240,s__duel_hlp_00523b3c);
        WinHelpA(g_MainAppHwnd,local_240,1,local_138);
      }
      return 0;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
      GetWindowRect(hwnd,&local_260);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_250);
      val_2 = abs(local_250.top - local_260.top);
      val_3 = abs(local_250.left - local_260.left);
      if (val_2 + val_3 < 5) {
        local_274 = (uint32_t)arg_4 & 0xffff;
        local_270 = (uint32_t)arg_4 >> 0x10;
        card_idx = (void *)GetWindowLongA(hwnd,0);
        loop_idx = GetWindowLongA(hwnd,4);
        match_count = GetWindowLongA(hwnd,0x1c);
        color_idx = GetWindowLongA(hwnd,8);
        target_idx = GetWindowLongA(hwnd,0xc);
        player_idx = GetWindowLongA(hwnd,0x10);
        local_24 = GetWindowLongA(hwnd,0x14);
        if ((1 < loop_idx) &&
           (Pic_Subsystem_0044d58f
                      (g_PlayerGoldCoins,g_PlayerAmuletGems,color_idx,target_idx,player_idx,local_24,&local_26c,
                       &local_268,&local_27c,&local_278), (int)local_270 < local_26c)) {
          GetClientRect(hwnd,&local_250);
          if ((int)local_274 < (local_250.right * 0x14) / 100) {
            local_264 = loop_idx;
            if (0 < match_count) {
              local_264 = match_count;
            }
            local_264 = local_264 + -1;
            SendMessageA(hwnd,0x400,*(WPARAM *)((int)card_idx + local_264 * 4),0);
          }
          else if ((local_250.right * 0x50) / 100 < (int)local_274) {
            if (match_count < loop_idx + -1) {
              local_264 = match_count + 1;
            }
            else {
              local_264 = 0;
            }
            SendMessageA(hwnd,0x400,*(WPARAM *)((int)card_idx + local_264 * 4),0);
          }
        }
      }
      return 0;
    }
    if (y == 0x11f) {
      if (((uint32_t)arg_3 >> 0x10 == 0xffff) && (arg_4 == (LONG *)0x0)) {
        local_394 = GetMenuItemCount(DAT_00538bf8);
        while (local_394 != 0) {
          DeleteMenu(DAT_00538bf8,0,0x400);
          local_394 = local_394 + -1;
        }
      }
      return 0;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      LVar4 = GDI_RealizePaletteTree_Magic(hwnd,y,(HWND)arg_3,arg_4);
      return LVar4;
    }
    if (y == 0x204) {
      local_390.x = (uint32_t)arg_4 & 0xffff;
      local_390.y = (uint32_t)arg_4 >> 0x10;
      ClientToScreen(hwnd,&local_390);
      SetRect(&local_388,local_390.x,local_390.y,local_390.x + 1,local_390.y + 1);
      TrackPopupMenu(DAT_00538bf8,2,local_390.x,local_390.y,0,hwnd,&local_388);
      return 0;
    }
  }
  else {
    switch(y) {
    case 0x400:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      local_50 = arg_3;
      if (arg_3 == (int32_t *)0x0) {
        return 0;
      }
      for (local_54 = 0; local_54 < loop_idx; local_54 = local_54 + 1) {
        if (*(int32_t **)((int)card_idx + local_54 * 4) == local_50) {
          match_count = local_54;
          SetWindowLongA(hwnd,0x1c,local_54);
          Pic_Subsystem_0044cfe4(hwnd);
        }
      }
      return 0;
    case 0x40a:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      match_count = GetWindowLongA(hwnd,0x1c);
      if (0x31 < loop_idx) {
        return 0;
      }
      local_58 = arg_3;
      local_5c = (HWND)SendMessageA(hwnd,0x40f,(WPARAM)arg_3,0);
      if (local_5c == (HWND)0x0) {
        local_5c = CreateWindowExA(0,s_MAGICGAME_CardClass_00523b28,s_Hand_Card_00523b1c,0x54000000,
                                   0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,local_58);
        if (local_5c != (HWND)0x0) {
          *(HWND *)((int)card_idx + loop_idx * 4) = local_5c;
          loop_idx = loop_idx + 1;
          SetWindowLongA(hwnd,4,loop_idx);
          val_2 = loop_idx;
          if (loop_idx + -1 == match_count + 1) {
            match_count = loop_idx + -1;
            SetWindowLongA(hwnd,0x1c,match_count);
          }
          else {
            while (local_60 = val_2 + -1, match_count + 1 < local_60) {
              *(int32_t *)((int)card_idx + local_60 * 4) =
                   *(int32_t *)((int)card_idx + -4 + local_60 * 4);
              val_2 = local_60;
            }
            *(HWND *)((int)card_idx + 4 + match_count * 4) = local_5c;
            match_count = match_count + 1;
            SetWindowLongA(hwnd,0x1c,match_count);
          }
          Pic_Subsystem_0044cfe4(hwnd);
          UI_DrawPlayerHandWindow(local_94,hwnd,loop_idx);
          return loop_idx;
        }
        return 0;
      }
      val_2 = Ai_Subsystem_004b5cbb(*local_58,local_58[1]);
      val_2 = FUN_0046bbab(local_5c,val_2);
      if (val_2 != 0) {
        return loop_idx;
      }
      SendMessageA(hwnd,0x40b,(WPARAM)local_58,0);
      SendMessageA(hwnd,0x40a,(WPARAM)local_58,0);
      return loop_idx;
    case 0x40b:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      match_count = GetWindowLongA(hwnd,0x1c);
      local_a4 = arg_3;
      local_98 = 0;
      local_9c = 0;
      while ((local_9c < loop_idx && (local_98 == 0))) {
        val_2 = FUN_0046bb29(*(HWND *)((int)card_idx + local_9c * 4),local_a4);
        if (val_2 != 0) {
          local_98 = 1;
          DestroyWindow(*(HWND *)((int)card_idx + local_9c * 4));
          loop_idx = loop_idx + -1;
          SetWindowLongA(hwnd,4,loop_idx);
          for (local_a0 = local_9c; local_a0 < loop_idx; local_a0 = local_a0 + 1) {
            *(int32_t *)((int)card_idx + local_a0 * 4) =
                 *(int32_t *)((int)card_idx + 4 + local_a0 * 4);
          }
          if (local_9c == match_count) {
            if (match_count == 0) {
              match_count = loop_idx;
            }
            match_count = match_count + -1;
            SetWindowLongA(hwnd,0x1c,match_count);
          }
          else {
            if (match_count == 0) {
              match_count = loop_idx;
            }
            match_count = match_count + -1;
            SetWindowLongA(hwnd,0x1c,match_count);
          }
          UI_DrawPlayerHandWindow(local_d8,hwnd,loop_idx);
          UpdateWindow(hwnd);
        }
        local_9c = local_9c + 1;
      }
      if (local_98 == 0) {
        return 0;
      }
      Pic_Subsystem_0044cfe4(hwnd);
      return local_98;
    case 0x40c:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      for (local_dc = 0; local_dc < loop_idx; local_dc = local_dc + 1) {
        DestroyWindow(*(HWND *)((int)card_idx + local_dc * 4));
      }
      loop_idx = 0;
      SetWindowLongA(hwnd,4,0);
      match_count = 0xffffffff;
      SetWindowLongA(hwnd,0x1c,-1);
      Pic_Subsystem_0044cfe4(hwnd);
      UI_DrawPlayerHandWindow(local_110,hwnd,loop_idx);
      return 0;
    case 0x40d:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      local_124 = arg_3;
      local_114 = 0;
      local_11c = 0;
      while( true ) {
        if (loop_idx <= local_11c) {
          return local_114;
        }
        if (local_114 != 0) break;
        val_2 = FUN_0046bb29(*(HWND *)((int)card_idx + local_11c * 4),local_124);
        if (val_2 != 0) {
          local_114 = 1;
          local_118 = *(HWND *)((int)card_idx + local_11c * 4);
          BringWindowToTop(local_118);
          for (local_120 = local_11c; local_120 < loop_idx + -1; local_120 = local_120 + 1) {
            *(int32_t *)((int)card_idx + local_120 * 4) =
                 *(int32_t *)((int)card_idx + 4 + local_120 * 4);
          }
          *(HWND *)((int)card_idx + -4 + loop_idx * 4) = local_118;
        }
        local_11c = local_11c + 1;
      }
      return local_114;
    case 0x40e:
    case 0x40f:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      local_130 = arg_3;
      local_128 = 0;
      local_134 = 0;
      while ((local_134 < loop_idx && (local_128 == 0))) {
        val_2 = FUN_0046bb29(*(HWND *)((int)card_idx + local_134 * 4),local_130);
        if (val_2 != 0) {
          local_128 = 1;
          if (y == 0x40e) {
            local_12c = FUN_0046bc2f(*(HWND *)((int)card_idx + local_134 * 4));
          }
          else {
            local_12c = *(LRESULT *)((int)card_idx + local_134 * 4);
          }
        }
        local_134 = local_134 + 1;
      }
      if (local_128 != 0) {
        return local_12c;
      }
      if (y == 0x40e) {
        return -1;
      }
      return 0;
    case 0x432:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      for (local_30 = 0; local_30 < loop_idx; local_30 = local_30 + 1) {
        SendMessageA(*(HWND *)((int)card_idx + local_30 * 4),0x432,0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      local_2c = arg_3;
      for (local_28 = 0; local_28 < loop_idx; local_28 = local_28 + 1) {
        val_2 = FUN_0046bbab(*(HWND *)((int)card_idx + local_28 * 4),(int)local_2c);
        if (val_2 != 0) {
          InvalidateRect(*(HWND *)((int)card_idx + local_28 * 4),(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x435:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      for (local_34 = 0; local_34 < loop_idx; local_34 = local_34 + 1) {
        InvalidateRect(*(HWND *)((int)card_idx + local_34 * 4),(RECT *)0x0,0);
      }
      return 0;
    case 0x436:
      card_idx = (void *)GetWindowLongA(hwnd,0);
      loop_idx = GetWindowLongA(hwnd,4);
      local_40 = arg_3;
      local_44 = arg_4;
      if (arg_3 == (int32_t *)0x0) {
        return 0;
      }
      local_38 = 0;
      local_3c = 0;
      while ((local_3c < loop_idx && (local_38 == 0))) {
        val_2 = FUN_0046bb29(*(HWND *)((int)card_idx + local_3c * 4),local_40);
        if (val_2 != 0) {
          local_38 = 1;
          if (local_44 == (LONG *)0x0) {
            InvalidateRect(*(HWND *)((int)card_idx + local_3c * 4),(RECT *)0x0,0);
          }
          else {
            SendMessageA(*(HWND *)((int)card_idx + local_3c * 4),0x432,0,0);
          }
        }
        local_3c = local_3c + 1;
      }
      return 0;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,0x18);
      return LVar1;
    case 0x439:
      local_4c = arg_3;
      local_48 = arg_4;
      slot_idx = (int32_t *)GetWindowLongA(hwnd,0x18);
      if (slot_idx != (HGDIOBJ)0x0) {
        DeleteObject(slot_idx);
      }
      slot_idx = local_4c;
      color_idx = *local_48;
      target_idx = local_48[1];
      player_idx = local_48[2];
      local_24 = local_48[3];
      SetWindowLongA(hwnd,8,color_idx);
      SetWindowLongA(hwnd,0xc,target_idx);
      SetWindowLongA(hwnd,0x10,player_idx);
      SetWindowLongA(hwnd,0x14,local_24);
      SetWindowLongA(hwnd,0x18,(LONG)slot_idx);
      Pic_Subsystem_0044cfe4(hwnd);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,y,(WPARAM)arg_3,(LPARAM)arg_4);
  return LVar4;
}



/*
 * Decompiled function: Pic_Subsystem_0044cfe4
 * Entry Point: 0044cfe4
 * Size: 822 bytes
 */


void Pic_Subsystem_0044cfe4(HWND hwnd)

{
  int local_58;
  int local_54;
  int local_50;
  LONG local_4c;
  LONG local_48;
  LONG local_44;
  LONG local_40;
  LONG local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  HWND local_28;
  LONG local_24;
  int loop_idx;
  int color_idx;
  LONG target_idx;
  int player_idx;
  LONG card_idx;
  int match_count;
  int slot_idx;
  
  color_idx = 8;
  local_48 = GetWindowLongA(hwnd,4);
  local_24 = GetWindowLongA(hwnd,0);
  local_44 = GetWindowLongA(hwnd,8);
  local_40 = GetWindowLongA(hwnd,0xc);
  local_3c = GetWindowLongA(hwnd,0x10);
  local_4c = GetWindowLongA(hwnd,0x14);
  card_idx = GetWindowLongA(hwnd,0x18);
  target_idx = GetWindowLongA(hwnd,0x1c);
  Pic_Subsystem_0044d58f
            (g_PlayerGoldCoins,g_PlayerAmuletGems,local_44,local_40,local_3c,local_4c,&player_idx,&slot_idx,
             &local_58,&local_54);
  if ((hwnd == g_AiLookaheadTreeRoot) || ((g_AiDuelTurnState == hwnd && (DAT_00695e90 != 0)))) {
    loop_idx = color_idx;
    if (local_48 <= color_idx) {
      loop_idx = local_48;
    }
    local_38 = local_54 * 2 + local_58 * 2 + g_PlayerGoldCoins;
    if (local_48 == 0) {
      match_count = slot_idx + player_idx;
    }
    else {
      match_count = (loop_idx + -1) * DAT_006ff67c + slot_idx + player_idx + g_PlayerAmuletGems;
    }
    if (0 < local_48) {
      local_2c = local_54 + local_58;
      local_30 = (match_count - slot_idx) - g_PlayerAmuletGems;
      local_34 = target_idx;
      local_28 = (HWND)0x0;
      for (local_50 = 1; local_50 <= loop_idx; local_50 = local_50 + 1) {
        MoveWindow(*(HWND *)(local_24 + local_34 * 4),local_2c,local_30,g_PlayerGoldCoins,g_PlayerAmuletGems,1)
        ;
        if (local_28 == (HWND)0x0) {
          BringWindowToTop(*(HWND *)(local_24 + local_34 * 4));
        }
        else {
          SetWindowPos(*(HWND *)(local_24 + local_34 * 4),local_28,0,0,0,0,3);
        }
        local_28 = *(HWND *)(local_24 + local_34 * 4);
        if (local_34 == 0) {
          local_34 = local_48;
        }
        local_34 = local_34 + -1;
        local_30 = local_30 - DAT_006ff67c;
      }
      for (local_50 = loop_idx; local_50 < local_48; local_50 = local_50 + 1) {
        MoveWindow(*(HWND *)(local_24 + local_34 * 4),-1,-1,0,0,1);
        if (local_34 == 0) {
          local_34 = local_48;
        }
        local_34 = local_34 + -1;
      }
    }
    UpdateWindow(hwnd);
    SetWindowPos(hwnd,(HWND)0x0,0,0,local_38,match_count,6);
  }
  else {
    local_38 = local_54 * 2 + local_58 * 2 + g_PlayerGoldCoins;
    match_count = slot_idx + player_idx;
    for (local_34 = 0; local_34 < local_48; local_34 = local_34 + 1) {
      MoveWindow(*(HWND *)(local_24 + local_34 * 4),-1,-1,0,0,1);
    }
    SetWindowPos(hwnd,(HWND)0x0,0,0,local_38,match_count,6);
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044d31a
 * Entry Point: 0044d31a
 * Size: 629 bytes
 */


void Pic_Subsystem_0044d31a
               (int player_id,int *card_slot,int *arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
               HANDLE arg_9)

{
  uint8_t local_34 [4];
  int local_30;
  int local_2c;
  int color_idx;
  tagRECT target_idx;
  int slot_idx;
  
  if ((((player != 0) && (card_slot != (int *)0x0)) && (arg_3 != (int *)0x0)) && (arg_9 != (HANDLE)0x0))
  {
    GetObjectA(arg_9,0x18,local_34);
    slot_idx = ((arg_3[1] - card_slot[1]) * local_2c) / arg_5;
    for (color_idx = arg_3[1]; color_idx < arg_3[3]; color_idx = color_idx + slot_idx) {
      SetRect(&target_idx,*arg_3,color_idx,*arg_3 + arg_4,color_idx + slot_idx);
      FUN_004f3bc7((HDC)player,&target_idx.left,arg_9,local_30 - arg_8,0,arg_8,local_2c);
      SetRect(&target_idx,arg_3[2] - arg_4,color_idx,arg_3[2],color_idx + slot_idx);
      FUN_004f3bc7((HDC)player,&target_idx.left,arg_9,local_30 - arg_8,0,arg_8,local_2c);
    }
    SetRect(&target_idx,*arg_3,card_slot[1],arg_3[2],arg_3[1]);
    FUN_004f3bc7((HDC)player,&target_idx.left,arg_9,0,0,(local_30 - arg_7) - arg_8,arg_5);
    SetRect(&target_idx,*arg_3,arg_3[3],arg_3[2],card_slot[3]);
    FUN_004f3bc7((HDC)player,&target_idx.left,arg_9,0,local_2c - arg_6,(local_30 - arg_7) - arg_8,arg_6
                );
    for (color_idx = card_slot[1]; color_idx < card_slot[3]; color_idx = color_idx + slot_idx) {
      SetRect(&target_idx,*card_slot,color_idx,*arg_3,color_idx + slot_idx);
      FUN_004f3bc7((HDC)player,&target_idx.left,arg_9,(local_30 - arg_7) - arg_8,0,arg_7,local_2c);
      SetRect(&target_idx,arg_3[2],color_idx,card_slot[2],color_idx + slot_idx);
      FUN_004f3bc7((HDC)player,&target_idx.left,arg_9,(local_30 - arg_7) - arg_8,0,arg_7,local_2c);
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044d58f
 * Entry Point: 0044d58f
 * Size: 139 bytes
 */


void Pic_Subsystem_0044d58f
               (int32_t player,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int *arg_7,
               int *arg_8,int *arg_9,int *arg_10)

{
  if (arg_3 == 0) {
    *arg_7 = 0;
    *arg_8 = 0;
    *arg_9 = 0;
    *arg_10 = 0;
  }
  else {
    *arg_7 = (card_slot * 0x1f) / 100;
    *arg_8 = (*arg_7 * arg_4) / arg_3;
    *arg_9 = (*arg_7 * arg_5) / arg_3;
    *arg_10 = (*arg_7 * arg_6) / arg_3;
  }
  return;
}



/*
 * Decompiled function: UI_DrawPlayerHandWindow
 * Entry Point: 0044d61a
 * Size: 93 bytes
 */


void UI_DrawPlayerHandWindow(char *filepath,HWND hwnd,int32_t arg_3)

{
  sprintf(str_1,s__s___d__00523b68,s_Your_hand_00523b50 + ((hwnd == g_AiLookaheadTreeRoot) - 1 & 0xc),arg_3);
  SetWindowTextA(hwnd,str_1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044d680
 * Entry Point: 0044d680
 * Size: 869 bytes
 */


void Pic_Subsystem_0044d680(void)

{
  bool flag_1;
  int val_2;
  int val_3;
  int local_28;
  int color_idx;
  int target_idx;
  int player_idx;
  uint32_t card_idx;
  
  do {
    Pic_Subsystem_0044e9ac();
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0,0x140,200,0);
    local_28 = 0;
    for (player_idx = 0; player_idx < 0x40; player_idx = player_idx + 1) {
      for (color_idx = 0; color_idx < 0x40; color_idx = color_idx + 1) {
        if ((((player_idx < 2) || (color_idx < 2)) || (0x3d < player_idx)) || (0x3d < color_idx)) {
          Surface_PutPixel((int *)g_DisplaySurfaceWork,player_idx,color_idx,0);
        }
        else {
          val_2 = (color_idx + player_idx) * 3 + -0x20;
          val_3 = (color_idx - player_idx) * 3 + 100;
          if (((val_2 < 4) || (val_3 < 4)) || ((0x13b < val_2 || (0xc3 < val_3)))) {
            Surface_PutPixel((int *)g_DisplaySurfaceWork,player_idx,color_idx,0);
          }
          else {
            val_2 = Pic_Subsystem_0044e864(player_idx,color_idx);
            switch((int)(val_2 + (val_2 >> 0x1f & 7U)) >> 3) {
            case 0:
            case 1:
              card_idx = 0;
              break;
            case 2:
              card_idx = 1;
              if (0x15 < val_2) {
                card_idx = 8;
              }
              break;
            case 3:
              card_idx = 3;
              break;
            case 4:
              card_idx = 6;
              if (val_2 < 0x22) {
                card_idx = 0xd;
              }
              break;
            case 5:
              if (0x2a < val_2) goto switchD_0044d8a6_caseD_6;
              card_idx = 10;
              break;
            case 6:
switchD_0044d8a6_caseD_6:
              card_idx = 2;
              break;
            case 7:
              if (val_2 < 0x3c) {
                card_idx = 0xf;
              }
              else {
                card_idx = 5;
              }
              break;
            case 8:
            case 9:
            case 10:
            case 0xb:
              card_idx = 5;
            }
            Surface_PutPixel((int *)g_DisplaySurfaceWork,player_idx,color_idx,card_idx);
            if (card_idx != 0) {
              local_28 = local_28 + 1;
            }
          }
        }
      }
    }
    if (0x6d5 < local_28) {
      for (player_idx = 1; player_idx < 0x3f; player_idx = player_idx + 1) {
        for (color_idx = 1; color_idx < 0x3f; color_idx = color_idx + 1) {
          card_idx = Surface_GetPixelColor(player_idx, color_idx);
          if (card_idx == 0) {
            flag_1 = false;
            for (target_idx = 1; target_idx < 9; target_idx = target_idx + 2) {
              val_2 = Surface_GetPixelColor(*(int *)(&DAT_00522378 + target_idx * 4) + player_idx,
                                   *(int *)(&DAT_005223e0 + target_idx * 4) + color_idx);
              if (val_2 == 0) {
                flag_1 = true;
                break;
              }
            }
            if (!flag_1) {
              Surface_PutPixel((int *)g_DisplaySurfaceWork,player_idx,color_idx,6);
            }
          }
        }
      }
      Pic_Subsystem_0044e528();
      val_2 = Pic_Subsystem_0044da25();
      if (val_2 != 0) {
        Pic_Subsystem_0044e17e();
        return;
      }
    }
  } while( true );
}



/*
 * Decompiled function: Pic_Util_0044da1a
 * Entry Point: 0044da1a
 * Size: 11 bytes
 */


void Pic_Util_0044da1a(void)

{
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044da25
 * Entry Point: 0044da25
 * Size: 1876 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0044da25(void)

{
  bool flag_1;
  uint32_t uval_2;
  int val_3;
  int arg2;
  int val_4;
  int val_5;
  uint32_t uval_6;
  sbyte sVar7;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint32_t local_34;
  int local_30;
  int local_2c;
  int target_idx;
  uint32_t card_idx;
  int match_count;
  int slot_idx;
  
  local_48 = 0;
  do {
    local_48 = local_48 + 1;
    if (4 < local_48) {
      return 0;
    }
    local_4c = 0;
    slot_idx = 0;
    card_idx = 0;
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      *(int32_t *)(&DAT_005224e8 + local_2c * 0x10) = 0;
    }
    uval_2 = clock();
    uval_6 = (int)uval_2 >> 0x1f;
    match_count = ((uval_2 ^ uval_6) - uval_6 & 0x7f ^ uval_6) - uval_6;
    memset(&g_CardSlot_CreatureType,0xff,0x3200);
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      local_44 = 0;
      do {
        flag_1 = false;
        val_3 = Util_GetRandomNumber(0x40);
        arg2 = Util_GetRandomNumber(0x40);
        val_4 = Surface_GetPixelColor(val_3,arg2);
        if (val_4 != 0) {
          local_40 = 0x7fff;
          target_idx = 0x7fff;
          for (local_34 = 0; (int)local_34 < 0x80; local_34 = local_34 + 1) {
            if (*(int *)(&g_DungeonMapTileX + local_34 * 100) != -1) {
              val_5 = FUN_0040a36f(val_3 - *(int *)(&g_DungeonMapTileX + local_34 * 100),
                                   arg2 - *(int *)(&g_DungeonMapTileY + local_34 * 100));
              if (val_5 < local_40) {
                local_40 = val_5;
              }
              if ((val_5 < target_idx) && (*(int *)(&g_CardSlot_CreatureType + local_34 * 100) == 3)) {
                target_idx = val_5;
              }
            }
          }
          local_44 = local_44 + 1;
          if (7 - local_44 / 100 <= local_40) {
            flag_1 = true;
            *(int *)(&g_DungeonMapTileX + match_count * 100) = val_3;
            *(int *)(&g_DungeonMapTileY + match_count * 100) = arg2;
            if (target_idx < 0x21) {
              if (local_40 < 0xb) {
                *(int32_t *)(&g_CardSlot_CreatureType + match_count * 100) = 1;
              }
              else {
                *(int32_t *)(&g_CardSlot_CreatureType + match_count * 100) = 2;
              }
            }
            else {
              *(int32_t *)(&g_CardSlot_CreatureType + match_count * 100) = 3;
            }
            *(int32_t *)(&DAT_0067bdfc + match_count * 100) = 0;
            *(int32_t *)(&g_CardSlot_StatusFlags + match_count * 100) =
                 *(int32_t *)(&DAT_0067bdfc + match_count * 100);
            for (local_34 = 0; (int)local_34 < 8; local_34 = local_34 + 1) {
              *(int32_t *)(&DAT_0067be24 + local_34 * 4 + match_count * 100) = 0xfffffc18;
            }
            *(int32_t *)(&DAT_0067be44 + match_count * 100) = 0xfffffc18;
            *(int32_t *)(&DAT_0067be48 + match_count * 100) = 0xfffffc18;
            sVar7 = val_4 == 3;
            if (val_4 == 1) {
              sVar7 = 2;
            }
            if (val_4 == 2) {
              sVar7 = 3;
            }
            if (val_4 == 5) {
              sVar7 = 4;
            }
            if (val_4 == 6) {
              sVar7 = 5;
            }
            if (((0x10 < target_idx) && (sVar7 != 0)) && ((card_idx & 1 << sVar7) == 0)) {
              *(int32_t *)(&g_CardSlot_CreatureType + match_count * 100) = 4;
              card_idx = card_idx | 1 << sVar7;
            }
            uval_2 = Glue_Subsystem_004ea7a6(val_4);
            if ((match_count != 0) &&
               ((*(int *)(&g_CardSlot_CreatureType + match_count * 100) == 3 ||
                (*(int *)(&g_CardSlot_CreatureType + match_count * 100) == 2)))) {
              for (local_34 = 0; (int)local_34 < 99; local_34 = local_34 + 1) {
                val_4 = Util_GetRandomNumber(10);
                val_4 = val_4 + 2;
                if ((*(int *)(&DAT_005224e8 + val_4 * 0x10) == 0) &&
                   ((uval_2 & 1 << ((uint8_t)(val_4 / 2) & 0x1f)) != 0)) {
                  *(int *)(&DAT_005224e8 + val_4 * 0x10) = match_count;
                  break;
                }
              }
              if (0x62 < (int)local_34) {
                val_4 = Util_GetRandomNumber(2);
                *(int *)(&DAT_005224e8 + val_4 * 0x10) = match_count;
              }
              if (local_4c < 10) {
                *(uint32_t *)(&g_CardSlot_StatusFlags + match_count * 100) =
                     *(uint32_t *)(&g_CardSlot_StatusFlags + match_count * 100) | 1;
                local_4c = local_4c + 1;
              }
            }
            FUN_0040c81c(0x10,val_3,arg2);
            uval_2 = match_count * 5 + 1;
            uval_6 = (int)uval_2 >> 0x1f;
            match_count = ((uval_2 ^ uval_6) - uval_6 & 0x7f ^ uval_6) - uval_6;
          }
        }
      } while (!flag_1);
      if (1 < *(int *)(&g_CardSlot_CreatureType + local_2c * 100)) {
        slot_idx = slot_idx + 1;
      }
    }
    flag_1 = true;
    if ((card_idx != 0x3e) || (slot_idx < 0x1e)) {
      flag_1 = false;
    }
    for (local_30 = 0; local_30 < 6; local_30 = local_30 + 1) {
      do {
        do {
          val_3 = Util_GetRandomNumber(0x80);
        } while (*(int *)(&g_CardSlot_CreatureType + val_3 * 100) < 2);
      } while ((*(int *)(&g_CardSlot_CreatureType + val_3 * 100) == 4) ||
              (*(int *)(&DAT_0067bdfc + val_3 * 100) != 0));
      *(int *)(&DAT_0067bdfc + val_3 * 100) = 1 << ((uint8_t)local_30 & 0x1f);
    }
    local_34 = Util_GetRandomNumber(0xc);
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      if ((1 < *(int *)(&g_CardSlot_CreatureType + local_2c * 100)) &&
         (*(int *)(&g_CardSlot_CreatureType + local_2c * 100) < 4)) {
        if ((local_34 & 1) == 0) {
          *(int *)(&DAT_0067bdfc + local_2c * 100) = (((int)local_34 % 10) / 2 + 1) * 0x100;
        }
        else {
          *(int *)(&DAT_0067bdfc + local_2c * 100) = 1 << ((uint8_t)(((int)local_34 % 0xc) / 2) & 0x1f)
          ;
        }
        local_34 = local_34 + 1;
      }
    }
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_005224e8 + local_2c * 0x10) == 0) {
        flag_1 = false;
      }
      if ((g_OverworldMovementFlags & 1 << ((uint8_t)local_2c & 0x1f)) != 0) {
        *(int32_t *)(&DAT_005224e8 + local_2c * 0x10) = 0;
      }
    }
    if (flag_1) {
      return 1;
    }
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      FUN_0040c889(0x10,*(int *)(&g_DungeonMapTileX + local_2c * 100),
                   *(int *)(&g_DungeonMapTileY + local_2c * 100));
    }
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      *(int32_t *)(&DAT_005224e8 + local_2c * 0x10) = 0;
    }
  } while( true );
}



/*
 * Decompiled function: Pic_Subsystem_0044e17e
 * Entry Point: 0044e17e
 * Size: 361 bytes
 */


void Pic_Subsystem_0044e17e(void)

{
  int val_1;
  int val_2;
  int local_28;
  int local_24;
  int color_idx;
  int target_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  for (color_idx = 0; color_idx < 0x80; color_idx = color_idx + 1) {
    for (local_28 = 0; local_28 < *(int *)(&g_CardSlot_CreatureType + color_idx * 100); local_28 = local_28 + 1)
    {
      slot_idx = 0;
      do {
        local_24 = 0x7fff;
        for (target_idx = 0; target_idx < 0x2a; target_idx = target_idx + 1) {
          val_1 = Util_GetRandomNumber(0x80);
          val_2 = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + color_idx * 100) -
                               *(int *)(&g_DungeonMapTileX + val_1 * 100),
                               *(int *)(&g_DungeonMapTileY + color_idx * 100) -
                               *(int *)(&g_DungeonMapTileY + val_1 * 100));
          if (val_2 < local_24) {
            card_idx = match_count;
            local_24 = val_2;
            match_count = val_1;
          }
        }
        val_1 = Pic_Subsystem_0044e2e7
                          (*(int *)(&g_DungeonMapTileX + color_idx * 100),
                           *(int *)(&g_DungeonMapTileY + color_idx * 100),
                           *(int *)(&g_DungeonMapTileX + card_idx * 100),
                           *(int *)(&g_DungeonMapTileY + card_idx * 100));
      } while ((val_1 == 0) && (slot_idx = slot_idx + 1, slot_idx < 3));
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044e2e7
 * Entry Point: 0044e2e7
 * Size: 577 bytes
 */


int32_t Pic_Subsystem_0044e2e7(int x,int y,int width,int height)

{
  int val_1;
  int val_2;
  int arg2;
  int val_3;
  uint32_t uval_4;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int loop_idx;
  int color_idx;
  int slot_idx;
  
  color_idx = x;
  loop_idx = y;
  local_34 = 0;
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,0,0x40,0x80,(int *)g_DisplaySurfaceWork,0x40,0);
  FUN_0040c81c(0x20,x,y);
  do {
    val_1 = FUN_0040a36f(width - color_idx,height - loop_idx);
    local_30 = -1;
    local_2c = 0x7fff;
    for (local_24 = 1; local_24 < 9; local_24 = local_24 + 1) {
      val_2 = *(int *)(&DAT_00522378 + local_24 * 4) + color_idx;
      arg2 = *(int *)(&DAT_005223e0 + local_24 * 4) + loop_idx;
      val_3 = Surface_GetPixelColor(val_2,arg2);
      if ((val_3 != 0) && (slot_idx = FUN_0040a36f(width - val_2,height - arg2), slot_idx < val_1)) {
        if ((val_3 == 2) || (val_3 == 0xb)) {
          slot_idx = slot_idx + 1;
        }
        if ((val_3 == 4) || (val_3 == 5)) {
          slot_idx = slot_idx + 4;
        }
        uval_4 = FUN_0040c7c0(val_2,arg2);
        if (((uval_4 & 0x20) != 0) && (0 < local_34)) {
          slot_idx = slot_idx + -4;
        }
        if (slot_idx < local_2c) {
          local_2c = slot_idx;
          local_30 = local_24;
        }
      }
    }
    if (local_30 == -1) {
      Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0x40,0,0x40,0x80,(int *)g_DisplaySurfaceWork,0,0);
      return 0;
    }
    val_1 = *(int *)(&DAT_00522378 + local_30 * 4) + color_idx;
    val_2 = *(int *)(&DAT_005223e0 + local_30 * 4) + loop_idx;
    uval_4 = FUN_0040c7c0(val_1,val_2);
    FUN_0040ca43(color_idx,loop_idx,local_30);
    if (((uval_4 & 0x20) != 0) && (0 < local_34)) {
      return 1;
    }
    local_34 = local_34 + 1;
    loop_idx = val_2;
    color_idx = val_1;
  } while ((val_1 != width) || (val_2 != height));
  return 1;
}



/*
 * Decompiled function: Pic_Subsystem_0044e528
 * Entry Point: 0044e528
 * Size: 565 bytes
 */


void Pic_Subsystem_0044e528(void)

{
  bool flag_1;
  int val_2;
  int target_idx;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  Surface_PutPixel((int *)g_DisplaySurfaceWork,0xa8,0x58,0xff);
  do {
    flag_1 = false;
    for (card_idx = 4; card_idx < 0x40; card_idx = card_idx + 4) {
      for (player_idx = 4; player_idx < 0x40; player_idx = player_idx + 4) {
        val_2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,card_idx + 0x80,player_idx + 0x40);
        if (val_2 != 0) {
          Surface_FillRect((int *)g_DisplaySurfaceWork,0x40,0,0x40,0x40,0);
          Pic_Subsystem_0044e75d(card_idx,player_idx,8);
          Surface_PutPixel((int *)g_DisplaySurfaceWork,card_idx + 0x80,player_idx + 0x40,0);
          for (target_idx = 0; target_idx < 0x40; target_idx = target_idx + 1) {
            for (slot_idx = 0; slot_idx < 0x40; slot_idx = slot_idx + 1) {
              val_2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,target_idx + 0x40,slot_idx);
              if ((val_2 != 0) &&
                 (val_2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,target_idx + 0x80,slot_idx),
                 val_2 == 0)) {
                flag_1 = true;
                Surface_PutPixel((int *)g_DisplaySurfaceWork,target_idx + 0x80,slot_idx,0xff);
                Surface_PutPixel((int *)g_DisplaySurfaceWork,target_idx + 0x80,slot_idx + 0x40,0xff);
              }
            }
          }
        }
      }
    }
  } while (flag_1);
  for (card_idx = 0; card_idx < 0x40; card_idx = card_idx + 1) {
    for (player_idx = 0; player_idx < 0x40; player_idx = player_idx + 1) {
      val_2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,card_idx + 0x80,player_idx);
      if (val_2 == 0) {
        Surface_PutPixel((int *)g_DisplaySurfaceWork,card_idx,player_idx,0);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044e75d
 * Entry Point: 0044e75d
 * Size: 231 bytes
 */


void Pic_Subsystem_0044e75d(int player_id,int card_slot,int event_type)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int val_4;
  char card_idx;
  
  Surface_PutPixel((int *)g_DisplaySurfaceWork,player + 0x40,card_slot,arg_3);
  if (1 < arg_3) {
    for (card_idx = '\x01'; card_idx < '\t'; card_idx = card_idx + '\x02') {
      cVar1 = (char)*(int32_t *)(&DAT_00522378 + card_idx * 4) + (char)player;
      cVar2 = (char)*(int32_t *)(&DAT_005223e0 + card_idx * 4) + (char)card_slot;
      cVar3 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,cVar1 + 0x40,(int)cVar2);
      if ((cVar3 < arg_3) &&
         (val_4 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,(int)cVar1,(int)cVar2), val_4 != 0))
      {
        Pic_Subsystem_0044e75d((int)cVar1,(int)cVar2,arg_3 + -1);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Util_0044e844
 * Entry Point: 0044e844
 * Size: 32 bytes
 */


void Pic_Util_0044e844(int arg1,int arg2)

{
  Pic_Subsystem_0044e864(arg1,arg2);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044e864
 * Entry Point: 0044e864
 * Size: 328 bytes
 */


void Pic_Subsystem_0044e864(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  
  val_1 = abs(arg2 + -0x20);
  val_2 = abs(arg1 + -0x20);
  val_1 = (val_1 + val_2) * (val_1 + val_2);
  val_2 = abs(arg1 - arg2);
  val_3 = Pic_Subsystem_0044eb9d(arg1 << 5,arg2 << 5);
  val_4 = Pic_Subsystem_0044eb9d(arg1 << 8,arg2 << 8);
  val_5 = Pic_Subsystem_0044eb9d(arg1 << 9,arg2 << 9);
  val_1 = Math_Clamp(((int)(val_1 + (val_1 >> 0x1f & 0x1ffU)) >> 9) +
                       ((int)(val_2 + (val_2 >> 0x1f & 0xfU)) >> 4),0,0xc);
  val_1 = (val_3 * 4 + val_4 * 2 + val_5 + val_1 * -0x200) * 7;
  val_1 = val_1 + (val_1 >> 0x1f & 0x3fU);
  Math_Clamp((int)((val_1 >> 6) + (val_1 >> 0x1f & 3U)) >> 2,0,100);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044e9ac
 * Entry Point: 0044e9ac
 * Size: 497 bytes
 */


void Pic_Subsystem_0044e9ac(void)

{
  uint8_t uval_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x12; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < 0x12; card_idx = card_idx + 1) {
      uval_1 = Util_GetRandomNumber(0x10);
      (&DAT_0067a6c0)[card_idx + slot_idx * 0x13] = uval_1;
    }
    (&DAT_0067a6d2)[slot_idx * 0x13] = (&DAT_0067a6c0)[slot_idx * 0x13];
  }
  for (card_idx = 0; card_idx < 0x12; card_idx = card_idx + 1) {
    (&DAT_0067a816)[card_idx] = (&DAT_0067a6c0)[card_idx];
  }
  for (slot_idx = 0; slot_idx < 0x11; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < 0x11; card_idx = card_idx + 1) {
      for (match_count = 1; match_count < 9; match_count = match_count + 1) {
      }
      (&DAT_0067a830)[card_idx + slot_idx * 0x13] = (&DAT_0067a6c0)[card_idx + slot_idx * 0x13];
    }
  }
  for (slot_idx = 0; slot_idx < 0x11; slot_idx = slot_idx + 1) {
    (&DAT_0067a840)[slot_idx * 0x13] = (&DAT_0067a830)[slot_idx * 0x13];
  }
  for (card_idx = 0; card_idx < 0x11; card_idx = card_idx + 1) {
    (&DAT_0067a960)[card_idx] = (&DAT_0067a830)[card_idx];
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044eb9d
 * Entry Point: 0044eb9d
 * Size: 259 bytes
 */


int Pic_Subsystem_0044eb9d(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  
  uval_2 = arg1 - 0x80U >> 8 & 0xf;
  uval_3 = (arg1 - 0x80U & 0xff) >> 3;
  uval_4 = arg2 - 0x80U >> 8 & 0xf;
  uval_5 = (arg2 - 0x80U & 0xff) >> 3;
  val_1 = (int)(char)(&DAT_0067a830)[uval_2 * 0x13 + uval_4] * (0x20 - uval_5) * (0x20 - uval_3) +
          (int)(char)(&DAT_0067a830)[uval_4 + (uval_2 + 1) * 0x13] * (0x20 - uval_5) * uval_3 +
          (int)(char)(&DAT_0067a831)[uval_4 + uval_2 * 0x13] * (0x20 - uval_3) * uval_5 +
          (int)(char)(&DAT_0067a831)[uval_4 + (uval_2 + 1) * 0x13] * uval_5 * uval_3;
  return (int)(val_1 + (val_1 >> 0x1f & 0x1fU)) >> 5;
}



/*
 * Decompiled function: SaveGame_SaveGauntletFile
 * Entry Point: 0044eca0
 * Size: 341 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SaveGame_SaveGauntletFile(void)

{
  size_t len_1;
  char *char_ptr_2;
  
  DAT_00695e98 = 0xd;
  strcpy(&DAT_00538c20,s___SVG_00523b70);
  strcpy(&DAT_00538c30,s_MTG_Gauntlet_Save_Game_00523b78);
  char_ptr_2 = &DAT_00538c20;
  len_1 = strlen(&DAT_00538c30);
  strcat((char *)(len_1 + 0x538c31),char_ptr_2);
  char_ptr_2 = &DAT_00523b90;
  len_1 = strlen(&DAT_00538c30);
  strcat((char *)(len_1 + 0x538c31),char_ptr_2);
  strcpy(&DAT_00538ca8,&DAT_00538c20);
  _DAT_006a2860 = 0x4c;
  _DAT_006a2864 = g_MainAppHwnd;
  _DAT_006a2868 = 0;
  _DAT_006a286c = &DAT_00538c30;
  _DAT_006a2870 = 0;
  _DAT_006a2874 = 0;
  _DAT_006a2878 = 0;
  DAT_006a287c = &DAT_00538ca8;
  _DAT_006a2880 = 0x104;
  _DAT_006a2884 = &DAT_00538c00;
  _DAT_006a2888 = 0x1e;
  _DAT_006a288c = &g_SaveGameDirectory;
  _DAT_006a2890 = s_Save_Game_00523b94;
  _DAT_006a2894 = 0x2a000c;
  _DAT_006a2898 = 0;
  _DAT_006a289a = 0;
  _DAT_006a289c = &DAT_00538c20;
  _DAT_006a28a0 = 0;
  _DAT_006a28a4 = 0;
  _DAT_006a28a8 = 0;
  return;
}



/*
 * Decompiled function: SaveGame_AutoSave
 * Entry Point: 0044edf5
 * Size: 270 bytes
 */


void SaveGame_AutoSave(int32_t player)

{
  int32_t uval_1;
  char local_10c [264];
  
  uval_1 = g_ScWillyScore;
  if (((uint8_t)DAT_006fe410 & 1) == 0) {
    g_ScWillyScore = player;
    strcpy(local_10c,&g_SaveGameDirectory);
    strcat(local_10c,s__AUTOSAVE_00523ba0);
    strcat(local_10c,&DAT_00538c21);
    FUN_0048e122(local_10c);
  }
  if ((((uint8_t)DAT_006fe410 & 1) != 0) && (DAT_0068a718 != 0)) {
    g_ScWillyScore = player;
    strcpy(local_10c,&g_SaveGameDirectory);
    strcat(local_10c,s__SHANDSAVE_00523bac);
    strcat(local_10c,&DAT_00538c21);
    FUN_0048e122(local_10c);
  }
  g_ScWillyScore = uval_1;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044ef03
 * Entry Point: 0044ef03
 * Size: 98 bytes
 */


void Pic_Subsystem_0044ef03(LPCSTR str_1)

{
  char local_10c [264];
  
  strcpy(local_10c,&g_SaveGameDirectory);
  strcat(local_10c,s__AUTOSAVE_00523bb8);
  strcat(local_10c,&DAT_00538c21);
  CopyFileA(local_10c,str_1,0);
  return;
}



/*
 * Decompiled function: Deck_LoadOneDeckProfile
 * Entry Point: 0044ef70
 * Size: 607 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0044f1b3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Deck_LoadOneDeckProfile(int32_t arg1,LPVOID out_buffer)

{
  int nPriority;
  HANDLE hHandle;
  int card_idx;
  DWORD match_count [2];
  
  _DAT_0063ee14 = 1;
  Palette_Subsystem_00496eaf();
  match_count[1] = 2;
  nPriority = GetThreadPriority(DAT_00626820);
  SetThreadPriority(DAT_00626820,-0xf);
  hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,Palette_Subsystem_004958b1,out_buffer,0,
                         match_count);
  WaitForSingleObject(hHandle,0xffffffff);
  GetExitCodeThread(hHandle,match_count + 1);
  CloseHandle(hHandle);
  SetThreadPriority(DAT_00626820,nPriority);
  if (DAT_0063ee80 == 0) {
    for (card_idx = 0; card_idx < 500; card_idx = card_idx + 1) {
      if (*(int *)(&deck + card_idx * 4) != -1) {
        *(uint32_t *)(&deck + card_idx * 4) = *(uint32_t *)(&deck + card_idx * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_00523dfc);
  }
  g_AiManaColorCost_Blue = 0xffffffff;
  DAT_006b2fe0 = 0xffffffff;
  g_GlobalEnchantmentCardId = 0xffffffff;
  g_IsAiThinking = 0;
  for (card_idx = 0; card_idx < 4; card_idx = card_idx + 1) {
    *(int32_t *)(&g_PlayerLifeTotals + card_idx * 4) = 8;
  }
  if (DAT_0067a6b0 != 0) {
    memcpy(&deck,&DAT_00679ee0,2000);
  }
  g_AiCombatScore_Blocker = 0;
  _DAT_0063ee14 = 1;
  g_ActiveBattlefieldFlag = 0;
  DAT_006a48e0 = 0;
  DAT_006ff2d8 = 0xffffffff;
  g_ScWillyScore = 0;
  ShowWindow(_hwndScreen,5);
  SetForegroundWindow(_hwndScreen);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_00523e18);
  Catalog_LoadPaletteMap(s_todpal_tr_00523e28,(char *)0x0);
  SelectPalette(*(HDC *)(g_ScreenSurfaces + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(g_ScreenSurfaces + 4));
  Glue_Sound_004ec32f();
  g_AiCombatLookaheadTarget = 0;
  g_AiManaColorCost_Blue = 0xffffffff;
  return DAT_00627a80;
}



/*
 * Decompiled function: Pic_Subsystem_0044f1de
 * Entry Point: 0044f1de
 * Size: 5427 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0044f701) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pic_Subsystem_0044f1de(int32_t arg1,int arg2)

{
  int val_1;
  uint32_t player;
  int32_t uval_2;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c [6];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  int32_t target_idx;
  uint32_t player_idx;
  uint32_t card_idx;
  int match_count;
  int slot_idx;
  
  if (((uint8_t)DAT_006fe410 & 1) == 0) {
    arg2 = -1;
  }
  Glue_Subsystem_004ebebf();
  Ai_SyncLookaheadBuffers();
  g_AiCombatScore_Blocker = 1;
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (color_idx = 0; color_idx < 0x50; color_idx = color_idx + 1) {
      *(int32_t *)(&g_ActiveCardsInPlay + slot_idx * 0x5b20 + color_idx * 0x120) = 0xffffffff;
      *(int32_t *)(&g_CardSlot_CardId + slot_idx * 0x5b20 + color_idx * 0x120) =
           *(int32_t *)(&g_ActiveCardsInPlay + slot_idx * 0x5b20 + color_idx * 0x120);
    }
    for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
      *(int32_t *)(&DAT_006b1590 + color_idx * 4 + slot_idx * 2000) = 0xffffffff;
      *(int32_t *)(&g_PlayerGraveyardList + color_idx * 4 + slot_idx * 2000) =
           *(int32_t *)(&DAT_006b1590 + color_idx * 4 + slot_idx * 2000);
    }
    *(int32_t *)(&DAT_006ff4b8 + slot_idx * 4) = 0;
    (&g_PlayerActiveCardCount)[slot_idx] = 0;
  }
  DAT_006ff2c0 = 0xef;
  DAT_006ff2c4 = 0x7e;
  DAT_006ff2c8 = 0x5b;
  DAT_006ff2cc = 0xa4;
  DAT_006ff2d0 = 0xbc;
  FUN_0046f300();
  FUN_0047643e();
  if (arg2 == -1) {
    g_PlayerDeckCardCount = 0x14;
    g_PlayerCreatureCount = 0x14;
    Ai_Subsystem_004b6f49(&DAT_00695e10);
    local_2c = 7;
    g_PendingSpellResolutionFlag = 0;
    DAT_00696a18 = 1;
    DAT_006b2d64 = -1;
    Util_SeedRandomGenerator();
    if (((g_CampaignDifficultyLevel == 0) || (val_1 = Util_GetRandomNumber(2), val_1 == 0)) || (g_IsAiThinking != 0)) {
      card_idx = 0;
    }
    else {
      card_idx = 1;
    }
    local_28 = 1;
    DAT_006a2858 = 1;
    if (DAT_0068a648 == 0) {
      for (local_54 = 0; local_54 < 0x3c; local_54 = local_54 + 1) {
        *(int32_t *)(&DAT_0069ef00 + local_54 * 4) = 0;
        *(int32_t *)(&g_PlayerDeckCardList + local_54 * 4) =
             *(int32_t *)(&DAT_0069ef00 + local_54 * 4);
      }
      for (local_54 = 0x3c; local_54 < 500; local_54 = local_54 + 1) {
        *(int32_t *)(&DAT_0069ef00 + local_54 * 4) = 0xffffffff;
        *(int32_t *)(&g_PlayerDeckCardList + local_54 * 4) =
             *(int32_t *)(&DAT_0069ef00 + local_54 * 4);
      }
      Ai_EvaluateTacticalPosition(0,0x30);
      for (local_54 = 0; local_54 < 0x10; local_54 = local_54 + 1) {
        (&DAT_006b2dd0)[local_54] = 0xffffffff;
        (&DAT_006b2d90)[local_54] = (&DAT_006b2dd0)[local_54];
      }
      if (DAT_006feeb8 != 0) {
        DAT_006b2d90 = FUN_0040a02a(g_OverworldPlayerDirection);
        DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
      }
      for (local_54 = 0; local_54 < 7; local_54 = local_54 + 1) {
        val_1 = FUN_0040a02a(g_OverworldPlayerDirection);
        Deck_AddCardToDeck(0,val_1);
        val_1 = FUN_0040a02a(DAT_0052eff8);
        Deck_AddCardToDeck(1,val_1);
      }
      Pic_Subsystem_00450711(&target_idx,&local_34,&loop_idx);
      for (local_50 = 0; local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = g_OverworldPlayerDirection;
        }
        else {
          local_60 = DAT_0052eff8;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < *(int *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280);
                local_58 = local_58 + 1) {
              *(int32_t *)(&g_PlayerDeckCardList + local_5c * 4 + local_50 * 2000) = 0;
              local_5c = local_5c + 1;
            }
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(int32_t *)(&g_PlayerDeckCardList + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      Ai_AssignCombatDamage
                (&card_idx,(uint32_t *)(local_4c + 5),card_idx,local_28,DAT_006b2dd0,DAT_006b2d90,
                 target_idx,local_34,loop_idx);
      if (local_4c[5] != 0) {
        Pic_Subsystem_0045083f(0,g_OverworldPlayerDirection);
        Ai_EvaluateTacticalPosition(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (loop_idx != 0)))) {
        Pic_Subsystem_0045083f(1,DAT_0052eff8);
        Ai_EvaluateTacticalPosition(0,0x30);
      }
      for (local_50 = 0; val_1 = g_IsAiThinking, local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = g_OverworldPlayerDirection;
        }
        else {
          local_60 = DAT_0052eff8;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < *(int *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280);
                local_58 = local_58 + 1) {
              uval_2 = Ai_Subsystem_004cbcd9
                                (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280));
              *(int32_t *)(&g_PlayerDeckCardList + local_5c * 4 + local_50 * 2000) = uval_2;
              local_5c = local_5c + 1;
            }
            *(int32_t *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280) = 0;
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(int32_t *)(&g_PlayerDeckCardList + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      g_OverworldPlayerDirection = -1;
      g_IsAiThinking = 1;
      Pic_Subsystem_00452276(0);
      Pic_Subsystem_00452276(1);
      g_IsAiThinking = val_1;
    }
  }
  else {
    local_4c[4] = 0;
    local_4c[0] = 0x1e;
    local_4c[1] = 0x23;
    local_4c[2] = 0x28;
    local_4c[3] = 0x28;
    g_PlayerCreatureCount = 10;
    if ((g_OverworldMovementFlags & 2) != 0) {
      g_PlayerCreatureCount = 0xc;
    }
    if ((g_OverworldMovementFlags & 0x800) != 0) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + 3;
    }
    if ((g_OverworldMovementFlags & 0x80) != 0) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + 5;
    }
    val_1 = Engine_CountActiveCreatures();
    g_PlayerCreatureCount = val_1 + g_AiCombatLookaheadTarget;
    g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_006498fc;
    if ((0 < g_AiManaColorCost_Blue) && (g_AiManaColorCost_Blue < 6)) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + g_AiManaColorCost_Blue;
    }
    DAT_00627868 = g_PlayerCreatureCount;
    g_AiCombatLookaheadTarget = 0;
    g_PlayerDeckCardCount = (int)(char)(&DAT_00522628)[arg2 * 0x44];
    if ((arg2 < 0x25) && (arg2 % 7 != 0)) {
      g_PlayerDeckCardCount = g_PlayerDeckCardCount + g_CampaignDifficultyLevel * 2;
    }
    else if ((arg2 < 0x25) && (arg2 % 7 == 0)) {
      g_PlayerDeckCardCount = g_PlayerDeckCardCount + g_CampaignDifficultyLevel * 5;
    }
    else if (arg2 < 0x37) {
      g_PlayerDeckCardCount = g_PlayerDeckCardCount + g_CampaignDifficultyLevel * 2;
    }
    else if (0x36 < arg2) {
      g_PlayerDeckCardCount = g_PlayerDeckCardCount + g_CampaignDifficultyLevel * 0x32;
    }
    if ((&DAT_0052262a)[arg2 * 0x44] == '\v') {
      for (color_idx = 0; color_idx < 10; color_idx = color_idx + 1) {
        if ((g_OverworldMovementFlags & 1 << ((uint8_t)color_idx & 0x1f)) != 0) {
          g_PlayerDeckCardCount = g_PlayerDeckCardCount + 1;
        }
      }
    }
    val_1 = g_PlayerDeckCardCount;
    if ((&DAT_0052262a)[arg2 * 0x44] == '\f') {
      g_PlayerDeckCardCount = g_PlayerDeckCardCount + 10;
      local_30 = 0;
      match_count = 0;
      for (color_idx = 0; (color_idx < 1000 && ((&DAT_0067b9b0)[color_idx] != '\0'));
          color_idx = color_idx + 1) {
        if ((int)(char)(&DAT_0067b9b0)[color_idx] >> 4 == DAT_006b2d64) {
          local_30 = local_30 + 1;
        }
      }
      g_PlayerDeckCardCount = g_PlayerDeckCardCount - local_30;
      for (local_24 = 0; local_24 < 0x80; local_24 = local_24 + 1) {
        if (((&DAT_0067be01)[local_24 * 100] != '\0') &&
           ((*(int *)(&g_CardSlot_StatusFlags + local_24 * 100) >> 8) + -1 == color_idx)) {
          match_count = match_count + 1;
        }
      }
      g_PlayerDeckCardCount = g_PlayerDeckCardCount + g_CampaignDifficultyLevel * match_count;
      val_1 = g_CampaignDifficultyLevel * 5 + 0x14;
      if (val_1 <= g_PlayerDeckCardCount) {
        val_1 = g_PlayerDeckCardCount;
      }
    }
    g_PlayerDeckCardCount = val_1;
    if ((&DAT_0052262a)[arg2 * 0x44] == '\r') {
      g_PlayerDeckCardCount = g_CampaignDifficultyLevel * 100 + 100;
    }
    g_OverworldWorldState = 0;
    Glue_Subsystem_004eaa19(arg2,0,0);
    strcpy(&DAT_00695e10,&g_OverworldWorldState);
    Math_Clamp(g_CampaignDifficultyLevel + DAT_00695df0 + 4,0,99);
    local_2c = 7;
    g_PendingSpellResolutionFlag = 0;
    Util_SeedRandomGenerator();
    if (((g_CampaignDifficultyLevel == 0) || (val_1 = Util_GetRandomNumber(2), val_1 == 0)) || (g_IsAiThinking != 0)) {
      card_idx = 0;
    }
    else {
      card_idx = 1;
    }
    local_28 = 1;
    DAT_006a2858 = 1;
    if ((DAT_0067a6b4 != 0) || (g_AiManaColorCost_Blue == 0)) {
      if (DAT_0067a6b4 == 0) {
        card_idx = 0;
      }
      else {
        card_idx = 1;
      }
      card_idx = (uint32_t)(DAT_0067a6b4 != 0);
      local_28 = 0;
      DAT_006a2858 = 0;
      DAT_0067a6b4 = 0;
    }
    if (g_IsAiThinking == 0) {
      DAT_0067a6b0 = 0;
      for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
        if ((*(int *)(&deck + color_idx * 4) != -1) && (((&DAT_00702151)[color_idx * 4] & 0x40) == 0))
        {
          local_4c[4] = local_4c[4] + 1;
        }
      }
      if (local_4c[4] < local_4c[g_CampaignDifficultyLevel]) {
        DAT_0067a6b0 = 1;
        memcpy(&DAT_00679ee0,&deck,2000);
        for (color_idx = 0; color_idx < local_4c[g_CampaignDifficultyLevel] - local_4c[4]; color_idx = color_idx + 1)
        {
          player = Util_GetRandomNumber(5);
          Pic_Subsystem_00451e40(player);
        }
      }
      for (color_idx = 0; color_idx < 0x3c; color_idx = color_idx + 1) {
        *(int32_t *)(&DAT_0069ef00 + color_idx * 4) = 0;
        *(int32_t *)(&g_PlayerDeckCardList + color_idx * 4) =
             *(int32_t *)(&DAT_0069ef00 + color_idx * 4);
      }
      for (color_idx = 0x3c; color_idx < 500; color_idx = color_idx + 1) {
        *(int32_t *)(&DAT_0069ef00 + color_idx * 4) = 0xffffffff;
        *(int32_t *)(&g_PlayerDeckCardList + color_idx * 4) =
             *(int32_t *)(&DAT_0069ef00 + color_idx * 4);
      }
      Ai_EvaluateTacticalPosition(0,0x30);
      for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
        if ((*(uint32_t *)(&deck + color_idx * 4) & 0xfff) == DAT_006b2d90) {
          *(uint32_t *)(&deck + color_idx * 4) = *(uint32_t *)(&deck + color_idx * 4) | 0x8000;
          break;
        }
      }
      for (color_idx = 0; color_idx < 7; color_idx = color_idx + 1) {
        if (g_OverworldPlayerDirection == -1) {
          val_1 = Pic_Subsystem_00451cb2();
          Deck_AddCardToDeck(0,val_1);
        }
        else {
          val_1 = FUN_0040a02a(g_OverworldPlayerDirection);
          Deck_AddCardToDeck(0,val_1);
        }
      }
      if (DAT_0052eff8 != -1) {
        if ((g_OverworldPlayerDirection == -1) && (FUN_00409eb0(DAT_0052eff8), DAT_006b2dd0 != -1)) {
          FUN_00409f16(0,DAT_006b2dd0);
        }
        for (color_idx = 0; color_idx < local_2c; color_idx = color_idx + 1) {
          val_1 = FUN_0040a02a((uint32_t)(g_OverworldPlayerDirection != -1));
          Deck_AddCardToDeck(1,val_1);
        }
      }
      Pic_Subsystem_00450711(&target_idx,&local_34,&loop_idx);
      Ai_AssignCombatDamage
                (&card_idx,(uint32_t *)(local_4c + 5),card_idx,local_28,DAT_006b2dd0,DAT_006b2d90,
                 target_idx,local_34,loop_idx);
      if (local_4c[5] != 0) {
        for (color_idx = 0; color_idx < 0x50; color_idx = color_idx + 1) {
          *(int32_t *)(&g_CardSlot_CardId + color_idx * 0x120) = 0xffffffff;
          *(int32_t *)(&g_ActiveCardsInPlay + color_idx * 0x120) = 0xffffffff;
        }
        for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
          if (*(int *)(&deck + color_idx * 4) != -1) {
            *(uint32_t *)(&deck + color_idx * 4) = *(uint32_t *)(&deck + color_idx * 4) & 0xffff7fff;
          }
        }
        for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
          if ((*(uint32_t *)(&deck + color_idx * 4) & 0xfff) == DAT_006b2d90) {
            *(uint32_t *)(&deck + color_idx * 4) = *(uint32_t *)(&deck + color_idx * 4) | 0x8000;
            break;
          }
        }
        for (color_idx = 0; color_idx < 7; color_idx = color_idx + 1) {
          if (g_OverworldPlayerDirection == -1) {
            val_1 = Pic_Subsystem_00451cb2();
            Deck_AddCardToDeck(0,val_1);
          }
          else {
            val_1 = FUN_0040a02a(g_OverworldPlayerDirection);
            Deck_AddCardToDeck(0,val_1);
          }
        }
        Ai_EvaluateTacticalPosition(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (loop_idx != 0)))) {
        for (color_idx = 0; color_idx < 0x50; color_idx = color_idx + 1) {
          *(int32_t *)(&DAT_006aba54 + color_idx * 0x120) = 0xffffffff;
          *(int32_t *)(&DAT_006aba50 + color_idx * 0x120) = 0xffffffff;
        }
        if ((g_OverworldPlayerDirection == -1) && (FUN_00409eb0(DAT_0052eff8), DAT_006b2dd0 != -1)) {
          FUN_00409f16(0,DAT_006b2dd0);
        }
        for (color_idx = 0; color_idx < local_2c; color_idx = color_idx + 1) {
          val_1 = FUN_0040a02a((uint32_t)(g_OverworldPlayerDirection != -1));
          Deck_AddCardToDeck(1,val_1);
        }
        Ai_EvaluateTacticalPosition(0,0x30);
      }
      if (g_OverworldPlayerDirection == -1) {
        DAT_0052eff8 = 0;
      }
      for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
        if (g_OverworldPlayerDirection == -1) {
          uval_2 = Pic_Subsystem_00451cb2();
          *(int32_t *)(&g_PlayerDeckCardList + color_idx * 4) = uval_2;
        }
        else {
          uval_2 = FUN_0040a02a(g_OverworldPlayerDirection);
          *(int32_t *)(&g_PlayerDeckCardList + color_idx * 4) = uval_2;
        }
        uval_2 = FUN_0040a02a(DAT_0052eff8);
        *(int32_t *)(&DAT_0069ef00 + color_idx * 4) = uval_2;
      }
      g_OverworldPlayerDirection = -1;
      if ((((&DAT_00522638)[arg2 * 0x44] & 2) != 0) && (DAT_0067f37c % 3 == 0)) {
        memcpy(&DAT_0069ef00,&g_PlayerDeckCardList,1000);
        color_idx = g_IsAiThinking;
        g_IsAiThinking = 1;
        Pic_Subsystem_00452276(1);
        g_IsAiThinking = color_idx;
        memcpy(&DAT_006aba50,&g_ActiveCardsInPlay,0x5b20);
        for (color_idx = 0; color_idx < 0x50; color_idx = color_idx + 1) {
          if (*(int *)(&DAT_006aba54 + color_idx * 0x120) != -1) {
            *(uint32_t *)(&DAT_006aba5c + color_idx * 0x120) =
                 *(uint32_t *)(&DAT_006aba5c + color_idx * 0x120) | 0x1000;
          }
        }
        g_PendingSpellResolutionFlag = 0;
      }
      if (DAT_006b2fe0 != -1) {
        color_idx = Deck_AddCardToDeck(1,DAT_006b2fe0);
        if (color_idx != -1) {
          *(uint32_t *)(&DAT_006aba5c + color_idx * 0x120) =
               *(uint32_t *)(&DAT_006aba5c + color_idx * 0x120) | 0x30002;
        }
        DAT_006b2fe0 = -1;
        if (g_AiManaColorCost_Blue == -1) {
          g_AiManaColorCost_Blue = 0;
        }
      }
      if (g_GlobalEnchantmentCardId != -1) {
        color_idx = Deck_AddCardToDeck(1,g_GlobalEnchantmentCardId);
        Pic_Subsystem_0042ac1f(1,color_idx);
        g_GlobalEnchantmentCardId = -1;
        if (g_AiManaColorCost_Blue == -1) {
          g_AiManaColorCost_Blue = 0;
        }
      }
      if (5 < g_AiManaColorCost_Blue) {
        color_idx = Deck_AddCardToDeck(0,g_AiManaColorCost_Blue);
        Pic_Subsystem_0042ac1f(0,color_idx);
      }
    }
  }
  FUN_0046f300();
  if (g_IsAiThinking == -1) {
    SaveGame_LoadCampaignFile(0);
  }
  if (g_IsAiThinking == -2) {
    SaveGame_LoadCampaignFile(1);
  }
  Pic_Subsystem_0044b8aa();
  if (g_IsAiThinking == -10) {
    FUN_0048e1bf(DAT_006a287c);
    Ai_EvaluateTacticalPosition(0,0xff);
    player_idx = g_DefendingPlayer;
  }
  else if (g_IsAiThinking == -1) {
    DAT_006a4b58 = 0;
    Ai_EvaluateTacticalPosition(0,0xff);
    player_idx = 1;
  }
  else if (g_IsAiThinking == -2) {
    DAT_006a4b58 = 0;
    Ai_EvaluateTacticalPosition(0,0xff);
    player_idx = 0;
  }
  else {
    DAT_006a4b58 = 1;
    player_idx = card_idx;
  }
  while ((DAT_006fe3f0 == 0 && (val_1 = FUN_005062b1(), val_1 == 0))) {
    if (DAT_007006d4 == 0) {
      FUN_00501f50(player_idx);
      player_idx = 1 - player_idx;
    }
    else {
      if ((DAT_007006d4 & 1) == 0) {
        DAT_007006d4 = 0;
        if (player_idx == 0) {
          DAT_006ff2d8 = 0xffffffff;
        }
        FUN_00501f50(1);
      }
      else {
        DAT_007006d4 = 0;
        if (player_idx == 1) {
          DAT_006ff2d8 = 0xffffffff;
        }
        FUN_00501f50(0);
      }
      DAT_006ff2d8 = 0xffffffff;
    }
  }
  UI_PrepareCombatViewport();
  if (DAT_0063ee80 == 0) {
    for (color_idx = 0; color_idx < 500; color_idx = color_idx + 1) {
      if (*(int *)(&deck + color_idx * 4) != -1) {
        *(uint32_t *)(&deck + color_idx * 4) = *(uint32_t *)(&deck + color_idx * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_00523e34);
  }
  g_AiManaColorCost_Blue = 0xffffffff;
  DAT_006b2fe0 = 0xffffffff;
  g_GlobalEnchantmentCardId = 0xffffffff;
  g_IsAiThinking = 0;
  for (color_idx = 0; color_idx < 4; color_idx = color_idx + 1) {
    *(int32_t *)(&g_PlayerLifeTotals + color_idx * 4) = 8;
  }
  g_AiCombatScore_Blocker = 0;
  _DAT_0063ee14 = 1;
  if (((g_PlayerCreatureCount < 1) || (9 < DAT_00696870)) ||
     ((0 < g_PlayerDeckCardCount && (DAT_00696874 < 10)))) {
    if (((g_PlayerDeckCardCount < 1) || (9 < DAT_00696874)) ||
       ((0 < g_PlayerCreatureCount && (DAT_00696870 < 10)))) {
      uval_2 = 0xffffffff;
    }
    else {
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: Pic_Subsystem_00450711
 * Entry Point: 00450711
 * Size: 302 bytes
 */


void Pic_Subsystem_00450711(int32_t *player,int32_t *card_slot,int32_t *arg_3)

{
  int card_idx;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  slot_idx = 0;
  for (card_idx = 0; card_idx < 7; card_idx = card_idx + 1) {
    if (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + card_idx * 0x120) * 0x34] & 1) != 0) {
      slot_idx = slot_idx + 1;
    }
    if (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + card_idx * 0x120) * 0x34] & 1) != 0
       ) {
      match_count = match_count + 1;
    }
  }
  if (match_count == 0) {
    *player = 1;
  }
  else if (match_count == 7) {
    *player = 2;
  }
  else {
    *player = 0;
  }
  if (slot_idx == 0) {
    *card_slot = 1;
  }
  else if (slot_idx == 7) {
    *card_slot = 2;
  }
  else {
    *card_slot = 0;
  }
  if ((slot_idx < 2) || (5 < slot_idx)) {
    *arg_3 = 1;
  }
  else {
    *arg_3 = 0;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0045083f
 * Entry Point: 0045083f
 * Size: 310 bytes
 */


void Pic_Subsystem_0045083f(int arg1,int arg2)

{
  bool flag_1;
  int val_2;
  int card_idx;
  int match_count;
  
  for (match_count = 0; match_count < 0x50; match_count = match_count + 1) {
    if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + match_count * 0x120) != -1) {
      flag_1 = false;
      card_idx = 0;
      while ((card_idx < 0x50 && (!flag_1))) {
        val_2 = Ai_Subsystem_004cbcd9(*(int *)(&DAT_00516cb8 + card_idx * 8 + arg2 * 0x280));
        if (val_2 == *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + match_count * 0x120)) {
          *(int *)(&DAT_00516cbc + card_idx * 8 + arg2 * 0x280) =
               *(int *)(&DAT_00516cbc + card_idx * 8 + arg2 * 0x280) + 1;
          flag_1 = true;
        }
        card_idx = card_idx + 1;
      }
      *(int32_t *)(&g_CardSlot_CardId + arg1 * 0x5b20 + match_count * 0x120) = 0xffffffff;
    }
  }
  for (match_count = 0; match_count < 7; match_count = match_count + 1) {
    val_2 = FUN_0040a02a(arg2);
    Deck_AddCardToDeck(arg1,val_2);
  }
  return;
}



/*
 * Decompiled function: Pic_Util_00450975
 * Entry Point: 00450975
 * Size: 39 bytes
 */


void Pic_Util_00450975(DWORD player)

{
  PostMessageA(g_MainAppHwnd,0x401,player,0);
                    /* WARNING: Subroutine does not return */
  ExitThread(player);
}



/*
 * Decompiled function: Pic_Subsystem_004509a1
 * Entry Point: 004509a1
 * Size: 71 bytes
 */


void Pic_Subsystem_004509a1
               (int player_id,int *card_slot,int event_type,int arg_4,int32_t arg_5,int arg_6,char *arg_7)

{
  if ((player == 0) && (g_IsAiThinking != 1)) {
    Ai_Subsystem_004cc49a(card_slot,arg_3,arg_4,arg_5,arg_6,arg_7);
  }
  return;
}



/*
 * Decompiled function: UI_DeckSelectionMenu
 * Entry Point: 004509e8
 * Size: 2212 bytes
 */


int UI_DeckSelectionMenu(int player_id,int card_slot,int event_type,int32_t arg_4,int arg_5)

{
  int val_1;
  int val_2;
  DWORD DVar3;
  uint32_t uval_4;
  int val_5;
  char *stack_arg;
  int local_1800;
  void *local_17fc;
  int32_t local_17f8;
  int32_t local_17f4;
  int32_t auStackY_17f0 [6];
  int32_t auStackY_17d8 [4];
  int32_t auStackY_17c8 [6];
  int32_t local_17b0;
  void *apvStackY_17ac [4];
  int local_179c;
  int32_t local_1798;
  int local_1794;
  int local_1790;
  int local_178c;
  int local_1788;
  int aiStackY_1784 [500];
  int aiStackY_fb4 [500];
  int local_7e4;
  int local_7e0;
  int local_7dc;
  int aiStackY_7d8 [487];
  int32_t uStackY_3c;
  int *piVar6;
  void *arg_6;
  int val_7;
  
  Mem_AllocOrFree_00513bd0();
  if ((g_CurrentTurnPhase == player) && (g_IsAiThinking != 1)) {
    if (g_AiCombatScore_Blocker == 0) {
      Catalog_LoadPaletteMap(s_todpal_tr_00523e50,(char *)0x0);
      FUN_0050d560(0,0);
      SelectPalette(_hdcScreen,DAT_00626834,0);
      LoadPalNoPic(s_advfac64_pic_00523e5c);
      FileIO_OpenFileStream(1,0,0,s_seedeck_pic_00523e6c,(short *)&DAT_0070a130);
      uStackY_3c = 0x450b44;
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
      local_1788 = 0;
      for (val_7 = 0; val_7 < arg_3; val_7 = val_7 + 1) {
        if ((*(int *)(card_slot + val_7 * 4) != -1) &&
           ((val_7 == 0 || (*(int *)(card_slot + -4 + val_7 * 4) != *(int *)(card_slot + val_7 * 4))))) {
          local_1788 = local_1788 + 1;
        }
      }
      local_7dc = (local_1788 + -1) / 5;
      if (local_7dc == 0) {
        local_7dc = 1;
      }
      local_1790 = (int)(0x54 / (longlong)local_7dc);
      local_7e0 = 0x60;
      local_7dc = 0;
      local_7e4 = 0x10;
      for (val_7 = 0; val_7 < arg_3; val_7 = val_7 + 1) {
        if ((*(int *)(card_slot + val_7 * 4) != -1) &&
           ((val_7 == 0 || (*(int *)(card_slot + -4 + val_7 * 4) != *(int *)(card_slot + val_7 * 4))))) {
          aiStackY_fb4[local_7dc] = local_7e0 + 4;
          aiStackY_1784[local_7dc] = local_7e4;
          aiStackY_7d8[local_7dc] = val_7;
          local_7dc = local_7dc + 1;
          local_7e0 = local_7e0 + 0x38;
          if (0x13f < local_7e0) {
            local_7e0 = 0x60;
            local_7e4 = local_7e4 + local_1790;
          }
        }
      }
      FUN_0040c421(arg_4,0xa0,2,0xff);
      local_179c = -1;
      local_1794 = 0;
      Sprite_LoadAll(&local_17fc,s_BuyButtons_spr_00523e78);
      apvStackY_17ac[3] = local_17fc;
      local_1798 = local_17f8;
      local_17b0 = local_17f4;
      for (local_1800 = 0; local_1800 < 3; local_1800 = local_1800 + 1) {
        apvStackY_17ac[local_1800] = (void *)auStackY_17f0[local_1800];
      }
      for (local_1800 = 0; local_1800 < 3; local_1800 = local_1800 + 1) {
        auStackY_17c8[local_1800 + 3] = auStackY_17f0[local_1800 + 3];
      }
      for (local_1800 = 0; local_1800 < 3; local_1800 = local_1800 + 1) {
        auStackY_17c8[local_1800] = auStackY_17f0[local_1800 + 6];
      }
      for (val_7 = 0; val_7 < local_7dc; val_7 = val_7 + 1) {
        FUN_0050b206(*(uint32_t *)(card_slot + aiStackY_7d8[val_7] * 4) & 0xfff,aiStackY_fb4[val_7],
                     aiStackY_1784[val_7],0,&DAT_00523e88);
      }
      while( true ) {
        do {
          Pic_Subsystem_0044b84b();
          local_178c = -1;
          g_MouseScreenCoordX = (g_MouseScreenCoordX * 0x140) / g_AiManaColorCost_Red;
          g_MouseScreenCoordY = (g_MouseScreenCoordY * 0xf0) / g_AiManaColorCost_Green;
          for (val_7 = 0; val_7 < local_7dc; val_7 = val_7 + 1) {
            if ((((aiStackY_fb4[val_7] <= g_MouseScreenCoordX) &&
                 (g_MouseScreenCoordX < aiStackY_fb4[val_7] + 0x30)) &&
                (aiStackY_1784[val_7] <= g_MouseScreenCoordY)) &&
               (g_MouseScreenCoordY < aiStackY_1784[val_7] + 0x30)) {
              local_178c = aiStackY_7d8[val_7];
            }
          }
          if ((local_178c != -1) &&
             (*(int *)(card_slot + local_179c * 4) != *(int *)(card_slot + local_178c * 4))) {
            FUN_0050b206(*(uint32_t *)(card_slot + local_178c * 4) & 0xfff,8,0x40,1,&DAT_00523e8c);
            local_179c = local_178c;
          }
          if (arg_5 == 0) {
            if ((g_CombatAttackerSlotIndex == 0) && (val_7 = Mem_AllocOrFree_00408089(), val_7 == 0)) {
              local_1794 = 0;
            }
            else {
              local_1794 = 1;
            }
          }
          else if (((g_CombatAttackerSlotIndex == 0) && (val_7 = Mem_AllocOrFree_00408089(), val_7 == 0)) ||
                  (local_178c == -1)) {
            local_1794 = 0;
          }
          else {
            local_1794 = 1;
          }
        } while (local_1794 == 0);
        if (arg_5 == 0) break;
        val_7 = Ai_Util_004c3ba3(0x34);
        val_7 = val_7 / 2;
        val_1 = Ai_Util_004c3ba3(0xdc);
        val_1 = val_1 / 2;
        piVar6 = (int *)g_DisplaySurfaceBackBuffer;
        val_2 = Ai_Util_004c3ba3(0x111);
        DVar3 = val_2 / 2;
        val_2 = Ai_Util_004c3ba3(0xc5);
        uval_4 = val_2 / 2;
        val_2 = Ai_Util_004c3ba3(0x34);
        val_2 = val_2 / 2;
        val_5 = Ai_Util_004c3ba3(0xdc);
        Surface_BlitToDevice((int *)g_DisplaySurfaceScreen,val_5 / 2,val_2,uval_4,DVar3,piVar6,val_1,val_7);
        strcpy(&g_OverworldWorldState,s_Take_00523e90);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + *(int *)(card_slot + local_178c * 4) * 0x34);
        strcat(&g_OverworldWorldState,s__Y_N__00523e98);
        arg_6 = apvStackY_17ac[3];
        val_7 = Ai_Util_004c3ba3(0x10f);
        val_7 = val_7 / 2;
        val_1 = Ai_Util_004c3ba3(0xc5);
        val_1 = val_1 / 2;
        val_2 = Ai_Util_004c3ba3(0x34);
        val_2 = val_2 / 2;
        val_5 = Ai_Util_004c3ba3(0xdc);
        Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_5 / 2,val_2,val_1,val_7,(int)arg_6);
        FUN_0050b3de(*(uint32_t *)(card_slot + local_178c * 4) & 0xfff,0x7a,0x29,0x4b,0x70,1,&DAT_00523ea4);
        *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
        FUN_0040c381(&g_OverworldWorldState,0x76,0x20,0x1b);
        val_7 = FUN_0048ac2f();
        if ((val_7 == 0x79) || (val_7 == 0x59)) break;
        val_7 = Ai_Util_004c3ba3(0x34);
        val_7 = val_7 / 2;
        val_1 = Ai_Util_004c3ba3(0xdc);
        val_1 = val_1 / 2;
        piVar6 = (int *)g_DisplaySurfaceScreen;
        val_2 = Ai_Util_004c3ba3(0x111);
        DVar3 = val_2 / 2;
        val_2 = Ai_Util_004c3ba3(0xc5);
        uval_4 = val_2 / 2;
        val_2 = Ai_Util_004c3ba3(0x34);
        val_2 = val_2 / 2;
        val_5 = Ai_Util_004c3ba3(0xdc);
        Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,val_5 / 2,val_2,uval_4,DVar3,piVar6,val_1,
                     val_7);
        App_ProcessPendingMessages();
      }
      Mem_AllocOrFree_0050fc50(apvStackY_17ac[3]);
      Palette_Subsystem_00496eaf();
    }
    else {
      local_178c = Ai_Subsystem_004cc455((int *)card_slot,arg_3,arg_4,arg_5,stack_arg);
    }
  }
  else {
    local_7dc = 0;
    for (val_7 = 0; val_7 < arg_3; val_7 = val_7 + 1) {
      if (*(int *)(card_slot + val_7 * 4) != -1) {
        aiStackY_7d8[local_7dc] = val_7;
        local_7dc = local_7dc + 1;
      }
    }
    g_AiDecisionScore = Util_GetRandomNumber(local_7dc);
    if (g_CurrentTurnPhase != player) {
      if (g_IsAiThinking == 1) {
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
    }
    local_178c = aiStackY_7d8[g_AiDecisionScore];
  }
  return local_178c;
}



/*
 * Decompiled function: Deck_AddCardToDeck
 * Entry Point: 00451291
 * Size: 186 bytes
 */


int Deck_AddCardToDeck(int arg1,int arg2)

{
  int slot_idx;
  
  if (arg2 != -1) {
    for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
      if (*(int *)(&g_ActiveCardsInPlay + slot_idx * 0x120 + arg1 * 0x5b20) == -1) {
        Pic_Subsystem_0045134b(arg1,arg2,slot_idx);
        if ((int)(&g_PlayerActiveCardCount)[arg1] <= slot_idx) {
          (&g_PlayerActiveCardCount)[arg1] = slot_idx + 1;
          return slot_idx;
        }
        return slot_idx;
      }
    }
    Engine_ReportFatalError(s_AddCard_error_00523ea8);
  }
  return -1;
}



/*
 * Decompiled function: Pic_Subsystem_0045134b
 * Entry Point: 0045134b
 * Size: 1837 bytes
 */


void Pic_Subsystem_0045134b(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int slot_idx;
  
  *(int *)(&g_ActiveCardsInPlay + arg_3 * 0x120 + player * 0x5b20) = card_slot;
  *(int32_t *)(&g_CardSlot_CardId + arg_3 * 0x120 + player * 0x5b20) =
       *(int32_t *)(&g_ActiveCardsInPlay + arg_3 * 0x120 + player * 0x5b20);
  *(int32_t *)(&g_CardSlot_Controller + arg_3 * 0x120 + player * 0x5b20) = 0;
  if (player == 0) {
    *(int32_t *)(&g_CardSlot_Flags + arg_3 * 0x120) = 0;
  }
  else {
    *(int32_t *)(&g_CardSlot_Flags + arg_3 * 0x120 + player * 0x5b20) = 0x1000;
  }
  *(int16_t *)(&g_CardSlot_Power + arg_3 * 0x120 + player * 0x5b20) = 0;
  (&g_CardSlot_Toughness)[arg_3 * 0x120 + player * 0x5b20] = 0xff;
  *(int32_t *)(&g_CardSlot_OriginalCardId + arg_3 * 0x120 + player * 0x5b20) = 0xffffffff;
  (&g_CardSlot_DamageReceived)[arg_3 * 0x120 + player * 0x5b20] = 0xff;
  *(int32_t *)(&g_CardSlot_TypeFlags + arg_3 * 0x120 + player * 0x5b20) = 0xffffffff;
  *(int16_t *)(&g_CardSlot_Counters + arg_3 * 0x120 + player * 0x5b20) =
       *(int16_t *)(&DAT_0051aec2 + card_slot * 0x34);
  *(int16_t *)(&DAT_006a5f46 + arg_3 * 0x120 + player * 0x5b20) =
       *(int16_t *)(&DAT_0051aec4 + card_slot * 0x34);
  *(int16_t *)(&g_CardSlot_PowerCounters + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(int16_t *)(&g_CardSlot_ToughnessCounters + arg_3 * 0x120 + player * 0x5b20) = 0;
  (&g_CardSlot_MinusOneCounters)[arg_3 * 0x120 + player * 0x5b20] = (&g_MasterCardColorTable)[card_slot * 0x34];
  (&g_CardSlot_PlusOneCounters)[arg_3 * 0x120 + player * 0x5b20] = (&g_CardSlot_MinusOneCounters)[arg_3 * 0x120 + player * 0x5b20];
  (&g_CardSlot_ColorMask)[arg_3 * 0x120 + player * 0x5b20] = 0xff;
  (&DAT_006a5f4f)[arg_3 * 0x120 + player * 0x5b20] = 0;
  (&g_CardSlot_CardTypeIndex)[arg_3 * 0x120 + player * 0x5b20] = 0;
  *(int32_t *)(&g_CardSlot_TargetSlot + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_3 * 0x120 + player * 0x5b20) =
       *(int32_t *)(&g_CardSlot_TargetSlot + arg_3 * 0x120 + player * 0x5b20);
  *(int32_t *)(&g_CardSlot_DisplayIndex + arg_3 * 0x120 + player * 0x5b20) = 0xffffffff;
  *(int32_t *)(&g_CardSlot_Abilities1 + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(int32_t *)(&g_CardSlot_Abilities2 + arg_3 * 0x120 + player * 0x5b20) = 0x8000000;
  uval_1 = Pic_Subsystem_00451b1c(player,arg_3);
  *(int32_t *)(&DAT_006a5f70 + arg_3 * 0x120 + player * 0x5b20) = uval_1;
  *(int32_t *)(&DAT_006a5f7c + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(int32_t *)(&DAT_006a5f80 + arg_3 * 0x120 + player * 0x5b20) = 0;
  (&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + player * 0x5b20] = 0;
  *(int32_t *)(&g_CardSlot_ProtectionFlags + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(int32_t *)(&g_CardSlot_SpecialState + arg_3 * 0x120 + player * 0x5b20) =
       *(int32_t *)(&g_CardSlot_ProtectionFlags + arg_3 * 0x120 + player * 0x5b20);
  for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
    (&DAT_006a603c)[slot_idx + player * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006a6048)[slot_idx + player * 0x5b20 + arg_3 * 0x120] =
         (&DAT_006a603c)[slot_idx + player * 0x5b20 + arg_3 * 0x120];
  }
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    (&DAT_006a6029)[slot_idx + player * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006a602f)[slot_idx + player * 0x5b20 + arg_3 * 0x120] = 0;
  }
  for (slot_idx = 0; slot_idx < 0x14; slot_idx = slot_idx + 1) {
    *(int32_t *)(&g_CardSlot_CombatTarget + arg_3 * 0x120 + player * 0x5b20 + slot_idx * 8) =
         0xffffffff;
    *(int32_t *)(&g_CardSlot_AttachedAura + arg_3 * 0x120 + player * 0x5b20 + slot_idx * 8) =
         0xffffffff;
  }
  if (((&g_MasterCardFlagsTable)[card_slot * 0x34] & 0x10) != 0) {
    if (((&g_MasterCardColorTable)[card_slot * 0x34] == '\x01') ||
       ((&g_MasterCardColorTable)[card_slot * 0x34] == '@')) {
      (&g_CardSlot_MinusOneCounters)[arg_3 * 0x120 + player * 0x5b20] = 1;
    }
    if (*(int *)(&g_MasterCardTypeTable + card_slot * 0x34) == 0xf) {
      (&g_CardSlot_PlusOneCounters)[arg_3 * 0x120 + player * 0x5b20] = 0x3e;
    }
    else if (*(int *)(&g_MasterCardTypeTable + card_slot * 0x34) == 300) {
      (&g_CardSlot_PlusOneCounters)[arg_3 * 0x120 + player * 0x5b20] = 1;
    }
  }
  FUN_00476482(player,arg_3);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00451a82
 * Entry Point: 00451a82
 * Size: 154 bytes
 */


int32_t Pic_Subsystem_00451a82(void)

{
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < 0x50; match_count = match_count + 1) {
      if (*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) == -1) {
        *(int32_t *)(&g_ActiveCardsInPlay + match_count * 0x120 + slot_idx * 0x5b20) = 0xffffffff;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_00451b1c
 * Entry Point: 00451b1c
 * Size: 406 bytes
 */


int Pic_Subsystem_00451b1c(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  int target_idx;
  int match_count;
  
  val_1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  uval_2 = *(uint32_t *)(&DAT_0051aecc + val_1 * 0x34);
  target_idx = ((int)*(short *)(&DAT_0051aec2 + val_1 * 0x34) & 0xffffbfffU) * 2;
  if ((&g_MasterCardRarityTable)[val_1 * 0x34] == '\0') {
    target_idx = 0;
  }
  match_count = (int)((target_idx + 2) *
                 (((int)*(short *)(&DAT_0051aec4 + val_1 * 0x34) & 0xffffbfffU) + 1)) / 2;
  if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
     (arg1 == g_DefendingPlayer)) {
    match_count = match_count + -1;
  }
  if ((uval_2 & 0x80) != 0) {
    match_count = (match_count * 3) / 2;
  }
  if ((uval_2 & 0x100) != 0) {
    match_count = (match_count * 3) / 2;
  }
  if (((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 3) != 0) {
    match_count = (match_count * 3) / 2;
  }
  if ((uval_2 & 0x40) != 0) {
    match_count = (int)((((int)*(short *)(&DAT_0051aec4 + val_1 * 0x34) & 0xffffbfffU) + 1) * match_count) /
              2;
  }
  if ((uval_2 & 0x200) != 0) {
    match_count = (match_count * 3) / 2;
  }
  return (int)(*(int *)(&g_AiPlayerLifeDifferential + arg1 * 4) * match_count +
              (*(int *)(&g_AiPlayerLifeDifferential + arg1 * 4) * match_count >> 0x1f & 7U)) >> 3;
}



/*
 * Decompiled function: Pic_Subsystem_00451cb2
 * Entry Point: 00451cb2
 * Size: 222 bytes
 */


uint32_t Pic_Subsystem_00451cb2(void)

{
  uint32_t uval_1;
  int val_2;
  int local_7dc;
  int aiStack_7d8 [500];
  int slot_idx;
  
  slot_idx = 0;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if ((*(int *)(&deck + local_7dc * 4) != -1) && (((&DAT_00702151)[local_7dc * 4] & 0xc0) == 0)) {
      aiStack_7d8[slot_idx] = local_7dc;
      slot_idx = slot_idx + 1;
    }
  }
  if (slot_idx == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    val_2 = Util_GetRandomNumber(slot_idx);
    *(uint32_t *)(&deck + aiStack_7d8[val_2] * 4) = *(uint32_t *)(&deck + aiStack_7d8[val_2] * 4) | 0x8000;
    uval_1 = *(uint32_t *)(&deck + aiStack_7d8[val_2] * 4) & 0xfff;
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00451d90
 * Entry Point: 00451d90
 * Size: 176 bytes
 */


int Pic_Subsystem_00451d90(uint32_t arg1,uint32_t arg2)

{
  bool flag_1;
  int val_2;
  int card_idx;
  
  card_idx = 0;
  do {
    flag_1 = false;
    val_2 = Util_GetRandomNumber(g_MasterCardCount + -0x29);
    if (((arg1 == 0) || ((arg1 & (uint8_t)(&g_MasterCardColorTable)[val_2 * 0x34]) != 0)) &&
       ((arg2 == 1 || ((arg2 & (int)(char)(&g_MasterCardColorTable)[val_2 * 0x34]) != 0)))) {
      flag_1 = true;
    }
  } while ((!flag_1) && (card_idx = card_idx + 1, card_idx < 999));
  return val_2;
}



/*
 * Decompiled function: Pic_Subsystem_00451e40
 * Entry Point: 00451e40
 * Size: 461 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pic_Subsystem_00451e40(uint32_t player)

{
  uint8_t flag_1;
  char cVar2;
  bool flag_3;
  int val_4;
  uint32_t uval_5;
  int val_6;
  int player_idx;
  
  val_4 = File_Load_Info(player);
  if (2 < val_4) {
    FUN_0040b3c2(((int)(player + ((int)player >> 0x1f & 0xffU)) >> 8) + 8,player & 0xff);
  }
  val_4 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[player * 0x34]);
  flag_1 = (&g_MasterCardColorTable)[player * 0x34];
  cVar2 = s_Swamp_0051aea9[player * 0x34];
  flag_3 = false;
  for (player_idx = 0; player_idx < 500; player_idx = player_idx + 1) {
    if (*(int *)(&deck + player_idx * 4) == -1) {
      flag_3 = true;
    }
  }
  if (flag_3) {
    for (player_idx = 0x1f2; -1 < player_idx; player_idx = player_idx + -1) {
      if (*(int *)(&deck + player_idx * 4) != -1) {
        uval_5 = *(uint32_t *)(&deck + player_idx * 4) & 0xfff;
        val_6 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[uval_5 * 0x34]);
        if ((int)(val_4 * 0x20 + (uint32_t)flag_1 * 0x100 + (int)cVar2) <=
            (int)(val_6 * 0x20 + (uint32_t)(uint8_t)(&g_MasterCardColorTable)[uval_5 * 0x34] * 0x100 +
                 (int)s_Swamp_0051aea9[uval_5 * 0x34])) {
          *(uint32_t *)(player_idx * 4 + 0x702154) = player;
          return player_idx + 1;
        }
        *(int32_t *)(player_idx * 4 + 0x702154) = *(int32_t *)(&deck + player_idx * 4);
      }
    }
    _deck = player;
    val_4 = 0;
  }
  else {
    val_4 = -1;
  }
  return val_4;
}



/*
 * Decompiled function: Pic_Subsystem_0045200d
 * Entry Point: 0045200d
 * Size: 88 bytes
 */


void Pic_Subsystem_0045200d(uint32_t player)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return;
    }
    if ((*(uint32_t *)(&deck + slot_idx * 4) & 0xfff) == player) break;
    slot_idx = slot_idx + 1;
  }
  Pic_Subsystem_00452065(slot_idx);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00452065
 * Entry Point: 00452065
 * Size: 77 bytes
 */


void Pic_Subsystem_00452065(int player_id)

{
  int slot_idx;
  
  while (slot_idx = player + 1, slot_idx < 500) {
    (&DAT_0070214c)[slot_idx] = *(int32_t *)(&deck + slot_idx * 4);
    player = slot_idx;
  }
  DAT_0070291c = 0xffffffff;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004520b2
 * Entry Point: 004520b2
 * Size: 244 bytes
 */


void Pic_Subsystem_004520b2(void)

{
  int val_1;
  int local_7dc;
  uint32_t auStack_7d8 [500];
  int32_t slot_idx;
  
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    auStack_7d8[local_7dc] = *(uint32_t *)(&deck + local_7dc * 4);
    *(int32_t *)(&deck + local_7dc * 4) = 0xffffffff;
  }
  slot_idx = DAT_0067bde0;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if (auStack_7d8[local_7dc] != 0xffffffff) {
      val_1 = Pic_Subsystem_00451e40(auStack_7d8[local_7dc] & 0xfff);
      *(uint32_t *)(&deck + val_1 * 4) =
           *(uint32_t *)(&deck + val_1 * 4) | auStack_7d8[local_7dc] & 0xfffff000;
    }
  }
  DAT_0067bde0 = slot_idx;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004521a6
 * Entry Point: 004521a6
 * Size: 208 bytes
 */


int32_t Pic_Subsystem_004521a6(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  
  if ((player == 1) || (card_slot == 1)) {
    uval_1 = 1;
  }
  else {
    val_2 = Rules_CalculateManaCostReduction((uint8_t)player);
    val_3 = Rules_CalculateManaCostReduction((uint8_t)card_slot);
    if ((char)(&DAT_00523bc8)[val_3 * 3] == val_2) {
      uval_1 = 1;
    }
    else if ((arg_3 < 2) || ((char)(&DAT_00523bc9)[val_3 * 3] != val_2)) {
      if ((arg_3 < 3) || ((char)(&DAT_00523bca)[val_3 * 3] != val_2)) {
        if (arg_3 < 4) {
          uval_1 = 0;
        }
        else {
          uval_1 = 1;
        }
      }
      else {
        uval_1 = 1;
      }
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Pic_Subsystem_00452276
 * Entry Point: 00452276
 * Size: 391 bytes
 */


void Pic_Subsystem_00452276(int player_id)

{
  int32_t uval_1;
  DWORD DVar2;
  int val_3;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (g_IsAiThinking != 1) {
    Duel_PlaySoundById(0x21);
    Ai_Subsystem_004b58d9(player);
  }
  slot_idx = 500;
  match_count = 0;
  do {
    if (499 < match_count) {
LAB_004522f5:
      match_count = 0;
      while( true ) {
        DVar2 = GetTickCount();
        if ((int)(DVar2 >> 0x10) <= match_count) break;
        rand();
        match_count = match_count + 1;
      }
      for (card_idx = 0; card_idx < 100; card_idx = card_idx + 1) {
        for (match_count = 0; match_count < slot_idx; match_count = match_count + 1) {
          val_3 = Util_GetRandomNumber(slot_idx);
          if (*(int *)(&g_PlayerDeckCardList + val_3 * 4 + player * 2000) != -1) {
            uval_1 = *(int32_t *)(&g_PlayerDeckCardList + val_3 * 4 + player * 2000);
            *(int32_t *)(&g_PlayerDeckCardList + val_3 * 4 + player * 2000) =
                 *(int32_t *)(&g_PlayerDeckCardList + match_count * 4 + player * 2000);
            *(int32_t *)(&g_PlayerDeckCardList + match_count * 4 + player * 2000) = uval_1;
          }
        }
      }
      return;
    }
    if (*(int *)(&g_PlayerDeckCardList + match_count * 4 + player * 2000) == -1) {
      slot_idx = match_count;
      goto LAB_004522f5;
    }
    match_count = match_count + 1;
  } while( true );
}



/*
 * Decompiled function: Pic_Subsystem_004523fd
 * Entry Point: 004523fd
 * Size: 97 bytes
 */


void Pic_Subsystem_004523fd(int arg1,int arg2)

{
  int slot_idx;
  
  while (slot_idx = arg2 + 1, slot_idx < 500) {
    *(int32_t *)(&DAT_0069e72c + slot_idx * 4 + arg1 * 2000) =
         *(int32_t *)(&g_PlayerDeckCardList + slot_idx * 4 + arg1 * 2000);
    arg2 = slot_idx;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0045245e
 * Entry Point: 0045245e
 * Size: 125 bytes
 */


int Pic_Subsystem_0045245e(int arg1,int32_t arg2)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return -1;
    }
    if (*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + arg1 * 2000) == -1) break;
    slot_idx = slot_idx + 1;
  }
  *(int32_t *)(&g_PlayerDeckCardList + slot_idx * 4 + arg1 * 2000) = arg2;
  return slot_idx;
}



/*
 * Decompiled function: Pic_Subsystem_004524db
 * Entry Point: 004524db
 * Size: 118 bytes
 */


void Pic_Subsystem_004524db(int arg1,int32_t arg2)

{
  int slot_idx;
  
  for (slot_idx = 499; 0 < slot_idx; slot_idx = slot_idx + -1) {
    *(int32_t *)(&g_PlayerDeckCardList + slot_idx * 4 + arg1 * 2000) =
         *(int32_t *)(&DAT_0069e72c + slot_idx * 4 + arg1 * 2000);
  }
  *(int32_t *)(&g_PlayerDeckCardList + arg1 * 2000) = arg2;
  return;
}



/*
 * Decompiled function: File_Load_Info
 * Entry Point: 00452551
 * Size: 318 bytes
 */


int File_Load_Info(int player_id)

{
  int val_1;
  char local_28 [32];
  int slot_idx;
  
  if (((*(uint32_t *)(&g_MasterCardSubtypeTable + player * 0x34) & 0x180) != 0) ||
     ((&DAT_0051aed6)[player * 0x34] == '@')) {
    (&DAT_0051aed4)[player * 0x34] = 4;
  }
  if ((&DAT_0051aed4)[player * 0x34] == -1) {
    Csv_SearchMaster_00406681
              (local_28,*(int *)(&g_MasterCardTypeTable + player * 0x34),9,s_info_csv_00523eb8);
    slot_idx = 1;
    val_1 = strcmp(local_28,s_Special_00523ec4);
    if (val_1 == 0) {
      slot_idx = 3;
    }
    val_1 = strcmp(local_28,&DAT_00523ecc);
    if (val_1 == 0) {
      slot_idx = 3;
    }
    val_1 = strcmp(local_28,s_Uncommon_00523ed4);
    if (val_1 == 0) {
      slot_idx = 2;
    }
    (&DAT_0051aed4)[player * 0x34] = (uint8_t)slot_idx;
  }
  else {
    slot_idx = (int)(char)(&DAT_0051aed4)[player * 0x34];
  }
  return slot_idx;
}



/*
 * Decompiled function: Pic_Subsystem_0045268f
 * Entry Point: 0045268f
 * Size: 121 bytes
 */


int Pic_Subsystem_0045268f(int player_id)

{
  int slot_idx;
  
  if (player != -1) {
    for (slot_idx = 0; slot_idx < g_MasterCardCount + 0x10; slot_idx = slot_idx + 1) {
      if (*(int *)(&g_MasterCardTypeTable + slot_idx * 0x34) == player) {
        return slot_idx;
      }
    }
  }
  return -1;
}



/*
 * Decompiled function: Pic_Subsystem_00452708
 * Entry Point: 00452708
 * Size: 82 bytes
 */


void Pic_Subsystem_00452708(char *filepath)

{
  int val_1;
  
  if (g_IsAiThinking != 1) {
    UI_PrepareCombatViewport();
    val_1 = FUN_0040c465(str_1);
    if (8 < val_1 + 8) {
      Ai_Subsystem_004cc97e(str_1);
    }
    Pic_Subsystem_0044b8aa();
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0045275a
 * Entry Point: 0045275a
 * Size: 57 bytes
 */


void Pic_Subsystem_0045275a(uint8_t *player)

{
  if (g_IsAiThinking != 1) {
    UI_PrepareCombatViewport();
    Ai_Util_004b128e(player);
    *player = 0;
    Pic_Subsystem_0044b8aa();
  }
  return;
}



