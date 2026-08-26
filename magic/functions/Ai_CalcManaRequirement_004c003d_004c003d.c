/*
 * Decompiled function: Ai_CalcManaRequirement_004c003d
 * Entry Point: 004c003d
 * Size: 1380 bytes
 */
#include "magic.h"


void Ai_CalcManaRequirement_004c003d(void)

{
  uint arg_1;
  char *pcVar1;
  int iVar2;
  char *local_114;
  char local_10c [256];
  int local_c;
  int local_8;
  
  g_OverworldWorldState = 0;
  if (DAT_0067f35c != -1) {
    local_c = 7;
    Adventure_FormatNewsString(DAT_0067f35c,0,0);
    strcat(&g_OverworldWorldState,s_attacking_0052dc6c);
    arg_1 = Duel_GetCardDrawOriginY
                      ((int)(*(int *)(&DAT_0067f2d4 + local_c * 0x14) +
                            (*(int *)(&DAT_0067f2d4 + local_c * 0x14) >> 0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&DAT_0067f2d8 + local_c * 0x14) +
                            (*(int *)(&DAT_0067f2d8 + local_c * 0x14) >> 0x1f & 0x1fU)) >> 5);
    Ai_TownEncounter_004c3b19(arg_1);
    strcat(&g_OverworldWorldState,&DAT_0052dc78);
  }
  if ((DAT_00627a7c != 0) || (DAT_00522454 != -1)) {
    strcat(&g_OverworldWorldState,s_Next_Duel__0052dc7c);
    if (DAT_00627a7c != 0) {
      pcVar1 = _itoa(DAT_00522454,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_lives_0052dc88);
    }
    if (DAT_00522454 == 0) {
      strcat(&g_OverworldWorldState,s_First_Move_0052dc90);
    }
    if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
      strcat(&g_OverworldWorldState,&DAT_0052dc9c);
      pcVar1 = _itoa(DAT_00522454,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_lives_0052dca0);
    }
    if (5 < DAT_00522454) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_00522454 * 0x34);
    }
    strcat(&g_OverworldWorldState,&DAT_0052dca8);
  }
  if ((DAT_0067b9a4 == 0) && (DAT_00522450 != 0xffffffff)) {
    if (DAT_0067f2c0 == 0) {
      strcat(&g_OverworldWorldState,s_Mana_Link_0052dcc0);
    }
    else if (*(int *)(&DAT_0067bdf0 + DAT_00522450 * 100) == 1) {
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_mana_stone__0052dcac);
    }
    else {
      FUN_0050a73e(DAT_00522450);
      strcat(&g_OverworldWorldState,&DAT_0052dcbc);
    }
    if ((((DAT_0067f2c0 == 0) || (DAT_0067f2c0 == 2)) ||
        ((DAT_0067f2c0 == 1 &&
         (iVar2 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3))), iVar2 != 0
         )))) || (DAT_0067f2c0 < -100)) {
      strcpy(local_10c,&g_OverworldWorldState);
      local_8 = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + DAT_00522450 * 100),
                             *(int *)(&DAT_0067bdf8 + DAT_00522450 * 100));
      strcpy(&g_OverworldWorldState,local_10c);
      if (DAT_0067f3bc != local_8) {
        DAT_0067f3bc = -1;
      }
      switch(DAT_0067f3bc) {
      case 0:
        strcat(&g_OverworldWorldState,s_Go_North_to_0052dcf8);
        break;
      case 1:
        strcat(&g_OverworldWorldState,s_Go_East_to_0052dd04);
        break;
      case 2:
        strcat(&g_OverworldWorldState,s_Go_South_to_0052dd10);
        break;
      case 3:
        strcat(&g_OverworldWorldState,s_Go_West_to_0052dd1c);
        break;
      case -1:
        if (DAT_0067f2c0 < 0) {
          strcat(&g_OverworldWorldState,s_Return_to_0052dccc);
        }
        else {
          if ((DAT_0067f2c0 == 0) || (DAT_0067f2c0 == 2)) {
            local_114 = s_Take_letter_to_0052dcd8;
          }
          else {
            local_114 = s_Take_card_to_0052dce8;
          }
          strcat(&g_OverworldWorldState,local_114);
        }
      }
      strcat(&g_OverworldWorldState,&DAT_0052dd28);
      Ai_TownEncounter_004c3b19(DAT_00522450);
      strcat(&g_OverworldWorldState,&DAT_0052dd2c);
    }
    else {
      if (DAT_0067f2c0 == 1) {
        pcVar1 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,s_Find_0052dd30);
        Adventure_AppendNewsDetails((int)*pcVar1,0);
        strcat(&g_OverworldWorldState,pcVar1);
        strcat(&g_OverworldWorldState,&DAT_0052dd38);
        FUN_00484c45(1 << ((byte)DAT_00522450 & 3));
        strcat(&g_OverworldWorldState,&DAT_0052dd3c);
      }
      if (DAT_0067f2c0 < 0) {
        strcat(&g_OverworldWorldState,s_Defeat_0052dd40);
        Adventure_FormatNewsString(-DAT_0067f2c0,0,0);
        strcat(&g_OverworldWorldState,&DAT_0052dd48);
      }
    }
  }
  return;
}


