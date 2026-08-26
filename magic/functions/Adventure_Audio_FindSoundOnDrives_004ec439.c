/*
 * Decompiled function: Adventure_Audio_FindSoundOnDrives
 * Entry Point: 004ec439
 * Size: 190 bytes
 */
#include "magic.h"


uint Adventure_Audio_FindSoundOnDrives(char *str_1)

{
  UINT UVar1;
  FILE *_File;
  int iVar2;
  undefined4 *puVar3;
  uint local_104;
  undefined4 local_100 [63];
  
  local_104 = DAT_0052faf4;
  puVar3 = local_100;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  do {
    if (0x7a < (char)local_104) {
      return (int)(char)local_104;
    }
    UVar1 = GetDriveTypeA((LPCSTR)&local_104);
    if (UVar1 == 5) {
      strcat((char *)&local_104,str_1);
      _File = fopen((char *)&local_104,&DAT_0052faf8);
      if (_File != (FILE *)0x0) {
        fclose(_File);
        return local_104 & 0xff;
      }
      local_104._0_3_ = (uint3)(ushort)local_104;
    }
    local_104 = CONCAT31(local_104._1_3_,(char)local_104 + '\x01');
  } while( true );
}


