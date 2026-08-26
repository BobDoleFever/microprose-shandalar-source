/*
 * Decompiled function: Palette_Subsystem_00496230
 * Entry Point: 00496230
 * Size: 258 bytes
 */
#include "magic.h"


void Palette_Subsystem_00496230(void)

{
  FUN_0047c734(s_MAGICGAME_LifeClass_0052b52c);
  Palette_Subsystem_004997b8(s_MAGICGAME_FullCardClass_0052b540);
  Ai_Subsystem_004b920e(s_MAGICGAME_ManaSummaryClass_0052b558);
  Pic_Subsystem_0044ba83(s_MAGICGAME_HandClass_0052b574);
  Duel_UnregisterCardWindowClass(s_MAGICGAME_ChatClass_0052b588);
  Minit_Subsystem_0046799f(s_MAGICGAME_CardClass_0052b59c);
  Pic_Subsystem_004249a8(s_MAGICGAME_PhaseDisplayClass_0052b5b0);
  Pic_Subsystem_00424aef(s_MAGICGAME_AttackPhaseDisplayClas_0052b5cc);
  Adventure_DestroyConfirmMenu(s_MAGICGAME_TerritoryClass_0052b5f0);
  FUN_0050bcd6(s_MAGICGAME_LibraryClass_0052b60c);
  Pic_Subsystem_004494d1(s_MAGICGAME_GraveyardClass_0052b624);
  FUN_0047d85c(s_MAGICGAME_AttackClass_0052b640);
  SpellChain_CleanupUI(s_MAGICGAME_SpellChainClass_0052b658);
  FUN_00409052(s_MAGICGAME_FaceClass_0052b674);
  FUN_00478bd5(s_MAGICGAME_ScrollbarClass_0052b688);
  Mem_AllocOrFree_00401f40(s_MAGICGAME_BigCardChoiceClass_0052b6a4);
  Mem_AllocOrFree_00401d23(s_MAGICGAME_BigCardCardClass_0052b6c4);
  FUN_004082d1(s_MAGIC_CueCardClass_0052b6e0);
  FUN_004770bc(s_MAGIC_TellUserClass_0052b6f4);
  return;
}


