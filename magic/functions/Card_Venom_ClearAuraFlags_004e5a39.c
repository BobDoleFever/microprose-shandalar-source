/*
 * Decompiled function: Card_Venom_ClearAuraFlags
 * Entry Point: 004e5a39
 * Size: 1026 bytes
 */
#include "magic.h"


undefined4 Card_Venom_ClearAuraFlags(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int arg1;
  int iVar5;
  uint uVar6;
  int local_1c;
  int local_14;
  
  arg1 = 1 - arg_1;
  if (arg_3 == 0x3c) {
    bVar4 = (&DAT_006a604f)[arg_2 * 0x120 + arg_1 * 0x5b20];
    bVar2 = FUN_0041d9d2(arg_1,arg_2,3);
    bVar3 = FUN_0041d9d2(arg_1,arg_2,5);
    (&DAT_006a604f)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         bVar4 | (byte)(1 << (bVar2 & 0x1f)) | (byte)(1 << (bVar3 & 0x1f)) | 0x80;
  }
  if (arg_3 == 0x1a) {
    bVar4 = FUN_0041d9d2(arg_1,arg_2,3);
    bVar2 = FUN_0041d9d2(arg_1,arg_2,5);
    uVar6 = 1 << (bVar4 & 0x1f) | 1 << (bVar2 & 0x1f);
    if ((arg_1 == g_DefendingPlayer) &&
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0)) {
      if ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
        local_1c = arg_2;
      }
      else {
        local_1c = (int)(char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[arg1]; local_14 = local_14 + 1)
      {
        if ((((char)(&g_CardSlot_ColorMask)[local_14 * 0x120 + arg1 * 0x5b20] == local_1c) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0))
           && ((uVar6 & (int)(char)(&DAT_006a5f4d)[local_14 * 0x120 + arg1 * 0x5b20]) != 0)) {
          FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg1,local_14);
        }
      }
    }
    if ((arg_1 != g_DefendingPlayer) &&
       ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&g_CardSlot_ColorMask)
              [arg1 * 0x5b20 + (char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120
              ];
      if (cVar1 == -1) {
        if ((uVar6 & (int)(char)(&DAT_006a5f4d)
                                [arg1 * 0x5b20 +
                                 (char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                 0x120]) != 0) {
          FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg1,
                       (int)(char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        }
      }
      else {
        for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[arg1]; local_14 = local_14 + 1
            ) {
          iVar5 = FUN_00471c32(arg1,local_14);
          if (((iVar5 != 0) && ((&g_CardSlot_ColorMask)[local_14 * 0x120 + arg1 * 0x5b20] == cVar1))
             && ((uVar6 & (int)(char)(&DAT_006a5f4d)[local_14 * 0x120 + arg1 * 0x5b20]) != 0)) {
            FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg1,local_14);
          }
        }
      }
    }
  }
  return 0;
}


