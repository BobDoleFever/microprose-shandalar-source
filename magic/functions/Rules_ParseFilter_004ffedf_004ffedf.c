/*
 * Decompiled function: Rules_ParseFilter_004ffedf
 * Entry Point: 004ffedf
 * Size: 1918 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Rules_ParseFilter_004ffedf(void)

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
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a4,0,1,
                        &local_18);
  if (LVar1 == 0) {
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_Layout_00530a38,(LPDWORD)0x0,(LPDWORD)0x0,local_14,&local_8)
    ;
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a40,&DAT_006fe444);
    }
    else {
      DAT_006fe444 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_DirectiveTracksMouse_00530a44,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a5c,&DAT_006fe424);
    }
    else {
      DAT_006fe424 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowCueCards_00530a60,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                             &local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a70,&DAT_006fe420);
    }
    else {
      DAT_006fe420 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowPowerToughnessOnCards_00530a74,(LPDWORD)0x0,(LPDWORD)0x0
                             ,local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530a90,&DAT_006fe428);
    }
    else {
      DAT_006fe428 = 1;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowIDTagsOnCards_00530a94,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530aa8,&DAT_006fe438);
    }
    else {
      DAT_006fe438 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowInvisibleEffectCards_00530aac,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530ac8,&DAT_006fe43c);
    }
    else {
      DAT_006fe43c = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ShowAllCardsSummonSickness_00530acc,(LPDWORD)0x0,
                             (LPDWORD)0x0,local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530ae8,&DAT_006fe440);
    }
    else {
      DAT_006fe440 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    RegQueryValueExA(local_18,s_ShowAbilitiesOnCards_00530aec,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                     &local_8);
    if (local_14[0] == '\0') {
      DAT_006fe42c = 1;
    }
    else {
      sscanf((char *)local_14,&DAT_00530b04,&DAT_006fe42c);
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_ExpandTextBoxOnBigCard_00530b08,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530b20,&DAT_006fe430);
    }
    else {
      DAT_006fe430 = 0;
    }
    local_8 = 10;
    local_14[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_SeeNextDrawsAtEndOfDuel_00530b24,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_14,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_14,&DAT_00530b3c,&DAT_006fe434);
    }
    else {
      DAT_006fe434 = 1;
    }
    local_8 = 100;
    local_84[0] = '\0';
    LVar1 = RegQueryValueExA(local_18,s_PhaseStoppers_00530b40,(LPDWORD)0x0,(LPDWORD)0x0,local_84,
                             &local_8);
    if (LVar1 == 0) {
      local_88 = local_84;
      local_1c = 0;
      while ((local_1c < 2 && (*local_88 != '\0'))) {
        local_20 = 0;
        while ((local_20 < 0x25 && (*local_88 != '\0'))) {
          if (*local_88 == 'S') {
            *(undefined4 *)(&DAT_00696740 + local_20 * 4 + local_1c * 0x98) = 1;
          }
          else {
            *(undefined4 *)(&DAT_00696740 + local_20 * 4 + local_1c * 0x98) = 0;
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
          *(undefined4 *)(&DAT_00696740 + local_20 * 4 + local_1c * 0x98) = 0;
        }
      }
      _DAT_00696790 = 1;
      _DAT_006967b8 = 1;
      DAT_00696854 = 1;
    }
    if (((byte)DAT_006fe410 & 1) == 0) {
      local_8 = 10;
      local_14[0] = '\0';
      LVar1 = RegQueryValueExA(local_18,s_PlayerTerritoryColor_00530b50,(LPDWORD)0x0,(LPDWORD)0x0,
                               local_14,&local_8);
      if (LVar1 == 0) {
        sscanf((char *)local_14,&DAT_00530b68,&DAT_006fe448);
      }
      else {
        DAT_006fe448 = 0xffffffff;
      }
    }
    if (((byte)DAT_006fe410 & 1) == 0) {
      local_8 = 10;
      local_14[0] = '\0';
      LVar1 = RegQueryValueExA(local_18,s_PlayerTerritoryType_00530b6c,(LPDWORD)0x0,(LPDWORD)0x0,
                               local_14,&local_8);
      if (LVar1 == 0) {
        sscanf((char *)local_14,&DAT_00530b80,&DAT_006fe44c);
      }
      else {
        DAT_006fe44c = 2;
      }
    }
    local_8 = 10;
    LVar1 = RegQueryValueExA(local_18,s_CoolKimCheats_00530b84,(LPDWORD)0x0,(LPDWORD)0x0,local_14,
                             &local_8);
    if (LVar1 == 0) {
      iVar2 = strcmp((char *)local_14,s_HolyMoly_00530b94);
      DAT_006b2d38 = (uint)(iVar2 == 0);
    }
    else {
      DAT_006b2d38 = 0;
    }
  }
  else {
    DAT_006fe444 = 1;
    DAT_006fe424 = 0;
    DAT_006fe420 = 1;
    DAT_006fe428 = 1;
    DAT_006fe438 = 0;
    DAT_006fe43c = 0;
    DAT_006fe440 = 0;
    DAT_006fe42c = 1;
    DAT_006fe430 = 0;
    DAT_006fe434 = 1;
    for (local_8c = 0; local_8c < 2; local_8c = local_8c + 1) {
      for (local_90 = 0; local_90 < 0x25; local_90 = local_90 + 1) {
        *(undefined4 *)(&DAT_00696740 + local_90 * 4 + local_8c * 0x98) = 0;
      }
    }
    _DAT_00696790 = 1;
    _DAT_006967a0 = 1;
    _DAT_006967b8 = 1;
    DAT_00696830 = 1;
    _DAT_00696838 = 1;
    DAT_00696854 = 1;
    if (((byte)DAT_006fe410 & 1) == 0) {
      DAT_006fe448 = 0xffffffff;
      DAT_006fe44c = 2;
    }
  }
  return;
}


