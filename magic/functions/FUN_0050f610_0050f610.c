/*
 * Decompiled function: FUN_0050f610
 * Entry Point: 0050f610
 * Size: 304 bytes
 */
#include "magic.h"


int FUN_0050f610(int *arg_1,char *str_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  HGDIOBJ h;
  HDC pHVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int local_10;
  _ABC local_c;
  
  local_10 = 0;
  iVar6 = arg_1[8] * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar6) == 0) {
    cVar1 = *str_2;
    while ((cVar1 != '\0' && (bVar7 = arg_3 != 0, arg_3 = arg_3 + -1, bVar7))) {
      cVar1 = *str_2;
      str_2 = str_2 + 1;
      if (*(int *)(&DAT_007077b8 + iVar6) == 0) {
        bVar2 = (&DAT_007077a3)[iVar6];
        if (bVar2 == 0) {
          bVar2 = (&DAT_00707720)[iVar6 + cVar1];
          bVar3 = (&DAT_007077a5)[iVar6];
        }
        else {
          bVar3 = (&DAT_007077a5)[iVar6];
        }
        iVar5 = (uint)bVar3 + (uint)bVar2;
      }
      else {
        pHVar4 = GetDC((HWND)0x0);
        SelectObject(pHVar4,*(HGDIOBJ *)(&DAT_007077bc + iVar6));
        GetCharABCWidthsA(pHVar4,(int)cVar1,(int)cVar1,&local_c);
        ReleaseDC((HWND)0x0,pHVar4);
        iVar5 = local_c.abcB + local_c.abcC + local_c.abcA;
      }
      local_10 = local_10 + iVar5;
      cVar1 = *str_2;
    }
    return local_10;
  }
  pHVar4 = *(HDC *)((&DAT_0070a850)[*arg_1] + 4);
  h = SelectObject(pHVar4,*(HGDIOBJ *)(&DAT_007077bc + iVar6));
  GetTextExtentPoint32A(pHVar4,str_2,arg_3,(LPSIZE)&local_c);
  SelectObject(pHVar4,h);
  return local_c.abcA;
}


