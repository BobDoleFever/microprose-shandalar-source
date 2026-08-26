/*
 * Decompiled function: Palette_Subsystem_004a7650
 * Entry Point: 004a7650
 * Size: 203 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a7650(int arg1,int arg2)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = arg2;
  local_10 = 0;
  g_ActivePalette = -1;
  while ((local_c < 500 && (local_10 == 0))) {
    iVar1 = *(int *)(&DAT_0069e730 + local_c * 4 + arg1 * 2000);
    if ((iVar1 != -1) &&
       (*(int *)(&DAT_006b3084 + *(int *)(&g_MasterCardTypeTable + iVar1 * 0x34) * 0x98) == 7)) {
      local_10 = *(int *)(&DAT_006b3088 + *(int *)(&g_MasterCardTypeTable + iVar1 * 0x34) * 0x98);
      g_ActivePalette = iVar1;
    }
    local_c = local_c + 1;
  }
  return local_10;
}


