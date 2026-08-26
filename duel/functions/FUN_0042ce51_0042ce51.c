/*
 * Decompiled function: FUN_0042ce51
 * Entry Point: 0042ce51
 * Size: 1014 bytes
 */
#include "duel.h"


undefined4 FUN_0042ce51(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int local_8c;
  char local_88 [100];
  undefined4 local_24;
  size_t local_20;
  uint local_1c;
  int local_18;
  int local_14;
  char local_10;
  uint local_c;
  undefined4 local_8;
  
  DAT_005f6810 = 0;
  local_1c = FUN_0048d3eb();
  if (local_1c == 0xffffffff) {
    FUN_004d9630(&DAT_005f6810,&DAT_004f3ba0);
  }
  else {
    local_8 = *(undefined4 *)(&DAT_0068efa8 + DAT_006764b8 * 8);
    local_24 = *(undefined4 *)(&DAT_0068efac + DAT_006764b8 * 8);
    local_c = local_1c >> 0x10 & 0xff;
    if (local_c == 0x71) {
      FUN_004d9630(&DAT_005f6810,s_CASTING__004f3b54);
      FUN_0044a5a4(local_8,local_24);
      FUN_004d9640(&DAT_005f6810,s___tap_004f3b60);
    }
    else if (local_c == 0x72) {
      FUN_004d9630(&DAT_005f6810,s_ACTIVATING__004f3b68);
      FUN_0044a5a4(local_8,local_24);
      FUN_004d9640(&DAT_005f6810,s___tap_004f3b78);
    }
    else if (local_c == 0x7e) {
      FUN_004d9630(&DAT_005f6810,s_PROCESSING__004f3b80);
      FUN_0044a5a4(local_8,local_24);
      FUN_004d9640(&DAT_005f6810,s___tap_004f3b90);
    }
    else {
      FUN_004d9630(&DAT_005f6810,&DAT_004f3b98);
    }
  }
  local_88[0] = '\0';
  if ((*param_2 == -1) || (param_2[6] == -1)) {
    if (param_4 == -1) {
      uVar5 = 0xfffffff0;
      pcVar4 = s__c__d_so_far__004f3ba8;
      iVar6 = param_3;
      sVar1 = _strlen(local_88);
      _sprintf(local_88 + sVar1,pcVar4,uVar5,iVar6);
    }
    else if (param_3 < param_4) {
      uVar5 = 0xfffffff0;
      pcVar4 = s__c__d_so_far__max__d__004f3bb8;
      iVar6 = param_3;
      iVar2 = param_4;
      sVar1 = _strlen(local_88);
      _sprintf(local_88 + sVar1,pcVar4,uVar5,iVar6,iVar2);
    }
  }
  else if ((*param_2 != 0) || (param_2[6] != 0)) {
    local_8c = param_2[6];
    iVar6 = *param_2;
    local_20 = _strlen(local_88);
    for (local_8c = local_8c + iVar6; 9 < local_8c; local_8c = local_8c + -10) {
      local_88[local_20] = -0x11;
      iVar6 = local_20 + 1;
      local_20 = local_20 + 1;
      local_88[iVar6] = '\0';
    }
    if (local_8c != 0) {
      local_88[local_20] = (char)local_8c + -0xf;
      iVar6 = local_20 + 1;
      local_20 = local_20 + 1;
      local_88[iVar6] = '\0';
    }
  }
  for (local_14 = 1; local_14 < 6; local_14 = local_14 + 1) {
    if (local_14 == 1) {
      local_10 = -2;
    }
    else if (local_14 == 2) {
      local_10 = -3;
    }
    else if (local_14 == 3) {
      local_10 = -1;
    }
    else if (local_14 == 4) {
      local_10 = -4;
    }
    else {
      local_10 = -5;
    }
    if (param_2[local_14] == -1) {
      if (param_4 == -1) {
        iVar2 = (int)local_10;
        pcVar4 = s__c__d_so_far__004f3bd0;
        iVar6 = param_3;
        sVar1 = _strlen(local_88);
        _sprintf(local_88 + sVar1,pcVar4,iVar2,iVar6);
      }
      else if (param_3 < param_4) {
        iVar3 = (int)local_10;
        pcVar4 = s__c__d_so_far__max__d__004f3be0;
        iVar6 = param_3;
        iVar2 = param_4;
        sVar1 = _strlen(local_88);
        _sprintf(local_88 + sVar1,pcVar4,iVar3,iVar6,iVar2);
      }
    }
    else if (param_2[local_14] != 0) {
      local_20 = _strlen(local_88);
      for (local_18 = 0; local_18 < param_2[local_14]; local_18 = local_18 + 1) {
        local_88[local_20] = local_10;
        local_20 = local_20 + 1;
      }
      local_88[local_20] = '\0';
    }
  }
  FUN_004d9640(&DAT_005f6810,local_88);
  return 0;
}


