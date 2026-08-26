/*
 * Decompiled function: FUN_0048c070
 * Entry Point: 0048c070
 * Size: 1619 bytes
 */
#include "magic.h"


int FUN_0048c070(int *arg_1,uint *arg_2,int arg_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  byte local_8;
  
  DAT_0053aa90 = arg_2;
  if (((uint)arg_2 & 3) == 0) {
    DAT_00527b44 = 0;
    DAT_00539e8c = 0;
  }
  else {
    iVar5 = 4 - ((uint)arg_2 & 3);
    DAT_00527b44 = iVar5 * 8;
    DAT_0053aa90 = (uint *)(iVar5 + (int)arg_2);
    DAT_00539e8c = 0xffffffffU >> (0x20U - (char)DAT_00527b44 & 0x1f) & *arg_2;
  }
  piVar1 = arg_1;
  DAT_0053aa98 = arg_3;
  DAT_0053aa94 = arg_2;
  if (DAT_00527b44 < 8) {
    iVar5 = 8 - DAT_00527b44;
    if ((int)DAT_0053aa90 + (4 - (int)arg_2) < arg_3) {
      uVar2 = *DAT_0053aa90;
      DAT_0053aa90 = DAT_0053aa90 + 1;
      uVar7 = DAT_00539e8c | ((&DAT_00539e88)[-iVar5] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
      DAT_00539e8c = uVar2 >> ((byte)iVar5 & 0x1f);
      DAT_00527b44 = 0x20 - iVar5;
    }
    else {
      uVar7 = 0xffffffff;
    }
  }
  else {
    uVar7 = DAT_00539e68 & DAT_00539e8c;
    DAT_00539e8c = DAT_00539e8c >> 8;
    DAT_00527b44 = DAT_00527b44 - 8;
  }
  while (uVar7 != 0xffffffff) {
    iVar5 = (&DAT_00539e90)[uVar7 * 3];
    if (iVar5 < 0x7fffffff) {
      uVar2 = (&DAT_00539e94)[uVar7 * 3];
      local_8 = (byte)uVar2;
      if (iVar5 == -0x80000000) {
        uVar2 = uVar2 + 2;
        if (DAT_00527b44 < uVar2) {
          uVar2 = uVar2 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar3 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-uVar2] & uVar3) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar3 >> ((byte)uVar2 & 0x1f);
            DAT_00527b44 = 0x20;
            goto LAB_0048c281;
          }
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (&DAT_00539e88)[-uVar2] & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> ((byte)uVar2 & 0x1f);
LAB_0048c281:
          DAT_00527b44 = DAT_00527b44 - uVar2;
        }
        if ((int)uVar4 < 0) break;
        uVar7 = uVar4 << (8 - local_8 & 0x1f) | (int)uVar7 >> (local_8 & 0x1f);
        uVar2 = uVar7;
        piVar8 = piVar1;
        if (((uint)piVar1 & 4) == 0) {
LAB_0048c2bd:
          uVar3 = uVar2 >> 1;
          if (uVar3 != 0) {
            while (uVar3 = uVar3 - 1, uVar3 != 0) {
              piVar8[0] = 0;
              piVar8[1] = 0;
              piVar8 = piVar8 + 2;
            }
            piVar8[0] = 0;
            piVar8[1] = 0;
          }
          if ((uVar2 & 1) != 0) {
            *(undefined1 *)piVar8 = 0;
          }
        }
        else {
          *(undefined1 *)piVar1 = 0;
          piVar8 = piVar1 + 1;
          uVar2 = uVar7 - 1;
          if (uVar2 != 0 && 0 < (int)uVar7) goto LAB_0048c2bd;
        }
        piVar1 = piVar1 + uVar7;
        if (DAT_00527b44 < 8) {
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
LAB_0048c661:
            iVar5 = 8 - DAT_00527b44;
            uVar2 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar7 = DAT_00539e8c | ((&DAT_00539e88)[-iVar5] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar2 >> ((byte)iVar5 & 0x1f);
            DAT_00527b44 = 0x20 - iVar5;
          }
          else {
LAB_0048c65a:
            uVar7 = 0xffffffff;
          }
        }
        else {
          uVar7 = DAT_00539e68 & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> 8;
          DAT_00527b44 = DAT_00527b44 - 8;
        }
      }
      else {
        *piVar1 = iVar5;
        piVar1 = piVar1 + 1;
        if (DAT_00527b44 < uVar2) {
          uVar2 = uVar2 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar3 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-uVar2] & uVar3) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar3 >> ((byte)uVar2 & 0x1f);
            DAT_00527b44 = 0x20;
            goto LAB_0048c419;
          }
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (&DAT_00539e88)[-uVar2] & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> (local_8 & 0x1f);
LAB_0048c419:
          DAT_00527b44 = DAT_00527b44 - uVar2;
        }
        if (uVar4 == 0xffffffff) break;
        uVar7 = (int)uVar7 >> (local_8 & 0x1f) | uVar4 << (8 - local_8 & 0x1f);
      }
    }
    else {
      iVar5 = (&DAT_00539e98)[uVar7 * 3];
      do {
        if (DAT_00527b44 == 0) {
          if ((int)DAT_0053aa90 - (int)DAT_0053aa94 < DAT_0053aa98) {
            DAT_00539e8c = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            DAT_00527b44 = 0x20;
            goto LAB_0048c492;
          }
          uVar2 = 0xffffffff;
        }
        else {
LAB_0048c492:
          uVar2 = (uint)((DAT_00539e8c & 1) != 0);
          DAT_00539e8c = DAT_00539e8c >> 1;
          DAT_00527b44 = DAT_00527b44 - 1;
        }
        if (uVar2 == 0xffffffff) goto LAB_0048c5f9;
        if (uVar2 == 0) {
          iVar6 = (&DAT_0053aaac)[iVar5 * 2];
        }
        else {
          iVar6 = (&DAT_0053aaa8)[iVar5 * 2];
        }
        iVar5 = iVar6 - DAT_0053aaa0;
      } while (-1 < iVar5);
      if (iVar6 == 0) {
        if (DAT_00527b44 < 10) {
          iVar5 = 10 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar2 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar7 = DAT_00539e8c | ((&DAT_00539e88)[-iVar5] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar2 >> ((byte)iVar5 & 0x1f);
            DAT_00527b44 = 0x20 - iVar5;
          }
          else {
            uVar7 = 0xffffffff;
          }
        }
        else {
          uVar7 = DAT_00539e60 & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> 10;
          DAT_00527b44 = DAT_00527b44 - 10;
        }
        if (-1 < (int)uVar7) {
          uVar2 = uVar7;
          piVar8 = piVar1;
          if (((uint)piVar1 & 4) == 0) {
LAB_0048c5c3:
            uVar3 = uVar2 >> 1;
            if (uVar3 != 0) {
              while (uVar3 = uVar3 - 1, uVar3 != 0) {
                piVar8[0] = 0;
                piVar8[1] = 0;
                piVar8 = piVar8 + 2;
              }
              piVar8[0] = 0;
              piVar8[1] = 0;
            }
            if ((uVar2 & 1) != 0) {
              *(undefined1 *)piVar8 = 0;
            }
          }
          else {
            *(undefined1 *)piVar1 = 0;
            piVar8 = piVar1 + 1;
            uVar2 = uVar7 - 1;
            if (uVar2 != 0 && 0 < (int)uVar7) goto LAB_0048c5c3;
          }
          piVar1 = piVar1 + uVar7;
        }
      }
      else {
        *piVar1 = *(int *)(DAT_0053aaa4 + iVar6 * 4);
        piVar1 = piVar1 + 1;
      }
LAB_0048c5f9:
      if (DAT_00527b44 < 8) {
        if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) goto LAB_0048c661;
        goto LAB_0048c65a;
      }
      uVar7 = DAT_00539e68 & DAT_00539e8c;
      DAT_00539e8c = DAT_00539e8c >> 8;
      DAT_00527b44 = DAT_00527b44 - 8;
    }
  }
  return (int)piVar1 - (int)arg_1 >> 2;
}


