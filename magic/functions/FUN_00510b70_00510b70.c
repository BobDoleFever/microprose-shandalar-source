/*
 * Decompiled function: FUN_00510b70
 * Entry Point: 00510b70
 * Size: 610 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00510b70(int arg_1,int arg_2,int arg_3,char *str_4,short *arg_5)

{
  char *_Str2;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 arg_1_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 arg_2_00;
  short local_400 [512];
  
  _Str2 = strchr(str_4,0x2e);
  iVar1 = _stricmp(&DAT_005327f4,_Str2);
  if (iVar1 != 0) {
    iVar1 = _open(str_4,0x8000);
    arg_1_00 = extraout_ECX;
    arg_2_00 = extraout_EDX;
    if (iVar1 == -1) {
      AssertOrLog(0,0x5327b8,0x87,str_4);
      arg_1_00 = extraout_ECX_00;
      arg_2_00 = extraout_EDX_00;
    }
    DAT_00706500 = PTR_DAT_005327b0;
    _DAT_006261ac = 0xffffffff;
    DAT_0067f43c = &LAB_00510f90;
    DAT_006261a8 = iVar1;
    DAT_006261b0 = iVar1;
    FUN_0070d000(arg_1_00,arg_2_00,(ushort *)arg_5);
    if (arg_1 < 0) {
      DAT_00536864 = 0;
    }
    DAT_006261a4 = 0;
    if (0 < DAT_00536864) {
      do {
        Mem_AllocOrFree_0070d484(&DAT_00706710,DAT_00536860);
        Surface_PutLine((undefined4 *)&DAT_00706710,arg_1,arg_2,DAT_006261a4 + arg_3,DAT_00536860);
        DAT_006261a4 = DAT_006261a4 + 1;
      } while (DAT_006261a4 < DAT_00536864);
    }
    if ((DAT_005327b4 != DAT_006261b0) && (iVar1 = _close(DAT_006261b0), iVar1 != 0)) {
      AssertOrLog(0,0x5327b8,0xa7,(char *)0x0);
    }
    return;
  }
  DAT_00703930 = (int)fopen(str_4,&DAT_0052afc4);
  AssertOrLog((uint)((FILE *)DAT_00703930 != (FILE *)0x0),0x5327b8,0xf6,
              s_Error_Opening_File__s_005327dc);
  DAT_00703938 = str_4;
  if (arg_5 == (short *)0x1) {
    arg_5 = local_400;
  }
  if (arg_5 == (short *)0x0) {
    FUN_00512500((void *)0x0);
  }
  else {
    FUN_00512500(arg_5 + 3);
    *(undefined1 *)arg_5 = 0x4d;
    *(undefined1 *)((int)arg_5 + 1) = 0x31;
    arg_5[1] = 0x300;
    *(undefined1 *)(arg_5 + 2) = 0;
    *(undefined1 *)((int)arg_5 + 5) = 0xff;
    FUN_0050e8b0(arg_5);
  }
  if (arg_1 < 0) {
    DAT_00536864 = 0;
  }
  DAT_006261a4 = 0;
  if (0 < DAT_00536864) {
    do {
      FUN_005126b0(&DAT_00706710);
      Surface_PutLine((undefined4 *)&DAT_00706710,arg_1,arg_2,DAT_006261a4 + arg_3,DAT_00536860);
      DAT_006261a4 = DAT_006261a4 + 1;
    } while (DAT_006261a4 < DAT_00536864);
  }
  fclose((FILE *)DAT_00703930);
  return;
}


