/*
 * Decompiled function: FUN_100127ad
 * Entry Point: 100127ad
 * Size: 406 bytes
 */
#include "deckdll.h"


int32_t FUN_100127ad(void)

{
  int32_t uval_1;
  
  DAT_101cf91c = CreateSolidBrush(0x24a3230);
  DAT_10176858 = CreateSolidBrush(0x2508080);
  DAT_101625fc = CreateSolidBrush(0x2508080);
  DAT_10175554 = CreateSolidBrush(0x2508080);
  DAT_10175f00 = CreateSolidBrush(0x2508080);
  DAT_10162900 = CreateSolidBrush(0x2508080);
  DAT_1016e4ac = CreateSolidBrush(0x2508080);
  if ((((DAT_101cf91c == (HBRUSH)0x0) || (DAT_10176858 == (HBRUSH)0x0)) ||
      (DAT_101625fc == (HBRUSH)0x0)) ||
     (((DAT_10175554 == (HBRUSH)0x0 || (DAT_10175f00 == (HBRUSH)0x0)) ||
      ((DAT_10162900 == (HBRUSH)0x0 || (DAT_1016e4ac == (HBRUSH)0x0)))))) {
    if (DAT_101cf91c != (HBRUSH)0x0) {
      DeleteObject(DAT_101cf91c);
    }
    if (DAT_10176858 != (HBRUSH)0x0) {
      DeleteObject(DAT_10176858);
    }
    if (DAT_101625fc != (HBRUSH)0x0) {
      DeleteObject(DAT_101625fc);
    }
    if (DAT_10175554 != (HBRUSH)0x0) {
      DeleteObject(DAT_10175554);
    }
    if (DAT_10175f00 != (HBRUSH)0x0) {
      DeleteObject(DAT_10175f00);
    }
    if (DAT_10162900 != (HBRUSH)0x0) {
      DeleteObject(DAT_10162900);
    }
    if (DAT_1016e4ac != (HBRUSH)0x0) {
      DeleteObject(DAT_1016e4ac);
    }
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}


