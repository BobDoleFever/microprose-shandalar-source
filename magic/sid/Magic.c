/*
 * sid/Magic.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 83
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Magic_ScanCards
 * Purpose: Scan all active cards on the battlefield for triggers and state changes.
 * Procedure:
 * 1. Increment the scan depth counter and check that depth is less than 10.
 * 2. Count active card slots for both players.
 * 3. Call the card script action callback for each active card.
 * 4. Update status flags and trigger pending continuous effects.
 */
/*
 * Decompiled function: Magic_ScanCards
 * Entry Point: 00473f06
 * Size: 864 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_ScanCards(int color_mask)

{
  int arg2;
  int uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  uVar1 = DAT_0067bdb0;
  _DAT_006b1584 = color_mask;
  _DAT_00627a0c = _DAT_00627a0c + 1;
  DAT_006fe3f8 = DAT_006fe3f8 + 1;
  if (9 < DAT_006fe3f8) {
    assert(s___nScan<10_00525d00,s_G__NewMagic_sources_sid_Magic_c_00525ce0,0x7f5);
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
      if (*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) != -1) {
        (&g_PlayerActiveCardCount)[local_8] = local_10 + 1;
      }
    }
  }
  for (local_14 = 0; (local_14 < 500 && (*(int *)(&DAT_007006e0 + local_14 * 4) != -1));
      local_14 = local_14 + 1) {
    local_8 = *(int *)(&DAT_007006e0 + local_14 * 4);
    arg2 = *(int *)(&DAT_006a5750 + local_14 * 4);
    if (((*(int *)(&g_CardSlot_DisplayIndex + local_8 * 0x5b20 + arg2 * 0x120) == local_14) &&
        (*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120) != -1)) &&
       ((((&g_CardSlot_Flags)[local_8 * 0x5b20 + arg2 * 0x120] & 2) != 0 ||
        (((&g_CardSlot_Flags)[local_8 * 0x5b20 + arg2 * 0x120] & 0x20) != 0)))) {
      _DAT_0068a704 = local_8 * 0x80 + arg2;
      if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120) < 0) ||
         (g_MasterCardCount + 0x10 < *(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120))
         ) {
        Engine_ReportFatalError(s_ScanCard_error_00525d0c);
      }
      else {
        (**(code **)(&DAT_0051aec8 +
                    *(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120) * 0x34))
                  (local_8,arg2,color_mask);
        if ((((color_mask == 0x15) && (g_DefendingPlayer == local_8)) &&
            (((byte)*(int *)(&g_CardSlot_Flags + local_8 * 0x5b20 + arg2 * 0x120) & 0x14) ==
             4)) && (iVar2 = FUN_004728c3(local_8,arg2), iVar2 == 0)) {
          *(uint *)(&g_CardSlot_Flags + local_8 * 0x5b20 + arg2 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_8 * 0x5b20 + arg2 * 0x120) | 0x10;
          DAT_006ff2d4 = 0xffffffff;
          Magic_BroadcastCardEvent(local_8,arg2,0x81);
        }
      }
    }
  }
  if ((color_mask == 0x15) && (g_DefendingPlayer == local_8)) {
    FUN_00472fae();
  }
  DAT_006fe3f8 = DAT_006fe3f8 + -1;
  if (DAT_0068a64c != -1) {
    (**(code **)(&DAT_0051aec8 + DAT_0068a64c * 0x34))(0,0x4e,color_mask);
  }
  DAT_0067bdb0 = uVar1;
  return;
}



/*
 * Magic_TriggerCardEvent
 * Purpose: Execute a card script function with the specified event code.
 * Procedure:
 * 1. Read the card definition pointer from the master table.
 * 2. Execute the script event handler.
 * 3. Return the result code to the calling function.
 */
/*
 * Decompiled function: Magic_TriggerCardEvent
 * Entry Point: 00474266
 * Size: 291 bytes
 */


int Magic_TriggerCardEvent(int color_mask,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) == -1) {
    iVar2 = 0;
  }
  else {
    Magic_PushEventContext();
    uVar1 = DAT_006a4920;
    g_CardEventResult = 0;
    g_EventSourcePlayer = color_mask;
    g_EventSourceSlot = arg_2;
    g_EventTargetPlayer = arg_4;
    g_EventTargetSlot = arg_5;
    iVar2 = (**(code **)(&DAT_0051aec8 +
                        *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) * 0x34))
                      (color_mask,arg_2,arg_3);
    if ((((iVar2 != 99) && ((g_PlayerHandCardCount & 0x224) != 0)) &&
        ((arg_3 == 0x74 || (arg_3 == 0x73)))) &&
       (iVar3 = Magic_IsManaSource(color_mask,arg_2), iVar3 == 0)) {
      DAT_006a4920 = uVar1;
      Magic_PopEventContext();
      return 0;
    }
    DAT_006b2e38 = g_CardEventResult;
    Magic_PopEventContext();
  }
  return iVar2;
}



/*
 * Magic_IsManaSource
 * Purpose: Resolve the top spell or activated ability on the resolution stack.
 * Procedure:
 * 1. Check if the spell stack contains active entries.
 * 2. Execute the top spell effect function.
 * 3. Move the card to the graveyard or battlefield.
 * 4. Decrement the stack depth counter.
 */
/*
 * Decompiled function: Magic_IsManaSource
 * Entry Point: 00474389
 * Size: 159 bytes
 */


bool Magic_IsManaSource(int x,int arg2)

{
  bool bVar1;
  
  if (((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + x * 0x5b20) * 0x34] & 0x10)
      == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = ((&DAT_0051aed0)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + x * 0x5b20) * 0x34] & 1
            ) == 0;
  }
  return bVar1;
}



/*
 * Magic_PushEventContext
 * Purpose: Save the current card-event context onto a stack (32 frames, depth in
 *   DAT_0052577c) so events can nest. Saves g_EventSourcePlayer, g_EventSourceSlot,
 *   g_EventCardId, g_EventCardColorMask, g_EventTargetPlayer, g_EventTargetSlot and g_CardEventResult.
 * Verified against the running game; the original label "pay mana cost" was wrong.
 *   See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Magic_PushEventContext
 * Entry Point: 00474428
 * Size: 182 bytes
 */


void Magic_PushEventContext(void)

{
  if (DAT_0052577c < 0x20) {
    *(int *)(&DAT_00676e40 + DAT_0052577c * 0x28) = g_EventSourcePlayer;
    *(int *)(&DAT_00676e44 + DAT_0052577c * 0x28) = g_EventSourceSlot;
    *(int *)(&DAT_00676e48 + DAT_0052577c * 0x28) = g_EventCardId;
    *(int *)(&DAT_00676e4c + DAT_0052577c * 0x28) = g_EventCardColorMask;
    *(int *)(&DAT_00676e50 + DAT_0052577c * 0x28) = g_EventTargetPlayer;
    *(int *)(&DAT_00676e54 + DAT_0052577c * 0x28) = g_EventTargetSlot;
    *(int *)(&DAT_00676e58 + DAT_0052577c * 0x28) = g_CardEventResult;
    DAT_0052577c = DAT_0052577c + 1;
  }
  return;
}



/*
 * Magic_PopEventContext
 * Purpose: Restore the card-event context saved by Magic_PushEventContext (drop one
 *   stack frame and reload the seven event globals).
 * Verified against the running game (98 pops, restoring outer contexts); the original label
 *   "tap card for mana" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Magic_PopEventContext
 * Entry Point: 004744de
 * Size: 170 bytes
 */


void Magic_PopEventContext(void)

{
  if (0 < DAT_0052577c) {
    DAT_0052577c = DAT_0052577c + -1;
  }
  g_EventSourcePlayer = *(int *)(&DAT_00676e40 + DAT_0052577c * 0x28);
  g_EventSourceSlot = *(int *)(&DAT_00676e44 + DAT_0052577c * 0x28);
  g_EventCardId = *(int *)(&DAT_00676e48 + DAT_0052577c * 0x28);
  g_EventCardColorMask = *(int *)(&DAT_00676e4c + DAT_0052577c * 0x28);
  g_EventTargetPlayer = *(int *)(&DAT_00676e50 + DAT_0052577c * 0x28);
  g_EventTargetSlot = *(int *)(&DAT_00676e54 + DAT_0052577c * 0x28);
  g_CardEventResult = *(int *)(&DAT_00676e58 + DAT_0052577c * 0x28);
  return;
}



/*
 * Magic_UntapTurnPhase
 * Purpose: Execute the Untap step for the active player.
 * Procedure:
 * 1. Iterate through all cards controlled by the active player.
 * 2. Clear the STATUS_TAPPED flag on cards that can untap.
 * 3. Remove summoning sickness from creatures played on previous turns.
 */
/*
 * Decompiled function: Magic_UntapTurnPhase
 * Entry Point: 00474588
 * Size: 945 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_UntapTurnPhase(void)

{
  byte color_mask;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  
  for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
    *(int *)(&DAT_006ff6b0 + local_10 * 4) = 0;
    *(int *)(&DAT_006ff690 + local_10 * 4) = *(int *)(&DAT_006ff6b0 + local_10 * 4);
    *(int *)(&DAT_006b2fc0 + local_10 * 4) = *(int *)(&DAT_006ff690 + local_10 * 4);
    *(int *)(&DAT_006b2fa0 + local_10 * 4) = *(int *)(&DAT_006b2fc0 + local_10 * 4);
    *(int *)(&DAT_006b2e60 + local_10 * 4) = *(int *)(&DAT_006b2fa0 + local_10 * 4);
    *(int *)(&DAT_006b2e40 + local_10 * 4) = *(int *)(&DAT_006b2e60 + local_10 * 4);
  }
  DAT_006a282c = 0;
  DAT_006a2828 = 0;
  DAT_00695e04 = 0;
  _DAT_00695e00 = 0;
  DAT_006a4a14 = 0;
  _DAT_006a4a10 = 0;
  for (local_10 = 0; local_10 < 0x18; local_10 = local_10 + 1) {
    *(int *)(&DAT_006b3000 + local_10 * 4) = 0;
  }
  _DAT_006b3000 = g_PlayerCreatureCount;
  DAT_006b3004 = DAT_006a4a04;
  for (local_c = 0; local_c < 2; local_c = local_c + 1) {
    (&DAT_006b3008)[local_c] = 0;
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_c]; local_10 = local_10 + 1)
    {
      iVar1 = Card_IsTapped(local_c, local_10);
      if (iVar1 == 0) {
        if (*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) != -1) {
          (&DAT_006b3008)[local_c] = (&DAT_006b3008)[local_c] + 1;
        }
      }
      else {
        iVar1 = *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20);
        color_mask = (&DAT_0051aebe)[iVar1 * 0x34];
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0) {
          iVar2 = Magic_QueryCardAttribute(local_c, local_10, 0x32, 0xffffffff);
          iVar3 = Magic_QueryCardAttribute(local_c,local_10,0x33,0xffffffff);
          iVar4 = Card_ColorMaskToColorIndex(color_mask);
          *(int *)(&DAT_006b2e40 + iVar4 * 4 + local_c * 0x20) =
               *(int *)(&DAT_006b2e40 + iVar4 * 4 + local_c * 0x20) + iVar2;
          *(int *)(&DAT_006b2e5c + local_c * 0x20) =
               *(int *)(&DAT_006b2e5c + local_c * 0x20) + iVar2;
          iVar2 = Card_ColorMaskToColorIndex(color_mask);
          *(int *)(&DAT_006b2fa0 + iVar2 * 4 + local_c * 0x20) =
               *(int *)(&DAT_006b2fa0 + iVar2 * 4 + local_c * 0x20) + iVar3;
          *(int *)(&DAT_006b2fbc + local_c * 0x20) =
               *(int *)(&DAT_006b2fbc + local_c * 0x20) + iVar3;
          *(int *)(&DAT_006a4a10 + local_c * 4) = *(int *)(&DAT_006a4a10 + local_c * 4) + 1;
        }
        (&DAT_006a2828)[local_c] =
             (&DAT_006a2828)[local_c] | (uint)(byte)(&g_MasterCardColorTable)[iVar1 * 0x34];
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0) {
          *(int *)(&DAT_006b3010 + local_c * 4) = *(int *)(&DAT_006b3010 + local_c * 4) + 1;
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) != 0) {
          (&DAT_006b3018)[local_c] = (&DAT_006b3018)[local_c] + 1;
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 4) != 0) {
          *(int *)(&DAT_006b3020 + local_c * 4) = *(int *)(&DAT_006b3020 + local_c * 4) + 1;
        }
      }
    }
    for (local_10 = 0; local_10 < 500; local_10 = local_10 + 1) {
      if (*(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) != -1) {
        *(uint *)(&DAT_00695e00 + local_c * 4) =
             *(uint *)(&DAT_00695e00 + local_c * 4) |
             (uint)(byte)(&g_MasterCardColorTable)
                         [*(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) * 0x34];
      }
    }
  }
  return;
}



/*
 * Decompiled function: Magic_CheckTurnTriggers
 * Entry Point: 00474939
 * Size: 50 bytes
 */


void Magic_CheckTurnTriggers(int x,int arg2)

{
  if (g_IsAiThinking != 1) {
    Ai_Subsystem_004cc3c4(x,arg2);
  }
  g_ActivePlayer = 0;
  return;
}



/*
 * Duel_PlaySoundById
 * Purpose: Play one duel sound effect by id (0x00 to 0x2f). Ids below 0x14 index the table of
 *   20 sound names (artifact, buried, draw, enchant, ... untap); higher ids use further tables.
 * Procedure:
 * 1. If the id is not loaded yet, evict a least-recently-used track and load its .wav.
 * 2. Start playback of the track.
 * Verified on the live game (called with id 2, draw.wav, from the draw function). The original
 * label "Upkeep phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Duel_PlaySoundById
 * Entry Point: 0047496b
 * Size: 788 bytes
 */


/* WARNING: Type propagation algorithm not settling */

int Duel_PlaySoundById(int sound_id)

{
  int uVar1;
  int iVar2;
  char local_134 [264];
  int local_2c;
  int local_28 [8];
  uint local_8;
  
  local_28[1] = 300;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = sound_id;
  local_8 = 0;
  if (g_IsAiThinking == 1) {
    uVar1 = 0;
  }
  else {
    local_28[0] = sound_id;
    if (sound_id < 0x14) {
      PlaySnd(sound_id,0);
    }
    else if (sound_id < 0x1d) {
      iVar2 = IsSndLoaded(sound_id,local_28);
      if (iVar2 == 0) {
        local_2c = GetLRUSnd(local_28,0x14,0x16);
        if (local_2c == 0) {
          CloseSndTrack(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        strcpy(local_134,&DAT_00696910);
        strcat(local_134,&DAT_00525d1c);
        strcat(local_134,(&PTR_s_artifact_wav_00525788)[sound_id]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
      }
      PlaySnd(local_28[0],0);
    }
    else if (sound_id < 0x22) {
      iVar2 = IsSndLoaded(sound_id,local_28);
      if (iVar2 == 0) {
        local_2c = GetLRUSnd(local_28,0x1d,0x1d);
        if (local_2c == 0) {
          CloseSndTrack(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        strcpy(local_134,&DAT_00696910);
        strcat(local_134,&DAT_00525d20);
        strcat(local_134,(&PTR_s_buried_wav_0052578c)[sound_id]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
      }
      PlaySnd(local_28[0],0);
    }
    else {
      if (0x2f < sound_id) {
        return 0;
      }
      local_28[1] = 400;
      iVar2 = IsSndLoaded(sound_id,local_28);
      if (iVar2 == 0) {
        if (sound_id == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          local_8 = local_8 | 4;
        }
        strcpy(local_134,&DAT_00696910);
        strcat(local_134,&DAT_00525d24);
        strcat(local_134,(&PTR_s_draw_wav_00525790)[sound_id]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
        PlaySnd(local_28[0],local_28 + 1);
      }
      else {
        if (sound_id == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          local_8 = local_8 | 4;
        }
        PlaySnd(local_28[0],local_28 + 1);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Duel_PreloadSoundEffects
 * Purpose: Preload the 20 duel sound effects (artifact, buried, draw, enchant, endphase,
 *   endturn, instant, interupt, five mana colours plus grey, lifeloss, sacrfice, sorcery,
 *   summon, tap, untap).
 * Procedure:
 * 1. Stop any sound track that is playing.
 * 2. For each of the 20 names, build the path from the duel sounds directory and register
 *    the .wav.
 * Verified on the live game: runs once when a duel starts. The original label "draw card
 * phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Duel_PreloadSoundEffects
 * Entry Point: 00474c7f
 * Size: 143 bytes
 */


void Duel_PreloadSoundEffects(void)

{
  char local_130 [264];
  int local_28;
  uint local_8;
  
  local_8 = local_8 & 0xfffffffb;
  StopSndTrack();
  for (local_28 = 0; local_28 < 0x14; local_28 = local_28 + 1) {
    strcpy(local_130,&DAT_00696910);
    strcat(local_130,&DAT_00525d28);
    strcat(local_130,(&PTR_s_artifact_wav_00525788)[local_28]);
    InitSndTrack(local_130,local_28,0);
  }
  return;
}



/*
 * Decompiled function: FUN_00474d0e
 * Entry Point: 00474d0e
 * Size: 16 bytes
 */


void FUN_00474d0e(void)

{
  StopSndTrack();
  return;
}



/*
 * Decompiled function: Magic_ClearSpellStack
 * Entry Point: 00474d1e
 * Size: 44 bytes
 */


int Magic_ClearSpellStack(void)

{
  g_SpellStackCount = 0;
  g_SpellStackObjects = 0xffffffff;
  return 0;
}



/*
 * Decompiled function: FUN_00474d4a
 * Entry Point: 00474d4a
 * Size: 51 bytes
 */


int FUN_00474d4a(void)

{
  int uVar1;
  
  if (g_SpellStackCount == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(int *)(&DAT_006ff4cc + g_SpellStackCount * 4);
  }
  return uVar1;
}



/*
 * Magic_MainTurnPhase
 * Purpose: Execute the Main phase.
 * Procedure:
 * 1. Grant priority to the active player.
 * 2. Process land drops and spell casts.
 */
/*
 * Decompiled function: Magic_MainTurnPhase
 * Entry Point: 00474d7d
 * Size: 1114 bytes
 */


int Magic_MainTurnPhase(int color_mask)

{
  int iVar1;
  int iVar2;
  int uVar3;
  int uVar4;
  int uVar5;
  int iVar6;
  
  iVar6 = g_SpellStackCount + -1;
  iVar1 = (&g_SpellStackObjects)[iVar6 * 2];
  iVar2 = *(int *)(&DAT_006fecc4 + iVar6 * 8);
  if (*(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + iVar1 * 0x5b20) == g_StackObjectCardId) {
    uVar3 = *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20);
    uVar4 = *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20);
    uVar5 = *(int *)(&g_CardSlot_DisplayIndex + iVar2 * 0x120 + iVar1 * 0x5b20);
    memcpy(&g_ActiveCardsInPlay + iVar1 * 0x5b20 + iVar2 * 0x120,
           &g_ActiveCardsInPlay +
           *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120 +
           *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20,0x120);
    *(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + iVar1 * 0x5b20) = g_StackObjectCardId;
    *(int *)(&DAT_006a5f80 + iVar2 * 0x120 + iVar1 * 0x5b20) = 0;
    (&DAT_006a5f50)[iVar2 * 0x120 + iVar1 * 0x5b20] = 0;
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + iVar1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + iVar1 * 0x5b20) | 2;
    *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar4;
    *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar3;
    *(int *)(&g_CardSlot_DisplayIndex + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar5;
    if (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120) != -1)
    {
      *(int *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + iVar1 * 0x5b20) =
           *(int *)
            (&g_CardSlot_CardId +
            *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
            *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120);
    }
    if ((*(int *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + iVar1 * 0x5b20) < DAT_006ff2e0) ||
       (DAT_006ff2e0 + 0x1d <= *(int *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + iVar1 * 0x5b20))) {
      *(int *)(&DAT_006a5f74 + iVar2 * 0x120 + iVar1 * 0x5b20) =
           *(int *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_ActiveCardsInPlay +
                    *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
                    *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120) *
            0x34);
    }
  }
  if (g_IsAiThinking != 1) {
    *(int *)(&DAT_00695d70 + iVar6 * 4) = color_mask;
  }
  *(int *)(&DAT_006ff390 + iVar6 * 8) =
       (int)(char)(&g_CardSlot_Toughness)[iVar2 * 0x120 + iVar1 * 0x5b20];
  *(int *)(&DAT_006ff394 + iVar6 * 8) =
       *(int *)(&g_CardSlot_OriginalCardId + iVar2 * 0x120 + iVar1 * 0x5b20);
  return 0;
}



/*
 * Magic_PushSpellStack
 * Purpose: Push one card event (a spell, ability or trigger) onto the spell stack, a table of up to
 *   32 entries counted by g_SpellStackCount. Each entry packs the card id, the event code (bits 16-23)
 *   and the target slot (bits 24-31) into g_SpellStackEntries and records the owner and slot in
 *   g_SpellStackObjects. For cards with an id of 5 or more it also copies the card into a free slot as a
 *   stand-in object marked with g_StackObjectCardId.
 * Static evidence only; the original label "combat phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Magic_PushSpellStack
 * Entry Point: 004751d7
 * Size: 1062 bytes
 */


int Magic_PushSpellStack(int color_mask,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int uVar1;
  bool bVar2;
  int local_c;
  
  if (g_SpellStackCount < 0x20) {
    *(int *)(&g_SpellStackEntries + g_SpellStackCount * 4) =
         *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20);
    *(uint *)(&g_SpellStackEntries + g_SpellStackCount * 4) =
         *(uint *)(&g_SpellStackEntries + g_SpellStackCount * 4) | arg_3 << 0x10;
    *(uint *)(&g_SpellStackEntries + g_SpellStackCount * 4) =
         *(uint *)(&g_SpellStackEntries + g_SpellStackCount * 4) | arg_4 << 0x18;
    if (((arg_3 == 0x71) || (arg_3 == 0x7e)) ||
       (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) < 5)) {
      local_c = arg_2;
      bVar2 = true;
    }
    else {
      local_c = Pic_Subsystem_00451291(color_mask,g_StackObjectCardId);
      if (local_c == -1) {
        bVar2 = false;
      }
      else {
        uVar1 = *(int *)(&g_CardSlot_DisplayIndex + color_mask * 0x5b20 + local_c * 0x120);
        memcpy(&g_ActiveCardsInPlay + local_c * 0x120 + color_mask * 0x5b20,
               &g_ActiveCardsInPlay + color_mask * 0x5b20 + arg_2 * 0x120,0x120);
        *(int *)(&g_CardSlot_CardId + color_mask * 0x5b20 + local_c * 0x120) = g_StackObjectCardId;
        *(int *)(&DAT_006a5f80 + color_mask * 0x5b20 + local_c * 0x120) = 0;
        (&DAT_006a5f50)[color_mask * 0x5b20 + local_c * 0x120] = 0;
        if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) == -1) {
          *(int *)(&g_ActiveCardsInPlay + color_mask * 0x5b20 + local_c * 0x120) =
               *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + color_mask * 0x5b20);
        }
        else {
          *(int *)(&g_ActiveCardsInPlay + color_mask * 0x5b20 + local_c * 0x120) =
               *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20);
        }
        *(int *)(&DAT_006a5f74 + color_mask * 0x5b20 + local_c * 0x120) =
             *(int *)(&DAT_006a5f74 + arg_2 * 0x120 + color_mask * 0x5b20);
        *(uint *)(&g_CardSlot_Flags + color_mask * 0x5b20 + local_c * 0x120) =
             *(uint *)(&g_CardSlot_Flags + color_mask * 0x5b20 + local_c * 0x120) | 2;
        *(int *)(&g_CardSlot_TapState + color_mask * 0x5b20 + local_c * 0x120) = color_mask;
        *(int *)(&g_CardSlot_SicknessState + color_mask * 0x5b20 + local_c * 0x120) = arg_2;
        *(int *)(&g_CardSlot_DisplayIndex + color_mask * 0x5b20 + local_c * 0x120) = uVar1;
        bVar2 = true;
      }
    }
    if (bVar2) {
      (&g_SpellStackObjects)[g_SpellStackCount * 2] = color_mask;
      *(int *)(&DAT_006fecc4 + g_SpellStackCount * 8) = local_c;
      *(int *)(&DAT_006ff390 + g_SpellStackCount * 8) =
           (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + color_mask * 0x5b20];
      *(int *)(&DAT_006ff394 + g_SpellStackCount * 8) =
           *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + color_mask * 0x5b20);
      if (g_CurrentStepCode == -1) {
        *(int *)(&DAT_00696880 + g_SpellStackCount * 4) = g_ScWillyScore;
      }
      else {
        *(int *)(&DAT_00696880 + g_SpellStackCount * 4) = g_CurrentStepCode;
      }
      if (g_IsAiThinking != 1) {
        *(int *)(&DAT_00695d70 + g_SpellStackCount * 4) = arg_5;
      }
      g_SpellStackCount = g_SpellStackCount + 1;
      (&g_SpellStackObjects)[g_SpellStackCount * 2] = 0xffffffff;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004755fd
 * Entry Point: 004755fd
 * Size: 164 bytes
 */


int FUN_004755fd(void)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0; local_c < g_SpellStackCount; local_c = local_c + 1) {
    iVar1 = (&g_SpellStackObjects)[local_c * 2];
    *(int *)(&DAT_006ff390 + local_c * 8) =
         (int)(char)(&g_CardSlot_Toughness)
                    [iVar1 * 0x5b20 + *(int *)(&DAT_006fecc4 + local_c * 8) * 0x120];
    *(int *)(&DAT_006ff394 + local_c * 8) =
         *(int *)
          (&g_CardSlot_OriginalCardId +
          iVar1 * 0x5b20 + *(int *)(&DAT_006fecc4 + local_c * 8) * 0x120);
  }
  return 0;
}



/*
 * Magic_ResolveTopSpell
 * Purpose: Pop the top entry of the spell stack and run it: the card's own handler through
 *   Magic_TriggerCardEvent, or the in-step broadcast for event 0x7e, with extra handling for stand-in
 *   objects.
 * Static evidence only; the original label "end of turn" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Magic_ResolveTopSpell
 * Entry Point: 004756a1
 * Size: 1295 bytes
 */


int Magic_ResolveTopSpell(void)

{
  int color_mask;
  int arg_2;
  int local_c;
  
  if (0 < g_SpellStackCount) {
    g_SpellStackCount = g_SpellStackCount + -1;
    color_mask = (&g_SpellStackObjects)[g_SpellStackCount * 2];
    arg_2 = *(int *)(&DAT_006fecc4 + g_SpellStackCount * 8);
    local_c = *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20);
    if (g_StackObjectCardId == local_c) {
      local_c = *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + color_mask * 0x5b20);
    }
    if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) != -1) {
      if ((char)((uint)*(int *)(&g_SpellStackEntries + g_SpellStackCount * 4) >> 0x10) == '~') {
        Magic_BroadcastCardEventInStep
                  (color_mask,arg_2,*(uint *)(&g_SpellStackEntries + g_SpellStackCount * 4) >> 0x10 & 0xff,
                   *(int *)(&g_SpellStackEntries + g_SpellStackCount * 4) >> 0x18);
      }
      else if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + color_mask * 0x5b20] & 8) == 0) {
        if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + color_mask * 0x5b20] & 0x80) == 0) {
          Magic_TriggerCardEvent
                    (color_mask,arg_2,*(uint *)(&g_SpellStackEntries + g_SpellStackCount * 4) >> 0x10 & 0xff,
                     1 - color_mask,0xffffffff);
        }
        else {
          if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + color_mask * 0x5b20] & 0x40) != 0) {
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) *
                          0x120 + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) *
                                  0x5b20) & 0xffffffef;
            Magic_TriggerCardEvent
                      (*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20),
                       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20),0x83,
                       1 - color_mask,0xffffffff);
          }
          *(uint *)(&g_CardSlot_SpecialState +
                   *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20) =
               *(uint *)(&g_CardSlot_SpecialState +
                        *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20)
               & 0xffffff7f;
        }
      }
      else {
        if (((((&DAT_006a6045)[arg_2 * 0x120 + color_mask * 0x5b20] & 2) == 0) &&
            (Magic_TriggerCardEvent(color_mask,arg_2,0x86,1 - color_mask,0xffffffff),
            *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) != -1)) &&
           (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + color_mask * 0x5b20] & 2) != 0)) {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20),
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20),1);
        }
        *(uint *)(&g_CardSlot_SpecialState +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20) &
             0xfffffdf7;
        *(uint *)(&g_CardSlot_SpecialState +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_SpecialState +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + color_mask * 0x5b20) * 0x5b20) | 4;
      }
      if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) == g_StackObjectCardId) {
        Pic_Subsystem_0044867e(color_mask,arg_2,4);
      }
    }
    (&g_SpellStackObjects)[g_SpellStackCount * 2] = 0xffffffff;
    FUN_00472fae();
    if (((((&DAT_0051aed1)[local_c * 0x34] & 0x10) == 0) || (((byte)g_PlayerHandCardCount & 2) != 0)
        ) && ((DAT_006fd3f0 < 2 && (((g_PlayerHandCardCount._1_1_ & 2) == 0 || (g_SpellStackCount == 0)))
              ))) {
      Pic_Subsystem_004475a4(g_DefendingPlayer);
      Pic_Subsystem_004488a0();
    }
  }
  return 0;
}



/*
 * Magic_DropTopSpell
 * Purpose: Pop the top entry of the spell stack without running it, clearing its stand-in card slot.
 * Static evidence only; the original label "discard to hand size" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
/*
 * Decompiled function: Magic_DropTopSpell
 * Entry Point: 00475bb0
 * Size: 177 bytes
 */


int Magic_DropTopSpell(void)

{
  if (0 < g_SpellStackCount) {
    g_SpellStackCount = g_SpellStackCount + -1;
    if (g_StackObjectCardId ==
        *(int *)(&g_CardSlot_CardId +
                *(int *)(&DAT_006fecc4 + g_SpellStackCount * 8) * 0x120 +
                (&g_SpellStackObjects)[g_SpellStackCount * 2] * 0x5b20)) {
      *(int *)
       (&g_CardSlot_CardId +
       *(int *)(&DAT_006fecc4 + g_SpellStackCount * 8) * 0x120 +
       (&g_SpellStackObjects)[g_SpellStackCount * 2] * 0x5b20) = 0xffffffff;
    }
    (&g_SpellStackObjects)[g_SpellStackCount * 2] = 0xffffffff;
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_00475c61
 * Entry Point: 00475c61
 * Size: 41 bytes
 */


void Mem_AllocOrFree_00475c61(void)

{
  DAT_006b2d24 = 0;
  DAT_006ff684 = 0;
  DAT_0052211c = 0;
  return;
}



/*
 * Decompiled function: FUN_00475c8a
 * Entry Point: 00475c8a
 * Size: 218 bytes
 */


int FUN_00475c8a(int x,int arg_2,char *arg_3,int arg_4)

{
  int uVar1;
  int iVar2;
  int uVar3;
  
  uVar1 = DAT_0063ee1c;
  if (((g_SpellStackCount == 0) && (iVar2 = FUN_00505c74(), iVar2 != 0)) && (x != -2)) {
    DAT_0063ee1c = 1;
  }
  do {
    DAT_006ff380 = 0;
    uVar3 = Magic_CleanupPhase(x,arg_2,arg_3,arg_4);
    if ((DAT_006ff380 == 0) || (0 < g_SpellStackCount)) break;
  } while (g_IsAiThinking != 1);
  DAT_0063ee1c = uVar1;
  if (g_SpellStackCount == 0) {
    DAT_0063ee1c = 0;
    *(uint *)(&DAT_00696740 + g_DefendingPlayer * 0x98 + g_ScWillyScore * 4) =
         *(uint *)(&DAT_00696740 + g_DefendingPlayer * 0x98 + g_ScWillyScore * 4) & 0xfffffffd;
  }
  return uVar3;
}



/*
 * Magic_CleanupPhase
 * Purpose: Remove temporary damage from creatures and reset until-end-of-turn effects.
 */
/*
 * Decompiled function: Magic_CleanupPhase
 * Entry Point: 00475d64
 * Size: 1185 bytes
 */


int Magic_CleanupPhase(int x,int y,char *str_3,int arg_4)

{
  int uVar1;
  int uVar2;
  int uVar3;
  int iVar4;
  int local_98;
  int local_94;
  char local_8c [128];
  int local_c;
  int local_8;
  
  uVar3 = DAT_006a4920;
  uVar2 = DAT_00695ec4;
  uVar1 = DAT_006808b0;
  local_c = g_CurrentStepCode;
  g_CurrentStepCode = 0xffffffff;
  DAT_006ff684 = DAT_006ff684 + 1;
  if (DAT_006ff684 == 1) {
    DAT_006b2d24 = 0;
  }
  else if ((((DAT_006b2d24 < DAT_006ff684) && (y != 0x8e)) && (y != 0x70)) && (y != 0xd3)) {
    DAT_006b2d24 = DAT_006ff684;
  }
  local_94 = 0;
  DAT_00695ec4 = arg_4;
  local_8 = DAT_00525850;
  if ((x == -2) && (iVar4 = FUN_00505c74(), iVar4 == 0)) {
    DAT_00525850 = 1;
  }
  else {
    DAT_00525850 = 0;
  }
  iVar4 = FUN_00505c74();
  if ((iVar4 == 0) &&
     ((*(int *)(&DAT_00696740 + g_DefendingPlayer * 0x98 + y * 4) != 0 ||
      ((g_DefendingPlayer == DAT_00627a84 && (y == DAT_00627a88)))))) {
    DAT_006808b0 = 1;
  }
  else {
    DAT_006808b0 = 0;
  }
  if ((-1 < x) && (DAT_006808b0 == 0)) {
LAB_0047615d:
    DAT_006ff684 = DAT_006ff684 + -1;
    if ((DAT_006ff684 == 0) && (DAT_0063edc8 = 0xffffffff, DAT_006fd3f0 == 0)) {
      DAT_0063ee1c = 0;
      DAT_0063edc4 = 0;
    }
    DAT_0063ee70 = 0xffffffff;
    DAT_006808b0 = uVar1;
    DAT_00525850 = local_8;
    DAT_006a4920 = uVar3;
    g_CurrentStepCode = local_c;
    DAT_00695ec4 = uVar2;
    if (local_94 != 0) {
      DAT_00633434 = 0;
    }
    return local_94;
  }
  strcpy(local_8c,str_3);
  if ((g_ScWillyScore == 4) && (DAT_006ff684 == 1)) {
    DAT_0063edc0 = g_DefendingPlayer;
    FUN_00476b0e();
  }
  do {
    do {
      if (g_DefendingPlayer == 0) {
        DAT_0068a67c = 1;
      }
      else if (x < 0) {
        DAT_0068a67c = 2;
      }
      else {
        DAT_0068a67c = 0;
      }
      if (DAT_006ff684 < 2) {
        DAT_0063ee70 = 0xffffffff;
      }
      g_ActivePlayer = 0;
      DAT_006a4920 = 0;
      local_98 = Pic_Subsystem_004458b0(g_DefendingPlayer,local_8c);
      if (local_98 != 0) {
        DAT_006ff380 = 1;
      }
      if (((g_DefendingPlayer == g_CurrentTurnPhase) && (local_98 != 0)) && (g_IsAiThinking != 1)) {
        local_94 = 1;
      }
      if ((DAT_006ff684 < DAT_006b2d24) && (-1 < g_SpellStackCount)) {
        local_98 = 0;
      }
    } while ((local_98 != 0) || (((DAT_006a4920 & 1) != 0 && (DAT_006ff684 == 1))));
    if ((g_ScWillyScore == 4) && (DAT_006ff684 == 1)) {
      DAT_0063edc0 = 1 - g_DefendingPlayer;
      FUN_00476b0e();
    }
    while( true ) {
      if (g_DefendingPlayer == 0) {
        if (x < 0) {
          DAT_0068a67c = 2;
        }
        else {
          DAT_0068a67c = 0;
        }
      }
      else {
        DAT_0068a67c = 1;
      }
      if (DAT_006ff684 < 2) {
        DAT_0063ee70 = 0xffffffff;
      }
      g_ActivePlayer = 0;
      DAT_006a4920 = 0;
      if (((DAT_006ff684 < DAT_006b2d24) && (-1 < g_SpellStackCount)) ||
         (iVar4 = Pic_Subsystem_004458b0(1 - g_DefendingPlayer,local_8c), iVar4 == 0))
      goto LAB_0047615d;
      DAT_006ff380 = 1;
      if (g_IsAiThinking != 1) break;
      if ((g_DefendingPlayer != g_CurrentTurnPhase) &&
         (((DAT_006a4920 & 1) == 0 || (DAT_006ff684 != 1)))) goto LAB_0047615d;
    }
  } while( true );
}



/*
 * Decompiled function: FUN_00476205
 * Entry Point: 00476205
 * Size: 74 bytes
 */


int FUN_00476205(int x,int arg_2,char *arg_3,int arg_4)

{
  Magic_RunTurnStep(x,arg_2,arg_3,arg_4);
  Magic_RunTurnStep(1 - x,arg_2,arg_3,arg_4);
  return 1;
}



/*
 * Decompiled function: Magic_RunTurnStep
 * Entry Point: 0047624f
 * Size: 495 bytes
 */


int Magic_RunTurnStep(int x,int arg_2,char *str_3,int height)

{
  uint uVar1;
  int uVar2;
  int uVar3;
  int uVar4;
  int uVar5;
  int iVar6;
  int local_18;
  
  uVar5 = DAT_006a4b5c;
  uVar4 = DAT_00695f0c;
  uVar3 = DAT_00695ec4;
  uVar2 = DAT_0068a67c;
  uVar1 = DAT_0063ee70;
  DAT_006fd3f0 = DAT_006fd3f0 + 1;
  DAT_00695ec4 = arg_2;
  DAT_006a4b5c = x;
  do {
    if (x == 0) {
      DAT_0068a67c = 1;
    }
    else {
      DAT_0068a67c = 2;
    }
    g_CurrentStepCode = arg_2;
    if (height == 0) {
      DAT_0063ee70 = 0;
    }
    else {
      DAT_0063ee70 = 0x30;
    }
    g_ActivePlayer = 0;
    DAT_0068a714 = 0;
    DAT_00695f0c = 0;
    iVar6 = Pic_Subsystem_004458b0(x,str_3);
    DAT_0063edc8 = uVar1 & 0x30;
  } while (((DAT_00695f0c & (-(uint)(iVar6 == 0) & 0xfffffffe) + 6) != 0) ||
          ((height != 0 && (iVar6 != 0))));
  g_CurrentStepCode = 0xffffffff;
  DAT_006fd3f0 = DAT_006fd3f0 + -1;
  DAT_0063ee70 = uVar1;
  DAT_0068a67c = uVar2;
  if (DAT_006fd3f0 == 0) {
    for (x = 0; x < 2; x = x + 1) {
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[x]; local_18 = local_18 + 1) {
        *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + x * 0x5b20) & 0xfffffeff;
      }
    }
    if (DAT_006ff684 == 0) {
      DAT_0063ee1c = 0;
      DAT_0063edc4 = 0;
    }
  }
  DAT_00695f0c = uVar4;
  DAT_006a4b5c = uVar5;
  DAT_00695ec4 = uVar3;
  return 0;
}



/*
 * Decompiled function: FUN_0047643e
 * Entry Point: 0047643e
 * Size: 68 bytes
 */


int FUN_0047643e(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    *(int *)(&DAT_007006e0 + local_8 * 4) = 0xffffffff;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00476482
 * Entry Point: 00476482
 * Size: 142 bytes
 */


int FUN_00476482(int x,int arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_007006e0 + local_8 * 4) == -1) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_007006e0 + local_8 * 4) = x;
  *(int *)(&DAT_006a5750 + local_8 * 4) = arg2;
  *(int *)(&g_CardSlot_DisplayIndex + arg2 * 0x120 + x * 0x5b20) = local_8;
  return local_8;
}



/*
 * Decompiled function: FUN_00476510
 * Entry Point: 00476510
 * Size: 357 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476510(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    while ((*(int *)(&DAT_007006e0 + local_8 * 4) != -1 &&
           ((local_c = local_8,
            *(int *)(&g_CardSlot_CardId +
                    *(int *)(&DAT_007006e0 + local_8 * 4) * 0x5b20 +
                    *(int *)(&DAT_006a5750 + local_8 * 4) * 0x120) == -1 ||
            (*(int *)(&g_CardSlot_DisplayIndex +
                     *(int *)(&DAT_007006e0 + local_8 * 4) * 0x5b20 +
                     *(int *)(&DAT_006a5750 + local_8 * 4) * 0x120) != local_8))))) {
      while (local_c = local_c + 1, local_c < 500) {
        *(int *)(&DAT_007006dc + local_c * 4) = *(int *)(&DAT_007006e0 + local_c * 4);
        *(int *)(&DAT_006a574c + local_c * 4) = *(int *)(&DAT_006a5750 + local_c * 4);
        if (*(int *)(&g_CardSlot_DisplayIndex +
                    *(int *)(&DAT_006a5750 + local_c * 4) * 0x120 +
                    *(int *)(&DAT_007006e0 + local_c * 4) * 0x5b20) == local_c) {
          *(int *)(&g_CardSlot_DisplayIndex +
                  *(int *)(&DAT_007006e0 + local_c * 4) * 0x5b20 +
                  *(int *)(&DAT_006a5750 + local_c * 4) * 0x120) =
               *(int *)(&g_CardSlot_DisplayIndex +
                       *(int *)(&DAT_007006e0 + local_c * 4) * 0x5b20 +
                       *(int *)(&DAT_006a5750 + local_c * 4) * 0x120) + -1;
        }
      }
      _DAT_00700eac = 0xffffffff;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476675
 * Entry Point: 00476675
 * Size: 377 bytes
 */


int FUN_00476675(int x,int arg2)

{
  int uVar1;
  int iVar2;
  int local_c;
  uint local_8;
  
  if (((&g_CardSlot_Flags)[x * 0x5b20 + arg2 * 0x120] & 0x10) == 0) {
    uVar1 = 0;
  }
  else {
    local_c = 0;
    for (local_8 = 1; (int)local_8 < 7; local_8 = local_8 + 1) {
      if ((&DAT_006a603c)[local_8 + arg2 * 0x120 + x * 0x5b20] != '\0') {
        iVar2 = Font_DrawString(x,local_8,
                             (int)(char)(&DAT_006a603c)[local_8 + arg2 * 0x120 + x * 0x5b20]);
        if (iVar2 == 0) {
          return 0;
        }
        local_c = local_c + (char)(&DAT_006a603c)[local_8 + arg2 * 0x120 + x * 0x5b20];
      }
    }
    iVar2 = Font_DrawString(x,7,(char)(&DAT_006a603c)[x * 0x5b20 + arg2 * 0x120] + local_c);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      Magic_TriggerCardEvent(x,arg2,0x88,1 - x,0xffffffff);
      if (DAT_006b2e38 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004767ee
 * Entry Point: 004767ee
 * Size: 470 bytes
 */


void FUN_004767ee(int color_mask)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_10;
  
  iVar2 = 1 - color_mask;
  for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[color_mask]; local_10 = local_10 + 1) {
    if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + color_mask * 0x5b20) != -1) &&
       (((byte)*(int *)(&g_CardSlot_Flags + local_10 * 0x120 + color_mask * 0x5b20) & 6) == 6)) {
      bVar1 = false;
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[iVar2]; local_18 = local_18 + 1)
      {
        if ((*(int *)(&g_CardSlot_CardId + iVar2 * 0x5b20 + local_18 * 0x120) != -1) &&
           ((char)(&g_CardSlot_ColorMask)[iVar2 * 0x5b20 + local_18 * 0x120] == local_10)) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[color_mask];
            local_18 = local_18 + 1) {
          if ((local_18 == local_10) ||
             (((char)(&g_CardSlot_ColorMask)[local_18 * 0x120 + color_mask * 0x5b20] == local_10 &&
              (((byte)*(int *)(&g_CardSlot_Flags + local_18 * 0x120 + color_mask * 0x5b20) & 6) ==
               6)))) {
            *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + color_mask * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + local_18 * 0x120 + color_mask * 0x5b20) | 0x200;
          }
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004769c4
 * Entry Point: 004769c4
 * Size: 183 bytes
 */


int FUN_004769c4(int x,int arg2)

{
  int uVar1;
  int local_8;
  
  if ((x == -1) || (arg2 == -1)) {
    uVar1 = 0;
  }
  else {
    local_8 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + x * 0x5b20);
    if (g_StackObjectCardId == local_8) {
      local_8 = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + x * 0x5b20);
    }
    if (local_8 == -1) {
      uVar1 = 0;
    }
    else if (((&DAT_0051aed2)[local_8 * 0x34] & 2) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_00476a80
 * Entry Point: 00476a80
 * Size: 142 bytes
 */


void FUN_00476a80(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      iVar1 = Card_IsTapped(local_8,local_c);
      if (iVar1 != 0) {
        *(int *)(&g_CardSlot_SpecialState + local_c * 0x120 + local_8 * 0x5b20) = 0;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476b0e
 * Entry Point: 00476b0e
 * Size: 361 bytes
 */


void FUN_00476b0e(void)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if (((&g_CardSlot_SpecialState)[local_10 * 0x120 + local_8 * 0x5b20] & 4) == 0) {
        iVar1 = Card_IsTapped(local_8,local_10);
        if (iVar1 != 0) {
          for (local_c = 0; local_c < 7; local_c = local_c + 1) {
            (&DAT_006a603c)[local_c + local_8 * 0x5b20 + local_10 * 0x120] = 0;
            (&DAT_006a6048)[local_c + local_8 * 0x5b20 + local_10 * 0x120] =
                 (&DAT_006a603c)[local_c + local_8 * 0x5b20 + local_10 * 0x120];
          }
          *(int *)(&g_CardSlot_SpecialState + local_10 * 0x120 + local_8 * 0x5b20) = 0;
          Magic_BroadcastCardEvent(local_8,local_10,0x85);
          Magic_BroadcastCardEvent(local_8,local_10,0x84);
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476c77
 * Entry Point: 00476c77
 * Size: 475 bytes
 */


uint FUN_00476c77(int x,int y,int width,int height)

{
  uint uVar1;
  uint local_8;
  
  local_8 = 0;
  if (((&DAT_006a604f)[y * 0x120 + x * 0x5b20] == '\0') &&
     ((&DAT_006a604f)[height * 0x120 + width * 0x5b20] == '\0')) {
    uVar1 = 0;
  }
  else {
    if ((((&DAT_006a604f)[y * 0x120 + x * 0x5b20] & (&DAT_006a5f4d)[height * 0x120 + width * 0x5b20]
         & 0x3f) != 0) &&
       ((local_8 = 1,
        (&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20) * 0x34] ==
        '\0' && (((&DAT_006a604f)[y * 0x120 + x * 0x5b20] & 0x80) == 0)))) {
      local_8 = 0;
    }
    uVar1 = local_8;
    if (((((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20] &
           (&DAT_006a604f)[height * 0x120 + width * 0x5b20] & 0x3f) != 0) &&
        (uVar1 = local_8 | 2,
        (&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] == '\0')) &&
       (((&DAT_006a604f)[height * 0x120 + width * 0x5b20] & 0x80) == 0)) {
      uVar1 = local_8;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Prompts_Load_00476e60
 * Entry Point: 00476e60
 * Size: 604 bytes
 */


int Prompts_Load_00476e60(LPCSTR filepath)

{
  ATOM AVar1;
  LOGFONTA *pLVar2;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  DAT_00695ecc = 2;
  DAT_0068a710 = 1;
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_Register_WINBK_TellUser_004771fa;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(2);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = filepath;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_TellUser_pic_00525d2c);
  DAT_00538e40 = Pic_Load_00423833(local_138);
  Pic_Subsystem_00424500(s_prompts_txt_00525d50,s_BUTTONLABELS_00525d40);
  strcpy(&DAT_006b2d70,&g_OverworldGoldAmount);
  strcpy(&DAT_0068a680,&DAT_0069f84a);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_TellUser_00525d5c,0);
  DAT_00538e14 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_TellUser_00525d68,0);
  DAT_00538e08 = CreateFontIndirectA(pLVar2);
  DAT_00538e18 = CreatePen(0,0,0x10000cb);
  DAT_00538e44 = CreatePen(0,0,0x10000cd);
  DAT_00538e20 = CreatePen(0,0,0x10000cf);
  DAT_00538e0c = 0x10000b6;
  DAT_00538e10 = 0x10000c9;
  DAT_00538e2c = CreateSolidBrush(0x10000cd);
  DAT_00538e24 = CreatePen(0,0,0x10000cb);
  DAT_00538e1c = CreatePen(0,0,0x10000cf);
  DAT_00538e28 = DAT_00538e0c;
  if (((((DAT_00538e14 == (HFONT)0x0) || (DAT_00538e08 == (HFONT)0x0)) ||
       (DAT_00538e18 == (HPEN)0x0)) || ((DAT_00538e44 == (HPEN)0x0 || (DAT_00538e20 == (HPEN)0x0))))
     || ((DAT_00538e2c == (HBRUSH)0x0 ||
         ((DAT_00538e24 == (HPEN)0x0 || (DAT_00538e1c == (HPEN)0x0)))))) {
    local_30 = 0;
  }
  return local_30;
}



/*
 * Decompiled function: FUN_004770bc
 * Entry Point: 004770bc
 * Size: 318 bytes
 */


void FUN_004770bc(void)

{
  if (DAT_00538e40 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00538e40);
  }
  if (DAT_00538e14 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e14);
  }
  if (DAT_00538e08 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e08);
  }
  if (DAT_00538e18 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e18);
  }
  if (DAT_00538e44 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e44);
  }
  if (DAT_00538e20 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e20);
  }
  if (DAT_00538e2c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e2c);
  }
  if (DAT_00538e24 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e24);
  }
  if (DAT_00538e1c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e1c);
  }
  DAT_00538e40 = (HANDLE)0x0;
  DAT_00538e14 = (HGDIOBJ)0x0;
  DAT_00538e18 = (HGDIOBJ)0x0;
  DAT_00538e44 = (HGDIOBJ)0x0;
  DAT_00538e20 = (HGDIOBJ)0x0;
  DAT_00538e2c = (HGDIOBJ)0x0;
  DAT_00538e24 = (HGDIOBJ)0x0;
  DAT_00538e1c = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_Register_WINBK_TellUser_004771fa
 * Entry Point: 004771fa
 * Size: 2920 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UI_Register_WINBK_TellUser_004771fa(HWND hwnd,uint y,LPSTR str_3,int height)

{
  BOOL BVar1;
  int cHeight;
  HBRUSH hbr;
  HGDIOBJ pvVar2;
  uint uVar3;
  char local_254 [264];
  HDC local_14c;
  tagPAINTSTRUCT local_148;
  CHAR local_108 [200];
  tagRECT local_40;
  LPCSTR local_30;
  int local_2c;
  HGDIOBJ local_28;
  HFONT local_24;
  tagRECT local_20;
  uint local_10;
  int local_c;
  LPSTR local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_8 = (LPSTR)GetWindowLongA(hwnd,0);
      local_14c = BeginPaint(hwnd,&local_148);
      if (local_14c != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_14c);
        GetClientRect(hwnd,&local_40);
        if (DAT_00538e40 == (HANDLE)0x0) {
          strcpy(local_254,&DAT_006b2e90);
          strcat(local_254,s__WINBK_TellUser_pic_00525da0);
          DAT_00538e40 = (HANDLE)Pic_Load_00423833(local_254);
        }
        if (DAT_00538e40 == (HANDLE)0x0) {
          hbr = GetStockObject(1);
          FillRect(local_14c,&local_40,hbr);
        }
        else {
          FUN_004f3d11(local_14c,&local_40.left,DAT_00538e40);
        }
        SelectObject(local_14c,DAT_00538e18);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,0);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,0,local_40.bottom + -1);
        SelectObject(local_14c,DAT_00538e44);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,1);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,1,local_40.bottom + -2);
        SelectObject(local_14c,DAT_00538e20);
        MoveToEx(local_14c,2,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,2);
        MoveToEx(local_14c,2,2,(LPPOINT)0x0);
        LineTo(local_14c,2,local_40.bottom + -4);
        pvVar2 = GetStockObject(7);
        SelectObject(local_14c,pvVar2);
        MoveToEx(local_14c,3,3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,3);
        MoveToEx(local_14c,3,3,(LPPOINT)0x0);
        LineTo(local_14c,3,local_40.bottom + -4);
        pvVar2 = GetStockObject(7);
        SelectObject(local_14c,pvVar2);
        MoveToEx(local_14c,0,local_40.bottom + -1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right,local_40.bottom + -1);
        MoveToEx(local_14c,local_40.right + -1,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom);
        SelectObject(local_14c,DAT_00538e20);
        MoveToEx(local_14c,1,local_40.bottom + -2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom + -2);
        MoveToEx(local_14c,local_40.right + -2,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -1);
        SelectObject(local_14c,DAT_00538e44);
        MoveToEx(local_14c,2,local_40.bottom + -3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -3);
        MoveToEx(local_14c,local_40.right + -3,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -2);
        SelectObject(local_14c,DAT_00538e18);
        MoveToEx(local_14c,2,local_40.bottom + -4,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -4);
        MoveToEx(local_14c,local_40.right + -4,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,local_40.bottom + -3);
        GetWindowTextA(hwnd,local_108,200);
        SetBkMode(local_14c,1);
        FUN_0047820f(hwnd,local_14c,&local_40.left);
        DPtoLP(local_14c,(LPPOINT)&local_40,2);
        OffsetRect(&local_40,2,2);
        SetTextColor(local_14c,DAT_00538e10);
        Palette_Subsystem_0049e5bc(local_14c,&local_40.left,local_108,0);
        OffsetRect(&local_40,-2,-2);
        SetTextColor(local_14c,DAT_00538e0c);
        Palette_Subsystem_0049e5bc(local_14c,&local_40.left,local_108,1);
        EndPaint(hwnd,&local_148);
      }
      return 0;
    }
    if (y == 1) {
      local_8 = DAT_00538e14;
      SetWindowLongA(hwnd,0,(LONG)DAT_00538e14);
      DAT_00676e38 = CreateWindowExA(0,s_BUTTON_00525d78,&DAT_00525d74,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x1,g_AppHInstance,(LPVOID)0x0);
      DAT_00676e34 = CreateWindowExA(0,s_BUTTON_00525d84,&DAT_00525d80,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x2,g_AppHInstance,(LPVOID)0x0);
      if ((DAT_00676e38 != (HWND)0x0) && (DAT_00676e34 != (HWND)0x0)) {
        GetClientRect(hwnd,&local_20);
        cHeight = (local_20.bottom * 2) / 100;
        if (cHeight < 0xd) {
          cHeight = 0xc;
        }
        local_24 = CreateFontA(cHeight,0,0,0,400,0,0,0,1,0,0,0,0,s_MS_Sans_Serif_00525d8c);
        SendMessageA(DAT_00676e38,0x30,(WPARAM)local_24,0);
        SendMessageA(DAT_00676e34,0x30,(WPARAM)local_24,0);
        return 0;
      }
      return 0xffffffff;
    }
    if (y == 2) {
      local_28 = (HGDIOBJ)SendMessageA(DAT_00676e38,0x31,0,0);
      SendMessageA(DAT_00676e38,0x30,0,0);
      SendMessageA(DAT_00676e34,0x30,0,0);
      DeleteObject(local_28);
      return 0;
    }
  }
  else if (y < 0x2c) {
    if (y == 0x2b) {
      local_2c = height;
      *(uint *)(height + 0x10) = *(uint *)(height + 0x10) & 0xffffffef;
      FUN_004f5107(height,DAT_00538e2c,DAT_00538e18,DAT_00538e20,DAT_00538e28,0);
      if (*(int *)(local_2c + 4) == 1) {
        local_30 = &DAT_006b2d70;
      }
      else if (*(int *)(local_2c + 4) == 2) {
        local_30 = &DAT_0068a680;
      }
      else {
        local_30 = &DAT_00525d9c;
      }
      SetMapMode(*(HDC *)(local_2c + 0x18),8);
      SetWindowExtEx(*(HDC *)(local_2c + 0x18),*(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c)
                     ,0x18,(LPSIZE)0x0);
      SetViewportExtEx(*(HDC *)(local_2c + 0x18),
                       *(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c),
                       *(int *)(local_2c + 0x28) - *(int *)(local_2c + 0x20),(LPSIZE)0x0);
      SelectObject(*(HDC *)(local_2c + 0x18),DAT_00538e08);
      SetTextColor(*(HDC *)(local_2c + 0x18),DAT_00538e28);
      if ((*(byte *)(local_2c + 0x10) & 1) != 0) {
        OffsetRect((LPRECT)(local_2c + 0x1c),2,2);
      }
      DPtoLP(*(HDC *)(local_2c + 0x18),(LPPOINT)(local_2c + 0x1c),2);
      DrawTextA(*(HDC *)(local_2c + 0x18),local_30,-1,(LPRECT)(local_2c + 0x1c),0x25);
      return 1;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      if (((uint)str_3 & 0xffff) == 1) {
        SendMessageA(hwnd,0x401,1,0);
      }
      else if (((uint)str_3 & 0xffff) == 2) {
        SendMessageA(hwnd,0x401,2,0);
      }
      return 0;
    }
    if (y == 0x30) {
      local_8 = str_3;
      if (str_3 == (LPSTR)0x0) {
        local_8 = DAT_00538e14;
      }
      SetWindowLongA(hwnd,0,(LONG)local_8);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x31) {
      uVar3 = GetWindowLongA(hwnd,0);
      return uVar3;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      uVar3 = GDI_RealizePaletteTree_Magic(hwnd,y,(HWND)str_3,height);
      return uVar3;
    }
    if (y == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
  }
  else {
    if (y == 0x401) {
      if ((DAT_006b1578 != 0) &&
         ((BVar1 = IsWindowVisible(DAT_00676e38), BVar1 != 0 ||
          (BVar1 = IsWindowVisible(DAT_00676e34), BVar1 != 0)))) {
        if (str_3 == (LPSTR)0x0) {
          BVar1 = IsWindowVisible(DAT_00676e34);
          if (BVar1 == 0) {
            local_c = 0xffffffff;
          }
          else {
            local_c = 0xfffffffe;
          }
        }
        else if (str_3 == (LPSTR)0x2) {
          local_c = 0xfffffffe;
        }
        else {
          local_c = 0xffffffff;
        }
        DAT_00627a84 = 0xffffffff;
        DAT_00627a88 = 0xffffffff;
        DAT_00627864 = 0;
        _DAT_00538e30 = 0xfffffffe;
        _DAT_00538e34 = 0xffffffff;
        _DAT_00538e38 = local_c;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538e30);
      }
      return 0;
    }
    if (y == 0x402) {
      if (str_3 != (LPSTR)0x0) {
        GetWindowTextA(hwnd,str_3,200);
      }
      local_10 = 0;
      BVar1 = IsWindowVisible(DAT_00676e38);
      if (BVar1 != 0) {
        local_10 = local_10 | 1;
      }
      BVar1 = IsWindowVisible(DAT_00676e34);
      if (BVar1 == 0) {
        return local_10;
      }
      return local_10 | 2;
    }
    if (y == 0x403) {
      FUN_00478163(hwnd);
      return 0;
    }
  }
  uVar3 = DefWindowProcA(hwnd,y,(WPARAM)str_3,height);
  return uVar3;
}



/*
 * Decompiled function: FUN_00477d73
 * Entry Point: 00477d73
 * Size: 1008 bytes
 */


void FUN_00477d73(HWND hwnd,char *str_2,uint arg_3)

{
  size_t sVar1;
  HDC hdc;
  tagSIZE *psizl;
  tagRECT local_74;
  HDC local_64;
  tagRECT local_60;
  tagSIZE local_50;
  int local_48;
  int local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  local_48 = 4;
  local_20 = 4;
  local_2c = 7;
  if (str_2 == (char *)0x0) {
LAB_00477daf:
    ShowWindow(hwnd,0);
  }
  else {
    sVar1 = strlen(str_2);
    if (sVar1 == 0) goto LAB_00477daf;
  }
  if ((arg_3 == 0) || ((arg_3 & 1) == 0)) {
    ShowWindow(DAT_00676e38,0);
  }
  if ((arg_3 == 0) || ((arg_3 & 2) == 0)) {
    ShowWindow(DAT_00676e34,0);
  }
  local_30 = 0;
  local_64 = GetDC(hwnd);
  GetClientRect(hwnd,&local_60);
  local_18 = (local_60.bottom - local_60.top) + local_20 * -2;
  FUN_0047820f(hwnd,local_64,&local_60.left);
  psizl = &local_50;
  sVar1 = strlen(&DAT_006b2d70);
  GetTextExtentPoint32A(local_64,&DAT_006b2d70,sVar1,psizl);
  local_44 = local_50.cx + local_18 / 2;
  local_60.right = 2000;
  local_24 = Palette_Subsystem_0049e53b(local_64,(int)&local_60,(int)str_2);
  local_24 = local_24 & 0xffff;
  ReleaseDC(hwnd,local_64);
  if (((arg_3 & 2) != 0) || ((arg_3 & 1) != 0)) {
    SetWindowPos(DAT_00676e34,(HWND)0x0,0,0,local_44,local_18,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if ((arg_3 & 1) != 0) {
    SetWindowPos(DAT_00676e38,(HWND)0x0,0,0,local_44,local_18,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if (str_2 != (char *)0x0) {
    sVar1 = strlen(str_2);
    if (sVar1 != 0) {
      hdc = GetDC(hwnd);
      GetClientRect(hwnd,&local_74);
      FUN_0047820f(hwnd,hdc,&local_74.left);
      local_74.right = 2000;
      local_24 = Palette_Subsystem_0049e53b(hdc,(int)&local_74,(int)str_2);
      local_24 = local_24 & 0xffff;
      ReleaseDC(hwnd,hdc);
      SetWindowTextA(hwnd,str_2);
      goto LAB_00477fb6;
    }
  }
  local_24 = 0;
  SetWindowTextA(hwnd,&DAT_00525db4);
LAB_00477fb6:
  GetWindowRect(hwnd,&local_14);
  SetWindowPos(hwnd,(HWND)0x0,0,0,local_48 * 2 + local_30 + local_24 + 0x19,
               local_14.bottom - local_14.top,6);
  GetClientRect(hwnd,&local_14);
  local_1c = local_14.left + local_48;
  if ((arg_3 & 2) != 0) {
    GetWindowRect(DAT_00676e34,&local_40);
    local_1c = local_1c + local_2c;
    local_28 = (local_14.bottom - local_14.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_00676e34,(HWND)0x0,local_1c,local_28,0,0,5);
  }
  if ((arg_3 & 1) != 0) {
    GetWindowRect(DAT_00676e38,&local_40);
    local_1c = local_1c + (local_40.right - local_40.left) + local_2c;
    local_28 = (local_14.bottom - local_14.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_00676e38,(HWND)0x0,local_1c,local_28,0,0,5);
  }
  FUN_00478163(hwnd);
  InvalidateRect(DAT_00676e38,(RECT *)0x0,1);
  InvalidateRect(DAT_00676e34,(RECT *)0x0,1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  if ((arg_3 & 1) != 0) {
    ShowWindow(DAT_00676e38,5);
  }
  if ((arg_3 & 2) != 0) {
    ShowWindow(DAT_00676e34,5);
  }
  if (str_2 != (char *)0x0) {
    sVar1 = strlen(str_2);
    if (sVar1 != 0) {
      ShowWindow(hwnd,5);
    }
  }
  FUN_004f59f7();
  UpdateWindow(hwnd);
  return;
}



/*
 * Decompiled function: FUN_00478163
 * Entry Point: 00478163
 * Size: 172 bytes
 */


void FUN_00478163(HWND hwnd)

{
  BOOL BVar1;
  tagRECT local_24;
  tagRECT local_14;
  
  BVar1 = IsWindowVisible(DAT_006fe3fc);
  if (BVar1 == 0) {
    BVar1 = IsWindowVisible(DAT_006b3064);
    if (BVar1 == 0) {
      GetWindowRect(DAT_006b2e2c,&local_24);
      GetWindowRect(hwnd,&local_14);
      local_24.bottom = local_24.bottom - (local_14.bottom - local_14.top) / 2;
    }
    else {
      GetWindowRect(DAT_006b2e24,&local_24);
    }
  }
  else {
    GetWindowRect(DAT_006fe3fc,&local_24);
  }
  SetWindowPos(hwnd,(HWND)0x0,local_24.left,local_24.bottom,0,0,5);
  return;
}



/*
 * Decompiled function: FUN_0047820f
 * Entry Point: 0047820f
 * Size: 347 bytes
 */


void FUN_0047820f(HWND hwnd,HDC hdc,int *arg_3)

{
  BOOL BVar1;
  int iVar2;
  tagRECT local_50;
  HGDIOBJ local_40;
  tagTEXTMETRICA local_3c;
  
  local_40 = (HGDIOBJ)GetWindowLongA(hwnd,0);
  if (local_40 != (HGDIOBJ)0x0) {
    SelectObject(hdc,local_40);
  }
  GetTextMetricsA(hdc,&local_3c);
  *arg_3 = *arg_3 + local_3c.tmHeight / 2;
  arg_3[1] = arg_3[1] + 4;
  arg_3[3] = arg_3[3] + -3;
  BVar1 = IsWindowVisible(DAT_00676e38);
  if (BVar1 != 0) {
    GetWindowRect(DAT_00676e38,&local_50);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_50,2);
    iVar2 = local_50.right + local_3c.tmHeight / 2;
    if (iVar2 <= *arg_3) {
      iVar2 = *arg_3;
    }
    *arg_3 = iVar2;
  }
  BVar1 = IsWindowVisible(DAT_00676e34);
  if (BVar1 != 0) {
    GetWindowRect(DAT_00676e34,&local_50);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_50,2);
    iVar2 = local_50.right + local_3c.tmHeight / 2;
    if (iVar2 <= *arg_3) {
      iVar2 = *arg_3;
    }
    *arg_3 = iVar2;
  }
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,arg_3[2] - *arg_3,0x14,(LPSIZE)0x0);
  SetViewportExtEx(hdc,arg_3[2] - *arg_3,arg_3[3] - arg_3[1],(LPSIZE)0x0);
  return;
}



/*
 * Decompiled function: FUN_00478370
 * Entry Point: 00478370
 * Size: 743 bytes
 */


int FUN_00478370(WPARAM color_mask,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  int local_4c;
  HBITMAP local_48;
  HDC local_44;
  int local_40;
  int local_3c;
  void *local_38;
  void *local_34;
  BITMAPINFO local_30;
  
  local_40 = 1;
  if (color_mask == 0xffffffff) {
    local_40 = 0;
  }
  else {
    local_4c = FUN_0047865c(color_mask,y);
    if (local_4c != 0) {
      if ((*(int *)(local_4c + 8) == width) && (*(int *)(local_4c + 0xc) == height)) {
        return 1;
      }
      FUN_004788e0(color_mask,y);
    }
    if ((*(int *)(&DAT_006b30b4 + color_mask * 0x98) < 2) || (y == 0)) {
      sprintf(local_154,s__s__04d_WVL_00525dc8,&DAT_006808d0,color_mask);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_00525db8,&DAT_006808d0,color_mask,(int)(char)((char)y + '`'));
    }
    local_3c = Glue_Subsystem_004f15c0(1,local_154,0);
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      GDI_RealizeAndFlushPalette_Magic(local_44);
      FUN_005017f0((int *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)FUN_004f27c0(0,local_3c,width,height);
        if (local_34 == (void *)0x0) {
          local_40 = 0;
          DeleteObject(local_48);
        }
        else {
          if ((-width & 3U) == 0) {
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          memcpy(local_38,local_34,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      Glue_Util_004f1910(local_3c);
    }
    if (local_40 != 0) {
      if (0x13 < DAT_00680778) {
        FUN_004788e0(DAT_006fefc0,DAT_006fefc4);
      }
      *(HBITMAP *)(&DAT_006fefb0 + DAT_00680778 * 0x18) = local_48;
      *(void **)(&DAT_006fefb4 + DAT_00680778 * 0x18) = local_38;
      *(int *)(&DAT_006fefb8 + DAT_00680778 * 0x18) = width;
      *(int *)(&DAT_006fefbc + DAT_00680778 * 0x18) = height;
      (&DAT_006fefc0)[DAT_00680778 * 6] = color_mask;
      (&DAT_006fefc4)[DAT_00680778 * 6] = y;
      DAT_00680778 = DAT_00680778 + 1;
      PostMessageA(g_MainAppHwnd,0x434,color_mask,y);
    }
  }
  return local_40;
}



/*
 * Decompiled function: FUN_0047865c
 * Entry Point: 0047865c
 * Size: 151 bytes
 */


uint8_t * FUN_0047865c(int x,int arg2)

{
  uint8_t *local_c;
  int local_8;
  
  local_c = (uint8_t *)0x0;
  if (x == -1) {
    local_c = (uint8_t *)0x0;
  }
  else {
    local_8 = 0;
    while ((local_8 < DAT_00680778 && (local_c == (uint8_t *)0x0))) {
      if (((&DAT_006fefc0)[local_8 * 6] == x) && ((&DAT_006fefc4)[local_8 * 6] == arg2)) {
        local_c = &DAT_006fefb0 + local_8 * 0x18;
      }
      local_8 = local_8 + 1;
    }
  }
  return local_c;
}



/*
 * Decompiled function: FUN_004786f3
 * Entry Point: 004786f3
 * Size: 112 bytes
 */


int FUN_004786f3(int x,int y,int width,int height)

{
  int local_8;
  
  if (x == -1) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0047865c(x,y);
    if ((local_8 != 0) && ((*(int *)(local_8 + 8) != width || (*(int *)(local_8 + 0xc) != height))))
    {
      local_8 = 0;
    }
  }
  return local_8;
}



/*
 * Decompiled function: FUN_00478763
 * Entry Point: 00478763
 * Size: 236 bytes
 */


int FUN_00478763(HDC hdc,RECT *arg_2,int width,int height)

{
  bool bVar1;
  HBRUSH hbr;
  int local_14;
  int local_10;
  int local_c;
  
  if (width == -1) {
    local_14 = 0;
  }
  else {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_00680778 && (!bVar1))) {
      if (((&DAT_006fefc0)[local_c * 6] == width) && ((&DAT_006fefc4)[local_c * 6] == height)) {
        bVar1 = true;
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
    if (bVar1) {
      local_14 = FUN_004f3b5f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_006fefb0 + local_10 * 0x18));
    }
    else {
      local_14 = 0;
    }
    if (local_14 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  return local_14;
}



/*
 * Decompiled function: FUN_0047884f
 * Entry Point: 0047884f
 * Size: 135 bytes
 */


int FUN_0047884f(WPARAM color_mask,int y,int width,int height)

{
  int uVar1;
  int iVar2;
  
  if (color_mask == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_004786f3(color_mask,y,width,height);
    if (iVar2 == 0) {
      FUN_004788e0(color_mask,y);
      iVar2 = FUN_00478370(color_mask,y,width,height);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004788e0
 * Entry Point: 004788e0
 * Size: 374 bytes
 */


void FUN_004788e0(int x,int arg2)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  if (x != -1) {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_00680778 && (!bVar1))) {
      if (((&DAT_006fefc0)[local_c * 6] == x) && ((&DAT_006fefc4)[local_c * 6] == arg2)) {
        bVar1 = true;
        if (*(int *)(&DAT_006fefb0 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_006fefb0 + local_c * 0x18));
        }
        DAT_00680778 = DAT_00680778 + -1;
        for (local_10 = local_c; local_10 < DAT_00680778; local_10 = local_10 + 1) {
          *(int *)(&DAT_006fefb0 + local_10 * 0x18) =
               *(int *)(&DAT_006fefb0 + (local_10 * 3 + 3) * 8);
          *(int *)(&DAT_006fefb4 + local_10 * 0x18) =
               *(int *)(&DAT_006fefb4 + (local_10 * 3 + 3) * 8);
          *(int *)(&DAT_006fefb8 + local_10 * 0x18) =
               *(int *)(&DAT_006fefb8 + (local_10 * 3 + 3) * 8);
          *(int *)(&DAT_006fefbc + local_10 * 0x18) =
               *(int *)(&DAT_006fefbc + (local_10 * 3 + 3) * 8);
          (&DAT_006fefc0)[local_10 * 6] = (&DAT_006fefc0)[(local_10 * 3 + 3) * 2];
          (&DAT_006fefc4)[local_10 * 6] = (&DAT_006fefc4)[(local_10 * 3 + 3) * 2];
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00478a56
 * Entry Point: 00478a56
 * Size: 78 bytes
 */


void FUN_00478a56(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00680778; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_006fefb0 + local_8 * 0x18));
  }
  DAT_00680778 = 0;
  return;
}



/*
 * Decompiled function: FUN_00478aa4
 * Entry Point: 00478aa4
 * Size: 113 bytes
 */


int FUN_00478aa4(int color_mask,int arg_2,int arg_3)

{
  int iVar1;
  
  if (color_mask == -1) {
    iVar1 = 0;
  }
  else if ((arg_2 == -1) || (arg_3 == -1)) {
    iVar1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + color_mask * 0x98) < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = (arg_3 + arg_2) % *(int *)(&DAT_006b30b4 + color_mask * 0x98);
  }
  return iVar1;
}



/*
 * Decompiled function: UI_CreateWindow_00478b20
 * Entry Point: 00478b20
 * Size: 181 bytes
 */


byte UI_CreateWindow_00478b20(LPCSTR str_1)

{
  byte bVar1;
  ATOM AVar2;
  int iVar3;
  int *arg_3;
  BITMAPINFO *arg_4;
  int *arg_5;
  int *arg_6;
  int *arg_7;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_WndProc_00478c08;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x28;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar2 = RegisterClassA(&local_2c);
  arg_7 = (int *)0x0;
  arg_6 = (int *)0x0;
  arg_5 = &DAT_00538e58;
  arg_4 = (BITMAPINFO *)0x0;
  arg_3 = &DAT_00538e48;
  iVar3 = GetSystemMetrics(3);
  bVar1 = FUN_004f39a4(1000,iVar3 * 5,arg_3,arg_4,arg_5,arg_6,arg_7);
  return AVar2 != 0 & bVar1;
}



/*
 * Decompiled function: FUN_00478bd5
 * Entry Point: 00478bd5
 * Size: 51 bytes
 */


void FUN_00478bd5(void)

{
  FUN_004f3b2c(DAT_00538e48,DAT_00538e58);
  DAT_00538e48 = (HDC)0x0;
  DAT_00538e58 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_WndProc_00478c08
 * Entry Point: 00478c08
 * Size: 4271 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UI_WndProc_00478c08(HWND hwnd,uint uMsg,uint *wParam,LONG *lParam)

{
  short sVar1;
  LONG *pLVar2;
  LONG LVar3;
  uint *puVar4;
  HWND pHVar5;
  HWND pHVar6;
  int iVar7;
  HBRUSH pHVar8;
  uint uVar9;
  WPARAM WVar10;
  tagRECT *lpPoints;
  HDC wParam_00;
  UINT UVar11;
  LPARAM lParam_00;
  uint8_t local_174 [4];
  int local_170;
  int local_16c;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  tagRECT local_138;
  HDC local_128;
  uint8_t local_124 [4];
  int local_120;
  int local_11c;
  int local_10c;
  tagPAINTSTRUCT local_108;
  int local_c8;
  tagRECT local_c4;
  int local_b4;
  int local_b0;
  int local_ac;
  tagRECT local_a8;
  tagRECT local_98;
  tagRECT local_88;
  int local_78;
  int local_74;
  tagRECT local_70;
  int local_60;
  int local_5c;
  tagRECT local_58;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_3c;
  uint *local_2c;
  LONG *local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  int local_18;
  LONG local_14;
  uint *local_10;
  LONG *local_c;
  LONG *local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_2c = (uint *)GetWindowLongA(hwnd,0);
      local_14 = GetWindowLongA(hwnd,0x20);
      local_18 = GetWindowLongA(hwnd,0xc);
      local_1c = (uint *)GetWindowLongA(hwnd,0x10);
      local_8 = (LONG *)GetWindowLongA(hwnd,0x14);
      local_10 = (uint *)GetWindowLongA(hwnd,0x18);
      local_28 = (LONG *)GetWindowLongA(hwnd,0x1c);
      local_20 = (uint *)GetWindowLongA(hwnd,0x24);
      local_24 = (uint *)GetWindowLongA(hwnd,4);
      local_c = (LONG *)GetWindowLongA(hwnd,8);
      local_128 = BeginPaint(hwnd,&local_108);
      if (local_128 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_128);
        GetClientRect(hwnd,&local_88);
        local_b0 = SaveDC(DAT_00538e48);
        IntersectClipRect(DAT_00538e48,0,0,local_88.right,local_88.bottom);
        GetWindowRect(hwnd,&local_98);
        UVar11 = 2;
        lpPoints = &local_98;
        pHVar6 = GetParent(hwnd);
        MapWindowPoints((HWND)0x0,pHVar6,(LPPOINT)lpPoints,UVar11);
        OffsetViewportOrgEx(DAT_00538e48,-local_98.left,-local_98.top,(LPPOINT)0x0);
        lParam_00 = 0;
        UVar11 = 0x14;
        wParam_00 = DAT_00538e48;
        pHVar6 = GetParent(hwnd);
        SendMessageA(pHVar6,UVar11,(WPARAM)wParam_00,lParam_00);
        OffsetViewportOrgEx(DAT_00538e48,local_98.left,local_98.top,(LPPOINT)0x0);
        if (local_1c == (HANDLE)0x0) {
          pHVar8 = GetStockObject(2);
          FillRect(DAT_00538e48,&local_88,pHVar8);
        }
        else {
          CopyRect(&local_138,&local_88);
          GetObjectA(local_1c,0x18,local_124);
          local_138.left = -((int)local_2c % local_120);
          local_10c = local_88.bottom;
          local_ac = local_138.left;
          if (local_8 == (LONG *)0x0) {
            local_c8 = ((local_120 / 2) * local_88.bottom) / local_11c;
            local_13c = local_120 / 2;
            local_140 = local_11c;
          }
          else {
            local_c8 = (local_120 * local_88.bottom) / (local_11c / 2);
            local_13c = local_120;
            local_140 = local_11c / 2;
          }
          for (; local_ac < local_138.right; local_ac = local_ac + local_13c) {
            for (local_b4 = local_138.top; local_b4 < local_138.bottom;
                local_b4 = local_b4 + local_140) {
              SetRect(&local_c4,local_ac,local_b4,local_ac + local_c8,local_b4 + local_10c);
              if (local_8 == (LONG *)0x0) {
                FUN_004f3e29(DAT_00538e48,&local_c4,local_1c);
              }
              else {
                FUN_004f3eaa(DAT_00538e48,&local_c4.left,local_1c,local_120,local_11c / 2,0,0,0,
                             local_11c / 2);
              }
            }
          }
        }
        if (local_20 != (uint *)0x0) {
          local_150 = local_14 % (int)local_28;
          iVar7 = FUN_00479d16(hwnd,local_14);
          if ((uint *)iVar7 != local_2c) {
            local_14 = FUN_00479dac(hwnd,(int)local_2c);
            SetWindowLongA(hwnd,0x20,local_14);
          }
          if ((local_10 == (HANDLE)0x0) || (local_28 == (LONG *)0x0)) {
            SetRect(&local_a8,local_14 - local_88.right / 0x14,0,local_14 + local_88.right / 0x14,
                    local_88.bottom);
            pHVar8 = GetStockObject(4);
            FillRect(DAT_00538e48,&local_a8,pHVar8);
          }
          else {
            GetObjectA(local_10,0x18,local_174);
            local_158 = local_170 / 2;
            local_15c = local_16c / (int)local_28;
            local_14c = 0;
            local_154 = local_15c * local_150;
            local_148 = local_154;
            local_144 = local_158;
            FUN_00479e3f(hwnd,&local_a8);
            if (local_18 == 0) {
              SetMapMode(DAT_00538e48,8);
              SetWindowExtEx(DAT_00538e48,1,1,(LPSIZE)0x0);
              SetViewportExtEx(DAT_00538e48,-1,1,(LPSIZE)0x0);
              SetWindowOrgEx(DAT_00538e48,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00538e48,local_88.right,0,(LPPOINT)0x0);
              iVar7 = local_88.right - local_a8.left;
              local_a8.left = local_88.right - local_a8.right;
              local_a8.right = iVar7;
            }
            FUN_004f3eaa(DAT_00538e48,&local_a8.left,local_10,local_158,local_15c,local_14c,
                         local_148,local_144,local_154);
            if (local_18 == 0) {
              SetMapMode(DAT_00538e48,1);
              SetWindowOrgEx(DAT_00538e48,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00538e48,0,0,(LPPOINT)0x0);
            }
          }
        }
        RestoreDC(DAT_00538e48,local_b0);
        BitBlt(local_128,0,0,local_88.right,local_88.bottom,DAT_00538e48,0,0,0xcc0020);
        EndPaint(hwnd,&local_108);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_2c = (uint *)0x0;
      local_24 = (uint *)0x0;
      local_c = (LONG *)0x0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,(LONG)local_24);
      SetWindowLongA(hwnd,8,(LONG)local_c);
      local_18 = 1;
      SetWindowLongA(hwnd,0xc,1);
      local_1c = (uint *)0x0;
      local_8 = (LONG *)0x0;
      SetWindowLongA(hwnd,0x10,0);
      SetWindowLongA(hwnd,0x14,(LONG)local_8);
      local_10 = (uint *)0x0;
      local_28 = (LONG *)0x0;
      SetWindowLongA(hwnd,0x18,0);
      SetWindowLongA(hwnd,0x1c,(LONG)local_28);
      local_14 = 0;
      SetWindowLongA(hwnd,0x20,0);
      local_20 = (uint *)0x0;
      SetWindowLongA(hwnd,0x24,0);
      return 0;
    }
  }
  else if (uMsg < 0xe1) {
    if (uMsg == 0xe0) {
      puVar4 = (uint *)GetWindowLongA(hwnd,0);
      if (puVar4 != wParam) {
        local_2c = wParam;
        SetWindowLongA(hwnd,0,(LONG)wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else {
    sVar1 = (short)((uint)lParam >> 0x10);
    if (uMsg < 0x201) {
      if (uMsg == 0x200) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          local_18 = GetWindowLongA(hwnd,0xc);
          local_2c = (uint *)GetWindowLongA(hwnd,0);
          local_24 = (uint *)GetWindowLongA(hwnd,4);
          local_c = (LONG *)GetWindowLongA(hwnd,8);
          local_14 = GetWindowLongA(hwnd,0);
          local_44 = (int)(short)lParam;
          local_40 = (int)sVar1;
          GetClientRect(hwnd,&local_3c);
          if (local_44 < 0) {
            local_44 = 0;
          }
          if (local_3c.right < local_44) {
            local_44 = local_3c.right;
          }
          if (local_40 < 0) {
            local_40 = 0;
          }
          if (local_3c.bottom < local_40) {
            local_40 = local_3c.bottom;
          }
          if (DAT_00538e50 < local_44) {
            if (local_18 == 0) {
              local_18 = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
          }
          else if ((local_44 < DAT_00538e50) && (local_18 != 0)) {
            local_18 = 0;
            SetWindowLongA(hwnd,0xc,0);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          local_48 = local_44;
          if (local_44 < (int)local_24) {
            local_48 = (int)local_24;
          }
          else if ((int)local_c < local_44) {
            local_48 = (int)local_c;
          }
          if (local_48 != local_14) {
            local_14 = local_48;
            SetWindowLongA(hwnd,0x20,local_48);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          iVar7 = FUN_00479d16(hwnd,local_44);
          if ((uint *)iVar7 != local_2c) {
            pHVar6 = hwnd;
            iVar7 = FUN_00479d16(hwnd,local_44);
            WVar10 = CONCAT31((int3)((uint)(iVar7 << 0x10) >> 8),5);
            UVar11 = 0x114;
            pHVar5 = GetParent(hwnd);
            SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
          }
          UpdateWindow(hwnd);
          DAT_00538e50 = local_44;
          _DAT_00538e54 = local_40;
        }
        return 0;
      }
      if (uMsg == 0xe1) {
        uVar9 = GetWindowLongA(hwnd,0);
        return uVar9;
      }
      if (uMsg == 0xe2) {
        local_24 = (uint *)GetWindowLongA(hwnd,4);
        pLVar2 = (LONG *)GetWindowLongA(hwnd,8);
        if ((local_24 != wParam) || (lParam != pLVar2)) {
          local_24 = wParam;
          local_c = lParam;
          SetWindowLongA(hwnd,4,(LONG)wParam);
          SetWindowLongA(hwnd,8,(LONG)local_c);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
      if (uMsg == 0xe3) {
        local_24 = (uint *)GetWindowLongA(hwnd,4);
        LVar3 = GetWindowLongA(hwnd,8);
        if (wParam != (uint *)0x0) {
          *wParam = (uint)local_24;
        }
        if (lParam != (LONG *)0x0) {
          *lParam = LVar3;
        }
        return LVar3 << 0x10 | (uint)local_24 & 0xffff;
      }
    }
    else if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        uVar9 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
        return uVar9;
      }
      if (uMsg == 0x201) {
        UpdateWindow(hwnd);
        local_14 = GetWindowLongA(hwnd,0x20);
        local_18 = GetWindowLongA(hwnd,0xc);
        local_20 = (uint *)GetWindowLongA(hwnd,0x24);
        local_60 = (int)(short)lParam;
        local_5c = (int)sVar1;
        if (local_20 == (uint *)0x0) {
          return 0;
        }
        FUN_00479e3f(hwnd,&local_58);
        if ((local_60 < local_58.left) || (local_58.right < local_60)) {
          if (local_58.right < local_60) {
            if (local_18 == 0) {
              local_18 = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 1;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
          else if (local_60 < local_58.left) {
            if (local_18 != 0) {
              local_18 = 0;
              SetWindowLongA(hwnd,0xc,0);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 0;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
        }
        else {
          SetCapture(hwnd);
        }
        DAT_00538e50 = local_60;
        _DAT_00538e54 = local_5c;
        return 0;
      }
      if (uMsg == 0x202) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          ReleaseCapture();
          local_14 = GetWindowLongA(hwnd,0x20);
          local_78 = (int)(short)lParam;
          local_74 = (int)sVar1;
          GetClientRect(hwnd,&local_70);
          if (local_78 < 0) {
            local_78 = 0;
          }
          if (local_70.right < local_78) {
            local_78 = local_70.right;
          }
          if (local_74 < 0) {
            local_74 = 0;
          }
          if (local_70.bottom < local_74) {
            local_74 = local_70.bottom;
          }
          local_14 = local_78;
          SetWindowLongA(hwnd,0x20,local_78);
          InvalidateRect(hwnd,(RECT *)0x0,1);
          pHVar6 = hwnd;
          iVar7 = FUN_00479d16(hwnd,local_78);
          WVar10 = CONCAT31((int3)((uint)(iVar7 << 0x10) >> 8),4);
          UVar11 = 0x114;
          pHVar5 = GetParent(hwnd);
          SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
        }
        return 0;
      }
    }
    else {
      switch(uMsg) {
      case 0x432:
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      case 0x464:
        puVar4 = (uint *)GetWindowLongA(hwnd,0x10);
        if (wParam != puVar4) {
          local_1c = wParam;
          local_8 = lParam;
          SetWindowLongA(hwnd,0x10,(LONG)wParam);
          SetWindowLongA(hwnd,0x14,(LONG)local_8);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x465:
        uVar9 = GetWindowLongA(hwnd,0x10);
        if (wParam == (uint *)0x0) {
          return uVar9;
        }
        *wParam = uVar9;
        return uVar9;
      case 0x466:
        local_10 = (uint *)GetWindowLongA(hwnd,0x18);
        GetWindowLongA(hwnd,0x1c);
        if (wParam != local_10) {
          local_10 = wParam;
          local_28 = lParam;
          SetWindowLongA(hwnd,0x18,(LONG)wParam);
          SetWindowLongA(hwnd,0x1c,(LONG)local_28);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x467:
        local_10 = (uint *)GetWindowLongA(hwnd,0x18);
        LVar3 = GetWindowLongA(hwnd,0x1c);
        if (wParam != (uint *)0x0) {
          *wParam = (uint)local_10;
        }
        if (lParam == (LONG *)0x0) {
          return (uint)local_10;
        }
        *lParam = LVar3;
        return (uint)local_10;
      case 0x468:
        puVar4 = (uint *)GetWindowLongA(hwnd,0x24);
        if (wParam != puVar4) {
          local_20 = wParam;
          SetWindowLongA(hwnd,0x24,(LONG)wParam);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
    }
  }
  uVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return uVar9;
}



/*
 * Decompiled function: FUN_00479d16
 * Entry Point: 00479d16
 * Size: 150 bytes
 */


int FUN_00479d16(HWND hwnd,int arg2)

{
  int iVar1;
  LONG LVar2;
  tagRECT local_18;
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    local_8 = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&local_18);
    if (arg2 < local_18.left) {
      arg2 = local_18.left;
    }
    if (local_18.right < arg2) {
      arg2 = local_18.right;
    }
    iVar1 = LVar2 + (((local_8 - LVar2) + 1) * arg2) / local_18.right;
  }
  return iVar1;
}



/*
 * Decompiled function: FUN_00479dac
 * Entry Point: 00479dac
 * Size: 147 bytes
 */


int FUN_00479dac(HWND hwnd,int arg2)

{
  int iVar1;
  LONG LVar2;
  tagRECT local_18;
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    local_8 = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&local_18);
    if (arg2 < LVar2) {
      arg2 = LVar2;
    }
    if (local_8 < arg2) {
      arg2 = local_8;
    }
    iVar1 = (local_18.right * arg2) / ((local_8 - LVar2) + 1);
  }
  return iVar1;
}



/*
 * Decompiled function: FUN_00479e3f
 * Entry Point: 00479e3f
 * Size: 362 bytes
 */


void FUN_00479e3f(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  uint8_t local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  int local_20;
  LONG local_1c;
  HANDLE local_18;
  tagRECT local_14;
  
  if ((hwnd != (HWND)0x0) && (arg2 != (LPRECT)0x0)) {
    local_1c = GetWindowLongA(hwnd,0x20);
    local_18 = (HANDLE)GetWindowLongA(hwnd,0x18);
    LVar1 = GetWindowLongA(hwnd,0x1c);
    GetClientRect(hwnd,&local_14);
    if ((local_18 == (HANDLE)0x0) || (LVar1 == 0)) {
      SetRect(arg2,local_1c - local_14.right / 0x14,0,local_1c + local_14.right / 0x14,
              local_14.bottom);
    }
    else {
      GetObjectA(local_18,0x18,local_3c);
      local_24 = local_14.bottom;
      local_20 = ((local_38 / 2) * local_14.bottom) / (local_34 / LVar1);
      SetRect(arg2,local_1c - local_20 / 2,0,(local_1c - local_20 / 2) + local_20,local_14.bottom);
    }
    if (arg2->left < local_14.left) {
      OffsetRect(arg2,local_14.left - arg2->left,0);
    }
    else if (local_14.right < arg2->right) {
      OffsetRect(arg2,local_14.right - arg2->right,0);
    }
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00479fb0
 * Entry Point: 00479fb0
 * Size: 44 bytes
 */


int Mem_AllocOrFree_00479fb0(int x,int arg2)

{
  if (arg2 == 2) {
    Mem_AllocOrFree_00479fdc(x);
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_00479fdc
 * Entry Point: 00479fdc
 * Size: 29 bytes
 */


int Mem_AllocOrFree_00479fdc(int color_mask)

{
  DAT_00525f28 = *(int *)(color_mask + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_00479ff9
 * Entry Point: 00479ff9
 * Size: 707 bytes
 */


int FUN_00479ff9(int x,int arg2)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int arg_2;
  int arg_3;
  int *piVar5;
  int arg_5;
  int local_18;
  int local_14;
  int *local_8;
  
  *(int *)g_DisplaySurfaceScreen = 1;
  iVar2 = *(int *)(&DAT_00525f34 + x * 0x10);
  iVar3 = *(int *)(&DAT_00525f30 + x * 0x10);
  piVar5 = (int *)g_DisplaySurfaceBackBuffer;
  DVar1 = Ai_Util_004c3bc4(0x2d);
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,*(uint *)(&DAT_00525f30 + x * 0x10),
               *(int *)(&DAT_00525f34 + x * 0x10),
               g_DisplayScreenWidth - *(int *)(&DAT_00525f30 + x * 0x10),DVar1,piVar5,iVar3,iVar2);
  switch(x) {
  case 0:
    local_8 = &DAT_005394d8;
    break;
  case 1:
    local_8 = (int *)&DAT_005394b0;
    break;
  case 2:
    local_8 = (int *)&DAT_005394f8;
    break;
  case 3:
    local_8 = (int *)&DAT_00539188;
  }
  switch(arg2) {
  case 0:
    local_18 = 0;
    local_14 = 0;
    break;
  case 1:
    local_18 = 1;
    local_14 = 1;
    break;
  case 2:
    local_18 = 1;
    local_14 = 2;
    break;
  case 3:
    local_18 = 2;
    local_14 = 3;
  }
  arg_2 = *(int *)(&DAT_00525f30 + x * 0x10) + (DAT_00525f84 - DAT_00525f80) / 2;
  arg_3 = *(int *)(&DAT_00525f34 + x * 0x10) + (DAT_00525f84 - DAT_00525f80) / 2;
  iVar2 = Ai_Util_004c3bc4(2);
  iVar3 = Ai_Util_004c3bc4(2);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar2 / 2 + arg_2,iVar3 / 2 + arg_3,DAT_00525f80
                      ,DAT_00525f80,*(int *)(&DAT_005394e8 + local_14 * 4));
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,DAT_00525f80,DAT_00525f80,
                      *(int *)(&DAT_005394e8 + local_14 * 4));
  }
  iVar2 = local_8[local_18];
  iVar3 = *(int *)(&DAT_00525f38 + x * 0x10);
  arg_5 = DAT_00525f80;
  iVar4 = Ai_Util_004c3bc4(0x24);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2 + iVar4,arg_3,iVar3,arg_5,iVar2);
  *(int *)g_DisplaySurfaceScreen = 0;
  iVar2 = *(int *)(&DAT_00525f34 + x * 0x10);
  iVar3 = *(int *)(&DAT_00525f30 + x * 0x10);
  piVar5 = (int *)g_DisplaySurfaceScreen;
  DVar1 = Ai_Util_004c3bc4(0x2d);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,*(uint *)(&DAT_00525f30 + x * 0x10),
               *(int *)(&DAT_00525f34 + x * 0x10),
               g_DisplayScreenWidth - *(int *)(&DAT_00525f30 + x * 0x10),DVar1,piVar5,iVar3,iVar2);
  return 0;
}



/*
 * Decompiled function: Sprite_Load_begin_0047a2e6
 * Entry Point: 0047a2e6
 * Size: 1633 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Sprite_Load_begin_0047a2e6(void)

{
  int iVar1;
  int uVar2;
  int local_1ac;
  int local_1a8;
  int local_1a0 [100];
  int local_10;
  char *local_c;
  int local_8;
  
  local_c = s_magic3_map_005269f4;
  do {
    strcpy(local_c,s_magic3_map_00526a00);
    DAT_00525f28 = -1;
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    FUN_00510b70(1,0,0,s_menubak_pic_00526a0c,
                 (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork
                       ,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    FUN_005115a0(0,(short)DAT_00530d9c);
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
    _DAT_00525f98 = FUN_00406b01(local_c);
    for (local_8 = 4; local_8 < 0xe; local_8 = local_8 + 1) {
      if (local_8 < 10) {
        local_c[5] = (char)local_8 + '0';
      }
      else {
        local_c[5] = (char)local_8 + 'W';
      }
      iVar1 = FUN_00406b01(local_c);
      if (iVar1 != 0) break;
    }
    if (local_8 == 0xe) {
      _DAT_00525f94 = 0;
    }
    local_1ac = 0;
    Sprite_LoadAll(local_1a0,s_begin_spr_00526a18);
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      (&DAT_005394d8)[local_1a8] = (void *)local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 3; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394b0 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 3; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394f8 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394c0 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_00539188 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_00538e60 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 4; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394e8 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    if (DAT_00525de8 == DAT_00525dd8) {
      for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f30 + local_8 * 0x10));
        *(int *)(&DAT_00525f30 + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f34 + local_8 * 0x10));
        *(int *)(&DAT_00525f34 + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f38 + local_8 * 0x10));
        *(int *)(&DAT_00525f38 + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f3c + local_8 * 0x10));
        *(int *)(&DAT_00525f3c + local_8 * 0x10) = uVar2;
        uVar2 = Ai_Util_004c3bc4((&DAT_00525de8)[local_8 * 0x15]);
        (&DAT_00525de8)[local_8 * 0x15] = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525dec + local_8 * 0x54));
        *(int *)(&DAT_00525dec + local_8 * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525df0 + local_8 * 0x54));
        *(int *)(&DAT_00525df0 + local_8 * 0x54) = uVar2;
        uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525df4 + local_8 * 0x54));
        *(int *)(&DAT_00525df4 + local_8 * 0x54) = uVar2;
      }
      DAT_00525f80 = Ai_Util_004c3bc4(DAT_00525f80);
      DAT_00525f84 = Ai_Util_004c3bc4(DAT_00525f84);
      DAT_00525f88 = Ai_Util_004c3bc4(DAT_00525f88);
    }
    local_10 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(local_10);
    FUN_0041f17e(0x525dd8,4,local_10);
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      FUN_00479ff9(local_8,-(uint)(*(int *)(&DAT_00525f90 + local_8 * 4) == 0) & 3);
      if (*(int *)(&DAT_00525f90 + local_8 * 4) == 0) {
        FUN_0041ece4((int)(&DAT_00525dd8 + local_8 * 0x15));
      }
    }
    while (DAT_00525f28 == -1) {
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
    }
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(local_10);
    Mem_AllocOrFree_0050fc50(DAT_005394d8);
    if (DAT_00525f28 != 4) {
      return DAT_00525f28 + -1;
    }
    Pic_Load_004244a0();
  } while( true );
}



/*
 * Decompiled function: FUN_0047a94c
 * Entry Point: 0047a94c
 * Size: 254 bytes
 */


int FUN_0047a94c(int x,int arg2)

{
  bool bVar1;
  int uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    FUN_00479ff9((x + -0x525dd8) / 0x54,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047aa4a
 * Entry Point: 0047aa4a
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047aa4a(int color_mask)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526a24,0xf,100,100,0);
  DAT_00525f28 = *(int *)(color_mask + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_0047aa7c
 * Entry Point: 0047aa7c
 * Size: 368 bytes
 */


int FUN_0047aa7c(int x,int arg2)

{
  uint arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
  int iVar1;
  uint arg_4_00;
  DWORD arg_5_00;
  int *arg_6;
  int arg_7;
  int arg_8;
  int *local_18;
  
  if (arg2 == 0) {
    local_18 = (int *)g_DisplaySurfaceBackBuffer;
  }
  else if (arg2 == 1) {
    local_18 = (int *)g_DisplaySurfaceWork;
  }
  else if (arg2 == 2) {
    local_18 = (int *)g_DisplaySurfaceWork;
  }
  arg_2 = *(uint *)(&DAT_00526150 + x * 0x10);
  arg_3 = *(int *)(&DAT_00526154 + x * 0x10);
  arg_4 = *(uint *)(&DAT_00526158 + x * 0x10);
  arg_5 = *(DWORD *)(&DAT_0052615c + x * 0x10);
  if (arg2 == 2) {
    arg_8 = 0;
    arg_7 = 0;
    arg_4_00 = arg_4;
    arg_5_00 = arg_5;
    arg_6 = (int *)g_DisplaySurfaceBackBuffer;
    iVar1 = Ai_Util_004c3bc4(0x43);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,200,arg_3 - iVar1,arg_4_00,arg_5_00,arg_6,arg_7,
                 arg_8);
    Surface_StretchBlt(local_18,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,4,4,
                       arg_4 - 4,arg_5 - 4);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    FUN_0050e040(local_18,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,arg_2,arg_3);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Load_menu2_hi_0047abf1
 * Entry Point: 0047abf1
 * Size: 945 bytes
 */


int Pic_Load_menu2_hi_0047abf1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int uVar5;
  int local_8;
  
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_menu2_pic_00526a38,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  iVar1 = Ai_Util_004c3bc4(0x19d);
  iVar2 = Ai_Util_004c3bc4(0xa4);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0x1b1,0x43,0xa4,0x19d,
                     (int *)g_DisplaySurfaceBackBuffer,200,0,iVar2,iVar1);
  FUN_005115a0(0,(short)DAT_00530d9c);
  Mem_AllocOrFree_00510e20(1,s_menu2_norm_pic_00526a44);
  iVar1 = Ai_Util_004c3bc4(0x19d);
  iVar2 = Ai_Util_004c3bc4(0xa4);
  iVar3 = Ai_Util_004c3bc4(0x43);
  iVar4 = Ai_Util_004c3bc4(0x1b1);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0xa4,0x19d,
                     (int *)g_DisplaySurfaceBackBuffer,iVar4,iVar3,iVar2,iVar1);
  Mem_AllocOrFree_00510e20(2,s_menu2_hi_pic_00526a54);
  iVar1 = Ai_Util_004c3bc4(0x19d);
  iVar2 = Ai_Util_004c3bc4(0xa4);
  iVar3 = Ai_Util_004c3bc4(0x43);
  iVar4 = Ai_Util_004c3bc4(0x1b1);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,0,0xa4,0x19d,(int *)g_DisplaySurfaceWork,iVar4,
                     iVar3,iVar2,iVar1);
  if (DAT_00525fb8 == DAT_00525fa8) {
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526150 + local_8 * 0x10));
      *(int *)(&DAT_00526150 + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526154 + local_8 * 0x10));
      *(int *)(&DAT_00526154 + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526158 + local_8 * 0x10));
      *(int *)(&DAT_00526158 + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_0052615c + local_8 * 0x10));
      *(int *)(&DAT_0052615c + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4((&DAT_00525fb8)[local_8 * 0x15]);
      (&DAT_00525fb8)[local_8 * 0x15] = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fbc + local_8 * 0x54));
      *(int *)(&DAT_00525fbc + local_8 * 0x54) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fc0 + local_8 * 0x54));
      *(int *)(&DAT_00525fc0 + local_8 * 0x54) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fc4 + local_8 * 0x54));
      *(int *)(&DAT_00525fc4 + local_8 * 0x54) = uVar5;
    }
  }
  iVar1 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar1);
  FUN_0041f17e(0x525fa8,5,iVar1);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    FUN_0047aa7c(local_8,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(iVar1);
  return DAT_00525f28 + -1;
}



/*
 * Decompiled function: FUN_0047afa2
 * Entry Point: 0047afa2
 * Size: 245 bytes
 */


int FUN_0047afa2(int x,int arg2)

{
  bool bVar1;
  int uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    FUN_0047aa7c(*(int *)(x + 0x2c) + -1,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047b097
 * Entry Point: 0047b097
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047b097(int color_mask)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526a64,0xf,100,100,0);
  DAT_00525f28 = *(int *)(color_mask + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_0047b0c9
 * Entry Point: 0047b0c9
 * Size: 314 bytes
 */


int FUN_0047b0c9(int x,int arg2)

{
  uint arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
  int *local_8;
  
  if (arg2 == 0) {
    local_8 = &DAT_00676d60;
  }
  else if (arg2 == 1) {
    local_8 = (int *)&DAT_00676e20;
  }
  else if (arg2 == 2) {
    local_8 = (int *)&DAT_00676e20;
  }
  arg_2 = *(uint *)(&DAT_00526388 + x * 0x10);
  arg_3 = *(int *)(&DAT_0052638c + x * 0x10);
  arg_4 = *(uint *)(&DAT_00526390 + x * 0x10);
  arg_5 = *(DWORD *)(&DAT_00526394 + x * 0x10);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceWork,arg_2 + 2,arg_3 + 2,arg_4 - 4,arg_5 - 4,
                      local_8[x]);
    Surface_BlitToDevice((int *)g_DisplaySurfaceWork,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,local_8[x]);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Load_menu3_but1_0047b208
 * Entry Point: 0047b208
 * Size: 1033 bytes
 */


int Pic_Load_menu3_but1_0047b208(void)

{
  int *piVar1;
  int uVar2;
  int local_3c [4];
  int local_2c [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_menu3_pic_00526a78,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork,0
                     ,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  FUN_005115a0(0,(short)DAT_00530d9c);
  piVar1 = (int *)FUN_0050e6f0(local_2c,(int)g_DisplaySurfaceWork,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  Mem_AllocOrFree_0050fc00();
  Mem_AllocOrFree_00510de0(1,s_menu3_but1_pic_00526a84);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,0,local_18 * 0x4b,0x46,0x4b);
    (&DAT_00676d60)[local_18] = (void *)uVar2;
  }
  Mem_AllocOrFree_00510de0(1,s_menu3but_pic_00526a94);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,0,local_18 * 0x4b,0x46,0x4b);
    *(int *)(&DAT_00676e20 + local_18 * 4) = uVar2;
  }
  FUN_0050fc20();
  if (DAT_005261a0 == DAT_00526190) {
    for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526388 + local_18 * 0x10));
      *(int *)(&DAT_00526388 + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_0052638c + local_18 * 0x10));
      *(int *)(&DAT_0052638c + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526390 + local_18 * 0x10));
      *(int *)(&DAT_00526390 + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526394 + local_18 * 0x10));
      *(int *)(&DAT_00526394 + local_18 * 0x10) = uVar2;
      uVar2 = Ai_Util_004c3bc4((&DAT_005261a0)[local_18 * 0x15]);
      (&DAT_005261a0)[local_18 * 0x15] = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261a4 + local_18 * 0x54));
      *(int *)(&DAT_005261a4 + local_18 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261a8 + local_18 * 0x54));
      *(int *)(&DAT_005261a8 + local_18 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261ac + local_18 * 0x54));
      *(int *)(&DAT_005261ac + local_18 * 0x54) = uVar2;
    }
  }
  local_1c = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_1c);
  FUN_0041f17e(0x526190,6,local_1c);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    FUN_0047b0c9(local_18,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(local_1c);
  Mem_AllocOrFree_0050fc50(DAT_00676d60);
  FUN_0050e6f0(local_3c,(int)g_DisplaySurfaceWork,local_14,local_10,local_c,local_8);
  if (DAT_00525f28 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(int *)(DAT_00525f28 * 4 + 0x5263d4);
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_0047b616
 * Entry Point: 0047b616
 * Size: 245 bytes
 */


int FUN_0047b616(int x,int arg2)

{
  bool bVar1;
  int uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    FUN_0047b0c9(*(int *)(x + 0x2c) + -1,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047b70b
 * Entry Point: 0047b70b
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047b70b(int color_mask)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526aa4,0xf,100,100,0);
  DAT_00525f28 = *(int *)(color_mask + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_0047b73d
 * Entry Point: 0047b73d
 * Size: 343 bytes
 */


int FUN_0047b73d(int x,int arg2)

{
  uint arg_2;
  int arg_3;
  uint arg_4;
  DWORD arg_5;
  int *local_8;
  
  if (arg2 == 0) {
    local_8 = &DAT_00676dd0;
  }
  else if (arg2 == 1) {
    local_8 = &DAT_00676d80;
  }
  else if (arg2 == 2) {
    local_8 = &DAT_00676d80;
  }
  arg_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005263f0 + x * 0x54) + 0x1d);
  arg_3 = Ai_Util_004c3bc4(*(int *)(&DAT_005263f4 + x * 0x54));
  arg_4 = Ai_Util_004c3bc4(0x4d);
  arg_5 = Ai_Util_004c3bc4(0x5f);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceWork,arg_2 + 4,arg_3 + 4,arg_4 - 4,arg_5 - 4,
                      local_8[x]);
    Surface_BlitToDevice((int *)g_DisplaySurfaceWork,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,local_8[x]);
  }
  return 0;
}



/*
 * Decompiled function: Sprite_Load__16faces_0047b899
 * Entry Point: 0047b899
 * Size: 1112 bytes
 */


int Sprite_Load__16faces_0047b899(void)

{
  int *piVar1;
  int iVar2;
  int local_90 [4];
  int local_80 [4];
  int local_70 [4];
  int local_60 [9];
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  char *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_pedstls_pic_00526ab8,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork,0
                     ,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  FUN_005115a0(0,(short)DAT_00530d9c);
  LoadPalNoPic(s_pedstls_pic_00526ac4);
  piVar1 = (int *)FUN_0050e6f0(local_70,(int)g_DisplaySurfaceWork,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  Sprite_LoadAll(&DAT_00676dd0,s_16facesLow_spr_00526ad0);
  Sprite_LoadAll(&DAT_00676d80,s_16faces_spr_00526ae0);
  FUN_0040b441((int *)&DAT_005263f0,0xe);
  local_1c = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_1c);
  FUN_0041f17e(0x5263f0,0xf,local_1c);
  for (local_18 = 0; local_18 < 0xe; local_18 = local_18 + 1) {
    FUN_0047b73d(local_18,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  if (DAT_00525f28 == 0) {
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(local_1c);
    iVar2 = -1;
  }
  else {
    FUN_0047c2fd(DAT_00525f28 + -1);
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(local_1c);
    local_60[0] = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 800;
    local_60[4] = 600;
    local_60[5] = 1;
    local_60[6] = 0xf;
    local_60[7] = 4;
    local_60[8] = 0;
    local_3c = local_60;
    local_20 = (&DAT_00676d7c)[DAT_00525f28];
    local_28 = (int)*(short *)(local_20 + 4);
    local_2c = (int)*(short *)(local_20 + 6);
    local_34 = FUN_0050d0b0(4,local_28 * 2,local_2c,8);
    FUN_0050d370(4,local_34);
    FUN_0050e6f0(local_80,(int)local_3c,0,0,local_28 * 2,local_2c);
    LoadPalNoPic(s_menu4_pic_00526aec);
    Surface_FillRect(local_3c,0,0,local_28,local_2c,0);
    Sprite_DrawDirect(local_3c,0,0,local_20);
    for (local_38 = 0; local_38 < local_2c; local_38 = local_38 + 1) {
      local_24 = (char *)((*(int *)(DAT_0070a860 + 0x2c) + *(int *)(DAT_0070a860 + 0x20)) * local_38
                         + *(int *)(DAT_0070a860 + 0x18));
      for (local_30 = 0; local_30 < local_28; local_30 = local_30 + 1) {
        if (*local_24 == '\0') {
          local_24[local_28] = -1;
        }
        local_24 = local_24 + 1;
      }
    }
    DAT_0067bdd8 = *(int *)(DAT_0070a860 + 8);
    DAT_0067bdd4 = DAT_0070a860;
    SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
    DAT_0070a860 = 0;
    Mem_AllocOrFree_0050fc50(DAT_00676dd0);
    Mem_AllocOrFree_0050fc50(DAT_00676d80);
    FUN_0050e6f0(local_90,(int)g_DisplaySurfaceWork,local_14,local_10,local_c,local_8);
    memset(s_Ned_Way_the_Ratiocinator_0052f020,0,0x40);
    strcpy(s_Ned_Way_the_Ratiocinator_0052f020,*(char **)(DAT_00525f28 * 4 + 0x5268dc));
    DAT_00676dc8 = strlen(s_Ned_Way_the_Ratiocinator_0052f020);
    Pic_Load_namepick_0047be64(s_Ned_Way_the_Ratiocinator_0052f020);
    strcpy(&DAT_0068a6a0,s_Ned_Way_the_Ratiocinator_0052f020);
    iVar2 = DAT_00525f28 + -1;
  }
  return iVar2;
}



/*
 * Decompiled function: FUN_0047bcf1
 * Entry Point: 0047bcf1
 * Size: 371 bytes
 */


void FUN_0047bcf1(int *color_mask,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,
                 int arg_7,int arg_8)

{
  int local_3fc;
  int local_3f8;
  char local_3f4 [1000];
  char *local_c;
  uint local_8;
  
  for (local_3fc = 0; local_3fc < arg_5; local_3fc = local_3fc + 1) {
    Surface_GetLine((int *)local_3f4,*color_mask,arg_2,local_3fc + arg_3,arg_4);
    if (local_3f4[0] == '\0') {
      local_c = (char *)0x0;
    }
    else {
      local_c = local_3f4;
    }
    local_8 = 0;
    for (local_3f8 = 0; local_3f8 < arg_4; local_3f8 = local_3f8 + 1) {
      if (local_3f4[local_3f8] == '\0') {
        if (local_8 == 0) {
          local_c = local_3f4 + local_3f8;
        }
        else {
          Surface_PutLine((int *)local_c,*arg_6,(int)(local_c + (arg_7 - (int)local_3f4)),
                          local_3fc + arg_8,local_8);
          local_8 = 0;
          local_c = local_3f4 + local_3f8;
        }
      }
      else {
        local_8 = local_8 + 1;
      }
    }
    if (local_8 != 0) {
      Surface_PutLine((int *)local_c,*arg_6,(int)(local_c + (arg_7 - (int)local_3f4)),
                      local_3fc + arg_8,local_8);
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Load_namepick_0047be64
 * Entry Point: 0047be64
 * Size: 540 bytes
 */


void Pic_Load_namepick_0047be64(char *filepath)

{
  int iVar1;
  uint arg_2;
  int iVar2;
  int iVar3;
  int iVar4;
  char *str_5;
  
  Mem_AllocOrFree_00510de0(1,s_namepick_pic_00526af8);
  *(int *)(g_DisplaySurfaceBackBuffer + 0x20) =
       *(int *)(g_DisplaySurfaceScreen + 0x20);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xed,0x8b,0x19);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x18);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,0x114,0x6a,(int *)g_DisplaySurfaceBackBuffer,0,
               200);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x100);
  iVar1 = Ai_Util_004c3bc4(0xbc);
  FUN_0047bcf1((int *)g_DisplaySurfaceBackBuffer,0,200,0x114,0x6a,
               (int *)g_DisplaySurfaceScreen,(g_DisplayScreenWidth + -0x114) / 2,iVar1);
  while( true ) {
    arg_2 = FUN_004080b2();
    if (arg_2 == 0x1c0d) break;
    iVar1 = FUN_0050f440((int *)g_DisplaySurfaceBackBuffer,filepath);
    if (arg_2 != 0) {
      FUN_0047c360(filepath,arg_2,0x19);
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,0x114,0x6a,
                   (int *)g_DisplaySurfaceBackBuffer,0,200);
      FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x100);
      iVar2 = Ai_Util_004c3bc4(0xbc);
      FUN_0047bcf1((int *)g_DisplaySurfaceBackBuffer,0,200,0x114,0x6a,
                   (int *)g_DisplaySurfaceScreen,(g_DisplayScreenWidth + -0x114) / 2,iVar2);
    }
    str_5 = filepath;
    iVar2 = DAT_00676dc8;
    iVar3 = Ai_Util_004c3bc4(0xbc);
    iVar3 = iVar3 + 0x30;
    iVar4 = Ai_Util_004c3bc4(0x140);
    FUN_0041fec7((int)g_DisplaySurfaceScreen,0xb4,iVar4 - iVar1 / 2,iVar3,str_5,iVar2);
  }
  Ai_Subsystem_004cd1d1();
  return;
}



/*
 * Decompiled function: FUN_0047c080
 * Entry Point: 0047c080
 * Size: 245 bytes
 */


int FUN_0047c080(int x,int arg2)

{
  bool bVar1;
  int uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    FUN_0047b73d(*(int *)(x + 0x2c) + -1,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047c175
 * Entry Point: 0047c175
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047c175(int color_mask)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526b30,0xf,100,100,0);
  DAT_00525f28 = *(int *)(color_mask + 0x2c);
  return 0;
}



/*
 * Decompiled function: Sprite_Load__16faces_0047c1a7
 * Entry Point: 0047c1a7
 * Size: 87 bytes
 */


void Sprite_Load__16faces_0047c1a7(int color_mask)

{
  Sprite_LoadAll(&DAT_00676dd0,s_16facesLow_spr_00526b44);
  Sprite_LoadAll(&DAT_00676d80,s_16faces_spr_00526b54);
  FUN_0047c2fd(color_mask);
  Mem_AllocOrFree_0050fc50(DAT_00676dd0);
  Mem_AllocOrFree_0050fc50(DAT_00676d80);
  return;
}



/*
 * Decompiled function: Pic_Load_advfac64_0047c1fe
 * Entry Point: 0047c1fe
 * Size: 255 bytes
 */


int Pic_Load_advfac64_0047c1fe(int *color_mask,int y,int width,int height)

{
  int uVar1;
  int local_20 [2];
  int local_18;
  uint local_14 [3];
  int local_8;
  
  local_8 = height;
  if (height == 0) {
    uVar1 = 0;
  }
  else {
    Surface_FillRect(color_mask,y,width,*(short *)(height + 4) + 2,*(short *)(height + 6) + 2,0);
    Sprite_DrawDirect(color_mask,y,width,height);
    FUN_00488fdb(color_mask,y,width,(int)*(short *)(local_8 + 4),(int)*(short *)(local_8 + 6),
                 s_pedstls_pic_00526b70,s_advfac64_pic_00526b60);
    FUN_0048ed04(height,local_14,local_20);
    local_18 = (int)*(short *)(local_8 + 0xc);
    uVar1 = Sprite_EncodeFromSurface
                      (*color_mask,y + local_14[0],width + local_18,(local_20[0] - local_14[0]) + 1,
                       (((int)*(short *)(local_8 + 0xc) + (int)*(short *)(local_8 + 0xe)) - local_18
                       ) + 1);
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_0047c2fd
 * Entry Point: 0047c2fd
 * Size: 99 bytes
 */


int FUN_0047c2fd(int color_mask)

{
  Mem_AllocOrFree_0050fc00();
  DAT_00676d78 = Pic_Load_advfac64_0047c1fe
                           ((int *)g_DisplaySurfaceBackBuffer,0,0,(&DAT_00676dd0)[color_mask]);
  DAT_00676d7c = Pic_Load_advfac64_0047c1fe
                           ((int *)g_DisplaySurfaceBackBuffer,0,0,(&DAT_00676d80)[color_mask]);
  FUN_0050fc20();
  return DAT_00676d78;
}



/*
 * Decompiled function: FUN_0047c360
 * Entry Point: 0047c360
 * Size: 716 bytes
 */


int FUN_0047c360(char *str_1,uint arg_2,uint arg_3)

{
  uint uVar1;
  size_t sVar2;
  
  sVar2 = DAT_00676dc8;
  if ((int)arg_2 < 0xf0a) {
    if (arg_2 == 0xf09) {
      DAT_00676dc8 = DAT_00676dc8 + 8;
      if ((int)DAT_00676dc8 < (int)arg_3) {
        return 0;
      }
      DAT_00676dc8 = arg_3;
      return 0;
    }
    if (arg_2 == 0xe08) {
      if (DAT_00676dc8 == 0) {
        return 0;
      }
      DAT_00676dc8 = DAT_00676dc8 - 1;
      strcpy(str_1 + DAT_00676dc8,str_1 + sVar2);
      return 0;
    }
  }
  else if ((int)arg_2 < 0x1c0e) {
    if (arg_2 == 0x1c0d) {
      return 1;
    }
    if (arg_2 == 0xf0f) {
      DAT_00676dc8 = DAT_00676dc8 - 8;
      if (0 < (int)DAT_00676dc8) {
        return 0;
      }
      DAT_00676dc8 = 0;
      return 0;
    }
  }
  else if ((int)arg_2 < 0x4b01) {
    if (arg_2 == 0x4b00) {
      if ((int)DAT_00676dc8 < 0) {
        return 0;
      }
      DAT_00676dc8 = DAT_00676dc8 - 1;
      return 0;
    }
    if (arg_2 == 0x4700) {
      DAT_00676dc8 = 0;
      return 0;
    }
  }
  else if ((int)arg_2 < 0x4f01) {
    if (arg_2 == 0x4f00) {
      DAT_00676dc8 = strlen(str_1);
      return 0;
    }
    if (arg_2 == 0x4d00) {
      if ((int)arg_3 <= (int)DAT_00676dc8) {
        return 0;
      }
      sVar2 = strlen(str_1);
      if (sVar2 == DAT_00676dc8) {
        strcat(str_1,&DAT_00526b7c);
      }
      DAT_00676dc8 = DAT_00676dc8 + 1;
      return 0;
    }
  }
  else {
    if (arg_2 == 0x5200) {
      DAT_00676dc4 = DAT_00676dc4 ^ 1;
      return 0;
    }
    if (arg_2 == 0x5300) {
      sVar2 = strlen(str_1);
      if ((int)sVar2 <= (int)DAT_00676dc8) {
        return 0;
      }
      strcpy(str_1 + DAT_00676dc8,str_1 + DAT_00676dc8 + 1);
      return 0;
    }
  }
  sVar2 = strlen(str_1);
  if ((sVar2 < arg_3) &&
     ((((uVar1 = arg_2 & 0xff, 0x40 < uVar1 && (uVar1 < 0x5b)) || ((0x60 < uVar1 && (uVar1 < 0x7b)))
       ) || (((0x2f < uVar1 && (uVar1 < 0x3a)) || (uVar1 == 0x20)))))) {
    if (DAT_00676dc4 != 0) {
      memmove(str_1 + DAT_00676dc8 + 1,str_1 + DAT_00676dc8,(arg_3 - DAT_00676dc8) - 1);
    }
    str_1[DAT_00676dc8] = (char)arg_2;
    DAT_00676dc8 = DAT_00676dc8 + 1;
  }
  return 0;
}



/*
 * Decompiled function: UI_Register_sPoison_0047c640
 * Entry Point: 0047c640
 * Size: 244 bytes
 */


int UI_Register_sPoison_0047c640(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_0047c7aa;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00539518 = CreatePopupMenu();
  sprintf(local_138,s__s_Poison_pic_00526b80,&DAT_006808d0);
  DAT_00539514 = Pic_Load_00423833(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00526b90,0);
  DAT_00539510 = CreateFontIndirectA(lplf);
  DAT_00539508 = 0x100004a;
  DAT_0053950c = 0x10000c9;
  return local_30;
}



/*
 * Decompiled function: FUN_0047c734
 * Entry Point: 0047c734
 * Size: 118 bytes
 */


void FUN_0047c734(void)

{
  if (DAT_00539518 != (HMENU)0x0) {
    DestroyMenu(DAT_00539518);
  }
  DAT_00539518 = (HMENU)0x0;
  if (DAT_00539514 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00539514);
  }
  DAT_00539514 = (HANDLE)0x0;
  if (DAT_00539510 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539510);
  }
  DAT_00539510 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_WndProc_0047c7aa
 * Entry Point: 0047c7aa
 * Size: 3059 bytes
 */


LRESULT UI_WndProc_0047c7aa(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  LONG LVar1;
  uint uVar2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int iVar3;
  LRESULT LVar4;
  int local_490;
  char local_48c [100];
  uint local_428;
  char local_424 [100];
  tagPOINT local_3c0;
  tagRECT local_3b8;
  char local_3a8 [264];
  HDC local_2a0;
  int local_29c;
  tagPAINTSTRUCT local_298;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  CHAR local_23c [12];
  tagRECT local_230;
  tagRECT local_220;
  tagMSG local_210;
  uint local_1f4;
  char local_1f0 [264];
  ULONG_PTR local_e8;
  uint local_e4;
  int local_e0;
  int local_dc;
  char local_d8 [100];
  char local_74 [100];
  LONG local_10;
  char *local_c;
  LONG local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      if (hwnd == DAT_006b2530) {
        local_240 = Ai_Subsystem_004b6fa6(0);
      }
      else {
        local_240 = Ai_Subsystem_004b6fa6(1);
      }
      wsprintfA(local_23c,&DAT_00526bdc,local_240);
      if (hwnd == DAT_006b2530) {
        local_248 = Ai_Subsystem_004b700c(0);
      }
      else {
        local_248 = Ai_Subsystem_004b700c(1);
      }
      if (local_240 != local_8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_248 != local_10) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      GetClientRect(hwnd,&local_220);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_2a0 = g_HdcBackBuffer;
      local_254 = SaveDC(g_HdcBackBuffer);
      local_c = (char *)GetWindowLongA(hwnd,8);
      FUN_004f3b5f((int)local_2a0,(int)&local_220,local_c);
      if (DAT_00539514 == (HANDLE)0x0) {
        sprintf(local_3a8,s__s_Poison_pic_00526be0,&DAT_006808d0);
        DAT_00539514 = (HANDLE)Pic_Load_00423833(local_3a8);
      }
      local_258 = (int)(local_220.right + (local_220.right >> 0x1f & 3U)) >> 2;
      local_29c = local_220.bottom / 3;
      local_244 = 0;
      local_250 = 0;
      for (local_24c = 0; local_24c < local_248; local_24c = local_24c + 1) {
        SetRect(&local_230,local_244,local_250,local_244 + local_258,local_250 + local_29c);
        FUN_004f3e29(local_2a0,&local_230,DAT_00539514);
        local_244 = local_244 + local_258;
        if (local_220.right < local_244 + local_258) {
          local_244 = 0;
          local_250 = local_250 + local_29c;
        }
      }
      SetMapMode(local_2a0,8);
      SetWindowExtEx(local_2a0,0x7d,100,(LPSIZE)0x0);
      SetViewportExtEx(local_2a0,local_220.right - local_220.left,local_220.bottom - local_220.top,
                       (LPSIZE)0x0);
      SelectObject(local_2a0,DAT_00539510);
      SetBkMode(local_2a0,1);
      SetRect(&local_220,0,0,0x7d,100);
      OffsetRect(&local_220,3,3);
      SetTextColor(local_2a0,DAT_0053950c);
      DrawTextA(local_2a0,local_23c,-1,&local_220,0x25);
      OffsetRect(&local_220,-3,-3);
      SetTextColor(local_2a0,DAT_00539508);
      DrawTextA(local_2a0,local_23c,-1,&local_220,0x25);
      RestoreDC(g_HdcBackBuffer,local_254);
      local_2a0 = BeginPaint(hwnd,&local_298);
      if (local_2a0 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_2a0);
        GetClientRect(hwnd,&local_220);
        if (DAT_0068a674 != 0) {
          hbr = GetStockObject(0);
          FillRect(local_2a0,&local_220,hbr);
          Sleep(200);
        }
        BitBlt(local_2a0,0,0,local_220.right,local_220.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_298);
        local_8 = local_240;
        SetWindowLongA(hwnd,0,local_240);
        local_10 = local_248;
        SetWindowLongA(hwnd,4,local_248);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,0,0);
      local_10 = 0;
      SetWindowLongA(hwnd,4,0);
      local_c = (char *)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      local_c = (char *)GetWindowLongA(hwnd,8);
      if (local_c != (HANDLE)0x0) {
        GDI_DestroyDIBSection_Magic(local_c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      local_428 = (uint)(hwnd != DAT_006b2530);
      if ((DAT_006b1578 != 0) && (iVar3 = FUN_00409cb2(local_428), iVar3 != 0)) {
        if (local_428 == 1) {
          Ai_Subsystem_004b6f49(local_424);
          sprintf(local_48c,s_Target__s_00526bf0);
        }
        else {
          strcpy(local_48c,s_Target_yourself_00526bfc);
        }
        AppendMenuA(DAT_00539518,0,0x66,local_48c);
      }
      iVar3 = GetMenuItemCount(DAT_00539518);
      if (0 < iVar3) {
        AppendMenuA(DAT_00539518,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00539518,0,100,s_Flip_over_to_face_00526c0c);
      AppendMenuA(DAT_00539518,0,0x65,s_Help____00526c20);
      return 0;
    }
    if (uMsg == 0x111) {
      uVar2 = (uint)wParam & 0xffff;
      if (uVar2 == 100) {
        FUN_00409b2c((uint)(hwnd != DAT_006b2530),1);
      }
      else if (uVar2 == 0x65) {
        local_e8 = 0x7e8;
        strcpy(local_1f0,&DAT_006807a0);
        strcat(local_1f0,s__duel_hlp_00526bd0);
        WinHelpA(g_MainAppHwnd,local_1f0,1,local_e8);
      }
      else if (uVar2 == 0x66) {
        local_e4 = (uint)(hwnd != DAT_006b2530);
        DAT_00627864 = 0;
        FUN_0047d3cf(local_e4);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      local_1f4 = (uint)(hwnd != DAT_006b2530);
      if (DAT_006b1578 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        DAT_00627864 = PeekMessageA(&local_210,hwnd,0x203,0x203,0);
        FUN_0047d3cf(local_1f4);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_490 = GetMenuItemCount(DAT_00539518);
        while (local_490 != 0) {
          DeleteMenu(DAT_00539518,0,0x400);
          local_490 = local_490 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x204) {
      local_3c0.x = lParam & 0xffff;
      local_3c0.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_3c0);
      SetRect(&local_3b8,local_3c0.x,local_3c0.y,local_3c0.x + 1,local_3c0.y + 1);
      TrackPopupMenu(DAT_00539518,2,local_3c0.x,local_3c0.y,0,hwnd,&local_3b8);
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x432:
      local_8 = GetWindowLongA(hwnd,0);
      if (hwnd == DAT_006b2530) {
        local_dc = Ai_Subsystem_004b6fa6(0);
      }
      else {
        local_dc = Ai_Subsystem_004b6fa6(1);
      }
      local_10 = GetWindowLongA(hwnd,4);
      if (hwnd == DAT_006b2530) {
        local_e0 = Ai_Subsystem_004b700c(0);
      }
      else {
        local_e0 = Ai_Subsystem_004b700c(1);
      }
      if (local_8 != local_dc) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_10 != local_e0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      local_10 = GetWindowLongA(hwnd,4);
      if (hwnd == DAT_006b2530) {
        strcpy(local_74,s_Your_00526b98);
      }
      else {
        Ai_Subsystem_004b6f49(local_74);
      }
      sprintf(local_d8,s__s_life_points_s_00526bbc,local_74,
              s_and_poison_counters_00526ba0 + ((local_10 != 0) - 1 & 0x18));
      strcpy(wParam,local_d8);
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      local_c = (char *)GetWindowLongA(hwnd,8);
      if (local_c != (HGDIOBJ)0x0) {
        DeleteObject(local_c);
      }
      local_c = wParam;
      SetWindowLongA(hwnd,8,(LONG)wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: FUN_0047d3cf
 * Entry Point: 0047d3cf
 * Size: 63 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047d3cf(int color_mask)

{
  _DAT_00539520 = 0;
  _DAT_00539524 = color_mask;
  _DAT_00539528 = 0xffffffff;
  PostMessageA(g_MainAppHwnd,0x464,0,0x539520);
  return;
}



/*
 * Decompiled function: FUN_0047d40e
 * Entry Point: 0047d40e
 * Size: 74 bytes
 */


int FUN_0047d40e(int color_mask)

{
  int uVar1;
  
  if (((color_mask == 1) && (DAT_006fefa0 != 0)) || ((color_mask == 0 && (DAT_006fefa4 != 0)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: UI_Register_WINBK_Attack_0047d460
 * Entry Point: 0047d460
 * Size: 1020 bytes
 */


int UI_Register_WINBK_Attack_0047d460(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_Register_MAGICGAME_CardClass_0047da80;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 0x801;
  local_2c.lpfnWndProc = UI_WndProc_004822b7;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackSwordShield_00526c2c;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_WndProc_00482dd6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackMinimized_00526c40;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_0053955c = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_Attack_pic_00526c50);
  DAT_00539590 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackSword_pic_00526c64);
  DAT_00539534 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackShield_pic_00526c7c);
  DAT_00539564 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackBones_pic_00526c94);
  DAT_00539544 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackRats_pic_00526cac);
  DAT_00539530 = Pic_Load_00423833(local_138);
  DAT_00526c28 = 6;
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_AttackMin_pic_00526cc4);
  DAT_0053957c = Pic_Load_00423833(local_138);
  DAT_00539550 = CreatePen(0,0,0x10000b4);
  DAT_00539580 = CreatePen(0,0,0x100007c);
  DAT_0053953c = CreatePen(0,0,0x1000050);
  DAT_00539558 = CreateSolidBrush(0x1000076);
  DAT_00539568 = CreatePen(0,0,0x10000d3);
  DAT_0053956c = CreatePen(0,0,0x100002f);
  DAT_00539548 = CreatePen(0,0,0x10000d7);
  DAT_00539578 = CreateSolidBrush(0x100003a);
  DAT_0053954c = 0x10000bf;
  DAT_0053958c = 0x10000c9;
  if (((((DAT_00539550 == (HPEN)0x0) || (DAT_00539580 == (HPEN)0x0)) || (DAT_0053953c == (HPEN)0x0))
      || ((DAT_00539558 == (HBRUSH)0x0 || (DAT_00539568 == (HPEN)0x0)))) ||
     ((DAT_0053956c == (HPEN)0x0 || ((DAT_00539548 == (HPEN)0x0 || (DAT_00539578 == (HBRUSH)0x0)))))
     ) {
    local_30 = 0;
  }
  return local_30;
}



/*
 * Decompiled function: FUN_0047d85c
 * Entry Point: 0047d85c
 * Size: 548 bytes
 */


void FUN_0047d85c(void)

{
  if (DAT_0053955c != (HMENU)0x0) {
    DestroyMenu(DAT_0053955c);
  }
  DAT_0053955c = (HMENU)0x0;
  if (DAT_00539590 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00539590);
  }
  if (DAT_00539534 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00539534);
  }
  if (DAT_00539564 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00539564);
  }
  if (DAT_00539544 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00539544);
  }
  if (DAT_00539530 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00539530);
  }
  if (DAT_0053957c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0053957c);
  }
  if (DAT_00539550 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539550);
  }
  if (DAT_00539580 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539580);
  }
  if (DAT_0053953c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053953c);
  }
  if (DAT_00539558 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539558);
  }
  if (DAT_00539568 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539568);
  }
  if (DAT_0053956c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053956c);
  }
  if (DAT_00539548 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539548);
  }
  if (DAT_00539578 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539578);
  }
  DAT_00539590 = (HANDLE)0x0;
  DAT_00539534 = (HANDLE)0x0;
  DAT_00539564 = (HANDLE)0x0;
  DAT_00539544 = (HANDLE)0x0;
  DAT_00539530 = (HANDLE)0x0;
  DAT_0053957c = (HANDLE)0x0;
  DAT_00539550 = (HGDIOBJ)0x0;
  DAT_00539580 = (HGDIOBJ)0x0;
  DAT_0053953c = (HGDIOBJ)0x0;
  DAT_00539558 = (HGDIOBJ)0x0;
  DAT_00539568 = (HGDIOBJ)0x0;
  DAT_0053956c = (HGDIOBJ)0x0;
  DAT_00539548 = (HGDIOBJ)0x0;
  DAT_00539578 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_Register_MAGICGAME_CardClass_0047da80
 * Entry Point: 0047da80
 * Size: 14661 bytes
 */


uint UI_Register_MAGICGAME_CardClass_0047da80(HWND hwnd,uint y,HWND param_3,HWND param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  LONG LVar4;
  HWND pHVar5;
  HWND pHVar6;
  HBRUSH hbr;
  HGDIOBJ pvVar7;
  uint uVar8;
  UINT UVar9;
  HMENU hMenu;
  WPARAM wParam;
  HINSTANCE hInstance;
  LPARAM LVar10;
  LPVOID lpParam;
  int local_598;
  tagPOINT local_594;
  tagRECT local_58c;
  uint local_57c;
  int local_574;
  HGDIOBJ local_570;
  tagRECT local_56c;
  HBITMAP local_55c;
  CHAR local_558 [100];
  HBRUSH local_4f4;
  HDC local_4f0;
  uint8_t local_4ec [4];
  int local_4e8;
  int local_4e4;
  int local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c8;
  int local_4c4;
  int local_4c0;
  uint local_4bc;
  tagRECT local_4b8;
  tagRECT local_4a8;
  HGDIOBJ local_498;
  tagRECT local_494;
  int local_484;
  HGDIOBJ local_480;
  HWND local_47c;
  int local_474;
  uint local_470;
  tagRECT local_46c;
  int local_45c;
  HWND local_454;
  int local_450;
  uint local_44c;
  uint local_448;
  int local_444;
  tagRECT local_440;
  tagRECT local_430;
  HWND local_420;
  uint local_41c;
  uint local_418;
  char local_414 [264];
  HWND local_30c;
  uint8_t local_308 [4];
  int local_304;
  tagRECT local_2f0;
  tagRECT local_2e0;
  LRESULT local_2d0;
  HWND local_2cc;
  char local_2c8 [264];
  ULONG_PTR local_1c0;
  int local_1bc;
  uint8_t local_1b8 [4];
  int local_1b4;
  int local_1b0;
  int local_1a0;
  int local_19c;
  int local_198;
  tagRECT local_194;
  LPARAM local_184;
  int local_180 [2];
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  uint local_168;
  HWND local_164;
  int local_160;
  int local_15c;
  int local_158;
  uint local_154;
  uint local_150;
  int local_14c;
  uint local_148;
  HWND local_144;
  uint local_140;
  int local_13c;
  int local_138;
  HWND local_134;
  HWND local_130;
  int local_12c;
  int local_128;
  HWND local_124;
  uint local_120;
  int local_118;
  int local_114;
  HWND local_110;
  uint local_10c;
  int local_108;
  int local_104;
  int local_100;
  HWND local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  HWND local_e8;
  uint local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  HWND local_c8;
  tagRECT local_c4;
  HWND local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  HWND local_a4;
  HWND local_a0;
  int local_9c;
  int local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_88;
  int local_84;
  int local_80;
  int local_7c;
  uint local_78;
  int local_74;
  HWND local_70;
  HWND local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  HWND local_4c;
  int local_48;
  int local_44;
  int local_40;
  tagPOINT local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  tagRECT local_24;
  int local_14;
  HWND local_10;
  void *local_c;
  LONG local_8;
  
  if (y == 0x464) {
    local_2c = param_3;
    local_c = (void *)GetWindowLongA(hwnd,0);
    local_8 = GetWindowLongA(hwnd,4);
    local_10 = GetDlgItem(hwnd,0);
    local_14 = 0;
    local_30 = 0;
    while ((local_30 < local_8 && (local_14 == 0))) {
      if (*(HWND *)((int)local_c + local_30 * 0x19c) == local_2c) {
        local_14 = 1;
        local_28 = 5000;
        local_40 = -5000;
        for (local_34 = 0; local_34 < *(int *)((int)local_c + 0xcc + local_30 * 0x19c);
            local_34 = local_34 + 1) {
          GetWindowRect(*(HWND *)(local_34 * 4 + local_30 * 0x19c + 4 + (int)local_c),&local_24);
          if (local_24.left < local_28) {
            local_28 = local_24.left;
          }
          if (local_40 < local_24.right) {
            local_40 = local_24.right;
          }
        }
        for (local_34 = 0; local_34 < *(int *)((int)local_c + 0x198 + local_30 * 0x19c);
            local_34 = local_34 + 1) {
          GetWindowRect(*(HWND *)(local_34 * 4 + local_30 * 0x19c + 0xd0 + (int)local_c),&local_24);
          if (local_24.left < local_28) {
            local_28 = local_24.left;
          }
          if (local_40 < local_24.right) {
            local_40 = local_24.right;
          }
        }
      }
      local_30 = local_30 + 1;
    }
    if (local_14 != 0) {
      GetWindowRect(hwnd,&local_24);
      if (local_28 < local_24.left) {
        local_3c.x = local_28;
        local_3c.y = 0;
        ScreenToClient(hwnd,&local_3c);
      }
      else if (local_24.right < local_40) {
        local_3c.x = local_28;
        local_3c.y = 0;
        ScreenToClient(hwnd,&local_3c);
      }
    }
    return 0;
  }
  if (y < 7) {
    if (y == 6) {
      if ((((uint)param_3 & 0xffff) == 1) || (((uint)param_3 & 0xffff) == 2)) {
        SendMessageA(DAT_006b2e24,0x86,1,0);
      }
      else {
        SendMessageA(DAT_006b2e24,0x86,0,0);
      }
      uVar8 = DefWindowProcA(hwnd,6,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    if (y == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,4,0);
      local_c = malloc(0xa0f0);
      SetWindowLongA(hwnd,0,(LONG)local_c);
      local_2cc = CreateWindowExA(0,s_MAGICGAME_ScrollbarClass_00526d34,&DAT_00526d30,0x50000000,0,0
                                  ,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (local_2cc != (HWND)0x0) {
        SendMessageA(local_2cc,0x464,DAT_00539544,1);
        SendMessageA(local_2cc,0x466,DAT_00539530,DAT_00526c28);
      }
      lpParam = (LPVOID)0x0;
      hMenu = (HMENU)0x0;
      hInstance = g_AppHInstance;
      pHVar6 = GetParent(hwnd);
      DAT_006b2e24 = CreateWindowExA(0,s_AttackSwordShield_00526d54,&DAT_00526d50,0x80c00000,0,0,0,0
                                     ,pHVar6,hMenu,hInstance,lpParam);
      DAT_00539540 = CreateWindowExA(0,s_AttackMinimized_00526d6c,&DAT_00526d68,0x80000000,0,0,0,0,
                                     hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if ((((local_c != (void *)0x0) && (local_2cc != (HWND)0x0)) && (DAT_006b2e24 != (HWND)0x0)) &&
         (DAT_00539540 != (HWND)0x0)) {
        return 0;
      }
      if (local_c != (void *)0x0) {
        free(local_c);
      }
      return 0xffffffff;
    }
    if (y == 2) {
      local_c = (void *)GetWindowLongA(hwnd,0);
      free(local_c);
      return 0;
    }
  }
  else if (y < 0x15) {
    if (y == 0x14) {
      local_30c = param_3;
      GDI_RealizeAndFlushPalette_Magic((HDC)param_3);
      GetClientRect(hwnd,&local_2e0);
      local_2d0 = SendDlgItemMessageA(hwnd,0,0xe1,0,0);
      if (DAT_00539590 == (HANDLE)0x0) {
        strcpy(local_414,&DAT_006b2e90);
        strcat(local_414,s__WINBK_Attack_pic_00526d7c);
        DAT_00539590 = (HANDLE)Pic_Load_00423833(local_414);
      }
      if (DAT_00539590 == (HANDLE)0x0) {
        hbr = GetStockObject(4);
        FillRect((HDC)local_30c,&local_2e0,hbr);
      }
      else {
        CopyRect(&local_2f0,&local_2e0);
        GetObjectA(DAT_00539590,0x18,local_308);
        local_2f0.left = -(local_2d0 % local_304);
        FUN_004f3d11((HDC)local_30c,&local_2f0.left,DAT_00539590);
      }
      return 1;
    }
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00539540,0);
      return 0;
    }
  }
  else if (y < 0x21) {
    if (y == 0x20) {
      uVar8 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    if (y == 0x18) {
      if (param_3 == (HWND)0x0) {
        ShowWindow(DAT_006b2e24,0);
      }
      else {
        ShowWindow(DAT_006b2e24,5);
      }
      PostMessageA(DAT_007006b0,0x403,0,0);
      uVar8 = DefWindowProcA(hwnd,0x18,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      local_47c = param_3;
      if (param_3 == (HWND)0x8) {
        SendMessageA(hwnd,0x111,0x65,0);
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0xa1,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    switch(y) {
    case 0x83:
      local_454 = param_4;
      local_45c = param_4->unused;
      uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      local_454->unused = local_45c;
      return uVar8;
    case 0x84:
      local_470 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      if (local_470 != 2) {
        return local_470;
      }
      local_474 = GetSystemMetrics(0x1e);
      GetClientRect(hwnd,&local_46c);
      MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_46c,2);
      return 8;
    case 0x85:
    case 0x86:
      GetWindowRect(hwnd,&local_494);
      OffsetRect(&local_494,-local_494.left,-local_494.top);
      if ((local_494.right != local_494.left) && (local_494.bottom != local_494.top)) {
        local_4bc = (uint)(y != 0x85);
        local_4f0 = GetWindowDC(hwnd);
        if (local_4f0 == (HDC)0x0) {
          return local_4bc;
        }
        GDI_RealizeAndFlushPalette_Magic(local_4f0);
        GetWindowRect(hwnd,&local_494);
        GetClientRect(hwnd,&local_56c);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_56c,2);
        OffsetRect(&local_56c,-local_494.left,-local_494.top);
        OffsetRect(&local_494,-local_494.left,-local_494.top);
        GetWindowTextA(hwnd,local_558,100);
        local_574 = local_494.right - local_56c.right;
        local_4c4 = local_494.bottom - local_56c.bottom;
        Ai_Subsystem_004b74b1(&local_484,(int *)0x0);
        if (local_484 == 0) {
          local_498 = DAT_00539550;
          local_570 = DAT_00539580;
          local_480 = DAT_0053953c;
          local_4f4 = DAT_00539558;
        }
        else {
          local_498 = DAT_00539568;
          local_570 = DAT_0053956c;
          local_480 = DAT_00539548;
          local_4f4 = DAT_00539578;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = 0;
        MoveToEx(local_4f0,0,0,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right + -1,local_4c8);
        SelectObject(local_4f0,local_498);
        local_4c8 = 1;
        for (local_4cc = 1; local_4cc <= local_4c4 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
          LineTo(local_4f0,(local_494.right - local_574) + 1,local_4c8);
          local_4c8 = local_4c8 + 1;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = local_4c4 + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_56c.right + 1,local_4c8);
        pvVar7 = GetStockObject(7);
        SelectObject(local_4f0,pvVar7);
        local_4c0 = local_494.right + -1;
        MoveToEx(local_4f0,local_4c0,0,(LPPOINT)0x0);
        LineTo(local_4f0,local_4c0,local_494.bottom);
        SelectObject(local_4f0,local_480);
        local_4c0 = local_494.right + -2;
        for (local_4cc = 1; local_4cc <= local_574 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,local_4c0,1,(LPPOINT)0x0);
          LineTo(local_4f0,local_4c0,local_494.bottom + -1);
          local_4c0 = local_4c0 + -1;
        }
        SelectObject(local_4f0,local_570);
        local_4c0 = local_56c.right;
        MoveToEx(local_4f0,local_56c.right,local_4c4 + -1,(LPPOINT)0x0);
        LineTo(local_4f0,local_4c0,local_56c.bottom + 1);
        pvVar7 = GetStockObject(7);
        SelectObject(local_4f0,pvVar7);
        local_4c8 = local_494.bottom + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right,local_4c8);
        SelectObject(local_4f0,local_480);
        local_4c8 = local_494.bottom + -2;
        for (local_4cc = 1; local_4cc <= local_4c4 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
          LineTo(local_4f0,local_494.right + -1,local_4c8);
          local_4c8 = local_4c8 + -1;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = local_494.bottom - local_4c4;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right + -2,local_4c8);
        SelectObject(local_4f0,local_570);
        local_4c8 = local_56c.top + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_56c.right + 1,local_4c8);
        SetRect(&local_4a8,0,local_4c4,local_56c.right,local_56c.top + -1);
        FillRect(local_4f0,&local_4a8,local_4f4);
        SetBkMode(local_4f0,1);
        OffsetRect(&local_4a8,1,1);
        SetTextColor(local_4f0,DAT_0053958c);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        OffsetRect(&local_4a8,-1,-1);
        SetTextColor(local_4f0,DAT_0053954c);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        local_55c = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fed);
        GetObjectA(local_55c,0x18,local_4ec);
        local_4d0 = local_4e8;
        local_4d4 = local_4e4;
        SetRect(&local_4b8,local_56c.right - local_4e8,local_56c.top - local_4e4,local_56c.right,
                local_56c.top);
        FUN_004f3b5f((int)local_4f0,(int)&local_4b8,DAT_0053957c);
        DeleteObject(local_55c);
        ReleaseDC(hwnd,local_4f0);
        return local_4bc;
      }
      uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      uVar8 = (uint)param_3 & 0xffff;
      if (uVar8 == 100) {
        local_1c0 = 0xbbc;
        strcpy(local_2c8,&DAT_006807a0);
        strcat(local_2c8,s__duel_hlp_00526d24);
        WinHelpA(g_MainAppHwnd,local_2c8,1,local_1c0);
      }
      else if (uVar8 == 0x65) {
        ShowWindow(hwnd,0);
        UpdateWindow(DAT_006b2e2c);
        GetWindowRect(DAT_006a284c,&local_194);
        local_198 = local_194.left;
        local_1a0 = local_194.right - local_194.left;
        if (DAT_0053957c == (HANDLE)0x0) {
          local_1bc = local_1a0 * 2;
        }
        else {
          GetObjectA(DAT_0053957c,0x18,local_1b8);
          local_1bc = (local_1b0 * local_1a0) / local_1b4;
        }
        local_19c = (local_194.bottom - local_194.top) / 2 + local_1bc / 2 + 2;
        MoveWindow(DAT_00539540,local_198,local_19c,local_1a0,local_1bc,1);
        ShowWindow(DAT_00539540,5);
        BringWindowToTop(DAT_00539540);
        SendMessageA(DAT_007006b0,0x403,0,0);
      }
      else if (uVar8 == 0x66) {
        ShowWindow(DAT_00539540,0);
        ShowWindow(hwnd,5);
        SendMessageA(DAT_007006b0,0x403,0,0);
        FUN_004f59f7();
      }
      return 0;
    }
    if (y == 0xa4) {
LAB_004810c3:
      local_594.x = (uint)param_4 & 0xffff;
      local_594.y = (uint)param_4 >> 0x10;
      if (y == 0x204) {
        ClientToScreen(hwnd,&local_594);
      }
      SetRect(&local_58c,local_594.x,local_594.y,local_594.x + 1,local_594.y + 1);
      TrackPopupMenu(DAT_0053955c,2,local_594.x,local_594.y,0,hwnd,&local_58c);
      return 0;
    }
  }
  else if (y < 0x120) {
    if (y == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (param_4 == (HWND)0x0)) {
        local_598 = GetMenuItemCount(DAT_0053955c);
        while (local_598 != 0) {
          DeleteMenu(DAT_0053955c,0,0x400);
          local_598 = local_598 + -1;
        }
      }
      return 0;
    }
    if (y == 0x112) {
      local_57c = (uint)param_3 & 0xfff0;
      if (local_57c == 0xf010) {
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0x112,(WPARAM)param_3,(LPARAM)param_4);
      return uVar8;
    }
    if (y == 0x114) {
      local_420 = GetDlgItem(hwnd,0);
      SendMessageA(local_420,0xe3,(WPARAM)&local_448,(LPARAM)&local_41c);
      local_44c = SendMessageA(local_420,0xe1,0,0);
      local_444 = DAT_006a28b0;
      GetClientRect(hwnd,&local_430);
      local_450 = local_430.right;
      switch((uint)param_3 & 0xffff) {
      case 0:
        local_418 = local_44c - local_444;
        break;
      case 1:
        local_418 = local_444 + local_44c;
        break;
      case 2:
        local_418 = local_44c - local_430.right;
        break;
      case 3:
        local_418 = local_430.right + local_44c;
        break;
      case 4:
      case 5:
        local_418 = (uint)param_3 >> 0x10;
        break;
      case 6:
        local_418 = local_448;
        break;
      case 7:
        local_418 = local_41c;
        break;
      default:
        local_418 = local_44c;
      }
      if ((int)local_418 < (int)local_448) {
        local_418 = local_448;
      }
      if ((int)local_41c < (int)local_418) {
        local_418 = local_41c;
      }
      if (local_418 != local_44c) {
        SendMessageA(local_420,0xe0,local_418,1);
        GetWindowRect(local_420,&local_440);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_440,2);
        ScrollWindow(hwnd,local_44c - local_418,0,(RECT *)0x0,(RECT *)0x0);
        MoveWindow(local_420,local_440.left,local_440.top,local_440.right - local_440.left,
                   local_440.bottom - local_440.top,0);
        UpdateWindow(hwnd);
      }
      return 0;
    }
    if (y == 0x117) {
      AppendMenuA(DAT_0053955c,0,0x65,s__Minimize_00526d90);
      AppendMenuA(DAT_0053955c,0,100,s_Help____00526d9c);
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_004810c3;
    if (y == 0x201) {
      return 0;
    }
  }
  else if (y < 0x402) {
    if (0x3ff < y) {
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_88 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      FUN_00483139(hwnd,&param_3->unused,(int *)0x0,&local_8c,&local_84);
      if ((local_8c == (HWND)0x0) ||
         (((local_84 == 0 || (y != 0x400)) && ((local_84 != 0 || (y != 0x401)))))) {
        local_7c = 0;
      }
      else {
        local_7c = 1;
      }
      if (local_7c == 0) {
        local_8c = CreateWindowExA(0,s_MAGICGAME_CardClass_00526cec,s_Card_in_attack_00526cdc,
                                   0x54000000,0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,local_88);
        if (local_8c == (HWND)0x0) {
          return 0;
        }
        if (y == 0x400) {
          local_80 = Ai_Subsystem_004b5b6f(local_88->unused,local_88[1].unused);
          if (local_80 == -1) {
            local_80 = local_88[1].unused;
          }
        }
        else {
          local_80 = Ai_Subsystem_004b5b6f(local_88->unused,local_88[1].unused);
        }
        local_90 = 0;
        local_7c = 0;
        while ((local_90 < local_8 && (local_7c == 0))) {
          if (*(int *)((int)local_c + local_90 * 0x19c) == local_80) {
            local_7c = 1;
            if ((y == 0x400) && (*(int *)((int)local_c + 0xcc + local_90 * 0x19c) < 0x32)) {
              *(HWND *)(local_90 * 0x19c + *(int *)((int)local_c + 0xcc + local_90 * 0x19c) * 4 + 4
                       + (int)local_c) = local_8c;
              piVar1 = (int *)((int)local_c + 0xcc + local_90 * 0x19c);
              *piVar1 = *piVar1 + 1;
            }
            else {
              if ((y != 0x401) || (0x31 < *(int *)((int)local_c + 0x198 + local_90 * 0x19c))) {
                DestroyWindow(local_8c);
                return 0;
              }
              *(HWND *)(local_90 * 0x19c + *(int *)((int)local_c + 0x198 + local_90 * 0x19c) * 4 +
                        0xd0 + (int)local_c) = local_8c;
              piVar1 = (int *)((int)local_c + 0x198 + local_90 * 0x19c);
              *piVar1 = *piVar1 + 1;
            }
          }
          local_90 = local_90 + 1;
        }
        if (local_7c == 0) {
          if (99 < local_8) {
            DestroyWindow(local_8c);
            return 0;
          }
          *(int *)((int)local_c + local_8 * 0x19c) = local_80;
          if (y == 0x400) {
            *(HWND *)((int)local_c + 4 + local_8 * 0x19c) = local_8c;
            *(int *)((int)local_c + 0xcc + local_8 * 0x19c) = 1;
            *(int *)((int)local_c + 0x198 + local_8 * 0x19c) = 0;
          }
          else {
            *(HWND *)((int)local_c + 0xd0 + local_8 * 0x19c) = local_8c;
            *(int *)((int)local_c + 0x198 + local_8 * 0x19c) = 1;
            *(int *)((int)local_c + 0xcc + local_8 * 0x19c) = 0;
          }
          local_8 = local_8 + 1;
          SetWindowLongA(hwnd,4,local_8);
        }
        BringWindowToTop(local_8c);
      }
      return 1;
    }
    if ((0x30e < y) && (y < 0x312)) {
      uVar8 = GDI_RealizePaletteTree_Magic(hwnd,y,param_3,param_4);
      return uVar8;
    }
  }
  else {
    switch(y) {
    case 0x402:
    case 0x403:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_fc = param_3;
      if (param_3 == (HWND)0x0) {
        local_e8 = param_4;
      }
      else {
        FUN_00483139(hwnd,&param_3->unused,(int *)0x0,&local_e8,(int *)0x0);
      }
      if ((local_e8 != (HWND)0x0) && (pHVar6 = GetParent(local_e8), pHVar6 == hwnd)) {
        for (local_ec = 0; local_ec < local_8; local_ec = local_ec + 1) {
          local_e4 = 0;
          local_f0 = 0;
          while ((local_f0 < *(int *)((int)local_c + 0xcc + local_ec * 0x19c) && (local_e4 == 0))) {
            if ((y == 0x403) &&
               (*(HWND *)(local_ec * 0x19c + local_f0 * 4 + 4 + (int)local_c) == local_e8)) {
              local_e4 = 1;
              FUN_00481491((int)local_e8,local_ec * 0x19c + (int)local_c + 4,
                           *(int *)((int)local_c + 0xcc + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)local_c + 0xcc + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)local_c) != 0) {
                  *(int *)(local_ec * 0x19c + local_f8 * 4 + 4 + (int)local_c) =
                       *(int *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)local_c);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)local_c + 0xcc + local_ec * 0x19c) = local_f8;
            }
            else if ((y == 0x402) &&
                    (*(HWND *)(local_ec * 0x19c + local_f0 * 4 + 0xd0 + (int)local_c) == local_e8))
            {
              local_e4 = 1;
              FUN_00481491((int)local_e8,local_ec * 0x19c + (int)local_c + 0xd0,
                           *(int *)((int)local_c + 0x198 + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)local_c + 0x198 + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)local_c) != 0) {
                  *(int *)(local_ec * 0x19c + local_f8 * 4 + 0xd0 + (int)local_c) =
                       *(int *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)local_c);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)local_c + 0x198 + local_ec * 0x19c) = local_f8;
            }
            local_f0 = local_f0 + 1;
          }
        }
        return local_e4;
      }
      return 0;
    case 0x404:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_134 = param_3;
      local_130 = param_4;
      if ((param_4 != (HWND)0x0) && (param_3 != (HWND)0xffffffff)) {
        local_140 = 0;
        for (local_138 = 0; local_138 < local_8; local_138 = local_138 + 1) {
          if (*(HWND *)((int)local_c + local_138 * 0x19c) == local_134) {
            for (local_13c = 0; local_13c < *(int *)((int)local_c + 0xcc + local_138 * 0x19c);
                local_13c = local_13c + 1) {
              iVar3 = FUN_0046bc92(*(HWND *)(local_138 * 0x19c + local_13c * 4 + 4 + (int)local_c));
              if (iVar3 == 0) {
                local_130[local_140].unused =
                     *(int *)(local_138 * 0x19c + local_13c * 4 + 4 + (int)local_c);
                local_140 = local_140 + 1;
              }
            }
          }
        }
        return local_140;
      }
      return 0;
    case 0x405:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_124 = param_3;
      if ((param_3 == (HWND)0x0) || (pHVar6 = GetParent(param_3), pHVar6 != hwnd)) {
        return 0xffffffff;
      }
      bVar2 = false;
      for (local_128 = 0; local_128 < local_8; local_128 = local_128 + 1) {
        local_12c = 0;
        while ((local_12c < *(int *)((int)local_c + 0xcc + local_128 * 0x19c) && (!bVar2))) {
          if (*(HWND *)(local_12c * 4 + local_128 * 0x19c + 4 + (int)local_c) == local_124) {
            bVar2 = true;
            local_120 = 1;
          }
          local_12c = local_12c + 1;
        }
        local_12c = 0;
        while ((local_12c < *(int *)((int)local_c + 0x198 + local_128 * 0x19c) && (!bVar2))) {
          if (*(HWND *)(local_12c * 4 + local_128 * 0x19c + 0xd0 + (int)local_c) == local_124) {
            bVar2 = true;
            local_120 = 0;
          }
          local_12c = local_12c + 1;
        }
      }
      if (bVar2) {
        return local_120;
      }
      return 0xffffffff;
    case 0x406:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_a0 = param_3;
      local_94 = param_4;
      if (((param_3 == (HWND)0x0) || (param_4 == (HWND)0x0)) ||
         (pHVar6 = GetParent(param_4), pHVar6 != hwnd)) {
        return 0;
      }
      iVar3 = FUN_00483139(hwnd,&local_a0->unused,(int *)0x0,(int *)0x0,
                           (int *)0x0);
      if (iVar3 != 0) {
        return 1;
      }
      local_a8 = 0;
      local_ac = 0;
      while ((local_ac < local_8 && (local_a8 == 0))) {
        local_b0 = 0;
        while ((local_b0 < *(int *)((int)local_c + 0xcc + local_ac * 0x19c) && (local_a8 == 0))) {
          if (*(HWND *)(local_b0 * 4 + local_ac * 0x19c + 4 + (int)local_c) == local_94) {
            local_a8 = 1;
            local_98 = local_ac;
            local_9c = 1;
          }
          local_b0 = local_b0 + 1;
        }
        local_b0 = 0;
        while ((local_b0 < *(int *)((int)local_c + 0x198 + local_ac * 0x19c) && (local_a8 == 0))) {
          if (*(HWND *)(local_b0 * 4 + local_ac * 0x19c + 0xd0 + (int)local_c) == local_94) {
            local_a8 = 1;
            local_98 = local_ac;
            local_9c = 0;
          }
          local_b0 = local_b0 + 1;
        }
        local_ac = local_ac + 1;
      }
      if (local_a8 == 0) {
        return 0;
      }
      local_a4 = CreateWindowExA(0,s_MAGICGAME_CardClass_00526d10,s_Card_in_attack_00526d00,
                                 0x54000000,0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,local_a0);
      if (local_a4 == (HWND)0x0) {
        return 0;
      }
      SendMessageA(local_a4,0x402,(WPARAM)local_94,0);
      if ((local_9c == 0) || (0x31 < *(int *)((int)local_c + 0xcc + local_98 * 0x19c))) {
        if ((local_9c != 0) || (0x31 < *(int *)((int)local_c + 0x198 + local_98 * 0x19c))) {
          DestroyWindow(local_a4);
          return 0;
        }
        *(HWND *)(local_98 * 0x19c + *(int *)((int)local_c + 0x198 + local_98 * 0x19c) * 4 + 0xd0 +
                 (int)local_c) = local_a4;
        piVar1 = (int *)((int)local_c + 0x198 + local_98 * 0x19c);
        *piVar1 = *piVar1 + 1;
      }
      else {
        *(HWND *)(local_98 * 0x19c + *(int *)((int)local_c + 0xcc + local_98 * 0x19c) * 4 + 4 +
                 (int)local_c) = local_a4;
        piVar1 = (int *)((int)local_c + 0xcc + local_98 * 0x19c);
        *piVar1 = *piVar1 + 1;
      }
      return 1;
    case 0x40c:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00539540,0);
      for (local_100 = 0; local_100 < local_8; local_100 = local_100 + 1) {
        for (local_104 = 0; local_104 < *(int *)((int)local_c + 0xcc + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 4 + (int)local_c));
        }
        *(int *)((int)local_c + 0xcc + local_100 * 0x19c) = 0;
        for (local_104 = 0; local_104 < *(int *)((int)local_c + 0x198 + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 0xd0 + (int)local_c));
        }
        *(int *)((int)local_c + 0x198 + local_100 * 0x19c) = 0;
      }
      local_8 = 0;
      SetWindowLongA(hwnd,4,0);
      LVar10 = 1;
      wParam = 0;
      UVar9 = 0xe0;
      pHVar6 = GetDlgItem(hwnd,0);
      SendMessageA(pHVar6,UVar9,wParam,LVar10);
      return 0;
    case 0x40e:
    case 0x40f:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_110 = param_3;
      if (param_3 == (HWND)0x0) {
        local_108 = 0;
      }
      else {
        local_108 = 0;
        for (local_114 = 0; local_114 < local_8; local_114 = local_114 + 1) {
          local_118 = 0;
          while ((local_118 < *(int *)((int)local_c + 0xcc + local_114 * 0x19c) && (local_108 == 0))
                ) {
            iVar3 = FUN_0046bb29(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)local_c),
                                 &local_110->unused);
            if (iVar3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0046bc2f(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 +
                                                  (int)local_c));
              }
              else {
                local_10c = *(uint *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)local_c);
              }
            }
            local_118 = local_118 + 1;
          }
          local_118 = 0;
          while ((local_118 < *(int *)((int)local_c + 0x198 + local_114 * 0x19c) && (local_108 == 0)
                 )) {
            iVar3 = FUN_0046bb29(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)local_c),
                                 &local_110->unused);
            if (iVar3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0046bc2f(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 +
                                                  (int)local_c));
              }
              else {
                local_10c = *(uint *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)local_c);
              }
            }
            local_118 = local_118 + 1;
          }
        }
      }
      if (local_108 != 0) {
        return local_10c;
      }
      if (y == 0x40e) {
        return 0xffffffff;
      }
      return 0;
    case 0x410:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_c8 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_dc = 5;
      local_e0 = DAT_006ff67c;
      GetWindowRect(param_3,&local_c4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c4,2);
      local_cc = local_c4.left + local_dc;
      local_d0 = local_c4.top - local_e0;
      local_b4 = local_c8;
      for (local_d4 = 0; local_d4 < local_8; local_d4 = local_d4 + 1) {
        for (local_d8 = 0; local_d8 < *(int *)((int)local_c + 0xcc + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_0046bc92(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)local_c))
          ;
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)local_c),local_b4,
                         local_cc,local_d0,DAT_006a28b0,DAT_006b2e30,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)local_c);
          }
        }
        for (local_d8 = 0; local_d8 < *(int *)((int)local_c + 0x198 + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_0046bc92(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 +
                                               (int)local_c));
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)local_c),local_b4,
                         local_cc,local_d0,DAT_006a28b0,DAT_006b2e30,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)local_c);
          }
        }
      }
      return 0;
    case 0x411:
      local_c = (void *)GetWindowLongA(hwnd,0);
      LVar4 = GetWindowLongA(hwnd,4);
      local_78 = 0;
      for (local_74 = 0; local_74 < LVar4; local_74 = local_74 + 1) {
        if (*(int *)((int)local_c + 0xcc + local_74 * 0x19c) != 0) {
          local_78 = local_78 + 1;
        }
      }
      return local_78;
    case 0x412:
      local_164 = param_3;
      local_154 = 0;
      for (local_14c = 0; local_14c < 2; local_14c = local_14c + 1) {
        for (local_16c = 0; local_16c < 0x50; local_16c = local_16c + 1) {
          local_174 = local_14c;
          local_170 = local_16c;
          local_158 = Ai_Subsystem_004b5c4b(local_14c,local_16c);
          local_15c = Ai_Subsystem_004b5d2e(local_14c,local_16c);
          local_150 = Ai_Subsystem_004b6c5b(local_14c,local_16c);
          FUN_00483139(hwnd,&local_174,(int *)0x0,&local_178,&local_160);
          iVar3 = Glue_Subsystem_004ef849(DAT_006a4924,&local_174,(int *)0x0,&local_144);
          if (iVar3 == 0) {
            Glue_Subsystem_004ef849(DAT_006b2e2c,&local_174,(int *)0x0,&local_144);
          }
          if ((local_158 != g_StackObjectCardId) && (local_15c != 2)) {
            if (((local_158 == -1) || (local_15c != 1)) ||
               (((local_150 & 0x10000) != 0 && (DAT_006fe43c == 0)))) {
              if (local_178 != 0) {
                if (local_160 == 0) {
                  uVar8 = SendMessageA(hwnd,0x402,0,local_178);
                  local_154 = local_154 | uVar8;
                }
                else {
                  uVar8 = SendMessageA(hwnd,0x403,0,local_178);
                  local_154 = local_154 | uVar8;
                }
              }
              LVar10 = 1;
              UVar9 = 0x402;
              pHVar6 = local_144;
              pHVar5 = GetParent(local_144);
              SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
            }
            else {
              local_148 = Ai_Subsystem_004b5de4(local_14c,local_16c);
              local_168 = Ai_Subsystem_004b6432(local_14c,local_16c);
              if ((local_148 & 0x10) == 0) {
                if (((((local_148 & 8) == 0) || ((local_168 & 4) != 0)) || ((local_168 & 0x40) != 0)
                    ) && ((local_168 & 8) == 0)) {
                  if ((local_178 != 0) && (local_160 == 0)) {
                    uVar8 = SendMessageA(hwnd,0x402,0,local_178);
                    local_154 = local_154 | uVar8;
                    LVar10 = 1;
                    UVar9 = 0x402;
                    pHVar6 = local_144;
                    pHVar5 = GetParent(local_144);
                    SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                  }
                }
                else if (local_178 == 0) {
                  SendMessageA(hwnd,0x401,(WPARAM)&local_174,0);
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  Glue_Subsystem_004ef64b(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
                if ((((local_148 & 4) == 0) && ((local_168 & 4) == 0)) && ((local_168 & 0x40) == 0))
                {
                  if ((local_178 != 0) && (local_160 != 0)) {
                    uVar8 = SendMessageA(hwnd,0x403,0,local_178);
                    local_154 = local_154 | uVar8;
                    LVar10 = 1;
                    UVar9 = 0x402;
                    pHVar6 = local_144;
                    pHVar5 = GetParent(local_144);
                    SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                  }
                }
                else if (local_178 == 0) {
                  SendMessageA(hwnd,0x400,(WPARAM)&local_174,0);
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  Glue_Subsystem_004ef64b(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
              }
              else {
                iVar3 = FUN_00483139(hwnd,&local_174,(int *)0x0,(int *)0x0,
                                     (int *)0x0);
                if (iVar3 == 0) {
                  Ai_Subsystem_004b5f74(local_180,local_14c,local_16c);
                  iVar3 = FUN_00483139(hwnd,local_180,(int *)0x0,&local_184,(int *)0x0
                                      );
                  if (iVar3 != 0) {
                    SendMessageA(hwnd,0x406,(WPARAM)&local_174,local_184);
                    local_154 = 1;
                  }
                }
              }
            }
          }
        }
      }
      if ((local_154 != 0) || (local_164 != (HWND)0x0)) {
        FUN_00481586(hwnd);
      }
      return 0;
    case 0x432:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      for (local_50 = 0; local_50 < local_8; local_50 = local_50 + 1) {
        for (local_54 = 0; local_54 < *(int *)((int)local_c + 0xcc + local_50 * 0x19c);
            local_54 = local_54 + 1) {
          SendMessageA(*(HWND *)(local_54 * 4 + local_50 * 0x19c + 4 + (int)local_c),0x432,0,0);
        }
        for (local_54 = 0; local_54 < *(int *)((int)local_c + 0x198 + local_50 * 0x19c);
            local_54 = local_54 + 1) {
          SendMessageA(*(HWND *)(local_54 * 4 + local_50 * 0x19c + 0xd0 + (int)local_c),0x432,0,0);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_4c = param_3;
      for (local_44 = 0; local_44 < local_8; local_44 = local_44 + 1) {
        for (local_48 = 0; local_48 < *(int *)((int)local_c + 0xcc + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          iVar3 = FUN_0046bbab(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)local_c),
                               (int)local_4c);
          if (iVar3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)local_c),(RECT *)0x0
                           ,0);
          }
        }
        for (local_48 = 0; local_48 < *(int *)((int)local_c + 0x198 + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          iVar3 = FUN_0046bbab(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)local_c),
                               (int)local_4c);
          if (iVar3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)local_c),
                           (RECT *)0x0,0);
          }
        }
      }
      return 0;
    case 0x435:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      for (local_58 = 0; local_58 < local_8; local_58 = local_58 + 1) {
        for (local_5c = 0; local_5c < *(int *)((int)local_c + 0xcc + local_58 * 0x19c);
            local_5c = local_5c + 1) {
          InvalidateRect(*(HWND *)(local_5c * 4 + local_58 * 0x19c + 4 + (int)local_c),(RECT *)0x0,0
                        );
        }
        for (local_5c = 0; local_5c < *(int *)((int)local_c + 0x198 + local_58 * 0x19c);
            local_5c = local_5c + 1) {
          InvalidateRect(*(HWND *)(local_5c * 4 + local_58 * 0x19c + 0xd0 + (int)local_c),
                         (RECT *)0x0,0);
        }
      }
      return 0;
    case 0x436:
      local_c = (void *)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      local_6c = param_3;
      local_70 = param_4;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_60 = 0;
      for (local_64 = 0; local_64 < local_8; local_64 = local_64 + 1) {
        for (local_68 = 0; local_68 < *(int *)((int)local_c + 0xcc + local_64 * 0x19c);
            local_68 = local_68 + 1) {
          iVar3 = FUN_0046bb29(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)local_c),
                               &local_6c->unused);
          if (iVar3 != 0) {
            local_60 = 1;
            if (local_70 == (HWND)0x0) {
              InvalidateRect(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)local_c),
                             (RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)local_c),0x432,0,0);
            }
          }
        }
        for (local_68 = 0; local_68 < *(int *)((int)local_c + 0x198 + local_64 * 0x19c);
            local_68 = local_68 + 1) {
          iVar3 = FUN_0046bb29(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)local_c),
                               &local_6c->unused);
          if (iVar3 != 0) {
            local_60 = 1;
            if (local_70 == (HWND)0x0) {
              InvalidateRect(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)local_c),
                             (RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)local_c),0x432,0,
                           0);
            }
          }
        }
      }
      return 0;
    case 0x437:
      return 0;
    }
  }
  uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
  return uVar8;
}



