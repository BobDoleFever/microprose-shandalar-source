/*
 * Decompiled function: FUN_0050f820
 * Entry Point: 0050f820
 * Size: 978 bytes
 */
#include "magic.h"


int FUN_0050f820(int *x,int y,int width,char *str_4)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  HDC pHVar4;
  HDC hdc;
  uint uVar5;
  HDC pHVar6;
  int iVar7;
  UINT UVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  _ABC local_20;
  uint local_14;
  uint local_10;
  uint local_c;
  char *local_8;
  int local_4;
  
  local_4 = y;
  local_8 = str_4;
  if (*str_4 == '\0') {
    return 0;
  }
  if ((width < x[2]) ||
     (iVar7 = x[8] * 0x2a0,
     x[4] < (int)((uint)(byte)(&DAT_007077a4)[iVar7] + (uint)(byte)(&DAT_007077a6)[iVar7] + width)))
  {
    return 0;
  }
  if (*(int *)(&DAT_007077b8 + iVar7) == 0) {
    pHVar4 = *(HDC *)((&DAT_0070a850)[*x] + 4);
    hdc = *(HDC *)(&DAT_007077b0 + iVar7);
    local_c = (uint)(byte)(&DAT_007077a4)[iVar7];
    local_10 = (uint)(byte)(&DAT_007077a2)[iVar7];
    local_14 = (uint)(byte)(&DAT_007077a0)[iVar7];
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077a8 + iVar7));
    SetTextColor(pHVar4,0x1000000);
    SetBkColor(pHVar4,0xffffff);
    do {
      UVar8 = (UINT)*str_4;
      iVar11 = (UVar8 - local_14) * local_10;
      if (*(int *)(&DAT_007077b8 + iVar7) == 0) {
        bVar2 = (&DAT_007077a3)[iVar7];
        if (bVar2 == 0) {
          bVar3 = (&DAT_00707720)[UVar8 + iVar7];
          bVar2 = (&DAT_007077a5)[iVar7];
        }
        else {
          bVar3 = (&DAT_007077a5)[iVar7];
        }
        iVar9 = (uint)bVar3 + (uint)bVar2;
      }
      else {
        pHVar6 = GetDC((HWND)0x0);
        SelectObject(pHVar6,*(HGDIOBJ *)(&DAT_007077bc + iVar7));
        GetCharABCWidthsA(pHVar6,UVar8,UVar8,&local_20);
        ReleaseDC((HWND)0x0,pHVar6);
        iVar9 = local_20.abcB + local_20.abcC + local_20.abcA;
      }
      str_4 = str_4 + 1;
      BitBlt(pHVar4,y,width,iVar9,local_c,hdc,iVar11 * 8,0,0x8800c6);
      y = y + iVar9;
    } while (*str_4 != '\0');
    y = local_4;
    str_4 = local_8;
    uVar5 = 0xfe;
    if (x[6] != 0xff) {
      uVar5 = x[6];
    }
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077ac + iVar7));
    SetTextColor(pHVar4,0x1000000);
    SetBkColor(pHVar4,uVar5 & 0xffff | 0x1000000);
    do {
      UVar8 = (UINT)*str_4;
      iVar11 = (UVar8 - local_14) * local_10;
      if (*(int *)(&DAT_007077b8 + iVar7) == 0) {
        bVar2 = (&DAT_007077a3)[iVar7];
        if (bVar2 == 0) {
          bVar3 = (&DAT_00707720)[UVar8 + iVar7];
          bVar2 = (&DAT_007077a5)[iVar7];
        }
        else {
          bVar3 = (&DAT_007077a5)[iVar7];
        }
        iVar9 = (uint)bVar3 + (uint)bVar2;
      }
      else {
        pHVar6 = GetDC((HWND)0x0);
        SelectObject(pHVar6,*(HGDIOBJ *)(&DAT_007077bc + iVar7));
        GetCharABCWidthsA(pHVar6,UVar8,UVar8,&local_20);
        ReleaseDC((HWND)0x0,pHVar6);
        iVar9 = local_20.abcB + local_20.abcC + local_20.abcA;
      }
      BitBlt(pHVar4,y,width,iVar9,local_c,hdc,iVar11 * 8,0,0xee0086);
      y = y + iVar9;
      str_4 = str_4 + 1;
    } while (*str_4 != '\0');
    return (int)str_4 - (int)local_8;
  }
  pHVar4 = *(HDC *)((&DAT_0070a850)[*x] + 4);
  local_20.abcA = (int)SelectObject(pHVar4,*(HGDIOBJ *)(&DAT_007077bc + iVar7));
  uVar5 = x[6];
  if (0xfd < (int)uVar5) {
    uVar5 = 0xfe;
  }
  SetTextColor(pHVar4,uVar5 & 0xffff | 0x1000000);
  SetBkMode(pHVar4,1);
  uVar5 = 0xffffffff;
  pcVar10 = str_4;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  TextOutA(pHVar4,y,width - ((int)((uint)(byte)(&DAT_007077a4)[x[8] * 0x2a0] * 4) >> 4),str_4,
           ~uVar5 - 1);
  SelectObject(pHVar4,(HGDIOBJ)local_20.abcA);
  return 1;
}


