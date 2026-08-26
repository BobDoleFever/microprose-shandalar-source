/*
 * Decompiled function: thunk_FUN_1000b097
 * Entry Point: 100011ea
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000b097(void)

{
  INT_PTR IVar1;
  int32_t uStack_c;
  
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0xc5,DAT_10176868,(DLGPROC)&LAB_100012d0,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_title_dial_10041210,&DAT_1004120c,0);
    uStack_c = 0;
  }
  else if (IVar1 == 0) {
    uStack_c = 0;
  }
  else if (IVar1 == 1) {
    uStack_c = 1;
  }
  return uStack_c;
}


