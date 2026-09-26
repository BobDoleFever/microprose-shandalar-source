/*
 * sid/Minit.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 154
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Engine_ReportFatalError
 * Entry Point: 00452793
 * Size: 41 bytes
 */


void Engine_ReportFatalError(char *player)

{
  Assert_Handler_005019a0(0,0x523ee0,0x63e,player);
  return;
}



/*
 * Decompiled function: UI_DrawCombatBanner
 * Entry Point: 004527bc
 * Size: 80 bytes
 */


void UI_DrawCombatBanner(void)

{
  Pic_Subsystem_0044b8da();
  Surface_FillRect((int *)g_DisplaySurfaceScreen,200,0x3c,0xf0,0x118,0xbc);
  FUN_0040c3cc(s_COMBAT_00523f00,0x140,0xc4,0xff);
  return;
}



/*
 * Decompiled function: Minit_Util_0045280c
 * Entry Point: 0045280c
 * Size: 27 bytes
 */


void Minit_Util_0045280c(void)

{
  Ai_Subsystem_004cc9c5(g_CurrentTurnPhase,6);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452827
 * Entry Point: 00452827
 * Size: 141 bytes
 */


int Minit_Subsystem_00452827(void)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
    if ((((*(uint *)(&DAT_0067be00 + local_8 * 100) & 0xff01) == 1) &&
        (1 < *(int *)(&DAT_0067bdf0 + local_8 * 100))) &&
       (*(int *)(&DAT_0067bdf0 + local_8 * 100) < 4)) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}



/*
 * Decompiled function: Minit_Subsystem_004528c0
 * Entry Point: 004528c0
 * Size: 494 bytes
 */


undefined4 Minit_Subsystem_004528c0(int x,int y,int width,int height)

{
  undefined4 uVar1;
  
  if ((width == 0x71) && (g_IsAiThinking != 1)) {
    Duel_PlaySoundById(height + 8);
  }
  if (width == 0x73) {
    if ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      FUN_0040d901(x,height,1);
      *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_006ff2d4 = height;
    }
    if (((width == 0x7f) && (g_EventSourceSlot == y)) && (x == g_EventSourcePlayer)) {
      if (((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
          (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34]
           & 2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
        FUN_0040d7e9(x,height,1);
      }
      *(uint *)(&DAT_0063eed0 + x * 4) =
           *(uint *)(&DAT_0063eed0 + x * 4) | 1 << ((byte)height & 0x1f);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00452ab3
 * Entry Point: 00452ab3
 * Size: 38 bytes
 */


void Minit_Subsystem_00452ab3(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_004528c0(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452ad9
 * Entry Point: 00452ad9
 * Size: 38 bytes
 */


void Minit_Subsystem_00452ad9(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_004528c0(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452aff
 * Entry Point: 00452aff
 * Size: 38 bytes
 */


void Minit_Subsystem_00452aff(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_004528c0(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452b25
 * Entry Point: 00452b25
 * Size: 38 bytes
 */


void Minit_Subsystem_00452b25(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_004528c0(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452b4b
 * Entry Point: 00452b4b
 * Size: 38 bytes
 */


void Minit_Subsystem_00452b4b(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_004528c0(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Mana_Init_00452b71
 * Entry Point: 00452b71
 * Size: 779 bytes
 */


void Mana_Init_00452b71(int player,int card_slot,int arg_3,int arg_4,int arg_5)

{
  char *pcVar1;
  char *str_4;
  int iVar2;
  char *str_6;
  int local_c;
  int local_8;
  
  if (arg_3 == 1) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20])
          != 0) {
        FUN_0040d7e9(player,local_8,1);
      }
    }
  }
  if (arg_3 == 0x71) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20])
          != 0) {
        FUN_0040d510(player,local_8,1);
      }
    }
  }
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    if ((arg_4 == DAT_00695ec8) || (DAT_00695ec8 == 0)) {
      local_c = arg_4;
    }
    else if (arg_5 == DAT_00695ec8) {
      local_c = arg_5;
    }
    else {
      strcpy(&g_OverworldWorldState,s_Which_mana__1__00523f08);
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(arg_4);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,&DAT_00523f18);
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(arg_5);
      strcat(&g_OverworldWorldState,pcVar1);
      str_6 = (char *)0x0;
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(arg_5);
      str_4 = (char *)Mem_AllocOrFree_00473d7e(arg_4);
      iVar2 = Ai_Subsystem_004cc814
                        (player,s_Which_type_of_mana_to_produce__00523f20,0,str_4,pcVar1,str_6);
      if (iVar2 == 0) {
        local_c = arg_4;
      }
      else {
        local_c = arg_5;
      }
    }
    FUN_0040d875(player,local_c,1);
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20])
          != 0) {
        FUN_0040d82b(player,local_8,1);
      }
    }
    *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    DAT_006ff2d4 = local_c;
  }
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452e81
 * Entry Point: 00452e81
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452e81(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,4,1);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452eab
 * Entry Point: 00452eab
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452eab(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,1,3);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452ed5
 * Entry Point: 00452ed5
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452ed5(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,4,5);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452eff
 * Entry Point: 00452eff
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452eff(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,5,3);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452f29
 * Entry Point: 00452f29
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452f29(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,5,1);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452f53
 * Entry Point: 00452f53
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452f53(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,3,4);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452f7d
 * Entry Point: 00452f7d
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452f7d(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,3,2);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452fa7
 * Entry Point: 00452fa7
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452fa7(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,2,5);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452fd1
 * Entry Point: 00452fd1
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452fd1(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,1,2);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452ffb
 * Entry Point: 00452ffb
 * Size: 42 bytes
 */


undefined4 Minit_Subsystem_00452ffb(int player,int card_slot,int arg_3)

{
  Mana_Init_00452b71(player,card_slot,arg_3,2,4);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00453025
 * Entry Point: 00453025
 * Size: 716 bytes
 */


undefined4 Minit_Subsystem_00453025(int player,int card_slot,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (arg_3 == 1) {
    iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20]);
    uVar3 = Minit_Subsystem_004528c0(player,card_slot,1,iVar2);
  }
  else {
    if (arg_3 == 0x71) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x25);
      }
      if (player == g_CurrentTurnPhase) {
        cVar1 = Math_RandomRange(5);
        (&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20] = (char)(1 << (cVar1 + 1U & 0x1f));
      }
      else {
        (&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20] = DAT_00679ed0;
      }
    }
    if (arg_3 == 0x73) {
      iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20]);
      uVar3 = Minit_Subsystem_004528c0(player,card_slot,0x73,iVar2);
    }
    else if (arg_3 == 0x6d) {
      iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20]);
      uVar3 = Minit_Subsystem_004528c0(player,card_slot,0x6d,iVar2);
    }
    else {
      if (arg_3 == 0x72) {
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x25);
        }
        if (player == g_CurrentTurnPhase) {
          cVar1 = Math_RandomRange(5);
          (&DAT_006a5f4c)
          [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] =
               (char)(1 << (cVar1 + 1U & 0x1f));
        }
        else {
          (&DAT_006a5f4c)
          [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] =
               DAT_00679ed0;
        }
      }
      if (arg_3 == 0x7f) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20]);
        uVar3 = Minit_Subsystem_004528c0(player,card_slot,0x7f,iVar2);
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



/*
 * Decompiled function: Mana_Init_004532f1
 * Entry Point: 004532f1
 * Size: 514 bytes
 */


undefined4 Mana_Init_004532f1(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (player == g_CurrentTurnPhase) {
        iVar2 = Math_RandomRange(5);
        local_10 = iVar2 + 1;
      }
      else {
        local_8 = -1;
        for (local_c = 1; local_c < 7; local_c = local_c + 1) {
          if (local_8 < *(int *)(&DAT_006ff690 + local_c * 4 + player * 0x20)) {
            local_8 = *(int *)(&DAT_006ff690 + local_c * 4 + player * 0x20);
            local_10 = local_c;
          }
        }
      }
      if (player == 1) {
        local_14 = local_10;
      }
      else {
        local_14 = -1;
      }
      iVar2 = Ai_Subsystem_004cc93d(player,s_What_kind_of_mana__00523f40,1,local_14,0xffffffff);
      if (iVar2 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0040d875(player,iVar2,1);
        Mem_AllocOrFree_0041df33(player,1,player,card_slot);
        *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        DAT_006ff2d4 = iVar2;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045350d
 * Entry Point: 0045350d
 * Size: 670 bytes
 */


undefined4 Minit_Subsystem_0045350d(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((g_ScWillyScore < 0x1a) || (0x1d < g_ScWillyScore)) ||
         (iVar2 = Ai_Subsystem_004cc814
                            (player,s_Desert__00523f64,1,s_Damage_00523f5c,&DAT_00523f54,(char *)0x0)
         , iVar2 != 0)) {
        FUN_0040d875(player,0,1);
        DAT_006ff2d4 = 0;
      }
      else {
        iVar2 = Glue_Subsystem_004e69ac(player,1 - player,card_slot);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          if (((&g_CardSlot_Flags)
               [*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120] & 0x44)
              != 0) {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),1,player
                         ,card_slot);
          }
          (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
          FUN_0040d82b(player,0,1);
          *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        }
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_004537b0
 * Entry Point: 004537b0
 * Size: 1200 bytes
 */


undefined4 Minit_Subsystem_004537b0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    local_14 = (uint)(((byte)g_PlayerHandCardCount & 4) != 0);
    if (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0) {
      local_14 = 0;
    }
    if (((local_14 != 0) && (((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0)) {
      local_14 = 0;
    }
    if (local_14 != 0) {
      local_14 = UI_PaintBigCardInfo((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                              0xffffffff,0xffffffff,0,0,0);
    }
    if (local_14 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((flags == 0x6d) && (((byte)g_PlayerHandCardCount & 4) != 0)) {
      if (DAT_006ff4ac == 0) {
        local_8 = 0;
        while (local_8 == 0) {
          Pic_Subsystem_00424500(s_prompts_txt_00523f74,s_OASIS_00523f6c);
          iVar2 = Action_ValidateTarget_00405802
                            (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,
                             0,0,&g_OverworldGoldAmount,1,&local_10);
          if (iVar2 == 0) {
            g_ActivePlayer = 1;
            local_8 = 1;
          }
          else if (*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x5b20 + local_c * 0x120) == -1)
          {
            if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_target__damage_type___00523f80);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_00523fa0);
            }
          }
          else {
            local_8 = 1;
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
            *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
            *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          }
        }
      }
      else {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        g_ActivePlayer = 1;
      }
    }
    if ((flags == 0x72) && ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')
       ) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1
                         ,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 != 0) {
        if (*(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) + -1;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00453c60
 * Entry Point: 00453c60
 * Size: 886 bytes
 */


undefined4 Minit_Subsystem_00453c60(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(player,card_slot,1,0);
    return uVar1;
  }
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      if ((((byte)g_PlayerHandCardCount & 4) == 0) ||
         (iVar2 = Ai_Subsystem_004cc814
                            (player,s_Elephant_s_Graveyard__00523fb8,1,s_Regenerate_00523fac,
                             &DAT_00523fa4,(char *)0x0), iVar2 != 0)) {
        FUN_0040d875(player,0,1);
        DAT_006ff2d4 = 0;
      }
      else {
        if ((local_c != -1) &&
           (((&DAT_0051aebd)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20)
              * 0x34] == '\n' ||
            ((&DAT_0051aebd)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20)
              * 0x34] == '\v')))) {
          (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
          *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = local_c;
          *(uint *)(&g_CardSlot_Abilities2 +
                   *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities2 +
                        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) *
                          0x5b20) | 0x200;
        }
        FUN_0040d82b(player,0,1);
      }
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (((byte)g_PlayerHandCardCount & 4) == 0) {
      *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
    }
    if ((((arg_3 == 0x34) &&
         (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) ==
          g_EventSourceSlot)) &&
        ((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer))
       && (g_EventSourceSlot != -1)) {
      g_CardEventResult = g_CardEventResult | 0x200;
    }
    return 0;
  }
  if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 00453fdb
 * Size: 1016 bytes
 */


undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags)

{
  int color_mask;
  int iVar1;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  undefined4 local_14;
  int local_8;
  
  if (flags == 1) {
    local_14 = Minit_Subsystem_004528c0(spell_id,target_id,1,0);
  }
  else if (flags == 0x71) {
    local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x71,0);
  }
  else if (flags == 0x73) {
    local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x73,0);
  }
  else if (flags == 0x6d) {
    local_14 = 0;
    strcpy(&g_OverworldWorldState,s_Get_mana__00523fd0);
    strcat(&g_OverworldWorldState,s_Sacrifice_to_destroy_a_land__00523fdc);
    strcat(&g_OverworldWorldState,s_Cancel__00523ffc);
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    if (DAT_00695ec8 == 0) {
      local_8 = 0;
    }
    else if (DAT_006ff4ac == 0) {
      if (spell_id == g_CurrentTurnPhase) {
        local_8 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,1);
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x6d,0);
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    else if (local_8 == 1) {
      DAT_006ff2d4 = 0xffffffff;
      Pic_Subsystem_00424500(s_prompts_txt_00524014,s_STRIPMINE_00524008);
      iVar1 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0xf);
        }
        Pic_Subsystem_0044867e(spell_id,target_id,3);
        FUN_0040d82b(spell_id,0,1);
      }
    }
    else {
      g_ActivePlayer = 1;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
  }
  else {
    if ((flags == 0x72) && ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')
       ) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (iVar1,color_mask,(char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,
                         iVar2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(iVar1,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (flags == 0x7f) {
      local_14 = Minit_Subsystem_004528c0(spell_id,target_id,0x7f,0);
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}



/*
 * Decompiled function: Minit_Subsystem_004543d3
 * Entry Point: 004543d3
 * Size: 495 bytes
 */


undefined4 Minit_Subsystem_004543d3(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = Glue_Subsystem_004e69ac(player,player,card_slot);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) == player) {
          iVar2 = Magic_QueryCardValue(*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                               *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                               0x33,0xffffffff);
          (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + iVar2;
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),3);
        }
        *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_004545c7
 * Entry Point: 004545c7
 * Size: 310 bytes
 */


undefined4 Minit_Subsystem_004545c7(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      Magic_ExecuteDrawPhase(player);
      Magic_ExecuteDrawPhase(player);
      for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
        if (0 < (int)(&DAT_006b3008)[player]) {
          Prompts_Load_0046fa40(player,0,0);
        }
      }
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Card_Setup_00454702
 * Entry Point: 00454702
 * Size: 739 bytes
 */


undefined4 Card_Setup_00454702(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  uint local_8;
  
  if (arg_3 == 1) {
    uVar2 = Minit_Subsystem_004528c0(player,card_slot,1,0);
  }
  else if (arg_3 == 0x71) {
    uVar2 = Minit_Subsystem_004528c0(player,card_slot,0x71,0);
  }
  else if (arg_3 == 0x73) {
    uVar2 = Minit_Subsystem_004528c0(player,card_slot,0x73,0);
  }
  else {
    if (arg_3 == 0x6d) {
      strcpy(&g_OverworldWorldState,s_Get_mana__00524020);
      iVar1 = (&DAT_006b3008)[player];
      if (iVar1 != 7) {
        strcat(&g_OverworldWorldState,s___Draw_a_card__0052403c);
      }
      else {
        strcat(&g_OverworldWorldState,s_Draw_a_card__0052402c);
      }
      local_c = (uint)(iVar1 == 7);
      strcat(&g_OverworldWorldState,s_Cancel__0052404c);
      if (DAT_00695ec8 == 0) {
        local_8 = 0;
      }
      else if (DAT_006ff4ac == 0) {
        if (player == g_CurrentTurnPhase) {
          local_8 = Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,&g_OverworldWorldState,local_c);
        }
        else {
          local_8 = local_c;
        }
      }
      else {
        local_8 = 0;
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      if (local_8 == 0) {
        uVar2 = Minit_Subsystem_004528c0(player,card_slot,0x6d,0);
        return uVar2;
      }
      if (local_8 == 1) {
        *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        FUN_0040d82b(player,0,1);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
        DAT_006ff2d4 = 0xffffffff;
      }
      else {
        g_ActivePlayer = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 1)) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120) = 0;
      Magic_ExecuteDrawPhase(player);
    }
    if (arg_3 == 0x7f) {
      uVar2 = Minit_Subsystem_004528c0(player,card_slot,0x7f,0);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/*
 * Decompiled function: Mana_Init_004549ea
 * Entry Point: 004549ea
 * Size: 3033 bytes
 */


undefined4 Mana_Init_004549ea(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 arg_10;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 arg_11;
  int iVar8;
  undefined4 arg_12;
  uint uVar9;
  uint uVar10;
  undefined4 arg_14;
  uint uVar11;
  undefined4 arg_15;
  uint uVar12;
  undefined4 arg_16;
  uint uVar13;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 1) {
    uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,1,0);
    return uVar2;
  }
  if (flags == 0x6c) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
  }
  if (flags == 0x71) {
    uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,0x71,0);
    return uVar2;
  }
  if (flags == 0x73) {
    bVar1 = false;
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0)))
       ) {
      bVar1 = true;
    }
    iVar3 = Font_DrawString(spell_id, 7, 1);
    if (iVar3 != 0) {
      bVar1 = true;
    }
    if (bVar1) {
      if ((spell_id == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      return 1;
    }
    return 0;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar2 = Pic_Subsystem_0045268f(0x38e);
          *(undefined4 *)
           (&g_CardSlot_CardId +
           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               uVar2;
          *(undefined4 *)
           (&g_CardSlot_Controller +
           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(undefined4 *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120)
          ;
          *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) =
               *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) + 1;
          (&DAT_006b3018)[g_DialogPromptHwnd] = (&DAT_006b3018)[g_DialogPromptHwnd] + 1;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                        0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                         target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 2;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x6c,1 - g_DialogPromptHwnd,0xffffffff);
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                        0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                         target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 0x80;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x71,1 - g_DialogPromptHwnd,0xffffffff);
        }
        else if ((local_8 == 2) &&
                ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
          local_14 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          local_10 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          uVar13 = 0;
          uVar12 = 0;
          uVar11 = 0;
          uVar10 = 0xffffffff;
          uVar9 = 0xffffffff;
          iVar8 = -1;
          iVar3 = Pic_Subsystem_0045268f(0x38e);
          uVar7 = 0;
          uVar6 = 0;
          uVar5 = Glue_Subsystem_004d0a42(spell_id,target_id);
          iVar3 = Rules_ParseFilter_0040360b
                            (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,0,0,0,uVar5,uVar6,
                             uVar7,iVar3,iVar8,uVar9,uVar10,uVar11,uVar12,uVar13);
          if (iVar3 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, DAT_006a2854, local_14, local_10);
            if (local_c != -1) {
              *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + spell_id * 0x5b20) = 1;
              *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,0x7f,0);
      return uVar2;
    }
    if (((((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
         (target_id == g_EventSourceSlot)) &&
        ((spell_id == g_EventSourcePlayer &&
         (iVar3 = Card_IsTapped(spell_id, target_id), iVar3 != 0)))) &&
       (*(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      g_CardEventResult =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x30;
      }
    }
    return 0;
  }
  uVar2 = 0;
  local_24 = 3;
  if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))))
  {
    strcpy(&g_OverworldWorldState,s_Get_mana__00524058);
    local_24 = 0;
  }
  else {
    strcpy(&g_OverworldWorldState,s__Get_mana__00524064);
  }
  iVar3 = Font_DrawString(spell_id, 7, 1);
  if (iVar3 == 0) {
    strcat(&g_OverworldWorldState,s__Change_to_Assembly_Worker__00524094);
  }
  else {
    strcat(&g_OverworldWorldState,s_Change_to_Assembly_Worker__00524074);
    if (g_ScWillyScore < 0x17) {
      local_24 = 1;
    }
  }
  if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))))
  {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uVar4 = Pic_Subsystem_0045268f(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = Glue_Subsystem_004d0a42(spell_id,target_id);
    iVar3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uVar4,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar3 != 0) {
      strcat(&g_OverworldWorldState,s_Pump_Assembly_Worker__005240b4);
      if ((g_ScWillyScore < 0x1e) && (0x16 < g_ScWillyScore)) {
        local_24 = 2;
      }
      goto LAB_00454d93;
    }
  }
  strcat(&g_OverworldWorldState,s__Pump_Assembly_Worker__005240cc);
LAB_00454d93:
  strcat(&g_OverworldWorldState,s_Cancel__005240e8);
  if (DAT_006ff4ac == 0) {
    local_8 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = local_8;
  if (local_8 == 0) {
    uVar2 = Minit_Subsystem_004528c0(spell_id,target_id,0x6d,0);
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
  }
  else if (local_8 == 1) {
    uVar5 = *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20);
    *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uVar5 & 0x40000) == 0) {
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xfffbffff;
    }
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    DAT_006ff2d4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    Pic_Subsystem_00424500(s_prompts_txt_00524104,s_MISHRAS_FACTORY_005240f4);
    arg_20 = &local_14;
    uVar4 = 1;
    arg_18 = &g_OverworldGoldAmount;
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    iVar8 = -1;
    iVar3 = Pic_Subsystem_0045268f(0x38e);
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = Glue_Subsystem_004d0a42(spell_id,target_id);
    iVar3 = Action_ValidateTarget_00405802
                      (spell_id,2,spell_id,0x200,0,0,0,uVar5,uVar6,uVar7,iVar3,iVar8,uVar9,uVar10,
                       uVar11,uVar12,uVar13,arg_18,uVar4,arg_20);
    if (iVar3 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      FUN_0040d82b(spell_id,0,1);
      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10;
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
    }
    DAT_006ff2d4 = 0xffffffff;
  }
  else {
    g_ActivePlayer = 1;
  }
  if (0 < DAT_006ff550) {
    DAT_006ff550 = DAT_006ff550 + -1;
  }
  return uVar2;
}



/*
 * Decompiled function: Mana_Init_004555c8
 * Entry Point: 004555c8
 * Size: 2960 bytes
 */


undefined4 Mana_Init_004555c8(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 arg_10;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_24;
  undefined4 local_20;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x22) {
    uVar1 = Pic_Subsystem_0045268f(0x1fc);
    *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) = uVar1;
    *(undefined4 *)(&g_CardSlot_Controller + spell_id * 0x5b20 + target_id * 0x120) = 0;
    (&DAT_006b3018)[spell_id] = (&DAT_006b3018)[spell_id] + -1;
    *(int *)(&DAT_006b3010 + spell_id * 4) = *(int *)(&DAT_006b3010 + spell_id * 4) + -1;
    DAT_00679ec8 = spell_id;
    DAT_00679ec4 = target_id;
    Glue_Subsystem_004e65e1(Minit_Subsystem_00456158,spell_id);
  }
  if (((flags == 0x77) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    uVar1 = Pic_Subsystem_0045268f(0x1fc);
    *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) = uVar1;
    return 0;
  }
  if (flags == 1) {
    uVar1 = Minit_Subsystem_004528c0(spell_id,target_id,1,0);
    return uVar1;
  }
  if (flags == 0x71) {
    uVar1 = Minit_Subsystem_004528c0(spell_id,target_id,0x71,0);
    return uVar1;
  }
  if (flags == 0x73) {
    local_18 = 0;
    if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0)))
       ) {
      local_18 = 1;
    }
    iVar2 = Font_DrawString(spell_id, 7, 1);
    if (iVar2 == 0) {
      return local_18;
    }
    return 1;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120);
      if (local_8 != 0) {
        if (local_8 == 1) {
          uVar1 = Pic_Subsystem_0045268f(0x38e);
          *(undefined4 *)
           (&g_CardSlot_CardId +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               uVar1;
          *(undefined4 *)
           (&g_CardSlot_Controller +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               *(undefined4 *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120)
          ;
          *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) =
               *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) + 1;
          (&DAT_006b3018)[g_DialogPromptHwnd] = (&DAT_006b3018)[g_DialogPromptHwnd] + 1;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) | 2;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x6c,1 - g_DialogPromptHwnd,0xffffffff);
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) | 0x80;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x71,1 - g_DialogPromptHwnd,0xffffffff);
        }
        else if ((local_8 == 2) &&
                ((&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] != '\0')) {
          local_14 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
          local_10 = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 0xffffffff;
          uVar7 = 0xffffffff;
          iVar6 = -1;
          iVar2 = Pic_Subsystem_0045268f(0x38e);
          uVar5 = 0;
          uVar4 = 0;
          uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
          iVar2 = Rules_ParseFilter_0040360b
                            (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,0,0,0,uVar3,uVar4,
                             uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
          if (iVar2 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, DAT_006a2854, local_14, local_10);
            if (local_c != -1) {
              *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + spell_id * 0x5b20) = 1;
              *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
        }
      }
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uVar1 = Minit_Subsystem_004528c0(spell_id,target_id,0x7f,0);
      return uVar1;
    }
    return 0;
  }
  local_20 = 0;
  local_24 = 3;
  if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))))
  {
    strcpy(&g_OverworldWorldState,s_Get_mana__00524110);
    local_24 = 0;
  }
  else {
    strcpy(&g_OverworldWorldState,s__Get_mana__0052411c);
  }
  iVar2 = Font_DrawString(spell_id, 7, 1);
  if (iVar2 == 0) {
    strcat(&g_OverworldWorldState,s__Re_change_to_Assembly_Worker__0052414c);
  }
  else {
    strcat(&g_OverworldWorldState,s_Re_change_to_Assembly_Worker__0052412c);
  }
  if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))))
  {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uVar1 = Pic_Subsystem_0045268f(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = Glue_Subsystem_004d0a42(spell_id,target_id);
    iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uVar1,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (iVar2 != 0) {
      strcat(&g_OverworldWorldState,s_Pump_Assembly_Worker__00524170);
      if ((g_ScWillyScore < 0x1e) && (0x16 < g_ScWillyScore)) {
        local_24 = 2;
      }
      goto LAB_004559f9;
    }
  }
  strcat(&g_OverworldWorldState,s__Pump_Assembly_Worker__00524188);
LAB_004559f9:
  strcat(&g_OverworldWorldState,s_Cancel__005241a4);
  if (DAT_006ff4ac == 0) {
    local_8 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,local_24);
  }
  else {
    local_8 = 0;
  }
  *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = local_8;
  if (local_8 == 0) {
    local_20 = Minit_Subsystem_004528c0(spell_id,target_id,0x6d,0);
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
  }
  else if (local_8 == 1) {
    uVar3 = *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120);
    *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uVar3 & 0x40000) == 0) {
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0xfffbffff;
    }
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    DAT_006ff2d4 = 0xffffffff;
  }
  else if (local_8 == 2) {
    Pic_Subsystem_00424500(s_prompts_txt_005241c0,s_ASSEMBLY_WORKER_005241b0);
    arg_20 = &local_14;
    uVar1 = 1;
    arg_18 = &g_OverworldGoldAmount;
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    uVar8 = 0xffffffff;
    uVar7 = 0xffffffff;
    iVar6 = -1;
    iVar2 = Pic_Subsystem_0045268f(0x38e);
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    iVar2 = Action_ValidateTarget_00405802
                      (spell_id,2,spell_id,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,uVar8,
                       uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
    if (iVar2 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      FUN_0040d82b(spell_id,0,1);
      *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_14;
      *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_10;
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
    }
    DAT_006ff2d4 = 0xffffffff;
  }
  else {
    g_ActivePlayer = 1;
  }
  return local_20;
}



/*
 * Decompiled function: Minit_Subsystem_00456158
 * Entry Point: 00456158
 * Size: 192 bytes
 */


undefined4 Minit_Subsystem_00456158(int player,int card_slot,int arg_3)

{
  if (((((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == DAT_00679ec8) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == DAT_00679ec4)) &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 4) != 0)) &&
     (*(int *)(&DAT_006b3088 + *(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) * 0x98) != 0x6d)) {
    Pic_Subsystem_0044867e(player,card_slot,2);
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00456218
 * Entry Point: 00456218
 * Size: 477 bytes
 */


undefined4 Minit_Subsystem_00456218(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if ((arg_3 == 0x71) && (g_IsAiThinking != 1)) {
    Duel_PlaySoundById(8);
  }
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d901(player,6,3);
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      DAT_006ff2d4 = 6;
    }
    if (((arg_3 == 0x7f) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      if (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
         (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
        FUN_0040d7e9(player,6,3);
      }
      *(uint *)(&DAT_0063eed0 + player * 4) = *(uint *)(&DAT_0063eed0 + player * 4) | 0x40;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_004563fa
 * Entry Point: 004563fa
 * Size: 339 bytes
 */


undefined4 Minit_Subsystem_004563fa(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d875(player,0,1);
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      DAT_006ff2d4 = 0;
      DAT_00679ecc = 0;
      Glue_Subsystem_004e65e1(Minit_Subsystem_00456552,player);
      if (DAT_00679ecc == 7) {
        FUN_0040d875(player,0,1);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00456552
 * Entry Point: 00456552
 * Size: 133 bytes
 */


undefined4 Minit_Subsystem_00456552(undefined4 player,undefined4 card_slot,int arg_3)

{
  int iVar1;
  
  if ((&DAT_0051aebd)[arg_3 * 0x34] == '\b') {
    iVar1 = Pic_Subsystem_0045268f(0x21d);
    if (iVar1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 1;
    }
    iVar1 = Pic_Subsystem_0045268f(0x21f);
    if (iVar1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 2;
    }
    iVar1 = Pic_Subsystem_0045268f(0x220);
    if (iVar1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 4;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004565d7
 * Entry Point: 004565d7
 * Size: 339 bytes
 */


undefined4 Minit_Subsystem_004565d7(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[player * 0x5b20 + card_slot * 0x120] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d875(player,0,1);
      *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
           *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
      DAT_006ff2d4 = 0;
      DAT_00679ecc = 0;
      Glue_Subsystem_004e65e1(Minit_Subsystem_00456552,player);
      if (DAT_00679ecc == 7) {
        FUN_0040d875(player,0,2);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045672f
 * Entry Point: 0045672f
 * Size: 1364 bytes
 */


undefined4 Minit_Subsystem_0045672f(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  int *arg_20;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int arg_15;
  uint uVar7;
  uint arg_17;
  uint uVar8;
  undefined1 *arg_18;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_18;
  uint local_14 [2];
  uint local_c;
  uint local_8;
  
  if (flags == 0x73) {
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0)))
       ) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if (DAT_006ff4ac == 0) {
        Ai_CalcManaRequirement_004ba890(spell_id,0,3);
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_005241d4,s_ARENA_005241cc);
          for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
            arg_20 = (int *)(((spell_id == 0) - 1 & (int)&local_c - (int)local_14) + (int)local_14);
            uVar3 = (uint)(spell_id == local_18);
            arg_18 = &g_OverworldGoldAmount;
            arg_17 = 0;
            uVar11 = 0;
            uVar10 = 0;
            uVar9 = 0xffffffff;
            uVar8 = 0xffffffff;
            iVar6 = -1;
            iVar5 = -1;
            uVar7 = 0;
            uVar4 = 0;
            uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
            iVar5 = Action_ValidateTarget_00405802
                              (spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,uVar4,uVar7,iVar5,iVar6,
                               uVar8,uVar9,uVar10,uVar11,arg_17,arg_18,uVar3,arg_20);
            if (iVar5 == 0) {
              g_ActivePlayer = 1;
            }
          }
          if (g_ActivePlayer != 1) {
            if (((((char)local_c == '\0') && ((local_8 & 0xffff) == 0)) &&
                ((local_14[0] & 0xffffff) == 0)) && (local_14[1] == 0)) {
              *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                   = 0;
            }
            else {
              *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                   = 1;
            }
          }
        }
      }
      else {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x72) {
      local_c = *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) >>
                0x18;
      local_8 = (*(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
                0xff0000) >> 0x10;
      local_14[0] = (uint)(byte)(&DAT_006a5f55)[target_id * 0x120 + spell_id * 0x5b20];
      local_14[1] = *(uint *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                    & 0xff;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,1,1,1,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6
                         ,uVar7,uVar8,uVar9,uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      arg_15 = -1;
      iVar6 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0040360b
                        (local_14[0],local_14[1],(char *)0x0,0,0,0,0x200,2,0,0,uVar2,uVar3,uVar4,
                         iVar6,arg_15,uVar7,uVar8,uVar9,uVar10,uVar11);
      if ((iVar5 == 0) || (iVar6 == 0)) {
        if ((iVar5 == 0) || (iVar6 != 0)) {
          if (((iVar5 == 0) && (iVar6 != 0)) &&
             (*(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) | 0x10,
             *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) != -1)) {
            iVar5 = Magic_QueryCardValue(local_c,local_8,0x32,0xffffffff);
            Card_ApplyCombatDamage(local_14[0],local_14[1],iVar5,local_c,local_8);
          }
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) | 0x10;
          if (*(int *)(&g_CardSlot_CardId + local_14[1] * 0x120 + local_14[0] * 0x5b20) != -1) {
            iVar5 = Magic_QueryCardValue(local_14[0],local_14[1],0x32,0xffffffff);
            Card_ApplyCombatDamage(local_c,local_8,iVar5,local_14[0],local_14[1]);
          }
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) | 0x10;
        *(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_14[0] * 0x5b20 + local_14[1] * 0x120) | 0x10;
        iVar5 = Magic_QueryCardValue(local_c,local_8,0x32,0xffffffff);
        iVar6 = Magic_QueryCardValue(local_14[0],local_14[1],0x32,0xffffffff);
        Card_ApplyCombatDamage(local_c,local_8,iVar6,local_14[0],local_14[1]);
        Card_ApplyCombatDamage(local_14[0],local_14[1],iVar5,local_c,local_8);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00456d10
 * Entry Point: 00456d10
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d10(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456d36
 * Entry Point: 00456d36
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d36(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456d5c
 * Entry Point: 00456d5c
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d5c(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456d82
 * Entry Point: 00456d82
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d82(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456da8
 * Entry Point: 00456da8
 * Size: 38 bytes
 */


void Minit_Subsystem_00456da8(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456dce
 * Entry Point: 00456dce
 * Size: 347 bytes
 */


undefined4 Minit_Subsystem_00456dce(int x,int y,int width,int height)

{
  undefined4 uVar1;
  
  if (width == 0x73) {
    if (((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0xc;
      FUN_0040d901(x,height,1);
      *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_006ff2d4 = height;
    }
    if ((((width == 0x7f) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) &&
       (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      FUN_0040d7e9(x,height,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Mana_Init_00456f29
 * Entry Point: 00456f29
 * Size: 897 bytes
 */


undefined4 Mana_Init_00456f29(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int card_slot;
  char *str_2;
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0x24;
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
        local_10 = -1;
        local_c = 1;
        while ((local_c < 6 && (local_10 == -1))) {
          if ((0 < (&DAT_006b2d40)[local_c]) &&
             (((int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20] &
              1 << ((byte)local_c & 0x1f)) != 0)) {
            local_10 = local_c;
          }
          local_c = local_c + 1;
        }
        if ((local_10 == -1) && (0 < DAT_006b2d40)) {
          local_10 = 1;
        }
        if ((local_10 == -1) && (0 < DAT_006b2d58)) {
          local_10 = 1;
        }
        if (local_10 == -1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        local_10 = -1;
      }
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_005241ec,s_BLACK_LOTUS_005241e0);
        card_slot = Ai_Subsystem_004cc93d
                          (spell_id,&g_OverworldGoldAmount,1,local_10,
                           (int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20]);
        if (card_slot == -1) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_0040d875(spell_id,card_slot,3);
          DAT_006ff2d4 = card_slot;
          if (g_IsAiThinking != 1) {
            Duel_PlaySoundById(0xf);
          }
          *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          if (g_CurrentTurnPhase != spell_id) {
            strcpy(&g_OverworldWorldState,s_to_produce_005241f8);
            str_2 = (char *)Mem_AllocOrFree_00473d7e(card_slot);
            strcat(&g_OverworldWorldState,str_2);
            strcat(&g_OverworldWorldState,s_mana__00524204);
            Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
          }
          Pic_Subsystem_0044867e(spell_id,target_id,3);
        }
      }
    }
    if ((((flags == 0x7f) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      FUN_0040d59c(spell_id,(int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20],3);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_004572aa
 * Entry Point: 004572aa
 * Size: 1181 bytes
 */


undefined4 Minit_Subsystem_004572aa(int spell_id,int target_id,int flags)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  if ((flags == 0x82) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
    *(uint *)(&DAT_006a6038 + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&DAT_006a6038 + spell_id * 0x5b20 + target_id * 0x120) & 0xfffffffc;
  }
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
    *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 1;
  }
  if (((flags == 0x6a) && (spell_id == g_DefendingPlayer)) &&
     ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0 &&
      (iVar2 = Glue_Subsystem_004e6978(spell_id,target_id), iVar2 == 0)))) {
    Pic_Subsystem_0042475a(s_prompts_txt_00524218,s_TIME_VAULT_0052420c);
    iVar2 = Math_RandomRange(5);
    iVar2 = Ai_Subsystem_004cc56d
                      (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,(uint)(iVar2 < 1));
    if (iVar2 != 0) {
      g_PlayerHandCardCount = g_PlayerHandCardCount | 0x8000;
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0xffffffef;
      Glue_Subsystem_004e66b3(spell_id,target_id);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
    }
  }
  if (flags == 0x73) {
    if ((((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (iVar2 = Glue_Subsystem_004e6978(spell_id,target_id), iVar2 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (iVar2 = Glue_Subsystem_004e6978(spell_id,target_id), iVar2 != 0)) {
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    }
    if (flags == 0x72) {
      iVar2 = rand();
      if (iVar2 % 5 < 1) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
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
          DAT_006ff2d8 = spell_id;
        }
      }
      Glue_Subsystem_004e676b(g_DialogPromptHwnd,g_DuelArenaHwnd);
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 1;
      iVar2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,-1,-1);
      *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) | 0x120;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Minit_Subsystem_00457747
 * Entry Point: 00457747
 * Size: 562 bytes
 */


undefined4 Minit_Subsystem_00457747(int player,int card_slot,int arg_3)

{
  int iVar1;
  int local_c;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      local_c = g_ActivePlayerPriority;
    }
    else {
      local_c = g_CurrentTurnPhase;
    }
    iVar1 = (&DAT_006b3008)[local_c] + -4;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      if (local_c == 0) {
        iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
      }
      else {
        iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
      }
    }
  }
  if ((((g_CurrentStepCode == 0xcb) && (card_slot == g_EventSourceSlot)) &&
      (player == g_EventSourcePlayer)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      local_c = g_ActivePlayerPriority;
    }
    else {
      local_c = g_CurrentTurnPhase;
    }
    if ((local_c == g_DefendingPlayer) && (4 < (int)(&DAT_006b3008)[local_c])) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (arg_3 == 0x7e) {
        Mem_AllocOrFree_0041df33(local_c,(&DAT_006b3008)[local_c] + -4,player,card_slot);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457979
 * Entry Point: 00457979
 * Size: 566 bytes
 */


undefined4 Minit_Subsystem_00457979(int player,int card_slot,int arg_3)

{
  int iVar1;
  int local_c;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      local_c = g_ActivePlayerPriority;
    }
    else {
      local_c = g_CurrentTurnPhase;
    }
    iVar1 = 3 - (&DAT_006b3008)[local_c];
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      if (local_c == 0) {
        iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
      }
      else {
        iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[local_c] / iVar1;
        if (iVar1 < 2) {
          iVar1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
      }
    }
  }
  if ((((g_CurrentStepCode == 0xcb) && (card_slot == g_EventSourceSlot)) &&
      (player == g_EventSourcePlayer)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      local_c = g_ActivePlayerPriority;
    }
    else {
      local_c = g_CurrentTurnPhase;
    }
    if ((local_c == g_DefendingPlayer) && ((int)(&DAT_006b3008)[local_c] < 3)) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (arg_3 == 0x7e) {
        Mem_AllocOrFree_0041df33(local_c,3 - (&DAT_006b3008)[local_c],player,card_slot);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457baf
 * Entry Point: 00457baf
 * Size: 428 bytes
 */


undefined4 Minit_Subsystem_00457baf(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    iVar1 = (&DAT_006b3008)[player] + -4;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (player == 0) {
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
    }
    else {
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
  }
  if (((((g_CurrentStepCode == 0xc9) && (card_slot == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) &&
      ((player == g_DefendingPlayer && (DAT_006a4b5c == player)))) &&
     ((4 < (int)(&DAT_006b3008)[player] &&
      ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))))) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((arg_3 == 0x7e) && (4 < (int)(&DAT_006b3008)[player])) {
      (&g_PlayerCreatureCount)[player] =
           (&g_PlayerCreatureCount)[player] + (&DAT_006b3008)[player] + -4;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457d5b
 * Entry Point: 00457d5b
 * Size: 268 bytes
 */


undefined4 Minit_Subsystem_00457d5b(int player,int card_slot,int arg_3)

{
  int local_8;
  
  if ((arg_3 == 0x1f) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      local_8 = g_ActivePlayerPriority;
    }
    else {
      local_8 = g_CurrentTurnPhase;
    }
    if ((g_DefendingPlayer == local_8) && (4 < (int)(&DAT_006b3008)[g_DefendingPlayer])) {
      g_CardEventResult = g_CardEventResult | 1;
      while (4 < (int)(&DAT_006b3008)[g_DefendingPlayer]) {
        Prompts_Load_0046fa40(g_DefendingPlayer,0,0);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457e67
 * Entry Point: 00457e67
 * Size: 1839 bytes
 */


undefined4 Minit_Subsystem_00457e67(int spell_id,int target_id,int flags)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int local_164;
  int local_160;
  int local_15c;
  int local_150 [80];
  int local_10;
  int local_c;
  undefined4 local_8;
  
  if ((((g_CurrentStepCode == 0xcf) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
      (iVar3 = Font_DrawString(spell_id, 7, 1), iVar3 != 0)) &&
     (((g_EventSourceSlot == target_id && (g_EventSourcePlayer == spell_id)) &&
      (DAT_006a4b5c == spell_id)))) {
    if (flags == 0x7d) {
      if (g_ActivePlayerPriority == spell_id) {
        if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0)
            && (local_10 = Font_DrawString(spell_id,7,3), local_10 != 0)) &&
           (g_CardEventResult = g_CardEventResult | 2,
           *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
          iVar3 = Math_RandomRange(local_10 + -2);
          *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = iVar3 + 2;
          DAT_0062785c = *(undefined4 *)
                          (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (flags == 0x7e) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      iVar3 = g_TurnCounter;
      local_8 = g_OverworldPlayerCoordY;
      g_OverworldPlayerCoordY = 0xffffffff;
      if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Magic_CombatPhase(spell_id,target_id,0x72,0,0);
        Ai_CalcManaRequirement_004ba890(spell_id,0,-1);
        Magic_DiscardToHandSize();
        local_164 = g_TurnCounter;
      }
      else {
        local_164 = Ai_CalcManaRequirement_004ba890
                              (spell_id,0,
                               *(int *)(&g_CardSlot_TargetSlot +
                                       target_id * 0x120 + spell_id * 0x5b20));
        if (local_164 == 0) {
          g_ActivePlayer = 1;
        }
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      g_OverworldPlayerCoordY = local_8;
      g_TurnCounter = iVar3;
      if ((g_ActivePlayer == 1) || (local_164 < 1)) {
        g_ActivePlayer = -1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        local_10 = 0;
        for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
          if (*(int *)(&DAT_0069e730 + local_160 * 4 + spell_id * 2000) != -1) {
            local_150[local_10] = *(int *)(&DAT_0069e730 + local_160 * 4 + spell_id * 2000);
            local_10 = local_10 + 1;
          }
        }
        local_150[local_10] = -1;
        if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
          Pic_Subsystem_00424500(s_prompts_txt_00524234,s_ALADDINS_LAMP_00524224);
          local_15c = Pic_Load_004509e8(spell_id,(int)local_150,local_10,&g_OverworldGoldAmount,1);
        }
        else {
          local_15c = FUN_004fdc20(spell_id,spell_id,2,(int)local_150);
          if (local_15c == -1) {
            local_15c = 0;
          }
        }
        if (local_10 != 0) {
          Pic_Subsystem_00451291(spell_id,local_150[local_15c]);
          for (local_160 = 0; local_160 < local_10; local_160 = local_160 + 1) {
            Pic_Subsystem_004523fd(spell_id,0);
          }
          local_150[local_15c] = -1;
          bVar2 = false;
          while (!bVar2) {
            local_160 = 0;
            do {
              local_15c = Math_RandomRange(local_164);
              if (local_150[local_15c] != -1) break;
              bVar1 = local_160 < 999;
              local_160 = local_160 + 1;
            } while (bVar1);
            if (local_150[local_15c] == -1) {
              for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
                if (local_150[local_160] != -1) {
                  local_15c = local_160;
                }
              }
            }
            if (local_150[local_15c] == -1) {
              bVar2 = true;
            }
            else {
              Pic_Subsystem_0045245e(spell_id,local_150[local_15c]);
              local_150[local_15c] = -1;
            }
          }
        }
        DAT_006fe408 = 1;
      }
    }
  }
  if ((flags == 0x6a) && (g_ActivePlayerPriority == spell_id)) {
    *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    local_c = 0;
    local_10 = 0;
    for (local_160 = 0; local_160 < (int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        local_160 = local_160 + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
             -1) && (((&g_CardSlot_Flags)[local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                     != 0)) &&
          (((&DAT_0051aed1)
            [*(int *)(&g_CardSlot_CardId + local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
             0x34] & 0x10) != 0)) &&
         (local_10 = local_10 + 1,
         ((&g_CardSlot_Flags)[local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0)) {
        local_c = local_c + 1;
      }
    }
    if (0x50 < (local_c * 100) / local_10) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 2;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458596
 * Entry Point: 00458596
 * Size: 322 bytes
 */


undefined4 Minit_Subsystem_00458596(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,2);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[player * 0x5b20 + card_slot * 0x120] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
    }
    if (arg_3 == 0x72) {
      Magic_ExecuteDrawPhase(player);
      Prompts_Load_0046fa40(player,0,0);
      *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
           *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_004586d8
 * Entry Point: 004586d8
 * Size: 445 bytes
 */


undefined4 Minit_Subsystem_004586d8(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      Pic_Subsystem_0044867e(player,card_slot,4);
    }
    if (arg_3 == 0x72) {
      for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
        if (*(int *)(&DAT_006ff710 + local_8 * 4 + player * 2000) != -1) {
          Pic_Subsystem_0045245e(player,*(undefined4 *)(&DAT_006ff710 + local_8 * 4 + player * 2000));
          *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + player * 2000) = 0xffffffff;
        }
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      Pic_Subsystem_00452276(player);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00458895
 * Entry Point: 00458895
 * Size: 882 bytes
 */


undefined4 Minit_Subsystem_00458895(int player,int card_slot,int arg_3)

{
  undefined1 uVar1;
  int iVar2;
  int local_18;
  
  if (arg_3 != 0x73) {
    if ((((arg_3 == 2) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
       (iVar2 = Font_DrawString(player,7,2), iVar2 != 0)) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    if (((arg_3 == 4) && (card_slot == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        ((iVar2 = Font_DrawString(player,7,2), iVar2 != 0 &&
         (Ai_CalcManaRequirement_004ba890(player,0,2), local_18 != -1)))))) {
      iVar2 = Card_UntapCard(player,card_slot,1);
      uVar1 = Card_UntapCard(player,card_slot,1);
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120) =
           *(undefined4 *)
            (&g_CardSlot_CardId +
            *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
            *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120);
      *(int *)(&g_CardSlot_CardId +
              *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
              *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120) =
           iVar2 + -1;
      (&DAT_006a5f4c)
      [*(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120] = uVar1;
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120 +
               *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120 +
                    *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20) |
           0x200;
    }
    if (((arg_3 == 0x77) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      iVar2 = Pic_Subsystem_0045268f(0x391);
      iVar2 = Pic_Subsystem_00451291(player,iVar2);
      if (iVar2 != -1) {
        *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + player * 0x5b20) | 2;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458c07
 * Entry Point: 00458c07
 * Size: 104 bytes
 */


undefined4 Minit_Subsystem_00458c07(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    Glue_Subsystem_004e65e1(Minit_Subsystem_00458c6f,-1);
    if (g_CardEventResult == 0) {
      Pic_Subsystem_0044867e(player,card_slot,4);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458c6f
 * Entry Point: 00458c6f
 * Size: 63 bytes
 */


undefined4 Minit_Subsystem_00458c6f(int arg1,int arg2)

{
  if (((&DAT_006a5f69)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458cae
 * Entry Point: 00458cae
 * Size: 1030 bytes
 */


undefined4 Minit_Subsystem_00458cae(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if ((((DAT_006a282c | DAT_006a2828) & 2) == 0) ||
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20,
       ((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) * 0x34] &
       0x40) != 0)) {
      g_ActivePlayer = 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) * 0x34]
          & 0x40) == 0) {
        iVar2 = Card_ApplyTriggerEffect(player,card_slot,DAT_006a2854,
                             (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
        if (iVar2 != -1) {
          *(undefined2 *)(&DAT_006a5f48 + iVar2 * 0x120 + player * 0x5b20) = 1;
          *(undefined2 *)(&DAT_006a5f4a + iVar2 * 0x120 + player * 0x5b20) = 1;
          *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + player * 0x5b20) | 0x20;
        }
        iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                     *(int *)(&g_CardSlot_OriginalCardId +
                                             card_slot * 0x120 + player * 0x5b20) * 0x120 +
                                     (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] *
                                     0x5b20));
        if (iVar2 != -1) {
          (&g_MasterCardColorTable)[iVar2 * 0x34] = 0x42;
          *(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) = iVar2;
        }
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = 0xff;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
             (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20];
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    if (arg_3 == 0x3b) {
      *(int *)(&DAT_00695eb0 + player * 4) = *(int *)(&DAT_00695eb0 + player * 4) + 1;
      *(int *)(&DAT_00695eb8 + player * 4) = *(int *)(&DAT_00695eb8 + player * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Card_Setup_004590b4
 * Entry Point: 004590b4
 * Size: 506 bytes
 */


undefined4 Card_Setup_004590b4(int player,int card_slot,int arg_3)

{
  if ((((arg_3 == 0x85) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_DefendingPlayer && (DAT_0063edc0 == player)))) {
    *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
  }
  if (((arg_3 == 4) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    if ((int)(&DAT_006b3008)[player] < 1) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    else {
      Prompts_Load_0046fa40(player,0,1);
    }
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_Unable_to_discard____Mishra_s_Wa_00524248,0);
    *(uint *)(&g_CardSlot_Flags +
             *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
             *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags +
                  *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) | 0x10;
    Mem_AllocOrFree_0041df33(player,3,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (card_slot == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if ((arg_3 == 199) && ((&DAT_006b3008)[player] != 0)) {
    Mem_AllocOrFree_0041df33(player,3,player,card_slot);
    g_SpellStackDepth = g_SpellStackDepth + 0x60;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004592ae
 * Entry Point: 004592ae
 * Size: 554 bytes
 */


undefined4 Minit_Subsystem_004592ae(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,6);
    if (((iVar1 == 0) || ((&DAT_006a2828)[player] == 0)) ||
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,6), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,6);
      strcpy(&g_OverworldWorldState,s_Pick_a_permanent_00524284);
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
      if (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      FUN_0041da41((int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20];
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_004594d8
 * Entry Point: 004594d8
 * Size: 759 bytes
 */


undefined4 Minit_Subsystem_004594d8(int spell_id,int target_id,int flags)

{
  int iVar1;
  int iVar2;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (spell_id == g_EventSourcePlayer)) {
    Pic_Subsystem_0042475a(s_prompts_txt_005242a4,s_PRIMAL_CLAY_00524298);
    iVar1 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,1);
    iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20));
    if (iVar2 != -1) {
      if (iVar1 == 0) {
        *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) = 1;
        *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34) = 6;
        (&DAT_0051aebd)[iVar2 * 0x34] = 0;
        *(undefined4 *)(&DAT_0051aecc + iVar2 * 0x34) = 0;
      }
      else if (iVar1 == 1) {
        *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) = 2;
        *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34) = 2;
        *(undefined4 *)(&DAT_0051aecc + iVar2 * 0x34) = 0x20;
      }
      else if (iVar1 == 2) {
        *(undefined2 *)(&DAT_0051aec2 + iVar2 * 0x34) = 3;
        *(undefined2 *)(&DAT_0051aec4 + iVar2 * 0x34) = 3;
        *(undefined4 *)(&DAT_0051aecc + iVar2 * 0x34) = 0;
      }
      *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = iVar2;
      *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
     ((g_EventSourceSlot == target_id &&
      ((spell_id == g_EventSourcePlayer &&
       (iVar1 = Card_IsTapped(spell_id, target_id), iVar1 != 0)))))) {
    g_CardEventResult =
         *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
  }
  if (((flags == 0x77) && (g_EventSourceSlot == target_id)) &&
     (spell_id == g_EventSourcePlayer)) {
    Mem_AllocOrFree_0041d942
              (*(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20));
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004597d4
 * Entry Point: 004597d4
 * Size: 1329 bytes
 */


undefined4 Minit_Subsystem_004597d4(int spell_id,int target_id,int flags)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short local_c;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    if (g_CurrentTurnPhase != spell_id) {
      if (g_IsAiThinking == 1) {
        g_AiDecisionScore = Math_RandomRange(7);
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
    }
    Pic_Subsystem_0042475a(s_prompts_txt_005242c0,s_SHAPESHIFTER_005242b0);
    local_c = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,g_AiDecisionScore)
    ;
    if (g_ActivePlayerPriority == spell_id) {
      local_c = (short)g_AiDecisionScore;
    }
    iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20));
    if (iVar2 != -1) {
      *(short *)(&DAT_0051aec2 + iVar2 * 0x34) = local_c;
      *(short *)(&DAT_0051aec4 + iVar2 * 0x34) = 7 - local_c;
      *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = iVar2;
      *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
     ((g_EventSourceSlot == target_id && (g_EventSourcePlayer == spell_id)))) {
    iVar2 = Card_IsTapped(spell_id, target_id);
    if (iVar2 != 0) {
      g_CardEventResult =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
  }
  if (flags == 0x73) {
    if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == spell_id)) &&
        (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 0)) &&
       (DAT_0063edc0 == spell_id)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = target_id;
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((flags == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20)
        != -1)) {
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      Pic_Subsystem_0042475a(s_prompts_txt_005242dc,s_SHAPESHIFTER_005242cc);
      sVar1 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,4);
      *(short *)(&DAT_0051aec2 +
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34) =
           sVar1;
      *(short *)(&DAT_0051aec4 +
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34) =
           7 - sVar1;
    }
    if (flags == 0x22) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Minit_Subsystem_00459d0a
 * Entry Point: 00459d0a
 * Size: 1041 bytes
 */


undefined4 Minit_Subsystem_00459d0a(int player,int card_slot,int arg_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    Glue_Subsystem_004e6913(player,card_slot,3);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
     ((g_EventSourceSlot == card_slot && (g_EventSourcePlayer == player)))) {
    iVar2 = Glue_Subsystem_004e6978(player,card_slot);
    g_CardEventResult = g_CardEventResult + iVar2;
  }
  if (arg_3 == 0x73) {
    bVar1 = false;
    if (((g_ScWillyScore == 4) && (g_DefendingPlayer == player)) && (DAT_0063edc0 == player)) {
      iVar2 = Glue_Subsystem_004e6978(player,card_slot);
      if (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) < iVar2) {
        bVar1 = true;
      }
      else {
        iVar2 = Minit_Subsystem_0045a120(player,card_slot);
        if (iVar2 != 0) {
          bVar1 = true;
        }
      }
    }
    if (bVar1) {
      if ((g_ActivePlayerPriority == player) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      iVar2 = Glue_Subsystem_004e6978(player,card_slot);
      iVar2 = iVar2 - *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20);
      iVar4 = Minit_Subsystem_0045a120(player,card_slot);
      if ((iVar2 == 3) || ((iVar2 != 0 && (iVar4 == 0)))) {
        Minit_Subsystem_0045a252(player,card_slot,iVar2);
      }
      else if ((iVar2 == 0) && (iVar4 != 0)) {
        *(uint *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) | 0x100;
      }
      else if ((iVar2 != 0) && (iVar4 != 0)) {
        iVar4 = Ai_Subsystem_004cc56d
                          (player,player,card_slot,-1,-1,s_Launch_tetravite__Dock_tetravite_005242e8,0);
        if (iVar4 == 0) {
          Minit_Subsystem_0045a252(player,card_slot,iVar2);
        }
        else {
          *(uint *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) | 0x100;
        }
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) != -1)) {
      if (((&DAT_006a5f61)[card_slot * 0x120 + player * 0x5b20] & 1) == 0) {
        Minit_Subsystem_0045a42a(player,card_slot);
      }
      else {
        Minit_Subsystem_0045a575(player,card_slot);
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
       (g_EventSourcePlayer == player)) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Minit_Subsystem_0045a120
 * Entry Point: 0045a120
 * Size: 306 bytes
 */


int Minit_Subsystem_0045a120(int arg1,int arg2)

{
  int iVar1;
  int local_14;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[local_8]; local_14 = local_14 + 1)
    {
      iVar1 = Card_IsTapped(local_8,local_14);
      if ((((iVar1 != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) * 0x34) ==
            0x37b)) &&
          ((char)(&g_CardSlot_DamageReceived)[local_14 * 0x120 + local_8 * 0x5b20] == arg1)) &&
         ((*(int *)(&g_CardSlot_TypeFlags + local_14 * 0x120 + local_8 * 0x5b20) == arg2 &&
          (*(int *)(&g_CardSlot_ConvertedManaCost + local_14 * 0x120 + local_8 * 0x5b20) == 0)))) {
        local_c = local_c + 1;
      }
    }
  }
  return local_c;
}



/*
 * Decompiled function: Minit_Subsystem_0045a252
 * Entry Point: 0045a252
 * Size: 472 bytes
 */


undefined4 Minit_Subsystem_0045a252(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  Pic_Subsystem_0042475a(s_prompts_txt_00524318,s_TETRAVUS_0052430c);
  if (flags < 3) {
    if (flags < 2) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
  }
  else {
    local_10 = 2;
  }
  uVar1 = Ai_Subsystem_004cc56d
                    (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount + local_10 * 0xfa,0);
  *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = uVar1;
  local_8 = (int)*(short *)(&DAT_006a5f46 + target_id * 0x120 + spell_id * 0x5b20);
  if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) <= flags) {
    local_c = 0;
    while ((local_c < *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) &&
           (0 < local_8))) {
      Glue_Subsystem_004e689b(spell_id,target_id,1);
      *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x2000000;
      local_8 = Magic_QueryCardValue(spell_id,target_id,0x33,0xffffffff);
      if (0 < local_8) {
        *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x4000000;
        Magic_QueryCardValue(spell_id,target_id,0x32,0xffffffff);
      }
      local_c = local_c + 1;
    }
  }
  if (0 < DAT_006ff550) {
    DAT_006ff550 = DAT_006ff550 + -1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045a42a
 * Entry Point: 0045a42a
 * Size: 331 bytes
 */


undefined4 Minit_Subsystem_0045a42a(int arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0;
      local_c < *(int *)(&g_CardSlot_TargetSlot +
                        *(int *)(&g_CardSlot_TapState + arg2 * 0x120 + arg1 * 0x5b20) * 0x5b20 +
                        *(int *)(&g_CardSlot_SicknessState + arg2 * 0x120 + arg1 * 0x5b20) * 0x120);
      local_c = local_c + 1) {
    iVar1 = Pic_Subsystem_0045268f(0x37b);
    iVar1 = Pic_Subsystem_00451291(arg1,iVar1);
    if (iVar1 != -1) {
      Pic_Subsystem_0042ac1f(arg1,iVar1);
      (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + arg1 * 0x5b20] = (undefined1)g_DialogPromptHwnd;
      *(undefined4 *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + arg1 * 0x5b20) = g_DuelArenaHwnd;
      *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + arg1 * 0x5b20) | 0x10;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + arg1 * 0x5b20) = 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045a575
 * Entry Point: 0045a575
 * Size: 532 bytes
 */


undefined4 Minit_Subsystem_0045a575(int spell_id,int target_id)

{
  bool bVar1;
  int iVar2;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined1 *arg_18;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    Pic_Subsystem_00424500(s_prompts_txt_00524330,s_TETRAVITE_00524324);
    arg_20 = &local_10;
    arg_19 = 1;
    arg_18 = &g_OverworldGoldAmount;
    arg_17 = 0;
    arg_16 = 0;
    arg_15 = 0;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = -1;
    iVar2 = Pic_Subsystem_0045268f(0x37b);
    iVar2 = Action_ValidateTarget_00405802
                      (spell_id,2,2,0x200,0,0,0,0,0,0,iVar2,arg_12,arg_13,arg_14,arg_15,arg_16,
                       arg_17,arg_18,arg_19,arg_20);
    if (iVar2 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      bVar1 = true;
      strcpy(&g_OverworldWorldState,s_Illegal_target__tetravite_not_re_0052433c);
      if ((((char)(&g_CardSlot_DamageReceived)[local_10 * 0x5b20 + local_c * 0x120] ==
            g_DialogPromptHwnd) &&
          (*(int *)(&g_CardSlot_TypeFlags + local_10 * 0x5b20 + local_c * 0x120) == g_DuelArenaHwnd)
          ) && (strcpy(&g_OverworldWorldState,s_Illegal_target__only_one_move_pe_00524370),
               *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) == 0))
      {
        Glue_Subsystem_004e66b3(g_DialogPromptHwnd,g_DuelArenaHwnd);
        Pic_Subsystem_0044867e(local_10,local_c,4);
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120
                + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                     0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120)
                             * 0x5b20) + 1;
        local_8 = local_8 + 1;
        bVar1 = false;
      }
      if ((bVar1) && (g_IsAiThinking != 1)) {
        Ai_Util_004cc42d(&g_OverworldWorldState);
        Sleep(2000);
        Ai_Util_004cc42d(&DAT_0052439c);
      }
    }
  } while ((g_ActivePlayer != 1) && (local_8 == 0));
  g_OverworldWorldState = 0;
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045a789
 * Entry Point: 0045a789
 * Size: 156 bytes
 */


undefined4 Minit_Subsystem_0045a789(int player,int card_slot,int arg_3)

{
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
     (g_EventSourcePlayer == player)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if (((arg_3 == 0x34) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_CardEventResult = g_CardEventResult | 0x20000;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045a825
 * Entry Point: 0045a825
 * Size: 474 bytes
 */


bool Minit_Subsystem_0045a825(int spell_id,int target_id,int flags)

{
  bool bVar1;
  int iVar2;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    Glue_Subsystem_004e6913(spell_id,target_id,3);
  }
  if (((flags == 0x32) || (flags == 0x33)) &&
     ((target_id == g_EventSourceSlot && (spell_id == g_EventSourcePlayer)))) {
    iVar2 = Glue_Subsystem_004e6978(spell_id,target_id);
    g_CardEventResult = g_CardEventResult + iVar2;
  }
  if (flags == 0x73) {
    iVar2 = Glue_Subsystem_004e6978(spell_id,target_id);
    bVar1 = 0 < iVar2;
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar1 = false;
  }
  else {
    if ((flags == 0x6d) && (iVar2 = Glue_Subsystem_004e6978(spell_id,target_id), 0 < iVar2)) {
      Pic_Subsystem_00424500(s_prompts_txt_005243ac,s_TRISKELION_005243a0);
      iVar2 = Glue_Subsystem_004df8ba(spell_id,target_id);
      if (iVar2 != 0) {
        *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x6000000;
        Glue_Subsystem_004e676b(spell_id,target_id);
      }
    }
    if (flags == 0x72) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045a9ff
 * Entry Point: 0045a9ff
 * Size: 1858 bytes
 */


undefined4 Minit_Subsystem_0045a9ff(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (flags == 0x73) {
    if ((g_ActivePlayerPriority == spell_id) &&
       (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_0042475a(s_prompts_txt_005243c8,s_URZAS_AVENGER_005243b8);
      iVar2 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,0);
      *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = iVar2 + 1;
      if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 5) {
        g_ActivePlayer = 1;
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    if (flags == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        if (((&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] == -1) &&
           (*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) == -1)) {
          local_8 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                                 g_DuelArenaHwnd);
          if (local_8 != -1) {
            *(undefined4 *)(&g_CardSlot_Abilities2 + local_8 * 0x120 + spell_id * 0x5b20) = 0;
            (&g_CardSlot_DamageReceived)
            [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
                 (undefined1)spell_id;
            *(int *)(&g_CardSlot_TypeFlags +
                    *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                    + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120) = local_8;
          }
        }
        else {
          local_8 = *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20);
        }
        if (local_8 != -1) {
          switch(*(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20)) {
          case 1:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x20;
            break;
          case 2:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x40;
            break;
          case 3:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x100;
            break;
          case 4:
            *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + spell_id * 0x5b20) |
                 0x80;
          }
          *(short *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) =
               *(short *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) + 1;
          *(short *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) =
               *(short *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) + 1;
        }
        *(undefined4 *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0x8000000;
        *(short *)(&DAT_006a5f48 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) =
             *(short *)(&DAT_006a5f48 +
                       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20) + -1;
        *(short *)(&DAT_006a5f4a +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) =
             *(short *)(&DAT_006a5f4a +
                       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20) + -1;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                             * 0x5b20) + 1;
        *(undefined4 *)
         (&g_CardSlot_TargetSlot +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
      }
    }
    if ((flags == 0x22) || (flags == 199)) {
      *(short *)(&DAT_006a5f48 + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&DAT_006a5f48 + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(undefined4 *)
                   (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      *(short *)(&DAT_006a5f4a + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&DAT_006a5f4a + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(undefined4 *)
                   (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(undefined4 *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
           (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045b156
 * Entry Point: 0045b156
 * Size: 940 bytes
 */


undefined4 Minit_Subsystem_0045b156(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    iVar1 = Font_DrawString(spell_id,7,2);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
        (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005243e0,s_MILLSTONE_005243d4);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_18);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_18;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_14
        ;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        local_10 = *(int *)(&DAT_0069e730 + iVar1 * 2000);
        if (local_10 != -1) {
          Pic_Subsystem_004523fd(iVar1,0);
          local_8 = Pic_Subsystem_00451291(iVar1,local_10);
          if (local_8 != -1) {
            Pic_Subsystem_0044913a(iVar1,local_8);
            *(undefined4 *)(&g_CardSlot_CardId + local_8 * 0x120 + iVar1 * 0x5b20) = 0xffffffff;
          }
        }
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x18);
        }
        if ((g_ScWillyScore == 0x1f) && (g_DefendingPlayer == g_CurrentTurnPhase)) {
          g_SpellStackDepth = g_SpellStackDepth + 0x18;
        }
      }
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x18;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Mana_Init_0045b502
 * Entry Point: 0045b502
 * Size: 727 bytes
 */


undefined4 Mana_Init_0045b502(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  char *str_2;
  int local_8;
  
  if (flags == 0x73) {
    iVar1 = Font_DrawString(spell_id,7,2);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((flags == 0x6d) && (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x18;
      Ai_CalcManaRequirement_004ba890(spell_id,0,2);
      if (g_ActivePlayer != 1) {
        if (spell_id == g_CurrentTurnPhase) {
          local_8 = -1;
        }
        else if (g_IsAiThinking == 1) {
          local_8 = DAT_006b1580 % 5 + 1;
          g_AiDecisionScore = local_8;
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
          if (g_AiDecisionScore < 6) {
            local_8 = g_AiDecisionScore;
          }
          else {
            g_ActivePlayer = 1;
          }
        }
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_005243fc,s_CELESTIAL_PRISM_005243ec);
          iVar1 = Ai_Subsystem_004cc93d
                            (spell_id,&g_OverworldGoldAmount,1,local_8,
                             (int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20]);
          if (iVar1 == -1) {
            g_ActivePlayer = 1;
          }
          if (g_ActivePlayer != 1) {
            FUN_0040d875(spell_id,iVar1,1);
            FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20],
                         1);
            *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
            DAT_006ff2d4 = iVar1;
            if (spell_id != g_CurrentTurnPhase) {
              strcpy(&g_OverworldWorldState,s_to_produce_00524408);
              str_2 = (char *)Mem_AllocOrFree_00473d7e(iVar1);
              strcat(&g_OverworldWorldState,str_2);
              strcat(&g_OverworldWorldState,s_mana__00524414);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Mana_Init_0045b7d9
 * Entry Point: 0045b7d9
 * Size: 1202 bytes
 */


undefined4 Mana_Init_0045b7d9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int card_slot;
  char *str_2;
  int local_10;
  int local_c;
  
  if (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) {
    FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
    (&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120] = (&DAT_0063eed0)[(1 - spell_id) * 4];
    FUN_0040d59c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if ((char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120] < '\x01') {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      else {
        if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
          local_10 = -1;
          local_c = 1;
          while ((local_c < 6 && (local_10 == -1))) {
            if ((0 < (&DAT_006b2d40)[local_c]) &&
               (((int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120] &
                1 << ((byte)local_c & 0x1f)) != 0)) {
              local_10 = local_c;
            }
            local_c = local_c + 1;
          }
          if ((local_10 == -1) && (0 < DAT_006b2d40)) {
            local_10 = 1;
          }
          if ((local_10 == -1) && (0 < DAT_006b2d58)) {
            local_10 = 1;
          }
          if (local_10 == -1) {
            g_ActivePlayer = 1;
          }
        }
        else {
          local_10 = -1;
        }
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_0052442c,s_FELLWAR_STONE_0052441c);
          card_slot = Ai_Subsystem_004cc93d
                            (spell_id,&g_OverworldGoldAmount,1,local_10,
                             (int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120]);
          if (card_slot == -1) {
            g_ActivePlayer = 1;
          }
          else {
            local_10._0_1_ = (byte)card_slot;
            if ((*(uint *)(&DAT_0063eed0 + (1 - spell_id) * 4) & 1 << ((byte)local_10 & 0x1f)) == 0)
            {
              g_ActivePlayer = 1;
            }
          }
          if (g_ActivePlayer != 1) {
            FUN_0040d875(spell_id,card_slot,1);
            FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],
                         1);
            *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
            DAT_006ff2d4 = card_slot;
            if (spell_id != g_CurrentTurnPhase) {
              strcpy(&g_OverworldWorldState,s_to_produce_00524438);
              str_2 = (char *)Mem_AllocOrFree_00473d7e(card_slot);
              strcat(&g_OverworldWorldState,str_2);
              strcat(&g_OverworldWorldState,s_mana__00524444);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
            }
          }
        }
      }
    }
    if ((((flags == 0x77) && (target_id == g_EventSourceSlot)) &&
        (spell_id == g_EventSourcePlayer)) &&
       (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[spell_id * 0x5b20 + target_id * 0x120],1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045bc8b
 * Entry Point: 0045bc8b
 * Size: 197 bytes
 */


undefined4 Minit_Subsystem_0045bc8b(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int arg_2_00;
  
  if (arg_3 == 0x73) {
    if (((*(byte *)(&DAT_006a2828 + player) & 2) == 0) ||
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      arg_2_00 = Glue_Subsystem_004e6bff(player);
      if (arg_2_00 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(player,arg_2_00,3);
      }
    }
    if (arg_3 == 0x72) {
      FUN_0040d875(player,0,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045bd50
 * Entry Point: 0045bd50
 * Size: 2117 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_0045bd50(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x82) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffd;
  }
  if (((g_ScWillyScore == 1) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    if (((flags == 0x7d) && (((&DAT_006a6038)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       ((((&DAT_006a6038)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
        ((_DAT_006ff198 &
         (byte)(&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34]) == 0))
       )) {
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
        iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        if ((iVar1 == -1) ||
           ((((&DAT_006a6038)
              [*(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[iVar1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 1) == 0
            && (((&g_CardSlot_Flags)
                 [*(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[iVar1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10)
                != 0)))) {
          g_CardEventResult = g_CardEventResult | 2;
        }
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (flags == 0x7e) {
      *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
  }
  if (flags == 0x73) {
    if ((((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                           arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           0xffffffff;
    }
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
        (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524460,s_ASHNODS_BATTLEGEAR_0052444c);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,2
                         ,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        local_8 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,local_10,local_c);
        if (local_8 != -1) {
          *(int *)(&g_CardSlot_ConvertedManaCost +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) = local_8;
          *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + spell_id * 0x5b20) | 0x20;
          *(undefined2 *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) = 2;
          *(undefined2 *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) = 0xfffe;
        }
      }
    }
    if (((flags == 0x77) && (g_EventSourceSlot == target_id)) &&
       ((g_EventSourcePlayer == spell_id &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != -1)))) {
      Pic_Subsystem_0044867e
                (spell_id,*(int *)(&g_CardSlot_ConvertedManaCost +
                                  target_id * 0x120 + spell_id * 0x5b20),1);
    }
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      Pic_Subsystem_0044867e
                (spell_id,*(int *)(&g_CardSlot_ConvertedManaCost +
                                  target_id * 0x120 + spell_id * 0x5b20),1);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           0xffffffff;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045c59a
 * Entry Point: 0045c59a
 * Size: 2702 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_0045c59a(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x82) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffd;
  }
  if (((g_ScWillyScore == 1) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    if (((flags == 0x7d) && (((&DAT_006a6038)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       ((((&DAT_006a6038)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
        ((_DAT_006ff198 &
         (byte)(&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34]) == 0))
       )) {
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
        iVar1 = *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20);
        if ((iVar1 == -1) ||
           ((((&DAT_006a6038)
              [*(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[iVar1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 1) == 0
            && (((&g_CardSlot_Flags)
                 [*(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[iVar1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10)
                != 0)))) {
          g_CardEventResult = g_CardEventResult | 2;
        }
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (flags == 0x7e) {
      *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006a6038 + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_0052447c,s_TAWNOS_WEAPONRY_0052446c);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        local_8 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,local_10,local_c);
        if (local_8 != -1) {
          *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + local_8 * 0x120 + spell_id * 0x5b20) | 0x20;
          *(undefined2 *)(&DAT_006a5f48 + local_8 * 0x120 + spell_id * 0x5b20) = 1;
          *(undefined2 *)(&DAT_006a5f4a + local_8 * 0x120 + spell_id * 0x5b20) = 1;
          (&g_CardSlot_DamageReceived)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
               (undefined1)spell_id;
          *(int *)(&g_CardSlot_TypeFlags +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) = local_8;
        }
      }
    }
    if (flags == 0x77) {
      if (((*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
          ((char)(&g_CardSlot_Toughness)
                 [*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20
                 ] == g_EventSourcePlayer)) &&
         (*(int *)(&g_CardSlot_OriginalCardId +
                  *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20
                  ) == g_EventSourceSlot)) {
        *(undefined4 *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
      }
      if (((target_id == g_EventSourceSlot) && (spell_id == g_EventSourcePlayer)) &&
         (*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20),1);
        *(undefined4 *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
      }
    }
    if ((*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20],
                 *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20),1);
      *(undefined4 *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
    }
    if (((flags == 0x3b) &&
        ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
       (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00695eb0 + spell_id * 4) = *(int *)(&DAT_00695eb0 + spell_id * 4) + 1;
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045d028
 * Entry Point: 0045d028
 * Size: 456 bytes
 */


undefined4 Minit_Subsystem_0045d028(int player,int card_slot,int arg_3)

{
  int arg_4;
  int local_14;
  int local_c;
  
  if (arg_3 == 0x3c) {
    (&DAT_006a604f)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a604f)[card_slot * 0x120 + player * 0x5b20] | 0x40;
  }
  if (((arg_3 == 0x1a) && (arg_4 = 1 - player, player == g_DefendingPlayer)) &&
     (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x44) != 0)) {
    if ((&g_CardSlot_ColorMask)[card_slot * 0x120 + player * 0x5b20] == -1) {
      local_14 = card_slot;
    }
    else {
      local_14 = (int)(char)(&g_CardSlot_ColorMask)[card_slot * 0x120 + player * 0x5b20];
    }
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg_4]; local_c = local_c + 1) {
      if ((((char)(&g_CardSlot_ColorMask)[local_c * 0x120 + arg_4 * 0x5b20] == local_14) &&
          ((&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + local_c * 0x120 + arg_4 * 0x5b20) * 0x34]
           == '\0')) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + arg_4 * 0x5b20) * 0x34] & 2) != 0)) {
        Card_ApplyTriggerEffect(player,card_slot,DAT_006a48e4,arg_4,local_c);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045d1f0
 * Entry Point: 0045d1f0
 * Size: 1618 bytes
 */


undefined4 Minit_Subsystem_0045d1f0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined1 *arg_18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar20 = 0;
    uVar19 = 0;
    uVar18 = 0;
    uVar16 = 0xffffffff;
    uVar14 = 0xffffffff;
    uVar12 = 0xffffffff;
    uVar10 = 0xffffffff;
    uVar8 = 0;
    uVar6 = 0;
    uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,1,0,0,uVar1,
                 uVar6,uVar8,uVar10,uVar12,uVar14,uVar16,uVar18,uVar19,uVar20);
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_CalcLifeAdvantage(0);
    uVar1 = 0;
  }
  else {
    if (flags == 0x6d) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      uVar1 = g_OverworldPlayerCoordY;
      arg_19 = 0;
      uVar20 = 0;
      uVar19 = 0;
      uVar18 = 0xffffffff;
      uVar16 = 0xffffffff;
      uVar14 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar10 = 0;
      uVar8 = 0;
      uVar6 = Glue_Subsystem_004d0a42(spell_id,target_id);
      UI_PaintBigCardInfo(&g_OverworldPlayerCoordY,0,spell_id,2,2,0x200,1,0,0,uVar6,uVar8,uVar10,uVar12,
                   uVar14,uVar16,uVar18,uVar19,uVar20,arg_19);
      DAT_006b2d40 = 0xffffffff;
      Ai_CalcManaRequirement_004ba890(spell_id,0,0);
      g_OverworldPlayerCoordY = uVar1;
      if (g_ActivePlayer != 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        local_c = 0;
        local_8 = 0;
        while (((local_c < g_TurnCounter && (local_8 == 0)) && (g_ActivePlayer != 1))) {
          Pic_Subsystem_00424500(s_prompts_txt_005244a0,s_CANDLEABRA_OF_TAWNOS_00524488);
          sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_c + 1,g_TurnCounter);
          arg_20 = &local_14;
          uVar1 = 1;
          arg_18 = &g_OverworldGoldAmount;
          uVar17 = 0;
          uVar15 = 0;
          uVar13 = 0;
          uVar11 = 0xffffffff;
          uVar9 = 0xffffffff;
          iVar7 = -1;
          iVar5 = -1;
          uVar4 = 0;
          uVar3 = 0;
          uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          iVar5 = Action_ValidateTarget_00405802
                            (spell_id,2,spell_id,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar7,uVar9,
                             uVar11,uVar13,uVar15,uVar17,arg_18,uVar1,arg_20);
          if (iVar5 == 0) {
            if (local_10 == -1) {
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              g_ActivePlayer = 1;
            }
            else {
              local_8 = 1;
            }
          }
          else {
            *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) | 0x300000;
            Ai_Subsystem_004cc9c5(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 local_14;
            *(int *)(&g_CardSlot_AttachedAura +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 local_10;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          local_c = local_c + 1;
        }
        for (local_c = 0;
            local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) &
               0xffcfffff;
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
      }
    }
    if (flags == 0x72) {
      for (local_c = 0;
          local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        local_14 = *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        local_10 = *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        uVar17 = 0;
        uVar15 = 0;
        uVar13 = 0;
        uVar11 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar7 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
        iVar5 = Rules_ParseFilter_0040360b
                          (local_14,local_10,(char *)0x0,spell_id,2,2,0x200,1,0,0,uVar2,uVar3,uVar4,
                           iVar5,iVar7,uVar9,uVar11,uVar13,uVar15,uVar17);
        if (iVar5 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Magic_TriggerCardEvent(local_14,local_10,1,0xffffffff,0xffffffff);
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x5b20 + local_10 * 0x120) & 0xffffffef;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045d842
 * Entry Point: 0045d842
 * Size: 77 bytes
 */


undefined4 Minit_Subsystem_0045d842(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uVar1 = Glue_Subsystem_004d7c60(player,card_slot,arg_3,0,2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045d88f
 * Entry Point: 0045d88f
 * Size: 77 bytes
 */


undefined4 Minit_Subsystem_0045d88f(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uVar1 = Glue_Subsystem_004d7c60(player,card_slot,arg_3,0,3);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045d8dc
 * Entry Point: 0045d8dc
 * Size: 1225 bytes
 */


undefined4 Minit_Subsystem_0045d8dc(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) ||
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0)) {
      if (((byte)g_PlayerHandCardCount & 4) == 0) {
        uVar1 = 0;
      }
      else if ((g_ScWillyScore == 0x1a) || (g_ScWillyScore == 0x19)) {
        iVar2 = Font_DrawString(spell_id, 7, 1);
        if (iVar2 == 0) {
          uVar1 = 0;
        }
        else {
          iVar2 = UI_PaintBigCardInfo((int *)0x0,2,spell_id,1 - spell_id,1 - spell_id,0x200,2,0,0,0,0,0,
                               0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,2,8);
          if (iVar2 == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 99;
          }
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((((flags == 0x6d) && (iVar2 = Font_DrawString(spell_id, 7, 1), iVar2 != 0)) &&
        (((byte)g_PlayerHandCardCount & 4) != 0)) &&
       ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) {
      Ai_CalcManaRequirement_004ba890(spell_id,0,1);
      Pic_Subsystem_00424500(s_prompts_txt_005244b8,s_FORCEFIELD_005244ac);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,
                         0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId +
                          *(int *)(&g_CardSlot_TypeFlags + local_c * 0x5b20 + local_8 * 0x120) *
                          0x120 + (char)(&g_CardSlot_DamageReceived)
                                        [local_c * 0x5b20 + local_8 * 0x120] * 0x5b20) * 0x34] & 2)
                != 0) &&
              (((&DAT_006a5f3d)
                [*(int *)(&g_CardSlot_TypeFlags + local_c * 0x5b20 + local_8 * 0x120) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)[local_c * 0x5b20 + local_8 * 0x120] * 0x5b20] &
               2) == 0)) {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,0,0,0,0,0,0,
                         DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) != 0) {
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045dda5
 * Entry Point: 0045dda5
 * Size: 716 bytes
 */


undefined4 Minit_Subsystem_0045dda5(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x73) {
    iVar1 = Font_DrawString(spell_id,7,3);
    if ((((iVar1 == 0) || (g_DefendingPlayer != spell_id)) ||
        ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
        (iVar1 = Font_DrawString(spell_id,7,3), iVar1 != 0)) &&
       ((g_DefendingPlayer == spell_id &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005244d8,s_DISRUPTING_SCEPTER_005244c4);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Prompts_Load_0046fa40
                (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),0,0);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_0045e071
 * Entry Point: 0045e071
 * Size: 395 bytes
 */


undefined4 Minit_Subsystem_0045e071(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[player] - (&g_PlayerCreatureCount)[1 - player]) * 0x18;
  }
  if (((arg_3 == 2) || (arg_3 == 3)) &&
     ((g_EventSourceSlot == card_slot &&
      ((g_EventSourcePlayer == player &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)))))) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  if (((((arg_3 == 4) || (arg_3 == 5)) || (arg_3 == 199)) &&
      ((g_EventSourceSlot == card_slot && (g_EventSourcePlayer == player)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)) {
    Mem_AllocOrFree_0041df33(g_DefendingPlayer,1,player,card_slot);
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e1fc
 * Entry Point: 0045e1fc
 * Size: 169 bytes
 */


undefined4 Minit_Subsystem_0045e1fc(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b3010 + player * 4) - *(int *)(&DAT_006b3000 + (5 - player) * 4)) * 0xc;
  }
  if (((arg_3 == 0x32) &&
      (((&g_CardSlot_Flags)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] & 4) != 0
      )) && (g_DefendingPlayer == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e2a5
 * Entry Point: 0045e2a5
 * Size: 171 bytes
 */


undefined4 Minit_Subsystem_0045e2a5(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b3000 + (5 - player) * 4) - *(int *)(&DAT_006b3010 + player * 4)) * 0xc;
  }
  if (((arg_3 == 0x32) &&
      (((&g_CardSlot_Flags)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] & 4) != 0
      )) && (g_DefendingPlayer == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult + -1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e350
 * Entry Point: 0045e350
 * Size: 34 bytes
 */


undefined4 Minit_Subsystem_0045e350(undefined4 player,undefined4 card_slot,int arg_3)

{
  if (arg_3 == 10) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e372
 * Entry Point: 0045e372
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e372(int player,int card_slot,int arg_3)

{
  Mana_Init_0045e430(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e398
 * Entry Point: 0045e398
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e398(int player,int card_slot,int arg_3)

{
  Mana_Init_0045e430(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e3be
 * Entry Point: 0045e3be
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e3be(int player,int card_slot,int arg_3)

{
  Mana_Init_0045e430(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e3e4
 * Entry Point: 0045e3e4
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e3e4(int player,int card_slot,int arg_3)

{
  Mana_Init_0045e430(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e40a
 * Entry Point: 0045e40a
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e40a(int player,int card_slot,int arg_3)

{
  Mana_Init_0045e430(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Mana_Init_0045e430
 * Entry Point: 0045e430
 * Size: 1569 bytes
 */


undefined4 Mana_Init_0045e430(int x,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  int local_78;
  char local_74 [100];
  int local_10;
  int local_c;
  int local_8;
  
  if (width == 0x73) {
    if (((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if ((width == 0x6d) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      local_8 = Glue_Subsystem_004e6978(x,y);
      if ((DAT_006ff4ac == 0) && (iVar2 = Font_DrawString(x,7,local_8 + 3), iVar2 != 0)) {
        strcpy(&g_OverworldWorldState,s_Tap_to_get_mana__005244e4);
        strcat(&g_OverworldWorldState,s_Charge_battery__add_counter___005244f8);
        strcat(&g_OverworldWorldState,s_Cancel__00524518);
        if ((g_ScWillyScore == 0x1f) && (1 - x == g_DefendingPlayer)) {
          local_10 = 1;
        }
        else {
          local_10 = 0;
        }
        local_c = Ai_Subsystem_004cc56d(x,x,y,-1,-1,&g_OverworldWorldState,local_10);
      }
      else {
        local_c = 0;
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
      if (local_c == 0) {
        FUN_0040d875(x,height,1);
        local_8 = Glue_Subsystem_004e6978(x,y);
        if (local_8 != 0) {
          if (((x == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
            if (g_IsAiThinking == 1) {
              local_78 = Math_RandomRange(local_8 + 1);
              g_AiDecisionScore = local_78;
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              local_78 = g_AiDecisionScore;
            }
          }
          else {
            sprintf(local_74,s__s_How_many_counters_do_you_wish_00524524,
                    *(undefined4 *)
                     (&DAT_006b3074 +
                     *(int *)(&g_MasterCardTypeTable +
                             *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34) * 0x98),
                    local_8);
            local_78 = Ai_Subsystem_004cc8de(x,local_74,0);
          }
          if (local_78 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            if (local_8 < local_78) {
              local_78 = local_8;
            }
            FUN_0040d901(x,height,local_78);
            Glue_Subsystem_004e689b(x,y,local_78);
          }
        }
        if (g_ActivePlayer == 1) {
          FUN_0040d8b7(x,height,1);
        }
        else {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
          *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
          DAT_006ff2d4 = height;
        }
      }
      else if (local_c == 1) {
        *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
        Ai_CalcManaRequirement_004ba890(x,0,2);
        if (g_ActivePlayer == 1) {
          *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xffffffef;
        }
        if (g_ActivePlayer != 1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 1;
          DAT_006ff2d4 = -1;
        }
      }
      else if (local_c == 2) {
        g_ActivePlayer = 1;
      }
    }
    if ((width == 0x72) && (*(int *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) == 1))
    {
      Glue_Subsystem_004e66b3(g_DialogPromptHwnd,g_DuelArenaHwnd);
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + y * 0x120 + x * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + y * 0x120 + x * 0x5b20) * 0x5b20) = 0;
    }
    if (((width == 0x7f) && (g_EventSourceSlot == y)) &&
       ((g_EventSourcePlayer == x && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)
        ))) {
      FUN_0040d7e9(x,height,1);
      iVar2 = Glue_Subsystem_004e6978(x,y);
      FUN_0040d7e9(x,height,iVar2);
    }
    if (((width == 0x8f) && (*(int *)(&DAT_0063eea4 + x * 0x20) != 0)) &&
       (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    if ((width == 199) && (g_ActivePlayerPriority == x)) {
      iVar2 = Glue_Subsystem_004e6978(x,y);
      g_SpellStackDepth = g_SpellStackDepth + iVar2 * 0xc;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045ea5b
 * Entry Point: 0045ea5b
 * Size: 388 bytes
 */


undefined4 Minit_Subsystem_0045ea5b(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = Font_DrawString(player,7,3);
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
        FUN_0040d875(player,0,3);
        g_SpellStackDepth = g_SpellStackDepth + -0x24;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else {
        iVar2 = Font_DrawString(player,7,3);
        if ((iVar2 != 0) &&
           ((g_CurrentTurnPhase == player ||
            (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)))) {
          Ai_CalcManaRequirement_004ba890(player,0,3);
        }
      }
    }
    if (arg_3 == 0x72) {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) ^ 0x10;
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045ebe4
 * Entry Point: 0045ebe4
 * Size: 1647 bytes
 */


undefined4 Minit_Subsystem_0045ebe4(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee4c + spell_id * 0x20) * 6;
  }
  if (flags == 0x73) {
    if ((((byte)g_PlayerHandCardCount & 4) == 0) ||
       ((((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) != 0)
          ) || (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) ||
        ((iVar1 = Font_DrawString(spell_id,7,3), iVar1 == 0 ||
         (iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,
                               DAT_006ff2e0,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), iVar1 == 0))
        )))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      local_10 = 0;
      local_c = 0;
      while (((local_10 < 2 && (local_c == 0)) && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_0052457c,s_CONSERVATOR_00524570);
        iVar1 = Action_ValidateTarget_00405802
                          (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,
                           0xffffffff,0x20,0,0,&g_OverworldGoldAmount,3,&local_18);
        if (iVar1 == 0) {
          if (local_14 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            local_c = 1;
          }
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_18 * 0x5b20 + local_14 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_18 * 0x5b20 + local_14 * 0x120) | 0x200000;
          Ai_Subsystem_004cc9c5(0,0x20);
          *(int *)(&g_CardSlot_CombatTarget +
                  spell_id * 0x5b20 +
                  target_id * 0x120 +
                  (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
               local_18;
          *(int *)(&g_CardSlot_AttachedAura +
                  spell_id * 0x5b20 +
                  target_id * 0x120 +
                  (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
               local_14;
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
               (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
        }
        local_10 = local_10 + 1;
      }
      for (local_10 = 0;
          local_10 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_10 = local_10 + 1) {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              spell_id * 0x5b20 + target_id * 0x120 + local_10 * 8) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_8 = 0;
      for (local_10 = 0;
          local_10 < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          local_10 = local_10 + 1) {
        local_18 = *(int *)(&g_CardSlot_CombatTarget +
                           local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20);
        local_14 = *(int *)(&g_CardSlot_AttachedAura +
                           local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20);
        iVar1 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   local_10 * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0
                           ,spell_id,(byte)spell_id,(byte)spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1
                           ,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar1 == 0) {
          local_8 = local_8 + 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) != 0
                ) {
          *(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) + -1;
        }
      }
      if ((char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] == local_8) {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_0045f258
 * Entry Point: 0045f258
 * Size: 371 bytes
 */


undefined4 Minit_Subsystem_0045f258(int player,int card_slot,int arg_3)

{
  char cVar1;
  byte bVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (((arg_3 == 0x33) || (arg_3 == 0x32)) &&
     (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
    cVar1 = (&DAT_006a5f4c)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20];
    bVar2 = Card_SetTapState(player, card_slot, 4);
    if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  if (((arg_3 == 0x7c) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 1) != 0)) {
    cVar1 = (&DAT_006a5f4c)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20];
    bVar2 = Card_UntapCard(player,card_slot,4);
    if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
      arg_3_00 = 1;
      arg_2_00 = Card_UntapCard(player,card_slot,4);
      FUN_0040d875(g_EventSourcePlayer,arg_2_00,arg_3_00);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045f3cb
 * Entry Point: 0045f3cb
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f3cb(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f3f1
 * Entry Point: 0045f3f1
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f3f1(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f417
 * Entry Point: 0045f417
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f417(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f43d
 * Entry Point: 0045f43d
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f43d(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f463
 * Entry Point: 0045f463
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f463(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f489
 * Entry Point: 0045f489
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f489(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,0);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f4af
 * Entry Point: 0045f4af
 * Size: 467 bytes
 */


undefined4 Minit_Subsystem_0045f4af(int x,int y,int width,int height)

{
  byte bVar1;
  int iVar2;
  
  if (((width == 0x6c) && (g_EventSourceSlot == y)) && (g_EventSourcePlayer == x)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         *(int *)(&DAT_0063ee30 + height * 4 + g_ActivePlayerPriority * 0x20) * 0xc;
  }
  if (((g_CurrentStepCode == 0xd3) && (g_EventSourceSlot == y)) &&
     ((g_EventSourcePlayer == x &&
      ((DAT_006a4b5c == x && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x20) == 0)))))) {
    iVar2 = Font_DrawString(x,7,1);
    if (iVar2 != 0) {
      bVar1 = Card_SetTapState(x,y,height);
      if (((1 << (bVar1 & 0x1f) &
           (int)(char)(&DAT_006a5f4d)[DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20]) != 0) &&
         ((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] !=
          '\x01')) {
        if (width == 0x7d) {
          if (g_ActivePlayerPriority == x) {
            g_CardEventResult = g_CardEventResult | 2;
          }
          else {
            g_CardEventResult = g_CardEventResult | 1;
          }
        }
        if (width == 0x7e) {
          Ai_CalcManaRequirement_004ba890(x,0,1);
          if ((g_ActivePlayer != 1) &&
             ((&g_PlayerCreatureCount)[x] = (&g_PlayerCreatureCount)[x] + 1,
             g_ActivePlayerPriority == x)) {
            g_SpellStackDepth = g_SpellStackDepth + -0x18;
          }
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045f682
 * Entry Point: 0045f682
 * Size: 425 bytes
 */


undefined4 Minit_Subsystem_0045f682(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) -
         *(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20)) * 0xc;
  }
  if (((((g_CurrentStepCode == 0xdb) || (g_CurrentStepCode == 0xd3)) &&
       ((card_slot == g_EventSourceSlot &&
        ((player == g_EventSourcePlayer && (DAT_006a4b5c == g_DefendingPlayer)))))) &&
      (*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) != -1)) &&
     ((((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] & 1) !=
       0 && ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0 ||
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)))))
     ) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x7e) {
      Mem_AllocOrFree_0041df33(DAT_00695f08,2,player,card_slot);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045f82b
 * Entry Point: 0045f82b
 * Size: 1408 bytes
 */


int Minit_Subsystem_0045f82b(int player,int card_slot,int arg_3)

{
  bool bVar1;
  int iVar2;
  int y;
  int height;
  int local_c;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[g_ActivePlayerPriority] -
         (&g_PlayerCreatureCount)[g_CurrentTurnPhase]) * 0x18;
  }
  if ((((g_CurrentStepCode == 0xc9) || (arg_3 == 199)) &&
      ((card_slot == g_EventSourceSlot &&
       ((player == g_EventSourcePlayer && (player == g_DefendingPlayer)))))) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Glue_Subsystem_004e66b3(player,card_slot);
      Ai_Subsystem_004cc9c5(0,0x20);
    }
  }
  if (arg_3 == 0x73) {
    if ((((g_ScWillyScore == 4) && (iVar2 = Glue_Subsystem_004e6978(player,card_slot), iVar2 != 0)) &&
        (iVar2 = Font_DrawString(DAT_0063edc0,7,4), iVar2 != 0)) &&
       (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) {
      if (DAT_0063edc0 == g_CurrentTurnPhase) {
        local_c = 1;
      }
      else {
        if (((int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] <
             (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase]) ||
           (iVar2 = Glue_Subsystem_004e6978(player,card_slot),
           (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] < iVar2)) {
          local_c = 1;
        }
        else {
          local_c = 0;
        }
        if (local_c != 0) {
          DAT_006a4920 = DAT_006a4920 | 3;
        }
      }
    }
    else {
      local_c = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) != -1)) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) = 0;
      if (((int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] <
           (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase]) ||
         (iVar2 = Glue_Subsystem_004e6978(player,card_slot),
         (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] < iVar2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (((g_IsAiThinking != 1) && (DAT_006fedc0 == 0)) && (DAT_0063edc0 != 1)) {
        bVar1 = true;
      }
      if (bVar1) {
        Ai_CalcManaRequirement_004ba890(DAT_0063edc0,0,4);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          Glue_Subsystem_004e676b(g_DialogPromptHwnd,g_DuelArenaHwnd);
        }
      }
    }
    if (((g_CurrentStepCode == 0xcb) || (arg_3 == 199)) &&
       ((((card_slot == g_EventSourceSlot &&
          ((player == g_EventSourcePlayer && (player == g_DefendingPlayer)))) &&
         (DAT_006a4b5c == player)) &&
        (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) &&
         (iVar2 = Glue_Subsystem_004e6978(player,card_slot), iVar2 != 0)))))) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        iVar2 = player;
        height = card_slot;
        y = Glue_Subsystem_004e6978(player,card_slot);
        Mem_AllocOrFree_0041df33(g_DefendingPlayer,y,iVar2,height);
        iVar2 = Glue_Subsystem_004e6978(player,card_slot);
        Mem_AllocOrFree_0041df33(1 - g_DefendingPlayer,iVar2,player,card_slot);
      }
    }
    local_c = 0;
  }
  return local_c;
}



/*
 * Decompiled function: Minit_Subsystem_0045fdb5
 * Entry Point: 0045fdb5
 * Size: 711 bytes
 */


undefined4 Minit_Subsystem_0045fdb5(int player,int card_slot,int arg_3)

{
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x77) &&
       ((&DAT_006a5f50)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\0')) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 1) != 0)) &&
     ((&DAT_006a5f50)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\x04')) {
    if (g_EventSourcePlayer == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) + 1;
    }
    else {
      *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) + 0x100;
    }
  }
  if ((((g_CurrentStepCode == 0xd5) && (card_slot == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       (((*(uint *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) & 0xffff) != 0
        && (player == DAT_006a4b5c)))))) &&
     ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)))) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x7e) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        if ((&g_CardSlot_ConvertedManaCost)[player * 0x5b20 + card_slot * 0x120] != '\0') {
          for (local_c = 0;
              local_c < (int)(*(uint *)(&g_CardSlot_ConvertedManaCost +
                                       player * 0x5b20 + card_slot * 0x120) & 0xff);
              local_c = local_c + 1) {
            Mem_AllocOrFree_0041df33(local_8,2,player,card_slot);
          }
        }
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) >> 8;
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046007c
 * Entry Point: 0046007c
 * Size: 825 bytes
 */


undefined4 Minit_Subsystem_0046007c(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x90;
  }
  if (((arg_3 == 0x77) &&
      ((&DAT_006a5f50)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\0')) &&
     ((((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 2) != 0 &&
      ((&DAT_006a5f50)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\x04'))))
  {
    if (((&DAT_006a5f55)[card_slot * 0x120 + player * 0x5b20] & 1) == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) + 1;
    }
    else {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
    }
  }
  if (((g_CurrentStepCode == 0xd5) && (g_EventSourceSlot == card_slot)) &&
     ((player == g_EventSourcePlayer &&
      (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] != '\0' &&
       (player == DAT_006a4b5c)))))) {
    *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 0x100;
    if ((arg_3 == 0x7d) && (iVar1 = Font_DrawString(player,7,1), iVar1 != 0)) {
      if ((player == g_ActivePlayerPriority) &&
         ((int)(&g_PlayerCreatureCount)[player] < (&g_PlayerCreatureCount)[1 - player] + 8)) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (arg_3 == 0x7e) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      if (g_ActivePlayer == 1) {
        g_ActivePlayer = -1;
      }
      else {
        (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) + -1;
      }
    }
    if ((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] != '\0') {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0xfffffeff;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004603b5
 * Entry Point: 004603b5
 * Size: 301 bytes
 */


undefined4 Minit_Subsystem_004603b5(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (((&g_PlayerCreatureCount)[g_CurrentTurnPhase] + 4) -
         (&g_PlayerCreatureCount)[g_ActivePlayerPriority]) *
         *(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) * 6;
  }
  if (((arg_3 == 0x77) && (g_EventSourcePlayer == player)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    iVar1 = Font_DrawString(player,7,1);
    if ((iVar1 != 0) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      if (g_ActivePlayer != 1) {
        (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004604e2
 * Entry Point: 004604e2
 * Size: 258 bytes
 */


undefined4 Minit_Subsystem_004604e2(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + (6 - (&DAT_006b3008)[player]) * 0xc;
  }
  if ((arg_3 == 0x77) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    iVar1 = Font_DrawString(player,7,3);
    if ((iVar1 != 0) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,3);
      if (g_ActivePlayer != 1) {
        Magic_ExecuteDrawPhase(player);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004605e4
 * Entry Point: 004605e4
 * Size: 1086 bytes
 */


undefined4 Minit_Subsystem_004605e4(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) * 3;
  }
  if (flags == 0x73) {
    if ((((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 2;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                           arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
        ((iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0 &&
         ((g_DefendingPlayer == spell_id && (DAT_006a5f20 != 0)))))) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524594,s_EBONYHORSE_00524588);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 2;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 2;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,2,
                         0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
        Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00695f14,local_c,local_8);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00460a22
 * Entry Point: 00460a22
 * Size: 472 bytes
 */


undefined4 Minit_Subsystem_00460a22(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     (((g_ActivePlayerPriority == player &&
       (iVar1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),
                             player), iVar1 != 0)) &&
      (3 < *(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) / iVar1)))) {
    g_SpellStackDepth = g_SpellStackDepth + 0x30;
  }
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,4);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,4), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,4), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Magic_ExecuteDrawPhase(player);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00460bfa
 * Entry Point: 00460bfa
 * Size: 1095 bytes
 */


undefined4 Minit_Subsystem_00460bfa(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x82) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(uint *)(&DAT_006a6038 + player * 0x5b20 + card_slot * 0x120) =
         *(uint *)(&DAT_006a6038 + player * 0x5b20 + card_slot * 0x120) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (card_slot == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0 &&
        (player == g_DefendingPlayer)))))) && (player == DAT_0063edc0)) {
    *(uint *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_slot * 0x120) =
         *(uint *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_slot * 0x120) | 0x10;
    (&DAT_006a603c)[player * 0x5b20 + card_slot * 0x120] =
         (&DAT_006a603c)[player * 0x5b20 + card_slot * 0x120] + '\x04';
  }
  if (((arg_3 == 1) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 1;
  }
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[player * 0x5b20 + card_slot * 0x120] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d901(player,0,3);
      *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
           *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
      DAT_006ff2d4 = 0;
    }
    if (((g_CurrentStepCode == 0xcb) || (arg_3 == 199)) &&
       ((card_slot == g_EventSourceSlot &&
        ((((player == g_EventSourcePlayer && (player == g_DefendingPlayer)) &&
          (player == DAT_006a4b5c)) &&
         ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0 &&
          (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) == 0)))))))) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Mem_AllocOrFree_0041df33(player,1,player,card_slot);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
      }
    }
    if (((arg_3 == 199) && (*(int *)(&DAT_0063ee4c + player * 0x20) < 4)) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0)) {
      (&g_PlayerCreatureCount)[player] =
           (&g_PlayerCreatureCount)[player] - (4 - *(int *)(&DAT_0063ee4c + player * 0x20));
    }
    if (((arg_3 == 0x7f) && (card_slot == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0)))) {
      FUN_0040d7e9(player,0,3);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00461041
 * Entry Point: 00461041
 * Size: 435 bytes
 */


undefined4 Minit_Subsystem_00461041(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) * 2;
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0040d875(player,0,2);
    }
    if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) &&
       ((g_EventSourcePlayer == player && (iVar2 = Math_RandomRange(2), iVar2 != 0)))) {
      Mem_AllocOrFree_0041df33(player,3,player,card_slot);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_004611f4
 * Entry Point: 004611f4
 * Size: 412 bytes
 */


undefined4 Minit_Subsystem_004611f4(int player,int card_slot,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (int)(0xc0 / (longlong)(*(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) + 1));
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0xc;
      FUN_0040d901(player,0,2);
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      DAT_006ff2d4 = 0;
    }
    if (((arg_3 == 0x7f) && (card_slot == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)))) {
      FUN_0040d7e9(player,0,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00461390
 * Entry Point: 00461390
 * Size: 1053 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_00461390(int player,int card_slot,int arg_3)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     (iVar1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1),
     iVar1 != 0)) {
    g_SpellStackDepth = g_SpellStackDepth + -0xf0;
  }
  if (((arg_3 == 0x82) &&
      (iVar1 = Magic_QueryCardValue(g_EventSourcePlayer,g_EventSourceSlot,0x32,0xffffffff), 2 < iVar1))
     && ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
    *(uint *)(&DAT_006a6038 + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
         *(uint *)(&DAT_006a6038 + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) &
         0xfffffffd;
    _DAT_006ff198 = _DAT_006ff198 | 1;
  }
  if (arg_3 == 199) {
    iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
    if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
        (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
      iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
    }
    local_c = 0;
    for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
          (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&g_CardSlot_Counters + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20))) {
        if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) == 0) {
          iVar2 = FUN_004728c3(g_CurrentTurnPhase,local_8);
          if (iVar2 == 0) {
            local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                          local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20);
          }
        }
        else if ((&DAT_006a603c)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] == '\0') {
          local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                        local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) * 2;
        }
      }
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1)
          && (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&g_CardSlot_Counters + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20)))
      {
        if (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0) {
          iVar2 = FUN_004728c3(g_ActivePlayerPriority,local_8);
          if (iVar2 == 0) {
            local_c = local_c - *(short *)(&g_CardSlot_Counters +
                                          local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20);
          }
        }
        else if ((&DAT_006a603c)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] == '\0') {
          local_c = local_c + *(short *)(&g_CardSlot_Counters +
                                        local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) * -2;
        }
      }
    }
    g_SpellStackDepth = g_SpellStackDepth + local_c * 0xc;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004617ad
 * Entry Point: 004617ad
 * Size: 1012 bytes
 */


undefined4 Minit_Subsystem_004617ad(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) * 3;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar1 = Font_DrawString(spell_id,7,3), iVar1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((iVar1 = Font_DrawString(spell_id,7,3), iVar1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005245b4,s_JANDORS_SADDLEBAGS_005245a0);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00461ba1
 * Entry Point: 00461ba1
 * Size: 920 bytes
 */


undefined4 Minit_Subsystem_00461ba1(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[g_ActivePlayerPriority] -
         (&g_PlayerCreatureCount)[g_CurrentTurnPhase]) * 0xc;
  }
  if (flags == 0x73) {
    if (((((byte)g_PlayerHandCardCount & 4) != 0) &&
        (iVar1 = Font_DrawString(spell_id, 7, 1), iVar1 != 0)) &&
       (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
            (iVar1 = UI_PaintBigCardInfo((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                                  0xffffffff,0xffffffff,0,0,0), iVar1 != 0)))))) {
      return 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) && (iVar1 = Font_DrawString(spell_id, 7, 1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005245d0,s_JADE_MONOLITH_005245c0);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0x200,0
                         ,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff
                         ,0xffffffff,0,0x200,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Minit_Subsystem_00461f3e(local_c,local_8,spell_id);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00461f3e
 * Entry Point: 00461f3e
 * Size: 389 bytes
 */


void Minit_Subsystem_00461f3e(int player,int card_slot,int arg_3)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0) &&
           (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == player)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == card_slot)) {
        *(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
        Mem_AllocOrFree_0041df33
                  (arg_3,*(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + local_8 * 0x5b20
                                 ),
                   (int)(char)(&g_CardSlot_DamageReceived)[local_c * 0x120 + local_8 * 0x5b20],
                   *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_8 * 0x5b20));
      }
    }
  }
  return;
}



/*
 * Decompiled function: Minit_Subsystem_004620c3
 * Entry Point: 004620c3
 * Size: 460 bytes
 */


undefined4 Minit_Subsystem_004620c3(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    iVar1 = Math_Clamp((&g_PlayerCreatureCount)[g_ActivePlayerPriority],1,99);
    g_SpellStackDepth = g_SpellStackDepth + (int)(0x30 / (longlong)iVar1);
  }
  if (((arg_3 == 0x77) && (card_slot == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0 &&
       ((&DAT_006a5f50)[card_slot * 0x120 + player * 0x5b20] != '\x04')))))) {
    iVar1 = Pic_Subsystem_00451291(player,DAT_006ff564);
    if (iVar1 != -1) {
      *(undefined4 *)(&g_ActiveCardsInPlay + iVar1 * 0x120 + player * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + player * 0x5b20) | 2;
      *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + player * 0x5b20) = 0x200;
      *(undefined4 *)(&DAT_006a5f80 + iVar1 * 0x120 + player * 0x5b20) = 0xd5;
      (&DAT_006a5f50)[iVar1 * 0x120 + player * 0x5b20] = 2;
      FUN_00476482(player,iVar1);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046228f
 * Entry Point: 0046228f
 * Size: 74 bytes
 */


undefined4 Minit_Subsystem_0046228f(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    FUN_0040d875(player,0,4);
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004622d9
 * Entry Point: 004622d9
 * Size: 1012 bytes
 */


undefined4 Minit_Subsystem_004622d9(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    if (((((byte)g_PlayerHandCardCount & 4) == 0) ||
        (iVar1 = Font_DrawString(spell_id,7,2), iVar1 == 0)) ||
       (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        || ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0 ||
            (iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,
                                  0xffffffff,0xffffffff,0xffffffff,0,0,0), iVar1 == 0)))))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (((flags == 0x6d) && (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005245ec,s_AMULET_KROOG_005245dc);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff
                         ,0,0,0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_8 * 0x120 + local_c * 0x5b20) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) + -1;
      }
    }
    if (((flags == 0x3b) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_004626d2
 * Entry Point: 004626d2
 * Size: 824 bytes
 */


undefined4 Minit_Subsystem_004626d2(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((((byte)g_PlayerHandCardCount & 4) == 0) || (iVar1 = Font_DrawString(player,7,2), iVar1 == 0))
       || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
      if ((local_8 == -1) ||
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120) !=
          DAT_006ff2e0)) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = local_8;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      if (*(int *)(&g_CardSlot_ConvertedManaCost +
                  *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                     (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) + -1;
      }
      *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
    }
    if ((arg_3 == 0x22) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0)) {
      FUN_0041da41(player,card_slot);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00462a0a
 * Entry Point: 00462a0a
 * Size: 788 bytes
 */


undefined4 Minit_Subsystem_00462a0a(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    if ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar1 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0x20,uVar1,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052460c,s_GRAPESHOT_CATAPULT_005245f8);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0x20,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar2 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,2,0,0x20,uVar3,uVar4,uVar5,
                         iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_ApplyCombatDamage(local_c,local_8,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00462d1e
 * Entry Point: 00462d1e
 * Size: 608 bytes
 */


undefined4 Minit_Subsystem_00462d1e(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_0063edec + g_ActivePlayerPriority * 0x20) * 3 + -0xc) * 4;
    *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,2);
    if ((iVar1 == 0) || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      Glue_Subsystem_004df8ba(player,card_slot);
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      Glue_Subsystem_004dfb23(player,card_slot,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] = 0;
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0xffffffef;
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0)) {
      Pic_Subsystem_0044867e(player,card_slot,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00462f7e
 * Entry Point: 00462f7e
 * Size: 1952 bytes
 */


undefined4 Minit_Subsystem_00462f7e(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
  }
  if (flags == 0x73) {
    if ((((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = Font_DrawString(spell_id,7,4), iVar1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,1 - spell_id,1 - spell_id,0x200,0,0,0,uVar2,arg_11,
                           arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) && (iVar1 = Font_DrawString(spell_id,7,4), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,4), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524628,s_BRONZE_TABLET_00524618);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,1 - spell_id,1 - spell_id,0x200,0x7f,0,0,uVar3,uVar4,uVar5,iVar1,
                         iVar6,uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,1 - (char)spell_id,1 - (char)spell_id,
                         0x200,0x7f,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,
                         uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0042475a(s_prompts_txt_00524644,s_BRONZE_TABLET_00524634);
        uVar2 = Ai_Subsystem_004cc56d
                          (1 - spell_id,spell_id,target_id,-1,-1,
                           &g_OverworldGoldAmount +
                           ((uint)((int)(&g_PlayerCreatureCount)[1 - spell_id] < 10) * 5 + 5) * 0x32
                           ,0);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             uVar2;
        iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        if (iVar1 == 0) {
          if (*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                              * 0x5b20) != -1) {
            if (g_CurrentTurnPhase == spell_id) {
              Pic_Subsystem_0045200d
                        (*(uint *)(&g_CardSlot_CardId +
                                  *(int *)(&g_CardSlot_SicknessState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                  *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20));
            }
            else {
              Pic_Subsystem_00451e40
                        (*(uint *)(&g_CardSlot_CardId +
                                  *(int *)(&g_CardSlot_SicknessState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                  *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20));
            }
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                             * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20
                                  ) * 0x120 +
                          *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) ^ 0x1000;
            Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
          }
          if (g_CurrentTurnPhase == spell_id) {
            Pic_Subsystem_00451e40
                      (*(uint *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120));
          }
          else {
            Pic_Subsystem_0045200d
                      (*(uint *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120));
          }
          *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_8 * 0x120) ^ 0x1000;
          Pic_Subsystem_0044867e(local_c,local_8,4);
        }
        else if (iVar1 == 1) {
          (&g_PlayerCreatureCount)[1 - spell_id] = (&g_PlayerCreatureCount)[1 - spell_id] + -10;
          if (*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                              * 0x5b20) != -1) {
            Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,2);
          }
        }
        else if ((iVar1 == 2) &&
                ((&g_PlayerCreatureCount)[1 - spell_id] = 0,
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,2);
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00463723
 * Entry Point: 00463723
 * Size: 1261 bytes
 */


undefined4 Minit_Subsystem_00463723(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    iVar1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1);
    if (iVar1 == 0) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e5c + (1 - player) * 0x20) - *(int *)(&DAT_006b2e5c + player * 0x20)) *
           0xc;
    }
    *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,1);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      local_c = 0;
      while( true ) {
        iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        if (iVar1 <= local_c) break;
        if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34] &
            2) != 0)) {
          Pic_Subsystem_0044867e(g_CurrentTurnPhase,local_c,2);
        }
        if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1
             ) && (((&g_CardSlot_Flags)[local_c * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0
                  )) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) *
              0x34] & 2) != 0)) {
          Pic_Subsystem_0044867e(g_ActivePlayerPriority,local_c,2);
        }
        local_c = local_c + 1;
      }
      Pic_Subsystem_004488a0();
      local_c = 0;
      while( true ) {
        iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        if (iVar1 <= local_c) break;
        if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[local_c * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
           ((((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
             & 0x44) != 0 &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
             & 2) == 0)))) {
          Pic_Subsystem_0044867e(g_CurrentTurnPhase,local_c,2);
        }
        if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
               -1) && (((&g_CardSlot_Flags)[local_c * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                       != 0)) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) *
               0x34] & 0x44) != 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) *
              0x34] & 2) == 0)) {
          Pic_Subsystem_0044867e(g_ActivePlayerPriority,local_c,2);
        }
        local_c = local_c + 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00463c10
 * Entry Point: 00463c10
 * Size: 193 bytes
 */


undefined4 Minit_Subsystem_00463c10(int player,int card_slot,int arg_3)

{
  if ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 2) != 0) &&
     (((&g_MasterCardColorTable)[arg_3 * 0x34] & 2) != 0)) {
    Pic_Subsystem_0044867e(player,card_slot,2);
  }
  Pic_Subsystem_004488a0();
  if ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 2) != 0) &&
     (((&g_MasterCardColorTable)[arg_3 * 0x34] & 0x44) != 0)) {
    Pic_Subsystem_0044867e(player,card_slot,2);
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00463cd1
 * Entry Point: 00463cd1
 * Size: 543 bytes
 */


undefined4 Minit_Subsystem_00463cd1(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x60;
  }
  if (flags == 0x73) {
    iVar1 = Font_DrawString(spell_id,7,8);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar2 = 0;
  }
  else {
    if (((flags == 0x6d) && (iVar1 = Font_DrawString(spell_id,7,8), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,8), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524660,s_ALADDIN_RING_00524650);
      Glue_Subsystem_004df8ba(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x72,4);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00463ef0
 * Entry Point: 00463ef0
 * Size: 538 bytes
 */


undefined4 Minit_Subsystem_00463ef0(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth + (*(int *)(&DAT_0063edec + g_ActivePlayerPriority * 0x20) * 3 + -6) * 4;
  }
  if (flags == 0x73) {
    iVar1 = Font_DrawString(spell_id,7,3);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) && (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524678,s_ROD_OF_RUIN_0052466c);
      Glue_Subsystem_004df8ba(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_0046410a
 * Entry Point: 0046410a
 * Size: 1157 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_0046410a(int player,int card_slot,int arg_3)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     (iVar1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1),
     iVar1 == 0)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) -
         *(int *)(&DAT_006b2e5c + g_CurrentTurnPhase * 0x20)) * 0xc;
  }
  if (((arg_3 == 0x82) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 1) != 0)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
    *(uint *)(&DAT_006a6038 + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
         *(uint *)(&DAT_006a6038 + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) &
         0xfffffffd;
    _DAT_006ff198 = _DAT_006ff198 | 1;
  }
  if (((g_ScWillyScore == 1) && (card_slot == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))))) {
    if ((arg_3 == 0x7d) &&
       ((iVar1 = UI_PaintBigCardInfo((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                              0x200,1,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x800,
                              0), iVar1 == 0 &&
        (iVar1 = UI_PaintBigCardInfo((int *)0x0,0,g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,
                              0x200,1,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400,
                              0), iVar1 != 0)))) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x7e) {
      if (g_DefendingPlayer == 1) {
        local_10 = g_DefendingPlayer;
        local_c = Pic_Subsystem_00441a42(1,1);
        Ai_Subsystem_004cc56d
                  (player,player,card_slot,local_10,local_c,s_Opponent_chooses_to_untap__00524684,0);
      }
      else {
        Action_ValidateTarget_00405802
                  (g_DefendingPlayer,g_DefendingPlayer,g_DefendingPlayer,0x200,1,0,0,0,0,0,-1,-1,
                   0xffffffff,0xffffffff,0,0x401,0,s_PROCESSING_Winter_Orb__Select_la_005246a0,0,
                   &local_10);
      }
      *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) =
           *(uint *)(&DAT_006a6038 + local_10 * 0x5b20 + local_c * 0x120) | 2;
      for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[g_DefendingPlayer];
          local_8 = local_8 + 1) {
        iVar1 = Card_IsTapped(g_DefendingPlayer,local_8);
        if ((((iVar1 != 0) &&
             (((&g_CardSlot_Flags)[g_DefendingPlayer * 0x5b20 + local_8 * 0x120] & 0x10) != 0)) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + g_DefendingPlayer * 0x5b20 + local_8 * 0x120) * 0x34] &
             1) != 0)) && (((&DAT_006a6038)[g_DefendingPlayer * 0x5b20 + local_8 * 0x120] & 2) == 0)
           ) {
          *(uint *)(&DAT_006a6038 + g_DefendingPlayer * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&DAT_006a6038 + g_DefendingPlayer * 0x5b20 + local_8 * 0x120) & 0xfffffffe;
        }
      }
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046458f
 * Entry Point: 0046458f
 * Size: 404 bytes
 */


undefined4 Minit_Subsystem_0046458f(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x82) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    *(uint *)(&DAT_006a6038 + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&DAT_006a6038 + card_slot * 0x120 + player * 0x5b20) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (g_EventSourceSlot == card_slot)) &&
      ((g_EventSourcePlayer == player &&
       ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0 &&
        (g_DefendingPlayer == player)))))) && (DAT_0063edc0 == player)) {
    *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x10;
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\x01';
  }
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\x01';
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00464723
 * Entry Point: 00464723
 * Size: 1029 bytes
 */


int Minit_Subsystem_00464723(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,2);
  }
  else if (arg_3 == 0x90) {
    DAT_0062785c = 2;
    iVar1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,2), iVar1 != 0)) &&
       ((Ai_CalcManaRequirement_004ba890(player,0,2), g_ActivePlayer != 1 &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)))) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 0x80000;
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) + 1;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          iVar1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,g_DialogPromptHwnd,
                               g_DuelArenaHwnd);
          if (iVar1 != -1) {
            *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + player * 0x5b20) = 1;
            *(uint *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + player * 0x5b20) =
                 *(uint *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      iVar1 = *(int *)(&DAT_0063edec + player * 0x20) / 2;
    }
    else {
      if ((arg_3 == 0x8f) && (1 < *(int *)(&DAT_0063eeac + player * 0x20))) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (arg_3 == 199) {
        if (player == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + ((*(int *)(&DAT_0063ee4c + player * 0x20) / 2) * 3 + 3) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + ((*(int *)(&DAT_0063ee4c + player * 0x20) / 2) * 3 + 3) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



/*
 * Decompiled function: Minit_Subsystem_00464b28
 * Entry Point: 00464b28
 * Size: 38 bytes
 */


void Minit_Subsystem_00464b28(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00464b74(player,card_slot,arg_3,7);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00464b4e
 * Entry Point: 00464b4e
 * Size: 38 bytes
 */


void Minit_Subsystem_00464b4e(int player,int card_slot,int arg_3)

{
  Minit_Subsystem_00464b74(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00464b74
 * Entry Point: 00464b74
 * Size: 1108 bytes
 */


undefined4 Minit_Subsystem_00464b74(int x,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (((width == 0x6c) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) {
    Glue_Subsystem_004e6913(x,y,height);
  }
  if ((((g_CurrentStepCode == 0xcc) && (iVar2 = Glue_Subsystem_004e6978(x,y), iVar2 != 0)) &&
      ((y == g_EventSourceSlot && ((x == g_EventSourcePlayer && (DAT_006a4b5c == x)))))) &&
     ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 4) != 0 ||
      (((&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] != -1 && (x != g_DefendingPlayer)))))) {
    if (width == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (width == 0x7e) {
      Glue_Subsystem_004e676b(x,y);
    }
  }
  if (((width == 0x32) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) {
    iVar2 = Glue_Subsystem_004e6978(x,y);
    g_CardEventResult = g_CardEventResult + iVar2;
  }
  uVar1 = g_OverworldPlayerCoordY;
  if (((width == 0x73) && (g_ScWillyScore == 4)) &&
     ((x == g_DefendingPlayer &&
      ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0 && (DAT_0063edc0 == x)))))) {
    iVar2 = Glue_Subsystem_004e6978(x,y);
    if ((iVar2 < height) && (iVar2 = Font_DrawString(x,7,1), iVar2 != 0)) {
      return 1;
    }
  }
  else if (width == 0x90) {
    iVar2 = Font_DrawString(x,7,1);
    iVar5 = 0;
    iVar3 = Glue_Subsystem_004e6978(x,y);
    DAT_0062785c = Math_Clamp(height - iVar3,iVar5,iVar2);
  }
  else {
    if (((width == 0x6d) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) {
      iVar2 = Glue_Subsystem_004e6978(x,y);
      g_OverworldPlayerCoordY = height - iVar2;
      if (x == g_CurrentTurnPhase) {
        uVar4 = Ai_CalcManaRequirement_004ba890(x,0,-1);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = uVar4;
      }
      else {
        iVar2 = Font_DrawString(x,7,1);
        iVar5 = 0;
        iVar3 = Glue_Subsystem_004e6978(x,y);
        iVar2 = Math_Clamp(height - iVar3,iVar5,iVar2);
        uVar4 = Ai_CalcManaRequirement_004ba890(x,0,iVar2);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = uVar4;
      }
      g_OverworldPlayerCoordY = uVar1;
      if (g_ActivePlayer == 1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    if ((width == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + y * 0x120 + x * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + y * 0x120 + x * 0x5b20) * 0x5b20) != -1)) {
      iVar5 = 0;
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20);
      iVar3 = Glue_Subsystem_004e6978(g_DialogPromptHwnd,g_DuelArenaHwnd);
      iVar2 = Math_Clamp(iVar2 + iVar3,iVar5,height);
      Glue_Subsystem_004e6913(g_DialogPromptHwnd,g_DuelArenaHwnd,iVar2);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00464fcd
 * Entry Point: 00464fcd
 * Size: 408 bytes
 */


undefined4 Minit_Subsystem_00464fcd(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x82) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    *(uint *)(&DAT_006a6038 + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&DAT_006a6038 + card_slot * 0x120 + player * 0x5b20) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (g_EventSourceSlot == card_slot)) &&
      ((g_EventSourcePlayer == player &&
       ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0 &&
        (g_DefendingPlayer == player)))))) && (DAT_0063edc0 == player)) {
    *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x10;
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\t';
  }
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\t';
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00465165
 * Entry Point: 00465165
 * Size: 1181 bytes
 */


undefined4 Minit_Subsystem_00465165(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  undefined4 local_c;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005246dc,s_FLYING_CARPET_005246cc);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(undefined4 *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0x8000000;
        iVar1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20));
        if (iVar1 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + spell_id * 0x5b20) = 0x20;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00465602
 * Entry Point: 00465602
 * Size: 983 bytes
 */


/* WARNING: Removing unreachable block (ram,0x004659aa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_00465602(int player,int card_slot,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       (iVar2 = Font_DrawString(player,7,2), iVar2 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar3 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = Font_DrawString(player,7,2), iVar2 != 0)) {
      if (local_c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,0,2);
        *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = local_c;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      iVar2 = Card_ApplyTriggerEffect(player,card_slot,DAT_0069f6dc,
                           (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
      if (iVar2 != -1) {
        cVar1 = Card_UntapCard(player,card_slot,2);
        *(int *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + player * 0x5b20) =
             1 << (cVar1 - 1U & 0x1f);
      }
      *(undefined4 *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
       (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) = 0x8000000;
      Minit_Subsystem_004659d9
                (player,card_slot,*(uint *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20))
      ;
      *(undefined4 *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
    }
    if ((((arg_3 == 0x77) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0)) &&
        (iVar2 = Minit_Subsystem_00465a19(player,card_slot), _DAT_0063ee20 == g_EventSourcePlayer))
       && (g_EventSourceSlot == iVar2)) {
      Pic_Subsystem_0044867e(player,card_slot,2);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/*
 * Decompiled function: Minit_Subsystem_004659d9
 * Entry Point: 004659d9
 * Size: 64 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Minit_Subsystem_004659d9(int player,int card_slot,uint arg_3)

{
  *(uint *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
       (-(uint)(_DAT_0063ee20 == 0) & 0xffffff00) + 0x200 | arg_3;
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00465a19
 * Entry Point: 00465a19
 * Size: 92 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Minit_Subsystem_00465a19(int arg1,int arg2)

{
  _DAT_0063ee20 = (*(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) >> 8) + -1;
  return *(uint *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
}



/*
 * Decompiled function: Minit_Subsystem_00465a75
 * Entry Point: 00465a75
 * Size: 1063 bytes
 */


undefined4 Minit_Subsystem_00465a75(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + (*(int *)(&DAT_006b3010 + spell_id * 4) * 0xc) / 2;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar1 = Font_DrawString(spell_id, 7, 1), iVar1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) && (iVar1 = Font_DrawString(spell_id, 7, 1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005246f8,s_HELM_OF_CHATZUK_005246e8);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,local_10,local_c);
        if (iVar1 != -1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + spell_id * 0x5b20) = 0x40;
        }
        *(undefined4 *)(&g_CardSlot_Abilities2 + local_c * 0x120 + local_10 * 0x5b20) = 0x8000000;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00465e9c
 * Entry Point: 00465e9c
 * Size: 1094 bytes
 */


undefined4 Minit_Subsystem_00465e9c(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    iVar1 = (&DAT_006b3008)[spell_id] * *(int *)(&DAT_006b3010 + spell_id * 4) * 0xc;
    g_SpellStackDepth = g_SpellStackDepth + ((int)(iVar1 + (iVar1 >> 0x1f & 0xfU)) >> 4);
  }
  if (flags == 0x73) {
    if ((((&DAT_006b3008)[spell_id] != 0) && (iVar1 = Font_DrawString(spell_id,7,3), iVar1 != 0)) &&
       (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) && ((&DAT_006b3008)[spell_id] != 0)) &&
       ((iVar1 = Font_DrawString(spell_id,7,3), iVar1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Prompts_Load_0046fa40(spell_id,1,1);
      Pic_Subsystem_00424500(s_prompts_txt_00524710,s_CORAL_HELM_00524704);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_10,local_c,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,local_10,local_c);
        if (iVar1 != -1) {
          *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + spell_id * 0x5b20) = 2;
          *(undefined2 *)(&DAT_006a5f4a + iVar1 * 0x120 + spell_id * 0x5b20) = 2;
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004662e2
 * Entry Point: 004662e2
 * Size: 607 bytes
 */


undefined4 Minit_Subsystem_004662e2(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
        (iVar1 = Font_DrawString(player,7,3), iVar1 != 0)) &&
       ((((&DAT_006a2828)[1 - player] | (&DAT_006a2828)[g_CurrentTurnPhase]) & 2) != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = Font_DrawString(player,7,3), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,3);
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      if (local_c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = local_c;
      }
    }
    if (((arg_3 == 0x72) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) &&
       (iVar1 = Card_ApplyTriggerEffect(player,card_slot,DAT_006a2854,
                             (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20)),
       iVar1 != -1)) {
      *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + player * 0x5b20) = 0xfffe;
      *(undefined2 *)(&DAT_006a5f4a + iVar1 * 0x120 + player * 0x5b20) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00466541
 * Entry Point: 00466541
 * Size: 1053 bytes
 */


undefined4 Minit_Subsystem_00466541(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0x2002;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((iVar1 = Font_DrawString(spell_id,7,2), iVar1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_00524728,s_TAWNOS_WAND_0052471c);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0x2002;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0x2002;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,
                         iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00696734,local_c,local_8);
      }
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x18;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Card_Setup_0046695e
 * Entry Point: 0046695e
 * Size: 349 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Card_Setup_0046695e(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,1);
    if ((iVar1 == 0) || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      strcpy(&g_OverworldWorldState,s_Tap_which_card__00524734);
      if (local_8 != -1) {
        *(uint *)(&g_CardSlot_Flags + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_8 * 0x120 + _DAT_0063ee20 * 0x5b20) | 0x10;
        Magic_BroadcastCardEvent(_DAT_0063ee20,local_8,0x7c);
      }
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00466abb
 * Entry Point: 00466abb
 * Size: 617 bytes
 */


undefined4 Minit_Subsystem_00466abb(int player,int card_slot,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x73) {
    if ((((*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0) &&
         (iVar1 = Font_DrawString(player,7,5), iVar1 != 0)) &&
        ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      if ((player == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      return 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,5), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,5), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
      if (0 < DAT_006ff550) {
        DAT_006ff550 = DAT_006ff550 + -1;
      }
    }
    if (arg_3 == 0x72) {
      iVar1 = Pic_Subsystem_0045268f(0x375);
      iVar1 = Pic_Subsystem_00451291(player,iVar1);
      if (iVar1 != -1) {
        Pic_Subsystem_0042ac1f(player,iVar1);
        *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) | 0x10;
      }
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00466d29
 * Entry Point: 00466d29
 * Size: 563 bytes
 */


undefined4 Minit_Subsystem_00466d29(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,1);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) ||
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_0044867e(player,card_slot,3);
    }
    if (arg_3 == 0x72) {
      if (player == g_CurrentTurnPhase) {
        strcpy(&g_OverworldWorldState,s_Heads_Tails_00524744);
      }
      else {
        strcpy(&g_OverworldWorldState,s_Call_the_coin_flip__Heads_Tails_00524754);
      }
      iVar1 = Math_RandomRange(1);
      iVar1 = Ai_Subsystem_004cc56d(1 - player,player,card_slot,-1,-1,&g_OverworldWorldState,iVar1);
      strcpy(&g_OverworldWorldState,&DAT_00524778);
      iVar3 = Ai_Subsystem_004b7d38(s_Bottle_of_Suleiman_0052477c);
      if (iVar3 == iVar1) {
        Mem_AllocOrFree_0041df33(player,5,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      else {
        iVar1 = Pic_Subsystem_0045268f(0x37a);
        iVar1 = Pic_Subsystem_00451291(player,iVar1);
        if (iVar1 != -1) {
          Pic_Subsystem_0042ac1f(player,iVar1);
          *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) | 0x10;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_00466f5c
 * Entry Point: 00466f5c
 * Size: 320 bytes
 */


undefined4 Minit_Subsystem_00466f5c(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,1);
    if ((iVar1 == 0) || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = Font_DrawString(player,7,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,1), g_ActivePlayer != 1)) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar1 = Card_IsTapped(local_8,local_c);
          if ((iVar1 != 0) && (iVar1 = Math_RandomRange(3), iVar1 == 0)) {
            Pic_Subsystem_0044867e(local_8,local_c,2);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Player_Init_0046709c
 * Entry Point: 0046709c
 * Size: 718 bytes
 */


undefined4 Player_Init_0046709c(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_94;
  int local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c [30];
  
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_005247a0,s_GLASSES_OF_URZA_00524790);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_90);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_90;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8c
        ;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_94 = 0;
      local_88 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      if (((g_IsAiThinking != 1) && (spell_id == 0)) && (DAT_006fedc0 == 0)) {
        for (local_84 = 0; local_84 < (int)(&g_PlayerActiveCardCount)[local_88];
            local_84 = local_84 + 1) {
          local_80 = *(int *)(&g_CardSlot_CardId + local_88 * 0x5b20 + local_84 * 0x120);
          if ((local_80 != -1) &&
             (((&g_CardSlot_Flags)[local_88 * 0x5b20 + local_84 * 0x120] & 2) == 0)) {
            local_7c[local_94] = local_80;
            local_94 = local_94 + 1;
          }
        }
        Pic_Load_004509e8(0,(int)local_7c,local_94,s_Target_Player_s_Hand_005247b4,0);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0046736a
 * Entry Point: 0046736a
 * Size: 258 bytes
 */


undefined4 Minit_Subsystem_0046736a(int player,int card_slot,int arg_3)

{
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_PlayerHandCardCount = g_PlayerHandCardCount | 0x800 << ((byte)player & 0x1f);
  }
  if (((arg_3 == 0x1f) && (g_DefendingPlayer == player)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_PlayerHandCardCount = g_PlayerHandCardCount & ~(0x800 << ((byte)player & 0x1f));
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046746c
 * Entry Point: 0046746c
 * Size: 288 bytes
 */


undefined4 Minit_Subsystem_0046746c(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,3);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (Ai_CalcManaRequirement_004ba890(player,0,3), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Minit_Subsystem_0046758c();
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Minit_Subsystem_0046758c
 * Entry Point: 0046758c
 * Size: 546 bytes
 */


undefined4 Minit_Subsystem_0046758c(void)

{
  int iVar1;
  int arg1;
  int iVar2;
  int local_fb4;
  int aiStack_fac [1000];
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_fb4 = 0; local_fb4 < 2; local_fb4 = local_fb4 + 1) {
    local_c = 0;
    while ((local_c < 500 &&
           (aiStack_fac[local_8] = *(int *)(&DAT_0069e730 + local_c * 4 + local_fb4 * 2000),
           *(int *)(&DAT_0069e730 + local_c * 4 + local_fb4 * 2000) != -1))) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&DAT_0069e730 + local_c * 4 + local_fb4 * 2000) * 0x34] & 2) != 0) {
        local_8 = local_8 + 1;
      }
      local_c = local_c + 1;
    }
  }
  iVar1 = Math_RandomRange(local_8);
  iVar1 = aiStack_fac[iVar1];
  if (iVar1 == -1) {
    g_ActivePlayer = 1;
  }
  else {
    arg1 = Math_RandomRange(2);
    local_c = Pic_Subsystem_00451291(arg1,iVar1);
    if (local_c != -1) {
      *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg1 * 0x5b20) | 0x10;
      Pic_Subsystem_0042ac1f(arg1,local_c);
      iVar2 = Math_RandomRange(2);
      if ((iVar2 != 0) && (local_c = Pic_Subsystem_00451291(1 - arg1,iVar1), local_c != -1)) {
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + (1 - arg1) * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + (1 - arg1) * 0x5b20) | 0x10;
        Pic_Subsystem_0042ac1f(1 - arg1,local_c);
      }
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x28);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004677ae
 * Entry Point: 004677ae
 * Size: 203 bytes
 */


undefined4 Minit_Subsystem_004677ae(int player,int card_slot,int arg_3)

{
  int arg_3_00;
  uint arg_2_00;
  
  if ((((arg_3 == 0x7f) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    arg_3_00 = Card_SetTapState(player, card_slot, 4);
    arg_2_00 = Card_SetTapState(player,card_slot,5);
    FUN_0040d72b(player,arg_2_00,arg_3_00);
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00467880
 * Entry Point: 00467880
 * Size: 287 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool Minit_Subsystem_00467880(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Card_Setup_00467a68;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_00538db4 = CreatePopupMenu();
  DAT_00538db0 = CreatePopupMenu();
  AppendMenuA(DAT_00538db0,0,0x72,&DAT_005248f4);
  DAT_00538df0 = LoadCursorA(g_AppHInstance,s_HAND1_005248f8);
  DAT_00538ddc = 3;
  _DAT_00538dd0 = LoadCursorA(g_AppHInstance,s_HAND2_00524900);
  _DAT_00538dd4 = LoadCursorA(g_AppHInstance,s_HAND3_00524908);
  _DAT_00538dd8 = LoadCursorA(g_AppHInstance,s_HAND4_00524910);
  return AVar1 != 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046799f
 * Entry Point: 0046799f
 * Size: 201 bytes
 */


void Minit_Subsystem_0046799f(void)

{
  int local_8;
  
  if (DAT_00538db4 != (HMENU)0x0) {
    DestroyMenu(DAT_00538db4);
  }
  if (DAT_00538db0 != (HMENU)0x0) {
    DestroyMenu(DAT_00538db0);
  }
  DAT_00538db4 = (HMENU)0x0;
  DAT_00538db0 = (HMENU)0x0;
  if (DAT_00538df0 != (HCURSOR)0x0) {
    DestroyCursor(DAT_00538df0);
  }
  DAT_00538df0 = (HCURSOR)0x0;
  for (local_8 = 0; local_8 < DAT_00538ddc; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00538dd0 + local_8 * 4) != 0) {
      DestroyCursor(*(HCURSOR *)(&DAT_00538dd0 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00538dd0 + local_8 * 4) = 0;
  }
  return;
}



/*
 * Decompiled function: Card_Setup_00467a68
 * Entry Point: 00467a68
 * Size: 12124 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Card_Setup_00467a68(HWND hwnd,uint uMsg,LONG *wParam,int *lParam)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  byte arg_3;
  uint uVar1;
  LONG LVar2;
  HWND pHVar3;
  HBRUSH pHVar4;
  int iVar5;
  uint uVar6;
  DWORD DVar7;
  BOOL BVar8;
  LRESULT LVar9;
  UINT UVar10;
  int *wParam_00;
  LONG *pLVar11;
  LPARAM LVar12;
  int iVar13;
  int local_960;
  undefined4 local_954;
  HWND local_950;
  int local_94c;
  uint local_948;
  uint local_944;
  uint local_940;
  undefined4 local_93c;
  undefined4 local_938;
  uint local_934;
  uint local_930;
  undefined4 local_92c;
  uint local_928;
  undefined4 local_924;
  HWND local_920;
  tagMSG local_91c;
  HWND local_900;
  int local_8fc;
  tagPOINT local_8f8;
  tagRECT local_8f0;
  undefined4 local_8e0;
  uint local_8dc;
  uint local_8d8;
  int local_8d4;
  int local_8d0;
  int local_8cc;
  int local_8c8;
  HDC local_8c4;
  tagPAINTSTRUCT local_8c0;
  tagRECT local_880;
  DWORD local_870;
  ULONG_PTR local_86c;
  undefined4 local_868;
  undefined4 local_864;
  HWND local_860;
  HWND local_85c;
  HWND local_858;
  tagRECT local_854;
  tagMSG local_844;
  BOOL local_828;
  int local_824;
  tagRECT local_820;
  LONG *local_810;
  undefined4 local_80c;
  CHAR local_808 [100];
  int local_7a4;
  int local_7a0;
  int local_79c;
  int local_798;
  int local_794;
  undefined1 local_790 [20];
  uint local_77c;
  char local_778 [208];
  int local_6a8;
  int local_6a4;
  int local_6a0;
  CHAR local_69c [100];
  int local_638;
  int local_634;
  int local_630;
  int local_62c;
  int local_628;
  undefined1 local_624 [20];
  uint local_610;
  char local_60c [208];
  int local_53c [2];
  char local_534 [264];
  ULONG_PTR local_42c;
  uint local_428;
  int local_424;
  int local_420;
  WPARAM local_41c;
  LONG local_418;
  LONG local_414;
  HWND local_410;
  int local_40c;
  HWND local_408 [2];
  undefined1 local_400 [288];
  LONG *local_2e0;
  HDC local_2d4;
  tagRECT local_2d0;
  ULONG_PTR local_2c0;
  undefined1 local_2bc [84];
  int local_268;
  uint local_19c;
  uint local_198;
  uint local_194;
  tagRECT local_190;
  char local_180 [100];
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int local_10c;
  int local_108;
  uint local_104 [18];
  tagRECT local_bc;
  int local_ac;
  int local_a8;
  int local_a4;
  char *local_a0 [4];
  char *local_90;
  char *local_8c;
  char *local_88;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  uint local_5c;
  int local_58;
  tagRECT local_54;
  int local_44;
  int local_40;
  int local_3c;
  tagRECT local_38;
  tagRECT local_28;
  int local_18;
  void *local_14;
  int local_10;
  int local_c;
  HWND local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      LVar9 = SendMessageA(hwnd,0x404,0,0);
      if (LVar9 != 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_870 = GetTickCount();
      GetClientRect(hwnd,&local_880);
      local_8c4 = BeginPaint(hwnd,&local_8c0);
      if (local_8c4 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_8c4);
        if (DAT_0068a674 != 0) {
          pHVar4 = GetStockObject(0);
          FillRect(local_8c4,&local_880,pHVar4);
          Sleep(200);
        }
        if ((local_c == -1) && (local_10 == -1)) {
          Palette_Subsystem_0049c6cb(local_8c4,&local_880);
        }
        else if (local_10 == -1) {
          FUN_004097e2(local_8c4,&local_880,local_c);
          pHVar4 = GetStockObject(4);
          FrameRect(local_8c4,&local_880,pHVar4);
        }
        else {
          local_86c = Ai_Subsystem_004b5cbb(local_c,local_10);
          if ((local_86c != 0xffffffff) && ((int)local_86c < DAT_006a49f4)) {
            if (local_86c == DAT_006ff2e8) {
              Palette_Subsystem_0049c6cb(local_8c4,&local_880);
              iVar13 = 1;
              iVar5 = Ai_Subsystem_004b673e(local_c,local_10);
              Palette_Subsystem_004a11fa
                        (local_8c4,&local_880.left,s_Draw_a_card_00524c50,iVar5,iVar13);
            }
            else if ((((local_86c == DAT_00695e94) || (local_86c == DAT_0068a70c)) ||
                     (local_86c == DAT_0068a694)) || (local_86c == DAT_006a2848)) {
              Ai_Subsystem_004b6023(&local_8cc,local_c,local_10);
              Palette_Subsystem_004a155f(local_8c4,&local_880.left,local_86c,local_c,local_10);
              iVar5 = Ai_Subsystem_004b682f(local_c,local_10);
              iVar13 = Ai_Subsystem_004b67ab(local_c,local_10);
              Palette_Subsystem_004a289f(local_8c4,&local_880.left,iVar13,iVar5);
              Palette_Subsystem_004a0466(local_8c4,&local_880.left,local_8cc,local_8c8,DAT_006fe438)
              ;
            }
            else if (local_86c == DAT_006ff2dc) {
              Ai_Subsystem_004b6da5(&local_8d4,local_c,local_10);
              Palette_Subsystem_004a1b64
                        (g_HdcBackBuffer,&local_880,local_86c,local_c,local_10,local_8d4,local_8d0);
              iVar5 = Ai_Subsystem_004b682f(local_8d4,local_8d0);
              iVar13 = Ai_Subsystem_004b67ab(local_8d4,local_8d0);
              Palette_Subsystem_004a289f(g_HdcBackBuffer,&local_880.left,iVar13,iVar5);
              Palette_Subsystem_004a0466
                        (g_HdcBackBuffer,&local_880.left,local_8d4,local_8d0,DAT_006fe438);
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,g_HdcBackBuffer,0,0,0xcc0020);
            }
            else {
              local_8d8 = Ai_Subsystem_004b5de4(local_c,local_10);
              pHVar3 = GetParent(hwnd);
              if (pHVar3 == DAT_006b3064) {
                local_8dc = 0;
              }
              else {
                local_8dc = local_8d8 & 4;
                local_8e0 = Ai_Subsystem_004b5b6f(local_c,local_10);
              }
              Ai_Subsystem_004b673e(local_c,local_10);
              Palette_Subsystem_004a1e09(g_HdcBackBuffer,&local_880.left,local_c,local_10);
              iVar5 = Ai_Subsystem_004b682f(local_c,local_10);
              iVar13 = Ai_Subsystem_004b67ab(local_c,local_10);
              Palette_Subsystem_004a289f(g_HdcBackBuffer,&local_880.left,iVar13,iVar5);
              uVar6 = Ai_Subsystem_004b6c5b(local_c,local_10);
              Palette_Subsystem_004a29c5(g_HdcBackBuffer,&local_880.left,uVar6 & 0x20000);
              arg_3 = Ai_Subsystem_004b6cc8(local_c,local_10);
              Palette_Subsystem_004a2a5b(g_HdcBackBuffer,&local_880,arg_3);
              Palette_Subsystem_004a0466
                        (g_HdcBackBuffer,&local_880.left,local_c,local_10,DAT_006fe438);
              uVar6 = Ai_Subsystem_004b613b(local_c,local_10);
              if ((((uVar6 & 2) != 0) || (DAT_006fe440 != 0)) &&
                 (uVar6 = Ai_Subsystem_004b5de4(local_c,local_10), (uVar6 & 1) != 0)) {
                Palette_Util_004a2edc(&DAT_006a4a20,DAT_006b2e1c,&local_880);
              }
              if ((local_8d8 & 2) != 0) {
                FUN_004f48f1(0x6a4a20,DAT_006b2e1c,&local_880);
              }
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,g_HdcBackBuffer,0,0,0xcc0020);
            }
            local_14 = (void *)GetWindowLongA(hwnd,0xc);
            Ai_Subsystem_004b70fe(local_14,local_c,local_10);
            if (DAT_006808c4 != 0) {
              FUN_0046ba19(local_8c4,(int)&local_880,local_c,local_10);
            }
          }
        }
        EndPaint(hwnd,&local_8c0);
      }
      DVar7 = GetTickCount();
      _DAT_00696738 = _DAT_00696738 + (DVar7 - local_870);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_810 = (LONG *)*lParam;
      if (local_810 == (LONG *)0x0) {
        return -1;
      }
      local_c = *local_810;
      local_10 = local_810[1];
      SetWindowLongA(hwnd,0,local_c);
      SetWindowLongA(hwnd,4,local_10);
      local_8 = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      local_14 = malloc(0x120);
      SetWindowLongA(hwnd,0xc,(LONG)local_14);
      SetWindowLongA(hwnd,0x10,0);
      if (local_14 == (void *)0x0) {
        return -1;
      }
      memset(local_14,0,0x120);
      return 0;
    }
    if (uMsg == 2) {
      local_14 = (void *)GetWindowLongA(hwnd,0xc);
      free(local_14);
      return 0;
    }
    if (uMsg == 3) {
      LVar12 = 0;
      UVar10 = 0x410;
      pHVar3 = GetParent(hwnd);
      SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar9 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,(LPARAM)lParam);
      return LVar9;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x117) {
    if (uMsg == 0x116) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_940 = Ai_Subsystem_004b5de4(local_c,local_10);
      local_940 = local_940 & 4;
      if (local_940 != 0) {
        Ai_Subsystem_004b5b6f(local_c,local_10);
      }
      local_938 = Ai_Subsystem_004b5b6f(local_c,local_10);
      local_93c = FUN_0046ab25(hwnd);
      local_948 = Ai_Subsystem_004b6288(local_c,local_10);
      local_948 = local_948 & 0x40;
      local_94c = Ai_Subsystem_004b5d2e(local_c,local_10);
      local_944 = Ai_Subsystem_004b5c4b(local_c,local_10);
      local_924 = Ai_Subsystem_004b5cbb(local_c,local_10);
      local_930 = Ai_Subsystem_004b6432(local_c,local_10);
      local_930 = local_930 & 0x40000;
      local_934 = *(uint *)(&DAT_0051aed0 + local_944 * 0x34) & 0x1000;
      uVar6 = Ai_Subsystem_004b613b(local_c,local_10);
      local_950 = GetParent(hwnd);
      local_928 = Ai_Subsystem_004b6e3b(local_c,local_10);
      Ai_Subsystem_004b74b1(&local_92c,&local_954);
      if (local_944 != local_928) {
        AppendMenuA(DAT_00538db4,0x10,(UINT_PTR)DAT_00538db0,s_Original_type_00524c5c);
        iVar5 = CardIDFromType(local_928);
        ModifyMenuA(DAT_00538db0,0x72,0,0x72,*(LPCSTR *)(&DAT_006b3074 + iVar5 * 0x98));
      }
      if (DAT_006fe444 == 2) {
        AppendMenuA(DAT_00538db4,0,0x6e,s_Show_full_card_R_DblClk_00524c6c);
      }
      else {
        AppendMenuA(DAT_00538db4,0,0x6e,s_View_in_full_card_00524c84);
      }
      if (((((uVar6 & 1) != 0) && (local_934 != 0)) &&
          (pHVar3 = GetParent(hwnd), pHVar3 == DAT_006a4924)) &&
         (AppendMenuA(DAT_00538db4,0,0x70,s_Don_t_auto_tap_this_card_00524c98), local_930 != 0)) {
        CheckMenuItem(DAT_00538db4,0x70,8);
      }
      AppendMenuA(DAT_00538db4,0,0x73,s_Show_ID_tags_Ctrl_T_00524cb4);
      if (DAT_006fe438 != 0) {
        CheckMenuItem(DAT_00538db4,0x73,8);
      }
      AppendMenuA(DAT_00538db4,0,0x74,s_Show_invisible_effects_Ctrl_I_00524cc8);
      if (DAT_006fe43c != 0) {
        CheckMenuItem(DAT_00538db4,0x74,8);
      }
      AppendMenuA(DAT_00538db4,0,0x75,s_Show_all_cards__summoning_sickne_00524ce8);
      if (DAT_006fe440 != 0) {
        CheckMenuItem(DAT_00538db4,0x75,8);
      }
      AppendMenuA(DAT_00538db4,0,0x71,s_Help____00524d14);
      if ((DAT_0068a718 != 0) && (DAT_006b1578 != 0)) {
        if (local_94c == 0) {
          AppendMenuA(DAT_00538db4,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_00538db4,0,0x262,s__M__Add_mana_for_this_card_00524d1c);
          AppendMenuA(DAT_00538db4,0,0x264,s__B__Bury_this_card_00524d38);
        }
        else {
          AppendMenuA(DAT_00538db4,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_00538db4,0,0x262,s__M__Add_mana_for_this_card_00524d4c);
          AppendMenuA(DAT_00538db4,0,0x263,s__T__Tap_untap_this_card_00524d68);
          AppendMenuA(DAT_00538db4,0,0x264,s__B__Bury_this_card_00524d80);
          AppendMenuA(DAT_00538db4,0,0x266,s__X__Increment_counters_for_this_c_00524d94);
        }
      }
      return 0;
    }
    if (uMsg == 0x111) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      local_418 = local_c;
      local_414 = local_10;
      pHVar3 = GetParent(hwnd);
      if (pHVar3 == DAT_006b3064) {
        local_410 = hwnd;
        Glue_Subsystem_004ef849(DAT_006a4924,&local_418,(undefined4 *)0x0,local_408);
      }
      else {
        local_408[0] = hwnd;
        FUN_00483139(DAT_006b3064,&local_418,(undefined4 *)0x0,&local_410,(undefined4 *)0x0);
      }
      uVar6 = (uint)wParam & 0xffff;
      if (uVar6 < 0x263) {
        if (uVar6 == 0x262) {
          if (DAT_0068a718 != 0) {
            local_40c = *(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_10 * 0x120);
            iVar5 = (int)(char)(&DAT_0051aebf)[local_40c * 0x34];
            iVar13 = Card_ColorMaskToColorIndex((&DAT_0051aebe)
                                  [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_10 * 0x120
                                           ) * 0x34]);
            FUN_0040d875(local_c,iVar13,iVar5);
            iVar5 = abs((int)(char)(&DAT_0051aec0)[local_40c * 0x34]);
            FUN_0040d875(local_c,0,iVar5);
            Ai_Subsystem_004b584e();
            Ai_EvalAttackCandidate_004b4a3f(0,0xff);
          }
        }
        else {
          switch(uVar6) {
          case 100:
          case 0x6d:
            DAT_00627864 = 0;
            FUN_0046aa75(hwnd);
            break;
          case 0x65:
            Ai_Subsystem_004b74b1((undefined4 *)0x0,local_53c);
            iVar5 = FUN_004726c5(local_c,local_10);
            if (iVar5 != 0) {
              local_53c[1] = 0xffffffff;
              *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) | 4;
              (&g_CardSlot_ColorMask)[local_c * 0x5b20 + local_10 * 0x120] = 0xff;
              Ai_Subsystem_004b42dc();
              if ((local_53c[0] < 0x15) || (0x1d < local_53c[0])) {
                LVar12 = 0;
                pLVar11 = &local_418;
                UVar10 = 0x436;
                pHVar3 = GetParent(hwnd);
                SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
              }
              else {
                SendMessageA(DAT_006b3064,0x412,0,0);
              }
            }
            break;
          case 0x66:
            iVar5 = Ai_Subsystem_004b5b6f(local_c,local_10);
            if (iVar5 != -1) {
              SendMessageA(hwnd,0x111,0x69,0);
            }
            *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) & 0xfffffffb;
            (&g_CardSlot_ColorMask)[local_c * 0x5b20 + local_10 * 0x120] = 0xff;
            Ai_Subsystem_004b42dc();
            if (hwnd == local_410) {
              SendMessageA(DAT_006b3064,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x68:
            SendMessageA(hwnd,0x111,0x69,0);
          case 0x67:
            iVar5 = FUN_004726c5(local_c,local_10);
            if (iVar5 != 0) {
              memcpy(local_624,&DAT_006feec0,0xe8);
              GetWindowTextA(DAT_00695ea0,local_69c,100);
              local_628 = DAT_006b1578;
              local_634 = Action_ValidateTarget_00405802
                                    (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                     s_Band_with_which_attacker__00524bcc,1,&local_630);
              DAT_006b1578 = local_628;
              if (local_634 != 0) {
                uVar6 = Ai_Subsystem_004b5de4(local_630,local_62c);
                if ((uVar6 & 4) == 0) {
                  UpdateWindow(g_MainAppHwnd);
                  Ai_Subsystem_004b5501(s_That_isn_t_an_attacker_00524bf8);
                  UpdateWindow(DAT_007006b0);
                  Sleep(2000);
                }
                else {
                  iVar5 = FUN_0048225c(local_c,local_10);
                  if (iVar5 == 0) {
                    UpdateWindow(g_MainAppHwnd);
                    Ai_Subsystem_004b5501(s_Illegal_band_00524be8);
                    UpdateWindow(DAT_007006b0);
                    Sleep(2000);
                  }
                  else {
                    local_638 = Ai_Subsystem_004b5b6f(local_630,local_62c);
                    if (local_638 == -1) {
                      local_638 = local_62c;
                      iVar5 = local_638;
                      *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                           *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) | 4;
                      local_638._0_1_ = (undefined1)local_62c;
                      (&g_CardSlot_ColorMask)[local_c * 0x5b20 + local_10 * 0x120] =
                           (undefined1)local_638;
                      *(uint *)(&g_CardSlot_Flags + local_630 * 0x5b20 + local_62c * 0x120) =
                           *(uint *)(&g_CardSlot_Flags + local_630 * 0x5b20 + local_62c * 0x120) | 4
                      ;
                      (&g_CardSlot_ColorMask)[local_630 * 0x5b20 + local_62c * 0x120] =
                           (undefined1)local_638;
                      local_638 = iVar5;
                      Ai_Subsystem_004b42dc();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(DAT_006b3064);
                      if (BVar8 == 0) {
                        LVar12 = 0;
                        wParam_00 = &local_630;
                        UVar10 = 0x436;
                        pHVar3 = GetParent(local_408[0]);
                        SendMessageA(pHVar3,UVar10,(WPARAM)wParam_00,LVar12);
                      }
                      else {
                        SendMessageA(DAT_006b3064,0x412,0,0);
                        SendMessageA(DAT_006b3064,0x436,(WPARAM)&local_630,0);
                      }
                    }
                    else {
                      *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                           *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) | 4;
                      (&g_CardSlot_ColorMask)[local_c * 0x5b20 + local_10 * 0x120] =
                           (undefined1)local_638;
                      Ai_Subsystem_004b42dc();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(DAT_006b3064);
                      if (BVar8 != 0) {
                        SendMessageA(DAT_006b3064,0x412,0,0);
                      }
                    }
                  }
                }
              }
              memcpy(&DAT_006feec0,local_624,0xe8);
              FUN_00477d73(DAT_007006b0,local_60c,local_610);
              Ai_Subsystem_004b553f(local_69c);
            }
            break;
          case 0x69:
            local_6a0 = Ai_Subsystem_004b5b6f(local_c,local_10);
            for (local_6a4 = 0; local_6a4 < (int)(&g_PlayerActiveCardCount)[local_c];
                local_6a4 = local_6a4 + 1) {
              iVar5 = Ai_Subsystem_004b5c4b(local_c,local_6a4);
              if (((iVar5 != -1) &&
                  (uVar6 = Ai_Subsystem_004b5de4(local_c,local_6a4), (uVar6 & 4) != 0)) &&
                 (iVar5 = Ai_Subsystem_004b5b6f(local_c,local_6a4), iVar5 == local_6a0)) {
                (&g_CardSlot_ColorMask)[local_6a4 * 0x120 + local_c * 0x5b20] = 0xff;
                Ai_Subsystem_004b42dc();
                local_418 = local_c;
                local_414 = local_6a4;
                BVar8 = IsWindowVisible(DAT_006b3064);
                if (BVar8 == 0) {
                  LVar12 = 0;
                  pLVar11 = &local_418;
                  UVar10 = 0x436;
                  pHVar3 = GetParent(local_408[0]);
                  SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                }
                else {
                  SendMessageA(DAT_006b3064,0x436,(WPARAM)&local_418,0);
                }
              }
            }
            BVar8 = IsWindowVisible(DAT_006b3064);
            if (BVar8 != 0) {
              SendMessageA(DAT_006b3064,0x412,0,0);
            }
            break;
          case 0x6a:
          case 0x6b:
            memcpy(local_790,&DAT_006feec0,0xe8);
            GetWindowTextA(DAT_00695ea0,local_808,100);
            local_794 = DAT_006b1578;
            local_7a0 = Action_ValidateTarget_00405802
                                  (0,1,0,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                   s_Block_which_attacker__00524c10,1,&local_79c);
            DAT_006b1578 = local_794;
            if (local_7a0 != 0) {
              uVar6 = Ai_Subsystem_004b5de4(local_79c,local_798);
              if ((uVar6 & 4) == 0) {
                UpdateWindow(g_MainAppHwnd);
                Ai_Subsystem_004b5501(s_That_isn_t_an_attacker_00524c38);
                UpdateWindow(DAT_007006b0);
                Sleep(2000);
              }
              else {
                iVar5 = FUN_00472e08(local_c,local_10,local_79c,local_798);
                if (iVar5 == 0) {
                  UpdateWindow(g_MainAppHwnd);
                  Ai_Subsystem_004b5501(s_Illegal_block_00524c28);
                  UpdateWindow(DAT_007006b0);
                  Sleep(2000);
                }
                else {
                  local_7a4 = Ai_Subsystem_004b5b6f(local_79c,local_798);
                  local_6a8 = local_7a4;
                  if (local_7a4 == -1) {
                    local_6a8 = local_798;
                  }
                  *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                       *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) | 8;
                  (&g_CardSlot_ColorMask)[local_c * 0x5b20 + local_10 * 0x120] =
                       (undefined1)local_6a8;
                  Ai_Subsystem_004b42dc();
                  BVar8 = IsWindowVisible(DAT_006b3064);
                  if ((BVar8 == 0) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_006b3064)) {
                    LVar12 = 0;
                    pLVar11 = &local_418;
                    UVar10 = 0x436;
                    pHVar3 = GetParent(hwnd);
                    SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                  }
                  else {
                    SendMessageA(DAT_006b3064,0x412,0,0);
                  }
                }
              }
            }
            memcpy(&DAT_006feec0,local_790,0xe8);
            FUN_00477d73(DAT_007006b0,local_778,local_77c);
            Ai_Subsystem_004b553f(local_808);
            break;
          case 0x6c:
            *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) & 0xfffffff7;
            (&g_CardSlot_ColorMask)[local_c * 0x5b20 + local_10 * 0x120] = 0xff;
            Ai_Subsystem_004b42dc();
            if (hwnd == local_410) {
              SendMessageA(DAT_006b3064,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x6e:
            local_41c = Ai_Subsystem_004b5cbb(local_c,local_10);
            local_424 = local_c;
            local_420 = local_10;
            SendMessageA(DAT_0069f744,0x401,local_41c,(LPARAM)&local_424);
            break;
          case 0x6f:
            pHVar3 = GetParent(hwnd);
            if ((pHVar3 == DAT_0069e720) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_006fe400)) {
              LVar12 = 0;
              UVar10 = 0x400;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
            }
            break;
          case 0x70:
            uVar6 = Ai_Subsystem_004b6432(local_c,local_10);
            local_428 = (uint)((uVar6 & 0x40000) == 0);
            if (local_428 == 0) {
              *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) & 0xfffbffff;
            }
            else {
              *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) | 0x40000;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
            *(undefined4 *)(&DAT_0068a73c + local_c * 0x5b20 + local_10 * 0x120) =
                 *(undefined4 *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120);
            LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
            InvalidateRect(hwnd,(RECT *)0x0,1);
            break;
          case 0x71:
            local_42c = Ai_Subsystem_004b5cbb(local_c,local_10);
            if (local_42c == DAT_006ff2e8) {
              local_42c = 0xc1b;
            }
            if (local_42c != 0xffffffff) {
              strcpy(local_534,&DAT_006807a0);
              strcat(local_534,s__duel_hlp_00524bc0);
              WinHelpA(g_MainAppHwnd,local_534,1,local_42c);
            }
            break;
          case 0x73:
            SendMessageA(g_MainAppHwnd,0x111,0x279,0);
            break;
          case 0x74:
            SendMessageA(g_MainAppHwnd,0x111,0x27a,0);
            break;
          case 0x75:
            SendMessageA(g_MainAppHwnd,0x111,0x27c,0);
          }
        }
      }
      else if (uVar6 == 0x263) {
        if (DAT_0068a718 != 0) {
          *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_c * 0x5b20 + local_10 * 0x120) ^ 0x10;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
      }
      else if (uVar6 == 0x264) {
        if (DAT_0068a718 != 0) {
          local_80c = *(undefined4 *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98)
          ;
          *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) =
               *(uint *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) & 0xfffe;
          *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x5b20 + local_10 * 0x120) | 8;
          Pic_Subsystem_0044867e(local_c,local_10,2);
          *(undefined4 *)(&DAT_00696740 + g_ScWillyScore * 4 + g_DefendingPlayer * 0x98) = local_80c
          ;
          Ai_EvalAttackCandidate_004b4a3f(0,0xff);
        }
      }
      else if ((uVar6 == 0x266) && (DAT_0068a718 != 0)) {
        *(int *)(&DAT_006a5f7c + local_c * 0x5b20 + local_10 * 0x120) =
             *(int *)(&DAT_006a5f7c + local_c * 0x5b20 + local_10 * 0x120) + 1;
        Ai_EvalAttackCandidate_004b4a3f(0,0xff);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      UVar10 = GetDoubleClickTime();
      LVar2 = GetMessageTime();
      DVar7 = GetTickCount();
      Sleep(UVar10 - (LVar2 - DVar7));
      local_828 = PeekMessageA(&local_844,hwnd,0x203,0x203,0);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 == DAT_006a4924) || (pHVar3 = GetParent(hwnd), pHVar3 == DAT_006b2e2c)) {
        if (local_8 == (HWND)0x0) {
          local_85c = hwnd;
        }
        else {
          local_85c = local_8;
          pHVar3 = local_85c;
          do {
            local_85c = pHVar3;
            local_860 = (HWND)FUN_0046bc92(local_85c);
            pHVar3 = local_860;
          } while (local_860 != (HWND)0x0);
          local_860 = (HWND)0x0;
        }
        GetWindowRect(local_85c,&local_854);
        local_858 = GetWindow(local_85c,3);
        SendMessageA(local_85c,0x112,0xf012,0);
        GetWindowRect(local_85c,&local_820);
        iVar5 = abs(local_854.top - local_820.top);
        iVar13 = abs(local_854.left - local_820.left);
        if (iVar5 + iVar13 < 5) {
          local_824 = 0;
          SetWindowPos(local_85c,local_858,0,0,0,0,3);
        }
        else {
          local_824 = 1;
        }
      }
      else {
        local_824 = 0;
      }
      if (local_824 == 0) {
        Ai_Subsystem_004b74b1(&local_864,&local_868);
        iVar5 = FUN_0046ab25(hwnd);
        if (iVar5 != 0) {
          DAT_00627864 = local_828;
          FUN_0046aa75(hwnd);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == (int *)0x0)) {
        local_960 = GetMenuItemCount(DAT_00538db4);
        while (local_960 != 0) {
          RemoveMenu(DAT_00538db4,0,0x400);
          local_960 = local_960 + -1;
        }
        pHVar3 = GetParent(hwnd);
        if ((pHVar3 != DAT_0069e720) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_006fe400)) {
          pHVar3 = (HWND)GetWindowLongA(hwnd,0x10);
          SetWindowPos(hwnd,pHVar3,0,0,0,0,3);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar9 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar9;
    }
    if (uMsg == 0x204) {
      local_8fc = 1;
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != DAT_0069e720) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_006fe400)) {
        local_900 = GetWindow(hwnd,3);
        SetWindowLongA(hwnd,0x10,(LONG)local_900);
        BringWindowToTop(hwnd);
      }
      if (DAT_006fe444 == 2) {
        UVar10 = GetDoubleClickTime();
        Sleep(UVar10);
        BVar8 = PeekMessageA(&local_91c,hwnd,0x206,0x206,0);
        if (BVar8 != 0) {
          local_8fc = 0;
        }
      }
      if ((local_c != -1) && (local_10 == -1)) {
        local_8fc = 0;
      }
      if (local_8fc != 0) {
        local_8f8.x = (uint)lParam & 0xffff;
        local_8f8.y = (uint)lParam >> 0x10;
        ClientToScreen(hwnd,&local_8f8);
        iVar5 = GetSystemMetrics(0xd);
        local_8f8.x = local_8f8.x + iVar5;
        iVar5 = local_8f8.y + 4;
        iVar13 = local_8f8.y + 5;
        local_8f8.y = iVar5;
        SetRect(&local_8f0,local_8f8.x,iVar5,local_8f8.x + 1,iVar13);
        TrackPopupMenu(DAT_00538db4,2,local_8f8.x,local_8f8.y,0,hwnd,(RECT *)0x0);
      }
      return 0;
    }
    if (uMsg == 0x205) {
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != DAT_0069e720) && (pHVar3 = GetParent(hwnd), pHVar3 != DAT_006fe400)) {
        local_920 = (HWND)GetWindowLongA(hwnd,0x10);
        SetWindowPos(hwnd,local_920,0,0,0,0,3);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      if ((local_c == -1) || (local_10 != -1)) {
        SendMessageA(hwnd,0x111,0x6e,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      LVar9 = Ai_Subsystem_004b5cbb(local_c,local_10);
      return LVar9;
    case 0x401:
      local_c = GetWindowLongA(hwnd,0);
      LVar2 = GetWindowLongA(hwnd,4);
      if (wParam != (LONG *)0x0) {
        *wParam = local_c;
        wParam[1] = LVar2;
      }
      return 0;
    case 0x402:
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      local_2e0 = wParam;
      if ((HWND)wParam != local_8) {
        if (wParam == (LONG *)0x0) {
          BringWindowToTop(hwnd);
        }
        local_8 = (HWND)local_2e0;
        SetWindowLongA(hwnd,8,(LONG)local_2e0);
      }
      return 0;
    case 0x403:
      LVar2 = GetWindowLongA(hwnd,8);
      return LVar2;
    case 0x404:
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_14 = (void *)GetWindowLongA(hwnd,0xc);
      if ((local_c != -1) && (local_10 == -1)) {
        return 0;
      }
      Ai_Subsystem_004b70fe(local_400,local_c,local_10);
      iVar5 = memcmp(local_14,local_400,0x120);
      return iVar5;
    case 0x432:
      BVar8 = IsWindowVisible(hwnd);
      if (BVar8 == 0) {
        return 0;
      }
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_14 = (void *)GetWindowLongA(hwnd,0xc);
      Ai_Subsystem_004b70fe(local_2bc,local_c,local_10);
      if ((local_c != -1) && (local_10 == -1)) {
        return 0;
      }
      iVar5 = FUN_0046adbc((int)local_14,(int)local_2bc);
      if (iVar5 == 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      else if ((DAT_006fe42c == 0) ||
              (iVar5 = FUN_0046b3e6((int)local_14,(int)local_2bc), iVar5 != 0)) {
        if (*(int *)((int)local_14 + 0x54) != local_268) {
          local_2c0 = Ai_Subsystem_004b5cbb(local_c,local_10);
          uVar6 = Ai_Subsystem_004b5de4(local_c,local_10);
          if ((uVar6 & 2) == 0) {
            if ((((DAT_006ff2dc == local_2c0) || (DAT_006ff2e8 == local_2c0)) ||
                (DAT_0068a694 == local_2c0)) ||
               (((DAT_00695e94 == local_2c0 || (DAT_006a2848 == local_2c0)) ||
                (DAT_0068a70c == local_2c0)))) {
              InvalidateRect(hwnd,(RECT *)0x0,0);
            }
            else if (local_2c0 != 0xffffffff) {
              local_2d4 = GetDC(hwnd);
              GDI_RealizeAndFlushPalette_Magic(local_2d4);
              GetClientRect(hwnd,&local_2d0);
              iVar5 = Ai_Subsystem_004b65bf(local_c,local_10);
              uVar6 = (uint)(iVar5 == local_c);
              iVar5 = Ai_Subsystem_004b673e(local_c,local_10);
              Palette_Subsystem_004a11fa
                        (local_2d4,&local_2d0.left,*(char **)(&DAT_006b3078 + local_2c0 * 0x98),
                         iVar5,uVar6);
              ReleaseDC(hwnd,local_2d4);
              *(int *)((int)local_14 + 0x54) = local_268;
            }
          }
          else {
            InvalidateRect(hwnd,(RECT *)0x0,0);
          }
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      local_104[0] = 0x20;
      local_104[1] = 0x400;
      local_104[2] = 0x40;
      local_104[3] = 0x80;
      local_104[4] = 0x100;
      local_104[5] = 0x200;
      local_104[6] = 1;
      local_104[7] = 2;
      local_104[8] = 4;
      local_104[9] = 8;
      local_104[10] = 0x10;
      local_104[0xb] = 0x800;
      local_104[0xc] = 0x1000;
      local_104[0xd] = 0x2000;
      local_104[0xe] = 0x4000;
      local_104[0xf] = 0x8000;
      local_104[0x10] = 0x10000;
      local_a0[0] = s_Flying_00524920;
      local_a0[1] = &DAT_0052492c;
      local_a0[2] = s_Banding_00524938;
      local_a0[3] = s_Trample_00524948;
      local_90 = s_First_strike_00524960;
      local_8c = s_Regenerates_0052497c;
      local_88 = s_Swampwalk_00524994;
      local_84 = s_Islandwalk_005249ac;
      local_80 = s_Forestwalk_005249c4;
      local_7c = s_Mountainwalk_005249e0;
      local_78 = s_Plainswalk_005249fc;
      local_74 = s_Protection_from_black_00524a20;
      local_70 = s_Protection_from_blue_00524a50;
      local_6c = s_Protection_from_green_00524a80;
      local_68 = s_Protection_from_red_00524aac;
      local_64 = s_Protection_from_white_00524ad8;
      local_60 = s_Protection_from_artifacts_00524b0c;
      local_ac = 0x11;
      local_c = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_3c = Ai_Subsystem_004b5cbb(local_c,local_10);
      local_114 = (uint)lParam & 0xffff;
      local_110 = (uint)lParam >> 0x10;
      if ((local_c == -1) || (local_10 != -1)) {
        local_10c = 0;
        GetClientRect(hwnd,&local_54);
        uVar1 = Ai_Subsystem_004b5de4(local_c,local_10);
        uVar6 = local_114;
        if ((uVar1 & 2) != 0) {
          local_19c = local_114;
          local_114 = local_110;
          local_110 = local_54.bottom - uVar6;
        }
        local_194 = Ai_Subsystem_004b6288(local_c,local_10);
        local_44 = -1;
        if (local_194 != 0) {
          local_108 = 0;
          while ((local_108 < local_ac && (local_44 == -1))) {
            Palette_Subsystem_004a0f97(&local_190,local_104[local_108],&local_54.left,local_194);
            pt.y = local_110;
            pt.x = local_114;
            BVar8 = PtInRect(&local_190,pt);
            if (BVar8 != 0) {
              local_44 = local_108;
            }
            local_108 = local_108 + 1;
          }
        }
        local_58 = Ai_Subsystem_004b5a46(local_c,local_10);
        Ai_Subsystem_004b5ab8(local_c,local_10,&local_5c,local_104 + 0x11,&local_118);
        Palette_Subsystem_004a080b(&local_bc,&local_54.left,local_58);
        local_18 = Ai_Subsystem_004b67ab(local_c,local_10);
        iVar5 = Ai_Subsystem_004b682f(local_c,local_10);
        local_198 = (uint)(iVar5 == 0);
        local_40 = Ai_Subsystem_004b5bdd(local_c,local_10);
        Palette_Subsystem_004a0392(&local_38,&local_54.left);
        local_11c = Ai_Subsystem_004b6cc8(local_c,local_10);
        Palette_Subsystem_004a2aa3(&local_28,&local_54.left);
        local_a4 = Ai_Subsystem_004b6eab(local_c,local_10);
        if ((((local_11c & 1) == 0) || ((local_11c & 2) == 0)) ||
           (pt_00.y = local_110, pt_00.x = local_114, BVar8 = PtInRect(&local_28,pt_00), BVar8 == 0)
           ) {
          if (local_44 == -1) {
            if ((local_40 < 1) ||
               (pt_01.y = local_110, pt_01.x = local_114, BVar8 = PtInRect(&local_38,pt_01),
               BVar8 == 0)) {
              if ((local_58 < 1) ||
                 (pt_02.y = local_110, pt_02.x = local_114, BVar8 = PtInRect(&local_bc,pt_02),
                 BVar8 == 0)) {
                if ((((int)(local_118 + local_104[0x11] + local_5c) < 1) ||
                    ((int)local_110 <= (local_54.bottom * 0x23) / 100)) ||
                   ((local_54.bottom * 0x3e) / 100 <= (int)local_110)) {
                  iVar5 = Ai_Subsystem_004b65bf(local_c,local_10);
                  if ((iVar5 == local_c) || ((local_54.bottom * 0xc) / 100 <= (int)local_110)) {
                    if (((local_18 == 0) && (local_198 == 0)) ||
                       (((((int)local_114 <= (local_54.right * 5) / 100 ||
                          ((local_54.right * 0x5f) / 100 <= (int)local_114)) ||
                         ((int)local_110 <= (local_54.bottom * 0xf) / 100)) ||
                        ((local_54.bottom * 0x5f) / 100 <= (int)local_110)))) {
                      if (((local_a4 == 2) && ((local_54.right * 5) / 100 < (int)local_114)) &&
                         (((int)local_114 < (local_54.right * 0x5f) / 100 &&
                          (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                           ((int)local_110 < (local_54.bottom * 0x5f) / 100)))))) {
                        strcpy(local_180,s_Dying_00524ba4);
                        local_10c = 1;
                      }
                      else {
                        uVar6 = Ai_Subsystem_004b613b(local_c,local_10);
                        if ((((uVar6 & 2) != 0) &&
                            (((uVar6 = Ai_Subsystem_004b5de4(local_c,local_10), (uVar6 & 1) != 0 &&
                              ((local_54.right * 5) / 100 < (int)local_114)) &&
                             ((int)local_114 < (local_54.right * 0x5f) / 100)))) &&
                           (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                            ((int)local_110 < (local_54.bottom * 0x5f) / 100)))) {
                          strcpy(local_180,s_Summoning_sickness_00524bac);
                          local_10c = 1;
                        }
                      }
                    }
                    else {
                      local_180[0] = '\0';
                      if (local_18 != 0) {
                        strcat(local_180,s_Is_a_target_00524b80);
                      }
                      if ((local_18 != 0) && (local_198 != 0)) {
                        strcat(local_180,&DAT_00524b8c);
                      }
                      if (local_198 != 0) {
                        strcat(local_180,s_Can_t_target_this_00524b90);
                      }
                      local_10c = 1;
                    }
                  }
                  else {
                    strcpy(local_180,s_Card_is_not_controlled_by_owner_00524b60);
                    local_10c = 1;
                  }
                }
                else {
                  local_a8 = (local_54.right - local_54.left) / 3;
                  if ((int)local_114 < local_54.left + local_a8) {
                    FUN_0046b887(local_180,1,local_118);
                  }
                  else if ((int)local_114 < local_a8 * 2 + local_54.left) {
                    FUN_0046b887(local_180,2,local_104[0x11]);
                  }
                  else {
                    FUN_0046b887(local_180,3,local_5c);
                  }
                  local_10c = 1;
                }
              }
              else {
                FUN_0046b4db(local_180,local_3c,local_58);
                local_10c = 1;
              }
            }
            else {
              sprintf(local_180,s_Damage___d_00524b54,local_40);
              local_10c = 1;
            }
          }
          else {
            strcpy(local_180,local_a0[local_44]);
            local_10c = 1;
          }
        }
        else {
          strcpy(local_180,s_This_card_will_untap_00524b3c);
          local_10c = 1;
        }
      }
      else {
        local_10c = 1;
        strcpy(local_180,s_Damage_to_player_00524b28);
      }
      if (local_10c != 0) {
        strcpy((char *)wParam,local_180);
      }
      if (DAT_006fe444 == 2) {
        return local_10c;
      }
      SendMessageA(hwnd,0x111,0x6e,0);
      return local_10c;
    }
  }
  LVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar9;
}



