/*
 * Decompiled function: thunk_FUN_10027181
 * Entry Point: 100010c8
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_10027181(void)

{
  int val_1;
  int iStack_10;
  
  DAT_101cf920 = 0;
  DAT_101628f8 = 0;
  iStack_10 = 0;
  DAT_101cece0 = 0;
  DAT_101cece4 = 0;
  while (val_1 = (*_FUN_101cdebc)(*(int32_t *)(deck + iStack_10 * 4)), val_1 != -1) {
    (&DAT_1016a620)[iStack_10 * 4] = val_1;
    *(uint32_t *)(&DAT_1016a624 + iStack_10 * 0x10) = *(uint32_t *)(deck + DAT_101cf920 * 4) & 0xfff;
    *(int32_t *)(&DAT_1016a628 + iStack_10 * 0x10) = 1;
    *(uint32_t *)(&DAT_1016a62c + iStack_10 * 0x10) =
         (*(uint32_t *)(deck + DAT_101cf920 * 4) & 0x70000) >> 0x10;
    if ((*(uint32_t *)(deck + DAT_101cf920 * 4) & 1 << ((char)_DAT_10162904 + 0x10U & 0x1f)) != 0) {
      thunk_FUN_100391f0((&DAT_1016a620)[iStack_10 * 4],1,0x101cded0);
      *(int32_t *)(&DAT_1016a628 + iStack_10 * 0x10) = 0;
    }
    DAT_101cf920 = DAT_101cf920 + 1;
    iStack_10 = iStack_10 + 1;
  }
  thunk_FUN_1000880b();
  return;
}


