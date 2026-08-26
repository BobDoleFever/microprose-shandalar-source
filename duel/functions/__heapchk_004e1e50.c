/*
 * Decompiled function: __heapchk
 * Entry Point: 004e1e50
 * Size: 120 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __heapchk
   
   Library: Visual Studio 1998 Debug */

int __cdecl __heapchk(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_8;
  
  local_8 = -2;
  iVar1 = ___sbh_heap_check();
  if (iVar1 < 0) {
    local_8 = -4;
  }
  BVar2 = HeapValidate(DAT_006c1c94,0,(LPCVOID)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      DAT_00509424 = 0x78;
      DAT_00509420 = 0x28;
    }
    else {
      local_8 = -4;
    }
  }
  return local_8;
}


