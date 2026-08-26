/*
 * Decompiled function: FUN_00492951
 * Entry Point: 00492951
 * Size: 436 bytes
 */
#include "duel.h"


void FUN_00492951(undefined1 *param_1,int param_2,int param_3,char *param_4)

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
  
  local_c = _fopen(param_4,&DAT_00505428);
  bVar1 = false;
  local_10 = '\0';
  *param_1 = 0;
  if ((*(int *)(&DAT_005daf18 + param_2 * 4) != -1) &&
     (iVar2 = _strcmp(param_4,s_master_csv_0050542c), iVar2 == 0)) {
    _fseek(local_c,*(long *)(&DAT_005daf18 + param_2 * 4),0);
  }
  while (local_8 = _fscanf(local_c,s______________00505438,acStack_211 + 1,local_21c), local_8 != 0)
  {
    if (acStack_211[1] == '0') {
      local_220 = _atoi(acStack_211 + 1);
    }
    if (local_220 == param_2) {
      local_10 = local_10 + '\x01';
      if ((local_10 == param_3) && (bVar1)) {
        FUN_004d9640(param_1,&DAT_00505448);
      }
      if (acStack_211[1] == '\"') {
        bVar1 = true;
      }
      if (local_10 == param_3) {
        FUN_004d9640(param_1,acStack_211 + 1);
      }
      sVar3 = _strlen(acStack_211 + 1);
      if (acStack_211[sVar3] == '\"') {
        bVar1 = false;
      }
      if (bVar1) {
        local_10 = local_10 + -1;
      }
    }
    if ((local_8 == -1) || ((local_10 != '\0' && (local_220 != param_2)))) break;
  }
  _fclose(local_c);
  return;
}


