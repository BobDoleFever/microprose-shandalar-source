/*
 * Decompiled function: FUN_004381c6
 * Entry Point: 004381c6
 * Size: 408 bytes
 */
#include "duel.h"


undefined4 FUN_004381c6(int *arg1,UINT arg2)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  tagPOINT local_1c;
  tagRECT local_14;
  
  iVar2 = arg1[1];
  if (iVar2 != 0xa0) {
    if (iVar2 == 0x113) {
      if ((*arg1 == 0) && (arg1[2] == DAT_004f6a94)) {
        KillTimer((HWND)0x0,DAT_004f6a94);
        DAT_004f6a94 = 0;
        GetCursorPos(&local_1c);
        iVar2 = GetSystemMetrics(0xd);
        local_1c.x = local_1c.x + iVar2;
        iVar2 = GetSystemMetrics(0xe);
        local_1c.y = local_1c.y + iVar2;
        GetWindowRect(DAT_0060cc6c,&local_14);
        iVar3 = (local_14.right - local_14.left) + local_1c.x;
        iVar2 = GetSystemMetrics(0);
        iVar3 = iVar3 - iVar2;
        if (0 < iVar3) {
          local_1c.x = local_1c.x - iVar3;
        }
        iVar3 = (local_14.bottom - local_14.top) + local_1c.y;
        iVar2 = GetSystemMetrics(1);
        iVar3 = iVar3 - iVar2;
        if (0 < iVar3) {
          local_1c.y = local_1c.y - iVar3;
        }
        SetWindowPos(DAT_0060cc6c,(HWND)0x0,local_1c.x,local_1c.y,0,0,5);
        return 1;
      }
      return 0;
    }
    if (iVar2 != 0x200) {
      return 0;
    }
  }
  if (DAT_004f6a94 != 0) {
    KillTimer((HWND)0x0,DAT_004f6a94);
    DAT_004f6a94 = 0;
  }
  if ((DAT_00663e04 != 0) && (BVar1 = IsWindowVisible(DAT_0060cc6c), BVar1 != 0)) {
    DAT_004f6a94 = SetTimer((HWND)0x0,0,arg2,(TIMERPROC)0x0);
  }
  return 0;
}


