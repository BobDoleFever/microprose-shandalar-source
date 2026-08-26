/*
 * Decompiled function: FUN_004fdad2
 * Entry Point: 004fdad2
 * Size: 334 bytes
 */
#include "magic.h"


int FUN_004fdad2(int arg_1,int arg_2,uint arg_3)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = -99;
  local_10 = -1;
  if (arg_2 == -1) {
    local_10 = -1;
  }
  else {
    local_18 = 0;
    while ((local_18 < 500 && (*(int *)(&DAT_0069e730 + local_18 * 4 + arg_2 * 2000) != -1))) {
      iVar1 = *(int *)(&DAT_0069e730 + local_18 * 4 + arg_2 * 2000);
      if ((arg_3 == 0xffffffff) || ((arg_3 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0)) {
        local_8 = abs((int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
        local_8 = local_8 + (char)(&DAT_0051aebf)[iVar1 * 0x34] * 2;
        if (*(int *)(&DAT_0063ee4c + arg_1 * 0x20) < local_8) {
          local_8 = -local_8;
        }
        if (local_8 == 0) {
          local_8 = 99;
        }
        iVar1 = Pic_Subsystem_00452551(iVar1);
        local_8 = local_8 + iVar1 * 2;
        if (local_14 < local_8) {
          local_10 = local_18;
          local_14 = local_8;
        }
      }
      local_18 = local_18 + 1;
    }
  }
  return local_10;
}


