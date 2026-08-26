/*
 * Decompiled function: FUN_0050ec90
 * Entry Point: 0050ec90
 * Size: 123 bytes
 */
#include "magic.h"


void FUN_0050ec90(undefined4 arg_1,int arg_2,int arg_3)

{
  undefined4 *puVar1;
  int iVar2;
  size_t _Size;
  
  if (arg_3 == 8) {
    _Size = 0x42c;
  }
  else {
    _Size = 0x2c;
  }
  puVar1 = malloc(_Size);
  *puVar1 = 0x28;
  iVar2 = 0;
  puVar1[1] = arg_1;
  puVar1[2] = -arg_2;
  *(undefined2 *)(puVar1 + 3) = 1;
  *(short *)((int)puVar1 + 0xe) = (short)arg_3;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  if (arg_3 == 8) {
    puVar1[8] = 0x100;
    puVar1[9] = 0x100;
    puVar1 = puVar1 + 10;
    do {
      *(short *)puVar1 = (short)iVar2;
      puVar1 = (undefined4 *)((int)puVar1 + 2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    return;
  }
  puVar1[8] = 0;
  puVar1[9] = 0;
  return;
}


