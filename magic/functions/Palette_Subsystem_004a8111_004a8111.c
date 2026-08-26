/*
 * Decompiled function: Palette_Subsystem_004a8111
 * Entry Point: 004a8111
 * Size: 3040 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a8111(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  short sVar2;
  uint arg_11;
  int iVar3;
  uint arg_12;
  uint arg_13;
  int iVar4;
  int iVar5;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  int local_c;
  int local_8;
  
  arg_20 = 0;
  arg_19 = 0;
  arg_18 = 0;
  arg_17 = 0xffffffff;
  arg_16 = 0xffffffff;
  iVar5 = -1;
  iVar4 = -1;
  arg_13 = 0;
  arg_12 = 0;
  arg_11 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
  iVar4 = Rules_ParseFilter_0040360b
                    (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),(char *)0x0
                     ,arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,iVar5,arg_16,arg_17,arg_18,
                     arg_19,arg_20);
  if (iVar4 == 0) {
    g_ActivePlayer = 1;
  }
  else {
    iVar4 = *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20);
    iVar5 = *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
    local_c = -1;
    if ((((-1 < arg_3) && (arg_3 < 0x14)) && (arg_3 != 0xd)) && (arg_3 != 1)) {
      strcpy(&g_OverworldWorldState,s_casts_Berserk__0052c698 + arg_3 * 0x32);
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar4,iVar5,&g_OverworldWorldState,0);
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x24);
      }
    }
    switch(arg_3) {
    case 0:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + arg_1 * 0x5b20) = 0x80;
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(undefined2 *)(&g_CardSlot_Counters + iVar4 * 0x5b20 + iVar5 * 0x120);
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg_1 * 0x5b20) | 0x4000;
      }
      break;
    case 1:
      if (*(short *)(&g_CardSlot_Counters + iVar4 * 0x5b20 + iVar5 * 0x120) < 3) {
        Ai_Subsystem_004cc56d
                  (arg_1,arg_1,arg_2,iVar4,iVar5,s_activates_Tawnos_s_Wand_effect__0052cb7c,0);
        local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00696734,iVar4,iVar5);
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x24);
        }
      }
      else {
        g_ActivePlayer = 1;
        Ai_Subsystem_004cc56d
                  (arg_1,arg_1,arg_2,iVar4,iVar5,s_fizzles_attempting_Tawnos_s_Wand_0052cba0,0);
      }
      break;
    case 2:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + arg_1 * 0x5b20) = 4;
        sVar2 = FUN_0040a305(4,0,*(short *)(&DAT_006a5f46 + iVar4 * 0x5b20 + iVar5 * 0x120) + -1);
        *(short *)(&DAT_006a5f4a + local_c * 0x120 + arg_1 * 0x5b20) = -sVar2;
      }
      break;
    case 3:
      bVar1 = FUN_0041d9d2(arg_1,arg_2,3);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 4:
      bVar1 = FUN_0041d9d2(arg_1,arg_2,5);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 5:
      bVar1 = FUN_0041d9d2(arg_1,arg_2,4);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 6:
      FUN_0041db67(iVar4,iVar5,3,g_DialogPromptHwnd,g_DuelArenaHwnd);
      break;
    case 7:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&g_CardSlot_Abilities2 + local_c * 0x120 + arg_1 * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + arg_1 * 0x5b20) = 0x20;
      }
      break;
    case 8:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + arg_1 * 0x5b20) = 3;
        *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + arg_1 * 0x5b20) = 3;
      }
      break;
    case 9:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + arg_1 * 0x5b20) = 0x40;
      }
      *(undefined4 *)(&g_CardSlot_Abilities2 + iVar4 * 0x5b20 + iVar5 * 0x120) = 0x8000000;
      break;
    case 10:
      bVar1 = FUN_0041d9d2(arg_1,arg_2,1);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 0xb:
      bVar1 = FUN_0041d9d2(arg_1,arg_2,2);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 0xc:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,iVar4,iVar5);
      if (local_c != -1) {
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg_1 * 0x5b20) | 0x800000;
      }
      *(undefined4 *)(&g_CardSlot_Abilities2 + iVar4 * 0x5b20 + iVar5 * 0x120) = 0x8000000;
      break;
    case 0xd:
      iVar3 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,iVar4,iVar5,s_casts_Twiddle__Tap__Untap__0052cb5c,
                         (*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x10) >> 4
                        );
      if (iVar3 == 0) {
        FUN_00415d48(iVar4,iVar5);
      }
      else {
        *(uint *)(&g_CardSlot_Flags + iVar4 * 0x5b20 + iVar5 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + iVar4 * 0x5b20 + iVar5 * 0x120) & 0xffffffef;
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x24);
      }
      break;
    case 0xe:
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + arg_1 * 0x5b20) = 0xfffe;
        *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + arg_1 * 0x5b20) = 0;
      }
      break;
    case 0xf:
      FUN_0041da41(iVar4,iVar5);
      break;
    case 0x10:
      FUN_0041db67(iVar4,iVar5,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      break;
    case 0x11:
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006b3060)
              && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
             (((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == iVar4 &&
              (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == iVar5)))
             ) {
            *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_8 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_8 * 0x5b20) & 0xfeffffff
            ;
          }
        }
      }
      local_c = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006b3060,iVar4,iVar5);
      if (local_c != -1) {
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg_1 * 0x5b20) | 0x1000000;
        *(ushort *)(&DAT_006a5f48 + local_c * 0x120 + arg_1 * 0x5b20) =
             -(*(ushort *)
                (&DAT_0051aec2 +
                *(int *)(&g_CardSlot_CardId + iVar4 * 0x5b20 + iVar5 * 0x120) * 0x34) & 0xbfff);
        *(ushort *)(&DAT_006a5f4a + local_c * 0x120 + arg_1 * 0x5b20) =
             2 - (*(ushort *)
                   (&DAT_0051aec4 +
                   *(int *)(&g_CardSlot_CardId + iVar4 * 0x5b20 + iVar5 * 0x120) * 0x34) & 0xbfff);
      }
      break;
    case 0x12:
      iVar3 = FUN_00473179(iVar4,iVar5,0x32,0xffffffff);
      (&g_PlayerCreatureCount)[iVar4] = (&g_PlayerCreatureCount)[iVar4] + iVar3;
      Pic_Subsystem_0044867e(iVar4,iVar5,4);
      break;
    case 0x13:
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2c);
        Sleep(0xdac);
      }
      *(short *)(&DAT_006a5f4a + iVar4 * 0x5b20 + iVar5 * 0x120) =
           *(short *)(&DAT_006a5f4a + iVar4 * 0x5b20 + iVar5 * 0x120) + -1;
      *(int *)(&DAT_006a5f7c + iVar4 * 0x5b20 + iVar5 * 0x120) =
           *(int *)(&DAT_006a5f7c + iVar4 * 0x5b20 + iVar5 * 0x120) + 0x1000000;
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2b);
      }
      break;
    default:
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar4,iVar5,s_made_an_error__0052cbcc,0);
    }
    if (local_c != -1) {
      iVar4 = FUN_00478aa4(*(int *)(&DAT_0052c640 + arg_3 * 4),arg_1,arg_2);
      *(uint *)(&DAT_006a5f74 + local_c * 0x120 + arg_1 * 0x5b20) =
           iVar4 << 0x10 | *(uint *)(&DAT_0052c640 + arg_3 * 4);
    }
  }
  (&g_CardSlot_TurnPlayed)
  [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
   *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
  return 0;
}


