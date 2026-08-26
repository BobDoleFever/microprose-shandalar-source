/*
 * Decompiled function: Pic_Subsystem_0042f2f8
 * Entry Point: 0042f2f8
 * Size: 915 bytes
 */
#include "magic.h"


uint Pic_Subsystem_0042f2f8(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == arg_1) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 0x40;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 0x40;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (local_8 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
      }
    }
    if ((arg_3 == 0x71) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      if (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    if (((arg_3 == 0x7c) &&
        (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid
        )) && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
                g_OverworldPlayerCoordX &&
               ((g_OverworldMapGrid != -1 &&
                (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0))))))
    {
      Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,2,arg_1,arg_2);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    if (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
      if (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x10) == 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0) {
        Mem_AllocOrFree_0041df33(g_OverworldPlayerCoordX,2,arg_1,arg_2);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


