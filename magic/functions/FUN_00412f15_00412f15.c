/*
 * Decompiled function: FUN_00412f15
 * Entry Point: 00412f15
 * Size: 1617 bytes
 */
#include "magic.h"


undefined4 FUN_00412f15(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  int local_14;
  uint local_c;
  int local_8;
  
  if ((((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid
        ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
              g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) &&
     (((arg_3 == 0x32 && (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) ||
      ((arg_3 == 0x33 && (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) != 0))))))
  {
    local_c = 0;
    uVar1 = *(uint *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xf00;
    if (uVar1 < 0x201) {
      if (uVar1 == 0x200) {
        for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
          if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == local_14)
              && (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) ||
             ((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != local_14 &&
              (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)))) {
            for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_14];
                local_8 = local_8 + 1) {
              if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20) != -1) &&
                  (((&g_CardSlot_Flags)[local_8 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
                 (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) ==
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20))) {
                local_c = local_c + 1;
              }
            }
          }
        }
      }
      else if (uVar1 == 0x100) {
        if (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0) {
          iVar2 = FUN_0041d963((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20)
                               ,*(int *)(&g_CardSlot_ConvertedManaCost +
                                        arg_2 * 0x120 + arg_1 * 0x5b20));
          local_c = *(uint *)(&DAT_0063ee30 +
                             iVar2 * 4 +
                             (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x20);
        }
        if (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
          iVar2 = FUN_0041d963((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20)
                               ,*(int *)(&g_CardSlot_ConvertedManaCost +
                                        arg_2 * 0x120 + arg_1 * 0x5b20));
          local_c = local_c + *(int *)(&DAT_0063ee30 +
                                      iVar2 * 4 +
                                      (1 - (char)(&g_CardSlot_Toughness)
                                                 [arg_2 * 0x120 + arg_1 * 0x5b20]) * 0x20);
        }
      }
    }
    else if (uVar1 == 0x400) {
      if (arg_3 == 0x32) {
        local_c = *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff;
      }
      else {
        local_c = (uint)(byte)(&DAT_006a5f55)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
    }
    else if (uVar1 == 0x800) {
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        if ((((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == local_14) &&
            (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) ||
           (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != local_14 &&
            (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)))) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_14];
              local_8 = local_8 + 1) {
            iVar2 = FUN_00471c32(local_14,local_8);
            if (((iVar2 != 0) &&
                (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20) * 0x34] & 2)
                 != 0)) &&
               ((&DAT_0051aebd)
                [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20) * 0x34] != '\0')
               ) {
              local_c = local_c + 1;
            }
          }
        }
      }
    }
    g_ActivePalette = g_ActivePalette + local_c;
    if (arg_3 == 0x32) {
      *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) = (short)local_c;
    }
    else {
      *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) = (short)local_c;
    }
  }
  return 0;
}


