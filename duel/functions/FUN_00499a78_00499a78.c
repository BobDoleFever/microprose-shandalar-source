/*
 * Decompiled function: FUN_00499a78
 * Entry Point: 00499a78
 * Size: 283 bytes
 */
#include "duel.h"


void FUN_00499a78(int param_1,int param_2,int param_3,char *param_4)

{
  size_t sVar1;
  char *pcVar2;
  size_t _Count;
  va_list _Args;
  undefined *puVar3;
  char local_114 [260];
  undefined8 local_10;
  va_list local_8;
  
  if (param_1 == 0) {
    FUN_004d9630(local_114,&DAT_005f76e0);
    FUN_004d9640(local_114,s__assertFile_txt_00505810);
    local_10._4_4_ = _fopen(local_114,&DAT_00505820);
    local_8 = &stack0x00000014;
    if ((param_2 != 0) && (param_3 != 0)) {
      _sprintf(&DAT_005dc318,s_File_>__s__Line_>__d_00505824,param_2,param_3);
    }
    _Count = 2000;
    _Args = local_8;
    sVar1 = _strlen(&DAT_005dc318);
    __vsnprintf(&DAT_005dc318 + sVar1,_Count,param_4,_Args);
    _time(&local_10);
    puVar3 = &DAT_005dc318;
    pcVar2 = _ctime(&local_10);
    _fprintf(local_10._4_4_,s__s_s_0050583c,pcVar2,puVar3);
    _fclose(local_10._4_4_);
    FUN_004d9640(&DAT_005dc318,s_Please_call_MPS_Customer_Support_00505844);
    MessageBoxA((HWND)0x0,&DAT_005dc318,s_Assertion_Error_00505878,0x1000);
  }
  return;
}


