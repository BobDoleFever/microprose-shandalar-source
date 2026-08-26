/*
 * sidlib/text.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: FUN_0050edf0
 * Entry Point: 0050edf0
 * Size: 253 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0050edf0(char *str_1)

{
  FILE *_File;
  int iVar1;
  long *_DstBuf;
  int iVar2;
  int local_44;
  long alStack_40 [16];
  
  local_44 = 0;
  _File = fopen(str_1,&DAT_0052afc4);
  AssertOrLog((uint)(_File != (FILE *)0x0),0x532744,0x7f,
              PTR_s_File__s_could_not_be_opened__EXI_00530fb0);
  fread(&local_44,2,1,_File);
  _DAT_00707710 = local_44;
  iVar1 = 1;
  AssertOrLog((uint)(local_44 < 0x10),0x532744,0x86,s_Can_not_load_more_than__d_fonts_00532720);
  if (0 < local_44) {
    _DstBuf = alStack_40;
    do {
      _DstBuf = _DstBuf + 1;
      iVar1 = iVar1 + 1;
      *_DstBuf = 0;
      fread(_DstBuf,2,1,_File);
    } while (iVar1 <= local_44);
  }
  iVar1 = 1;
  if (0 < local_44) {
    do {
      fseek(_File,alStack_40[iVar1],0);
      iVar2 = iVar1 + 1;
      FUN_0050eef0(iVar1,_File);
      iVar1 = iVar2;
    } while (iVar2 <= local_44);
  }
  fclose(_File);
  return local_44;
}



/*
 * Decompiled function: FUN_0050eef0
 * Entry Point: 0050eef0
 * Size: 497 bytes
 */


undefined4 FUN_0050eef0(int arg1,FILE *fp)

{
  size_t _Count;
  uint nHeight;
  uint uVar1;
  void *_DstBuf;
  uint uVar2;
  HBITMAP pHVar3;
  byte *pbVar4;
  HDC pHVar5;
  int iVar6;
  int iVar7;
  uint _Count_00;
  int iVar8;
  
  iVar6 = arg1 * 0x2a0;
  pbVar4 = &DAT_007077a0 + iVar6;
  fseek(fp,-8,1);
  fread(pbVar4,1,8,fp);
  _Count = ((uint)(byte)(&DAT_007077a1)[iVar6] - (uint)*pbVar4) + 1;
  if ((&DAT_007077a3)[iVar6] == '\0') {
    fseek(fp,-8 - _Count,1);
    fread(&DAT_00707720 + (uint)*pbVar4 + iVar6,1,_Count,fp);
    fseek(fp,8,1);
  }
  nHeight = (uint)(byte)(&DAT_007077a4)[iVar6];
  _Count_00 = (byte)(&DAT_007077a2)[iVar6] * _Count;
  uVar1 = _Count_00 & 1;
  (&DAT_007077a7)[iVar6] = (char)uVar1;
  if (*(void **)(&DAT_007077b4 + iVar6) != (void *)0x0) {
    free(*(void **)(&DAT_007077b4 + iVar6));
  }
  if (*(HGDIOBJ *)(&DAT_007077ac + iVar6) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(&DAT_007077ac + iVar6));
  }
  if (*(HGDIOBJ *)(&DAT_007077a8 + iVar6) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(&DAT_007077a8 + iVar6));
  }
  iVar8 = (uVar1 + _Count_00) * nHeight;
  _DstBuf = malloc(iVar8 + 10000);
  *(void **)(&DAT_007077b4 + iVar6) = _DstBuf;
  for (uVar2 = nHeight; uVar2 != 0; uVar2 = uVar2 - 1) {
    fread(_DstBuf,1,_Count_00,fp);
    _DstBuf = (void *)((int)_DstBuf + uVar1 + _Count_00);
  }
  pHVar3 = CreateBitmap(_Count_00 * 8,nHeight,1,1,*(void **)(&DAT_007077b4 + iVar6));
  *(HBITMAP *)(&DAT_007077ac + iVar6) = pHVar3;
  pbVar4 = *(byte **)(&DAT_007077b4 + iVar6);
  iVar7 = iVar8;
  if (0 < iVar8) {
    do {
      iVar7 = iVar7 + -1;
      *pbVar4 = ~*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (iVar7 != 0);
  }
  pHVar3 = CreateBitmap(_Count_00 * 8,nHeight,1,1,*(void **)(&DAT_007077b4 + iVar6));
  *(HBITMAP *)(&DAT_007077a8 + iVar6) = pHVar3;
  pbVar4 = *(byte **)(&DAT_007077b4 + iVar6);
  if (0 < iVar8) {
    do {
      iVar8 = iVar8 + -1;
      *pbVar4 = ~*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (iVar8 != 0);
  }
  if (*(int *)(&DAT_007077b0 + iVar6) == 0) {
    pHVar5 = CreateCompatibleDC((HDC)0x0);
    *(HDC *)(&DAT_007077b0 + iVar6) = pHVar5;
  }
  *(undefined4 *)(&DAT_007077b8 + iVar6) = 0;
  return 0;
}



/*
 * Decompiled function: FUN_0050f0f0
 * Entry Point: 0050f0f0
 * Size: 237 bytes
 */


undefined4 FUN_0050f0f0(int arg_1,int arg_2,char *str_3)

{
  FILE *_File;
  undefined4 uVar1;
  long *_DstBuf;
  int iVar2;
  int local_44;
  long alStack_40 [16];
  
  local_44 = 0;
  AssertOrLog((uint)(arg_1 < 0x10),0x532744,0xd7,s_Can_not_load_more_than__d_fonts_00532720);
  _File = fopen(str_3,&DAT_0052afc4);
  AssertOrLog((uint)(_File != (FILE *)0x0),0x532744,0xd9,
              PTR_s_File__s_could_not_be_opened__EXI_00530fb0);
  iVar2 = 1;
  fread(&local_44,2,1,_File);
  if (1 < local_44) {
    _DstBuf = alStack_40;
    do {
      _DstBuf = _DstBuf + 1;
      iVar2 = iVar2 + 1;
      *_DstBuf = 0;
      fread(_DstBuf,2,1,_File);
    } while (iVar2 < local_44);
  }
  if (local_44 <= arg_2) {
    return 0xffffffff;
  }
  fseek(_File,alStack_40[arg_2],0);
  uVar1 = FUN_0050eef0(arg_1,_File);
  return uVar1;
}



/*
 * Decompiled function: FUN_0050f1e0
 * Entry Point: 0050f1e0
 * Size: 197 bytes
 */


undefined4 FUN_0050f1e0(int arg_1,int arg_2,LPCSTR str_3,LPCSTR str_4,int arg_5,DWORD arg_6)

{
  char cVar1;
  HFONT pHVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  AddFontResourceA(str_3);
  iVar5 = arg_1 * 0x2a0;
  pHVar2 = CreateFontA(arg_2,0,0,0,arg_5,arg_6,0,0,0,0,0,0,0,str_4);
  uVar3 = 0xffffffff;
  *(HFONT *)(&DAT_007077bc + iVar5) = pHVar2;
  do {
    pcVar6 = str_3;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = str_3 + 1;
    cVar1 = *str_3;
    str_3 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  pcVar7 = &DAT_007077c0 + iVar5;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar6 = str_4;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = str_4 + 1;
    cVar1 = *str_4;
    str_4 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  pcVar7 = &DAT_007078c0 + iVar5;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  (&DAT_007077a4)[iVar5] = (char)((int)(arg_2 * 0xd + (arg_2 * 0xd >> 0x1f & 0xfU)) >> 4);
  *(undefined4 *)(&DAT_007077b8 + iVar5) = 1;
  return 1;
}



/*
 * Decompiled function: FUN_0050f2e0
 * Entry Point: 0050f2e0
 * Size: 108 bytes
 */


HFONT FUN_0050f2e0(int arg1,LONG arg2)

{
  HANDLE h;
  HFONT pHVar1;
  int iVar2;
  LOGFONTA local_3c;
  
  iVar2 = arg1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar2) == 0) {
    return (HFONT)0x0;
  }
  h = *(HANDLE *)(&DAT_007077bc + iVar2);
  GetObjectA(h,0x3c,&local_3c);
  DeleteObject(h);
  local_3c.lfHeight = arg2;
  (&DAT_007077a4)[iVar2] = (char)arg2;
  pHVar1 = CreateFontIndirectA(&local_3c);
  *(HFONT *)(&DAT_007077bc + iVar2) = pHVar1;
  return pHVar1;
}



/*
 * Decompiled function: FUN_0050f350
 * Entry Point: 0050f350
 * Size: 59 bytes
 */


BOOL FUN_0050f350(int arg_1)

{
  BOOL BVar1;
  int iVar2;
  
  iVar2 = arg_1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar2) == 0) {
    return 0;
  }
  DeleteObject(*(HGDIOBJ *)(&DAT_007077bc + iVar2));
  BVar1 = RemoveFontResourceA(&DAT_007077c0 + iVar2);
  return BVar1;
}



/*
 * Decompiled function: FUN_0050f390
 * Entry Point: 0050f390
 * Size: 172 bytes
 */


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



/*
 * Decompiled function: FUN_0050f440
 * Entry Point: 0050f440
 * Size: 458 bytes
 */


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



/*
 * Decompiled function: FUN_0050f610
 * Entry Point: 0050f610
 * Size: 304 bytes
 */


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



/*
 * Decompiled function: Mem_AllocOrFree_0050f740
 * Entry Point: 0050f740
 * Size: 32 bytes
 */


int Mem_AllocOrFree_0050f740(int arg_1)

{
  return (uint)(byte)(&DAT_007077a4)[arg_1 * 0x2a0] + (uint)(byte)(&DAT_007077a6)[arg_1 * 0x2a0];
}



/*
 * Decompiled function: FUN_0050f760
 * Entry Point: 0050f760
 * Size: 187 bytes
 */


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



/*
 * Decompiled function: FUN_0050f820
 * Entry Point: 0050f820
 * Size: 978 bytes
 */


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



/*
 * Decompiled function: Mem_AllocOrFree_0050fc00
 * Entry Point: 0050fc00
 * Size: 25 bytes
 */


void Mem_AllocOrFree_0050fc00(void)

{
  DAT_00625178 = malloc(0x200000);
  DAT_0062517c = DAT_00625178;
  return;
}



/*
 * Decompiled function: FUN_0050fc20
 * Entry Point: 0050fc20
 * Size: 46 bytes
 */


void FUN_0050fc20(void)

{
  *DAT_0062517c = 0xffffffff;
  DAT_00625178 = (int)_expand((void *)DAT_00625178,(int)DAT_0062517c + (0x10 - DAT_00625178));
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0050fc50
 * Entry Point: 0050fc50
 * Size: 17 bytes
 */


void Mem_AllocOrFree_0050fc50(void *arg_1)

{
  free(arg_1);
  return;
}



/*
 * Decompiled function: FUN_0050fc70
 * Entry Point: 0050fc70
 * Size: 70 bytes
 */


size_t FUN_0050fc70(void *arg1,char *str_2)

{
  size_t _Count;
  FILE *_File;
  
  _Count = _msize(arg1);
  _File = fopen(str_2,&DAT_00532768);
  fwrite(arg1,1,_Count,_File);
  fclose(_File);
  return _Count;
}



