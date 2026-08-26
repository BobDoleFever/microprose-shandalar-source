/*
 * Decompiled function: thunk_FUN_1000ebea
 * Entry Point: 100012d5
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000ebea(uint32_t arg_1)

{
  int *i_ptr_1;
  int val_2;
  int *i_ptr_3;
  int val_4;
  uint8_t *pbVar5;
  int iStack_28;
  int iStack_20;
  uint32_t uStack_1c;
  
  thunk_FUN_1000ea83(arg_1,(uint32_t *)&DAT_10129250);
  pbVar5 = &DAT_10129250;
  i_ptr_3 = DAT_1012925c;
  do {
    i_ptr_1 = (int *)i_ptr_3[*pbVar5 + 2];
    pbVar5 = pbVar5 + 1;
    if (i_ptr_1 == (int *)0x0) {
      if (*i_ptr_3 == 0) {
        val_2 = i_ptr_3[10];
        iStack_20 = 0x7fffffff;
        for (iStack_28 = 0; iStack_28 < i_ptr_3[0xb]; iStack_28 = iStack_28 + 1) {
          val_4 = *(int *)(PTR_DAT_1004156c +
                          (((arg_1 & 0xff0000) >> 0x10) -
                          ((*(uint32_t *)(&DAT_10128a30 + (uint32_t)*(uint8_t *)(iStack_28 + val_2) * 4) &
                           0xff0000) >> 0x10)) * 4) +
                  *(int *)(PTR_DAT_1004156c +
                          ((arg_1 >> 8 & 0xff) -
                          (uint32_t)(uint8_t)(&DAT_10128a31)[(uint32_t)*(uint8_t *)(iStack_28 + val_2) * 4]) * 4)
                  + *(int *)(PTR_DAT_1004156c +
                            ((arg_1 & 0xff) -
                            (*(uint32_t *)(&DAT_10128a30 + (uint32_t)*(uint8_t *)(iStack_28 + val_2) * 4) &
                            0xff)) * 4);
          if (val_4 < iStack_20) {
            uStack_1c = (uint32_t)*(uint8_t *)(iStack_28 + val_2);
            iStack_20 = val_4;
          }
        }
        return *(int32_t *)(&DAT_10128a30 + uStack_1c * 4);
      }
      return *(int32_t *)(&DAT_10128a30 + i_ptr_3[1] * 4);
    }
    i_ptr_3 = i_ptr_1;
  } while ((char)*i_ptr_1 != '\x01');
  return *(int32_t *)(&DAT_10128a30 + i_ptr_1[1] * 4);
}


