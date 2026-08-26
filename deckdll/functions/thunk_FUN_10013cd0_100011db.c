/*
 * Decompiled function: thunk_FUN_10013cd0
 * Entry Point: 100011db
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10013cd0(int arg1,int arg2)

{
  bool flag_1;
  int iStack_10;
  int iStack_c;
  
  if (arg1 != -1) {
    iStack_c = 0;
    flag_1 = false;
    while ((iStack_c < DAT_10158728 && (!flag_1))) {
      if (((&DAT_101cf600)[iStack_c * 6] == arg1) && ((&DAT_101cf604)[iStack_c * 6] == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_101cf5f0 + iStack_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_101cf5f0 + iStack_c * 0x18));
        }
        DAT_10158728 = DAT_10158728 + -1;
        for (iStack_10 = iStack_c; iStack_10 < DAT_10158728; iStack_10 = iStack_10 + 1) {
          *(int32_t *)(&DAT_101cf5f0 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5f0 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_101cf5f4 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5f4 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_101cf5f8 + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5f8 + (iStack_10 * 3 + 3) * 8);
          *(int32_t *)(&DAT_101cf5fc + iStack_10 * 0x18) =
               *(int32_t *)(&DAT_101cf5fc + (iStack_10 * 3 + 3) * 8);
          (&DAT_101cf600)[iStack_10 * 6] = (&DAT_101cf600)[(iStack_10 * 3 + 3) * 2];
          (&DAT_101cf604)[iStack_10 * 6] = (&DAT_101cf604)[(iStack_10 * 3 + 3) * 2];
        }
      }
      iStack_c = iStack_c + 1;
    }
  }
  return;
}


