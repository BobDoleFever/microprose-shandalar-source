/*
 * Decompiled function: FUN_004804eb
 * Entry Point: 004804eb
 * Size: 420 bytes
 */
#include "duel.h"


int FUN_004804eb(HWND hwnd,int arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  undefined1 *ptr_1;
  int iVar1;
  BITMAPINFO *lpbmi;
  HDC hdc;
  int iVar2;
  int local_2c;
  int local_28;
  int local_1c;
  undefined1 *local_14;
  undefined1 local_10;
  int local_8;
  
  local_1c = 0;
  local_8 = 0;
  ptr_1 = _malloc(arg_6 * arg_5 * 3 + 8);
  _memset(ptr_1,0,arg_6 * arg_5 * 3);
  local_14 = ptr_1;
  for (local_2c = 0; local_2c < (int)arg_6; local_2c = local_2c + 1) {
    for (local_28 = 0; local_28 < (int)arg_5; local_28 = local_28 + 1) {
      iVar1 = *(int *)(local_28 * 4 + arg_5 * local_2c * 4 + arg_2) >> 2;
      iVar2 = iVar1;
      if ((local_8 <= iVar1) && (iVar2 = local_8, local_1c < iVar1)) {
        local_1c = iVar1;
      }
      local_8 = iVar2;
      if (iVar1 < 1) {
        iVar1 = 0;
      }
      if (0xfe < iVar1) {
        iVar1 = 0xff;
      }
      local_10 = (undefined1)iVar1;
      local_14[2] = local_10;
      local_14[1] = local_14[2];
      *local_14 = local_14[1];
      local_14 = local_14 + 3;
    }
  }
  lpbmi = (BITMAPINFO *)FUN_0047f7d3(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  iVar2 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,ptr_1,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  Mem_AllocOrFree_0047f8f7(lpbmi);
  FUN_004db150(ptr_1);
  return iVar2;
}


