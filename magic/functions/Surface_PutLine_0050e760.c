/*
 * Decompiled function: Surface_PutLine
 * Entry Point: 0050e760
 * Size: 232 bytes
 */
#include "magic.h"


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


