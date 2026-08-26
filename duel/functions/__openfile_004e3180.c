/*
 * Decompiled function: __openfile
 * Entry Point: 004e3180
 * Size: 831 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __openfile
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl __openfile(char *x,char *y,int width,FILE *height)

{
  char cVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  FILE *pFVar7;
  uint local_20;
  uint local_18;
  
  local_20 = DAT_0050a720;
  bVar4 = false;
  bVar5 = false;
  if ((x == (char *)0x0) &&
     (iVar6 = __CrtDbgReport(2,0x4f0e70,0x47,0,"filename != NULL"), iVar6 == 1)) {
    pcVar2 = (code *)swi(3);
    pFVar7 = (FILE *)(*pcVar2)();
    return pFVar7;
  }
  if ((y == (char *)0x0) && (iVar6 = __CrtDbgReport(2,0x4f0e70,0x48,0,"mode != NULL"), iVar6 == 1))
  {
    pcVar2 = (code *)swi(3);
    pFVar7 = (FILE *)(*pcVar2)();
    return pFVar7;
  }
  if ((height == (FILE *)0x0) &&
     (iVar6 = __CrtDbgReport(2,0x4f0e70,0x49,0,"str != NULL"), iVar6 == 1)) {
    pcVar2 = (code *)swi(3);
    pFVar7 = (FILE *)(*pcVar2)();
    return pFVar7;
  }
  cVar1 = *y;
  if (cVar1 == 'a') {
    local_18 = 0x109;
    local_20 = local_20 | 2;
  }
  else if (cVar1 == 'r') {
    local_18 = 0;
    local_20 = local_20 | 1;
  }
  else {
    if (cVar1 != 'w') {
      return (FILE *)0x0;
    }
    local_18 = 0x301;
    local_20 = local_20 | 2;
  }
  bVar3 = true;
  while ((y = y + 1, *y != '\0' && (bVar3))) {
    switch(*y) {
    case '+':
      if ((local_18 & 2) == 0) {
        local_18 = local_18 & 0xfffffffe | 2;
        local_20 = local_20 & 0xfffffffc | 0x80;
      }
      else {
        bVar3 = false;
      }
      break;
    default:
      bVar3 = false;
      break;
    case 'D':
      if ((local_18 & 0x40) == 0) {
        local_18 = local_18 | 0x40;
      }
      else {
        bVar3 = false;
      }
      break;
    case 'R':
      if (bVar5) {
        bVar3 = false;
      }
      else {
        bVar5 = true;
        local_18 = local_18 | 0x10;
      }
      break;
    case 'S':
      if (bVar5) {
        bVar3 = false;
      }
      else {
        bVar5 = true;
        local_18 = local_18 | 0x20;
      }
      break;
    case 'T':
      if ((local_18 & 0x1000) == 0) {
        local_18 = local_18 | 0x1000;
      }
      else {
        bVar3 = false;
      }
      break;
    case 'b':
      if ((local_18 & 0xc000) == 0) {
        local_18 = local_18 | 0x8000;
      }
      else {
        bVar3 = false;
      }
      break;
    case 'c':
      if (bVar4) {
        bVar3 = false;
      }
      else {
        bVar4 = true;
        local_20 = local_20 | 0x4000;
      }
      break;
    case 'n':
      if (bVar4) {
        bVar3 = false;
      }
      else {
        bVar4 = true;
        local_20 = local_20 & 0xffffbfff;
      }
      break;
    case 't':
      if ((local_18 & 0xc000) == 0) {
        local_18 = local_18 | 0x4000;
      }
      else {
        bVar3 = false;
      }
    }
  }
  iVar6 = __sopen(x,local_18,width,0x1a4);
  if (iVar6 < 0) {
    height = (FILE *)0x0;
  }
  else {
    _DAT_005099d0 = _DAT_005099d0 + 1;
    height->_flag = local_20;
    height->_cnt = 0;
    height->_ptr = (char *)0x0;
    height->_base = height->_ptr;
    height->_tmpfname = height->_base;
    height->_file = iVar6;
  }
  return height;
}


