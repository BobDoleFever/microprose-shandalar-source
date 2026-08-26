/*
 * Decompiled function: GetAVISndBuff
 * Entry Point: 10001032
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl GetAVISndBuff(int arg1,uint32_t arg2)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t uStack_28;
  int iStack_24;
  int32_t uStack_20;
  uint32_t uStack_1c;
  int iStack_18;
  int iStack_14;
  int32_t uStack_10;
  int32_t uStack_c;
  int iStack_8;
  
                    /* 0x1032  23  GetAVISndBuff */
  uStack_28 = 0;
  iStack_14 = 0;
  uStack_c = 0;
  uStack_10 = 0;
  uStack_20 = 0;
  if ((arg1 < 0x110) && (0xff < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    iStack_24 = *(int *)(&DAT_1000a648 + arg1 * 4);
    if (iStack_24 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uStack_28 = 0;
    }
    else {
      if ((*(uint32_t *)(iStack_24 + 4) >> 7 & 1) != 0) {
        val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a484,0x484,0,0);
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_3 = (*char_ptr_1)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(iStack_24 + 4) >> 7 & 1) == 0) {
        uStack_1c = arg2 % *(uint32_t *)(iStack_24 + 0x94);
        iStack_8 = *(int *)(iStack_24 + 0x8c) * uStack_1c;
        iStack_18 = (**(code **)(**(int **)(iStack_24 + 0xbc) + 0x2c))
                              (*(int32_t *)(iStack_24 + 0xbc),iStack_8,
                               *(int32_t *)(iStack_24 + 0x8c),&uStack_28,&uStack_c,&iStack_14,
                               &uStack_10,0);
        if (iStack_18 == 0) {
          if (iStack_14 != 0) {
            val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4a0,0x496,0,0);
            if (val_2 == 1) {
              char_ptr_1 = (code *)swi(3);
              uval_3 = (*char_ptr_1)();
              return uval_3;
            }
          }
          if (iStack_14 == 0) {
            *(int32_t *)(iStack_24 + 0xa4) = uStack_28;
            *(uint32_t *)(iStack_24 + 4) = *(uint32_t *)(iStack_24 + 4) | 0x80;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          }
          else {
            (**(code **)(**(int **)(iStack_24 + 0xbc) + 0x4c))
                      (*(int32_t *)(iStack_24 + 0xbc),uStack_28,uStack_c,iStack_14,uStack_10);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            uStack_28 = 0;
          }
        }
        else {
          uStack_28 = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uStack_28 = 0;
      }
    }
  }
  else {
    uStack_28 = 0;
  }
  return uStack_28;
}


