/*
 * Decompiled function: thunk_FUN_10028def
 * Entry Point: 100012ee
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10028def(WPARAM arg_1,int32_t arg_2,int width,int height)

{
  HGDIOBJ ho;
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else if (*(int *)(&DAT_10176af4 + arg_1 * 0x98) < 2) {
    if (((*(int *)(&DAT_10162910 + arg_1 * 0x10) == 0) ||
        (*(int *)(&DAT_10162918 + arg_1 * 0x10) != width)) ||
       (*(int *)(&DAT_1016291c + arg_1 * 0x10) != height)) {
      ho = *(HGDIOBJ *)(&DAT_10162910 + arg_1 * 0x10);
      *(int32_t *)(&DAT_10162910 + arg_1 * 0x10) = 0;
      val_2 = thunk_FUN_10028a10(arg_1,arg_2,width,height);
      if (val_2 == 0) {
        *(HGDIOBJ *)(&DAT_10162910 + arg_1 * 0x10) = ho;
        uval_1 = 0;
      }
      else {
        if (ho != (HGDIOBJ)0x0) {
          DeleteObject(ho);
        }
        uval_1 = 1;
      }
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    uval_1 = thunk_FUN_10029386(arg_1,arg_2,width,height);
  }
  return uval_1;
}


