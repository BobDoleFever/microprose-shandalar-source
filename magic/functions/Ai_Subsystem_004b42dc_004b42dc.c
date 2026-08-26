/*
 * Decompiled function: Ai_Subsystem_004b42dc
 * Entry Point: 004b42dc
 * Size: 1891 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004b42dc(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_10;
  int local_c;
  uint local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  local_8 = memcmp(&DAT_0068a730,&g_ActiveCardsInPlay,0xb640);
  memcpy(&DAT_0068a730,&g_ActiveCardsInPlay,0xb640);
  if ((g_PlayerActiveCardCount != DAT_006a29c8) || (DAT_006808bc != DAT_006a29cc)) {
    local_8 = 1;
  }
  DAT_006a29c8 = g_PlayerActiveCardCount;
  DAT_006a29cc = DAT_006808bc;
  if ((g_PlayerCreatureCount != DAT_006a3f7c) || (DAT_006a4a04 != DAT_006ff194)) {
    local_8 = 1;
  }
  DAT_006a3f7c = g_PlayerCreatureCount;
  DAT_006ff194 = DAT_006a4a04;
  if ((DAT_00696870 != DAT_00695ed8) || (DAT_00696874 != DAT_007006d8)) {
    local_8 = 1;
  }
  DAT_00695ed8 = DAT_00696870;
  DAT_007006d8 = DAT_00696874;
  uVar3 = memcmp(&DAT_0069f6e0,&DAT_0063ee90,0x1c);
  uVar4 = memcmp(&DAT_00695ee0,&DAT_0063eeb0,0x1c);
  memcpy(&DAT_0069f6e0,&DAT_0063ee90,0x1c);
  memcpy(&DAT_00695ee0,&DAT_0063eeb0,0x1c);
  uVar5 = memcmp(&DAT_00695f20,&DAT_006ff710,2000);
  uVar6 = memcmp(&DAT_006fd400,&DAT_006ffee0,2000);
  DAT_006ff1a0 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006ff710 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006ff710 + local_c * 4));
    (&DAT_00695f20)[DAT_006ff1a0] = uVar7;
    DAT_006ff1a0 = DAT_006ff1a0 + 1;
  }
  DAT_007006b4 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006ffee0 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006ffee0 + local_c * 4));
    (&DAT_006fd400)[DAT_007006b4] = uVar7;
    DAT_007006b4 = DAT_007006b4 + 1;
  }
  uVar8 = memcmp(&DAT_006fe4a0,&DAT_006b1590,2000);
  uVar9 = memcmp(&DAT_006a4f80,&DAT_006b1d60,2000);
  DAT_006ff2e4 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006b1590 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006b1590 + local_c * 4));
    (&DAT_006fe4a0)[DAT_006ff2e4] = uVar7;
    DAT_006ff2e4 = DAT_006ff2e4 + 1;
  }
  DAT_006b2d34 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006b1d60 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006b1d60 + local_c * 4));
    (&DAT_006a4f80)[DAT_006b2d34] = uVar7;
    DAT_006b2d34 = DAT_006b2d34 + 1;
  }
  uVar10 = memcmp(&DAT_006b2550,&DAT_0069e730,2000);
  uVar11 = memcmp(&DAT_006fdbe0,&DAT_0069ef00,2000);
  local_8 = local_8 | uVar3 | uVar4 | uVar5 | uVar6 | uVar8 | uVar9 | uVar10 | uVar11;
  DAT_006b2d30 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0069e730 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_0069e730 + local_c * 4));
    (&DAT_006b2550)[DAT_006b2d30] = uVar7;
    DAT_006b2d30 = DAT_006b2d30 + 1;
  }
  DAT_006b2e20 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0069ef00 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_0069ef00 + local_c * 4));
    (&DAT_006fdbe0)[DAT_006b2e20] = uVar7;
    DAT_006b2e20 = DAT_006b2e20 + 1;
  }
  DAT_006b2e28 = 0;
  for (local_c = 0; ((&DAT_006fecc0)[local_c * 2] != -1 && (local_c < 0x20)); local_c = local_c + 1)
  {
    if (*(int *)(&DAT_00695d70 + local_c * 4) != 0) {
      iVar1 = (&DAT_006fecc0)[local_c * 2];
      iVar2 = *(int *)(&DAT_006fecc4 + local_c * 8);
      (&DAT_006a29e0)[DAT_006b2e28 * 0x2b] = iVar1;
      (&DAT_006a29e4)[DAT_006b2e28 * 0x2b] = iVar2;
      (&DAT_006a2a88)[DAT_006b2e28 * 0x2b] =
           (int)(char)(&g_CardSlot_TurnPlayed)[iVar2 * 0x120 + iVar1 * 0x5b20];
      for (local_10 = 0; local_10 < (char)(&g_CardSlot_TurnPlayed)[iVar2 * 0x120 + iVar1 * 0x5b20];
          local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_006a29e8 + local_10 * 8 + DAT_006b2e28 * 0xac) =
             *(undefined4 *)
              (&g_CardSlot_CombatTarget + iVar2 * 0x120 + iVar1 * 0x5b20 + local_10 * 8);
        *(undefined4 *)(&DAT_006a29ec + local_10 * 8 + DAT_006b2e28 * 0xac) =
             *(undefined4 *)
              (&g_CardSlot_AttachedAura + iVar2 * 0x120 + iVar1 * 0x5b20 + local_10 * 8);
      }
      DAT_006b2e28 = DAT_006b2e28 + 1;
    }
  }
  DAT_0069f740 = 0;
  for (local_c = 0; (local_c < 0x10 && ((&DAT_006b2dd0)[local_c] != -1)); local_c = local_c + 1) {
    DAT_0069f740 = DAT_0069f740 + 1;
  }
  memcpy(&DAT_006fec70,&DAT_006b2dd0,0x40);
  DAT_00701004 = 0;
  for (local_c = 0; (local_c < 0x10 && ((&DAT_006b2d90)[local_c] != -1)); local_c = local_c + 1) {
    DAT_00701004 = DAT_00701004 + 1;
  }
  memcpy(&DAT_006ff6d0,&DAT_006b2d90,0x40);
  for (local_c = 0; local_c < 0x26; local_c = local_c + 1) {
    if (*(int *)(&DAT_00696740 + local_c * 4) != *(int *)(&DAT_006fedd0 + local_c * 4)) {
      local_8 = local_8 | 1;
    }
    if (*(int *)(&DAT_006967d8 + local_c * 4) != *(int *)(&DAT_006a4940 + local_c * 4)) {
      local_8 = local_8 | 1;
    }
    *(uint *)(&DAT_006fedd0 + local_c * 4) = *(uint *)(&DAT_00696740 + local_c * 4) & 1;
    *(uint *)(&DAT_006a4940 + local_c * 4) = *(uint *)(&DAT_006967d8 + local_c * 4) & 1;
  }
  if (DAT_0063ee10 != DAT_0068077c) {
    local_8 = 1;
  }
  DAT_0068077c = DAT_0063ee10;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return local_8;
}


