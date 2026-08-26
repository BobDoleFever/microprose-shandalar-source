/*
 * Decompiled function: FUN_00512740
 * Entry Point: 00512740
 * Size: 422 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00512740(void)

{
  int arg_4;
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int in_stack_00001008;
  char *in_stack_0000100c;
  void *in_stack_00001010;
  int in_stack_00001014;
  int in_stack_00001018;
  uint in_stack_0000101c;
  int in_stack_00001020;
  
  Mem_AllocOrFree_00513bd0();
  DAT_00703934 = (int)fopen(in_stack_0000100c,&DAT_00536d44);
  AssertOrLog((uint)((FILE *)DAT_00703934 != (FILE *)0x0),
              (int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x146,
              s_Error_Opening_File__s_005327dc);
  DAT_00703940 = 10;
  iVar3 = 0;
  DAT_00703944 = 0;
  uVar2 = (ushort)in_stack_0000101c;
  DAT_00703948 = uVar2 - 1;
  DAT_00703941 = 5;
  DAT_00703942 = 1;
  DAT_00703943 = 8;
  DAT_0070394a = (short)in_stack_00001020 + -1;
  DAT_00703980 = 0;
  DAT_00703981 = 1;
  DAT_00703946 = 0;
  _DAT_0070394c = 0;
  uVar1 = (ushort)((int)in_stack_0000101c >> 0x1f);
  _DAT_0070394e = 0;
  _DAT_00703986 = 0;
  _DAT_00703988 = 0;
  DAT_00703982 = (((uVar2 ^ uVar1) - uVar1 & 1 ^ uVar1) - uVar1) + uVar2;
  _DAT_00703984 = 1;
  DAT_00703938 = in_stack_0000100c;
  fwrite(&DAT_00703940,0x80,1,(FILE *)DAT_00703934);
  if (0 < in_stack_00001020) {
    do {
      arg_4 = in_stack_00001018 + iVar3;
      iVar3 = iVar3 + 1;
      Surface_GetLine((undefined4 *)&stack0x00000004,in_stack_00001008,in_stack_00001014,arg_4,
                      in_stack_0000101c);
      FUN_005129a0(&stack0x00000004,in_stack_0000101c);
    } while (iVar3 < in_stack_00001020);
  }
  fwrite(&stack0x00000003,1,1,(FILE *)DAT_00703934);
  fwrite(in_stack_00001010,3,0x100,(FILE *)DAT_00703934);
  fclose((FILE *)DAT_00703934);
  return 0;
}


