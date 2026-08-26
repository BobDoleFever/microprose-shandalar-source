/*
 * Decompiled function: FUN_10015ce1
 * Entry Point: 10015ce1
 * Size: 208 bytes
 */
#include "deckdll.h"


int32_t __thiscall FUN_10015ce1(void *this)

{
  int val_1;
  int32_t reg_eax;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  int32_t *puVar6;
  int unaff_retaddr;
  int iStack00000080;
  int stack_arg;
  
  val_5 = 0;
  puVar6 = (int32_t *)register0x00000010;
  for (; this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar6 = reg_eax;
    puVar6 = puVar6 + 1;
  }
  val_4 = stack_arg + -1;
  iStack00000080 = val_4;
  puVar6 = &DAT_101cfba0;
  for (val_3 = 0x20; val_1 = DAT_1013a0b8, val_3 != 0; val_3 = val_3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  do {
    val_3 = val_5 + 1;
    if (*(int *)(&stack0x00000000 + val_5 * 4) == 0) {
      val_4 = (&DAT_10129434)[val_4 * 2];
    }
    else {
      val_4 = (&DAT_10129430)[val_4 * 2];
    }
    val_4 = val_4 - val_1;
    *(int *)((int)&stack0x00000080 + val_3 * 4) = val_4;
    if (val_4 < 0) {
      val_4 = (&DAT_101cfba0)[val_3];
      *(int32_t *)(&stack0x00000000 + val_3 * 4) = 1;
      (&DAT_101cfba0)[val_3] = val_4 + 1;
      val_2 = val_5 * 4;
      *(int *)(&stack0x00000000 + val_2) = *(int *)(&stack0x00000000 + val_5 * 4) + -1;
      val_4 = *(int *)((int)&stack0x00000080 + val_2);
      val_3 = val_5;
      if (unaff_retaddr < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)(&stack0x00000000 + val_2)) break;
        *(int32_t *)(&stack0x00000000 + val_2) = 1;
        val_3 = val_3 + -1;
        *(int *)(&stack0xfffffffc + val_2) = *(int *)(&stack0xfffffffc + val_2) + -1;
        val_4 = *(int *)(&stack0x0000007c + val_2);
        val_2 = val_2 + -4;
      } while (-1 < unaff_retaddr);
    }
    val_5 = val_3;
    if (unaff_retaddr < 0) {
      return 0;
    }
  } while( true );
}


