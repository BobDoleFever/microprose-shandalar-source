/*
 * Decompiled function: Sound_DirectSoundShutdown
 * Entry Point: 100013b6
 * Size: 114 bytes
 */
#include "magsnd.h"


void Sound_DirectSoundShutdown(void)

{
  if (DAT_1000a434 != 0) {
    UnloadAllSnds();
    if (DAT_1000a424 != 0) {
      thunk_FUN_10004788();
    }
    (**(code **)(*DAT_1000ba90 + 8))(DAT_1000ba90);
    DAT_1000ba90 = (int *)0x0;
    DAT_1000ba88 = 0;
    DAT_1000a434 = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}


