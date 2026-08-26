/*
 * wtombenv.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___wtomb_environ
 * Entry Point: 004ed720
 * Size: 205 bytes
 */


/* Library Function - Single Match
    ___wtomb_environ
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___wtomb_environ(void)

{
  int val_1;
  char **str_1;
  int *slot_idx;
  
  slot_idx = DAT_00509450;
  while( true ) {
    if (*slot_idx == 0) {
      return 0;
    }
    val_1 = WideCharToMultiByte(1,0,(LPCWSTR)*slot_idx,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (val_1 == 0) {
      return -1;
    }
    str_1 = (char **)__malloc_dbg(val_1,2,"wtombenv.c",0x3d);
    if (str_1 == (char **)0x0) {
      return -1;
    }
    val_1 = WideCharToMultiByte(1,0,(LPCWSTR)*slot_idx,-1,(LPSTR)str_1,val_1,(LPCSTR)0x0,(LPBOOL)0x0)
    ;
    if (val_1 == 0) break;
    ___crtsetenv(str_1,0);
    slot_idx = slot_idx + 1;
  }
  return -1;
}



/*
 * Decompiled function: ___ld12mul
 * Entry Point: 004ed7f0
 * Size: 1063 bytes
 */


/* Library Function - Single Match
    ___ld12mul
   
   Library: Visual Studio 1998 Debug */

void ___ld12mul(int *arg1,int *arg2)

{
  short len_1;
  int val_2;
  uint16_t uval_3;
  uint16_t uval_4;
  uint16_t uval_5;
  int val_6;
  int local_3c;
  uint16_t local_38;
  int local_30;
  int local_2c;
  int local_24;
  int32_t color_idx;
  short target_idx [3];
  uint8_t uStack_12;
  uint8_t bStack_11;
  int16_t card_idx;
  int match_count;
  int slot_idx;
  
  card_idx = 0;
  color_idx._0_1_ = 0;
  color_idx._1_1_ = 0;
  color_idx._2_2_ = 0;
  target_idx[0] = 0;
  target_idx[1] = 0;
  target_idx[2] = 0;
  uStack_12 = 0;
  bStack_11 = 0;
  uval_3 = *(uint16_t *)((int)arg1 + 10);
  uval_4 = *(uint16_t *)((int)arg2 + 10);
  uval_5 = uval_4 ^ uval_3;
  local_38 = (uval_4 & 0x7fff) + (uval_3 & 0x7fff);
  if ((((uval_3 & 0x7fff) < 0x7fff) && ((uval_4 & 0x7fff) < 0x7fff)) && (local_38 < 0xbffe)) {
    if (local_38 < 0x3fc0) {
      arg1[2] = 0;
      arg1[1] = 0;
      *arg1 = 0;
    }
    else if ((((uval_3 & 0x7fff) == 0) && (local_38 = local_38 + 1, (arg1[2] & 0x7fffffffU) == 0)) &&
            ((arg1[1] == 0 && (*arg1 == 0)))) {
      *(int16_t *)((int)arg1 + 10) = 0;
    }
    else if ((((uval_4 & 0x7fff) == 0) && (local_38 = local_38 + 1, (arg2[2] & 0x7fffffffU) == 0)) &&
            ((arg2[1] == 0 && (*arg2 == 0)))) {
      arg1[2] = 0;
      arg1[1] = 0;
      *arg1 = 0;
    }
    else {
      local_30 = 0;
      for (local_24 = 0; local_24 < 5; local_24 = local_24 + 1) {
        local_2c = local_24 * 2;
        match_count = 8;
        for (local_3c = 5 - local_24; 0 < local_3c; local_3c = local_3c + -1) {
          val_6 = ___addl(*(uint32_t *)((int)&color_idx + local_30),
                          (uint32_t)*(uint16_t *)((int)arg2 + match_count) *
                          (uint32_t)*(uint16_t *)(local_2c + (int)arg1),
                          (uint32_t *)((int)&color_idx + local_30));
          if (val_6 != 0) {
            *(short *)((int)target_idx + local_30) = *(short *)((int)target_idx + local_30) + 1;
          }
          local_2c = local_2c + 2;
          match_count = match_count + -2;
        }
        local_30 = local_30 + 2;
      }
      local_38 = local_38 + 0xc002;
      while ((0 < (short)local_38 && ((bStack_11 & 0x80) == 0))) {
        ___shl_12(&color_idx);
        local_38 = local_38 - 1;
      }
      if ((short)local_38 < 1) {
        for (local_38 = local_38 - 1; (short)local_38 < 0; local_38 = local_38 + 1) {
          if (((uint8_t)color_idx & 1) != 0) {
            slot_idx = slot_idx + 1;
          }
          ___shr_12(&color_idx);
        }
        if (slot_idx != 0) {
          color_idx._0_1_ = (uint8_t)color_idx | 1;
        }
      }
      val_2 = CONCAT22(target_idx[0],color_idx._2_2_);
      val_6 = CONCAT22(target_idx[2],target_idx[1]);
      len_1 = CONCAT11(bStack_11,uStack_12);
      if (0x8000 < CONCAT11(color_idx._1_1_,(uint8_t)color_idx)) {
        if (CONCAT22(target_idx[0],color_idx._2_2_) == -1) {
          val_2 = 0;
          if (CONCAT22(target_idx[2],target_idx[1]) == -1) {
            val_6 = 0;
            if (CONCAT11(bStack_11,uStack_12) == -1) {
              len_1 = -0x8000;
              local_38 = local_38 + 1;
            }
            else {
              len_1 = CONCAT11(bStack_11,uStack_12) + 1;
            }
          }
          else {
            val_6 = CONCAT22(target_idx[2],target_idx[1]) + 1;
          }
        }
        else {
          val_2 = CONCAT22(target_idx[0],color_idx._2_2_) + 1;
          val_6 = CONCAT22(target_idx[2],target_idx[1]);
        }
      }
      target_idx[0] = (short)((uint32_t)val_2 >> 0x10);
      color_idx._2_2_ = (int16_t)val_2;
      bStack_11 = (uint8_t)((uint16_t)len_1 >> 8);
      uStack_12 = (uint8_t)len_1;
      target_idx[2] = (short)((uint32_t)val_6 >> 0x10);
      target_idx[1] = (short)val_6;
      if (local_38 < 0x7fff) {
        *(int16_t *)arg1 = color_idx._2_2_;
        *(uint32_t *)((int)arg1 + 2) = CONCAT22(target_idx[1],target_idx[0]);
        *(uint32_t *)((int)arg1 + 6) = CONCAT13(bStack_11,CONCAT12(uStack_12,target_idx[2]));
        *(uint16_t *)((int)arg1 + 10) = uval_5 & 0x8000 | local_38;
      }
      else {
        if ((uval_5 & 0x8000) == 0) {
          arg1[2] = 0x7fff8000;
        }
        else {
          arg1[2] = -0x8000;
        }
        arg1[1] = 0;
        *arg1 = 0;
      }
    }
  }
  else {
    if ((uval_5 & 0x8000) == 0) {
      arg1[2] = 0x7fff8000;
    }
    else {
      arg1[2] = -0x8000;
    }
    arg1[1] = 0;
    *arg1 = 0;
  }
  return;
}



/*
 * Decompiled function: ___multtenpow12
 * Entry Point: 004edc20
 * Size: 216 bytes
 */


/* Library Function - Single Match
    ___multtenpow12
   
   Library: Visual Studio 1998 Debug */

void ___multtenpow12(int *arg_1,uint32_t arg_2,int event_type)

{
  uint32_t uval_1;
  uint16_t target_idx;
  int32_t uStack_16;
  int16_t uStack_12;
  int32_t card_idx;
  uint16_t *match_count;
  uint8_t *slot_idx;
  
  slot_idx = &DAT_0050a888;
  if (arg_2 != 0) {
    if ((int)arg_2 < 0) {
      arg_2 = -arg_2;
      slot_idx = &DAT_0050a9e8;
    }
    uStack_16 = CONCAT22(uStack_16._2_2_,(int16_t)uStack_16);
    if (arg_3 == 0) {
      *(int16_t *)arg_1 = 0;
      uStack_16 = CONCAT22(uStack_16._2_2_,(int16_t)uStack_16);
    }
    while (arg_2 != 0) {
      slot_idx = slot_idx + 0x54;
      uval_1 = arg_2 & 7;
      arg_2 = (int)arg_2 >> 3;
      if (uval_1 != 0) {
        match_count = (uint16_t *)(slot_idx + uval_1 * 0xc);
        if (0x7fff < *match_count) {
          target_idx = (uint16_t)*(int32_t *)match_count;
          uStack_16._0_2_ = (int16_t)((uint32_t)*(int32_t *)match_count >> 0x10);
          uStack_16._2_2_ = (int16_t)*(int32_t *)(match_count + 2);
          uStack_12 = (int16_t)((uint32_t)*(int32_t *)(match_count + 2) >> 0x10);
          card_idx = *(int32_t *)(match_count + 4);
          uStack_16 = CONCAT22(uStack_16._2_2_,(int16_t)uStack_16) + -1;
          match_count = &target_idx;
        }
        ___ld12mul(arg_1,(int *)match_count);
      }
    }
  }
  return;
}



