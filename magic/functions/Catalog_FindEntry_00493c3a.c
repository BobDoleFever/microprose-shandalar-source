/*
 * Decompiled function: Catalog_FindEntry
 * Entry Point: 00493c3a
 * Size: 124 bytes
 */
#include "magic.h"


void * Catalog_FindEntry(int arg1,byte *arg2)

{
  void *pvVar1;
  int local_8;
  
  local_8 = Catalog_ComputeFilenameHash(arg2);
  if ((*(int *)(arg1 + 0xc) == 0) || (**(int **)(arg1 + 0xc) != local_8)) {
    pvVar1 = bsearch(&local_8,*(void **)(arg1 + 8),*(size_t *)(arg1 + 4),0xc,
                     Catalog_CompareEntryHash);
    *(void **)(arg1 + 0xc) = pvVar1;
  }
  else {
    pvVar1 = *(void **)(arg1 + 0xc);
  }
  return pvVar1;
}


