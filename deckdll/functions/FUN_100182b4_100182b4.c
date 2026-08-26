/*
 * Decompiled function: FUN_100182b4
 * Entry Point: 100182b4
 * Size: 172 bytes
 */
#include "deckdll.h"


int32_t FUN_100182b4(int32_t arg1,int arg2)

{
  uint32_t uval_1;
  undefined8 uval_2;
  char local_60 [80];
  int local_10;
  int local_c;
  int32_t local_8;
  
  local_8 = 0;
  if (arg2 == 0) {
    sprintf(local_60,s_Card_Number__d_does_not_have_a_v_1004326c,arg1);
    local_8 = 0;
  }
  else if ((DAT_101cf803 & 1) == 0) {
    local_8 = 1;
  }
  else {
    local_10 = thunk_FUN_10018360((char *)arg2,DAT_101628f0);
    uval_1 = DAT_101cf808;
    local_c = local_10 >> 0x1f;
    uval_2 = __allshl((uint8_t)local_10,0);
    if (((DAT_101cf80c & (uint32_t)((ulonglong)uval_2 >> 0x20)) != 0) || ((uval_1 & (uint32_t)uval_2) != 0)) {
      local_8 = 1;
    }
  }
  return local_8;
}


