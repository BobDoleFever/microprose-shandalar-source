/*
 * Decompiled function: FUN_10016980
 * Entry Point: 10016980
 * Size: 290 bytes
 */
#include "deckdll.h"


void FUN_10016980(int x,int y,int width,char *str_4)

{
  size_t len_1;
  char *char_ptr_2;
  size_t _Count;
  va_list _Args;
  uint8_t *u_ptr_3;
  char local_114 [260];
  undefined8 local_10;
  FILE *local_8;
  
  if (x == 0) {
    strcpy(local_114,&DAT_10158770);
    strcat(local_114,s__assertFile_txt_100430b4);
    local_8 = fopen(local_114,&DAT_100430c4);
    local_10._4_4_ = &stack0x00000014;
    if ((y != 0) && (width != 0)) {
      sprintf(&DAT_1013d680,s_File_>__s__Line_>__d_100430c8,y,width);
    }
    _Count = 2000;
    _Args = local_10._4_4_;
    len_1 = strlen(&DAT_1013d680);
    _vsnprintf(&DAT_1013d680 + len_1,_Count,str_4,_Args);
    time(&local_10);
    u_ptr_3 = &DAT_1013d680;
    char_ptr_2 = ctime(&local_10);
    fprintf(local_8,s__s_s_100430e0,char_ptr_2,u_ptr_3);
    fclose(local_8);
    strcat(&DAT_1013d680,s_Please_call_MPS_Customer_Support_100430e8);
    MessageBoxA((HWND)0x0,&DAT_1013d680,s_Assertion_Error_1004311c,0x1000);
  }
  return;
}


