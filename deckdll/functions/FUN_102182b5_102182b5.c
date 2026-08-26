/*
 * Decompiled function: FUN_102182b5
 * Entry Point: 102182b5
 * Size: 75 bytes
 */
#include "deckdll.h"


void FUN_102182b5(void)

{
  char cVar1;
  int val_2;
  int val_3;
  
  DAT_1004a826 = 9;
  DAT_1004a828 = 0x1ff;
  DAT_1004a82c = 0x100;
  val_3 = 0;
  val_2 = 0x800;
  do {
    *(int16_t *)((int)&DAT_10046810 + val_3) = 0xffff;
    val_3 = val_3 + 3;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  cVar1 = '\0';
  val_3 = 0;
  val_2 = 0x100;
  do {
    (&DAT_10046812)[val_3] = cVar1;
    cVar1 = cVar1 + '\x01';
    val_3 = val_3 + 3;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  return;
}


