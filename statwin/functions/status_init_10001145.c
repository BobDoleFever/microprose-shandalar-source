/*
 * Decompiled function: status_init
 * Entry Point: 10001145
 * Size: 5 bytes
 */
#include "statwin.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl status_init(int32_t *ptr_1)

{
  int val_1;
  
                    /* 0x1145  2  status_init */
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


