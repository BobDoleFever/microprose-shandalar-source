/*
 * Decompiled function: FUN_004f40e6
 * Entry Point: 004f40e6
 * Size: 257 bytes
 */
#include "magic.h"


undefined4 FUN_004f40e6(LPCSTR str_1,void *arg_2,undefined4 arg_3)

{
  char local_20c [500];
  undefined4 local_18;
  HANDLE local_14;
  HANDLE local_10;
  LPVOID local_c;
  BITMAPINFO *local_8;
  
  local_18 = 0;
  local_14 = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  if (local_14 != (HANDLE)0xffffffff) {
    local_10 = CreateFileMappingA(local_14,(LPSECURITY_ATTRIBUTES)0x0,0x8000000,0,0,(LPCSTR)0x0);
    if (local_10 != (HANDLE)0x0) {
      local_c = MapViewOfFile(local_10,4,0,0,0);
      if (local_c != (LPVOID)0x0) {
        local_8 = (BITMAPINFO *)((int)local_c + 0xe);
        local_18 = FUN_004f41e7(local_8,arg_2);
        UnmapViewOfFile(local_8);
      }
      CloseHandle(local_10);
    }
    CloseHandle(local_14);
  }
  if (DAT_006b157c != 0) {
    sprintf(local_20c,s__08X_LoadDIBSectionFromFile___s__005301e0,local_18,str_1);
    OutputDebugStringA(local_20c);
  }
  return local_18;
}


