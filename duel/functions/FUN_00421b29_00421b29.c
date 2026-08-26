/*
 * Decompiled function: FUN_00421b29
 * Entry Point: 00421b29
 * Size: 519 bytes
 */
#include "duel.h"


int FUN_00421b29(int *arg1,int arg2)

{
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg1 == (int *)0x0) || (arg2 == 0)) {
    local_50 = 0;
  }
  else {
    local_10 = arg1[5];
    local_8 = arg1[3];
    local_14 = arg1[4];
    local_58 = arg1[1];
    local_54 = arg1[2];
    local_18 = *arg1;
    local_50 = 0;
    if (local_18 != 0) {
      if (local_18 == -1) {
        local_4c._0_1_ = -0x10;
        local_50 = 1;
      }
      else if (local_18 == 0x48) {
        local_4c._0_1_ = -0x10;
        local_50 = 1;
      }
      else if ((local_18 < 1) || (9 < local_18)) {
        if (local_18 == 10) {
          local_4c._0_1_ = -0x11;
          local_50 = 1;
        }
      }
      else {
        local_4c._0_1_ = (char)local_18 + -0xf;
        local_50 = 1;
      }
    }
    local_c = 0;
    while (local_c == 0) {
      if (local_10 == 0) {
        if (local_8 == 0) {
          if (local_14 == 0) {
            if (local_58 == 0) {
              if (local_54 == 0) {
                *(undefined1 *)((int)&local_4c + local_50) = 0;
                local_c = 1;
              }
              else {
                *(undefined1 *)((int)&local_4c + local_50) = 0xfd;
                local_50 = local_50 + 1;
                local_54 = local_54 + -1;
              }
            }
            else {
              *(undefined1 *)((int)&local_4c + local_50) = 0xfe;
              local_50 = local_50 + 1;
              local_58 = local_58 + -1;
            }
          }
          else {
            *(undefined1 *)((int)&local_4c + local_50) = 0xfc;
            local_50 = local_50 + 1;
            local_14 = local_14 + -1;
          }
        }
        else {
          *(undefined1 *)((int)&local_4c + local_50) = 0xff;
          local_50 = local_50 + 1;
          local_8 = local_8 + -1;
        }
      }
      else {
        *(undefined1 *)((int)&local_4c + local_50) = 0xfb;
        local_50 = local_50 + 1;
        local_10 = local_10 + -1;
      }
    }
    if ((((local_18 == 0) && (local_50 == 0)) && (local_10 == 0)) &&
       (((local_8 == 0 && (local_14 == 0)) && ((local_58 == 0 && (local_54 == 0)))))) {
      local_4c._0_1_ = -0xf;
      local_4c._1_1_ = 0;
    }
    if (arg2 != 0) {
      Mem_AllocOrFree_004d9630((uint *)arg2,&local_4c);
    }
  }
  return local_50;
}


