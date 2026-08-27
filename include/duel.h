/*
 * duel.h - Function Prototypes and Header for DUEL.EXE
 * Decompiled using Ghidra on 2026-08-24 22:26:04
 */
#ifndef DUEL_H
#define DUEL_H

#include "windows_types.h"
#include "duel_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function at 00401000 (Size: 183 bytes) */
bool UI_BigCardDialogProc(LPCSTR str_1);;

/* Function at 004010b7 (Size: 46 bytes) */
void FUN_004010b7(void);;

/* Function at 004010e5 (Size: 1007 bytes) */
LRESULT UI_WndProc_004010e5(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 004014e0 (Size: 701 bytes) */
int32_t FUN_004014e0(int max_val,int point,int hBitmap);;

/* Function at 0040179d (Size: 355 bytes) */
int32_t FUN_0040179d(int max_val,int point,int hBitmap);;

/* Function at 00401900 (Size: 936 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00401ca8 (Size: 529 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00401eb9 (Size: 529 bytes) */
int32_t FUN_00401eb9(int max_val,int point,int hBitmap);;

/* Function at 004020ca (Size: 379 bytes) */
int32_t FUN_004020ca(int max_val,int point,int hBitmap);;

/* Function at 00402245 (Size: 283 bytes) */
int32_t FUN_00402245(int max_val,int point,int hBitmap);;

/* Function at 00402360 (Size: 477 bytes) */
int32_t FUN_00402360(int max_val,int point,int hBitmap);;

/* Function at 0040253d (Size: 323 bytes) */
int32_t FUN_0040253d(int max_val,int point,int hBitmap);;

/* Function at 00402680 (Size: 521 bytes) */
int32_t FUN_00402680(int max_val,int point,int hBitmap);;

/* Function at 00402889 (Size: 91 bytes) */
void FUN_00402889(int player,int card_slot);;

/* Function at 004028e4 (Size: 140 bytes) */
int32_t FUN_004028e4(int max_val,int point,int hBitmap);;

/* Function at 00402970 (Size: 849 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00402cc1 (Size: 572 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00402efd (Size: 237 bytes) */
int32_t FUN_00402efd(int max_val,int point,int hBitmap);;

/* Function at 00402fea (Size: 1851 bytes) */
int32_t Glue_Subsystem_004dec09(int spell_id,int target_id,int flags);;

/* Function at 00403725 (Size: 542 bytes) */
int32_t FUN_00403725(int max_val,int point,int hBitmap);;

/* Function at 00403943 (Size: 540 bytes) */
int32_t FUN_00403943(int max_val,int point,int hBitmap);;

/* Function at 00403b5f (Size: 237 bytes) */
int32_t FUN_00403b5f(int max_val,int point,int hBitmap);;

/* Function at 00403c4c (Size: 314 bytes) */
int32_t FUN_00403c4c(int max_val,int point,int hBitmap);;

/* Function at 00403d86 (Size: 1153 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 0040420c (Size: 679 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004044b3 (Size: 1470 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00404a71 (Size: 149 bytes) */
int FUN_00404a71(int player,int card_slot);;

/* Function at 00404b06 (Size: 206 bytes) */
int FUN_00404b06(int max_val,int point,int hBitmap);;

/* Function at 00404bd4 (Size: 3165 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00405831 (Size: 906 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00405bc0 (Size: 322 bytes) */
int32_t FUN_00405bc0(int max_val,int point,int hBitmap);;

/* Function at 00405d02 (Size: 1316 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00406226 (Size: 1103 bytes) */
int Pic_Load_0042a1c9(int spell_id,int target_id,int flags);;

/* Function at 00406675 (Size: 706 bytes) */
int32_t Glue_Subsystem_004e4508(int max_val,int point,int hBitmap);;

/* Function at 00406937 (Size: 889 bytes) */
int Pic_Load_0042a1c9(int spell_id,int target_id,int flags);;

/* Function at 00406cb0 (Size: 576 bytes) */
int32_t Glue_Subsystem_004e4508(int max_val,int point,int hBitmap);;

/* Function at 00406ef0 (Size: 712 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004071cd (Size: 880 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 0040753d (Size: 559 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 0040776c (Size: 690 bytes) */
int32_t Glue_Subsystem_004e4508(int max_val,int point,int hBitmap);;

/* Function at 00407a1e (Size: 533 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00407c33 (Size: 608 bytes) */
int32_t FUN_00407c33(int max_val,int point,int hBitmap);;

/* Function at 00407e93 (Size: 380 bytes) */
int32_t FUN_00407e93(int max_val,int point,int hBitmap);;

/* Function at 0040800f (Size: 274 bytes) */
int FUN_0040800f(int player,uint32_t card_slot);;

/* Function at 00408121 (Size: 334 bytes) */
int FUN_00408121(int max_val,int point,uint32_t hBitmap);;

/* Function at 0040826f (Size: 299 bytes) */
int FUN_0040826f(int x,int y,uint32_t width,int height);;

/* Function at 0040839a (Size: 237 bytes) */
int32_t FUN_0040839a(int max_val,int point,int hBitmap);;

/* Function at 00408487 (Size: 314 bytes) */
int32_t FUN_00408487(int max_val,int point,int hBitmap);;

/* Function at 004085c1 (Size: 237 bytes) */
int32_t FUN_004085c1(int max_val,int point,int hBitmap);;

/* Function at 004086ae (Size: 1568 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00408cce (Size: 642 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00408f50 (Size: 182 bytes) */
int32_t FUN_00408f50(int max_val,int point,int hBitmap);;

/* Function at 00409006 (Size: 1451 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004095b1 (Size: 542 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004097cf (Size: 492 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004099bb (Size: 228 bytes) */
int32_t FUN_004099bb(int max_val,int point,int hBitmap);;

/* Function at 00409aa0 (Size: 38 bytes) */
void Mem_AllocOrFree_00409aa0(int max_val,int point,int hBitmap);;

/* Function at 00409ac6 (Size: 38 bytes) */
void Mem_AllocOrFree_00409ac6(int max_val,int point,int hBitmap);;

/* Function at 00409aec (Size: 38 bytes) */
void Mem_AllocOrFree_00409aec(int max_val,int point,int hBitmap);;

/* Function at 00409b12 (Size: 38 bytes) */
void Mem_AllocOrFree_00409b12(int max_val,int point,int hBitmap);;

/* Function at 00409b38 (Size: 38 bytes) */
void Mem_AllocOrFree_00409b38(int max_val,int point,int hBitmap);;

/* Function at 00409b5e (Size: 347 bytes) */
int32_t FUN_00409b5e(int x,int y,int width,int flags);;

/* Function at 00409cb9 (Size: 897 bytes) */
int32_t Mana_Init_00456f29(int spell_id,int target_id,int flags);;

/* Function at 0040a03a (Size: 1180 bytes) */
int32_t CardScript_TimeVault(int spell_id,int target_id,int flags);;

/* Function at 0040a4d6 (Size: 564 bytes) */
int32_t FUN_0040a4d6(int max_val,int point,int hBitmap);;

/* Function at 0040a70a (Size: 566 bytes) */
int32_t FUN_0040a70a(int max_val,int point,int hBitmap);;

/* Function at 0040a940 (Size: 428 bytes) */
int32_t FUN_0040a940(int max_val,int point,int hBitmap);;

/* Function at 0040aaec (Size: 268 bytes) */
int32_t FUN_0040aaec(int max_val,int point,int hBitmap);;

/* Function at 0040abf8 (Size: 1839 bytes) */
int32_t CardScript_AladdinsLamp(int spell_id,int target_id,int flags);;

/* Function at 0040b327 (Size: 322 bytes) */
int32_t FUN_0040b327(int max_val,int point,int hBitmap);;

/* Function at 0040b469 (Size: 445 bytes) */
int32_t FUN_0040b469(int max_val,int point,int hBitmap);;

/* Function at 0040b626 (Size: 882 bytes) */
int32_t FUN_0040b626(int max_val,int point,int hBitmap);;

/* Function at 0040b998 (Size: 102 bytes) */
int32_t FUN_0040b998(int max_val,int point,int hBitmap);;

/* Function at 0040b9fe (Size: 63 bytes) */
int32_t FUN_0040b9fe(int player,int card_slot);;

/* Function at 0040ba3d (Size: 1030 bytes) */
int32_t FUN_0040ba3d(int max_val,int point,int hBitmap);;

/* Function at 0040be43 (Size: 506 bytes) */
int32_t Card_Setup_004590b4(int max_val,int point,int hBitmap);;

/* Function at 0040c03d (Size: 554 bytes) */
int32_t Minit_Subsystem_004592ae(int max_val,int point,int hBitmap);;

/* Function at 0040c267 (Size: 756 bytes) */
int32_t CardScript_PrimalClay(int spell_id,int target_id,int flags);;

/* Function at 0040c560 (Size: 1322 bytes) */
int32_t CardScript_Shapeshifter(int spell_id,int target_id,int flags);;

/* Function at 0040ca8f (Size: 1041 bytes) */
int32_t CardScript_Tetravite(int max_val,int point,int hBitmap);;

/* Function at 0040cea5 (Size: 306 bytes) */
int FUN_0040cea5(int player,int card_slot);;

/* Function at 0040cfd7 (Size: 472 bytes) */
int32_t CardScript_Tetravus(int spell_id,int target_id,int flags);;

/* Function at 0040d1af (Size: 331 bytes) */
int32_t FUN_0040d1af(int player,int card_slot);;

/* Function at 0040d2fa (Size: 532 bytes) */
int32_t CardScript_Tetravite(int spell_id,int target_id);;

/* Function at 0040d50e (Size: 154 bytes) */
int32_t FUN_0040d50e(int max_val,int point,int hBitmap);;

/* Function at 0040d5a8 (Size: 478 bytes) */
bool CardScript_Triskelion(int spell_id,int target_id,int flags);;

/* Function at 0040d786 (Size: 1858 bytes) */
int32_t CardScript_UrzasAvenger(int spell_id,int target_id,int flags);;

/* Function at 0040dedd (Size: 940 bytes) */
int32_t CardScript_Millstone(int spell_id,int target_id,int flags);;

/* Function at 0040e289 (Size: 727 bytes) */
int32_t Mana_Init_0045b502(int spell_id,int target_id,int flags);;

/* Function at 0040e560 (Size: 1202 bytes) */
int32_t Mana_Init_0045b7d9(int spell_id,int target_id,int flags);;

/* Function at 0040ea12 (Size: 197 bytes) */
int32_t FUN_0040ea12(int max_val,int point,int hBitmap);;

/* Function at 0040ead7 (Size: 2117 bytes) */
int32_t CardScript_AshnodsBattlegear(int spell_id,int target_id,int flags);;

/* Function at 0040f321 (Size: 2708 bytes) */
int32_t CardScript_TawnosWeaponry(int spell_id,int target_id,int flags);;

/* Function at 0040fdb5 (Size: 457 bytes) */
int32_t FUN_0040fdb5(int max_val,int point,int hBitmap);;

/* Function at 0040ff7e (Size: 1617 bytes) */
int32_t CardScript_CandelabraOfTawnos(int spell_id,int target_id,int flags);;

/* Function at 004105cf (Size: 77 bytes) */
int32_t FUN_004105cf(int max_val,int point,int hBitmap);;

/* Function at 0041061c (Size: 77 bytes) */
int32_t FUN_0041061c(int max_val,int point,int hBitmap);;

/* Function at 00410669 (Size: 1225 bytes) */
int32_t CardScript_Forcefield(int spell_id,int target_id,int flags);;

/* Function at 00410b32 (Size: 716 bytes) */
int32_t CardScript_DisruptingScepter(int spell_id,int target_id,int flags);;

/* Function at 00410dfe (Size: 395 bytes) */
int32_t FUN_00410dfe(int max_val,int point,int hBitmap);;

/* Function at 00410f89 (Size: 169 bytes) */
int32_t FUN_00410f89(int max_val,int point,int hBitmap);;

/* Function at 00411032 (Size: 170 bytes) */
int32_t FUN_00411032(int max_val,int point,int hBitmap);;

/* Function at 004110dc (Size: 34 bytes) */
int32_t Mem_AllocOrFree_004110dc(int32_t max_val,int32_t point,int hBitmap);;

/* Function at 004110fe (Size: 38 bytes) */
void Mem_AllocOrFree_004110fe(int max_val,int point,int hBitmap);;

/* Function at 00411124 (Size: 38 bytes) */
void Mem_AllocOrFree_00411124(int max_val,int point,int hBitmap);;

/* Function at 0041114a (Size: 38 bytes) */
void Mem_AllocOrFree_0041114a(int max_val,int point,int hBitmap);;

/* Function at 00411170 (Size: 38 bytes) */
void Mem_AllocOrFree_00411170(int max_val,int point,int hBitmap);;

/* Function at 00411196 (Size: 38 bytes) */
void Mem_AllocOrFree_00411196(int max_val,int point,int hBitmap);;

/* Function at 004111bc (Size: 1568 bytes) */
int32_t Mana_Init_0045e430(int x,int y,int width,int flags);;

/* Function at 004117e6 (Size: 387 bytes) */
int32_t FUN_004117e6(int max_val,int point,int hBitmap);;

/* Function at 0041196e (Size: 1645 bytes) */
int32_t CardScript_Conservator(int spell_id,int target_id,int flags);;

/* Function at 00411fe0 (Size: 371 bytes) */
int32_t FUN_00411fe0(int max_val,int point,int hBitmap);;

/* Function at 00412153 (Size: 38 bytes) */
void Mem_AllocOrFree_00412153(int max_val,int point,int hBitmap);;

/* Function at 00412179 (Size: 38 bytes) */
void Mem_AllocOrFree_00412179(int max_val,int point,int hBitmap);;

/* Function at 0041219f (Size: 38 bytes) */
void Mem_AllocOrFree_0041219f(int max_val,int point,int hBitmap);;

/* Function at 004121c5 (Size: 38 bytes) */
void Mem_AllocOrFree_004121c5(int max_val,int point,int hBitmap);;

/* Function at 004121eb (Size: 38 bytes) */
void Mem_AllocOrFree_004121eb(int max_val,int point,int hBitmap);;

/* Function at 00412211 (Size: 38 bytes) */
void Mem_AllocOrFree_00412211(int max_val,int point,int hBitmap);;

/* Function at 00412237 (Size: 467 bytes) */
int32_t FUN_00412237(int x,int y,int width,int height);;

/* Function at 0041240a (Size: 425 bytes) */
int32_t FUN_0041240a(int max_val,int point,int hBitmap);;

/* Function at 004125b3 (Size: 1408 bytes) */
int FUN_004125b3(int max_val,int point,int hBitmap);;

/* Function at 00412b3d (Size: 712 bytes) */
int32_t FUN_00412b3d(int max_val,int point,int hBitmap);;

/* Function at 00412e05 (Size: 823 bytes) */
int32_t FUN_00412e05(int max_val,int point,int hBitmap);;

/* Function at 0041313c (Size: 301 bytes) */
int32_t FUN_0041313c(int max_val,int point,int hBitmap);;

/* Function at 00413269 (Size: 258 bytes) */
int32_t FUN_00413269(int max_val,int point,int hBitmap);;

/* Function at 0041336b (Size: 1084 bytes) */
int32_t CardScript_EbonyHorse(int spell_id,int target_id,int flags);;

/* Function at 004137a7 (Size: 470 bytes) */
int32_t FUN_004137a7(int max_val,int point,int hBitmap);;

/* Function at 0041397d (Size: 1096 bytes) */
int32_t FUN_0041397d(int max_val,int point,int hBitmap);;

/* Function at 00413dc5 (Size: 429 bytes) */
int32_t FUN_00413dc5(int max_val,int point,int hBitmap);;

/* Function at 00413f72 (Size: 412 bytes) */
int32_t FUN_00413f72(int max_val,int point,int hBitmap);;

/* Function at 0041410e (Size: 1053 bytes) */
int32_t FUN_0041410e(int max_val,int point,int hBitmap);;

/* Function at 0041452b (Size: 1012 bytes) */
int32_t CardScript_JandorsSaddlebags(int spell_id,int target_id,int flags);;

/* Function at 0041491f (Size: 920 bytes) */
int32_t CardScript_JadeMonolith(int spell_id,int target_id,int flags);;

/* Function at 00414cbc (Size: 389 bytes) */
void FUN_00414cbc(int max_val,int point,int hBitmap);;

/* Function at 00414e41 (Size: 460 bytes) */
int32_t FUN_00414e41(int max_val,int point,int hBitmap);;

/* Function at 0041500d (Size: 74 bytes) */
int32_t FUN_0041500d(int max_val,int point,int hBitmap);;

/* Function at 00415057 (Size: 1012 bytes) */
int32_t CardScript_AmuletOfKroog(int spell_id,int target_id,int flags);;

/* Function at 00415450 (Size: 824 bytes) */
int32_t FUN_00415450(int max_val,int point,int hBitmap);;

/* Function at 00415788 (Size: 788 bytes) */
int32_t CardScript_GrapeshotCatapult(int spell_id,int target_id,int flags);;

/* Function at 00415a9c (Size: 608 bytes) */
int32_t FUN_00415a9c(int max_val,int point,int hBitmap);;

/* Function at 00415cfc (Size: 1948 bytes) */
int32_t CardScript_BronzeTablet(int spell_id,int target_id,int flags);;

/* Function at 0041649d (Size: 1261 bytes) */
int32_t FUN_0041649d(int max_val,int point,int hBitmap);;

/* Function at 0041698a (Size: 193 bytes) */
int32_t FUN_0041698a(int max_val,int point,int hBitmap);;

/* Function at 00416a4b (Size: 543 bytes) */
int32_t CardScript_AladdinsRing(int spell_id,int target_id,int flags);;

/* Function at 00416c6a (Size: 537 bytes) */
int32_t CardScript_RodOfRuin(int spell_id,int target_id,int flags);;

/* Function at 00416e83 (Size: 1157 bytes) */
int32_t Pic_Subsystem_00439408(int max_val,int point,int hBitmap);;

/* Function at 00417308 (Size: 404 bytes) */
int32_t FUN_00417308(int max_val,int point,int hBitmap);;

/* Function at 0041749c (Size: 1032 bytes) */
int FUN_0041749c(int max_val,int point,int hBitmap);;

/* Function at 004178a4 (Size: 38 bytes) */
void Mem_AllocOrFree_004178a4(int max_val,int point,int hBitmap);;

/* Function at 004178ca (Size: 38 bytes) */
void Mem_AllocOrFree_004178ca(int max_val,int point,int hBitmap);;

/* Function at 004178f0 (Size: 1108 bytes) */
int32_t FUN_004178f0(int x,int y,int width,int height);;

/* Function at 00417d49 (Size: 408 bytes) */
int32_t FUN_00417d49(int max_val,int point,int hBitmap);;

/* Function at 00417ee1 (Size: 1183 bytes) */
int32_t CardScript_FlyingCarpet(int spell_id,int target_id,int flags);;

/* Function at 00418380 (Size: 981 bytes) */
int32_t FUN_00418380(int max_val,int point,int hBitmap);;

/* Function at 00418755 (Size: 64 bytes) */
void FUN_00418755(int max_val,int point,uint32_t hBitmap);;

/* Function at 00418795 (Size: 92 bytes) */
uint32_t FUN_00418795(int player,int card_slot);;

/* Function at 004187f1 (Size: 1066 bytes) */
int32_t CardScript_HelmOfChatzuk(int spell_id,int target_id,int flags);;

/* Function at 00418c1b (Size: 1094 bytes) */
int32_t CardScript_CoralHelm(int spell_id,int target_id,int flags);;

/* Function at 00419061 (Size: 607 bytes) */
int32_t FUN_00419061(int max_val,int point,int hBitmap);;

/* Function at 004192c0 (Size: 1055 bytes) */
int32_t CardScript_TawnosWand(int spell_id,int target_id,int flags);;

/* Function at 004196df (Size: 349 bytes) */
int32_t Card_Setup_0046695e(int max_val,int point,int hBitmap);;

/* Function at 0041983c (Size: 618 bytes) */
int32_t FUN_0041983c(int max_val,int point,int hBitmap);;

/* Function at 00419aab (Size: 563 bytes) */
int32_t Palette_Subsystem_004a9137(int max_val,int point,int hBitmap);;

/* Function at 00419cde (Size: 320 bytes) */
int32_t FUN_00419cde(int max_val,int point,int hBitmap);;

/* Function at 00419e1e (Size: 718 bytes) */
int32_t Player_Init_0046709c(int spell_id,int target_id,int flags);;

/* Function at 0041a0ec (Size: 255 bytes) */
int32_t FUN_0041a0ec(int max_val,int point,int hBitmap);;

/* Function at 0041a1eb (Size: 288 bytes) */
int32_t FUN_0041a1eb(int max_val,int point,int hBitmap);;

/* Function at 0041a30b (Size: 546 bytes) */
int32_t FUN_0041a30b(void);;

/* Function at 0041a52d (Size: 203 bytes) */
int32_t FUN_0041a52d(int max_val,int point,int hBitmap);;

/* Function at 0041a600 (Size: 152 bytes) */
bool UI_RegisterClass_0041a600(LPCSTR str_1);;

/* Function at 0041a698 (Size: 46 bytes) */
void FUN_0041a698(void);;

/* Function at 0041a6c6 (Size: 4921 bytes) */
LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint32_t uMsg,int *wParam,int *lParam);;

/* Function at 0041bcf0 (Size: 955 bytes) */
int32_t UI_SelectTargetCardDialog(int *max_val,int point,int hBitmap,uint32_t flags,uint32_t damage,uint32_t arg_6,uint32_t arg_7,uint32_t arg_8,uint32_t arg_9,uint32_t arg_10,uint32_t arg_11,uint32_t arg_12,int arg_13,int arg_14,uint32_t arg_15,uint32_t arg_16,uint32_t arg_17,uint32_t arg_18,uint32_t arg_19);;

/* Function at 0041c0ab (Size: 7256 bytes) */
uint32_t Rules_ParseFilter_0041c0ab(int card_id,int color_mask,uint8_t *hBitmap,int flags,uint8_t damage,uint8_t arg_6,uint32_t arg_7,uint32_t arg_8,uint32_t arg_9,uint32_t arg_10,uint32_t arg_11,uint32_t arg_12,uint32_t arg_13,int arg_14,int arg_15,uint32_t arg_16,uint32_t arg_17,uint32_t arg_18,uint32_t arg_19,uint32_t arg_20);;

/* Function at 0041dd17 (Size: 249 bytes) */
int FUN_0041dd17(int player,int card_slot);;

/* Function at 0041de10 (Size: 832 bytes) */
void Ai_Subsystem_004bc029(uint32_t spell_id,int32_t target_id,int flags);;

/* Function at 0041e2a2 (Size: 1736 bytes) */
int Action_ValidateTarget_0041e2a2(int spell_id,uint32_t target_id,uint32_t flags,uint32_t flags,uint32_t damage,uint32_t arg_6,uint32_t arg_7,uint32_t arg_8,uint32_t arg_9,uint32_t arg_10,int arg_11,int arg_12,uint32_t arg_13,uint32_t arg_14,uint32_t arg_15,uint32_t arg_16,uint32_t arg_17,uint8_t *arg_18,int32_t arg_19,int *arg_20);;

/* Function at 0041e97e (Size: 184 bytes) */
int32_t FUN_0041e97e(int player,int card_slot);;

/* Function at 0041ea36 (Size: 324 bytes) */
int32_t FUN_0041ea36(int player,int card_slot);;

/* Function at 0041eb80 (Size: 2793 bytes) */
int32_t Palette_Color_0049ae00(void);;

/* Function at 0041f669 (Size: 2066 bytes) */
void Palette_Color_0049ae00(void);;

/* Function at 0041fe7b (Size: 677 bytes) */
void FUN_0041fe7b(void);;

/* Function at 00420120 (Size: 793 bytes) */
int32_t Palette_Subsystem_0049c3ac(int *max_val);;

/* Function at 0042043e (Size: 252 bytes) */
void FUN_0042043e(HDC hdc,RECT *card_slot);;

/* Function at 0042053a (Size: 4227 bytes) */
int32_t Palette_Subsystem_0049c7c7(HDC hdc,int *point,int32_t *hBitmap,int flags,uint32_t damage,int arg_6);;

/* Function at 004215c2 (Size: 576 bytes) */
int32_t FUN_004215c2(HDC hdc,int *point,int hBitmap,int flags,int damage,uint32_t arg_6,int arg_7);;

/* Function at 00421802 (Size: 398 bytes) */
void FUN_00421802(int max_val,int point,uint32_t hBitmap);;

/* Function at 00421990 (Size: 196 bytes) */
void FUN_00421990(HDC hdc,int point,char *str_3);;

/* Function at 00421a54 (Size: 213 bytes) */
int FUN_00421a54(HDC hdc,char *str_2);;

/* Function at 00421b29 (Size: 519 bytes) */
int FUN_00421b29(int *player,int card_slot);;

/* Function at 00421d30 (Size: 735 bytes) */
uint32_t Palette_Subsystem_0049dfb1(HDC hdc,int point,int hBitmap,LONG flags,char *str_5);;

/* Function at 0042200f (Size: 682 bytes) */
void FUN_0042200f(int max_val,char point,int hBitmap,int flags,int damage,int arg_6);;

/* Function at 004222b9 (Size: 129 bytes) */
int32_t FUN_004222b9(HDC hdc,int point,int hBitmap);;

/* Function at 0042233a (Size: 1600 bytes) */
uint32_t FUN_0042233a(HDC hdc,int *y,char *str_3,int height);;

/* Function at 0042297a (Size: 435 bytes) */
void FUN_0042297a(HDC hdc,RECT *point,int hBitmap,int flags);;

/* Function at 00422b2d (Size: 2852 bytes) */
void Palette_Subsystem_0049eda9(HDC hdc,int *point,int hBitmap,int flags,int damage);;

/* Function at 00423651 (Size: 662 bytes) */
void FUN_00423651(HDC hdc,int *point,int32_t *hBitmap,int flags,int damage);;

/* Function at 004238e7 (Size: 900 bytes) */
void Palette_Subsystem_0049c7c7(HDC hdc,RECT *point,int hBitmap);;

/* Function at 00423c6b (Size: 490 bytes) */
void FUN_00423c6b(HDC hdc,int *y,uint32_t width,uint32_t height);;

/* Function at 00423e55 (Size: 360 bytes) */
void FUN_00423e55(HDC hdc,int *point,int32_t hBitmap);;

/* Function at 00423fbd (Size: 343 bytes) */
int32_t FUN_00423fbd(HDC hdc,int point,int32_t hBitmap);;

/* Function at 00424114 (Size: 212 bytes) */
void FUN_00424114(LPRECT player,int *card_slot);;

/* Function at 004241e8 (Size: 547 bytes) */
void FUN_004241e8(HDC hdc,int *point,int hBitmap,int flags,int damage);;

/* Function at 0042440b (Size: 385 bytes) */
int32_t FUN_0042440b(int x,int y,int width,int height);;

/* Function at 0042458c (Size: 446 bytes) */
void FUN_0042458c(LPRECT max_val,int *point,int hBitmap);;

/* Function at 0042474a (Size: 823 bytes) */
int32_t FUN_0042474a(int max_val,int *point,int hBitmap,int flags,int damage);;

/* Function at 00424a81 (Size: 663 bytes) */
void FUN_00424a81(HDC hdc,int32_t *point,uint32_t hBitmap);;

/* Function at 00424d18 (Size: 611 bytes) */
void FUN_00424d18(LPRECT max_val,uint32_t y,int *width,uint32_t height);;

/* Function at 00424f7b (Size: 445 bytes) */
void FUN_00424f7b(HDC hdc,int *point,int hBitmap,int flags,int damage);;

/* Function at 00425138 (Size: 424 bytes) */
void FUN_00425138(HDC hdc,int *point,int hBitmap,int32_t flags,int damage);;

/* Function at 004252e0 (Size: 1533 bytes) */
void Palette_Subsystem_0049eda9(HDC hdc,int *point,int hBitmap,int flags,int damage);;

/* Function at 004258dd (Size: 682 bytes) */
void Palette_Subsystem_004a155f(HDC hdc,RECT *point,int hBitmap,int flags,int damage,int arg_6,int arg_7);;

/* Function at 00425b87 (Size: 1530 bytes) */
void Palette_Subsystem_004a155f(HDC hdc,int *y,int width,int flags);;

/* Function at 00426181 (Size: 760 bytes) */
void FUN_00426181(HDC hdc,int *y,int width,int height);;

/* Function at 00426479 (Size: 135 bytes) */
void FUN_00426479(int32_t player,int32_t card_slot);;

/* Function at 00426500 (Size: 135 bytes) */
void FUN_00426500(int32_t player,int32_t card_slot);;

/* Function at 00426587 (Size: 153 bytes) */
void FUN_00426587(HDC hdc,int *card_slot);;

/* Function at 00426620 (Size: 294 bytes) */
uint32_t FUN_00426620(HDC hdc,int *y,int width,int height);;

/* Function at 00426746 (Size: 150 bytes) */
void FUN_00426746(HDC hdc,int *point,int hBitmap);;

/* Function at 004267dc (Size: 72 bytes) */
void FUN_004267dc(int32_t max_val,int *point,uint8_t hBitmap);;

/* Function at 00426824 (Size: 221 bytes) */
void FUN_00426824(LPRECT player,int *card_slot);;

/* Function at 00426901 (Size: 592 bytes) */
int32_t FUN_00426901(int max_val);;

/* Function at 00426b51 (Size: 267 bytes) */
void FUN_00426b51(char *str_1,char *str_2,int hBitmap);;

/* Function at 00426c5c (Size: 11 bytes) */
void Mem_AllocOrFree_00426c5c(void);;

/* Function at 00426c70 (Size: 15615 bytes) */
void FUN_00426c70(int max_val);;

/* Function at 0042a99c (Size: 172 bytes) */
int32_t FUN_0042a99c(void);;

/* Function at 0042aa48 (Size: 287 bytes) */
bool FUN_0042aa48(int max_val);;

/* Function at 0042ab67 (Size: 104 bytes) */
int32_t FUN_0042ab67(int max_val);;

/* Function at 0042abcf (Size: 386 bytes) */
void FUN_0042abcf(int max_val);;

/* Function at 0042ad51 (Size: 207 bytes) */
void FUN_0042ad51(int max_val);;

/* Function at 0042ae2a (Size: 433 bytes) */
void FUN_0042ae2a(void);;

/* Function at 0042afdb (Size: 220 bytes) */
int32_t FUN_0042afdb(void);;

/* Function at 0042b0b7 (Size: 105 bytes) */
int32_t FUN_0042b0b7(int x,int y,int width,int height);;

/* Function at 0042b120 (Size: 238 bytes) */
int32_t FUN_0042b120(int player,int card_slot);;

/* Function at 0042b213 (Size: 139 bytes) */
int32_t FUN_0042b213(int player,int card_slot);;

/* Function at 0042b2a0 (Size: 132 bytes) */
bool UI_RegisterClass_0042b2a0(LPCSTR str_1);;

/* Function at 0042b324 (Size: 878 bytes) */
LRESULT UI_WndProc_0042b324(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 0042b6b0 (Size: 4254 bytes) */
int Ai_CalcManaRequirement_004ba890(int max_val,int point,int hBitmap);;

/* Function at 0042c815 (Size: 425 bytes) */
void FUN_0042c815(int x,int point,int *hBitmap,int height);;

/* Function at 0042c9be (Size: 509 bytes) */
void FUN_0042c9be(int max_val,int point,int *hBitmap,int flags,int *damage,int arg_6);;

/* Function at 0042cbbb (Size: 507 bytes) */
void FUN_0042cbbb(int max_val,int point,int *hBitmap,int flags,int *damage,int arg_6);;

/* Function at 0042cdb6 (Size: 155 bytes) */
int32_t FUN_0042cdb6(int max_val,int point,int hBitmap);;

/* Function at 0042ce51 (Size: 1014 bytes) */
int32_t Ai_Subsystem_004bc029(int32_t spell_id,int *target_id,int flags,int height);;

/* Function at 0042d247 (Size: 2317 bytes) */
int32_t FUN_0042d247(int max_val,int32_t point,int32_t hBitmap,int32_t flags,int damage);;

/* Function at 0042db54 (Size: 522 bytes) */
int32_t FUN_0042db54(int max_val,int point,uint8_t hBitmap);;

/* Function at 0042dd5e (Size: 426 bytes) */
int32_t FUN_0042dd5e(int player,int card_slot);;

/* Function at 0042df08 (Size: 112 bytes) */
void FUN_0042df08(int max_val,int point,int hBitmap,int *flags,int32_t damage,int arg_6,int arg_7,int arg_8,int *arg_9);;

/* Function at 0042df78 (Size: 151 bytes) */
int FUN_0042df78(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int arg_7);;

/* Function at 0042e00f (Size: 109 bytes) */
int32_t FUN_0042e00f(void);;

/* Function at 0042e081 (Size: 71 bytes) */
bool FUN_0042e081(int player,int card_slot);;

/* Function at 0042e0cd (Size: 47 bytes) */
bool Mem_AllocOrFree_0042e0cd(void);;

/* Function at 0042e101 (Size: 154 bytes) */
int32_t FUN_0042e101(int max_val);;

/* Function at 0042e1a0 (Size: 114 bytes) */
int32_t FUN_0042e1a0(int max_val);;

/* Function at 0042e217 (Size: 2683 bytes) */
int32_t Ai_Subsystem_004bd6f9(int max_val,uint32_t point,int hBitmap);;

/* Function at 0042ecaf (Size: 169 bytes) */
int FUN_0042ecaf(int x,int y,int width,int height);;

/* Function at 0042ed60 (Size: 3718 bytes) */
uint32_t FUN_0042ed60(int max_val);;

/* Function at 0042fbf0 (Size: 697 bytes) */
void Ai_SaveGameState(void);;

/* Function at 0042fea9 (Size: 631 bytes) */
void FUN_0042fea9(void);;

/* Function at 00430120 (Size: 583 bytes) */
void FUN_00430120(void);;

/* Function at 00430367 (Size: 583 bytes) */
void FUN_00430367(void);;

/* Function at 004305ae (Size: 37 bytes) */
void Mem_AllocOrFree_004305ae(void);;

/* Function at 004305d3 (Size: 119 bytes) */
void FUN_004305d3(void);;

/* Function at 0043064a (Size: 211 bytes) */
void FUN_0043064a(void);;

/* Function at 0043071d (Size: 75 bytes) */
int32_t Card_DispatchRulesEvent(int max_val);;

/* Function at 00430768 (Size: 74 bytes) */
int32_t FUN_00430768(int max_val);;

/* Function at 004307b2 (Size: 108 bytes) */
void FUN_004307b2(void);;

/* Function at 0043081e (Size: 177 bytes) */
void FUN_0043081e(void);;

/* Function at 004308cf (Size: 21 bytes) */
int32_t Mem_AllocOrFree_004308cf(void);;

/* Function at 004308e4 (Size: 45 bytes) */
void Mem_AllocOrFree_004308e4(void);;

/* Function at 00430911 (Size: 2728 bytes) */
int FUN_00430911(int max_val);;

/* Function at 004313b9 (Size: 2380 bytes) */
int FUN_004313b9(int player,int card_slot);;

/* Function at 00431d05 (Size: 572 bytes) */
int32_t Ai_ChooseBlockers(int player,int card_slot);;

/* Function at 00431f41 (Size: 155 bytes) */
void FUN_00431f41(uint32_t *player,uint32_t *card_slot);;

/* Function at 00431fe0 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_00431fe0(void);;

/* Function at 004327e0 (Size: 66 bytes) */
int32_t FUN_004327e0(void);;

/* Function at 00432822 (Size: 54 bytes) */
int32_t FUN_00432822(void);;

/* Function at 00432860 (Size: 80 bytes) */
int FUN_00432860(int max_val);;

/* Function at 004328ba (Size: 329 bytes) */
int FUN_004328ba(int max_val);;

/* Function at 00432a0b (Size: 178 bytes) */
uint32_t FUN_00432a0b(char *str_1,int card_slot);;

/* Function at 00432ac7 (Size: 286 bytes) */
void FUN_00432ac7(int max_val);;

/* Function at 00432be5 (Size: 69 bytes) */
int32_t FUN_00432be5(char *max_val);;

/* Function at 00432c2a (Size: 67 bytes) */
bool FUN_00432c2a(int max_val,void *point,uint32_t hBitmap);;

/* Function at 00432c72 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_00432c72(void);;

/* Function at 00432c87 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00432c87(void);;

/* Function at 00432c99 (Size: 226 bytes) */
int32_t FUN_00432c99(char *str_1);;

/* Function at 00432d7b (Size: 137 bytes) */
int32_t FUN_00432d7b(char *str_1);;

/* Function at 00432e04 (Size: 3506 bytes) */
uint32_t FUN_00432e04(void);;

/* Function at 00433bb6 (Size: 131 bytes) */
uint32_t FileIo_ReadDataBlock(void *player, uint32_t card_slot);;

/* Function at 00433c39 (Size: 77 bytes) */
int FUN_00433c39(char *str_1);;

/* Function at 00433c86 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00433c86(void);;

/* Function at 00433c98 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00433c98(void);;

/* Function at 00433caa (Size: 155 bytes) */
void FUN_00433caa(char *str_1);;

/* Function at 00433d45 (Size: 237 bytes) */
uint32_t FUN_00433d45(char *str_1);;

/* Function at 00433e40 (Size: 146 bytes) */
bool UI_RegisterClass_00433e40(LPCSTR str_1);;

/* Function at 00433ed2 (Size: 516 bytes) */
LRESULT UI_WndProc_00433ed2(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam);;

/* Function at 004340f0 (Size: 586 bytes) */
int Catalog_Open(char *str_1);;

/* Function at 0043433a (Size: 188 bytes) */
bool FUN_0043433a(int max_val);;

/* Function at 004343f6 (Size: 70 bytes) */
int32_t FUN_004343f6(int *player,int *card_slot);;

/* Function at 00434446 (Size: 123 bytes) */
void * FUN_00434446(int player,uint8_t *card_slot);;

/* Function at 004344c1 (Size: 169 bytes) */
size_t FUN_004344c1(int max_val,int32_t point,int *hBitmap);;

/* Function at 0043456a (Size: 234 bytes) */
uint32_t FUN_0043456a(uint8_t *max_val);;

/* Function at 00434660 (Size: 589 bytes) */
int Catalog_ParseCsvLine(uint32_t *player, uint32_t *card_slot);;

/* Function at 004348b2 (Size: 340 bytes) */
uint32_t FUN_004348b2(int32_t player,int32_t card_slot);;

/* Function at 00434a10 (Size: 51 bytes) */
void * FUN_00434a10(void);;

/* Function at 00434a43 (Size: 596 bytes) */
int16_t * Catalog_LoadPaletteMap(char *str_1,char *str_2);;

/* Function at 00434c97 (Size: 114 bytes) */
int32_t FUN_00434c97(void);;

/* Function at 00434d09 (Size: 127 bytes) */
void FUN_00434d09(int *max_val,int point,int *hBitmap);;

/* Function at 00434d88 (Size: 319 bytes) */
int FUN_00434d88(int *max_val);;

/* Function at 00434ec7 (Size: 218 bytes) */
int32_t FUN_00434ec7(int32_t *max_val,char *str_2,int32_t hBitmap);;

/* Function at 00434fa1 (Size: 172 bytes) */
int FUN_00434fa1(int *max_val);;

/* Function at 0043504d (Size: 100 bytes) */
void FUN_0043504d(uint32_t player,uint32_t *card_slot);;

/* Function at 004350b1 (Size: 260 bytes) */
int32_t FUN_004350b1(void);;

/* Function at 004351b5 (Size: 393 bytes) */
int32_t FUN_004351b5(uint32_t max_val);;

/* Function at 00435343 (Size: 371 bytes) */
uint32_t FUN_00435343(uint32_t max_val);;

/* Function at 004354bb (Size: 150 bytes) */
int FUN_004354bb(int *player,int *card_slot);;

/* Function at 00435551 (Size: 152 bytes) */
int32_t FUN_00435551(uint32_t *x,int y,int width,int height);;

/* Function at 004355e9 (Size: 230 bytes) */
int32_t FUN_004355e9(uint32_t *x,int y,int width,int height);;

/* Function at 004356cf (Size: 1440 bytes) */
int FUN_004356cf(int max_val,int point,uint32_t *hBitmap,int flags,int damage,int arg_6);;

/* Function at 00435c74 (Size: 65 bytes) */
void FUN_00435c74(int32_t *player,int card_slot);;

/* Function at 00435cb5 (Size: 441 bytes) */
int32_t Palette_AllocErrorDiffusionTable(int player,int card_slot);;

/* Function at 00435e6e (Size: 1061 bytes) */
int32_t FUN_00435e6e(int max_val,uint8_t *point,int hBitmap,int flags,int damage);;

/* Function at 00436293 (Size: 1345 bytes) */
int32_t FUN_00436293(int max_val,int point,int hBitmap,int flags,int damage,int arg_6);;

/* Function at 004367d4 (Size: 35 bytes) */
void Mem_AllocOrFree_004367d4(void);;

/* Function at 00436800 (Size: 24 bytes) */
uint32_t Mem_AllocOrFree_00436800(uint32_t max_val);;

/* Function at 00436820 (Size: 562 bytes) */
int32_t UI_Register_FACE_BLACK_00436820(LPCSTR str_1);;

/* Function at 00436a52 (Size: 164 bytes) */
void FUN_00436a52(void);;

/* Function at 00436af6 (Size: 1760 bytes) */
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam);;

/* Function at 004371ec (Size: 846 bytes) */
void FUN_004371ec(HDC hdc,RECT *point,int hBitmap);;

/* Function at 0043753a (Size: 327 bytes) */
void FUN_0043753a(int player,int card_slot);;

/* Function at 00437681 (Size: 63 bytes) */
void FUN_00437681(int32_t max_val);;

/* Function at 004376c0 (Size: 74 bytes) */
int32_t FUN_004376c0(int max_val);;

/* Function at 00437710 (Size: 1013 bytes) */
int32_t Palette_Color_00495430(char *str_1);;

/* Function at 00437b05 (Size: 135 bytes) */
void FUN_00437b05(void);;

/* Function at 00437b8c (Size: 167 bytes) */
int Palette_Subsystem_004958b1(int max_val);;

/* Function at 00437c33 (Size: 901 bytes) */
int32_t Palette_Subsystem_00495958(uint8_t *max_val);;

/* Function at 00437fb8 (Size: 526 bytes) */
void FUN_00437fb8(MSG *max_val);;

/* Function at 004381c6 (Size: 408 bytes) */
int32_t FUN_004381c6(int *player,UINT card_slot);;

/* Function at 00438368 (Size: 418 bytes) */
int32_t Palette_Subsystem_0049608e(void);;

/* Function at 0043850a (Size: 258 bytes) */
void Palette_Subsystem_0049608e(void);;

/* Function at 0043860c (Size: 37 bytes) */
int32_t Mem_AllocOrFree_0043860c(void);;

/* Function at 00438636 (Size: 134 bytes) */
int32_t FUN_00438636(HWND max_val,uint32_t y,HWND hBitmap,int32_t flags);;

/* Function at 004386c1 (Size: 176 bytes) */
int32_t Palette_Subsystem_004963e7(void);;

/* Function at 00438771 (Size: 487 bytes) */
LRESULT Palette_Subsystem_00496497(HWND hwnd,uint32_t y,WPARAM hBitmap,uint32_t height);;

/* Function at 00438980 (Size: 619 bytes) */
int FUN_00438980(WPARAM max_val,int point,int width,int height);;

/* Function at 00438bf0 (Size: 130 bytes) */
int32_t FUN_00438bf0(int player,int card_slot);;

/* Function at 00438c81 (Size: 221 bytes) */
int FUN_00438c81(HDC hdc,RECT *point,int width,int flags);;

/* Function at 00438d5e (Size: 271 bytes) */
int32_t FUN_00438d5e(WPARAM max_val,int point,int width,int height);;

/* Function at 00438e72 (Size: 80 bytes) */
void FUN_00438e72(int max_val);;

/* Function at 00438ec2 (Size: 683 bytes) */
int FUN_00438ec2(WPARAM max_val,int y,int width,int height);;

/* Function at 00439172 (Size: 150 bytes) */
uint8_t * FUN_00439172(int player,int card_slot);;

/* Function at 00439208 (Size: 235 bytes) */
int FUN_00439208(HDC hdc,RECT *point,int width,int height);;

/* Function at 004392f3 (Size: 165 bytes) */
int32_t FUN_004392f3(WPARAM max_val,int y,int width,int height);;

/* Function at 004393a2 (Size: 372 bytes) */
void FUN_004393a2(int player,int card_slot);;

/* Function at 00439516 (Size: 79 bytes) */
void FUN_00439516(void);;

/* Function at 00439570 (Size: 102 bytes) */
void FUN_00439570(int max_val);;

/* Function at 004395d6 (Size: 131 bytes) */
void FUN_004395d6(int player,int card_slot);;

/* Function at 00439659 (Size: 145 bytes) */
void FUN_00439659(char *max_val,int y,uint32_t hBitmap,int flags);;

/* Function at 004396ea (Size: 324 bytes) */
int FUN_004396ea(int max_val);;

/* Function at 0043982e (Size: 53 bytes) */
void FUN_0043982e(void);;

/* Function at 00439863 (Size: 47 bytes) */
void Mem_AllocOrFree_00439863(void);;

/* Function at 00439892 (Size: 44 bytes) */
int Duel_RandomRange(int max_val);;

/* Function at 004398be (Size: 64 bytes) */
void FUN_004398be(void);;

/* Function at 004398fe (Size: 21 bytes) */
void Mem_AllocOrFree_004398fe(void);;

/* Function at 00439913 (Size: 101 bytes) */
uint32_t FUN_00439913(uint32_t max_val);;

/* Function at 00439980 (Size: 246 bytes) */
int32_t UI_DeckDialogProc_00439980(uint32_t *max_val,uint32_t *point,int32_t *hBitmap);;

/* Function at 00439a76 (Size: 1556 bytes) */
HGDIOBJ Palette_Subsystem_00496497(HWND hwnd,uint32_t y,HDC hdc,HWND param_4);;

/* Function at 0043a094 (Size: 775 bytes) */
int32_t FUN_0043a094(int max_val);;

/* Function at 0043a3a0 (Size: 401 bytes) */
bool UI_RegisterExpandedGraveyardClass(LPCSTR str_1);;

/* Function at 0043a531 (Size: 46 bytes) */
void FUN_0043a531(void);;

/* Function at 0043a55f (Size: 2639 bytes) */
LRESULT UI_GraveyardMenuProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam);;

/* Function at 0043b02a (Size: 366 bytes) */
LRESULT UI_WndProc_0043b02a(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 0043b1a4 (Size: 705 bytes) */
LRESULT UI_WndProc_0043b1a4(HWND hwnd,uint32_t uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 0043b471 (Size: 970 bytes) */
HWND UI_RegisterExpandedGraveyardClass(HWND hwnd,int card_slot);;

/* Function at 0043b83b (Size: 21 bytes) */
void FUN_0043b83b(HWND hwnd);;

/* Function at 0043b850 (Size: 83 bytes) */
int32_t FUN_0043b850(int max_val);;

/* Function at 0043b8a8 (Size: 41 bytes) */
void Mem_AllocOrFree_0043b8a8(void);;

/* Function at 0043b8d1 (Size: 2562 bytes) */
HGDIOBJ UI_AnteDisplayWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 0043c2dd (Size: 496 bytes) */
void FUN_0043c2dd(LPRECT max_val,HWND hwnd,int width,int height);;

/* Function at 0043c4d0 (Size: 2423 bytes) */
size_t Ai_CalcManaRequirement_004b9284(char *str_1);;

/* Function at 0043ce47 (Size: 48 bytes) */
void Mem_AllocOrFree_0043ce47(void);;

/* Function at 0043ce77 (Size: 594 bytes) */
int32_t FUN_0043ce77(LPCSTR str_1);;

/* Function at 0043d0c9 (Size: 48 bytes) */
void Mem_AllocOrFree_0043d0c9(void);;

/* Function at 0043d0f9 (Size: 202 bytes) */
char * FUN_0043d0f9(int32_t *max_val);;

/* Function at 0043d1d0 (Size: 559 bytes) */
uint8_t * FUN_0043d1d0(int max_val,int point,int hBitmap);;

/* Function at 0043d3ff (Size: 788 bytes) */
int32_t Pic_LoadImageFile(int max_val,int32_t point,int32_t hBitmap,char *str_4,uint8_t *damage);;

/* Function at 0043d713 (Size: 134 bytes) */
int Pic_LoadKimPicture(char *str_1);;

/* Function at 0043d799 (Size: 51 bytes) */
int FUN_0043d799(char *str_1,int card_slot);;

/* Function at 0043d7cc (Size: 42 bytes) */
void FUN_0043d7cc(int max_val);;

/* Function at 0043d7f6 (Size: 39 bytes) */
void Mem_AllocOrFree_0043d7f6(int32_t max_val);;

/* Function at 0043d81d (Size: 59 bytes) */
int FUN_0043d81d(void);;

/* Function at 0043d858 (Size: 11 bytes) */
void Mem_AllocOrFree_0043d858(void);;

/* Function at 0043d863 (Size: 11 bytes) */
void Mem_AllocOrFree_0043d863(void);;

/* Function at 0043d870 (Size: 351 bytes) */
int Sound_Init(int hInst,int32_t hWnd,uint32_t flags);;

/* Function at 0043d9cf (Size: 118 bytes) */
void CloseSnd(void);;

/* Function at 0043da45 (Size: 60 bytes) */
int32_t InitSndTrack(int32_t max_val,int32_t point,int32_t hBitmap);;

/* Function at 0043da81 (Size: 52 bytes) */
int32_t CloseSndTrack(int32_t max_val);;

/* Function at 0043dab5 (Size: 45 bytes) */
int32_t StopSndTrack(void);;

/* Function at 0043dae2 (Size: 69 bytes) */
int32_t PlaySnd(int32_t sound_id,int32_t flags);;

/* Function at 0043db27 (Size: 73 bytes) */
int32_t PlaySndFile(int32_t filename,int32_t loop_flag,int32_t out_handle);;

/* Function at 0043db70 (Size: 65 bytes) */
int32_t StopSnd(int32_t sound_id);;

/* Function at 0043dbb1 (Size: 48 bytes) */
void PauseSnd(void);;

/* Function at 0043dbe1 (Size: 69 bytes) */
int32_t ResumeSnd(int32_t player,int32_t card_slot);;

/* Function at 0043dc26 (Size: 69 bytes) */
int32_t SetPitch(int32_t value,int32_t card_slot);;

/* Function at 0043dc6b (Size: 69 bytes) */
int32_t GetPitch(int32_t player,int32_t card_slot);;

/* Function at 0043dcb0 (Size: 69 bytes) */
int32_t SetVol(int32_t value,int32_t card_slot);;

/* Function at 0043dcf5 (Size: 69 bytes) */
int32_t GetVol(int32_t player,int32_t card_slot);;

/* Function at 0043dd3a (Size: 69 bytes) */
int32_t SetPan(int32_t value,int32_t card_slot);;

/* Function at 0043dd7f (Size: 69 bytes) */
int32_t GetPan(int32_t player,int32_t card_slot);;

/* Function at 0043ddc4 (Size: 58 bytes) */
int32_t UpdateSnd(void);;

/* Function at 0043ddfe (Size: 69 bytes) */
int32_t SetSndMarker(int32_t player,int32_t card_slot);;

/* Function at 0043de43 (Size: 69 bytes) */
int32_t PlaySndMarker(int32_t player,int32_t card_slot);;

/* Function at 0043de88 (Size: 65 bytes) */
int32_t GetSndTime(int32_t max_val);;

/* Function at 0043dec9 (Size: 69 bytes) */
int32_t ResetSnd(int32_t player,int32_t card_slot);;

/* Function at 0043df0e (Size: 69 bytes) */
int32_t GetSndState(int32_t player,int32_t card_slot);;

/* Function at 0043df53 (Size: 66 bytes) */
int32_t GetAVISndBuff(int32_t player,int32_t card_slot);;

/* Function at 0043df95 (Size: 69 bytes) */
int32_t ReleaseAVISndBuff(int32_t player,int32_t card_slot);;

/* Function at 0043dfda (Size: 55 bytes) */
int32_t GetSndHWND(void);;

/* Function at 0043e011 (Size: 66 bytes) */
int32_t IsSndLoaded(int32_t player,int32_t card_slot);;

/* Function at 0043e053 (Size: 73 bytes) */
int32_t GetLRUSnd(int32_t max_val,int32_t point,int32_t hBitmap);;

/* Function at 0043e09c (Size: 58 bytes) */
void FUN_0043e09c(void);;

/* Function at 0043e0e0 (Size: 538 bytes) */
int32_t Ai_AssignCombatDamage(int32_t *max_val,uint32_t *point,uint32_t hBitmap,int flags,uint32_t damage,uint32_t arg_6,int32_t arg_7,int arg_8,int32_t arg_9);;

/* Function at 0043e2fa (Size: 2163 bytes) */
HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 0043eb81 (Size: 179 bytes) */
void Ai_LoadStartDuel2Backdrop(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int32_t *flags,int32_t *damage,int32_t *arg_6);;

/* Function at 0043ec34 (Size: 77 bytes) */
void FUN_0043ec34(int max_val,int point,int hBitmap);;

/* Function at 0043ec81 (Size: 3683 bytes) */
HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 0043faee (Size: 224 bytes) */
void Ai_LoadStartDuelBackdrop(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int32_t *flags,int32_t *damage,int32_t *arg_6,int32_t *arg_7);;

/* Function at 0043fbce (Size: 99 bytes) */
void FUN_0043fbce(int x,int y,int width,int height);;

/* Function at 0043fc31 (Size: 298 bytes) */
void Ai_ScoreBoardPermanents(int max_val);;

/* Function at 0043fd5b (Size: 241 bytes) */
INT_PTR Ai_CalculateCombatOdds(int32_t max_val,int32_t point,int32_t hBitmap,int32_t flags,int32_t damage);;

/* Function at 0043fe4c (Size: 2918 bytes) */
HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004409b7 (Size: 229 bytes) */
void Ai_LoadEndDuelBackdrop(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int *flags,int *damage,int *arg_6,int32_t *arg_7,int32_t *arg_8);;

/* Function at 00440a9c (Size: 93 bytes) */
void FUN_00440a9c(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 00440af9 (Size: 293 bytes) */
int32_t FUN_00440af9(int player,int card_slot);;

/* Function at 00440c1e (Size: 737 bytes) */
LRESULT FUN_00440c1e(int32_t max_val,int point,int32_t hBitmap,int32_t flags,int32_t damage,int32_t arg_6,int32_t arg_7,int *arg_8,int32_t *arg_9,int32_t arg_10,int32_t arg_11);;

/* Function at 00440eff (Size: 35 bytes) */
void FUN_00440eff(void);;

/* Function at 00440f22 (Size: 445 bytes) */
INT_PTR Ai_EvaluateCreatureCast(int *max_val,int point,int hBitmap,int32_t flags,int damage,uint32_t *arg_6);;

/* Function at 004410df (Size: 4321 bytes) */
LRESULT Ai_EvaluateSpellCast(HWND hwnd,uint32_t y,HDC hdc,int32_t *flags);;

/* Function at 004421e2 (Size: 237 bytes) */
void FUN_004421e2(int *max_val,int *point,int *hBitmap,int *flags,int *damage,int32_t *arg_6);;

/* Function at 004422cf (Size: 111 bytes) */
void FUN_004422cf(HGDIOBJ max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags,HGDIOBJ damage);;

/* Function at 0044233e (Size: 1024 bytes) */
LRESULT UI_WndProc_0044233e(HWND hwnd,uint32_t uMsg,WPARAM wParam,LONG *lParam);;

/* Function at 0044274a (Size: 19 bytes) */
void Mem_AllocOrFree_0044274a(void);;

/* Function at 00442839 (Size: 137 bytes) */
void FUN_00442839(uint32_t max_val,int point,int hBitmap);;

/* Function at 004428c2 (Size: 16 bytes) */
void Mem_AllocOrFree_004428c2(void);;

/* Function at 004428d2 (Size: 452 bytes) */
INT_PTR FUN_004428d2(int max_val,int32_t point,INT_PTR hBitmap,char *str_4,char *str_5,char *str_6);;

/* Function at 00442a9b (Size: 924 bytes) */
HWND UI_DialogProc_00442a9b(HWND hwnd,uint32_t uMsg,uint32_t wParam,int32_t *lParam);;

/* Function at 00442e3c (Size: 87 bytes) */
INT_PTR FUN_00442e3c(int max_val,int32_t point,INT_PTR hBitmap);;

/* Function at 00442e98 (Size: 355 bytes) */
int32_t UI_DialogProc_00442e98(HWND hwnd,uint32_t uMsg,uint32_t wParam,int32_t *lParam);;

/* Function at 00443000 (Size: 94 bytes) */
INT_PTR FUN_00443000(int max_val,int32_t point,INT_PTR hBitmap);;

/* Function at 00443063 (Size: 1344 bytes) */
HGDIOBJ UI_DialogProc_00443063(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004435ad (Size: 148 bytes) */
LRESULT FUN_004435ad(HWND hwnd,UINT y,uint32_t width,LPARAM flags);;

/* Function at 0044364b (Size: 220 bytes) */
void Pic_Load_WinbkQuestn(int32_t *max_val,int32_t *out_buffer,int *hBitmap,int *flags,int *damage,int32_t *arg_6,int32_t *arg_7);;

/* Function at 00443727 (Size: 93 bytes) */
void FUN_00443727(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 00443784 (Size: 698 bytes) */
INT_PTR FUN_00443784(int max_val,int32_t point,int32_t hBitmap,int flags,uint32_t damage);;

/* Function at 00443a43 (Size: 3381 bytes) */
HGDIOBJ UI_DialogProc_004b257c(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004447aa (Size: 549 bytes) */
void Ai_CalcManaRequirement_004b32d1(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int32_t *flags,int32_t *damage,int *arg_6,int *arg_7,int *arg_8,int32_t *arg_9,int32_t *arg_10);;

/* Function at 004449cf (Size: 182 bytes) */
void FUN_004449cf(int max_val,int point,int hBitmap,HGDIOBJ flags,HGDIOBJ damage,HGDIOBJ arg_6);;

/* Function at 00444a85 (Size: 451 bytes) */
void FUN_00444a85(LPRECT max_val,HWND hwnd,int hBitmap);;

/* Function at 00444c48 (Size: 193 bytes) */
INT_PTR FUN_00444c48(int max_val,int32_t *point,int32_t hBitmap,int flags,uint32_t damage);;

/* Function at 00444d18 (Size: 2369 bytes) */
HBRUSH UI_DialogProc_004b3847(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 0044565e (Size: 220 bytes) */
void Pic_Load_WinbkChangetext(int32_t *max_val,int32_t *out_buffer,int *hBitmap,int *flags,int *damage,int32_t *arg_6,int32_t *arg_7);;

/* Function at 0044573a (Size: 93 bytes) */
void FUN_0044573a(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 00445797 (Size: 11 bytes) */
void Mem_AllocOrFree_00445797(void);;

/* Function at 004457a2 (Size: 1891 bytes) */
uint32_t FUN_004457a2(void);;

/* Function at 00445f05 (Size: 2404 bytes) */
void Ai_EvalAttackCandidate_004b4a3f(int32_t player,uint32_t card_slot);;

/* Function at 00446869 (Size: 37 bytes) */
void Mem_AllocOrFree_00446869(void);;

/* Function at 0044688e (Size: 39 bytes) */
int32_t FUN_0044688e(void);;

/* Function at 004468b5 (Size: 64 bytes) */
uint32_t FUN_004468b5(void);;

/* Function at 004468f5 (Size: 16 bytes) */
void Mem_AllocOrFree_004468f5(void);;

/* Function at 00446905 (Size: 16 bytes) */
void Mem_AllocOrFree_00446905(void);;

/* Function at 00446915 (Size: 180 bytes) */
int32_t Ai_Subsystem_004b544d(void);;

/* Function at 004469c9 (Size: 62 bytes) */
void FUN_004469c9(uint8_t *max_val);;

/* Function at 00446a07 (Size: 527 bytes) */
void FUN_00446a07(char *str_1);;

/* Function at 00446c16 (Size: 252 bytes) */
int FUN_00446c16(int max_val,int point,int hBitmap,int flags,int32_t damage,int32_t arg_6);;

/* Function at 00446d17 (Size: 139 bytes) */
int32_t FUN_00446d17(void);;

/* Function at 00446da2 (Size: 64 bytes) */
void FUN_00446da2(int max_val);;

/* Function at 00446de2 (Size: 78 bytes) */
int32_t FUN_00446de2(int player,int card_slot);;

/* Function at 00446e30 (Size: 114 bytes) */
uint32_t FUN_00446e30(int player,int card_slot);;

/* Function at 00446ea2 (Size: 109 bytes) */
int32_t FUN_00446ea2(int player,int card_slot);;

/* Function at 00446f0f (Size: 114 bytes) */
uint32_t FUN_00446f0f(int player,int card_slot);;

/* Function at 00446f81 (Size: 183 bytes) */
void FUN_00446f81(int max_val,int point,uint32_t *hBitmap,uint32_t *flags,uint32_t *damage);;

/* Function at 00447038 (Size: 110 bytes) */
int FUN_00447038(int player,int card_slot);;

/* Function at 004470a6 (Size: 110 bytes) */
int FUN_004470a6(int player,int card_slot);;

/* Function at 00447114 (Size: 112 bytes) */
int32_t FUN_00447114(int player,int card_slot);;

/* Function at 00447184 (Size: 110 bytes) */
int32_t Deck_ValidateCardLimit(int player, int card_slot);;

/* Function at 004471f7 (Size: 182 bytes) */
int32_t FUN_004471f7(int player,int card_slot);;

/* Function at 004472ad (Size: 400 bytes) */
uint8_t FUN_004472ad(int player,int card_slot);;

/* Function at 0044743d (Size: 175 bytes) */
void FUN_0044743d(int *max_val,int point,int hBitmap);;

/* Function at 004474ec (Size: 280 bytes) */
int32_t FUN_004474ec(int *max_val,int point,int hBitmap);;

/* Function at 00447604 (Size: 108 bytes) */
uint8_t FUN_00447604(int player,int card_slot);;

/* Function at 00447675 (Size: 110 bytes) */
int FUN_00447675(int player,int card_slot);;

/* Function at 004476e3 (Size: 110 bytes) */
int FUN_004476e3(int player,int card_slot);;

/* Function at 00447751 (Size: 206 bytes) */
uint32_t FUN_00447751(int player,int card_slot);;

/* Function at 0044781f (Size: 110 bytes) */
int FUN_0044781f(int player,int card_slot);;

/* Function at 0044788d (Size: 110 bytes) */
int FUN_0044788d(int player,int card_slot);;

/* Function at 004478fb (Size: 109 bytes) */
int32_t FUN_004478fb(int player,int card_slot);;

/* Function at 00447968 (Size: 109 bytes) */
int32_t FUN_00447968(int player,int card_slot);;

/* Function at 004479d5 (Size: 161 bytes) */
void FUN_004479d5(int x,int y,int *width,int *height);;

/* Function at 00447a76 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00447a76(void);;

/* Function at 00447a88 (Size: 100 bytes) */
uint32_t FUN_00447a88(int player,int card_slot);;

/* Function at 00447aec (Size: 115 bytes) */
uint32_t FUN_00447aec(int player,int card_slot);;

/* Function at 00447b5f (Size: 168 bytes) */
bool FUN_00447b5f(int player,int card_slot);;

/* Function at 00447c07 (Size: 109 bytes) */
int32_t FUN_00447c07(int player,int card_slot);;

/* Function at 00447c74 (Size: 132 bytes) */
bool FUN_00447c74(int player,int card_slot);;

/* Function at 00447cf8 (Size: 132 bytes) */
bool FUN_00447cf8(int player,int card_slot);;

/* Function at 00447d7c (Size: 263 bytes) */
void FUN_00447d7c(int max_val,int point,char *hBitmap);;

/* Function at 00447e83 (Size: 494 bytes) */
void Ai_Subsystem_004b69ba(int max_val,int point,char *hBitmap);;

/* Function at 00448071 (Size: 179 bytes) */
int FUN_00448071(int max_val,int point,void *hBitmap);;

/* Function at 00448124 (Size: 109 bytes) */
int32_t FUN_00448124(int player,int card_slot);;

/* Function at 00448191 (Size: 109 bytes) */
int32_t FUN_00448191(int player,int card_slot);;

/* Function at 004481fe (Size: 112 bytes) */
int32_t FUN_004481fe(int player,int card_slot);;

/* Function at 0044826e (Size: 150 bytes) */
void FUN_0044826e(int32_t *max_val,int point,int hBitmap);;

/* Function at 00448304 (Size: 112 bytes) */
int32_t FUN_00448304(int player,int card_slot);;

/* Function at 00448374 (Size: 110 bytes) */
int FUN_00448374(int player,int card_slot);;

/* Function at 004483e2 (Size: 48 bytes) */
int32_t Mem_AllocOrFree_004483e2(int max_val);;

/* Function at 00448412 (Size: 93 bytes) */
void FUN_00448412(char *str_1);;

/* Function at 0044846f (Size: 102 bytes) */
int32_t FUN_0044846f(int max_val);;

/* Function at 004484d5 (Size: 102 bytes) */
int32_t FUN_004484d5(int max_val);;

/* Function at 0044853b (Size: 140 bytes) */
int32_t FUN_0044853b(void *player,int card_slot);;

/* Function at 004485c7 (Size: 140 bytes) */
int32_t FUN_004485c7(void *max_val,int point,int hBitmap);;

/* Function at 00448653 (Size: 163 bytes) */
int32_t FUN_00448653(void *player,int card_slot);;

/* Function at 004486f6 (Size: 163 bytes) */
int32_t FUN_004486f6(void *player,int card_slot);;

/* Function at 00448799 (Size: 163 bytes) */
int32_t FUN_00448799(void *player,int card_slot);;

/* Function at 0044883c (Size: 91 bytes) */
int32_t FUN_0044883c(void *max_val);;

/* Function at 00448897 (Size: 227 bytes) */
void FUN_00448897(int x,int *y,int width,int *height);;

/* Function at 0044897a (Size: 73 bytes) */
void FUN_0044897a(int32_t *player,int32_t *card_slot);;

/* Function at 004489c3 (Size: 117 bytes) */
void FUN_004489c3(void *player,int card_slot);;

/* Function at 00448a38 (Size: 53 bytes) */
void FUN_00448a38(int32_t *max_val);;

/* Function at 00448a6d (Size: 52 bytes) */
int32_t FUN_00448a6d(void);;

/* Function at 00448aa1 (Size: 81 bytes) */
bool FUN_00448aa1(int32_t *max_val);;

/* Function at 00448af2 (Size: 52 bytes) */
int32_t FUN_00448af2(void);;

/* Function at 00448b26 (Size: 73 bytes) */
void FUN_00448b26(int32_t *player,int32_t *card_slot);;

/* Function at 00448b6f (Size: 423 bytes) */
int FUN_00448b6f(void *max_val,int y,int width,int height);;

/* Function at 00448d16 (Size: 74 bytes) */
void FUN_00448d16(int32_t player,int32_t card_slot);;

/* Function at 00448d60 (Size: 1177 bytes) */
int32_t Ai_CalcManaRequirement_004b7897(HWND hwnd,uint32_t uMsg,HDC wParam,int32_t lParam);;

/* Function at 004491fe (Size: 175 bytes) */
int FUN_004491fe(uint32_t *max_val);;

/* Function at 004492ad (Size: 1276 bytes) */
HBRUSH UI_PlayCoinTossAvi(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 004497ae (Size: 36 bytes) */
void FUN_004497ae(int32_t *player,int32_t *card_slot);;

/* Function at 004497d2 (Size: 31 bytes) */
void FUN_004497d2(HGDIOBJ max_val);;

/* Function at 004497f1 (Size: 234 bytes) */
int32_t FUN_004497f1(int max_val,int point,int32_t hBitmap,int32_t flags,int32_t *damage,int32_t *arg_6,int32_t *arg_7);;

/* Function at 004498e5 (Size: 2209 bytes) */
HBRUSH UI_DialogProc_004b8421(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam);;

/* Function at 0044a18b (Size: 220 bytes) */
void CardScript_Fireball(int32_t *max_val,int32_t *out_buffer,int *hBitmap,int *flags,int *damage,int32_t *arg_6,int32_t *arg_7);;

/* Function at 0044a267 (Size: 93 bytes) */
void FUN_0044a267(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 0044a2c4 (Size: 80 bytes) */
int FUN_0044a2c4(int player,int card_slot);;

/* Function at 0044a314 (Size: 656 bytes) */
uint8_t * Ai_Subsystem_004b8e4d(int player,int card_slot);;

/* Function at 0044a5a4 (Size: 60 bytes) */
void FUN_0044a5a4(int player,int card_slot);;

/* Function at 0044a5e0 (Size: 238 bytes) */
int32_t Ai_CalcManaRequirement_004b9120(LPCSTR str_1);;

/* Function at 0044a6ce (Size: 118 bytes) */
void FUN_0044a6ce(void);;

/* Function at 0044a744 (Size: 5167 bytes) */
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam);;

/* Function at 0044bb84 (Size: 475 bytes) */
void FUN_0044bb84(LPRECT max_val,HWND hwnd,int hBitmap);;

/* Function at 0044bd60 (Size: 132 bytes) */
bool UI_RegisterClass_0044bd60(LPCSTR str_1);;

/* Function at 0044bde4 (Size: 1003 bytes) */
LRESULT UI_WndProc_0044bde4(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 0044c1e0 (Size: 535 bytes) */
uint8_t * FUN_0044c1e0(char *str_1,uint8_t *point,void *hBitmap);;

/* Function at 0044c3f7 (Size: 131 bytes) */
bool FUN_0044c3f7(char *str_1,void *card_slot);;

/* Function at 0044c47a (Size: 486 bytes) */
int32_t FUN_0044c47a(void *max_val);;

/* Function at 0044c660 (Size: 220 bytes) */
int32_t FUN_0044c660(uint8_t *max_val);;

/* Function at 0044c73c (Size: 240 bytes) */
int32_t FUN_0044c73c(uint8_t *max_val,char *str_2,void *hBitmap,int32_t flags,int32_t damage,int arg_6,int arg_7);;

/* Function at 0044c82c (Size: 196 bytes) */
int32_t FUN_0044c82c(int32_t player,short card_slot);;

/* Function at 0044c8f0 (Size: 275 bytes) */
int32_t FUN_0044c8f0(char *str_1,int card_slot);;

/* Function at 0044ca03 (Size: 77 bytes) */
void FUN_0044ca03(uint8_t max_val);;

/* Function at 0044ca50 (Size: 95 bytes) */
int FUN_0044ca50(char max_val,char *str_2,int hBitmap);;

/* Function at 0044caaf (Size: 72 bytes) */
int32_t FUN_0044caaf(void *max_val);;

/* Function at 0044cb00 (Size: 248 bytes) */
int32_t UI_LoadPhaseBackdrop(LPCSTR str_1);;

/* Function at 0044cbf8 (Size: 118 bytes) */
void FUN_0044cbf8(void);;

/* Function at 0044cc6e (Size: 209 bytes) */
int32_t UI_LoadPhaseCombatBackdrop(LPCSTR str_1);;

/* Function at 0044cd3f (Size: 48 bytes) */
void Mem_AllocOrFree_0044cd3f(void);;

/* Function at 0044cd6f (Size: 4970 bytes) */
LRESULT UI_PhaseDisplayWndProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam);;

/* Function at 0044e141 (Size: 1004 bytes) */
void FUN_0044e141(POINT *x,RECT *point,int32_t *hBitmap,int *height);;

/* Function at 0044e52d (Size: 585 bytes) */
void FUN_0044e52d(LPRECT max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 0044e776 (Size: 685 bytes) */
void FUN_0044e776(HDC hdc,int card_slot);;

/* Function at 0044ea23 (Size: 4223 bytes) */
LRESULT UI_CombatDefenseWndProc(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam);;

/* Function at 0044fab8 (Size: 445 bytes) */
void FUN_0044fab8(POINT *max_val,RECT *point,int32_t *hBitmap);;

/* Function at 0044fc75 (Size: 449 bytes) */
void FUN_0044fc75(LPRECT max_val,int y,int width,int height);;

/* Function at 0044fe36 (Size: 619 bytes) */
void FUN_0044fe36(HDC hdc,int card_slot);;

/* Function at 004500a1 (Size: 563 bytes) */
void Pic_Draw_00427e36(int *max_val,int32_t *point,int hBitmap);;

/* Function at 0045033a (Size: 19 bytes) */
void Mem_AllocOrFree_0045033a(void);;

/* Function at 00450590 (Size: 52 bytes) */
uint32_t FUN_00450590(int player,int card_slot);;

/* Function at 004505c4 (Size: 47 bytes) */
int32_t Mem_AllocOrFree_004505c4(int player,int card_slot);;

/* Function at 004505f3 (Size: 106 bytes) */
uint32_t FUN_004505f3(int player,int card_slot);;

/* Function at 00450667 (Size: 48 bytes) */
int Mem_AllocOrFree_00450667(int player,int card_slot);;

/* Function at 00450697 (Size: 48 bytes) */
int Mem_AllocOrFree_00450697(int player,int card_slot);;

/* Function at 004506c7 (Size: 47 bytes) */
int32_t Mem_AllocOrFree_004506c7(int player,int card_slot);;

/* Function at 004506f6 (Size: 47 bytes) */
int32_t Mem_AllocOrFree_004506f6(int player,int card_slot);;

/* Function at 00450725 (Size: 106 bytes) */
int32_t FUN_00450725(int player,int card_slot);;

/* Function at 00450799 (Size: 137 bytes) */
int CardTypeFromID(int max_val);;

/* Function at 00450827 (Size: 61 bytes) */
int32_t CardIDFromType(uint32_t max_val);;

/* Function at 00450869 (Size: 44 bytes) */
uint32_t CardInDeck(uint32_t max_val);;

/* Function at 0045089a (Size: 54 bytes) */
void SetCardInDeck(int player,int card_slot);;

/* Function at 004508d0 (Size: 66 bytes) */
bool FUN_004508d0(int player,int card_slot);;

/* Function at 00450917 (Size: 283 bytes) */
uint8_t FUN_00450917(int player,int card_slot);;

/* Function at 00450a32 (Size: 94 bytes) */
undefined8 FUN_00450a32(int player,int card_slot);;

/* Function at 00450a90 (Size: 131 bytes) */
int32_t FUN_00450a90(int max_val,int point,int *hBitmap);;

/* Function at 00450b13 (Size: 111 bytes) */
uint8_t FUN_00450b13(int player,int card_slot);;

/* Function at 00450b87 (Size: 48 bytes) */
int Mem_AllocOrFree_00450b87(int player,int card_slot);;

/* Function at 00450bb7 (Size: 48 bytes) */
int Mem_AllocOrFree_00450bb7(int player,int card_slot);;

/* Function at 00450be7 (Size: 92 bytes) */
int32_t FUN_00450be7(int player,int card_slot);;

/* Function at 00450c48 (Size: 48 bytes) */
int Mem_AllocOrFree_00450c48(int player,int card_slot);;

/* Function at 00450c78 (Size: 48 bytes) */
int Mem_AllocOrFree_00450c78(int player,int card_slot);;

/* Function at 00450ca8 (Size: 110 bytes) */
char * Ai_Subsystem_004cc1e8(int player,int card_slot);;

/* Function at 00450d1b (Size: 108 bytes) */
int FUN_00450d1b(int player,int card_slot);;

/* Function at 00450d8c (Size: 108 bytes) */
int FUN_00450d8c(int player,int card_slot);;

/* Function at 00450dfd (Size: 135 bytes) */
int32_t FUN_00450dfd(int max_val,int point,int32_t hBitmap);;

/* Function at 00450e84 (Size: 52 bytes) */
int32_t FUN_00450e84(int player,int card_slot);;

/* Function at 00450eb8 (Size: 53 bytes) */
void FUN_00450eb8(int32_t max_val,int32_t point,int32_t hBitmap,int32_t flags);;

/* Function at 00450eed (Size: 40 bytes) */
void Mem_AllocOrFree_00450eed(uint8_t *max_val);;

/* Function at 00450f15 (Size: 69 bytes) */
int32_t FUN_00450f15(int *max_val,int point,int32_t hBitmap,int flags,int32_t damage);;

/* Function at 00450f5a (Size: 71 bytes) */
int32_t FUN_00450f5a(int *max_val,int point,int hBitmap,int32_t flags,int damage,int32_t arg_6);;

/* Function at 00450fa1 (Size: 41 bytes) */
void Mem_AllocOrFree_00450fa1(int32_t max_val);;

/* Function at 00450fca (Size: 99 bytes) */
void FUN_00450fca(int32_t max_val,int32_t point,int32_t hBitmap,int32_t flags);;

/* Function at 0045102d (Size: 592 bytes) */
int Ai_Subsystem_004cc56d(int max_val,int point,int hBitmap,int flags,int damage,uint32_t *arg_6,int arg_7);;

/* Function at 00451282 (Size: 79 bytes) */
void FUN_00451282(int32_t player,int32_t card_slot);;

/* Function at 004512d1 (Size: 107 bytes) */
INT_PTR FUN_004512d1(int max_val,int32_t point,INT_PTR hBitmap,char *str_4,char *str_5,char *str_6);;

/* Function at 0045133c (Size: 95 bytes) */
INT_PTR FUN_0045133c(int max_val,int32_t point,INT_PTR hBitmap);;

/* Function at 0045139b (Size: 95 bytes) */
INT_PTR FUN_0045139b(int max_val,int32_t point,INT_PTR hBitmap);;

/* Function at 004513fa (Size: 65 bytes) */
int FUN_004513fa(int max_val,int32_t point,int32_t hBitmap,int flags,uint32_t damage);;

/* Function at 0045143b (Size: 71 bytes) */
void FUN_0045143b(int32_t max_val);;

/* Function at 00451482 (Size: 734 bytes) */
void Duel_UpdateBoardState(int32_t player,int32_t card_slot);;

/* Function at 00451760 (Size: 565 bytes) */
void FUN_00451760(void);;

/* Function at 00451995 (Size: 631 bytes) */
void FUN_00451995(void);;

/* Function at 00451c0c (Size: 73 bytes) */
void FUN_00451c0c(int32_t max_val);;

/* Function at 00451c55 (Size: 57 bytes) */
void FUN_00451c55(void);;

/* Function at 00451c8e (Size: 61 bytes) */
int32_t FUN_00451c8e(void);;

/* Function at 00451ccb (Size: 372 bytes) */
int32_t Pic_Load_Title(void);;

/* Function at 00451e58 (Size: 592 bytes) */
void FUN_00451e58(void);;

/* Function at 004520a8 (Size: 171 bytes) */
int32_t Glue_Timer_004cd63b(void);;

/* Function at 00452153 (Size: 50 bytes) */
int32_t FUN_00452153(void);;

/* Function at 00452185 (Size: 21 bytes) */
void Mem_AllocOrFree_00452185(void);;

/* Function at 0045219a (Size: 53 bytes) */
int FUN_0045219a(void);;

/* Function at 004521d0 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_004521d0(void);;

/* Function at 004521e2 (Size: 645 bytes) */
uint32_t Mana_GetCardColorRequirement(int player, int card_slot);;

/* Function at 0045247b (Size: 959 bytes) */
int32_t Glue_Subsystem_004d0cdb(int max_val,int point,int hBitmap);;

/* Function at 0045283a (Size: 3108 bytes) */
int32_t Glue_Subsystem_004d109a(int max_val,int point,int hBitmap);;

/* Function at 00453463 (Size: 332 bytes) */
bool Palette_Subsystem_004a9137(int max_val,int point,int hBitmap);;

/* Function at 004535af (Size: 796 bytes) */
int32_t FUN_004535af(int max_val,int point,int hBitmap);;

/* Function at 004538cb (Size: 1247 bytes) */
void Glue_Subsystem_004d212c(int max_val,int point,int hBitmap);;

/* Function at 00453daf (Size: 970 bytes) */
int32_t Glue_Subsystem_004d2610(int spell_id,int target_id,int flags);;

/* Function at 00454179 (Size: 573 bytes) */
int32_t Glue_Subsystem_004d29da(int spell_id,int target_id,int flags);;

/* Function at 004543b6 (Size: 273 bytes) */
int32_t Glue_Subsystem_004d2c17(int max_val,int point,int hBitmap);;

/* Function at 004544c7 (Size: 258 bytes) */
int32_t FUN_004544c7(int player,int card_slot);;

/* Function at 004545c9 (Size: 322 bytes) */
int32_t FUN_004545c9(int player,int card_slot);;

/* Function at 0045470b (Size: 322 bytes) */
int32_t FUN_0045470b(int player,int card_slot);;

/* Function at 0045484d (Size: 150 bytes) */
int32_t FUN_0045484d(int max_val,int point,int hBitmap);;

/* Function at 004548e3 (Size: 101 bytes) */
int32_t FUN_004548e3(int max_val,int point,int hBitmap);;

/* Function at 00454948 (Size: 128 bytes) */
int32_t FUN_00454948(int max_val,int point,int hBitmap);;

/* Function at 004549c8 (Size: 99 bytes) */
int32_t FUN_004549c8(int max_val,int point,int hBitmap);;

/* Function at 00454a2b (Size: 158 bytes) */
int32_t FUN_00454a2b(int max_val,int point,int hBitmap);;

/* Function at 00454ac9 (Size: 531 bytes) */
int32_t FUN_00454ac9(int max_val,int point,int hBitmap);;

/* Function at 00454cdc (Size: 528 bytes) */
int32_t FUN_00454cdc(int max_val,int point,int hBitmap);;

/* Function at 00454eec (Size: 528 bytes) */
int32_t FUN_00454eec(int max_val,int point,int hBitmap);;

/* Function at 004550fc (Size: 960 bytes) */
int32_t FUN_004550fc(int max_val,int point,int hBitmap);;

/* Function at 004554bc (Size: 101 bytes) */
int32_t FUN_004554bc(int max_val,int point,int hBitmap);;

/* Function at 00455521 (Size: 125 bytes) */
int32_t FUN_00455521(int max_val,int point,int hBitmap);;

/* Function at 0045559e (Size: 418 bytes) */
int32_t FUN_0045559e(int max_val,int point,int hBitmap);;

/* Function at 00455740 (Size: 248 bytes) */
int32_t FUN_00455740(int max_val,int point,int hBitmap);;

/* Function at 00455838 (Size: 373 bytes) */
int32_t FUN_00455838(int max_val,int point,int hBitmap);;

/* Function at 004559ad (Size: 1364 bytes) */
int32_t Glue_Subsystem_004d420e(int spell_id,int target_id,int flags);;

/* Function at 00455f01 (Size: 1468 bytes) */
int32_t Glue_Subsystem_004d4762(int spell_id,int target_id,int flags);;

/* Function at 004564bd (Size: 596 bytes) */
int32_t FUN_004564bd(int max_val,int point,int hBitmap);;

/* Function at 00456711 (Size: 1715 bytes) */
int32_t FUN_00456711(int max_val,int point,int hBitmap);;

/* Function at 00456dc4 (Size: 1528 bytes) */
int32_t FUN_00456dc4(int max_val,int point,int hBitmap);;

/* Function at 004573bc (Size: 1907 bytes) */
int FUN_004573bc(int max_val,int point,int hBitmap);;

/* Function at 00457b2f (Size: 111 bytes) */
int32_t FUN_00457b2f(int player,int card_slot);;

/* Function at 00457b9e (Size: 773 bytes) */
int32_t FUN_00457b9e(int max_val,int point,int hBitmap);;

/* Function at 00457ea3 (Size: 313 bytes) */
int32_t FUN_00457ea3(int max_val,int point,int hBitmap);;

/* Function at 00457fdc (Size: 661 bytes) */
int32_t FUN_00457fdc(int max_val,int point,int hBitmap);;

/* Function at 00458271 (Size: 367 bytes) */
int32_t FUN_00458271(int max_val,int point,int hBitmap);;

/* Function at 004583e0 (Size: 319 bytes) */
int32_t FUN_004583e0(int max_val,int point,int hBitmap);;

/* Function at 0045851f (Size: 247 bytes) */
int32_t FUN_0045851f(int max_val,int point,int hBitmap);;

/* Function at 00458616 (Size: 492 bytes) */
int32_t FUN_00458616(int max_val,int point,int hBitmap);;

/* Function at 00458802 (Size: 1727 bytes) */
int32_t Glue_Subsystem_004d7065(int spell_id,int target_id,int flags);;

/* Function at 00458ec1 (Size: 87 bytes) */
int32_t FUN_00458ec1(int max_val,int point,int hBitmap);;

/* Function at 00458f18 (Size: 274 bytes) */
int32_t FUN_00458f18(int max_val,int point,int hBitmap);;

/* Function at 0045902a (Size: 69 bytes) */
int32_t FUN_0045902a(int32_t max_val,int32_t point,int hBitmap);;

/* Function at 0045906f (Size: 212 bytes) */
int32_t FUN_0045906f(int max_val,int point,int hBitmap);;

/* Function at 00459143 (Size: 117 bytes) */
int32_t FUN_00459143(int max_val,int point,int hBitmap);;

/* Function at 004591b8 (Size: 333 bytes) */
int32_t Glue_Subsystem_004d7a1b(int max_val,int point,int hBitmap);;

/* Function at 00459305 (Size: 77 bytes) */
int32_t FUN_00459305(int max_val,int point,int hBitmap);;

/* Function at 00459352 (Size: 171 bytes) */
int32_t Glue_Subsystem_004d7bb5(int max_val,int point,int hBitmap);;

/* Function at 004593fd (Size: 560 bytes) */
int32_t FUN_004593fd(int max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 0045962d (Size: 579 bytes) */
int32_t FUN_0045962d(int player,int card_slot);;

/* Function at 00459870 (Size: 168 bytes) */
int32_t FUN_00459870(int max_val,int point,int hBitmap);;

/* Function at 00459918 (Size: 1616 bytes) */
int32_t FUN_00459918(int max_val,int point,int hBitmap);;

/* Function at 00459f68 (Size: 1665 bytes) */
int32_t FUN_00459f68(int max_val,int point,int hBitmap);;

/* Function at 0045a5e9 (Size: 1685 bytes) */
int32_t FUN_0045a5e9(int max_val,int point,int hBitmap);;

/* Function at 0045ac7e (Size: 1564 bytes) */
int32_t FUN_0045ac7e(int max_val,int point,int hBitmap);;

/* Function at 0045b29a (Size: 1153 bytes) */
void Glue_Subsystem_004d9afd(int max_val,int point,int hBitmap);;

/* Function at 0045b71b (Size: 1284 bytes) */
int32_t Glue_Subsystem_004d9f7e(int spell_id,int target_id,int flags);;

/* Function at 0045bc1f (Size: 982 bytes) */
int32_t Glue_Subsystem_004da482(int spell_id,int target_id,int flags);;

/* Function at 0045bff5 (Size: 504 bytes) */
int32_t Glue_Subsystem_004da858(int spell_id,int target_id,int flags);;

/* Function at 0045c1ed (Size: 449 bytes) */
int32_t Glue_Subsystem_004daa50(int spell_id,int target_id,int flags);;

/* Function at 0045c3ae (Size: 613 bytes) */
int32_t Glue_Subsystem_004dac11(int spell_id,int target_id,int flags);;

/* Function at 0045c613 (Size: 430 bytes) */
int32_t FUN_0045c613(int x,int y,int width,uint32_t height);;

/* Function at 0045c7c1 (Size: 989 bytes) */
int32_t Glue_Subsystem_004db024(int spell_id,int target_id,int flags);;

/* Function at 0045cb9e (Size: 1222 bytes) */
bool FUN_0045cb9e(int max_val,int point,int hBitmap);;

/* Function at 0045d064 (Size: 339 bytes) */
int32_t FUN_0045d064(int max_val,int point,int hBitmap);;

/* Function at 0045d1b7 (Size: 1469 bytes) */
int32_t Glue_Subsystem_004dba1c(int spell_id,int target_id,int flags);;

/* Function at 0045d774 (Size: 746 bytes) */
void FUN_0045d774(int max_val,int point,int hBitmap);;

/* Function at 0045da63 (Size: 1021 bytes) */
int32_t Glue_Subsystem_004dc2ca(int spell_id,int target_id,int flags);;

/* Function at 0045de60 (Size: 806 bytes) */
int32_t Glue_Subsystem_004dc6c7(int spell_id,int target_id,int flags);;

/* Function at 0045e186 (Size: 1124 bytes) */
int32_t Glue_Subsystem_004dc9ed(int spell_id,int target_id,int flags);;

/* Function at 0045e5ea (Size: 1258 bytes) */
int32_t Glue_Subsystem_004dce51(int spell_id,int target_id,int flags);;

/* Function at 0045ead4 (Size: 753 bytes) */
int32_t FUN_0045ead4(int max_val,int point,int hBitmap);;

/* Function at 0045edca (Size: 861 bytes) */
uint8_t Glue_Subsystem_004dd632(int spell_id,int target_id,int flags);;

/* Function at 0045f127 (Size: 869 bytes) */
int32_t FUN_0045f127(int max_val,int point,int hBitmap);;

/* Function at 0045f48c (Size: 344 bytes) */
int32_t FUN_0045f48c(int max_val,int point,int hBitmap);;

/* Function at 0045f5e4 (Size: 168 bytes) */
int32_t FUN_0045f5e4(int max_val,int point,int hBitmap);;

/* Function at 0045f68c (Size: 81 bytes) */
int32_t FUN_0045f68c(int player,int card_slot);;

/* Function at 0045f6dd (Size: 77 bytes) */
int32_t FUN_0045f6dd(int max_val,int point,int hBitmap);;

/* Function at 0045f72a (Size: 199 bytes) */
int32_t FUN_0045f72a(int max_val,int point,int hBitmap);;

/* Function at 0045f7f1 (Size: 84 bytes) */
int32_t FUN_0045f7f1(int max_val,int point,int hBitmap);;

/* Function at 0045f845 (Size: 77 bytes) */
int32_t FUN_0045f845(int max_val,int point,int hBitmap);;

/* Function at 0045f892 (Size: 192 bytes) */
int32_t FUN_0045f892(int max_val,int point,int hBitmap);;

/* Function at 0045f952 (Size: 414 bytes) */
int32_t Glue_Subsystem_004de1c0(int max_val,int point,int hBitmap);;

/* Function at 0045faf0 (Size: 308 bytes) */
int32_t FUN_0045faf0(int max_val,int point,int hBitmap);;

/* Function at 0045fc24 (Size: 939 bytes) */
int32_t FUN_0045fc24(int max_val,int point,int hBitmap);;

/* Function at 0045ffcf (Size: 967 bytes) */
int32_t FUN_0045ffcf(int max_val,int point,int hBitmap);;

/* Function at 00460396 (Size: 610 bytes) */
int32_t Glue_Subsystem_004dec09(int spell_id,int target_id,int flags);;

/* Function at 004605f8 (Size: 343 bytes) */
int32_t Glue_Subsystem_004dee6b(int max_val,int point,int hBitmap);;

/* Function at 0046074f (Size: 136 bytes) */
int32_t FUN_0046074f(int max_val,int point,int hBitmap);;

/* Function at 004607d7 (Size: 450 bytes) */
int32_t Glue_Subsystem_004df04a(int spell_id,int target_id,int flags);;

/* Function at 00460999 (Size: 264 bytes) */
bool FUN_00460999(int max_val,int point,int hBitmap);;

/* Function at 00460aa1 (Size: 868 bytes) */
int32_t Glue_Subsystem_004df314(int spell_id,int target_id,int flags);;

/* Function at 00460e05 (Size: 578 bytes) */
bool Glue_Subsystem_004df678(int spell_id,int target_id,int flags);;

/* Function at 00461047 (Size: 612 bytes) */
bool FUN_00461047(int player,int card_slot);;

/* Function at 004612b0 (Size: 529 bytes) */
int32_t FUN_004612b0(int x,int y,int width,int flags);;

/* Function at 004614c6 (Size: 347 bytes) */
bool Glue_Subsystem_004dfd39(int spell_id,int target_id,int flags);;

/* Function at 00461621 (Size: 244 bytes) */
int32_t FUN_00461621(int max_val,int point,int hBitmap);;

/* Function at 00461715 (Size: 175 bytes) */
int32_t FUN_00461715(int max_val,int point,int hBitmap);;

/* Function at 004617c4 (Size: 176 bytes) */
int32_t FUN_004617c4(int max_val,int point,int hBitmap);;

/* Function at 00461874 (Size: 718 bytes) */
int32_t Glue_Subsystem_004e00e7(int max_val,int point,int hBitmap);;

/* Function at 00461b42 (Size: 265 bytes) */
int32_t FUN_00461b42(int max_val,int point,int hBitmap);;

/* Function at 00461c4b (Size: 194 bytes) */
int32_t FUN_00461c4b(int max_val,int point,int hBitmap);;

/* Function at 00461d0d (Size: 565 bytes) */
uint32_t FUN_00461d0d(int max_val,int point,int hBitmap);;

/* Function at 00461f42 (Size: 247 bytes) */
int32_t FUN_00461f42(int max_val,int point,int hBitmap);;

/* Function at 00462039 (Size: 175 bytes) */
int32_t FUN_00462039(int max_val,int point,int hBitmap);;

/* Function at 004620e8 (Size: 348 bytes) */
int32_t FUN_004620e8(int max_val,int point,int hBitmap);;

/* Function at 00462244 (Size: 357 bytes) */
bool Glue_Subsystem_004e0ab7(int spell_id,int target_id,int flags);;

/* Function at 004623a9 (Size: 580 bytes) */
bool Glue_Subsystem_004e0c1c(int spell_id,int target_id,int flags);;

/* Function at 004625ed (Size: 368 bytes) */
int32_t FUN_004625ed(int max_val,int point,int hBitmap);;

/* Function at 0046275d (Size: 382 bytes) */
int32_t FUN_0046275d(int max_val,int point,int hBitmap);;

/* Function at 004628db (Size: 385 bytes) */
int32_t FUN_004628db(int max_val,int point,int hBitmap);;

/* Function at 00462a5c (Size: 1614 bytes) */
int32_t FUN_00462a5c(int max_val,int point,int hBitmap);;

/* Function at 004630aa (Size: 270 bytes) */
int32_t FUN_004630aa(int max_val,int point,int hBitmap);;

/* Function at 004631b8 (Size: 269 bytes) */
int32_t FUN_004631b8(int max_val,int point,int hBitmap);;

/* Function at 004632c5 (Size: 340 bytes) */
int32_t Glue_Subsystem_004e1b38(int max_val,int point,int hBitmap);;

/* Function at 00463419 (Size: 266 bytes) */
int32_t FUN_00463419(int max_val,int point,int hBitmap);;

/* Function at 00463523 (Size: 213 bytes) */
int32_t FUN_00463523(int max_val,int point,int hBitmap);;

/* Function at 004635f8 (Size: 161 bytes) */
int32_t FUN_004635f8(int max_val,int point,int hBitmap);;

/* Function at 00463699 (Size: 190 bytes) */
int32_t FUN_00463699(int player,int card_slot);;

/* Function at 00463757 (Size: 310 bytes) */
int32_t Glue_Subsystem_004e1fcb(int max_val,int point,int hBitmap);;

/* Function at 0046388d (Size: 433 bytes) */
bool FUN_0046388d(int max_val,int point,int hBitmap);;

/* Function at 00463a3e (Size: 988 bytes) */
bool Glue_Subsystem_004e22b2(int spell_id,int target_id,int flags);;

/* Function at 00463e1a (Size: 435 bytes) */
int32_t Glue_Subsystem_004e268e(int max_val,int point,int hBitmap);;

/* Function at 00463fcd (Size: 856 bytes) */
int32_t Glue_Subsystem_004e2841(int spell_id,int target_id,int flags);;

/* Function at 00464325 (Size: 230 bytes) */
int FUN_00464325(int player,int card_slot);;

/* Function at 0046440b (Size: 873 bytes) */
int32_t Glue_Subsystem_004e2c7f(int max_val,int point,int hBitmap);;

/* Function at 00464774 (Size: 315 bytes) */
int32_t FUN_00464774(int max_val,int point,int hBitmap);;

/* Function at 004648af (Size: 93 bytes) */
int32_t FUN_004648af(int max_val,int point,int hBitmap);;

/* Function at 0046490c (Size: 364 bytes) */
int32_t FUN_0046490c(int max_val,int point,int hBitmap);;

/* Function at 00464a78 (Size: 497 bytes) */
int32_t Glue_Subsystem_004e32f3(int max_val,int point,int hBitmap);;

/* Function at 00464c69 (Size: 127 bytes) */
int32_t FUN_00464c69(int max_val,int point,int hBitmap);;

/* Function at 00464ce8 (Size: 129 bytes) */
int32_t FUN_00464ce8(int max_val,int point,int hBitmap);;

/* Function at 00464d69 (Size: 332 bytes) */
void FUN_00464d69(int max_val,int point,int hBitmap);;

/* Function at 00464eb5 (Size: 90 bytes) */
int32_t FUN_00464eb5(int max_val,int point,int hBitmap);;

/* Function at 00464f0f (Size: 970 bytes) */
int32_t Glue_Subsystem_004e378b(int max_val,int point,int hBitmap);;

/* Function at 004652d9 (Size: 753 bytes) */
int32_t Glue_Subsystem_004e3b55(int spell_id,int target_id,int flags);;

/* Function at 004655ca (Size: 766 bytes) */
int32_t Glue_Subsystem_004e3e46(int spell_id,int target_id,int flags);;

/* Function at 004658c8 (Size: 355 bytes) */
uint32_t FUN_004658c8(int max_val,int point,int hBitmap);;

/* Function at 00465a30 (Size: 604 bytes) */
int32_t FUN_00465a30(int max_val,int point,int hBitmap);;

/* Function at 00465c8c (Size: 582 bytes) */
void Pic_Load_0042a1c9(int max_val,int point,int hBitmap);;

/* Function at 00465ed2 (Size: 185 bytes) */
void FUN_00465ed2(int max_val,int point,int hBitmap);;

/* Function at 00465f8b (Size: 1959 bytes) */
int32_t Glue_Subsystem_004e4807(int spell_id,int target_id,int flags);;

/* Function at 00466732 (Size: 992 bytes) */
int32_t FUN_00466732(int max_val,int point,int hBitmap);;

/* Function at 00466b12 (Size: 583 bytes) */
int32_t FUN_00466b12(int max_val,int point,int hBitmap);;

/* Function at 00466d59 (Size: 568 bytes) */
int32_t FUN_00466d59(int max_val,int point,int hBitmap);;

/* Function at 00466f91 (Size: 287 bytes) */
bool FUN_00466f91(int max_val,int point,int hBitmap);;

/* Function at 004670b0 (Size: 269 bytes) */
int32_t FUN_004670b0(int max_val,int point,int hBitmap);;

/* Function at 004671bd (Size: 1026 bytes) */
int32_t FUN_004671bd(int max_val,int point,int hBitmap);;

/* Function at 004675bf (Size: 875 bytes) */
int32_t Glue_Subsystem_004e5e3b(int spell_id,int target_id,int flags);;

/* Function at 0046792a (Size: 932 bytes) */
int32_t Glue_Subsystem_004e61a6(int spell_id,int target_id,int flags);;

/* Function at 00467cce (Size: 151 bytes) */
int32_t FUN_00467cce(int player,uint8_t card_slot);;

/* Function at 00467d65 (Size: 210 bytes) */
void FUN_00467d65(uint8_t *player,int card_slot);;

/* Function at 00467e37 (Size: 184 bytes) */
void FUN_00467e37(int player,int card_slot);;

/* Function at 00467eef (Size: 118 bytes) */
void FUN_00467eef(int player,int card_slot);;

/* Function at 00467f65 (Size: 186 bytes) */
void FUN_00467f65(int max_val,int point,int hBitmap);;

/* Function at 0046801f (Size: 120 bytes) */
void FUN_0046801f(int max_val,int point,int hBitmap);;

/* Function at 00468097 (Size: 101 bytes) */
void FUN_00468097(int max_val,int point,int hBitmap);;

/* Function at 004680fc (Size: 52 bytes) */
uint32_t FUN_004680fc(int player,int card_slot);;

/* Function at 00468130 (Size: 300 bytes) */
bool Mana_CanAffordCost(int max_val, uint32_t point, int hBitmap);;

/* Function at 00468261 (Size: 285 bytes) */
bool FUN_00468261(int max_val,uint32_t point,int hBitmap);;

/* Function at 00468383 (Size: 461 bytes) */
int FUN_00468383(int max_val);;

/* Function at 00468550 (Size: 300 bytes) */
bool FUN_00468550(int max_val,uint32_t point,int hBitmap);;

/* Function at 00468681 (Size: 285 bytes) */
bool FUN_00468681(int max_val,uint32_t point,int hBitmap);;

/* Function at 004687a3 (Size: 142 bytes) */
int32_t FUN_004687a3(int max_val);;

/* Function at 00468831 (Size: 300 bytes) */
bool FUN_00468831(int max_val,uint32_t point,int hBitmap);;

/* Function at 00468962 (Size: 285 bytes) */
bool FUN_00468962(int max_val,uint32_t point,int hBitmap);;

/* Function at 00468a84 (Size: 142 bytes) */
int32_t FUN_00468a84(int max_val);;

/* Function at 00468b20 (Size: 408 bytes) */
int FUN_00468b20(int max_val,int point,int hBitmap);;

/* Function at 00468cb8 (Size: 104 bytes) */
int FUN_00468cb8(int max_val);;

/* Function at 00468def (Size: 1486 bytes) */
int32_t Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags);;

/* Function at 004693bd (Size: 147 bytes) */
int FUN_004693bd(int max_val);;

/* Function at 00469450 (Size: 203 bytes) */
int FUN_00469450(int player,int card_slot);;

/* Function at 0046951b (Size: 249 bytes) */
int FUN_0046951b(int max_val,int point,int32_t hBitmap);;

/* Function at 00469614 (Size: 529 bytes) */
int32_t FUN_00469614(int max_val,int point,int hBitmap);;

/* Function at 00469825 (Size: 424 bytes) */
int FUN_00469825(int max_val,int point,int hBitmap);;

/* Function at 004699cd (Size: 312 bytes) */
int FUN_004699cd(int max_val,int point,int hBitmap);;

/* Function at 00469b05 (Size: 311 bytes) */
int FUN_00469b05(int player,int card_slot);;

/* Function at 00469c3c (Size: 238 bytes) */
int32_t FUN_00469c3c(int max_val,int point,int hBitmap);;

/* Function at 00469d2a (Size: 487 bytes) */
int32_t FUN_00469d2a(int max_val,int point,int hBitmap);;

/* Function at 00469f11 (Size: 3040 bytes) */
int32_t Palette_Subsystem_004a8111(int max_val,int point,int hBitmap);;

/* Function at 0046ab46 (Size: 658 bytes) */
int32_t Palette_Subsystem_004a8d46(int max_val,int point,int hBitmap);;

/* Function at 0046add8 (Size: 351 bytes) */
int FUN_0046add8(int x,int y,int width,uint32_t height);;

/* Function at 0046af37 (Size: 2076 bytes) */
int32_t Palette_Subsystem_004a9137(int max_val,int point,int32_t hBitmap);;

/* Function at 0046b7a0 (Size: 4139 bytes) */
uint32_t UI_PromptFastEffectsDialog(int player,uint32_t *card_slot);;

/* Function at 0046c7d0 (Size: 1141 bytes) */
uint32_t FUN_0046c7d0(int max_val);;

/* Function at 0046cc45 (Size: 1260 bytes) */
int32_t FUN_0046cc45(int player,int card_slot);;

/* Function at 0046d140 (Size: 840 bytes) */
int32_t FUN_0046d140(void);;

/* Function at 0046d497 (Size: 1142 bytes) */
void Rules_ProcessDamagePrevention(void);;

/* Function at 0046d90d (Size: 317 bytes) */
void FUN_0046d90d(void);;

/* Function at 0046da4a (Size: 2677 bytes) */
int FUN_0046da4a(int player,int card_slot);;

/* Function at 0046e4c9 (Size: 168 bytes) */
int32_t FUN_0046e4c9(int x,int y,int width,int32_t flags);;

/* Function at 0046e571 (Size: 546 bytes) */
void Duel_DrawCardSprite(int max_val,int point,int hBitmap);;

/* Function at 0046e793 (Size: 191 bytes) */
int32_t Rules_SendCardsToGraveyard(void);;

/* Function at 0046e852 (Size: 1226 bytes) */
int32_t Rules_CardLeavingPlay(int player,int card_slot);;

/* Function at 0046ed1c (Size: 785 bytes) */
void FUN_0046ed1c(int player,int card_slot);;

/* Function at 0046f02d (Size: 233 bytes) */
void FUN_0046f02d(int player,int card_slot);;

/* Function at 0046f116 (Size: 121 bytes) */
void FUN_0046f116(int player,int card_slot);;

/* Function at 0046f18f (Size: 164 bytes) */
void FUN_0046f18f(int player,int card_slot);;

/* Function at 0046f240 (Size: 181 bytes) */
uint8_t UI_RegisterClass_0046f240(LPCSTR str_1);;

/* Function at 0046f2f5 (Size: 51 bytes) */
void FUN_0046f2f5(void);;

/* Function at 0046f328 (Size: 4272 bytes) */
uint32_t UI_WndProc_0046f328(HWND hwnd,uint32_t uMsg,uint32_t *wParam,LONG *lParam);;

/* Function at 00470437 (Size: 150 bytes) */
int FUN_00470437(HWND hwnd,int card_slot);;

/* Function at 004704cd (Size: 147 bytes) */
int FUN_004704cd(HWND hwnd,int card_slot);;

/* Function at 00470560 (Size: 365 bytes) */
void FUN_00470560(HWND hwnd,LPRECT card_slot);;

/* Function at 004706d0 (Size: 93 bytes) */
bool FUN_004706d0(void);;

/* Function at 0047072d (Size: 65 bytes) */
void FUN_0047072d(void);;

/* Function at 0047076e (Size: 54 bytes) */
void FUN_0047076e(char *str_1);;

/* Function at 004707a4 (Size: 79 bytes) */
void GDI_RealizeAndFlushPalette(HDC hdc);;

/* Function at 004707f3 (Size: 387 bytes) */
int32_t FUN_004707f3(int32_t max_val,int point,int32_t *hBitmap,BITMAPINFO *flags,int32_t *damage,int32_t *arg_6,int *arg_7);;

/* Function at 0047097b (Size: 51 bytes) */
void FUN_0047097b(HDC hdc,HGDIOBJ card_slot);;

/* Function at 004709ae (Size: 104 bytes) */
int32_t GDI_DrawBitmapToHDC(int max_val,int point,HANDLE hBitmap);;

/* Function at 00470a16 (Size: 330 bytes) */
int32_t FUN_00470a16(HDC hdc,int *point,HANDLE hBitmap,int flags,int damage,int arg_6,int arg_7);;

/* Function at 00470b60 (Size: 280 bytes) */
int32_t FUN_00470b60(HDC hdc,int *point,HANDLE hBitmap);;

/* Function at 00470c78 (Size: 130 bytes) */
int32_t FUN_00470c78(HDC max_val,int *point,HANDLE hBitmap);;

/* Function at 00470cfa (Size: 379 bytes) */
int32_t FUN_00470cfa(HDC hdc,int *point,HANDLE hBitmap,int flags,int damage,int arg_6,int arg_7,int arg_8,int arg_9);;

/* Function at 00470e75 (Size: 192 bytes) */
int32_t FUN_00470e75(int32_t max_val,LPCSTR str_2,void *hBitmap,int32_t flags);;

/* Function at 00470f35 (Size: 256 bytes) */
int32_t FUN_00470f35(LPCSTR str_1,void *point,int32_t hBitmap);;

/* Function at 00471035 (Size: 794 bytes) */
HBITMAP FUN_00471035(BITMAPINFO *player,void *card_slot);;

/* Function at 00471395 (Size: 145 bytes) */
void GDI_DestroyDIBSection(HANDLE max_val);;

/* Function at 00471426 (Size: 753 bytes) */
int32_t FUN_00471426(void);;

/* Function at 00471717 (Size: 38 bytes) */
void FUN_00471717(void);;

/* Function at 0047173d (Size: 417 bytes) */
void FUN_0047173d(int max_val,int point,RECT *hBitmap);;

/* Function at 004718de (Size: 584 bytes) */
void FUN_004718de(char *str_1,char *str_2,int width,char *str_4);;

/* Function at 00471b26 (Size: 454 bytes) */
int FUN_00471b26(char *str_1,char *str_2,int hBitmap);;

/* Function at 00471cf1 (Size: 261 bytes) */
int FUN_00471cf1(HWND hwnd,int card_slot);;

/* Function at 00471df6 (Size: 134 bytes) */
LRESULT UI_WndProc_00471df6(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);;

/* Function at 00471e86 (Size: 191 bytes) */
int32_t FUN_00471e86(char *str_1,COLORREF point,HBRUSH hBitmap);;

/* Function at 00471f45 (Size: 978 bytes) */
void FUN_00471f45(int max_val,HBRUSH point,HGDIOBJ hBitmap,HGDIOBJ flags,COLORREF damage,int arg_6);;

/* Function at 00472317 (Size: 571 bytes) */
void FUN_00472317(int max_val,HANDLE point,HANDLE hBitmap,HANDLE flags,COLORREF damage,int arg_6);;

/* Function at 00472552 (Size: 28 bytes) */
void FUN_00472552(HWND hwnd);;

/* Function at 0047256e (Size: 65 bytes) */
int32_t FUN_0047256e(HWND hwnd);;

/* Function at 004725af (Size: 309 bytes) */
LRESULT FUN_004725af(HWND hwnd,UINT y,HWND param_3,LPARAM flags);;

/* Function at 004726e4 (Size: 72 bytes) */
bool FUN_004726e4(HWND hwnd);;

/* Function at 00472731 (Size: 268 bytes) */
uint8_t * FUN_00472731(uint32_t *player,int card_slot);;

/* Function at 0047283d (Size: 383 bytes) */
void FUN_0047283d(void);;

/* Function at 004729bc (Size: 131 bytes) */
int FUN_004729bc(int player,int card_slot);;

/* Function at 00472a3f (Size: 190 bytes) */
int32_t FUN_00472a3f(HWND hwnd,int point,int hBitmap);;

/* Function at 00472b02 (Size: 94 bytes) */
uint32_t FUN_00472b02(int max_val);;

/* Function at 00472b60 (Size: 421 bytes) */
int32_t GDI_RealizePaletteTree(HWND hwnd,uint32_t y,HWND param_3,int32_t flags);;

/* Function at 00472d0a (Size: 84 bytes) */
int32_t FUN_00472d0a(HWND hwnd,int *card_slot);;

/* Function at 00472d60 (Size: 305 bytes) */
uint32_t FUN_00472d60(int max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 00472ea0 (Size: 278 bytes) */
void FUN_00472ea0(int max_val,int point,int hBitmap,int flags,int damage,int32_t arg_6);;

/* Function at 00472fc0 (Size: 2674 bytes) */
void FUN_00472fc0(int max_val);;

/* Function at 00473a32 (Size: 4945 bytes) */
void FUN_00473a32(int max_val);;

/* Function at 00474d83 (Size: 6885 bytes) */
uint32_t FUN_00474d83(int max_val);;

/* Function at 00476868 (Size: 317 bytes) */
void FUN_00476868(int max_val);;

/* Function at 004769a5 (Size: 388 bytes) */
void FUN_004769a5(int32_t player,int card_slot);;

/* Function at 00476b29 (Size: 2276 bytes) */
int FUN_00476b29(void);;

/* Function at 0047740d (Size: 6381 bytes) */
void Ai_EvalAttackCandidate_004c864d(uint32_t spell_id);;

/* Function at 00478cfa (Size: 78 bytes) */
int32_t FUN_00478cfa(int player,uint32_t card_slot);;

/* Function at 00478d48 (Size: 243 bytes) */
int32_t FUN_00478d48(int max_val);;

/* Function at 00478e3b (Size: 94 bytes) */
void FUN_00478e3b(void);;

/* Function at 00478e99 (Size: 1595 bytes) */
void FUN_00478e99(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int *arg_7,int *arg_8);;

/* Function at 004794d4 (Size: 1150 bytes) */
void FUN_004794d4(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int *arg_7,int *arg_8);;

/* Function at 00479952 (Size: 467 bytes) */
void FUN_00479952(void);;

/* Function at 00479b25 (Size: 96 bytes) */
void FUN_00479b25(int max_val,int point,int hBitmap);;

/* Function at 00479b85 (Size: 96 bytes) */
void FUN_00479b85(int max_val,int point,int hBitmap);;

/* Function at 00479be5 (Size: 34 bytes) */
void FUN_00479be5(WPARAM max_val);;

/* Function at 00479c07 (Size: 524 bytes) */
int FUN_00479c07(int player,int card_slot);;

/* Function at 00479e13 (Size: 396 bytes) */
int FUN_00479e13(int player,int card_slot);;

/* Function at 00479f9f (Size: 237 bytes) */
int32_t FUN_00479f9f(int player,int card_slot);;

/* Function at 0047a090 (Size: 494 bytes) */
int32_t Sound_PlaySpatialSound(int x, int y, int width, int height);;

/* Function at 0047a283 (Size: 38 bytes) */
void Mem_AllocOrFree_0047a283(int max_val,int point,int hBitmap);;

/* Function at 0047a2a9 (Size: 38 bytes) */
void Mem_AllocOrFree_0047a2a9(int max_val,int point,int hBitmap);;

/* Function at 0047a2cf (Size: 38 bytes) */
void Mem_AllocOrFree_0047a2cf(int max_val,int point,int hBitmap);;

/* Function at 0047a2f5 (Size: 38 bytes) */
void Mem_AllocOrFree_0047a2f5(int max_val,int point,int hBitmap);;

/* Function at 0047a31b (Size: 38 bytes) */
void Mem_AllocOrFree_0047a31b(int max_val,int point,int hBitmap);;

/* Function at 0047a341 (Size: 779 bytes) */
void Mana_Init_00452b71(int max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 0047a651 (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a651(int max_val,int point,int hBitmap);;

/* Function at 0047a67b (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a67b(int max_val,int point,int hBitmap);;

/* Function at 0047a6a5 (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a6a5(int max_val,int point,int hBitmap);;

/* Function at 0047a6cf (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a6cf(int max_val,int point,int hBitmap);;

/* Function at 0047a6f9 (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a6f9(int max_val,int point,int hBitmap);;

/* Function at 0047a723 (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a723(int max_val,int point,int hBitmap);;

/* Function at 0047a74d (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a74d(int max_val,int point,int hBitmap);;

/* Function at 0047a777 (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a777(int max_val,int point,int hBitmap);;

/* Function at 0047a7a1 (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a7a1(int max_val,int point,int hBitmap);;

/* Function at 0047a7cb (Size: 42 bytes) */
int32_t Mem_AllocOrFree_0047a7cb(int max_val,int point,int hBitmap);;

/* Function at 0047a7f5 (Size: 716 bytes) */
int32_t FUN_0047a7f5(int max_val,int point,int hBitmap);;

/* Function at 0047aac1 (Size: 514 bytes) */
int32_t Mana_Init_004532f1(int max_val,int point,int hBitmap);;

/* Function at 0047acdd (Size: 670 bytes) */
int32_t Ai_Subsystem_004b8e4d(int max_val,int point,int hBitmap);;

/* Function at 0047af80 (Size: 1200 bytes) */
int32_t CardScript_Oasis(int spell_id,int target_id,int flags);;

/* Function at 0047b430 (Size: 886 bytes) */
int32_t CardScript_ElephantsGraveyard(int max_val,int point,int hBitmap);;

/* Function at 0047b7ab (Size: 1016 bytes) */
int32_t Mana_Init_00453fdb(int spell_id,int target_id,int flags);;

/* Function at 0047bba3 (Size: 495 bytes) */
int32_t FUN_0047bba3(int max_val,int point,int hBitmap);;

/* Function at 0047bd97 (Size: 310 bytes) */
int32_t FUN_0047bd97(int max_val,int point,int hBitmap);;

/* Function at 0047bed2 (Size: 739 bytes) */
int32_t Mana_Init_00453fdb(int max_val,int point,int hBitmap);;

/* Function at 0047c1ba (Size: 3033 bytes) */
int32_t Mana_Init_00453fdb(int spell_id,int target_id,int flags);;

/* Function at 0047cd98 (Size: 2960 bytes) */
int32_t Mana_Init_004555c8(int spell_id,int target_id,int flags);;

/* Function at 0047d928 (Size: 192 bytes) */
int32_t FUN_0047d928(int max_val,int point,int hBitmap);;

/* Function at 0047d9e8 (Size: 477 bytes) */
int32_t FUN_0047d9e8(int max_val,int point,int hBitmap);;

/* Function at 0047dbca (Size: 339 bytes) */
int32_t FUN_0047dbca(int max_val,int point,int hBitmap);;

/* Function at 0047dd22 (Size: 133 bytes) */
int32_t FUN_0047dd22(int32_t max_val,int32_t point,int hBitmap);;

/* Function at 0047dda7 (Size: 339 bytes) */
int32_t FUN_0047dda7(int max_val,int point,int hBitmap);;

/* Function at 0047deff (Size: 1366 bytes) */
int32_t CardScript_Arena(int spell_id,int target_id,int flags);;

/* Function at 0047e4e0 (Size: 709 bytes) */
int * Glue_Subsystem_004f15c0(int max_val,char *str_2,int hBitmap);;

/* Function at 0047e7a5 (Size: 46 bytes) */
int32_t FUN_0047e7a5(void);;

/* Function at 0047e7d3 (Size: 1106 bytes) */
void * Haar_DecompressWaveletImage(int *player,void *card_slot);;

/* Function at 0047ec25 (Size: 103 bytes) */
void FUN_0047ec25(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int arg_7);;

/* Function at 0047ec8c (Size: 412 bytes) */
void FUN_0047ec8c(int *max_val,int *point,int *hBitmap,int flags,int damage,int32_t arg_6,int arg_7);;

/* Function at 0047ee28 (Size: 59 bytes) */
void FUN_0047ee28(undefined8 *max_val,undefined8 *point,uint32_t hBitmap);;

/* Function at 0047ee63 (Size: 105 bytes) */
void FUN_0047ee63(undefined8 *max_val,uint32_t point,uint32_t hBitmap);;

/* Function at 0047eecc (Size: 325 bytes) */
void FUN_0047eecc(int max_val,int point,int hBitmap);;

/* Function at 0047f011 (Size: 213 bytes) */
void FUN_0047f011(int *max_val,int *point,int *hBitmap,int flags,int damage,int32_t arg_6,int arg_7);;

/* Function at 0047f0e6 (Size: 219 bytes) */
void FUN_0047f0e6(int *max_val,int *point,int *hBitmap,int flags,int damage,int32_t arg_6,int arg_7);;

/* Function at 0047f1c1 (Size: 38 bytes) */
int16_t Mem_AllocOrFree_0047f1c1(uint32_t player,uint32_t card_slot);;

/* Function at 0047f1e7 (Size: 713 bytes) */
uint8_t *FUN_0047f1e7(uint8_t *max_val,int *point,int hBitmap,int flags,int damage,int arg_6,int arg_7,int32_t arg_8,int arg_9);;

/* Function at 0047f4b0 (Size: 567 bytes) */
int32_t FUN_0047f4b0(int player,int *card_slot);;

/* Function at 0047f6e7 (Size: 105 bytes) */
bool FUN_0047f6e7(HWND hwnd);;

/* Function at 0047f750 (Size: 131 bytes) */
int FUN_0047f750(HWND hwnd,void *point,int hBitmap,int flags,DWORD damage,DWORD arg_6);;

/* Function at 0047f7d3 (Size: 292 bytes) */
int32_t * FUN_0047f7d3(int32_t max_val,int point,int hBitmap);;

/* Function at 0047f8f7 (Size: 33 bytes) */
int32_t Mem_AllocOrFree_0047f8f7(int32_t max_val);;

/* Function at 0047f918 (Size: 757 bytes) */
int32_t * FUN_0047f918(int32_t *max_val,int *y,int width,int height);;

/* Function at 0047fc0d (Size: 106 bytes) */
bool FUN_0047fc0d(HWND hwnd,int *y,DWORD hBitmap,DWORD flags);;

/* Function at 0047fc77 (Size: 1831 bytes) */
uint32_t * FUN_0047fc77(uint32_t *x,int *y,int width,int height);;

/* Function at 0048039e (Size: 193 bytes) */
int32_t FUN_0048039e(HWND hwnd,int *y,DWORD hBitmap,DWORD flags);;

/* Function at 0048045f (Size: 82 bytes) */
int32_t * FUN_0048045f(int max_val);;

/* Function at 004804b1 (Size: 58 bytes) */
void FUN_004804b1(int max_val);;

/* Function at 004804eb (Size: 420 bytes) */
int FUN_004804eb(HWND hwnd,int point,int hBitmap,int flags,DWORD damage,DWORD arg_6);;

/* Function at 00480690 (Size: 374 bytes) */
void FUN_00480690(HWND hwnd);;

/* Function at 00480806 (Size: 2001 bytes) */
HBRUSH UI_DialogProc_00480806(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 00480fdc (Size: 229 bytes) */
void Pic_Load_s_WINBK_Options_00480fdc(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int *flags,int *damage,int *arg_6,int32_t *arg_7,int32_t *arg_8);;

/* Function at 004810c1 (Size: 93 bytes) */
void FUN_004810c1(HANDLE max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 0048111e (Size: 1906 bytes) */
void Rules_ParseFilter_0048111e(void);;

/* Function at 00481890 (Size: 1022 bytes) */
void Rules_ParseFilter_00481890(void);;

/* Function at 00481c8e (Size: 628 bytes) */
void FUN_00481c8e(void);;

/* Function at 00481f02 (Size: 418 bytes) */
void FUN_00481f02(void);;

/* Function at 004820b0 (Size: 287 bytes) */
bool UI_RegisterClass_00467880(LPCSTR str_1);;

/* Function at 004821cf (Size: 202 bytes) */
void FUN_004821cf(void);;

/* Function at 00482299 (Size: 12135 bytes) */
LRESULT Card_Setup_00467a68(HWND hwnd,uint32_t uMsg,HWND wParam,int *lParam);;

/* Function at 004852b1 (Size: 176 bytes) */
void FUN_004852b1(HWND hwnd);;

/* Function at 00485361 (Size: 550 bytes) */
int32_t FUN_00485361(HWND hwnd);;

/* Function at 00485587 (Size: 114 bytes) */
int FUN_00485587(HWND hwnd);;

/* Function at 004855f9 (Size: 654 bytes) */
bool FUN_004855f9(int player,int card_slot);;

/* Function at 00485887 (Size: 921 bytes) */
uint32_t Palette_Subsystem_0049c7c7(int player,int card_slot);;

/* Function at 00485c20 (Size: 54 bytes) */
bool FUN_00485c20(int player,int card_slot);;

/* Function at 00485c56 (Size: 159 bytes) */
bool FUN_00485c56(int player,int card_slot);;

/* Function at 00485cf5 (Size: 32 bytes) */
void Mem_AllocOrFree_00485cf5(int player,int card_slot);;

/* Function at 00485d15 (Size: 917 bytes) */
void FUN_00485d15(char *str_1,int point,int32_t hBitmap);;

/* Function at 004860aa (Size: 161 bytes) */
void FUN_004860aa(char *str_1,int point,int hBitmap);;

/* Function at 0048614b (Size: 19 bytes) */
void Mem_AllocOrFree_0048614b(void);;

/* Function at 00486239 (Size: 271 bytes) */
void FUN_00486239(HDC hdc,int y,int32_t hBitmap,int32_t flags);;

/* Function at 00486348 (Size: 125 bytes) */
int32_t FUN_00486348(HWND hwnd,int *card_slot);;

/* Function at 004863ca (Size: 127 bytes) */
int32_t FUN_004863ca(HWND hwnd,int card_slot);;

/* Function at 0048644e (Size: 99 bytes) */
int32_t FUN_0048644e(HWND hwnd);;

/* Function at 004864b1 (Size: 41 bytes) */
LONG FUN_004864b1(HWND hwnd);;

/* Function at 004864e0 (Size: 741 bytes) */
int FUN_004864e0(WPARAM max_val,int y,int width,int height);;

/* Function at 004867ca (Size: 151 bytes) */
uint8_t * FUN_004867ca(int player,int card_slot);;

/* Function at 00486861 (Size: 112 bytes) */
int FUN_00486861(int x,int y,int width,int height);;

/* Function at 004868d1 (Size: 236 bytes) */
int FUN_004868d1(HDC hdc,RECT *point,int width,int height);;

/* Function at 004869bd (Size: 135 bytes) */
int32_t FUN_004869bd(WPARAM max_val,int y,int width,int height);;

/* Function at 00486a4e (Size: 373 bytes) */
void FUN_00486a4e(int player,int card_slot);;

/* Function at 00486bc3 (Size: 79 bytes) */
void FUN_00486bc3(void);;

/* Function at 00486c12 (Size: 113 bytes) */
int FUN_00486c12(int max_val,int point,int hBitmap);;

/* Function at 00486c90 (Size: 310 bytes) */
bool UI_RegisterClass_00486c90(LPCSTR str_1);;

/* Function at 00486dc6 (Size: 81 bytes) */
void FUN_00486dc6(void);;

/* Function at 00486e17 (Size: 2807 bytes) */
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t y,HWND param_3,uint32_t height);;

/* Function at 00487924 (Size: 41 bytes) */
void Mem_AllocOrFree_00487924(int max_val);;

/* Function at 0048794d (Size: 179 bytes) */
LRESULT UI_WndProc_0048794d(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam);;

/* Function at 00487a10 (Size: 721 bytes) */
void FUN_00487a10(void);;

/* Function at 00487ce1 (Size: 1130 bytes) */
int FUN_00487ce1(int max_val);;

/* Function at 00488150 (Size: 1096 bytes) */
void Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 00488598 (Size: 202 bytes) */
int32_t FUN_00488598(int player,int card_slot);;

/* Function at 00488662 (Size: 2992 bytes) */
int32_t FUN_00488662(int max_val,int point,int hBitmap);;

/* Function at 00489247 (Size: 877 bytes) */
int32_t Ai_ChooseBlockers(int player,int card_slot);;

/* Function at 004895b4 (Size: 408 bytes) */
bool FUN_004895b4(int max_val,int point,int hBitmap);;

/* Function at 0048974c (Size: 2353 bytes) */
bool FUN_0048974c(int player,int card_slot);;

/* Function at 0048a07d (Size: 330 bytes) */
int32_t FUN_0048a07d(int player,int card_slot);;

/* Function at 0048a1c7 (Size: 262 bytes) */
int32_t FUN_0048a1c7(int max_val,int point,int hBitmap);;

/* Function at 0048a2cd (Size: 114 bytes) */
bool FUN_0048a2cd(int player,int card_slot);;

/* Function at 0048a33f (Size: 114 bytes) */
bool Duel_CardIsTapped(int player,int card_slot);;

/* Function at 0048a3b1 (Size: 114 bytes) */
int32_t FUN_0048a3b1(int player,int card_slot);;

/* Function at 0048a423 (Size: 722 bytes) */
void Card_Setup_00467a68(uint32_t max_val);;

/* Function at 0048acd3 (Size: 175 bytes) */
int32_t FUN_0048acd3(int max_val);;

/* Function at 0048ad82 (Size: 510 bytes) */
int32_t FUN_0048ad82(int player,int card_slot);;

/* Function at 0048af80 (Size: 66 bytes) */
bool FUN_0048af80(int player,int card_slot);;

/* Function at 0048afc2 (Size: 261 bytes) */
int32_t FUN_0048afc2(int max_val);;

/* Function at 0048b0c7 (Size: 391 bytes) */
int32_t FUN_0048b0c7(int max_val);;

/* Function at 0048b24e (Size: 123 bytes) */
int32_t FUN_0048b24e(int x,int point,int hBitmap,int flags);;

/* Function at 0048b2c9 (Size: 508 bytes) */
bool FUN_0048b2c9(int max_val,int point,int32_t hBitmap,int32_t flags,uint32_t damage,uint32_t arg_6);;

/* Function at 0048b4c5 (Size: 260 bytes) */
int FUN_0048b4c5(int x,int y,int32_t hBitmap,int32_t flags);;

/* Function at 0048b5c9 (Size: 134 bytes) */
void FUN_0048b5c9(int32_t player,int card_slot);;

/* Function at 0048b64f (Size: 459 bytes) */
void FUN_0048b64f(void);;

/* Function at 0048b81a (Size: 2824 bytes) */
uint32_t Duel_TapCardForMana(int x,int y,int width,int32_t flags);;

/* Function at 0048c367 (Size: 121 bytes) */
int32_t Duel_ColorMaskToIndex(uint8_t max_val);;

/* Function at 0048c420 (Size: 26 bytes) */
uint8_t * Mem_AllocOrFree_0048c420(int max_val);;

/* Function at 0048c43a (Size: 209 bytes) */
int FUN_0048c43a(int max_val);;

/* Function at 0048c50b (Size: 157 bytes) */
int32_t FUN_0048c50b(int max_val,int32_t point,int hBitmap);;

/* Function at 0048c5a8 (Size: 863 bytes) */
void Magic_ScanCards(int max_val);;

/* Function at 0048c907 (Size: 291 bytes) */
int Duel_PlayCardSoundEffect(int max_val,int point,int hBitmap,int32_t flags,int32_t damage);;

/* Function at 0048ca2a (Size: 159 bytes) */
bool FUN_0048ca2a(int player,int card_slot);;

/* Function at 0048cac9 (Size: 182 bytes) */
void FUN_0048cac9(void);;

/* Function at 0048cb7f (Size: 170 bytes) */
void FUN_0048cb7f(void);;

/* Function at 0048cc29 (Size: 945 bytes) */
void FUN_0048cc29(void);;

/* Function at 0048cfda (Size: 50 bytes) */
void FUN_0048cfda(int player,int card_slot);;

/* Function at 0048d00c (Size: 788 bytes) */
int32_t Sound_PlayTrackById(int max_val);;

/* Function at 0048d320 (Size: 143 bytes) */
void FUN_0048d320(void);;

/* Function at 0048d3af (Size: 16 bytes) */
void FUN_0048d3af(void);;

/* Function at 0048d3bf (Size: 44 bytes) */
int32_t Mem_AllocOrFree_0048d3bf(void);;

/* Function at 0048d3eb (Size: 51 bytes) */
int32_t FUN_0048d3eb(void);;

/* Function at 0048d41e (Size: 1114 bytes) */
int32_t FUN_0048d41e(int32_t max_val);;

/* Function at 0048d878 (Size: 1062 bytes) */
int32_t FUN_0048d878(int max_val,int point,int hBitmap,int flags,int32_t damage);;

/* Function at 0048dc9e (Size: 165 bytes) */
int32_t FUN_0048dc9e(void);;

/* Function at 0048dd43 (Size: 1294 bytes) */
int32_t FUN_0048dd43(void);;

/* Function at 0048e251 (Size: 177 bytes) */
int32_t FUN_0048e251(void);;

/* Function at 0048e302 (Size: 41 bytes) */
void Mem_AllocOrFree_0048e302(void);;

/* Function at 0048e32b (Size: 218 bytes) */
int32_t FUN_0048e32b(int x,int point,int32_t hBitmap,int32_t flags);;

/* Function at 0048e405 (Size: 1187 bytes) */
int FUN_0048e405(int x,int y,uint32_t *hBitmap,int32_t flags);;

/* Function at 0048e8a8 (Size: 74 bytes) */
int32_t FUN_0048e8a8(int x,int32_t point,int32_t hBitmap,int flags);;

/* Function at 0048e8f2 (Size: 495 bytes) */
int32_t FUN_0048e8f2(int x,int32_t point,int32_t hBitmap,int height);;

/* Function at 0048eae1 (Size: 68 bytes) */
int32_t FUN_0048eae1(void);;

/* Function at 0048eb25 (Size: 142 bytes) */
int FUN_0048eb25(int player,int card_slot);;

/* Function at 0048ebb3 (Size: 357 bytes) */
void FUN_0048ebb3(void);;

/* Function at 0048ed18 (Size: 377 bytes) */
int32_t FUN_0048ed18(int player,int card_slot);;

/* Function at 0048ee91 (Size: 470 bytes) */
void FUN_0048ee91(int max_val);;

/* Function at 0048f067 (Size: 183 bytes) */
int32_t FUN_0048f067(int player,int card_slot);;

/* Function at 0048f123 (Size: 142 bytes) */
void FUN_0048f123(void);;

/* Function at 0048f1b1 (Size: 361 bytes) */
void FUN_0048f1b1(void);;

/* Function at 0048f31a (Size: 475 bytes) */
uint32_t FUN_0048f31a(int x,int y,int width,int height);;

/* Function at 0048f500 (Size: 3217 bytes) */
int32_t Palette_Subsystem_0049608e(HWND hwnd,uint32_t y,HDC hdc,uint32_t height);;

/* Function at 00490196 (Size: 146 bytes) */
bool UI_RegisterClass_00490196(LPCSTR str_1);;

/* Function at 00490228 (Size: 11 bytes) */
void Mem_AllocOrFree_00490228(void);;

/* Function at 00490233 (Size: 309 bytes) */
LRESULT UI_WndProc_00490233(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam);;

/* Function at 0049036d (Size: 219 bytes) */
int32_t UI_Register_WINBK_BigCard_0049036d(LPCSTR str_1);;

/* Function at 00490448 (Size: 48 bytes) */
void Mem_AllocOrFree_00490448(void);;

/* Function at 00490478 (Size: 4331 bytes) */
LRESULT UI_WndProc_00490478(HWND hwnd,uint32_t uMsg,HWND wParam,LONG *lParam);;

/* Function at 00491688 (Size: 185 bytes) */
bool FUN_00491688(HWND hwnd,int card_slot);;

/* Function at 00491750 (Size: 118 bytes) */
void FUN_00491750(int32_t *max_val,int32_t point,int hBitmap);;

/* Function at 004917d0 (Size: 289 bytes) */
bool UI_RegisterClass_004917d0(LPCSTR str_1);;

/* Function at 004918f1 (Size: 153 bytes) */
void FUN_004918f1(void);;

/* Function at 0049198a (Size: 1114 bytes) */
LRESULT UI_WndProc_0049198a(HWND hwnd,uint32_t uMsg,HWND wParam,LPSTR lParam);;

/* Function at 00491ef3 (Size: 1064 bytes) */
int32_t FUN_00491ef3(int *max_val);;

/* Function at 00492440 (Size: 595 bytes) */
void File_Load_Info(void);;

/* Function at 00492693 (Size: 315 bytes) */
void Csv_LoadMaster_00492693(void);;

/* Function at 004927ce (Size: 164 bytes) */
void Csv_ReadConcise_004927ce(void);;

/* Function at 00492872 (Size: 223 bytes) */
void Csv_ReadConcise_00492872(void);;

/* Function at 00492951 (Size: 436 bytes) */
void Csv_LoadMaster_00492951(uint8_t *max_val,int y,int width,char *str_4);;

/* Function at 00492b05 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_00492b05(void);;

/* Function at 00492b17 (Size: 121 bytes) */
void FUN_00492b17(char *str_1,int card_slot);;

/* Function at 00492b90 (Size: 73 bytes) */
bool FUN_00492b90(char *str_1);;

/* Function at 00492bd9 (Size: 1297 bytes) */
int Deck_FilterAttributes_00492bd9(char *filter_string,int color_mask,uint32_t width,int height);;

/* Function at 004930ea (Size: 192 bytes) */
void Tale_Load_004930ea(int max_val);;

/* Function at 004931aa (Size: 578 bytes) */
void Hints_Load_004931aa(void);;

/* Function at 004933ec (Size: 122 bytes) */
void Hints_Load_004933ec(int max_val);;

/* Function at 00493466 (Size: 681 bytes) */
int FUN_00493466(int max_val);;

/* Function at 00493714 (Size: 103 bytes) */
int32_t FUN_00493714(int max_val);;

/* Function at 0049377b (Size: 144 bytes) */
char * FUN_0049377b(char *str_1);;

/* Function at 00493810 (Size: 1020 bytes) */
int32_t UI_Register_WINBK_Attack_00493810(LPCSTR str_1);;

/* Function at 00493c0c (Size: 548 bytes) */
void FUN_00493c0c(void);;

/* Function at 00493e30 (Size: 14669 bytes) */
uint32_t Glue_Subsystem_004cdb4f(HWND hwnd,uint32_t y,HWND param_3,HWND param_4);;

/* Function at 00497849 (Size: 245 bytes) */
int32_t FUN_00497849(int max_val,int point,int hBitmap);;

/* Function at 0049793e (Size: 2707 bytes) */
void FUN_0049793e(HWND hwnd);;

/* Function at 004983d1 (Size: 578 bytes) */
void FUN_004983d1(HWND hwnd,LPRECT card_slot);;

/* Function at 00498613 (Size: 91 bytes) */
bool FUN_00498613(int player,int card_slot);;

/* Function at 0049866e (Size: 2734 bytes) */
uint32_t UI_WndProc_0049866e(HWND hwnd,uint32_t uMsg,HWND wParam,int lParam);;

/* Function at 00499128 (Size: 103 bytes) */
void FUN_00499128(HWND hwnd);;

/* Function at 0049918f (Size: 861 bytes) */
LRESULT Glue_Subsystem_004d0602(HWND hwnd,uint32_t uMsg,HDC wParam,uint32_t lParam);;

/* Function at 004994f8 (Size: 688 bytes) */
int FUN_004994f8(HWND hwnd,int *point,int32_t *hBitmap,int32_t *flags,int32_t *damage);;

/* Function at 004997a8 (Size: 417 bytes) */
int FUN_004997a8(HWND hwnd,int card_slot);;

/* Function at 00499950 (Size: 293 bytes) */
void File_Load_Assertfile(int x,int y,int width,char *str_4);;

/* Function at 00499a78 (Size: 283 bytes) */
void File_Load_Assertfile(int x,int y,int width,char *str_4);;

/* Function at 00499ba0 (Size: 243 bytes) */
int32_t UI_Register_sPoison_00499ba0(LPCSTR str_1);;

/* Function at 00499c93 (Size: 118 bytes) */
void FUN_00499c93(void);;

/* Function at 00499d09 (Size: 3071 bytes) */
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t uMsg,HWND wParam,uint32_t lParam);;

/* Function at 0049a93a (Size: 63 bytes) */
void FUN_0049a93a(int32_t max_val);;

/* Function at 0049a979 (Size: 74 bytes) */
int32_t FUN_0049a979(int max_val);;

/* Function at 0049a9d0 (Size: 68 bytes) */
int32_t FUN_0049a9d0(void);;

/* Function at 0049aa14 (Size: 55 bytes) */
int FUN_0049aa14(int max_val,int point,int hBitmap);;

/* Function at 0049aa4b (Size: 51 bytes) */
void FUN_0049aa4b(void);;

/* Function at 0049aa7e (Size: 114 bytes) */
int FUN_0049aa7e(int player,int card_slot);;

/* Function at 0049aaf0 (Size: 11 bytes) */
void Mem_AllocOrFree_0049aaf0(void);;

/* Function at 0049aafb (Size: 11 bytes) */
void Mem_AllocOrFree_0049aafb(void);;

/* Function at 0049ab06 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049ab06(void);;

/* Function at 0049ab18 (Size: 40 bytes) */
void FUN_0049ab18(void *max_val,void *point,size_t hBitmap);;

/* Function at 0049ab40 (Size: 40 bytes) */
void FUN_0049ab40(void *max_val,void *point,size_t hBitmap);;

/* Function at 0049ab68 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049ab68(void);;

/* Function at 0049ab7a (Size: 120 bytes) */
int32_t FUN_0049ab7a(void);;

/* Function at 0049ac00 (Size: 341 bytes) */
void SaveGame_SaveGauntletFile(void);;

/* Function at 0049ad55 (Size: 270 bytes) */
void SaveGame_AutoSave(int32_t max_val);;

/* Function at 0049ae63 (Size: 98 bytes) */
void SaveGame_AutoSave(LPCSTR str_1);;

/* Function at 0049aed0 (Size: 66 bytes) */
int32_t FUN_0049aed0(int max_val,int point,int hBitmap);;

/* Function at 0049af12 (Size: 74 bytes) */
int32_t FUN_0049af12(int max_val,int point,int hBitmap);;

/* Function at 0049af5c (Size: 176 bytes) */
void FUN_0049af5c(int max_val,uint32_t point,int hBitmap);;

/* Function at 0049b00c (Size: 223 bytes) */
void FUN_0049b00c(int max_val,uint32_t point,int hBitmap);;

/* Function at 0049b0eb (Size: 190 bytes) */
void FUN_0049b0eb(int max_val,uint32_t point,int hBitmap);;

/* Function at 0049b1a9 (Size: 66 bytes) */
int32_t FUN_0049b1a9(int max_val,int point,int hBitmap);;

/* Function at 0049b1eb (Size: 74 bytes) */
int32_t FUN_0049b1eb(int max_val,int point,int hBitmap);;

/* Function at 0049b235 (Size: 66 bytes) */
int32_t FUN_0049b235(int max_val,int point,int hBitmap);;

/* Function at 0049b277 (Size: 74 bytes) */
int32_t FUN_0049b277(int max_val,int point,int hBitmap);;

/* Function at 0049b2c1 (Size: 72 bytes) */
int32_t FUN_0049b2c1(int max_val,int point,int hBitmap);;

/* Function at 0049b309 (Size: 895 bytes) */
int Duel_DrawString(int max_val, uint32_t point, int hBitmap);;

/* Function at 0049b68d (Size: 338 bytes) */
int FUN_0049b68d(int x,int y,uint32_t width,int height);;

/* Function at 0049b7f0 (Size: 675 bytes) */
int32_t Palette_Subsystem_00495958(int32_t max_val,int32_t point,char *str_3);;

/* Function at 0049ba93 (Size: 1859 bytes) */
int Catalog_LoadAllBigCardArtPics(HWND hwnd,int card_slot);;

/* Function at 0049c211 (Size: 62 bytes) */
int32_t FUN_0049c211(void);;

/* Function at 0049c24f (Size: 129 bytes) */
INT_PTR UI_DialogProc_0049c24f(HWND hwnd);;

/* Function at 0049c2d0 (Size: 3256 bytes) */
HBRUSH UI_DialogProc_0049c2d0(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 0049cff7 (Size: 229 bytes) */
void Pic_Load_s_GAUN_Startup_0049cff7(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int *flags,int *damage,int *arg_6,int32_t *arg_7,int32_t *arg_8);;

/* Function at 0049d0dc (Size: 93 bytes) */
void FUN_0049d0dc(HANDLE max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 0049d139 (Size: 68 bytes) */
void FUN_0049d139(uint32_t *player,int card_slot);;

/* Function at 0049d17d (Size: 579 bytes) */
LRESULT Palette_Subsystem_00496497(HWND hwnd);;

/* Function at 0049d3c0 (Size: 4627 bytes) */
int32_t Deck_FilterAttributes_0049d3c0(char *filter_string);;

/* Function at 0049e5d3 (Size: 137 bytes) */
int32_t FUN_0049e5d3(int max_val,int point,int hBitmap);;

/* Function at 0049e65c (Size: 157 bytes) */
WPARAM FUN_0049e65c(HWND hwnd,char *str_2);;

/* Function at 0049e6f9 (Size: 270 bytes) */
void FUN_0049e6f9(void);;

/* Function at 0049e807 (Size: 282 bytes) */
void FUN_0049e807(HWND hwnd,int card_slot);;

/* Function at 0049e921 (Size: 383 bytes) */
void FUN_0049e921(HWND hwnd,int card_slot);;

/* Function at 0049eaa0 (Size: 1944 bytes) */
HBRUSH UI_DialogProc_0049eaa0(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam);;

/* Function at 0049f242 (Size: 229 bytes) */
void Pic_Load_s_GAUN_Options_0049f242(int32_t *max_val,int32_t *out_buffer,int32_t *hBitmap,int *flags,int *damage,int *arg_6,int32_t *arg_7,int32_t *arg_8);;

/* Function at 0049f327 (Size: 93 bytes) */
void FUN_0049f327(HANDLE max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);;

/* Function at 0049f384 (Size: 340 bytes) */
void FUN_0049f384(HWND hwnd);;

/* Function at 0049f4d8 (Size: 82 bytes) */
bool FUN_0049f4d8(char *str_1,int32_t card_slot);;

/* Function at 0049f52a (Size: 41 bytes) */
void Mem_AllocOrFree_0049f52a(int32_t max_val);;

/* Function at 0049f553 (Size: 21 bytes) */
void Mem_AllocOrFree_0049f553(void);;

/* Function at 0049f568 (Size: 21 bytes) */
void Mem_AllocOrFree_0049f568(void);;

/* Function at 0049f57d (Size: 11 bytes) */
void Mem_AllocOrFree_0049f57d(void);;

/* Function at 0049f588 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f588(void);;

/* Function at 0049f59a (Size: 11 bytes) */
void Mem_AllocOrFree_0049f59a(void);;

/* Function at 0049f5a5 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5a5(void);;

/* Function at 0049f5b0 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5b0(void);;

/* Function at 0049f5bb (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5bb(void);;

/* Function at 0049f5c6 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f5c6(void);;

/* Function at 0049f5d8 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5d8(void);;

/* Function at 0049f5e3 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5e3(void);;

/* Function at 0049f5ee (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5ee(void);;

/* Function at 0049f5f9 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f5f9(void);;

/* Function at 0049f604 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f604(void);;

/* Function at 0049f616 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f616(void);;

/* Function at 0049f628 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f628(void);;

/* Function at 0049f633 (Size: 100 bytes) */
void FUN_0049f633(int max_val);;

/* Function at 0049f697 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f697(void);;

/* Function at 0049f6a9 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f6a9(void);;

/* Function at 0049f6b4 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f6b4(void);;

/* Function at 0049f6bf (Size: 11 bytes) */
void Mem_AllocOrFree_0049f6bf(void);;

/* Function at 0049f6ca (Size: 11 bytes) */
void Mem_AllocOrFree_0049f6ca(void);;

/* Function at 0049f6d5 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f6d5(void);;

/* Function at 0049f6e7 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f6e7(void);;

/* Function at 0049f6f9 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f6f9(void);;

/* Function at 0049f704 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f704(void);;

/* Function at 0049f70f (Size: 11 bytes) */
void Mem_AllocOrFree_0049f70f(void);;

/* Function at 0049f71a (Size: 11 bytes) */
void Mem_AllocOrFree_0049f71a(void);;

/* Function at 0049f725 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f725(void);;

/* Function at 0049f737 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f737(void);;

/* Function at 0049f749 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f749(void);;

/* Function at 0049f754 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f754(void);;

/* Function at 0049f75f (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f75f(void);;

/* Function at 0049f771 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f771(void);;

/* Function at 0049f783 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f783(void);;

/* Function at 0049f795 (Size: 11 bytes) */
void Mem_AllocOrFree_0049f795(void);;

/* Function at 0049f7a0 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f7a0(void);;

/* Function at 0049f7b2 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_0049f7b2(void);;

/* Function at 0049f7c4 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_0049f7c4(void);;

/* Function at 0049f7d9 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_0049f7d9(void);;

/* Function at 0049f7ee (Size: 19 bytes) */
int16_t Mem_AllocOrFree_0049f7ee(void);;

/* Function at 0049f801 (Size: 19 bytes) */
int16_t Mem_AllocOrFree_0049f801(void);;

/* Function at 0049f820 (Size: 673 bytes) */
int32_t Glue_Subsystem_004cd760(LPCSTR str_1);;

/* Function at 0049fac1 (Size: 334 bytes) */
void FUN_0049fac1(void);;

/* Function at 0049fc0f (Size: 7410 bytes) */
uint32_t Glue_Subsystem_004cdb4f(HWND hwnd,uint32_t y,HWND param_3,uint32_t height);;

/* Function at 004a197e (Size: 175 bytes) */
int FUN_004a197e(HWND hwnd);;

/* Function at 004a1a2d (Size: 333 bytes) */
void FUN_004a1a2d(HWND hwnd,int card_slot);;

/* Function at 004a1b7a (Size: 125 bytes) */
bool FUN_004a1b7a(void);;

/* Function at 004a1bf7 (Size: 569 bytes) */
int Palette_Subsystem_0049608e(HWND hwnd,int32_t point,int32_t hBitmap);;

/* Function at 004a1e30 (Size: 229 bytes) */
void FUN_004a1e30(HWND hwnd,int card_slot);;

/* Function at 004a1f15 (Size: 397 bytes) */
int Palette_Subsystem_0049608e(HWND hwnd);;

/* Function at 004a20a2 (Size: 1546 bytes) */
void FUN_004a20a2(HWND hwnd,LPRECT card_slot);;

/* Function at 004a26ac (Size: 26 bytes) */
void FUN_004a26ac(int32_t player,LPRECT card_slot);;

/* Function at 004a26c6 (Size: 861 bytes) */
LRESULT Glue_Subsystem_004d0602(HWND hwnd,uint32_t uMsg,HDC wParam,uint32_t lParam);;

/* Function at 004a2a2f (Size: 88 bytes) */
BOOL FUN_004a2a2f(void);;

/* Function at 004a2a87 (Size: 112 bytes) */
bool FUN_004a2a87(void);;

/* Function at 004a2b00 (Size: 561 bytes) */
int Duel_TriggerCardEvent(int max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 004a2d31 (Size: 622 bytes) */
int32_t FUN_004a2d31(int max_val,int point,int hBitmap);;

/* Function at 004a2f9f (Size: 162 bytes) */
int32_t FUN_004a2f9f(int max_val,int point,int hBitmap);;

/* Function at 004a3041 (Size: 269 bytes) */
int32_t FUN_004a3041(int max_val,int point,int hBitmap);;

/* Function at 004a314e (Size: 1093 bytes) */
int32_t FUN_004a314e(int max_val,int point,int hBitmap);;

/* Function at 004a3593 (Size: 341 bytes) */
int32_t FUN_004a3593(int max_val,int point,int hBitmap);;

/* Function at 004a36e8 (Size: 1774 bytes) */
int32_t FUN_004a36e8(int max_val,int point,int hBitmap);;

/* Function at 004a3dd6 (Size: 435 bytes) */
int32_t FUN_004a3dd6(int max_val,int point,int hBitmap);;

/* Function at 004a3f89 (Size: 251 bytes) */
int32_t FUN_004a3f89(int max_val,int point,int hBitmap);;

/* Function at 004a4084 (Size: 461 bytes) */
int32_t FUN_004a4084(int max_val,int point,int hBitmap);;

/* Function at 004a4251 (Size: 371 bytes) */
int32_t FUN_004a4251(int max_val,int point,int hBitmap);;

/* Function at 004a43c4 (Size: 260 bytes) */
int32_t FUN_004a43c4(int max_val,int point,int hBitmap);;

/* Function at 004a44c8 (Size: 437 bytes) */
bool FUN_004a44c8(int max_val,int point,int hBitmap);;

/* Function at 004a467d (Size: 1748 bytes) */
int32_t FUN_004a467d(int max_val,int point,int hBitmap);;

/* Function at 004a4d51 (Size: 1617 bytes) */
int32_t FUN_004a4d51(int max_val,int point,int hBitmap);;

/* Function at 004a53ac (Size: 761 bytes) */
int32_t FUN_004a53ac(int max_val,int point,int hBitmap);;

/* Function at 004a56a5 (Size: 457 bytes) */
int32_t FUN_004a56a5(int max_val,int point,int hBitmap);;

/* Function at 004a586e (Size: 376 bytes) */
int32_t FUN_004a586e(int max_val,int point,int hBitmap);;

/* Function at 004a59e6 (Size: 343 bytes) */
int32_t FUN_004a59e6(int max_val,int point,int hBitmap);;

/* Function at 004a5b3d (Size: 139 bytes) */
int32_t FUN_004a5b3d(int player,int card_slot);;

/* Function at 004a5bc8 (Size: 551 bytes) */
int32_t FUN_004a5bc8(int max_val,int point,int hBitmap);;

/* Function at 004a5def (Size: 699 bytes) */
int32_t FUN_004a5def(int max_val,int point,int hBitmap);;

/* Function at 004a60aa (Size: 814 bytes) */
int32_t FUN_004a60aa(int max_val,int point,int hBitmap);;

/* Function at 004a63d8 (Size: 519 bytes) */
int32_t FUN_004a63d8(int max_val,int point,int hBitmap);;

/* Function at 004a65df (Size: 189 bytes) */
int32_t FUN_004a65df(int max_val,int point,int hBitmap);;

/* Function at 004a66b0 (Size: 210 bytes) */
int32_t FUN_004a66b0(int max_val,int point,int hBitmap);;

/* Function at 004a6782 (Size: 378 bytes) */
int32_t FUN_004a6782(int max_val,int32_t point,int hBitmap);;

/* Function at 004a68fc (Size: 723 bytes) */
int32_t FUN_004a68fc(int max_val,int point,int hBitmap);;

/* Function at 004a6bd4 (Size: 448 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a6d94 (Size: 295 bytes) */
int32_t FUN_004a6d94(int max_val,int point,int hBitmap);;

/* Function at 004a6ebb (Size: 126 bytes) */
int32_t FUN_004a6ebb(int max_val,int point,int hBitmap);;

/* Function at 004a6f39 (Size: 412 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a70d5 (Size: 637 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a7352 (Size: 434 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a7504 (Size: 599 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a775b (Size: 1064 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a7b83 (Size: 176 bytes) */
int32_t FUN_004a7b83(int player,int card_slot);;

/* Function at 004a7c33 (Size: 609 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a7e94 (Size: 208 bytes) */
int32_t FUN_004a7e94(int max_val,int point,int hBitmap);;

/* Function at 004a7f64 (Size: 249 bytes) */
int32_t FUN_004a7f64(int max_val,int point,int hBitmap);;

/* Function at 004a805d (Size: 777 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a8366 (Size: 641 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a85e7 (Size: 702 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a88a5 (Size: 624 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a8b15 (Size: 92 bytes) */
int32_t FUN_004a8b15(int max_val,int point,int hBitmap);;

/* Function at 004a8b71 (Size: 484 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a8d55 (Size: 908 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a90e1 (Size: 951 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a9498 (Size: 700 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a9754 (Size: 139 bytes) */
int32_t FUN_004a9754(int max_val,int point,int hBitmap);;

/* Function at 004a97df (Size: 179 bytes) */
int32_t FUN_004a97df(int max_val,int point,int hBitmap);;

/* Function at 004a9892 (Size: 178 bytes) */
int32_t FUN_004a9892(int player,int card_slot);;

/* Function at 004a9944 (Size: 176 bytes) */
int32_t FUN_004a9944(int max_val,int point,int hBitmap);;

/* Function at 004a99f4 (Size: 221 bytes) */
int32_t FUN_004a99f4(int player,int card_slot);;

/* Function at 004a9ad1 (Size: 673 bytes) */
int32_t FUN_004a9ad1(int max_val,int point,int hBitmap);;

/* Function at 004a9d72 (Size: 189 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004a9e2f (Size: 607 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004aa08e (Size: 653 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004aa31b (Size: 459 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004aa4e6 (Size: 126 bytes) */
bool FUN_004aa4e6(int max_val,int point,int hBitmap);;

/* Function at 004aa569 (Size: 86 bytes) */
int32_t FUN_004aa569(int player,int card_slot);;

/* Function at 004aa5bf (Size: 1231 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004aaa93 (Size: 209 bytes) */
void FUN_004aaa93(int x,int y,int width,uint8_t flags);;

/* Function at 004aab64 (Size: 1904 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004ab2e3 (Size: 209 bytes) */
void FUN_004ab2e3(int x,int y,int width,uint8_t flags);;

/* Function at 004ab3b4 (Size: 1926 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004abb49 (Size: 1250 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004ac030 (Size: 636 bytes) */
uint32_t FUN_004ac030(int max_val,int point,int hBitmap);;

/* Function at 004ac2b1 (Size: 695 bytes) */
int32_t FUN_004ac2b1(int max_val,int point,int hBitmap);;

/* Function at 004ac56d (Size: 1594 bytes) */
int32_t FUN_004ac56d(int max_val,int point,int hBitmap);;

/* Function at 004acbac (Size: 995 bytes) */
int32_t FUN_004acbac(int max_val,int point,int hBitmap);;

/* Function at 004acf99 (Size: 1250 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004ad480 (Size: 519 bytes) */
uint32_t FUN_004ad480(int max_val,int point,int hBitmap);;

/* Function at 004ad687 (Size: 158 bytes) */
int32_t FUN_004ad687(int max_val,int point,int hBitmap);;

/* Function at 004ad725 (Size: 42 bytes) */
void Mem_AllocOrFree_004ad725(int max_val,int point,int hBitmap);;

/* Function at 004ad74f (Size: 38 bytes) */
void Mem_AllocOrFree_004ad74f(int max_val,int point,int hBitmap);;

/* Function at 004ad775 (Size: 2213 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags,int height);;

/* Function at 004ae01a (Size: 1704 bytes) */
int32_t Glue_Subsystem_004dd632(int spell_id,int target_id,int flags);;

/* Function at 004ae6cc (Size: 697 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004ae985 (Size: 1027 bytes) */
uint32_t FUN_004ae985(int max_val,int point,int hBitmap);;

/* Function at 004aed88 (Size: 117 bytes) */
int32_t FUN_004aed88(int max_val,int point,int hBitmap);;

/* Function at 004aee02 (Size: 402 bytes) */
int32_t FUN_004aee02(int max_val,int point,int hBitmap);;

/* Function at 004aef94 (Size: 614 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004af1fa (Size: 1173 bytes) */
int32_t FUN_004af1fa(int max_val,int point,int hBitmap);;

/* Function at 004af68f (Size: 156 bytes) */
int FUN_004af68f(int max_val);;

/* Function at 004af72b (Size: 33 bytes) */
void Mem_AllocOrFree_004af72b(int max_val);;

/* Function at 004af74c (Size: 106 bytes) */
int Duel_GetCardModifiedPower(int max_val, int point, int hBitmap);;

/* Function at 004af7bb (Size: 106 bytes) */
int Duel_GetCardColorOverride(int max_val, int point, int hBitmap);;

/* Function at 004af82a (Size: 294 bytes) */
void Rules_CardLeavingPlay(int player,int card_slot);;

/* Function at 004af950 (Size: 972 bytes) */
int Duel_ApplyCombatDamage(int max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 004afd1c (Size: 37 bytes) */
void Mem_AllocOrFree_004afd1c(int x,int y,int width,int height);;

/* Function at 004afd50 (Size: 180 bytes) */
bool Glue_Subsystem_004ecee0(LPCSTR str_1);;

/* Function at 004afe04 (Size: 81 bytes) */
void FUN_004afe04(void);;

/* Function at 004afe55 (Size: 7257 bytes) */
int Glue_UI_004ecfe5(HWND hwnd,uint32_t y,HWND param_3,uint32_t height);;

/* Function at 004b1bba (Size: 263 bytes) */
void FUN_004b1bba(HWND hwnd);;

/* Function at 004b1cc1 (Size: 529 bytes) */
void FUN_004b1cc1(HWND hwnd);;

/* Function at 004b1ed2 (Size: 253 bytes) */
void FUN_004b1ed2(HWND hwnd);;

/* Function at 004b1fcf (Size: 1271 bytes) */
void FUN_004b1fcf(HWND hwnd,int *point,int hBitmap,int *flags,int *damage,int arg_6);;

/* Function at 004b24c6 (Size: 245 bytes) */
void FUN_004b24c6(HWND hwnd,HWND param_2);;

/* Function at 004b25bb (Size: 265 bytes) */
void FUN_004b25bb(HWND hwnd,LPARAM point,uint8_t hBitmap);;

/* Function at 004b26c4 (Size: 295 bytes) */
int FUN_004b26c4(HWND hwnd,int *y,int32_t *hBitmap,int32_t *flags);;

/* Function at 004b27eb (Size: 171 bytes) */
int32_t FUN_004b27eb(HWND hwnd,int *card_slot);;

/* Function at 004b289b (Size: 154 bytes) */
int FUN_004b289b(HWND hwnd,int card_slot);;

/* Function at 004b2935 (Size: 129 bytes) */
int FUN_004b2935(HWND hwnd,int card_slot);;

/* Function at 004b29b6 (Size: 259 bytes) */
HGDIOBJ UI_DialogProc_004b29b6(HWND hwnd,uint32_t point,HDC hdc);;

/* Function at 004b2bd0 (Size: 1932 bytes) */
int Ai_Subsystem_004bc029(int spell_id,int target_id,int flags,uint32_t flags,uint32_t damage,int arg_6,int32_t arg_7);;

/* Function at 004b3360 (Size: 145 bytes) */
bool UI_RegisterClass_004b3360(LPCSTR str_1);;

/* Function at 004b33f1 (Size: 6694 bytes) */
uint32_t Catalog_LoadAllBigCardArtPics(HWND hwnd,uint32_t y,HWND param_3,int *height);;

/* Function at 004b4ea6 (Size: 86 bytes) */
WPARAM FUN_004b4ea6(void);;

/* Function at 004b4efc (Size: 1636 bytes) */
int32_t Pic_Clip_00443b63(HWND hwnd);;

/* Function at 004b5565 (Size: 3841 bytes) */
void FUN_004b5565(HWND hwnd,int card_slot);;

/* Function at 004b6466 (Size: 1239 bytes) */
void Palette_Subsystem_0049c3ac(int max_val,int point,int hBitmap);;

/* Function at 004b693d (Size: 69 bytes) */
void FUN_004b693d(void);;

/* Function at 004b6982 (Size: 705 bytes) */
int32_t Palette_Subsystem_0049608e(HWND hwnd,uint32_t y,HDC hdc,int32_t flags);;

/* Function at 004b6c50 (Size: 604 bytes) */
int32_t Palette_Color_0049ae00(LPCSTR filepath);;

/* Function at 004b6eac (Size: 318 bytes) */
void FUN_004b6eac(void);;

/* Function at 004b6fea (Size: 2920 bytes) */
uint32_t UI_Register_WINBK_TellUser_004b6fea(HWND hwnd,uint32_t y,HWND param_3,int height);;

/* Function at 004b7b63 (Size: 1009 bytes) */
void FUN_004b7b63(HWND hwnd,char *str_2,uint32_t hBitmap);;

/* Function at 004b7f54 (Size: 173 bytes) */
void FUN_004b7f54(HWND hwnd);;

/* Function at 004b8001 (Size: 350 bytes) */
void FUN_004b8001(HWND hwnd,HDC hdc,int *hBitmap);;

/* Function at 004b8160 (Size: 209 bytes) */
int FUN_004b8160(int32_t max_val,int point,int hBitmap);;

/* Function at 004b8231 (Size: 1597 bytes) */
int32_t UI_DialogProc_004b8231(HWND hwnd,uint32_t uMsg,HWND wParam,uint8_t *lParam);;

/* Function at 004b8899 (Size: 846 bytes) */
void FUN_004b8899(HWND hwnd,uint8_t point,uint8_t hBitmap);;

/* Function at 004b8bf0 (Size: 303 bytes) */
int32_t FUN_004b8bf0(void);;

/* Function at 004b921d (Size: 81 bytes) */
uint32_t FUN_004b921d(void);;

/* Function at 004b926e (Size: 16 bytes) */
void Mem_AllocOrFree_004b926e(void);;

/* Function at 004b927e (Size: 326 bytes) */
int FUN_004b927e(HDC hdc,int *y,WPARAM *hBitmap,int height);;

/* Function at 004b93c4 (Size: 84 bytes) */
int FUN_004b93c4(void);;

/* Function at 004b9420 (Size: 18 bytes) */
int32_t Mem_AllocOrFree_004b9420(void);;

/* Function at 004b9432 (Size: 11 bytes) */
void Mem_AllocOrFree_004b9432(void);;

/* Function at 004b943d (Size: 11 bytes) */
void Mem_AllocOrFree_004b943d(void);;

/* Function at 004b9448 (Size: 11 bytes) */
void Mem_AllocOrFree_004b9448(void);;

/* Function at 004b9460 (Size: 195 bytes) */
bool UI_RegisterClass_004b9460(LPCSTR str_1);;

/* Function at 004b9523 (Size: 81 bytes) */
void FUN_004b9523(void);;

/* Function at 004b9574 (Size: 5262 bytes) */
LRESULT UI_PlayerHandCardWndProc(HWND hwnd,uint32_t y,HWND param_3,LONG *flags);;

/* Function at 004baa8b (Size: 823 bytes) */
void FUN_004baa8b(HWND hwnd);;

/* Function at 004badc2 (Size: 629 bytes) */
void FUN_004badc2(HDC hdc,int *point,int *hBitmap,int flags,int damage,int arg_6,int arg_7,int arg_8,HANDLE arg_9);;

/* Function at 004bb037 (Size: 139 bytes) */
void FUN_004bb037(int32_t max_val,int point,int hBitmap,int flags,int damage,int arg_6,int *arg_7,int *arg_8,int *arg_9,int *arg_10);;

/* Function at 004bb0c2 (Size: 92 bytes) */
void UI_DrawPlayerHandWindow(char *str_1,HWND hwnd,int32_t hBitmap);;

/* Function at 004bb120 (Size: 1278 bytes) */
int32_t FUN_004bb120(int max_val,int point,int hBitmap);;

/* Function at 004bb61e (Size: 1340 bytes) */
int32_t FUN_004bb61e(int max_val,int point,int hBitmap);;

/* Function at 004bbb5a (Size: 1245 bytes) */
int32_t FUN_004bbb5a(int max_val,int point,int hBitmap);;

/* Function at 004bc037 (Size: 1463 bytes) */
int32_t CardScript_SylvanLibrary(int spell_id,int target_id,int flags);;

/* Function at 004bc5ee (Size: 1675 bytes) */
int32_t CardScript_LandTax(int spell_id,int target_id,int flags);;

/* Function at 004bcc7e (Size: 601 bytes) */
int CardScript_Kismet(int spell_id,int target_id,int flags);;

/* Function at 004bced7 (Size: 243 bytes) */
void FUN_004bced7(int max_val,int point,int hBitmap);;

/* Function at 004bcfca (Size: 2641 bytes) */
uint32_t Pic_Load_0042a1c9(int spell_id,int target_id,int flags);;

/* Function at 004bda20 (Size: 510 bytes) */
int32_t Pic_Subsystem_0042ac1f(int player,int card_slot);;

/* Function at 004bdc1e (Size: 2008 bytes) */
int32_t CardScript_AnimateArtifact(int spell_id,int target_id,int flags);;

/* Function at 004be3f6 (Size: 1208 bytes) */
int32_t FUN_004be3f6(int max_val,int point,int hBitmap);;

/* Function at 004be8ae (Size: 64 bytes) */
int32_t FUN_004be8ae(int max_val,int point,int hBitmap);;

/* Function at 004be8ee (Size: 64 bytes) */
int32_t FUN_004be8ee(int max_val,int point,int hBitmap);;

/* Function at 004be92e (Size: 951 bytes) */
int32_t CardScript_AnimateWall(int spell_id,int target_id,int flags);;

/* Function at 004bece5 (Size: 96 bytes) */
void CardScript_ControlMagic(int spell_id,int target_id,int flags);;

/* Function at 004bed45 (Size: 96 bytes) */
void CardScript_StealArtifact(int spell_id,int target_id,int flags);;

/* Function at 004beda5 (Size: 2442 bytes) */
int32_t FUN_004beda5(int x,int y,int width,uint32_t height);;

/* Function at 004bf72f (Size: 292 bytes) */
int32_t FUN_004bf72f(int max_val,int point,int hBitmap);;

/* Function at 004bf853 (Size: 1040 bytes) */
int FUN_004bf853(int player,int card_slot);;

/* Function at 004bfc63 (Size: 2028 bytes) */
int32_t FUN_004bfc63(int x,int y,int width,int height);;

/* Function at 004c044f (Size: 1242 bytes) */
int32_t FUN_004c044f(int max_val,int point,int hBitmap);;

/* Function at 004c0929 (Size: 502 bytes) */
int32_t FUN_004c0929(int max_val,int point,int hBitmap);;

/* Function at 004c0b1f (Size: 1461 bytes) */
int32_t CardScript_Feedback(int spell_id,int target_id,int flags);;

/* Function at 004c10d9 (Size: 1335 bytes) */
int32_t CardScript_Brainwash(int spell_id,int target_id,int flags);;

/* Function at 004c1610 (Size: 178 bytes) */
int32_t FUN_004c1610(int max_val,int point,int hBitmap);;

/* Function at 004c16c2 (Size: 935 bytes) */
int32_t CardScript_SpiritShackle(int spell_id,int target_id,int flags);;

/* Function at 004c1a69 (Size: 314 bytes) */
int32_t FUN_004c1a69(int player,int card_slot);;

/* Function at 004c1ba3 (Size: 1370 bytes) */
int32_t CardScript_RelicBind(uint32_t spell_id,int target_id,int flags);;

/* Function at 004c20fd (Size: 915 bytes) */
uint32_t FUN_004c20fd(int max_val,int point,int hBitmap);;

/* Function at 004c2495 (Size: 249 bytes) */
int32_t FUN_004c2495(int max_val,int point,int hBitmap);;

/* Function at 004c258e (Size: 243 bytes) */
int32_t FUN_004c258e(int max_val,int point,int hBitmap);;

/* Function at 004c2681 (Size: 1562 bytes) */
int32_t CardScript_PowerLeak(int spell_id,int target_id,int flags);;

/* Function at 004c2ca0 (Size: 387 bytes) */
int32_t Pic_Subsystem_0042fe9a(int max_val,int point,int hBitmap);;

/* Function at 004c2e23 (Size: 408 bytes) */
int32_t FUN_004c2e23(int max_val,int point,int hBitmap);;

/* Function at 004c2fbb (Size: 158 bytes) */
int32_t FUN_004c2fbb(int max_val,int point,int hBitmap);;

/* Function at 004c3059 (Size: 922 bytes) */
uint32_t FUN_004c3059(int max_val,int point,int hBitmap);;

/* Function at 004c33f8 (Size: 283 bytes) */
int32_t FUN_004c33f8(int max_val,int point,int hBitmap);;

/* Function at 004c3513 (Size: 2036 bytes) */
int32_t CardScript_Erosion(int spell_id,int target_id,int flags);;

/* Function at 004c3d11 (Size: 1326 bytes) */
int32_t CardScript_CursedLand(int spell_id,int target_id,int flags);;

/* Function at 004c4244 (Size: 650 bytes) */
uint32_t FUN_004c4244(int max_val,int point,int hBitmap);;

/* Function at 004c44d3 (Size: 756 bytes) */
int32_t FUN_004c44d3(int max_val,int point,int hBitmap);;

/* Function at 004c47cc (Size: 1294 bytes) */
int32_t CardScript_EvilPresence(int spell_id,int target_id,int flags);;

/* Function at 004c4cda (Size: 1831 bytes) */
int32_t CardScript_LivingArtifact(int spell_id,int target_id,int flags);;

/* Function at 004c5406 (Size: 1300 bytes) */
int32_t CardScript_Blight(int spell_id,int target_id,int flags);;

/* Function at 004c591a (Size: 1118 bytes) */
int32_t CardScript_TargetLand(int spell_id,int target_id,int flags);;

/* Function at 004c5d78 (Size: 231 bytes) */
int32_t FUN_004c5d78(int max_val,int point,int hBitmap);;

/* Function at 004c5e5f (Size: 474 bytes) */
int32_t FUN_004c5e5f(int max_val,int point,int hBitmap);;

/* Function at 004c6039 (Size: 258 bytes) */
int32_t FUN_004c6039(int max_val,int point,int hBitmap);;

/* Function at 004c613b (Size: 306 bytes) */
void FUN_004c613b(int max_val,int32_t point,int hBitmap);;

/* Function at 004c626d (Size: 438 bytes) */
int32_t FUN_004c626d(int max_val,int point,int hBitmap);;

/* Function at 004c6423 (Size: 220 bytes) */
int32_t FUN_004c6423(int max_val,int point,int hBitmap);;

/* Function at 004c64ff (Size: 934 bytes) */
int32_t Pic_Subsystem_004336f8(int max_val,int point,int hBitmap);;

/* Function at 004c68a5 (Size: 229 bytes) */
int32_t FUN_004c68a5(int max_val,int point,int hBitmap);;

/* Function at 004c698a (Size: 223 bytes) */
int32_t FUN_004c698a(int max_val,int point,int hBitmap);;

/* Function at 004c6a69 (Size: 853 bytes) */
int32_t CardScript_AspectOfWolf(int spell_id,int target_id,int flags);;

/* Function at 004c6dbe (Size: 1401 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004c7337 (Size: 123 bytes) */
int32_t FUN_004c7337(int x,int y,int width,int height);;

/* Function at 004c73b2 (Size: 1398 bytes) */
int32_t CardScript_SpiritLink(int spell_id,int target_id,int flags);;

/* Function at 004c7928 (Size: 1043 bytes) */
int32_t CardScript_CreatureBond(int spell_id,int target_id,int flags);;

/* Function at 004c7d3b (Size: 1153 bytes) */
int32_t CardScript_GaseousForm(int spell_id,int target_id,int flags);;

/* Function at 004c81bc (Size: 1804 bytes) */
int32_t CardScript_Backfire(int spell_id,int target_id,int flags);;

/* Function at 004c88c8 (Size: 2625 bytes) */
int32_t CardScript_HolyArmor(int spell_id,int target_id,int flags);;

/* Function at 004c9309 (Size: 2656 bytes) */
int32_t CardScript_Blessing(int spell_id,int target_id,int flags);;

/* Function at 004c9d69 (Size: 2521 bytes) */
int32_t CardScript_Firebreathing(int spell_id,int target_id,int flags);;

/* Function at 004ca742 (Size: 387 bytes) */
void CardScript_Invisibility(int spell_id,int target_id,int flags);;

/* Function at 004ca8ca (Size: 820 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004cabfe (Size: 819 bytes) */
int32_t CardScript_Seeker(int spell_id,int target_id,int flags);;

/* Function at 004caf31 (Size: 754 bytes) */
int32_t Palette_Color_0049ae00(int spell_id,int target_id,int flags);;

/* Function at 004cb223 (Size: 1143 bytes) */
int32_t FUN_004cb223(int max_val,int point,int hBitmap);;

/* Function at 004cb69a (Size: 258 bytes) */
int32_t FUN_004cb69a(int max_val,int point,int hBitmap);;

/* Function at 004cb79c (Size: 856 bytes) */
int32_t FUN_004cb79c(int max_val,int point,int hBitmap);;

/* Function at 004cbaf4 (Size: 1820 bytes) */
int32_t CardScript_Paralyze(int spell_id,int target_id,int flags);;

/* Function at 004cc210 (Size: 987 bytes) */
int32_t Pic_Subsystem_00439408(int max_val,int point,int hBitmap);;

/* Function at 004cc5eb (Size: 938 bytes) */
int32_t FUN_004cc5eb(int max_val,int point,int hBitmap);;

/* Function at 004cc99a (Size: 500 bytes) */
uint32_t CardScript_Cocoon(int spell_id,int target_id,int flags);;

/* Function at 004ccb93 (Size: 123 bytes) */
void CardScript_Burrowing(int spell_id,int target_id,int flags);;

/* Function at 004ccc0e (Size: 1313 bytes) */
int32_t CardScript_Wanderlust(int spell_id,int target_id,int flags);;

/* Function at 004cd134 (Size: 2364 bytes) */
int32_t CardScript_InstillEnergy(int spell_id,int target_id,int flags);;

/* Function at 004cda70 (Size: 811 bytes) */
int32_t CardScript_Flood(int spell_id,int target_id,int flags);;

/* Function at 004cdd9b (Size: 212 bytes) */
int32_t FUN_004cdd9b(int max_val,int point,int hBitmap);;

/* Function at 004cde6f (Size: 366 bytes) */
int32_t FUN_004cde6f(int max_val,int point,int hBitmap);;

/* Function at 004cdfdd (Size: 77 bytes) */
int32_t FUN_004cdfdd(int max_val,int point,int hBitmap);;

/* Function at 004ce02a (Size: 512 bytes) */
int32_t Pic_Subsystem_0043b224(int max_val,int point,int hBitmap);;

/* Function at 004ce22a (Size: 710 bytes) */
int32_t Pic_Subsystem_0043b424(int max_val,int point,int hBitmap);;

/* Function at 004ce4f0 (Size: 99 bytes) */
void CardScript_Lance(int spell_id,int target_id,int flags);;

/* Function at 004ce553 (Size: 123 bytes) */
void CardScript_FishliverOil(int spell_id,int target_id,int flags);;

/* Function at 004ce5ce (Size: 677 bytes) */
void FUN_004ce5ce(int x,int y,int width,uint32_t height);;

/* Function at 004ce873 (Size: 98 bytes) */
void CardScript_HolyStrength(int spell_id,int target_id,int flags);;

/* Function at 004ce8d5 (Size: 98 bytes) */
void CardScript_GiantStrength(int spell_id,int target_id,int flags);;

/* Function at 004ce937 (Size: 97 bytes) */
void CardScript_Immolation(int spell_id,int target_id,int flags);;

/* Function at 004ce998 (Size: 98 bytes) */
void CardScript_DivineTransformation(int spell_id,int target_id,int flags);;

/* Function at 004ce9fa (Size: 98 bytes) */
void CardScript_UnholyStrength(int spell_id,int target_id,int flags);;

/* Function at 004cea5c (Size: 98 bytes) */
void CardScript_Weakness(int spell_id,int target_id,int flags);;

/* Function at 004ceabe (Size: 1006 bytes) */
int32_t FUN_004ceabe(uint32_t max_val,int point,int hBitmap,int flags,int damage);;

/* Function at 004ceeb6 (Size: 194 bytes) */
int32_t FUN_004ceeb6(int max_val,int point,int hBitmap);;

/* Function at 004cef78 (Size: 55 bytes) */
void FUN_004cef78(int max_val,int point,int hBitmap);;

/* Function at 004cefaf (Size: 55 bytes) */
void FUN_004cefaf(int max_val,int point,int hBitmap);;

/* Function at 004cefe6 (Size: 55 bytes) */
void FUN_004cefe6(int max_val,int point,int hBitmap);;

/* Function at 004cf01d (Size: 55 bytes) */
void FUN_004cf01d(int max_val,int point,int hBitmap);;

/* Function at 004cf054 (Size: 55 bytes) */
void FUN_004cf054(int max_val,int point,int hBitmap);;

/* Function at 004cf08b (Size: 1644 bytes) */
int32_t CardScript_AnyWard(int spell_id,int target_id,int flags,int height);;

/* Function at 004cf6f7 (Size: 2249 bytes) */
int32_t CardScript_UnstableMutation(int spell_id,int target_id,int flags);;

/* Function at 004cffc5 (Size: 2124 bytes) */
int32_t CardScript_CopyArtifact(int spell_id,int target_id,int flags);;

/* Function at 004d0811 (Size: 1447 bytes) */
int32_t CardScript_TargetArtifact(int spell_id,int target_id,int flags);;

/* Function at 004d0dbd (Size: 309 bytes) */
int32_t Pic_Subsystem_0043dfbb(int max_val,int point,int hBitmap);;

/* Function at 004d0ef2 (Size: 1696 bytes) */
int32_t Pic_Subsystem_0043e0f6(int max_val,int point,int hBitmap);;

/* Function at 004d1597 (Size: 1054 bytes) */
int32_t FUN_004d1597(int max_val,int point,int hBitmap);;

/* Function at 004d19ba (Size: 1503 bytes) */
int32_t CardScript_Regeneration(int spell_id,int target_id,int flags);;

/* Function at 004d1f99 (Size: 895 bytes) */
int32_t CardScript_EternalWarrior(int spell_id,int target_id,int flags);;

/* Function at 004d2318 (Size: 1498 bytes) */
int32_t CardScript_TheBrute(int spell_id,int target_id,int flags);;

/* Function at 004d28f2 (Size: 639 bytes) */
uint32_t CardScript_Earthbind(int spell_id,int target_id,int flags);;

/* Function at 004d2b76 (Size: 55 bytes) */
void FUN_004d2b76(int max_val,int point,int hBitmap);;

/* Function at 004d2bad (Size: 55 bytes) */
void FUN_004d2bad(int max_val,int point,int hBitmap);;

/* Function at 004d2be4 (Size: 55 bytes) */
void FUN_004d2be4(int max_val,int point,int hBitmap);;

/* Function at 004d2c1b (Size: 55 bytes) */
void FUN_004d2c1b(int max_val,int point,int hBitmap);;

/* Function at 004d2c52 (Size: 55 bytes) */
void FUN_004d2c52(int max_val,int point,int hBitmap);;

/* Function at 004d2c89 (Size: 1014 bytes) */
int32_t CardScript_CircleOfProtection(int spell_id,int target_id,int flags,int height);;

/* Function at 004d3084 (Size: 1028 bytes) */
int32_t CardScript_CircleOfProtection(int spell_id,int target_id,int flags);;

/* Function at 004d3488 (Size: 1213 bytes) */
int32_t CardScript_PhantasmalTerrain(int spell_id,int target_id,int flags);;

/* Function at 004d3945 (Size: 620 bytes) */
int32_t FUN_004d3945(int max_val,int point,int hBitmap);;

/* Function at 004d3bb1 (Size: 946 bytes) */
int32_t CardScript_WildGrowth(int spell_id,int target_id,int flags);;

/* Function at 004d3f63 (Size: 885 bytes) */
int32_t CardScript_Flight(int spell_id,int target_id,int flags);;

/* Function at 004d42d8 (Size: 686 bytes) */
int32_t FUN_004d42d8(int max_val,int point,int hBitmap);;

/* Function at 004d458b (Size: 686 bytes) */
int32_t FUN_004d458b(int max_val,int point,int hBitmap);;

/* Function at 004d483e (Size: 1481 bytes) */
int FUN_004d483e(int player,int card_slot);;

/* Function at 004d4e10 (Size: 46 bytes) */
int32_t Mem_AllocOrFree_004d4e10(void);;

/* Function at 004d4e3e (Size: 5412 bytes) */
int32_t Deck_LoadOneDeckProfile(int32_t player,int card_slot);;

/* Function at 004d6362 (Size: 302 bytes) */
void FUN_004d6362(int32_t *max_val,int32_t *point,int32_t *hBitmap);;

/* Function at 004d6490 (Size: 310 bytes) */
void FUN_004d6490(int player,int card_slot);;

/* Function at 004d65c6 (Size: 39 bytes) */
void FUN_004d65c6(DWORD max_val);;

/* Function at 004d65f2 (Size: 71 bytes) */
void FUN_004d65f2(int max_val,int *point,int hBitmap,int flags,int32_t damage,int arg_6,int32_t arg_7);;

/* Function at 004d6639 (Size: 797 bytes) */
int Palette_Subsystem_004a5722(int max_val,int *out_buffer,int hBitmap,int32_t flags,int damage,int32_t arg_6);;

/* Function at 004d695b (Size: 186 bytes) */
int Deck_AddCardToDeck(int player,int card_slot);;

/* Function at 004d6a15 (Size: 1837 bytes) */
void FUN_004d6a15(int max_val,int point,int hBitmap);;

/* Function at 004d714c (Size: 154 bytes) */
int32_t FUN_004d714c(void);;

/* Function at 004d71e6 (Size: 412 bytes) */
int FUN_004d71e6(int player,int card_slot);;

/* Function at 004d7382 (Size: 222 bytes) */
uint32_t FUN_004d7382(void);;

/* Function at 004d7460 (Size: 176 bytes) */
int FUN_004d7460(uint32_t player,uint32_t card_slot);;

/* Function at 004d7510 (Size: 461 bytes) */
int Ai_Subsystem_004cc1e8(uint32_t max_val);;

/* Function at 004d76dd (Size: 88 bytes) */
void FUN_004d76dd(uint32_t max_val);;

/* Function at 004d7735 (Size: 77 bytes) */
void FUN_004d7735(int max_val);;

/* Function at 004d7782 (Size: 244 bytes) */
void FUN_004d7782(void);;

/* Function at 004d7876 (Size: 208 bytes) */
int32_t FUN_004d7876(int max_val,int point,int hBitmap);;

/* Function at 004d7946 (Size: 390 bytes) */
void FUN_004d7946(int max_val);;

/* Function at 004d7acc (Size: 97 bytes) */
void FUN_004d7acc(int player,int card_slot);;

/* Function at 004d7b2d (Size: 125 bytes) */
int FUN_004d7b2d(int player,int32_t card_slot);;

/* Function at 004d7baa (Size: 118 bytes) */
void FUN_004d7baa(int player,int32_t card_slot);;

/* Function at 004d7c20 (Size: 318 bytes) */
int File_Load_Info(int max_val);;

/* Function at 004d7d5e (Size: 121 bytes) */
int Card_IsValidCardId(int max_val);;

/* Function at 004d7dd7 (Size: 82 bytes) */
void FUN_004d7dd7(int32_t max_val);;

/* Function at 004d7e29 (Size: 57 bytes) */
void FUN_004d7e29(uint8_t *max_val);;

/* Function at 004d7e62 (Size: 67 bytes) */
void FUN_004d7e62(int32_t max_val);;

/* Function at 004d7ea5 (Size: 11 bytes) */
void Mem_AllocOrFree_004d7ea5(void);;

/* Function at 004d7eb0 (Size: 27 bytes) */
void Mem_AllocOrFree_004d7eb0(void);;

/* Function at 004d7ecb (Size: 141 bytes) */
int FUN_004d7ecb(void);;

/* Function at 004d7f60 (Size: 88 bytes) */
void FUN_004d7f60(undefined8 *player,uint32_t card_slot);;

/* Function at 004d7fb8 (Size: 444 bytes) */
int FUN_004d7fb8(uint8_t *max_val,int32_t point,int32_t hBitmap);;

/* Function at 004d8174 (Size: 771 bytes) */
int32_t FUN_004d8174(int max_val);;

/* Function at 004d8477 (Size: 372 bytes) */
int FUN_004d8477(int32_t *max_val,int32_t point,int32_t hBitmap);;

/* Function at 004d85eb (Size: 280 bytes) */
int FUN_004d85eb(int32_t max_val,int32_t point,int32_t hBitmap);;

/* Function at 004d8703 (Size: 848 bytes) */
int32_t FUN_004d8703(int max_val);;

/* Function at 004d8a53 (Size: 411 bytes) */
int32_t FUN_004d8a53(int max_val);;

/* Function at 004d8bee (Size: 272 bytes) */
int FUN_004d8bee(int32_t *max_val,int32_t point,int32_t hBitmap);;

/* Function at 004d8cfe (Size: 653 bytes) */
int FUN_004d8cfe(undefined8 *max_val,uint32_t *point,int32_t hBitmap);;

/* Function at 004d8f90 (Size: 221 bytes) */
uint32_t FUN_004d8f90(uint32_t max_val);;

/* Function at 004d9080 (Size: 137 bytes) */
uint32_t FUN_004d9080(void);;

/* Function at 004d910a (Size: 6 bytes) */
void MCIWndCreateA(void);;

/* Function at 004d95f0 (Size: 6 bytes) */
BOOL GetOpenFileNameA(LPOPENFILENAMEA max_val);;

/* Function at 004d95f6 (Size: 6 bytes) */
BOOL GetSaveFileNameA(LPOPENFILENAMEA max_val);;

/* Function at 004d9626 (Size: 6 bytes) */
void DeckBuilderMain(void);;

/* Function at 004d9630 (Size: 7 bytes) */
uint32_t * Mem_AllocOrFree_004d9630(uint32_t *player,uint32_t *card_slot);;

/* Function at 004d9640 (Size: 224 bytes) */
uint32_t * Str_CopyFast(uint32_t *player, uint32_t *card_slot);;

/* Function at 004d9720 (Size: 236 bytes) */
int __cdecl _sprintf(char *str_1,char *str_2,...);;

/* Function at 004d9810 (Size: 24 bytes) */
int Mem_AllocOrFree_004d9810(uint32_t max_val);;

/* Function at 004d9830 (Size: 19 bytes) */
void Mem_AllocOrFree_004d9830(int32_t max_val);;

/* Function at 004d9850 (Size: 65 bytes) */
int __cdecl _rand(void);;

/* Function at 004d98a0 (Size: 123 bytes) */
size_t __cdecl _strlen(char *str_1);;

/* Function at 004d9920 (Size: 129 bytes) */
int __cdecl _strcmp(char *str_1,char *str_2);;

/* Function at 004d99b0 (Size: 285 bytes) */
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t hBitmap);;

/* Function at 004d9b00 (Size: 56 bytes) */
int __cdecl _strncmp(char *str_1,char *str_2,size_t hBitmap);;

/* Function at 004d9b40 (Size: 282 bytes) */
long __cdecl _atol(char *str_1);;

/* Function at 004d9c60 (Size: 28 bytes) */
int __cdecl _atoi(char *str_1);;

/* Function at 004d9c80 (Size: 324 bytes) */
longlong __cdecl __atoi64(char *str_1);;

/* Function at 004d9dd0 (Size: 951 bytes) */
void __assert(uint32_t *max_val,uint32_t *point,int hBitmap);;

/* Function at 004da190 (Size: 88 bytes) */
void * __cdecl _memset(void *ptr_1,int point,size_t hBitmap);;

/* Function at 004da1f0 (Size: 66 bytes) */
int __cdecl __cinit(int max_val);;

/* Function at 004da240 (Size: 27 bytes) */
void __cdecl _exit(int max_val);;

/* Function at 004da260 (Size: 27 bytes) */
void __exit(UINT max_val);;

/* Function at 004da280 (Size: 25 bytes) */
void __cdecl __cexit(void);;

/* Function at 004da2a0 (Size: 25 bytes) */
void __cdecl __c_exit(void);;

/* Function at 004da2c0 (Size: 251 bytes) */
void __cdecl doexit(UINT max_val,int point,int hBitmap);;

/* Function at 004da3c0 (Size: 49 bytes) */
void __initterm(int *player,int *card_slot);;

/* Function at 004da400 (Size: 456 bytes) */
size_t __cdecl _fread(void *ptr_1,size_t point,size_t hBitmap,FILE *fp);;

/* Function at 004da5d0 (Size: 40 bytes) */
void * __cdecl _malloc(size_t max_val);;

/* Function at 004da600 (Size: 46 bytes) */
void __malloc_dbg(size_t max_val,int32_t point,int32_t hBitmap,int32_t flags);;

/* Function at 004da630 (Size: 38 bytes) */
void * __cdecl __nh_malloc(size_t max_val,int point);;

/* Function at 004da660 (Size: 101 bytes) */
int __nh_malloc_dbg(size_t max_val,int point,uint32_t hBitmap,int flags,int32_t damage);;

/* Function at 004da6d0 (Size: 34 bytes) */
void * __cdecl __heap_alloc(size_t max_val);;

/* Function at 004da700 (Size: 818 bytes) */
int32_t * __heap_alloc_dbg(uint32_t x,uint32_t y,int width,int32_t flags);;

/* Function at 004daa40 (Size: 38 bytes) */
void * __cdecl _calloc(size_t max_val,size_t point);;

/* Function at 004daa70 (Size: 110 bytes) */
uint8_t * __calloc_dbg(int max_val,int point,int32_t hBitmap,int32_t flags,int32_t damage);;

/* Function at 004daae0 (Size: 38 bytes) */
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t point);;

/* Function at 004dab10 (Size: 55 bytes) */
int32_t __realloc_dbg(int max_val,uint32_t point,uint32_t hBitmap,int flags,int damage);;

/* Function at 004dab50 (Size: 1409 bytes) */
int * __cdecl realloc_help(int max_val,uint32_t point,uint32_t hBitmap,int flags,int damage,int arg_6);;

/* Function at 004db0e0 (Size: 38 bytes) */
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t point);;

/* Function at 004db110 (Size: 55 bytes) */
int32_t __expand_dbg(int max_val,uint32_t point,uint32_t hBitmap,int flags,int damage);;

/* Function at 004db150 (Size: 25 bytes) */
void FUN_004db150(void *max_val);;

/* Function at 004db170 (Size: 1057 bytes) */
void __free_dbg(void *player,int card_slot);;

/* Function at 004db5a0 (Size: 30 bytes) */
size_t __cdecl __msize(void *ptr_1);;

/* Function at 004db5c0 (Size: 358 bytes) */
int32_t __msize_dbg(int player,int card_slot);;

/* Function at 004db730 (Size: 38 bytes) */
int32_t Mem_AllocOrFree_004db730(int32_t max_val);;

/* Function at 004db760 (Size: 160 bytes) */
void __CrtSetDbgBlockType(int player,int32_t card_slot);;

/* Function at 004db800 (Size: 38 bytes) */
uint8_t * Mem_AllocOrFree_004db800(uint8_t *max_val);;

/* Function at 004db830 (Size: 140 bytes) */
int32_t _CheckBytes(char *str_1,char point,int hBitmap);;

/* Function at 004db8c0 (Size: 873 bytes) */
int32_t __CrtCheckMemory(void);;

/* Function at 004dbc40 (Size: 48 bytes) */
int __CrtSetDbgFlag(int max_val);;

/* Function at 004dbc70 (Size: 105 bytes) */
void __CrtDoForAllClientObjects(uint8_t *player,int32_t card_slot);;

/* Function at 004dbce0 (Size: 92 bytes) */
int32_t __CrtIsValidPointer(void *max_val,UINT_PTR point,int hBitmap);;

/* Function at 004dbd40 (Size: 182 bytes) */
BOOL __CrtIsValidHeapPointer(int max_val);;

/* Function at 004dbe10 (Size: 255 bytes) */
int32_t __CrtIsMemoryBlock(void *max_val,UINT_PTR point,int32_t *hBitmap,int32_t *flags,int32_t *damage);;

/* Function at 004dbf10 (Size: 38 bytes) */
int32_t Mem_AllocOrFree_004dbf10(int32_t max_val);;

/* Function at 004dbf40 (Size: 316 bytes) */
void __CrtMemCheckpoint(int32_t *max_val);;

/* Function at 004dc080 (Size: 312 bytes) */
int32_t __CrtMemDifference(int32_t *max_val,int point,int hBitmap);;

/* Function at 004dc1c0 (Size: 704 bytes) */
void __CrtMemDumpAllObjectsSince(int32_t *max_val);;

/* Function at 004dc480 (Size: 252 bytes) */
void __printMemBlockData(int max_val);;

/* Function at 004dc580 (Size: 132 bytes) */
int32_t __CrtDumpMemoryLeaks(void);;

/* Function at 004dc610 (Size: 199 bytes) */
void __CrtMemDumpStatistics(int max_val);;

/* Function at 004dc6e0 (Size: 258 bytes) */
FILE * __cdecl __fsopen(char *filename,char *str_2,int hBitmap);;

/* Function at 004dc7f0 (Size: 34 bytes) */
FILE * __cdecl _fopen(char *filename,char *str_2);;

/* Function at 004dc820 (Size: 237 bytes) */
int __cdecl _fclose(FILE *fp);;

/* Function at 004dc910 (Size: 277 bytes) */
void * __cdecl _bsearch(void *ptr_1,void *out_buffer,size_t hBitmap,size_t flags,_PtFuncCompare *ptr_5);;

/* Function at 004dca30 (Size: 304 bytes) */
int __cdecl _fseek(FILE *fp,long point,int hBitmap);;

/* Function at 004dcb60 (Size: 578 bytes) */
void __cdecl __splitpath(char *str_1,char *str_2,char *str_3,char *str_4,char *str_5);;

/* Function at 004dcdb0 (Size: 301 bytes) */
char * __cdecl _fgets(char *str_1,int point,FILE *fp);;

/* Function at 004dcee0 (Size: 139 bytes) */
int __cdecl _fscanf(FILE *fp,char *str_2,...);;

/* Function at 004dcf80 (Size: 193 bytes) */
char * __cdecl _strchr(char *str_1,int point);;

/* Function at 004dd040 (Size: 193 bytes) */
int __cdecl _sscanf(char *str_1,char *str_2,...);;

/* Function at 004dd110 (Size: 62 bytes) */
size_t __cdecl _strspn(char *str_1,char *str_2);;

/* Function at 004dd150 (Size: 62 bytes) */
size_t __cdecl _strcspn(char *str_1,char *str_2);;

/* Function at 004dd190 (Size: 94 bytes) */
int __cdecl FID_conflict:__mkdir(char *str_1);;

/* Function at 004dd1f0 (Size: 126 bytes) */
int __cdecl _fgetc(FILE *fp);;

/* Function at 004dd270 (Size: 28 bytes) */
int __cdecl _getc(FILE *fp);;

/* Function at 004dd290 (Size: 67 bytes) */
int __cdecl __open(char *filename,int point,...);;

/* Function at 004dd2e0 (Size: 1355 bytes) */
int __cdecl __sopen(char *filename,int point,int hBitmap,...);;

/* Function at 004dd880 (Size: 267 bytes) */
int __cdecl __close(int max_val);;

/* Function at 004dd990 (Size: 1156 bytes) */
int __cdecl __read(int max_val,void *out_buffer,uint32_t hBitmap);;

/* Function at 004dde30 (Size: 172 bytes) */
int __cdecl _memcmp(void *ptr_1,void *ptr_2,size_t hBitmap);;

/* Function at 004ddee0 (Size: 47 bytes) */
void Mem_AllocOrFree_004ddee0(void);;

/* Function at 004ddf10 (Size: 536 bytes) */
size_t __cdecl FID_conflict:__fwrite_lk(void *ptr_1,size_t point,size_t hBitmap,FILE *fp);;

/* Function at 004de130 (Size: 39 bytes) */
char * __cdecl _strrchr(char *str_1,int point);;

/* Function at 004de160 (Size: 182 bytes) */
int __cdecl __isctype(int player,int card_slot);;

/* Function at 004de220 (Size: 31 bytes) */
longlong __fastcall __allshl(uint8_t player,int card_slot);;

/* Function at 004de240 (Size: 674 bytes) */
long __cdecl _ftell(FILE *fp);;

/* Function at 004de4f0 (Size: 176 bytes) */
int __cdecl _fprintf(FILE *fp,char *str_2,...);;

/* Function at 004de5a0 (Size: 63 bytes) */
char * __cdecl _ctime(time_t *ptr_1);;

/* Function at 004de5f0 (Size: 390 bytes) */
time_t __cdecl _time(time_t *ptr_1);;

/* Function at 004de780 (Size: 229 bytes) */
int __cdecl __vsnprintf(char *str_1,size_t point,char *str_3,va_list flags);;

/* Function at 004de870 (Size: 254 bytes) */
char * __cdecl _strncpy(char *str_1,char *str_2,size_t hBitmap);;

/* Function at 004de970 (Size: 38 bytes) */
void __cdecl __fpmath(int max_val);;

/* Function at 004de9a0 (Size: 16 bytes) */
void Mem_AllocOrFree_004de9a0(void);;

/* Function at 004de9b0 (Size: 71 bytes) */
void __cfltcvt_init(void);;

/* Function at 004dea00 (Size: 38 bytes) */
int32_t Mem_AllocOrFree_004dea00(int32_t max_val);;

/* Function at 004dea30 (Size: 494 bytes) */
void entry(void);;

/* Function at 004dec80 (Size: 55 bytes) */
void __cdecl __amsg_exit(int max_val);;

/* Function at 004decc0 (Size: 660 bytes) */
int __cdecl __flsbuf(int player,FILE *card_slot);;

/* Function at 004def60 (Size: 3177 bytes) */
int __output(FILE *max_val,uint8_t *point,int32_t *hBitmap);;

/* Function at 004dfcf0 (Size: 117 bytes) */
void __cdecl write_char(int max_val,FILE *fp,int *hBitmap);;

/* Function at 004dfd70 (Size: 75 bytes) */
void __cdecl write_multi_char(int x,int y,FILE *fp,int *height);;

/* Function at 004dfdc0 (Size: 87 bytes) */
void __cdecl write_string(char *str_1,int y,FILE *fp,int *height);;

/* Function at 004dfe20 (Size: 30 bytes) */
int32_t __cdecl get_int_arg(int *max_val);;

/* Function at 004dfe40 (Size: 35 bytes) */
undefined8 __cdecl get_int64_arg(int *max_val);;

/* Function at 004dfe70 (Size: 31 bytes) */
int32_t __cdecl get_short_arg(int *max_val);;

/* Function at 004dfe90 (Size: 17 bytes) */
void __CrtDbgBreak(void);;

/* Function at 004dfeb0 (Size: 126 bytes) */
int32_t __CrtSetReportMode(int player,uint32_t card_slot);;

/* Function at 004dff30 (Size: 169 bytes) */
int32_t __CrtSetReportFile(int player,int card_slot);;

/* Function at 004dffe0 (Size: 38 bytes) */
int32_t Mem_AllocOrFree_004dffe0(int32_t max_val);;

/* Function at 004e0010 (Size: 998 bytes) */
int32_t __CrtDbgReport(int max_val,int point,int hBitmap,int32_t flags,char *str_5);;

/* Function at 004e0400 (Size: 813 bytes) */
bool _CrtMessageWindow(void);;

/* Function at 004e0730 (Size: 52 bytes) */
longlong __allmul(uint32_t x,int y,uint32_t width,int height);;

/* Function at 004e0770 (Size: 41 bytes) */
void __cdecl _abort(void);;

/* Function at 004e07a0 (Size: 432 bytes) */
void __cdecl _signal(int max_val);;

/* Function at 004e0980 (Size: 136 bytes) */
int32_t ctrlevent_capture(int max_val);;

/* Function at 004e0a10 (Size: 475 bytes) */
int __cdecl _raise(int max_val);;

/* Function at 004e0c30 (Size: 99 bytes) */
int32_t * __cdecl siglookup(int max_val);;

/* Function at 004e0ca0 (Size: 223 bytes) */
int __cdecl ___crtMessageBoxA(LPCSTR max_val,LPCSTR point,UINT hBitmap);;

/* Function at 004e0d80 (Size: 291 bytes) */
char * __cdecl _strncat(char *str_1,char *str_2,size_t hBitmap);;

/* Function at 004e0eb0 (Size: 88 bytes) */
char * __cdecl __itoa(int max_val,char *str_2,int hBitmap);;

/* Function at 004e0f10 (Size: 181 bytes) */
void __cdecl xtoa(uint32_t x,char *str_2,uint32_t width,int height);;

/* Function at 004e0fd0 (Size: 85 bytes) */
char * __cdecl __ltoa(long max_val,char *str_2,int hBitmap);;

/* Function at 004e1030 (Size: 41 bytes) */
char * __cdecl __ultoa(uint32_t max_val,char *str_2,int hBitmap);;

/* Function at 004e1060 (Size: 102 bytes) */
char * __cdecl __i64toa(longlong max_val,char *str_2,int hBitmap);;

/* Function at 004e10d0 (Size: 216 bytes) */
void x64toa(uint32_t max_val,uint32_t point,char *str_3,uint32_t flags,int damage);;

/* Function at 004e11b0 (Size: 42 bytes) */
char * __cdecl __ui64toa(ulonglong max_val,char *str_2,int hBitmap);;

/* Function at 004e11e0 (Size: 126 bytes) */
int __cdecl _fflush(FILE *fp);;

/* Function at 004e1260 (Size: 186 bytes) */
int __cdecl __flush(FILE *fp);;

/* Function at 004e1320 (Size: 26 bytes) */
int __cdecl __flushall(void);;

/* Function at 004e1340 (Size: 247 bytes) */
int __cdecl flsall(int max_val);;

/* Function at 004e1440 (Size: 338 bytes) */
void ___initstdio(void);;

/* Function at 004e15a0 (Size: 36 bytes) */
void ___endstdio(void);;

/* Function at 004e15d0 (Size: 347 bytes) */
int __cdecl _setvbuf(FILE *x,char *y,int width,size_t height);;

/* Function at 004e1730 (Size: 479 bytes) */
int __cdecl __filbuf(FILE *fp);;

/* Function at 004e1910 (Size: 38 bytes) */
int32_t Mem_AllocOrFree_004e1910(int32_t max_val);;

/* Function at 004e1940 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_004e1940(void);;

/* Function at 004e1960 (Size: 62 bytes) */
int __cdecl __callnewh(size_t max_val);;

/* Function at 004e19a0 (Size: 34 bytes) */
void __malloc_base(uint32_t max_val);;

/* Function at 004e19d0 (Size: 150 bytes) */
int __nh_malloc_base(uint32_t player,int card_slot);;

/* Function at 004e1a70 (Size: 99 bytes) */
LPVOID __heap_alloc_base(int max_val);;

/* Function at 004e1ae0 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_004e1ae0(void);;

/* Function at 004e1b00 (Size: 195 bytes) */
LPVOID __expand_base(LPVOID player,uint32_t card_slot);;

/* Function at 004e1bd0 (Size: 518 bytes) */
void * __realloc_base(void *player,uint32_t card_slot);;

/* Function at 004e1de0 (Size: 105 bytes) */
void __free_base(LPVOID max_val);;

/* Function at 004e1e50 (Size: 120 bytes) */
int __cdecl __heapchk(void);;

/* Function at 004e1ed0 (Size: 21 bytes) */
int __cdecl __heapset(uint32_t max_val);;

/* Function at 004e1ef0 (Size: 93 bytes) */
int __cdecl __heap_init(void);;

/* Function at 004e1f50 (Size: 93 bytes) */
void __cdecl __heap_term(void);;

/* Function at 004e1fb0 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_004e1fb0(void);;

/* Function at 004e1fd0 (Size: 61 bytes) */
bool __set_sbh_threshold(int max_val);;

/* Function at 004e2020 (Size: 508 bytes) */
uint8_t ** ___sbh_new_region(void);;

/* Function at 004e2230 (Size: 132 bytes) */
void ___sbh_release_region(uint8_t **max_val);;

/* Function at 004e22c0 (Size: 376 bytes) */
void ___sbh_decommit_pages(int max_val);;

/* Function at 004e2440 (Size: 162 bytes) */
int ___sbh_find_block(uint8_t *max_val,int32_t *point,uint32_t *hBitmap);;

/* Function at 004e24f0 (Size: 136 bytes) */
void ___sbh_free_block(int max_val,int point,char *str_3);;

/* Function at 004e2580 (Size: 1207 bytes) */
uint8_t * ___sbh_alloc_block(uint32_t max_val);;

/* Function at 004e2a50 (Size: 763 bytes) */
int ___sbh_alloc_block_from_page(int *max_val,uint32_t point,uint32_t hBitmap);;

/* Function at 004e2d50 (Size: 439 bytes) */
int32_t ___sbh_resize_block(int x,int32_t *point,uint8_t *hBitmap,uint32_t height);;

/* Function at 004e2f10 (Size: 617 bytes) */
int32_t ___sbh_heap_check(void);;

/* Function at 004e3180 (Size: 831 bytes) */
FILE * __cdecl __openfile(char *x,char *y,int width,FILE *height);;

/* Function at 004e3540 (Size: 274 bytes) */
FILE * __cdecl __getstream(void);;

/* Function at 004e3660 (Size: 138 bytes) */
void __cdecl __freebuf(FILE *fp);;

/* Function at 004e36f0 (Size: 285 bytes) */
long __cdecl __lseek(int max_val,long point,int hBitmap);;

/* Function at 004e3810 (Size: 277 bytes) */
uchar * __cdecl __mbsnbcpy(uchar *str_1,uchar *str_2,size_t hBitmap);;

/* Function at 004e3930 (Size: 815 bytes) */
int __cdecl __setmbcp(int max_val);;

/* Function at 004e3c60 (Size: 121 bytes) */
UINT __cdecl getSystemCP(UINT max_val);;

/* Function at 004e3cf0 (Size: 107 bytes) */
int32_t _CPtoLCID(int32_t max_val);;

/* Function at 004e3d90 (Size: 120 bytes) */
void __cdecl setSBCS(void);;

/* Function at 004e3e10 (Size: 21 bytes) */
int32_t Mem_AllocOrFree_004e3e10(void);;

/* Function at 004e3e30 (Size: 21 bytes) */
void ___initmbctable(void);;

/* Function at 004e3e50 (Size: 4808 bytes) */
uint32_t __input(int max_val,uint8_t *point,int32_t *hBitmap);;

/* Function at 004e5200 (Size: 102 bytes) */
uint32_t __hextodec(uint32_t max_val);;

/* Function at 004e5270 (Size: 79 bytes) */
uint32_t __inc(FILE *fp);;

/* Function at 004e52c0 (Size: 37 bytes) */
void __un_inc(int player,FILE *fp);;

/* Function at 004e52f0 (Size: 67 bytes) */
int __whiteout(int *player,FILE *fp);;

/* Function at 004e5340 (Size: 177 bytes) */
void __cdecl __dosmaperr(uint32_t max_val);;

/* Function at 004e5400 (Size: 808 bytes) */
int __cdecl __ioinit(void);;

/* Function at 004e5730 (Size: 104 bytes) */
void __cdecl __ioterm(void);;

/* Function at 004e57a0 (Size: 675 bytes) */
int __cdecl __chsize(int player,long card_slot);;

/* Function at 004e5a50 (Size: 333 bytes) */
int __cdecl __alloc_osfhnd(void);;

/* Function at 004e5ba0 (Size: 234 bytes) */
int __cdecl __set_osfhnd(int player,intptr_t card_slot);;

/* Function at 004e5ca0 (Size: 263 bytes) */
int __cdecl __free_osfhnd(int max_val);;

/* Function at 004e5dc0 (Size: 118 bytes) */
intptr_t __cdecl __get_osfhandle(int max_val);;

/* Function at 004e5e40 (Size: 256 bytes) */
int __cdecl __open_osfhandle(intptr_t player,int card_slot);;

/* Function at 004e5f40 (Size: 744 bytes) */
int __cdecl __write(int max_val,void *ptr_2,uint32_t hBitmap);;

/* Function at 004e6240 (Size: 607 bytes) */
void ___crtGetStringTypeW(DWORD max_val,LPCWSTR point,int hBitmap,LPWORD flags,UINT damage,LCID arg_6);;

/* Function at 004e64a0 (Size: 406 bytes) */
BOOL __cdecl ___crtGetStringTypeA(_locale_t max_val,DWORD point,LPCSTR hBitmap,int flags,LPWORD damage,int arg_6,BOOL arg_7);;

/* Function at 004e6640 (Size: 330 bytes) */
int __cdecl __stbuf(FILE *fp);;

/* Function at 004e6790 (Size: 182 bytes) */
void __cdecl __ftbuf(int player,FILE *card_slot);;

/* Function at 004e6850 (Size: 345 bytes) */
char * __cdecl _asctime(tm *ptr_1);;

/* Function at 004e69b0 (Size: 63 bytes) */
char * __cdecl store_dt(char *str_1,int card_slot);;

/* Function at 004e69f0 (Size: 597 bytes) */
tm * __cdecl _localtime(time_t *ptr_1);;

/* Function at 004e6c50 (Size: 274 bytes) */
int ___loctotime_t(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int arg_7);;

/* Function at 004e6d70 (Size: 29 bytes) */
void __setdefaultprecision(void);;

/* Function at 004e6d90 (Size: 94 bytes) */
int32_t __ms_p5_test_fdiv(void);;

/* Function at 004e6df0 (Size: 86 bytes) */
void __ms_p5_mp_test_fdiv(void);;

/* Function at 004e6e50 (Size: 179 bytes) */
void __cdecl __forcdecpt(char *str_1);;

/* Function at 004e6f10 (Size: 223 bytes) */
void __cdecl __cropzeros(char *str_1);;

/* Function at 004e6ff0 (Size: 50 bytes) */
int __cdecl __positive(double *ptr_1);;

/* Function at 004e7030 (Size: 83 bytes) */
void __cdecl __fassign(int max_val,char *str_2,char *str_3);;

/* Function at 004e7090 (Size: 458 bytes) */
errno_t __cdecl __cftoe(double *ptr_1,char *str_2,size_t hBitmap,int flags,int damage);;

/* Function at 004e7260 (Size: 393 bytes) */
errno_t __cdecl __cftof(double *x,char *y,size_t width,int height);;

/* Function at 004e73f0 (Size: 281 bytes) */
void __cftog(int32_t *max_val,int y,size_t hBitmap,int flags);;

/* Function at 004e7510 (Size: 63 bytes) */
errno_t __cftoe_g(double *max_val,char *str_2,size_t hBitmap,int height);;

/* Function at 004e7550 (Size: 59 bytes) */
errno_t __cftof_g(double *max_val,char *str_2,size_t hBitmap);;

/* Function at 004e7590 (Size: 119 bytes) */
errno_t __cdecl __cfltcvt(double *ptr_1,char *str_2,size_t hBitmap,int flags,int damage,int arg_6);;

/* Function at 004e7610 (Size: 54 bytes) */
void __shift(char *str_1,int card_slot);;

/* Function at 004e7648 (Size: 32 bytes) */
void __global_unwind2(PVOID max_val);;

/* Function at 004e768a (Size: 104 bytes) */
void __local_unwind2(int player,int card_slot);;

/* Function at 004e771e (Size: 24 bytes) */
void Mem_AllocOrFree_004e771e(void);;

/* Function at 004e7740 (Size: 500 bytes) */
int __cdecl __XcptFilter(uint32_t card_id,_EXCEPTION_POINTERS *out_filter);;

/* Function at 004e7940 (Size: 97 bytes) */
int * __cdecl xcptlookup(int max_val);;

/* Function at 004e79b0 (Size: 32 bytes) */
int __cdecl __ismbbkalnum(uint32_t max_val);;

/* Function at 004e79d0 (Size: 32 bytes) */
int __cdecl __ismbbkprint(uint32_t max_val);;

/* Function at 004e79f0 (Size: 32 bytes) */
int __cdecl __ismbbkpunct(uint32_t max_val);;

/* Function at 004e7a10 (Size: 35 bytes) */
int __cdecl __ismbbalnum(uint32_t max_val);;

/* Function at 004e7a40 (Size: 35 bytes) */
int __cdecl __ismbbalpha(uint32_t max_val);;

/* Function at 004e7a70 (Size: 35 bytes) */
int __cdecl __ismbbgraph(uint32_t max_val);;

/* Function at 004e7aa0 (Size: 35 bytes) */
int __cdecl __ismbbprint(uint32_t max_val);;

/* Function at 004e7ad0 (Size: 32 bytes) */
int __cdecl __ismbbpunct(uint32_t max_val);;

/* Function at 004e7af0 (Size: 32 bytes) */
int __cdecl __ismbblead(uint32_t max_val);;

/* Function at 004e7b10 (Size: 32 bytes) */
int __cdecl __ismbbtrail(uint32_t max_val);;

/* Function at 004e7b30 (Size: 68 bytes) */
int __cdecl __ismbbkana(uint32_t max_val);;

/* Function at 004e7b80 (Size: 110 bytes) */
int32_t __cdecl x_ismbbtype(uint8_t max_val,uint32_t point,uint8_t hBitmap);;

/* Function at 004e7bf0 (Size: 204 bytes) */
int __cdecl __setargv(void);;

/* Function at 004e7cc0 (Size: 958 bytes) */
void __cdecl parse_cmdline(uint8_t *max_val,int32_t *point,uint8_t *hBitmap,int *flags,int *damage);;

/* Function at 004e8080 (Size: 689 bytes) */
LPVOID __cdecl ___crtGetEnvironmentStringsW(void);;

/* Function at 004e8340 (Size: 602 bytes) */
LPVOID __cdecl ___crtGetEnvironmentStringsA(void);;

/* Function at 004e8661 (Size: 27 bytes) */
void FUN_004e8661(int max_val);;

/* Function at 004e8680 (Size: 95 bytes) */
void __cdecl __FF_MSGBANNER(void);;

/* Function at 004e86e0 (Size: 537 bytes) */
void __cdecl __NMSG_WRITE(int max_val);;

/* Function at 004e8900 (Size: 109 bytes) */
wchar_t * __cdecl __GET_RTERRMSG(int max_val);;

/* Function at 004e8980 (Size: 188 bytes) */
void __cdecl __getbuf(FILE *fp);;

/* Function at 004e8a40 (Size: 66 bytes) */
int __cdecl __isatty(int max_val);;

/* Function at 004e8a90 (Size: 198 bytes) */
int __cdecl _wctomb(char *str_1,wchar_t point);;

/* Function at 004e8b60 (Size: 104 bytes) */
undefined8 __aulldiv(uint32_t x,uint32_t y,uint32_t width,uint32_t height);;

/* Function at 004e8bd0 (Size: 117 bytes) */
undefined8 __aullrem(uint32_t x,uint32_t y,uint32_t width,uint32_t height);;

/* Function at 004e8c50 (Size: 235 bytes) */
int __cdecl __snprintf(char *str_1,size_t point,char *str_3,...);;

/* Function at 004e8d40 (Size: 217 bytes) */
int __cdecl __commit(int max_val);;

/* Function at 004e8e20 (Size: 187 bytes) */
int __cdecl __fcloseall(void);;

/* Function at 004e8ee0 (Size: 410 bytes) */
int __cdecl _mbtowc(wchar_t *str_1,char *str_2,size_t hBitmap);;

/* Function at 004e9080 (Size: 74 bytes) */
int __cdecl _isalpha(int max_val);;

/* Function at 004e90d0 (Size: 68 bytes) */
int __cdecl _isupper(int max_val);;

/* Function at 004e9120 (Size: 68 bytes) */
int __cdecl _islower(int max_val);;

/* Function at 004e9170 (Size: 68 bytes) */
int __cdecl _isdigit(int max_val);;

/* Function at 004e91c0 (Size: 74 bytes) */
int __cdecl _isxdigit(int max_val);;

/* Function at 004e9210 (Size: 68 bytes) */
int __cdecl _isspace(int max_val);;

/* Function at 004e9260 (Size: 68 bytes) */
int __cdecl _ispunct(int max_val);;

/* Function at 004e92b0 (Size: 74 bytes) */
int __cdecl _isalnum(int max_val);;

/* Function at 004e9300 (Size: 74 bytes) */
int __cdecl _isprint(int max_val);;

/* Function at 004e9350 (Size: 74 bytes) */
int __cdecl _isgraph(int max_val);;

/* Function at 004e93a0 (Size: 68 bytes) */
int __cdecl _iscntrl(int max_val);;

/* Function at 004e93f0 (Size: 41 bytes) */
int __cdecl ___isascii(int max_val);;

/* Function at 004e9420 (Size: 22 bytes) */
uint32_t Mem_AllocOrFree_004e9420(uint32_t max_val);;

/* Function at 004e9440 (Size: 113 bytes) */
int __cdecl ___iscsymf(int max_val);;

/* Function at 004e94c0 (Size: 113 bytes) */
int __cdecl ___iscsym(int max_val);;

/* Function at 004e9540 (Size: 299 bytes) */
int __cdecl _ungetc(int player,FILE *card_slot);;

/* Function at 004e9670 (Size: 308 bytes) */
int __cdecl __setmode(int player,int card_slot);;

/* Function at 004e97b0 (Size: 285 bytes) */
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t hBitmap);;

/* Function at 004e9900 (Size: 35 bytes) */
void ___tzset(void);;

/* Function at 004e9930 (Size: 861 bytes) */
void __cdecl __tzset(void);;

/* Function at 004e9c90 (Size: 859 bytes) */
int __cdecl __isindst(tm *ptr_1);;

/* Function at 004ea000 (Size: 515 bytes) */
void __cdecl cvtdate(int max_val,int point,uint32_t hBitmap,int flags,int damage,int arg_6,int arg_7,int arg_8,int arg_9,int arg_10,int arg_11);;

/* Function at 004ea210 (Size: 487 bytes) */
tm * __cdecl _gmtime(time_t *ptr_1);;

/* Function at 004ea400 (Size: 35 bytes) */
uint32_t __cdecl __statusfp(void);;

/* Function at 004ea430 (Size: 36 bytes) */
uint32_t __cdecl __clearfp(void);;

/* Function at 004ea460 (Size: 79 bytes) */
uint32_t __cdecl __control87(uint32_t player,uint32_t card_slot);;

/* Function at 004ea4b0 (Size: 37 bytes) */
uint32_t __cdecl __controlfp(uint32_t player,uint32_t card_slot);;

/* Function at 004ea4e0 (Size: 89 bytes) */
void __cdecl __fpreset(void);;

/* Function at 004ea540 (Size: 308 bytes) */
uint32_t __abstract_cw(uint32_t max_val);;

/* Function at 004ea690 (Size: 431 bytes) */
int32_t __hw_cw(uint32_t max_val);;

/* Function at 004ea860 (Size: 116 bytes) */
uint32_t __abstract_sw(uint8_t max_val);;

/* Function at 004ea8e0 (Size: 21 bytes) */
void __cdecl __fptrap(void);;

/* Function at 004ea900 (Size: 22 bytes) */
int Mem_AllocOrFree_004ea900(int max_val);;

/* Function at 004ea920 (Size: 313 bytes) */
int __cdecl _tolower(int max_val);;

/* Function at 004eaa60 (Size: 153 bytes) */
int32_t __ZeroTail(int player,int card_slot);;

/* Function at 004eab00 (Size: 179 bytes) */
int __IncMan(int player,int card_slot);;

/* Function at 004eabc0 (Size: 220 bytes) */
int32_t __RoundMan(int player,int card_slot);;

/* Function at 004eaca0 (Size: 74 bytes) */
void __CopyMan(int32_t *player,int32_t *card_slot);;

/* Function at 004eacf0 (Size: 57 bytes) */
void __FillZeroMan(int max_val);;

/* Function at 004ead30 (Size: 77 bytes) */
int32_t __IsZeroMan(int max_val);;

/* Function at 004ead80 (Size: 235 bytes) */
void __ShrMan(int player,int card_slot);;

/* Function at 004eae70 (Size: 616 bytes) */
int32_t __ld12cvt(uint16_t *max_val,uint32_t *point,int *hBitmap);;

/* Function at 004eb0e0 (Size: 37 bytes) */
INTRNCVT_STATUS __cdecl FID_conflict:__ld12tod(_LDBL12 *ptr_1,_CRT_DOUBLE *ptr_2);;

/* Function at 004eb110 (Size: 37 bytes) */
INTRNCVT_STATUS __cdecl FID_conflict:__ld12tod(_LDBL12 *ptr_1,_CRT_DOUBLE *ptr_2);;

/* Function at 004eb140 (Size: 201 bytes) */
INTRNCVT_STATUS __cdecl __ld12told(_LDBL12 *ptr_1,_LDOUBLE *ptr_2);;

/* Function at 004eb210 (Size: 58 bytes) */
int __cdecl FID_conflict:__atodbl(_CRT_FLOAT *ptr_1,char *str_2);;

/* Function at 004eb250 (Size: 58 bytes) */
int __cdecl __atoldbl(_LDOUBLE *ptr_1,char *str_2);;

/* Function at 004eb290 (Size: 58 bytes) */
int __cdecl FID_conflict:__atodbl(_CRT_FLOAT *ptr_1,char *str_2);;

/* Function at 004eb2d0 (Size: 215 bytes) */
errno_t __cdecl __fptostr(char *x,size_t y,int width,STRFLT height);;

/* Function at 004eb3b0 (Size: 111 bytes) */
uint8_t * __fltout(void);;

/* Function at 004eb420 (Size: 375 bytes) */
void ___dtold(uint32_t *player,uint32_t *card_slot);;

/* Function at 004eb5a0 (Size: 66 bytes) */
size_t __cdecl _wcslen(wchar_t *str_1);;

/* Function at 004eb5f0 (Size: 829 bytes) */
size_t __cdecl _wcstombs(char *str_1,wchar_t *str_2,size_t hBitmap);;

/* Function at 004eb950 (Size: 110 bytes) */
int __cdecl wcsncnt(short *player,int card_slot);;

/* Function at 004eb9c0 (Size: 227 bytes) */
char * __cdecl _getenv(char *str_1);;

/* Function at 004ebab0 (Size: 760 bytes) */
int __cdecl ___crtLCMapStringW(LPCWSTR max_val,DWORD point,LPCWSTR hBitmap,int flags,LPWSTR damage,int arg_6);;

/* Function at 004ebdb0 (Size: 108 bytes) */
int __cdecl wcsncnt(short *player,int card_slot);;

/* Function at 004ebe20 (Size: 791 bytes) */
int __cdecl ___crtLCMapStringA(_locale_t max_val,LPCWSTR point,DWORD hBitmap,LPCSTR flags,int damage,LPSTR arg_6,int arg_7,int arg_8,BOOL arg_9);;

/* Function at 004ec140 (Size: 100 bytes) */
size_t __cdecl _strncnt(char *str_1,size_t point);;

/* Function at 004ec1b0 (Size: 73 bytes) */
int32_t ___addl(uint32_t max_val,uint32_t point,uint32_t *hBitmap);;

/* Function at 004ec200 (Size: 171 bytes) */
void ___add_12(uint32_t *player,uint32_t *card_slot);;

/* Function at 004ec2b0 (Size: 118 bytes) */
void ___shl_12(int *max_val);;

/* Function at 004ec330 (Size: 119 bytes) */
void ___shr_12(uint32_t *max_val);;

/* Function at 004ec3b0 (Size: 312 bytes) */
void ___mtold12(char *str_1,int point,uint32_t *hBitmap);;

/* Function at 004ec4f0 (Size: 2795 bytes) */
uint32_t __cdecl ___strgtold12(_LDBL12 *ptr_1,char **str_2,char *str_3,int flags,int damage,int arg_6,int arg_7);;

/* Function at 004ed110 (Size: 88 bytes) */
uint32_t __cdecl ___STRINGTOLD(_LDOUBLE *x,char **y,char *width,int height);;

/* Function at 004ed170 (Size: 1335 bytes) */
int32_t __cdecl $I10_OUTPUT(int max_val,uint32_t point,uint16_t hBitmap,int flags,uint8_t damage,short *arg_6);;

/* Function at 004ed6b0 (Size: 103 bytes) */
int __cdecl __mbsnbicoll(uchar *str_1,uchar *str_2,size_t hBitmap);;

/* Function at 004ed720 (Size: 205 bytes) */
int __cdecl ___wtomb_environ(void);;

/* Function at 004ed7f0 (Size: 1063 bytes) */
void ___ld12mul(int *player,int *card_slot);;

/* Function at 004edc20 (Size: 216 bytes) */
void ___multtenpow12(int *max_val,uint32_t point,int hBitmap);;

/* Function at 004edd00 (Size: 746 bytes) */
int __cdecl ___crtCompareStringW(LPCWSTR max_val,DWORD point,LPCWSTR hBitmap,int flags,LPCWSTR damage,int arg_6);;

/* Function at 004edff0 (Size: 108 bytes) */
int __cdecl wcsncnt(short *player,int card_slot);;

/* Function at 004ee060 (Size: 1107 bytes) */
int __cdecl ___crtCompareStringA(_locale_t max_val,LPCWSTR point,DWORD hBitmap,LPCSTR flags,int damage,LPCSTR arg_6,int arg_7,int arg_8);;

/* Function at 004ee4c0 (Size: 100 bytes) */
size_t __cdecl _strncnt(char *str_1,size_t point);;

/* Function at 004ee530 (Size: 867 bytes) */
int __cdecl ___crtsetenv(char **str_1,int point);;

/* Function at 004ee8a0 (Size: 155 bytes) */
int __cdecl findenv(uchar *str_1,size_t card_slot);;

/* Function at 004ee940 (Size: 255 bytes) */
int * __cdecl copy_environ(int *max_val);;

/* Function at 004eea40 (Size: 229 bytes) */
uchar * __cdecl __mbschr(uchar *str_1,uint32_t point);;

/* Function at 004eec20 (Size: 6 bytes) */
void RtlUnwind(PVOID max_val,PVOID point,PEXCEPTION_RECORD hBitmap,PVOID flags);;

/* Function at 004eec70 (Size: 226 bytes) */
int __cdecl __chdir(char *str_1);;

/* Function at 004eed60 (Size: 140 bytes) */
int __cdecl __strcmpi(char *str_1,char *str_2);;

/* Function at 004eedf0 (Size: 173 bytes) */
int __cdecl __strnicmp(char *str_1,char *str_2,size_t hBitmap);;

/* Function at 004eeea0 (Size: 293 bytes) */
char * __cdecl __strlwr(char *str_1);;

/* Function at 004eefd0 (Size: 188 bytes) */
uint32_t __cdecl __mbctoupper(uint32_t max_val);;

/* Function at 006c5000 (Size: 396 bytes) */
void __fastcall FUN_006c5000(int32_t max_val,int32_t point,uint16_t *hBitmap);;

/* Function at 006c5245 (Size: 112 bytes) */
void __fastcall FUN_006c5245(int32_t player,int32_t card_slot);;

/* Function at 006c52b5 (Size: 75 bytes) */
void FUN_006c52b5(void);;

/* Function at 006c5300 (Size: 146 bytes) */
void __fastcall FUN_006c5300(uint32_t max_val);;

/* Function at 006c5392 (Size: 242 bytes) */
int32_t __fastcall FUN_006c5392(int32_t max_val,uint32_t point,int32_t hBitmap);;

/* Function at 006c5484 (Size: 36 bytes) */
void Mem_AllocOrFree_006c5484(int32_t player,uint32_t card_slot);;


#ifdef __cplusplus
}
#endif

#endif /* DUEL_H */
