/*
 * Decompiled function: thunk_FUN_1003c100
 * Entry Point: 100012c6
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1003c100(HDC hdc,int32_t arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int val_1;
  size_t c;
  int iStack_128;
  int iStack_124;
  int iStack_120;
  CHAR aCStack_11c [264];
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_10 = arg_7;
  SetTextColor(hdc,DAT_1013ee60);
  for (iStack_14 = 0; iStack_14 < 9; iStack_14 = iStack_14 + 1) {
    iStack_8 = arg_6;
    if (iStack_14 == 1) {
      iStack_10 = iStack_10 + arg_3 / 2;
    }
    for (iStack_c = 0; iStack_c < 7; iStack_c = iStack_c + 1) {
      if (iStack_14 == 0) {
        SetTextColor(hdc,DAT_1013ee5c);
      }
      else {
        SetTextColor(hdc,DAT_1013ee60);
      }
      if (*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) == 0) {
        if ((*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) == 0) ||
           (*(int *)(&DAT_1013ed20 + iStack_14 * 0x1c) == 0)) {
          iStack_128 = 0;
        }
        else {
          iStack_128 = (*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) * 100 +
                       (*(int *)(&DAT_1013ed20 + iStack_14 * 0x1c) >> 1)) /
                       *(int *)(&DAT_1013ed20 + iStack_14 * 0x1c);
        }
        wsprintfA(aCStack_11c,&DAT_1004bc38,
                  *(int32_t *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c),iStack_128);
      }
      else if ((iStack_14 == 8) || (iStack_c == 6)) {
        if ((*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) == 0) || (DAT_1013ee00 == 0))
        {
          iStack_120 = 0;
        }
        else {
          iStack_120 = (*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) * 100 +
                       (DAT_1013ee00 >> 1)) / DAT_1013ee00;
        }
        wsprintfA(aCStack_11c,s___d___d___1004bc20,
                  *(int32_t *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c),iStack_120);
      }
      else {
        if ((*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) == 0) ||
           (*(int *)(&DAT_1013ed20 + iStack_14 * 0x1c) == 0)) {
          iStack_124 = 0;
        }
        else {
          iStack_124 = (*(int *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c) * 100 +
                       (*(int *)(&DAT_1013ed20 + iStack_14 * 0x1c) >> 1)) /
                       *(int *)(&DAT_1013ed20 + iStack_14 * 0x1c);
        }
        wsprintfA(aCStack_11c,s___d___d___1004bc2c,
                  *(int32_t *)(&DAT_1013ed08 + iStack_c * 4 + iStack_14 * 0x1c),iStack_124);
      }
      c = strlen(aCStack_11c);
      TextOutA(hdc,iStack_8,iStack_10,aCStack_11c,c);
      iStack_8 = iStack_8 + arg_4;
    }
    val_1 = arg_5;
    if (iStack_14 == 7) {
      val_1 = arg_3 + arg_5;
    }
    iStack_10 = iStack_10 + val_1;
  }
  return;
}


