/*
 * Decompiled function: __ioinit
 * Entry Point: 00402b00
 * Size: 808 bytes
 */
#include "deck.h"


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
  UINT *local_8;
  
  local_54 = (int32_t *)__malloc_dbg(0x100,2,0x410088,0x83);
  if (local_54 == (int32_t *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_004157fc = 0x20;
  DAT_004156c0 = local_54;
  for (; local_54 < DAT_004156c0 + 0x40; local_54 = local_54 + 2) {
    *(uint8_t *)(local_54 + 1) = 0;
    *local_54 = 0xffffffff;
    *(uint8_t *)((int)local_54 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    local_68 = *(UINT *)local_4c.lpReserved2;
    local_8 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_64 = (uint8_t *)(local_68 + (int)local_8);
    if (0x7ff < (int)local_68) {
      local_68 = 0x800;
    }
    local_60 = 1;
    while ((int)DAT_004157fc < (int)local_68) {
      local_54 = (int32_t *)__malloc_dbg(0x100,2,0x410088,0xb8);
      if (local_54 == (int32_t *)0x0) {
        local_68 = DAT_004157fc;
        break;
      }
      (&DAT_004156c0)[local_60] = local_54;
      DAT_004157fc = DAT_004157fc + 0x20;
      for (; local_54 < (int32_t *)((int)(&DAT_004156c0)[local_60] + 0x100);
          local_54 = local_54 + 2) {
        *(uint8_t *)(local_54 + 1) = 0;
        *local_54 = 0xffffffff;
        *(uint8_t *)((int)local_54 + 5) = 10;
      }
      local_60 = local_60 + 1;
    }
    for (local_5c = 0; (int)local_5c < (int)local_68; local_5c = local_5c + 1) {
      if (((*(int *)local_64 != -1) && ((*local_8 & 1) != 0)) &&
         (((*local_8 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)local_64), DVar2 != 0)))) {
        u_ptr_1 = (int32_t *)
                 (*(int *)((int)&DAT_004156c0 + ((int)(local_5c & 0xffffffe0) >> 3)) +
                 (local_5c & 0x1f) * 8);
        *u_ptr_1 = *(int32_t *)local_64;
        *(uint8_t *)(u_ptr_1 + 1) = (uint8_t)*local_8;
      }
      local_8 = (UINT *)((int)local_8 + 1);
      local_64 = local_64 + 4;
    }
  }
  for (local_5c = 0; (int)local_5c < 3; local_5c = local_5c + 1) {
    i_ptr_3 = DAT_004156c0 + local_5c * 2;
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
  UVar4 = SetHandleCount(DAT_004157fc);
  return UVar4;
}


