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
 * Decompiled function: Font_LoadFontFile
 * Entry Point: 0050edf0
 * Size: 253 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Font_LoadFontFile(char *filepath)

{
  FILE *_File;
  int val_1;
  long *_DstBuf;
  int val_2;
  int local_44;
  long alStack_40 [16];
  
  local_44 = 0;
  _File = fopen(str_1,&DAT_0052afc4);
  AssertOrLog((uint32_t)(_File != (FILE *)0x0),0x532744,0x7f,
              PTR_s_File__s_could_not_be_opened__EXI_00530fb0);
  fread(&local_44,2,1,_File);
  _DAT_00707710 = local_44;
  val_1 = 1;
  AssertOrLog((uint32_t)(local_44 < 0x10),0x532744,0x86,s_Can_not_load_more_than__d_fonts_00532720);
  if (0 < local_44) {
    _DstBuf = alStack_40;
    do {
      _DstBuf = _DstBuf + 1;
      val_1 = val_1 + 1;
      *_DstBuf = 0;
      fread(_DstBuf,2,1,_File);
    } while (val_1 <= local_44);
  }
  val_1 = 1;
  if (0 < local_44) {
    do {
      fseek(_File,alStack_40[val_1],0);
      val_2 = val_1 + 1;
      FUN_0050eef0(val_1,_File);
      val_1 = val_2;
    } while (val_2 <= local_44);
  }
  fclose(_File);
  return local_44;
}



/*
 * Decompiled function: FUN_0050eef0
 * Entry Point: 0050eef0
 * Size: 497 bytes
 */


int32_t FUN_0050eef0(int arg1,FILE *fp)

{
  size_t _Count;
  uint32_t nHeight;
  uint32_t uval_1;
  void *_DstBuf;
  uint32_t uval_2;
  HBITMAP pHVar3;
  uint8_t *pbVar4;
  HDC pHVar5;
  int val_6;
  int val_7;
  uint32_t _Count_00;
  int val_8;
  
  val_6 = arg1 * 0x2a0;
  pbVar4 = &DAT_007077a0 + val_6;
  fseek(fp,-8,1);
  fread(pbVar4,1,8,fp);
  _Count = ((uint32_t)(uint8_t)(&DAT_007077a1)[val_6] - (uint32_t)*pbVar4) + 1;
  if ((&DAT_007077a3)[val_6] == '\0') {
    fseek(fp,-8 - _Count,1);
    fread(&DAT_00707720 + (uint32_t)*pbVar4 + val_6,1,_Count,fp);
    fseek(fp,8,1);
  }
  nHeight = (uint32_t)(uint8_t)(&DAT_007077a4)[val_6];
  _Count_00 = (uint8_t)(&DAT_007077a2)[val_6] * _Count;
  uval_1 = _Count_00 & 1;
  (&DAT_007077a7)[val_6] = (char)uval_1;
  if (*(void **)(&DAT_007077b4 + val_6) != (void *)0x0) {
    free(*(void **)(&DAT_007077b4 + val_6));
  }
  if (*(HGDIOBJ *)(&DAT_007077ac + val_6) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(&DAT_007077ac + val_6));
  }
  if (*(HGDIOBJ *)(&DAT_007077a8 + val_6) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(&DAT_007077a8 + val_6));
  }
  val_8 = (uval_1 + _Count_00) * nHeight;
  _DstBuf = malloc(val_8 + 10000);
  *(void **)(&DAT_007077b4 + val_6) = _DstBuf;
  for (uval_2 = nHeight; uval_2 != 0; uval_2 = uval_2 - 1) {
    fread(_DstBuf,1,_Count_00,fp);
    _DstBuf = (void *)((int)_DstBuf + uval_1 + _Count_00);
  }
  pHVar3 = CreateBitmap(_Count_00 * 8,nHeight,1,1,*(void **)(&DAT_007077b4 + val_6));
  *(HBITMAP *)(&DAT_007077ac + val_6) = pHVar3;
  pbVar4 = *(uint8_t **)(&DAT_007077b4 + val_6);
  val_7 = val_8;
  if (0 < val_8) {
    do {
      val_7 = val_7 + -1;
      *pbVar4 = ~*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (val_7 != 0);
  }
  pHVar3 = CreateBitmap(_Count_00 * 8,nHeight,1,1,*(void **)(&DAT_007077b4 + val_6));
  *(HBITMAP *)(&DAT_007077a8 + val_6) = pHVar3;
  pbVar4 = *(uint8_t **)(&DAT_007077b4 + val_6);
  if (0 < val_8) {
    do {
      val_8 = val_8 + -1;
      *pbVar4 = ~*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (val_8 != 0);
  }
  if (*(int *)(&DAT_007077b0 + val_6) == 0) {
    pHVar5 = CreateCompatibleDC((HDC)0x0);
    *(HDC *)(&DAT_007077b0 + val_6) = pHVar5;
  }
  *(int32_t *)(&DAT_007077b8 + val_6) = 0;
  return 0;
}



/*
 * Decompiled function: FUN_0050f0f0
 * Entry Point: 0050f0f0
 * Size: 237 bytes
 */


int32_t FUN_0050f0f0(int player_id,int card_slot,char *str_3)

{
  FILE *_File;
  int32_t uval_1;
  long *_DstBuf;
  int val_2;
  int local_44;
  long alStack_40 [16];
  
  local_44 = 0;
  AssertOrLog((uint32_t)(arg_1 < 0x10),0x532744,0xd7,s_Can_not_load_more_than__d_fonts_00532720);
  _File = fopen(str_3,&DAT_0052afc4);
  AssertOrLog((uint32_t)(_File != (FILE *)0x0),0x532744,0xd9,
              PTR_s_File__s_could_not_be_opened__EXI_00530fb0);
  val_2 = 1;
  fread(&local_44,2,1,_File);
  if (1 < local_44) {
    _DstBuf = alStack_40;
    do {
      _DstBuf = _DstBuf + 1;
      val_2 = val_2 + 1;
      *_DstBuf = 0;
      fread(_DstBuf,2,1,_File);
    } while (val_2 < local_44);
  }
  if (local_44 <= arg_2) {
    return 0xffffffff;
  }
  fseek(_File,alStack_40[arg_2],0);
  uval_1 = FUN_0050eef0(arg_1,_File);
  return uval_1;
}



/*
 * Decompiled function: FUN_0050f1e0
 * Entry Point: 0050f1e0
 * Size: 197 bytes
 */


int32_t FUN_0050f1e0(int player_id,int card_slot,LPCSTR str_3,LPCSTR str_4,int arg_5,DWORD arg_6)

{
  char cVar1;
  HFONT pHVar2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  char *pcVar6;
  char *pcVar7;
  
  AddFontResourceA(str_3);
  val_5 = arg_1 * 0x2a0;
  pHVar2 = CreateFontA(arg_2,0,0,0,arg_5,arg_6,0,0,0,0,0,0,0,str_4);
  uval_3 = 0xffffffff;
  *(HFONT *)(&DAT_007077bc + val_5) = pHVar2;
  do {
    pcVar6 = str_3;
    if (uval_3 == 0) break;
    uval_3 = uval_3 - 1;
    pcVar6 = str_3 + 1;
    cVar1 = *str_3;
    str_3 = pcVar6;
  } while (cVar1 != '\0');
  uval_3 = ~uval_3;
  pcVar6 = pcVar6 + -uval_3;
  pcVar7 = &DAT_007077c0 + val_5;
  for (uval_4 = uval_3 >> 2; uval_4 != 0; uval_4 = uval_4 - 1) {
    *(int32_t *)pcVar7 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uval_3 = uval_3 & 3; uval_3 != 0; uval_3 = uval_3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uval_3 = 0xffffffff;
  do {
    pcVar6 = str_4;
    if (uval_3 == 0) break;
    uval_3 = uval_3 - 1;
    pcVar6 = str_4 + 1;
    cVar1 = *str_4;
    str_4 = pcVar6;
  } while (cVar1 != '\0');
  uval_3 = ~uval_3;
  pcVar6 = pcVar6 + -uval_3;
  pcVar7 = &DAT_007078c0 + val_5;
  for (uval_4 = uval_3 >> 2; uval_4 != 0; uval_4 = uval_4 - 1) {
    *(int32_t *)pcVar7 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uval_3 = uval_3 & 3; uval_3 != 0; uval_3 = uval_3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  (&DAT_007077a4)[val_5] = (char)((int)(arg_2 * 0xd + (arg_2 * 0xd >> 0x1f & 0xfU)) >> 4);
  *(int32_t *)(&DAT_007077b8 + val_5) = 1;
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
  int val_2;
  LOGFONTA local_3c;
  
  val_2 = arg1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + val_2) == 0) {
    return (HFONT)0x0;
  }
  h = *(HANDLE *)(&DAT_007077bc + val_2);
  GetObjectA(h,0x3c,&local_3c);
  DeleteObject(h);
  local_3c.lfHeight = arg2;
  (&DAT_007077a4)[val_2] = (char)arg2;
  pHVar1 = CreateFontIndirectA(&local_3c);
  *(HFONT *)(&DAT_007077bc + val_2) = pHVar1;
  return pHVar1;
}



/*
 * Decompiled function: FUN_0050f350
 * Entry Point: 0050f350
 * Size: 59 bytes
 */


BOOL FUN_0050f350(int player_id)

{
  BOOL BVar1;
  int val_2;
  
  val_2 = arg_1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + val_2) == 0) {
    return 0;
  }
  DeleteObject(*(HGDIOBJ *)(&DAT_007077bc + val_2));
  BVar1 = RemoveFontResourceA(&DAT_007077c0 + val_2);
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
  int val_1;
  _ABC match_count;
  
  val_1 = arg1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + val_1) != 0) {
    hdc = GetDC((HWND)0x0);
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077bc + val_1));
    GetCharABCWidthsA(hdc,(int)arg2,(int)arg2,&match_count);
    ReleaseDC((HWND)0x0,hdc);
    return match_count.abcB + match_count.abcC + match_count.abcA;
  }
  if ((&DAT_007077a3)[val_1] != 0) {
    return (uint32_t)(uint8_t)(&DAT_007077a3)[val_1] + (uint32_t)(uint8_t)(&DAT_007077a5)[val_1];
  }
  return (uint32_t)(uint8_t)(&DAT_007077a5)[val_1] + (uint32_t)(uint8_t)(&DAT_00707720)[val_1 + arg2];
}



/*
 * Decompiled function: FUN_0050f440
 * Entry Point: 0050f440
 * Size: 458 bytes
 */


int FUN_0050f440(int *arg1,char *mode_str)

{
  char *char_ptr_1;
  char cVar2;
  uint8_t flag_3;
  uint8_t bVar4;
  HGDIOBJ h;
  HDC pHVar5;
  int val_6;
  uint32_t uval_7;
  char *pcVar8;
  int iVar9;
  LPCSTR pCVar10;
  int target_idx;
  int player_idx;
  _ABC match_count;
  
  target_idx = 0;
  player_idx = -1;
  iVar9 = arg1[8] * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar9) == 0) {
    cVar2 = *str_2;
    while (cVar2 != '\0') {
      cVar2 = *str_2;
      if (cVar2 == '\n') {
        if (player_idx < target_idx) {
          player_idx = target_idx;
        }
        target_idx = 0;
      }
      else {
        if (*(int *)(&DAT_007077b8 + iVar9) == 0) {
          flag_3 = (&DAT_007077a3)[iVar9];
          if (flag_3 == 0) {
            flag_3 = (&DAT_00707720)[iVar9 + cVar2];
            bVar4 = (&DAT_007077a5)[iVar9];
          }
          else {
            bVar4 = (&DAT_007077a5)[iVar9];
          }
          val_6 = (uint32_t)bVar4 + (uint32_t)flag_3;
        }
        else {
          pHVar5 = GetDC((HWND)0x0);
          SelectObject(pHVar5,*(HGDIOBJ *)(&DAT_007077bc + iVar9));
          GetCharABCWidthsA(pHVar5,(int)cVar2,(int)cVar2,&match_count);
          ReleaseDC((HWND)0x0,pHVar5);
          val_6 = match_count.abcB + match_count.abcC + match_count.abcA;
        }
        target_idx = target_idx + val_6;
      }
      pcVar8 = str_2 + 1;
      str_2 = str_2 + 1;
      cVar2 = *pcVar8;
    }
    if (player_idx <= target_idx) {
      player_idx = target_idx;
    }
    return player_idx;
  }
  pHVar5 = *(HDC *)((&g_ScreenSurfaces)[*arg1] + 4);
  h = SelectObject(pHVar5,*(HGDIOBJ *)(&DAT_007077bc + iVar9));
  cVar2 = *str_2;
  pcVar8 = str_2;
  while (cVar2 != '\0') {
    if (*str_2 == '\n') {
      uval_7 = 0xffffffff;
      *str_2 = '\0';
      pCVar10 = pcVar8;
      do {
        if (uval_7 == 0) break;
        uval_7 = uval_7 - 1;
        cVar2 = *pCVar10;
        pCVar10 = pCVar10 + 1;
      } while (cVar2 != '\0');
      GetTextExtentPoint32A(pHVar5,pcVar8,~uval_7 - 1,(LPSIZE)&match_count);
      if (player_idx < match_count.abcA + 2) {
        player_idx = match_count.abcA + 2;
      }
      pcVar8 = str_2 + 1;
      *str_2 = '\n';
    }
    char_ptr_1 = str_2 + 1;
    str_2 = str_2 + 1;
    cVar2 = *char_ptr_1;
  }
  uval_7 = 0xffffffff;
  pCVar10 = pcVar8;
  do {
    if (uval_7 == 0) break;
    uval_7 = uval_7 - 1;
    cVar2 = *pCVar10;
    pCVar10 = pCVar10 + 1;
  } while (cVar2 != '\0');
  GetTextExtentPoint32A(pHVar5,pcVar8,~uval_7 - 1,(LPSIZE)&match_count);
  if (player_idx < match_count.abcA + 2) {
    player_idx = match_count.abcA + 2;
  }
  SelectObject(pHVar5,h);
  return player_idx;
}



/*
 * Decompiled function: FUN_0050f610
 * Entry Point: 0050f610
 * Size: 304 bytes
 */


int FUN_0050f610(int *arg_1,char *mode_str,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  uint8_t flag_3;
  HGDIOBJ h;
  HDC pHVar4;
  int val_5;
  int val_6;
  bool bVar7;
  int card_idx;
  _ABC match_count;
  
  card_idx = 0;
  val_6 = arg_1[8] * 0x2a0;
  if (*(int *)(&DAT_007077b8 + val_6) == 0) {
    cVar1 = *str_2;
    while ((cVar1 != '\0' && (bVar7 = arg_3 != 0, arg_3 = arg_3 + -1, bVar7))) {
      cVar1 = *str_2;
      str_2 = str_2 + 1;
      if (*(int *)(&DAT_007077b8 + val_6) == 0) {
        flag_2 = (&DAT_007077a3)[val_6];
        if (flag_2 == 0) {
          flag_2 = (&DAT_00707720)[val_6 + cVar1];
          flag_3 = (&DAT_007077a5)[val_6];
        }
        else {
          flag_3 = (&DAT_007077a5)[val_6];
        }
        val_5 = (uint32_t)flag_3 + (uint32_t)flag_2;
      }
      else {
        pHVar4 = GetDC((HWND)0x0);
        SelectObject(pHVar4,*(HGDIOBJ *)(&DAT_007077bc + val_6));
        GetCharABCWidthsA(pHVar4,(int)cVar1,(int)cVar1,&match_count);
        ReleaseDC((HWND)0x0,pHVar4);
        val_5 = match_count.abcB + match_count.abcC + match_count.abcA;
      }
      card_idx = card_idx + val_5;
      cVar1 = *str_2;
    }
    return card_idx;
  }
  pHVar4 = *(HDC *)((&g_ScreenSurfaces)[*arg_1] + 4);
  h = SelectObject(pHVar4,*(HGDIOBJ *)(&DAT_007077bc + val_6));
  GetTextExtentPoint32A(pHVar4,str_2,arg_3,(LPSIZE)&match_count);
  SelectObject(pHVar4,h);
  return match_count.abcA;
}



/*
 * Decompiled function: Mem_AllocOrFree_0050f740
 * Entry Point: 0050f740
 * Size: 32 bytes
 */


int Mem_AllocOrFree_0050f740(int player_id)

{
  return (uint32_t)(uint8_t)(&DAT_007077a4)[arg_1 * 0x2a0] + (uint32_t)(uint8_t)(&DAT_007077a6)[arg_1 * 0x2a0];
}



/*
 * Decompiled function: FUN_0050f760
 * Entry Point: 0050f760
 * Size: 187 bytes
 */


int32_t FUN_0050f760(int *x,int y,int width,LPCSTR str_4)

{
  char cVar1;
  HDC hdc;
  HGDIOBJ h;
  uint32_t uval_2;
  LPCSTR pCVar3;
  
  hdc = *(HDC *)((&g_ScreenSurfaces)[*x] + 4);
  h = SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077bc + x[8] * 0x2a0));
  uval_2 = x[6];
  if (0xfd < (int)uval_2) {
    uval_2 = 0xfe;
  }
  SetTextColor(hdc,uval_2 & 0xffff | 0x1000000);
  SetBkMode(hdc,1);
  uval_2 = 0xffffffff;
  pCVar3 = str_4;
  do {
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    cVar1 = *pCVar3;
    pCVar3 = pCVar3 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,y,width - ((int)((uint32_t)(uint8_t)(&DAT_007077a4)[x[8] * 0x2a0] * 4) >> 4),str_4,
           ~uval_2 - 1);
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
  uint8_t flag_2;
  uint8_t flag_3;
  HDC pHVar4;
  HDC hdc;
  uint32_t uval_5;
  HDC pHVar6;
  int val_7;
  UINT UVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  _ABC loop_idx;
  uint32_t player_idx;
  uint32_t card_idx;
  uint32_t match_count;
  char *slot_idx;
  int local_4;
  
  local_4 = y;
  slot_idx = str_4;
  if (*str_4 == '\0') {
    return 0;
  }
  if ((width < x[2]) ||
     (val_7 = x[8] * 0x2a0,
     x[4] < (int)((uint32_t)(uint8_t)(&DAT_007077a4)[val_7] + (uint32_t)(uint8_t)(&DAT_007077a6)[val_7] + width)))
  {
    return 0;
  }
  if (*(int *)(&DAT_007077b8 + val_7) == 0) {
    pHVar4 = *(HDC *)((&g_ScreenSurfaces)[*x] + 4);
    hdc = *(HDC *)(&DAT_007077b0 + val_7);
    match_count = (uint32_t)(uint8_t)(&DAT_007077a4)[val_7];
    card_idx = (uint32_t)(uint8_t)(&DAT_007077a2)[val_7];
    player_idx = (uint32_t)(uint8_t)(&DAT_007077a0)[val_7];
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077a8 + val_7));
    SetTextColor(pHVar4,0x1000000);
    SetBkColor(pHVar4,0xffffff);
    do {
      UVar8 = (UINT)*str_4;
      iVar11 = (UVar8 - player_idx) * card_idx;
      if (*(int *)(&DAT_007077b8 + val_7) == 0) {
        flag_2 = (&DAT_007077a3)[val_7];
        if (flag_2 == 0) {
          flag_3 = (&DAT_00707720)[UVar8 + val_7];
          flag_2 = (&DAT_007077a5)[val_7];
        }
        else {
          flag_3 = (&DAT_007077a5)[val_7];
        }
        iVar9 = (uint32_t)flag_3 + (uint32_t)flag_2;
      }
      else {
        pHVar6 = GetDC((HWND)0x0);
        SelectObject(pHVar6,*(HGDIOBJ *)(&DAT_007077bc + val_7));
        GetCharABCWidthsA(pHVar6,UVar8,UVar8,&loop_idx);
        ReleaseDC((HWND)0x0,pHVar6);
        iVar9 = loop_idx.abcB + loop_idx.abcC + loop_idx.abcA;
      }
      str_4 = str_4 + 1;
      BitBlt(pHVar4,y,width,iVar9,match_count,hdc,iVar11 * 8,0,0x8800c6);
      y = y + iVar9;
    } while (*str_4 != '\0');
    y = local_4;
    str_4 = slot_idx;
    uval_5 = 0xfe;
    if (x[6] != 0xff) {
      uval_5 = x[6];
    }
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_007077ac + val_7));
    SetTextColor(pHVar4,0x1000000);
    SetBkColor(pHVar4,uval_5 & 0xffff | 0x1000000);
    do {
      UVar8 = (UINT)*str_4;
      iVar11 = (UVar8 - player_idx) * card_idx;
      if (*(int *)(&DAT_007077b8 + val_7) == 0) {
        flag_2 = (&DAT_007077a3)[val_7];
        if (flag_2 == 0) {
          flag_3 = (&DAT_00707720)[UVar8 + val_7];
          flag_2 = (&DAT_007077a5)[val_7];
        }
        else {
          flag_3 = (&DAT_007077a5)[val_7];
        }
        iVar9 = (uint32_t)flag_3 + (uint32_t)flag_2;
      }
      else {
        pHVar6 = GetDC((HWND)0x0);
        SelectObject(pHVar6,*(HGDIOBJ *)(&DAT_007077bc + val_7));
        GetCharABCWidthsA(pHVar6,UVar8,UVar8,&loop_idx);
        ReleaseDC((HWND)0x0,pHVar6);
        iVar9 = loop_idx.abcB + loop_idx.abcC + loop_idx.abcA;
      }
      BitBlt(pHVar4,y,width,iVar9,match_count,hdc,iVar11 * 8,0,0xee0086);
      y = y + iVar9;
      str_4 = str_4 + 1;
    } while (*str_4 != '\0');
    return (int)str_4 - (int)slot_idx;
  }
  pHVar4 = *(HDC *)((&g_ScreenSurfaces)[*x] + 4);
  loop_idx.abcA = (int)SelectObject(pHVar4,*(HGDIOBJ *)(&DAT_007077bc + val_7));
  uval_5 = x[6];
  if (0xfd < (int)uval_5) {
    uval_5 = 0xfe;
  }
  SetTextColor(pHVar4,uval_5 & 0xffff | 0x1000000);
  SetBkMode(pHVar4,1);
  uval_5 = 0xffffffff;
  pcVar10 = str_4;
  do {
    if (uval_5 == 0) break;
    uval_5 = uval_5 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  TextOutA(pHVar4,y,width - ((int)((uint32_t)(uint8_t)(&DAT_007077a4)[x[8] * 0x2a0] * 4) >> 4),str_4,
           ~uval_5 - 1);
  SelectObject(pHVar4,(HGDIOBJ)loop_idx.abcA);
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


size_t FUN_0050fc70(void *arg1,char *mode_str)

{
  size_t _Count;
  FILE *_File;
  
  _Count = _msize(arg1);
  _File = fopen(str_2,&DAT_00532768);
  fwrite(arg1,1,_Count,_File);
  fclose(_File);
  return _Count;
}



