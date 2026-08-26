/*
 * Decompiled function: FUN_0044fc75
 * Entry Point: 0044fc75
 * Size: 449 bytes
 */
#include "duel.h"


void FUN_0044fc75(LPRECT arg_1,int y,int width,int height)

{
  undefined4 local_8;
  
  if (y == -1) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    if (y == 0x15) {
      local_8 = (height * 2) / 0x2f8;
    }
    else if (y == 0x16) {
      local_8 = (height * 0x2b) / 0x2f8;
    }
    else if (y == 0x17) {
      local_8 = (height * 0x54) / 0x2f8;
    }
    else if (y == 0x18) {
      local_8 = (height * 0x7d) / 0x2f8;
    }
    else if (y == 0x19) {
      local_8 = (height * 0xa6) / 0x2f8;
    }
    else if (y == 0x1a) {
      local_8 = (height * 0xcf) / 0x2f8;
    }
    else if (y == 0x1b) {
      local_8 = (height * 0xcf) / 0x2f8;
    }
    else if (y == 0x1e) {
      local_8 = (height * 0x121) / 0x2f8;
    }
    else {
      local_8 = -1;
    }
    if (local_8 == -1) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      SetRect(arg_1,0,local_8,width,(height * 0x28) / 0x2f8 + local_8);
    }
  }
  return;
}


