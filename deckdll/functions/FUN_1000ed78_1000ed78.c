/*
 * Decompiled function: FUN_1000ed78
 * Entry Point: 1000ed78
 * Size: 371 bytes
 */
#include "deckdll.h"


uint32_t FUN_1000ed78(uint32_t arg_1)

{
  int *i_ptr_1;
  int val_2;
  int *i_ptr_3;
  int val_4;
  uint8_t *pbVar5;
  int local_28;
  int local_20;
  uint32_t local_1c;
  
  thunk_FUN_1000ea83(arg_1,(uint32_t *)&DAT_10128e38);
  pbVar5 = &DAT_10128e38;
  i_ptr_3 = DAT_1012925c;
  do {
    i_ptr_1 = (int *)i_ptr_3[*pbVar5 + 2];
    pbVar5 = pbVar5 + 1;
    if (i_ptr_1 == (int *)0x0) {
      if (*i_ptr_3 == 0) {
        val_2 = i_ptr_3[10];
        local_20 = 0x7fffffff;
        for (local_28 = 0; local_28 < i_ptr_3[0xb]; local_28 = local_28 + 1) {
          val_4 = *(int *)(PTR_DAT_1004156c +
                          ((arg_1 >> 8 & 0xff) -
                          (uint32_t)(uint8_t)(&DAT_10128a31)[(uint32_t)*(uint8_t *)(local_28 + val_2) * 4]) * 4) +
                  *(int *)(PTR_DAT_1004156c +
                          (((arg_1 & 0xff0000) >> 0x10) -
                          (*(uint32_t *)(&DAT_10128a30 + (uint32_t)*(uint8_t *)(local_28 + val_2) * 4) & 0xff))
                          * 4) +
                  *(int *)(PTR_DAT_1004156c +
                          ((arg_1 & 0xff) -
                          ((*(uint32_t *)(&DAT_10128a30 + (uint32_t)*(uint8_t *)(local_28 + val_2) * 4) &
                           0xff0000) >> 0x10)) * 4);
          if (val_4 < local_20) {
            local_1c = (uint32_t)*(uint8_t *)(local_28 + val_2);
            local_20 = val_4;
          }
        }
        return local_1c;
      }
      return i_ptr_3[1];
    }
    i_ptr_3 = i_ptr_1;
  } while ((char)*i_ptr_1 != '\x01');
  return i_ptr_1[1];
}


