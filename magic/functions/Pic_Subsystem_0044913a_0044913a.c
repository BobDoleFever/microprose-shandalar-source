/*
 * Decompiled function: Pic_Subsystem_0044913a
 * Entry Point: 0044913a
 * Size: 233 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044913a(int arg1,int arg2)

{
  int iVar1;
  int local_10;
  uint local_c;
  
  iVar1 = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20);
  local_c = (uint)(((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
  *(uint *)(&DAT_00695e00 + local_c * 4) =
       *(uint *)(&DAT_00695e00 + local_c * 4) | (uint)(byte)(&g_MasterCardColorTable)[iVar1 * 0x34];
  local_10 = 0;
  while( true ) {
    if (499 < local_10) {
      return;
    }
    if (*(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) == -1) break;
    local_10 = local_10 + 1;
  }
  *(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) = iVar1;
  return;
}


