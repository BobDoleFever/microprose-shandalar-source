/*
 * Decompiled function: FUN_0040eb04
 * Entry Point: 0040eb04
 * Size: 86 bytes
 */
#include "magic.h"


void FUN_0040eb04(int arg_1)

{
  char cVar1;
  size_t sVar2;
  int local_10;
  
  local_10 = 0;
  sVar2 = strlen(&g_OverworldWorldState);
  do {
    cVar1 = (&PTR_s_Restless_Graveyard_005174e8)[arg_1][local_10];
    (&g_OverworldWorldState)[local_10 + sVar2] = cVar1;
    local_10 = local_10 + 1;
  } while (cVar1 != '\0');
  return;
}


