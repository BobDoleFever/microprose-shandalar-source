/*
 * Decompiled function: FUN_1003336e
 * Entry Point: 1003336e
 * Size: 72 bytes
 */
#include "deckdll.h"


bool FUN_1003336e(HWND hwnd)

{
  int val_1;
  CHAR local_68 [100];
  
  GetClassNameA(hwnd,local_68,100);
  val_1 = strcmp(local_68,s_Button_1004670c);
  return val_1 == 0;
}


