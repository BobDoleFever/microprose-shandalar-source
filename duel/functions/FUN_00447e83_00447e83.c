/*
 * Decompiled function: FUN_00447e83
 * Entry Point: 00447e83
 * Size: 494 bytes
 */
#include "duel.h"


void FUN_00447e83(int arg_1,int arg_2,char *arg_3)

{
  uint local_30 [5];
  int local_1c;
  uint local_18 [5];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
    if (*(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + local_1c) != '\0') {
      FUN_004718de(arg_3,(char *)(local_1c * 10 + 0x6c12e0),1,
                   &DAT_006c1360 +
                   *(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + local_1c) * 10);
      FUN_004718de(arg_3,(char *)(local_1c * 10 + 0x6c12a0),1,
                   &DAT_006c1360 +
                   *(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + local_1c) * 10);
      FUN_004718de(arg_3,s_PLAINSs_004f7f00,1,s_PLAINS_004f7ef8);
      Mem_AllocOrFree_004d9630(local_30,(uint *)(local_1c * 10 + 0x6c12e0));
      FUN_004d9640(local_30,(uint *)&DAT_004f7f08);
      Mem_AllocOrFree_004d9630
                (local_18,(uint *)(&DAT_006c1360 +
                                  *(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + local_1c) *
                                  10));
      FUN_004d9640(local_18,(uint *)&DAT_004f7f10);
      FUN_004718de(arg_3,(char *)local_30,1,(char *)local_18);
      Mem_AllocOrFree_004d9630(local_30,(uint *)(local_1c * 10 + 0x6c12a0));
      FUN_004d9640(local_30,(uint *)&DAT_004f7f18);
      FUN_004718de(arg_3,(char *)local_30,1,(char *)local_18);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}


