/*
 * Decompiled function: thunk_FUN_10032018
 * Entry Point: 100012f8
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10032018(HANDLE arg_1)

{
  char acStack_254 [500];
  HANDLE pvStack_60;
  uint8_t auStack_5c [20];
  int iStack_48;
  HANDLE pvStack_10;
  int iStack_c;
  int iStack_8;
  
  if (arg_1 != (HANDLE)0x0) {
    GetObjectA(arg_1,0x54,auStack_5c);
    pvStack_60 = pvStack_10;
    iStack_8 = iStack_48 + iStack_c;
    DeleteObject(arg_1);
    if (pvStack_60 != (HANDLE)0x0) {
      CloseHandle(pvStack_60);
    }
  }
  if (DAT_10176354 != 0) {
    sprintf(acStack_254,s__08x_DestroyDIBSection__file_map_100466b4,arg_1,pvStack_60);
    OutputDebugStringA(acStack_254);
  }
  return;
}


