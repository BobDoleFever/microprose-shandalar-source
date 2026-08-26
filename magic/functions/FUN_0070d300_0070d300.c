/*
 * Decompiled function: FUN_0070d300
 * Entry Point: 0070d300
 * Size: 146 bytes
 */
#include "magic.h"


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0070d300(uint arg_1)

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
  
  if (DAT_00536885 != '\0') {
    arg_1 = arg_1 + 1 >> 1;
  }
  LOCK();
  UNLOCK();
  uVar3 = DAT_0053687c;
  puVar4 = (undefined4 *)DAT_0053686c;
  DAT_0053686c = (undefined1 *)register0x00000010;
  _DAT_00536870 = arg_1;
  do {
    puVar5 = puVar4;
    if (DAT_00536874 == '\0') {
      puVar4[-1] = 0x70d32c;
      cVar1 = FUN_0070d392(arg_1,uVar3,*puVar4);
      puVar5 = puVar4 + 1;
      arg_1 = arg_1_00;
      uVar3 = arg_2;
      if (cVar1 == -0x70) {
        *puVar4 = 0x70d33c;
        cVar1 = FUN_0070d392(arg_1_00,arg_2,puVar4[1]);
        puVar5 = puVar4 + 2;
        arg_1 = extraout_ECX;
        uVar3 = extraout_EDX;
        if (cVar1 != '\0') {
          DAT_00536874 = cVar1 + -1;
          goto LAB_0070d350;
        }
        DAT_00536875 = -0x70;
        puVar5 = puVar4 + 2;
        cVar1 = DAT_00536875;
      }
    }
    else {
LAB_0070d350:
      DAT_00536874 = DAT_00536874 + -1;
      cVar1 = DAT_00536875;
    }
    DAT_00536875 = cVar1;
    if (DAT_00536885 == '\0') {
      *unaff_EDI = DAT_00536875;
      unaff_EDI = unaff_EDI + 1;
    }
    else {
      uVar2 = CONCAT11(DAT_00536875,DAT_00536875) & 0xff0f;
      *(ushort *)unaff_EDI = CONCAT11((byte)(uVar2 >> 0xc),(char)uVar2);
      unaff_EDI = unaff_EDI + 2;
    }
    _DAT_00536870 = _DAT_00536870 - 1;
    puVar4 = puVar5;
    if (_DAT_00536870 == 0) {
      DAT_0053687c = uVar3;
      LOCK();
      DAT_0053686c = (undefined1 *)puVar5;
      UNLOCK();
      return;
    }
  } while( true );
}


