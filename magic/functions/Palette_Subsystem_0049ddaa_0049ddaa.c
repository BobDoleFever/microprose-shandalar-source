/*
 * Decompiled function: Palette_Subsystem_0049ddaa
 * Entry Point: 0049ddaa
 * Size: 519 bytes
 */
#include "magic.h"


int Palette_Subsystem_0049ddaa(int *arg1,char *str_2)

{
  int local_58;
  int local_54;
  int local_50;
  char local_4c [52];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg1 == (int *)0x0) || (str_2 == (char *)0x0)) {
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
        local_4c[0] = -0x10;
        local_50 = 1;
      }
      else if (local_18 == 0x48) {
        local_4c[0] = -0x10;
        local_50 = 1;
      }
      else if ((local_18 < 1) || (9 < local_18)) {
        if (local_18 == 10) {
          local_4c[0] = -0x11;
          local_50 = 1;
        }
      }
      else {
        local_4c[0] = (char)local_18 + -0xf;
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
                local_4c[local_50] = '\0';
                local_c = 1;
              }
              else {
                local_4c[local_50] = -3;
                local_50 = local_50 + 1;
                local_54 = local_54 + -1;
              }
            }
            else {
              local_4c[local_50] = -2;
              local_50 = local_50 + 1;
              local_58 = local_58 + -1;
            }
          }
          else {
            local_4c[local_50] = -4;
            local_50 = local_50 + 1;
            local_14 = local_14 + -1;
          }
        }
        else {
          local_4c[local_50] = -1;
          local_50 = local_50 + 1;
          local_8 = local_8 + -1;
        }
      }
      else {
        local_4c[local_50] = -5;
        local_50 = local_50 + 1;
        local_10 = local_10 + -1;
      }
    }
    if ((((local_18 == 0) && (local_50 == 0)) && (local_10 == 0)) &&
       (((local_8 == 0 && (local_14 == 0)) && ((local_58 == 0 && (local_54 == 0)))))) {
      local_4c[0] = -0xf;
      local_4c[1] = 0;
    }
    if (str_2 != (char *)0x0) {
      strcpy(str_2,local_4c);
    }
  }
  return local_50;
}


