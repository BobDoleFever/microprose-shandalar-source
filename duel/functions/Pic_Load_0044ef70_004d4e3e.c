/*
 * Decompiled function: Pic_Load_0044ef70
 * Entry Point: 004d4e3e
 * Size: 5412 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x004d535c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Load_0044ef70(undefined4 arg1,int arg2)

{
  int iVar1;
  uint arg_1;
  undefined4 uVar2;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c [6];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (((byte)DAT_00663dfc & 1) == 0) {
    arg2 = -1;
  }
  FUN_004398be();
  DAT_0068eed8 = 1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
      *(undefined4 *)(&DAT_006826c0 + local_1c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
      *(undefined4 *)(&DAT_006826c4 + local_1c * 0x120 + local_8 * 0x5b20) =
           *(undefined4 *)(&DAT_006826c0 + local_1c * 0x120 + local_8 * 0x5b20);
    }
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      *(undefined4 *)(&DAT_0068dd10 + local_1c * 4 + local_8 * 2000) = 0xffffffff;
      *(undefined4 *)(&DAT_0068f370 + local_1c * 4 + local_8 * 2000) =
           *(undefined4 *)(&DAT_0068dd10 + local_1c * 4 + local_8 * 2000);
    }
    *(undefined4 *)(&DAT_0068f228 + local_8 * 4) = 0;
    (&DAT_00666408)[local_8] = 0;
  }
  DAT_0068f0e0 = 0xef;
  DAT_0068f0e4 = 0x7e;
  DAT_0068f0e8 = 0x5b;
  DAT_0068f0ec = 0xa4;
  DAT_0068f0f0 = 0xbc;
  FUN_00487a10();
  FUN_0048eae1();
  if (arg2 == -1) {
    DAT_00681eac = 0x14;
    DAT_00681ea8 = 0x14;
    FUN_00448412(&DAT_00666500);
    local_2c = 7;
    DAT_006668f8 = 0;
    DAT_006669e8 = 1;
    DAT_0068ed00 = -1;
    FUN_0049a9d0();
    if (((DAT_005f2f50 == 0) || (iVar1 = FUN_00439892(2), iVar1 == 0)) || (DAT_0066aaf4 != 0)) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
    local_28 = 1;
    DAT_0066aaf0 = 1;
    if (DAT_00601578 == 0) {
      for (local_54 = 0; local_54 < 0x3c; local_54 = local_54 + 1) {
        *(undefined4 *)(&DAT_006671c0 + local_54 * 4) = 0;
        *(undefined4 *)(&DAT_006669f0 + local_54 * 4) =
             *(undefined4 *)(&DAT_006671c0 + local_54 * 4);
      }
      for (local_54 = 0x3c; local_54 < 500; local_54 = local_54 + 1) {
        *(undefined4 *)(&DAT_006671c0 + local_54 * 4) = 0xffffffff;
        *(undefined4 *)(&DAT_006669f0 + local_54 * 4) =
             *(undefined4 *)(&DAT_006671c0 + local_54 * 4);
      }
      FUN_00451482(0,0x30);
      for (local_54 = 0; local_54 < 0x10; local_54 = local_54 + 1) {
        (&DAT_0068ed90)[local_54] = 0xffffffff;
        (&DAT_0068ed50)[local_54] = (&DAT_0068ed90)[local_54];
      }
      if (DAT_00664778 != 0) {
        DAT_0068ed50 = FUN_004396ea(DAT_00505988);
        DAT_0068ed90 = FUN_004396ea(DAT_00505984);
      }
      for (local_54 = 0; local_54 < 7; local_54 = local_54 + 1) {
        iVar1 = FUN_004396ea(DAT_00505988);
        Pic_Subsystem_00451291(0,iVar1);
        iVar1 = FUN_004396ea(DAT_00505984);
        Pic_Subsystem_00451291(1,iVar1);
      }
      FUN_004d6362(&local_18,&local_34,&local_20);
      for (local_50 = 0; local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = DAT_00505988;
        }
        else {
          local_60 = DAT_00505984;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_004f71c0 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < (int)(&DAT_004f71c4)[local_60 * 0xa0 + local_54 * 2];
                local_58 = local_58 + 1) {
              *(undefined4 *)(&DAT_006669f0 + local_5c * 4 + local_50 * 2000) = 0;
              local_5c = local_5c + 1;
            }
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(undefined4 *)(&DAT_006669f0 + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      Ai_AssignCombatDamage
                (&local_10,(uint *)(local_4c + 5),local_10,local_28,DAT_0068ed90,DAT_0068ed50,
                 local_18,local_34,local_20);
      if (local_4c[5] != 0) {
        FUN_004d6490(0,DAT_00505988);
        FUN_00451482(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (local_20 != 0)))) {
        FUN_004d6490(1,DAT_00505984);
        FUN_00451482(0,0x30);
      }
      for (local_50 = 0; iVar1 = DAT_0066aaf4, local_50 < 2; local_50 = local_50 + 1) {
        if (local_50 == 0) {
          local_60 = DAT_00505988;
        }
        else {
          local_60 = DAT_00505984;
        }
        local_5c = 0;
        for (local_54 = 0; local_54 < 0x50; local_54 = local_54 + 1) {
          if (*(int *)(&DAT_004f71c0 + local_54 * 8 + local_60 * 0x280) != -1) {
            for (local_58 = 0; local_58 < (int)(&DAT_004f71c4)[local_60 * 0xa0 + local_54 * 2];
                local_58 = local_58 + 1) {
              uVar2 = CardTypeFromID(*(int *)(&DAT_004f71c0 + local_54 * 8 + local_60 * 0x280));
              *(undefined4 *)(&DAT_006669f0 + local_5c * 4 + local_50 * 2000) = uVar2;
              local_5c = local_5c + 1;
            }
            (&DAT_004f71c4)[local_60 * 0xa0 + local_54 * 2] = 0;
          }
        }
        for (local_54 = local_5c; local_54 < 500; local_54 = local_54 + 1) {
          *(undefined4 *)(&DAT_006669f0 + local_54 * 4 + local_50 * 2000) = 0xffffffff;
        }
      }
      DAT_00505988 = -1;
      DAT_0066aaf4 = 1;
      FUN_004d7946(0);
      FUN_004d7946(1);
      DAT_0066aaf4 = iVar1;
    }
  }
  else {
    local_4c[4] = 0;
    local_4c[0] = 0x1e;
    local_4c[1] = 0x23;
    local_4c[2] = 0x28;
    local_4c[3] = 0x28;
    DAT_00681ea8 = 10;
    if ((_DAT_005f2f44 & 2) != 0) {
      DAT_00681ea8 = 0xc;
    }
    if ((_DAT_005f2f44 & 0x800) != 0) {
      DAT_00681ea8 = DAT_00681ea8 + 3;
    }
    if ((_DAT_005f2f44 & 0x80) != 0) {
      DAT_00681ea8 = DAT_00681ea8 + 5;
    }
    iVar1 = FUN_004d7ecb();
    DAT_00681ea8 = iVar1 + DAT_006669e4;
    DAT_00681ea8 = DAT_00681ea8 + DAT_005f6284;
    if ((0 < DAT_005071c4) && (DAT_005071c4 < 6)) {
      DAT_00681ea8 = DAT_00681ea8 + DAT_005071c4;
    }
    _DAT_006664e0 = DAT_00681ea8;
    DAT_006669e4 = 0;
    DAT_00681eac = (int)*(char *)(arg2 * 0x44 + 0x507398);
    if ((arg2 < 0x25) && (arg2 % 7 != 0)) {
      DAT_00681eac = DAT_00681eac + DAT_005f2f50 * 2;
    }
    else if ((arg2 < 0x25) && (arg2 % 7 == 0)) {
      DAT_00681eac = DAT_00681eac + DAT_005f2f50 * 5;
    }
    else if (arg2 < 0x37) {
      DAT_00681eac = DAT_00681eac + DAT_005f2f50 * 2;
    }
    else if (0x36 < arg2) {
      DAT_00681eac = DAT_00681eac + DAT_005f2f50 * 0x32;
    }
    if (*(char *)(arg2 * 0x44 + 0x50739a) == '\v') {
      for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
        if ((_DAT_005f2f44 & 1 << ((byte)local_1c & 0x1f)) != 0) {
          DAT_00681eac = DAT_00681eac + 1;
        }
      }
    }
    iVar1 = DAT_00681eac;
    if (*(char *)(arg2 * 0x44 + 0x50739a) == '\f') {
      DAT_00681eac = DAT_00681eac + 10;
      local_30 = 0;
      local_c = 0;
      for (local_1c = 0; (local_1c < 1000 && ((&DAT_005ef580)[local_1c] != '\0'));
          local_1c = local_1c + 1) {
        if ((int)(char)(&DAT_005ef580)[local_1c] >> 4 == DAT_0068ed00) {
          local_30 = local_30 + 1;
        }
      }
      DAT_00681eac = DAT_00681eac - local_30;
      for (local_24 = 0; local_24 < 0x80; local_24 = local_24 + 1) {
        if (((&DAT_005ef9d1)[local_24 * 100] != '\0') &&
           ((*(int *)(&DAT_005ef9d0 + local_24 * 100) >> 8) + -1 == local_1c)) {
          local_c = local_c + 1;
        }
      }
      DAT_00681eac = DAT_00681eac + DAT_005f2f50 * local_c;
      iVar1 = DAT_005f2f50 * 5 + 0x14;
      if (iVar1 <= DAT_00681eac) {
        iVar1 = DAT_00681eac;
      }
    }
    DAT_00681eac = iVar1;
    if (*(char *)(arg2 * 0x44 + 0x50739a) == '\r') {
      DAT_00681eac = DAT_005f2f50 * 100 + 100;
    }
    DAT_005f6810 = 0;
    FUN_0049f633(arg2);
    Mem_AllocOrFree_004d9630((uint *)&DAT_00666500,(uint *)&DAT_005f6810);
    FUN_0049aa14(DAT_005f2f50 + DAT_006664e4 + 4,0,99);
    local_2c = 7;
    DAT_006668f8 = 0;
    FUN_0049a9d0();
    if (((DAT_005f2f50 == 0) || (iVar1 = FUN_00439892(2), iVar1 == 0)) || (DAT_0066aaf4 != 0)) {
      local_10 = 0;
    }
    else {
      local_10 = 1;
    }
    local_28 = 1;
    DAT_0066aaf0 = 1;
    if ((DAT_005ee564 != 0) || (DAT_005071c4 == 0)) {
      if (DAT_005ee564 == 0) {
        local_10 = 0;
      }
      else {
        local_10 = 1;
      }
      local_10 = (uint)(DAT_005ee564 != 0);
      local_28 = 0;
      DAT_0066aaf0 = 0;
      DAT_005ee564 = 0;
    }
    if (DAT_0066aaf4 == 0) {
      _DAT_005ee560 = 0;
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if ((*(int *)(&deck + local_1c * 4) != -1) && (((&DAT_006c13b1)[local_1c * 4] & 0x40) == 0))
        {
          local_4c[4] = local_4c[4] + 1;
        }
      }
      if (local_4c[4] < local_4c[DAT_005f2f50]) {
        _DAT_005ee560 = 1;
        FID_conflict__memcpy(&DAT_005edd90,&deck,2000);
        for (local_1c = 0; local_1c < local_4c[DAT_005f2f50] - local_4c[4]; local_1c = local_1c + 1)
        {
          arg_1 = FUN_00439892(5);
          Ai_Subsystem_004cc1e8(arg_1);
        }
      }
      for (local_1c = 0; local_1c < 0x3c; local_1c = local_1c + 1) {
        *(undefined4 *)(&DAT_006671c0 + local_1c * 4) = 0;
        *(undefined4 *)(&DAT_006669f0 + local_1c * 4) =
             *(undefined4 *)(&DAT_006671c0 + local_1c * 4);
      }
      for (local_1c = 0x3c; local_1c < 500; local_1c = local_1c + 1) {
        *(undefined4 *)(&DAT_006671c0 + local_1c * 4) = 0xffffffff;
        *(undefined4 *)(&DAT_006669f0 + local_1c * 4) =
             *(undefined4 *)(&DAT_006671c0 + local_1c * 4);
      }
      FUN_00451482(0,0x30);
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if ((*(uint *)(&deck + local_1c * 4) & 0xfff) == DAT_0068ed50) {
          *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) | 0x8000;
          break;
        }
      }
      for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
        if (DAT_00505988 == -1) {
          iVar1 = FUN_004d7382();
          Pic_Subsystem_00451291(0,iVar1);
        }
        else {
          iVar1 = FUN_004396ea(DAT_00505988);
          Pic_Subsystem_00451291(0,iVar1);
        }
      }
      if (DAT_00505984 != -1) {
        if ((DAT_00505988 == -1) && (FUN_00439570(DAT_00505984), DAT_0068ed90 != -1)) {
          FUN_004395d6(0,DAT_0068ed90);
        }
        for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
          iVar1 = FUN_004396ea((uint)(DAT_00505988 != -1));
          Pic_Subsystem_00451291(1,iVar1);
        }
      }
      FUN_004d6362(&local_18,&local_34,&local_20);
      Ai_AssignCombatDamage
                (&local_10,(uint *)(local_4c + 5),local_10,local_28,DAT_0068ed90,DAT_0068ed50,
                 local_18,local_34,local_20);
      if (local_4c[5] != 0) {
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          *(undefined4 *)(&DAT_006826c4 + local_1c * 0x120) = 0xffffffff;
          *(undefined4 *)(&DAT_006826c0 + local_1c * 0x120) = 0xffffffff;
        }
        for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
          if (*(int *)(&deck + local_1c * 4) != -1) {
            *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) & 0xffff7fff;
          }
        }
        for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
          if ((*(uint *)(&deck + local_1c * 4) & 0xfff) == DAT_0068ed50) {
            *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) | 0x8000;
            break;
          }
        }
        for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
          if (DAT_00505988 == -1) {
            iVar1 = FUN_004d7382();
            Pic_Subsystem_00451291(0,iVar1);
          }
          else {
            iVar1 = FUN_004396ea(DAT_00505988);
            Pic_Subsystem_00451291(0,iVar1);
          }
        }
        FUN_00451482(0,0x30);
      }
      if ((local_34 != 0) || ((local_4c[5] != 0 && (local_20 != 0)))) {
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          *(undefined4 *)(&DAT_006881e4 + local_1c * 0x120) = 0xffffffff;
          *(undefined4 *)(&DAT_006881e0 + local_1c * 0x120) = 0xffffffff;
        }
        if ((DAT_00505988 == -1) && (FUN_00439570(DAT_00505984), DAT_0068ed90 != -1)) {
          FUN_004395d6(0,DAT_0068ed90);
        }
        for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
          iVar1 = FUN_004396ea((uint)(DAT_00505988 != -1));
          Pic_Subsystem_00451291(1,iVar1);
        }
        FUN_00451482(0,0x30);
      }
      if (DAT_00505988 == -1) {
        DAT_00505984 = 0;
      }
      for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
        if (DAT_00505988 == -1) {
          uVar2 = FUN_004d7382();
          *(undefined4 *)(&DAT_006669f0 + local_1c * 4) = uVar2;
        }
        else {
          uVar2 = FUN_004396ea(DAT_00505988);
          *(undefined4 *)(&DAT_006669f0 + local_1c * 4) = uVar2;
        }
        uVar2 = FUN_004396ea(DAT_00505984);
        *(undefined4 *)(&DAT_006671c0 + local_1c * 4) = uVar2;
      }
      DAT_00505988 = -1;
      if (((*(byte *)(arg2 * 0x44 + 0x5073a8) & 2) != 0) && (DAT_005f2f4c % 3 == 0)) {
        FID_conflict__memcpy(&DAT_006671c0,&DAT_006669f0,1000);
        local_1c = DAT_0066aaf4;
        DAT_0066aaf4 = 1;
        FUN_004d7946(1);
        DAT_0066aaf4 = local_1c;
        FID_conflict__memcpy(&DAT_006881e0,&DAT_006826c0,0x5b20);
        for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
          if (*(int *)(&DAT_006881e4 + local_1c * 0x120) != -1) {
            *(uint *)(&DAT_006881ec + local_1c * 0x120) =
                 *(uint *)(&DAT_006881ec + local_1c * 0x120) | 0x1000;
          }
        }
        DAT_006668f8 = 0;
      }
      if (DAT_0068ee60 != -1) {
        local_1c = Pic_Subsystem_00451291(1,DAT_0068ee60);
        if (local_1c != -1) {
          *(uint *)(&DAT_006881ec + local_1c * 0x120) =
               *(uint *)(&DAT_006881ec + local_1c * 0x120) | 0x30002;
        }
        DAT_0068ee60 = -1;
        if (DAT_005071c4 == -1) {
          DAT_005071c4 = 0;
        }
      }
      if (DAT_00666418 != -1) {
        local_1c = Pic_Subsystem_00451291(1,DAT_00666418);
        Pic_Subsystem_0042ac1f(1,local_1c);
        DAT_00666418 = -1;
        if (DAT_005071c4 == -1) {
          DAT_005071c4 = 0;
        }
      }
      if (5 < DAT_005071c4) {
        local_1c = Pic_Subsystem_00451291(0,DAT_005071c4);
        Pic_Subsystem_0042ac1f(0,local_1c);
      }
    }
  }
  FUN_00487a10();
  if (DAT_0066aaf4 == -1) {
    FUN_004328ba(0);
  }
  if (DAT_0066aaf4 == -2) {
    FUN_004328ba(1);
  }
  if (DAT_0066aaf4 == -10) {
    FUN_00433d45(DAT_0061531c);
    FUN_00451482(0,0xff);
    local_14 = DAT_00666458;
  }
  else if (DAT_0066aaf4 == -1) {
    DAT_00681ec0 = 0;
    FUN_00451482(0,0xff);
    local_14 = 1;
  }
  else if (DAT_0066aaf4 == -2) {
    DAT_00681ec0 = 0;
    FUN_00451482(0,0xff);
    local_14 = 0;
  }
  else {
    DAT_00681ec0 = 1;
    local_14 = local_10;
  }
  while ((DAT_0068ef40 == 0 && (iVar1 = FUN_0042afdb(), iVar1 == 0))) {
    if (DAT_00690318 == 0) {
      FUN_00426c70(local_14);
      local_14 = 1 - local_14;
    }
    else {
      if ((DAT_00690318 & 1) == 0) {
        DAT_00690318 = 0;
        if (local_14 == 0) {
          DAT_0068f0f8 = 0xffffffff;
        }
        FUN_00426c70(1);
      }
      else {
        DAT_00690318 = 0;
        if (local_14 == 1) {
          DAT_0068f0f8 = 0xffffffff;
        }
        FUN_00426c70(0);
      }
      DAT_0068f0f8 = 0xffffffff;
    }
  }
  if (DAT_0068f0d0 == 0) {
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      if (*(int *)(&deck + local_1c * 4) != -1) {
        *(uint *)(&deck + local_1c * 4) = *(uint *)(&deck + local_1c * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_0050928c);
  }
  DAT_005071c4 = 0xffffffff;
  DAT_0068ee60 = 0xffffffff;
  DAT_00666418 = 0xffffffff;
  DAT_0066aaf4 = 0;
  for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
    *(undefined4 *)(&DAT_00666710 + local_1c * 4) = 8;
  }
  DAT_0068eed8 = 0;
  _DAT_0068eed4 = 1;
  if (((DAT_00681ea8 < 1) || (9 < DAT_006668f0)) || ((0 < DAT_00681eac && (DAT_006668f4 < 10)))) {
    if (((DAT_00681eac < 1) || (9 < DAT_006668f4)) || ((0 < DAT_00681ea8 && (DAT_006668f0 < 10)))) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


