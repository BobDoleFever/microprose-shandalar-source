/*
 * Decompiled function: Ai_Subsystem_004cc9c5
 * Entry Point: 004cc9c5
 * Size: 734 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cc9c5(int arg1,int arg2)

{
  undefined4 uVar1;
  int local_10;
  int local_8;
  
  Ai_Subsystem_004ccca3();
  if ((DAT_0063ee10 == 0) && (g_PlayerManaPool == -1)) {
    DAT_0063ee78 = 0;
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
        FUN_00473179(local_8,local_10,0x3c,0xffffffff);
      }
    }
  }
  Ai_Subsystem_004cced8();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
        FUN_00473179(local_8,local_10,0x34,0xffffffff);
        FUN_00473179(local_8,local_10,0x32,0xffffffff);
        FUN_00473179(local_8,local_10,0x33,0xffffffff);
      }
    }
  }
  if (g_IsAiThinking != 1) {
    DAT_006a4920 = 0;
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8];
          local_10 = local_10 + 1) {
        if (*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) {
          uVar1 = Pic_Subsystem_00447b57(local_8,local_10);
          *(undefined4 *)(&DAT_006a5f84 + local_10 * 0x120 + local_8 * 0x5b20) = uVar1;
        }
      }
    }
    if (DAT_0063ee18 == 0) {
      Pic_Load_combat2_0048369c(arg1,arg2);
    }
    else {
      SendMessageA(g_MainAppHwnd,0x464,0xffff,0);
    }
  }
  return;
}


