/*
 * Decompiled function: FUN_00472731
 * Entry Point: 00472731
 * Size: 268 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00472731(uint *arg1,int arg2)

{
  uint local_6c [25];
  UINT local_8;
  
  FID_conflict__memcpy(&DAT_00522468,&DAT_004f9788,0x3c);
  Mem_AllocOrFree_004d9630(local_6c,(uint *)&DAT_004f9864);
  FUN_004d9640(local_6c,arg1);
  _DAT_00522468 = GetPrivateProfileIntA(s_Fonts_004f986c,(LPCSTR)local_6c,0x14,&DAT_00664c40);
  Mem_AllocOrFree_004d9630(local_6c,(uint *)&DAT_004f9874);
  FUN_004d9640(local_6c,arg1);
  local_8 = GetPrivateProfileIntA(s_Fonts_004f987c,(LPCSTR)local_6c,0,&DAT_00664c40);
  if (local_8 != 0) {
    _DAT_00522478 = 700;
  }
  if (arg2 != 0) {
    DAT_0052247c = 1;
  }
  Mem_AllocOrFree_004d9630(local_6c,(uint *)&DAT_004f9884);
  FUN_004d9640(local_6c,arg1);
  GetPrivateProfileStringA
            (s_Fonts_004f989c,(LPCSTR)local_6c,s_MS_Sans_Serif_004f988c,&DAT_00522484,0x20,
             &DAT_00664c40);
  return &DAT_00522468;
}


