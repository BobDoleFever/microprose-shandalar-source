/*
 * Decompiled function: FUN_0050b5be
 * Entry Point: 0050b5be
 * Size: 161 bytes
 */
#include "magic.h"


void FUN_0050b5be(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int xLeft;
  tagRECT local_14;
  
  iVar1 = Ai_Util_004c3ba3(arg_5);
  iVar2 = Ai_Util_004c3ba3(arg_3);
  iVar1 = iVar1 + iVar2;
  iVar2 = Ai_Util_004c3ba3(arg_4);
  iVar3 = Ai_Util_004c3ba3(arg_2);
  iVar2 = iVar2 + iVar3;
  iVar3 = Ai_Util_004c3ba3(arg_3);
  xLeft = Ai_Util_004c3ba3(arg_2);
  SetRect(&local_14,xLeft,iVar3,iVar2,iVar1);
  Palette_Subsystem_00496d30
            (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_14.left,
             (WPARAM *)(&DAT_006b3070 + arg_1 * 0x98),1);
  return;
}


