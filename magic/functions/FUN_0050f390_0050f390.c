/*
 * Decompiled function: FUN_0050f390
 * Entry Point: 0050f390
 * Size: 172 bytes
 */
#include "magic.h"


int FUN_0050f390(int arg1,char arg2)

{
  HDC hdc;
  int iVar1;
  _ABC local_c;
  
  iVar1 = arg1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar1) != 0) {
    hdc = GetDC((HWND)0x0);
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077bc + iVar1));
    GetCharABCWidthsA(hdc,(int)arg2,(int)arg2,&local_c);
    ReleaseDC((HWND)0x0,hdc);
    return local_c.abcB + local_c.abcC + local_c.abcA;
  }
  if ((&DAT_007077a3)[iVar1] != 0) {
    return (uint)(byte)(&DAT_007077a3)[iVar1] + (uint)(byte)(&DAT_007077a5)[iVar1];
  }
  return (uint)(byte)(&DAT_007077a5)[iVar1] + (uint)(byte)(&DAT_00707720)[iVar1 + arg2];
}


