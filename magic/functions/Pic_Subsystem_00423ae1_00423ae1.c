/*
 * Decompiled function: Pic_Subsystem_00423ae1
 * Entry Point: 00423ae1
 * Size: 118 bytes
 */
#include "magic.h"


void Pic_Subsystem_00423ae1(void)

{
  if (DAT_00520d44 != 0) {
    DAT_00520d44 = 0;
    if ((DAT_00520d48 != 0) && (DAT_00520d40 == 0)) {
      (*DAT_0067f3d4)();
    }
    FreeLibrary(DAT_0067f3c8);
    Pic_Subsystem_004241ae();
    DAT_0067f3c8 = (HMODULE)0x0;
    DAT_00520d40 = 0;
    DAT_00520d48 = 0;
  }
  return;
}


