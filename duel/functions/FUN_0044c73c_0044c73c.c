/*
 * Decompiled function: FUN_0044c73c
 * Entry Point: 0044c73c
 * Size: 240 bytes
 */
#include "duel.h"


undefined4
FUN_0044c73c(undefined *arg_1,char *str_2,void *arg_3,undefined4 arg_4,undefined4 arg_5,int arg_6,
            int arg_7)

{
  int local_100c;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  Mem_AllocOrFree_004ddee0();
  DAT_00694434 = _fopen(str_2,&DAT_004f823c);
  uStackY_28 = 0x44c78a;
  Assert_Handler_00499950
            ((uint)(DAT_00694434 != (FILE *)0x0),
             (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__004f8134,0x146,
             s_Error_Opening_File__s_004f8224);
  DAT_00694438 = str_2;
  FUN_0044c82c(arg_6,(short)arg_7);
  for (local_100c = 0; local_100c < arg_7; local_100c = local_100c + 1) {
    uStackY_28 = 0x44c7eb;
    Mem_AllocOrFree_0043d863();
    FUN_0044c8f0(local_1008,arg_6);
  }
  FUN_0044caaf(arg_3);
  _fclose(DAT_00694434);
  return 0;
}


