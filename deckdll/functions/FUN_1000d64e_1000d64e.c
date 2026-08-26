/*
 * Decompiled function: FUN_1000d64e
 * Entry Point: 1000d64e
 * Size: 262 bytes
 */
#include "deckdll.h"


int32_t FUN_1000d64e(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int val_4;
  int local_10;
  int local_c;
  
  local_c = 0;
  flag_1 = false;
  while ((local_c < DAT_101cf920 && (!flag_1))) {
    if (((&DAT_1016a620)[local_c * 4] == arg1) && (*(int *)(&DAT_1016a628 + local_c * 0x10) == arg2)
       ) {
      local_10 = local_c;
      flag_1 = true;
      if (arg2 == 0) {
        thunk_FUN_100395de(arg1,1,0x101cded0);
      }
    }
    local_c = local_c + 1;
  }
  if (flag_1) {
    while (local_c = local_10 + 1, local_c < DAT_101cf920) {
      val_3 = local_c * 0x10;
      val_4 = local_10 * 0x10;
      (&DAT_1016a620)[local_10 * 4] = (&DAT_1016a620)[local_c * 4];
      *(int32_t *)(&DAT_1016a624 + val_4) = *(int32_t *)(&DAT_1016a624 + val_3);
      *(int32_t *)(&DAT_1016a628 + val_4) = *(int32_t *)(&DAT_1016a628 + val_3);
      *(int32_t *)(&DAT_1016a62c + val_4) = *(int32_t *)(&DAT_1016a62c + val_3);
      local_10 = local_c;
    }
    DAT_101cf920 = DAT_101cf920 + -1;
    uval_2 = 1;
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}


