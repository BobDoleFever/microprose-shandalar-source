/*
 * ioinit.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: __ioinit
 * Entry Point: 004e5400
 * Size: 808 bytes
 */


/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ioinit(void)

{
  int32_t *u_ptr_1;
  DWORD DVar2;
  int *i_ptr_3;
  HANDLE hFile;
  UINT UVar4;
  DWORD local_6c;
  UINT local_68;
  uint8_t *local_64;
  int local_60;
  uint32_t local_5c;
  char local_58;
  int32_t *local_54;
  _STARTUPINFOA local_4c;
  UINT *slot_idx;
  
  local_54 = (int32_t *)__malloc_dbg(0x100,2,"ioinit.c",0x83);
  if (local_54 == (int32_t *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_006c1c90 = 0x20;
  DAT_006c1b90 = local_54;
  for (; local_54 < DAT_006c1b90 + 0x40; local_54 = local_54 + 2) {
    *(uint8_t *)(local_54 + 1) = 0;
    *local_54 = 0xffffffff;
    *(uint8_t *)((int)local_54 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    local_68 = *(UINT *)local_4c.lpReserved2;
    slot_idx = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_64 = (uint8_t *)(local_68 + (int)slot_idx);
    if (0x7ff < (int)local_68) {
      local_68 = 0x800;
    }
    local_60 = 1;
    while ((int)DAT_006c1c90 < (int)local_68) {
      local_54 = (int32_t *)__malloc_dbg(0x100,2,"ioinit.c",0xb8);
      if (local_54 == (int32_t *)0x0) {
        local_68 = DAT_006c1c90;
        break;
      }
      (&DAT_006c1b90)[local_60] = local_54;
      DAT_006c1c90 = DAT_006c1c90 + 0x20;
      for (; local_54 < (int32_t *)((int)(&DAT_006c1b90)[local_60] + 0x100);
          local_54 = local_54 + 2) {
        *(uint8_t *)(local_54 + 1) = 0;
        *local_54 = 0xffffffff;
        *(uint8_t *)((int)local_54 + 5) = 10;
      }
      local_60 = local_60 + 1;
    }
    for (local_5c = 0; (int)local_5c < (int)local_68; local_5c = local_5c + 1) {
      if (((*(int *)local_64 != -1) && ((*slot_idx & 1) != 0)) &&
         (((*slot_idx & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)local_64), DVar2 != 0)))) {
        u_ptr_1 = (int32_t *)
                 (*(int *)((int)&DAT_006c1b90 + ((int)(local_5c & 0xffffffe0) >> 3)) +
                 (local_5c & 0x1f) * 8);
        *u_ptr_1 = *(int32_t *)local_64;
        *(uint8_t *)(u_ptr_1 + 1) = (uint8_t)*slot_idx;
      }
      slot_idx = (UINT *)((int)slot_idx + 1);
      local_64 = local_64 + 4;
    }
  }
  for (local_5c = 0; (int)local_5c < 3; local_5c = local_5c + 1) {
    i_ptr_3 = DAT_006c1b90 + local_5c * 2;
    if (*i_ptr_3 == -1) {
      *(uint8_t *)(i_ptr_3 + 1) = 0x81;
      if (local_5c == 0) {
        local_6c = 0xfffffff6;
      }
      else if (local_5c == 1) {
        local_6c = 0xfffffff5;
      }
      else {
        local_6c = 0xfffffff4;
      }
      hFile = GetStdHandle(local_6c);
      if ((hFile == (HANDLE)0xffffffff) || (DVar2 = GetFileType(hFile), DVar2 == 0)) {
        *(uint8_t *)(i_ptr_3 + 1) = *(uint8_t *)(i_ptr_3 + 1) | 0x40;
      }
      else {
        *i_ptr_3 = (int)hFile;
        local_58 = (char)DVar2;
        if (local_58 == '\x02') {
          *(uint8_t *)(i_ptr_3 + 1) = *(uint8_t *)(i_ptr_3 + 1) | 0x40;
        }
        else if (local_58 == '\x03') {
          *(uint8_t *)(i_ptr_3 + 1) = *(uint8_t *)(i_ptr_3 + 1) | 8;
        }
      }
    }
    else {
      *(uint8_t *)(i_ptr_3 + 1) = *(uint8_t *)(i_ptr_3 + 1) | 0x80;
    }
  }
  UVar4 = SetHandleCount(DAT_006c1c90);
  return UVar4;
}



/*
 * Decompiled function: __ioterm
 * Entry Point: 004e5730
 * Size: 104 bytes
 */


/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 1998 Debug */

void __cdecl __ioterm(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x40; slot_idx = slot_idx + 1) {
    if ((&DAT_006c1b90)[slot_idx] != 0) {
      __free_dbg((void *)(&DAT_006c1b90)[slot_idx],2);
    }
  }
  return;
}



