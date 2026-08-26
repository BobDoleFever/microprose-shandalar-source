/*
 * Decompiled function: FUN_100037ad
 * Entry Point: 100037ad
 * Size: 445 bytes
 */
#include "statwin.h"


int __cdecl FUN_100037ad(int32_t arg_1,int16_t arg_2,int16_t arg_3,uint8_t arg_4)

{
  LONG LVar1;
  int val_2;
  int16_t local_20;
  int16_t local_1e;
  int32_t local_1c;
  int local_18;
  uint32_t local_14;
  int local_10;
  HWND local_c;
  HWND local_8;
  
  local_14 = 0;
  local_1c = 0;
  if (DAT_1001178c == 0) {
    local_c = (HWND)0x0;
  }
  else {
    local_c = (HWND)thunk_FUN_10001c1a();
  }
  if ((arg_4 & 1) != 0) {
    local_10 = GetSystemMetrics(0);
    local_18 = GetSystemMetrics(1);
    local_8 = CreateWindowExA(0,PTR_s_STATWINCLASS_100117a0,(LPCSTR)0x0,0x80000000,0,0,local_10,
                              local_18,local_c,(HMENU)0x0,DAT_1001316c,(LPVOID)0x0);
    if (local_8 == (HWND)0x0) {
      return 8;
    }
    LVar1 = SetWindowLongA(local_8,-4,0x10001177);
    if (LVar1 == 0) {
      DestroyWindow(local_8);
      return 8;
    }
    ShowWindow(local_8,5);
  }
  if ((arg_4 & 2) == 0) {
    local_20 = arg_2;
    local_1e = arg_3;
  }
  else {
    local_14 = local_14 | 2;
    local_20 = 0;
    local_1e = 0;
  }
  val_2 = thunk_FUN_100097b0(arg_1,&local_1c,&local_20,local_14);
  if (val_2 == 0) {
    thunk_FUN_10009a89(local_1c,0);
    thunk_FUN_10009824(local_1c);
    while (val_2 = thunk_FUN_10009b0f(local_1c), val_2 != 0) {
      val_2 = thunk_FUN_1000245c();
      if (val_2 != 0) {
        thunk_FUN_10009865(local_1c);
        break;
      }
      Sleep(0x32);
    }
    thunk_FUN_100097f0(local_1c);
    local_1c = 0;
    DestroyWindow(local_8);
    val_2 = 0;
  }
  else {
    DestroyWindow(local_8);
  }
  return val_2;
}


