/*
 * fclose.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: _fclose
 * Entry Point: 004dc820
 * Size: 237 bytes
 */


/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fclose(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  int slot_idx;
  
  slot_idx = -1;
  if ((fp->_flag & 0x40) == 0) {
    if (fp == (FILE *)0x0) {
      val_2 = __CrtDbgReport(2,0x4f0ad0,0x77,0,"str != NULL");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        val_2 = (*char_ptr_1)();
        return val_2;
      }
    }
    if ((fp->_flag & 0x83) != 0) {
      slot_idx = __flush(fp);
      __freebuf(fp);
      val_2 = __close(fp->_file);
      if (val_2 < 0) {
        slot_idx = -1;
      }
      else if (fp->_tmpfname != (char *)0x0) {
        __free_dbg(fp->_tmpfname,2);
        fp->_tmpfname = (char *)0x0;
      }
    }
    fp->_flag = 0;
  }
  else {
    fp->_flag = 0;
    slot_idx = -1;
  }
  return slot_idx;
}



/*
 * Decompiled function: _bsearch
 * Entry Point: 004dc910
 * Size: 277 bytes
 */


/* Library Function - Single Match
    _bsearch
   
   Library: Visual Studio 1998 Debug */

void * __cdecl
_bsearch(void *ptr_1,void *out_buffer,size_t arg_3,size_t arg_4,_PtFuncCompare *ptr_5)

{
  uint32_t uval_1;
  uint32_t uval_2;
  void *buf_ptr_3;
  int val_4;
  uint32_t color_idx;
  void *target_idx;
  void *player_idx;
  
  player_idx = out_buffer;
  target_idx = (void *)((arg_3 - 1) * arg_4 + (int)out_buffer);
  while( true ) {
    if (target_idx < player_idx) {
      return (void *)0x0;
    }
    uval_2 = arg_3 >> 1;
    if (uval_2 == 0) break;
    color_idx = uval_2;
    if ((arg_3 & 1) == 0) {
      color_idx = uval_2 - 1;
    }
    buf_ptr_3 = (void *)(arg_4 * color_idx + (int)player_idx);
    val_4 = (*ptr_5)(ptr_1,buf_ptr_3);
    if (val_4 == 0) {
      return buf_ptr_3;
    }
    if (val_4 < 0) {
      target_idx = (void *)((int)buf_ptr_3 - arg_4);
      uval_1 = arg_3 & 1;
      arg_3 = uval_2;
      if (uval_1 == 0) {
        arg_3 = uval_2 - 1;
      }
    }
    else {
      player_idx = (void *)(arg_4 + (int)buf_ptr_3);
      arg_3 = uval_2;
    }
  }
  if (arg_3 == 0) {
    return (void *)0x0;
  }
  val_4 = (*ptr_5)(ptr_1,player_idx);
  if (val_4 != 0) {
    return (void *)0x0;
  }
  return player_idx;
}



