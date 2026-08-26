/*
 * Decompiled function: FUN_00476c77
 * Entry Point: 00476c77
 * Size: 475 bytes
 */
#include "magic.h"


uint FUN_00476c77(int x,int y,int width,int height)

{
  uint uVar1;
  uint local_8;
  
  local_8 = 0;
  if (((&DAT_006a604f)[y * 0x120 + x * 0x5b20] == '\0') &&
     ((&DAT_006a604f)[height * 0x120 + width * 0x5b20] == '\0')) {
    uVar1 = 0;
  }
  else {
    if ((((&DAT_006a604f)[y * 0x120 + x * 0x5b20] & (&DAT_006a5f4d)[height * 0x120 + width * 0x5b20]
         & 0x3f) != 0) &&
       ((local_8 = 1,
        (&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20) * 0x34] ==
        '\0' && (((&DAT_006a604f)[y * 0x120 + x * 0x5b20] & 0x80) == 0)))) {
      local_8 = 0;
    }
    uVar1 = local_8;
    if (((((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20] &
           (&DAT_006a604f)[height * 0x120 + width * 0x5b20] & 0x3f) != 0) &&
        (uVar1 = local_8 | 2,
        (&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] == '\0')) &&
       (((&DAT_006a604f)[height * 0x120 + width * 0x5b20] & 0x80) == 0)) {
      uVar1 = local_8;
    }
  }
  return uVar1;
}


