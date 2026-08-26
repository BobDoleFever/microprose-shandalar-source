/*
 * Decompiled function: FUN_1000b79e
 * Entry Point: 1000b79e
 * Size: 140 bytes
 */
#include "deckdll.h"


int32_t FUN_1000b79e(void)

{
  INT_PTR IVar1;
  int32_t local_c;
  
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0xc7,DAT_10176868,(DLGPROC)&LAB_10001348,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_title_dial_10041268,&DAT_10041264,0);
    local_c = 0;
  }
  else if (IVar1 == 0) {
    local_c = 0;
  }
  else if (IVar1 == 1) {
    local_c = 1;
  }
  return local_c;
}


