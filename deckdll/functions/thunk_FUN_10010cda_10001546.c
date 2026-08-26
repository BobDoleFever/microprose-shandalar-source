/*
 * Decompiled function: thunk_FUN_10010cda
 * Entry Point: 10001546
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t thunk_FUN_10010cda(void)

{
  int iStack_c;
  uint32_t uStack_8;
  
  thunk_FUN_10012ca3();
  if ((DAT_1017646c & 1) != 0) {
    for (iStack_c = 0; iStack_c < DAT_101cf920; iStack_c = iStack_c + 1) {
      uStack_8 = 0;
      if (*(int *)(&DAT_1016a628 + iStack_c * 0x10) != 0) {
        uStack_8 = 0x4000;
      }
      *(uint32_t *)(deck + iStack_c * 4) =
           *(uint32_t *)(&DAT_1016a624 + iStack_c * 0x10) |
           uStack_8 | *(int *)(&DAT_1016a62c + iStack_c * 0x10) << 0x10;
    }
    for (iStack_c = DAT_101cf920; iStack_c < 500; iStack_c = iStack_c + 1) {
      *(int32_t *)(deck + iStack_c * 4) = 0xffffffff;
    }
    *DAT_10176484 = _DAT_10162904;
  }
  thunk_FUN_10012141();
  thunk_FUN_10012740();
  thunk_FUN_1003239b();
  for (iStack_c = 0; iStack_c < DAT_10175ee0; iStack_c = iStack_c + 1) {
    thunk_FUN_10028f03(iStack_c);
  }
  thunk_FUN_10013e46();
  thunk_FUN_10012943();
  DeleteDC(DAT_101625e8);
  DeleteObject(DAT_101cf924);
  _chdir(&DAT_10176990);
  return 0;
}


