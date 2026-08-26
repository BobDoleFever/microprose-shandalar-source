/*
 * Decompiled function: __open_osfhandle
 * Entry Point: 0040aa30
 * Size: 256 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __open_osfhandle
   
   Library: Visual Studio 1998 Debug */

int __cdecl __open_osfhandle(intptr_t arg1,int arg2)

{
  DWORD DVar1;
  uint32_t arg1_00;
  uint8_t local_10;
  
  local_10 = 0;
  if ((arg2 & 8U) != 0) {
    local_10 = 0x20;
  }
  if ((arg2 & 0x4000U) != 0) {
    local_10 = local_10 | 0x80;
  }
  DVar1 = GetFileType((HANDLE)arg1);
  if (DVar1 == 0) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
    arg1_00 = 0xffffffff;
  }
  else {
    if (DVar1 == 2) {
      local_10 = local_10 | 0x40;
    }
    else if (DVar1 == 3) {
      local_10 = local_10 | 8;
    }
    arg1_00 = __alloc_osfhnd();
    if (arg1_00 == 0xffffffff) {
      _DAT_00412a6c = 0x18;
      _DAT_00412a70 = 0;
      arg1_00 = 0xffffffff;
    }
    else {
      __set_osfhnd(arg1_00,arg1);
      *(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg1_00 & 0xffffffe0) >> 3)) + 4 +
               (arg1_00 & 0x1f) * 8) = local_10 | 1;
    }
  }
  return arg1_00;
}


