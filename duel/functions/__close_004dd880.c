/*
 * Decompiled function: __close
 * Entry Point: 004dd880
 * Size: 267 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Debug */

int __cdecl __close(int arg_1)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  int iVar4;
  ulong local_8;
  
  if ((DAT_006c1c90 <= (uint)arg_1) ||
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) == 0)) {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    return -1;
  }
  if ((arg_1 == 1) || (arg_1 == 2)) {
    iVar1 = __get_osfhandle(2);
    iVar2 = __get_osfhandle(1);
    if (iVar1 != iVar2) goto LAB_004dd909;
  }
  else {
LAB_004dd909:
    hObject = (HANDLE)__get_osfhandle(arg_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      local_8 = GetLastError();
      goto LAB_004dd939;
    }
  }
  local_8 = 0;
LAB_004dd939:
  __free_osfhnd(arg_1);
  if (local_8 == 0) {
    *(undefined1 *)
     (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 + (arg_1 & 0x1fU) * 8) =
         0;
    iVar4 = 0;
  }
  else {
    __dosmaperr(local_8);
    iVar4 = -1;
  }
  return iVar4;
}


