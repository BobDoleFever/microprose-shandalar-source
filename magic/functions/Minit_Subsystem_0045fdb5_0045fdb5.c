/*
 * Decompiled function: Minit_Subsystem_0045fdb5
 * Entry Point: 0045fdb5
 * Size: 711 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045fdb5(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x77) &&
       ((&DAT_006a5f50)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] != '\0')) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) * 0x34] & 1) != 0)) &&
     ((&DAT_006a5f50)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] != '\x04')) {
    if (g_OverworldPlayerCoordX == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) + 1;
    }
    else {
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) + 0x100;
    }
  }
  if ((((g_PlayerManaPool == 0xd5) && (arg_2 == g_OverworldMapGrid)) &&
      ((arg_1 == g_OverworldPlayerCoordX &&
       (((*(uint *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffff) != 0
        && (arg_1 == DAT_006a4b5c)))))) &&
     ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) != 0)))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        if ((&g_CardSlot_ConvertedManaCost)[arg_1 * 0x5b20 + arg_2 * 0x120] != '\0') {
          for (local_c = 0;
              local_c < (int)(*(uint *)(&g_CardSlot_ConvertedManaCost +
                                       arg_1 * 0x5b20 + arg_2 * 0x120) & 0xff);
              local_c = local_c + 1) {
            Mem_AllocOrFree_0041df33(local_8,2,arg_1,arg_2);
          }
        }
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) >> 8;
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
  }
  return 0;
}


