/*
 * Decompiled function: FUN_1002ed06
 * Entry Point: 1002ed06
 * Size: 272 bytes
 */
#include "deckdll.h"


int32_t FUN_1002ed06(int arg_1)

{
  int32_t local_c;
  int local_8;
  
  if (arg_1 == 0) {
    strcpy(&DAT_1013ead8,s_Select_Active_Artist_10046484);
  }
  else if (arg_1 == 1) {
    strcpy(&DAT_1013ead8,s_Select_Active_Creature_1004649c);
  }
  else {
    strcpy(&DAT_1013ead8,s_Filter_Dialog_100464b4);
  }
  if (arg_1 == 0) {
    local_8 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x80,DAT_10176868,(DLGPROC)&LAB_1000116d,0);
  }
  else {
    local_8 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x80,DAT_10176868,(DLGPROC)&LAB_100014a1,0);
  }
  if (local_8 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_filter_dia_100464c8,&DAT_100464c4,0);
    local_c = 0;
  }
  else if (local_8 == 0) {
    local_c = 0;
  }
  else if (local_8 == 1) {
    local_c = 1;
  }
  return local_c;
}


