/*
 * Decompiled function: UI_Register_MAGICGAME_CardClass_004a1bf7
 * Entry Point: 004a1bf7
 * Size: 569 bytes
 */
#include "duel.h"


int UI_Register_MAGICGAME_CardClass_004a1bf7(HWND hwnd,undefined4 arg_2,undefined4 arg_3)

{
  LONG LVar1;
  HWND pHVar2;
  int in_stack_000000b0;
  int in_stack_000000b4;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  int local_64;
  LONG local_60;
  HWND local_5c;
  int aiStack_58 [20];
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    local_6c = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    local_60 = GetWindowLongA(hwnd,4);
    if (local_60 == 100) {
      local_6c = 0;
    }
    else {
      local_6c = 1;
      local_74 = arg_2;
      local_70 = arg_3;
      local_5c = CreateWindowExA(0,s_MAGICGAME_CardClass_00505f7c,s_Spell_Card_00505f70,0x50000000,0
                                 ,0,0,0,hwnd,(HMENU)0x1,DAT_00664680,&local_74);
      if (local_5c == (HWND)0x0) {
        local_6c = 0;
      }
      local_8 = 0;
      local_68 = 0;
      while ((local_68 < in_stack_000000b0 && (local_6c != 0))) {
        local_74 = *(undefined4 *)(&stack0x00000010 + local_68 * 8);
        local_70 = *(undefined4 *)(&stack0x00000014 + local_68 * 8);
        pHVar2 = CreateWindowExA(0,s_MAGICGAME_CardClass_00505fa4,s_Spell_Target_Card_00505f90,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x1,DAT_00664680,&local_74);
        aiStack_58[local_68] = (int)pHVar2;
        if (aiStack_58[local_68] == 0) {
          local_6c = 0;
        }
        else {
          local_8 = local_8 + 1;
        }
        local_68 = local_68 + 1;
      }
      if (local_6c == 0) {
        if (local_5c != (HWND)0x0) {
          DestroyWindow(local_5c);
        }
        for (local_68 = 0; local_68 < local_8; local_68 = local_68 + 1) {
          if (aiStack_58[local_68] != 0) {
            DestroyWindow((HWND)aiStack_58[local_68]);
          }
        }
      }
      else {
        for (local_64 = in_stack_000000b4; local_64 < local_60; local_64 = local_64 + 1) {
          FID_conflict__memcpy
                    ((void *)((local_64 + 1) * 0x58 + LVar1),(void *)(local_64 * 0x58 + LVar1),0x58)
          ;
        }
        FID_conflict__memcpy((void *)(in_stack_000000b4 * 0x58 + LVar1),&local_5c,0x58);
        local_60 = local_60 + 1;
        SetWindowLongA(hwnd,4,local_60);
      }
    }
  }
  return local_6c;
}


