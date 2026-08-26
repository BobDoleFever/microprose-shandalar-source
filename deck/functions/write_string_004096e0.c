/*
 * Decompiled function: write_string
 * Entry Point: 004096e0
 * Size: 87 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_string(char *x,int y,FILE *width,int *height)

{
  do {
    if (y < 1) {
      return;
    }
    write_char((int)*x,width,height);
    x = x + 1;
    y = y + -1;
  } while (*height != -1);
  return;
}


