/*
 * Decompiled function: FUN_1000365d
 * Entry Point: 1000365d
 * Size: 265 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_1000365d(int arg_1)

{
  int32_t uval_1;
  DWORD dwStyle;
  BOOL bMenu;
  tagRECT local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  tagRECT local_14;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    local_2c = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (local_2c == 0) {
      uval_1 = 0;
    }
    else {
      local_18 = *(int **)(local_2c + 8);
      GetClientRect((HWND)local_18[5],&local_3c);
      if (*local_18 == 0) {
        local_24 = 0;
        local_28 = 0;
        local_20 = 0x140;
        local_1c = 0;
      }
      else {
        thunk_FUN_1000b5e0((void *)*local_18,&local_28);
      }
      local_14.top = 0;
      local_14.left = 0;
      local_14.right = local_20 - local_28;
      local_14.bottom = ((local_1c - local_24) - local_3c.top) + local_3c.bottom;
      bMenu = 1;
      dwStyle = GetWindowLongA((HWND)local_18[5],-0x10);
      AdjustWindowRect(&local_14,dwStyle,bMenu);
      SetWindowPos((HWND)local_18[5],(HWND)0x0,0,0,local_14.right - local_14.left,
                   local_14.bottom - local_14.top,0x16);
      uval_1 = 0;
    }
  }
  return uval_1;
}


