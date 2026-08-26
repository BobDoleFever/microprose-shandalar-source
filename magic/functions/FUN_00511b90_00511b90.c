/*
 * Decompiled function: FUN_00511b90
 * Entry Point: 00511b90
 * Size: 461 bytes
 */
#include "magic.h"


uint FUN_00511b90(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8,
                 int arg_9,int arg_10)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int y;
  COLORREF color;
  int iVar4;
  int x;
  int y_00;
  int cx;
  int cy;
  uint uVar5;
  uint uVar6;
  uint local_1c;
  
  iVar1 = (uint)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  iVar2 = (uint)(arg_5 % arg_7 != 0) + arg_5 / arg_7;
  iVar4 = 0;
  uVar6 = 0;
  uVar5 = (iVar2 + 1) * (iVar1 + 1);
  uVar3 = 0x40000000;
  do {
    if ((uVar5 & uVar3) != 0) {
      if (uVar6 == 0) {
        uVar6 = uVar3;
      }
      iVar4 = iVar4 + 1;
    }
    uVar3 = (int)uVar3 >> 1;
  } while (uVar3 != 0);
  if (iVar4 != 1) {
    uVar6 = uVar6 * 2;
  }
  local_1c = 0;
  uVar3 = 1;
  if (1 < (int)uVar6) {
    do {
      local_1c = local_1c | uVar3;
      uVar3 = uVar3 * 2;
    } while ((int)uVar3 < (int)uVar6);
  }
  iVar4 = rand();
  uVar3 = iVar4 % (int)uVar6;
  uVar6 = iVar4 / (int)uVar6;
  while (uVar5 != 0) {
    uVar3 = uVar3 * 0x21 + 1 & local_1c;
    uVar6 = uVar3;
    if ((int)uVar3 <= iVar2 * iVar1) {
      y = (int)uVar3 / iVar1;
      x = (int)uVar3 % iVar1;
      iVar4 = arg_2 + x * arg_6;
      y_00 = arg_3 + y * arg_7;
      cx = arg_6;
      if (arg_4 + arg_2 <= arg_6 + iVar4) {
        cx = (arg_4 - iVar4) + arg_2;
      }
      cy = arg_7;
      if (arg_5 + arg_3 <= arg_7 + y_00) {
        cy = (arg_5 - y_00) + arg_3;
      }
      if ((arg_6 == 1) && (arg_7 == 1)) {
        color = GetPixel(param_8,x,y);
        uVar6 = SetPixelV(hdc,x,y,color);
      }
      else {
        uVar6 = BitBlt(hdc,iVar4,y_00,cx,cy,param_8,arg_9 + x * arg_6,arg_10 + y * arg_7,0xcc0020);
      }
      uVar5 = uVar5 - 1;
    }
  }
  return uVar6;
}


