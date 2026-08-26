/*
 * Decompiled function: Adventure_NewsFlash_DominionSpell
 * Entry Point: 004eb824
 * Size: 1208 bytes
 */
#include "magic.h"


void Adventure_NewsFlash_DominionSpell(void)

{
  char *pcVar1;
  LONG arg2;
  int iVar2;
  int local_34 [9];
  uint local_10;
  int local_c;
  int local_8;
  
  local_34[7] = 7;
  DAT_006410b0 = 0;
  if (DAT_0067f35c != -1) {
    FUN_0040a3e1();
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
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    FUN_0040a3e1();
    Ai_Subsystem_004cd1d1();
    FUN_0046e70d(local_34[7],local_34[7] + 8);
    *(undefined4 *)(&DAT_0067f2d0 + local_34[7] * 0x14) = 0xffffffff;
    Adventure_Map_UpdateLightingAndPalette(3,local_10);
    Ai_Subsystem_004c05ba();
    DAT_006410b0 = 0;
    if (local_c <= local_34[6]) {
      FUN_005112b0(0,(short)DAT_00530d9c);
      Mem_AllocOrFree_00510de0(1,s_uth_arz_pic_0052f708);
      g_OverworldWorldState = 0;
      if ((DAT_00522458 == 0x280) || (DAT_00522458 == 800)) {
        local_34[0] = 0x14;
      }
      else {
        local_34[0] = 0x10;
      }
      *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 5;
      arg2 = Ai_Util_004c3bc4(local_34[0]);
      FUN_0050f2e0(5,arg2);
      strcat(&g_OverworldWorldState,s_Your_Righteous_Quest_has_Failed_0052f714);
      strcat(&g_OverworldWorldState,s_The_Evil_Planeswalker_Arzakon_an_0052f738);
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_Wizard_have_attained_Dominion_ov_0052f770);
      strcat(&g_OverworldWorldState,s_The_people_will_suffer_a_thousan_0052f7b0);
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceBackBuffer + 0x20));
      FUN_0040d269((int)g_DisplaySurfaceBackBuffer,0xea,0x140,iVar2 * -7 + 0x1e0);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_005112b0(0,(short)DAT_00530d9c);
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


