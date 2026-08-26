/*
 * Decompiled function: Palette_Subsystem_004a554b
 * Entry Point: 004a554b
 * Size: 59 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a554b(int x,int y,int *width,int *height)

{
  *width = x * 0x20 + y * 0x20 + -0x60;
  *height = x * -0x10 + y * 0x10 + 0x110;
  return;
}


