/*
 * Decompiled function: FUN_004f4025
 * Entry Point: 004f4025
 * Size: 193 bytes
 */
#include "magic.h"


undefined4 FUN_004f4025(undefined4 arg_1,LPCSTR str_2,void *arg_3,undefined4 arg_4)

{
  char local_208 [500];
  undefined4 local_14;
  HGLOBAL local_10;
  BITMAPINFO *local_c;
  HRSRC local_8;
  
  local_14 = 0;
  local_8 = FindResourceA(g_AppHInstance,str_2,(LPCSTR)0x2);
  if (local_8 != (HRSRC)0x0) {
    local_10 = LoadResource(g_AppHInstance,local_8);
    if (local_10 != (HGLOBAL)0x0) {
      local_c = LockResource(local_10);
      if (local_c != (BITMAPINFO *)0x0) {
        local_14 = FUN_004f41e7(local_c,arg_3);
      }
    }
  }
  if (DAT_006b157c != 0) {
    sprintf(local_208,s__08X_LoadDIBSection___s__005301c4,local_14,str_2);
    OutputDebugStringA(local_208);
  }
  return local_14;
}


