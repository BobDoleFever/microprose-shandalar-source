/*
 * Decompiled function: FUN_1002a2a3
 * Entry Point: 1002a2a3
 * Size: 597 bytes
 */
#include "deckdll.h"


int32_t FUN_1002a2a3(LPCSTR str_1)

{
  char *char_ptr_1;
  uint8_t local_20 [4];
  HANDLE local_1c;
  int32_t local_18;
  DWORD local_14;
  DWORD local_10;
  int local_c;
  char *local_8;
  
  local_18 = 0;
  for (local_c = 0; local_c < DAT_10175ee0; local_c = local_c + 1) {
    *(uint8_t **)(&DAT_101589a0 + local_c * 0x14) = &DAT_100460fc;
    *(uint8_t **)(&DAT_101589a4 + local_c * 0x14) = &DAT_10046100;
    *(uint8_t **)(&DAT_101589a8 + local_c * 0x14) = &DAT_10046104;
    *(uint8_t **)(&DAT_101589ac + local_c * 0x14) = &DAT_10046108;
    *(uint8_t **)(&DAT_101589b0 + local_c * 0x14) = &DAT_1004610c;
  }
  local_1c = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (local_1c != (HANDLE)0xffffffff) {
    local_10 = GetFileSize(local_1c,(LPDWORD)0x0);
    DAT_10162614 = malloc(local_10 + 1);
    if (DAT_10162614 != (void *)0x0) {
      ReadFile(local_1c,DAT_10162614,local_10,&local_14,(LPOVERLAPPED)0x0);
      local_8 = DAT_10162614;
      char_ptr_1 = strchr(DAT_10162614,10);
      local_8 = char_ptr_1 + 1;
      for (local_c = 0; local_c < DAT_10175ee0; local_c = local_c + 1) {
        sscanf(local_8,&DAT_10046110,local_20);
        local_8 = (char *)thunk_FUN_1002a529(&local_8);
        local_8 = (char *)thunk_FUN_1002a529(&local_8);
        char_ptr_1 = (char *)thunk_FUN_1002a529(&local_8);
        *(char **)(&DAT_101589a0 + local_c * 0x14) = local_8;
        local_8 = char_ptr_1;
        char_ptr_1 = (char *)thunk_FUN_1002a529(&local_8);
        *(char **)(&DAT_101589a4 + local_c * 0x14) = local_8;
        local_8 = char_ptr_1;
        char_ptr_1 = (char *)thunk_FUN_1002a529(&local_8);
        *(char **)(&DAT_101589a8 + local_c * 0x14) = local_8;
        local_8 = char_ptr_1;
        char_ptr_1 = (char *)thunk_FUN_1002a529(&local_8);
        *(char **)(&DAT_101589ac + local_c * 0x14) = local_8;
        local_8 = char_ptr_1;
        char_ptr_1 = (char *)thunk_FUN_1002a529(&local_8);
        *(char **)(&DAT_101589b0 + local_c * 0x14) = local_8;
        local_8 = char_ptr_1;
      }
      local_18 = 1;
    }
    CloseHandle(local_1c);
  }
  return local_18;
}


