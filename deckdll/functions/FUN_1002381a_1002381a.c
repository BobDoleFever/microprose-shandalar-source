/*
 * Decompiled function: FUN_1002381a
 * Entry Point: 1002381a
 * Size: 133 bytes
 */
#include "deckdll.h"


bool FUN_1002381a(char *str_1,void *arg2)

{
  int val_1;
  
  DAT_1013f3cc = (int)fopen(str_1,&DAT_10043b5c);
  thunk_FUN_10016850((uint32_t)((FILE *)DAT_1013f3cc != (FILE *)0x0),
                     (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0x9c,
                     s_Error_Opening_File__s_10043b44);
  DAT_101407b0 = str_1;
  val_1 = thunk_FUN_1002389f(arg2);
  if (val_1 != 0) {
    fclose((FILE *)DAT_1013f3cc);
  }
  return val_1 != 0;
}


