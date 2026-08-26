/*
 * Decompiled function: __CrtIsValidHeapPointer
 * Entry Point: 004dbd40
 * Size: 182 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtIsValidHeapPointer
   
   Library: Visual Studio 1998 Debug */

BOOL __CrtIsValidHeapPointer(int arg_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_10;
  char *local_c;
  uint local_8;
  
  if (arg_1 == 0) {
    BVar1 = 0;
  }
  else {
    iVar2 = __CrtIsValidPointer((void *)(arg_1 + -0x20),0x20,1);
    if (iVar2 == 0) {
      BVar1 = 0;
    }
    else {
      local_c = (char *)___sbh_find_block((undefined *)(arg_1 + -0x20),&local_10,&local_8);
      if (local_c == (char *)0x0) {
        if ((DAT_0050942c._1_1_ & 0x80) == 0) {
          BVar1 = HeapValidate(DAT_006c1c94,0,(LPCVOID)(arg_1 + -0x20));
        }
        else {
          BVar1 = 1;
        }
      }
      else if (*local_c == '\0') {
        BVar1 = 0;
      }
      else {
        BVar1 = 1;
      }
    }
  }
  return BVar1;
}


