/*
 * Decompiled function: _strrchr
 * Entry Point: 004de130
 * Size: 39 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strrchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *str_1,int arg_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  do {
    pcVar4 = str_1;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = str_1 + 1;
    cVar1 = *str_1;
    str_1 = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)arg_2 != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)arg_2) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}


