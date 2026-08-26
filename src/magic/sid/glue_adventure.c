/*
 * sid/glue_adventure.c - Shandalar Overworld Campaign, Town Dialogs, Newsflashes & Audio Events
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"

/*
 * Adventure_EnterTownLocation
 * Purpose: Initialize town interface, load dialog pic assets, and configure display.
 * Procedure:
 * 1. Load advfac64.pic, advinter800.pic, and dbox.spr.
 * 2. Initialize town UI buttons and layout.
 * 3. Display town backdrop.
 */
/*
 * Decompiled function: Adventure_EnterTownLocation
 * Entry Point: 004e73a0
 * Size: 1405 bytes
 */

int Adventure_EnterTownLocation(void)

{
  bool is_valid;
  uint8_t arg1;
  int val_result;
  int uval_3;
  int val_4;
  uint32_t uval_5;
  clock_t cVar6;
  int match_count;
  
  is_valid = false;
  DAT_006b2fe0 = 0xffffffff;
  g_GlobalEnchantmentCardId = 0xffffffff;
  Ai_Subsystem_004cd3eb();
  for (match_count = 0; match_count < 4; match_count = match_count + 1) {
    *(int *)(&g_PlayerLifeTotals + match_count * 4) = 8;
  }
  Hints_Load_004071ce();
  Csv_ReadConcise_0040659f();
  Mem_AllocOrFree_00512220(1,1,DAT_00677690);
  Pic_Subsystem_0044b8aa();
  UI_PrepareCombatViewport();
  GdiGetBatchLimit();
  GdiSetBatchLimit(100);
  LoadPalNoPic(s_advfac64_pic_0052f0c0);
  Sprite_LoadAll(&DAT_006781d0,s_dbox_spr_0052f0d0);
  do {
    val_result = Sprite_Load_begin_0047a2e6();
    FUN_005112b0(0,(short)g_MidiMusicTrackId);
    switch(val_result) {
    case 0:
      while( true ) {
        g_CampaignDifficultyLevel = Pic_Load_menu2_hi_0047abf1();
        FUN_005112b0(0,(short)g_MidiMusicTrackId);
        if (g_CampaignDifficultyLevel == -1) break;
        while( true ) {
          g_OverworldPlayerDirection = Pic_Load_menu3_but1_0047b208();
          DAT_006410d8 = g_OverworldPlayerDirection;
          DAT_006fe448 = g_OverworldPlayerDirection;
          DAT_006fe44c = Util_GetRandomNumber(3);
          FUN_005112b0(0,(short)g_MidiMusicTrackId);
          if (DAT_006410d8 == -1) break;
          DAT_006ff678 = Sprite_Load__16faces_0047b899();
          FUN_005112b0(0,(short)g_MidiMusicTrackId);
          if (DAT_006ff678 != -1) {
            DAT_0052f000 = 1 << ((uint8_t)g_OverworldPlayerDirection & 0x1f);
            LoadPalNoPic(s_advfac64_pic_0052f0dc);
            Mem_AllocOrFree_00510e20(1,PTR_s_advinter800_pic_00530d98);
            FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
                         (int *)g_DisplaySurfaceScreen,0,0);
            DAT_0067f388 = 0;
            Palette_Subsystem_00496ccf();
            is_valid = true;
            *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
            FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xff,0x140,0xbc);
            DAT_0064101c = 1;
            FUN_0046e960();
            Pic_Subsystem_0044d680();
            FUN_0048e306();
            Gold = (5 - g_CampaignDifficultyLevel) * 0x32;
            DAT_0052f00c = 0;
            goto switchD_004e765f_default;
          }
        }
      }
      break;
    case 1:
      DAT_0067f388 = 0;
      val_4 = Mem_AllocOrFree_0048e108();
      SaveGame_LoadCampaignFile(val_4);
    default:
switchD_004e765f_default:
      for (match_count = 0; match_count < 0x80; match_count = match_count + 1) {
        if (*(int *)(&g_CardSlot_CreatureType + match_count * 100) == 5) {
          uval_3 = FUN_0040c761(*(int *)(&g_DungeonMapTileX + match_count * 100),
                               *(int *)(&g_DungeonMapTileY + match_count * 100));
          arg1 = Adventure_GetLocationEncounterIndex(uval_3);
          val_4 = Rules_CalculateManaCostReduction(arg1);
          *(int *)(&DAT_006410c0 + (val_4 + -1) * 4) = 1;
        }
      }
      Subsystem_LoadStatWinDll();
      if (!is_valid) {
        Palette_Subsystem_00496ccf();
      }
      Castle_Process_0046c8b0();
      FUN_0041edd4();
      Adventure_Map_RedrawViewport();
      if (val_result != 0) {
        Pic_Subsystem_004520b2();
      }
      LoadPalNoPic(s_advfac64_pic_0052f108);
      Overworld_LoadAdventureInterface800();
      if (val_result == 0) {
        do {
          do {
            val_result = Util_GetRandomNumber(0x40);
            g_OverworldMapPixelX = val_result * 0x20 + 0x10;
            val_result = Util_GetRandomNumber(0x40);
            g_OverworldMapPixelY = val_result * 0x20 + 0x10;
            uval_3 = FUN_0040c761((int)(g_OverworldMapPixelX + (g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5,
                                 (int)(g_OverworldMapPixelY + (g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5);
            uval_5 = Adventure_GetLocationEncounterIndex(uval_3);
          } while ((uval_5 & DAT_0052f000) == 0);
          uval_5 = FUN_0040c7c0((int)(g_OverworldMapPixelX + (g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5,
                               (int)(g_OverworldMapPixelY + (g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5);
        } while ((uval_5 & 0x10) != 0);
      }
      DAT_005659bc = 0;
      DAT_0067bde8 = 0;
      DAT_0067f3b8 = 0;
      for (match_count = 0; match_count < 500; match_count = match_count + 1) {
        if ((*(int *)(&deck + match_count * 4) != -1) &&
           (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[match_count * 4] & 0x40) == 0)) {
          DAT_0067f3b8 = DAT_0067f3b8 + 1;
        }
      }
      do {
        Mem_AllocOrFree_005016f9();
        Ai_Subsystem_004be643(g_OverworldMapPixelX,g_OverworldMapPixelY,DAT_005659dc);
        DAT_005659dc = 0;
        do {
          cVar6 = clock();
        } while (cVar6 < 0x3c);
        clock();
        if ((g_MouseCursorButtonState & 2) != 0) {
          Adventure_PromptLocationMenu();
        }
        Adventure_ExitTownLocation();
        Adventure_PlayLocationMusic();
        Adventure_UpdateWorldMapLoop();
        Adventure_TriggerDuelFromEncounter();
        Pic_Subsystem_0044b84b();
        FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
        DAT_0067f37c = DAT_0067f37c + 1;
        FUN_0040a3e1();
        Mem_AllocOrFree_0040a422();
      } while (DAT_006fe3f0 == 0);
      FUN_005112b0(0,(short)g_MidiMusicTrackId);
      Subsystem_FreeStatWinDll();
      uval_3 = Palette_Util_00496d20();
      return uval_3;
    case 2:
      DAT_0067f388 = 0;
      SaveGame_LoadCampaignFile(3);
      goto switchD_004e765f_default;
    case 3:
      goto switchD_004e765f_default;
    case 4:
      DAT_006fe3f0 = 1;
      return 0;
    }
  } while( true );
}

/*
 * Adventure_PromptLocationMenu
 * Purpose: Display overworld location menu options (Save, Quit, Deck, etc.).
 * Procedure:
 * 1. Render location options dialog.
 * 2. Prompt user for selection.
 */
/*
 * Decompiled function: Adventure_PromptLocationMenu
 * Entry Point: 004e7936
 * Size: 276 bytes
 */

void Adventure_PromptLocationMenu(void)

{
  int u_res;
  int u_temp;
  int arg2;
  
  u_res = *(int *)(g_DisplaySurfaceScreen + 0x20);
  *(int *)(g_DisplaySurfaceScreen + 0x20) = 4;
  u_temp = Ai_Util_004c3bc4(0x40);
  arg2 = Ai_Util_004c3bc4(0x50);
  u_temp = FUN_00489710(s_Will_you_____Save_Quit_See_Edit_D_0052f118,arg2,u_temp);
  switch(u_temp) {
  case 0:
    Util_MoveMemoryBuffer(0x53);
    break;
  case 1:
    Util_MoveMemoryBuffer(0x51);
    break;
  case 2:
    Util_MoveMemoryBuffer(0x3b00);
    break;
  case 3:
    Util_MoveMemoryBuffer(0x3c00);
    break;
  case 4:
    Util_MoveMemoryBuffer(0x3d00);
    break;
  case 5:
    Util_MoveMemoryBuffer(0x3e00);
    break;
  case 6:
    Util_MoveMemoryBuffer(0x3f00);
    break;
  case 7:
    Util_MoveMemoryBuffer(0x4000);
    break;
  default:
    Overworld_LoadAdventureInterface800();
  }
  *(int *)(g_DisplaySurfaceScreen + 0x20) = u_res;
  return;
}

/*
 * Adventure_HandleLocationMenuChoice
 * Purpose: Process selected menu action in overworld location.
 * Procedure:
 * 1. Handle Save Game, Edit Deck, or Leave Location.
 */
/*
 * Decompiled function: Adventure_HandleLocationMenuChoice
 * Entry Point: 004e7a6f
 * Size: 756 bytes
 */

int Adventure_HandleLocationMenuChoice(int arg1,int arg2)

{
  int status;
  int arg1;
  int local_40 [10];
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  uint32_t slot_idx;
  
  local_40[0] = 0x4800;
  local_40[1] = 0x4900;
  local_40[2] = 0x4d00;
  local_40[3] = 0x5100;
  local_40[4] = 0x5000;
  local_40[5] = 0x4f00;
  local_40[6] = 0x4b00;
  local_40[7] = 0x4700;
  local_40[8] = 0x4800;
  status = Ai_Util_004c3bc4(0x40);
  if ((((arg1 < status) || (status = Ai_Util_004c3bc4(0x240), status < arg1)) ||
      (status = Ai_Util_004c3bc4(0x30), arg2 < status)) ||
     (status = Ai_Util_004c3bc4(0x148), status < arg2)) {
    status = -1;
  }
  else {
    status = Ai_Util_004c3bc4(0x130);
    if (((status < arg1) && (status = Ai_Util_004c3bc4(0x158), arg1 < status)) &&
       ((status = Ai_Util_004c3bc4(0xa8), status < arg2 &&
        (status = Ai_Util_004c3bc4(0xdd), arg2 < status)))) {
      status = 0x20;
    }
    else {
      player_idx = Ai_Util_004c3bc4(0x140);
      target_idx = Ai_Util_004c3bc4(0xbc);
      status = arg1 - player_idx;
      arg1 = target_idx - arg2;
      match_count = abs(status);
      card_idx = abs(arg1);
      if ((status < 0) || (arg1 < 0)) {
        if ((status < 0) || (-1 < arg1)) {
          if ((status < 0) && (arg1 < 0)) {
            slot_idx = 4;
          }
          else if ((status < 0) && (-1 < arg1)) {
            slot_idx = 6;
          }
        }
        else {
          slot_idx = 2;
        }
      }
      else {
        slot_idx = 0;
      }
      if (((slot_idx & 2) == 0) && (card_idx < match_count)) {
        slot_idx = slot_idx + 1;
      }
      else if (((slot_idx & 2) != 0) && (match_count < card_idx)) {
        slot_idx = slot_idx + 1;
      }
      switch(slot_idx) {
      case 0:
      case 3:
      case 4:
      case 7:
        local_40[9] = match_count * 0x9a85 >> 0xe;
        if (arg1 < 0) {
          local_40[9] = -local_40[9];
        }
        break;
      case 1:
      case 2:
      case 5:
      case 6:
        local_40[9] = match_count * 0x1a82 >> 0xe;
        if (arg1 < 0) {
          local_40[9] = -local_40[9];
        }
      }
      switch(slot_idx) {
      case 0:
      case 1:
      case 2:
      case 3:
        if (arg1 < local_40[9]) {
          slot_idx = slot_idx + 1;
        }
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        if (local_40[9] < arg1) {
          slot_idx = slot_idx + 1;
        }
      }
      status = local_40[slot_idx];
    }
  }
  return status;
}

/*
 * Adventure_ExitTownLocation
 * Purpose: Cleanup location state and return to world map.
 * Procedure:
 * 1. Free location UI resources.
 * 2. Restore world map state.
 */
/*
 * Decompiled function: Adventure_ExitTownLocation
 * Entry Point: 004e7da1
 * Size: 326 bytes
 */

void Adventure_ExitTownLocation(void)

{
  int slot_idx;
  
  slot_idx = -1;
  switch(DAT_00640f08) {
  case 1:
    Util_MoveMemoryBuffer(0x3b00);
    break;
  case 2:
    Util_MoveMemoryBuffer(0x3c00);
    break;
  case 3:
    Util_MoveMemoryBuffer(0x3d00);
    break;
  case 4:
    Util_MoveMemoryBuffer(0x3e00);
    break;
  case 5:
    Util_MoveMemoryBuffer(0x3f00);
    break;
  case 6:
    Util_MoveMemoryBuffer(0x4000);
    break;
  default:
    Pic_Subsystem_0044b84b();
    if (g_CombatAttackerSlotIndex != 0) {
      slot_idx = Adventure_HandleLocationMenuChoice(g_MouseScreenCoordX,g_MouseScreenCoordY);
    }
    if (slot_idx != -1) {
      Util_MoveMemoryBuffer(slot_idx);
    }
    break;
  case 0x31:
    Util_MoveMemoryBuffer(0x31);
    break;
  case 0x32:
    Util_MoveMemoryBuffer(0x32);
    break;
  case 0x33:
    Util_MoveMemoryBuffer(0x33);
    break;
  case 0x34:
    Util_MoveMemoryBuffer(0x34);
    break;
  case 0x35:
    Util_MoveMemoryBuffer(0x35);
  }
  DAT_00640f08 = 0;
  return;
}

/*
 * Adventure_PlayLocationMusic
 * Purpose: Manage location background music playback based on terrain and castle color.
 * Procedure:
 * 1. Determine music track for current location.
 * 2. Stream WAV music track from sound archive.
 */
/*
 * Decompiled function: Adventure_PlayLocationMusic
 * Entry Point: 004e7f51
 * Size: 5122 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Adventure_PlayLocationMusic(void)

{
  uint32_t u_res;
  int val_result;
  uint32_t uval_3;
  int val_4;
  int val_5;
  int val_6;
  int height;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_58;
  int local_44;
  int local_40;
  int local_34;
  int local_30;
  int local_2c;
  int card_idx;
  int match_count;
  
  val_result = Mem_AllocOrFree_0040810f();
  if (val_result != 0) goto LAB_004e8570;
  local_34 = FUN_0048ac2f();
  DAT_005659bc = 0;
  if (local_34 < 0x21) {
    if (local_34 == 0x20) {
      DAT_0052f010 = 0;
    }
    else if (local_34 == 0x1b) goto LAB_004e7f84;
  }
  else if (local_34 < 0x52) {
    if (local_34 == 0x51) {
LAB_004e7f84:
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 4;
      strcpy(&g_OverworldWorldState,s_Ready_to_Quit__No__Yes__0052f1b0);
      val_result = FUN_004896be(&g_OverworldWorldState,100,0x50);
      if (val_result == 1) {
        DAT_006fe3f0 = 1;
      }
      else {
        Overworld_LoadAdventureInterface800();
      }
      SaveGame_SaveCampaignFile(3);
    }
    else if ((0x30 < local_34) && (local_34 < 0x36)) {
LAB_004e8168:
      val_result = local_34 + -0x30;
      if ((*(int *)(&DAT_0067bdbc + val_result * 4) != 0) &&
         ((g_OverworldMovementFlags & 1 << ((char)val_result * '\x02' & 0x1fU)) != 0)) {
        val_4 = Util_GetRandomNumber(4 - g_CampaignDifficultyLevel);
        if (val_4 == 0) {
          *(int *)(&DAT_0067bdbc + val_result * 4) = *(int *)(&DAT_0067bdbc + val_result * 4) + -1;
        }
        Overworld_LoadAdventureInterface800();
        switch(local_34) {
        case 0x31:
          FUN_005112b0(0,(short)g_MidiMusicTrackId);
          DeckBuilderMain(_hwndScreen,1,1);
          Pic_Load_advfac64_0040a4fc();
          FUN_0050d560(0,7);
          Overworld_LoadAdventureInterface800();
          break;
        case 0x32:
          do {
            val_result = Util_GetRandomNumber(0x40);
            val_4 = Util_GetRandomNumber(0x40);
            val_5 = FUN_0040c761(val_result,val_4);
          } while (val_5 == 0);
          FUN_0040b3c2(0x12,2);
          g_OverworldMapPixelX = val_result * 0x20 + 0x10;
          g_OverworldMapPixelY = val_4 * 0x20 + 0x10;
          Overworld_LoadAdventureInterface800();
          DAT_0064101c = 1;
          break;
        case 0x33:
          *(int *)(&DAT_005224ec + val_result * 0x20) = 0x96;
          FUN_0040b3c2(0x12,3);
          break;
        case 0x34:
          local_44 = 0x7fff;
          card_idx = -1;
          for (local_2c = 0; local_2c < 6; local_2c = local_2c + 1) {
            if ((0 < *(int *)(&g_TownBuildingCoordinates + local_2c * 0x14)) &&
               (val_result = FUN_0040a36f(g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_2c * 0x14),
                                     g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_2c * 0x14)),
               val_result < local_44)) {
              card_idx = local_2c;
              local_44 = val_result;
            }
          }
          if (card_idx != -1) {
            FUN_0046e70d(card_idx,card_idx + 8);
            FUN_0040b3c2(0x12,CONCAT31((int3)((uint32_t)(*(int *)(&g_TownBuildingCoordinates + card_idx * 0x14) <<
                                                    0x10) >> 8),4));
            *(int *)(&g_TownBuildingCoordinates + card_idx * 0x14) = 0xffffffff;
          }
          break;
        case 0x35:
          if (DAT_0067f35c != -1) {
            g_OverworldMapPixelX = (DAT_0067f360 & 0xffe0) + 0x10;
            g_OverworldMapPixelY = (DAT_0067f364 & 0xffe0) + 0x1f;
            FUN_0040b3c2(0x12,5);
          }
          DAT_0064101c = 1;
        }
      }
    }
  }
  else if (local_34 < 0x72) {
    if (local_34 == 0x71) goto LAB_004e7f84;
    if (local_34 == 0x53) {
      DAT_0052f010 = 0;
      val_result = Mem_AllocOrFree_0048e0ee();
      if (val_result != -1) {
        SaveGame_SaveCampaignFile(val_result);
      }
      LoadPalNoPic(s_advfac64_pic_0052f1cc);
      Overworld_LoadAdventureInterface800();
    }
    else if (local_34 == 0x55) {
      DAT_00532550 = DAT_00532550 ^ 1;
      goto LAB_004e8168;
    }
  }
  else if (local_34 < 0x3c01) {
    if (local_34 == 0x3c00) {
      FUN_0040a3e1();
      Ai_CastleEncounter_004c24b3(0);
      Overworld_LoadAdventureInterface800();
    }
    else if (local_34 == 0x3b00) {
      if ((g_OverworldMovementFlags & 8) != 0) {
        local_34 = 0x31;
        goto LAB_004e8168;
      }
      FUN_005112b0(0,(short)g_MidiMusicTrackId);
      DeckBuilderMain(_hwndScreen,1,0);
      Pic_Load_advfac64_0040a4fc();
      Overworld_LoadAdventureInterface800();
    }
  }
  else if (local_34 < 0x3e01) {
    if (local_34 == 0x3e00) {
      FUN_0040a3e1();
      Castle_Process_0048f523(1);
      Overworld_LoadAdventureInterface800();
    }
    else if (local_34 == 0x3d00) {
      FUN_0040a3e1();
      Town_Process_00490d7b(1);
      Overworld_LoadAdventureInterface800();
    }
  }
  else if (local_34 < 0x4001) {
    if (local_34 == 0x4000) {
      FUN_0040a3e1();
      Adventure_Map_UpdateLightingAndPalette(0,0xffffffff);
      Overworld_LoadAdventureInterface800();
    }
    else if (local_34 == 0x3f00) {
      Castle_Process_00421b32();
      Overworld_LoadAdventureInterface800();
    }
  }
  else if (local_34 < 0x4801) {
    if (local_34 == 0x4800) {
      DAT_0052f010 = 2;
    }
    else if (local_34 == 0x4700) {
      DAT_0052f010 = 1;
    }
  }
  else if (local_34 < 0x4b01) {
    if (local_34 == 0x4b00) {
      DAT_0052f010 = 8;
    }
    else if (local_34 == 0x4900) {
      DAT_0052f010 = 3;
    }
  }
  else if (local_34 < 0x4f01) {
    if (local_34 == 0x4f00) {
      DAT_0052f010 = 7;
    }
    else if (local_34 == 0x4d00) {
      DAT_0052f010 = 4;
    }
  }
  else if (local_34 == 0x5000) {
    DAT_0052f010 = 6;
  }
  else if (local_34 == 0x5100) {
    DAT_0052f010 = 5;
  }
  Adventure_LoadFacePalette(0);
LAB_004e8570:
  if ((DAT_005659b8 != 0) && (DAT_005659bc = DAT_005659bc + 1, 500 < DAT_005659bc)) {
    Pic_Load_Title();
    DAT_005659bc = 300;
  }
  val_result = FUN_0040c761((int)(*(int *)(&DAT_00522378 + DAT_0052f010 * 4) + g_OverworldMapPixelX +
                            ((int)(*(int *)(&DAT_00522378 + DAT_0052f010 * 4) + g_OverworldMapPixelX) >>
                             0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&DAT_005223e0 + DAT_0052f010 * 4) + g_OverworldMapPixelY +
                            ((int)(*(int *)(&DAT_005223e0 + DAT_0052f010 * 4) + g_OverworldMapPixelY) >>
                             0x1f & 0x1fU)) >> 5);
  uval_3 = Adventure_GetLocationEncounterIndex(val_result);
  if (uval_3 == 0) {
    local_40 = 0;
  }
  else {
    do {
      local_40 = Util_GetRandomNumber(5);
      local_40 = local_40 + 1;
    } while ((uval_3 & 1 << ((uint8_t)local_40 & 0x1f)) == 0);
  }
  match_count = 1;
  DAT_00641010 = (int)(g_OverworldMapPixelX + ((int)g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5;
  DAT_00641014 = (int)(g_OverworldMapPixelY + ((int)g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5;
  if (((val_result == 2) || ((val_result == 3 && ((g_OverworldMovementFlags & 8) == 0)))) ||
     ((val_result == 4 && ((g_OverworldMovementFlags & 0x200) == 0)))) {
    match_count = 3;
  }
  if ((val_result == 5) && ((g_OverworldMovementFlags & 0x200) == 0)) {
    match_count = 3;
  }
  val_result = FUN_0040cb4f(DAT_00641010,DAT_00641014,(char)DAT_0052f010);
  if (val_result != 0) {
    match_count = 1;
  }
  val_result = FUN_0040cb4f(DAT_00641010,DAT_00641014,((char)DAT_0052f010 + 3U & 7) + 1);
  if (val_result != 0) {
    match_count = 1;
  }
  if (DAT_00522448 == 0) {
    match_count = FUN_0040a305(match_count + 2,0,4);
  }
  u_res = g_OverworldMapPixelY;
  uval_3 = g_OverworldMapPixelX;
  val_result = g_OverworldMapPixelX + ((int)g_OverworldMapPixelX >> 0x1f & 0x1fU);
  val_4 = g_OverworldMapPixelY + ((int)g_OverworldMapPixelY >> 0x1f & 0x1fU);
  val_5 = (int)DAT_0067f37c / match_count;
  if ((int)DAT_0067f37c % match_count == 0) {
    if (match_count == 3) {
      val_5 = *(int *)(&DAT_00522378 + DAT_0052f010 * 4) * 2;
    }
    else {
      val_5 = *(int *)(&DAT_00522378 + DAT_0052f010 * 4);
    }
    g_OverworldMapPixelX = g_OverworldMapPixelX + val_5;
    if (match_count == 3) {
      val_5 = *(int *)(&DAT_005223e0 + DAT_0052f010 * 4) * 2;
    }
    else {
      val_5 = *(int *)(&DAT_005223e0 + DAT_0052f010 * 4);
    }
    g_OverworldMapPixelY = g_OverworldMapPixelY + val_5;
    DAT_006410dc = DAT_006410dc + 1;
    if (4 < (int)DAT_006410dc) {
      DAT_006410dc = 1;
    }
    if (DAT_0052f010 != 0) {
      height = 0;
      val_5 = Util_GetRandomNumber(0x28);
      val_5 = val_5 + 0x50;
      val_6 = Util_GetRandomNumber(0x19);
      Adventure_Audio_PlayEffectAtVolume
                (((DAT_006410dc & 1) - 2) + local_40 * 2,val_6 + 0x4b,val_5,height);
    }
    if (DAT_0052f010 == 0) {
      DAT_006410dc = 0;
    }
    else {
      DAT_006410d4 = DAT_0052f010;
    }
    if ((DAT_0052254c != 0) ||
       (((DAT_0067f37c & 1) != 0 &&
        (val_5 = FUN_0040cb4f(DAT_00641010,DAT_00641014,((char)DAT_0052f010 + 3U & 7) + 1),
        val_5 != 0)))) {
      g_OverworldMapPixelX = g_OverworldMapPixelX + *(int *)(&DAT_00522378 + DAT_0052f010 * 4);
      g_OverworldMapPixelY = g_OverworldMapPixelY + *(int *)(&DAT_005223e0 + DAT_0052f010 * 4);
    }
    val_5 = FUN_0040c761((int)(g_OverworldMapPixelX + ((int)g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5,
                         (int)(g_OverworldMapPixelY + ((int)g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5);
    if ((val_5 == 0) &&
       ((val_6 = abs(g_OverworldMapPixelX - ((g_OverworldMapPixelX & 0xffffffe0) + 0x10)), val_6 < 0xc ||
        (val_6 = abs(g_OverworldMapPixelY - ((g_OverworldMapPixelY & 0xffffffe0) + 0x10)), val_6 < 0xc)))) {
      DAT_0052f010 = 0;
      g_OverworldMapPixelX = uval_3;
      g_OverworldMapPixelY = u_res;
    }
    val_6 = Util_GetRandomNumber(0x28);
    if ((val_6 == 0) && (DAT_0052f008 == 0)) {
      Adventure_Audio_PlayTerrainAmbience(local_40);
    }
    if (((DAT_0067f37c & 0x1f) == 0) && (DAT_0052f010 != 0)) {
      if (DAT_00522448 != 0) {
        DAT_00522448 = DAT_00522448 + -1;
      }
      if ((DAT_00522558 == 0) && (val_5 == 2)) {
        DAT_00522448 = DAT_00522448 + 2;
      }
      DAT_0052f004 = DAT_0052f004 + 1;
      DAT_00641020 = DAT_00641020 + 1;
      if ((DAT_0052f004 & 0x3f) == 0) {
        Adventure_NewsFlash_EnemyAttack();
        val_5 = FUN_0040a305(g_CampaignDifficultyLevel +
                             ((int)(DAT_0052f004 + ((int)DAT_0052f004 >> 0x1f & 0xffU)) >> 8),0,0x10
                            );
        DAT_0052f004 = DAT_0052f004 + val_5;
      }
      if (((uint8_t)DAT_0052f004 & 0x3f) == 0x18) {
        Adventure_NewsFlash_DominionSpell();
        val_5 = FUN_0040a305(g_CampaignDifficultyLevel * 2 +
                             ((int)(DAT_0052f004 + ((int)DAT_0052f004 >> 0x1f & 0x3fU)) >> 6),0,0x20
                            );
        DAT_0052f004 = DAT_0052f004 + val_5;
      }
      DAT_005659dc = 1;
      if (7 < (int)DAT_0052f004) {
        DAT_0052f00c = 1;
      }
    }
    DAT_00641010 = (int)(g_OverworldMapPixelX + ((int)g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5;
    DAT_00641014 = (int)(g_OverworldMapPixelY + ((int)g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5;
    if ((DAT_00641010 != val_result >> 5) || (DAT_00641014 != val_4 >> 5)) {
      DAT_005659b0 = 0;
    }
    if ((DAT_0067f37c & 1) == 0) {
      local_68 = 0x7fff;
      for (local_64 = 0; local_64 < 0x80; local_64 = local_64 + 1) {
        if ((*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != -1) &&
           (val_result = FUN_0040a36f((*(int *)(&g_DungeonMapTileX + local_64 * 100) * 0x20 + 0x10) -
                                 g_OverworldMapPixelX,
                                 (*(int *)(&g_DungeonMapTileY + local_64 * 100) * 0x20 + 0x10) -
                                 g_OverworldMapPixelY), val_result < local_68)) {
          local_58 = local_64;
          local_68 = val_result;
        }
      }
      val_result = FUN_0040a305(0x80 - local_68,0,100);
      if ((val_result < 0xb) || (*(int *)(&g_CardSlot_CreatureType + local_58 * 100) < 1)) {
        if (DAT_0052f014 != 0) {
          Pic_Subsystem_00423c82(0x10);
        }
        DAT_0052f014 = 0;
        DAT_0052f064 = -1;
      }
      else {
        if (local_58 == DAT_0052f064) {
          Pic_Subsystem_00423dc2(0x10,val_result << 2);
        }
        else {
          DAT_0052f064 = local_58;
          if (*(int *)(&g_CardSlot_CreatureType + local_58 * 100) == 4) {
            for (local_30 = 0;
                (local_30 < 5 &&
                ((*(int *)(&g_DungeonMapTileX + local_58 * 100) !=
                  *(int *)(&DAT_0067f000 + local_30 * 0x30) ||
                 (*(int *)(&g_DungeonMapTileY + local_58 * 100) !=
                  *(int *)(&DAT_0067f004 + local_30 * 0x30))))); local_30 = local_30 + 1) {
            }
            val_4 = DAT_0052f018;
            if (local_30 + 0x15 != DAT_0052f018) {
              if ((DAT_0052f018 != -1) && (local_30 + 0x15 != DAT_0052f018)) {
                Pic_Subsystem_00423b93(0x10);
              }
              switch(local_30) {
              case 0:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_bcastle_wav_0052f1dc,0x10);
                break;
              case 1:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_ucastle_wav_0052f1f0,0x10);
                break;
              case 2:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_gcastle_wav_0052f204,0x10);
                break;
              case 3:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_rcastle_wav_0052f218,0x10);
                break;
              case 4:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_wcastle_wav_0052f22c,0x10);
              }
              val_4 = local_30 + 0x15;
            }
          }
          else if (*(int *)(&g_CardSlot_CreatureType + local_58 * 100) == 1) {
            if ((DAT_0052f018 != -1) && (DAT_0052f018 != 0x32)) {
              Pic_Subsystem_00423b93(0x10);
            }
            if (DAT_0052f018 != 0x32) {
              Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus0_wav_0052f240,0x10);
            }
            DAT_0052f018 = 0x32;
            val_4 = DAT_0052f018;
          }
          else {
            val_4 = local_58 % 0x14;
            if (val_4 != DAT_0052f018) {
              if (DAT_0052f018 != -1) {
                Pic_Subsystem_00423b93(0x10);
              }
              switch(val_4) {
              case 0:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus1_wav_0052f254,0x10);
                break;
              case 1:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus2_wav_0052f268,0x10);
                break;
              case 2:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus3_wav_0052f27c,0x10);
                break;
              case 3:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus4_wav_0052f290,0x10);
                break;
              case 4:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus5_wav_0052f2a4,0x10);
                break;
              case 5:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus6_wav_0052f2b8,0x10);
                break;
              case 6:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus7_wav_0052f2cc,0x10);
                break;
              case 7:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus8_wav_0052f2e0,0x10);
                break;
              case 8:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus9_wav_0052f2f4,0x10);
                break;
              case 9:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus10_wav_0052f308,0x10);
                break;
              case 10:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus11_wav_0052f320,0x10);
                break;
              case 0xb:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus12_wav_0052f338,0x10);
                break;
              case 0xc:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus13_wav_0052f350,0x10);
                break;
              case 0xd:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus14_wav_0052f368,0x10);
                break;
              case 0xe:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus15_wav_0052f380,0x10);
                break;
              case 0xf:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus16_wav_0052f398,0x10);
                break;
              case 0x10:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus17_wav_0052f3b0,0x10);
                break;
              case 0x11:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus18_wav_0052f3c8,0x10);
                break;
              case 0x12:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus19_wav_0052f3e0,0x10);
                break;
              case 0x13:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_tmplmus1_wav_0052f3f8,0x10);
                break;
              default:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus0_wav_0052f410,0x10);
              }
            }
          }
          DAT_0052f018 = val_4;
          Adventure_Audio_PlayEffectLooped(0x10,val_result,0);
          Pic_Subsystem_00423f10(0x10,1);
        }
        DAT_0052f014 = 1;
      }
    }
    if ((((DAT_005659b0 == 0) && (val_result = abs((g_OverworldMapPixelX & 0x1f) - 0x10), val_result < 0xc)) &&
        (val_result = abs((g_OverworldMapPixelY & 0x1f) - 0x10), val_result < 0xc)) &&
       (uval_3 = FUN_0040c7c0(DAT_00641010,DAT_00641014), (uval_3 & 0x10) != 0)) {
      uval_3 = Duel_GetCardDrawOriginX(DAT_00641010,DAT_00641014);
      if (uval_3 == 0xffffffff) {
        FUN_0040c889(0x10,DAT_00641010,DAT_00641014);
      }
      else {
        Pic_Subsystem_00423dc2(0x10,400);
        Pic_Subsystem_00423f55(0x10,1);
        Town_Process_00506580(uval_3);
        DAT_0052f00c = 1;
        DAT_005659b0 = 1;
        DAT_0052f010 = 0;
        for (local_2c = 0; local_2c < 6; local_2c = local_2c + 1) {
          if ((0 < *(int *)(&g_TownBuildingCoordinates + local_2c * 0x14)) &&
             (val_result = FUN_0040a36f(g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_2c * 0x14),
                                   g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_2c * 0x14)),
             val_result < 0x60)) {
            val_result = g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_2c * 0x14);
            val_4 = g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_2c * 0x14);
            val_5 = abs(val_4);
            val_6 = abs(val_result);
            if (val_5 / 2 < val_6) {
              local_6c = FUN_0040a33c(val_result);
              local_6c = local_6c * 0x30;
            }
            else {
              local_6c = 0;
            }
            *(uint32_t *)(&g_AiCardEvaluationScore + local_2c * 0x14) = g_OverworldMapPixelX - local_6c;
            val_result = abs(val_result);
            val_5 = abs(val_4);
            if (val_result / 2 < val_5) {
              local_70 = FUN_0040a33c(val_4);
              local_70 = local_70 * 0x30;
            }
            else {
              local_70 = 0;
            }
            *(uint32_t *)(&g_AiCardSynergyScore + local_2c * 0x14) = g_OverworldMapPixelY - local_70;
          }
        }
        Palette_Subsystem_004981b5(0);
        SaveGame_SaveCampaignFile(3);
        Adventure_LoadFacePalette(0);
        Overworld_LoadAdventureInterface800();
        DAT_0067f37c = DAT_0067f37c | 0x1f;
      }
    }
    if (((DAT_005659b0 == 0) && ((g_OverworldMapPixelX - 8 & 0x10) == 0)) &&
       (((g_OverworldMapPixelY - 8 & 0x10) == 0 &&
        (uval_3 = FUN_0040c7c0(DAT_00641010,DAT_00641014), (uval_3 & 0x40) != 0)))) {
      val_result = FUN_0048ec9a(DAT_00641010,DAT_00641014);
      DAT_005659b0 = 1;
      if (((val_result != -1) && (*(int *)(&DAT_0067eff0 + val_result * 0x30) != -1)) &&
         (*(int *)(&DAT_0067f010 + val_result * 0x30) != 0)) {
        FUN_004909a0(val_result);
      }
    }
    DAT_0067bde8 = 0;
    DAT_0067f3b8 = 0;
    for (local_2c = 0; local_2c < 500; local_2c = local_2c + 1) {
      if ((*(int *)(&deck + local_2c * 4) != -1) &&
         (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[local_2c * 4] & 0x40) == 0)) {
        DAT_0067f3b8 = DAT_0067f3b8 + 1;
      }
    }
    val_5 = Mem_AllocOrFree_0040a422();
  }
  return val_5;
}

/*
 * Adventure_UpdateWorldMapLoop
 * Purpose: Main overworld turn processing, player movement, and enemy wizard AI pathing.
 * Procedure:
 * 1. Process player input coordinates.
 * 2. Update enemy wizard positions across Shandalar map.
 * 3. Check for wandering monster encounters.
 */
/*
 * Decompiled function: Adventure_UpdateWorldMapLoop
 * Entry Point: 004e93df
 * Size: 4945 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Adventure_UpdateWorldMapLoop(void)

{
  int status;
  bool is_match;
  uint8_t flag_3;
  int val_4;
  int val_5;
  int val_6;
  int uval_7;
  uint32_t uval_8;
  int iVar9;
  int iVar10;
  uint32_t local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  uint32_t local_48;
  int local_44;
  uint32_t local_40;
  int local_3c;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int player_idx;
  uint32_t card_idx;
  int match_count;
  
  local_54 = 0x7fff;
  for (local_40 = 0; (int)local_40 < 6; local_40 = local_40 + 1) {
    val_4 = FUN_0040a36f(g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14),
                         g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_40 * 0x14));
    if ((val_4 < local_54) && (*(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) != 0)) {
      card_idx = local_40;
      local_54 = val_4;
    }
  }
  if (DAT_0067f35c == -1) {
    DAT_006410b0 = 0;
  }
  for (local_40 = 0; (int)local_40 < 8; local_40 = local_40 + 1) {
    val_4 = FUN_0040a36f(g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14),
                         g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_40 * 0x14));
    val_5 = abs(DAT_00641010 -
                ((int)(*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) +
                      (*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5));
    val_6 = abs(DAT_00641014 -
                ((int)(*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) +
                      (*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5));
    if (((int)local_40 < 6) &&
       (((*(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) == -1 || (4 < val_5)) || (4 < val_6)))) {
      do {
        val_5 = Util_GetRandomNumber(2);
        if (val_5 == 0) {
          val_5 = Util_GetRandomNumber(2);
          local_3c = (-(uint32_t)(val_5 == 0) & 0xfffffff8) + 4 + DAT_00641014;
          val_5 = Util_GetRandomNumber(9);
          local_28 = DAT_00641010 + val_5 + -4;
        }
        else {
          val_5 = Util_GetRandomNumber(2);
          local_28 = (-(uint32_t)(val_5 == 0) & 0xfffffff8) + 4 + DAT_00641010;
          val_5 = Util_GetRandomNumber(9);
          local_3c = DAT_00641014 + val_5 + -4;
        }
        uval_7 = FUN_0040c761(local_28,local_3c);
        uval_8 = Adventure_GetLocationEncounterIndex(uval_7);
      } while (uval_8 == 0);
      do {
        val_5 = Util_GetRandomNumber(6);
        local_44._0_1_ = (uint8_t)val_5;
        flag_3 = (uint8_t)local_44;
      } while ((uval_8 & 1 << ((uint8_t)local_44 & 0x1f)) == 0);
      local_44 = (int)(DAT_0067f384 + (DAT_0067f384 >> 0x1f & 7U)) >> 3;
      for (local_48 = 0; (int)local_48 < 1000; local_48 = local_48 + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == val_5) {
          local_44 = local_44 + 1;
        }
      }
      val_6 = FUN_0040a305((int)(0x80 / (longlong)(local_44 + 4)),6,0x14);
      val_6 = Util_GetRandomNumber(val_6);
      switch(val_6 + (int)(5 / (longlong)(local_44 + 1))) {
      case 0:
        local_24 = 10;
        break;
      case 1:
        local_24 = 10;
        break;
      case 2:
        local_24 = 10;
        break;
      case 3:
        local_24 = 0;
        break;
      case 4:
        local_24 = 10;
        break;
      case 5:
        local_24 = 8;
        break;
      case 6:
        local_24 = 6;
        break;
      case 7:
        local_24 = 4;
        break;
      case 8:
        local_24 = 6;
        break;
      case 9:
        local_24 = 0;
        break;
      case 10:
        local_24 = 4;
        break;
      case 0xb:
        local_24 = 6;
        break;
      case 0xc:
        local_24 = 0;
        break;
      case 0xd:
        local_24 = 4;
        break;
      case 0xe:
        local_24 = 0;
        break;
      case 0xf:
        local_24 = 4;
        break;
      default:
        local_24 = 0;
      }
      if (local_24 == 10) {
        local_24 = Util_GetRandomNumber(200);
        if (local_24 < 0x32) {
          local_24 = 10;
        }
        else if (local_24 < 0x55) {
          local_24 = 0xb;
        }
        else if (local_24 < 0x73) {
          local_24 = 0xc;
        }
        else if (local_24 < 0x8e) {
          local_24 = 0xd;
        }
        else if (local_24 < 0xa5) {
          local_24 = 0xe;
        }
        else if (local_24 < 0xb9) {
          local_24 = 0x10;
        }
        else if (local_24 < 200) {
          local_24 = 0x12;
        }
      }
      if (((local_40 == 0) && (g_AiHandEvaluationBuffer < 0)) && (-100 < g_AiHandEvaluationBuffer)) {
        local_24 = (int)(char)(&DAT_00522628)[g_AiHandEvaluationBuffer * -0x44];
      }
      if (local_24 == 0) {
        *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0;
      }
      else {
        local_24 = Adventure_CheckMonsterEncounter(val_5,local_24);
        *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = local_24;
        local_2c = 0;
        for (local_48 = 0; ((int)local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
            local_48 = local_48 + 1) {
          if ((((&DAT_0067b9b0)[local_48] & 0xf) == (&DAT_0052262a)[local_24 * 0x44]) &&
             ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == val_5)) {
            local_2c = local_2c + 1;
          }
        }
        if (8 < local_2c) {
          local_24 = -1;
          *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0xffffffff;
        }
      }
      *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) = local_28 * 0x20 + 0x10;
      *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) = local_3c * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + local_40 * 0x14) = val_5;
      (&DAT_0067f2e0)[local_40 * 0x14] = 0;
      (&DAT_0067f2e1)[local_40 * 0x14] = 0;
      if (((1 << (flag_3 & 0x1f) & (int)(char)(&DAT_0052262b)[local_24 * 0x44]) != 0) &&
         ((DAT_0067bdb4 & 1 << (flag_3 & 0x1f)) != 0)) {
        uval_8 = (int)(char)(&DAT_0052262b)[local_24 * 0x44] & ~(1 << (flag_3 & 0x1f));
        if ((uval_8 == 0) || ((uval_8 & DAT_0067bdb4) != 0)) {
          FUN_0046e70d(local_40,local_40 + 8);
          *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0xffffffff;
        }
        else if (uval_8 != 0) {
          uval_7 = Rules_CalculateManaCostReduction((uint8_t)uval_8);
          *(int *)(&DAT_0067f2dc + local_40 * 0x14) = uval_7;
        }
      }
      uval_8 = FUN_0040c7c0(local_28,local_3c);
      if ((uval_8 & 0x10) != 0) {
        FUN_0046e70d(local_40,local_40 + 8);
        *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0xffffffff;
      }
      if (((local_40 == 0) && (g_AiHandEvaluationBuffer < 0)) && (g_TownBuildingCoordinates != -g_AiHandEvaluationBuffer)) {
        FUN_0046e70d(0,8);
        g_TownBuildingCoordinates = -1;
      }
      if (*(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) < 1) {
        if (*(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) != -1) {
          for (local_6c = 0; (int)local_6c < 8; local_6c = local_6c + 1) {
            if (((*(int *)(&g_TownBuildingCoordinates + local_6c * 0x14) != -1) && (local_40 != local_6c)) &&
               ((*(int *)(&g_AiCardEvaluationScore + local_6c * 0x14) ==
                 *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) &&
                (*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) ==
                 *(int *)(&g_AiCardSynergyScore + local_6c * 0x14))))) {
              *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0xffffffff;
            }
          }
        }
      }
      else {
        FUN_0046e70d(local_40,local_40 + 8);
      }
    }
    val_5 = *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14);
    if (val_5 != -1) {
      if (0 < val_5) {
        Sprite_Load_BK_AMG_0046d333(val_5,local_40,local_40 + 8);
      }
      loop_idx = 1;
      switch((&DAT_0052262a)[val_5 * 0x44]) {
      case 0:
        local_34 = -1;
        loop_idx = 0;
        break;
      case 1:
        match_count = 1;
        local_34 = 0x20;
        loop_idx = 1;
        break;
      case 2:
        match_count = 1;
        local_34 = 0x20;
        loop_idx = 1;
        break;
      case 3:
        match_count = 1;
        local_34 = 0x30;
        loop_idx = 1;
        break;
      case 4:
        match_count = 1;
        local_34 = 0x30;
        loop_idx = 1;
        break;
      case 5:
        match_count = 1;
        local_34 = 0x40;
        loop_idx = 1;
        break;
      case 6:
        match_count = 1;
        local_34 = 0x60;
        loop_idx = 1;
        break;
      case 7:
        match_count = 1;
        local_34 = 0x60;
        loop_idx = 1;
        break;
      case 8:
        match_count = 1;
        local_34 = 0x40;
        loop_idx = 1;
        break;
      case 9:
        match_count = 1;
        local_34 = 0x20;
        loop_idx = 2;
        break;
      case 10:
        match_count = 1;
        local_34 = 0x30;
        loop_idx = 1;
      }
      local_34 = (local_34 * 3) / 2;
      if (((&DAT_00522631)[val_5 * 0x44] & 2) != 0) {
        local_34 = local_34 << 1;
      }
      player_idx = val_4;
      if (local_40 != card_idx) {
        local_34 = local_34 / 2;
      }
      for (; val_6 = abs(local_34), val_6 < player_idx; player_idx = player_idx / 2) {
        match_count = match_count << 1;
      }
      val_6 = *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14);
      status = *(int *)(&g_AiCardSynergyScore + local_40 * 0x14);
      if (DAT_006410dc == 0) {
        local_60 = g_OverworldMapPixelX - val_6;
        local_64 = g_OverworldMapPixelY - status;
      }
      else {
        iVar9 = FUN_0040a305(val_4 / 3,0,g_CampaignDifficultyLevel << 4);
        local_60 = (iVar9 * *(int *)(&DAT_00522378 + DAT_006410d4 * 4) + g_OverworldMapPixelX) - val_6;
        iVar9 = FUN_0040a305(val_4 / 3,0,g_CampaignDifficultyLevel << 4);
        local_64 = (iVar9 * *(int *)(&DAT_005223e0 + DAT_006410d4 * 4) + g_OverworldMapPixelY) - status;
      }
      if (((&DAT_00522630)[val_5 * 0x44] & 1) != 0) {
        loop_idx = 2;
      }
      if ((val_4 < 0x40) && ((int)local_40 < 7)) {
        local_2c = 0;
        for (local_48 = 0; ((int)local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
            local_48 = local_48 + 1) {
          if ((((&DAT_0067b9b0)[local_48] & 0xf) == (&DAT_0052262a)[val_5 * 0x44]) &&
             ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == *(int *)(&DAT_0067f2dc + local_40 * 0x14)
             )) {
            local_2c = local_2c + 1;
          }
        }
        if (g_CampaignDifficultyLevel + 3 <= local_2c) {
          local_60 = -local_60;
          local_64 = -local_64;
        }
      }
      if ((local_40 == 7) && (0x18 < val_4)) {
        iVar9 = Duel_GetCardDrawOriginY
                          ((int)(DAT_0067f360 + (DAT_0067f360 >> 0x1f & 0x1fU)) >> 5,
                           (int)(DAT_0067f364 + (DAT_0067f364 >> 0x1f & 0x1fU)) >> 5);
        local_60 = (*(int *)(&g_DungeonMapTileX + iVar9 * 100) * 0x20 - val_6) + (DAT_0067f37c & 0x1f);
        local_64 = (*(int *)(&g_DungeonMapTileY + iVar9 * 100) * 0x20 - status) +
                   ((DAT_0067f37c & 0x3e) >> 1);
      }
      uval_7 = FUN_0040c761((int)(*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) +
                                (*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                           (int)(*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) +
                                (*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5);
      iVar9 = Adventure_GetLocationEncounterIndex(uval_7);
      if (((((&DAT_00522630)[val_5 * 0x44] & 0xf8) != 0) &&
          ((*(uint32_t *)(&DAT_00522630 + val_5 * 0x44) & iVar9 << 3) != 0)) && (1 < match_count)) {
        match_count = match_count / 2;
      }
      local_5c = 0;
      local_60 = local_60 + *(int *)(&DAT_00522378 + (char)(&DAT_0067f2e0)[local_40 * 0x14] * 4) * 8
      ;
      local_64 = local_64 + *(int *)(&DAT_005223e0 + (char)(&DAT_0067f2e0)[local_40 * 0x14] * 4) * 8
      ;
      iVar9 = abs(local_64);
      iVar10 = abs(local_60);
      if (iVar9 * 2 < iVar10) {
        if (local_60 < 1) {
          local_5c = 7;
        }
        else {
          local_5c = 3;
        }
      }
      iVar9 = abs(local_60);
      iVar10 = abs(local_64);
      if (iVar9 * 2 < iVar10) {
        if (local_64 < 1) {
          local_5c = 1;
        }
        else {
          local_5c = 5;
        }
      }
      if (local_5c == 0) {
        if (local_60 < 1) {
          if (local_64 < 1) {
            local_5c = 8;
          }
          else {
            local_5c = 6;
          }
        }
        else if (local_64 < 1) {
          local_5c = 2;
        }
        else {
          local_5c = 4;
        }
      }
      if ((local_40 + DAT_0067f37c & 3) == 0) {
        (&DAT_0067f2e0)[local_40 * 0x14] = (uint8_t)local_5c;
      }
      else {
        local_5c = (int)(char)(&DAT_0067f2e0)[local_40 * 0x14];
      }
      *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) =
           *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) + *(int *)(&DAT_00522378 + local_5c * 4) * 4;
      *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) =
           *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) + *(int *)(&DAT_005223e0 + local_5c * 4) * 4;
      is_match = true;
      for (local_48 = 0; (int)local_48 < 6; local_48 = local_48 + 1) {
        if (((*(int *)(&g_TownBuildingCoordinates + local_48 * 0x14) != 0) && (local_40 != local_48)) &&
           ((0x1f < val_4 &&
            ((iVar9 = FUN_0040a36f(*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) -
                                   *(int *)(&g_AiCardEvaluationScore + local_48 * 0x14),
                                   *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) -
                                   *(int *)(&g_AiCardSynergyScore + local_48 * 0x14)), iVar9 < 0x20 &&
             (iVar10 = FUN_0040a36f(val_6 - *(int *)(&g_AiCardEvaluationScore + local_48 * 0x14),
                                    status - *(int *)(&g_AiCardSynergyScore + local_48 * 0x14)),
             iVar9 < iVar10)))))) {
          is_match = false;
        }
      }
      if (is_match) {
        if ((((&DAT_00522630)[val_5 * 0x44] & 4) != 0) && ((DAT_0067f37c & 0x3f) == 0)) {
          iVar9 = Util_GetRandomNumber(2);
          if (iVar9 == 0) {
            iVar9 = Util_GetRandomNumber(2);
            if (iVar9 == 0) {
              *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) =
                   *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) + -0x20;
            }
            else {
              *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) =
                   *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) + 0x20;
            }
          }
          else {
            iVar9 = Util_GetRandomNumber(2);
            if (iVar9 == 0) {
              *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) =
                   *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) + -0x20;
            }
            else {
              *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) =
                   *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) + 0x20;
            }
          }
        }
        uval_7 = FUN_0040c761((int)(*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) +
                                  (*(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                             (int)(*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) +
                                  (*(int *)(&g_AiCardSynergyScore + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5)
        ;
        uval_8 = Adventure_GetLocationEncounterIndex(uval_7);
        if ((((uval_8 & (int)(char)(&DAT_0052262b)[val_5 * 0x44]) == 0) && (-1 < local_34)) &&
           (local_40 != 7)) {
          *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) = val_6;
          *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) = status;
          uval_7 = FUN_0040c761((int)(val_6 + (val_6 >> 0x1f & 0x1fU)) >> 5,
                               (int)(status + (status >> 0x1f & 0x1fU)) >> 5);
          uval_8 = Adventure_GetLocationEncounterIndex(uval_7);
          (&DAT_0067f2e1)[local_40 * 0x14] = 0;
          if ((uval_8 & (int)(char)(&DAT_0052262b)[val_5 * 0x44]) == 0) {
            FUN_0046e70d(local_40,local_40 + 8);
            *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0xffffffff;
          }
        }
        else {
          *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) =
               *(int *)(&DAT_00522378 + local_5c * 4) * loop_idx + val_6;
          *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) =
               *(int *)(&DAT_005223e0 + local_5c * 4) * loop_idx + status;
          (&DAT_0067f2e0)[local_40 * 0x14] = (uint8_t)local_5c;
          (&DAT_0067f2e1)[local_40 * 0x14] = (&DAT_0067f2e1)[local_40 * 0x14] + '\x01';
          if ('\x04' < (char)(&DAT_0067f2e1)[local_40 * 0x14]) {
            (&DAT_0067f2e1)[local_40 * 0x14] = 1;
          }
        }
        val_6 = FUN_0040a36f(g_OverworldMapPixelX - *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14),
                             g_OverworldMapPixelY - *(int *)(&g_AiCardSynergyScore + local_40 * 0x14));
        if (val_6 < (int)((-(uint32_t)(*(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) == 0) & 10) + 0x10)) {
          SaveGame_SaveCampaignFile(3);
          val_4 = Dungeon_Process_004856b0(local_40,*(int *)(&DAT_0067f2dc + local_40 * 0x14));
          Overworld_LoadAdventureInterface800();
          if ((local_40 == 7) && (val_4 < 1)) {
            Adventure_NewsFlash_DominionSpell();
          }
          else if (local_40 == 7) {
            FUN_0040b3c2(0xd,DAT_0067f368);
            DAT_006410b0 = 0;
          }
          FUN_0046e70d(local_40,local_40 + 8);
          *(int *)(&g_TownBuildingCoordinates + local_40 * 0x14) = 0xffffffff;
          Adventure_LoadFacePalette(0);
          DAT_0067f37c = DAT_0067f37c | 0x1f;
          SaveGame_SaveCampaignFile(3);
        }
        else if (((val_5 != 0) && ((&DAT_0067f2e1)[local_40 * 0x14] != '\0')) &&
                ((val_4 < 0x50 && (val_6 = Util_GetRandomNumber(val_4), val_6 < 4)))) {
          Adventure_PlayMonsterEncounterSound
                    (val_5,0x68 - val_4 / 2,100 - val_4 / 3,
                     *(int *)(&DAT_00522378 +
                             ((int)(char)(&DAT_0067f2e0)[local_40 * 0x14] + 2U & 7) * 4) * 100);
        }
      }
      else {
        *(int *)(&g_AiCardEvaluationScore + local_40 * 0x14) = val_6;
        *(int *)(&g_AiCardSynergyScore + local_40 * 0x14) = status;
        (&DAT_0067f2e1)[local_40 * 0x14] = 0;
      }
    }
  }
  return;
}

/*
 * Adventure_GetLocationEncounterIndex
 * Purpose: Retrieve encounter table entry for current coordinate.
 * Procedure:
 * 1. Return encounter index for map tile.
 */
/*
 * Decompiled function: Adventure_GetLocationEncounterIndex
 * Entry Point: 004ea7a6
 * Size: 248 bytes
 */

int Adventure_GetLocationEncounterIndex(int arg1)

{
  int slot_idx;
  
  switch(arg1) {
  case 1:
    slot_idx = 4;
    break;
  case 2:
    slot_idx = 8;
    break;
  case 3:
    slot_idx = 2;
    break;
  case 4:
    slot_idx = 0x30;
    break;
  case 5:
    slot_idx = 0x10;
    break;
  case 6:
    slot_idx = 0x20;
    break;
  case 7:
    slot_idx = 0x24;
    break;
  case 8:
    slot_idx = 6;
    break;
  case 9:
    slot_idx = 0x14;
    break;
  case 10:
    slot_idx = 0x28;
    break;
  case 0xb:
    slot_idx = 10;
    break;
  case 0xc:
    slot_idx = 0x12;
    break;
  case 0xd:
    slot_idx = 0x22;
    break;
  case 0xe:
    slot_idx = 0xc;
    break;
  case 0xf:
    slot_idx = 0x18;
    break;
  default:
    slot_idx = 0;
  }
  return slot_idx;
}

/*
 * Adventure_SetLocationEncounterIndex
 * Purpose: Store encounter index for map coordinate.
 * Procedure:
 * 1. Write encounter index to coordinate map.
 */
/*
 * Decompiled function: Adventure_SetLocationEncounterIndex
 * Entry Point: 004ea8df
 * Size: 128 bytes
 */

int Adventure_SetLocationEncounterIndex(int arg1)

{
  int slot_idx;
  
  switch(arg1) {
  case 1:
    slot_idx = 2;
    break;
  case 2:
    slot_idx = 3;
    break;
  case 3:
    slot_idx = 1;
    break;
  default:
    slot_idx = 0;
    break;
  case 5:
    slot_idx = 4;
    break;
  case 6:
    slot_idx = 5;
  }
  return slot_idx;
}

/*
 * Adventure_CheckMonsterEncounter
 * Purpose: Test if enemy monster intercepts player on world map.
 * Procedure:
 * 1. Calculate distance between player and monster sprites.
 * 2. Trigger encounter if collision detected.
 */
/*
 * Decompiled function: Adventure_CheckMonsterEncounter
 * Entry Point: 004ea97c
 * Size: 157 bytes
 */

int Adventure_CheckMonsterEncounter(int arg1,int arg2)

{
  int status;
  int match_count;
  
  match_count = 0;
  while( true ) {
    status = Util_GetRandomNumber(DAT_00523524 + -1);
    status = status + 1;
    match_count = match_count + 1;
    if (0x3e6 < match_count) break;
    if (((char)(&DAT_00522628)[status * 0x44] == arg2) &&
       ((arg1 == 0 || ((1 << ((uint8_t)arg1 & 0x1f) & (int)(char)(&DAT_0052262b)[status * 0x44]) != 0)))
       ) break;
  }
  if (match_count == 999) {
    status = 0;
  }
  return status;
}

/*
 * Adventure_FormatNewsString
 * Purpose: Format news broadcast text buffer.
 * Procedure:
 * 1. Copy news headline into news string buffer.
 */
/*
 * Decompiled function: Adventure_FormatNewsString
 * Entry Point: 004eaa19
 * Size: 131 bytes
 */

void Adventure_FormatNewsString(int arg1,int arg2,int arg3)

{
  char c_res;
  size_t len_2;
  int card_idx;
  
  if (arg2 != 0) {
    Adventure_AppendNewsDetails((int)(char)(&DAT_00522600)[arg1 * 0x44],arg3);
  }
  card_idx = 0;
  len_2 = strlen(&g_OverworldWorldState);
  do {
    c_res = (&DAT_00522600)[arg1 * 0x44 + card_idx];
    (&g_OverworldWorldState)[card_idx + len_2] = c_res;
    card_idx = card_idx + 1;
  } while (c_res != '\0');
  return;
}

/*
 * Adventure_AppendNewsDetails
 * Purpose: Concatenate encounter details to news buffer.
 * Procedure:
 * 1. Append monster and town names to news text.
 */
/*
 * Decompiled function: Adventure_AppendNewsDetails
 * Entry Point: 004eaa9c
 * Size: 176 bytes
 */

int Adventure_AppendNewsDetails(int arg1,int arg2)

{
  switch(arg1) {
  case 0x41:
  case 0x45:
  case 0x49:
  case 0x4f:
  case 0x55:
  case 0x61:
  case 0x65:
  case 0x69:
  case 0x6f:
  case 0x75:
    if (arg2 == 0) {
      strcat(&g_OverworldWorldState,&DAT_0052f428);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_0052f424);
    }
    break;
  default:
    if (arg2 == 0) {
      strcat(&g_OverworldWorldState,&DAT_0052f430);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_0052f42c);
    }
  }
  return 0;
}

/*
 * Adventure_PlayMonsterEncounterSound
 * Purpose: Play audio cue for wandering monster.
 * Procedure:
 * 1. Identify monster creature type.
 * 2. Play corresponding monster sound effect WAV.
 */
/*
 * Decompiled function: Adventure_PlayMonsterEncounterSound
 * Entry Point: 004eabb2
 * Size: 340 bytes
 */

void Adventure_PlayMonsterEncounterSound(int x,int arg2,int arg3,int height)

{
  if (DAT_0052f068 == 0) {
    Pic_Subsystem_00423b93(0xf);
  }
  DAT_0052f068 = 0;
  switch((&DAT_0052262a)[x * 0x44]) {
  case 1:
    Adventure_Audio_InitSoundTrack(s_x_sound_malewiz_wav_0052f434,0xf,0);
    break;
  case 2:
    Adventure_Audio_InitSoundTrack(s_x_sound_fewiz_wav_0052f448,0xf,0);
    break;
  case 3:
    Adventure_Audio_InitSoundTrack(s_x_sound_knight_wav_0052f45c,0xf,0);
    break;
  case 4:
    Adventure_Audio_InitSoundTrack(s_x_sound_lord_wav_0052f470,0xf,0);
    break;
  case 5:
    Adventure_Audio_InitSoundTrack(s_x_sound_djinn_wav_0052f484,0xf,0);
    break;
  case 6:
    Adventure_Audio_InitSoundTrack(s_x_sound_troll_wav_0052f498,0xf,0);
    break;
  case 7:
    Adventure_Audio_InitSoundTrack(s_x_sound_wyrm_wav_0052f4ac,0xf,0);
    break;
  case 8:
    Adventure_Audio_InitSoundTrack(s_x_sound_dragon_wav_0052f4c0,0xf,0);
    break;
  case 9:
    Adventure_Audio_InitSoundTrack(s_x_sound_flyer_wav_0052f4d4,0xf,0);
    break;
  case 10:
    Adventure_Audio_InitSoundTrack(s_x_sound_archmage_wav_0052f4e8,0xf,0);
  }
  Adventure_Audio_PlayEffectAtVolume(0xf,arg2,arg3,-height);
  return;
}

/*
 * Adventure_TriggerDuelFromEncounter
 * Purpose: Transition from overworld encounter into duel arena.
 * Procedure:
 * 1. Initialize duel parameters.
 * 2. Launch tactical duel engine.
 */
/*
 * Decompiled function: Adventure_TriggerDuelFromEncounter
 * Entry Point: 004ead33
 * Size: 99 bytes
 */

void Adventure_TriggerDuelFromEncounter(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0xc; slot_idx = slot_idx + 1) {
    if ((0 < *(int *)(&DAT_005224ec + slot_idx * 0x10)) &&
       (*(int *)(&DAT_005224ec + slot_idx * 0x10) = *(int *)(&DAT_005224ec + slot_idx * 0x10) + -1,
       *(int *)(&DAT_005224ec + slot_idx * 0x10) == 0)) {
      Overworld_LoadAdventureInterface800();
    }
  }
  return;
}

/*
 * Adventure_ReloadWorldPalette
 * Purpose: Restore overworld 8-bit palette.
 * Procedure:
 * 1. Apply default world map palette.
 */
/*
 * Decompiled function: Adventure_ReloadWorldPalette
 * Entry Point: 004ead96
 * Size: 33 bytes
 */

void Adventure_ReloadWorldPalette(int arg1)

{
  DAT_005659b4 = 0xffffffff;
  Adventure_LoadFacePalette(arg1);
  return;
}

/*
 * Adventure_LoadFacePalette
 * Purpose: Load 64-color character portrait palette.
 * Procedure:
 * 1. Load advfac64.pic palette colors into GDI palette.
 */
/*
 * Decompiled function: Adventure_LoadFacePalette
 * Entry Point: 004eadb7
 * Size: 46 bytes
 */

void Adventure_LoadFacePalette(int arg1)

{
  if (arg1 != DAT_005659b4) {
    LoadPalNoPic(s_advfac64_pic_0052f500);
    DAT_005659b4 = arg1;
  }
  return;
}

/*
 * Adventure_NewsFlash_EnemyAttack
 * Purpose: Broadcast news alert: enemy wizard sends creature to attack town.
 * Procedure:
 * 1. Load newsback.pic and play newsflash.wav.
 * 2. Display animated news banner announcing attack.
 */
/*
 * Decompiled function: Adventure_NewsFlash_EnemyAttack
 * Entry Point: 004eade5
 * Size: 1279 bytes
 */

void Adventure_NewsFlash_EnemyAttack(void)

{
  int *i_ptr_1;
  uint8_t arg1;
  int u_temp;
  char *file_name;
  int aiStack_80 [7];
  uint32_t local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int aiStack_50 [7];
  int aiStack_34 [7];
  int target_idx;
  int player_idx;
  int card_idx;
  uint32_t match_count;
  int slot_idx;
  
  if (DAT_006410b0 == 0) {
    FUN_0040a3e1();
    for (target_idx = 0; target_idx < 7; target_idx = target_idx + 1) {
      aiStack_34[target_idx] = -1;
      aiStack_80[target_idx] = 0;
    }
    for (target_idx = 0; target_idx < 0x80; target_idx = target_idx + 1) {
      if (*(int *)(&g_CardSlot_CreatureType + target_idx * 100) == 4) {
        u_temp = FUN_0040c761(*(int *)(&g_DungeonMapTileX + target_idx * 100),
                             *(int *)(&g_DungeonMapTileY + target_idx * 100));
        arg1 = Adventure_GetLocationEncounterIndex(u_temp);
        local_60 = Rules_CalculateManaCostReduction(arg1);
        aiStack_34[local_60] = *(int *)(&g_DungeonMapTileX + target_idx * 100);
        aiStack_50[local_60] = *(int *)(&g_DungeonMapTileY + target_idx * 100);
      }
      if ((&DAT_0067be01)[target_idx * 100] != '\0') {
        i_ptr_1 = (int *)((int)aiStack_80 +
                        ((int)(*(uint32_t *)(&g_CardSlot_StatusFlags + target_idx * 100) & 0xffffff3f) >> 6));
        *i_ptr_1 = *i_ptr_1 + 1;
      }
    }
    local_5c = 0x7fff;
    local_60 = -1;
    for (local_64 = 0; (int)local_64 < 0x80; local_64 = local_64 + 1) {
      if (((((&DAT_0067be01)[local_64 * 100] == '\0') &&
           (*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != 4)) &&
          (*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != 1)) &&
         (*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != 5)) {
        local_58 = 0x7fff;
        for (target_idx = 1; target_idx < 6; target_idx = target_idx + 1) {
          if (aiStack_34[target_idx] != -1) {
            card_idx = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + local_64 * 100) - aiStack_34[target_idx],
                                    *(int *)(&g_DungeonMapTileY + local_64 * 100) - aiStack_50[target_idx])
            ;
            if (card_idx < local_58) {
              local_58 = card_idx;
              local_60 = target_idx;
            }
          }
        }
        slot_idx = Util_GetRandomNumber(0x80);
        slot_idx = slot_idx + aiStack_80[local_60] * 0x20;
        if (slot_idx < local_5c) {
          local_5c = slot_idx;
          match_count = local_64;
          local_54 = local_60;
        }
      }
    }
    local_60 = local_54;
    local_64 = match_count;
    if (local_54 != -1) {
      target_idx = 7;
      switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
      case 0:
        player_idx = 4;
        break;
      case 1:
        player_idx = 6;
        break;
      case 2:
        player_idx = 8;
        break;
      case 3:
        player_idx = 0xc;
        break;
      default:
        if (((&g_DungeonMapTileY)[match_count * 100] & 1) == 0) {
          player_idx = 0x10;
        }
        else {
          player_idx = 0xc;
        }
      }
      FUN_0046e70d(7,0xf);
      u_temp = Adventure_CheckMonsterEncounter(local_60,player_idx);
      *(int *)(&g_TownBuildingCoordinates + target_idx * 0x14) = u_temp;
      *(int *)(&g_AiCardEvaluationScore + target_idx * 0x14) =
           *(int *)(&g_DungeonMapTileX + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&g_AiCardSynergyScore + target_idx * 0x14) =
           *(int *)(&g_DungeonMapTileY + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + target_idx * 0x14) = local_60;
      DAT_006410b4 = DAT_006410b4 + 1;
      FUN_0040c81c(0x80,*(int *)(&g_DungeonMapTileX + local_64 * 100),
                   *(int *)(&g_DungeonMapTileY + local_64 * 100));
      Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f510,0x97,100,100,0);
      FUN_0040a95d(s_newsback_pic_0052f528);
      strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____0052f538);
      file_name = (char *)Mem_AllocOrFree_00473d7e(local_60);
      strcat(&g_OverworldWorldState,file_name);
      strcat(&g_OverworldWorldState,s_Wizard_sends_0052f550);
      Adventure_FormatNewsString(*(int *)(&g_TownBuildingCoordinates + target_idx * 0x14),1,0);
      strcat(&g_OverworldWorldState,s_to_attack_0052f560);
      Ai_TownEncounter_004c3b19(local_64);
      strcat(&g_OverworldWorldState,&DAT_0052f56c);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
      FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      Overworld_LoadAdventureInterface800();
      DAT_006410b0 = 1;
    }
  }
  return;
}

/*
 * Adventure_NewsFlash_Retaliation
 * Purpose: Broadcast news alert: retaliation attack against player town.
 * Procedure:
 * 1. Display news banner announcing retaliation raid.
 */
/*
 * Decompiled function: Adventure_NewsFlash_Retaliation
 * Entry Point: 004eb2f9
 * Size: 1302 bytes
 */

void Adventure_NewsFlash_Retaliation(int arg1)

{
  int *i_ptr_1;
  uint8_t arg_1_00;
  int u_temp;
  char *file_name;
  int aiStack_80 [7];
  uint32_t local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int aiStack_50 [7];
  int aiStack_34 [7];
  int target_idx;
  int player_idx;
  int card_idx;
  uint32_t match_count;
  int slot_idx;
  
  if (DAT_006410b0 == 0) {
    FUN_0040a3e1();
    for (target_idx = 0; target_idx < 7; target_idx = target_idx + 1) {
      aiStack_34[target_idx] = -1;
      aiStack_80[target_idx] = 0;
    }
    for (target_idx = 0; target_idx < 0x80; target_idx = target_idx + 1) {
      if (*(int *)(&g_CardSlot_CreatureType + target_idx * 100) == 4) {
        u_temp = FUN_0040c761(*(int *)(&g_DungeonMapTileX + target_idx * 100),
                             *(int *)(&g_DungeonMapTileY + target_idx * 100));
        arg_1_00 = Adventure_GetLocationEncounterIndex(u_temp);
        local_60 = Rules_CalculateManaCostReduction(arg_1_00);
        if (local_60 == arg1) {
          aiStack_34[local_60] = *(int *)(&g_DungeonMapTileX + target_idx * 100);
          aiStack_50[local_60] = *(int *)(&g_DungeonMapTileY + target_idx * 100);
        }
      }
      if ((&DAT_0067be01)[target_idx * 100] != '\0') {
        i_ptr_1 = (int *)((int)aiStack_80 +
                        ((int)(*(uint32_t *)(&g_CardSlot_StatusFlags + target_idx * 100) & 0xffffff3f) >> 6));
        *i_ptr_1 = *i_ptr_1 + 1;
      }
    }
    local_5c = 0x7fff;
    for (local_64 = 0; (int)local_64 < 0x80; local_64 = local_64 + 1) {
      if (((((&DAT_0067be01)[local_64 * 100] == '\0') &&
           (*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != 4)) &&
          (*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != 1)) &&
         (*(int *)(&g_CardSlot_CreatureType + local_64 * 100) != 5)) {
        local_58 = 0x7fff;
        for (target_idx = 1; target_idx < 6; target_idx = target_idx + 1) {
          if (aiStack_34[target_idx] != -1) {
            card_idx = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + local_64 * 100) - aiStack_34[target_idx],
                                    *(int *)(&g_DungeonMapTileY + local_64 * 100) - aiStack_50[target_idx])
            ;
            if (card_idx < local_58) {
              local_58 = card_idx;
              local_60 = target_idx;
            }
          }
        }
        slot_idx = Util_GetRandomNumber(0x80);
        slot_idx = slot_idx + aiStack_80[local_60] * 0x20;
        if (slot_idx < local_5c) {
          local_5c = slot_idx;
          match_count = local_64;
          local_54 = local_60;
        }
      }
    }
    local_60 = local_54;
    local_64 = match_count;
    if (local_54 != -1) {
      target_idx = 7;
      switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
      case 0:
        player_idx = 4;
        break;
      case 1:
        player_idx = 6;
        break;
      case 2:
        player_idx = 8;
        break;
      case 3:
        player_idx = 0xc;
        break;
      default:
        if (((&g_DungeonMapTileY)[match_count * 100] & 1) == 0) {
          player_idx = 0x10;
        }
        else {
          player_idx = 0xc;
        }
      }
      FUN_0046e70d(7,0xf);
      u_temp = Adventure_CheckMonsterEncounter(local_60,player_idx);
      *(int *)(&g_TownBuildingCoordinates + target_idx * 0x14) = u_temp;
      *(int *)(&g_AiCardEvaluationScore + target_idx * 0x14) =
           *(int *)(&g_DungeonMapTileX + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&g_AiCardSynergyScore + target_idx * 0x14) =
           *(int *)(&g_DungeonMapTileY + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + target_idx * 0x14) = local_60;
      DAT_006410b4 = DAT_006410b4 + 1;
      FUN_0040c81c(0x80,*(int *)(&g_DungeonMapTileX + local_64 * 100),
                   *(int *)(&g_DungeonMapTileY + local_64 * 100));
      Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f570,0x97,100,100,0);
      FUN_0040a95d(s_newsback_pic_0052f588);
      strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____0052f598);
      strcat(&g_OverworldWorldState,s_In_retaliation_for_your_effronte_0052f5ac);
      file_name = (char *)Mem_AllocOrFree_00473d7e(local_60);
      strcat(&g_OverworldWorldState,file_name);
      strcat(&g_OverworldWorldState,s_Wizard_sends_0052f5dc);
      Adventure_FormatNewsString(*(int *)(&g_TownBuildingCoordinates + target_idx * 0x14),1,0);
      strcat(&g_OverworldWorldState,s_to_attack_0052f5ec);
      Ai_TownEncounter_004c3b19(local_64);
      strcat(&g_OverworldWorldState,&DAT_0052f5f8);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
      FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      Overworld_LoadAdventureInterface800();
      DAT_006410b0 = 1;
    }
  }
  return;
}

/*
 * Adventure_NewsFlash_DominionSpell
 * Purpose: Broadcast news alert: wizard casts Spell of Dominion.
 * Procedure:
 * 1. Display warning that enemy wizard is casting Dominion spell.
 * 2. Display mana taps remaining.
 */
/*
 * Decompiled function: Adventure_NewsFlash_DominionSpell
 * Entry Point: 004eb824
 * Size: 1208 bytes
 */

void Adventure_NewsFlash_DominionSpell(void)

{
  char *char_ptr_1;
  LONG arg2;
  int val_result;
  int local_34 [9];
  uint32_t card_idx;
  int match_count;
  int slot_idx;
  
  local_34[7] = 7;
  DAT_006410b0 = 0;
  if (DAT_0067f35c != -1) {
    FUN_0040a3e1();
    card_idx = *(uint32_t *)(&DAT_0067f2dc + local_34[7] * 0x14);
    local_34[8] = Duel_GetCardDrawOriginY
                            ((int)(*(int *)(&g_AiCardEvaluationScore + local_34[7] * 0x14) +
                                  (*(int *)(&g_AiCardEvaluationScore + local_34[7] * 0x14) >> 0x1f & 0x1fU)) >>
                             5,(int)(*(int *)(&g_AiCardSynergyScore + local_34[7] * 0x14) +
                                    (*(int *)(&g_AiCardSynergyScore + local_34[7] * 0x14) >> 0x1f & 0x1fU))
                               >> 5);
    *(uint32_t *)(&g_CardSlot_StatusFlags + local_34[8] * 100) =
         *(uint32_t *)(&g_CardSlot_StatusFlags + local_34[8] * 100) & 0xffff00ff;
    *(uint32_t *)(&g_CardSlot_StatusFlags + local_34[8] * 100) =
         *(uint32_t *)(&g_CardSlot_StatusFlags + local_34[8] * 100) | card_idx << 8;
    local_34[6] = 0;
    for (slot_idx = 0; slot_idx < 0x80; slot_idx = slot_idx + 1) {
      if (*(int *)(&g_CardSlot_StatusFlags + slot_idx * 100) >> 8 == card_idx) {
        local_34[6] = local_34[6] + 1;
      }
    }
    if (DAT_00522598 == 0) {
      match_count = 5;
    }
    else {
      match_count = 3;
    }
    Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f5fc,0x97,100,100,0);
    FUN_0040a95d(s_newsback_pic_0052f614);
    local_34[1] = 0;
    local_34[2] = 1;
    local_34[3] = 0;
    local_34[4] = 1;
    local_34[5] = 0;
    strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____The_Evil_0052f624);
    char_ptr_1 = (char *)Mem_AllocOrFree_00473d7e(card_idx);
    strcat(&g_OverworldWorldState,char_ptr_1);
    strcat(&g_OverworldWorldState,s_Wizard_taps_0052f644);
    Ai_TownEncounter_004c3b19(local_34[8]);
    if (match_count == local_34[6]) {
      if (local_34[card_idx] == 0) {
        strcat(&g_OverworldWorldState,s___He_casts_the_spell_of_Dominion_0052f6c4);
      }
      else {
        strcat(&g_OverworldWorldState,s___She_casts_the_spell_of_Dominio_0052f6a0);
      }
    }
    else {
      if (local_34[card_idx] == 0) {
        strcat(&g_OverworldWorldState,s___He_needs_0052f664);
      }
      else {
        strcat(&g_OverworldWorldState,s___She_needs_0052f654);
      }
      char_ptr_1 = _itoa(match_count - local_34[6],&DAT_005659c8,10);
      strcat(&g_OverworldWorldState,char_ptr_1);
      strcat(&g_OverworldWorldState,s_more_mana_taps_to_cast_the_Spell_0052f670);
    }
    if (((&g_CardSlot_StatusFlags)[local_34[8] * 100] & 1) != 0) {
      *(uint32_t *)(&g_CardSlot_StatusFlags + local_34[8] * 100) =
           *(uint32_t *)(&g_CardSlot_StatusFlags + local_34[8] * 100) & 0xfffffffe;
      strcat(&g_OverworldWorldState,s_Your_mana_tap_here_is_lost__0052f6e8);
    }
    DAT_006410b4 = DAT_006410b4 + 1;
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
    FUN_0040a3e1();
    Ai_Subsystem_004cd1d1();
    FUN_0046e70d(local_34[7],local_34[7] + 8);
    *(int *)(&g_TownBuildingCoordinates + local_34[7] * 0x14) = 0xffffffff;
    Adventure_Map_UpdateLightingAndPalette(3,card_idx);
    Overworld_LoadAdventureInterface800();
    DAT_006410b0 = 0;
    if (match_count <= local_34[6]) {
      FUN_005112b0(0,(short)g_MidiMusicTrackId);
      Mem_AllocOrFree_00510de0(1,s_uth_arz_pic_0052f708);
      g_OverworldWorldState = 0;
      if ((g_AiManaColorCost_Red == 0x280) || (g_AiManaColorCost_Red == 800)) {
        local_34[0] = 0x14;
      }
      else {
        local_34[0] = 0x10;
      }
      *(int *)(g_DisplaySurfaceBackBuffer + 0x20) = 5;
      arg2 = Ai_Util_004c3bc4(local_34[0]);
      FUN_0050f2e0(5,arg2);
      strcat(&g_OverworldWorldState,s_Your_Righteous_Quest_has_Failed_0052f714);
      strcat(&g_OverworldWorldState,s_The_Evil_Planeswalker_Arzakon_an_0052f738);
      char_ptr_1 = (char *)Mem_AllocOrFree_00473d7e(card_idx);
      strcat(&g_OverworldWorldState,char_ptr_1);
      strcat(&g_OverworldWorldState,s_Wizard_have_attained_Dominion_ov_0052f770);
      strcat(&g_OverworldWorldState,s_The_people_will_suffer_a_thousan_0052f7b0);
      val_result = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceBackBuffer + 0x20));
      FUN_0040d269((int)g_DisplaySurfaceBackBuffer,0xea,0x140,val_result * -7 + 0x1e0);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_005112b0(0,(short)g_MidiMusicTrackId);
      DAT_006fe3f0 = 1;
      Subsystem_FreeStatWinDll();
      Palette_Util_00496d20();
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  }
  DAT_006410b0 = 0;
  return;
}

/*
 * Adventure_Audio_PlayEffect
 * Purpose: Play sound effect with voice channel allocation.
 * Procedure:
 * 1. Allocate audio channel.
 * 2. Stream WAV audio data.
 */
/*
 * Decompiled function: Adventure_Audio_PlayEffect
 * Entry Point: 004ebcdc
 * Size: 134 bytes
 */

void Adventure_Audio_PlayEffect(char *arg1,int arg2,int arg3,int arg4,int arg5)

{
  int local_24;
  int loop_idx;
  int color_idx;
  uint32_t slot_idx;
  
  Pic_Subsystem_00423b93(arg2);
  Adventure_Audio_InitSoundTrack(arg1,arg2,0);
  memset(&local_24,0,0x20);
  local_24 = arg3 << 2;
  loop_idx = (arg4 * 0x5622) / 100;
  color_idx = arg5 << 2;
  slot_idx = slot_idx & 0xffffffee;
  Pic_Subsystem_00423bf4(arg2,&local_24);
  return;
}

/*
 * Adventure_Audio_PlayEffectAtVolume
 * Purpose: Play sound effect at specified volume level.
 * Procedure:
 * 1. Set volume gain and play sound effect.
 */
/*
 * Decompiled function: Adventure_Audio_PlayEffectAtVolume
 * Entry Point: 004ebd62
 * Size: 104 bytes
 */

void Adventure_Audio_PlayEffectAtVolume(int arg1,int y,int width,int height)

{
  int local_24;
  int loop_idx;
  int color_idx;
  uint32_t slot_idx;
  
  memset(&local_24,0,0x20);
  local_24 = y << 2;
  loop_idx = (width * 0x5622) / 100;
  color_idx = height << 2;
  slot_idx = slot_idx & 0xffffffee;
  Pic_Subsystem_00423bf4(arg1,&local_24);
  return;
}

/*
 * Adventure_Audio_PlayEffectLooped
 * Purpose: Play looped ambient sound effect.
 * Procedure:
 * 1. Configure sound track for continuous looping.
 */
/*
 * Decompiled function: Adventure_Audio_PlayEffectLooped
 * Entry Point: 004ebdca
 * Size: 80 bytes
 */

void Adventure_Audio_PlayEffectLooped(int arg1,int arg2,int arg3)

{
  int local_24 [7];
  uint32_t slot_idx;
  
  memset(local_24,0,0x20);
  local_24[0] = arg2 << 2;
  local_24[1] = 0x5622;
  local_24[2] = arg3 << 2;
  slot_idx = slot_idx | 1;
  Pic_Subsystem_00423bf4(arg1,local_24);
  return;
}

/*
 * Adventure_Audio_StopEffectChannel
 * Purpose: Stop specific audio effect channel.
 * Procedure:
 * 1. Halt playback on audio channel.
 */
/*
 * Decompiled function: Adventure_Audio_StopEffectChannel
 * Entry Point: 004ebe1a
 * Size: 71 bytes
 */

void Adventure_Audio_StopEffectChannel(int arg1,int arg2,int arg3)

{
  int local_24 [8];
  
  memset(local_24,0,0x20);
  local_24[0] = arg2 << 2;
  local_24[1] = 0x5622;
  local_24[2] = arg3 << 2;
  Pic_Subsystem_00423bf4(arg1,local_24);
  return;
}

/*
 * Adventure_Audio_SetPlaybackPosition
 * Purpose: Set sound track marker offset.
 * Procedure:
 * 1. Seek to position in audio stream.
 */
/*
 * Decompiled function: Adventure_Audio_SetPlaybackPosition
 * Entry Point: 004ebe61
 * Size: 94 bytes
 */

void Adventure_Audio_SetPlaybackPosition(char *arg1,int arg2)

{
  int local_24;
  int loop_idx;
  int color_idx;
  uint32_t slot_idx;
  
  memset(&local_24,0,0x20);
  slot_idx = slot_idx | 4;
  local_24 = 400;
  loop_idx = 0;
  color_idx = 0;
  Adventure_Audio_InitSoundTrack(arg1,arg2,&local_24);
  Pic_Subsystem_00423f10(arg2,1);
  return;
}

/*
 * Adventure_Audio_StopAllTracks
 * Purpose: Stop all digital audio streaming channels.
 * Procedure:
 * 1. Stop all active WAV playback.
 */
/*
 * Decompiled function: Adventure_Audio_StopAllTracks
 * Entry Point: 004ebebf
 * Size: 44 bytes
 */

void Adventure_Audio_StopAllTracks(void)

{
  if (DAT_0052f014 != 0) {
    Pic_Subsystem_00423c82(0x10);
  }
  DAT_0052f014 = 0;
  return;
}

/*
 * Adventure_Audio_PlayCastleVictory
 * Purpose: Play castle victory fanfare.
 * Procedure:
 * 1. Play castle victory WAV corresponding to castle color.
 */
/*
 * Decompiled function: Adventure_Audio_PlayCastleVictory
 * Entry Point: 004ebeeb
 * Size: 231 bytes
 */

void Adventure_Audio_PlayCastleVictory(int arg1)

{
  Adventure_Audio_StopAllTracks();
  if (DAT_0052f018 != -1) {
    Pic_Subsystem_00423b93(0x10);
  }
  DAT_0052f018 = arg1 + 0x15;
  switch(arg1) {
  case 1:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_bcastle_wav_0052f860,0x10);
    break;
  case 2:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_ucastle_wav_0052f874,0x10);
    break;
  case 3:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_gcastle_wav_0052f888,0x10);
    break;
  case 4:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_rcastle_wav_0052f89c,0x10);
    break;
  case 5:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_wcastle_wav_0052f8b0,0x10);
    break;
  case 6:
    Adventure_Audio_SetPlaybackPosition(s_x_sound_wingame_wav_0052f8c4,0x10);
  }
  Adventure_Audio_PlayEffectLooped(0x10,100,0);
  DAT_0052f014 = 1;
  return;
}

/*
 * Adventure_Audio_PlayDuelIntro
 * Purpose: Play duel intro fanfare.
 * Procedure:
 * 1. Play dueltune.wav audio track.
 */
/*
 * Decompiled function: Adventure_Audio_PlayDuelIntro
 * Entry Point: 004ebfef
 * Size: 102 bytes
 */

void Adventure_Audio_PlayDuelIntro(int arg1)

{
  if (DAT_0052f018 != -1) {
    Pic_Subsystem_00423b93(0x10);
  }
  DAT_0052f018 = 0x15;
  DAT_0052f064 = 0xffffffff;
  Adventure_Audio_SetPlaybackPosition((&PTR_s_x_sound_dueltune_wav_0052f070)[arg1],0x10);
  Adventure_Audio_StopEffectChannel(0x10,0x80,0);
  DAT_0052f014 = 1;
  return;
}

/*
 * Adventure_Audio_PlayTerrainAmbience
 * Purpose: Play ambient biome sound effects and bird calls.
 * Procedure:
 * 1. Select ambient WAV based on terrain biome (plains, forest, swamp, etc.).
 */
/*
 * Decompiled function: Adventure_Audio_PlayTerrainAmbience
 * Entry Point: 004ec055
 * Size: 680 bytes
 */

void Adventure_Audio_PlayTerrainAmbience(int arg1)

{
  int arg_1_00;
  int status;
  int val_result;
  
  arg_1_00 = arg1 + 9;
  status = Util_GetRandomNumber(200);
  status = status + -100;
  val_result = Util_GetRandomNumber(0x32);
  Adventure_Audio_PlayEffectAtVolume(arg_1_00,100,val_result + 0x46,status);
  status = Util_GetRandomNumber(3);
  if (status == 0) {
    Pic_Subsystem_00423b93(arg_1_00);
    switch(arg1) {
    case 1:
      status = Util_GetRandomNumber(3);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_kbird1_wav_0052f8d8,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_kland1_wav_0052f8ec,arg_1_00,0);
      }
      else if (status == 2) {
        Adventure_Audio_InitSoundTrack(s_x_sound_kland2_wav_0052f900,arg_1_00,0);
      }
      break;
    case 2:
      status = Util_GetRandomNumber(3);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_bbird1_wav_0052f914,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_bland1_wav_0052f928,arg_1_00,0);
      }
      else if (status == 2) {
        Adventure_Audio_InitSoundTrack(s_x_sound_bland2_wav_0052f93c,arg_1_00,0);
      }
      break;
    case 3:
      status = Util_GetRandomNumber(2);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_gbird1_wav_0052f950,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_gland1_wav_0052f964,arg_1_00,0);
      }
      break;
    case 4:
      status = Util_GetRandomNumber(2);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_rbird1_wav_0052f978,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_rland1_wav_0052f98c,arg_1_00,0);
      }
      break;
    case 5:
      status = Util_GetRandomNumber(2);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_wbird1_wav_0052f9a0,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_wland1_wav_0052f9b4,arg_1_00,0);
      }
    }
  }
  return;
}

/*
 * Adventure_Audio_PlayFootstep
 * Purpose: Play footstep walking sound effects by terrain type.
 * Procedure:
 * 1. Play terrain-specific walking audio clip.
 */
/*
 * Decompiled function: Adventure_Audio_PlayFootstep
 * Entry Point: 004ec32f
 * Size: 266 bytes
 */

void Adventure_Audio_PlayFootstep(void)

{
  Adventure_Audio_InitSoundTrack(s_x_sound_kwalkl_wav_0052f9c8,0,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_kwalkr_wav_0052f9dc,1,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_bwalkl_wav_0052f9f0,2,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_bwalkr_wav_0052fa04,3,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_gwalkl_wav_0052fa18,4,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_gwalkr_wav_0052fa2c,5,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_rwalkl_wav_0052fa40,6,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_rwalkr_wav_0052fa54,7,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_wwalkl_wav_0052fa68,8,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_wwalkr_wav_0052fa7c,9,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_kbird1_wav_0052fa90,10,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_bbird1_wav_0052faa4,0xb,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_gbird1_wav_0052fab8,0xc,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_rbird1_wav_0052facc,0xd,0);
  Adventure_Audio_InitSoundTrack(s_x_sound_wbird1_wav_0052fae0,0xe,0);
  return;
}

/*
 * Adventure_Audio_FindSoundOnDrives
 * Purpose: Search optical drive paths for streaming sound assets.
 * Procedure:
 * 1. Iterate drive letters to find game asset directory.
 */
/*
 * Decompiled function: Adventure_Audio_FindSoundOnDrives
 * Entry Point: 004ec439
 * Size: 190 bytes
 */

uint32_t Adventure_Audio_FindSoundOnDrives(char *name_or_path)

{
  UINT UVar1;
  FILE *_File;
  int val_result;
  int *u_ptr_3;
  uint32_t local_104;
  int local_100 [63];
  
  local_104 = DAT_0052faf4;
  u_ptr_3 = local_100;
  for (val_result = 0x3f; val_result != 0; val_result = val_result + -1) {
    *u_ptr_3 = 0;
    u_ptr_3 = u_ptr_3 + 1;
  }
  do {
    if (0x7a < (char)local_104) {
      return (int)(char)local_104;
    }
    UVar1 = GetDriveTypeA((LPCSTR)&local_104);
    if (UVar1 == 5) {
      strcat((char *)&local_104,name_or_path);
      _File = fopen((char *)&local_104,&DAT_0052faf8);
      if (_File != (FILE *)0x0) {
        fclose(_File);
        return local_104 & 0xff;
      }
      local_104._0_3_ = (uint3)(uint16_t)local_104;
    }
    local_104 = CONCAT31(local_104._1_3_,(char)local_104 + '\x01');
  } while( true );
}

/*
 * Adventure_Audio_GetMusicDrivePath
 * Purpose: Locate music WAV files on installation drive.
 * Procedure:
 * 1. Return path to sound\locmus1.wav.
 */
/*
 * Decompiled function: Adventure_Audio_GetMusicDrivePath
 * Entry Point: 004ec4fc
 * Size: 113 bytes
 */

char Adventure_Audio_GetMusicDrivePath(void)

{
  char c_res;
  char local_104 [256];
  
  if (DAT_005659d8 == 0) {
    DAT_00641018 = Adventure_Audio_FindSoundOnDrives(s_sound_locmus1_wav_0052fafc);
    DAT_005659d8 = 1;
  }
  c_res = DAT_00641018;
  if (DAT_00626828 == 0) {
    _getcwd(local_104,0x100);
    c_res = local_104[0];
  }
  return c_res;
}

/*
 * Adventure_Audio_FreeSoundTrack
 * Purpose: Free allocated sound track memory buffers.
 * Procedure:
 * 1. Release sound track memory.
 */
/*
 * Decompiled function: Adventure_Audio_FreeSoundTrack
 * Entry Point: 004ec572
 * Size: 76 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Adventure_Audio_FreeSoundTrack(void *arg1)

{
  _DAT_00640f0c = _DAT_00640f0c + 1;
  Pic_Subsystem_00423b57(arg1,*(int *)((int)arg1 + 0x100),(int)arg1 + 0x104);
  free(arg1);
  _DAT_00640f0c = _DAT_00640f0c + -1;
  return;
}

/*
 * Adventure_Audio_InitSoundTrack
 * Purpose: Load and initialize WAV audio stream.
 * Procedure:
 * 1. Open WAV file and initialize audio streaming buffer.
 */
/*
 * Decompiled function: Adventure_Audio_InitSoundTrack
 * Entry Point: 004ec5be
 * Size: 156 bytes
 */

int Adventure_Audio_InitSoundTrack(char *name_or_path,int arg2,int arg3)

{
  char c_res;
  int val_result;
  
  if (DAT_005659c0 == 0) {
    _getcwd(&DAT_00640f10,0x100);
    DAT_005659c0 = 1;
  }
  if (*name_or_path == 'x') {
    *name_or_path = DAT_00640f10;
    val_result = FUN_00406b01(name_or_path);
    if (val_result == 0) {
      c_res = Adventure_Audio_GetMusicDrivePath();
      *name_or_path = c_res;
    }
  }
  do {
  } while (DAT_0062681c != 0);
  Pic_Subsystem_00423b57(name_or_path,arg2,arg3);
  return 0;
}

/*
 * Adventure_Audio_GetTrackStatus
 * Purpose: Query active audio track playback state.
 * Procedure:
 * 1. Return track status code.
 */
/*
 * Decompiled function: Adventure_Audio_GetTrackStatus
 * Entry Point: 004ec65a
 * Size: 115 bytes
 */

int Adventure_Audio_GetTrackStatus(int arg1)

{
  int u_res;
  
  switch(arg1) {
  case 1:
    u_res = 4;
    break;
  case 2:
    u_res = 2;
    break;
  case 3:
    u_res = 3;
    break;
  case 4:
    u_res = 1;
    break;
  case 5:
    u_res = 0;
    break;
  case 6:
    u_res = 5;
    break;
  default:
    u_res = 0xffffffff;
  }
  return u_res;
}

/*
 * Adventure_Map_GetTerrainAtCoord
 * Purpose: Query map terrain tile at coordinate.
 * Procedure:
 * 1. Read tile type from world map grid.
 */
/*
 * Decompiled function: Adventure_Map_GetTerrainAtCoord
 * Entry Point: 004ec6ea
 * Size: 271 bytes
 */

int Adventure_Map_GetTerrainAtCoord(uint32_t arg1)

{
  int local_24;
  int loop_idx;
  int color_idx;
  uint32_t target_idx [5];
  
  color_idx = 0;
  target_idx[0] = arg1 & 0x20;
  target_idx[1] = arg1 & 0x10;
  target_idx[2] = arg1 & 4;
  target_idx[3] = arg1 & 8;
  target_idx[4] = arg1 & 2;
  for (loop_idx = 0; loop_idx < 5; loop_idx = loop_idx + 1) {
    if (target_idx[loop_idx] != 0) {
      color_idx = color_idx + 1;
    }
  }
  if (color_idx == 1) {
    for (loop_idx = 0; loop_idx < 5; loop_idx = loop_idx + 1) {
      if (target_idx[loop_idx] != 0) {
        return loop_idx;
      }
    }
  }
  else {
    local_24 = Util_GetRandomNumber(color_idx);
    local_24 = local_24 + 1;
    for (loop_idx = 0; loop_idx < 5; loop_idx = loop_idx + 1) {
      if (target_idx[loop_idx] != 0) {
        local_24 = local_24 + -1;
      }
      if (local_24 == 0) {
        return loop_idx;
      }
    }
  }
  return -1;
}

/*
 * Adventure_Map_RedrawViewport
 * Purpose: Redraw overworld campaign view area and monster sprites.
 * Procedure:
 * 1. Blit terrain tiles and draw monster sprites.
 */
/*
 * Decompiled function: Adventure_Map_RedrawViewport
 * Entry Point: 004ec7f9
 * Size: 405 bytes
 */

void Adventure_Map_RedrawViewport(void)

{
  int status;
  int val_result;
  int temp_idx;
  int local_4c;
  int local_48;
  int local_44;
  int local_3c [5];
  int aiStack_28 [5];
  uint8_t auStack_14 [5];
  uint8_t local_f;
  uint8_t local_e;
  uint8_t local_d;
  int slot_idx;
  
  for (local_44 = 0; local_44 < 5; local_44 = local_44 + 1) {
    local_4c = 0;
    slot_idx = 0;
    status = Adventure_Audio_GetTrackStatus(local_44 + 1);
    for (local_48 = 0; local_48 < 0x80; local_48 = local_48 + 1) {
      if (((&DAT_0067be01)[local_48 * 100] != '\0') &&
         ((*(int *)(&g_CardSlot_StatusFlags + local_48 * 100) >> 8) + -1 == local_44)) {
        slot_idx = slot_idx + 1;
      }
    }
    auStack_14[status] = (uint8_t)slot_idx;
    if (*(int *)(&DAT_006410c0 + local_44 * 4) == 0) {
      val_result = g_CampaignDifficultyLevel * slot_idx + g_CampaignDifficultyLevel * 5 + 0x1e;
      for (local_48 = 0; (local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
          local_48 = local_48 + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == local_44 + 1) {
          local_4c = local_4c + 1;
        }
      }
      aiStack_28[status] = local_4c;
      temp_idx = g_CampaignDifficultyLevel * 5 + 0x14;
      local_4c = val_result - local_4c;
      if (temp_idx <= local_4c) {
        temp_idx = local_4c;
      }
      local_3c[status] = 0x1e - (val_result - temp_idx);
    }
    else {
      local_3c[status] = 0;
    }
  }
  local_f = 0;
  local_e = 0;
  local_d = 0;
  Mem_AllocOrFree_00409e3c(local_3c);
  return;
}

/*
 * Adventure_Map_UpdateLightingAndPalette
 * Purpose: Apply day/night cycle palette fade.
 * Procedure:
 * 1. Load todpal.tr and update ambient palette lighting.
 */
/*
 * Decompiled function: Adventure_Map_UpdateLightingAndPalette
 * Entry Point: 004ec98e
 * Size: 841 bytes
 */

int Adventure_Map_UpdateLightingAndPalette(uint32_t arg1,uint32_t arg2)

{
  uint32_t local_40 [7];
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  FUN_005112b0(0,(short)g_MidiMusicTrackId);
  FUN_0050d560(0,0);
  LoadPalNoPic(s_advfac64_pic_0052fb10);
  player_idx = GetThreadPriority(DAT_00627850);
  for (target_idx = 0; target_idx < 5; target_idx = target_idx + 1) {
    loop_idx = 0;
    match_count = 0;
    local_24 = Adventure_Audio_GetTrackStatus(target_idx + 1);
    for (color_idx = 0; color_idx < 0x80; color_idx = color_idx + 1) {
      if (((&DAT_0067be01)[color_idx * 100] != '\0') &&
         ((*(int *)(&g_CardSlot_StatusFlags + color_idx * 100) >> 8) + -1 == target_idx)) {
        match_count = match_count + 1;
      }
    }
    (&DAT_00641058)[local_24] = (uint8_t)match_count;
    if (*(int *)(&DAT_006410c0 + target_idx * 4) == 0) {
      card_idx = g_CampaignDifficultyLevel * match_count + g_CampaignDifficultyLevel * 5 + 0x1e;
      for (color_idx = 0; (color_idx < 1000 && ((&DAT_0067b9b0)[color_idx] != '\0'));
          color_idx = color_idx + 1) {
        if ((int)(char)(&DAT_0067b9b0)[color_idx] >> 4 == target_idx + 1) {
          loop_idx = loop_idx + 1;
        }
      }
      *(int *)(&DAT_00641044 + local_24 * 4) = loop_idx;
      local_40[6] = g_CampaignDifficultyLevel * 5 + 0x14;
      if ((int)local_40[6] <= card_idx - loop_idx) {
        local_40[6] = card_idx - loop_idx;
      }
      *(uint32_t *)(&DAT_00641030 + local_24 * 4) = 0x1e - (card_idx - local_40[6]);
    }
    else {
      *(int *)(&DAT_00641030 + local_24 * 4) = 0;
    }
  }
  DAT_0064105d = 0;
  DAT_0064105e = 0;
  DAT_0064105f = 0;
  if ((char)arg1 == '\x01') {
    if ((arg1 & 0x100) == 0) {
      *(int *)(&DAT_006410bc + arg2 * 4) = 1;
    }
    DAT_0064105d = Adventure_Audio_GetTrackStatus(arg2);
    *(int *)(&DAT_00641030 + (uint32_t)DAT_0064105d * 4) = 0;
    arg1 = arg1 & 0xff;
  }
  if (arg1 == 2) {
    local_40[0] = arg2 >> 0x10;
    local_40[1] = 4;
    local_40[2] = 2;
    local_40[3] = 3;
    local_40[4] = 1;
    local_40[5] = 0;
    arg2 = arg2 & 0xffff;
    if ((&DAT_0052262b)[arg2 * 0x44] == -1) {
      arg1 = 0;
    }
    else {
      DAT_0064105e = (uint8_t)arg2;
      DAT_0064105d = (uint8_t)local_40[local_40[0]];
    }
  }
  if (arg1 == 3) {
    DAT_0064105f = (uint8_t)arg2;
  }
  Mem_AllocOrFree_00409e13(&DAT_00641030,arg1);
  SetThreadPriority(DAT_00627850,player_idx);
  SetThreadPriority(DAT_00626820,slot_idx);
  SetForegroundWindow(_hwndScreen);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_0052fb20);
  Catalog_LoadPaletteMap(s_todpal_tr_0052fb30,(char *)0x0);
  SelectPalette(*(HDC *)(g_ScreenSurfaces + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(g_ScreenSurfaces + 4));
  return 0;
}

/*
 * Adventure_ShowDefeatScreen
 * Purpose: Display Arzakon victory defeat cinematic sequence.
 * Procedure:
 * 1. Load uth_arz.pic and display defeat text.
 * 2. Terminate adventure session.
 */
/*
 * Decompiled function: Adventure_ShowDefeatScreen
 * Entry Point: 004eccd7
 * Size: 509 bytes
 */

void Adventure_ShowDefeatScreen(void)

{
  LONG arg2;
  int status;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  for (match_count = 0; match_count < 500; match_count = match_count + 1) {
    if (((*(int *)(&deck + match_count * 4) != -1) && (((&DAT_00702151)[match_count * 4] & 0x40) == 0)) &&
       (4 < (*(uint32_t *)(&deck + match_count * 4) & 0xfff))) {
      slot_idx = slot_idx + 1;
    }
  }
  if (slot_idx == 0) {
    FUN_005112b0(0,(short)g_MidiMusicTrackId);
    Mem_AllocOrFree_00510de0(1,s_uth_arz_pic_0052fb3c);
    g_OverworldWorldState = 0;
    *(int *)(g_DisplaySurfaceBackBuffer + 0x20) = 5;
    if ((g_AiManaColorCost_Red == 0x280) || (g_AiManaColorCost_Red == 800)) {
      card_idx = 0x14;
    }
    else {
      card_idx = 0x10;
    }
    arg2 = Ai_Util_004c3bc4(card_idx);
    FUN_0050f2e0(5,arg2);
    strcat(&g_OverworldWorldState,s_You_have_no_power_for_even_an_An_0052fb48);
    strcat(&g_OverworldWorldState,s_Your_Righteous_Quest_has_Failed_0052fb70);
    strcat(&g_OverworldWorldState,s_The_Evil_Planeswalker_Arzakon_an_0052fb94);
    strcat(&g_OverworldWorldState,s_have_worn_you_down_0052fbcc);
    strcat(&g_OverworldWorldState,s_The_people_will_suffer_a_thousan_0052fbe4);
    status = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceBackBuffer + 0x20));
    FUN_0040d269((int)g_DisplaySurfaceBackBuffer,0xea,0x140,status * -7 + 0x1e0);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    FUN_0040a3e1();
    Ai_Subsystem_004cd1d1();
    FUN_005112b0(0,(short)g_MidiMusicTrackId);
    DAT_006fe3f0 = 1;
    Subsystem_FreeStatWinDll();
    Palette_Util_00496d20();
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}

/*
 * Adventure_PromptConfirmDialog
 * Purpose: Display modal confirmation prompt (Yes, I'm sure).
 * Procedure:
 * 1. Display confirmation popup menu.
 * 2. Return player confirmation choice.
 */
/*
 * Decompiled function: Adventure_PromptConfirmDialog
 * Entry Point: 004ecee0
 * Size: 180 bytes
 */

bool Adventure_PromptConfirmDialog(LPCSTR name_or_path)

{
  ATOM atom_res;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Duel_MainArena_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x10;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = name_or_path;
  atom_res = RegisterClassA(&local_2c);
  g_CampaignMenuHandle = CreatePopupMenu();
  DAT_005659e0 = CreatePopupMenu();
  AppendMenuA(DAT_005659e0,0,0x6c,s_Yes__I_m_sure_0052fc98);
  return atom_res != 0;
}

/*
 * Adventure_DestroyConfirmMenu
 * Purpose: Cleanup popup confirm menu resources.
 * Procedure:
 * 1. Destroy popup menu handle.
 */
/*
 * Decompiled function: Adventure_DestroyConfirmMenu
 * Entry Point: 004ecf94
 * Size: 81 bytes
 */

void Adventure_DestroyConfirmMenu(void)

{
  if (g_CampaignMenuHandle != (HMENU)0x0) {
    DestroyMenu(g_CampaignMenuHandle);
  }
  if (DAT_005659e0 != (HMENU)0x0) {
    DestroyMenu(DAT_005659e0);
  }
  g_CampaignMenuHandle = (HMENU)0x0;
  DAT_005659e0 = (HMENU)0x0;
  return;
}

