/*
 * Decompiled function: FUN_0050eb90
 * Entry Point: 0050eb90
 * Size: 132 bytes
 */
#include "magic.h"


void FUN_0050eb90(int arg_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_320;
  undefined1 local_31c;
  undefined4 local_31b;
  
  local_320 = DAT_005326d8;
  puVar3 = &local_31b;
  for (iVar2 = 0xc6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_31c = 0;
  local_31b._0_1_ = 0xff;
  puVar1 = (undefined1 *)((int)&local_31b + 1);
  puVar3 = (undefined4 *)&DAT_0070a450;
  do {
    puVar4 = puVar3 + 1;
    *puVar1 = *(undefined1 *)puVar3;
    puVar1[1] = *(undefined1 *)((int)puVar3 + 1);
    puVar1[2] = *(undefined1 *)((int)puVar3 + 2);
    puVar1 = puVar1 + 3;
    puVar3 = puVar4;
  } while (puVar4 < &DAT_0070a850);
  _write(arg_1,&local_320,0x306);
  return;
}


