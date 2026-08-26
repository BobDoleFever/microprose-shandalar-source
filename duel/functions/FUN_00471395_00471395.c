/*
 * Decompiled function: FUN_00471395
 * Entry Point: 00471395
 * Size: 145 bytes
 */
#include "duel.h"


void FUN_00471395(HANDLE arg_1)

{
  char local_254 [500];
  HANDLE local_60;
  undefined1 local_5c [20];
  int local_48;
  HANDLE local_10;
  int local_c;
  int local_8;
  
  if (arg_1 != (HANDLE)0x0) {
    GetObjectA(arg_1,0x54,local_5c);
    local_60 = local_10;
    local_8 = local_48 + local_c;
    DeleteObject(arg_1);
    if (local_60 != (HANDLE)0x0) {
      CloseHandle(local_60);
    }
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_254,s__08x_DestroyDIBSection__file_map_004f9804,arg_1,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}


