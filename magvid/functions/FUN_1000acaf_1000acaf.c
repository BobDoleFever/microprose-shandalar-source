/*
 * Decompiled function: FUN_1000acaf
 * Entry Point: 1000acaf
 * Size: 390 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_1000acaf(int32_t *ptr_1)

{
  int32_t uval_1;
  
  ptr_1[4] = 0;
  if (ptr_1[1] == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    ICSendMessage(*ptr_1,0x403f,0,0);
    if (ptr_1[0x5f] != 0) {
      if ((void *)ptr_1[0x5f] != (void *)0x0) {
        thunk_FUN_10004b70((void *)ptr_1[0x5f],1);
      }
    }
    if (DAT_100275d0 != 0) {
      DrawDibStop(ptr_1[2]);
      DrawDibEnd(ptr_1[2]);
    }
    if (ptr_1[0x6a] != 0) {
      SelectPalette((HDC)ptr_1[1],(HPALETTE)ptr_1[0x6a],0);
    }
    if (ptr_1[0x6b] != 0) {
      SelectPalette((HDC)ptr_1[0x68],(HPALETTE)ptr_1[0x6b],0);
    }
    if (ptr_1[99] != 0) {
      DeleteObject((HGDIOBJ)ptr_1[99]);
      ptr_1[99] = 0;
    }
    if (ptr_1[0x69] != 0) {
      SelectObject((HDC)ptr_1[0x68],(HGDIOBJ)ptr_1[0x69]);
    }
    if (ptr_1[0x68] != 0) {
      DeleteDC((HDC)ptr_1[0x68]);
    }
    ptr_1[1] = 0;
    uval_1 = 0;
  }
  return uval_1;
}


