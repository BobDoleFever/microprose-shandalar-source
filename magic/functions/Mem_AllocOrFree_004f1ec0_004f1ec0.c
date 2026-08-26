/*
 * Decompiled function: Mem_AllocOrFree_004f1ec0
 * Entry Point: 004f1ec0
 * Size: 11 bytes
 */
#include "magic.h"


void Mem_AllocOrFree_004f1ec0(int *arg_1,int arg_2,int arg_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *arg_2_00;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int in_stack_00000024;
  int iStack_18;
  int *piStack_c;
  
  if (DAT_005300ac == 0) {
    piStack_c = malloc(0x32000);
    DAT_0063eef0 = piStack_c;
    DAT_0063eeec = malloc(0x32000);
    DAT_005300ac = 1;
  }
  else {
    piStack_c = DAT_0063eef0;
  }
  arg_2_00 = DAT_0063eeec;
  if (arg_3 < arg_2) {
    do {
      iVar4 = arg_3 * arg_3;
      piVar5 = arg_1 + iVar4;
      piVar6 = piStack_c;
      piVar7 = arg_1;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          piVar1 = piVar6 + arg_3 * 2;
          piVar2 = piVar5;
          piVar3 = piVar7;
          while (piVar3 = piVar3 + 1, piVar3 < piVar7 + arg_3) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[arg_3] = *piVar3 - *piVar2;
            piVar1 = piVar1 + arg_3 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar6 = *piVar7 + *piVar2;
          piVar6[arg_3] = *piVar7 - *piVar2;
          iStack_18 = iStack_18 + -1;
          piVar6 = piVar6 + 1;
          piVar7 = piVar3;
        } while (iStack_18 != 0);
      }
      piVar5 = arg_1 + iVar4 * 3;
      piVar6 = arg_1 + iVar4 * 2;
      piVar7 = arg_2_00;
      iStack_18 = arg_3;
      if (0 < arg_3) {
        do {
          piVar1 = piVar7 + arg_3 * 2;
          piVar2 = piVar5;
          piVar3 = piVar6;
          while (piVar3 = piVar3 + 1, piVar3 < piVar6 + arg_3) {
            *piVar1 = *piVar3 + *piVar2;
            piVar1[arg_3] = *piVar3 - *piVar2;
            piVar1 = piVar1 + arg_3 * 2;
            piVar2 = piVar2 + 1;
          }
          piVar5 = piVar2 + 1;
          *piVar7 = *piVar6 + *piVar2;
          piVar7[arg_3] = *piVar6 - *piVar2;
          iStack_18 = iStack_18 + -1;
          piVar7 = piVar7 + 1;
          piVar6 = piVar3;
        } while (iStack_18 != 0);
      }
      iVar4 = arg_3 * 2;
      Mem_AllocOrFree_004f2110(piStack_c,arg_2_00,arg_1,arg_3,iVar4,iVar4,iVar4);
      arg_3 = iVar4;
    } while (iVar4 < in_stack_00000024);
  }
  return;
}


