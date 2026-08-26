/*
 * Decompiled function: thunk_FUN_1003a490
 * Entry Point: 100011c2
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1003a490(void)

{
  if (DAT_101cfa68 == 0) {
    if (DAT_101cece0 < 0x4b) {
      DAT_10175558 = DAT_1015872c;
      DAT_10176860 = DAT_101628e8;
    }
    else if (DAT_101cece0 < 0x84) {
      DAT_10175558 = DAT_101cfb84;
      DAT_10176860 = DAT_10158730;
    }
    else {
      DAT_10175558 = DAT_10176470;
      DAT_10176860 = DAT_10176978;
    }
  }
  else if (DAT_101cece4 < 0x4b) {
    DAT_10175558 = DAT_1015872c;
    DAT_10176860 = DAT_101628e8;
  }
  else if (DAT_101cece4 < 0x84) {
    DAT_10175558 = DAT_101cfb84;
    DAT_10176860 = DAT_10158730;
  }
  else {
    DAT_10175558 = DAT_10176470;
    DAT_10176860 = DAT_10176978;
  }
  return;
}


