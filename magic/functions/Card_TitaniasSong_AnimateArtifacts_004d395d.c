/*
 * Decompiled function: Card_TitaniasSong_AnimateArtifacts
 * Entry Point: 004d395d
 * Size: 960 bytes
 */
#include "magic.h"


undefined4 Card_TitaniasSong_AnimateArtifacts(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  uint uVar2;
  int arg1;
  int iVar3;
  int iVar4;
  
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) == DAT_006ff2e0)) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == -1)) &&
      (((char)(&g_CardSlot_DamageReceived)
              [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] == arg_1 &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != 0)) {
    (&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (undefined1)g_OverworldPlayerCoordX;
    *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) = g_OverworldMapGrid;
  }
  if (((g_PlayerManaPool == 0xd7) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      (((&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1 &&
       (arg_1 == DAT_006a4b5c)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      cVar1 = (&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120];
      arg1 = (int)cVar1;
      iVar3 = Pic_Subsystem_00451291(arg1,DAT_006a28ac);
      if (iVar3 != -1) {
        *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + iVar3 * 0x120) | 2;
        *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + iVar3 * 0x120) | 8;
        (&DAT_006a5f4d)[arg1 * 0x5b20 + iVar3 * 0x120] =
             (&DAT_006a5f4d)[arg_1 * 0x5b20 + arg_2 * 0x120];
        uVar2 = *(uint *)(&g_MasterCardTypeTable +
                         *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
        iVar4 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable +
                                     *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) *
                                     0x34),arg_1,arg_2);
        *(uint *)(&DAT_006a5f74 + arg1 * 0x5b20 + iVar3 * 0x120) = uVar2 | iVar4 << 0x10;
        (&g_CardSlot_DamageReceived)[arg1 * 0x5b20 + iVar3 * 0x120] = (undefined1)arg_1;
        *(int *)(&g_CardSlot_TypeFlags + arg1 * 0x5b20 + iVar3 * 0x120) = arg_2;
        (&g_CardSlot_Toughness)[arg1 * 0x5b20 + iVar3 * 0x120] = cVar1;
        *(undefined4 *)(&g_CardSlot_OriginalCardId + arg1 * 0x5b20 + iVar3 * 0x120) = 0xffffffff;
      }
      (&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] = 0xff;
    }
  }
  return 0;
}


