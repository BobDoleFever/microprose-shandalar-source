/*
 * Decompiled function: Rules_ParseFilter_0050065d
 * Entry Point: 0050065d
 * Size: 1022 bytes
 */
#include "magic.h"


void Rules_ParseFilter_0050065d(void)

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
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a4,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_00530ba0,DAT_006fe444);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Layout_00530ba4,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bac,DAT_006fe424);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_DirectiveTracksMouse_00530bb0,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bc8,DAT_006fe420);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowCueCards_00530bcc,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bdc,DAT_006fe428);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowPowerToughnessOnCards_00530be0,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530bfc,DAT_006fe42c);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowAbilitiesOnCards_00530c00,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c18,DAT_006fe438);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowIDTagsOnCards_00530c1c,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c30,DAT_006fe43c);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowInvisibleEffectCards_00530c34,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c50,DAT_006fe440);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ShowAllCardsSummonSickness_00530c54,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c70,DAT_006fe430);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ExpandTextBoxOnBigCard_00530c74,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530c8c,DAT_006fe434);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_SeeNextDrawsAtEndOfDuel_00530c90,0,1,local_14,sVar2 + 1);
    local_88 = local_84;
    for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < 0x25; local_20 = local_20 + 1) {
        if (((&DAT_00696740)[local_20 * 4 + local_1c * 0x98] & 1) == 0) {
          *local_88 = '-';
        }
        else {
          *local_88 = 'S';
        }
        local_88 = local_88 + 1;
      }
    }
    *local_88 = '\0';
    sVar2 = strlen((char *)local_84);
    RegSetValueExA(local_18,s_PhaseStoppers_00530ca8,0,1,local_84,sVar2 + 1);
    if (((byte)DAT_006fe410 & 1) == 0) {
      wsprintfA((LPSTR)local_14,&DAT_00530cb8,DAT_006fe448);
      sVar2 = strlen((char *)local_14);
      RegSetValueExA(local_18,s_PlayerTerritoryColor_00530cbc,0,1,local_14,sVar2 + 1);
    }
    if (((byte)DAT_006fe410 & 1) == 0) {
      wsprintfA((LPSTR)local_14,&DAT_00530cd4,DAT_006fe44c);
      sVar2 = strlen((char *)local_14);
      RegSetValueExA(local_18,s_PlayerTerritoryType_00530cd8,0,1,local_14,sVar2 + 1);
    }
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}


