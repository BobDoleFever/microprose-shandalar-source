/*
 * Decompiled function: FUN_100032f0
 * Entry Point: 100032f0
 * Size: 273 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_100032f0(int *ptr_1,int arg_2)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  tagRECT local_28;
  int32_t local_18;
  int32_t local_14;
  int local_10;
  int local_c;
  LPARAM local_8;
  
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_2 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      local_8 = ptr_1_00[2];
      ptr_1_00[0x14] = (LPARAM)ptr_1;
      ptr_1_00[0x15] = 0;
      thunk_FUN_100066d7(ptr_1_00);
      local_28.left = 0;
      local_28.top = 0;
      local_28.right = 0;
      local_28.bottom = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      GetWindowRect((HWND)ptr_1_00[4],&local_28);
      (**(code **)(*ptr_1 + 0x14))(&local_18);
      if (local_10 < local_28.right) {
        ptr_1_00[0x16] = (local_28.right - local_10) / 2;
      }
      if (local_c < local_28.bottom) {
        ptr_1_00[0x17] = (local_28.bottom - local_c) / 2;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}


