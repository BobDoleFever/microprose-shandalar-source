/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 00438368
 * Size: 418 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x004384f4) */

undefined4 Palette_Subsystem_0049608e(void)

{
  Ordinal_17();
  UI_CreateWindow_004b3360(s_MAGICGAME_MainClass_004f6d58);
  UI_Register_sPoison_00499ba0(s_MAGICGAME_LifeClass_004f6d6c);
  UI_CreateWindow_0041a600(s_MAGICGAME_FullCardClass_004f6d80);
  Ai_CalcManaRequirement_004b9120(s_MAGICGAME_ManaSummaryClass_004f6d98);
  UI_CreateWindow_004b9460(s_MAGICGAME_HandClass_004f6db4);
  UI_CreateWindow_00401000(s_MAGICGAME_ChatClass_004f6dc8);
  Minit_Subsystem_00467880(s_MAGICGAME_CardClass_004f6ddc);
  Pic_Load_004248b0(s_MAGICGAME_PhaseDisplayClass_004f6df0);
  Pic_Load_00424a1e(s_MAGICGAME_AttackPhaseDisplayClas_004f6e0c);
  Glue_Subsystem_004ecee0(s_MAGICGAME_TerritoryClass_004f6e30);
  UI_CreateWindow_00486c90(s_MAGICGAME_LibraryClass_004f6e4c);
  Pic_Subsystem_00449340(s_MAGICGAME_GraveyardClass_004f6e64);
  UI_Register_WINBK_Attack_00493810(s_MAGICGAME_AttackClass_004f6e80);
  Glue_Subsystem_004cd760(s_MAGICGAME_SpellChainClass_004f6e98);
  UI_Register_FACE_BLACK_00436820(s_MAGICGAME_FaceClass_004f6eb4);
  UI_CreateWindow_0046f240(s_MAGICGAME_ScrollbarClass_004f6ec8);
  UI_CreateWindow_0042b2a0(s_MAGICTHEME_IconButtonClass_004f6ee4);
  UI_Register_WINBK_BigCard_0049036d(s_MAGICGAME_BigCardChoiceClass_004f6f00);
  UI_CreateWindow_00490196(s_MAGICGAME_BigCardCardClass_004f6f20);
  UI_CreateWindow_0044bd60(s_MAGIC_PaletteClass_004f6f3c);
  UI_CreateWindow_004917d0(s_MAGIC_CueCardClass_004f6f50);
  UI_CreateWindow_00433e40(s_MAGIC_PlayerDirectiveClass_004f6f64);
  Palette_Color_0049ae00(s_MAGIC_TellUserClass_004f6f80);
  return 1;
}


