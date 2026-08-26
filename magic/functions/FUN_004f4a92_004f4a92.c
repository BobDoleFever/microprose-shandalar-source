/*
 * Decompiled function: FUN_004f4a92
 * Entry Point: 004f4a92
 * Size: 591 bytes
 */
#include "magic.h"


void FUN_004f4a92(char *str_1,char *str_2,int width,char *str_4)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  uint local_20c;
  int local_208;
  char local_204 [500];
  size_t local_10;
  int local_c;
  char *local_8;
  
  if (((((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) && (str_4 != (char *)0x0)) &&
      ((sVar2 = strlen(str_1), sVar2 != 0 && (sVar2 = strlen(str_2), sVar2 != 0)))) &&
     (sVar2 = strlen(str_4), sVar2 != 0)) {
    local_10 = strlen(str_2);
    local_8 = str_1;
    local_204[0] = '\0';
    local_208 = 0;
    while (*local_8 != '\0') {
      local_c = 0;
      if (((width != 0) && (iVar3 = strncmp(local_8,str_2,local_10), iVar3 == 0)) ||
         ((width == 0 && (iVar3 = _strnicmp(local_8,str_2,local_10), iVar3 == 0)))) {
        if (local_8[local_10] == '\0') {
          local_c = 1;
        }
        else if (local_8[local_10] == 's') {
          local_c = 1;
        }
        else if (local_8[local_10] == '.') {
          local_c = 1;
        }
        else if (local_8[local_10] == ' ') {
          piVar4 = (int *)__p___mb_cur_max();
          if (*piVar4 < 2) {
            cVar1 = local_8[local_10 + 1];
            piVar4 = (int *)__p__pctype();
            local_20c = *(ushort *)(*piVar4 + cVar1 * 2) & 1;
          }
          else {
            local_20c = _isctype((int)local_8[local_10 + 1],1);
          }
          if (local_20c == 0) {
            local_c = 1;
          }
        }
      }
      if (local_c == 0) {
        local_204[local_208] = *local_8;
        local_8 = local_8 + 1;
        local_204[local_208 + 1] = '\0';
        local_208 = local_208 + 1;
      }
      else {
        strcat(local_204,str_4);
        sVar2 = strlen(str_4);
        local_8 = local_8 + local_10;
        local_208 = local_208 + sVar2;
      }
    }
    strcpy(str_1,local_204);
  }
  return;
}


