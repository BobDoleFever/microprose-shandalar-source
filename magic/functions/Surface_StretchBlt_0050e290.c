/*
 * Decompiled function: Surface_StretchBlt
 * Entry Point: 0050e290
 * Size: 91 bytes
 */
#include "magic.h"


void Surface_StretchBlt(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,int arg_7,
                       int arg_8,int arg_9,int arg_10)

{
  StretchBlt(*(HDC *)((&DAT_0070a850)[*arg_6] + 4),arg_7,arg_8,arg_9,arg_10,
             *(HDC *)((&DAT_0070a850)[*arg_1] + 4),arg_2,arg_3,arg_4,arg_5,0xcc0020);
  return;
}


