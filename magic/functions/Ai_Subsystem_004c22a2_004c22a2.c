/*
 * Decompiled function: Ai_Subsystem_004c22a2
 * Entry Point: 004c22a2
 * Size: 158 bytes
 */
#include "magic.h"


int Ai_Subsystem_004c22a2(int x,int y,int width,byte *arg_4)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0x7fffffff;
  for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
    iVar1 = *(int *)(PTR_DAT_0052a1a4 + (width - (uint)arg_4[2]) * 4) +
            *(int *)(PTR_DAT_0052a1a4 + (y - (uint)arg_4[1]) * 4) +
            *(int *)(PTR_DAT_0052a1a4 + (x - (uint)*arg_4) * 4);
    if (iVar1 < local_14) {
      local_10 = local_c;
      local_14 = iVar1;
    }
    arg_4 = arg_4 + 3;
  }
  return local_10;
}


