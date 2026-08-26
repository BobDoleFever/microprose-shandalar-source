/*
 * Decompiled function: FUN_10005dff
 * Entry Point: 10005dff
 * Size: 269 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_10005dff(FILE *x,int y,long width,uint32_t height)

{
  int32_t uval_1;
  int local_1c;
  uint32_t local_18;
  uint32_t local_14;
  int local_10 [3];
  
  fseek(x,width,0);
  fread(local_10,1,0xc,x);
  if (local_10[0] == y) {
    fseek(x,width,0);
    uval_1 = 1;
  }
  else {
    while( true ) {
      local_14 = ftell(x);
      fread(&local_1c,1,8,x);
      if (height <= local_14) break;
      if (local_1c == y) {
        fseek(x,local_14,0);
        return 1;
      }
      local_14 = ftell(x);
      if ((local_18 & 1) != 0) {
        local_18 = local_18 + 1;
      }
      fseek(x,local_18,1);
    }
    fseek(x,width,0);
    uval_1 = 0;
  }
  return uval_1;
}


