/*
 * Decompiled function: Ai_Subsystem_004c3aa1
 * Entry Point: 004c3aa1
 * Size: 51 bytes
 */
#include "magic.h"


void Ai_Subsystem_004c3aa1(int x,int y,int *width,int *height)

{
  *width = (y + x) * 6 + -0x40;
  *height = (y - x) * 6 + 200;
  return;
}


