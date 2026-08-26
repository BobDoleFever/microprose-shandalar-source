/*
 * Decompiled function: UI_CreateWindow_00440f22
 * Entry Point: 00440f22
 * Size: 445 bytes
 */
#include "duel.h"


INT_PTR UI_CreateWindow_00440f22
                  (int *arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5,uint *arg_6)

{
  INT_PTR IVar1;
  undefined4 uVar2;
  undefined4 local_690;
  undefined4 auStack_68c [200];
  undefined4 auStack_36c [200];
  int local_4c;
  uint local_48;
  int local_44;
  uint local_40 [3];
  int local_34;
  WNDCLASSA local_30;
  
  if (((arg_3 < 1) || (arg_1 == (int *)0x0)) || (*arg_1 == -1)) {
    IVar1 = -1;
  }
  else {
    local_30.style = 0;
    local_30.lpfnWndProc = UI_WndProc_0044233e;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0xc;
    local_30.hInstance = DAT_00664680;
    local_30.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hbrBackground = (HBRUSH)0x6;
    local_30.lpszMenuName = (LPCSTR)0x0;
    local_30.lpszClassName = s_ShowListCard_004f7d00;
    RegisterClassA(&local_30);
    local_690 = arg_4;
    for (local_34 = 0; (local_34 < arg_3 && (arg_1[local_34] != -1)); local_34 = local_34 + 1) {
      uVar2 = CardIDFromType(arg_1[local_34] & 0xfff);
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
      Mem_AllocOrFree_004d9630(local_40,arg_6);
    }
    else {
      Mem_AllocOrFree_004d9630(local_40,(uint *)&DAT_004f7d10);
    }
    IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe9,DAT_00618990,UI_CreateWindow_004410df,
                            (LPARAM)&local_690);
  }
  return IVar1;
}


