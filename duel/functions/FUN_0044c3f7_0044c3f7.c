/*
 * Decompiled function: FUN_0044c3f7
 * Entry Point: 0044c3f7
 * Size: 131 bytes
 */
#include "duel.h"


bool FUN_0044c3f7(char *str_1,void *arg2)

{
  int iVar1;
  
  DAT_00694430 = _fopen(str_1,&DAT_004f81c4);
  Assert_Handler_00499950
            ((uint)(DAT_00694430 != (FILE *)0x0),
             (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x9c,
             s_Error_Opening_File__s_004f81ac);
  DAT_00694438 = str_1;
  iVar1 = FUN_0044c47a(arg2);
  if (iVar1 != 0) {
    _fclose(DAT_00694430);
  }
  return iVar1 != 0;
}


