/*
 * Decompiled function: FUN_00476675
 * Entry Point: 00476675
 * Size: 377 bytes
 */
#include "magic.h"


undefined4 FUN_00476675(int arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  uint local_8;
  
  if (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) == 0) {
    uVar1 = 0;
  }
  else {
    local_c = 0;
    for (local_8 = 1; (int)local_8 < 7; local_8 = local_8 + 1) {
      if ((&DAT_006a603c)[local_8 + arg2 * 0x120 + arg1 * 0x5b20] != '\0') {
        iVar2 = FUN_0040d949(arg1,local_8,
                             (int)(char)(&DAT_006a603c)[local_8 + arg2 * 0x120 + arg1 * 0x5b20]);
        if (iVar2 == 0) {
          return 0;
        }
        local_c = local_c + (char)(&DAT_006a603c)[local_8 + arg2 * 0x120 + arg1 * 0x5b20];
      }
    }
    iVar2 = FUN_0040d949(arg1,7,(char)(&DAT_006a603c)[arg1 * 0x5b20 + arg2 * 0x120] + local_c);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      Magic_TriggerCardEvent(arg1,arg2,0x88,1 - arg1,0xffffffff);
      if (DAT_006b2e38 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


