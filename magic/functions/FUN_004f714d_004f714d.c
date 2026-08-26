/*
 * Decompiled function: FUN_004f714d
 * Entry Point: 004f714d
 * Size: 355 bytes
 */
#include "magic.h"


undefined4 FUN_004f714d(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x60;
    }
    if (arg_3 == 0x71) {
      if (DAT_006ff2d8 == -1) {
        bVar1 = false;
        local_c = 0;
        while ((local_c < 2 && (!bVar1))) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c];
              local_8 = local_8 + 1) {
            if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) == DAT_006a4b64)
               && (((&DAT_006a5f69)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              bVar1 = true;
            }
          }
          local_c = local_c + 1;
        }
        if (!bVar1) {
          DAT_006ff2d8 = arg_1;
        }
      }
      iVar3 = FUN_00410cc0(arg_1,arg_2,DAT_006a4b64,-1,-1);
      *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + arg_1 * 0x5b20) | 0x120;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


