/*
 * Decompiled function: __chsize
 * Entry Point: 004e57a0
 * Size: 675 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __chsize
   
   Library: Visual Studio 1998 Debug */

int __cdecl __chsize(int arg1,long arg2)

{
  code *pcVar1;
  int iVar2;
  long arg_2;
  long lVar3;
  int iVar4;
  HANDLE hFile;
  BOOL BVar5;
  uint local_1024;
  int local_1020;
  uint local_101c;
  undefined1 local_1008 [4064];
  undefined4 uStackY_28;
  
  Mem_AllocOrFree_004ddee0();
  local_1020 = 0;
  if (((uint)arg1 < DAT_006c1c90) &&
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg1 & 0xffffffe0U) >> 3)) + 4 +
                (arg1 & 0x1fU) * 8) & 1) != 0)) {
    if (arg2 < 0) {
      uStackY_28 = 0x4e5829;
      iVar2 = __CrtDbgReport(2,0x4f0eb8,0x7e,0,"size >= 0");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        iVar2 = (*pcVar1)();
        return iVar2;
      }
    }
    arg_2 = __lseek(arg1,0,1);
    if ((arg_2 == -1) || (lVar3 = __lseek(arg1,0,2), lVar3 == -1)) {
      local_1020 = -1;
    }
    else {
      local_101c = arg2 - lVar3;
      if ((int)local_101c < 1) {
        if ((int)local_101c < 0) {
          __lseek(arg1,arg2,0);
          hFile = (HANDLE)__get_osfhandle(arg1);
          BVar5 = SetEndOfFile(hFile);
          if (BVar5 == 0) {
            local_1020 = -1;
          }
          else {
            local_1020 = 0;
          }
          if (local_1020 == -1) {
            DAT_00509420 = 0xd;
            DAT_00509424 = GetLastError();
          }
        }
      }
      else {
        _memset(local_1008,0,0x1000);
        iVar2 = __setmode(arg1,0x8000);
        do {
          if ((int)local_101c < 0x1000) {
            local_1024 = local_101c;
          }
          else {
            local_1024 = 0x1000;
          }
          iVar4 = __write(arg1,local_1008,local_1024);
          if (iVar4 == -1) {
            if (DAT_00509424 == 5) {
              DAT_00509420 = 0xd;
            }
            local_1020 = -1;
            break;
          }
          local_101c = local_101c - iVar4;
        } while (0 < (int)local_101c);
        __setmode(arg1,iVar2);
      }
      __lseek(arg1,arg_2,0);
    }
  }
  else {
    DAT_00509420 = 9;
    local_1020 = -1;
  }
  return local_1020;
}


