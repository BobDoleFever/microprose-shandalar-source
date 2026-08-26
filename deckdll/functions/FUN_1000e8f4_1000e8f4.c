/*
 * Decompiled function: FUN_1000e8f4
 * Entry Point: 1000e8f4
 * Size: 224 bytes
 */
#include "deckdll.h"


int32_t FUN_1000e8f4(int32_t *arg_1,char *str_2,int32_t arg_3)

{
  size_t len_1;
  int val_2;
  int32_t uval_3;
  size_t sVar4;
  size_t sVar5;
  char *_Control;
  
  len_1 = strspn(str_2,&DAT_100423a4);
  for (str_2 = str_2 + len_1; *str_2 != '\0'; str_2 = str_2 + len_1 + sVar4 + sVar5) {
    val_2 = atoi(str_2);
    if (arg_1[val_2 + 2] == 0) {
      uval_3 = thunk_FUN_1000e440();
      arg_1[val_2 + 2] = uval_3;
    }
    arg_1 = (int32_t *)arg_1[val_2 + 2];
    _Control = &DAT_100423ac;
    len_1 = strspn(str_2,&DAT_100423b0);
    len_1 = strcspn(str_2 + len_1,_Control);
    sVar4 = strspn(str_2,&DAT_100423a8);
    sVar5 = strspn(str_2 + len_1 + sVar4,&DAT_100423b4);
  }
  *arg_1 = 1;
  arg_1[1] = arg_3;
  return 0;
}


