/*
 * Decompiled function: FUN_0048f31a
 * Entry Point: 0048f31a
 * Size: 475 bytes
 */
#include "duel.h"


uint FUN_0048f31a(int x,int y,int width,int height)

{
  uint uVar1;
  uint local_8;
  
  local_8 = 0;
  if (((&DAT_006827df)[y * 0x120 + x * 0x5b20] == '\0') &&
     ((&DAT_006827df)[width * 0x5b20 + height * 0x120] == '\0')) {
    uVar1 = 0;
  }
  else {
    if ((((&DAT_006826dd)[width * 0x5b20 + height * 0x120] & (&DAT_006827df)[y * 0x120 + x * 0x5b20]
         & 0x3f) != 0) &&
       ((local_8 = 1,
        (&DAT_004ff595)[*(int *)(&DAT_006826c4 + width * 0x5b20 + height * 0x120) * 0x34] == '\0' &&
        (((&DAT_006827df)[y * 0x120 + x * 0x5b20] & 0x80) == 0)))) {
      local_8 = 0;
    }
    uVar1 = local_8;
    if (((((&DAT_006827df)[width * 0x5b20 + height * 0x120] &
           (&DAT_006826dd)[y * 0x120 + x * 0x5b20] & 0x3f) != 0) &&
        (uVar1 = local_8 | 2,
        (&DAT_004ff595)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] == '\0')) &&
       (((&DAT_006827df)[width * 0x5b20 + height * 0x120] & 0x80) == 0)) {
      uVar1 = local_8;
    }
  }
  return uVar1;
}


