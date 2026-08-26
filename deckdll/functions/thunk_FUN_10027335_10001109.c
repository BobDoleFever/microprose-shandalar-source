/*
 * Decompiled function: thunk_FUN_10027335
 * Entry Point: 10001109
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10027335(char *str_1)

{
  INT_PTR IVar1;
  int32_t uStack_c;
  
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0xdd,DAT_10176868,(DLGPROC)&LAB_100015c3,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_Load_Deck_d_10045d94,&DAT_10045d90,0);
    uStack_c = 0;
  }
  else if (IVar1 == 0) {
    uStack_c = 0;
  }
  else if (IVar1 == 1) {
    strcpy(str_1,&DAT_10103ca0);
    uStack_c = 1;
  }
  return uStack_c;
}


