/*
 * Decompiled function: FUN_00417bb9
 * Entry Point: 00417bb9
 * Size: 221 bytes
 */
#include "magic.h"


undefined4 FUN_00417bb9(int arg1,int arg2)

{
  int iVar1;
  
  if (((&g_CardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) == 0)) {
    iVar1 = FUN_00410cc0(DAT_00538740,DAT_0053873c,DAT_006a2854,arg1,arg2);
    if (iVar1 != -1) {
      *(undefined2 *)(&DAT_006a5f48 + DAT_00538740 * 0x5b20 + iVar1 * 0x120) = 0;
      *(undefined2 *)(&DAT_006a5f4a + DAT_00538740 * 0x5b20 + iVar1 * 0x120) = 3;
    }
  }
  return 0;
}


