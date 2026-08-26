/*
 * Decompiled function: thunk_FUN_1000ac70
 * Entry Point: 1000173f
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000ac70(void)

{
  INT_PTR IVar1;
  int32_t uStack_c;
  
  strcpy(&DAT_10176320,s_How_many_to_Sell__10041174);
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x7f,DAT_10176868,(DLGPROC)&LAB_100011e0,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_filter_dia_1004118c,&DAT_10041188,0);
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


