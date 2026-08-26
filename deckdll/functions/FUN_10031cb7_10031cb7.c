/*
 * Decompiled function: FUN_10031cb7
 * Entry Point: 10031cb7
 * Size: 795 bytes
 */
#include "deckdll.h"


HBITMAP FUN_10031cb7(BITMAPINFO *arg1,void *arg2)

{
  WORD WVar1;
  BYTE *lpBits;
  BITMAPINFO *lpbmi;
  DWORD DVar2;
  HANDLE hSection;
  HDC hdc;
  int local_30;
  HBITMAP local_2c;
  DWORD local_28;
  void *local_10;
  DWORD local_c;
  int local_8;
  
  local_2c = (HBITMAP)0x0;
  WVar1 = (arg1->bmiHeader).biBitCount;
  if (WVar1 == 1) {
    local_8 = 2;
  }
  else if (WVar1 == 4) {
    local_8 = 0x10;
  }
  else if (WVar1 == 8) {
    local_8 = 0x100;
  }
  else {
    local_8 = 0;
  }
  lpBits = &arg1->bmiColors[local_8 + -10].rgbBlue + (arg1->bmiHeader).biSize;
  lpbmi = malloc(local_8 * 4 + 0x28);
  if (lpbmi != (BITMAPINFO *)0x0) {
    memcpy(lpbmi,arg1,0x28);
    memcpy(lpbmi->bmiColors,arg1->bmiColors,local_8 << 2);
    if ((arg1->bmiHeader).biWidth % 3 == 0) {
      local_30 = 0;
    }
    else {
      local_30 = 4 - (arg1->bmiHeader).biWidth % 3;
    }
    local_28 = ((arg1->bmiHeader).biWidth + local_30) * (arg1->bmiHeader).biHeight;
    switch((arg1->bmiHeader).biBitCount) {
    case 1:
      break;
    case 4:
      break;
    case 8:
      break;
    case 0x10:
      local_28 = local_28 * 2;
      break;
    case 0x18:
      local_28 = local_28 * 3;
      break;
    case 0x20:
      local_28 = local_28 * 4;
    }
    local_c = (arg1->bmiHeader).biSizeImage;
    DVar2 = local_c;
    if ((int)local_c <= (int)local_28) {
      DVar2 = local_28;
    }
    hSection = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                  DVar2 + 1000,(LPCSTR)0x0);
    if (hSection != (HANDLE)0x0) {
      hdc = GetDC((HWND)0x0);
      thunk_FUN_10031425(hdc);
      (lpbmi->bmiHeader).biSizeImage = local_28;
      (lpbmi->bmiHeader).biCompression = 0;
      if (local_8 == 0) {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&local_10,hSection,0);
      }
      else {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&local_10,hSection,0);
      }
      (lpbmi->bmiHeader).biSizeImage = local_c;
      if (local_2c == (HBITMAP)0x0) {
        CloseHandle(hSection);
      }
      else {
        if (local_8 == 0) {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        else {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        if (arg2 != (void *)0x0) {
          memcpy(arg2,arg1,0x28);
          memcpy((void *)((int)arg2 + 0x28),arg1->bmiColors,local_8 << 2);
        }
        SetBitmapDimensionEx(local_2c,(int)hSection,0,(LPSIZE)0x0);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    free(lpbmi);
  }
  return local_2c;
}


