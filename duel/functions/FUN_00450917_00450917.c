/*
 * Decompiled function: FUN_00450917
 * Entry Point: 00450917
 * Size: 283 bytes
 */
#include "duel.h"


byte FUN_00450917(int arg1,int arg2)

{
  byte bVar1;
  
  bVar1 = ((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0;
  if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) {
    bVar1 = bVar1 | 2;
  }
  if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] != -1) {
    bVar1 = bVar1 | 8;
  }
  if (((&DAT_006826d2)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (*(int *)(&DAT_006826e8 + arg2 * 0x120 + arg1 * 0x5b20) != -1)) {
    bVar1 = bVar1 | 0x10;
  }
  return bVar1;
}


