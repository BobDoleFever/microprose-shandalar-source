/*
 * Decompiled function: __aullrem
 * Entry Point: 00409c20
 * Size: 117 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio 1998 Debug */

undefined8 __aullrem(uint32_t x,uint32_t y,uint32_t width,uint32_t height)

{
  ulonglong uval_1;
  longlong lVar2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int val_6;
  int val_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  bool bVar11;
  
  uval_4 = x;
  uVar9 = height;
  uVar10 = y;
  uval_3 = width;
  if (height == 0) {
    val_6 = (int)(((ulonglong)y % (ulonglong)width << 0x20 | (ulonglong)x) % (ulonglong)width);
    val_7 = 0;
  }
  else {
    do {
      uval_5 = uVar9 >> 1;
      uval_3 = (uint32_t)(CONCAT14((uVar9 & 1) != 0,uval_3) >> 1);
      uval_8 = uVar10 >> 1;
      uval_4 = (uint32_t)(CONCAT14((uVar10 & 1) != 0,uval_4) >> 1);
      uVar9 = uval_5;
      uVar10 = uval_8;
    } while (uval_5 != 0);
    uval_1 = CONCAT44(uval_8,uval_4) / (ulonglong)uval_3;
    uval_3 = (int)uval_1 * height;
    lVar2 = (uval_1 & 0xffffffff) * (ulonglong)width;
    uVar9 = (uint32_t)((ulonglong)lVar2 >> 0x20);
    uval_4 = (uint32_t)lVar2;
    uVar10 = uVar9 + uval_3;
    if (((CARRY4(uVar9,uval_3)) || (y < uVar10)) || ((y <= uVar10 && (x < uval_4)))) {
      bVar11 = uval_4 < width;
      uval_4 = uval_4 - width;
      uVar10 = (uVar10 - height) - (uint32_t)bVar11;
    }
    val_6 = -(uval_4 - x);
    val_7 = -(uint32_t)(uval_4 - x != 0) - ((uVar10 - y) - (uint32_t)(uval_4 < x));
  }
  return CONCAT44(val_7,val_6);
}


