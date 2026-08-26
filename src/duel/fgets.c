/*
 * fgets.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: _fgets
 * Entry Point: 004dcdb0
 * Size: 301 bytes
 */


/* Library Function - Single Match
    _fgets
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _fgets(char *filepath,int card_slot,FILE *fp)

{
  char cVar1;
  code *char_ptr_2;
  int val_3;
  char *pcVar4;
  uint32_t card_idx;
  char *match_count;
  
  match_count = str_1;
  if ((str_1 == (char *)0x0) &&
     (val_3 = __CrtDbgReport(2,0x4f0af0,0x3b,0,"string != NULL"), val_3 == 1)) {
    char_ptr_2 = (code *)swi(3);
    pcVar4 = (char *)(*char_ptr_2)();
    return pcVar4;
  }
  if ((fp == (FILE *)0x0) && (val_3 = __CrtDbgReport(2,0x4f0af0,0x3c,0,"str != NULL"), val_3 == 1))
  {
    char_ptr_2 = (code *)swi(3);
    pcVar4 = (char *)(*char_ptr_2)();
    return pcVar4;
  }
  if (arg_2 < 1) {
    str_1 = (char *)0x0;
  }
  else {
    do {
      arg_2 = arg_2 + -1;
      if (arg_2 == 0) break;
      fp->_cnt = fp->_cnt + -1;
      if (fp->_cnt < 0) {
        card_idx = __filbuf(fp);
      }
      else {
        card_idx = (uint32_t)(uint8_t)*fp->_ptr;
        fp->_ptr = fp->_ptr + 1;
      }
      if (card_idx == 0xffffffff) {
        if (str_1 == match_count) {
          return (char *)0x0;
        }
        break;
      }
      pcVar4 = match_count + 1;
      *match_count = (char)card_idx;
      cVar1 = *match_count;
      match_count = pcVar4;
    } while (cVar1 != '\n');
    *match_count = '\0';
  }
  return str_1;
}



