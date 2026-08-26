/*
 * Decompiled function: FUN_00470e75
 * Entry Point: 00470e75
 * Size: 192 bytes
 */
#include "duel.h"


undefined4 FUN_00470e75(undefined4 arg_1,LPCSTR str_2,void *arg_3,undefined4 arg_4)

{
  char local_208 [500];
  undefined4 local_14;
  HGLOBAL local_10;
  BITMAPINFO *local_c;
  HRSRC local_8;
  
  local_14 = 0;
  local_8 = FindResourceA(DAT_00664680,str_2,(LPCSTR)0x2);
  if (local_8 != (HRSRC)0x0) {
    local_10 = LoadResource(DAT_00664680,local_8);
    if (local_10 != (HGLOBAL)0x0) {
      local_c = LockResource(local_10);
      if (local_c != (BITMAPINFO *)0x0) {
        local_14 = FUN_00471035(local_c,arg_3);
      }
    }
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_208,s__08X_LoadDIBSection___s__004f97c4,local_14,str_2);
    OutputDebugStringA(local_208);
  }
  return local_14;
}


