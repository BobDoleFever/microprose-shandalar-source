/*
 * Decompiled function: FUN_00471d16
 * Entry Point: 00471d16
 * Size: 722 bytes
 */
#include "magic.h"


void FUN_00471d16(uint arg_1)

{
  int iVar1;
  int aiStack_100 [16];
  int aiStack_c0 [16];
  uint local_80;
  int local_70;
  int local_64;
  int local_50;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  if (g_IsAiThinking != 1) {
    Ai_Subsystem_004cc9c5(0,0xff);
    local_80 = arg_1;
    local_2c = 1 - arg_1;
    local_70 = 0;
    local_30 = 0;
    for (local_50 = 0; local_50 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_50 = local_50 + 1) {
      local_38 = *(int *)(&g_CardSlot_CardId + local_50 * 0x120 + arg_1 * 0x5b20);
      if ((local_38 != -1) && (((&g_CardSlot_Flags)[local_50 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
        local_64 = FUN_00473179(arg_1,local_50,0x32,0xffffffff);
        aiStack_100[local_30] = local_50;
        aiStack_c0[local_30] = local_64;
        local_30 = local_30 + 1;
        if (local_70 < local_64) {
          local_70 = local_64;
        }
      }
    }
    local_20 = 0;
    while ((local_20 == 0 && (iVar1 = FUN_00472a0a(local_2c), iVar1 != 0))) {
      iVar1 = Action_ValidateTarget_00405802
                        (local_2c,local_2c,local_2c,0x2200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0
                         ,0,0x11,s_Choose_blockers_00525ca4,2,&local_28);
      if (iVar1 == 0) {
        local_20 = 1;
      }
      else {
        iVar1 = Action_ValidateTarget_00405802
                          (local_2c,local_80,local_80,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,
                           0,2,0,s_Block_which_attacker__00525cb4,1,&local_1c);
        if (iVar1 != 0) {
          iVar1 = FUN_00472e08(local_28,local_24,local_1c,local_18);
          if (iVar1 == 0) {
            if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_block__00525ccc);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_00525cdc);
            }
          }
          else {
            local_3c = (int)(char)(&g_CardSlot_ColorMask)[local_1c * 0x5b20 + local_18 * 0x120];
            if (local_3c == -1) {
              (&g_CardSlot_ColorMask)[local_28 * 0x5b20 + local_24 * 0x120] = (undefined1)local_18;
            }
            else {
              (&g_CardSlot_ColorMask)[local_28 * 0x5b20 + local_24 * 0x120] =
                   (&g_CardSlot_ColorMask)[local_1c * 0x5b20 + local_18 * 0x120];
            }
            *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) | 8;
            Ai_Subsystem_004cc9c5(0,0xff);
          }
        }
      }
    }
  }
  return;
}


