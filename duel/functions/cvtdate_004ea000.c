/*
 * Decompiled function: cvtdate
 * Entry Point: 004ea000
 * Size: 515 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _cvtdate
   
   Library: Visual Studio 1998 Debug */

void __cdecl
cvtdate(int arg_1,int arg_2,uint arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9,
       int arg_10,int arg_11)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  
  if (arg_2 == 1) {
    if ((arg_3 & 3) == 0) {
      local_10 = *(int *)(&DAT_0050a834 + arg_4 * 4);
    }
    else {
      local_10 = *(int *)(&DAT_0050a86c + arg_4 * 4);
    }
    iVar1 = (int)((arg_3 - 0x46) * 0x16d + ((int)(arg_3 - 1) >> 2) + -0xd + local_10 + 1) % 7;
    if (iVar1 < arg_6) {
      local_c = (arg_6 - iVar1) + (arg_5 + -1) * 7;
    }
    else {
      local_c = (arg_6 - iVar1) + arg_5 * 7;
    }
    local_c = local_10 + 1 + local_c;
    if (arg_5 == 5) {
      if ((arg_3 & 3) == 0) {
        local_14 = *(int *)(&DAT_0050a838 + arg_4 * 4);
      }
      else {
        local_14 = *(int *)(&DAT_0050a870 + arg_4 * 4);
      }
      if (local_14 < local_c) {
        local_c = local_c + -7;
      }
    }
  }
  else {
    if ((arg_3 & 3) == 0) {
      local_c = *(int *)(&DAT_0050a834 + arg_4 * 4);
    }
    else {
      local_c = *(int *)(&DAT_0050a86c + arg_4 * 4);
    }
    local_c = local_c + arg_7;
  }
  if (arg_1 == 1) {
    DAT_0050a7f4 = local_c;
    DAT_0050a7f8 = ((arg_8 * 0x3c + arg_9) * 0x3c + arg_10) * 1000 + arg_11;
    DAT_0050a7f0 = arg_3;
  }
  else {
    DAT_0050a804 = local_c;
    DAT_0050a808 = ((arg_8 * 0x3c + arg_9) * 0x3c + arg_10) * 1000 + arg_11 + DAT_0050a758 * 1000;
    if (DAT_0050a808 < 0) {
      DAT_0050a808 = DAT_0050a808 + 86399999;
    }
    else if (86399999 < DAT_0050a808) {
      DAT_0050a808 = DAT_0050a808 + -86399999;
    }
    DAT_0050a800 = arg_3;
  }
  return;
}


