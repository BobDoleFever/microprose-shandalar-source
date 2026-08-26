/*
 * Decompiled function: Surface_PutPixel
 * Entry Point: 0050dbb0
 * Size: 121 bytes
 */
#include "magic.h"


void Surface_PutPixel(int *x,int y,int width,uint height)

{
  COLORREF color;
  uint uVar1;
  
  if ((int)height < 0) {
    uVar1 = -height;
    color = 0xffffff;
    if (height != 0xff000001) {
      color = ((uVar1 & 0xffff) >> 8 | 0x20000) << 8 | (uVar1 >> 0x10 & 0xff) << 0x10 | uVar1 & 0xff
      ;
    }
  }
  else if (height == 0xff) {
    color = 0xffffff;
  }
  else {
    color = height & 0xffff | 0x1000000;
  }
  SetPixelV(*(HDC *)((&DAT_0070a850)[*x] + 4),y,width,color);
  return;
}


