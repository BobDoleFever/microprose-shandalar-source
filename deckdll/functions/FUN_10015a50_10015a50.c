/*
 * Decompiled function: FUN_10015a50
 * Entry Point: 10015a50
 * Size: 501 bytes
 */
#include "deckdll.h"


int32_t FUN_10015a50(int arg_1)

{
  int32_t *u_ptr_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  int *piVar8;
  uint32_t local_e0;
  int local_b8 [11];
  int32_t uStack_8c;
  int aiStack_30 [12];
  
  local_b8[0] = 0x100;
  local_b8[1] = 0x200;
  local_b8[2] = 0x400;
  piVar8 = local_b8 + 3;
  for (val_2 = 0x20; val_2 != 0; val_2 = val_2 + -1) {
    *piVar8 = 1;
    piVar8 = piVar8 + 1;
  }
  val_2 = arg_1 + -1;
  aiStack_30[1] = val_2;
  val_4 = 0;
  do {
    val_5 = val_4 + 1;
    if (local_b8[val_4 + 3] == 0) {
      val_3 = (&DAT_10129434)[val_2 * 2];
    }
    else {
      val_3 = (&DAT_10129430)[val_2 * 2];
    }
    val_2 = val_3 - DAT_1013a0b8;
    aiStack_30[val_4 + 2] = val_2;
    if (val_2 < 0) {
      val_2 = 0;
      local_e0 = 0;
      if (0 < val_5) {
        do {
          local_e0 = local_e0 | local_b8[val_2 + 3] << ((uint8_t)val_2 & 0x1f);
          val_2 = val_2 + 1;
        } while (val_2 < val_5);
      }
      val_6 = 0;
      val_2 = local_b8[-val_5];
      if (0 < val_2) {
        u_ptr_1 = (int32_t *)(DAT_10129420 + val_3 * 4);
        do {
          uval_7 = local_e0 | val_6 << ((uint8_t)val_5 & 0x1f);
          val_6 = val_6 + 1;
          (&DAT_101394bc)[uval_7 * 3] = val_5;
          (&DAT_101394b8)[uval_7 * 3] = *u_ptr_1;
          (&DAT_101394c0)[uval_7 * 3] = 0xffffffff;
        } while (val_6 < val_2);
      }
      local_b8[val_4 + 4] = 1;
      local_b8[val_4 + 3] = local_b8[val_4 + 3] + -1;
LAB_10015bf3:
      val_3 = val_4 * 4;
      val_2 = aiStack_30[val_4 + 1];
      val_5 = val_4;
      if (local_b8[3] < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)((int)local_b8 + val_3 + 0xc)) break;
        val_2 = *(int *)((int)aiStack_30 + val_3);
        *(int32_t *)((int)local_b8 + val_3 + 0xc) = 1;
        val_5 = val_5 + -1;
        *(int *)((int)local_b8 + val_3 + 8) = *(int *)((int)local_b8 + val_3 + 8) + -1;
        val_3 = val_3 + -4;
      } while (-1 < local_b8[3]);
    }
    else if (val_5 == 8) {
      val_5 = 0;
      uval_7 = 0;
      do {
        uval_7 = uval_7 | local_b8[val_5 + 3] << ((uint8_t)val_5 & 0x1f);
        val_5 = val_5 + 1;
      } while (val_5 < 8);
      uStack_8c = 1;
      (&DAT_101394b8)[uval_7 * 3] = 0x7fffffff;
      (&DAT_101394bc)[uval_7 * 3] = 8;
      (&DAT_101394c0)[uval_7 * 3] = val_2;
      local_b8[val_4 + 3] = local_b8[val_4 + 3] + -1;
      goto LAB_10015bf3;
    }
    val_4 = val_5;
    if (local_b8[3] < 0) {
      return 0;
    }
  } while( true );
}


