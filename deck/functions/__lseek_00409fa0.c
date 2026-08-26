/*
 * Decompiled function: __lseek
 * Entry Point: 00409fa0
 * Size: 285 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 1998 Debug */

long __cdecl __lseek(int arg_1,long arg_2,int arg_3)

{
  DWORD DVar1;
  HANDLE hFile;
  uint32_t local_8;
  
  if (((uint32_t)arg_1 < DAT_004157fc) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(arg_1);
    if (hFile == (HANDLE)0xffffffff) {
      _DAT_00412a6c = 9;
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
        *(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) =
             *(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                      (arg_1 & 0x1fU) * 8) & 0xfd;
      }
      else {
        __dosmaperr(local_8);
        DVar1 = 0xffffffff;
      }
    }
  }
  else {
    _DAT_00412a6c = 9;
    _DAT_00412a70 = 0;
    DVar1 = 0xffffffff;
  }
  return DVar1;
}


