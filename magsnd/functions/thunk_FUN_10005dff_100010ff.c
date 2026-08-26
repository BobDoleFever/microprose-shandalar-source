/*
 * Decompiled function: thunk_FUN_10005dff
 * Entry Point: 100010ff
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_10005dff(FILE *x,int y,long width,uint32_t height)

{
  int32_t uval_1;
  int iStack_1c;
  uint32_t uStack_18;
  uint32_t uStack_14;
  int aiStack_10 [3];
  
  fseek(x,width,0);
  fread(aiStack_10,1,0xc,x);
  if (aiStack_10[0] == y) {
    fseek(x,width,0);
    uval_1 = 1;
  }
  else {
    while( true ) {
      uStack_14 = ftell(x);
      fread(&iStack_1c,1,8,x);
      if (height <= uStack_14) break;
      if (iStack_1c == y) {
        fseek(x,uStack_14,0);
        return 1;
      }
      uStack_14 = ftell(x);
      if ((uStack_18 & 1) != 0) {
        uStack_18 = uStack_18 + 1;
      }
      fseek(x,uStack_18,1);
    }
    fseek(x,width,0);
    uval_1 = 0;
  }
  return uval_1;
}


