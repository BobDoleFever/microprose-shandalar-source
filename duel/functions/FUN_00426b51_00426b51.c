/*
 * Decompiled function: FUN_00426b51
 * Entry Point: 00426b51
 * Size: 267 bytes
 */
#include "duel.h"


void FUN_00426b51(char *str_1,char *str_2,int arg_3)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  char *local_14;
  char *local_8;
  
  if ((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) {
    bVar1 = false;
    local_8 = str_2;
    pcVar2 = local_8;
    while (local_8 = pcVar2, !bVar1) {
      while ((*local_8 != '\0' && (iVar3 = _strncmp(local_8,&DAT_004f36a8,2), iVar3 != 0))) {
        local_8 = local_8 + 1;
      }
      if (*local_8 == '\0') {
        bVar1 = true;
        pcVar2 = local_8;
      }
      else {
        iVar3 = _atoi(local_8 + 2);
        pcVar2 = local_8 + 2;
        if (iVar3 == arg_3) {
          local_8 = local_8 + 3;
          local_14 = str_1;
          while ((*local_8 != '\0' && (iVar3 = _strncmp(local_8,&DAT_004f36ac,2), iVar3 != 0))) {
            *local_14 = *local_8;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          *local_14 = '\0';
          bVar1 = true;
          pcVar2 = local_8;
        }
      }
    }
  }
  return;
}


