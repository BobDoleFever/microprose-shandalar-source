/*
 * Decompiled function: FUN_005064e9
 * Entry Point: 005064e9
 * Size: 139 bytes
 */
#include "magic.h"


undefined4 FUN_005064e9(int arg1,int arg2)

{
  DAT_006ff4ac = 1;
  DAT_006ff2d4 = 0xffffffff;
  Magic_TriggerCardEvent(arg1,arg2,0x6d,1 - arg1,0xffffffff);
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) {
    FUN_00473e69(arg1,arg2,0x81);
  }
  DAT_006ff4ac = 0;
  return DAT_006ff2d4;
}


