/*
 * Decompiled function: FUN_00440f22
 * Entry Point: 00440f22
 * Size: 445 bytes
 */
#include "duel.h"


INT_PTR FUN_00440f22(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                    undefined4 param_6)

{
  INT_PTR IVar1;
  undefined4 uVar2;
  undefined4 local_690;
  undefined4 auStack_68c [200];
  undefined4 auStack_36c [200];
  int local_4c;
  uint local_48;
  int local_44;
  undefined1 local_40 [12];
  int local_34;
  WNDCLASSA local_30;
  
  if (((param_3 < 1) || (param_1 == (int *)0x0)) || (*param_1 == -1)) {
    IVar1 = -1;
  }
  else {
    local_30.style = 0;
    local_30.lpfnWndProc = FUN_0044233e;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0xc;
    local_30.hInstance = DAT_00664680;
    local_30.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hbrBackground = (HBRUSH)0x6;
    local_30.lpszMenuName = (LPCSTR)0x0;
    local_30.lpszClassName = s_ShowListCard_004f7d00;
    RegisterClassA(&local_30);
    local_690 = param_4;
    for (local_34 = 0; (local_34 < param_3 && (param_1[local_34] != -1)); local_34 = local_34 + 1) {
      uVar2 = CardIDFromType(param_1[local_34] & 0xfff);
      auStack_68c[local_34] = uVar2;
    }
    local_4c = local_34;
    local_48 = (uint)(param_2 != 0);
    if (local_48 != 0) {
      for (local_34 = 0; local_34 < local_4c; local_34 = local_34 + 1) {
        auStack_36c[local_34] = *(undefined4 *)(param_2 + local_34 * 4);
      }
    }
    local_44 = param_5;
    if (param_5 == 0) {
      FUN_004d9630(local_40,param_6);
    }
    else {
      FUN_004d9630(local_40,&DAT_004f7d10);
    }
    IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe9,DAT_00618990,FUN_004410df,(LPARAM)&local_690);
  }
  return IVar1;
}


