/*
 * Decompiled function: thunk_FUN_1001c315
 * Entry Point: 10001483
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1001c315(HDC hdc,char *str_2)

{
  BOOL BVar1;
  int iStack_50;
  int iStack_4c;
  tagTEXTMETRICA tStack_48;
  _ABC _Stack_10;
  
  if (str_2 == (char *)0x0) {
    iStack_4c = 0;
  }
  else {
    GetTextMetricsA(hdc,&tStack_48);
    iStack_4c = 0;
    for (; *str_2 != '\0'; str_2 = str_2 + 1) {
      if ((*str_2 < -0x12) || ((uint32_t)(int)*str_2 < 0x80000000)) {
        BVar1 = GetCharABCWidthsA(hdc,(int)*str_2,(int)*str_2,&_Stack_10);
        if (BVar1 == 0) {
          GetCharWidthA(hdc,(int)*str_2,(int)*str_2,&iStack_50);
          iStack_4c = iStack_4c + iStack_50;
        }
        else {
          iStack_4c = _Stack_10.abcB + _Stack_10.abcC + _Stack_10.abcA + iStack_4c;
        }
      }
      else {
        iStack_4c = iStack_4c + tStack_48.tmHeight;
      }
    }
  }
  return iStack_4c;
}


