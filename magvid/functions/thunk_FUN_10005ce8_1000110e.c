/*
 * Decompiled function: thunk_FUN_10005ce8
 * Entry Point: 1000110e
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10005ce8(int arg1,int arg2)

{
  int *i_ptr_1;
  HPALETTE hPal;
  
  i_ptr_1 = *(int **)(arg1 + 8);
  if ((((i_ptr_1 != (int *)0x0) && (*i_ptr_1 != 0)) && (*(int *)(arg1 + 0x10) != arg2)) &&
     (*(int *)(*i_ptr_1 + 0x194) != 0)) {
    hPal = SelectPalette((HDC)i_ptr_1[0xc],*(HPALETTE *)(*i_ptr_1 + 0x194),0);
    RealizePalette((HDC)i_ptr_1[0xc]);
    if (hPal != (HPALETTE)0x0) {
      SelectPalette((HDC)i_ptr_1[0xc],hPal,0);
    }
  }
  return;
}


