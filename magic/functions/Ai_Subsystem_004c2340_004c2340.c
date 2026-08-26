/*
 * Decompiled function: Ai_Subsystem_004c2340
 * Entry Point: 004c2340
 * Size: 371 bytes
 */
#include "magic.h"


void Ai_Subsystem_004c2340
               (undefined4 *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7)

{
  undefined1 uVar1;
  byte local_430 [1024];
  uint local_30;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  int local_c;
  int local_8;
  
  local_14 = (byte *)((int)&DAT_0070a134 + 2);
  if (arg_7 != 0) {
    local_28 = arg_6 & 0xff;
    local_30 = arg_6 >> 8 & 0xff;
    local_24 = (arg_6 & 0xff0000) >> 0x10;
    for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
      local_c = (int)(*local_14 + local_28) / 2;
      local_18 = (int)(local_14[1] + local_30) / 2;
      local_8 = (int)(local_14[2] + local_24) / 2;
      local_14 = local_14 + 3;
      uVar1 = Ai_Subsystem_004c22a2(local_c,local_18,local_8,(byte *)((int)&DAT_0070a134 + 2));
      (&DAT_00558cc0)[local_1c] = uVar1;
    }
  }
  for (local_20 = arg_3; local_20 < arg_5 + arg_3; local_20 = local_20 + 1) {
    Surface_GetLine((undefined4 *)local_430,*arg_1,arg_2,local_20,arg_4);
    for (local_1c = 0; local_1c < arg_4; local_1c = local_1c + 1) {
      local_430[local_1c] = (&DAT_00558cc0)[local_430[local_1c]];
    }
    Surface_PutLine((undefined4 *)local_430,*arg_1,arg_2,local_20,arg_4);
  }
  return;
}


