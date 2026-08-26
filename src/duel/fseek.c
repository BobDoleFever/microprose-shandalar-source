/*
 * fseek.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: _fseek
 * Entry Point: 004dca30
 * Size: 304 bytes
 */


/* Library Function - Single Match
    _fseek
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fseek(FILE *fp,long arg_2,int event_type)

{
  code *char_ptr_1;
  int val_2;
  long lVar3;
  
  if ((fp == (FILE *)0x0) && (val_2 = __CrtDbgReport(2,0x4f0ae8,0x92,0,"str != NULL"), val_2 == 1))
  {
    char_ptr_1 = (code *)swi(3);
    val_2 = (*char_ptr_1)();
    return val_2;
  }
  if (((fp->_flag & 0x83) == 0) || (((arg_3 != 0 && (arg_3 != 1)) && (arg_3 != 2)))) {
    DAT_00509420 = 0x16;
    val_2 = -1;
  }
  else {
    fp->_flag = fp->_flag & 0xffffffef;
    if (arg_3 == 1) {
      lVar3 = _ftell(fp);
      arg_2 = arg_2 + lVar3;
      arg_3 = 0;
    }
    __flush(fp);
    if ((fp->_flag & 0x80) == 0) {
      if ((((fp->_flag & 1) != 0) && ((fp->_flag & 8) != 0)) && ((fp->_flag & 0x400) == 0)) {
        fp->_bufsiz = 0x200;
      }
    }
    else {
      fp->_flag = fp->_flag & 0xfffffffc;
    }
    lVar3 = __lseek(fp->_file,arg_2,arg_3);
    if (lVar3 == -1) {
      val_2 = -1;
    }
    else {
      val_2 = 0;
    }
  }
  return val_2;
}



/*
 * Decompiled function: __splitpath
 * Entry Point: 004dcb60
 * Size: 578 bytes
 */


/* Library Function - Single Match
    __splitpath
   
   Library: Visual Studio 1998 Debug */

void __cdecl __splitpath(char *filepath,char *mode_str,char *str_3,char *str_4,char *str_5)

{
  size_t len_1;
  uint8_t *card_idx;
  uint8_t *match_count;
  uint8_t *slot_idx;
  
  match_count = (uint8_t *)0x0;
  if (str_1[1] == ':') {
    if (str_2 != (char *)0x0) {
      __mbsnbcpy((uchar *)str_2,(uchar *)str_1,2);
      str_2[2] = '\0';
    }
    str_1 = str_1 + 2;
  }
  else if (str_2 != (char *)0x0) {
    *str_2 = '\0';
  }
  card_idx = (uint8_t *)0x0;
  for (slot_idx = (uint8_t *)str_1; *slot_idx != 0; slot_idx = slot_idx + 1) {
    if (((&DAT_0050a201)[*slot_idx] & 4) == 0) {
      if ((*slot_idx == 0x2f) || (*slot_idx == 0x5c)) {
        card_idx = slot_idx + 1;
      }
      else if (*slot_idx == 0x2e) {
        match_count = slot_idx;
      }
    }
    else {
      slot_idx = slot_idx + 1;
    }
  }
  if (card_idx == (uint8_t *)0x0) {
    if (str_3 != (char *)0x0) {
      *str_3 = '\0';
    }
  }
  else {
    if (str_3 != (char *)0x0) {
      len_1 = (int)card_idx - (int)str_1;
      if (0xfe < len_1) {
        len_1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_3,(uchar *)str_1,len_1);
      str_3[len_1] = '\0';
    }
    str_1 = (char *)card_idx;
  }
  if ((match_count == (uint8_t *)0x0) || (match_count < str_1)) {
    if (str_4 != (char *)0x0) {
      len_1 = (int)slot_idx - (int)str_1;
      if (0xfe < len_1) {
        len_1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_4,(uchar *)str_1,len_1);
      str_4[len_1] = '\0';
    }
    if (str_5 != (char *)0x0) {
      *str_5 = '\0';
    }
  }
  else {
    if (str_4 != (char *)0x0) {
      len_1 = (int)match_count - (int)str_1;
      if (0xfe < len_1) {
        len_1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_4,(uchar *)str_1,len_1);
      str_4[len_1] = '\0';
    }
    if (str_5 != (char *)0x0) {
      len_1 = (int)slot_idx - (int)match_count;
      if (0xfe < len_1) {
        len_1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_5,match_count,len_1);
      str_5[len_1] = '\0';
    }
  }
  return;
}



