/*
 * Decompiled function: SetVidBackgroundToDIB
 * Entry Point: 100011f4
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl SetVidBackgroundToDIB(int *ptr_1,int arg_2)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  tagRECT tStack_28;
  int32_t uStack_18;
  int32_t uStack_14;
  int iStack_10;
  int iStack_c;
  LPARAM LStack_8;
  
                    /* 0x11f4  10  SetVidBackgroundToDIB */
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_2 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      LStack_8 = ptr_1_00[2];
      ptr_1_00[0x14] = (LPARAM)ptr_1;
      ptr_1_00[0x15] = 0;
      thunk_FUN_100066d7(ptr_1_00);
      tStack_28.left = 0;
      tStack_28.top = 0;
      tStack_28.right = 0;
      tStack_28.bottom = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      iStack_10 = 0;
      iStack_c = 0;
      GetWindowRect((HWND)ptr_1_00[4],&tStack_28);
      (**(code **)(*ptr_1 + 0x14))(&uStack_18);
      if (iStack_10 < tStack_28.right) {
        ptr_1_00[0x16] = (tStack_28.right - iStack_10) / 2;
      }
      if (iStack_c < tStack_28.bottom) {
        ptr_1_00[0x17] = (tStack_28.bottom - iStack_c) / 2;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}


