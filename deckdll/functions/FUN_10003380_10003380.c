/*
 * Decompiled function: DeckDll_BlitCardArtwork
 * Entry Point: 10003380
 * Size: 104 bytes
 */
#include "deckdll.h"


int DeckDll_BlitCardArtwork(HWND hwnd,void *arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  BITMAPINFO *lpbmi;
  HDC hdc;
  int val_1;
  
  lpbmi = (BITMAPINFO *)thunk_FUN_10003410(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_1 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,arg_2,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  return val_1;
}


