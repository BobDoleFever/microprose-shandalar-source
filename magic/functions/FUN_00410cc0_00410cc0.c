/*
 * Decompiled function: FUN_00410cc0
 * Entry Point: 00410cc0
 * Size: 561 bytes
 */
#include "magic.h"


int FUN_00410cc0(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = Pic_Subsystem_00451291(arg_1,arg_3);
  if (iVar2 != -1) {
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg_1 * 0x5b20) =
         CONCAT31((uint3)((arg_1 == 0) - 1 >> 8) & 0x10,2);
    (&DAT_006a5f4c)[iVar2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20];
    (&DAT_006a5f4d)[iVar2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006a5f4d)[arg_2 * 0x120 + arg_1 * 0x5b20];
    (&g_CardSlot_DamageReceived)[iVar2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
    *(int *)(&g_CardSlot_TypeFlags + iVar2 * 0x120 + arg_1 * 0x5b20) = arg_2;
    uVar1 = *(uint *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34);
    iVar3 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable +
                                 *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                 0x34),arg_1,arg_2);
    *(uint *)(&DAT_006a5f74 + iVar2 * 0x120 + arg_1 * 0x5b20) = uVar1 | iVar3 << 0x10;
    (&g_CardSlot_Toughness)[iVar2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_4;
    *(int *)(&g_CardSlot_OriginalCardId + iVar2 * 0x120 + arg_1 * 0x5b20) = arg_5;
    if ((arg_4 != -1) && (arg_5 != -1)) {
      *(uint *)(&g_CardSlot_Abilities2 + arg_4 * 0x5b20 + arg_5 * 0x120) =
           *(uint *)(&g_CardSlot_Abilities2 + arg_4 * 0x5b20 + arg_5 * 0x120) | 0xf000000;
    }
  }
  return iVar2;
}


