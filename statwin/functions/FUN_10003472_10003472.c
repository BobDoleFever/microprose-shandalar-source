/*
 * Decompiled function: FUN_10003472
 * Entry Point: 10003472
 * Size: 197 bytes
 */
#include "statwin.h"


uint32_t __cdecl FUN_10003472(char *str_1)

{
  UINT UVar1;
  FILE *_File;
  int val_2;
  int32_t *u_ptr_3;
  uint3 local_104;
  uint8_t uStack_101;
  int32_t local_100 [63];
  
  _local_104 = DAT_10011bf4;
  u_ptr_3 = local_100;
  for (val_2 = 0x3f; val_2 != 0; val_2 = val_2 + -1) {
    *u_ptr_3 = 0;
    u_ptr_3 = u_ptr_3 + 1;
  }
  do {
    if ('z' < (char)local_104) {
      return (uint32_t)(uint3)((char)local_104 >> 7) << 8;
    }
    UVar1 = GetDriveTypeA((LPCSTR)&local_104);
    if (UVar1 == 5) {
      strcat((char *)&local_104,str_1);
      _File = fopen((char *)&local_104,&DAT_10011bf8);
      if (_File != (FILE *)0x0) {
        val_2 = fclose(_File);
        return CONCAT31((int3)((uint32_t)val_2 >> 8),(char)local_104);
      }
      local_104 = (uint3)(uint16_t)local_104;
    }
    _local_104 = CONCAT31(stack0xfffffefd,(char)local_104 + '\x01');
  } while( true );
}


