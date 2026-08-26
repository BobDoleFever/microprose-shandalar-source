/*
 * Decompiled function: FUN_10218392
 * Entry Point: 10218392
 * Size: 242 bytes
 */
#include "deckdll.h"


int32_t __fastcall FUN_10218392(int32_t arg_1,uint32_t arg_2,int32_t arg_3)

{
  int val_1;
  uint8_t flag_2;
  uint32_t uval_3;
  uint32_t extraout_ECX;
  uint32_t uval_4;
  uint16_t *unaff_ESI;
  uint16_t *puVar5;
  
  uval_3 = DAT_1004a836;
  if (&stack0x00000000 == (uint8_t *)0x1004ac37) {
    uval_4 = DAT_1004a830 >> (0x10 - DAT_1004a834 & 0x1f);
    for (flag_2 = DAT_1004a834; (char)flag_2 < DAT_1004a826; flag_2 = flag_2 + 0x10) {
      puVar5 = unaff_ESI;
      if (PTR_DAT_1004baec <= unaff_ESI) {
        (*DAT_1013f170)();
        puVar5 = DAT_1013eefc;
      }
      unaff_ESI = puVar5 + 1;
      DAT_1004a830 = (uint32_t)*puVar5;
      uval_4 = uval_4 | DAT_1004a830 << (flag_2 & 0x1f);
    }
    DAT_1004a834 = flag_2 - DAT_1004a826;
    uval_4 = uval_4 & DAT_1004a828;
    uval_3 = uval_4;
    if ((int)arg_2 <= (int)uval_4) {
      uval_4 = DAT_1004a836;
      uval_3 = arg_2;
    }
    while( true ) {
      val_1 = uval_4 * 3;
      if (*(short *)((int)&DAT_10046810 + val_1) == -1) break;
      uval_4 = CONCAT22((short)(uval_4 >> 0x10),*(short *)((int)&DAT_10046810 + val_1));
      arg_3 = CONCAT31((int3)((uint32_t)val_1 >> 8),(&DAT_10046812)[val_1]);
    }
    DAT_1004a83a = (&DAT_10046812)[val_1];
    (&DAT_10046812)[arg_2 * 3] = DAT_1004a83a;
    *(short *)((int)&DAT_10046810 + arg_2 * 3) = (short)DAT_1004a836;
    if ((int)DAT_1004a828 < (int)(arg_2 + 1)) {
      DAT_1004a826 = DAT_1004a826 + '\x01';
      DAT_1004a828 = DAT_1004a828 << 1 | 1;
    }
    if (DAT_1004a827 < DAT_1004a826) {
      FUN_102182b5();
      uval_3 = extraout_ECX;
    }
  }
  DAT_1004a836 = uval_3;
                    /* WARNING: Treating indirect jump as return */
  return arg_3;
}


