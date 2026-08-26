/*
 * Decompiled function: FUN_0047e4e0
 * Entry Point: 0047e4e0
 * Size: 709 bytes
 */
#include "duel.h"


int * FUN_0047e4e0(int arg_1,char *str_2,int arg_3)

{
  size_t sVar1;
  int iVar2;
  uint local_41c [66];
  uint local_314 [65];
  uint local_210 [64];
  uint local_110 [64];
  int local_10;
  int *local_c;
  int local_8;
  
  local_c = (int *)&DAT_005237d0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
  __splitpath(str_2,(char *)0x0,(char *)local_314,(char *)local_210,(char *)local_110);
  if (DAT_005237c4 == 0) {
    Mem_AllocOrFree_004d9630(local_41c,local_314);
    FUN_004d9640(local_41c,(uint *)s_SmallArt_cat_004f9d54);
    DAT_004f9d44 = FUN_004340f0((char *)local_41c);
    Mem_AllocOrFree_004d9630(local_41c,local_314);
    FUN_004d9640(local_41c,(uint *)s_MedArt_cat_004f9d64);
    DAT_004f9d48 = FUN_004340f0((char *)local_41c);
    DAT_005237c4 = 1;
  }
  sVar1 = _strlen((char *)local_314);
  local_8 = (int)local_314 + sVar1;
  if (arg_1 == 0) {
    DAT_005dad80 = DAT_004f9d44;
  }
  else {
    if (arg_1 != 1) {
      return (int *)0x0;
    }
    DAT_005dad80 = DAT_004f9d48;
  }
  Mem_AllocOrFree_004d9630(local_314,local_210);
  FUN_004d9640(local_314,local_110);
  __strlwr((char *)local_314);
  if (local_c != (int *)0x0) {
    _memset(local_c,0,0x1b0);
    Mem_AllocOrFree_004d9630((uint *)(local_c + 0x27),(uint *)str_2);
    local_c[0x68] = (int)&DAT_0059e180;
    local_10 = FUN_004344c1(DAT_005dad80,local_314,local_c + 0x68);
    if (local_10 == -1) {
      FUN_004d9640((uint *)str_2,(uint *)&DAT_004f9d70);
      OutputDebugStringA(str_2);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
      local_c = (int *)0x0;
    }
    else {
      local_c[0x69] = local_10 + -0x9c;
      FID_conflict__memcpy(local_c,(void *)local_c[0x68],0x9c);
      local_c[0x68] = local_c[0x68] + 0x9c;
      if (local_c[10] == 4) {
        local_c[7] = local_c[7] << 1;
        local_c[8] = local_c[8] << 1;
      }
      if (arg_3 != 0) {
        iVar2 = FUN_0047e7d3(local_c,(void *)0x0);
        local_c[0x6b] = iVar2;
        if (local_c[0x6b] == 0) {
          FUN_0047e7a5(local_c);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
          local_c = (int *)0x0;
        }
        else {
          local_c[0x6a] = 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
        }
      }
    }
  }
  return local_c;
}


