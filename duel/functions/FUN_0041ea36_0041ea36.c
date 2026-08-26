/*
 * Decompiled function: FUN_0041ea36
 * Entry Point: 0041ea36
 * Size: 324 bytes
 */
#include "duel.h"


undefined4 FUN_0041ea36(int arg1,int arg2)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((arg2 == 0) && ((arg1 == 0 || (*(int *)(&DAT_004ff590 + arg1 * 0x34) == DAT_0068f0e0)))) {
    local_8 = 1;
  }
  if ((arg2 == 1) && ((arg1 == 1 || (*(int *)(&DAT_004ff590 + arg1 * 0x34) == DAT_0068f0e4)))) {
    local_8 = 1;
  }
  if ((arg2 == 2) && ((arg1 == 2 || (*(int *)(&DAT_004ff590 + arg1 * 0x34) == DAT_0068f0e8)))) {
    local_8 = 1;
  }
  if ((arg2 == 3) && ((arg1 == 3 || (*(int *)(&DAT_004ff590 + arg1 * 0x34) == DAT_0068f0ec)))) {
    local_8 = 1;
  }
  if ((arg2 == 4) && ((arg1 == 4 || (*(int *)(&DAT_004ff590 + arg1 * 0x34) == DAT_0068f0f0)))) {
    local_8 = 1;
  }
  return local_8;
}


