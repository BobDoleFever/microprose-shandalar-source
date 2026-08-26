/*
 * Decompiled function: FUN_00434ec7
 * Entry Point: 00434ec7
 * Size: 218 bytes
 */
#include "duel.h"


undefined4 FUN_00434ec7(undefined4 *arg_1,char *str_2,undefined4 arg_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  size_t sVar5;
  char *str_2_00;
  
  sVar1 = _strspn(str_2,&DAT_004f544c);
  for (str_2 = str_2 + sVar1; *str_2 != '\0'; str_2 = str_2 + sVar1 + sVar4 + sVar5) {
    iVar2 = _atoi(str_2);
    if (arg_1[iVar2 + 2] == 0) {
      uVar3 = FUN_00434a10();
      arg_1[iVar2 + 2] = uVar3;
    }
    arg_1 = (undefined4 *)arg_1[iVar2 + 2];
    str_2_00 = &DAT_004f5454;
    sVar1 = _strspn(str_2,&DAT_004f5458);
    sVar1 = _strcspn(str_2 + sVar1,str_2_00);
    sVar4 = _strspn(str_2,&DAT_004f5450);
    sVar5 = _strspn(str_2 + sVar1 + sVar4,&DAT_004f545c);
  }
  *arg_1 = 1;
  arg_1[1] = arg_3;
  return 0;
}


