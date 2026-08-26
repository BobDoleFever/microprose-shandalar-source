/*
 * sidlib/lib.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: FUN_0050d0b0
 * Entry Point: 0050d0b0
 * Size: 483 bytes
 */


undefined4 * FUN_0050d0b0(int x,int y,int width,int height)

{
  int *piVar1;
  HPALETTE hPal;
  undefined4 *puVar2;
  int iVar3;
  HDC pHVar4;
  undefined4 uVar5;
  HANDLE x_00;
  HBITMAP x_01;
  HGDIOBJ pvVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 local_10;
  undefined2 local_c;
  char local_a [10];
  
  local_10 = DAT_00532628;
  local_c = DAT_0053262c;
  local_a[0] = DAT_0053262e;
  local_a[1] = '\0';
  local_a[2] = '\0';
  local_a[3] = '\0';
  local_a[4] = '\0';
  local_a[5] = '\0';
  local_a[6] = '\0';
  local_a[7] = '\0';
  local_a[8] = '\0';
  local_a[9] = 0;
  AssertOrLog((uint)(x != 0),0x5325e0,0xd5,s_Cannot_explicitly_allocate_page_0_00532604);
  AssertOrLog((uint)(x < 10),0x5325e0,0xd6,s_Graphic_Page_number_out_of_range_005325b8);
  puVar2 = malloc(0x30);
  puVar2[8] = y;
  puVar2[9] = width;
  iVar3 = height * y + (height * y >> 0x1f & 7U);
  puVar2[10] = height;
  piVar1 = puVar2 + 0xb;
  uVar8 = iVar3 >> 0x1f;
  iVar3 = ((iVar3 >> 3 ^ uVar8) - uVar8 & 3 ^ uVar8) - uVar8;
  if (iVar3 == 0) {
    *piVar1 = 0;
  }
  else {
    *piVar1 = 4 - iVar3;
  }
  iVar3 = (*piVar1 + y) * height * width;
  uVar8 = ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + 0x10;
  puVar2[7] = uVar8;
  _itoa(x,local_a,10);
  pHVar4 = CreateCompatibleDC((HDC)0x0);
  puVar2[1] = pHVar4;
  uVar5 = FUN_0050ec90(y,width,height);
  puVar2[4] = uVar5;
  x_00 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,uVar8,
                            (LPCSTR)&local_10);
  *puVar2 = x_00;
  AssertOrLog((int)x_00,0x5325e0,0xec,s_Create_File_Mapping_failed__page_00532590);
  x_01 = CreateDIBSection((HDC)puVar2[1],(BITMAPINFO *)puVar2[4],(uint)(height == 8),
                          (void **)(puVar2 + 6),(HANDLE)*puVar2,0);
  puVar2[2] = x_01;
  AssertOrLog((int)x_01,0x5325e0,0xf0,s_WM_CREATE_CreateDIBSection_00532574);
  pvVar6 = SelectObject((HDC)puVar2[1],(HGDIOBJ)puVar2[2]);
  puVar2[3] = pvVar6;
  hPal = _hLibPal;
  puVar2[5] = _hLibPal;
  SelectPalette((HDC)puVar2[1],hPal,0);
  RealizePalette((HDC)puVar2[1]);
  SetStretchBltMode((HDC)puVar2[1],3);
  puVar9 = (undefined4 *)puVar2[6];
  for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar9 = 0;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  return puVar2;
}



/*
 * Decompiled function: FUN_0050d2a0
 * Entry Point: 0050d2a0
 * Size: 200 bytes
 */


undefined4 FUN_0050d2a0(int arg_1)

{
  undefined4 *_Memory;
  HGDIOBJ h;
  
  AssertOrLog((uint)(arg_1 != 0),0x5325e0,0x10b,s_Cannot_explicitly_Deallocate_pag_00532630);
  AssertOrLog((uint)(arg_1 < 10),0x5325e0,0x10c,s_Graphic_Page_number_out_of_range_005325b8);
  _Memory = (undefined4 *)(&DAT_0070a850)[arg_1];
  if (_Memory == (undefined4 *)0x0) {
    return 0;
  }
  SelectObject((HDC)_Memory[1],(HGDIOBJ)_Memory[3]);
  DeleteObject((HGDIOBJ)_Memory[2]);
  free((void *)_Memory[4]);
  CloseHandle((HANDLE)*_Memory);
  h = GetStockObject(0xf);
  SelectObject((HDC)_Memory[1],h);
  RealizePalette((HDC)_Memory[1]);
  DeleteDC((HDC)_Memory[1]);
  free(_Memory);
  (&DAT_0070a850)[arg_1] = 0;
  return 0;
}



/*
 * Decompiled function: FUN_0050d370
 * Entry Point: 0050d370
 * Size: 227 bytes
 */


void FUN_0050d370(int arg1,undefined4 arg2)

{
  undefined4 *_Memory;
  HGDIOBJ h;
  
  if ((arg1 != 0) && ((&DAT_0070a850)[arg1] != 0)) {
    AssertOrLog((uint)(arg1 != 0),0x5325e0,0x10b,s_Cannot_explicitly_Deallocate_pag_00532630);
    AssertOrLog((uint)(arg1 < 10),0x5325e0,0x10c,s_Graphic_Page_number_out_of_range_005325b8);
    _Memory = (undefined4 *)(&DAT_0070a850)[arg1];
    if (_Memory != (undefined4 *)0x0) {
      SelectObject((HDC)_Memory[1],(HGDIOBJ)_Memory[3]);
      DeleteObject((HGDIOBJ)_Memory[2]);
      free((void *)_Memory[4]);
      CloseHandle((HANDLE)*_Memory);
      h = GetStockObject(0xf);
      SelectObject((HDC)_Memory[1],h);
      RealizePalette((HDC)_Memory[1]);
      DeleteDC((HDC)_Memory[1]);
      free(_Memory);
      (&DAT_0070a850)[arg1] = 0;
    }
  }
  (&DAT_0070a850)[arg1] = arg2;
  return;
}



/*
 * Decompiled function: FUN_0050d4a0
 * Entry Point: 0050d4a0
 * Size: 64 bytes
 */


void FUN_0050d4a0(int *arg1,int arg2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_0070a850)[*arg1];
  iVar2 = (*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * *(int *)(iVar1 + 0x28) * arg2;
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + ((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
  *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) - arg2;
  arg1[4] = arg1[4] - arg2;
  return;
}



/*
 * Decompiled function: FUN_0050d4e0
 * Entry Point: 0050d4e0
 * Size: 63 bytes
 */


void FUN_0050d4e0(int arg_1)

{
  if ((*(HDC *)((&DAT_0070a850)[arg_1] + 4) != (HDC)0x0) && (*(HDC *)(DAT_0070a850 + 4) != (HDC)0x0)
     ) {
    BitBlt(*(HDC *)(DAT_0070a850 + 4),0,0,*(int *)(DAT_0070a850 + 0x20),
           *(int *)(DAT_0070a850 + 0x24),*(HDC *)((&DAT_0070a850)[arg_1] + 4),0,0,0xcc0020);
  }
  return;
}



/*
 * Decompiled function: FUN_0050d520
 * Entry Point: 0050d520
 * Size: 55 bytes
 */


void FUN_0050d520(int arg_1)

{
  int iVar1;
  
  iVar1 = (&DAT_0070a850)[arg_1];
  BitBlt(*(HDC *)(DAT_0070a850 + 4),0,0,*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24),
         *(HDC *)(iVar1 + 4),0,0,0xcc0020);
  return;
}



/*
 * Decompiled function: FUN_0050d560
 * Entry Point: 0050d560
 * Size: 152 bytes
 */


void FUN_0050d560(int arg1,int arg2)

{
  int iVar1;
  HBRUSH hbr;
  RECT local_1c;
  LOGBRUSH local_c;
  
  local_c.lbStyle = 0;
  iVar1 = (&DAT_0070a850)[arg1];
  local_c.lbColor =
       ((byte)(&DAT_0070a452)[arg2 * 4] | 0x200) << 0x10 |
       (uint)(byte)(&DAT_0070a451)[arg2 * 4] << 8 | (uint)(byte)(&DAT_0070a450)[arg2 * 4];
  hbr = CreateBrushIndirect(&local_c);
  local_1c.top = 0;
  local_1c.left = 0;
  local_1c.right = *(LONG *)(iVar1 + 0x20);
  local_1c.bottom = *(LONG *)(iVar1 + 0x24);
  FillRect(*(HDC *)(iVar1 + 4),&local_1c,hbr);
  DeleteObject(hbr);
  return;
}



/*
 * Decompiled function: Surface_GetPixel
 * Entry Point: 0050d6f0
 * Size: 198 bytes
 */


uint Surface_GetPixel(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  COLORREF CVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  
  iVar1 = (&DAT_0070a850)[arg_1];
  if (arg_1 == 0) {
    CVar2 = GetPixel(_hdcScreen,arg_2,arg_3);
    pbVar4 = &DAT_0070a450;
    uVar3 = 0;
    uVar5 = (-(uint)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
    while ((((*pbVar4 & uVar5) != (CVar2 & 0xff) || ((pbVar4[1] & uVar5) != (CVar2 >> 8 & 0xff))) ||
           ((pbVar4[2] & uVar5) != (CVar2 >> 0x10 & 0xff)))) {
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar4 + 4;
      if (0xff < (int)uVar3) {
        return 0xffffffff;
      }
    }
  }
  else {
    uVar3 = (uint)*(byte *)((*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * arg_3 +
                            *(int *)(iVar1 + 0x18) + arg_2);
  }
  return uVar3;
}



/*
 * Decompiled function: Surface_GetPixelPtr
 * Entry Point: 0050da40
 * Size: 199 bytes
 */


uint Surface_GetPixelPtr(int *arg_1,int arg_2,int arg_3)

{
  int iVar1;
  COLORREF CVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  
  iVar1 = (&DAT_0070a850)[*arg_1];
  if (*arg_1 == 0) {
    CVar2 = GetPixel(_hdcScreen,arg_2,arg_3);
    pbVar4 = &DAT_0070a450;
    uVar3 = 0;
    uVar5 = (-(uint)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
    while ((((*pbVar4 & uVar5) != (CVar2 & 0xff) || ((pbVar4[1] & uVar5) != (CVar2 >> 8 & 0xff))) ||
           ((pbVar4[2] & uVar5) != (CVar2 >> 0x10 & 0xff)))) {
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar4 + 4;
      if (0xff < (int)uVar3) {
        return 0xffffffff;
      }
    }
  }
  else {
    uVar3 = (uint)*(byte *)((*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * arg_3 +
                            *(int *)(iVar1 + 0x18) + arg_2);
  }
  return uVar3;
}



/*
 * Decompiled function: Surface_DrawLine
 * Entry Point: 0050db10
 * Size: 157 bytes
 */


void Surface_DrawLine(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int iVar1;
  HPEN h;
  HGDIOBJ h_00;
  COLORREF color;
  
  iVar1 = (&DAT_0070a850)[*arg_1];
  if (arg_6 < 0) {
    color = -arg_6;
  }
  else {
    color = (uint)(byte)(&DAT_0070a451)[arg_6 * 4] << 8 |
            (uint)(byte)(&DAT_0070a452)[arg_6 * 4] << 0x10 | (uint)(byte)(&DAT_0070a450)[arg_6 * 4];
  }
  h = CreatePen(0,1,color);
  h_00 = SelectObject(*(HDC *)(iVar1 + 4),h);
  MoveToEx(*(HDC *)(iVar1 + 4),arg_2,arg_3,(LPPOINT)0x0);
  LineTo(*(HDC *)(iVar1 + 4),arg_4,arg_5);
  SelectObject(*(HDC *)(iVar1 + 4),h_00);
  DeleteObject(h);
  return;
}



/*
 * Decompiled function: Surface_PutPixel
 * Entry Point: 0050dbb0
 * Size: 121 bytes
 */


void Surface_PutPixel(int *x,int y,int width,uint height)

{
  COLORREF color;
  uint uVar1;
  
  if ((int)height < 0) {
    uVar1 = -height;
    color = 0xffffff;
    if (height != 0xff000001) {
      color = ((uVar1 & 0xffff) >> 8 | 0x20000) << 8 | (uVar1 >> 0x10 & 0xff) << 0x10 | uVar1 & 0xff
      ;
    }
  }
  else if (height == 0xff) {
    color = 0xffffff;
  }
  else {
    color = height & 0xffff | 0x1000000;
  }
  SetPixelV(*(HDC *)((&DAT_0070a850)[*x] + 4),y,width,color);
  return;
}



/*
 * Decompiled function: Surface_FillRect
 * Entry Point: 0050dc30
 * Size: 176 bytes
 */


void Surface_FillRect(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6)

{
  int iVar1;
  COLORREF color;
  uint uVar2;
  HBRUSH hbr;
  RECT local_10;
  
  local_10.left = arg_2;
  local_10.right = arg_2 + arg_4;
  local_10.top = arg_3;
  local_10.bottom = arg_5 + arg_3;
  iVar1 = (&DAT_0070a850)[*arg_1];
  if ((int)arg_6 < 0) {
    uVar2 = -arg_6;
    color = 0xffffff;
    if (arg_6 != 0xff000001) {
      color = ((uVar2 & 0xffff) >> 8 | 0x20000) << 8 | (uVar2 >> 0x10 & 0xff) << 0x10 | uVar2 & 0xff
      ;
    }
  }
  else if (arg_6 == 0xff) {
    color = 0xffffff;
  }
  else {
    color = arg_6 & 0xffff | 0x1000000;
  }
  hbr = CreateSolidBrush(color);
  FillRect(*(HDC *)(iVar1 + 4),&local_10,hbr);
  DeleteObject(hbr);
  return;
}



/*
 * Decompiled function: FUN_0050dce0
 * Entry Point: 0050dce0
 * Size: 853 bytes
 */


void FUN_0050dce0(int *arg_1,uint arg_2,int arg_3,uint arg_4,DWORD arg_5,int *arg_6,int arg_7,
                 int arg_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGBQUAD *pRVar11;
  undefined8 *arg_2_00;
  RGBQUAD *pRVar12;
  undefined8 *arg_2_01;
  int local_4;
  
  iVar1 = (&DAT_0070a850)[*arg_1];
  iVar2 = (&DAT_0070a850)[*arg_6];
  if (DAT_0062314c == 0) {
    DAT_00622930 = (BITMAPINFO *)FUN_0050ec90(1,1,8);
    DAT_0062314c = 1;
  }
  (DAT_00622930->bmiHeader).biWidth = *(LONG *)(iVar1 + 0x20);
  if (arg_3 == 0) {
    (DAT_00622930->bmiHeader).biHeight = *(LONG *)(iVar1 + 0x24);
  }
  else {
    (DAT_00622930->bmiHeader).biHeight = *(LONG *)(iVar1 + 0x24);
  }
  if (*arg_6 == 0) {
    if (((arg_2 & 7) == 0) && (DAT_00532550 != 0)) {
      if (DAT_0070a880 != 8) {
        pRVar11 = (RGBQUAD *)&DAT_0070a890;
        pRVar12 = DAT_00622930->bmiColors;
        for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
          *pRVar12 = *pRVar11;
          pRVar11 = pRVar11 + 1;
          pRVar12 = pRVar12 + 1;
        }
      }
      arg_2_00 = (undefined8 *)(arg_3 * *(int *)(iVar1 + 0x20) + arg_2 + *(int *)(iVar1 + 0x18));
      arg_2_01 = (undefined8 *)
                 ((arg_3 + arg_5 + -1) * *(int *)(iVar1 + 0x20) + arg_2 + *(int *)(iVar1 + 0x18));
      local_4 = (int)arg_5 / 2;
      if (0 < local_4) {
        do {
          Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532560,arg_2_00,arg_4);
          Mem_AllocOrFree_004f1e20(arg_2_00,arg_2_01,arg_4);
          Mem_AllocOrFree_004f1e20(arg_2_01,(undefined8 *)PTR_DAT_00532560,arg_4);
          arg_2_00 = (undefined8 *)((int)arg_2_00 + *(int *)(iVar1 + 0x20));
          arg_2_01 = (undefined8 *)((int)arg_2_01 - *(int *)(iVar1 + 0x20));
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      SetDIBitsToDevice(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_4,arg_5,arg_2,arg_3,0,
                        *(UINT *)(iVar1 + 0x24),*(void **)(iVar1 + 0x18),DAT_00622930,
                        (uint)(DAT_0070a880 == 8));
      return;
    }
  }
  else if ((*arg_1 != 0) && (*(int *)(iVar1 + 0x28) == *(int *)(iVar2 + 0x28))) {
    if ((iVar1 == iVar2) && (arg_8 < arg_3)) {
      iVar10 = 0;
      if ((int)arg_5 < 1) {
        return;
      }
      do {
        iVar3 = *(int *)(iVar1 + 0x20) * *(int *)(iVar1 + 0x28);
        iVar4 = arg_3 + iVar10;
        iVar5 = arg_2 * *(int *)(iVar1 + 0x28);
        iVar6 = *(int *)(iVar2 + 0x20) * *(int *)(iVar2 + 0x28);
        iVar7 = arg_8 + iVar10;
        iVar10 = iVar10 + 1;
        iVar8 = arg_7 * *(int *)(iVar2 + 0x28);
        iVar9 = arg_4 * *(int *)(iVar2 + 0x28);
        memmove((void *)((*(int *)(iVar2 + 0x2c) + ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3)) *
                         iVar7 + ((int)(iVar8 + (iVar8 >> 0x1f & 7U)) >> 3) + *(int *)(iVar2 + 0x18)
                        ),
                (void *)((*(int *)(iVar1 + 0x2c) + ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3)) *
                         iVar4 + ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + *(int *)(iVar1 + 0x18)
                        ),(int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3);
      } while (iVar10 < (int)arg_5);
      return;
    }
    iVar10 = arg_5 - 1;
    if (iVar10 < 0) {
      return;
    }
    do {
      iVar3 = *(int *)(iVar1 + 0x20) * *(int *)(iVar1 + 0x28);
      iVar4 = arg_2 * *(int *)(iVar1 + 0x28);
      iVar5 = *(int *)(iVar2 + 0x20) * *(int *)(iVar2 + 0x28);
      iVar6 = arg_7 * *(int *)(iVar2 + 0x28);
      iVar7 = arg_4 * *(int *)(iVar2 + 0x28);
      memmove((void *)((*(int *)(iVar2 + 0x2c) + ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3)) *
                       (arg_8 + iVar10) + ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) +
                      *(int *)(iVar2 + 0x18)),
              (void *)((*(int *)(iVar1 + 0x2c) + ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3)) *
                       (arg_3 + iVar10) + ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) +
                      *(int *)(iVar1 + 0x18)),(int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3);
      iVar10 = iVar10 + -1;
    } while (-1 < iVar10);
    return;
  }
  BitBlt(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_4,arg_5,*(HDC *)(iVar1 + 4),arg_2,arg_3,0xcc0020);
  return;
}



/*
 * Decompiled function: FUN_0050e040
 * Entry Point: 0050e040
 * Size: 582 bytes
 */


void FUN_0050e040(int *arg_1,uint arg_2,int arg_3,uint arg_4,DWORD arg_5,int *arg_6,int arg_7,
                 int arg_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  RGBQUAD *pRVar6;
  RGBQUAD *pRVar7;
  undefined8 *puVar8;
  int local_10;
  
  iVar1 = (&DAT_0070a850)[*arg_1];
  iVar2 = (&DAT_0070a850)[*arg_6];
  if (DAT_00620120 == 0) {
    DAT_00623958 = (BITMAPINFO *)FUN_0050ec90(1,1,8);
    DAT_00620120 = 1;
  }
  (DAT_00623958->bmiHeader).biWidth = *(LONG *)(iVar1 + 0x20);
  if (arg_3 == 0) {
    (DAT_00623958->bmiHeader).biHeight = *(LONG *)(iVar1 + 0x24);
  }
  else {
    (DAT_00623958->bmiHeader).biHeight = *(LONG *)(iVar1 + 0x24);
  }
  if (((*arg_6 == 0) && ((arg_2 & 7) == 0)) && (DAT_00532550 != 0)) {
    if (DAT_0070a880 != 8) {
      pRVar6 = (RGBQUAD *)&DAT_0070a890;
      pRVar7 = DAT_00623958->bmiColors;
      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pRVar7 = *pRVar6;
        pRVar6 = pRVar6 + 1;
        pRVar7 = pRVar7 + 1;
      }
    }
    puVar8 = (undefined8 *)(arg_2 + *(int *)(iVar1 + 0x20) * arg_3 + *(int *)(iVar1 + 0x18));
    iVar4 = arg_3 + -1 + arg_5;
    puVar5 = (undefined8 *)(arg_2 + iVar4 * *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x18));
    iVar3 = (int)arg_5 / 2;
    local_10 = iVar3;
    if (0 < iVar3) {
      do {
        Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532564,puVar8,arg_4);
        Mem_AllocOrFree_004f1e20(puVar8,puVar5,arg_4);
        Mem_AllocOrFree_004f1e20(puVar5,(undefined8 *)PTR_DAT_00532564,arg_4);
        puVar8 = (undefined8 *)((int)puVar8 + *(int *)(iVar1 + 0x20));
        puVar5 = (undefined8 *)((int)puVar5 - *(int *)(iVar1 + 0x20));
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
    SetDIBitsToDevice(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_4,arg_5,arg_2,arg_3,0,
                      *(UINT *)(iVar1 + 0x24),*(void **)(iVar1 + 0x18),DAT_00623958,
                      (uint)(DAT_0070a880 == 8));
    puVar8 = (undefined8 *)(arg_2 + *(int *)(iVar1 + 0x20) * arg_3 + *(int *)(iVar1 + 0x18));
    puVar5 = (undefined8 *)(arg_2 + iVar4 * *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x18));
    local_10 = iVar3;
    if (0 < iVar3) {
      do {
        Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532568,puVar8,arg_4);
        Mem_AllocOrFree_004f1e20(puVar8,puVar5,arg_4);
        Mem_AllocOrFree_004f1e20(puVar5,(undefined8 *)PTR_DAT_00532568,arg_4);
        puVar8 = (undefined8 *)((int)puVar8 + *(int *)(iVar1 + 0x20));
        puVar5 = (undefined8 *)((int)puVar5 - *(int *)(iVar1 + 0x20));
        local_10 = local_10 + -1;
      } while (local_10 != 0);
      return;
    }
  }
  else {
    BitBlt(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_4,arg_5,*(HDC *)(iVar1 + 4),arg_2,arg_3,0xcc0020);
  }
  return;
}



/*
 * Decompiled function: Surface_StretchBlt
 * Entry Point: 0050e290
 * Size: 91 bytes
 */


void Surface_StretchBlt(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,int arg_7,
                       int arg_8,int arg_9,int arg_10)

{
  StretchBlt(*(HDC *)((&DAT_0070a850)[*arg_6] + 4),arg_7,arg_8,arg_9,arg_10,
             *(HDC *)((&DAT_0070a850)[*arg_1] + 4),arg_2,arg_3,arg_4,arg_5,0xcc0020);
  return;
}



/*
 * Decompiled function: FUN_0050e2f0
 * Entry Point: 0050e2f0
 * Size: 1021 bytes
 */


void FUN_0050e2f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  undefined8 *arg_1;
  uint *puVar10;
  int iVar11;
  int iStack00000004;
  int *in_stack_00002018;
  int in_stack_0000201c;
  int in_stack_00002020;
  int in_stack_00002024;
  int in_stack_00002028;
  int *in_stack_0000202c;
  int in_stack_00002030;
  int in_stack_00002034;
  uint in_stack_00002038;
  int in_stack_0000203c;
  int in_stack_00002040;
  int in_stack_00002044;
  
  Mem_AllocOrFree_00513bd0();
  if ((DAT_00624160 == 0) || (in_stack_00002040 == -100000)) {
    DAT_00622934 = (in_stack_00002024 << 0x10) / (int)in_stack_00002038;
    uVar4 = 0;
    DAT_00620928 = (in_stack_00002028 << 0x10) / in_stack_0000203c;
    DAT_0062293c = 0x800;
    DAT_00620124 = 0x800;
    puVar8 = &DAT_00620930;
    do {
      *puVar8 = uVar4;
      puVar8 = puVar8 + 1;
      uVar4 = uVar4 + DAT_00622934;
    } while (puVar8 < &DAT_00622930);
    uVar4 = 0;
    puVar8 = &DAT_0061e120;
    do {
      *puVar8 = uVar4;
      puVar8 = puVar8 + 1;
      uVar4 = uVar4 + DAT_00620928;
    } while (puVar8 < &DAT_00620120);
    DAT_00624160 = 1;
  }
  else {
    if (in_stack_00002040 < 0) {
      iVar9 = 0;
      uVar4 = DAT_00620930 & 0xffff;
      do {
        iVar9 = iVar9 + -1;
        uVar4 = uVar4 - DAT_00622934;
      } while ((int)uVar4 >> 0x10 != in_stack_00002040);
      memmove(&DAT_00620930 + -iVar9,&DAT_00620930,(DAT_0062293c + iVar9) * 4);
      if (-1 < -1 - iVar9) {
        puVar8 = &DAT_00620930 + (-1 - iVar9);
        do {
          puVar10 = puVar8 + -1;
          *puVar8 = puVar8[1] - DAT_00622934;
          puVar8 = puVar10;
        } while ((uint *)((int)&DAT_0062092c + 3U) < puVar10);
      }
    }
    else if (0 < in_stack_00002040) {
      iVar9 = 0;
      uVar4 = DAT_00620930 & 0xffff;
      do {
        iVar9 = iVar9 + 1;
        uVar4 = uVar4 + DAT_00622934;
      } while ((int)uVar4 >> 0x10 != in_stack_00002040);
      uVar6 = DAT_0062293c - iVar9;
      puVar8 = &DAT_00620930 + iVar9;
      puVar10 = &DAT_00620930;
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(char *)puVar10 = (char)*puVar8;
        puVar8 = (uint *)((int)puVar8 + 1);
        puVar10 = (uint *)((int)puVar10 + 1);
      }
      if ((int)uVar6 < DAT_0062293c) {
        iVar9 = DAT_0062293c - uVar6;
        puVar8 = &DAT_00620930 + uVar6;
        do {
          iVar9 = iVar9 + -1;
          *puVar8 = puVar8[-1] + DAT_00622934;
          puVar8 = puVar8 + 1;
        } while (iVar9 != 0);
      }
    }
    if (in_stack_00002044 < 0) {
      iVar9 = 0;
      uVar4 = DAT_0061e120 & 0xffff;
      do {
        iVar9 = iVar9 + -1;
        uVar4 = uVar4 - DAT_00620928;
      } while ((int)uVar4 >> 0x10 != in_stack_00002044);
      memmove(&DAT_0061e120 + -iVar9,&DAT_0061e120,(DAT_00620124 + iVar9) * 4);
      if (-1 < -1 - iVar9) {
        puVar8 = &DAT_0061e120 + (-1 - iVar9);
        do {
          puVar10 = puVar8 + -1;
          *puVar8 = puVar8[1] - DAT_00620928;
          puVar8 = puVar10;
        } while ((uint *)((int)&DAT_0061e11c + 3U) < puVar10);
      }
    }
    else if (0 < in_stack_00002044) {
      iVar9 = 0;
      uVar4 = DAT_0061e120 & 0xffff;
      do {
        iVar9 = iVar9 + 1;
        uVar4 = uVar4 + DAT_00620928;
      } while ((int)uVar4 >> 0x10 != in_stack_00002044);
      uVar6 = DAT_00620124 - iVar9;
      puVar8 = &DAT_0061e120 + iVar9;
      puVar10 = &DAT_0061e120;
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(char *)puVar10 = (char)*puVar8;
        puVar8 = (uint *)((int)puVar8 + 1);
        puVar10 = (uint *)((int)puVar10 + 1);
      }
      if ((int)uVar6 < DAT_00620124) {
        iVar9 = DAT_00620124 - uVar6;
        puVar8 = &DAT_0061e120 + uVar6;
        do {
          iVar9 = iVar9 + -1;
          *puVar8 = puVar8[-1] + DAT_00620928;
          puVar8 = puVar8 + 1;
        } while (iVar9 != 0);
      }
    }
    DAT_0062092c = DAT_0062092c + in_stack_00002040;
    DAT_00622940 = DAT_00622940 + in_stack_00002044;
  }
  if (0 < DAT_0062293c) {
    iVar9 = DAT_0062293c;
    iVar5 = 0;
    do {
      iVar9 = iVar9 + -1;
      *(int *)(&stack0x00000014 + iVar5) =
           (*(int *)((int)&DAT_00620930 + iVar5) >> 0x10) - DAT_0062092c;
      iVar5 = iVar5 + 4;
    } while (iVar9 != 0);
  }
  if ((*in_stack_00002018 == 0) || (*in_stack_0000202c == 0)) {
    iVar9 = 0;
  }
  else {
    iVar9 = 1;
  }
  AssertOrLog(iVar9,0x5325e0,0x435,s_MScaledRectCopy_only_works_on_me_00532658);
  iVar9 = (&DAT_0070a850)[*in_stack_00002018];
  iVar5 = (&DAT_0070a850)[*in_stack_0000202c];
  iVar1 = *(int *)(iVar9 + 0x2c);
  iVar2 = *(int *)(iVar9 + 0x20);
  iVar3 = *(int *)(iVar5 + 0x20);
  iVar9 = *(int *)(iVar9 + 0x18);
  arg_1 = (undefined8 *)
          (in_stack_00002030 +
          (*(int *)(iVar5 + 0x2c) + iVar3) * in_stack_00002034 + *(int *)(iVar5 + 0x18));
  if (0 < in_stack_0000203c) {
    puVar8 = &DAT_0061e120;
    iVar5 = -1;
    iStack00000004 = in_stack_0000203c;
    do {
      iVar11 = ((int)*puVar8 >> 0x10) - DAT_00622940;
      if (iVar5 == iVar11) {
        Mem_AllocOrFree_004f1e20(arg_1,(undefined8 *)&DAT_00623158,in_stack_00002038);
        iVar11 = iVar5;
      }
      else {
        iVar5 = 0;
        if (0 < (int)in_stack_00002038) {
          do {
            iVar7 = iVar5 + 1;
            (&DAT_00623158)[iVar5] =
                 *(undefined1 *)
                  (*(int *)(&stack0x00000014 + iVar5 * 4) +
                  iVar2 * iVar11 + in_stack_0000201c + (iVar1 + iVar2) * in_stack_00002020 + iVar9);
            iVar5 = iVar7;
          } while (iVar7 < (int)in_stack_00002038);
        }
        Mem_AllocOrFree_004f1e20(arg_1,(undefined8 *)&DAT_00623158,in_stack_00002038);
      }
      puVar8 = puVar8 + 1;
      arg_1 = (undefined8 *)((int)arg_1 + iVar3);
      iStack00000004 = iStack00000004 + -1;
      iVar5 = iVar11;
    } while (iStack00000004 != 0);
  }
  return;
}



/*
 * Decompiled function: FUN_0050e6f0
 * Entry Point: 0050e6f0
 * Size: 109 bytes
 */


void FUN_0050e6f0(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(arg_2 + 4);
  iVar2 = *(int *)(arg_2 + 0xc);
  iVar3 = *(int *)(arg_2 + 8);
  iVar4 = *(int *)(arg_2 + 0x10);
  *(int *)(arg_2 + 8) = arg_4;
  *(int *)(arg_2 + 4) = arg_3;
  *(int *)(arg_2 + 0xc) = arg_3 + arg_5;
  *(int *)(arg_2 + 0x10) = arg_6 + arg_4;
  *arg_1 = iVar1;
  arg_1[1] = iVar3;
  arg_1[2] = iVar2 - iVar1;
  arg_1[3] = iVar4 - iVar3;
  return;
}



/*
 * Decompiled function: Surface_PutLine
 * Entry Point: 0050e760
 * Size: 232 bytes
 */


void Surface_PutLine(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,uint arg_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  RGBQUAD *pRVar4;
  RGBQUAD *pRVar5;
  undefined4 *puVar6;
  
  if (DAT_00623148 == 0) {
    DAT_00622938 = (BITMAPINFO *)FUN_0050ec90(1,1,8);
    DAT_00623148 = 1;
  }
  iVar1 = (&DAT_0070a850)[arg_2];
  (DAT_00622938->bmiHeader).biWidth = arg_5;
  if (arg_2 == 0) {
    if ((DAT_0070a880 != 8) && (DAT_00532558 != 0)) {
      pRVar4 = (RGBQUAD *)&DAT_0070a890;
      pRVar5 = DAT_00622938->bmiColors;
      for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pRVar5 = *pRVar4;
        pRVar4 = pRVar4 + 1;
        pRVar5 = pRVar5 + 1;
      }
      DAT_00532558 = 0;
    }
    SetDIBitsToDevice(*(HDC *)(iVar1 + 4),arg_3,arg_4,arg_5,1,0,0,0,1,arg_1,DAT_00622938,
                      (uint)(DAT_0070a880 == 8));
    return;
  }
  puVar6 = (undefined4 *)
           (arg_3 + (*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * arg_4 +
                    *(int *)(iVar1 + 0x18));
  for (uVar3 = arg_5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *arg_1;
    arg_1 = arg_1 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar3 = arg_5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)arg_1;
    arg_1 = (undefined4 *)((int)arg_1 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  return;
}



/*
 * Decompiled function: Surface_GetLine
 * Entry Point: 0050e850
 * Size: 96 bytes
 */


void Surface_GetLine(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,uint arg_5)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  AssertOrLog((uint)(arg_2 != 0),0x5325e0,0x4b8,s_GetLine_not_implemented_for_page_00532688);
  iVar1 = (&DAT_0070a850)[arg_2];
  puVar3 = (undefined4 *)
           ((*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * arg_4 + *(int *)(iVar1 + 0x18) +
           arg_3);
  for (uVar2 = arg_5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *arg_1 = *puVar3;
    puVar3 = puVar3 + 1;
    arg_1 = arg_1 + 1;
  }
  for (uVar2 = arg_5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)arg_1 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    arg_1 = (undefined4 *)((int)arg_1 + 1);
  }
  return;
}



/*
 * Decompiled function: FUN_0050e8b0
 * Entry Point: 0050e8b0
 * Size: 735 bytes
 */


void FUN_0050e8b0(short *arg_1)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int iVar11;
  int *piVar12;
  
  sVar1 = arg_1[1];
  psVar8 = arg_1;
  puVar10 = &DAT_0070a130;
  for (uVar4 = (uint)(int)(short)(sVar1 + 2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar10 = *(undefined4 *)psVar8;
    psVar8 = psVar8 + 2;
    puVar10 = puVar10 + 1;
  }
  for (uVar4 = (int)(short)(sVar1 + 2) & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)puVar10 = (char)*psVar8;
    psVar8 = (short *)((int)psVar8 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  uVar5 = (uint)*(byte *)(arg_1 + 2);
  uVar4 = (-(uint)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
  uVar6 = (uint)*(byte *)((int)arg_1 + 5);
  bVar3 = (byte)uVar4;
  if (DAT_005326d4 == *arg_1) {
    if (uVar5 <= uVar6) {
      iVar11 = uVar5 * 4;
      pbVar9 = (byte *)((int)arg_1 + uVar5 * 3 + 6);
      iVar7 = (uVar6 - uVar5) + 1;
      do {
        bVar2 = (byte)(((uint)*pbVar9 * 0xff) / 0x3f) & bVar3;
        (&DAT_0070a450)[iVar11] = bVar2;
        *(byte *)((int)&DAT_0070a890 + iVar11 + 2) = bVar2;
        bVar2 = (byte)(((uint)pbVar9[1] * 0xff) / 0x3f) & bVar3;
        (&DAT_0070a451)[iVar11] = bVar2;
        *(byte *)((int)&DAT_0070a890 + iVar11 + 1) = bVar2;
        bVar2 = (byte)(((uint)pbVar9[2] * 0xff) / 0x3f) & bVar3;
        (&DAT_0070a452)[iVar11] = bVar2;
        *(byte *)((int)&DAT_0070a890 + iVar11) = bVar2;
        (&DAT_0070a453)[iVar11] = 1;
        *(undefined1 *)((int)&DAT_0070a890 + iVar11 + 3) = 0;
        if ((*(int *)((int)&DAT_0070a890 + iVar11) == 0xffffff) && (iVar11 != 0x3fc)) {
          uVar5 = uVar4 * 0x10000 | uVar4 * 0x100 | uVar4;
          *(uint *)(&DAT_0070a450 + iVar11) = uVar5 & 0x1fefefe;
          *(uint *)((int)&DAT_0070a890 + iVar11) = uVar5 & 0xfefefe;
        }
        iVar11 = iVar11 + 4;
        pbVar9 = pbVar9 + 3;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else if ((DAT_005326d0 == *arg_1) && (uVar5 <= uVar6)) {
    iVar11 = uVar5 * 4;
    pbVar9 = (byte *)((int)arg_1 + uVar5 * 3 + 6);
    iVar7 = (uVar6 - uVar5) + 1;
    do {
      bVar2 = *pbVar9;
      (&DAT_0070a450)[iVar11] = bVar2 & bVar3;
      *(byte *)((int)&DAT_0070a890 + iVar11 + 2) = bVar2 & bVar3;
      bVar2 = pbVar9[1];
      (&DAT_0070a451)[iVar11] = bVar2 & bVar3;
      *(byte *)((int)&DAT_0070a890 + iVar11 + 1) = bVar2 & bVar3;
      bVar2 = pbVar9[2];
      (&DAT_0070a452)[iVar11] = bVar2 & bVar3;
      *(byte *)((int)&DAT_0070a890 + iVar11) = bVar2 & bVar3;
      (&DAT_0070a453)[iVar11] = 1;
      *(undefined1 *)((int)&DAT_0070a890 + iVar11 + 3) = 0;
      if ((*(int *)((int)&DAT_0070a890 + iVar11) == 0xffffff) && (iVar11 != 0x3fc)) {
        uVar5 = (uVar4 * 0x10000 | uVar4 * 0x100 | uVar4) & 0xfefefe;
        *(uint *)((int)&DAT_0070a890 + iVar11) = uVar5;
        *(uint *)(&DAT_0070a450 + iVar11) = uVar5;
        (&DAT_0070a453)[iVar11] = 1;
      }
      iVar11 = iVar11 + 4;
      pbVar9 = pbVar9 + 3;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  DAT_0070a452 = 0;
  DAT_0070a451 = 0;
  DAT_0070a450 = 0;
  DAT_0070a453 = 0;
  DAT_0070a890._0_1_ = 0;
  DAT_0070a890._1_1_ = 0;
  DAT_0070a890._2_1_ = 0;
  DAT_0070a890._3_1_ = 0;
  DAT_0070a847 = 1;
  DAT_0070a84b = 1;
  DAT_0070a84f = 0;
  DAT_0070ac87 = 0;
  DAT_0070ac8c = 0xff;
  DAT_0070ac8d = 0xff;
  DAT_0070ac8e = 0xff;
  DAT_0070ac8f = 0;
  AnimatePalette(_hLibPal,0,0x100,(PALETTEENTRY *)&DAT_0070a450);
  if (DAT_0070a850 != 0) {
    RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  }
  piVar12 = &DAT_0070a854;
  do {
    if (*piVar12 != 0) {
      SetDIBColorTable(*(HDC *)(*piVar12 + 4),0,0x100,(RGBQUAD *)&DAT_0070a890);
    }
    piVar12 = piVar12 + 1;
  } while (piVar12 < &DAT_0070a878);
  DAT_00623150 = FindWindowExA((HWND)0x0,(HWND)0x0,s_ShowPaletteClass_005326ac,
                               s_Current_Palette_005326c0);
  if (DAT_00623150 != (HWND)0x0) {
    InvalidateRect(DAT_00623150,(RECT *)0x0,0);
    UpdateWindow(DAT_00623150);
  }
  DAT_00532558 = 1;
  return;
}



/*
 * Decompiled function: FUN_0050eb90
 * Entry Point: 0050eb90
 * Size: 132 bytes
 */


void FUN_0050eb90(int arg_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_320;
  undefined1 local_31c;
  undefined4 local_31b;
  
  local_320 = DAT_005326d8;
  puVar3 = &local_31b;
  for (iVar2 = 0xc6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_31c = 0;
  local_31b._0_1_ = 0xff;
  puVar1 = (undefined1 *)((int)&local_31b + 1);
  puVar3 = (undefined4 *)&DAT_0070a450;
  do {
    puVar4 = puVar3 + 1;
    *puVar1 = *(undefined1 *)puVar3;
    puVar1[1] = *(undefined1 *)((int)puVar3 + 1);
    puVar1[2] = *(undefined1 *)((int)puVar3 + 2);
    puVar1 = puVar1 + 3;
    puVar3 = puVar4;
  } while (puVar4 < &DAT_0070a850);
  _write(arg_1,&local_320,0x306);
  return;
}



/*
 * Decompiled function: FUN_0050ec20
 * Entry Point: 0050ec20
 * Size: 104 bytes
 */


int FUN_0050ec20(HWND hwnd,void *arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  BITMAPINFO *lpbmi;
  HDC hdc;
  int iVar1;
  
  lpbmi = (BITMAPINFO *)FUN_0050ec90(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  iVar1 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,arg_2,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  return iVar1;
}



/*
 * Decompiled function: FUN_0050ec90
 * Entry Point: 0050ec90
 * Size: 123 bytes
 */


void FUN_0050ec90(undefined4 arg_1,int arg_2,int arg_3)

{
  undefined4 *puVar1;
  int iVar2;
  size_t _Size;
  
  if (arg_3 == 8) {
    _Size = 0x42c;
  }
  else {
    _Size = 0x2c;
  }
  puVar1 = malloc(_Size);
  *puVar1 = 0x28;
  iVar2 = 0;
  puVar1[1] = arg_1;
  puVar1[2] = -arg_2;
  *(undefined2 *)(puVar1 + 3) = 1;
  *(short *)((int)puVar1 + 0xe) = (short)arg_3;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  if (arg_3 == 8) {
    puVar1[8] = 0x100;
    puVar1[9] = 0x100;
    puVar1 = puVar1 + 10;
    do {
      *(short *)puVar1 = (short)iVar2;
      puVar1 = (undefined4 *)((int)puVar1 + 2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    return;
  }
  puVar1[8] = 0;
  puVar1[9] = 0;
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0050ed10
 * Entry Point: 0050ed10
 * Size: 22 bytes
 */


undefined4 Mem_AllocOrFree_0050ed10(void *arg_1)

{
  free(arg_1);
  return 1;
}



