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
  byte color_mask;
  int val_result;
  int uVar3;
  int iVar4;
  uint uVar5;
  clock_t cVar6;
  int local_c;
  
  is_valid = false;
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  Ai_Subsystem_004cd3eb();
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    *(int *)(&g_PlayerLifeTotals + local_c * 4) = 8;
  }
  Hints_Load_004071ce();
  Csv_ReadConcise_0040659f();
  Mem_AllocOrFree_00512220(1,1,DAT_00677690);
  Pic_Subsystem_0044b8aa();
  Pic_Subsystem_0044b8da();
  GdiGetBatchLimit();
  GdiSetBatchLimit(100);
  LoadPalNoPic(s_advfac64_pic_0052f0c0);
  Sprite_LoadAll(&DAT_006781d0,s_dbox_spr_0052f0d0);
  do {
    val_result = Sprite_Load_begin_0047a2e6();
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    switch(val_result) {
    case 0:
      while( true ) {
        DAT_0067f380 = Pic_Load_menu2_hi_0047abf1();
        Surface_TransformPoint(0,(short)DAT_00530d9c);
        if (DAT_0067f380 == -1) break;
        while( true ) {
          DAT_0052effc = Pic_Load_menu3_but1_0047b208();
          DAT_006410d8 = DAT_0052effc;
          DAT_006fe448 = DAT_0052effc;
          DAT_006fe44c = Math_RandomRange(3);
          Surface_TransformPoint(0,(short)DAT_00530d9c);
          if (DAT_006410d8 == -1) break;
          DAT_006ff678 = Sprite_Load__16faces_0047b899();
          Surface_TransformPoint(0,(short)DAT_00530d9c);
          if (DAT_006ff678 != -1) {
            DAT_0052f000 = 1 << ((byte)DAT_0052effc & 0x1f);
            LoadPalNoPic(s_advfac64_pic_0052f0dc);
            Mem_AllocOrFree_00510e20(1,PTR_s_advinter800_pic_00530d98);
            Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                         (int *)g_DisplaySurfaceScreen,0,0);
            DAT_0067f388 = 0;
            Palette_Subsystem_00496ccf();
            is_valid = true;
            *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
            Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xff,0x140,0xbc);
            DAT_0064101c = 1;
            FUN_0046e960();
            Pic_Subsystem_0044d680();
            FUN_0048e306();
            Gold = (5 - DAT_0067f380) * 0x32;
            DAT_0052f00c = 0;
            goto switchD_004e765f_default;
          }
        }
      }
      break;
    case 1:
      DAT_0067f388 = 0;
      iVar4 = Mem_AllocOrFree_0048e108();
      FUN_0048c72a(iVar4);
    default:
switchD_004e765f_default:
      for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
        if (*(int *)(&DAT_0067bdf0 + local_c * 100) == 5) {
          uVar3 = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + local_c * 100),
                               *(int *)(&DAT_0067bdf8 + local_c * 100));
          color_mask = Adventure_GetLocationEncounterIndex(uVar3);
          iVar4 = Card_ColorMaskToColorIndex(color_mask);
          *(int *)(&DAT_006410c0 + (iVar4 + -1) * 4) = 1;
        }
      }
      FUN_00409d10();
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
      Ai_Subsystem_004c05ba();
      if (val_result == 0) {
        do {
          do {
            val_result = Math_RandomRange(0x40);
            DAT_0052eff0 = val_result * 0x20 + 0x10;
            val_result = Math_RandomRange(0x40);
            DAT_0052eff4 = val_result * 0x20 + 0x10;
            uVar3 = Surface_GetPixelColor((int)(DAT_0052eff0 + (DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                                 (int)(DAT_0052eff4 + (DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
            uVar5 = Adventure_GetLocationEncounterIndex(uVar3);
          } while ((uVar5 & DAT_0052f000) == 0);
          uVar5 = FUN_0040c7c0((int)(DAT_0052eff0 + (DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                               (int)(DAT_0052eff4 + (DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
        } while ((uVar5 & 0x10) != 0);
      }
      DAT_005659bc = 0;
      DAT_0067bde8 = 0;
      DAT_0067f3b8 = 0;
      for (local_c = 0; local_c < 500; local_c = local_c + 1) {
        if ((*(int *)(&deck + local_c * 4) != -1) &&
           (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[local_c * 4] & 0x40) == 0)) {
          DAT_0067f3b8 = DAT_0067f3b8 + 1;
        }
      }
      do {
        Mem_AllocOrFree_005016f9();
        Ai_Subsystem_004be643(DAT_0052eff0,DAT_0052eff4,DAT_005659dc);
        DAT_005659dc = 0;
        do {
          cVar6 = clock();
        } while (cVar6 < 0x3c);
        clock();
        if ((DAT_007039c4 & 2) != 0) {
          Adventure_PromptLocationMenu();
        }
        Adventure_ExitTownLocation();
        Adventure_PlayLocationMusic();
        Adventure_UpdateWorldMapLoop();
        Adventure_TriggerDuelFromEncounter();
        Pic_Subsystem_0044b84b();
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
        DAT_0067f37c = DAT_0067f37c + 1;
        App_ProcessPendingMessages();
        Mem_AllocOrFree_0040a422();
      } while (DAT_006fe3f0 == 0);
      Surface_TransformPoint(0,(short)DAT_00530d9c);
      FUN_00409db6();
      uVar3 = Palette_Util_00496d20();
      return uVar3;
    case 2:
      DAT_0067f388 = 0;
      FUN_0048c72a(3);
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
    FUN_0040816b(0x53);
    break;
  case 1:
    FUN_0040816b(0x51);
    break;
  case 2:
    FUN_0040816b(0x3b00);
    break;
  case 3:
    FUN_0040816b(0x3c00);
    break;
  case 4:
    FUN_0040816b(0x3d00);
    break;
  case 5:
    FUN_0040816b(0x3e00);
    break;
  case 6:
    FUN_0040816b(0x3f00);
    break;
  case 7:
    FUN_0040816b(0x4000);
    break;
  default:
    Ai_Subsystem_004c05ba();
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

int Adventure_HandleLocationMenuChoice(int color_mask,int arg2)

{
  int status;
  int color_mask;
  int local_40 [10];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
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
  if ((((color_mask < status) || (status = Ai_Util_004c3bc4(0x240), status < color_mask)) ||
      (status = Ai_Util_004c3bc4(0x30), arg2 < status)) ||
     (status = Ai_Util_004c3bc4(0x148), status < arg2)) {
    status = -1;
  }
  else {
    status = Ai_Util_004c3bc4(0x130);
    if (((status < color_mask) && (status = Ai_Util_004c3bc4(0x158), color_mask < status)) &&
       ((status = Ai_Util_004c3bc4(0xa8), status < arg2 &&
        (status = Ai_Util_004c3bc4(0xdd), arg2 < status)))) {
      status = 0x20;
    }
    else {
      local_14 = Ai_Util_004c3bc4(0x140);
      local_18 = Ai_Util_004c3bc4(0xbc);
      status = color_mask - local_14;
      color_mask = local_18 - arg2;
      local_c = abs(status);
      local_10 = abs(color_mask);
      if ((status < 0) || (color_mask < 0)) {
        if ((status < 0) || (-1 < color_mask)) {
          if ((status < 0) && (color_mask < 0)) {
            local_8 = 4;
          }
          else if ((status < 0) && (-1 < color_mask)) {
            local_8 = 6;
          }
        }
        else {
          local_8 = 2;
        }
      }
      else {
        local_8 = 0;
      }
      if (((local_8 & 2) == 0) && (local_10 < local_c)) {
        local_8 = local_8 + 1;
      }
      else if (((local_8 & 2) != 0) && (local_c < local_10)) {
        local_8 = local_8 + 1;
      }
      switch(local_8) {
      case 0:
      case 3:
      case 4:
      case 7:
        local_40[9] = local_c * 0x9a85 >> 0xe;
        if (color_mask < 0) {
          local_40[9] = -local_40[9];
        }
        break;
      case 1:
      case 2:
      case 5:
      case 6:
        local_40[9] = local_c * 0x1a82 >> 0xe;
        if (color_mask < 0) {
          local_40[9] = -local_40[9];
        }
      }
      switch(local_8) {
      case 0:
      case 1:
      case 2:
      case 3:
        if (color_mask < local_40[9]) {
          local_8 = local_8 + 1;
        }
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        if (local_40[9] < color_mask) {
          local_8 = local_8 + 1;
        }
      }
      status = local_40[local_8];
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
  int local_8;
  
  local_8 = -1;
  switch(DAT_00640f08) {
  case 1:
    FUN_0040816b(0x3b00);
    break;
  case 2:
    FUN_0040816b(0x3c00);
    break;
  case 3:
    FUN_0040816b(0x3d00);
    break;
  case 4:
    FUN_0040816b(0x3e00);
    break;
  case 5:
    FUN_0040816b(0x3f00);
    break;
  case 6:
    FUN_0040816b(0x4000);
    break;
  default:
    Pic_Subsystem_0044b84b();
    if (DAT_0067bda0 != 0) {
      local_8 = Adventure_HandleLocationMenuChoice(DAT_0067bda4,DAT_0067bda8);
    }
    if (local_8 != -1) {
      FUN_0040816b(local_8);
    }
    break;
  case 0x31:
    FUN_0040816b(0x31);
    break;
  case 0x32:
    FUN_0040816b(0x32);
    break;
  case 0x33:
    FUN_0040816b(0x33);
    break;
  case 0x34:
    FUN_0040816b(0x34);
    break;
  case 0x35:
    FUN_0040816b(0x35);
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
  uint u_res;
  int val_result;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
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
  int local_10;
  int local_c;
  
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
        Ai_Subsystem_004c05ba();
      }
      FUN_0048c970(3);
    }
    else if ((0x30 < local_34) && (local_34 < 0x36)) {
LAB_004e8168:
      val_result = local_34 + -0x30;
      if ((*(int *)(&DAT_0067bdbc + val_result * 4) != 0) &&
         ((_DAT_0067f374 & 1 << ((char)val_result * '\x02' & 0x1fU)) != 0)) {
        iVar4 = Math_RandomRange(4 - DAT_0067f380);
        if (iVar4 == 0) {
          *(int *)(&DAT_0067bdbc + val_result * 4) = *(int *)(&DAT_0067bdbc + val_result * 4) + -1;
        }
        Ai_Subsystem_004c05ba();
        switch(local_34) {
        case 0x31:
          Surface_TransformPoint(0,(short)DAT_00530d9c);
          DeckBuilderMain(_hwndScreen,1,1);
          Pic_Load_advfac64_0040a4fc();
          FUN_0050d560(0,7);
          Ai_Subsystem_004c05ba();
          break;
        case 0x32:
          do {
            val_result = Math_RandomRange(0x40);
            iVar4 = Math_RandomRange(0x40);
            iVar5 = Surface_GetPixelColor(val_result,iVar4);
          } while (iVar5 == 0);
          FUN_0040b3c2(0x12,2);
          DAT_0052eff0 = val_result * 0x20 + 0x10;
          DAT_0052eff4 = iVar4 * 0x20 + 0x10;
          Ai_Subsystem_004c05ba();
          DAT_0064101c = 1;
          break;
        case 0x33:
          *(int *)(&DAT_005224ec + val_result * 0x20) = 0x96;
          FUN_0040b3c2(0x12,3);
          break;
        case 0x34:
          local_44 = 0x7fff;
          local_10 = -1;
          for (local_2c = 0; local_2c < 6; local_2c = local_2c + 1) {
            if ((0 < *(int *)(&DAT_0067f2d0 + local_2c * 0x14)) &&
               (val_result = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_2c * 0x14),
                                     DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_2c * 0x14)),
               val_result < local_44)) {
              local_10 = local_2c;
              local_44 = val_result;
            }
          }
          if (local_10 != -1) {
            FUN_0046e70d(local_10,local_10 + 8);
            FUN_0040b3c2(0x12,CONCAT31((int3)((uint)(*(int *)(&DAT_0067f2d0 + local_10 * 0x14) <<
                                                    0x10) >> 8),4));
            *(int *)(&DAT_0067f2d0 + local_10 * 0x14) = 0xffffffff;
          }
          break;
        case 0x35:
          if (DAT_0067f35c != -1) {
            DAT_0052eff0 = (DAT_0067f360 & 0xffe0) + 0x10;
            DAT_0052eff4 = (DAT_0067f364 & 0xffe0) + 0x1f;
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
        FUN_0048c970(val_result);
      }
      LoadPalNoPic(s_advfac64_pic_0052f1cc);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x55) {
      DAT_00532550 = DAT_00532550 ^ 1;
      goto LAB_004e8168;
    }
  }
  else if (local_34 < 0x3c01) {
    if (local_34 == 0x3c00) {
      App_ProcessPendingMessages();
      Ai_CastleEncounter_004c24b3(0);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x3b00) {
      if ((_DAT_0067f374 & 8) != 0) {
        local_34 = 0x31;
        goto LAB_004e8168;
      }
      Surface_TransformPoint(0,(short)DAT_00530d9c);
      DeckBuilderMain(_hwndScreen,1,0);
      Pic_Load_advfac64_0040a4fc();
      Ai_Subsystem_004c05ba();
    }
  }
  else if (local_34 < 0x3e01) {
    if (local_34 == 0x3e00) {
      App_ProcessPendingMessages();
      Castle_Process_0048f523(1);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x3d00) {
      App_ProcessPendingMessages();
      Town_Process_00490d7b(1);
      Ai_Subsystem_004c05ba();
    }
  }
  else if (local_34 < 0x4001) {
    if (local_34 == 0x4000) {
      App_ProcessPendingMessages();
      Adventure_Map_UpdateLightingAndPalette(0,0xffffffff);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x3f00) {
      Castle_Process_00421b32();
      Ai_Subsystem_004c05ba();
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
    Ai_Subsystem_004cd20e();
    DAT_005659bc = 300;
  }
  val_result = Surface_GetPixelColor((int)(*(int *)(&DAT_00522378 + DAT_0052f010 * 4) + DAT_0052eff0 +
                            ((int)(*(int *)(&DAT_00522378 + DAT_0052f010 * 4) + DAT_0052eff0) >>
                             0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&DAT_005223e0 + DAT_0052f010 * 4) + DAT_0052eff4 +
                            ((int)(*(int *)(&DAT_005223e0 + DAT_0052f010 * 4) + DAT_0052eff4) >>
                             0x1f & 0x1fU)) >> 5);
  uVar3 = Adventure_GetLocationEncounterIndex(val_result);
  if (uVar3 == 0) {
    local_40 = 0;
  }
  else {
    do {
      local_40 = Math_RandomRange(5);
      local_40 = local_40 + 1;
    } while ((uVar3 & 1 << ((byte)local_40 & 0x1f)) == 0);
  }
  local_c = 1;
  DAT_00641010 = (int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5;
  DAT_00641014 = (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5;
  if (((val_result == 2) || ((val_result == 3 && ((_DAT_0067f374 & 8) == 0)))) ||
     ((val_result == 4 && ((_DAT_0067f374 & 0x200) == 0)))) {
    local_c = 3;
  }
  if ((val_result == 5) && ((_DAT_0067f374 & 0x200) == 0)) {
    local_c = 3;
  }
  val_result = FUN_0040cb4f(DAT_00641010,DAT_00641014,(char)DAT_0052f010);
  if (val_result != 0) {
    local_c = 1;
  }
  val_result = FUN_0040cb4f(DAT_00641010,DAT_00641014,((char)DAT_0052f010 + 3U & 7) + 1);
  if (val_result != 0) {
    local_c = 1;
  }
  if (DAT_00522448 == 0) {
    local_c = Math_Clamp(local_c + 2, 0, 4);
  }
  u_res = DAT_0052eff4;
  uVar3 = DAT_0052eff0;
  val_result = DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU);
  iVar4 = DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU);
  iVar5 = (int)DAT_0067f37c / local_c;
  if ((int)DAT_0067f37c % local_c == 0) {
    if (local_c == 3) {
      iVar5 = *(int *)(&DAT_00522378 + DAT_0052f010 * 4) * 2;
    }
    else {
      iVar5 = *(int *)(&DAT_00522378 + DAT_0052f010 * 4);
    }
    DAT_0052eff0 = DAT_0052eff0 + iVar5;
    if (local_c == 3) {
      iVar5 = *(int *)(&DAT_005223e0 + DAT_0052f010 * 4) * 2;
    }
    else {
      iVar5 = *(int *)(&DAT_005223e0 + DAT_0052f010 * 4);
    }
    DAT_0052eff4 = DAT_0052eff4 + iVar5;
    DAT_006410dc = DAT_006410dc + 1;
    if (4 < (int)DAT_006410dc) {
      DAT_006410dc = 1;
    }
    if (DAT_0052f010 != 0) {
      height = 0;
      iVar5 = Math_RandomRange(0x28);
      iVar5 = iVar5 + 0x50;
      iVar6 = Math_RandomRange(0x19);
      Adventure_Audio_PlayEffectAtVolume
                (((DAT_006410dc & 1) - 2) + local_40 * 2,iVar6 + 0x4b,iVar5,height);
    }
    if (DAT_0052f010 == 0) {
      DAT_006410dc = 0;
    }
    else {
      DAT_006410d4 = DAT_0052f010;
    }
    if ((DAT_0052254c != 0) ||
       (((DAT_0067f37c & 1) != 0 &&
        (iVar5 = FUN_0040cb4f(DAT_00641010,DAT_00641014,((char)DAT_0052f010 + 3U & 7) + 1),
        iVar5 != 0)))) {
      DAT_0052eff0 = DAT_0052eff0 + *(int *)(&DAT_00522378 + DAT_0052f010 * 4);
      DAT_0052eff4 = DAT_0052eff4 + *(int *)(&DAT_005223e0 + DAT_0052f010 * 4);
    }
    iVar5 = Surface_GetPixelColor((int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                         (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
    if ((iVar5 == 0) &&
       ((iVar6 = abs(DAT_0052eff0 - ((DAT_0052eff0 & 0xffffffe0) + 0x10)), iVar6 < 0xc ||
        (iVar6 = abs(DAT_0052eff4 - ((DAT_0052eff4 & 0xffffffe0) + 0x10)), iVar6 < 0xc)))) {
      DAT_0052f010 = 0;
      DAT_0052eff0 = uVar3;
      DAT_0052eff4 = u_res;
    }
    iVar6 = Math_RandomRange(0x28);
    if ((iVar6 == 0) && (DAT_0052f008 == 0)) {
      Adventure_Audio_PlayTerrainAmbience(local_40);
    }
    if (((DAT_0067f37c & 0x1f) == 0) && (DAT_0052f010 != 0)) {
      if (DAT_00522448 != 0) {
        DAT_00522448 = DAT_00522448 + -1;
      }
      if ((DAT_00522558 == 0) && (iVar5 == 2)) {
        DAT_00522448 = DAT_00522448 + 2;
      }
      DAT_0052f004 = DAT_0052f004 + 1;
      DAT_00641020 = DAT_00641020 + 1;
      if ((DAT_0052f004 & 0x3f) == 0) {
        Adventure_NewsFlash_EnemyAttack();
        iVar5 = Math_Clamp(DAT_0067f380 +
                             ((int)(DAT_0052f004 + ((int)DAT_0052f004 >> 0x1f & 0xffU)) >> 8),0,0x10
                            );
        DAT_0052f004 = DAT_0052f004 + iVar5;
      }
      if (((byte)DAT_0052f004 & 0x3f) == 0x18) {
        Adventure_NewsFlash_DominionSpell();
        iVar5 = Math_Clamp(DAT_0067f380 * 2 +
                             ((int)(DAT_0052f004 + ((int)DAT_0052f004 >> 0x1f & 0x3fU)) >> 6),0,0x20
                            );
        DAT_0052f004 = DAT_0052f004 + iVar5;
      }
      DAT_005659dc = 1;
      if (7 < (int)DAT_0052f004) {
        DAT_0052f00c = 1;
      }
    }
    DAT_00641010 = (int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5;
    DAT_00641014 = (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5;
    if ((DAT_00641010 != val_result >> 5) || (DAT_00641014 != iVar4 >> 5)) {
      DAT_005659b0 = 0;
    }
    if ((DAT_0067f37c & 1) == 0) {
      local_68 = 0x7fff;
      for (local_64 = 0; local_64 < 0x80; local_64 = local_64 + 1) {
        if ((*(int *)(&DAT_0067bdf0 + local_64 * 100) != -1) &&
           (val_result = FUN_0040a36f((*(int *)(&DAT_0067bdf4 + local_64 * 100) * 0x20 + 0x10) -
                                 DAT_0052eff0,
                                 (*(int *)(&DAT_0067bdf8 + local_64 * 100) * 0x20 + 0x10) -
                                 DAT_0052eff4), val_result < local_68)) {
          local_58 = local_64;
          local_68 = val_result;
        }
      }
      val_result = Math_Clamp(0x80 - local_68,0,100);
      if ((val_result < 0xb) || (*(int *)(&DAT_0067bdf0 + local_58 * 100) < 1)) {
        if (DAT_0052f014 != 0) {
          StopSnd(0x10);
        }
        DAT_0052f014 = 0;
        DAT_0052f064 = -1;
      }
      else {
        if (local_58 == DAT_0052f064) {
          SetVol(0x10,val_result << 2);
        }
        else {
          DAT_0052f064 = local_58;
          if (*(int *)(&DAT_0067bdf0 + local_58 * 100) == 4) {
            for (local_30 = 0;
                (local_30 < 5 &&
                ((*(int *)(&DAT_0067bdf4 + local_58 * 100) !=
                  *(int *)(&DAT_0067f000 + local_30 * 0x30) ||
                 (*(int *)(&DAT_0067bdf8 + local_58 * 100) !=
                  *(int *)(&DAT_0067f004 + local_30 * 0x30))))); local_30 = local_30 + 1) {
            }
            iVar4 = DAT_0052f018;
            if (local_30 + 0x15 != DAT_0052f018) {
              if ((DAT_0052f018 != -1) && (local_30 + 0x15 != DAT_0052f018)) {
                CloseSndTrack(0x10);
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
              iVar4 = local_30 + 0x15;
            }
          }
          else if (*(int *)(&DAT_0067bdf0 + local_58 * 100) == 1) {
            if ((DAT_0052f018 != -1) && (DAT_0052f018 != 0x32)) {
              CloseSndTrack(0x10);
            }
            if (DAT_0052f018 != 0x32) {
              Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus0_wav_0052f240,0x10);
            }
            DAT_0052f018 = 0x32;
            iVar4 = DAT_0052f018;
          }
          else {
            iVar4 = local_58 % 0x14;
            if (iVar4 != DAT_0052f018) {
              if (DAT_0052f018 != -1) {
                CloseSndTrack(0x10);
              }
              switch(iVar4) {
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
          DAT_0052f018 = iVar4;
          Adventure_Audio_PlayEffectLooped(0x10,val_result,0);
          SetSndMarker(0x10,1);
        }
        DAT_0052f014 = 1;
      }
    }
    if ((((DAT_005659b0 == 0) && (val_result = abs((DAT_0052eff0 & 0x1f) - 0x10), val_result < 0xc)) &&
        (val_result = abs((DAT_0052eff4 & 0x1f) - 0x10), val_result < 0xc)) &&
       (uVar3 = FUN_0040c7c0(DAT_00641010,DAT_00641014), (uVar3 & 0x10) != 0)) {
      uVar3 = Duel_GetCardDrawOriginX(DAT_00641010,DAT_00641014);
      if (uVar3 == 0xffffffff) {
        FUN_0040c889(0x10,DAT_00641010,DAT_00641014);
      }
      else {
        SetVol(0x10,400);
        PlaySndMarker(0x10,1);
        Town_Process_00506580(uVar3);
        DAT_0052f00c = 1;
        DAT_005659b0 = 1;
        DAT_0052f010 = 0;
        for (local_2c = 0; local_2c < 6; local_2c = local_2c + 1) {
          if ((0 < *(int *)(&DAT_0067f2d0 + local_2c * 0x14)) &&
             (val_result = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_2c * 0x14),
                                   DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_2c * 0x14)),
             val_result < 0x60)) {
            val_result = DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_2c * 0x14);
            iVar4 = DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_2c * 0x14);
            iVar5 = abs(iVar4);
            iVar6 = abs(val_result);
            if (iVar5 / 2 < iVar6) {
              local_6c = FUN_0040a33c(val_result);
              local_6c = local_6c * 0x30;
            }
            else {
              local_6c = 0;
            }
            *(uint *)(&DAT_0067f2d4 + local_2c * 0x14) = DAT_0052eff0 - local_6c;
            val_result = abs(val_result);
            iVar5 = abs(iVar4);
            if (val_result / 2 < iVar5) {
              local_70 = FUN_0040a33c(iVar4);
              local_70 = local_70 * 0x30;
            }
            else {
              local_70 = 0;
            }
            *(uint *)(&DAT_0067f2d8 + local_2c * 0x14) = DAT_0052eff4 - local_70;
          }
        }
        Palette_Subsystem_004981b5(0);
        FUN_0048c970(3);
        Adventure_LoadFacePalette(0);
        Ai_Subsystem_004c05ba();
        DAT_0067f37c = DAT_0067f37c | 0x1f;
      }
    }
    if (((DAT_005659b0 == 0) && ((DAT_0052eff0 - 8 & 0x10) == 0)) &&
       (((DAT_0052eff4 - 8 & 0x10) == 0 &&
        (uVar3 = FUN_0040c7c0(DAT_00641010,DAT_00641014), (uVar3 & 0x40) != 0)))) {
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
    iVar5 = Mem_AllocOrFree_0040a422();
  }
  return iVar5;
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
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  uint local_10;
  int local_c;
  
  local_54 = 0x7fff;
  for (local_40 = 0; (int)local_40 < 6; local_40 = local_40 + 1) {
    iVar4 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_40 * 0x14),
                         DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_40 * 0x14));
    if ((iVar4 < local_54) && (*(int *)(&DAT_0067f2d0 + local_40 * 0x14) != 0)) {
      local_10 = local_40;
      local_54 = iVar4;
    }
  }
  if (DAT_0067f35c == -1) {
    DAT_006410b0 = 0;
  }
  for (local_40 = 0; (int)local_40 < 8; local_40 = local_40 + 1) {
    iVar4 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_40 * 0x14),
                         DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_40 * 0x14));
    iVar5 = abs(DAT_00641010 -
                ((int)(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) +
                      (*(int *)(&DAT_0067f2d4 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5));
    iVar6 = abs(DAT_00641014 -
                ((int)(*(int *)(&DAT_0067f2d8 + local_40 * 0x14) +
                      (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5));
    if (((int)local_40 < 6) &&
       (((*(int *)(&DAT_0067f2d0 + local_40 * 0x14) == -1 || (4 < iVar5)) || (4 < iVar6)))) {
      do {
        iVar5 = Math_RandomRange(2);
        if (iVar5 == 0) {
          iVar5 = Math_RandomRange(2);
          local_3c = (-(uint)(iVar5 == 0) & 0xfffffff8) + 4 + DAT_00641014;
          iVar5 = Math_RandomRange(9);
          local_28 = DAT_00641010 + iVar5 + -4;
        }
        else {
          iVar5 = Math_RandomRange(2);
          local_28 = (-(uint)(iVar5 == 0) & 0xfffffff8) + 4 + DAT_00641010;
          iVar5 = Math_RandomRange(9);
          local_3c = DAT_00641014 + iVar5 + -4;
        }
        uVar7 = Surface_GetPixelColor(local_28,local_3c);
        uVar8 = Adventure_GetLocationEncounterIndex(uVar7);
      } while (uVar8 == 0);
      do {
        iVar5 = Math_RandomRange(6);
        local_44._0_1_ = (byte)iVar5;
        bVar3 = (byte)local_44;
      } while ((uVar8 & 1 << ((byte)local_44 & 0x1f)) == 0);
      local_44 = (int)(DAT_0067f384 + (DAT_0067f384 >> 0x1f & 7U)) >> 3;
      for (local_48 = 0; (int)local_48 < 1000; local_48 = local_48 + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == iVar5) {
          local_44 = local_44 + 1;
        }
      }
      iVar6 = Math_Clamp((int)(0x80 / (longlong)(local_44 + 4)),6,0x14);
      iVar6 = Math_RandomRange(iVar6);
      switch(iVar6 + (int)(5 / (longlong)(local_44 + 1))) {
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
        local_24 = Math_RandomRange(200);
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
      if (((local_40 == 0) && (DAT_0067f2c0 < 0)) && (-100 < DAT_0067f2c0)) {
        local_24 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44];
      }
      if (local_24 == 0) {
        *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0;
      }
      else {
        local_24 = Adventure_CheckMonsterEncounter(iVar5,local_24);
        *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = local_24;
        local_2c = 0;
        for (local_48 = 0; ((int)local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
            local_48 = local_48 + 1) {
          if ((((&DAT_0067b9b0)[local_48] & 0xf) == (&DAT_0052262a)[local_24 * 0x44]) &&
             ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == iVar5)) {
            local_2c = local_2c + 1;
          }
        }
        if (8 < local_2c) {
          local_24 = -1;
          *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
        }
      }
      *(int *)(&DAT_0067f2d4 + local_40 * 0x14) = local_28 * 0x20 + 0x10;
      *(int *)(&DAT_0067f2d8 + local_40 * 0x14) = local_3c * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + local_40 * 0x14) = iVar5;
      (&DAT_0067f2e0)[local_40 * 0x14] = 0;
      (&DAT_0067f2e1)[local_40 * 0x14] = 0;
      if (((1 << (bVar3 & 0x1f) & (int)(char)(&DAT_0052262b)[local_24 * 0x44]) != 0) &&
         ((DAT_0067bdb4 & 1 << (bVar3 & 0x1f)) != 0)) {
        uVar8 = (int)(char)(&DAT_0052262b)[local_24 * 0x44] & ~(1 << (bVar3 & 0x1f));
        if ((uVar8 == 0) || ((uVar8 & DAT_0067bdb4) != 0)) {
          FUN_0046e70d(local_40,local_40 + 8);
          *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
        }
        else if (uVar8 != 0) {
          uVar7 = Card_ColorMaskToColorIndex((byte)uVar8);
          *(int *)(&DAT_0067f2dc + local_40 * 0x14) = uVar7;
        }
      }
      uVar8 = FUN_0040c7c0(local_28,local_3c);
      if ((uVar8 & 0x10) != 0) {
        FUN_0046e70d(local_40,local_40 + 8);
        *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
      }
      if (((local_40 == 0) && (DAT_0067f2c0 < 0)) && (_DAT_0067f2d0 != -DAT_0067f2c0)) {
        FUN_0046e70d(0,8);
        _DAT_0067f2d0 = -1;
      }
      if (*(int *)(&DAT_0067f2d0 + local_40 * 0x14) < 1) {
        if (*(int *)(&DAT_0067f2d0 + local_40 * 0x14) != -1) {
          for (local_6c = 0; (int)local_6c < 8; local_6c = local_6c + 1) {
            if (((*(int *)(&DAT_0067f2d0 + local_6c * 0x14) != -1) && (local_40 != local_6c)) &&
               ((*(int *)(&DAT_0067f2d4 + local_6c * 0x14) ==
                 *(int *)(&DAT_0067f2d4 + local_40 * 0x14) &&
                (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) ==
                 *(int *)(&DAT_0067f2d8 + local_6c * 0x14))))) {
              *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
            }
          }
        }
      }
      else {
        FUN_0046e70d(local_40,local_40 + 8);
      }
    }
    iVar5 = *(int *)(&DAT_0067f2d0 + local_40 * 0x14);
    if (iVar5 != -1) {
      if (0 < iVar5) {
        Sprite_Load_BK_AMG_0046d333(iVar5,local_40,local_40 + 8);
      }
      local_20 = 1;
      switch((&DAT_0052262a)[iVar5 * 0x44]) {
      case 0:
        local_34 = -1;
        local_20 = 0;
        break;
      case 1:
        local_c = 1;
        local_34 = 0x20;
        local_20 = 1;
        break;
      case 2:
        local_c = 1;
        local_34 = 0x20;
        local_20 = 1;
        break;
      case 3:
        local_c = 1;
        local_34 = 0x30;
        local_20 = 1;
        break;
      case 4:
        local_c = 1;
        local_34 = 0x30;
        local_20 = 1;
        break;
      case 5:
        local_c = 1;
        local_34 = 0x40;
        local_20 = 1;
        break;
      case 6:
        local_c = 1;
        local_34 = 0x60;
        local_20 = 1;
        break;
      case 7:
        local_c = 1;
        local_34 = 0x60;
        local_20 = 1;
        break;
      case 8:
        local_c = 1;
        local_34 = 0x40;
        local_20 = 1;
        break;
      case 9:
        local_c = 1;
        local_34 = 0x20;
        local_20 = 2;
        break;
      case 10:
        local_c = 1;
        local_34 = 0x30;
        local_20 = 1;
      }
      local_34 = (local_34 * 3) / 2;
      if (((&DAT_00522631)[iVar5 * 0x44] & 2) != 0) {
        local_34 = local_34 << 1;
      }
      local_14 = iVar4;
      if (local_40 != local_10) {
        local_34 = local_34 / 2;
      }
      for (; iVar6 = abs(local_34), iVar6 < local_14; local_14 = local_14 / 2) {
        local_c = local_c << 1;
      }
      iVar6 = *(int *)(&DAT_0067f2d4 + local_40 * 0x14);
      status = *(int *)(&DAT_0067f2d8 + local_40 * 0x14);
      if (DAT_006410dc == 0) {
        local_60 = DAT_0052eff0 - iVar6;
        local_64 = DAT_0052eff4 - status;
      }
      else {
        iVar9 = Math_Clamp(iVar4 / 3,0,DAT_0067f380 << 4);
        local_60 = (iVar9 * *(int *)(&DAT_00522378 + DAT_006410d4 * 4) + DAT_0052eff0) - iVar6;
        iVar9 = Math_Clamp(iVar4 / 3,0,DAT_0067f380 << 4);
        local_64 = (iVar9 * *(int *)(&DAT_005223e0 + DAT_006410d4 * 4) + DAT_0052eff4) - status;
      }
      if (((&DAT_00522630)[iVar5 * 0x44] & 1) != 0) {
        local_20 = 2;
      }
      if ((iVar4 < 0x40) && ((int)local_40 < 7)) {
        local_2c = 0;
        for (local_48 = 0; ((int)local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
            local_48 = local_48 + 1) {
          if ((((&DAT_0067b9b0)[local_48] & 0xf) == (&DAT_0052262a)[iVar5 * 0x44]) &&
             ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == *(int *)(&DAT_0067f2dc + local_40 * 0x14)
             )) {
            local_2c = local_2c + 1;
          }
        }
        if (DAT_0067f380 + 3 <= local_2c) {
          local_60 = -local_60;
          local_64 = -local_64;
        }
      }
      if ((local_40 == 7) && (0x18 < iVar4)) {
        iVar9 = Duel_GetCardDrawOriginY
                          ((int)(DAT_0067f360 + (DAT_0067f360 >> 0x1f & 0x1fU)) >> 5,
                           (int)(DAT_0067f364 + (DAT_0067f364 >> 0x1f & 0x1fU)) >> 5);
        local_60 = (*(int *)(&DAT_0067bdf4 + iVar9 * 100) * 0x20 - iVar6) + (DAT_0067f37c & 0x1f);
        local_64 = (*(int *)(&DAT_0067bdf8 + iVar9 * 100) * 0x20 - status) +
                   ((DAT_0067f37c & 0x3e) >> 1);
      }
      uVar7 = Surface_GetPixelColor((int)(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) +
                                (*(int *)(&DAT_0067f2d4 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                           (int)(*(int *)(&DAT_0067f2d8 + local_40 * 0x14) +
                                (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5);
      iVar9 = Adventure_GetLocationEncounterIndex(uVar7);
      if (((((&DAT_00522630)[iVar5 * 0x44] & 0xf8) != 0) &&
          ((*(uint *)(&DAT_00522630 + iVar5 * 0x44) & iVar9 << 3) != 0)) && (1 < local_c)) {
        local_c = local_c / 2;
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
      *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
           *(int *)(&DAT_0067f2d4 + local_40 * 0x14) + *(int *)(&DAT_00522378 + local_5c * 4) * 4;
      *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
           *(int *)(&DAT_0067f2d8 + local_40 * 0x14) + *(int *)(&DAT_005223e0 + local_5c * 4) * 4;
      is_match = true;
      for (local_48 = 0; (int)local_48 < 6; local_48 = local_48 + 1) {
        if (((*(int *)(&DAT_0067f2d0 + local_48 * 0x14) != 0) && (local_40 != local_48)) &&
           ((0x1f < iVar4 &&
            ((iVar9 = FUN_0040a36f(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) -
                                   *(int *)(&DAT_0067f2d4 + local_48 * 0x14),
                                   *(int *)(&DAT_0067f2d8 + local_40 * 0x14) -
                                   *(int *)(&DAT_0067f2d8 + local_48 * 0x14)), iVar9 < 0x20 &&
             (iVar10 = FUN_0040a36f(iVar6 - *(int *)(&DAT_0067f2d4 + local_48 * 0x14),
                                    status - *(int *)(&DAT_0067f2d8 + local_48 * 0x14)),
             iVar9 < iVar10)))))) {
          is_match = false;
        }
      }
      if (is_match) {
        if ((((&DAT_00522630)[iVar5 * 0x44] & 4) != 0) && ((DAT_0067f37c & 0x3f) == 0)) {
          iVar9 = Math_RandomRange(2);
          if (iVar9 == 0) {
            iVar9 = Math_RandomRange(2);
            if (iVar9 == 0) {
              *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d8 + local_40 * 0x14) + -0x20;
            }
            else {
              *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d8 + local_40 * 0x14) + 0x20;
            }
          }
          else {
            iVar9 = Math_RandomRange(2);
            if (iVar9 == 0) {
              *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d4 + local_40 * 0x14) + -0x20;
            }
            else {
              *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d4 + local_40 * 0x14) + 0x20;
            }
          }
        }
        uVar7 = Surface_GetPixelColor((int)(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) +
                                  (*(int *)(&DAT_0067f2d4 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                             (int)(*(int *)(&DAT_0067f2d8 + local_40 * 0x14) +
                                  (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5)
        ;
        uVar8 = Adventure_GetLocationEncounterIndex(uVar7);
        if ((((uVar8 & (int)(char)(&DAT_0052262b)[iVar5 * 0x44]) == 0) && (-1 < local_34)) &&
           (local_40 != 7)) {
          *(int *)(&DAT_0067f2d4 + local_40 * 0x14) = iVar6;
          *(int *)(&DAT_0067f2d8 + local_40 * 0x14) = status;
          uVar7 = Surface_GetPixelColor((int)(iVar6 + (iVar6 >> 0x1f & 0x1fU)) >> 5,
                               (int)(status + (status >> 0x1f & 0x1fU)) >> 5);
          uVar8 = Adventure_GetLocationEncounterIndex(uVar7);
          (&DAT_0067f2e1)[local_40 * 0x14] = 0;
          if ((uVar8 & (int)(char)(&DAT_0052262b)[iVar5 * 0x44]) == 0) {
            FUN_0046e70d(local_40,local_40 + 8);
            *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
          }
        }
        else {
          *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
               *(int *)(&DAT_00522378 + local_5c * 4) * local_20 + iVar6;
          *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
               *(int *)(&DAT_005223e0 + local_5c * 4) * local_20 + status;
          (&DAT_0067f2e0)[local_40 * 0x14] = (uint8_t)local_5c;
          (&DAT_0067f2e1)[local_40 * 0x14] = (&DAT_0067f2e1)[local_40 * 0x14] + '\x01';
          if ('\x04' < (char)(&DAT_0067f2e1)[local_40 * 0x14]) {
            (&DAT_0067f2e1)[local_40 * 0x14] = 1;
          }
        }
        iVar6 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_40 * 0x14),
                             DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_40 * 0x14));
        if (iVar6 < (int)((-(uint)(*(int *)(&DAT_0067f2d0 + local_40 * 0x14) == 0) & 10) + 0x10)) {
          FUN_0048c970(3);
          iVar4 = Dungeon_Process_004856b0(local_40,*(int *)(&DAT_0067f2dc + local_40 * 0x14));
          Ai_Subsystem_004c05ba();
          if ((local_40 == 7) && (iVar4 < 1)) {
            Adventure_NewsFlash_DominionSpell();
          }
          else if (local_40 == 7) {
            FUN_0040b3c2(0xd,DAT_0067f368);
            DAT_006410b0 = 0;
          }
          FUN_0046e70d(local_40,local_40 + 8);
          *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
          Adventure_LoadFacePalette(0);
          DAT_0067f37c = DAT_0067f37c | 0x1f;
          FUN_0048c970(3);
        }
        else if (((iVar5 != 0) && ((&DAT_0067f2e1)[local_40 * 0x14] != '\0')) &&
                ((iVar4 < 0x50 && (iVar6 = Math_RandomRange(iVar4), iVar6 < 4)))) {
          Adventure_PlayMonsterEncounterSound
                    (iVar5,0x68 - iVar4 / 2,100 - iVar4 / 3,
                     *(int *)(&DAT_00522378 +
                             ((int)(char)(&DAT_0067f2e0)[local_40 * 0x14] + 2U & 7) * 4) * 100);
        }
      }
      else {
        *(int *)(&DAT_0067f2d4 + local_40 * 0x14) = iVar6;
        *(int *)(&DAT_0067f2d8 + local_40 * 0x14) = status;
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

int Adventure_GetLocationEncounterIndex(int color_mask)

{
  int local_8;
  
  switch(color_mask) {
  case 1:
    local_8 = 4;
    break;
  case 2:
    local_8 = 8;
    break;
  case 3:
    local_8 = 2;
    break;
  case 4:
    local_8 = 0x30;
    break;
  case 5:
    local_8 = 0x10;
    break;
  case 6:
    local_8 = 0x20;
    break;
  case 7:
    local_8 = 0x24;
    break;
  case 8:
    local_8 = 6;
    break;
  case 9:
    local_8 = 0x14;
    break;
  case 10:
    local_8 = 0x28;
    break;
  case 0xb:
    local_8 = 10;
    break;
  case 0xc:
    local_8 = 0x12;
    break;
  case 0xd:
    local_8 = 0x22;
    break;
  case 0xe:
    local_8 = 0xc;
    break;
  case 0xf:
    local_8 = 0x18;
    break;
  default:
    local_8 = 0;
  }
  return local_8;
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

int Adventure_SetLocationEncounterIndex(int color_mask)

{
  int local_8;
  
  switch(color_mask) {
  case 1:
    local_8 = 2;
    break;
  case 2:
    local_8 = 3;
    break;
  case 3:
    local_8 = 1;
    break;
  default:
    local_8 = 0;
    break;
  case 5:
    local_8 = 4;
    break;
  case 6:
    local_8 = 5;
  }
  return local_8;
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

int Adventure_CheckMonsterEncounter(int color_mask,int arg2)

{
  int status;
  int local_c;
  
  local_c = 0;
  while( true ) {
    status = Math_RandomRange(DAT_00523524 + -1);
    status = status + 1;
    local_c = local_c + 1;
    if (0x3e6 < local_c) break;
    if (((char)(&DAT_00522628)[status * 0x44] == arg2) &&
       ((color_mask == 0 || ((1 << ((byte)color_mask & 0x1f) & (int)(char)(&DAT_0052262b)[status * 0x44]) != 0)))
       ) break;
  }
  if (local_c == 999) {
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

void Adventure_FormatNewsString(int color_mask,int arg2,int arg3)

{
  char c_res;
  size_t sVar2;
  int local_10;
  
  if (arg2 != 0) {
    Adventure_AppendNewsDetails((int)(char)(&DAT_00522600)[color_mask * 0x44],arg3);
  }
  local_10 = 0;
  sVar2 = strlen(&g_OverworldWorldState);
  do {
    c_res = (&DAT_00522600)[color_mask * 0x44 + local_10];
    (&g_OverworldWorldState)[local_10 + sVar2] = c_res;
    local_10 = local_10 + 1;
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

int Adventure_AppendNewsDetails(int color_mask,int arg2)

{
  switch(color_mask) {
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
    CloseSndTrack(0xf);
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
  int local_8;
  
  for (local_8 = 0; local_8 < 0xc; local_8 = local_8 + 1) {
    if ((0 < *(int *)(&DAT_005224ec + local_8 * 0x10)) &&
       (*(int *)(&DAT_005224ec + local_8 * 0x10) = *(int *)(&DAT_005224ec + local_8 * 0x10) + -1,
       *(int *)(&DAT_005224ec + local_8 * 0x10) == 0)) {
      Ai_Subsystem_004c05ba();
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

void Adventure_ReloadWorldPalette(int color_mask)

{
  DAT_005659b4 = 0xffffffff;
  Adventure_LoadFacePalette(color_mask);
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

void Adventure_LoadFacePalette(int color_mask)

{
  if (color_mask != DAT_005659b4) {
    LoadPalNoPic(s_advfac64_pic_0052f500);
    DAT_005659b4 = color_mask;
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
  int *piVar1;
  byte color_mask;
  int u_temp;
  char *file_name;
  int aiStack_80 [7];
  uint local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int aiStack_50 [7];
  int aiStack_34 [7];
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (DAT_006410b0 == 0) {
    App_ProcessPendingMessages();
    for (local_18 = 0; local_18 < 7; local_18 = local_18 + 1) {
      aiStack_34[local_18] = -1;
      aiStack_80[local_18] = 0;
    }
    for (local_18 = 0; local_18 < 0x80; local_18 = local_18 + 1) {
      if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 4) {
        u_temp = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + local_18 * 100),
                             *(int *)(&DAT_0067bdf8 + local_18 * 100));
        color_mask = Adventure_GetLocationEncounterIndex(u_temp);
        local_60 = Card_ColorMaskToColorIndex(color_mask);
        aiStack_34[local_60] = *(int *)(&DAT_0067bdf4 + local_18 * 100);
        aiStack_50[local_60] = *(int *)(&DAT_0067bdf8 + local_18 * 100);
      }
      if ((&DAT_0067be01)[local_18 * 100] != '\0') {
        piVar1 = (int *)((int)aiStack_80 +
                        ((int)(*(uint *)(&DAT_0067be00 + local_18 * 100) & 0xffffff3f) >> 6));
        *piVar1 = *piVar1 + 1;
      }
    }
    local_5c = 0x7fff;
    local_60 = -1;
    for (local_64 = 0; (int)local_64 < 0x80; local_64 = local_64 + 1) {
      if (((((&DAT_0067be01)[local_64 * 100] == '\0') &&
           (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 4)) &&
          (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 1)) &&
         (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 5)) {
        local_58 = 0x7fff;
        for (local_18 = 1; local_18 < 6; local_18 = local_18 + 1) {
          if (aiStack_34[local_18] != -1) {
            local_10 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_64 * 100) - aiStack_34[local_18],
                                    *(int *)(&DAT_0067bdf8 + local_64 * 100) - aiStack_50[local_18])
            ;
            if (local_10 < local_58) {
              local_58 = local_10;
              local_60 = local_18;
            }
          }
        }
        local_8 = Math_RandomRange(0x80);
        local_8 = local_8 + aiStack_80[local_60] * 0x20;
        if (local_8 < local_5c) {
          local_5c = local_8;
          local_c = local_64;
          local_54 = local_60;
        }
      }
    }
    local_60 = local_54;
    local_64 = local_c;
    if (local_54 != -1) {
      local_18 = 7;
      switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
      case 0:
        local_14 = 4;
        break;
      case 1:
        local_14 = 6;
        break;
      case 2:
        local_14 = 8;
        break;
      case 3:
        local_14 = 0xc;
        break;
      default:
        if (((&DAT_0067bdf8)[local_c * 100] & 1) == 0) {
          local_14 = 0x10;
        }
        else {
          local_14 = 0xc;
        }
      }
      FUN_0046e70d(7,0xf);
      u_temp = Adventure_CheckMonsterEncounter(local_60,local_14);
      *(int *)(&DAT_0067f2d0 + local_18 * 0x14) = u_temp;
      *(int *)(&DAT_0067f2d4 + local_18 * 0x14) =
           *(int *)(&DAT_0067bdf4 + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2d8 + local_18 * 0x14) =
           *(int *)(&DAT_0067bdf8 + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + local_18 * 0x14) = local_60;
      DAT_006410b4 = DAT_006410b4 + 1;
      FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + local_64 * 100),
                   *(int *)(&DAT_0067bdf8 + local_64 * 100));
      Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f510,0x97,100,100,0);
      FUN_0040a95d(s_newsback_pic_0052f528);
      strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____0052f538);
      file_name = (char *)Mem_AllocOrFree_00473d7e(local_60);
      strcat(&g_OverworldWorldState,file_name);
      strcat(&g_OverworldWorldState,s_Wizard_sends_0052f550);
      Adventure_FormatNewsString(*(int *)(&DAT_0067f2d0 + local_18 * 0x14),1,0);
      strcat(&g_OverworldWorldState,s_to_attack_0052f560);
      Ai_TownEncounter_004c3b19(local_64);
      strcat(&g_OverworldWorldState,&DAT_0052f56c);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
      Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
      Ai_Subsystem_004c05ba();
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

void Adventure_NewsFlash_Retaliation(int color_mask)

{
  int *piVar1;
  byte arg_1_00;
  int u_temp;
  char *file_name;
  int aiStack_80 [7];
  uint local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int aiStack_50 [7];
  int aiStack_34 [7];
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (DAT_006410b0 == 0) {
    App_ProcessPendingMessages();
    for (local_18 = 0; local_18 < 7; local_18 = local_18 + 1) {
      aiStack_34[local_18] = -1;
      aiStack_80[local_18] = 0;
    }
    for (local_18 = 0; local_18 < 0x80; local_18 = local_18 + 1) {
      if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 4) {
        u_temp = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + local_18 * 100),
                             *(int *)(&DAT_0067bdf8 + local_18 * 100));
        arg_1_00 = Adventure_GetLocationEncounterIndex(u_temp);
        local_60 = Card_ColorMaskToColorIndex(arg_1_00);
        if (local_60 == color_mask) {
          aiStack_34[local_60] = *(int *)(&DAT_0067bdf4 + local_18 * 100);
          aiStack_50[local_60] = *(int *)(&DAT_0067bdf8 + local_18 * 100);
        }
      }
      if ((&DAT_0067be01)[local_18 * 100] != '\0') {
        piVar1 = (int *)((int)aiStack_80 +
                        ((int)(*(uint *)(&DAT_0067be00 + local_18 * 100) & 0xffffff3f) >> 6));
        *piVar1 = *piVar1 + 1;
      }
    }
    local_5c = 0x7fff;
    for (local_64 = 0; (int)local_64 < 0x80; local_64 = local_64 + 1) {
      if (((((&DAT_0067be01)[local_64 * 100] == '\0') &&
           (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 4)) &&
          (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 1)) &&
         (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 5)) {
        local_58 = 0x7fff;
        for (local_18 = 1; local_18 < 6; local_18 = local_18 + 1) {
          if (aiStack_34[local_18] != -1) {
            local_10 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_64 * 100) - aiStack_34[local_18],
                                    *(int *)(&DAT_0067bdf8 + local_64 * 100) - aiStack_50[local_18])
            ;
            if (local_10 < local_58) {
              local_58 = local_10;
              local_60 = local_18;
            }
          }
        }
        local_8 = Math_RandomRange(0x80);
        local_8 = local_8 + aiStack_80[local_60] * 0x20;
        if (local_8 < local_5c) {
          local_5c = local_8;
          local_c = local_64;
          local_54 = local_60;
        }
      }
    }
    local_60 = local_54;
    local_64 = local_c;
    if (local_54 != -1) {
      local_18 = 7;
      switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
      case 0:
        local_14 = 4;
        break;
      case 1:
        local_14 = 6;
        break;
      case 2:
        local_14 = 8;
        break;
      case 3:
        local_14 = 0xc;
        break;
      default:
        if (((&DAT_0067bdf8)[local_c * 100] & 1) == 0) {
          local_14 = 0x10;
        }
        else {
          local_14 = 0xc;
        }
      }
      FUN_0046e70d(7,0xf);
      u_temp = Adventure_CheckMonsterEncounter(local_60,local_14);
      *(int *)(&DAT_0067f2d0 + local_18 * 0x14) = u_temp;
      *(int *)(&DAT_0067f2d4 + local_18 * 0x14) =
           *(int *)(&DAT_0067bdf4 + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2d8 + local_18 * 0x14) =
           *(int *)(&DAT_0067bdf8 + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + local_18 * 0x14) = local_60;
      DAT_006410b4 = DAT_006410b4 + 1;
      FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + local_64 * 100),
                   *(int *)(&DAT_0067bdf8 + local_64 * 100));
      Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f570,0x97,100,100,0);
      FUN_0040a95d(s_newsback_pic_0052f588);
      strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____0052f598);
      strcat(&g_OverworldWorldState,s_In_retaliation_for_your_effronte_0052f5ac);
      file_name = (char *)Mem_AllocOrFree_00473d7e(local_60);
      strcat(&g_OverworldWorldState,file_name);
      strcat(&g_OverworldWorldState,s_Wizard_sends_0052f5dc);
      Adventure_FormatNewsString(*(int *)(&DAT_0067f2d0 + local_18 * 0x14),1,0);
      strcat(&g_OverworldWorldState,s_to_attack_0052f5ec);
      Ai_TownEncounter_004c3b19(local_64);
      strcat(&g_OverworldWorldState,&DAT_0052f5f8);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
      Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
      *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
      Ai_Subsystem_004c05ba();
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
  char *pcVar1;
  LONG arg2;
  int val_result;
  int local_34 [9];
  uint local_10;
  int local_c;
  int local_8;
  
  local_34[7] = 7;
  DAT_006410b0 = 0;
  if (DAT_0067f35c != -1) {
    App_ProcessPendingMessages();
    local_10 = *(uint *)(&DAT_0067f2dc + local_34[7] * 0x14);
    local_34[8] = Duel_GetCardDrawOriginY
                            ((int)(*(int *)(&DAT_0067f2d4 + local_34[7] * 0x14) +
                                  (*(int *)(&DAT_0067f2d4 + local_34[7] * 0x14) >> 0x1f & 0x1fU)) >>
                             5,(int)(*(int *)(&DAT_0067f2d8 + local_34[7] * 0x14) +
                                    (*(int *)(&DAT_0067f2d8 + local_34[7] * 0x14) >> 0x1f & 0x1fU))
                               >> 5);
    *(uint *)(&DAT_0067be00 + local_34[8] * 100) =
         *(uint *)(&DAT_0067be00 + local_34[8] * 100) & 0xffff00ff;
    *(uint *)(&DAT_0067be00 + local_34[8] * 100) =
         *(uint *)(&DAT_0067be00 + local_34[8] * 100) | local_10 << 8;
    local_34[6] = 0;
    for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_0067be00 + local_8 * 100) >> 8 == local_10) {
        local_34[6] = local_34[6] + 1;
      }
    }
    if (DAT_00522598 == 0) {
      local_c = 5;
    }
    else {
      local_c = 3;
    }
    Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f5fc,0x97,100,100,0);
    FUN_0040a95d(s_newsback_pic_0052f614);
    local_34[1] = 0;
    local_34[2] = 1;
    local_34[3] = 0;
    local_34[4] = 1;
    local_34[5] = 0;
    strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____The_Evil_0052f624);
    pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_10);
    strcat(&g_OverworldWorldState,pcVar1);
    strcat(&g_OverworldWorldState,s_Wizard_taps_0052f644);
    Ai_TownEncounter_004c3b19(local_34[8]);
    if (local_c == local_34[6]) {
      if (local_34[local_10] == 0) {
        strcat(&g_OverworldWorldState,s___He_casts_the_spell_of_Dominion_0052f6c4);
      }
      else {
        strcat(&g_OverworldWorldState,s___She_casts_the_spell_of_Dominio_0052f6a0);
      }
    }
    else {
      if (local_34[local_10] == 0) {
        strcat(&g_OverworldWorldState,s___He_needs_0052f664);
      }
      else {
        strcat(&g_OverworldWorldState,s___She_needs_0052f654);
      }
      pcVar1 = _itoa(local_c - local_34[6],&DAT_005659c8,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_more_mana_taps_to_cast_the_Spell_0052f670);
    }
    if (((&DAT_0067be00)[local_34[8] * 100] & 1) != 0) {
      *(uint *)(&DAT_0067be00 + local_34[8] * 100) =
           *(uint *)(&DAT_0067be00 + local_34[8] * 100) & 0xfffffffe;
      strcat(&g_OverworldWorldState,s_Your_mana_tap_here_is_lost__0052f6e8);
    }
    DAT_006410b4 = DAT_006410b4 + 1;
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
    App_ProcessPendingMessages();
    Ai_Subsystem_004cd1d1();
    FUN_0046e70d(local_34[7],local_34[7] + 8);
    *(int *)(&DAT_0067f2d0 + local_34[7] * 0x14) = 0xffffffff;
    Adventure_Map_UpdateLightingAndPalette(3,local_10);
    Ai_Subsystem_004c05ba();
    DAT_006410b0 = 0;
    if (local_c <= local_34[6]) {
      Surface_TransformPoint(0,(short)DAT_00530d9c);
      Mem_AllocOrFree_00510de0(1,s_uth_arz_pic_0052f708);
      g_OverworldWorldState = 0;
      if ((g_DisplayScreenWidth == 0x280) || (g_DisplayScreenWidth == 800)) {
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
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_Wizard_have_attained_Dominion_ov_0052f770);
      strcat(&g_OverworldWorldState,s_The_people_will_suffer_a_thousan_0052f7b0);
      val_result = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceBackBuffer + 0x20));
      FUN_0040d269((int)g_DisplaySurfaceBackBuffer,0xea,0x140,val_result * -7 + 0x1e0);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
      App_ProcessPendingMessages();
      Ai_Subsystem_004cd1d1();
      Surface_TransformPoint(0,(short)DAT_00530d9c);
      DAT_006fe3f0 = 1;
      FUN_00409db6();
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

void Adventure_Audio_PlayEffect(char *color_mask,int arg2,int arg3,int arg4,int arg5)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_8;
  
  CloseSndTrack(arg2);
  Adventure_Audio_InitSoundTrack(color_mask,arg2,0);
  memset(&local_24,0,0x20);
  local_24 = arg3 << 2;
  local_20 = (arg4 * 0x5622) / 100;
  local_1c = arg5 << 2;
  local_8 = local_8 & 0xffffffee;
  PlaySnd(arg2,&local_24);
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

void Adventure_Audio_PlayEffectAtVolume(int color_mask,int y,int width,int height)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_8;
  
  memset(&local_24,0,0x20);
  local_24 = y << 2;
  local_20 = (width * 0x5622) / 100;
  local_1c = height << 2;
  local_8 = local_8 & 0xffffffee;
  PlaySnd(color_mask,&local_24);
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

void Adventure_Audio_PlayEffectLooped(int color_mask,int arg2,int arg3)

{
  int local_24 [7];
  uint local_8;
  
  memset(local_24,0,0x20);
  local_24[0] = arg2 << 2;
  local_24[1] = 0x5622;
  local_24[2] = arg3 << 2;
  local_8 = local_8 | 1;
  PlaySnd(color_mask,local_24);
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

void Adventure_Audio_StopEffectChannel(int color_mask,int arg2,int arg3)

{
  int local_24 [8];
  
  memset(local_24,0,0x20);
  local_24[0] = arg2 << 2;
  local_24[1] = 0x5622;
  local_24[2] = arg3 << 2;
  PlaySnd(color_mask,local_24);
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

void Adventure_Audio_SetPlaybackPosition(char *color_mask,int arg2)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_8;
  
  memset(&local_24,0,0x20);
  local_8 = local_8 | 4;
  local_24 = 400;
  local_20 = 0;
  local_1c = 0;
  Adventure_Audio_InitSoundTrack(color_mask,arg2,&local_24);
  SetSndMarker(arg2,1);
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
    StopSnd(0x10);
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

void Adventure_Audio_PlayCastleVictory(int color_mask)

{
  Adventure_Audio_StopAllTracks();
  if (DAT_0052f018 != -1) {
    CloseSndTrack(0x10);
  }
  DAT_0052f018 = color_mask + 0x15;
  switch(color_mask) {
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

void Adventure_Audio_PlayDuelIntro(int color_mask)

{
  if (DAT_0052f018 != -1) {
    CloseSndTrack(0x10);
  }
  DAT_0052f018 = 0x15;
  DAT_0052f064 = 0xffffffff;
  Adventure_Audio_SetPlaybackPosition((&PTR_s_x_sound_dueltune_wav_0052f070)[color_mask],0x10);
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

void Adventure_Audio_PlayTerrainAmbience(int color_mask)

{
  int arg_1_00;
  int status;
  int val_result;
  
  arg_1_00 = color_mask + 9;
  status = Math_RandomRange(200);
  status = status + -100;
  val_result = Math_RandomRange(0x32);
  Adventure_Audio_PlayEffectAtVolume(arg_1_00,100,val_result + 0x46,status);
  status = Math_RandomRange(3);
  if (status == 0) {
    CloseSndTrack(arg_1_00);
    switch(color_mask) {
    case 1:
      status = Math_RandomRange(3);
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
      status = Math_RandomRange(3);
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
      status = Math_RandomRange(2);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_gbird1_wav_0052f950,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_gland1_wav_0052f964,arg_1_00,0);
      }
      break;
    case 4:
      status = Math_RandomRange(2);
      if (status == 0) {
        Adventure_Audio_InitSoundTrack(s_x_sound_rbird1_wav_0052f978,arg_1_00,0);
      }
      else if (status == 1) {
        Adventure_Audio_InitSoundTrack(s_x_sound_rland1_wav_0052f98c,arg_1_00,0);
      }
      break;
    case 5:
      status = Math_RandomRange(2);
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

uint Adventure_Audio_FindSoundOnDrives(char *name_or_path)

{
  UINT UVar1;
  FILE *_File;
  int val_result;
  int *puVar3;
  uint local_104;
  int local_100 [63];
  
  local_104 = DAT_0052faf4;
  puVar3 = local_100;
  for (val_result = 0x3f; val_result != 0; val_result = val_result + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
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
      local_104._0_3_ = (uint3)(ushort)local_104;
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

void Adventure_Audio_FreeSoundTrack(void *color_mask)

{
  _DAT_00640f0c = _DAT_00640f0c + 1;
  InitSndTrack(color_mask,*(int *)((int)color_mask + 0x100),(int)color_mask + 0x104);
  free(color_mask);
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
  InitSndTrack(name_or_path,arg2,arg3);
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

int Adventure_Audio_GetTrackStatus(int color_mask)

{
  int u_res;
  
  switch(color_mask) {
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

int Adventure_Map_GetTerrainAtCoord(uint color_mask)

{
  int local_24;
  int local_20;
  int local_1c;
  uint local_18 [5];
  
  local_1c = 0;
  local_18[0] = color_mask & 0x20;
  local_18[1] = color_mask & 0x10;
  local_18[2] = color_mask & 4;
  local_18[3] = color_mask & 8;
  local_18[4] = color_mask & 2;
  for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
    if (local_18[local_20] != 0) {
      local_1c = local_1c + 1;
    }
  }
  if (local_1c == 1) {
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (local_18[local_20] != 0) {
        return local_20;
      }
    }
  }
  else {
    local_24 = Math_RandomRange(local_1c);
    local_24 = local_24 + 1;
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (local_18[local_20] != 0) {
        local_24 = local_24 + -1;
      }
      if (local_24 == 0) {
        return local_20;
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
  int local_8;
  
  for (local_44 = 0; local_44 < 5; local_44 = local_44 + 1) {
    local_4c = 0;
    local_8 = 0;
    status = Adventure_Audio_GetTrackStatus(local_44 + 1);
    for (local_48 = 0; local_48 < 0x80; local_48 = local_48 + 1) {
      if (((&DAT_0067be01)[local_48 * 100] != '\0') &&
         ((*(int *)(&DAT_0067be00 + local_48 * 100) >> 8) + -1 == local_44)) {
        local_8 = local_8 + 1;
      }
    }
    auStack_14[status] = (uint8_t)local_8;
    if (*(int *)(&DAT_006410c0 + local_44 * 4) == 0) {
      val_result = DAT_0067f380 * local_8 + DAT_0067f380 * 5 + 0x1e;
      for (local_48 = 0; (local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
          local_48 = local_48 + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == local_44 + 1) {
          local_4c = local_4c + 1;
        }
      }
      aiStack_28[status] = local_4c;
      temp_idx = DAT_0067f380 * 5 + 0x14;
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

int Adventure_Map_UpdateLightingAndPalette(uint color_mask,uint arg2)

{
  uint local_40 [7];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Surface_TransformPoint(0,(short)DAT_00530d9c);
  FUN_0050d560(0,0);
  LoadPalNoPic(s_advfac64_pic_0052fb10);
  local_14 = GetThreadPriority(DAT_00627850);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    local_20 = 0;
    local_c = 0;
    local_24 = Adventure_Audio_GetTrackStatus(local_18 + 1);
    for (local_1c = 0; local_1c < 0x80; local_1c = local_1c + 1) {
      if (((&DAT_0067be01)[local_1c * 100] != '\0') &&
         ((*(int *)(&DAT_0067be00 + local_1c * 100) >> 8) + -1 == local_18)) {
        local_c = local_c + 1;
      }
    }
    (&DAT_00641058)[local_24] = (uint8_t)local_c;
    if (*(int *)(&DAT_006410c0 + local_18 * 4) == 0) {
      local_10 = DAT_0067f380 * local_c + DAT_0067f380 * 5 + 0x1e;
      for (local_1c = 0; (local_1c < 1000 && ((&DAT_0067b9b0)[local_1c] != '\0'));
          local_1c = local_1c + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_1c] >> 4 == local_18 + 1) {
          local_20 = local_20 + 1;
        }
      }
      *(int *)(&DAT_00641044 + local_24 * 4) = local_20;
      local_40[6] = DAT_0067f380 * 5 + 0x14;
      if ((int)local_40[6] <= local_10 - local_20) {
        local_40[6] = local_10 - local_20;
      }
      *(uint *)(&DAT_00641030 + local_24 * 4) = 0x1e - (local_10 - local_40[6]);
    }
    else {
      *(int *)(&DAT_00641030 + local_24 * 4) = 0;
    }
  }
  DAT_0064105d = 0;
  DAT_0064105e = 0;
  DAT_0064105f = 0;
  if ((char)color_mask == '\x01') {
    if ((color_mask & 0x100) == 0) {
      *(int *)(&DAT_006410bc + arg2 * 4) = 1;
    }
    DAT_0064105d = Adventure_Audio_GetTrackStatus(arg2);
    *(int *)(&DAT_00641030 + (uint)DAT_0064105d * 4) = 0;
    color_mask = color_mask & 0xff;
  }
  if (color_mask == 2) {
    local_40[0] = arg2 >> 0x10;
    local_40[1] = 4;
    local_40[2] = 2;
    local_40[3] = 3;
    local_40[4] = 1;
    local_40[5] = 0;
    arg2 = arg2 & 0xffff;
    if ((&DAT_0052262b)[arg2 * 0x44] == -1) {
      color_mask = 0;
    }
    else {
      DAT_0064105e = (uint8_t)arg2;
      DAT_0064105d = (byte)local_40[local_40[0]];
    }
  }
  if (color_mask == 3) {
    DAT_0064105f = (uint8_t)arg2;
  }
  Mem_AllocOrFree_00409e13(&DAT_00641030,color_mask);
  SetThreadPriority(DAT_00627850,local_14);
  SetThreadPriority(DAT_00626820,local_8);
  SetForegroundWindow(_hwndScreen);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_0052fb20);
  Catalog_LoadPaletteMap(s_todpal_tr_0052fb30,(char *)0x0);
  SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(DAT_0070a850 + 4));
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
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 500; local_c = local_c + 1) {
    if (((*(int *)(&deck + local_c * 4) != -1) && (((&DAT_00702151)[local_c * 4] & 0x40) == 0)) &&
       (4 < (*(uint *)(&deck + local_c * 4) & 0xfff))) {
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    Mem_AllocOrFree_00510de0(1,s_uth_arz_pic_0052fb3c);
    g_OverworldWorldState = 0;
    *(int *)(g_DisplaySurfaceBackBuffer + 0x20) = 5;
    if ((g_DisplayScreenWidth == 0x280) || (g_DisplayScreenWidth == 800)) {
      local_10 = 0x14;
    }
    else {
      local_10 = 0x10;
    }
    arg2 = Ai_Util_004c3bc4(local_10);
    FUN_0050f2e0(5,arg2);
    strcat(&g_OverworldWorldState,s_You_have_no_power_for_even_an_An_0052fb48);
    strcat(&g_OverworldWorldState,s_Your_Righteous_Quest_has_Failed_0052fb70);
    strcat(&g_OverworldWorldState,s_The_Evil_Planeswalker_Arzakon_an_0052fb94);
    strcat(&g_OverworldWorldState,s_have_worn_you_down_0052fbcc);
    strcat(&g_OverworldWorldState,s_The_people_will_suffer_a_thousan_0052fbe4);
    status = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceBackBuffer + 0x20));
    FUN_0040d269((int)g_DisplaySurfaceBackBuffer,0xea,0x140,status * -7 + 0x1e0);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    App_ProcessPendingMessages();
    Ai_Subsystem_004cd1d1();
    Surface_TransformPoint(0,(short)DAT_00530d9c);
    DAT_006fe3f0 = 1;
    FUN_00409db6();
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
  DAT_005659f8 = CreatePopupMenu();
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
  if (DAT_005659f8 != (HMENU)0x0) {
    DestroyMenu(DAT_005659f8);
  }
  if (DAT_005659e0 != (HMENU)0x0) {
    DestroyMenu(DAT_005659e0);
  }
  DAT_005659f8 = (HMENU)0x0;
  DAT_005659e0 = (HMENU)0x0;
  return;
}

