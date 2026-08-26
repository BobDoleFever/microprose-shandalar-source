/*
 * Decompiled function: Ai_Subsystem_004c4c84
 * Entry Point: 004c4c84
 * Size: 4933 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c4c84(int arg_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int aiStack_cc [16];
  uint local_8c;
  int local_88;
  int local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  int aiStack_58 [16];
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  DAT_00559a20 = 1 - arg_1;
  if (DAT_00559b18 == 0) {
    Ai_FilterValidBlockers(&local_8,&local_18);
    if (DAT_00559a20 == 1) {
      DAT_0055a094 = local_8;
    }
    else {
      DAT_0055a094 = local_18;
    }
    DAT_0055a090 = 0;
    DAT_00559a94 = 0;
    local_6c = g_IsAiThinking;
    g_IsAiThinking = 1;
    DAT_00676c8c = 1;
    Ai_Subsystem_004cab92();
    Ai_PushBoardState();
    local_64 = g_SpellStackDepth;
    g_SpellStackDepth = 0;
    DAT_0055999c = 0;
    _DAT_00559800 = 0;
    Magic_ScanCards(199);
    Pic_Subsystem_004475a4(arg_1);
    local_88 = Ai_SimulateCombatRound(arg_1);
    local_88 = g_SpellStackDepth + local_88;
    Ai_PopBoardState();
    g_SpellStackDepth = local_64;
    for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + arg_1 * 0x5b20);
      if (((local_68 != -1) && (((&g_CardSlot_Flags)[local_70 * 0x120 + arg_1 * 0x5b20] & 4) != 0))
         && (((&g_CardSlot_ColorMask)[local_70 * 0x120 + arg_1 * 0x5b20] == -1 ||
             ((char)(&g_CardSlot_ColorMask)[local_70 * 0x120 + arg_1 * 0x5b20] == local_70)))) {
        local_80 = FUN_00473cc5((&DAT_0051aebe)[local_68 * 0x34]);
        local_78 = *(int *)(&DAT_006410f0 + local_70 * 0xc + arg_1 * 0x3c0);
        (&DAT_005596b8)[DAT_00559a94] = local_70;
        (&DAT_00559f88)[DAT_00559a94] = *(int *)(&DAT_00695eb0 + arg_1 * 4) + local_78;
        (&DAT_00559808)[DAT_00559a94] =
             *(int *)(&DAT_006410f4 + local_70 * 0xc + arg_1 * 0x3c0) +
             *(int *)(&DAT_00695eb8 + arg_1 * 4);
        (&DAT_005595f8)[DAT_00559a94] =
             *(undefined4 *)(&DAT_006410f8 + local_70 * 0xc + arg_1 * 0x3c0);
        iVar2 = FUN_0040d949(arg_1,local_80,1);
        if (iVar2 == 0) {
          (&DAT_005595f8)[DAT_00559a94] = (&DAT_005595f8)[DAT_00559a94] & 0xfffffdff;
        }
        DAT_006ff19c = 0;
        FUN_00473e69(arg_1,local_70,0x8a);
        (&DAT_00559a98)[DAT_00559a94] = DAT_006ff19c;
        if (((&DAT_0051aed0)[local_68 * 0x34] & 8) != 0) {
          iVar2 = (**(code **)(&DAT_0051aec8 + local_68 * 0x34))(arg_1,local_70,0x39);
          (&DAT_00559f88)[DAT_00559a94] = (&DAT_00559f88)[DAT_00559a94] + iVar2;
        }
        if (((&DAT_0051aed0)[local_68 * 0x34] & 0x10) != 0) {
          iVar2 = (**(code **)(&DAT_0051aec8 + local_68 * 0x34))(arg_1,local_70,0x3a);
          (&DAT_00559808)[DAT_00559a94] = (&DAT_00559808)[DAT_00559a94] + iVar2;
        }
        Ai_PushBoardState();
        local_64 = g_SpellStackDepth;
        g_SpellStackDepth = 0;
        *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg_1 * 0x5b20) | 8;
        Pic_Subsystem_0044867e(arg_1,local_70,2);
        Magic_ScanCards(199);
        Pic_Subsystem_004475a4(arg_1);
        local_c = Ai_SimulateCombatRound(arg_1);
        local_c = g_SpellStackDepth + local_c;
        Ai_PopBoardState();
        g_SpellStackDepth = local_64;
        iVar2 = abs((int)(char)(&DAT_0051aec0)[local_68 * 0x34]);
        local_10 = ((iVar2 + (char)(&DAT_0051aebf)[local_68 * 0x34]) - local_c) + local_88;
        if ((*(byte *)((int)&DAT_005595f8 + DAT_00559a94 * 4 + 1) & 2) != 0) {
          iVar2 = FUN_0040d949(arg_1,local_80,1);
          if (iVar2 == 0) {
            local_10 = local_10 << 1;
          }
          else {
            local_10 = local_10 / 3;
          }
        }
        *(int *)(&DAT_006a5f70 + local_70 * 0x120 + arg_1 * 0x5b20) = local_10;
        (&DAT_00559fc8)[DAT_00559a94] = local_10;
        (&DAT_00559808)[DAT_00559a94] =
             (&DAT_00559808)[DAT_00559a94] -
             (int)*(short *)(&g_CardSlot_Power + local_70 * 0x120 + arg_1 * 0x5b20);
        (&DAT_00559890)[DAT_00559a94] = 0;
        if ((&DAT_006a604f)[local_70 * 0x120 + arg_1 * 0x5b20] != '\0') {
          _DAT_00559800 = _DAT_00559800 | 1 << ((byte)DAT_00559a94 & 0x1f);
        }
        DAT_00559a94 = DAT_00559a94 + 1;
        if ((g_IsAiThinking == 1) && (6 < DAT_00559a94)) break;
      }
    }
    for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + arg_1 * 0x5b20);
      if ((((local_68 != -1) && (((&g_CardSlot_Flags)[local_70 * 0x120 + arg_1 * 0x5b20] & 4) != 0))
          && ((&g_CardSlot_ColorMask)[local_70 * 0x120 + arg_1 * 0x5b20] != -1)) &&
         ((char)(&g_CardSlot_ColorMask)[local_70 * 0x120 + arg_1 * 0x5b20] != local_70)) {
        local_5c = -1;
        for (local_74 = 0; local_74 < DAT_00559a94; local_74 = local_74 + 1) {
          if ((int)(char)(&g_CardSlot_ColorMask)[local_70 * 0x120 + arg_1 * 0x5b20] ==
              (&DAT_005596b8)[local_74]) {
            local_5c = local_74;
            break;
          }
        }
        if (local_5c != -1) {
          local_80 = FUN_00473cc5((&DAT_0051aebe)[local_68 * 0x34]);
          (&DAT_00559ad8)[DAT_0055a090] = local_70;
          local_78 = *(int *)(&DAT_006410f0 + local_70 * 0xc + arg_1 * 0x3c0);
          (&DAT_00559f88)[local_5c] = (&DAT_00559f88)[local_5c] + local_78;
          (&DAT_00559808)[local_5c] =
               (&DAT_00559808)[local_5c] + *(int *)(&DAT_006410f4 + local_70 * 0xc + arg_1 * 0x3c0);
          local_8c = *(uint *)(&DAT_006410f8 + local_70 * 0xc + arg_1 * 0x3c0) & 0x200 |
                     (&DAT_005595f8)[local_5c] & 0x200;
          (&DAT_005595f8)[local_5c] =
               (&DAT_005595f8)[local_5c] & *(uint *)(&DAT_006410f8 + local_70 * 0xc + arg_1 * 0x3c0)
          ;
          (&DAT_005595f8)[local_5c] = (&DAT_005595f8)[local_5c] | local_8c;
          if (((&DAT_0051aed0)[local_68 * 0x34] & 8) != 0) {
            iVar2 = (**(code **)(&DAT_0051aec8 + local_68 * 0x34))(arg_1,local_70,0x39);
            (&DAT_00559f88)[local_5c] = (&DAT_00559f88)[local_5c] + iVar2;
          }
          if (((&DAT_0051aed0)[local_68 * 0x34] & 0x10) != 0) {
            iVar2 = (**(code **)(&DAT_0051aec8 + local_68 * 0x34))(arg_1,local_70,0x3a);
            (&DAT_00559808)[local_5c] = (&DAT_00559808)[local_5c] + iVar2;
          }
          Ai_PushBoardState();
          local_64 = g_SpellStackDepth;
          g_SpellStackDepth = 0;
          *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg_1 * 0x5b20) | 8;
          Pic_Subsystem_0044867e(arg_1,local_70,2);
          Magic_ScanCards(199);
          Pic_Subsystem_004475a4(arg_1);
          local_c = Ai_SimulateCombatRound(arg_1);
          local_c = g_SpellStackDepth + local_c;
          Ai_PopBoardState();
          g_SpellStackDepth = local_64;
          iVar2 = abs((int)(char)(&DAT_0051aec0)[local_68 * 0x34]);
          local_10 = ((iVar2 + (char)(&DAT_0051aebf)[local_68 * 0x34]) - local_c) + local_88;
          if ((*(byte *)((int)&DAT_005595f8 + local_5c * 4 + 1) & 2) != 0) {
            iVar2 = FUN_0040d949(arg_1,local_80,1);
            if (iVar2 == 0) {
              local_10 = local_10 << 1;
            }
            else {
              local_10 = local_10 / 3;
            }
          }
          *(int *)(&DAT_006a5f70 + local_70 * 0x120 + arg_1 * 0x5b20) = local_10;
          if (local_10 < (int)(&DAT_00559fc8)[local_5c]) {
            (&DAT_00559fc8)[local_5c] = local_10;
          }
          (&DAT_00559808)[local_5c] =
               (&DAT_00559808)[local_5c] -
               (int)*(short *)(&g_CardSlot_Power + local_70 * 0x120 + arg_1 * 0x5b20);
          (&DAT_00559890)[local_5c] = 0;
          if ((&DAT_006a604f)[local_70 * 0x120 + arg_1 * 0x5b20] != '\0') {
            _DAT_00559800 = _DAT_00559800 | 1 << ((byte)local_5c & 0x1f);
          }
          DAT_0055a090 = DAT_0055a090 + 1;
        }
      }
    }
    local_60 = 0;
    for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[DAT_00559a20];
        local_70 = local_70 + 1) {
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + DAT_00559a20 * 0x5b20);
      if (((local_68 != -1) && (((&g_MasterCardColorTable)[local_68 * 0x34] & 2) != 0)) &&
         ((((byte)*(undefined4 *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) &
           0x12) == 2 && ((&g_CardSlot_ColorMask)[local_70 * 0x120 + DAT_00559a20 * 0x5b20] == -1)))
         ) {
        aiStack_58[local_60] = local_70;
        local_60 = local_60 + 1;
      }
      if ((g_IsAiThinking == 1) && (0xf < local_60)) break;
    }
    if ((g_IsAiThinking == 1) && (6 < local_60)) {
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        iVar2 = Ai_Subsystem_004cb04d(DAT_00559a20,aiStack_58[local_70]);
        aiStack_cc[local_70] = iVar2;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_cc[local_70] < aiStack_cc[local_74]) {
            iVar2 = aiStack_cc[local_70];
            aiStack_cc[local_70] = aiStack_cc[local_74];
            aiStack_cc[local_74] = iVar2;
            iVar2 = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = iVar2;
          }
        }
      }
      if (6 < local_60) {
        local_60 = 7;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_58[local_74] < aiStack_58[local_70]) {
            iVar2 = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = iVar2;
          }
        }
      }
    }
    DAT_00559b1c = 0;
    for (local_84 = 0; local_84 < local_60; local_84 = local_84 + 1) {
      local_70 = aiStack_58[local_84];
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + DAT_00559a20 * 0x5b20);
      local_80 = FUN_00473cc5((&DAT_0051aebe)[local_68 * 0x34]);
      *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) | 8;
      local_78 = *(int *)(&DAT_006410f0 + local_70 * 0xc + DAT_00559a20 * 0x3c0);
      (&DAT_0055a050)[DAT_00559b1c] = local_70;
      (&DAT_0055a010)[DAT_00559b1c] = *(int *)(&DAT_00695eb0 + DAT_00559a20 * 4) + local_78;
      (&DAT_00559848)[DAT_00559b1c] =
           *(int *)(&DAT_006410f4 + local_70 * 0xc + DAT_00559a20 * 0x3c0) +
           *(int *)(&DAT_00695eb8 + DAT_00559a20 * 4);
      (&DAT_00559638)[DAT_00559b1c] =
           *(undefined4 *)(&DAT_006410f8 + local_70 * 0xc + DAT_00559a20 * 0x3c0);
      iVar2 = FUN_0040d949(DAT_00559a20,local_80,1);
      if (iVar2 == 0) {
        (&DAT_00559638)[DAT_00559b1c] = (&DAT_00559638)[DAT_00559b1c] & 0xfffffdff;
      }
      DAT_006ff19c = 0;
      FUN_00473e69(DAT_00559a20,local_70,0x8b);
      (&DAT_00559a28)[DAT_00559a94] = DAT_006ff19c;
      if (g_CurrentTurnPhase == DAT_00559a20) {
        if (((&DAT_0051aed0)[local_68 * 0x34] & 8) != 0) {
          iVar2 = (**(code **)(&DAT_0051aec8 + local_68 * 0x34))(DAT_00559a20,local_70,0x39);
          (&DAT_0055a010)[DAT_00559b1c] = (&DAT_0055a010)[DAT_00559b1c] + iVar2;
        }
        if (((&DAT_0051aed0)[local_68 * 0x34] & 0x10) != 0) {
          iVar2 = (**(code **)(&DAT_0051aec8 + local_68 * 0x34))(DAT_00559a20,local_70,0x3a);
          (&DAT_00559848)[DAT_00559b1c] = (&DAT_00559848)[DAT_00559b1c] + iVar2;
        }
      }
      Ai_PushBoardState();
      local_64 = g_SpellStackDepth;
      g_SpellStackDepth = 0;
      *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + DAT_00559a20 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + DAT_00559a20 * 0x5b20) | 8;
      Pic_Subsystem_0044867e(DAT_00559a20,local_70,2);
      Magic_ScanCards(199);
      Pic_Subsystem_004475a4(arg_1);
      local_c = Ai_SimulateCombatRound(arg_1);
      local_c = g_SpellStackDepth + local_c;
      Ai_PopBoardState();
      g_SpellStackDepth = 0;
      *(undefined4 *)(&g_CardSlot_CardId + local_70 * 0x120 + DAT_00559a20 * 0x5b20) = 0xffffffff;
      local_14 = Ai_SimulateCombatRound(arg_1);
      local_14 = g_SpellStackDepth + local_14;
      Ai_PopBoardState();
      g_SpellStackDepth = local_64;
      local_10 = local_c - local_88;
      if ((*(byte *)((int)&DAT_00559638 + DAT_00559b1c * 4 + 1) & 2) != 0) {
        iVar2 = FUN_0040d949(DAT_00559a20,local_80,1);
        if (iVar2 == 0) {
          local_10 = local_10 << 1;
        }
        else {
          local_10 = local_10 / 5;
        }
      }
      (&DAT_0055a098)[DAT_00559b1c] = local_10;
      *(int *)(&DAT_006a5f70 + local_70 * 0x120 + DAT_00559a20 * 0x5b20) = local_10;
      (&DAT_00559848)[DAT_00559b1c] =
           (&DAT_00559848)[DAT_00559b1c] -
           (int)*(short *)(&g_CardSlot_Power + local_70 * 0x120 + DAT_00559a20 * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) & 0xfffffff7;
      for (local_74 = 0; local_74 < DAT_00559a94; local_74 = local_74 + 1) {
        iVar2 = FUN_00472c0c(DAT_00559a20,local_70,arg_1,(&DAT_005596b8)[local_74],
                             (&DAT_005595f8)[local_74],DAT_0055a094);
        if (iVar2 == 0) {
          if (DAT_0055a090 != 0) {
            for (local_7c = 0; local_7c < DAT_0055a090; local_7c = local_7c + 1) {
              if (((int)(char)(&g_CardSlot_ColorMask)
                              [arg_1 * 0x5b20 + (&DAT_00559ad8)[local_7c] * 0x120] ==
                   (&DAT_005596b8)[local_70]) &&
                 (iVar2 = FUN_00472c0c(DAT_00559a20,local_70,arg_1,(&DAT_00559ad8)[local_7c],
                                       (&DAT_005595f8)[local_74],DAT_0055a094), iVar2 != 0)) {
                (&DAT_00559890)[local_74] =
                     (&DAT_00559890)[local_74] | 1 << ((byte)DAT_00559b1c & 0x1f);
              }
            }
          }
        }
        else {
          (&DAT_00559890)[local_74] = (&DAT_00559890)[local_74] | 1 << ((byte)DAT_00559b1c & 0x1f);
        }
      }
      if ((&DAT_006a604f)[local_70 * 0x120 + DAT_00559a20 * 0x5b20] != '\0') {
        DAT_0055999c = DAT_0055999c | 1 << ((byte)DAT_00559b1c & 0x1f);
      }
      *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + DAT_00559a20 * 0x5b20) & 0xfffffff7;
      iVar2 = *(int *)(&DAT_00695e88 + DAT_00559a20 * 4);
      iVar1 = (&DAT_0055a098)[DAT_00559b1c];
      iVar3 = FUN_0040a305((&DAT_00559848)[DAT_00559b1c] + 1,1,99);
      (&DAT_00559678)[DAT_00559b1c] = (iVar2 * iVar1) / iVar3;
      DAT_00559b1c = DAT_00559b1c + 1;
      if ((g_IsAiThinking == 1) && (6 < DAT_00559b1c)) break;
    }
    memset(&DAT_00559a68,0,0x1c);
    memset(&DAT_00559b20,0,0x1c);
    for (local_70 = 0; local_70 < DAT_00559a94; local_70 = local_70 + 1) {
      for (local_74 = 0; local_74 < DAT_00559b1c; local_74 = local_74 + 1) {
        uVar4 = FUN_00476c77(arg_1,(&DAT_005596b8)[local_70],DAT_00559a20,(&DAT_0055a050)[local_74])
        ;
        if ((uVar4 & 1) != 0) {
          *(uint *)(&DAT_00559a68 + local_70 * 4) =
               *(uint *)(&DAT_00559a68 + local_70 * 4) | 1 << ((byte)local_74 & 0x1f);
        }
        if ((uVar4 & 2) != 0) {
          *(uint *)(&DAT_00559b20 + local_74 * 4) =
               *(uint *)(&DAT_00559b20 + local_74 * 4) | 1 << ((byte)local_70 & 0x1f);
        }
      }
    }
    g_IsAiThinking = local_6c;
  }
  DAT_00559b18 = 0;
  DAT_00676c8c = 0;
  DAT_00559888 = (&DAT_0052dde0)[DAT_00559a94];
  return;
}


