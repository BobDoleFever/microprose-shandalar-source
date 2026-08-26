/*
 * Decompiled function: Ai_Subsystem_004b553f
 * Entry Point: 004b553f
 * Size: 526 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b553f(char *str_1)

{
  int iVar1;
  int local_28;
  tagPOINT local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char *local_8;
  
  if (str_1 == (char *)0x0) {
    local_8 = &DAT_0052d3d4;
  }
  else {
    local_8 = str_1;
  }
  if (DAT_006fe444 != 0) {
    if (*local_8 == '\0') {
      ShowWindow(DAT_00695ea0,0);
      SetWindowTextA(DAT_00695ea0,local_8);
    }
    else {
      local_10 = GetSystemMetrics(0);
      local_c = GetSystemMetrics(1);
      if (DAT_006fe424 == 0) {
        iVar1 = GetSystemMetrics(1);
        if ((iVar1 * 3) / 100 < 0x13) {
          local_28 = 0x12;
        }
        else {
          iVar1 = GetSystemMetrics(1);
          local_28 = (iVar1 * 3) / 100;
        }
        local_1c = FUN_004f4eb3(DAT_00695ea0,local_8);
        local_1c = local_1c + local_28 * 2;
        local_14 = (local_10 - (local_10 * 0x14) / 100) - local_1c;
        local_18 = (local_c - local_28) / 2;
      }
      else {
        iVar1 = GetSystemMetrics(1);
        if ((iVar1 * 2) / 100 < 0xd) {
          local_28 = 0xc;
        }
        else {
          iVar1 = GetSystemMetrics(1);
          local_28 = (iVar1 * 2) / 100;
        }
        local_1c = FUN_004f4eb3(DAT_00695ea0,local_8);
        local_1c = local_1c + local_28 * 2;
        GetCursorPos(&local_24);
        iVar1 = GetSystemMetrics(0xe);
        local_24.y = local_24.y + iVar1;
        if (local_10 < local_24.x + local_1c) {
          local_24.x = local_10 - local_1c;
        }
        if (local_c < local_24.y + local_28) {
          local_24.y = local_c - local_28;
        }
        local_14 = local_24.x;
        local_18 = local_24.y;
      }
      SetWindowPos(DAT_00695ea0,(HWND)0x0,local_14,local_18,local_1c,local_28,4);
      SetWindowTextA(DAT_00695ea0,local_8);
      ShowWindow(DAT_00695ea0,5);
      BringWindowToTop(DAT_00695ea0);
    }
  }
  return;
}


