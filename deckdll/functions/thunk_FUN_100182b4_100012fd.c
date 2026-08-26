/*
 * Decompiled function: thunk_FUN_100182b4
 * Entry Point: 100012fd
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100182b4(int32_t arg1,int arg2)

{
  uint32_t uval_1;
  undefined8 uval_2;
  char acStack_60 [80];
  int iStack_10;
  int iStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0;
  if (arg2 == 0) {
    sprintf(acStack_60,s_Card_Number__d_does_not_have_a_v_1004326c,arg1);
    uStack_8 = 0;
  }
  else if ((DAT_101cf803 & 1) == 0) {
    uStack_8 = 1;
  }
  else {
    iStack_10 = thunk_FUN_10018360((char *)arg2,DAT_101628f0);
    uval_1 = DAT_101cf808;
    iStack_c = iStack_10 >> 0x1f;
    uval_2 = __allshl((uint8_t)iStack_10,0);
    if (((DAT_101cf80c & (uint32_t)((ulonglong)uval_2 >> 0x20)) != 0) || ((uval_1 & (uint32_t)uval_2) != 0)) {
      uStack_8 = 1;
    }
  }
  return uStack_8;
}


