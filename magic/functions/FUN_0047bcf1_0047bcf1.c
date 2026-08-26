/*
 * Decompiled function: FUN_0047bcf1
 * Entry Point: 0047bcf1
 * Size: 371 bytes
 */
#include "magic.h"


void FUN_0047bcf1(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,undefined4 *arg_6,
                 int arg_7,int arg_8)

{
  int local_3fc;
  int local_3f8;
  char local_3f4 [1000];
  char *local_c;
  uint local_8;
  
  for (local_3fc = 0; local_3fc < arg_5; local_3fc = local_3fc + 1) {
    Surface_GetLine((undefined4 *)local_3f4,*arg_1,arg_2,local_3fc + arg_3,arg_4);
    if (local_3f4[0] == '\0') {
      local_c = (char *)0x0;
    }
    else {
      local_c = local_3f4;
    }
    local_8 = 0;
    for (local_3f8 = 0; local_3f8 < arg_4; local_3f8 = local_3f8 + 1) {
      if (local_3f4[local_3f8] == '\0') {
        if (local_8 == 0) {
          local_c = local_3f4 + local_3f8;
        }
        else {
          Surface_PutLine((undefined4 *)local_c,*arg_6,(int)(local_c + (arg_7 - (int)local_3f4)),
                          local_3fc + arg_8,local_8);
          local_8 = 0;
          local_c = local_3f4 + local_3f8;
        }
      }
      else {
        local_8 = local_8 + 1;
      }
    }
    if (local_8 != 0) {
      Surface_PutLine((undefined4 *)local_c,*arg_6,(int)(local_c + (arg_7 - (int)local_3f4)),
                      local_3fc + arg_8,local_8);
    }
  }
  return;
}


