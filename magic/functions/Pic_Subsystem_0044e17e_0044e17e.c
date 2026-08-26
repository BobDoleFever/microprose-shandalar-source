/*
 * Decompiled function: Pic_Subsystem_0044e17e
 * Entry Point: 0044e17e
 * Size: 361 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044e17e(void)

{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_1c = 0; local_1c < 0x80; local_1c = local_1c + 1) {
    for (local_28 = 0; local_28 < *(int *)(&DAT_0067bdf0 + local_1c * 100); local_28 = local_28 + 1)
    {
      local_8 = 0;
      do {
        local_24 = 0x7fff;
        for (local_18 = 0; local_18 < 0x2a; local_18 = local_18 + 1) {
          iVar1 = FUN_0040a1d2(0x80);
          iVar2 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_1c * 100) -
                               *(int *)(&DAT_0067bdf4 + iVar1 * 100),
                               *(int *)(&DAT_0067bdf8 + local_1c * 100) -
                               *(int *)(&DAT_0067bdf8 + iVar1 * 100));
          if (iVar2 < local_24) {
            local_10 = local_c;
            local_24 = iVar2;
            local_c = iVar1;
          }
        }
        iVar1 = Pic_Subsystem_0044e2e7
                          (*(int *)(&DAT_0067bdf4 + local_1c * 100),
                           *(int *)(&DAT_0067bdf8 + local_1c * 100),
                           *(int *)(&DAT_0067bdf4 + local_10 * 100),
                           *(int *)(&DAT_0067bdf8 + local_10 * 100));
      } while ((iVar1 == 0) && (local_8 = local_8 + 1, local_8 < 3));
    }
  }
  return;
}


