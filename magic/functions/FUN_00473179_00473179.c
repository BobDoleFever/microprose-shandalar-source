/*
 * Decompiled function: FUN_00473179
 * Entry Point: 00473179
 * Size: 2823 bytes
 */
#include "magic.h"


uint FUN_00473179(int x,int y,int width,undefined4 arg_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  uint local_1c;
  int local_18;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar3 = DAT_0067bdb0;
  DAT_00677340 = DAT_00677340 + 1;
  if (DAT_0063ee18 != 0) {
    Magic_PayManaCost();
  }
  g_OverworldPlayerCoordX = x;
  g_OverworldMapGrid = y;
  DAT_006a4f70 = *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
  DAT_006b2fe4 = (int)(char)(&DAT_0051aebe)[DAT_006a4f70 * 0x34];
  DAT_006b2d5c = arg_4;
  switch(width) {
  case 0x32:
    if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_0051aec2 + DAT_006a4f70 * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_0051aec2 + DAT_006a4f70 * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006a5f48 + y * 0x120 + x * 0x5b20);
    if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 4) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfbffffff;
      goto LAB_004737a0;
    }
    g_ActivePalette = (uint)*(short *)(&g_CardSlot_Counters + y * 0x120 + x * 0x5b20);
    break;
  case 0x33:
    if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_0051aec4 + DAT_006a4f70 * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_0051aec4 + DAT_006a4f70 * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006a5f4a + y * 0x120 + x * 0x5b20);
    if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 2) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfdffffff;
      goto LAB_004737a0;
    }
    g_ActivePalette = (uint)*(short *)(&DAT_006a5f46 + y * 0x120 + x * 0x5b20);
    break;
  case 0x34:
    uVar1 = *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20);
    uVar2 = *(uint *)(&DAT_0051aecc + DAT_006a4f70 * 0x34);
    local_8 = uVar1 & 0x7000000 | uVar2;
    if ((uVar2 & 0x1ff81f) != 0) {
      local_1c = 0;
      for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
        if ((local_8 & 1 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = FUN_0041d963(x,y,local_18 + 1);
          local_1c = local_1c | 1 << (cVar4 - 1U & 0x1f);
        }
        if ((local_8 & 0x800 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = FUN_0041d9d2(x,y,local_18 + 1);
          local_1c = local_1c | 0x800 << (cVar4 - 1U & 0x1f);
        }
      }
      local_8 = uVar1 & 0x7000000 | uVar2 & 0xffe007e0 | local_1c;
    }
    if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 8) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xf7ffffff;
      goto LAB_004737a0;
    }
    g_ActivePalette = *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20);
    break;
  case 0x35:
    local_8 = (uint)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20);
    goto LAB_004737a0;
  case 0x36:
    local_8 = (uint)(char)(&DAT_0051aebe)[DAT_006a4f70 * 0x34];
    goto LAB_004737a0;
  default:
    local_8 = 0;
LAB_004737a0:
    g_ActivePalette = local_8;
    if ((DAT_0063ee18 != 0) && (Magic_ScanCards(width), (g_PlayerHandCardCount & 0x10000) != 0)) {
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffeffff;
      *(uint *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = g_ActivePalette;
      g_PlayerHandCardCount = g_PlayerHandCardCount | 0x20000;
      Magic_ScanCards(width);
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffdffff;
    }
    if (width == 0x32) {
      if ((int)g_ActivePalette < 0) {
        g_ActivePalette = 0;
      }
      if (((&DAT_006a5f69)[y * 0x120 + x * 0x5b20] & 0x40) != 0) {
        g_ActivePalette = g_ActivePalette << 1;
      }
    }
    break;
  case 0x3c:
    if (((*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) < DAT_006ff2e0) ||
        (DAT_006ff2e0 + 0x1d <= *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20))) &&
       (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) != -1)) {
      local_8 = *(uint *)(&g_ActiveCardsInPlay + y * 0x120 + x * 0x5b20);
      if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 1) != 0) {
        *(undefined4 *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&g_ActiveCardsInPlay + y * 0x120 + x * 0x5b20);
        *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfeffffff;
        (&DAT_006a604f)[y * 0x120 + x * 0x5b20] = 0;
        goto LAB_004737a0;
      }
      g_ActivePalette = *(uint *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    }
    else {
      g_ActivePalette = *(uint *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    }
  }
  uVar1 = g_ActivePalette;
  iVar5 = FUN_00471c32(x,y);
  if (((iVar5 != 0) && (width == 0x33)) &&
     ((((&g_MasterCardColorTable)[DAT_006a4f70 * 0x34] & 2) != 0 &&
      (((((int)uVar1 < 1 ||
         ((int)uVar1 <= (int)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20))) &&
        (g_PlayerManaPool == -1)) && ((g_PlayerHandCardCount & 0x204) == 0)))))) {
    Pic_Subsystem_0044867e(x,y,2);
    Pic_Subsystem_004488a0();
  }
  if (DAT_0063ee18 != 0) {
    Magic_TapCardForMana();
  }
  if (width == 0x32) {
    *(short *)(&g_CardSlot_Counters + y * 0x120 + x * 0x5b20) = (short)uVar1;
  }
  if (width == 0x33) {
    *(short *)(&DAT_006a5f46 + y * 0x120 + x * 0x5b20) = (short)uVar1;
  }
  if (width == 0x34) {
    *(uint *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) = uVar1;
  }
  if (width != 0x3c) {
    DAT_0067bdb0 = uVar3;
    return uVar1;
  }
  *(uint *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = uVar1;
  if (((&DAT_0051aed1)[uVar1 * 0x34] & 0x10) == 0) goto LAB_00473adb;
  iVar5 = *(int *)(&g_MasterCardTypeTable + uVar1 * 0x34);
  if (iVar5 < 0x12d) {
    if (iVar5 == 300) {
      (&DAT_006a5f4c)[y * 0x120 + x * 0x5b20] = 1;
      goto LAB_00473adb;
    }
    if (iVar5 == 0xf) {
      (&DAT_006a5f4c)[y * 0x120 + x * 0x5b20] = 0x3e;
      goto LAB_00473adb;
    }
  }
  else if ((iVar5 == 0x13e) || (iVar5 == 0x366)) goto LAB_00473adb;
  (&DAT_006a5f4c)[y * 0x120 + x * 0x5b20] = (&DAT_0051aebe)[uVar1 * 0x34];
LAB_00473adb:
  if ((((&g_CardSlot_Abilities1)[y * 0x120 + x * 0x5b20] & 0x40) != 0) &&
     (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 2)
      == 0)) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_c];
          local_10 = local_10 + 1) {
        if ((((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) != -1) &&
             (((&g_CardSlot_Flags)[local_10 * 0x120 + local_c * 0x5b20] & 2) != 0)) &&
            ((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + local_c * 0x5b20] == x)) &&
           (((*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + local_c * 0x5b20) == y &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) * 0x34] & 4) != 0
             )) && (*(int *)(&DAT_006b3088 +
                            *(int *)(&g_MasterCardTypeTable +
                                    *(int *)(&g_CardSlot_CardId +
                                            local_10 * 0x120 + local_c * 0x5b20) * 0x34) * 0x98) ==
                    0x2d)))) {
          Pic_Subsystem_0044867e(local_c,local_10,3);
        }
      }
    }
  }
  DAT_0067bdb0 = uVar3;
  return uVar1;
}


