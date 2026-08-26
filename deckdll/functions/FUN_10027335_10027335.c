/*
 * Decompiled function: FUN_10027335
 * Entry Point: 10027335
 * Size: 157 bytes
 */
#include "deckdll.h"


int32_t FUN_10027335(char *str_1)

{
  INT_PTR IVar1;
  int32_t local_c;
  
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0xdd,DAT_10176868,(DLGPROC)&LAB_100015c3,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_Load_Deck_d_10045d94,&DAT_10045d90,0);
    local_c = 0;
  }
  else if (IVar1 == 0) {
    local_c = 0;
  }
  else if (IVar1 == 1) {
    strcpy(str_1,&DAT_10103ca0);
    local_c = 1;
  }
  return local_c;
}


