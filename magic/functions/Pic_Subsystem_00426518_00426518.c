/*
 * Decompiled function: Pic_Subsystem_00426518
 * Entry Point: 00426518
 * Size: 685 bytes
 */
#include "magic.h"


void Pic_Subsystem_00426518(HDC hdc,int arg2)

{
  BOOL BVar1;
  int local_d4;
  int local_d0 [38];
  HGDIOBJ local_38;
  tagRECT local_34;
  int local_24;
  tagRECT local_20;
  int local_10;
  HBRUSH local_c;
  int local_8;
  
  Ai_Subsystem_004b765d(&local_8,&local_24);
  if ((local_8 == -1) || (local_24 == -1)) {
    local_c = CreateSolidBrush(0xff);
    local_38 = SelectObject(hdc,local_c);
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      Ai_Subsystem_004b74fa(local_d0,local_10);
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if (local_d0[local_d4] != 0) {
          Pic_Subsystem_004262cf
                    (&local_34,local_10,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&local_20,&local_34);
            local_20.left = local_20.right - (local_34.right - local_34.left) / 3;
            local_20.top = local_20.bottom -
                           ((local_20.right - local_20.left) * (local_34.bottom - local_34.top)) /
                           (local_34.right - local_34.left);
            Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
          }
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_c);
  }
  if ((local_8 != -1) && (local_24 != -1)) {
    local_c = CreateSolidBrush(0xff00);
    local_38 = SelectObject(hdc,local_c);
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      for (local_d4 = 0; local_d4 < 0x26; local_d4 = local_d4 + 1) {
        if ((local_10 == local_8) && (local_d4 == local_24)) {
          Pic_Subsystem_004262cf
                    (&local_34,local_10,local_d4,*(int *)(arg2 + 8),*(int *)(arg2 + 0xc));
          BVar1 = IsRectEmpty(&local_34);
          if (BVar1 == 0) {
            CopyRect(&local_20,&local_34);
            local_20.right = local_20.left + (local_34.right - local_34.left) / 3;
            local_20.top = local_20.bottom -
                           ((local_20.right - local_20.left) * (local_34.bottom - local_34.top)) /
                           (local_34.right - local_34.left);
            Ellipse(hdc,local_20.left,local_20.top,local_20.right,local_20.bottom);
          }
        }
      }
    }
    SelectObject(hdc,local_38);
    DeleteObject(local_c);
  }
  return;
}


