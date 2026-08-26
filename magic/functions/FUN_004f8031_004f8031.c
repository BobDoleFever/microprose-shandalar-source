/*
 * Decompiled function: FUN_004f8031
 * Entry Point: 004f8031
 * Size: 521 bytes
 */
#include "magic.h"


undefined4 FUN_004f8031(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth - ((&DAT_006b3008)[arg_1] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      local_10 = 0;
      local_8 = g_DefendingPlayer;
      while (local_10 < 2) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = FUN_00471bc0(local_8,local_c);
          if (iVar2 != 0) {
            Pic_Subsystem_0045245e
                      (local_8,*(undefined4 *)
                                (&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20));
            *(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
          }
        }
        local_c = 0;
        while ((local_c < 500 && (*(int *)(&DAT_006ff710 + local_c * 4 + local_8 * 2000) != -1))) {
          Pic_Subsystem_0045245e
                    (local_8,*(undefined4 *)(&DAT_006ff710 + local_c * 4 + local_8 * 2000));
          local_c = local_c + 1;
        }
        for (local_c = 0; local_c < 500; local_c = local_c + 1) {
          *(undefined4 *)(&DAT_006ff710 + local_c * 4 + local_8 * 2000) = 0xffffffff;
        }
        Ai_Subsystem_004cc9c5(0,0x30);
        Pic_Subsystem_00452276(local_8);
        FUN_004f823a(local_8,7);
        local_10 = local_10 + 1;
        if (g_DefendingPlayer == 0) {
          local_8 = local_8 + 1;
        }
        else {
          local_8 = local_8 + -1;
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


