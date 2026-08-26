/*
 * Decompiled function: FUN_1003d810
 * Entry Point: 1003d810
 * Size: 47 bytes
 */
#include "deckdll.h"


/* WARNING: Unable to track spacebase fully for stack */

void FUN_1003d810(void)

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


