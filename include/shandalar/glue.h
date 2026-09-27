/*
 * shandalar/glue.h - Master Declarations & Subsystems for Shandalar Engine
 * MicroProse Magic: The Gathering (Shandalar 1997) Reconstructed ANSI C Engine
 */
#ifndef SHANDALAR_GLUE_H
#define SHANDALAR_GLUE_H

#include "types.h"
#include "win32_compat.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================= */
/* Modernized Function Prototypes (251 Subsystem Functions)                  */
/* ========================================================================= */

int Timer_InitVxD(void);
int Timer_GetTicks(void);
void Timer_MarkStart(void);
int Timer_GetElapsedFraction(void);
int SpellChain_RegisterClass(LPCSTR name_or_path);
void SpellChain_CleanupUI(void);
uint32_t SpellChain_WndProc(HWND hwnd,uint32_t y,HWND wParam,uint32_t height);
int SpellChain_FindEntryIndex(HWND hwnd);
void SpellChain_RemoveEntry(HWND hwnd,int arg2);
bool SpellChain_EntryTargetsMatch(void);
int SpellChain_InsertEntry(HWND hwnd,int arg2,int arg3);
void SpellChain_ClearEntryTargets(HWND hwnd,int arg2);
int SpellChain_RebuildEntryTargets(HWND hwnd);
void SpellChain_UpdateLayout(HWND hwnd,LPRECT arg2);
void SpellChain_GetContentRect(int arg1,LPRECT arg2);
LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,uint32_t lParam);
BOOL SpellChain_MinimizeIfShown(void);
bool SpellChain_RestoreIfMinimized(void);
int Card_DefaultEventHandler(void);
uint32_t Card_GetColorAndTypeFlags(int arg1,int arg2);
int Card_PrismaticDragon_ColorChange(int player,int card_index,int event_code);
int Card_RainbowKnights_ActivatedAbility(int player,int card_index,int event_code);
bool Card_Sinbad_Draw(int player,int card_index,int event_code);
int Card_Kudzu_LandDestruction(int player,int card_index,int event_code);
void Card_BronzeTablets_AnteSwap(int player,int card_index,int event_code);
int Card_XenicPoltergeist_AnimateArtifact(int player,int card_index,int event_code);
int Card_VesuvanDoppelganger_Copy(int player,int card_index,int event_code);
int Card_VesuvanDoppelganger_Upkeep(int player,int card_index,int event_code);
int Card_Doppelganger_ClearMimic(int player,int card_index);
int Card_Doppelganger_ApplyMimicStats(int player,int card_index);
int Card_Doppelganger_SyncAbilities(int player,int card_index);
int Card_Doppelganger_CheckState(int player,int card_index,int event_code);
int Card_IslandSanctuary_SkipDraw(int player,int card_index,int event_code);
int Card_IslandSanctuary_AttackRestriction(int player,int card_index,int event_code);
int Card_IslandSanctuary_Trigger(int player,int card_index,int event_code);
int Card_IslandSanctuary_CheckActive(int player,int card_index,int event_code);
int Card_IslandSanctuary_Prompt(int player,int card_index,int event_code);
int Card_LivingLands_AnimateForests(int player,int card_index,int event_code);
int Card_KormusBell_AnimateSwamps(int player,int card_index,int event_code);
int Card_TitaniasSong_AnimateArtifacts(int player,int card_index,int event_code);
int Card_TitaniasSong_RemoveAbilities(int player,int card_index,int event_code);
int Card_TitaniasSong_RestoreAbilities(int player,int card_index,int event_code);
int Card_TitaniasSong_UpdateStatus(int player,int card_index,int event_code);
int Card_TitaniasSong_ClearFlags(int player,int card_index,int event_code);
int Card_TitaniasSong_CheckTrigger(int player,int card_index,int event_code);
int Card_PersonalIncarnation_RedirectDamage(int player,int card_index,int event_code);
int Card_AliFromCairo_PreventLethalDamage(int player,int card_index,int event_code);
int Card_AliFromCairo_ResetState(int player,int card_index,int event_code);
int Card_ShivanDragon_PumpFirebreathing(int player,int card_index,int event_code);
int Card_DragonWhelp_PumpFirebreathing(int player,int card_index,int event_code);
int Card_DragonWhelp_EndTurnCheck(int player,int card_index,int event_code);
int Card_FrozenShade_ClearBoost(int player,int card_index);
int Card_FrozenShade_PumpBlack(int player,int card_index,int event_code);
int Card_WaterElemental_PumpBlue(int player,int card_index,int event_code);
int Card_ClockworkBeast_ResetCounters(int player,int card_index,int event_code);
int Card_ClockworkBeast_CombatTrigger(int player,int card_index,int event_code);
int Card_ClockworkBeast_Rewind(int player,int card_index,int event_code);
int Card_ClockworkBeast_GetPower(int player,int card_index,int event_code);
int Card_ClockworkBeast_GetToughness(int player,int card_index,int event_code);
int Card_GaeasLiege_TransformLand(int player,int card_index,int event_code);
int Card_GaeasLiege_ResetLand(int player,int card_index,int event_code);
int Card_GaeasLiege_CheckAttackRestriction(int player,int card_index,int event_code);
int Card_GaeasLiege_IsForest(int player,int card_index,int event_code);
int Card_GaeasLiege_CombatCheck(int player,int card_index,int event_code);
int Card_SedgeTroll_CheckSwamp(int player,int card_index,int event_code);
int Card_SedgeTroll_Regenerate(int player,int card_index,int event_code);
int Card_LivingWall_PromptRegenerate(int player,int card_index,int event_code);
int Card_LivingWall_Regenerate(int player,int card_index,int event_code);
int Card_GenericCreature_Regenerate(int player,int card_index,int event_code,uint32_t action_param,int extra_flags);
int Card_GenericCreature_CanRegenerate(int player,int card_index);
int Card_GenericCreature_TriggerRegen(int player,int card_index,int event_code);
int Card_DrudgeSkeletons_Regenerate(int player,int card_index,int event_code);
int Card_UthdenTroll_Regenerate(int player,int card_index,int event_code);
int Card_WillOTheWisp_Regenerate(int player,int card_index,int event_code);
int Card_MarrowThieves_Regenerate(int player,int card_index,int event_code);
void Card_HypnoticSpecter_RandomDiscard(int player,int card_index,int event_code);
int Card_TimeElemental_BouncePermanent(int player,int card_index,int event_code);
int Card_NorthernPaladin_DestroyBlack(int player,int card_index,int event_code);
int Card_RoyalAssassin_DestroyTapped(int player,int card_index,int event_code);
int Card_DwarvenDemolitionTeam_DestroyWall(int player,int card_index,int event_code);
int Card_KingSuleiman_DestroyDjinn(int player,int card_index,int event_code);
int Card_Targeting_PromptCreature(int x,int y,int width,uint32_t height);
int Card_NettlingImp_ForceAttack(int player,int card_index,int event_code);
bool Card_NettlingImp_CheckEndTurn(int player,int card_index,int event_code);
int Card_NettlingImp_IsTargetEligible(int player,int card_index,int event_code);
int Card_SorceressQueen_SetStats02(int player,int card_index,int event_code);
void Card_SorceressQueen_ResetStats(int player,int card_index,int event_code);
int Card_StoneGiant_Fling(int player,int card_index,int event_code);
int Card_DwarvenWarriors_MakeUnblockable(int player,int card_index,int event_code);
int Card_CavePeople_Mountainwalk(int player,int card_index,int event_code);
int Card_PradeshGypsies_PreventAttack(int player,int card_index,int event_code);
int Card_PradeshGypsies_ResetRestriction(int player,int card_index,int event_code);
uint8_t Card_SamiteHealer_PreventDamage(int player,int card_index,int event_code);
int Card_SamiteHealer_CalculateHealAdvantage(int player,int card_index,int event_code);
int Card_AlabasterPotion_HealOrPrevent(int player,int card_index,int event_code);
int Card_HealingSalve_DamagePrevention(int player,int card_index,int event_code);
int Card_DamagePrevention_ApplyBubble(int player,int card_index);
int Card_DamagePrevention_ReduceDamage(int player,int card_index,int event_code);
int Card_DamagePrevention_ClearAtCleanup(int player,int card_index,int event_code);
int Card_DamagePrevention_QueryAmount(int player,int card_index,int event_code);
int Card_DamagePrevention_PromptTarget(int player,int card_index,int event_code);
int Card_DamagePrevention_CheckSource(int player,int card_index,int event_code);
int Card_ErgRaiders_UpkeepDamage(int player,int card_index,int event_code);
int Card_ErgRaiders_MarkAttack(int player,int card_index,int event_code);
int Card_ErgRaiders_ClearTurnAttack(int player,int card_index,int event_code);
int Card_Leviathan_SacrificeLands(int player,int card_index,int event_code);
int Card_Leviathan_PromptLandSacrifice(int player,int card_index,int event_code);
int Card_Leviathan_SelectLand(int player,int card_index,int event_code);
int Card_Leviathan_AttackTrigger(int player,int card_index,int event_code);
int Card_BrothersOfFire_Ping(int player,int card_index,int event_code);
bool Card_BrothersOfFire_EvaluateTarget(int player,int card_index,int event_code);
int Card_CrimsonManticore_DamageTarget(int player,int card_index,int event_code);
bool Card_ProdigalSorcerer_PingTarget(int player,int card_index,int event_code);
bool Card_DirectDamage_EvaluateBestTarget(int player,int card_index);
int Card_DirectDamage_PromptAndDealDamage(int x,int y,int width,int height);
bool Card_PirateShip_PingTarget(int player,int card_index,int event_code);
int Card_PirateShip_CheckIslandwalk(int player,int card_index,int event_code);
int Card_PirateShip_HasIsland(int player,int card_index,int event_code);
int Card_PirateShip_AttackTrigger(int player,int card_index,int event_code);
int Card_IslandFishJasconius_PayToUntap(int player,int card_index,int event_code);
int Card_IslandFishJasconius_CheckIslands(int player,int card_index,int event_code);
int Card_IslandFishJasconius_DestroyIfNoIslands(int player,int card_index,int event_code);
uint32_t Card_RodOfRuin_Ping(int player,int card_index,int event_code);
int Card_RodOfRuin_EvaluateAi(int player,int card_index,int event_code);
int Card_RodOfRuin_PayActivation(int player,int card_index,int event_code);
int Card_RodOfRuin_SelectTarget(int player,int card_index,int event_code);
bool Card_OrcishArtillery_ShootTarget(int player,int card_index,int event_code);
bool Card_PsionicEntity_ShootTarget(int player,int card_index,int event_code);
int Card_PsionicEntity_EvaluateTarget(int player,int card_index,int event_code);
int Card_PsionicEntity_SelfDamage(int player,int card_index,int event_code);
int Card_KhabalGhoul_AddCounterOnDeath(int player,int card_index,int event_code);
int Card_KhabalGhoul_CheckCreatureDeath(int player,int card_index,int event_code);
int Card_KhabalGhoul_ApplyCounterBonus(int player,int card_index,int event_code);
int Card_KhabalGhoul_ResetCounterBonus(int player,int card_index,int event_code);
int Card_LordOfAtlantis_PayOrSacrifice(int player,int card_index,int event_code);
int Card_LordOfAtlantis_ApplyMerfolkBuff(int player,int card_index,int event_code);
int Card_LordOfAtlantis_RemoveMerfolkBuff(int player,int card_index,int event_code);
int Card_LordOfAtlantis_IslandwalkTrigger(int player,int card_index,int event_code);
int Card_LordOfAtlantis_CheckMerfolkType(int player,int card_index);
int Card_ForceOfNature_PayUpkeep(int player,int card_index,int event_code);
bool Card_ForceOfNature_AiPayOrTakeDamage(int player,int card_index,int event_code);
bool Card_BirdsOfParadise_TapForMana(int player,int card_index,int event_code);
int Card_CosmicHorror_PayUpkeep(int player,int card_index,int event_code);
int Card_LordOfThePit_SacrificeOrDamage(int player,int card_index,int event_code);
int Card_LordOfThePit_FindSacrificeCandidate(int player,int card_index);
int Card_KormusBell_PayLandUpkeep(int player,int card_index,int event_code);
int Card_KormusBell_CheckSwampCreature(int player,int card_index,int event_code);
int Card_NetherShadow_CheckGraveyard(int player,int card_index,int event_code);
int Card_NetherShadow_CountCreaturesAbove(int player,int card_index,int event_code);
int Card_NetherShadow_ReturnFromGrave(int player,int card_index,int event_code);
int Card_RockHydra_DecrementHead(int player,int card_index,int event_code);
int Card_RockHydra_DamageTrigger(int player,int card_index,int event_code);
void Card_RockHydra_UpdateStatsFromHeads(int player,int card_index,int event_code);
int Card_RockHydra_InitHeads(int player,int card_index,int event_code);
int Card_RockHydra_RegrowHead(int player,int card_index,int event_code);
int Card_AliBaba_TapWall(int player,int card_index,int event_code);
int Card_LeyDruid_UntapLand(int player,int card_index,int event_code);
uint32_t Card_LeyDruid_AiEvaluateLand(int player,int card_index,int event_code);
int Card_LeyDruid_ExecuteUntap(int player,int card_index,int event_code);
void Card_HurkylsRecall_PickArtifact(int player,int card_index,int event_code);
void Card_HurkylsRecall_ReturnAllArtifacts(int player,int card_index,int event_code);
int Card_Venom_DestroyCombatBlocker(int player,int card_index,int event_code);
int Card_Venom_AttachToCreature(int player,int card_index,int event_code);
int Card_Venom_CombatDamageTrigger(int player,int card_index,int event_code);
int Card_Venom_DestroyAtEndOfCombat(int player,int card_index,int event_code);
bool Card_Venom_AiEvaluateAura(int player,int card_index,int event_code);
int Card_Venom_AiCastScore(int player,int card_index,int event_code);
int Card_Venom_ClearAuraFlags(int player,int card_index,int event_code);
int Card_RadjanSpirit_RemoveFlying(int player,int card_index,int event_code);
int Card_HurrJackal_GrantCombatAbility(int player,int card_index,int event_code);
int CardQuery_PlayerControlsColor(int arg1,uint8_t arg2);
void CardQuery_ForEachPermanent(uint8_t *arg1,int arg2);
void Card_IncrementCounter(int player,int card_index);
void Card_DecrementCounter(int player,int card_index);
void Card_AddCounters(int player,int card_index,int event_code);
void Card_RemoveCounters(int player,int card_index,int event_code);
void Card_SetCounters(int player,int card_index,int event_code);
uint32_t Card_GetCounters(int player,int card_index);
bool CardTarget_PromptTargetCreature(int arg1,uint32_t arg2,int arg3);
bool CardTarget_SetTargetCreature(int arg1,uint32_t arg2,int arg3);
int CardTarget_HasValidCreatureTarget(int arg1);
bool CardTarget_PromptTargetPermanent(int arg1,uint32_t arg2,int arg3);
bool CardTarget_SetTargetPermanent(int arg1,uint32_t arg2,int arg3);
int CardTarget_HasValidPermanentTarget(int arg1);
bool CardTarget_PromptTargetPlayerOrCreature(int arg1,uint32_t arg2,int arg3);
bool CardTarget_SetTargetPlayerOrCreature(int arg1,uint32_t arg2,int arg3);
int CardTarget_HasValidPlayerOrCreatureTarget(int arg1);
int Adventure_EnterTownLocation(void);
void Adventure_PromptLocationMenu(void);
int Adventure_HandleLocationMenuChoice(int arg1,int arg2);
void Adventure_ExitTownLocation(void);
int Adventure_PlayLocationMusic(void);
void Adventure_UpdateWorldMapLoop(void);
int Adventure_GetLocationEncounterIndex(int arg1);
int Adventure_SetLocationEncounterIndex(int arg1);
int Adventure_CheckMonsterEncounter(int arg1,int arg2);
void Adventure_FormatNewsString(int arg1,int arg2,int arg3);
int Adventure_AppendNewsDetails(int arg1,int arg2);
void Adventure_PlayMonsterEncounterSound(int x,int arg2,int arg3,int height);
void Adventure_TriggerDuelFromEncounter(void);
void Adventure_ReloadWorldPalette(int arg1);
void Adventure_LoadFacePalette(int arg1);
void Adventure_NewsFlash_EnemyAttack(void);
void Adventure_NewsFlash_Retaliation(int arg1);
void Adventure_NewsFlash_DominionSpell(void);
void Adventure_Audio_PlayEffect(char *arg1,int arg2,int arg3,int arg4,int arg5);
void Adventure_Audio_PlayEffectAtVolume(int arg1,int y,int width,int height);
void Adventure_Audio_PlayEffectLooped(int arg1,int arg2,int arg3);
void Adventure_Audio_StopEffectChannel(int arg1,int arg2,int arg3);
void Adventure_Audio_SetPlaybackPosition(char *arg1,int arg2);
void Adventure_Audio_StopAllTracks(void);
void Adventure_Audio_PlayCastleVictory(int arg1);
void Adventure_Audio_PlayDuelIntro(int arg1);
void Adventure_Audio_PlayTerrainAmbience(int arg1);
void Adventure_Audio_PlayFootstep(void);
uint32_t Adventure_Audio_FindSoundOnDrives(char *name_or_path);
char Adventure_Audio_GetMusicDrivePath(void);
void Adventure_Audio_FreeSoundTrack(void *arg1);
int Adventure_Audio_InitSoundTrack(char *name_or_path,int arg2,int arg3);
int Adventure_Audio_GetTrackStatus(int arg1);
int Adventure_Map_GetTerrainAtCoord(uint32_t arg1);
void Adventure_Map_RedrawViewport(void);
int Adventure_Map_UpdateLightingAndPalette(uint32_t arg1,uint32_t arg2);
void Adventure_ShowDefeatScreen(void);
bool Adventure_PromptConfirmDialog(LPCSTR name_or_path);
void Adventure_DestroyConfirmMenu(void);
int Duel_MainArena_WndProc(HWND hwnd,uint32_t y,HWND wParam,uint32_t height);
void Duel_UpdateWindowScroll(HWND hwnd);
void Duel_BringCardWindowToTop(HWND hwnd);
void Duel_GetBattlefieldClientRect(HWND hwnd);
void Duel_LayoutCardSlots(HWND hwnd,int *arg2,int arg3,int *arg4,int *arg5,int arg6);
void Duel_ScrollLeftButton_Handler(HWND hwnd,HWND uMsg);
void Duel_ScrollRightButton_Handler(HWND hwnd,LPARAM arg2,uint8_t arg3);
int Duel_HitTestCardSlot(HWND hwnd,int *y,int *arg3,int *arg4);
int Duel_GetHoveredCardSlot(HWND hwnd,int *arg2);
int Duel_GetCardSlotWindowHandle(HWND hwnd,int arg2);
int Duel_GetTargetSlotWindowHandle(HWND hwnd,int arg2);
HGDIOBJ Duel_PaintBattlefieldBackground(HWND hwnd,uint32_t arg2,HDC hdc);
int Duel_LogActionStatusBanner(int spell_id,int target_id,int flags,uint32_t arg4,uint32_t arg5,char *banner_text,
              int arg7);
bool Duel_RegisterChildCardWindowClass(LPCSTR name_or_path);
void Duel_UnregisterCardWindowClass(void);
LRESULT Duel_ChildCard_WndProc(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);
int Duel_GetCardDrawOriginX(int arg1,int arg2);
int Duel_GetCardDrawOriginY(int arg1,int arg2);
void Duel_TriggerCardDrawAnimation(void);
int Duel_UpdateCardMotionStep(uint32_t arg1);
void Duel_ResetCardAnimationState(char arg1,char arg2);
int Bazaar_GetCardBaseValue(int arg1);
int Bazaar_SellCardsDialog(int arg1);
int * Catalog_LoadWaveletCardArt(int arg1,char *file_name,int arg3);
int Catalog_ReleaseWaveletLock(void);

/* ========================================================================= */
/* Backward Compatibility Aliases for Legacy Decompiled Symbols             */
/* ========================================================================= */

#define Card_ChaosLace_ModifyAttributes Card_RainbowKnights_ActivatedAbility
#define Card_ColorWard_ChangeColor Card_PrismaticDragon_ColorChange
#define Timer_InitDavesExtraCoolTimer Timer_InitVxD
#define FUN_004cd6e3 Timer_GetTicks
#define FUN_004cd715 Timer_MarkStart
#define FUN_004cd72a Timer_GetElapsedFraction
#define UI_RegisterSpellChainWindowClasses SpellChain_RegisterClass
#define FUN_004cda01 SpellChain_CleanupUI
#define UI_SpellChainWndProc SpellChain_WndProc
#define FUN_004cf8b6 SpellChain_FindEntryIndex
#define FUN_004cf965 SpellChain_RemoveEntry
#define FUN_004cfab2 SpellChain_EntryTargetsMatch
#define UI_SpellCardWndProc SpellChain_InsertEntry
#define FUN_004cfd68 SpellChain_ClearEntryTargets
#define UI_SpellTargetCardWndProc SpellChain_RebuildEntryTargets
#define FUN_004cffda SpellChain_UpdateLayout
#define FUN_004d05e8 SpellChain_GetContentRect
#define UI_MinimizedSpellChainWndProc SpellChain_MinimizedWndProc
#define FUN_004d0965 SpellChain_MinimizeIfShown
#define FUN_004d09bd SpellChain_RestoreIfMinimized
#define FUN_004d0a30 Card_DefaultEventHandler
#define FUN_004d0a42 Card_GetColorAndTypeFlags
#define FUN_004d0cdb Card_PrismaticDragon_ColorChange
#define FUN_004d109a Card_RainbowKnights_ActivatedAbility
#define CardScript_Sinbad Card_Sinbad_Draw
#define FUN_004d1e10 Card_Kudzu_LandDestruction
#define FUN_004d212c Card_BronzeTablets_AnteSwap
#define CardScript_XenicPoltergeist Card_XenicPoltergeist_AnimateArtifact
#define CardScript_VesuvanDoppelganger Card_VesuvanDoppelganger_Copy
#define FUN_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define FUN_004d2d28 Card_Doppelganger_ClearMimic
#define FUN_004d2e2a Card_Doppelganger_ApplyMimicStats
#define FUN_004d2f6c Card_Doppelganger_SyncAbilities
#define FUN_004d30ae Card_Doppelganger_CheckState
#define FUN_004d3144 Card_IslandSanctuary_SkipDraw
#define FUN_004d31a9 Card_IslandSanctuary_AttackRestriction
#define FUN_004d3229 Card_IslandSanctuary_Trigger
#define FUN_004d328c Card_IslandSanctuary_CheckActive
#define FUN_004d332a Card_IslandSanctuary_Prompt
#define FUN_004d353d Card_LivingLands_AnimateForests
#define FUN_004d374d Card_KormusBell_AnimateSwamps
#define FUN_004d395d Card_TitaniasSong_AnimateArtifacts
#define FUN_004d3d1d Card_TitaniasSong_RemoveAbilities
#define FUN_004d3d82 Card_TitaniasSong_RestoreAbilities
#define FUN_004d3dff Card_TitaniasSong_UpdateStatus
#define FUN_004d3fa1 Card_TitaniasSong_ClearFlags
#define FUN_004d4099 Card_TitaniasSong_CheckTrigger
#define CardScript_PersonalIncarnation Card_PersonalIncarnation_RedirectDamage
#define CardScript_AliFromCairo Card_AliFromCairo_PreventLethalDamage
#define FUN_004d4d1f Card_AliFromCairo_ResetState
#define FUN_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define FUN_004d5626 Card_DragonWhelp_PumpFirebreathing
#define FUN_004d5c1e Card_DragonWhelp_EndTurnCheck
#define FUN_004d6391 Card_FrozenShade_ClearBoost
#define FUN_004d6400 Card_FrozenShade_PumpBlack
#define FUN_004d6706 Card_WaterElemental_PumpBlue
#define FUN_004d683f Card_ClockworkBeast_ResetCounters
#define FUN_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define FUN_004d6c43 Card_ClockworkBeast_Rewind
#define FUN_004d6d82 Card_ClockworkBeast_GetPower
#define FUN_004d6e79 Card_ClockworkBeast_GetToughness
#define CardScript_GaeasLiege Card_GaeasLiege_TransformLand
#define FUN_004d7724 Card_GaeasLiege_ResetLand
#define FUN_004d777b Card_GaeasLiege_CheckAttackRestriction
#define FUN_004d788d Card_GaeasLiege_IsForest
#define FUN_004d78d2 Card_GaeasLiege_CombatCheck
#define FUN_004d79a6 Card_SedgeTroll_CheckSwamp
#define CardScript_SedgeTroll Card_SedgeTroll_Regenerate
#define FUN_004d7b68 Card_LivingWall_PromptRegenerate
#define CardScript_LivingWall Card_LivingWall_Regenerate
#define FUN_004d7c60 Card_GenericCreature_Regenerate
#define FUN_004d7e90 Card_GenericCreature_CanRegenerate
#define FUN_004d80d3 Card_GenericCreature_TriggerRegen
#define FUN_004d817b Card_DrudgeSkeletons_Regenerate
#define FUN_004d87cb Card_UthdenTroll_Regenerate
#define FUN_004d8e4c Card_WillOTheWisp_Regenerate
#define FUN_004d94e1 Card_MarrowThieves_Regenerate
#define FUN_004d9afd Card_HypnoticSpecter_RandomDiscard
#define CardScript_TimeElemental Card_TimeElemental_BouncePermanent
#define CardScript_NorthernPaladin Card_NorthernPaladin_DestroyBlack
#define CardScript_RoyalAssassin Card_RoyalAssassin_DestroyTapped
#define CardScript_DwarvenDemolitionTeam Card_DwarvenDemolitionTeam_DestroyWall
#define CardScript_KingSuleiman Card_KingSuleiman_DestroyDjinn
#define FUN_004dae76 Card_Targeting_PromptCreature
#define CardScript_NettlingImp Card_NettlingImp_ForceAttack
#define FUN_004db401 Card_NettlingImp_CheckEndTurn
#define FUN_004db8c9 Card_NettlingImp_IsTargetEligible
#define CardScript_SorceressQueen Card_SorceressQueen_SetStats02
#define FUN_004dbfdb Card_SorceressQueen_ResetStats
#define CardScript_StoneGiant Card_StoneGiant_Fling
#define CardScript_DwarvenWarriors Card_DwarvenWarriors_MakeUnblockable
#define CardScript_CavePeople Card_CavePeople_Mountainwalk
#define CardScript_PradeshGypsies Card_PradeshGypsies_PreventAttack
#define FUN_004dd33b Card_PradeshGypsies_ResetRestriction
#define CardScript_SamiteHealer Card_SamiteHealer_PreventDamage
#define FUN_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define FUN_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define FUN_004dde51 Card_HealingSalve_DamagePrevention
#define FUN_004ddefa Card_DamagePrevention_ApplyBubble
#define FUN_004ddf4b Card_DamagePrevention_ReduceDamage
#define FUN_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define FUN_004de05f Card_DamagePrevention_QueryAmount
#define FUN_004de0b3 Card_DamagePrevention_PromptTarget
#define FUN_004de100 Card_DamagePrevention_CheckSource
#define CardScript_ErgRaiders Card_ErgRaiders_UpkeepDamage
#define FUN_004de35e Card_ErgRaiders_MarkAttack
#define FUN_004de492 Card_ErgRaiders_ClearTurnAttack
#define FUN_004de83d Card_Leviathan_SacrificeLands
#define CardScript_Leviathan Card_Leviathan_PromptLandSacrifice
#define FUN_004dee6b Card_Leviathan_SelectLand
#define FUN_004defc2 Card_Leviathan_AttackTrigger
#define CardScript_BrothersOfFire Card_BrothersOfFire_Ping
#define FUN_004df20c Card_BrothersOfFire_EvaluateTarget
#define CardScript_CrimsonManticore Card_CrimsonManticore_DamageTarget
#define CardScript_ProdigalSorcerer Card_ProdigalSorcerer_PingTarget
#define FUN_004df8ba Card_DirectDamage_EvaluateBestTarget
#define FUN_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define CardScript_PirateShip Card_PirateShip_PingTarget
#define FUN_004dfe94 Card_PirateShip_CheckIslandwalk
#define FUN_004dff88 Card_PirateShip_HasIsland
#define FUN_004e0037 Card_PirateShip_AttackTrigger
#define FUN_004e00e7 Card_IslandFishJasconius_PayToUntap
#define FUN_004e03b5 Card_IslandFishJasconius_CheckIslands
#define FUN_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define FUN_004e0580 Card_RodOfRuin_Ping
#define FUN_004e07b5 Card_RodOfRuin_EvaluateAi
#define FUN_004e08ac Card_RodOfRuin_PayActivation
#define FUN_004e095b Card_RodOfRuin_SelectTarget
#define CardScript_OrcishArtillery Card_OrcishArtillery_ShootTarget
#define CardScript_PsionicEntity Card_PsionicEntity_ShootTarget
#define FUN_004e0e60 Card_PsionicEntity_EvaluateTarget
#define FUN_004e0fd0 Card_PsionicEntity_SelfDamage
#define FUN_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define FUN_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define FUN_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define FUN_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define FUN_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define FUN_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define FUN_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define FUN_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define FUN_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define FUN_004e1fcb Card_ForceOfNature_PayUpkeep
#define FUN_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Card_BirdsOfParadise_TapForMana Card_BirdsOfParadise_TapForMana
#define FUN_004e268e Card_CosmicHorror_PayUpkeep
#define Card_LordOfThePit_SacrificeOrDamage Card_LordOfThePit_SacrificeOrDamage
#define FUN_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define FUN_004e2c7f Card_KormusBell_PayLandUpkeep
#define FUN_004e2fe8 Card_KormusBell_CheckSwampCreature
#define FUN_004e3128 Card_NetherShadow_CheckGraveyard
#define FUN_004e3185 Card_NetherShadow_CountCreaturesAbove
#define FUN_004e32f3 Card_NetherShadow_ReturnFromGrave
#define FUN_004e34e4 Card_RockHydra_DecrementHead
#define FUN_004e3563 Card_RockHydra_DamageTrigger
#define FUN_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define FUN_004e3730 Card_RockHydra_InitHeads
#define FUN_004e378b Card_RockHydra_RegrowHead
#define CardScript_Alibaba Card_AliBaba_TapWall
#define CardScript_LeyDruid Card_LeyDruid_UntapLand
#define FUN_004e4144 Card_LeyDruid_AiEvaluateLand
#define FUN_004e42ac Card_LeyDruid_ExecuteUntap
#define FUN_004e4508 Card_HurkylsRecall_PickArtifact
#define FUN_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define CardScript_Venom Card_Venom_DestroyCombatBlocker
#define FUN_004e4fae Card_Venom_AttachToCreature
#define FUN_004e538e Card_Venom_CombatDamageTrigger
#define FUN_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define FUN_004e580d Card_Venom_AiEvaluateAura
#define FUN_004e592c Card_Venom_AiCastScore
#define FUN_004e5a39 Card_Venom_ClearAuraFlags
#define CardScript_RadjanSpirit Card_RadjanSpirit_RemoveFlying
#define CardScript_HurrJackal Card_HurrJackal_GrantCombatAbility
#define FUN_004e654a CardQuery_PlayerControlsColor
#define FUN_004e65e1 CardQuery_ForEachPermanent
#define FUN_004e66b3 Card_IncrementCounter
#define FUN_004e676b Card_DecrementCounter
#define FUN_004e67e1 Card_AddCounters
#define FUN_004e689b Card_RemoveCounters
#define FUN_004e6913 Card_SetCounters
#define FUN_004e6978 Card_GetCounters
#define FUN_004e69ac CardTarget_PromptTargetCreature
#define FUN_004e6add CardTarget_SetTargetCreature
#define FUN_004e6bff CardTarget_HasValidCreatureTarget
#define FUN_004e6dcc CardTarget_PromptTargetPermanent
#define FUN_004e6efd CardTarget_SetTargetPermanent
#define FUN_004e701f CardTarget_HasValidPermanentTarget
#define FUN_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define FUN_004e71de CardTarget_SetTargetPlayerOrCreature
#define FUN_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Sprite_Load_Dbox Adventure_EnterTownLocation
#define FUN_004e7936 Adventure_PromptLocationMenu
#define FUN_004e7a6f Adventure_HandleLocationMenuChoice
#define FUN_004e7da1 Adventure_ExitTownLocation
#define Sound_Play_Bcastle_Loc Adventure_PlayLocationMusic
#define FUN_004e93df Adventure_UpdateWorldMapLoop
#define FUN_004ea7a6 Adventure_GetLocationEncounterIndex
#define FUN_004ea8df Adventure_SetLocationEncounterIndex
#define FUN_004ea97c Adventure_CheckMonsterEncounter
#define FUN_004eaa19 Adventure_FormatNewsString
#define FUN_004eaa9c Adventure_AppendNewsDetails
#define Sound_Play_Archmage Adventure_PlayMonsterEncounterSound
#define FUN_004ead33 Adventure_TriggerDuelFromEncounter
#define FUN_004ead96 Adventure_ReloadWorldPalette
#define Pic_Load_Advfac64_Face Adventure_LoadFacePalette
#define Sound_Play_Newsflash_Attack Adventure_NewsFlash_EnemyAttack
#define Sound_Play_Newsflash_Retaliate Adventure_NewsFlash_Retaliation
#define Sound_Play_Newsflash_Spell Adventure_NewsFlash_DominionSpell
#define FUN_004ebcdc Adventure_Audio_PlayEffect
#define FUN_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define FUN_004ebdca Adventure_Audio_PlayEffectLooped
#define FUN_004ebe1a Adventure_Audio_StopEffectChannel
#define FUN_004ebe61 Adventure_Audio_SetPlaybackPosition
#define FUN_004ebebf Adventure_Audio_StopAllTracks
#define Sound_Play_Bcastle_Victory Adventure_Audio_PlayCastleVictory
#define FUN_004ebfef Adventure_Audio_PlayDuelIntro
#define Sound_Play_Bbird1_Ambience Adventure_Audio_PlayTerrainAmbience
#define Sound_Play_Bbird1_Step Adventure_Audio_PlayFootstep
#define FUN_004ec439 Adventure_Audio_FindSoundOnDrives
#define Sound_Play_Locmus1 Adventure_Audio_GetMusicDrivePath
#define FUN_004ec572 Adventure_Audio_FreeSoundTrack
#define FUN_004ec5be Adventure_Audio_InitSoundTrack
#define FUN_004ec65a Adventure_Audio_GetTrackStatus
#define FUN_004ec6ea Adventure_Map_GetTerrainAtCoord
#define FUN_004ec7f9 Adventure_Map_RedrawViewport
#define Pic_Load_Advfac64_Map Adventure_Map_UpdateLightingAndPalette
#define Pic_Load_Arz Adventure_ShowDefeatScreen
#define UI_RegisterClass_004ecee0 Adventure_PromptConfirmDialog
#define FUN_004ecf94 Adventure_DestroyConfirmMenu
#define UI_WndProc_004ecfe5 Duel_MainArena_WndProc
#define FUN_004eed47 Duel_UpdateWindowScroll
#define FUN_004eee4e Duel_BringCardWindowToTop
#define FUN_004ef05f Duel_GetBattlefieldClientRect
#define FUN_004ef15b Duel_LayoutCardSlots
#define FUN_004ef64b Duel_ScrollLeftButton_Handler
#define FUN_004ef740 Duel_ScrollRightButton_Handler
#define FUN_004ef849 Duel_HitTestCardSlot
#define FUN_004ef970 Duel_GetHoveredCardSlot
#define FUN_004efa20 Duel_GetCardSlotWindowHandle
#define FUN_004efaba Duel_GetTargetSlotWindowHandle
#define UI_DialogProc_004efb3b Duel_PaintBattlefieldBackground
#define FUN_004efd50 Duel_LogActionStatusBanner
#define UI_RegisterClass_004f04e0 Duel_RegisterChildCardWindowClass
#define FUN_004f0597 Duel_UnregisterCardWindowClass
#define UI_WndProc_004f05c5 Duel_ChildCard_WndProc
#define FUN_004f09c0 Duel_GetCardDrawOriginX
#define FUN_004f0a4a Duel_GetCardDrawOriginY
#define FUN_004f0af6 Duel_TriggerCardDrawAnimation
#define FUN_004f0b50 Duel_UpdateCardMotionStep
#define FUN_004f0d90 Duel_ResetCardAnimationState
#define FUN_004f0de8 Bazaar_GetCardBaseValue
#define FUN_004f0e47 Bazaar_SellCardsDialog
#define FUN_004f15c0 Catalog_LoadWaveletCardArt
#define FUN_004f1910 Catalog_ReleaseWaveletLock
#define Glue_004cd63b Timer_InitVxD
#define Glue_004cd6e3 Timer_GetTicks
#define Glue_004cd715 Timer_MarkStart
#define Glue_004cd72a Timer_GetElapsedFraction
#define Glue_004cd760 SpellChain_RegisterClass
#define Glue_004cda01 SpellChain_CleanupUI
#define Glue_004cdb4f SpellChain_WndProc
#define Glue_004cf8b6 SpellChain_FindEntryIndex
#define Glue_004cf965 SpellChain_RemoveEntry
#define Glue_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_004cfb2f SpellChain_InsertEntry
#define Glue_004cfd68 SpellChain_ClearEntryTargets
#define Glue_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_004cffda SpellChain_UpdateLayout
#define Glue_004d05e8 SpellChain_GetContentRect
#define Glue_004d0602 SpellChain_MinimizedWndProc
#define Glue_004d0965 SpellChain_MinimizeIfShown
#define Glue_004d09bd SpellChain_RestoreIfMinimized
#define Glue_004d0a30 Card_DefaultEventHandler
#define Glue_004d0a42 Card_GetColorAndTypeFlags
#define Glue_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_004d1cc4 Card_Sinbad_Draw
#define Glue_004d1e10 Card_Kudzu_LandDestruction
#define Glue_004d212c Card_BronzeTablets_AnteSwap
#define Glue_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_004d30ae Card_Doppelganger_CheckState
#define Glue_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_004d3229 Card_IslandSanctuary_Trigger
#define Glue_004d328c Card_IslandSanctuary_CheckActive
#define Glue_004d332a Card_IslandSanctuary_Prompt
#define Glue_004d353d Card_LivingLands_AnimateForests
#define Glue_004d374d Card_KormusBell_AnimateSwamps
#define Glue_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_004d4d1f Card_AliFromCairo_ResetState
#define Glue_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_004d6391 Card_FrozenShade_ClearBoost
#define Glue_004d6400 Card_FrozenShade_PumpBlack
#define Glue_004d6706 Card_WaterElemental_PumpBlue
#define Glue_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_004d7065 Card_GaeasLiege_TransformLand
#define Glue_004d7724 Card_GaeasLiege_ResetLand
#define Glue_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_004d788d Card_GaeasLiege_IsForest
#define Glue_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_004d7bb5 Card_LivingWall_Regenerate
#define Glue_004d7c60 Card_GenericCreature_Regenerate
#define Glue_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_004d87cb Card_UthdenTroll_Regenerate
#define Glue_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_004dae76 Card_Targeting_PromptCreature
#define Glue_004db024 Card_NettlingImp_ForceAttack
#define Glue_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_004dba1c Card_SorceressQueen_SetStats02
#define Glue_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_004dc2ca Card_StoneGiant_Fling
#define Glue_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_004de05f Card_DamagePrevention_QueryAmount
#define Glue_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_004de100 Card_DamagePrevention_CheckSource
#define Glue_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_004de35e Card_ErgRaiders_MarkAttack
#define Glue_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_004de83d Card_Leviathan_SacrificeLands
#define Glue_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_004dee6b Card_Leviathan_SelectLand
#define Glue_004defc2 Card_Leviathan_AttackTrigger
#define Glue_004df04a Card_BrothersOfFire_Ping
#define Glue_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_004dfd39 Card_PirateShip_PingTarget
#define Glue_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_004dff88 Card_PirateShip_HasIsland
#define Glue_004e0037 Card_PirateShip_AttackTrigger
#define Glue_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_004e0580 Card_RodOfRuin_Ping
#define Glue_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_004e08ac Card_RodOfRuin_PayActivation
#define Glue_004e095b Card_RodOfRuin_SelectTarget
#define Glue_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_004e34e4 Card_RockHydra_DecrementHead
#define Glue_004e3563 Card_RockHydra_DamageTrigger
#define Glue_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_004e3730 Card_RockHydra_InitHeads
#define Glue_004e378b Card_RockHydra_RegrowHead
#define Glue_004e3b55 Card_AliBaba_TapWall
#define Glue_004e3e46 Card_LeyDruid_UntapLand
#define Glue_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_004e4fae Card_Venom_AttachToCreature
#define Glue_004e538e Card_Venom_CombatDamageTrigger
#define Glue_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_004e580d Card_Venom_AiEvaluateAura
#define Glue_004e592c Card_Venom_AiCastScore
#define Glue_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_004e654a CardQuery_PlayerControlsColor
#define Glue_004e65e1 CardQuery_ForEachPermanent
#define Glue_004e66b3 Card_IncrementCounter
#define Glue_004e676b Card_DecrementCounter
#define Glue_004e67e1 Card_AddCounters
#define Glue_004e689b Card_RemoveCounters
#define Glue_004e6913 Card_SetCounters
#define Glue_004e6978 Card_GetCounters
#define Glue_004e69ac CardTarget_PromptTargetCreature
#define Glue_004e6add CardTarget_SetTargetCreature
#define Glue_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_004e6efd CardTarget_SetTargetPermanent
#define Glue_004e701f CardTarget_HasValidPermanentTarget
#define Glue_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_004e73a0 Adventure_EnterTownLocation
#define Glue_004e7936 Adventure_PromptLocationMenu
#define Glue_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_004e7da1 Adventure_ExitTownLocation
#define Glue_004e7f51 Adventure_PlayLocationMusic
#define Glue_004e93df Adventure_UpdateWorldMapLoop
#define Glue_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_004ea97c Adventure_CheckMonsterEncounter
#define Glue_004eaa19 Adventure_FormatNewsString
#define Glue_004eaa9c Adventure_AppendNewsDetails
#define Glue_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_004ead96 Adventure_ReloadWorldPalette
#define Glue_004eadb7 Adventure_LoadFacePalette
#define Glue_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_004ebcdc Adventure_Audio_PlayEffect
#define Glue_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_004ebebf Adventure_Audio_StopAllTracks
#define Glue_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_004ec32f Adventure_Audio_PlayFootstep
#define Glue_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_004eccd7 Adventure_ShowDefeatScreen
#define Glue_004ecee0 Adventure_PromptConfirmDialog
#define Glue_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_004ecfe5 Duel_MainArena_WndProc
#define Glue_004eed47 Duel_UpdateWindowScroll
#define Glue_004eee4e Duel_BringCardWindowToTop
#define Glue_004ef05f Duel_GetBattlefieldClientRect
#define Glue_004ef15b Duel_LayoutCardSlots
#define Glue_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_004ef740 Duel_ScrollRightButton_Handler
#define Glue_004ef849 Duel_HitTestCardSlot
#define Glue_004ef970 Duel_GetHoveredCardSlot
#define Glue_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_004efb3b Duel_PaintBattlefieldBackground
#define Glue_004efd50 Duel_LogActionStatusBanner
#define Glue_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_004f0597 Duel_UnregisterCardWindowClass
#define Glue_004f05c5 Duel_ChildCard_WndProc
#define Glue_004f09c0 Duel_GetCardDrawOriginX
#define Glue_004f0a4a Duel_GetCardDrawOriginY
#define Glue_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_004f0b50 Duel_UpdateCardMotionStep
#define Glue_004f0d90 Duel_ResetCardAnimationState
#define Glue_004f0de8 Bazaar_GetCardBaseValue
#define Glue_004f0e47 Bazaar_SellCardsDialog
#define Glue_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_004f1910 Catalog_ReleaseWaveletLock
#define Glue_Render_004cd63b Timer_InitVxD
#define Glue_Render_004cd6e3 Timer_GetTicks
#define Glue_Render_004cd715 Timer_MarkStart
#define Glue_Render_004cd72a Timer_GetElapsedFraction
#define Glue_Render_004cd760 SpellChain_RegisterClass
#define Glue_Render_004cda01 SpellChain_CleanupUI
#define Glue_Render_004cdb4f SpellChain_WndProc
#define Glue_Render_004cf8b6 SpellChain_FindEntryIndex
#define Glue_Render_004cf965 SpellChain_RemoveEntry
#define Glue_Render_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_Render_004cfb2f SpellChain_InsertEntry
#define Glue_Render_004cfd68 SpellChain_ClearEntryTargets
#define Glue_Render_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_Render_004cffda SpellChain_UpdateLayout
#define Glue_Render_004d05e8 SpellChain_GetContentRect
#define Glue_Render_004d0602 SpellChain_MinimizedWndProc
#define Glue_Render_004d0965 SpellChain_MinimizeIfShown
#define Glue_Render_004d09bd SpellChain_RestoreIfMinimized
#define Glue_Render_004d0a30 Card_DefaultEventHandler
#define Glue_Render_004d0a42 Card_GetColorAndTypeFlags
#define Glue_Render_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_Render_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_Render_004d1cc4 Card_Sinbad_Draw
#define Glue_Render_004d1e10 Card_Kudzu_LandDestruction
#define Glue_Render_004d212c Card_BronzeTablets_AnteSwap
#define Glue_Render_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_Render_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_Render_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_Render_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_Render_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_Render_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_Render_004d30ae Card_Doppelganger_CheckState
#define Glue_Render_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_Render_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_Render_004d3229 Card_IslandSanctuary_Trigger
#define Glue_Render_004d328c Card_IslandSanctuary_CheckActive
#define Glue_Render_004d332a Card_IslandSanctuary_Prompt
#define Glue_Render_004d353d Card_LivingLands_AnimateForests
#define Glue_Render_004d374d Card_KormusBell_AnimateSwamps
#define Glue_Render_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_Render_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_Render_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_Render_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_Render_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_Render_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_Render_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_Render_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_Render_004d4d1f Card_AliFromCairo_ResetState
#define Glue_Render_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_Render_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_Render_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_Render_004d6391 Card_FrozenShade_ClearBoost
#define Glue_Render_004d6400 Card_FrozenShade_PumpBlack
#define Glue_Render_004d6706 Card_WaterElemental_PumpBlue
#define Glue_Render_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_Render_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_Render_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_Render_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_Render_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_Render_004d7065 Card_GaeasLiege_TransformLand
#define Glue_Render_004d7724 Card_GaeasLiege_ResetLand
#define Glue_Render_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_Render_004d788d Card_GaeasLiege_IsForest
#define Glue_Render_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_Render_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_Render_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_Render_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_Render_004d7bb5 Card_LivingWall_Regenerate
#define Glue_Render_004d7c60 Card_GenericCreature_Regenerate
#define Glue_Render_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_Render_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_Render_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_Render_004d87cb Card_UthdenTroll_Regenerate
#define Glue_Render_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_Render_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_Render_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_Render_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_Render_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_Render_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_Render_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_Render_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_Render_004dae76 Card_Targeting_PromptCreature
#define Glue_Render_004db024 Card_NettlingImp_ForceAttack
#define Glue_Render_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_Render_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_Render_004dba1c Card_SorceressQueen_SetStats02
#define Glue_Render_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_Render_004dc2ca Card_StoneGiant_Fling
#define Glue_Render_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_Render_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_Render_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_Render_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_Render_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_Render_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_Render_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_Render_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_Render_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_Render_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_Render_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_Render_004de05f Card_DamagePrevention_QueryAmount
#define Glue_Render_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_Render_004de100 Card_DamagePrevention_CheckSource
#define Glue_Render_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_Render_004de35e Card_ErgRaiders_MarkAttack
#define Glue_Render_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_Render_004de83d Card_Leviathan_SacrificeLands
#define Glue_Render_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_Render_004dee6b Card_Leviathan_SelectLand
#define Glue_Render_004defc2 Card_Leviathan_AttackTrigger
#define Glue_Render_004df04a Card_BrothersOfFire_Ping
#define Glue_Render_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_Render_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_Render_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_Render_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_Render_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_Render_004dfd39 Card_PirateShip_PingTarget
#define Glue_Render_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_Render_004dff88 Card_PirateShip_HasIsland
#define Glue_Render_004e0037 Card_PirateShip_AttackTrigger
#define Glue_Render_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_Render_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_Render_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_Render_004e0580 Card_RodOfRuin_Ping
#define Glue_Render_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_Render_004e08ac Card_RodOfRuin_PayActivation
#define Glue_Render_004e095b Card_RodOfRuin_SelectTarget
#define Glue_Render_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_Render_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_Render_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_Render_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_Render_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_Render_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_Render_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_Render_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_Render_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_Render_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_Render_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_Render_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_Render_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_Render_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_Render_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_Render_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_Render_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_Render_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_Render_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_Render_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_Render_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_Render_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_Render_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_Render_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_Render_004e34e4 Card_RockHydra_DecrementHead
#define Glue_Render_004e3563 Card_RockHydra_DamageTrigger
#define Glue_Render_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_Render_004e3730 Card_RockHydra_InitHeads
#define Glue_Render_004e378b Card_RockHydra_RegrowHead
#define Glue_Render_004e3b55 Card_AliBaba_TapWall
#define Glue_Render_004e3e46 Card_LeyDruid_UntapLand
#define Glue_Render_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_Render_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_Render_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_Render_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_Render_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_Render_004e4fae Card_Venom_AttachToCreature
#define Glue_Render_004e538e Card_Venom_CombatDamageTrigger
#define Glue_Render_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_Render_004e580d Card_Venom_AiEvaluateAura
#define Glue_Render_004e592c Card_Venom_AiCastScore
#define Glue_Render_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_Render_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_Render_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_Render_004e654a CardQuery_PlayerControlsColor
#define Glue_Render_004e65e1 CardQuery_ForEachPermanent
#define Glue_Render_004e66b3 Card_IncrementCounter
#define Glue_Render_004e676b Card_DecrementCounter
#define Glue_Render_004e67e1 Card_AddCounters
#define Glue_Render_004e689b Card_RemoveCounters
#define Glue_Render_004e6913 Card_SetCounters
#define Glue_Render_004e6978 Card_GetCounters
#define Glue_Render_004e69ac CardTarget_PromptTargetCreature
#define Glue_Render_004e6add CardTarget_SetTargetCreature
#define Glue_Render_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_Render_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_Render_004e6efd CardTarget_SetTargetPermanent
#define Glue_Render_004e701f CardTarget_HasValidPermanentTarget
#define Glue_Render_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_Render_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_Render_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_Render_004e73a0 Adventure_EnterTownLocation
#define Glue_Render_004e7936 Adventure_PromptLocationMenu
#define Glue_Render_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_Render_004e7da1 Adventure_ExitTownLocation
#define Glue_Render_004e7f51 Adventure_PlayLocationMusic
#define Glue_Render_004e93df Adventure_UpdateWorldMapLoop
#define Glue_Render_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_Render_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_Render_004ea97c Adventure_CheckMonsterEncounter
#define Glue_Render_004eaa19 Adventure_FormatNewsString
#define Glue_Render_004eaa9c Adventure_AppendNewsDetails
#define Glue_Render_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_Render_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_Render_004ead96 Adventure_ReloadWorldPalette
#define Glue_Render_004eadb7 Adventure_LoadFacePalette
#define Glue_Render_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_Render_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_Render_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_Render_004ebcdc Adventure_Audio_PlayEffect
#define Glue_Render_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_Render_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_Render_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_Render_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_Render_004ebebf Adventure_Audio_StopAllTracks
#define Glue_Render_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_Render_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_Render_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_Render_004ec32f Adventure_Audio_PlayFootstep
#define Glue_Render_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_Render_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_Render_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_Render_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_Render_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_Render_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_Render_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_Render_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_Render_004eccd7 Adventure_ShowDefeatScreen
#define Glue_Render_004ecee0 Adventure_PromptConfirmDialog
#define Glue_Render_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_Render_004ecfe5 Duel_MainArena_WndProc
#define Glue_Render_004eed47 Duel_UpdateWindowScroll
#define Glue_Render_004eee4e Duel_BringCardWindowToTop
#define Glue_Render_004ef05f Duel_GetBattlefieldClientRect
#define Glue_Render_004ef15b Duel_LayoutCardSlots
#define Glue_Render_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_Render_004ef740 Duel_ScrollRightButton_Handler
#define Glue_Render_004ef849 Duel_HitTestCardSlot
#define Glue_Render_004ef970 Duel_GetHoveredCardSlot
#define Glue_Render_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_Render_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_Render_004efb3b Duel_PaintBattlefieldBackground
#define Glue_Render_004efd50 Duel_LogActionStatusBanner
#define Glue_Render_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_Render_004f0597 Duel_UnregisterCardWindowClass
#define Glue_Render_004f05c5 Duel_ChildCard_WndProc
#define Glue_Render_004f09c0 Duel_GetCardDrawOriginX
#define Glue_Render_004f0a4a Duel_GetCardDrawOriginY
#define Glue_Render_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_Render_004f0b50 Duel_UpdateCardMotionStep
#define Glue_Render_004f0d90 Duel_ResetCardAnimationState
#define Glue_Render_004f0de8 Bazaar_GetCardBaseValue
#define Glue_Render_004f0e47 Bazaar_SellCardsDialog
#define Glue_Render_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_Render_004f1910 Catalog_ReleaseWaveletLock
#define Glue_Sound_004cd63b Timer_InitVxD
#define Glue_Sound_004cd6e3 Timer_GetTicks
#define Glue_Sound_004cd715 Timer_MarkStart
#define Glue_Sound_004cd72a Timer_GetElapsedFraction
#define Glue_Sound_004cd760 SpellChain_RegisterClass
#define Glue_Sound_004cda01 SpellChain_CleanupUI
#define Glue_Sound_004cdb4f SpellChain_WndProc
#define Glue_Sound_004cf8b6 SpellChain_FindEntryIndex
#define Glue_Sound_004cf965 SpellChain_RemoveEntry
#define Glue_Sound_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_Sound_004cfb2f SpellChain_InsertEntry
#define Glue_Sound_004cfd68 SpellChain_ClearEntryTargets
#define Glue_Sound_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_Sound_004cffda SpellChain_UpdateLayout
#define Glue_Sound_004d05e8 SpellChain_GetContentRect
#define Glue_Sound_004d0602 SpellChain_MinimizedWndProc
#define Glue_Sound_004d0965 SpellChain_MinimizeIfShown
#define Glue_Sound_004d09bd SpellChain_RestoreIfMinimized
#define Glue_Sound_004d0a30 Card_DefaultEventHandler
#define Glue_Sound_004d0a42 Card_GetColorAndTypeFlags
#define Glue_Sound_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_Sound_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_Sound_004d1cc4 Card_Sinbad_Draw
#define Glue_Sound_004d1e10 Card_Kudzu_LandDestruction
#define Glue_Sound_004d212c Card_BronzeTablets_AnteSwap
#define Glue_Sound_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_Sound_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_Sound_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_Sound_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_Sound_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_Sound_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_Sound_004d30ae Card_Doppelganger_CheckState
#define Glue_Sound_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_Sound_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_Sound_004d3229 Card_IslandSanctuary_Trigger
#define Glue_Sound_004d328c Card_IslandSanctuary_CheckActive
#define Glue_Sound_004d332a Card_IslandSanctuary_Prompt
#define Glue_Sound_004d353d Card_LivingLands_AnimateForests
#define Glue_Sound_004d374d Card_KormusBell_AnimateSwamps
#define Glue_Sound_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_Sound_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_Sound_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_Sound_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_Sound_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_Sound_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_Sound_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_Sound_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_Sound_004d4d1f Card_AliFromCairo_ResetState
#define Glue_Sound_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_Sound_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_Sound_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_Sound_004d6391 Card_FrozenShade_ClearBoost
#define Glue_Sound_004d6400 Card_FrozenShade_PumpBlack
#define Glue_Sound_004d6706 Card_WaterElemental_PumpBlue
#define Glue_Sound_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_Sound_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_Sound_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_Sound_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_Sound_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_Sound_004d7065 Card_GaeasLiege_TransformLand
#define Glue_Sound_004d7724 Card_GaeasLiege_ResetLand
#define Glue_Sound_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_Sound_004d788d Card_GaeasLiege_IsForest
#define Glue_Sound_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_Sound_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_Sound_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_Sound_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_Sound_004d7bb5 Card_LivingWall_Regenerate
#define Glue_Sound_004d7c60 Card_GenericCreature_Regenerate
#define Glue_Sound_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_Sound_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_Sound_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_Sound_004d87cb Card_UthdenTroll_Regenerate
#define Glue_Sound_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_Sound_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_Sound_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_Sound_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_Sound_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_Sound_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_Sound_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_Sound_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_Sound_004dae76 Card_Targeting_PromptCreature
#define Glue_Sound_004db024 Card_NettlingImp_ForceAttack
#define Glue_Sound_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_Sound_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_Sound_004dba1c Card_SorceressQueen_SetStats02
#define Glue_Sound_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_Sound_004dc2ca Card_StoneGiant_Fling
#define Glue_Sound_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_Sound_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_Sound_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_Sound_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_Sound_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_Sound_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_Sound_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_Sound_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_Sound_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_Sound_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_Sound_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_Sound_004de05f Card_DamagePrevention_QueryAmount
#define Glue_Sound_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_Sound_004de100 Card_DamagePrevention_CheckSource
#define Glue_Sound_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_Sound_004de35e Card_ErgRaiders_MarkAttack
#define Glue_Sound_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_Sound_004de83d Card_Leviathan_SacrificeLands
#define Glue_Sound_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_Sound_004dee6b Card_Leviathan_SelectLand
#define Glue_Sound_004defc2 Card_Leviathan_AttackTrigger
#define Glue_Sound_004df04a Card_BrothersOfFire_Ping
#define Glue_Sound_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_Sound_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_Sound_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_Sound_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_Sound_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_Sound_004dfd39 Card_PirateShip_PingTarget
#define Glue_Sound_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_Sound_004dff88 Card_PirateShip_HasIsland
#define Glue_Sound_004e0037 Card_PirateShip_AttackTrigger
#define Glue_Sound_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_Sound_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_Sound_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_Sound_004e0580 Card_RodOfRuin_Ping
#define Glue_Sound_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_Sound_004e08ac Card_RodOfRuin_PayActivation
#define Glue_Sound_004e095b Card_RodOfRuin_SelectTarget
#define Glue_Sound_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_Sound_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_Sound_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_Sound_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_Sound_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_Sound_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_Sound_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_Sound_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_Sound_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_Sound_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_Sound_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_Sound_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_Sound_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_Sound_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_Sound_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_Sound_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_Sound_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_Sound_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_Sound_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_Sound_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_Sound_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_Sound_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_Sound_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_Sound_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_Sound_004e34e4 Card_RockHydra_DecrementHead
#define Glue_Sound_004e3563 Card_RockHydra_DamageTrigger
#define Glue_Sound_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_Sound_004e3730 Card_RockHydra_InitHeads
#define Glue_Sound_004e378b Card_RockHydra_RegrowHead
#define Glue_Sound_004e3b55 Card_AliBaba_TapWall
#define Glue_Sound_004e3e46 Card_LeyDruid_UntapLand
#define Glue_Sound_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_Sound_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_Sound_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_Sound_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_Sound_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_Sound_004e4fae Card_Venom_AttachToCreature
#define Glue_Sound_004e538e Card_Venom_CombatDamageTrigger
#define Glue_Sound_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_Sound_004e580d Card_Venom_AiEvaluateAura
#define Glue_Sound_004e592c Card_Venom_AiCastScore
#define Glue_Sound_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_Sound_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_Sound_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_Sound_004e654a CardQuery_PlayerControlsColor
#define Glue_Sound_004e65e1 CardQuery_ForEachPermanent
#define Glue_Sound_004e66b3 Card_IncrementCounter
#define Glue_Sound_004e676b Card_DecrementCounter
#define Glue_Sound_004e67e1 Card_AddCounters
#define Glue_Sound_004e689b Card_RemoveCounters
#define Glue_Sound_004e6913 Card_SetCounters
#define Glue_Sound_004e6978 Card_GetCounters
#define Glue_Sound_004e69ac CardTarget_PromptTargetCreature
#define Glue_Sound_004e6add CardTarget_SetTargetCreature
#define Glue_Sound_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_Sound_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_Sound_004e6efd CardTarget_SetTargetPermanent
#define Glue_Sound_004e701f CardTarget_HasValidPermanentTarget
#define Glue_Sound_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_Sound_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_Sound_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_Sound_004e73a0 Adventure_EnterTownLocation
#define Glue_Sound_004e7936 Adventure_PromptLocationMenu
#define Glue_Sound_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_Sound_004e7da1 Adventure_ExitTownLocation
#define Glue_Sound_004e7f51 Adventure_PlayLocationMusic
#define Glue_Sound_004e93df Adventure_UpdateWorldMapLoop
#define Glue_Sound_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_Sound_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_Sound_004ea97c Adventure_CheckMonsterEncounter
#define Glue_Sound_004eaa19 Adventure_FormatNewsString
#define Glue_Sound_004eaa9c Adventure_AppendNewsDetails
#define Glue_Sound_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_Sound_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_Sound_004ead96 Adventure_ReloadWorldPalette
#define Glue_Sound_004eadb7 Adventure_LoadFacePalette
#define Glue_Sound_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_Sound_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_Sound_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_Sound_004ebcdc Adventure_Audio_PlayEffect
#define Glue_Sound_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_Sound_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_Sound_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_Sound_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_Sound_004ebebf Adventure_Audio_StopAllTracks
#define Glue_Sound_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_Sound_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_Sound_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_Sound_004ec32f Adventure_Audio_PlayFootstep
#define Glue_Sound_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_Sound_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_Sound_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_Sound_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_Sound_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_Sound_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_Sound_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_Sound_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_Sound_004eccd7 Adventure_ShowDefeatScreen
#define Glue_Sound_004ecee0 Adventure_PromptConfirmDialog
#define Glue_Sound_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_Sound_004ecfe5 Duel_MainArena_WndProc
#define Glue_Sound_004eed47 Duel_UpdateWindowScroll
#define Glue_Sound_004eee4e Duel_BringCardWindowToTop
#define Glue_Sound_004ef05f Duel_GetBattlefieldClientRect
#define Glue_Sound_004ef15b Duel_LayoutCardSlots
#define Glue_Sound_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_Sound_004ef740 Duel_ScrollRightButton_Handler
#define Glue_Sound_004ef849 Duel_HitTestCardSlot
#define Glue_Sound_004ef970 Duel_GetHoveredCardSlot
#define Glue_Sound_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_Sound_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_Sound_004efb3b Duel_PaintBattlefieldBackground
#define Glue_Sound_004efd50 Duel_LogActionStatusBanner
#define Glue_Sound_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_Sound_004f0597 Duel_UnregisterCardWindowClass
#define Glue_Sound_004f05c5 Duel_ChildCard_WndProc
#define Glue_Sound_004f09c0 Duel_GetCardDrawOriginX
#define Glue_Sound_004f0a4a Duel_GetCardDrawOriginY
#define Glue_Sound_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_Sound_004f0b50 Duel_UpdateCardMotionStep
#define Glue_Sound_004f0d90 Duel_ResetCardAnimationState
#define Glue_Sound_004f0de8 Bazaar_GetCardBaseValue
#define Glue_Sound_004f0e47 Bazaar_SellCardsDialog
#define Glue_Sound_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_Sound_004f1910 Catalog_ReleaseWaveletLock
#define Glue_Subsystem_004cd63b Timer_InitVxD
#define Glue_Subsystem_004cd6e3 Timer_GetTicks
#define Glue_Subsystem_004cd715 Timer_MarkStart
#define Glue_Subsystem_004cd72a Timer_GetElapsedFraction
#define SpellChain_RegisterClass SpellChain_RegisterClass
#define Glue_Subsystem_004cda01 SpellChain_CleanupUI
#define SpellChain_WndProc SpellChain_WndProc
#define Glue_Subsystem_004cf8b6 SpellChain_FindEntryIndex
#define Glue_Subsystem_004cf965 SpellChain_RemoveEntry
#define Glue_Subsystem_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_Subsystem_004cfb2f SpellChain_InsertEntry
#define Glue_Subsystem_004cfd68 SpellChain_ClearEntryTargets
#define Glue_Subsystem_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_Subsystem_004cffda SpellChain_UpdateLayout
#define Glue_Subsystem_004d05e8 SpellChain_GetContentRect
#define SpellChain_MinimizedWndProc SpellChain_MinimizedWndProc
#define Glue_Subsystem_004d0965 SpellChain_MinimizeIfShown
#define Glue_Subsystem_004d09bd SpellChain_RestoreIfMinimized
#define Glue_Subsystem_004d0a30 Card_DefaultEventHandler
#define Glue_Subsystem_004d0a42 Card_GetColorAndTypeFlags
#define Glue_Subsystem_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_Subsystem_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_Subsystem_004d1cc4 Card_Sinbad_Draw
#define Glue_Subsystem_004d1e10 Card_Kudzu_LandDestruction
#define Glue_Subsystem_004d212c Card_BronzeTablets_AnteSwap
#define Glue_Subsystem_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_Subsystem_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_Subsystem_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_Subsystem_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_Subsystem_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_Subsystem_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_Subsystem_004d30ae Card_Doppelganger_CheckState
#define Glue_Subsystem_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_Subsystem_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_Subsystem_004d3229 Card_IslandSanctuary_Trigger
#define Glue_Subsystem_004d328c Card_IslandSanctuary_CheckActive
#define Glue_Subsystem_004d332a Card_IslandSanctuary_Prompt
#define Glue_Subsystem_004d353d Card_LivingLands_AnimateForests
#define Glue_Subsystem_004d374d Card_KormusBell_AnimateSwamps
#define Glue_Subsystem_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_Subsystem_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_Subsystem_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_Subsystem_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_Subsystem_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_Subsystem_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_Subsystem_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_Subsystem_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_Subsystem_004d4d1f Card_AliFromCairo_ResetState
#define Glue_Subsystem_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_Subsystem_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_Subsystem_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_Subsystem_004d6391 Card_FrozenShade_ClearBoost
#define Glue_Subsystem_004d6400 Card_FrozenShade_PumpBlack
#define Glue_Subsystem_004d6706 Card_WaterElemental_PumpBlue
#define Glue_Subsystem_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_Subsystem_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_Subsystem_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_Subsystem_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_Subsystem_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_Subsystem_004d7065 Card_GaeasLiege_TransformLand
#define Glue_Subsystem_004d7724 Card_GaeasLiege_ResetLand
#define Glue_Subsystem_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_Subsystem_004d788d Card_GaeasLiege_IsForest
#define Glue_Subsystem_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_Subsystem_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_Subsystem_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_Subsystem_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_Subsystem_004d7bb5 Card_LivingWall_Regenerate
#define Glue_Subsystem_004d7c60 Card_GenericCreature_Regenerate
#define Glue_Subsystem_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_Subsystem_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_Subsystem_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_Subsystem_004d87cb Card_UthdenTroll_Regenerate
#define Glue_Subsystem_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_Subsystem_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_Subsystem_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_Subsystem_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_Subsystem_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_Subsystem_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_Subsystem_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_Subsystem_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_Subsystem_004dae76 Card_Targeting_PromptCreature
#define Glue_Subsystem_004db024 Card_NettlingImp_ForceAttack
#define Glue_Subsystem_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_Subsystem_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_Subsystem_004dba1c Card_SorceressQueen_SetStats02
#define Glue_Subsystem_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_Subsystem_004dc2ca Card_StoneGiant_Fling
#define Glue_Subsystem_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_Subsystem_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_Subsystem_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_Subsystem_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_Subsystem_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_Subsystem_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_Subsystem_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_Subsystem_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_Subsystem_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_Subsystem_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_Subsystem_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_Subsystem_004de05f Card_DamagePrevention_QueryAmount
#define Glue_Subsystem_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_Subsystem_004de100 Card_DamagePrevention_CheckSource
#define Glue_Subsystem_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_Subsystem_004de35e Card_ErgRaiders_MarkAttack
#define Glue_Subsystem_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_Subsystem_004de83d Card_Leviathan_SacrificeLands
#define Glue_Subsystem_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_Subsystem_004dee6b Card_Leviathan_SelectLand
#define Glue_Subsystem_004defc2 Card_Leviathan_AttackTrigger
#define Glue_Subsystem_004df04a Card_BrothersOfFire_Ping
#define Glue_Subsystem_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_Subsystem_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_Subsystem_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_Subsystem_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_Subsystem_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_Subsystem_004dfd39 Card_PirateShip_PingTarget
#define Glue_Subsystem_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_Subsystem_004dff88 Card_PirateShip_HasIsland
#define Glue_Subsystem_004e0037 Card_PirateShip_AttackTrigger
#define Glue_Subsystem_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_Subsystem_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_Subsystem_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_Subsystem_004e0580 Card_RodOfRuin_Ping
#define Glue_Subsystem_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_Subsystem_004e08ac Card_RodOfRuin_PayActivation
#define Glue_Subsystem_004e095b Card_RodOfRuin_SelectTarget
#define Glue_Subsystem_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_Subsystem_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_Subsystem_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_Subsystem_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_Subsystem_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_Subsystem_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_Subsystem_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_Subsystem_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_Subsystem_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_Subsystem_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_Subsystem_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_Subsystem_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_Subsystem_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_Subsystem_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_Subsystem_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_Subsystem_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_Subsystem_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_Subsystem_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_Subsystem_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_Subsystem_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_Subsystem_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_Subsystem_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_Subsystem_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_Subsystem_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_Subsystem_004e34e4 Card_RockHydra_DecrementHead
#define Glue_Subsystem_004e3563 Card_RockHydra_DamageTrigger
#define Glue_Subsystem_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_Subsystem_004e3730 Card_RockHydra_InitHeads
#define Glue_Subsystem_004e378b Card_RockHydra_RegrowHead
#define Glue_Subsystem_004e3b55 Card_AliBaba_TapWall
#define Glue_Subsystem_004e3e46 Card_LeyDruid_UntapLand
#define Glue_Subsystem_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_Subsystem_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_Subsystem_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_Subsystem_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_Subsystem_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_Subsystem_004e4fae Card_Venom_AttachToCreature
#define Glue_Subsystem_004e538e Card_Venom_CombatDamageTrigger
#define Glue_Subsystem_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_Subsystem_004e580d Card_Venom_AiEvaluateAura
#define Glue_Subsystem_004e592c Card_Venom_AiCastScore
#define Glue_Subsystem_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_Subsystem_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_Subsystem_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_Subsystem_004e654a CardQuery_PlayerControlsColor
#define Glue_Subsystem_004e65e1 CardQuery_ForEachPermanent
#define Glue_Subsystem_004e66b3 Card_IncrementCounter
#define Glue_Subsystem_004e676b Card_DecrementCounter
#define Glue_Subsystem_004e67e1 Card_AddCounters
#define Glue_Subsystem_004e689b Card_RemoveCounters
#define Glue_Subsystem_004e6913 Card_SetCounters
#define Glue_Subsystem_004e6978 Card_GetCounters
#define Glue_Subsystem_004e69ac CardTarget_PromptTargetCreature
#define Glue_Subsystem_004e6add CardTarget_SetTargetCreature
#define Glue_Subsystem_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_Subsystem_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_Subsystem_004e6efd CardTarget_SetTargetPermanent
#define Glue_Subsystem_004e701f CardTarget_HasValidPermanentTarget
#define Glue_Subsystem_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_Subsystem_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_Subsystem_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_Subsystem_004e73a0 Adventure_EnterTownLocation
#define Glue_Subsystem_004e7936 Adventure_PromptLocationMenu
#define Glue_Subsystem_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_Subsystem_004e7da1 Adventure_ExitTownLocation
#define Glue_Subsystem_004e7f51 Adventure_PlayLocationMusic
#define Glue_Subsystem_004e93df Adventure_UpdateWorldMapLoop
#define Glue_Subsystem_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_Subsystem_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_Subsystem_004ea97c Adventure_CheckMonsterEncounter
#define Glue_Subsystem_004eaa19 Adventure_FormatNewsString
#define Glue_Subsystem_004eaa9c Adventure_AppendNewsDetails
#define Glue_Subsystem_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_Subsystem_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_Subsystem_004ead96 Adventure_ReloadWorldPalette
#define Glue_Subsystem_004eadb7 Adventure_LoadFacePalette
#define Glue_Subsystem_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_Subsystem_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_Subsystem_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_Subsystem_004ebcdc Adventure_Audio_PlayEffect
#define Glue_Subsystem_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_Subsystem_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_Subsystem_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_Subsystem_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_Subsystem_004ebebf Adventure_Audio_StopAllTracks
#define Glue_Subsystem_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_Subsystem_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_Subsystem_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_Subsystem_004ec32f Adventure_Audio_PlayFootstep
#define Glue_Subsystem_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_Subsystem_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_Subsystem_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_Subsystem_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_Subsystem_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_Subsystem_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_Subsystem_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_Subsystem_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_Subsystem_004eccd7 Adventure_ShowDefeatScreen
#define Glue_Subsystem_004ecee0 Adventure_PromptConfirmDialog
#define Glue_Subsystem_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_Subsystem_004ecfe5 Duel_MainArena_WndProc
#define Glue_Subsystem_004eed47 Duel_UpdateWindowScroll
#define Glue_Subsystem_004eee4e Duel_BringCardWindowToTop
#define Glue_Subsystem_004ef05f Duel_GetBattlefieldClientRect
#define Glue_Subsystem_004ef15b Duel_LayoutCardSlots
#define Glue_Subsystem_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_Subsystem_004ef740 Duel_ScrollRightButton_Handler
#define Glue_Subsystem_004ef849 Duel_HitTestCardSlot
#define Glue_Subsystem_004ef970 Duel_GetHoveredCardSlot
#define Glue_Subsystem_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_Subsystem_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_Subsystem_004efb3b Duel_PaintBattlefieldBackground
#define Glue_Subsystem_004efd50 Duel_LogActionStatusBanner
#define Glue_Subsystem_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_Subsystem_004f0597 Duel_UnregisterCardWindowClass
#define Glue_Subsystem_004f05c5 Duel_ChildCard_WndProc
#define Glue_Subsystem_004f09c0 Duel_GetCardDrawOriginX
#define Glue_Subsystem_004f0a4a Duel_GetCardDrawOriginY
#define Glue_Subsystem_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_Subsystem_004f0b50 Duel_UpdateCardMotionStep
#define Glue_Subsystem_004f0d90 Duel_ResetCardAnimationState
#define Glue_Subsystem_004f0de8 Bazaar_GetCardBaseValue
#define Glue_Subsystem_004f0e47 Bazaar_SellCardsDialog
#define Glue_Subsystem_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_Subsystem_004f1910 Catalog_ReleaseWaveletLock
#define Glue_Timer_004cd63b Timer_InitVxD
#define Glue_Timer_004cd6e3 Timer_GetTicks
#define Glue_Timer_004cd715 Timer_MarkStart
#define Glue_Timer_004cd72a Timer_GetElapsedFraction
#define Glue_Timer_004cd760 SpellChain_RegisterClass
#define Glue_Timer_004cda01 SpellChain_CleanupUI
#define Glue_Timer_004cdb4f SpellChain_WndProc
#define Glue_Timer_004cf8b6 SpellChain_FindEntryIndex
#define Glue_Timer_004cf965 SpellChain_RemoveEntry
#define Glue_Timer_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_Timer_004cfb2f SpellChain_InsertEntry
#define Glue_Timer_004cfd68 SpellChain_ClearEntryTargets
#define Glue_Timer_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_Timer_004cffda SpellChain_UpdateLayout
#define Glue_Timer_004d05e8 SpellChain_GetContentRect
#define Glue_Timer_004d0602 SpellChain_MinimizedWndProc
#define Glue_Timer_004d0965 SpellChain_MinimizeIfShown
#define Glue_Timer_004d09bd SpellChain_RestoreIfMinimized
#define Glue_Timer_004d0a30 Card_DefaultEventHandler
#define Glue_Timer_004d0a42 Card_GetColorAndTypeFlags
#define Glue_Timer_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_Timer_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_Timer_004d1cc4 Card_Sinbad_Draw
#define Glue_Timer_004d1e10 Card_Kudzu_LandDestruction
#define Glue_Timer_004d212c Card_BronzeTablets_AnteSwap
#define Glue_Timer_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_Timer_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_Timer_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_Timer_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_Timer_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_Timer_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_Timer_004d30ae Card_Doppelganger_CheckState
#define Glue_Timer_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_Timer_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_Timer_004d3229 Card_IslandSanctuary_Trigger
#define Glue_Timer_004d328c Card_IslandSanctuary_CheckActive
#define Glue_Timer_004d332a Card_IslandSanctuary_Prompt
#define Glue_Timer_004d353d Card_LivingLands_AnimateForests
#define Glue_Timer_004d374d Card_KormusBell_AnimateSwamps
#define Glue_Timer_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_Timer_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_Timer_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_Timer_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_Timer_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_Timer_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_Timer_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_Timer_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_Timer_004d4d1f Card_AliFromCairo_ResetState
#define Glue_Timer_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_Timer_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_Timer_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_Timer_004d6391 Card_FrozenShade_ClearBoost
#define Glue_Timer_004d6400 Card_FrozenShade_PumpBlack
#define Glue_Timer_004d6706 Card_WaterElemental_PumpBlue
#define Glue_Timer_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_Timer_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_Timer_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_Timer_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_Timer_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_Timer_004d7065 Card_GaeasLiege_TransformLand
#define Glue_Timer_004d7724 Card_GaeasLiege_ResetLand
#define Glue_Timer_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_Timer_004d788d Card_GaeasLiege_IsForest
#define Glue_Timer_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_Timer_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_Timer_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_Timer_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_Timer_004d7bb5 Card_LivingWall_Regenerate
#define Glue_Timer_004d7c60 Card_GenericCreature_Regenerate
#define Glue_Timer_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_Timer_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_Timer_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_Timer_004d87cb Card_UthdenTroll_Regenerate
#define Glue_Timer_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_Timer_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_Timer_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_Timer_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_Timer_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_Timer_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_Timer_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_Timer_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_Timer_004dae76 Card_Targeting_PromptCreature
#define Glue_Timer_004db024 Card_NettlingImp_ForceAttack
#define Glue_Timer_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_Timer_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_Timer_004dba1c Card_SorceressQueen_SetStats02
#define Glue_Timer_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_Timer_004dc2ca Card_StoneGiant_Fling
#define Glue_Timer_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_Timer_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_Timer_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_Timer_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_Timer_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_Timer_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_Timer_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_Timer_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_Timer_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_Timer_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_Timer_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_Timer_004de05f Card_DamagePrevention_QueryAmount
#define Glue_Timer_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_Timer_004de100 Card_DamagePrevention_CheckSource
#define Glue_Timer_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_Timer_004de35e Card_ErgRaiders_MarkAttack
#define Glue_Timer_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_Timer_004de83d Card_Leviathan_SacrificeLands
#define Glue_Timer_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_Timer_004dee6b Card_Leviathan_SelectLand
#define Glue_Timer_004defc2 Card_Leviathan_AttackTrigger
#define Glue_Timer_004df04a Card_BrothersOfFire_Ping
#define Glue_Timer_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_Timer_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_Timer_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_Timer_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_Timer_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_Timer_004dfd39 Card_PirateShip_PingTarget
#define Glue_Timer_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_Timer_004dff88 Card_PirateShip_HasIsland
#define Glue_Timer_004e0037 Card_PirateShip_AttackTrigger
#define Glue_Timer_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_Timer_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_Timer_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_Timer_004e0580 Card_RodOfRuin_Ping
#define Glue_Timer_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_Timer_004e08ac Card_RodOfRuin_PayActivation
#define Glue_Timer_004e095b Card_RodOfRuin_SelectTarget
#define Glue_Timer_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_Timer_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_Timer_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_Timer_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_Timer_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_Timer_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_Timer_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_Timer_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_Timer_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_Timer_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_Timer_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_Timer_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_Timer_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_Timer_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_Timer_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_Timer_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_Timer_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_Timer_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_Timer_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_Timer_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_Timer_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_Timer_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_Timer_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_Timer_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_Timer_004e34e4 Card_RockHydra_DecrementHead
#define Glue_Timer_004e3563 Card_RockHydra_DamageTrigger
#define Glue_Timer_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_Timer_004e3730 Card_RockHydra_InitHeads
#define Glue_Timer_004e378b Card_RockHydra_RegrowHead
#define Glue_Timer_004e3b55 Card_AliBaba_TapWall
#define Glue_Timer_004e3e46 Card_LeyDruid_UntapLand
#define Glue_Timer_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_Timer_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_Timer_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_Timer_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_Timer_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_Timer_004e4fae Card_Venom_AttachToCreature
#define Glue_Timer_004e538e Card_Venom_CombatDamageTrigger
#define Glue_Timer_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_Timer_004e580d Card_Venom_AiEvaluateAura
#define Glue_Timer_004e592c Card_Venom_AiCastScore
#define Glue_Timer_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_Timer_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_Timer_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_Timer_004e654a CardQuery_PlayerControlsColor
#define Glue_Timer_004e65e1 CardQuery_ForEachPermanent
#define Glue_Timer_004e66b3 Card_IncrementCounter
#define Glue_Timer_004e676b Card_DecrementCounter
#define Glue_Timer_004e67e1 Card_AddCounters
#define Glue_Timer_004e689b Card_RemoveCounters
#define Glue_Timer_004e6913 Card_SetCounters
#define Glue_Timer_004e6978 Card_GetCounters
#define Glue_Timer_004e69ac CardTarget_PromptTargetCreature
#define Glue_Timer_004e6add CardTarget_SetTargetCreature
#define Glue_Timer_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_Timer_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_Timer_004e6efd CardTarget_SetTargetPermanent
#define Glue_Timer_004e701f CardTarget_HasValidPermanentTarget
#define Glue_Timer_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_Timer_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_Timer_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_Timer_004e73a0 Adventure_EnterTownLocation
#define Glue_Timer_004e7936 Adventure_PromptLocationMenu
#define Glue_Timer_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_Timer_004e7da1 Adventure_ExitTownLocation
#define Glue_Timer_004e7f51 Adventure_PlayLocationMusic
#define Glue_Timer_004e93df Adventure_UpdateWorldMapLoop
#define Glue_Timer_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_Timer_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_Timer_004ea97c Adventure_CheckMonsterEncounter
#define Glue_Timer_004eaa19 Adventure_FormatNewsString
#define Glue_Timer_004eaa9c Adventure_AppendNewsDetails
#define Glue_Timer_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_Timer_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_Timer_004ead96 Adventure_ReloadWorldPalette
#define Glue_Timer_004eadb7 Adventure_LoadFacePalette
#define Glue_Timer_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_Timer_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_Timer_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_Timer_004ebcdc Adventure_Audio_PlayEffect
#define Glue_Timer_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_Timer_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_Timer_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_Timer_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_Timer_004ebebf Adventure_Audio_StopAllTracks
#define Glue_Timer_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_Timer_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_Timer_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_Timer_004ec32f Adventure_Audio_PlayFootstep
#define Glue_Timer_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_Timer_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_Timer_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_Timer_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_Timer_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_Timer_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_Timer_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_Timer_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_Timer_004eccd7 Adventure_ShowDefeatScreen
#define Glue_Timer_004ecee0 Adventure_PromptConfirmDialog
#define Glue_Timer_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_Timer_004ecfe5 Duel_MainArena_WndProc
#define Glue_Timer_004eed47 Duel_UpdateWindowScroll
#define Glue_Timer_004eee4e Duel_BringCardWindowToTop
#define Glue_Timer_004ef05f Duel_GetBattlefieldClientRect
#define Glue_Timer_004ef15b Duel_LayoutCardSlots
#define Glue_Timer_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_Timer_004ef740 Duel_ScrollRightButton_Handler
#define Glue_Timer_004ef849 Duel_HitTestCardSlot
#define Glue_Timer_004ef970 Duel_GetHoveredCardSlot
#define Glue_Timer_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_Timer_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_Timer_004efb3b Duel_PaintBattlefieldBackground
#define Glue_Timer_004efd50 Duel_LogActionStatusBanner
#define Glue_Timer_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_Timer_004f0597 Duel_UnregisterCardWindowClass
#define Glue_Timer_004f05c5 Duel_ChildCard_WndProc
#define Glue_Timer_004f09c0 Duel_GetCardDrawOriginX
#define Glue_Timer_004f0a4a Duel_GetCardDrawOriginY
#define Glue_Timer_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_Timer_004f0b50 Duel_UpdateCardMotionStep
#define Glue_Timer_004f0d90 Duel_ResetCardAnimationState
#define Glue_Timer_004f0de8 Bazaar_GetCardBaseValue
#define Glue_Timer_004f0e47 Bazaar_SellCardsDialog
#define Glue_Timer_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_Timer_004f1910 Catalog_ReleaseWaveletLock
#define Glue_UI_004cd63b Timer_InitVxD
#define Glue_UI_004cd6e3 Timer_GetTicks
#define Glue_UI_004cd715 Timer_MarkStart
#define Glue_UI_004cd72a Timer_GetElapsedFraction
#define Glue_UI_004cd760 SpellChain_RegisterClass
#define Glue_UI_004cda01 SpellChain_CleanupUI
#define Glue_UI_004cdb4f SpellChain_WndProc
#define Glue_UI_004cf8b6 SpellChain_FindEntryIndex
#define Glue_UI_004cf965 SpellChain_RemoveEntry
#define Glue_UI_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_UI_004cfb2f SpellChain_InsertEntry
#define Glue_UI_004cfd68 SpellChain_ClearEntryTargets
#define Glue_UI_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_UI_004cffda SpellChain_UpdateLayout
#define Glue_UI_004d05e8 SpellChain_GetContentRect
#define Glue_UI_004d0602 SpellChain_MinimizedWndProc
#define Glue_UI_004d0965 SpellChain_MinimizeIfShown
#define Glue_UI_004d09bd SpellChain_RestoreIfMinimized
#define Glue_UI_004d0a30 Card_DefaultEventHandler
#define Glue_UI_004d0a42 Card_GetColorAndTypeFlags
#define Glue_UI_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_UI_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_UI_004d1cc4 Card_Sinbad_Draw
#define Glue_UI_004d1e10 Card_Kudzu_LandDestruction
#define Glue_UI_004d212c Card_BronzeTablets_AnteSwap
#define Glue_UI_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_UI_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_UI_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_UI_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_UI_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_UI_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_UI_004d30ae Card_Doppelganger_CheckState
#define Glue_UI_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_UI_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_UI_004d3229 Card_IslandSanctuary_Trigger
#define Glue_UI_004d328c Card_IslandSanctuary_CheckActive
#define Glue_UI_004d332a Card_IslandSanctuary_Prompt
#define Glue_UI_004d353d Card_LivingLands_AnimateForests
#define Glue_UI_004d374d Card_KormusBell_AnimateSwamps
#define Glue_UI_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_UI_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_UI_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_UI_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_UI_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_UI_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_UI_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_UI_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_UI_004d4d1f Card_AliFromCairo_ResetState
#define Glue_UI_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_UI_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_UI_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_UI_004d6391 Card_FrozenShade_ClearBoost
#define Glue_UI_004d6400 Card_FrozenShade_PumpBlack
#define Glue_UI_004d6706 Card_WaterElemental_PumpBlue
#define Glue_UI_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_UI_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_UI_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_UI_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_UI_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_UI_004d7065 Card_GaeasLiege_TransformLand
#define Glue_UI_004d7724 Card_GaeasLiege_ResetLand
#define Glue_UI_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_UI_004d788d Card_GaeasLiege_IsForest
#define Glue_UI_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_UI_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_UI_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_UI_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_UI_004d7bb5 Card_LivingWall_Regenerate
#define Glue_UI_004d7c60 Card_GenericCreature_Regenerate
#define Glue_UI_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_UI_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_UI_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_UI_004d87cb Card_UthdenTroll_Regenerate
#define Glue_UI_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_UI_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_UI_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_UI_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_UI_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_UI_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_UI_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_UI_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_UI_004dae76 Card_Targeting_PromptCreature
#define Glue_UI_004db024 Card_NettlingImp_ForceAttack
#define Glue_UI_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_UI_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_UI_004dba1c Card_SorceressQueen_SetStats02
#define Glue_UI_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_UI_004dc2ca Card_StoneGiant_Fling
#define Glue_UI_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_UI_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_UI_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_UI_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_UI_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_UI_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_UI_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_UI_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_UI_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_UI_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_UI_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_UI_004de05f Card_DamagePrevention_QueryAmount
#define Glue_UI_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_UI_004de100 Card_DamagePrevention_CheckSource
#define Glue_UI_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_UI_004de35e Card_ErgRaiders_MarkAttack
#define Glue_UI_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_UI_004de83d Card_Leviathan_SacrificeLands
#define Glue_UI_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_UI_004dee6b Card_Leviathan_SelectLand
#define Glue_UI_004defc2 Card_Leviathan_AttackTrigger
#define Glue_UI_004df04a Card_BrothersOfFire_Ping
#define Glue_UI_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_UI_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_UI_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_UI_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_UI_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_UI_004dfd39 Card_PirateShip_PingTarget
#define Glue_UI_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_UI_004dff88 Card_PirateShip_HasIsland
#define Glue_UI_004e0037 Card_PirateShip_AttackTrigger
#define Glue_UI_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_UI_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_UI_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_UI_004e0580 Card_RodOfRuin_Ping
#define Glue_UI_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_UI_004e08ac Card_RodOfRuin_PayActivation
#define Glue_UI_004e095b Card_RodOfRuin_SelectTarget
#define Glue_UI_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_UI_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_UI_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_UI_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_UI_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_UI_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_UI_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_UI_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_UI_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_UI_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_UI_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_UI_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_UI_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_UI_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_UI_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_UI_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_UI_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_UI_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_UI_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_UI_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_UI_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_UI_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_UI_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_UI_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_UI_004e34e4 Card_RockHydra_DecrementHead
#define Glue_UI_004e3563 Card_RockHydra_DamageTrigger
#define Glue_UI_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_UI_004e3730 Card_RockHydra_InitHeads
#define Glue_UI_004e378b Card_RockHydra_RegrowHead
#define Glue_UI_004e3b55 Card_AliBaba_TapWall
#define Glue_UI_004e3e46 Card_LeyDruid_UntapLand
#define Glue_UI_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_UI_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_UI_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_UI_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_UI_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_UI_004e4fae Card_Venom_AttachToCreature
#define Glue_UI_004e538e Card_Venom_CombatDamageTrigger
#define Glue_UI_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_UI_004e580d Card_Venom_AiEvaluateAura
#define Glue_UI_004e592c Card_Venom_AiCastScore
#define Glue_UI_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_UI_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_UI_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_UI_004e654a CardQuery_PlayerControlsColor
#define Glue_UI_004e65e1 CardQuery_ForEachPermanent
#define Glue_UI_004e66b3 Card_IncrementCounter
#define Glue_UI_004e676b Card_DecrementCounter
#define Glue_UI_004e67e1 Card_AddCounters
#define Glue_UI_004e689b Card_RemoveCounters
#define Glue_UI_004e6913 Card_SetCounters
#define Glue_UI_004e6978 Card_GetCounters
#define Glue_UI_004e69ac CardTarget_PromptTargetCreature
#define Glue_UI_004e6add CardTarget_SetTargetCreature
#define Glue_UI_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_UI_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_UI_004e6efd CardTarget_SetTargetPermanent
#define Glue_UI_004e701f CardTarget_HasValidPermanentTarget
#define Glue_UI_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_UI_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_UI_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_UI_004e73a0 Adventure_EnterTownLocation
#define Glue_UI_004e7936 Adventure_PromptLocationMenu
#define Glue_UI_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_UI_004e7da1 Adventure_ExitTownLocation
#define Glue_UI_004e7f51 Adventure_PlayLocationMusic
#define Glue_UI_004e93df Adventure_UpdateWorldMapLoop
#define Glue_UI_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_UI_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_UI_004ea97c Adventure_CheckMonsterEncounter
#define Glue_UI_004eaa19 Adventure_FormatNewsString
#define Glue_UI_004eaa9c Adventure_AppendNewsDetails
#define Glue_UI_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_UI_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_UI_004ead96 Adventure_ReloadWorldPalette
#define Glue_UI_004eadb7 Adventure_LoadFacePalette
#define Glue_UI_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_UI_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_UI_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_UI_004ebcdc Adventure_Audio_PlayEffect
#define Glue_UI_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_UI_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_UI_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_UI_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_UI_004ebebf Adventure_Audio_StopAllTracks
#define Glue_UI_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_UI_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_UI_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_UI_004ec32f Adventure_Audio_PlayFootstep
#define Glue_UI_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_UI_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_UI_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_UI_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_UI_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_UI_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_UI_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_UI_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_UI_004eccd7 Adventure_ShowDefeatScreen
#define Glue_UI_004ecee0 Adventure_PromptConfirmDialog
#define Glue_UI_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_UI_004ecfe5 Duel_MainArena_WndProc
#define Glue_UI_004eed47 Duel_UpdateWindowScroll
#define Glue_UI_004eee4e Duel_BringCardWindowToTop
#define Glue_UI_004ef05f Duel_GetBattlefieldClientRect
#define Glue_UI_004ef15b Duel_LayoutCardSlots
#define Glue_UI_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_UI_004ef740 Duel_ScrollRightButton_Handler
#define Glue_UI_004ef849 Duel_HitTestCardSlot
#define Glue_UI_004ef970 Duel_GetHoveredCardSlot
#define Glue_UI_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_UI_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_UI_004efb3b Duel_PaintBattlefieldBackground
#define Glue_UI_004efd50 Duel_LogActionStatusBanner
#define Glue_UI_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_UI_004f0597 Duel_UnregisterCardWindowClass
#define Glue_UI_004f05c5 Duel_ChildCard_WndProc
#define Glue_UI_004f09c0 Duel_GetCardDrawOriginX
#define Glue_UI_004f0a4a Duel_GetCardDrawOriginY
#define Glue_UI_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_UI_004f0b50 Duel_UpdateCardMotionStep
#define Glue_UI_004f0d90 Duel_ResetCardAnimationState
#define Glue_UI_004f0de8 Bazaar_GetCardBaseValue
#define Glue_UI_004f0e47 Bazaar_SellCardsDialog
#define Glue_UI_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_UI_004f1910 Catalog_ReleaseWaveletLock
#define Glue_Util_004cd63b Timer_InitVxD
#define Glue_Util_004cd6e3 Timer_GetTicks
#define Glue_Util_004cd715 Timer_MarkStart
#define Glue_Util_004cd72a Timer_GetElapsedFraction
#define Glue_Util_004cd760 SpellChain_RegisterClass
#define Glue_Util_004cda01 SpellChain_CleanupUI
#define Glue_Util_004cdb4f SpellChain_WndProc
#define Glue_Util_004cf8b6 SpellChain_FindEntryIndex
#define Glue_Util_004cf965 SpellChain_RemoveEntry
#define Glue_Util_004cfab2 SpellChain_EntryTargetsMatch
#define Glue_Util_004cfb2f SpellChain_InsertEntry
#define Glue_Util_004cfd68 SpellChain_ClearEntryTargets
#define Glue_Util_004cfe4d SpellChain_RebuildEntryTargets
#define Glue_Util_004cffda SpellChain_UpdateLayout
#define Glue_Util_004d05e8 SpellChain_GetContentRect
#define Glue_Util_004d0602 SpellChain_MinimizedWndProc
#define Glue_Util_004d0965 SpellChain_MinimizeIfShown
#define Glue_Util_004d09bd SpellChain_RestoreIfMinimized
#define Glue_Util_004d0a30 Card_DefaultEventHandler
#define Glue_Util_004d0a42 Card_GetColorAndTypeFlags
#define Glue_Util_004d0cdb Card_PrismaticDragon_ColorChange
#define Glue_Util_004d109a Card_RainbowKnights_ActivatedAbility
#define Glue_Util_004d1cc4 Card_Sinbad_Draw
#define Glue_Util_004d1e10 Card_Kudzu_LandDestruction
#define Glue_Util_004d212c Card_BronzeTablets_AnteSwap
#define Glue_Util_004d2610 Card_XenicPoltergeist_AnimateArtifact
#define Glue_Util_004d29da Card_VesuvanDoppelganger_Copy
#define Glue_Util_004d2c17 Card_VesuvanDoppelganger_Upkeep
#define Glue_Util_004d2d28 Card_Doppelganger_ClearMimic
#define Glue_Util_004d2e2a Card_Doppelganger_ApplyMimicStats
#define Glue_Util_004d2f6c Card_Doppelganger_SyncAbilities
#define Glue_Util_004d30ae Card_Doppelganger_CheckState
#define Glue_Util_004d3144 Card_IslandSanctuary_SkipDraw
#define Glue_Util_004d31a9 Card_IslandSanctuary_AttackRestriction
#define Glue_Util_004d3229 Card_IslandSanctuary_Trigger
#define Glue_Util_004d328c Card_IslandSanctuary_CheckActive
#define Glue_Util_004d332a Card_IslandSanctuary_Prompt
#define Glue_Util_004d353d Card_LivingLands_AnimateForests
#define Glue_Util_004d374d Card_KormusBell_AnimateSwamps
#define Glue_Util_004d395d Card_TitaniasSong_AnimateArtifacts
#define Glue_Util_004d3d1d Card_TitaniasSong_RemoveAbilities
#define Glue_Util_004d3d82 Card_TitaniasSong_RestoreAbilities
#define Glue_Util_004d3dff Card_TitaniasSong_UpdateStatus
#define Glue_Util_004d3fa1 Card_TitaniasSong_ClearFlags
#define Glue_Util_004d4099 Card_TitaniasSong_CheckTrigger
#define Glue_Util_004d420e Card_PersonalIncarnation_RedirectDamage
#define Glue_Util_004d4762 Card_AliFromCairo_PreventLethalDamage
#define Glue_Util_004d4d1f Card_AliFromCairo_ResetState
#define Glue_Util_004d4f73 Card_ShivanDragon_PumpFirebreathing
#define Glue_Util_004d5626 Card_DragonWhelp_PumpFirebreathing
#define Glue_Util_004d5c1e Card_DragonWhelp_EndTurnCheck
#define Glue_Util_004d6391 Card_FrozenShade_ClearBoost
#define Glue_Util_004d6400 Card_FrozenShade_PumpBlack
#define Glue_Util_004d6706 Card_WaterElemental_PumpBlue
#define Glue_Util_004d683f Card_ClockworkBeast_ResetCounters
#define Glue_Util_004d6ad4 Card_ClockworkBeast_CombatTrigger
#define Glue_Util_004d6c43 Card_ClockworkBeast_Rewind
#define Glue_Util_004d6d82 Card_ClockworkBeast_GetPower
#define Glue_Util_004d6e79 Card_ClockworkBeast_GetToughness
#define Glue_Util_004d7065 Card_GaeasLiege_TransformLand
#define Glue_Util_004d7724 Card_GaeasLiege_ResetLand
#define Glue_Util_004d777b Card_GaeasLiege_CheckAttackRestriction
#define Glue_Util_004d788d Card_GaeasLiege_IsForest
#define Glue_Util_004d78d2 Card_GaeasLiege_CombatCheck
#define Glue_Util_004d79a6 Card_SedgeTroll_CheckSwamp
#define Glue_Util_004d7a1b Card_SedgeTroll_Regenerate
#define Glue_Util_004d7b68 Card_LivingWall_PromptRegenerate
#define Glue_Util_004d7bb5 Card_LivingWall_Regenerate
#define Glue_Util_004d7c60 Card_GenericCreature_Regenerate
#define Glue_Util_004d7e90 Card_GenericCreature_CanRegenerate
#define Glue_Util_004d80d3 Card_GenericCreature_TriggerRegen
#define Glue_Util_004d817b Card_DrudgeSkeletons_Regenerate
#define Glue_Util_004d87cb Card_UthdenTroll_Regenerate
#define Glue_Util_004d8e4c Card_WillOTheWisp_Regenerate
#define Glue_Util_004d94e1 Card_MarrowThieves_Regenerate
#define Glue_Util_004d9afd Card_HypnoticSpecter_RandomDiscard
#define Glue_Util_004d9f7e Card_TimeElemental_BouncePermanent
#define Glue_Util_004da482 Card_NorthernPaladin_DestroyBlack
#define Glue_Util_004da858 Card_RoyalAssassin_DestroyTapped
#define Glue_Util_004daa50 Card_DwarvenDemolitionTeam_DestroyWall
#define Glue_Util_004dac11 Card_KingSuleiman_DestroyDjinn
#define Glue_Util_004dae76 Card_Targeting_PromptCreature
#define Glue_Util_004db024 Card_NettlingImp_ForceAttack
#define Glue_Util_004db401 Card_NettlingImp_CheckEndTurn
#define Glue_Util_004db8c9 Card_NettlingImp_IsTargetEligible
#define Glue_Util_004dba1c Card_SorceressQueen_SetStats02
#define Glue_Util_004dbfdb Card_SorceressQueen_ResetStats
#define Glue_Util_004dc2ca Card_StoneGiant_Fling
#define Glue_Util_004dc6c7 Card_DwarvenWarriors_MakeUnblockable
#define Glue_Util_004dc9ed Card_CavePeople_Mountainwalk
#define Glue_Util_004dce51 Card_PradeshGypsies_PreventAttack
#define Glue_Util_004dd33b Card_PradeshGypsies_ResetRestriction
#define Glue_Util_004dd632 Card_SamiteHealer_PreventDamage
#define Glue_Util_004dd98f Card_SamiteHealer_CalculateHealAdvantage
#define Glue_Util_004ddcf4 Card_AlabasterPotion_HealOrPrevent
#define Glue_Util_004dde51 Card_HealingSalve_DamagePrevention
#define Glue_Util_004ddefa Card_DamagePrevention_ApplyBubble
#define Glue_Util_004ddf4b Card_DamagePrevention_ReduceDamage
#define Glue_Util_004ddf98 Card_DamagePrevention_ClearAtCleanup
#define Glue_Util_004de05f Card_DamagePrevention_QueryAmount
#define Glue_Util_004de0b3 Card_DamagePrevention_PromptTarget
#define Glue_Util_004de100 Card_DamagePrevention_CheckSource
#define Glue_Util_004de1c0 Card_ErgRaiders_UpkeepDamage
#define Glue_Util_004de35e Card_ErgRaiders_MarkAttack
#define Glue_Util_004de492 Card_ErgRaiders_ClearTurnAttack
#define Glue_Util_004de83d Card_Leviathan_SacrificeLands
#define Glue_Util_004dec09 Card_Leviathan_PromptLandSacrifice
#define Glue_Util_004dee6b Card_Leviathan_SelectLand
#define Glue_Util_004defc2 Card_Leviathan_AttackTrigger
#define Glue_Util_004df04a Card_BrothersOfFire_Ping
#define Glue_Util_004df20c Card_BrothersOfFire_EvaluateTarget
#define Glue_Util_004df314 Card_CrimsonManticore_DamageTarget
#define Glue_Util_004df678 Card_ProdigalSorcerer_PingTarget
#define Glue_Util_004df8ba Card_DirectDamage_EvaluateBestTarget
#define Glue_Util_004dfb23 Card_DirectDamage_PromptAndDealDamage
#define Glue_Util_004dfd39 Card_PirateShip_PingTarget
#define Glue_Util_004dfe94 Card_PirateShip_CheckIslandwalk
#define Glue_Util_004dff88 Card_PirateShip_HasIsland
#define Glue_Util_004e0037 Card_PirateShip_AttackTrigger
#define Glue_Util_004e00e7 Card_IslandFishJasconius_PayToUntap
#define Glue_Util_004e03b5 Card_IslandFishJasconius_CheckIslands
#define Glue_Util_004e04be Card_IslandFishJasconius_DestroyIfNoIslands
#define Glue_Util_004e0580 Card_RodOfRuin_Ping
#define Glue_Util_004e07b5 Card_RodOfRuin_EvaluateAi
#define Glue_Util_004e08ac Card_RodOfRuin_PayActivation
#define Glue_Util_004e095b Card_RodOfRuin_SelectTarget
#define Glue_Util_004e0ab7 Card_OrcishArtillery_ShootTarget
#define Glue_Util_004e0c1c Card_PsionicEntity_ShootTarget
#define Glue_Util_004e0e60 Card_PsionicEntity_EvaluateTarget
#define Glue_Util_004e0fd0 Card_PsionicEntity_SelfDamage
#define Glue_Util_004e114e Card_KhabalGhoul_AddCounterOnDeath
#define Glue_Util_004e12cf Card_KhabalGhoul_CheckCreatureDeath
#define Glue_Util_004e191d Card_KhabalGhoul_ApplyCounterBonus
#define Glue_Util_004e1a2b Card_KhabalGhoul_ResetCounterBonus
#define Glue_Util_004e1b38 Card_LordOfAtlantis_PayOrSacrifice
#define Glue_Util_004e1c8c Card_LordOfAtlantis_ApplyMerfolkBuff
#define Glue_Util_004e1d96 Card_LordOfAtlantis_RemoveMerfolkBuff
#define Glue_Util_004e1e6c Card_LordOfAtlantis_IslandwalkTrigger
#define Glue_Util_004e1f0d Card_LordOfAtlantis_CheckMerfolkType
#define Glue_Util_004e1fcb Card_ForceOfNature_PayUpkeep
#define Glue_Util_004e2101 Card_ForceOfNature_AiPayOrTakeDamage
#define Glue_Util_004e22b2 Card_BirdsOfParadise_TapForMana
#define Glue_Util_004e268e Card_CosmicHorror_PayUpkeep
#define Glue_Util_004e2841 Card_LordOfThePit_SacrificeOrDamage
#define Glue_Util_004e2b99 Card_LordOfThePit_FindSacrificeCandidate
#define Glue_Util_004e2c7f Card_KormusBell_PayLandUpkeep
#define Glue_Util_004e2fe8 Card_KormusBell_CheckSwampCreature
#define Glue_Util_004e3128 Card_NetherShadow_CheckGraveyard
#define Glue_Util_004e3185 Card_NetherShadow_CountCreaturesAbove
#define Glue_Util_004e32f3 Card_NetherShadow_ReturnFromGrave
#define Glue_Util_004e34e4 Card_RockHydra_DecrementHead
#define Glue_Util_004e3563 Card_RockHydra_DamageTrigger
#define Glue_Util_004e35e4 Card_RockHydra_UpdateStatsFromHeads
#define Glue_Util_004e3730 Card_RockHydra_InitHeads
#define Glue_Util_004e378b Card_RockHydra_RegrowHead
#define Glue_Util_004e3b55 Card_AliBaba_TapWall
#define Glue_Util_004e3e46 Card_LeyDruid_UntapLand
#define Glue_Util_004e4144 Card_LeyDruid_AiEvaluateLand
#define Glue_Util_004e42ac Card_LeyDruid_ExecuteUntap
#define Glue_Util_004e4508 Card_HurkylsRecall_PickArtifact
#define Glue_Util_004e474e Card_HurkylsRecall_ReturnAllArtifacts
#define Glue_Util_004e4807 Card_Venom_DestroyCombatBlocker
#define Glue_Util_004e4fae Card_Venom_AttachToCreature
#define Glue_Util_004e538e Card_Venom_CombatDamageTrigger
#define Glue_Util_004e55d5 Card_Venom_DestroyAtEndOfCombat
#define Glue_Util_004e580d Card_Venom_AiEvaluateAura
#define Glue_Util_004e592c Card_Venom_AiCastScore
#define Glue_Util_004e5a39 Card_Venom_ClearAuraFlags
#define Glue_Util_004e5e3b Card_RadjanSpirit_RemoveFlying
#define Glue_Util_004e61a6 Card_HurrJackal_GrantCombatAbility
#define Glue_Util_004e654a CardQuery_PlayerControlsColor
#define Glue_Util_004e65e1 CardQuery_ForEachPermanent
#define Glue_Util_004e66b3 Card_IncrementCounter
#define Glue_Util_004e676b Card_DecrementCounter
#define Glue_Util_004e67e1 Card_AddCounters
#define Glue_Util_004e689b Card_RemoveCounters
#define Glue_Util_004e6913 Card_SetCounters
#define Glue_Util_004e6978 Card_GetCounters
#define Glue_Util_004e69ac CardTarget_PromptTargetCreature
#define Glue_Util_004e6add CardTarget_SetTargetCreature
#define Glue_Util_004e6bff CardTarget_HasValidCreatureTarget
#define Glue_Util_004e6dcc CardTarget_PromptTargetPermanent
#define Glue_Util_004e6efd CardTarget_SetTargetPermanent
#define Glue_Util_004e701f CardTarget_HasValidPermanentTarget
#define Glue_Util_004e70ad CardTarget_PromptTargetPlayerOrCreature
#define Glue_Util_004e71de CardTarget_SetTargetPlayerOrCreature
#define Glue_Util_004e7300 CardTarget_HasValidPlayerOrCreatureTarget
#define Glue_Util_004e73a0 Adventure_EnterTownLocation
#define Glue_Util_004e7936 Adventure_PromptLocationMenu
#define Glue_Util_004e7a6f Adventure_HandleLocationMenuChoice
#define Glue_Util_004e7da1 Adventure_ExitTownLocation
#define Glue_Util_004e7f51 Adventure_PlayLocationMusic
#define Glue_Util_004e93df Adventure_UpdateWorldMapLoop
#define Glue_Util_004ea7a6 Adventure_GetLocationEncounterIndex
#define Glue_Util_004ea8df Adventure_SetLocationEncounterIndex
#define Glue_Util_004ea97c Adventure_CheckMonsterEncounter
#define Glue_Util_004eaa19 Adventure_FormatNewsString
#define Glue_Util_004eaa9c Adventure_AppendNewsDetails
#define Glue_Util_004eabb2 Adventure_PlayMonsterEncounterSound
#define Glue_Util_004ead33 Adventure_TriggerDuelFromEncounter
#define Glue_Util_004ead96 Adventure_ReloadWorldPalette
#define Glue_Util_004eadb7 Adventure_LoadFacePalette
#define Glue_Util_004eade5 Adventure_NewsFlash_EnemyAttack
#define Glue_Util_004eb2f9 Adventure_NewsFlash_Retaliation
#define Glue_Util_004eb824 Adventure_NewsFlash_DominionSpell
#define Glue_Util_004ebcdc Adventure_Audio_PlayEffect
#define Glue_Util_004ebd62 Adventure_Audio_PlayEffectAtVolume
#define Glue_Util_004ebdca Adventure_Audio_PlayEffectLooped
#define Glue_Util_004ebe1a Adventure_Audio_StopEffectChannel
#define Glue_Util_004ebe61 Adventure_Audio_SetPlaybackPosition
#define Glue_Util_004ebebf Adventure_Audio_StopAllTracks
#define Glue_Util_004ebeeb Adventure_Audio_PlayCastleVictory
#define Glue_Util_004ebfef Adventure_Audio_PlayDuelIntro
#define Glue_Util_004ec055 Adventure_Audio_PlayTerrainAmbience
#define Glue_Util_004ec32f Adventure_Audio_PlayFootstep
#define Glue_Util_004ec439 Adventure_Audio_FindSoundOnDrives
#define Glue_Util_004ec4fc Adventure_Audio_GetMusicDrivePath
#define Glue_Util_004ec572 Adventure_Audio_FreeSoundTrack
#define Glue_Util_004ec5be Adventure_Audio_InitSoundTrack
#define Glue_Util_004ec65a Adventure_Audio_GetTrackStatus
#define Glue_Util_004ec6ea Adventure_Map_GetTerrainAtCoord
#define Glue_Util_004ec7f9 Adventure_Map_RedrawViewport
#define Glue_Util_004ec98e Adventure_Map_UpdateLightingAndPalette
#define Glue_Util_004eccd7 Adventure_ShowDefeatScreen
#define Glue_Util_004ecee0 Adventure_PromptConfirmDialog
#define Glue_Util_004ecf94 Adventure_DestroyConfirmMenu
#define Glue_Util_004ecfe5 Duel_MainArena_WndProc
#define Glue_Util_004eed47 Duel_UpdateWindowScroll
#define Glue_Util_004eee4e Duel_BringCardWindowToTop
#define Glue_Util_004ef05f Duel_GetBattlefieldClientRect
#define Glue_Util_004ef15b Duel_LayoutCardSlots
#define Glue_Util_004ef64b Duel_ScrollLeftButton_Handler
#define Glue_Util_004ef740 Duel_ScrollRightButton_Handler
#define Glue_Util_004ef849 Duel_HitTestCardSlot
#define Glue_Util_004ef970 Duel_GetHoveredCardSlot
#define Glue_Util_004efa20 Duel_GetCardSlotWindowHandle
#define Glue_Util_004efaba Duel_GetTargetSlotWindowHandle
#define Glue_Util_004efb3b Duel_PaintBattlefieldBackground
#define Glue_Util_004efd50 Duel_LogActionStatusBanner
#define Glue_Util_004f04e0 Duel_RegisterChildCardWindowClass
#define Glue_Util_004f0597 Duel_UnregisterCardWindowClass
#define Glue_Util_004f05c5 Duel_ChildCard_WndProc
#define Glue_Util_004f09c0 Duel_GetCardDrawOriginX
#define Glue_Util_004f0a4a Duel_GetCardDrawOriginY
#define Glue_Util_004f0af6 Duel_TriggerCardDrawAnimation
#define Glue_Util_004f0b50 Duel_UpdateCardMotionStep
#define Glue_Util_004f0d90 Duel_ResetCardAnimationState
#define Glue_Util_004f0de8 Bazaar_GetCardBaseValue
#define Glue_Util_004f0e47 Bazaar_SellCardsDialog
#define Glue_Util_004f15c0 Catalog_LoadWaveletCardArt
#define Glue_Util_004f1910 Catalog_ReleaseWaveletLock

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_GLUE_H */
