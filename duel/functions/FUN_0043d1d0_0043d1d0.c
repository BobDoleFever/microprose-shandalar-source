/*
 * Decompiled function: FUN_0043d1d0
 * Entry Point: 0043d1d0
 * Size: 559 bytes
 */
#include "duel.h"


undefined * FUN_0043d1d0(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  DWORD dwMaximumSizeLow;
  undefined4 uVar2;
  HANDLE pvVar3;
  HDC pHVar4;
  HBITMAP pHVar5;
  undefined *puVar6;
  uint uVar7;
  
  *(int *)(PTR_DAT_004f7914 + 0x20) = arg_1;
  *(int *)(PTR_DAT_004f7914 + 0x24) = arg_2;
  *(int *)(PTR_DAT_004f7914 + 0x28) = arg_3;
  iVar1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
  uVar7 = iVar1 >> 0x1f;
  if (((iVar1 >> 3 ^ uVar7) - uVar7 & 3 ^ uVar7) == uVar7) {
    *(undefined4 *)(PTR_DAT_004f7914 + 0x2c) = 0;
  }
  else {
    iVar1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
    uVar7 = iVar1 >> 0x1f;
    *(uint *)(PTR_DAT_004f7914 + 0x2c) = 4 - (((iVar1 >> 3 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
  }
  iVar1 = (*(int *)(PTR_DAT_004f7914 + 0x2c) + arg_1) * arg_2 * arg_3;
  dwMaximumSizeLow = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + 0x10;
  *(DWORD *)(PTR_DAT_004f7914 + 0x1c) = dwMaximumSizeLow;
  uVar2 = FUN_0047f7d3(arg_1,arg_2,arg_3);
  *(undefined4 *)(PTR_DAT_004f7914 + 0x10) = uVar2;
  if (*(int *)(PTR_DAT_004f7914 + 0x10) == 0) {
    puVar6 = (undefined *)0x0;
  }
  else {
    pvVar3 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                dwMaximumSizeLow,(LPCSTR)0x0);
    *(HANDLE *)PTR_DAT_004f7914 = pvVar3;
    if (*(int *)PTR_DAT_004f7914 == 0) {
      Mem_AllocOrFree_0047f8f7(*(undefined4 *)(PTR_DAT_004f7914 + 0x10));
      puVar6 = (undefined *)0x0;
    }
    else {
      pHVar4 = GetDC((HWND)0x0);
      *(HDC *)(PTR_DAT_004f7914 + 4) = pHVar4;
      FUN_004707a4(*(HDC *)(PTR_DAT_004f7914 + 4));
      pHVar5 = CreateDIBSection(*(HDC *)(PTR_DAT_004f7914 + 4),
                                *(BITMAPINFO **)(PTR_DAT_004f7914 + 0x10),(uint)(arg_3 == 8),
                                (void **)(PTR_DAT_004f7914 + 0x18),*(HANDLE *)PTR_DAT_004f7914,0);
      *(HBITMAP *)(PTR_DAT_004f7914 + 8) = pHVar5;
      ReleaseDC((HWND)0x0,*(HDC *)(PTR_DAT_004f7914 + 4));
      if (*(int *)(PTR_DAT_004f7914 + 8) == 0) {
        Mem_AllocOrFree_0047f8f7(*(undefined4 *)(PTR_DAT_004f7914 + 0x10));
        CloseHandle(*(HANDLE *)PTR_DAT_004f7914);
        puVar6 = (undefined *)0x0;
      }
      else {
        Mem_AllocOrFree_0047f8f7(*(undefined4 *)(PTR_DAT_004f7914 + 0x10));
        puVar6 = PTR_DAT_004f7914;
      }
    }
  }
  return puVar6;
}


