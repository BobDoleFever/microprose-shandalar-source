/*
 * Decompiled function: Palette_Subsystem_004966a0
 * Entry Point: 004966a0
 * Size: 304 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004966a0(void)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
    iVar1 = Ai_Subsystem_004cbcd9(local_c);
    if (iVar1 != -1) {
      if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 1) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 1;
      }
      else if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 2) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 3;
      }
      else if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 3) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 4;
      }
      else if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 4) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 2;
      }
      else {
        (&DAT_0051aed4)[iVar1 * 0x34] = 1;
      }
    }
  }
  return 1;
}


