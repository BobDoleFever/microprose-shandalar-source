/*
 * Decompiled function: FUN_10218300
 * Entry Point: 10218300
 * Size: 146 bytes
 */
#include "deckdll.h"


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10218300(uint32_t arg_1)

{
  char cVar1;
  uint16_t uval_2;
  uint32_t arg_1_00;
  uint32_t extraout_ECX;
  uint32_t arg_2;
  uint32_t extraout_EDX;
  uint32_t uval_3;
  int32_t *puVar4;
  int32_t *puVar5;
  char *unaff_EDI;
  
  if (DAT_1004a835 != '\0') {
    arg_1 = arg_1 + 1 >> 1;
  }
  LOCK();
  UNLOCK();
  uval_3 = DAT_1004a82c;
  puVar4 = (int32_t *)DAT_1004a81c;
  DAT_1004a81c = (uint8_t *)register0x00000010;
  _DAT_1004a820 = arg_1;
  do {
    puVar5 = puVar4;
    if (DAT_1004a824 == '\0') {
      puVar4[-1] = 0x1021832c;
      cVar1 = FUN_10218392(arg_1,uval_3,*puVar4);
      puVar5 = puVar4 + 1;
      arg_1 = arg_1_00;
      uval_3 = arg_2;
      if (cVar1 == -0x70) {
        *puVar4 = 0x1021833c;
        cVar1 = FUN_10218392(arg_1_00,arg_2,puVar4[1]);
        puVar5 = puVar4 + 2;
        arg_1 = extraout_ECX;
        uval_3 = extraout_EDX;
        if (cVar1 != '\0') {
          DAT_1004a824 = cVar1 + -1;
          goto LAB_10218350;
        }
        DAT_1004a825 = -0x70;
        puVar5 = puVar4 + 2;
        cVar1 = DAT_1004a825;
      }
    }
    else {
LAB_10218350:
      DAT_1004a824 = DAT_1004a824 + -1;
      cVar1 = DAT_1004a825;
    }
    DAT_1004a825 = cVar1;
    if (DAT_1004a835 == '\0') {
      *unaff_EDI = DAT_1004a825;
      unaff_EDI = unaff_EDI + 1;
    }
    else {
      uval_2 = CONCAT11(DAT_1004a825,DAT_1004a825) & 0xff0f;
      *(uint16_t *)unaff_EDI = CONCAT11((uint8_t)(uval_2 >> 0xc),(char)uval_2);
      unaff_EDI = unaff_EDI + 2;
    }
    _DAT_1004a820 = _DAT_1004a820 - 1;
    puVar4 = puVar5;
    if (_DAT_1004a820 == 0) {
      DAT_1004a82c = uval_3;
      LOCK();
      DAT_1004a81c = (uint8_t *)puVar5;
      UNLOCK();
      return;
    }
  } while( true );
}


