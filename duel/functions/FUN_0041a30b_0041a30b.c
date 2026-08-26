/*
 * Decompiled function: FUN_0041a30b
 * Entry Point: 0041a30b
 * Size: 546 bytes
 */
#include "duel.h"


undefined4 FUN_0041a30b(void)

{
  int iVar1;
  int arg1;
  int iVar2;
  int local_fb4;
  int aiStack_fac [1000];
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_fb4 = 0; local_fb4 < 2; local_fb4 = local_fb4 + 1) {
    local_c = 0;
    while ((local_c < 500 &&
           (aiStack_fac[local_8] = *(int *)(&DAT_006669f0 + local_c * 4 + local_fb4 * 2000),
           *(int *)(&DAT_006669f0 + local_c * 4 + local_fb4 * 2000) != -1))) {
      if (((&DAT_004ff594)[*(int *)(&DAT_006669f0 + local_c * 4 + local_fb4 * 2000) * 0x34] & 2) !=
          0) {
        local_8 = local_8 + 1;
      }
      local_c = local_c + 1;
    }
  }
  iVar1 = FUN_00439892(local_8);
  iVar1 = aiStack_fac[iVar1];
  if (iVar1 == -1) {
    DAT_00681ea4 = 1;
  }
  else {
    arg1 = FUN_00439892(2);
    local_c = Pic_Subsystem_00451291(arg1,iVar1);
    if (local_c != -1) {
      *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg1 * 0x5b20) | 0x10;
      Pic_Subsystem_0042ac1f(arg1,local_c);
      iVar2 = FUN_00439892(2);
      if ((iVar2 != 0) && (local_c = Pic_Subsystem_00451291(1 - arg1,iVar1), local_c != -1)) {
        *(uint *)(&DAT_006826f8 + local_c * 0x120 + (1 - arg1) * 0x5b20) =
             *(uint *)(&DAT_006826f8 + local_c * 0x120 + (1 - arg1) * 0x5b20) | 0x10;
        Pic_Subsystem_0042ac1f(1 - arg1,local_c);
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x28);
      }
    }
  }
  return 0;
}


