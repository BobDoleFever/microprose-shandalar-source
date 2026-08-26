/*
 * Decompiled function: _strncmp
 * Entry Point: 004d9b00
 * Size: 56 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *str_1,char *str_2,size_t arg_3)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = arg_3;
  pcVar6 = str_1;
  if (arg_3 != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = arg_3 - sVar3;
    do {
      pcVar6 = str_2;
      pcVar7 = str_1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = str_1 + 1;
      pcVar6 = str_2 + 1;
      cVar2 = *str_1;
      cVar1 = *str_2;
      str_2 = pcVar6;
      str_1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}


