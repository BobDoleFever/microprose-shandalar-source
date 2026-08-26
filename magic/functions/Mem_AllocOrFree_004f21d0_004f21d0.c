/*
 * Decompiled function: Mem_AllocOrFree_004f21d0
 * Entry Point: 004f21d0
 * Size: 11 bytes
 */
#include "magic.h"


undefined1 *
Mem_AllocOrFree_004f21d0
          (undefined1 *arg_1,int *arg_2,int arg_3,int arg_4,int *arg_5,int *arg_6,int arg_7,
          undefined4 arg_8,int arg_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int iStack_1c;
  uint uStack_18;
  int iStack_14;
  int *piStack_10;
  int *piStack_c;
  
  if (DAT_0061d7e4 == 0) {
    iVar1 = -0x400;
    do {
      if (iVar1 < 1) {
        PTR_DAT_005300b0[iVar1] = 0;
      }
      else {
        iVar2 = iVar1 >> 2;
        if (0xfe < iVar2) {
          iVar2 = 0xff;
        }
        PTR_DAT_005300b0[iVar1] = (char)iVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x1c00);
    DAT_0061d7e4 = 1;
  }
  if (arg_1 == (undefined1 *)0x0) {
    arg_1 = malloc(arg_3 * arg_3 * 3 + 0x10);
  }
  iStack_14 = 0;
  if (0 < arg_4) {
    piStack_10 = arg_6;
    piStack_c = arg_5;
    puVar4 = arg_1;
    do {
      piVar5 = piStack_c;
      piVar6 = piStack_10;
      if (arg_9 != 0) {
        iVar1 = (iStack_14 / 2) * arg_7;
        piVar5 = arg_5 + iVar1;
        piVar6 = arg_6 + iVar1;
      }
      uStack_18 = 0;
      if (0 < arg_3) {
        do {
          iVar1 = *arg_2;
          if (arg_9 == 0) {
            iVar2 = *piVar6;
            iVar2 = (iVar2 >> 3) + (iVar2 >> 1) + iVar2;
            iStack_1c = *piVar5;
          }
          else {
            if ((uStack_18 & 1) == 0) {
              iStack_1c = *piVar5;
              iVar2 = *piVar6;
            }
            else {
              bVar7 = arg_3 - uStack_18 != 1;
              iStack_1c = (piVar5[bVar7] + *piVar5) / 2;
              iVar2 = (piVar6[bVar7] + *piVar6) / 2;
            }
            iVar2 = (iVar2 >> 3) + (iVar2 >> 1) + iVar2;
          }
          iVar3 = iVar2 + -0x333 + iVar1;
          iVar2 = iVar1 + -0x400 + iStack_1c * 2;
          *puVar4 = PTR_DAT_005300b0[iVar2];
          puVar4[1] = PTR_DAT_005300b0
                      [((((iVar2 >> 4) - (iVar1 >> 2)) - (iVar2 >> 2)) - (iVar3 >> 1)) + iVar1 * 2];
          puVar4[2] = PTR_DAT_005300b0[iVar3];
          if ((arg_9 == 0) || ((uStack_18 & 1) != 0)) {
            piVar5 = piVar5 + 1;
            piVar6 = piVar6 + 1;
          }
          uStack_18 = uStack_18 + 1;
          arg_2 = arg_2 + 1;
          puVar4 = puVar4 + 3;
        } while ((int)uStack_18 < arg_3);
      }
      piStack_10 = piStack_10 + arg_7;
      piStack_c = piStack_c + arg_7;
      iStack_14 = iStack_14 + 1;
    } while (iStack_14 < arg_4);
  }
  return arg_1;
}


