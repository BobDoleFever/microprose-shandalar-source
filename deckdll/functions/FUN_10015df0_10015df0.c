/*
 * Decompiled function: FUN_10015df0
 * Entry Point: 10015df0
 * Size: 488 bytes
 */
#include "deckdll.h"


int FUN_10015df0(int32_t *arg_1,uint32_t *arg_2,int arg_3)

{
  int val_1;
  int32_t *u_ptr_2;
  int val_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int local_8;
  
  local_8 = 0;
  DAT_101394b4 = arg_2;
  DAT_1013a0bc = arg_2;
  val_3 = DAT_10129424 + -1;
  DAT_10129428 = arg_3;
  DAT_1004300c = 0;
  do {
    if (DAT_1004300c == 0) {
      if ((int)DAT_101394b4 - (int)DAT_1013a0bc < DAT_10129428) {
        DAT_1012942c = *DAT_101394b4;
        DAT_101394b4 = DAT_101394b4 + 1;
        DAT_1004300c = 0x20;
        goto LAB_10015e73;
      }
      uval_5 = 0xffffffff;
    }
    else {
LAB_10015e73:
      uval_5 = (uint32_t)((DAT_1012942c & 1) != 0);
      DAT_1012942c = DAT_1012942c >> 1;
      DAT_1004300c = DAT_1004300c - 1;
    }
    if (uval_5 == 0xffffffff) {
      return local_8;
    }
    if (uval_5 == 0) {
      val_1 = (&DAT_10129434)[val_3 * 2];
    }
    else {
      val_1 = (&DAT_10129430)[val_3 * 2];
    }
    val_3 = val_1 - DAT_1013a0b8;
    if (val_3 < 0) {
      if (val_1 == 0) {
        if (DAT_1004300c < 10) {
          val_3 = 10 - DAT_1004300c;
          if ((int)DAT_101394b4 + (4 - (int)DAT_1013a0bc) < DAT_10129428) {
            uval_5 = *DAT_101394b4;
            DAT_101394b4 = DAT_101394b4 + 1;
            uval_4 = DAT_1012942c | ((&DAT_101394b0)[-val_3] & uval_5) << ((uint8_t)DAT_1004300c & 0x1f);
            DAT_1012942c = uval_5 >> ((uint8_t)val_3 & 0x1f);
            DAT_1004300c = 0x20 - val_3;
          }
          else {
            uval_4 = 0xffffffff;
          }
        }
        else {
          uval_4 = DAT_10139488 & DAT_1012942c;
          DAT_1012942c = DAT_1012942c >> 10;
          DAT_1004300c = DAT_1004300c - 10;
        }
        if ((int)uval_4 < 0) {
          return local_8;
        }
        u_ptr_2 = arg_1 + uval_4;
        for (uval_5 = uval_4 & 0x3fffffff; uval_5 != 0; uval_5 = uval_5 - 1) {
          *arg_1 = 0;
          arg_1 = arg_1 + 1;
        }
        for (val_3 = 0; val_3 != 0; val_3 = val_3 + -1) {
          *(uint8_t *)arg_1 = 0;
          arg_1 = (int32_t *)((int)arg_1 + 1);
        }
        local_8 = local_8 + uval_4;
      }
      else {
        u_ptr_2 = arg_1 + 1;
        local_8 = local_8 + 1;
        *arg_1 = *(int32_t *)(DAT_10129420 + val_1 * 4);
      }
      val_3 = DAT_10129424 + -1;
      arg_1 = u_ptr_2;
    }
  } while( true );
}


