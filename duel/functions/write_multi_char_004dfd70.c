/*
 * Decompiled function: write_multi_char
 * Entry Point: 004dfd70
 * Size: 75 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_multi_char(int x,int y,FILE *fp,int *height)

{
  do {
    if (y < 1) {
      return;
    }
    write_char(x,fp,height);
    y = y + -1;
  } while (*height != -1);
  return;
}


