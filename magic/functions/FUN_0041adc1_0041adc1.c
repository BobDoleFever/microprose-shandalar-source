/*
 * Decompiled function: FUN_0041adc1
 * Entry Point: 0041adc1
 * Size: 995 bytes
 */
#include "magic.h"


undefined4 FUN_0041adc1(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar3 = 0;
    }
    else if ((g_ActivePlayerPriority == arg_1) && (iVar2 = FUN_0040d949(arg_1,7,2), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      local_c = (int)(char)(&DAT_0051aec0)
                           [*(int *)(&g_CardSlot_CardId +
                                    DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20) * 0x34];
      if (local_c == -1) {
        local_c = g_TurnCounter;
      }
      cVar1 = (&DAT_0051aebf)
              [*(int *)(&g_CardSlot_CardId + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20) * 0x34];
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = cVar1 + local_c;
      iVar2 = FUN_0040d949(arg_1,2,1);
      if (((iVar2 == 0) || (iVar2 = FUN_0040d949(arg_1,7,cVar1 + local_c + 1), iVar2 == 0)) ||
         (iVar2 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                             0xffffffff,0xffffffff,2,0,0), iVar2 == 0)) {
        uVar3 = 0;
      }
      else {
        DAT_006fe3f4 = 1;
        uVar3 = 99;
      }
    }
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (DAT_006b2d3c != -1)) {
      DAT_006b2d48 = 1;
      Ai_CalcManaRequirement_004ba890
                (arg_1,0,*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (g_ActivePlayer != 1) {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        g_TurnCounter = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (arg_3 == 0x71) {
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x20
               ) != 0) {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


