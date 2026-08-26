/*
 * Decompiled function: FUN_10031af5
 * Entry Point: 10031af5
 * Size: 193 bytes
 */
#include "deckdll.h"


int32_t FUN_10031af5(int32_t arg_1,LPCSTR str_2,void *arg_3)

{
  char local_208 [500];
  int32_t local_14;
  HGLOBAL local_10;
  BITMAPINFO *local_c;
  HRSRC local_8;
  
  local_14 = 0;
  local_8 = FindResourceA(DAT_101cf334,str_2,(LPCSTR)0x2);
  if (local_8 != (HRSRC)0x0) {
    local_10 = LoadResource(DAT_101cf334,local_8);
    if (local_10 != (HGLOBAL)0x0) {
      local_c = LockResource(local_10);
      if (local_c != (BITMAPINFO *)0x0) {
        local_14 = thunk_FUN_10031cb7(local_c,arg_3);
      }
    }
  }
  if (DAT_10176354 != 0) {
    sprintf(local_208,s__08X_LoadDIBSection___s__10046674,local_14,str_2);
    OutputDebugStringA(local_208);
  }
  return local_14;
}


