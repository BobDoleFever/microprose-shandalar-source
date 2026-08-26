/*
 * Decompiled function: FUN_004f7bf6
 * Entry Point: 004f7bf6
 * Size: 283 bytes
 */
#include "magic.h"


undefined4 FUN_004f7bf6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
      while ((&DAT_006b3008)[arg_1] != 0) {
        Prompts_Load_0046fa40(arg_1,1,0);
      }
      for (local_c = 0; ((&DAT_006b2d90)[arg_1 * 0x10 + local_c] != -1 && (local_c < 0x10));
          local_c = local_c + 1) {
      }
      if (local_c < 0x10) {
        iVar2 = FUN_0046f5d1(arg_1);
        (&DAT_006b2d90)[arg_1 * 0x10 + local_c] =
             *(undefined4 *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg_1 * 0x5b20);
        *(undefined4 *)(&g_CardSlot_CardId + iVar2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      }
      FUN_004f823a(arg_1,7);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


