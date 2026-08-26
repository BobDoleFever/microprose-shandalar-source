/*
 * Decompiled function: FUN_1002e9bb
 * Entry Point: 1002e9bb
 * Size: 254 bytes
 */
#include "deckdll.h"


int32_t FUN_1002e9bb(int arg_1)

{
  INT_PTR IVar1;
  int32_t local_c;
  
  if (arg_1 == 0x1d) {
    strcpy(&DAT_1013ead8,s_Casting_Cost_1004640c);
  }
  else if (arg_1 == 0x1e) {
    strcpy(&DAT_1013ead8,s_Power_1004641c);
  }
  else if (arg_1 == 0x1f) {
    strcpy(&DAT_1013ead8,s_Toughness_10046424);
  }
  else {
    strcpy(&DAT_1013ead8,s_Filter_Dialog_10046430);
  }
  IVar1 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x7f,DAT_10176868,(DLGPROC)&LAB_100014fb,0);
  if (IVar1 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_filter_dia_10046444,&DAT_10046440,0);
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


