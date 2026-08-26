/*
 * Decompiled function: thunk_FUN_1000ad0b
 * Entry Point: 1000100a
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000ad0b(void)

{
  INT_PTR IVar1;
  int32_t uStack_c;
  
  strcpy(&DAT_10176320,s_How_many_to_move__100411b4);
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x7f,DAT_10176868,(DLGPROC)&LAB_100011e0,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_filter_dia_100411cc,&DAT_100411c8,0);
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


