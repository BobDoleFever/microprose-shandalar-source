/*
 * Decompiled function: FUN_0049918f
 * Entry Point: 0049918f
 * Size: 861 bytes
 */
#include "duel.h"


LRESULT FUN_0049918f(HWND param_1,uint param_2,HDC param_3,uint param_4)

{
  HBRUSH hbr;
  LRESULT LVar1;
  int local_13c;
  tagPOINT local_138;
  tagRECT local_130;
  undefined1 local_120 [264];
  HDC local_18;
  tagRECT local_14;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_18 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_14);
      IntersectClipRect(local_18,0,0,local_14.right,local_14.bottom);
      if (DAT_005dc2f8 == 0) {
        FUN_004d9630(local_120,&DAT_006189a0);
        FUN_004d9640(local_120,s__WINBK_AttackMin_pic_00505740);
        DAT_005dc2f8 = FUN_0043d713(local_120);
      }
      if (DAT_005dc2f8 == 0) {
        hbr = GetStockObject(4);
        FillRect(local_18,&local_14,hbr);
      }
      else {
        FUN_004709ae(local_18,&local_14,DAT_005dc2f8);
      }
      return 1;
    }
    if (param_2 == 0x10) {
      ShowWindow(param_1,0);
      ShowWindow(DAT_00618ab0,0);
      return 0;
    }
  }
  else if (param_2 < 0x120) {
    if (param_2 == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
        local_13c = GetMenuItemCount(DAT_005dc2d8);
        while (local_13c != 0) {
          DeleteMenu(DAT_005dc2d8,0,0x400);
          local_13c = local_13c + -1;
        }
      }
      return 0;
    }
    if (param_2 == 0x117) {
      AppendMenuA(DAT_005dc2d8,0,0x66,s__Restore_00505758);
      AppendMenuA(DAT_005dc2d8,0,100,s_Help____00505764);
      return 0;
    }
  }
  else if (param_2 < 0x205) {
    if (param_2 == 0x204) {
      local_138.x = param_4 & 0xffff;
      local_138.y = param_4 >> 0x10;
      ClientToScreen(param_1,&local_138);
      SetRect(&local_130,local_138.x,local_138.y,local_138.x + 1,local_138.y + 1);
      TrackPopupMenu(DAT_005dc2d8,2,local_138.x,local_138.y,0,DAT_00618ab0,&local_130);
      return 0;
    }
    if (param_2 == 0x201) {
      SendMessageA(DAT_00618ab0,0x111,0x66,0);
      return 0;
    }
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      LVar1 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar1;
    }
    if (param_2 == 0x437) {
      FUN_004d9630(param_3,s_Minimized_attack_window_00505728);
      return 1;
    }
  }
  LVar1 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return LVar1;
}


