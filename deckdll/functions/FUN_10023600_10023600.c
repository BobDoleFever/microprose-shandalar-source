/*
 * Decompiled function: FUN_10023600
 * Entry Point: 10023600
 * Size: 538 bytes
 */
#include "deckdll.h"


uint8_t * FUN_10023600(char *str_1,uint8_t *arg_2,void *arg_3)

{
  uint8_t *u_ptr_1;
  uint32_t uval_2;
  int val_3;
  HGLOBAL pvVar4;
  uint32_t uval_5;
  int local_18;
  int local_10;
  int local_c;
  
  DAT_1013f3cc = (int)fopen(str_1,&DAT_10043b14);
  thunk_FUN_10016850((uint32_t)((FILE *)DAT_1013f3cc != (FILE *)0x0),
                     (int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0x69,
                     s_Error_Opening_File__s_10043afc);
  DAT_101407b0 = str_1;
  thunk_FUN_1002389f(arg_3);
  if ((DAT_10140733 == '\b') && (DAT_10140771 == '\x01')) {
    local_18 = 1;
  }
  else {
    local_18 = 0;
  }
  thunk_FUN_10016850(local_18,(int)PTR_s_D__Newmagic_sources_sidlib_Pcxw__10043acc,0x6f,
                     s__s_Not_a_256_color_palettized_pc_10043b18);
  uval_2 = 4 - (DAT_1004a810 & 3);
  uval_5 = (int)uval_2 >> 0x1f;
  val_3 = ((uval_2 ^ uval_5) - uval_5 & 3 ^ uval_5) - uval_5;
  if ((DAT_1004a810 == DAT_10043ad0) && (DAT_1004a814 == DAT_10043ad4)) {
    memset(arg_2,0,(val_3 + DAT_10043ad0) * DAT_10043ad4);
  }
  else {
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalFree(pvVar4);
    pvVar4 = GlobalAlloc(0x40,(val_3 + DAT_1004a810) * DAT_1004a814);
    arg_2 = GlobalLock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalLock(pvVar4);
    DAT_10043ad0 = DAT_1004a810;
    DAT_10043ad4 = DAT_1004a814;
  }
  u_ptr_1 = arg_2;
  for (local_c = 0; local_c < DAT_1004a814; local_c = local_c + 1) {
    thunk_FUN_10023a88(&DAT_1013f730);
    for (local_10 = 0; local_10 < (int)DAT_1004a810; local_10 = local_10 + 1) {
      *arg_2 = (&DAT_1013f730)[local_10];
      arg_2 = arg_2 + 1;
    }
    arg_2 = arg_2 + val_3;
  }
  fclose((FILE *)DAT_1013f3cc);
  return u_ptr_1;
}


