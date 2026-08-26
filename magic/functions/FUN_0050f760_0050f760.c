/*
 * Decompiled function: FUN_0050f760
 * Entry Point: 0050f760
 * Size: 187 bytes
 */
#include "magic.h"


undefined4 FUN_0050f760(int *x,int y,int width,LPCSTR str_4)

{
  char cVar1;
  HDC hdc;
  HGDIOBJ h;
  uint uVar2;
  LPCSTR pCVar3;
  
  hdc = *(HDC *)((&DAT_0070a850)[*x] + 4);
  h = SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077bc + x[8] * 0x2a0));
  uVar2 = x[6];
  if (0xfd < (int)uVar2) {
    uVar2 = 0xfe;
  }
  SetTextColor(hdc,uVar2 & 0xffff | 0x1000000);
  SetBkMode(hdc,1);
  uVar2 = 0xffffffff;
  pCVar3 = str_4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pCVar3;
    pCVar3 = pCVar3 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,y,width - ((int)((uint)(byte)(&DAT_007077a4)[x[8] * 0x2a0] * 4) >> 4),str_4,
           ~uVar2 - 1);
  SelectObject(hdc,h);
  return 1;
}


