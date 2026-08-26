/*
 * Decompiled function: FUN_004f6b33
 * Entry Point: 004f6b33
 * Size: 597 bytes
 */
#include "magic.h"


undefined4 FUN_004f6b33(LPCSTR str_1)

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
  for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
    *(undefined **)(&DAT_006809e0 + local_c * 0x14) = &DAT_00530318;
    *(undefined **)(&DAT_006809e4 + local_c * 0x14) = &DAT_0053031c;
    *(undefined **)(&DAT_006809e8 + local_c * 0x14) = &DAT_00530320;
    *(undefined **)(&DAT_006809ec + local_c * 0x14) = &DAT_00530324;
    *(undefined **)(&DAT_006809f0 + local_c * 0x14) = &DAT_00530328;
  }
  local_1c = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (local_1c != (HANDLE)0xffffffff) {
    local_10 = GetFileSize(local_1c,(LPDWORD)0x0);
    DAT_0068a720 = malloc(local_10 + 1);
    if (DAT_0068a720 != (void *)0x0) {
      ReadFile(local_1c,DAT_0068a720,local_10,&local_14,(LPOVERLAPPED)0x0);
      local_8 = DAT_0068a720;
      pcVar1 = strchr(DAT_0068a720,10);
      local_8 = pcVar1 + 1;
      for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
        sscanf(local_8,&DAT_0053032c,local_20);
        local_8 = (char *)FUN_004f6db9(&local_8);
        local_8 = (char *)FUN_004f6db9(&local_8);
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809e0 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809e4 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809e8 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809ec + local_c * 0x14) = local_8;
        local_8 = pcVar1;
        pcVar1 = (char *)FUN_004f6db9(&local_8);
        *(char **)(&DAT_006809f0 + local_c * 0x14) = local_8;
        local_8 = pcVar1;
      }
      local_18 = 1;
    }
    CloseHandle(local_1c);
  }
  return local_18;
}


