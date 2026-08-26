/*
 * Decompiled function: FUN_00409d10
 * Entry Point: 00409d10
 * Size: 166 bytes
 */
#include "magic.h"


undefined4 FUN_00409d10(void)

{
  undefined4 uVar1;
  FARPROC pFVar2;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    (&DAT_00701020)[local_8] = 0;
  }
  DAT_00516ca8 = LoadLibraryA(s_statwin_dll_00516cac);
  if (DAT_00516ca8 == (HMODULE)0x0) {
    uVar1 = 1;
  }
  else {
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      pFVar2 = GetProcAddress(DAT_00516ca8,(LPCSTR)(local_8 + 1U & 0xffff));
      (&DAT_00701020)[local_8] = pFVar2;
    }
    uVar1 = 0;
  }
  return uVar1;
}


