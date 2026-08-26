/*
 * Decompiled function: FUN_004a1b7a
 * Entry Point: 004a1b7a
 * Size: 125 bytes
 */
#include "duel.h"


bool FUN_004a1b7a(void)

{
  int iVar1;
  bool bVar2;
  int in_stack_00000058;
  int in_stack_00000104;
  int local_8;
  
  bVar2 = in_stack_00000104 == in_stack_00000058;
  for (local_8 = 0; local_8 < in_stack_00000058; local_8 = local_8 + 1) {
    iVar1 = FUN_00486348(*(HWND *)(&stack0x00000008 + local_8 * 4),
                         (int *)(&stack0x00000064 + local_8 * 8));
    if (iVar1 == 0) {
      bVar2 = false;
    }
  }
  return bVar2;
}


