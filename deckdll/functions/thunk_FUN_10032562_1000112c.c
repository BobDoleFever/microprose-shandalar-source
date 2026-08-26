/*
 * Decompiled function: thunk_FUN_10032562
 * Entry Point: 1000112c
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10032562(char *str_1,char *str_2,int width,char *str_4)

{
  char cVar1;
  size_t len_2;
  int val_3;
  int *piVar4;
  uint32_t uStack_20c;
  int iStack_208;
  char acStack_204 [500];
  size_t sStack_10;
  int iStack_c;
  char *pcStack_8;
  
  if (((((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) && (str_4 != (char *)0x0)) &&
      ((len_2 = strlen(str_1), len_2 != 0 && (len_2 = strlen(str_2), len_2 != 0)))) &&
     (len_2 = strlen(str_4), len_2 != 0)) {
    sStack_10 = strlen(str_2);
    pcStack_8 = str_1;
    acStack_204[0] = '\0';
    iStack_208 = 0;
    while (*pcStack_8 != '\0') {
      iStack_c = 0;
      if (((width != 0) && (val_3 = strncmp(pcStack_8,str_2,sStack_10), val_3 == 0)) ||
         ((width == 0 && (val_3 = _strnicmp(pcStack_8,str_2,sStack_10), val_3 == 0)))) {
        if (pcStack_8[sStack_10] == '\0') {
          iStack_c = 1;
        }
        else if (pcStack_8[sStack_10] == 's') {
          iStack_c = 1;
        }
        else if (pcStack_8[sStack_10] == '.') {
          iStack_c = 1;
        }
        else if (pcStack_8[sStack_10] == ' ') {
          piVar4 = (int *)__p___mb_cur_max();
          if (*piVar4 < 2) {
            cVar1 = pcStack_8[sStack_10 + 1];
            piVar4 = (int *)__p__pctype();
            uStack_20c = *(uint16_t *)(*piVar4 + cVar1 * 2) & 1;
          }
          else {
            uStack_20c = _isctype((int)pcStack_8[sStack_10 + 1],1);
          }
          if (uStack_20c == 0) {
            iStack_c = 1;
          }
        }
      }
      if (iStack_c == 0) {
        acStack_204[iStack_208] = *pcStack_8;
        pcStack_8 = pcStack_8 + 1;
        acStack_204[iStack_208 + 1] = '\0';
        iStack_208 = iStack_208 + 1;
      }
      else {
        strcat(acStack_204,str_4);
        len_2 = strlen(str_4);
        pcStack_8 = pcStack_8 + sStack_10;
        iStack_208 = iStack_208 + len_2;
      }
    }
    strcpy(str_1,acStack_204);
  }
  return;
}


