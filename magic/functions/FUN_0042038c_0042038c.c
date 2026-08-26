/*
 * Decompiled function: FUN_0042038c
 * Entry Point: 0042038c
 * Size: 1052 bytes
 */
#include "magic.h"


undefined4 FUN_0042038c(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  undefined4 *puVar1;
  short sVar2;
  undefined2 uVar3;
  int arg_2_00;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_a8;
  int local_a4;
  int local_a0;
  undefined4 uStack_9c;
  short local_98 [2];
  undefined4 auStack_94 [3];
  short local_88;
  short local_86;
  short local_78;
  short local_76;
  short local_68;
  short local_66;
  short local_58;
  short local_56;
  short local_48;
  short local_46;
  short local_38;
  short local_36;
  short local_28;
  short local_26;
  short local_18;
  short local_16;
  int local_c;
  int *local_8;
  
  local_8 = &DAT_005387b8;
  for (local_a4 = 0; local_a4 < 9; local_a4 = local_a4 + 1) {
    puVar1 = (undefined4 *)local_8[local_a4];
    (&uStack_9c)[local_a4 * 4] = *puVar1;
    *(undefined4 *)(local_98 + local_a4 * 8) = puVar1[1];
    auStack_94[local_a4 * 4] = puVar1[2];
    auStack_94[local_a4 * 4 + 1] = puVar1[3];
    sVar2 = Ai_Util_004c3bc4((int)local_98[local_a4 * 8]);
    local_98[local_a4 * 8] = sVar2;
    uVar3 = Ai_Util_004c3bc4((int)*(short *)((int)auStack_94 + local_a4 * 0x10 + -2));
    *(undefined2 *)((int)auStack_94 + local_a4 * 0x10 + -2) = uVar3;
  }
  arg_2_00 = Ai_Util_004c3bc4(arg_2);
  iVar4 = Ai_Util_004c3bc4(arg_3);
  iVar5 = Ai_Util_004c3bc4(arg_4);
  iVar6 = Ai_Util_004c3bc4(arg_5);
  Sprite_DrawScaled(arg_1,(arg_2_00 + iVar5 / 2) - (int)local_98[0] / 2,
                    iVar4 - ((int)local_98[1] - (int)local_46),(int)local_98[0],(int)local_98[1],
                    *local_8);
  local_a0 = (int)local_98[0] / 2 + iVar5 / 2 + arg_2_00;
  for (local_c = ((arg_2_00 + iVar5 / 2) - (int)local_98[0] / 2) - (int)local_48; arg_2_00 < local_c
      ; local_c = local_c - local_48) {
    Sprite_DrawScaled(arg_1,local_c,iVar4,(int)local_48,(int)local_46,local_8[5]);
    Sprite_DrawScaled(arg_1,local_a0,iVar4,(int)local_48,(int)local_46,local_8[5]);
    local_a0 = local_a0 + local_48;
  }
  Sprite_DrawScaled(arg_1,arg_2_00,iVar4,(int)local_88,(int)local_86,local_8[1]);
  Sprite_DrawScaled(arg_1,(iVar5 + arg_2_00) - (int)local_78,iVar4,(int)local_78,(int)local_76,
                    local_8[2]);
  iVar7 = (int)local_18;
  for (local_a8 = local_86 + iVar4; local_a8 < (iVar6 + iVar4) - (int)local_66;
      local_a8 = local_a8 + local_16) {
    Sprite_DrawScaled(arg_1,arg_2_00,local_a8,(int)local_18,(int)local_16,local_8[8]);
    Sprite_DrawScaled(arg_1,(iVar5 + arg_2_00) - iVar7,local_a8,(int)local_38,(int)local_36,
                      local_8[6]);
  }
  Sprite_DrawScaled(arg_1,arg_2_00,(iVar6 + iVar4) - (int)local_66,(int)local_68,(int)local_66,
                    local_8[3]);
  Sprite_DrawScaled(arg_1,(iVar5 + arg_2_00) - (int)local_58,(iVar6 + iVar4) - (int)local_56,
                    (int)local_58,(int)local_56,local_8[4]);
  local_a0 = ((iVar5 + arg_2_00) - (int)local_58) - (int)local_28;
  iVar4 = iVar4 + (iVar6 - local_26);
  for (local_c = local_68 + arg_2_00; local_c < arg_2_00 + iVar5 / 2; local_c = local_c + local_28)
  {
    Sprite_DrawScaled(arg_1,local_c,iVar4,(int)local_28,(int)local_26,local_8[7]);
    Sprite_DrawScaled(arg_1,local_a0,iVar4,(int)local_28,(int)local_26,local_8[7]);
    local_a0 = local_a0 - local_28;
  }
  return 0;
}


