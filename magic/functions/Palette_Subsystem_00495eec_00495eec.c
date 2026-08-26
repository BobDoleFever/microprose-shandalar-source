/*
 * Decompiled function: Palette_Subsystem_00495eec
 * Entry Point: 00495eec
 * Size: 408 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_00495eec(int *arg1,UINT arg2)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  tagPOINT local_1c;
  tagRECT local_14;
  
  iVar2 = arg1[1];
  if (iVar2 != 0xa0) {
    if (iVar2 == 0x113) {
      if ((*arg1 == 0) && (arg1[2] == DAT_0052b02c)) {
        KillTimer((HWND)0x0,DAT_0052b02c);
        DAT_0052b02c = 0;
        GetCursorPos(&local_1c);
        iVar2 = GetSystemMetrics(0xd);
        local_1c.x = local_1c.x + iVar2;
        iVar2 = GetSystemMetrics(0xe);
        local_1c.y = local_1c.y + iVar2;
        GetWindowRect(DAT_00695ea0,&local_14);
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
        SetWindowPos(DAT_00695ea0,(HWND)0x0,local_1c.x,local_1c.y,0,0,5);
        return 1;
      }
      return 0;
    }
    if (iVar2 != 0x200) {
      return 0;
    }
  }
  if (DAT_0052b02c != 0) {
    KillTimer((HWND)0x0,DAT_0052b02c);
    DAT_0052b02c = 0;
  }
  if ((DAT_006fe424 != 0) && (BVar1 = IsWindowVisible(DAT_00695ea0), BVar1 != 0)) {
    DAT_0052b02c = SetTimer((HWND)0x0,0,arg2,(TIMERPROC)0x0);
  }
  return 0;
}


