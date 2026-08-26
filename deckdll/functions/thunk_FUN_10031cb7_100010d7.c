/*
 * Decompiled function: thunk_FUN_10031cb7
 * Entry Point: 100010d7
 * Size: 5 bytes
 */
#include "deckdll.h"


HBITMAP thunk_FUN_10031cb7(BITMAPINFO *arg1,void *arg2)

{
  WORD WVar1;
  BYTE *lpBits;
  BITMAPINFO *lpbmi;
  DWORD DVar2;
  HANDLE hSection;
  HDC hdc;
  int iStack_30;
  HBITMAP pHStack_2c;
  DWORD DStack_28;
  void *pvStack_10;
  DWORD DStack_c;
  int iStack_8;
  
  pHStack_2c = (HBITMAP)0x0;
  WVar1 = (arg1->bmiHeader).biBitCount;
  if (WVar1 == 1) {
    iStack_8 = 2;
  }
  else if (WVar1 == 4) {
    iStack_8 = 0x10;
  }
  else if (WVar1 == 8) {
    iStack_8 = 0x100;
  }
  else {
    iStack_8 = 0;
  }
  lpBits = &arg1->bmiColors[iStack_8 + -10].rgbBlue + (arg1->bmiHeader).biSize;
  lpbmi = malloc(iStack_8 * 4 + 0x28);
  if (lpbmi != (BITMAPINFO *)0x0) {
    memcpy(lpbmi,arg1,0x28);
    memcpy(lpbmi->bmiColors,arg1->bmiColors,iStack_8 << 2);
    if ((arg1->bmiHeader).biWidth % 3 == 0) {
      iStack_30 = 0;
    }
    else {
      iStack_30 = 4 - (arg1->bmiHeader).biWidth % 3;
    }
    DStack_28 = ((arg1->bmiHeader).biWidth + iStack_30) * (arg1->bmiHeader).biHeight;
    switch((arg1->bmiHeader).biBitCount) {
    case 1:
      break;
    case 4:
      break;
    case 8:
      break;
    case 0x10:
      DStack_28 = DStack_28 * 2;
      break;
    case 0x18:
      DStack_28 = DStack_28 * 3;
      break;
    case 0x20:
      DStack_28 = DStack_28 * 4;
    }
    DStack_c = (arg1->bmiHeader).biSizeImage;
    DVar2 = DStack_c;
    if ((int)DStack_c <= (int)DStack_28) {
      DVar2 = DStack_28;
    }
    hSection = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                  DVar2 + 1000,(LPCSTR)0x0);
    if (hSection != (HANDLE)0x0) {
      hdc = GetDC((HWND)0x0);
      thunk_FUN_10031425(hdc);
      (lpbmi->bmiHeader).biSizeImage = DStack_28;
      (lpbmi->bmiHeader).biCompression = 0;
      if (iStack_8 == 0) {
        pHStack_2c = CreateDIBSection(hdc,lpbmi,0,&pvStack_10,hSection,0);
      }
      else {
        pHStack_2c = CreateDIBSection(hdc,lpbmi,0,&pvStack_10,hSection,0);
      }
      (lpbmi->bmiHeader).biSizeImage = DStack_c;
      if (pHStack_2c == (HBITMAP)0x0) {
        CloseHandle(hSection);
      }
      else {
        if (iStack_8 == 0) {
          SetDIBits(hdc,pHStack_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        else {
          SetDIBits(hdc,pHStack_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        if (arg2 != (void *)0x0) {
          memcpy(arg2,arg1,0x28);
          memcpy((void *)((int)arg2 + 0x28),arg1->bmiColors,iStack_8 << 2);
        }
        SetBitmapDimensionEx(pHStack_2c,(int)hSection,0,(LPSIZE)0x0);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    free(lpbmi);
  }
  return pHStack_2c;
}


