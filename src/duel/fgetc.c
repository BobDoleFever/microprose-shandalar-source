/*
 * fgetc.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _fgetc
 * Entry Point: 004dd1f0
 * Size: 126 bytes
 */


/* Library Function - Single Match
    _fgetc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fgetc(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  uint32_t slot_idx;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b20,0x29,0,"stream != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  fp->_cnt = fp->_cnt + -1;
  if (fp->_cnt < 0) {
    slot_idx = __filbuf(fp);
  }
  else {
    slot_idx = (uint32_t)(uint8_t)*fp->_ptr;
    fp->_ptr = fp->_ptr + 1;
  }
  return slot_idx;
}



/*
 * Decompiled function: _getc
 * Entry Point: 004dd270
 * Size: 28 bytes
 */


/* Library Function - Single Match
    _getc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _getc(FILE *fp)

{
  int val_1;
  
  val_1 = _fgetc(fp);
  return val_1;
}



/*
 * Decompiled function: __open
 * Entry Point: 004dd290
 * Size: 67 bytes
 */


/* Library Function - Single Match
    __open
   
   Library: Visual Studio 1998 Debug */

int __cdecl __open(char *filename,int card_slot,...)

{
  int val_1;
  int32_t stack_arg;
  
  val_1 = __sopen(filename,arg_2,0x40,stack_arg);
  return val_1;
}



/*
 * Decompiled function: __sopen
 * Entry Point: 004dd2e0
 * Size: 1355 bytes
 */


/* Library Function - Single Match
    __sopen
   
   Library: Visual Studio 1998 Debug */

int __cdecl __sopen(char *filename,int card_slot,int event_type,...)

{
  uint32_t uval_1;
  DWORD DVar2;
  long lVar3;
  int val_4;
  bool bVar5;
  uint32_t stack_arg;
  uint8_t local_3c;
  uint32_t local_38;
  char local_34 [4];
  int32_t local_30;
  uint32_t local_2c;
  _SECURITY_ATTRIBUTES local_28;
  DWORD color_idx;
  uint32_t target_idx;
  uint32_t player_idx;
  DWORD card_idx;
  DWORD match_count;
  HANDLE slot_idx;
  
  local_28.nLength = 0xc;
  local_28.lpSecurityDescriptor = (LPVOID)0x0;
  bVar5 = (arg_2 & 0x80U) == 0;
  if (bVar5) {
    local_3c = 0;
  }
  else {
    local_3c = 0x10;
  }
  local_28.bInheritHandle = (BOOL)bVar5;
  if ((arg_2 & 0x8000U) == 0) {
    if ((arg_2 & 0x4000U) == 0) {
      if (DAT_0050a598 != 0x8000) {
        local_3c = local_3c | 0x80;
      }
    }
    else {
      local_3c = local_3c | 0x80;
    }
  }
  uval_1 = arg_2 & 3;
  if (uval_1 == 0) {
    local_38 = 0x80000000;
  }
  else if (uval_1 == 1) {
    local_38 = 0x40000000;
  }
  else {
    if (uval_1 != 2) {
      DAT_00509420 = 0x16;
      DAT_00509424 = 0;
      return -1;
    }
    local_38 = 0xc0000000;
  }
  switch(arg_3) {
  case 0x10:
    match_count = 0;
    break;
  default:
    DAT_00509420 = 0x16;
    DAT_00509424 = 0;
    return -1;
  case 0x20:
    match_count = 1;
    break;
  case 0x30:
    match_count = 2;
    break;
  case 0x40:
    match_count = 3;
  }
  uval_1 = arg_2 & 0x700;
  if (uval_1 < 0x101) {
    if (uval_1 == 0x100) {
      color_idx = 4;
      goto LAB_004dd58c;
    }
    if (uval_1 != 0) {
      DAT_00509420 = 0x16;
      DAT_00509424 = 0;
      return -1;
    }
LAB_004dd4a2:
    color_idx = 3;
    goto LAB_004dd58c;
  }
  if (uval_1 < 0x301) {
    if (uval_1 == 0x300) {
      color_idx = 2;
      goto LAB_004dd58c;
    }
    if (uval_1 != 0x200) {
      DAT_00509420 = 0x16;
      DAT_00509424 = 0;
      return -1;
    }
LAB_004dd4c6:
    color_idx = 5;
  }
  else {
    if (uval_1 < 0x501) {
      if (uval_1 != 0x500) {
        if (uval_1 != 0x400) {
          DAT_00509420 = 0x16;
          DAT_00509424 = 0;
          return -1;
        }
        goto LAB_004dd4a2;
      }
    }
    else {
      if (uval_1 == 0x600) goto LAB_004dd4c6;
      if (uval_1 != 0x700) {
        DAT_00509420 = 0x16;
        DAT_00509424 = 0;
        return -1;
      }
    }
    color_idx = 1;
  }
LAB_004dd58c:
  local_2c = 0x80;
  if ((arg_2 & 0x100U) != 0) {
    player_idx = stack_arg;
    local_30 = 0;
    if ((~DAT_00509428 & stack_arg & 0x80) == 0) {
      local_2c = 1;
    }
  }
  if ((arg_2 & 0x40U) != 0) {
    local_2c = local_2c | 0x4000000;
    local_38 = local_38 | 0x10000;
  }
  if ((arg_2 & 0x1000U) != 0) {
    local_2c = local_2c | 0x100;
  }
  if ((arg_2 & 0x20U) == 0) {
    if ((arg_2 & 0x10U) != 0) {
      local_2c = local_2c | 0x10000000;
    }
  }
  else {
    local_2c = local_2c | 0x8000000;
  }
  target_idx = __alloc_osfhnd();
  if (target_idx == 0xffffffff) {
    DAT_00509420 = 0x18;
    DAT_00509424 = 0;
    target_idx = 0xffffffff;
  }
  else {
    slot_idx = CreateFileA(filename,local_38,match_count,&local_28,color_idx,local_2c,(HANDLE)0x0);
    if (slot_idx == (HANDLE)0xffffffff) {
      DVar2 = GetLastError();
      __dosmaperr(DVar2);
      target_idx = 0xffffffff;
    }
    else {
      card_idx = GetFileType(slot_idx);
      if (card_idx == 0) {
        CloseHandle(slot_idx);
        DVar2 = GetLastError();
        __dosmaperr(DVar2);
        target_idx = 0xffffffff;
      }
      else {
        if (card_idx == 2) {
          local_3c = local_3c | 0x40;
        }
        else if (card_idx == 3) {
          local_3c = local_3c | 8;
        }
        __set_osfhnd(target_idx,(intptr_t)slot_idx);
        *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(target_idx & 0xffffffe0) >> 3)) + 4 +
                 (target_idx & 0x1f) * 8) = local_3c | 1;
        if ((((local_3c & 0x48) == 0) && ((local_3c & 0x80) != 0)) && ((arg_2 & 2U) != 0)) {
          lVar3 = __lseek(target_idx,-1,2);
          if (lVar3 == -1) {
            if (DAT_00509424 != 0x83) {
              __close(target_idx);
              return -1;
            }
          }
          else {
            local_34[0] = '\0';
            val_4 = __read(target_idx,local_34,1);
            if (((val_4 == 0) && (local_34[0] == '\x1a')) &&
               (val_4 = __chsize(target_idx,lVar3), val_4 == -1)) {
              __close(target_idx);
              return -1;
            }
            lVar3 = __lseek(target_idx,0,0);
            if (lVar3 == -1) {
              __close(target_idx);
              return -1;
            }
          }
        }
        if (((local_3c & 0x48) == 0) && ((arg_2 & 8U) != 0)) {
          *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(target_idx & 0xffffffe0) >> 3)) + 4 +
                   (target_idx & 0x1f) * 8) =
               *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(target_idx & 0xffffffe0) >> 3)) + 4 +
                        (target_idx & 0x1f) * 8) | 0x20;
        }
      }
    }
  }
  return target_idx;
}



/*
 * Decompiled function: __close
 * Entry Point: 004dd880
 * Size: 267 bytes
 */


/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Debug */

int __cdecl __close(int player_id)

{
  intptr_t val_1;
  intptr_t val_2;
  HANDLE hObject;
  BOOL BVar3;
  int val_4;
  uint32_t slot_idx;
  
  if ((DAT_006c1c90 <= (uint32_t)arg_1) ||
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) == 0)) {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    return -1;
  }
  if ((arg_1 == 1) || (arg_1 == 2)) {
    val_1 = __get_osfhandle(2);
    val_2 = __get_osfhandle(1);
    if (val_1 != val_2) goto LAB_004dd909;
  }
  else {
LAB_004dd909:
    hObject = (HANDLE)__get_osfhandle(arg_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      slot_idx = GetLastError();
      goto LAB_004dd939;
    }
  }
  slot_idx = 0;
LAB_004dd939:
  __free_osfhnd(arg_1);
  if (slot_idx == 0) {
    *(uint8_t *)
     (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 + (arg_1 & 0x1fU) * 8) =
         0;
    val_4 = 0;
  }
  else {
    __dosmaperr(slot_idx);
    val_4 = -1;
  }
  return val_4;
}



/*
 * Decompiled function: __read
 * Entry Point: 004dd990
 * Size: 1156 bytes
 */


/* Library Function - Single Match
    __read
   
   Library: Visual Studio 1998 Debug */

int __cdecl __read(int player_id,void *out_buffer,uint32_t arg_3)

{
  BOOL BVar1;
  char loop_idx [4];
  int color_idx;
  void *target_idx;
  DWORD player_idx;
  char *card_idx;
  DWORD match_count;
  char *slot_idx;
  
  if (((uint32_t)arg_1 < DAT_006c1c90) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    color_idx = 0;
    target_idx = out_buffer;
    if ((arg_3 == 0) ||
       ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                  (arg_1 & 0x1fU) * 8) & 2) != 0)) {
      color_idx = 0;
    }
    else {
      if (((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg_1 & 0x1fU) * 8) & 0x48) != 0) &&
         (*(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5 +
                   (arg_1 & 0x1fU) * 8) != '\n')) {
        *(uint8_t *)out_buffer =
             *(uint8_t *)
              (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5 +
              (arg_1 & 0x1fU) * 8);
        target_idx = (void *)((int)out_buffer + 1);
        color_idx = 1;
        arg_3 = arg_3 - 1;
        *(uint8_t *)
         (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5 + (arg_1 & 0x1fU) * 8
         ) = 10;
      }
      BVar1 = ReadFile(*(HANDLE *)
                        (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                        (arg_1 & 0x1fU) * 8),target_idx,arg_3,&player_idx,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        match_count = GetLastError();
        if (match_count == 5) {
          DAT_00509420 = 9;
          color_idx = -1;
          DAT_00509424 = 5;
        }
        else if (match_count == 0x6d) {
          color_idx = 0;
        }
        else {
          __dosmaperr(match_count);
          color_idx = -1;
        }
      }
      else {
        color_idx = color_idx + player_idx;
        if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                      (arg_1 & 0x1fU) * 8) & 0x80) != 0) {
          if ((player_idx == 0) || (*(char *)out_buffer != '\n')) {
            *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg_1 & 0x1fU) * 8) =
                 *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) & 0xfb;
          }
          else {
            *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg_1 & 0x1fU) * 8) =
                 *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) | 4;
          }
          card_idx = out_buffer;
          slot_idx = out_buffer;
          while (slot_idx < (char *)(color_idx + (int)out_buffer)) {
            if (*slot_idx == '\x1a') {
              if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                            (arg_1 & 0x1fU) * 8) & 0x40) == 0) {
                *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                         (arg_1 & 0x1fU) * 8) =
                     *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4
                              + (arg_1 & 0x1fU) * 8) | 2;
              }
              break;
            }
            if (*slot_idx == '\r') {
              if (slot_idx < (char *)((int)out_buffer + color_idx + -1)) {
                if (slot_idx[1] == '\n') {
                  slot_idx = slot_idx + 2;
                  *card_idx = '\n';
                }
                else {
                  *card_idx = *slot_idx;
                  slot_idx = slot_idx + 1;
                }
                card_idx = card_idx + 1;
              }
              else {
                slot_idx = slot_idx + 1;
                match_count = 0;
                BVar1 = ReadFile(*(HANDLE *)
                                  (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3))
                                  + (arg_1 & 0x1fU) * 8),loop_idx,1,&player_idx,(LPOVERLAPPED)0x0);
                if (BVar1 == 0) {
                  match_count = GetLastError();
                }
                if ((match_count == 0) && (player_idx != 0)) {
                  if ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                                 4 + (arg_1 & 0x1fU) * 8) & 0x48) == 0) {
                    if ((out_buffer == card_idx) && (loop_idx[0] == '\n')) {
                      *card_idx = '\n';
                      card_idx = card_idx + 1;
                    }
                    else {
                      __lseek(arg_1,-1,1);
                      if (loop_idx[0] != '\n') {
                        *card_idx = '\r';
                        card_idx = card_idx + 1;
                      }
                    }
                  }
                  else {
                    if (loop_idx[0] == '\n') {
                      *card_idx = '\n';
                    }
                    else {
                      *card_idx = '\r';
                      *(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5
                               + (arg_1 & 0x1fU) * 8) = loop_idx[0];
                    }
                    card_idx = card_idx + 1;
                  }
                }
                else {
                  *card_idx = '\r';
                  card_idx = card_idx + 1;
                }
              }
            }
            else {
              *card_idx = *slot_idx;
              slot_idx = slot_idx + 1;
              card_idx = card_idx + 1;
            }
          }
          color_idx = (int)card_idx - (int)out_buffer;
        }
      }
    }
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    color_idx = -1;
  }
  return color_idx;
}



/*
 * Decompiled function: _memcmp
 * Entry Point: 004dde30
 * Size: 172 bytes
 */


/* Library Function - Single Match
    _memcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _memcmp(void *ptr_1,void *ptr_2,size_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int val_3;
  uint8_t bVar4;
  uint32_t uval_5;
  uint8_t bVar6;
  uint32_t *puVar7;
  uint32_t *puVar8;
  bool bVar9;
  
  if (arg_3 != 0) {
    if ((((uint32_t)ptr_1 | (uint32_t)ptr_2) & 3) == 0) {
      uval_2 = arg_3 & 3;
      uval_5 = arg_3 >> 2;
      bVar9 = false;
      puVar7 = ptr_1;
      puVar8 = ptr_2;
      if (uval_5 != 0) {
        do {
          ptr_1 = puVar7;
          ptr_2 = puVar8;
          if (uval_5 == 0) break;
          uval_5 = uval_5 - 1;
          ptr_2 = puVar8 + 1;
          ptr_1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = ptr_1;
          puVar8 = ptr_2;
        } while (bVar9);
        if (!bVar9) {
          uval_2 = *(uint32_t *)((int)ptr_1 + -4);
          uval_5 = *(uint32_t *)((int)ptr_2 + -4);
          bVar9 = (uint8_t)uval_2 < (uint8_t)uval_5;
          if ((((uint8_t)uval_2 == (uint8_t)uval_5) &&
              (bVar4 = (uint8_t)(uval_2 >> 8), bVar6 = (uint8_t)(uval_5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (uint8_t)(uval_2 >> 0x10), bVar6 = (uint8_t)(uval_5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (uint8_t)(uval_2 >> 0x18) < (uint8_t)(uval_5 >> 0x18);
          }
          goto LAB_004ddeaa;
        }
      }
      if (uval_2 != 0) {
        uval_5 = *(uint32_t *)ptr_1;
        uval_1 = *(uint32_t *)ptr_2;
        bVar9 = (uint8_t)uval_5 < (uint8_t)uval_1;
        if ((uint8_t)uval_5 != (uint8_t)uval_1) {
LAB_004ddeaa:
          return (1 - (uint32_t)bVar9) - (uint32_t)(bVar9 != 0);
        }
        val_3 = 0;
        if (uval_2 != 1) {
          bVar6 = (uint8_t)(uval_5 >> 8);
          bVar4 = (uint8_t)(uval_1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_004ddeaa;
          val_3 = 0;
          if (uval_2 != 2) {
            bVar9 = (uval_5 & 0xff0000) < (uval_1 & 0xff0000);
            if ((uval_5 & 0xff0000) != (uval_1 & 0xff0000)) goto LAB_004ddeaa;
            val_3 = uval_2 - 3;
          }
        }
        return val_3;
      }
    }
    else {
      if ((arg_3 & 1) == 0) goto LAB_004dde5d;
      bVar9 = *(uint8_t *)ptr_1 < *(uint8_t *)ptr_2;
      if (*(uint8_t *)ptr_1 != *(uint8_t *)ptr_2) goto LAB_004ddeaa;
      ptr_1 = (void *)((int)ptr_1 + 1);
      ptr_2 = (void *)((int)ptr_2 + 1);
      for (arg_3 = arg_3 - 1; arg_3 != 0; arg_3 = arg_3 - 2) {
LAB_004dde5d:
        bVar9 = *(uint8_t *)ptr_1 < *(uint8_t *)ptr_2;
        if ((*(uint8_t *)ptr_1 != *(uint8_t *)ptr_2) ||
           (bVar9 = *(uint8_t *)((int)ptr_1 + 1) < *(uint8_t *)((int)ptr_2 + 1),
           *(uint8_t *)((int)ptr_1 + 1) != *(uint8_t *)((int)ptr_2 + 1))) goto LAB_004ddeaa;
        ptr_2 = (void *)((int)ptr_2 + 2);
        ptr_1 = (void *)((int)ptr_1 + 2);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_004ddee0
 * Entry Point: 004ddee0
 * Size: 47 bytes
 */


/* WARNING: Unable to track spacebase fully for stack */

void Mem_AllocOrFree_004ddee0(void)

{
  uint32_t reg_eax;
  uint8_t *u_ptr_1;
  int32_t unaff_retaddr;
  
  u_ptr_1 = &stack0x00000004;
  for (; 0xfff < reg_eax; reg_eax = reg_eax - 0x1000) {
    u_ptr_1 = u_ptr_1 + -0x1000;
  }
  *(int32_t *)(u_ptr_1 + (-4 - reg_eax)) = unaff_retaddr;
  return;
}



/*
 * Decompiled function: FID_conflict:__fwrite_lk
 * Entry Point: 004ddf10
 * Size: 536 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __fwrite_lk
    _fwrite
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl FID_conflict___fwrite_lk(void *ptr_1,size_t arg_2,size_t arg_3,FILE *fp)

{
  uint32_t uval_1;
  size_t len_2;
  int val_3;
  uint32_t uval_4;
  uint32_t loop_idx;
  uint32_t color_idx;
  uint32_t card_idx;
  char *match_count;
  
  match_count = ptr_1;
  uval_1 = arg_3 * arg_2;
  if (uval_1 == 0) {
    len_2 = 0;
  }
  else {
    card_idx = uval_1;
    if ((fp->_flag & 0x10cU) == 0) {
      loop_idx = 0x1000;
    }
    else {
      loop_idx = fp->_bufsiz;
    }
    do {
      while( true ) {
        while( true ) {
          if (card_idx == 0) {
            return arg_3;
          }
          if (((fp->_flag & 0x108U) == 0) || (fp->_cnt == 0)) break;
          uval_4 = fp->_cnt;
          if (card_idx <= (uint32_t)fp->_cnt) {
            uval_4 = card_idx;
          }
          FID_conflict__memcpy(fp->_ptr,match_count,uval_4);
          card_idx = card_idx - uval_4;
          fp->_cnt = fp->_cnt - uval_4;
          fp->_ptr = fp->_ptr + uval_4;
          match_count = match_count + uval_4;
        }
        if (loop_idx <= card_idx) break;
        val_3 = __flsbuf((int)*match_count,fp);
        if (val_3 == -1) {
          return (uval_1 - card_idx) / arg_2;
        }
        match_count = match_count + 1;
        card_idx = card_idx - 1;
        if (fp->_bufsiz < 1) {
          loop_idx = 1;
        }
        else {
          loop_idx = fp->_bufsiz;
        }
      }
      if (((fp->_flag & 0x108U) != 0) && (val_3 = __flush(fp), val_3 != 0)) {
        return (uval_1 - card_idx) / arg_2;
      }
      if (loop_idx == 0) {
        color_idx = card_idx;
      }
      else {
        color_idx = card_idx - card_idx % loop_idx;
      }
      uval_4 = __write(fp->_file,match_count,color_idx);
      if (uval_4 == 0xffffffff) {
        fp->_flag = fp->_flag | 0x20;
        return (uval_1 - card_idx) / arg_2;
      }
      card_idx = card_idx - uval_4;
      match_count = match_count + uval_4;
    } while (color_idx <= uval_4);
    fp->_flag = fp->_flag | 0x20;
    len_2 = (uval_1 - card_idx) / arg_2;
  }
  return len_2;
}



/*
 * Decompiled function: _strrchr
 * Entry Point: 004de130
 * Size: 39 bytes
 */


/* Library Function - Single Match
    _strrchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *filepath,int card_slot)

{
  char cVar1;
  int val_2;
  char *char_ptr_3;
  char *pcVar4;
  
  val_2 = -1;
  do {
    pcVar4 = str_1;
    if (val_2 == 0) break;
    val_2 = val_2 + -1;
    pcVar4 = str_1 + 1;
    cVar1 = *str_1;
    str_1 = pcVar4;
  } while (cVar1 != '\0');
  val_2 = -(val_2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    char_ptr_3 = pcVar4;
    if (val_2 == 0) break;
    val_2 = val_2 + -1;
    char_ptr_3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = char_ptr_3;
  } while ((char)arg_2 != cVar1);
  char_ptr_3 = char_ptr_3 + 1;
  if (*char_ptr_3 != (char)arg_2) {
    char_ptr_3 = (char *)0x0;
  }
  return char_ptr_3;
}



/*
 * Decompiled function: __isctype
 * Entry Point: 004de160
 * Size: 182 bytes
 */


/* Library Function - Single Match
    __isctype
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isctype(int arg1,int arg2)

{
  BOOL BVar1;
  uint32_t uval_2;
  BOOL unaff_EDI;
  uint8_t card_idx;
  uint8_t local_f;
  uint8_t local_e;
  LPCSTR match_count;
  uint32_t slot_idx;
  
  if (arg1 + 1U < 0x101) {
    uval_2 = (uint32_t)*(uint16_t *)(PTR_DAT_005094a0 + arg1 * 2) & arg2;
  }
  else {
    if ((*(uint16_t *)(PTR_DAT_005094a0 + ((uint32_t)arg1 >> 8 & 0xff) * 2) & 0x8000) == 0) {
      card_idx = (uint8_t)arg1;
      local_f = 0;
      match_count = (LPCSTR)0x1;
    }
    else {
      card_idx = (uint8_t)((uint32_t)arg1 >> 8);
      local_f = (uint8_t)arg1;
      local_e = 0;
      match_count = (LPCSTR)0x2;
    }
    BVar1 = ___crtGetStringTypeA
                      ((_locale_t)0x1,(DWORD)&card_idx,match_count,(int)&slot_idx,(LPWORD)0x0,0,unaff_EDI
                      );
    if (BVar1 == 0) {
      uval_2 = 0;
    }
    else {
      uval_2 = slot_idx & 0xffff & arg2;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: __allshl
 * Entry Point: 004de220
 * Size: 31 bytes
 */


/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(uint8_t arg1,int arg2)

{
  uint32_t reg_eax;
  
  if (0x3f < arg1) {
    return 0;
  }
  if (arg1 < 0x20) {
    return CONCAT44(arg2 << (arg1 & 0x1f) | reg_eax >> 0x20 - (arg1 & 0x1f),reg_eax << (arg1 & 0x1f));
  }
  return (ulonglong)(reg_eax << (arg1 & 0x1f)) << 0x20;
}



