/*
 * Decompiled function: Pic_Subsystem_0044da25
 * Entry Point: 0044da25
 * Size: 1876 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0044da25(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int arg2;
  int iVar4;
  int iVar5;
  uint uVar6;
  sbyte sVar7;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_34;
  int local_30;
  int local_2c;
  int local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  local_48 = 0;
  do {
    local_48 = local_48 + 1;
    if (4 < local_48) {
      return 0;
    }
    local_4c = 0;
    local_8 = 0;
    local_10 = 0;
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      *(undefined4 *)(&DAT_005224e8 + local_2c * 0x10) = 0;
    }
    uVar2 = clock();
    uVar6 = (int)uVar2 >> 0x1f;
    local_c = ((uVar2 ^ uVar6) - uVar6 & 0x7f ^ uVar6) - uVar6;
    memset(&DAT_0067bdf0,0xff,0x3200);
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      local_44 = 0;
      do {
        bVar1 = false;
        iVar3 = FUN_0040a1d2(0x40);
        arg2 = FUN_0040a1d2(0x40);
        iVar4 = FUN_0040c761(iVar3,arg2);
        if (iVar4 != 0) {
          local_40 = 0x7fff;
          local_18 = 0x7fff;
          for (local_34 = 0; (int)local_34 < 0x80; local_34 = local_34 + 1) {
            if (*(int *)(&DAT_0067bdf4 + local_34 * 100) != -1) {
              iVar5 = FUN_0040a36f(iVar3 - *(int *)(&DAT_0067bdf4 + local_34 * 100),
                                   arg2 - *(int *)(&DAT_0067bdf8 + local_34 * 100));
              if (iVar5 < local_40) {
                local_40 = iVar5;
              }
              if ((iVar5 < local_18) && (*(int *)(&DAT_0067bdf0 + local_34 * 100) == 3)) {
                local_18 = iVar5;
              }
            }
          }
          local_44 = local_44 + 1;
          if (7 - local_44 / 100 <= local_40) {
            bVar1 = true;
            *(int *)(&DAT_0067bdf4 + local_c * 100) = iVar3;
            *(int *)(&DAT_0067bdf8 + local_c * 100) = arg2;
            if (local_18 < 0x21) {
              if (local_40 < 0xb) {
                *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 1;
              }
              else {
                *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 2;
              }
            }
            else {
              *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 3;
            }
            *(undefined4 *)(&DAT_0067bdfc + local_c * 100) = 0;
            *(undefined4 *)(&DAT_0067be00 + local_c * 100) =
                 *(undefined4 *)(&DAT_0067bdfc + local_c * 100);
            for (local_34 = 0; (int)local_34 < 8; local_34 = local_34 + 1) {
              *(undefined4 *)(&DAT_0067be24 + local_34 * 4 + local_c * 100) = 0xfffffc18;
            }
            *(undefined4 *)(&DAT_0067be44 + local_c * 100) = 0xfffffc18;
            *(undefined4 *)(&DAT_0067be48 + local_c * 100) = 0xfffffc18;
            sVar7 = iVar4 == 3;
            if (iVar4 == 1) {
              sVar7 = 2;
            }
            if (iVar4 == 2) {
              sVar7 = 3;
            }
            if (iVar4 == 5) {
              sVar7 = 4;
            }
            if (iVar4 == 6) {
              sVar7 = 5;
            }
            if (((0x10 < local_18) && (sVar7 != 0)) && ((local_10 & 1 << sVar7) == 0)) {
              *(undefined4 *)(&DAT_0067bdf0 + local_c * 100) = 4;
              local_10 = local_10 | 1 << sVar7;
            }
            uVar2 = Adventure_GetLocationEncounterIndex(iVar4);
            if ((local_c != 0) &&
               ((*(int *)(&DAT_0067bdf0 + local_c * 100) == 3 ||
                (*(int *)(&DAT_0067bdf0 + local_c * 100) == 2)))) {
              for (local_34 = 0; (int)local_34 < 99; local_34 = local_34 + 1) {
                iVar4 = FUN_0040a1d2(10);
                iVar4 = iVar4 + 2;
                if ((*(int *)(&DAT_005224e8 + iVar4 * 0x10) == 0) &&
                   ((uVar2 & 1 << ((byte)(iVar4 / 2) & 0x1f)) != 0)) {
                  *(int *)(&DAT_005224e8 + iVar4 * 0x10) = local_c;
                  break;
                }
              }
              if (0x62 < (int)local_34) {
                iVar4 = FUN_0040a1d2(2);
                *(int *)(&DAT_005224e8 + iVar4 * 0x10) = local_c;
              }
              if (local_4c < 10) {
                *(uint *)(&DAT_0067be00 + local_c * 100) =
                     *(uint *)(&DAT_0067be00 + local_c * 100) | 1;
                local_4c = local_4c + 1;
              }
            }
            FUN_0040c81c(0x10,iVar3,arg2);
            uVar2 = local_c * 5 + 1;
            uVar6 = (int)uVar2 >> 0x1f;
            local_c = ((uVar2 ^ uVar6) - uVar6 & 0x7f ^ uVar6) - uVar6;
          }
        }
      } while (!bVar1);
      if (1 < *(int *)(&DAT_0067bdf0 + local_2c * 100)) {
        local_8 = local_8 + 1;
      }
    }
    bVar1 = true;
    if ((local_10 != 0x3e) || (local_8 < 0x1e)) {
      bVar1 = false;
    }
    for (local_30 = 0; local_30 < 6; local_30 = local_30 + 1) {
      do {
        do {
          iVar3 = FUN_0040a1d2(0x80);
        } while (*(int *)(&DAT_0067bdf0 + iVar3 * 100) < 2);
      } while ((*(int *)(&DAT_0067bdf0 + iVar3 * 100) == 4) ||
              (*(int *)(&DAT_0067bdfc + iVar3 * 100) != 0));
      *(int *)(&DAT_0067bdfc + iVar3 * 100) = 1 << ((byte)local_30 & 0x1f);
    }
    local_34 = FUN_0040a1d2(0xc);
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      if ((1 < *(int *)(&DAT_0067bdf0 + local_2c * 100)) &&
         (*(int *)(&DAT_0067bdf0 + local_2c * 100) < 4)) {
        if ((local_34 & 1) == 0) {
          *(int *)(&DAT_0067bdfc + local_2c * 100) = (((int)local_34 % 10) / 2 + 1) * 0x100;
        }
        else {
          *(int *)(&DAT_0067bdfc + local_2c * 100) = 1 << ((byte)(((int)local_34 % 0xc) / 2) & 0x1f)
          ;
        }
        local_34 = local_34 + 1;
      }
    }
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_005224e8 + local_2c * 0x10) == 0) {
        bVar1 = false;
      }
      if ((_DAT_0067f374 & 1 << ((byte)local_2c & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_005224e8 + local_2c * 0x10) = 0;
      }
    }
    if (bVar1) {
      return 1;
    }
    for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
      FUN_0040c889(0x10,*(int *)(&DAT_0067bdf4 + local_2c * 100),
                   *(int *)(&DAT_0067bdf8 + local_2c * 100));
    }
    for (local_2c = 0; local_2c < 0xc; local_2c = local_2c + 1) {
      *(undefined4 *)(&DAT_005224e8 + local_2c * 0x10) = 0;
    }
  } while( true );
}


