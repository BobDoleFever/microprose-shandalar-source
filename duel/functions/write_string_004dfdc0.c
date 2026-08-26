/*
 * Decompiled function: write_string
 * Entry Point: 004dfdc0
 * Size: 87 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_string(char *str_1,int y,FILE *fp,int *height)

{
  do {
    if (y < 1) {
      return;
    }
    write_char((int)*str_1,fp,height);
    str_1 = str_1 + 1;
    y = y + -1;
  } while (*height != -1);
  return;
}


