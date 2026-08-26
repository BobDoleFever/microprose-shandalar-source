/*
 * Decompiled function: Pic_Load_0042a1c9
 * Entry Point: 004bcfca
 * Size: 2641 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Load_0042a1c9(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint uVar2;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (flags == 0x74) {
    if (DAT_00676510 == spell_id) {
      uVar2 = (DAT_006664f4 | _DAT_006664f0) & 2;
    }
    else {
      if (DAT_0066aaf4 == 1) {
        DAT_0068f2c8 = FUN_00439892(2);
        FUN_0043064a();
      }
      else {
        FUN_004307b2();
      }
      *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = DAT_0068f2c8;
      uVar2 = *(uint *)(&DAT_006664f0 + DAT_0068f2c8 * 4) & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      if ((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) {
        local_14[1] = 0;
        local_14[0] = 0;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          local_20 = 0;
          while( true ) {
            if ((499 < local_20) || (*(int *)(&DAT_0068f370 + local_20 * 4 + spell_id * 2000) == -1)
               ) goto LAB_004bd0fc;
            if (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_20 * 4 + local_18 * 2000) * 0x34] &
                2) != 0) break;
            local_20 = local_20 + 1;
          }
          local_14[local_18] = local_14[local_18] + 1;
LAB_004bd0fc:
        }
        if ((local_14[0] == 0) || (local_14[1] == 0)) {
          if (local_14[0] == 0) {
            local_24 = 1;
          }
          else {
            local_24 = 0;
          }
        }
        else {
          local_24 = Ai_Subsystem_004cc56d
                               (spell_id,spell_id,target_id,-1,-1,
                                s_From_my_graveyard__From_opponent_00508854,0);
          if (local_24 == 2) {
            DAT_00681ea4 = 1;
          }
        }
        if (DAT_00681ea4 != 1) {
          if (local_24 == 0) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_00508890);
          }
          else {
            FUN_00448412(&DAT_005f6810);
            FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_0050888c);
          }
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_graveyard__Pick_a_creature_00508898);
          local_1c = 0;
          do {
            local_14[3] = Palette_Subsystem_004a5722
                                    (spell_id,(int *)(&DAT_0068f370 + local_24 * 2000),500,
                                     &DAT_005f6810,0,s_Cancel_005088b4);
            if (local_14[3] == -1) {
              DAT_00681ea4 = 1;
            }
            else if (((&DAT_004ff594)
                      [*(int *)(&DAT_0068f370 + local_14[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0
                    ) {
              if (DAT_0066aaf4 != 1) {
                Mem_AllocOrFree_00450eed(s_Illegal_Target_005088bc);
                Sleep(2000);
                Mem_AllocOrFree_00450eed(&DAT_005088cc);
              }
            }
            else {
              local_1c = local_1c + 1;
            }
          } while ((DAT_00681ea4 != 1) && (local_1c == 0));
        }
      }
      else {
        local_24 = *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
        local_14[3] = FUN_0040800f(local_24,2);
      }
      if ((DAT_00681ea4 == 1) ||
         (((local_14[3] == -1 || (*(int *)(&DAT_0068f370 + local_14[3] * 4 + local_24 * 2000) == -1)
           ) || (((&DAT_004ff594)
                  [*(int *)(&DAT_0068f370 + local_14[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0))))
      {
        DAT_00681ea4 = 1;
      }
      else {
        local_14[2] = Pic_Subsystem_00451291
                                (spell_id,*(int *)(&DAT_0068f370 + local_14[3] * 4 + local_24 * 2000
                                                  ));
        if (local_14[2] != -1) {
          *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) = local_14[2];
          (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)spell_id;
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffefff;
          if (local_24 != 0) {
            *(uint *)(&DAT_006826cc +
                     *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                     (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
                 *(uint *)(&DAT_006826cc +
                          *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) |
                 0x1000;
          }
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) |
               0x20;
          *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(int *)(&DAT_00682720 + target_id * 0x120 + spell_id * 0x5b20) = local_24;
          *(int *)(&DAT_00682724 + target_id * 0x120 + spell_id * 0x5b20) = local_14[3];
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20];
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20);
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
    }
    if (flags == 0x71) {
      local_14[3] = *(int *)(&DAT_00682724 + target_id * 0x120 + spell_id * 0x5b20);
      if (*(int *)(&DAT_0068f370 +
                  local_14[3] * 4 +
                  *(int *)(&DAT_00682720 + target_id * 0x120 + spell_id * 0x5b20) * 2000) == -1) {
        FUN_0046e571(spell_id,target_id,2);
        *(undefined4 *)
         (&DAT_006826c4 +
         *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0xffffffff;
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046f116(*(int *)(&DAT_00682720 + target_id * 0x120 + spell_id * 0x5b20),local_14[3]);
        *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 0;
        Pic_Subsystem_0042ac1f
                  ((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20));
        *(undefined2 *)
         (&DAT_006826d8 +
         *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) = 0xffff;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((((DAT_0068f230 == 0xd4) && (DAT_00690c48 == target_id)) &&
         ((DAT_0068ecb0 == spell_id &&
          (((&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] != -1 &&
           (*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) != -1))))
         )) && (DAT_00666754 == spell_id)) &&
       ((DAT_0068edd0 == target_id && (spell_id == DAT_00681ec4)))) {
      if (flags == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (flags == 0x7e) {
        if (*(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) != 0) {
          *(uint *)(&DAT_006826f8 +
                   *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826f8 +
                        *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 8;
        }
        cVar1 = (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20];
        (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
        FUN_0046e571((int)cVar1,*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),1);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


