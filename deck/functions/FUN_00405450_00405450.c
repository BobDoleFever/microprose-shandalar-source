/*
 * Decompiled function: FUN_00405450
 * Entry Point: 00405450
 * Size: 7 bytes
 */
#include "deck.h"


uint32_t * __cdecl FUN_00405450(uint32_t *ptr_1,uint32_t *ptr_2)

{
  uint8_t flag_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t *puVar4;
  
  puVar4 = ptr_1;
  while (((uint32_t)ptr_2 & 3) != 0) {
    flag_1 = (uint8_t)*ptr_2;
    uval_3 = (uint32_t)flag_1;
    ptr_2 = (uint32_t *)((int)ptr_2 + 1);
    if (flag_1 == 0) goto LAB_00405538;
    *(uint8_t *)puVar4 = flag_1;
    puVar4 = (uint32_t *)((int)puVar4 + 1);
  }
  do {
    uval_2 = *ptr_2;
    uval_3 = *ptr_2;
    ptr_2 = ptr_2 + 1;
    if (((uval_2 ^ 0xffffffff ^ uval_2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uval_3 == '\0') {
LAB_00405538:
        *(uint8_t *)puVar4 = (uint8_t)uval_3;
        return ptr_1;
      }
      if ((char)(uval_3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uval_3;
        return ptr_1;
      }
      if ((uval_3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uval_3;
        *(uint8_t *)((int)puVar4 + 2) = 0;
        return ptr_1;
      }
      if ((uval_3 & 0xff000000) == 0) {
        *puVar4 = uval_3;
        return ptr_1;
      }
    }
    *puVar4 = uval_3;
    puVar4 = puVar4 + 1;
  } while( true );
}


