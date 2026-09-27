
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int DAT_004f45fc;
extern int DAT_005f76e0;
extern int DAT_004f45f8;
extern int DAT_004f4608;
extern int DAT_004f4600;
extern int DAT_004f4604;
extern int s_SHIT_004f451c;
extern int DAT_00525744;
extern int DAT_006679ef;
int Str_CopyFast();

#define _rand rand
#define _sprintf sprintf
#define _strlen strlen
#define _strcmp strcmp
#define _fopen fopen
#define _fclose fclose
#define _fgets fgets
#define _fscanf fscanf
#define _read read
#define __read read
#define __strnicmp strncasecmp

typedef int (*GhidraCall)(void *, ...);

int Duel_ColorMaskToIndex(byte arg_1);
uint Duel_QueryCardAttribute(int player, int slot, int event_code, undefined4 target_slot);
uint Mana_GetCardColorRequirement(int player, int card_slot);
bool Mana_CanAffordCost(int arg_1, uint arg_2, int arg_3);
int Duel_GetCardColorOverride(int arg_1, int arg_2, int arg_3);

int Duel_ApplyCombatDamage(int arg_1, int arg_2, int arg_3, int arg_4, int arg_5);
int Duel_GetCardModifiedPower(int arg_1, int arg_2, int arg_3);
int Duel_RandomRange(int arg_1);

void Duel_UpdateBoardState(undefined4 arg1, undefined4 arg2);
bool Duel_CardIsTapped(int arg1, int arg2);
int Duel_TriggerCardEvent(int arg_1, int arg_2, int arg_3, int arg_4, int arg_5);
int Duel_PlayCardSoundEffect(int arg_1, int arg_2, int arg_3, undefined4 arg_4, undefined4 arg_5);

void Duel_DrawCardSprite(int arg_1, int arg_2, int arg_3);
int Duel_DrawString(int arg_1, uint arg_2, int arg_3);
undefined4 UI_SelectTargetCardDialog(void *arg1, uint arg2);

void EnterCriticalSection(void *cs);
void LeaveCriticalSection(void *cs);
int thunk_FUN_10001c16(void *p);
int thunk_FUN_100019c7(void *p);
int thunk_FUN_1000dd80();
int IsSndLoaded();
int GetLRUSnd();
void OutputDebugStringA(const char *s);
void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext);
HMODULE LoadLibraryA(const char *lib);
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
int ReleaseSnd();
void DeckBuilderMain();
int AVIFileOpenA();
int AVIFileRelease();
int AVIFileGetStream();
LRESULT SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

extern int32_t g_DuelCardSlot_CardId;
extern int32_t g_DuelCardSlot_Flags;
extern uint8_t g_DuelCardSlot_Subtypes;
extern uint8_t g_DuelCardSlot_ColorMask;
extern uint8_t g_DuelCardSlot_Controller;
extern int16_t g_DuelCardSlot_Power;
extern int32_t g_DuelCardSlot_Counters;
extern int32_t g_DuelCardSlot_TargetSlot;
extern int32_t g_DuelCardSlot_DisplayIndex;
extern uint32_t g_DuelCardSlot_Abilities1;
extern uint32_t g_DuelCardSlot_Abilities2;
extern int32_t g_DuelCardSlot_TargetPlayer;
extern int32_t g_DuelCardSlot_CombatTargetSlot;
extern int32_t g_DuelCardSlot_AttachedAuraPlayer;
extern int32_t g_DuelCardSlot_AttachedAuraSlot;
extern uint8_t g_DuelCardSlot_TapState;
extern uint8_t g_DuelCardSlot_SpecialState;

extern int32_t g_DuelActivePlayer;
extern int32_t g_DuelActiveCardSlot;
extern int32_t g_DuelHumanPlayerIndex;
extern int32_t g_DuelPlayerLifeTotals;
extern int32_t g_DuelPlayerManaPool;
extern int32_t g_DuelTurnCounter;
extern int32_t g_DuelPlayerCreatureCount;
extern int32_t g_DuelCurrentTurnPhase;
extern int32_t g_DuelDefendingPlayer;
extern int32_t g_DuelTargetPlayer;
extern int32_t g_DuelTargetCardSlot;
extern int32_t g_DuelDebugModeFlag;
extern int32_t g_DuelCombatPhaseState;
extern int32_t g_DuelCurrentEventCode;
extern int32_t g_DuelTargetCardId;
extern int32_t g_DuelDamageAccumulator;
extern int32_t g_DuelCombatAttackerPlayer;
extern int32_t g_DuelCombatBlockerSlot;
extern uint8_t g_DuelMasterCardTable;
extern uint8_t g_DuelMasterCardSubType;
extern char g_DuelCardChoicePrompt;
extern char g_DuelCardNameBuffer;
extern HINSTANCE g_DuelInstanceHandle;
extern HWND g_DuelMainHwnd;
extern char g_DuelAssetDirectory;
extern int32_t g_DisplayScreenWidth;
extern int32_t g_DisplayScreenHeight;

extern uint32_t g_CardEventResult;
extern int32_t g_CardSlot_Counters;
extern int32_t g_CardSlot_CardId;
extern int32_t g_CardSlot_Flags;
extern int g_EventSourcePlayer;
extern int g_OverworldPlayerCoordY;
extern int g_EventSourceSlot;
extern int g_ActivePlayerPriority;
extern int g_IsAiThinking;

extern int DAT_0068eee0;
extern int DAT_0068eed8;
extern int DAT_006826c0;
extern int DAT_006826ec;
extern int DAT_00682704;
extern int DAT_00682710;
extern int DAT_006826dd;
extern int DAT_00682714;
extern int DAT_0068f2e0;
extern int DAT_0068ed10;
extern int DAT_006b2fe4;
extern int DAT_006b157c;
extern int DAT_006fedc0;
extern int DAT_00527e88;
extern int DAT_005ef980;
extern int DAT_00666444;
extern int DAT_00627870;
extern int DAT_0051aebe;
extern int DAT_00676500;
extern int DAT_00666900;
extern int DAT_006a4f70;
extern int DAT_0063edd0;
extern int DAT_0068ecfc;
extern int DAT_0068ee70;
extern int DAT_0068eef0;
extern int DAT_0068edd4;
extern int DAT_0068ee98;
extern int DAT_00681ec8;
extern int DAT_00681eb4;
extern int DAT_00690310;
extern int DAT_00667994;
extern int DAT_0067bdb0;
extern int DAT_00677340;
extern int DAT_005239ec;
extern int DAT_0067bda0;
extern int DAT_00627a20;
extern int DAT_00665ed0;
extern int DAT_0054aab0;
extern int DAT_0054aab8;
extern int DAT_00515e80;
extern int DAT_00515e88;
extern int DAT_0061815c;
extern int PTR_DAT_004f7914;
extern int DAT_0051aec4;
extern int DAT_006a4b70;
extern int DAT_004fb0f4;
extern int _DAT_1004c884;
extern int DAT_1004c6d4;
extern int DAT_1004044c;
extern int DAT_1001e8a0;
extern int *DAT_1000a640;
extern int DAT_1000a440;
extern int *DAT_1000ba90;
extern int _DAT_0068f0b4;
extern int DAT_0063ee18;
extern int DAT_0063ee90;
extern int DAT_004ff590;
extern int DAT_00666760;
extern int DAT_006663e0;
extern int DAT_0066aae8;
extern int DAT_0068f0b0;
extern int DAT_006b2d5c;
extern int DAT_0063eea8;
extern int DAT_0060d4a0;
extern int DAT_00412ac4;
extern int g_OverworldWorldState;
extern const char* s_spr1024__00525754;
extern const char* s_spr800__0052574c;
extern const char* s_SmallArt_cat_10040480;
extern const char* s_MedArt_cat_10040470;
extern const char* s__08X_LoadKimPicture___s___file_m_004f7970;
extern const char* s_Magic__The_Gathering_00412a30;
extern const char* s__MTGshell_00412a48;
extern const char* s__08x_DestroyDIBSection__file_map_004f9804;
extern const char* s__08x_DestroyDIBSection__file_map_00530204;
extern const char* PTR_s_magsnd_1001152c;
extern int DAT_101cf930;
extern int DAT_10011524;
extern int DAT_1001e87c;
extern int DAT_1000a434;

int Pic_Subsystem_00451291();
int Pic_Subsystem_0044895f();
int Pic_Subsystem_0044867e();
int Pic_Subsystem_0044b84b();
int FUN_00451760();
int FUN_0046da4a();
int FUN_00451995();
int Mem_AllocOrFree_0049f704();
int Mem_AllocOrFree_00408089();
int Mem_AllocOrFree_004f1e20();
int Mem_AllocOrFree_0050f740();
uint32_t* Mem_AllocOrFree_004d9630(uint32_t*, uint32_t*);
int FUN_0048ac2f();
int FUN_00470a16();
int FUN_0048cb7f();
int Magic_IsManaSource();
int FUN_0048cac9();
int FUN_0048caf4();
int FUN_00432c2a();
int FUN_00447114();
int FUN_00446de2();
int FUN_00401010();
int FUN_004010aa();
int FUN_0040161a();
int FUN_0040cc08();
int FUN_0043d3ff();
int FUN_0049b2c1();
int FUN_0049b1a9();
int FUN_0050d560();
int FUN_00511120();
int FUN_00510fc0();
int FUN_0050e8b0();
int FUN_0050ec90();
int FUN_0050f820();
int FUN_0050f440();
int FUN_00486c12();
int FUN_00478aa4();

/*
 * Decompiled function: FileIo_ReadStream
 * Entry Point: 0048e01d
 * Size: 132 bytes
 */


uint FileIo_ReadStream(void *buffer,uint size)

{
  uint uVar1;
  uint local_8;
  
  if (DAT_0054aab0 == 0) {
    local_8 = FUN_0048caf4(DAT_0054aab8,buffer,size);
  }
  else {
    uVar1 = _read(DAT_0054aab8,buffer,size);
    local_8 = (uint)(uVar1 == size);
  }
  if (local_8 == 0) {
    OutputDebugStringA(&DAT_00527e88);
  }
  return local_8;
}

/*
 * Decompiled function: FileIo_ReadDataBlock
 * Entry Point: 00433bb6
 * Size: 131 bytes
 */


uint FileIo_ReadDataBlock(void *buffer,uint size)

{
  uint uVar1;
  uint local_8;
  
  if (DAT_00515e80 == 0) {
    local_8 = FUN_00432c2a(DAT_00515e88,buffer,size);
  }
  else {
    uVar1 = __read(DAT_00515e88,buffer,size);
    local_8 = (uint)(uVar1 == size);
  }
  if (local_8 == 0) {
    OutputDebugStringA(s_SHIT_004f451c);
  }
  return local_8;
}

/*
 * Decompiled function: Sprite_ResolveAssetPath
 * Entry Point: 0046f172
 * Size: 167 bytes
 */


undefined1 * Sprite_ResolveAssetPath(char *str_1)

{
  if (g_DisplayScreenWidth == 0x280) {
    strcpy(&g_OverworldWorldState,&DAT_00525744);
  }
  else if (g_DisplayScreenWidth == 800) {
    strcpy(&g_OverworldWorldState,s_spr800__0052574c);
  }
  else if (g_DisplayScreenWidth == 0x400) {
    strcpy(&g_OverworldWorldState,s_spr1024__00525754);
  }
  strcat(&g_OverworldWorldState,str_1);
  return &g_OverworldWorldState;
}

/*
 * Decompiled function: Catalog_ParseCsvLine
 * Entry Point: 00434660
 * Size: 589 bytes
 */


int Catalog_ParseCsvLine(uint *csv_buffer,uint *src)

{
  FILE *fp;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int local_310;
  char local_30c [252];
  uint local_210 [66];
  uint local_108 [63];
  int local_c;
  int local_8;
  
  if (g_DuelDebugModeFlag != 1) {
    Mem_AllocOrFree_004d9630(local_108,(uint *)&DAT_004f45f8);
    Str_CopyFast(local_108,src);
    Str_CopyFast(local_108,(uint *)&DAT_004f45fc);
    Mem_AllocOrFree_004d9630(local_210,(uint *)&DAT_005f76e0);
    Str_CopyFast(local_210,(uint *)&DAT_004f4600);
    Mem_AllocOrFree_004d9630(local_210,csv_buffer);
    fp = _fopen((char *)local_210,&DAT_004f4604);
    if (fp != (FILE *)0x0) {
      do {
        iVar1 = _strcmp((char *)local_108,local_30c);
        if (iVar1 == 0) {
          _fscanf(fp,&DAT_004f4608,&local_8);
          _fgets(local_30c,0x50,fp);
          local_c = 0;
          for (local_310 = 0; (local_310 < local_8 && (local_310 < 0x32)); local_310 = local_310 + 1
              ) {
            pcVar2 = _fgets(&g_DuelCardNameBuffer + local_310 * 0xfa,0xfa,fp);
            if (pcVar2 == (char *)0x0) {
              _fclose(fp);
              return -local_c;
            }
            sVar3 = _strlen(&g_DuelCardNameBuffer + local_310 * 0xfa);
            (&DAT_006679ef)[local_310 * 0xfa + sVar3] = 0;
            local_c = local_c + 1;
          }
          _fclose(fp);
          if (local_c < local_8) {
            return -local_c;
          }
          return local_c;
        }
        pcVar2 = _fgets(local_30c,0x50,fp);
      } while (pcVar2 != (char *)0x0);
      _fclose(fp);
    }
  }
  return 0;
}
