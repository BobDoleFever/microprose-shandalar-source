/*
 * Decompiled function: FUN_00432ac7
 * Entry Point: 00432ac7
 * Size: 286 bytes
 */
#include "duel.h"


void FUN_00432ac7(int arg_1)

{
  int iVar1;
  
  DAT_00515ea4 = 0;
  DAT_00515e80 = 0;
  iVar1 = Mem_AllocOrFree_00432c72();
  if (iVar1 != -1) {
    if (arg_1 == -1) {
      arg_1 = 0;
    }
    if (arg_1 != -1) {
      DAT_006669e0 = arg_1;
      s_D_MAGIC0_SVE_004f4350[7] = FUN_00432860(arg_1);
      iVar1 = FUN_00432be5(s_D_MAGIC0_SVE_004f4350);
      if (iVar1 != 0) {
        if (DAT_00515ea4 == 0) {
          Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Game_has_been_saved__004f4484);
        }
        else {
          Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Game_NOT_saved__004f449c);
          Mem_AllocOrFree_0049f628(DAT_005f6c50,0x40,0x7f,0xc0,0x22,0xc);
        }
        if (DAT_00515ea4 == 0xd) {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Write_access_denied__004f44b0);
        }
        if (DAT_00515ea4 == 0x1c) {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Disk_Full__004f44c8);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Press_key_to_continue__004f44d8);
      }
    }
  }
  return;
}


