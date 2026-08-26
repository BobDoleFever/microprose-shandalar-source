/*
 * Decompiled function: FUN_10029435
 * Entry Point: 10029435
 * Size: 372 bytes
 */
#include "deckdll.h"


void FUN_10029435(int arg1,int arg2)

{
  bool flag_1;
  int local_10;
  int local_c;
  
  if (arg1 != -1) {
    local_c = 0;
    flag_1 = false;
    while ((local_c < DAT_101cdeb0 && (!flag_1))) {
      if ((*(int *)(&DAT_10175570 + local_c * 0x18) == arg1) &&
         (*(int *)(&DAT_10175574 + local_c * 0x18) == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_10175560 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_10175560 + local_c * 0x18));
        }
        DAT_101cdeb0 = DAT_101cdeb0 + -1;
        for (local_10 = local_c; local_10 < DAT_101cdeb0; local_10 = local_10 + 1) {
          *(int32_t *)(&DAT_10175560 + local_10 * 0x18) =
               *(int32_t *)(&DAT_10175560 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175564 + local_10 * 0x18) =
               *(int32_t *)(&DAT_10175564 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175568 + local_10 * 0x18) =
               *(int32_t *)(&DAT_10175568 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_1017556c + local_10 * 0x18) =
               *(int32_t *)(&DAT_1017556c + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175570 + local_10 * 0x18) =
               *(int32_t *)(&DAT_10175570 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_10175574 + local_10 * 0x18) =
               *(int32_t *)(&DAT_10175574 + (local_10 * 3 + 3) * 8);
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}


