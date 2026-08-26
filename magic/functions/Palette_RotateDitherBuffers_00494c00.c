/*
 * Decompiled function: Palette_RotateDitherBuffers
 * Entry Point: 00494c00
 * Size: 38 bytes
 */
#include "magic.h"


void Palette_RotateDitherBuffers(undefined4 *arg1,int arg2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = *arg1;
  puVar4 = arg1;
  puVar3 = arg1;
  for (uVar2 = arg2 * 4 - 4U >> 2; puVar3 = puVar3 + 1, uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *puVar3;
    puVar4 = puVar4 + 1;
  }
  arg1[arg2 + -1] = uVar1;
  return;
}


