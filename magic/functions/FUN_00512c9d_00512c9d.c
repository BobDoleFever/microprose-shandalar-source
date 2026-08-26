/*
 * Decompiled function: FUN_00512c9d
 * Entry Point: 00512c9d
 * Size: 1364 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00512c9d(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  byte *pbVar8;
  uint uVar9;
  ushort uVar10;
  uint arg_1;
  bool bVar11;
  code *in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  undefined2 uStack00000028;
  undefined2 uStack0000002c;
  
  DAT_006261e4 = (int)malloc(0xbfd0);
  DAT_006261e8 = -1;
  _DAT_006261ca = 0;
  DAT_006261c0 = 0;
  DAT_006261b8 = 0;
  _DAT_006261cc = uStack00000028;
  _DAT_006261ce = uStack0000002c;
  _DAT_006261c8 = 0x3058;
  DAT_006261e0 = 0;
  iVar6 = 7;
  pbVar8 = &DAT_006261c8;
  do {
    FUN_005135e0(8,(uint)*pbVar8);
    bVar11 = iVar6 != 0;
    iVar6 = iVar6 + -1;
    pbVar8 = pbVar8 + 1;
  } while (bVar11);
  uVar10 = 1;
  pbVar2 = &DAT_006261f0 + in_stack_00000020;
  uVar4 = 0xffffffff;
  pbVar8 = pbVar2 + _uStack00000028;
  do {
    uVar9 = uVar4;
    pbVar3 = pbVar8;
    if (pbVar2 + _uStack00000028 <= pbVar8) {
      bVar11 = _uStack0000002c == 0;
      _uStack0000002c = _uStack0000002c + -1;
      if (bVar11) {
        iVar6 = DAT_006261e8;
        if ((short)uVar4 == 0x90) {
          while (DAT_006261e8 = iVar6, uVar10 != 0) {
            uVar10 = uVar10 - 1;
            if (iVar6 == -1) {
              DAT_006261e8 = 0;
              FUN_005135e0(8,0xb);
              FUN_005134a0();
              DAT_006261dc = 0x90;
              g_OverworldWorldState = 0x90;
              DAT_006261d8 = 1;
              iVar6 = DAT_006261dc;
            }
            else {
              iVar5 = DAT_006261d8 + 1;
              puVar1 = &g_OverworldWorldState + DAT_006261d8;
              DAT_006261d8 = iVar5;
              *puVar1 = 0x90;
              if (iVar6 < iVar5) {
                DAT_006261e8 = iVar5;
              }
              iVar6 = FUN_00513510(0x90);
              if (iVar6 == -1) {
                *DAT_00702924 = 0x90;
                DAT_00702924[1] = DAT_006261dc;
                DAT_00702924[2] = DAT_006261ec;
                DAT_006261ec = DAT_006261ec + 1;
                FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
                DAT_006261d8 = 1;
                DAT_006261dc = 0x90;
                g_OverworldWorldState = 0x90;
                iVar6 = DAT_006261dc;
                if ((1 << ((byte)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                   (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                  FUN_005134a0();
                  iVar6 = DAT_006261dc;
                }
              }
            }
            DAT_006261dc = iVar6;
            FUN_00513200(0);
            iVar6 = DAT_006261e8;
          }
        }
        else {
          if (3 < uVar10) {
            do {
              uVar9 = (uint)uVar10;
              if (0xfe < uVar10) {
                uVar9 = 0xff;
              }
              uVar10 = uVar10 - (short)uVar9;
              FUN_00513200(uVar4 & 0xffff);
              FUN_00513200(0x90);
              FUN_00513200(uVar9);
            } while (3 < uVar10);
          }
          if (uVar10 != 0) {
            do {
              uVar10 = uVar10 - 1;
              FUN_00513200(uVar4 & 0xffff);
            } while (uVar10 != 0);
          }
        }
        FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
        FUN_005135e0(8,0);
        _write(DAT_006261d4,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        lVar7 = _tell(DAT_006261d4);
        _DAT_006261ca = (short)lVar7 + -4;
        if (DAT_006261d0 == 0) {
          lVar7 = 0;
        }
        else {
          lVar7 = 0x306;
        }
        _lseek(DAT_006261d4,lVar7,0);
        _write(DAT_006261d4,&DAT_006261c8,8);
        free((void *)DAT_006261e4);
        _close(DAT_006261d4);
        return;
      }
      iVar6 = in_stack_00000024 + 1;
      (*in_stack_00000018)
                (pbVar2,in_stack_0000001c,in_stack_00000020,in_stack_00000024,_uStack00000028);
      pbVar3 = pbVar2;
      in_stack_00000024 = iVar6;
      if (uVar4 == 0xffffffff) {
        pbVar3 = (byte *)(in_stack_00000020 + 0x6261f1);
        uVar9 = (uint)*pbVar2;
      }
    }
    pbVar8 = pbVar3 + 1;
    uVar4 = (uint)*pbVar3;
    if (uVar9 == uVar4) {
      uVar10 = uVar10 + 1;
      uVar4 = uVar9;
    }
    else {
      iVar6 = DAT_006261e8;
      if ((short)uVar9 == 0x90) {
        while (DAT_006261e8 = iVar6, uVar10 != 0) {
          uVar10 = uVar10 - 1;
          if (iVar6 == -1) {
            DAT_006261e8 = 0;
            FUN_005135e0(8,0xb);
            FUN_005134a0();
            DAT_006261dc = 0x90;
            g_OverworldWorldState = 0x90;
            DAT_006261d8 = 1;
            iVar6 = DAT_006261dc;
          }
          else {
            iVar5 = DAT_006261d8 + 1;
            puVar1 = &g_OverworldWorldState + DAT_006261d8;
            DAT_006261d8 = iVar5;
            *puVar1 = 0x90;
            if (iVar6 < iVar5) {
              DAT_006261e8 = iVar5;
            }
            iVar6 = FUN_00513510(0x90);
            if (iVar6 == -1) {
              *DAT_00702924 = 0x90;
              DAT_00702924[1] = DAT_006261dc;
              DAT_00702924[2] = DAT_006261ec;
              DAT_006261ec = DAT_006261ec + 1;
              FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
              DAT_006261dc = 0x90;
              g_OverworldWorldState = 0x90;
              DAT_006261d8 = 1;
              iVar6 = DAT_006261dc;
              if ((1 << ((byte)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                 (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                FUN_005134a0();
                iVar6 = DAT_006261dc;
              }
            }
          }
          DAT_006261dc = iVar6;
          FUN_00513200(0);
          iVar6 = DAT_006261e8;
        }
      }
      else {
        if (3 < uVar10) {
          do {
            arg_1 = (uint)uVar10;
            if (0xfe < uVar10) {
              arg_1 = 0xff;
            }
            uVar10 = uVar10 - (short)arg_1;
            FUN_00513200(uVar9 & 0xffff);
            FUN_00513200(0x90);
            FUN_00513200(arg_1);
          } while (3 < uVar10);
        }
        if (uVar10 != 0) {
          do {
            uVar10 = uVar10 - 1;
            FUN_00513200(uVar9 & 0xffff);
          } while (uVar10 != 0);
        }
      }
      uVar10 = 1;
    }
  } while( true );
}


