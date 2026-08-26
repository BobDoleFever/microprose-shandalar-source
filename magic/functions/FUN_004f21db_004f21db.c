/*
 * Decompiled function: FUN_004f21db
 * Entry Point: 004f21db
 * Size: 549 bytes
 */
#include "magic.h"


undefined1 * FUN_004f21db(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  int *piVar7;
  bool in_ZF;
  bool bVar8;
  uint uStack00000004;
  int iStack00000008;
  int *piStack0000000c;
  int *piStack00000010;
  undefined1 *in_stack_00000020;
  int *in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int *in_stack_00000030;
  int *in_stack_00000034;
  int in_stack_00000038;
  int in_stack_00000040;
  
  if (in_ZF) {
    iVar2 = -0x400;
    do {
      if (iVar2 < 1) {
        PTR_DAT_005300b0[iVar2] = 0;
      }
      else {
        iVar3 = iVar2 >> 2;
        if (0xfe < iVar3) {
          iVar3 = 0xff;
        }
        PTR_DAT_005300b0[iVar2] = (char)iVar3;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x1c00);
    DAT_0061d7e4 = 1;
  }
  if (in_stack_00000020 == (undefined1 *)0x0) {
    in_stack_00000020 = malloc(in_stack_00000028 * in_stack_00000028 * 3 + 0x10);
  }
  iStack00000008 = 0;
  if (0 < in_stack_0000002c) {
    piStack0000000c = in_stack_00000034;
    piStack00000010 = in_stack_00000030;
    puVar5 = in_stack_00000020;
    do {
      piVar6 = piStack00000010;
      piVar7 = piStack0000000c;
      if (in_stack_00000040 != 0) {
        iVar2 = (iStack00000008 / 2) * in_stack_00000038;
        piVar6 = in_stack_00000030 + iVar2;
        piVar7 = in_stack_00000034 + iVar2;
      }
      uStack00000004 = 0;
      if (0 < in_stack_00000028) {
        do {
          iVar2 = *in_stack_00000024;
          if (in_stack_00000040 == 0) {
            iVar3 = *piVar7;
            iVar3 = (iVar3 >> 3) + (iVar3 >> 1) + iVar3;
            iVar1 = *piVar6;
          }
          else {
            if ((uStack00000004 & 1) == 0) {
              iVar1 = *piVar6;
              iVar3 = *piVar7;
            }
            else {
              bVar8 = in_stack_00000028 - uStack00000004 != 1;
              iVar1 = (piVar6[bVar8] + *piVar6) / 2;
              iVar3 = (piVar7[bVar8] + *piVar7) / 2;
            }
            iVar3 = (iVar3 >> 3) + (iVar3 >> 1) + iVar3;
          }
          iVar4 = iVar3 + -0x333 + iVar2;
          iVar3 = iVar2 + -0x400 + iVar1 * 2;
          *puVar5 = PTR_DAT_005300b0[iVar3];
          puVar5[1] = PTR_DAT_005300b0
                      [((((iVar3 >> 4) - (iVar2 >> 2)) - (iVar3 >> 2)) - (iVar4 >> 1)) + iVar2 * 2];
          puVar5[2] = PTR_DAT_005300b0[iVar4];
          if ((in_stack_00000040 == 0) || ((uStack00000004 & 1) != 0)) {
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          uStack00000004 = uStack00000004 + 1;
          in_stack_00000024 = in_stack_00000024 + 1;
          puVar5 = puVar5 + 3;
        } while ((int)uStack00000004 < in_stack_00000028);
      }
      piStack0000000c = piStack0000000c + in_stack_00000038;
      piStack00000010 = piStack00000010 + in_stack_00000038;
      iStack00000008 = iStack00000008 + 1;
    } while (iStack00000008 < in_stack_0000002c);
  }
  return in_stack_00000020;
}


