/*
 * Decompiled function: thunk_FUN_100083a9
 * Entry Point: 100014f1
 * Size: 5 bytes
 */
#include "deckdll.h"


HWND thunk_FUN_100083a9(HWND hwnd,int arg_2,int arg_3)

{
  int val_1;
  LRESULT LVar2;
  int32_t uStack_c;
  int32_t uStack_8;
  
  uStack_8 = (HWND)0x0;
  for (uStack_c = GetTopWindow(hwnd); uStack_c != (HWND)0x0; uStack_c = GetWindow(uStack_c,2)) {
    val_1 = GetDlgCtrlID(uStack_c);
    if (val_1 == arg_2) {
      LVar2 = SendMessageA(uStack_c,0x400,0,0);
      if (LVar2 == arg_3) {
        uStack_8 = uStack_c;
      }
    }
  }
  return uStack_8;
}


