/*
 * Decompiled function: __close
 * Entry Point: 0040b040
 * Size: 267 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Debug */

int __cdecl __close(int arg_1)

{
  intptr_t val_1;
  intptr_t val_2;
  HANDLE hObject;
  BOOL BVar3;
  int val_4;
  uint32_t local_8;
  
  if ((DAT_004157fc <= (uint32_t)arg_1) ||
     ((*(uint8_t *)(*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) == 0)) {
    _DAT_00412a6c = 9;
    _DAT_00412a70 = 0;
    return -1;
  }
  if ((arg_1 == 1) || (arg_1 == 2)) {
    val_1 = __get_osfhandle(2);
    val_2 = __get_osfhandle(1);
    if (val_1 != val_2) goto LAB_0040b0c9;
  }
  else {
LAB_0040b0c9:
    hObject = (HANDLE)__get_osfhandle(arg_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      local_8 = GetLastError();
      goto LAB_0040b0f9;
    }
  }
  local_8 = 0;
LAB_0040b0f9:
  __free_osfhnd(arg_1);
  if (local_8 == 0) {
    *(uint8_t *)
     (*(int *)((int)&DAT_004156c0 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 + (arg_1 & 0x1fU) * 8) =
         0;
    val_4 = 0;
  }
  else {
    __dosmaperr(local_8);
    val_4 = -1;
  }
  return val_4;
}


