/*
 * Decompiled function: thunk_FUN_1002ed06
 * Entry Point: 10001271
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1002ed06(int arg_1)

{
  int32_t uStack_c;
  int iStack_8;
  
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
    iStack_8 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x80,DAT_10176868,(DLGPROC)&LAB_1000116d,0);
  }
  else {
    iStack_8 = DialogBoxParamA(DAT_101cf334,(LPCSTR)0x80,DAT_10176868,(DLGPROC)&LAB_100014a1,0);
  }
  if (iStack_8 == -1) {
    MessageBoxA(DAT_10176868,s_Couldn_t_bring_up_the_filter_dia_100464c8,&DAT_100464c4,0);
    uStack_c = 0;
  }
  else if (iStack_8 == 0) {
    uStack_c = 0;
  }
  else if (iStack_8 == 1) {
    uStack_c = 1;
  }
  return uStack_c;
}


