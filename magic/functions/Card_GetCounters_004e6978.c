/*
 * Decompiled function: Card_GetCounters
 * Entry Point: 004e6978
 * Size: 52 bytes
 */
#include "magic.h"


uint Card_GetCounters(int arg1,int arg2)

{
  return *(uint *)(&DAT_006a5f7c + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
}


