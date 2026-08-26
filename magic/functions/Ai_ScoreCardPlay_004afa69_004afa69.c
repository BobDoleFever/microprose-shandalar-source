/*
 * Decompiled function: Ai_ScoreCardPlay_004afa69
 * Entry Point: 004afa69
 * Size: 445 bytes
 */
#include "magic.h"


INT_PTR Ai_ScoreCardPlay_004afa69
                  (int *arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5,char *str_6)

{
  INT_PTR IVar1;
  undefined4 uVar2;
  undefined4 local_690;
  undefined4 auStack_68c [200];
  undefined4 auStack_36c [200];
  int local_4c;
  uint local_48;
  int local_44;
  char local_40 [12];
  int local_34;
  WNDCLASSA local_30;
  
  if (((arg_3 < 1) || (arg_1 == (int *)0x0)) || (*arg_1 == -1)) {
    IVar1 = -1;
  }
  else {
    local_30.style = 0;
    local_30.lpfnWndProc = Ai_Subsystem_004b0e80;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0xc;
    local_30.hInstance = g_AppHInstance;
    local_30.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hbrBackground = (HBRUSH)0x6;
    local_30.lpszMenuName = (LPCSTR)0x0;
    local_30.lpszClassName = s_ShowListCard_0052d1e0;
    RegisterClassA(&local_30);
    local_690 = arg_4;
    for (local_34 = 0; (local_34 < arg_3 && (arg_1[local_34] != -1)); local_34 = local_34 + 1) {
      uVar2 = Ai_Subsystem_004cbd67(arg_1[local_34] & 0xfff);
      auStack_68c[local_34] = uVar2;
    }
    local_4c = local_34;
    local_48 = (uint)(arg_2 != 0);
    if (local_48 != 0) {
      for (local_34 = 0; local_34 < local_4c; local_34 = local_34 + 1) {
        auStack_36c[local_34] = *(undefined4 *)(arg_2 + local_34 * 4);
      }
    }
    local_44 = arg_5;
    if (arg_5 == 0) {
      strcpy(local_40,str_6);
    }
    else {
      strcpy(local_40,&DAT_0052d1f0);
    }
    IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe9,g_MainAppHwnd,Ai_ScoreCardPlay_004afc26,
                            (LPARAM)&local_690);
  }
  return IVar1;
}


