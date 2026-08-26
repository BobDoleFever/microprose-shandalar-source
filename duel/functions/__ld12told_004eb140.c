/*
 * Decompiled function: __ld12told
 * Entry Point: 004eb140
 * Size: 201 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ld12told
   
   Library: Visual Studio 1998 Debug */

INTRNCVT_STATUS __cdecl __ld12told(_LDBL12 *ptr_1,_LDOUBLE *ptr_2)

{
  ushort uVar1;
  int iVar2;
  INTRNCVT_STATUS local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(ptr_1->ld12 + 10)) & 0xffff7fff;
  uVar1 = *(ushort *)(ptr_1->ld12 + 10);
  local_14 = *(undefined4 *)(ptr_1->ld12 + 6);
  local_10 = *(undefined4 *)(ptr_1->ld12 + 2);
  local_c = (uint)*(ushort *)ptr_1->ld12 << 0x10;
  iVar2 = __RoundMan((int)&local_14,0x40);
  if (iVar2 != 0) {
    local_14 = 0x80000000;
    local_8 = (uint)(ushort)((short)local_8 + 1);
  }
  local_18 = (INTRNCVT_STATUS)((local_8 & 0xffff) == 0x7fff);
  *(undefined4 *)(ptr_2->ld + 4) = local_14;
  *(undefined4 *)ptr_2->ld = local_10;
  *(ushort *)(ptr_2->ld + 8) = uVar1 & 0x8000 | (ushort)local_8;
  return local_18;
}


