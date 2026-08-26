/*
 * Decompiled function: Pic_Subsystem_0044f1de
 * Entry Point: 0044f1de
 * Size: 5427 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x0044f701) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0044f1de(undefined4 arg1,int arg2)

{
  int iVar1;
  uint arg_1;
  undefined4 uVar2;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c [6];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (((byte)DAT_006fe410 & 1) == 0) {
    arg2 = -1;
  }
  Adventure_Audio_StopAllTracks();
  FUN_0040a1ff();
  DAT_0063ee18 = 1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
      *(undefined4 *)(&g_ActiveCardsInPlay + local_8 * 0x5b20 + local_1c * 0x120) = 0xffffffff;
      *(undefined4 *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_1c * 0x120) =
           *(undefined4 *)(&g_ActiveCardsInPlay + local_8 * 0x5b20 + local_1c * 0x120);
    }
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      *(undefined4 *)(&DAT_006b1590 + local_1c * 4 + local_8 * 2000) = 0xffffffff;
      *(undefined4 *)(&DAT_006ff710 + local_1c * 4 + local_8 * 2000) =
           *(undefined4 *)(&DAT_006b1590 + local_1c * 4 + local_8 * 2000);
    }
    *(undefined4 *)(&DAT_006ff4b8 + local_8 * 4) = 0;
    (&g_PlayerActiveCardCount)[local_8] = 0;
  }
  DAT_006ff2c0 = 0xef;
  DAT_006ff2c4 = 0x7e;
  DAT_006ff2c8 = 0x5b;
  DAT_006ff2cc = 0xa4;
  DAT_006ff2d0 = 0xbc;
  FUN_0046f300();
  FUN_0047643e();
  if (arg2 == -1) {
    DAT_006a4a04 = 0x14;
    g_PlayerCreatureCount = 0x14;
    Ai_Subsystem_004b6f49(&DAT_00695e10);
    local_2c = 7;
    DAT_00627a14 = 0;
    DAT_00696a18 = 1;
    DAT_006b2d64 = -1;
    FUN_0040a2c0();
    if (((DAT_0067f380 == 0) || (iVar1 = FUN_0040a1d2(2), iVar1 == 0)) || (g_IsAiThinking != 0)) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
    local_28 = 1;
    DAT_006a2858 = 1;
    if (DAT_0068a648 == 0) {
      for (local_54 = 0; local_54 < 0x3c; local_54 = local_54 + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_54 * 4) = 0;
        *(undefined4 *)(&DAT_0069e730 + local_54 * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_54 * 4);
      }
      for (local_54 = 0x3c; local_54 < 500; local_54 = local_54 + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_54 * 4) = 0xffffffff;
        *(undefined4 *)(&DAT_0069e730 + local_54 * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_54 * 4);
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      for (local_54 = 0; local_54 < 0x10; local_54 = local_54 + 1) {
        (&DAT_006b2dd0)[local_54] = 0xffffffff;
        (&DAT_006b2d90)[local_54] = (&DAT_006b2dd0)[local_54];
      }
      if (DAT_006feeb8 != 0) {
        DAT_006b2d90 = FUN_0040a02a(DAT_0052effc);
        DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
      }
      for (local_54 = 0; local_54 < 7; local_54 = local_54 + 1) {
        iVar1 = FUN_0040a02a(DAT_0052effc);
        Pic_Subsystem_00451291(0,iVar1);
        iVar1 = FUN_0040a02a(DAT_0052eff8);
        Pic_Subsystem_00451291(1,iVar1);
      }
      Pic_Subsystem_00450711(&local_18,&local_34,&local_20);
      for (local_50 = 0; local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = DAT_0052effc;
        }
        else {
          local_60 = DAT_0052eff8;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < *(int *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280);
                local_58 = local_58 + 1) {
              *(undefined4 *)(&DAT_0069e730 + local_5c * 4 + local_50 * 2000) = 0;
              local_5c = local_5c + 1;
            }
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(undefined4 *)(&DAT_0069e730 + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      Ai_AssignCombatDamage
                (&local_10,(uint *)(local_4c + 5),local_10,local_28,DAT_006b2dd0,DAT_006b2d90,
                 local_18,local_34,local_20);
      if (local_4c[5] != 0) {
        Pic_Subsystem_0045083f(0,DAT_0052effc);
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (local_20 != 0)))) {
        Pic_Subsystem_0045083f(1,DAT_0052eff8);
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      for (local_50 = 0; iVar1 = g_IsAiThinking, local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = DAT_0052effc;
        }
        else {
          local_60 = DAT_0052eff8;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < *(int *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280);
                local_58 = local_58 + 1) {
              uVar2 = Ai_Subsystem_004cbcd9
                                (*(int *)(&DAT_00516cb8 + local_54 * 8 + local_60 * 0x280));
              *(undefined4 *)(&DAT_0069e730 + local_5c * 4 + local_50 * 2000) = uVar2;
              local_5c = local_5c + 1;
            }
            *(undefined4 *)(&DAT_00516cbc + local_54 * 8 + local_60 * 0x280) = 0;
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(undefined4 *)(&DAT_0069e730 + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      DAT_0052effc = -1;
      g_IsAiThinking = 1;
      Pic_Subsystem_00452276(0);
      Pic_Subsystem_00452276(1);
      g_IsAiThinking = iVar1;
    }
  }
  else {
    local_4c[4] = 0;
    local_4c[0] = 0x1e;
    local_4c[1] = 0x23;
    local_4c[2] = 0x28;
    local_4c[3] = 0x28;
    g_PlayerCreatureCount = 10;
    if ((_DAT_0067f374 & 2) != 0) {
      g_PlayerCreatureCount = 0xc;
    }
    if ((_DAT_0067f374 & 0x800) != 0) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + 3;
    }
    if ((_DAT_0067f374 & 0x80) != 0) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + 5;
    }
    iVar1 = Minit_Subsystem_00452827();
    g_PlayerCreatureCount = iVar1 + DAT_00627a7c;
    g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_006498fc;
    if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
      g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_00522454;
    }
    DAT_00627868 = g_PlayerCreatureCount;
    DAT_00627a7c = 0;
    DAT_006a4a04 = (int)(char)(&DAT_00522628)[arg2 * 0x44];
    if ((arg2 < 0x25) && (arg2 % 7 != 0)) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 2;
    }
    else if ((arg2 < 0x25) && (arg2 % 7 == 0)) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 5;
    }
    else if (arg2 < 0x37) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 2;
    }
    else if (0x36 < arg2) {
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * 0x32;
    }
    if ((&DAT_0052262a)[arg2 * 0x44] == '\v') {
      for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
        if ((_DAT_0067f374 & 1 << ((byte)local_1c & 0x1f)) != 0) {
          DAT_006a4a04 = DAT_006a4a04 + 1;
        }
      }
    }
    iVar1 = DAT_006a4a04;
    if ((&DAT_0052262a)[arg2 * 0x44] == '\f') {
      DAT_006a4a04 = DAT_006a4a04 + 10;
      local_30 = 0;
      local_c = 0;
      for (local_1c = 0; (local_1c < 1000 && ((&DAT_0067b9b0)[local_1c] != '\0'));
          local_1c = local_1c + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_1c] >> 4 == DAT_006b2d64) {
          local_30 = local_30 + 1;
        }
      }
      DAT_006a4a04 = DAT_006a4a04 - local_30;
      for (local_24 = 0; local_24 < 0x80; local_24 = local_24 + 1) {
        if (((&DAT_0067be01)[local_24 * 100] != '\0') &&
           ((*(int *)(&DAT_0067be00 + local_24 * 100) >> 8) + -1 == local_1c)) {
          local_c = local_c + 1;
        }
      }
      DAT_006a4a04 = DAT_006a4a04 + DAT_0067f380 * local_c;
      iVar1 = DAT_0067f380 * 5 + 0x14;
      if (iVar1 <= DAT_006a4a04) {
        iVar1 = DAT_006a4a04;
      }
    }
    DAT_006a4a04 = iVar1;
    if ((&DAT_0052262a)[arg2 * 0x44] == '\r') {
      DAT_006a4a04 = DAT_0067f380 * 100 + 100;
    }
    g_OverworldWorldState = 0;
    Adventure_FormatNewsString(arg2,0,0);
    strcpy(&DAT_00695e10,&g_OverworldWorldState);
    FUN_0040a305(DAT_0067f380 + DAT_00695df0 + 4,0,99);
    local_2c = 7;
    DAT_00627a14 = 0;
    FUN_0040a2c0();
    if (((DAT_0067f380 == 0) || (iVar1 = FUN_0040a1d2(2), iVar1 == 0)) || (g_IsAiThinking != 0)) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
    local_28 = 1;
    DAT_006a2858 = 1;
    if ((DAT_0067a6b4 != 0) || (DAT_00522454 == 0)) {
      if (DAT_0067a6b4 == 0) {
        local_10 = 0;
      }
      else {
        local_10 = 1;
      }
      local_10 = (uint)(DAT_0067a6b4 != 0);
      local_28 = 0;
      DAT_006a2858 = 0;
      DAT_0067a6b4 = 0;
    }
    if (g_IsAiThinking == 0) {
      DAT_0067a6b0 = 0;
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if ((*(int *)(&deck + local_1c * 4) != -1) && (((&DAT_00702151)[local_1c * 4] & 0x40) == 0))
        {
          local_4c[4] = local_4c[4] + 1;
        }
      }
      if (local_4c[4] < local_4c[DAT_0067f380]) {
        DAT_0067a6b0 = 1;
        memcpy(&DAT_00679ee0,&deck,2000);
        for (local_1c = 0; local_1c < local_4c[DAT_0067f380] - local_4c[4]; local_1c = local_1c + 1)
        {
          arg_1 = FUN_0040a1d2(5);
          Pic_Subsystem_00451e40(arg_1);
        }
      }
      for (local_1c = 0; local_1c < 0x3c; local_1c = local_1c + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_1c * 4) = 0;
        *(undefined4 *)(&DAT_0069e730 + local_1c * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_1c * 4);
      }
      for (local_1c = 0x3c; local_1c < 500; local_1c = local_1c + 1) {
        *(undefined4 *)(&DAT_0069ef00 + local_1c * 4) = 0xffffffff;
        *(undefined4 *)(&DAT_0069e730 + local_1c * 4) =
             *(undefined4 *)(&DAT_0069ef00 + local_1c * 4);
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if ((*(uint *)(&deck + local_1c * 4) & 0xfff) == DAT_006b2d90) {
          *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) | 0x8000;
          break;
        }
      }
      for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
        if (DAT_0052effc == -1) {
          iVar1 = Pic_Subsystem_00451cb2();
          Pic_Subsystem_00451291(0,iVar1);
        }
        else {
          iVar1 = FUN_0040a02a(DAT_0052effc);
          Pic_Subsystem_00451291(0,iVar1);
        }
      }
      if (DAT_0052eff8 != -1) {
        if ((DAT_0052effc == -1) && (FUN_00409eb0(DAT_0052eff8), DAT_006b2dd0 != -1)) {
          FUN_00409f16(0,DAT_006b2dd0);
        }
        for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
          iVar1 = FUN_0040a02a((uint)(DAT_0052effc != -1));
          Pic_Subsystem_00451291(1,iVar1);
        }
      }
      Pic_Subsystem_00450711(&local_18,&local_34,&local_20);
      Ai_AssignCombatDamage
                (&local_10,(uint *)(local_4c + 5),local_10,local_28,DAT_006b2dd0,DAT_006b2d90,
                 local_18,local_34,local_20);
      if (local_4c[5] != 0) {
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          *(undefined4 *)(&g_CardSlot_CardId + local_1c * 0x120) = 0xffffffff;
          *(undefined4 *)(&g_ActiveCardsInPlay + local_1c * 0x120) = 0xffffffff;
        }
        for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
          if (*(int *)(&deck + local_1c * 4) != -1) {
            *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) & 0xffff7fff;
          }
        }
        for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
          if ((*(uint *)(&deck + local_1c * 4) & 0xfff) == DAT_006b2d90) {
            *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) | 0x8000;
            break;
          }
        }
        for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
          if (DAT_0052effc == -1) {
            iVar1 = Pic_Subsystem_00451cb2();
            Pic_Subsystem_00451291(0,iVar1);
          }
          else {
            iVar1 = FUN_0040a02a(DAT_0052effc);
            Pic_Subsystem_00451291(0,iVar1);
          }
        }
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (local_20 != 0)))) {
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          *(undefined4 *)(&DAT_006aba54 + local_1c * 0x120) = 0xffffffff;
          *(undefined4 *)(&DAT_006aba50 + local_1c * 0x120) = 0xffffffff;
        }
        if ((DAT_0052effc == -1) && (FUN_00409eb0(DAT_0052eff8), DAT_006b2dd0 != -1)) {
          FUN_00409f16(0,DAT_006b2dd0);
        }
        for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
          iVar1 = FUN_0040a02a((uint)(DAT_0052effc != -1));
          Pic_Subsystem_00451291(1,iVar1);
        }
        Ai_Subsystem_004cc9c5(0,0x30);
      }
      if (DAT_0052effc == -1) {
        DAT_0052eff8 = 0;
      }
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if (DAT_0052effc == -1) {
          uVar2 = Pic_Subsystem_00451cb2();
          *(undefined4 *)(&DAT_0069e730 + local_1c * 4) = uVar2;
        }
        else {
          uVar2 = FUN_0040a02a(DAT_0052effc);
          *(undefined4 *)(&DAT_0069e730 + local_1c * 4) = uVar2;
        }
        uVar2 = FUN_0040a02a(DAT_0052eff8);
        *(undefined4 *)(&DAT_0069ef00 + local_1c * 4) = uVar2;
      }
      DAT_0052effc = -1;
      if ((((&DAT_00522638)[arg2 * 0x44] & 2) != 0) && (DAT_0067f37c % 3 == 0)) {
        memcpy(&DAT_0069ef00,&DAT_0069e730,1000);
        local_1c = g_IsAiThinking;
        g_IsAiThinking = 1;
        Pic_Subsystem_00452276(1);
        g_IsAiThinking = local_1c;
        memcpy(&DAT_006aba50,&g_ActiveCardsInPlay,0x5b20);
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          if (*(int *)(&DAT_006aba54 + local_1c * 0x120) != -1) {
            *(uint *)(&DAT_006aba5c + local_1c * 0x120) =
                 *(uint *)(&DAT_006aba5c + local_1c * 0x120) | 0x1000;
          }
        }
        DAT_00627a14 = 0;
      }
      if (DAT_006b2fe0 != -1) {
        local_1c = Pic_Subsystem_00451291(1,DAT_006b2fe0);
        if (local_1c != -1) {
          *(uint *)(&DAT_006aba5c + local_1c * 0x120) =
               *(uint *)(&DAT_006aba5c + local_1c * 0x120) | 0x30002;
        }
        DAT_006b2fe0 = -1;
        if (DAT_00522454 == -1) {
          DAT_00522454 = 0;
        }
      }
      if (DAT_0068a64c != -1) {
        local_1c = Pic_Subsystem_00451291(1,DAT_0068a64c);
        Pic_Subsystem_0042ac1f(1,local_1c);
        DAT_0068a64c = -1;
        if (DAT_00522454 == -1) {
          DAT_00522454 = 0;
        }
      }
      if (5 < DAT_00522454) {
        local_1c = Pic_Subsystem_00451291(0,DAT_00522454);
        Pic_Subsystem_0042ac1f(0,local_1c);
      }
    }
  }
  FUN_0046f300();
  if (g_IsAiThinking == -1) {
    FUN_0048c72a(0);
  }
  if (g_IsAiThinking == -2) {
    FUN_0048c72a(1);
  }
  Pic_Subsystem_0044b8aa();
  if (g_IsAiThinking == -10) {
    FUN_0048e1bf(DAT_006a287c);
    Ai_Subsystem_004cc9c5(0,0xff);
    local_14 = g_DefendingPlayer;
  }
  else if (g_IsAiThinking == -1) {
    DAT_006a4b58 = 0;
    Ai_Subsystem_004cc9c5(0,0xff);
    local_14 = 1;
  }
  else if (g_IsAiThinking == -2) {
    DAT_006a4b58 = 0;
    Ai_Subsystem_004cc9c5(0,0xff);
    local_14 = 0;
  }
  else {
    DAT_006a4b58 = 1;
    local_14 = local_10;
  }
  while ((DAT_006fe3f0 == 0 && (iVar1 = FUN_005062b1(), iVar1 == 0))) {
    if (DAT_007006d4 == 0) {
      FUN_00501f50(local_14);
      local_14 = 1 - local_14;
    }
    else {
      if ((DAT_007006d4 & 1) == 0) {
        DAT_007006d4 = 0;
        if (local_14 == 0) {
          DAT_006ff2d8 = 0xffffffff;
        }
        FUN_00501f50(1);
      }
      else {
        DAT_007006d4 = 0;
        if (local_14 == 1) {
          DAT_006ff2d8 = 0xffffffff;
        }
        FUN_00501f50(0);
      }
      DAT_006ff2d8 = 0xffffffff;
    }
  }
  Pic_Subsystem_0044b8da();
  if (DAT_0063ee80 == 0) {
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      if (*(int *)(&deck + local_1c * 4) != -1) {
        *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_00523e34);
  }
  DAT_00522454 = 0xffffffff;
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  g_IsAiThinking = 0;
  for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
    *(undefined4 *)(&g_PlayerLifeTotals + local_1c * 4) = 8;
  }
  DAT_0063ee18 = 0;
  _DAT_0063ee14 = 1;
  if (((g_PlayerCreatureCount < 1) || (9 < DAT_00696870)) ||
     ((0 < DAT_006a4a04 && (DAT_00696874 < 10)))) {
    if (((DAT_006a4a04 < 1) || (9 < DAT_00696874)) ||
       ((0 < g_PlayerCreatureCount && (DAT_00696870 < 10)))) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


