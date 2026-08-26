/*
 * Decompiled function: FUN_004219e1
 * Entry Point: 004219e1
 * Size: 160 bytes
 */
#include "magic.h"


void FUN_004219e1(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int arg_4_00;
  int arg_5_00;
  
  arg_4_00 = arg_2 + arg_4;
  arg_5_00 = arg_5 + arg_3;
  Surface_DrawLine(arg_1,arg_2,arg_3,arg_4_00,arg_3,arg_6);
  Surface_DrawLine(arg_1,arg_4_00,arg_3,arg_4_00,arg_5_00,arg_6);
  Surface_DrawLine(arg_1,arg_4_00,arg_5_00,arg_2,arg_5_00,arg_6);
  Surface_DrawLine(arg_1,arg_2,arg_5_00,arg_2,arg_3,arg_6);
  return;
}


