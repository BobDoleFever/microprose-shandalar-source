/*
 * Decompiled function: AVI_ShutdownSubsystem
 * Entry Point: 10001926
 * Size: 43 bytes
 */
#include "magvid.h"


void __fastcall AVI_ShutdownSubsystem(int *ptr_1)

{
  thunk_FUN_10001c16(ptr_1);
  thunk_FUN_100019c7((int)ptr_1);
  AVIFileExit();
  return;
}


