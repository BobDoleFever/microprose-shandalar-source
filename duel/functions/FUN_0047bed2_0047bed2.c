/*
 * Decompiled function: FUN_0047bed2
 * Entry Point: 0047bed2
 * Size: 739 bytes
 */
#include "duel.h"


undefined4 FUN_0047bed2(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  uint local_8;
  
  if (arg_3 == 1) {
    uVar2 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x71) {
    uVar2 = FUN_0047a090(arg_1,arg_2,0x71,0);
  }
  else if (arg_3 == 0x73) {
    uVar2 = FUN_0047a090(arg_1,arg_2,0x73,0);
  }
  else {
    if (arg_3 == 0x6d) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Get_mana__004f9b44);
      iVar1 = (&DAT_0068ee78)[arg_1];
      if (iVar1 != 7) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Draw_a_card__004f9b60);
      }
      else {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Draw_a_card__004f9b50);
      }
      local_c = (uint)(iVar1 == 7);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cancel__004f9b70);
      if (DAT_00666748 == 0) {
        local_8 = 0;
      }
      else if (DAT_0068f220 == 0) {
        if (arg_1 == DAT_00676510) {
          local_8 = FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,local_c);
        }
        else {
          local_8 = local_c;
        }
      }
      else {
        local_8 = 0;
      }
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      if (local_8 == 0) {
        uVar2 = FUN_0047a090(arg_1,arg_2,0x6d,0);
        return uVar2;
      }
      if (local_8 == 1) {
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        FUN_0049b1eb(arg_1,0,1);
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
        DAT_0068f0f4 = 0xffffffff;
      }
      else {
        DAT_00681ea4 = 1;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 1)) {
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
      FUN_00487ce1(arg_1);
    }
    if (arg_3 == 0x7f) {
      uVar2 = FUN_0047a090(arg_1,arg_2,0x7f,0);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


