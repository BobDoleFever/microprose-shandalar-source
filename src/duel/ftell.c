/*
 * ftell.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: _ftell
 * Entry Point: 004de240
 * Size: 674 bytes
 */


/* Library Function - Single Match
    _ftell
   
   Library: Visual Studio 1998 Debug */

long __cdecl _ftell(FILE *fp)

{
  uint32_t arg_1;
  code *char_ptr_1;
  int val_2;
  long lVar3;
  char *pcVar4;
  int loop_idx;
  int color_idx;
  char *player_idx;
  char *slot_idx;
  
  if ((fp == (FILE *)0x0) && (val_2 = __CrtDbgReport(2,0x4f0b28,99,0,"str != NULL"), val_2 == 1)) {
    char_ptr_1 = (code *)swi(3);
    lVar3 = (*char_ptr_1)();
    return lVar3;
  }
  arg_1 = fp->_file;
  if (fp->_cnt < 0) {
    fp->_cnt = 0;
  }
  loop_idx = __lseek(arg_1,0,1);
  if (loop_idx < 0) {
    color_idx = -1;
  }
  else if ((fp->_flag & 0x108U) == 0) {
    color_idx = loop_idx - fp->_cnt;
  }
  else {
    color_idx = (int)fp->_ptr - (int)fp->_base;
    if ((fp->_flag & 3) == 0) {
      if ((fp->_flag & 0x80) == 0) {
        DAT_00509420 = 0x16;
        return -1;
      }
    }
    else if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0) >> 3)) + 4 +
                       (arg_1 & 0x1f) * 8) & 0x80) != 0) {
      for (slot_idx = fp->_base; slot_idx < fp->_ptr; slot_idx = slot_idx + 1) {
        if (*slot_idx == '\n') {
          color_idx = color_idx + 1;
        }
      }
    }
    if (loop_idx != 0) {
      if ((fp->_flag & 1) != 0) {
        if (fp->_cnt == 0) {
          color_idx = 0;
        }
        else {
          player_idx = fp->_ptr + (fp->_cnt - (int)fp->_base);
          if (((int)*(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0) >> 3)) + 4 +
                             (arg_1 & 0x1f) * 8) & 0x80U) != 0) {
            lVar3 = __lseek(arg_1,0,2);
            if (lVar3 == loop_idx) {
              pcVar4 = fp->_base + (int)player_idx;
              for (slot_idx = fp->_base; slot_idx < pcVar4; slot_idx = slot_idx + 1) {
                if (*slot_idx == '\n') {
                  player_idx = player_idx + 1;
                }
              }
              if ((fp->_flag & 0x2000) != 0) {
                player_idx = player_idx + 1;
              }
            }
            else {
              __lseek(arg_1,loop_idx,0);
              if (((player_idx < (char *)0x201) && ((fp->_flag & 8) != 0)) &&
                 ((fp->_flag & 0x400) == 0)) {
                player_idx = (char *)0x200;
              }
              else {
                player_idx = (char *)fp->_bufsiz;
              }
              if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0) >> 3)) + 4 +
                            (arg_1 & 0x1f) * 8) & 4) != 0) {
                player_idx = player_idx + 1;
              }
            }
          }
          loop_idx = loop_idx - (int)player_idx;
        }
      }
      color_idx = loop_idx + color_idx;
    }
  }
  return color_idx;
}



