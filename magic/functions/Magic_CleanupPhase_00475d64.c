/*
 * Decompiled function: Magic_CleanupPhase
 * Entry Point: 00475d64
 * Size: 1185 bytes
 */
#include "magic.h"


int Magic_CleanupPhase(int x,int y,char *str_3,undefined4 arg_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_98;
  int local_94;
  char local_8c [128];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = DAT_006a4920;
  uVar2 = DAT_00695ec4;
  uVar1 = DAT_006808b0;
  local_c = g_PlayerManaPool;
  g_PlayerManaPool = 0xffffffff;
  DAT_006ff684 = DAT_006ff684 + 1;
  if (DAT_006ff684 == 1) {
    DAT_006b2d24 = 0;
  }
  else if ((((DAT_006b2d24 < DAT_006ff684) && (y != 0x8e)) && (y != 0x70)) && (y != 0xd3)) {
    DAT_006b2d24 = DAT_006ff684;
  }
  local_94 = 0;
  DAT_00695ec4 = arg_4;
  local_8 = DAT_00525850;
  if ((x == -2) && (iVar4 = FUN_00505c74(), iVar4 == 0)) {
    DAT_00525850 = 1;
  }
  else {
    DAT_00525850 = 0;
  }
  iVar4 = FUN_00505c74();
  if ((iVar4 == 0) &&
     ((*(int *)(&DAT_00696740 + g_DefendingPlayer * 0x98 + y * 4) != 0 ||
      ((g_DefendingPlayer == DAT_00627a84 && (y == DAT_00627a88)))))) {
    DAT_006808b0 = 1;
  }
  else {
    DAT_006808b0 = 0;
  }
  if ((-1 < x) && (DAT_006808b0 == 0)) {
LAB_0047615d:
    DAT_006ff684 = DAT_006ff684 + -1;
    if ((DAT_006ff684 == 0) && (DAT_0063edc8 = 0xffffffff, DAT_006fd3f0 == 0)) {
      DAT_0063ee1c = 0;
      DAT_0063edc4 = 0;
    }
    DAT_0063ee70 = 0xffffffff;
    DAT_006808b0 = uVar1;
    DAT_00525850 = local_8;
    DAT_006a4920 = uVar3;
    g_PlayerManaPool = local_c;
    DAT_00695ec4 = uVar2;
    if (local_94 != 0) {
      DAT_00633434 = 0;
    }
    return local_94;
  }
  strcpy(local_8c,str_3);
  if ((g_ScWillyScore == 4) && (DAT_006ff684 == 1)) {
    DAT_0063edc0 = g_DefendingPlayer;
    FUN_00476b0e();
  }
  do {
    do {
      if (g_DefendingPlayer == 0) {
        DAT_0068a67c = 1;
      }
      else if (x < 0) {
        DAT_0068a67c = 2;
      }
      else {
        DAT_0068a67c = 0;
      }
      if (DAT_006ff684 < 2) {
        DAT_0063ee70 = 0xffffffff;
      }
      g_ActivePlayer = 0;
      DAT_006a4920 = 0;
      local_98 = Pic_Subsystem_004458b0(g_DefendingPlayer,local_8c);
      if (local_98 != 0) {
        DAT_006ff380 = 1;
      }
      if (((g_DefendingPlayer == g_CurrentTurnPhase) && (local_98 != 0)) && (g_IsAiThinking != 1)) {
        local_94 = 1;
      }
      if ((DAT_006ff684 < DAT_006b2d24) && (-1 < DAT_006a3f78)) {
        local_98 = 0;
      }
    } while ((local_98 != 0) || (((DAT_006a4920 & 1) != 0 && (DAT_006ff684 == 1))));
    if ((g_ScWillyScore == 4) && (DAT_006ff684 == 1)) {
      DAT_0063edc0 = 1 - g_DefendingPlayer;
      FUN_00476b0e();
    }
    while( true ) {
      if (g_DefendingPlayer == 0) {
        if (x < 0) {
          DAT_0068a67c = 2;
        }
        else {
          DAT_0068a67c = 0;
        }
      }
      else {
        DAT_0068a67c = 1;
      }
      if (DAT_006ff684 < 2) {
        DAT_0063ee70 = 0xffffffff;
      }
      g_ActivePlayer = 0;
      DAT_006a4920 = 0;
      if (((DAT_006ff684 < DAT_006b2d24) && (-1 < DAT_006a3f78)) ||
         (iVar4 = Pic_Subsystem_004458b0(1 - g_DefendingPlayer,local_8c), iVar4 == 0))
      goto LAB_0047615d;
      DAT_006ff380 = 1;
      if (g_IsAiThinking != 1) break;
      if ((g_DefendingPlayer != g_CurrentTurnPhase) &&
         (((DAT_006a4920 & 1) == 0 || (DAT_006ff684 != 1)))) goto LAB_0047615d;
    }
  } while( true );
}


