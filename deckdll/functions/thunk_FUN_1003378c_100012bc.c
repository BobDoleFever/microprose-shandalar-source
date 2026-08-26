/*
 * Decompiled function: thunk_FUN_1003378c
 * Entry Point: 100012bc
 * Size: 5 bytes
 */
#include "deckdll.h"


uint32_t thunk_FUN_1003378c(int arg_1)

{
  return CONCAT12((&DAT_10175f10)[arg_1 * 4],
                  CONCAT11((&DAT_10175f11)[arg_1 * 4],(&DAT_10175f12)[arg_1 * 4])) | 0x2000000;
}


