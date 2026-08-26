/*
 * Decompiled function: Ai_Subsystem_004be25f
 * Entry Point: 004be25f
 * Size: 248 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be25f
               (undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,undefined4 arg_5)

{
  int local_c;
  int local_8;
  
  *(undefined4 *)(&DAT_00557cc0 + DAT_00556c60 * 4) = arg_2;
  *(undefined4 *)(&DAT_005584c0 + DAT_00556c60 * 4) = arg_3;
  *(int *)(&DAT_00556c70 + DAT_00556c60 * 4) = arg_4;
  *(undefined4 *)(&DAT_005574c0 + DAT_00556c60 * 4) = arg_5;
  if (DAT_00556c60 == 0) {
    _DAT_00558dd8 = 0xffffffff;
  }
  else {
    local_8 = -1;
    for (local_c = DAT_00556c64; (*(int *)(&DAT_00556c70 + local_c * 4) < arg_4 && (local_c != -1));
        local_c = *(int *)(&DAT_00558dd8 + local_c * 4)) {
      local_8 = local_c;
    }
    *(int *)(&DAT_00558dd8 + DAT_00556c60 * 4) = local_c;
    if (local_8 == -1) {
      DAT_00556c64 = DAT_00556c60;
    }
    else {
      *(int *)(&DAT_00558dd8 + local_8 * 4) = DAT_00556c60;
    }
  }
  DAT_00556c60 = DAT_00556c60 + 1;
  return;
}


