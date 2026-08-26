/*
 * Decompiled function: __CrtMemDumpAllObjectsSince
 * Entry Point: 00404f30
 * Size: 704 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtMemDumpAllObjectsSince
   
   Library: Visual Studio 1998 Debug */

void __cdecl __CrtMemDumpAllObjectsSince(int32_t *ptr_1)

{
  code *char_ptr_1;
  int val_2;
  int32_t *local_c;
  int32_t *local_8;
  
  local_c = (int32_t *)0x0;
  val_2 = __CrtDbgReport(0,0,0,0,"%s");
  if (val_2 == 1) {
    char_ptr_1 = (code *)swi(3);
    (*char_ptr_1)();
    return;
  }
  if (ptr_1 != (int32_t *)0x0) {
    local_c = (int32_t *)*ptr_1;
  }
  local_8 = DAT_00414334;
  do {
    if ((local_8 == (int32_t *)0x0) || (local_8 == local_c)) {
      val_2 = __CrtDbgReport(0,0,0,0,"%s");
      if (val_2 != 1) {
        return;
      }
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    if ((((local_8[5] & 0xffff) != 3) && ((local_8[5] & 0xffff) != 0)) &&
       (((local_8[5] & 0xffff) != 2 || (((uint8_t)DAT_00412e28 & 0x10) != 0)))) {
      if (local_8[2] != 0) {
        val_2 = __CrtIsValidPointer((void *)local_8[2],1,0);
        if (val_2 == 0) {
          val_2 = __CrtDbgReport(0,0,0,0,"#File Error#(%d) : ");
          if (val_2 == 1) {
            char_ptr_1 = (code *)swi(3);
            (*char_ptr_1)();
            return;
          }
        }
        else {
          val_2 = __CrtDbgReport(0,0,0,0,"%hs(%d) : ");
          if (val_2 == 1) {
            char_ptr_1 = (code *)swi(3);
            (*char_ptr_1)();
            return;
          }
        }
      }
      val_2 = __CrtDbgReport(0,0,0,0,"{%ld} ");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
      if ((local_8[5] & 0xffff) == 4) {
        val_2 = __CrtDbgReport(0,0,0,0,"client block at 0x%08X, subtype %x, %u bytes long.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        if (DAT_004156a0 == (code *)0x0) {
          __printMemBlockData((int)local_8);
        }
        else {
          (*DAT_004156a0)(local_8 + 8,local_8[4]);
        }
      }
      else if (local_8[5] == 1) {
        val_2 = __CrtDbgReport(0,0,0,0,"normal block at 0x%08X, %u bytes long.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        __printMemBlockData((int)local_8);
      }
      else if ((local_8[5] & 0xffff) == 2) {
        val_2 = __CrtDbgReport(0,0,0,0,"crt block at 0x%08X, subtype %x, %u bytes long.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
        __printMemBlockData((int)local_8);
      }
    }
    local_8 = (int32_t *)*local_8;
  } while( true );
}


