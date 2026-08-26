/*
 * Decompiled function: Pic_Load_00423833
 * Entry Point: 00423833
 * Size: 135 bytes
 */
#include "magic.h"


int Pic_Load_00423833(char *str_1)

{
  char local_1fc [500];
  int local_8;
  
  local_8 = Pic_Load_0042351b(0,0,0,str_1,(undefined1 *)0x0);
  if (local_8 != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_00520cb8);
  }
  if (DAT_006b157c != 0) {
    sprintf(local_1fc,s__08X_LoadKimPicture___s___file_m_00520d10,local_8,str_1,
            *(undefined4 *)PTR_DAT_00520cb8);
    OutputDebugStringA(local_1fc);
  }
  return local_8;
}


