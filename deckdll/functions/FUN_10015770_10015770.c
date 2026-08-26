/*
 * Decompiled function: FUN_10015770
 * Entry Point: 10015770
 * Size: 579 bytes
 */
#include "deckdll.h"


int FUN_10015770(uint32_t *arg_1,int32_t arg_2,int32_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int val_3;
  uint32_t uval_4;
  uint32_t *puVar5;
  uint32_t local_4;
  
  val_3 = 0;
  local_4 = 0xd;
  do {
    (&DAT_10139430)[val_3] = 0xffffffff >> ((uint8_t)val_3 & 0x1f);
    val_3 = val_3 + 1;
  } while (val_3 < 0x20);
  DAT_1013a0bc = arg_1;
  DAT_101394b4 = arg_1 + 1;
  DAT_10129428 = 100000;
  DAT_1004300c = 0x13;
  uval_1 = DAT_1013947c & *arg_1;
  DAT_1012942c = *arg_1 >> 0xd;
  DAT_10129424 = uval_1;
  if (0 < (int)uval_1) {
    puVar5 = &DAT_10129430;
    local_4 = uval_1 * 0x1a + 0xd;
    do {
      if (DAT_1004300c < 0xd) {
        val_3 = 0xd - DAT_1004300c;
        if ((int)DAT_101394b4 + (4 - (int)arg_1) < 100000) {
          uval_2 = *DAT_101394b4;
          DAT_101394b4 = DAT_101394b4 + 1;
          uval_4 = DAT_1012942c | ((&DAT_101394b0)[-val_3] & uval_2) << ((uint8_t)DAT_1004300c & 0x1f);
          DAT_1012942c = uval_2 >> ((uint8_t)val_3 & 0x1f);
          DAT_1004300c = 0x20 - val_3;
          *puVar5 = uval_4;
        }
        else {
          *puVar5 = 0xffffffff;
        }
      }
      else {
        uval_2 = DAT_1013947c & DAT_1012942c;
        DAT_1012942c = DAT_1012942c >> 0xd;
        DAT_1004300c = DAT_1004300c - 0xd;
        *puVar5 = uval_2;
      }
      if (DAT_1004300c < 0xd) {
        val_3 = 0xd - DAT_1004300c;
        if ((int)DAT_101394b4 + (4 - (int)arg_1) < 100000) {
          uval_2 = *DAT_101394b4;
          DAT_101394b4 = DAT_101394b4 + 1;
          uval_4 = DAT_1012942c | ((&DAT_101394b0)[-val_3] & uval_2) << ((uint8_t)DAT_1004300c & 0x1f);
          DAT_1012942c = uval_2 >> ((uint8_t)val_3 & 0x1f);
          DAT_1004300c = 0x20 - val_3;
          puVar5[1] = uval_4;
        }
        else {
          puVar5[1] = 0xffffffff;
        }
      }
      else {
        uval_2 = DAT_1013947c & DAT_1012942c;
        DAT_1012942c = DAT_1012942c >> 0xd;
        DAT_1004300c = DAT_1004300c - 0xd;
        puVar5[1] = uval_2;
      }
      puVar5 = puVar5 + 2;
      uval_1 = uval_1 - 1;
    } while (uval_1 != 0);
  }
  DAT_1013a0b8 = arg_3;
  DAT_10129420 = arg_2;
  thunk_FUN_10015a50(DAT_10129424);
  return ((int)(local_4 + ((int)local_4 >> 0x1f & 7U)) >> 3) + (uint32_t)((local_4 & 7) != 0);
}


