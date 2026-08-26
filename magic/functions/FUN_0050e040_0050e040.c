/*
 * Decompiled function: FUN_0050e040
 * Entry Point: 0050e040
 * Size: 582 bytes
 */
#include "magic.h"


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


