/*
 * Decompiled function: Adventure_UpdateWorldMapLoop
 * Entry Point: 004e93df
 * Size: 4945 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Adventure_UpdateWorldMapLoop(void)

{
  int iVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  uint local_10;
  int local_c;
  
  local_54 = 0x7fff;
  for (local_40 = 0; (int)local_40 < 6; local_40 = local_40 + 1) {
    iVar4 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_40 * 0x14),
                         DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_40 * 0x14));
    if ((iVar4 < local_54) && (*(int *)(&DAT_0067f2d0 + local_40 * 0x14) != 0)) {
      local_10 = local_40;
      local_54 = iVar4;
    }
  }
  if (DAT_0067f35c == -1) {
    DAT_006410b0 = 0;
  }
  for (local_40 = 0; (int)local_40 < 8; local_40 = local_40 + 1) {
    iVar4 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_40 * 0x14),
                         DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_40 * 0x14));
    iVar5 = abs(DAT_00641010 -
                ((int)(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) +
                      (*(int *)(&DAT_0067f2d4 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5));
    iVar6 = abs(DAT_00641014 -
                ((int)(*(int *)(&DAT_0067f2d8 + local_40 * 0x14) +
                      (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5));
    if (((int)local_40 < 6) &&
       (((*(int *)(&DAT_0067f2d0 + local_40 * 0x14) == -1 || (4 < iVar5)) || (4 < iVar6)))) {
      do {
        iVar5 = FUN_0040a1d2(2);
        if (iVar5 == 0) {
          iVar5 = FUN_0040a1d2(2);
          local_3c = (-(uint)(iVar5 == 0) & 0xfffffff8) + 4 + DAT_00641014;
          iVar5 = FUN_0040a1d2(9);
          local_28 = DAT_00641010 + iVar5 + -4;
        }
        else {
          iVar5 = FUN_0040a1d2(2);
          local_28 = (-(uint)(iVar5 == 0) & 0xfffffff8) + 4 + DAT_00641010;
          iVar5 = FUN_0040a1d2(9);
          local_3c = DAT_00641014 + iVar5 + -4;
        }
        uVar7 = FUN_0040c761(local_28,local_3c);
        uVar8 = Adventure_GetLocationEncounterIndex(uVar7);
      } while (uVar8 == 0);
      do {
        iVar5 = FUN_0040a1d2(6);
        local_44._0_1_ = (byte)iVar5;
        bVar3 = (byte)local_44;
      } while ((uVar8 & 1 << ((byte)local_44 & 0x1f)) == 0);
      local_44 = (int)(DAT_0067f384 + (DAT_0067f384 >> 0x1f & 7U)) >> 3;
      for (local_48 = 0; (int)local_48 < 1000; local_48 = local_48 + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == iVar5) {
          local_44 = local_44 + 1;
        }
      }
      iVar6 = FUN_0040a305((int)(0x80 / (longlong)(local_44 + 4)),6,0x14);
      iVar6 = FUN_0040a1d2(iVar6);
      switch(iVar6 + (int)(5 / (longlong)(local_44 + 1))) {
      case 0:
        local_24 = 10;
        break;
      case 1:
        local_24 = 10;
        break;
      case 2:
        local_24 = 10;
        break;
      case 3:
        local_24 = 0;
        break;
      case 4:
        local_24 = 10;
        break;
      case 5:
        local_24 = 8;
        break;
      case 6:
        local_24 = 6;
        break;
      case 7:
        local_24 = 4;
        break;
      case 8:
        local_24 = 6;
        break;
      case 9:
        local_24 = 0;
        break;
      case 10:
        local_24 = 4;
        break;
      case 0xb:
        local_24 = 6;
        break;
      case 0xc:
        local_24 = 0;
        break;
      case 0xd:
        local_24 = 4;
        break;
      case 0xe:
        local_24 = 0;
        break;
      case 0xf:
        local_24 = 4;
        break;
      default:
        local_24 = 0;
      }
      if (local_24 == 10) {
        local_24 = FUN_0040a1d2(200);
        if (local_24 < 0x32) {
          local_24 = 10;
        }
        else if (local_24 < 0x55) {
          local_24 = 0xb;
        }
        else if (local_24 < 0x73) {
          local_24 = 0xc;
        }
        else if (local_24 < 0x8e) {
          local_24 = 0xd;
        }
        else if (local_24 < 0xa5) {
          local_24 = 0xe;
        }
        else if (local_24 < 0xb9) {
          local_24 = 0x10;
        }
        else if (local_24 < 200) {
          local_24 = 0x12;
        }
      }
      if (((local_40 == 0) && (DAT_0067f2c0 < 0)) && (-100 < DAT_0067f2c0)) {
        local_24 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44];
      }
      if (local_24 == 0) {
        *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0;
      }
      else {
        local_24 = Adventure_CheckMonsterEncounter(iVar5,local_24);
        *(int *)(&DAT_0067f2d0 + local_40 * 0x14) = local_24;
        local_2c = 0;
        for (local_48 = 0; ((int)local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
            local_48 = local_48 + 1) {
          if ((((&DAT_0067b9b0)[local_48] & 0xf) == (&DAT_0052262a)[local_24 * 0x44]) &&
             ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == iVar5)) {
            local_2c = local_2c + 1;
          }
        }
        if (8 < local_2c) {
          local_24 = -1;
          *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
        }
      }
      *(int *)(&DAT_0067f2d4 + local_40 * 0x14) = local_28 * 0x20 + 0x10;
      *(int *)(&DAT_0067f2d8 + local_40 * 0x14) = local_3c * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + local_40 * 0x14) = iVar5;
      (&DAT_0067f2e0)[local_40 * 0x14] = 0;
      (&DAT_0067f2e1)[local_40 * 0x14] = 0;
      if (((1 << (bVar3 & 0x1f) & (int)(char)(&DAT_0052262b)[local_24 * 0x44]) != 0) &&
         ((DAT_0067bdb4 & 1 << (bVar3 & 0x1f)) != 0)) {
        uVar8 = (int)(char)(&DAT_0052262b)[local_24 * 0x44] & ~(1 << (bVar3 & 0x1f));
        if ((uVar8 == 0) || ((uVar8 & DAT_0067bdb4) != 0)) {
          FUN_0046e70d(local_40,local_40 + 8);
          *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
        }
        else if (uVar8 != 0) {
          uVar7 = FUN_00473cc5((byte)uVar8);
          *(undefined4 *)(&DAT_0067f2dc + local_40 * 0x14) = uVar7;
        }
      }
      uVar8 = FUN_0040c7c0(local_28,local_3c);
      if ((uVar8 & 0x10) != 0) {
        FUN_0046e70d(local_40,local_40 + 8);
        *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
      }
      if (((local_40 == 0) && (DAT_0067f2c0 < 0)) && (_DAT_0067f2d0 != -DAT_0067f2c0)) {
        FUN_0046e70d(0,8);
        _DAT_0067f2d0 = -1;
      }
      if (*(int *)(&DAT_0067f2d0 + local_40 * 0x14) < 1) {
        if (*(int *)(&DAT_0067f2d0 + local_40 * 0x14) != -1) {
          for (local_6c = 0; (int)local_6c < 8; local_6c = local_6c + 1) {
            if (((*(int *)(&DAT_0067f2d0 + local_6c * 0x14) != -1) && (local_40 != local_6c)) &&
               ((*(int *)(&DAT_0067f2d4 + local_6c * 0x14) ==
                 *(int *)(&DAT_0067f2d4 + local_40 * 0x14) &&
                (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) ==
                 *(int *)(&DAT_0067f2d8 + local_6c * 0x14))))) {
              *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
            }
          }
        }
      }
      else {
        FUN_0046e70d(local_40,local_40 + 8);
      }
    }
    iVar5 = *(int *)(&DAT_0067f2d0 + local_40 * 0x14);
    if (iVar5 != -1) {
      if (0 < iVar5) {
        Sprite_Load_BK_AMG_0046d333(iVar5,local_40,local_40 + 8);
      }
      local_20 = 1;
      switch((&DAT_0052262a)[iVar5 * 0x44]) {
      case 0:
        local_34 = -1;
        local_20 = 0;
        break;
      case 1:
        local_c = 1;
        local_34 = 0x20;
        local_20 = 1;
        break;
      case 2:
        local_c = 1;
        local_34 = 0x20;
        local_20 = 1;
        break;
      case 3:
        local_c = 1;
        local_34 = 0x30;
        local_20 = 1;
        break;
      case 4:
        local_c = 1;
        local_34 = 0x30;
        local_20 = 1;
        break;
      case 5:
        local_c = 1;
        local_34 = 0x40;
        local_20 = 1;
        break;
      case 6:
        local_c = 1;
        local_34 = 0x60;
        local_20 = 1;
        break;
      case 7:
        local_c = 1;
        local_34 = 0x60;
        local_20 = 1;
        break;
      case 8:
        local_c = 1;
        local_34 = 0x40;
        local_20 = 1;
        break;
      case 9:
        local_c = 1;
        local_34 = 0x20;
        local_20 = 2;
        break;
      case 10:
        local_c = 1;
        local_34 = 0x30;
        local_20 = 1;
      }
      local_34 = (local_34 * 3) / 2;
      if (((&DAT_00522631)[iVar5 * 0x44] & 2) != 0) {
        local_34 = local_34 << 1;
      }
      local_14 = iVar4;
      if (local_40 != local_10) {
        local_34 = local_34 / 2;
      }
      for (; iVar6 = abs(local_34), iVar6 < local_14; local_14 = local_14 / 2) {
        local_c = local_c << 1;
      }
      iVar6 = *(int *)(&DAT_0067f2d4 + local_40 * 0x14);
      iVar1 = *(int *)(&DAT_0067f2d8 + local_40 * 0x14);
      if (DAT_006410dc == 0) {
        local_60 = DAT_0052eff0 - iVar6;
        local_64 = DAT_0052eff4 - iVar1;
      }
      else {
        iVar9 = FUN_0040a305(iVar4 / 3,0,DAT_0067f380 << 4);
        local_60 = (iVar9 * *(int *)(&DAT_00522378 + DAT_006410d4 * 4) + DAT_0052eff0) - iVar6;
        iVar9 = FUN_0040a305(iVar4 / 3,0,DAT_0067f380 << 4);
        local_64 = (iVar9 * *(int *)(&DAT_005223e0 + DAT_006410d4 * 4) + DAT_0052eff4) - iVar1;
      }
      if (((&DAT_00522630)[iVar5 * 0x44] & 1) != 0) {
        local_20 = 2;
      }
      if ((iVar4 < 0x40) && ((int)local_40 < 7)) {
        local_2c = 0;
        for (local_48 = 0; ((int)local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
            local_48 = local_48 + 1) {
          if ((((&DAT_0067b9b0)[local_48] & 0xf) == (&DAT_0052262a)[iVar5 * 0x44]) &&
             ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == *(int *)(&DAT_0067f2dc + local_40 * 0x14)
             )) {
            local_2c = local_2c + 1;
          }
        }
        if (DAT_0067f380 + 3 <= local_2c) {
          local_60 = -local_60;
          local_64 = -local_64;
        }
      }
      if ((local_40 == 7) && (0x18 < iVar4)) {
        iVar9 = Duel_GetCardDrawOriginY
                          ((int)(DAT_0067f360 + (DAT_0067f360 >> 0x1f & 0x1fU)) >> 5,
                           (int)(DAT_0067f364 + (DAT_0067f364 >> 0x1f & 0x1fU)) >> 5);
        local_60 = (*(int *)(&DAT_0067bdf4 + iVar9 * 100) * 0x20 - iVar6) + (DAT_0067f37c & 0x1f);
        local_64 = (*(int *)(&DAT_0067bdf8 + iVar9 * 100) * 0x20 - iVar1) +
                   ((DAT_0067f37c & 0x3e) >> 1);
      }
      uVar7 = FUN_0040c761((int)(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) +
                                (*(int *)(&DAT_0067f2d4 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                           (int)(*(int *)(&DAT_0067f2d8 + local_40 * 0x14) +
                                (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5);
      iVar9 = Adventure_GetLocationEncounterIndex(uVar7);
      if (((((&DAT_00522630)[iVar5 * 0x44] & 0xf8) != 0) &&
          ((*(uint *)(&DAT_00522630 + iVar5 * 0x44) & iVar9 << 3) != 0)) && (1 < local_c)) {
        local_c = local_c / 2;
      }
      local_5c = 0;
      local_60 = local_60 + *(int *)(&DAT_00522378 + (char)(&DAT_0067f2e0)[local_40 * 0x14] * 4) * 8
      ;
      local_64 = local_64 + *(int *)(&DAT_005223e0 + (char)(&DAT_0067f2e0)[local_40 * 0x14] * 4) * 8
      ;
      iVar9 = abs(local_64);
      iVar10 = abs(local_60);
      if (iVar9 * 2 < iVar10) {
        if (local_60 < 1) {
          local_5c = 7;
        }
        else {
          local_5c = 3;
        }
      }
      iVar9 = abs(local_60);
      iVar10 = abs(local_64);
      if (iVar9 * 2 < iVar10) {
        if (local_64 < 1) {
          local_5c = 1;
        }
        else {
          local_5c = 5;
        }
      }
      if (local_5c == 0) {
        if (local_60 < 1) {
          if (local_64 < 1) {
            local_5c = 8;
          }
          else {
            local_5c = 6;
          }
        }
        else if (local_64 < 1) {
          local_5c = 2;
        }
        else {
          local_5c = 4;
        }
      }
      if ((local_40 + DAT_0067f37c & 3) == 0) {
        (&DAT_0067f2e0)[local_40 * 0x14] = (undefined1)local_5c;
      }
      else {
        local_5c = (int)(char)(&DAT_0067f2e0)[local_40 * 0x14];
      }
      *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
           *(int *)(&DAT_0067f2d4 + local_40 * 0x14) + *(int *)(&DAT_00522378 + local_5c * 4) * 4;
      *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
           *(int *)(&DAT_0067f2d8 + local_40 * 0x14) + *(int *)(&DAT_005223e0 + local_5c * 4) * 4;
      bVar2 = true;
      for (local_48 = 0; (int)local_48 < 6; local_48 = local_48 + 1) {
        if (((*(int *)(&DAT_0067f2d0 + local_48 * 0x14) != 0) && (local_40 != local_48)) &&
           ((0x1f < iVar4 &&
            ((iVar9 = FUN_0040a36f(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) -
                                   *(int *)(&DAT_0067f2d4 + local_48 * 0x14),
                                   *(int *)(&DAT_0067f2d8 + local_40 * 0x14) -
                                   *(int *)(&DAT_0067f2d8 + local_48 * 0x14)), iVar9 < 0x20 &&
             (iVar10 = FUN_0040a36f(iVar6 - *(int *)(&DAT_0067f2d4 + local_48 * 0x14),
                                    iVar1 - *(int *)(&DAT_0067f2d8 + local_48 * 0x14)),
             iVar9 < iVar10)))))) {
          bVar2 = false;
        }
      }
      if (bVar2) {
        if ((((&DAT_00522630)[iVar5 * 0x44] & 4) != 0) && ((DAT_0067f37c & 0x3f) == 0)) {
          iVar9 = FUN_0040a1d2(2);
          if (iVar9 == 0) {
            iVar9 = FUN_0040a1d2(2);
            if (iVar9 == 0) {
              *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d8 + local_40 * 0x14) + -0x20;
            }
            else {
              *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d8 + local_40 * 0x14) + 0x20;
            }
          }
          else {
            iVar9 = FUN_0040a1d2(2);
            if (iVar9 == 0) {
              *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d4 + local_40 * 0x14) + -0x20;
            }
            else {
              *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
                   *(int *)(&DAT_0067f2d4 + local_40 * 0x14) + 0x20;
            }
          }
        }
        uVar7 = FUN_0040c761((int)(*(int *)(&DAT_0067f2d4 + local_40 * 0x14) +
                                  (*(int *)(&DAT_0067f2d4 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                             (int)(*(int *)(&DAT_0067f2d8 + local_40 * 0x14) +
                                  (*(int *)(&DAT_0067f2d8 + local_40 * 0x14) >> 0x1f & 0x1fU)) >> 5)
        ;
        uVar8 = Adventure_GetLocationEncounterIndex(uVar7);
        if ((((uVar8 & (int)(char)(&DAT_0052262b)[iVar5 * 0x44]) == 0) && (-1 < local_34)) &&
           (local_40 != 7)) {
          *(int *)(&DAT_0067f2d4 + local_40 * 0x14) = iVar6;
          *(int *)(&DAT_0067f2d8 + local_40 * 0x14) = iVar1;
          uVar7 = FUN_0040c761((int)(iVar6 + (iVar6 >> 0x1f & 0x1fU)) >> 5,
                               (int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5);
          uVar8 = Adventure_GetLocationEncounterIndex(uVar7);
          (&DAT_0067f2e1)[local_40 * 0x14] = 0;
          if ((uVar8 & (int)(char)(&DAT_0052262b)[iVar5 * 0x44]) == 0) {
            FUN_0046e70d(local_40,local_40 + 8);
            *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
          }
        }
        else {
          *(int *)(&DAT_0067f2d4 + local_40 * 0x14) =
               *(int *)(&DAT_00522378 + local_5c * 4) * local_20 + iVar6;
          *(int *)(&DAT_0067f2d8 + local_40 * 0x14) =
               *(int *)(&DAT_005223e0 + local_5c * 4) * local_20 + iVar1;
          (&DAT_0067f2e0)[local_40 * 0x14] = (undefined1)local_5c;
          (&DAT_0067f2e1)[local_40 * 0x14] = (&DAT_0067f2e1)[local_40 * 0x14] + '\x01';
          if ('\x04' < (char)(&DAT_0067f2e1)[local_40 * 0x14]) {
            (&DAT_0067f2e1)[local_40 * 0x14] = 1;
          }
        }
        iVar6 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_40 * 0x14),
                             DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_40 * 0x14));
        if (iVar6 < (int)((-(uint)(*(int *)(&DAT_0067f2d0 + local_40 * 0x14) == 0) & 10) + 0x10)) {
          FUN_0048c970(3);
          iVar4 = Dungeon_Process_004856b0(local_40,*(int *)(&DAT_0067f2dc + local_40 * 0x14));
          Ai_Subsystem_004c05ba();
          if ((local_40 == 7) && (iVar4 < 1)) {
            Adventure_NewsFlash_DominionSpell();
          }
          else if (local_40 == 7) {
            FUN_0040b3c2(0xd,DAT_0067f368);
            DAT_006410b0 = 0;
          }
          FUN_0046e70d(local_40,local_40 + 8);
          *(undefined4 *)(&DAT_0067f2d0 + local_40 * 0x14) = 0xffffffff;
          Adventure_LoadFacePalette(0);
          DAT_0067f37c = DAT_0067f37c | 0x1f;
          FUN_0048c970(3);
        }
        else if (((iVar5 != 0) && ((&DAT_0067f2e1)[local_40 * 0x14] != '\0')) &&
                ((iVar4 < 0x50 && (iVar6 = FUN_0040a1d2(iVar4), iVar6 < 4)))) {
          Adventure_PlayMonsterEncounterSound
                    (iVar5,0x68 - iVar4 / 2,100 - iVar4 / 3,
                     *(int *)(&DAT_00522378 +
                             ((int)(char)(&DAT_0067f2e0)[local_40 * 0x14] + 2U & 7) * 4) * 100);
        }
      }
      else {
        *(int *)(&DAT_0067f2d4 + local_40 * 0x14) = iVar6;
        *(int *)(&DAT_0067f2d8 + local_40 * 0x14) = iVar1;
        (&DAT_0067f2e1)[local_40 * 0x14] = 0;
      }
    }
  }
  return;
}


