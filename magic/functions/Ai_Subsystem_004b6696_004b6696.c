/*
 * Decompiled function: Ai_Subsystem_004b6696
 * Entry Point: 004b6696
 * Size: 168 bytes
 */
#include "magic.h"


bool Ai_Subsystem_004b6696(int arg1,int arg2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    iVar1 = Ai_Subsystem_004b5c4b(arg1,arg2);
    if (iVar1 == -1) {
      bVar2 = false;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      bVar2 = ((&DAT_0068a768)[arg2 * 0x120 + arg1 * 0x5b20] & 6) != 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


