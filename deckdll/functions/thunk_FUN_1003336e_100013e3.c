/*
 * Decompiled function: thunk_FUN_1003336e
 * Entry Point: 100013e3
 * Size: 5 bytes
 */
#include "deckdll.h"


bool thunk_FUN_1003336e(HWND hwnd)

{
  int val_1;
  CHAR aCStack_68 [100];
  
  GetClassNameA(hwnd,aCStack_68,100);
  val_1 = strcmp(aCStack_68,s_Button_1004670c);
  return val_1 == 0;
}


