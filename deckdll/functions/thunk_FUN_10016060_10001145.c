/*
 * Decompiled function: thunk_FUN_10016060
 * Entry Point: 10001145
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10016060(int *arg_1,uint32_t *arg_2,int arg_3)

{
  int *i_ptr_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  int *piVar8;
  uint8_t bStack_8;
  
  DAT_101394b4 = arg_2;
  if (((uint32_t)arg_2 & 3) == 0) {
    DAT_1004300c = 0;
    DAT_1012942c = 0;
  }
  else {
    val_5 = 4 - ((uint32_t)arg_2 & 3);
    DAT_1004300c = val_5 * 8;
    DAT_101394b4 = (uint32_t *)(val_5 + (int)arg_2);
    DAT_1012942c = 0xffffffffU >> (0x20U - (char)DAT_1004300c & 0x1f) & *arg_2;
  }
  i_ptr_1 = arg_1;
  DAT_10129428 = arg_3;
  DAT_1013a0bc = arg_2;
  if (DAT_1004300c < 8) {
    val_5 = 8 - DAT_1004300c;
    if ((int)DAT_101394b4 + (4 - (int)arg_2) < arg_3) {
      uval_2 = *DAT_101394b4;
      DAT_101394b4 = DAT_101394b4 + 1;
      uval_7 = DAT_1012942c | ((&DAT_101394b0)[-val_5] & uval_2) << ((uint8_t)DAT_1004300c & 0x1f);
      DAT_1012942c = uval_2 >> ((uint8_t)val_5 & 0x1f);
      DAT_1004300c = 0x20 - val_5;
    }
    else {
      uval_7 = 0xffffffff;
    }
  }
  else {
    uval_7 = DAT_10139490 & DAT_1012942c;
    DAT_1012942c = DAT_1012942c >> 8;
    DAT_1004300c = DAT_1004300c - 8;
  }
  while (uval_7 != 0xffffffff) {
    val_5 = (&DAT_101394b8)[uval_7 * 3];
    if (val_5 < 0x7fffffff) {
      uval_2 = (&DAT_101394bc)[uval_7 * 3];
      bStack_8 = (uint8_t)uval_2;
      if (val_5 == -0x80000000) {
        uval_2 = uval_2 + 2;
        if (DAT_1004300c < uval_2) {
          uval_2 = uval_2 - DAT_1004300c;
          if ((int)DAT_101394b4 + (4 - (int)DAT_1013a0bc) < DAT_10129428) {
            uval_3 = *DAT_101394b4;
            DAT_101394b4 = DAT_101394b4 + 1;
            uval_4 = DAT_1012942c | ((&DAT_101394b0)[-uval_2] & uval_3) << ((uint8_t)DAT_1004300c & 0x1f);
            DAT_1012942c = uval_3 >> ((uint8_t)uval_2 & 0x1f);
            DAT_1004300c = 0x20;
            goto LAB_10016271;
          }
          uval_4 = 0xffffffff;
        }
        else {
          uval_4 = (&DAT_101394b0)[-uval_2] & DAT_1012942c;
          DAT_1012942c = DAT_1012942c >> ((uint8_t)uval_2 & 0x1f);
LAB_10016271:
          DAT_1004300c = DAT_1004300c - uval_2;
        }
        if ((int)uval_4 < 0) break;
        uval_7 = uval_4 << (8 - bStack_8 & 0x1f) | (int)uval_7 >> (bStack_8 & 0x1f);
        uval_2 = uval_7;
        piVar8 = i_ptr_1;
        if (((uint32_t)i_ptr_1 & 4) == 0) {
LAB_100162ad:
          uval_3 = uval_2 >> 1;
          if (uval_3 != 0) {
            while (uval_3 = uval_3 - 1, uval_3 != 0) {
              piVar8[0] = 0;
              piVar8[1] = 0;
              piVar8 = piVar8 + 2;
            }
            piVar8[0] = 0;
            piVar8[1] = 0;
          }
          if ((uval_2 & 1) != 0) {
            *(uint8_t *)piVar8 = 0;
          }
        }
        else {
          *(uint8_t *)i_ptr_1 = 0;
          piVar8 = i_ptr_1 + 1;
          uval_2 = uval_7 - 1;
          if (uval_2 != 0 && 0 < (int)uval_7) goto LAB_100162ad;
        }
        i_ptr_1 = i_ptr_1 + uval_7;
        if (DAT_1004300c < 8) {
          if ((int)DAT_101394b4 + (4 - (int)DAT_1013a0bc) < DAT_10129428) {
LAB_10016651:
            val_5 = 8 - DAT_1004300c;
            uval_2 = *DAT_101394b4;
            DAT_101394b4 = DAT_101394b4 + 1;
            uval_7 = DAT_1012942c | ((&DAT_101394b0)[-val_5] & uval_2) << ((uint8_t)DAT_1004300c & 0x1f);
            DAT_1012942c = uval_2 >> ((uint8_t)val_5 & 0x1f);
            DAT_1004300c = 0x20 - val_5;
          }
          else {
LAB_1001664a:
            uval_7 = 0xffffffff;
          }
        }
        else {
          uval_7 = DAT_10139490 & DAT_1012942c;
          DAT_1012942c = DAT_1012942c >> 8;
          DAT_1004300c = DAT_1004300c - 8;
        }
      }
      else {
        *i_ptr_1 = val_5;
        i_ptr_1 = i_ptr_1 + 1;
        if (DAT_1004300c < uval_2) {
          uval_2 = uval_2 - DAT_1004300c;
          if ((int)DAT_101394b4 + (4 - (int)DAT_1013a0bc) < DAT_10129428) {
            uval_3 = *DAT_101394b4;
            DAT_101394b4 = DAT_101394b4 + 1;
            uval_4 = DAT_1012942c | ((&DAT_101394b0)[-uval_2] & uval_3) << ((uint8_t)DAT_1004300c & 0x1f);
            DAT_1012942c = uval_3 >> ((uint8_t)uval_2 & 0x1f);
            DAT_1004300c = 0x20;
            goto LAB_10016409;
          }
          uval_4 = 0xffffffff;
        }
        else {
          uval_4 = (&DAT_101394b0)[-uval_2] & DAT_1012942c;
          DAT_1012942c = DAT_1012942c >> (bStack_8 & 0x1f);
LAB_10016409:
          DAT_1004300c = DAT_1004300c - uval_2;
        }
        if (uval_4 == 0xffffffff) break;
        uval_7 = (int)uval_7 >> (bStack_8 & 0x1f) | uval_4 << (8 - bStack_8 & 0x1f);
      }
    }
    else {
      val_5 = (&DAT_101394c0)[uval_7 * 3];
      do {
        if (DAT_1004300c == 0) {
          if ((int)DAT_101394b4 - (int)DAT_1013a0bc < DAT_10129428) {
            DAT_1012942c = *DAT_101394b4;
            DAT_101394b4 = DAT_101394b4 + 1;
            DAT_1004300c = 0x20;
            goto LAB_10016482;
          }
          uval_2 = 0xffffffff;
        }
        else {
LAB_10016482:
          uval_2 = (uint32_t)((DAT_1012942c & 1) != 0);
          DAT_1012942c = DAT_1012942c >> 1;
          DAT_1004300c = DAT_1004300c - 1;
        }
        if (uval_2 == 0xffffffff) goto LAB_100165e9;
        if (uval_2 == 0) {
          val_6 = (&DAT_10129434)[val_5 * 2];
        }
        else {
          val_6 = (&DAT_10129430)[val_5 * 2];
        }
        val_5 = val_6 - DAT_1013a0b8;
      } while (-1 < val_5);
      if (val_6 == 0) {
        if (DAT_1004300c < 10) {
          val_5 = 10 - DAT_1004300c;
          if ((int)DAT_101394b4 + (4 - (int)DAT_1013a0bc) < DAT_10129428) {
            uval_2 = *DAT_101394b4;
            DAT_101394b4 = DAT_101394b4 + 1;
            uval_7 = DAT_1012942c | ((&DAT_101394b0)[-val_5] & uval_2) << ((uint8_t)DAT_1004300c & 0x1f);
            DAT_1012942c = uval_2 >> ((uint8_t)val_5 & 0x1f);
            DAT_1004300c = 0x20 - val_5;
          }
          else {
            uval_7 = 0xffffffff;
          }
        }
        else {
          uval_7 = DAT_10139488 & DAT_1012942c;
          DAT_1012942c = DAT_1012942c >> 10;
          DAT_1004300c = DAT_1004300c - 10;
        }
        if (-1 < (int)uval_7) {
          uval_2 = uval_7;
          piVar8 = i_ptr_1;
          if (((uint32_t)i_ptr_1 & 4) == 0) {
LAB_100165b3:
            uval_3 = uval_2 >> 1;
            if (uval_3 != 0) {
              while (uval_3 = uval_3 - 1, uval_3 != 0) {
                piVar8[0] = 0;
                piVar8[1] = 0;
                piVar8 = piVar8 + 2;
              }
              piVar8[0] = 0;
              piVar8[1] = 0;
            }
            if ((uval_2 & 1) != 0) {
              *(uint8_t *)piVar8 = 0;
            }
          }
          else {
            *(uint8_t *)i_ptr_1 = 0;
            piVar8 = i_ptr_1 + 1;
            uval_2 = uval_7 - 1;
            if (uval_2 != 0 && 0 < (int)uval_7) goto LAB_100165b3;
          }
          i_ptr_1 = i_ptr_1 + uval_7;
        }
      }
      else {
        *i_ptr_1 = *(int *)(DAT_10129420 + val_6 * 4);
        i_ptr_1 = i_ptr_1 + 1;
      }
LAB_100165e9:
      if (DAT_1004300c < 8) {
        if ((int)DAT_101394b4 + (4 - (int)DAT_1013a0bc) < DAT_10129428) goto LAB_10016651;
        goto LAB_1001664a;
      }
      uval_7 = DAT_10139490 & DAT_1012942c;
      DAT_1012942c = DAT_1012942c >> 8;
      DAT_1004300c = DAT_1004300c - 8;
    }
  }
  return (int)i_ptr_1 - (int)arg_1 >> 2;
}


