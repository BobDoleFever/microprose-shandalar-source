/*
 * Decompiled function: Ai_Subsystem_004c5fc9
 * Entry Point: 004c5fc9
 * Size: 6879 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Ai_Subsystem_004c5fc9(int arg_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c [7];
  int local_450 [9];
  uint local_42c;
  int local_428;
  int local_424;
  int local_420;
  int aiStack_41c [16];
  int aiStack_3dc [16];
  undefined4 local_39c [16];
  char acStack_35c [84];
  uint local_308 [16];
  int local_2c8;
  uint local_2c4;
  uint local_2c0;
  int local_2bc;
  int local_2b8;
  uint local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  uint local_2a4;
  undefined4 local_2a0;
  int local_29c;
  undefined4 local_298 [16];
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int aiStack_244 [16];
  int local_204;
  uint local_200;
  int aiStack_1fc [14];
  int aiStack_1c4 [18];
  int local_17c;
  int aiStack_178 [16];
  int local_138;
  char acStack_134 [80];
  int local_e4;
  int aiStack_e0 [16];
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88 [16];
  undefined4 local_48 [16];
  uint local_8;
  
  Ai_Subsystem_004c4210(arg_1);
  local_2a0 = DAT_0067bdb0;
  DAT_0067bdb0 = 2;
  local_24c = g_IsAiThinking;
  if (g_IsAiThinking == 1) {
    DAT_00680790 = DAT_00680790 ^ 2;
  }
  for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_2a8 = local_2a8 + 1)
  {
    *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
  }
  Magic_ScanCards(0x15);
  local_2c4 = 0;
  local_29c = 0;
  local_248 = 0;
  local_8c = 0;
  local_254 = 0;
  local_8 = 0xffffffff;
  memset(local_46c,0,0x40);
  for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_2a8 = local_2a8 + 1)
  {
    local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + arg_1 * 0x5b20);
    if ((((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
        ((*(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg_1 * 0x5b20) & 0x20012) == 2)) &&
       (iVar2 = FUN_004726c5(arg_1,local_2a8), iVar2 != 0)) {
      if (((&DAT_006a5f3d)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
        local_8c = local_8c | 1 << ((byte)local_254 & 0x1f);
      }
      if ((((DAT_00680790 & 2) == 0) ||
          (((&DAT_006a5f3d)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0)) ||
         (((&DAT_006410f8)[local_2a8 * 0xc + arg_1 * 0x3c0] & 0x40) == 0)) {
        iVar2 = Ai_Subsystem_004cae47(arg_1,local_2a8);
        aiStack_e0[local_254] = iVar2;
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
        *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg_1 * 0x5b20) | 4;
      }
      else {
        local_29c = local_29c + *(int *)(&DAT_006410f0 + local_2a8 * 0xc + arg_1 * 0x3c0);
        local_8 = local_8 & *(uint *)(&DAT_006410f8 + local_2a8 * 0xc + arg_1 * 0x3c0);
        local_2c4 = local_2c4 | *(uint *)(&DAT_006410f8 + local_2a8 * 0xc + arg_1 * 0x3c0) & 0x200;
        aiStack_244[local_248] = local_2a8;
        local_248 = local_248 + 1;
      }
    }
  }
  local_8 = local_8 | local_2c4;
  if (7 < local_254) {
    local_470 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[DAT_00559a20];
        local_2a8 = local_2a8 + 1) {
      local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + DAT_00559a20 * 0x5b20);
      if (((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_2a8 * 0x120 + DAT_00559a20 * 0x5b20] & 0x12) != 0)) {
        local_470 = local_470 + 1;
      }
    }
    for (local_2a8 = 0; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = 0;
    }
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = *(int *)(&DAT_006410f0 + local_46c[local_2a8] * 0xc + arg_1 * 0x3c0);
    }
    while (local_470 != 0) {
      local_47c = 0;
      local_478 = 0;
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        if (local_47c < aiStack_178[local_2a8]) {
          local_47c = aiStack_178[local_2a8];
          local_478 = local_2a8;
        }
      }
      aiStack_178[local_478] = 0;
      local_470 = local_470 + -1;
    }
    local_474 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      local_474 = local_474 + aiStack_178[local_2a8];
    }
    if ((int)(&g_PlayerCreatureCount)[1 - arg_1] <= local_474) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
      }
      DAT_006a5f20 = (1 << ((byte)local_254 & 0x1f)) - 1;
      return DAT_006a5f20;
    }
  }
  if (7 < local_254) {
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      for (local_2b8 = local_2a8; local_2b8 < local_254; local_2b8 = local_2b8 + 1) {
        if (aiStack_e0[local_2a8] < aiStack_e0[local_2b8]) {
          iVar2 = aiStack_e0[local_2a8];
          aiStack_e0[local_2a8] = aiStack_e0[local_2b8];
          aiStack_e0[local_2b8] = iVar2;
          iVar2 = local_46c[local_2a8];
          local_46c[local_2a8] = local_46c[local_2b8];
          local_46c[local_2b8] = iVar2;
          uVar3 = 1 << ((byte)local_2a8 & 0x1f) & local_8c;
          uVar1 = local_8c & ~(1 << ((byte)local_2a8 & 0x1f));
          local_8c = uVar1 & ~(1 << ((byte)local_2b8 & 0x1f));
          if (uVar3 != 0) {
            local_8c = local_8c | 1 << ((byte)local_2b8 & 0x1f);
          }
          if ((1 << ((byte)local_2b8 & 0x1f) & uVar1) != 0) {
            local_8c = local_8c | 1 << ((byte)local_2a8 & 0x1f);
          }
        }
      }
    }
    if (6 < local_254) {
      local_254 = 7;
    }
    for (local_2a8 = 7; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb
      ;
    }
    memset(local_450,0,0x24);
    local_8c = 0;
    local_254 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[arg_1];
        local_2a8 = local_2a8 + 1) {
      if (((&g_CardSlot_Flags)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
        if (((&DAT_006a5f3d)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
          local_8c = local_8c | 1 << ((byte)local_254 & 0x1f);
        }
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
      }
    }
  }
  Ai_Subsystem_004c4c84(arg_1);
  memcpy(local_88,&DAT_00559f88,0x40);
  memcpy(local_48,&DAT_00559808,0x40);
  memcpy(local_308,&DAT_005595f8,0x40);
  memcpy(local_298,&DAT_00559fc8,0x40);
  memcpy(local_39c,&DAT_00559890,0x40);
  memcpy(&DAT_005598d8,&DAT_00559a98,0x40);
  memcpy(&DAT_00559778,&DAT_00559a28,0x40);
  Ai_PushBoardState();
  g_IsAiThinking = 1;
  Magic_ScanCards(199);
  g_IsAiThinking = local_24c;
  for (local_2a8 = 0; local_2a8 < 8; local_2a8 = local_2a8 + 1) {
    *(undefined4 *)(&DAT_0063edd0 + local_2a8 * 4 + DAT_00559a20 * 0x20) =
         *(undefined4 *)(&DAT_0063ee30 + local_2a8 * 4 + DAT_00559a20 * 0x20);
  }
  local_e4 = 0;
  local_90 = 0;
  for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[DAT_00559a20];
      local_2a8 = local_2a8 + 1) {
    local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + DAT_00559a20 * 0x5b20);
    if (((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
       (((&g_CardSlot_Flags)[local_2a8 * 0x120 + DAT_00559a20 * 0x5b20] & 2) != 0)) {
      aiStack_41c[local_90] = *(int *)(&DAT_006410f0 + local_2a8 * 0xc + DAT_00559a20 * 0x3c0);
      aiStack_3dc[local_90] = *(int *)(&DAT_006410f4 + local_2a8 * 0xc + DAT_00559a20 * 0x3c0);
      if (((&DAT_0051aed0)[local_204 * 0x34] & 8) != 0) {
        iVar2 = (**(code **)(&DAT_0051aec8 + local_204 * 0x34))(DAT_00559a20,local_2a8,0x39);
        aiStack_41c[local_90] = aiStack_41c[local_90] + iVar2;
      }
      if (((&DAT_0051aed0)[local_204 * 0x34] & 0x10) != 0) {
        iVar2 = (**(code **)(&DAT_0051aec8 + local_204 * 0x34))(DAT_00559a20,local_2a8,0x3a);
        aiStack_3dc[local_90] = aiStack_3dc[local_90] + iVar2;
      }
      if (local_e4 < aiStack_3dc[local_90]) {
        local_e4 = aiStack_3dc[local_90];
      }
      acStack_35c[local_2a8] = (char)local_90;
      local_90 = local_90 + 1;
    }
  }
  local_420 = -1;
  for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
    if (((local_420 == -1) && (local_88[local_2a8] < local_e4)) &&
       ((local_e4 <= local_88[local_2a8] + local_29c &&
        ((local_308[local_2a8] & local_8) == local_308[local_2a8])))) {
      local_88[local_2a8] = local_88[local_2a8] + local_29c;
      local_420 = local_46c[local_2a8];
    }
  }
  local_17c = 0;
  for (local_2b8 = 0; local_2b8 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_2b8 = local_2b8 + 1)
  {
    if (((*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg_1 * 0x5b20) != -1) &&
        (((&g_CardSlot_Flags)[local_2b8 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)) {
      aiStack_178[local_17c] = *(int *)(&DAT_006410f0 + local_2b8 * 0xc + arg_1 * 0x3c0);
      aiStack_1fc[local_17c] = *(int *)(&DAT_006410f4 + local_2b8 * 0xc + arg_1 * 0x3c0);
      aiStack_e0[local_17c] = (aiStack_1fc[local_17c] + 1) * (aiStack_178[local_17c] + 1);
      for (local_2c0 = 0; (int)local_2c0 < DAT_00559a94; local_2c0 = local_2c0 + 1) {
        if ((&DAT_005596b8)[local_2c0] == local_2b8) {
          aiStack_e0[local_17c] = (&DAT_00559fc8)[local_2c0];
        }
      }
      acStack_134[local_2b8] = (char)local_17c;
      local_17c = local_17c + 1;
    }
  }
  Ai_PopBoardState();
  local_258 = 9999;
  Ai_FilterValidBlockers(&local_2b4,(uint *)0x0);
  local_2c0 = 0;
  do {
    if (1 << ((byte)local_254 & 0x1f) <= (int)local_2c0) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) &
             0xfffffffb;
        if ((local_2a4 & 1 << ((byte)local_2a8 & 0x1f)) != 0) {
          *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
               *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
          FUN_004726c5(arg_1,local_46c[local_2a8]);
          if (((local_248 != 0) && (local_420 == -1)) &&
             ((local_308[local_2a8] & local_8) == local_308[local_2a8])) {
            local_420 = local_46c[local_2a8];
          }
        }
      }
      if (((local_248 == 0) || (local_420 == -1)) ||
         (((&g_CardSlot_Flags)[local_420 * 0x120 + arg_1 * 0x5b20] & 4) == 0)) {
        if ((local_248 != 0) && (local_e4 == 0)) {
          for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
            *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
            FUN_004726c5(arg_1,aiStack_244[local_2a8]);
          }
          local_2a4 = 1;
        }
      }
      else {
        for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
          (&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120] =
               (undefined1)local_420;
          *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
               *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
          FUN_004726c5(arg_1,aiStack_244[local_2a8]);
        }
        (&g_CardSlot_ColorMask)[local_420 * 0x120 + arg_1 * 0x5b20] = (undefined1)local_420;
      }
      DAT_0067bdb0 = local_2a0;
      DAT_006a5f20 = local_2a4;
      return local_2a4;
    }
    local_2bc = 1;
    DAT_00559a94 = 0;
    _DAT_00559800 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb
      ;
      local_2b0 = *(int *)(&g_MasterCardTypeTable +
                          *(int *)(&g_CardSlot_CardId +
                                  arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) * 0x34);
      if ((local_2c0 & 1 << ((byte)local_2a8 & 0x1f)) == 0) {
        if ((local_2b0 == 0x19f) || (local_2b0 == 0x84)) {
          local_2bc = 0;
        }
        if ((local_8c & 1 << ((byte)local_2a8 & 0x1f)) != 0) {
          local_2bc = 0;
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
        (&DAT_005596b8)[DAT_00559a94] = local_46c[local_2a8];
        (&DAT_00559f88)[DAT_00559a94] = local_88[local_2a8];
        (&DAT_00559808)[DAT_00559a94] = local_48[local_2a8];
        (&DAT_005595f8)[DAT_00559a94] = local_308[local_2a8];
        (&DAT_00559fc8)[DAT_00559a94] = local_298[local_2a8];
        (&DAT_00559890)[DAT_00559a94] = local_39c[local_2a8];
        (&DAT_00559a98)[DAT_00559a94] = *(undefined4 *)(&DAT_005598d8 + local_2a8 * 4);
        (&DAT_00559a28)[DAT_00559a94] = *(undefined4 *)(&DAT_00559778 + local_2a8 * 4);
        if ((local_2b0 == 0x28) || (local_2b0 == 0x98)) {
          _DAT_00559800 = _DAT_00559800 | 1 << ((byte)DAT_00559a94 & 0x1f);
        }
        DAT_00559a94 = DAT_00559a94 + 1;
      }
    }
    if (local_2bc != 0) {
      DAT_00559b18 = 1;
      Ai_Subsystem_004c7aa8(arg_1);
      Ai_PushBoardState();
      g_IsAiThinking = 1;
      Magic_ScanCards(199);
      g_IsAiThinking = local_24c;
      local_2ac = 0;
      for (local_98 = 0; local_98 < 8; local_98 = local_98 + 1) {
        aiStack_1c4[local_98 * 2 + 3] = -1;
      }
      for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[DAT_00559a20];
          local_2a8 = local_2a8 + 1) {
        local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + DAT_00559a20 * 0x5b20);
        if (((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
           ((*(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + DAT_00559a20 * 0x5b20) & 0x402) != 0)
           ) {
          local_90 = (int)acStack_35c[local_2a8];
          local_428 = aiStack_41c[acStack_35c[local_2a8]];
          local_2b8 = 0;
LAB_004c72b0:
          if (local_2b8 < 8) {
            if (local_428 <= aiStack_1c4[local_2b8 * 2 + 3]) goto LAB_004c72aa;
            for (local_98 = 7; local_2b8 < local_98; local_98 = local_98 + -1) {
              aiStack_1c4[local_98 * 2 + 2] = aiStack_1c4[local_98 * 2];
              aiStack_1c4[local_98 * 2 + 3] = aiStack_1c4[local_98 * 2 + 1];
            }
            aiStack_1c4[local_2b8 * 2 + 2] = local_2a8;
            aiStack_1c4[local_2b8 * 2 + 3] = local_428;
          }
        }
      }
      local_98 = 0;
      while ((local_98 < 8 && (aiStack_1c4[local_98 * 2 + 3] != -1))) {
        local_2a8 = aiStack_1c4[local_98 * 2 + 2];
        local_200 = FUN_00473179(DAT_00559a20,local_2a8,0x34,0xffffffff);
        local_90 = (int)acStack_35c[local_2a8];
        local_428 = aiStack_41c[local_90];
        local_424 = aiStack_3dc[local_90];
        local_2c8 = 0;
        local_42c = 0;
        local_17c = 0;
        local_9c = 0x7fff;
        for (local_2b8 = 0; local_2b8 < (int)(&g_PlayerActiveCardCount)[arg_1];
            local_2b8 = local_2b8 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg_1 * 0x5b20) != -1) &&
              ((*(uint *)(&g_CardSlot_Flags + local_2b8 * 0x120 + arg_1 * 0x5b20) & 0x402) != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            local_17c = (int)acStack_134[local_2b8];
            local_a0 = aiStack_178[local_17c];
            local_138 = aiStack_1fc[local_17c];
            iVar4 = local_2b8 * 0x120;
            iVar2 = FUN_004728c3(arg_1,local_2b8);
            if (((*(uint *)(&g_CardSlot_Flags + iVar4 + arg_1 * 0x5b20) &
                 (-(uint)(iVar2 == 0) & 4) + 8) == 0) &&
               (iVar2 = FUN_00472c0c(arg_1,local_2b8,DAT_00559a20,local_2a8,local_200,local_2b4),
               uVar1 = local_42c, iVar2 != 0)) {
              local_42c = local_42c | 1;
              if ((local_428 < local_138) || (local_424 <= local_a0)) {
                local_42c = uVar1 | 3;
                *(uint *)(&g_CardSlot_Flags + local_2b8 * 0x120 + arg_1 * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags + local_2b8 * 0x120 + arg_1 * 0x5b20) | 8;
                break;
              }
              if (aiStack_e0[local_17c] < local_9c) {
                local_9c = aiStack_e0[local_17c];
                local_2c8 = local_2b8;
              }
            }
          }
        }
        if ((local_42c & 2) == 0) {
          iVar2 = *(int *)(&g_PlayerLifeTotals + arg_1 * 4) * local_428 * 0x18;
          iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
          iVar4 = FUN_0040a305((&g_PlayerCreatureCount)[arg_1] + 1,1,99);
          local_250 = (int)(CONCAT44(iVar2 >> 0x1f,iVar2 >> 2) / (longlong)iVar4);
          if (local_42c != 0) {
            local_94 = (int)(*(int *)(&DAT_00695e88 + arg_1 * 4) * local_9c +
                            (*(int *)(&DAT_00695e88 + arg_1 * 4) * local_9c >> 0x1f & 7U)) >> 3;
            if (local_94 <= local_250) {
              DAT_0055a008 = DAT_0055a008 + local_94;
              *(uint *)(&g_CardSlot_Flags + local_2c8 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Flags + local_2c8 * 0x120 + arg_1 * 0x5b20) | 8;
              goto LAB_004c737a;
            }
          }
          local_2ac = local_2ac + local_428;
          DAT_0055a008 = DAT_0055a008 + local_250;
        }
LAB_004c737a:
        local_98 = local_98 + 1;
      }
      Ai_PopBoardState();
      if ((((int)(&g_PlayerCreatureCount)[arg_1] <= local_2ac) &&
          (0 < (int)(&g_PlayerCreatureCount)[arg_1])) &&
         (0 < (int)(&g_PlayerCreatureCount)[1 - arg_1])) {
        DAT_0055a008 = DAT_0055a008 + ((local_2ac - (&g_PlayerCreatureCount)[arg_1]) + 2) * 0x80;
        DAT_0055a008 = DAT_0055a008 + DAT_00559998;
      }
      if (DAT_0055a008 < local_258) {
        local_258 = DAT_0055a008;
        local_2a4 = local_2c0;
      }
    }
    local_2c0 = local_2c0 + 1;
  } while( true );
LAB_004c72aa:
  local_2b8 = local_2b8 + 1;
  goto LAB_004c72b0;
}


