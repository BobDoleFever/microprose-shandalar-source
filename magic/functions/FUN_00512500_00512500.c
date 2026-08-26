/*
 * Decompiled function: FUN_00512500
 * Entry Point: 00512500
 * Size: 421 bytes
 */
#include "magic.h"


undefined4 FUN_00512500(void *arg_1)

{
  int iVar1;
  
  fread(&DAT_00703940,0x80,1,DAT_00703930);
  AssertOrLog((uint)(DAT_00703940 == '\n'),(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0xad
              ,s__s_Not_a_pcx_file_00536d30);
  AssertOrLog((uint)(DAT_00703941 == '\x05'),(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,
              0xae,s__s_Not_a_version_5_pcx_file_00536d10);
  DAT_00536860 = ((uint)DAT_00703948 - (uint)DAT_00703944) + 1;
  DAT_00536864 = ((uint)DAT_0070394a - (uint)DAT_00703946) + 1;
  if (arg_1 == (void *)0x0) {
    return 1;
  }
  if ((DAT_00703981 == '\x01') && (DAT_00703943 == '\b')) {
    fseek(DAT_00703930,-0x300,2);
    fread(arg_1,1,0x300,DAT_00703930);
    fseek(DAT_00703930,0x80,0);
    return 1;
  }
  if ((DAT_00703981 == '\x04') && (DAT_00703943 == '\x01')) {
    iVar1 = 0x10;
    fseek(DAT_00703930,0x10,2);
    do {
      fread(arg_1,1,3,DAT_00703930);
      iVar1 = iVar1 + -1;
      arg_1 = (void *)((int)arg_1 + 4);
    } while (iVar1 != 0);
    fseek(DAT_00703930,0x80,0);
    return 1;
  }
  AssertOrLog(0,(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0xd4,
              s__s_is_not_in_a_recognizable_form_00536ce8);
  return 1;
}


