/*
 * Decompiled function: FUN_00481890
 * Entry Point: 00481890
 * Size: 1022 bytes
 */
#include "duel.h"


void FUN_00481890(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  BYTE *local_88;
  BYTE local_84 [100];
  int local_20;
  int local_1c;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e48,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_004fa044,DAT_00663e24);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_Layout_004fa048,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa050,DAT_00663e04);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_DirectiveTracksMouse_004fa054,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa06c,DAT_00663e00);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowCueCards_004fa070,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa080,DAT_00663e08);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowPowerToughnessOnCards_004fa084,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa0a0,DAT_00663e0c);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowAbilitiesOnCards_004fa0a4,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa0bc,DAT_00663e18);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowIDTagsOnCards_004fa0c0,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa0d4,DAT_00663e1c);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowInvisibleEffectCards_004fa0d8,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa0f4,DAT_00663e20);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowAllCardsSummonSickness_004fa0f8,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa114,DAT_00663e10);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_ExpandTextBoxOnBigCard_004fa118,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa130,DAT_00663e14);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_SeeNextDrawsAtEndOfDuel_004fa134,0,1,local_14,sVar2 + 1);
    local_88 = local_84;
    for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < 0x25; local_20 = local_20 + 1) {
        if (((&DAT_006667c0)[local_20 * 4 + local_1c * 0x98] & 1) == 0) {
          *local_88 = '-';
        }
        else {
          *local_88 = 'S';
        }
        local_88 = local_88 + 1;
      }
    }
    *local_88 = '\0';
    sVar2 = _strlen((char *)local_84);
    RegSetValueExA(local_18,s_PhaseStoppers_004fa14c,0,1,local_84,sVar2 + 1);
    if (((byte)DAT_00663dfc & 1) == 0) {
      wsprintfA((LPSTR)local_14,&DAT_004fa15c,DAT_00663e28);
      sVar2 = _strlen((char *)local_14);
      RegSetValueExA(local_18,s_PlayerTerritoryColor_004fa160,0,1,local_14,sVar2 + 1);
    }
    if (((byte)DAT_00663dfc & 1) == 0) {
      wsprintfA((LPSTR)local_14,&DAT_004fa178,DAT_00663e2c);
      sVar2 = _strlen((char *)local_14);
      RegSetValueExA(local_18,s_PlayerTerritoryType_004fa17c,0,1,local_14,sVar2 + 1);
    }
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}


