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
 * Decompiled function: Memory_AllocateVirtualPage
 * Entry Point: 0050d0b0
 * Size: 483 bytes
 */


int32_t * Memory_AllocateVirtualPage(int x,int y,int width,int height)

{
  int *i_ptr_1;
  HPALETTE hPal;
  int32_t *u_ptr_2;
  int val_3;
  HDC pHVar4;
  int32_t uval_5;
  HANDLE x_00;
  HBITMAP x_01;
  HGDIOBJ pvVar6;
  uint32_t uval_7;
  uint32_t uval_8;
  int32_t *puVar9;
  int32_t card_idx;
  int16_t match_count;
  char local_a [10];
  
  card_idx = DAT_00532628;
  match_count = DAT_0053262c;
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
  AssertOrLog((uint32_t)(x != 0),0x5325e0,0xd5,s_Cannot_explicitly_allocate_page_0_00532604);
  AssertOrLog((uint32_t)(x < 10),0x5325e0,0xd6,s_Graphic_Page_number_out_of_range_005325b8);
  u_ptr_2 = malloc(0x30);
  u_ptr_2[8] = y;
  u_ptr_2[9] = width;
  val_3 = height * y + (height * y >> 0x1f & 7U);
  u_ptr_2[10] = height;
  i_ptr_1 = u_ptr_2 + 0xb;
  uval_8 = val_3 >> 0x1f;
  val_3 = ((val_3 >> 3 ^ uval_8) - uval_8 & 3 ^ uval_8) - uval_8;
  if (val_3 == 0) {
    *i_ptr_1 = 0;
  }
  else {
    *i_ptr_1 = 4 - val_3;
  }
  val_3 = (*i_ptr_1 + y) * height * width;
  uval_8 = ((int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3) + 0x10;
  u_ptr_2[7] = uval_8;
  _itoa(x,local_a,10);
  pHVar4 = CreateCompatibleDC((HDC)0x0);
  u_ptr_2[1] = pHVar4;
  uval_5 = FUN_0050ec90(y,width,height);
  u_ptr_2[4] = uval_5;
  x_00 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,uval_8,
                            (LPCSTR)&card_idx);
  *u_ptr_2 = x_00;
  AssertOrLog((int)x_00,0x5325e0,0xec,s_Create_File_Mapping_failed__page_00532590);
  x_01 = CreateDIBSection((HDC)u_ptr_2[1],(BITMAPINFO *)u_ptr_2[4],(uint32_t)(height == 8),
                          (void **)(u_ptr_2 + 6),(HANDLE)*u_ptr_2,0);
  u_ptr_2[2] = x_01;
  AssertOrLog((int)x_01,0x5325e0,0xf0,s_WM_CREATE_CreateDIBSection_00532574);
  pvVar6 = SelectObject((HDC)u_ptr_2[1],(HGDIOBJ)u_ptr_2[2]);
  u_ptr_2[3] = pvVar6;
  hPal = _hLibPal;
  u_ptr_2[5] = _hLibPal;
  SelectPalette((HDC)u_ptr_2[1],hPal,0);
  RealizePalette((HDC)u_ptr_2[1]);
  SetStretchBltMode((HDC)u_ptr_2[1],3);
  puVar9 = (int32_t *)u_ptr_2[6];
  for (uval_7 = uval_8 >> 2; uval_7 != 0; uval_7 = uval_7 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  for (uval_8 = uval_8 & 3; uval_8 != 0; uval_8 = uval_8 - 1) {
    *(uint8_t *)puVar9 = 0;
    puVar9 = (int32_t *)((int)puVar9 + 1);
  }
  return u_ptr_2;
}



/*
 * Decompiled function: Memory_FreeVirtualPage
 * Entry Point: 0050d2a0
 * Size: 200 bytes
 */


int32_t Memory_FreeVirtualPage(int player_id)

{
  int32_t *_Memory;
  HGDIOBJ h;
  
  AssertOrLog((uint32_t)(arg_1 != 0),0x5325e0,0x10b,s_Cannot_explicitly_Deallocate_pag_00532630);
  AssertOrLog((uint32_t)(arg_1 < 10),0x5325e0,0x10c,s_Graphic_Page_number_out_of_range_005325b8);
  _Memory = (int32_t *)(&g_ScreenSurfaces)[arg_1];
  if (_Memory == (int32_t *)0x0) {
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
  (&g_ScreenSurfaces)[arg_1] = 0;
  return 0;
}



/*
 * Decompiled function: FUN_0050d370
 * Entry Point: 0050d370
 * Size: 227 bytes
 */


void FUN_0050d370(int arg1,int32_t arg2)

{
  int32_t *_Memory;
  HGDIOBJ h;
  
  if ((arg1 != 0) && ((&g_ScreenSurfaces)[arg1] != 0)) {
    AssertOrLog((uint32_t)(arg1 != 0),0x5325e0,0x10b,s_Cannot_explicitly_Deallocate_pag_00532630);
    AssertOrLog((uint32_t)(arg1 < 10),0x5325e0,0x10c,s_Graphic_Page_number_out_of_range_005325b8);
    _Memory = (int32_t *)(&g_ScreenSurfaces)[arg1];
    if (_Memory != (int32_t *)0x0) {
      SelectObject((HDC)_Memory[1],(HGDIOBJ)_Memory[3]);
      DeleteObject((HGDIOBJ)_Memory[2]);
      free((void *)_Memory[4]);
      CloseHandle((HANDLE)*_Memory);
      h = GetStockObject(0xf);
      SelectObject((HDC)_Memory[1],h);
      RealizePalette((HDC)_Memory[1]);
      DeleteDC((HDC)_Memory[1]);
      free(_Memory);
      (&g_ScreenSurfaces)[arg1] = 0;
    }
  }
  (&g_ScreenSurfaces)[arg1] = arg2;
  return;
}



/*
 * Decompiled function: FUN_0050d4a0
 * Entry Point: 0050d4a0
 * Size: 64 bytes
 */


void FUN_0050d4a0(int *arg1,int arg2)

{
  int val_1;
  int val_2;
  
  val_1 = (&g_ScreenSurfaces)[*arg1];
  val_2 = (*(int *)(val_1 + 0x2c) + *(int *)(val_1 + 0x20)) * *(int *)(val_1 + 0x28) * arg2;
  *(int *)(val_1 + 0x18) = *(int *)(val_1 + 0x18) + ((int)(val_2 + (val_2 >> 0x1f & 7U)) >> 3);
  *(int *)(val_1 + 0x24) = *(int *)(val_1 + 0x24) - arg2;
  arg1[4] = arg1[4] - arg2;
  return;
}



/*
 * Decompiled function: FUN_0050d4e0
 * Entry Point: 0050d4e0
 * Size: 63 bytes
 */


void FUN_0050d4e0(int player_id)

{
  if ((*(HDC *)((&g_ScreenSurfaces)[arg_1] + 4) != (HDC)0x0) && (*(HDC *)(g_ScreenSurfaces + 4) != (HDC)0x0)
     ) {
    BitBlt(*(HDC *)(g_ScreenSurfaces + 4),0,0,*(int *)(g_ScreenSurfaces + 0x20),
           *(int *)(g_ScreenSurfaces + 0x24),*(HDC *)((&g_ScreenSurfaces)[arg_1] + 4),0,0,0xcc0020);
  }
  return;
}



/*
 * Decompiled function: FUN_0050d520
 * Entry Point: 0050d520
 * Size: 55 bytes
 */


void FUN_0050d520(int player_id)

{
  int val_1;
  
  val_1 = (&g_ScreenSurfaces)[arg_1];
  BitBlt(*(HDC *)(g_ScreenSurfaces + 4),0,0,*(int *)(val_1 + 0x20),*(int *)(val_1 + 0x24),
         *(HDC *)(val_1 + 4),0,0,0xcc0020);
  return;
}



/*
 * Decompiled function: FUN_0050d560
 * Entry Point: 0050d560
 * Size: 152 bytes
 */


void FUN_0050d560(int arg1,int arg2)

{
  int val_1;
  HBRUSH hbr;
  RECT color_idx;
  LOGBRUSH match_count;
  
  match_count.lbStyle = 0;
  val_1 = (&g_ScreenSurfaces)[arg1];
  match_count.lbColor =
       ((uint8_t)(&DAT_0070a452)[arg2 * 4] | 0x200) << 0x10 |
       (uint32_t)(uint8_t)(&DAT_0070a451)[arg2 * 4] << 8 | (uint32_t)(uint8_t)(&DAT_0070a450)[arg2 * 4];
  hbr = CreateBrushIndirect(&match_count);
  color_idx.top = 0;
  color_idx.left = 0;
  color_idx.right = *(LONG *)(val_1 + 0x20);
  color_idx.bottom = *(LONG *)(val_1 + 0x24);
  FillRect(*(HDC *)(val_1 + 4),&color_idx,hbr);
  DeleteObject(hbr);
  return;
}



/*
 * Decompiled function: Surface_GetPixel
 * Entry Point: 0050d6f0
 * Size: 198 bytes
 */


uint32_t Surface_GetPixel(int player_id,int card_slot,int event_type)

{
  int val_1;
  COLORREF CVar2;
  uint32_t uval_3;
  uint8_t *pbVar4;
  uint32_t uval_5;
  
  val_1 = (&g_ScreenSurfaces)[arg_1];
  if (arg_1 == 0) {
    CVar2 = GetPixel(_hdcScreen,arg_2,arg_3);
    pbVar4 = &DAT_0070a450;
    uval_3 = 0;
    uval_5 = (-(uint32_t)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
    while ((((*pbVar4 & uval_5) != (CVar2 & 0xff) || ((pbVar4[1] & uval_5) != (CVar2 >> 8 & 0xff))) ||
           ((pbVar4[2] & uval_5) != (CVar2 >> 0x10 & 0xff)))) {
      uval_3 = uval_3 + 1;
      pbVar4 = pbVar4 + 4;
      if (0xff < (int)uval_3) {
        return 0xffffffff;
      }
    }
  }
  else {
    uval_3 = (uint32_t)*(uint8_t *)((*(int *)(val_1 + 0x2c) + *(int *)(val_1 + 0x20)) * arg_3 +
                            *(int *)(val_1 + 0x18) + arg_2);
  }
  return uval_3;
}



/*
 * Decompiled function: Surface_GetPixelValue
 * Entry Point: 0050da40
 * Size: 199 bytes
 */


uint32_t Surface_GetPixelValue(int *arg_1,int card_slot,int event_type)

{
  int val_1;
  COLORREF CVar2;
  uint32_t uval_3;
  uint8_t *pbVar4;
  uint32_t uval_5;
  
  val_1 = (&g_ScreenSurfaces)[*arg_1];
  if (*arg_1 == 0) {
    CVar2 = GetPixel(_hdcScreen,arg_2,arg_3);
    pbVar4 = &DAT_0070a450;
    uval_3 = 0;
    uval_5 = (-(uint32_t)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
    while ((((*pbVar4 & uval_5) != (CVar2 & 0xff) || ((pbVar4[1] & uval_5) != (CVar2 >> 8 & 0xff))) ||
           ((pbVar4[2] & uval_5) != (CVar2 >> 0x10 & 0xff)))) {
      uval_3 = uval_3 + 1;
      pbVar4 = pbVar4 + 4;
      if (0xff < (int)uval_3) {
        return 0xffffffff;
      }
    }
  }
  else {
    uval_3 = (uint32_t)*(uint8_t *)((*(int *)(val_1 + 0x2c) + *(int *)(val_1 + 0x20)) * arg_3 +
                            *(int *)(val_1 + 0x18) + arg_2);
  }
  return uval_3;
}



/*
 * Decompiled function: Surface_DrawLine
 * Entry Point: 0050db10
 * Size: 157 bytes
 */


void Surface_DrawLine(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  HPEN h;
  HGDIOBJ h_00;
  COLORREF color;
  
  val_1 = (&g_ScreenSurfaces)[*arg_1];
  if (arg_6 < 0) {
    color = -arg_6;
  }
  else {
    color = (uint32_t)(uint8_t)(&DAT_0070a451)[arg_6 * 4] << 8 |
            (uint32_t)(uint8_t)(&DAT_0070a452)[arg_6 * 4] << 0x10 | (uint32_t)(uint8_t)(&DAT_0070a450)[arg_6 * 4];
  }
  h = CreatePen(0,1,color);
  h_00 = SelectObject(*(HDC *)(val_1 + 4),h);
  MoveToEx(*(HDC *)(val_1 + 4),arg_2,arg_3,(LPPOINT)0x0);
  LineTo(*(HDC *)(val_1 + 4),arg_4,arg_5);
  SelectObject(*(HDC *)(val_1 + 4),h_00);
  DeleteObject(h);
  return;
}



/*
 * Decompiled function: Surface_PutPixel
 * Entry Point: 0050dbb0
 * Size: 121 bytes
 */


void Surface_PutPixel(int *x,int y,int width,uint32_t height)

{
  COLORREF color;
  uint32_t uval_1;
  
  if ((int)height < 0) {
    uval_1 = -height;
    color = 0xffffff;
    if (height != 0xff000001) {
      color = ((uval_1 & 0xffff) >> 8 | 0x20000) << 8 | (uval_1 >> 0x10 & 0xff) << 0x10 | uval_1 & 0xff
      ;
    }
  }
  else if (height == 0xff) {
    color = 0xffffff;
  }
  else {
    color = height & 0xffff | 0x1000000;
  }
  SetPixelV(*(HDC *)((&g_ScreenSurfaces)[*x] + 4),y,width,color);
  return;
}



/*
 * Decompiled function: Surface_FillRect
 * Entry Point: 0050dc30
 * Size: 176 bytes
 */


void Surface_FillRect(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,uint32_t arg_6)

{
  int val_1;
  COLORREF color;
  uint32_t uval_2;
  HBRUSH hbr;
  RECT card_idx;
  
  card_idx.left = arg_2;
  card_idx.right = arg_2 + arg_4;
  card_idx.top = arg_3;
  card_idx.bottom = arg_5 + arg_3;
  val_1 = (&g_ScreenSurfaces)[*arg_1];
  if ((int)arg_6 < 0) {
    uval_2 = -arg_6;
    color = 0xffffff;
    if (arg_6 != 0xff000001) {
      color = ((uval_2 & 0xffff) >> 8 | 0x20000) << 8 | (uval_2 >> 0x10 & 0xff) << 0x10 | uval_2 & 0xff
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
  FillRect(*(HDC *)(val_1 + 4),&card_idx,hbr);
  DeleteObject(hbr);
  return;
}



/*
 * Decompiled function: Surface_BlitToDevice
 * Entry Point: 0050dce0
 * Size: 853 bytes
 */


void Surface_BlitToDevice(int *arg_1,uint32_t arg_2,int event_type,uint32_t arg_4,DWORD arg_5,int *arg_6,int arg_7,
                 int arg_8)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  int val_6;
  int val_7;
  int val_8;
  int iVar9;
  int iVar10;
  RGBQUAD *pRVar11;
  undefined8 *arg_2_00;
  RGBQUAD *pRVar12;
  undefined8 *arg_2_01;
  int local_4;
  
  val_1 = (&g_ScreenSurfaces)[*arg_1];
  val_2 = (&g_ScreenSurfaces)[*arg_6];
  if (DAT_0062314c == 0) {
    DAT_00622930 = (BITMAPINFO *)FUN_0050ec90(1,1,8);
    DAT_0062314c = 1;
  }
  (DAT_00622930->bmiHeader).biWidth = *(LONG *)(val_1 + 0x20);
  if (arg_3 == 0) {
    (DAT_00622930->bmiHeader).biHeight = *(LONG *)(val_1 + 0x24);
  }
  else {
    (DAT_00622930->bmiHeader).biHeight = *(LONG *)(val_1 + 0x24);
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
      arg_2_00 = (undefined8 *)(arg_3 * *(int *)(val_1 + 0x20) + arg_2 + *(int *)(val_1 + 0x18));
      arg_2_01 = (undefined8 *)
                 ((arg_3 + arg_5 + -1) * *(int *)(val_1 + 0x20) + arg_2 + *(int *)(val_1 + 0x18));
      local_4 = (int)arg_5 / 2;
      if (0 < local_4) {
        do {
          Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532560,arg_2_00,arg_4);
          Mem_AllocOrFree_004f1e20(arg_2_00,arg_2_01,arg_4);
          Mem_AllocOrFree_004f1e20(arg_2_01,(undefined8 *)PTR_DAT_00532560,arg_4);
          arg_2_00 = (undefined8 *)((int)arg_2_00 + *(int *)(val_1 + 0x20));
          arg_2_01 = (undefined8 *)((int)arg_2_01 - *(int *)(val_1 + 0x20));
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      SetDIBitsToDevice(*(HDC *)(val_2 + 4),arg_7,arg_8,arg_4,arg_5,arg_2,arg_3,0,
                        *(UINT *)(val_1 + 0x24),*(void **)(val_1 + 0x18),DAT_00622930,
                        (uint32_t)(DAT_0070a880 == 8));
      return;
    }
  }
  else if ((*arg_1 != 0) && (*(int *)(val_1 + 0x28) == *(int *)(val_2 + 0x28))) {
    if ((val_1 == val_2) && (arg_8 < arg_3)) {
      iVar10 = 0;
      if ((int)arg_5 < 1) {
        return;
      }
      do {
        val_3 = *(int *)(val_1 + 0x20) * *(int *)(val_1 + 0x28);
        val_4 = arg_3 + iVar10;
        val_5 = arg_2 * *(int *)(val_1 + 0x28);
        val_6 = *(int *)(val_2 + 0x20) * *(int *)(val_2 + 0x28);
        val_7 = arg_8 + iVar10;
        iVar10 = iVar10 + 1;
        val_8 = arg_7 * *(int *)(val_2 + 0x28);
        iVar9 = arg_4 * *(int *)(val_2 + 0x28);
        memmove((void *)((*(int *)(val_2 + 0x2c) + ((int)(val_6 + (val_6 >> 0x1f & 7U)) >> 3)) *
                         val_7 + ((int)(val_8 + (val_8 >> 0x1f & 7U)) >> 3) + *(int *)(val_2 + 0x18)
                        ),
                (void *)((*(int *)(val_1 + 0x2c) + ((int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3)) *
                         val_4 + ((int)(val_5 + (val_5 >> 0x1f & 7U)) >> 3) + *(int *)(val_1 + 0x18)
                        ),(int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3);
      } while (iVar10 < (int)arg_5);
      return;
    }
    iVar10 = arg_5 - 1;
    if (iVar10 < 0) {
      return;
    }
    do {
      val_3 = *(int *)(val_1 + 0x20) * *(int *)(val_1 + 0x28);
      val_4 = arg_2 * *(int *)(val_1 + 0x28);
      val_5 = *(int *)(val_2 + 0x20) * *(int *)(val_2 + 0x28);
      val_6 = arg_7 * *(int *)(val_2 + 0x28);
      val_7 = arg_4 * *(int *)(val_2 + 0x28);
      memmove((void *)((*(int *)(val_2 + 0x2c) + ((int)(val_5 + (val_5 >> 0x1f & 7U)) >> 3)) *
                       (arg_8 + iVar10) + ((int)(val_6 + (val_6 >> 0x1f & 7U)) >> 3) +
                      *(int *)(val_2 + 0x18)),
              (void *)((*(int *)(val_1 + 0x2c) + ((int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3)) *
                       (arg_3 + iVar10) + ((int)(val_4 + (val_4 >> 0x1f & 7U)) >> 3) +
                      *(int *)(val_1 + 0x18)),(int)(val_7 + (val_7 >> 0x1f & 7U)) >> 3);
      iVar10 = iVar10 + -1;
    } while (-1 < iVar10);
    return;
  }
  BitBlt(*(HDC *)(val_2 + 4),arg_7,arg_8,arg_4,arg_5,*(HDC *)(val_1 + 4),arg_2,arg_3,0xcc0020);
  return;
}



/*
 * Decompiled function: FUN_0050e040
 * Entry Point: 0050e040
 * Size: 582 bytes
 */


void FUN_0050e040(int *arg_1,uint32_t arg_2,int event_type,uint32_t arg_4,DWORD arg_5,int *arg_6,int arg_7,
                 int arg_8)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  undefined8 *puVar5;
  RGBQUAD *pRVar6;
  RGBQUAD *pRVar7;
  undefined8 *puVar8;
  int card_idx;
  
  val_1 = (&g_ScreenSurfaces)[*arg_1];
  val_2 = (&g_ScreenSurfaces)[*arg_6];
  if (DAT_00620120 == 0) {
    DAT_00623958 = (BITMAPINFO *)FUN_0050ec90(1,1,8);
    DAT_00620120 = 1;
  }
  (DAT_00623958->bmiHeader).biWidth = *(LONG *)(val_1 + 0x20);
  if (arg_3 == 0) {
    (DAT_00623958->bmiHeader).biHeight = *(LONG *)(val_1 + 0x24);
  }
  else {
    (DAT_00623958->bmiHeader).biHeight = *(LONG *)(val_1 + 0x24);
  }
  if (((*arg_6 == 0) && ((arg_2 & 7) == 0)) && (DAT_00532550 != 0)) {
    if (DAT_0070a880 != 8) {
      pRVar6 = (RGBQUAD *)&DAT_0070a890;
      pRVar7 = DAT_00623958->bmiColors;
      for (val_4 = 0x100; val_4 != 0; val_4 = val_4 + -1) {
        *pRVar7 = *pRVar6;
        pRVar6 = pRVar6 + 1;
        pRVar7 = pRVar7 + 1;
      }
    }
    puVar8 = (undefined8 *)(arg_2 + *(int *)(val_1 + 0x20) * arg_3 + *(int *)(val_1 + 0x18));
    val_4 = arg_3 + -1 + arg_5;
    puVar5 = (undefined8 *)(arg_2 + val_4 * *(int *)(val_1 + 0x20) + *(int *)(val_1 + 0x18));
    val_3 = (int)arg_5 / 2;
    card_idx = val_3;
    if (0 < val_3) {
      do {
        Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532564,puVar8,arg_4);
        Mem_AllocOrFree_004f1e20(puVar8,puVar5,arg_4);
        Mem_AllocOrFree_004f1e20(puVar5,(undefined8 *)PTR_DAT_00532564,arg_4);
        puVar8 = (undefined8 *)((int)puVar8 + *(int *)(val_1 + 0x20));
        puVar5 = (undefined8 *)((int)puVar5 - *(int *)(val_1 + 0x20));
        card_idx = card_idx + -1;
      } while (card_idx != 0);
    }
    SetDIBitsToDevice(*(HDC *)(val_2 + 4),arg_7,arg_8,arg_4,arg_5,arg_2,arg_3,0,
                      *(UINT *)(val_1 + 0x24),*(void **)(val_1 + 0x18),DAT_00623958,
                      (uint32_t)(DAT_0070a880 == 8));
    puVar8 = (undefined8 *)(arg_2 + *(int *)(val_1 + 0x20) * arg_3 + *(int *)(val_1 + 0x18));
    puVar5 = (undefined8 *)(arg_2 + val_4 * *(int *)(val_1 + 0x20) + *(int *)(val_1 + 0x18));
    card_idx = val_3;
    if (0 < val_3) {
      do {
        Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532568,puVar8,arg_4);
        Mem_AllocOrFree_004f1e20(puVar8,puVar5,arg_4);
        Mem_AllocOrFree_004f1e20(puVar5,(undefined8 *)PTR_DAT_00532568,arg_4);
        puVar8 = (undefined8 *)((int)puVar8 + *(int *)(val_1 + 0x20));
        puVar5 = (undefined8 *)((int)puVar5 - *(int *)(val_1 + 0x20));
        card_idx = card_idx + -1;
      } while (card_idx != 0);
      return;
    }
  }
  else {
    BitBlt(*(HDC *)(val_2 + 4),arg_7,arg_8,arg_4,arg_5,*(HDC *)(val_1 + 4),arg_2,arg_3,0xcc0020);
  }
  return;
}



/*
 * Decompiled function: Surface_StretchBlt
 * Entry Point: 0050e290
 * Size: 91 bytes
 */


void Surface_StretchBlt(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int *arg_6,int arg_7,
                       int arg_8,int arg_9,int arg_10)

{
  StretchBlt(*(HDC *)((&g_ScreenSurfaces)[*arg_6] + 4),arg_7,arg_8,arg_9,arg_10,
             *(HDC *)((&g_ScreenSurfaces)[*arg_1] + 4),arg_2,arg_3,arg_4,arg_5,0xcc0020);
  return;
}



/*
 * Decompiled function: Graphics_MScaledRectCopy
 * Entry Point: 0050e2f0
 * Size: 1021 bytes
 */


void Graphics_MScaledRectCopy(void)

{
  int val_1;
  int val_2;
  int val_3;
  uint32_t uval_4;
  int val_5;
  uint32_t uval_6;
  int val_7;
  uint32_t *puVar8;
  int iVar9;
  undefined8 *arg_1;
  uint32_t *puVar10;
  int iVar11;
  int iStack00000004;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  int stack_arg;
  int stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  uint32_t stack_arg;
  int stack_arg;
  int stack_arg;
  int stack_arg;
  
  Mem_AllocOrFree_00513bd0();
  if ((DAT_00624160 == 0) || (stack_arg == -100000)) {
    DAT_00622934 = (stack_arg << 0x10) / (int)stack_arg;
    uval_4 = 0;
    DAT_00620928 = (stack_arg << 0x10) / stack_arg;
    DAT_0062293c = 0x800;
    DAT_00620124 = 0x800;
    puVar8 = &DAT_00620930;
    do {
      *puVar8 = uval_4;
      puVar8 = puVar8 + 1;
      uval_4 = uval_4 + DAT_00622934;
    } while (puVar8 < &DAT_00622930);
    uval_4 = 0;
    puVar8 = &DAT_0061e120;
    do {
      *puVar8 = uval_4;
      puVar8 = puVar8 + 1;
      uval_4 = uval_4 + DAT_00620928;
    } while (puVar8 < &DAT_00620120);
    DAT_00624160 = 1;
  }
  else {
    if (stack_arg < 0) {
      iVar9 = 0;
      uval_4 = DAT_00620930 & 0xffff;
      do {
        iVar9 = iVar9 + -1;
        uval_4 = uval_4 - DAT_00622934;
      } while ((int)uval_4 >> 0x10 != stack_arg);
      memmove(&DAT_00620930 + -iVar9,&DAT_00620930,(DAT_0062293c + iVar9) * 4);
      if (-1 < -1 - iVar9) {
        puVar8 = &DAT_00620930 + (-1 - iVar9);
        do {
          puVar10 = puVar8 + -1;
          *puVar8 = puVar8[1] - DAT_00622934;
          puVar8 = puVar10;
        } while ((uint32_t *)((int)&DAT_0062092c + 3U) < puVar10);
      }
    }
    else if (0 < stack_arg) {
      iVar9 = 0;
      uval_4 = DAT_00620930 & 0xffff;
      do {
        iVar9 = iVar9 + 1;
        uval_4 = uval_4 + DAT_00622934;
      } while ((int)uval_4 >> 0x10 != stack_arg);
      uval_6 = DAT_0062293c - iVar9;
      puVar8 = &DAT_00620930 + iVar9;
      puVar10 = &DAT_00620930;
      for (uval_4 = uval_6 & 0x3fffffff; uval_4 != 0; uval_4 = uval_4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(char *)puVar10 = (char)*puVar8;
        puVar8 = (uint32_t *)((int)puVar8 + 1);
        puVar10 = (uint32_t *)((int)puVar10 + 1);
      }
      if ((int)uval_6 < DAT_0062293c) {
        iVar9 = DAT_0062293c - uval_6;
        puVar8 = &DAT_00620930 + uval_6;
        do {
          iVar9 = iVar9 + -1;
          *puVar8 = puVar8[-1] + DAT_00622934;
          puVar8 = puVar8 + 1;
        } while (iVar9 != 0);
      }
    }
    if (stack_arg < 0) {
      iVar9 = 0;
      uval_4 = DAT_0061e120 & 0xffff;
      do {
        iVar9 = iVar9 + -1;
        uval_4 = uval_4 - DAT_00620928;
      } while ((int)uval_4 >> 0x10 != stack_arg);
      memmove(&DAT_0061e120 + -iVar9,&DAT_0061e120,(DAT_00620124 + iVar9) * 4);
      if (-1 < -1 - iVar9) {
        puVar8 = &DAT_0061e120 + (-1 - iVar9);
        do {
          puVar10 = puVar8 + -1;
          *puVar8 = puVar8[1] - DAT_00620928;
          puVar8 = puVar10;
        } while ((uint32_t *)((int)&DAT_0061e11c + 3U) < puVar10);
      }
    }
    else if (0 < stack_arg) {
      iVar9 = 0;
      uval_4 = DAT_0061e120 & 0xffff;
      do {
        iVar9 = iVar9 + 1;
        uval_4 = uval_4 + DAT_00620928;
      } while ((int)uval_4 >> 0x10 != stack_arg);
      uval_6 = DAT_00620124 - iVar9;
      puVar8 = &DAT_0061e120 + iVar9;
      puVar10 = &DAT_0061e120;
      for (uval_4 = uval_6 & 0x3fffffff; uval_4 != 0; uval_4 = uval_4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(char *)puVar10 = (char)*puVar8;
        puVar8 = (uint32_t *)((int)puVar8 + 1);
        puVar10 = (uint32_t *)((int)puVar10 + 1);
      }
      if ((int)uval_6 < DAT_00620124) {
        iVar9 = DAT_00620124 - uval_6;
        puVar8 = &DAT_0061e120 + uval_6;
        do {
          iVar9 = iVar9 + -1;
          *puVar8 = puVar8[-1] + DAT_00620928;
          puVar8 = puVar8 + 1;
        } while (iVar9 != 0);
      }
    }
    DAT_0062092c = DAT_0062092c + stack_arg;
    DAT_00622940 = DAT_00622940 + stack_arg;
  }
  if (0 < DAT_0062293c) {
    iVar9 = DAT_0062293c;
    val_5 = 0;
    do {
      iVar9 = iVar9 + -1;
      *(int *)(&stack0x00000014 + val_5) =
           (*(int *)((int)&DAT_00620930 + val_5) >> 0x10) - DAT_0062092c;
      val_5 = val_5 + 4;
    } while (iVar9 != 0);
  }
  if ((*stack_arg == 0) || (*stack_arg == 0)) {
    iVar9 = 0;
  }
  else {
    iVar9 = 1;
  }
  AssertOrLog(iVar9,0x5325e0,0x435,s_MScaledRectCopy_only_works_on_me_00532658);
  iVar9 = (&g_ScreenSurfaces)[*stack_arg];
  val_5 = (&g_ScreenSurfaces)[*stack_arg];
  val_1 = *(int *)(iVar9 + 0x2c);
  val_2 = *(int *)(iVar9 + 0x20);
  val_3 = *(int *)(val_5 + 0x20);
  iVar9 = *(int *)(iVar9 + 0x18);
  arg_1 = (undefined8 *)
          (stack_arg +
          (*(int *)(val_5 + 0x2c) + val_3) * stack_arg + *(int *)(val_5 + 0x18));
  if (0 < stack_arg) {
    puVar8 = &DAT_0061e120;
    val_5 = -1;
    iStack00000004 = stack_arg;
    do {
      iVar11 = ((int)*puVar8 >> 0x10) - DAT_00622940;
      if (val_5 == iVar11) {
        Mem_AllocOrFree_004f1e20(arg_1,(undefined8 *)&DAT_00623158,stack_arg);
        iVar11 = val_5;
      }
      else {
        val_5 = 0;
        if (0 < (int)stack_arg) {
          do {
            val_7 = val_5 + 1;
            (&DAT_00623158)[val_5] =
                 *(uint8_t *)
                  (*(int *)(&stack0x00000014 + val_5 * 4) +
                  val_2 * iVar11 + stack_arg + (val_1 + val_2) * stack_arg + iVar9);
            val_5 = val_7;
          } while (val_7 < (int)stack_arg);
        }
        Mem_AllocOrFree_004f1e20(arg_1,(undefined8 *)&DAT_00623158,stack_arg);
      }
      puVar8 = puVar8 + 1;
      arg_1 = (undefined8 *)((int)arg_1 + val_3);
      iStack00000004 = iStack00000004 + -1;
      val_5 = iVar11;
    } while (iStack00000004 != 0);
  }
  return;
}



/*
 * Decompiled function: FUN_0050e6f0
 * Entry Point: 0050e6f0
 * Size: 109 bytes
 */


void FUN_0050e6f0(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  
  val_1 = *(int *)(arg_2 + 4);
  val_2 = *(int *)(arg_2 + 0xc);
  val_3 = *(int *)(arg_2 + 8);
  val_4 = *(int *)(arg_2 + 0x10);
  *(int *)(arg_2 + 8) = arg_4;
  *(int *)(arg_2 + 4) = arg_3;
  *(int *)(arg_2 + 0xc) = arg_3 + arg_5;
  *(int *)(arg_2 + 0x10) = arg_6 + arg_4;
  *arg_1 = val_1;
  arg_1[1] = val_3;
  arg_1[2] = val_2 - val_1;
  arg_1[3] = val_4 - val_3;
  return;
}



/*
 * Decompiled function: Surface_PutLine
 * Entry Point: 0050e760
 * Size: 232 bytes
 */


void Surface_PutLine(int32_t *arg_1,int card_slot,int event_type,int arg_4,uint32_t arg_5)

{
  int val_1;
  int val_2;
  uint32_t uval_3;
  RGBQUAD *pRVar4;
  RGBQUAD *pRVar5;
  int32_t *puVar6;
  
  if (DAT_00623148 == 0) {
    DAT_00622938 = (BITMAPINFO *)FUN_0050ec90(1,1,8);
    DAT_00623148 = 1;
  }
  val_1 = (&g_ScreenSurfaces)[arg_2];
  (DAT_00622938->bmiHeader).biWidth = arg_5;
  if (arg_2 == 0) {
    if ((DAT_0070a880 != 8) && (DAT_00532558 != 0)) {
      pRVar4 = (RGBQUAD *)&DAT_0070a890;
      pRVar5 = DAT_00622938->bmiColors;
      for (val_2 = 0x100; val_2 != 0; val_2 = val_2 + -1) {
        *pRVar5 = *pRVar4;
        pRVar4 = pRVar4 + 1;
        pRVar5 = pRVar5 + 1;
      }
      DAT_00532558 = 0;
    }
    SetDIBitsToDevice(*(HDC *)(val_1 + 4),arg_3,arg_4,arg_5,1,0,0,0,1,arg_1,DAT_00622938,
                      (uint32_t)(DAT_0070a880 == 8));
    return;
  }
  puVar6 = (int32_t *)
           (arg_3 + (*(int *)(val_1 + 0x2c) + *(int *)(val_1 + 0x20)) * arg_4 +
                    *(int *)(val_1 + 0x18));
  for (uval_3 = arg_5 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *puVar6 = *arg_1;
    arg_1 = arg_1 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uval_3 = arg_5 & 3; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(uint8_t *)puVar6 = *(uint8_t *)arg_1;
    arg_1 = (int32_t *)((int)arg_1 + 1);
    puVar6 = (int32_t *)((int)puVar6 + 1);
  }
  return;
}



/*
 * Decompiled function: Surface_GetLine
 * Entry Point: 0050e850
 * Size: 96 bytes
 */


void Surface_GetLine(int32_t *arg_1,int card_slot,int event_type,int arg_4,uint32_t arg_5)

{
  int val_1;
  uint32_t uval_2;
  int32_t *u_ptr_3;
  
  AssertOrLog((uint32_t)(arg_2 != 0),0x5325e0,0x4b8,s_GetLine_not_implemented_for_page_00532688);
  val_1 = (&g_ScreenSurfaces)[arg_2];
  u_ptr_3 = (int32_t *)
           ((*(int *)(val_1 + 0x2c) + *(int *)(val_1 + 0x20)) * arg_4 + *(int *)(val_1 + 0x18) +
           arg_3);
  for (uval_2 = arg_5 >> 2; uval_2 != 0; uval_2 = uval_2 - 1) {
    *arg_1 = *u_ptr_3;
    u_ptr_3 = u_ptr_3 + 1;
    arg_1 = arg_1 + 1;
  }
  for (uval_2 = arg_5 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *(uint8_t *)arg_1 = *(uint8_t *)u_ptr_3;
    u_ptr_3 = (int32_t *)((int)u_ptr_3 + 1);
    arg_1 = (int32_t *)((int)arg_1 + 1);
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
  short len_1;
  uint8_t flag_2;
  uint8_t flag_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  int val_7;
  short *psVar8;
  uint8_t *pbVar9;
  int32_t *puVar10;
  int iVar11;
  int *piVar12;
  
  len_1 = arg_1[1];
  psVar8 = arg_1;
  puVar10 = &DAT_0070a130;
  for (uval_4 = (uint32_t)(int)(short)(len_1 + 2) >> 2; uval_4 != 0; uval_4 = uval_4 - 1) {
    *puVar10 = *(int32_t *)psVar8;
    psVar8 = psVar8 + 2;
    puVar10 = puVar10 + 1;
  }
  for (uval_4 = (int)(short)(len_1 + 2) & 3; uval_4 != 0; uval_4 = uval_4 - 1) {
    *(char *)puVar10 = (char)*psVar8;
    psVar8 = (short *)((int)psVar8 + 1);
    puVar10 = (int32_t *)((int)puVar10 + 1);
  }
  uval_5 = (uint32_t)*(uint8_t *)(arg_1 + 2);
  uval_4 = (-(uint32_t)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
  uval_6 = (uint32_t)*(uint8_t *)((int)arg_1 + 5);
  flag_3 = (uint8_t)uval_4;
  if (DAT_005326d4 == *arg_1) {
    if (uval_5 <= uval_6) {
      iVar11 = uval_5 * 4;
      pbVar9 = (uint8_t *)((int)arg_1 + uval_5 * 3 + 6);
      val_7 = (uval_6 - uval_5) + 1;
      do {
        flag_2 = (uint8_t)(((uint32_t)*pbVar9 * 0xff) / 0x3f) & flag_3;
        (&DAT_0070a450)[iVar11] = flag_2;
        *(uint8_t *)((int)&DAT_0070a890 + iVar11 + 2) = flag_2;
        flag_2 = (uint8_t)(((uint32_t)pbVar9[1] * 0xff) / 0x3f) & flag_3;
        (&DAT_0070a451)[iVar11] = flag_2;
        *(uint8_t *)((int)&DAT_0070a890 + iVar11 + 1) = flag_2;
        flag_2 = (uint8_t)(((uint32_t)pbVar9[2] * 0xff) / 0x3f) & flag_3;
        (&DAT_0070a452)[iVar11] = flag_2;
        *(uint8_t *)((int)&DAT_0070a890 + iVar11) = flag_2;
        (&DAT_0070a453)[iVar11] = 1;
        *(uint8_t *)((int)&DAT_0070a890 + iVar11 + 3) = 0;
        if ((*(int *)((int)&DAT_0070a890 + iVar11) == 0xffffff) && (iVar11 != 0x3fc)) {
          uval_5 = uval_4 * 0x10000 | uval_4 * 0x100 | uval_4;
          *(uint32_t *)(&DAT_0070a450 + iVar11) = uval_5 & 0x1fefefe;
          *(uint32_t *)((int)&DAT_0070a890 + iVar11) = uval_5 & 0xfefefe;
        }
        iVar11 = iVar11 + 4;
        pbVar9 = pbVar9 + 3;
        val_7 = val_7 + -1;
      } while (val_7 != 0);
    }
  }
  else if ((DAT_005326d0 == *arg_1) && (uval_5 <= uval_6)) {
    iVar11 = uval_5 * 4;
    pbVar9 = (uint8_t *)((int)arg_1 + uval_5 * 3 + 6);
    val_7 = (uval_6 - uval_5) + 1;
    do {
      flag_2 = *pbVar9;
      (&DAT_0070a450)[iVar11] = flag_2 & flag_3;
      *(uint8_t *)((int)&DAT_0070a890 + iVar11 + 2) = flag_2 & flag_3;
      flag_2 = pbVar9[1];
      (&DAT_0070a451)[iVar11] = flag_2 & flag_3;
      *(uint8_t *)((int)&DAT_0070a890 + iVar11 + 1) = flag_2 & flag_3;
      flag_2 = pbVar9[2];
      (&DAT_0070a452)[iVar11] = flag_2 & flag_3;
      *(uint8_t *)((int)&DAT_0070a890 + iVar11) = flag_2 & flag_3;
      (&DAT_0070a453)[iVar11] = 1;
      *(uint8_t *)((int)&DAT_0070a890 + iVar11 + 3) = 0;
      if ((*(int *)((int)&DAT_0070a890 + iVar11) == 0xffffff) && (iVar11 != 0x3fc)) {
        uval_5 = (uval_4 * 0x10000 | uval_4 * 0x100 | uval_4) & 0xfefefe;
        *(uint32_t *)((int)&DAT_0070a890 + iVar11) = uval_5;
        *(uint32_t *)(&DAT_0070a450 + iVar11) = uval_5;
        (&DAT_0070a453)[iVar11] = 1;
      }
      iVar11 = iVar11 + 4;
      pbVar9 = pbVar9 + 3;
      val_7 = val_7 + -1;
    } while (val_7 != 0);
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
  if (g_ScreenSurfaces != 0) {
    RealizePalette(*(HDC *)(g_ScreenSurfaces + 4));
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


void FUN_0050eb90(int player_id)

{
  uint8_t *u_ptr_1;
  int val_2;
  int32_t *u_ptr_3;
  int32_t *puVar4;
  int32_t local_320;
  uint8_t local_31c;
  int32_t local_31b;
  
  local_320 = DAT_005326d8;
  u_ptr_3 = &local_31b;
  for (val_2 = 0xc6; val_2 != 0; val_2 = val_2 + -1) {
    *u_ptr_3 = 0;
    u_ptr_3 = u_ptr_3 + 1;
  }
  *(int16_t *)u_ptr_3 = 0;
  *(uint8_t *)((int)u_ptr_3 + 2) = 0;
  local_31c = 0;
  local_31b._0_1_ = 0xff;
  u_ptr_1 = (uint8_t *)((int)&local_31b + 1);
  u_ptr_3 = (int32_t *)&DAT_0070a450;
  do {
    puVar4 = u_ptr_3 + 1;
    *u_ptr_1 = *(uint8_t *)u_ptr_3;
    u_ptr_1[1] = *(uint8_t *)((int)u_ptr_3 + 1);
    u_ptr_1[2] = *(uint8_t *)((int)u_ptr_3 + 2);
    u_ptr_1 = u_ptr_1 + 3;
    u_ptr_3 = puVar4;
  } while (puVar4 < &g_ScreenSurfaces);
  _write(arg_1,&local_320,0x306);
  return;
}



/*
 * Decompiled function: FUN_0050ec20
 * Entry Point: 0050ec20
 * Size: 104 bytes
 */


int FUN_0050ec20(HWND hwnd,void *arg_2,int event_type,int arg_4,DWORD arg_5,DWORD arg_6)

{
  BITMAPINFO *lpbmi;
  HDC hdc;
  int val_1;
  
  lpbmi = (BITMAPINFO *)FUN_0050ec90(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_1 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,arg_2,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  return val_1;
}



/*
 * Decompiled function: FUN_0050ec90
 * Entry Point: 0050ec90
 * Size: 123 bytes
 */


void FUN_0050ec90(int32_t arg_1,int card_slot,int event_type)

{
  int32_t *u_ptr_1;
  int val_2;
  size_t _Size;
  
  if (arg_3 == 8) {
    _Size = 0x42c;
  }
  else {
    _Size = 0x2c;
  }
  u_ptr_1 = malloc(_Size);
  *u_ptr_1 = 0x28;
  val_2 = 0;
  u_ptr_1[1] = arg_1;
  u_ptr_1[2] = -arg_2;
  *(int16_t *)(u_ptr_1 + 3) = 1;
  *(short *)((int)u_ptr_1 + 0xe) = (short)arg_3;
  u_ptr_1[4] = 0;
  u_ptr_1[5] = 0;
  u_ptr_1[6] = 0;
  u_ptr_1[7] = 0;
  if (arg_3 == 8) {
    u_ptr_1[8] = 0x100;
    u_ptr_1[9] = 0x100;
    u_ptr_1 = u_ptr_1 + 10;
    do {
      *(short *)u_ptr_1 = (short)val_2;
      u_ptr_1 = (int32_t *)((int)u_ptr_1 + 2);
      val_2 = val_2 + 1;
    } while (val_2 < 0x100);
    return;
  }
  u_ptr_1[8] = 0;
  u_ptr_1[9] = 0;
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0050ed10
 * Entry Point: 0050ed10
 * Size: 22 bytes
 */


int32_t Mem_AllocOrFree_0050ed10(void *arg_1)

{
  free(arg_1);
  return 1;
}



