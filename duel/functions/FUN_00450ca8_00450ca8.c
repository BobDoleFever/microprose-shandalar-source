/*
 * Decompiled function: FUN_00450ca8
 * Entry Point: 00450ca8
 * Size: 110 bytes
 */
#include "duel.h"


char * FUN_00450ca8(int arg1,int arg2)

{
  char *pcVar1;
  
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    pcVar1 = &DAT_004f85f8;
  }
  else {
    pcVar1 = s_Swamp_004ff581 + *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34;
  }
  return pcVar1;
}


