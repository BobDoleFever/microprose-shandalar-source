/*
 * Decompiled function: InitVid
 * Entry Point: 100012a3
 * Size: 5 bytes
 */
#include "magvid.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t InitVid(void)

{
                    /* 0x12a3  1  InitVid */
  if (DAT_10010530 == 0) {
    _DAT_10010878 = 3;
    _DAT_1001087c = &LAB_100010be;
    _DAT_10010880 = 0;
    _DAT_10010884 = 0;
    DAT_10010888 = DAT_1001054c;
    _DAT_1001088c = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10010890 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10010894 = 0;
    _DAT_10010898 = 0;
    _DAT_1001089c = PTR_s_VIDWINCLASS_10010534;
    RegisterClassA((WNDCLASSA *)&DAT_10010878);
  }
  thunk_FUN_10004c90(0,0,3);
  DAT_10010530 = DAT_10010530 + 1;
  return 0;
}


