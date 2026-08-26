/*
 * Decompiled function: FUN_004232f0
 * Entry Point: 004232f0
 * Size: 555 bytes
 */
#include "magic.h"


undefined * FUN_004232f0(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  DWORD dwMaximumSizeLow;
  undefined4 uVar2;
  HANDLE pvVar3;
  HDC pHVar4;
  HBITMAP pHVar5;
  undefined *puVar6;
  uint uVar7;
  
  *(int *)(PTR_DAT_00520cb8 + 0x20) = arg_1;
  *(int *)(PTR_DAT_00520cb8 + 0x24) = arg_2;
  *(int *)(PTR_DAT_00520cb8 + 0x28) = arg_3;
  iVar1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
  uVar7 = iVar1 >> 0x1f;
  if (((iVar1 >> 3 ^ uVar7) - uVar7 & 3 ^ uVar7) == uVar7) {
    *(undefined4 *)(PTR_DAT_00520cb8 + 0x2c) = 0;
  }
  else {
    iVar1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
    uVar7 = iVar1 >> 0x1f;
    *(uint *)(PTR_DAT_00520cb8 + 0x2c) = 4 - (((iVar1 >> 3 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
  }
  iVar1 = (*(int *)(PTR_DAT_00520cb8 + 0x2c) + arg_1) * arg_3 * arg_2;
  dwMaximumSizeLow = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + 0x10;
  *(DWORD *)(PTR_DAT_00520cb8 + 0x1c) = dwMaximumSizeLow;
  uVar2 = FUN_0050ec90(arg_1,arg_2,arg_3);
  *(undefined4 *)(PTR_DAT_00520cb8 + 0x10) = uVar2;
  if (*(int *)(PTR_DAT_00520cb8 + 0x10) == 0) {
    puVar6 = (undefined *)0x0;
  }
  else {
    pvVar3 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                dwMaximumSizeLow,(LPCSTR)0x0);
    *(HANDLE *)PTR_DAT_00520cb8 = pvVar3;
    if (*(int *)PTR_DAT_00520cb8 == 0) {
      Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
      puVar6 = (undefined *)0x0;
    }
    else {
      pHVar4 = GetDC((HWND)0x0);
      *(HDC *)(PTR_DAT_00520cb8 + 4) = pHVar4;
      FUN_004f3955(*(HDC *)(PTR_DAT_00520cb8 + 4));
      pHVar5 = CreateDIBSection(*(HDC *)(PTR_DAT_00520cb8 + 4),
                                *(BITMAPINFO **)(PTR_DAT_00520cb8 + 0x10),(uint)(arg_3 == 8),
                                (void **)(PTR_DAT_00520cb8 + 0x18),*(HANDLE *)PTR_DAT_00520cb8,0);
      *(HBITMAP *)(PTR_DAT_00520cb8 + 8) = pHVar5;
      ReleaseDC((HWND)0x0,*(HDC *)(PTR_DAT_00520cb8 + 4));
      if (*(int *)(PTR_DAT_00520cb8 + 8) == 0) {
        Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
        CloseHandle(*(HANDLE *)PTR_DAT_00520cb8);
        puVar6 = (undefined *)0x0;
      }
      else {
        Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
        puVar6 = PTR_DAT_00520cb8;
      }
    }
  }
  return puVar6;
}


