/*
 * Decompiled function: FUN_004767ee
 * Entry Point: 004767ee
 * Size: 470 bytes
 */
#include "magic.h"


void FUN_004767ee(int arg_1)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_10;
  
  iVar2 = 1 - arg_1;
  for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_10 = local_10 + 1) {
    if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + arg_1 * 0x5b20) != -1) &&
       (((byte)*(undefined4 *)(&g_CardSlot_Flags + local_10 * 0x120 + arg_1 * 0x5b20) & 6) == 6)) {
      bVar1 = false;
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[iVar2]; local_18 = local_18 + 1)
      {
        if ((*(int *)(&g_CardSlot_CardId + iVar2 * 0x5b20 + local_18 * 0x120) != -1) &&
           ((char)(&g_CardSlot_ColorMask)[iVar2 * 0x5b20 + local_18 * 0x120] == local_10)) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[arg_1];
            local_18 = local_18 + 1) {
          if ((local_18 == local_10) ||
             (((char)(&g_CardSlot_ColorMask)[local_18 * 0x120 + arg_1 * 0x5b20] == local_10 &&
              (((byte)*(undefined4 *)(&g_CardSlot_Flags + local_18 * 0x120 + arg_1 * 0x5b20) & 6) ==
               6)))) {
            *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + arg_1 * 0x5b20) | 0x200;
          }
        }
      }
    }
  }
  return;
}


