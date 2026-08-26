/*
 * Decompiled function: Ai_Subsystem_004b7d38
 * Entry Point: 004b7d38
 * Size: 176 bytes
 */
#include "magic.h"


int Ai_Subsystem_004b7d38(char *str_1)

{
  uint uVar1;
  uint uVar2;
  char local_70 [100];
  int local_c;
  INT_PTR local_8;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  uVar1 = rand();
  uVar2 = (int)uVar1 >> 0x1f;
  local_c = ((uVar1 ^ uVar2) - uVar2 & 1 ^ uVar2) - uVar2;
  if (g_IsAiThinking != 1) {
    strcpy(local_70,str_1);
    local_8 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf0,g_MainAppHwnd,Ai_Subsystem_004b7de8,
                              (LPARAM)local_70);
    InvalidateRect(DAT_006a4924,(RECT *)0x0,1);
    InvalidateRect(DAT_006b2e2c,(RECT *)0x0,1);
    Pic_Subsystem_00423c82(0x2f);
  }
  return local_c;
}


