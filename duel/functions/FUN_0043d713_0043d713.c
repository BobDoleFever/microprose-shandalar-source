/*
 * Decompiled function: FUN_0043d713
 * Entry Point: 0043d713
 * Size: 134 bytes
 */
#include "duel.h"


int FUN_0043d713(char *str_1)

{
  char local_1fc [500];
  int local_8;
  
  local_8 = FUN_0043d3ff(0,0,0,str_1,(undefined1 *)0x0);
  if (local_8 != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_004f7914);
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_1fc,s__08X_LoadKimPicture___s___file_m_004f7970,local_8,str_1,
             *(undefined4 *)PTR_DAT_004f7914);
    OutputDebugStringA(local_1fc);
  }
  return local_8;
}


