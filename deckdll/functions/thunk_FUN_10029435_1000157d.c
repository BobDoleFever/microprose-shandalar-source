/*
 * Decompiled function: thunk_FUN_10029435
 * Entry Point: 1000157d
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10029435(int arg1,int arg2)

{
  bool flag_1;
  int iStack_10;
  int iStack_c;
  
  if (arg1 != -1) {
    iStack_c = 0;
    flag_1 = false;
    while ((iStack_c < DAT_101cdeb0 && (!flag_1))) {
      if ((*(int *)(&DAT_10175570 + iStack_c * 0x18) == arg1) &&
         (*(int *)(&DAT_10175574 + iStack_c * 0x18) == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_10175560 + iStack_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_10175560 + iStack_c * 0x18));
        }
        DAT_101cdeb0 = DAT_101cdeb0 + -1;
        for (iStack_10 = iStack_c; iStack_10 < DAT_101cdeb0; iStack_10 = iStack_10 + 1) {
          *(int32_t *)(&DAT_10175560 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_10175560 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175564 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_10175564 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175568 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_10175568 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_1017556c + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_1017556c + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175570 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_10175570 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175574 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_10175574 + (iStack_10 * 3 + 3) * 8);
        }
      }
      iStack_c = iStack_c + 1;
    }
  }
  return;
}


