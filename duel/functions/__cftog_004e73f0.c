/*
 * Decompiled function: __cftog
 * Entry Point: 004e73f0
 * Size: 281 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cftog
   
   Library: Visual Studio 1998 Debug */

void __cftog(undefined4 *arg_1,int y,size_t arg_3,int arg_4)

{
  char *x;
  STRFLT unaff_EDI;
  char *local_8;
  
  DAT_005edb14 = (int *)__fltout(*arg_1,arg_1[1]);
  DAT_0050a5cc = DAT_005edb14[1] + -1;
  x = (char *)((uint)(*DAT_005edb14 == 0x2d) + y);
  __fptostr(x,arg_3,(int)DAT_005edb14,unaff_EDI);
  DAT_0050a5d0 = DAT_0050a5cc < DAT_005edb14[1] + -1;
  DAT_0050a5cc = DAT_005edb14[1] + -1;
  if ((DAT_0050a5cc < -4) || ((int)arg_3 <= DAT_0050a5cc)) {
    __cftoe_g((double *)arg_1,(char *)y,arg_3,arg_4);
  }
  else {
    if ((bool)DAT_0050a5d0) {
      do {
        local_8 = x;
        x = local_8 + 1;
      } while (*local_8 != '\0');
      local_8[-1] = '\0';
    }
    __cftof_g((double *)arg_1,(char *)y,arg_3);
  }
  return;
}


