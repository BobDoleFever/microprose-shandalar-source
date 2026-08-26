/*
 * Decompiled function: Sprite_LoadAll
 * Entry Point: 0050fcc0
 * Size: 141 bytes
 */
#include "magic.h"


int Sprite_LoadAll(undefined4 *arg1,char *str_2)

{
  FILE *_File;
  int iVar1;
  size_t _Size;
  int *_DstBuf;
  int iVar2;
  
  iVar2 = 0;
  _File = fopen(str_2,&DAT_0052afc4);
  AssertOrLog((int)_File,0x53276c,0xa3,s_Could_not_open_Sprite_File__s_00532790);
  iVar1 = _fileno(_File);
  _Size = _filelength(iVar1);
  _DstBuf = malloc(_Size);
  fread(_DstBuf,1,_Size,_File);
  fclose(_File);
  iVar1 = *_DstBuf;
  while (iVar1 != -1) {
    *arg1 = _DstBuf;
    arg1 = arg1 + 1;
    iVar2 = iVar2 + 1;
    _DstBuf = (int *)((int)_DstBuf + *_DstBuf);
    iVar1 = *_DstBuf;
  }
  return iVar2;
}


