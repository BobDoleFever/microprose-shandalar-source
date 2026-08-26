/*
 * Decompiled function: __commit
 * Entry Point: 004e8d40
 * Size: 217 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 1998 Debug */

int __cdecl __commit(int arg_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD local_8;
  
  if ((((uint)arg_1 < DAT_006c1c90) &&
      ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) & 1) != 0)) &&
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
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
    DAT_00509424 = local_8;
  }
  DAT_00509420 = 9;
  return -1;
}


