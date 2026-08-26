/*
 * Decompiled function: FUN_00470b36
 * Entry Point: 00470b36
 * Size: 877 bytes
 */
#include "magic.h"


undefined4 FUN_00470b36(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  FUN_00473cc5((&DAT_0051aebe)[iVar1 * 0x34]);
  if (iVar1 == -1) {
    Magic_DiscardToHandSize();
    uVar3 = 0;
  }
  else {
    if (((&g_MasterCardColorTable)[iVar1 * 0x34] != '\x01') &&
       (((&g_MasterCardColorTable)[iVar1 * 0x34] != ' ' ||
        (((&DAT_0051aed1)[iVar1 * 0x34] & 0x10) == 0)))) {
      strcpy(&g_OverworldWorldState,s_Cast_00525c04);
      Ai_Subsystem_004b90de(arg1,arg2);
      FUN_00475c8a(-2,g_ScWillyScore,&g_OverworldWorldState,0x6c);
    }
    *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffffdf;
    *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 2;
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffffdf;
    if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == iVar1) {
      (&DAT_006a2828)[arg1] =
           (&DAT_006a2828)[arg1] | (uint)(byte)(&g_MasterCardColorTable)[iVar1 * 0x34];
      if (g_IsAiThinking != 1) {
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0) {
          Magic_UpkeepPhase(0x11);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) != 0) {
          Magic_UpkeepPhase(0);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 4) != 0) {
          Magic_UpkeepPhase(3);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x10) != 0) {
          Magic_UpkeepPhase(6);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x20) != 0) {
          Magic_UpkeepPhase(7);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 8) != 0) {
          Magic_UpkeepPhase(0x10);
        }
      }
      Magic_EndTurnPhase();
      uVar2 = DAT_006b2e14;
      uVar3 = DAT_00695f08;
      DAT_00695f08 = arg1;
      DAT_006b2e14 = arg2;
      FUN_00476205(g_DefendingPlayer,0xd3,s_Casting_00525c0c,0);
      DAT_00695f08 = uVar3;
      DAT_006b2e14 = uVar2;
      Pic_Subsystem_004475a4(arg1);
      DAT_0068a650 = 0xffffffff;
      DAT_0068a708 = 0xffffffff;
      if (g_ActivePlayer == 1) {
        if (g_IsAiThinking != 1) {
          Ai_Util_004cc42d(s_fizzle_00525c14);
          Sleep(2000);
          Ai_Util_004cc42d(&DAT_00525c1c);
        }
        DAT_00701008 = 1;
        g_ActivePlayer = 0;
        uVar3 = 0;
      }
      else {
        g_ActivePlayer = 0;
        Ai_Subsystem_004cc9c5(0,0xff);
        uVar3 = 1;
      }
    }
    else {
      Magic_DiscardToHandSize();
      uVar3 = 0;
    }
  }
  return uVar3;
}


