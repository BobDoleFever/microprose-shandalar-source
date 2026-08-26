/*
 * osfinfo.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 6
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __alloc_osfhnd
 * Entry Point: 004e5a50
 * Size: 333 bytes
 */


/* Library Function - Single Match
    __alloc_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __alloc_osfhnd(void)

{
  int card_idx;
  int match_count;
  int32_t *slot_idx;
  
  match_count = -1;
  card_idx = 0;
  do {
    if (0x3f < card_idx) {
      return match_count;
    }
    if ((&DAT_006c1b90)[card_idx] == 0) {
      slot_idx = (int32_t *)__malloc_dbg(0x100,2,"osfinfo.c",0x79);
      if (slot_idx == (int32_t *)0x0) {
        return match_count;
      }
      (&DAT_006c1b90)[card_idx] = slot_idx;
      DAT_006c1c90 = DAT_006c1c90 + 0x20;
      for (; slot_idx < (int32_t *)((&DAT_006c1b90)[card_idx] + 0x100); slot_idx = slot_idx + 2) {
        *(uint8_t *)(slot_idx + 1) = 0;
        *slot_idx = 0xffffffff;
        *(uint8_t *)((int)slot_idx + 5) = 10;
      }
      return card_idx << 5;
    }
    for (slot_idx = (int32_t *)(&DAT_006c1b90)[card_idx];
        slot_idx < (int32_t *)((&DAT_006c1b90)[card_idx] + 0x100); slot_idx = slot_idx + 2) {
      if ((*(uint8_t *)(slot_idx + 1) & 1) == 0) {
        *slot_idx = 0xffffffff;
        match_count = ((int)slot_idx - (&DAT_006c1b90)[card_idx] >> 3) + card_idx * 0x20;
        break;
      }
    }
    if (match_count != -1) {
      return match_count;
    }
    card_idx = card_idx + 1;
  } while( true );
}



/*
 * Decompiled function: __set_osfhnd
 * Entry Point: 004e5ba0
 * Size: 234 bytes
 */


/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __set_osfhnd(int arg1,intptr_t arg2)

{
  int val_1;
  
  if (((uint32_t)arg1 < DAT_006c1c90) &&
     (*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + (arg1 & 0x1fU) * 8)
      == -1)) {
    if (DAT_005096ec == 1) {
      if (arg1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)arg2);
      }
      else if (arg1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)arg2);
      }
      else if (arg1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)arg2);
      }
    }
    *(intptr_t *)
     (*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + (arg1 & 0x1fU) * 8) = arg2;
    val_1 = 0;
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    val_1 = -1;
  }
  return val_1;
}



/*
 * Decompiled function: __free_osfhnd
 * Entry Point: 004e5ca0
 * Size: 263 bytes
 */


/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __free_osfhnd(int player_id)

{
  int val_1;
  
  if ((((uint32_t)arg_1 < DAT_006c1c90) &&
      ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) & 1) != 0)) &&
     (*(int *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
              (arg_1 & 0x1fU) * 8) != -1)) {
    if (DAT_005096ec == 1) {
      if (arg_1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)0x0);
      }
      else if (arg_1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)0x0);
      }
      else if (arg_1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)0x0);
      }
    }
    *(int32_t *)
     (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + (arg_1 & 0x1fU) * 8) =
         0xffffffff;
    val_1 = 0;
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    val_1 = -1;
  }
  return val_1;
}



/*
 * Decompiled function: __get_osfhandle
 * Entry Point: 004e5dc0
 * Size: 118 bytes
 */


/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Debug */

intptr_t __cdecl __get_osfhandle(int player_id)

{
  intptr_t val_1;
  
  if (((uint32_t)arg_1 < DAT_006c1c90) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    val_1 = *(intptr_t *)
             (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + (arg_1 & 0x1fU) * 8
             );
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    val_1 = -1;
  }
  return val_1;
}



/*
 * Decompiled function: __open_osfhandle
 * Entry Point: 004e5e40
 * Size: 256 bytes
 */


/* Library Function - Single Match
    __open_osfhandle
   
   Library: Visual Studio 1998 Debug */

int __cdecl __open_osfhandle(intptr_t arg1,int arg2)

{
  DWORD DVar1;
  uint32_t arg1_00;
  uint8_t card_idx;
  
  card_idx = 0;
  if ((arg2 & 8U) != 0) {
    card_idx = 0x20;
  }
  if ((arg2 & 0x4000U) != 0) {
    card_idx = card_idx | 0x80;
  }
  DVar1 = GetFileType((HANDLE)arg1);
  if (DVar1 == 0) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
    arg1_00 = 0xffffffff;
  }
  else {
    if (DVar1 == 2) {
      card_idx = card_idx | 0x40;
    }
    else if (DVar1 == 3) {
      card_idx = card_idx | 8;
    }
    arg1_00 = __alloc_osfhnd();
    if (arg1_00 == 0xffffffff) {
      DAT_00509420 = 0x18;
      DAT_00509424 = 0;
      arg1_00 = 0xffffffff;
    }
    else {
      __set_osfhnd(arg1_00,arg1);
      *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1_00 & 0xffffffe0) >> 3)) + 4 +
               (arg1_00 & 0x1f) * 8) = card_idx | 1;
    }
  }
  return arg1_00;
}



/*
 * Decompiled function: __write
 * Entry Point: 004e5f40
 * Size: 744 bytes
 */


/* Library Function - Single Match
    __write
   
   Library: Visual Studio 1998 Debug */

int __cdecl __write(int player_id,void *ptr_2,uint32_t arg_3)

{
  char cVar1;
  BOOL BVar2;
  int local_424;
  DWORD local_41c;
  char local_418 [1028];
  DWORD player_idx;
  uint32_t card_idx;
  char *match_count;
  char *slot_idx;
  
  if (((uint32_t)arg_1 < DAT_006c1c90) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    player_idx = 0;
    local_424 = 0;
    if (arg_3 == 0) {
      local_424 = 0;
    }
    else {
      if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg_1 & 0x1fU) * 8) & 0x20) != 0) {
        __lseek(arg_1,0,2);
      }
      if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg_1 & 0x1fU) * 8) & 0x80) == 0) {
        BVar2 = WriteFile(*(HANDLE *)
                           (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                           (arg_1 & 0x1fU) * 8),ptr_2,arg_3,&local_41c,(LPOVERLAPPED)0x0);
        if (BVar2 == 0) {
          card_idx = GetLastError();
        }
        else {
          card_idx = 0;
          player_idx = local_41c;
        }
      }
      else {
        slot_idx = ptr_2;
        card_idx = 0;
        do {
          if (arg_3 <= (uint32_t)((int)slot_idx - (int)ptr_2)) break;
          match_count = local_418;
          while (((int)match_count - (int)local_418 < 0x400 &&
                 ((uint32_t)((int)slot_idx - (int)ptr_2) < arg_3))) {
            cVar1 = *slot_idx;
            slot_idx = slot_idx + 1;
            if (cVar1 == '\n') {
              local_424 = local_424 + 1;
              *match_count = '\r';
              match_count = match_count + 1;
            }
            *match_count = cVar1;
            match_count = match_count + 1;
          }
          BVar2 = WriteFile(*(HANDLE *)
                             (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                             (arg_1 & 0x1fU) * 8),local_418,(int)match_count - (int)local_418,&local_41c
                            ,(LPOVERLAPPED)0x0);
          if (BVar2 == 0) {
            card_idx = GetLastError();
            break;
          }
          player_idx = player_idx + local_41c;
        } while ((int)match_count - (int)local_418 <= (int)local_41c);
      }
      if (player_idx == 0) {
        if (card_idx == 0) {
          if (((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                         (arg_1 & 0x1fU) * 8) & 0x40) == 0) || (*(char *)ptr_2 != '\x1a')) {
            DAT_00509420 = 0x1c;
            DAT_00509424 = 0;
            local_424 = -1;
          }
          else {
            local_424 = 0;
          }
        }
        else {
          if (card_idx == 5) {
            DAT_00509420 = 9;
            DAT_00509424 = card_idx;
          }
          else {
            __dosmaperr(card_idx);
          }
          local_424 = -1;
        }
      }
      else {
        local_424 = player_idx - local_424;
      }
    }
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    local_424 = -1;
  }
  return local_424;
}



