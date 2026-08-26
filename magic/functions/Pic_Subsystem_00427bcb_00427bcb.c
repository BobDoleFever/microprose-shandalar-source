/*
 * Decompiled function: Pic_Subsystem_00427bcb
 * Entry Point: 00427bcb
 * Size: 619 bytes
 */
#include "magic.h"


void Pic_Subsystem_00427bcb(HDC hdc,int arg2)

{
  BOOL BVar1;
  int local_d4;
  int local_d0 [38];
  HGDIOBJ local_38;
  tagRECT local_34;
  int local_24;
  tagRECT local_20;
  HBRUSH local_10;
  int local_c;
  int local_8;
  
  Ai_Subsystem_004b765d(&local_8,&local_24);
  if ((local_8 == -1) || (local_24 == -1)) {
    local_10 = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,local_10);
    Ai_Subsystem_004b74b1(&local_c,(undefined4 *)0x0);
    Ai_Subsystem_004b74fa(local_d0,local_c);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_d0[local_d4] != 0) {
        Pic_Subsystem_00427a0a(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
        BVar1 = IsRectEmpty(&local_34);
        if (BVar1 == 0) {
          CopyRect(&local_20,&local_34);
          local_20.left = local_20.right - (local_34.right - local_34.left) / 3;
          local_20.top = local_20.bottom -
                         ((local_34.bottom - local_34.top) * (local_20.right - local_20.left)) /
                         (local_34.right - local_34.left);
          Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_10);
  }
  if ((local_8 != -1) && (local_24 != -1)) {
    local_10 = CreateSolidBrush(0xff00);
    local_38 = SelectObject(hdc,local_10);
    for (local_d4 = 0x15; local_d4 < 0x1f; local_d4 = local_d4 + 1) {
      if (local_24 == local_d4) {
        Pic_Subsystem_00427a0a(&local_34,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
        BVar1 = IsRectEmpty(&local_34);
        if (BVar1 == 0) {
          CopyRect(&local_20,&local_34);
          local_20.right = local_20.left + (local_34.right - local_34.left) / 3;
          local_20.top = local_20.bottom -
                         ((local_34.bottom - local_34.top) * (local_20.right - local_20.left)) /
                         (local_34.right - local_34.left);
          Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_10);
  }
  return;
}


