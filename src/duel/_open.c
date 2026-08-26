/*
 * _open.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __openfile
 * Entry Point: 004e3180
 * Size: 831 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __openfile
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl __openfile(char *x,char *y,int width,FILE *height)

{
  char cVar1;
  code *char_ptr_2;
  bool flag_3;
  bool bVar4;
  bool bVar5;
  int val_6;
  FILE *pFVar7;
  uint32_t loop_idx;
  uint32_t target_idx;
  
  loop_idx = DAT_0050a720;
  bVar4 = false;
  bVar5 = false;
  if ((x == (char *)0x0) &&
     (val_6 = __CrtDbgReport(2,0x4f0e70,0x47,0,"filename != NULL"), val_6 == 1)) {
    char_ptr_2 = (code *)swi(3);
    pFVar7 = (FILE *)(*char_ptr_2)();
    return pFVar7;
  }
  if ((y == (char *)0x0) && (val_6 = __CrtDbgReport(2,0x4f0e70,0x48,0,"mode != NULL"), val_6 == 1))
  {
    char_ptr_2 = (code *)swi(3);
    pFVar7 = (FILE *)(*char_ptr_2)();
    return pFVar7;
  }
  if ((height == (FILE *)0x0) &&
     (val_6 = __CrtDbgReport(2,0x4f0e70,0x49,0,"str != NULL"), val_6 == 1)) {
    char_ptr_2 = (code *)swi(3);
    pFVar7 = (FILE *)(*char_ptr_2)();
    return pFVar7;
  }
  cVar1 = *y;
  if (cVar1 == 'a') {
    target_idx = 0x109;
    loop_idx = loop_idx | 2;
  }
  else if (cVar1 == 'r') {
    target_idx = 0;
    loop_idx = loop_idx | 1;
  }
  else {
    if (cVar1 != 'w') {
      return (FILE *)0x0;
    }
    target_idx = 0x301;
    loop_idx = loop_idx | 2;
  }
  flag_3 = true;
  while ((y = y + 1, *y != '\0' && (flag_3))) {
    switch(*y) {
    case '+':
      if ((target_idx & 2) == 0) {
        target_idx = target_idx & 0xfffffffe | 2;
        loop_idx = loop_idx & 0xfffffffc | 0x80;
      }
      else {
        flag_3 = false;
      }
      break;
    default:
      flag_3 = false;
      break;
    case 'D':
      if ((target_idx & 0x40) == 0) {
        target_idx = target_idx | 0x40;
      }
      else {
        flag_3 = false;
      }
      break;
    case 'R':
      if (bVar5) {
        flag_3 = false;
      }
      else {
        bVar5 = true;
        target_idx = target_idx | 0x10;
      }
      break;
    case 'S':
      if (bVar5) {
        flag_3 = false;
      }
      else {
        bVar5 = true;
        target_idx = target_idx | 0x20;
      }
      break;
    case 'T':
      if ((target_idx & 0x1000) == 0) {
        target_idx = target_idx | 0x1000;
      }
      else {
        flag_3 = false;
      }
      break;
    case 'b':
      if ((target_idx & 0xc000) == 0) {
        target_idx = target_idx | 0x8000;
      }
      else {
        flag_3 = false;
      }
      break;
    case 'c':
      if (bVar4) {
        flag_3 = false;
      }
      else {
        bVar4 = true;
        loop_idx = loop_idx | 0x4000;
      }
      break;
    case 'n':
      if (bVar4) {
        flag_3 = false;
      }
      else {
        bVar4 = true;
        loop_idx = loop_idx & 0xffffbfff;
      }
      break;
    case 't':
      if ((target_idx & 0xc000) == 0) {
        target_idx = target_idx | 0x4000;
      }
      else {
        flag_3 = false;
      }
    }
  }
  val_6 = __sopen(x,target_idx,width,0x1a4);
  if (val_6 < 0) {
    height = (FILE *)0x0;
  }
  else {
    _DAT_005099d0 = _DAT_005099d0 + 1;
    height->_flag = loop_idx;
    height->_cnt = 0;
    height->_ptr = (char *)0x0;
    height->_base = height->_ptr;
    height->_tmpfname = height->_base;
    height->_file = val_6;
  }
  return height;
}



