/*
 * Decompiled function: __aulldiv
 * Entry Point: 004e8b60
 * Size: 104 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio 1998 Debug */

undefined8 __aulldiv(uint x,uint y,uint width,uint height)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;
  
  uVar9 = x;
  uVar6 = height;
  uVar7 = y;
  uVar3 = width;
  if (height == 0) {
    uVar3 = y / width;
    iVar4 = (int)(((ulonglong)y % (ulonglong)width << 0x20 | (ulonglong)x) / (ulonglong)width);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)width * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * height;
    if (((CARRY4(uVar3,iVar4 * height)) || (y < uVar9)) || ((y <= uVar9 && (x < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}


