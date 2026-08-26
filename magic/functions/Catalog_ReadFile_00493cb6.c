/*
 * Decompiled function: Catalog_ReadFile
 * Entry Point: 00493cb6
 * Size: 172 bytes
 */
#include "magic.h"


size_t Catalog_ReadFile(int arg_1,undefined4 arg_2,int *arg_3)

{
  undefined4 *arg1;
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  
  arg1 = (undefined4 *)(&DAT_00676620 + (arg_1 + -1) * 0x114);
  iVar1 = Catalog_FindEntry((int)arg1,arg_2);
  if (iVar1 == 0) {
    sVar2 = 0xffffffff;
  }
  else {
    if (*arg_3 == 0) {
      pvVar3 = malloc(*(int *)(iVar1 + 8) + 0x10);
      *arg_3 = (int)pvVar3;
    }
    fseek((FILE *)*arg1,*(long *)(iVar1 + 4),0);
    sVar2 = fread((void *)*arg_3,1,*(size_t *)(iVar1 + 8),(FILE *)*arg1);
  }
  return sVar2;
}


