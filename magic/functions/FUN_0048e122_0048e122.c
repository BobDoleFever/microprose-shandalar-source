/*
 * Decompiled function: FUN_0048e122
 * Entry Point: 0048e122
 * Size: 157 bytes
 */
#include "magic.h"


void FUN_0048e122(char *str_1)

{
  DAT_0054aab8 = _open(str_1,0x8301,0x80);
  if (DAT_0054aab8 != -1) {
    DAT_0054aab0 = 0;
    FUN_0048e01d(&DAT_00695e98,4);
    FUN_0048d259();
    FUN_0048e01d(&_PlayerFace,4);
    FUN_0048e01d(&_OpponFace,4);
    FUN_0048e01d(&DAT_006ff310,0x32);
    FUN_0048e01d(&DAT_0068a6a0,0x32);
    _close(DAT_0054aab8);
  }
  return;
}


