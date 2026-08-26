/*
 * Decompiled function: FUN_0041db67
 * Entry Point: 0041db67
 * Size: 972 bytes
 */
#include "magic.h"


int FUN_0041db67(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_8;
  
  if (((arg_1 == -1) || (arg_4 == -1)) || (arg_3 < 1)) {
    iVar1 = -1;
  }
  else {
    if (arg_2 == -1) {
      local_8 = arg_1;
    }
    else {
      local_8 = arg_4;
    }
    iVar1 = Pic_Subsystem_00451291(local_8,DAT_006ff2e0);
    if (iVar1 != -1) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) |
           CONCAT31((uint3)((local_8 == 0) - 1 >> 8) & 0x10,2);
      (&g_CardSlot_Toughness)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)arg_1;
      *(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + local_8 * 0x5b20) = arg_2;
      *(int *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + local_8 * 0x5b20) = arg_3;
      (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)arg_4;
      *(int *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + local_8 * 0x5b20) = arg_5;
      if (arg_5 == -1) {
        *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) = 0xef;
      }
      else {
        if ((*(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20) == -1) ||
           (*(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20) == DAT_006fd3f4)) {
          local_10 = *(int *)(&g_ActiveCardsInPlay + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        else {
          local_10 = *(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] =
             (&DAT_006a5f4d)[arg_5 * 0x120 + arg_4 * 0x5b20];
        if (((&g_MasterCardColorTable)[local_10 * 0x34] & 0x40) != 0) {
          (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] =
               (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] | 0x40;
        }
        *(uint *)(&g_CardSlot_TargetSlot + iVar1 * 0x120 + local_8 * 0x5b20) =
             (uint)(byte)(&g_MasterCardColorTable)[local_10 * 0x34];
        if ((*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == DAT_0068a694) ||
           (*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == DAT_006a2848)) {
          *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) =
               *(undefined4 *)(&DAT_006a5f74 + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        else {
          iVar2 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable + local_10 * 0x34),arg_4,arg_5);
          *(uint *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) =
               iVar2 << 0x10 | *(uint *)(&g_MasterCardTypeTable + local_10 * 0x34);
        }
      }
      g_PlayerHandCardCount = g_PlayerHandCardCount | 2;
    }
  }
  return iVar1;
}


