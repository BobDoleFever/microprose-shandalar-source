/*
 * Decompiled function: DeckBuilder_CheckExistingInstance
 * Entry Point: 00401010
 * Size: 113 bytes
 */
#include "deck.h"


int32_t DeckBuilder_CheckExistingInstance(int32_t arg_1,int32_t arg_2,char *str_3)

{
  HWND hWnd;
  int val_1;
  
  hWnd = FindWindowA((LPCSTR)0x0,s_Magic__The_Gathering_00412a30);
  if ((hWnd != (HWND)0x0) && (val_1 = __strnicmp(str_3,s__MTGshell_00412a48,9), val_1 != 0)) {
    PostMessageA(hWnd,0x400,3,0);
    return 0;
  }
  DeckBuilderMain(0,2,1);
  return 0;
}


