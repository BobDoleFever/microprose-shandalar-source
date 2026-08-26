/*
 * Decompiled function: Ai_Subsystem_004be192
 * Entry Point: 004be192
 * Size: 169 bytes
 */
#include "magic.h"


int Ai_Subsystem_004be192(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
  DAT_006b2d40 = DAT_006b2d40 + *(int *)(&DAT_006330d0 + iVar1 * 4);
  iVar2 = Ai_CalcManaRequirement_004ba890(x,width,height);
  iVar1 = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
  iVar2 = iVar2 - *(int *)(&DAT_006330d0 + iVar1 * 4);
  if (g_ActivePlayer == 1) {
    iVar2 = 0;
  }
  return iVar2;
}


