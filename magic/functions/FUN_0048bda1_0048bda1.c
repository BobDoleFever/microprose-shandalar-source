/*
 * Decompiled function: FUN_0048bda1
 * Entry Point: 0048bda1
 * Size: 208 bytes
 */
#include "magic.h"


undefined4 __thiscall FUN_0048bda1(void *this)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_retaddr;
  int iStack00000080;
  int in_stack_00000104;
  
  iVar5 = 0;
  puVar6 = (undefined4 *)register0x00000010;
  for (; this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar6 = in_EAX;
    puVar6 = puVar6 + 1;
  }
  iVar4 = in_stack_00000104 + -1;
  iStack00000080 = iVar4;
  puVar6 = &DAT_00676c90;
  for (iVar3 = 0x20; iVar1 = DAT_0053aaa0, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  do {
    iVar3 = iVar5 + 1;
    if (*(int *)(&stack0x00000000 + iVar5 * 4) == 0) {
      iVar4 = (&DAT_0053aaac)[iVar4 * 2];
    }
    else {
      iVar4 = (&DAT_0053aaa8)[iVar4 * 2];
    }
    iVar4 = iVar4 - iVar1;
    *(int *)((int)&stack0x00000080 + iVar3 * 4) = iVar4;
    if (iVar4 < 0) {
      iVar4 = (&DAT_00676c90)[iVar3];
      *(undefined4 *)(&stack0x00000000 + iVar3 * 4) = 1;
      (&DAT_00676c90)[iVar3] = iVar4 + 1;
      iVar2 = iVar5 * 4;
      *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar5 * 4) + -1;
      iVar4 = *(int *)((int)&stack0x00000080 + iVar2);
      iVar3 = iVar5;
      if (unaff_retaddr < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)(&stack0x00000000 + iVar2)) break;
        *(undefined4 *)(&stack0x00000000 + iVar2) = 1;
        iVar3 = iVar3 + -1;
        *(int *)(&stack0xfffffffc + iVar2) = *(int *)(&stack0xfffffffc + iVar2) + -1;
        iVar4 = *(int *)(&stack0x0000007c + iVar2);
        iVar2 = iVar2 + -4;
      } while (-1 < unaff_retaddr);
    }
    iVar5 = iVar3;
    if (unaff_retaddr < 0) {
      return 0;
    }
  } while( true );
}


