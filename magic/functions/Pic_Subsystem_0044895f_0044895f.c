/*
 * Decompiled function: Pic_Subsystem_0044895f
 * Entry Point: 0044895f
 * Size: 1226 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0044895f(int arg1,int arg2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  cVar1 = (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20];
  if (cVar1 != '\0') {
    if ((((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0) &&
       ((&g_MasterCardColorTable)[iVar2 * 0x34] != -0x80)) {
      if ((cVar1 != '\x04') &&
         ((((&g_MasterCardColorTable)[iVar2 * 0x34] & 2) != 0 &&
          (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)))) {
        DAT_006b303c = DAT_006b303c + 1;
      }
      if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x47) != 0) {
        Magic_PayManaCost();
        g_ActivePalette = 0;
        g_OverworldPlayerCoordX = arg1;
        g_OverworldMapGrid = arg2;
        DAT_007006c8 = 1 - arg1;
        DAT_006b2d5c = 0xffffffff;
        Magic_ScanCards(0x77);
        if (0 < g_ActivePalette) {
          *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
          Magic_TapCardForMana();
          return 0;
        }
        cVar1 = (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20];
        Magic_TapCardForMana();
      }
      if (((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
        if (cVar1 == '\x04') {
          Pic_Subsystem_0044929c
                    ((*(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x1000) >> 0xc,
                     *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20));
        }
        else {
          if ((cVar1 != '\x03') && (g_IsAiThinking != 1)) {
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0) {
              if (((&g_MasterCardColorTable)
                   [*(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x38) ==
                  0) {
                Magic_UpkeepPhase(1);
              }
            }
            else {
              Magic_UpkeepPhase(0x19);
            }
          }
          Pic_Subsystem_0044913a(arg1,arg2);
          if (cVar1 == '\x03') {
            FUN_00476205(g_DefendingPlayer,0xd5,s_Card_s__to_Graveyard_00522210,0);
          }
        }
      }
    }
    Magic_PayManaCost();
    uVar4 = DAT_006b2e14;
    uVar3 = DAT_00695f08;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x47) != 0) {
      FUN_00476205(g_DefendingPlayer,0xd4,s_Card_leaving_play_00522228,0);
    }
    DAT_00695f08 = uVar3;
    DAT_006b2e14 = uVar4;
    Magic_TapCardForMana();
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg1 * 4) = *(int *)(&DAT_006b3010 + arg1 * 4) + -1;
    }
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg1] = (&DAT_006b3018)[arg1] + -1;
    }
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg1 * 4) = *(int *)(&DAT_006b3020 + arg1 * 4) + -1;
    }
    *(undefined4 *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
    (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(undefined4 *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    if (g_IsAiThinking != 1) {
      Ai_Subsystem_004cc3f8(arg1,arg2,7,2);
    }
    Pic_Subsystem_00448e29(arg1,arg2);
    if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 0x47) != 0) {
      FUN_00472fae();
    }
  }
  return 0;
}


