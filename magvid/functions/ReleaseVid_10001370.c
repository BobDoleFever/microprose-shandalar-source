/*
 * Decompiled function: ReleaseVid
 * Entry Point: 10001370
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t ReleaseVid(void)

{
                    /* 0x1370  2  ReleaseVid */
  if ((DAT_10010530 != 0) && (DAT_10010530 = DAT_10010530 + -1, DAT_10010530 == 0)) {
    UnregisterClassA(PTR_s_VIDWINCLASS_10010534,DAT_10010888);
    thunk_FUN_10004def();
  }
  return 0;
}


