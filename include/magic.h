/*
 * magic.h - Function Prototypes and Header for MAGIC.EXE
 * Decompiled using Ghidra on 2026-08-25 08:38:56
 */
#ifndef MAGIC_H
#define MAGIC_H

#include "windows_types.h"
#include "magic_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function at 00401000 (Size: 3212 bytes) */
int32_t UI_Register_MAGICGAME_BigCardCardClass_00401000(HWND hwnd,uint32_t y,HDC hdc,int32_t *flags);;

/* Function at 00401c91 (Size: 146 bytes) */
bool UI_RegisterSmallCardClass(LPCSTR str_1);;

/* Function at 00401d23 (Size: 11 bytes) */
void Mem_AllocOrFree_00401d23(void);;

/* Function at 00401d2e (Size: 306 bytes) */
LRESULT UI_WndProc_00401d2e(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 00401e65 (Size: 219 bytes) */
int32_t UI_Register_WINBK_BigCard_00401e65(LPCSTR str_1);;

/* Function at 00401f40 (Size: 48 bytes) */
void Mem_AllocOrFree_00401f40(void);;

/* Function at 00401f70 (Size: 4340 bytes) */
LRESULT UI_CardListWndProc(HWND hwnd,uint32_t uMsg,WPARAM wParam,LONG *lParam);;

/* Function at 00403189 (Size: 185 bytes) */
bool FUN_00403189(HWND hwnd,int card_slot);;

/* Function at 00403250 (Size: 955 bytes) */
int32_t UI_PaintBigCardInfo(int *value,int min_val,int max_val,uint32_t flags,uint32_t flags,uint32_t arg_6,uint32_t arg_7,uint32_t arg_8,uint32_t arg_9,uint32_t arg_10,uint32_t arg_11,uint32_t arg_12,int arg_13,int arg_14,uint32_t arg_15,uint32_t arg_16,uint32_t arg_17,uint32_t arg_18,uint32_t arg_19);;

/* Function at 0040360b (Size: 7256 bytes) */
uint32_t Rules_ParseFilter_0040360b(int card_id,int color_mask,char *str_3,int flags,uint8_t flags,uint8_t arg_6,uint32_t arg_7,uint32_t arg_8,uint32_t arg_9,uint32_t arg_10,uint32_t arg_11,uint32_t arg_12,uint32_t arg_13,int arg_14,int arg_15,uint32_t arg_16,uint32_t arg_17,uint32_t arg_18,uint32_t arg_19,uint32_t arg_20);;

/* Function at 00405277 (Size: 249 bytes) */
int FUN_00405277(int player,int card_slot);;

/* Function at 00405370 (Size: 832 bytes) */
void Action_PromptTarget_00405370(uint32_t spell_id,int32_t target_id,int flags);;

/* Function at 00405802 (Size: 1737 bytes) */
int Action_ValidateTarget_00405802(int spell_id,uint32_t target_id,uint32_t flags,uint32_t flags,uint32_t flags,uint32_t arg_6,uint32_t arg_7,uint32_t arg_8,uint32_t arg_9,uint32_t arg_10,int arg_11,int arg_12,uint32_t arg_13,uint32_t arg_14,uint32_t arg_15,uint32_t arg_16,uint32_t arg_17,uint8_t *arg_18,int32_t arg_19,int *arg_20);;

/* Function at 00405edf (Size: 184 bytes) */
int32_t FUN_00405edf(int player,int card_slot);;

/* Function at 00405f97 (Size: 324 bytes) */
int32_t FUN_00405f97(int player,int card_slot);;

/* Function at 004060e0 (Size: 728 bytes) */
void Csv_LoadInfo_004060e0(void);;

/* Function at 004063b8 (Size: 320 bytes) */
void Csv_LoadMaster_004063b8(void);;

/* Function at 004064f8 (Size: 167 bytes) */
void Csv_WriteConcise_004064f8(void);;

/* Function at 0040659f (Size: 226 bytes) */
void Csv_ReadConcise_0040659f(void);;

/* Function at 00406681 (Size: 441 bytes) */
void Csv_SearchMaster_00406681(char *filepath,int y,int width,char *str_4);;

/* Function at 0040683a (Size: 583 bytes) */
int FUN_0040683a(char *str_1,int min_val,int max_val,int flags,int32_t flags);;

/* Function at 00406a88 (Size: 121 bytes) */
void FUN_00406a88(char *str_1,int card_slot);;

/* Function at 00406b01 (Size: 75 bytes) */
bool FUN_00406b01(char *str_1);;

/* Function at 00406b4c (Size: 1315 bytes) */
int Deck_FilterAttributes_00406b4c(char *filter_string,int color_mask,uint32_t width,int height);;

/* Function at 0040706f (Size: 155 bytes) */
void Story_Load_0040706f(void);;

/* Function at 0040710a (Size: 196 bytes) */
void Tale_Load_0040710a(int value);;

/* Function at 004071ce (Size: 589 bytes) */
void Hints_Load_004071ce(void);;

/* Function at 0040741b (Size: 126 bytes) */
void Hints_GetNext_0040741b(int value);;

/* Function at 00407499 (Size: 681 bytes) */
int FUN_00407499(int value);;

/* Function at 00407747 (Size: 103 bytes) */
int32_t FUN_00407747(int value);;

/* Function at 004077ae (Size: 144 bytes) */
char * FUN_004077ae(char *str_1);;

/* Function at 00407843 (Size: 753 bytes) */
char * FUN_00407843(char *str_1,char *str_2,int max_val);;

/* Function at 00407b34 (Size: 776 bytes) */
void Merchant_ProcessBuy_00407b34(int value);;

/* Function at 00407e40 (Size: 585 bytes) */
void UI_ProcessKeyboardInput(int32_t player,uint32_t card_slot);;

/* Function at 00408089 (Size: 41 bytes) */
bool Mem_AllocOrFree_00408089(void);;

/* Function at 004080b2 (Size: 93 bytes) */
int32_t Util_CopyMemoryBuffer(void);;

/* Function at 0040810f (Size: 41 bytes) */
int32_t Mem_AllocOrFree_0040810f(void);;

/* Function at 0040813d (Size: 41 bytes) */
int32_t Mem_AllocOrFree_0040813d(void);;

/* Function at 0040816b (Size: 57 bytes) */
void Util_MoveMemoryBuffer(int32_t value);;

/* Function at 004081b0 (Size: 289 bytes) */
bool UI_RegisterCueCardClass(LPCSTR str_1);;

/* Function at 004082d1 (Size: 153 bytes) */
void UI_UnregisterCueCardClass(void);;

/* Function at 0040836a (Size: 1111 bytes) */
LRESULT UI_CueCardWndProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,LPSTR lParam);;

/* Function at 004088d0 (Size: 1068 bytes) */
int32_t UI_UpdateCueCardPosition(int *value);;

/* Function at 00408e20 (Size: 562 bytes) */
int32_t UI_Register_FACE_BLACK_00408e20(LPCSTR str_1);;

/* Function at 00409052 (Size: 164 bytes) */
void UI_UnregisterFaceClass(void);;

/* Function at 004090f6 (Size: 1750 bytes) */
LRESULT UI_DuelArenaMenuProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam);;

/* Function at 004097e2 (Size: 842 bytes) */
void UI_RenderDuelStatusBanner(HDC hdc,RECT *min_val,int max_val);;

/* Function at 00409b2c (Size: 327 bytes) */
void UI_ShowDuelArenaWindow(int player,int card_slot);;

/* Function at 00409c73 (Size: 63 bytes) */
void UI_PostDuelArenaMessage(int32_t value);;

/* Function at 00409cb2 (Size: 74 bytes) */
int32_t FUN_00409cb2(int value);;

/* Function at 00409d10 (Size: 166 bytes) */
int32_t Subsystem_LoadStatWinDll(void);;

/* Function at 00409db6 (Size: 93 bytes) */
void Subsystem_FreeStatWinDll(void);;

/* Function at 00409e13 (Size: 41 bytes) */
void Mem_AllocOrFree_00409e13(int32_t player,int32_t card_slot);;

/* Function at 00409e3c (Size: 49 bytes) */
int32_t Mem_AllocOrFree_00409e3c(int32_t value);;

/* Function at 00409e6d (Size: 61 bytes) */
int32_t FUN_00409e6d(int32_t value,int32_t min_val,int32_t max_val,int32_t flags);;

/* Function at 00409eb0 (Size: 102 bytes) */
void FUN_00409eb0(int value);;

/* Function at 00409f16 (Size: 131 bytes) */
void FUN_00409f16(int player,int card_slot);;

/* Function at 00409f99 (Size: 145 bytes) */
void FUN_00409f99(char *str_1,int y,uint32_t width,int height);;

/* Function at 0040a02a (Size: 324 bytes) */
int FUN_0040a02a(int value);;

/* Function at 0040a16e (Size: 53 bytes) */
void UI_RenderOpponentLibraryPrompt(void);;

/* Function at 0040a1a3 (Size: 47 bytes) */
void UI_RenderPlayerLibraryPrompt(void);;

/* Function at 0040a1d2 (Size: 45 bytes) */
int Util_GetRandomNumber(int value);;

/* Function at 0040a1ff (Size: 65 bytes) */
void Ai_SyncLookaheadBuffers(void);;

/* Function at 0040a240 (Size: 21 bytes) */
void Mem_AllocOrFree_0040a240(void);;

/* Function at 0040a255 (Size: 101 bytes) */
uint32_t FUN_0040a255(uint32_t value);;

/* Function at 0040a2c0 (Size: 69 bytes) */
int32_t Util_SeedRandomGenerator(void);;

/* Function at 0040a305 (Size: 55 bytes) */
int Math_Clamp(int value,int min_val,int max_val);;

/* Function at 0040a33c (Size: 51 bytes) */
void FUN_0040a33c(void);;

/* Function at 0040a36f (Size: 114 bytes) */
int FUN_0040a36f(int player,int card_slot);;

/* Function at 0040a3e1 (Size: 65 bytes) */
void App_ProcessPendingMessages(void);;

/* Function at 0040a422 (Size: 34 bytes) */
void Mem_AllocOrFree_0040a422(void);;

/* Function at 0040a444 (Size: 104 bytes) */
int FUN_0040a444(void);;

/* Function at 0040a4ac (Size: 40 bytes) */
void Mem_AllocOrFree_0040a4ac(void *value,void *min_val,size_t max_val);;

/* Function at 0040a4d4 (Size: 40 bytes) */
void Mem_AllocOrFree_0040a4d4(void *value,void *min_val,size_t max_val);;

/* Function at 0040a4fc (Size: 106 bytes) */
int32_t Pic_Load_advfac64_0040a4fc(void);;

/* Function at 0040a566 (Size: 120 bytes) */
int32_t FUN_0040a566(void);;

/* Function at 0040a5de (Size: 327 bytes) */
void FUN_0040a5de(void);;

/* Function at 0040a725 (Size: 350 bytes) */
void FUN_0040a725(char *value);;

/* Function at 0040a883 (Size: 218 bytes) */
void FUN_0040a883(char *value);;

/* Function at 0040a95d (Size: 404 bytes) */
void FUN_0040a95d(char *value);;

/* Function at 0040aaf1 (Size: 264 bytes) */
void FUN_0040aaf1(char *value);;

/* Function at 0040abf9 (Size: 260 bytes) */
void FUN_0040abf9(char *value);;

/* Function at 0040acfd (Size: 178 bytes) */
void FUN_0040acfd(char *value);;

/* Function at 0040adaf (Size: 182 bytes) */
void FUN_0040adaf(char *value,int min_val,int max_val);;

/* Function at 0040ae70 (Size: 407 bytes) */
int32_t FUN_0040ae70(int player,int card_slot);;

/* Function at 0040b00c (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0040b00c(int value);;

/* Function at 0040b03e (Size: 261 bytes) */
int32_t FUN_0040b03e(int player,int card_slot);;

/* Function at 0040b143 (Size: 389 bytes) */
int32_t FUN_0040b143(int value);;

/* Function at 0040b2c8 (Size: 250 bytes) */
int32_t FUN_0040b2c8(int value);;

/* Function at 0040b3c2 (Size: 127 bytes) */
void FUN_0040b3c2(int32_t player,int32_t card_slot);;

/* Function at 0040b441 (Size: 167 bytes) */
void FUN_0040b441(int *player,int card_slot);;

/* Function at 0040b4e8 (Size: 771 bytes) */
void FUN_0040b4e8(void);;

/* Function at 0040b7fa (Size: 1193 bytes) */
int Castle_Process_0040b7fa(int value);;

/* Function at 0040bcff (Size: 1147 bytes) */
void FUN_0040bcff(uint32_t player,uint32_t card_slot);;

/* Function at 0040c180 (Size: 45 bytes) */
void Mem_AllocOrFree_0040c180(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 0040c1ad (Size: 199 bytes) */
void FUN_0040c1ad(char *value,int y,int width,int32_t flags);;

/* Function at 0040c274 (Size: 59 bytes) */
void FUN_0040c274(int32_t value,int y,int width,int32_t flags);;

/* Function at 0040c2af (Size: 58 bytes) */
void FUN_0040c2af(int32_t value,int y,int width,int32_t flags);;

/* Function at 0040c2e9 (Size: 77 bytes) */
void FUN_0040c2e9(int32_t value,int y,int width,int32_t flags);;

/* Function at 0040c336 (Size: 75 bytes) */
void FUN_0040c336(int32_t value,int y,int width,int flags);;

/* Function at 0040c381 (Size: 75 bytes) */
void FUN_0040c381(int32_t value,int y,int width,int32_t flags);;

/* Function at 0040c3cc (Size: 85 bytes) */
void UI_DrawCombatString(char *value,int y,int width,int32_t flags);;

/* Function at 0040c421 (Size: 68 bytes) */
void FUN_0040c421(int32_t value,int y,int width,int height);;

/* Function at 0040c465 (Size: 96 bytes) */
int FUN_0040c465(char *str_1);;

/* Function at 0040c4c5 (Size: 139 bytes) */
void FUN_0040c4c5(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8);;

/* Function at 0040c550 (Size: 137 bytes) */
void FUN_0040c550(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8);;

/* Function at 0040c5d9 (Size: 137 bytes) */
void FUN_0040c5d9(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8);;

/* Function at 0040c662 (Size: 101 bytes) */
void FUN_0040c662(int *value,int min_val,int max_val,int flags,int flags,uint32_t arg_6);;

/* Function at 0040c6c7 (Size: 101 bytes) */
void FUN_0040c6c7(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0040c72c (Size: 53 bytes) */
void FUN_0040c72c(int value,int min_val,int max_val,int flags,uint32_t flags);;

/* Function at 0040c761 (Size: 95 bytes) */
uint32_t Surface_GetPixelColor(int player, int card_slot);;

/* Function at 0040c7c0 (Size: 92 bytes) */
int32_t FUN_0040c7c0(int player,int card_slot);;

/* Function at 0040c81c (Size: 109 bytes) */
void FUN_0040c81c(uint32_t value,int min_val,int max_val);;

/* Function at 0040c889 (Size: 113 bytes) */
void FUN_0040c889(uint32_t value,int min_val,int max_val);;

/* Function at 0040c8fa (Size: 95 bytes) */
int32_t FUN_0040c8fa(int player,int card_slot);;

/* Function at 0040c959 (Size: 115 bytes) */
void FUN_0040c959(uint32_t value,int min_val,int max_val);;

/* Function at 0040c9cc (Size: 119 bytes) */
void FUN_0040c9cc(uint32_t value,int min_val,int max_val);;

/* Function at 0040ca43 (Size: 268 bytes) */
void FUN_0040ca43(int value,int min_val,int max_val);;

/* Function at 0040cb4f (Size: 110 bytes) */
uint32_t FUN_0040cb4f(int value,int min_val,char max_val);;

/* Function at 0040cbbd (Size: 75 bytes) */
int32_t FUN_0040cbbd(int player,int card_slot);;

/* Function at 0040cc08 (Size: 118 bytes) */
int FUN_0040cc08(char *str_1);;

/* Function at 0040cc7e (Size: 551 bytes) */
int Font_DrawFormattedText(int value,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int32_t *arg_9);;

/* Function at 0040cea5 (Size: 50 bytes) */
void FUN_0040cea5(int value,int min_val,int max_val);;

/* Function at 0040ced7 (Size: 50 bytes) */
void FUN_0040ced7(int value,int min_val,int max_val);;

/* Function at 0040cf09 (Size: 50 bytes) */
void FUN_0040cf09(int value,int min_val,int max_val);;

/* Function at 0040cf3b (Size: 50 bytes) */
void FUN_0040cf3b(int value,int min_val,int max_val);;

/* Function at 0040cf6d (Size: 52 bytes) */
void FUN_0040cf6d(int x,int y,int width,int height);;

/* Function at 0040cfa1 (Size: 52 bytes) */
void FUN_0040cfa1(int x,int y,int width,int height);;

/* Function at 0040cfd5 (Size: 52 bytes) */
void FUN_0040cfd5(int x,int y,int width,int height);;

/* Function at 0040d009 (Size: 52 bytes) */
void FUN_0040d009(int x,int y,int width,int height);;

/* Function at 0040d03d (Size: 50 bytes) */
void FUN_0040d03d(int value,int min_val,int max_val);;

/* Function at 0040d06f (Size: 50 bytes) */
void FUN_0040d06f(int value,int min_val,int max_val);;

/* Function at 0040d0a1 (Size: 50 bytes) */
void FUN_0040d0a1(int value,int min_val,int max_val);;

/* Function at 0040d0d3 (Size: 50 bytes) */
void FUN_0040d0d3(int value,int min_val,int max_val);;

/* Function at 0040d105 (Size: 50 bytes) */
void FUN_0040d105(int value,int min_val,int max_val);;

/* Function at 0040d137 (Size: 50 bytes) */
void FUN_0040d137(int value,int min_val,int max_val);;

/* Function at 0040d169 (Size: 50 bytes) */
void FUN_0040d169(int value,int min_val,int max_val);;

/* Function at 0040d19b (Size: 50 bytes) */
void FUN_0040d19b(int value,int min_val,int max_val);;

/* Function at 0040d1cd (Size: 52 bytes) */
void FUN_0040d1cd(int x,int y,int width,int height);;

/* Function at 0040d201 (Size: 52 bytes) */
void FUN_0040d201(int x,int y,int width,int height);;

/* Function at 0040d235 (Size: 52 bytes) */
void FUN_0040d235(int x,int y,int width,int height);;

/* Function at 0040d269 (Size: 52 bytes) */
void FUN_0040d269(int x,int y,int width,int height);;

/* Function at 0040d29d (Size: 52 bytes) */
void FUN_0040d29d(int x,int y,int width,int height);;

/* Function at 0040d2d1 (Size: 52 bytes) */
void FUN_0040d2d1(int x,int y,int width,int height);;

/* Function at 0040d305 (Size: 52 bytes) */
void FUN_0040d305(int x,int y,int width,int height);;

/* Function at 0040d339 (Size: 52 bytes) */
void FUN_0040d339(int x,int y,int width,int height);;

/* Function at 0040d36d (Size: 50 bytes) */
void FUN_0040d36d(int value,int min_val,int max_val);;

/* Function at 0040d39f (Size: 50 bytes) */
void FUN_0040d39f(int value,int min_val,int max_val);;

/* Function at 0040d3d1 (Size: 50 bytes) */
void FUN_0040d3d1(int value,int min_val,int max_val);;

/* Function at 0040d403 (Size: 50 bytes) */
void FUN_0040d403(int value,int min_val,int max_val);;

/* Function at 0040d435 (Size: 52 bytes) */
void FUN_0040d435(int x,int y,int width,int height);;

/* Function at 0040d469 (Size: 52 bytes) */
void FUN_0040d469(int x,int y,int width,int height);;

/* Function at 0040d49d (Size: 52 bytes) */
void FUN_0040d49d(int x,int y,int width,int height);;

/* Function at 0040d4d1 (Size: 52 bytes) */
void Font_DrawTextInRect(int x, int y, int width, int height);;

/* Function at 0040d510 (Size: 66 bytes) */
int32_t FUN_0040d510(int value,int min_val,int max_val);;

/* Function at 0040d552 (Size: 74 bytes) */
int32_t FUN_0040d552(int value,int min_val,int max_val);;

/* Function at 0040d59c (Size: 176 bytes) */
void FUN_0040d59c(int value,uint32_t min_val,int max_val);;

/* Function at 0040d64c (Size: 223 bytes) */
void FUN_0040d64c(int value,uint32_t min_val,int max_val);;

/* Function at 0040d72b (Size: 190 bytes) */
void FUN_0040d72b(int value,uint32_t min_val,int max_val);;

/* Function at 0040d7e9 (Size: 66 bytes) */
int32_t FUN_0040d7e9(int value,int min_val,int max_val);;

/* Function at 0040d82b (Size: 74 bytes) */
int32_t FUN_0040d82b(int value,int min_val,int max_val);;

/* Function at 0040d875 (Size: 66 bytes) */
int32_t FUN_0040d875(int value,int min_val,int max_val);;

/* Function at 0040d8b7 (Size: 74 bytes) */
int32_t FUN_0040d8b7(int value,int min_val,int max_val);;

/* Function at 0040d901 (Size: 72 bytes) */
int32_t FUN_0040d901(int value,int min_val,int max_val);;

/* Function at 0040d949 (Size: 892 bytes) */
int Font_DrawString(int value, uint32_t min_val, int max_val);;

/* Function at 0040dcca (Size: 338 bytes) */
int FUN_0040dcca(int x,int y,uint32_t width,int height);;

/* Function at 0040de30 (Size: 3070 bytes) */
void Sound_LoadWav_x_DuelSounds_artifact_0040de30(int value);;

/* Function at 0040eab1 (Size: 83 bytes) */
int FUN_0040eab1(void);;

/* Function at 0040eb04 (Size: 86 bytes) */
void FUN_0040eb04(int value);;

/* Function at 0040eb5a (Size: 835 bytes) */
void Pic_Load_winbak01_0040eb5a(int player,int card_slot);;

/* Function at 0040eea2 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0040eea2(void);;

/* Function at 0040eeb4 (Size: 1632 bytes) */
int32_t Bazaar_TradeCardDialogue(int player,int card_slot);;

/* Function at 0040f514 (Size: 290 bytes) */
void UI_PromptDeckInspection(uint8_t value);;

/* Function at 0040f636 (Size: 75 bytes) */
int FUN_0040f636(char *str_1);;

/* Function at 0040f681 (Size: 104 bytes) */
int FUN_0040f681(int *player,int32_t *card_slot);;

/* Function at 0040f6e9 (Size: 164 bytes) */
int FUN_0040f6e9(void);;

/* Function at 0040f78d (Size: 554 bytes) */
int FUN_0040f78d(int value);;

/* Function at 0040f9b7 (Size: 130 bytes) */
int FUN_0040f9b7(uint8_t value);;

/* Function at 0040fa39 (Size: 420 bytes) */
int32_t FUN_0040fa39(char *str_1,char *str_2,int max_val);;

/* Function at 0040fbe2 (Size: 184 bytes) */
int FUN_0040fbe2(void);;

/* Function at 0040fc9a (Size: 88 bytes) */
void FUN_0040fc9a(int value,char *str_2,char *str_3);;

/* Function at 0040fcf2 (Size: 11 bytes) */
void Mem_AllocOrFree_0040fcf2(void);;

/* Function at 0040fcfd (Size: 3913 bytes) */
int32_t Dungeon_Process_0040fcfd(int value,int min_val,int max_val);;

/* Function at 00410c7d (Size: 65 bytes) */
void FUN_00410c7d(char *value);;

/* Function at 00410cc0 (Size: 561 bytes) */
int Card_ApplyTriggerEffect(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 00410ef1 (Size: 622 bytes) */
int32_t FUN_00410ef1(int value,int min_val,int max_val);;

/* Function at 0041115f (Size: 162 bytes) */
int32_t FUN_0041115f(int value,int min_val,int max_val);;

/* Function at 00411201 (Size: 269 bytes) */
int32_t FUN_00411201(int value,int min_val,int max_val);;

/* Function at 0041130e (Size: 1093 bytes) */
int32_t FUN_0041130e(int value,int min_val,int max_val);;

/* Function at 00411753 (Size: 341 bytes) */
int32_t FUN_00411753(int value,int min_val,int max_val);;

/* Function at 004118a8 (Size: 1776 bytes) */
int32_t FUN_004118a8(int value,int min_val,int max_val);;

/* Function at 00411f98 (Size: 435 bytes) */
int32_t CardScript_NafsAsp_DamageTrigger(int value,int min_val,int max_val);;

/* Function at 0041214b (Size: 251 bytes) */
int32_t FUN_0041214b(int value,int min_val,int max_val);;

/* Function at 00412246 (Size: 461 bytes) */
int32_t FUN_00412246(int value,int min_val,int max_val);;

/* Function at 00412413 (Size: 371 bytes) */
int32_t FUN_00412413(int value,int min_val,int max_val);;

/* Function at 00412586 (Size: 260 bytes) */
int32_t FUN_00412586(int value,int min_val,int max_val);;

/* Function at 0041268a (Size: 437 bytes) */
bool UI_PromptLifeBidValidation(int value,int min_val,int max_val);;

/* Function at 0041283f (Size: 1750 bytes) */
int32_t FUN_0041283f(int value,int min_val,int max_val);;

/* Function at 00412f15 (Size: 1617 bytes) */
int32_t FUN_00412f15(int value,int min_val,int max_val);;

/* Function at 00413570 (Size: 761 bytes) */
int32_t FUN_00413570(int value,int min_val,int max_val);;

/* Function at 00413869 (Size: 457 bytes) */
int32_t FUN_00413869(int value,int min_val,int max_val);;

/* Function at 00413a32 (Size: 376 bytes) */
int32_t FUN_00413a32(int value,int min_val,int max_val);;

/* Function at 00413baa (Size: 343 bytes) */
int32_t FUN_00413baa(int value,int min_val,int max_val);;

/* Function at 00413d01 (Size: 140 bytes) */
int32_t FUN_00413d01(int player,int card_slot);;

/* Function at 00413d8d (Size: 551 bytes) */
int32_t FUN_00413d8d(int value,int min_val,int max_val);;

/* Function at 00413fb4 (Size: 700 bytes) */
int32_t FUN_00413fb4(int value,int min_val,int max_val);;

/* Function at 00414270 (Size: 813 bytes) */
int32_t FUN_00414270(int value,int min_val,int max_val);;

/* Function at 0041459d (Size: 519 bytes) */
int32_t FUN_0041459d(int value,int min_val,int max_val);;

/* Function at 004147a4 (Size: 189 bytes) */
int32_t FUN_004147a4(int value,int min_val,int max_val);;

/* Function at 00414875 (Size: 210 bytes) */
int32_t FUN_00414875(int value,int min_val,int max_val);;

/* Function at 00414947 (Size: 378 bytes) */
int32_t CardScript_NaturalSelection(int value,int32_t min_val,int max_val);;

/* Function at 00414ac1 (Size: 723 bytes) */
int32_t FUN_00414ac1(int value,int min_val,int max_val);;

/* Function at 00414d99 (Size: 448 bytes) */
int32_t Prompts_Load_00414d99(int spell_id,int target_id,int flags);;

/* Function at 00414f59 (Size: 295 bytes) */
int32_t FUN_00414f59(int value,int min_val,int max_val);;

/* Function at 00415080 (Size: 126 bytes) */
int32_t FUN_00415080(int value,int min_val,int max_val);;

/* Function at 004150fe (Size: 412 bytes) */
int32_t Prompts_Load_004150fe(int spell_id,int target_id,int flags);;

/* Function at 0041529a (Size: 637 bytes) */
int32_t Prompts_Load_0041529a(int spell_id,int target_id,int flags);;

/* Function at 00415517 (Size: 434 bytes) */
int32_t Prompts_Load_00415517(int spell_id,int target_id,int flags);;

/* Function at 004156c9 (Size: 599 bytes) */
int32_t Prompts_Load_004156c9(int spell_id,int target_id,int flags);;

/* Function at 00415920 (Size: 1064 bytes) */
int32_t Prompts_Load_00415920(int spell_id,int target_id,int flags);;

/* Function at 00415d48 (Size: 176 bytes) */
int32_t FUN_00415d48(int player,int card_slot);;

/* Function at 00415df8 (Size: 609 bytes) */
int32_t Prompts_Load_00415df8(int spell_id,int target_id,int flags);;

/* Function at 00416059 (Size: 208 bytes) */
int32_t FUN_00416059(int value,int min_val,int max_val);;

/* Function at 00416129 (Size: 249 bytes) */
int32_t FUN_00416129(int value,int min_val,int max_val);;

/* Function at 00416222 (Size: 777 bytes) */
int32_t Prompts_Load_00416222(int spell_id,int target_id,int flags);;

/* Function at 0041652b (Size: 641 bytes) */
int32_t Prompts_Load_0041652b(int spell_id,int target_id,int flags);;

/* Function at 004167ac (Size: 702 bytes) */
int32_t Prompts_Load_004167ac(int spell_id,int target_id,int flags);;

/* Function at 00416a6a (Size: 624 bytes) */
int32_t Prompts_Load_00416a6a(int spell_id,int target_id,int flags);;

/* Function at 00416cda (Size: 92 bytes) */
int32_t FUN_00416cda(int value,int min_val,int max_val);;

/* Function at 00416d36 (Size: 484 bytes) */
int32_t Prompts_Load_00416d36(int spell_id,int target_id,int flags);;

/* Function at 00416f1a (Size: 908 bytes) */
int32_t Prompts_Load_00416f1a(int spell_id,int target_id,int flags);;

/* Function at 004172a6 (Size: 951 bytes) */
int32_t Prompts_Load_004172a6(int spell_id,int target_id,int flags);;

/* Function at 0041765d (Size: 700 bytes) */
int32_t Prompts_Load_0041765d(int spell_id,int target_id,int flags);;

/* Function at 00417919 (Size: 139 bytes) */
int32_t FUN_00417919(int value,int min_val,int max_val);;

/* Function at 004179a4 (Size: 179 bytes) */
int32_t FUN_004179a4(int value,int min_val,int max_val);;

/* Function at 00417a57 (Size: 178 bytes) */
int32_t FUN_00417a57(int player,int card_slot);;

/* Function at 00417b09 (Size: 176 bytes) */
int32_t FUN_00417b09(int value,int min_val,int max_val);;

/* Function at 00417bb9 (Size: 221 bytes) */
int32_t FUN_00417bb9(int player,int card_slot);;

/* Function at 00417c96 (Size: 674 bytes) */
int32_t FUN_00417c96(int value,int min_val,int max_val);;

/* Function at 00417f38 (Size: 189 bytes) */
int32_t Prompts_Load_00417f38(int spell_id,int target_id,int flags);;

/* Function at 00417ff5 (Size: 607 bytes) */
int32_t Prompts_Load_00417ff5(int spell_id,int target_id,int flags);;

/* Function at 00418254 (Size: 653 bytes) */
int32_t Prompts_Load_00418254(int spell_id,int target_id,int flags);;

/* Function at 004184e1 (Size: 459 bytes) */
int32_t Prompts_Load_004184e1(int spell_id,int target_id,int flags);;

/* Function at 004186ac (Size: 126 bytes) */
bool FUN_004186ac(int value,int min_val,int max_val);;

/* Function at 0041872f (Size: 86 bytes) */
int32_t FUN_0041872f(int player,int card_slot);;

/* Function at 00418785 (Size: 1231 bytes) */
int32_t Prompts_Load_00418785(int spell_id,int target_id,int flags);;

/* Function at 00418c59 (Size: 209 bytes) */
void FUN_00418c59(int x,int y,int width,uint8_t flags);;

/* Function at 00418d2a (Size: 1942 bytes) */
int32_t Prompts_Load_00418d2a(int spell_id,int target_id,int flags);;

/* Function at 004194cf (Size: 213 bytes) */
void FUN_004194cf(int x,int y,int width,uint8_t flags);;

/* Function at 004195a4 (Size: 1963 bytes) */
int32_t Prompts_Load_004195a4(int spell_id,int target_id,int flags);;

/* Function at 00419d5e (Size: 1250 bytes) */
int32_t Prompts_Load_00419d5e(int spell_id,int target_id,int flags);;

/* Function at 0041a245 (Size: 636 bytes) */
uint32_t FUN_0041a245(int value,int min_val,int max_val);;

/* Function at 0041a4c6 (Size: 695 bytes) */
int32_t FUN_0041a4c6(int value,int min_val,int max_val);;

/* Function at 0041a782 (Size: 1594 bytes) */
int32_t FUN_0041a782(int value,int min_val,int max_val);;

/* Function at 0041adc1 (Size: 995 bytes) */
int32_t FUN_0041adc1(int value,int min_val,int max_val);;

/* Function at 0041b1ae (Size: 1250 bytes) */
int32_t Prompts_Load_0041b1ae(int spell_id,int target_id,int flags);;

/* Function at 0041b695 (Size: 519 bytes) */
uint32_t FUN_0041b695(int value,int min_val,int max_val);;

/* Function at 0041b89c (Size: 158 bytes) */
int32_t FUN_0041b89c(int value,int min_val,int max_val);;

/* Function at 0041b93a (Size: 42 bytes) */
void Mem_AllocOrFree_0041b93a(int value,int min_val,int max_val);;

/* Function at 0041b964 (Size: 38 bytes) */
void Mem_AllocOrFree_0041b964(int value,int min_val,int max_val);;

/* Function at 0041b98a (Size: 2213 bytes) */
int32_t Prompts_Load_0041b98a(int spell_id,int target_id,int flags,int height);;

/* Function at 0041c22f (Size: 1704 bytes) */
int32_t Prompts_Load_0041c22f(int spell_id,int target_id,int flags);;

/* Function at 0041c8e1 (Size: 697 bytes) */
int32_t Prompts_Load_0041c8e1(int spell_id,int target_id,int flags);;

/* Function at 0041cb9a (Size: 1029 bytes) */
uint32_t FUN_0041cb9a(int value,int min_val,int max_val);;

/* Function at 0041cf9f (Size: 117 bytes) */
int32_t FUN_0041cf9f(int value,int min_val,int max_val);;

/* Function at 0041d019 (Size: 402 bytes) */
int32_t FUN_0041d019(int value,int min_val,int max_val);;

/* Function at 0041d1ab (Size: 614 bytes) */
int32_t Prompts_Load_0041d1ab(int spell_id,int target_id,int flags);;

/* Function at 0041d411 (Size: 1173 bytes) */
int32_t FUN_0041d411(int value,int min_val,int max_val);;

/* Function at 0041d8a6 (Size: 156 bytes) */
int FUN_0041d8a6(int value);;

/* Function at 0041d942 (Size: 33 bytes) */
void Mem_AllocOrFree_0041d942(int value);;

/* Function at 0041d963 (Size: 106 bytes) */
int Card_UntapCard(int value, int min_val, int max_val);;

/* Function at 0041d9d2 (Size: 106 bytes) */
int Card_SetTapState(int value, int min_val, int max_val);;

/* Function at 0041da41 (Size: 294 bytes) */
void FUN_0041da41(int player,int card_slot);;

/* Function at 0041db67 (Size: 972 bytes) */
int Card_ApplyCombatDamage(int value, int min_val, int max_val, int flags, int flags);;

/* Function at 0041df33 (Size: 37 bytes) */
void Mem_AllocOrFree_0041df33(int x,int y,int width,int height);;

/* Function at 0041df60 (Size: 132 bytes) */
bool UI_RegisterClass_0041df60(LPCSTR str_1);;

/* Function at 0041dfe4 (Size: 874 bytes) */
LRESULT UI_WndProc_0041dfe4(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 0041e370 (Size: 278 bytes) */
int32_t FUN_0041e370(int player,int card_slot);;

/* Function at 0041e486 (Size: 508 bytes) */
int32_t FUN_0041e486(int player,int card_slot);;

/* Function at 0041e682 (Size: 566 bytes) */
int32_t FUN_0041e682(int player,int card_slot);;

/* Function at 0041e8b8 (Size: 981 bytes) */
int32_t FUN_0041e8b8(int player,int card_slot);;

/* Function at 0041ec8d (Size: 87 bytes) */
int32_t FUN_0041ec8d(int value);;

/* Function at 0041ece4 (Size: 86 bytes) */
int32_t FUN_0041ece4(int value);;

/* Function at 0041ed3a (Size: 76 bytes) */
int32_t FUN_0041ed3a(int value);;

/* Function at 0041ed86 (Size: 78 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0041ed86(int value);;

/* Function at 0041edd4 (Size: 855 bytes) */
int32_t FUN_0041edd4(void);;

/* Function at 0041f12b (Size: 46 bytes) */
int32_t Mem_AllocOrFree_0041f12b(int value);;

/* Function at 0041f159 (Size: 37 bytes) */
int32_t Mem_AllocOrFree_0041f159(int32_t value);;

/* Function at 0041f17e (Size: 149 bytes) */
int32_t FUN_0041f17e(int value,int min_val,int max_val);;

/* Function at 0041f213 (Size: 156 bytes) */
int32_t FUN_0041f213(void);;

/* Function at 0041f2af (Size: 165 bytes) */
int32_t FUN_0041f2af(int player,int card_slot);;

/* Function at 0041f354 (Size: 61 bytes) */
int FUN_0041f354(void);;

/* Function at 0041f391 (Size: 89 bytes) */
int FUN_0041f391(void);;

/* Function at 0041f3ea (Size: 2675 bytes) */
int FUN_0041f3ea(int32_t value,int32_t min_val,int max_val);;

/* Function at 0041fe70 (Size: 59 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0041fe70(int32_t player,int card_slot);;

/* Function at 0041feab (Size: 28 bytes) */
int32_t Mem_AllocOrFree_0041feab(void);;

/* Function at 0041fec7 (Size: 309 bytes) */
int32_t FUN_0041fec7(int value,int min_val,int max_val,int flags,char *str_5,int arg_6);;

/* Function at 0041fffc (Size: 595 bytes) */
int32_t FUN_0041fffc(int value,int *min_val,int max_val,int flags,char *str_5,int arg_6,int arg_7);;

/* Function at 0042024f (Size: 296 bytes) */
int32_t FUN_0042024f(int player,int card_slot);;

/* Function at 0042038c (Size: 1052 bytes) */
int32_t FUN_0042038c(int *value,int min_val,int max_val,int flags,int flags);;

/* Function at 004207a8 (Size: 2576 bytes) */
int Save_ProcessGame_004207a8(int value);;

/* Function at 004211bd (Size: 247 bytes) */
int32_t FUN_004211bd(int player,int card_slot);;

/* Function at 004212b4 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_004212b4(int value);;

/* Function at 004212f0 (Size: 479 bytes) */
int32_t FUN_004212f0(int player,int card_slot);;

/* Function at 004214cf (Size: 390 bytes) */
int32_t FUN_004214cf(int player,int card_slot);;

/* Function at 00421655 (Size: 144 bytes) */
int32_t Sound_LoadWav_x_sound_button2_00421655(int value);;

/* Function at 004216e5 (Size: 261 bytes) */
int32_t FUN_004216e5(int player,int card_slot);;

/* Function at 004217ea (Size: 321 bytes) */
int32_t FUN_004217ea(int value);;

/* Function at 0042192b (Size: 182 bytes) */
int32_t FUN_0042192b(int value);;

/* Function at 004219e1 (Size: 160 bytes) */
void FUN_004219e1(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 00421a81 (Size: 177 bytes) */
int32_t FUN_00421a81(int player,int card_slot);;

/* Function at 00421b32 (Size: 3986 bytes) */
int32_t Castle_Process_00421b32(void);;

/* Function at 00422b04 (Size: 1026 bytes) */
void FUN_00422b04(int value);;

/* Function at 00422f06 (Size: 380 bytes) */
void FUN_00422f06(void);;

/* Function at 004230bd (Size: 560 bytes) */
void Pic_Load_worlbak1_004230bd(int value);;

/* Function at 004232f0 (Size: 555 bytes) */
uint8_t * Pic_AllocateImageBuffer(int value,int min_val,int max_val);;

/* Function at 0042351b (Size: 792 bytes) */
int32_t Pic_LoadImageFile(int value,int32_t min_val,int32_t max_val,char *str_4,uint8_t *flags);;

/* Function at 00423833 (Size: 135 bytes) */
int Pic_LoadKimPicture(char *str_1);;

/* Function at 004238ba (Size: 52 bytes) */
int Pic_OpenArchiveStream(char *str_1,int card_slot);;

/* Function at 004238ee (Size: 43 bytes) */
void Pic_Subsystem_004238ee(int value);;

/* Function at 00423919 (Size: 39 bytes) */
void Pic_SeekImageStream(int32_t value);;

/* Function at 00423940 (Size: 60 bytes) */
int Pic_Subsystem_00423940(void);;

/* Function at 00423980 (Size: 353 bytes) */
int Sound_Init(int hInst,int32_t hWnd,uint32_t flags);;

/* Function at 00423ae1 (Size: 118 bytes) */
void CloseSnd(void);;

/* Function at 00423b57 (Size: 60 bytes) */
int32_t InitSndTrack(int32_t value,int32_t min_val,int32_t max_val);;

/* Function at 00423b93 (Size: 52 bytes) */
int32_t CloseSndTrack(int32_t value);;

/* Function at 00423bc7 (Size: 45 bytes) */
int32_t StopSndTrack(void);;

/* Function at 00423bf4 (Size: 69 bytes) */
int32_t PlaySnd(int32_t sound_id,int32_t flags);;

/* Function at 00423c39 (Size: 73 bytes) */
int32_t PlaySndFile(int32_t filename,int32_t loop_flag,int32_t out_handle);;

/* Function at 00423c82 (Size: 65 bytes) */
int32_t StopSnd(int32_t sound_id);;

/* Function at 00423cc3 (Size: 48 bytes) */
void PauseSnd(void);;

/* Function at 00423cf3 (Size: 69 bytes) */
int32_t ResumeSnd(int32_t player,int32_t card_slot);;

/* Function at 00423d38 (Size: 69 bytes) */
int32_t SetPitch(int32_t value,int32_t card_slot);;

/* Function at 00423d7d (Size: 69 bytes) */
int32_t GetPitch(int32_t player,int32_t card_slot);;

/* Function at 00423dc2 (Size: 69 bytes) */
int32_t SetVol(int32_t value,int32_t card_slot);;

/* Function at 00423e07 (Size: 69 bytes) */
int32_t GetVol(int32_t player,int32_t card_slot);;

/* Function at 00423e4c (Size: 69 bytes) */
int32_t SetPan(int32_t value,int32_t card_slot);;

/* Function at 00423e91 (Size: 69 bytes) */
int32_t GetPan(int32_t player,int32_t card_slot);;

/* Function at 00423ed6 (Size: 58 bytes) */
int32_t UpdateSnd(void);;

/* Function at 00423f10 (Size: 69 bytes) */
int32_t SetSndMarker(int32_t player,int32_t card_slot);;

/* Function at 00423f55 (Size: 69 bytes) */
int32_t PlaySndMarker(int32_t player,int32_t card_slot);;

/* Function at 00423f9a (Size: 65 bytes) */
int32_t GetSndTime(int32_t value);;

/* Function at 00423fdb (Size: 69 bytes) */
int32_t ResetSnd(int32_t player,int32_t card_slot);;

/* Function at 00424020 (Size: 69 bytes) */
int32_t GetSndState(int32_t player,int32_t card_slot);;

/* Function at 00424065 (Size: 66 bytes) */
int32_t GetAVISndBuff(int32_t player,int32_t card_slot);;

/* Function at 004240a7 (Size: 69 bytes) */
int32_t ReleaseAVISndBuff(int32_t player,int32_t card_slot);;

/* Function at 004240ec (Size: 55 bytes) */
int32_t GetSndHWND(void);;

/* Function at 00424123 (Size: 66 bytes) */
int32_t IsSndLoaded(int32_t player,int32_t card_slot);;

/* Function at 00424165 (Size: 73 bytes) */
int32_t GetLRUSnd(int32_t value,int32_t min_val,int32_t max_val);;

/* Function at 004241ae (Size: 58 bytes) */
void Pic_Subsystem_004241ae(void);;

/* Function at 004241f0 (Size: 146 bytes) */
bool UI_RegisterClass_004241f0(LPCSTR str_1);;

/* Function at 00424282 (Size: 516 bytes) */
LRESULT UI_WndProc_00424282(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam);;

/* Function at 004244a0 (Size: 81 bytes) */
void UI_LoadHallBackdrop(void);;

/* Function at 00424500 (Size: 597 bytes) */
int Pic_Subsystem_00424500(char *str_1,char *str_2);;

/* Function at 0042475a (Size: 340 bytes) */
int Pic_Subsystem_0042475a(char *str_1,char *str_2);;

/* Function at 004248b0 (Size: 248 bytes) */
int32_t UI_LoadPhaseBackdrop(LPCSTR str_1);;

/* Function at 004249a8 (Size: 118 bytes) */
void Pic_Subsystem_004249a8(void);;

/* Function at 00424a1e (Size: 209 bytes) */
int32_t UI_LoadPhaseCombatBackdrop(LPCSTR str_1);;

/* Function at 00424aef (Size: 48 bytes) */
void Pic_Subsystem_00424aef(void);;

/* Function at 00424b1f (Size: 4956 bytes) */
LRESULT UI_PhaseDisplayWndProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam);;

/* Function at 00425ee3 (Size: 1004 bytes) */
void Pic_Subsystem_00425ee3(POINT *x,RECT *min_val,int32_t *max_val,int *height);;

/* Function at 004262cf (Size: 585 bytes) */
void Pic_Subsystem_004262cf(LPRECT value,int min_val,int max_val,int flags,int flags);;

/* Function at 00426518 (Size: 685 bytes) */
void Pic_Subsystem_00426518(HDC hdc,int card_slot);;

/* Function at 004267c5 (Size: 4210 bytes) */
LRESULT UI_CombatDefenseWndProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam);;

/* Function at 0042784d (Size: 445 bytes) */
void Pic_Subsystem_0042784d(POINT *value,RECT *min_val,int32_t *max_val);;

/* Function at 00427a0a (Size: 449 bytes) */
void Pic_Subsystem_00427a0a(LPRECT value,int y,int width,int height);;

/* Function at 00427bcb (Size: 619 bytes) */
void Pic_Subsystem_00427bcb(HDC hdc,int card_slot);;

/* Function at 00427e36 (Size: 563 bytes) */
void Pic_Draw_00427e36(int *value,int32_t *min_val,char *str_3);;

/* Function at 004280cf (Size: 19 bytes) */
void Pic_Util_004280cf(void);;

/* Function at 00428320 (Size: 1278 bytes) */
int32_t Pic_Subsystem_00428320(int value,int min_val,int max_val);;

/* Function at 0042881e (Size: 1340 bytes) */
int32_t Pic_Subsystem_0042881e(int value,int min_val,int max_val);;

/* Function at 00428d5a (Size: 1245 bytes) */
int32_t Pic_Subsystem_00428d5a(int value,int min_val,int max_val);;

/* Function at 00429237 (Size: 1462 bytes) */
int32_t CardScript_SylvanLibrary(int spell_id,int target_id,int flags);;

/* Function at 004297ed (Size: 1675 bytes) */
int32_t CardScript_LandTax(int spell_id,int target_id,int flags);;

/* Function at 00429e7d (Size: 601 bytes) */
int CardScript_Kismet(int spell_id,int target_id,int flags);;

/* Function at 0042a0d6 (Size: 243 bytes) */
void Pic_Subsystem_0042a0d6(int value,int min_val,int max_val);;

/* Function at 0042a1c9 (Size: 2641 bytes) */
uint32_t Pic_Load_0042a1c9(int spell_id,int target_id,int flags);;

/* Function at 0042ac1f (Size: 510 bytes) */
int32_t Pic_Subsystem_0042ac1f(int player,int card_slot);;

/* Function at 0042ae1d (Size: 2008 bytes) */
int32_t CardScript_AnimateArtifact(int spell_id,int target_id,int flags);;

/* Function at 0042b5f5 (Size: 1209 bytes) */
int32_t Pic_Subsystem_0042b5f5(int value,int min_val,int max_val);;

/* Function at 0042baae (Size: 64 bytes) */
int32_t Pic_Subsystem_0042baae(int value,int min_val,int max_val);;

/* Function at 0042baee (Size: 64 bytes) */
int32_t Pic_Subsystem_0042baee(int value,int min_val,int max_val);;

/* Function at 0042bb2e (Size: 951 bytes) */
int32_t CardScript_AnimateWall(int spell_id,int target_id,int flags);;

/* Function at 0042bee5 (Size: 96 bytes) */
void CardScript_ControlMagic(int spell_id,int target_id,int flags);;

/* Function at 0042bf45 (Size: 96 bytes) */
void CardScript_StealArtifact(int spell_id,int target_id,int flags);;

/* Function at 0042bfa5 (Size: 2442 bytes) */
int32_t Pic_Subsystem_0042bfa5(int x,int y,int width,uint32_t height);;

/* Function at 0042c92f (Size: 292 bytes) */
int32_t Pic_Subsystem_0042c92f(int value,int min_val,int max_val);;

/* Function at 0042ca53 (Size: 1040 bytes) */
int Pic_Subsystem_0042ca53(int player,int card_slot);;

/* Function at 0042ce63 (Size: 2028 bytes) */
int32_t Pic_Subsystem_0042ce63(int x,int y,int width,int height);;

/* Function at 0042d64f (Size: 1242 bytes) */
int32_t Pic_Subsystem_0042d64f(int value,int min_val,int max_val);;

/* Function at 0042db29 (Size: 502 bytes) */
int32_t Pic_Subsystem_0042db29(int value,int min_val,int max_val);;

/* Function at 0042dd1f (Size: 1461 bytes) */
int32_t CardScript_Feedback(int spell_id,int target_id,int flags);;

/* Function at 0042e2d9 (Size: 1333 bytes) */
int32_t CardScript_Brainwash(int spell_id,int target_id,int flags);;

/* Function at 0042e80e (Size: 178 bytes) */
int32_t Pic_Subsystem_0042e80e(int value,int min_val,int max_val);;

/* Function at 0042e8c0 (Size: 933 bytes) */
int32_t CardScript_SpiritShackle(int spell_id,int target_id,int flags);;

/* Function at 0042ec65 (Size: 314 bytes) */
int32_t Pic_Subsystem_0042ec65(int player,int card_slot);;

/* Function at 0042ed9f (Size: 1369 bytes) */
int32_t CardScript_RelicBind(uint32_t spell_id,int target_id,int flags);;

/* Function at 0042f2f8 (Size: 915 bytes) */
uint32_t Pic_Subsystem_0042f2f8(int value,int min_val,int max_val);;

/* Function at 0042f690 (Size: 249 bytes) */
int32_t Pic_Subsystem_0042f690(int value,int min_val,int max_val);;

/* Function at 0042f789 (Size: 242 bytes) */
int32_t Pic_Subsystem_0042f789(int value,int min_val,int max_val);;

/* Function at 0042f87b (Size: 1562 bytes) */
int32_t CardScript_PowerLeak(int spell_id,int target_id,int flags);;

/* Function at 0042fe9a (Size: 387 bytes) */
int32_t Pic_Subsystem_0042fe9a(int value,int min_val,int max_val);;

/* Function at 0043001d (Size: 407 bytes) */
int32_t Pic_Subsystem_0043001d(int value,int min_val,int max_val);;

/* Function at 004301b4 (Size: 158 bytes) */
int32_t Pic_Subsystem_004301b4(int value,int min_val,int max_val);;

/* Function at 00430252 (Size: 922 bytes) */
uint32_t Pic_Subsystem_00430252(int value,int min_val,int max_val);;

/* Function at 004305f1 (Size: 283 bytes) */
int32_t Pic_Subsystem_004305f1(int value,int min_val,int max_val);;

/* Function at 0043070c (Size: 2036 bytes) */
int32_t CardScript_Erosion(int spell_id,int target_id,int flags);;

/* Function at 00430f0a (Size: 1326 bytes) */
int32_t CardScript_CursedLand(int spell_id,int target_id,int flags);;

/* Function at 0043143d (Size: 650 bytes) */
uint32_t Pic_Subsystem_0043143d(int value,int min_val,int max_val);;

/* Function at 004316cc (Size: 756 bytes) */
int32_t Pic_Subsystem_004316cc(int value,int min_val,int max_val);;

/* Function at 004319c5 (Size: 1294 bytes) */
int32_t CardScript_EvilPresence(int spell_id,int target_id,int flags);;

/* Function at 00431ed3 (Size: 1830 bytes) */
int32_t CardScript_LivingArtifact(int spell_id,int target_id,int flags);;

/* Function at 004325fe (Size: 1300 bytes) */
int32_t CardScript_Blight(int spell_id,int target_id,int flags);;

/* Function at 00432b12 (Size: 1118 bytes) */
int32_t CardScript_TargetLand(int spell_id,int target_id,int flags);;

/* Function at 00432f70 (Size: 231 bytes) */
int32_t Pic_Subsystem_00432f70(int value,int min_val,int max_val);;

/* Function at 00433057 (Size: 475 bytes) */
int32_t Pic_Subsystem_00433057(int value,int min_val,int max_val);;

/* Function at 00433232 (Size: 258 bytes) */
int32_t Pic_Subsystem_00433232(int value,int min_val,int max_val);;

/* Function at 00433334 (Size: 306 bytes) */
void Pic_Subsystem_00433334(int value,int32_t min_val,int max_val);;

/* Function at 00433466 (Size: 438 bytes) */
int32_t Pic_Subsystem_00433466(int value,int min_val,int max_val);;

/* Function at 0043361c (Size: 220 bytes) */
int32_t Pic_Subsystem_0043361c(int value,int min_val,int max_val);;

/* Function at 004336f8 (Size: 934 bytes) */
int32_t Pic_Subsystem_004336f8(int value,int min_val,int max_val);;

/* Function at 00433a9e (Size: 229 bytes) */
int32_t Pic_Subsystem_00433a9e(int value,int min_val,int max_val);;

/* Function at 00433b83 (Size: 223 bytes) */
int32_t Pic_Subsystem_00433b83(int value,int min_val,int max_val);;

/* Function at 00433c62 (Size: 851 bytes) */
int32_t CardScript_AspectOfWolf(int spell_id,int target_id,int flags);;

/* Function at 00433fb5 (Size: 1401 bytes) */
int32_t File_Load_Prompts(int spell_id,int target_id,int flags);;

/* Function at 0043452e (Size: 123 bytes) */
int32_t Pic_Subsystem_0043452e(int x,int min_val,int max_val,int flags);;

/* Function at 004345a9 (Size: 1398 bytes) */
int32_t CardScript_SpiritLink(int spell_id,int target_id,int flags);;

/* Function at 00434b1f (Size: 1043 bytes) */
int32_t CardScript_CreatureBond(int spell_id,int target_id,int flags);;

/* Function at 00434f32 (Size: 1153 bytes) */
int32_t CardScript_GaseousForm(int spell_id,int target_id,int flags);;

/* Function at 004353b3 (Size: 1804 bytes) */
int32_t CardScript_Backfire(int spell_id,int target_id,int flags);;

/* Function at 00435abf (Size: 2625 bytes) */
int32_t CardScript_HolyArmor(int spell_id,int target_id,int flags);;

/* Function at 00436500 (Size: 2656 bytes) */
int32_t CardScript_Blessing(int spell_id,int target_id,int flags);;

/* Function at 00436f60 (Size: 2522 bytes) */
int32_t CardScript_Firebreathing(int spell_id,int target_id,int flags);;

/* Function at 0043793a (Size: 387 bytes) */
void CardScript_Invisibility(int spell_id,int target_id,int flags);;

/* Function at 00437ac2 (Size: 820 bytes) */
int32_t File_Load_Prompts(int spell_id,int target_id,int flags);;

/* Function at 00437df6 (Size: 820 bytes) */
int32_t CardScript_Seeker(int spell_id,int target_id,int flags);;

/* Function at 0043812a (Size: 754 bytes) */
int32_t File_Load_Prompts(int spell_id,int target_id,int flags);;

/* Function at 0043841c (Size: 1143 bytes) */
int32_t Pic_Subsystem_0043841c(int value,int min_val,int max_val);;

/* Function at 00438893 (Size: 258 bytes) */
int32_t Pic_Subsystem_00438893(int value,int min_val,int max_val);;

/* Function at 00438995 (Size: 856 bytes) */
int32_t Pic_Subsystem_00438995(int value,int min_val,int max_val);;

/* Function at 00438ced (Size: 1819 bytes) */
int32_t CardScript_Paralyze(int spell_id,int target_id,int flags);;

/* Function at 00439408 (Size: 987 bytes) */
int32_t Pic_Subsystem_00439408(int value,int min_val,int max_val);;

/* Function at 004397e3 (Size: 938 bytes) */
int32_t Pic_Subsystem_004397e3(int value,int min_val,int max_val);;

/* Function at 00439b92 (Size: 500 bytes) */
uint32_t CardScript_Cocoon(int spell_id,int target_id,int flags);;

/* Function at 00439d8b (Size: 123 bytes) */
void CardScript_Burrowing(int spell_id,int target_id,int flags);;

/* Function at 00439e06 (Size: 1313 bytes) */
int32_t CardScript_Wanderlust(int spell_id,int target_id,int flags);;

/* Function at 0043a32c (Size: 2364 bytes) */
int32_t CardScript_InstillEnergy(int spell_id,int target_id,int flags);;

/* Function at 0043ac68 (Size: 811 bytes) */
int32_t CardScript_Flood(int spell_id,int target_id,int flags);;

/* Function at 0043af93 (Size: 212 bytes) */
int32_t Pic_Subsystem_0043af93(int value,int min_val,int max_val);;

/* Function at 0043b067 (Size: 368 bytes) */
int32_t Pic_Subsystem_0043b067(int value,int min_val,int max_val);;

/* Function at 0043b1d7 (Size: 77 bytes) */
int32_t Pic_Subsystem_0043b1d7(int value,int min_val,int max_val);;

/* Function at 0043b224 (Size: 512 bytes) */
int32_t Pic_Subsystem_0043b224(int value,int min_val,int max_val);;

/* Function at 0043b424 (Size: 711 bytes) */
int32_t Pic_Subsystem_0043b424(int value,int min_val,int max_val);;

/* Function at 0043b6eb (Size: 99 bytes) */
void CardScript_Lance(int spell_id,int target_id,int flags);;

/* Function at 0043b74e (Size: 123 bytes) */
void CardScript_FishliverOil(int spell_id,int target_id,int flags);;

/* Function at 0043b7c9 (Size: 677 bytes) */
void Pic_Subsystem_0043b7c9(int x,int y,int width,uint32_t height);;

/* Function at 0043ba6e (Size: 98 bytes) */
void CardScript_HolyStrength(int spell_id,int target_id,int flags);;

/* Function at 0043bad0 (Size: 98 bytes) */
void CardScript_GiantStrength(int spell_id,int target_id,int flags);;

/* Function at 0043bb32 (Size: 98 bytes) */
void CardScript_Immolation(int spell_id,int target_id,int flags);;

/* Function at 0043bb94 (Size: 98 bytes) */
void CardScript_DivineTransformation(int spell_id,int target_id,int flags);;

/* Function at 0043bbf6 (Size: 98 bytes) */
void CardScript_UnholyStrength(int spell_id,int target_id,int flags);;

/* Function at 0043bc58 (Size: 98 bytes) */
void CardScript_Weakness(int spell_id,int target_id,int flags);;

/* Function at 0043bcba (Size: 1006 bytes) */
int32_t Pic_Subsystem_0043bcba(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 0043c0b2 (Size: 194 bytes) */
int32_t Pic_Subsystem_0043c0b2(int value,int min_val,int max_val);;

/* Function at 0043c174 (Size: 55 bytes) */
void Pic_Subsystem_0043c174(int value,int min_val,int max_val);;

/* Function at 0043c1ab (Size: 55 bytes) */
void Pic_Subsystem_0043c1ab(int value,int min_val,int max_val);;

/* Function at 0043c1e2 (Size: 55 bytes) */
void Pic_Subsystem_0043c1e2(int value,int min_val,int max_val);;

/* Function at 0043c219 (Size: 55 bytes) */
void Pic_Subsystem_0043c219(int value,int min_val,int max_val);;

/* Function at 0043c250 (Size: 55 bytes) */
void Pic_Subsystem_0043c250(int value,int min_val,int max_val);;

/* Function at 0043c287 (Size: 1646 bytes) */
int32_t CardScript_AnyWard(int spell_id,int target_id,int flags,int height);;

/* Function at 0043c8f5 (Size: 2249 bytes) */
int32_t CardScript_UnstableMutation(int spell_id,int target_id,int flags);;

/* Function at 0043d1c3 (Size: 2124 bytes) */
int32_t CardScript_CopyArtifact(int spell_id,int target_id,int flags);;

/* Function at 0043da0f (Size: 1447 bytes) */
int32_t CardScript_TargetArtifact(int spell_id,int target_id,int flags);;

/* Function at 0043dfbb (Size: 315 bytes) */
int32_t Pic_Subsystem_0043dfbb(int value,int min_val,int max_val);;

/* Function at 0043e0f6 (Size: 1697 bytes) */
int32_t Pic_Subsystem_0043e0f6(int value,int min_val,int max_val);;

/* Function at 0043e79c (Size: 1054 bytes) */
int32_t Pic_Subsystem_0043e79c(int value,int min_val,int max_val);;

/* Function at 0043ebbf (Size: 1503 bytes) */
int32_t CardScript_Regeneration(int spell_id,int target_id,int flags);;

/* Function at 0043f19e (Size: 895 bytes) */
int32_t CardScript_EternalWarrior(int spell_id,int target_id,int flags);;

/* Function at 0043f51d (Size: 1498 bytes) */
int32_t CardScript_TheBrute(int spell_id,int target_id,int flags);;

/* Function at 0043faf7 (Size: 639 bytes) */
uint32_t CardScript_Earthbind(int spell_id,int target_id,int flags);;

/* Function at 0043fd7b (Size: 55 bytes) */
void Pic_Subsystem_0043fd7b(int value,int min_val,int max_val);;

/* Function at 0043fdb2 (Size: 55 bytes) */
void Pic_Subsystem_0043fdb2(int value,int min_val,int max_val);;

/* Function at 0043fde9 (Size: 55 bytes) */
void Pic_Subsystem_0043fde9(int value,int min_val,int max_val);;

/* Function at 0043fe20 (Size: 55 bytes) */
void Pic_Subsystem_0043fe20(int value,int min_val,int max_val);;

/* Function at 0043fe57 (Size: 55 bytes) */
void Pic_Subsystem_0043fe57(int value,int min_val,int max_val);;

/* Function at 0043fe8e (Size: 1014 bytes) */
int32_t CardScript_CircleOfProtection(int spell_id,int target_id,int flags,int height);;

/* Function at 00440289 (Size: 1027 bytes) */
int32_t CardScript_CircleOfProtection(int spell_id,int target_id,int flags);;

/* Function at 0044068c (Size: 1213 bytes) */
int32_t CardScript_PhantasmalTerrain(int spell_id,int target_id,int flags);;

/* Function at 00440b49 (Size: 620 bytes) */
int32_t Pic_Subsystem_00440b49(int value,int min_val,int max_val);;

/* Function at 00440db5 (Size: 946 bytes) */
int32_t CardScript_WildGrowth(int spell_id,int target_id,int flags);;

/* Function at 00441167 (Size: 885 bytes) */
int32_t CardScript_Flight(int spell_id,int target_id,int flags);;

/* Function at 004414dc (Size: 686 bytes) */
int32_t Pic_Subsystem_004414dc(int value,int min_val,int max_val);;

/* Function at 0044178f (Size: 686 bytes) */
int32_t Pic_Subsystem_0044178f(int value,int min_val,int max_val);;

/* Function at 00441a42 (Size: 1480 bytes) */
int Pic_Subsystem_00441a42(int player,int card_slot);;

/* Function at 00442010 (Size: 145 bytes) */
bool UI_RegisterClass_00442010(LPCSTR str_1);;

/* Function at 004420a1 (Size: 6620 bytes) */
uint32_t Catalog_LoadAllBigCardArtPics(HWND hwnd,uint32_t y,void *max_val,int *height);;

/* Function at 00443b0c (Size: 87 bytes) */
WPARAM Pic_Subsystem_00443b0c(void);;

/* Function at 00443b63 (Size: 1636 bytes) */
int32_t Pic_Clip_00443b63(HWND hwnd);;

/* Function at 004441cc (Size: 3831 bytes) */
void Pic_Subsystem_004441cc(HWND hwnd,int card_slot);;

/* Function at 004450c3 (Size: 1243 bytes) */
void UI_LoadGraveyardBackdrops(int value,int min_val,int max_val);;

/* Function at 0044559e (Size: 69 bytes) */
void Pic_Subsystem_0044559e(void);;

/* Function at 004455e3 (Size: 704 bytes) */
int32_t UI_RegisterThinkingCardClass(HWND hwnd,uint32_t y,HDC hdc,int32_t flags);;

/* Function at 004458b0 (Size: 4135 bytes) */
uint32_t UI_PromptFastEffectsDialog(int player,char *str_2);;

/* Function at 004468dc (Size: 1142 bytes) */
uint32_t Pic_Subsystem_004468dc(int value);;

/* Function at 00446d52 (Size: 1260 bytes) */
int32_t Pic_Subsystem_00446d52(int player,int card_slot);;

/* Function at 0044724d (Size: 840 bytes) */
int32_t Pic_Subsystem_0044724d(void);;

/* Function at 004475a4 (Size: 1142 bytes) */
void Rules_ProcessDamagePrevention(void);;

/* Function at 00447a1a (Size: 317 bytes) */
void Pic_Subsystem_00447a1a(void);;

/* Function at 00447b57 (Size: 2677 bytes) */
int Pic_Subsystem_00447b57(int player,int card_slot);;

/* Function at 004485d6 (Size: 168 bytes) */
int32_t Magic_BroadcastCardEventInStep(int player,int slot,int event_code,int32_t event_arg);;

/* Function at 0044867e (Size: 546 bytes) */
void Pic_Subsystem_0044867e(int value,int min_val,int max_val);;

/* Function at 004488a0 (Size: 191 bytes) */
int32_t Rules_SendCardsToGraveyard(void);;

/* Function at 0044895f (Size: 1226 bytes) */
int32_t Rules_CardLeavingPlay(int player,int card_slot);;

/* Function at 00448e29 (Size: 785 bytes) */
void Pic_Subsystem_00448e29(int player,int card_slot);;

/* Function at 0044913a (Size: 233 bytes) */
void Pic_Subsystem_0044913a(int player,int card_slot);;

/* Function at 00449223 (Size: 121 bytes) */
void Pic_Subsystem_00449223(int player,int card_slot);;

/* Function at 0044929c (Size: 164 bytes) */
void Pic_Subsystem_0044929c(int player,int card_slot);;

/* Function at 00449340 (Size: 401 bytes) */
bool UI_RegisterExpandedGraveyardClass(LPCSTR str_1);;

/* Function at 004494d1 (Size: 46 bytes) */
void Pic_Subsystem_004494d1(void);;

/* Function at 004494ff (Size: 2624 bytes) */
LRESULT UI_GraveyardMenuProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam);;

/* Function at 00449fbb (Size: 366 bytes) */
LRESULT UI_WndProc_00449fbb(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 0044a135 (Size: 705 bytes) */
LRESULT UI_WndProc_0044a135(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 0044a402 (Size: 970 bytes) */
HWND UI_GraveyardListWndProc(HWND hwnd,int card_slot);;

/* Function at 0044a7cc (Size: 21 bytes) */
void Pic_Util_0044a7cc(HWND hwnd);;

/* Function at 0044a7e1 (Size: 83 bytes) */
int32_t Pic_Subsystem_0044a7e1(int value);;

/* Function at 0044a839 (Size: 41 bytes) */
void Pic_Subsystem_0044a839(void);;

/* Function at 0044a862 (Size: 2560 bytes) */
HGDIOBJ UI_AnteDisplayWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 0044b26c (Size: 496 bytes) */
void Pic_Subsystem_0044b26c(LPRECT value,HWND hwnd,int width,int height);;

/* Function at 0044b460 (Size: 985 bytes) */
void Font_LoadCustomFonts(void);;

/* Function at 0044b839 (Size: 18 bytes) */
int32_t Pic_Util_0044b839(void);;

/* Function at 0044b84b (Size: 95 bytes) */
void Pic_Subsystem_0044b84b(void);;

/* Function at 0044b8aa (Size: 48 bytes) */
void Pic_Subsystem_0044b8aa(void);;

/* Function at 0044b8da (Size: 48 bytes) */
void UI_PrepareCombatViewport(void);;

/* Function at 0044b90a (Size: 57 bytes) */
void Pic_Subsystem_0044b90a(char *player,int32_t card_slot);;

/* Function at 0044b943 (Size: 23 bytes) */
void Pic_Util_0044b943(int32_t player,short *card_slot);;

/* Function at 0044b95a (Size: 18 bytes) */
int32_t Pic_Util_0044b95a(void);;

/* Function at 0044b96c (Size: 81 bytes) */
int32_t Pic_Subsystem_0044b96c(int value);;

/* Function at 0044b9c0 (Size: 195 bytes) */
bool UI_RegisterClass_0044b9c0(LPCSTR str_1);;

/* Function at 0044ba83 (Size: 81 bytes) */
void Pic_Subsystem_0044ba83(void);;

/* Function at 0044bad4 (Size: 5255 bytes) */
LRESULT UI_PlayerHandCardWndProc(HWND hwnd,uint32_t y,int32_t *max_val,LONG *flags);;

/* Function at 0044cfe4 (Size: 822 bytes) */
void Pic_Subsystem_0044cfe4(HWND hwnd);;

/* Function at 0044d31a (Size: 629 bytes) */
void Pic_Subsystem_0044d31a(int value,int *min_val,int *max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,HANDLE arg_9);;

/* Function at 0044d58f (Size: 139 bytes) */
void Pic_Subsystem_0044d58f(int32_t value,int min_val,int max_val,int flags,int flags,int arg_6,int *arg_7,int *arg_8,int *arg_9,int *arg_10);;

/* Function at 0044d61a (Size: 93 bytes) */
void UI_DrawPlayerHandWindow(char *str_1,HWND hwnd,int32_t max_val);;

/* Function at 0044d680 (Size: 869 bytes) */
void Pic_Subsystem_0044d680(void);;

/* Function at 0044da1a (Size: 11 bytes) */
void Pic_Util_0044da1a(void);;

/* Function at 0044da25 (Size: 1876 bytes) */
int32_t Pic_Subsystem_0044da25(void);;

/* Function at 0044e17e (Size: 361 bytes) */
void Pic_Subsystem_0044e17e(void);;

/* Function at 0044e2e7 (Size: 577 bytes) */
int32_t Pic_Subsystem_0044e2e7(int x,int y,int width,int height);;

/* Function at 0044e528 (Size: 565 bytes) */
void Pic_Subsystem_0044e528(void);;

/* Function at 0044e75d (Size: 231 bytes) */
void Pic_Subsystem_0044e75d(int value,int min_val,int max_val);;

/* Function at 0044e844 (Size: 32 bytes) */
void Pic_Util_0044e844(int player,int card_slot);;

/* Function at 0044e864 (Size: 328 bytes) */
void Pic_Subsystem_0044e864(int player,int card_slot);;

/* Function at 0044e9ac (Size: 497 bytes) */
void Pic_Subsystem_0044e9ac(void);;

/* Function at 0044eb9d (Size: 259 bytes) */
int Pic_Subsystem_0044eb9d(int player,int card_slot);;

/* Function at 0044eca0 (Size: 341 bytes) */
void SaveGame_SaveGauntletFile(void);;

/* Function at 0044edf5 (Size: 270 bytes) */
void SaveGame_AutoSave(int32_t value);;

/* Function at 0044ef03 (Size: 98 bytes) */
void Pic_Subsystem_0044ef03(LPCSTR str_1);;

/* Function at 0044ef70 (Size: 607 bytes) */
int32_t Deck_LoadOneDeckProfile(int32_t player,LPVOID out_buffer);;

/* Function at 0044f1de (Size: 5427 bytes) */
int32_t Pic_Subsystem_0044f1de(int32_t player,int card_slot);;

/* Function at 00450711 (Size: 302 bytes) */
void Pic_Subsystem_00450711(int32_t *value,int32_t *min_val,int32_t *max_val);;

/* Function at 0045083f (Size: 310 bytes) */
void Pic_Subsystem_0045083f(int player,int card_slot);;

/* Function at 00450975 (Size: 39 bytes) */
void Pic_Util_00450975(DWORD value);;

/* Function at 004509a1 (Size: 71 bytes) */
void Pic_Subsystem_004509a1(int value,int *min_val,int max_val,int flags,int32_t flags,int arg_6,char *arg_7);;

/* Function at 004509e8 (Size: 2212 bytes) */
int UI_DeckSelectionMenu(int value,int min_val,int max_val,int32_t flags,int flags);;

/* Function at 00451291 (Size: 186 bytes) */
int Deck_AddCardToDeck(int player,int card_slot);;

/* Function at 0045134b (Size: 1837 bytes) */
void Pic_Subsystem_0045134b(int value,int min_val,int max_val);;

/* Function at 00451a82 (Size: 154 bytes) */
int32_t Pic_Subsystem_00451a82(void);;

/* Function at 00451b1c (Size: 406 bytes) */
int Pic_Subsystem_00451b1c(int player,int card_slot);;

/* Function at 00451cb2 (Size: 222 bytes) */
uint32_t Pic_Subsystem_00451cb2(void);;

/* Function at 00451d90 (Size: 176 bytes) */
int Pic_Subsystem_00451d90(uint32_t player,uint32_t card_slot);;

/* Function at 00451e40 (Size: 461 bytes) */
int Pic_Subsystem_00451e40(uint32_t value);;

/* Function at 0045200d (Size: 88 bytes) */
void Pic_Subsystem_0045200d(uint32_t value);;

/* Function at 00452065 (Size: 77 bytes) */
void Pic_Subsystem_00452065(int value);;

/* Function at 004520b2 (Size: 244 bytes) */
void Pic_Subsystem_004520b2(void);;

/* Function at 004521a6 (Size: 208 bytes) */
int32_t Pic_Subsystem_004521a6(int value,int min_val,int max_val);;

/* Function at 00452276 (Size: 391 bytes) */
void Pic_Subsystem_00452276(int value);;

/* Function at 004523fd (Size: 97 bytes) */
void Pic_Subsystem_004523fd(int player,int card_slot);;

/* Function at 0045245e (Size: 125 bytes) */
int Pic_Subsystem_0045245e(int player,int32_t card_slot);;

/* Function at 004524db (Size: 118 bytes) */
void Pic_Subsystem_004524db(int player,int32_t card_slot);;

/* Function at 00452551 (Size: 318 bytes) */
int File_Load_Info(int value);;

/* Function at 0045268f (Size: 121 bytes) */
int Pic_Subsystem_0045268f(int value);;

/* Function at 00452708 (Size: 82 bytes) */
void Pic_Subsystem_00452708(char *str_1);;

/* Function at 0045275a (Size: 57 bytes) */
void Pic_Subsystem_0045275a(uint8_t *value);;

/* Function at 00452793 (Size: 41 bytes) */
void Engine_ReportFatalError(char *value);;

/* Function at 004527bc (Size: 80 bytes) */
void UI_DrawCombatBanner(void);;

/* Function at 0045280c (Size: 27 bytes) */
void Ai_TriggerTurnPhaseEvaluation(void);;

/* Function at 00452827 (Size: 141 bytes) */
int Engine_CountActiveCreatures(void);;

/* Function at 004528c0 (Size: 494 bytes) */
int32_t UI_DrawManaSymbolBox(int x,int y,int width,int height);;

/* Function at 00452ab3 (Size: 38 bytes) */
void Minit_Subsystem_00452ab3(int value,int min_val,int max_val);;

/* Function at 00452ad9 (Size: 38 bytes) */
void Minit_Subsystem_00452ad9(int value,int min_val,int max_val);;

/* Function at 00452aff (Size: 38 bytes) */
void Minit_Subsystem_00452aff(int value,int min_val,int max_val);;

/* Function at 00452b25 (Size: 38 bytes) */
void Minit_Subsystem_00452b25(int value,int min_val,int max_val);;

/* Function at 00452b4b (Size: 38 bytes) */
void Minit_Subsystem_00452b4b(int value,int min_val,int max_val);;

/* Function at 00452b71 (Size: 779 bytes) */
void Mana_Init_00452b71(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 00452e81 (Size: 42 bytes) */
int32_t Minit_Subsystem_00452e81(int value,int min_val,int max_val);;

/* Function at 00452eab (Size: 42 bytes) */
int32_t Minit_Subsystem_00452eab(int value,int min_val,int max_val);;

/* Function at 00452ed5 (Size: 42 bytes) */
int32_t Minit_Subsystem_00452ed5(int value,int min_val,int max_val);;

/* Function at 00452eff (Size: 42 bytes) */
int32_t Minit_Subsystem_00452eff(int value,int min_val,int max_val);;

/* Function at 00452f29 (Size: 42 bytes) */
int32_t Minit_Subsystem_00452f29(int value,int min_val,int max_val);;

/* Function at 00452f53 (Size: 42 bytes) */
int32_t Minit_Subsystem_00452f53(int value,int min_val,int max_val);;

/* Function at 00452f7d (Size: 42 bytes) */
int32_t Minit_Subsystem_00452f7d(int value,int min_val,int max_val);;

/* Function at 00452fa7 (Size: 42 bytes) */
int32_t Minit_Subsystem_00452fa7(int value,int min_val,int max_val);;

/* Function at 00452fd1 (Size: 42 bytes) */
int32_t Minit_Subsystem_00452fd1(int value,int min_val,int max_val);;

/* Function at 00452ffb (Size: 42 bytes) */
int32_t Minit_Subsystem_00452ffb(int value,int min_val,int max_val);;

/* Function at 00453025 (Size: 716 bytes) */
int32_t Minit_Subsystem_00453025(int value,int min_val,int max_val);;

/* Function at 004532f1 (Size: 514 bytes) */
int32_t Mana_Init_004532f1(int value,int min_val,int max_val);;

/* Function at 0045350d (Size: 670 bytes) */
int32_t CardScript_Desert(int value,int min_val,int max_val);;

/* Function at 004537b0 (Size: 1200 bytes) */
int32_t CardScript_Oasis(int spell_id,int target_id,int flags);;

/* Function at 00453c60 (Size: 886 bytes) */
int32_t CardScript_ElephantsGraveyard(int value,int min_val,int max_val);;

/* Function at 00453fdb (Size: 1016 bytes) */
int32_t Mana_Init_00453fdb(int spell_id,int target_id,int flags);;

/* Function at 004543d3 (Size: 495 bytes) */
int32_t Minit_Subsystem_004543d3(int value,int min_val,int max_val);;

/* Function at 004545c7 (Size: 310 bytes) */
int32_t Minit_Subsystem_004545c7(int value,int min_val,int max_val);;

/* Function at 00454702 (Size: 739 bytes) */
int32_t Card_Setup_00454702(int value,int min_val,int max_val);;

/* Function at 004549ea (Size: 3033 bytes) */
int32_t Mana_Init_004549ea(int spell_id,int target_id,int flags);;

/* Function at 004555c8 (Size: 2960 bytes) */
int32_t Mana_Init_004555c8(int spell_id,int target_id,int flags);;

/* Function at 00456158 (Size: 192 bytes) */
int32_t Minit_Subsystem_00456158(int value,int min_val,int max_val);;

/* Function at 00456218 (Size: 477 bytes) */
int32_t Minit_Subsystem_00456218(int value,int min_val,int max_val);;

/* Function at 004563fa (Size: 339 bytes) */
int32_t Minit_Subsystem_004563fa(int value,int min_val,int max_val);;

/* Function at 00456552 (Size: 133 bytes) */
int32_t Minit_Subsystem_00456552(int32_t value,int32_t min_val,int max_val);;

/* Function at 004565d7 (Size: 339 bytes) */
int32_t Minit_Subsystem_004565d7(int value,int min_val,int max_val);;

/* Function at 0045672f (Size: 1364 bytes) */
int32_t CardScript_Arena(int spell_id,int target_id,int flags);;

/* Function at 00456d10 (Size: 38 bytes) */
void Minit_Subsystem_00456d10(int value,int min_val,int max_val);;

/* Function at 00456d36 (Size: 38 bytes) */
void Minit_Subsystem_00456d36(int value,int min_val,int max_val);;

/* Function at 00456d5c (Size: 38 bytes) */
void Minit_Subsystem_00456d5c(int value,int min_val,int max_val);;

/* Function at 00456d82 (Size: 38 bytes) */
void Minit_Subsystem_00456d82(int value,int min_val,int max_val);;

/* Function at 00456da8 (Size: 38 bytes) */
void Minit_Subsystem_00456da8(int value,int min_val,int max_val);;

/* Function at 00456dce (Size: 347 bytes) */
int32_t Minit_Subsystem_00456dce(int x,int y,int width,int height);;

/* Function at 00456f29 (Size: 897 bytes) */
int32_t Mana_Init_00456f29(int spell_id,int target_id,int flags);;

/* Function at 004572aa (Size: 1181 bytes) */
int32_t CardScript_TimeVault(int spell_id,int target_id,int flags);;

/* Function at 00457747 (Size: 562 bytes) */
int32_t Minit_Subsystem_00457747(int value,int min_val,int max_val);;

/* Function at 00457979 (Size: 566 bytes) */
int32_t Minit_Subsystem_00457979(int value,int min_val,int max_val);;

/* Function at 00457baf (Size: 428 bytes) */
int32_t Minit_Subsystem_00457baf(int value,int min_val,int max_val);;

/* Function at 00457d5b (Size: 268 bytes) */
int32_t Minit_Subsystem_00457d5b(int value,int min_val,int max_val);;

/* Function at 00457e67 (Size: 1839 bytes) */
int32_t CardScript_AladdinsLamp(int spell_id,int target_id,int flags);;

/* Function at 00458596 (Size: 322 bytes) */
int32_t Minit_Subsystem_00458596(int value,int min_val,int max_val);;

/* Function at 004586d8 (Size: 445 bytes) */
int32_t Minit_Subsystem_004586d8(int value,int min_val,int max_val);;

/* Function at 00458895 (Size: 882 bytes) */
int32_t Minit_Subsystem_00458895(int value,int min_val,int max_val);;

/* Function at 00458c07 (Size: 104 bytes) */
int32_t Minit_Subsystem_00458c07(int value,int min_val,int max_val);;

/* Function at 00458c6f (Size: 63 bytes) */
int32_t Minit_Subsystem_00458c6f(int player,int card_slot);;

/* Function at 00458cae (Size: 1030 bytes) */
int32_t Minit_Subsystem_00458cae(int value,int min_val,int max_val);;

/* Function at 004590b4 (Size: 506 bytes) */
int32_t Card_Setup_004590b4(int value,int min_val,int max_val);;

/* Function at 004592ae (Size: 554 bytes) */
int32_t Minit_Subsystem_004592ae(int value,int min_val,int max_val);;

/* Function at 004594d8 (Size: 759 bytes) */
int32_t CardScript_PrimalClay(int spell_id,int target_id,int flags);;

/* Function at 004597d4 (Size: 1329 bytes) */
int32_t CardScript_Shapeshifter(int spell_id,int target_id,int flags);;

/* Function at 00459d0a (Size: 1041 bytes) */
int32_t CardScript_Tetravite(int value,int min_val,int max_val);;

/* Function at 0045a120 (Size: 306 bytes) */
int Minit_Subsystem_0045a120(int player,int card_slot);;

/* Function at 0045a252 (Size: 472 bytes) */
int32_t CardScript_Tetravus(int spell_id,int target_id,int flags);;

/* Function at 0045a42a (Size: 331 bytes) */
int32_t Minit_Subsystem_0045a42a(int player,int card_slot);;

/* Function at 0045a575 (Size: 532 bytes) */
int32_t CardScript_Tetravite(int spell_id,int target_id);;

/* Function at 0045a789 (Size: 156 bytes) */
int32_t Minit_Subsystem_0045a789(int value,int min_val,int max_val);;

/* Function at 0045a825 (Size: 474 bytes) */
bool CardScript_Triskelion(int spell_id,int target_id,int flags);;

/* Function at 0045a9ff (Size: 1858 bytes) */
int32_t CardScript_UrzasAvenger(int spell_id,int target_id,int flags);;

/* Function at 0045b156 (Size: 940 bytes) */
int32_t CardScript_Millstone(int spell_id,int target_id,int flags);;

/* Function at 0045b502 (Size: 727 bytes) */
int32_t Mana_Init_0045b502(int spell_id,int target_id,int flags);;

/* Function at 0045b7d9 (Size: 1202 bytes) */
int32_t Mana_Init_0045b7d9(int spell_id,int target_id,int flags);;

/* Function at 0045bc8b (Size: 197 bytes) */
int32_t Minit_Subsystem_0045bc8b(int value,int min_val,int max_val);;

/* Function at 0045bd50 (Size: 2117 bytes) */
int32_t CardScript_AshnodsBattlegear(int spell_id,int target_id,int flags);;

/* Function at 0045c59a (Size: 2702 bytes) */
int32_t CardScript_TawnosWeaponry(int spell_id,int target_id,int flags);;

/* Function at 0045d028 (Size: 456 bytes) */
int32_t Minit_Subsystem_0045d028(int value,int min_val,int max_val);;

/* Function at 0045d1f0 (Size: 1618 bytes) */
int32_t CardScript_CandelabraOfTawnos(int spell_id,int target_id,int flags);;

/* Function at 0045d842 (Size: 77 bytes) */
int32_t Minit_Subsystem_0045d842(int value,int min_val,int max_val);;

/* Function at 0045d88f (Size: 77 bytes) */
int32_t Minit_Subsystem_0045d88f(int value,int min_val,int max_val);;

/* Function at 0045d8dc (Size: 1225 bytes) */
int32_t CardScript_Forcefield(int spell_id,int target_id,int flags);;

/* Function at 0045dda5 (Size: 716 bytes) */
int32_t CardScript_DisruptingScepter(int spell_id,int target_id,int flags);;

/* Function at 0045e071 (Size: 395 bytes) */
int32_t Minit_Subsystem_0045e071(int value,int min_val,int max_val);;

/* Function at 0045e1fc (Size: 169 bytes) */
int32_t Minit_Subsystem_0045e1fc(int value,int min_val,int max_val);;

/* Function at 0045e2a5 (Size: 171 bytes) */
int32_t Minit_Subsystem_0045e2a5(int value,int min_val,int max_val);;

/* Function at 0045e350 (Size: 34 bytes) */
int32_t Minit_Subsystem_0045e350(int32_t value,int32_t min_val,int max_val);;

/* Function at 0045e372 (Size: 38 bytes) */
void Minit_Subsystem_0045e372(int value,int min_val,int max_val);;

/* Function at 0045e398 (Size: 38 bytes) */
void Minit_Subsystem_0045e398(int value,int min_val,int max_val);;

/* Function at 0045e3be (Size: 38 bytes) */
void Minit_Subsystem_0045e3be(int value,int min_val,int max_val);;

/* Function at 0045e3e4 (Size: 38 bytes) */
void Minit_Subsystem_0045e3e4(int value,int min_val,int max_val);;

/* Function at 0045e40a (Size: 38 bytes) */
void Minit_Subsystem_0045e40a(int value,int min_val,int max_val);;

/* Function at 0045e430 (Size: 1569 bytes) */
int32_t Mana_Init_0045e430(int x,int y,int width,int height);;

/* Function at 0045ea5b (Size: 388 bytes) */
int32_t Minit_Subsystem_0045ea5b(int value,int min_val,int max_val);;

/* Function at 0045ebe4 (Size: 1647 bytes) */
int32_t CardScript_Conservator(int spell_id,int target_id,int flags);;

/* Function at 0045f258 (Size: 371 bytes) */
int32_t Minit_Subsystem_0045f258(int value,int min_val,int max_val);;

/* Function at 0045f3cb (Size: 38 bytes) */
void Minit_Subsystem_0045f3cb(int value,int min_val,int max_val);;

/* Function at 0045f3f1 (Size: 38 bytes) */
void Minit_Subsystem_0045f3f1(int value,int min_val,int max_val);;

/* Function at 0045f417 (Size: 38 bytes) */
void Minit_Subsystem_0045f417(int value,int min_val,int max_val);;

/* Function at 0045f43d (Size: 38 bytes) */
void Minit_Subsystem_0045f43d(int value,int min_val,int max_val);;

/* Function at 0045f463 (Size: 38 bytes) */
void Minit_Subsystem_0045f463(int value,int min_val,int max_val);;

/* Function at 0045f489 (Size: 38 bytes) */
void Minit_Subsystem_0045f489(int value,int min_val,int max_val);;

/* Function at 0045f4af (Size: 467 bytes) */
int32_t Minit_Subsystem_0045f4af(int x,int y,int width,int height);;

/* Function at 0045f682 (Size: 425 bytes) */
int32_t Minit_Subsystem_0045f682(int value,int min_val,int max_val);;

/* Function at 0045f82b (Size: 1408 bytes) */
int Minit_Subsystem_0045f82b(int value,int min_val,int max_val);;

/* Function at 0045fdb5 (Size: 711 bytes) */
int32_t Minit_Subsystem_0045fdb5(int value,int min_val,int max_val);;

/* Function at 0046007c (Size: 825 bytes) */
int32_t Minit_Subsystem_0046007c(int value,int min_val,int max_val);;

/* Function at 004603b5 (Size: 301 bytes) */
int32_t Minit_Subsystem_004603b5(int value,int min_val,int max_val);;

/* Function at 004604e2 (Size: 258 bytes) */
int32_t Minit_Subsystem_004604e2(int value,int min_val,int max_val);;

/* Function at 004605e4 (Size: 1086 bytes) */
int32_t CardScript_EbonyHorse(int spell_id,int target_id,int flags);;

/* Function at 00460a22 (Size: 472 bytes) */
int32_t Minit_Subsystem_00460a22(int value,int min_val,int max_val);;

/* Function at 00460bfa (Size: 1095 bytes) */
int32_t Minit_Subsystem_00460bfa(int value,int min_val,int max_val);;

/* Function at 00461041 (Size: 435 bytes) */
int32_t Minit_Subsystem_00461041(int value,int min_val,int max_val);;

/* Function at 004611f4 (Size: 412 bytes) */
int32_t Minit_Subsystem_004611f4(int value,int min_val,int max_val);;

/* Function at 00461390 (Size: 1053 bytes) */
int32_t Minit_Subsystem_00461390(int value,int min_val,int max_val);;

/* Function at 004617ad (Size: 1012 bytes) */
int32_t CardScript_JandorsSaddlebags(int spell_id,int target_id,int flags);;

/* Function at 00461ba1 (Size: 920 bytes) */
int32_t CardScript_JadeMonolith(int spell_id,int target_id,int flags);;

/* Function at 00461f3e (Size: 389 bytes) */
void Minit_Subsystem_00461f3e(int value,int min_val,int max_val);;

/* Function at 004620c3 (Size: 460 bytes) */
int32_t Minit_Subsystem_004620c3(int value,int min_val,int max_val);;

/* Function at 0046228f (Size: 74 bytes) */
int32_t Minit_Subsystem_0046228f(int value,int min_val,int max_val);;

/* Function at 004622d9 (Size: 1012 bytes) */
int32_t CardScript_AmuletOfKroog(int spell_id,int target_id,int flags);;

/* Function at 004626d2 (Size: 824 bytes) */
int32_t Minit_Subsystem_004626d2(int value,int min_val,int max_val);;

/* Function at 00462a0a (Size: 788 bytes) */
int32_t CardScript_GrapeshotCatapult(int spell_id,int target_id,int flags);;

/* Function at 00462d1e (Size: 608 bytes) */
int32_t Minit_Subsystem_00462d1e(int value,int min_val,int max_val);;

/* Function at 00462f7e (Size: 1952 bytes) */
int32_t CardScript_BronzeTablet(int spell_id,int target_id,int flags);;

/* Function at 00463723 (Size: 1261 bytes) */
int32_t Minit_Subsystem_00463723(int value,int min_val,int max_val);;

/* Function at 00463c10 (Size: 193 bytes) */
int32_t Minit_Subsystem_00463c10(int value,int min_val,int max_val);;

/* Function at 00463cd1 (Size: 543 bytes) */
int32_t CardScript_AladdinsRing(int spell_id,int target_id,int flags);;

/* Function at 00463ef0 (Size: 538 bytes) */
int32_t CardScript_RodOfRuin(int spell_id,int target_id,int flags);;

/* Function at 0046410a (Size: 1157 bytes) */
int32_t Minit_Subsystem_0046410a(int value,int min_val,int max_val);;

/* Function at 0046458f (Size: 404 bytes) */
int32_t Minit_Subsystem_0046458f(int value,int min_val,int max_val);;

/* Function at 00464723 (Size: 1029 bytes) */
int Minit_Subsystem_00464723(int value,int min_val,int max_val);;

/* Function at 00464b28 (Size: 38 bytes) */
void Minit_Subsystem_00464b28(int value,int min_val,int max_val);;

/* Function at 00464b4e (Size: 38 bytes) */
void Minit_Subsystem_00464b4e(int value,int min_val,int max_val);;

/* Function at 00464b74 (Size: 1108 bytes) */
int32_t Minit_Subsystem_00464b74(int x,int y,int width,int height);;

/* Function at 00464fcd (Size: 408 bytes) */
int32_t Minit_Subsystem_00464fcd(int value,int min_val,int max_val);;

/* Function at 00465165 (Size: 1181 bytes) */
int32_t CardScript_FlyingCarpet(int spell_id,int target_id,int flags);;

/* Function at 00465602 (Size: 983 bytes) */
int32_t Minit_Subsystem_00465602(int value,int min_val,int max_val);;

/* Function at 004659d9 (Size: 64 bytes) */
void Minit_Subsystem_004659d9(int value,int min_val,uint32_t max_val);;

/* Function at 00465a19 (Size: 92 bytes) */
uint32_t Minit_Subsystem_00465a19(int player,int card_slot);;

/* Function at 00465a75 (Size: 1063 bytes) */
int32_t CardScript_HelmOfChatzuk(int spell_id,int target_id,int flags);;

/* Function at 00465e9c (Size: 1094 bytes) */
int32_t CardScript_CoralHelm(int spell_id,int target_id,int flags);;

/* Function at 004662e2 (Size: 607 bytes) */
int32_t Minit_Subsystem_004662e2(int value,int min_val,int max_val);;

/* Function at 00466541 (Size: 1053 bytes) */
int32_t CardScript_TawnosWand(int spell_id,int target_id,int flags);;

/* Function at 0046695e (Size: 349 bytes) */
int32_t Card_Setup_0046695e(int value,int min_val,int max_val);;

/* Function at 00466abb (Size: 617 bytes) */
int32_t Minit_Subsystem_00466abb(int value,int min_val,int max_val);;

/* Function at 00466d29 (Size: 563 bytes) */
int32_t CardScript_BottleOfSuleiman(int value,int min_val,int max_val);;

/* Function at 00466f5c (Size: 320 bytes) */
int32_t Minit_Subsystem_00466f5c(int value,int min_val,int max_val);;

/* Function at 0046709c (Size: 718 bytes) */
int32_t Player_Init_0046709c(int spell_id,int target_id,int flags);;

/* Function at 0046736a (Size: 258 bytes) */
int32_t Minit_Subsystem_0046736a(int value,int min_val,int max_val);;

/* Function at 0046746c (Size: 288 bytes) */
int32_t Minit_Subsystem_0046746c(int value,int min_val,int max_val);;

/* Function at 0046758c (Size: 546 bytes) */
int32_t Minit_Subsystem_0046758c(void);;

/* Function at 004677ae (Size: 203 bytes) */
int32_t Minit_Subsystem_004677ae(int value,int min_val,int max_val);;

/* Function at 00467880 (Size: 287 bytes) */
bool UI_RegisterClass_00467880(LPCSTR str_1);;

/* Function at 0046799f (Size: 201 bytes) */
void Minit_Subsystem_0046799f(void);;

/* Function at 00467a68 (Size: 12124 bytes) */
LRESULT Card_Setup_00467a68(HWND hwnd,uint32_t uMsg,LONG *wParam,int *lParam);;

/* Function at 0046aa75 (Size: 176 bytes) */
void FUN_0046aa75(HWND hwnd);;

/* Function at 0046ab25 (Size: 549 bytes) */
int32_t FUN_0046ab25(HWND hwnd);;

/* Function at 0046ad4a (Size: 114 bytes) */
int FUN_0046ad4a(HWND hwnd);;

/* Function at 0046adbc (Size: 654 bytes) */
bool FUN_0046adbc(int player,int card_slot);;

/* Function at 0046b04a (Size: 924 bytes) */
uint32_t FUN_0046b04a(int player,int card_slot);;

/* Function at 0046b3e6 (Size: 54 bytes) */
bool FUN_0046b3e6(int player,int card_slot);;

/* Function at 0046b41c (Size: 159 bytes) */
bool FUN_0046b41c(int player,int card_slot);;

/* Function at 0046b4bb (Size: 32 bytes) */
void Mem_AllocOrFree_0046b4bb(int player,int card_slot);;

/* Function at 0046b4db (Size: 940 bytes) */
void UI_FormatCardCounterString(char *str_1,int min_val,int32_t max_val);;

/* Function at 0046b887 (Size: 164 bytes) */
void FUN_0046b887(char *str_1,int min_val,int max_val);;

/* Function at 0046b92b (Size: 19 bytes) */
void Mem_AllocOrFree_0046b92b(void);;

/* Function at 0046ba19 (Size: 272 bytes) */
void FUN_0046ba19(HDC hdc,int y,int32_t max_val,int32_t flags);;

/* Function at 0046bb29 (Size: 125 bytes) */
int32_t FUN_0046bb29(HWND hwnd,int *card_slot);;

/* Function at 0046bbab (Size: 127 bytes) */
int32_t FUN_0046bbab(HWND hwnd,int card_slot);;

/* Function at 0046bc2f (Size: 99 bytes) */
int32_t FUN_0046bc2f(HWND hwnd);;

/* Function at 0046bc92 (Size: 41 bytes) */
LONG FUN_0046bc92(HWND hwnd);;

/* Function at 0046bcc0 (Size: 620 bytes) */
int Catalog_LoadWaveletArt(WPARAM value,int min_val,int width,int height);;

/* Function at 0046bf31 (Size: 130 bytes) */
int32_t FUN_0046bf31(int player,int card_slot);;

/* Function at 0046bfc2 (Size: 221 bytes) */
int FUN_0046bfc2(HDC hdc,RECT *min_val,int width,int flags);;

/* Function at 0046c09f (Size: 271 bytes) */
int32_t FUN_0046c09f(WPARAM value,int min_val,int width,int height);;

/* Function at 0046c1b3 (Size: 80 bytes) */
void FUN_0046c1b3(int value);;

/* Function at 0046c203 (Size: 685 bytes) */
int Catalog_LoadWaveletArtAlt(WPARAM value,int y,int width,int height);;

/* Function at 0046c4b5 (Size: 150 bytes) */
uint8_t * FUN_0046c4b5(int player,int card_slot);;

/* Function at 0046c54b (Size: 235 bytes) */
int FUN_0046c54b(HDC hdc,RECT *min_val,int width,int height);;

/* Function at 0046c636 (Size: 165 bytes) */
int32_t FUN_0046c636(WPARAM value,int y,int width,int height);;

/* Function at 0046c6e5 (Size: 372 bytes) */
void FUN_0046c6e5(int player,int card_slot);;

/* Function at 0046c859 (Size: 78 bytes) */
void FUN_0046c859(void);;

/* Function at 0046c8b0 (Size: 2686 bytes) */
void Castle_Process_0046c8b0(void);;

/* Function at 0046d333 (Size: 4866 bytes) */
void Sprite_Load_BK_AMG_0046d333(int32_t value,int min_val,int max_val);;

/* Function at 0046e70d (Size: 109 bytes) */
void FUN_0046e70d(int player,int card_slot);;

/* Function at 0046e77a (Size: 424 bytes) */
void FUN_0046e77a(char *player,int card_slot);;

/* Function at 0046e922 (Size: 62 bytes) */
int Deck_PickRandomSecondaryColor(uint32_t existing_color_mask);
#define FUN_0046e922 Deck_PickRandomSecondaryColor

/* Function at 0046e960 (Size: 941 bytes) */
void Deck_GenerateStartingResources(void);
#define FUN_0046e960 Deck_GenerateStartingResources

/* Function at 0046ed22 (Size: 1104 bytes) */
int32_t Deck_PopulateCategoryCards(uint32_t color_mask, int num_lands, int num_spells, int num_creatures, int guaranteed_rare_count, int allow_colorless_artifacts);
#define FUN_0046ed22 Deck_PopulateCategoryCards

/* Function at 0046f172 (Size: 167 bytes) */
uint8_t * Sprite_SelectResolutionFolder(char *str_1);;

/* Function at 0046f21e (Size: 211 bytes) */
void FUN_0046f21e(char *value,int32_t min_val,int32_t max_val);;

/* Function at 0046f300 (Size: 721 bytes) */
void FUN_0046f300(void);;

/* Function at 0046f5d1 (Size: 1130 bytes) */
int Magic_ExecuteDrawPhase(int value);;

/* Function at 0046fa40 (Size: 1094 bytes) */
void Prompts_Load_0046fa40(int spell_id,int target_id,int flags);;

/* Function at 0046fe86 (Size: 202 bytes) */
int32_t FUN_0046fe86(int player,int card_slot);;

/* Function at 0046ff50 (Size: 2993 bytes) */
int32_t Magic_ExecuteCastSpellPhase(int value,int min_val,int max_val);;

/* Function at 00470b36 (Size: 877 bytes) */
int32_t Magic_ResolveCastSpell(int player,int card_slot);;

/* Function at 00470ea3 (Size: 408 bytes) */
bool FUN_00470ea3(int value,int min_val,int max_val);;

/* Function at 0047103b (Size: 2358 bytes) */
bool Magic_ExecuteUpkeepPhase(int player,int card_slot);;

/* Function at 00471971 (Size: 329 bytes) */
int32_t Magic_ExecuteTapCardAction(int player,int card_slot);;

/* Function at 00471aba (Size: 262 bytes) */
int32_t Magic_ExecuteProcessTriggers(int value,int min_val,int max_val);;

/* Function at 00471bc0 (Size: 114 bytes) */
bool FUN_00471bc0(int player,int card_slot);;

/* Function at 00471c32 (Size: 114 bytes) */
bool Card_IsTapped(int player,int card_slot);;

/* Function at 00471ca4 (Size: 114 bytes) */
int32_t FUN_00471ca4(int player,int card_slot);;

/* Function at 00471d16 (Size: 722 bytes) */
void Magic_ExecuteDeclareBlockersPhase(uint32_t value);;

/* Function at 00472616 (Size: 175 bytes) */
int32_t FUN_00472616(int value);;

/* Function at 004726c5 (Size: 510 bytes) */
int32_t FUN_004726c5(int player,int card_slot);;

/* Function at 004728c3 (Size: 66 bytes) */
bool Rules_ValidateCardTargetSlot(int player,int card_slot);;

/* Function at 00472905 (Size: 261 bytes) */
int32_t FUN_00472905(int value);;

/* Function at 00472a0a (Size: 391 bytes) */
int32_t FUN_00472a0a(int value);;

/* Function at 00472b91 (Size: 123 bytes) */
int32_t FUN_00472b91(int x,int min_val,int max_val,int flags);;

/* Function at 00472c0c (Size: 508 bytes) */
bool FUN_00472c0c(int value,int min_val,int32_t max_val,int32_t flags,uint32_t flags,uint32_t arg_6);;

/* Function at 00472e08 (Size: 260 bytes) */
int FUN_00472e08(int x,int y,int32_t max_val,int32_t flags);;

/* Function at 00472f0c (Size: 162 bytes) */
void FUN_00472f0c(int32_t player,int card_slot);;

/* Function at 00472fae (Size: 459 bytes) */
void Rules_ProcessCombatDamageStep(void);;

/* Function at 00473179 (Size: 2823 bytes) */
uint32_t Magic_QueryCardValue(int player,int slot,int event_code,int32_t target_slot);;

/* Function at 00473cc5 (Size: 121 bytes) */
int32_t Rules_CalculateManaCostReduction(uint8_t value);;

/* Function at 00473d7e (Size: 26 bytes) */
uint8_t * Mem_AllocOrFree_00473d7e(int value);;

/* Function at 00473d98 (Size: 209 bytes) */
int FUN_00473d98(int value);;

/* Function at 00473e69 (Size: 157 bytes) */
int32_t Magic_BroadcastCardEvent(int player,int32_t slot,int event_code);;

/* Function at 00473f06 (Size: 864 bytes) */
void Magic_ScanCards(int value);;

/* Function at 00474266 (Size: 291 bytes) */
int Magic_TriggerCardEvent(int player,int slot,int event_code,int32_t target_player,int32_t target_slot);;

/* Function at 00474389 (Size: 159 bytes) */
bool Magic_ResolveSpellStack(int player,int card_slot);;

/* Function at 00474428 (Size: 182 bytes) */
void Magic_PushEventContext(void);;

/* Function at 004744de (Size: 170 bytes) */
void Magic_PopEventContext(void);;

/* Function at 00474588 (Size: 945 bytes) */
void Magic_UntapTurnPhase(void);;

/* Function at 00474939 (Size: 50 bytes) */
void Magic_CheckTurnTriggers(int player,int card_slot);;

/* Function at 0047496b (Size: 788 bytes) */
int32_t Duel_PlaySoundById(int value);;

/* Function at 00474c7f (Size: 143 bytes) */
void Duel_PreloadSoundEffects(void);;

/* Function at 00474d0e (Size: 16 bytes) */
void FUN_00474d0e(void);;

/* Function at 00474d1e (Size: 44 bytes) */
int32_t Mem_AllocOrFree_00474d1e(void);;

/* Function at 00474d4a (Size: 51 bytes) */
int32_t FUN_00474d4a(void);;

/* Function at 00474d7d (Size: 1114 bytes) */
int32_t Magic_MainTurnPhase(int32_t value);;

/* Function at 004751d7 (Size: 1062 bytes) */
int32_t Magic_CombatPhase(int value,int min_val,int max_val,int flags,int32_t flags);;

/* Function at 004755fd (Size: 164 bytes) */
int32_t FUN_004755fd(void);;

/* Function at 004756a1 (Size: 1295 bytes) */
int32_t Magic_EndTurnPhase(void);;

/* Function at 00475bb0 (Size: 177 bytes) */
int32_t Magic_DiscardToHandSize(void);;

/* Function at 00475c61 (Size: 41 bytes) */
void Mem_AllocOrFree_00475c61(void);;

/* Function at 00475c8a (Size: 218 bytes) */
int32_t FUN_00475c8a(int x,int min_val,char *max_val,int32_t flags);;

/* Function at 00475d64 (Size: 1185 bytes) */
int Magic_CleanupPhase(int x,int y,char *str_3,int32_t flags);;

/* Function at 00476205 (Size: 74 bytes) */
int32_t FUN_00476205(int x,int32_t min_val,char *max_val,int flags);;

/* Function at 0047624f (Size: 495 bytes) */
int32_t Magic_RunTurnStep(int player,int32_t step_code,char *step_name,int repeat_while_active);;

/* Function at 0047643e (Size: 68 bytes) */
int32_t FUN_0047643e(void);;

/* Function at 00476482 (Size: 142 bytes) */
int FUN_00476482(int player,int card_slot);;

/* Function at 00476510 (Size: 357 bytes) */
void FUN_00476510(void);;

/* Function at 00476675 (Size: 377 bytes) */
int32_t FUN_00476675(int player,int card_slot);;

/* Function at 004767ee (Size: 470 bytes) */
void FUN_004767ee(int value);;

/* Function at 004769c4 (Size: 183 bytes) */
int32_t FUN_004769c4(int player,int card_slot);;

/* Function at 00476a80 (Size: 142 bytes) */
void FUN_00476a80(void);;

/* Function at 00476b0e (Size: 361 bytes) */
void FUN_00476b0e(void);;

/* Function at 00476c77 (Size: 475 bytes) */
uint32_t FUN_00476c77(int x,int y,int width,int height);;

/* Function at 00476e60 (Size: 604 bytes) */
int32_t Prompts_Load_00476e60(LPCSTR filepath);;

/* Function at 004770bc (Size: 318 bytes) */
void FUN_004770bc(void);;

/* Function at 004771fa (Size: 2920 bytes) */
uint32_t UI_Register_WINBK_TellUser_004771fa(HWND hwnd,uint32_t y,LPSTR str_3,int height);;

/* Function at 00477d73 (Size: 1008 bytes) */
void FUN_00477d73(HWND hwnd,char *str_2,uint32_t max_val);;

/* Function at 00478163 (Size: 172 bytes) */
void FUN_00478163(HWND hwnd);;

/* Function at 0047820f (Size: 347 bytes) */
void FUN_0047820f(HWND hwnd,HDC hdc,int *max_val);;

/* Function at 00478370 (Size: 743 bytes) */
int FUN_00478370(WPARAM value,int y,int width,int height);;

/* Function at 0047865c (Size: 151 bytes) */
uint8_t * FUN_0047865c(int player,int card_slot);;

/* Function at 004786f3 (Size: 112 bytes) */
int FUN_004786f3(int x,int y,int width,int height);;

/* Function at 00478763 (Size: 236 bytes) */
int FUN_00478763(HDC hdc,RECT *min_val,int width,int height);;

/* Function at 0047884f (Size: 135 bytes) */
int32_t FUN_0047884f(WPARAM value,int y,int width,int height);;

/* Function at 004788e0 (Size: 374 bytes) */
void FUN_004788e0(int player,int card_slot);;

/* Function at 00478a56 (Size: 78 bytes) */
void FUN_00478a56(void);;

/* Function at 00478aa4 (Size: 113 bytes) */
int FUN_00478aa4(int value,int min_val,int max_val);;

/* Function at 00478b20 (Size: 181 bytes) */
uint8_t UI_RegisterClass_00478b20(LPCSTR str_1);;

/* Function at 00478bd5 (Size: 51 bytes) */
void FUN_00478bd5(void);;

/* Function at 00478c08 (Size: 4271 bytes) */
uint32_t UI_WndProc_00478c08(HWND hwnd,uint32_t uMsg,uint32_t *wParam,LONG *lParam);;

/* Function at 00479d16 (Size: 150 bytes) */
int FUN_00479d16(HWND hwnd,int card_slot);;

/* Function at 00479dac (Size: 147 bytes) */
int FUN_00479dac(HWND hwnd,int card_slot);;

/* Function at 00479e3f (Size: 362 bytes) */
void FUN_00479e3f(HWND hwnd,LPRECT card_slot);;

/* Function at 00479fb0 (Size: 44 bytes) */
int32_t Mem_AllocOrFree_00479fb0(int player,int card_slot);;

/* Function at 00479fdc (Size: 29 bytes) */
int32_t Mem_AllocOrFree_00479fdc(int value);;

/* Function at 00479ff9 (Size: 707 bytes) */
int32_t FUN_00479ff9(int player,int card_slot);;

/* Function at 0047a2e6 (Size: 1633 bytes) */
int Sprite_Load_begin_0047a2e6(void);;

/* Function at 0047a94c (Size: 254 bytes) */
int32_t FUN_0047a94c(int player,int card_slot);;

/* Function at 0047aa4a (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0047aa4a(int value);;

/* Function at 0047aa7c (Size: 368 bytes) */
int32_t FUN_0047aa7c(int player,int card_slot);;

/* Function at 0047abf1 (Size: 945 bytes) */
int Pic_Load_menu2_hi_0047abf1(void);;

/* Function at 0047afa2 (Size: 245 bytes) */
int32_t FUN_0047afa2(int player,int card_slot);;

/* Function at 0047b097 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0047b097(int value);;

/* Function at 0047b0c9 (Size: 314 bytes) */
int32_t FUN_0047b0c9(int player,int card_slot);;

/* Function at 0047b208 (Size: 1033 bytes) */
int32_t Pic_Load_menu3_but1_0047b208(void);;

/* Function at 0047b616 (Size: 245 bytes) */
int32_t FUN_0047b616(int player,int card_slot);;

/* Function at 0047b70b (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0047b70b(int value);;

/* Function at 0047b73d (Size: 343 bytes) */
int32_t FUN_0047b73d(int player,int card_slot);;

/* Function at 0047b899 (Size: 1112 bytes) */
int Sprite_Load__16faces_0047b899(void);;

/* Function at 0047bcf1 (Size: 371 bytes) */
void FUN_0047bcf1(int32_t *value,int min_val,int max_val,int flags,int flags,int32_t *arg_6,int arg_7,int arg_8);;

/* Function at 0047be64 (Size: 540 bytes) */
void Pic_Load_namepick_0047be64(char *filepath);;

/* Function at 0047c080 (Size: 245 bytes) */
int32_t FUN_0047c080(int player,int card_slot);;

/* Function at 0047c175 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0047c175(int value);;

/* Function at 0047c1a7 (Size: 87 bytes) */
void Sprite_Load__16faces_0047c1a7(int value);;

/* Function at 0047c1fe (Size: 255 bytes) */
int32_t Pic_Load_advfac64_0047c1fe(int32_t *value,int y,int width,int height);;

/* Function at 0047c2fd (Size: 99 bytes) */
int32_t FUN_0047c2fd(int value);;

/* Function at 0047c360 (Size: 716 bytes) */
int32_t FUN_0047c360(char *str_1,uint32_t min_val,uint32_t max_val);;

/* Function at 0047c640 (Size: 244 bytes) */
int32_t UI_Register_sPoison_0047c640(LPCSTR str_1);;

/* Function at 0047c734 (Size: 118 bytes) */
void FUN_0047c734(void);;

/* Function at 0047c7aa (Size: 3059 bytes) */
LRESULT UI_LifePointsDisplayWndProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam);;

/* Function at 0047d3cf (Size: 63 bytes) */
void FUN_0047d3cf(int32_t value);;

/* Function at 0047d40e (Size: 74 bytes) */
int32_t FUN_0047d40e(int value);;

/* Function at 0047d460 (Size: 1020 bytes) */
int32_t UI_Register_WINBK_Attack_0047d460(LPCSTR str_1);;

/* Function at 0047d85c (Size: 548 bytes) */
void FUN_0047d85c(void);;

/* Function at 0047da80 (Size: 14661 bytes) */
uint32_t UI_Register_MAGICGAME_CardClass_0047da80(HWND hwnd,uint32_t y,HWND param_3,HWND param_4);;

/* Function at 00481491 (Size: 245 bytes) */
int32_t FUN_00481491(int value,int min_val,int max_val);;

/* Function at 00481586 (Size: 2708 bytes) */
void UI_LayoutAttackCards(HWND hwnd);;

/* Function at 0048201a (Size: 578 bytes) */
void FUN_0048201a(HWND hwnd,LPRECT card_slot);;

/* Function at 0048225c (Size: 91 bytes) */
bool FUN_0048225c(int player,int card_slot);;

/* Function at 004822b7 (Size: 2732 bytes) */
uint32_t UI_LoadAttackSwordShieldPics(HWND hwnd,uint32_t uMsg,uint32_t wParam,int lParam);;

/* Function at 00482d6f (Size: 103 bytes) */
void FUN_00482d6f(HWND hwnd);;

/* Function at 00482dd6 (Size: 855 bytes) */
LRESULT UI_MinimizedAttackWindowWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,uint32_t lParam);;

/* Function at 00483139 (Size: 688 bytes) */
int FUN_00483139(HWND hwnd,int *min_val,int32_t *max_val,int32_t *flags,int32_t *flags);;

/* Function at 004833e9 (Size: 417 bytes) */
int FUN_004833e9(HWND hwnd,int card_slot);;

/* Function at 00483590 (Size: 204 bytes) */
void FUN_00483590(char *str_1,int min_val,int max_val);;

/* Function at 0048365c (Size: 64 bytes) */
int32_t FUN_0048365c(void);;

/* Function at 0048369c (Size: 3951 bytes) */
void Pic_Load_combat2_0048369c(int player,int card_slot);;

/* Function at 00484668 (Size: 41 bytes) */
void FUN_00484668(char *str_1);;

/* Function at 00484691 (Size: 167 bytes) */
void FUN_00484691(uint8_t player,int card_slot);;

/* Function at 00484738 (Size: 386 bytes) */
void Sprite_Load_dungbutt_00484738(int value,int32_t min_val,char *str_3);;

/* Function at 00484c45 (Size: 263 bytes) */
void FUN_00484c45(int32_t value);;

/* Function at 00484df9 (Size: 52 bytes) */
void FUN_00484df9(int32_t player,int32_t card_slot);;

/* Function at 00484e2d (Size: 142 bytes) */
void FUN_00484e2d(int value,int32_t min_val,int32_t max_val,int flags,int32_t flags);;

/* Function at 00484ebb (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00484ebb(void);;

/* Function at 00484ecd (Size: 292 bytes) */
int FUN_00484ecd(int x,int y,int width,int32_t flags);;

/* Function at 00485005 (Size: 57 bytes) */
bool FUN_00485005(int value);;

/* Function at 00485040 (Size: 64 bytes) */
int32_t FUN_00485040(int32_t player,int32_t card_slot);;

/* Function at 00485229 (Size: 11 bytes) */
void Mem_AllocOrFree_00485229(void);;

/* Function at 00485234 (Size: 398 bytes) */
void FUN_00485234(int value);;

/* Function at 004853c2 (Size: 226 bytes) */
void UI_AnteCardDisplayWndProc(void);;

/* Function at 004854a4 (Size: 353 bytes) */
int FUN_004854a4(int value,char *str_2,int max_val);;

/* Function at 00485605 (Size: 168 bytes) */
int FUN_00485605(int value,char *str_2,int max_val);;

/* Function at 004856b0 (Size: 14542 bytes) */
int Dungeon_Process_004856b0(uint32_t player,int card_slot);;

/* Function at 00488f92 (Size: 73 bytes) */
int32_t FUN_00488f92(int value);;

/* Function at 00488fdb (Size: 429 bytes) */
void FUN_00488fdb(int32_t *value,int min_val,int max_val,int flags,int flags,char *str_6,char *str_7);;

/* Function at 00489188 (Size: 1192 bytes) */
void Pic_Load_advfac64_00489188(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 00489630 (Size: 88 bytes) */
void FUN_00489630(uint32_t value);;

/* Function at 00489690 (Size: 46 bytes) */
void Mem_AllocOrFree_00489690(int32_t value,int32_t min_val,int32_t max_val);;

/* Function at 004896be (Size: 82 bytes) */
void FUN_004896be(int32_t value,int min_val,uint32_t max_val);;

/* Function at 00489710 (Size: 56 bytes) */
void FUN_00489710(int32_t value,int32_t min_val,int32_t max_val);;

/* Function at 00489748 (Size: 1359 bytes) */
int FUN_00489748(char *player,int card_slot);;

/* Function at 00489c9c (Size: 1310 bytes) */
int FUN_00489c9c(char *str_1,int card_slot);;

/* Function at 0048a1ba (Size: 116 bytes) */
void FUN_0048a1ba(int32_t value,int y,int32_t max_val,int32_t flags);;

/* Function at 0048a2a5 (Size: 147 bytes) */
void FUN_0048a2a5(int value,int min_val,int max_val,int flags,int32_t flags);;

/* Function at 0048a338 (Size: 148 bytes) */
void FUN_0048a338(int value,int min_val,int max_val,int flags,int32_t flags,int32_t arg_6);;

/* Function at 0048a3cc (Size: 803 bytes) */
void FUN_0048a3cc(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 0048a6ef (Size: 1344 bytes) */
void FUN_0048a6ef(int value,int min_val,int max_val,int flags,int32_t *flags);;

/* Function at 0048ac2f (Size: 684 bytes) */
uint32_t FUN_0048ac2f(void);;

/* Function at 0048aee0 (Size: 59 bytes) */
void FUN_0048aee0(undefined8 *player,uint32_t card_slot);;

/* Function at 0048b950 (Size: 579 bytes) */
int FUN_0048b950(uint32_t *value,int32_t min_val,int32_t max_val);;

/* Function at 0048bba0 (Size: 487 bytes) */
int32_t FUN_0048bba0(int value);;

/* Function at 0048bda1 (Size: 208 bytes) */
int32_t __thiscall FUN_0048bda1(void *this);;

/* Function at 0048be80 (Size: 488 bytes) */
int FUN_0048be80(int32_t *value,uint32_t *min_val,int max_val);;

/* Function at 0048c070 (Size: 1619 bytes) */
int FUN_0048c070(int *value,uint32_t *min_val,int max_val);;

/* Function at 0048c6d0 (Size: 80 bytes) */
int FUN_0048c6d0(int value);;

/* Function at 0048c72a (Size: 387 bytes) */
int SaveGame_LoadCampaignFile(int value);;

/* Function at 0048c8b2 (Size: 180 bytes) */
uint32_t FUN_0048c8b2(char *str_1,int card_slot);;

/* Function at 0048c970 (Size: 319 bytes) */
void SaveGame_SaveCampaignFile(int value);;

/* Function at 0048caaf (Size: 69 bytes) */
int32_t FUN_0048caaf(char *value);;

/* Function at 0048caf4 (Size: 71 bytes) */
bool FUN_0048caf4(int value,void *min_val,uint32_t max_val);;

/* Function at 0048cb40 (Size: 84 bytes) */
int FUN_0048cb40(void);;

/* Function at 0048cdf5 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0048cdf5(void);;

/* Function at 0048ce07 (Size: 640 bytes) */
int32_t FUN_0048ce07(char *str_1);;

/* Function at 0048d087 (Size: 466 bytes) */
int32_t Overworld_SaveMapFile(char *str_1);;

/* Function at 0048d259 (Size: 3524 bytes) */
uint32_t FUN_0048d259(void);;

/* Function at 0048e01d (Size: 132 bytes) */
uint32_t FileIo_ReadStream(void *player, uint32_t card_slot);;

/* Function at 0048e0a1 (Size: 77 bytes) */
int FUN_0048e0a1(char *str_1);;

/* Function at 0048e0ee (Size: 26 bytes) */
void Mem_AllocOrFree_0048e0ee(void);;

/* Function at 0048e108 (Size: 26 bytes) */
void Mem_AllocOrFree_0048e108(void);;

/* Function at 0048e122 (Size: 157 bytes) */
void FUN_0048e122(char *str_1);;

/* Function at 0048e1bf (Size: 239 bytes) */
uint32_t FUN_0048e1bf(char *str_1);;

/* Function at 0048e2b0 (Size: 86 bytes) */
void FUN_0048e2b0(int value);;

/* Function at 0048e306 (Size: 1882 bytes) */
void FUN_0048e306(void);;

/* Function at 0048ea81 (Size: 91 bytes) */
void FUN_0048ea81(int value);;

/* Function at 0048eadc (Size: 396 bytes) */
int32_t FUN_0048eadc(int player,int card_slot);;

/* Function at 0048ec68 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0048ec68(int value);;

/* Function at 0048ec9a (Size: 106 bytes) */
int FUN_0048ec9a(int player,int card_slot);;

/* Function at 0048ed04 (Size: 231 bytes) */
void FUN_0048ed04(int value,uint32_t *min_val,int *max_val);;

/* Function at 0048edeb (Size: 82 bytes) */
int32_t FUN_0048edeb(int value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0048ee42 (Size: 389 bytes) */
int32_t FUN_0048ee42(void);;

/* Function at 0048efc7 (Size: 231 bytes) */
int32_t FUN_0048efc7(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0048f0ae (Size: 374 bytes) */
int FUN_0048f0ae(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0048f224 (Size: 287 bytes) */
int32_t FUN_0048f224(int player,int card_slot);;

/* Function at 0048f343 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_0048f343(int value);;

/* Function at 0048f375 (Size: 430 bytes) */
int32_t FUN_0048f375(int *value,int min_val,int max_val);;

/* Function at 0048f523 (Size: 5156 bytes) */
void Castle_Process_0048f523(void);;

/* Function at 0049094c (Size: 84 bytes) */
int FUN_0049094c(void);;

/* Function at 004909a0 (Size: 51 bytes) */
void FUN_004909a0(int value);;

/* Function at 004909d3 (Size: 271 bytes) */
void Deck_LoadPreconstructedDeck(int x,int32_t min_val,uint32_t width,int height);;

/* Function at 00490ae2 (Size: 287 bytes) */
int32_t FUN_00490ae2(int player,int card_slot);;

/* Function at 00490c01 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_00490c01(int value);;

/* Function at 00490c33 (Size: 278 bytes) */
int32_t FUN_00490c33(int player,int card_slot);;

/* Function at 00490d49 (Size: 50 bytes) */
int32_t Sound_LoadWav_x_sound_button2_00490d49(int value);;

/* Function at 00490d7b (Size: 4071 bytes) */
void Town_Process_00490d7b(void);;

/* Function at 00491d8f (Size: 1320 bytes) */
int32_t Castle_Process_00491d8f(int32_t value,int y,int width,int height);;

/* Function at 004922dc (Size: 194 bytes) */
int FUN_004922dc(void);;

/* Function at 0049239e (Size: 2323 bytes) */
void Action_PromptTarget_0049239e(int spell_id);;

/* Function at 00492cb1 (Size: 302 bytes) */
int FUN_00492cb1(int player,int card_slot);;

/* Function at 00492ddf (Size: 2808 bytes) */
void Castle_Process_00492ddf(int value);;

/* Function at 004938e0 (Size: 588 bytes) */
int Catalog_Open(char *str_1);;

/* Function at 00493b2c (Size: 190 bytes) */
bool Catalog_Close(int value);;

/* Function at 00493bea (Size: 70 bytes) */
int32_t Catalog_CompareEntryHash(int *player,int *card_slot);;

/* Function at 00493c3a (Size: 124 bytes) */
void * Catalog_FindEntry(int player,uint8_t *card_slot);;

/* Function at 00493cb6 (Size: 172 bytes) */
size_t Catalog_ReadFile(int value,int32_t min_val,int *max_val);;

/* Function at 00493d62 (Size: 235 bytes) */
uint32_t Catalog_ComputeFilenameHash(uint8_t *value);;

/* Function at 00493e50 (Size: 29 bytes) */
int32_t * ColorOctree_AllocNode(void);;

/* Function at 00493e70 (Size: 519 bytes) */
uint8_t * Catalog_LoadPaletteMap(char *str_1,char *str_2);;

/* Function at 00494080 (Size: 58 bytes) */
int32_t Palette_InitSquareDistanceTable(void);;

/* Function at 004940c0 (Size: 85 bytes) */
void ColorOctree_CollectLeaves(int *value,int min_val,int *max_val);;

/* Function at 00494120 (Size: 224 bytes) */
int ColorOctree_BuildClusters(int *value);;

/* Function at 00494200 (Size: 153 bytes) */
int32_t ColorOctree_InsertColor(int32_t *value,char *str_2,int32_t max_val);;

/* Function at 004942a0 (Size: 106 bytes) */
int ColorOctree_FreeTree(int *value);;

/* Function at 00494310 (Size: 105 bytes) */
void Color_QuantizeRGBToPalette(uint32_t player,uint32_t *card_slot);;

/* Function at 00494380 (Size: 98 bytes) */
int32_t Palette_BuildFastColorLookup(void);;

/* Function at 004943f0 (Size: 325 bytes) */
int32_t Color_FindNearestRGB(uint32_t value);;

/* Function at 00494540 (Size: 324 bytes) */
uint32_t Color_FindNearestPaletteIndex(uint32_t value);;

/* Function at 00494690 (Size: 81 bytes) */
int ColorOctree_Flatten(int *player,int *card_slot);;

/* Function at 004946f0 (Size: 93 bytes) */
int32_t Palette_RemapBitmapRGB(uint32_t *x,int y,int width,int height);;

/* Function at 00494820 (Size: 984 bytes) */
uint32_t * Palette_DitherBitmapRGB(uint32_t *value,int min_val,uint32_t *max_val,int flags,int flags,int arg_6);;

/* Function at 00494c00 (Size: 38 bytes) */
void Palette_RotateDitherBuffers(int32_t *player,int card_slot);;

/* Function at 00494c30 (Size: 311 bytes) */
int32_t Palette_AllocErrorDiffusionTable(int player,int card_slot);;

/* Function at 004950b0 (Size: 864 bytes) */
int32_t Palette_DitherScanline(int value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 00495410 (Size: 25 bytes) */
void Palette_Util_00495410(void);;

/* Function at 00495430 (Size: 1017 bytes) */
int32_t Palette_Color_00495430(char *str_1);;

/* Function at 00495829 (Size: 136 bytes) */
void Palette_Subsystem_00495829(void);;

/* Function at 004958b1 (Size: 167 bytes) */
int Palette_Subsystem_004958b1(int value);;

/* Function at 00495958 (Size: 902 bytes) */
int32_t Palette_Subsystem_00495958(char *str_1);;

/* Function at 00495cde (Size: 526 bytes) */
void Palette_Subsystem_00495cde(MSG *value);;

/* Function at 00495eec (Size: 408 bytes) */
int32_t Palette_Subsystem_00495eec(int *player,UINT card_slot);;

/* Function at 0049608e (Size: 418 bytes) */
int32_t Palette_Subsystem_0049608e(void);;

/* Function at 00496230 (Size: 258 bytes) */
void Palette_Subsystem_00496230(void);;

/* Function at 00496332 (Size: 37 bytes) */
int32_t Palette_Util_00496332(void);;

/* Function at 0049635c (Size: 134 bytes) */
int32_t Palette_Subsystem_0049635c(HWND value,uint32_t y,HWND max_val,int32_t flags);;

/* Function at 004963e7 (Size: 176 bytes) */
int32_t Palette_Subsystem_004963e7(void);;

/* Function at 00496497 (Size: 484 bytes) */
LRESULT Palette_Subsystem_00496497(HWND hwnd,uint32_t y,WPARAM max_val,uint32_t height);;

/* Function at 004966a0 (Size: 304 bytes) */
int32_t Palette_Subsystem_004966a0(void);;

/* Function at 00496ccf (Size: 81 bytes) */
uint32_t Palette_Subsystem_00496ccf(void);;

/* Function at 00496d20 (Size: 16 bytes) */
void Palette_Util_00496d20(void);;

/* Function at 00496d30 (Size: 383 bytes) */
int Palette_Subsystem_00496d30(HDC hdc,int *y,WPARAM *max_val,int height);;

/* Function at 00496eaf (Size: 83 bytes) */
int Palette_Subsystem_00496eaf(void);;

/* Function at 00496f10 (Size: 80 bytes) */
int32_t Palette_Subsystem_00496f10(void);;

/* Function at 00496f60 (Size: 68 bytes) */
int32_t Palette_Subsystem_00496f60(void);;

/* Function at 00496fa4 (Size: 408 bytes) */
int32_t Palette_Subsystem_00496fa4(int player,int card_slot);;

/* Function at 0049713c (Size: 50 bytes) */
int32_t Palette_Subsystem_0049713c(int value);;

/* Function at 0049716e (Size: 4152 bytes) */
uint32_t Palette_Color_0049716e(int32_t value,uint32_t min_val,uint32_t max_val,int flags,int flags);;

/* Function at 004981b5 (Size: 1904 bytes) */
void Palette_Subsystem_004981b5(int value);;

/* Function at 004989a9 (Size: 111 bytes) */
void Palette_Subsystem_004989a9(int x,int y,int width,int32_t flags);;

/* Function at 00498a18 (Size: 3133 bytes) */
bool Palette_Subsystem_00498a18(void);;

/* Function at 00499720 (Size: 152 bytes) */
bool Palette_Subsystem_00499720(LPCSTR str_1);;

/* Function at 004997b8 (Size: 46 bytes) */
void Palette_Subsystem_004997b8(void);;

/* Function at 004997e6 (Size: 4913 bytes) */
LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint32_t uMsg,int *wParam,int *lParam);;

/* Function at 0049ae00 (Size: 2805 bytes) */
int32_t Palette_Color_0049ae00(void);;

/* Function at 0049b8f5 (Size: 2066 bytes) */
void Palette_Subsystem_0049b8f5(void);;

/* Function at 0049c107 (Size: 677 bytes) */
void Palette_Subsystem_0049c107(void);;

/* Function at 0049c3ac (Size: 794 bytes) */
int32_t Palette_Subsystem_0049c3ac(int *value);;

/* Function at 0049c6cb (Size: 252 bytes) */
void Palette_Subsystem_0049c6cb(HDC hdc,RECT *card_slot);;

/* Function at 0049c7c7 (Size: 4215 bytes) */
int32_t Palette_Subsystem_0049c7c7(HDC hdc,int *min_val,WPARAM *max_val,int flags,uint32_t flags,int arg_6);;

/* Function at 0049d843 (Size: 576 bytes) */
int32_t Palette_Subsystem_0049d843(HDC hdc,int *min_val,int max_val,int flags,int flags,uint32_t arg_6,int arg_7);;

/* Function at 0049da83 (Size: 398 bytes) */
void Palette_Subsystem_0049da83(int value,int min_val,uint32_t max_val);;

/* Function at 0049dc11 (Size: 196 bytes) */
void Palette_Subsystem_0049dc11(HDC hdc,int min_val,char *str_3);;

/* Function at 0049dcd5 (Size: 213 bytes) */
int Palette_Subsystem_0049dcd5(HDC hdc,char *str_2);;

/* Function at 0049ddaa (Size: 519 bytes) */
int Palette_Subsystem_0049ddaa(int *player,char *str_2);;

/* Function at 0049dfb1 (Size: 736 bytes) */
uint32_t Palette_Subsystem_0049dfb1(HDC hdc,int min_val,int max_val,LONG flags,char *str_5);;

/* Function at 0049e291 (Size: 682 bytes) */
void Palette_Subsystem_0049e291(int value,char min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0049e53b (Size: 129 bytes) */
int32_t Palette_Subsystem_0049e53b(HDC hdc,int min_val,int max_val);;

/* Function at 0049e5bc (Size: 1594 bytes) */
uint32_t Palette_Subsystem_0049e5bc(HDC hdc,int *y,char *str_3,int height);;

/* Function at 0049ebf6 (Size: 435 bytes) */
void Palette_Subsystem_0049ebf6(HDC hdc,RECT *min_val,int max_val,int flags);;

/* Function at 0049eda9 (Size: 2852 bytes) */
void Palette_Subsystem_0049eda9(HDC hdc,int *min_val,int max_val,int flags,int flags);;

/* Function at 0049f8cd (Size: 662 bytes) */
void Palette_Subsystem_0049f8cd(HDC hdc,int *min_val,WPARAM *max_val,int flags,int flags);;

/* Function at 0049fb63 (Size: 900 bytes) */
void Palette_Subsystem_0049fb63(HDC hdc,RECT *min_val,int max_val);;

/* Function at 0049fee7 (Size: 490 bytes) */
void Palette_Subsystem_0049fee7(HDC hdc,int *y,uint32_t width,uint32_t height);;

/* Function at 004a00d1 (Size: 361 bytes) */
void Palette_Subsystem_004a00d1(HDC hdc,int *min_val,int32_t max_val);;

/* Function at 004a023a (Size: 344 bytes) */
int32_t Palette_Subsystem_004a023a(HDC hdc,int min_val,int32_t max_val);;

/* Function at 004a0392 (Size: 212 bytes) */
void Palette_Subsystem_004a0392(LPRECT player,int *card_slot);;

/* Function at 004a0466 (Size: 548 bytes) */
void Palette_Subsystem_004a0466(HDC hdc,int *min_val,int max_val,int flags,int flags);;

/* Function at 004a068a (Size: 385 bytes) */
int32_t Palette_Subsystem_004a068a(int x,int y,int width,int height);;

/* Function at 004a080b (Size: 446 bytes) */
void Palette_Subsystem_004a080b(LPRECT value,int *min_val,int max_val);;

/* Function at 004a09c9 (Size: 823 bytes) */
int32_t Palette_Subsystem_004a09c9(int value,int *min_val,int max_val,int flags,int flags);;

/* Function at 004a0d00 (Size: 663 bytes) */
void Palette_Subsystem_004a0d00(HDC hdc,int32_t *min_val,uint32_t max_val);;

/* Function at 004a0f97 (Size: 611 bytes) */
void Palette_Subsystem_004a0f97(LPRECT value,uint32_t y,int *width,uint32_t height);;

/* Function at 004a11fa (Size: 445 bytes) */
void Palette_Subsystem_004a11fa(HDC hdc,int *min_val,char *str_3,int flags,int flags);;

/* Function at 004a13b7 (Size: 424 bytes) */
void Palette_Subsystem_004a13b7(HDC hdc,int *min_val,int max_val,int32_t flags,int flags);;

/* Function at 004a155f (Size: 1541 bytes) */
void Palette_Subsystem_004a155f(HDC hdc,int *min_val,int max_val,int flags,int flags);;

/* Function at 004a1b64 (Size: 677 bytes) */
void Palette_Subsystem_004a1b64(HDC hdc,RECT *min_val,int max_val,int flags,int flags,int arg_6,int arg_7);;

/* Function at 004a1e09 (Size: 1528 bytes) */
void Palette_Subsystem_004a1e09(HDC hdc,int *y,int width,int height);;

/* Function at 004a2401 (Size: 759 bytes) */
void Palette_Subsystem_004a2401(HDC hdc,int *y,int width,int height);;

/* Function at 004a26f8 (Size: 135 bytes) */
void Palette_Subsystem_004a26f8(int32_t player,int32_t card_slot);;

/* Function at 004a277f (Size: 135 bytes) */
void Palette_Subsystem_004a277f(int32_t player,int32_t card_slot);;

/* Function at 004a2806 (Size: 153 bytes) */
void Palette_Subsystem_004a2806(HDC hdc,int *card_slot);;

/* Function at 004a289f (Size: 294 bytes) */
uint32_t Palette_Subsystem_004a289f(HDC hdc,int *y,int width,int height);;

/* Function at 004a29c5 (Size: 150 bytes) */
void Palette_Subsystem_004a29c5(HDC hdc,int *min_val,int max_val);;

/* Function at 004a2a5b (Size: 72 bytes) */
void Palette_Subsystem_004a2a5b(int32_t value,int *min_val,uint8_t max_val);;

/* Function at 004a2aa3 (Size: 219 bytes) */
void Palette_Subsystem_004a2aa3(LPRECT player,int *card_slot);;

/* Function at 004a2b7e (Size: 592 bytes) */
int32_t Palette_Subsystem_004a2b7e(int value);;

/* Function at 004a2dce (Size: 270 bytes) */
void Palette_Subsystem_004a2dce(char *str_1,char *str_2,int max_val);;

/* Function at 004a2edc (Size: 11 bytes) */
void Palette_Util_004a2edc(void);;

/* Function at 004a2ef0 (Size: 4766 bytes) */
int32_t Palette_Subsystem_004a2ef0(int value);;

/* Function at 004a41fd (Size: 1379 bytes) */
int Palette_Subsystem_004a41fd(void);;

/* Function at 004a4760 (Size: 271 bytes) */
void Palette_Subsystem_004a4760(int value,int min_val,int max_val);;

/* Function at 004a486f (Size: 472 bytes) */
void Palette_Subsystem_004a486f(int player,int card_slot);;

/* Function at 004a4a47 (Size: 2575 bytes) */
void Palette_Subsystem_004a4a47(int value,int min_val,int max_val);;

/* Function at 004a554b (Size: 59 bytes) */
void Palette_Subsystem_004a554b(int x,int y,int *width,int *height);;

/* Function at 004a5586 (Size: 125 bytes) */
void Palette_Subsystem_004a5586(int x,int y,int *width,int *height);;

/* Function at 004a5603 (Size: 287 bytes) */
void Palette_Subsystem_004a5603(int player,int card_slot);;

/* Function at 004a5722 (Size: 1834 bytes) */
int Palette_Subsystem_004a5722(int value,int min_val,int max_val);;

/* Function at 004a5e4c (Size: 304 bytes) */
void Palette_Subsystem_004a5e4c(void);;

/* Function at 004a5f7c (Size: 96 bytes) */
void Palette_Subsystem_004a5f7c(void);;

/* Function at 004a5fdc (Size: 60 bytes) */
void Palette_Subsystem_004a5fdc(void);;

/* Function at 004a6018 (Size: 246 bytes) */
void Palette_Subsystem_004a6018(void);;

/* Function at 004a610e (Size: 397 bytes) */
int32_t Palette_Subsystem_004a610e(int player,int card_slot);;

/* Function at 004a62a0 (Size: 208 bytes) */
int Palette_Subsystem_004a62a0(int32_t value,int min_val,int max_val);;

/* Function at 004a6370 (Size: 1581 bytes) */
int32_t Palette_Subsystem_004a6370(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint8_t *lParam);;

/* Function at 004a69c8 (Size: 845 bytes) */
void Palette_Subsystem_004a69c8(HWND hwnd,uint8_t min_val,uint8_t max_val);;

/* Function at 004a6d20 (Size: 408 bytes) */
int Palette_Subsystem_004a6d20(int value,int min_val,int max_val);;

/* Function at 004a6eb8 (Size: 104 bytes) */
int Palette_Subsystem_004a6eb8(int value);;

/* Function at 004a6fef (Size: 1486 bytes) */
int32_t Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags);;

/* Function at 004a75bd (Size: 147 bytes) */
int Palette_Subsystem_004a75bd(int value);;

/* Function at 004a7650 (Size: 203 bytes) */
int Palette_Subsystem_004a7650(int player,int card_slot);;

/* Function at 004a771b (Size: 249 bytes) */
int Palette_Subsystem_004a771b(int value,int min_val,int32_t max_val);;

/* Function at 004a7814 (Size: 529 bytes) */
int32_t Palette_Subsystem_004a7814(int value,int min_val,int max_val);;

/* Function at 004a7a25 (Size: 424 bytes) */
int Palette_Subsystem_004a7a25(int value,int min_val,int max_val);;

/* Function at 004a7bcd (Size: 312 bytes) */
int Palette_Subsystem_004a7bcd(int value,int min_val,int max_val);;

/* Function at 004a7d05 (Size: 311 bytes) */
int Palette_Subsystem_004a7d05(int player,int card_slot);;

/* Function at 004a7e3c (Size: 238 bytes) */
int32_t Palette_Subsystem_004a7e3c(int value,int min_val,int max_val);;

/* Function at 004a7f2a (Size: 487 bytes) */
int32_t Palette_Subsystem_004a7f2a(int value,int min_val,int max_val);;

/* Function at 004a8111 (Size: 3040 bytes) */
int32_t Palette_Subsystem_004a8111(int value,int min_val,int max_val);;

/* Function at 004a8d46 (Size: 658 bytes) */
int32_t Palette_Subsystem_004a8d46(int value,int min_val,int max_val);;

/* Function at 004a8fd8 (Size: 351 bytes) */
int Palette_Subsystem_004a8fd8(int value,int min_val,int width,uint32_t height);;

/* Function at 004a9137 (Size: 2076 bytes) */
int32_t Palette_Subsystem_004a9137(int value,int min_val,int32_t max_val);;

/* Function at 004a99a0 (Size: 3718 bytes) */
uint32_t Palette_Subsystem_004a99a0(int value);;

/* Function at 004aa830 (Size: 698 bytes) */
void Ai_SaveGameState(void);;

/* Function at 004aaaea (Size: 631 bytes) */
void Ai_RestoreGameState(void);;

/* Function at 004aad61 (Size: 583 bytes) */
void Ai_PushBoardState(void);;

/* Function at 004aafa8 (Size: 583 bytes) */
void Ai_PopBoardState(void);;

/* Function at 004ab1ef (Size: 37 bytes) */
void Ai_ResetEvaluationState(void);;

/* Function at 004ab214 (Size: 119 bytes) */
void Ai_GetActivePlayerScore(void);;

/* Function at 004ab28b (Size: 211 bytes) */
void Ai_EvaluateCreaturePower(void);;

/* Function at 004ab35e (Size: 75 bytes) */
int32_t Ai_GetOpponentPlayerScore(int value);;

/* Function at 004ab3a9 (Size: 74 bytes) */
int32_t Ai_CalcLifeAdvantage(int value);;

/* Function at 004ab3f3 (Size: 108 bytes) */
void Ai_CalcCardAdvantage(void);;

/* Function at 004ab45f (Size: 177 bytes) */
void Ai_ScoreBoardPosition(void);;

/* Function at 004ab510 (Size: 21 bytes) */
int32_t Ai_ClearCandidateScoreList(void);;

/* Function at 004ab525 (Size: 45 bytes) */
void Ai_SortCandidateScoreList(void);;

/* Function at 004ab552 (Size: 2722 bytes) */
int Ai_SimulateCombatRound(int value);;

/* Function at 004abff4 (Size: 2380 bytes) */
int Ai_ChooseAttackers(int player,int card_slot);;

/* Function at 004ac940 (Size: 575 bytes) */
int32_t Ai_ChooseBlockers(int player,int card_slot);;

/* Function at 004acb7f (Size: 155 bytes) */
void Ai_FilterValidBlockers(uint32_t *player,uint32_t *card_slot);;

/* Function at 004acc20 (Size: 538 bytes) */
int32_t Ai_AssignCombatDamage(int32_t *value,uint32_t *min_val,uint32_t max_val,int flags,uint32_t flags,uint32_t arg_6,int32_t arg_7,int arg_8,int32_t arg_9);;

/* Function at 004ace3a (Size: 2167 bytes) */
HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 004ad6c5 (Size: 182 bytes) */
void Ai_LoadStartDuel2Backdrop(int32_t *value,int32_t *out_buffer,int32_t *max_val,int32_t *flags,int32_t *flags,int32_t *arg_6);;

/* Function at 004ad77b (Size: 77 bytes) */
void Ai_InitCombatHeuristics(int value,int min_val,int max_val);;

/* Function at 004ad7c8 (Size: 3680 bytes) */
HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 004ae632 (Size: 228 bytes) */
void Ai_LoadStartDuelBackdrop(int32_t *value,int32_t *out_buffer,int32_t *max_val,int32_t *flags,int32_t *flags,int32_t *arg_6,int32_t *arg_7);;

/* Function at 004ae716 (Size: 99 bytes) */
void Ai_EvaluateManaCurve(int x,int y,int width,int height);;

/* Function at 004ae779 (Size: 298 bytes) */
void Ai_ScoreBoardPermanents(int value);;

/* Function at 004ae8a3 (Size: 242 bytes) */
INT_PTR Ai_CalculateCombatOdds(int32_t value,int32_t min_val,int32_t max_val,int32_t flags,int32_t flags);;

/* Function at 004ae995 (Size: 2915 bytes) */
HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004af4fd (Size: 230 bytes) */
void Ai_LoadEndDuelBackdrop(int32_t *value,int32_t *out_buffer,int32_t *max_val,int *flags,int *flags,int *arg_6,int32_t *arg_7,int32_t *arg_8);;

/* Function at 004af5e3 (Size: 93 bytes) */
void Ai_FindOptimalSpellTarget(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);;

/* Function at 004af640 (Size: 293 bytes) */
int32_t Ai_EvaluateInstantSpells(int player,int card_slot);;

/* Function at 004af765 (Size: 737 bytes) */
LRESULT Ai_ScoreAttackerCombination(int32_t value,char *str_2,int32_t max_val,int32_t flags,int32_t flags,int32_t arg_6,int32_t arg_7,int *arg_8,int32_t *arg_9,int32_t arg_10,int32_t arg_11);;

/* Function at 004afa46 (Size: 35 bytes) */
void Ai_GetHighestPriorityMove(void);;

/* Function at 004afa69 (Size: 445 bytes) */
INT_PTR Ai_EvaluateCreatureCast(int *value,int min_val,int max_val,int32_t flags,int flags,char *str_6);;

/* Function at 004afc26 (Size: 4316 bytes) */
LRESULT Ai_EvaluateSpellCast(HWND hwnd,uint32_t y,HDC hdc,int32_t *flags);;

/* Function at 004b0d24 (Size: 237 bytes) */
void Ai_Subsystem_004b0d24(int *value,int *min_val,int *max_val,int *flags,int *flags,int32_t *arg_6);;

/* Function at 004b0e11 (Size: 111 bytes) */
void Ai_Subsystem_004b0e11(HGDIOBJ value,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags,HGDIOBJ flags);;

/* Function at 004b0e80 (Size: 1026 bytes) */
LRESULT UI_WndProc_004b0e80(HWND hwnd,uint32_t uMsg,WPARAM wParam,LONG *lParam);;

/* Function at 004b128e (Size: 19 bytes) */
void Ai_Util_004b128e(void);;

/* Function at 004b137d (Size: 137 bytes) */
void Ai_Subsystem_004b137d(uint32_t value,int min_val,int max_val);;

/* Function at 004b1406 (Size: 16 bytes) */
void Ai_Util_004b1406(void);;

/* Function at 004b1416 (Size: 452 bytes) */
INT_PTR Ai_Subsystem_004b1416(int value,int32_t min_val,INT_PTR max_val,char *str_4,char *str_5,char *str_6);;

/* Function at 004b15df (Size: 912 bytes) */
HWND UI_DialogProc_004b15df(HWND hwnd,uint32_t uMsg,uint32_t wParam,int32_t *lParam);;

/* Function at 004b1974 (Size: 87 bytes) */
INT_PTR Ai_Subsystem_004b1974(int value,int32_t min_val,INT_PTR max_val);;

/* Function at 004b19d0 (Size: 355 bytes) */
int32_t UI_DialogProc_004b19d0(HWND hwnd,uint32_t uMsg,uint32_t wParam,int32_t *lParam);;

/* Function at 004b1b38 (Size: 94 bytes) */
INT_PTR Ai_Subsystem_004b1b38(int value,int32_t min_val,INT_PTR max_val);;

/* Function at 004b1b9b (Size: 1344 bytes) */
HGDIOBJ UI_DialogProc_004b1b9b(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004b20e5 (Size: 148 bytes) */
LRESULT Ai_Subsystem_004b20e5(HWND hwnd,UINT y,uint32_t width,LPARAM flags);;

/* Function at 004b2183 (Size: 221 bytes) */
void Pic_Load_WinbkQuestn(int32_t *value,int32_t *out_buffer,int *max_val,int *flags,int *flags,int32_t *arg_6,int32_t *arg_7);;

/* Function at 004b2260 (Size: 93 bytes) */
void Ai_Subsystem_004b2260(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);;

/* Function at 004b22bd (Size: 698 bytes) */
INT_PTR Ai_Subsystem_004b22bd(int value,int32_t min_val,int32_t max_val,int flags,uint32_t flags);;

/* Function at 004b257c (Size: 3363 bytes) */
HGDIOBJ UI_DialogProc_004b257c(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004b32d1 (Size: 557 bytes) */
void Ai_CalcManaRequirement_004b32d1(int32_t *value,int32_t *out_buffer,int32_t *max_val,int32_t *flags,int32_t *flags,int *arg_6,int *arg_7,int *arg_8,int32_t *arg_9,int32_t *arg_10);;

/* Function at 004b34fe (Size: 182 bytes) */
void Ai_Subsystem_004b34fe(int value,int min_val,int max_val,HGDIOBJ flags,HGDIOBJ flags,HGDIOBJ arg_6);;

/* Function at 004b35b4 (Size: 451 bytes) */
void Ai_Subsystem_004b35b4(LPRECT value,HWND hwnd,int max_val);;

/* Function at 004b3777 (Size: 193 bytes) */
INT_PTR Ai_Subsystem_004b3777(int value,int32_t *min_val,int32_t max_val,int flags,uint32_t flags);;

/* Function at 004b3847 (Size: 2379 bytes) */
HBRUSH UI_DialogProc_004b3847(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 004b4197 (Size: 221 bytes) */
void Pic_Load_WinbkChangetext(int32_t *value,int32_t *out_buffer,int *max_val,int *flags,int *flags,int32_t *arg_6,int32_t *arg_7);;

/* Function at 004b4274 (Size: 93 bytes) */
void Ai_Subsystem_004b4274(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);;

/* Function at 004b42d1 (Size: 11 bytes) */
void Ai_Util_004b42d1(void);;

/* Function at 004b42dc (Size: 1891 bytes) */
uint32_t Ai_Subsystem_004b42dc(void);;

/* Function at 004b4a3f (Size: 2402 bytes) */
void Ai_EvalAttackCandidate_004b4a3f(int32_t player,uint32_t card_slot);;

/* Function at 004b53a1 (Size: 37 bytes) */
void Ai_Util_004b53a1(void);;

/* Function at 004b53c6 (Size: 39 bytes) */
int32_t Ai_Util_004b53c6(void);;

/* Function at 004b53ed (Size: 64 bytes) */
uint32_t Ai_Subsystem_004b53ed(void);;

/* Function at 004b542d (Size: 16 bytes) */
void Ai_Util_004b542d(void);;

/* Function at 004b543d (Size: 16 bytes) */
void Ai_Util_004b543d(void);;

/* Function at 004b544d (Size: 180 bytes) */
int32_t Ai_Subsystem_004b544d(void);;

/* Function at 004b5501 (Size: 62 bytes) */
void Ai_Subsystem_004b5501(char *str_1);;

/* Function at 004b553f (Size: 526 bytes) */
void Ai_Subsystem_004b553f(char *str_1);;

/* Function at 004b574d (Size: 252 bytes) */
int Ai_Subsystem_004b574d(int value,int min_val,int max_val,int flags,int32_t flags,int32_t arg_6);;

/* Function at 004b584e (Size: 139 bytes) */
int32_t Ai_Subsystem_004b584e(void);;

/* Function at 004b58d9 (Size: 64 bytes) */
void Ai_Subsystem_004b58d9(int value);;

/* Function at 004b5919 (Size: 78 bytes) */
int32_t Ai_Subsystem_004b5919(int player,int card_slot);;

/* Function at 004b5967 (Size: 114 bytes) */
uint32_t Ai_Subsystem_004b5967(int player,int card_slot);;

/* Function at 004b59d9 (Size: 109 bytes) */
int32_t Ai_Subsystem_004b59d9(int player,int card_slot);;

/* Function at 004b5a46 (Size: 114 bytes) */
uint32_t Ai_Subsystem_004b5a46(int player,int card_slot);;

/* Function at 004b5ab8 (Size: 183 bytes) */
void Ai_Subsystem_004b5ab8(int value,int min_val,uint32_t *max_val,uint32_t *flags,uint32_t *flags);;

/* Function at 004b5b6f (Size: 110 bytes) */
int Ai_Subsystem_004b5b6f(int player,int card_slot);;

/* Function at 004b5bdd (Size: 110 bytes) */
int Ai_Subsystem_004b5bdd(int player,int card_slot);;

/* Function at 004b5c4b (Size: 112 bytes) */
int32_t Ai_Subsystem_004b5c4b(int player,int card_slot);;

/* Function at 004b5cbb (Size: 110 bytes) */
int32_t Ai_Subsystem_004b5cbb(int player,int card_slot);;

/* Function at 004b5d2e (Size: 182 bytes) */
int32_t Ai_Subsystem_004b5d2e(int player,int card_slot);;

/* Function at 004b5de4 (Size: 400 bytes) */
uint8_t Ai_Subsystem_004b5de4(int player,int card_slot);;

/* Function at 004b5f74 (Size: 175 bytes) */
void Ai_Subsystem_004b5f74(int *value,int min_val,int max_val);;

/* Function at 004b6023 (Size: 280 bytes) */
int32_t Ai_Subsystem_004b6023(int *value,int min_val,int max_val);;

/* Function at 004b613b (Size: 108 bytes) */
uint8_t Ai_Subsystem_004b613b(int player,int card_slot);;

/* Function at 004b61ac (Size: 110 bytes) */
int Ai_Subsystem_004b61ac(int player,int card_slot);;

/* Function at 004b621a (Size: 110 bytes) */
int Ai_Subsystem_004b621a(int player,int card_slot);;

/* Function at 004b6288 (Size: 206 bytes) */
uint32_t Ai_Subsystem_004b6288(int player,int card_slot);;

/* Function at 004b6356 (Size: 110 bytes) */
int Ai_Subsystem_004b6356(int player,int card_slot);;

/* Function at 004b63c4 (Size: 110 bytes) */
int Ai_Subsystem_004b63c4(int player,int card_slot);;

/* Function at 004b6432 (Size: 109 bytes) */
int32_t Ai_Subsystem_004b6432(int player,int card_slot);;

/* Function at 004b649f (Size: 109 bytes) */
int32_t Ai_Subsystem_004b649f(int player,int card_slot);;

/* Function at 004b650c (Size: 161 bytes) */
void Ai_Subsystem_004b650c(int x,int y,int *width,int *height);;

/* Function at 004b65ad (Size: 18 bytes) */
int32_t Ai_Util_004b65ad(void);;

/* Function at 004b65bf (Size: 100 bytes) */
uint32_t Ai_Subsystem_004b65bf(int player,int card_slot);;

/* Function at 004b6623 (Size: 115 bytes) */
uint32_t Ai_Subsystem_004b6623(int player,int card_slot);;

/* Function at 004b6696 (Size: 168 bytes) */
bool Ai_Subsystem_004b6696(int player,int card_slot);;

/* Function at 004b673e (Size: 109 bytes) */
int32_t Ai_Subsystem_004b673e(int player,int card_slot);;

/* Function at 004b67ab (Size: 132 bytes) */
bool Ai_Subsystem_004b67ab(int player,int card_slot);;

/* Function at 004b682f (Size: 132 bytes) */
bool Ai_Subsystem_004b682f(int player,int card_slot);;

/* Function at 004b68b3 (Size: 263 bytes) */
void Ai_Subsystem_004b68b3(int value,int min_val,char *max_val);;

/* Function at 004b69ba (Size: 494 bytes) */
void Ai_Subsystem_004b69ba(int value,int min_val,char *max_val);;

/* Function at 004b6ba8 (Size: 179 bytes) */
int Ai_Subsystem_004b6ba8(int value,int min_val,void *max_val);;

/* Function at 004b6c5b (Size: 109 bytes) */
int32_t Ai_Subsystem_004b6c5b(int player,int card_slot);;

/* Function at 004b6cc8 (Size: 109 bytes) */
int32_t Ai_Subsystem_004b6cc8(int player,int card_slot);;

/* Function at 004b6d35 (Size: 112 bytes) */
int32_t Ai_Subsystem_004b6d35(int player,int card_slot);;

/* Function at 004b6da5 (Size: 150 bytes) */
void Ai_Subsystem_004b6da5(int32_t *value,int min_val,int max_val);;

/* Function at 004b6e3b (Size: 112 bytes) */
int32_t Ai_Subsystem_004b6e3b(int player,int card_slot);;

/* Function at 004b6eab (Size: 110 bytes) */
int Ai_Subsystem_004b6eab(int player,int card_slot);;

/* Function at 004b6f19 (Size: 48 bytes) */
int32_t Ai_Util_004b6f19(int value);;

/* Function at 004b6f49 (Size: 93 bytes) */
void Ai_Subsystem_004b6f49(char *str_1);;

/* Function at 004b6fa6 (Size: 102 bytes) */
int32_t Ai_Subsystem_004b6fa6(int value);;

/* Function at 004b700c (Size: 102 bytes) */
int32_t Ai_Subsystem_004b700c(int value);;

/* Function at 004b7072 (Size: 140 bytes) */
int32_t Ai_Subsystem_004b7072(void *player,int card_slot);;

/* Function at 004b70fe (Size: 140 bytes) */
int32_t Ai_Subsystem_004b70fe(void *value,int min_val,int max_val);;

/* Function at 004b718a (Size: 163 bytes) */
int32_t Ai_Subsystem_004b718a(void *player,int card_slot);;

/* Function at 004b722d (Size: 163 bytes) */
int32_t Ai_Subsystem_004b722d(void *player,int card_slot);;

/* Function at 004b72d0 (Size: 163 bytes) */
int32_t Ai_Subsystem_004b72d0(void *player,int card_slot);;

/* Function at 004b7373 (Size: 91 bytes) */
int32_t Ai_Subsystem_004b7373(void *value);;

/* Function at 004b73ce (Size: 227 bytes) */
void Ai_Subsystem_004b73ce(int x,int *y,int width,int *height);;

/* Function at 004b74b1 (Size: 73 bytes) */
void Ai_Subsystem_004b74b1(int32_t *player,int32_t *card_slot);;

/* Function at 004b74fa (Size: 117 bytes) */
void Ai_Subsystem_004b74fa(void *player,int card_slot);;

/* Function at 004b756f (Size: 53 bytes) */
void Ai_Subsystem_004b756f(int32_t *value);;

/* Function at 004b75a4 (Size: 52 bytes) */
int32_t Ai_Subsystem_004b75a4(void);;

/* Function at 004b75d8 (Size: 81 bytes) */
bool Ai_Subsystem_004b75d8(int32_t *value);;

/* Function at 004b7629 (Size: 52 bytes) */
int32_t Ai_Subsystem_004b7629(void);;

/* Function at 004b765d (Size: 73 bytes) */
void Ai_Subsystem_004b765d(int32_t *player,int32_t *card_slot);;

/* Function at 004b76a6 (Size: 423 bytes) */
int Ai_Subsystem_004b76a6(void *value,int y,int width,int height);;

/* Function at 004b784d (Size: 74 bytes) */
void Ai_Subsystem_004b784d(int32_t player,int32_t card_slot);;

/* Function at 004b7897 (Size: 1180 bytes) */
int32_t Ai_CalcManaRequirement_004b7897(HWND hwnd,uint32_t uMsg,HDC wParam,int *lParam);;

/* Function at 004b7d38 (Size: 176 bytes) */
int Ai_Subsystem_004b7d38(char *str_1);;

/* Function at 004b7de8 (Size: 1277 bytes) */
HBRUSH UI_PlayCoinTossAvi(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004b82ea (Size: 36 bytes) */
void Ai_Util_004b82ea(int32_t *player,int32_t *card_slot);;

/* Function at 004b830e (Size: 31 bytes) */
void Ai_Util_004b830e(HGDIOBJ value);;

/* Function at 004b832d (Size: 234 bytes) */
int32_t Ai_Subsystem_004b832d(int value,int min_val,int32_t max_val,int32_t flags,int32_t *flags,int32_t *arg_6,int32_t *arg_7);;

/* Function at 004b8421 (Size: 2205 bytes) */
HBRUSH UI_DialogProc_004b8421(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 004b8cc3 (Size: 221 bytes) */
void CardScript_Fireball(int32_t *value,int32_t *out_buffer,int *max_val,int *flags,int *flags,int32_t *arg_6,int32_t *arg_7);;

/* Function at 004b8da0 (Size: 93 bytes) */
void Ai_Subsystem_004b8da0(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);;

/* Function at 004b8dfd (Size: 80 bytes) */
int Ai_Subsystem_004b8dfd(int player,int card_slot);;

/* Function at 004b8e4d (Size: 657 bytes) */
char * Ai_Subsystem_004b8e4d(int player,int card_slot);;

/* Function at 004b90de (Size: 60 bytes) */
void Ai_Subsystem_004b90de(int player,int card_slot);;

/* Function at 004b9120 (Size: 238 bytes) */
int32_t UI_Register_WINBK_ManaPool_004b9120(LPCSTR str_1);;

/* Function at 004b920e (Size: 118 bytes) */
void Ai_Subsystem_004b920e(void);;

/* Function at 004b9284 (Size: 5153 bytes) */
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam);;

/* Function at 004ba6b6 (Size: 472 bytes) */
void Ai_Subsystem_004ba6b6(LPRECT value,HWND hwnd,int max_val);;

/* Function at 004ba890 (Size: 4252 bytes) */
int Ai_CalcManaRequirement_004ba890(int value,int min_val,int max_val);;

/* Function at 004bb9f3 (Size: 422 bytes) */
void Ai_Subsystem_004bb9f3(int x,int min_val,int *max_val,int height);;

/* Function at 004bbb99 (Size: 506 bytes) */
void Ai_Subsystem_004bbb99(int value,int min_val,int *max_val,int flags,int *flags,int arg_6);;

/* Function at 004bbd93 (Size: 507 bytes) */
void Ai_Subsystem_004bbd93(int value,int min_val,int *max_val,int flags,int *flags,int arg_6);;

/* Function at 004bbf8e (Size: 155 bytes) */
int32_t Ai_Subsystem_004bbf8e(int value,int min_val,int max_val);;

/* Function at 004bc029 (Size: 1018 bytes) */
int32_t Ai_Subsystem_004bc029(int32_t spell_id,int *target_id,int flags,int height);;

/* Function at 004bc423 (Size: 675 bytes) */
int32_t Ai_CalcManaRequirement_004bc423(void);;

/* Function at 004bc72e (Size: 2311 bytes) */
int32_t Ai_Subsystem_004bc72e(int value,int32_t min_val,int32_t max_val,int32_t flags,int flags);;

/* Function at 004bd035 (Size: 522 bytes) */
int32_t Ai_Subsystem_004bd035(int value,int min_val,uint8_t max_val);;

/* Function at 004bd23f (Size: 426 bytes) */
int32_t Ai_Subsystem_004bd23f(int player,int card_slot);;

/* Function at 004bd3e9 (Size: 112 bytes) */
void Ai_Subsystem_004bd3e9(int value,int min_val,int max_val,int *flags,int32_t flags,int arg_6,int arg_7,int arg_8,int *arg_9);;

/* Function at 004bd459 (Size: 151 bytes) */
int Ai_Subsystem_004bd459(int value,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7);;

/* Function at 004bd4f0 (Size: 110 bytes) */
int32_t Ai_Subsystem_004bd4f0(void);;

/* Function at 004bd563 (Size: 71 bytes) */
bool Ai_Subsystem_004bd563(int player,int card_slot);;

/* Function at 004bd5af (Size: 47 bytes) */
bool Ai_Util_004bd5af(void);;

/* Function at 004bd5e3 (Size: 154 bytes) */
int32_t Ai_Subsystem_004bd5e3(int value);;

/* Function at 004bd682 (Size: 114 bytes) */
int32_t Ai_Subsystem_004bd682(int value);;

/* Function at 004bd6f9 (Size: 2684 bytes) */
int32_t Ai_Subsystem_004bd6f9(int value,uint32_t min_val,int max_val);;

/* Function at 004be192 (Size: 169 bytes) */
int Ai_Subsystem_004be192(int x,int y,int width,int height);;

/* Function at 004be240 (Size: 31 bytes) */
void Ai_Util_004be240(void);;

/* Function at 004be25f (Size: 248 bytes) */
void Ai_Subsystem_004be25f(int32_t value,int32_t min_val,int32_t max_val,int flags,int32_t flags);;

/* Function at 004be357 (Size: 109 bytes) */
void Ai_Subsystem_004be357(void);;

/* Function at 004be3c4 (Size: 123 bytes) */
void Ai_Subsystem_004be3c4(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 004be43f (Size: 92 bytes) */
void Ai_Subsystem_004be43f(int x,int y,int *width,int *height);;

/* Function at 004be49b (Size: 138 bytes) */
void Ai_Subsystem_004be49b(int x,int y,int *width,int *height);;

/* Function at 004be525 (Size: 137 bytes) */
void Ai_Subsystem_004be525(int x,int y,int *width,int *height);;

/* Function at 004be5ae (Size: 149 bytes) */
void Ai_Subsystem_004be5ae(int x,int y,int *width,int *height);;

/* Function at 004be643 (Size: 3048 bytes) */
void Ai_Subsystem_004be643(int value,int min_val,int max_val);;

/* Function at 004bf23a (Size: 633 bytes) */
void Ai_Subsystem_004bf23a(void);;

/* Function at 004bf4b3 (Size: 2929 bytes) */
void Ai_CalcManaRequirement_004bf4b3(int card_id);;

/* Function at 004c003d (Size: 1380 bytes) */
void Ai_CalcManaRequirement_004c003d(void);;

/* Function at 004c05ba (Size: 293 bytes) */
void Overworld_LoadAdventureInterface800(void);;

/* Function at 004c06df (Size: 2074 bytes) */
void Ai_Subsystem_004c06df(uint32_t player,uint32_t card_slot);;

/* Function at 004c0efe (Size: 4369 bytes) */
void Ai_CastleEncounter_004c0efe(uint32_t value,uint32_t min_val,int max_val,int flags,uint32_t flags,int arg_6,int arg_7,int arg_8);;

/* Function at 004c207a (Size: 497 bytes) */
int32_t Ai_Subsystem_004c207a(int player,int card_slot);;

/* Function at 004c2270 (Size: 50 bytes) */
int32_t Sound_Play_Button2(int value);;

/* Function at 004c22a2 (Size: 158 bytes) */
int Ai_Subsystem_004c22a2(int x,int y,int width,uint8_t *flags);;

/* Function at 004c2340 (Size: 371 bytes) */
void Ai_Subsystem_004c2340(int32_t *value,int min_val,int max_val,int flags,int flags,uint32_t arg_6,int arg_7);;

/* Function at 004c24b3 (Size: 5604 bytes) */
void Ai_CastleEncounter_004c24b3(int value);;

/* Function at 004c3aa1 (Size: 51 bytes) */
void Ai_Subsystem_004c3aa1(int x,int y,int *width,int *height);;

/* Function at 004c3ad4 (Size: 69 bytes) */
void Ai_Subsystem_004c3ad4(int x,int y,int *width,int *height);;

/* Function at 004c3b19 (Size: 138 bytes) */
void Ai_TownEncounter_004c3b19(uint32_t value);;

/* Function at 004c3ba3 (Size: 33 bytes) */
int Ai_Util_004c3ba3(int value);;

/* Function at 004c3bc4 (Size: 33 bytes) */
int Ai_Util_004c3bc4(int value);;

/* Function at 004c3be5 (Size: 119 bytes) */
int32_t Ai_Subsystem_004c3be5(int player,int card_slot);;

/* Function at 004c3c5c (Size: 1459 bytes) */
void Ai_Subsystem_004c3c5c(int value);;

/* Function at 004c4210 (Size: 2676 bytes) */
void Ai_Subsystem_004c4210(int value);;

/* Function at 004c4c84 (Size: 4933 bytes) */
void Ai_Subsystem_004c4c84(int value);;

/* Function at 004c5fc9 (Size: 6879 bytes) */
uint32_t Ai_Subsystem_004c5fc9(int value);;

/* Function at 004c7aa8 (Size: 317 bytes) */
void Ai_Subsystem_004c7aa8(int value);;

/* Function at 004c7be5 (Size: 388 bytes) */
void Ai_Subsystem_004c7be5(int32_t player,int card_slot);;

/* Function at 004c7d69 (Size: 2276 bytes) */
int Ai_Subsystem_004c7d69(void);;

/* Function at 004c864d (Size: 6381 bytes) */
void Ai_EvalAttackCandidate_004c864d(uint32_t spell_id);;

/* Function at 004c9f3a (Size: 78 bytes) */
int32_t Ai_Subsystem_004c9f3a(int player,uint32_t card_slot);;

/* Function at 004c9f88 (Size: 243 bytes) */
int32_t Ai_Subsystem_004c9f88(int value);;

/* Function at 004ca07b (Size: 94 bytes) */
void Ai_Subsystem_004ca07b(void);;

/* Function at 004ca0d9 (Size: 1595 bytes) */
void Ai_Subsystem_004ca0d9(int value,int min_val,int max_val,int flags,int flags,int arg_6,int *arg_7,int *arg_8);;

/* Function at 004ca714 (Size: 1150 bytes) */
void Ai_Subsystem_004ca714(int value,int min_val,int max_val,int flags,int flags,int arg_6,int *arg_7,int *arg_8);;

/* Function at 004cab92 (Size: 467 bytes) */
void Ai_Subsystem_004cab92(void);;

/* Function at 004cad65 (Size: 96 bytes) */
void Ai_Subsystem_004cad65(int value,int min_val,int max_val);;

/* Function at 004cadc5 (Size: 96 bytes) */
void Ai_Subsystem_004cadc5(int value,int min_val,int max_val);;

/* Function at 004cae25 (Size: 34 bytes) */
void Ai_Util_004cae25(WPARAM value);;

/* Function at 004cae47 (Size: 518 bytes) */
int Ai_Subsystem_004cae47(int player,int card_slot);;

/* Function at 004cb04d (Size: 393 bytes) */
int Ai_Subsystem_004cb04d(int player,int card_slot);;

/* Function at 004cb1d6 (Size: 237 bytes) */
int32_t Ai_Subsystem_004cb1d6(int player,int card_slot);;

/* Function at 004cb2d0 (Size: 21 bytes) */
int32_t Ai_Util_004cb2d0(void);;

/* Function at 004cbad0 (Size: 52 bytes) */
uint32_t Ai_Subsystem_004cbad0(int player,int card_slot);;

/* Function at 004cbb04 (Size: 47 bytes) */
int32_t Ai_Util_004cbb04(int player,int card_slot);;

/* Function at 004cbb33 (Size: 106 bytes) */
uint32_t Ai_Subsystem_004cbb33(int player,int card_slot);;

/* Function at 004cbba7 (Size: 48 bytes) */
int Ai_Util_004cbba7(int player,int card_slot);;

/* Function at 004cbbd7 (Size: 48 bytes) */
int Ai_Util_004cbbd7(int player,int card_slot);;

/* Function at 004cbc07 (Size: 47 bytes) */
int32_t Ai_Util_004cbc07(int player,int card_slot);;

/* Function at 004cbc36 (Size: 47 bytes) */
int32_t Ai_Util_004cbc36(int player,int card_slot);;

/* Function at 004cbc65 (Size: 106 bytes) */
int32_t Ai_Subsystem_004cbc65(int player,int card_slot);;

/* Function at 004cbcd9 (Size: 137 bytes) */
int CardTypeFromID(int value);;

/* Function at 004cbd67 (Size: 61 bytes) */
int32_t CardIDFromType(uint32_t value);;

/* Function at 004cbda9 (Size: 44 bytes) */
uint32_t Ai_Util_004cbda9(uint32_t value);;

/* Function at 004cbdda (Size: 54 bytes) */
void Ai_Subsystem_004cbdda(int player,int card_slot);;

/* Function at 004cbe10 (Size: 66 bytes) */
bool Ai_Subsystem_004cbe10(int player,int card_slot);;

/* Function at 004cbe57 (Size: 283 bytes) */
uint8_t Ai_Subsystem_004cbe57(int player,int card_slot);;

/* Function at 004cbf72 (Size: 94 bytes) */
undefined8 Ai_Subsystem_004cbf72(int player,int card_slot);;

/* Function at 004cbfd0 (Size: 131 bytes) */
int32_t Ai_Subsystem_004cbfd0(int value,int min_val,int *max_val);;

/* Function at 004cc053 (Size: 111 bytes) */
uint8_t Ai_Subsystem_004cc053(int player,int card_slot);;

/* Function at 004cc0c7 (Size: 48 bytes) */
int Ai_Util_004cc0c7(int player,int card_slot);;

/* Function at 004cc0f7 (Size: 48 bytes) */
int Ai_Util_004cc0f7(int player,int card_slot);;

/* Function at 004cc127 (Size: 92 bytes) */
int32_t Ai_Subsystem_004cc127(int player,int card_slot);;

/* Function at 004cc188 (Size: 48 bytes) */
int Ai_Util_004cc188(int player,int card_slot);;

/* Function at 004cc1b8 (Size: 48 bytes) */
int Ai_Util_004cc1b8(int player,int card_slot);;

/* Function at 004cc1e8 (Size: 110 bytes) */
char * Ai_Subsystem_004cc1e8(int player,int card_slot);;

/* Function at 004cc25b (Size: 108 bytes) */
int Ai_Subsystem_004cc25b(int player,int card_slot);;

/* Function at 004cc2cc (Size: 108 bytes) */
int Ai_Subsystem_004cc2cc(int player,int card_slot);;

/* Function at 004cc33d (Size: 135 bytes) */
int32_t Ai_Subsystem_004cc33d(int value,int min_val,int32_t max_val);;

/* Function at 004cc3c4 (Size: 52 bytes) */
int32_t Ai_Subsystem_004cc3c4(int player,int card_slot);;

/* Function at 004cc3f8 (Size: 53 bytes) */
void Ai_Subsystem_004cc3f8(int32_t value,int32_t min_val,int32_t max_val,int32_t flags);;

/* Function at 004cc42d (Size: 40 bytes) */
void Ai_Util_004cc42d(char *str_1);;

/* Function at 004cc455 (Size: 69 bytes) */
int32_t Ai_Subsystem_004cc455(int *value,int min_val,int32_t max_val,int flags,char *str_5);;

/* Function at 004cc49a (Size: 71 bytes) */
int32_t Ai_Subsystem_004cc49a(int *value,int min_val,int max_val,int32_t flags,int flags,char *str_6);;

/* Function at 004cc4e1 (Size: 41 bytes) */
void Ai_Util_004cc4e1(int32_t value);;

/* Function at 004cc50a (Size: 99 bytes) */
void Ai_Subsystem_004cc50a(int32_t value,int32_t min_val,char *str_3);;

/* Function at 004cc56d (Size: 595 bytes) */
int Ai_Subsystem_004cc56d(int value,int min_val,int max_val,int flags,int flags,char *str_6,int arg_7);;

/* Function at 004cc7c5 (Size: 79 bytes) */
void Ai_Subsystem_004cc7c5(int32_t player,int32_t card_slot);;

/* Function at 004cc814 (Size: 107 bytes) */
INT_PTR Ai_Subsystem_004cc814(int value,char *str_2,INT_PTR max_val,char *str_4,char *str_5,char *str_6);;

/* Function at 004cc87f (Size: 95 bytes) */
INT_PTR Ai_Subsystem_004cc87f(int value,char *str_2,INT_PTR max_val);;

/* Function at 004cc8de (Size: 95 bytes) */
INT_PTR Ai_Subsystem_004cc8de(int value,char *str_2,INT_PTR max_val);;

/* Function at 004cc93d (Size: 65 bytes) */
int Ai_Subsystem_004cc93d(int value,int32_t min_val,int32_t max_val,int flags,uint32_t flags);;

/* Function at 004cc97e (Size: 71 bytes) */
void Ai_Subsystem_004cc97e(char *str_1);;

/* Function at 004cc9c5 (Size: 734 bytes) */
void Ai_EvaluateTacticalPosition(int player,int card_slot);;

/* Function at 004ccca3 (Size: 565 bytes) */
void Ai_Subsystem_004ccca3(void);;

/* Function at 004cced8 (Size: 631 bytes) */
void Ai_Subsystem_004cced8(void);;

/* Function at 004cd14f (Size: 73 bytes) */
void Ai_Subsystem_004cd14f(int value);;

/* Function at 004cd198 (Size: 57 bytes) */
void Ai_Subsystem_004cd198(void);;

/* Function at 004cd1d1 (Size: 61 bytes) */
int32_t Ai_Subsystem_004cd1d1(void);;

/* Function at 004cd20e (Size: 452 bytes) */
int32_t Pic_Load_Title(void);;

/* Function at 004cd3eb (Size: 592 bytes) */
void Ai_Subsystem_004cd3eb(void);;

/* Function at 004cd63b (Size: 168 bytes) */
int32_t Timer_InitVxD(void);;

/* Function at 004cd6e3 (Size: 50 bytes) */
int32_t Timer_GetTicks(void);;

/* Function at 004cd715 (Size: 21 bytes) */
void Timer_MarkStart(void);;

/* Function at 004cd72a (Size: 53 bytes) */
int Timer_GetElapsedFraction(void);;

/* Function at 004cd760 (Size: 673 bytes) */
int32_t SpellChain_RegisterClass(LPCSTR str_1);;

/* Function at 004cda01 (Size: 334 bytes) */
void SpellChain_CleanupUI(void);;

/* Function at 004cdb4f (Size: 7402 bytes) */
uint32_t SpellChain_WndProc(HWND hwnd,uint32_t y,HWND param_3,uint32_t height);;

/* Function at 004cf8b6 (Size: 175 bytes) */
int SpellChain_GetCardCount(HWND hwnd);;

/* Function at 004cf965 (Size: 333 bytes) */
void SpellChain_UpdateTargetPositions(HWND hwnd,int card_slot);;

/* Function at 004cfab2 (Size: 125 bytes) */
bool SpellChain_HasActiveSpells(void);;

/* Function at 004cfb2f (Size: 569 bytes) */
int SpellChain_CreateCardSlot(HWND hwnd,int32_t min_val,int32_t max_val);;

/* Function at 004cfd68 (Size: 229 bytes) */
void SpellChain_RemoveCardSlot(HWND hwnd,int card_slot);;

/* Function at 004cfe4d (Size: 397 bytes) */
int SpellChain_CreateTargetSlot(HWND hwnd);;

/* Function at 004cffda (Size: 1550 bytes) */
void SpellChain_UpdateLayout(HWND hwnd,LPRECT card_slot);;

/* Function at 004d05e8 (Size: 26 bytes) */
void SpellChain_SetWindowRect(int32_t player,LPRECT card_slot);;

/* Function at 004d0602 (Size: 855 bytes) */
LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,uint32_t lParam);;

/* Function at 004d0965 (Size: 88 bytes) */
BOOL SpellChain_IsVisible(void);;

/* Function at 004d09bd (Size: 112 bytes) */
bool SpellChain_IsMinimized(void);;

/* Function at 004d0a30 (Size: 18 bytes) */
int32_t SpellChain_GetActiveCount(void);;

/* Function at 004d0a42 (Size: 645 bytes) */
uint32_t SpellChain_ProcessTriggerEvent(int player,int card_slot);;

/* Function at 004d0cdb (Size: 959 bytes) */
int32_t Card_ColorWard_ChangeColor(int value,int min_val,int max_val);;

/* Function at 004d109a (Size: 3109 bytes) */
int32_t Card_ChaosLace_ModifyAttributes(int value,int min_val,int max_val);;

/* Function at 004d1cc4 (Size: 332 bytes) */
bool Card_Sinbad_Draw(int value,int min_val,int max_val);;

/* Function at 004d1e10 (Size: 796 bytes) */
int32_t Card_Kudzu_LandDestruction(int value,int min_val,int max_val);;

/* Function at 004d212c (Size: 1247 bytes) */
void Card_BronzeTablets_AnteSwap(int value,int min_val,int max_val);;

/* Function at 004d2610 (Size: 970 bytes) */
int32_t Card_XenicPoltergeist_AnimateArtifact(int spell_id,int target_id,int flags);;

/* Function at 004d29da (Size: 573 bytes) */
int32_t Card_VesuvanDoppelganger_Copy(int spell_id,int target_id,int flags);;

/* Function at 004d2c17 (Size: 273 bytes) */
int32_t Card_VesuvanDoppelganger_Upkeep(int value,int min_val,int max_val);;

/* Function at 004d2d28 (Size: 258 bytes) */
int32_t Card_Doppelganger_ClearMimic(int player,int card_slot);;

/* Function at 004d2e2a (Size: 322 bytes) */
int32_t Card_Doppelganger_ApplyMimicStats(int player,int card_slot);;

/* Function at 004d2f6c (Size: 322 bytes) */
int32_t Card_Doppelganger_SyncAbilities(int player,int card_slot);;

/* Function at 004d30ae (Size: 150 bytes) */
int32_t Card_Doppelganger_CheckState(int value,int min_val,int max_val);;

/* Function at 004d3144 (Size: 101 bytes) */
int32_t Card_IslandSanctuary_SkipDraw(int value,int min_val,int max_val);;

/* Function at 004d31a9 (Size: 128 bytes) */
int32_t Card_IslandSanctuary_AttackRestriction(int value,int min_val,int max_val);;

/* Function at 004d3229 (Size: 99 bytes) */
int32_t Card_IslandSanctuary_Trigger(int value,int min_val,int max_val);;

/* Function at 004d328c (Size: 158 bytes) */
int32_t Card_IslandSanctuary_CheckActive(int value,int min_val,int max_val);;

/* Function at 004d332a (Size: 531 bytes) */
int32_t Card_IslandSanctuary_Prompt(int value,int min_val,int max_val);;

/* Function at 004d353d (Size: 528 bytes) */
int32_t Card_LivingLands_AnimateForests(int value,int min_val,int max_val);;

/* Function at 004d374d (Size: 528 bytes) */
int32_t Card_KormusBell_AnimateSwamps(int value,int min_val,int max_val);;

/* Function at 004d395d (Size: 960 bytes) */
int32_t Card_TitaniasSong_AnimateArtifacts(int value,int min_val,int max_val);;

/* Function at 004d3d1d (Size: 101 bytes) */
int32_t Card_TitaniasSong_RemoveAbilities(int value,int min_val,int max_val);;

/* Function at 004d3d82 (Size: 125 bytes) */
int32_t Card_TitaniasSong_RestoreAbilities(int value,int min_val,int max_val);;

/* Function at 004d3dff (Size: 418 bytes) */
int32_t Card_TitaniasSong_UpdateStatus(int value,int min_val,int max_val);;

/* Function at 004d3fa1 (Size: 248 bytes) */
int32_t Card_TitaniasSong_ClearFlags(int value,int min_val,int max_val);;

/* Function at 004d4099 (Size: 373 bytes) */
int32_t Card_TitaniasSong_CheckTrigger(int value,int min_val,int max_val);;

/* Function at 004d420e (Size: 1364 bytes) */
int32_t Card_PersonalIncarnation_RedirectDamage(int spell_id,int target_id,int flags);;

/* Function at 004d4762 (Size: 1469 bytes) */
int32_t Card_AliFromCairo_PreventLethalDamage(int spell_id,int target_id,int flags);;

/* Function at 004d4d1f (Size: 596 bytes) */
int32_t Card_AliFromCairo_ResetState(int value,int min_val,int max_val);;

/* Function at 004d4f73 (Size: 1715 bytes) */
int32_t Card_ShivanDragon_PumpFirebreathing(int value,int min_val,int max_val);;

/* Function at 004d5626 (Size: 1528 bytes) */
int32_t Card_DragonWhelp_PumpFirebreathing(int value,int min_val,int max_val);;

/* Function at 004d5c1e (Size: 1907 bytes) */
int Card_DragonWhelp_EndTurnCheck(int value,int min_val,int max_val);;

/* Function at 004d6391 (Size: 111 bytes) */
int32_t Card_FrozenShade_ClearBoost(int player,int card_slot);;

/* Function at 004d6400 (Size: 774 bytes) */
int32_t Card_FrozenShade_PumpBlack(int value,int min_val,int max_val);;

/* Function at 004d6706 (Size: 313 bytes) */
int32_t Card_WaterElemental_PumpBlue(int value,int min_val,int max_val);;

/* Function at 004d683f (Size: 661 bytes) */
int32_t Card_ClockworkBeast_ResetCounters(int value,int min_val,int max_val);;

/* Function at 004d6ad4 (Size: 367 bytes) */
int32_t Card_ClockworkBeast_CombatTrigger(int value,int min_val,int max_val);;

/* Function at 004d6c43 (Size: 319 bytes) */
int32_t Card_ClockworkBeast_Rewind(int value,int min_val,int max_val);;

/* Function at 004d6d82 (Size: 247 bytes) */
int32_t Card_ClockworkBeast_GetPower(int value,int min_val,int max_val);;

/* Function at 004d6e79 (Size: 492 bytes) */
int32_t Card_ClockworkBeast_GetToughness(int value,int min_val,int max_val);;

/* Function at 004d7065 (Size: 1727 bytes) */
int32_t Card_GaeasLiege_TransformLand(int spell_id,int target_id,int flags);;

/* Function at 004d7724 (Size: 87 bytes) */
int32_t Card_GaeasLiege_ResetLand(int value,int min_val,int max_val);;

/* Function at 004d777b (Size: 274 bytes) */
int32_t Card_GaeasLiege_CheckAttackRestriction(int value,int min_val,int max_val);;

/* Function at 004d788d (Size: 69 bytes) */
int32_t Card_GaeasLiege_IsForest(int32_t value,int32_t min_val,int max_val);;

/* Function at 004d78d2 (Size: 212 bytes) */
int32_t Card_GaeasLiege_CombatCheck(int value,int min_val,int max_val);;

/* Function at 004d79a6 (Size: 117 bytes) */
int32_t Card_SedgeTroll_CheckSwamp(int value,int min_val,int max_val);;

/* Function at 004d7a1b (Size: 333 bytes) */
int32_t Card_SedgeTroll_Regenerate(int value,int min_val,int max_val);;

/* Function at 004d7b68 (Size: 77 bytes) */
int32_t Card_LivingWall_PromptRegenerate(int value,int min_val,int max_val);;

/* Function at 004d7bb5 (Size: 171 bytes) */
int32_t Card_LivingWall_Regenerate(int value,int min_val,int max_val);;

/* Function at 004d7c60 (Size: 560 bytes) */
int32_t Card_GenericCreature_Regenerate(int value,int min_val,int max_val,uint32_t flags,int flags);;

/* Function at 004d7e90 (Size: 579 bytes) */
int32_t Card_GenericCreature_CanRegenerate(int player,int card_slot);;

/* Function at 004d80d3 (Size: 168 bytes) */
int32_t Card_GenericCreature_TriggerRegen(int value,int min_val,int max_val);;

/* Function at 004d817b (Size: 1616 bytes) */
int32_t Card_DrudgeSkeletons_Regenerate(int value,int min_val,int max_val);;

/* Function at 004d87cb (Size: 1665 bytes) */
int32_t Card_UthdenTroll_Regenerate(int value,int min_val,int max_val);;

/* Function at 004d8e4c (Size: 1685 bytes) */
int32_t Card_WillOTheWisp_Regenerate(int value,int min_val,int max_val);;

/* Function at 004d94e1 (Size: 1564 bytes) */
int32_t Card_MarrowThieves_Regenerate(int value,int min_val,int max_val);;

/* Function at 004d9afd (Size: 1153 bytes) */
void Card_HypnoticSpecter_RandomDiscard(int value,int min_val,int max_val);;

/* Function at 004d9f7e (Size: 1284 bytes) */
int32_t Card_TimeElemental_BouncePermanent(int spell_id,int target_id,int flags);;

/* Function at 004da482 (Size: 982 bytes) */
int32_t Card_NorthernPaladin_DestroyBlack(int spell_id,int target_id,int flags);;

/* Function at 004da858 (Size: 504 bytes) */
int32_t Card_RoyalAssassin_DestroyTapped(int spell_id,int target_id,int flags);;

/* Function at 004daa50 (Size: 449 bytes) */
int32_t Card_DwarvenDemolitionTeam_DestroyWall(int spell_id,int target_id,int flags);;

/* Function at 004dac11 (Size: 613 bytes) */
int32_t Card_KingSuleiman_DestroyDjinn(int spell_id,int target_id,int flags);;

/* Function at 004dae76 (Size: 430 bytes) */
int32_t Card_Targeting_PromptCreature(int x,int y,int width,uint32_t height);;

/* Function at 004db024 (Size: 989 bytes) */
int32_t Card_NettlingImp_ForceAttack(int spell_id,int target_id,int flags);;

/* Function at 004db401 (Size: 1224 bytes) */
bool Card_NettlingImp_CheckEndTurn(int value,int min_val,int max_val);;

/* Function at 004db8c9 (Size: 339 bytes) */
int32_t Card_NettlingImp_IsTargetEligible(int value,int min_val,int max_val);;

/* Function at 004dba1c (Size: 1471 bytes) */
int32_t Card_SorceressQueen_SetStats02(int spell_id,int target_id,int flags);;

/* Function at 004dbfdb (Size: 746 bytes) */
void Card_SorceressQueen_ResetStats(int value,int min_val,int max_val);;

/* Function at 004dc2ca (Size: 1021 bytes) */
int32_t Card_StoneGiant_Fling(int spell_id,int target_id,int flags);;

/* Function at 004dc6c7 (Size: 806 bytes) */
int32_t Card_DwarvenWarriors_MakeUnblockable(int spell_id,int target_id,int flags);;

/* Function at 004dc9ed (Size: 1124 bytes) */
int32_t Card_CavePeople_Mountainwalk(int spell_id,int target_id,int flags);;

/* Function at 004dce51 (Size: 1258 bytes) */
int32_t Card_PradeshGypsies_PreventAttack(int spell_id,int target_id,int flags);;

/* Function at 004dd33b (Size: 754 bytes) */
int32_t Card_PradeshGypsies_ResetRestriction(int value,int min_val,int max_val);;

/* Function at 004dd632 (Size: 861 bytes) */
uint8_t Card_SamiteHealer_PreventDamage(int spell_id,int target_id,int flags);;

/* Function at 004dd98f (Size: 869 bytes) */
int32_t Card_SamiteHealer_CalculateHealAdvantage(int value,int min_val,int max_val);;

/* Function at 004ddcf4 (Size: 349 bytes) */
int32_t Card_AlabasterPotion_HealOrPrevent(int value,int min_val,int max_val);;

/* Function at 004dde51 (Size: 169 bytes) */
int32_t Card_HealingSalve_DamagePrevention(int value,int min_val,int max_val);;

/* Function at 004ddefa (Size: 81 bytes) */
int32_t Card_DamagePrevention_ApplyBubble(int player,int card_slot);;

/* Function at 004ddf4b (Size: 77 bytes) */
int32_t Card_DamagePrevention_ReduceDamage(int value,int min_val,int max_val);;

/* Function at 004ddf98 (Size: 199 bytes) */
int32_t Card_DamagePrevention_ClearAtCleanup(int value,int min_val,int max_val);;

/* Function at 004de05f (Size: 84 bytes) */
int32_t Card_DamagePrevention_QueryAmount(int value,int min_val,int max_val);;

/* Function at 004de0b3 (Size: 77 bytes) */
int32_t Card_DamagePrevention_PromptTarget(int value,int min_val,int max_val);;

/* Function at 004de100 (Size: 192 bytes) */
int32_t Card_DamagePrevention_CheckSource(int value,int min_val,int max_val);;

/* Function at 004de1c0 (Size: 414 bytes) */
int32_t Card_ErgRaiders_UpkeepDamage(int value,int min_val,int max_val);;

/* Function at 004de35e (Size: 308 bytes) */
int32_t Card_ErgRaiders_MarkAttack(int value,int min_val,int max_val);;

/* Function at 004de492 (Size: 939 bytes) */
int32_t Card_ErgRaiders_ClearTurnAttack(int value,int min_val,int max_val);;

/* Function at 004de83d (Size: 972 bytes) */
int32_t Card_Leviathan_SacrificeLands(int value,int min_val,int max_val);;

/* Function at 004dec09 (Size: 610 bytes) */
int32_t Card_Leviathan_PromptLandSacrifice(int spell_id,int target_id,int flags);;

/* Function at 004dee6b (Size: 343 bytes) */
int32_t Card_Leviathan_SelectLand(int value,int min_val,int max_val);;

/* Function at 004defc2 (Size: 136 bytes) */
int32_t Card_Leviathan_AttackTrigger(int value,int min_val,int max_val);;

/* Function at 004df04a (Size: 450 bytes) */
int32_t Card_BrothersOfFire_Ping(int spell_id,int target_id,int flags);;

/* Function at 004df20c (Size: 264 bytes) */
bool Card_BrothersOfFire_EvaluateTarget(int value,int min_val,int max_val);;

/* Function at 004df314 (Size: 868 bytes) */
int32_t Card_CrimsonManticore_DamageTarget(int spell_id,int target_id,int flags);;

/* Function at 004df678 (Size: 578 bytes) */
bool Card_ProdigalSorcerer_PingTarget(int spell_id,int target_id,int flags);;

/* Function at 004df8ba (Size: 612 bytes) */
bool Card_DirectDamage_EvaluateBestTarget(int player,int card_slot);;

/* Function at 004dfb23 (Size: 529 bytes) */
int32_t Card_DirectDamage_PromptAndDealDamage(int x,int y,int width,int height);;

/* Function at 004dfd39 (Size: 347 bytes) */
bool Card_PirateShip_PingTarget(int spell_id,int target_id,int flags);;

/* Function at 004dfe94 (Size: 244 bytes) */
int32_t Card_PirateShip_CheckIslandwalk(int value,int min_val,int max_val);;

/* Function at 004dff88 (Size: 175 bytes) */
int32_t Card_PirateShip_HasIsland(int value,int min_val,int max_val);;

/* Function at 004e0037 (Size: 176 bytes) */
int32_t Card_PirateShip_AttackTrigger(int value,int min_val,int max_val);;

/* Function at 004e00e7 (Size: 718 bytes) */
int32_t Card_IslandFishJasconius_PayToUntap(int value,int min_val,int max_val);;

/* Function at 004e03b5 (Size: 265 bytes) */
int32_t Card_IslandFishJasconius_CheckIslands(int value,int min_val,int max_val);;

/* Function at 004e04be (Size: 194 bytes) */
int32_t Card_IslandFishJasconius_DestroyIfNoIslands(int value,int min_val,int max_val);;

/* Function at 004e0580 (Size: 565 bytes) */
uint32_t Card_RodOfRuin_Ping(int value,int min_val,int max_val);;

/* Function at 004e07b5 (Size: 247 bytes) */
int32_t Card_RodOfRuin_EvaluateAi(int value,int min_val,int max_val);;

/* Function at 004e08ac (Size: 175 bytes) */
int32_t Card_RodOfRuin_PayActivation(int value,int min_val,int max_val);;

/* Function at 004e095b (Size: 348 bytes) */
int32_t Card_RodOfRuin_SelectTarget(int value,int min_val,int max_val);;

/* Function at 004e0ab7 (Size: 357 bytes) */
bool Card_OrcishArtillery_ShootTarget(int spell_id,int target_id,int flags);;

/* Function at 004e0c1c (Size: 580 bytes) */
bool Card_PsionicEntity_ShootTarget(int spell_id,int target_id,int flags);;

/* Function at 004e0e60 (Size: 368 bytes) */
int32_t Card_PsionicEntity_EvaluateTarget(int value,int min_val,int max_val);;

/* Function at 004e0fd0 (Size: 382 bytes) */
int32_t Card_PsionicEntity_SelfDamage(int value,int min_val,int max_val);;

/* Function at 004e114e (Size: 385 bytes) */
int32_t Card_KhabalGhoul_AddCounterOnDeath(int value,int min_val,int max_val);;

/* Function at 004e12cf (Size: 1614 bytes) */
int32_t Card_KhabalGhoul_CheckCreatureDeath(int value,int min_val,int max_val);;

/* Function at 004e191d (Size: 270 bytes) */
int32_t Card_KhabalGhoul_ApplyCounterBonus(int value,int min_val,int max_val);;

/* Function at 004e1a2b (Size: 269 bytes) */
int32_t Card_KhabalGhoul_ResetCounterBonus(int value,int min_val,int max_val);;

/* Function at 004e1b38 (Size: 340 bytes) */
int32_t Card_LordOfAtlantis_PayOrSacrifice(int value,int min_val,int max_val);;

/* Function at 004e1c8c (Size: 266 bytes) */
int32_t Card_LordOfAtlantis_ApplyMerfolkBuff(int value,int min_val,int max_val);;

/* Function at 004e1d96 (Size: 214 bytes) */
int32_t Card_LordOfAtlantis_RemoveMerfolkBuff(int value,int min_val,int max_val);;

/* Function at 004e1e6c (Size: 161 bytes) */
int32_t Card_LordOfAtlantis_IslandwalkTrigger(int value,int min_val,int max_val);;

/* Function at 004e1f0d (Size: 190 bytes) */
int32_t Card_LordOfAtlantis_CheckMerfolkType(int player,int card_slot);;

/* Function at 004e1fcb (Size: 310 bytes) */
int32_t Card_ForceOfNature_PayUpkeep(int value,int min_val,int max_val);;

/* Function at 004e2101 (Size: 433 bytes) */
bool Card_ForceOfNature_AiPayOrTakeDamage(int value,int min_val,int max_val);;

/* Function at 004e22b2 (Size: 988 bytes) */
bool Card_BirdsOfParadise_TapForMana(int spell_id,int target_id,int flags);;

/* Function at 004e268e (Size: 435 bytes) */
int32_t Card_CosmicHorror_PayUpkeep(int value,int min_val,int max_val);;

/* Function at 004e2841 (Size: 856 bytes) */
int32_t Card_LordOfThePit_SacrificeOrDamage(int spell_id,int target_id,int flags);;

/* Function at 004e2b99 (Size: 230 bytes) */
int Card_LordOfThePit_FindSacrificeCandidate(int player,int card_slot);;

/* Function at 004e2c7f (Size: 873 bytes) */
int32_t Card_KormusBell_PayLandUpkeep(int value,int min_val,int max_val);;

/* Function at 004e2fe8 (Size: 320 bytes) */
int32_t Card_KormusBell_CheckSwampCreature(int value,int min_val,int max_val);;

/* Function at 004e3128 (Size: 93 bytes) */
int32_t Card_NetherShadow_CheckGraveyard(int value,int min_val,int max_val);;

/* Function at 004e3185 (Size: 366 bytes) */
int32_t Card_NetherShadow_CountCreaturesAbove(int value,int min_val,int max_val);;

/* Function at 004e32f3 (Size: 497 bytes) */
int32_t Card_NetherShadow_ReturnFromGrave(int value,int min_val,int max_val);;

/* Function at 004e34e4 (Size: 127 bytes) */
int32_t Card_RockHydra_DecrementHead(int value,int min_val,int max_val);;

/* Function at 004e3563 (Size: 129 bytes) */
int32_t Card_RockHydra_DamageTrigger(int value,int min_val,int max_val);;

/* Function at 004e35e4 (Size: 332 bytes) */
void Card_RockHydra_UpdateStatsFromHeads(int value,int min_val,int max_val);;

/* Function at 004e3730 (Size: 91 bytes) */
int32_t Card_RockHydra_InitHeads(int value,int min_val,int max_val);;

/* Function at 004e378b (Size: 970 bytes) */
int32_t Card_RockHydra_RegrowHead(int value,int min_val,int max_val);;

/* Function at 004e3b55 (Size: 753 bytes) */
int32_t Card_AliBaba_TapWall(int spell_id,int target_id,int flags);;

/* Function at 004e3e46 (Size: 766 bytes) */
int32_t Card_LeyDruid_UntapLand(int spell_id,int target_id,int flags);;

/* Function at 004e4144 (Size: 355 bytes) */
uint32_t Card_LeyDruid_AiEvaluateLand(int value,int min_val,int max_val);;

/* Function at 004e42ac (Size: 604 bytes) */
int32_t Card_LeyDruid_ExecuteUntap(int value,int min_val,int max_val);;

/* Function at 004e4508 (Size: 582 bytes) */
void Card_HurkylsRecall_PickArtifact(int value,int min_val,int max_val);;

/* Function at 004e474e (Size: 185 bytes) */
void Card_HurkylsRecall_ReturnAllArtifacts(int value,int min_val,int max_val);;

/* Function at 004e4807 (Size: 1959 bytes) */
int32_t Card_Venom_DestroyCombatBlocker(int spell_id,int target_id,int flags);;

/* Function at 004e4fae (Size: 992 bytes) */
int32_t Card_Venom_AttachToCreature(int value,int min_val,int max_val);;

/* Function at 004e538e (Size: 583 bytes) */
int32_t Card_Venom_CombatDamageTrigger(int value,int min_val,int max_val);;

/* Function at 004e55d5 (Size: 568 bytes) */
int32_t Card_Venom_DestroyAtEndOfCombat(int value,int min_val,int max_val);;

/* Function at 004e580d (Size: 287 bytes) */
bool Card_Venom_AiEvaluateAura(int value,int min_val,int max_val);;

/* Function at 004e592c (Size: 269 bytes) */
int32_t Card_Venom_AiCastScore(int value,int min_val,int max_val);;

/* Function at 004e5a39 (Size: 1026 bytes) */
int32_t Card_Venom_ClearAuraFlags(int value,int min_val,int max_val);;

/* Function at 004e5e3b (Size: 875 bytes) */
int32_t Card_RadjanSpirit_RemoveFlying(int spell_id,int target_id,int flags);;

/* Function at 004e61a6 (Size: 932 bytes) */
int32_t Card_HurrJackal_GrantCombatAbility(int spell_id,int target_id,int flags);;

/* Function at 004e654a (Size: 151 bytes) */
int32_t CardQuery_PlayerControlsColor(int player,uint8_t card_slot);;

/* Function at 004e65e1 (Size: 210 bytes) */
void CardQuery_ForEachPermanent(uint8_t *player,int card_slot);;

/* Function at 004e66b3 (Size: 184 bytes) */
void Card_IncrementCounter(int player,int card_slot);;

/* Function at 004e676b (Size: 118 bytes) */
void Card_DecrementCounter(int player,int card_slot);;

/* Function at 004e67e1 (Size: 186 bytes) */
void Card_AddCounters(int value,int min_val,int max_val);;

/* Function at 004e689b (Size: 120 bytes) */
void Card_RemoveCounters(int value,int min_val,int max_val);;

/* Function at 004e6913 (Size: 101 bytes) */
void Card_SetCounters(int value,int min_val,int max_val);;

/* Function at 004e6978 (Size: 52 bytes) */
uint32_t Card_GetCounters(int player,int card_slot);;

/* Function at 004e69ac (Size: 300 bytes) */
bool CardTarget_PromptTargetCreature(int value,uint32_t min_val,int max_val);;

/* Function at 004e6add (Size: 285 bytes) */
bool CardTarget_SetTargetCreature(int value,uint32_t min_val,int max_val);;

/* Function at 004e6bff (Size: 461 bytes) */
int CardTarget_HasValidCreatureTarget(int value);;

/* Function at 004e6dcc (Size: 300 bytes) */
bool CardTarget_PromptTargetPermanent(int value,uint32_t min_val,int max_val);;

/* Function at 004e6efd (Size: 285 bytes) */
bool CardTarget_SetTargetPermanent(int value,uint32_t min_val,int max_val);;

/* Function at 004e701f (Size: 142 bytes) */
int32_t CardTarget_HasValidPermanentTarget(int value);;

/* Function at 004e70ad (Size: 300 bytes) */
bool CardTarget_PromptTargetPlayerOrCreature(int value,uint32_t min_val,int max_val);;

/* Function at 004e71de (Size: 285 bytes) */
bool CardTarget_SetTargetPlayerOrCreature(int value,uint32_t min_val,int max_val);;

/* Function at 004e7300 (Size: 142 bytes) */
int32_t CardTarget_HasValidPlayerOrCreatureTarget(int value);;

/* Function at 004e73a0 (Size: 1405 bytes) */
int32_t Adventure_EnterTownLocation(void);;

/* Function at 004e7936 (Size: 276 bytes) */
void Adventure_PromptLocationMenu(void);;

/* Function at 004e7a6f (Size: 756 bytes) */
int Adventure_HandleLocationMenuChoice(int player,int card_slot);;

/* Function at 004e7da1 (Size: 326 bytes) */
void Adventure_ExitTownLocation(void);;

/* Function at 004e7f51 (Size: 5122 bytes) */
int Adventure_PlayLocationMusic(void);;

/* Function at 004e93df (Size: 4945 bytes) */
void Adventure_UpdateWorldMapLoop(void);;

/* Function at 004ea7a6 (Size: 248 bytes) */
int32_t Adventure_GetLocationEncounterIndex(int32_t value);;

/* Function at 004ea8df (Size: 128 bytes) */
int32_t Adventure_SetLocationEncounterIndex(int32_t value);;

/* Function at 004ea97c (Size: 157 bytes) */
int Adventure_CheckMonsterEncounter(int player,int card_slot);;

/* Function at 004eaa19 (Size: 131 bytes) */
void Adventure_FormatNewsString(int value,int min_val,int max_val);;

/* Function at 004eaa9c (Size: 176 bytes) */
int32_t Adventure_AppendNewsDetails(int32_t player,int card_slot);;

/* Function at 004eabb2 (Size: 340 bytes) */
void Adventure_PlayMonsterEncounterSound(int x,int min_val,int max_val,int height);;

/* Function at 004ead33 (Size: 99 bytes) */
void Adventure_TriggerDuelFromEncounter(void);;

/* Function at 004ead96 (Size: 33 bytes) */
void Adventure_ReloadWorldPalette(int value);;

/* Function at 004eadb7 (Size: 46 bytes) */
void Adventure_LoadFacePalette(int value);;

/* Function at 004eade5 (Size: 1279 bytes) */
void Adventure_NewsFlash_EnemyAttack(void);;

/* Function at 004eb2f9 (Size: 1302 bytes) */
void Adventure_NewsFlash_Retaliation(int value);;

/* Function at 004eb824 (Size: 1208 bytes) */
void Adventure_NewsFlash_DominionSpell(void);;

/* Function at 004ebcdc (Size: 134 bytes) */
void Adventure_Audio_PlayEffect(char *value,int32_t min_val,int max_val,int flags,int flags);;

/* Function at 004ebd62 (Size: 104 bytes) */
void Adventure_Audio_PlayEffectAtVolume(int32_t value,int y,int width,int height);;

/* Function at 004ebdca (Size: 80 bytes) */
void Adventure_Audio_PlayEffectLooped(int32_t value,int min_val,int max_val);;

/* Function at 004ebe1a (Size: 71 bytes) */
void Adventure_Audio_StopEffectChannel(int32_t value,int min_val,int max_val);;

/* Function at 004ebe61 (Size: 94 bytes) */
void Adventure_Audio_SetPlaybackPosition(char *player,int32_t card_slot);;

/* Function at 004ebebf (Size: 44 bytes) */
void Adventure_Audio_StopAllTracks(void);;

/* Function at 004ebeeb (Size: 231 bytes) */
void Adventure_Audio_PlayCastleVictory(int value);;

/* Function at 004ebfef (Size: 102 bytes) */
void Adventure_Audio_PlayDuelIntro(int value);;

/* Function at 004ec055 (Size: 680 bytes) */
void Adventure_Audio_PlayTerrainAmbience(int value);;

/* Function at 004ec32f (Size: 266 bytes) */
void Adventure_Audio_PlayFootstep(void);;

/* Function at 004ec439 (Size: 190 bytes) */
uint32_t Adventure_Audio_FindSoundOnDrives(char *str_1);;

/* Function at 004ec4fc (Size: 113 bytes) */
char Adventure_Audio_GetMusicDrivePath(void);;

/* Function at 004ec572 (Size: 76 bytes) */
void Adventure_Audio_FreeSoundTrack(void *value);;

/* Function at 004ec5be (Size: 156 bytes) */
int32_t Adventure_Audio_InitSoundTrack(char *str_1,int32_t min_val,int32_t max_val);;

/* Function at 004ec65a (Size: 115 bytes) */
int32_t Adventure_Audio_GetTrackStatus(int32_t value);;

/* Function at 004ec6ea (Size: 271 bytes) */
int Adventure_Map_GetTerrainAtCoord(uint32_t value);;

/* Function at 004ec7f9 (Size: 405 bytes) */
void Adventure_Map_RedrawViewport(void);;

/* Function at 004ec98e (Size: 841 bytes) */
int32_t Adventure_Map_UpdateLightingAndPalette(uint32_t player,uint32_t card_slot);;

/* Function at 004eccd7 (Size: 509 bytes) */
void Adventure_ShowDefeatScreen(void);;

/* Function at 004ecee0 (Size: 180 bytes) */
bool Adventure_PromptConfirmDialog(LPCSTR str_1);;

/* Function at 004ecf94 (Size: 81 bytes) */
void Adventure_DestroyConfirmMenu(void);;

/* Function at 004ecfe5 (Size: 7254 bytes) */
int Duel_MainArena_WndProc(HWND hwnd,uint32_t y,HWND param_3,uint32_t height);;

/* Function at 004eed47 (Size: 263 bytes) */
void Duel_UpdateWindowScroll(HWND hwnd);;

/* Function at 004eee4e (Size: 529 bytes) */
void Duel_BringCardWindowToTop(HWND hwnd);;

/* Function at 004ef05f (Size: 252 bytes) */
void Duel_GetBattlefieldClientRect(HWND hwnd);;

/* Function at 004ef15b (Size: 1264 bytes) */
void Duel_LayoutCardSlots(HWND hwnd,int *min_val,int max_val,int *flags,int *flags,int arg_6);;

/* Function at 004ef64b (Size: 245 bytes) */
void Duel_ScrollLeftButton_Handler(HWND hwnd,HWND param_2);;

/* Function at 004ef740 (Size: 265 bytes) */
void Duel_ScrollRightButton_Handler(HWND hwnd,LPARAM min_val,uint8_t max_val);;

/* Function at 004ef849 (Size: 295 bytes) */
int Duel_HitTestCardSlot(HWND hwnd,int *y,int32_t *max_val,int32_t *flags);;

/* Function at 004ef970 (Size: 171 bytes) */
int32_t Duel_GetHoveredCardSlot(HWND hwnd,int *card_slot);;

/* Function at 004efa20 (Size: 154 bytes) */
int Duel_GetCardSlotWindowHandle(HWND hwnd,int card_slot);;

/* Function at 004efaba (Size: 129 bytes) */
int Duel_GetTargetSlotWindowHandle(HWND hwnd,int card_slot);;

/* Function at 004efb3b (Size: 259 bytes) */
HGDIOBJ Duel_PaintBattlefieldBackground(HWND hwnd,uint32_t min_val,HDC hdc);;

/* Function at 004efd50 (Size: 1932 bytes) */
int Duel_LogActionStatusBanner(int spell_id,int target_id,int flags,uint32_t flags,uint32_t flags,char *str_6,int32_t arg_7);;

/* Function at 004f04e0 (Size: 183 bytes) */
bool Duel_RegisterChildCardWindowClass(LPCSTR str_1);;

/* Function at 004f0597 (Size: 46 bytes) */
void Duel_UnregisterCardWindowClass(void);;

/* Function at 004f05c5 (Size: 1007 bytes) */
LRESULT Duel_ChildCard_WndProc(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 004f09c0 (Size: 138 bytes) */
int Duel_GetCardDrawOriginX(int player,int card_slot);;

/* Function at 004f0a4a (Size: 172 bytes) */
int Duel_GetCardDrawOriginY(int player,int card_slot);;

/* Function at 004f0af6 (Size: 90 bytes) */
void Duel_TriggerCardDrawAnimation(void);;

/* Function at 004f0b50 (Size: 576 bytes) */
int Duel_UpdateCardMotionStep(uint32_t value);;

/* Function at 004f0d90 (Size: 88 bytes) */
void Duel_ResetCardAnimationState(char player,char card_slot);;

/* Function at 004f0de8 (Size: 95 bytes) */
int Bazaar_GetCardBaseValue(int value);;

/* Function at 004f0e47 (Size: 1899 bytes) */
int Bazaar_SellCardsDialog(int value);;

/* Function at 004f15c0 (Size: 841 bytes) */
int32_t * Catalog_LoadWaveletCardArt(int value,char *str_2,int max_val);;

/* Function at 004f1910 (Size: 14 bytes) */
int32_t Catalog_ReleaseWaveletLock(void);;

/* Function at 004f1920 (Size: 836 bytes) */
undefined8 * Haar_DecompressWaveletImage(int *player,undefined8 *card_slot);;

/* Function at 004f1cfa (Size: 283 bytes) */
void FUN_004f1cfa(void);;

/* Function at 004f1e20 (Size: 45 bytes) */
void Mem_AllocOrFree_004f1e20(undefined8 *value,undefined8 *min_val,uint32_t max_val);;

/* Function at 004f1e50 (Size: 110 bytes) */
void Haar_Transform2D_Inverse(undefined8 *value,uint32_t min_val,uint32_t max_val);;

/* Function at 004f1ec0 (Size: 11 bytes) */
void Mem_AllocOrFree_004f1ec0(int *value,int min_val,int max_val);;

/* Function at 004f1ecb (Size: 416 bytes) */
void FUN_004f1ecb(void);;

/* Function at 004f207a (Size: 136 bytes) */
void FUN_004f207a(int value,int32_t min_val,int *max_val,int *flags,int *flags,int arg_6,int32_t arg_7,int32_t arg_8,int arg_9);;

/* Function at 004f2110 (Size: 10 bytes) */
void Mem_AllocOrFree_004f2110(int *value,int *min_val,int *max_val,int flags,int flags,int32_t arg_6,int arg_7);;

/* Function at 004f211a (Size: 140 bytes) */
void FUN_004f211a(int value,int32_t min_val,int *max_val,int *flags,int *flags,int arg_6,int32_t arg_7,int32_t arg_8,int arg_9);;

/* Function at 004f21d0 (Size: 11 bytes) */
uint8_t *Mem_AllocOrFree_004f21d0(uint8_t *value,int *min_val,int max_val,int flags,int *flags,int *arg_6,int arg_7,int32_t arg_8,int arg_9);;

/* Function at 004f21db (Size: 549 bytes) */
uint8_t * FUN_004f21db(void);;

/* Function at 004f2400 (Size: 431 bytes) */
int32_t Haar_DecompressHeader(int32_t *player,int *card_slot);;

/* Function at 004f27c0 (Size: 1153 bytes) */
uint32_t * FUN_004f27c0(void);;

/* Function at 004f2c50 (Size: 140 bytes) */
int32_t FUN_004f2c50(HWND value,int y,int width,int height);;

/* Function at 004f2d30 (Size: 292 bytes) */
int FUN_004f2d30(HWND hwnd,int min_val,int max_val,int flags,DWORD flags,DWORD arg_6);;

/* Function at 004f2e60 (Size: 246 bytes) */
int32_t UI_DeckDialogProc_004f2e60(char *str_1,char *str_2,int32_t *max_val);;

/* Function at 004f2f56 (Size: 1561 bytes) */
HGDIOBJ UI_DialogProc_004f2f56(HWND hwnd,uint32_t y,HDC hdc,HWND param_4);;

/* Function at 004f3579 (Size: 775 bytes) */
int32_t FUN_004f3579(int value);;

/* Function at 004f3880 (Size: 93 bytes) */
bool FUN_004f3880(void);;

/* Function at 004f38dd (Size: 65 bytes) */
void FUN_004f38dd(void);;

/* Function at 004f391e (Size: 55 bytes) */
void FUN_004f391e(char *str_1);;

/* Function at 004f3955 (Size: 79 bytes) */
void GDI_RealizeAndFlushPalette_Magic(HDC hdc);;

/* Function at 004f39a4 (Size: 387 bytes) */
int32_t FUN_004f39a4(int32_t value,int min_val,int32_t *max_val,BITMAPINFO *flags,int32_t *flags,int32_t *arg_6,int *arg_7);;

/* Function at 004f3b2c (Size: 51 bytes) */
void FUN_004f3b2c(HDC hdc,HGDIOBJ card_slot);;

/* Function at 004f3b5f (Size: 104 bytes) */
int32_t FUN_004f3b5f(int value,int min_val,HANDLE max_val);;

/* Function at 004f3bc7 (Size: 330 bytes) */
int32_t FUN_004f3bc7(HDC hdc,int *min_val,HANDLE max_val,int flags,int flags,int arg_6,int arg_7);;

/* Function at 004f3d11 (Size: 280 bytes) */
int32_t FUN_004f3d11(HDC hdc,int *min_val,HANDLE max_val);;

/* Function at 004f3e29 (Size: 129 bytes) */
int32_t FUN_004f3e29(HDC value,int *min_val,HANDLE max_val);;

/* Function at 004f3eaa (Size: 379 bytes) */
int32_t FUN_004f3eaa(HDC hdc,int *min_val,HANDLE max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int arg_9);;

/* Function at 004f4025 (Size: 193 bytes) */
int32_t Pic_LoadDIBSection(int32_t value,LPCSTR str_2,void *max_val,int32_t flags);;

/* Function at 004f40e6 (Size: 257 bytes) */
int32_t Pic_LoadDIBSectionFromFile(LPCSTR str_1,void *min_val,int32_t max_val);;

/* Function at 004f41e7 (Size: 795 bytes) */
HBITMAP FUN_004f41e7(BITMAPINFO *player,void *card_slot);;

/* Function at 004f4548 (Size: 146 bytes) */
void Pic_DestroyDIBSection(HANDLE value);;

/* Function at 004f45da (Size: 753 bytes) */
int32_t Palette_LoadDuelPalette(void);;

/* Function at 004f48cb (Size: 38 bytes) */
void FUN_004f48cb(void);;

/* Function at 004f48f1 (Size: 417 bytes) */
void FUN_004f48f1(int value,int min_val,RECT *max_val);;

/* Function at 004f4a92 (Size: 591 bytes) */
void FUN_004f4a92(char *str_1,char *str_2,int width,char *str_4);;

/* Function at 004f4ce1 (Size: 461 bytes) */
int FUN_004f4ce1(char *str_1,char *str_2,int max_val);;

/* Function at 004f4eb3 (Size: 261 bytes) */
int FUN_004f4eb3(HWND hwnd,char *str_2);;

/* Function at 004f4fb8 (Size: 134 bytes) */
LRESULT UI_WndProc_004f4fb8(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 004f5048 (Size: 191 bytes) */
int32_t FUN_004f5048(char *str_1,COLORREF min_val,HBRUSH max_val);;

/* Function at 004f5107 (Size: 974 bytes) */
void FUN_004f5107(int value,HBRUSH min_val,HGDIOBJ max_val,HGDIOBJ flags,COLORREF flags,int arg_6);;

/* Function at 004f54d5 (Size: 567 bytes) */
void FUN_004f54d5(int value,HANDLE min_val,HANDLE max_val,HANDLE flags,COLORREF flags,int arg_6);;

/* Function at 004f570c (Size: 28 bytes) */
void FUN_004f570c(HWND hwnd);;

/* Function at 004f5728 (Size: 65 bytes) */
int32_t FUN_004f5728(HWND hwnd);;

/* Function at 004f5769 (Size: 309 bytes) */
LRESULT FUN_004f5769(HWND hwnd,UINT y,HWND param_3,LPARAM flags);;

/* Function at 004f589e (Size: 72 bytes) */
bool FUN_004f589e(HWND hwnd);;

/* Function at 004f58eb (Size: 268 bytes) */
uint8_t * FUN_004f58eb(char *str_1,int card_slot);;

/* Function at 004f59f7 (Size: 383 bytes) */
void FUN_004f59f7(void);;

/* Function at 004f5b76 (Size: 131 bytes) */
int FUN_004f5b76(int player,int card_slot);;

/* Function at 004f5bf9 (Size: 190 bytes) */
int32_t FUN_004f5bf9(HWND hwnd,int min_val,int max_val);;

/* Function at 004f5cbc (Size: 94 bytes) */
uint32_t FUN_004f5cbc(int value);;

/* Function at 004f5d1a (Size: 421 bytes) */
int32_t GDI_RealizePaletteTree_Magic(HWND hwnd,uint32_t y,HWND param_3,int32_t flags);;

/* Function at 004f5ec4 (Size: 84 bytes) */
int32_t FUN_004f5ec4(HWND hwnd,int *card_slot);;

/* Function at 004f5f20 (Size: 305 bytes) */
uint32_t FUN_004f5f20(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 004f6060 (Size: 278 bytes) */
void FUN_004f6060(int value,int min_val,int max_val,int flags,int flags,int32_t arg_6);;

/* Function at 004f6180 (Size: 2434 bytes) */
int Catalog_LoadCardsDat(char *str_1);;

/* Function at 004f6b02 (Size: 49 bytes) */
void Mem_AllocOrFree_004f6b02(void);;

/* Function at 004f6b33 (Size: 597 bytes) */
int32_t FUN_004f6b33(LPCSTR str_1);;

/* Function at 004f6d88 (Size: 49 bytes) */
void Mem_AllocOrFree_004f6d88(void);;

/* Function at 004f6db9 (Size: 205 bytes) */
char * FUN_004f6db9(int32_t *value);;

/* Function at 004f6e90 (Size: 701 bytes) */
int32_t FUN_004f6e90(int value,int min_val,int max_val);;

/* Function at 004f714d (Size: 355 bytes) */
int32_t FUN_004f714d(int value,int min_val,int max_val);;

/* Function at 004f72b0 (Size: 936 bytes) */
int32_t Prompts_Load_004f72b0(int spell_id,int target_id,int flags);;

/* Function at 004f7658 (Size: 529 bytes) */
int32_t Prompts_Load_004f7658(int spell_id,int target_id,int flags);;

/* Function at 004f7869 (Size: 529 bytes) */
int32_t FUN_004f7869(int value,int min_val,int max_val);;

/* Function at 004f7a7a (Size: 380 bytes) */
int32_t CardScript_Darkpact(int value,int min_val,int max_val);;

/* Function at 004f7bf6 (Size: 283 bytes) */
int32_t FUN_004f7bf6(int value,int min_val,int max_val);;

/* Function at 004f7d11 (Size: 477 bytes) */
int32_t FUN_004f7d11(int value,int min_val,int max_val);;

/* Function at 004f7eee (Size: 323 bytes) */
int32_t FUN_004f7eee(int value,int min_val,int max_val);;

/* Function at 004f8031 (Size: 521 bytes) */
int32_t FUN_004f8031(int value,int min_val,int max_val);;

/* Function at 004f823a (Size: 91 bytes) */
void FUN_004f823a(int player,int card_slot);;

/* Function at 004f8295 (Size: 140 bytes) */
int32_t FUN_004f8295(int value,int min_val,int max_val);;

/* Function at 004f8321 (Size: 849 bytes) */
int32_t Prompts_Load_004f8321(int spell_id,int target_id,int flags);;

/* Function at 004f8672 (Size: 572 bytes) */
int32_t Prompts_Load_004f8672(int spell_id,int target_id,int flags);;

/* Function at 004f88ae (Size: 237 bytes) */
int32_t FUN_004f88ae(int value,int min_val,int max_val);;

/* Function at 004f899b (Size: 1852 bytes) */
int32_t Prompts_Load_004f899b(int spell_id,int target_id,int flags);;

/* Function at 004f90d7 (Size: 540 bytes) */
int32_t FUN_004f90d7(int value,int min_val,int max_val);;

/* Function at 004f92f3 (Size: 541 bytes) */
int32_t FUN_004f92f3(int value,int min_val,int max_val);;

/* Function at 004f9510 (Size: 237 bytes) */
int32_t FUN_004f9510(int value,int min_val,int max_val);;

/* Function at 004f95fd (Size: 314 bytes) */
int32_t FUN_004f95fd(int value,int min_val,int max_val);;

/* Function at 004f9737 (Size: 1153 bytes) */
int32_t Prompts_Load_004f9737(int spell_id,int target_id,int flags);;

/* Function at 004f9bbd (Size: 679 bytes) */
int32_t Prompts_Load_004f9bbd(int spell_id,int target_id,int flags);;

/* Function at 004f9e64 (Size: 1471 bytes) */
int32_t Prompts_Load_004f9e64(int spell_id,int target_id,int flags);;

/* Function at 004fa423 (Size: 149 bytes) */
int FUN_004fa423(int player,int card_slot);;

/* Function at 004fa4b8 (Size: 206 bytes) */
int FUN_004fa4b8(int value,int min_val,int max_val);;

/* Function at 004fa586 (Size: 3166 bytes) */
int32_t Prompts_Load_004fa586(int spell_id,int target_id,int flags);;

/* Function at 004fb1e4 (Size: 906 bytes) */
int32_t Prompts_Load_004fb1e4(int spell_id,int target_id,int flags);;

/* Function at 004fb573 (Size: 322 bytes) */
int32_t FUN_004fb573(int value,int min_val,int max_val);;

/* Function at 004fb6b5 (Size: 1311 bytes) */
int32_t Prompts_Load_004fb6b5(int spell_id,int target_id,int flags);;

/* Function at 004fbbd4 (Size: 1103 bytes) */
int Prompts_Load_004fbbd4(int spell_id,int target_id,int flags);;

/* Function at 004fc023 (Size: 706 bytes) */
int32_t CardScript_DrafnasRestoration(int value,int min_val,int max_val);;

/* Function at 004fc2e5 (Size: 889 bytes) */
int Prompts_Load_004fc2e5(int spell_id,int target_id,int flags);;

/* Function at 004fc65e (Size: 576 bytes) */
int32_t FUN_004fc65e(int value,int min_val,int max_val);;

/* Function at 004fc89e (Size: 711 bytes) */
int32_t Prompts_Load_004fc89e(int spell_id,int target_id,int flags);;

/* Function at 004fcb7a (Size: 880 bytes) */
int32_t Prompts_Load_004fcb7a(int spell_id,int target_id,int flags);;

/* Function at 004fceea (Size: 561 bytes) */
int32_t Prompts_Load_004fceea(int spell_id,int target_id,int flags);;

/* Function at 004fd11b (Size: 692 bytes) */
int32_t FUN_004fd11b(int value,int min_val,int max_val);;

/* Function at 004fd3cf (Size: 533 bytes) */
int32_t Prompts_Load_004fd3cf(int spell_id,int target_id,int flags);;

/* Function at 004fd5e4 (Size: 608 bytes) */
int32_t FUN_004fd5e4(int value,int min_val,int max_val);;

/* Function at 004fd844 (Size: 380 bytes) */
int32_t FUN_004fd844(int value,int min_val,int max_val);;

/* Function at 004fd9c0 (Size: 274 bytes) */
int FUN_004fd9c0(int player,uint32_t card_slot);;

/* Function at 004fdad2 (Size: 334 bytes) */
int FUN_004fdad2(int value,int min_val,uint32_t max_val);;

/* Function at 004fdc20 (Size: 299 bytes) */
int FUN_004fdc20(int x,int y,uint32_t width,int height);;

/* Function at 004fdd4b (Size: 237 bytes) */
int32_t FUN_004fdd4b(int value,int min_val,int max_val);;

/* Function at 004fde38 (Size: 314 bytes) */
int32_t FUN_004fde38(int value,int min_val,int max_val);;

/* Function at 004fdf72 (Size: 237 bytes) */
int32_t FUN_004fdf72(int value,int min_val,int max_val);;

/* Function at 004fe05f (Size: 1568 bytes) */
int32_t Prompts_Load_004fe05f(int spell_id,int target_id,int flags);;

/* Function at 004fe67f (Size: 642 bytes) */
int32_t Prompts_Load_004fe67f(int spell_id,int target_id,int flags);;

/* Function at 004fe901 (Size: 181 bytes) */
int32_t FUN_004fe901(int value,int min_val,int max_val);;

/* Function at 004fe9b6 (Size: 1451 bytes) */
int32_t Prompts_Load_004fe9b6(int spell_id,int target_id,int flags);;

/* Function at 004fef61 (Size: 542 bytes) */
int32_t Prompts_Load_004fef61(int spell_id,int target_id,int flags);;

/* Function at 004ff17f (Size: 492 bytes) */
int32_t Prompts_Load_004ff17f(int spell_id,int target_id,int flags);;

/* Function at 004ff36b (Size: 228 bytes) */
int32_t FUN_004ff36b(int value,int min_val,int max_val);;

/* Function at 004ff450 (Size: 374 bytes) */
void FUN_004ff450(HWND hwnd);;

/* Function at 004ff5c6 (Size: 2001 bytes) */
HBRUSH UI_DialogProc_004ff5c6(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004ffd9c (Size: 230 bytes) */
void Pic_Load_s_WINBK_Options_004ffd9c(int32_t *value,int32_t *out_buffer,int32_t *max_val,int *flags,int *flags,int *arg_6,int32_t *arg_7,int32_t *arg_8);;

/* Function at 004ffe82 (Size: 93 bytes) */
void FUN_004ffe82(HANDLE value,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);;

/* Function at 004ffedf (Size: 1918 bytes) */
void Rules_ParseFilter_004ffedf(void);;

/* Function at 0050065d (Size: 1022 bytes) */
void Rules_ParseFilter_0050065d(void);;

/* Function at 00500a5b (Size: 634 bytes) */
void Config_SaveRegistrySettings(void);;

/* Function at 00500cd5 (Size: 418 bytes) */
void FUN_00500cd5(void);;

/* Function at 00500e80 (Size: 1337 bytes) */
int WinMain(HINSTANCE x,HINSTANCE y,LPSTR width,int height);;

/* Function at 005013be (Size: 652 bytes) */
LRESULT UI_WndProc_ShowPaletteClass_005013be(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 00501671 (Size: 136 bytes) */
void FUN_00501671(void);;

/* Function at 005016f9 (Size: 40 bytes) */
int32_t Mem_AllocOrFree_005016f9(void);;

/* Function at 00501721 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_00501721(void);;

/* Function at 00501736 (Size: 52 bytes) */
void FUN_00501736(int value);;

/* Function at 0050176a (Size: 35 bytes) */
void FUN_0050176a(void);;

/* Function at 0050178d (Size: 25 bytes) */
void FUN_0050178d(void);;

/* Function at 005017a6 (Size: 74 bytes) */
int32_t Sound_LoadWav_sound_locmus1_005017a6(void);;

/* Function at 005017f0 (Size: 118 bytes) */
void FUN_005017f0(int32_t *value,int32_t min_val,int max_val);;

/* Function at 00501870 (Size: 304 bytes) */
void AssertOrLog(int x,int y,int width,char *str_4);;

/* Function at 005019a0 (Size: 290 bytes) */
void AssertOrLog(int x,int y,int width,char *str_4);;

/* Function at 00501ad0 (Size: 132 bytes) */
bool UI_RegisterClass_00501ad0(LPCSTR str_1);;

/* Function at 00501b54 (Size: 1002 bytes) */
LRESULT UI_WndProc_00501b54(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 00501f50 (Size: 15607 bytes) */
void FUN_00501f50(uint32_t value);;

/* Function at 00505c74 (Size: 172 bytes) */
int32_t FUN_00505c74(void);;

/* Function at 00505d20 (Size: 287 bytes) */
bool FUN_00505d20(int value);;

/* Function at 00505e3f (Size: 104 bytes) */
int32_t FUN_00505e3f(int value);;

/* Function at 00505ea7 (Size: 386 bytes) */
void FUN_00505ea7(int value);;

/* Function at 00506029 (Size: 207 bytes) */
void FUN_00506029(char *str_1);;

/* Function at 00506102 (Size: 431 bytes) */
void FUN_00506102(void);;

/* Function at 005062b1 (Size: 220 bytes) */
int32_t FUN_005062b1(void);;

/* Function at 0050638d (Size: 105 bytes) */
int32_t FUN_0050638d(int x,int y,int width,int height);;

/* Function at 005063f6 (Size: 238 bytes) */
int32_t FUN_005063f6(int player,int card_slot);;

/* Function at 005064e9 (Size: 139 bytes) */
int32_t FUN_005064e9(int player,int card_slot);;

/* Function at 00506580 (Size: 5505 bytes) */
int Town_Process_00506580(uint32_t value);;

/* Function at 00507b1a (Size: 42 bytes) */
void Sound_LoadWav_x_sound_button2_00507b1a(void);;

/* Function at 00507b44 (Size: 322 bytes) */
int32_t FUN_00507b44(int player,int card_slot);;

/* Function at 00507c86 (Size: 4024 bytes) */
int32_t Town_Process_00507c86(uint32_t value);;

/* Function at 00508c3e (Size: 153 bytes) */
void Town_Process_00508c3e(void);;

/* Function at 00508cd7 (Size: 1671 bytes) */
void Town_Process_00508cd7(void);;

/* Function at 0050935e (Size: 441 bytes) */
int32_t FUN_0050935e(int player,int card_slot);;

/* Function at 00509517 (Size: 2749 bytes) */
void Merchant_ProcessBuy_00509517(void);;

/* Function at 00509fd4 (Size: 145 bytes) */
void Town_Process_00509fd4(void);;

/* Function at 0050a065 (Size: 152 bytes) */
void Town_Process_0050a065(void);;

/* Function at 0050a0fd (Size: 126 bytes) */
void Town_Process_0050a0fd(void);;

/* Function at 0050a17b (Size: 126 bytes) */
void Town_Process_0050a17b(void);;

/* Function at 0050a1f9 (Size: 105 bytes) */
void Town_Process_0050a1f9(void);;

/* Function at 0050a262 (Size: 126 bytes) */
void Town_Process_0050a262(void);;

/* Function at 0050a2e0 (Size: 241 bytes) */
void FUN_0050a2e0(int value,int min_val,char *str_3);;

/* Function at 0050a73e (Size: 331 bytes) */
uint8_t * FUN_0050a73e(int value);;

/* Function at 0050a8ae (Size: 273 bytes) */
int SellPrice(int value);;

/* Function at 0050a9bf (Size: 1228 bytes) */
int FUN_0050a9bf(int value);;

/* Function at 0050aef6 (Size: 199 bytes) */
int32_t FUN_0050aef6(int player,int card_slot);;

/* Function at 0050afbd (Size: 79 bytes) */
void FUN_0050afbd(void);;

/* Function at 0050b00c (Size: 240 bytes) */
int FUN_0050b00c(void);;

/* Function at 0050b0fc (Size: 164 bytes) */
int FUN_0050b0fc(uint8_t player,uint8_t card_slot);;

/* Function at 0050b1a0 (Size: 102 bytes) */
void FUN_0050b1a0(void);;

/* Function at 0050b206 (Size: 472 bytes) */
void FUN_0050b206(int value,int min_val,int max_val,int flags,char *str_5);;

/* Function at 0050b3de (Size: 480 bytes) */
void FUN_0050b3de(int value,int min_val,int max_val,int flags,int flags,int arg_6,char *str_7);;

/* Function at 0050b5be (Size: 161 bytes) */
void FUN_0050b5be(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 0050b65f (Size: 865 bytes) */
void FUN_0050b65f(int value,int min_val,int max_val,int flags,char *str_5);;

/* Function at 0050b9d5 (Size: 442 bytes) */
void FUN_0050b9d5(int *value);;

/* Function at 0050bba0 (Size: 310 bytes) */
bool Rules_ShufflePlayerLibrary(LPCSTR str_1);;

/* Function at 0050bcd6 (Size: 81 bytes) */
void FUN_0050bcd6(void);;

/* Function at 0050bd27 (Size: 2798 bytes) */
LRESULT UI_LibraryCardCountWndProc(HWND hwnd,uint32_t y,HWND param_3,uint32_t height);;

/* Function at 0050c82b (Size: 41 bytes) */
void Mem_AllocOrFree_0050c82b(int value);;

/* Function at 0050c854 (Size: 179 bytes) */
LRESULT UI_WndProc_0050c854(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam);;

/* Function at 0050ce18 (Size: 6 bytes) */
BOOL GetSaveFileNameA(LPOPENFILENAMEA value);;

/* Function at 0050ce66 (Size: 6 bytes) */
void MCIWndCreateA(void);;

/* Function at 0050ce6c (Size: 6 bytes) */
void DeckBuilderMain(void);;

/* Function at 0050ce80 (Size: 3 bytes) */
int32_t Mem_AllocOrFree_0050ce80(void);;

/* Function at 0050ce90 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_0050ce90(int32_t player,int card_slot);;

/* Function at 0050ceb0 (Size: 5 bytes) */
int32_t * thunk_FUN_0050cef0(void);;

/* Function at 0050cec0 (Size: 38 bytes) */
void Mem_AllocOrFree_0050cec0(int value);;

/* Function at 0050cef0 (Size: 440 bytes) */
int32_t * FUN_0050cef0(void);;

/* Function at 0050d0b0 (Size: 483 bytes) */
int32_t * Memory_AllocateVirtualPage(int x,int y,int width,int height);;

/* Function at 0050d2a0 (Size: 200 bytes) */
int32_t Memory_FreeVirtualPage(int value);;

/* Function at 0050d370 (Size: 227 bytes) */
void FUN_0050d370(int player,int32_t card_slot);;

/* Function at 0050d4a0 (Size: 64 bytes) */
void FUN_0050d4a0(int *player,int card_slot);;

/* Function at 0050d4e0 (Size: 63 bytes) */
void FUN_0050d4e0(int value);;

/* Function at 0050d520 (Size: 55 bytes) */
void FUN_0050d520(int value);;

/* Function at 0050d560 (Size: 152 bytes) */
void FUN_0050d560(int player,int card_slot);;

/* Function at 0050d6f0 (Size: 198 bytes) */
uint32_t Surface_GetPixel(int value,int min_val,int max_val);;

/* Function at 0050da40 (Size: 199 bytes) */
uint32_t Surface_GetPixelPtr(int *value,int min_val,int max_val);;

/* Function at 0050db10 (Size: 157 bytes) */
void Surface_DrawLine(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0050dbb0 (Size: 121 bytes) */
void Surface_PutPixel(int *x,int y,int width,uint32_t height);;

/* Function at 0050dc30 (Size: 176 bytes) */
void Surface_FillRect(int *value,int min_val,int max_val,int flags,int flags,uint32_t arg_6);;

/* Function at 0050dce0 (Size: 853 bytes) */
void Surface_BlitToDevice(int *value,uint32_t min_val,int max_val,uint32_t flags,DWORD flags,int *arg_6,int arg_7,int arg_8);;

/* Function at 0050e040 (Size: 582 bytes) */
void FUN_0050e040(int *value,uint32_t min_val,int max_val,uint32_t flags,DWORD flags,int *arg_6,int arg_7,int arg_8);;

/* Function at 0050e290 (Size: 91 bytes) */
void Surface_StretchBlt(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8,int arg_9,int arg_10);;

/* Function at 0050e2f0 (Size: 1021 bytes) */
void Graphics_MScaledRectCopy(void);;

/* Function at 0050e6f0 (Size: 109 bytes) */
void FUN_0050e6f0(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 0050e760 (Size: 232 bytes) */
void Surface_PutLine(int32_t *value,int min_val,int max_val,int flags,uint32_t flags);;

/* Function at 0050e850 (Size: 96 bytes) */
void Surface_GetLine(int32_t *value,int min_val,int max_val,int flags,uint32_t flags);;

/* Function at 0050e8b0 (Size: 735 bytes) */
void FUN_0050e8b0(short *value);;

/* Function at 0050eb90 (Size: 132 bytes) */
void FUN_0050eb90(int value);;

/* Function at 0050ec20 (Size: 104 bytes) */
int FUN_0050ec20(HWND hwnd,void *min_val,int max_val,int flags,DWORD flags,DWORD arg_6);;

/* Function at 0050ec90 (Size: 123 bytes) */
void FUN_0050ec90(int32_t value,int min_val,int max_val);;

/* Function at 0050ed10 (Size: 22 bytes) */
int32_t Mem_AllocOrFree_0050ed10(void *value);;

/* Function at 0050edf0 (Size: 253 bytes) */
int Font_LoadFontFile(char *str_1);;

/* Function at 0050eef0 (Size: 497 bytes) */
int32_t FUN_0050eef0(int player,FILE *fp);;

/* Function at 0050f0f0 (Size: 237 bytes) */
int32_t FUN_0050f0f0(int value,int min_val,char *str_3);;

/* Function at 0050f1e0 (Size: 197 bytes) */
int32_t FUN_0050f1e0(int value,int min_val,LPCSTR str_3,LPCSTR str_4,int flags,DWORD arg_6);;

/* Function at 0050f2e0 (Size: 108 bytes) */
HFONT FUN_0050f2e0(int player,LONG card_slot);;

/* Function at 0050f350 (Size: 59 bytes) */
BOOL FUN_0050f350(int value);;

/* Function at 0050f390 (Size: 172 bytes) */
int FUN_0050f390(int player,char card_slot);;

/* Function at 0050f440 (Size: 458 bytes) */
int FUN_0050f440(int *player,char *str_2);;

/* Function at 0050f610 (Size: 304 bytes) */
int FUN_0050f610(int *value,char *str_2,int max_val);;

/* Function at 0050f740 (Size: 32 bytes) */
int Mem_AllocOrFree_0050f740(int value);;

/* Function at 0050f760 (Size: 187 bytes) */
int32_t FUN_0050f760(int *x,int y,int width,LPCSTR str_4);;

/* Function at 0050f820 (Size: 978 bytes) */
int FUN_0050f820(int *x,int y,int width,char *str_4);;

/* Function at 0050fc00 (Size: 25 bytes) */
void Mem_AllocOrFree_0050fc00(void);;

/* Function at 0050fc20 (Size: 46 bytes) */
void FUN_0050fc20(void);;

/* Function at 0050fc50 (Size: 17 bytes) */
void Mem_AllocOrFree_0050fc50(void *value);;

/* Function at 0050fc70 (Size: 70 bytes) */
size_t FUN_0050fc70(void *player,char *str_2);;

/* Function at 0050fcc0 (Size: 141 bytes) */
int Sprite_LoadAll(int32_t *player,char *str_2);;

/* Function at 0050fd50 (Size: 149 bytes) */
uint32_t Sprite_LoadCount(int32_t *value,char *str_2,uint32_t max_val);;

/* Function at 0050fdf0 (Size: 154 bytes) */
int Sprite_ScanRunLength(int value,int min_val,int max_val,int flags,int flags);;

/* Function at 0050fe90 (Size: 841 bytes) */
void Sprite_EncodeFromSurface(int value,int min_val,int max_val,uint32_t flags,int flags);;

/* Function at 005101e0 (Size: 384 bytes) */
void Sprite_DrawDirect(int *x,int y,int width,int height);;

/* Function at 00510360 (Size: 752 bytes) */
void Sprite_DrawClipped(int *x,int y,int width,int height);;

/* Function at 00510650 (Size: 1181 bytes) */
void Sprite_DrawScaled(int *value,int min_val,int max_val,int flags,int flags,int arg_6);;

/* Function at 00510b70 (Size: 610 bytes) */
void FileIO_OpenFileStream(int value,int min_val,int max_val,char *str_4,short *flags);;

/* Function at 00510de0 (Size: 25 bytes) */
void Mem_AllocOrFree_00510de0(int player,char *str_2);;

/* Function at 00510e20 (Size: 25 bytes) */
void Mem_AllocOrFree_00510e20(int player,char *str_2);;

/* Function at 00510e40 (Size: 22 bytes) */
void LoadPalNoPic(char *filepath);;

/* Function at 00510e60 (Size: 25 bytes) */
void Mem_AllocOrFree_00510e60(char *str_1,short *card_slot);;

/* Function at 00510fc0 (Size: 350 bytes) */
void FUN_00510fc0(int *player,int *card_slot);;

/* Function at 00511120 (Size: 364 bytes) */
void FUN_00511120(uint32_t *player,int *card_slot);;

/* Function at 005112b0 (Size: 747 bytes) */
int Surface_TransformPoint(short player,short card_slot);;

/* Function at 005115a0 (Size: 784 bytes) */
int FUN_005115a0(short player,short card_slot);;

/* Function at 00511930 (Size: 172 bytes) */
int32_t FUN_00511930(HDC hdc,COLORREF min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8);;

/* Function at 005119e0 (Size: 425 bytes) */
uint32_t FUN_005119e0(HDC hdc,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,HDC param_8);;

/* Function at 00511b90 (Size: 461 bytes) */
uint32_t FUN_00511b90(HDC hdc,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,HDC param_8,int arg_9,int arg_10);;

/* Function at 00511d60 (Size: 182 bytes) */
int32_t FUN_00511d60(HDC hdc,COLORREF min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int arg_9,int arg_10);;

/* Function at 00511e20 (Size: 846 bytes) */
void FUN_00511e20(HDC hdc,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int arg_9,HDC param_10);;

/* Function at 005121d0 (Size: 6 bytes) */
int32_t Mem_AllocOrFree_005121d0(void);;

/* Function at 005121e0 (Size: 6 bytes) */
int32_t Mem_AllocOrFree_005121e0(void);;

/* Function at 005121f0 (Size: 9 bytes) */
void FUN_005121f0(void);;

/* Function at 00512200 (Size: 9 bytes) */
void FUN_00512200(void);;

/* Function at 00512210 (Size: 16 bytes) */
int32_t Mem_AllocOrFree_00512210(void);;

/* Function at 00512220 (Size: 1 bytes) */
void Mem_AllocOrFree_00512220(void);;

/* Function at 00512230 (Size: 608 bytes) */
int32_t * Pcx_Load256ColorPcx(char *str_1,int32_t *min_val,void *max_val);;

/* Function at 00512500 (Size: 421 bytes) */
int32_t Pic_DecodeKimpicHeader(void *value);;

/* Function at 005126b0 (Size: 132 bytes) */
int32_t Pic_DecodeKimpicScanline(uint8_t *value);;

/* Function at 00512740 (Size: 422 bytes) */
int32_t Pcx_OpenPcxFileStream(void);;

/* Function at 005129a0 (Size: 293 bytes) */
int32_t FUN_005129a0(uint8_t *player,int card_slot);;

/* Function at 00512b50 (Size: 66 bytes) */
int32_t FUN_00512b50(void *value);;

/* Function at 00512ba0 (Size: 95 bytes) */
int FUN_00512ba0(int32_t player,char *str_2);;

/* Function at 00512c00 (Size: 130 bytes) */
int FUN_00512c00(int32_t value,int min_val,int max_val,int flags,int flags,int arg_6,char *str_7);;

/* Function at 00512c90 (Size: 13 bytes) */
void Mem_AllocOrFree_00512c90(int value,uint8_t *min_val,int32_t max_val,int flags,int flags,int arg_6,int arg_7);;

/* Function at 00512c9d (Size: 1364 bytes) */
void FUN_00512c9d(void);;

/* Function at 00513200 (Size: 664 bytes) */
void FUN_00513200(int value);;

/* Function at 005134a0 (Size: 109 bytes) */
void FUN_005134a0(void);;

/* Function at 00513510 (Size: 204 bytes) */
uint32_t FUN_00513510(int value);;

/* Function at 005135e0 (Size: 170 bytes) */
void FUN_005135e0(int player,uint32_t card_slot);;

/* Function at 00513820 (Size: 131 bytes) */
ATOM UI_Register_ShowPaletteClass_00513820(HINSTANCE hInstance);;

/* Function at 005138b0 (Size: 121 bytes) */
void UI_Register_ShowPaletteClass_005138b0(HINSTANCE hInstance,HWND hwnd);;

/* Function at 00513a70 (Size: 140 bytes) */
void FUN_00513a70(HDC hdc,int min_val,int max_val,int flags,int flags,uint32_t arg_6);;

/* Function at 00513afc (Size: 6 bytes) */
size_t __cdecl strlen(char *str_1);;

/* Function at 00513b02 (Size: 6 bytes) */
int __cdecl sprintf(char *str_1,char *str_2,...);;

/* Function at 00513b08 (Size: 6 bytes) */
int __cdecl abs(int value);;

/* Function at 00513b0e (Size: 6 bytes) */
char * __cdecl strcat(char *str_1,char *str_2);;

/* Function at 00513b14 (Size: 6 bytes) */
char * __cdecl strcpy(char *str_1,char *str_2);;

/* Function at 00513b2c (Size: 6 bytes) */
int __cdecl strcmp(char *str_1,char *str_2);;

/* Function at 00513b80 (Size: 6 bytes) */
void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t max_val);;

/* Function at 00513b98 (Size: 6 bytes) */
int __cdecl _vsnprintf(char *str_1,size_t min_val,char *str_3,va_list flags);;

/* Function at 00513b9e (Size: 6 bytes) */
void * __cdecl memset(void *ptr_1,int min_val,size_t max_val);;

/* Function at 00513bbc (Size: 6 bytes) */
clock_t __cdecl clock(void);;

/* Function at 00513bd0 (Size: 47 bytes) */
void Mem_AllocOrFree_00513bd0(void);;

/* Function at 00513c00 (Size: 6 bytes) */
int __cdecl memcmp(void *ptr_1,void *ptr_2,size_t max_val);;

/* Function at 00513c50 (Size: 31 bytes) */
longlong __fastcall __allshl(uint8_t player,int card_slot);;

/* Function at 00513c80 (Size: 208 bytes) */
_onexit_t __onexit(_onexit_t value);;

/* Function at 00513d50 (Size: 48 bytes) */
int __cdecl _atexit(_func_4879 *ptr_1);;

/* Function at 00513da0 (Size: 510 bytes) */
void entry(void);;

/* Function at 00513fde (Size: 6 bytes) */
int __cdecl _write(int value,void *ptr_2,uint32_t max_val);;

/* Function at 00514008 (Size: 6 bytes) */
void __dllonexit(void);;

/* Function at 00514022 (Size: 6 bytes) */
void __cdecl initterm(void);;

/* Function at 00514030 (Size: 29 bytes) */
void __setdefaultprecision(void);;

/* Function at 00514060 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00514060(void);;

/* Function at 00514080 (Size: 11 bytes) */
int __cdecl __setargv(void);;

/* Function at 005140a4 (Size: 6 bytes) */
uint32_t __cdecl _controlfp(uint32_t player,uint32_t card_slot);;

/* Function at 00514128 (Size: 6 bytes) */
int __cdecl _chdir(char *str_1);;

/* Function at 0070d000 (Size: 396 bytes) */
void __fastcall Pic_ReadCompressedChunk(int32_t value,int32_t min_val,uint16_t *max_val);;

/* Function at 0070d245 (Size: 112 bytes) */
void __fastcall FUN_0070d245(int32_t player,int32_t card_slot);;

/* Function at 0070d2b5 (Size: 75 bytes) */
void FUN_0070d2b5(void);;

/* Function at 0070d300 (Size: 146 bytes) */
void __fastcall FUN_0070d300(uint32_t value);;

/* Function at 0070d392 (Size: 242 bytes) */
int32_t __fastcall FUN_0070d392(int32_t value,uint32_t min_val,int32_t max_val);;

/* Function at 0070d484 (Size: 36 bytes) */
void Mem_AllocOrFree_0070d484(int32_t player,uint32_t card_slot);;


#ifdef __cplusplus
}
#endif

#endif /* MAGIC_H */
