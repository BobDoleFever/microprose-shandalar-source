/*
 * Decompiled function: DeckDll_LoadDeckFile
 * Entry Point: 10006500
 * Size: 157 bytes
 */
#include "statwin.h"


int32_t __cdecl DeckDll_LoadDeckFile(int32_t arg_1)

{
  int32_t local_8;
  
  switch(arg_1) {
  case 0:
    local_8 = 0xffffffff;
    break;
  case 1:
    local_8 = 0;
    break;
  case 2:
    local_8 = 1;
    break;
  case 3:
    local_8 = 2;
    break;
  case 4:
    local_8 = 3;
    break;
  case 5:
  case 6:
  case 7:
    local_8 = 4;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    local_8 = 5;
    break;
  default:
    local_8 = 6;
  }
  return local_8;
}


