/*
 * Decompiled function: FUN_1003afa3
 * Entry Point: 1003afa3
 * Size: 135 bytes
 */
#include "deckdll.h"


int FUN_1003afa3(char *str_1)

{
  char local_1fc [500];
  int local_8;
  
  local_8 = thunk_FUN_1003ac8b(0,0,0,str_1,(uint8_t *)0x0);
  if (local_8 != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_1004bae8);
  }
  if (DAT_10176354 != 0) {
    sprintf(local_1fc,s__08X_LoadKimPicture___s___file_m_1004bb44,local_8,str_1,
            *(int32_t *)PTR_DAT_1004bae8);
    OutputDebugStringA(local_1fc);
  }
  return local_8;
}


