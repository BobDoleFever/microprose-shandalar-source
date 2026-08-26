/*
 * Decompiled function: FUN_0044c47a
 * Entry Point: 0044c47a
 * Size: 486 bytes
 */
#include "duel.h"


undefined4 FUN_0044c47a(void *arg_1)

{
  int local_8;
  
  _fread(&DAT_00694440,0x80,1,DAT_00694430);
  Assert_Handler_00499950
            ((uint)(DAT_00694440 == '\n'),(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0xad,
             s__s_Not_a_pcx_file_004f81c8);
  Assert_Handler_00499950
            ((uint)(DAT_00694441 == '\x05'),(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,
             0xae,s__s_Not_a_version_5_pcx_file_004f81dc);
  DAT_004ff154 = ((uint)DAT_00694448 - (uint)DAT_00694444) + 1;
  DAT_004ff158 = ((uint)DAT_0069444a - (uint)DAT_00694446) + 1;
  if (arg_1 != (void *)0x0) {
    if ((DAT_00694481 == '\x01') && (DAT_00694443 == '\b')) {
      _fseek(DAT_00694430,-0x300,2);
      _fread(arg_1,1,0x300,DAT_00694430);
      _fseek(DAT_00694430,0x80,0);
    }
    else if ((DAT_00694481 == '\x04') && (DAT_00694443 == '\x01')) {
      _fseek(DAT_00694430,0x10,2);
      for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
        _fread((void *)(local_8 * 4 + (int)arg_1),1,3,DAT_00694430);
      }
      _fseek(DAT_00694430,0x80,0);
    }
    else {
      Assert_Handler_00499950
                (0,(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0xd4,
                 s__s_is_not_in_a_recognizable_form_004f81fc);
    }
  }
  return 1;
}


