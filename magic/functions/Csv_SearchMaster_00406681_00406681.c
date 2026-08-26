/*
 * Decompiled function: Csv_SearchMaster_00406681
 * Entry Point: 00406681
 * Size: 441 bytes
 */
#include "magic.h"


void Csv_SearchMaster_00406681(char *filepath,int y,int width,char *str_4)

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
  
  local_c = fopen(str_4,&DAT_00516448);
  bVar1 = false;
  local_10 = '\0';
  *filepath = '\0';
  if ((*(int *)(&DAT_00536e78 + y * 4) != -1) &&
     (iVar2 = strcmp(str_4,s_master_csv_0051644c), iVar2 == 0)) {
    fseek(local_c,*(long *)(&DAT_00536e78 + y * 4),0);
  }
  while (local_8 = fscanf(local_c,s______________00516458,acStack_211 + 1,local_21c), local_8 != 0)
  {
    if (acStack_211[1] == '0') {
      local_220 = atoi(acStack_211 + 1);
    }
    if (local_220 == y) {
      local_10 = local_10 + '\x01';
      if ((local_10 == width) && (bVar1)) {
        strcat(filepath,&DAT_00516468);
      }
      if (acStack_211[1] == '\"') {
        bVar1 = true;
      }
      if (local_10 == width) {
        strcat(filepath,acStack_211 + 1);
      }
      sVar3 = strlen(acStack_211 + 1);
      if (acStack_211[sVar3] == '\"') {
        bVar1 = false;
      }
      if (bVar1) {
        local_10 = local_10 + -1;
      }
    }
    if ((local_8 == -1) || ((local_10 != '\0' && (local_220 != y)))) break;
  }
  fclose(local_c);
  return;
}


