/*
 * Decompiled function: __NMSG_WRITE
 * Entry Point: 004030a0
 * Size: 537 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 1998 Debug */

void __cdecl __NMSG_WRITE(int arg_1)

{
  code *char_ptr_1;
  int val_2;
  size_t len_3;
  DWORD DVar4;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  HANDLE local_1b8;
  uint32_t local_1b4 [40];
  uint32_t local_114 [65];
  uint32_t *local_10;
  uint32_t local_c;
  DWORD local_8;
  
  for (local_c = 0; (local_c < 0x12 && (*(int *)(&DAT_00412d90 + local_c * 8) != arg_1));
      local_c = local_c + 1) {
  }
  if (*(int *)(&DAT_00412d90 + local_c * 8) == arg_1) {
    if ((arg_1 != 0xfc) &&
       (val_2 = __CrtDbgReport(1,0,0,0,(&PTR_s_R6002___floating_point_not_loade_00412d94)
                                       [local_c * 2]), val_2 == 1)) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    if ((DAT_00412a64 == 1) || ((DAT_00412a64 == 0 && (DAT_00412a68 == 1)))) {
      if ((DAT_004156c0 == 0) || (*(int *)(DAT_004156c0 + 0x10) == -1)) {
        local_1b8 = GetStdHandle(0xfffffff4);
      }
      else {
        local_1b8 = *(HANDLE *)(DAT_004156c0 + 0x10);
      }
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &local_8;
      len_3 = _strlen((&PTR_s_R6002___floating_point_not_loade_00412d94)[local_c * 2]);
      WriteFile(local_1b8,(&PTR_s_R6002___floating_point_not_loade_00412d94)[local_c * 2],len_3,
                lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (arg_1 != 0xfc) {
      DVar4 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_114,0x104);
      if (DVar4 == 0) {
        FUN_00405450(local_114,(uint32_t *)"<program name unknown>");
      }
      local_10 = local_114;
      len_3 = _strlen((char *)local_10);
      if (0x3c < len_3 + 1) {
        len_3 = _strlen((char *)local_114);
        local_10 = (uint32_t *)((int)local_10 + (len_3 - 0x3b));
        _strncpy((char *)local_10,"...",3);
      }
      FUN_00405450(local_1b4,(uint32_t *)"Runtime Error!\n\nProgram: ");
      FUN_00405460(local_1b4,local_10);
      FUN_00405460(local_1b4,(uint32_t *)&DAT_00410348);
      FUN_00405460(local_1b4,(uint32_t *)(&PTR_s_R6002___floating_point_not_loade_00412d94)[local_c * 2]
                  );
      ___crtMessageBoxA((LPCSTR)local_1b4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}


