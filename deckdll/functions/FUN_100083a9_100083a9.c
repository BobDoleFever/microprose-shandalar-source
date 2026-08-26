/*
 * Decompiled function: FUN_100083a9
 * Entry Point: 100083a9
 * Size: 130 bytes
 */
#include "deckdll.h"


HWND FUN_100083a9(HWND hwnd,int arg_2,int arg_3)

{
  int val_1;
  LRESULT LVar2;
  int32_t local_c;
  int32_t local_8;
  
  local_8 = (HWND)0x0;
  for (local_c = GetTopWindow(hwnd); local_c != (HWND)0x0; local_c = GetWindow(local_c,2)) {
    val_1 = GetDlgCtrlID(local_c);
    if (val_1 == arg_2) {
      LVar2 = SendMessageA(local_c,0x400,0,0);
      if (LVar2 == arg_3) {
        local_8 = local_c;
      }
    }
  }
  return local_8;
}


