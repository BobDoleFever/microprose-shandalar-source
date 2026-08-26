/*
 * Decompiled function: FUN_0050d0b0
 * Entry Point: 0050d0b0
 * Size: 483 bytes
 */
#include "magic.h"


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


