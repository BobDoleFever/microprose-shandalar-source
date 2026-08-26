/*
 * Decompiled function: Card_NettlingImp_IsTargetEligible
 * Entry Point: 004db8c9
 * Size: 339 bytes
 */
#include "magic.h"


undefined4 Card_NettlingImp_IsTargetEligible(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  if (((arg_3 == 0x1a) && (g_DefendingPlayer == arg_1)) &&
     (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    iVar2 = 1 - arg_1;
    bVar1 = true;
    for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[iVar2]; local_8 = local_8 + 1) {
      iVar3 = FUN_00471c32(iVar2,local_8);
      if ((iVar3 != 0) && ((char)(&g_CardSlot_ColorMask)[local_8 * 0x120 + iVar2 * 0x5b20] == arg_2)
         ) {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      iVar2 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,arg_1,arg_2);
      if (iVar2 != -1) {
        *(undefined2 *)(&DAT_006a5f48 + arg_1 * 0x5b20 + iVar2 * 0x120) = 2;
        *(undefined2 *)(&DAT_006a5f4a + arg_1 * 0x5b20 + iVar2 * 0x120) = 0;
      }
    }
  }
  return 0;
}


