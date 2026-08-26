/*
 * Decompiled function: FUN_0047c360
 * Entry Point: 0047c360
 * Size: 716 bytes
 */
#include "magic.h"


undefined4 FUN_0047c360(char *str_1,uint arg_2,uint arg_3)

{
  uint uVar1;
  size_t sVar2;
  
  sVar2 = DAT_00676dc8;
  if ((int)arg_2 < 0xf0a) {
    if (arg_2 == 0xf09) {
      DAT_00676dc8 = DAT_00676dc8 + 8;
      if ((int)DAT_00676dc8 < (int)arg_3) {
        return 0;
      }
      DAT_00676dc8 = arg_3;
      return 0;
    }
    if (arg_2 == 0xe08) {
      if (DAT_00676dc8 == 0) {
        return 0;
      }
      DAT_00676dc8 = DAT_00676dc8 - 1;
      strcpy(str_1 + DAT_00676dc8,str_1 + sVar2);
      return 0;
    }
  }
  else if ((int)arg_2 < 0x1c0e) {
    if (arg_2 == 0x1c0d) {
      return 1;
    }
    if (arg_2 == 0xf0f) {
      DAT_00676dc8 = DAT_00676dc8 - 8;
      if (0 < (int)DAT_00676dc8) {
        return 0;
      }
      DAT_00676dc8 = 0;
      return 0;
    }
  }
  else if ((int)arg_2 < 0x4b01) {
    if (arg_2 == 0x4b00) {
      if ((int)DAT_00676dc8 < 0) {
        return 0;
      }
      DAT_00676dc8 = DAT_00676dc8 - 1;
      return 0;
    }
    if (arg_2 == 0x4700) {
      DAT_00676dc8 = 0;
      return 0;
    }
  }
  else if ((int)arg_2 < 0x4f01) {
    if (arg_2 == 0x4f00) {
      DAT_00676dc8 = strlen(str_1);
      return 0;
    }
    if (arg_2 == 0x4d00) {
      if ((int)arg_3 <= (int)DAT_00676dc8) {
        return 0;
      }
      sVar2 = strlen(str_1);
      if (sVar2 == DAT_00676dc8) {
        strcat(str_1,&DAT_00526b7c);
      }
      DAT_00676dc8 = DAT_00676dc8 + 1;
      return 0;
    }
  }
  else {
    if (arg_2 == 0x5200) {
      DAT_00676dc4 = DAT_00676dc4 ^ 1;
      return 0;
    }
    if (arg_2 == 0x5300) {
      sVar2 = strlen(str_1);
      if ((int)sVar2 <= (int)DAT_00676dc8) {
        return 0;
      }
      strcpy(str_1 + DAT_00676dc8,str_1 + DAT_00676dc8 + 1);
      return 0;
    }
  }
  sVar2 = strlen(str_1);
  if ((sVar2 < arg_3) &&
     ((((uVar1 = arg_2 & 0xff, 0x40 < uVar1 && (uVar1 < 0x5b)) || ((0x60 < uVar1 && (uVar1 < 0x7b)))
       ) || (((0x2f < uVar1 && (uVar1 < 0x3a)) || (uVar1 == 0x20)))))) {
    if (DAT_00676dc4 != 0) {
      memmove(str_1 + DAT_00676dc8 + 1,str_1 + DAT_00676dc8,(arg_3 - DAT_00676dc8) - 1);
    }
    str_1[DAT_00676dc8] = (char)arg_2;
    DAT_00676dc8 = DAT_00676dc8 + 1;
  }
  return 0;
}


