/*
 * fopen.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __fsopen
 * Entry Point: 004dc6e0
 * Size: 258 bytes
 */


/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl __fsopen(char *filename,char *mode_str,int event_type)

{
  code *char_ptr_1;
  int val_2;
  FILE *pFVar3;
  
  if (filename == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0ab8,0x35,0,"file != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      pFVar3 = (FILE *)(*char_ptr_1)();
      return pFVar3;
    }
  }
  if (*filename == '\0') {
    val_2 = __CrtDbgReport(2,0x4f0ab8,0x36,0,"*file != _T(\'\\0\')");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      pFVar3 = (FILE *)(*char_ptr_1)();
      return pFVar3;
    }
  }
  if (str_2 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0ab8,0x37,0,"mode != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      pFVar3 = (FILE *)(*char_ptr_1)();
      return pFVar3;
    }
  }
  if (*str_2 == '\0') {
    val_2 = __CrtDbgReport(2,0x4f0ab8,0x38,0,"*mode != _T(\'\\0\')");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      pFVar3 = (FILE *)(*char_ptr_1)();
      return pFVar3;
    }
  }
  pFVar3 = __getstream();
  if (pFVar3 == (FILE *)0x0) {
    pFVar3 = (FILE *)0x0;
  }
  else {
    pFVar3 = __openfile(filename,str_2,arg_3,pFVar3);
  }
  return pFVar3;
}



/*
 * Decompiled function: _fopen
 * Entry Point: 004dc7f0
 * Size: 34 bytes
 */


/* Library Function - Single Match
    _fopen
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl _fopen(char *filename,char *mode_str)

{
  FILE *pFVar1;
  
  pFVar1 = __fsopen(filename,str_2,0x40);
  return pFVar1;
}



