/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004a8d55
 * Size: 908 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  int local_8;
  
  if ((flags == 0x74) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    bVar1 = false;
    FUN_0043071d(0);
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      local_8 = 0;
      while ((local_8 < (int)(&DAT_00666408)[local_10] && (!bVar1))) {
        if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_10 * 0x5b20) != -1) &&
           (((((byte)*(undefined4 *)(&DAT_006826cc + local_8 * 0x120 + local_10 * 0x5b20) & 0x22) ==
              2 && (((&DAT_004ff594)
                     [*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_10 * 0x5b20) * 0x34] & 2) !=
                    0)) && ((&DAT_006826e0)[local_8 * 0x120 + local_10 * 0x5b20] == '\x02')))) {
          bVar1 = true;
        }
        local_8 = local_8 + 1;
      }
    }
    if (bVar1) {
      uVar2 = 99;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if ((flags == 0x6c) &&
       (((DAT_00690c48 == target_id && (DAT_0068ecb0 == spell_id)) &&
        ((DAT_00681eb0._1_1_ & 2) != 0)))) {
      bVar1 = false;
      do {
        FUN_00434660(s_prompts_txt_0050628c,s_DEATH_WARD_00506280);
        iVar3 = FUN_00468261(spell_id,spell_id,target_id);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        if ((&DAT_006826e0)
            [*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120] == '\x02') {
          bVar1 = true;
        }
        else if (DAT_0066aaf4 != 1) {
          Mem_AllocOrFree_00450eed(s_Illegal_target__not_dying___00506298);
          Sleep(2000);
          Mem_AllocOrFree_00450eed(&DAT_005062b4);
        }
      } while ((DAT_00681ea4 != 1) && (!bVar1));
    }
    if ((flags == 0x71) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
      iVar3 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,
                         0xffffffff,0,0,0);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0045962d(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


