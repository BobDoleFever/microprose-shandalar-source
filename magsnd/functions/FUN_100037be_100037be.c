/*
 * Decompiled function: FUN_100037be
 * Entry Point: 100037be
 * Size: 401 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_100037be(int arg_1)

{
  int val_1;
  code *char_ptr_2;
  int32_t uval_3;
  int val_4;
  
  if ((arg_1 < 0x110) && (0xff < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    val_1 = *(int *)(&DAT_1000a648 + arg_1 * 4);
    if (val_1 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_3 = 0;
    }
    else {
      if ((*(uint32_t *)(val_1 + 4) >> 7 & 1) == 0) {
        val_4 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4bc,0x4b0,0,0);
        if (val_4 == 1) {
          char_ptr_2 = (code *)swi(3);
          uval_3 = (*char_ptr_2)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(val_1 + 4) >> 7 & 1) == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_3 = 0xe;
      }
      else {
        if (*(int *)(val_1 + 0xa4) == 0) {
          val_4 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4d8,0x4b5,0,0);
          if (val_4 == 1) {
            char_ptr_2 = (code *)swi(3);
            uval_3 = (*char_ptr_2)();
            return uval_3;
          }
        }
        if (*(int *)(val_1 + 0xa4) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          uval_3 = 0xf;
        }
        else {
          (**(code **)(**(int **)(val_1 + 0xbc) + 0x4c))
                    (*(int32_t *)(val_1 + 0xbc),*(int32_t *)(val_1 + 0xa4),
                     *(int32_t *)(val_1 + 0x8c),0,0);
          *(uint32_t *)(val_1 + 4) = *(uint32_t *)(val_1 + 4) & 0xffffff7f;
          *(int32_t *)(val_1 + 0xa4) = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          uval_3 = 0;
        }
      }
    }
  }
  else {
    uval_3 = 0;
  }
  return uval_3;
}


