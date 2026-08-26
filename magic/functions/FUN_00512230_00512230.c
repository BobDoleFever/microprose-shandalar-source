/*
 * Decompiled function: FUN_00512230
 * Entry Point: 00512230
 * Size: 608 bytes
 */
#include "magic.h"


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


