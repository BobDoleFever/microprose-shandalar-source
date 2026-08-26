/*
 * Decompiled function: Pic_Subsystem_004336f8
 * Entry Point: 004336f8
 * Size: 934 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004336f8(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  int local_18;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar4 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (g_CurrentTurnPhase == arg_1) {
        iVar5 = FUN_0040a1d2(5);
        local_18 = iVar5 + 1;
      }
      else {
        local_8 = -1;
        for (local_c = 1; local_c < 7; local_c = local_c + 1) {
          if (local_8 < *(int *)(&DAT_006b2e40 + local_c * 4 + (1 - arg_1) * 0x20) +
                        *(int *)(&DAT_006b2fa0 + local_c * 4 + (1 - arg_1) * 0x20)) {
            local_8 = *(int *)(&DAT_006b2fa0 + local_c * 4 + (1 - arg_1) * 0x20) +
                      *(int *)(&DAT_006b2fa0 + local_c * 4 + (1 - arg_1) * 0x20);
            local_18 = local_c;
          }
        }
      }
      if (arg_1 == 1) {
        local_1c = local_18;
      }
      else {
        local_1c = -1;
      }
      iVar5 = Ai_Subsystem_004cc93d(arg_1,s_Jihad_color__005214b8,1,local_1c,0xffffffff);
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = iVar5;
      if (iVar5 == -1) {
        g_ActivePlayer = 1;
      }
    }
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       ((((byte)*(undefined4 *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x22) == 2 &&
        ((((byte)*(undefined4 *)
                  (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                  ) & 0x22) == 2 &&
         (cVar1 = (&DAT_006a5f4c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120],
         bVar3 = FUN_0041d9d2(arg_1,arg_2,5), (1 << (bVar3 & 0x1f) & (int)cVar1) != 0)))))) {
      if (arg_3 == 0x32) {
        g_ActivePalette = g_ActivePalette + 2;
      }
      else {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0) &&
        (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      bVar2 = false;
      iVar5 = 1 - arg_1;
      bVar3 = (&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20];
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[iVar5]; local_c = local_c + 1) {
        iVar6 = FUN_00471c32(iVar5,local_c);
        if (((iVar6 != 0) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + iVar5 * 0x5b20) * 0x34] & 0x1e) != 0)
            ) && ((1 << (bVar3 & 0x1f) &
                  (int)(char)(&DAT_006a5f4d)[local_c * 0x120 + iVar5 * 0x5b20]) != 0)) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}


