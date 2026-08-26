/*
 * Decompiled function: FUN_0050a2e0
 * Entry Point: 0050a2e0
 * Size: 241 bytes
 */
#include "magic.h"


void FUN_0050a2e0(int arg_1,int arg_2,char *str_3)

{
  int arg_5;
  int arg_4;
  int arg_3;
  int arg_2_00;
  char local_6c [100];
  undefined4 local_8;
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    strcpy(local_6c,str_3);
    arg_5 = Ai_Util_004c3ba3(0xdf);
    arg_4 = Ai_Util_004c3ba3(0x95);
    arg_3 = Ai_Util_004c3ba3(0x34);
    arg_2_00 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3,arg_4,arg_5,arg_2);
    FUN_0050b206(arg_1,0x78,0x26,1,&DAT_005323e8);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_8 = FUN_0040c465(local_6c);
    FUN_0040c3cc(local_6c,DAT_00522458 / 2,0x48,0);
    FUN_0040c3cc(local_6c,DAT_00522458 / 2,0x47,0xff);
    Pic_Subsystem_0044b8aa();
  }
  return;
}


