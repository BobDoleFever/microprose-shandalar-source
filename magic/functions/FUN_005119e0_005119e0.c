/*
 * Decompiled function: FUN_005119e0
 * Entry Point: 005119e0
 * Size: 425 bytes
 */
#include "magic.h"


uint FUN_005119e0(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int y;
  COLORREF color;
  uint uVar4;
  int x;
  int x_00;
  int y_00;
  int cy;
  uint uVar5;
  uint uVar6;
  uint local_10;
  
  iVar1 = (uint)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  iVar2 = (uint)(arg_5 % arg_7 != 0) + arg_5 / arg_7;
  uVar4 = 0x40000000;
  uVar6 = 0;
  uVar5 = (iVar2 + 1) * (iVar1 + 1);
  iVar3 = 0;
  do {
    if ((uVar4 & uVar5) != 0) {
      if (uVar6 == 0) {
        uVar6 = uVar4;
      }
      iVar3 = iVar3 + 1;
    }
    uVar4 = (int)uVar4 >> 1;
  } while (uVar4 != 0);
  if (iVar3 != 1) {
    uVar6 = uVar6 * 2;
  }
  local_10 = 0;
  uVar4 = 1;
  if (1 < (int)uVar6) {
    do {
      local_10 = local_10 | uVar4;
      uVar4 = uVar4 * 2;
    } while ((int)uVar4 < (int)uVar6);
  }
  iVar3 = rand();
  uVar4 = iVar3 % (int)uVar6;
  uVar6 = iVar3 / (int)uVar6;
  while (uVar5 != 0) {
    uVar4 = uVar4 * 0x21 + 1 & local_10;
    uVar6 = uVar4;
    if ((int)uVar4 <= iVar2 * iVar1) {
      y = (int)uVar4 / iVar1;
      x_00 = (int)uVar4 % iVar1;
      x = x_00 * arg_6 + arg_2;
      y_00 = y * arg_7 + arg_3;
      iVar3 = arg_6;
      if (arg_4 + arg_2 <= arg_6 + x) {
        iVar3 = (arg_2 - x) + arg_4;
      }
      cy = arg_7;
      if (arg_5 + arg_3 <= arg_7 + y_00) {
        cy = (arg_3 - y_00) + arg_5;
      }
      if ((arg_6 == 1) && (arg_7 == 1)) {
        color = GetPixel(param_8,x_00,y);
        uVar6 = SetPixelV(hdc,x_00,y,color);
      }
      else {
        uVar6 = BitBlt(hdc,x,y_00,iVar3,cy,param_8,x,y_00,0xcc0020);
      }
      uVar5 = uVar5 - 1;
    }
  }
  return uVar6;
}


