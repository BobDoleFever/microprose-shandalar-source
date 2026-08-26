/*
 * Decompiled function: __aulldiv
 * Entry Point: 00409bb0
 * Size: 104 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio 1998 Debug */

undefined8 __aulldiv(uint32_t x,uint32_t y,uint32_t width,uint32_t height)

{
  ulonglong uval_1;
  longlong lVar2;
  uint32_t uval_3;
  int val_4;
  uint32_t uval_5;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uval_6;
  
  uVar9 = x;
  uval_6 = height;
  uval_7 = y;
  uval_3 = width;
  if (height == 0) {
    uval_3 = y / width;
    val_4 = (int)(((ulonglong)y % (ulonglong)width << 0x20 | (ulonglong)x) / (ulonglong)width);
  }
  else {
    do {
      uval_5 = uval_6 >> 1;
      uval_3 = (uint32_t)(CONCAT14((uval_6 & 1) != 0,uval_3) >> 1);
      uval_8 = uval_7 >> 1;
      uVar9 = (uint32_t)(CONCAT14((uval_7 & 1) != 0,uVar9) >> 1);
      uval_6 = uval_5;
      uval_7 = uval_8;
    } while (uval_5 != 0);
    uval_1 = CONCAT44(uval_8,uVar9) / (ulonglong)uval_3;
    val_4 = (int)uval_1;
    lVar2 = (ulonglong)width * (uval_1 & 0xffffffff);
    uval_3 = (uint32_t)((ulonglong)lVar2 >> 0x20);
    uVar9 = uval_3 + val_4 * height;
    if (((CARRY4(uval_3,val_4 * height)) || (y < uVar9)) || ((y <= uVar9 && (x < (uint32_t)lVar2)))) {
      val_4 = val_4 + -1;
    }
    uval_3 = 0;
  }
  return CONCAT44(uval_3,val_4);
}


