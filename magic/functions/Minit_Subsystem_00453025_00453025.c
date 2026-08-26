/*
 * Decompiled function: Minit_Subsystem_00453025
 * Entry Point: 00453025
 * Size: 716 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00453025(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (arg_3 == 1) {
    iVar2 = FUN_00473cc5((&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20]);
    uVar3 = Minit_Subsystem_004528c0(arg_1,arg_2,1,iVar2);
  }
  else {
    if (arg_3 == 0x71) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x25);
      }
      if (arg_1 == g_CurrentTurnPhase) {
        cVar1 = FUN_0040a1d2(5);
        (&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20] = (char)(1 << (cVar1 + 1U & 0x1f));
      }
      else {
        (&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_00679ed0;
      }
    }
    if (arg_3 == 0x73) {
      iVar2 = FUN_00473cc5((&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      uVar3 = Minit_Subsystem_004528c0(arg_1,arg_2,0x73,iVar2);
    }
    else if (arg_3 == 0x6d) {
      iVar2 = FUN_00473cc5((&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      uVar3 = Minit_Subsystem_004528c0(arg_1,arg_2,0x6d,iVar2);
    }
    else {
      if (arg_3 == 0x72) {
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x25);
        }
        if (arg_1 == g_CurrentTurnPhase) {
          cVar1 = FUN_0040a1d2(5);
          (&DAT_006a5f4c)
          [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] =
               (char)(1 << (cVar1 + 1U & 0x1f));
        }
        else {
          (&DAT_006a5f4c)
          [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] =
               DAT_00679ed0;
        }
      }
      if (arg_3 == 0x7f) {
        iVar2 = FUN_00473cc5((&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        uVar3 = Minit_Subsystem_004528c0(arg_1,arg_2,0x7f,iVar2);
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}


