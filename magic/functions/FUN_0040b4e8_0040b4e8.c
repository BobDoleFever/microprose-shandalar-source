/*
 * Decompiled function: FUN_0040b4e8
 * Entry Point: 0040b4e8
 * Size: 771 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b4e8(void)

{
  int iVar1;
  int iVar2;
  int local_1c;
  
  Ai_CastleEncounter_004c24b3(4);
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  DAT_005384e0 = 0xffffffff;
  DAT_005384dc = 0xffffffff;
  for (local_1c = 0; (local_1c < 10000 && (*(int *)(&DAT_0067a9a0 + local_1c * 0x10) != 0));
      local_1c = local_1c + 1) {
  }
  DAT_005384d8 = local_1c;
  _DAT_00517284 = local_1c;
  DAT_005384d4 = -1;
  FUN_0040b441((int *)&DAT_00517200,3);
  iVar1 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar1);
  _DAT_005172e8 = 3;
  FUN_0041f17e(0x517200,3,iVar1);
  DAT_00680770 = 1;
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  FUN_0040ae70(0x517200,0);
  FUN_0040b2c8(0x517254);
  DAT_00680770 = 0;
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  Castle_Process_0040b7fa(0);
  do {
    Mem_AllocOrFree_005016f9();
    DAT_005384d0 = -1;
    while (DAT_005384d0 == -1) {
      iVar1 = Mem_AllocOrFree_00501721();
      iVar2 = Mem_AllocOrFree_00501721();
      if (iVar2 % 10 == 0 && iVar1 % 0x14 == 0) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_005384c8 + -2,DAT_005384cc + -2,5,5,0xff)
        ;
      }
      iVar1 = Mem_AllocOrFree_00501721();
      iVar2 = Mem_AllocOrFree_00501721();
      if ((iVar2 % 0x14 & (uint)(iVar1 % 10 == 0)) != 0) {
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,DAT_005384c8 - 2,DAT_005384cc + -2,5,5,
                     (int *)g_DisplaySurfaceScreen,DAT_005384c8,DAT_005384cc);
      }
      Pic_Subsystem_0044b84b();
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
      if ((DAT_005384d0 == -1) &&
         ((DAT_007039c4 != 0 || (iVar1 = Mem_AllocOrFree_0040810f(), iVar1 == 0)))) {
        iVar1 = FUN_004080b2();
        if (((DAT_007039c4 & 1) == 0) && (iVar1 != 0x5000)) {
          if (((DAT_007039c4 & 2) != 0) || (iVar1 == 0x4800)) {
            Castle_Process_0040b7fa(DAT_005384d4 + -1);
          }
        }
        else {
          Castle_Process_0040b7fa(DAT_005384d4 + 1);
        }
        FUN_0040a3e1();
      }
    }
  } while (DAT_005384d0 == 1);
  if (DAT_005384d0 == 4) {
    FUN_0040a3e1();
    FUN_0041f391();
    Mem_AllocOrFree_0050fc50(DAT_00641890);
  }
  return;
}


