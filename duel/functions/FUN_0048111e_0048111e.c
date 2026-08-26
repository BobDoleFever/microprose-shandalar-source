/*
 * Decompiled function: FUN_0048111e
 * Entry Point: 0048111e
 * Size: 1906 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048111e(void)

{
  LSTATUS LVar1;
  int iVar2;
  int local_90;
  int local_8c;
  BYTE *local_88;
  BYTE local_84 [100];
  int local_20;
  int local_1c;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e48,0,1,
                        &local_18);
  if (LVar1 == 0) {
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_Layout_004f9edc,(LPDWORD)0x0,(LPDWORD)0x0,local_14,&local_8)
    ;
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9ee4,&DAT_00663e24);
    }
    else {
      DAT_00663e24 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_DirectiveTracksMouse_004f9ee8,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9f00,&DAT_00663e04);
    }
    else {
      DAT_00663e04 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowCueCards_004f9f04,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                             &local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9f14,&DAT_00663e00);
    }
    else {
      DAT_00663e00 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowPowerToughnessOnCards_004f9f18,(LPDWORD)0x0,(LPDWORD)0x0
                             ,local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9f34,&DAT_00663e08);
    }
    else {
      DAT_00663e08 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowIDTagsOnCards_004f9f38,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9f4c,&DAT_00663e18);
    }
    else {
      DAT_00663e18 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowInvisibleEffectCards_004f9f50,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9f6c,&DAT_00663e1c);
    }
    else {
      DAT_00663e1c = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowAllCardsSummonSickness_004f9f70,(LPDWORD)0x0,
                             (LPDWORD)0x0,local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9f8c,&DAT_00663e20);
    }
    else {
      DAT_00663e20 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    RegQueryValueExA(local_18,s_ShowAbilitiesOnCards_004f9f90,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                     &local_8);
    if (local_14[0] == '\0') {
      DAT_00663e0c = 1;
    }
    else {
      _sscanf((char *)local_14,&DAT_004f9fa8,&DAT_00663e0c);
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ExpandTextBoxOnBigCard_004f9fac,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9fc4,&DAT_00663e10);
    }
    else {
      DAT_00663e10 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_SeeNextDrawsAtEndOfDuel_004f9fc8,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_14,&DAT_004f9fe0,&DAT_00663e14);
    }
    else {
      DAT_00663e14 = 1;
    }
    local_8 = 100;
    local_84[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_PhaseStoppers_004f9fe4,(LPDWORD)0x0,(LPDWORD)0x0,local_84,
                             &local_8);
    if (LVar1 == 0) {
      local_88 = local_84;
      local_1c = 0;
      while ((local_1c < 2 && (*local_88 != '\0'))) {
        local_20 = 0;
        while ((local_20 < 0x25 && (*local_88 != '\0'))) {
          if (*local_88 == 'S') {
            *(undefined4 *)(&DAT_006667c0 + local_1c * 0x98 + local_20 * 4) = 1;
          }
          else {
            *(undefined4 *)(&DAT_006667c0 + local_1c * 0x98 + local_20 * 4) = 0;
          }
          local_20 = local_20 + 1;
          local_88 = local_88 + 1;
        }
        local_1c = local_1c + 1;
      }
    }
    else {
      for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < 0x25; local_20 = local_20 + 1) {
          *(undefined4 *)(&DAT_006667c0 + local_1c * 0x98 + local_20 * 4) = 0;
        }
      }
      _DAT_00666810 = 1;
      _DAT_00666838 = 1;
      DAT_006668d4 = 1;
    }
    if (((byte)DAT_00663dfc & 1) == 0) {
      local_8 = 10;
      local_14[0] = '\0';
      LVar1 = RegQueryValueExA(local_18,s_PlayerTerritoryColor_004f9ff4,(LPDWORD)0x0,(LPDWORD)0x0,
                               local_14,&local_8);
      if (LVar1 == 0) {
        _sscanf((char *)local_14,&DAT_004fa00c,&DAT_00663e28);
      }
      else {
        DAT_00663e28 = 0xffffffff;
      }
    }
    if (((byte)DAT_00663dfc & 1) == 0) {
      local_8 = 10;
      local_14[0] = '\0';
      LVar1 = RegQueryValueExA(local_18,s_PlayerTerritoryType_004fa010,(LPDWORD)0x0,(LPDWORD)0x0,
                               local_14,&local_8);
      if (LVar1 == 0) {
        _sscanf((char *)local_14,&DAT_004fa024,&DAT_00663e2c);
      }
      else {
        DAT_00663e2c = 2;
      }
    }
    local_8 = 10;
    LVar1 = RegQueryValueExA(local_18,s_CoolKimCheats_004fa028,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                             &local_8);
    if (LVar1 == 0) {
      iVar2 = _strcmp((char *)local_14,s_HolyMoly_004fa038);
      DAT_0061894c = (uint)(iVar2 == 0);
    }
    else {
      DAT_0061894c = 0;
    }
  }
  else {
    DAT_00663e24 = 1;
    DAT_00663e04 = 0;
    DAT_00663e00 = 1;
    DAT_00663e08 = 1;
    DAT_00663e18 = 0;
    DAT_00663e1c = 0;
    DAT_00663e20 = 0;
    DAT_00663e0c = 1;
    DAT_00663e10 = 0;
    DAT_00663e14 = 1;
    for (local_8c = 0; local_8c < 2; local_8c = local_8c + 1) {
      for (local_90 = 0; local_90 < 0x25; local_90 = local_90 + 1) {
        *(undefined4 *)(&DAT_006667c0 + local_90 * 4 + local_8c * 0x98) = 0;
      }
    }
    _DAT_00666810 = 1;
    _DAT_00666820 = 1;
    _DAT_00666838 = 1;
    DAT_006668b0 = 1;
    _DAT_006668b8 = 1;
    DAT_006668d4 = 1;
    if (((byte)DAT_00663dfc & 1) == 0) {
      DAT_00663e28 = 0xffffffff;
      DAT_00663e2c = 2;
    }
  }
  return;
}


