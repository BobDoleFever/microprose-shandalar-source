/*
 * Decompiled function: FUN_00421a54
 * Entry Point: 00421a54
 * Size: 213 bytes
 */
#include "duel.h"


int FUN_00421a54(HDC hdc,char *str_2)

{
  BOOL BVar1;
  int local_50;
  int local_4c;
  tagTEXTMETRICA local_48;
  _ABC local_10;
  
  if (str_2 == (char *)0x0) {
    local_4c = 0;
  }
  else {
    GetTextMetricsA(hdc,&local_48);
    local_4c = 0;
    for (; *str_2 != '\0'; str_2 = str_2 + 1) {
      if ((*str_2 < -0x12) || ((uint)(int)*str_2 < 0x80000000)) {
        BVar1 = GetCharABCWidthsA(hdc,(int)*str_2,(int)*str_2,&local_10);
        if (BVar1 == 0) {
          GetCharWidthA(hdc,(int)*str_2,(int)*str_2,&local_50);
          local_4c = local_4c + local_50;
        }
        else {
          local_4c = local_10.abcB + local_10.abcC + local_10.abcA + local_4c;
        }
      }
      else {
        local_4c = local_4c + local_48.tmHeight;
      }
    }
  }
  return local_4c;
}


