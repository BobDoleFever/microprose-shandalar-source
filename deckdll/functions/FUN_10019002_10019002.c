/*
 * Decompiled function: FUN_10019002
 * Entry Point: 10019002
 * Size: 283 bytes
 */
#include "deckdll.h"


void FUN_10019002(HDC hdc,int arg_2,int arg_3)

{
  CHAR local_30 [8];
  int local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  if (1 < *(int *)(&DAT_10176af4 + arg_3 * 0x98)) {
    SetRect(&local_14,*(int *)(arg_2 + 8) + -0x23,*(int *)(arg_2 + 4) + 0x32,
            *(int *)(arg_2 + 8) + -10,*(int *)(arg_2 + 4) + 0x4b);
    for (local_28 = 0; local_28 < *(int *)(&DAT_10176af4 + arg_3 * 0x98); local_28 = local_28 + 1) {
      if (*(int *)(&DAT_10176af8 + arg_3 * 0x98) == local_28) {
        thunk_FUN_1002c220(hdc,&local_14.left,&local_24,1);
      }
      else {
        thunk_FUN_1002c220(hdc,&local_14.left,&local_24,0);
      }
      wsprintfA(local_30,&DAT_10043308,local_28 + 1);
      SetBkMode(hdc,1);
      DrawTextA(hdc,local_30,-1,&local_24,0x25);
      OffsetRect(&local_14,0,0x19);
    }
  }
  return;
}


