/*
 * Decompiled function: Catalog_CompareEntryHash
 * Entry Point: 00493bea
 * Size: 70 bytes
 */
#include "magic.h"


undefined4 Catalog_CompareEntryHash(int *arg1,int *arg2)

{
  undefined4 uVar1;
  
  if (*arg2 < *arg1) {
    uVar1 = 1;
  }
  else if (*arg1 < *arg2) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


