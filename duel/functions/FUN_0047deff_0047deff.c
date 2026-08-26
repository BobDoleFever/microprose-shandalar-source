/*
 * Decompiled function: FUN_0047deff
 * Entry Point: 0047deff
 * Size: 1366 bytes
 */
#include "duel.h"


undefined4 FUN_0047deff(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_18;
  uint local_14 [2];
  uint local_c;
  uint local_8;
  
  if (param_3 == 0x73) {
    if ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (param_3 == 0x6d) {
      if (DAT_0068f220 == 0) {
        FUN_0042b6b0(param_1,0,3);
        if (DAT_00681ea4 != 1) {
          FUN_00434660(s_prompts_txt_004f9cf8,s_ARENA_004f9cf0);
          for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
            uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0
                                 ,0,&DAT_006679f0,param_1 == local_18,
                                 ((param_1 == 0) - 1 & (int)&local_c - (int)local_14) +
                                 (int)local_14);
            iVar2 = FUN_0041e2a2(param_1,param_1,param_1,0x200,2,0,0,uVar1);
            if (iVar2 == 0) {
              DAT_00681ea4 = 1;
            }
          }
          if (DAT_00681ea4 != 1) {
            if (((((char)local_c == '\0') && ((local_8 & 0xffff) == 0)) &&
                ((local_14[0] & 0xffffff) == 0)) && (local_14[1] == 0)) {
              *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
            }
            else {
              *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
            }
          }
        }
      }
      else {
        DAT_00681ea4 = 1;
      }
    }
    if (param_3 == 0x72) {
      local_c = *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) >> 0x18;
      local_8 = (*(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xff0000) >> 0x10;
      local_14[0] = (uint)(byte)(&DAT_006826e5)[param_2 * 0x120 + param_1 * 0x5b20];
      local_14[1] = *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xff;
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_c,local_8,0,1,1,1,0x200,2,0,0,uVar1);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(local_14[0],local_14[1],0,0,0,0,0x200,2,0,0,uVar1);
      if ((iVar2 == 0) || (iVar3 == 0)) {
        if ((iVar2 == 0) || (iVar3 != 0)) {
          if (((iVar2 == 0) && (iVar3 != 0)) &&
             (*(uint *)(&DAT_006826cc + local_14[0] * 0x5b20 + local_14[1] * 0x120) =
                   *(uint *)(&DAT_006826cc + local_14[0] * 0x5b20 + local_14[1] * 0x120) | 0x10,
             *(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) != -1)) {
            uVar1 = FUN_0048b81a(local_c,local_8,0x32,0xffffffff);
            FUN_004af950(local_14[0],local_14[1],uVar1,local_c,local_8);
          }
        }
        else {
          *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) | 0x10;
          if (*(int *)(&DAT_006826c4 + local_14[1] * 0x120 + local_14[0] * 0x5b20) != -1) {
            uVar1 = FUN_0048b81a(local_14[0],local_14[1],0x32,0xffffffff);
            FUN_004af950(local_c,local_8,uVar1,local_14[0],local_14[1]);
          }
        }
      }
      else {
        *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) | 0x10;
        *(uint *)(&DAT_006826cc + local_14[0] * 0x5b20 + local_14[1] * 0x120) =
             *(uint *)(&DAT_006826cc + local_14[0] * 0x5b20 + local_14[1] * 0x120) | 0x10;
        uVar1 = FUN_0048b81a(local_c,local_8,0x32,0xffffffff);
        uVar4 = FUN_0048b81a(local_14[0],local_14[1],0x32,0xffffffff);
        FUN_004af950(local_c,local_8,uVar4,local_14[0],local_14[1]);
        FUN_004af950(local_14[0],local_14[1],uVar1,local_c,local_8);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


