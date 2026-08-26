/*
 * Decompiled function: ___sbh_resize_block
 * Entry Point: 00406500
 * Size: 439 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl ___sbh_resize_block(int x,int32_t *y,uint8_t *width,uint32_t height)

{
  uint8_t flag_1;
  uint32_t uval_2;
  uint8_t *local_18;
  int32_t local_14;
  uint8_t *local_10;
  int local_8;
  
  local_14 = 0;
  flag_1 = *width;
  uval_2 = (uint32_t)flag_1;
  if (height < uval_2) {
    *width = (uint8_t)height;
    *(uint8_t *)(((int)y - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) =
         (*(char *)(((int)y - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) - (uint8_t)height) + flag_1;
    *(uint8_t *)(((int)y - *(int *)(x + 0x810) >> 0xc) + 0x410 + x) = 0xf1;
    local_14 = 1;
  }
  else if ((uval_2 < height) && (width + height <= y + 0x3e)) {
    local_18 = width + height;
    for (local_10 = width + uval_2; (local_10 < local_18 && (*local_10 == 0));
        local_10 = local_10 + 1) {
    }
    if (local_18 == local_10) {
      *width = (uint8_t)height;
      if ((width <= (uint8_t *)*y) && ((uint8_t *)*y < local_18)) {
        if (local_18 < y + 0x3e) {
          *y = local_18;
          local_8 = 0;
          for (; *local_18 == 0; local_18 = local_18 + 1) {
            local_8 = local_8 + 1;
          }
          y[1] = local_8;
        }
        else {
          *y = y + 2;
          y[1] = 0;
        }
      }
      *(uint8_t *)(((int)y - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) =
           (*(char *)(((int)y - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) - (uint8_t)height) + flag_1;
      local_14 = 1;
    }
  }
  return local_14;
}


