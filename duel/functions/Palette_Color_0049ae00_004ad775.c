/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004ad775
 * Size: 2213 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags,int height)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((spell_id == DAT_00676504) && (height == 0)) {
      uVar2 = 0;
    }
    else if (((byte)DAT_00681eb0 & 4) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
      if (((byte)DAT_00681eb0 & 4) == 0) {
        FUN_00434660(s_prompts_txt_00506468,s_HEALING_SALVE_00506458);
        iVar3 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_18);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_18;
          *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_14;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = height;
        }
      }
      else {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        cVar1 = -1;
        local_8 = 0;
        DAT_00681ea4 = -1;
        local_10 = 0;
        while ((((char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] < height &&
                (local_8 == 0)) && ((DAT_00681ea4 != 1 && (local_10 == 0))))) {
          FUN_00434660(s_prompts_txt_00506484,s_HEALING_SALVE_00506474);
          _sprintf(&DAT_005f6810,&DAT_00667aea,
                   (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + 1,height);
          iVar3 = Action_ValidateTarget_0041e2a2
                            (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,
                             0xffffffff,0,0,0,&DAT_005f6810,3,&local_18);
          if (iVar3 == 0) {
            if (local_14 == -1) {
              DAT_00681ea4 = 1;
            }
            else {
              local_8 = 1;
            }
          }
          else if ((((&DAT_006826d2)[local_18 * 0x5b20 + local_14 * 0x120] == cVar1) &&
                   (*(int *)(&DAT_006826e8 + local_18 * 0x5b20 + local_14 * 0x120) == local_1c)) ||
                  (cVar1 == -1)) {
            cVar1 = (&DAT_006826d2)[local_18 * 0x5b20 + local_14 * 0x120];
            local_1c = *(int *)(&DAT_006826e8 + local_18 * 0x5b20 + local_14 * 0x120);
            *(uint *)(&DAT_006826cc + local_18 * 0x5b20 + local_14 * 0x120) =
                 *(uint *)(&DAT_006826cc + local_18 * 0x5b20 + local_14 * 0x120) | 0x200000;
            FUN_00451482(0,0x20);
            *(int *)(&DAT_00682718 +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_18;
            *(int *)(&DAT_0068271c +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_14;
            (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
            if ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] == '\x13') {
              local_10 = local_10 + 1;
            }
            if (DAT_0066643c == 1) {
              while (((char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] < height &&
                     (local_10 == 0))) {
                *(int *)(&DAT_00682718 +
                        target_id * 0x120 +
                        spell_id * 0x5b20 +
                        (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_18
                ;
                *(int *)(&DAT_0068271c +
                        target_id * 0x120 +
                        spell_id * 0x5b20 +
                        (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_14
                ;
                (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
                     (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
                if ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] == '\x13') {
                  local_10 = 1;
                }
              }
            }
          }
          else if (DAT_0066aaf4 != 1) {
            Mem_AllocOrFree_00450eed(s_Illegal_target__prevent_damage_t_00506490);
            Sleep(2000);
            Mem_AllocOrFree_00450eed(&DAT_005064c0);
          }
        }
        for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) *
                   0x120 + *(int *)(&DAT_00682718 +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ) * 0x120 +
                        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ) * 0x5b20) & 0xffcfffff;
        }
        if ((local_10 != 0) && (local_10 = 0, DAT_0066aaf4 != 1)) {
          Mem_AllocOrFree_00450eed(s_WARNING___target_array_overflow_i_005064c4);
          Sleep(5000);
          Mem_AllocOrFree_00450eed(&DAT_005064f8);
        }
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      while ('\0' < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20]) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + -1;
        local_18 = *(int *)(&DAT_00682718 +
                           target_id * 0x120 +
                           spell_id * 0x5b20 +
                           (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8);
        local_14 = *(int *)(&DAT_0068271c +
                           target_id * 0x120 +
                           spell_id * 0x5b20 +
                           (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8);
        if (((byte)DAT_00681eb0 & 4) == 0) {
          (&DAT_00681ea8)[local_18] =
               (&DAT_00681ea8)[local_18] +
               *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
        }
        else {
          iVar3 = Rules_ParseFilter_0041c0ab
                            (local_18,local_14,(undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                             DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0);
          if (iVar3 == 0) {
            DAT_00681ea4 = 1;
          }
          else if (*(int *)(&DAT_006826e4 + local_18 * 0x5b20 + local_14 * 0x120) != 0) {
            *(int *)(&DAT_006826e4 + local_18 * 0x5b20 + local_14 * 0x120) =
                 *(int *)(&DAT_006826e4 + local_18 * 0x5b20 + local_14 * 0x120) + -1;
          }
        }
      }
      FUN_0046e571(spell_id,target_id,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


