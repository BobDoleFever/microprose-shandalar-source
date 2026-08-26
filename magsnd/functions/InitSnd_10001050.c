/*
 * Decompiled function: InitSnd
 * Entry Point: 10001050
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl InitSnd(int arg_1,int32_t arg_2,uint8_t arg_3)

{
  int32_t uval_1;
  int val_2;
  uint8_t auStack_8 [4];
  
                    /* 0x1050  1  InitSnd */
  if (((arg_3 & 2) == 0) || (DAT_1000a434 != 0)) {
    if (((arg_3 & 2) == 0) || (DAT_1000a434 == 0)) {
      if ((DAT_1000a434 == 0) && (arg_1 != 0)) {
        val_2 = DirectSoundCreate(0,&DAT_1000ba90,0);
        if (val_2 != 0) {
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000ba90 + 0x18))(DAT_1000ba90,arg_1,3);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000ba90 + 0xc))(DAT_1000ba90,&DAT_1000a440,&DAT_1000a640,0);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000a640 + 0x38))(DAT_1000a640,&DAT_1000a458);
        if (val_2 != 0) {
          (**(code **)(*DAT_1000a640 + 0x14))(DAT_1000a640,&DAT_1000a458,0x12,auStack_8);
        }
        DAT_1000ba88 = arg_1;
        DAT_1000a434 = DAT_1000a434 + 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
      if ((arg_3 & 1) != 0) {
        if (DAT_1000a424 != 0) {
          thunk_FUN_10004788();
        }
        DAT_1000a420 = 0;
      }
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 4;
  }
  return uval_1;
}


