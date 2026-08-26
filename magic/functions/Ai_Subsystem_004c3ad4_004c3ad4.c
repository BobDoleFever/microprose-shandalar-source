/*
 * Decompiled function: Ai_Subsystem_004c3ad4
 * Entry Point: 004c3ad4
 * Size: 69 bytes
 */
#include "magic.h"


void Ai_Subsystem_004c3ad4(int x,int y,int *width,int *height)

{
  *width = ((x + 0x40) - (y + -200)) / 0xc;
  *height = *width + (y + -200) / 6;
  return;
}


