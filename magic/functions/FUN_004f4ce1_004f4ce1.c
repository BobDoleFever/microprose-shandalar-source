/*
 * Decompiled function: FUN_004f4ce1
 * Entry Point: 004f4ce1
 * Size: 461 bytes
 */
#include "magic.h"


int FUN_004f4ce1(char *str_1,char *str_2,int arg_3)

{
  char cVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  int *piVar5;
  uint local_18;
  int local_14;
  char *local_8;
  
  if ((((str_1 == (char *)0x0) || (str_2 == (char *)0x0)) || (sVar3 = strlen(str_1), sVar3 == 0)) ||
     (sVar3 = strlen(str_2), sVar3 == 0)) {
    return -1;
  }
  sVar3 = strlen(str_2);
  local_8 = str_1;
  local_14 = 0;
  bVar2 = false;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if ((*local_8 == '\0') || (bVar2)) {
              if (!bVar2) {
                return -1;
              }
              return local_14;
            }
            if (((arg_3 != 0) && (iVar4 = strncmp(local_8,str_2,sVar3), iVar4 == 0)) ||
               ((arg_3 == 0 && (iVar4 = _strnicmp(local_8,str_2,sVar3), iVar4 == 0)))) break;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          if (local_8[sVar3] != 's') break;
          bVar2 = true;
        }
        if (local_8[sVar3] != '.') break;
        bVar2 = true;
      }
      if (local_8[sVar3] == ' ') break;
LAB_004f4e77:
      local_8 = local_8 + 1;
      local_14 = local_14 + 1;
    }
    piVar5 = (int *)__p___mb_cur_max();
    if (*piVar5 < 2) {
      cVar1 = local_8[sVar3 + 1];
      piVar5 = (int *)__p__pctype();
      local_18 = *(ushort *)(*piVar5 + cVar1 * 2) & 1;
    }
    else {
      local_18 = _isctype((int)local_8[sVar3 + 1],1);
    }
    if (local_18 != 0) goto LAB_004f4e77;
    bVar2 = true;
  } while( true );
}


