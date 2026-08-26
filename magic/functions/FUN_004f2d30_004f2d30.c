/*
 * Decompiled function: FUN_004f2d30
 * Entry Point: 004f2d30
 * Size: 292 bytes
 */
#include "magic.h"


int FUN_004f2d30(HWND hwnd,int arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  undefined1 uVar1;
  undefined4 *lpvBits;
  int iVar2;
  BITMAPINFO *lpbmi;
  HDC hdc;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  DWORD DVar12;
  DWORD local_4;
  
  iVar8 = 0;
  iVar11 = 0;
  uVar4 = arg_6 * arg_5 * 3;
  lpvBits = malloc(arg_6 * arg_5 * 3 + 8);
  puVar7 = lpvBits;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  if (0 < (int)arg_6) {
    iVar5 = 0;
    local_4 = arg_6;
    puVar7 = lpvBits;
    do {
      if (0 < (int)arg_5) {
        piVar10 = (int *)(arg_2 + iVar5 * 4);
        puVar6 = puVar7;
        iVar9 = iVar8;
        DVar12 = arg_5;
        do {
          iVar2 = *piVar10 >> 2;
          iVar8 = iVar2;
          if ((iVar9 <= iVar2) && (iVar8 = iVar9, iVar11 < iVar2)) {
            iVar11 = iVar2;
          }
          if (iVar2 < 1) {
            iVar2 = 0;
          }
          if (0xfe < iVar2) {
            iVar2 = 0xff;
          }
          uVar1 = (undefined1)iVar2;
          *(undefined1 *)((int)puVar6 + 2) = uVar1;
          piVar10 = piVar10 + 1;
          *(undefined1 *)((int)puVar6 + 1) = uVar1;
          puVar7 = (undefined4 *)((int)puVar6 + 3);
          DVar12 = DVar12 - 1;
          *(undefined1 *)puVar6 = uVar1;
          puVar6 = puVar7;
          iVar9 = iVar8;
        } while (DVar12 != 0);
      }
      iVar5 = iVar5 + arg_5;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  lpbmi = (BITMAPINFO *)FUN_0050ec90(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  iVar8 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,lpvBits,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  Mem_AllocOrFree_0050ed10(lpbmi);
  free(lpvBits);
  return iVar8;
}


