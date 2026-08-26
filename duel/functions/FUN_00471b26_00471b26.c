/*
 * Decompiled function: FUN_00471b26
 * Entry Point: 00471b26
 * Size: 454 bytes
 */
#include "duel.h"


int FUN_00471b26(char *str_1,char *str_2,int arg_3)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  uint local_18;
  int local_14;
  char *local_8;
  
  if ((((str_1 == (char *)0x0) || (str_2 == (char *)0x0)) || (sVar2 = _strlen(str_1), sVar2 == 0))
     || (sVar2 = _strlen(str_2), sVar2 == 0)) {
    return -1;
  }
  sVar2 = _strlen(str_2);
  local_8 = str_1;
  local_14 = 0;
  bVar1 = false;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if ((*local_8 == '\0') || (bVar1)) {
              if (!bVar1) {
                return -1;
              }
              return local_14;
            }
            if (((arg_3 != 0) && (iVar3 = _strncmp(local_8,str_2,sVar2), iVar3 == 0)) ||
               ((arg_3 == 0 && (iVar3 = __strnicmp(local_8,str_2,sVar2), iVar3 == 0)))) break;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          if (local_8[sVar2] != 's') break;
          bVar1 = true;
        }
        if (local_8[sVar2] != '.') break;
        bVar1 = true;
      }
      if (local_8[sVar2] == ' ') break;
LAB_00471cb5:
      local_8 = local_8 + 1;
      local_14 = local_14 + 1;
    }
    if (DAT_005096ac < 2) {
      local_18 = *(ushort *)(PTR_DAT_005094a0 + local_8[sVar2 + 1] * 2) & 1;
    }
    else {
      local_18 = __isctype((int)local_8[sVar2 + 1],1);
    }
    if (local_18 != 0) goto LAB_00471cb5;
    bVar1 = true;
  } while( true );
}


