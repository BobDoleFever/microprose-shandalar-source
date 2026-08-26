/*
 * Decompiled function: FUN_0050dce0
 * Entry Point: 0050dce0
 * Size: 853 bytes
 */
#include "magic.h"


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


