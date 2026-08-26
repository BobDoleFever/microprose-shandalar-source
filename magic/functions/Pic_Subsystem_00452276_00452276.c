/*
 * Decompiled function: Pic_Subsystem_00452276
 * Entry Point: 00452276
 * Size: 391 bytes
 */
#include "magic.h"


void Pic_Subsystem_00452276(int arg_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    Magic_UpkeepPhase(0x21);
    Ai_Subsystem_004b58d9(arg_1);
  }
  local_8 = 500;
  local_c = 0;
  do {
    if (499 < local_c) {
LAB_004522f5:
      local_c = 0;
      while( true ) {
        DVar2 = GetTickCount();
        if ((int)(DVar2 >> 0x10) <= local_c) break;
        rand();
        local_c = local_c + 1;
      }
      for (local_10 = 0; local_10 < 100; local_10 = local_10 + 1) {
        for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
          iVar3 = FUN_0040a1d2(local_8);
          if (*(int *)(&DAT_0069e730 + iVar3 * 4 + arg_1 * 2000) != -1) {
            uVar1 = *(undefined4 *)(&DAT_0069e730 + iVar3 * 4 + arg_1 * 2000);
            *(undefined4 *)(&DAT_0069e730 + iVar3 * 4 + arg_1 * 2000) =
                 *(undefined4 *)(&DAT_0069e730 + local_c * 4 + arg_1 * 2000);
            *(undefined4 *)(&DAT_0069e730 + local_c * 4 + arg_1 * 2000) = uVar1;
          }
        }
      }
      return;
    }
    if (*(int *)(&DAT_0069e730 + local_c * 4 + arg_1 * 2000) == -1) {
      local_8 = local_c;
      goto LAB_004522f5;
    }
    local_c = local_c + 1;
  } while( true );
}


