/*
 * Decompiled function: Pic_Subsystem_0042881e
 * Entry Point: 0042881e
 * Size: 1340 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042881e(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      iVar2 = FUN_0041d963(arg_1,arg_2,1);
      iVar2 = FUN_0041d8a6(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) = iVar2;
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             (int)(char)(&DAT_006a6030)[arg_1 * 0x5b20 + arg_2 * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] | 2;
        *(uint *)(&DAT_0051aed0 +
                 *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34) =
             *(uint *)(&DAT_0051aed0 +
                      *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34) |
             0x8000;
        *(undefined2 *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34)
             = 1;
        *(undefined2 *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34)
             = 1;
        (&DAT_0051aebf)[*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] =
             1;
      }
    }
    if ((int)(char)(&DAT_006a6030)[arg_1 * 0x5b20 + arg_2 * 0x120] !=
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120));
      iVar2 = FUN_0041d963(arg_1,arg_2,1);
      iVar2 = FUN_0041d8a6(iVar2 + -1);
      if (iVar2 != -1) {
        *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) = iVar2;
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             (int)(char)(&DAT_006a6030)[arg_1 * 0x5b20 + arg_2 * 0x120];
        (&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] =
             (&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] | 2;
        *(uint *)(&DAT_0051aed0 +
                 *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34) =
             *(uint *)(&DAT_0051aed0 +
                      *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34) |
             0x8000;
        *(undefined2 *)
         (&DAT_0051aec2 + *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34)
             = 1;
        *(undefined2 *)
         (&DAT_0051aec4 + *(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34)
             = 1;
        (&DAT_0051aebf)[*(int *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] =
             1;
      }
    }
    if ((arg_3 == 0x3c) && (iVar2 = FUN_00471c32(arg_1,arg_2), iVar2 != 0)) {
      if ((g_PlayerHandCardCount & 0x20000) == 0) {
        g_PlayerHandCardCount = g_PlayerHandCardCount | 0x10000;
      }
      else {
        iVar2 = FUN_00471c32(g_OverworldPlayerCoordX,g_OverworldMapGrid);
        if (((iVar2 != 0) &&
            (iVar3 = g_OverworldMapGrid * 0x120, iVar4 = g_OverworldPlayerCoordX * 0x5b20,
            iVar2 = FUN_0041d963(arg_1,arg_2,1),
            *(int *)(&g_CardSlot_CardId + iVar4 + iVar3) == iVar2 + -1)) &&
           ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0 ||
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) != 0)))) {
          g_ActivePalette = *(undefined4 *)(&g_CardSlot_Controller + arg_1 * 0x5b20 + arg_2 * 0x120)
          ;
          *(uint *)(&g_CardSlot_Abilities1 +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
               *(uint *)(&g_CardSlot_Abilities1 +
                        g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x40;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


