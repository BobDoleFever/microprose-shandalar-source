/*
 * Decompiled function: thunk_FUN_1000bb7d
 * Entry Point: 100013ca
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000bb7d(void)

{
  INT_PTR IVar1;
  int32_t uStack_c;
  
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0xc8,DAT_10176868,(DLGPROC)&LAB_100016a9,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_filter_dia_100412a8,&DAT_100412a4,0);
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


