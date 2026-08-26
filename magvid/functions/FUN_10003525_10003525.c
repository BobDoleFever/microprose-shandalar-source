/*
 * Decompiled function: FUN_10003525
 * Entry Point: 10003525
 * Size: 208 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_10003525(int *x,short *y,int *width,int height)

{
  int val_1;
  int32_t uval_2;
  
  if (((x == (int *)0x0) || (y == (short *)0x0)) || (width == (int *)0x0)) {
    uval_2 = 2;
  }
  else if ((height < 0) || (2 < height)) {
    uval_2 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + height * 4);
    if ((val_1 == 0) || (*(int *)(val_1 + 0x50) == 0)) {
      uval_2 = 5;
    }
    else {
      (**(code **)(*x + 0x18))
                (*(int32_t *)(val_1 + 0x50),(int)*y,(int)y[1],width[2] - *width,
                 width[3] - width[1],*width,width[1]);
      uval_2 = 0;
    }
  }
  return uval_2;
}


