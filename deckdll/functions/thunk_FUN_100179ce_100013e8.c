/*
 * Decompiled function: thunk_FUN_100179ce
 * Entry Point: 100013e8
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100179ce(int32_t arg1,int arg2)

{
  char acStack_58 [80];
  int32_t uStack_8;
  
  uStack_8 = 0;
  if (arg2 < 5) {
    if ((DAT_101cf802 & 1) == 0) {
      uStack_8 = 1;
    }
    else {
      if (((DAT_101cf802 & 2) != 0) && (arg2 < 2)) {
        uStack_8 = 1;
      }
      if (((DAT_101cf802 & 4) != 0) && (arg2 == 4)) {
        uStack_8 = 1;
      }
      if (((DAT_101cf802 & 8) != 0) && (arg2 == 2)) {
        uStack_8 = 1;
      }
    }
  }
  else {
    sprintf(acStack_58,s_Card_Number__d_does_not_have_a_v_100431e8,arg1);
    MessageBoxA(DAT_10176868,acStack_58,s_Card_Error_1004321c,0x10);
    uStack_8 = 0;
  }
  return uStack_8;
}


