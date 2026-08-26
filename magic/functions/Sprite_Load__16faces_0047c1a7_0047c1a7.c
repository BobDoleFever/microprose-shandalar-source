/*
 * Decompiled function: Sprite_Load__16faces_0047c1a7
 * Entry Point: 0047c1a7
 * Size: 87 bytes
 */
#include "magic.h"


void Sprite_Load__16faces_0047c1a7(int arg_1)

{
  Sprite_LoadAll(&DAT_00676dd0,s_16facesLow_spr_00526b44);
  Sprite_LoadAll(&DAT_00676d80,s_16faces_spr_00526b54);
  FUN_0047c2fd(arg_1);
  Mem_AllocOrFree_0050fc50(DAT_00676dd0);
  Mem_AllocOrFree_0050fc50(DAT_00676d80);
  return;
}


