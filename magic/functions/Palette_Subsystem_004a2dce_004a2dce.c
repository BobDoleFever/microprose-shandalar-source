/*
 * Decompiled function: Palette_Subsystem_004a2dce
 * Entry Point: 004a2dce
 * Size: 270 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a2dce(char *str_1,char *str_2,int arg_3)

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
      while ((*local_8 != '\0' && (iVar3 = strncmp(local_8,&DAT_0052c294,2), iVar3 != 0))) {
        local_8 = local_8 + 1;
      }
      if (*local_8 == '\0') {
        bVar1 = true;
        pcVar2 = local_8;
      }
      else {
        iVar3 = atoi(local_8 + 2);
        pcVar2 = local_8 + 2;
        if (iVar3 == arg_3) {
          local_8 = local_8 + 3;
          local_14 = str_1;
          while ((*local_8 != '\0' && (iVar3 = strncmp(local_8,&DAT_0052c298,2), iVar3 != 0))) {
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


