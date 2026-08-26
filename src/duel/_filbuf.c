/*
 * _filbuf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __filbuf
 * Entry Point: 004e1730
 * Size: 479 bytes
 */


/* Library Function - Single Match
    __filbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __filbuf(FILE *fp)

{
  uint8_t *pbVar1;
  code *char_ptr_2;
  int val_3;
  uint32_t uval_4;
  uint8_t *match_count;
  
  if (fp == (FILE *)0x0) {
    val_3 = __CrtDbgReport(2,0x4f0e64,0x69,0,"str != NULL");
    if (val_3 == 1) {
      char_ptr_2 = (code *)swi(3);
      val_3 = (*char_ptr_2)();
      return val_3;
    }
  }
  if (((fp->_flag & 0x83) == 0) || ((fp->_flag & 0x40) != 0)) {
    uval_4 = 0xffffffff;
  }
  else if ((fp->_flag & 2) == 0) {
    fp->_flag = fp->_flag | 1;
    if ((fp->_flag & 0x10cU) == 0) {
      __getbuf(fp);
    }
    else {
      fp->_ptr = fp->_base;
    }
    val_3 = __read(fp->_file,fp->_base,fp->_bufsiz);
    fp->_cnt = val_3;
    if ((fp->_cnt == 0) || (fp->_cnt == -1)) {
      if (fp->_cnt == 0) {
        fp->_flag = fp->_flag | 0x10;
      }
      else {
        fp->_flag = fp->_flag | 0x20;
      }
      fp->_cnt = 0;
      uval_4 = 0xffffffff;
    }
    else {
      if ((fp->_flag & 0x82) == 0) {
        if (fp->_file == -1) {
          match_count = &DAT_0050a590;
        }
        else {
          match_count = (uint8_t *)
                    (*(int *)((int)&DAT_006c1b90 + ((int)(fp->_file & 0xffffffe0U) >> 3)) +
                    (fp->_file & 0x1fU) * 8);
        }
        if ((match_count[4] & 0x82) == 0x82) {
          fp->_flag = fp->_flag | 0x2000;
        }
      }
      if (((fp->_bufsiz == 0x200) && ((fp->_flag & 8) != 0)) && ((fp->_flag & 0x400) == 0)) {
        fp->_bufsiz = 0x1000;
      }
      fp->_cnt = fp->_cnt + -1;
      pbVar1 = (uint8_t *)fp->_ptr;
      fp->_ptr = fp->_ptr + 1;
      uval_4 = (uint32_t)*pbVar1;
    }
  }
  else {
    fp->_flag = fp->_flag | 0x20;
    uval_4 = 0xffffffff;
  }
  return uval_4;
}



/*
 * Decompiled function: Mem_AllocOrFree_004e1910
 * Entry Point: 004e1910
 * Size: 38 bytes
 */


int32_t Mem_AllocOrFree_004e1910(int32_t arg_1)

{
  int32_t uval_1;
  
  uval_1 = DAT_005edaf0;
  DAT_005edaf0 = arg_1;
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_004e1940
 * Entry Point: 004e1940
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_004e1940(void)

{
  return DAT_005edaf0;
}



/*
 * Decompiled function: __callnewh
 * Entry Point: 004e1960
 * Size: 62 bytes
 */


/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Debug */

int __cdecl __callnewh(size_t arg_1)

{
  int val_1;
  
  if ((DAT_005edaf0 != (code *)0x0) && (val_1 = (*DAT_005edaf0)(arg_1), val_1 != 0)) {
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: __malloc_base
 * Entry Point: 004e19a0
 * Size: 34 bytes
 */


/* Library Function - Single Match
    __malloc_base
   
   Library: Visual Studio 1998 Debug */

void __malloc_base(uint32_t arg_1)

{
  __nh_malloc_base(arg_1,DAT_005099d4);
  return;
}



/*
 * Decompiled function: __nh_malloc_base
 * Entry Point: 004e19d0
 * Size: 150 bytes
 */


/* Library Function - Single Match
    __nh_malloc_base
   
   Library: Visual Studio 1998 Debug */

int __nh_malloc_base(uint32_t arg1,int arg2)

{
  int val_1;
  int slot_idx;
  
  if (arg1 < 0xffffffe1) {
    if (arg1 == 0) {
      arg1 = 1;
    }
    do {
      if (arg1 < 0xffffffe1) {
        slot_idx = __heap_alloc_base(arg1);
      }
      else {
        slot_idx = 0;
      }
      if (slot_idx != 0) {
        return slot_idx;
      }
      if (arg2 == 0) {
        return 0;
      }
      val_1 = __callnewh(arg1);
    } while (val_1 != 0);
  }
  return 0;
}



/*
 * Decompiled function: __heap_alloc_base
 * Entry Point: 004e1a70
 * Size: 99 bytes
 */


/* Library Function - Single Match
    __heap_alloc_base
   
   Library: Visual Studio 1998 Debug */

LPVOID __heap_alloc_base(int player_id)

{
  uint32_t dwBytes;
  LPVOID buf_ptr_1;
  
  dwBytes = arg_1 + 0xfU & 0xfffffff0;
  if ((DAT_0050a1fc < dwBytes) ||
     (buf_ptr_1 = (LPVOID)___sbh_alloc_block(arg_1 + 0xfU >> 4), buf_ptr_1 == (LPVOID)0x0)) {
    buf_ptr_1 = HeapAlloc(DAT_006c1c94,0,dwBytes);
  }
  return buf_ptr_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_004e1ae0
 * Entry Point: 004e1ae0
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_004e1ae0(void)

{
  return 1;
}



/*
 * Decompiled function: __expand_base
 * Entry Point: 004e1b00
 * Size: 195 bytes
 */


/* Library Function - Single Match
    __expand_base
   
   Library: Visual Studio 1998 Debug */

LPVOID __expand_base(LPVOID arg1,uint32_t arg2)

{
  int val_1;
  int player_idx;
  uint8_t *card_idx;
  LPVOID match_count;
  int32_t *slot_idx;
  
  if (arg2 < 0xffffffe1) {
    if (arg2 == 0) {
      arg2 = 0x10;
    }
    else {
      arg2 = arg2 + 0xf & 0xfffffff0;
    }
    card_idx = (uint8_t *)___sbh_find_block(arg1,&player_idx,(uint32_t *)&slot_idx);
    if (card_idx == (uint8_t *)0x0) {
      match_count = HeapReAlloc(DAT_006c1c94,0x10,arg1,arg2);
    }
    else {
      match_count = (LPVOID)0x0;
      if ((arg2 <= DAT_0050a1fc) &&
         (val_1 = ___sbh_resize_block(player_idx,slot_idx,card_idx,arg2 >> 4), val_1 != 0)) {
        match_count = arg1;
      }
    }
  }
  else {
    match_count = (LPVOID)0x0;
  }
  return match_count;
}



/*
 * Decompiled function: __realloc_base
 * Entry Point: 004e1bd0
 * Size: 518 bytes
 */


/* Library Function - Single Match
    __realloc_base
   
   Library: Visual Studio 1998 Debug */

void * __realloc_base(void *arg1,uint32_t arg2)

{
  void *buf_ptr_1;
  int val_2;
  uint32_t uval_3;
  int target_idx;
  uint32_t player_idx;
  uint8_t *card_idx;
  void *match_count;
  int32_t *slot_idx;
  
  if (arg1 == (void *)0x0) {
    buf_ptr_1 = (void *)__malloc_base(arg2);
  }
  else if (arg2 == 0) {
    __free_base(arg1);
    buf_ptr_1 = (void *)0x0;
  }
  else {
    if (arg2 < 0xffffffe1) {
      if (arg2 == 0) {
        arg2 = 0x10;
      }
      else {
        arg2 = arg2 + 0xf & 0xfffffff0;
      }
    }
    do {
      match_count = (void *)0x0;
      if (arg2 < 0xffffffe1) {
        card_idx = (uint8_t *)___sbh_find_block(arg1,&target_idx,(uint32_t *)&slot_idx);
        if (card_idx == (uint8_t *)0x0) {
          match_count = HeapReAlloc(DAT_006c1c94,0,arg1,arg2);
        }
        else {
          if (arg2 < DAT_0050a1fc) {
            val_2 = ___sbh_resize_block(target_idx,slot_idx,card_idx,arg2 >> 4);
            if (val_2 == 0) {
              match_count = (void *)___sbh_alloc_block(arg2 >> 4);
              if (match_count != (void *)0x0) {
                player_idx = (uint32_t)*card_idx << 4;
                uval_3 = arg2;
                if (player_idx <= arg2) {
                  uval_3 = player_idx;
                }
                FID_conflict__memcpy(match_count,arg1,uval_3);
                ___sbh_free_block(target_idx,(int)slot_idx,(char *)card_idx);
              }
            }
            else {
              match_count = arg1;
            }
          }
          if ((match_count == (void *)0x0) &&
             (match_count = HeapAlloc(DAT_006c1c94,0,arg2), match_count != (LPVOID)0x0)) {
            player_idx = (uint32_t)*card_idx << 4;
            uval_3 = arg2;
            if (player_idx <= arg2) {
              uval_3 = player_idx;
            }
            FID_conflict__memcpy(match_count,arg1,uval_3);
            ___sbh_free_block(target_idx,(int)slot_idx,(char *)card_idx);
          }
        }
      }
      if (match_count != (void *)0x0) {
        return match_count;
      }
      if (DAT_005099d4 == 0) {
        return (void *)0x0;
      }
      val_2 = __callnewh(arg2);
    } while (val_2 != 0);
    buf_ptr_1 = (void *)0x0;
  }
  return buf_ptr_1;
}



/*
 * Decompiled function: __free_base
 * Entry Point: 004e1de0
 * Size: 105 bytes
 */


/* Library Function - Single Match
    __free_base
   
   Library: Visual Studio 1998 Debug */

void __free_base(LPVOID arg_1)

{
  int card_idx;
  char *match_count;
  uint32_t slot_idx;
  
  if (arg_1 != (LPVOID)0x0) {
    match_count = (char *)___sbh_find_block(arg_1,&card_idx,&slot_idx);
    if (match_count == (char *)0x0) {
      HeapFree(DAT_006c1c94,0,arg_1);
    }
    else {
      ___sbh_free_block(card_idx,slot_idx,match_count);
    }
  }
  return;
}



/*
 * Decompiled function: __heapchk
 * Entry Point: 004e1e50
 * Size: 120 bytes
 */


/* Library Function - Single Match
    __heapchk
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heapchk(void)

{
  int val_1;
  BOOL BVar2;
  DWORD DVar3;
  int32_t slot_idx;
  
  slot_idx = -2;
  val_1 = ___sbh_heap_check();
  if (val_1 < 0) {
    slot_idx = -4;
  }
  BVar2 = HeapValidate(DAT_006c1c94,0,(LPCVOID)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      DAT_00509424 = 0x78;
      DAT_00509420 = 0x28;
    }
    else {
      slot_idx = -4;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: __heapset
 * Entry Point: 004e1ed0
 * Size: 21 bytes
 */


/* Library Function - Single Match
    __heapset
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heapset(uint32_t arg_1)

{
  int val_1;
  
  val_1 = __heapchk();
  return val_1;
}



/*
 * Decompiled function: __heap_init
 * Entry Point: 004e1ef0
 * Size: 93 bytes
 */


/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heap_init(void)

{
  int val_1;
  
  DAT_006c1c94 = HeapCreate(1,0x1000,0);
  if (DAT_006c1c94 == (HANDLE)0x0) {
    val_1 = 0;
  }
  else {
    val_1 = ___sbh_new_region();
    if (val_1 == 0) {
      HeapDestroy(DAT_006c1c94);
      val_1 = 0;
    }
    else {
      val_1 = 1;
    }
  }
  return val_1;
}



/*
 * Decompiled function: __heap_term
 * Entry Point: 004e1f50
 * Size: 93 bytes
 */


/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 1998 Debug */

void __cdecl __heap_term(void)

{
  uint8_t **slot_idx;
  
  slot_idx = &PTR_LOOP_005099e0;
  do {
    if (slot_idx[0x204] != (uint8_t *)0x0) {
      VirtualFree(slot_idx[0x204],0,0x8000);
    }
    slot_idx = (uint8_t **)*slot_idx;
  } while (slot_idx != &PTR_LOOP_005099e0);
  HeapDestroy(DAT_006c1c94);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004e1fb0
 * Entry Point: 004e1fb0
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_004e1fb0(void)

{
  return DAT_0050a1fc;
}



/*
 * Decompiled function: __set_sbh_threshold
 * Entry Point: 004e1fd0
 * Size: 61 bytes
 */


/* Library Function - Single Match
    __set_sbh_threshold
   
   Library: Visual Studio 1998 Debug */

bool __set_sbh_threshold(int player_id)

{
  uint32_t uval_1;
  
  uval_1 = arg_1 + 0xfU & 0xfffffff0;
  if (uval_1 < 0x781) {
    DAT_0050a1fc = uval_1;
  }
  return uval_1 < 0x781;
}



/*
 * Decompiled function: ___sbh_new_region
 * Entry Point: 004e2020
 * Size: 508 bytes
 */


/* Library Function - Single Match
    ___sbh_new_region
   
   Library: Visual Studio 1998 Debug */

uint8_t ** ___sbh_new_region(void)

{
  LPVOID buf_ptr_1;
  uint8_t **card_idx;
  int match_count;
  int32_t *slot_idx;
  
  if (DAT_0050a1f0 == 0) {
    card_idx = &PTR_LOOP_005099e0;
  }
  else {
    card_idx = HeapAlloc(DAT_006c1c94,0,0x814);
    if (card_idx == (uint8_t **)0x0) {
      return (uint8_t **)0x0;
    }
  }
  slot_idx = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (slot_idx != (int32_t *)0x0) {
    buf_ptr_1 = VirtualAlloc(slot_idx,0x10000,0x1000,4);
    if (buf_ptr_1 != (LPVOID)0x0) {
      if (card_idx == &PTR_LOOP_005099e0) {
        if (PTR_LOOP_005099e0 == (uint8_t *)0x0) {
          PTR_LOOP_005099e0 = (uint8_t *)&PTR_LOOP_005099e0;
        }
        if (PTR_LOOP_005099e4 == (uint8_t *)0x0) {
          PTR_LOOP_005099e4 = (uint8_t *)&PTR_LOOP_005099e0;
        }
      }
      else {
        *card_idx = (uint8_t *)&PTR_LOOP_005099e0;
        card_idx[1] = PTR_LOOP_005099e4;
        PTR_LOOP_005099e4 = (uint8_t *)card_idx;
        *(uint8_t ***)card_idx[1] = card_idx;
      }
      card_idx[0x204] = (uint8_t *)slot_idx;
      card_idx[2] = (uint8_t *)0x0;
      card_idx[3] = (uint8_t *)0x10;
      for (match_count = 0; match_count < 0x400; match_count = match_count + 1) {
        if (match_count < 0x10) {
          *(uint8_t *)(match_count + 0x10 + (int)card_idx) = 0xf0;
        }
        else {
          *(uint8_t *)(match_count + 0x10 + (int)card_idx) = 0xff;
        }
        *(uint8_t *)(match_count + 0x410 + (int)card_idx) = 0xf1;
      }
      _memset(slot_idx,0,0x10000);
      for (; slot_idx < card_idx[0x204] + 0x10000; slot_idx = slot_idx + 0x400) {
        *slot_idx = slot_idx + 2;
        slot_idx[1] = 0xf0;
        *(uint8_t *)(slot_idx + 0x3e) = 0xff;
      }
      return card_idx;
    }
    VirtualFree(slot_idx,0,0x8000);
  }
  if (card_idx != &PTR_LOOP_005099e0) {
    HeapFree(DAT_006c1c94,0,card_idx);
  }
  return (uint8_t **)0x0;
}



/*
 * Decompiled function: ___sbh_release_region
 * Entry Point: 004e2230
 * Size: 132 bytes
 */


/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Debug */

void ___sbh_release_region(uint8_t **arg_1)

{
  VirtualFree(arg_1[0x204],0,0x8000);
  if (arg_1 == (uint8_t **)PTR_LOOP_0050a1f4) {
    PTR_LOOP_0050a1f4 = arg_1[1];
  }
  if (arg_1 == &PTR_LOOP_005099e0) {
    DAT_0050a1f0 = 0;
  }
  else {
    *(uint8_t **)arg_1[1] = *arg_1;
    *(uint8_t **)(*arg_1 + 4) = arg_1[1];
    HeapFree(DAT_006c1c94,0,arg_1);
  }
  return;
}



/*
 * Decompiled function: ___sbh_decommit_pages
 * Entry Point: 004e22c0
 * Size: 376 bytes
 */


/* Library Function - Single Match
    ___sbh_decommit_pages
   
   Library: Visual Studio 1998 Debug */

void ___sbh_decommit_pages(int player_id)

{
  uint8_t **ppuVar1;
  BOOL BVar2;
  uint8_t **target_idx;
  int player_idx;
  uint8_t *card_idx;
  char *match_count;
  
  target_idx = (uint8_t **)PTR_LOOP_005099e4;
  do {
    ppuVar1 = target_idx;
    if (target_idx[0x204] != (uint8_t *)0x0) {
      player_idx = 0;
      match_count = (char *)((int)target_idx + 0x40f);
      for (card_idx = (uint8_t *)0x3ff; -1 < (int)card_idx; card_idx = card_idx + -1) {
        if ((*match_count == -0x10) &&
           (BVar2 = VirtualFree(target_idx[0x204] + (int)card_idx * 0x1000,0x1000,0x4000), BVar2 != 0)
           ) {
          *match_count = -1;
          DAT_0050a1f8 = DAT_0050a1f8 + -1;
          if ((target_idx[3] == (uint8_t *)0xffffffff) || ((int)card_idx < (int)target_idx[3])) {
            target_idx[3] = card_idx;
          }
          player_idx = player_idx + 1;
          arg_1 = arg_1 + -1;
          if (arg_1 == 0) break;
        }
        match_count = match_count + -1;
      }
      ppuVar1 = (uint8_t **)target_idx[1];
      if ((player_idx != 0) && (*(char *)(target_idx + 4) == -1)) {
        card_idx = (uint8_t *)0x1;
        for (match_count = (char *)((int)target_idx + 0x11); ((int)card_idx < 0x400 && (*match_count == -1));
            match_count = match_count + 1) {
          card_idx = (uint8_t *)((int)card_idx + 1);
        }
        if (card_idx == (uint8_t *)0x400) {
          ___sbh_release_region(target_idx);
        }
      }
    }
    target_idx = ppuVar1;
    if (((uint8_t **)PTR_LOOP_005099e4 == target_idx) || (arg_1 < 1)) {
      return;
    }
  } while( true );
}



/*
 * Decompiled function: ___sbh_find_block
 * Entry Point: 004e2440
 * Size: 162 bytes
 */


/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Debug */

int ___sbh_find_block(uint8_t *arg_1,int32_t *arg_2,uint32_t *arg_3)

{
  uint32_t uval_1;
  uint8_t **match_count;
  
  match_count = &PTR_LOOP_005099e0;
  while (((match_count[0x204] == (uint8_t *)0x0 || (arg_1 <= match_count[0x204])) ||
         (match_count[0x204] + 0x400000 <= arg_1))) {
    match_count = (uint8_t **)*match_count;
    if (match_count == &PTR_LOOP_005099e0) {
      return 0;
    }
  }
  *arg_2 = match_count;
  uval_1 = (uint32_t)arg_1 & 0xfffff000;
  *arg_3 = uval_1;
  return ((int)((int)arg_1 - (uval_1 + 0x100)) >> 4) + 8 + uval_1;
}



/*
 * Decompiled function: ___sbh_free_block
 * Entry Point: 004e24f0
 * Size: 136 bytes
 */


/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Debug */

void ___sbh_free_block(int player_id,int card_slot,char *str_3)

{
  int val_1;
  
  val_1 = arg_2 - *(int *)(arg_1 + 0x810) >> 0xc;
  *(char *)(val_1 + 0x10 + arg_1) = *(char *)(val_1 + 0x10 + arg_1) + *str_3;
  *str_3 = '\0';
  *(uint8_t *)(val_1 + 0x410 + arg_1) = 0xf1;
  if ((*(char *)(val_1 + 0x10 + arg_1) == -0x10) &&
     (DAT_0050a1f8 = DAT_0050a1f8 + 1, DAT_0050a1f8 == 0x20)) {
    ___sbh_decommit_pages(0x10);
  }
  return;
}



/*
 * Decompiled function: ___sbh_alloc_block
 * Entry Point: 004e2580
 * Size: 1207 bytes
 */


/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Debug */

uint8_t * ___sbh_alloc_block(uint32_t arg_1)

{
  int *i_ptr_1;
  uint8_t *u_ptr_2;
  uint8_t *u_ptr_3;
  uint8_t *puVar4;
  int32_t *puVar5;
  uint8_t **target_idx;
  uint8_t *player_idx;
  uint8_t *card_idx;
  int32_t *slot_idx;
  
  target_idx = (uint8_t **)PTR_LOOP_0050a1f4;
  do {
    if (target_idx[0x204] != (uint8_t *)0x0) {
      for (card_idx = target_idx[2]; (int)card_idx < 0x400;
          card_idx = (uint8_t *)((int)card_idx + 1)) {
        if (((arg_1 <= *(uint8_t *)((int)card_idx + 0x10 + (int)target_idx)) &&
            (*(char *)((int)card_idx + 0x10 + (int)target_idx) != -1)) &&
           (arg_1 < *(uint8_t *)((int)card_idx + 0x410 + (int)target_idx))) {
          u_ptr_2 = (uint8_t *)
                   ___sbh_alloc_block_from_page
                             ((int *)((int)target_idx[0x204] + (int)card_idx * 0x1000),
                              (uint32_t)*(uint8_t *)((int)card_idx + 0x10 + (int)target_idx),arg_1);
          if (u_ptr_2 != (uint8_t *)0x0) {
            PTR_LOOP_0050a1f4 = (uint8_t *)target_idx;
            *(char *)((int)card_idx + 0x10 + (int)target_idx) =
                 *(char *)((int)card_idx + 0x10 + (int)target_idx) - (char)arg_1;
            target_idx[2] = card_idx;
            return u_ptr_2;
          }
          *(char *)((int)card_idx + 0x410 + (int)target_idx) = (char)arg_1;
        }
      }
      for (card_idx = (uint8_t *)0x0; (int)card_idx < (int)target_idx[2];
          card_idx = (uint8_t *)((int)card_idx + 1)) {
        if (((arg_1 <= *(uint8_t *)((int)card_idx + 0x10 + (int)target_idx)) &&
            (*(char *)((int)card_idx + 0x10 + (int)target_idx) != -1)) &&
           (arg_1 < *(uint8_t *)((int)card_idx + 0x410 + (int)target_idx))) {
          u_ptr_2 = (uint8_t *)
                   ___sbh_alloc_block_from_page
                             ((int *)((int)target_idx[0x204] + (int)card_idx * 0x1000),
                              (uint32_t)*(uint8_t *)((int)card_idx + 0x10 + (int)target_idx),arg_1);
          if (u_ptr_2 != (uint8_t *)0x0) {
            PTR_LOOP_0050a1f4 = (uint8_t *)target_idx;
            *(char *)((int)card_idx + 0x10 + (int)target_idx) =
                 *(char *)((int)card_idx + 0x10 + (int)target_idx) - (char)arg_1;
            target_idx[2] = card_idx;
            return u_ptr_2;
          }
          *(char *)((int)card_idx + 0x410 + (int)target_idx) = (char)arg_1;
        }
      }
    }
    target_idx = (uint8_t **)*target_idx;
  } while (target_idx != (uint8_t **)PTR_LOOP_0050a1f4);
  target_idx = &PTR_LOOP_005099e0;
  while ((target_idx[0x204] == (uint8_t *)0x0 || (target_idx[3] == (uint8_t *)0xffffffff))) {
    target_idx = (uint8_t **)*target_idx;
    if (target_idx == &PTR_LOOP_005099e0) {
      u_ptr_2 = (uint8_t *)___sbh_new_region();
      if (u_ptr_2 != (uint8_t *)0x0) {
        i_ptr_1 = *(int **)(u_ptr_2 + 0x810);
        *(char *)(i_ptr_1 + 2) = (char)arg_1;
        PTR_LOOP_0050a1f4 = u_ptr_2;
        *i_ptr_1 = (int)i_ptr_1 + arg_1 + 8;
        i_ptr_1[1] = 0xf0 - arg_1;
        u_ptr_2[0x10] = u_ptr_2[0x10] - (char)arg_1;
        return (uint8_t *)(*(int *)(u_ptr_2 + 0x810) + 0x100);
      }
      return (uint8_t *)0x0;
    }
  }
  u_ptr_2 = target_idx[3];
  u_ptr_3 = u_ptr_2 + 0x10;
  if (0x3ff < (int)u_ptr_3) {
    u_ptr_3 = (uint8_t *)0x400;
  }
  do {
    card_idx = u_ptr_2 + 1;
    if ((int)u_ptr_3 <= (int)card_idx) break;
    puVar4 = u_ptr_2 + 0x11;
    u_ptr_2 = card_idx;
  } while (puVar4[(int)target_idx] == -1);
  u_ptr_2 = target_idx[3];
  u_ptr_3 = target_idx[0x204];
  puVar4 = VirtualAlloc(target_idx[0x204] + (int)target_idx[3] * 0x1000,
                        ((int)card_idx - (int)target_idx[3]) * 0x1000,0x1000,4);
  if (u_ptr_3 + (int)u_ptr_2 * 0x1000 == puVar4) {
    player_idx = target_idx[3];
    slot_idx = (int32_t *)(target_idx[0x204] + (int)player_idx * 0x1000);
    for (; (int)player_idx < (int)card_idx; player_idx = player_idx + 1) {
      _memset(slot_idx,0x1000,0);
      *slot_idx = slot_idx + 2;
      slot_idx[1] = 0xf0;
      *(uint8_t *)(slot_idx + 0x3e) = 0xff;
      (player_idx + 0x10)[(int)target_idx] = 0xf0;
      (player_idx + 0x410)[(int)target_idx] = 0xf1;
      slot_idx = slot_idx + 0x400;
    }
    PTR_LOOP_0050a1f4 = (uint8_t *)target_idx;
    for (; ((int)card_idx < 0x400 && ((card_idx + 0x10)[(int)target_idx] != -1));
        card_idx = card_idx + 1) {
    }
    u_ptr_2 = target_idx[3];
    if ((int)card_idx < 0x400) {
      target_idx[3] = card_idx;
    }
    else {
      target_idx[3] = (uint8_t *)0xffffffff;
    }
    puVar5 = (int32_t *)(target_idx[0x204] + (int)u_ptr_2 * 0x1000);
    *(char *)(puVar5 + 2) = (char)arg_1;
    target_idx[2] = u_ptr_2;
    (u_ptr_2 + 0x10)[(int)target_idx] = (u_ptr_2 + 0x10)[(int)target_idx] - (char)arg_1;
    *puVar5 = (uint8_t *)((int)puVar5 + arg_1 + 8);
    puVar5[1] = puVar5[1] - arg_1;
    u_ptr_2 = target_idx[0x204] + (int)u_ptr_2 * 0x1000 + 0x100;
  }
  else {
    u_ptr_2 = (uint8_t *)0x0;
  }
  return u_ptr_2;
}



/*
 * Decompiled function: ___sbh_alloc_block_from_page
 * Entry Point: 004e2a50
 * Size: 763 bytes
 */


/* Library Function - Single Match
    ___sbh_alloc_block_from_page
   
   Library: Visual Studio 1998 Debug */

int ___sbh_alloc_block_from_page(int *arg_1,uint32_t arg_2,uint32_t arg_3)

{
  uint8_t *pbVar1;
  int val_2;
  uint32_t player_idx;
  uint8_t *card_idx;
  uint8_t *match_count;
  
  pbVar1 = (uint8_t *)*arg_1;
  if ((uint32_t)arg_1[1] < arg_3) {
    match_count = pbVar1;
    if (pbVar1[arg_1[1]] != 0) {
      match_count = pbVar1 + arg_1[1];
    }
    while (match_count + arg_3 < arg_1 + 0x3e) {
      if (*match_count == 0) {
        player_idx = 1;
        card_idx = match_count;
        while (card_idx = card_idx + 1, *card_idx == 0) {
          player_idx = player_idx + 1;
        }
        if (arg_3 <= player_idx) {
          if (match_count + arg_3 < arg_1 + 0x3e) {
            *arg_1 = (int)(match_count + arg_3);
            arg_1[1] = player_idx - arg_3;
          }
          else {
            *arg_1 = (int)(arg_1 + 2);
            arg_1[1] = 0;
          }
          *match_count = (uint8_t)arg_3;
          return (int)match_count * 0x10 + (int)arg_1 * -0xf + 0x80;
        }
        if (pbVar1 == match_count) {
          arg_1[1] = player_idx;
        }
        else {
          arg_2 = arg_2 - player_idx;
          if (arg_2 < arg_3) {
            return 0;
          }
        }
        match_count = card_idx;
      }
      else {
        match_count = match_count + *match_count;
      }
    }
    match_count = (uint8_t *)(arg_1 + 2);
    while ((match_count < pbVar1 && (match_count + arg_3 <= (uint8_t *)((int)arg_1 + 0xf7)))) {
      if (*match_count == 0) {
        player_idx = 1;
        card_idx = match_count;
        while (card_idx = card_idx + 1, *card_idx == 0) {
          player_idx = player_idx + 1;
        }
        if (arg_3 <= player_idx) {
          if (match_count + arg_3 < arg_1 + 0x3e) {
            *arg_1 = (int)(match_count + arg_3);
            arg_1[1] = player_idx - arg_3;
          }
          else {
            *arg_1 = (int)(arg_1 + 2);
            arg_1[1] = 0;
          }
          *match_count = (uint8_t)arg_3;
          return (int)match_count * 0x10 + (int)arg_1 * -0xf + 0x80;
        }
        arg_2 = arg_2 - player_idx;
        if (arg_2 < arg_3) {
          return 0;
        }
        match_count = card_idx;
      }
      else {
        match_count = match_count + *match_count;
      }
    }
    val_2 = 0;
  }
  else {
    *pbVar1 = (uint8_t)arg_3;
    if (pbVar1 + arg_3 < arg_1 + 0x3e) {
      *arg_1 = *arg_1 + arg_3;
      arg_1[1] = arg_1[1] - arg_3;
    }
    else {
      *arg_1 = (int)(arg_1 + 2);
      arg_1[1] = 0;
    }
    val_2 = (int)pbVar1 * 0x10 + (int)arg_1 * -0xf + 0x80;
  }
  return val_2;
}



/*
 * Decompiled function: ___sbh_resize_block
 * Entry Point: 004e2d50
 * Size: 439 bytes
 */


/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 1998 Debug */

int32_t ___sbh_resize_block(int x,int32_t *arg_2,uint8_t *arg_3,uint32_t height)

{
  uint8_t flag_1;
  uint32_t uval_2;
  uint8_t *target_idx;
  int32_t player_idx;
  uint8_t *card_idx;
  int slot_idx;
  
  player_idx = 0;
  flag_1 = *arg_3;
  uval_2 = (uint32_t)flag_1;
  if (height < uval_2) {
    *arg_3 = (uint8_t)height;
    *(uint8_t *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) =
         (*(char *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) - (uint8_t)height) + flag_1;
    *(uint8_t *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x410 + x) = 0xf1;
    player_idx = 1;
  }
  else if ((uval_2 < height) && (arg_3 + height <= arg_2 + 0x3e)) {
    target_idx = arg_3 + height;
    for (card_idx = arg_3 + uval_2; (card_idx < target_idx && (*card_idx == 0));
        card_idx = card_idx + 1) {
    }
    if (target_idx == card_idx) {
      *arg_3 = (uint8_t)height;
      if ((arg_3 <= (uint8_t *)*arg_2) && ((uint8_t *)*arg_2 < target_idx)) {
        if (target_idx < arg_2 + 0x3e) {
          *arg_2 = target_idx;
          slot_idx = 0;
          for (; *target_idx == 0; target_idx = target_idx + 1) {
            slot_idx = slot_idx + 1;
          }
          arg_2[1] = slot_idx;
        }
        else {
          *arg_2 = arg_2 + 2;
          arg_2[1] = 0;
        }
      }
      *(uint8_t *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) =
           (*(char *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) - (uint8_t)height) + flag_1;
      player_idx = 1;
    }
  }
  return player_idx;
}



/*
 * Decompiled function: ___sbh_heap_check
 * Entry Point: 004e2f10
 * Size: 617 bytes
 */


/* Library Function - Single Match
    ___sbh_heap_check
   
   Library: Visual Studio 1998 Debug */

int32_t ___sbh_heap_check(void)

{
  int val_1;
  int val_2;
  int32_t uval_3;
  int local_2c;
  uint32_t local_28;
  int local_24;
  uint8_t **loop_idx;
  int color_idx;
  int target_idx;
  uint8_t *player_idx;
  int card_idx;
  int match_count;
  int *slot_idx;
  
  match_count = 0;
  loop_idx = &PTR_LOOP_005099e0;
  do {
    if (loop_idx == (uint8_t **)PTR_LOOP_0050a1f4) {
      match_count = match_count + 1;
    }
    if (loop_idx[0x204] != (uint8_t *)0x0) {
      player_idx = (uint8_t *)0x0;
      local_2c = 0;
      slot_idx = (int *)loop_idx[0x204];
      for (; (int)player_idx < 0x400; player_idx = player_idx + 1) {
        if ((player_idx + 0x10)[(int)loop_idx] == -1) {
          if ((local_2c == 0) && (loop_idx[3] != player_idx)) {
            return 0xffffffff;
          }
          local_2c = local_2c + 1;
        }
        else {
          if (slot_idx + 0x3e <= (int *)*slot_idx) {
            return 0xfffffffe;
          }
          if ((char)slot_idx[0x3e] != -1) {
            return 0xfffffffd;
          }
          target_idx = 0;
          card_idx = 0;
          local_28 = 0;
          local_24 = 0;
          while (target_idx < 0xf0) {
            if ((int)slot_idx + target_idx + 8 == *slot_idx) {
              card_idx = card_idx + 1;
            }
            if (*(char *)(target_idx + 8 + (int)slot_idx) == '\0') {
              local_28 = local_28 + 1;
              local_24 = local_24 + 1;
              target_idx = target_idx + 1;
            }
            else {
              if ((int)(uint32_t)(uint8_t)(player_idx + 0x410)[(int)loop_idx] <= local_24) {
                return 0xfffffffc;
              }
              if (card_idx == 1) {
                if (local_24 < slot_idx[1]) {
                  return 0xfffffffb;
                }
                card_idx = 2;
              }
              local_24 = 0;
              val_2 = target_idx;
              while (color_idx = val_2 + 1,
                    color_idx < (int)((uint32_t)*(uint8_t *)(target_idx + 8 + (int)slot_idx) + target_idx)) {
                val_1 = val_2 + 9;
                val_2 = color_idx;
                if (*(char *)(val_1 + (int)slot_idx) != '\0') {
                  return 0xfffffffa;
                }
              }
              target_idx = color_idx;
            }
          }
          if ((uint8_t)(player_idx + 0x10)[(int)loop_idx] != local_28) {
            return 0xfffffff9;
          }
          if (card_idx == 0) {
            return 0xfffffff8;
          }
        }
        slot_idx = slot_idx + 0x400;
      }
    }
    loop_idx = (uint8_t **)*loop_idx;
    if (loop_idx == &PTR_LOOP_005099e0) {
      if (match_count == 0) {
        uval_3 = 0xfffffff7;
      }
      else {
        uval_3 = 0;
      }
      return uval_3;
    }
  } while( true );
}



