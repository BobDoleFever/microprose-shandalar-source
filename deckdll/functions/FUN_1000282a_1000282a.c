/*
 * Decompiled function: FUN_1000282a
 * Entry Point: 1000282a
 * Size: 283 bytes
 */
#include "deckdll.h"


void FUN_1000282a(void)

{
  int *i_ptr_1;
  int val_2;
  int reg_eax;
  int val_3;
  int *piVar4;
  int val_5;
  int *piVar6;
  bool in_ZF;
  char in_SF;
  char in_OF;
  int iStack0000000c;
  int *stack_arg;
  int *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  
  iStack0000000c = reg_eax;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar4 = stack_arg;
      piVar6 = stack_arg;
      while (piVar4 < stack_arg + stack_arg + -1) {
        piVar6 = piVar6 + stack_arg * 2;
        i_ptr_1 = piVar4 + 1;
        piVar4 = piVar4 + 1;
        val_2 = *stack_arg;
        val_5 = *i_ptr_1 * 0xb504;
        val_3 = val_5;
        if (val_2 != 0) {
          val_3 = val_5 + val_2 * 0xb504;
          val_5 = val_5 + val_2 * -0xb504;
        }
        stack_arg = stack_arg + 1;
        *piVar6 = val_3 >> 0x10;
        piVar6[stack_arg] = val_5 >> 0x10;
      }
      *stack_arg = (*stack_arg + *stack_arg) * 0xb504 >> 0x10;
      val_3 = *stack_arg;
      val_5 = *stack_arg;
      stack_arg = piVar4 + 1;
      stack_arg = stack_arg + 1;
      iStack0000000c = iStack0000000c + -1;
      stack_arg[stack_arg] = (val_3 - val_5) * 0xb504 >> 0x10;
      stack_arg = stack_arg + 1;
    } while (iStack0000000c != 0);
  }
  return;
}


