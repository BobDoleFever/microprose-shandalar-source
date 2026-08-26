/*
 * Decompiled function: FUN_10002e20
 * Entry Point: 10002e20
 * Size: 11 bytes
 */
#include "deckdll.h"


uint8_t *
FUN_10002e20(uint8_t *arg_1,int *arg_2,int arg_3,int arg_4,int *arg_5,int *arg_6,int arg_7,
            int32_t arg_8,int arg_9)

{
  int val_1;
  int val_2;
  int val_3;
  uint8_t *puVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int iStack_1c;
  uint32_t uStack_18;
  int iStack_14;
  int *piStack_10;
  int *piStack_c;
  
  if (DAT_10103c94 == 0) {
    val_1 = -0x400;
    do {
      if (val_1 < 1) {
        PTR_DAT_10040458[val_1] = 0;
      }
      else {
        val_2 = val_1 >> 2;
        if (0xfe < val_2) {
          val_2 = 0xff;
        }
        PTR_DAT_10040458[val_1] = (char)val_2;
      }
      val_1 = val_1 + 1;
    } while (val_1 < 0x1c00);
    DAT_10103c94 = 1;
  }
  if (arg_1 == (uint8_t *)0x0) {
    arg_1 = malloc(arg_3 * arg_3 * 3 + 0x10);
  }
  iStack_14 = 0;
  if (0 < arg_4) {
    piStack_10 = arg_6;
    piStack_c = arg_5;
    puVar4 = arg_1;
    do {
      piVar5 = piStack_c;
      piVar6 = piStack_10;
      if (arg_9 != 0) {
        val_1 = (iStack_14 / 2) * arg_7;
        piVar5 = arg_5 + val_1;
        piVar6 = arg_6 + val_1;
      }
      uStack_18 = 0;
      if (0 < arg_3) {
        do {
          val_1 = *arg_2;
          if (arg_9 == 0) {
            val_2 = *piVar6;
            val_2 = (val_2 >> 3) + (val_2 >> 1) + val_2;
            iStack_1c = *piVar5;
          }
          else {
            if ((uStack_18 & 1) == 0) {
              iStack_1c = *piVar5;
              val_2 = *piVar6;
            }
            else {
              bVar7 = arg_3 - uStack_18 != 1;
              iStack_1c = (piVar5[bVar7] + *piVar5) / 2;
              val_2 = (piVar6[bVar7] + *piVar6) / 2;
            }
            val_2 = (val_2 >> 3) + (val_2 >> 1) + val_2;
          }
          val_3 = val_2 + -0x333 + val_1;
          val_2 = val_1 + -0x400 + iStack_1c * 2;
          *puVar4 = PTR_DAT_10040458[val_2];
          puVar4[1] = PTR_DAT_10040458
                      [((((val_2 >> 4) - (val_1 >> 2)) - (val_2 >> 2)) - (val_3 >> 1)) + val_1 * 2];
          puVar4[2] = PTR_DAT_10040458[val_3];
          if ((arg_9 == 0) || ((uStack_18 & 1) != 0)) {
            piVar5 = piVar5 + 1;
            piVar6 = piVar6 + 1;
          }
          uStack_18 = uStack_18 + 1;
          arg_2 = arg_2 + 1;
          puVar4 = puVar4 + 3;
        } while ((int)uStack_18 < arg_3);
      }
      piStack_10 = piStack_10 + arg_7;
      piStack_c = piStack_c + arg_7;
      iStack_14 = iStack_14 + 1;
    } while (iStack_14 < arg_4);
  }
  return arg_1;
}


