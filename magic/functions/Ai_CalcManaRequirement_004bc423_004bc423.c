/*
 * Decompiled function: Ai_CalcManaRequirement_004bc423
 * Entry Point: 004bc423
 * Size: 675 bytes
 */
#include "magic.h"


undefined4 Ai_CalcManaRequirement_004bc423(void)

{
  int arg2;
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int local_18;
  int local_c;
  
  local_18 = 0;
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    iVar1 = abs((&DAT_006b2d40)[local_c]);
    local_18 = local_18 + iVar1;
  }
  if (local_18 == 0) {
    g_OverworldWorldState = 0;
  }
  else {
    local_18 = 0;
    g_OverworldWorldState = 0;
    uVar2 = FUN_00474d4a();
    if (uVar2 != 0xffffffff) {
      iVar1 = *(int *)(&DAT_006fecb8 + DAT_006a3f78 * 8);
      arg2 = *(int *)(&DAT_006fecbc + DAT_006a3f78 * 8);
      uVar2 = uVar2 >> 0x10 & 0xff;
      if (uVar2 == 0x71) {
        strcpy(&g_OverworldWorldState,s_CASTING__0052d698);
        Ai_Subsystem_004b90de(iVar1,arg2);
      }
      if (uVar2 == 0x72) {
        strcpy(&g_OverworldWorldState,s_ACTIVATING__0052d6a4);
        Ai_Subsystem_004b90de(iVar1,arg2);
      }
      if (uVar2 == 0x7e) {
        strcpy(&g_OverworldWorldState,s_PROCESSING__0052d6b4);
        Ai_Subsystem_004b90de(iVar1,arg2);
      }
    }
    strcat(&g_OverworldWorldState,s___tap_0052d6c4);
    for (local_c = 6; -1 < local_c; local_c = local_c + -1) {
      if ((&DAT_006b2d40)[local_c] != 0) {
        if (local_18 != 0) {
          strcat(&g_OverworldWorldState,s_and_0052d6cc);
        }
        if ((&DAT_006b2d40)[local_c] == -1) {
          strcat(&g_OverworldWorldState,s_X__now_0052d6d4);
          pcVar3 = _itoa(g_TurnCounter,&DAT_00556c40,10);
          strcat(&g_OverworldWorldState,pcVar3);
          if (g_OverworldPlayerCoordY != -1) {
            strcat(&g_OverworldWorldState,s___max_0052d6dc);
            pcVar3 = _itoa(g_OverworldPlayerCoordY,&DAT_00556c40,10);
            strcat(&g_OverworldWorldState,pcVar3);
          }
          strcat(&g_OverworldWorldState,&DAT_0052d6e4);
        }
        else {
          pcVar3 = _itoa((&DAT_006b2d40)[local_c],&DAT_00556c40,10);
          strcat(&g_OverworldWorldState,pcVar3);
        }
        strcat(&g_OverworldWorldState,&DAT_0052d6e8);
        pcVar3 = (char *)Mem_AllocOrFree_00473d7e(local_c);
        strcat(&g_OverworldWorldState,pcVar3);
        local_18 = local_18 + 1;
      }
    }
    strcat(&g_OverworldWorldState,s_mana__0052d6ec);
  }
  return 0;
}


