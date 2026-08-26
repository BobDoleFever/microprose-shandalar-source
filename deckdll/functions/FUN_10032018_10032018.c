/*
 * Decompiled function: FUN_10032018
 * Entry Point: 10032018
 * Size: 146 bytes
 */
#include "deckdll.h"


void FUN_10032018(HANDLE arg_1)

{
  char local_254 [500];
  HANDLE local_60;
  uint8_t local_5c [20];
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
  if (DAT_10176354 != 0) {
    sprintf(local_254,s__08x_DestroyDIBSection__file_map_100466b4,arg_1,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}


