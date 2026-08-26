/*
 * Decompiled function: __heapchk
 * Entry Point: 00407950
 * Size: 120 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __heapchk
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heapchk(void)

{
  int val_1;
  BOOL BVar2;
  DWORD DVar3;
  int32_t local_8;
  
  local_8 = -2;
  val_1 = ___sbh_heap_check();
  if (val_1 < 0) {
    local_8 = -4;
  }
  BVar2 = HeapValidate(DAT_004156ac,0,(LPCVOID)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      _DAT_00412a70 = 0x78;
      _DAT_00412a6c = 0x28;
    }
    else {
      local_8 = -4;
    }
  }
  return local_8;
}


