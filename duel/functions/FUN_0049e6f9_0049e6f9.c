/*
 * Decompiled function: FUN_0049e6f9
 * Entry Point: 0049e6f9
 * Size: 270 bytes
 */
#include "duel.h"


void FUN_0049e6f9(void)

{
  int iVar1;
  int iVar2;
  int local_58;
  int aiStack_54 [20];
  
  if ((DAT_005f649c != 0) && (DAT_005f6288 != 0)) {
    for (local_58 = 0; local_58 < DAT_005f649c; local_58 = local_58 + 1) {
      aiStack_54[local_58] = local_58;
    }
    for (local_58 = 0; local_58 < DAT_005f649c * 10; local_58 = local_58 + 1) {
      iVar2 = _rand();
      iVar1 = aiStack_54[local_58 % DAT_005f649c];
      aiStack_54[local_58 % DAT_005f649c] = aiStack_54[iVar2 % DAT_005f649c];
      aiStack_54[iVar2 % DAT_005f649c] = iVar1;
    }
    for (local_58 = 0; local_58 < DAT_005f649c; local_58 = local_58 + 1) {
      Mem_AllocOrFree_004d9630
                ((uint *)(&DAT_005f6cc0 + local_58 * 0x80),
                 (uint *)(&DAT_005f2fb0 + aiStack_54[local_58] * 0x80));
    }
  }
  return;
}


