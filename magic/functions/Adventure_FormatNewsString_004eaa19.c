/*
 * Decompiled function: Adventure_FormatNewsString
 * Entry Point: 004eaa19
 * Size: 131 bytes
 */
#include "magic.h"


void Adventure_FormatNewsString(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  size_t sVar2;
  int local_10;
  
  if (arg_2 != 0) {
    Adventure_AppendNewsDetails((int)(char)(&DAT_00522600)[arg_1 * 0x44],arg_3);
  }
  local_10 = 0;
  sVar2 = strlen(&g_OverworldWorldState);
  do {
    cVar1 = (&DAT_00522600)[arg_1 * 0x44 + local_10];
    (&g_OverworldWorldState)[local_10 + sVar2] = cVar1;
    local_10 = local_10 + 1;
  } while (cVar1 != '\0');
  return;
}


