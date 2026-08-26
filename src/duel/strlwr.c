/*
 * strlwr.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: __strlwr
 * Entry Point: 004eeea0
 * Size: 293 bytes
 */


/* Library Function - Single Match
    __strlwr
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __strlwr(char *filepath)

{
  LPSTR arg_6;
  int val_1;
  BOOL unaff_ESI;
  int unaff_EDI;
  char *card_idx;
  uint32_t *match_count;
  
  match_count = (uint32_t *)0x0;
  if (DAT_0050a730 == (_locale_t)0x0) {
    for (card_idx = str_1; *card_idx != '\0'; card_idx = card_idx + 1) {
      if (('@' < *card_idx) && (*card_idx < '[')) {
        *card_idx = *card_idx + ' ';
      }
    }
  }
  else {
    arg_6 = (LPSTR)___crtLCMapStringA(DAT_0050a730,(LPCWSTR)0x100,(DWORD)str_1,(LPCSTR)0xffffffff,0,
                                      (LPSTR)0x0,0,unaff_EDI,unaff_ESI);
    if (((arg_6 != (LPSTR)0x0) &&
        (match_count = (uint32_t *)__malloc_dbg(arg_6,2,"strlwr.c",100), match_count != (uint32_t *)0x0)) &&
       (val_1 = ___crtLCMapStringA(DAT_0050a730,(LPCWSTR)0x100,(DWORD)str_1,(LPCSTR)0xffffffff,
                                   (int)match_count,arg_6,0,unaff_EDI,unaff_ESI), val_1 != 0)) {
      Mem_AllocOrFree_004d9630((uint32_t *)str_1,match_count);
    }
    __free_dbg(match_count,2);
  }
  return str_1;
}



/*
 * Decompiled function: __mbctoupper
 * Entry Point: 004eefd0
 * Size: 188 bytes
 */


/* Library Function - Single Match
    __mbctoupper
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl __mbctoupper(uint32_t arg_1)

{
  int val_1;
  BOOL unaff_ESI;
  int unaff_EDI;
  uint8_t match_count;
  uint8_t local_b;
  uint8_t slot_idx;
  uint8_t local_7;
  
  if (arg_1 < 0x100) {
    if ((0x60 < (int)arg_1) && ((int)arg_1 < 0x7b)) {
      arg_1 = arg_1 - 0x20;
    }
  }
  else {
    slot_idx = (uint8_t)(arg_1 >> 8);
    local_7 = (uint8_t)arg_1;
    if ((((&DAT_0050a201)[slot_idx] & 4) != 0) &&
       (val_1 = ___crtLCMapStringA(DAT_0050a308,(LPCWSTR)0x200,(DWORD)&slot_idx,(LPCSTR)0x2,
                                   (int)&match_count,(LPSTR)0x2,DAT_0050a304,unaff_EDI,unaff_ESI),
       val_1 != 0)) {
      arg_1 = (uint32_t)local_b + (uint32_t)match_count * 0x100;
    }
  }
  return arg_1;
}



