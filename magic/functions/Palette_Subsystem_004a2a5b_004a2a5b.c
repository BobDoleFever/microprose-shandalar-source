/*
 * Decompiled function: Palette_Subsystem_004a2a5b
 * Entry Point: 004a2a5b
 * Size: 72 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a2a5b(undefined4 arg_1,int *arg_2,byte arg_3)

{
  tagRECT local_14;
  
  if (((arg_3 & 1) != 0) && ((arg_3 & 2) != 0)) {
    Palette_Subsystem_004a2aa3(&local_14,arg_2);
    FUN_004f3e29(arg_1,&local_14,DAT_0054b3d8);
  }
  return;
}


