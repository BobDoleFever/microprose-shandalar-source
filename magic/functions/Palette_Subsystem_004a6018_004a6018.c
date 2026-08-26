/*
 * Decompiled function: Palette_Subsystem_004a6018
 * Entry Point: 004a6018
 * Size: 246 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a6018(void)

{
  undefined4 uVar1;
  char local_48 [8];
  char local_40 [56];
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    Mem_AllocOrFree_0050fc00();
    strcpy(local_48,(&PTR_s_dungeon1_spr_0052c2a8)[local_8]);
    strcpy(local_40,&DAT_0052c620);
    Mem_AllocOrFree_00510e20(1,local_48);
    for (local_8 = 0; local_8 < 0x18; local_8 = local_8 + 1) {
      uVar1 = Sprite_EncodeFromSurface
                        (1,(local_8 % 0xc) * 0x41 + 1,(local_8 / 0xc) * 0x41 + 1,0x40,0x40);
      (&DAT_006786b0)[local_8] = (void *)uVar1;
    }
    strcpy(local_40,&DAT_0052c628);
    FUN_0050fc70(DAT_006786b0,local_48);
    Mem_AllocOrFree_0050fc50(DAT_006786b0);
  }
  return;
}


