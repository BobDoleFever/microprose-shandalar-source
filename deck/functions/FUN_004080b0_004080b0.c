/*
 * Decompiled function: FUN_004080b0
 * Entry Point: 004080b0
 * Size: 47 bytes
 */
#include "deck.h"


/* WARNING: Unable to track spacebase fully for stack */

void FUN_004080b0(void)

{
  uint32_t reg_eax;
  uint8_t *u_ptr_1;
  int32_t unaff_retaddr;
  
  u_ptr_1 = &stack0x00000004;
  for (; 0xfff < reg_eax; reg_eax = reg_eax - 0x1000) {
    u_ptr_1 = u_ptr_1 + -0x1000;
  }
  *(int32_t *)(u_ptr_1 + (-4 - reg_eax)) = unaff_retaddr;
  return;
}


