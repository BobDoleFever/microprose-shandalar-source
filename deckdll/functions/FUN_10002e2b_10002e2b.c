/*
 * Decompiled function: FUN_10002e2b
 * Entry Point: 10002e2b
 * Size: 549 bytes
 */
#include "deckdll.h"


uint8_t * FUN_10002e2b(void)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  uint8_t *puVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  bool bVar8;
  uint32_t uStack00000004;
  int iStack00000008;
  int *piStack0000000c;
  int *piStack00000010;
  uint8_t *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  int *stack_arg;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  
  if (in_ZF) {
    val_2 = -0x400;
    do {
      if (val_2 < 1) {
        PTR_DAT_10040458[val_2] = 0;
      }
      else {
        val_3 = val_2 >> 2;
        if (0xfe < val_3) {
          val_3 = 0xff;
        }
        PTR_DAT_10040458[val_2] = (char)val_3;
      }
      val_2 = val_2 + 1;
    } while (val_2 < 0x1c00);
    DAT_10103c94 = 1;
  }
  if (stack_arg == (uint8_t *)0x0) {
    stack_arg = malloc(stack_arg * stack_arg * 3 + 0x10);
  }
  iStack00000008 = 0;
  if (0 < stack_arg) {
    piStack0000000c = stack_arg;
    piStack00000010 = stack_arg;
    puVar5 = stack_arg;
    do {
      piVar6 = piStack00000010;
      piVar7 = piStack0000000c;
      if (stack_arg != 0) {
        val_2 = (iStack00000008 / 2) * stack_arg;
        piVar6 = stack_arg + val_2;
        piVar7 = stack_arg + val_2;
      }
      uStack00000004 = 0;
      if (0 < stack_arg) {
        do {
          val_2 = *stack_arg;
          if (stack_arg == 0) {
            val_3 = *piVar7;
            val_3 = (val_3 >> 3) + (val_3 >> 1) + val_3;
            val_1 = *piVar6;
          }
          else {
            if ((uStack00000004 & 1) == 0) {
              val_1 = *piVar6;
              val_3 = *piVar7;
            }
            else {
              bVar8 = stack_arg - uStack00000004 != 1;
              val_1 = (piVar6[bVar8] + *piVar6) / 2;
              val_3 = (piVar7[bVar8] + *piVar7) / 2;
            }
            val_3 = (val_3 >> 3) + (val_3 >> 1) + val_3;
          }
          val_4 = val_3 + -0x333 + val_2;
          val_3 = val_2 + -0x400 + val_1 * 2;
          *puVar5 = PTR_DAT_10040458[val_3];
          puVar5[1] = PTR_DAT_10040458
                      [((((val_3 >> 4) - (val_2 >> 2)) - (val_3 >> 2)) - (val_4 >> 1)) + val_2 * 2];
          puVar5[2] = PTR_DAT_10040458[val_4];
          if ((stack_arg == 0) || ((uStack00000004 & 1) != 0)) {
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          uStack00000004 = uStack00000004 + 1;
          stack_arg = stack_arg + 1;
          puVar5 = puVar5 + 3;
        } while ((int)uStack00000004 < stack_arg);
      }
      piStack0000000c = piStack0000000c + stack_arg;
      piStack00000010 = piStack00000010 + stack_arg;
      iStack00000008 = iStack00000008 + 1;
    } while (iStack00000008 < stack_arg);
  }
  return stack_arg;
}


