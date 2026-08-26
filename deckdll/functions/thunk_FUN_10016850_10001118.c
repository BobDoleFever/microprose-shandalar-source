/*
 * Decompiled function: thunk_FUN_10016850
 * Entry Point: 10001118
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10016850(int x,int y,int width,char *str_4)

{
  size_t len_1;
  char *char_ptr_2;
  size_t _Count;
  va_list _Args;
  uint8_t *u_ptr_3;
  char acStack_114 [260];
  undefined8 uStack_10;
  FILE *pFStack_8;
  
  if (x == 0) {
    strcpy(acStack_114,&DAT_10158770);
    strcat(acStack_114,s__assertFile_txt_1004303c);
    pFStack_8 = fopen(acStack_114,&DAT_1004304c);
    uStack_10._4_4_ = &stack0x00000014;
    if ((y != 0) && (width != 0)) {
      sprintf(&DAT_1013d680,s_File_>__s__Line_>__d_10043050,y,width);
    }
    _Count = 2000;
    _Args = uStack_10._4_4_;
    len_1 = strlen(&DAT_1013d680);
    _vsnprintf(&DAT_1013d680 + len_1,_Count,str_4,_Args);
    time(&uStack_10);
    u_ptr_3 = &DAT_1013d680;
    char_ptr_2 = ctime(&uStack_10);
    fprintf(pFStack_8,s__s_s_10043068,char_ptr_2,u_ptr_3);
    fclose(pFStack_8);
    strcat(&DAT_1013d680,s_Please_call_MPS_Customer_Support_10043070);
    MessageBoxA((HWND)0x0,&DAT_1013d680,s_Assertion_Error_100430a4,0x1000);
                    /* WARNING: Subroutine does not return */
    exit(0xff);
  }
  return;
}


