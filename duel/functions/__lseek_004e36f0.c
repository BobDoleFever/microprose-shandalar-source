/*
 * Decompiled function: __lseek
 * Entry Point: 004e36f0
 * Size: 285 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 1998 Debug */

long __cdecl __lseek(int arg_1,long arg_2,int arg_3)

{
  DWORD DVar1;
  HANDLE hFile;
  ulong local_8;
  
  if (((uint)arg_1 < DAT_006c1c90) &&
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(arg_1);
    if (hFile == (HANDLE)0xffffffff) {
      DAT_00509420 = 9;
      DVar1 = 0xffffffff;
    }
    else {
      DVar1 = SetFilePointer(hFile,arg_2,(PLONG)0x0,arg_3);
      if (DVar1 == 0xffffffff) {
        local_8 = GetLastError();
      }
      else {
        local_8 = 0;
      }
      if (local_8 == 0) {
        *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) =
             *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                      (arg_1 & 0x1fU) * 8) & 0xfd;
      }
      else {
        __dosmaperr(local_8);
        DVar1 = 0xffffffff;
      }
    }
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    DVar1 = 0xffffffff;
  }
  return DVar1;
}


