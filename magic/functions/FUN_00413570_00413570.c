/*
 * Decompiled function: FUN_00413570
 * Entry Point: 00413570
 * Size: 761 bytes
 */
#include "magic.h"


undefined4 FUN_00413570(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  if ((((((&DAT_006a5f6b)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
             g_OverworldPlayerCoordX)) &&
     ((g_OverworldMapGrid != -1 && ((arg_3 == 0x32 || (arg_3 == 0x33)))))) {
    local_14 = 0;
    local_10 = 0;
    iVar2 = (int)(char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120];
    local_8 = 0;
    bVar1 = false;
    while ((local_8 < (int)(&g_PlayerActiveCardCount)[iVar2] && (!bVar1))) {
      if ((((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + iVar2 * 0x5b20) == DAT_00701000) &&
           (((&g_CardSlot_Flags)[local_8 * 0x120 + iVar2 * 0x5b20] & 2) != 0)) &&
          ((&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
           (&g_CardSlot_Toughness)[local_8 * 0x120 + iVar2 * 0x5b20])) &&
         (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + iVar2 * 0x5b20))) {
        bVar1 = true;
        local_10 = -(int)*(short *)(&DAT_006a5f48 + local_8 * 0x120 + iVar2 * 0x5b20);
        local_14 = -(int)*(short *)(&DAT_006a5f4a + local_8 * 0x120 + iVar2 * 0x5b20);
      }
      local_8 = local_8 + 1;
    }
    if (arg_3 == 0x32) {
      g_ActivePalette =
           g_ActivePalette + *(short *)(&DAT_006a5f48 + arg_1 * 0x5b20 + arg_2 * 0x120) + local_10;
    }
    else {
      g_ActivePalette =
           g_ActivePalette + *(short *)(&DAT_006a5f4a + arg_1 * 0x5b20 + arg_2 * 0x120) + local_14;
    }
  }
  if ((((&g_CardSlot_Abilities1)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0) &&
     ((arg_3 == 0x22 || (arg_3 == 199)))) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


