/*
 * Decompiled function: thunk_FUN_1003afa3
 * Entry Point: 100011f9
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1003afa3(char *str_1)

{
  char acStack_1fc [500];
  int iStack_8;
  
  iStack_8 = thunk_FUN_1003ac8b(0,0,0,str_1,(uint8_t *)0x0);
  if (iStack_8 != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_1004bae8);
  }
  if (DAT_10176354 != 0) {
    sprintf(acStack_1fc,s__08X_LoadKimPicture___s___file_m_1004bb44,iStack_8,str_1,
            *(int32_t *)PTR_DAT_1004bae8);
    OutputDebugStringA(acStack_1fc);
  }
  return iStack_8;
}


