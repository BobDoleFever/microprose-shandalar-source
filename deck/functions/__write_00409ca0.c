/*
 * Decompiled function: __write
 * Entry Point: 00409ca0
 * Size: 744 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __write
   
   Library: Visual Studio 1998 Debug */

int __cdecl __write(int arg_1,void *ptr_2,uint32_t arg_3)

{
  char cVar1;
  BOOL BVar2;
  int local_424;
  DWORD local_41c;
  char local_418 [1028];
  DWORD local_14;
  uint32_t local_10;
  char *local_c;
  char *local_8;
  
  if (((uint32_t)arg_1 < DAT_004157fc) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    local_14 = 0;
    local_424 = 0;
    if (arg_3 == 0) {
      local_424 = 0;
    }
    else {
      if ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg_1 & 0x1fU) * 8) & 0x20) != 0) {
        __lseek(arg_1,0,2);
      }
      if ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                    (arg_1 & 0x1fU) * 8) & 0x80) == 0) {
        BVar2 = WriteFile(*(HANDLE *)
                           (*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                           (arg_1 & 0x1fU) * 8),ptr_2,arg_3,&local_41c,(LPOVERLAPPED)0x0);
        if (BVar2 == 0) {
          local_10 = GetLastError();
        }
        else {
          local_10 = 0;
          local_14 = local_41c;
        }
      }
      else {
        local_8 = ptr_2;
        local_10 = 0;
        do {
          if (arg_3 <= (uint32_t)((int)local_8 - (int)ptr_2)) break;
          local_c = local_418;
          while (((int)local_c - (int)local_418 < 0x400 &&
                 ((uint32_t)((int)local_8 - (int)ptr_2) < arg_3))) {
            cVar1 = *local_8;
            local_8 = local_8 + 1;
            if (cVar1 == '\n') {
              local_424 = local_424 + 1;
              *local_c = '\r';
              local_c = local_c + 1;
            }
            *local_c = cVar1;
            local_c = local_c + 1;
          }
          BVar2 = WriteFile(*(HANDLE *)
                             (*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                             (arg_1 & 0x1fU) * 8),local_418,(int)local_c - (int)local_418,&local_41c
                            ,(LPOVERLAPPED)0x0);
          if (BVar2 == 0) {
            local_10 = GetLastError();
            break;
          }
          local_14 = local_14 + local_41c;
        } while ((int)local_c - (int)local_418 <= (int)local_41c);
      }
      if (local_14 == 0) {
        if (local_10 == 0) {
          if (((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                         (arg_1 & 0x1fU) * 8) & 0x40) == 0) || (*(char *)ptr_2 != '\x1a')) {
            _DAT_00412a6c = 0x1c;
            _DAT_00412a70 = 0;
            local_424 = -1;
          }
          else {
            local_424 = 0;
          }
        }
        else {
          if (local_10 == 5) {
            _DAT_00412a6c = 9;
            _DAT_00412a70 = local_10;
          }
          else {
            __dosmaperr(local_10);
          }
          local_424 = -1;
        }
      }
      else {
        local_424 = local_14 - local_424;
      }
    }
  }
  else {
    _DAT_00412a6c = 9;
    _DAT_00412a70 = 0;
    local_424 = -1;
  }
  return local_424;
}


