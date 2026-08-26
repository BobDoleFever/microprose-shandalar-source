/*
 * Decompiled function: FUN_004f1cfa
 * Entry Point: 004f1cfa
 * Size: 283 bytes
 */
#include "magic.h"


void FUN_004f1cfa(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  bool in_ZF;
  char in_SF;
  char in_OF;
  int iStack0000000c;
  int *in_stack_00000014;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_0000002c;
  
  iStack0000000c = in_EAX;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar4 = in_stack_00000014;
      piVar6 = in_stack_0000001c;
      while (piVar4 < in_stack_00000014 + in_stack_00000020 + -1) {
        piVar6 = piVar6 + in_stack_0000002c * 2;
        piVar1 = piVar4 + 1;
        piVar4 = piVar4 + 1;
        iVar2 = *in_stack_00000018;
        iVar5 = *piVar1 * 0xb504;
        iVar3 = iVar5;
        if (iVar2 != 0) {
          iVar3 = iVar5 + iVar2 * 0xb504;
          iVar5 = iVar5 + iVar2 * -0xb504;
        }
        in_stack_00000018 = in_stack_00000018 + 1;
        *piVar6 = iVar3 >> 0x10;
        piVar6[in_stack_0000002c] = iVar5 >> 0x10;
      }
      *in_stack_0000001c = (*in_stack_00000018 + *in_stack_00000014) * 0xb504 >> 0x10;
      iVar3 = *in_stack_00000014;
      iVar5 = *in_stack_00000018;
      in_stack_00000014 = piVar4 + 1;
      in_stack_00000018 = in_stack_00000018 + 1;
      iStack0000000c = iStack0000000c + -1;
      in_stack_0000001c[in_stack_0000002c] = (iVar3 - iVar5) * 0xb504 >> 0x10;
      in_stack_0000001c = in_stack_0000001c + 1;
    } while (iStack0000000c != 0);
  }
  return;
}


