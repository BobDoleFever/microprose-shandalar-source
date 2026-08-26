/*
 * Decompiled function: FUN_00447d7c
 * Entry Point: 00447d7c
 * Size: 263 bytes
 */
#include "duel.h"


void FUN_00447d7c(int arg_1,int arg_2,char *arg_3)

{
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if (*(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x601719 + local_8) != '\0') {
      FUN_004718de(arg_3,(char *)(local_8 * 10 + 0x6c1260),1,
                   &DAT_006c1220 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x601719 + local_8) * 10);
      FUN_004718de(arg_3,(char *)(local_8 * 10 + 0x6c1320),1,
                   &DAT_006c1220 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x601719 + local_8) * 10);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}


