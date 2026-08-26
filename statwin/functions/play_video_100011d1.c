/*
 * Decompiled function: play_video
 * Entry Point: 100011d1
 * Size: 5 bytes
 */
#include "statwin.h"


int __cdecl play_video(int32_t arg_1,int16_t arg_2,int16_t arg_3,uint8_t arg_4)

{
  LONG LVar1;
  int val_2;
  int16_t uStack_20;
  int16_t uStack_1e;
  int32_t uStack_1c;
  int iStack_18;
  uint32_t uStack_14;
  int iStack_10;
  HWND pHStack_c;
  HWND pHStack_8;
  
                    /* 0x11d1  3  play_video */
  uStack_14 = 0;
  uStack_1c = 0;
  if (DAT_1001178c == 0) {
    pHStack_c = (HWND)0x0;
  }
  else {
    pHStack_c = (HWND)thunk_FUN_10001c1a();
  }
  if ((arg_4 & 1) != 0) {
    iStack_10 = GetSystemMetrics(0);
    iStack_18 = GetSystemMetrics(1);
    pHStack_8 = CreateWindowExA(0,PTR_s_STATWINCLASS_100117a0,(LPCSTR)0x0,0x80000000,0,0,iStack_10,
                                iStack_18,pHStack_c,(HMENU)0x0,DAT_1001316c,(LPVOID)0x0);
    if (pHStack_8 == (HWND)0x0) {
      return 8;
    }
    LVar1 = SetWindowLongA(pHStack_8,-4,0x10001177);
    if (LVar1 == 0) {
      DestroyWindow(pHStack_8);
      return 8;
    }
    ShowWindow(pHStack_8,5);
  }
  if ((arg_4 & 2) == 0) {
    uStack_20 = arg_2;
    uStack_1e = arg_3;
  }
  else {
    uStack_14 = uStack_14 | 2;
    uStack_20 = 0;
    uStack_1e = 0;
  }
  val_2 = thunk_FUN_100097b0(arg_1,&uStack_1c,&uStack_20,uStack_14);
  if (val_2 == 0) {
    thunk_FUN_10009a89(uStack_1c,0);
    thunk_FUN_10009824(uStack_1c);
    while (val_2 = thunk_FUN_10009b0f(uStack_1c), val_2 != 0) {
      val_2 = thunk_FUN_1000245c();
      if (val_2 != 0) {
        thunk_FUN_10009865(uStack_1c);
        break;
      }
      Sleep(0x32);
    }
    thunk_FUN_100097f0(uStack_1c);
    uStack_1c = 0;
    DestroyWindow(pHStack_8);
    val_2 = 0;
  }
  else {
    DestroyWindow(pHStack_8);
  }
  return val_2;
}


