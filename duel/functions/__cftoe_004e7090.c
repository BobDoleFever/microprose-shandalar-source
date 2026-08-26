/*
 * Decompiled function: __cftoe
 * Entry Point: 004e7090
 * Size: 458 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cftoe
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __cftoe(double *ptr_1,char *str_2,size_t arg_3,int arg_4,int arg_5)

{
  undefined1 *puVar1;
  STRFLT unaff_EDI;
  int local_10;
  int *local_c;
  char *local_8;
  
  if (DAT_0050a5c8 == '\0') {
    local_c = (int *)__fltout(*(undefined4 *)ptr_1,*(undefined4 *)((int)ptr_1 + 4));
    __fptostr(str_2 + (uint)(*local_c == 0x2d) + (uint)(0 < (int)arg_3),arg_3 + 1,(int)local_c,
              unaff_EDI);
  }
  else {
    local_c = DAT_005edb14;
    __shift(str_2 + (*DAT_005edb14 == 0x2d),(uint)(0 < (int)arg_3));
  }
  local_8 = str_2;
  if (*local_c == 0x2d) {
    *str_2 = '-';
    local_8 = str_2 + 1;
  }
  if (0 < (int)arg_3) {
    *local_8 = local_8[1];
    local_8 = local_8 + 1;
    *local_8 = DAT_005096b0;
  }
  puVar1 = (undefined1 *)
           Mem_AllocOrFree_004d9630
                     ((uint *)(local_8 + (DAT_0050a5c8 == '\0') + arg_3),(uint *)"e+000");
  if (arg_4 != 0) {
    *puVar1 = 0x45;
  }
  if (*(char *)local_c[3] != '0') {
    local_10 = local_c[1] + -1;
    if (local_10 < 0) {
      local_10 = -local_10;
      puVar1[1] = 0x2d;
    }
    if (99 < local_10) {
      puVar1[2] = (char)(local_10 / 100) + puVar1[2];
      local_10 = local_10 % 100;
    }
    if (9 < local_10) {
      puVar1[3] = (char)(local_10 / 10) + puVar1[3];
      local_10 = local_10 % 10;
    }
    puVar1[4] = puVar1[4] + (char)local_10;
  }
  return (errno_t)str_2;
}


