/*
 * Decompiled function: FUN_004ab3b4
 * Entry Point: 004ab3b4
 * Size: 1926 bytes
 */
#include "duel.h"


undefined4 FUN_004ab3b4(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  undefined1 local_d0 [200];
  int local_8;
  
  if (param_3 == 0x74) {
    if (DAT_00676510 == param_1) {
      if (DAT_0068ecd0 == -1) {
        FUN_0043071d(0);
        uVar2 = 1;
      }
      else {
        uVar2 = 99;
      }
    }
    else if ((DAT_0068ecd0 == -1) || (DAT_00666458 != DAT_00676510)) {
      FUN_0043071d(0);
      uVar2 = 1;
    }
    else {
      uVar2 = 99;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      if (DAT_0068ecd0 == -1) {
        FUN_00434660(s_prompts_txt_005063dc,s_SLEIGHT_OF_MIND_005063cc);
        uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_d8);
        iVar4 = FUN_0041e2a2(param_1,2,2,0x200,0x7f,0,0,uVar2);
        if (iVar4 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_d8;
          *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_d4;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_0068ecd0;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
      if (DAT_00681ea4 != 1) {
        local_8 = FUN_00439892(5);
        local_8 = local_8 + 1;
        if (((DAT_00676510 == param_1) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
          uVar3 = FUN_00444c48(param_1,&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120,
                               s_Sleight_of_Mind_00506418,(1 << ((byte)local_8 & 0x1f) & 0xffU) << 8
                               ,0);
          if (uVar3 == 0xffffffff) {
            DAT_00681ea4 = 1;
          }
          else {
            iVar4 = FUN_0048c367(uVar3 >> 8 & 0xff);
            iVar5 = FUN_0048c367(uVar3 & 0xff);
            *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = iVar4 * 0x100 + iVar5;
          }
        }
        else {
          local_e4 = *(uint *)(&DAT_00618b1c +
                              *(int *)(&DAT_004ff590 +
                                      *(int *)(&DAT_006826c4 +
                                              *(int *)(&DAT_0068271c +
                                                      param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                                              *(int *)(&DAT_00682718 +
                                                      param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20)
                                      * 0x34) * 0x98);
          if (local_e4 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            if (((&DAT_006826f8)
                 [*(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] & 4) != 0)
            {
              uVar2 = FUN_0048c367(local_e4);
              bVar1 = FUN_004af7bb(*(undefined4 *)
                                    (&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                                   *(undefined4 *)
                                    (&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),uVar2);
              local_e4 = 1 << (bVar1 & 0x1f);
            }
            do {
              local_e0 = FUN_00439892(5);
              local_e0 = local_e0 + 1;
            } while ((local_e4 & 1 << ((byte)local_e0 & 0x1f)) == 0);
            do {
              local_dc = FUN_00439892(5);
              local_dc = local_dc + 1;
            } while (local_dc == local_e0);
            if (DAT_0066aaf4 == 1) {
              DAT_0068f2c8 = local_e0;
              FUN_0043064a();
              DAT_0068f2c8 = local_dc;
              FUN_0043064a();
            }
            else {
              FUN_004307b2();
              local_e0 = DAT_0068f2c8;
              FUN_004307b2();
              local_dc = DAT_0068f2c8;
            }
            *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
                 local_dc * 0x100 + local_e0;
            if (DAT_0066aaf4 != 1) {
              FUN_00434660(s_prompts_txt_005063f4,s_COLORWORDS_005063e8);
              FUN_004d9630(local_d0,s_Sleighting_00506400);
              FUN_004d9640(local_d0,&DAT_006679f0 + (local_e0 * 5 + -5) * 0x32);
              FUN_004d9640(local_d0,&DAT_00506410);
              FUN_004d9640(local_d0,&DAT_006679f0 + (local_dc * 5 + 0x2d) * 0x32);
              FUN_0045102d(param_1,param_1,param_2,
                           *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),
                           local_d0,0);
            }
          }
        }
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      }
    }
    if (param_3 == 0x71) {
      local_d8 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_d4 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x1e);
      }
      *(uint *)(&DAT_006826f8 + local_d8 * 0x5b20 + local_d4 * 0x120) =
           *(uint *)(&DAT_006826f8 + local_d8 * 0x5b20 + local_d4 * 0x120) | 4;
      FUN_004ab2e3(local_d8,local_d4,(&DAT_006826e4)[param_2 * 0x120 + param_1 * 0x5b20],
                   (&DAT_006826e5)[param_2 * 0x120 + param_1 * 0x5b20]);
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


