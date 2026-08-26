/*
 * Decompiled function: Adventure_AppendNewsDetails
 * Entry Point: 004eaa9c
 * Size: 176 bytes
 */
#include "magic.h"


undefined4 Adventure_AppendNewsDetails(undefined4 arg1,int arg2)

{
  switch(arg1) {
  case 0x41:
  case 0x45:
  case 0x49:
  case 0x4f:
  case 0x55:
  case 0x61:
  case 0x65:
  case 0x69:
  case 0x6f:
  case 0x75:
    if (arg2 == 0) {
      strcat(&g_OverworldWorldState,&DAT_0052f428);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_0052f424);
    }
    break;
  default:
    if (arg2 == 0) {
      strcat(&g_OverworldWorldState,&DAT_0052f430);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_0052f42c);
    }
  }
  return 0;
}


