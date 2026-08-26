/*
 * Decompiled function: Assert_Handler_005019a0
 * Entry Point: 005019a0
 * Size: 290 bytes
 */
#include "magic.h"


void Assert_Handler_005019a0(int x,int y,int width,char *str_4)

{
  size_t sVar1;
  char *pcVar2;
  size_t arg_2;
  va_list arg_4;
  undefined *puVar3;
  char local_114 [260];
  undefined8 local_10;
  va_list local_8;
  
  if (x == 0) {
    strcpy(local_114,&DAT_006807a0);
    strcat(local_114,s__assertFile_txt_00531054);
    local_10._4_4_ = fopen(local_114,&DAT_00531064);
    local_8 = &stack0x00000014;
    if ((y != 0) && (width != 0)) {
      sprintf(&DAT_0061d888,s_File_>__s__Line_>__d_00531068,y,width);
    }
    arg_2 = 2000;
    arg_4 = local_8;
    sVar1 = strlen(&DAT_0061d888);
    _vsnprintf(&DAT_0061d888 + sVar1,arg_2,str_4,arg_4);
    time(&local_10);
    puVar3 = &DAT_0061d888;
    pcVar2 = ctime(&local_10);
    fprintf(local_10._4_4_,s__s_s_00531080,pcVar2,puVar3);
    fclose(local_10._4_4_);
    strcat(&DAT_0061d888,s_Please_call_MPS_Customer_Support_00531088);
    MessageBoxA((HWND)0x0,&DAT_0061d888,s_Assertion_Error_005310bc,0x1000);
  }
  return;
}


