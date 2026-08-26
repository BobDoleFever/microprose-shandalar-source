/*
 * Decompiled function: thunk_FUN_1000667b
 * Entry Point: 1000100a
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_1000667b(int32_t arg_1,int *ptr_2)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int val_3;
  int32_t *puVar4;
  int32_t *puVar5;
  int32_t uStack0000000c;
  int32_t auStack_fc [4];
  int16_t uStack_ec;
  int32_t auStack_e8 [18];
  uint8_t auStack_a0 [4];
  int iStack_9c;
  int iStack_98;
  int32_t uStack_94;
  int aiStack_90 [8];
  int iStack_70;
  int iStack_68;
  int iStack_60;
  
  uStack_94 = 0x12;
  AVIStreamInfoA(arg_1,aiStack_90,0x8c);
  if (aiStack_90[0] == 0x73647561) {
    AVIStreamRead(arg_1,0,1,0,0,auStack_a0,0);
    iStack_98 = iStack_60 * iStack_70;
    AVIStreamReadFormat(arg_1,0,auStack_fc,&uStack_94);
    uStack_ec = 0;
    uStack0000000c = 0xe8;
    iStack_9c = iStack_68 * 0xb;
    buf_ptr_2 = thunk_FUN_10006540(DAT_1000ba90,iStack_9c,auStack_fc,0xe8);
    *ptr_2 = (int)buf_ptr_2;
    if (*ptr_2 == 0) {
      uval_1 = 9;
    }
    else {
      *(int32_t *)(*ptr_2 + 0x1e0) = 0;
      *(int32_t *)(*ptr_2 + 0x1c8) = 0;
      puVar4 = auStack_e8;
      puVar5 = (int32_t *)(*ptr_2 + 0x180);
      for (val_3 = 0x12; val_3 != 0; val_3 = val_3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(int *)(*ptr_2 + 0x1cc) = iStack_98;
      *(int32_t *)*ptr_2 = arg_1;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x20;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
      *(int *)(*ptr_2 + 0x8c) = iStack_68;
      *(int *)(*ptr_2 + 0x90) = iStack_60;
      *(int32_t *)(*ptr_2 + 0x94) = 0xb;
      *(int32_t *)(*ptr_2 + 0x1dc) = 0;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 8;
  }
  return uval_1;
}


