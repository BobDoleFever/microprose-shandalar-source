/*
 * Decompiled function: Ai_Subsystem_004c06df
 * Entry Point: 004c06df
 * Size: 2074 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c06df(uint arg1,uint arg2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int local_d8;
  uint local_d4;
  int local_d0;
  DWORD local_cc;
  uint local_c8;
  int local_c4;
  int local_bc;
  int local_b8;
  int local_88 [5];
  uint local_74;
  int local_64;
  int local_60 [2];
  int local_58;
  int local_54;
  int local_50 [3];
  uint local_44;
  int local_3c;
  int local_38;
  int local_24;
  undefined4 local_20;
  int local_1c [2];
  int local_14 [3];
  int local_8;
  
  local_20 = *(undefined4 *)g_DisplaySurfaceScreen;
  *(undefined4 *)g_DisplaySurfaceScreen = 2;
  DAT_006498d8 = arg1;
  DAT_006498dc = arg2;
  local_38 = arg1 - (arg1 & 0x1f);
  local_54 = arg2 - (arg2 & 0x1f);
  Ai_Subsystem_004be525(local_38,local_54,local_50,local_60);
  Ai_Subsystem_004be525(arg1,arg2,local_14,local_1c);
  Ai_Subsystem_004be525(0,0,local_88,&local_24);
  if ((DAT_00556c54 == 0) || (DAT_00641884 == 0)) {
    local_44 = 0xfffffff7;
    local_64 = 9;
    local_3c = -4;
    local_58 = 6;
    _DAT_00557480 = local_88[0];
    _DAT_00558dcc = local_24;
    DAT_00556c6c = arg1;
    DAT_00558dc4 = arg2;
    _DAT_006498d0 = 0;
    DAT_006498d4 = 0;
    _DAT_0064187c = arg1;
    _DAT_00641880 = arg2;
    DAT_00556c68 = 0x40;
    DAT_00556c5c = DAT_005574b0 * 2 + DAT_0052d77c + 0x10;
    DAT_00558dc0 = Ai_Util_004c3ba3(0x100);
    DAT_00557490 = Ai_Util_004c3ba3(0x8c);
    DAT_00557470 = -0x40;
    DAT_00558dd0 = 0x40;
    DAT_005574b4 = 0x80 - DAT_00556c5c;
    DAT_005574a8 = *(int *)(g_DisplaySurfaceScreen + 0x10) - (DAT_00556c5c + DAT_00557490);
    DAT_00556c54 = 1;
    DAT_00641884 = 1;
    Ai_CastleEncounter_004c0efe(arg1,arg2,local_3c,local_58,local_44,local_64,1,0);
    Ai_CastleEncounter_004c0efe(arg1,arg2,local_3c + -2,local_58,local_44,local_64 + 2,2,1);
  }
  else {
    bVar1 = false;
    bVar2 = 0;
    bVar3 = 0;
    bVar4 = 0;
    iVar5 = (int)(arg1 + ((int)arg1 >> 0x1f & 0x1fU)) >> 5;
    local_8 = (int)(arg2 + ((int)arg2 >> 0x1f & 0x1fU)) >> 5;
    _DAT_006498d0 = *(int *)(&DAT_006418d0 + iVar5 * 4 + local_8 * 0x100) - local_50[0];
    local_60[0] = *(int *)(&DAT_006458d0 + iVar5 * 4 + local_8 * 0x100) - local_60[0];
    if ((_DAT_006498d0 != 0) || (local_60[0] != 0)) {
      if (((int)_DAT_006498d0 < 0) && ((int)_DAT_006498d0 <= DAT_00557470)) {
        bVar1 = true;
      }
      if ((0 < (int)_DAT_006498d0) && (DAT_00558dd0 <= (int)_DAT_006498d0)) {
        bVar2 = 1;
      }
      if ((0 < local_60[0]) && (DAT_005574a8 <= local_60[0])) {
        bVar4 = 1;
      }
      if ((local_60[0] < 0) && (local_60[0] <= DAT_005574b4)) {
        bVar3 = 1;
      }
    }
    DAT_006498d4 = local_60[0];
    local_74 = _DAT_006498d0;
    if (!(bool)(bVar4 | bVar3 | bVar2) && !bVar1) {
      FUN_0050dce0((int *)g_DisplaySurfaceScreen,DAT_00556c68 + _DAT_006498d0,
                   DAT_00556c5c + local_60[0],DAT_00558dc0,DAT_00557490,
                   (int *)g_DisplaySurfaceBackBuffer,0x40,DAT_005574b0 * 2 + DAT_0052d77c + 0x10);
      *(undefined4 *)g_DisplaySurfaceScreen = local_20;
      Ai_CastleEncounter_004c0efe(DAT_00556c6c,DAT_00558dc4,-5,4,0xfffffff9,9,0,1);
      DAT_006498d8 = arg1;
      DAT_006498dc = arg2;
      return;
    }
    Ai_CastleEncounter_004c0efe(arg1,arg2,-5,4,0xfffffff9,9,0,1);
    if ((int)local_74 < 1) {
      if ((int)local_74 < 0) {
        local_d4 = 0;
        local_bc = -local_74;
        local_c8 = *(int *)(g_DisplaySurfaceScreen + 0xc) + local_74;
        local_d0 = 1;
      }
      else {
        local_d4 = 0;
        local_bc = 0;
        local_c8 = *(uint *)(g_DisplaySurfaceScreen + 0xc);
        local_d0 = -1;
      }
    }
    else {
      local_d4 = local_74;
      local_bc = 0;
      local_c8 = *(int *)(g_DisplaySurfaceScreen + 0xc) - local_74;
      local_d0 = 2;
    }
    if (local_60[0] < 1) {
      if (local_60[0] < 0) {
        local_d8 = 0x80;
        local_c4 = 0x80 - local_60[0];
        local_cc = (*(int *)(g_DisplaySurfaceScreen + 0x10) + local_60[0]) - 0x80;
        local_b8 = 1;
      }
      else {
        local_d8 = 0x80;
        local_c4 = 0x80;
        local_cc = *(int *)(g_DisplaySurfaceScreen + 0x10) - 0x80;
        local_b8 = -1;
      }
    }
    else {
      local_d8 = local_60[0] + 0x80;
      local_c4 = 0x80;
      local_cc = (*(int *)(g_DisplaySurfaceScreen + 0x10) - local_60[0]) - 0x80;
      local_b8 = 2;
    }
    FUN_0050dce0((int *)g_DisplaySurfaceScreen,local_d4,local_d8,local_c8,local_cc,
                 (int *)g_DisplaySurfaceScreen,local_bc,local_c4);
    if (local_d0 == 1) {
      Ai_CastleEncounter_004c0efe(arg1,arg2,-3,-1,0xfffffff9,7,1,0);
      if (local_b8 == 1) {
        Ai_CastleEncounter_004c0efe(arg1,arg2,-1,4,0xfffffff9,-3,1,0);
      }
      else if (local_b8 == 2) {
        Ai_CastleEncounter_004c0efe(arg1,arg2,-1,4,3,7,1,0);
      }
    }
    else if (local_d0 == 2) {
      Ai_CastleEncounter_004c0efe(arg1,arg2,2,5,0xfffffff9,7,1,0);
      if (local_b8 == 1) {
        Ai_CastleEncounter_004c0efe(arg1,arg2,-3,2,0xfffffff9,-3,1,0);
      }
      else if (local_b8 == 2) {
        Ai_CastleEncounter_004c0efe(arg1,arg2,-3,2,3,7,1,0);
      }
    }
    else if (local_b8 == 1) {
      Ai_CastleEncounter_004c0efe(arg1,arg2,-3,5,0xfffffff9,-3,1,0);
    }
    else if (local_b8 == 2) {
      Ai_CastleEncounter_004c0efe(arg1,arg2,-3,5,3,7,1,0);
    }
    Ai_CastleEncounter_004c0efe(arg1,arg2,-4,6,0xfffffff7,0xb,2,0);
    _DAT_00557480 = local_88[0];
    _DAT_00558dcc = local_24;
    DAT_00556c6c = arg1;
    DAT_00558dc4 = arg2;
    _DAT_006498d0 = 0;
    DAT_006498d4 = 0;
    _DAT_0064187c = arg1;
    _DAT_00641880 = arg2;
  }
  DAT_006498d8 = arg1;
  DAT_006498dc = arg2;
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,DAT_00556c68,DAT_00556c5c,DAT_00558dc0,DAT_00557490,
               (int *)g_DisplaySurfaceBackBuffer,0x40,DAT_005574b0 * 2 + DAT_0052d77c + 0x10);
  *(undefined4 *)g_DisplaySurfaceScreen = local_20;
  return;
}


