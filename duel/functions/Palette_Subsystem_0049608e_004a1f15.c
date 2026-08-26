/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 004a1f15
 * Size: 397 bytes
 */
#include "duel.h"


int Palette_Subsystem_0049608e(HWND hwnd)

{
  LONG LVar1;
  HWND pHVar2;
  int in_stack_000000b0;
  int in_stack_000000b4;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  LONG local_60;
  undefined4 local_5c;
  int aiStack_58 [20];
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    local_68 = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    local_60 = GetWindowLongA(hwnd,4);
    local_68 = 1;
    local_5c = *(undefined4 *)(LVar1 + in_stack_000000b4 * 0x58);
    local_8 = 0;
    local_64 = 0;
    while ((local_64 < in_stack_000000b0 && (local_68 != 0))) {
      local_70 = *(undefined4 *)(&stack0x00000010 + local_64 * 8);
      local_6c = *(undefined4 *)(&stack0x00000014 + local_64 * 8);
      pHVar2 = CreateWindowExA(0,s_MAGICGAME_CardClass_00505fcc,s_Spell_Target_Card_00505fb8,
                               0x50000000,0,0,0,0,hwnd,(HMENU)0x1,DAT_00664680,&local_70);
      aiStack_58[local_64] = (int)pHVar2;
      if (aiStack_58[local_64] == 0) {
        local_68 = 0;
      }
      else {
        local_8 = local_8 + 1;
      }
      local_64 = local_64 + 1;
    }
    if (local_68 == 0) {
      for (local_64 = 0; local_64 < local_8; local_64 = local_64 + 1) {
        if (aiStack_58[local_64] != 0) {
          DestroyWindow((HWND)aiStack_58[local_64]);
        }
      }
      *(undefined4 *)(LVar1 + 0x54 + in_stack_000000b4 * 0x58) = 0;
    }
    else {
      FID_conflict__memcpy((void *)(in_stack_000000b4 * 0x58 + LVar1),&local_5c,0x58);
    }
  }
  return local_68;
}


