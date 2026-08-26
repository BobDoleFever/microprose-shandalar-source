/*
 * Decompiled function: FUN_0048ea81
 * Entry Point: 0048ea81
 * Size: 91 bytes
 */
#include "magic.h"


void FUN_0048ea81(int arg_1)

{
  byte bVar1;
  
  do {
    bVar1 = FUN_0040a1d2(3);
  } while ((*(uint *)(&DAT_0067f010 + arg_1 * 0x30) & 1 << (bVar1 & 0x1f)) != 0);
  *(uint *)(&DAT_0067f010 + arg_1 * 0x30) =
       *(uint *)(&DAT_0067f010 + arg_1 * 0x30) | 1 << (bVar1 & 0x1f);
  Castle_Process_00492ddf(arg_1);
  return;
}


