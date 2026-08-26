/*
 * Decompiled function: FUN_0048cac9
 * Entry Point: 0048cac9
 * Size: 182 bytes
 */
#include "duel.h"


void FUN_0048cac9(void)

{
  if (DAT_004fab4c < 0x20) {
    *(undefined4 *)(&DAT_00665ee0 + DAT_004fab4c * 0x28) = DAT_0068ecb0;
    *(undefined4 *)(&DAT_00665ee4 + DAT_004fab4c * 0x28) = DAT_00690c48;
    *(undefined4 *)(&DAT_00665ee8 + DAT_004fab4c * 0x28) = DAT_00681ecc;
    *(undefined4 *)(&DAT_00665eec + DAT_004fab4c * 0x28) = DAT_0068ee64;
    *(undefined4 *)(&DAT_00665ef0 + DAT_004fab4c * 0x28) = DAT_00690310;
    *(undefined4 *)(&DAT_00665ef4 + DAT_004fab4c * 0x28) = DAT_0068ecfc;
    *(undefined4 *)(&DAT_00665ef8 + DAT_004fab4c * 0x28) = DAT_0066642c;
    DAT_004fab4c = DAT_004fab4c + 1;
  }
  return;
}


