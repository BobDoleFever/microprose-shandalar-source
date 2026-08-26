/*
 * Decompiled function: FUN_004b8bf0
 * Entry Point: 004b8bf0
 * Size: 303 bytes
 */
#include "duel.h"


undefined4 FUN_004b8bf0(void)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0; local_c < DAT_0061743c; local_c = local_c + 1) {
    iVar1 = CardTypeFromID(local_c);
    if (iVar1 != -1) {
      if (*(int *)(&DAT_00618ae4 + local_c * 0x98) == 1) {
        (&DAT_004ff5ac)[iVar1 * 0x34] = 1;
      }
      else if (*(int *)(&DAT_00618ae4 + local_c * 0x98) == 2) {
        (&DAT_004ff5ac)[iVar1 * 0x34] = 3;
      }
      else if (*(int *)(&DAT_00618ae4 + local_c * 0x98) == 3) {
        (&DAT_004ff5ac)[iVar1 * 0x34] = 4;
      }
      else if (*(int *)(&DAT_00618ae4 + local_c * 0x98) == 4) {
        (&DAT_004ff5ac)[iVar1 * 0x34] = 2;
      }
      else {
        (&DAT_004ff5ac)[iVar1 * 0x34] = 1;
      }
    }
  }
  return 1;
}


