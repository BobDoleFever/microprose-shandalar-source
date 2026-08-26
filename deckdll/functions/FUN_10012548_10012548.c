/*
 * Decompiled function: FUN_10012548
 * Entry Point: 10012548
 * Size: 504 bytes
 */
#include "deckdll.h"


int32_t FUN_10012548(void)

{
  int32_t uval_1;
  
  DAT_101628fc = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_GREENCARD_10042bd8,(void *)0x0);
  DAT_10175efc = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_WHITECARD_10042be4,(void *)0x0);
  DAT_101cf950 = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_BLUECARD_10042bf0,(void *)0x0);
  DAT_10175544 = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_BLACKCARD_10042bfc,(void *)0x0);
  DAT_10176488 = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_REDCARD_10042c08,(void *)0x0);
  DAT_101628ec = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_LANDCARD_10042c10,(void *)0x0);
  DAT_101cf928 = (HANDLE)thunk_FUN_10031af5(DAT_101cf334,s_ARTIFACTCARD_10042c1c,(void *)0x0);
  if ((((DAT_101628fc == (HANDLE)0x0) || (DAT_10175efc == (HANDLE)0x0)) ||
      (DAT_101cf950 == (HANDLE)0x0)) ||
     (((DAT_10175544 == (HANDLE)0x0 || (DAT_10176488 == (HANDLE)0x0)) ||
      ((DAT_101628ec == (HANDLE)0x0 || (DAT_101cf928 == (HANDLE)0x0)))))) {
    if (DAT_101628fc != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_101628fc);
    }
    if (DAT_10175efc != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_10175efc);
    }
    if (DAT_101cf950 != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_101cf950);
    }
    if (DAT_10175544 != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_10175544);
    }
    if (DAT_10176488 != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_10176488);
    }
    if (DAT_101628ec != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_101628ec);
    }
    if (DAT_101cf928 != (HANDLE)0x0) {
      thunk_FUN_10032018(DAT_101cf928);
    }
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}


