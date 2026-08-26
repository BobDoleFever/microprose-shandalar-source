/*
 * Decompiled function: FUN_10003401
 * Entry Point: 10003401
 * Size: 292 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_10003401(int arg_1)

{
  int val_1;
  int *arg_1_00;
  int32_t uval_2;
  int32_t uval_3;
  int32_t uval_4;
  HDC hDC;
  int32_t uval_5;
  int32_t uval_6;
  int32_t uval_7;
  int32_t uval_8;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_3 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (val_1 == 0) {
      uval_3 = 0;
    }
    else {
      arg_1_00 = *(int **)(val_1 + 0x50);
      if (arg_1_00 == (int *)0x0) {
        uval_3 = 2;
      }
      else {
        if (*(int *)(val_1 + 0x10) != 0) {
          uval_4 = DrawDibOpen();
          hDC = GetDC(*(HWND *)(val_1 + 0x10));
          uval_5 = thunk_FUN_10004bc0((int)arg_1_00);
          uval_3 = *(int32_t *)(val_1 + 0x58);
          uval_2 = *(int32_t *)(val_1 + 0x5c);
          uval_6 = (**(code **)(*arg_1_00 + 8))();
          uval_7 = (**(code **)(*arg_1_00 + 0xc))();
          uval_8 = thunk_FUN_10004bf0((int)arg_1_00);
          DrawDibDraw(uval_4,hDC,uval_3,uval_2,uval_6,uval_7,uval_5,uval_8,0,0,uval_6,uval_7,0);
          ReleaseDC(*(HWND *)(val_1 + 0x10),hDC);
          DrawDibClose(uval_4);
        }
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}


