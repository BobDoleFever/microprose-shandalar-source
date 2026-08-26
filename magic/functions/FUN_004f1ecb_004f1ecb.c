/*
 * Decompiled function: FUN_004f1ecb
 * Entry Point: 004f1ecb
 * Size: 416 bytes
 */
#include "magic.h"


void FUN_004f1ecb(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *arg_2;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  int iStack00000004;
  int *piStack00000010;
  int *in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_00000040;
  
  if (in_ZF) {
    piStack00000010 = malloc(0x32000);
    DAT_0063eef0 = piStack00000010;
    DAT_0063eeec = malloc(0x32000);
    DAT_005300ac = 1;
  }
  else {
    piStack00000010 = DAT_0063eef0;
  }
  arg_2 = DAT_0063eeec;
  if (in_stack_00000028 < in_stack_00000024) {
    do {
      iVar4 = in_stack_00000028 * in_stack_00000028;
      piVar5 = in_stack_00000020 + iVar4;
      piVar6 = piStack00000010;
      piVar7 = in_stack_00000020;
      iStack00000004 = in_stack_00000028;
      if (0 < in_stack_00000028) {
        do {
          piVar1 = piVar6 + in_stack_00000028 * 2;
          piVar2 = piVar5;
          piVar3 = piVar7;
          while (piVar3 = piVar3 + 1, piVar3 < piVar7 + in_stack_00000028) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[in_stack_00000028] = *piVar3 - *piVar2;
            piVar1 = piVar1 + in_stack_00000028 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar6 = *piVar7 + *piVar2;
          piVar6[in_stack_00000028] = *piVar7 - *piVar2;
          iStack00000004 = iStack00000004 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = piVar3;
        } while (iStack00000004 != 0);
      }
      piVar5 = in_stack_00000020 + iVar4 * 3;
      piVar6 = in_stack_00000020 + iVar4 * 2;
      piVar7 = arg_2;
      iStack00000004 = in_stack_00000028;
      if (0 < in_stack_00000028) {
        do {
          piVar1 = piVar7 + in_stack_00000028 * 2;
          piVar2 = piVar5;
          piVar3 = piVar6;
          while (piVar3 = piVar3 + 1, piVar3 < piVar6 + in_stack_00000028) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[in_stack_00000028] = *piVar3 - *piVar2;
            piVar1 = piVar1 + in_stack_00000028 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar7 = *piVar6 + *piVar2;
          piVar7[in_stack_00000028] = *piVar6 - *piVar2;
          iStack00000004 = iStack00000004 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = piVar3;
        } while (iStack00000004 != 0);
      }
      iVar4 = in_stack_00000028 * 2;
      Mem_AllocOrFree_004f2110
                (piStack00000010,arg_2,in_stack_00000020,in_stack_00000028,iVar4,iVar4,iVar4);
      in_stack_00000028 = iVar4;
    } while (iVar4 < in_stack_00000040);
  }
  return;
}


