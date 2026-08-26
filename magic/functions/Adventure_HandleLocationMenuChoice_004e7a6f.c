/*
 * Decompiled function: Adventure_HandleLocationMenuChoice
 * Entry Point: 004e7a6f
 * Size: 756 bytes
 */
#include "magic.h"


int Adventure_HandleLocationMenuChoice(int arg1,int arg2)

{
  int iVar1;
  int arg_1;
  int local_40 [10];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_40[0] = 0x4800;
  local_40[1] = 0x4900;
  local_40[2] = 0x4d00;
  local_40[3] = 0x5100;
  local_40[4] = 0x5000;
  local_40[5] = 0x4f00;
  local_40[6] = 0x4b00;
  local_40[7] = 0x4700;
  local_40[8] = 0x4800;
  iVar1 = Ai_Util_004c3bc4(0x40);
  if ((((arg1 < iVar1) || (iVar1 = Ai_Util_004c3bc4(0x240), iVar1 < arg1)) ||
      (iVar1 = Ai_Util_004c3bc4(0x30), arg2 < iVar1)) ||
     (iVar1 = Ai_Util_004c3bc4(0x148), iVar1 < arg2)) {
    iVar1 = -1;
  }
  else {
    iVar1 = Ai_Util_004c3bc4(0x130);
    if (((iVar1 < arg1) && (iVar1 = Ai_Util_004c3bc4(0x158), arg1 < iVar1)) &&
       ((iVar1 = Ai_Util_004c3bc4(0xa8), iVar1 < arg2 &&
        (iVar1 = Ai_Util_004c3bc4(0xdd), arg2 < iVar1)))) {
      iVar1 = 0x20;
    }
    else {
      local_14 = Ai_Util_004c3bc4(0x140);
      local_18 = Ai_Util_004c3bc4(0xbc);
      iVar1 = arg1 - local_14;
      arg_1 = local_18 - arg2;
      local_c = abs(iVar1);
      local_10 = abs(arg_1);
      if ((iVar1 < 0) || (arg_1 < 0)) {
        if ((iVar1 < 0) || (-1 < arg_1)) {
          if ((iVar1 < 0) && (arg_1 < 0)) {
            local_8 = 4;
          }
          else if ((iVar1 < 0) && (-1 < arg_1)) {
            local_8 = 6;
          }
        }
        else {
          local_8 = 2;
        }
      }
      else {
        local_8 = 0;
      }
      if (((local_8 & 2) == 0) && (local_10 < local_c)) {
        local_8 = local_8 + 1;
      }
      else if (((local_8 & 2) != 0) && (local_c < local_10)) {
        local_8 = local_8 + 1;
      }
      switch(local_8) {
      case 0:
      case 3:
      case 4:
      case 7:
        local_40[9] = local_c * 0x9a85 >> 0xe;
        if (arg_1 < 0) {
          local_40[9] = -local_40[9];
        }
        break;
      case 1:
      case 2:
      case 5:
      case 6:
        local_40[9] = local_c * 0x1a82 >> 0xe;
        if (arg_1 < 0) {
          local_40[9] = -local_40[9];
        }
      }
      switch(local_8) {
      case 0:
      case 1:
      case 2:
      case 3:
        if (arg_1 < local_40[9]) {
          local_8 = local_8 + 1;
        }
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        if (local_40[9] < arg_1) {
          local_8 = local_8 + 1;
        }
      }
      iVar1 = local_40[local_8];
    }
  }
  return iVar1;
}


