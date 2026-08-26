/*
 * Decompiled function: FUN_004472ad
 * Entry Point: 004472ad
 * Size: 400 bytes
 */
#include "duel.h"


byte FUN_004472ad(int arg1,int arg2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    bVar2 = ((&DAT_0060162e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0;
    if ((((&DAT_0060162c)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
       (((&DAT_004ff594)[*(int *)(&DAT_00601624 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x47) != 4
       )) {
      bVar2 = bVar2 | 2;
    }
    if (((&DAT_0060162c)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
      bVar2 = bVar2 | 4;
    }
    if ((&DAT_0060163e)[arg2 * 0x120 + arg1 * 0x5b20] != -1) {
      bVar2 = bVar2 | 8;
    }
    if (((&DAT_00601632)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
       (*(int *)(&DAT_00601648 + arg2 * 0x120 + arg1 * 0x5b20) != -1)) {
      bVar2 = bVar2 | 0x10;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    bVar2 = 0;
  }
  return bVar2;
}


