/*
 * Decompiled function: Catalog_LoadPaletteMap
 * Entry Point: 00434a43
 * Size: 596 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * Catalog_LoadPaletteMap(char *str_1,char *str_2)

{
  char local_120 [256];
  int local_20;
  int local_1c;
  FILE *local_18;
  char *local_14;
  int local_10;
  uint local_c;
  undefined2 *local_8;
  
  local_20 = 0;
  local_8 = &DAT_006c0150;
  DAT_006c0150 = 0x300;
  local_18 = _fopen(str_1,&DAT_004f5434);
  if (local_18 == (FILE *)0x0) {
    local_8 = (undefined2 *)0x0;
  }
  else {
    if (DAT_005162b4 != (int *)0x0) {
      FUN_00434fa1(DAT_005162b4);
    }
    DAT_005162b4 = (int *)FUN_00434a10();
    _fgets(local_120,0xff,local_18);
    while ((local_18->_flag & 0x10) == 0) {
      _sscanf(local_120,s__d____d__d__d_004f5438,&local_20,&local_10,&local_1c,&local_c);
      local_14 = _strchr(local_120,0x2d);
      local_14 = local_14 + 1;
      local_14 = _strchr(local_14,0x2d);
      local_14 = local_14 + 1;
      FUN_00434ec7(DAT_005162b4,local_14,local_20);
      *(uint *)(&DAT_005162d0 + local_20 * 4) = local_10 << 0x10 | local_1c << 8 | local_c;
      *(undefined1 *)(local_8 + local_20 * 2 + 2) = (undefined1)local_10;
      *(undefined1 *)((int)local_8 + local_20 * 4 + 5) = (undefined1)local_1c;
      *(undefined1 *)(local_8 + local_20 * 2 + 3) = (undefined1)local_c;
      if ((local_20 == 0) || (local_20 == 0xff)) {
        *(undefined1 *)((int)local_8 + local_20 * 4 + 7) = 0;
      }
      else {
        *(undefined1 *)((int)local_8 + local_20 * 4 + 7) = 1;
      }
      _fgets(local_120,0xff,local_18);
    }
    DAT_005166e4 = 0;
    DAT_004f4610 = 0;
    _DAT_005162c8 = FUN_00434d88(DAT_005162b4);
    DAT_004f4610 = DAT_004f4610 + -1;
    local_8[1] = 0x100;
    _fclose(local_18);
    local_18 = (FILE *)0x0;
    if (str_2 != (char *)0x0) {
      local_18 = _fopen(str_2,&DAT_004f5448);
    }
    if (local_18 != (FILE *)0x0) {
      _fread(&DAT_006c0150,0x404,1,local_18);
      _fclose(local_18);
    }
    *(undefined1 *)((int)local_8 + 0x403) = 0;
    *(undefined1 *)((int)local_8 + 7) = *(undefined1 *)((int)local_8 + 0x403);
    FUN_004350b1();
    FUN_00434c97();
  }
  return local_8;
}


