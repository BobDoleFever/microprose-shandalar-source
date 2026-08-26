/*
 * Decompiled function: thunk_FUN_10006830
 * Entry Point: 10001069
 * Size: 5 bytes
 */
#include "magsnd.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl thunk_FUN_10006830(int32_t *ptr_1,int32_t arg_2)

{
  int iStack_1c;
  int32_t uStack_c;
  size_t sStack_8;
  
  uStack_c = 0;
  sStack_8 = ptr_1[0x74] - ptr_1[0x75];
  if (ptr_1[0x68] - ptr_1[0x67] != sStack_8) {
    _DAT_1000a520 = _DAT_1000a520 + 1;
  }
  iStack_1c = ptr_1[0x65] - sStack_8;
  if ((int)(ptr_1[0x73] - ptr_1[0x74]) < (int)(ptr_1[0x65] - sStack_8)) {
    iStack_1c = ptr_1[0x73] - ptr_1[0x74];
  }
  if (sStack_8 != 0) {
    memmove((void *)ptr_1[0x66],(void *)ptr_1[0x67],sStack_8);
  }
  ptr_1[0x67] = ptr_1[0x66] + sStack_8;
  AVIStreamRead(*ptr_1,arg_2,iStack_1c / (int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21),ptr_1[0x67],iStack_1c,
                &uStack_c,0);
  ptr_1[0x68] = ptr_1[0x65] + ptr_1[0x66];
  ptr_1[0x67] = ptr_1[0x66];
  mmioSetInfo((HMMIO)ptr_1[0x72],(LPCMMIOINFO)(ptr_1 + 0x60),0);
  return;
}


