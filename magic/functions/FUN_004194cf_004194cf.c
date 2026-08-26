/*
 * Decompiled function: FUN_004194cf
 * Entry Point: 004194cf
 * Size: 213 bytes
 */
#include "magic.h"


void FUN_004194cf(int x,int y,int width,undefined1 arg_4)

{
  int local_8;
  
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if ((char)(&DAT_006a6029)[local_8 + y * 0x120 + x * 0x5b20] == width) {
      (&DAT_006a6029)[local_8 + y * 0x120 + x * 0x5b20] = arg_4;
    }
  }
  if ((&DAT_006a6029)[width + y * 0x120 + x * 0x5b20] == '\0') {
    (&DAT_006a6029)[width + y * 0x120 + x * 0x5b20] = arg_4;
  }
  return;
}


