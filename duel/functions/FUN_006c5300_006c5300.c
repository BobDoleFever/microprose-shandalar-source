/*
 * Decompiled function: FUN_006c5300
 * Entry Point: 006c5300
 * Size: 146 bytes
 */
#include "duel.h"


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_006c5300(uint arg_1)

{
  char cVar1;
  ushort uVar2;
  uint arg_1_00;
  uint extraout_ECX;
  uint arg_2;
  uint extraout_EDX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *unaff_EDI;
  
  if (DAT_004ff179 != '\0') {
    arg_1 = arg_1 + 1 >> 1;
  }
  LOCK();
  UNLOCK();
  uVar3 = DAT_004ff170;
  puVar4 = (undefined4 *)DAT_004ff160;
  DAT_004ff160 = (undefined1 *)register0x00000010;
  _DAT_004ff164 = arg_1;
  do {
    puVar5 = puVar4;
    if (DAT_004ff168 == '\0') {
      puVar4[-1] = 0x6c532c;
      cVar1 = FUN_006c5392(arg_1,uVar3,*puVar4);
      puVar5 = puVar4 + 1;
      arg_1 = arg_1_00;
      uVar3 = arg_2;
      if (cVar1 == -0x70) {
        *puVar4 = 0x6c533c;
        cVar1 = FUN_006c5392(arg_1_00,arg_2,puVar4[1]);
        puVar5 = puVar4 + 2;
        arg_1 = extraout_ECX;
        uVar3 = extraout_EDX;
        if (cVar1 != '\0') {
          DAT_004ff168 = cVar1 + -1;
          goto LAB_006c5350;
        }
        DAT_004ff169 = -0x70;
        puVar5 = puVar4 + 2;
        cVar1 = DAT_004ff169;
      }
    }
    else {
LAB_006c5350:
      DAT_004ff168 = DAT_004ff168 + -1;
      cVar1 = DAT_004ff169;
    }
    DAT_004ff169 = cVar1;
    if (DAT_004ff179 == '\0') {
      *unaff_EDI = DAT_004ff169;
      unaff_EDI = unaff_EDI + 1;
    }
    else {
      uVar2 = CONCAT11(DAT_004ff169,DAT_004ff169) & 0xff0f;
      *(ushort *)unaff_EDI = CONCAT11((byte)(uVar2 >> 0xc),(char)uVar2);
      unaff_EDI = unaff_EDI + 2;
    }
    _DAT_004ff164 = _DAT_004ff164 - 1;
    puVar4 = puVar5;
    if (_DAT_004ff164 == 0) {
      DAT_004ff170 = uVar3;
      LOCK();
      DAT_004ff160 = (undefined1 *)puVar5;
      UNLOCK();
      return;
    }
  } while( true );
}


