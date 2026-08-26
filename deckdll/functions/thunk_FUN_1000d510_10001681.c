/*
 * Decompiled function: thunk_FUN_1000d510
 * Entry Point: 10001681
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000d510(int arg1,int arg2)

{
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (arg2 == 0) {
    iStack_10 = 0;
    iStack_c = 2;
  }
  else if (arg2 == 1) {
    iStack_10 = 1;
    iStack_c = 2;
  }
  else if (arg2 == 2) {
    iStack_10 = 2;
    iStack_c = 0;
  }
  else {
    if (arg2 != 3) {
      return 0;
    }
    iStack_10 = 2;
    iStack_c = 1;
  }
  iStack_8 = 0;
  while( true ) {
    if (DAT_101cf920 <= iStack_8) {
      return 0;
    }
    if (((&DAT_1016a620)[iStack_8 * 4] == arg1) &&
       (*(int *)(&DAT_1016a628 + iStack_8 * 0x10) == iStack_10)) break;
    iStack_8 = iStack_8 + 1;
  }
  *(int *)(&DAT_1016a628 + iStack_8 * 0x10) = iStack_c;
  if (iStack_c == 0) {
    *(uint32_t *)(&DAT_1016a62c + iStack_8 * 0x10) =
         *(uint32_t *)(&DAT_1016a62c + iStack_8 * 0x10) | 1 << (DAT_10162904 & 0x1f);
  }
  if (iStack_c == 1) {
    *(uint32_t *)(&DAT_1016a62c + iStack_8 * 0x10) =
         *(uint32_t *)(&DAT_1016a62c + iStack_8 * 0x10) & ~(1 << (DAT_10162904 & 0x1f));
  }
  return 1;
}


