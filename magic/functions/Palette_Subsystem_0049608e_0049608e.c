/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 0049608e
 * Size: 418 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x0049621a) */

undefined4 Palette_Subsystem_0049608e(void)

{
  Ordinal_17();
  Pic_Subsystem_00442010(s_MAGICGAME_MainClass_0052b2f0);
  UI_Register_sPoison_0047c640(s_MAGICGAME_LifeClass_0052b304);
  Palette_Subsystem_00499720(s_MAGICGAME_FullCardClass_0052b318);
  Ai_CalcManaRequirement_004b9120(s_MAGICGAME_ManaSummaryClass_0052b330);
  Pic_Subsystem_0044b9c0(s_MAGICGAME_HandClass_0052b34c);
  Duel_RegisterChildCardWindowClass(s_MAGICGAME_ChatClass_0052b360);
  Minit_Subsystem_00467880(s_MAGICGAME_CardClass_0052b374);
  Pic_Load_004248b0(s_MAGICGAME_PhaseDisplayClass_0052b388);
  Pic_Load_00424a1e(s_MAGICGAME_AttackPhaseDisplayClas_0052b3a4);
  Adventure_PromptConfirmDialog(s_MAGICGAME_TerritoryClass_0052b3c8);
  UI_CreateWindow_0050bba0(s_MAGICGAME_LibraryClass_0052b3e4);
  Pic_Subsystem_00449340(s_MAGICGAME_GraveyardClass_0052b3fc);
  UI_Register_WINBK_Attack_0047d460(s_MAGICGAME_AttackClass_0052b418);
  SpellChain_RegisterClass(s_MAGICGAME_SpellChainClass_0052b430);
  UI_Register_FACE_BLACK_00408e20(s_MAGICGAME_FaceClass_0052b44c);
  UI_CreateWindow_00478b20(s_MAGICGAME_ScrollbarClass_0052b460);
  UI_CreateWindow_0041df60(s_MAGICTHEME_IconButtonClass_0052b47c);
  UI_Register_WINBK_BigCard_00401e65(s_MAGICGAME_BigCardChoiceClass_0052b498);
  UI_CreateWindow_00401c91(s_MAGICGAME_BigCardCardClass_0052b4b8);
  UI_CreateWindow_00501ad0(s_MAGIC_PaletteClass_0052b4d4);
  UI_CreateWindow_004081b0(s_MAGIC_CueCardClass_0052b4e8);
  Pic_Subsystem_004241f0(s_MAGIC_PlayerDirectiveClass_0052b4fc);
  Prompts_Load_00476e60(s_MAGIC_TellUserClass_0052b518);
  return 1;
}


