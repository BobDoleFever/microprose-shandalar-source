/*
 * _getbuf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 5
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __getbuf
 * Entry Point: 004e8980
 * Size: 188 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __getbuf(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  char *char_ptr_3;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f1228,0x2e,0,"str != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  _DAT_005099d0 = _DAT_005099d0 + 1;
  char_ptr_3 = (char *)__malloc_dbg(0x1000,2,"_getbuf.c",0x3b);
  fp->_base = char_ptr_3;
  if (fp->_base == (char *)0x0) {
    fp->_flag = fp->_flag | 4;
    fp->_base = (char *)&fp->_charbuf;
    fp->_bufsiz = 2;
  }
  else {
    fp->_flag = fp->_flag | 8;
    fp->_bufsiz = 0x1000;
  }
  fp->_ptr = fp->_base;
  fp->_cnt = 0;
  return;
}



/*
 * Decompiled function: __isatty
 * Entry Point: 004e8a40
 * Size: 66 bytes
 */


/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isatty(int player_id)

{
  uint32_t uval_1;
  
  if ((uint32_t)arg_1 < DAT_006c1c90) {
    uval_1 = (int)*(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) & 0x40;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: _wctomb
 * Entry Point: 004e8a90
 * Size: 198 bytes
 */


/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Debug */

int __cdecl _wctomb(char *filepath,wchar_t arg_2)

{
  int val_1;
  int16_t stack_arg;
  BOOL match_count [2];
  
  if (str_1 == (char *)0x0) {
    val_1 = 0;
  }
  else if (DAT_0050a730 == 0) {
    if ((uint16_t)arg_2 < 0x100) {
      *str_1 = (char)arg_2;
      val_1 = 1;
    }
    else {
      DAT_00509420 = 0x2a;
      val_1 = -1;
    }
  }
  else {
    match_count[0] = 0;
    val_1 = WideCharToMultiByte(DAT_0050a740,0x220,&arg_2,1,str_1,DAT_005096ac,(LPCSTR)0x0,match_count);
    if ((val_1 == 0) || (match_count[0] != 0)) {
      DAT_00509420 = 0x2a;
      val_1 = -1;
    }
  }
  return val_1;
}



/*
 * Decompiled function: __aulldiv
 * Entry Point: 004e8b60
 * Size: 104 bytes
 */


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



/*
 * Decompiled function: __aullrem
 * Entry Point: 004e8bd0
 * Size: 117 bytes
 */


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



