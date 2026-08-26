/*
 * Decompiled function: thunk_FUN_100091bd
 * Entry Point: 100013d9
 * Size: 5 bytes
 */
#include "deckdll.h"


bool thunk_FUN_100091bd(HWND hwnd,LPVOID arg_2,WPARAM arg_3)

{
  HWND hWnd;
  
  hWnd = CreateWindowExA(0,s_MAGICDECK_CardClass_10040bb0,&DAT_10040bac,0x54000000,0,0,DAT_10175558,
                         DAT_10176860,hwnd,(HMENU)0x1,DAT_101cf334,arg_2);
  if (hWnd != (HWND)0x0) {
    BringWindowToTop(hWnd);
    SendMessageA(hWnd,0x401,arg_3,0);
  }
  return hWnd != (HWND)0x0;
}


