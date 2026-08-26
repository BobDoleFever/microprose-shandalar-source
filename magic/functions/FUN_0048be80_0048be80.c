/*
 * Decompiled function: FUN_0048be80
 * Entry Point: 0048be80
 * Size: 488 bytes
 */
#include "magic.h"


int FUN_0048be80(undefined4 *arg_1,uint *arg_2,int arg_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_8;
  
  local_8 = 0;
  DAT_0053aa90 = arg_2;
  DAT_0053aa94 = arg_2;
  iVar3 = DAT_0053aa9c + -1;
  DAT_0053aa98 = arg_3;
  DAT_00527b44 = 0;
  do {
    if (DAT_00527b44 == 0) {
      if ((int)DAT_0053aa90 - (int)DAT_0053aa94 < DAT_0053aa98) {
        DAT_00539e8c = *DAT_0053aa90;
        DAT_0053aa90 = DAT_0053aa90 + 1;
        DAT_00527b44 = 0x20;
        goto LAB_0048bf03;
      }
      uVar5 = 0xffffffff;
    }
    else {
LAB_0048bf03:
      uVar5 = (uint)((DAT_00539e8c & 1) != 0);
      DAT_00539e8c = DAT_00539e8c >> 1;
      DAT_00527b44 = DAT_00527b44 - 1;
    }
    if (uVar5 == 0xffffffff) {
      return local_8;
    }
    if (uVar5 == 0) {
      iVar1 = (&DAT_0053aaac)[iVar3 * 2];
    }
    else {
      iVar1 = (&DAT_0053aaa8)[iVar3 * 2];
    }
    iVar3 = iVar1 - DAT_0053aaa0;
    if (iVar3 < 0) {
      if (iVar1 == 0) {
        if (DAT_00527b44 < 10) {
          iVar3 = 10 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar5 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-iVar3] & uVar5) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar5 >> ((byte)iVar3 & 0x1f);
            DAT_00527b44 = 0x20 - iVar3;
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
        else {
          uVar4 = DAT_00539e60 & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> 10;
          DAT_00527b44 = DAT_00527b44 - 10;
        }
        if ((int)uVar4 < 0) {
          return local_8;
        }
        puVar2 = arg_1 + uVar4;
        for (uVar5 = uVar4 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *arg_1 = 0;
          arg_1 = arg_1 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)arg_1 = 0;
          arg_1 = (undefined4 *)((int)arg_1 + 1);
        }
        local_8 = local_8 + uVar4;
      }
      else {
        puVar2 = arg_1 + 1;
        local_8 = local_8 + 1;
        *arg_1 = *(undefined4 *)(DAT_0053aaa4 + iVar1 * 4);
      }
      iVar3 = DAT_0053aa9c + -1;
      arg_1 = puVar2;
    }
  } while( true );
}


