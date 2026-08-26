/*
 * Decompiled function: FUN_1002389f
 * Entry Point: 1002389f
 * Size: 489 bytes
 */
#include "deckdll.h"


int32_t FUN_1002389f(void *arg_1)

{
  int local_8;
  
  fread(&DAT_10140730,0x80,1,DAT_1013f3cc);
  thunk_FUN_10016850((uint32_t)(DAT_10140730 == '\n'),
                     (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0xad,
                     s__s_Not_a_pcx_file_10043b60);
  thunk_FUN_10016850((uint32_t)(DAT_10140731 == '\x05'),
                     (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0xae,
                     s__s_Not_a_version_5_pcx_file_10043b74);
  DAT_1004a810 = ((uint32_t)DAT_10140738 - (uint32_t)DAT_10140734) + 1;
  DAT_1004a814 = ((uint32_t)DAT_1014073a - (uint32_t)DAT_10140736) + 1;
  if (arg_1 != (void *)0x0) {
    if ((DAT_10140771 == '\x01') && (DAT_10140733 == '\b')) {
      fseek(DAT_1013f3cc,-0x300,2);
      fread(arg_1,1,0x300,DAT_1013f3cc);
      fseek(DAT_1013f3cc,0x80,0);
    }
    else if ((DAT_10140771 == '\x04') && (DAT_10140733 == '\x01')) {
      fseek(DAT_1013f3cc,0x10,2);
      for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
        fread((void *)(local_8 * 4 + (int)arg_1),1,3,DAT_1013f3cc);
      }
      fseek(DAT_1013f3cc,0x80,0);
    }
    else {
      thunk_FUN_10016850(0,(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0xd4,
                         s__s_is_not_in_a_recognizable_form_10043b94);
    }
  }
  return 1;
}


