/*
 * Decompiled function: FUN_0044e52d
 * Entry Point: 0044e52d
 * Size: 585 bytes
 */
#include "duel.h"


void FUN_0044e52d(LPRECT arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  undefined4 local_8;
  
  if ((arg_2 == -1) || (arg_3 == -1)) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    if (arg_3 == 1) {
      local_8 = (arg_5 * 2) / 0x2f8;
    }
    else if ((((arg_3 == 2) || (arg_3 == 3)) || (arg_3 == 4)) || (arg_3 == 5)) {
      local_8 = (arg_5 * 0x2b) / 0x2f8;
    }
    else if (arg_3 == 10) {
      local_8 = (arg_5 * 0x54) / 0x2f8;
    }
    else if (arg_3 == 0x14) {
      local_8 = (arg_5 * 0x7d) / 0x2f8;
    }
    else if (((arg_2 == 1) && (arg_3 == 0x16)) || ((arg_2 == 0 && (arg_3 == 0x15)))) {
      local_8 = (arg_5 * 0xa6) / 0x2f8;
    }
    else if (arg_3 == 0x1e) {
      local_8 = (arg_5 * 0xcf) / 0x2f8;
    }
    else if (arg_3 == 0x1f) {
      local_8 = (arg_5 * 0xf8) / 0x2f8;
    }
    else if (((arg_3 == 0x20) || (arg_3 == 0x21)) || ((arg_3 == 0x22 || (arg_3 == 0x25)))) {
      local_8 = (arg_5 * 0x121) / 0x2f8;
    }
    else {
      local_8 = -1;
    }
    if (local_8 == -1) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      if (arg_2 == 0) {
        local_8 = local_8 + (arg_5 * 0x1ae) / 0x2f8;
      }
      SetRect(arg_1,0,local_8,arg_4,local_8 + (arg_5 * 0x28) / 0x2f8);
    }
  }
  return;
}


