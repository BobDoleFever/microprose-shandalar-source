/*
 * Decompiled function: FUN_0050f0f0
 * Entry Point: 0050f0f0
 * Size: 237 bytes
 */
#include "magic.h"


undefined4 FUN_0050f0f0(int arg_1,int arg_2,char *str_3)

{
  FILE *_File;
  undefined4 uVar1;
  long *_DstBuf;
  int iVar2;
  int local_44;
  long alStack_40 [16];
  
  local_44 = 0;
  AssertOrLog((uint)(arg_1 < 0x10),0x532744,0xd7,s_Can_not_load_more_than__d_fonts_00532720);
  _File = fopen(str_3,&DAT_0052afc4);
  AssertOrLog((uint)(_File != (FILE *)0x0),0x532744,0xd9,
              PTR_s_File__s_could_not_be_opened__EXI_00530fb0);
  iVar2 = 1;
  fread(&local_44,2,1,_File);
  if (1 < local_44) {
    _DstBuf = alStack_40;
    do {
      _DstBuf = _DstBuf + 1;
      iVar2 = iVar2 + 1;
      *_DstBuf = 0;
      fread(_DstBuf,2,1,_File);
    } while (iVar2 < local_44);
  }
  if (local_44 <= arg_2) {
    return 0xffffffff;
  }
  fseek(_File,alStack_40[arg_2],0);
  uVar1 = FUN_0050eef0(arg_1,_File);
  return uVar1;
}


