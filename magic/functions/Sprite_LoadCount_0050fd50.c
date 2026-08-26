/*
 * Decompiled function: Sprite_LoadCount
 * Entry Point: 0050fd50
 * Size: 149 bytes
 */
#include "magic.h"


uint Sprite_LoadCount(undefined4 *arg_1,char *str_2,uint arg_3)

{
  FILE *_File;
  int iVar1;
  size_t _Size;
  int *_DstBuf;
  uint uVar2;
  
  _File = fopen(str_2,&DAT_0052afc4);
  AssertOrLog((int)_File,0x53276c,0xc5,s_Could_not_open_Sprite_File__s_00532790);
  iVar1 = _fileno(_File);
  _Size = _filelength(iVar1);
  _DstBuf = malloc(_Size);
  fread(_DstBuf,1,_Size,_File);
  fclose(_File);
  iVar1 = *_DstBuf;
  for (uVar2 = 0; (iVar1 != -1 && (uVar2 < arg_3)); uVar2 = uVar2 + 1) {
    *arg_1 = _DstBuf;
    arg_1 = arg_1 + 1;
    _DstBuf = (int *)((int)_DstBuf + *_DstBuf);
    iVar1 = *_DstBuf;
  }
  return uVar2;
}


