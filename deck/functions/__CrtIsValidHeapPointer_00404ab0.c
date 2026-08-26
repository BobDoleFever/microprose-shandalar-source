/*
 * Decompiled function: __CrtIsValidHeapPointer
 * Entry Point: 00404ab0
 * Size: 182 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtIsValidHeapPointer
   
   Library: Visual Studio 1998 Debug */

BOOL __cdecl __CrtIsValidHeapPointer(int arg_1)

{
  BOOL BVar1;
  int val_2;
  int32_t local_10;
  char *local_c;
  uint32_t local_8;
  
  if (arg_1 == 0) {
    BVar1 = 0;
  }
  else {
    val_2 = __CrtIsValidPointer((void *)(arg_1 + -0x20),0x20,1);
    if (val_2 == 0) {
      BVar1 = 0;
    }
    else {
      local_c = (char *)___sbh_find_block((uint8_t *)(arg_1 + -0x20),&local_10,&local_8);
      if (local_c == (char *)0x0) {
        if ((DAT_00412a78._1_1_ & 0x80) == 0) {
          BVar1 = HeapValidate(DAT_004156ac,0,(LPCVOID)(arg_1 + -0x20));
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


