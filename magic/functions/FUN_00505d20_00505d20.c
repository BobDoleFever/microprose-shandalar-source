/*
 * Decompiled function: FUN_00505d20
 * Entry Point: 00505d20
 * Size: 287 bytes
 */
#include "magic.h"


bool FUN_00505d20(int arg_1)

{
  int iVar1;
  bool bVar2;
  int local_c;
  
  if (g_IsAiThinking == 1) {
    bVar2 = false;
  }
  else if (DAT_0063ee1c == 0) {
    iVar1 = Pic_Subsystem_0044724d();
    if (iVar1 == 0) {
      bVar2 = false;
    }
    else if (DAT_00627860 == 0) {
      bVar2 = false;
    }
    else {
      if ((arg_1 < 2) || (5 < arg_1)) {
        if ((arg_1 < 0x20) || (0x25 < arg_1)) {
          if ((arg_1 < 2) || (5 < arg_1)) {
            local_c = arg_1;
          }
          else {
            local_c = 4;
          }
        }
        else {
          local_c = 0x20;
        }
      }
      else {
        local_c = 4;
      }
      bVar2 = DAT_00627a88 == local_c;
      if ((DAT_00627a88 == -1) &&
         (((&DAT_00696740)[local_c * 4 + g_DefendingPlayer * 0x98] & 1) != 0)) {
        bVar2 = true;
      }
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


