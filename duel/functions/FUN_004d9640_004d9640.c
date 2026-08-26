/*
 * Decompiled function: FUN_004d9640
 * Entry Point: 004d9640
 * Size: 224 bytes
 */
#include "duel.h"


uint * FUN_004d9640(uint *arg1,uint *arg2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = arg1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_004d965c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_004d968f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x004d96ab;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_004d965c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x004d96ab;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x004d96ab;
    }
  }
LAB_004d968f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x004d96ab:
  do {
    if (((uint)arg2 & 3) == 0) {
      do {
        uVar2 = *arg2;
        uVar4 = *arg2;
        arg2 = arg2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_004d9718:
            *(byte *)puVar5 = (byte)uVar4;
            return arg1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return arg1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return arg1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return arg1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*arg2;
    uVar4 = (uint)bVar1;
    arg2 = (uint *)((int)arg2 + 1);
    if (bVar1 == 0) goto LAB_004d9718;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


