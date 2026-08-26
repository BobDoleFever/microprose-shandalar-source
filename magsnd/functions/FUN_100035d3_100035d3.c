/*
 * Decompiled function: FUN_100035d3
 * Entry Point: 100035d3
 * Size: 491 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_100035d3(int arg1,uint32_t arg2)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t local_28;
  int local_24;
  int32_t local_20;
  uint32_t local_1c;
  int local_18;
  int local_14;
  int32_t local_10;
  int32_t local_c;
  int local_8;
  
  local_28 = 0;
  local_14 = 0;
  local_c = 0;
  local_10 = 0;
  local_20 = 0;
  if ((arg1 < 0x110) && (0xff < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    local_24 = *(int *)(&DAT_1000a648 + arg1 * 4);
    if (local_24 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_28 = 0;
    }
    else {
      if ((*(uint32_t *)(local_24 + 4) >> 7 & 1) != 0) {
        val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a484,0x484,0,0);
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_3 = (*char_ptr_1)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(local_24 + 4) >> 7 & 1) == 0) {
        local_1c = arg2 % *(uint32_t *)(local_24 + 0x94);
        local_8 = *(int *)(local_24 + 0x8c) * local_1c;
        local_18 = (**(code **)(**(int **)(local_24 + 0xbc) + 0x2c))
                             (*(int32_t *)(local_24 + 0xbc),local_8,
                              *(int32_t *)(local_24 + 0x8c),&local_28,&local_c,&local_14,
                              &local_10,0);
        if (local_18 == 0) {
          if (local_14 != 0) {
            val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4a0,0x496,0,0);
            if (val_2 == 1) {
              char_ptr_1 = (code *)swi(3);
              uval_3 = (*char_ptr_1)();
              return uval_3;
            }
          }
          if (local_14 == 0) {
            *(int32_t *)(local_24 + 0xa4) = local_28;
            *(uint32_t *)(local_24 + 4) = *(uint32_t *)(local_24 + 4) | 0x80;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          }
          else {
            (**(code **)(**(int **)(local_24 + 0xbc) + 0x4c))
                      (*(int32_t *)(local_24 + 0xbc),local_28,local_c,local_14,local_10);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            local_28 = 0;
          }
        }
        else {
          local_28 = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        local_28 = 0;
      }
    }
  }
  else {
    local_28 = 0;
  }
  return local_28;
}


