/*
 * Decompiled function: FUN_00405460
 * Entry Point: 00405460
 * Size: 224 bytes
 */
#include "deck.h"


uint32_t * __cdecl FUN_00405460(uint32_t *ptr_1,uint32_t *ptr_2)

{
  uint8_t flag_1;
  uint32_t uval_2;
  uint32_t *u_ptr_3;
  uint32_t uval_4;
  uint32_t *puVar5;
  
  u_ptr_3 = ptr_1;
  do {
    if (((uint32_t)u_ptr_3 & 3) == 0) goto LAB_0040547c;
    uval_4 = *u_ptr_3;
    u_ptr_3 = (uint32_t *)((int)u_ptr_3 + 1);
  } while ((uint8_t)uval_4 != 0);
  goto LAB_004054af;
  while( true ) {
    if ((uval_4 & 0xff0000) == 0) {
      puVar5 = (uint32_t *)((int)puVar5 + 2);
      goto joined_r0x004054cb;
    }
    if ((uval_4 & 0xff000000) == 0) break;
LAB_0040547c:
    do {
      puVar5 = u_ptr_3;
      u_ptr_3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uval_4 = *puVar5;
    if ((char)uval_4 == '\0') goto joined_r0x004054cb;
    if ((char)(uval_4 >> 8) == '\0') {
      puVar5 = (uint32_t *)((int)puVar5 + 1);
      goto joined_r0x004054cb;
    }
  }
LAB_004054af:
  puVar5 = (uint32_t *)((int)u_ptr_3 + -1);
joined_r0x004054cb:
  do {
    if (((uint32_t)ptr_2 & 3) == 0) {
      do {
        uval_2 = *ptr_2;
        uval_4 = *ptr_2;
        ptr_2 = ptr_2 + 1;
        if (((uval_2 ^ 0xffffffff ^ uval_2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uval_4 == '\0') {
LAB_00405538:
            *(uint8_t *)puVar5 = (uint8_t)uval_4;
            return ptr_1;
          }
          if ((char)(uval_4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uval_4;
            return ptr_1;
          }
          if ((uval_4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uval_4;
            *(uint8_t *)((int)puVar5 + 2) = 0;
            return ptr_1;
          }
          if ((uval_4 & 0xff000000) == 0) {
            *puVar5 = uval_4;
            return ptr_1;
          }
        }
        *puVar5 = uval_4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    flag_1 = (uint8_t)*ptr_2;
    uval_4 = (uint32_t)flag_1;
    ptr_2 = (uint32_t *)((int)ptr_2 + 1);
    if (flag_1 == 0) goto LAB_00405538;
    *(uint8_t *)puVar5 = flag_1;
    puVar5 = (uint32_t *)((int)puVar5 + 1);
  } while( true );
}


