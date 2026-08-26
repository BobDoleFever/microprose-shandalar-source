/*
 * sidlib/Pcxw.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: FUN_00512230
 * Entry Point: 00512230
 * Size: 608 bytes
 */


undefined4 * FUN_00512230(char *str_1,undefined4 *arg_2,void *arg_3)

{
  undefined1 *puVar1;
  byte bVar2;
  uint uVar3;
  HGLOBAL pvVar4;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  int local_8;
  int iVar5;
  
  DAT_00703930 = (int)fopen(str_1,&DAT_0052afc4);
  AssertOrLog((uint)((FILE *)DAT_00703930 != (FILE *)0x0),
              (int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x69,
              s_Error_Opening_File__s_005327dc);
  DAT_00703938 = str_1;
  FUN_00512500(arg_3);
  if ((DAT_00703943 != '\b') || (iVar6 = 1, DAT_00703981 != '\x01')) {
    iVar6 = 0;
  }
  AssertOrLog(iVar6,(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x6f,
              s__s_Not_a_256_color_palettized_pc_00536cbc);
  uVar3 = 4 - (DAT_00536860 & 3);
  uVar9 = (int)uVar3 >> 0x1f;
  iVar6 = ((uVar3 ^ uVar9) - uVar9 & 3 ^ uVar9) - uVar9;
  if ((DAT_00536cb4 == DAT_00536860) && (DAT_00536cb8 == DAT_00536864)) {
    uVar9 = (DAT_00536cb4 + iVar6) * DAT_00536cb8;
    puVar12 = arg_2;
    for (uVar3 = uVar9 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
  }
  else {
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalFree(pvVar4);
    pvVar4 = GlobalAlloc(0x40,(iVar6 + DAT_00536860) * DAT_00536864);
    arg_2 = GlobalLock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalLock(pvVar4);
    DAT_00536cb4 = DAT_00536860;
    DAT_00536cb8 = DAT_00536864;
  }
  puVar12 = arg_2;
  local_8 = 0;
  if (0 < DAT_00536864) {
    do {
      pbVar11 = &DAT_00702930;
      for (iVar10 = (int)DAT_00703982; 0 < iVar10; iVar10 = iVar10 + iVar5) {
        uVar3 = fgetc((FILE *)DAT_00703930);
        bVar2 = (byte)uVar3;
        if ((bVar2 & 0xc0) == 0xc0) {
          uVar9 = uVar3 & 0x3f;
          iVar5 = fgetc((FILE *)DAT_00703930);
          bVar2 = (byte)iVar5;
          if (uVar9 < 2) goto LAB_00512421;
          if (uVar9 != 0) {
            pbVar13 = pbVar11;
            for (uVar7 = uVar9 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(uint *)pbVar13 = CONCAT22(CONCAT11(bVar2,bVar2),CONCAT11(bVar2,bVar2));
              pbVar13 = pbVar13 + 4;
            }
            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *pbVar13 = bVar2;
              pbVar13 = pbVar13 + 1;
            }
            pbVar11 = pbVar11 + uVar9;
          }
          iVar5 = -uVar9;
        }
        else {
LAB_00512421:
          *pbVar11 = bVar2;
          pbVar11 = pbVar11 + 1;
          iVar5 = -1;
        }
      }
      iVar10 = 0;
      if (0 < (int)DAT_00536860) {
        do {
          puVar1 = &DAT_00702930 + iVar10;
          puVar8 = (undefined4 *)((int)arg_2 + 1);
          iVar10 = iVar10 + 1;
          *(undefined1 *)arg_2 = *puVar1;
          arg_2 = puVar8;
        } while (iVar10 < (int)DAT_00536860);
      }
      arg_2 = (undefined4 *)((int)arg_2 + iVar6);
      local_8 = local_8 + 1;
    } while (local_8 < DAT_00536864);
  }
  fclose((FILE *)DAT_00703930);
  return puVar12;
}



/*
 * Decompiled function: FUN_00512500
 * Entry Point: 00512500
 * Size: 421 bytes
 */


undefined4 FUN_00512500(void *arg_1)

{
  int iVar1;
  
  fread(&DAT_00703940,0x80,1,DAT_00703930);
  AssertOrLog((uint)(DAT_00703940 == '\n'),(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0xad
              ,s__s_Not_a_pcx_file_00536d30);
  AssertOrLog((uint)(DAT_00703941 == '\x05'),(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,
              0xae,s__s_Not_a_version_5_pcx_file_00536d10);
  DAT_00536860 = ((uint)DAT_00703948 - (uint)DAT_00703944) + 1;
  DAT_00536864 = ((uint)DAT_0070394a - (uint)DAT_00703946) + 1;
  if (arg_1 == (void *)0x0) {
    return 1;
  }
  if ((DAT_00703981 == '\x01') && (DAT_00703943 == '\b')) {
    fseek(DAT_00703930,-0x300,2);
    fread(arg_1,1,0x300,DAT_00703930);
    fseek(DAT_00703930,0x80,0);
    return 1;
  }
  if ((DAT_00703981 == '\x04') && (DAT_00703943 == '\x01')) {
    iVar1 = 0x10;
    fseek(DAT_00703930,0x10,2);
    do {
      fread(arg_1,1,3,DAT_00703930);
      iVar1 = iVar1 + -1;
      arg_1 = (void *)((int)arg_1 + 4);
    } while (iVar1 != 0);
    fseek(DAT_00703930,0x80,0);
    return 1;
  }
  AssertOrLog(0,(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0xd4,
              s__s_is_not_in_a_recognizable_form_00536ce8);
  return 1;
}



/*
 * Decompiled function: FUN_005126b0
 * Entry Point: 005126b0
 * Size: 132 bytes
 */


undefined4 FUN_005126b0(byte *arg_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  iVar6 = (int)DAT_00703982;
  do {
    if (iVar6 < 1) {
      return 1;
    }
    uVar2 = fgetc(DAT_00703930);
    bVar1 = (byte)uVar2;
    if ((bVar1 & 0xc0) == 0xc0) {
      uVar3 = uVar2 & 0x3f;
      iVar4 = fgetc(DAT_00703930);
      bVar1 = (byte)iVar4;
      if (uVar3 < 2) goto LAB_00512722;
      if (uVar3 != 0) {
        pbVar7 = arg_1;
        for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(uint *)pbVar7 = CONCAT22(CONCAT11(bVar1,bVar1),CONCAT11(bVar1,bVar1));
          pbVar7 = pbVar7 + 4;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pbVar7 = bVar1;
          pbVar7 = pbVar7 + 1;
        }
        arg_1 = arg_1 + uVar3;
      }
      iVar4 = -uVar3;
    }
    else {
LAB_00512722:
      *arg_1 = bVar1;
      arg_1 = arg_1 + 1;
      iVar4 = -1;
    }
    iVar6 = iVar6 + iVar4;
  } while( true );
}



/*
 * Decompiled function: FUN_00512740
 * Entry Point: 00512740
 * Size: 422 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00512740(void)

{
  int arg_4;
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int in_stack_00001008;
  char *in_stack_0000100c;
  void *in_stack_00001010;
  int in_stack_00001014;
  int in_stack_00001018;
  uint in_stack_0000101c;
  int in_stack_00001020;
  
  Mem_AllocOrFree_00513bd0();
  DAT_00703934 = (int)fopen(in_stack_0000100c,&DAT_00536d44);
  AssertOrLog((uint)((FILE *)DAT_00703934 != (FILE *)0x0),
              (int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x146,
              s_Error_Opening_File__s_005327dc);
  DAT_00703940 = 10;
  iVar3 = 0;
  DAT_00703944 = 0;
  uVar2 = (ushort)in_stack_0000101c;
  DAT_00703948 = uVar2 - 1;
  DAT_00703941 = 5;
  DAT_00703942 = 1;
  DAT_00703943 = 8;
  DAT_0070394a = (short)in_stack_00001020 + -1;
  DAT_00703980 = 0;
  DAT_00703981 = 1;
  DAT_00703946 = 0;
  _DAT_0070394c = 0;
  uVar1 = (ushort)((int)in_stack_0000101c >> 0x1f);
  _DAT_0070394e = 0;
  _DAT_00703986 = 0;
  _DAT_00703988 = 0;
  DAT_00703982 = (((uVar2 ^ uVar1) - uVar1 & 1 ^ uVar1) - uVar1) + uVar2;
  _DAT_00703984 = 1;
  DAT_00703938 = in_stack_0000100c;
  fwrite(&DAT_00703940,0x80,1,(FILE *)DAT_00703934);
  if (0 < in_stack_00001020) {
    do {
      arg_4 = in_stack_00001018 + iVar3;
      iVar3 = iVar3 + 1;
      Surface_GetLine((undefined4 *)&stack0x00000004,in_stack_00001008,in_stack_00001014,arg_4,
                      in_stack_0000101c);
      FUN_005129a0(&stack0x00000004,in_stack_0000101c);
    } while (iVar3 < in_stack_00001020);
  }
  fwrite(&stack0x00000003,1,1,(FILE *)DAT_00703934);
  fwrite(in_stack_00001010,3,0x100,(FILE *)DAT_00703934);
  fclose((FILE *)DAT_00703934);
  return 0;
}



/*
 * Decompiled function: FUN_005129a0
 * Entry Point: 005129a0
 * Size: 293 bytes
 */


undefined4 FUN_005129a0(byte *arg1,int arg2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined1 local_7;
  byte local_6;
  byte local_5;
  uint local_4;
  
  iVar3 = 0;
  if (0 < arg2) {
    do {
      local_5 = *arg1;
      iVar2 = arg2 - iVar3;
      if ((iVar2 == 1) || (arg1[1] != local_5)) {
        local_7 = 0xc1;
        local_6 = local_5;
        if ((local_5 & 0xc0) == 0xc0) {
          fwrite(&local_7,1,1,DAT_00703934);
        }
        iVar3 = iVar3 + 1;
        arg1 = arg1 + 1;
        fwrite(&local_6,1,1,DAT_00703934);
      }
      else {
        if (0x3e < iVar2) {
          iVar2 = 0x3f;
        }
        local_4 = 0;
        pbVar1 = arg1;
        while (iVar2 != 0) {
          iVar2 = iVar2 + -1;
          if (*pbVar1 != local_5) break;
          local_4 = local_4 + 1;
          pbVar1 = pbVar1 + 1;
        }
        iVar3 = iVar3 + local_4;
        arg1 = arg1 + local_4;
        local_4 = local_4 | 0xc0;
        fwrite(&local_4,1,1,DAT_00703934);
        fwrite(&local_5,1,1,DAT_00703934);
      }
    } while (iVar3 < arg2);
  }
  if (iVar3 < DAT_00703982) {
    local_5 = 0;
    fwrite(&local_5,1,1,DAT_00703934);
  }
  return 1;
}



/*
 * Decompiled function: FUN_00512b50
 * Entry Point: 00512b50
 * Size: 66 bytes
 */


undefined4 FUN_00512b50(void *arg_1)

{
  undefined1 local_1;
  
  local_1 = 0xc;
  fwrite(&local_1,1,1,DAT_00703934);
  fwrite(arg_1,3,0x100,DAT_00703934);
  return 0;
}



/*
 * Decompiled function: FUN_00512ba0
 * Entry Point: 00512ba0
 * Size: 95 bytes
 */


int FUN_00512ba0(undefined4 arg1,char *str_2)

{
  int arg_1;
  int iVar1;
  
  arg_1 = _open(str_2,0x8302,0x80);
  iVar1 = arg_1;
  if (arg_1 != -1) {
    DAT_006261d0 = 0;
    iVar1 = Mem_AllocOrFree_00512c90(arg_1,Surface_GetLine,arg1,0,0,0x140,200);
    _close(arg_1);
  }
  return iVar1;
}



/*
 * Decompiled function: FUN_00512c00
 * Entry Point: 00512c00
 * Size: 130 bytes
 */


int FUN_00512c00(undefined4 arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,char *str_7)

{
  int arg_1_00;
  int iVar1;
  
  arg_1_00 = _open(str_7,0x8302,0x80);
  iVar1 = arg_1_00;
  if (arg_1_00 != -1) {
    if (arg_6 != 0) {
      FUN_0050eb90(arg_1_00);
    }
    DAT_006261d0 = (uint)(arg_6 != 0);
    iVar1 = Mem_AllocOrFree_00512c90(arg_1_00,Surface_GetLine,arg_1,arg_2,arg_3,arg_4,arg_5);
    _close(arg_1_00);
  }
  return iVar1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00512c90
 * Entry Point: 00512c90
 * Size: 13 bytes
 */


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



/*
 * Decompiled function: FUN_00512c9d
 * Entry Point: 00512c9d
 * Size: 1364 bytes
 */


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



/*
 * Decompiled function: FUN_00513200
 * Entry Point: 00513200
 * Size: 664 bytes
 */


void FUN_00513200(int arg_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  
  iVar7 = DAT_006261e8;
  uVar6 = (undefined1)arg_1;
  if (DAT_006261e8 == -1) {
    iVar7 = 0;
    DAT_006261e8 = 0;
    FUN_005135e0(8,0xb);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 0xc;
      *(int *)(DAT_006261e4 + -4 + iVar3) = iVar7;
      *(int *)(DAT_006261e4 + -0xc + iVar3) = iVar7;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(DAT_006261e4 + -8 + iVar3) = 0xffffffff;
    } while (iVar3 < 0xc00);
    if (iVar7 < 0xffb) {
      iVar7 = iVar7 * 0xc;
      do {
        iVar7 = iVar7 + 0xc;
        *(undefined4 *)(DAT_006261e4 + -0xc + iVar7) = 0xffffffff;
      } while (iVar7 < 0xbfc4);
    }
    DAT_006261bc = 9;
    DAT_006261ec = 0x101;
    DAT_006261d8 = 1;
    DAT_006261dc = arg_1;
    g_OverworldWorldState = uVar6;
    return;
  }
  iVar2 = DAT_006261d8 + 1;
  puVar1 = &g_OverworldWorldState + DAT_006261d8;
  DAT_006261d8 = iVar2;
  *puVar1 = uVar6;
  iVar3 = DAT_006261d8;
  if (iVar7 < iVar2) {
    DAT_006261e8 = iVar2;
  }
  uVar4 = 0;
  (&g_OverworldWorldState)[DAT_006261d8] = 0;
  if (0 < iVar3) {
    iVar7 = 0;
    do {
      uVar4 = uVar4 + (int)*(short *)(&g_OverworldWorldState + iVar7);
      iVar7 = iVar7 + 2;
    } while (iVar7 < DAT_006261d8);
  }
  uVar4 = uVar4 & 0x7fff;
  if (uVar4 == 0) {
    uVar4 = DAT_006261d8 * 0x25 & 0x7fff;
  }
  uVar5 = uVar4 % 0xffb;
  iVar7 = -1;
  while( true ) {
    DAT_00702924 = (int *)(DAT_006261e4 + uVar5 * 0xc);
    if (*DAT_00702924 == -1) break;
    if ((arg_1 == *DAT_00702924) && (DAT_00702924[1] == DAT_006261dc)) goto LAB_0051338a;
    if (iVar7 == -1) {
      iVar7 = 0xff9 - uVar4 % 0xff9;
    }
    if (iVar7 == 0) {
      iVar7 = DAT_006261d8 * 0x89;
    }
    uVar5 = (int)(uVar5 + iVar7) % 0xffb;
  }
  uVar5 = 0xffffffff;
LAB_0051338a:
  if (uVar5 != 0xffffffff) {
    DAT_006261dc = uVar5;
    return;
  }
  *DAT_00702924 = arg_1;
  DAT_00702924[1] = DAT_006261dc;
  DAT_00702924[2] = DAT_006261ec;
  DAT_006261ec = DAT_006261ec + 1;
  FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
  DAT_006261dc = arg_1;
  DAT_006261d8 = 1;
  g_OverworldWorldState = uVar6;
  if ((1 << ((byte)DAT_006261bc & 0x1f) < DAT_006261ec) &&
     (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
    iVar3 = 0;
    iVar7 = 0;
    do {
      iVar3 = iVar3 + 0xc;
      *(int *)(DAT_006261e4 + -4 + iVar3) = iVar7;
      *(int *)(DAT_006261e4 + -0xc + iVar3) = iVar7;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(DAT_006261e4 + -8 + iVar3) = 0xffffffff;
    } while (iVar3 < 0xc00);
    if (iVar7 < 0xffb) {
      iVar7 = iVar7 * 0xc;
      do {
        iVar7 = iVar7 + 0xc;
        *(undefined4 *)(DAT_006261e4 + -0xc + iVar7) = 0xffffffff;
      } while (iVar7 < 0xbfc4);
    }
    DAT_006261bc = 9;
    DAT_006261ec = 0x101;
  }
  return;
}



/*
 * Decompiled function: FUN_005134a0
 * Entry Point: 005134a0
 * Size: 109 bytes
 */


void FUN_005134a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 0xc;
    *(int *)(DAT_006261e4 + -4 + iVar2) = iVar1;
    *(int *)(DAT_006261e4 + -0xc + iVar2) = iVar1;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(DAT_006261e4 + -8 + iVar2) = 0xffffffff;
  } while (iVar2 < 0xc00);
  if (iVar1 < 0xffb) {
    iVar1 = iVar1 * 0xc;
    do {
      iVar1 = iVar1 + 0xc;
      *(undefined4 *)(DAT_006261e4 + -0xc + iVar1) = 0xffffffff;
    } while (iVar1 < 0xbfc4);
  }
  DAT_006261bc = 9;
  DAT_006261ec = 0x101;
  return;
}



/*
 * Decompiled function: FUN_00513510
 * Entry Point: 00513510
 * Size: 204 bytes
 */


uint FUN_00513510(int arg_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_006261d8;
  uVar2 = 0;
  (&g_OverworldWorldState)[DAT_006261d8] = 0;
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      uVar2 = uVar2 + (int)*(short *)(&g_OverworldWorldState + iVar1);
      iVar1 = iVar1 + 2;
    } while (iVar1 < DAT_006261d8);
  }
  uVar2 = uVar2 & 0x7fff;
  if (uVar2 == 0) {
    uVar2 = DAT_006261d8 * 0x25 & 0x7fff;
  }
  uVar3 = uVar2 % 0xffb;
  iVar1 = -1;
  while( true ) {
    DAT_00702924 = (int *)(DAT_006261e4 + uVar3 * 0xc);
    if (*DAT_00702924 == -1) {
      return 0xffffffff;
    }
    if ((arg_1 == *DAT_00702924) && (DAT_00702924[1] == DAT_006261dc)) break;
    if (iVar1 == -1) {
      iVar1 = 0xff9 - uVar2 % 0xff9;
    }
    if (iVar1 == 0) {
      iVar1 = DAT_006261d8 * 0x89;
    }
    uVar3 = (int)(iVar1 + uVar3) % 0xffb;
  }
  return uVar3;
}



/*
 * Decompiled function: FUN_005135e0
 * Entry Point: 005135e0
 * Size: 170 bytes
 */


void FUN_005135e0(int arg1,uint arg2)

{
  int arg_1;
  uint uVar1;
  
  arg_1 = DAT_006261d4;
  while (arg1 != 0) {
    arg1 = arg1 + -1;
    uVar1 = DAT_006261b8;
    if (7 < DAT_006261c0) {
      (&DAT_00706510)[DAT_006261e0] = (char)DAT_006261b8;
      DAT_006261e0 = DAT_006261e0 + 1;
      DAT_006261b8 = 0;
      DAT_006261c0 = 0;
      uVar1 = 0;
      if (0x1ff < DAT_006261e0) {
        _write(arg_1,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        arg_1 = DAT_006261d4;
        uVar1 = DAT_006261b8;
      }
    }
    DAT_006261b8 = (int)uVar1 >> 1;
    if ((arg2 & 1) != 0) {
      DAT_006261b8 = DAT_006261b8 | 0x80;
    }
    arg2 = (int)arg2 >> 1;
    DAT_006261c0 = DAT_006261c0 + 1;
  }
  return;
}



/*
 * Decompiled function: UI_Register_ShowPaletteClass_00513820
 * Entry Point: 00513820
 * Size: 131 bytes
 */


ATOM UI_Register_ShowPaletteClass_00513820(HINSTANCE hInstance)

{
  ATOM AVar1;
  WNDCLASSA local_28;
  
  local_28.style = 0x20;
  local_28.hInstance = hInstance;
  local_28.lpfnWndProc = (WNDPROC)&LAB_00513690;
  local_28.cbClsExtra = 0;
  local_28.cbWndExtra = 0;
  local_28.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_28.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_28.hbrBackground = CreateSolidBrush(0);
  local_28.lpszMenuName = (LPCSTR)0x0;
  local_28.lpszClassName = s_ShowPaletteClass_005326ac;
  AVar1 = RegisterClassA(&local_28);
  return AVar1;
}



/*
 * Decompiled function: UI_Register_ShowPaletteClass_005138b0
 * Entry Point: 005138b0
 * Size: 121 bytes
 */


void UI_Register_ShowPaletteClass_005138b0(HINSTANCE hInstance,HWND hwnd)

{
  tagRECT local_10;
  
  local_10.right = 0x100;
  local_10.bottom = 0x100;
  local_10.left = 0;
  local_10.top = 0;
  AdjustWindowRect(&local_10,0xcc0000,0);
  CreateWindowExA(0,s_ShowPaletteClass_005326ac,s_Current_Palette_005326c0,0x80c80000,100,0x32,
                  local_10.right - local_10.left,local_10.bottom - local_10.top,hwnd,(HMENU)0x0,
                  hInstance,(LPVOID)0x0);
  return;
}



/*
 * Decompiled function: FUN_00513a70
 * Entry Point: 00513a70
 * Size: 140 bytes
 */


void FUN_00513a70(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6)

{
  HPEN h;
  HGDIOBJ ho;
  LOGPEN local_10;
  
  local_10.lopnStyle = 0;
  local_10.lopnColor = arg_6 & 0xffff | 0x1000000;
  local_10.lopnWidth.x = 0;
  local_10.lopnWidth.y = 0;
  h = CreatePenIndirect(&local_10);
  ho = SelectObject(hdc,h);
  DeleteObject(ho);
  for (; arg_3 < arg_5; arg_3 = arg_3 + 1) {
    MoveToEx(hdc,arg_2,arg_3,(LPPOINT)0x0);
    LineTo(hdc,arg_4,arg_3);
  }
  return;
}



/*
 * Decompiled function: strlen
 * Entry Point: 00513afc
 * Size: 6 bytes
 */


size_t __cdecl strlen(char *str_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = strlen(str_1);
  return sVar1;
}



/*
 * Decompiled function: sprintf
 * Entry Point: 00513b02
 * Size: 6 bytes
 */


int __cdecl sprintf(char *str_1,char *str_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = sprintf(str_1,str_2);
  return iVar1;
}



/*
 * Decompiled function: abs
 * Entry Point: 00513b08
 * Size: 6 bytes
 */


int __cdecl abs(int arg_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = abs(arg_1);
  return iVar1;
}



/*
 * Decompiled function: strcat
 * Entry Point: 00513b0e
 * Size: 6 bytes
 */


char * __cdecl strcat(char *str_1,char *str_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strcat(str_1,str_2);
  return pcVar1;
}



/*
 * Decompiled function: strcpy
 * Entry Point: 00513b14
 * Size: 6 bytes
 */


char * __cdecl strcpy(char *str_1,char *str_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strcpy(str_1,str_2);
  return pcVar1;
}



/*
 * Decompiled function: strcmp
 * Entry Point: 00513b2c
 * Size: 6 bytes
 */


int __cdecl strcmp(char *str_1,char *str_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(str_1,str_2);
  return iVar1;
}



/*
 * Decompiled function: memcpy
 * Entry Point: 00513b80
 * Size: 6 bytes
 */


void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(ptr_1,ptr_2,arg_3);
  return pvVar1;
}



/*
 * Decompiled function: _vsnprintf
 * Entry Point: 00513b98
 * Size: 6 bytes
 */


int __cdecl _vsnprintf(char *str_1,size_t arg_2,char *str_3,va_list arg_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnprintf(str_1,arg_2,str_3,arg_4);
  return iVar1;
}



/*
 * Decompiled function: memset
 * Entry Point: 00513b9e
 * Size: 6 bytes
 */


void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(ptr_1,arg_2,arg_3);
  return pvVar1;
}



/*
 * Decompiled function: clock
 * Entry Point: 00513bbc
 * Size: 6 bytes
 */


clock_t __cdecl clock(void)

{
  clock_t cVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513bbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  cVar1 = clock();
  return cVar1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00513bd0
 * Entry Point: 00513bd0
 * Size: 47 bytes
 */


/* WARNING: Unable to track spacebase fully for stack */

void Mem_AllocOrFree_00513bd0(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



/*
 * Decompiled function: memcmp
 * Entry Point: 00513c00
 * Size: 6 bytes
 */


int __cdecl memcmp(void *ptr_1,void *ptr_2,size_t arg_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(ptr_1,ptr_2,arg_3);
  return iVar1;
}



/*
 * Decompiled function: __allshl
 * Entry Point: 00513c50
 * Size: 31 bytes
 */


/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(byte arg1,int arg2)

{
  uint in_EAX;
  
  if (0x3f < arg1) {
    return 0;
  }
  if (arg1 < 0x20) {
    return CONCAT44(arg2 << (arg1 & 0x1f) | in_EAX >> 0x20 - (arg1 & 0x1f),in_EAX << (arg1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (arg1 & 0x1f)) << 0x20;
}



/*
 * Decompiled function: __onexit
 * Entry Point: 00513c80
 * Size: 208 bytes
 */


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_00536d50 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_00536d50 = DAT_00536d50 + 1;
    }
    else {
      DAT_00536d50 = DAT_00536d50 + -1;
    }
  }
  if (0 < DAT_00536d50) {
    while (0 < DAT_00536d54) {
      Sleep(0);
    }
    DAT_00536d54 = DAT_00536d54 + 1;
  }
  if (DAT_0070ac9c == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_0070ac9c,&DAT_0070ac98);
  }
  if (0 < DAT_00536d50) {
    DAT_00536d54 = DAT_00536d54 + -1;
  }
  return local_c;
}



/*
 * Decompiled function: _atexit
 * Entry Point: 00513d50
 * Size: 48 bytes
 */


/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atexit(_func_4879 *ptr_1)

{
  int iVar1;
  
  iVar1 = __onexit((_onexit_t)ptr_1);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/*
 * Decompiled function: entry
 * Entry Point: 00513da0
 * Size: 510 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  HMODULE x;
  undefined4 *unaff_FS_OFFSET;
  HINSTANCE y;
  uint local_84;
  byte *local_78;
  char **local_74;
  _startupinfo local_70;
  int local_6c;
  char **local_68;
  int local_64;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005151c8;
  puStack_10 = &DAT_0051409e;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff6c;
  local_8 = 0;
  __set_app_type(2);
  DAT_0070ac98 = 0xffffffff;
  DAT_0070ac9c = 0xffffffff;
  puVar2 = (undefined4 *)__p__fmode();
  *puVar2 = DAT_00536d70;
  puVar2 = (undefined4 *)__p__commode();
  *puVar2 = DAT_00536d6c;
  _DAT_0070ac94 = *(undefined4 *)_adjust_fdiv_exref;
  __setargv();
  if (DAT_00536d68 == 0) {
    __setusermatherr(Mem_AllocOrFree_00514060);
  }
  __setdefaultprecision();
  initterm(&DAT_00516008,&DAT_0051600c);
  local_70.newmode = DAT_00536d64;
  __getmainargs(&local_64,&local_74,&local_68,DAT_00536d60,&local_70);
  initterm(&DAT_00516000,&DAT_00516004);
  puVar2 = (undefined4 *)__p__acmdln();
  local_78 = (byte *)*puVar2;
  pbVar1 = local_78;
  if (*local_78 == 0x22) {
    do {
      local_78 = pbVar1;
      pbVar1 = local_78 + 1;
      if (*pbVar1 == 0) break;
    } while (*pbVar1 != 0x22);
    if (*pbVar1 == 0x22) {
      pbVar1 = local_78 + 2;
    }
  }
  else {
    for (; pbVar1 = local_78, 0x20 < *local_78; local_78 = local_78 + 1) {
    }
  }
  while ((local_78 = pbVar1, *local_78 != 0 && (*local_78 < 0x21))) {
    pbVar1 = local_78 + 1;
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    local_84 = 10;
  }
  else {
    local_84 = local_60._48_4_ & 0xffff;
  }
  y = (HINSTANCE)0x0;
  x = GetModuleHandleA((LPCSTR)0x0);
  local_6c = WinMain(x,y,(LPSTR)local_78,local_84);
                    /* WARNING: Subroutine does not return */
  exit(local_6c);
}



/*
 * Decompiled function: _write
 * Entry Point: 00513fde
 * Size: 6 bytes
 */


int __cdecl _write(int arg_1,void *ptr_2,uint arg_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513fde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _write(arg_1,ptr_2,arg_3);
  return iVar1;
}



/*
 * Decompiled function: __dllonexit
 * Entry Point: 00514008
 * Size: 6 bytes
 */


void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00514008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}



/*
 * Decompiled function: initterm
 * Entry Point: 00514022
 * Size: 6 bytes
 */


void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00514022. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}



/*
 * Decompiled function: __setdefaultprecision
 * Entry Point: 00514030
 * Size: 29 bytes
 */


/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Debug */

void __setdefaultprecision(void)

{
  _controlfp(0x10000,0x30000);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00514060
 * Entry Point: 00514060
 * Size: 18 bytes
 */


undefined4 Mem_AllocOrFree_00514060(void)

{
  return 0;
}



/*
 * Decompiled function: __setargv
 * Entry Point: 00514080
 * Size: 11 bytes
 */


/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setargv(void)

{
  int in_EAX;
  
  return in_EAX;
}



/*
 * Decompiled function: _controlfp
 * Entry Point: 005140a4
 * Size: 6 bytes
 */


uint __cdecl _controlfp(uint arg1,uint arg2)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005140a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = _controlfp(arg1,arg2);
  return uVar1;
}



/*
 * Decompiled function: _chdir
 * Entry Point: 00514128
 * Size: 6 bytes
 */


int __cdecl _chdir(char *str_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00514128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _chdir(str_1);
  return iVar1;
}



