/*
 * Decompiled function: Adventure_PromptLocationMenu
 * Entry Point: 004e7936
 * Size: 276 bytes
 */
#include "magic.h"


void Adventure_PromptLocationMenu(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 arg_2;
  
  uVar1 = *(undefined4 *)(g_DisplaySurfaceScreen + 0x20);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  uVar2 = Ai_Util_004c3bc4(0x40);
  arg_2 = Ai_Util_004c3bc4(0x50);
  uVar2 = FUN_00489710(s_Will_you_____Save_Quit_See_Edit_D_0052f118,arg_2,uVar2);
  switch(uVar2) {
  case 0:
    FUN_0040816b(0x53);
    break;
  case 1:
    FUN_0040816b(0x51);
    break;
  case 2:
    FUN_0040816b(0x3b00);
    break;
  case 3:
    FUN_0040816b(0x3c00);
    break;
  case 4:
    FUN_0040816b(0x3d00);
    break;
  case 5:
    FUN_0040816b(0x3e00);
    break;
  case 6:
    FUN_0040816b(0x3f00);
    break;
  case 7:
    FUN_0040816b(0x4000);
    break;
  default:
    Ai_Subsystem_004c05ba();
  }
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = uVar1;
  return;
}


