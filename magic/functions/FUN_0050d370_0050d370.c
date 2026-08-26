/*
 * Decompiled function: FUN_0050d370
 * Entry Point: 0050d370
 * Size: 227 bytes
 */
#include "magic.h"


void FUN_0050d370(int arg1,undefined4 arg2)

{
  undefined4 *_Memory;
  HGDIOBJ h;
  
  if ((arg1 != 0) && ((&DAT_0070a850)[arg1] != 0)) {
    AssertOrLog((uint)(arg1 != 0),0x5325e0,0x10b,s_Cannot_explicitly_Deallocate_pag_00532630);
    AssertOrLog((uint)(arg1 < 10),0x5325e0,0x10c,s_Graphic_Page_number_out_of_range_005325b8);
    _Memory = (undefined4 *)(&DAT_0070a850)[arg1];
    if (_Memory != (undefined4 *)0x0) {
      SelectObject((HDC)_Memory[1],(HGDIOBJ)_Memory[3]);
      DeleteObject((HGDIOBJ)_Memory[2]);
      free((void *)_Memory[4]);
      CloseHandle((HANDLE)*_Memory);
      h = GetStockObject(0xf);
      SelectObject((HDC)_Memory[1],h);
      RealizePalette((HDC)_Memory[1]);
      DeleteDC((HDC)_Memory[1]);
      free(_Memory);
      (&DAT_0070a850)[arg1] = 0;
    }
  }
  (&DAT_0070a850)[arg1] = arg2;
  return;
}


