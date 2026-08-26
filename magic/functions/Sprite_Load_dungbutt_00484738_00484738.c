/*
 * Decompiled function: Sprite_Load_dungbutt_00484738
 * Entry Point: 00484738
 * Size: 386 bytes
 */
#include "magic.h"


void Sprite_Load_dungbutt_00484738(int arg_1,undefined4 arg_2,char *str_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *arg_6;
  undefined4 arg_4;
  char local_1fc [100];
  undefined4 local_198;
  void *local_194 [100];
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    strcpy(local_1fc,str_3);
    Sprite_LoadAll(local_194,s_dungbutt_spr_00526f90);
    arg_6 = local_194[0];
    iVar1 = Ai_Util_004c3ba3(0x10f);
    iVar1 = iVar1 / 2;
    iVar2 = Ai_Util_004c3ba3(0xc5);
    iVar2 = iVar2 / 2;
    iVar3 = Ai_Util_004c3ba3(0x34);
    iVar3 = iVar3 / 2;
    iVar4 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar4 / 2,iVar3,iVar2,iVar1,(int)arg_6);
    FUN_0050b3de(arg_1,0x7a,0x29,0x4b,0x70,1,&DAT_00526fa0);
    Mem_AllocOrFree_0050fc50(local_194[0]);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    local_198 = FUN_0040c465(local_1fc);
    arg_4 = 0;
    iVar1 = Ai_Util_004c3bc4(0x52);
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    FUN_0040c3cc(local_1fc,DAT_00522458 / 2,(iVar1 - iVar2) + -2,arg_4);
    iVar1 = Ai_Util_004c3bc4(0x52);
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    FUN_0040c3cc(local_1fc,DAT_00522458 / 2,(iVar1 - iVar2) + -3,arg_2);
    Pic_Subsystem_0044b8aa();
  }
  return;
}


