/*
 * Decompiled function: FUN_00506029
 * Entry Point: 00506029
 * Size: 207 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00506029(char *str_1)

{
  bool bVar1;
  int arg2;
  int iVar2;
  
  bVar1 = false;
  while (!bVar1) {
    arg2 = Duel_LogActionStatusBanner
                     (g_CurrentTurnPhase,g_CurrentTurnPhase,g_CurrentTurnPhase,0xff,0,str_1,2);
    if (DAT_0063ee8c != -3) {
      if (DAT_0063ee8c == -2) {
        bVar1 = true;
      }
      else if (((DAT_0063ee8c == 0) && (arg2 != -1)) &&
              (iVar2 = FUN_005063f6(_DAT_0063ee20,arg2), iVar2 != 0)) {
        FUN_005064e9(_DAT_0063ee20,arg2);
      }
    }
  }
  return;
}


