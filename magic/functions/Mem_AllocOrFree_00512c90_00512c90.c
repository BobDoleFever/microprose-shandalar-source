/*
 * Decompiled function: Mem_AllocOrFree_00512c90
 * Entry Point: 00512c90
 * Size: 13 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Mem_AllocOrFree_00512c90
               (int arg_1,undefined *arg_2,undefined4 arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  undefined1 *puVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  ushort uVar8;
  uint arg_1_00;
  bool bVar9;
  byte *pbStack_10;
  
  DAT_006261d4 = arg_1;
  DAT_006261e4 = (int)malloc(0xbfd0);
  DAT_006261e8 = -1;
  _DAT_006261ca = 0;
  DAT_006261c0 = 0;
  DAT_006261b8 = 0;
  _DAT_006261cc = (undefined2)arg_6;
  _DAT_006261ce = (undefined2)arg_7;
  _DAT_006261c8 = 0x3058;
  DAT_006261e0 = 0;
  iVar5 = 7;
  pbVar2 = &DAT_006261c8;
  do {
    FUN_005135e0(8,(uint)*pbVar2);
    bVar9 = iVar5 != 0;
    iVar5 = iVar5 + -1;
    pbVar2 = pbVar2 + 1;
  } while (bVar9);
  uVar8 = 1;
  pbVar2 = &DAT_006261f0 + arg_4;
  uVar3 = 0xffffffff;
  pbStack_10 = pbVar2 + arg_6;
  do {
    uVar7 = uVar3;
    if (pbVar2 + arg_6 <= pbStack_10) {
      bVar9 = arg_7 == 0;
      arg_7 = arg_7 + -1;
      if (bVar9) {
        iVar5 = DAT_006261e8;
        if ((short)uVar3 == 0x90) {
          while (DAT_006261e8 = iVar5, uVar8 != 0) {
            uVar8 = uVar8 - 1;
            if (iVar5 == -1) {
              DAT_006261e8 = 0;
              FUN_005135e0(8,0xb);
              FUN_005134a0();
              DAT_006261dc = 0x90;
              g_OverworldWorldState = 0x90;
              DAT_006261d8 = 1;
              iVar5 = DAT_006261dc;
            }
            else {
              iVar4 = DAT_006261d8 + 1;
              puVar1 = &g_OverworldWorldState + DAT_006261d8;
              DAT_006261d8 = iVar4;
              *puVar1 = 0x90;
              if (iVar5 < iVar4) {
                DAT_006261e8 = iVar4;
              }
              iVar5 = FUN_00513510(0x90);
              if (iVar5 == -1) {
                *DAT_00702924 = 0x90;
                DAT_00702924[1] = DAT_006261dc;
                DAT_00702924[2] = DAT_006261ec;
                DAT_006261ec = DAT_006261ec + 1;
                FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
                DAT_006261d8 = 1;
                DAT_006261dc = 0x90;
                g_OverworldWorldState = 0x90;
                iVar5 = DAT_006261dc;
                if ((1 << ((byte)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                   (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                  FUN_005134a0();
                  iVar5 = DAT_006261dc;
                }
              }
            }
            DAT_006261dc = iVar5;
            FUN_00513200(0);
            iVar5 = DAT_006261e8;
          }
        }
        else {
          if (3 < uVar8) {
            do {
              uVar7 = (uint)uVar8;
              if (0xfe < uVar8) {
                uVar7 = 0xff;
              }
              uVar8 = uVar8 - (short)uVar7;
              FUN_00513200(uVar3 & 0xffff);
              FUN_00513200(0x90);
              FUN_00513200(uVar7);
            } while (3 < uVar8);
          }
          if (uVar8 != 0) {
            do {
              uVar8 = uVar8 - 1;
              FUN_00513200(uVar3 & 0xffff);
            } while (uVar8 != 0);
          }
        }
        FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
        FUN_005135e0(8,0);
        _write(DAT_006261d4,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        lVar6 = _tell(DAT_006261d4);
        _DAT_006261ca = (short)lVar6 + -4;
        if (DAT_006261d0 == 0) {
          lVar6 = 0;
        }
        else {
          lVar6 = 0x306;
        }
        _lseek(DAT_006261d4,lVar6,0);
        _write(DAT_006261d4,&DAT_006261c8,8);
        free((void *)DAT_006261e4);
        _close(DAT_006261d4);
        return;
      }
      iVar5 = arg_5 + 1;
      (*(code *)arg_2)(pbVar2,arg_3,arg_4,arg_5,arg_6);
      arg_5 = iVar5;
      pbStack_10 = pbVar2;
      if (uVar3 == 0xffffffff) {
        pbStack_10 = (byte *)(arg_4 + 0x6261f1);
        uVar7 = (uint)*pbVar2;
      }
    }
    uVar3 = (uint)*pbStack_10;
    if (uVar7 == uVar3) {
      uVar8 = uVar8 + 1;
      uVar3 = uVar7;
      pbStack_10 = pbStack_10 + 1;
    }
    else {
      iVar5 = DAT_006261e8;
      if ((short)uVar7 == 0x90) {
        while (DAT_006261e8 = iVar5, uVar8 != 0) {
          uVar8 = uVar8 - 1;
          if (iVar5 == -1) {
            DAT_006261e8 = 0;
            FUN_005135e0(8,0xb);
            FUN_005134a0();
            DAT_006261dc = 0x90;
            g_OverworldWorldState = 0x90;
            DAT_006261d8 = 1;
            iVar5 = DAT_006261dc;
          }
          else {
            iVar4 = DAT_006261d8 + 1;
            puVar1 = &g_OverworldWorldState + DAT_006261d8;
            DAT_006261d8 = iVar4;
            *puVar1 = 0x90;
            if (iVar5 < iVar4) {
              DAT_006261e8 = iVar4;
            }
            iVar5 = FUN_00513510(0x90);
            if (iVar5 == -1) {
              *DAT_00702924 = 0x90;
              DAT_00702924[1] = DAT_006261dc;
              DAT_00702924[2] = DAT_006261ec;
              DAT_006261ec = DAT_006261ec + 1;
              FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
              DAT_006261dc = 0x90;
              g_OverworldWorldState = 0x90;
              DAT_006261d8 = 1;
              iVar5 = DAT_006261dc;
              if ((1 << ((byte)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                 (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                FUN_005134a0();
                iVar5 = DAT_006261dc;
              }
            }
          }
          DAT_006261dc = iVar5;
          FUN_00513200(0);
          iVar5 = DAT_006261e8;
        }
      }
      else {
        if (3 < uVar8) {
          do {
            arg_1_00 = (uint)uVar8;
            if (0xfe < uVar8) {
              arg_1_00 = 0xff;
            }
            uVar8 = uVar8 - (short)arg_1_00;
            FUN_00513200(uVar7 & 0xffff);
            FUN_00513200(0x90);
            FUN_00513200(arg_1_00);
          } while (3 < uVar8);
        }
        if (uVar8 != 0) {
          do {
            uVar8 = uVar8 - 1;
            FUN_00513200(uVar7 & 0xffff);
          } while (uVar8 != 0);
        }
      }
      uVar8 = 1;
      pbStack_10 = pbStack_10 + 1;
    }
  } while( true );
}


