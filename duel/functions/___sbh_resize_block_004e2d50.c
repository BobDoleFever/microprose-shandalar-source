/*
 * Decompiled function: ___sbh_resize_block
 * Entry Point: 004e2d50
 * Size: 439 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 1998 Debug */

undefined4 ___sbh_resize_block(int x,undefined4 *arg_2,byte *arg_3,uint height)

{
  byte bVar1;
  uint uVar2;
  byte *local_18;
  undefined4 local_14;
  byte *local_10;
  int local_8;
  
  local_14 = 0;
  bVar1 = *arg_3;
  uVar2 = (uint)bVar1;
  if (height < uVar2) {
    *arg_3 = (byte)height;
    *(byte *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) =
         (*(char *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) - (byte)height) + bVar1;
    *(undefined1 *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x410 + x) = 0xf1;
    local_14 = 1;
  }
  else if ((uVar2 < height) && (arg_3 + height <= arg_2 + 0x3e)) {
    local_18 = arg_3 + height;
    for (local_10 = arg_3 + uVar2; (local_10 < local_18 && (*local_10 == 0));
        local_10 = local_10 + 1) {
    }
    if (local_18 == local_10) {
      *arg_3 = (byte)height;
      if ((arg_3 <= (byte *)*arg_2) && ((byte *)*arg_2 < local_18)) {
        if (local_18 < arg_2 + 0x3e) {
          *arg_2 = local_18;
          local_8 = 0;
          for (; *local_18 == 0; local_18 = local_18 + 1) {
            local_8 = local_8 + 1;
          }
          arg_2[1] = local_8;
        }
        else {
          *arg_2 = arg_2 + 2;
          arg_2[1] = 0;
        }
      }
      *(byte *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) =
           (*(char *)(((int)arg_2 - *(int *)(x + 0x810) >> 0xc) + 0x10 + x) - (byte)height) + bVar1;
      local_14 = 1;
    }
  }
  return local_14;
}


