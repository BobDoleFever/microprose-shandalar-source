/*
 * fscanf.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: _fscanf
 * Entry Point: 004dcee0
 * Size: 139 bytes
 */


/* Library Function - Single Match
    _fscanf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fscanf(FILE *fp,char *mode_str,...)

{
  code *char_ptr_1;
  int val_2;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0af8,0x36,0,"stream != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_2 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0af8,0x37,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  val_2 = __input((int)fp,(uint8_t *)str_2,(int32_t *)&stack0x0000000c);
  return val_2;
}



/*
 * Decompiled function: _strchr
 * Entry Point: 004dcf80
 * Size: 193 bytes
 */


/* Library Function - Single Match
    _strchr
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strchr(char *filepath,int card_slot)

{
  uint32_t uval_1;
  char cVar2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t *puVar5;
  
  while (((uint32_t)str_1 & 3) != 0) {
    uval_1 = *(uint32_t *)str_1;
    if ((char)uval_1 == (char)arg_2) {
      return (char *)(uint32_t *)str_1;
    }
    str_1 = (char *)((int)str_1 + 1);
    if ((char)uval_1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uval_1 = *(uint32_t *)str_1;
      uval_4 = uval_1 ^ CONCAT22(CONCAT11((char)arg_2,(char)arg_2),CONCAT11((char)arg_2,(char)arg_2));
      uval_3 = uval_1 ^ 0xffffffff ^ uval_1 + 0x7efefeff;
      puVar5 = (uint32_t *)((int)str_1 + 4);
      if (((uval_4 ^ 0xffffffff ^ uval_4 + 0x7efefeff) & 0x81010100) != 0) break;
      str_1 = (char *)puVar5;
      if ((uval_3 & 0x81010100) != 0) {
        if ((uval_3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uval_1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uval_1 = *(uint32_t *)str_1;
    if ((char)uval_1 == (char)arg_2) {
      return (char *)(uint32_t *)str_1;
    }
    if ((char)uval_1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uval_1 >> 8);
    if (cVar2 == (char)arg_2) {
      return (char *)((int)str_1 + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uval_1 >> 0x10);
    if (cVar2 == (char)arg_2) {
      return (char *)((int)str_1 + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uval_1 >> 0x18);
    if (cVar2 == (char)arg_2) {
      return (char *)((int)str_1 + 3);
    }
    str_1 = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



