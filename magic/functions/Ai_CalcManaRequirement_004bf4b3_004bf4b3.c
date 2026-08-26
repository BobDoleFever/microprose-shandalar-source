/*
 * Decompiled function: Ai_CalcManaRequirement_004bf4b3
 * Entry Point: 004bf4b3
 * Size: 2929 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void Ai_CalcManaRequirement_004bf4b3(int card_id)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  DWORD DVar9;
  int *piVar10;
  char *local_420;
  char local_418 [1000];
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  DWORD local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar1 = DAT_00677e14;
  local_8 = DAT_00677e14;
  local_c = DAT_00677fc0;
  local_10 = *(undefined4 *)g_DisplaySurfaceBackBuffer;
  *(undefined4 *)g_DisplaySurfaceBackBuffer = 1;
  local_18 = ((int)((DAT_0067bddc - DAT_00641020) + (DAT_0067bddc - DAT_00641020 >> 0x1f & 0xfU)) >>
             4) + 1;
  if ((card_id == 0) ||
     ((((DAT_00522450 == 0xffffffff && (DAT_0067f35c == -1)) && (DAT_00627a7c == 0)) &&
      (DAT_00522454 == -1)))) {
    if (card_id != 0) {
      Ai_Subsystem_004be3c4(g_DisplaySurfaceScreen,0x181,0x135,DAT_00677e10,0xed,0x74);
    }
    goto LAB_004c002d;
  }
  _DAT_0052d7b4 = DAT_00522454;
  _DAT_0052d7b0 = DAT_00627a7c;
  _DAT_00557474 = DAT_0067f35c;
  local_20 = Ai_Util_004c3bc4(*(short *)(iVar1 + 6) + -0x13);
  if (DAT_0052f008 == 0) {
    local_24 = Ai_Util_004c3bc4(0x17c);
    iVar1 = Ai_Util_004c3bc4(0x13);
    DVar9 = *(DWORD *)(PTR_DAT_005174bc + 0x10);
    piVar10 = (int *)g_DisplaySurfaceBackBuffer;
    uVar6 = local_24;
    iVar2 = Ai_Util_004c3bc4(0x280);
    FUN_0050dce0((int *)PTR_DAT_005174bc,local_24,0,iVar2 - local_24,DVar9,piVar10,uVar6,iVar1);
    local_24 = Ai_Util_004c3bc4(0x181);
    iVar1 = DAT_00677e14;
    iVar2 = Ai_Util_004c3bc4((int)*(short *)(local_8 + 6));
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_8 + 4));
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,local_24,0,iVar3,iVar2,iVar1);
    if (DAT_00522450 != 0xffffffff) {
      iVar1 = (&DAT_00677fc0)[DAT_0067f37c & 7];
      iVar2 = Ai_Util_004c3bc4((int)*(short *)(local_c + 6));
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_c + 4));
      iVar4 = Ai_Util_004c3bc4(0x15);
      iVar5 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar5,iVar4,iVar3,iVar2,iVar1);
      iVar1 = *(int *)(&DAT_00677f50 + ((DAT_0067bddc - DAT_00641020) % 0xe) * 4);
      iVar2 = Ai_Util_004c3bc4((int)*(short *)(local_c + 6));
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_c + 4));
      iVar4 = Ai_Util_004c3bc4(0x15);
      iVar5 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar5,iVar4,iVar3,iVar2,iVar1);
      iVar1 = *(int *)(&DAT_00678360 + local_18 * 4);
      iVar2 = Ai_Util_004c3bc4((int)*(short *)(local_c + 6));
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_c + 4));
      iVar4 = Ai_Util_004c3bc4(0x15);
      iVar5 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar5,iVar4,iVar3,iVar2,iVar1);
    }
  }
  iVar1 = DAT_006776a0;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  local_2c = 0x5b - (int)*(short *)(iVar1 + 6) / 2;
  local_28 = DAT_006776a0;
  Ai_Subsystem_004be3c4
            (g_DisplaySurfaceBackBuffer,0x193,local_2c,DAT_006776a0,
             (int)*(short *)(DAT_006776a0 + 4),(int)*(short *)(DAT_006776a0 + 6));
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,DAT_0052d770,0x1a9,
               local_2c + (int)*(short *)(local_28 + 6) / 2);
  local_24 = Ai_Util_004c3bc4(0x17c);
  local_1c = 0x200;
  local_14 = 0x33;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 2;
  g_OverworldWorldState = 0;
  if (DAT_0067f35c == -1) {
    DAT_006410b0 = 0;
  }
  else {
    local_30 = 7;
    Adventure_FormatNewsString(DAT_0067f35c,0,0);
    strcat(&g_OverworldWorldState,s_attacking_0052db50);
    uVar6 = Duel_GetCardDrawOriginY
                      ((int)(*(int *)(&DAT_0067f2d4 + local_30 * 0x14) +
                            (*(int *)(&DAT_0067f2d4 + local_30 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&DAT_0067f2d8 + local_30 * 0x14) +
                            (*(int *)(&DAT_0067f2d8 + local_30 * 0x14) >> 0x1f & 0x1fU)) >> 5);
    Ai_TownEncounter_004c3b19(uVar6);
    strcat(&g_OverworldWorldState,&DAT_0052db5c);
  }
  if ((DAT_00627a7c != 0) || (DAT_00522454 != -1)) {
    strcat(&g_OverworldWorldState,s_Next_Duel__0052db60);
    if (DAT_00627a7c != 0) {
      strcat(&g_OverworldWorldState,&DAT_0052db6c + ((-1 < DAT_00627a7c) - 1 & 4));
      pcVar7 = _itoa(DAT_00627a7c,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar7);
      strcat(&g_OverworldWorldState,s_lives_0052db74);
      iVar1 = DAT_00677fac;
      iVar2 = Ai_Util_004c3bc4(0x25);
      iVar3 = Ai_Util_004c3bc4(0x1c);
      iVar4 = Ai_Util_004c3bc4(200);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,iVar4,iVar3,iVar2,iVar1);
    }
    if (DAT_00522454 == 0) {
      strcat(&g_OverworldWorldState,s_First_Move_0052db7c);
      iVar1 = DAT_00677fa4;
      iVar2 = Ai_Util_004c3bc4(0x25);
      iVar3 = Ai_Util_004c3bc4(0x1c);
      iVar4 = Ai_Util_004c3bc4(200);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,iVar4,iVar3,iVar2,iVar1);
    }
    if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
      strcat(&g_OverworldWorldState,&DAT_0052db88);
      pcVar7 = _itoa(DAT_00522454,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar7);
      strcat(&g_OverworldWorldState,s_lives_0052db8c);
      iVar1 = DAT_00677fa8;
      iVar2 = Ai_Util_004c3bc4(0x25);
      iVar3 = Ai_Util_004c3bc4(0x1c);
      iVar4 = Ai_Util_004c3bc4(200);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,iVar4,iVar3,iVar2,iVar1);
    }
    if (5 < DAT_00522454) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_00522454 * 0x34);
      iVar1 = DAT_00677fa0;
      iVar2 = Ai_Util_004c3bc4(0x25);
      iVar3 = Ai_Util_004c3bc4(0x1c);
      iVar4 = Ai_Util_004c3bc4(0x90);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,iVar4,iVar3,iVar2,iVar1);
    }
    strcat(&g_OverworldWorldState,&DAT_0052db94);
  }
  if (DAT_00522450 == 0xffffffff) {
LAB_004bfef2:
    FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,0xff,local_1c,0x41);
    iVar1 = Ai_Util_004c3bc4(0x148);
    DVar9 = local_20;
    piVar10 = (int *)g_DisplaySurfaceScreen;
    uVar6 = local_24;
    iVar2 = Ai_Util_004c3bc4(0x280);
    uVar8 = iVar2 - local_24;
    iVar2 = Ai_Util_004c3bc4(0x13);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_24,iVar2,uVar8,DVar9,piVar10,uVar6,iVar1);
  }
  else {
    if (DAT_0067f2c0 == 0) {
      strcat(&g_OverworldWorldState,s_Mana_Link_0052dbac);
    }
    else {
      if (*(int *)(&DAT_0067bdf0 + DAT_00522450 * 100) == 1) {
        pcVar7 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,pcVar7);
        strcat(&g_OverworldWorldState,s_mana_stone__0052db98);
      }
      else {
        FUN_0050a73e(DAT_00522450);
      }
      strcat(&g_OverworldWorldState,&DAT_0052dba8);
    }
    if ((((DAT_0067f2c0 != 0) && (DAT_0067f2c0 != 2)) &&
        ((DAT_0067f2c0 != 1 ||
         (iVar1 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3))), iVar1 == 0
         )))) && (-0x65 < DAT_0067f2c0)) {
      if (DAT_0067f2c0 == 1) {
        pcVar7 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,s_Find_0052dc18);
        Adventure_AppendNewsDetails((int)*pcVar7,0);
        strcat(&g_OverworldWorldState,pcVar7);
        strcat(&g_OverworldWorldState,&DAT_0052dc20);
        FUN_00484c45(1 << ((byte)DAT_00522450 & 3));
        strcat(&g_OverworldWorldState,&DAT_0052dc24);
      }
      if (DAT_0067f2c0 < 0) {
        strcat(&g_OverworldWorldState,s_Defeat_0052dc28);
        Adventure_FormatNewsString(-DAT_0067f2c0,0,0);
      }
      goto LAB_004bfef2;
    }
    strcpy(local_418,&g_OverworldWorldState);
    local_18 = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                            *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
    if (DAT_0067f3bc != local_18) {
      DAT_0067f3bc = -1;
    }
    strcpy(&g_OverworldWorldState,local_418);
    switch(DAT_0067f3bc) {
    case 0:
      strcat(&g_OverworldWorldState,s_Go_North_to_0052dbe4);
      break;
    case 1:
      strcat(&g_OverworldWorldState,s_Go_East_to_0052dbf0);
      break;
    case 2:
      strcat(&g_OverworldWorldState,s_Go_South_to_0052dbfc);
      break;
    case 3:
      strcat(&g_OverworldWorldState,s_Go_West_to_0052dc08);
      break;
    case -1:
      if (DAT_0067f2c0 < 0) {
        strcat(&g_OverworldWorldState,s_Return_to_0052dbb8);
      }
      else {
        if ((DAT_0067f2c0 == 0) || (DAT_0067f2c0 == 2)) {
          local_420 = s_Take_letter_to_0052dbc4;
        }
        else {
          local_420 = s_Take_card_to_0052dbd4;
        }
        strcat(&g_OverworldWorldState,local_420);
      }
    }
    strcat(&g_OverworldWorldState,&DAT_0052dc14);
    Ai_TownEncounter_004c3b19(DAT_00522450);
    FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,0xff,local_1c,0x41);
    iVar1 = Ai_Util_004c3bc4(0x148);
    DVar9 = local_20;
    piVar10 = (int *)g_DisplaySurfaceScreen;
    uVar6 = local_24;
    iVar2 = Ai_Util_004c3bc4(0x280);
    uVar8 = iVar2 - local_24;
    iVar2 = Ai_Util_004c3bc4(0x13);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_24,iVar2,uVar8,DVar9,piVar10,uVar6,iVar1);
  }
  if ((DAT_00522450 != 0xffffffff) && (DAT_0067bddc <= DAT_00641020)) {
    FUN_0040b3c2(0x11,DAT_0067f2c0);
    strcpy(&g_OverworldWorldState,s_The_people_of_0052dc30);
    Ai_TownEncounter_004c3b19(DAT_0067f370);
    strcat(&g_OverworldWorldState,s_are_sorry_their_quest_was_not_co_0052dc40);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    FUN_004896be(&g_OverworldWorldState,0x5a,0x50);
    *(uint *)(&DAT_0067be00 + DAT_0067f370 * 100) =
         *(uint *)(&DAT_0067be00 + DAT_0067f370 * 100) | 4;
    DAT_00522450 = 0xffffffff;
    Ai_Subsystem_004c05ba();
  }
LAB_004c002d:
  *(undefined4 *)g_DisplaySurfaceBackBuffer = local_10;
  return;
}


