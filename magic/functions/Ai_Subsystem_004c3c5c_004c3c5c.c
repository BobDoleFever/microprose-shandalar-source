/*
 * Decompiled function: Ai_Subsystem_004c3c5c
 * Entry Point: 004c3c5c
 * Size: 1459 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c3c5c(int arg_1)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  uint arg_2;
  int *piVar4;
  int iVar5;
  int arg_8;
  uint local_20;
  
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  arg_8 = 0;
  iVar5 = 0;
  piVar4 = (int *)g_DisplaySurfaceBackBuffer;
  DVar1 = Ai_Util_004c3bc4(0x15);
  uVar2 = Ai_Util_004c3bc4(0x126);
  iVar3 = Ai_Util_004c3bc4(0x13);
  arg_2 = Ai_Util_004c3bc4(0x58);
  FUN_0050dce0((int *)PTR_DAT_005174bc,arg_2,iVar3,uVar2,DVar1,piVar4,iVar5,arg_8);
  iVar3 = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0x12);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,DAT_0052d770,iVar5,iVar3);
  iVar3 = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0x60);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,DAT_0052d770,iVar5,iVar3);
  Minit_Subsystem_00452827();
  iVar3 = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0xab);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,DAT_0052d770,iVar5,iVar3);
  iVar3 = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0x10c);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,DAT_0052d770,iVar5,iVar3);
  iVar3 = Ai_Util_004c3bc4(0x15b);
  iVar5 = Ai_Util_004c3bc4(0x58);
  piVar4 = (int *)g_DisplaySurfaceScreen;
  DVar1 = Ai_Util_004c3bc4(0x15);
  uVar2 = Ai_Util_004c3bc4(0x126);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,uVar2,DVar1,piVar4,iVar5,iVar3);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 2;
  Ai_CalcManaRequirement_004bf4b3(1);
  iVar3 = DAT_006776a0;
  if ((DAT_0052d778 == 0) && (arg_1 == 0)) {
    Pic_Subsystem_0044b8aa();
  }
  else {
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    iVar5 = 400 - (int)*(short *)(iVar3 + 6) / 2;
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0x4e,iVar5,DAT_006776a8,(int)*(short *)(iVar3 + 4),
               (int)*(short *)(iVar3 + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,DAT_0052d770,100,iVar5 + (int)*(short *)(iVar3 + 6) / 2
                );
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0xa1,iVar5,DAT_006776a4,(int)*(short *)(iVar3 + 4),
               (int)*(short *)(iVar3 + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,DAT_0052d770,0xb7,
                 iVar5 + (int)*(short *)(iVar3 + 6) / 2);
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0xf0,iVar5,DAT_006776b0,(int)*(short *)(iVar3 + 4),
               (int)*(short *)(iVar3 + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,DAT_0052d770,0x106,
                 iVar5 + (int)*(short *)(iVar3 + 6) / 2);
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0x140,iVar5,DAT_006776ac,(int)*(short *)(iVar3 + 4),
               (int)*(short *)(iVar3 + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,DAT_0052d770,0x156,
                 iVar5 + (int)*(short *)(iVar3 + 6) / 2);
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0x193,iVar5,DAT_006776a0,(int)*(short *)(iVar3 + 4),
               (int)*(short *)(iVar3 + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,DAT_0052d770,0x1a9,
                 iVar5 + (int)*(short *)(iVar3 + 6) / 2);
    for (local_20 = 0; (int)local_20 < 0xc; local_20 = local_20 + 1) {
      if ((_DAT_0067f374 & 1 << ((byte)local_20 & 0x1f)) != 0) {
        Bazaar_GetCardBaseValue(local_20);
        if (((int)local_20 < 2) || ((local_20 & 1) != 0)) {
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(undefined4 *)(&DAT_006782a0 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
        }
        else if (*(int *)(&DAT_0067bdbc + ((int)local_20 / 2) * 4) == 0) {
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(undefined4 *)(&DAT_00678300 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
        }
        else {
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(undefined4 *)(&DAT_006782a0 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(undefined4 *)(&DAT_00678330 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
        }
      }
    }
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  }
  return;
}


