/*
 * Decompiled function: __realloc_base
 * Entry Point: 004e1bd0
 * Size: 518 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __realloc_base
   
   Library: Visual Studio 1998 Debug */

void * __realloc_base(void *arg1,uint arg2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int local_18;
  uint local_14;
  byte *local_10;
  void *local_c;
  undefined4 *local_8;
  
  if (arg1 == (void *)0x0) {
    pvVar1 = (void *)__malloc_base(arg2);
  }
  else if (arg2 == 0) {
    __free_base(arg1);
    pvVar1 = (void *)0x0;
  }
  else {
    if (arg2 < 0xffffffe1) {
      if (arg2 == 0) {
        arg2 = 0x10;
      }
      else {
        arg2 = arg2 + 0xf & 0xfffffff0;
      }
    }
    do {
      local_c = (void *)0x0;
      if (arg2 < 0xffffffe1) {
        local_10 = (byte *)___sbh_find_block(arg1,&local_18,(uint *)&local_8);
        if (local_10 == (byte *)0x0) {
          local_c = HeapReAlloc(DAT_006c1c94,0,arg1,arg2);
        }
        else {
          if (arg2 < DAT_0050a1fc) {
            iVar2 = ___sbh_resize_block(local_18,local_8,local_10,arg2 >> 4);
            if (iVar2 == 0) {
              local_c = (void *)___sbh_alloc_block(arg2 >> 4);
              if (local_c != (void *)0x0) {
                local_14 = (uint)*local_10 << 4;
                uVar3 = arg2;
                if (local_14 <= arg2) {
                  uVar3 = local_14;
                }
                FID_conflict__memcpy(local_c,arg1,uVar3);
                ___sbh_free_block(local_18,(int)local_8,(char *)local_10);
              }
            }
            else {
              local_c = arg1;
            }
          }
          if ((local_c == (void *)0x0) &&
             (local_c = HeapAlloc(DAT_006c1c94,0,arg2), local_c != (LPVOID)0x0)) {
            local_14 = (uint)*local_10 << 4;
            uVar3 = arg2;
            if (local_14 <= arg2) {
              uVar3 = local_14;
            }
            FID_conflict__memcpy(local_c,arg1,uVar3);
            ___sbh_free_block(local_18,(int)local_8,(char *)local_10);
          }
        }
      }
      if (local_c != (void *)0x0) {
        return local_c;
      }
      if (DAT_005099d4 == 0) {
        return (void *)0x0;
      }
      iVar2 = __callnewh(arg2);
    } while (iVar2 != 0);
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}


