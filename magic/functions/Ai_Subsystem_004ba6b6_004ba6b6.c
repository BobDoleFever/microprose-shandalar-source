/*
 * Decompiled function: Ai_Subsystem_004ba6b6
 * Entry Point: 004ba6b6
 * Size: 472 bytes
 */
#include "magic.h"


void Ai_Subsystem_004ba6b6(LPRECT arg_1,HWND hwnd,int arg_3)

{
  undefined1 local_48 [24];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  Ai_Subsystem_004b7072(local_48,(uint)(hwnd != DAT_006b2d60));
  GetClientRect(hwnd,&local_18);
  local_20 = (local_18.bottom * 5) / 100;
  local_28 = (local_18.bottom * 0x91) / 1000;
  local_24 = (local_18.bottom * 0x14) / 1000;
  if (arg_3 == 1) {
    local_2c = 0;
  }
  else if (arg_3 == 2) {
    local_2c = 1;
  }
  else if (arg_3 == 3) {
    local_2c = 2;
  }
  else if (arg_3 == 4) {
    local_2c = 3;
  }
  else if (arg_3 == 5) {
    local_2c = 4;
  }
  else if (arg_3 == 0) {
    local_2c = 5;
  }
  else if (arg_3 == 6) {
    local_2c = 5;
  }
  else {
    local_2c = -1;
  }
  if (local_2c == -1) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    local_8 = (local_24 + local_28) * local_2c + local_20;
    local_1c = local_8 + local_28;
    SetRect(arg_1,local_18.left,local_8,local_18.right,local_1c);
    if (local_30 == 0) {
      if (arg_3 == 6) {
        SetRect(arg_1,0,0,0,0);
      }
    }
    else if (arg_3 == 0) {
      arg_1->right = arg_1->right - (local_18.right - local_18.left) / 2;
    }
    else if (arg_3 == 6) {
      arg_1->left = arg_1->left + ((local_18.right - local_18.left) * 2) / 3;
    }
  }
  return;
}


