/*
 * Decompiled function: FUN_1000d510
 * Entry Point: 1000d510
 * Size: 318 bytes
 */
#include "deckdll.h"


int32_t FUN_1000d510(int arg1,int arg2)

{
  int local_10;
  int local_c;
  int local_8;
  
  if (arg2 == 0) {
    local_10 = 0;
    local_c = 2;
  }
  else if (arg2 == 1) {
    local_10 = 1;
    local_c = 2;
  }
  else if (arg2 == 2) {
    local_10 = 2;
    local_c = 0;
  }
  else {
    if (arg2 != 3) {
      return 0;
    }
    local_10 = 2;
    local_c = 1;
  }
  local_8 = 0;
  while( true ) {
    if (DAT_101cf920 <= local_8) {
      return 0;
    }
    if (((&DAT_1016a620)[local_8 * 4] == arg1) &&
       (*(int *)(&DAT_1016a628 + local_8 * 0x10) == local_10)) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_1016a628 + local_8 * 0x10) = local_c;
  if (local_c == 0) {
    *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) =
         *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) | 1 << (DAT_10162904 & 0x1f);
  }
  if (local_c == 1) {
    *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) =
         *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) & ~(1 << (DAT_10162904 & 0x1f));
  }
  return 1;
}


