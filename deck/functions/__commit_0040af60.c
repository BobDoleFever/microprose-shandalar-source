/*
 * Decompiled function: __commit
 * Entry Point: 0040af60
 * Size: 217 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 1998 Debug */

int __cdecl __commit(int arg_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD local_8;
  
  if ((((uint32_t)arg_1 < DAT_004157fc) &&
      ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) & 1) != 0)) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(arg_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      local_8 = GetLastError();
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      return 0;
    }
    _DAT_00412a70 = local_8;
  }
  _DAT_00412a6c = 9;
  return -1;
}


