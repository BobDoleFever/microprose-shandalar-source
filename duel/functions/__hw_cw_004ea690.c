/*
 * Decompiled function: __hw_cw
 * Entry Point: 004ea690
 * Size: 431 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Debug */

undefined4 __hw_cw(uint arg_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = (ushort)((arg_1 & 0x10) != 0);
  if ((arg_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((arg_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((arg_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((arg_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((arg_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = arg_1 & 0x300;
  if (uVar2 < 0x101) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
  }
  else if (uVar2 == 0x200) {
    uVar1 = uVar1 | 0x800;
  }
  else if (uVar2 == 0x300) {
    uVar1 = uVar1 | 0xc00;
  }
  uVar2 = arg_1 & 0x30000;
  if (uVar2 == 0) {
    uVar2 = uVar1 | 0x300;
    uVar1 = (ushort)uVar2;
  }
  else if (uVar2 == 0x10000) {
    uVar2 = uVar1 | 0x200;
    uVar1 = (ushort)uVar2;
  }
  if ((arg_1 & 0x40000) != 0) {
    uVar2 = uVar1 | 0x1000;
    uVar1 = (ushort)uVar2;
  }
  return CONCAT22((short)(uVar2 >> 0x10),uVar1);
}


