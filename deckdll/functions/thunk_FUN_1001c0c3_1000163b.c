/*
 * Decompiled function: thunk_FUN_1001c0c3
 * Entry Point: 1000163b
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001c0c3(HDC hdc,int arg_2,uint32_t arg_3)

{
  uint8_t auStack_44 [4];
  int iStack_40;
  int iStack_3c;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  tagRECT tStack_1c;
  int iStack_c;
  int iStack_8;
  
  if ((((((hdc != (HDC)0x0) && (arg_2 != 0)) && ((arg_3 & 0x800) == 0)) &&
       ((arg_3 != 0xffffffff && ((arg_3 & 0x10) == 0)))) &&
      (((arg_3 & 0x80) == 0 && (DAT_1013e1f0 != (HANDLE)0x0)))) &&
     (((arg_3 & 0x2e) != 0 || ((arg_3 & 0x100) != 0)))) {
    GetObjectA(DAT_1013e1f0,0x18,auStack_44);
    iStack_24 = iStack_40 / 10;
    iStack_2c = iStack_3c;
    if ((arg_3 & 0x20) == 0) {
      if ((arg_3 & 0x100) == 0) {
        if ((arg_3 & 4) == 0) {
          if ((arg_3 & 2) == 0) {
            if ((arg_3 & 8) != 0) {
              iStack_20 = iStack_24 << 3;
            }
          }
          else {
            iStack_20 = iStack_24 * 6;
          }
        }
        else {
          iStack_20 = iStack_24 << 2;
        }
      }
      else {
        iStack_20 = iStack_24 * 2;
      }
    }
    else {
      iStack_20 = 0;
    }
    iStack_c = iStack_24 + iStack_20;
    iStack_8 = *(int *)(arg_2 + 0xc) - *(int *)(arg_2 + 4);
    iStack_28 = (iStack_8 * iStack_24) / iStack_3c;
    SetRect(&tStack_1c,*(int *)(arg_2 + 8) - iStack_28,*(int *)(arg_2 + 4),*(int *)(arg_2 + 8),
            *(int *)(arg_2 + 4) + iStack_8);
    thunk_FUN_1003197a(hdc,&tStack_1c.left,DAT_1013e1f0,iStack_24,iStack_2c,iStack_20,0,iStack_c,0);
  }
  return;
}


