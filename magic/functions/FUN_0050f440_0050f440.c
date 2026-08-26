/*
 * Decompiled function: FUN_0050f440
 * Entry Point: 0050f440
 * Size: 458 bytes
 */
#include "magic.h"


int FUN_0050f440(int *arg1,char *str_2)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  HGDIOBJ h;
  HDC pHVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  LPCSTR pCVar10;
  int local_18;
  int local_14;
  _ABC local_c;
  
  local_18 = 0;
  local_14 = -1;
  iVar9 = arg1[8] * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar9) == 0) {
    cVar2 = *str_2;
    while (cVar2 != '\0') {
      cVar2 = *str_2;
      if (cVar2 == '\n') {
        if (local_14 < local_18) {
          local_14 = local_18;
        }
        local_18 = 0;
      }
      else {
        if (*(int *)(&DAT_007077b8 + iVar9) == 0) {
          bVar3 = (&DAT_007077a3)[iVar9];
          if (bVar3 == 0) {
            bVar3 = (&DAT_00707720)[iVar9 + cVar2];
            bVar4 = (&DAT_007077a5)[iVar9];
          }
          else {
            bVar4 = (&DAT_007077a5)[iVar9];
          }
          iVar6 = (uint)bVar4 + (uint)bVar3;
        }
        else {
          pHVar5 = GetDC((HWND)0x0);
          SelectObject(pHVar5,*(HGDIOBJ *)(&DAT_007077bc + iVar9));
          GetCharABCWidthsA(pHVar5,(int)cVar2,(int)cVar2,&local_c);
          ReleaseDC((HWND)0x0,pHVar5);
          iVar6 = local_c.abcB + local_c.abcC + local_c.abcA;
        }
        local_18 = local_18 + iVar6;
      }
      pcVar8 = str_2 + 1;
      str_2 = str_2 + 1;
      cVar2 = *pcVar8;
    }
    if (local_14 <= local_18) {
      local_14 = local_18;
    }
    return local_14;
  }
  pHVar5 = *(HDC *)((&DAT_0070a850)[*arg1] + 4);
  h = SelectObject(pHVar5,*(HGDIOBJ *)(&DAT_007077bc + iVar9));
  cVar2 = *str_2;
  pcVar8 = str_2;
  while (cVar2 != '\0') {
    if (*str_2 == '\n') {
      uVar7 = 0xffffffff;
      *str_2 = '\0';
      pCVar10 = pcVar8;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar2 = *pCVar10;
        pCVar10 = pCVar10 + 1;
      } while (cVar2 != '\0');
      GetTextExtentPoint32A(pHVar5,pcVar8,~uVar7 - 1,(LPSIZE)&local_c);
      if (local_14 < local_c.abcA + 2) {
        local_14 = local_c.abcA + 2;
      }
      pcVar8 = str_2 + 1;
      *str_2 = '\n';
    }
    pcVar1 = str_2 + 1;
    str_2 = str_2 + 1;
    cVar2 = *pcVar1;
  }
  uVar7 = 0xffffffff;
  pCVar10 = pcVar8;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pCVar10;
    pCVar10 = pCVar10 + 1;
  } while (cVar2 != '\0');
  GetTextExtentPoint32A(pHVar5,pcVar8,~uVar7 - 1,(LPSIZE)&local_c);
  if (local_14 < local_c.abcA + 2) {
    local_14 = local_c.abcA + 2;
  }
  SelectObject(pHVar5,h);
  return local_14;
}


