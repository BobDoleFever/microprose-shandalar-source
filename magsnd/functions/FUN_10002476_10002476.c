/*
 * Decompiled function: Sound_StopWaveSample
 * Entry Point: 10002476
 * Size: 549 bytes
 */
#include "magsnd.h"


int __cdecl Sound_StopWaveSample(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int val_1;
  int local_24;
  int32_t local_20;
  int32_t local_1c;
  uint32_t local_8;
  
  if ((arg1 < 0x100) && (-1 < arg1)) {
    if (((int)arg2 < 0x11) && (-1 < (int)arg2)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      val_1 = *(int *)(&DAT_1000a648 + arg1 * 4);
      if (val_1 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 1;
      }
      else if ((*(int *)(val_1 + 0x30) == 0) || (*(uint32_t *)(val_1 + 0x30) < arg2)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 5;
      }
      else {
        ptr_1 = *(int32_t **)(val_1 + 0x34 + arg2 * 4);
        if (ptr_1 == (int32_t *)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else if (((uint32_t)ptr_1[1] >> 5 & 1) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else {
          if ((*(uint8_t *)(val_1 + 4) & 1) != 0) {
            thunk_FUN_10002900(arg1);
          }
          ptr_1[0x7c] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0);
          local_24 = ptr_1[0x7c];
          ptr_1[0x7b] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1ec);
          local_20 = ptr_1[0x7b];
          ptr_1[0x7a] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1e8);
          local_1c = ptr_1[0x7a];
          local_8 = ptr_1[2] & 1 | local_8 & 0xfffffffe;
          val_1 = thunk_FUN_1000192c(ptr_1,&local_24);
          if (val_1 == 0) {
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 0x40;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) = arg2 - 1;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
      }
    }
    else {
      val_1 = 5;
    }
  }
  else {
    val_1 = 5;
  }
  return val_1;
}


