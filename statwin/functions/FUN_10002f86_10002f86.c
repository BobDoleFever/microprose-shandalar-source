/*
 * Decompiled function: StatWin_DrawDibRender
 * Entry Point: 10002f86
 * Size: 260 bytes
 */
#include "statwin.h"


void __cdecl StatWin_DrawDibRender(HWND hwnd)

{
  code *char_ptr_1;
  HDC hDC;
  int32_t uval_2;
  int val_3;
  int32_t uval_4;
  int32_t uval_5;
  int32_t uval_6;
  int32_t uval_7;
  
  hDC = GetDC(hwnd);
  uval_2 = DrawDibOpen();
  if (*(int *)(DAT_100117a4 + 0xc) == 0) {
    val_3 = _CrtDbgReport(2,s_G__NewMagic_tstvid_statwin_cpp_10011bd4,0x302,0,0);
    if (val_3 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  uval_4 = thunk_FUN_100042a0(*(int *)(DAT_100117a4 + 0xc));
  uval_5 = (**(code **)(**(int **)(DAT_100117a4 + 0xc) + 8))();
  uval_6 = (**(code **)(**(int **)(DAT_100117a4 + 0xc) + 0xc))();
  uval_7 = thunk_FUN_100042d0(*(int *)(DAT_100117a4 + 0xc));
  DrawDibDraw(uval_2,hDC,0,0,uval_5,uval_6,uval_4,uval_7,0,0,uval_5,uval_6,0);
  ReleaseDC(hwnd,hDC);
  DrawDibClose(uval_2);
  return;
}


