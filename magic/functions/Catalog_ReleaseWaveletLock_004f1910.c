/*
 * Decompiled function: Catalog_ReleaseWaveletLock
 * Entry Point: 004f1910
 * Size: 14 bytes
 */
#include "magic.h"


undefined4 Catalog_ReleaseWaveletLock(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
  return 0;
}


