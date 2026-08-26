/*
 * Decompiled function: StatWin_SetAssetPath
 * Entry Point: 100021a3
 * Size: 97 bytes
 */
#include "statwin.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl StatWin_SetAssetPath(int32_t *ptr_1)

{
  int val_1;
  
  val_1 = thunk_FUN_10004512(DAT_100117a4,ptr_1,0);
  if (val_1 == 0) {
    _DAT_10011794 = 1;
    thunk_FUN_100035b2();
    *PTR_s___statwin__10011540 = DAT_1001317c;
    val_1 = 0;
  }
  else {
    _DAT_10011794 = 0;
  }
  return val_1;
}


