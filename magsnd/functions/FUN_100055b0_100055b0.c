/*
 * Decompiled function: FUN_100055b0
 * Entry Point: 100055b0
 * Size: 95 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_100055b0(char *str_1,int *ptr_2)

{
  FILE *fp;
  int32_t uval_1;
  
  fp = fopen(str_1,&DAT_1000a524);
  if (fp == (FILE *)0x0) {
    uval_1 = 7;
  }
  else {
    uval_1 = thunk_FUN_10005abe(fp,ptr_2);
    fclose(fp);
  }
  return uval_1;
}


