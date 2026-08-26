/*
 * Decompiled function: FUN_004718de
 * Entry Point: 004718de
 * Size: 584 bytes
 */
#include "duel.h"


void FUN_004718de(char *str_1,char *str_2,int width,char *str_4)

{
  size_t sVar1;
  int iVar2;
  uint local_20c;
  int local_208;
  undefined4 local_204;
  size_t local_10;
  int local_c;
  char *local_8;
  
  if (((((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) && (str_4 != (char *)0x0)) &&
      ((sVar1 = _strlen(str_1), sVar1 != 0 && (sVar1 = _strlen(str_2), sVar1 != 0)))) &&
     (sVar1 = _strlen(str_4), sVar1 != 0)) {
    local_10 = _strlen(str_2);
    local_8 = str_1;
    local_204._0_1_ = 0;
    local_208 = 0;
    while (*local_8 != '\0') {
      local_c = 0;
      if (((width != 0) && (iVar2 = _strncmp(local_8,str_2,local_10), iVar2 == 0)) ||
         ((width == 0 && (iVar2 = __strnicmp(local_8,str_2,local_10), iVar2 == 0)))) {
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
          if (DAT_005096ac < 2) {
            local_20c = *(ushort *)(PTR_DAT_005094a0 + local_8[local_10 + 1] * 2) & 1;
          }
          else {
            local_20c = __isctype((int)local_8[local_10 + 1],1);
          }
          if (local_20c == 0) {
            local_c = 1;
          }
        }
      }
      if (local_c == 0) {
        *(char *)((int)&local_204 + local_208) = *local_8;
        local_8 = local_8 + 1;
        *(undefined1 *)((int)&local_204 + local_208 + 1) = 0;
        local_208 = local_208 + 1;
      }
      else {
        FUN_004d9640(&local_204,(uint *)str_4);
        sVar1 = _strlen(str_4);
        local_8 = local_8 + local_10;
        local_208 = local_208 + sVar1;
      }
    }
    Mem_AllocOrFree_004d9630((uint *)str_1,&local_204);
  }
  return;
}


