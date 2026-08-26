/*
 * Decompiled function: Csv_LoadMaster_00492951
 * Entry Point: 00492951
 * Size: 436 bytes
 */
#include "duel.h"


/* WARNING: Type propagation algorithm not settling */

void Csv_LoadMaster_00492951(undefined1 *arg_1,int y,int width,char *str_4)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  int local_220;
  undefined1 local_21c [11];
  char acStack_211 [513];
  char local_10;
  FILE *local_c;
  int local_8;
  
  local_c = _fopen(str_4,&DAT_00505428);
  bVar1 = false;
  local_10 = '\0';
  *arg_1 = 0;
  if ((*(int *)(&DAT_005daf18 + y * 4) != -1) &&
     (iVar2 = _strcmp(str_4,s_master_csv_0050542c), iVar2 == 0)) {
    _fseek(local_c,*(long *)(&DAT_005daf18 + y * 4),0);
  }
  while (local_8 = _fscanf(local_c,s______________00505438,(int)acStack_211 + 1,local_21c),
        local_8 != 0) {
    if (acStack_211[1] == '0') {
      local_220 = _atoi((char *)((int)acStack_211 + 1));
    }
    if (local_220 == y) {
      local_10 = local_10 + '\x01';
      if ((local_10 == width) && (bVar1)) {
        FUN_004d9640((uint *)arg_1,(uint *)&DAT_00505448);
      }
      if (acStack_211[1] == '\"') {
        bVar1 = true;
      }
      if (local_10 == width) {
        FUN_004d9640((uint *)arg_1,(uint *)((int)acStack_211 + 1));
      }
      sVar3 = _strlen((char *)((int)acStack_211 + 1));
      if (acStack_211[sVar3] == '\"') {
        bVar1 = false;
      }
      if (bVar1) {
        local_10 = local_10 + -1;
      }
    }
    if ((local_8 == -1) || ((local_10 != '\0' && (local_220 != y)))) break;
  }
  _fclose(local_c);
  return;
}


