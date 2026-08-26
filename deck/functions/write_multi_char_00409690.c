/*
 * Decompiled function: write_multi_char
 * Entry Point: 00409690
 * Size: 75 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_multi_char(int x,int y,FILE *width,int *height)

{
  do {
    if (y < 1) {
      return;
    }
    write_char(x,width,height);
    y = y + -1;
  } while (*height != -1);
  return;
}


