/*
 * Decompiled function: FUN_00488fdb
 * Entry Point: 00488fdb
 * Size: 429 bytes
 */
#include "magic.h"


void FUN_00488fdb(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,char *str_6,char *str_7)

{
  byte *pbVar1;
  undefined1 uVar2;
  int iVar3;
  byte local_42c [1040];
  int local_1c;
  int local_18;
  uint local_14;
  uint local_c;
  uint local_8;
  
  iVar3 = strcmp(PTR_DAT_00527aa4,str_6);
  if (iVar3 == 0) {
    iVar3 = strcmp(PTR_DAT_00527aa8,str_7);
    if (iVar3 == 0) goto LAB_004890e3;
  }
  FUN_00510b70(-1,0,0,str_6,(short *)&DAT_00539928);
  FUN_00510b70(-1,0,0,str_7,(short *)&DAT_00539600);
  DAT_00539c48 = &DAT_0053992e;
  PTR_DAT_00527aa4 = str_6;
  PTR_DAT_00527aa8 = str_7;
  for (local_18 = 0; pbVar1 = DAT_00539c48, local_18 < 0x100; local_18 = local_18 + 1) {
    local_c = (uint)*DAT_00539c48;
    DAT_00539c48 = DAT_00539c48 + 1;
    local_14 = (uint)*DAT_00539c48;
    DAT_00539c48 = pbVar1 + 2;
    local_8 = (uint)*DAT_00539c48;
    DAT_00539c48 = pbVar1 + 3;
    uVar2 = Ai_Subsystem_004c22a2(local_c,local_14,local_8,&DAT_00539606);
    (&DAT_00539c50)[local_18] = uVar2;
  }
LAB_004890e3:
  for (local_1c = arg_3; local_1c < arg_5 + arg_3; local_1c = local_1c + 1) {
    Surface_GetLine((undefined4 *)local_42c,*arg_1,arg_2,local_1c,arg_4);
    for (local_18 = 0; local_18 < arg_4; local_18 = local_18 + 1) {
      local_42c[local_18] = (&DAT_00539c50)[local_42c[local_18]];
    }
    Surface_PutLine((undefined4 *)local_42c,*arg_1,arg_2,local_1c,arg_4);
  }
  return;
}


