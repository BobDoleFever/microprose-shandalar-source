/*
 * Decompiled function: FUN_0044c1e0
 * Entry Point: 0044c1e0
 * Size: 535 bytes
 */
#include "duel.h"


undefined1 * FUN_0044c1e0(char *str_1,undefined1 *arg_2,void *arg_3)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  HGLOBAL pvVar4;
  uint uVar5;
  int local_18;
  int local_14;
  int local_8;
  
  DAT_00694430 = _fopen(str_1,&DAT_004f817c);
  Assert_Handler_00499950
            ((uint)(DAT_00694430 != (FILE *)0x0),
             (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x69,
             s_Error_Opening_File__s_004f8164);
  DAT_00694438 = str_1;
  FUN_0044c47a(arg_3);
  if ((DAT_00694443 == '\b') && (DAT_00694481 == '\x01')) {
    local_18 = 1;
  }
  else {
    local_18 = 0;
  }
  Assert_Handler_00499950
            (local_18,(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x6f,
             s__s_Not_a_256_color_palettized_pc_004f8180);
  uVar2 = 4 - (DAT_004ff154 & 3);
  uVar5 = (int)uVar2 >> 0x1f;
  iVar3 = ((uVar2 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5;
  if ((DAT_004f8138 == DAT_004ff154) && (DAT_004f813c == DAT_004ff158)) {
    _memset(arg_2,0,(DAT_004f8138 + iVar3) * DAT_004f813c);
  }
  else {
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalFree(pvVar4);
    pvVar4 = GlobalAlloc(0x40,(iVar3 + DAT_004ff154) * DAT_004ff158);
    arg_2 = GlobalLock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalLock(pvVar4);
    DAT_004f8138 = DAT_004ff154;
    DAT_004f813c = DAT_004ff158;
  }
  puVar1 = arg_2;
  for (local_8 = 0; local_8 < DAT_004ff158; local_8 = local_8 + 1) {
    FUN_0044c660(&DAT_00693430);
    for (local_14 = 0; local_14 < (int)DAT_004ff154; local_14 = local_14 + 1) {
      *arg_2 = (&DAT_00693430)[local_14];
      arg_2 = arg_2 + 1;
    }
    arg_2 = arg_2 + iVar3;
  }
  _fclose(DAT_00694430);
  return puVar1;
}


