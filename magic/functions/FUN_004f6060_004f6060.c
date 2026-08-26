/*
 * Decompiled function: FUN_004f6060
 * Entry Point: 004f6060
 * Size: 278 bytes
 */
#include "magic.h"


void FUN_004f6060(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,undefined4 arg_6)

{
  undefined1 uVar3;
  int iVar1;
  undefined4 *puVar2;
  uint uVar4;
  uint uVar5;
  
  if ((arg_1 != 0) && ((((arg_2 == 0x20 || (arg_2 == 0x18)) || (arg_2 == 0x10)) || (arg_2 == 8)))) {
    iVar1 = (int)(arg_2 + (arg_2 >> 0x1f & 7U)) >> 3;
    uVar4 = arg_3 * iVar1 >> 0x1f;
    uVar4 = 4 - (((arg_3 * iVar1 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4);
    uVar5 = (int)uVar4 >> 0x1f;
    puVar2 = (undefined4 *)
             ((arg_3 * iVar1 + (((uVar4 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5)) * arg_5 +
              arg_4 * iVar1 + arg_1);
    if (arg_2 == 0x20) {
      *puVar2 = arg_6;
    }
    else {
      uVar3 = (undefined1)((uint)arg_6 >> 8);
      if (arg_2 == 0x18) {
        *(char *)puVar2 = (char)((uint)arg_6 >> 0x10);
        *(undefined1 *)((int)puVar2 + 1) = uVar3;
        *(undefined1 *)((int)puVar2 + 2) = (undefined1)arg_6;
      }
      else if (arg_2 == 0x10) {
        *(undefined1 *)puVar2 = uVar3;
        *(undefined1 *)((int)puVar2 + 1) = (undefined1)arg_6;
      }
      else if (arg_2 == 8) {
        *(undefined1 *)puVar2 = (undefined1)arg_6;
      }
    }
  }
  return;
}


