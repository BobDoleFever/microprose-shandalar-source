/*
 * Decompiled function: FUN_10002986
 * Entry Point: 10002986
 * Size: 73 bytes
 */
#include "magvid.h"


int32_t FUN_10002986(void)

{
  if ((DAT_10010530 != 0) && (DAT_10010530 = DAT_10010530 + -1, DAT_10010530 == 0)) {
    UnregisterClassA(PTR_s_VIDWINCLASS_10010534,DAT_10010888);
    thunk_FUN_10004def();
  }
  return 0;
}


