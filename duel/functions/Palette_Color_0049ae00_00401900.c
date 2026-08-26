/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 00401900
 * Size: 936 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_110;
  int local_108;
  uint local_104 [63];
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (flags == 0x71) {
      FUN_00434660(s_prompts_txt_004f2040,s_BALANCE_004f2038);
      Mem_AllocOrFree_004d9630(local_104,(uint *)&DAT_006679f0);
      do {
        Mem_AllocOrFree_004d9630((uint *)&DAT_006679f0,local_104);
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_00666408;
          if (DAT_00666408 <= DAT_0066640c) {
            iVar2 = DAT_0066640c;
          }
          if (iVar2 <= local_8) break;
          iVar2 = FUN_0048a33f(0,local_8);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120) * 0x34] & 1) != 0)) {
            local_108 = local_108 + 1;
          }
          iVar2 = FUN_0048a33f(1,local_8);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006881e4 + local_8 * 0x120) * 0x34] & 1) != 0)) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        if (local_110 < local_108) {
          FUN_004687a3(0);
        }
        else if (local_108 < local_110) {
          FUN_004687a3(1);
        }
        FUN_00451482(0,0xff);
      } while (local_110 != local_108);
      do {
        if (DAT_0068ee7c < DAT_0068ee78) {
          Palette_Color_0049ae00(0,0,0);
        }
        if (DAT_0068ee78 < DAT_0068ee7c) {
          Palette_Color_0049ae00(1,0,0);
        }
      } while (DAT_0068ee78 != DAT_0068ee7c);
      do {
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_00666408;
          if (DAT_00666408 <= DAT_0066640c) {
            iVar2 = DAT_0066640c;
          }
          if (iVar2 <= local_8) break;
          iVar2 = FUN_0048a33f(0,local_8);
          if (((iVar2 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120) * 0x34] & 2) != 0)) &&
             ((&DAT_006826e0)[local_8 * 0x120] != '\x03')) {
            local_108 = local_108 + 1;
          }
          iVar2 = FUN_0048a33f(1,local_8);
          if (((iVar2 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006881e4 + local_8 * 0x120) * 0x34] & 2) != 0)) &&
             ((&DAT_006826e0)[local_8 * 0x120] != '\x03')) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        Mem_AllocOrFree_004d9630((uint *)&DAT_006679f0,(uint *)&DAT_00667aea);
        if (local_110 < local_108) {
          iVar2 = FUN_00468383(0);
          FUN_0046e571(0,iVar2,3);
        }
        if (local_108 < local_110) {
          iVar2 = FUN_00468383(1);
          FUN_0046e571(1,iVar2,3);
        }
        FUN_00451482(0,0xff);
      } while (local_110 != local_108);
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


