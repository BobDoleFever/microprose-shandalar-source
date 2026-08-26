/*
 * Decompiled function: thunk_FUN_10002a60
 * Entry Point: 100012b7
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10002a60(int *arg_1,int arg_2,int arg_3)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int *arg_2_00;
  int val_4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int stack_arg;
  int iStack_18;
  int *piStack_c;
  
  if (DAT_10040454 == 0) {
    piStack_c = malloc(0x32000);
    DAT_10212a00 = piStack_c;
    DAT_102129fc = malloc(0x32000);
    DAT_10040454 = 1;
  }
  else {
    piStack_c = DAT_10212a00;
  }
  arg_2_00 = DAT_102129fc;
  if (arg_3 < arg_2) {
    do {
      val_4 = arg_3 * arg_3;
      piVar5 = arg_1 + val_4;
      piVar6 = piStack_c;
      piVar7 = arg_1;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          i_ptr_1 = piVar6 + arg_3 * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar7;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar7 + arg_3) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[arg_3] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + arg_3 * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar6 = *i_ptr_2 + *piVar7;
          piVar6[arg_3] = *piVar7 - *i_ptr_2;
          iStack_18 = iStack_18 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = i_ptr_3;
        } while (iStack_18 != 0);
      }
      piVar5 = arg_1 + val_4 * 3;
      piVar6 = arg_1 + val_4 * 2;
      piVar7 = arg_2_00;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          i_ptr_1 = piVar7 + arg_3 * 2;
          i_ptr_2 = piVar5;
          i_ptr_3 = piVar6;
          while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < piVar6 + arg_3) {
            *i_ptr_1 = *i_ptr_3 + *i_ptr_2;
            i_ptr_1[arg_3] = *i_ptr_3 - *i_ptr_2;
            i_ptr_1 = i_ptr_1 + arg_3 * 2;
            i_ptr_2 = i_ptr_2 + 1;
          }
          piVar5 = i_ptr_2 + 1;
          *piVar7 = *i_ptr_2 + *piVar6;
          piVar7[arg_3] = *piVar6 - *i_ptr_2;
          iStack_18 = iStack_18 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = i_ptr_3;
        } while (iStack_18 != 0);
      }
      val_4 = arg_3 * 2;
      thunk_FUN_10002d30(piStack_c,arg_2_00,arg_1,arg_3,val_4,val_4,val_4);
      arg_3 = val_4;
    } while (val_4 < stack_arg);
  }
  return;
}


