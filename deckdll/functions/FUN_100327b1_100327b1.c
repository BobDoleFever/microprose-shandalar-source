/*
 * Decompiled function: FUN_100327b1
 * Entry Point: 100327b1
 * Size: 461 bytes
 */
#include "deckdll.h"


int FUN_100327b1(char *str_1,char *str_2,int arg_3)

{
  char cVar1;
  bool flag_2;
  size_t len_3;
  int val_4;
  int *piVar5;
  uint32_t local_18;
  int local_14;
  char *local_8;
  
  if ((((str_1 == (char *)0x0) || (str_2 == (char *)0x0)) || (len_3 = strlen(str_1), len_3 == 0)) ||
     (len_3 = strlen(str_2), len_3 == 0)) {
    return -1;
  }
  len_3 = strlen(str_2);
  local_8 = str_1;
  local_14 = 0;
  flag_2 = false;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if ((*local_8 == '\0') || (flag_2)) {
              if (!flag_2) {
                return -1;
              }
              return local_14;
            }
            if (((arg_3 != 0) && (val_4 = strncmp(local_8,str_2,len_3), val_4 == 0)) ||
               ((arg_3 == 0 && (val_4 = _strnicmp(local_8,str_2,len_3), val_4 == 0)))) break;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          if (local_8[len_3] != 's') break;
          flag_2 = true;
        }
        if (local_8[len_3] != '.') break;
        flag_2 = true;
      }
      if (local_8[len_3] == ' ') break;
LAB_10032947:
      local_8 = local_8 + 1;
      local_14 = local_14 + 1;
    }
    piVar5 = (int *)__p___mb_cur_max();
    if (*piVar5 < 2) {
      cVar1 = local_8[len_3 + 1];
      piVar5 = (int *)__p__pctype();
      local_18 = *(uint16_t *)(*piVar5 + cVar1 * 2) & 1;
    }
    else {
      local_18 = _isctype((int)local_8[len_3 + 1],1);
    }
    if (local_18 != 0) goto LAB_10032947;
    flag_2 = true;
  } while( true );
}


