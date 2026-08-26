/*
 * Decompiled function: FUN_0050edf0
 * Entry Point: 0050edf0
 * Size: 253 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0050edf0(char *str_1)

{
  FILE *_File;
  int iVar1;
  long *_DstBuf;
  int iVar2;
  int local_44;
  long alStack_40 [16];
  
  local_44 = 0;
  _File = fopen(str_1,&DAT_0052afc4);
  AssertOrLog((uint)(_File != (FILE *)0x0),0x532744,0x7f,
              PTR_s_File__s_could_not_be_opened__EXI_00530fb0);
  fread(&local_44,2,1,_File);
  _DAT_00707710 = local_44;
  iVar1 = 1;
  AssertOrLog((uint)(local_44 < 0x10),0x532744,0x86,s_Can_not_load_more_than__d_fonts_00532720);
  if (0 < local_44) {
    _DstBuf = alStack_40;
    do {
      _DstBuf = _DstBuf + 1;
      iVar1 = iVar1 + 1;
      *_DstBuf = 0;
      fread(_DstBuf,2,1,_File);
    } while (iVar1 <= local_44);
  }
  iVar1 = 1;
  if (0 < local_44) {
    do {
      fseek(_File,alStack_40[iVar1],0);
      iVar2 = iVar1 + 1;
      FUN_0050eef0(iVar1,_File);
      iVar1 = iVar2;
    } while (iVar2 <= local_44);
  }
  fclose(_File);
  return local_44;
}


