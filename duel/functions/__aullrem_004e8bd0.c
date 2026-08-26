/*
 * Decompiled function: __aullrem
 * Entry Point: 004e8bd0
 * Size: 117 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio 1998 Debug */

undefined8 __aullrem(uint x,uint y,uint width,uint height)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = x;
  uVar9 = height;
  uVar10 = y;
  uVar3 = width;
  if (height == 0) {
    iVar6 = (int)(((ulonglong)y % (ulonglong)width << 0x20 | (ulonglong)x) % (ulonglong)width);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar5;
      uVar10 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * height;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)width;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (y < uVar10)) || ((y <= uVar10 && (x < uVar4)))) {
      bVar11 = uVar4 < width;
      uVar4 = uVar4 - width;
      uVar10 = (uVar10 - height) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - x);
    iVar7 = -(uint)(uVar4 - x != 0) - ((uVar10 - y) - (uint)(uVar4 < x));
  }
  return CONCAT44(iVar7,iVar6);
}


