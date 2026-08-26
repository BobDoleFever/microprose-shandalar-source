/*
 * Decompiled function: FUN_1001772e
 * Entry Point: 1001772e
 * Size: 331 bytes
 */
#include "deckdll.h"


int32_t FUN_1001772e(int32_t arg1,char *str_2)

{
  int val_1;
  char local_5c [84];
  int32_t local_8;
  
  local_8 = 0;
  if (str_2 == (char *)0x0) {
    sprintf(local_5c,s_Card_Number__d_does_not_have_a_v_100431ac,arg1);
    MessageBoxA(DAT_10176868,local_5c,s_Card_Error_100431dc,0x10);
    local_8 = 0;
  }
  else if ((DAT_101cf7f4 & 1) == 0) {
    local_8 = 1;
  }
  else if (*str_2 == 'H') {
    if ((DAT_101cf7f4 & 0x10) == 0) {
      local_8 = 0;
    }
    else {
      local_8 = 1;
    }
  }
  else {
    val_1 = (int)str_2[2] + (int)str_2[5] + (int)str_2[7] + (int)str_2[8] + (int)str_2[1] +
            (int)*str_2;
    if (((DAT_101cf7f4 & 2) != 0) && (DAT_101cf7f6 <= val_1)) {
      local_8 = 1;
    }
    if (((DAT_101cf7f4 & 4) != 0) && (val_1 <= DAT_101cf7f6)) {
      local_8 = 1;
    }
    if (((DAT_101cf7f4 & 8) != 0) && (DAT_101cf7f6 == val_1)) {
      local_8 = 1;
    }
  }
  return local_8;
}


