/*
 * Decompiled function: FUN_10218245
 * Entry Point: 10218245
 * Size: 112 bytes
 */
#include "deckdll.h"


void __fastcall FUN_10218245(int32_t arg1,int32_t arg2)

{
  uint16_t uval_1;
  char cVar2;
  int val_3;
  int val_4;
  
  if (DAT_1004a810 == 0 && DAT_1004a814 == 0) {
    return;
  }
  DAT_1004a824 = 0;
  DAT_1004a825 = 0;
  DAT_1004a81c = &DAT_1004ac3b;
  if (PTR_DAT_1004baec <= DAT_1013eefc) {
    (*DAT_1013f170)(arg2,arg1);
  }
  uval_1 = *DAT_1013eefc;
  DAT_1004a830 = (uint32_t)uval_1;
  if (0xb < (uint8_t)uval_1) {
    DAT_1004a830 = CONCAT31((uint3)(uint8_t)(uval_1 >> 8),0xb);
  }
  DAT_1004a827 = (uint8_t)DAT_1004a830;
  DAT_1004a834 = 8;
  DAT_1004a826 = 9;
  DAT_1004a828 = 0x1ff;
  DAT_1004a82c = 0x100;
  val_4 = 0;
  val_3 = 0x800;
  DAT_1013eefc = DAT_1013eefc + 1;
  do {
    *(int16_t *)((int)&DAT_10046810 + val_4) = 0xffff;
    val_4 = val_4 + 3;
    val_3 = val_3 + -1;
  } while (val_3 != 0);
  cVar2 = '\0';
  val_4 = 0;
  val_3 = 0x100;
  do {
    (&DAT_10046812)[val_4] = cVar2;
    cVar2 = cVar2 + '\x01';
    val_4 = val_4 + 3;
    val_3 = val_3 + -1;
  } while (val_3 != 0);
  return;
}


