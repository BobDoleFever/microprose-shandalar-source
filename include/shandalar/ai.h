/*
 * shandalar/ai.h - MicroProse Sid Meier Tactical AI & Decision Engine
 * Original Source Path: G:\NewMagic\sources\sid\Ai.h / Ai.c
 * Comments follow Simplified Technical English (STE) rules.
 */
#ifndef SHANDALAR_AI_H
#define SHANDALAR_AI_H

#include "types.h"
#include "sound.h"
#include "win32_compat.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * AI Difficulty Levels.
 * Use these values to set the opponent skill level.
 */
typedef enum AiDifficulty {
    AI_DIFFICULTY_APPRENTICE = 0, /* Lowest difficulty level. */
    AI_DIFFICULTY_MAGE       = 1, /* Medium difficulty level. */
    AI_DIFFICULTY_ARCHMAGE   = 2, /* Hard difficulty level. */
    AI_DIFFICULTY_WIZARD     = 3  /* Expert difficulty level. */
} AiDifficulty;

/*
 * Board Evaluation Score Metrics.
 * This structure holds numeric score values for board analysis.
 */
typedef struct BoardScore {
    int32_t life_score;          /* Score for player life total advantage. */
    int32_t card_advantage;      /* Score for count of cards in hand. */
    int32_t creature_power;      /* Total attack and defense power of creatures. */
    int32_t mana_available;      /* Count of untapped mana sources. */
    int32_t board_threat;        /* Threat value of opponent cards (ScWilly metric). */
    int32_t total_score;         /* Sum of all calculated score values. */
} BoardScore;

/*
 * Combat Decision Matrix.
 * This structure stores combat assignments for creatures.
 */
typedef struct CombatDecision {
    int32_t attacker_card_id;    /* Identification number of attacking card. */
    int32_t blocker_card_id;     /* Identification number of blocking card (-1 = none). */
    int32_t damage_assigned;     /* Amount of damage to apply. */
    bool    should_attack;       /* True if the creature must attack. */
    bool    should_block;        /* True if the creature must block. */
} CombatDecision;

/* ========================================================================= */
/* Modernized Function Prototypes (260 Tactical AI Functions)               */
/* ========================================================================= */

void Ai_SaveGameState(void);
void Ai_RestoreGameState(void);
void Ai_PushBoardState(void);
void Ai_PopBoardState(void);
void Ai_ClearPlan(void);
void Ai_BeginTrial(void);
void Ai_RecordChoice(void);
int Ai_GetOpponentPlayerScore(int arg1);
int Ai_CalcLifeAdvantage(int arg1);
void Ai_ReplayChoice(void);
void Ai_CommitBestPlan(void);
int Ai_Score_ClearCache(void);
void Ai_Score_SetValidityFlag(void);
int Ai_EvaluateBoard(int arg1);
int Ai_PenalizeCounterattack(int player, int attacker_idx);
int Ai_ChooseBlockers(int player, int attacker_idx);
void Ai_FilterValidBlockers(uint32_t * arg1, uint32_t * arg2);
int Duel_ShowStartOfDuelDialog(int * arg1, uint32_t * arg2, uint32_t arg3, int arg4, uint32_t arg5, uint32_t arg6, int arg7, int arg8, int arg9);
HGDIOBJ Ai_DuelDialogProc(HWND hwnd, uint32_t uMsg, HWND wParam, HWND lParam);
void Ai_LoadStartDuel2Backdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6);
void Ai_StartDuel_InitContext(int arg1, int arg2, int arg3);
HGDIOBJ Ai_StartDuelWndProc(HWND hwnd, uint32_t uMsg, HWND wParam, HWND lParam);
void Ai_LoadStartDuelBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7);
void Ai_Duel_ResetBuffers(int x, int y, int width, int height);
void Ai_Duel_SetupSurfaces(int arg1);
INT_PTR Ai_Duel_RenderBackdrop(int arg1, int arg2, int arg3, int arg4, int arg5);
HGDIOBJ Ai_DuelMainWndProc(HWND hwnd, uint32_t uMsg, HDC wParam, HWND lParam);
void Ai_LoadEndDuelBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7, int * arg8);
void Ai_EndDuel_ShowResult(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4);
int Ai_EndDuel_ProcessRewards(int arg1, int arg2);
LRESULT Ai_EndDuel_Cleanup(int arg1, char * output_str, int arg3, int arg4, int arg5, int arg6, int arg7, int * arg8, int * arg9, int arg10, int arg11);
void Ai_Score_InitRegister(void);
INT_PTR Ai_ScoreCardPlay_Creature(int * player, int card_index, int target_player, int action_flags, int arg5, char * arg6);
LRESULT Ai_ScoreCardPlay_Spell(HWND player, uint32_t card_index, HDC target_player, int * action_flags);
void Ai_ScoreCardPlay_Enchantment(int * player, int * card_index, int * target_player, int * action_flags, int * arg5, int * arg6);
void Ai_ScoreCardPlay_Artifact(HGDIOBJ player, HGDIOBJ card_index, HGDIOBJ target_player, HGDIOBJ action_flags, HGDIOBJ arg5);
LRESULT Ai_ScoreDialog_WndProc(HWND hwnd, uint32_t uMsg, WPARAM wParam, LONG * lParam);
void Ai_CalcMana_ResetPool(void);
void Ai_CalcMana_AddSource(uint32_t player, int color_index, int required_amount);
void Ai_CalcMana_ClearAvailable(void);
INT_PTR Ai_ManaSelection_DialogProc(int hwnd, int uMsg, INT_PTR wParam, char * lParam, char * arg5, char * arg6);
HWND Ai_TargetSelection_DialogProc(HWND hwnd, uint32_t uMsg, uint32_t wParam, int * lParam);
INT_PTR Ai_Target_HighlightCandidate(int arg1, int arg2, INT_PTR arg3);
int Ai_AttackSelection_DialogProc(HWND hwnd, uint32_t uMsg, uint32_t wParam, int * lParam);
INT_PTR Ai_Attack_ToggleAttacker(int arg1, int arg2, INT_PTR arg3);
HGDIOBJ Ai_BlockSelection_DialogProc(HWND hwnd, uint32_t uMsg, HDC wParam, HWND lParam);
LRESULT Ai_Block_AssignPair(HWND hwnd, UINT y, uint32_t width, LPARAM arg4);
void Ai_LoadQuestPromptBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7);
void Ai_Quest_FormatPromptText(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4);
INT_PTR Ai_Quest_ProcessChoice(int arg1, int arg2, int arg3, int arg4, uint32_t arg5);
HGDIOBJ Ai_Quest_DialogProc(HWND hwnd, uint32_t uMsg, HDC wParam, HWND lParam);
void Ai_CalcManaRequirement_Black(int * player, int * color_index, int * required_amount, int * arg4, int * arg5, int * arg6, int * arg7, int * arg8, int * arg9, int * arg10);
void Ai_CalcManaRequirement_Blue(int player, int color_index, int required_amount, HGDIOBJ arg4, HGDIOBJ arg5, HGDIOBJ arg6);
void Ai_CalcManaRequirement_Green(LPRECT player, HWND color_index, int required_amount);
INT_PTR Ai_CalcManaRequirement_Red(int player, int * color_index, int required_amount, int arg4, uint32_t arg5);
HBRUSH Ai_CalcManaRequirement_White(HWND player, uint32_t color_index, HWND required_amount, HWND arg4);
void Ai_LoadChangeTextBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7);
void Ai_ChangeText_FormatOptions(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4);
void Ai_ChangeText_ResetState(void);
uint32_t Ai_ChangeText_ApplyWord(void);
void Ai_EvalAttackCandidate_CombatTrade(int player, uint32_t attacker_idx);
void Ai_Eval_ClearCandidateBuffer(void);
int Ai_Eval_GetCandidateScore(void);
uint32_t Ai_Eval_SetCandidateScore(void);
void Ai_Eval_GetBestCandidate(void);
void Ai_Eval_ResetBestCandidate(void);
int Ai_Eval_SortCandidates(void);
void Ai_EvalAbility_Flying(char * player);
void Ai_EvalAbility_Trample(char * player);
int Ai_EvalAbility_FirstStrike(int player, int card_index, int target_player, int action_flags, int arg5, int arg6);
int Ai_EvalAbility_Regeneration(void);
void Ai_EvalAbility_Protection(int player);
int Ai_EvalAbility_Landwalk(int player, int card_index);
uint32_t Ai_EvalAbility_Deathtouch(int player, int card_index);
int Ai_EvalAbility_DirectDamage(int player, int card_index);
uint32_t Ai_EvalAbility_Removal(int player, int card_index);
void Ai_EvalAbility_Counterspell(int player, int card_index, uint32_t * target_player, uint32_t * action_flags, uint32_t * arg5);
int Ai_EvalAbility_CardDraw(int player, int card_index);
int Ai_EvalAbility_Displacement(int player, int card_index);
int Ai_EvalAbility_LifeGain(int player, int card_index);
int Ai_EvalAbility_Disenchant(int player, int card_index);
int Ai_EvalAbility_BoardWipe(int player, int card_index);
uint8_t Ai_EvalAbility_LandDestruction(int player, int card_index);
void Ai_EvalAbility_ManaRamp(int * player, int card_index, int target_player);
int Ai_EvalAbility_Tapping(int * player, int card_index, int target_player);
uint8_t Ai_EvalAbility_Discard(int player, int card_index);
int Ai_EvalAbility_PumpSpell(int player, int card_index);
int Ai_EvalAbility_Haste(int player, int card_index);
uint32_t Ai_EvalAbility_Vigilance(int player, int card_index);
int Ai_EvalAbility_Defender(int player, int card_index);
int Ai_EvalAbility_PingDamage(int player, int card_index);
int Ai_EvalAbility_Recursion(int player, int card_index);
int Ai_EvalAbility_TokenGeneration(int player, int card_index);
void Ai_EvalAbility_SacrificeOutlet(int player, int card_index, int * target_player, int * action_flags);
int Ai_Eval_ClearAbilityTable(void);
uint32_t Ai_EvalAbility_DamagePrevention(int player, int card_index);
uint32_t Ai_EvalAbility_PowerMod(int player, int card_index);
bool Ai_EvalAbility_ToughnessMod(int player, int card_index);
int Ai_EvalAbility_ColorIdentity(int player, int card_index);
bool Ai_Subsystem_004b67ab(int arg1, int arg2);
bool Ai_EvalAbility_StealCreature(int player, int card_index);
void Ai_Subsystem_004b68b3(int arg1, int arg2, char * arg3);
void Ai_Subsystem_004b69ba(int arg1, int arg2, char * arg3);
int Ai_Subsystem_004b6ba8(int arg1, int arg2, void * arg3);
int Ai_Subsystem_004b6c5b(int arg1, int arg2);
int Ai_Subsystem_004b6cc8(int arg1, int arg2);
int Ai_Subsystem_004b6d35(int arg1, int arg2);
void Ai_Subsystem_004b6da5(int * arg1, int arg2, int arg3);
int Ai_Subsystem_004b6e3b(int arg1, int arg2);
int Ai_Subsystem_004b6eab(int arg1, int arg2);
int Ai_Util_004b6f19(int arg1);
void Ai_Subsystem_004b6f49(char * prompt_text);
int Ai_Subsystem_004b6fa6(int arg1);
int Ai_Subsystem_004b700c(int arg1);
int Ai_Subsystem_004b7072(void * arg1, int arg2);
int Ai_Subsystem_004b70fe(void * arg1, int arg2, int arg3);
int Ai_Subsystem_004b718a(void * arg1, int arg2);
int Ai_Subsystem_004b722d(void * arg1, int arg2);
int Ai_Subsystem_004b72d0(void * arg1, int arg2);
int Ai_Subsystem_004b7373(void * arg1);
void Ai_Duel_CalculateLayout(int x, int * y, int width, int * height);
void Ai_Subsystem_004b74b1(int * arg1, int * arg2);
void Ai_Subsystem_004b74fa(void * arg1, int arg2);
void Ai_Subsystem_004b756f(int * arg1);
int Ai_Subsystem_004b75a4(void);
bool Ai_Subsystem_004b75d8(int * arg1);
int Ai_Subsystem_004b7629(void);
void Ai_Subsystem_004b765d(int * arg1, int * arg2);
int Ai_Subsystem_004b76a6(void * arg1, int y, int width, int height);
void Ai_Subsystem_004b784d(int arg1, int arg2);
int Ai_CalcManaRequirement_Colorless(HWND player, uint32_t color_index, HDC required_amount, int * arg4);
int Ai_Subsystem_004b7d38(char * prompt_text);
HBRUSH Ai_WndProc_004b7de8(HWND hwnd, uint32_t uMsg, HDC wParam, HWND lParam);
void Ai_Util_004b82ea(int * arg1, int * arg2);
void Ai_Util_004b830e(HGDIOBJ arg1);
int Ai_Subsystem_004b832d(int arg1, int arg2, int arg3, int arg4, int * arg5, int * arg6, int * arg7);
HBRUSH Ai_WndProc_004b8421(HWND hwnd, uint32_t uMsg, HWND wParam, HWND lParam);
void CardScript_Fireball(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7);
void Ai_Subsystem_004b8da0(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4);
int Ai_Subsystem_004b8dfd(int arg1, int arg2);
char * Ai_FormatCardScoreString(int arg1, int arg2);
void Ai_Subsystem_004b90de(int arg1, int arg2);
int Ai_CalcManaRequirement_MultiColor(LPCSTR player);
void Ai_Subsystem_004b920e(void);
LRESULT Ai_CalcManaRequirement_General(HWND player, uint32_t color_index, char * required_amount, uint32_t arg4);
void Ai_WndProc_004ba6b6(LPRECT lprect, HWND hwnd_target, int wParam);
int Ai_CalcManaRequirement_PayCost(int player, int color_index, int required_amount);
void Ai_Subsystem_004bb9f3(int x, int arg2, int * arg3, int height);
void Ai_Subsystem_004bbb99(int arg1, int arg2, int * arg3, int arg4, int * arg5, int arg6);
void Ai_Subsystem_004bbd93(int arg1, int arg2, int * arg3, int arg4, int * arg5, int arg6);
int Ai_Subsystem_004bbf8e(int arg1, int arg2, int arg3);
int Ai_Subsystem_004bc029(int spell_id, int * target_id, int flags, int height);
int Ai_CalcMana_004bc423(void);
int Ai_Subsystem_004bc72e(int arg1, int arg2, int arg3, int arg4, int arg5);
int Ai_Subsystem_004bd035(int arg1, int arg2, uint8_t arg3);
int Ai_Subsystem_004bd23f(int arg1, int arg2);
void Ai_Subsystem_004bd3e9(int arg1, int arg2, int arg3, int * arg4, int arg5, int arg6, int arg7, int arg8, int * arg9);
int Ai_Subsystem_004bd459(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
int Ai_Subsystem_004bd4f0(void);
bool Ai_Subsystem_004bd563(int arg1, int arg2);
bool Ai_Util_CheckTimer(void);
int Ai_Subsystem_004bd5e3(int arg1);
int Ai_Subsystem_004bd682(int arg1);
int Ai_Subsystem_004bd6f9(int arg1, uint32_t arg2, int arg3);
int Ai_Subsystem_004be192(int x, int y, int width, int height);
void Ai_Util_004be240(void);
void Ai_Subsystem_004be25f(int arg1, int arg2, int arg3, int arg4, int arg5);
void Ai_Subsystem_004be357(void);
void Ai_Subsystem_004be3c4(int * arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
void Ai_Subsystem_004be43f(int x, int y, int * width, int * height);
void Ai_Subsystem_004be49b(int x, int y, int * width, int * height);
void Ai_Subsystem_004be525(int x, int y, int * width, int * height);
void Ai_Subsystem_004be5ae(int x, int y, int * width, int * height);
void Ai_Subsystem_004be643(int arg1, int arg2, int arg3);
void Ai_Subsystem_004bf23a(void);
void Ai_CalcMana_004bf4b3(int player);
void Ai_CalcMana_004c003d(void);
void Overworld_LoadAdventureInterface800(void);
void Ai_Subsystem_004c06df(uint32_t arg1, uint32_t arg2);
void Ai_Subsystem_004c0efe(uint32_t arg1, uint32_t arg2, int arg3, int arg4, uint32_t arg5, int arg6, int arg7, int arg8);
int Ai_Simulate_EvaluateMoveTree(int arg1, int arg2);
int Sound_Play_Button2(int arg1);
int Ai_Subsystem_004c22a2(int x, int y, int width, uint8_t * arg4);
void Ai_Subsystem_004c2340(int * arg1, int arg2, int arg3, int arg4, int arg5, uint32_t arg6, int arg7);
void Overworld_LoadMapScreenPics(int arg1);
void Ai_Subsystem_004c3aa1(int x, int y, int * width, int * height);
void Ai_Subsystem_004c3ad4(int x, int y, int * width, int * height);
void Ai_Subsystem_004c3b19(uint32_t arg1);
int Ai_Util_004c3ba3(int arg1);
int Ai_Util_004c3bc4(int arg1);
int Ai_Subsystem_004c3be5(int arg1, int arg2);
void Ai_Subsystem_004c3c5c(int arg1);
void Ai_Subsystem_004c4210(int arg1);
void Ai_Subsystem_004c4c84(int arg1);
uint32_t Ai_Subsystem_004c5fc9(int arg1);
void Ai_Subsystem_004c7aa8(int arg1);
void Ai_Subsystem_004c7be5(int arg1, int arg2);
int Ai_Subsystem_004c7d69(void);
void Ai_EvalAttackCandidate_General(uint32_t player);
int Ai_Subsystem_004c9f3a(int arg1, uint32_t arg2);
int Ai_Overworld_EvaluateEncounterThreat(int arg1);
void Ai_Subsystem_004ca07b(void);
void Ai_Subsystem_004ca0d9(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int * arg7, int * arg8);
void Ai_Subsystem_004ca714(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int * arg7, int * arg8);
void Ai_Subsystem_004cab92(void);
void Ai_Subsystem_004cad65(int arg1, int arg2, int arg3);
void Ai_Subsystem_004cadc5(int arg1, int arg2, int arg3);
void Ai_Util_004cae25(WPARAM arg1);
int Ai_Subsystem_004cae47(int arg1, int arg2);
int Ai_Subsystem_004cb04d(int arg1, int arg2);
int Ai_Subsystem_004cb1d6(int arg1, int arg2);
int Ai_Util_004cb2d0(void);
uint32_t Ai_Subsystem_004cbad0(int arg1, int arg2);
int Ai_Util_004cbb04(int arg1, int arg2);
uint32_t Ai_Subsystem_004cbb33(int arg1, int arg2);
int Ai_Util_004cbba7(int arg1, int arg2);
int Ai_Util_004cbbd7(int arg1, int arg2);
int Ai_Util_004cbc07(int arg1, int arg2);
int Ai_Util_004cbc36(int arg1, int arg2);
int Ai_Subsystem_004cbc65(int arg1, int arg2);
int Ai_Overworld_ChooseRoamDirection(int player);
int CardIDFromType(uint32_t arg1);
uint32_t Ai_Util_004cbda9(uint32_t arg1);
void Ai_Subsystem_004cbdda(int arg1, int arg2);
bool Ai_Subsystem_004cbe10(int arg1, int arg2);
uint8_t Ai_Subsystem_004cbe57(int arg1, int arg2);
undefined8 Ai_Subsystem_004cbf72(int arg1, int arg2);
int Ai_Subsystem_004cbfd0(int arg1, int arg2, int * arg3);
uint8_t Ai_Subsystem_004cc053(int arg1, int arg2);
int Ai_Util_004cc0c7(int arg1, int arg2);
int Ai_Util_004cc0f7(int arg1, int arg2);
int Ai_Subsystem_004cc127(int arg1, int arg2);
int Ai_Util_004cc188(int arg1, int arg2);
int Ai_Util_004cc1b8(int arg1, int arg2);
char * Ai_Subsystem_004cc1e8(int arg1, int arg2);
int Ai_Subsystem_004cc25b(int arg1, int arg2);
int Ai_Subsystem_004cc2cc(int arg1, int arg2);
int Ai_Subsystem_004cc33d(int arg1, int arg2, int arg3);
int Ai_Subsystem_004cc3c4(int arg1, int arg2);
void Ai_Subsystem_004cc3f8(int arg1, int arg2, int arg3, int arg4);
void Ai_Overworld_LogAction(char * prompt_text);
int Ai_Subsystem_004cc455(int * arg1, int arg2, int arg3, int arg4, char * str_5);
int Ai_Subsystem_004cc49a(int * arg1, int arg2, int arg3, int arg4, int arg5, char * str_6);
void Ai_Util_004cc4e1(int arg1);
void Ai_Subsystem_004cc50a(int arg1, int arg2, char * str_3);
int Ai_Deck_SelectStartingHand(int arg1, int arg2, int arg3, int arg4, int arg5, char * str_6, int arg7);
void Ai_Subsystem_004cc7c5(int arg1, int arg2);
INT_PTR Ai_Subsystem_004cc814(int arg1, char * output_str, INT_PTR arg3, char * str_4, char * str_5, char * str_6);
INT_PTR Ai_Subsystem_004cc87f(int arg1, char * output_str, INT_PTR arg3);
INT_PTR Ai_Subsystem_004cc8de(int arg1, char * output_str, INT_PTR arg3);
int Ai_Subsystem_004cc93d(int arg1, int arg2, int arg3, int arg4, uint32_t arg5);
void Ai_Subsystem_004cc97e(char * prompt_text);
void Ai_Turn_ExecuteMainPhase(int arg1, int arg2);
void Ai_Subsystem_004ccca3(void);
void Ai_Subsystem_004cced8(void);
void Ai_Subsystem_004cd14f(int arg1);
void Ai_Subsystem_004cd198(void);
int Ai_Subsystem_004cd1d1(void);
int Pic_Load_Title(void);
void Ai_Subsystem_004cd3eb(void);

/* ========================================================================= */
/* Backward Compatibility Aliases for Legacy Decompiled Symbols             */
/* ========================================================================= */

#define Ai_004aa830 Ai_SaveGameState
#define Ai_004aaaea Ai_RestoreGameState
#define Ai_004aad61 Ai_PushBoardState
#define Ai_004aafa8 Ai_PopBoardState
#define Ai_004ab1ef Ai_ClearPlan
#define Ai_004ab214 Ai_BeginTrial
#define Ai_004ab28b Ai_RecordChoice
#define Ai_004ab35e Ai_GetOpponentPlayerScore
#define Ai_004ab3a9 Ai_CalcLifeAdvantage
#define Ai_004ab3f3 Ai_ReplayChoice
#define Ai_004ab45f Ai_CommitBestPlan
#define Ai_004ab510 Ai_Score_ClearCache
#define Ai_004ab525 Ai_Score_SetValidityFlag
#define Ai_004ab552 Ai_EvaluateBoard
#define Ai_004abff4 Ai_PenalizeCounterattack
#define Ai_004ac940 Ai_ChooseBlockers
#define Ai_004acb7f Ai_FilterValidBlockers
#define Ai_004acc20 Duel_ShowStartOfDuelDialog
#define Ai_004ace3a Ai_DuelDialogProc
#define Ai_004ad6c5 Ai_LoadStartDuel2Backdrop
#define Ai_004ad77b Ai_StartDuel_InitContext
#define Ai_004ad7c8 Ai_StartDuelWndProc
#define Ai_004ae632 Ai_LoadStartDuelBackdrop
#define Ai_004ae716 Ai_Duel_ResetBuffers
#define Ai_004ae779 Ai_Duel_SetupSurfaces
#define Ai_004ae8a3 Ai_Duel_RenderBackdrop
#define Ai_004ae995 Ai_DuelMainWndProc
#define Ai_004af4fd Ai_LoadEndDuelBackdrop
#define Ai_004af5e3 Ai_EndDuel_ShowResult
#define Ai_004af640 Ai_EndDuel_ProcessRewards
#define Ai_004af765 Ai_EndDuel_Cleanup
#define Ai_004afa46 Ai_Score_InitRegister
#define Ai_004afa69 Ai_ScoreCardPlay_Creature
#define Ai_004afc26 Ai_ScoreCardPlay_Spell
#define Ai_004b0d24 Ai_ScoreCardPlay_Enchantment
#define Ai_004b0e11 Ai_ScoreCardPlay_Artifact
#define Ai_004b0e80 Ai_ScoreDialog_WndProc
#define Ai_004b128e Ai_CalcMana_ResetPool
#define Ai_004b137d Ai_CalcMana_AddSource
#define Ai_004b1406 Ai_CalcMana_ClearAvailable
#define Ai_004b1416 Ai_ManaSelection_DialogProc
#define Ai_004b15df Ai_TargetSelection_DialogProc
#define Ai_004b1974 Ai_Target_HighlightCandidate
#define Ai_004b19d0 Ai_AttackSelection_DialogProc
#define Ai_004b1b38 Ai_Attack_ToggleAttacker
#define Ai_004b1b9b Ai_BlockSelection_DialogProc
#define Ai_004b20e5 Ai_Block_AssignPair
#define Ai_004b2183 Ai_LoadQuestPromptBackdrop
#define Ai_004b2260 Ai_Quest_FormatPromptText
#define Ai_004b22bd Ai_Quest_ProcessChoice
#define Ai_004b257c Ai_Quest_DialogProc
#define Ai_004b32d1 Ai_CalcManaRequirement_Black
#define Ai_004b34fe Ai_CalcManaRequirement_Blue
#define Ai_004b35b4 Ai_CalcManaRequirement_Green
#define Ai_004b3777 Ai_CalcManaRequirement_Red
#define Ai_004b3847 Ai_CalcManaRequirement_White
#define Ai_004b4197 Ai_LoadChangeTextBackdrop
#define Ai_004b4274 Ai_ChangeText_FormatOptions
#define Ai_004b42d1 Ai_ChangeText_ResetState
#define Ai_004b42dc Ai_ChangeText_ApplyWord
#define Ai_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define Ai_004b53a1 Ai_Eval_ClearCandidateBuffer
#define Ai_004b53c6 Ai_Eval_GetCandidateScore
#define Ai_004b53ed Ai_Eval_SetCandidateScore
#define Ai_004b542d Ai_Eval_GetBestCandidate
#define Ai_004b543d Ai_Eval_ResetBestCandidate
#define Ai_004b544d Ai_Eval_SortCandidates
#define Ai_004b5501 Ai_EvalAbility_Flying
#define Ai_004b553f Ai_EvalAbility_Trample
#define Ai_004b574d Ai_EvalAbility_FirstStrike
#define Ai_004b584e Ai_EvalAbility_Regeneration
#define Ai_004b58d9 Ai_EvalAbility_Protection
#define Ai_004b5919 Ai_EvalAbility_Landwalk
#define Ai_004b5967 Ai_EvalAbility_Deathtouch
#define Ai_004b59d9 Ai_EvalAbility_DirectDamage
#define Ai_004b5a46 Ai_EvalAbility_Removal
#define Ai_004b5ab8 Ai_EvalAbility_Counterspell
#define Ai_004b5b6f Ai_EvalAbility_CardDraw
#define Ai_004b5bdd Ai_EvalAbility_Displacement
#define Ai_004b5c4b Ai_EvalAbility_LifeGain
#define Ai_004b5cbb Ai_EvalAbility_Disenchant
#define Ai_004b5d2e Ai_EvalAbility_BoardWipe
#define Ai_004b5de4 Ai_EvalAbility_LandDestruction
#define Ai_004b5f74 Ai_EvalAbility_ManaRamp
#define Ai_004b6023 Ai_EvalAbility_Tapping
#define Ai_004b613b Ai_EvalAbility_Discard
#define Ai_004b61ac Ai_EvalAbility_PumpSpell
#define Ai_004b621a Ai_EvalAbility_Haste
#define Ai_004b6288 Ai_EvalAbility_Vigilance
#define Ai_004b6356 Ai_EvalAbility_Defender
#define Ai_004b63c4 Ai_EvalAbility_PingDamage
#define Ai_004b6432 Ai_EvalAbility_Recursion
#define Ai_004b649f Ai_EvalAbility_TokenGeneration
#define Ai_004b650c Ai_EvalAbility_SacrificeOutlet
#define Ai_004b65ad Ai_Eval_ClearAbilityTable
#define Ai_004b65bf Ai_EvalAbility_DamagePrevention
#define Ai_004b6623 Ai_EvalAbility_PowerMod
#define Ai_004b6696 Ai_EvalAbility_ToughnessMod
#define Ai_004b673e Ai_EvalAbility_ColorIdentity
#define Ai_004b67ab Ai_Subsystem_004b67ab
#define Ai_004b682f Ai_EvalAbility_StealCreature
#define Ai_004b68b3 Ai_Subsystem_004b68b3
#define Ai_004b69ba Ai_Subsystem_004b69ba
#define Ai_004b6ba8 Ai_Subsystem_004b6ba8
#define Ai_004b6c5b Ai_Subsystem_004b6c5b
#define Ai_004b6cc8 Ai_Subsystem_004b6cc8
#define Ai_004b6d35 Ai_Subsystem_004b6d35
#define Ai_004b6da5 Ai_Subsystem_004b6da5
#define Ai_004b6e3b Ai_Subsystem_004b6e3b
#define Ai_004b6eab Ai_Subsystem_004b6eab
#define Ai_004b6f19 Ai_Util_004b6f19
#define Ai_004b6f49 Ai_Subsystem_004b6f49
#define Ai_004b6fa6 Ai_Subsystem_004b6fa6
#define Ai_004b700c Ai_Subsystem_004b700c
#define Ai_004b7072 Ai_Subsystem_004b7072
#define Ai_004b70fe Ai_Subsystem_004b70fe
#define Ai_004b718a Ai_Subsystem_004b718a
#define Ai_004b722d Ai_Subsystem_004b722d
#define Ai_004b72d0 Ai_Subsystem_004b72d0
#define Ai_004b7373 Ai_Subsystem_004b7373
#define Ai_004b73ce Ai_Duel_CalculateLayout
#define Ai_004b74b1 Ai_Subsystem_004b74b1
#define Ai_004b74fa Ai_Subsystem_004b74fa
#define Ai_004b756f Ai_Subsystem_004b756f
#define Ai_004b75a4 Ai_Subsystem_004b75a4
#define Ai_004b75d8 Ai_Subsystem_004b75d8
#define Ai_004b7629 Ai_Subsystem_004b7629
#define Ai_004b765d Ai_Subsystem_004b765d
#define Ai_004b76a6 Ai_Subsystem_004b76a6
#define Ai_004b784d Ai_Subsystem_004b784d
#define Ai_004b7897 Ai_CalcManaRequirement_Colorless
#define Ai_004b7d38 Ai_Subsystem_004b7d38
#define Ai_004b7de8 Ai_WndProc_004b7de8
#define Ai_004b82ea Ai_Util_004b82ea
#define Ai_004b830e Ai_Util_004b830e
#define Ai_004b832d Ai_Subsystem_004b832d
#define Ai_004b8421 Ai_WndProc_004b8421
#define Ai_004b8cc3 CardScript_Fireball
#define Ai_004b8da0 Ai_Subsystem_004b8da0
#define Ai_004b8dfd Ai_Subsystem_004b8dfd
#define Ai_004b8e4d Ai_FormatCardScoreString
#define Ai_004b90de Ai_Subsystem_004b90de
#define UI_Register_WINBK_ManaPool_004b9120 Ai_CalcManaRequirement_MultiColor
#define Ai_004b920e Ai_Subsystem_004b920e
#define Ai_004b9284 Ai_CalcManaRequirement_General
#define Ai_004ba6b6 Ai_WndProc_004ba6b6
#define Ai_004ba890 Ai_CalcManaRequirement_PayCost
#define Ai_004bb9f3 Ai_Subsystem_004bb9f3
#define Ai_004bbb99 Ai_Subsystem_004bbb99
#define Ai_004bbd93 Ai_Subsystem_004bbd93
#define Ai_004bbf8e Ai_Subsystem_004bbf8e
#define Ai_004bc029 Ai_Subsystem_004bc029
#define Ai_004bc423 Ai_CalcMana_004bc423
#define Ai_004bc72e Ai_Subsystem_004bc72e
#define Ai_004bd035 Ai_Subsystem_004bd035
#define Ai_004bd23f Ai_Subsystem_004bd23f
#define Ai_004bd3e9 Ai_Subsystem_004bd3e9
#define Ai_004bd459 Ai_Subsystem_004bd459
#define Ai_004bd4f0 Ai_Subsystem_004bd4f0
#define Ai_004bd563 Ai_Subsystem_004bd563
#define Ai_004bd5af Ai_Util_CheckTimer
#define Ai_004bd5e3 Ai_Subsystem_004bd5e3
#define Ai_004bd682 Ai_Subsystem_004bd682
#define Ai_004bd6f9 Ai_Subsystem_004bd6f9
#define Ai_004be192 Ai_Subsystem_004be192
#define Ai_004be240 Ai_Util_004be240
#define Ai_004be25f Ai_Subsystem_004be25f
#define Ai_004be357 Ai_Subsystem_004be357
#define Ai_004be3c4 Ai_Subsystem_004be3c4
#define Ai_004be43f Ai_Subsystem_004be43f
#define Ai_004be49b Ai_Subsystem_004be49b
#define Ai_004be525 Ai_Subsystem_004be525
#define Ai_004be5ae Ai_Subsystem_004be5ae
#define Ai_004be643 Ai_Subsystem_004be643
#define Ai_004bf23a Ai_Subsystem_004bf23a
#define Ai_004bf4b3 Ai_CalcMana_004bf4b3
#define Ai_004c003d Ai_CalcMana_004c003d
#define Ai_004c05ba Overworld_LoadAdventureInterface800
#define Ai_004c06df Ai_Subsystem_004c06df
#define Ai_004c0efe Ai_Subsystem_004c0efe
#define Ai_004c207a Ai_Simulate_EvaluateMoveTree
#define Ai_004c2270 Sound_Play_Button2
#define Ai_004c22a2 Ai_Subsystem_004c22a2
#define Ai_004c2340 Ai_Subsystem_004c2340
#define Ai_004c24b3 Overworld_LoadMapScreenPics
#define Ai_004c3aa1 Ai_Subsystem_004c3aa1
#define Ai_004c3ad4 Ai_Subsystem_004c3ad4
#define Ai_004c3b19 Ai_Subsystem_004c3b19
#define Ai_004c3ba3 Ai_Util_004c3ba3
#define Ai_004c3bc4 Ai_Util_004c3bc4
#define Ai_004c3be5 Ai_Subsystem_004c3be5
#define Ai_004c3c5c Ai_Subsystem_004c3c5c
#define Ai_004c4210 Ai_Subsystem_004c4210
#define Ai_004c4c84 Ai_Subsystem_004c4c84
#define Ai_004c5fc9 Ai_Subsystem_004c5fc9
#define Ai_004c7aa8 Ai_Subsystem_004c7aa8
#define Ai_004c7be5 Ai_Subsystem_004c7be5
#define Ai_004c7d69 Ai_Subsystem_004c7d69
#define Ai_004c864d Ai_EvalAttackCandidate_General
#define Ai_004c9f3a Ai_Subsystem_004c9f3a
#define Ai_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define Ai_004ca07b Ai_Subsystem_004ca07b
#define Ai_004ca0d9 Ai_Subsystem_004ca0d9
#define Ai_004ca714 Ai_Subsystem_004ca714
#define Ai_004cab92 Ai_Subsystem_004cab92
#define Ai_004cad65 Ai_Subsystem_004cad65
#define Ai_004cadc5 Ai_Subsystem_004cadc5
#define Ai_004cae25 Ai_Util_004cae25
#define Ai_004cae47 Ai_Subsystem_004cae47
#define Ai_004cb04d Ai_Subsystem_004cb04d
#define Ai_004cb1d6 Ai_Subsystem_004cb1d6
#define Ai_004cb2d0 Ai_Util_004cb2d0
#define Ai_004cbad0 Ai_Subsystem_004cbad0
#define Ai_004cbb04 Ai_Util_004cbb04
#define Ai_004cbb33 Ai_Subsystem_004cbb33
#define Ai_004cbba7 Ai_Util_004cbba7
#define Ai_004cbbd7 Ai_Util_004cbbd7
#define Ai_004cbc07 Ai_Util_004cbc07
#define Ai_004cbc36 Ai_Util_004cbc36
#define Ai_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define Ai_004cbda9 Ai_Util_004cbda9
#define Ai_004cbdda Ai_Subsystem_004cbdda
#define Ai_004cbe10 Ai_Subsystem_004cbe10
#define Ai_004cbe57 Ai_Subsystem_004cbe57
#define Ai_004cbf72 Ai_Subsystem_004cbf72
#define Ai_004cbfd0 Ai_Subsystem_004cbfd0
#define Ai_004cc053 Ai_Subsystem_004cc053
#define Ai_004cc0c7 Ai_Util_004cc0c7
#define Ai_004cc0f7 Ai_Util_004cc0f7
#define Ai_004cc127 Ai_Subsystem_004cc127
#define Ai_004cc188 Ai_Util_004cc188
#define Ai_004cc1b8 Ai_Util_004cc1b8
#define Ai_004cc1e8 Ai_Subsystem_004cc1e8
#define Ai_004cc25b Ai_Subsystem_004cc25b
#define Ai_004cc2cc Ai_Subsystem_004cc2cc
#define Ai_004cc33d Ai_Subsystem_004cc33d
#define Ai_004cc3c4 Ai_Subsystem_004cc3c4
#define Ai_004cc3f8 Ai_Subsystem_004cc3f8
#define Ai_004cc42d Ai_Overworld_LogAction
#define Ai_004cc455 Ai_Subsystem_004cc455
#define Ai_004cc49a Ai_Subsystem_004cc49a
#define Ai_004cc4e1 Ai_Util_004cc4e1
#define Ai_004cc50a Ai_Subsystem_004cc50a
#define Ai_004cc56d Ai_Deck_SelectStartingHand
#define Ai_004cc7c5 Ai_Subsystem_004cc7c5
#define Ai_004cc814 Ai_Subsystem_004cc814
#define Ai_004cc87f Ai_Subsystem_004cc87f
#define Ai_004cc8de Ai_Subsystem_004cc8de
#define Ai_004cc93d Ai_Subsystem_004cc93d
#define Ai_004cc97e Ai_Subsystem_004cc97e
#define Ai_004cc9c5 Ai_Turn_ExecuteMainPhase
#define Ai_004ccca3 Ai_Subsystem_004ccca3
#define Ai_004cced8 Ai_Subsystem_004cced8
#define Ai_004cd14f Ai_Subsystem_004cd14f
#define Ai_004cd198 Ai_Subsystem_004cd198
#define Ai_004cd1d1 Ai_Subsystem_004cd1d1
#define Ai_004cd20e Pic_Load_Title
#define Ai_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_CalcManaRequirement_004b32d1 Ai_CalcManaRequirement_Black
#define Ai_CalcManaRequirement_004b7897 Ai_CalcManaRequirement_Colorless
#define UI_Register_WINBK_ManaPool_004b9120 Ai_CalcManaRequirement_MultiColor
#define Ai_CalcManaRequirement_004b9284 Ai_CalcManaRequirement_General
#define Ai_CalcManaRequirement_004ba890 Ai_CalcManaRequirement_PayCost
#define Ai_CalcManaRequirement_004bc423 Ai_CalcMana_004bc423
#define Ai_CalcManaRequirement_004bf4b3 Ai_CalcMana_004bf4b3
#define Ai_CalcManaRequirement_004c003d Ai_CalcMana_004c003d
#define Ai_CastleEncounter_004c0efe Ai_Subsystem_004c0efe
#define Ai_CastleEncounter_004c24b3 Overworld_LoadMapScreenPics
#define Duel_RefreshAllWindows Ai_EvalAttackCandidate_CombatTrade
#define Combat_ResolveBlocksAndDamage Ai_EvalAttackCandidate_General
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define Ai_Subsystem_004b0d24 Ai_ScoreCardPlay_Enchantment
#define Ai_Subsystem_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define Ai_Subsystem_004b128e Ai_CalcMana_ResetPool
#define Ai_Subsystem_004b137d Ai_CalcMana_AddSource
#define Ai_Subsystem_004b1406 Ai_CalcMana_ClearAvailable
#define Ai_Subsystem_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define Ai_Subsystem_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define Ai_Subsystem_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define Ai_Subsystem_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define Ai_Subsystem_004b2260 Ai_Quest_FormatPromptText
#define Ai_Subsystem_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define Ai_Subsystem_004b34fe Ai_CalcManaRequirement_Blue
#define Ai_Subsystem_004b35b4 Ai_CalcManaRequirement_Green
#define Ai_Subsystem_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define Ai_Subsystem_004b4274 Ai_ChangeText_FormatOptions
#define Ai_Subsystem_004b42d1 Ai_ChangeText_ResetState
#define Ai_Subsystem_004b42dc Ai_ChangeText_ApplyWord
#define Ai_Subsystem_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define Ai_Subsystem_004b53a1 Ai_Eval_ClearCandidateBuffer
#define Ai_Subsystem_004b53c6 Ai_Eval_GetCandidateScore
#define Ai_Subsystem_004b53ed Ai_Eval_SetCandidateScore
#define Ai_Subsystem_004b542d Ai_Eval_GetBestCandidate
#define Ai_Subsystem_004b543d Ai_Eval_ResetBestCandidate
#define Ai_Subsystem_004b544d Ai_Eval_SortCandidates
#define Ai_Subsystem_004b5501 Ai_EvalAbility_Flying
#define Ai_Subsystem_004b553f Ai_EvalAbility_Trample
#define Ai_Subsystem_004b574d Ai_EvalAbility_FirstStrike
#define Ai_Subsystem_004b584e Ai_EvalAbility_Regeneration
#define Ai_Subsystem_004b58d9 Ai_EvalAbility_Protection
#define Ai_Subsystem_004b5919 Ai_EvalAbility_Landwalk
#define Ai_Subsystem_004b5967 Ai_EvalAbility_Deathtouch
#define Ai_Subsystem_004b59d9 Ai_EvalAbility_DirectDamage
#define Ai_Subsystem_004b5a46 Ai_EvalAbility_Removal
#define Ai_Subsystem_004b5ab8 Ai_EvalAbility_Counterspell
#define Ai_Subsystem_004b5b6f Ai_EvalAbility_CardDraw
#define Ai_Subsystem_004b5bdd Ai_EvalAbility_Displacement
#define Ai_Subsystem_004b5c4b Ai_EvalAbility_LifeGain
#define Ai_Subsystem_004b5cbb Ai_EvalAbility_Disenchant
#define Ai_Subsystem_004b5d2e Ai_EvalAbility_BoardWipe
#define Ai_Subsystem_004b5de4 Ai_EvalAbility_LandDestruction
#define Ai_Subsystem_004b5f74 Ai_EvalAbility_ManaRamp
#define Ai_Subsystem_004b6023 Ai_EvalAbility_Tapping
#define Ai_Subsystem_004b613b Ai_EvalAbility_Discard
#define Ai_Subsystem_004b61ac Ai_EvalAbility_PumpSpell
#define Ai_Subsystem_004b621a Ai_EvalAbility_Haste
#define Ai_Subsystem_004b6288 Ai_EvalAbility_Vigilance
#define Ai_Subsystem_004b6356 Ai_EvalAbility_Defender
#define Ai_Subsystem_004b63c4 Ai_EvalAbility_PingDamage
#define Ai_Subsystem_004b6432 Ai_EvalAbility_Recursion
#define Ai_Subsystem_004b649f Ai_EvalAbility_TokenGeneration
#define Ai_Subsystem_004b650c Ai_EvalAbility_SacrificeOutlet
#define Ai_Subsystem_004b65ad Ai_Eval_ClearAbilityTable
#define Ai_Subsystem_004b65bf Ai_EvalAbility_DamagePrevention
#define Ai_Subsystem_004b6623 Ai_EvalAbility_PowerMod
#define Ai_Subsystem_004b6696 Ai_EvalAbility_ToughnessMod
#define Ai_Subsystem_004b673e Ai_EvalAbility_ColorIdentity
#define Ai_Subsystem_004b682f Ai_EvalAbility_StealCreature
#define Ai_Subsystem_004b6f19 Ai_Util_004b6f19
#define Ai_Subsystem_004b73ce Ai_Duel_CalculateLayout
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define Ai_Subsystem_004b82ea Ai_Util_004b82ea
#define Ai_Subsystem_004b830e Ai_Util_004b830e
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define Ai_Subsystem_004b8e4d Ai_FormatCardScoreString
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define Ai_Subsystem_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define Ai_Subsystem_004bc423 Ai_CalcMana_004bc423
#define Ai_Subsystem_004bd5af Ai_Util_CheckTimer
#define Ai_Subsystem_004be240 Ai_Util_004be240
#define Ai_Subsystem_004bf4b3 Ai_CalcMana_004bf4b3
#define Ai_Subsystem_004c003d Ai_CalcMana_004c003d
#define Ai_Subsystem_004c207a Ai_Simulate_EvaluateMoveTree
#define Ai_Subsystem_004c3ba3 Ai_Util_004c3ba3
#define Ai_Subsystem_004c3bc4 Ai_Util_004c3bc4
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define Ai_Subsystem_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define Ai_Subsystem_004cae25 Ai_Util_004cae25
#define Ai_Subsystem_004cb2d0 Ai_Util_004cb2d0
#define Ai_Subsystem_004cbb04 Ai_Util_004cbb04
#define Ai_Subsystem_004cbba7 Ai_Util_004cbba7
#define Ai_Subsystem_004cbbd7 Ai_Util_004cbbd7
#define Ai_Subsystem_004cbc07 Ai_Util_004cbc07
#define Ai_Subsystem_004cbc36 Ai_Util_004cbc36
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define Ai_Subsystem_004cbda9 Ai_Util_004cbda9
#define Ai_Subsystem_004cc0c7 Ai_Util_004cc0c7
#define Ai_Subsystem_004cc0f7 Ai_Util_004cc0f7
#define Ai_Subsystem_004cc188 Ai_Util_004cc188
#define Ai_Subsystem_004cc1b8 Ai_Util_004cc1b8
#define Ai_Subsystem_004cc42d Ai_Overworld_LogAction
#define Ai_Subsystem_004cc4e1 Ai_Util_004cc4e1
#define Ai_Subsystem_004cc56d Ai_Deck_SelectStartingHand
#define Ai_EvaluateTacticalPosition Ai_Turn_ExecuteMainPhase
#define Ai_TownEncounter_004c3b19 Ai_Subsystem_004c3b19
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define Ai_Util_004b0d24 Ai_ScoreCardPlay_Enchantment
#define Ai_Util_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define Ai_Util_004b128e Ai_CalcMana_ResetPool
#define Ai_Util_004b137d Ai_CalcMana_AddSource
#define Ai_Util_004b1406 Ai_CalcMana_ClearAvailable
#define Ai_Util_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define Ai_Util_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define Ai_Util_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define Ai_Util_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define Ai_Util_004b2260 Ai_Quest_FormatPromptText
#define Ai_Util_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define Ai_Util_004b34fe Ai_CalcManaRequirement_Blue
#define Ai_Util_004b35b4 Ai_CalcManaRequirement_Green
#define Ai_Util_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define Ai_Util_004b4274 Ai_ChangeText_FormatOptions
#define Ai_Util_004b42d1 Ai_ChangeText_ResetState
#define Ai_Util_004b42dc Ai_ChangeText_ApplyWord
#define Ai_Util_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define Ai_Util_004b53a1 Ai_Eval_ClearCandidateBuffer
#define Ai_Util_004b53c6 Ai_Eval_GetCandidateScore
#define Ai_Util_004b53ed Ai_Eval_SetCandidateScore
#define Ai_Util_004b542d Ai_Eval_GetBestCandidate
#define Ai_Util_004b543d Ai_Eval_ResetBestCandidate
#define Ai_Util_004b544d Ai_Eval_SortCandidates
#define Ai_Util_004b5501 Ai_EvalAbility_Flying
#define Ai_Util_004b553f Ai_EvalAbility_Trample
#define Ai_Util_004b574d Ai_EvalAbility_FirstStrike
#define Ai_Util_004b584e Ai_EvalAbility_Regeneration
#define Ai_Util_004b58d9 Ai_EvalAbility_Protection
#define Ai_Util_004b5919 Ai_EvalAbility_Landwalk
#define Ai_Util_004b5967 Ai_EvalAbility_Deathtouch
#define Ai_Util_004b59d9 Ai_EvalAbility_DirectDamage
#define Ai_Util_004b5a46 Ai_EvalAbility_Removal
#define Ai_Util_004b5ab8 Ai_EvalAbility_Counterspell
#define Ai_Util_004b5b6f Ai_EvalAbility_CardDraw
#define Ai_Util_004b5bdd Ai_EvalAbility_Displacement
#define Ai_Util_004b5c4b Ai_EvalAbility_LifeGain
#define Ai_Util_004b5cbb Ai_EvalAbility_Disenchant
#define Ai_Util_004b5d2e Ai_EvalAbility_BoardWipe
#define Ai_Util_004b5de4 Ai_EvalAbility_LandDestruction
#define Ai_Util_004b5f74 Ai_EvalAbility_ManaRamp
#define Ai_Util_004b6023 Ai_EvalAbility_Tapping
#define Ai_Util_004b613b Ai_EvalAbility_Discard
#define Ai_Util_004b61ac Ai_EvalAbility_PumpSpell
#define Ai_Util_004b621a Ai_EvalAbility_Haste
#define Ai_Util_004b6288 Ai_EvalAbility_Vigilance
#define Ai_Util_004b6356 Ai_EvalAbility_Defender
#define Ai_Util_004b63c4 Ai_EvalAbility_PingDamage
#define Ai_Util_004b6432 Ai_EvalAbility_Recursion
#define Ai_Util_004b649f Ai_EvalAbility_TokenGeneration
#define Ai_Util_004b650c Ai_EvalAbility_SacrificeOutlet
#define Ai_Util_004b65ad Ai_Eval_ClearAbilityTable
#define Ai_Util_004b65bf Ai_EvalAbility_DamagePrevention
#define Ai_Util_004b6623 Ai_EvalAbility_PowerMod
#define Ai_Util_004b6696 Ai_EvalAbility_ToughnessMod
#define Ai_Util_004b673e Ai_EvalAbility_ColorIdentity
#define Ai_Util_004b67ab Ai_Subsystem_004b67ab
#define Ai_Util_004b682f Ai_EvalAbility_StealCreature
#define Ai_Util_004b68b3 Ai_Subsystem_004b68b3
#define Ai_Util_004b69ba Ai_Subsystem_004b69ba
#define Ai_Util_004b6ba8 Ai_Subsystem_004b6ba8
#define Ai_Util_004b6c5b Ai_Subsystem_004b6c5b
#define Ai_Util_004b6cc8 Ai_Subsystem_004b6cc8
#define Ai_Util_004b6d35 Ai_Subsystem_004b6d35
#define Ai_Util_004b6da5 Ai_Subsystem_004b6da5
#define Ai_Util_004b6e3b Ai_Subsystem_004b6e3b
#define Ai_Util_004b6eab Ai_Subsystem_004b6eab
#define Ai_Util_004b6f49 Ai_Subsystem_004b6f49
#define Ai_Util_004b6fa6 Ai_Subsystem_004b6fa6
#define Ai_Util_004b700c Ai_Subsystem_004b700c
#define Ai_Util_004b7072 Ai_Subsystem_004b7072
#define Ai_Util_004b70fe Ai_Subsystem_004b70fe
#define Ai_Util_004b718a Ai_Subsystem_004b718a
#define Ai_Util_004b722d Ai_Subsystem_004b722d
#define Ai_Util_004b72d0 Ai_Subsystem_004b72d0
#define Ai_Util_004b7373 Ai_Subsystem_004b7373
#define Ai_Util_004b73ce Ai_Duel_CalculateLayout
#define Ai_Util_004b74b1 Ai_Subsystem_004b74b1
#define Ai_Util_004b74fa Ai_Subsystem_004b74fa
#define Ai_Util_004b756f Ai_Subsystem_004b756f
#define Ai_Util_004b75a4 Ai_Subsystem_004b75a4
#define Ai_Util_004b75d8 Ai_Subsystem_004b75d8
#define Ai_Util_004b7629 Ai_Subsystem_004b7629
#define Ai_Util_004b765d Ai_Subsystem_004b765d
#define Ai_Util_004b76a6 Ai_Subsystem_004b76a6
#define Ai_Util_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define Ai_Util_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define Ai_Util_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define Ai_Util_004b8da0 Ai_Subsystem_004b8da0
#define Ai_Util_004b8dfd Ai_Subsystem_004b8dfd
#define Ai_Util_004b8e4d Ai_FormatCardScoreString
#define Ai_Util_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define Ai_Util_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define Ai_Util_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define Ai_Util_004bb9f3 Ai_Subsystem_004bb9f3
#define Ai_Util_004bbb99 Ai_Subsystem_004bbb99
#define Ai_Util_004bbd93 Ai_Subsystem_004bbd93
#define Ai_Util_004bbf8e Ai_Subsystem_004bbf8e
#define Ai_Util_004bc029 Ai_Subsystem_004bc029
#define Ai_Util_004bc423 Ai_CalcMana_004bc423
#define Ai_Util_004bc72e Ai_Subsystem_004bc72e
#define Ai_Util_004bd035 Ai_Subsystem_004bd035
#define Ai_Util_004bd23f Ai_Subsystem_004bd23f
#define Ai_Util_004bd3e9 Ai_Subsystem_004bd3e9
#define Ai_Util_004bd459 Ai_Subsystem_004bd459
#define Ai_Util_004bd4f0 Ai_Subsystem_004bd4f0
#define Ai_Util_004bd563 Ai_Subsystem_004bd563
#define Ai_Util_004bd5af Ai_Util_CheckTimer
#define Ai_Util_004bd5e3 Ai_Subsystem_004bd5e3
#define Ai_Util_004bd682 Ai_Subsystem_004bd682
#define Ai_Util_004bd6f9 Ai_Subsystem_004bd6f9
#define Ai_Util_004be192 Ai_Subsystem_004be192
#define Ai_Util_004be25f Ai_Subsystem_004be25f
#define Ai_Util_004be357 Ai_Subsystem_004be357
#define Ai_Util_004be3c4 Ai_Subsystem_004be3c4
#define Ai_Util_004be43f Ai_Subsystem_004be43f
#define Ai_Util_004be49b Ai_Subsystem_004be49b
#define Ai_Util_004be525 Ai_Subsystem_004be525
#define Ai_Util_004be5ae Ai_Subsystem_004be5ae
#define Ai_Util_004be643 Ai_Subsystem_004be643
#define Ai_Util_004bf23a Ai_Subsystem_004bf23a
#define Ai_Util_004bf4b3 Ai_CalcMana_004bf4b3
#define Ai_Util_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define Ai_Util_004c06df Ai_Subsystem_004c06df
#define Ai_Util_004c0efe Ai_Subsystem_004c0efe
#define Ai_Util_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define Ai_Util_004c22a2 Ai_Subsystem_004c22a2
#define Ai_Util_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define Ai_Util_004c3aa1 Ai_Subsystem_004c3aa1
#define Ai_Util_004c3ad4 Ai_Subsystem_004c3ad4
#define Ai_Util_004c3b19 Ai_Subsystem_004c3b19
#define Ai_Util_004c3be5 Ai_Subsystem_004c3be5
#define Ai_Util_004c3c5c Ai_Subsystem_004c3c5c
#define Ai_Util_004c4210 Ai_Subsystem_004c4210
#define Ai_Util_004c4c84 Ai_Subsystem_004c4c84
#define Ai_Util_004c5fc9 Ai_Subsystem_004c5fc9
#define Ai_Util_004c7aa8 Ai_Subsystem_004c7aa8
#define Ai_Util_004c7be5 Ai_Subsystem_004c7be5
#define Ai_Util_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define Ai_Util_004c9f3a Ai_Subsystem_004c9f3a
#define Ai_Util_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define Ai_Util_004ca07b Ai_Subsystem_004ca07b
#define Ai_Util_004ca0d9 Ai_Subsystem_004ca0d9
#define Ai_Util_004ca714 Ai_Subsystem_004ca714
#define Ai_Util_004cab92 Ai_Subsystem_004cab92
#define Ai_Util_004cad65 Ai_Subsystem_004cad65
#define Ai_Util_004cadc5 Ai_Subsystem_004cadc5
#define Ai_Util_004cae47 Ai_Subsystem_004cae47
#define Ai_Util_004cb04d Ai_Subsystem_004cb04d
#define Ai_Util_004cb1d6 Ai_Subsystem_004cb1d6
#define Ai_Util_004cbad0 Ai_Subsystem_004cbad0
#define Ai_Util_004cbb33 Ai_Subsystem_004cbb33
#define Ai_Util_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define Ai_Util_004cbdda Ai_Subsystem_004cbdda
#define Ai_Util_004cbe10 Ai_Subsystem_004cbe10
#define Ai_Util_004cbe57 Ai_Subsystem_004cbe57
#define Ai_Util_004cbf72 Ai_Subsystem_004cbf72
#define Ai_Util_004cbfd0 Ai_Subsystem_004cbfd0
#define Ai_Util_004cc053 Ai_Subsystem_004cc053
#define Ai_Util_004cc127 Ai_Subsystem_004cc127
#define Ai_Util_004cc1e8 Ai_Subsystem_004cc1e8
#define Ai_Util_004cc25b Ai_Subsystem_004cc25b
#define Ai_Util_004cc2cc Ai_Subsystem_004cc2cc
#define Ai_Util_004cc33d Ai_Subsystem_004cc33d
#define Ai_Util_004cc3c4 Ai_Subsystem_004cc3c4
#define Ai_Util_004cc3f8 Ai_Subsystem_004cc3f8
#define Ai_Util_004cc42d Ai_Overworld_LogAction
#define Ai_Util_004cc455 Ai_Subsystem_004cc455
#define Ai_Util_004cc49a Ai_Subsystem_004cc49a
#define Ai_Util_004cc50a Ai_Subsystem_004cc50a
#define Ai_Util_004cc56d Ai_Deck_SelectStartingHand
#define Ai_Util_004cc7c5 Ai_Subsystem_004cc7c5
#define Ai_Util_004cc814 Ai_Subsystem_004cc814
#define Ai_Util_004cc87f Ai_Subsystem_004cc87f
#define Ai_Util_004cc8de Ai_Subsystem_004cc8de
#define Ai_Util_004cc93d Ai_Subsystem_004cc93d
#define Ai_Util_004cc97e Ai_Subsystem_004cc97e
#define Ai_Util_004cc9c5 Ai_Turn_ExecuteMainPhase
#define Ai_Util_004ccca3 Ai_Subsystem_004ccca3
#define Ai_Util_004cced8 Ai_Subsystem_004cced8
#define Ai_Util_004cd14f Ai_Subsystem_004cd14f
#define Ai_Util_004cd198 Ai_Subsystem_004cd198
#define Ai_Util_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define Ai_Util_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define FUN_004b0d24 Ai_ScoreCardPlay_Enchantment
#define FUN_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define FUN_004b128e Ai_CalcMana_ResetPool
#define FUN_004b137d Ai_CalcMana_AddSource
#define FUN_004b1406 Ai_CalcMana_ClearAvailable
#define FUN_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define FUN_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define FUN_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define FUN_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define FUN_004b2260 Ai_Quest_FormatPromptText
#define FUN_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define FUN_004b34fe Ai_CalcManaRequirement_Blue
#define FUN_004b35b4 Ai_CalcManaRequirement_Green
#define FUN_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define FUN_004b4274 Ai_ChangeText_FormatOptions
#define FUN_004b42d1 Ai_ChangeText_ResetState
#define FUN_004b42dc Ai_ChangeText_ApplyWord
#define FUN_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define FUN_004b53a1 Ai_Eval_ClearCandidateBuffer
#define FUN_004b53c6 Ai_Eval_GetCandidateScore
#define FUN_004b53ed Ai_Eval_SetCandidateScore
#define FUN_004b542d Ai_Eval_GetBestCandidate
#define FUN_004b543d Ai_Eval_ResetBestCandidate
#define FUN_004b544d Ai_Eval_SortCandidates
#define FUN_004b5501 Ai_EvalAbility_Flying
#define FUN_004b553f Ai_EvalAbility_Trample
#define FUN_004b574d Ai_EvalAbility_FirstStrike
#define FUN_004b584e Ai_EvalAbility_Regeneration
#define FUN_004b58d9 Ai_EvalAbility_Protection
#define FUN_004b5919 Ai_EvalAbility_Landwalk
#define FUN_004b5967 Ai_EvalAbility_Deathtouch
#define FUN_004b59d9 Ai_EvalAbility_DirectDamage
#define FUN_004b5a46 Ai_EvalAbility_Removal
#define FUN_004b5ab8 Ai_EvalAbility_Counterspell
#define FUN_004b5b6f Ai_EvalAbility_CardDraw
#define FUN_004b5bdd Ai_EvalAbility_Displacement
#define FUN_004b5c4b Ai_EvalAbility_LifeGain
#define FUN_004b5cbb Ai_EvalAbility_Disenchant
#define FUN_004b5d2e Ai_EvalAbility_BoardWipe
#define FUN_004b5de4 Ai_EvalAbility_LandDestruction
#define FUN_004b5f74 Ai_EvalAbility_ManaRamp
#define FUN_004b6023 Ai_EvalAbility_Tapping
#define FUN_004b613b Ai_EvalAbility_Discard
#define FUN_004b61ac Ai_EvalAbility_PumpSpell
#define FUN_004b621a Ai_EvalAbility_Haste
#define FUN_004b6288 Ai_EvalAbility_Vigilance
#define FUN_004b6356 Ai_EvalAbility_Defender
#define FUN_004b63c4 Ai_EvalAbility_PingDamage
#define FUN_004b6432 Ai_EvalAbility_Recursion
#define FUN_004b649f Ai_EvalAbility_TokenGeneration
#define FUN_004b650c Ai_EvalAbility_SacrificeOutlet
#define FUN_004b65ad Ai_Eval_ClearAbilityTable
#define FUN_004b65bf Ai_EvalAbility_DamagePrevention
#define FUN_004b6623 Ai_EvalAbility_PowerMod
#define FUN_004b6696 Ai_EvalAbility_ToughnessMod
#define FUN_004b673e Ai_EvalAbility_ColorIdentity
#define FUN_004b67ab Ai_Subsystem_004b67ab
#define FUN_004b682f Ai_EvalAbility_StealCreature
#define FUN_004b68b3 Ai_Subsystem_004b68b3
#define FUN_004b69ba Ai_Subsystem_004b69ba
#define FUN_004b6ba8 Ai_Subsystem_004b6ba8
#define FUN_004b6c5b Ai_Subsystem_004b6c5b
#define FUN_004b6cc8 Ai_Subsystem_004b6cc8
#define FUN_004b6d35 Ai_Subsystem_004b6d35
#define FUN_004b6da5 Ai_Subsystem_004b6da5
#define FUN_004b6e3b Ai_Subsystem_004b6e3b
#define FUN_004b6eab Ai_Subsystem_004b6eab
#define FUN_004b6f19 Ai_Util_004b6f19
#define FUN_004b6f49 Ai_Subsystem_004b6f49
#define FUN_004b6fa6 Ai_Subsystem_004b6fa6
#define FUN_004b700c Ai_Subsystem_004b700c
#define FUN_004b7072 Ai_Subsystem_004b7072
#define FUN_004b70fe Ai_Subsystem_004b70fe
#define FUN_004b718a Ai_Subsystem_004b718a
#define FUN_004b722d Ai_Subsystem_004b722d
#define FUN_004b72d0 Ai_Subsystem_004b72d0
#define FUN_004b7373 Ai_Subsystem_004b7373
#define FUN_004b73ce Ai_Duel_CalculateLayout
#define FUN_004b74b1 Ai_Subsystem_004b74b1
#define FUN_004b74fa Ai_Subsystem_004b74fa
#define FUN_004b756f Ai_Subsystem_004b756f
#define FUN_004b75a4 Ai_Subsystem_004b75a4
#define FUN_004b75d8 Ai_Subsystem_004b75d8
#define FUN_004b7629 Ai_Subsystem_004b7629
#define FUN_004b765d Ai_Subsystem_004b765d
#define FUN_004b76a6 Ai_Subsystem_004b76a6
#define FUN_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define FUN_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define FUN_004b82ea Ai_Util_004b82ea
#define FUN_004b830e Ai_Util_004b830e
#define FUN_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define FUN_004b8da0 Ai_Subsystem_004b8da0
#define FUN_004b8dfd Ai_Subsystem_004b8dfd
#define FUN_004b8e4d Ai_FormatCardScoreString
#define FUN_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define FUN_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define FUN_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define FUN_004bb9f3 Ai_Subsystem_004bb9f3
#define FUN_004bbb99 Ai_Subsystem_004bbb99
#define FUN_004bbd93 Ai_Subsystem_004bbd93
#define FUN_004bbf8e Ai_Subsystem_004bbf8e
#define FUN_004bc029 Ai_Subsystem_004bc029
#define FUN_004bc423 Ai_CalcMana_004bc423
#define FUN_004bc72e Ai_Subsystem_004bc72e
#define FUN_004bd035 Ai_Subsystem_004bd035
#define FUN_004bd23f Ai_Subsystem_004bd23f
#define FUN_004bd3e9 Ai_Subsystem_004bd3e9
#define FUN_004bd459 Ai_Subsystem_004bd459
#define FUN_004bd4f0 Ai_Subsystem_004bd4f0
#define FUN_004bd563 Ai_Subsystem_004bd563
#define FUN_004bd5af Ai_Util_CheckTimer
#define FUN_004bd5e3 Ai_Subsystem_004bd5e3
#define FUN_004bd682 Ai_Subsystem_004bd682
#define FUN_004bd6f9 Ai_Subsystem_004bd6f9
#define FUN_004be192 Ai_Subsystem_004be192
#define FUN_004be240 Ai_Util_004be240
#define FUN_004be25f Ai_Subsystem_004be25f
#define FUN_004be357 Ai_Subsystem_004be357
#define FUN_004be3c4 Ai_Subsystem_004be3c4
#define FUN_004be43f Ai_Subsystem_004be43f
#define FUN_004be49b Ai_Subsystem_004be49b
#define FUN_004be525 Ai_Subsystem_004be525
#define FUN_004be5ae Ai_Subsystem_004be5ae
#define FUN_004be643 Ai_Subsystem_004be643
#define FUN_004bf23a Ai_Subsystem_004bf23a
#define FUN_004bf4b3 Ai_CalcMana_004bf4b3
#define FUN_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define FUN_004c06df Ai_Subsystem_004c06df
#define FUN_004c0efe Ai_Subsystem_004c0efe
#define FUN_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define FUN_004c22a2 Ai_Subsystem_004c22a2
#define FUN_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define FUN_004c3aa1 Ai_Subsystem_004c3aa1
#define FUN_004c3ad4 Ai_Subsystem_004c3ad4
#define FUN_004c3b19 Ai_Subsystem_004c3b19
#define FUN_004c3ba3 Ai_Util_004c3ba3
#define FUN_004c3bc4 Ai_Util_004c3bc4
#define FUN_004c3be5 Ai_Subsystem_004c3be5
#define FUN_004c3c5c Ai_Subsystem_004c3c5c
#define FUN_004c4210 Ai_Subsystem_004c4210
#define FUN_004c4c84 Ai_Subsystem_004c4c84
#define FUN_004c5fc9 Ai_Subsystem_004c5fc9
#define FUN_004c7aa8 Ai_Subsystem_004c7aa8
#define FUN_004c7be5 Ai_Subsystem_004c7be5
#define FUN_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define FUN_004c9f3a Ai_Subsystem_004c9f3a
#define FUN_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define FUN_004ca07b Ai_Subsystem_004ca07b
#define FUN_004ca0d9 Ai_Subsystem_004ca0d9
#define FUN_004ca714 Ai_Subsystem_004ca714
#define FUN_004cab92 Ai_Subsystem_004cab92
#define FUN_004cad65 Ai_Subsystem_004cad65
#define FUN_004cadc5 Ai_Subsystem_004cadc5
#define FUN_004cae25 Ai_Util_004cae25
#define FUN_004cae47 Ai_Subsystem_004cae47
#define FUN_004cb04d Ai_Subsystem_004cb04d
#define FUN_004cb1d6 Ai_Subsystem_004cb1d6
#define FUN_004cb2d0 Ai_Util_004cb2d0
#define FUN_004cbad0 Ai_Subsystem_004cbad0
#define FUN_004cbb04 Ai_Util_004cbb04
#define FUN_004cbb33 Ai_Subsystem_004cbb33
#define FUN_004cbba7 Ai_Util_004cbba7
#define FUN_004cbbd7 Ai_Util_004cbbd7
#define FUN_004cbc07 Ai_Util_004cbc07
#define FUN_004cbc36 Ai_Util_004cbc36
#define FUN_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define FUN_004cbda9 Ai_Util_004cbda9
#define FUN_004cbdda Ai_Subsystem_004cbdda
#define FUN_004cbe10 Ai_Subsystem_004cbe10
#define FUN_004cbe57 Ai_Subsystem_004cbe57
#define FUN_004cbf72 Ai_Subsystem_004cbf72
#define FUN_004cbfd0 Ai_Subsystem_004cbfd0
#define FUN_004cc053 Ai_Subsystem_004cc053
#define FUN_004cc0c7 Ai_Util_004cc0c7
#define FUN_004cc0f7 Ai_Util_004cc0f7
#define FUN_004cc127 Ai_Subsystem_004cc127
#define FUN_004cc188 Ai_Util_004cc188
#define FUN_004cc1b8 Ai_Util_004cc1b8
#define FUN_004cc1e8 Ai_Subsystem_004cc1e8
#define FUN_004cc25b Ai_Subsystem_004cc25b
#define FUN_004cc2cc Ai_Subsystem_004cc2cc
#define FUN_004cc33d Ai_Subsystem_004cc33d
#define FUN_004cc3c4 Ai_Subsystem_004cc3c4
#define FUN_004cc3f8 Ai_Subsystem_004cc3f8
#define FUN_004cc42d Ai_Overworld_LogAction
#define FUN_004cc455 Ai_Subsystem_004cc455
#define FUN_004cc49a Ai_Subsystem_004cc49a
#define FUN_004cc4e1 Ai_Util_004cc4e1
#define FUN_004cc50a Ai_Subsystem_004cc50a
#define FUN_004cc56d Ai_Deck_SelectStartingHand
#define FUN_004cc7c5 Ai_Subsystem_004cc7c5
#define FUN_004cc814 Ai_Subsystem_004cc814
#define FUN_004cc87f Ai_Subsystem_004cc87f
#define FUN_004cc8de Ai_Subsystem_004cc8de
#define FUN_004cc93d Ai_Subsystem_004cc93d
#define FUN_004cc97e Ai_Subsystem_004cc97e
#define FUN_004cc9c5 Ai_Turn_ExecuteMainPhase
#define FUN_004ccca3 Ai_Subsystem_004ccca3
#define FUN_004cced8 Ai_Subsystem_004cced8
#define FUN_004cd14f Ai_Subsystem_004cd14f
#define FUN_004cd198 Ai_Subsystem_004cd198
#define FUN_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define FUN_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define Mem_AllocOrFree_004b0d24 Ai_ScoreCardPlay_Enchantment
#define Mem_AllocOrFree_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define Mem_AllocOrFree_004b128e Ai_CalcMana_ResetPool
#define Mem_AllocOrFree_004b137d Ai_CalcMana_AddSource
#define Mem_AllocOrFree_004b1406 Ai_CalcMana_ClearAvailable
#define Mem_AllocOrFree_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define Mem_AllocOrFree_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define Mem_AllocOrFree_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define Mem_AllocOrFree_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define Mem_AllocOrFree_004b2260 Ai_Quest_FormatPromptText
#define Mem_AllocOrFree_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define Mem_AllocOrFree_004b34fe Ai_CalcManaRequirement_Blue
#define Mem_AllocOrFree_004b35b4 Ai_CalcManaRequirement_Green
#define Mem_AllocOrFree_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define Mem_AllocOrFree_004b4274 Ai_ChangeText_FormatOptions
#define Mem_AllocOrFree_004b42d1 Ai_ChangeText_ResetState
#define Mem_AllocOrFree_004b42dc Ai_ChangeText_ApplyWord
#define Mem_AllocOrFree_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define Mem_AllocOrFree_004b53a1 Ai_Eval_ClearCandidateBuffer
#define Mem_AllocOrFree_004b53c6 Ai_Eval_GetCandidateScore
#define Mem_AllocOrFree_004b53ed Ai_Eval_SetCandidateScore
#define Mem_AllocOrFree_004b542d Ai_Eval_GetBestCandidate
#define Mem_AllocOrFree_004b543d Ai_Eval_ResetBestCandidate
#define Mem_AllocOrFree_004b544d Ai_Eval_SortCandidates
#define Mem_AllocOrFree_004b5501 Ai_EvalAbility_Flying
#define Mem_AllocOrFree_004b553f Ai_EvalAbility_Trample
#define Mem_AllocOrFree_004b574d Ai_EvalAbility_FirstStrike
#define Mem_AllocOrFree_004b584e Ai_EvalAbility_Regeneration
#define Mem_AllocOrFree_004b58d9 Ai_EvalAbility_Protection
#define Mem_AllocOrFree_004b5919 Ai_EvalAbility_Landwalk
#define Mem_AllocOrFree_004b5967 Ai_EvalAbility_Deathtouch
#define Mem_AllocOrFree_004b59d9 Ai_EvalAbility_DirectDamage
#define Mem_AllocOrFree_004b5a46 Ai_EvalAbility_Removal
#define Mem_AllocOrFree_004b5ab8 Ai_EvalAbility_Counterspell
#define Mem_AllocOrFree_004b5b6f Ai_EvalAbility_CardDraw
#define Mem_AllocOrFree_004b5bdd Ai_EvalAbility_Displacement
#define Mem_AllocOrFree_004b5c4b Ai_EvalAbility_LifeGain
#define Mem_AllocOrFree_004b5cbb Ai_EvalAbility_Disenchant
#define Mem_AllocOrFree_004b5d2e Ai_EvalAbility_BoardWipe
#define Mem_AllocOrFree_004b5de4 Ai_EvalAbility_LandDestruction
#define Mem_AllocOrFree_004b5f74 Ai_EvalAbility_ManaRamp
#define Mem_AllocOrFree_004b6023 Ai_EvalAbility_Tapping
#define Mem_AllocOrFree_004b613b Ai_EvalAbility_Discard
#define Mem_AllocOrFree_004b61ac Ai_EvalAbility_PumpSpell
#define Mem_AllocOrFree_004b621a Ai_EvalAbility_Haste
#define Mem_AllocOrFree_004b6288 Ai_EvalAbility_Vigilance
#define Mem_AllocOrFree_004b6356 Ai_EvalAbility_Defender
#define Mem_AllocOrFree_004b63c4 Ai_EvalAbility_PingDamage
#define Mem_AllocOrFree_004b6432 Ai_EvalAbility_Recursion
#define Mem_AllocOrFree_004b649f Ai_EvalAbility_TokenGeneration
#define Mem_AllocOrFree_004b650c Ai_EvalAbility_SacrificeOutlet
#define Mem_AllocOrFree_004b65ad Ai_Eval_ClearAbilityTable
#define Mem_AllocOrFree_004b65bf Ai_EvalAbility_DamagePrevention
#define Mem_AllocOrFree_004b6623 Ai_EvalAbility_PowerMod
#define Mem_AllocOrFree_004b6696 Ai_EvalAbility_ToughnessMod
#define Mem_AllocOrFree_004b673e Ai_EvalAbility_ColorIdentity
#define Mem_AllocOrFree_004b67ab Ai_Subsystem_004b67ab
#define Mem_AllocOrFree_004b682f Ai_EvalAbility_StealCreature
#define Mem_AllocOrFree_004b68b3 Ai_Subsystem_004b68b3
#define Mem_AllocOrFree_004b69ba Ai_Subsystem_004b69ba
#define Mem_AllocOrFree_004b6ba8 Ai_Subsystem_004b6ba8
#define Mem_AllocOrFree_004b6c5b Ai_Subsystem_004b6c5b
#define Mem_AllocOrFree_004b6cc8 Ai_Subsystem_004b6cc8
#define Mem_AllocOrFree_004b6d35 Ai_Subsystem_004b6d35
#define Mem_AllocOrFree_004b6da5 Ai_Subsystem_004b6da5
#define Mem_AllocOrFree_004b6e3b Ai_Subsystem_004b6e3b
#define Mem_AllocOrFree_004b6eab Ai_Subsystem_004b6eab
#define Mem_AllocOrFree_004b6f19 Ai_Util_004b6f19
#define Mem_AllocOrFree_004b6f49 Ai_Subsystem_004b6f49
#define Mem_AllocOrFree_004b6fa6 Ai_Subsystem_004b6fa6
#define Mem_AllocOrFree_004b700c Ai_Subsystem_004b700c
#define Mem_AllocOrFree_004b7072 Ai_Subsystem_004b7072
#define Mem_AllocOrFree_004b70fe Ai_Subsystem_004b70fe
#define Mem_AllocOrFree_004b718a Ai_Subsystem_004b718a
#define Mem_AllocOrFree_004b722d Ai_Subsystem_004b722d
#define Mem_AllocOrFree_004b72d0 Ai_Subsystem_004b72d0
#define Mem_AllocOrFree_004b7373 Ai_Subsystem_004b7373
#define Mem_AllocOrFree_004b73ce Ai_Duel_CalculateLayout
#define Mem_AllocOrFree_004b74b1 Ai_Subsystem_004b74b1
#define Mem_AllocOrFree_004b74fa Ai_Subsystem_004b74fa
#define Mem_AllocOrFree_004b756f Ai_Subsystem_004b756f
#define Mem_AllocOrFree_004b75a4 Ai_Subsystem_004b75a4
#define Mem_AllocOrFree_004b75d8 Ai_Subsystem_004b75d8
#define Mem_AllocOrFree_004b7629 Ai_Subsystem_004b7629
#define Mem_AllocOrFree_004b765d Ai_Subsystem_004b765d
#define Mem_AllocOrFree_004b76a6 Ai_Subsystem_004b76a6
#define Mem_AllocOrFree_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define Mem_AllocOrFree_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define Mem_AllocOrFree_004b82ea Ai_Util_004b82ea
#define Mem_AllocOrFree_004b830e Ai_Util_004b830e
#define Mem_AllocOrFree_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define Mem_AllocOrFree_004b8da0 Ai_Subsystem_004b8da0
#define Mem_AllocOrFree_004b8dfd Ai_Subsystem_004b8dfd
#define Mem_AllocOrFree_004b8e4d Ai_FormatCardScoreString
#define Mem_AllocOrFree_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define Mem_AllocOrFree_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define Mem_AllocOrFree_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define Mem_AllocOrFree_004bb9f3 Ai_Subsystem_004bb9f3
#define Mem_AllocOrFree_004bbb99 Ai_Subsystem_004bbb99
#define Mem_AllocOrFree_004bbd93 Ai_Subsystem_004bbd93
#define Mem_AllocOrFree_004bbf8e Ai_Subsystem_004bbf8e
#define Mem_AllocOrFree_004bc029 Ai_Subsystem_004bc029
#define Mem_AllocOrFree_004bc423 Ai_CalcMana_004bc423
#define Mem_AllocOrFree_004bc72e Ai_Subsystem_004bc72e
#define Mem_AllocOrFree_004bd035 Ai_Subsystem_004bd035
#define Mem_AllocOrFree_004bd23f Ai_Subsystem_004bd23f
#define Mem_AllocOrFree_004bd3e9 Ai_Subsystem_004bd3e9
#define Mem_AllocOrFree_004bd459 Ai_Subsystem_004bd459
#define Mem_AllocOrFree_004bd4f0 Ai_Subsystem_004bd4f0
#define Mem_AllocOrFree_004bd563 Ai_Subsystem_004bd563
#define Mem_AllocOrFree_004bd5af Ai_Util_CheckTimer
#define Mem_AllocOrFree_004bd5e3 Ai_Subsystem_004bd5e3
#define Mem_AllocOrFree_004bd682 Ai_Subsystem_004bd682
#define Mem_AllocOrFree_004bd6f9 Ai_Subsystem_004bd6f9
#define Mem_AllocOrFree_004be192 Ai_Subsystem_004be192
#define Mem_AllocOrFree_004be240 Ai_Util_004be240
#define Mem_AllocOrFree_004be25f Ai_Subsystem_004be25f
#define Mem_AllocOrFree_004be357 Ai_Subsystem_004be357
#define Mem_AllocOrFree_004be3c4 Ai_Subsystem_004be3c4
#define Mem_AllocOrFree_004be43f Ai_Subsystem_004be43f
#define Mem_AllocOrFree_004be49b Ai_Subsystem_004be49b
#define Mem_AllocOrFree_004be525 Ai_Subsystem_004be525
#define Mem_AllocOrFree_004be5ae Ai_Subsystem_004be5ae
#define Mem_AllocOrFree_004be643 Ai_Subsystem_004be643
#define Mem_AllocOrFree_004bf23a Ai_Subsystem_004bf23a
#define Mem_AllocOrFree_004bf4b3 Ai_CalcMana_004bf4b3
#define Mem_AllocOrFree_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define Mem_AllocOrFree_004c06df Ai_Subsystem_004c06df
#define Mem_AllocOrFree_004c0efe Ai_Subsystem_004c0efe
#define Mem_AllocOrFree_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define Mem_AllocOrFree_004c22a2 Ai_Subsystem_004c22a2
#define Mem_AllocOrFree_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define Mem_AllocOrFree_004c3aa1 Ai_Subsystem_004c3aa1
#define Mem_AllocOrFree_004c3ad4 Ai_Subsystem_004c3ad4
#define Mem_AllocOrFree_004c3b19 Ai_Subsystem_004c3b19
#define Mem_AllocOrFree_004c3ba3 Ai_Util_004c3ba3
#define Mem_AllocOrFree_004c3bc4 Ai_Util_004c3bc4
#define Mem_AllocOrFree_004c3be5 Ai_Subsystem_004c3be5
#define Mem_AllocOrFree_004c3c5c Ai_Subsystem_004c3c5c
#define Mem_AllocOrFree_004c4210 Ai_Subsystem_004c4210
#define Mem_AllocOrFree_004c4c84 Ai_Subsystem_004c4c84
#define Mem_AllocOrFree_004c5fc9 Ai_Subsystem_004c5fc9
#define Mem_AllocOrFree_004c7aa8 Ai_Subsystem_004c7aa8
#define Mem_AllocOrFree_004c7be5 Ai_Subsystem_004c7be5
#define Mem_AllocOrFree_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define Mem_AllocOrFree_004c9f3a Ai_Subsystem_004c9f3a
#define Mem_AllocOrFree_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define Mem_AllocOrFree_004ca07b Ai_Subsystem_004ca07b
#define Mem_AllocOrFree_004ca0d9 Ai_Subsystem_004ca0d9
#define Mem_AllocOrFree_004ca714 Ai_Subsystem_004ca714
#define Mem_AllocOrFree_004cab92 Ai_Subsystem_004cab92
#define Mem_AllocOrFree_004cad65 Ai_Subsystem_004cad65
#define Mem_AllocOrFree_004cadc5 Ai_Subsystem_004cadc5
#define Mem_AllocOrFree_004cae25 Ai_Util_004cae25
#define Mem_AllocOrFree_004cae47 Ai_Subsystem_004cae47
#define Mem_AllocOrFree_004cb04d Ai_Subsystem_004cb04d
#define Mem_AllocOrFree_004cb1d6 Ai_Subsystem_004cb1d6
#define Mem_AllocOrFree_004cb2d0 Ai_Util_004cb2d0
#define Mem_AllocOrFree_004cbad0 Ai_Subsystem_004cbad0
#define Mem_AllocOrFree_004cbb04 Ai_Util_004cbb04
#define Mem_AllocOrFree_004cbb33 Ai_Subsystem_004cbb33
#define Mem_AllocOrFree_004cbba7 Ai_Util_004cbba7
#define Mem_AllocOrFree_004cbbd7 Ai_Util_004cbbd7
#define Mem_AllocOrFree_004cbc07 Ai_Util_004cbc07
#define Mem_AllocOrFree_004cbc36 Ai_Util_004cbc36
#define Mem_AllocOrFree_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define Mem_AllocOrFree_004cbda9 Ai_Util_004cbda9
#define Mem_AllocOrFree_004cbdda Ai_Subsystem_004cbdda
#define Mem_AllocOrFree_004cbe10 Ai_Subsystem_004cbe10
#define Mem_AllocOrFree_004cbe57 Ai_Subsystem_004cbe57
#define Mem_AllocOrFree_004cbf72 Ai_Subsystem_004cbf72
#define Mem_AllocOrFree_004cbfd0 Ai_Subsystem_004cbfd0
#define Mem_AllocOrFree_004cc053 Ai_Subsystem_004cc053
#define Mem_AllocOrFree_004cc0c7 Ai_Util_004cc0c7
#define Mem_AllocOrFree_004cc0f7 Ai_Util_004cc0f7
#define Mem_AllocOrFree_004cc127 Ai_Subsystem_004cc127
#define Mem_AllocOrFree_004cc188 Ai_Util_004cc188
#define Mem_AllocOrFree_004cc1b8 Ai_Util_004cc1b8
#define Mem_AllocOrFree_004cc1e8 Ai_Subsystem_004cc1e8
#define Mem_AllocOrFree_004cc25b Ai_Subsystem_004cc25b
#define Mem_AllocOrFree_004cc2cc Ai_Subsystem_004cc2cc
#define Mem_AllocOrFree_004cc33d Ai_Subsystem_004cc33d
#define Mem_AllocOrFree_004cc3c4 Ai_Subsystem_004cc3c4
#define Mem_AllocOrFree_004cc3f8 Ai_Subsystem_004cc3f8
#define Mem_AllocOrFree_004cc42d Ai_Overworld_LogAction
#define Mem_AllocOrFree_004cc455 Ai_Subsystem_004cc455
#define Mem_AllocOrFree_004cc49a Ai_Subsystem_004cc49a
#define Mem_AllocOrFree_004cc4e1 Ai_Util_004cc4e1
#define Mem_AllocOrFree_004cc50a Ai_Subsystem_004cc50a
#define Mem_AllocOrFree_004cc56d Ai_Deck_SelectStartingHand
#define Mem_AllocOrFree_004cc7c5 Ai_Subsystem_004cc7c5
#define Mem_AllocOrFree_004cc814 Ai_Subsystem_004cc814
#define Mem_AllocOrFree_004cc87f Ai_Subsystem_004cc87f
#define Mem_AllocOrFree_004cc8de Ai_Subsystem_004cc8de
#define Mem_AllocOrFree_004cc93d Ai_Subsystem_004cc93d
#define Mem_AllocOrFree_004cc97e Ai_Subsystem_004cc97e
#define Mem_AllocOrFree_004cc9c5 Ai_Turn_ExecuteMainPhase
#define Mem_AllocOrFree_004ccca3 Ai_Subsystem_004ccca3
#define Mem_AllocOrFree_004cced8 Ai_Subsystem_004cced8
#define Mem_AllocOrFree_004cd14f Ai_Subsystem_004cd14f
#define Mem_AllocOrFree_004cd198 Ai_Subsystem_004cd198
#define Mem_AllocOrFree_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define Mem_AllocOrFree_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define Pic_Load_004b0d24 Ai_ScoreCardPlay_Enchantment
#define Pic_Load_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define Pic_Load_004b128e Ai_CalcMana_ResetPool
#define Pic_Load_004b137d Ai_CalcMana_AddSource
#define Pic_Load_004b1406 Ai_CalcMana_ClearAvailable
#define Pic_Load_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define Pic_Load_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define Pic_Load_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define Pic_Load_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define Pic_Load_004b2260 Ai_Quest_FormatPromptText
#define Pic_Load_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define Pic_Load_004b34fe Ai_CalcManaRequirement_Blue
#define Pic_Load_004b35b4 Ai_CalcManaRequirement_Green
#define Pic_Load_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define Pic_Load_004b4274 Ai_ChangeText_FormatOptions
#define Pic_Load_004b42d1 Ai_ChangeText_ResetState
#define Pic_Load_004b42dc Ai_ChangeText_ApplyWord
#define Pic_Load_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define Pic_Load_004b53a1 Ai_Eval_ClearCandidateBuffer
#define Pic_Load_004b53c6 Ai_Eval_GetCandidateScore
#define Pic_Load_004b53ed Ai_Eval_SetCandidateScore
#define Pic_Load_004b542d Ai_Eval_GetBestCandidate
#define Pic_Load_004b543d Ai_Eval_ResetBestCandidate
#define Pic_Load_004b544d Ai_Eval_SortCandidates
#define Pic_Load_004b5501 Ai_EvalAbility_Flying
#define Pic_Load_004b553f Ai_EvalAbility_Trample
#define Pic_Load_004b574d Ai_EvalAbility_FirstStrike
#define Pic_Load_004b584e Ai_EvalAbility_Regeneration
#define Pic_Load_004b58d9 Ai_EvalAbility_Protection
#define Pic_Load_004b5919 Ai_EvalAbility_Landwalk
#define Pic_Load_004b5967 Ai_EvalAbility_Deathtouch
#define Pic_Load_004b59d9 Ai_EvalAbility_DirectDamage
#define Pic_Load_004b5a46 Ai_EvalAbility_Removal
#define Pic_Load_004b5ab8 Ai_EvalAbility_Counterspell
#define Pic_Load_004b5b6f Ai_EvalAbility_CardDraw
#define Pic_Load_004b5bdd Ai_EvalAbility_Displacement
#define Pic_Load_004b5c4b Ai_EvalAbility_LifeGain
#define Pic_Load_004b5cbb Ai_EvalAbility_Disenchant
#define Pic_Load_004b5d2e Ai_EvalAbility_BoardWipe
#define Pic_Load_004b5de4 Ai_EvalAbility_LandDestruction
#define Pic_Load_004b5f74 Ai_EvalAbility_ManaRamp
#define Pic_Load_004b6023 Ai_EvalAbility_Tapping
#define Pic_Load_004b613b Ai_EvalAbility_Discard
#define Pic_Load_004b61ac Ai_EvalAbility_PumpSpell
#define Pic_Load_004b621a Ai_EvalAbility_Haste
#define Pic_Load_004b6288 Ai_EvalAbility_Vigilance
#define Pic_Load_004b6356 Ai_EvalAbility_Defender
#define Pic_Load_004b63c4 Ai_EvalAbility_PingDamage
#define Pic_Load_004b6432 Ai_EvalAbility_Recursion
#define Pic_Load_004b649f Ai_EvalAbility_TokenGeneration
#define Pic_Load_004b650c Ai_EvalAbility_SacrificeOutlet
#define Pic_Load_004b65ad Ai_Eval_ClearAbilityTable
#define Pic_Load_004b65bf Ai_EvalAbility_DamagePrevention
#define Pic_Load_004b6623 Ai_EvalAbility_PowerMod
#define Pic_Load_004b6696 Ai_EvalAbility_ToughnessMod
#define Pic_Load_004b673e Ai_EvalAbility_ColorIdentity
#define Pic_Load_004b67ab Ai_Subsystem_004b67ab
#define Pic_Load_004b682f Ai_EvalAbility_StealCreature
#define Pic_Load_004b68b3 Ai_Subsystem_004b68b3
#define Pic_Load_004b69ba Ai_Subsystem_004b69ba
#define Pic_Load_004b6ba8 Ai_Subsystem_004b6ba8
#define Pic_Load_004b6c5b Ai_Subsystem_004b6c5b
#define Pic_Load_004b6cc8 Ai_Subsystem_004b6cc8
#define Pic_Load_004b6d35 Ai_Subsystem_004b6d35
#define Pic_Load_004b6da5 Ai_Subsystem_004b6da5
#define Pic_Load_004b6e3b Ai_Subsystem_004b6e3b
#define Pic_Load_004b6eab Ai_Subsystem_004b6eab
#define Pic_Load_004b6f19 Ai_Util_004b6f19
#define Pic_Load_004b6f49 Ai_Subsystem_004b6f49
#define Pic_Load_004b6fa6 Ai_Subsystem_004b6fa6
#define Pic_Load_004b700c Ai_Subsystem_004b700c
#define Pic_Load_004b7072 Ai_Subsystem_004b7072
#define Pic_Load_004b70fe Ai_Subsystem_004b70fe
#define Pic_Load_004b718a Ai_Subsystem_004b718a
#define Pic_Load_004b722d Ai_Subsystem_004b722d
#define Pic_Load_004b72d0 Ai_Subsystem_004b72d0
#define Pic_Load_004b7373 Ai_Subsystem_004b7373
#define Pic_Load_004b73ce Ai_Duel_CalculateLayout
#define Pic_Load_004b74b1 Ai_Subsystem_004b74b1
#define Pic_Load_004b74fa Ai_Subsystem_004b74fa
#define Pic_Load_004b756f Ai_Subsystem_004b756f
#define Pic_Load_004b75a4 Ai_Subsystem_004b75a4
#define Pic_Load_004b75d8 Ai_Subsystem_004b75d8
#define Pic_Load_004b7629 Ai_Subsystem_004b7629
#define Pic_Load_004b765d Ai_Subsystem_004b765d
#define Pic_Load_004b76a6 Ai_Subsystem_004b76a6
#define Pic_Load_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define Pic_Load_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define Pic_Load_004b82ea Ai_Util_004b82ea
#define Pic_Load_004b830e Ai_Util_004b830e
#define Pic_Load_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define Pic_Load_004b8da0 Ai_Subsystem_004b8da0
#define Pic_Load_004b8dfd Ai_Subsystem_004b8dfd
#define Pic_Load_004b8e4d Ai_FormatCardScoreString
#define Pic_Load_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define Pic_Load_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define Pic_Load_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define Pic_Load_004bb9f3 Ai_Subsystem_004bb9f3
#define Pic_Load_004bbb99 Ai_Subsystem_004bbb99
#define Pic_Load_004bbd93 Ai_Subsystem_004bbd93
#define Pic_Load_004bbf8e Ai_Subsystem_004bbf8e
#define Pic_Load_004bc029 Ai_Subsystem_004bc029
#define Pic_Load_004bc423 Ai_CalcMana_004bc423
#define Pic_Load_004bc72e Ai_Subsystem_004bc72e
#define Pic_Load_004bd035 Ai_Subsystem_004bd035
#define Pic_Load_004bd23f Ai_Subsystem_004bd23f
#define Pic_Load_004bd3e9 Ai_Subsystem_004bd3e9
#define Pic_Load_004bd459 Ai_Subsystem_004bd459
#define Pic_Load_004bd4f0 Ai_Subsystem_004bd4f0
#define Pic_Load_004bd563 Ai_Subsystem_004bd563
#define Pic_Load_004bd5af Ai_Util_CheckTimer
#define Pic_Load_004bd5e3 Ai_Subsystem_004bd5e3
#define Pic_Load_004bd682 Ai_Subsystem_004bd682
#define Pic_Load_004bd6f9 Ai_Subsystem_004bd6f9
#define Pic_Load_004be192 Ai_Subsystem_004be192
#define Pic_Load_004be240 Ai_Util_004be240
#define Pic_Load_004be25f Ai_Subsystem_004be25f
#define Pic_Load_004be357 Ai_Subsystem_004be357
#define Pic_Load_004be3c4 Ai_Subsystem_004be3c4
#define Pic_Load_004be43f Ai_Subsystem_004be43f
#define Pic_Load_004be49b Ai_Subsystem_004be49b
#define Pic_Load_004be525 Ai_Subsystem_004be525
#define Pic_Load_004be5ae Ai_Subsystem_004be5ae
#define Pic_Load_004be643 Ai_Subsystem_004be643
#define Pic_Load_004bf23a Ai_Subsystem_004bf23a
#define Pic_Load_004bf4b3 Ai_CalcMana_004bf4b3
#define Pic_Load_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define Pic_Load_004c06df Ai_Subsystem_004c06df
#define Pic_Load_004c0efe Ai_Subsystem_004c0efe
#define Pic_Load_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define Pic_Load_004c22a2 Ai_Subsystem_004c22a2
#define Pic_Load_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define Pic_Load_004c3aa1 Ai_Subsystem_004c3aa1
#define Pic_Load_004c3ad4 Ai_Subsystem_004c3ad4
#define Pic_Load_004c3b19 Ai_Subsystem_004c3b19
#define Pic_Load_004c3ba3 Ai_Util_004c3ba3
#define Pic_Load_004c3bc4 Ai_Util_004c3bc4
#define Pic_Load_004c3be5 Ai_Subsystem_004c3be5
#define Pic_Load_004c3c5c Ai_Subsystem_004c3c5c
#define Pic_Load_004c4210 Ai_Subsystem_004c4210
#define Pic_Load_004c4c84 Ai_Subsystem_004c4c84
#define Pic_Load_004c5fc9 Ai_Subsystem_004c5fc9
#define Pic_Load_004c7aa8 Ai_Subsystem_004c7aa8
#define Pic_Load_004c7be5 Ai_Subsystem_004c7be5
#define Pic_Load_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define Pic_Load_004c9f3a Ai_Subsystem_004c9f3a
#define Pic_Load_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define Pic_Load_004ca07b Ai_Subsystem_004ca07b
#define Pic_Load_004ca0d9 Ai_Subsystem_004ca0d9
#define Pic_Load_004ca714 Ai_Subsystem_004ca714
#define Pic_Load_004cab92 Ai_Subsystem_004cab92
#define Pic_Load_004cad65 Ai_Subsystem_004cad65
#define Pic_Load_004cadc5 Ai_Subsystem_004cadc5
#define Pic_Load_004cae25 Ai_Util_004cae25
#define Pic_Load_004cae47 Ai_Subsystem_004cae47
#define Pic_Load_004cb04d Ai_Subsystem_004cb04d
#define Pic_Load_004cb1d6 Ai_Subsystem_004cb1d6
#define Pic_Load_004cb2d0 Ai_Util_004cb2d0
#define Pic_Load_004cbad0 Ai_Subsystem_004cbad0
#define Pic_Load_004cbb04 Ai_Util_004cbb04
#define Pic_Load_004cbb33 Ai_Subsystem_004cbb33
#define Pic_Load_004cbba7 Ai_Util_004cbba7
#define Pic_Load_004cbbd7 Ai_Util_004cbbd7
#define Pic_Load_004cbc07 Ai_Util_004cbc07
#define Pic_Load_004cbc36 Ai_Util_004cbc36
#define Pic_Load_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define Pic_Load_004cbda9 Ai_Util_004cbda9
#define Pic_Load_004cbdda Ai_Subsystem_004cbdda
#define Pic_Load_004cbe10 Ai_Subsystem_004cbe10
#define Pic_Load_004cbe57 Ai_Subsystem_004cbe57
#define Pic_Load_004cbf72 Ai_Subsystem_004cbf72
#define Pic_Load_004cbfd0 Ai_Subsystem_004cbfd0
#define Pic_Load_004cc053 Ai_Subsystem_004cc053
#define Pic_Load_004cc0c7 Ai_Util_004cc0c7
#define Pic_Load_004cc0f7 Ai_Util_004cc0f7
#define Pic_Load_004cc127 Ai_Subsystem_004cc127
#define Pic_Load_004cc188 Ai_Util_004cc188
#define Pic_Load_004cc1b8 Ai_Util_004cc1b8
#define Pic_Load_004cc1e8 Ai_Subsystem_004cc1e8
#define Pic_Load_004cc25b Ai_Subsystem_004cc25b
#define Pic_Load_004cc2cc Ai_Subsystem_004cc2cc
#define Pic_Load_004cc33d Ai_Subsystem_004cc33d
#define Pic_Load_004cc3c4 Ai_Subsystem_004cc3c4
#define Pic_Load_004cc3f8 Ai_Subsystem_004cc3f8
#define Pic_Load_004cc42d Ai_Overworld_LogAction
#define Pic_Load_004cc455 Ai_Subsystem_004cc455
#define Pic_Load_004cc49a Ai_Subsystem_004cc49a
#define Pic_Load_004cc4e1 Ai_Util_004cc4e1
#define Pic_Load_004cc50a Ai_Subsystem_004cc50a
#define Pic_Load_004cc56d Ai_Deck_SelectStartingHand
#define Pic_Load_004cc7c5 Ai_Subsystem_004cc7c5
#define Pic_Load_004cc814 Ai_Subsystem_004cc814
#define Pic_Load_004cc87f Ai_Subsystem_004cc87f
#define Pic_Load_004cc8de Ai_Subsystem_004cc8de
#define Pic_Load_004cc93d Ai_Subsystem_004cc93d
#define Pic_Load_004cc97e Ai_Subsystem_004cc97e
#define Pic_Load_004cc9c5 Ai_Turn_ExecuteMainPhase
#define Pic_Load_004ccca3 Ai_Subsystem_004ccca3
#define Pic_Load_004cced8 Ai_Subsystem_004cced8
#define Pic_Load_004cd14f Ai_Subsystem_004cd14f
#define Pic_Load_004cd198 Ai_Subsystem_004cd198
#define Pic_Load_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define Pic_Load_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define UI_CreateWindow_004b0d24 Ai_ScoreCardPlay_Enchantment
#define UI_CreateWindow_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define UI_CreateWindow_004b128e Ai_CalcMana_ResetPool
#define UI_CreateWindow_004b137d Ai_CalcMana_AddSource
#define UI_CreateWindow_004b1406 Ai_CalcMana_ClearAvailable
#define UI_CreateWindow_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define UI_CreateWindow_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define UI_CreateWindow_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define UI_CreateWindow_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define UI_CreateWindow_004b2260 Ai_Quest_FormatPromptText
#define UI_CreateWindow_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define UI_CreateWindow_004b34fe Ai_CalcManaRequirement_Blue
#define UI_CreateWindow_004b35b4 Ai_CalcManaRequirement_Green
#define UI_CreateWindow_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define UI_CreateWindow_004b4274 Ai_ChangeText_FormatOptions
#define UI_CreateWindow_004b42d1 Ai_ChangeText_ResetState
#define UI_CreateWindow_004b42dc Ai_ChangeText_ApplyWord
#define UI_CreateWindow_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define UI_CreateWindow_004b53a1 Ai_Eval_ClearCandidateBuffer
#define UI_CreateWindow_004b53c6 Ai_Eval_GetCandidateScore
#define UI_CreateWindow_004b53ed Ai_Eval_SetCandidateScore
#define UI_CreateWindow_004b542d Ai_Eval_GetBestCandidate
#define UI_CreateWindow_004b543d Ai_Eval_ResetBestCandidate
#define UI_CreateWindow_004b544d Ai_Eval_SortCandidates
#define UI_CreateWindow_004b5501 Ai_EvalAbility_Flying
#define UI_CreateWindow_004b553f Ai_EvalAbility_Trample
#define UI_CreateWindow_004b574d Ai_EvalAbility_FirstStrike
#define UI_CreateWindow_004b584e Ai_EvalAbility_Regeneration
#define UI_CreateWindow_004b58d9 Ai_EvalAbility_Protection
#define UI_CreateWindow_004b5919 Ai_EvalAbility_Landwalk
#define UI_CreateWindow_004b5967 Ai_EvalAbility_Deathtouch
#define UI_CreateWindow_004b59d9 Ai_EvalAbility_DirectDamage
#define UI_CreateWindow_004b5a46 Ai_EvalAbility_Removal
#define UI_CreateWindow_004b5ab8 Ai_EvalAbility_Counterspell
#define UI_CreateWindow_004b5b6f Ai_EvalAbility_CardDraw
#define UI_CreateWindow_004b5bdd Ai_EvalAbility_Displacement
#define UI_CreateWindow_004b5c4b Ai_EvalAbility_LifeGain
#define UI_CreateWindow_004b5cbb Ai_EvalAbility_Disenchant
#define UI_CreateWindow_004b5d2e Ai_EvalAbility_BoardWipe
#define UI_CreateWindow_004b5de4 Ai_EvalAbility_LandDestruction
#define UI_CreateWindow_004b5f74 Ai_EvalAbility_ManaRamp
#define UI_CreateWindow_004b6023 Ai_EvalAbility_Tapping
#define UI_CreateWindow_004b613b Ai_EvalAbility_Discard
#define UI_CreateWindow_004b61ac Ai_EvalAbility_PumpSpell
#define UI_CreateWindow_004b621a Ai_EvalAbility_Haste
#define UI_CreateWindow_004b6288 Ai_EvalAbility_Vigilance
#define UI_CreateWindow_004b6356 Ai_EvalAbility_Defender
#define UI_CreateWindow_004b63c4 Ai_EvalAbility_PingDamage
#define UI_CreateWindow_004b6432 Ai_EvalAbility_Recursion
#define UI_CreateWindow_004b649f Ai_EvalAbility_TokenGeneration
#define UI_CreateWindow_004b650c Ai_EvalAbility_SacrificeOutlet
#define UI_CreateWindow_004b65ad Ai_Eval_ClearAbilityTable
#define UI_CreateWindow_004b65bf Ai_EvalAbility_DamagePrevention
#define UI_CreateWindow_004b6623 Ai_EvalAbility_PowerMod
#define UI_CreateWindow_004b6696 Ai_EvalAbility_ToughnessMod
#define UI_CreateWindow_004b673e Ai_EvalAbility_ColorIdentity
#define UI_CreateWindow_004b67ab Ai_Subsystem_004b67ab
#define UI_CreateWindow_004b682f Ai_EvalAbility_StealCreature
#define UI_CreateWindow_004b68b3 Ai_Subsystem_004b68b3
#define UI_CreateWindow_004b69ba Ai_Subsystem_004b69ba
#define UI_CreateWindow_004b6ba8 Ai_Subsystem_004b6ba8
#define UI_CreateWindow_004b6c5b Ai_Subsystem_004b6c5b
#define UI_CreateWindow_004b6cc8 Ai_Subsystem_004b6cc8
#define UI_CreateWindow_004b6d35 Ai_Subsystem_004b6d35
#define UI_CreateWindow_004b6da5 Ai_Subsystem_004b6da5
#define UI_CreateWindow_004b6e3b Ai_Subsystem_004b6e3b
#define UI_CreateWindow_004b6eab Ai_Subsystem_004b6eab
#define UI_CreateWindow_004b6f19 Ai_Util_004b6f19
#define UI_CreateWindow_004b6f49 Ai_Subsystem_004b6f49
#define UI_CreateWindow_004b6fa6 Ai_Subsystem_004b6fa6
#define UI_CreateWindow_004b700c Ai_Subsystem_004b700c
#define UI_CreateWindow_004b7072 Ai_Subsystem_004b7072
#define UI_CreateWindow_004b70fe Ai_Subsystem_004b70fe
#define UI_CreateWindow_004b718a Ai_Subsystem_004b718a
#define UI_CreateWindow_004b722d Ai_Subsystem_004b722d
#define UI_CreateWindow_004b72d0 Ai_Subsystem_004b72d0
#define UI_CreateWindow_004b7373 Ai_Subsystem_004b7373
#define UI_CreateWindow_004b73ce Ai_Duel_CalculateLayout
#define UI_CreateWindow_004b74b1 Ai_Subsystem_004b74b1
#define UI_CreateWindow_004b74fa Ai_Subsystem_004b74fa
#define UI_CreateWindow_004b756f Ai_Subsystem_004b756f
#define UI_CreateWindow_004b75a4 Ai_Subsystem_004b75a4
#define UI_CreateWindow_004b75d8 Ai_Subsystem_004b75d8
#define UI_CreateWindow_004b7629 Ai_Subsystem_004b7629
#define UI_CreateWindow_004b765d Ai_Subsystem_004b765d
#define UI_CreateWindow_004b76a6 Ai_Subsystem_004b76a6
#define UI_CreateWindow_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define UI_CreateWindow_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define UI_CreateWindow_004b82ea Ai_Util_004b82ea
#define UI_CreateWindow_004b830e Ai_Util_004b830e
#define UI_CreateWindow_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define UI_CreateWindow_004b8da0 Ai_Subsystem_004b8da0
#define UI_CreateWindow_004b8dfd Ai_Subsystem_004b8dfd
#define UI_CreateWindow_004b8e4d Ai_FormatCardScoreString
#define UI_CreateWindow_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define UI_CreateWindow_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define UI_CreateWindow_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define UI_CreateWindow_004bb9f3 Ai_Subsystem_004bb9f3
#define UI_CreateWindow_004bbb99 Ai_Subsystem_004bbb99
#define UI_CreateWindow_004bbd93 Ai_Subsystem_004bbd93
#define UI_CreateWindow_004bbf8e Ai_Subsystem_004bbf8e
#define UI_CreateWindow_004bc029 Ai_Subsystem_004bc029
#define UI_CreateWindow_004bc423 Ai_CalcMana_004bc423
#define UI_CreateWindow_004bc72e Ai_Subsystem_004bc72e
#define UI_CreateWindow_004bd035 Ai_Subsystem_004bd035
#define UI_CreateWindow_004bd23f Ai_Subsystem_004bd23f
#define UI_CreateWindow_004bd3e9 Ai_Subsystem_004bd3e9
#define UI_CreateWindow_004bd459 Ai_Subsystem_004bd459
#define UI_CreateWindow_004bd4f0 Ai_Subsystem_004bd4f0
#define UI_CreateWindow_004bd563 Ai_Subsystem_004bd563
#define UI_CreateWindow_004bd5af Ai_Util_CheckTimer
#define UI_CreateWindow_004bd5e3 Ai_Subsystem_004bd5e3
#define UI_CreateWindow_004bd682 Ai_Subsystem_004bd682
#define UI_CreateWindow_004bd6f9 Ai_Subsystem_004bd6f9
#define UI_CreateWindow_004be192 Ai_Subsystem_004be192
#define UI_CreateWindow_004be240 Ai_Util_004be240
#define UI_CreateWindow_004be25f Ai_Subsystem_004be25f
#define UI_CreateWindow_004be357 Ai_Subsystem_004be357
#define UI_CreateWindow_004be3c4 Ai_Subsystem_004be3c4
#define UI_CreateWindow_004be43f Ai_Subsystem_004be43f
#define UI_CreateWindow_004be49b Ai_Subsystem_004be49b
#define UI_CreateWindow_004be525 Ai_Subsystem_004be525
#define UI_CreateWindow_004be5ae Ai_Subsystem_004be5ae
#define UI_CreateWindow_004be643 Ai_Subsystem_004be643
#define UI_CreateWindow_004bf23a Ai_Subsystem_004bf23a
#define UI_CreateWindow_004bf4b3 Ai_CalcMana_004bf4b3
#define UI_CreateWindow_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define UI_CreateWindow_004c06df Ai_Subsystem_004c06df
#define UI_CreateWindow_004c0efe Ai_Subsystem_004c0efe
#define UI_CreateWindow_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define UI_CreateWindow_004c22a2 Ai_Subsystem_004c22a2
#define UI_CreateWindow_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define UI_CreateWindow_004c3aa1 Ai_Subsystem_004c3aa1
#define UI_CreateWindow_004c3ad4 Ai_Subsystem_004c3ad4
#define UI_CreateWindow_004c3b19 Ai_Subsystem_004c3b19
#define UI_CreateWindow_004c3ba3 Ai_Util_004c3ba3
#define UI_CreateWindow_004c3bc4 Ai_Util_004c3bc4
#define UI_CreateWindow_004c3be5 Ai_Subsystem_004c3be5
#define UI_CreateWindow_004c3c5c Ai_Subsystem_004c3c5c
#define UI_CreateWindow_004c4210 Ai_Subsystem_004c4210
#define UI_CreateWindow_004c4c84 Ai_Subsystem_004c4c84
#define UI_CreateWindow_004c5fc9 Ai_Subsystem_004c5fc9
#define UI_CreateWindow_004c7aa8 Ai_Subsystem_004c7aa8
#define UI_CreateWindow_004c7be5 Ai_Subsystem_004c7be5
#define UI_CreateWindow_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define UI_CreateWindow_004c9f3a Ai_Subsystem_004c9f3a
#define UI_CreateWindow_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define UI_CreateWindow_004ca07b Ai_Subsystem_004ca07b
#define UI_CreateWindow_004ca0d9 Ai_Subsystem_004ca0d9
#define UI_CreateWindow_004ca714 Ai_Subsystem_004ca714
#define UI_CreateWindow_004cab92 Ai_Subsystem_004cab92
#define UI_CreateWindow_004cad65 Ai_Subsystem_004cad65
#define UI_CreateWindow_004cadc5 Ai_Subsystem_004cadc5
#define UI_CreateWindow_004cae25 Ai_Util_004cae25
#define UI_CreateWindow_004cae47 Ai_Subsystem_004cae47
#define UI_CreateWindow_004cb04d Ai_Subsystem_004cb04d
#define UI_CreateWindow_004cb1d6 Ai_Subsystem_004cb1d6
#define UI_CreateWindow_004cb2d0 Ai_Util_004cb2d0
#define UI_CreateWindow_004cbad0 Ai_Subsystem_004cbad0
#define UI_CreateWindow_004cbb04 Ai_Util_004cbb04
#define UI_CreateWindow_004cbb33 Ai_Subsystem_004cbb33
#define UI_CreateWindow_004cbba7 Ai_Util_004cbba7
#define UI_CreateWindow_004cbbd7 Ai_Util_004cbbd7
#define UI_CreateWindow_004cbc07 Ai_Util_004cbc07
#define UI_CreateWindow_004cbc36 Ai_Util_004cbc36
#define UI_CreateWindow_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define UI_CreateWindow_004cbda9 Ai_Util_004cbda9
#define UI_CreateWindow_004cbdda Ai_Subsystem_004cbdda
#define UI_CreateWindow_004cbe10 Ai_Subsystem_004cbe10
#define UI_CreateWindow_004cbe57 Ai_Subsystem_004cbe57
#define UI_CreateWindow_004cbf72 Ai_Subsystem_004cbf72
#define UI_CreateWindow_004cbfd0 Ai_Subsystem_004cbfd0
#define UI_CreateWindow_004cc053 Ai_Subsystem_004cc053
#define UI_CreateWindow_004cc0c7 Ai_Util_004cc0c7
#define UI_CreateWindow_004cc0f7 Ai_Util_004cc0f7
#define UI_CreateWindow_004cc127 Ai_Subsystem_004cc127
#define UI_CreateWindow_004cc188 Ai_Util_004cc188
#define UI_CreateWindow_004cc1b8 Ai_Util_004cc1b8
#define UI_CreateWindow_004cc1e8 Ai_Subsystem_004cc1e8
#define UI_CreateWindow_004cc25b Ai_Subsystem_004cc25b
#define UI_CreateWindow_004cc2cc Ai_Subsystem_004cc2cc
#define UI_CreateWindow_004cc33d Ai_Subsystem_004cc33d
#define UI_CreateWindow_004cc3c4 Ai_Subsystem_004cc3c4
#define UI_CreateWindow_004cc3f8 Ai_Subsystem_004cc3f8
#define UI_CreateWindow_004cc42d Ai_Overworld_LogAction
#define UI_CreateWindow_004cc455 Ai_Subsystem_004cc455
#define UI_CreateWindow_004cc49a Ai_Subsystem_004cc49a
#define UI_CreateWindow_004cc4e1 Ai_Util_004cc4e1
#define UI_CreateWindow_004cc50a Ai_Subsystem_004cc50a
#define UI_CreateWindow_004cc56d Ai_Deck_SelectStartingHand
#define UI_CreateWindow_004cc7c5 Ai_Subsystem_004cc7c5
#define UI_CreateWindow_004cc814 Ai_Subsystem_004cc814
#define UI_CreateWindow_004cc87f Ai_Subsystem_004cc87f
#define UI_CreateWindow_004cc8de Ai_Subsystem_004cc8de
#define UI_CreateWindow_004cc93d Ai_Subsystem_004cc93d
#define UI_CreateWindow_004cc97e Ai_Subsystem_004cc97e
#define UI_CreateWindow_004cc9c5 Ai_Turn_ExecuteMainPhase
#define UI_CreateWindow_004ccca3 Ai_Subsystem_004ccca3
#define UI_CreateWindow_004cced8 Ai_Subsystem_004cced8
#define UI_CreateWindow_004cd14f Ai_Subsystem_004cd14f
#define UI_CreateWindow_004cd198 Ai_Subsystem_004cd198
#define UI_CreateWindow_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define UI_CreateWindow_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define UI_DialogProc_004b0d24 Ai_ScoreCardPlay_Enchantment
#define UI_DialogProc_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define UI_DialogProc_004b128e Ai_CalcMana_ResetPool
#define UI_DialogProc_004b137d Ai_CalcMana_AddSource
#define UI_DialogProc_004b1406 Ai_CalcMana_ClearAvailable
#define UI_DialogProc_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define UI_DialogProc_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define UI_DialogProc_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define UI_DialogProc_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define UI_DialogProc_004b2260 Ai_Quest_FormatPromptText
#define UI_DialogProc_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define UI_DialogProc_004b34fe Ai_CalcManaRequirement_Blue
#define UI_DialogProc_004b35b4 Ai_CalcManaRequirement_Green
#define UI_DialogProc_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define UI_DialogProc_004b4274 Ai_ChangeText_FormatOptions
#define UI_DialogProc_004b42d1 Ai_ChangeText_ResetState
#define UI_DialogProc_004b42dc Ai_ChangeText_ApplyWord
#define UI_DialogProc_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define UI_DialogProc_004b53a1 Ai_Eval_ClearCandidateBuffer
#define UI_DialogProc_004b53c6 Ai_Eval_GetCandidateScore
#define UI_DialogProc_004b53ed Ai_Eval_SetCandidateScore
#define UI_DialogProc_004b542d Ai_Eval_GetBestCandidate
#define UI_DialogProc_004b543d Ai_Eval_ResetBestCandidate
#define UI_DialogProc_004b544d Ai_Eval_SortCandidates
#define UI_DialogProc_004b5501 Ai_EvalAbility_Flying
#define UI_DialogProc_004b553f Ai_EvalAbility_Trample
#define UI_DialogProc_004b574d Ai_EvalAbility_FirstStrike
#define UI_DialogProc_004b584e Ai_EvalAbility_Regeneration
#define UI_DialogProc_004b58d9 Ai_EvalAbility_Protection
#define UI_DialogProc_004b5919 Ai_EvalAbility_Landwalk
#define UI_DialogProc_004b5967 Ai_EvalAbility_Deathtouch
#define UI_DialogProc_004b59d9 Ai_EvalAbility_DirectDamage
#define UI_DialogProc_004b5a46 Ai_EvalAbility_Removal
#define UI_DialogProc_004b5ab8 Ai_EvalAbility_Counterspell
#define UI_DialogProc_004b5b6f Ai_EvalAbility_CardDraw
#define UI_DialogProc_004b5bdd Ai_EvalAbility_Displacement
#define UI_DialogProc_004b5c4b Ai_EvalAbility_LifeGain
#define UI_DialogProc_004b5cbb Ai_EvalAbility_Disenchant
#define UI_DialogProc_004b5d2e Ai_EvalAbility_BoardWipe
#define UI_DialogProc_004b5de4 Ai_EvalAbility_LandDestruction
#define UI_DialogProc_004b5f74 Ai_EvalAbility_ManaRamp
#define UI_DialogProc_004b6023 Ai_EvalAbility_Tapping
#define UI_DialogProc_004b613b Ai_EvalAbility_Discard
#define UI_DialogProc_004b61ac Ai_EvalAbility_PumpSpell
#define UI_DialogProc_004b621a Ai_EvalAbility_Haste
#define UI_DialogProc_004b6288 Ai_EvalAbility_Vigilance
#define UI_DialogProc_004b6356 Ai_EvalAbility_Defender
#define UI_DialogProc_004b63c4 Ai_EvalAbility_PingDamage
#define UI_DialogProc_004b6432 Ai_EvalAbility_Recursion
#define UI_DialogProc_004b649f Ai_EvalAbility_TokenGeneration
#define UI_DialogProc_004b650c Ai_EvalAbility_SacrificeOutlet
#define UI_DialogProc_004b65ad Ai_Eval_ClearAbilityTable
#define UI_DialogProc_004b65bf Ai_EvalAbility_DamagePrevention
#define UI_DialogProc_004b6623 Ai_EvalAbility_PowerMod
#define UI_DialogProc_004b6696 Ai_EvalAbility_ToughnessMod
#define UI_DialogProc_004b673e Ai_EvalAbility_ColorIdentity
#define UI_DialogProc_004b67ab Ai_Subsystem_004b67ab
#define UI_DialogProc_004b682f Ai_EvalAbility_StealCreature
#define UI_DialogProc_004b68b3 Ai_Subsystem_004b68b3
#define UI_DialogProc_004b69ba Ai_Subsystem_004b69ba
#define UI_DialogProc_004b6ba8 Ai_Subsystem_004b6ba8
#define UI_DialogProc_004b6c5b Ai_Subsystem_004b6c5b
#define UI_DialogProc_004b6cc8 Ai_Subsystem_004b6cc8
#define UI_DialogProc_004b6d35 Ai_Subsystem_004b6d35
#define UI_DialogProc_004b6da5 Ai_Subsystem_004b6da5
#define UI_DialogProc_004b6e3b Ai_Subsystem_004b6e3b
#define UI_DialogProc_004b6eab Ai_Subsystem_004b6eab
#define UI_DialogProc_004b6f19 Ai_Util_004b6f19
#define UI_DialogProc_004b6f49 Ai_Subsystem_004b6f49
#define UI_DialogProc_004b6fa6 Ai_Subsystem_004b6fa6
#define UI_DialogProc_004b700c Ai_Subsystem_004b700c
#define UI_DialogProc_004b7072 Ai_Subsystem_004b7072
#define UI_DialogProc_004b70fe Ai_Subsystem_004b70fe
#define UI_DialogProc_004b718a Ai_Subsystem_004b718a
#define UI_DialogProc_004b722d Ai_Subsystem_004b722d
#define UI_DialogProc_004b72d0 Ai_Subsystem_004b72d0
#define UI_DialogProc_004b7373 Ai_Subsystem_004b7373
#define UI_DialogProc_004b73ce Ai_Duel_CalculateLayout
#define UI_DialogProc_004b74b1 Ai_Subsystem_004b74b1
#define UI_DialogProc_004b74fa Ai_Subsystem_004b74fa
#define UI_DialogProc_004b756f Ai_Subsystem_004b756f
#define UI_DialogProc_004b75a4 Ai_Subsystem_004b75a4
#define UI_DialogProc_004b75d8 Ai_Subsystem_004b75d8
#define UI_DialogProc_004b7629 Ai_Subsystem_004b7629
#define UI_DialogProc_004b765d Ai_Subsystem_004b765d
#define UI_DialogProc_004b76a6 Ai_Subsystem_004b76a6
#define UI_DialogProc_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define UI_DialogProc_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define UI_DialogProc_004b82ea Ai_Util_004b82ea
#define UI_DialogProc_004b830e Ai_Util_004b830e
#define UI_DialogProc_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define UI_DialogProc_004b8da0 Ai_Subsystem_004b8da0
#define UI_DialogProc_004b8dfd Ai_Subsystem_004b8dfd
#define UI_DialogProc_004b8e4d Ai_FormatCardScoreString
#define UI_DialogProc_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define UI_DialogProc_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define UI_DialogProc_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define UI_DialogProc_004bb9f3 Ai_Subsystem_004bb9f3
#define UI_DialogProc_004bbb99 Ai_Subsystem_004bbb99
#define UI_DialogProc_004bbd93 Ai_Subsystem_004bbd93
#define UI_DialogProc_004bbf8e Ai_Subsystem_004bbf8e
#define UI_DialogProc_004bc029 Ai_Subsystem_004bc029
#define UI_DialogProc_004bc423 Ai_CalcMana_004bc423
#define UI_DialogProc_004bc72e Ai_Subsystem_004bc72e
#define UI_DialogProc_004bd035 Ai_Subsystem_004bd035
#define UI_DialogProc_004bd23f Ai_Subsystem_004bd23f
#define UI_DialogProc_004bd3e9 Ai_Subsystem_004bd3e9
#define UI_DialogProc_004bd459 Ai_Subsystem_004bd459
#define UI_DialogProc_004bd4f0 Ai_Subsystem_004bd4f0
#define UI_DialogProc_004bd563 Ai_Subsystem_004bd563
#define UI_DialogProc_004bd5af Ai_Util_CheckTimer
#define UI_DialogProc_004bd5e3 Ai_Subsystem_004bd5e3
#define UI_DialogProc_004bd682 Ai_Subsystem_004bd682
#define UI_DialogProc_004bd6f9 Ai_Subsystem_004bd6f9
#define UI_DialogProc_004be192 Ai_Subsystem_004be192
#define UI_DialogProc_004be240 Ai_Util_004be240
#define UI_DialogProc_004be25f Ai_Subsystem_004be25f
#define UI_DialogProc_004be357 Ai_Subsystem_004be357
#define UI_DialogProc_004be3c4 Ai_Subsystem_004be3c4
#define UI_DialogProc_004be43f Ai_Subsystem_004be43f
#define UI_DialogProc_004be49b Ai_Subsystem_004be49b
#define UI_DialogProc_004be525 Ai_Subsystem_004be525
#define UI_DialogProc_004be5ae Ai_Subsystem_004be5ae
#define UI_DialogProc_004be643 Ai_Subsystem_004be643
#define UI_DialogProc_004bf23a Ai_Subsystem_004bf23a
#define UI_DialogProc_004bf4b3 Ai_CalcMana_004bf4b3
#define UI_DialogProc_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define UI_DialogProc_004c06df Ai_Subsystem_004c06df
#define UI_DialogProc_004c0efe Ai_Subsystem_004c0efe
#define UI_DialogProc_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define UI_DialogProc_004c22a2 Ai_Subsystem_004c22a2
#define UI_DialogProc_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define UI_DialogProc_004c3aa1 Ai_Subsystem_004c3aa1
#define UI_DialogProc_004c3ad4 Ai_Subsystem_004c3ad4
#define UI_DialogProc_004c3b19 Ai_Subsystem_004c3b19
#define UI_DialogProc_004c3ba3 Ai_Util_004c3ba3
#define UI_DialogProc_004c3bc4 Ai_Util_004c3bc4
#define UI_DialogProc_004c3be5 Ai_Subsystem_004c3be5
#define UI_DialogProc_004c3c5c Ai_Subsystem_004c3c5c
#define UI_DialogProc_004c4210 Ai_Subsystem_004c4210
#define UI_DialogProc_004c4c84 Ai_Subsystem_004c4c84
#define UI_DialogProc_004c5fc9 Ai_Subsystem_004c5fc9
#define UI_DialogProc_004c7aa8 Ai_Subsystem_004c7aa8
#define UI_DialogProc_004c7be5 Ai_Subsystem_004c7be5
#define UI_DialogProc_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define UI_DialogProc_004c9f3a Ai_Subsystem_004c9f3a
#define UI_DialogProc_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define UI_DialogProc_004ca07b Ai_Subsystem_004ca07b
#define UI_DialogProc_004ca0d9 Ai_Subsystem_004ca0d9
#define UI_DialogProc_004ca714 Ai_Subsystem_004ca714
#define UI_DialogProc_004cab92 Ai_Subsystem_004cab92
#define UI_DialogProc_004cad65 Ai_Subsystem_004cad65
#define UI_DialogProc_004cadc5 Ai_Subsystem_004cadc5
#define UI_DialogProc_004cae25 Ai_Util_004cae25
#define UI_DialogProc_004cae47 Ai_Subsystem_004cae47
#define UI_DialogProc_004cb04d Ai_Subsystem_004cb04d
#define UI_DialogProc_004cb1d6 Ai_Subsystem_004cb1d6
#define UI_DialogProc_004cb2d0 Ai_Util_004cb2d0
#define UI_DialogProc_004cbad0 Ai_Subsystem_004cbad0
#define UI_DialogProc_004cbb04 Ai_Util_004cbb04
#define UI_DialogProc_004cbb33 Ai_Subsystem_004cbb33
#define UI_DialogProc_004cbba7 Ai_Util_004cbba7
#define UI_DialogProc_004cbbd7 Ai_Util_004cbbd7
#define UI_DialogProc_004cbc07 Ai_Util_004cbc07
#define UI_DialogProc_004cbc36 Ai_Util_004cbc36
#define UI_DialogProc_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define UI_DialogProc_004cbda9 Ai_Util_004cbda9
#define UI_DialogProc_004cbdda Ai_Subsystem_004cbdda
#define UI_DialogProc_004cbe10 Ai_Subsystem_004cbe10
#define UI_DialogProc_004cbe57 Ai_Subsystem_004cbe57
#define UI_DialogProc_004cbf72 Ai_Subsystem_004cbf72
#define UI_DialogProc_004cbfd0 Ai_Subsystem_004cbfd0
#define UI_DialogProc_004cc053 Ai_Subsystem_004cc053
#define UI_DialogProc_004cc0c7 Ai_Util_004cc0c7
#define UI_DialogProc_004cc0f7 Ai_Util_004cc0f7
#define UI_DialogProc_004cc127 Ai_Subsystem_004cc127
#define UI_DialogProc_004cc188 Ai_Util_004cc188
#define UI_DialogProc_004cc1b8 Ai_Util_004cc1b8
#define UI_DialogProc_004cc1e8 Ai_Subsystem_004cc1e8
#define UI_DialogProc_004cc25b Ai_Subsystem_004cc25b
#define UI_DialogProc_004cc2cc Ai_Subsystem_004cc2cc
#define UI_DialogProc_004cc33d Ai_Subsystem_004cc33d
#define UI_DialogProc_004cc3c4 Ai_Subsystem_004cc3c4
#define UI_DialogProc_004cc3f8 Ai_Subsystem_004cc3f8
#define UI_DialogProc_004cc42d Ai_Overworld_LogAction
#define UI_DialogProc_004cc455 Ai_Subsystem_004cc455
#define UI_DialogProc_004cc49a Ai_Subsystem_004cc49a
#define UI_DialogProc_004cc4e1 Ai_Util_004cc4e1
#define UI_DialogProc_004cc50a Ai_Subsystem_004cc50a
#define UI_DialogProc_004cc56d Ai_Deck_SelectStartingHand
#define UI_DialogProc_004cc7c5 Ai_Subsystem_004cc7c5
#define UI_DialogProc_004cc814 Ai_Subsystem_004cc814
#define UI_DialogProc_004cc87f Ai_Subsystem_004cc87f
#define UI_DialogProc_004cc8de Ai_Subsystem_004cc8de
#define UI_DialogProc_004cc93d Ai_Subsystem_004cc93d
#define UI_DialogProc_004cc97e Ai_Subsystem_004cc97e
#define UI_DialogProc_004cc9c5 Ai_Turn_ExecuteMainPhase
#define UI_DialogProc_004ccca3 Ai_Subsystem_004ccca3
#define UI_DialogProc_004cced8 Ai_Subsystem_004cced8
#define UI_DialogProc_004cd14f Ai_Subsystem_004cd14f
#define UI_DialogProc_004cd198 Ai_Subsystem_004cd198
#define UI_DialogProc_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define UI_DialogProc_004cd3eb Ai_Subsystem_004cd3eb
#define Ai_SaveGameState Ai_SaveGameState
#define Ai_RestoreGameState Ai_RestoreGameState
#define Ai_PushBoardState Ai_PushBoardState
#define Ai_PopBoardState Ai_PopBoardState
#define Ai_ClearPlan Ai_ClearPlan
#define Ai_BeginTrial Ai_BeginTrial
#define Ai_RecordChoice Ai_RecordChoice
#define Ai_GetOpponentPlayerScore Ai_GetOpponentPlayerScore
#define Ai_CalcLifeAdvantage Ai_CalcLifeAdvantage
#define Ai_ReplayChoice Ai_ReplayChoice
#define Ai_CommitBestPlan Ai_CommitBestPlan
#define Ai_ClearCandidateScoreList Ai_Score_ClearCache
#define Ai_SortCandidateScoreList Ai_Score_SetValidityFlag
#define Ai_EvaluateBoard Ai_EvaluateBoard
#define Ai_PenalizeCounterattack Ai_PenalizeCounterattack
#define Ai_ChooseBlockers Ai_ChooseBlockers
#define Ai_FilterValidBlockers Ai_FilterValidBlockers
#define Duel_ShowStartOfDuelDialog Duel_ShowStartOfDuelDialog
#define Ai_DuelDialogProc Ai_DuelDialogProc
#define Ai_LoadStartDuel2Backdrop Ai_LoadStartDuel2Backdrop
#define Ai_InitCombatHeuristics Ai_StartDuel_InitContext
#define Ai_StartDuelWndProc Ai_StartDuelWndProc
#define Ai_LoadStartDuelBackdrop Ai_LoadStartDuelBackdrop
#define Ai_EvaluateManaCurve Ai_Duel_ResetBuffers
#define Ai_ScoreBoardPermanents Ai_Duel_SetupSurfaces
#define Ai_CalculateCombatOdds Ai_Duel_RenderBackdrop
#define Ai_DuelMainWndProc Ai_DuelMainWndProc
#define Ai_LoadEndDuelBackdrop Ai_LoadEndDuelBackdrop
#define Ai_FindOptimalSpellTarget Ai_EndDuel_ShowResult
#define Ai_EvaluateInstantSpells Ai_EndDuel_ProcessRewards
#define Ai_ScoreAttackerCombination Ai_EndDuel_Cleanup
#define Ai_GetHighestPriorityMove Ai_Score_InitRegister
#define Ai_EvaluateCreatureCast Ai_ScoreCardPlay_Creature
#define Ai_EvaluateSpellCast Ai_ScoreCardPlay_Spell
#define UI_WndProc_004b0d24 Ai_ScoreCardPlay_Enchantment
#define UI_WndProc_004b0e11 Ai_ScoreCardPlay_Artifact
#define UI_WndProc_004b0e80 Ai_ScoreDialog_WndProc
#define UI_WndProc_004b128e Ai_CalcMana_ResetPool
#define UI_WndProc_004b137d Ai_CalcMana_AddSource
#define UI_WndProc_004b1406 Ai_CalcMana_ClearAvailable
#define UI_WndProc_004b1416 Ai_ManaSelection_DialogProc
#define UI_DialogProc_004b15df Ai_TargetSelection_DialogProc
#define UI_WndProc_004b1974 Ai_Target_HighlightCandidate
#define UI_DialogProc_004b19d0 Ai_AttackSelection_DialogProc
#define UI_WndProc_004b1b38 Ai_Attack_ToggleAttacker
#define UI_DialogProc_004b1b9b Ai_BlockSelection_DialogProc
#define UI_WndProc_004b20e5 Ai_Block_AssignPair
#define Pic_Load_WinbkQuestn Ai_LoadQuestPromptBackdrop
#define UI_WndProc_004b2260 Ai_Quest_FormatPromptText
#define UI_WndProc_004b22bd Ai_Quest_ProcessChoice
#define UI_DialogProc_004b257c Ai_Quest_DialogProc
#define Pic_Load_QuestmanaBlack Ai_CalcManaRequirement_Black
#define UI_WndProc_004b34fe Ai_CalcManaRequirement_Blue
#define UI_WndProc_004b35b4 Ai_CalcManaRequirement_Green
#define UI_WndProc_004b3777 Ai_CalcManaRequirement_Red
#define UI_DialogProc_004b3847 Ai_CalcManaRequirement_White
#define Pic_Load_WinbkChangetext Ai_LoadChangeTextBackdrop
#define UI_WndProc_004b4274 Ai_ChangeText_FormatOptions
#define UI_WndProc_004b42d1 Ai_ChangeText_ResetState
#define UI_WndProc_004b42dc Ai_ChangeText_ApplyWord
#define UI_WndProc_004b4a3f Ai_EvalAttackCandidate_CombatTrade
#define UI_WndProc_004b53a1 Ai_Eval_ClearCandidateBuffer
#define UI_WndProc_004b53c6 Ai_Eval_GetCandidateScore
#define UI_WndProc_004b53ed Ai_Eval_SetCandidateScore
#define UI_WndProc_004b542d Ai_Eval_GetBestCandidate
#define UI_WndProc_004b543d Ai_Eval_ResetBestCandidate
#define UI_WndProc_004b544d Ai_Eval_SortCandidates
#define UI_WndProc_004b5501 Ai_EvalAbility_Flying
#define UI_WndProc_004b553f Ai_EvalAbility_Trample
#define UI_WndProc_004b574d Ai_EvalAbility_FirstStrike
#define UI_WndProc_004b584e Ai_EvalAbility_Regeneration
#define UI_WndProc_004b58d9 Ai_EvalAbility_Protection
#define UI_WndProc_004b5919 Ai_EvalAbility_Landwalk
#define UI_WndProc_004b5967 Ai_EvalAbility_Deathtouch
#define UI_WndProc_004b59d9 Ai_EvalAbility_DirectDamage
#define UI_WndProc_004b5a46 Ai_EvalAbility_Removal
#define UI_WndProc_004b5ab8 Ai_EvalAbility_Counterspell
#define UI_WndProc_004b5b6f Ai_EvalAbility_CardDraw
#define UI_WndProc_004b5bdd Ai_EvalAbility_Displacement
#define UI_WndProc_004b5c4b Ai_EvalAbility_LifeGain
#define UI_WndProc_004b5cbb Ai_EvalAbility_Disenchant
#define UI_WndProc_004b5d2e Ai_EvalAbility_BoardWipe
#define UI_WndProc_004b5de4 Ai_EvalAbility_LandDestruction
#define UI_WndProc_004b5f74 Ai_EvalAbility_ManaRamp
#define UI_WndProc_004b6023 Ai_EvalAbility_Tapping
#define UI_WndProc_004b613b Ai_EvalAbility_Discard
#define UI_WndProc_004b61ac Ai_EvalAbility_PumpSpell
#define UI_WndProc_004b621a Ai_EvalAbility_Haste
#define UI_WndProc_004b6288 Ai_EvalAbility_Vigilance
#define UI_WndProc_004b6356 Ai_EvalAbility_Defender
#define UI_WndProc_004b63c4 Ai_EvalAbility_PingDamage
#define UI_WndProc_004b6432 Ai_EvalAbility_Recursion
#define UI_WndProc_004b649f Ai_EvalAbility_TokenGeneration
#define UI_WndProc_004b650c Ai_EvalAbility_SacrificeOutlet
#define UI_WndProc_004b65ad Ai_Eval_ClearAbilityTable
#define UI_WndProc_004b65bf Ai_EvalAbility_DamagePrevention
#define UI_WndProc_004b6623 Ai_EvalAbility_PowerMod
#define UI_WndProc_004b6696 Ai_EvalAbility_ToughnessMod
#define UI_WndProc_004b673e Ai_EvalAbility_ColorIdentity
#define UI_WndProc_004b67ab Ai_Subsystem_004b67ab
#define UI_WndProc_004b682f Ai_EvalAbility_StealCreature
#define UI_WndProc_004b68b3 Ai_Subsystem_004b68b3
#define UI_WndProc_004b69ba Ai_Subsystem_004b69ba
#define UI_WndProc_004b6ba8 Ai_Subsystem_004b6ba8
#define UI_WndProc_004b6c5b Ai_Subsystem_004b6c5b
#define UI_WndProc_004b6cc8 Ai_Subsystem_004b6cc8
#define UI_WndProc_004b6d35 Ai_Subsystem_004b6d35
#define UI_WndProc_004b6da5 Ai_Subsystem_004b6da5
#define UI_WndProc_004b6e3b Ai_Subsystem_004b6e3b
#define UI_WndProc_004b6eab Ai_Subsystem_004b6eab
#define UI_WndProc_004b6f19 Ai_Util_004b6f19
#define UI_WndProc_004b6f49 Ai_Subsystem_004b6f49
#define UI_WndProc_004b6fa6 Ai_Subsystem_004b6fa6
#define UI_WndProc_004b700c Ai_Subsystem_004b700c
#define UI_WndProc_004b7072 Ai_Subsystem_004b7072
#define UI_WndProc_004b70fe Ai_Subsystem_004b70fe
#define UI_WndProc_004b718a Ai_Subsystem_004b718a
#define UI_WndProc_004b722d Ai_Subsystem_004b722d
#define UI_WndProc_004b72d0 Ai_Subsystem_004b72d0
#define UI_WndProc_004b7373 Ai_Subsystem_004b7373
#define UI_WndProc_004b73ce Ai_Duel_CalculateLayout
#define UI_WndProc_004b74b1 Ai_Subsystem_004b74b1
#define UI_WndProc_004b74fa Ai_Subsystem_004b74fa
#define UI_WndProc_004b756f Ai_Subsystem_004b756f
#define UI_WndProc_004b75a4 Ai_Subsystem_004b75a4
#define UI_WndProc_004b75d8 Ai_Subsystem_004b75d8
#define UI_WndProc_004b7629 Ai_Subsystem_004b7629
#define UI_WndProc_004b765d Ai_Subsystem_004b765d
#define UI_WndProc_004b76a6 Ai_Subsystem_004b76a6
#define UI_WndProc_004b784d Ai_Subsystem_004b784d
#define Rules_ApplyManaBurn Ai_CalcManaRequirement_Colorless
#define UI_WndProc_004b7d38 Ai_Subsystem_004b7d38
#define UI_PlayCoinTossAvi Ai_WndProc_004b7de8
#define UI_WndProc_004b82ea Ai_Util_004b82ea
#define UI_WndProc_004b830e Ai_Util_004b830e
#define UI_WndProc_004b832d Ai_Subsystem_004b832d
#define UI_DialogProc_004b8421 Ai_WndProc_004b8421
#define CardScript_Fireball CardScript_Fireball
#define UI_WndProc_004b8da0 Ai_Subsystem_004b8da0
#define UI_WndProc_004b8dfd Ai_Subsystem_004b8dfd
#define UI_WndProc_004b8e4d Ai_FormatCardScoreString
#define UI_WndProc_004b90de Ai_Subsystem_004b90de
#define UI_RegisterManaPoolClass Ai_CalcManaRequirement_MultiColor
#define UI_WndProc_004b920e Ai_Subsystem_004b920e
#define UI_ManaPoolWndProc Ai_CalcManaRequirement_General
#define UI_WndProc_004ba6b6 Ai_WndProc_004ba6b6
#define UI_PromptManaColorSelection Ai_CalcManaRequirement_PayCost
#define UI_WndProc_004bb9f3 Ai_Subsystem_004bb9f3
#define UI_WndProc_004bbb99 Ai_Subsystem_004bbb99
#define UI_WndProc_004bbd93 Ai_Subsystem_004bbd93
#define UI_WndProc_004bbf8e Ai_Subsystem_004bbf8e
#define UI_WndProc_004bc029 Ai_Subsystem_004bc029
#define UI_WndProc_004bc423 Ai_CalcMana_004bc423
#define UI_WndProc_004bc72e Ai_Subsystem_004bc72e
#define UI_WndProc_004bd035 Ai_Subsystem_004bd035
#define UI_WndProc_004bd23f Ai_Subsystem_004bd23f
#define UI_WndProc_004bd3e9 Ai_Subsystem_004bd3e9
#define UI_WndProc_004bd459 Ai_Subsystem_004bd459
#define UI_WndProc_004bd4f0 Ai_Subsystem_004bd4f0
#define UI_WndProc_004bd563 Ai_Subsystem_004bd563
#define UI_WndProc_004bd5af Ai_Util_CheckTimer
#define UI_WndProc_004bd5e3 Ai_Subsystem_004bd5e3
#define UI_WndProc_004bd682 Ai_Subsystem_004bd682
#define UI_WndProc_004bd6f9 Ai_Subsystem_004bd6f9
#define UI_WndProc_004be192 Ai_Subsystem_004be192
#define UI_WndProc_004be240 Ai_Util_004be240
#define UI_WndProc_004be25f Ai_Subsystem_004be25f
#define UI_WndProc_004be357 Ai_Subsystem_004be357
#define UI_WndProc_004be3c4 Ai_Subsystem_004be3c4
#define UI_WndProc_004be43f Ai_Subsystem_004be43f
#define UI_WndProc_004be49b Ai_Subsystem_004be49b
#define UI_WndProc_004be525 Ai_Subsystem_004be525
#define UI_WndProc_004be5ae Ai_Subsystem_004be5ae
#define UI_WndProc_004be643 Ai_Subsystem_004be643
#define UI_WndProc_004bf23a Ai_Subsystem_004bf23a
#define UI_WndProc_004bf4b3 Ai_CalcMana_004bf4b3
#define UI_WndProc_004c003d Ai_CalcMana_004c003d
#define Overworld_LoadAdventureInterface800 Overworld_LoadAdventureInterface800
#define UI_WndProc_004c06df Ai_Subsystem_004c06df
#define UI_WndProc_004c0efe Ai_Subsystem_004c0efe
#define UI_WndProc_004c207a Ai_Simulate_EvaluateMoveTree
#define Sound_Play_Button2 Sound_Play_Button2
#define UI_WndProc_004c22a2 Ai_Subsystem_004c22a2
#define UI_WndProc_004c2340 Ai_Subsystem_004c2340
#define Overworld_LoadMapScreenPics Overworld_LoadMapScreenPics
#define UI_WndProc_004c3aa1 Ai_Subsystem_004c3aa1
#define UI_WndProc_004c3ad4 Ai_Subsystem_004c3ad4
#define UI_WndProc_004c3b19 Ai_Subsystem_004c3b19
#define UI_WndProc_004c3ba3 Ai_Util_004c3ba3
#define UI_WndProc_004c3bc4 Ai_Util_004c3bc4
#define UI_WndProc_004c3be5 Ai_Subsystem_004c3be5
#define UI_WndProc_004c3c5c Ai_Subsystem_004c3c5c
#define UI_WndProc_004c4210 Ai_Subsystem_004c4210
#define UI_WndProc_004c4c84 Ai_Subsystem_004c4c84
#define UI_WndProc_004c5fc9 Ai_Subsystem_004c5fc9
#define UI_WndProc_004c7aa8 Ai_Subsystem_004c7aa8
#define UI_WndProc_004c7be5 Ai_Subsystem_004c7be5
#define UI_WndProc_004c7d69 Ai_Subsystem_004c7d69
#define Rules_AssignCombatBlockerDamage Ai_EvalAttackCandidate_General
#define UI_WndProc_004c9f3a Ai_Subsystem_004c9f3a
#define UI_WndProc_004c9f88 Ai_Overworld_EvaluateEncounterThreat
#define UI_WndProc_004ca07b Ai_Subsystem_004ca07b
#define UI_WndProc_004ca0d9 Ai_Subsystem_004ca0d9
#define UI_WndProc_004ca714 Ai_Subsystem_004ca714
#define UI_WndProc_004cab92 Ai_Subsystem_004cab92
#define UI_WndProc_004cad65 Ai_Subsystem_004cad65
#define UI_WndProc_004cadc5 Ai_Subsystem_004cadc5
#define UI_WndProc_004cae25 Ai_Util_004cae25
#define UI_WndProc_004cae47 Ai_Subsystem_004cae47
#define UI_WndProc_004cb04d Ai_Subsystem_004cb04d
#define UI_WndProc_004cb1d6 Ai_Subsystem_004cb1d6
#define UI_WndProc_004cb2d0 Ai_Util_004cb2d0
#define UI_WndProc_004cbad0 Ai_Subsystem_004cbad0
#define UI_WndProc_004cbb04 Ai_Util_004cbb04
#define UI_WndProc_004cbb33 Ai_Subsystem_004cbb33
#define UI_WndProc_004cbba7 Ai_Util_004cbba7
#define UI_WndProc_004cbbd7 Ai_Util_004cbbd7
#define UI_WndProc_004cbc07 Ai_Util_004cbc07
#define UI_WndProc_004cbc36 Ai_Util_004cbc36
#define UI_WndProc_004cbc65 Ai_Subsystem_004cbc65
#define CardTypeFromID Ai_Overworld_ChooseRoamDirection
#define CardIDFromType CardIDFromType
#define UI_WndProc_004cbda9 Ai_Util_004cbda9
#define UI_WndProc_004cbdda Ai_Subsystem_004cbdda
#define UI_WndProc_004cbe10 Ai_Subsystem_004cbe10
#define UI_WndProc_004cbe57 Ai_Subsystem_004cbe57
#define UI_WndProc_004cbf72 Ai_Subsystem_004cbf72
#define UI_WndProc_004cbfd0 Ai_Subsystem_004cbfd0
#define UI_WndProc_004cc053 Ai_Subsystem_004cc053
#define UI_WndProc_004cc0c7 Ai_Util_004cc0c7
#define UI_WndProc_004cc0f7 Ai_Util_004cc0f7
#define UI_WndProc_004cc127 Ai_Subsystem_004cc127
#define UI_WndProc_004cc188 Ai_Util_004cc188
#define UI_WndProc_004cc1b8 Ai_Util_004cc1b8
#define UI_WndProc_004cc1e8 Ai_Subsystem_004cc1e8
#define UI_WndProc_004cc25b Ai_Subsystem_004cc25b
#define UI_WndProc_004cc2cc Ai_Subsystem_004cc2cc
#define UI_WndProc_004cc33d Ai_Subsystem_004cc33d
#define UI_WndProc_004cc3c4 Ai_Subsystem_004cc3c4
#define UI_WndProc_004cc3f8 Ai_Subsystem_004cc3f8
#define UI_WndProc_004cc42d Ai_Overworld_LogAction
#define UI_WndProc_004cc455 Ai_Subsystem_004cc455
#define UI_WndProc_004cc49a Ai_Subsystem_004cc49a
#define UI_WndProc_004cc4e1 Ai_Util_004cc4e1
#define UI_WndProc_004cc50a Ai_Subsystem_004cc50a
#define UI_WndProc_004cc56d Ai_Deck_SelectStartingHand
#define UI_WndProc_004cc7c5 Ai_Subsystem_004cc7c5
#define UI_WndProc_004cc814 Ai_Subsystem_004cc814
#define UI_WndProc_004cc87f Ai_Subsystem_004cc87f
#define UI_WndProc_004cc8de Ai_Subsystem_004cc8de
#define UI_WndProc_004cc93d Ai_Subsystem_004cc93d
#define UI_WndProc_004cc97e Ai_Subsystem_004cc97e
#define UI_WndProc_004cc9c5 Ai_Turn_ExecuteMainPhase
#define UI_WndProc_004ccca3 Ai_Subsystem_004ccca3
#define UI_WndProc_004cced8 Ai_Subsystem_004cced8
#define UI_WndProc_004cd14f Ai_Subsystem_004cd14f
#define UI_WndProc_004cd198 Ai_Subsystem_004cd198
#define UI_WndProc_004cd1d1 Ai_Subsystem_004cd1d1
#define Pic_Load_Title Pic_Load_Title
#define UI_WndProc_004cd3eb Ai_Subsystem_004cd3eb

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_AI_H */
