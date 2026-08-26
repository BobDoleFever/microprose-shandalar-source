/*
 * Decompiled function: __CrtCheckMemory
 * Entry Point: 00404630
 * Size: 873 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtCheckMemory
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtCheckMemory(void)

{
  code *char_ptr_1;
  bool flag_2;
  int val_3;
  int32_t uval_4;
  int32_t *local_c;
  int32_t local_8;
  
  local_8 = 1;
  if (((uint8_t)DAT_00412e28 & 1) == 0) {
    local_8 = 1;
  }
  else {
    val_3 = __heapchk();
    if ((val_3 == -1) || (val_3 == -2)) {
      for (local_c = DAT_00414334; local_c != (int32_t *)0x0; local_c = (int32_t *)*local_c) {
        flag_2 = true;
        val_3 = _CheckBytes((char *)(local_c + 7),DAT_00412e34,4);
        if (val_3 == 0) {
          val_3 = __CrtDbgReport(0,0,0,0,"DAMAGE: before %hs block (#%d) at 0x%08X.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          flag_2 = false;
        }
        val_3 = _CheckBytes((char *)((int)local_c + local_c[4] + 0x20),DAT_00412e34,4);
        if (val_3 == 0) {
          val_3 = __CrtDbgReport(0,0,0,0,"DAMAGE: after %hs block (#%d) at 0x%08X.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          flag_2 = false;
        }
        if ((local_c[5] == 0) &&
           (val_3 = _CheckBytes((char *)(local_c + 8),DAT_00412e38,local_c[4]), val_3 == 0)) {
          val_3 = __CrtDbgReport(0,0,0,0,"DAMAGE: on top of Free block at 0x%08X.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          flag_2 = false;
        }
        if (!flag_2) {
          if ((local_c[2] != 0) &&
             (val_3 = __CrtDbgReport(0,0,0,0,"%hs allocated at file %hs(%d).\n"), val_3 == 1)) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          val_3 = __CrtDbgReport(0,0,0,0,"%hs located at 0x%08X is %u bytes long.\n");
          if (val_3 == 1) {
            char_ptr_1 = (code *)swi(3);
            uval_4 = (*char_ptr_1)();
            return uval_4;
          }
          local_8 = 0;
        }
      }
    }
    else {
      switch(val_3) {
      case -6:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      case -5:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      case -4:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      case -3:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
        break;
      default:
        val_3 = __CrtDbgReport(0,0,0,0,"%s");
        if (val_3 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_4 = (*char_ptr_1)();
          return uval_4;
        }
      }
      local_8 = 0;
    }
  }
  return local_8;
}


