/*
 * Decompiled function: Palette_Subsystem_004a610e
 * Entry Point: 004a610e
 * Size: 397 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a610e(int arg1,int arg2)

{
  int arg_1;
  undefined4 uVar1;
  int arg_1_00;
  int local_44 [10];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_44[1] = 0x4800;
  local_44[2] = 0x4900;
  local_44[3] = 0x4d00;
  local_44[4] = 0x5100;
  local_44[5] = 0x5000;
  local_44[6] = 0x4f00;
  local_44[7] = 0x4b00;
  local_44[8] = 0x4700;
  Palette_Subsystem_004a5586(arg1,arg2,local_44,&local_8);
  if ((DAT_00649900 == local_44[0]) && (DAT_00649904 == local_8)) {
    FUN_0040816b(0x1b);
    uVar1 = 0;
  }
  else {
    Palette_Subsystem_004a554b(DAT_0054bd28,DAT_0054bd2c,&local_18,&local_1c);
    local_18 = Ai_Util_004c3bc4(local_18);
    local_1c = Ai_Util_004c3bc4(local_1c);
    arg_1 = arg1 - local_18;
    arg_1_00 = local_1c - arg2;
    local_10 = abs(arg_1);
    local_14 = abs(arg_1_00);
    if ((arg_1 < 0) || (arg_1_00 < 0)) {
      if ((arg_1 < 0) || (-1 < arg_1_00)) {
        if ((arg_1 < 0) && (arg_1_00 < 0)) {
          local_c = 4;
        }
        else if ((arg_1 < 0) && (-1 < arg_1_00)) {
          local_c = 6;
        }
      }
      else {
        local_c = 2;
      }
    }
    else {
      local_c = 0;
    }
    FUN_0040816b(local_44[local_c + 2]);
    uVar1 = 1;
  }
  return uVar1;
}


