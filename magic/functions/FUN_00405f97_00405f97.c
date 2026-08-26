/*
 * Decompiled function: FUN_00405f97
 * Entry Point: 00405f97
 * Size: 324 bytes
 */
#include "magic.h"


undefined4 FUN_00405f97(int arg1,int arg2)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((arg2 == 0) &&
     ((arg1 == 0 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2c0)))) {
    local_8 = 1;
  }
  if ((arg2 == 1) &&
     ((arg1 == 1 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2c4)))) {
    local_8 = 1;
  }
  if ((arg2 == 2) &&
     ((arg1 == 2 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2c8)))) {
    local_8 = 1;
  }
  if ((arg2 == 3) &&
     ((arg1 == 3 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2cc)))) {
    local_8 = 1;
  }
  if ((arg2 == 4) &&
     ((arg1 == 4 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2d0)))) {
    local_8 = 1;
  }
  return local_8;
}


