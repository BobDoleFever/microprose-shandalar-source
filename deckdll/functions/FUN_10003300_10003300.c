/*
 * Decompiled function: DeckDll_RenderCardPreview
 * Entry Point: 10003300
 * Size: 92 bytes
 */
#include "deckdll.h"


int32_t DeckDll_RenderCardPreview(HWND hwnd)

{
  HDC hDC;
  HBRUSH hbr;
  tagRECT local_10;
  
  if (hwnd == (HWND)0x0) {
    return 0;
  }
  hDC = GetDC(hwnd);
  GetClientRect(hwnd,&local_10);
  hbr = GetStockObject(0);
  FillRect(hDC,&local_10,hbr);
  ReleaseDC(hwnd,hDC);
  return 1;
}


