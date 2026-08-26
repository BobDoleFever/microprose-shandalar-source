/*
 * Decompiled function: FUN_10013cd0
 * Entry Point: 10013cd0
 * Size: 374 bytes
 */
#include "deckdll.h"


void FUN_10013cd0(int arg1,int arg2)

{
  bool flag_1;
  int local_10;
  int local_c;
  
  if (arg1 != -1) {
    local_c = 0;
    flag_1 = false;
    while ((local_c < DAT_10158728 && (!flag_1))) {
      if (((&DAT_101cf600)[local_c * 6] == arg1) && ((&DAT_101cf604)[local_c * 6] == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_101cf5f0 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_101cf5f0 + local_c * 0x18));
        }
        DAT_10158728 = DAT_10158728 + -1;
        for (local_10 = local_c; local_10 < DAT_10158728; local_10 = local_10 + 1) {
          *(int32_t *)(&DAT_101cf5f0 + local_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5f0 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_101cf5f4 + local_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5f4 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_101cf5f8 + local_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5f8 + (local_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_101cf5fc + local_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5fc + (local_10 * 3 + 3) * 8);
          (&DAT_101cf600)[local_10 * 6] = (&DAT_101cf600)[(local_10 * 3 + 3) * 2];
          (&DAT_101cf604)[local_10 * 6] = (&DAT_101cf604)[(local_10 * 3 + 3) * 2];
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}


