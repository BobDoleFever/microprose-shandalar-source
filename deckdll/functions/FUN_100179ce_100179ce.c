/*
 * Decompiled function: FUN_100179ce
 * Entry Point: 100179ce
 * Size: 212 bytes
 */
#include "deckdll.h"


int32_t FUN_100179ce(int32_t arg1,int arg2)

{
  char local_58 [80];
  int32_t local_8;
  
  local_8 = 0;
  if (arg2 < 5) {
    if ((DAT_101cf802 & 1) == 0) {
      local_8 = 1;
    }
    else {
      if (((DAT_101cf802 & 2) != 0) && (arg2 < 2)) {
        local_8 = 1;
      }
      if (((DAT_101cf802 & 4) != 0) && (arg2 == 4)) {
        local_8 = 1;
      }
      if (((DAT_101cf802 & 8) != 0) && (arg2 == 2)) {
        local_8 = 1;
      }
    }
  }
  else {
    sprintf(local_58,s_Card_Number__d_does_not_have_a_v_100431e8,arg1);
    MessageBoxA(DAT_10176868,local_58,s_Card_Error_1004321c,0x10);
    local_8 = 0;
  }
  return local_8;
}


