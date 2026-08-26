/*
 * Decompiled function: Pic_Subsystem_0044867e
 * Entry Point: 0044867e
 * Size: 546 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044867e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_1 != -1) && (arg_2 != -1)) &&
     (((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x80) == 0)) {
    *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80;
    iVar1 = *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
    if (iVar1 != -1) {
      if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0) {
        arg_3 = 3;
      }
      if (((((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) == 0) && (arg_3 != 3)) &&
         ((arg_3 != 4 &&
          ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 3) != 0 &&
           ((&g_MasterCardColorTable)[iVar1 * 0x34] != -0x80)))))) {
        (&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_3;
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 2;
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) == 0) {
          Pic_Subsystem_0044895f(arg_1,arg_2);
        }
        else {
          *(undefined4 *)(&DAT_006a5f80 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xd6;
        }
        DAT_00695f18 = Pic_Subsystem_0044895f;
      }
      else {
        (&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_3;
        Pic_Subsystem_0044895f(arg_1,arg_2);
      }
    }
  }
  return;
}


