/*
 * Decompiled function: FUN_10002a6b
 * Entry Point: 10002a6b
 * Size: 408 bytes
 */
#include "deckdll.h"


void FUN_10002a6b(void)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int *arg_2;
  int val_4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  int iStack00000004;
  int *piStack00000010;
  int *stack_arg;
  int stack_arg;
  int stack_arg;
  int stack_arg;
  
  if (in_ZF) {
    piStack00000010 = malloc(0x32000);
    DAT_10212a00 = piStack00000010;
    DAT_102129fc = malloc(0x32000);
    DAT_10040454 = 1;
  }
  else {
    piStack00000010 = DAT_10212a00;
  }
  arg_2 = DAT_102129fc;
  if (stack_arg < stack_arg) {
    do {
      val_4 = stack_arg * stack_arg;
      piVar5 = stack_arg + val_4;
      piVar6 = piStack00000010;
      piVar7 = stack_arg;
      iStack00000004 = stack_arg;
      if (0 < stack_arg) {
        do {
          i_ptr_1 = piVar6 + stack_arg * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar7;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar7 + stack_arg) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[stack_arg] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + stack_arg * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar6 = *i_ptr_2 + *piVar7;
          piVar6[stack_arg] = *piVar7 - *i_ptr_2;
          iStack00000004 = iStack00000004 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = i_ptr_3;
        } while (iStack00000004 != 0);
      }
      piVar5 = stack_arg + val_4 * 3;
      piVar6 = stack_arg + val_4 * 2;
      piVar7 = arg_2;
      iStack00000004 = stack_arg;
      if (0 < stack_arg) {
        do {
          i_ptr_1 = piVar7 + stack_arg * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar6;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar6 + stack_arg) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[stack_arg] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + stack_arg * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar7 = *i_ptr_2 + *piVar6;
          piVar7[stack_arg] = *piVar6 - *i_ptr_2;
          iStack00000004 = iStack00000004 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = i_ptr_3;
        } while (iStack00000004 != 0);
      }
      val_4 = stack_arg * 2;
      thunk_FUN_10002d30(piStack00000010,arg_2,stack_arg,stack_arg,val_4,val_4,val_4
                        );
      stack_arg = val_4;
    } while (val_4 < stack_arg);
  }
  return;
}


