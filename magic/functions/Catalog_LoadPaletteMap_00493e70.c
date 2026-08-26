/*
 * Decompiled function: Catalog_LoadPaletteMap
 * Entry Point: 00493e70
 * Size: 519 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * Catalog_LoadPaletteMap(char *str_1,char *str_2)

{
  uint uVar1;
  FILE *_File;
  char *pcVar2;
  FILE *_File_00;
  int local_110;
  int local_10c;
  int local_108;
  uint local_104;
  char local_100 [256];
  
  local_110 = 0;
  _DAT_00675ac0 = 0x300;
  _File = fopen(str_1,&DAT_0052afd8);
  if (_File == (FILE *)0x0) {
    return (undefined *)0x0;
  }
  if (DAT_0054aefc != (int *)0x0) {
    ColorOctree_FreeTree(DAT_0054aefc);
  }
  DAT_0054aefc = (int *)ColorOctree_AllocNode();
  fgets(local_100,0xff,_File);
  uVar1 = _File->_flag;
  while ((uVar1 & 0x10) == 0) {
    sscanf(local_100,s__d____d__d__d_0052afc8,&local_110,&local_10c,&local_108,&local_104);
    pcVar2 = strchr(local_100,0x2d);
    pcVar2 = strchr(pcVar2 + 1,0x2d);
    ColorOctree_InsertColor(DAT_0054aefc,pcVar2 + 1,local_110);
    *(uint *)(&DAT_0054af18 + local_110 * 4) = local_108 << 8 | local_10c << 0x10 | local_104;
    (&DAT_00675ac4)[local_110 * 4] = (undefined1)local_10c;
    (&DAT_00675ac5)[local_110 * 4] = (undefined1)local_108;
    (&DAT_00675ac6)[local_110 * 4] = (undefined1)local_104;
    if ((local_110 == 0) || (local_110 == 0xff)) {
      (&DAT_00675ac7)[local_110 * 4] = 0;
    }
    else {
      (&DAT_00675ac7)[local_110 * 4] = 1;
    }
    fgets(local_100,0xff,_File);
    uVar1 = _File->_flag;
  }
  _File_00 = (FILE *)0x0;
  DAT_0054b32c = 0;
  DAT_0052a1a0 = 0;
  _DAT_0054af10 = ColorOctree_BuildClusters(DAT_0054aefc);
  DAT_0052a1a0 = DAT_0052a1a0 + -1;
  _DAT_00675ac2 = 0x100;
  fclose(_File);
  if (str_2 != (char *)0x0) {
    _File_00 = fopen(str_2,&DAT_0052afc4);
  }
  if (_File_00 != (FILE *)0x0) {
    fread(&DAT_00675ac0,0x404,1,_File_00);
    fclose(_File_00);
  }
  DAT_00675ec3 = 0;
  DAT_00675ac7 = 0;
  Palette_BuildFastColorLookup();
  Palette_InitSquareDistanceTable();
  return &DAT_00675ac0;
}


