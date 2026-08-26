/*
 * Decompiled function: FUN_1003c100
 * Entry Point: 1003c100
 * Size: 871 bytes
 */
#include "deckdll.h"


void FUN_1003c100(HDC hdc,int32_t arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int val_1;
  size_t c;
  int local_128;
  int local_124;
  int local_120;
  CHAR local_11c [264];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = arg_7;
  SetTextColor(hdc,DAT_1013ee60);
  for (local_14 = 0; local_14 < 9; local_14 = local_14 + 1) {
    local_8 = arg_6;
    if (local_14 == 1) {
      local_10 = local_10 + arg_3 / 2;
    }
    for (local_c = 0; local_c < 7; local_c = local_c + 1) {
      if (local_14 == 0) {
        SetTextColor(hdc,DAT_1013ee5c);
      }
      else {
        SetTextColor(hdc,DAT_1013ee60);
      }
      if (*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) == 0) {
        if ((*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) == 0) ||
           (*(int *)(&DAT_1013ed20 + local_14 * 0x1c) == 0)) {
          local_128 = 0;
        }
        else {
          local_128 = (*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) * 100 +
                      (*(int *)(&DAT_1013ed20 + local_14 * 0x1c) >> 1)) /
                      *(int *)(&DAT_1013ed20 + local_14 * 0x1c);
        }
        wsprintfA(local_11c,&DAT_1004bc38,
                  *(int32_t *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c),local_128);
      }
      else if ((local_14 == 8) || (local_c == 6)) {
        if ((*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) == 0) || (DAT_1013ee00 == 0)) {
          local_120 = 0;
        }
        else {
          local_120 = (*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) * 100 +
                      (DAT_1013ee00 >> 1)) / DAT_1013ee00;
        }
        wsprintfA(local_11c,s___d___d___1004bc20,
                  *(int32_t *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c),local_120);
      }
      else {
        if ((*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) == 0) ||
           (*(int *)(&DAT_1013ed20 + local_14 * 0x1c) == 0)) {
          local_124 = 0;
        }
        else {
          local_124 = (*(int *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c) * 100 +
                      (*(int *)(&DAT_1013ed20 + local_14 * 0x1c) >> 1)) /
                      *(int *)(&DAT_1013ed20 + local_14 * 0x1c);
        }
        wsprintfA(local_11c,s___d___d___1004bc2c,
                  *(int32_t *)(&DAT_1013ed08 + local_c * 4 + local_14 * 0x1c),local_124);
      }
      c = strlen(local_11c);
      TextOutA(hdc,local_8,local_10,local_11c,c);
      local_8 = local_8 + arg_4;
    }
    val_1 = arg_5;
    if (local_14 == 7) {
      val_1 = arg_3 + arg_5;
    }
    local_10 = local_10 + val_1;
  }
  return;
}


