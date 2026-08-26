/*
 * Decompiled function: FUN_0046e852
 * Entry Point: 0046e852
 * Size: 1226 bytes
 */
#include "duel.h"


undefined4 FUN_0046e852(int arg1,int arg2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  cVar1 = (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20];
  if (cVar1 != '\0') {
    if ((((&DAT_006826f8)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0) &&
       ((&DAT_004ff594)[iVar2 * 0x34] != -0x80)) {
      if ((cVar1 != '\x04') &&
         ((((&DAT_004ff594)[iVar2 * 0x34] & 2) != 0 &&
          (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)))) {
        DAT_0068eeac = DAT_0068eeac + 1;
      }
      if (((&DAT_004ff594)[iVar2 * 0x34] & 0x47) != 0) {
        FUN_0048cac9();
        DAT_0066642c = 0;
        DAT_0068ecb0 = arg1;
        DAT_00690c48 = arg2;
        DAT_00690310 = 1 - arg1;
        DAT_0068ecfc = 0xffffffff;
        FUN_0048c5a8(0x77);
        if (0 < DAT_0066642c) {
          *(uint *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
          FUN_0048cb7f();
          return 0;
        }
        cVar1 = (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20];
        FUN_0048cb7f();
      }
      if (((&DAT_006826f8)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
        if (cVar1 == '\x04') {
          FUN_0046f18f((*(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0x1000) >> 0xc,
                       *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20));
        }
        else {
          if ((cVar1 != '\x03') && (DAT_0066aaf4 != 1)) {
            if (((&DAT_004ff594)[*(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2)
                == 0) {
              if (((&DAT_004ff594)[*(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
                  0x38) == 0) {
                FUN_0048d00c(1);
              }
            }
            else {
              FUN_0048d00c(0x19);
            }
          }
          FUN_0046f02d(arg1,arg2);
          if (cVar1 == '\x03') {
            FUN_0048e8a8(DAT_00666458,0xd5,s_Card_s__to_Graveyard_004f9750,0);
          }
        }
      }
    }
    FUN_0048cac9();
    uVar4 = DAT_0068edd0;
    uVar3 = DAT_00666754;
    DAT_00666754 = arg1;
    DAT_0068edd0 = arg2;
    if (((&DAT_004ff594)[iVar2 * 0x34] & 0x47) != 0) {
      FUN_0048e8a8(DAT_00666458,0xd4,s_Card_leaving_play_004f9768,0);
    }
    DAT_00666754 = uVar3;
    DAT_0068edd0 = uVar4;
    FUN_0048cb7f();
    if (((&DAT_004ff594)[iVar2 * 0x34] & 2) != 0) {
      *(int *)(&DAT_0068ee80 + arg1 * 4) = *(int *)(&DAT_0068ee80 + arg1 * 4) + -1;
    }
    if (((&DAT_004ff594)[iVar2 * 0x34] & 0x40) != 0) {
      (&DAT_0068ee88)[arg1] = (&DAT_0068ee88)[arg1] + -1;
    }
    if (((&DAT_004ff594)[iVar2 * 0x34] & 4) != 0) {
      *(int *)(&DAT_0068ee90 + arg1 * 4) = *(int *)(&DAT_0068ee90 + arg1 * 4) + -1;
    }
    *(undefined4 *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
    (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(undefined4 *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    if (DAT_0066aaf4 != 1) {
      FUN_00450eb8(arg1,arg2,7,2);
    }
    FUN_0046ed1c(arg1,arg2);
    if (((&DAT_004ff594)[iVar2 * 0x34] & 0x47) != 0) {
      FUN_0048b64f();
    }
  }
  return 0;
}


