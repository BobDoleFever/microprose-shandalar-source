/*
 * Decompiled function: Card_Venom_AttachToCreature
 * Entry Point: 004e4fae
 * Size: 992 bytes
 */
#include "magic.h"


undefined4 Card_Venom_AttachToCreature(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int arg1;
  int iVar2;
  int local_18;
  int local_10;
  
  if (arg_3 == 0x3c) {
    (&DAT_006a604f)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006a604f)[arg_1 * 0x5b20 + arg_2 * 0x120] | 0x3f;
  }
  if (arg_3 == 0x1a) {
    arg1 = 1 - arg_1;
    if ((arg_1 == g_DefendingPlayer) &&
       (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x44) != 0)) {
      if ((&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120] == -1) {
        local_18 = arg_2;
      }
      else {
        local_18 = (int)(char)(&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120];
      }
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[arg1]; local_10 = local_10 + 1)
      {
        if ((((char)(&g_CardSlot_ColorMask)[arg1 * 0x5b20 + local_10 * 0x120] == local_18) &&
            ((&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_10 * 0x120) * 0x34]
             != '\0')) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] & 2) != 0)) {
          FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg1,local_10);
        }
      }
    }
    if ((arg_1 != g_DefendingPlayer) &&
       ((&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1)) {
      cVar1 = (&g_CardSlot_ColorMask)
              [arg1 * 0x5b20 + (char)(&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x120
              ];
      if (cVar1 == -1) {
        if (((&DAT_0051aebd)
             [*(int *)(&g_CardSlot_CardId +
                      arg1 * 0x5b20 +
                      (char)(&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x120) * 0x34]
             != '\0') &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId +
                      arg1 * 0x5b20 +
                      (char)(&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x120) * 0x34]
            & 2) != 0)) {
          FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg1,
                       (int)(char)(&g_CardSlot_ColorMask)[arg_1 * 0x5b20 + arg_2 * 0x120]);
        }
      }
      else {
        for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[arg1]; local_10 = local_10 + 1
            ) {
          iVar2 = FUN_00471c32(arg1,local_10);
          if (((iVar2 != 0) && ((&g_CardSlot_ColorMask)[arg1 * 0x5b20 + local_10 * 0x120] == cVar1))
             && (((&DAT_0051aebd)
                  [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] != '\0'
                 && (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] & 2)
                     != 0)))) {
            FUN_00410cc0(arg_1,arg_2,DAT_006a48e4,arg1,local_10);
          }
        }
      }
    }
  }
  return 0;
}


