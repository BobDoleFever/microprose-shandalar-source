/*
 * Decompiled function: FUN_00446d17
 * Entry Point: 00446d17
 * Size: 139 bytes
 */
#include "duel.h"


undefined4 FUN_00446d17(void)

{
  if (DAT_0066aaf4 != 1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    FID_conflict__memcpy(&DAT_006152c0,&DAT_0068f2e0,0x1c);
    FID_conflict__memcpy(&DAT_0060cc90,&DAT_0068f300,0x1c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    SendMessageA(DAT_00618950,0x432,0,0);
    SendMessageA(DAT_00664c34,0x432,0,0);
  }
  return 0;
}


