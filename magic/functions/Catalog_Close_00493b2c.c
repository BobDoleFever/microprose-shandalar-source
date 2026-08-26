/*
 * Decompiled function: Catalog_Close
 * Entry Point: 00493b2c
 * Size: 190 bytes
 */
#include "magic.h"


bool Catalog_Close(int arg_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = arg_1 + -1;
  iVar2 = *(int *)(&DAT_00676620 + iVar1 * 0x114);
  if (iVar2 != 0) {
    free(*(void **)(&DAT_00676628 + iVar1 * 0x114));
    fclose(*(FILE **)(&DAT_00676620 + iVar1 * 0x114));
    *(undefined4 *)(&DAT_00676628 + iVar1 * 0x114) = 0;
    *(undefined4 *)(&DAT_00676620 + iVar1 * 0x114) = 0;
    *(undefined4 *)(&DAT_00676624 + iVar1 * 0x114) = 0;
  }
  return iVar2 != 0;
}


