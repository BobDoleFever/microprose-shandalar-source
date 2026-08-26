/*
 * Decompiled function: ReleaseSnd
 * Entry Point: 10001104
 * Size: 5 bytes
 */
#include "magsnd.h"


void ReleaseSnd(void)

{
                    /* 0x1104  2  ReleaseSnd */
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


