/*
 * Decompiled function: Glue_Subsystem_004d0602
 * Entry Point: 004a26c6
 * Size: 861 bytes
 */
#include "duel.h"


LRESULT Glue_Subsystem_004d0602(HWND hwnd,uint uMsg,HDC wParam,uint lParam)

{
  HBRUSH hbr;
  LRESULT LVar1;
  int local_13c;
  tagPOINT local_138;
  tagRECT local_130;
  uint local_120 [66];
  HDC local_18;
  tagRECT local_14;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_18 = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_14);
      IntersectClipRect(local_18,0,0,local_14.right,local_14.bottom);
      if (DAT_005dcd50 == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_120,(uint *)&DAT_006189a0);
        FUN_004d9640(local_120,(uint *)s__WINBK_SpellMin_pic_00505ff8);
        DAT_005dcd50 = (HANDLE)Pic_Load_00423833((char *)local_120);
      }
      if (DAT_005dcd50 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_18,&local_14,hbr);
      }
      else {
        FUN_004709ae((int)local_18,(int)&local_14,DAT_005dcd50);
      }
      return 1;
    }
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00663df0,0);
      return 0;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_13c = GetMenuItemCount(DAT_005dcd1c);
        while (local_13c != 0) {
          DeleteMenu(DAT_005dcd1c,0,0x400);
          local_13c = local_13c + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      AppendMenuA(DAT_005dcd1c,0,0x66,s__Restore_0050600c);
      AppendMenuA(DAT_005dcd1c,0,100,s_Help____00506018);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_138.x = lParam & 0xffff;
      local_138.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_138);
      SetRect(&local_130,local_138.x,local_138.y,local_138.x + 1,local_138.y + 1);
      TrackPopupMenu(DAT_005dcd1c,2,local_138.x,local_138.y,0,DAT_00663df0,&local_130);
      return 0;
    }
    if (uMsg == 0x201) {
      SendMessageA(DAT_00663df0,0x111,0x66,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 0x437) {
      Mem_AllocOrFree_004d9630((uint *)wParam,(uint *)s_Minimized_spell_chain_00505fe0);
      return 1;
    }
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}


