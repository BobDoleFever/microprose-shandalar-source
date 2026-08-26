/*
 * Decompiled function: __NMSG_WRITE
 * Entry Point: 004e86e0
 * Size: 537 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 1998 Debug */

void __cdecl __NMSG_WRITE(int arg_1)

{
  code *pcVar1;
  int iVar2;
  size_t sVar3;
  DWORD DVar4;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  HANDLE local_1b8;
  uint local_1b4 [40];
  uint local_114 [65];
  uint *local_10;
  uint local_c;
  DWORD local_8;
  
  for (local_c = 0; (local_c < 0x12 && (*(int *)(&DAT_0050a680 + local_c * 8) != arg_1));
      local_c = local_c + 1) {
  }
  if (*(int *)(&DAT_0050a680 + local_c * 8) == arg_1) {
    if ((arg_1 != 0xfc) &&
       (iVar2 = __CrtDbgReport(1,0,0,0,(&PTR_s_R6002___floating_point_not_loade_0050a684)
                                       [local_c * 2]), iVar2 == 1)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_005096e8 == 1) || ((DAT_005096e8 == 0 && (DAT_005096ec == 1)))) {
      if ((DAT_006c1b90 == 0) || (*(int *)(DAT_006c1b90 + 0x10) == -1)) {
        local_1b8 = GetStdHandle(0xfffffff4);
      }
      else {
        local_1b8 = *(HANDLE *)(DAT_006c1b90 + 0x10);
      }
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &local_8;
      sVar3 = _strlen((&PTR_s_R6002___floating_point_not_loade_0050a684)[local_c * 2]);
      WriteFile(local_1b8,(&PTR_s_R6002___floating_point_not_loade_0050a684)[local_c * 2],sVar3,
                lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (arg_1 != 0xfc) {
      DVar4 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_114,0x104);
      if (DVar4 == 0) {
        Mem_AllocOrFree_004d9630(local_114,(uint *)"<program name unknown>");
      }
      local_10 = local_114;
      sVar3 = _strlen((char *)local_10);
      if (0x3c < sVar3 + 1) {
        sVar3 = _strlen((char *)local_114);
        local_10 = (uint *)((int)local_10 + (sVar3 - 0x3b));
        _strncpy((char *)local_10,"...",3);
      }
      Mem_AllocOrFree_004d9630(local_1b4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_004d9640(local_1b4,local_10);
      FUN_004d9640(local_1b4,(uint *)&DAT_004f0218);
      FUN_004d9640(local_1b4,(uint *)(&PTR_s_R6002___floating_point_not_loade_0050a684)[local_c * 2]
                  );
      ___crtMessageBoxA((LPCSTR)local_1b4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


