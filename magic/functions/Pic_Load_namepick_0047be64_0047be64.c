/*
 * Decompiled function: Pic_Load_namepick_0047be64
 * Entry Point: 0047be64
 * Size: 540 bytes
 */
#include "magic.h"


void Pic_Load_namepick_0047be64(char *filepath)

{
  int iVar1;
  uint arg_2;
  int iVar2;
  int iVar3;
  int iVar4;
  char *str_5;
  
  Mem_AllocOrFree_00510de0(1,s_namepick_pic_00526af8);
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) =
       *(undefined4 *)(g_DisplaySurfaceScreen + 0x20);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xed,0x8b,0x19);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x18);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,0x114,0x6a,(int *)g_DisplaySurfaceBackBuffer,0,
               200);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x100);
  iVar1 = Ai_Util_004c3bc4(0xbc);
  FUN_0047bcf1((undefined4 *)g_DisplaySurfaceBackBuffer,0,200,0x114,0x6a,
               (undefined4 *)g_DisplaySurfaceScreen,(DAT_00522458 + -0x114) / 2,iVar1);
  while( true ) {
    arg_2 = FUN_004080b2();
    if (arg_2 == 0x1c0d) break;
    iVar1 = FUN_0050f440((int *)g_DisplaySurfaceBackBuffer,filepath);
    if (arg_2 != 0) {
      FUN_0047c360(filepath,arg_2,0x19);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,0x114,0x6a,
                   (int *)g_DisplaySurfaceBackBuffer,0,200);
      FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x100);
      iVar2 = Ai_Util_004c3bc4(0xbc);
      FUN_0047bcf1((undefined4 *)g_DisplaySurfaceBackBuffer,0,200,0x114,0x6a,
                   (undefined4 *)g_DisplaySurfaceScreen,(DAT_00522458 + -0x114) / 2,iVar2);
    }
    str_5 = filepath;
    iVar2 = DAT_00676dc8;
    iVar3 = Ai_Util_004c3bc4(0xbc);
    iVar3 = iVar3 + 0x30;
    iVar4 = Ai_Util_004c3bc4(0x140);
    FUN_0041fec7((int)g_DisplaySurfaceScreen,0xb4,iVar4 - iVar1 / 2,iVar3,str_5,iVar2);
  }
  Ai_Subsystem_004cd1d1();
  return;
}


