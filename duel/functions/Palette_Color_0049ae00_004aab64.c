/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004aab64
 * Size: 1904 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  byte bVar1;
  undefined4 uVar2;
  uint arg_8;
  int iVar3;
  int iVar4;
  uint arg_9;
  uint arg_10;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined *arg_18;
  int *arg_20;
  byte local_e8;
  byte bStack_e7;
  uint local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint local_d0 [50];
  int local_8;
  
  if (flags == 0x74) {
    if (spell_id == DAT_00676510) {
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
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (spell_id == DAT_0068ecb0)) {
      if (DAT_0068ecd0 == -1) {
        FUN_00434660(s_prompts_txt_00506384,s_MAGICAL_HACK_00506374);
        arg_20 = &local_d8;
        uVar2 = 1;
        arg_18 = &DAT_006679f0;
        arg_17 = 0;
        arg_16 = 0;
        arg_15 = 0;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        iVar4 = -1;
        iVar3 = -1;
        arg_10 = 0;
        arg_9 = 0;
        arg_8 = FUN_004521e2(spell_id,target_id);
        iVar3 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,2,0x200,0x7f,0,0,arg_8,arg_9,arg_10,iVar3,iVar4,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18,uVar2,arg_20);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_d8;
          *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_d4;
          (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        }
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = DAT_0068ecd0;
        *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = DAT_0068eccc;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
      if (DAT_00681ea4 != 1) {
        local_8 = FUN_00439892(5);
        local_8 = local_8 + 1;
        if (spell_id == DAT_00676510) {
          iVar3 = FUN_00444c48(spell_id,(undefined4 *)
                                        (&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                               s_Magical_Hack_005063bc,(1 << ((byte)local_8 & 0x1f) & 0xffU) << 8,1)
          ;
          if (iVar3 == -1) {
            local_8 = -1;
            DAT_00681ea4 = 1;
          }
          else {
            bStack_e7 = (byte)((uint)iVar3 >> 8);
            iVar4 = FUN_0048c367(bStack_e7);
            local_e8 = (byte)iVar3;
            iVar3 = FUN_0048c367(local_e8);
            *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = iVar4 * 0x100 + iVar3;
          }
        }
        else {
          local_e4 = *(uint *)(&DAT_00618b54 +
                              *(int *)(&DAT_004ff590 +
                                      *(int *)(&DAT_006826c4 +
                                              *(int *)(&DAT_00682718 +
                                                      spell_id * 0x5b20 + target_id * 0x120) *
                                              0x5b20 + *(int *)(&DAT_0068271c +
                                                               spell_id * 0x5b20 + target_id * 0x120
                                                               ) * 0x120) * 0x34) * 0x98);
          if (local_e4 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            if (((&DAT_006826f8)
                 [*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                  *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) * 0x120] & 2) != 0
               ) {
              iVar3 = FUN_0048c367((byte)local_e4);
              bVar1 = FUN_004af74c(*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                                   *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),
                                   iVar3);
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
            *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) =
                 local_dc * 0x100 + local_e0;
            if (DAT_0066aaf4 != 1) {
              FUN_00434660(s_prompts_txt_0050639c,s_LANDWORDS_00506390);
              Mem_AllocOrFree_004d9630(local_d0,(uint *)s_Hacking_005063a8);
              FUN_004d9640(local_d0,(uint *)(&DAT_006679f0 + (local_e0 * 5 + -5) * 0x32));
              FUN_004d9640(local_d0,(uint *)&DAT_005063b4);
              FUN_004d9640(local_d0,(uint *)(&DAT_006679f0 + (local_dc * 5 + 0x2d) * 0x32));
              Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,
                         *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),local_d0,0)
              ;
            }
          }
        }
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
    }
    if (flags == 0x71) {
      local_d8 = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      local_d4 = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x1e);
      }
      *(uint *)(&DAT_006826f8 + local_d8 * 0x5b20 + local_d4 * 0x120) =
           *(uint *)(&DAT_006826f8 + local_d8 * 0x5b20 + local_d4 * 0x120) | 2;
      FUN_004aaa93(local_d8,local_d4,
                   (uint)(byte)(&DAT_006826e4)[spell_id * 0x5b20 + target_id * 0x120],
                   (&DAT_006826e5)[spell_id * 0x5b20 + target_id * 0x120]);
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


