/*
 * Decompiled function: __heap_alloc_dbg
 * Entry Point: 00403470
 * Size: 818 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __heap_alloc_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t * __cdecl __heap_alloc_dbg(uint32_t x,uint32_t y,int width,int32_t height)

{
  code *char_ptr_1;
  bool flag_2;
  int32_t *u_ptr_3;
  int val_4;
  int32_t *puVar5;
  int val_6;
  
  flag_2 = false;
  if (((((uint8_t)DAT_00412e28 & 4) != 0) && (val_4 = __CrtCheckMemory(), val_4 == 0)) &&
     (val_4 = __CrtDbgReport(2,0x410460,0x141,0,"_CrtCheckMemory()"), val_4 == 1)) {
    char_ptr_1 = (code *)swi(3);
    puVar5 = (int32_t *)(*char_ptr_1)();
    return puVar5;
  }
  val_4 = DAT_00412e2c;
  if (DAT_00412e2c == DAT_00412e30) {
    char_ptr_1 = (code *)swi(3);
    puVar5 = (int32_t *)(*char_ptr_1)();
    return puVar5;
  }
  val_6 = (*(code *)PTR_FUN_00413900)(1,0,x,y,DAT_00412e2c,width,height);
  if (val_6 == 0) {
    if (width == 0) {
      val_4 = __CrtDbgReport(0,0,0,0,"%s");
      if (val_4 == 1) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
    }
    else {
      val_4 = __CrtDbgReport(0,0,0,0,"Client hook allocation failure at file %hs line %d.\n");
      if (val_4 == 1) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
    }
    puVar5 = (int32_t *)0x0;
  }
  else {
    if (((y & 0xffff) != 2) && (((uint8_t)DAT_00412e28 & 1) == 0)) {
      flag_2 = true;
    }
    if ((x < 0xffffffe1) && (x + 0x24 < 0xffffffe1)) {
      if (((((y & 0xffff) != 4) && (y != 1)) && ((y & 0xffff) != 2)) &&
         ((y != 3 && (val_6 = __CrtDbgReport(1,0,0,0,"%s"), val_6 == 1)))) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
      puVar5 = (int32_t *)__heap_alloc_base(x + 0x24);
      if (puVar5 == (int32_t *)0x0) {
        puVar5 = (int32_t *)0x0;
      }
      else {
        DAT_00412e2c = DAT_00412e2c + 1;
        if (flag_2) {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0xfedcbabc;
          puVar5[4] = x;
          puVar5[5] = 3;
          puVar5[6] = 0;
        }
        else {
          DAT_00414330 = DAT_00414330 + x;
          DAT_00414338 = DAT_00414338 + x;
          if (DAT_0041433c < DAT_00414338) {
            DAT_0041433c = DAT_00414338;
          }
          u_ptr_3 = puVar5;
          if (DAT_00414334 != (int32_t *)0x0) {
            DAT_00414334[1] = puVar5;
            u_ptr_3 = DAT_0041432c;
          }
          DAT_0041432c = u_ptr_3;
          *puVar5 = DAT_00414334;
          puVar5[1] = 0;
          puVar5[2] = width;
          puVar5[3] = height;
          puVar5[4] = x;
          puVar5[5] = y;
          puVar5[6] = val_4;
          DAT_00414334 = puVar5;
        }
        _memset(puVar5 + 7,(uint32_t)DAT_00412e34,4);
        _memset((void *)((int)puVar5 + x + 0x20),(uint32_t)DAT_00412e34,4);
        _memset(puVar5 + 8,(uint32_t)DAT_00412e3c,x);
        puVar5 = puVar5 + 8;
      }
    }
    else {
      val_4 = __CrtDbgReport(1,0,0,0,"Invalid allocation size: %u bytes.\n");
      if (val_4 == 1) {
        char_ptr_1 = (code *)swi(3);
        puVar5 = (int32_t *)(*char_ptr_1)();
        return puVar5;
      }
      puVar5 = (int32_t *)0x0;
    }
  }
  return puVar5;
}


