/*
 * Decompiled function: Pic_Subsystem_00447b57
 * Entry Point: 00447b57
 * Size: 2677 bytes
 */
#include "magic.h"


int Pic_Subsystem_00447b57(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  int arg_3;
  int local_14;
  int local_c;
  
  DAT_0063ee88 = 1;
  *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x800;
  iVar1 = FUN_00471c32(arg1,arg2);
  if (((((iVar1 == 0) || (g_ScWillyScore != 0x15)) || (g_DefendingPlayer != arg1)) ||
      ((((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0 ||
       (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)))) ||
     (iVar1 = FUN_004726c5(arg1,arg2), iVar1 == 0)) {
    if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (g_PlayerManaPool == -1))
    {
      if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) &&
         ((g_PlayerManaPool != -1 &&
          (*(code **)(&DAT_0051aec8 +
                     *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34) !=
           Prompts_Load_00416f1a)))) {
        local_c = 0;
      }
      else if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) ||
              (g_ScWillyScore != 1)) {
        if (g_CurrentTurnPhase == arg1) {
          iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
          if ((DAT_0063ee10 == 0) && ((g_ScWillyScore == 0x15 || (g_ScWillyScore == 0x17)))) {
            if (((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) &&
                (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
               (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) {
              if (((g_DefendingPlayer == arg1) && (iVar1 = FUN_004726c5(arg1,arg2), iVar1 != 0)) &&
                 (((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0)) {
                DAT_0063ee88 = 0;
                return 0x10;
              }
              if ((g_DefendingPlayer != arg1) && (DAT_006a5f20 != 0)) {
                DAT_0063ee88 = 0;
                return 0x20;
              }
            }
            *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            local_c = 0;
          }
          else {
            if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
              if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
                *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                DAT_0063ee88 = 0;
                return 0;
              }
              FUN_00473cc5((&DAT_0051aebe)[iVar1 * 0x34]);
              if ((DAT_0063ee10 == 0) ||
                 ((DAT_0063edc8 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
                if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 1) != 0) {
                  if (((g_DefendingPlayer == arg1) && (((byte)g_PlayerHandCardCount & 1) == 0)) &&
                     ((g_ScWillyScore == 0x14 || (g_ScWillyScore == 0x1e)))) {
                    DAT_0063ee88 = 0;
                    return 4;
                  }
                  *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                       *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                  DAT_0063ee88 = 0;
                  return 0;
                }
                if (((g_DefendingPlayer == g_CurrentTurnPhase) ||
                    (((g_DefendingPlayer != g_CurrentTurnPhase && (DAT_0063ee10 != 0)) &&
                     ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x10) != 0 ||
                      (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x20) != 0)))))) &&
                   ((iVar2 = FUN_00470ea3(arg1,arg1,arg2), iVar2 != 0 &&
                    (((((byte)g_PlayerHandCardCount & 4) == 0 ||
                      ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x3004) != 0)) &&
                     ((((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x42) != 0 ||
                      (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x74,1 - arg1,0xffffffff),
                      iVar1 != 0)))))))) {
                  DAT_0063ee88 = 0;
                  return 4;
                }
              }
            }
            else {
              if ((DAT_00695ec4 == 4) &&
                 (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
                DAT_006a4920 = DAT_006a4920 | 3;
                DAT_00695f0c = DAT_00695f0c | 4;
                DAT_0063ee88 = 0;
                return 2;
              }
              if ((((DAT_00695ec4 == 4) &&
                   (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
                  (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0)) &&
                 (iVar2 = FUN_00476675(arg1,arg2), iVar2 != 0)) {
                DAT_00695f0c = DAT_00695f0c | 2;
                DAT_0063ee88 = 0;
                return 8;
              }
              if (((((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) &&
                    (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) &&
                   ((DAT_0063ee10 == 0 && ((g_DefendingPlayer == arg1 && (g_ScWillyScore < 0x1b)))))
                   ) && (iVar2 = FUN_004726c5(arg1,arg2), iVar2 != 0)) &&
                 ((((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                  (((&g_MasterCardColorTable)
                    [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0))
                 )) {
                DAT_0063ee78 = 1;
              }
              if (((((((&DAT_0051aed1)[iVar1 * 0x34] & 0x10) != 0) &&
                    (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
                   ((((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                    (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0
                    )))) || (((((&DAT_0051aed0)[iVar1 * 0x34] & 1) != 0 &&
                              ((DAT_0063edc8 & 0x10) != 0)) ||
                             ((((&DAT_0051aed0)[iVar1 * 0x34] & 2) != 0 &&
                              ((DAT_0063edc8 & 0x20) != 0)))))) &&
                 ((((((byte)g_PlayerHandCardCount & 4) == 0 ||
                    ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x5004) != 0)) &&
                   (DAT_006a4920 = DAT_006a4920 & 0xfffffffd,
                   ((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)) &&
                  (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x73,1 - arg1,0xffffffff), iVar1 != 0)))
                 ) {
                if ((DAT_006a4920 & 2) != 0) {
                  DAT_00695f0c = DAT_00695f0c | 4;
                  DAT_0063ee88 = 0;
                  return 2;
                }
                DAT_00695f0c = DAT_00695f0c | 2;
                DAT_0063ee88 = 0;
                return 8;
              }
            }
            *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            local_c = 0;
          }
        }
        else if ((DAT_00695ec4 == 4) &&
                (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
          DAT_006a4920 = DAT_006a4920 | 3;
          DAT_00695f0c = DAT_00695f0c | 4;
          local_c = 2;
        }
        else {
          *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
          local_c = 0;
        }
      }
      else {
        g_OverworldPlayerCoordX = arg1;
        g_OverworldMapGrid = arg2;
        g_ActivePalette = 0;
        Magic_ScanCards(0x7d);
        local_c = g_ActivePalette;
      }
    }
    else {
      if (*(int *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) == g_PlayerManaPool) {
        if (arg1 == DAT_006a4b5c) {
          local_14 = 2;
        }
        else {
          local_14 = 0;
        }
      }
      else {
        arg_3 = 2;
        iVar2 = 0;
        iVar1 = Pic_Subsystem_004485d6(arg1,arg2,0x7d,arg1);
        local_14 = FUN_0040a305(iVar1,iVar2,arg_3);
      }
      if (local_14 == 0) {
        local_c = 0;
      }
      else {
        DAT_00695f0c = DAT_00695f0c | 1 << ((byte)local_14 & 0x1f);
        DAT_0068a714 = DAT_0068a714 + 1;
        local_c = local_14;
      }
    }
  }
  else {
    local_c = 2;
  }
  DAT_0063ee88 = 0;
  return local_c;
}


