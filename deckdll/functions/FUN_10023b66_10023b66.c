/*
 * Decompiled function: FUN_10023b66
 * Entry Point: 10023b66
 * Size: 242 bytes
 */
#include "deckdll.h"


int32_t
FUN_10023b66(int32_t arg_1,char *str_2,void *arg_3,int32_t arg_4,int32_t arg_5,int arg_6,
            int arg_7)

{
  int local_100c;
  uint8_t local_1008 [4064];
  int32_t uStackY_28;
  
  FUN_1003d810();
  DAT_1013f728 = (int)fopen(str_2,&DAT_10043bd4);
  uStackY_28 = 0x10023bb5;
  thunk_FUN_10016850((uint32_t)((FILE *)DAT_1013f728 != (FILE *)0x0),
                     (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0x146,
                     s_Error_Opening_File__s_10043bbc);
  DAT_101407b0 = str_2;
  thunk_FUN_10023c58(arg_6,(short)arg_7);
  for (local_100c = 0; local_100c < arg_7; local_100c = local_100c + 1) {
    uStackY_28 = 0x10023c16;
    thunk_FUN_1003b0f7();
    thunk_FUN_10023d1d(local_1008,arg_6);
  }
  thunk_FUN_10023ee1(arg_3);
  fclose((FILE *)DAT_1013f728);
  return 0;
}


