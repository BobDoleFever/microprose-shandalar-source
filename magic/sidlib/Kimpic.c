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
 * Decompiled function: Pic_Load_0042351b
 * Entry Point: 0042351b
 * Size: 792 bytes
 */


undefined4
Pic_Load_0042351b(int player,undefined4 card_slot,undefined4 arg_3,char *str_4,undefined1 *arg_5)

{
  char *_Str2;
  int iVar1;
  undefined4 arg_1_00;
  undefined4 arg_2_00;
  int local_414;
  int local_410;
  undefined1 local_40c [1024];
  byte *local_c;
  int local_8;
  
  local_8 = 8;
  _Str2 = strchr(str_4,0x2e);
  iVar1 = _stricmp(&DAT_00520cc8,_Str2);
  if (iVar1 == 0) {
    DAT_00703930 = (int)fopen(str_4,&DAT_00520cd0);
    if ((FILE *)DAT_00703930 == (FILE *)0x0) {
      return 0;
    }
    DAT_00703938 = str_4;
    if (arg_5 == (undefined1 *)0x1) {
      arg_5 = local_40c;
    }
    if (arg_5 == (undefined1 *)0x0) {
      FUN_00512500((void *)0x0);
      if (player < 0) {
        DAT_00536864 = 0;
      }
      if ((int)DAT_00536860 % 3 == 0) {
        local_410 = 0;
      }
      else {
        local_410 = 4 - (int)DAT_00536860 % 3;
      }
      DAT_00538ad4 = DAT_00536860 + local_410;
      FUN_004232f0(DAT_00538ad4,DAT_00536864,local_8);
      local_c = *(byte **)(PTR_DAT_00520cb8 + 0x18);
      for (DAT_00538adc = 0; DAT_00538adc < DAT_00536864; DAT_00538adc = DAT_00538adc + 1) {
        FUN_005126b0(local_c);
        local_c = local_c + ((int)(local_8 + (local_8 >> 0x1f & 7U)) >> 3) * DAT_00538ad4;
      }
      fclose((FILE *)DAT_00703930);
    }
    else {
      FUN_00512500(arg_5 + 6);
      *arg_5 = 0x4d;
      arg_5[1] = 0x31;
      *(undefined2 *)(arg_5 + 2) = 0x300;
      arg_5[4] = 0;
      arg_5[5] = 0xff;
    }
  }
  else {
    DAT_00538ae0 = Pic_Subsystem_004238ba(str_4,0x8000);
    if (DAT_00538ae0 == -1) {
      AssertOrLog(0,0x520cec,0xe4,s_Could_not_open_file__s_00520cd4);
      *(undefined4 *)(PTR_DAT_00520cb8 + 8) = 0;
    }
    else {
      Pic_Util_00423919(DAT_00538ae0);
      FUN_0070d000(arg_1_00,arg_2_00,(ushort *)arg_5);
      if ((DAT_00536860 & 3) == 0) {
        local_414 = 0;
      }
      else {
        local_414 = 4 - (DAT_00536860 & 3);
      }
      DAT_00538ad4 = DAT_00536860 + local_414;
      iVar1 = FUN_004232f0(DAT_00536860,DAT_00536864,local_8);
      if (iVar1 == 0) {
        *(undefined4 *)(PTR_DAT_00520cb8 + 8) = 0;
      }
      else {
        local_c = *(byte **)(PTR_DAT_00520cb8 + 0x18);
        DAT_00538adc = 0;
        while (DAT_00538adc < DAT_00536864) {
          Mem_AllocOrFree_0070d484(local_c,DAT_00536860);
          DAT_00538adc = DAT_00538adc + 1;
          local_c = (byte *)((int)local_c +
                            *(int *)(PTR_DAT_00520cb8 + 0x2c) +
                            ((int)(local_8 * DAT_00536860 +
                                  ((int)(local_8 * DAT_00536860) >> 0x1f & 7U)) >> 3));
        }
      }
      Pic_Subsystem_004238ee(DAT_00538ae0);
    }
  }
  return *(undefined4 *)(PTR_DAT_00520cb8 + 8);
}



/*
 * Decompiled function: Pic_Load_00423833
 * Entry Point: 00423833
 * Size: 135 bytes
 */


int Pic_Load_00423833(char *str_1)

{
  char local_1fc [500];
  int local_8;
  
  local_8 = Pic_Load_0042351b(0,0,0,str_1,(undefined1 *)0x0);
  if (local_8 != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_00520cb8);
  }
  if (DAT_006b157c != 0) {
    sprintf(local_1fc,s__08X_LoadKimPicture___s___file_m_00520d10,local_8,str_1,
            *(undefined4 *)PTR_DAT_00520cb8);
    OutputDebugStringA(local_1fc);
  }
  return local_8;
}



/*
 * Decompiled function: Pic_Subsystem_004238ba
 * Entry Point: 004238ba
 * Size: 52 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pic_Subsystem_004238ba(char *str_1,int arg2)

{
  int iVar1;
  
  iVar1 = _open(str_1,arg2);
  _DAT_00538ae8 = 0xffffffff;
  return iVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004238ee
 * Entry Point: 004238ee
 * Size: 43 bytes
 */


void Pic_Subsystem_004238ee(int player)

{
  if (player != DAT_00520cbc) {
    _close(player);
  }
  return;
}



/*
 * Decompiled function: Pic_Util_00423919
 * Entry Point: 00423919
 * Size: 39 bytes
 */


void Pic_Util_00423919(undefined4 player)

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
  int iVar1;
  
  iVar1 = _read(DAT_00538ae4,&DAT_00706510,0x200);
  DAT_00706500 = &DAT_00706510;
  return iVar1;
}



/*
 * Decompiled function: Sound_Init
 * Entry Point: 00423980
 * Size: 353 bytes
 */


int Sound_Init(int hInst,undefined4 hWnd,uint flags)

{
  int iVar1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_00520d44 == 0) {
    DAT_0067f3c8 = LoadLibraryA(PTR_s_magsnd_00520d4c);
    if (DAT_0067f3c8 == (HMODULE)0x0) {
      iVar1 = 4;
    }
    else {
      for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_0067f3c8,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_0067f3d0)[local_c] = pFVar2;
        if ((&DAT_0067f3d0)[local_c] == (code *)0x0) {
          FreeLibrary(DAT_0067f3c8);
          Pic_Subsystem_004241ae();
          return 4;
        }
      }
      if ((hInst == 0) && ((flags & 2) == 0)) {
        FreeLibrary(DAT_0067f3c8);
        Pic_Subsystem_004241ae();
        iVar1 = 5;
      }
      else {
        iVar1 = (*DAT_0067f3d0)(hInst,hWnd,flags);
        if (iVar1 == 0) {
          DAT_00520d48 = 1;
          if ((flags & 2) != 0) {
            DAT_00520d40 = 1;
          }
          DAT_00520d44 = 1;
          iVar1 = 0;
        }
        else {
          FreeLibrary(DAT_0067f3c8);
          Pic_Subsystem_004241ae();
        }
      }
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}



/*
 * Decompiled function: CloseSnd
 * Entry Point: 00423ae1
 * Size: 118 bytes
 */


void CloseSnd(void)

{
  if (DAT_00520d44 != 0) {
    DAT_00520d44 = 0;
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
 * Decompiled function: InitSndTrack
 * Entry Point: 00423b57
 * Size: 60 bytes
 */


undefined4 InitSndTrack(undefined4 player,undefined4 card_slot,undefined4 arg_3)

{
  undefined4 uVar1;
  
  if (DAT_00520d44 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3d8)(player,card_slot,arg_3);
  }
  return uVar1;
}



/*
 * Decompiled function: CloseSndTrack
 * Entry Point: 00423b93
 * Size: 52 bytes
 */


undefined4 CloseSndTrack(undefined4 player)

{
  undefined4 uVar1;
  
  if (DAT_00520d44 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3dc)(player);
  }
  return uVar1;
}



/*
 * Decompiled function: StopSndTrack
 * Entry Point: 00423bc7
 * Size: 45 bytes
 */


undefined4 StopSndTrack(void)

{
  undefined4 uVar1;
  
  if (DAT_00520d44 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3e0)();
  }
  return uVar1;
}



/*
 * Decompiled function: PlaySnd
 * Entry Point: 00423bf4
 * Size: 69 bytes
 */


undefined4 PlaySnd(undefined4 sound_id,undefined4 flags)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3e4)(sound_id,flags);
  }
  return uVar1;
}



/*
 * Decompiled function: PlaySndFile
 * Entry Point: 00423c39
 * Size: 73 bytes
 */


undefined4 PlaySndFile(undefined4 filename,undefined4 loop_flag,undefined4 out_handle)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3e8)(filename,loop_flag,out_handle);
  }
  return uVar1;
}



/*
 * Decompiled function: StopSnd
 * Entry Point: 00423c82
 * Size: 65 bytes
 */


undefined4 StopSnd(undefined4 sound_id)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3ec)(sound_id);
  }
  return uVar1;
}



/*
 * Decompiled function: PauseSnd
 * Entry Point: 00423cc3
 * Size: 48 bytes
 */


void PauseSnd(void)

{
  if ((DAT_00520d44 != 0) && (DAT_00520d44 != 2)) {
    (*DAT_0067f3f0)();
  }
  return;
}



/*
 * Decompiled function: ResumeSnd
 * Entry Point: 00423cf3
 * Size: 69 bytes
 */


undefined4 ResumeSnd(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3f4)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: SetPitch
 * Entry Point: 00423d38
 * Size: 69 bytes
 */


undefined4 SetPitch(undefined4 value,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3f8)(value,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetPitch
 * Entry Point: 00423d7d
 * Size: 69 bytes
 */


undefined4 GetPitch(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f3fc)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: SetVol
 * Entry Point: 00423dc2
 * Size: 69 bytes
 */


undefined4 SetVol(undefined4 value,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f400)(value,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetVol
 * Entry Point: 00423e07
 * Size: 69 bytes
 */


undefined4 GetVol(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f404)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: SetPan
 * Entry Point: 00423e4c
 * Size: 69 bytes
 */


undefined4 SetPan(undefined4 value,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f408)(value,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetPan
 * Entry Point: 00423e91
 * Size: 69 bytes
 */


undefined4 GetPan(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f40c)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: UpdateSnd
 * Entry Point: 00423ed6
 * Size: 58 bytes
 */


undefined4 UpdateSnd(void)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f410)();
  }
  return uVar1;
}



/*
 * Decompiled function: SetSndMarker
 * Entry Point: 00423f10
 * Size: 69 bytes
 */


undefined4 SetSndMarker(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f414)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: PlaySndMarker
 * Entry Point: 00423f55
 * Size: 69 bytes
 */


undefined4 PlaySndMarker(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f418)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetSndTime
 * Entry Point: 00423f9a
 * Size: 65 bytes
 */


undefined4 GetSndTime(undefined4 player)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f420)(player);
  }
  return uVar1;
}



/*
 * Decompiled function: ResetSnd
 * Entry Point: 00423fdb
 * Size: 69 bytes
 */


undefined4 ResetSnd(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f41c)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetSndState
 * Entry Point: 00424020
 * Size: 69 bytes
 */


undefined4 GetSndState(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f424)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetAVISndBuff
 * Entry Point: 00424065
 * Size: 66 bytes
 */


undefined4 GetAVISndBuff(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_0067f428)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: ReleaseAVISndBuff
 * Entry Point: 004240a7
 * Size: 69 bytes
 */


undefined4 ReleaseAVISndBuff(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f42c)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetSndHWND
 * Entry Point: 004240ec
 * Size: 55 bytes
 */


undefined4 GetSndHWND(void)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_0067f430)();
  }
  return uVar1;
}



/*
 * Decompiled function: IsSndLoaded
 * Entry Point: 00424123
 * Size: 66 bytes
 */


undefined4 IsSndLoaded(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_0067f434)(arg1,arg2);
  }
  return uVar1;
}



/*
 * Decompiled function: GetLRUSnd
 * Entry Point: 00424165
 * Size: 73 bytes
 */


undefined4 GetLRUSnd(undefined4 player,undefined4 card_slot,undefined4 arg_3)

{
  undefined4 uVar1;
  
  if ((DAT_00520d44 == 0) || (DAT_00520d44 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_0067f438)(player,card_slot,arg_3);
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004241ae
 * Entry Point: 004241ae
 * Size: 58 bytes
 */


void Pic_Subsystem_004241ae(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x1b; local_8 = local_8 + 1) {
    (&DAT_0067f3d0)[local_8] = 0;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004241f0
 * Entry Point: 004241f0
 * Size: 146 bytes
 */


bool Pic_Subsystem_004241f0(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = Pic_Subsystem_00424282;
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
 * Decompiled function: Pic_Subsystem_00424282
 * Entry Point: 00424282
 * Size: 516 bytes
 */


LRESULT Pic_Subsystem_00424282(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam)

{
  HDC hdc;
  LRESULT LVar1;
  tagPAINTSTRUCT local_134;
  CHAR local_f4 [200];
  tagRECT local_2c;
  HDC local_1c;
  tagRECT local_18;
  HBRUSH local_8;
  
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
      local_1c = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      GetClientRect(hwnd,&local_18);
      local_8 = CreateSolidBrush(0xffff);
      FillRect(local_1c,&local_18,local_8);
      DeleteObject(local_8);
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
 * Decompiled function: Pic_Load_004244a0
 * Entry Point: 004244a0
 * Size: 81 bytes
 */


void Pic_Load_004244a0(void)

{
  Mem_AllocOrFree_00510de0(1,s_hallback_pic_00520d58);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  Ai_Subsystem_004cd1d1();
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00424500
 * Entry Point: 00424500
 * Size: 597 bytes
 */


int Pic_Subsystem_00424500(char *str_1,char *str_2)

{
  FILE *_File;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int local_310;
  char local_30c [252];
  char local_210 [264];
  char local_108 [252];
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    strcpy(local_108,&DAT_00520d68);
    strcat(local_108,str_2);
    strcat(local_108,&DAT_00520d6c);
    strcpy(local_210,&DAT_006807a0);
    strcat(local_210,&DAT_00520d70);
    strcpy(local_210,str_1);
    _File = fopen(local_210,&DAT_00520d74);
    if (_File != (FILE *)0x0) {
      do {
        iVar1 = strcmp(local_108,local_30c);
        if (iVar1 == 0) {
          fscanf(_File,&DAT_00520d78,&local_8);
          fgets(local_30c,0x50,_File);
          local_c = 0;
          for (local_310 = 0; (local_310 < local_8 && (local_310 < 0x32)); local_310 = local_310 + 1
              ) {
            pcVar2 = fgets(&g_OverworldGoldAmount + local_310 * 0xfa,0xfa,_File);
            if (pcVar2 == (char *)0x0) {
              fclose(_File);
              return -local_c;
            }
            sVar3 = strlen(&g_OverworldGoldAmount + local_310 * 0xfa);
            (&DAT_0069f74f)[local_310 * 0xfa + sVar3] = 0;
            local_c = local_c + 1;
          }
          fclose(_File);
          if (local_c < local_8) {
            return -local_c;
          }
          return local_c;
        }
        pcVar2 = fgets(local_30c,0x50,_File);
      } while (pcVar2 != (char *)0x0);
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


int Pic_Subsystem_0042475a(char *str_1,char *str_2)

{
  int player;
  int iVar1;
  size_t sVar2;
  int local_18;
  int local_10;
  int local_c;
  
  if (g_IsAiThinking == 1) {
    player = 0;
  }
  else {
    player = Pic_Subsystem_00424500(str_1,str_2);
    for (local_c = 0; iVar1 = abs(player), local_c < iVar1; local_c = local_c + 1) {
      sVar2 = strlen(&g_OverworldGoldAmount + local_c * 0xfa);
      local_18 = 0;
      for (local_10 = 0; local_10 < (int)sVar2; local_10 = local_10 + 1) {
        if (((&g_OverworldGoldAmount)[local_c * 0xfa + local_10] == '\\') &&
           ((&DAT_0069f751)[local_c * 0xfa + local_10] == 'n')) {
          (&g_OverworldGoldAmount)[local_c * 0xfa + local_18] = 10;
          local_10 = local_10 + 1;
        }
        else {
          (&g_OverworldGoldAmount)[local_c * 0xfa + local_18] =
               (&g_OverworldGoldAmount)[local_c * 0xfa + local_10];
        }
        local_18 = local_18 + 1;
      }
      (&g_OverworldGoldAmount)[local_c * 0xfa + local_18] = 0;
    }
  }
  return player;
}



/*
 * Decompiled function: Pic_Load_004248b0
 * Entry Point: 004248b0
 * Size: 248 bytes
 */


undefined4 Pic_Load_004248b0(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Load_00424b1f;
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
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_Phase_pic_00520d7c);
  DAT_00538b20 = Pic_Load_00423833(local_138);
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
    GDI_DestroyDIBSection_Magic(DAT_00538b20);
  }
  if (DAT_00538b3c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538b3c);
  }
  DAT_00538b20 = (HANDLE)0x0;
  DAT_00538b3c = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: Pic_Load_00424a1e
 * Entry Point: 00424a1e
 * Size: 209 bytes
 */


undefined4 Pic_Load_00424a1e(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Load_004267c5;
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
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_PhaseCombat_pic_00520d90);
  DAT_00538b38 = Pic_Load_00423833(local_138);
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
    GDI_DestroyDIBSection_Magic(DAT_00538b38);
  }
  DAT_00538b38 = (HANDLE)0x0;
  return;
}



/*
 * Decompiled function: Pic_Load_00424b1f
 * Entry Point: 00424b1f
 * Size: 4956 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Pic_Load_00424b1f(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  bool bVar1;
  uint uVar2;
  UINT dwMilliseconds;
  HBRUSH pHVar3;
  int iVar4;
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
  undefined1 local_3b4 [4];
  int local_3b0;
  int local_3ac;
  tagPAINTSTRUCT local_39c;
  int local_35c;
  tagRECT local_358;
  int local_348;
  tagRECT local_344;
  tagMSG local_334;
  uint local_318;
  BOOL local_314;
  POINT local_310;
  tagRECT local_308;
  int local_2f8;
  char local_2f4 [264];
  ULONG_PTR local_1ec;
  int local_1e8;
  uint local_1e4;
  tagRECT local_1e0;
  tagRECT local_1d0;
  int local_1c0;
  uint local_1bc;
  int local_1b8;
  uint local_1b4;
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
  int local_20;
  tagRECT local_1c;
  LONG local_c;
  LONG local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      Ai_Subsystem_004b74b1(&local_348,&local_3b8);
      if ((local_c != local_3b8) || (local_8 != local_348)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (DAT_00538b20 == (HANDLE)0x0) {
        strcpy(local_4c8,&DAT_006b2e90);
        strcat(local_4c8,s__WINBK_Phase_pic_00520e78);
        DAT_00538b20 = (HANDLE)Pic_Load_00423833(local_4c8);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
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
        local_c = local_3b8;
        local_8 = local_348;
        SetWindowLongA(hwnd,0,local_3b8);
        SetWindowLongA(hwnd,4,local_8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_c = 0;
      local_8 = 0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,local_8);
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
        iVar4 = GetMenuItemCount(DAT_00538b40);
        if (iVar4 != 0) {
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
      if (((uint)wParam & 0xffff) == 100) {
        local_a0 = 0x7e5;
        strcpy(local_1a8,&DAT_006807a0);
        strcat(local_1a8,s__duel_hlp_00520e60);
        WinHelpA(g_MainAppHwnd,local_1a8,1,local_a0);
      }
      else {
        uVar2 = (uint)wParam & 0xffff;
        if (uVar2 < 0xfa) {
          if (uVar2 < 200) {
            local_1b0 = 0x96;
          }
          else {
            local_1b0 = 200;
          }
        }
        else {
          local_1b0 = 0xfa;
        }
        local_1b8 = uVar2 - local_1b0;
        bVar1 = 9 < local_1b8;
        if (bVar1) {
          local_1b8 = local_1b8 + -10;
        }
        local_1b4 = (uint)bVar1;
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
          DAT_00627864 = 0;
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
          if (((&DAT_00696740)[local_1e8 * 4 + local_1b4 * 0x98] & 1) == 0) {
            *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) | 1;
          }
          else {
            *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) & 0xfffffffe;
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
          strcpy(local_2f4,&DAT_006807a0);
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
        DAT_00627864 = local_314;
        _DAT_00538b28 = 0xfffffffe;
        _DAT_00538b2c = 0xffffffff;
        _DAT_00538b30 = 0xffffffff;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538b28);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
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
      local_c = GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      Ai_Subsystem_004b74b1(&local_98,&local_9c);
      if ((local_c != local_9c) || (local_8 != local_98)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_2c.x = lParam & 0xffff;
      local_2c.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_1c);
      Pic_Subsystem_00425ee3(&local_2c,&local_1c,&local_20,&local_30);
      local_24 = 1;
      if (local_20 == 0) {
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
        if (local_20 == 1) {
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


void Pic_Subsystem_00425ee3(POINT *x,RECT *card_slot,undefined4 *arg_3,int *height)

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
  undefined4 local_34;
  tagRECT local_28;
  tagRECT local_18;
  int local_8;
  
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
  local_8 = -1;
  local_34 = 1;
  Pic_Subsystem_004262cf(&local_18,1,1,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt);
  if (BVar1 != 0) {
    local_8 = 1;
  }
  Pic_Subsystem_004262cf(&local_18,1,4,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_00);
  if (BVar1 != 0) {
    local_8 = 4;
  }
  Pic_Subsystem_004262cf(&local_18,1,10,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_01);
  if (BVar1 != 0) {
    local_8 = 10;
  }
  Pic_Subsystem_004262cf(&local_18,1,0x14,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_02);
  if (BVar1 != 0) {
    local_8 = 0x14;
  }
  Pic_Subsystem_004262cf(&local_18,1,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_03);
  if (BVar1 != 0) {
    local_8 = 0x16;
  }
  Pic_Subsystem_004262cf(&local_18,1,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_04);
  if (BVar1 != 0) {
    local_8 = 0x1e;
  }
  Pic_Subsystem_004262cf(&local_18,1,0x1f,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_05);
  if (BVar1 != 0) {
    local_8 = 0x1f;
  }
  Pic_Subsystem_004262cf(&local_18,1,0x20,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_06);
  if (BVar1 != 0) {
    local_8 = 0x20;
  }
  if (local_8 == -1) {
    local_34 = 0;
    Pic_Subsystem_004262cf(&local_18,0,1,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_07);
    if (BVar1 != 0) {
      local_8 = 1;
    }
    Pic_Subsystem_004262cf(&local_18,0,4,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_08);
    if (BVar1 != 0) {
      local_8 = 4;
    }
    Pic_Subsystem_004262cf(&local_18,0,10,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_09);
    if (BVar1 != 0) {
      local_8 = 10;
    }
    Pic_Subsystem_004262cf(&local_18,0,0x14,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_10);
    if (BVar1 != 0) {
      local_8 = 0x14;
    }
    Pic_Subsystem_004262cf(&local_18,0,0x15,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_11);
    if (BVar1 != 0) {
      local_8 = 0x15;
    }
    Pic_Subsystem_004262cf(&local_18,0,0x1e,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_12);
    if (BVar1 != 0) {
      local_8 = 0x1e;
    }
    Pic_Subsystem_004262cf(&local_18,0,0x1f,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_13);
    if (BVar1 != 0) {
      local_8 = 0x1f;
    }
    Pic_Subsystem_004262cf(&local_18,0,0x20,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_14);
    if (BVar1 != 0) {
      local_8 = 0x20;
    }
  }
  *arg_3 = local_34;
  *height = local_8;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004262cf
 * Entry Point: 004262cf
 * Size: 585 bytes
 */


void Pic_Subsystem_004262cf(LPRECT player,int card_slot,int arg_3,int arg_4,int arg_5)

{
  undefined4 local_8;
  
  if ((card_slot == -1) || (arg_3 == -1)) {
    SetRect(player,0,0,0,0);
  }
  else {
    if (arg_3 == 1) {
      local_8 = (arg_5 * 2) / 0x2f8;
    }
    else if ((((arg_3 == 2) || (arg_3 == 3)) || (arg_3 == 4)) || (arg_3 == 5)) {
      local_8 = (arg_5 * 0x2b) / 0x2f8;
    }
    else if (arg_3 == 10) {
      local_8 = (arg_5 * 0x54) / 0x2f8;
    }
    else if (arg_3 == 0x14) {
      local_8 = (arg_5 * 0x7d) / 0x2f8;
    }
    else if (((card_slot == 1) && (arg_3 == 0x16)) || ((card_slot == 0 && (arg_3 == 0x15)))) {
      local_8 = (arg_5 * 0xa6) / 0x2f8;
    }
    else if (arg_3 == 0x1e) {
      local_8 = (arg_5 * 0xcf) / 0x2f8;
    }
    else if (arg_3 == 0x1f) {
      local_8 = (arg_5 * 0xf8) / 0x2f8;
    }
    else if (((arg_3 == 0x20) || (arg_3 == 0x21)) || ((arg_3 == 0x22 || (arg_3 == 0x25)))) {
      local_8 = (arg_5 * 0x121) / 0x2f8;
    }
    else {
      local_8 = -1;
    }
    if (local_8 == -1) {
      SetRect(player,0,0,0,0);
    }
    else {
      if (card_slot == 0) {
        local_8 = local_8 + (arg_5 * 0x1ae) / 0x2f8;
      }
      SetRect(player,0,local_8,arg_4,local_8 + (arg_5 * 0x28) / 0x2f8);
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
  tagRECT local_20;
  int local_10;
  HBRUSH local_c;
  int local_8;
  
  Ai_Subsystem_004b765d(&local_8,&local_24);
  if ((local_8 == -1) || (local_24 == -1)) {
    local_c = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,local_c);
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      Ai_Subsystem_004b74fa(local_d0,local_10);
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if (local_d0[local_d4] != 0) {
          Pic_Subsystem_004262cf
                    (&local_34,local_10,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&local_20,&local_34);
            local_20.left = local_20.right - (local_34.right - local_34.left) / 3;
            local_20.top = local_20.bottom -
                           ((local_20.right - local_20.left) * (local_34.bottom - local_34.top)) /
                           (local_34.right - local_34.left);
            Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
          }
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_c);
  }
  if ((local_8 != -1) && (local_24 != -1)) {
    local_c = CreateSolidBrush(0xff00);
    local_38 = SelectObject(hdc,local_c);
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if ((local_10 == local_8) && (local_d4 == local_24)) {
          Pic_Subsystem_004262cf
                    (&local_34,local_10,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&local_20,&local_34);
            local_20.right = local_20.left + (local_34.right - local_34.left) / 3;
            local_20.top = local_20.bottom -
                           ((local_20.right - local_20.left) * (local_34.bottom - local_34.top)) /
                           (local_34.right - local_34.left);
            Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
          }
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_c);
  }
  return;
}



/*
 * Decompiled function: Pic_Load_004267c5
 * Entry Point: 004267c5
 * Size: 4210 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Pic_Load_004267c5(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  uint uVar1;
  UINT dwMilliseconds;
  HBRUSH pHVar2;
  int iVar3;
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
  undefined1 local_3a4 [4];
  int local_3a0;
  int local_39c;
  tagPAINTSTRUCT local_38c;
  int local_34c;
  tagRECT local_348;
  int local_338;
  tagRECT local_334;
  undefined4 local_324;
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
  undefined4 local_1a0;
  char local_19c [264];
  ULONG_PTR local_94;
  int local_90;
  char local_8c [100];
  int local_28;
  POINT local_24;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b74b1(&local_338,&local_3a8);
      if (DAT_00538b38 == (HANDLE)0x0) {
        strcpy(local_4b8,&DAT_006b2e90);
        strcat(local_4b8,s__WINBK_PhaseCombat_pic_00520fb0);
        DAT_00538b38 = (HANDLE)Pic_Load_00423833(local_4b8);
      }
      if (local_8 != local_3a8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_3ac = g_HdcBackBuffer;
      local_34c = SaveDC(g_HdcBackBuffer);
      GetClientRect(hwnd,&local_334);
      Ai_Subsystem_004b74b1(&local_338,(undefined4 *)0x0);
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
        local_8 = local_3a8;
        SetWindowLongA(hwnd,0,local_3a8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0;
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
      Ai_Subsystem_004b74b1(&local_4d4,(undefined4 *)0x0);
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
        iVar3 = GetMenuItemCount(DAT_00538b40);
        if (iVar3 != 0) {
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
      if (((uint)wParam & 0xffff) == 100) {
        local_94 = 0x7e5;
        strcpy(local_19c,&DAT_006807a0);
        strcat(local_19c,s__duel_hlp_00520f98);
        WinHelpA(g_MainAppHwnd,local_19c,1,local_94);
      }
      else {
        uVar1 = (uint)wParam & 0xffff;
        if (uVar1 < 0xfa) {
          if (uVar1 < 200) {
            local_1a8 = 0x96;
          }
          else {
            local_1a8 = 200;
          }
        }
        else {
          local_1a8 = 0xfa;
        }
        local_1ac = uVar1 - local_1a8;
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
          Ai_Subsystem_004b74b1(&local_1a0,(undefined4 *)0x0);
          DAT_00627a84 = local_1a0;
          DAT_00627a88 = local_1b0;
          DAT_00627864 = 0;
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
          Ai_Subsystem_004b74b1(&local_1d4,(undefined4 *)0x0);
          if (((&DAT_00696740)[local_1d8 * 4 + local_1d4 * 0x98] & 1) == 0) {
            *(uint *)(&DAT_00696740 + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint *)(&DAT_00696740 + local_1d8 * 4 + local_1d4 * 0x98) | 1;
          }
          else {
            *(uint *)(&DAT_00696740 + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint *)(&DAT_00696740 + local_1d8 * 4 + local_1d4 * 0x98) & 0xfffffffe;
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
          strcpy(local_2e4,&DAT_006807a0);
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
        Ai_Subsystem_004b74b1(&local_324,(undefined4 *)0x0);
        DAT_00627a84 = local_324;
        DAT_00627a88 = local_2e8;
        DAT_00627864 = local_304;
        _DAT_00538b48 = 0xfffffffe;
        _DAT_00538b4c = 0xffffffff;
        _DAT_00538b50 = 0xffffffff;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538b48);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
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
      local_8 = GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b74b1((undefined4 *)0x0,&local_90);
      if (local_90 != local_8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_24.x = lParam & 0xffff;
      local_24.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_18);
      Pic_Subsystem_0042784d(&local_24,&local_18,&local_28);
      local_1c = 1;
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
        local_1c = 0;
      }
      if (local_1c == 0) {
        return 0;
      }
      strcpy(wParam,local_8c);
      return local_1c;
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


void Pic_Subsystem_0042784d(POINT *player,RECT *card_slot,undefined4 *arg_3)

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
  tagRECT local_18;
  undefined4 local_8;
  
  CopyRect(&local_28,card_slot);
  pt_05 = *player;
  pt_04 = *player;
  pt_03 = *player;
  pt_02 = *player;
  pt_01 = *player;
  pt_00 = *player;
  pt = *player;
  local_8 = 0xffffffff;
  Pic_Subsystem_00427a0a(&local_18,0x15,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt);
  if (BVar1 != 0) {
    local_8 = 0x15;
  }
  Pic_Subsystem_00427a0a(&local_18,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_00);
  if (BVar1 != 0) {
    local_8 = 0x16;
  }
  Pic_Subsystem_00427a0a(&local_18,0x17,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_01);
  if (BVar1 != 0) {
    local_8 = 0x17;
  }
  Pic_Subsystem_00427a0a(&local_18,0x18,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_02);
  if (BVar1 != 0) {
    local_8 = 0x18;
  }
  Pic_Subsystem_00427a0a(&local_18,0x19,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_03);
  if (BVar1 != 0) {
    local_8 = 0x19;
  }
  Pic_Subsystem_00427a0a(&local_18,0x1b,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_04);
  if (BVar1 != 0) {
    local_8 = 0x1a;
  }
  Pic_Subsystem_00427a0a(&local_18,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_05);
  if (BVar1 != 0) {
    local_8 = 0x1e;
  }
  *arg_3 = local_8;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00427a0a
 * Entry Point: 00427a0a
 * Size: 449 bytes
 */


void Pic_Subsystem_00427a0a(LPRECT player,int y,int width,int height)

{
  undefined4 local_8;
  
  if (y == -1) {
    SetRect(player,0,0,0,0);
  }
  else {
    if (y == 0x15) {
      local_8 = (height * 2) / 0x2f8;
    }
    else if (y == 0x16) {
      local_8 = (height * 0x2b) / 0x2f8;
    }
    else if (y == 0x17) {
      local_8 = (height * 0x54) / 0x2f8;
    }
    else if (y == 0x18) {
      local_8 = (height * 0x7d) / 0x2f8;
    }
    else if (y == 0x19) {
      local_8 = (height * 0xa6) / 0x2f8;
    }
    else if (y == 0x1a) {
      local_8 = (height * 0xcf) / 0x2f8;
    }
    else if (y == 0x1b) {
      local_8 = (height * 0xcf) / 0x2f8;
    }
    else if (y == 0x1e) {
      local_8 = (height * 0x121) / 0x2f8;
    }
    else {
      local_8 = -1;
    }
    if (local_8 == -1) {
      SetRect(player,0,0,0,0);
    }
    else {
      SetRect(player,0,local_8,width,(height * 0x28) / 0x2f8 + local_8);
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
  tagRECT local_20;
  HBRUSH local_10;
  int local_c;
  int local_8;
  
  Ai_Subsystem_004b765d(&local_8,&local_24);
  if ((local_8 == -1) || (local_24 == -1)) {
    local_10 = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,local_10);
    Ai_Subsystem_004b74b1(&local_c,(undefined4 *)0x0);
    Ai_Subsystem_004b74fa(local_d0,local_c);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_d0[local_d4] != 0) {
        Pic_Subsystem_00427a0a(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
        BVar1 = IsRectEmpty(&local_34);
        if (BVar1 == 0) {
          CopyRect(&local_20,&local_34);
          local_20.left = local_20.right - (local_34.right - local_34.left) / 3;
          local_20.top = local_20.bottom -
                         ((local_34.bottom - local_34.top) * (local_20.right - local_20.left)) /
                         (local_34.right - local_34.left);
          Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_10);
  }
  if ((local_8 != -1) && (local_24 != -1)) {
    local_10 = CreateSolidBrush(0xff00);
    local_38 = SelectObject(hdc,local_10);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_24 == local_d4) {
        Pic_Subsystem_00427a0a(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
        BVar1 = IsRectEmpty(&local_34);
        if (BVar1 == 0) {
          CopyRect(&local_20,&local_34);
          local_20.right = local_20.left + (local_34.right - local_34.left) / 3;
          local_20.top = local_20.bottom -
                         ((local_34.bottom - local_34.top) * (local_20.right - local_20.left)) /
                         (local_34.right - local_34.left);
          Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_10);
  }
  return;
}



/*
 * Decompiled function: Pic_Draw_00427e36
 * Entry Point: 00427e36
 * Size: 563 bytes
 */


void Pic_Draw_00427e36(int *player,undefined4 *card_slot,char *str_3)

{
  int local_7c;
  char local_74 [100];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  Ai_Subsystem_004b74b1(&local_8,&local_10);
  local_7c = local_8;
  switch(local_10) {
  case 1:
    local_c = 4;
    strcpy(local_74,s_Upkeep_phase_0052101c);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    local_c = 10;
    strcpy(local_74,s_Draw_phase_0052102c);
    break;
  default:
    local_c = 0xffffffff;
    strcpy(local_74,s_next_phase_00521128);
    break;
  case 10:
    local_c = 0x14;
    strcpy(local_74,s_Main_phase__pre_combat__00521038);
    break;
  case 0x14:
    local_c = 0x15;
    strcpy(local_74,s_Main_phase__combat__00521050);
    break;
  case 0x15:
    local_c = 0x16;
    strcpy(local_74,s_Attack_fast_effects_phase_00521064);
    break;
  case 0x16:
    local_c = 0x17;
    strcpy(local_74,s_Choose_defenders_phase_00521080);
    break;
  case 0x17:
    local_c = 0x18;
    strcpy(local_74,s_Block_fast_effects_phase_00521098);
    break;
  case 0x18:
    local_c = 0x19;
    strcpy(local_74,s_Resolve_1st_strike_005210b4);
    break;
  case 0x19:
  case 0x1a:
    local_c = 0x1b;
    strcpy(local_74,s_Resolve_attack_005210c8);
    break;
  case 0x1b:
    local_c = 0x1e;
    strcpy(local_74,s_Main_phase__post_combat__005210d8);
    break;
  case 0x1e:
    local_c = 0x1f;
    strcpy(local_74,s_Discard_phase_005210f4);
    break;
  case 0x1f:
    local_c = 0x20;
    strcpy(local_74,s_Cleanup_phase_00521104);
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
    local_c = 0;
    local_7c = 1 - local_8;
    strcpy(local_74,s_Start_of_next_turn_00521114);
  }
  if (player != (int *)0x0) {
    *player = local_7c;
  }
  if (card_slot != (undefined4 *)0x0) {
    *card_slot = local_c;
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


undefined4 Pic_Subsystem_00428320(int player,int card_slot,int arg_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player))
       && (iVar4 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),
                                player), iVar4 == 0)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if ((((g_CurrentStepCode == 0xcf) && (g_ScWillyScore == 10)) &&
        ((g_TurnPlayer == DAT_006a4b5c &&
         ((g_EventSourceSlot == card_slot && (g_EventSourcePlayer == player)))))) &&
       (DAT_006a4b5c == player)) {
      if (arg_3 == 0x7d) {
        if (g_ActivePlayerPriority == player) {
          if (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 2) == 0) {
            *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 2;
            local_c = 0;
            bVar1 = false;
            while ((local_c < (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase] && (!bVar1))) {
              iVar4 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20);
              if (((iVar4 != -1) &&
                  (((((&g_CardSlot_Flags)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0
                    && (((&g_MasterCardColorTable)[iVar4 * 0x34] & 2) != 0)) &&
                   (((&g_CardSlot_Abilities2)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x20)
                    == 0)))) &&
                 (((iVar5 = g_CurrentTurnPhase * 0x5b20, cVar2 = Card_UntapCard(player, card_slot, 2),
                   (*(uint *)(&g_CardSlot_Abilities2 + local_c * 0x120 + iVar5) &
                   1 << (cVar2 - 1U & 0x1f)) == 0 && ((&DAT_0051aebd)[iVar4 * 0x34] == '\0')) &&
                  (((&DAT_006a5f69)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 8) == 0)))) {
                bVar1 = true;
              }
              local_c = local_c + 1;
            }
            if ((bVar1) && (iVar4 = Math_RandomRange(8 - (&DAT_006b3008)[player]), iVar4 == 0)) {
              *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
            }
          }
          if (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) != 0) {
            g_CardEventResult = g_CardEventResult | 2;
          }
        }
        else {
          g_CardEventResult = g_CardEventResult | 1;
        }
      }
      if (arg_3 == 0x7e) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
        *(undefined4 *)(&DAT_00680780 + player * 4) = 1;
        iVar4 = Card_ApplyTriggerEffect(player, card_slot, DAT_006a4b64, -1, -1);
        if (iVar4 != -1) {
          *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + player * 0x5b20) | 0x400020;
          cVar2 = Card_UntapCard(player, card_slot, 2);
          *(uint *)(&g_CardSlot_ConvertedManaCost + iVar4 * 0x120 + player * 0x5b20) =
               1 << (cVar2 - 1U & 0x1f) | 0x20;
          if (((&g_CardSlot_Abilities1)[card_slot * 0x120 + player * 0x5b20] & 2) != 0) {
            *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + player * 0x5b20) =
                 *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + player * 0x5b20) | 2;
            for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
              (&DAT_006a602f)[local_10 + player * 0x5b20 + iVar4 * 0x120] =
                   (&DAT_006a602f)[local_10 + player * 0x5b20 + card_slot * 0x120];
            }
          }
        }
        DAT_006fe408 = 1;
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
       (g_EventSourcePlayer == player)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_0042881e
 * Entry Point: 0042881e
 * Size: 1340 bytes
 */


undefined4 Pic_Subsystem_0042881e(int player,int card_slot,int arg_3)

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
      iVar2 = Card_UntapCard(player,card_slot,1);
      iVar2 = FUN_0041d8a6(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = iVar2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint *)(&DAT_0051aed0 +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint *)(&DAT_0051aed0 +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(undefined2 *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(undefined2 *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&DAT_0051aebf)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((int)(char)(&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120] !=
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120));
      iVar2 = Card_UntapCard(player,card_slot,1);
      iVar2 = FUN_0041d8a6(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = iVar2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint *)(&DAT_0051aed0 +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint *)(&DAT_0051aed0 +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(undefined2 *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(undefined2 *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&DAT_0051aebf)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((arg_3 == 0x3c) && (iVar2 = Card_IsTapped(player,card_slot), iVar2 != 0)) {
      if ((g_DuelModeFlags & 0x20000) == 0) {
        g_DuelModeFlags = g_DuelModeFlags | 0x10000;
      }
      else {
        iVar2 = Card_IsTapped(g_EventSourcePlayer,g_EventSourceSlot);
        if (((iVar2 != 0) &&
            (iVar3 = g_EventSourceSlot * 0x120, iVar4 = g_EventSourcePlayer * 0x5b20,
            iVar2 = Card_UntapCard(player,card_slot,1),
            *(int *)(&g_CardSlot_CardId + iVar4 + iVar3) == iVar2 + -1)) &&
           ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0 ||
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)))) {
          g_CardEventResult = *(undefined4 *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120)
          ;
          *(uint *)(&g_CardSlot_Abilities1 +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
               *(uint *)(&g_CardSlot_Abilities1 +
                        g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) | 0x40;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00428d5a
 * Entry Point: 00428d5a
 * Size: 1245 bytes
 */


undefined4 Pic_Subsystem_00428d5a(int player,int card_slot,int arg_3)

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
      iVar2 = Card_UntapCard(player,card_slot,3);
      iVar2 = FUN_0041d8a6(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = iVar2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6032)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint *)(&DAT_0051aed0 +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint *)(&DAT_0051aed0 +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(undefined2 *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(undefined2 *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&DAT_0051aebf)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((int)(char)(&DAT_006a6032)[player * 0x5b20 + card_slot * 0x120] !=
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120));
      iVar2 = Card_UntapCard(player,card_slot,3);
      iVar2 = FUN_0041d8a6(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) = iVar2;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             (int)(char)(&DAT_006a6032)[player * 0x5b20 + card_slot * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] | 2;
        *(uint *)(&DAT_0051aed0 +
                 *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) =
             *(uint *)(&DAT_0051aed0 +
                      *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34) |
             0x8000;
        *(undefined2 *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        *(undefined2 *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34)
             = 1;
        (&DAT_0051aebf)[*(int *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120) * 0x34] =
             1;
      }
    }
    if ((arg_3 == 0x3c) && (iVar2 = Card_IsTapped(player,card_slot), iVar2 != 0)) {
      if ((g_DuelModeFlags & 0x20000) == 0) {
        g_DuelModeFlags = g_DuelModeFlags | 0x10000;
      }
      else {
        iVar2 = Card_IsTapped(g_EventSourcePlayer,g_EventSourceSlot);
        if ((iVar2 != 0) &&
           (iVar3 = g_EventSourceSlot * 0x120, iVar4 = g_EventSourcePlayer * 0x5b20,
           iVar2 = Card_UntapCard(player,card_slot,3),
           *(int *)(&g_CardSlot_CardId + iVar4 + iVar3) == iVar2 + -1)) {
          g_CardEventResult = *(undefined4 *)(&g_CardSlot_Controller + player * 0x5b20 + card_slot * 0x120)
          ;
          *(uint *)(&g_CardSlot_Abilities1 +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
               *(uint *)(&g_CardSlot_Abilities1 +
                        g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) | 0x40;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00429237
 * Entry Point: 00429237
 * Size: 1462 bytes
 */


undefined4 Pic_Subsystem_00429237(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_10c;
  uint local_104;
  int local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4 [30];
  int aiStack_7c [30];
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (flags == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if ((((flags == 0x73) && (g_TurnPlayer == spell_id)) &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) &&
       (g_ScWillyScore == 10)) {
      iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
      if ((*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) ||
         (iVar2 = FUN_0040dcca(spell_id,target_id,7,0), iVar2 != 0)) {
        if (spell_id == g_ActivePlayerPriority) {
          DAT_006a4920 = DAT_006a4920 | 3;
        }
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if ((flags == 0x6d) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 1
          ;
        }
      }
      if ((flags == 0x72) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          Magic_ExecuteDrawPhase(g_TurnPlayer);
        }
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          local_10c = 0;
          for (local_100 = 0; local_100 < (int)(&g_PlayerActiveCardCount)[spell_id];
              local_100 = local_100 + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_100 * 0x120 + spell_id * 0x5b20) != -1) &&
                (((&g_CardSlot_Flags)[local_100 * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
               (((&g_CardSlot_Flags)[local_100 * 0x120 + spell_id * 0x5b20] & 2) == 0)) {
              local_f4[local_10c] =
                   *(undefined4 *)(&g_CardSlot_CardId + local_100 * 0x120 + spell_id * 0x5b20);
              aiStack_7c[local_10c] = local_100;
              local_10c = local_10c + 1;
            }
          }
          local_fc = 0;
          if (0x12 < (int)(&g_PlayerCreatureCount)[spell_id]) {
            local_fc = (&g_PlayerCreatureCount)[spell_id] + 0x1e;
          }
          if ((int)(&DAT_006b3008)[spell_id] < 7) {
            local_fc = local_fc + (7 - (&DAT_006b3008)[spell_id]) * 5 + 10;
          }
          if ((0 < local_f8) && (local_104 == 0)) {
            local_fc = local_fc / 2;
          }
          if ((int)(&g_PlayerCreatureCount)[spell_id] < 4) {
            local_fc = 0;
          }
          iVar2 = Math_RandomRange(100);
          local_104 = (uint)(local_fc <= iVar2);
          iVar2 = Ai_Subsystem_004cc56d
                            (spell_id,g_DialogPromptHwnd,g_DuelArenaHwnd,-1,-1,
                             s_Lose_4_life__Put_back_on_library_00521134,local_104);
          if (iVar2 == 0) {
            (&g_PlayerCreatureCount)[spell_id] = (&g_PlayerCreatureCount)[spell_id] + -4;
          }
          else if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) &&
                  (DAT_006fedc0 == 0)) {
            Pic_Subsystem_00424500(s_prompts_txt_00521168,s_SYLVAN_LIBRARY_00521158);
            iVar2 = Pic_Load_004509e8(spell_id,(int)local_f4,local_10c,&g_OverworldGoldAmount,1);
            Pic_Subsystem_004524db(spell_id,local_f4[iVar2]);
            *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + aiStack_7c[iVar2] * 0x120) =
                 0xffffffff;
            (&DAT_006b3008)[spell_id] = (&DAT_006b3008)[spell_id] + -1;
          }
          else if (0 < local_10c) {
            iVar2 = Math_RandomRange(local_10c);
            Pic_Subsystem_004524db(spell_id,local_f4[iVar2]);
            *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + aiStack_7c[iVar2] * 0x120) =
                 0xffffffff;
            (&DAT_006b3008)[spell_id] = (&DAT_006b3008)[spell_id] + -1;
          }
        }
      }
      if (((flags == 0x22) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004297ed
 * Entry Point: 004297ed
 * Size: 1675 bytes
 */


undefined4 Pic_Subsystem_004297ed(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (flags == 0x74) {
    uVar2 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       (iVar3 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       iVar3 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((*(int *)(&DAT_0063ee4c + (1 - spell_id) * 0x20) -
            *(int *)(&DAT_0063ee4c + spell_id * 0x20)) * 3 + 6) * 4;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == spell_id)) && (spell_id == DAT_0063edc0))
         && ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0
             && (*(int *)(&DAT_0063ee4c + spell_id * 0x20) <
                 *(int *)(&DAT_0063ee4c + (1 - spell_id) * 0x20))))) {
        iVar3 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_006330d0 + iVar3 * 4) == 0) ||
           (iVar3 = FUN_0040dcca(spell_id,target_id,7,0), iVar3 != 0)) {
          if ((g_CurrentTurnPhase != spell_id) && (*(int *)(&DAT_0069e740 + spell_id * 2000) != -1))
          {
            DAT_006a4920 = DAT_006a4920 | 3;
          }
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 0x6d) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        iVar3 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar3 * 4) != 0) {
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
          iVar3 = Ai_Subsystem_004b76a6(&DAT_0069e730 + spell_id * 2000,500,(int)local_14,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            Pic_Subsystem_00451291
                      (spell_id,*(int *)(&DAT_0069e730 + local_14[local_18] * 4 + spell_id * 2000));
          }
          if (iVar3 == 1) {
            Pic_Subsystem_004523fd(spell_id,local_14[0]);
          }
          if (iVar3 == 2) {
            iVar4 = local_14[1];
            if (local_14[1] <= local_14[0]) {
              iVar4 = local_14[0];
            }
            Pic_Subsystem_004523fd(spell_id,iVar4);
            iVar4 = local_14[1];
            if (local_14[0] <= local_14[1]) {
              iVar4 = local_14[0];
            }
            Pic_Subsystem_004523fd(spell_id,iVar4);
          }
          if (iVar3 == 3) {
            Pic_Subsystem_004523fd(spell_id,local_14[0]);
            if (local_14[0] < local_14[1]) {
              local_14[1] = local_14[1] + -1;
            }
            if (local_14[0] < local_14[2]) {
              local_14[2] = local_14[2] + -1;
            }
            iVar3 = local_14[1];
            if (local_14[1] <= local_14[2]) {
              iVar3 = local_14[2];
            }
            Pic_Subsystem_004523fd(spell_id,iVar3);
            iVar3 = local_14[1];
            if (local_14[2] <= local_14[1]) {
              iVar3 = local_14[2];
            }
            Pic_Subsystem_004523fd(spell_id,iVar3);
          }
          Ai_Subsystem_004cc9c5(0,0xff);
        }
        else {
          local_1c = 0;
          local_18 = 0;
          bVar1 = false;
          while ((local_18 < (int)(&DAT_006b3008)[spell_id] && (!bVar1))) {
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + spell_id * 0x5b20) * 0x34] & 1)
                != 0) {
              bVar1 = true;
            }
            local_18 = local_18 + 1;
          }
          if (!bVar1) {
            g_SpellStackDepth = g_SpellStackDepth + 0x30;
          }
          iVar3 = Math_Clamp(8 - (&DAT_006b3008)[spell_id],1,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            local_14[3] = FUN_004fdad2(spell_id,spell_id,1);
            if (4 < *(int *)(&DAT_0069e730 + local_14[3] * 4 + spell_id * 2000)) {
              local_14[3] = -1;
              local_18 = 0;
              while (((local_18 < 500 && (local_14[3] == -1)) &&
                     (*(int *)(&DAT_0069e730 + local_18 * 4 + spell_id * 2000) != -1))) {
                if (*(int *)(&DAT_0069e730 + local_18 * 4 + spell_id * 2000) < 5) {
                  local_14[3] = local_18;
                }
                local_18 = local_18 + 1;
              }
            }
            if ((local_14[3] != -1) &&
               (*(int *)(&DAT_0069e730 + local_14[3] * 4 + spell_id * 2000) != -1)) {
              local_14[local_1c] = *(int *)(&DAT_0069e730 + local_14[3] * 4 + spell_id * 2000);
              local_1c = local_1c + 1;
              Pic_Subsystem_004523fd(spell_id,local_14[3]);
            }
          }
          if (spell_id == 1) {
            Pic_Load_004509e8(0,(int)local_14,local_1c,s_Opponent_chose_these_basic_lands_00521180,0
                             );
          }
          for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
            Pic_Subsystem_00451291(spell_id,local_14[local_18]);
          }
        }
        Pic_Subsystem_00452276(spell_id);
      }
      if (((flags == 0x22) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_00429e7d
 * Entry Point: 00429e7d
 * Size: 601 bytes
 */


int Pic_Subsystem_00429e7d(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    iVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
       (spell_id == g_EventSourcePlayer)) {
      iVar1 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                            spell_id * 0x5b20 + target_id * 0x120),-1);
      if (iVar1 == 0) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
    }
    if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
       (spell_id == g_EventSourcePlayer)) {
      Pic_Subsystem_00424500(s_prompts_txt_005211c0,s_KISMET_005211b8);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    iVar1 = target_id * 0x120;
    if (((((&g_CardSlot_Flags)[spell_id * 0x5b20 + iVar1] & 0x20) == 0) && (flags == 0x6c)) &&
       ((iVar1 = target_id * 0x120,
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + iVar1) ==
        g_EventSourcePlayer &&
        (iVar1 = *(int *)(&g_CardSlot_CardId +
                         g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0xd,
        ((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 0x43) !=
        0)))) {
      iVar1 = g_EventSourceSlot * 0x120;
      *(uint *)(&g_CardSlot_Flags + g_EventSourcePlayer * 0x5b20 + iVar1) =
           *(uint *)(&g_CardSlot_Flags + g_EventSourcePlayer * 0x5b20 + iVar1) | 0x10;
    }
  }
  return iVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042a0d6
 * Entry Point: 0042a0d6
 * Size: 243 bytes
 */


void Pic_Subsystem_0042a0d6(int player,int card_slot,int arg_3)

{
  int iVar1;
  int iVar2;
  
  if (((arg_3 == 0x7f) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    iVar1 = Card_SetTapState(player, card_slot, 5);
    *(int *)(&DAT_006330d0 + iVar1 * 4) = *(int *)(&DAT_006330d0 + iVar1 * 4) + 3;
  }
  if ((((arg_3 != 0x74) && ((arg_3 == 0x6c || (arg_3 == 199)))) && (g_EventSourceSlot == card_slot)) &&
     (g_EventSourcePlayer == player)) {
    iVar1 = Card_SetTapState(player, card_slot, 5);
    iVar1 = *(int *)(&DAT_0063ee30 + iVar1 * 4 + (1 - player) * 0x20);
    iVar2 = Card_SetTapState(player, card_slot, 5);
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((iVar1 + *(int *)(&DAT_0063ee30 + iVar2 * 4 + player * 0x20) * -2) * 3 + 3) * 4;
  }
  return;
}



/*
 * Decompiled function: Pic_Load_0042a1c9
 * Entry Point: 0042a1c9
 * Size: 2641 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Load_0042a1c9(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint uVar2;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      uVar2 = (DAT_00695e04 | _DAT_00695e00) & 2;
    }
    else {
      if (g_IsAiThinking == 1) {
        g_AiDecisionScore = Math_RandomRange(2);
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           g_AiDecisionScore;
      uVar2 = *(uint *)(&DAT_00695e00 + g_AiDecisionScore * 4) & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        local_14[1] = 0;
        local_14[0] = 0;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          local_20 = 0;
          while( true ) {
            if ((499 < local_20) || (*(int *)(&DAT_006ff710 + local_20 * 4 + spell_id * 2000) == -1)
               ) goto LAB_0042a2fb;
            if (((&g_MasterCardColorTable)
                 [*(int *)(&DAT_006ff710 + local_20 * 4 + local_18 * 2000) * 0x34] & 2) != 0) break;
            local_20 = local_20 + 1;
          }
          local_14[local_18] = local_14[local_18] + 1;
LAB_0042a2fb:
        }
        if ((local_14[0] == 0) || (local_14[1] == 0)) {
          if (local_14[0] == 0) {
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
          local_1c = 0;
          do {
            local_14[3] = Pic_Load_004509e8(spell_id,(int)(&DAT_006ff710 + local_24 * 2000),500,
                                            &g_OverworldWorldState,0);
            if (local_14[3] == -1) {
              g_ActivePlayer = 1;
            }
            else if (((&g_MasterCardColorTable)
                      [*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0
                    ) {
              if (g_IsAiThinking != 1) {
                Ai_Util_004cc42d(s_Illegal_Target_00521234);
                Sleep(2000);
                Ai_Util_004cc42d(&DAT_00521244);
              }
            }
            else {
              local_1c = local_1c + 1;
            }
          } while ((g_ActivePlayer != 1) && (local_1c == 0));
        }
      }
      else {
        local_24 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        local_14[3] = FUN_004fd9c0(local_24,2);
      }
      if ((g_ActivePlayer == 1) ||
         (((local_14[3] == -1 || (*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000) == -1)
           ) || (((&g_MasterCardColorTable)
                  [*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0))))
      {
        g_ActivePlayer = 1;
      }
      else {
        local_14[2] = Pic_Subsystem_00451291
                                (spell_id,*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000
                                                  ));
        if (local_14[2] != -1) {
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) = local_14[2]
          ;
          (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)spell_id;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffefff;
          if (local_24 != 0) {
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_OriginalCardId +
                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) | 0x1000;
          }
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 0x20;
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20) = local_24;
          *(int *)(&DAT_006a5f94 + target_id * 0x120 + spell_id * 0x5b20) = local_14[3];
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
    }
    if (flags == 0x71) {
      local_14[3] = *(int *)(&DAT_006a5f94 + target_id * 0x120 + spell_id * 0x5b20);
      if (*(int *)(&DAT_006ff710 +
                  local_14[3] * 4 +
                  *(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20) * 2000) == -1) {
        Pic_Subsystem_0044867e(spell_id,target_id,2);
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0xffffffff;
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_00449223
                  (*(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20),local_14[3]);
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        Pic_Subsystem_0042ac1f
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
        *(undefined2 *)
         (&DAT_006a5f48 +
         *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) = 0xffff;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((((g_CurrentStepCode == 0xd4) && (g_EventSourceSlot == target_id)) &&
         ((g_EventSourcePlayer == spell_id &&
          (((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1 &&
           (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) != -1)))))) && (DAT_00695f08 == spell_id)) &&
       ((DAT_006b2e14 == target_id && (spell_id == DAT_006a4b5c)))) {
      if (flags == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (flags == 0x7e) {
        if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0) {
          *(uint *)(&g_CardSlot_Abilities1 +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 +
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
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0042ac1f
 * Entry Point: 0042ac1f
 * Size: 510 bytes
 */


undefined4 Pic_Subsystem_0042ac1f(int arg1,int arg2)

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
    (&DAT_006a2828)[arg1] =
         (&DAT_006a2828)[arg1] |
         (uint)(byte)(&g_MasterCardColorTable)
                     [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
    *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) | 0x30022;
    Magic_BroadcastCardEvent(arg1,arg2,0x6c);
    *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) |
         CONCAT31((uint3)((arg1 == 0) - 1 >> 8) & 0x4000,0x80);
    Magic_TriggerCardEvent(arg1,arg2,0x71,1 - arg1,0xffffffff);
    *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120) & 0xffffffdf;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    FUN_00476205(g_TurnPlayer,0xdb,s_Card_into_play_00521248,0);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042ae1d
 * Entry Point: 0042ae1d
 * Size: 2008 bytes
 */


undefined4 Pic_Subsystem_0042ae1d(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  undefined4 local_c;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052126c,s_ANIMATE_ARTIFACT_00521258);
      arg_20 = &local_10;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,2,0x200,0x40,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9
                         ,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7
                         ,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) * 0x34] & 0x42) == 0x40) {
          local_8 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                         *(int *)(&g_CardSlot_OriginalCardId +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                         (char)(&g_CardSlot_Toughness)
                                               [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20));
          if (local_8 != -1) {
            (&g_MasterCardColorTable)[local_8 * 0x34] = 0x42;
            *(short *)(&DAT_0051aec4 + local_8 * 0x34) =
                 (short)(char)(&DAT_0051aec0)
                              [*(int *)(&g_CardSlot_CardId +
                                       *(int *)(&g_CardSlot_OriginalCardId +
                                               target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                       (char)(&g_CardSlot_Toughness)
                                             [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) *
                               0x34];
            *(undefined2 *)(&DAT_0051aec2 + local_8 * 0x34) =
                 *(undefined2 *)(&DAT_0051aec4 + local_8 * 0x34);
            *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = local_8;
            *(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) = local_8;
            *(uint *)(&g_CardSlot_Abilities2 +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) =
                 *(uint *)(&g_CardSlot_Abilities2 +
                          *(int *)(&g_CardSlot_OriginalCardId +
                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) | 0x1000000;
          }
        }
        else {
          *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x77) && (g_EventSourceSlot == target_id)) &&
       ((g_EventSourcePlayer == spell_id &&
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
    if (((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot &&
        ((((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_EventSourcePlayer && (g_EventSourceSlot != -1)) &&
         (iVar5 = Card_IsTapped(spell_id,target_id), iVar5 != 0)))))) {
      g_CardEventResult =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) | 0x40;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042b5f5
 * Entry Point: 0042b5f5
 * Size: 1209 bytes
 */


undefined4 Pic_Subsystem_0042b5f5(int player,int card_slot,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      Glue_Subsystem_004e65e1(Pic_Subsystem_0042baae,-1);
    }
    if ((arg_3 == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) {
      iVar3 = Card_IsTapped(player,card_slot);
      if ((iVar3 != 0) &&
         ((g_EventSourceSlot != -1 &&
          (((&g_MasterCardColorTable)[g_CardEventResult * 0x34] & 0x42) == 0x40)))) {
        local_10 = 0;
        bVar1 = false;
        while( true ) {
          iVar3 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
          if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
              (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
            iVar3 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
          }
          if ((iVar3 <= local_10) || (bVar1)) break;
          if (((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20) ==
                DAT_00695edc) &&
              (((&g_CardSlot_Flags)[local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
             (((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20] ==
               g_EventSourcePlayer &&
              (*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20)
               == g_EventSourceSlot)))) {
            bVar1 = true;
          }
          if (((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20) ==
                DAT_00695edc) &&
              (((&g_CardSlot_Flags)[local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0))
             && (((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20]
                  == g_EventSourcePlayer &&
                 (*(int *)(&g_CardSlot_OriginalCardId +
                          local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20) == g_EventSourceSlot)
                 ))) {
            bVar1 = true;
          }
          local_10 = local_10 + 1;
        }
        if (!bVar1) {
          iVar3 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                       g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                                       ));
          if (iVar3 != -1) {
            iVar4 = Card_ApplyTriggerEffect(player,card_slot,DAT_00695edc,g_EventSourcePlayer,g_EventSourceSlot
                                );
            if (iVar4 != -1) {
              *(int *)(&g_CardSlot_Controller + iVar4 * 0x120 + player * 0x5b20) = iVar3;
              *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + player * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + player * 0x5b20) | 0x10020;
              UI_PaintBigCardInfo(&local_8,0,player,2,2,0x200,0,0,0,0,0,0,
                           *(undefined4 *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120),
                           0xffffffff,0xffffffff,0xffffffff,0,0,0);
              *(int *)(&g_CardSlot_TargetSlot + iVar4 * 0x120 + player * 0x5b20) = local_8;
            }
            (&g_MasterCardColorTable)[iVar3 * 0x34] = 0x42;
            *(short *)(&DAT_0051aec4 + iVar3 * 0x34) =
                 (short)(char)(&DAT_0051aebf)
                              [*(int *)(&g_CardSlot_CardId +
                                       g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                                       ) * 0x34] +
                 (short)(char)(&DAT_0051aec0)
                              [*(int *)(&g_CardSlot_CardId +
                                       g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                                       ) * 0x34];
            *(undefined2 *)(&DAT_0051aec2 + iVar3 * 0x34) =
                 *(undefined2 *)(&DAT_0051aec4 + iVar3 * 0x34);
            *(code **)(&DAT_0051aec8 + iVar3 * 0x34) = Glue_Util_004d0a30;
            *(undefined4 *)(&DAT_0051aed0 + iVar3 * 0x34) = 0x8000;
            (&DAT_0051aebe)[iVar3 * 0x34] = 1;
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      Glue_Subsystem_004e65e1(Pic_Subsystem_0042baee,-1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0042baae
 * Entry Point: 0042baae
 * Size: 64 bytes
 */


undefined4 Pic_Subsystem_0042baae(int player,int card_slot,int arg_3)

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


undefined4 Pic_Subsystem_0042baee(int player,int card_slot,int arg_3)

{
  if (DAT_00695edc == arg_3) {
    *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) + -1;
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042bb2e
 * Entry Point: 0042bb2e
 * Size: 951 bytes
 */


undefined4 Pic_Subsystem_0042bb2e(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
       (spell_id == g_EventSourcePlayer)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521288,s_ANIMATE_WALL_00521278);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar5 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
        *(uint *)(&g_CardSlot_Abilities1 +
                 *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                 0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 +
                      *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                      0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                              0x5b20) | 0x800;
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x77) && (target_id == g_EventSourceSlot)) &&
       ((spell_id == g_EventSourcePlayer &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) != -1)))) {
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) *
                    0x120 + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                            0x5b20) & 0xfffff7ff;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042bee5
 * Entry Point: 0042bee5
 * Size: 96 bytes
 */


void Pic_Subsystem_0042bee5(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005212a4,s_CONTROL_MAGIC_00521294);
  }
  Pic_Subsystem_0042bfa5(spell_id,target_id,flags,2);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0042bf45
 * Entry Point: 0042bf45
 * Size: 96 bytes
 */


void Pic_Subsystem_0042bf45(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
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


undefined4 Pic_Subsystem_0042bfa5(int x,int y,int width,uint height)

{
  undefined4 uVar1;
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
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
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
    uVar1 = Glue_Subsystem_004d0a42(x,y);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,x,2,2,0x200,height,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((width == 0x6c) && (g_EventSourceSlot == y)) && (g_EventSourcePlayer == x)) {
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = Glue_Subsystem_004d0a42(x,y);
      iVar5 = Action_ValidateTarget_00405802
                        (x,2,1 - x,0x200,height,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) = local_14;
        *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) = local_10;
        (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 1;
      }
    }
    if (width == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = Glue_Subsystem_004d0a42(x,y);
      iVar5 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x200,height,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,
                         uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(x,y,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] =
             (&g_CardSlot_CombatTarget)[y * 0x120 + x * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20);
        for (local_c = 0; local_c < 2; local_c = local_c + 1) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c];
              local_8 = local_8 + 1) {
            if ((((*(int *)(&g_MasterCardTypeTable +
                           *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34)
                   == 0x2c) ||
                 (*(int *)(&g_MasterCardTypeTable +
                          *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34)
                  == 0xea)) &&
                ((((&g_CardSlot_Flags)[local_8 * 0x120 + local_c * 0x5b20] & 2) != 0 &&
                 (((&g_CardSlot_Toughness)[local_8 * 0x120 + local_c * 0x5b20] ==
                   (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] &&
                  (*(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + local_c * 0x5b20) ==
                   *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20))))))) &&
               (((&DAT_006a5f6b)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + local_c * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + local_c * 0x5b20) &
                   0xfeffffff;
              (&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] = (undefined1)local_c;
              *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) = local_8;
            }
          }
        }
        *(uint *)(&g_CardSlot_Abilities1 + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + y * 0x120 + x * 0x5b20) | 0x1000000;
        if (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) != x) {
          local_8 = Pic_Subsystem_0042ca53
                              ((int)(char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20));
          (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] = (undefined1)x;
          *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) = local_8;
        }
      }
      (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((((g_CurrentStepCode == 0xd4) && (g_EventSourceSlot == y)) &&
         (g_EventSourcePlayer == x)) &&
        (((&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] != -1 &&
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1)))) &&
       ((DAT_00695f08 == x && ((DAT_006b2e14 == y && (x == DAT_006a4b5c)))))) {
      if (width == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (width == 0x7e) {
        if (((&DAT_006a5f6b)[y * 0x120 + x * 0x5b20] & 1) == 0) {
          Glue_Subsystem_004e65e1(Pic_Subsystem_0042c92f,-1);
        }
        else if ((&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] == -1) {
          if ((*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                       (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1) &&
             (((((&DAT_006a5f3e)
                 [*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) != 0 &&
               ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_CurrentTurnPhase)) ||
              ((((&DAT_006a5f3e)
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
          *(uint *)(&g_CardSlot_Abilities1 +
                   *(int *)(&g_CardSlot_TypeFlags + y * 0x120 + x * 0x5b20) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[y * 0x120 + x * 0x5b20] * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 +
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
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042c92f
 * Entry Point: 0042c92f
 * Size: 292 bytes
 */


undefined4 Pic_Subsystem_0042c92f(int player,int card_slot,int arg_3)

{
  if ((((*(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) == 0x2c) ||
       (*(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) == 0xea)) &&
      ((char)(&g_CardSlot_DamageReceived)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer
      )) && (*(int *)(&g_CardSlot_TypeFlags + card_slot * 0x120 + player * 0x5b20) == g_EventSourceSlot)
     ) {
    (&g_CardSlot_DamageReceived)[card_slot * 0x120 + player * 0x5b20] =
         (&g_CardSlot_DamageReceived)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]
    ;
    *(undefined4 *)(&g_CardSlot_TypeFlags + card_slot * 0x120 + player * 0x5b20) =
         *(undefined4 *)
          (&g_CardSlot_TypeFlags + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120);
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
  int iVar1;
  int arg1_00;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  undefined1 local_8;
  
  arg1_00 = 1 - arg1;
  iVar1 = *(int *)(&g_CardSlot_DisplayIndex + arg1 * 0x5b20 + arg2 * 0x120);
  iVar2 = Pic_Subsystem_00451291
                    (arg1_00,*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120));
  if (iVar2 != -1) {
    memcpy(&g_ActiveCardsInPlay + arg1_00 * 0x5b20 + iVar2 * 0x120,
           &g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20,0x120);
    if (*(int *)(&g_MasterCardTypeTable +
                *(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg1_00 * 0x5b20) * 0x34) != 0xab) {
      *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) | 0x30000;
    }
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg1_00 * 0x5b20) & 0xfffffff3;
    *(int *)(&DAT_007006e0 + iVar1 * 4) = arg1_00;
    *(int *)(&DAT_006a5750 + iVar1 * 4) = iVar2;
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14];
          local_18 = local_18 + 1) {
        local_8 = (undefined1)arg1_00;
        if (((char)(&g_CardSlot_Toughness)[local_18 * 0x120 + local_14 * 0x5b20] == arg1) &&
           (*(int *)(&g_CardSlot_OriginalCardId + local_18 * 0x120 + local_14 * 0x5b20) == arg2)) {
          (&g_CardSlot_Toughness)[local_18 * 0x120 + local_14 * 0x5b20] = local_8;
          *(int *)(&g_CardSlot_OriginalCardId + local_18 * 0x120 + local_14 * 0x5b20) = iVar2;
        }
        if (((char)(&g_CardSlot_DamageReceived)[local_18 * 0x120 + local_14 * 0x5b20] == arg1) &&
           (*(int *)(&g_CardSlot_TypeFlags + local_18 * 0x120 + local_14 * 0x5b20) == arg2)) {
          (&g_CardSlot_DamageReceived)[local_18 * 0x120 + local_14 * 0x5b20] = local_8;
          *(int *)(&g_CardSlot_TypeFlags + local_18 * 0x120 + local_14 * 0x5b20) = iVar2;
        }
        if ((&g_CardSlot_TurnPlayed)[local_18 * 0x120 + local_14 * 0x5b20] != '\0') {
          for (local_1c = 0;
              local_1c < (char)(&g_CardSlot_TurnPlayed)[local_18 * 0x120 + local_14 * 0x5b20];
              local_1c = local_1c + 1) {
            if ((*(int *)(&g_CardSlot_CombatTarget +
                         local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) == arg1) &&
               (*(int *)(&g_CardSlot_AttachedAura +
                        local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) == arg2)) {
              *(int *)(&g_CardSlot_CombatTarget +
                      local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) = arg1_00;
              *(int *)(&g_CardSlot_AttachedAura +
                      local_18 * 0x120 + local_14 * 0x5b20 + local_1c * 8) = iVar2;
            }
          }
        }
      }
    }
  }
  *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) | 8;
  Pic_Subsystem_0044867e(arg1,arg2,4);
  return iVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0042ce63
 * Entry Point: 0042ce63
 * Size: 2028 bytes
 */


undefined4 Pic_Subsystem_0042ce63(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_10;
  
  iVar1 = *(int *)(&g_CardSlot_DisplayIndex + y * 0x120 + x * 0x5b20);
  iVar2 = *(int *)(&g_CardSlot_DisplayIndex + height * 0x120 + width * 0x5b20);
  iVar3 = Pic_Subsystem_00451291(x,*(int *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20));
  if (iVar3 == -1) {
    uVar4 = 0;
  }
  else {
    iVar5 = Pic_Subsystem_00451291(width,*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20));
    if (iVar5 == -1) {
      *(undefined4 *)(&g_CardSlot_CardId + iVar3 * 0x120 + x * 0x5b20) = 0xffffffff;
      uVar4 = 0;
    }
    else {
      memcpy(&g_ActiveCardsInPlay + x * 0x5b20 + iVar3 * 0x120,
             &g_ActiveCardsInPlay + width * 0x5b20 + height * 0x120,0x120);
      memcpy(&g_ActiveCardsInPlay + width * 0x5b20 + iVar5 * 0x120,
             &g_ActiveCardsInPlay + x * 0x5b20 + y * 0x120,0x120);
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + iVar3 * 0x120 + x * 0x5b20) * 0x34) != 0xab) {
        *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) | 0x30000;
      }
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + iVar5 * 0x120 + width * 0x5b20) * 0x34) != 0xab) {
        *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) | 0x30000;
      }
      *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar3 * 0x120 + x * 0x5b20) & 0xfffffff3;
      *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) & 0xfffffff3;
      *(int *)(&DAT_007006e0 + iVar1 * 4) = width;
      *(int *)(&DAT_006a5750 + iVar1 * 4) = iVar5;
      *(int *)(&DAT_007006e0 + iVar2 * 4) = x;
      *(int *)(&DAT_006a5750 + iVar2 * 4) = iVar3;
      *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar5 * 0x120 + width * 0x5b20) | 0x400000;
      for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
        for (local_1c = 0; local_1c < (int)(&g_PlayerActiveCardCount)[local_10];
            local_1c = local_1c + 1) {
          if (((char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] == x) &&
             (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) == y)) {
            (&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)width;
            *(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) = iVar5;
          }
          if (((char)(&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] == x) &&
             (*(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) == y)) {
            (&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)width;
            *(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) = iVar5;
          }
          if ((&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20] != '\0') {
            for (local_20 = 0;
                local_20 < (char)(&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20];
                local_20 = local_20 + 1) {
              if ((*(int *)(&g_CardSlot_CombatTarget +
                           local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == x) &&
                 (*(int *)(&g_CardSlot_AttachedAura +
                          local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == y)) {
                *(int *)(&g_CardSlot_CombatTarget +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = width;
                *(int *)(&g_CardSlot_AttachedAura +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = iVar5;
              }
            }
          }
          if (((char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] == width) &&
             (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) == height)
             ) {
            (&g_CardSlot_Toughness)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)x;
            *(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_10 * 0x5b20) = iVar3;
          }
          if (((char)(&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] == width) &&
             (*(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) == height)) {
            (&g_CardSlot_DamageReceived)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)x;
            *(int *)(&g_CardSlot_TypeFlags + local_1c * 0x120 + local_10 * 0x5b20) = iVar3;
          }
          if ((&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20] != '\0') {
            for (local_20 = 0;
                local_20 < (char)(&g_CardSlot_TurnPlayed)[local_1c * 0x120 + local_10 * 0x5b20];
                local_20 = local_20 + 1) {
              if ((*(int *)(&g_CardSlot_CombatTarget +
                           local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == width) &&
                 (*(int *)(&g_CardSlot_AttachedAura +
                          local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == height)) {
                *(int *)(&g_CardSlot_CombatTarget +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = x;
                *(int *)(&g_CardSlot_AttachedAura +
                        local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = iVar3;
              }
            }
          }
        }
      }
      *(undefined4 *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = 0xffffffff;
      *(undefined4 *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20) = 0xffffffff;
      FUN_00472fae();
      uVar4 = 1;
    }
  }
  return uVar4;
}



/*
 * Decompiled function: Pic_Subsystem_0042d64f
 * Entry Point: 0042d64f
 * Size: 1242 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0042d64f(int player,int card_slot,int arg_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       ((*(byte *)(&DAT_006a2828 + (1 - player)) & 2) != 0)) {
      return 1;
    }
    return 0;
  }
  if (arg_3 != 0x6d) goto LAB_0042d76f;
  if (local_c == -1) {
LAB_0042d745:
    g_ActivePlayer = 1;
  }
  else {
    iVar2 = Magic_QueryCardAttribute(player, card_slot, 0x32, 0xffffffff);
    iVar3 = Magic_QueryCardAttribute(_DAT_0063ee20,local_c,0x32,0xffffffff);
    if (iVar2 < iVar3) goto LAB_0042d745;
    *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = local_c;
    (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
  }
  *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
       *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
LAB_0042d76f:
  if ((arg_3 == 0x72) &&
     (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
    uVar4 = Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
    *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = uVar4;
    (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = (undefined1)player;
  }
  if (((((&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] != -1) &&
       (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
    bVar1 = true;
    if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      bVar1 = false;
    }
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      bVar1 = false;
    }
    iVar2 = Magic_QueryCardAttribute(player, card_slot, 0x32, 0xffffffff);
    iVar3 = Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20),0x32,
                         0xffffffff);
    if (iVar2 < iVar3) {
      bVar1 = false;
    }
    if (!bVar1) {
      iVar2 = *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20);
      *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
      Pic_Subsystem_0042ca53(player,iVar2);
    }
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if (((arg_3 == 0x77) &&
      (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_EventSourceSlot))
     && (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer
         && (g_EventSourceSlot != -1)))) {
    *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
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

undefined4 Pic_Subsystem_0042db29(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  if (arg_3 == 0x73) {
    if ((((*(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
        ((*(byte *)(&DAT_006a2828 + (1 - player)) & 0x40) != 0)) &&
       ((iVar1 = Font_DrawString(player, 7, 3), iVar1 != 0 &&
        (iVar1 = Font_DrawString(player,4,2), iVar1 != 0)))) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_006b2d40 = 1;
      Ai_CalcManaRequirement_004ba890(player,4,2);
      if (local_10 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Pic_Subsystem_0042ca53(_DAT_0063ee20,local_10);
        *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + (1 - _DAT_0063ee20) * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + (1 - _DAT_0063ee20) * 0x5b20) |
             0x400;
      }
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[1 - player]; local_c = local_c + 1)
      {
        if (((&DAT_006a5f69)[local_c * 0x120 + (1 - player) * 0x5b20] & 4) != 0) {
          iVar1 = Pic_Subsystem_0042ca53(1 - player,local_c);
          *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) & 0xfffffbff;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0042dd1f
 * Entry Point: 0042dd1f
 * Size: 1461 bytes
 */


undefined4 Pic_Subsystem_0042dd1f(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
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
  undefined4 local_8;
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
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
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005212d8,s_FEEDBACK_005212cc);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
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
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,4,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0042e2d9
 * Entry Point: 0042e2d9
 * Size: 1333 bytes
 */


undefined4 Pic_Subsystem_0042e2d9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005212f0,s_BRAINWASH_005212e4);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        if (local_c == spell_id) {
          iVar5 = Magic_QueryCardAttribute(local_c,local_8,0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth - (iVar5 * 0xc) / 2;
        }
        else {
          iVar5 = Magic_QueryCardAttribute(local_c,local_8,0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + (iVar5 * 0xc) / 2;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((((g_CurrentStepCode == 0xdc) && (g_ScWillyScore == 0x15)) &&
         ((g_EventSourceSlot == target_id &&
          ((g_EventSourcePlayer == spell_id && (g_TurnPlayer == DAT_006a4b5c)))))) &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) &&
       (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == DAT_00695f08 &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         DAT_006b2e14)))) {
      iVar5 = Font_DrawString(g_TurnPlayer,7,3);
      if (iVar5 == 0) {
        DAT_0068a65c = 1;
      }
      else {
        if (flags == 0x7d) {
          g_CardEventResult = g_CardEventResult | 2;
        }
        if (flags == 0x7e) {
          Magic_PushSpellStack(spell_id,target_id,0x7e,spell_id,0);
          Ai_CalcManaRequirement_004ba890(g_TurnPlayer,0,3);
          Magic_DropTopSpell();
          if (g_ActivePlayer == 1) {
            DAT_0068a65c = 1;
            g_ActivePlayer = 0;
          }
          else {
            *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 1;
          }
        }
      }
    }
    if ((flags == 0x79) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
      iVar5 = Font_DrawString(g_TurnPlayer,7,3);
      if (iVar5 == 0) {
        g_CardEventResult = 1;
      }
      uVar1 = 0;
    }
    else {
      if ((flags == 0x22) || (flags == 199)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042e80e
 * Entry Point: 0042e80e
 * Size: 178 bytes
 */


undefined4 Pic_Subsystem_0042e80e(int player,int card_slot,int arg_3)

{
  if (((*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_EventSourceSlot)
      && ((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer))
     && (g_EventSourceSlot != -1)) {
    (**(code **)(&DAT_0051aec8 + arg_3 * 0x34))(player,card_slot,0x79);
    if (g_ActivePlayer == 1) {
      g_CardEventResult = g_CardEventResult + 1;
      g_ActivePlayer = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042e8c0
 * Entry Point: 0042e8c0
 * Size: 933 bytes
 */


undefined4 Pic_Subsystem_0042e8c0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (spell_id == g_EventSourcePlayer)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052130c,s_SPIRIT_SHACKLE_005212fc);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (local_c == spell_id) {
          iVar5 = -(*(int *)(&DAT_006a5f70 + local_c * 0x5b20 + local_8 * 0x120) / 2);
        }
        else {
          iVar5 = *(int *)(&DAT_006a5f70 + local_c * 0x5b20 + local_8 * 0x120) / 2;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar5;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && (g_EventSourceSlot != -1)))) {
      Pic_Subsystem_0042ec65(spell_id,target_id);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042ec65
 * Entry Point: 0042ec65
 * Size: 314 bytes
 */


undefined4 Pic_Subsystem_0042ec65(int arg1,int arg2)

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
  *(short *)(&DAT_006a5f4a +
            *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) =
       *(short *)(&DAT_006a5f4a +
                 *(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] * 0x5b20) + -2;
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0042ed9f
 * Entry Point: 0042ed9f
 * Size: 1369 bytes
 */


undefined4 Pic_Subsystem_0042ed9f(uint spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == spell_id) &&
       (g_EventSourceSlot == target_id)) && (g_EventSourcePlayer == spell_id)) &&
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,1 - spell_id,1 - spell_id,0x200,0x40,0,0,uVar1,arg_11
                         ,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521324,s_RELIC_BIND_00521318);
      arg_20 = &local_10;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,1 - spell_id,1 - spell_id,0x200,0x40,0,0,uVar2,uVar3,uVar4,iVar5,
                         iVar6,uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (((&DAT_0051aed0)
             [*(int *)(&g_CardSlot_CardId + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 1) != 0)
        {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (((char)(&DAT_0051aec0)
                       [*(int *)(&g_CardSlot_CardId + local_10 * 0x5b20 + local_c * 0x120) * 0x34] *
                 3 + 6) * 8) / 2;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,1 - (char)spell_id,1 - (char)spell_id,0x200,0x40,0,0,
                         uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && (g_EventSourceSlot != -1)))) {
      local_8 = Ai_Subsystem_004cc56d
                          (spell_id,spell_id,target_id,-1,-1,s_Gain_life__Take_Damage__00521330,
                           (uint)((int)(&g_PlayerCreatureCount)[1 - spell_id] <=
                                 (int)(&g_PlayerCreatureCount)[spell_id]));
      Pic_Subsystem_00424500(s_prompts_txt_00521358,s_RELIC_BIND_0052134c);
      if ((int)(&g_PlayerCreatureCount)[spell_id] < (int)(&g_PlayerCreatureCount)[1 - spell_id]) {
        local_14 = spell_id;
      }
      else {
        local_14 = 1 - spell_id;
      }
      Action_ValidateTarget_00405802
                (spell_id,2,local_14,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0xffffffff,0,0,
                 &DAT_0069f84a,0,&local_10);
      if (local_8 == 0) {
        (&g_PlayerCreatureCount)[local_10] = (&g_PlayerCreatureCount)[local_10] + 1;
      }
      else {
        Mem_AllocOrFree_0041df33(local_10,1,spell_id,target_id);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f2f8
 * Entry Point: 0042f2f8
 * Size: 915 bytes
 */


uint Pic_Subsystem_0042f2f8(int player,int card_slot,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == player) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 0x40;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 0x40;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      if (local_8 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = local_8;
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
      }
    }
    if ((arg_3 == 0x71) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      if (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      }
    }
    if (((arg_3 == 0x7c) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_EventSourceSlot
        )) && (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] ==
                g_EventSourcePlayer &&
               ((g_EventSourceSlot != -1 &&
                (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0))))))
    {
      Mem_AllocOrFree_0041df33(g_EventSourcePlayer,2,player,card_slot);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    if (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1) {
      if (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0) {
        Mem_AllocOrFree_0041df33(g_EventSourcePlayer,2,player,card_slot);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f690
 * Entry Point: 0042f690
 * Size: 249 bytes
 */


undefined4 Pic_Subsystem_0042f690(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b3000 + (7 - player) * 4) - (&DAT_006b3018)[player]) * 0x18;
    }
    if (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 0x40) !=
        0)) {
      Mem_AllocOrFree_0041df33(g_EventSourcePlayer,1,player,card_slot);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f789
 * Entry Point: 0042f789
 * Size: 242 bytes
 */


undefined4 Pic_Subsystem_0042f789(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      g_SpellStackDepth = g_SpellStackDepth + (*(int *)(&DAT_006b3000 + (7 - player) * 4) * 0x18) / 2
      ;
    }
    if (((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       ((player != g_EventSourcePlayer &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 0x40) !=
         0)))) {
      (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042f87b
 * Entry Point: 0042f87b
 * Size: 1562 bytes
 */


undefined4 Pic_Subsystem_0042f87b(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_18;
  undefined4 local_14;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521370,s_POWERLEAK_00521364);
      arg_20 = &local_18;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_14
        ;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_18;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,4,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        local_c = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                          [target_id * 0x120 + spell_id * 0x5b20],7,1);
        if (2 < local_c) {
          if (((local_c < 8) && (5 < (int)(&DAT_006b3008)[spell_id])) &&
             (7 < (int)(&g_PlayerCreatureCount)[spell_id])) {
            local_c = 0;
          }
          else {
            local_c = 2;
          }
        }
        local_8 = Ai_Subsystem_004cc56d
                            ((int)(char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20],spell_id,target_id,
                             (int)(char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             s_Take_the_2_damage__Pay_1_mana__t_0052137c,local_c);
        if (local_8 == 0) {
          local_10 = 2;
        }
        else if (local_8 == 1) {
          Magic_PushSpellStack(spell_id,target_id,0x7e,0,0);
          Ai_CalcManaRequirement_004ba890
                    ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],0,1);
          Magic_DropTopSpell();
          if (g_ActivePlayer == 1) {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else {
          Ai_CalcManaRequirement_004ba890
                    ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],0,2);
          if (g_ActivePlayer == 1) {
            local_10 = 2;
          }
          else {
            local_10 = 0;
          }
        }
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                   local_10,g_DialogPromptHwnd,g_DuelArenaHwnd);
        g_ActivePlayer = -1;
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0042fe9a
 * Entry Point: 0042fe9a
 * Size: 387 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0042fe9a(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
       ((*(byte *)(&DAT_006a2828 + player) & 2) != 0)) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) &&
       ((g_EventSourcePlayer == player && ((*(byte *)(&DAT_006a2828 + player) & 2) != 0)))) {
      iVar2 = Ai_Subsystem_004cc56d
                        (player,player,card_slot,-1,-1,s_Sacrifice_creature_to_use_gate__N_005213bc,0);
      if (iVar2 != 0) {
        iVar2 = Glue_Subsystem_004e6bff(player);
        if (iVar2 != -1) {
          Pic_Subsystem_0044867e(player,iVar2,3);
          if ((iVar2 != -1) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) *
                          0x5b20) * 0x34] & 0x40) != 0)) {
            Pic_Subsystem_0044867e(_DAT_0063ee20,iVar2,2);
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043001d
 * Entry Point: 0043001d
 * Size: 407 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0043001d(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player))
       && (g_ActivePlayerPriority == player)) {
      if (DAT_006b3018 == 0) {
        g_SpellStackDepth = g_SpellStackDepth + -0xf0;
      }
      else {
        iVar2 = Font_DrawString(g_ActivePlayerPriority,7,1);
        g_SpellStackDepth = g_SpellStackDepth + (iVar2 / 2 + (DAT_006b3018 - _DAT_006b301c)) * 0x18;
      }
    }
    if (((arg_3 == 0x85) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 0x40) !=
         0)) && ((g_EventSourcePlayer == DAT_0063edc0 && (g_TurnPlayer == DAT_0063edc0))))
    {
      *(uint *)(&g_CardSlot_SpecialState +
               g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) | 3;
      (&DAT_006a6048)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
           (&DAT_006a6048)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] + '\x02';
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004301b4
 * Entry Point: 004301b4
 * Size: 158 bytes
 */


undefined4 Pic_Subsystem_004301b4(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b3000 + (7 - player) * 4) - (&DAT_006b3018)[player]) * 0xc;
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00430252
 * Entry Point: 00430252
 * Size: 922 bytes
 */


uint Pic_Subsystem_00430252(int player,int card_slot,int arg_3)

{
  uint uVar1;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == player) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 1;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_ActivePlayerPriority] & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar1 = Glue_Subsystem_004d0a42(player,card_slot);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                         (char *)0x0,player,2,2,0x200,1,0,0,uVar1,arg_12,arg_13,iVar2,arg_15,arg_16,
                         arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
             (&g_CardSlot_CombatTarget)[card_slot * 0x120 + player * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20);
        Glue_Subsystem_004e65e1(Pic_Subsystem_004305f1,-1);
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    if (((arg_3 == 0x77) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_EventSourceSlot
        )) && (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] ==
                g_EventSourcePlayer && (g_EventSourceSlot != -1)))) {
      g_CardEventResult = 1;
    }
    if ((((arg_3 == 0x6c) && ((g_EventSourceSlot != card_slot || (g_EventSourcePlayer != player))))
        && (*(int *)(&g_CardSlot_OriginalCardId +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
            *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20))) &&
       (((&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] ==
         (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 4) != 0)
        ))) {
      g_ActivePlayer = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004305f1
 * Entry Point: 004305f1
 * Size: 283 bytes
 */


undefined4 Pic_Subsystem_004305f1(int player,int card_slot,int arg_3)

{
  if ((((((&g_MasterCardColorTable)[arg_3 * 0x34] & 4) != 0) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20))) &&
      ((&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] ==
       (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20])) &&
     ((*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) != 0x29 &&
      ((g_EventSourcePlayer != player || (g_EventSourceSlot != card_slot)))))) {
    Pic_Subsystem_0044867e(player,card_slot,1);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0043070c
 * Entry Point: 0043070c
 * Size: 2036 bytes
 */


undefined4 Pic_Subsystem_0043070c(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int iVar5;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_10;
  
  bVar1 = false;
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
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar2,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005213f0,s_EROSION_005213e8);
      iVar3 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar3 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) ==
            g_CurrentTurnPhase) {
          iVar3 = Card_ColorMaskToColorIndex((&DAT_0051aebe)
                               [*(int *)(&g_CardSlot_CardId +
                                        *(int *)(&g_CardSlot_AttachedAura +
                                                spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                                        *(int *)(&g_CardSlot_CombatTarget +
                                                spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               *(int *)(&DAT_0063ee30 + iVar3 * 4 + g_CurrentTurnPhase * 0x20) * -4 + 0x20;
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
      iVar5 = -1;
      iVar3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar4 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uVar4,arg_12,arg_13,iVar3,iVar5,arg_16
                         ,arg_17,arg_18,arg_19,arg_20);
      if (iVar3 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[spell_id * 0x5b20 + target_id * 0x120] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_SpecialState + spell_id * 0x5b20 + target_id * 0x120) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        iVar3 = 1;
        uVar4 = Card_ColorMaskToColorIndex((&DAT_006a5f4c)
                             [*(int *)(&g_CardSlot_OriginalCardId +
                                      spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                              (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] *
                              0x5b20]);
        iVar3 = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],uVar4,iVar3);
        iVar5 = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],7,1);
        if (iVar3 == 1) {
          if ((iVar5 < 4) &&
             (10 < (int)(&g_PlayerCreatureCount)
                        [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]])) {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else if ((iVar5 < 3) &&
                (0xf < (int)(&g_PlayerCreatureCount)
                            [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]]))
        {
          local_10 = 2;
        }
        else {
          local_10 = 0;
        }
        while (!bVar1) {
          iVar3 = Ai_Subsystem_004cc56d
                            ((int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],spell_id,target_id,
                             (int)(char)(&g_CardSlot_Toughness)
                                        [spell_id * 0x5b20 + target_id * 0x120],
                             *(int *)(&g_CardSlot_OriginalCardId +
                                     spell_id * 0x5b20 + target_id * 0x120),
                             s_Destroy_enchanted_land__Pay_1_ma_005213fc,local_10);
          if (iVar3 == 0) {
            Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120],
                       *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120),
                       2);
            bVar1 = true;
          }
          else if (iVar3 == 1) {
            iVar3 = Font_DrawString((int)(char)(&g_CardSlot_Toughness)
                                            [spell_id * 0x5b20 + target_id * 0x120],7,1);
            if (iVar3 != 0) {
              *(uint *)(&g_CardSlot_Flags +
                       *(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
                   *(uint *)(&g_CardSlot_Flags +
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
                bVar1 = true;
              }
            }
          }
          else if (iVar3 == 2) {
            (&g_PlayerCreatureCount)
            [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]] =
                 (&g_PlayerCreatureCount)
                 [(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120]] + -1;
            bVar1 = true;
          }
        }
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_00430f0a
 * Entry Point: 00430f0a
 * Size: 1326 bytes
 */


undefined4 Pic_Subsystem_00430f0a(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
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
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521448,s_CURSED_LAND_0052143c);
      iVar1 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar1 == 0);
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
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,iVar1,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0043143d
 * Entry Point: 0043143d
 * Size: 650 bytes
 */


uint Pic_Subsystem_0043143d(int player,int card_slot,int arg_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int local_c;
  
  if (arg_3 == 0x74) {
    if (player == g_CurrentTurnPhase) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 1;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      iVar2 = Glue_Subsystem_004e6dcc(player,1 - player,card_slot);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_slot * 0x120] == player) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_0063ee4c + (1 - player) * 0x20) - *(int *)(&DAT_0063ee4c + player * 0x20))
             * 0xc;
      }
    }
    if (((arg_3 == 0x7c) && (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x20) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_slot * 0x120) == g_EventSourceSlot
        && (((char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_slot * 0x120] ==
             g_EventSourcePlayer && (g_EventSourceSlot != -1)))))) {
      iVar2 = Glue_Subsystem_004e654a(g_EventSourcePlayer,1);
      bVar3 = iVar2 != 0;
      iVar2 = Glue_Subsystem_004e654a(1 - g_EventSourcePlayer,1);
      if (iVar2 != 0) {
        bVar3 = bVar3 | 2;
      }
      if (bVar3 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,2);
      }
      else {
        if (g_EventSourcePlayer == g_CurrentTurnPhase) {
          do {
          } while (local_c == -1);
        }
        else {
          do {
          } while (local_c == -1);
        }
        *(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_slot * 0x120) = local_c;
        (&g_CardSlot_Toughness)[player * 0x5b20 + card_slot * 0x120] = DAT_0063ee20;
      }
      Pic_Subsystem_0044867e(g_EventSourcePlayer,g_EventSourceSlot,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004316cc
 * Entry Point: 004316cc
 * Size: 756 bytes
 */


undefined4 Pic_Subsystem_004316cc(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    iVar1 = Card_UntapCard(player,card_slot,1);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + g_CurrentTurnPhase * 0x20) != 0) {
      iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase] /
                     *(int *)(&DAT_0063ee30 + iVar1 * 4 + g_CurrentTurnPhase * 0x20);
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    iVar1 = Card_UntapCard(player,card_slot,1);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + g_ActivePlayerPriority * 0x20) != 0) {
      iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] /
                     *(int *)(&DAT_0063ee30 + iVar1 * 4 + g_ActivePlayerPriority * 0x20);
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
    }
  }
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else if (arg_3 == 0x73) {
    if (((g_ScWillyScore == 4) &&
        (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) &&
       ((g_TurnPlayer == DAT_0063edc0 &&
        (iVar1 = Card_UntapCard(player,card_slot,1),
        *(int *)(&DAT_0063ee30 + iVar1 * 4 + DAT_0063edc0 * 0x20) != 0)))) {
      *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x101;
      DAT_006a4920 = DAT_006a4920 | 3;
      return 1;
    }
    uVar2 = 0;
  }
  else {
    if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
      DAT_00695df8 = 1;
      g_CardEventResult = g_CardEventResult | 1;
    }
    if (arg_3 == 0x86) {
      iVar1 = player;
      iVar4 = card_slot;
      iVar3 = Card_UntapCard(player,card_slot,1);
      Mem_AllocOrFree_0041df33
                (g_TurnPlayer,*(int *)(&DAT_0063ee30 + iVar3 * 4 + g_TurnPlayer * 0x20),
                 iVar1,iVar4);
    }
    if (arg_3 == 0x22) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
    }
    if (arg_3 == 199) {
      iVar1 = 1 - g_TurnPlayer;
      iVar4 = Card_UntapCard(player,card_slot,1);
      Mem_AllocOrFree_0041df33(iVar1,*(int *)(&DAT_0063ee30 + iVar4 * 4 + iVar1 * 0x20),player,card_slot)
      ;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_004319c5
 * Entry Point: 004319c5
 * Size: 1294 bytes
 */


undefined4 Pic_Subsystem_004319c5(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
      Pic_Subsystem_00424500(s_prompts_txt_00521464,s_EVIL_PRESENCE_00521454);
      iVar2 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x40 / (longlong)(*(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20) + 1));
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
        iVar2 = Card_UntapCard(spell_id,target_id,
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     target_id * 0x120 + spell_id * 0x5b20));
        *(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             iVar2 + -1;
        *(uint *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x1000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
        ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_EventSourceSlot &&
         (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_EventSourcePlayer && (g_EventSourceSlot != -1)))))) &&
       (iVar2 = Card_IsTapped(spell_id,target_id), iVar2 != 0)) {
      iVar2 = Card_UntapCard(spell_id,target_id,
                           *(int *)(&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20));
      g_CardEventResult = iVar2 + -1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00431ed3
 * Entry Point: 00431ed3
 * Size: 1830 bytes
 */


undefined4 Pic_Subsystem_00431ed3(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  int local_8;
  
  if ((((flags == 0x6e) &&
       (*(int *)(&g_CardSlot_CardId + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
        == DAT_006ff2e0)) &&
      ((char)(&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]
       == spell_id)) &&
     ((*(int *)(&g_CardSlot_OriginalCardId +
               g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == -1 &&
      (*(int *)(&g_CardSlot_ConvertedManaCost +
               g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) != 0)))) {
    *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) +
         *(int *)(&g_CardSlot_ConvertedManaCost +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120);
  }
  if (((g_CurrentStepCode == 0xd7) && (g_EventSourceSlot == target_id)) &&
     ((g_EventSourcePlayer == spell_id &&
      ((*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
       (spell_id == DAT_006a4b5c)))))) {
    if (flags == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (flags == 0x7e) {
      Glue_Subsystem_004e67e1
                (spell_id,target_id,
                 *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20));
      *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar1,arg_11_00,arg_12_00,
                         arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521480,s_LIVING_ARTIFACT_00521470);
      iVar2 = Glue_Subsystem_004e70ad(spell_id,2,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (g_ActivePlayer != 1) {
        if ((int)(&g_PlayerCreatureCount)[spell_id] < (int)(&g_PlayerCreatureCount)[1 - spell_id]) {
          local_8 = 3;
        }
        else {
          local_8 = 1;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (char)(&DAT_0051aec0)
                     [*(int *)(&g_CardSlot_CardId +
                              *(int *)(&g_CardSlot_AttachedAura +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                              *(int *)(&g_CardSlot_CombatTarget +
                                      target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34] *
               local_8 * 0x18;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + (uint)(local_8 * 0x18) / 2;
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == spell_id)) && (spell_id == DAT_0063edc0))
         && ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0
             && (iVar2 = Glue_Subsystem_004e6978(spell_id,target_id), iVar2 != 0)))) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) ||
           (iVar2 = FUN_0040dcca(spell_id,target_id,7,0), iVar2 != 0)) {
          if (g_ActivePlayerPriority == spell_id) {
            DAT_006a4920 = DAT_006a4920 | 3;
          }
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((flags == 0x6d) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) != 0) {
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
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004325fe
 * Entry Point: 004325fe
 * Size: 1300 bytes
 */


undefined4 Pic_Subsystem_004325fe(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521494,s_BLIGHT_0052148c);
      arg_20 = &local_10;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,2,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (local_10 == g_CurrentTurnPhase) {
          iVar5 = Card_ColorMaskToColorIndex((&DAT_0051aebe)
                               [*(int *)(&g_CardSlot_CardId + local_10 * 0x5b20 + local_c * 0x120) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x60 / (longlong)
                            (*(int *)(&DAT_0063ee30 + iVar5 * 4 + g_CurrentTurnPhase * 0x20) + 1));
        }
        if (local_10 == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x18;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                        0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) | 0x40000;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x81) &&
         (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_EventSourceSlot)) &&
        (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_EventSourcePlayer &&
         ((g_EventSourceSlot != -1 &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))))) &&
       (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0)) {
      iVar5 = Card_ApplyTriggerEffect(spell_id,target_id,DAT_006a4b64,
                           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(int *)(&g_CardSlot_OriginalCardId +
                                    target_id * 0x120 + spell_id * 0x5b20));
      if (iVar5 != -1) {
        (&DAT_006a5f50)[iVar5 * 0x120 + spell_id * 0x5b20] = 5;
      }
      *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00432b12
 * Entry Point: 00432b12
 * Size: 1118 bytes
 */


undefined4 Pic_Subsystem_00432b12(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214ac,s_TARGET_LAND_005214a0);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
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
                        (spell_id,2,1 - spell_id,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (local_c == g_CurrentTurnPhase) {
          iVar5 = Card_ColorMaskToColorIndex((&DAT_0051aebe)
                               [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) *
                                0x34]);
          g_SpellStackDepth =
               g_SpellStackDepth +
               (int)(0x60 / (longlong)
                            (*(int *)(&DAT_0063ee30 + iVar5 * 4 + g_CurrentTurnPhase * 0x20) + 1));
        }
        if (local_c == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_ActivePlayerPriority) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                        0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) | 0x40000;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && (g_EventSourceSlot != -1)))) {
      Mem_AllocOrFree_0041df33
                ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],2,
                 spell_id,target_id);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00432f70
 * Entry Point: 00432f70
 * Size: 231 bytes
 */


undefined4 Pic_Subsystem_00432f70(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) -
           *(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20)) * 0x18;
    }
    if (((arg_3 == 0x81) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 1) != 0)
        ) && (DAT_006ff2d4 != -1)) {
      Mem_AllocOrFree_0041df33(g_EventSourcePlayer,1,player,card_slot);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00433057
 * Entry Point: 00433057
 * Size: 475 bytes
 */


undefined4 Pic_Subsystem_00433057(int player,int card_slot,int arg_3)

{
  byte arg_1_00;
  undefined4 uVar1;
  int arg_2_00;
  int arg_3_00;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if (((arg_3 == 0x81) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 1) != 0)
        ) && (DAT_006ff2d4 != -1)) {
      FUN_0040d875(g_EventSourcePlayer,DAT_006ff2d4,1);
    }
    if (((arg_3 == 0x7f) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 1) != 0)
        ) && (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] &
              0x10) == 0)) {
      arg_1_00 = (&DAT_006a5f4c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      local_8 = 0;
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        if (((int)(char)arg_1_00 & 1 << ((byte)local_c & 0x1f)) != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 < 1) {
        arg_3_00 = 1;
        arg_2_00 = Card_ColorMaskToColorIndex(arg_1_00);
        FUN_0040d7e9(g_EventSourcePlayer,arg_2_00,arg_3_00);
      }
      else {
        FUN_0040d59c(g_EventSourcePlayer,(int)(char)arg_1_00,1);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00433232
 * Entry Point: 00433232
 * Size: 258 bytes
 */


undefined4 Pic_Subsystem_00433232(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((arg_3 == 0x81) && (g_EventSourcePlayer != player)) {
      iVar3 = *(int *)(&g_CardSlot_CardId +
                      g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120);
      iVar2 = Card_UntapCard(player,card_slot,3);
      if (*(int *)(&g_MasterCardTypeTable + iVar3 * 0x34) == *(int *)(&DAT_006ff2bc + iVar2 * 4)) {
        (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
      }
    }
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
       (g_EventSourcePlayer == player)) {
      iVar3 = Card_UntapCard(player,card_slot,3);
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee30 + iVar3 * 4 + g_CurrentTurnPhase * 0x20) * 3 + 3) * 8;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00433334
 * Entry Point: 00433334
 * Size: 306 bytes
 */


void Pic_Subsystem_00433334(int player,undefined4 card_slot,int arg_3)

{
  if (arg_3 != 0x74) {
    if ((((arg_3 == 0x32) && (g_EventSourcePlayer == player)) &&
        ((&DAT_0051aebd)
         [*(int *)(&g_CardSlot_CardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] == '\0'))
       && (((byte)*(undefined4 *)
                   (&g_CardSlot_Flags +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) & 0x22) == 2)) {
      g_CardEventResult = g_CardEventResult + 1;
    }
    if (((arg_3 == 0x34) && (g_EventSourcePlayer == player)) &&
       (((&DAT_0051aebd)
         [*(int *)(&g_CardSlot_CardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] == '\0' &&
        (((byte)*(undefined4 *)
                 (&g_CardSlot_Flags + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
         & 0x22) == 2)))) {
      g_CardEventResult = g_CardEventResult | 0x40;
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00433466
 * Entry Point: 00433466
 * Size: 438 bytes
 */


undefined4 Pic_Subsystem_00433466(int player,int card_slot,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       (((byte)*(undefined4 *)
                (&g_CardSlot_Flags + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
        & 0x22) == 2)) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(player,card_slot,2);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        g_CardEventResult = g_CardEventResult + 1;
      }
    }
    if (((arg_3 == 0x85) && (g_EventSourceSlot == card_slot)) &&
       ((g_EventSourcePlayer == player &&
        ((g_TurnPlayer == player && (DAT_0063edc0 == player)))))) {
      *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
      (&DAT_006a604a)[card_slot * 0x120 + player * 0x5b20] =
           (&DAT_006a604a)[card_slot * 0x120 + player * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if ((arg_3 == 199) && ((int)(&DAT_0063ee38)[player * 8] < 2)) {
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_0043361c
 * Entry Point: 0043361c
 * Size: 220 bytes
 */


undefined4 Pic_Subsystem_0043361c(int player,int card_slot,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if ((((arg_3 == 0x32) || (arg_3 == 0x33)) &&
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0)) &&
       (((byte)*(undefined4 *)
                (&g_CardSlot_Flags + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
        & 0x22) == 2)) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(player,card_slot,1);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        g_CardEventResult = g_CardEventResult + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_004336f8
 * Entry Point: 004336f8
 * Size: 934 bytes
 */


undefined4 Pic_Subsystem_004336f8(int player,int card_slot,int arg_3)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  int local_18;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar4 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      if (g_CurrentTurnPhase == player) {
        iVar5 = Math_RandomRange(5);
        local_18 = iVar5 + 1;
      }
      else {
        local_8 = -1;
        for (local_c = 1; local_c < 7; local_c = local_c + 1) {
          if (local_8 < *(int *)(&DAT_006b2e40 + local_c * 4 + (1 - player) * 0x20) +
                        *(int *)(&DAT_006b2fa0 + local_c * 4 + (1 - player) * 0x20)) {
            local_8 = *(int *)(&DAT_006b2fa0 + local_c * 4 + (1 - player) * 0x20) +
                      *(int *)(&DAT_006b2fa0 + local_c * 4 + (1 - player) * 0x20);
            local_18 = local_c;
          }
        }
      }
      if (player == 1) {
        local_1c = local_18;
      }
      else {
        local_1c = -1;
      }
      iVar5 = Ai_Subsystem_004cc93d(player,s_Jihad_color__005214b8,1,local_1c,0xffffffff);
      *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = iVar5;
      if (iVar5 == -1) {
        g_ActivePlayer = 1;
      }
    }
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       ((((byte)*(undefined4 *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x22) == 2 &&
        ((((byte)*(undefined4 *)
                  (&g_CardSlot_Flags + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                  ) & 0x22) == 2 &&
         (cVar1 = (&DAT_006a5f4c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120],
         bVar3 = Card_SetTapState(player, card_slot, 5), (1 << (bVar3 & 0x1f) & (int)cVar1) != 0)))))) {
      if (arg_3 == 0x32) {
        g_CardEventResult = g_CardEventResult + 2;
      }
      else {
        g_CardEventResult = g_CardEventResult + 1;
      }
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0) &&
        (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      bVar2 = false;
      iVar5 = 1 - player;
      bVar3 = (&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20];
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[iVar5]; local_c = local_c + 1) {
        iVar6 = Card_IsTapped(iVar5,local_c);
        if (((iVar6 != 0) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + iVar5 * 0x5b20) * 0x34] & 0x1e) != 0)
            ) && ((1 << (bVar3 & 0x1f) &
                  (int)(char)(&DAT_006a5f4d)[local_c * 0x120 + iVar5 * 0x5b20]) != 0)) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
        Pic_Subsystem_0044867e(player,card_slot,1);
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



/*
 * Decompiled function: Pic_Subsystem_00433a9e
 * Entry Point: 00433a9e
 * Size: 229 bytes
 */


undefined4 Pic_Subsystem_00433a9e(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_006b3010 + player * 4) * 0xc;
    }
    if (((arg_3 == 0x32) &&
        (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 4) !=
         0)) && ((player == g_TurnPlayer &&
                 ((g_EventSourcePlayer == player &&
                  (((byte)*(undefined4 *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) & 0x22
                   ) == 2)))))) {
      g_CardEventResult = g_CardEventResult + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00433b83
 * Entry Point: 00433b83
 * Size: 223 bytes
 */


undefined4 Pic_Subsystem_00433b83(int player,int card_slot,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if ((((arg_3 == 0x32) || (arg_3 == 0x33)) &&
        (((byte)*(undefined4 *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x22) == 2))
       && (((byte)*(undefined4 *)
                   (&g_CardSlot_Flags +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) & 0x22) == 2)) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(player, card_slot, 5);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        g_CardEventResult = g_CardEventResult + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_00433c62
 * Entry Point: 00433c62
 * Size: 851 bytes
 */


undefined4 Pic_Subsystem_00433c62(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214d8,s_ASPECTOFWOLF_005214c8);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_EventSourceSlot) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_EventSourcePlayer)) &&
       ((g_EventSourceSlot != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 0x32) {
        iVar2 = Card_UntapCard(spell_id,target_id,3);
        g_CardEventResult =
             g_CardEventResult + *(int *)(&DAT_0063ee30 + iVar2 * 4 + spell_id * 0x20) / 2;
      }
      if (flags == 0x33) {
        iVar2 = Card_UntapCard(spell_id,target_id,3);
        g_CardEventResult =
             g_CardEventResult + (*(int *)(&DAT_0063ee30 + iVar2 * 4 + spell_id * 0x20) + 1) / 2;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00433fb5
 * Entry Point: 00433fb5
 * Size: 1401 bytes
 */


undefined4 Pic_Subsystem_00433fb5(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  undefined1 local_8;
  
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214ec,&DAT_005214e4);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if ((g_CurrentStepCode == 0xda) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      g_CurrentStepCode = 0xffffffff;
      if (((((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
             g_TurnPlayer) &&
           ((((&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 4)
             != 0 && (((&g_CardSlot_Flags)
                       [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 2) != 0))))
          && ((&g_CardSlot_ColorMask)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]
              == -1)) && (g_EventSourcePlayer != g_TurnPlayer)) {
        iVar2 = Pic_Subsystem_0043452e
                          (g_EventSourcePlayer,g_EventSourceSlot,
                           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(undefined4 *)
                             (&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
        if (iVar2 != 0) {
          if ((&g_CardSlot_ColorMask)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] ==
              -1) {
            local_8 = (undefined1)
                      *(undefined4 *)
                       (&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          }
          else {
            local_8 = (&g_CardSlot_ColorMask)
                      [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
          }
          if (flags == 0x7d) {
            g_CardEventResult = g_CardEventResult | 2;
          }
          if (flags == 0x7e) {
            (&g_CardSlot_ColorMask)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
                 local_8;
            *(uint *)(&g_CardSlot_Flags +
                     g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
                 *(uint *)(&g_CardSlot_Flags +
                          g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) | 0x8008;
          }
        }
      }
      g_CurrentStepCode = 0xda;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043452e
 * Entry Point: 0043452e
 * Size: 123 bytes
 */


undefined4 Pic_Subsystem_0043452e(int x,int card_slot,int arg_3,int arg_4)

{
  uint arg_5;
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  uint local_8;
  
  arg_5 = Magic_QueryCardAttribute(arg_3,arg_4,0x34,0xffffffff);
  Ai_FilterValidBlockers(&local_8,&local_c);
  if (x == 1) {
    local_10 = local_8;
  }
  else {
    local_10 = local_c;
  }
  uVar1 = FUN_00472c0c(x,card_slot,arg_3,arg_4,arg_5,local_10);
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004345a9
 * Entry Point: 004345a9
 * Size: 1398 bytes
 */


undefined4 Pic_Subsystem_004345a9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  int local_8;
  
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521504,s_SPIRITLINK_005214f8);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,2,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (g_ActivePlayer != 1) {
        iVar2 = Magic_QueryCardAttribute(*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
        g_SpellStackDepth = g_SpellStackDepth + iVar2 * 0x18;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                 ) == DAT_006ff2e0)) &&
       (((&g_CardSlot_DamageReceived)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]
         == (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] &&
        ((*(int *)(&g_CardSlot_TypeFlags +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) != 0)))))) {
      *(int *)(&g_CardSlot_CombatTarget +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_EventSourcePlayer;
      *(int *)(&g_CardSlot_AttachedAura +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_EventSourceSlot;
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((((g_CurrentStepCode == 0xd7) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
        (spell_id == DAT_006a4b5c)))) {
      if (flags == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (flags == 0x7e) {
        for (local_8 = 0;
            local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20
                              ); local_8 = local_8 + 1) {
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_AttachedAura +
                               target_id * 0x120 + spell_id * 0x5b20 + local_8 * 8) * 0x120 +
                       *(int *)(&g_CardSlot_CombatTarget +
                               target_id * 0x120 + spell_id * 0x5b20 + local_8 * 8) * 0x5b20);
        }
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00434b1f
 * Entry Point: 00434b1f
 * Size: 1043 bytes
 */


undefined4 Pic_Subsystem_00434b1f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521520,s_CREATUREBOND_00521510);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x77) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer &&
        ((g_EventSourceSlot != -1 &&
         (iVar2 = Pic_Subsystem_00451291(spell_id,DAT_006ff564), iVar2 != -1)))))) {
      *(undefined4 *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + spell_id * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + iVar2 * 0x120 + spell_id * 0x5b20) = 0x32;
      uVar1 = Magic_QueryCardAttribute(g_EventSourcePlayer,g_EventSourceSlot,0x33,0xffffffff);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) = uVar1;
      (&g_CardSlot_Toughness)[iVar2 * 0x120 + spell_id * 0x5b20] =
           (undefined1)g_EventSourcePlayer;
      FUN_00476482(spell_id,iVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00434f32
 * Entry Point: 00434f32
 * Size: 1153 bytes
 */


undefined4 Pic_Subsystem_00434f32(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521538,s_GASEOUSFORM_0052152c);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,2,target_id);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x21) && ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) &&
       (*(int *)(&g_CardSlot_CardId + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
        == DAT_006ff2e0)) {
      if (((&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] ==
           (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]) &&
         (*(int *)(&g_CardSlot_OriginalCardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20))) {
        (&DAT_006a5f4f)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
             (&g_CardSlot_ConvertedManaCost)
             [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) = 0;
      }
      if (((&g_CardSlot_DamageReceived)
           [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] ==
           (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]) &&
         (*(int *)(&g_CardSlot_TypeFlags +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20))) {
        (&DAT_006a5f4f)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
             (&g_CardSlot_ConvertedManaCost)
             [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004353b3
 * Entry Point: 004353b3
 * Size: 1804 bytes
 */


undefined4 Pic_Subsystem_004353b3(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  int local_10;
  
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521550,s_BACKFIRE_00521544);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (g_ActivePlayer != 1) {
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
            g_CurrentTurnPhase) {
          iVar2 = Magic_QueryCardAttribute(*(int *)(&g_CardSlot_CombatTarget +
                                       target_id * 0x120 + spell_id * 0x5b20),
                               *(int *)(&g_CardSlot_AttachedAura +
                                       target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + iVar2 * 0xc;
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x6e) &&
         (*(int *)(&g_CardSlot_CardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == DAT_006ff2e0))
        && ((*(int *)(&g_CardSlot_OriginalCardId +
                     g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) == -1 &&
            (((char)(&g_CardSlot_Toughness)
                    [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] == spell_id &&
             (*(int *)(&g_CardSlot_TypeFlags +
                      g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
              *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20))))))) &&
       ((&g_CardSlot_DamageReceived)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]
        == (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20])) {
      *(int *)(&g_CardSlot_CombatTarget +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_EventSourcePlayer;
      *(int *)(&g_CardSlot_AttachedAura +
              target_id * 0x120 +
              spell_id * 0x5b20 +
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) * 8) =
           g_EventSourceSlot;
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((((g_CurrentStepCode == 0xd7) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
        (spell_id == DAT_006a4b5c)))) {
      if (flags == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (flags == 0x7e) {
        for (local_10 = 0;
            local_10 <
            *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
            local_10 = local_10 + 1) {
          Mem_AllocOrFree_0041df33
                    ((int)(char)(&g_CardSlot_DamageReceived)
                                [*(int *)(&g_CardSlot_AttachedAura +
                                         target_id * 0x120 + spell_id * 0x5b20 + local_10 * 8) *
                                 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 +
                                                 spell_id * 0x5b20 + local_10 * 8) * 0x5b20],
                     *(int *)(&g_CardSlot_ConvertedManaCost +
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_10 * 8) * 0x120 +
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_10 * 8) * 0x5b20)
                     ,spell_id,target_id);
        }
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    if (((flags == 0x8a) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && (g_EventSourceSlot != -1)))) {
      DAT_006ff19c = DAT_006ff19c +
                     *(short *)(&g_CardSlot_Counters +
                               *(int *)(&g_CardSlot_OriginalCardId +
                                       target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                               (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                               * 0x5b20) * 0x18;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00435abf
 * Entry Point: 00435abf
 * Size: 2625 bytes
 */


undefined4 Pic_Subsystem_00435abf(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
       (spell_id == g_EventSourcePlayer)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
      *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
      Pic_Subsystem_00424500(s_prompts_txt_00521568,s_HOLY_ARMOR_0052155c);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x33) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         g_EventSourceSlot &&
        (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
          g_EventSourcePlayer && (g_EventSourceSlot != -1)))))) {
      g_CardEventResult = g_CardEventResult + 2;
    }
    if (flags == 0x73) {
      uVar1 = FUN_0040dcca(spell_id,target_id,5,1);
    }
    else if (flags == 0x90) {
      if (spell_id == g_TurnPlayer) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      DAT_006fefa8 = (int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] << 8
                     | *(uint *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120)
      ;
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (iVar2 = FUN_0040dcca(spell_id,target_id,5,1), iVar2 != 0)) {
        if (spell_id == g_TurnPlayer) {
          iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
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
          iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) =
               (int)(char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120];
          *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) =
               *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120);
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)
          {
            *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) |
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
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                       0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120
                                       ) * 0x5b20) +
               (*(uint *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) & 0xff) *
               0x100;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120
                + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] &
              8) != 0) {
            *(uint *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                     0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120)
                             * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120
                                  ) * 0x120 +
                          *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                          0x5b20) & 0xfff7ffff;
            iVar2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [spell_id * 0x5b20 + target_id * 0x120],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         spell_id * 0x5b20 + target_id * 0x120));
            if (iVar2 != -1) {
              *(short *)(&DAT_006a5f4a + iVar2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(undefined4 *)
                           (&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
              *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) |
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
        *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + spell_id * 0x5b20 + target_id * 0x120);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00436500
 * Entry Point: 00436500
 * Size: 2656 bytes
 */


undefined4 Pic_Subsystem_00436500(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      Pic_Subsystem_00424500(s_prompts_txt_00521580,s_BLESSING_00521574);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      uVar1 = FUN_0040dcca(spell_id,target_id,5,1);
    }
    else if (flags == 0x90) {
      if (g_TurnPlayer == spell_id) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      DAT_006fefa8 = (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] << 8
                     | *(uint *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
      ;
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (iVar2 = FUN_0040dcca(spell_id,target_id,5,1), iVar2 != 0)) {
        if (g_TurnPlayer == spell_id) {
          iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
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
          iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,5,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,5,1);
          }
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
          {
            *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) |
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
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) +
               (*(uint *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) & 0xff);
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) +
               (*(uint *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) & 0xff) *
               0x100;
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120]
              & 8) != 0) {
            *(uint *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                     + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                           target_id * 0x120 + spell_id * 0x5b20) * 0x120) &
                 0xfff7ffff;
            iVar2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [target_id * 0x120 + spell_id * 0x5b20],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         target_id * 0x120 + spell_id * 0x5b20));
            if (iVar2 != -1) {
              *(short *)(&DAT_006a5f48 + iVar2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(undefined4 *)
                           (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
              *(short *)(&DAT_006a5f4a + iVar2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(undefined4 *)
                           (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
              *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) |
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
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00436f60
 * Entry Point: 00436f60
 * Size: 2522 bytes
 */


undefined4 Pic_Subsystem_00436f60(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (spell_id == g_EventSourcePlayer)) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      Pic_Subsystem_00424500(s_prompts_txt_0052159c,s_FIREBREATHING_0052158c);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      uVar1 = FUN_0040dcca(spell_id,target_id,4,1);
    }
    else if (flags == 0x90) {
      if (spell_id == g_TurnPlayer) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
          Ai_CalcLifeAdvantage(0);
        }
        else {
          DAT_0062785c = 1;
        }
      }
      else {
        DAT_0062785c = 1;
      }
      DAT_006fefa8 = (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] << 8
                     | *(uint *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
      ;
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (iVar2 = FUN_0040dcca(spell_id,target_id,4,1), iVar2 != 0)) {
        if (spell_id == g_TurnPlayer) {
          iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
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
          iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
          if (*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) {
            Ai_CalcManaRequirement_004ba890(spell_id,4,1);
          }
          else {
            Ai_Subsystem_004be192(spell_id,target_id,4,1);
          }
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
        }
        if (g_ActivePlayer == 1) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
          {
            *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) |
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
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) +
               (*(uint *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) & 0xff);
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
          if (((&DAT_006a5f56)
               [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120]
              & 8) != 0) {
            *(uint *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                     + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost +
                          *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                           target_id * 0x120 + spell_id * 0x5b20) * 0x120) &
                 0xfff7ffff;
            iVar2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,
                                 (int)(char)(&g_CardSlot_Toughness)
                                            [target_id * 0x120 + spell_id * 0x5b20],
                                 *(int *)(&g_CardSlot_OriginalCardId +
                                         target_id * 0x120 + spell_id * 0x5b20));
            if (iVar2 != -1) {
              *(short *)(&DAT_006a5f48 + iVar2 * 0x120 + spell_id * 0x5b20) =
                   (short)*(undefined4 *)
                           (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
              *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) =
                   *(uint *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + spell_id * 0x5b20) |
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
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043793a
 * Entry Point: 0043793a
 * Size: 387 bytes
 */


void Pic_Subsystem_0043793a(int spell_id,int target_id,int flags)

{
  int iVar1;
  
  if (flags != 0x74) {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215b8,s_INVISIBILITY_005215a8);
      iVar1 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventTargetSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_EventTargetPlayer &&
        ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         ((&DAT_0051aebd)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] != '\0')))
        ))) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00437ac2
 * Entry Point: 00437ac2
 * Size: 820 bytes
 */


undefined4 Pic_Subsystem_00437ac2(int spell_id,int target_id,int flags)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215cc,&DAT_005215c4);
      iVar4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
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
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventTargetSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_EventTargetPlayer &&
        ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(spell_id,target_id,1);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) == 0) {
        g_CardEventResult = g_CardEventResult + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_00437df6
 * Entry Point: 00437df6
 * Size: 820 bytes
 */


undefined4 Pic_Subsystem_00437df6(int spell_id,int target_id,int flags)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215e0,s_SEEKER_005215d8);
      iVar4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
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
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         g_EventTargetSlot)) &&
       (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == g_EventTargetPlayer &&
        ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(spell_id,target_id,5);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) == 0) {
        g_CardEventResult = g_CardEventResult + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_0043812a
 * Entry Point: 0043812a
 * Size: 754 bytes
 */


undefined4 Pic_Subsystem_0043812a(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215f0,&DAT_005215ec);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_EventSourceSlot) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_EventSourcePlayer)) &&
       ((g_EventSourceSlot != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 0x33) {
        g_CardEventResult = g_CardEventResult + 2;
      }
      if (flags == 0x34) {
        g_CardEventResult = g_CardEventResult | 0x400;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043841c
 * Entry Point: 0043841c
 * Size: 1143 bytes
 */


undefined4 Pic_Subsystem_0043841c(int player,int card_slot,int arg_3)

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
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      iVar2 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1);
      if (iVar2 == 0) {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_006b2e5c + (1 - player) * 0x20) - *(int *)(&DAT_006b2e5c + player * 0x20))
        ;
      }
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = (undefined1)player;
    }
    if (((arg_3 == 0x85) && (g_EventSourceSlot == card_slot)) &&
       ((g_EventSourcePlayer == player &&
        ((g_TurnPlayer == player && (g_TurnPlayer == DAT_0063edc0)))))) {
      *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
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
        iVar2 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          iVar2 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        local_c = 0;
        for (local_8 = 0; local_8 < iVar2; local_8 = local_8 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1)
              && (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
              & 2) != 0)) {
            if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) == 0) {
              iVar3 = FUN_004728c3(g_CurrentTurnPhase,local_8);
              if (iVar3 == 0) {
                local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                              local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20);
              }
            }
            else {
              local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                            local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) * 2;
            }
          }
          if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
                -1) && (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                        != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
                0x34] & 2) != 0)) {
            if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0
               ) {
              iVar3 = FUN_004728c3(g_ActivePlayerPriority,local_8);
              if (iVar3 == 0) {
                local_c = local_c - *(short *)(&g_CardSlot_Counters +
                                              local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20);
              }
            }
            else {
              local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                            local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) * -2;
            }
          }
        }
        g_SpellStackDepth = g_SpellStackDepth + local_c * 0xc;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00438893
 * Entry Point: 00438893
 * Size: 258 bytes
 */


undefined4 Pic_Subsystem_00438893(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((g_TurnPlayer == player) && ((g_DuelModeFlags & 1) != 0)) {
      g_DuelModeFlags = g_DuelModeFlags & 0xfffffffe;
      if (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else {
        Mem_AllocOrFree_0041df33(player,1,player,card_slot);
      }
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00438995
 * Entry Point: 00438995
 * Size: 856 bytes
 */


undefined4 Pic_Subsystem_00438995(int player,int card_slot,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e48 + (1 - player) * 0x20) - *(int *)(&DAT_006b2e48 + player * 0x20));
    }
    if (arg_3 == 0x82) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(player,card_slot,2);
      if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 2) != 0
         )) {
        *(uint *)(&DAT_006a6038 + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
             *(uint *)(&DAT_006a6038 + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120
                      ) & 0xfffffffc;
      }
    }
    if (((arg_3 == 0x84) &&
        (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 0x10)
         != 0)) &&
       ((g_TurnPlayer == g_EventSourcePlayer &&
        ((g_TurnPlayer == DAT_0063edc0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 2) != 0
         )))))) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(player,card_slot,2);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        *(uint *)(&g_CardSlot_SpecialState +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
             *(uint *)(&g_CardSlot_SpecialState +
                      g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) | 0x10;
        (&DAT_006a603c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
             (&DAT_006a603c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] + '\x04'
        ;
      }
    }
    if (arg_3 == 0x6c) {
      cVar1 = (&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120];
      bVar2 = Card_SetTapState(player,card_slot,2);
      if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 2) != 0
         )) {
        (&DAT_006a603c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
             (&DAT_006a603c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] + '\x04'
        ;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_00438ced
 * Entry Point: 00438ced
 * Size: 1819 bytes
 */


undefined4 Pic_Subsystem_00438ced(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  undefined1 local_98 [12];
  undefined1 *local_8c;
  undefined1 local_88 [128];
  undefined1 *local_8;
  
  local_8 = local_88;
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521608,s_PARALYZE_005215fc);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,2,target_id);
      if (iVar2 == 0) {
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
          else if (((&DAT_0051aebd)
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        FUN_00415d48((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x82) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && (g_EventSourceSlot != -1)))) {
      *(uint *)(&DAT_006a6038 +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006a6038 +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) & 0xfffffffc;
    }
    if (((((flags == 0x84) &&
          (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_EventSourceSlot)) &&
         ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_EventSourcePlayer)) &&
        ((g_EventSourceSlot != -1 &&
         (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10)
          != 0)))) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
        && (g_TurnPlayer == DAT_0063edc0)))) {
      *(uint *)(&g_CardSlot_SpecialState +
               g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState +
                    g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) | 0x10;
      (&DAT_006a603c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] =
           (&DAT_006a603c)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] + '\x04';
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00439408
 * Entry Point: 00439408
 * Size: 987 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_00439408(int player,int card_slot,int arg_3)

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
    if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player))
       && (iVar2 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120),
                                -1), iVar2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e5c + g_CurrentTurnPhase * 0x20) -
           *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20)) * 0xc;
    }
    if ((arg_3 == 0x82) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 2) != 0))
    {
      *(uint *)(&DAT_006a6038 + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
           *(uint *)(&DAT_006a6038 + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
           & 0xfffffffd;
      _DAT_006ff198 = _DAT_006ff198 | 2;
    }
    if (((g_ScWillyScore == 1) && (g_EventSourceSlot == card_slot)) &&
       (g_EventSourcePlayer == player)) {
      if (((arg_3 == 0x7d) &&
          (iVar2 = UI_PaintBigCardInfo((int *)0x0,0,g_TurnPlayer,g_TurnPlayer,g_TurnPlayer,
                                0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,
                                0x800,0), iVar2 == 0)) &&
         (iVar2 = UI_PaintBigCardInfo((int *)0x0,0,g_TurnPlayer,g_TurnPlayer,g_TurnPlayer,
                               0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400
                               ,0), iVar2 != 0)) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (arg_3 == 0x7e) {
        if (g_TurnPlayer == 1) {
          local_10 = g_TurnPlayer;
          local_c = Pic_Subsystem_00441a42(1,2);
          Ai_Subsystem_004cc56d
                    (player,player,card_slot,local_10,local_c,s_Opponent_chooses_to_untap__00521614,0);
        }
        else {
          Action_ValidateTarget_00405802
                    (g_TurnPlayer,g_TurnPlayer,g_TurnPlayer,0x200,2,0,0,0,0,0,-1,-1,
                     0xffffffff,0xffffffff,0,0x401,0,s_PROCESSING_Smoke__Select_creatur_00521630,0,
                     &local_10);
        }
        *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) =
             *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) | 2;
        for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[g_TurnPlayer];
            local_8 = local_8 + 1) {
          iVar2 = Card_IsTapped(g_TurnPlayer,local_8);
          if (((iVar2 != 0) &&
              (((&g_CardSlot_Flags)[local_8 * 0x120 + g_TurnPlayer * 0x5b20] & 0x10) != 0)) &&
             ((((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_TurnPlayer * 0x5b20) * 0x34]
               & 2) != 0 &&
              (((&DAT_006a6038)[local_8 * 0x120 + g_TurnPlayer * 0x5b20] & 2) == 0)))) {
            *(uint *)(&DAT_006a6038 + local_8 * 0x120 + g_TurnPlayer * 0x5b20) =
                 *(uint *)(&DAT_006a6038 + local_8 * 0x120 + g_TurnPlayer * 0x5b20) &
                 0xfffffffe;
          }
        }
      }
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004397e3
 * Entry Point: 004397e3
 * Size: 938 bytes
 */


undefined4 Pic_Subsystem_004397e3(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6a) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) = 0;
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[g_TurnPlayer];
          local_c = local_c + 1) {
        iVar2 = Card_IsTapped(g_TurnPlayer,local_c);
        if (((iVar2 != 0) &&
            (((&g_CardSlot_Flags)[local_c * 0x120 + g_TurnPlayer * 0x5b20] & 0x10) == 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_TurnPlayer * 0x5b20) * 0x34] &
            1) != 0)) {
          *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
               *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) + 1;
        }
      }
    }
    if (arg_3 == 0x73) {
      if (((g_ScWillyScore == 4) &&
          (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) &&
         (g_TurnPlayer == DAT_0063edc0)) {
        *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (arg_3 == 0x86) {
        Mem_AllocOrFree_0041df33
                  (g_TurnPlayer,
                   *(int *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20),player,card_slot);
        *(undefined4 *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) = 0;
      }
      if (arg_3 == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
      }
      if (arg_3 == 199) {
        local_8 = 0;
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[1 - g_TurnPlayer];
            local_c = local_c + 1) {
          iVar2 = Card_IsTapped(1 - g_TurnPlayer,local_c);
          if (((iVar2 != 0) &&
              (((&g_CardSlot_Flags)[local_c * 0x120 + (1 - g_TurnPlayer) * 0x5b20] & 0x10) == 0
              )) && (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId +
                               local_c * 0x120 + (1 - g_TurnPlayer) * 0x5b20) * 0x34] & 1) != 0
                    )) {
            local_8 = local_8 + 1;
          }
        }
        Mem_AllocOrFree_0041df33(1 - g_TurnPlayer,local_8,player,card_slot);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00439b92
 * Entry Point: 00439b92
 * Size: 500 bytes
 */


uint Pic_Subsystem_00439b92(int spell_id,int target_id,int flags)

{
  uint uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    if (spell_id == g_CurrentTurnPhase) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 2;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521664,s_COCOON_0052165c);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_EventSourceSlot) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_EventSourcePlayer)) &&
       ((g_EventSourceSlot != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 4) {
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) + 1;
      }
      if (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) < 4) {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      else {
        if (flags == 0x33) {
          g_CardEventResult = g_CardEventResult + 1;
        }
        if (flags == 0x32) {
          g_CardEventResult = g_CardEventResult + 1;
        }
        if (flags == 0x34) {
          g_CardEventResult = g_CardEventResult | 0x20;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00439d8b
 * Entry Point: 00439d8b
 * Size: 123 bytes
 */


void Pic_Subsystem_00439d8b(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052167c,s_BURROWING_00521670);
  }
  cVar1 = Card_UntapCard(spell_id,target_id,4);
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,1 << (cVar1 - 1U & 0x1f));
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00439e06
 * Entry Point: 00439e06
 * Size: 1313 bytes
 */


undefined4 Pic_Subsystem_00439e06(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
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
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521694,s_WANDERLUST_00521688);
      iVar1 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
      g_ActivePlayer = (uint)(iVar1 == 0);
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
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0043a32c
 * Entry Point: 0043a32c
 * Size: 2364 bytes
 */


undefined4 Pic_Subsystem_0043a32c(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005216b0,s_INSTILL_ENERGY_005216a0);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if ((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) {
        if (((&DAT_0051aebd)
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
        if ((((&DAT_0051aed0)
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        if (((&g_CardSlot_Flags)
             [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
              (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 2) !=
            0) {
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xfffcffff;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
      if ((*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) ||
         (iVar2 = FUN_0040dcca(spell_id,target_id,7,0), iVar2 != 0)) {
        if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)
            && ((((&g_CardSlot_Flags)
                  [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20] & 0x10) != 0 && (g_TurnPlayer == g_EventSourcePlayer))))
           && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if ((flags == 0x6d) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) != 0) {
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
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffffef;
        }
      }
      if ((((((g_CurrentStepCode == 0xd4) && (g_EventSourceSlot == target_id)) &&
            (g_EventSourcePlayer == spell_id)) &&
           ((*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
            ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)))) &&
          ((*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) != -1 &&
           ((DAT_00695f08 == spell_id && (DAT_006b2e14 == target_id)))))) &&
         (spell_id == DAT_006a4b5c)) {
        if (flags == 0x7d) {
          g_CardEventResult = g_CardEventResult | 2;
        }
        if (flags == 0x7e) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 0x30000;
        }
      }
      if (((flags == 0x22) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043ac68
 * Entry Point: 0043ac68
 * Size: 811 bytes
 */


undefined4 Pic_Subsystem_0043ac68(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if (flags == 0x73) {
      iVar2 = FUN_0040dcca(spell_id,target_id,2,2);
      if (iVar2 != 0) {
        arg_19 = 0;
        arg_18_00 = 0;
        arg_17 = 0;
        arg_16 = 0xffffffff;
        arg_15 = 0xffffffff;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        arg_12 = 0;
        uVar1 = 0;
        uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
        iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3 | 0x20,uVar1,arg_12,arg_13,
                             arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
        if (iVar2 != 0) {
          return 1;
        }
      }
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (Ai_Subsystem_004be192(spell_id,target_id,2,2), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_005216c4,s_FLOOD_005216bc);
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
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3 | 0x20,uVar4,uVar5,iVar2,iVar6,
                           uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               local_8;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
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
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3 | 0x20,uVar4,uVar5,
                           iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
        if (iVar2 == 0) {
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
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043af93
 * Entry Point: 0043af93
 * Size: 212 bytes
 */


undefined4 Pic_Subsystem_0043af93(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else if (arg_3 == 0x73) {
    if ((g_ActivePlayerPriority == player) && ((&g_PlayerCreatureCount)[player] == 2)) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0040dcca(player,card_slot,1,1);
      if ((iVar2 == 0) || ((int)(&g_PlayerCreatureCount)[player] < 2)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
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
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043b067
 * Entry Point: 0043b067
 * Size: 368 bytes
 */


undefined4 Pic_Subsystem_0043b067(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else if (arg_3 == 0x73) {
    uVar1 = FUN_0040dcca(player,card_slot,1,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0040dcca(player,card_slot,1,1);
      if (iVar2 != 0) {
        Ai_Subsystem_004be192(player,card_slot,1,1);
      }
    }
    if (arg_3 == 0x72) {
      Mem_AllocOrFree_0041df33(1 - player,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      Mem_AllocOrFree_0041df33(player,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      Glue_Subsystem_004e65e1(Pic_Subsystem_0043b1d7,-1);
    }
    if ((((g_CurrentStepCode == 0xcd) && (g_EventSourceSlot == card_slot)) &&
        (g_EventSourcePlayer == player)) && (DAT_006a4b5c == player)) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (arg_3 == 0x7e) {
        iVar2 = Glue_Subsystem_004e654a(player,2);
        if (iVar2 == 0) {
          iVar2 = Glue_Subsystem_004e654a(1 - player,2);
          if (iVar2 == 0) {
            Pic_Subsystem_0044867e(player,card_slot,2);
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043b1d7
 * Entry Point: 0043b1d7
 * Size: 77 bytes
 */


undefined4 Pic_Subsystem_0043b1d7(int player,int card_slot,int arg_3)

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


undefined4 Pic_Subsystem_0043b224(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((&g_PlayerCreatureCount)[player] - (&g_PlayerCreatureCount)[1 - player]) * 0xc;
    }
    if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
      iVar2 = Font_DrawString(player,3,*(int *)(&g_CardSlot_ConvertedManaCost +
                                           card_slot * 0x120 + player * 0x5b20) + 1);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,2);
      }
      else {
        iVar2 = Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_Pay_mana__No_Yes_005216d0,1);
        if (iVar2 == 0) {
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
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043b424
 * Entry Point: 0043b424
 * Size: 711 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0043b424(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *str_2;
  int local_28;
  int local_20;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x6c) {
      iVar5 = *(int *)(&DAT_006b2e5c + player * 0x20);
      iVar3 = Math_Clamp(*(int *)(&DAT_006b3010 + player * 4),1,99);
      iVar1 = *(int *)(&DAT_006b2e5c + (1 - player) * 0x20);
      iVar4 = Math_Clamp(*(int *)(&DAT_006b3000 + (5 - player) * 4),1,99);
      g_SpellStackDepth = g_SpellStackDepth + ((iVar5 * 0xc) / iVar3 - (iVar1 * 0xc) / iVar4);
    }
    if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      local_10 = 999;
      local_20 = 0;
      local_14 = 0xffffffff;
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar5 = Card_IsTapped(local_8,local_c);
          if ((iVar5 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            iVar5 = Magic_QueryCardAttribute(local_8,local_c,0x32,0xffffffff);
            if (iVar5 < local_10) {
              local_14 = local_8 * 0x100 + local_c;
              local_20 = 0;
              local_10 = iVar5;
            }
            if (iVar5 == local_10) {
              local_20 = local_20 + 1;
            }
          }
        }
      }
      if (local_20 == 1) {
        Pic_Subsystem_0044867e((int)local_14 >> 8,local_14 & 0xff,1);
      }
      if (1 < local_20) {
        do {
          strcpy(&g_OverworldWorldState,s_Lowest_power_is_005216e4);
          str_2 = _itoa(local_10,&DAT_00538b80,10);
          strcat(&g_OverworldWorldState,str_2);
          local_18 = -1;
          if (local_28 != -1) {
            local_18 = Magic_QueryCardAttribute(_DAT_0063ee20,local_28,0x32,0xffffffff);
          }
        } while (local_18 != local_10);
        Pic_Subsystem_0044867e(_DAT_0063ee20,local_28,1);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0043b6eb
 * Entry Point: 0043b6eb
 * Size: 99 bytes
 */


void Pic_Subsystem_0043b6eb(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521700,s_LANCE_005216f8);
  }
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,0x100);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043b74e
 * Entry Point: 0043b74e
 * Size: 123 bytes
 */


void Pic_Subsystem_0043b74e(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
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


void Pic_Subsystem_0043b7c9(int x,int y,int width,uint height)

{
  undefined4 arg_10;
  int iVar1;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    if (((width == 0x6c) && (g_EventSourceSlot == y)) && (g_EventSourcePlayer == x)) {
      iVar1 = Glue_Subsystem_004e69ac(x,x,y);
      if (iVar1 == 0) {
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
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(x,y);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,arg_15,arg_16,arg_17,arg_18,
                         arg_19,arg_20);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(x,y,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] =
             (&g_CardSlot_CombatTarget)[y * 0x120 + x * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) == g_EventSourceSlot) &&
        ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_EventSourcePlayer)) &&
       ((g_EventSourceSlot != -1 &&
        ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x20) == 0 && (width == 0x34)))))) {
      g_CardEventResult = g_CardEventResult | height;
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043ba6e
 * Entry Point: 0043ba6e
 * Size: 98 bytes
 */


void Pic_Subsystem_0043ba6e(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521738,s_HOLY_STRENGTH_00521728);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,1,2);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043bad0
 * Entry Point: 0043bad0
 * Size: 98 bytes
 */


void Pic_Subsystem_0043bad0(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521754,s_GIANT_STRENGTH_00521744);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,2);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043bb32
 * Entry Point: 0043bb32
 * Size: 98 bytes
 */


void Pic_Subsystem_0043bb32(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052176c,s_IMMOLATION_00521760);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,-2);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043bb94
 * Entry Point: 0043bb94
 * Size: 98 bytes
 */


void Pic_Subsystem_0043bb94(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521790,s_DIVINE_TRANSFORMATION_00521778);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,3,3);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043bbf6
 * Entry Point: 0043bbf6
 * Size: 98 bytes
 */


void Pic_Subsystem_0043bbf6(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005217ac,s_UNHOLY_STRENGTH_0052179c);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,1);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043bc58
 * Entry Point: 0043bc58
 * Size: 98 bytes
 */


void Pic_Subsystem_0043bc58(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
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


undefined4 Pic_Subsystem_0043bcba(int player,int card_slot,int arg_3,int arg_4,int arg_5)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 uVar3;
  uint arg_12;
  undefined4 uVar4;
  uint arg_13;
  undefined4 uVar5;
  undefined4 uVar6;
  int arg_15;
  undefined4 uVar7;
  uint arg_16;
  undefined4 uVar8;
  uint arg_17;
  undefined4 uVar9;
  uint arg_18;
  undefined4 uVar10;
  uint arg_19;
  undefined4 uVar11;
  uint arg_20;
  uint local_8;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == player) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = Glue_Subsystem_004d0a42(player,card_slot);
      uVar1 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
    else if (arg_5 + arg_4 < 0) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = Glue_Subsystem_004d0a42(player,card_slot);
      uVar1 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
    else {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = Glue_Subsystem_004d0a42(player,card_slot);
      uVar1 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      if (arg_5 + arg_4 < 0) {
        local_8 = 1 - player;
      }
      else {
        local_8 = player;
      }
      iVar2 = Glue_Subsystem_004e69ac(player,local_8,card_slot);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(player,card_slot);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                         (char *)0x0,player,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,arg_16,
                         arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(player,card_slot,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
             (&g_CardSlot_CombatTarget)[card_slot * 0x120 + player * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0) {
      if (((arg_3 == 0x32) &&
          (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) ==
           g_EventSourceSlot)) &&
         (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer
          && (g_EventSourceSlot != -1)))) {
        g_CardEventResult = g_CardEventResult + arg_4;
      }
      if (((arg_3 == 0x33) &&
          (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) ==
           g_EventSourceSlot)) &&
         (((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer
          && (g_EventSourceSlot != -1)))) {
        g_CardEventResult = g_CardEventResult + arg_5;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043c0b2
 * Entry Point: 0043c0b2
 * Size: 194 bytes
 */


undefined4 Pic_Subsystem_0043c0b2(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x33) && (g_EventSourcePlayer == player)) &&
        (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 0x14)
         == 0)) &&
       ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x20) == 0 &&
        (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 2) !=
         0)))) {
      g_CardEventResult = g_CardEventResult + 2;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043c174
 * Entry Point: 0043c174
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c174(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,1);
  Pic_Subsystem_0043c287(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c1ab
 * Entry Point: 0043c1ab
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c1ab(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,3);
  Pic_Subsystem_0043c287(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c1e2
 * Entry Point: 0043c1e2
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c1e2(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,2);
  Pic_Subsystem_0043c287(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c219
 * Entry Point: 0043c219
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c219(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,4);
  Pic_Subsystem_0043c287(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c250
 * Entry Point: 0043c250
 * Size: 55 bytes
 */


void Pic_Subsystem_0043c250(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player, card_slot, 5);
  Pic_Subsystem_0043c287(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043c287
 * Entry Point: 0043c287
 * Size: 1646 bytes
 */


undefined4 Pic_Subsystem_0043c287(int spell_id,int target_id,int flags,int height)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_10;
  int local_8;
  
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005217dc,s_ANY_WARD_005217d0);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_ActivePlayerPriority) {
          iVar2 = *(int *)(&DAT_006b2e40 + height * 4 + g_CurrentTurnPhase * 0x20);
          iVar3 = Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)
                                          [target_id * 0x120 + spell_id * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId +
                                       target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + (iVar2 + 1) * iVar3 * 3;
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
      iVar3 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar4 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar4,arg_12,arg_13,iVar2,iVar3,arg_16
                         ,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    uVar4 = g_CardEventResult;
    if (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8];
            local_10 = local_10 + 1) {
          if (((((((&g_CardSlot_Flags)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0) &&
                (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
                 *(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + local_8 * 0x5b20))) &&
               (((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
                 (&g_CardSlot_Toughness)[local_10 * 0x120 + local_8 * 0x5b20] &&
                ((int)(char)(&DAT_006a5f4d)[local_10 * 0x120 + local_8 * 0x5b20] ==
                 1 << ((byte)height & 0x1f))))) &&
              ((spell_id != local_8 || (target_id != local_10)))) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 4) != 0
             )) {
            g_CardEventResult = uVar4;
            Pic_Subsystem_0044867e(local_8,local_10,1);
          }
        }
      }
    }
    g_CardEventResult = uVar4;
    if ((((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_EventSourceSlot) &&
         ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) &&
       ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (height = Card_SetTapState(spell_id,target_id,height), flags == 0x34)))) {
      g_CardEventResult = g_CardEventResult | 0x800 << ((char)height - 1U & 0x1f);
    }
    if (((flags == 0x6c) &&
        ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         (&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120])) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         *(int *)(&g_CardSlot_OriginalCardId +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) &&
        (((1 << ((byte)height & 0x1f) &
          (int)(char)(&DAT_006a5f4d)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120])
          != 0 && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))))) {
      g_CardEventResult = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043c8f5
 * Entry Point: 0043c8f5
 * Size: 2249 bytes
 */


undefined4 Pic_Subsystem_0043c8f5(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005217fc,s_UNSTABLE_MUTATION_005217e8);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) &&
         (((&DAT_006a5f3e)
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x32) || (flags == 0x33)) &&
       ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_EventSourceSlot &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_EventSourcePlayer)) && (g_EventSourceSlot != -1)))))) {
      g_CardEventResult = g_CardEventResult + 3;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
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
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -1;
        *(uint *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x6000000;
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      if (flags == 199) {
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -2;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) + -2;
        if (((g_ActivePlayerPriority == spell_id) && (g_TurnPlayer == g_ActivePlayerPriority))
           && (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20] & 0x40) == 0)) {
          g_SpellStackDepth = g_SpellStackDepth + -0x3c;
        }
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043d1c3
 * Entry Point: 0043d1c3
 * Size: 2124 bytes
 */


undefined4 Pic_Subsystem_0043d1c3(int spell_id,int target_id,int flags)

{
  bool bVar1;
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
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      do {
        Pic_Subsystem_00424500(s_prompts_txt_00521818,s_COPY_ARTIFACT_00521808);
        arg_20 = &local_10;
        uVar2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
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
                          (spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar6 == 0) {
          g_ActivePlayer = 1;
        }
        else if (((&g_MasterCardColorTable)
                  [*(int *)(&g_ActiveCardsInPlay + local_10 * 0x5b20 + local_c * 0x120) * 0x34] &
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
               local_10;
          *(int *)(&g_CardSlot_AttachedAura +
                  target_id * 0x120 +
                  spell_id * 0x5b20 +
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
               local_c;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      } while ((g_ActivePlayer != 1) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_ActiveCardsInPlay + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 0x40
               ) == 0));
    }
    if (flags == 0x71) {
      uVar12 = 0;
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
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8
                         ,uVar9,uVar10,uVar11,uVar12);
      if (iVar6 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        bVar1 = false;
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
          bVar1 = true;
        }
        if (bVar1) {
          local_8 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                         *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&g_CardSlot_AttachedAura +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        else {
          local_8 = FUN_0041d8a6(*(int *)(&g_ActiveCardsInPlay +
                                         *(int *)(&g_CardSlot_CombatTarget +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                                         *(int *)(&g_CardSlot_AttachedAura +
                                                 target_id * 0x120 + spell_id * 0x5b20) * 0x120));
        }
        if (local_8 != -1) {
          *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = local_8;
          *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
               0x1000000;
          (&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] =
               (&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] | 4;
        }
        (&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_006a5f4d)
             [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120];
        if (bVar1) {
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
          (&DAT_006a2828)[spell_id] =
               (&DAT_006a2828)[spell_id] |
               (uint)(byte)(&g_MasterCardColorTable)
                           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) *
                            0x34];
          *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) |
               (spell_id == 0) - 1 & 0x400000 | 0x30082;
          DAT_00695f08 = spell_id;
          DAT_006b2e14 = target_id;
          FUN_00476205(g_TurnPlayer,0xdb,s_Card_into_play_0052185c,0);
        }
        else {
          Pic_Subsystem_0042ac1f(spell_id,target_id);
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
        (g_EventSourceSlot == target_id)) &&
       ((g_EventSourcePlayer == spell_id &&
        (iVar6 = Card_IsTapped(spell_id,target_id), iVar6 != 0)))) {
      g_CardEventResult =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0043da0f
 * Entry Point: 0043da0f
 * Size: 1447 bytes
 */


undefined4 Pic_Subsystem_0043da0f(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
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
  
  if (((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_CurrentTurnPhase)
    {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&g_PlayerCreatureCount)
                     [(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
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
    uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052187c,s_TARGET_ARTIFACT_0052186c);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (local_c == g_CurrentTurnPhase) {
          g_SpellStackDepth =
               g_SpellStackDepth +
               ((char)(&DAT_0051aec0)
                      [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34] * 3
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
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,0x40,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7
                         ,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_TurnPlayer == DAT_0063edc0)) &&
          ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == g_TurnPlayer
          )) && (((&g_CardSlot_ConvertedManaCost)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0))
      {
        *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (g_EventSourceSlot == target_id)) &&
         (g_EventSourcePlayer == spell_id)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],1,
                   spell_id,target_id);
      }
      if (flags == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
             0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0043dfbb
 * Entry Point: 0043dfbb
 * Size: 315 bytes
 */


undefined4 Pic_Subsystem_0043dfbb(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ede4 + player * 0x20) * 0xc;
    }
    if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      iVar2 = Font_DrawString(player,5,2);
      if (iVar2 != 0) {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if ((((arg_3 == 4) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) ||
       (arg_3 == 199)) {
      iVar2 = Font_DrawString(player,5,2);
      if (iVar2 != 0) {
        iVar2 = Ai_Subsystem_004cc56d
                          (player,player,card_slot,-1,-1,s_Add_life_for_2_white_mana__No_Ye_00521888,1);
        if (iVar2 != 0) {
          Ai_CalcManaRequirement_004ba890(player,5,2);
          (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043e0f6
 * Entry Point: 0043e0f6
 * Size: 1697 bytes
 */


undefined4 Pic_Subsystem_0043e0f6(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int aiStack_288 [160];
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (arg_3 == 0x73) {
      if (((g_ScWillyScore == 4) &&
          (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) &&
         (g_TurnPlayer == DAT_0063edc0)) {
        *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x101;
        DAT_006a4920 = DAT_006a4920 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
        DAT_00695df8 = 1;
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (arg_3 == 0x86) {
        if (g_IsAiThinking == 1) {
          return 0;
        }
        for (local_290 = 0; local_290 < 2; local_290 = local_290 + 1) {
          local_294 = 0;
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_290];
              local_8 = local_8 + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_290 * 0x5b20) != -1) &&
                (((&g_CardSlot_Flags)[local_8 * 0x120 + local_290 * 0x5b20] & 2) != 0)) &&
               ((((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_290 * 0x5b20) * 0x34] &
                 0x43) != 0 &&
                (iVar4 = local_8 * 0x120, uVar2 = Glue_Subsystem_004d0a42(player,card_slot),
                (*(uint *)(&g_CardSlot_Abilities2 + iVar4 + local_290 * 0x5b20) & uVar2) == 0)))) {
              aiStack_288[local_294 + local_290 * 0x50] = local_8;
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
        if (g_TurnPlayer == g_CurrentTurnPhase) {
          if (local_2a8 < 1) {
            g_ActivePlayer = 1;
          }
          else {
            iVar4 = Math_RandomRange(local_2a8);
            local_298 = aiStack_288[iVar4 + g_CurrentTurnPhase * 0x50];
            local_28c = 0;
            local_29c = 0;
            local_294 = Math_RandomRange(local_2a4);
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
          iVar4 = Math_RandomRange(local_2a4);
          local_2a0 = aiStack_288[iVar4 + g_ActivePlayerPriority * 0x50];
          local_28c = 0;
          local_29c = 0;
          local_294 = Math_RandomRange(local_2a8);
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
          pcVar3 = (char *)Ai_Subsystem_004b8e4d(g_CurrentTurnPhase,local_298);
          strcat(&g_OverworldWorldState,pcVar3);
          strcat(&g_OverworldWorldState,s_for_005218c0);
          pcVar3 = (char *)Ai_Subsystem_004b8e4d(g_ActivePlayerPriority,local_2a0);
          strcat(&g_OverworldWorldState,pcVar3);
          Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,&g_OverworldWorldState,0);
          Pic_Subsystem_0042ce63(g_CurrentTurnPhase,local_298,g_ActivePlayerPriority,local_2a0);
        }
        if (g_ActivePlayer != 1) {
          Duel_PlaySoundById(0x2a);
        }
      }
      if (arg_3 == 0x22) {
        *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) & 0xfffffffe;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043e79c
 * Entry Point: 0043e79c
 * Size: 1054 bytes
 */


undefined4 Pic_Subsystem_0043e79c(int player,int card_slot,int arg_3)

{
  short sVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (arg_3 == 0x74) {
    uVar5 = 1;
  }
  else if (arg_3 == 0x73) {
    iVar6 = Glue_Subsystem_004e6978(player,card_slot);
    if ((iVar6 != 0) && (iVar6 = FUN_0040dcca(player,card_slot,7,5), iVar6 != 0)) {
      if ((player == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      return 1;
    }
    uVar5 = 0;
  }
  else {
    if ((((arg_3 == 0x6d) && (iVar6 = FUN_0040dcca(player,card_slot,7,5), iVar6 != 0)) &&
        (Ai_Subsystem_004be192(player,card_slot,0,5), g_ActivePlayer != 1)) && (0 < DAT_006ff550)) {
      DAT_006ff550 = DAT_006ff550 + -1;
    }
    if (arg_3 == 0x72) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x26);
      }
      iVar6 = Pic_Subsystem_0045268f(900);
      iVar6 = Pic_Subsystem_00451291(player,iVar6);
      if (iVar6 != -1) {
        Pic_Subsystem_0042ac1f(player,iVar6);
        cVar2 = Card_SetTapState(player,card_slot,1);
        (&DAT_006a5f4d)[iVar6 * 0x120 + player * 0x5b20] = (char)(2 << (cVar2 - 1U & 0x1f));
        *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + player * 0x5b20) | 0x10;
        if (((&g_CardSlot_Abilities1)[player * 0x5b20 + card_slot * 0x120] & 2) != 0) {
          *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + player * 0x5b20) | 2;
          (&DAT_006a6030)[iVar6 * 0x120 + player * 0x5b20] =
               (&DAT_006a6030)[player * 0x5b20 + card_slot * 0x120];
        }
        *(undefined4 *)(&DAT_006a5f74 + iVar6 * 0x120 + player * 0x5b20) =
             *(undefined4 *)
              (&g_MasterCardTypeTable +
              *(int *)(&g_ActiveCardsInPlay + player * 0x5b20 + card_slot * 0x120) * 0x34);
        sVar1 = *(short *)(&DAT_006a5f48 + iVar6 * 0x120 + player * 0x5b20);
        sVar4 = Math_RandomRange(3);
        *(short *)(&DAT_006a5f48 + iVar6 * 0x120 + player * 0x5b20) = sVar1 + sVar4;
        sVar1 = *(short *)(&DAT_006a5f4a + iVar6 * 0x120 + player * 0x5b20);
        sVar4 = Math_RandomRange(3);
        *(short *)(&DAT_006a5f4a + iVar6 * 0x120 + player * 0x5b20) = sVar1 + sVar4;
        Glue_Subsystem_004e676b(g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
    }
    if (((arg_3 == 0x77) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x34] & 2) != 0)
        ) && ((((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] &
               0x20) == 0 &&
              (((&DAT_006a5f50)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] !=
                '\x04' &&
               (cVar2 = (&DAT_006a5f4d)
                        [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120],
               cVar3 = Card_SetTapState(player,card_slot,1), (2 << (cVar3 - 1U & 0x1f) & (int)cVar2) == 0))))
             )) {
      Glue_Subsystem_004e66b3(player,card_slot);
    }
    uVar5 = 0;
  }
  return uVar5;
}



/*
 * Decompiled function: Pic_Subsystem_0043ebbf
 * Entry Point: 0043ebbf
 * Size: 1503 bytes
 */


undefined4 Pic_Subsystem_0043ebbf(int spell_id,int target_id,int flags)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
       (spell_id == g_EventSourcePlayer)) {
      Pic_Subsystem_00424500(s_prompts_txt_005218d8,s_REGENERATION_005218c8);
      iVar4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar4 == 0);
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
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x73) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
      bVar1 = (&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
      cVar2 = (&DAT_006a5f50)
              [*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) * 0x120
               + (char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
      iVar4 = FUN_0040dcca(spell_id,target_id,3,1);
      if (iVar4 == 0 || (cVar2 != '\x02' || (bVar1 & 2) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
    else if (flags == 0x90) {
      Ai_GetOpponentPlayerScore(0);
      uVar3 = 0;
    }
    else {
      if (((flags == 0x6d) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,3,1), g_ActivePlayer != 1)) {
        DAT_00695df8 = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) + 1;
      }
      if ((flags == 0x72) && ((g_DuelModeFlags._1_1_ & 2) != 0)) {
        *(undefined4 *)
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
      uVar3 = 0;
    }
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_0043f19e
 * Entry Point: 0043f19e
 * Size: 895 bytes
 */


undefined4 Pic_Subsystem_0043f19e(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005218f4,s_ETERNAL_WARRIOR_005218e4);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      g_ActivePlayer = (uint)(iVar2 == 0);
      if (((g_ActivePlayer != 1) && (g_ActivePlayerPriority == spell_id)) &&
         ((iVar2 = FUN_004728c3(*(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20),
                                *(int *)(&g_CardSlot_AttachedAura +
                                        target_id * 0x120 + spell_id * 0x5b20)), iVar2 != 0 ||
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_EventSourceSlot) &&
        ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) {
      *(uint *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) | 0x2000;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043f51d
 * Entry Point: 0043f51d
 * Size: 1498 bytes
 */


undefined4 Pic_Subsystem_0043f51d(int spell_id,int target_id,int flags)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052190c,s_THE_BRUTE_00521900);
      iVar4 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
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
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x73) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      bVar1 = (&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      cVar2 = (&DAT_006a5f50)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
      iVar4 = FUN_0040dcca(spell_id,target_id,4,3);
      if (iVar4 == 0 || (cVar2 != '\x02' || (bVar1 & 2) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
    else if (flags == 0x90) {
      Ai_GetOpponentPlayerScore(0);
      uVar3 = 0;
    }
    else {
      if (((flags == 0x6d) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,4,3), g_ActivePlayer != 1)) {
        DAT_00695df8 = 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
      }
      if ((flags == 0x72) && ((g_DuelModeFlags._1_1_ & 2) != 0)) {
        *(undefined4 *)
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
             g_EventSourceSlot) &&
           ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) &&
         ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
          (flags == 0x32)))) {
        g_CardEventResult = g_CardEventResult + 1;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}



/*
 * Decompiled function: Pic_Subsystem_0043faf7
 * Entry Point: 0043faf7
 * Size: 639 bytes
 */


uint Pic_Subsystem_0043faf7(int spell_id,int target_id,int flags)

{
  uint uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 2;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521924,s_EARTH_BIND_00521918);
    }
    iVar2 = Glue_Subsystem_004e69ac(spell_id,1 - spell_id,target_id);
    g_ActivePlayer = (uint)(iVar2 == 0);
    if ((flags == 0x71) &&
       (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      uVar1 = Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(int *)(&g_CardSlot_OriginalCardId +
                                    target_id * 0x120 + spell_id * 0x5b20),0x34,0xffffffff);
      if ((uVar1 & 0x20) != 0) {
        Card_ApplyCombatDamage((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),2,
                     spell_id,target_id);
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && ((g_EventSourceSlot != -1 && (flags == 0x34)))))) {
      g_CardEventResult = g_CardEventResult & 0xffffffdf;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0043fd7b
 * Entry Point: 0043fd7b
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fd7b(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,1);
  Pic_Subsystem_0043fe8e(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fdb2
 * Entry Point: 0043fdb2
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fdb2(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player, card_slot, 5);
  Pic_Subsystem_0043fe8e(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fde9
 * Entry Point: 0043fde9
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fde9(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,4);
  Pic_Subsystem_0043fe8e(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fe20
 * Entry Point: 0043fe20
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fe20(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,2);
  Pic_Subsystem_0043fe8e(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fe57
 * Entry Point: 0043fe57
 * Size: 55 bytes
 */


void Pic_Subsystem_0043fe57(int player,int card_slot,int arg_3)

{
  int height;
  
  height = Card_SetTapState(player,card_slot,3);
  Pic_Subsystem_0043fe8e(player,card_slot,arg_3,height);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0043fe8e
 * Entry Point: 0043fe8e
 * Size: 1014 bytes
 */


undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags,int height)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       (iVar2 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       iVar2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee30 + height * 4 + g_CurrentTurnPhase * 0x20) +
           *(int *)(&DAT_006b2e40 + height * 4 + g_CurrentTurnPhase * 0x20) / 2) * 0x18;
    }
    if (flags == 0x73) {
      if (((((byte)g_DuelModeFlags & 4) == 0) ||
          (iVar2 = FUN_0040dcca(spell_id,target_id,7,1), iVar2 == 0)) ||
         (iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0,
                               DAT_006ff2e0,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), iVar2 == 0))
      {
        uVar1 = 0;
      }
      else {
        uVar1 = 99;
      }
    }
    else {
      if (((flags == 0x6d) &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,0,1), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_00521948,s_CIRCLE_OF_PROTECTION_00521930);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((byte)height & 0x1f),0,DAT_006ff2e0,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&local_c);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               local_8;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        iVar2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,0,
                           1 << ((byte)height & 0x1f),0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,0
                           ,0);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) != 0) {
          *(undefined4 *)
           (&g_CardSlot_ConvertedManaCost +
           *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00440289
 * Entry Point: 00440289
 * Size: 1027 bytes
 */


undefined4 Pic_Subsystem_00440289(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 6;
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       (iVar2 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       iVar2 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee48 + g_CurrentTurnPhase * 0x20) +
            *(int *)(&DAT_006b2e40 + g_CurrentTurnPhase * 0x20) / 2 +
           *(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20)) * 0x18;
    }
    if (flags == 0x73) {
      if ((((byte)g_DuelModeFlags & 4) != 0) &&
         (iVar2 = FUN_0040dcca(spell_id,target_id,7,2), iVar2 != 0)) {
        iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,
                             DAT_006ff2e0,0xffffffff,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar2 != 0) {
          return 99;
        }
      }
      uVar1 = 0;
    }
    else {
      if (((flags == 0x6d) &&
          (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) &&
         (Ai_Subsystem_004be192(spell_id,target_id,0,2), g_ActivePlayer != 1)) {
        Pic_Subsystem_00424500(s_prompts_txt_0052196c,s_CIRCLE_OF_PROTECTION_00521954);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0,0,0,0,1 << ((byte)local_8 & 0x1f),0,DAT_006ff2e0,-1,
                           0xffffffff,0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&local_10);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               local_c;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
        iVar2 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20
                                   ),
                           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ),(char *)0x0,spell_id,2,2,0x200,0,0,0,0,
                           1 << ((byte)local_8 & 0x1f),0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,
                           0,0);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x5b20 +
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20)
                         * 0x120) != 0) {
          *(undefined4 *)
           (&g_CardSlot_ConvertedManaCost +
           *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0044068c
 * Entry Point: 0044068c
 * Size: 1213 bytes
 */


undefined4 Pic_Subsystem_0044068c(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
  int local_c;
  int local_8;
  
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
      Pic_Subsystem_00424500(s_prompts_txt_0052198c,s_PHANTASMAL_TERRAIN_00521978);
      iVar2 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (g_CurrentTurnPhase == spell_id) {
          if (spell_id == 1) {
            local_c = Math_RandomRange(5);
            local_c = local_c + 1;
          }
          else {
            local_c = -1;
          }
          local_8 = Ai_Subsystem_004cc93d(spell_id,s_Land_type__00521998,0,local_c,0x3e);
          if (local_8 == -1) {
            g_ActivePlayer = 1;
          }
        }
        else if (g_IsAiThinking == 1) {
          local_8 = Math_RandomRange(5);
          local_8 = local_8 + 1;
          g_AiDecisionScore = local_8;
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
          local_8 = g_AiDecisionScore;
        }
        if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == spell_id)
        {
          g_SpellStackDepth = g_SpellStackDepth + -0x30;
        }
        *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = local_8;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) =
             *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) + -1;
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
        *(uint *)(&g_CardSlot_Abilities2 +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 +
                      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                              0x5b20) | 0x1000000;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if ((((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
        ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_EventSourceSlot &&
         (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
           g_EventSourcePlayer && (g_EventSourceSlot != -1)))))) &&
       (iVar2 = Card_IsTapped(spell_id,target_id), iVar2 != 0)) {
      g_CardEventResult =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00440b49
 * Entry Point: 00440b49
 * Size: 620 bytes
 */


undefined4 Pic_Subsystem_00440b49(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
       (g_EventSourcePlayer == player)) {
      iVar2 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1);
      if (iVar2 == 0) {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_006b2e54 + g_ActivePlayerPriority * 0x20) -
             *(int *)(&DAT_006b2e54 + g_CurrentTurnPhase * 0x20)) * 0xc;
      }
    }
    if (arg_3 == 0x71) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 5;
    }
    if (((arg_3 == 0x85) && (g_EventSourceSlot == card_slot)) &&
       ((g_EventSourcePlayer == player &&
        ((g_TurnPlayer == player && (g_TurnPlayer == DAT_0063edc0)))))) {
      *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
      (&DAT_006a604d)[card_slot * 0x120 + player * 0x5b20] =
           (&DAT_006a604d)[card_slot * 0x120 + player * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if ((arg_3 == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) {
      iVar2 = Card_IsTapped(player,card_slot);
      if (iVar2 != 0) {
        iVar2 = Card_IsTapped(g_EventSourcePlayer,g_EventSourceSlot);
        if (iVar2 != 0) {
          iVar2 = Card_UntapCard(player,card_slot,4);
          if (*(int *)(&DAT_006ff2bc + iVar2 * 4) ==
              *(int *)(&g_MasterCardTypeTable + g_CardEventResult * 0x34)) {
            iVar2 = Card_UntapCard(player,card_slot,
                                 *(int *)(&g_CardSlot_ConvertedManaCost +
                                         card_slot * 0x120 + player * 0x5b20));
            g_CardEventResult = iVar2 + -1;
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00440db5
 * Entry Point: 00440db5
 * Size: 946 bytes
 */


undefined4 Pic_Subsystem_00440db5(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
      Pic_Subsystem_00424500(s_prompts_txt_005219b0,s_WILD_GROWTH_005219a4);
      iVar2 = Glue_Subsystem_004e6dcc(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((flags == 0x81) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer && ((g_EventSourceSlot != -1 && (DAT_006ff2d4 != -1)))))) {
      FUN_0040d875((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],3,1);
    }
    if ((((flags == 0x7f) &&
         (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
          g_EventSourceSlot)) &&
        ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_EventSourcePlayer)) &&
       ((g_EventSourceSlot != -1 &&
        (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 0x10)
         == 0)))) {
      FUN_0040d7e9(g_EventSourcePlayer,3,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00441167
 * Entry Point: 00441167
 * Size: 885 bytes
 */


undefined4 Pic_Subsystem_00441167(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
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
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    uVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005219c4,s_FLIGHT_005219bc);
      iVar2 = Glue_Subsystem_004e69ac(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
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
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0) &&
        (*(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourceSlot)) &&
       ((*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) ==
         g_EventSourcePlayer && ((g_EventSourceSlot != -1 && (flags == 0x34)))))) {
      g_CardEventResult = g_CardEventResult | 0x20;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004414dc
 * Entry Point: 004414dc
 * Size: 686 bytes
 */


undefined4 Pic_Subsystem_004414dc(int player,int card_slot,int arg_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee34)[(1 - player) * 8] * 5 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (DAT_006b2d3c == -1) {
        uVar2 = 0;
      }
      else {
        if ((((byte)g_DuelModeFlags & 0x20) != 0) &&
           (iVar3 = FUN_0040dcca(player,card_slot,3,2), iVar3 != 0)) {
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 2;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar5 = -1;
          iVar3 = -1;
          uVar4 = 0;
          bVar1 = Card_SetTapState(player,card_slot,1);
          iVar3 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,player,2,2,0,0,0,0,0,
                             1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
          if (iVar3 != 0) {
            return 99;
          }
        }
        uVar2 = 0;
      }
    }
    else {
      if (((arg_3 == 0x6d) && (iVar3 = FUN_0040dcca(player,card_slot,3,2), iVar3 != 0)) &&
         ((DAT_006b2d3c != -1 && (Ai_Subsystem_004be192(player,card_slot,3,2), g_ActivePlayer != 1)))) {
        *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) = DAT_006b2d2c;
      }
      if (arg_3 == 0x72) {
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 2;
        uVar7 = 0xffffffff;
        uVar6 = 0xffffffff;
        iVar5 = -1;
        iVar3 = -1;
        uVar4 = 0;
        bVar1 = Card_SetTapState(player,card_slot,1);
        iVar3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                           (char *)0x0,player,2,2,0,0,0,0,0,1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,
                           uVar6,uVar7,uVar8,uVar9,uVar10);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),1);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_0044178f
 * Entry Point: 0044178f
 * Size: 686 bytes
 */


undefined4 Pic_Subsystem_0044178f(int player,int card_slot,int arg_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_SpellStackDepth =
           g_SpellStackDepth + *(int *)(&DAT_0063ee3c + (1 - player) * 0x20) * 5 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (DAT_006b2d3c == -1) {
        uVar2 = 0;
      }
      else {
        if ((((byte)g_DuelModeFlags & 0x20) != 0) &&
           (iVar3 = FUN_0040dcca(player,card_slot,1,2), iVar3 != 0)) {
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 2;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar5 = -1;
          iVar3 = -1;
          uVar4 = 0;
          bVar1 = Card_SetTapState(player,card_slot,3);
          iVar3 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,player,2,2,0,0,0,0,0,
                             1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
          if (iVar3 != 0) {
            return 99;
          }
        }
        uVar2 = 0;
      }
    }
    else {
      if (((arg_3 == 0x6d) && (iVar3 = FUN_0040dcca(player,card_slot,1,2), iVar3 != 0)) &&
         ((DAT_006b2d3c != -1 && (Ai_Subsystem_004be192(player,card_slot,1,2), g_ActivePlayer != 1)))) {
        *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) = DAT_006b2d2c;
      }
      if (arg_3 == 0x72) {
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 2;
        uVar7 = 0xffffffff;
        uVar6 = 0xffffffff;
        iVar5 = -1;
        iVar3 = -1;
        uVar4 = 0;
        bVar1 = Card_SetTapState(player,card_slot,3);
        iVar3 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                           (char *)0x0,player,2,2,0,0,0,0,0,1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,
                           uVar6,uVar7,uVar8,uVar9,uVar10);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),1);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_00441a42
 * Entry Point: 00441a42
 * Size: 1480 bytes
 */


int Pic_Subsystem_00441a42(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_5a0 [50];
  int local_4d8;
  int aiStack_4d4 [50];
  int aiStack_40c [50];
  byte abStack_344 [200];
  int local_27c;
  int local_278;
  int local_274;
  int aiStack_270 [50];
  int local_1a8;
  int aiStack_1a4 [50];
  int local_dc;
  int aiStack_d8 [50];
  int local_10;
  int local_c;
  int local_8;
  
  if (arg1 == -1) {
    local_8 = -1;
  }
  else if (arg2 == 1) {
    local_8 = -1;
    local_c = -10;
    local_1a8 = 0;
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[arg1]; local_10 = local_10 + 1) {
      local_dc = *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + arg1 * 0x5b20);
      if (((local_dc != -1) && (((&g_CardSlot_Flags)[local_10 * 0x120 + arg1 * 0x5b20] & 2) != 0))
         && ((((&g_MasterCardColorTable)[local_dc * 0x34] & 1) != 0 &&
             (((&g_CardSlot_Flags)[local_10 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)))) {
        aiStack_d8[local_1a8] = local_10;
        aiStack_1a4[local_1a8] = 0;
        local_1a8 = local_1a8 + 1;
      }
    }
    for (local_10 = 0; local_10 < local_1a8; local_10 = local_10 + 1) {
      if (((&DAT_0051aed0)
           [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + aiStack_d8[local_10] * 0x120) * 0x34] & 1)
          != 0) {
        aiStack_1a4[local_10] = aiStack_1a4[local_10] + 1;
      }
      if (((&DAT_006a5f3e)[local_10 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
        aiStack_1a4[local_10] = -1;
      }
    }
    for (local_10 = 0; local_10 < local_1a8; local_10 = local_10 + 1) {
      if (local_c < aiStack_1a4[local_10]) {
        local_c = aiStack_1a4[local_10];
        local_8 = aiStack_d8[local_10];
      }
    }
  }
  else if (arg2 == 2) {
    local_8 = -1;
    local_c = -1;
    local_274 = 0;
    local_278 = 0;
    local_4d8 = 0;
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[arg1]; local_10 = local_10 + 1) {
      local_27c = *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + arg1 * 0x5b20);
      if ((((local_27c != -1) && (((&g_CardSlot_Flags)[local_10 * 0x120 + arg1 * 0x5b20] & 2) != 0))
          && (((&g_MasterCardColorTable)[local_27c * 0x34] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_10 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
        aiStack_270[local_4d8] = local_10;
        iVar1 = Magic_QueryCardAttribute(arg1,local_10,0x32,0xffffffff);
        aiStack_4d4[local_4d8] = iVar1;
        if (local_274 < aiStack_4d4[local_4d8]) {
          local_274 = aiStack_4d4[local_4d8];
        }
        iVar1 = Magic_QueryCardAttribute(arg1,local_10,0x33,0xffffffff);
        aiStack_5a0[local_4d8] = iVar1;
        if (local_278 < aiStack_5a0[local_4d8]) {
          local_278 = aiStack_5a0[local_4d8];
        }
        uVar2 = Magic_QueryCardAttribute(arg1,local_10,0x34,0xffffffff);
        *(undefined4 *)(abStack_344 + local_4d8 * 4) = uVar2;
        aiStack_40c[local_4d8] = 0;
        local_4d8 = local_4d8 + 1;
      }
    }
    for (local_10 = 0; local_10 < local_4d8; local_10 = local_10 + 1) {
      if (aiStack_4d4[local_10] == local_274) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 3;
      }
      if (aiStack_5a0[local_10] == local_278) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 2;
      }
      if ((abStack_344[local_10 * 4] & 0x20) != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
      if ((abStack_344[local_10 * 4 + 1] & 1) != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
      while (*(int *)(abStack_344 + local_10 * 4) != 0) {
        if ((abStack_344[local_10 * 4] & 1) != 0) {
          aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
        }
        *(int *)(abStack_344 + local_10 * 4) = *(int *)(abStack_344 + local_10 * 4) >> 1;
      }
      if (((&DAT_0051aed1)
           [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + aiStack_270[local_10] * 0x120) * 0x34] &
          0x10) != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
      if (((&DAT_0051aed0)
           [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + aiStack_270[local_10] * 0x120) * 0x34] & 1
          ) != 0) {
        aiStack_40c[local_10] = aiStack_40c[local_10] + 1;
      }
    }
    for (local_10 = 0; local_10 < local_4d8; local_10 = local_10 + 1) {
      if (local_c < aiStack_40c[local_10]) {
        local_c = aiStack_40c[local_10];
        local_8 = aiStack_270[local_10];
      }
    }
  }
  else {
    local_8 = -1;
  }
  return local_8;
}



/*
 * Decompiled function: Pic_Subsystem_00442010
 * Entry Point: 00442010
 * Size: 145 bytes
 */


bool Pic_Subsystem_00442010(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x20;
  local_2c.lpfnWndProc = Pic_Load_004420a1;
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
 * Decompiled function: Pic_Load_004420a1
 * Entry Point: 004420a1
 * Size: 6620 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Load_004420a1(HWND hwnd,uint y,void *arg_3,int *height)

{
  POINT Point;
  DWORD _Seed;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  HDC *arg_3_00;
  BITMAPINFO *arg_4;
  HGDIOBJ *arg_5;
  undefined4 *arg_6;
  int *arg_7;
  int local_630;
  char local_62c [264];
  char local_524 [500];
  char local_330 [52];
  int local_2fc;
  undefined4 local_2f8;
  int local_2f4;
  int local_2f0;
  uint local_2ec;
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
  uint local_40;
  HWND local_3c;
  void *local_38;
  tagMSG local_34;
  DWORD local_18;
  int *local_14;
  BOOL local_10;
  uint local_c;
  int local_8;
  
  if (y < 0x11) {
    if (y == 0x10) {
      DAT_0067f3c4 = 1;
      g_PlayerCreatureCount = 0;
      return 0;
    }
    if (y == 1) {
      DAT_006fe484 = (HANDLE)0x0;
      iVar2 = Pic_Clip_00443b63(hwnd);
      if (iVar2 == 0) {
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
      strcpy(local_62c,&DAT_006807a0);
      strcat(local_62c,s__duel_hlp_00521b34);
      WinHelpA(g_MainAppHwnd,local_62c,2,0);
      KillTimer(hwnd,(UINT_PTR)DAT_006fdbd4);
      return 0;
    }
    if (y == 5) {
      if ((arg_3 == (void *)0x0) && (DAT_005219d4 == 0)) {
        LockWindowUpdate(hwnd);
        Pic_Subsystem_004441cc(hwnd,DAT_006fe444);
        Glue_Subsystem_004eee4e(DAT_006a4924);
        Glue_Subsystem_004eee4e(DAT_006b2e2c);
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
        for (local_630 = 0; local_630 < DAT_006a49f4; local_630 = local_630 + 1) {
          FUN_0046c1b3(local_630);
        }
        for (local_630 = 0; local_630 < DAT_00680778; local_630 = local_630 + 1) {
          FUN_004788e0((&DAT_006fefc0)[local_630 * 6],(&DAT_006fefc4)[local_630 * 6]);
        }
        DAT_00680778 = 0;
      }
      DAT_006ff554 = arg_3;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      FUN_004f3b2c(g_HdcBackBuffer,DAT_006ff384);
      arg_7 = &DAT_006b2e1c;
      arg_6 = (undefined4 *)&DAT_007006dc;
      arg_5 = &DAT_006ff384;
      arg_4 = (BITMAPINFO *)&DAT_006a4a20;
      arg_3_00 = &g_HdcBackBuffer;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      iVar2 = FUN_004f39a4(iVar3,iVar2,arg_3_00,arg_4,arg_5,arg_6,arg_7);
      if (iVar2 == 0) {
        MessageBoxA(hwnd,s_Not_enough_system_memory_to_run_a_00521b58,
                    s_Magic__The_Gathering_00521b40,0x30);
        ShowWindow(hwnd,0);
      }
      else {
        ShowWindow(hwnd,5);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      BVar4 = IsIconic(hwnd);
      if (BVar4 == 0) {
        MoveWindow(hwnd,1,0,((uint)height & 0xffff) - 1,(uint)height >> 0x10,1);
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
      uVar5 = GDI_RealizePaletteTree_Magic(hwnd,y,arg_3,height);
      return uVar5;
    }
    if (y == 0x111) {
      switch((uint)arg_3 & 0xffff) {
      case 599:
        DAT_0068a718 = (uint)(DAT_0068a718 == 0);
        if (DAT_006b2d38 == 0) {
          DAT_0068a718 = 0;
        }
        break;
      case 0x25c:
        if (DAT_0068a718 != 0) {
          DAT_00695e90 = (uint)(DAT_00695e90 == 0);
          Pic_Subsystem_0044cfe4(DAT_006fe400);
        }
        break;
      case 0x25d:
        if (DAT_0068a718 != 0) {
          FUN_0040a16e(DAT_0052eff8);
        }
        break;
      case 0x25e:
        if (DAT_0068a718 != 0) {
          Mem_AllocOrFree_0040a1a3(DAT_0052eff8);
        }
        break;
      case 0x263:
        if (DAT_0068a718 != 0) {
          g_PlayerCreatureCount = 0;
          DAT_006a4a04 = 0;
          SendMessageA(DAT_006b2530,0x432,0,0);
          SendMessageA(DAT_006ff4a8,0x432,0,0);
        }
        break;
      case 0x267:
      case 0x268:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) == 0x267);
          (&g_PlayerCreatureCount)[local_2ec] = 0;
          SendMessageA(DAT_006b2530,0x432,0,0);
          SendMessageA(DAT_006ff4a8,0x432,0,0);
        }
        break;
      case 0x269:
      case 0x26a:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x269);
          Magic_ExecuteDrawPhase(local_2ec);
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26b:
      case 0x26c:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x26b);
          local_2f0 = Palette_Subsystem_004a62a0(s_Pick_a_card_to_put_into_play_00521a60,-1,-1);
          local_2f8 = *(undefined4 *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98)
          ;
          *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) =
               *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) & 0xfffe;
          local_2f4 = Pic_Subsystem_00451291(local_2ec,local_2f0);
          if (local_2f4 != -1) {
            Pic_Subsystem_0042ac1f(local_2ec,local_2f4);
          }
          *(undefined4 *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) = local_2f8
          ;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26d:
      case 0x26e:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x26d);
          local_2f0 = Palette_Subsystem_004a62a0(s_Pick_a_card_to_put_into_hand_00521a80,-1,-1);
          local_2f4 = Pic_Subsystem_00451291(local_2ec,local_2f0);
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
        break;
      case 0x26f:
      case 0x270:
        if (DAT_0068a718 != 0) {
          local_2ec = (uint)(((uint)arg_3 & 0xffff) != 0x26f);
          uVar1 = Ai_Subsystem_004b1b38
                            (0,s_Set_player_lives_to__00521aa0 + ((local_2ec == 0) - 1 & 0x18),
                             (&g_PlayerCreatureCount)[local_2ec]);
          (&g_PlayerCreatureCount)[local_2ec] = uVar1;
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
          DAT_006808c4 = (uint)(DAT_006808c4 == 0);
          SendMessageA(DAT_006a4924,0x435,0,0);
          SendMessageA(DAT_006b2e2c,0x435,0,0);
          SendMessageA(DAT_0069e720,0x435,0,0);
          SendMessageA(DAT_006fe400,0x435,0,0);
          InvalidateRect(DAT_006fe48c,(RECT *)0x0,1);
          InvalidateRect(DAT_006ff388,(RECT *)0x0,1);
        }
        break;
      case 0x273:
        if (DAT_0068a718 != 0) {
          DAT_00695ea4 = (uint)(DAT_00695ea4 == 0);
          SendMessageA(DAT_006a4924,0x435,0,0);
          SendMessageA(DAT_006b2e2c,0x435,0,0);
          SendMessageA(DAT_0069e720,0x435,0,0);
          SendMessageA(DAT_006fe400,0x435,0,0);
          InvalidateRect(DAT_0069f744,(RECT *)0x0,0);
        }
        break;
      case 0x274:
        if (DAT_0068a718 != 0) {
          DAT_006fedc0 = 0;
        }
        break;
      case 0x275:
        if (DAT_0068a718 != 0) {
          sprintf(local_524,s__d_big_arts_are_in__max_is__d__00521ad0,DAT_00680778,0x14);
          for (local_2fc = 0; local_2fc < DAT_00680778; local_2fc = local_2fc + 1) {
            sprintf(local_330,s__3d__d___dx_d_00521af0,(&DAT_006fefc0)[local_2fc * 6],
                    (&DAT_006fefc4)[local_2fc * 6],*(undefined4 *)(&DAT_006fefb8 + local_2fc * 0x18)
                    ,*(undefined4 *)(&DAT_006fefbc + local_2fc * 0x18));
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
          ShowWindow(DAT_0064a0bc,-(uint)(BVar4 == 0) & 5);
        }
        break;
      case 0x279:
        DAT_006fe438 = (uint)(DAT_006fe438 == 0);
        SendMessageA(DAT_006a4924,0x435,0,0);
        SendMessageA(DAT_006b2e2c,0x435,0,0);
        SendMessageA(DAT_006b3064,0x435,0,0);
        SendMessageA(DAT_006fe3fc,0x435,0,0);
        break;
      case 0x27a:
        DAT_006fe43c = (uint)(DAT_006fe43c == 0);
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
        DAT_006fe440 = (uint)(DAT_006fe440 == 0);
        SendMessageA(DAT_006a4924,0x435,0,0);
        SendMessageA(DAT_006b2e2c,0x435,0,0);
        SendMessageA(DAT_006b3064,0x435,0,0);
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
      if (DAT_006fe444 == 2) {
        ShowWindow(DAT_0069f744,0);
      }
      else {
        SendMessageA(DAT_0069f744,0x401,0xffffffff,0);
      }
      SendMessageA(DAT_0069e720,0x40c,0,0);
      SendMessageA(DAT_006fe400,0x40c,0,0);
      SendMessageA(DAT_006a4924,0x40c,0,0);
      SendMessageA(DAT_006b2e2c,0x40c,0,0);
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
        *(undefined4 *)(&DAT_00695ee0 + local_c8 * 4) = 0;
        *(undefined4 *)(&DAT_0069f6e0 + local_c8 * 4) =
             *(undefined4 *)(&DAT_00695ee0 + local_c8 * 4);
      }
      SendMessageA(DAT_006b2d60,0x432,0,0);
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
      SendMessageA(DAT_006b3064,0x40c,0,0);
      DAT_006b2e28 = 0;
      g_SpellStackObjects = 0xffffffff;
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
        DAT_0052effc = 0;
        DAT_0052eff8 = 1;
      }
      else if (((byte)DAT_006fe410 & 4) == 0) {
        if (((byte)DAT_006fe410 & 1) != 0) {
          DAT_006fe490 = FUN_004f3579(DAT_0052eff8);
          DAT_006a3f60 = FUN_004f3579(DAT_0052effc);
        }
      }
      else {
        DAT_006fe490 = FUN_004f3579(DAT_0052eff8);
        DAT_006a3f60 = FUN_004f3579(DAT_0052effc);
      }
      if (((byte)DAT_006fe410 & 0x10) == 0) {
        if (((byte)DAT_006fe410 & 1) == 0) {
          if (DAT_006a49e8 == -1) {
            sprintf(local_2d4,s__s__03d_pic_00521a3c,&DAT_006a4a50,_OpponFace);
          }
          else {
            sprintf(local_2d4,s__s__03d_pic_00521a30,&DAT_006a4a50,DAT_006a49e8);
          }
          local_cc = Pic_Load_00423833(local_2d4);
          SendMessageA(DAT_006a49f0,0x439,local_cc,0);
          sprintf(local_2d4,s__s__03d_pic_00521a48,&DAT_006a4a50,_PlayerFace);
          local_cc = Pic_Load_00423833(local_2d4);
          SendMessageA(DAT_0068a620,0x439,local_cc,0);
        }
        else {
          if (DAT_006a49e8 == -1) {
            local_cc = 0;
          }
          else {
            sprintf(local_1d0,s__s__03d_pic_00521a24,&DAT_006a4a50,DAT_006a49e8);
            local_cc = Pic_Load_00423833(local_1d0);
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
      if (((byte)DAT_006fe410 & 0x10) == 0) {
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
      Pic_Load_004450c3(1,local_2dc,local_2e4);
      Pic_Load_004450c3(0,local_2e0,local_2d8);
      BVar4 = IsWindowVisible(hwnd);
      if (BVar4 == 0) {
        ShowWindow(hwnd,5);
        SetForegroundWindow(hwnd);
        UpdateWindow(hwnd);
        ShowWindow(DAT_0069e720,5);
        ShowWindow(DAT_006fe400,5);
      }
      if (((byte)DAT_006fe410 & 0x10) == 0) {
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
      if (((byte)DAT_006fe410 & 1) == 0) {
        if (((byte)DAT_006fe410 & 2) != 0) {
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
            iVar2 = MessageBoxA(hwnd,local_c0,s_End_of_duel_00521a18,4);
            if (iVar2 == 6) {
              local_5c = 0;
              SendMessageA(hwnd,0x400,0,0);
            }
          }
        }
      }
      else if (DAT_006fe434 != 0) {
        Ai_Subsystem_004ae779((int)local_58);
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
      local_14 = height;
      DAT_006b1578 = 1;
      memcpy(&DAT_006feec0,arg_3,0xe8);
      GetCursorPos(&local_48);
      Point.y = local_48.y;
      Point.x = local_48.x;
      local_3c = WindowFromPoint(Point);
      local_40 = SendMessageA(local_3c,0x84,0,local_48.y << 0x10 | local_48.x & 0xffffU);
      SendMessageA(local_3c,0x20,(WPARAM)local_3c,local_40 & 0xffff | 0x2000000);
      FUN_00409b2c(1,*(int *)((int)local_38 + 0xe0));
      FUN_00409b2c(0,*(int *)((int)local_38 + 0xe4));
      FUN_00477d73(DAT_007006b0,(char *)((int)local_38 + 0x18),*(uint *)((int)local_38 + 0x14));
      Ai_Subsystem_004b74b1(&local_4c,&local_50);
      if (((local_50 == 0x15) && (local_4c == 1)) && (iVar2 = Ai_Subsystem_004b75a4(), iVar2 != 0))
      {
        DAT_0069f6d0 = 1;
      }
      local_8 = 0;
      while (local_8 == 0) {
        GetExitCodeThread(DAT_006fe484,&local_18);
        if (local_18 != 0x103) {
          local_8 = 1;
        }
        local_10 = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
        if (DAT_0067f3c4 != 0) {
          if ((local_10 != 0) && (local_34.message == 0x464)) {
            local_10 = 0;
          }
          local_8 = 1;
          *local_14 = -5;
          local_14[1] = -1;
          local_14[2] = -1;
          if (*local_14 == 0) {
            local_c = 1;
          }
          else {
            local_c = 0;
          }
        }
        if (local_10 != 0) {
          if (local_34.message == 0x464) {
            local_54 = (int *)local_34.lParam;
            local_8 = 1;
            local_c = (uint)(*(int *)local_34.lParam == 0);
            memcpy(local_14,(void *)local_34.lParam,0x10);
          }
          else if (local_34.message == 0x12) {
            PostQuitMessage(local_34.wParam);
            local_8 = 1;
            local_c = 0;
            *local_14 = -2;
          }
          else {
            Palette_Subsystem_00495cde(&local_34);
          }
        }
      }
      FUN_00477d73(DAT_007006b0,(char *)0x0,0);
      FUN_00409b2c(1,0);
      FUN_00409b2c(0,0);
      UpdateWindow(g_MainAppHwnd);
      DAT_006b1578 = 0;
      SetTimer(hwnd,(UINT_PTR)DAT_006fdbd4,45000,(TIMERPROC)0x0);
      return local_c;
    }
  }
  else {
    if (y == 0x464) {
      Ai_EvalAttackCandidate_004b4a3f(0,(uint)arg_3);
      return 0;
    }
    if (y == 0x501) {
      DAT_005219d0 = 0;
      BVar4 = 1;
      iVar2 = GetSystemMetrics(1);
      iVar3 = GetSystemMetrics(0);
      MoveWindow(hwnd,1,0,iVar3 + -1,iVar2,BVar4);
      return 0;
    }
  }
  uVar5 = DefWindowProcA(hwnd,y,(WPARAM)arg_3,(LPARAM)height);
  return uVar5;
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


undefined4 Pic_Clip_00443b63(HWND hwnd)

{
  undefined4 uVar1;
  tagRECT local_14;
  
  GetClientRect(hwnd,&local_14);
  DAT_006b1570 = CreateWindowExA(0,s_MAGIC_CueCardClass_00521bf4,&DAT_00521bf0,0x80000000,0,0,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_00695ea0 = CreateWindowExA(0,s_MAGIC_PlayerDirectiveClass_00521c0c,&DAT_00521c08,0x80000000,0,
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
  DAT_006b2d60 = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00521df0,s_Player_Mana_00521de4,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x69,g_AppHInstance,(LPVOID)0x0);
  DAT_006a49f0 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00521e18,s_Oppon_Face_00521e0c,0x40000000,0
                                 ,0,0,0,hwnd,(HMENU)0x7c,g_AppHInstance,(LPVOID)0x0);
  DAT_0068a620 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00521e38,s_Player_Face_00521e2c,0x40000000,
                                 0,0,0,0,hwnd,(HMENU)0x7b,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4b60 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00521e58,s_Oppon_Chat_00521e4c,0x80800000,0
                                 ,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006b1574 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00521e78,s_Player_Chat_00521e6c,0x80800000,
                                 0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4924 = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00521ea0,s_Player_Territory_00521e8c,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x79,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2e2c = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00521ecc,s_Oppon_Territory_00521ebc,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x7a,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe400 = CreateWindowExA(0,s_MAGICGAME_HandClass_00521ef8,s_Opponent_Hand_00521ee8,
                                 0x82000000,(local_14.right * 0x50) / 100,
                                 (local_14.bottom * 0x28) / 100,0,0,hwnd,(HMENU)0x0,g_AppHInstance,
                                 (LPVOID)0x0);
  DAT_0069e720 = CreateWindowExA(0,s_MAGICGAME_HandClass_00521f18,s_Player_Hand_00521f0c,0x82000000,
                                 (local_14.right * 0x50) / 100,(local_14.bottom * 0x3c) / 100,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006b3064 = CreateWindowExA(0,s_MAGICGAME_AttackClass_00521f34,s_Attack_00521f2c,0x82c00000,0,0
                                 ,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe3fc = CreateWindowExA(0,s_MAGICGAME_SpellChainClass_00521f58,s_Spell_Chain_00521f4c,
                                 0x80c00000,0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  if ((((((DAT_00695ea0 == (HWND)0x0) || (DAT_0069f744 == (HWND)0x0)) || (DAT_006ff4a8 == (HWND)0x0)
        ) || (((DAT_006b2530 == (HWND)0x0 || (DAT_006ff560 == (HWND)0x0)) ||
              ((DAT_006b2d60 == (HWND)0x0 ||
               ((DAT_006a4928 == (HWND)0x0 || (DAT_006ff388 == (HWND)0x0)))))))) ||
      ((DAT_006b2e10 == (HWND)0x0 ||
       ((((((DAT_006fe48c == (HWND)0x0 || (DAT_006a4b60 == (HWND)0x0)) ||
           (DAT_006b1574 == (HWND)0x0)) ||
          ((DAT_006a284c == (HWND)0x0 || (DAT_006a283c == (HWND)0x0)))) ||
         ((DAT_006b3064 == (HWND)0x0 || ((DAT_006fe3fc == (HWND)0x0 || (DAT_006a4924 == (HWND)0x0)))
          ))) || (DAT_006b2e2c == (HWND)0x0)))))) ||
     ((((DAT_007006b0 == (HWND)0x0 || (DAT_006a49f0 == (HWND)0x0)) || (DAT_0068a620 == (HWND)0x0))
      || ((DAT_006fe400 == (HWND)0x0 || (DAT_0069e720 == (HWND)0x0)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004441cc
 * Entry Point: 004441cc
 * Size: 3831 bytes
 */


void Pic_Subsystem_004441cc(HWND hwnd,int arg2)

{
  char local_350 [200];
  uint local_288;
  CHAR local_284 [100];
  char local_220 [200];
  uint local_158;
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
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  GetClientRect(hwnd,&local_2c);
  DAT_006a28b0 = (int)(local_2c.right + (local_2c.right >> 0x1f & 7U)) >> 3;
  DAT_006ff67c = (DAT_006a28b0 * 0x21) / 0x118;
  DAT_006b2e30 = DAT_006a28b0;
  if (arg2 == 1) {
    GetWindowTextA(DAT_00695ea0,local_154,100);
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
    local_c = local_2c.left;
    local_70 = local_2c.top;
    local_e4 = local_cc + local_80;
    local_9c = local_58 - local_2c.top;
    local_1c = local_2c.bottom - local_e4;
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
    local_18 = local_cc;
    local_14 = local_54;
    local_10 = local_d8;
    local_8 = local_dc;
    ShowWindow(DAT_0069f744,5);
    MoveWindow(DAT_006ff4a8,local_c,local_70,local_64,local_9c,1);
    MoveWindow(DAT_006b2530,local_90,local_e4,local_64,local_1c,1);
    MoveWindow(DAT_006ff560,local_d4,local_d0,local_c4,local_34,1);
    MoveWindow(DAT_006b2d60,local_60,local_5c,local_c4,local_b0,1);
    MoveWindow(DAT_006ff388,local_ac,local_58,local_7c,local_18,1);
    MoveWindow(DAT_006fe48c,local_f0,local_80,local_7c,local_18,1);
    MoveWindow(DAT_006a4928,local_14,local_50,local_e0,local_cc,1);
    MoveWindow(DAT_006b2e10,local_54,local_6c,local_e0,local_cc,1);
    local_b8.x = local_8c;
    local_b8.y = local_88;
    ClientToScreen(hwnd,&local_b8);
    MoveWindow(DAT_0069f744,local_b8.x,local_b8.y,local_44,local_ec,1);
    MoveWindow(DAT_006b2e2c,local_8,local_84,local_10,local_3c,1);
    SendMessageA(DAT_006b2e2c,0x412,0,0);
    MoveWindow(DAT_006a4924,local_40,local_c0,local_10,local_38,1);
    SendMessageA(DAT_006a4924,0x412,0,0);
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
    MoveWindow(DAT_006a49f0,local_c,local_70,local_c4 + local_64,local_34,1);
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
    GetWindowTextA(DAT_00695ea0,local_284,100);
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
    local_c = local_2c.left;
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
    local_1c = local_9c;
    local_18 = local_cc;
    local_14 = local_54;
    local_10 = local_d8;
    local_8 = local_dc;
    ShowWindow(DAT_0069f744,0);
    MoveWindow(DAT_006ff4a8,local_c,local_70,local_64,local_9c,1);
    MoveWindow(DAT_006b2530,local_90,local_e4,local_64,local_1c,1);
    MoveWindow(DAT_006ff560,local_d4,local_d0,local_c4,local_34,1);
    MoveWindow(DAT_006b2d60,local_60,local_5c,local_c4,local_b0,1);
    MoveWindow(DAT_006ff388,local_ac,local_58,local_7c,local_18,1);
    MoveWindow(DAT_006fe48c,local_f0,local_80,local_7c,local_18,1);
    MoveWindow(DAT_006a4928,local_14,local_50,local_e0,local_cc,1);
    MoveWindow(DAT_006b2e10,local_54,local_6c,local_e0,local_cc,1);
    MoveWindow(DAT_0069f744,local_8c,local_88,local_44,local_ec,1);
    MoveWindow(DAT_006b2e2c,local_8,local_84,local_10,local_3c,1);
    SendMessageA(DAT_006b2e2c,0x412,0,0);
    MoveWindow(DAT_006a4924,local_40,local_c0,local_10,local_38,1);
    SendMessageA(DAT_006a4924,0x412,0,0);
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
    MoveWindow(DAT_006a49f0,local_c,local_70,local_64,local_9c,1);
    MoveWindow(DAT_0068a620,local_90,local_e4,local_64,local_1c,1);
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
  Pic_Subsystem_0044cfe4(DAT_0069e720);
  Pic_Subsystem_0044cfe4(DAT_006fe400);
  Glue_Subsystem_004eed47(DAT_006a4924);
  Glue_Subsystem_004eed47(DAT_006b2e2c);
  FUN_00481586(DAT_006b3064);
  Glue_Subsystem_004cffda(DAT_006fe3fc,(LPRECT)0x0);
  UpdateWindow(DAT_0069f744);
  UpdateWindow(hwnd);
  return;
}



/*
 * Decompiled function: Pic_Load_004450c3
 * Entry Point: 004450c3
 * Size: 1243 bytes
 */


void Pic_Load_004450c3(int player,int card_slot,int arg_3)

{
  HWND local_17c;
  HWND local_178;
  HWND local_174;
  HWND local_170;
  char local_16c [264];
  HANDLE local_64;
  char local_60 [52];
  undefined1 local_2c [8];
  int local_24;
  int local_14 [4];
  
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
  sprintf(local_16c,s__s__s_pic_00521fc8,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
  if (player == 0) {
    local_170 = DAT_006a4924;
  }
  else {
    local_170 = DAT_006b2e2c;
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
  sprintf(local_16c,s__s__s_pic_00522028,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
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
  sprintf(local_16c,s__s__s_pic_00522070,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
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
  sprintf(local_16c,s__s__s_pic_005220b8,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
  GetObjectA(local_64,0x18,local_2c);
  local_14[1] = 0xb;
  local_14[0] = local_24 + -0xb;
  local_14[2] = 7;
  local_14[3] = 4;
  if (player == 0) {
    local_17c = DAT_0069e720;
  }
  else {
    local_17c = DAT_006fe400;
  }
  SendMessageA(local_17c,0x439,(WPARAM)local_64,(LPARAM)local_14);
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
    DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf9,g_MainAppHwnd,Pic_Subsystem_004455e3,0);
    DAT_006ff1a8 = 0;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004455e3
 * Entry Point: 004455e3
 * Size: 704 bytes
 */


undefined4 Pic_Subsystem_004455e3(HWND hwnd,uint y,HDC hdc,undefined4 arg_4)

{
  undefined4 uVar1;
  HBRUSH hbr;
  HGDIOBJ h;
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_30;
  undefined4 local_20;
  undefined4 local_1c;
  HWND local_18;
  tagRECT local_14;
  
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
      local_20 = 1;
      local_1c = 0xffffffff;
      GetClientRect(hwnd,&local_14);
      local_18 = CreateWindowExA(0,s_MAGICGAME_CardClass_005220e0,
                                 s_StillThinking_small_card_005220c4,0x50000000,
                                 (local_14.right - DAT_006a28b0) / 2,
                                 (local_14.bottom - DAT_006b2e30) + -10,DAT_006a28b0,DAT_006b2e30,
                                 hwnd,(HMENU)0x1,g_AppHInstance,&local_20);
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
      uVar1 = GDI_RealizePaletteTree_Magic(hwnd,y,(HWND)hdc,arg_4);
      return uVar1;
    }
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_004458b0
 * Entry Point: 004458b0
 * Size: 4135 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Subsystem_004458b0(int arg1,char *str_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_84;
  int local_7c;
  int local_78;
  byte local_74;
  int local_70;
  char local_68 [64];
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase] < 1) {
    *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) =
         *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) | 2;
  }
  local_18 = 0;
  if (((g_IsAiThinking != 1) && (g_TurnPlayer == DAT_00627a84)) &&
     (DAT_00627a88 == g_ScWillyScore)) {
    DAT_0063ee1c = 0;
  }
  if (arg1 == 1) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_00505d20(g_ScWillyScore);
  }
  strcpy(local_68,str_2);
  uVar3 = g_DuelModeFlags;
  uVar2 = DAT_0063edc0;
  local_14 = arg1;
  DAT_0063edc0 = arg1;
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
  if ((g_ActivePlayerPriority == arg1) && (g_SpellStackObjects == g_CurrentTurnPhase)) {
    _DAT_00538bb4 = 0xf;
    _DAT_00538bb8 = 0xfffffff0;
  }
  if (((((g_IsAiThinking == 1) || (DAT_00633434 != 0)) ||
       ((g_CurrentStepCode != -1 && (g_ActivePlayerPriority == DAT_006a4b5c)))) ||
      (DAT_00695ec4 == 4)) ||
     ((g_ActivePlayerPriority == arg1 && ((g_DuelModeFlags & 0x200) != 0)))) {
    local_84 = Pic_Subsystem_004468dc(arg1);
    local_14 = _DAT_0063ee20;
  }
  else {
    local_84 = -1;
  }
  local_20 = 0;
  if ((local_84 != -1) &&
     (iVar4 = Magic_BroadcastCardEventInStep(local_14,local_84,0x7d,local_24), iVar4 == 2)) {
    FUN_00471aba(local_14,local_84,local_24);
    local_84 = -1;
    Ai_Subsystem_004cc9c5(0,0xff);
  }
  if (local_84 != -1) {
    _DAT_0063ee84 = *(int *)(&g_CardSlot_CardId + local_84 * 0x120 + local_14 * 0x5b20);
    local_1c = _DAT_0063ee84;
    if (((&g_CardSlot_Flags)[local_84 * 0x120 + local_14 * 0x5b20] & 2) == 0) {
      iVar4 = FUN_0046fe86(local_14,local_84);
      if (iVar4 != 0) {
        if ((&g_MasterCardColorTable)[local_1c * 0x34] == ' ') {
          DAT_0063edc8 = DAT_0063ee70 & 0x20;
        }
        local_20 = 1;
        Ai_Subsystem_004cc9c5(0,0xff);
        if ((g_IsAiThinking != 1) && (iVar4 = Math_RandomRange(3), iVar4 == 0)) {
          Pic_Subsystem_0045275a(s_Didn_t_expect_that__did_ya__00522120);
        }
      }
    }
    else {
      if (((*(int *)(&DAT_006a5f80 + local_84 * 0x120 + local_14 * 0x5b20) == g_CurrentStepCode) &&
          (DAT_00695f18 != (code *)0x0)) && (g_CurrentStepCode != -1)) {
        if (DAT_00695f18 != (code *)0x0) {
          (*DAT_00695f18)(local_14,local_84);
        }
      }
      else {
        Magic_TriggerCardEvent(local_14,local_84,0x73,1 - local_14,0xffffffff);
        iVar4 = FUN_0047103b(local_14,local_84);
        if (iVar4 != 0) {
          FUN_00471971(local_14,local_84);
        }
        g_ActivePlayer = 0;
      }
      local_20 = 1;
      Ai_Subsystem_004cc9c5(0,0xff);
    }
  }
  local_28 = 0;
  local_8 = 0;
  local_7c = -1;
  if ((g_IsAiThinking != 1) || ((g_CurrentStepCode != -1 && (g_CurrentTurnPhase == DAT_006a4b5c)))) {
    if ((g_CurrentTurnPhase == DAT_006a4b5c) && (g_CurrentStepCode != -1)) {
      for (local_24 = 0; local_24 < 2; local_24 = local_24 + 1) {
        for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[local_24];
            local_70 = local_70 + 1) {
          if ((((&g_CardSlot_Flags)[local_70 * 0x120 + local_24 * 0x5b20] & 2) != 0) &&
             (iVar4 = Magic_BroadcastCardEventInStep(local_24,local_70,0x7d,arg1), iVar4 != 0)) {
            if (iVar4 == 2) {
              local_7c = local_70;
              local_c = local_24;
              local_14 = local_24;
              local_8 = local_8 + 1;
            }
            else {
              local_74 = (byte)iVar4;
              local_28 = local_28 | 1 << (local_74 & 0x1f);
            }
          }
          if (((((DAT_0068a67c & 1) != 0) &&
               (*(int *)(&DAT_006a5f80 + local_70 * 0x120 + local_24 * 0x5b20) == g_CurrentStepCode))
              && (local_24 == DAT_006a4b5c)) && (g_CurrentStepCode != -1)) {
            local_28 = local_28 | 4;
            local_7c = local_70;
            local_c = local_24;
            local_14 = local_24;
            local_8 = local_8 + 1;
          }
        }
      }
    }
    if (local_7c == -1) {
      if (g_IsAiThinking == 1) goto LAB_00446898;
      if ((g_CurrentStepCode == 0xca) && (*(int *)(&DAT_00696750 + g_TurnPlayer * 0x98) == 0)) {
        DAT_0068a67c = 0;
      }
      if ((g_CurrentStepCode == 0xce) && (*(int *)(&DAT_00696768 + g_TurnPlayer * 0x98) == 0)) {
        DAT_0068a67c = 0;
      }
    }
    if (((local_7c != -1) || (local_28 != 0)) || (((DAT_0068a67c & 1) != 0 && (DAT_0063ee70 != 0))))
    {
      DAT_006a4920 = 0;
      DAT_0068a67c = 0;
      local_78 = 0;
      for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
          local_70 = local_70 + 1) {
        if (((*(int *)(&g_CardSlot_CardId + local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1)
            && (((((&g_CardSlot_SpecialState)[local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 1)
                  != 0 || (((&g_CardSlot_SpecialState)
                            [local_70 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) != 0)) ||
                ((iVar4 = Magic_IsManaSource(g_CurrentTurnPhase,local_70), iVar4 == 0 &&
                 (g_CurrentTurnPhase == DAT_0063edc0)))))) &&
           (((uVar5 = Pic_Subsystem_00446d52(g_CurrentTurnPhase,local_70), 1 < (int)uVar5 ||
             ((((DAT_006808b0 != 0 || (g_TurnPlayer != g_CurrentTurnPhase)) &&
               ((uVar5 & 2) != 0)) || ((DAT_006a4920 & 2) != 0)))) &&
            (((g_CurrentTurnPhase != DAT_006a4b5c || (g_CurrentStepCode == -1)) ||
             ((uVar5 != 2 || ((DAT_006a4920 & 2) != 0)))))))) {
          if (((DAT_006a4920 & 2) == 0) && (uVar5 != 2)) {
            if (uVar5 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
          }
          else {
            local_7c = local_70;
            local_c = g_CurrentTurnPhase;
            local_8 = local_8 + 1;
          }
          DAT_006a4920 = DAT_006a4920 & 0xfffffffd;
        }
      }
      if (DAT_00695ec4 == 4) {
        for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[1 - g_CurrentTurnPhase];
            local_70 = local_70 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20)
                != -1) &&
              (((((&g_CardSlot_SpecialState)[local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20] &
                 1) != 0 ||
                (((&g_CardSlot_SpecialState)[local_70 * 0x120 + (1 - g_CurrentTurnPhase) * 0x5b20] &
                 0x10) != 0)) ||
               (iVar4 = Magic_IsManaSource(1 - g_CurrentTurnPhase,local_70), iVar4 == 0)))) &&
             (iVar4 = Pic_Subsystem_00446d52(1 - g_CurrentTurnPhase,local_70),
             (DAT_006a4920 & 2) != 0)) {
            local_7c = local_70;
            local_c = 1 - g_CurrentTurnPhase;
            local_8 = local_8 + 1;
            DAT_006a4920 = DAT_006a4920 & 0xfffffffd;
            if (iVar4 == 2) {
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
        local_18 = 1;
      }
    }
  }
  if (((local_18 != 0) || (local_10 != 0)) || (local_8 != 0)) {
    strcpy(&g_OverworldWorldState,s_Triggered_effects_____0052213c);
    if (((DAT_0063edc8 & 0x10) == 0) || (DAT_006b2d3c != -1)) {
      if ((DAT_0063edc8 & 0x20) != 0) {
        strcpy(&g_OverworldWorldState,s_Interrupts_____00522168);
      }
    }
    else {
      strcpy(&g_OverworldWorldState,s_Fast_Effects_____00522154);
    }
    if (g_CurrentStepCode != -1) {
      strcpy(&g_OverworldWorldState,s_Triggered_effects_____00522178);
    }
    strcat(&g_OverworldWorldState,local_68);
    if ((DAT_0063ee1c == 0) || ((local_28 & 2) != 0)) {
      if (((((local_10 == 0) && ((DAT_006808b0 == 0 || (g_CurrentStepCode != -1)))) &&
           ((local_18 == 0 || (g_CurrentStepCode == -1)))) &&
          ((DAT_00525850 == 0 || ((local_28 & 6) == 0)))) &&
         (((local_8 <= (int)(uint)((local_28 & 2) == 0) && ((local_28 & 4) == 0)) ||
          ((((local_78 == 0 && (iVar4 = FUN_00505c74(), iVar4 != 0)) || (g_CurrentStepCode == 0xd6))
           || ((local_7c != -1 && (DAT_00627a10 == DAT_0063edc4)))))))) {
        local_84 = local_7c;
        local_14 = local_c;
        _DAT_0063eed8 = 1;
      }
      else {
        DAT_007006d0 = 1;
        DAT_00627a84 = -1;
        DAT_0063edc4 = 0;
        bVar1 = false;
        while (!bVar1) {
          if (g_IsAiThinking == 1) {
            local_84 = local_7c;
            bVar1 = true;
            DAT_0063ee8c = -1;
          }
          else {
            local_84 = Glue_Subsystem_004efd50
                                 (g_CurrentTurnPhase,-1,g_CurrentTurnPhase,0xff,0,
                                  &g_OverworldWorldState,2);
            local_14 = _DAT_0063ee20;
            if (-1 < local_84) {
              *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) =
                   *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) | 2;
            }
          }
          if (DAT_0063ee8c == -3) {
            bVar1 = false;
          }
          else if (DAT_0063ee8c == -2) {
            bVar1 = true;
            local_84 = -1;
            DAT_00695f0c = DAT_00695f0c & 0xfffffffd;
            if (g_CurrentStepCode != -1) {
              DAT_00627a84 = g_TurnPlayer;
              DAT_00627a88 = g_ScWillyScore;
              DAT_0063ee8c = 0;
            }
            if (local_8 != 0) {
              DAT_0063edc4 = DAT_00627a10;
              DAT_0063ee1c = 1;
              _DAT_0063eed8 = 1;
              DAT_00627a88 = -1;
              DAT_00627a84 = -1;
            }
          }
          else if (DAT_0063ee8c == 0) {
            if ((local_14 == -1) || (local_84 == -1)) {
              if ((local_14 != -1) && (local_84 == -1)) {
                bVar1 = false;
              }
            }
            else {
              bVar1 = true;
            }
          }
        }
      }
    }
    else {
      local_84 = local_7c;
      local_14 = local_c;
      if (local_7c != -1) {
        _DAT_0063eed8 = 1;
      }
    }
    g_OverworldWorldState = 0;
    if ((local_84 != -1) &&
       ((g_CurrentTurnPhase == local_14 ||
        (((((&g_CardSlot_Flags)[local_84 * 0x120 + local_14 * 0x5b20] & 2) != 0 &&
          (iVar4 = Magic_BroadcastCardEventInStep(local_14,local_84,0x7d,g_CurrentTurnPhase), iVar4 != 0))
         || (DAT_00695ec4 == 4)))))) {
      local_1c = *(int *)(&g_CardSlot_CardId + local_84 * 0x120 + local_14 * 0x5b20);
      iVar4 = Pic_Subsystem_00446d52(local_14,local_84);
      if (iVar4 == 0) {
        iVar4 = FUN_005063f6(local_14,local_84);
        if (iVar4 != 0) {
          FUN_005064e9(local_14,local_84);
        }
      }
      else {
        if (((&g_CardSlot_Flags)[local_84 * 0x120 + local_14 * 0x5b20] & 2) == 0) {
          FUN_0046fe86(local_14,local_84);
          if ((&g_MasterCardColorTable)[local_1c * 0x34] == ' ') {
            DAT_0063edc8 = DAT_0063ee70 & 0x20;
          }
          iVar4 = Math_RandomRange(3);
          if (iVar4 == 0) {
            Pic_Subsystem_0045275a(s_I_knew_that_was_coming__00522190);
          }
        }
        else {
          iVar4 = Magic_BroadcastCardEventInStep(local_14,local_84,0x7d,g_CurrentTurnPhase);
          if (iVar4 == 0) {
            if (((*(int *)(&DAT_006a5f80 + local_84 * 0x120 + local_14 * 0x5b20) == g_CurrentStepCode
                 ) && (DAT_00695f18 != (code *)0x0)) && (g_CurrentStepCode != -1)) {
              if (DAT_00695f18 != (code *)0x0) {
                (*DAT_00695f18)(local_14,local_84);
              }
            }
            else {
              iVar4 = FUN_0047103b(local_14,local_84);
              if (((iVar4 != 0) && (FUN_00471971(local_14,local_84), g_ActivePlayer != 1)) &&
                 (g_IsAiThinking != 1)) {
                Duel_PlaySoundById(0x1c);
              }
              g_ActivePlayer = 0;
            }
          }
          else {
            FUN_00471aba(local_14,local_84,g_CurrentTurnPhase);
          }
        }
        Ai_Subsystem_004cc9c5(0,0xff);
        local_20 = local_20 | 2;
      }
      local_20 = local_20 | 2;
    }
    DAT_0068a67c = 1;
    _DAT_0063eed8 = 0;
  }
LAB_00446898:
  if (local_20 == 0) {
    DAT_0063edc8 = DAT_0063ee70 & 0x30;
  }
  DAT_0063ee10 = 0;
  DAT_0063edc0 = uVar2;
  g_DuelModeFlags = uVar3;
  DAT_00627a10 = DAT_00627a10 + -1;
  return local_20;
}



/*
 * Decompiled function: Pic_Subsystem_004468dc
 * Entry Point: 004468dc
 * Size: 1142 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Subsystem_004468dc(int player)

{
  int iVar1;
  uint uVar2;
  uint auStack_68 [20];
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if ((g_CurrentStepCode != -1) && (g_ActivePlayerPriority == DAT_006a4b5c)) {
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      for (local_14 = 0; (int)local_14 < (int)(&g_PlayerActiveCardCount)[local_10];
          local_14 = local_14 + 1) {
        if ((((&g_CardSlot_Flags)[local_14 * 0x120 + local_10 * 0x5b20] & 2) != 0) &&
           (iVar1 = Magic_BroadcastCardEventInStep(local_10,local_14,0x7d,player), iVar1 == 2)) {
          _DAT_0063ee20 = local_10;
          DAT_00695f0c = 4;
          return local_14;
        }
        if ((((local_10 == player) &&
             (*(int *)(&DAT_006a5f80 + local_14 * 0x120 + local_10 * 0x5b20) == g_CurrentStepCode))
            && (local_10 == DAT_006a4b5c)) && (g_CurrentStepCode != -1)) {
          DAT_00695f0c = DAT_00695f0c | 4;
          DAT_0068a714 = DAT_0068a714 + 1;
          _DAT_0063ee20 = local_10;
          return local_14;
        }
      }
    }
  }
  if (((((byte)DAT_0068a67c & 2) == 0) || (g_CurrentTurnPhase == player)) || (DAT_0063ee70 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    _DAT_0063ee20 = player;
    for (local_14 = 0; (int)local_14 < (int)(&g_PlayerActiveCardCount)[player];
        local_14 = local_14 + 1) {
      local_c = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + player * 0x5b20);
      if ((local_c != -1) && (local_18 = Pic_Subsystem_00446d52(player,local_14), local_18 != 0)) {
        auStack_68[local_8] = local_14;
        local_8 = local_8 + 1;
        if (local_18 == 2) {
          return local_14;
        }
      }
    }
    if (DAT_00695ec4 == 4) {
      for (local_14 = 0; (int)local_14 < (int)(&g_PlayerActiveCardCount)[1 - player];
          local_14 = local_14 + 1) {
        local_c = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + (1 - player) * 0x5b20);
        if (((local_c != -1) &&
            (local_18 = Pic_Subsystem_00446d52(1 - player,local_14), local_18 != 0)) &&
           (local_18 == 2)) {
          _DAT_0063ee20 = 1 - player;
          return local_14;
        }
      }
    }
    if (DAT_00695ec4 == 4) {
      uVar2 = 0xffffffff;
    }
    else {
      auStack_68[local_8] = 0xffffffff;
      local_8 = local_8 + 1;
      if (g_IsAiThinking == 1) {
        iVar1 = Math_RandomRange(2);
        if ((iVar1 == 0) || (iVar1 = Ai_Util_004ab510(), iVar1 == 0)) {
          g_AiDecisionScore = Math_RandomRange(local_8);
        }
        else {
          g_AiDecisionScore = local_8 + -1;
        }
        if ((DAT_006a2838 != 0) && (g_AiDecisionScore = local_8 + -1, DAT_006a2838 == 1)) {
          DAT_006a2838 = -1;
        }
        DAT_006fefa8 = (-(uint)((*(uint *)(&g_CardSlot_Flags +
                                          player * 0x5b20 + auStack_68[g_AiDecisionScore] * 0x120) &
                                2) == 0) & 0xfffff000) + 0x2000 | auStack_68[g_AiDecisionScore] |
                       (player == 0) - 1 & 0x100;
        DAT_0052ce1c = 4;
        Ai_EvaluateCreaturePower();
      }
      else {
        DAT_0052ce1c = 4;
        Ai_CalcCardAdvantage();
        if (local_8 <= g_AiDecisionScore) {
          g_AiDecisionScore = local_8 + -1;
        }
      }
      if (auStack_68[g_AiDecisionScore] != 0xffffffff) {
        if (0xf < DAT_006a2844) {
          DAT_006a2844 = DAT_006a2844 + -1;
        }
        *(undefined4 *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
             *(undefined4 *)
              (&g_CardSlot_CardId + player * 0x5b20 + auStack_68[g_AiDecisionScore] * 0x120);
        *(uint *)(&DAT_006966f0 + DAT_006a2844 * 4) = auStack_68[g_AiDecisionScore];
        DAT_006a2844 = DAT_006a2844 + 1;
      }
      uVar2 = auStack_68[g_AiDecisionScore];
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_00446d52
 * Entry Point: 00446d52
 * Size: 1260 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_00446d52(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  byte local_c;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
    if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
      return 0;
    }
    if ((g_CurrentStepCode != -1) &&
       (*(code **)(&DAT_0051aec8 + iVar1 * 0x34) != Prompts_Load_00416f1a)) {
      return 0;
    }
    if ((DAT_00525778 != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x20) == 0)) {
      return 0;
    }
    if (((((DAT_0063edc8 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0) &&
         (iVar2 = FUN_00470ea3(arg1,arg1,arg2), iVar2 != 0)) &&
        ((((byte)g_DuelModeFlags & 4) == 0 ||
         ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x3004) != 0)))) &&
       (((g_CurrentTurnPhase == arg1 ||
         ((_DAT_00538bb4 & (int)(char)(&DAT_0051aed5)[iVar1 * 0x34]) != 0)) &&
        (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x74,1 - arg1,0xffffffff), iVar1 != 0)))) {
      return 3;
    }
  }
  else {
    if ((*(int *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) == g_CurrentStepCode) &&
       (g_CurrentStepCode != -1)) {
      if (arg1 == DAT_006a4b5c) {
        DAT_00695f0c = DAT_00695f0c | 4;
        DAT_0068a714 = DAT_0068a714 + 1;
        return 2;
      }
      return 0;
    }
    if (g_CurrentStepCode != -1) {
      iVar1 = Magic_BroadcastCardEventInStep(arg1,arg2,0x7d,arg1);
      if (iVar1 == 0) {
        return 0;
      }
      local_c = (byte)iVar1;
      DAT_00695f0c = DAT_00695f0c | 1 << (local_c & 0x1f);
      DAT_0068a714 = DAT_0068a714 + 1;
      if (1 < iVar1) {
        return 2;
      }
      return 3;
    }
    if ((((((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0) &&
         (((&DAT_0051aed0)[iVar1 * 0x34] & 1) != 0)) && ((DAT_0063edc8 & 0x10) != 0)) ||
       ((((&DAT_0051aed0)[iVar1 * 0x34] & 2) != 0 && ((DAT_0063edc8 & 0x20) != 0)))) {
      if ((DAT_00525778 != 0) && (((&DAT_0051aed0)[iVar1 * 0x34] & 2) == 0)) {
        return 0;
      }
      if (((((byte)g_DuelModeFlags & 4) == 0) ||
          ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x5004) != 0)) &&
         (((DAT_006a4920 = DAT_006a4920 & 0xfffffffd, g_CurrentTurnPhase == arg1 ||
           ((_DAT_00538bb8 & (int)(char)(&DAT_0051aed5)[iVar1 * 0x34]) != 0)) &&
          ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0 &&
           (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x73,1 - arg1,0xffffffff), iVar1 != 0)))))) {
        if ((DAT_006a4920 & 2) != 0) {
          DAT_00695f0c = DAT_00695f0c | 4;
          return 2;
        }
        DAT_00695f0c = DAT_00695f0c | 2;
        return 3;
      }
    }
    if ((DAT_00695ec4 == 4) && (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)
       ) {
      DAT_006a4920 = DAT_006a4920 | 3;
      DAT_00695f0c = DAT_00695f0c | 4;
      return 2;
    }
    if ((((DAT_00695ec4 == 4) && (arg1 == DAT_0063edc0)) &&
        (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
       ((((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0 &&
        (iVar1 = FUN_00476675(arg1,arg2), iVar1 != 0)))) {
      DAT_00695f0c = DAT_00695f0c | 2;
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


undefined4 Pic_Subsystem_0044724d(void)

{
  undefined4 uVar1;
  
  if (DAT_00695ec4 == 0x8e) {
    if (DAT_006a5f20 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (((((DAT_00695ec4 == 0x6a) || (DAT_00695ec4 == 0x6b)) || (DAT_00695ec4 == 0x6c)) ||
           ((((DAT_00695ec4 == 0x6d || (DAT_00695ec4 == 0x6e)) ||
             ((DAT_00695ec4 == 0x6f || ((DAT_00695ec4 == 0x70 || (DAT_00695ec4 == 0x71)))))) ||
            ((DAT_00695ec4 == 0x72 ||
             ((((DAT_00695ec4 == 0x73 || (DAT_00695ec4 == 0x74)) || (DAT_00695ec4 == 0x75)) ||
              ((DAT_00695ec4 == 0x76 || (DAT_00695ec4 == 0x77)))))))))) ||
          (((DAT_00695ec4 == 0x78 || ((DAT_00695ec4 == 0x79 || (DAT_00695ec4 == 0x7a)))) ||
           (((DAT_00695ec4 == 0x7b ||
             ((((DAT_00695ec4 == 0x7c || (DAT_00695ec4 == 0x7d)) || (DAT_00695ec4 == 0x7e)) ||
              (((DAT_00695ec4 == 0x7f || (DAT_00695ec4 == 0x80)) ||
               ((DAT_00695ec4 == 0x81 || ((DAT_00695ec4 == 0x82 || (DAT_00695ec4 == 0x83))))))))))
            || ((((DAT_00695ec4 == 0x84 ||
                  ((((((DAT_00695ec4 == 0x85 || (DAT_00695ec4 == 0x86)) || (DAT_00695ec4 == 0x87))
                     || (((DAT_00695ec4 == 0x88 || (DAT_00695ec4 == 0x89)) ||
                         ((DAT_00695ec4 == 0x8e || ((DAT_00695ec4 == 199 || (DAT_00695ec4 == 200))))
                         )))) || (DAT_00695ec4 == 0xc9)) ||
                   ((((((DAT_00695ec4 == 0xca || (DAT_00695ec4 == 0xcb)) || (DAT_00695ec4 == 0xcc))
                      || ((DAT_00695ec4 == 0xcd || (DAT_00695ec4 == 0xce)))) ||
                     (DAT_00695ec4 == 0xcf)) || ((DAT_00695ec4 == 0xd2 || (DAT_00695ec4 == 0xd3)))))
                   ))) || (((DAT_00695ec4 == 0xd4 ||
                            (((DAT_00695ec4 == 0xd5 || (DAT_00695ec4 == 0xd6)) ||
                             (DAT_00695ec4 == 0xd7)))) ||
                           (((DAT_00695ec4 == 0xd8 || (DAT_00695ec4 == 0xd9)) ||
                            (DAT_00695ec4 == 0xdc)))))) || (DAT_00695ec4 == 0xdb)))))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_004475a4
 * Entry Point: 004475a4
 * Size: 1142 bytes
 */


void Pic_Subsystem_004475a4(void)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  if ((g_DuelModeFlags & 2) == 0) {
    return;
  }
  g_DuelModeFlags = g_DuelModeFlags & 0xfffffffd;
  g_DuelModeFlags = g_DuelModeFlags | 4;
  Ai_Subsystem_004cc9c5(0,0xff);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14]; local_18 = local_18 + 1
        ) {
      if (((*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + local_14 * 0x5b20) == DAT_006ff2e0) &&
          (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0)) {
        Magic_BroadcastCardEvent(local_14,local_18,0x21);
      }
    }
  }
  bVar1 = false;
  do {
    if ((g_IsAiThinking != 1) && (DAT_00633434 == 0)) {
      FUN_00472f0c(9,0xf);
      local_10 = -99999;
      bVar1 = true;
    }
    while( true ) {
      if ((DAT_006808a8 == 9) && (bVar1)) {
        Ai_GetActivePlayerScore();
        DAT_006b253c = 0;
        DAT_006b2538 = 0;
        DAT_006a2844 = 0;
        g_SpellStackDepth = 0;
      }
      iVar2 = FUN_00475c8a(-2,0xffffffff,s_Damage_prevention_005221a8,0x8e);
      if (iVar2 != 0) break;
      Magic_ScanCards(0x25);
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14];
            local_18 = local_18 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + local_14 * 0x5b20) == DAT_006ff2e0)
              && (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
             (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0)) {
            Magic_BroadcastCardEvent(local_14,local_18,0x6e);
          }
        }
      }
      FUN_00476205(g_TurnPlayer,0xd7,s_Damage_Dealing_005221bc,0);
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[local_14];
            local_18 = local_18 + 1) {
          if ((*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + local_14 * 0x5b20) == DAT_006ff2e0)
             && (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) {
            if (((&g_CardSlot_Flags)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0) {
              g_DuelModeFlags = g_DuelModeFlags | 2;
            }
            else {
              Pic_Subsystem_0044867e(local_14,local_18,1);
            }
          }
        }
      }
      Pic_Subsystem_00447a1a();
      g_DuelModeFlags = g_DuelModeFlags & 0xfffffffb;
      if (((g_IsAiThinking != 1) || (!bVar1)) || (DAT_006808a8 != 9)) {
        if (g_IsAiThinking == 1) {
          return;
        }
        if (!bVar1) {
          return;
        }
        DAT_00633434 = 0;
        return;
      }
      Pic_Subsystem_004488a0();
      iVar2 = Ai_SimulateCombatRound(g_ActivePlayerPriority);
      iVar2 = g_SpellStackDepth + iVar2;
      if (local_10 < iVar2) {
        Ai_ScoreBoardPosition();
        local_c = DAT_00680790;
        local_10 = iVar2;
      }
      if (DAT_006a2840 == 999) {
        DAT_006a2840 = -1;
      }
      DAT_006a2838 = 0;
      iVar2 = Mem_AllocOrFree_00501721();
      if ((DAT_006fe40c * DAT_0052244c) / 5 < iVar2) {
        g_IsAiThinking = 0;
        DAT_006a2840 = -1;
        DAT_00680790 = local_c;
      }
      g_DuelModeFlags = g_DuelModeFlags | 4;
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
  short sVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0))
         && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        sVar1 = *(short *)(&g_CardSlot_Power + local_c * 0x120 + local_8 * 0x5b20);
        iVar2 = Magic_QueryCardAttribute(local_8,local_c,0x33,0xffffffff);
        if (iVar2 <= sVar1) {
          if (g_IsAiThinking != 1) {
            Duel_PlaySoundById(0x19);
          }
          Pic_Subsystem_0044867e(local_8,local_c,2);
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
  int iVar1;
  int iVar2;
  int arg_3;
  int local_14;
  int local_c;
  
  DAT_0063ee88 = 1;
  *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x800;
  iVar1 = Card_IsTapped(arg1,arg2);
  if (((((iVar1 == 0) || (g_ScWillyScore != 0x15)) || (g_TurnPlayer != arg1)) ||
      ((((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0 ||
       (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)))) ||
     (iVar1 = FUN_004726c5(arg1,arg2), iVar1 == 0)) {
    if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (g_CurrentStepCode == -1))
    {
      if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) &&
         ((g_CurrentStepCode != -1 &&
          (*(code **)(&DAT_0051aec8 +
                     *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34) !=
           Prompts_Load_00416f1a)))) {
        local_c = 0;
      }
      else if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) ||
              (g_ScWillyScore != 1)) {
        if (g_CurrentTurnPhase == arg1) {
          iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
          if ((DAT_0063ee10 == 0) && ((g_ScWillyScore == 0x15 || (g_ScWillyScore == 0x17)))) {
            if (((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) &&
                (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
               (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) {
              if (((g_TurnPlayer == arg1) && (iVar1 = FUN_004726c5(arg1,arg2), iVar1 != 0)) &&
                 (((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0)) {
                DAT_0063ee88 = 0;
                return 0x10;
              }
              if ((g_TurnPlayer != arg1) && (DAT_006a5f20 != 0)) {
                DAT_0063ee88 = 0;
                return 0x20;
              }
            }
            *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            local_c = 0;
          }
          else {
            if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
              if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
                *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                DAT_0063ee88 = 0;
                return 0;
              }
              Card_ColorMaskToColorIndex((&DAT_0051aebe)[iVar1 * 0x34]);
              if ((DAT_0063ee10 == 0) ||
                 ((DAT_0063edc8 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
                if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 1) != 0) {
                  if (((g_TurnPlayer == arg1) && (((byte)g_DuelModeFlags & 1) == 0)) &&
                     ((g_ScWillyScore == 0x14 || (g_ScWillyScore == 0x1e)))) {
                    DAT_0063ee88 = 0;
                    return 4;
                  }
                  *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                       *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                  DAT_0063ee88 = 0;
                  return 0;
                }
                if (((g_TurnPlayer == g_CurrentTurnPhase) ||
                    (((g_TurnPlayer != g_CurrentTurnPhase && (DAT_0063ee10 != 0)) &&
                     ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x10) != 0 ||
                      (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x20) != 0)))))) &&
                   ((iVar2 = FUN_00470ea3(arg1,arg1,arg2), iVar2 != 0 &&
                    (((((byte)g_DuelModeFlags & 4) == 0 ||
                      ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x3004) != 0)) &&
                     ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x42) != 0 ||
                      (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x74,1 - arg1,0xffffffff),
                      iVar1 != 0)))))))) {
                  DAT_0063ee88 = 0;
                  return 4;
                }
              }
            }
            else {
              if ((DAT_00695ec4 == 4) &&
                 (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
                DAT_006a4920 = DAT_006a4920 | 3;
                DAT_00695f0c = DAT_00695f0c | 4;
                DAT_0063ee88 = 0;
                return 2;
              }
              if ((((DAT_00695ec4 == 4) &&
                   (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
                  (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0)) &&
                 (iVar2 = FUN_00476675(arg1,arg2), iVar2 != 0)) {
                DAT_00695f0c = DAT_00695f0c | 2;
                DAT_0063ee88 = 0;
                return 8;
              }
              if (((((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) &&
                    (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) &&
                   ((DAT_0063ee10 == 0 && ((g_TurnPlayer == arg1 && (g_ScWillyScore < 0x1b)))))
                   ) && (iVar2 = FUN_004726c5(arg1,arg2), iVar2 != 0)) &&
                 ((((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                  (((&g_MasterCardColorTable)
                    [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0))
                 )) {
                DAT_0063ee78 = 1;
              }
              if (((((((&DAT_0051aed1)[iVar1 * 0x34] & 0x10) != 0) &&
                    (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
                   ((((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                    (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0
                    )))) || (((((&DAT_0051aed0)[iVar1 * 0x34] & 1) != 0 &&
                              ((DAT_0063edc8 & 0x10) != 0)) ||
                             ((((&DAT_0051aed0)[iVar1 * 0x34] & 2) != 0 &&
                              ((DAT_0063edc8 & 0x20) != 0)))))) &&
                 ((((((byte)g_DuelModeFlags & 4) == 0 ||
                    ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x5004) != 0)) &&
                   (DAT_006a4920 = DAT_006a4920 & 0xfffffffd,
                   ((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)) &&
                  (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x73,1 - arg1,0xffffffff), iVar1 != 0)))
                 ) {
                if ((DAT_006a4920 & 2) != 0) {
                  DAT_00695f0c = DAT_00695f0c | 4;
                  DAT_0063ee88 = 0;
                  return 2;
                }
                DAT_00695f0c = DAT_00695f0c | 2;
                DAT_0063ee88 = 0;
                return 8;
              }
            }
            *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            local_c = 0;
          }
        }
        else if ((DAT_00695ec4 == 4) &&
                (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
          DAT_006a4920 = DAT_006a4920 | 3;
          DAT_00695f0c = DAT_00695f0c | 4;
          local_c = 2;
        }
        else {
          *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
          local_c = 0;
        }
      }
      else {
        g_EventSourcePlayer = arg1;
        g_EventSourceSlot = arg2;
        g_CardEventResult = 0;
        Magic_ScanCards(0x7d);
        local_c = g_CardEventResult;
      }
    }
    else {
      if (*(int *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) == g_CurrentStepCode) {
        if (arg1 == DAT_006a4b5c) {
          local_14 = 2;
        }
        else {
          local_14 = 0;
        }
      }
      else {
        arg_3 = 2;
        iVar2 = 0;
        iVar1 = Magic_BroadcastCardEventInStep(arg1,arg2,0x7d,arg1);
        local_14 = Math_Clamp(iVar1,iVar2,arg_3);
      }
      if (local_14 == 0) {
        local_c = 0;
      }
      else {
        DAT_00695f0c = DAT_00695f0c | 1 << ((byte)local_14 & 0x1f);
        DAT_0068a714 = DAT_0068a714 + 1;
        local_c = local_14;
      }
    }
  }
  else {
    local_c = 2;
  }
  DAT_0063ee88 = 0;
  return local_c;
}



/*
 * Decompiled function: Magic_BroadcastCardEventInStep
 * Entry Point: 004485d6
 * Size: 168 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Magic_BroadcastCardEventInStep(int x,int y,int width,undefined4 arg_4)

{
  undefined4 uVar1;
  
  if ((width == 0x7d) &&
     ((((&DAT_006a5f3d)[y * 0x120 + x * 0x5b20] & 1) != 0 || (DAT_0068078c != 0)))) {
    uVar1 = 0;
  }
  else if (g_CurrentStepCode < 200) {
    uVar1 = 0;
  }
  else {
    g_CardEventResult = 0;
    g_EventSourcePlayer = x;
    g_EventSourceSlot = y;
    _DAT_006b2fe8 = arg_4;
    g_EventTargetSlot = 0xffffffff;
    Magic_ScanCards(width);
    uVar1 = g_CardEventResult;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0044867e
 * Entry Point: 0044867e
 * Size: 546 bytes
 */


void Pic_Subsystem_0044867e(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (((player != -1) && (card_slot != -1)) &&
     (((&g_CardSlot_Abilities1)[card_slot * 0x120 + player * 0x5b20] & 0x80) == 0)) {
    *(uint *)(&g_CardSlot_Abilities1 + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + card_slot * 0x120 + player * 0x5b20) | 0x80;
    iVar1 = *(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20);
    if (iVar1 != -1) {
      if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) == 0) {
        arg_3 = 3;
      }
      if (((((&g_CardSlot_Abilities1)[card_slot * 0x120 + player * 0x5b20] & 8) == 0) && (arg_3 != 3)) &&
         ((arg_3 != 4 &&
          ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 3) != 0 &&
           ((&g_MasterCardColorTable)[iVar1 * 0x34] != -0x80)))))) {
        (&DAT_006a5f50)[card_slot * 0x120 + player * 0x5b20] = (undefined1)arg_3;
        *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 2;
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) == 0) {
          Pic_Subsystem_0044895f(player,card_slot);
        }
        else {
          *(undefined4 *)(&DAT_006a5f80 + card_slot * 0x120 + player * 0x5b20) = 0xd6;
        }
        DAT_00695f18 = Pic_Subsystem_0044895f;
      }
      else {
        (&DAT_006a5f50)[card_slot * 0x120 + player * 0x5b20] = (undefined1)arg_3;
        Pic_Subsystem_0044895f(player,card_slot);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004488a0
 * Entry Point: 004488a0
 * Size: 191 bytes
 */


undefined4 Pic_Subsystem_004488a0(void)

{
  if ((DAT_00695f18 != 0) && (DAT_0052211c == 0)) {
    DAT_0052211c = 1;
    g_DuelModeFlags = g_DuelModeFlags | 0x200;
    FUN_00475c8a(-2,g_ScWillyScore,s_Use_Regeneration_Effects_005221cc,0x70);
    g_DuelModeFlags = g_DuelModeFlags & 0xfffffdff;
    FUN_00476205(g_TurnPlayer,0xd6,s_Graveyard_order_005221e8,0);
    FUN_00476205(g_TurnPlayer,0xd5,s_Card_s__to_Graveyard_005221f8,0);
    DAT_00695f18 = 0;
    DAT_0052211c = 0;
    Ai_Subsystem_004cc9c5(0,0xff);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044895f
 * Entry Point: 0044895f
 * Size: 1226 bytes
 */


undefined4 Pic_Subsystem_0044895f(int arg1,int arg2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  cVar1 = (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20];
  if (cVar1 != '\0') {
    if ((((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0) &&
       ((&g_MasterCardColorTable)[iVar2 * 0x34] != -0x80)) {
      if ((cVar1 != '\x04') &&
         ((((&g_MasterCardColorTable)[iVar2 * 0x34] & 2) != 0 &&
          (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)))) {
        DAT_006b303c = DAT_006b303c + 1;
      }
      if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x47) != 0) {
        Magic_PushEventContext();
        g_CardEventResult = 0;
        g_EventSourcePlayer = arg1;
        g_EventSourceSlot = arg2;
        g_EventTargetPlayer = 1 - arg1;
        g_EventTargetSlot = 0xffffffff;
        Magic_ScanCards(0x77);
        if (0 < g_CardEventResult) {
          *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
          Magic_PopEventContext();
          return 0;
        }
        cVar1 = (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20];
        Magic_PopEventContext();
      }
      if (((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
        if (cVar1 == '\x04') {
          Pic_Subsystem_0044929c
                    ((*(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x1000) >> 0xc,
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
            FUN_00476205(g_TurnPlayer,0xd5,s_Card_s__to_Graveyard_00522210,0);
          }
        }
      }
    }
    Magic_PushEventContext();
    uVar4 = DAT_006b2e14;
    uVar3 = DAT_00695f08;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x47) != 0) {
      FUN_00476205(g_TurnPlayer,0xd4,s_Card_leaving_play_00522228,0);
    }
    DAT_00695f08 = uVar3;
    DAT_006b2e14 = uVar4;
    Magic_PopEventContext();
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg1 * 4) = *(int *)(&DAT_006b3010 + arg1 * 4) + -1;
    }
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg1] = (&DAT_006b3018)[arg1] + -1;
    }
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg1 * 4) = *(int *)(&DAT_006b3020 + arg1 * 4) + -1;
    }
    *(undefined4 *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
    (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(undefined4 *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    if (g_IsAiThinking != 1) {
      Ai_Subsystem_004cc3f8(arg1,arg2,7,2);
    }
    Pic_Subsystem_00448e29(arg1,arg2);
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x47) != 0) {
      FUN_00472fae();
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
          *(undefined4 *)(&g_CardSlot_OriginalCardId + local_514 * 0x120 + local_508 * 0x5b20) =
               0xffffffff;
        }
      }
    }
  }
  while (local_510 != 0) {
    local_510 = local_510 + -1;
    Pic_Subsystem_0044867e(aiStack_504[local_510 * 2],aiStack_504[local_510 * 2 + 1],2);
  }
  *(undefined2 *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20) = 0;
  *(undefined2 *)(&DAT_006a5f4a + arg2 * 0x120 + arg1 * 0x5b20) =
       *(undefined2 *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20);
  *(undefined2 *)(&DAT_006a5f48 + arg2 * 0x120 + arg1 * 0x5b20) =
       *(undefined2 *)(&DAT_006a5f4a + arg2 * 0x120 + arg1 * 0x5b20);
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
  int iVar1;
  int local_10;
  uint local_c;
  
  iVar1 = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20);
  local_c = (uint)(((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
  *(uint *)(&DAT_00695e00 + local_c * 4) =
       *(uint *)(&DAT_00695e00 + local_c * 4) | (uint)(byte)(&g_MasterCardColorTable)[iVar1 * 0x34];
  local_10 = 0;
  while( true ) {
    if (499 < local_10) {
      return;
    }
    if (*(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) == -1) break;
    local_10 = local_10 + 1;
  }
  *(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) = iVar1;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00449223
 * Entry Point: 00449223
 * Size: 121 bytes
 */


void Pic_Subsystem_00449223(int arg1,int arg2)

{
  int local_8;
  
  for (local_8 = arg2; local_8 < 499; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_006ff714 + local_8 * 4 + arg1 * 2000);
  }
  *(undefined4 *)(&DAT_006ffedc + arg1 * 2000) = 0xffffffff;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044929c
 * Entry Point: 0044929c
 * Size: 164 bytes
 */


void Pic_Subsystem_0044929c(int arg1,int arg2)

{
  int local_8;
  
  if ((g_IsAiThinking != 1) && (((&g_MasterCardColorTable)[arg2 * 0x34] & 2) != 0)) {
    Duel_PlaySoundById(0x17);
  }
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return;
    }
    if (*(int *)(&DAT_006b1590 + local_8 * 4 + arg1 * 2000) == -1) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_006b1590 + local_8 * 4 + arg1 * 2000) = arg2;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00449340
 * Entry Point: 00449340
 * Size: 401 bytes
 */


bool Pic_Subsystem_00449340(LPCSTR str_1)

{
  ATOM AVar1;
  ATOM AVar2;
  ATOM AVar3;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Pic_Subsystem_004494ff;
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
  local_2c.lpfnWndProc = Pic_Subsystem_00449fbb;
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
  local_2c.lpfnWndProc = Pic_Subsystem_0044a135;
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
 * Decompiled function: Pic_Subsystem_004494ff
 * Entry Point: 004494ff
 * Size: 2624 bytes
 */


LRESULT Pic_Subsystem_004494ff(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  LONG LVar1;
  HBRUSH pHVar2;
  UINT dwMilliseconds;
  BOOL BVar3;
  int iVar4;
  WPARAM wParam_00;
  LRESULT LVar5;
  int local_a68;
  undefined1 local_a60 [2000];
  uint local_290;
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
  uint local_f0;
  char *local_ec;
  int local_e8;
  char *local_e4;
  char *local_e0;
  WPARAM local_dc;
  char local_d8 [100];
  char local_74 [100];
  LONG local_10;
  char *local_c;
  HWND local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_10 = GetWindowLongA(hwnd,0);
      local_c = (char *)GetWindowLongA(hwnd,8);
      local_200 = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      if (local_200 != local_10) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      GetClientRect(hwnd,&local_210);
      pHVar2 = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_210,pHVar2);
      if (local_200 == -1) {
        if (local_c != (HANDLE)0x0) {
          FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_210,local_c);
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
        local_10 = local_200;
        SetWindowLongA(hwnd,0,local_200);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_10 = 0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      local_8 = (HWND)0x0;
      SetWindowLongA(hwnd,4,0);
      local_c = (char *)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      local_c = (char *)GetWindowLongA(hwnd,8);
      if (local_c != (HANDLE)0x0) {
        GDI_DestroyDIBSection_Magic(local_c);
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
      local_290 = (uint)(hwnd != DAT_006b2e10);
      AppendMenuA(DAT_00538bcc,0,100,s_View_the_graveyard_00522284);
      iVar4 = Ai_Subsystem_004b718a(local_a60,local_290);
      if (iVar4 == 0) {
        EnableMenuItem(DAT_00538bcc,100,1);
      }
      AppendMenuA(DAT_00538bcc,0,0x65,s_View_the_out_of_play_cards_00522298);
      iVar4 = Ai_Subsystem_004b722d(local_a60,local_290);
      if (iVar4 == 0) {
        EnableMenuItem(DAT_00538bcc,0x65,1);
      }
      AppendMenuA(DAT_00538bcc,0,0x66,s_View_both_antes_005222b4);
      AppendMenuA(DAT_00538bcc,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_00538bcc,0,0x67,s_Help____005222c4);
      return 0;
    }
    if (uMsg == 0x111) {
      switch((uint)wParam & 0xffff) {
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
        strcpy(local_1fc,&DAT_006807a0);
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
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
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
      if (DAT_006fe444 == 2) {
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
      wParam_00 = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      if ((wParam_00 != 0xffffffff) && (DAT_006fe444 == 2)) {
        SendMessageA(DAT_0069f744,0x401,wParam_00,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      local_8 = (HWND)GetWindowLongA(hwnd,4);
      local_ec = wParam;
      local_f0 = lParam;
      if (wParam == (char *)0x0) {
        if (local_8 != (HWND)0x0) {
          ReleaseCapture();
          Pic_Util_0044a7cc(local_8);
          local_8 = (HWND)0x0;
          SetWindowLongA(hwnd,4,0);
        }
      }
      else {
        if (local_8 == (HWND)0x0) {
          local_8 = (HWND)Pic_Subsystem_0044a402(hwnd,lParam);
        }
        SetWindowLongA(hwnd,4,(LONG)local_8);
        if (local_8 != (HWND)0x0) {
          SetCapture(local_8);
        }
      }
      return 0;
    case 0x432:
      local_10 = GetWindowLongA(hwnd,0);
      local_e8 = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      SendMessageA(hwnd,0x400,0,0);
      if (local_e8 != local_10) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_e0 = (char *)Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
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
      local_dc = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      if ((local_dc != 0xffffffff) &&
         ((DAT_006fe444 != 2 || (BVar3 = IsWindowVisible(DAT_0069f744), BVar3 != 0)))) {
        SendMessageA(DAT_0069f744,0x401,local_dc,0);
      }
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      local_c = (char *)GetWindowLongA(hwnd,8);
      if (local_c != (HGDIOBJ)0x0) {
        DeleteObject(local_c);
      }
      local_c = wParam;
      SetWindowLongA(hwnd,8,(LONG)wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}



/*
 * Decompiled function: Pic_Subsystem_00449fbb
 * Entry Point: 00449fbb
 * Size: 366 bytes
 */


LRESULT Pic_Subsystem_00449fbb(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam)

{
  POINT Point;
  LRESULT LVar1;
  tagPOINT local_10;
  HWND local_8;
  
  if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_0044a00e:
      GetCursorPos(&local_10);
      Point.y = local_10.y;
      Point.x = local_10.x;
      local_8 = WindowFromPoint(Point);
      MapWindowPoints((HWND)0x0,local_8,&local_10,1);
      if (hwnd != local_8) {
        SendMessageA(local_8,uMsg,wParam,local_10.y << 0x10 | local_10.x & 0xffffU);
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
 * Decompiled function: Pic_Subsystem_0044a135
 * Entry Point: 0044a135
 * Size: 705 bytes
 */


LRESULT Pic_Subsystem_0044a135(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam)

{
  BOOL BVar1;
  LONG LVar2;
  WPARAM WVar3;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar4;
  tagPAINTSTRUCT local_58;
  tagRECT local_18;
  WPARAM local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      GetClientRect(hwnd,&local_18);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      hbr = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_18,hbr);
      Palette_Subsystem_0049c7c7
                (g_HdcBackBuffer,&local_18.left,(WPARAM *)(&DAT_006b3070 + local_8 * 0x98),0,0x11,0)
      ;
      hdc = BeginPaint(hwnd,&local_58);
      if (hdc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(hdc);
        BitBlt(hdc,0,0,local_18.right,local_18.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_58);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0xffffffff;
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
      local_8 = GetWindowLongA(hwnd,0);
      if (DAT_006fe444 == 2) {
        SendMessageA(DAT_0069f744,0x401,local_8,0);
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
        local_8 = wParam;
        SetWindowLongA(hwnd,0,wParam);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_8 = GetWindowLongA(hwnd,0);
      if ((DAT_006fe444 != 2) || (BVar1 = IsWindowVisible(DAT_0069f744), BVar1 != 0)) {
        SendMessageA(DAT_0069f744,0x401,local_8,0);
      }
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: Pic_Subsystem_0044a402
 * Entry Point: 0044a402
 * Size: 970 bytes
 */


HWND Pic_Subsystem_0044a402(HWND hwnd,int arg2)

{
  int iVar1;
  HGDIOBJ pvVar2;
  int iVar3;
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
  uint local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  GetWindowRect(hwnd,&local_24);
  local_14.left = local_24.left;
  local_14.top = local_24.top;
  GetClientRect(g_MainAppHwnd,&local_24);
  local_14.right = (local_24.right * 0x4b) / 100;
  local_14.bottom = local_24.bottom;
  GetClientRect(hwnd,&local_24);
  local_2c = local_24.bottom;
  iVar1 = (local_24.right * 0x3c) / 100;
  local_44 = 5;
  local_40 = 5;
  local_3c = (((local_14.right - local_14.left) + -10) - local_24.right) / iVar1 + 1;
  local_28 = (uint)(hwnd != DAT_006b2e10);
  local_30 = CreateWindowExA(0,s_ExpandedGraveyard_005222f0,
                             s_Graveyard_list_005222cc + ((arg2 != 0) - 1 & 0x10),0x80000000,0,0,0,0
                             ,g_MainAppHwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  if (local_30 == (HWND)0x0) {
    local_30 = (HWND)0x0;
  }
  else {
    if (arg2 == 0) {
      pvVar2 = GetStockObject(0);
      SetClassLongA(local_30,-10,(LONG)pvVar2);
    }
    else {
      pvVar2 = GetStockObject(4);
      SetClassLongA(local_30,-10,(LONG)pvVar2);
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
        local_830 = local_830 + iVar1;
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
      iVar3 = local_3c + -1;
      if (local_820 + -1 <= local_3c + -1) {
        iVar3 = local_820 + -1;
      }
      local_14.right = iVar3 * iVar1 + local_44 * 2 + local_14.left + local_24.right;
      local_834 = local_820 / local_3c;
      if (local_820 % local_3c != 0) {
        local_834 = local_834 + 1;
      }
      local_14.bottom =
           (local_40 + local_2c) * (local_834 + -1) + local_40 * 2 + local_14.top + local_2c;
      GetClientRect(g_MainAppHwnd,&local_24);
      if (local_24.bottom < local_14.bottom) {
        OffsetRect(&local_14,0,-(local_14.bottom - local_24.bottom));
      }
      MoveWindow(local_30,local_14.left,local_14.top,local_14.right - local_14.left,
                 local_14.bottom - local_14.top,1);
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


undefined4 Pic_Subsystem_0044a7e1(int player)

{
  undefined4 uVar1;
  int local_7d8;
  undefined1 local_7d4 [2000];
  
  local_7d8 = Ai_Subsystem_004b718a(local_7d4,player);
  if (local_7d8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(local_7d4 + local_7d8 * 4 + -4);
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_0044a839
 * Entry Point: 0044a839
 * Size: 41 bytes
 */


void Pic_Subsystem_0044a839(void)

{
  DialogBoxParamA(g_AppHInstance,(LPCSTR)0xeb,g_MainAppHwnd,Pic_Load_0044a862,0);
  return;
}



/*
 * Decompiled function: Pic_Load_0044a862
 * Entry Point: 0044a862
 * Size: 2560 bytes
 */


HGDIOBJ Pic_Load_0044a862(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  size_t c;
  int iVar1;
  BOOL BVar2;
  HGDIOBJ pvVar3;
  HBRUSH hbr;
  HWND pHVar4;
  HWND pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
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
  uint local_224;
  uint local_220;
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
  tagRECT local_14;
  
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
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43c);
      ShowWindow(pHVar4,iVar8);
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x439);
      ShowWindow(pHVar4,iVar8);
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      ShowWindow(pHVar4,iVar8);
      iVar8 = 0;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      ShowWindow(pHVar4,iVar8);
      sprintf(local_1e4,s__s_WINBK_Ante_pic_00522338,&DAT_006b2e90);
      DAT_00538bc0 = (HANDLE)Pic_Load_00423833(local_1e4);
      sprintf(local_1e4,s__s_WINBK_AnteLabel_pic_0052234c,&DAT_006b2e90);
      DAT_00538bc8 = (HANDLE)Pic_Load_00423833(local_1e4);
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
      iVar8 = local_1ec.cy + local_1ec.cx;
      iVar1 = (local_1ec.cy * 3) / 2;
      UVar9 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      local_1f8 = iVar1;
      local_1f4 = iVar8;
      pHVar4 = GetDlgItem(hwnd,0x43a);
      SetWindowPos(pHVar4,pHVar5,iVar6,iVar7,iVar8,iVar1,UVar9);
      UVar9 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar8 = local_1f4;
      iVar1 = local_1f8;
      pHVar4 = GetDlgItem(hwnd,0x43b);
      SetWindowPos(pHVar4,pHVar5,iVar6,iVar7,iVar8,iVar1,UVar9);
      ReleaseDC(hwnd,local_1fc);
      GetWindowRect(hwnd,&local_14);
      UVar9 = 5;
      iVar6 = 0;
      iVar1 = 0;
      iVar8 = GetSystemMetrics(0);
      SetWindowPos(hwnd,(HWND)0x0,(iVar8 * 0x14) / 100,local_14.top,iVar1,iVar6,UVar9);
      SetFocus(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x100) {
LAB_0044ab14:
      GDI_DestroyDIBSection_Magic(DAT_00538bc0);
      GDI_DestroyDIBSection_Magic(DAT_00538bc8);
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
      pvVar3 = GetStockObject(5);
      return pvVar3;
    }
    if (uMsg == 0x111) goto LAB_0044ab14;
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar3 = (HGDIOBJ)GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar3;
    }
    if (uMsg != 0x200) {
      if (uMsg == 0x201) {
        GDI_DestroyDIBSection_Magic(DAT_00538bc0);
        GDI_DestroyDIBSection_Magic(DAT_00538bc8);
        EndDialog(hwnd,0);
        return (HGDIOBJ)0x1;
      }
      if (uMsg != 0x204) {
        return (HGDIOBJ)0x0;
      }
    }
    Ai_Subsystem_004b73ce((int)local_2a4,&local_204,(int)local_264,&local_21c);
    local_224 = (uint)lParam & 0xffff;
    local_220 = (uint)lParam >> 0x10;
    if (((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) {
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
  undefined1 local_c4 [64];
  undefined1 local_84 [64];
  int local_44;
  int local_40;
  tagRECT local_3c;
  tagRECT local_2c;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  Ai_Subsystem_004b73ce((int)local_c4,&local_18,(int)local_84,&local_1c);
  ptVar2 = &local_3c;
  pHVar1 = GetDlgItem(hwnd,0x43c);
  GetWindowRect(pHVar1,ptVar2);
  MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_3c,2);
  ptVar2 = &local_2c;
  pHVar1 = GetDlgItem(hwnd,0x439);
  GetWindowRect(pHVar1,ptVar2);
  MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_2c,2);
  local_44 = local_3c.right - local_3c.left;
  GetClientRect(hwnd,&local_14);
  local_14.left = local_3c.left;
  if (width == 0) {
    if ((local_1c < 1) || (local_1c <= height)) {
      SetRect(player,0,0,0,0);
    }
    else {
      for (local_40 = (local_44 * 0x3c) / 100;
          (local_14.right - local_3c.left < (local_1c + -1) * local_40 + local_44 &&
          ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
      }
      CopyRect(player,&local_2c);
      OffsetRect(player,local_40 * height,0);
    }
  }
  else if ((local_18 < 1) || (local_18 <= height)) {
    SetRect(player,0,0,0,0);
  }
  else {
    for (local_40 = (local_44 * 0x3c) / 100;
        (local_14.right - local_3c.left < (local_18 + -1) * local_40 + local_44 &&
        ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
    }
    CopyRect(player,&local_3c);
    OffsetRect(player,local_40 * height,0);
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044b460
 * Entry Point: 0044b460
 * Size: 985 bytes
 */


void Pic_Subsystem_0044b460(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  int local_c;
  
  DVar1 = GetTickCount();
  srand(DVar1);
  uVar2 = Mem_AllocOrFree_0050ce90(s_misc_exe_005239f4,0);
  Mem_AllocOrFree_0050ce80(uVar2);
  uVar2 = Mem_AllocOrFree_0050ce90(s_mgraphic_exe_00523a0c,0x523a00);
  Mem_AllocOrFree_0050ce80(uVar2);
  uVar2 = Mem_AllocOrFree_0050ce90(s_nsound_cvl_00523a1c,0);
  Mem_AllocOrFree_0050ce80(uVar2);
  if (g_DisplayScreenWidth == 0x280) {
    DVar1 = 1;
    iVar6 = 700;
    pcVar5 = s_MagicMedieval_00523a28;
    pcVar4 = s_magim____ttf_00523a38;
    iVar3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    FUN_0050f1e0(1,0x10,s_tt0300m__ttf_00523a58,s_Zurich_Cn_BT_00523a48,400,0);
  }
  else if (g_DisplayScreenWidth == 800) {
    DVar1 = 1;
    iVar6 = 700;
    pcVar5 = s_MagicMedieval_00523a68;
    pcVar4 = s_magim____ttf_00523a78;
    iVar3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    FUN_0050f1e0(1,0x10,s_tt0127m__ttf_00523a98,s_Benguiat_Bk_BT_00523a88,100,0);
  }
  else if (g_DisplayScreenWidth == 0x400) {
    DVar1 = 1;
    iVar6 = 700;
    pcVar5 = s_MagicMedieval_00523aa8;
    pcVar4 = s_magim____ttf_00523ab8;
    iVar3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    DVar1 = 0;
    iVar6 = 100;
    pcVar5 = s_Benguiat_Bk_BT_00523ac8;
    pcVar4 = s_tt0127m__ttf_00523ad8;
    iVar3 = Ai_Util_004c3bc4(0xc);
    FUN_0050f1e0(1,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    DVar1 = 0;
    iVar6 = 100;
    pcVar5 = s_Benguiat_Bk_BT_00523ae8;
    pcVar4 = s_tt0127m__ttf_00523af8;
    iVar3 = Ai_Util_004c3bc4(0x11);
    FUN_0050f1e0(4,iVar3,pcVar4,pcVar5,iVar6,DVar1);
  }
  thunk_FUN_0050cef0(0);
  Catalog_LoadPaletteMap(s_todpal_tr_00523b08,(char *)0x0);
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    if ((local_c == 1) && (*(int *)(DAT_0070a850 + 0x20) < 0x401)) {
      local_10 = FUN_0050d0b0(1,0x400,800,8);
    }
    else {
      local_10 = Mem_AllocOrFree_0050cec0(local_c);
    }
    FUN_0050d370(local_c,local_10);
  }
  iVar7 = 8;
  iVar3 = Ai_Util_004c3bc4(0x1e0);
  iVar6 = Ai_Util_004c3bc4(0x148);
  iVar6 = (iVar3 - iVar6) + 3;
  iVar3 = Ai_Util_004c3bc4(0x280);
  uVar2 = FUN_0050d0b0(3,iVar3,iVar6,iVar7);
  FUN_0050d370(3,uVar2);
  iVar7 = 8;
  iVar3 = Ai_Util_004c3bc4(0x148);
  iVar6 = Ai_Util_004c3bc4(0x40);
  uVar2 = FUN_0050d0b0(5,iVar6,iVar3,iVar7);
  FUN_0050d370(5,uVar2);
  uVar2 = Ai_Util_004c3bc4(0x280);
  *(undefined4 *)(PTR_DAT_005174bc + 0xc) = uVar2;
  *(undefined4 *)(g_DisplaySurfaceWork + 0xc) = *(undefined4 *)(PTR_DAT_005174bc + 0xc);
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0xc) = *(undefined4 *)(g_DisplaySurfaceWork + 0xc);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0xc) = *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0xc);
  uVar2 = Ai_Util_004c3bc4(0x1e0);
  *(undefined4 *)(g_DisplaySurfaceWork + 0xc) = uVar2;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x10) = *(undefined4 *)(g_DisplaySurfaceWork + 0xc);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x10) =
       *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x10);
  iVar3 = Ai_Util_004c3bc4(0x1e0);
  iVar6 = Ai_Util_004c3bc4(0x148);
  *(int *)(PTR_DAT_005174bc + 0x10) = iVar3 - iVar6;
  uVar2 = Ai_Util_004c3bc4(0x148);
  *(undefined4 *)(PTR_DAT_005174e4 + 0x10) = uVar2;
  uVar2 = Ai_Util_004c3bc4(0x40);
  *(undefined4 *)(PTR_DAT_005174e4 + 0xc) = uVar2;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
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


undefined4 Pic_Util_0044b839(void)

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
  uint uVar1;
  
  if (DAT_005239ec == 0) {
    DAT_0067bda8 = 0;
    DAT_0067bda4 = 0;
    DAT_0067bda0 = 0;
  }
  else {
    uVar1 = Mem_AllocOrFree_00512210();
    DAT_0067bda0 = uVar1 | DAT_007039c4;
    DAT_0067bda4 = DAT_007039cc;
    DAT_0067bda8 = DAT_007039c8;
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
 * Decompiled function: Pic_Subsystem_0044b8da
 * Entry Point: 0044b8da
 * Size: 48 bytes
 */


void Pic_Subsystem_0044b8da(void)

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


void Pic_Subsystem_0044b90a(char *arg1,undefined4 arg2)

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


void Pic_Util_0044b943(undefined4 arg1,short *arg2)

{
  FUN_0050e8b0(arg2);
  return;
}



/*
 * Decompiled function: Pic_Util_0044b95a
 * Entry Point: 0044b95a
 * Size: 18 bytes
 */


undefined4 Pic_Util_0044b95a(void)

{
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044b96c
 * Entry Point: 0044b96c
 * Size: 81 bytes
 */


undefined4 Pic_Subsystem_0044b96c(int player)

{
  int iVar1;
  
  if ((player != 0) && (g_IsAiThinking != 1)) {
    Mem_AllocOrFree_005016f9();
    do {
      iVar1 = Mem_AllocOrFree_00501721();
    } while (iVar1 < DAT_0052244c * player);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Subsystem_0044b9c0
 * Entry Point: 0044b9c0
 * Size: 195 bytes
 */


bool Pic_Subsystem_0044b9c0(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = Pic_Subsystem_0044bad4;
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
 * Decompiled function: Pic_Subsystem_0044bad4
 * Entry Point: 0044bad4
 * Size: 5255 bytes
 */


LRESULT Pic_Subsystem_0044bad4(HWND hwnd,uint y,undefined4 *arg_3,LONG *arg_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
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
  uint local_274;
  uint local_270;
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
  undefined4 *local_50;
  undefined4 *local_4c;
  LONG *local_48;
  LONG *local_44;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 *local_2c;
  int local_28;
  LONG local_24;
  int local_20;
  LONG local_1c;
  LONG local_18;
  LONG local_14;
  void *local_10;
  int local_c;
  undefined4 *local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_1c = GetWindowLongA(hwnd,8);
      local_18 = GetWindowLongA(hwnd,0xc);
      local_14 = GetWindowLongA(hwnd,0x10);
      local_24 = GetWindowLongA(hwnd,0x14);
      local_8 = (undefined4 *)GetWindowLongA(hwnd,0x18);
      Pic_Subsystem_0044d58f
                (DAT_006a28b0,DAT_006b2e30,local_1c,local_18,local_14,local_24,&local_2a4,&local_290
                 ,&local_378,&local_374);
      GetClientRect(hwnd,&local_30c);
      local_288 = local_30c.top + local_2a4;
      local_280 = local_30c.bottom - local_290;
      local_28c = local_30c.left + local_378;
      local_284 = local_30c.right - local_378;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_2b8 = SaveDC(g_HdcBackBuffer);
      hbr = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_30c,hbr);
      Pic_Subsystem_0044d31a
                ((int)g_HdcBackBuffer,&local_30c.left,&local_28c,local_374,local_1c,local_18,
                 local_14,local_24,local_8);
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
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (y == 1) {
      local_20 = 0;
      SetWindowLongA(hwnd,4,0);
      local_10 = malloc(200);
      SetWindowLongA(hwnd,0,(LONG)local_10);
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_24 = 0;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,0xc,local_18);
      SetWindowLongA(hwnd,0x10,local_14);
      SetWindowLongA(hwnd,0x14,local_24);
      local_8 = (undefined4 *)0x0;
      SetWindowLongA(hwnd,0x18,0);
      local_c = 0xffffffff;
      SetWindowLongA(hwnd,0x1c,-1);
      if (local_10 == (void *)0x0) {
        return -1;
      }
      Pic_Subsystem_0044cfe4(hwnd);
      return 0;
    }
    if (y == 2) {
      local_10 = (void *)GetWindowLongA(hwnd,0);
      free(local_10);
      local_8 = (undefined4 *)GetWindowLongA(hwnd,0x18);
      if (local_8 != (HANDLE)0x0) {
        GDI_DestroyDIBSection_Magic(local_8);
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
      if (((uint)arg_3 & 0xffff) == 100) {
        local_138 = 0x7e3;
        strcpy(local_240,&DAT_006807a0);
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
      iVar2 = abs(local_250.top - local_260.top);
      iVar3 = abs(local_250.left - local_260.left);
      if (iVar2 + iVar3 < 5) {
        local_274 = (uint)arg_4 & 0xffff;
        local_270 = (uint)arg_4 >> 0x10;
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_20 = GetWindowLongA(hwnd,4);
        local_c = GetWindowLongA(hwnd,0x1c);
        local_1c = GetWindowLongA(hwnd,8);
        local_18 = GetWindowLongA(hwnd,0xc);
        local_14 = GetWindowLongA(hwnd,0x10);
        local_24 = GetWindowLongA(hwnd,0x14);
        if ((1 < local_20) &&
           (Pic_Subsystem_0044d58f
                      (DAT_006a28b0,DAT_006b2e30,local_1c,local_18,local_14,local_24,&local_26c,
                       &local_268,&local_27c,&local_278), (int)local_270 < local_26c)) {
          GetClientRect(hwnd,&local_250);
          if ((int)local_274 < (local_250.right * 0x14) / 100) {
            local_264 = local_20;
            if (0 < local_c) {
              local_264 = local_c;
            }
            local_264 = local_264 + -1;
            SendMessageA(hwnd,0x400,*(WPARAM *)((int)local_10 + local_264 * 4),0);
          }
          else if ((local_250.right * 0x50) / 100 < (int)local_274) {
            if (local_c < local_20 + -1) {
              local_264 = local_c + 1;
            }
            else {
              local_264 = 0;
            }
            SendMessageA(hwnd,0x400,*(WPARAM *)((int)local_10 + local_264 * 4),0);
          }
        }
      }
      return 0;
    }
    if (y == 0x11f) {
      if (((uint)arg_3 >> 0x10 == 0xffff) && (arg_4 == (LONG *)0x0)) {
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
      local_390.x = (uint)arg_4 & 0xffff;
      local_390.y = (uint)arg_4 >> 0x10;
      ClientToScreen(hwnd,&local_390);
      SetRect(&local_388,local_390.x,local_390.y,local_390.x + 1,local_390.y + 1);
      TrackPopupMenu(DAT_00538bf8,2,local_390.x,local_390.y,0,hwnd,&local_388);
      return 0;
    }
  }
  else {
    switch(y) {
    case 0x400:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_50 = arg_3;
      if (arg_3 == (undefined4 *)0x0) {
        return 0;
      }
      for (local_54 = 0; local_54 < local_20; local_54 = local_54 + 1) {
        if (*(undefined4 **)((int)local_10 + local_54 * 4) == local_50) {
          local_c = local_54;
          SetWindowLongA(hwnd,0x1c,local_54);
          Pic_Subsystem_0044cfe4(hwnd);
        }
      }
      return 0;
    case 0x40a:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_c = GetWindowLongA(hwnd,0x1c);
      if (0x31 < local_20) {
        return 0;
      }
      local_58 = arg_3;
      local_5c = (HWND)SendMessageA(hwnd,0x40f,(WPARAM)arg_3,0);
      if (local_5c == (HWND)0x0) {
        local_5c = CreateWindowExA(0,s_MAGICGAME_CardClass_00523b28,s_Hand_Card_00523b1c,0x54000000,
                                   0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,local_58);
        if (local_5c != (HWND)0x0) {
          *(HWND *)((int)local_10 + local_20 * 4) = local_5c;
          local_20 = local_20 + 1;
          SetWindowLongA(hwnd,4,local_20);
          iVar2 = local_20;
          if (local_20 + -1 == local_c + 1) {
            local_c = local_20 + -1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          else {
            while (local_60 = iVar2 + -1, local_c + 1 < local_60) {
              *(undefined4 *)((int)local_10 + local_60 * 4) =
                   *(undefined4 *)((int)local_10 + -4 + local_60 * 4);
              iVar2 = local_60;
            }
            *(HWND *)((int)local_10 + 4 + local_c * 4) = local_5c;
            local_c = local_c + 1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          Pic_Subsystem_0044cfe4(hwnd);
          Pic_Subsystem_0044d61a(local_94,hwnd,local_20);
          return local_20;
        }
        return 0;
      }
      iVar2 = Ai_Subsystem_004b5cbb(*local_58,local_58[1]);
      iVar2 = FUN_0046bbab(local_5c,iVar2);
      if (iVar2 != 0) {
        return local_20;
      }
      SendMessageA(hwnd,0x40b,(WPARAM)local_58,0);
      SendMessageA(hwnd,0x40a,(WPARAM)local_58,0);
      return local_20;
    case 0x40b:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_c = GetWindowLongA(hwnd,0x1c);
      local_a4 = arg_3;
      local_98 = 0;
      local_9c = 0;
      while ((local_9c < local_20 && (local_98 == 0))) {
        iVar2 = FUN_0046bb29(*(HWND *)((int)local_10 + local_9c * 4),local_a4);
        if (iVar2 != 0) {
          local_98 = 1;
          DestroyWindow(*(HWND *)((int)local_10 + local_9c * 4));
          local_20 = local_20 + -1;
          SetWindowLongA(hwnd,4,local_20);
          for (local_a0 = local_9c; local_a0 < local_20; local_a0 = local_a0 + 1) {
            *(undefined4 *)((int)local_10 + local_a0 * 4) =
                 *(undefined4 *)((int)local_10 + 4 + local_a0 * 4);
          }
          if (local_9c == local_c) {
            if (local_c == 0) {
              local_c = local_20;
            }
            local_c = local_c + -1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          else {
            if (local_c == 0) {
              local_c = local_20;
            }
            local_c = local_c + -1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          Pic_Subsystem_0044d61a(local_d8,hwnd,local_20);
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
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      for (local_dc = 0; local_dc < local_20; local_dc = local_dc + 1) {
        DestroyWindow(*(HWND *)((int)local_10 + local_dc * 4));
      }
      local_20 = 0;
      SetWindowLongA(hwnd,4,0);
      local_c = 0xffffffff;
      SetWindowLongA(hwnd,0x1c,-1);
      Pic_Subsystem_0044cfe4(hwnd);
      Pic_Subsystem_0044d61a(local_110,hwnd,local_20);
      return 0;
    case 0x40d:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_124 = arg_3;
      local_114 = 0;
      local_11c = 0;
      while( true ) {
        if (local_20 <= local_11c) {
          return local_114;
        }
        if (local_114 != 0) break;
        iVar2 = FUN_0046bb29(*(HWND *)((int)local_10 + local_11c * 4),local_124);
        if (iVar2 != 0) {
          local_114 = 1;
          local_118 = *(HWND *)((int)local_10 + local_11c * 4);
          BringWindowToTop(local_118);
          for (local_120 = local_11c; local_120 < local_20 + -1; local_120 = local_120 + 1) {
            *(undefined4 *)((int)local_10 + local_120 * 4) =
                 *(undefined4 *)((int)local_10 + 4 + local_120 * 4);
          }
          *(HWND *)((int)local_10 + -4 + local_20 * 4) = local_118;
        }
        local_11c = local_11c + 1;
      }
      return local_114;
    case 0x40e:
    case 0x40f:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_130 = arg_3;
      local_128 = 0;
      local_134 = 0;
      while ((local_134 < local_20 && (local_128 == 0))) {
        iVar2 = FUN_0046bb29(*(HWND *)((int)local_10 + local_134 * 4),local_130);
        if (iVar2 != 0) {
          local_128 = 1;
          if (y == 0x40e) {
            local_12c = FUN_0046bc2f(*(HWND *)((int)local_10 + local_134 * 4));
          }
          else {
            local_12c = *(LRESULT *)((int)local_10 + local_134 * 4);
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
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      for (local_30 = 0; local_30 < local_20; local_30 = local_30 + 1) {
        SendMessageA(*(HWND *)((int)local_10 + local_30 * 4),0x432,0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_2c = arg_3;
      for (local_28 = 0; local_28 < local_20; local_28 = local_28 + 1) {
        iVar2 = FUN_0046bbab(*(HWND *)((int)local_10 + local_28 * 4),(int)local_2c);
        if (iVar2 != 0) {
          InvalidateRect(*(HWND *)((int)local_10 + local_28 * 4),(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x435:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      for (local_34 = 0; local_34 < local_20; local_34 = local_34 + 1) {
        InvalidateRect(*(HWND *)((int)local_10 + local_34 * 4),(RECT *)0x0,0);
      }
      return 0;
    case 0x436:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_40 = arg_3;
      local_44 = arg_4;
      if (arg_3 == (undefined4 *)0x0) {
        return 0;
      }
      local_38 = 0;
      local_3c = 0;
      while ((local_3c < local_20 && (local_38 == 0))) {
        iVar2 = FUN_0046bb29(*(HWND *)((int)local_10 + local_3c * 4),local_40);
        if (iVar2 != 0) {
          local_38 = 1;
          if (local_44 == (LONG *)0x0) {
            InvalidateRect(*(HWND *)((int)local_10 + local_3c * 4),(RECT *)0x0,0);
          }
          else {
            SendMessageA(*(HWND *)((int)local_10 + local_3c * 4),0x432,0,0);
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
      local_8 = (undefined4 *)GetWindowLongA(hwnd,0x18);
      if (local_8 != (HGDIOBJ)0x0) {
        DeleteObject(local_8);
      }
      local_8 = local_4c;
      local_1c = *local_48;
      local_18 = local_48[1];
      local_14 = local_48[2];
      local_24 = local_48[3];
      SetWindowLongA(hwnd,8,local_1c);
      SetWindowLongA(hwnd,0xc,local_18);
      SetWindowLongA(hwnd,0x10,local_14);
      SetWindowLongA(hwnd,0x14,local_24);
      SetWindowLongA(hwnd,0x18,(LONG)local_8);
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
  int local_20;
  int local_1c;
  LONG local_18;
  int local_14;
  LONG local_10;
  int local_c;
  int local_8;
  
  local_1c = 8;
  local_48 = GetWindowLongA(hwnd,4);
  local_24 = GetWindowLongA(hwnd,0);
  local_44 = GetWindowLongA(hwnd,8);
  local_40 = GetWindowLongA(hwnd,0xc);
  local_3c = GetWindowLongA(hwnd,0x10);
  local_4c = GetWindowLongA(hwnd,0x14);
  local_10 = GetWindowLongA(hwnd,0x18);
  local_18 = GetWindowLongA(hwnd,0x1c);
  Pic_Subsystem_0044d58f
            (DAT_006a28b0,DAT_006b2e30,local_44,local_40,local_3c,local_4c,&local_14,&local_8,
             &local_58,&local_54);
  if ((hwnd == DAT_0069e720) || ((DAT_006fe400 == hwnd && (DAT_00695e90 != 0)))) {
    local_20 = local_1c;
    if (local_48 <= local_1c) {
      local_20 = local_48;
    }
    local_38 = local_54 * 2 + local_58 * 2 + DAT_006a28b0;
    if (local_48 == 0) {
      local_c = local_8 + local_14;
    }
    else {
      local_c = (local_20 + -1) * DAT_006ff67c + local_8 + local_14 + DAT_006b2e30;
    }
    if (0 < local_48) {
      local_2c = local_54 + local_58;
      local_30 = (local_c - local_8) - DAT_006b2e30;
      local_34 = local_18;
      local_28 = (HWND)0x0;
      for (local_50 = 1; local_50 <= local_20; local_50 = local_50 + 1) {
        MoveWindow(*(HWND *)(local_24 + local_34 * 4),local_2c,local_30,DAT_006a28b0,DAT_006b2e30,1)
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
      for (local_50 = local_20; local_50 < local_48; local_50 = local_50 + 1) {
        MoveWindow(*(HWND *)(local_24 + local_34 * 4),-1,-1,0,0,1);
        if (local_34 == 0) {
          local_34 = local_48;
        }
        local_34 = local_34 + -1;
      }
    }
    UpdateWindow(hwnd);
    SetWindowPos(hwnd,(HWND)0x0,0,0,local_38,local_c,6);
  }
  else {
    local_38 = local_54 * 2 + local_58 * 2 + DAT_006a28b0;
    local_c = local_8 + local_14;
    for (local_34 = 0; local_34 < local_48; local_34 = local_34 + 1) {
      MoveWindow(*(HWND *)(local_24 + local_34 * 4),-1,-1,0,0,1);
    }
    SetWindowPos(hwnd,(HWND)0x0,0,0,local_38,local_c,6);
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044d31a
 * Entry Point: 0044d31a
 * Size: 629 bytes
 */


void Pic_Subsystem_0044d31a
               (int player,int *card_slot,int *arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
               HANDLE arg_9)

{
  undefined1 local_34 [4];
  int local_30;
  int local_2c;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if ((((player != 0) && (card_slot != (int *)0x0)) && (arg_3 != (int *)0x0)) && (arg_9 != (HANDLE)0x0))
  {
    GetObjectA(arg_9,0x18,local_34);
    local_8 = ((arg_3[1] - card_slot[1]) * local_2c) / arg_5;
    for (local_1c = arg_3[1]; local_1c < arg_3[3]; local_1c = local_1c + local_8) {
      SetRect(&local_18,*arg_3,local_1c,*arg_3 + arg_4,local_1c + local_8);
      FUN_004f3bc7((HDC)player,&local_18.left,arg_9,local_30 - arg_8,0,arg_8,local_2c);
      SetRect(&local_18,arg_3[2] - arg_4,local_1c,arg_3[2],local_1c + local_8);
      FUN_004f3bc7((HDC)player,&local_18.left,arg_9,local_30 - arg_8,0,arg_8,local_2c);
    }
    SetRect(&local_18,*arg_3,card_slot[1],arg_3[2],arg_3[1]);
    FUN_004f3bc7((HDC)player,&local_18.left,arg_9,0,0,(local_30 - arg_7) - arg_8,arg_5);
    SetRect(&local_18,*arg_3,arg_3[3],arg_3[2],card_slot[3]);
    FUN_004f3bc7((HDC)player,&local_18.left,arg_9,0,local_2c - arg_6,(local_30 - arg_7) - arg_8,arg_6
                );
    for (local_1c = card_slot[1]; local_1c < card_slot[3]; local_1c = local_1c + local_8) {
      SetRect(&local_18,*card_slot,local_1c,*arg_3,local_1c + local_8);
      FUN_004f3bc7((HDC)player,&local_18.left,arg_9,(local_30 - arg_7) - arg_8,0,arg_7,local_2c);
      SetRect(&local_18,arg_3[2],local_1c,card_slot[2],local_1c + local_8);
      FUN_004f3bc7((HDC)player,&local_18.left,arg_9,(local_30 - arg_7) - arg_8,0,arg_7,local_2c);
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
               (undefined4 player,int card_slot,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,
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
 * Decompiled function: Pic_Subsystem_0044d61a
 * Entry Point: 0044d61a
 * Size: 93 bytes
 */


void Pic_Subsystem_0044d61a(char *str_1,HWND hwnd,undefined4 arg_3)

{
  sprintf(str_1,s__s___d__00523b68,s_Your_hand_00523b50 + ((hwnd == DAT_0069e720) - 1 & 0xc),arg_3);
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
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  
  do {
    Pic_Subsystem_0044e9ac();
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0,0x140,200,0);
    local_28 = 0;
    for (local_14 = 0; local_14 < 0x40; local_14 = local_14 + 1) {
      for (local_1c = 0; local_1c < 0x40; local_1c = local_1c + 1) {
        if ((((local_14 < 2) || (local_1c < 2)) || (0x3d < local_14)) || (0x3d < local_1c)) {
          Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,0);
        }
        else {
          iVar2 = (local_1c + local_14) * 3 + -0x20;
          iVar3 = (local_1c - local_14) * 3 + 100;
          if (((iVar2 < 4) || (iVar3 < 4)) || ((0x13b < iVar2 || (0xc3 < iVar3)))) {
            Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,0);
          }
          else {
            iVar2 = Pic_Subsystem_0044e864(local_14,local_1c);
            switch((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) {
            case 0:
            case 1:
              local_10 = 0;
              break;
            case 2:
              local_10 = 1;
              if (0x15 < iVar2) {
                local_10 = 8;
              }
              break;
            case 3:
              local_10 = 3;
              break;
            case 4:
              local_10 = 6;
              if (iVar2 < 0x22) {
                local_10 = 0xd;
              }
              break;
            case 5:
              if (0x2a < iVar2) goto switchD_0044d8a6_caseD_6;
              local_10 = 10;
              break;
            case 6:
switchD_0044d8a6_caseD_6:
              local_10 = 2;
              break;
            case 7:
              if (iVar2 < 0x3c) {
                local_10 = 0xf;
              }
              else {
                local_10 = 5;
              }
              break;
            case 8:
            case 9:
            case 10:
            case 0xb:
              local_10 = 5;
            }
            Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,local_10);
            if (local_10 != 0) {
              local_28 = local_28 + 1;
            }
          }
        }
      }
    }
    if (0x6d5 < local_28) {
      for (local_14 = 1; local_14 < 0x3f; local_14 = local_14 + 1) {
        for (local_1c = 1; local_1c < 0x3f; local_1c = local_1c + 1) {
          local_10 = Surface_GetPixelColor(local_14, local_1c);
          if (local_10 == 0) {
            bVar1 = false;
            for (local_18 = 1; local_18 < 9; local_18 = local_18 + 2) {
              iVar2 = Surface_GetPixelColor(*(int *)(&DAT_00522378 + local_18 * 4) + local_14,
                                   *(int *)(&DAT_005223e0 + local_18 * 4) + local_1c);
              if (iVar2 == 0) {
                bVar1 = true;
                break;
              }
            }
            if (!bVar1) {
              Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,6);
            }
          }
        }
      }
      Pic_Subsystem_0044e528();
      iVar2 = Pic_Subsystem_0044da25();
      if (iVar2 != 0) {
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

undefined4 Pic_Subsystem_0044da25(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int arg2;
  int iVar4;
  int iVar5;
  uint uVar6;
  sbyte sVar7;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_34;
  int local_30;
  int local_2c;
  int local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  local_48 = 0;
  do {
    local_48 = local_48 + 1;
    if (4 < local_48) {
      return 0;
    }
    local_4c = 0;
    local_8 = 0;
    local_10 = 0;
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      *(undefined4 *)(&DAT_005224e8 + local_2c * 0x10) = 0;
    }
    uVar2 = clock();
    uVar6 = (int)uVar2 >> 0x1f;
    local_c = ((uVar2 ^ uVar6) - uVar6 & 0x7f ^ uVar6) - uVar6;
    memset(&DAT_0067bdf0,0xff,0x3200);
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      local_44 = 0;
      do {
        bVar1 = false;
        iVar3 = Math_RandomRange(0x40);
        arg2 = Math_RandomRange(0x40);
        iVar4 = Surface_GetPixelColor(iVar3,arg2);
        if (iVar4 != 0) {
          local_40 = 0x7fff;
          local_18 = 0x7fff;
          for (local_34 = 0; (int)local_34 < 0x80; local_34 = local_34 + 1) {
            if (*(int *)(&DAT_0067bdf4 + local_34 * 100) != -1) {
              iVar5 = FUN_0040a36f(iVar3 - *(int *)(&DAT_0067bdf4 + local_34 * 100),
                                   arg2 - *(int *)(&DAT_0067bdf8 + local_34 * 100));
              if (iVar5 < local_40) {
                local_40 = iVar5;
              }
              if ((iVar5 < local_18) && (*(int *)(&DAT_0067bdf0 + local_34 * 100) == 3)) {
                local_18 = iVar5;
              }
            }
          }
          local_44 = local_44 + 1;
          if (7 - local_44 / 100 <= local_40) {
            bVar1 = true;
            *(int *)(&DAT_0067bdf4 + local_c * 100) = iVar3;
            *(int *)(&DAT_0067bdf8 + local_c * 100) = arg2;
            if (local_18 < 0x21) {
              if (local_40 < 0xb) {
                *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 1;
              }
              else {
                *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 2;
              }
            }
            else {
              *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 3;
            }
            *(undefined4 *)(&DAT_0067bdfc + local_c * 100) = 0;
            *(undefined4 *)(&DAT_0067be00 + local_c * 100) =
                 *(undefined4 *)(&DAT_0067bdfc + local_c * 100);
            for (local_34 = 0; (int)local_34 < 8; local_34 = local_34 + 1) {
              *(undefined4 *)(&DAT_0067be24 + local_34 * 4 + local_c * 100) = 0xfffffc18;
            }
            *(undefined4 *)(&DAT_0067be44 + local_c * 100) = 0xfffffc18;
            *(undefined4 *)(&DAT_0067be48 + local_c * 100) = 0xfffffc18;
            sVar7 = iVar4 == 3;
            if (iVar4 == 1) {
              sVar7 = 2;
            }
            if (iVar4 == 2) {
              sVar7 = 3;
            }
            if (iVar4 == 5) {
              sVar7 = 4;
            }
            if (iVar4 == 6) {
              sVar7 = 5;
            }
            if (((0x10 < local_18) && (sVar7 != 0)) && ((local_10 & 1 << sVar7) == 0)) {
              *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 4;
              local_10 = local_10 | 1 << sVar7;
            }
            uVar2 = Glue_Subsystem_004ea7a6(iVar4);
            if ((local_c != 0) &&
               ((*(int *)(&DAT_0067bdf0 + local_c * 100) == 3 ||
                (*(int *)(&DAT_0067bdf0 + local_c * 100) == 2)))) {
              for (local_34 = 0; (int)local_34 < 99; local_34 = local_34 + 1) {
                iVar4 = Math_RandomRange(10);
                iVar4 = iVar4 + 2;
                if ((*(int *)(&DAT_005224e8 + iVar4 * 0x10) == 0) &&
                   ((uVar2 & 1 << ((byte)(iVar4 / 2) & 0x1f)) != 0)) {
                  *(int *)(&DAT_005224e8 + iVar4 * 0x10) = local_c;
                  break;
                }
              }
              if (0x62 < (int)local_34) {
                iVar4 = Math_RandomRange(2);
                *(int *)(&DAT_005224e8 + iVar4 * 0x10) = local_c;
              }
              if (local_4c < 10) {
                *(uint *)(&DAT_0067be00 + local_c * 100) =
                     *(uint *)(&DAT_0067be00 + local_c * 100) | 1;
                local_4c = local_4c + 1;
              }
            }
            FUN_0040c81c(0x10,iVar3,arg2);
            uVar2 = local_c * 5 + 1;
            uVar6 = (int)uVar2 >> 0x1f;
            local_c = ((uVar2 ^ uVar6) - uVar6 & 0x7f ^ uVar6) - uVar6;
          }
        }
      } while (!bVar1);
      if (1 < *(int *)(&DAT_0067bdf0 + local_2c * 100)) {
        local_8 = local_8 + 1;
      }
    }
    bVar1 = true;
    if ((local_10 != 0x3e) || (local_8 < 0x1e)) {
      bVar1 = false;
    }
    for (local_30 = 0; local_30 < 6; local_30 = local_30 + 1) {
      do {
        do {
          iVar3 = Math_RandomRange(0x80);
        } while (*(int *)(&DAT_0067bdf0 + iVar3 * 100) < 2);
      } while ((*(int *)(&DAT_0067bdf0 + iVar3 * 100) == 4) ||
              (*(int *)(&DAT_0067bdfc + iVar3 * 100) != 0));
      *(int *)(&DAT_0067bdfc + iVar3 * 100) = 1 << ((byte)local_30 & 0x1f);
    }
    local_34 = Math_RandomRange(0xc);
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      if ((1 < *(int *)(&DAT_0067bdf0 + local_2c * 100)) &&
         (*(int *)(&DAT_0067bdf0 + local_2c * 100) < 4)) {
        if ((local_34 & 1) == 0) {
          *(int *)(&DAT_0067bdfc + local_2c * 100) = (((int)local_34 % 10) / 2 + 1) * 0x100;
        }
        else {
          *(int *)(&DAT_0067bdfc + local_2c * 100) = 1 << ((byte)(((int)local_34 % 0xc) / 2) & 0x1f)
          ;
        }
        local_34 = local_34 + 1;
      }
    }
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_005224e8 + local_2c * 0x10) == 0) {
        bVar1 = false;
      }
      if ((_DAT_0067f374 & 1 << ((byte)local_2c & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_005224e8 + local_2c * 0x10) = 0;
      }
    }
    if (bVar1) {
      return 1;
    }
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      FUN_0040c889(0x10,*(int *)(&DAT_0067bdf4 + local_2c * 100),
                   *(int *)(&DAT_0067bdf8 + local_2c * 100));
    }
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      *(undefined4 *)(&DAT_005224e8 + local_2c * 0x10) = 0;
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
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_1c = 0; local_1c < 0x80; local_1c = local_1c + 1) {
    for (local_28 = 0; local_28 < *(int *)(&DAT_0067bdf0 + local_1c * 100); local_28 = local_28 + 1)
    {
      local_8 = 0;
      do {
        local_24 = 0x7fff;
        for (local_18 = 0; local_18 < 0x2a; local_18 = local_18 + 1) {
          iVar1 = Math_RandomRange(0x80);
          iVar2 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_1c * 100) -
                               *(int *)(&DAT_0067bdf4 + iVar1 * 100),
                               *(int *)(&DAT_0067bdf8 + local_1c * 100) -
                               *(int *)(&DAT_0067bdf8 + iVar1 * 100));
          if (iVar2 < local_24) {
            local_10 = local_c;
            local_24 = iVar2;
            local_c = iVar1;
          }
        }
        iVar1 = Pic_Subsystem_0044e2e7
                          (*(int *)(&DAT_0067bdf4 + local_1c * 100),
                           *(int *)(&DAT_0067bdf8 + local_1c * 100),
                           *(int *)(&DAT_0067bdf4 + local_10 * 100),
                           *(int *)(&DAT_0067bdf8 + local_10 * 100));
      } while ((iVar1 == 0) && (local_8 = local_8 + 1, local_8 < 3));
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044e2e7
 * Entry Point: 0044e2e7
 * Size: 577 bytes
 */


undefined4 Pic_Subsystem_0044e2e7(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  int arg2;
  int iVar3;
  uint uVar4;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_8;
  
  local_1c = x;
  local_20 = y;
  local_34 = 0;
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,0,0x40,0x80,(int *)g_DisplaySurfaceWork,0x40,0);
  FUN_0040c81c(0x20,x,y);
  do {
    iVar1 = FUN_0040a36f(width - local_1c,height - local_20);
    local_30 = -1;
    local_2c = 0x7fff;
    for (local_24 = 1; local_24 < 9; local_24 = local_24 + 1) {
      iVar2 = *(int *)(&DAT_00522378 + local_24 * 4) + local_1c;
      arg2 = *(int *)(&DAT_005223e0 + local_24 * 4) + local_20;
      iVar3 = Surface_GetPixelColor(iVar2,arg2);
      if ((iVar3 != 0) && (local_8 = FUN_0040a36f(width - iVar2,height - arg2), local_8 < iVar1)) {
        if ((iVar3 == 2) || (iVar3 == 0xb)) {
          local_8 = local_8 + 1;
        }
        if ((iVar3 == 4) || (iVar3 == 5)) {
          local_8 = local_8 + 4;
        }
        uVar4 = FUN_0040c7c0(iVar2,arg2);
        if (((uVar4 & 0x20) != 0) && (0 < local_34)) {
          local_8 = local_8 + -4;
        }
        if (local_8 < local_2c) {
          local_2c = local_8;
          local_30 = local_24;
        }
      }
    }
    if (local_30 == -1) {
      Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0x40,0,0x40,0x80,(int *)g_DisplaySurfaceWork,0,0);
      return 0;
    }
    iVar1 = *(int *)(&DAT_00522378 + local_30 * 4) + local_1c;
    iVar2 = *(int *)(&DAT_005223e0 + local_30 * 4) + local_20;
    uVar4 = FUN_0040c7c0(iVar1,iVar2);
    FUN_0040ca43(local_1c,local_20,local_30);
    if (((uVar4 & 0x20) != 0) && (0 < local_34)) {
      return 1;
    }
    local_34 = local_34 + 1;
    local_20 = iVar2;
    local_1c = iVar1;
  } while ((iVar1 != width) || (iVar2 != height));
  return 1;
}



/*
 * Decompiled function: Pic_Subsystem_0044e528
 * Entry Point: 0044e528
 * Size: 565 bytes
 */


void Pic_Subsystem_0044e528(void)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  Surface_PutPixel((int *)g_DisplaySurfaceWork,0xa8,0x58,0xff);
  do {
    bVar1 = false;
    for (local_10 = 4; local_10 < 0x40; local_10 = local_10 + 4) {
      for (local_14 = 4; local_14 < 0x40; local_14 = local_14 + 4) {
        iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_10 + 0x80,local_14 + 0x40);
        if (iVar2 != 0) {
          Surface_FillRect((int *)g_DisplaySurfaceWork,0x40,0,0x40,0x40,0);
          Pic_Subsystem_0044e75d(local_10,local_14,8);
          Surface_PutPixel((int *)g_DisplaySurfaceWork,local_10 + 0x80,local_14 + 0x40,0);
          for (local_18 = 0; local_18 < 0x40; local_18 = local_18 + 1) {
            for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
              iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_18 + 0x40,local_8);
              if ((iVar2 != 0) &&
                 (iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_18 + 0x80,local_8),
                 iVar2 == 0)) {
                bVar1 = true;
                Surface_PutPixel((int *)g_DisplaySurfaceWork,local_18 + 0x80,local_8,0xff);
                Surface_PutPixel((int *)g_DisplaySurfaceWork,local_18 + 0x80,local_8 + 0x40,0xff);
              }
            }
          }
        }
      }
    }
  } while (bVar1);
  for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < 0x40; local_14 = local_14 + 1) {
      iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_10 + 0x80,local_14);
      if (iVar2 == 0) {
        Surface_PutPixel((int *)g_DisplaySurfaceWork,local_10,local_14,0);
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


void Pic_Subsystem_0044e75d(int player,int card_slot,int arg_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char local_10;
  
  Surface_PutPixel((int *)g_DisplaySurfaceWork,player + 0x40,card_slot,arg_3);
  if (1 < arg_3) {
    for (local_10 = '\x01'; local_10 < '\t'; local_10 = local_10 + '\x02') {
      cVar1 = (char)*(undefined4 *)(&DAT_00522378 + local_10 * 4) + (char)player;
      cVar2 = (char)*(undefined4 *)(&DAT_005223e0 + local_10 * 4) + (char)card_slot;
      cVar3 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,cVar1 + 0x40,(int)cVar2);
      if ((cVar3 < arg_3) &&
         (iVar4 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,(int)cVar1,(int)cVar2), iVar4 != 0))
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
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = abs(arg2 + -0x20);
  iVar2 = abs(arg1 + -0x20);
  iVar1 = (iVar1 + iVar2) * (iVar1 + iVar2);
  iVar2 = abs(arg1 - arg2);
  iVar3 = Pic_Subsystem_0044eb9d(arg1 << 5,arg2 << 5);
  iVar4 = Pic_Subsystem_0044eb9d(arg1 << 8,arg2 << 8);
  iVar5 = Pic_Subsystem_0044eb9d(arg1 << 9,arg2 << 9);
  iVar1 = Math_Clamp(((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9) +
                       ((int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4),0,0xc);
  iVar1 = (iVar3 * 4 + iVar4 * 2 + iVar5 + iVar1 * -0x200) * 7;
  iVar1 = iVar1 + (iVar1 >> 0x1f & 0x3fU);
  Math_Clamp((int)((iVar1 >> 6) + (iVar1 >> 0x1f & 3U)) >> 2,0,100);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0044e9ac
 * Entry Point: 0044e9ac
 * Size: 497 bytes
 */


void Pic_Subsystem_0044e9ac(void)

{
  undefined1 uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x12; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x12; local_10 = local_10 + 1) {
      uVar1 = Math_RandomRange(0x10);
      (&DAT_0067a6c0)[local_10 + local_8 * 0x13] = uVar1;
    }
    (&DAT_0067a6d2)[local_8 * 0x13] = (&DAT_0067a6c0)[local_8 * 0x13];
  }
  for (local_10 = 0; local_10 < 0x12; local_10 = local_10 + 1) {
    (&DAT_0067a816)[local_10] = (&DAT_0067a6c0)[local_10];
  }
  for (local_8 = 0; local_8 < 0x11; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x11; local_10 = local_10 + 1) {
      for (local_c = 1; local_c < 9; local_c = local_c + 1) {
      }
      (&DAT_0067a830)[local_10 + local_8 * 0x13] = (&DAT_0067a6c0)[local_10 + local_8 * 0x13];
    }
  }
  for (local_8 = 0; local_8 < 0x11; local_8 = local_8 + 1) {
    (&DAT_0067a840)[local_8 * 0x13] = (&DAT_0067a830)[local_8 * 0x13];
  }
  for (local_10 = 0; local_10 < 0x11; local_10 = local_10 + 1) {
    (&DAT_0067a960)[local_10] = (&DAT_0067a830)[local_10];
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
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = arg1 - 0x80U >> 8 & 0xf;
  uVar3 = (arg1 - 0x80U & 0xff) >> 3;
  uVar4 = arg2 - 0x80U >> 8 & 0xf;
  uVar5 = (arg2 - 0x80U & 0xff) >> 3;
  iVar1 = (int)(char)(&DAT_0067a830)[uVar2 * 0x13 + uVar4] * (0x20 - uVar5) * (0x20 - uVar3) +
          (int)(char)(&DAT_0067a830)[uVar4 + (uVar2 + 1) * 0x13] * (0x20 - uVar5) * uVar3 +
          (int)(char)(&DAT_0067a831)[uVar4 + uVar2 * 0x13] * (0x20 - uVar3) * uVar5 +
          (int)(char)(&DAT_0067a831)[uVar4 + (uVar2 + 1) * 0x13] * uVar5 * uVar3;
  return (int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5;
}



/*
 * Decompiled function: Pic_Subsystem_0044eca0
 * Entry Point: 0044eca0
 * Size: 341 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pic_Subsystem_0044eca0(void)

{
  size_t sVar1;
  char *pcVar2;
  
  DAT_00695e98 = 0xd;
  strcpy(&DAT_00538c20,s___SVG_00523b70);
  strcpy(&DAT_00538c30,s_MTG_Gauntlet_Save_Game_00523b78);
  pcVar2 = &DAT_00538c20;
  sVar1 = strlen(&DAT_00538c30);
  strcat((char *)(sVar1 + 0x538c31),pcVar2);
  pcVar2 = &DAT_00523b90;
  sVar1 = strlen(&DAT_00538c30);
  strcat((char *)(sVar1 + 0x538c31),pcVar2);
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
  _DAT_006a288c = &DAT_006a28c0;
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
 * Decompiled function: Pic_Subsystem_0044edf5
 * Entry Point: 0044edf5
 * Size: 270 bytes
 */


void Pic_Subsystem_0044edf5(undefined4 player)

{
  undefined4 uVar1;
  char local_10c [264];
  
  uVar1 = g_ScWillyScore;
  if (((byte)DAT_006fe410 & 1) == 0) {
    g_ScWillyScore = player;
    strcpy(local_10c,&DAT_006a28c0);
    strcat(local_10c,s__AUTOSAVE_00523ba0);
    strcat(local_10c,&DAT_00538c21);
    FUN_0048e122(local_10c);
  }
  if ((((byte)DAT_006fe410 & 1) != 0) && (DAT_0068a718 != 0)) {
    g_ScWillyScore = player;
    strcpy(local_10c,&DAT_006a28c0);
    strcat(local_10c,s__SHANDSAVE_00523bac);
    strcat(local_10c,&DAT_00538c21);
    FUN_0048e122(local_10c);
  }
  g_ScWillyScore = uVar1;
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
  
  strcpy(local_10c,&DAT_006a28c0);
  strcat(local_10c,s__AUTOSAVE_00523bb8);
  strcat(local_10c,&DAT_00538c21);
  CopyFileA(local_10c,str_1,0);
  return;
}



/*
 * Decompiled function: Pic_Load_0044ef70
 * Entry Point: 0044ef70
 * Size: 607 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0044f1b3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Load_0044ef70(undefined4 arg1,LPVOID out_buffer)

{
  int nPriority;
  HANDLE hHandle;
  int local_10;
  DWORD local_c [2];
  
  _DAT_0063ee14 = 1;
  Palette_Subsystem_00496eaf();
  local_c[1] = 2;
  nPriority = GetThreadPriority(DAT_00626820);
  SetThreadPriority(DAT_00626820,-0xf);
  hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,Palette_Subsystem_004958b1,out_buffer,0,
                         local_c);
  WaitForSingleObject(hHandle,0xffffffff);
  GetExitCodeThread(hHandle,local_c + 1);
  CloseHandle(hHandle);
  SetThreadPriority(DAT_00626820,nPriority);
  if (DAT_0063ee80 == 0) {
    for (local_10 = 0; local_10 < 500; local_10 = local_10 + 1) {
      if (*(int *)(&deck + local_10 * 4) != -1) {
        *(uint *)(&deck + local_10 * 4) = *(uint *)(&deck + local_10 * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_00523dfc);
  }
  DAT_00522454 = 0xffffffff;
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  g_IsAiThinking = 0;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    *(undefined4 *)(&g_PlayerLifeTotals + local_10 * 4) = 8;
  }
  if (DAT_0067a6b0 != 0) {
    memcpy(&deck,&DAT_00679ee0,2000);
  }
  DAT_0063ee18 = 0;
  _DAT_0063ee14 = 1;
  DAT_006a5f20 = 0;
  DAT_006a48e0 = 0;
  DAT_006ff2d8 = 0xffffffff;
  g_ScWillyScore = 0;
  ShowWindow(_hwndScreen,5);
  SetForegroundWindow(_hwndScreen);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_00523e18);
  Catalog_LoadPaletteMap(s_todpal_tr_00523e28,(char *)0x0);
  SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  Glue_Sound_004ec32f();
  DAT_00627a7c = 0;
  DAT_00522454 = 0xffffffff;
  return DAT_00627a80;
}



/*
 * Decompiled function: Pic_Subsystem_0044f1de
 * Entry Point: 0044f1de
 * Size: 5427 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0044f701) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0044f1de(undefined4 arg1,int arg2)

{
  int iVar1;
  uint player;
  undefined4 uVar2;
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
  int local_20;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (((byte)DAT_006fe410 & 1) == 0) {
    arg2 = -1;
  }
  Glue_Subsystem_004ebebf();
  FUN_0040a1ff();
  DAT_0063ee18 = 1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
      *(undefined4 *)(&g_ActiveCardsInPlay + local_8 * 0x5b20 + local_1c * 0x120) = 0xffffffff;
      *(undefined4 *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_1c * 0x120) =
           *(undefined4 *)(&g_ActiveCardsInPlay + local_8 * 0x5b20 + local_1c * 0x120);
    }
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      *(undefined4 *)(&DAT_006b1590 + local_1c * 4 + local_8 * 2000) = 0xffffffff;
      *(undefined4 *)(&DAT_006ff710 + local_1c * 4 + local_8 * 2000) =
           *(undefined4 *)(&DAT_006b1590 + local_1c * 4 + local_8 * 2000);
    }
    *(undefined4 *)(&DAT_006ff4b8 + local_8 * 4) = 0;
    (&g_PlayerActiveCardCount)[local_8] = 0;
  }
  DAT_006ff2c0 = 0xef;
  DAT_006ff2c4 = 0x7e;
  DAT_006ff2c8 = 0x5b;
  DAT_006ff2cc = 0xa4;
  DAT_006ff2d0 = 0xbc;
  FUN_0046f300();
  FUN_0047643e();
  if (arg2 == -1) {
    DAT_006a4a04 = 0x14;
    g_PlayerCreatureCount = 0x14;
    Ai_Subsystem_004b6f49(&DAT_00695e10);
    local_2c = 7;
    DAT_00627a14 = 0;
    DAT_00696a18 = 1;
    DAT_006b2d64 = -1;
    FUN_0040a2c0();
    if (((DAT_0067f380 == 0) || (iVar1 = Math_RandomRange(2), iVar1 == 0)) || (g_IsAiThinking != 0)) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
    local_28 = 1;
    DAT_006a2858 = 1;
    if (DAT_0068a648 == 0) {
      for (local_54 = 0; local_54 < 0x3c; local_54 = local_54 + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_54 * 4) = 0;
        *(undefined4 *)(&DAT_0069e730 + local_54 * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_54 * 4);
      }
      for (local_54 = 0x3c; local_54 < 500; local_54 = local_54 + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_54 * 4) = 0xffffffff;
        *(undefined4 *)(&DAT_0069e730 + local_54 * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_54 * 4);
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      for (local_54 = 0; local_54 < 0x10; local_54 = local_54 + 1) {
        (&DAT_006b2dd0)[local_54] = 0xffffffff;
        (&DAT_006b2d90)[local_54] = (&DAT_006b2dd0)[local_54];
      }
      if (DAT_006feeb8 != 0) {
        DAT_006b2d90 = FUN_0040a02a(DAT_0052effc);
        DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
      }
      for (local_54 = 0; local_54 < 7; local_54 = local_54 + 1) {
        iVar1 = FUN_0040a02a(DAT_0052effc);
        Pic_Subsystem_00451291(0,iVar1);
        iVar1 = FUN_0040a02a(DAT_0052eff8);
        Pic_Subsystem_00451291(1,iVar1);
      }
      Pic_Subsystem_00450711(&local_18,&local_34,&local_20);
      for (local_50 = 0; local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = DAT_0052effc;
        }
        else {
          local_60 = DAT_0052eff8;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < *(int *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280);
                local_58 = local_58 + 1) {
              *(undefined4 *)(&DAT_0069e730 + local_5c * 4 + local_50 * 2000) = 0;
              local_5c = local_5c + 1;
            }
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(undefined4 *)(&DAT_0069e730 + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      Ai_AssignCombatDamage
                (&local_10,(uint *)(local_4c + 5),local_10,local_28,DAT_006b2dd0,DAT_006b2d90,
                 local_18,local_34,local_20);
      if (local_4c[5] != 0) {
        Pic_Subsystem_0045083f(0,DAT_0052effc);
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (local_20 != 0)))) {
        Pic_Subsystem_0045083f(1,DAT_0052eff8);
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      for (local_50 = 0; iVar1 = g_IsAiThinking, local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = DAT_0052effc;
        }
        else {
          local_60 = DAT_0052eff8;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < *(int *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280);
                local_58 = local_58 + 1) {
              uVar2 = CardTypeFromID
                                (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280));
              *(undefined4 *)(&DAT_0069e730 + local_5c * 4 + local_50 * 2000) = uVar2;
              local_5c = local_5c + 1;
            }
            *(undefined4 *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280) = 0;
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(undefined4 *)(&DAT_0069e730 + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      DAT_0052effc = -1;
      g_IsAiThinking = 1;
      Pic_Subsystem_00452276(0);
      Pic_Subsystem_00452276(1);
      g_IsAiThinking = iVar1;
    }
  }
  else {
    local_4c[4] = 0;
    local_4c[0] = 0x1e;
    local_4c[1] = 0x23;
    local_4c[2] = 0x28;
    local_4c[3] = 0x28;
    g_PlayerCreatureCount = 10;
    if ((_DAT_0067f374 & 2) != 0) {
      g_PlayerCreatureCount = 0xc;
    }
    if ((_DAT_0067f374 & 0x800) != 0) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + 3;
    }
    if ((_DAT_0067f374 & 0x80) != 0) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + 5;
    }
    iVar1 = Minit_Subsystem_00452827();
    g_PlayerCreatureCount = iVar1 + DAT_00627a7c;
    g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_006498fc;
    if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_00522454;
    }
    DAT_00627868 = g_PlayerCreatureCount;
    DAT_00627a7c = 0;
    DAT_006a4a04 = (int)(char)(&DAT_00522628)[arg2 * 0x44];
    if ((arg2 < 0x25) && (arg2 % 7 != 0)) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 2;
    }
    else if ((arg2 < 0x25) && (arg2 % 7 == 0)) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 5;
    }
    else if (arg2 < 0x37) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 2;
    }
    else if (0x36 < arg2) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 0x32;
    }
    if ((&DAT_0052262a)[arg2 * 0x44] == '\v') {
      for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
        if ((_DAT_0067f374 & 1 << ((byte)local_1c & 0x1f)) != 0) {
          DAT_006a4a04 = DAT_006a4a04 + 1;
        }
      }
    }
    iVar1 = DAT_006a4a04;
    if ((&DAT_0052262a)[arg2 * 0x44] == '\f') {
      DAT_006a4a04 = DAT_006a4a04 + 10;
      local_30 = 0;
      local_c = 0;
      for (local_1c = 0; (local_1c < 1000 && ((&DAT_0067b9b0)[local_1c] != '\0'));
          local_1c = local_1c + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_1c] >> 4 == DAT_006b2d64) {
          local_30 = local_30 + 1;
        }
      }
      DAT_006a4a04 = DAT_006a4a04 - local_30;
      for (local_24 = 0; local_24 < 0x80; local_24 = local_24 + 1) {
        if (((&DAT_0067be01)[local_24 * 100] != '\0') &&
           ((*(int *)(&DAT_0067be00 + local_24 * 100) >> 8) + -1 == local_1c)) {
          local_c = local_c + 1;
        }
      }
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * local_c;
      iVar1 = DAT_0067f380 * 5 + 0x14;
      if (iVar1 <= DAT_006a4a04) {
        iVar1 = DAT_006a4a04;
      }
    }
    DAT_006a4a04 = iVar1;
    if ((&DAT_0052262a)[arg2 * 0x44] == '\r') {
      DAT_006a4a04 = DAT_0067f380 * 100 + 100;
    }
    g_OverworldWorldState = 0;
    Glue_Subsystem_004eaa19(arg2,0,0);
    strcpy(&DAT_00695e10,&g_OverworldWorldState);
    Math_Clamp(DAT_0067f380 + DAT_00695df0 + 4,0,99);
    local_2c = 7;
    DAT_00627a14 = 0;
    FUN_0040a2c0();
    if (((DAT_0067f380 == 0) || (iVar1 = Math_RandomRange(2), iVar1 == 0)) || (g_IsAiThinking != 0)) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
    local_28 = 1;
    DAT_006a2858 = 1;
    if ((DAT_0067a6b4 != 0) || (DAT_00522454 == 0)) {
      if (DAT_0067a6b4 == 0) {
        local_10 = 0;
      }
      else {
        local_10 = 1;
      }
      local_10 = (uint)(DAT_0067a6b4 != 0);
      local_28 = 0;
      DAT_006a2858 = 0;
      DAT_0067a6b4 = 0;
    }
    if (g_IsAiThinking == 0) {
      DAT_0067a6b0 = 0;
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if ((*(int *)(&deck + local_1c * 4) != -1) && (((&DAT_00702151)[local_1c * 4] & 0x40) == 0))
        {
          local_4c[4] = local_4c[4] + 1;
        }
      }
      if (local_4c[4] < local_4c[DAT_0067f380]) {
        DAT_0067a6b0 = 1;
        memcpy(&DAT_00679ee0,&deck,2000);
        for (local_1c = 0; local_1c < local_4c[DAT_0067f380] - local_4c[4]; local_1c = local_1c + 1)
        {
          player = Math_RandomRange(5);
          Pic_Subsystem_00451e40(player);
        }
      }
      for (local_1c = 0; local_1c < 0x3c; local_1c = local_1c + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_1c * 4) = 0;
        *(undefined4 *)(&DAT_0069e730 + local_1c * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_1c * 4);
      }
      for (local_1c = 0x3c; local_1c < 500; local_1c = local_1c + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_1c * 4) = 0xffffffff;
        *(undefined4 *)(&DAT_0069e730 + local_1c * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_1c * 4);
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if ((*(uint *)(&deck + local_1c * 4) & 0xfff) == DAT_006b2d90) {
          *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) | 0x8000;
          break;
        }
      }
      for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
        if (DAT_0052effc == -1) {
          iVar1 = Pic_Subsystem_00451cb2();
          Pic_Subsystem_00451291(0,iVar1);
        }
        else {
          iVar1 = FUN_0040a02a(DAT_0052effc);
          Pic_Subsystem_00451291(0,iVar1);
        }
      }
      if (DAT_0052eff8 != -1) {
        if ((DAT_0052effc == -1) && (FUN_00409eb0(DAT_0052eff8), DAT_006b2dd0 != -1)) {
          FUN_00409f16(0,DAT_006b2dd0);
        }
        for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
          iVar1 = FUN_0040a02a((uint)(DAT_0052effc != -1));
          Pic_Subsystem_00451291(1,iVar1);
        }
      }
      Pic_Subsystem_00450711(&local_18,&local_34,&local_20);
      Ai_AssignCombatDamage
                (&local_10,(uint *)(local_4c + 5),local_10,local_28,DAT_006b2dd0,DAT_006b2d90,
                 local_18,local_34,local_20);
      if (local_4c[5] != 0) {
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          *(undefined4 *)(&g_CardSlot_CardId + local_1c * 0x120) = 0xffffffff;
          *(undefined4 *)(&g_ActiveCardsInPlay + local_1c * 0x120) = 0xffffffff;
        }
        for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
          if (*(int *)(&deck + local_1c * 4) != -1) {
            *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) & 0xffff7fff;
          }
        }
        for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
          if ((*(uint *)(&deck + local_1c * 4) & 0xfff) == DAT_006b2d90) {
            *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) | 0x8000;
            break;
          }
        }
        for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
          if (DAT_0052effc == -1) {
            iVar1 = Pic_Subsystem_00451cb2();
            Pic_Subsystem_00451291(0,iVar1);
          }
          else {
            iVar1 = FUN_0040a02a(DAT_0052effc);
            Pic_Subsystem_00451291(0,iVar1);
          }
        }
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (local_20 != 0)))) {
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          *(undefined4 *)(&DAT_006aba54 + local_1c * 0x120) = 0xffffffff;
          *(undefined4 *)(&DAT_006aba50 + local_1c * 0x120) = 0xffffffff;
        }
        if ((DAT_0052effc == -1) && (FUN_00409eb0(DAT_0052eff8), DAT_006b2dd0 != -1)) {
          FUN_00409f16(0,DAT_006b2dd0);
        }
        for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
          iVar1 = FUN_0040a02a((uint)(DAT_0052effc != -1));
          Pic_Subsystem_00451291(1,iVar1);
        }
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      if (DAT_0052effc == -1) {
        DAT_0052eff8 = 0;
      }
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if (DAT_0052effc == -1) {
          uVar2 = Pic_Subsystem_00451cb2();
          *(undefined4 *)(&DAT_0069e730 + local_1c * 4) = uVar2;
        }
        else {
          uVar2 = FUN_0040a02a(DAT_0052effc);
          *(undefined4 *)(&DAT_0069e730 + local_1c * 4) = uVar2;
        }
        uVar2 = FUN_0040a02a(DAT_0052eff8);
        *(undefined4 *)(&DAT_0069ef00 + local_1c * 4) = uVar2;
      }
      DAT_0052effc = -1;
      if ((((&DAT_00522638)[arg2 * 0x44] & 2) != 0) && (DAT_0067f37c % 3 == 0)) {
        memcpy(&DAT_0069ef00,&DAT_0069e730,1000);
        local_1c = g_IsAiThinking;
        g_IsAiThinking = 1;
        Pic_Subsystem_00452276(1);
        g_IsAiThinking = local_1c;
        memcpy(&DAT_006aba50,&g_ActiveCardsInPlay,0x5b20);
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          if (*(int *)(&DAT_006aba54 + local_1c * 0x120) != -1) {
            *(uint *)(&DAT_006aba5c + local_1c * 0x120) =
                 *(uint *)(&DAT_006aba5c + local_1c * 0x120) | 0x1000;
          }
        }
        DAT_00627a14 = 0;
      }
      if (DAT_006b2fe0 != -1) {
        local_1c = Pic_Subsystem_00451291(1,DAT_006b2fe0);
        if (local_1c != -1) {
          *(uint *)(&DAT_006aba5c + local_1c * 0x120) =
               *(uint *)(&DAT_006aba5c + local_1c * 0x120) | 0x30002;
        }
        DAT_006b2fe0 = -1;
        if (DAT_00522454 == -1) {
          DAT_00522454 = 0;
        }
      }
      if (DAT_0068a64c != -1) {
        local_1c = Pic_Subsystem_00451291(1,DAT_0068a64c);
        Pic_Subsystem_0042ac1f(1,local_1c);
        DAT_0068a64c = -1;
        if (DAT_00522454 == -1) {
          DAT_00522454 = 0;
        }
      }
      if (5 < DAT_00522454) {
        local_1c = Pic_Subsystem_00451291(0,DAT_00522454);
        Pic_Subsystem_0042ac1f(0,local_1c);
      }
    }
  }
  FUN_0046f300();
  if (g_IsAiThinking == -1) {
    FUN_0048c72a(0);
  }
  if (g_IsAiThinking == -2) {
    FUN_0048c72a(1);
  }
  Pic_Subsystem_0044b8aa();
  if (g_IsAiThinking == -10) {
    FUN_0048e1bf(DAT_006a287c);
    Ai_Subsystem_004cc9c5(0,0xff);
    local_14 = g_TurnPlayer;
  }
  else if (g_IsAiThinking == -1) {
    DAT_006a4b58 = 0;
    Ai_Subsystem_004cc9c5(0,0xff);
    local_14 = 1;
  }
  else if (g_IsAiThinking == -2) {
    DAT_006a4b58 = 0;
    Ai_Subsystem_004cc9c5(0,0xff);
    local_14 = 0;
  }
  else {
    DAT_006a4b58 = 1;
    local_14 = local_10;
  }
  while ((DAT_006fe3f0 == 0 && (iVar1 = FUN_005062b1(), iVar1 == 0))) {
    if (DAT_007006d4 == 0) {
      FUN_00501f50(local_14);
      local_14 = 1 - local_14;
    }
    else {
      if ((DAT_007006d4 & 1) == 0) {
        DAT_007006d4 = 0;
        if (local_14 == 0) {
          DAT_006ff2d8 = 0xffffffff;
        }
        FUN_00501f50(1);
      }
      else {
        DAT_007006d4 = 0;
        if (local_14 == 1) {
          DAT_006ff2d8 = 0xffffffff;
        }
        FUN_00501f50(0);
      }
      DAT_006ff2d8 = 0xffffffff;
    }
  }
  Pic_Subsystem_0044b8da();
  if (DAT_0063ee80 == 0) {
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      if (*(int *)(&deck + local_1c * 4) != -1) {
        *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_00523e34);
  }
  DAT_00522454 = 0xffffffff;
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  g_IsAiThinking = 0;
  for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
    *(undefined4 *)(&g_PlayerLifeTotals + local_1c * 4) = 8;
  }
  DAT_0063ee18 = 0;
  _DAT_0063ee14 = 1;
  if (((g_PlayerCreatureCount < 1) || (9 < DAT_00696870)) ||
     ((0 < DAT_006a4a04 && (DAT_00696874 < 10)))) {
    if (((DAT_006a4a04 < 1) || (9 < DAT_00696874)) ||
       ((0 < g_PlayerCreatureCount && (DAT_00696870 < 10)))) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/*
 * Decompiled function: Pic_Subsystem_00450711
 * Entry Point: 00450711
 * Size: 302 bytes
 */


void Pic_Subsystem_00450711(undefined4 *player,undefined4 *card_slot,undefined4 *arg_3)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  for (local_10 = 0; local_10 < 7; local_10 = local_10 + 1) {
    if (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + local_10 * 0x120) * 0x34] & 1) != 0) {
      local_8 = local_8 + 1;
    }
    if (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + local_10 * 0x120) * 0x34] & 1) != 0
       ) {
      local_c = local_c + 1;
    }
  }
  if (local_c == 0) {
    *player = 1;
  }
  else if (local_c == 7) {
    *player = 2;
  }
  else {
    *player = 0;
  }
  if (local_8 == 0) {
    *card_slot = 1;
  }
  else if (local_8 == 7) {
    *card_slot = 2;
  }
  else {
    *card_slot = 0;
  }
  if ((local_8 < 2) || (5 < local_8)) {
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
  bool bVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
    if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120) != -1) {
      bVar1 = false;
      local_10 = 0;
      while ((local_10 < 0x50 && (!bVar1))) {
        iVar2 = CardTypeFromID(*(int *)(&DAT_00516cb8 + local_10 * 8 + arg2 * 0x280));
        if (iVar2 == *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120)) {
          *(int *)(&DAT_00516cbc + local_10 * 8 + arg2 * 0x280) =
               *(int *)(&DAT_00516cbc + local_10 * 8 + arg2 * 0x280) + 1;
          bVar1 = true;
        }
        local_10 = local_10 + 1;
      }
      *(undefined4 *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120) = 0xffffffff;
    }
  }
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    iVar2 = FUN_0040a02a(arg2);
    Pic_Subsystem_00451291(arg1,iVar2);
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
               (int player,int *card_slot,int arg_3,int arg_4,undefined4 arg_5,int arg_6,char *arg_7)

{
  if ((player == 0) && (g_IsAiThinking != 1)) {
    Ai_Subsystem_004cc49a(card_slot,arg_3,arg_4,arg_5,arg_6,arg_7);
  }
  return;
}



/*
 * Decompiled function: Pic_Load_004509e8
 * Entry Point: 004509e8
 * Size: 2212 bytes
 */


int Pic_Load_004509e8(int player,int card_slot,int arg_3,undefined4 arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  char *in_stack_00000018;
  int local_1800;
  void *local_17fc;
  undefined4 local_17f8;
  undefined4 local_17f4;
  undefined4 auStackY_17f0 [6];
  undefined4 auStackY_17d8 [4];
  undefined4 auStackY_17c8 [6];
  undefined4 local_17b0;
  void *apvStackY_17ac [4];
  int local_179c;
  undefined4 local_1798;
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
  undefined4 uStackY_3c;
  int *piVar6;
  void *arg_6;
  int iVar7;
  
  Mem_AllocOrFree_00513bd0();
  if ((g_CurrentTurnPhase == player) && (g_IsAiThinking != 1)) {
    if (DAT_0063ee18 == 0) {
      Catalog_LoadPaletteMap(s_todpal_tr_00523e50,(char *)0x0);
      FUN_0050d560(0,0);
      SelectPalette(_hdcScreen,DAT_00626834,0);
      LoadPalNoPic(s_advfac64_pic_00523e5c);
      FUN_00510b70(1,0,0,s_seedeck_pic_00523e6c,(short *)&DAT_0070a130);
      uStackY_3c = 0x450b44;
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
      local_1788 = 0;
      for (iVar7 = 0; iVar7 < arg_3; iVar7 = iVar7 + 1) {
        if ((*(int *)(card_slot + iVar7 * 4) != -1) &&
           ((iVar7 == 0 || (*(int *)(card_slot + -4 + iVar7 * 4) != *(int *)(card_slot + iVar7 * 4))))) {
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
      for (iVar7 = 0; iVar7 < arg_3; iVar7 = iVar7 + 1) {
        if ((*(int *)(card_slot + iVar7 * 4) != -1) &&
           ((iVar7 == 0 || (*(int *)(card_slot + -4 + iVar7 * 4) != *(int *)(card_slot + iVar7 * 4))))) {
          aiStackY_fb4[local_7dc] = local_7e0 + 4;
          aiStackY_1784[local_7dc] = local_7e4;
          aiStackY_7d8[local_7dc] = iVar7;
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
      for (iVar7 = 0; iVar7 < local_7dc; iVar7 = iVar7 + 1) {
        FUN_0050b206(*(uint *)(card_slot + aiStackY_7d8[iVar7] * 4) & 0xfff,aiStackY_fb4[iVar7],
                     aiStackY_1784[iVar7],0,&DAT_00523e88);
      }
      while( true ) {
        do {
          Pic_Subsystem_0044b84b();
          local_178c = -1;
          DAT_0067bda4 = (DAT_0067bda4 * 0x140) / g_DisplayScreenWidth;
          DAT_0067bda8 = (DAT_0067bda8 * 0xf0) / g_DisplayScreenHeight;
          for (iVar7 = 0; iVar7 < local_7dc; iVar7 = iVar7 + 1) {
            if ((((aiStackY_fb4[iVar7] <= DAT_0067bda4) &&
                 (DAT_0067bda4 < aiStackY_fb4[iVar7] + 0x30)) &&
                (aiStackY_1784[iVar7] <= DAT_0067bda8)) &&
               (DAT_0067bda8 < aiStackY_1784[iVar7] + 0x30)) {
              local_178c = aiStackY_7d8[iVar7];
            }
          }
          if ((local_178c != -1) &&
             (*(int *)(card_slot + local_179c * 4) != *(int *)(card_slot + local_178c * 4))) {
            FUN_0050b206(*(uint *)(card_slot + local_178c * 4) & 0xfff,8,0x40,1,&DAT_00523e8c);
            local_179c = local_178c;
          }
          if (arg_5 == 0) {
            if ((DAT_0067bda0 == 0) && (iVar7 = Mem_AllocOrFree_00408089(), iVar7 == 0)) {
              local_1794 = 0;
            }
            else {
              local_1794 = 1;
            }
          }
          else if (((DAT_0067bda0 == 0) && (iVar7 = Mem_AllocOrFree_00408089(), iVar7 == 0)) ||
                  (local_178c == -1)) {
            local_1794 = 0;
          }
          else {
            local_1794 = 1;
          }
        } while (local_1794 == 0);
        if (arg_5 == 0) break;
        iVar7 = Ai_Util_004c3ba3(0x34);
        iVar7 = iVar7 / 2;
        iVar1 = Ai_Util_004c3ba3(0xdc);
        iVar1 = iVar1 / 2;
        piVar6 = (int *)g_DisplaySurfaceBackBuffer;
        iVar2 = Ai_Util_004c3ba3(0x111);
        DVar3 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0xc5);
        uVar4 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0x34);
        iVar2 = iVar2 / 2;
        iVar5 = Ai_Util_004c3ba3(0xdc);
        Surface_BlitToDevice((int *)g_DisplaySurfaceScreen,iVar5 / 2,iVar2,uVar4,DVar3,piVar6,iVar1,iVar7);
        strcpy(&g_OverworldWorldState,s_Take_00523e90);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + *(int *)(card_slot + local_178c * 4) * 0x34);
        strcat(&g_OverworldWorldState,s__Y_N__00523e98);
        arg_6 = apvStackY_17ac[3];
        iVar7 = Ai_Util_004c3ba3(0x10f);
        iVar7 = iVar7 / 2;
        iVar1 = Ai_Util_004c3ba3(0xc5);
        iVar1 = iVar1 / 2;
        iVar2 = Ai_Util_004c3ba3(0x34);
        iVar2 = iVar2 / 2;
        iVar5 = Ai_Util_004c3ba3(0xdc);
        Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5 / 2,iVar2,iVar1,iVar7,(int)arg_6);
        FUN_0050b3de(*(uint *)(card_slot + local_178c * 4) & 0xfff,0x7a,0x29,0x4b,0x70,1,&DAT_00523ea4);
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
        FUN_0040c381(&g_OverworldWorldState,0x76,0x20,0x1b);
        iVar7 = FUN_0048ac2f();
        if ((iVar7 == 0x79) || (iVar7 == 0x59)) break;
        iVar7 = Ai_Util_004c3ba3(0x34);
        iVar7 = iVar7 / 2;
        iVar1 = Ai_Util_004c3ba3(0xdc);
        iVar1 = iVar1 / 2;
        piVar6 = (int *)g_DisplaySurfaceScreen;
        iVar2 = Ai_Util_004c3ba3(0x111);
        DVar3 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0xc5);
        uVar4 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0x34);
        iVar2 = iVar2 / 2;
        iVar5 = Ai_Util_004c3ba3(0xdc);
        Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,iVar5 / 2,iVar2,uVar4,DVar3,piVar6,iVar1,
                     iVar7);
        App_ProcessPendingMessages();
      }
      Mem_AllocOrFree_0050fc50(apvStackY_17ac[3]);
      Palette_Subsystem_00496eaf();
    }
    else {
      local_178c = Ai_Subsystem_004cc455((int *)card_slot,arg_3,arg_4,arg_5,in_stack_00000018);
    }
  }
  else {
    local_7dc = 0;
    for (iVar7 = 0; iVar7 < arg_3; iVar7 = iVar7 + 1) {
      if (*(int *)(card_slot + iVar7 * 4) != -1) {
        aiStackY_7d8[local_7dc] = iVar7;
        local_7dc = local_7dc + 1;
      }
    }
    g_AiDecisionScore = Math_RandomRange(local_7dc);
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
 * Decompiled function: Pic_Subsystem_00451291
 * Entry Point: 00451291
 * Size: 186 bytes
 */


int Pic_Subsystem_00451291(int arg1,int arg2)

{
  int local_8;
  
  if (arg2 != -1) {
    for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
      if (*(int *)(&g_ActiveCardsInPlay + local_8 * 0x120 + arg1 * 0x5b20) == -1) {
        Pic_Subsystem_0045134b(arg1,arg2,local_8);
        if ((int)(&g_PlayerActiveCardCount)[arg1] <= local_8) {
          (&g_PlayerActiveCardCount)[arg1] = local_8 + 1;
          return local_8;
        }
        return local_8;
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


void Pic_Subsystem_0045134b(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  *(int *)(&g_ActiveCardsInPlay + arg_3 * 0x120 + player * 0x5b20) = card_slot;
  *(undefined4 *)(&g_CardSlot_CardId + arg_3 * 0x120 + player * 0x5b20) =
       *(undefined4 *)(&g_ActiveCardsInPlay + arg_3 * 0x120 + player * 0x5b20);
  *(undefined4 *)(&g_CardSlot_Controller + arg_3 * 0x120 + player * 0x5b20) = 0;
  if (player == 0) {
    *(undefined4 *)(&g_CardSlot_Flags + arg_3 * 0x120) = 0;
  }
  else {
    *(undefined4 *)(&g_CardSlot_Flags + arg_3 * 0x120 + player * 0x5b20) = 0x1000;
  }
  *(undefined2 *)(&g_CardSlot_Power + arg_3 * 0x120 + player * 0x5b20) = 0;
  (&g_CardSlot_Toughness)[arg_3 * 0x120 + player * 0x5b20] = 0xff;
  *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_3 * 0x120 + player * 0x5b20) = 0xffffffff;
  (&g_CardSlot_DamageReceived)[arg_3 * 0x120 + player * 0x5b20] = 0xff;
  *(undefined4 *)(&g_CardSlot_TypeFlags + arg_3 * 0x120 + player * 0x5b20) = 0xffffffff;
  *(undefined2 *)(&g_CardSlot_Counters + arg_3 * 0x120 + player * 0x5b20) =
       *(undefined2 *)(&DAT_0051aec2 + card_slot * 0x34);
  *(undefined2 *)(&DAT_006a5f46 + arg_3 * 0x120 + player * 0x5b20) =
       *(undefined2 *)(&DAT_0051aec4 + card_slot * 0x34);
  *(undefined2 *)(&DAT_006a5f48 + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(undefined2 *)(&DAT_006a5f4a + arg_3 * 0x120 + player * 0x5b20) = 0;
  (&DAT_006a5f4d)[arg_3 * 0x120 + player * 0x5b20] = (&DAT_0051aebe)[card_slot * 0x34];
  (&DAT_006a5f4c)[arg_3 * 0x120 + player * 0x5b20] = (&DAT_006a5f4d)[arg_3 * 0x120 + player * 0x5b20];
  (&g_CardSlot_ColorMask)[arg_3 * 0x120 + player * 0x5b20] = 0xff;
  (&DAT_006a5f4f)[arg_3 * 0x120 + player * 0x5b20] = 0;
  (&DAT_006a5f50)[arg_3 * 0x120 + player * 0x5b20] = 0;
  *(undefined4 *)(&g_CardSlot_TargetSlot + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_3 * 0x120 + player * 0x5b20) =
       *(undefined4 *)(&g_CardSlot_TargetSlot + arg_3 * 0x120 + player * 0x5b20);
  *(undefined4 *)(&g_CardSlot_DisplayIndex + arg_3 * 0x120 + player * 0x5b20) = 0xffffffff;
  *(undefined4 *)(&g_CardSlot_Abilities1 + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(undefined4 *)(&g_CardSlot_Abilities2 + arg_3 * 0x120 + player * 0x5b20) = 0x8000000;
  uVar1 = Pic_Subsystem_00451b1c(player,arg_3);
  *(undefined4 *)(&DAT_006a5f70 + arg_3 * 0x120 + player * 0x5b20) = uVar1;
  *(undefined4 *)(&DAT_006a5f7c + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(undefined4 *)(&DAT_006a5f80 + arg_3 * 0x120 + player * 0x5b20) = 0;
  (&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + player * 0x5b20] = 0;
  *(undefined4 *)(&DAT_006a6038 + arg_3 * 0x120 + player * 0x5b20) = 0;
  *(undefined4 *)(&g_CardSlot_SpecialState + arg_3 * 0x120 + player * 0x5b20) =
       *(undefined4 *)(&DAT_006a6038 + arg_3 * 0x120 + player * 0x5b20);
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    (&DAT_006a603c)[local_8 + player * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006a6048)[local_8 + player * 0x5b20 + arg_3 * 0x120] =
         (&DAT_006a603c)[local_8 + player * 0x5b20 + arg_3 * 0x120];
  }
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    (&DAT_006a6029)[local_8 + player * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006a602f)[local_8 + player * 0x5b20 + arg_3 * 0x120] = 0;
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&g_CardSlot_CombatTarget + arg_3 * 0x120 + player * 0x5b20 + local_8 * 8) =
         0xffffffff;
    *(undefined4 *)(&g_CardSlot_AttachedAura + arg_3 * 0x120 + player * 0x5b20 + local_8 * 8) =
         0xffffffff;
  }
  if (((&DAT_0051aed1)[card_slot * 0x34] & 0x10) != 0) {
    if (((&g_MasterCardColorTable)[card_slot * 0x34] == '\x01') ||
       ((&g_MasterCardColorTable)[card_slot * 0x34] == '@')) {
      (&DAT_006a5f4d)[arg_3 * 0x120 + player * 0x5b20] = 1;
    }
    if (*(int *)(&g_MasterCardTypeTable + card_slot * 0x34) == 0xf) {
      (&DAT_006a5f4c)[arg_3 * 0x120 + player * 0x5b20] = 0x3e;
    }
    else if (*(int *)(&g_MasterCardTypeTable + card_slot * 0x34) == 300) {
      (&DAT_006a5f4c)[arg_3 * 0x120 + player * 0x5b20] = 1;
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


undefined4 Pic_Subsystem_00451a82(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
      if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == -1) {
        *(undefined4 *)(&g_ActiveCardsInPlay + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
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
  int iVar1;
  uint uVar2;
  int local_18;
  int local_c;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  uVar2 = *(uint *)(&DAT_0051aecc + iVar1 * 0x34);
  local_18 = ((int)*(short *)(&DAT_0051aec2 + iVar1 * 0x34) & 0xffffbfffU) * 2;
  if ((&DAT_0051aebd)[iVar1 * 0x34] == '\0') {
    local_18 = 0;
  }
  local_c = (int)((local_18 + 2) *
                 (((int)*(short *)(&DAT_0051aec4 + iVar1 * 0x34) & 0xffffbfffU) + 1)) / 2;
  if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
     (arg1 == g_TurnPlayer)) {
    local_c = local_c + -1;
  }
  if ((uVar2 & 0x80) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if ((uVar2 & 0x100) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if (((&DAT_0051aed0)[iVar1 * 0x34] & 3) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if ((uVar2 & 0x40) != 0) {
    local_c = (int)((((int)*(short *)(&DAT_0051aec4 + iVar1 * 0x34) & 0xffffbfffU) + 1) * local_c) /
              2;
  }
  if ((uVar2 & 0x200) != 0) {
    local_c = (local_c * 3) / 2;
  }
  return (int)(*(int *)(&DAT_00695e88 + arg1 * 4) * local_c +
              (*(int *)(&DAT_00695e88 + arg1 * 4) * local_c >> 0x1f & 7U)) >> 3;
}



/*
 * Decompiled function: Pic_Subsystem_00451cb2
 * Entry Point: 00451cb2
 * Size: 222 bytes
 */


uint Pic_Subsystem_00451cb2(void)

{
  uint uVar1;
  int iVar2;
  int local_7dc;
  int aiStack_7d8 [500];
  int local_8;
  
  local_8 = 0;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if ((*(int *)(&deck + local_7dc * 4) != -1) && (((&DAT_00702151)[local_7dc * 4] & 0xc0) == 0)) {
      aiStack_7d8[local_8] = local_7dc;
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = Math_RandomRange(local_8);
    *(uint *)(&deck + aiStack_7d8[iVar2] * 4) = *(uint *)(&deck + aiStack_7d8[iVar2] * 4) | 0x8000;
    uVar1 = *(uint *)(&deck + aiStack_7d8[iVar2] * 4) & 0xfff;
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00451d90
 * Entry Point: 00451d90
 * Size: 176 bytes
 */


int Pic_Subsystem_00451d90(uint arg1,uint arg2)

{
  bool bVar1;
  int iVar2;
  int local_10;
  
  local_10 = 0;
  do {
    bVar1 = false;
    iVar2 = Math_RandomRange(g_MasterCardCount + -0x29);
    if (((arg1 == 0) || ((arg1 & (byte)(&g_MasterCardColorTable)[iVar2 * 0x34]) != 0)) &&
       ((arg2 == 1 || ((arg2 & (int)(char)(&DAT_0051aebe)[iVar2 * 0x34]) != 0)))) {
      bVar1 = true;
    }
  } while ((!bVar1) && (local_10 = local_10 + 1, local_10 < 999));
  return iVar2;
}



/*
 * Decompiled function: Pic_Subsystem_00451e40
 * Entry Point: 00451e40
 * Size: 461 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pic_Subsystem_00451e40(uint player)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  
  iVar4 = Pic_Subsystem_00452551(player);
  if (2 < iVar4) {
    FUN_0040b3c2(((int)(player + ((int)player >> 0x1f & 0xffU)) >> 8) + 8,player & 0xff);
  }
  iVar4 = Card_ColorMaskToColorIndex((&DAT_0051aebe)[player * 0x34]);
  bVar1 = (&g_MasterCardColorTable)[player * 0x34];
  cVar2 = s_Swamp_0051aea9[player * 0x34];
  bVar3 = false;
  for (local_14 = 0; local_14 < 500; local_14 = local_14 + 1) {
    if (*(int *)(&deck + local_14 * 4) == -1) {
      bVar3 = true;
    }
  }
  if (bVar3) {
    for (local_14 = 0x1f2; -1 < local_14; local_14 = local_14 + -1) {
      if (*(int *)(&deck + local_14 * 4) != -1) {
        uVar5 = *(uint *)(&deck + local_14 * 4) & 0xfff;
        iVar6 = Card_ColorMaskToColorIndex((&DAT_0051aebe)[uVar5 * 0x34]);
        if ((int)(iVar4 * 0x20 + (uint)bVar1 * 0x100 + (int)cVar2) <=
            (int)(iVar6 * 0x20 + (uint)(byte)(&g_MasterCardColorTable)[uVar5 * 0x34] * 0x100 +
                 (int)s_Swamp_0051aea9[uVar5 * 0x34])) {
          *(uint *)(local_14 * 4 + 0x702154) = player;
          return local_14 + 1;
        }
        *(undefined4 *)(local_14 * 4 + 0x702154) = *(undefined4 *)(&deck + local_14 * 4);
      }
    }
    _deck = player;
    iVar4 = 0;
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}



/*
 * Decompiled function: Pic_Subsystem_0045200d
 * Entry Point: 0045200d
 * Size: 88 bytes
 */


void Pic_Subsystem_0045200d(uint player)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return;
    }
    if ((*(uint *)(&deck + local_8 * 4) & 0xfff) == player) break;
    local_8 = local_8 + 1;
  }
  Pic_Subsystem_00452065(local_8);
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00452065
 * Entry Point: 00452065
 * Size: 77 bytes
 */


void Pic_Subsystem_00452065(int player)

{
  int local_8;
  
  while (local_8 = player + 1, local_8 < 500) {
    (&DAT_0070214c)[local_8] = *(undefined4 *)(&deck + local_8 * 4);
    player = local_8;
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
  int iVar1;
  int local_7dc;
  uint auStack_7d8 [500];
  undefined4 local_8;
  
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    auStack_7d8[local_7dc] = *(uint *)(&deck + local_7dc * 4);
    *(undefined4 *)(&deck + local_7dc * 4) = 0xffffffff;
  }
  local_8 = DAT_0067bde0;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if (auStack_7d8[local_7dc] != 0xffffffff) {
      iVar1 = Pic_Subsystem_00451e40(auStack_7d8[local_7dc] & 0xfff);
      *(uint *)(&deck + iVar1 * 4) =
           *(uint *)(&deck + iVar1 * 4) | auStack_7d8[local_7dc] & 0xfffff000;
    }
  }
  DAT_0067bde0 = local_8;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_004521a6
 * Entry Point: 004521a6
 * Size: 208 bytes
 */


undefined4 Pic_Subsystem_004521a6(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((player == 1) || (card_slot == 1)) {
    uVar1 = 1;
  }
  else {
    iVar2 = Card_ColorMaskToColorIndex((byte)player);
    iVar3 = Card_ColorMaskToColorIndex((byte)card_slot);
    if ((char)(&DAT_00523bc8)[iVar3 * 3] == iVar2) {
      uVar1 = 1;
    }
    else if ((arg_3 < 2) || ((char)(&DAT_00523bc9)[iVar3 * 3] != iVar2)) {
      if ((arg_3 < 3) || ((char)(&DAT_00523bca)[iVar3 * 3] != iVar2)) {
        if (arg_3 < 4) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Pic_Subsystem_00452276
 * Entry Point: 00452276
 * Size: 391 bytes
 */


void Pic_Subsystem_00452276(int player)

{
  undefined4 uVar1;
  DWORD DVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    Duel_PlaySoundById(0x21);
    Ai_Subsystem_004b58d9(player);
  }
  local_8 = 500;
  local_c = 0;
  do {
    if (499 < local_c) {
LAB_004522f5:
      local_c = 0;
      while( true ) {
        DVar2 = GetTickCount();
        if ((int)(DVar2 >> 0x10) <= local_c) break;
        rand();
        local_c = local_c + 1;
      }
      for (local_10 = 0; local_10 < 100; local_10 = local_10 + 1) {
        for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
          iVar3 = Math_RandomRange(local_8);
          if (*(int *)(&DAT_0069e730 + iVar3 * 4 + player * 2000) != -1) {
            uVar1 = *(undefined4 *)(&DAT_0069e730 + iVar3 * 4 + player * 2000);
            *(undefined4 *)(&DAT_0069e730 + iVar3 * 4 + player * 2000) =
                 *(undefined4 *)(&DAT_0069e730 + local_c * 4 + player * 2000);
            *(undefined4 *)(&DAT_0069e730 + local_c * 4 + player * 2000) = uVar1;
          }
        }
      }
      return;
    }
    if (*(int *)(&DAT_0069e730 + local_c * 4 + player * 2000) == -1) {
      local_8 = local_c;
      goto LAB_004522f5;
    }
    local_c = local_c + 1;
  } while( true );
}



/*
 * Decompiled function: Pic_Subsystem_004523fd
 * Entry Point: 004523fd
 * Size: 97 bytes
 */


void Pic_Subsystem_004523fd(int arg1,int arg2)

{
  int local_8;
  
  while (local_8 = arg2 + 1, local_8 < 500) {
    *(undefined4 *)(&DAT_0069e72c + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000);
    arg2 = local_8;
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0045245e
 * Entry Point: 0045245e
 * Size: 125 bytes
 */


int Pic_Subsystem_0045245e(int arg1,undefined4 arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000) == -1) break;
    local_8 = local_8 + 1;
  }
  *(undefined4 *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000) = arg2;
  return local_8;
}



/*
 * Decompiled function: Pic_Subsystem_004524db
 * Entry Point: 004524db
 * Size: 118 bytes
 */


void Pic_Subsystem_004524db(int arg1,undefined4 arg2)

{
  int local_8;
  
  for (local_8 = 499; 0 < local_8; local_8 = local_8 + -1) {
    *(undefined4 *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_0069e72c + local_8 * 4 + arg1 * 2000);
  }
  *(undefined4 *)(&DAT_0069e730 + arg1 * 2000) = arg2;
  return;
}



/*
 * Decompiled function: Pic_Subsystem_00452551
 * Entry Point: 00452551
 * Size: 318 bytes
 */


int Pic_Subsystem_00452551(int player)

{
  int iVar1;
  char local_28 [32];
  int local_8;
  
  if (((*(uint *)(&DAT_0051aed0 + player * 0x34) & 0x180) != 0) ||
     ((&DAT_0051aed6)[player * 0x34] == '@')) {
    (&DAT_0051aed4)[player * 0x34] = 4;
  }
  if ((&DAT_0051aed4)[player * 0x34] == -1) {
    Csv_SearchMaster_00406681
              (local_28,*(int *)(&g_MasterCardTypeTable + player * 0x34),9,s_info_csv_00523eb8);
    local_8 = 1;
    iVar1 = strcmp(local_28,s_Special_00523ec4);
    if (iVar1 == 0) {
      local_8 = 3;
    }
    iVar1 = strcmp(local_28,&DAT_00523ecc);
    if (iVar1 == 0) {
      local_8 = 3;
    }
    iVar1 = strcmp(local_28,s_Uncommon_00523ed4);
    if (iVar1 == 0) {
      local_8 = 2;
    }
    (&DAT_0051aed4)[player * 0x34] = (undefined1)local_8;
  }
  else {
    local_8 = (int)(char)(&DAT_0051aed4)[player * 0x34];
  }
  return local_8;
}



/*
 * Decompiled function: Pic_Subsystem_0045268f
 * Entry Point: 0045268f
 * Size: 121 bytes
 */


int Pic_Subsystem_0045268f(int player)

{
  int local_8;
  
  if (player != -1) {
    for (local_8 = 0; local_8 < g_MasterCardCount + 0x10; local_8 = local_8 + 1) {
      if (*(int *)(&g_MasterCardTypeTable + local_8 * 0x34) == player) {
        return local_8;
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


void Pic_Subsystem_00452708(char *str_1)

{
  int iVar1;
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    iVar1 = FUN_0040c465(str_1);
    if (8 < iVar1 + 8) {
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


void Pic_Subsystem_0045275a(undefined1 *player)

{
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    Ai_Util_004b128e(player);
    *player = 0;
    Pic_Subsystem_0044b8aa();
  }
  return;
}



