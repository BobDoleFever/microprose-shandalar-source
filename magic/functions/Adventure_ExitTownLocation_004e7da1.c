/*
 * Decompiled function: Adventure_ExitTownLocation
 * Entry Point: 004e7da1
 * Size: 326 bytes
 */
#include "magic.h"


void Adventure_ExitTownLocation(void)

{
  int local_8;
  
  local_8 = -1;
  switch(DAT_00640f08) {
  case 1:
    FUN_0040816b(0x3b00);
    break;
  case 2:
    FUN_0040816b(0x3c00);
    break;
  case 3:
    FUN_0040816b(0x3d00);
    break;
  case 4:
    FUN_0040816b(0x3e00);
    break;
  case 5:
    FUN_0040816b(0x3f00);
    break;
  case 6:
    FUN_0040816b(0x4000);
    break;
  default:
    Pic_Subsystem_0044b84b();
    if (DAT_0067bda0 != 0) {
      local_8 = Adventure_HandleLocationMenuChoice(DAT_0067bda4,DAT_0067bda8);
    }
    if (local_8 != -1) {
      FUN_0040816b(local_8);
    }
    break;
  case 0x31:
    FUN_0040816b(0x31);
    break;
  case 0x32:
    FUN_0040816b(0x32);
    break;
  case 0x33:
    FUN_0040816b(0x33);
    break;
  case 0x34:
    FUN_0040816b(0x34);
    break;
  case 0x35:
    FUN_0040816b(0x35);
  }
  DAT_00640f08 = 0;
  return;
}


