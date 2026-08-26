/*
 * Decompiled function: __realloc_base
 * Entry Point: 004076d0
 * Size: 518 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __realloc_base
   
   Library: Visual Studio 1998 Debug */

uint8_t * __cdecl __realloc_base(uint8_t *ptr_1,uint32_t arg_2)

{
  uint8_t *u_ptr_1;
  int val_2;
  uint32_t uval_3;
  int local_18;
  uint32_t local_14;
  uint8_t *local_10;
  uint8_t *local_c;
  int32_t *local_8;
  
  if (ptr_1 == (uint8_t *)0x0) {
    u_ptr_1 = (uint8_t *)__malloc_base(arg_2);
  }
  else if (arg_2 == 0) {
    __free_base(ptr_1);
    u_ptr_1 = (uint8_t *)0x0;
  }
  else {
    if (arg_2 < 0xffffffe1) {
      if (arg_2 == 0) {
        arg_2 = 0x10;
      }
      else {
        arg_2 = arg_2 + 0xf & 0xfffffff0;
      }
    }
    do {
      local_c = (uint8_t *)0x0;
      if (arg_2 < 0xffffffe1) {
        local_10 = (uint8_t *)___sbh_find_block(ptr_1,&local_18,(uint32_t *)&local_8);
        if (local_10 == (uint8_t *)0x0) {
          local_c = HeapReAlloc(DAT_004156ac,0,ptr_1,arg_2);
        }
        else {
          if (arg_2 < DAT_004138ac) {
            val_2 = ___sbh_resize_block(local_18,local_8,local_10,arg_2 >> 4);
            if (val_2 == 0) {
              local_c = ___sbh_alloc_block(arg_2 >> 4);
              if (local_c != (uint8_t *)0x0) {
                local_14 = (uint32_t)*local_10 << 4;
                uval_3 = arg_2;
                if (local_14 <= arg_2) {
                  uval_3 = local_14;
                }
                FID_conflict__memcpy(local_c,ptr_1,uval_3);
                ___sbh_free_block(local_18,(int)local_8,(char *)local_10);
              }
            }
            else {
              local_c = ptr_1;
            }
          }
          if ((local_c == (uint8_t *)0x0) &&
             (local_c = HeapAlloc(DAT_004156ac,0,arg_2), local_c != (uint8_t *)0x0)) {
            local_14 = (uint32_t)*local_10 << 4;
            uval_3 = arg_2;
            if (local_14 <= arg_2) {
              uval_3 = local_14;
            }
            FID_conflict__memcpy(local_c,ptr_1,uval_3);
            ___sbh_free_block(local_18,(int)local_8,(char *)local_10);
          }
        }
      }
      if (local_c != (uint8_t *)0x0) {
        return local_c;
      }
      if (DAT_004138f8 == 0) {
        return (uint8_t *)0x0;
      }
      val_2 = __callnewh(arg_2);
    } while (val_2 != 0);
    u_ptr_1 = (uint8_t *)0x0;
  }
  return u_ptr_1;
}


