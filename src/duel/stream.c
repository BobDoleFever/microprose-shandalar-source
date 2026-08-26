/*
 * stream.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: __getstream
 * Entry Point: 004e3540
 * Size: 274 bytes
 */


/* Library Function - Single Match
    __getstream
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl __getstream(void)

{
  int32_t uval_1;
  FILE *match_count;
  int slot_idx;
  
  match_count = (FILE *)0x0;
  slot_idx = 0;
  do {
    if (DAT_006c2ca0 <= slot_idx) {
LAB_004e35fb:
      if (match_count != (FILE *)0x0) {
        match_count->_cnt = 0;
        match_count->_flag = match_count->_cnt;
        match_count->_base = (char *)0x0;
        match_count->_ptr = match_count->_base;
        match_count->_tmpfname = match_count->_ptr;
        match_count->_file = -1;
      }
      return match_count;
    }
    if (*(int *)(DAT_006c1c98 + slot_idx * 4) == 0) {
      uval_1 = __malloc_dbg(0x20,2,"stream.c",0x55);
      *(int32_t *)(DAT_006c1c98 + slot_idx * 4) = uval_1;
      if (*(int *)(DAT_006c1c98 + slot_idx * 4) != 0) {
        match_count = *(FILE **)(DAT_006c1c98 + slot_idx * 4);
      }
      goto LAB_004e35fb;
    }
    if ((*(uint8_t *)(*(int *)(DAT_006c1c98 + slot_idx * 4) + 0xc) & 0x83) == 0) {
      match_count = *(FILE **)(DAT_006c1c98 + slot_idx * 4);
      goto LAB_004e35fb;
    }
    slot_idx = slot_idx + 1;
  } while( true );
}



