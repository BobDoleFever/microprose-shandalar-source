/*
 * Decompiled function: FUN_0043ce77
 * Entry Point: 0043ce77
 * Size: 594 bytes
 */
#include "duel.h"


undefined4 FUN_0043ce77(LPCSTR str_1)

{
  char *pcVar1;
  undefined1 local_20 [4];
  HANDLE local_1c;
  undefined4 local_18;
  DWORD local_14;
  DWORD local_10;
  int local_c;
  char *local_8;
  
  local_18 = 0;
  for (local_c = 0; local_c < DAT_0061743c; local_c = local_c + 1) {
    *(undefined **)(&DAT_005f7910 + local_c * 0x14) = &DAT_004f78fc;
    *(undefined **)(&DAT_005f7914 + local_c * 0x14) = &DAT_004f7900;
    *(undefined **)(&DAT_005f7918 + local_c * 0x14) = &DAT_004f7904;
    *(undefined **)(&DAT_005f791c + local_c * 0x14) = &DAT_004f7908;
    *(undefined **)(&DAT_005f7920 + local_c * 0x14) = &DAT_004f790c;
  }
  local_1c = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (local_1c != (HANDLE)0xffffffff) {
    local_10 = GetFileSize(local_1c,(LPDWORD)0x0);
    DAT_0060161c = _malloc(local_10 + 1);
    if (DAT_0060161c != (char *)0x0) {
      ReadFile(local_1c,DAT_0060161c,local_10,&local_14,(LPOVERLAPPED)0x0);
      local_8 = DAT_0060161c;
      pcVar1 = _strchr(DAT_0060161c,10);
      local_8 = pcVar1 + 1;
      for (local_c = 0; local_c < DAT_0061743c; local_c = local_c + 1) {
        _sscanf(local_8,&DAT_004f7910,local_20);
        local_8 = (char *)FUN_0043d0f9(&local_8);
        local_8 = (char *)FUN_0043d0f9(&local_8);
        pcVar1 = (char *)FUN_0043d0f9(&local_8);
        *(char **)(&DAT_005f7910 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_0043d0f9(&local_8);
        *(char **)(&DAT_005f7914 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_0043d0f9(&local_8);
        *(char **)(&DAT_005f7918 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_0043d0f9(&local_8);
        *(char **)(&DAT_005f791c + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_0043d0f9(&local_8);
        *(char **)(&DAT_005f7920 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
      }
      local_18 = 1;
    }
    CloseHandle(local_1c);
  }
  return local_18;
}


